"""Press legitimacy gate, delayed-review queue, and inbound registration.

Split from communications/inbound.py during the 2026-04 refactor.

Holds the three predicates/queues that sit between the inbound parser
(``frm.py``) and the response generator (``respond.py``):

  * ``legitimacy_gate``           — accept/reject an inbound press by
    alliance-trust, history, and current stance.
  * ``delay_review``              — queue a press for later re-evaluation
    if it cannot yet be decided.
  * ``register_received_press``   — commit an accepted press to the ledger.

``delay_review`` and ``register_received_press`` both re-run
``legitimacy_gate`` to short-circuit clearly illegitimate traffic.

Module-level deps: ``...state.InnerGameState``;
``..evaluators._split_xdo_clauses`` (delay_review),
``..parsers._parse_xdo_candidates`` and ``..senders.send_alliance_press``
(register_received_press).

NOTE: ``delay_review`` contained a broken function-local import
``from .dispatch import …`` (one dot, targeting non-existent
``communications/inbound/dispatch.py``).  Fixed 2026-04-20 to
``from ...dispatch import …`` (three dots → ``albert.dispatch``).
The import was subsequently promoted to module level (C1 hardening,
2026-04-20) so that startup fails loudly if dispatch is unavailable.
All callers' ``except Exception`` narrowed to specific types.
"""

import logging as _logging
import time as _time

from ...state import InnerGameState
from ...dispatch import validate_and_dispatch_order
from ..parsers import _parse_xdo_candidates
from ..senders import send_alliance_press
from ..evaluators import _split_xdo_clauses

_DAIDE_POWERS = ["AUS", "ENG", "FRA", "GER", "ITA", "RUS", "TUR"]

_log = _logging.getLogger(__name__)


def legitimacy_gate(
    state: "InnerGameState",
    own_power_idx: int,
    candidates: list,
) -> int:
    """
    Port of FUN_00426140 — the per-order legitimacy gate that CAL_VALUE and
    register_received_press invoke over a std::set<TokenList> of accepted
    XDO clauses. Returns the **minimum per-order score** across the set
    (CAL_VALUE uses ``< 0`` as the demote-verdict threshold).

    See docs/funcs/FUN_00426140_and_FUN_0041a100.md for the full spec.

    Parameters
    ----------
    candidates : list of dicts with at least the keys:
        'order_seq'  — parsed order dict consumed by validate_and_dispatch_order
        'flag_bit'   — the +0x1c channel tag (1 = sub-tree A, skip own-power
                       rescore; 0 = sub-tree B, eligible for clamp-window rescore)
        'type_flag'  — candidate polarity alias: 0=XDO maps to flag_bit=1;
                       1=NOT-XDO maps to flag_bit=0

    Per-candidate evaluation mirrors the C:

        raw = validate_and_dispatch_order(state, candidate power, order, commit=False)
        skip_rescore = (flag_bit == 1)
        if not skip_rescore and raw > -90000:
            rescored = same order re-scored as own_power_idx (own-power prefix prepend)
            if -89999 <= rescored <= -80000:
                score = 100000   # clamp window: peer-owed obligation that
                                 # aligns with own plan → "unlocked"
            else:
                score = rescored
        else:
            score = raw

    Aggregation:
        First-iter special case: if min is still seed (None) and score == 100000,
        set min = 100000 (without this the normal ``score < min`` update would
        reject 100000 whenever initial seed is 0, causing first-iter clamps to
        silently fail to propagate).
        Otherwise: min = min(min, score).

    Returns the aggregate minimum (defaults to 0 for an empty set).
    """
    # validate_and_dispatch_order imported at module level (C1 fix 2026-04-20)

    aggregate: int | None = None

    for cand in candidates:
        order_seq = cand.get('order_seq') or cand
        polarity = int(cand.get('type_flag', 0))
        flag_bit = cand.get('flag_bit', 0 if polarity == 1 else 1)

        # Find the order's claimed power (from the XDO's unit spec) — the C
        # equivalent reads the power token out of the clause's TokenList and
        # calls FUN_00422a90 with it.
        claimed_power = cand.get('power', order_seq.get('power', own_power_idx))

        raw = validate_and_dispatch_order(
            state, claimed_power, order_seq, commit=False,
        )

        if flag_bit != 1 and raw > -90000:
            # Own-power prefix re-score: evaluate this order *as if Albert
            # were the executing power*. A clause that looks hostile to the
            # sender can look like an excellent own-plan alignment.
            rescored = validate_and_dispatch_order(
                state, own_power_idx, order_seq, commit=False,
            )
            if -89999 <= rescored <= -80000:
                # Clamp window: trust-layer failure (FUN_0041d360 range)
                # becomes a strong positive.
                score = 100000
            else:
                score = rescored
        else:
            score = raw

        if aggregate is None:
            # First iter: seed with this score. Covers the C special branch
            # for first-iter 100000 clamps that the plain min-update would miss.
            aggregate = score
        else:
            aggregate = min(aggregate, score)

        _log.debug(
            "legitimacy_gate: flag_bit=%d raw=%d score=%d agg=%s",
            flag_bit, raw, score, aggregate,
        )

    return aggregate if aggregate is not None else 0


def _clause_text(tokens) -> str:
    return ' '.join(str(t) for t in tokens)


def _candidate_clause_tokens(candidate) -> "tuple[list, int]":
    """(XDO clause tokens without any NOT wrapper, Python polarity) of a node
    candidate.  Python polarity 0 is ``XDO``, 1 is ``NOT ( XDO ... )``."""
    tokens = candidate.get('tokens', []) if isinstance(candidate, dict) else candidate
    tokens = list(tokens or [])
    negated = bool(tokens) and str(tokens[0]).upper() == 'NOT'
    if negated:
        tokens = tokens[1:]
        if tokens and tokens[0] == '(' and tokens[-1] == ')':
            tokens = tokens[1:-1]
    return tokens, int(negated)


def _candidate_clause(candidate) -> "tuple[str, int]":
    tokens, polarity = _candidate_clause_tokens(candidate)
    return _clause_text(tokens), polarity


def _entry_clause_token_sets(entry: dict) -> "tuple[list, list]":
    """The two XDO clause sets of a broadcast record, in C orientation.

    Record +0x18 (set A) and +0x24 (set B) are what DELAY_REVIEW and CAL_VALUE
    compare a proposal's plain and negated XDO clauses against, and set A is
    what ScoreOrderCandidates turns into general orders.  FUN_00431310's
    first pass files plain XDO clauses in set B and negated ones in set A;
    its second pass swaps them.  BuildAndSendSUB's own proposal records
    carry explicit ``clause_set_a`` / ``clause_set_b`` token lists.
    """
    if 'clause_set_a' in entry or 'clause_set_b' in entry:
        return (
            [list(t) for t in entry.get('clause_set_a', [])],
            [list(t) for t in entry.get('clause_set_b', [])],
        )
    plain: list = []
    negated: list = []
    for candidate in entry.get('order_candidates', []) or []:
        tokens, polarity = _candidate_clause_tokens(candidate)
        sink = negated if polarity else plain
        if tokens not in sink:
            sink.append(tokens)
    if int(entry.get('registration_pass', 0)) == 1:
        return negated, plain
    return plain, negated


def _entry_clause_sets(entry: dict) -> "tuple[set, set]":
    """``_entry_clause_token_sets`` as sets of clause texts."""
    set_a, set_b = _entry_clause_token_sets(entry)
    return {_clause_text(t) for t in set_a}, {_clause_text(t) for t in set_b}


def _proposal_xdo_clauses(content_tokens: list) -> "tuple[list, list, bool, bool]":
    """DELAY_REVIEW's clause split of ``PRP ( ... )`` content.

    Returns (plain clauses, negated clauses, is_orr, has_xdo), each clause a
    flat token list without its NOT wrapper, in first-seen order and
    de-duplicated (FUN_00419300 inserts into a std::set).
    """
    from ..tokens import _c_element_count, _c_sublist, _c_token_at

    body = _c_sublist(content_tokens, 1)
    first = str(_c_token_at(body, 0)).upper()
    plain: list = []
    negated: list = []
    has_xdo = False

    def _add(clause: list, is_not: bool) -> None:
        sink = negated if is_not else plain
        if clause not in sink:
            sink.append(clause)

    if first in ('AND', 'ORR'):
        for index in range(1, _c_element_count(body)):
            clause = _c_sublist(body, index)
            is_not = str(_c_token_at(clause, 0)).upper() == 'NOT'
            if is_not:
                clause = _c_sublist(clause, 1)
            if str(_c_token_at(clause, 0)).upper() == 'XDO':
                has_xdo = True
                _add(clause, is_not)
        return plain, negated, first == 'ORR', has_xdo

    is_not = first == 'NOT'
    if is_not:
        body = _c_sublist(body, 1)
    if str(_c_token_at(body, 0)).upper() == 'XDO':
        has_xdo = True
        _add(body, is_not)
    return plain, negated, False, has_xdo


def delay_review(
    state: "InnerGameState",
    content_tokens: list,
    sender_power: "int | None" = None,
    recipient_powers: "list[int] | None" = None,
) -> bool:
    """
    Port of DELAY_REVIEW (0x00438e60).

    C arguments: the ``PRP ( ... )`` content, the sender byte and the FRM
    recipient list.  Returns True when the proposal's review is delayed.

    C flow:
      1. Strip PRP.  For AND/ORR, collect every child clause that is XDO or
         NOT ( XDO ); otherwise test the single clause.  No XDO clause →
         return False without registering anything: every other proposal is
         answered on the spot by the FRM handler.
      2. Unless ORR, walk DAT_00bb65ec for a record that is unflagged
         (+0x00 != 1), has +0x04 == 0, and whose set A / set B hold exactly
         the plain / negated clauses.  Found → return False (a live record
         already stands for this proposal; nothing is registered).
      3. Otherwise register the proposal through FUN_00431310, which returns
         the FUN_00426140 score.  ORR calls it once per clause of the
         candidate set, each time with the whole set, flagging only the last
         second-pass record, and keeps the maximum (seeded -500000).
      4. Score 0 → log "have delayed its review", archive elapsed + 10000,
         return True.  Any other score → False.
    """
    import logging as _logging
    import time as _t
    _log = _logging.getLogger(__name__)

    plain, negated, is_orr, has_xdo = _proposal_xdo_clauses(content_tokens)
    if not has_xdo:
        return False

    if not is_orr:
        plain_set = {_clause_text(c) for c in plain}
        negated_set = {_clause_text(c) for c in negated}
        for entry in state.g_broadcast_list:
            if not isinstance(entry, dict):
                continue
            if entry.get('sent', False):
                continue
            if int(entry.get('type_flag', 0)) != 0:
                continue
            set_a, set_b = _entry_clause_sets(entry)
            if set_a == plain_set and set_b == negated_set:
                return False

    # FUN_0041a100 builds the candidate set keyed by clause: plain clauses
    # (polarity byte 1) first, then negated ones (polarity 0); a clause
    # already present keeps its first polarity.
    candidates: list = []
    seen: set = set()
    for clause, is_not in [(c, False) for c in plain] + [(c, True) for c in negated]:
        text = _clause_text(clause)
        if text in seen:
            continue
        seen.add(text)
        candidates.append((clause, is_not))

    own_power = int(getattr(state, 'albert_power_idx', 0))
    sender = own_power if sender_power is None else int(sender_power)
    from_tok = 0x4100 | sender
    to_toks = [0x4100 | int(p) for p in (recipient_powers or [])]

    if is_orr:
        best = -500000
        for index in range(len(candidates)):
            score = register_received_press(
                state, content_tokens, from_tok, to_toks,
                flag=1 if index == len(candidates) - 1 else 0,
                candidates=candidates,
            )
            best = max(best, score)
    else:
        best = register_received_press(
            state, content_tokens, from_tok, to_toks,
            flag=1, candidates=candidates,
        )

    if best == 0:
        _log.info(
            "We have received the proposal: but have delayed its review: %s",
            _clause_text(content_tokens),
        )
        state.g_alliance_msg_tree.add(
            int(_t.time() - getattr(state, 'g_turn_start_time', 0.0)) + 10000
        )
        return True
    return False


def register_received_press(
    state: "InnerGameState",
    press_content: list,
    from_power_tok: int,
    to_power_toks: list,
    flag: int = 0,
    candidates: "list | None" = None,
) -> int:
    """
    Port of RegisterReceivedPress = FUN_00431310.

    Called only by DELAY_REVIEW, which passes the ``PRP ( ... )`` content,
    the sender, the recipients, its XDO candidate set (``candidates``:
    ``(clause tokens, negated)`` pairs) and the flag byte for the
    second-pass record.  Returns the FUN_00426140 score, which DELAY_REVIEW
    tests against zero.

    addr: ``0x00431310``
    C signature (Ghidra): ``undefined * FUN_00431310(undefined1 param_1,
        undefined1 param_2, undefined1 param_3, undefined1 param_4,
        undefined2 param_5, undefined1 param_6..9, int **param_11,
        undefined1 param_12)``

    Creates two g_broadcast_list entries for an incoming FRM press proposal
    (bilateral validation: pass-1 "received" entry + pass-2 "confirmed"
    entry) so that BuildAndSendSUB can process them via
    RECEIVE_PROPOSAL → EvaluatePress → RESPOND.

    C flow (verified against Source/communications/register_received_press.c):
      1. Build local power-set map (local_1c8) from from-power + to-powers
         via StdMap_FindOrInsert — absorbed as Python validation.
      2. Build SUB token prefix (local_14c); copy content/from/to into
         scratch lists (local_12c, local_118) — all freed at end; absorbed.
      3. FUN_00426140(local_1e8) → local_1fc: legitimacy gate over the
         candidate set.  Returns a non-null pointer when score > 0.
         When non-null: local_1d4[0]=1 (registration flag) and
         local_1cc=DAT_004c6bbc, i.e. record +0x08 -- the node's completed-
         trial counter -- starts at the cap so BuildAndSendSUB skips it.
         When null: both stay 0. The function always enqueues regardless.
      4. local_134 = __time64(NULL) — wall-clock capture.
      5. Two-pass split of param_11 (order-candidates BST) by candidate polarity:
           type_flag==0 → local_1e4 (positive XDO tree)
           type_flag==1 → local_f0  (negative NOT-XDO tree)
         Pass 1: local_150 = 0xffffffff (no watermark).
                 BuildHostilityRecord + SendAlliancePress(local_1e4).
         Cleanup: both sets cleared.
         Pass 2: re-iterate; local_13c = param_12 (flag byte);
                 local_150 = local_1f8 (watermark = size before pass-1 insert).
                 BuildHostilityRecord + SendAlliancePress(local_1e4).
      6. DAT_00baed60 = puVar4: set to broadcast list size read during the
         second iterator loop body (= size_after, captured before pass-2's
         SendAlliancePress inserts its entry).

    Python mapping:
      param_11 (BST)     → _parse_xdo_candidates() applied to press_content
      BuildHostilityRecord → fields embedded in each entry dict
      local_1d4[0]=1     → sent = True (record +0x00, the byte
                           BuildAndSendSUB.c:215 gates on); history_flag is
                           the port's inert duplicate of the same byte
      local_1cc          → trial_count = g_press_proposals_cap iff gate_score != 0
                           (record +0x08; the same dword BuildAndSendSUB
                            reads and writes as puVar18[8])
      local_1e4/local_f0 → one Python candidate list retaining the polarity
                           byte; CAL_VALUE reconstructs the two C trees
      score_vector[p]    → the one legitimacy_gate score replicated to all
                           seven slots, matching the C assignment loop
      DAT_00baed60       → state.g_broadcast_list_watermark = size_after

    Callees (C):
      FUN_00422960   AllianceRecord constructor      → absorbed
      StdMap_FindOrInsert  power-set map insert      → absorbed
      FUN_00465f60   token-list copy                 → absorbed
      FUN_00466f80   prefix+content list builder     → absorbed
      FUN_00426140   alliance-partner gate           → legitimacy_gate()
      FUN_00410cf0   linked-list sentinel init       → absorbed
      FUN_00419300   std::set<TokenSeq> insert       → absorbed
      BuildHostilityRecord  copy-constructor         → absorbed into entry dict
      SendAlliancePress     RB-tree insert           → send_alliance_press()
      DestroyAllianceRecord destructor               → absorbed
      FUN_0041abc0   BST destructor for param_11     → absorbed (GC)
    """
    import time as _time
    import logging as _logging
    _log = _logging.getLogger(__name__)

    sched_time = int(_time.time())  # C: local_134 = __time64(NULL)

    # Order candidates (the BST param_11).  Candidate type_flag is polarity:
    # 0=XDO, 1=NOT-XDO.  DELAY_REVIEW supplies its candidate set; a direct
    # caller without one gets every XDO clause in the content.
    if candidates is None:
        content_str = ' '.join(str(t) for t in press_content)
        order_candidates = _parse_xdo_candidates(content_str)
    else:
        order_candidates = []
        for clause, negated in candidates:
            clause_str = ' '.join(str(t) for t in clause)
            if negated:
                clause_str = f"NOT ( {clause_str} )"
            parsed = _parse_xdo_candidates(clause_str)
            if parsed:
                order_candidates.append(parsed[0])

    # C line 103: local_1fc = FUN_00426140(local_1e8)
    # Returns a non-null pointer (score != 0) or null (score == 0).
    # Drives local_1d4[0] (registration flag) and local_1cc in both passes.
    own_power_idx = getattr(
        state, 'albert_power_idx',
        getattr(state, 'g_albert_power', 0),
    )
    gate_score = 0
    try:
        gate_score = legitimacy_gate(
            state, int(own_power_idx),
            [{
                'order_seq': c.get('order_seq', c),
                'power': c.get('power', int(own_power_idx)),
                'flag_bit': 0 if c.get('type_flag', 0) == 1 else 1,
            } for c in order_candidates],
        )
        _log.debug("register_received_press: legitimacy_gate -> %d", gate_score)
    except (KeyError, IndexError, TypeError, ValueError) as exc:
        _log.warning("register_received_press: legitimacy_gate raised %s; proceeding", exc)

    # C: local_1d4[0] = 1 and local_1cc = DAT_004c6bbc only when local_1fc != NULL.
    # history_flag maps to local_1d4[0].  CAL_VALUE's delta-baseline branch is
    # instead controlled by local_150 (`watermark`).
    #
    # local_1cc is record +0x08 (BuildHostilityRecord's `int_8` slot), and that
    # is the very dword BuildAndSendSUB uses as the node's completed-trial
    # counter: BuildAndSendSUB.c:220 breaks on `DAT_004c6bbc <= puVar18[8]`,
    # :226 copies it to DAT_0062cc64, :373 writes it back, and :380 marks the
    # node processed once it equals the cap.  A proposal whose legitimacy gate
    # passed is therefore inserted already AT the cap and skips the MC trial
    # loop entirely.  The port previously wrote two separate keys for this one
    # field -- `int_8` (which nothing read) and `trial_count: 0` -- so gated
    # proposals were given a full run of trials.
    #
    # local_1d4[0] is record +0x00.  The record base is node+0x18 -- fixed by
    # the 21-dword score array, which BuildHostilityRecord puts at record +0x30
    # and BuildAndSendSUB.c:625 reads at puVar18+0x12 = node+0x48.  So record
    # +0x00 is the byte BuildAndSendSUB.c:215 gates on (`*(char *)(puVar18 + 6)
    # == '\0'` -- process only unflagged nodes) and sets at :386 when the node
    # is finished; senders.py already documents it as `node+24 / node[6]`, the
    # `sent` flag, and every self-generated record in this port sets `sent` and
    # `history_flag` together.  A proposal whose legitimacy gate passed is
    # therefore enqueued already flagged, and BuildAndSendSUB skips its trial
    # loop entirely -- the gate has decided.  Its RECEIVE_PROPOSAL/
    # EvaluatePress/RESPOND block (BuildAndSendSUB.c:491-570) sits inside that
    # same guard, so a gated proposal is never answered there: DELAY_REVIEW
    # returns "not delayed" and the FRM handler answers it on the spot.
    gate_passed = gate_score != 0
    history_flag = 1 if gate_passed else 0
    trial_count = (
        int(getattr(state, 'g_press_proposals_cap', 30)) if gate_passed else 0
    )

    # C: local_1f8 = DAT_00bb65f4  (g_broadcast_list size before first insert)
    size_before = len(state.g_broadcast_list)

    # C copies the one FUN_00426140 result into every active-power slot.
    score_vec = [int(gate_score)] * 7

    # C lines 64-75: the record's first set (local_1c8) is the sender plus
    # every recipient.  BuildAndSendSUB.c:230-236 copies that set into
    # DAT_00bc1e00 for each trial iteration, and UpdateScoreState.c gates its
    # per-power work on membership in it.
    def _power_of(tok) -> "int | None":
        if isinstance(tok, int):
            return tok & 0x7f if 0x4100 <= tok <= 0x4106 else None
        name = str(tok).strip('()').upper()
        return _DAIDE_POWERS.index(name) if name in _DAIDE_POWERS else None

    participant_powers = set()
    for _tok in [from_power_tok, *to_power_toks]:
        _idx = _power_of(_tok)
        if _idx is not None:
            participant_powers.add(_idx)

    # ── Pass 1: external candidates, watermark = sentinel ────────────────
    # C: local_150 = 0xffffffff (no watermark); key = local_e4[0] = DAT_00bb65f4
    entry1: dict = {
        'sent':             gate_passed,   # local_1d4[0], record +0x00
        'received_flag':    True,          # set by FUN_0042e450 (RB-tree insert)
        'type_flag':        0,             # external / received (sub-B)
        'trial_count':      trial_count,   # local_1cc, record +0x08
        'sched_time':       sched_time,
        'watermark':        None,          # local_150 = 0xffffffff
        'registration_pass': 1,            # plain XDO clauses in set B
        'flag':             0,             # local_13c, record +0x98
        'history_flag':     history_flag,  # local_1d4[0]
        'from_power_tok':   from_power_tok,
        'target_power':     int(from_power_tok) & 0x7f,
        'sublist1':         [from_power_tok],
        'sublist2':         list(to_power_toks),
        'sublist3':         list(press_content),
        'order_candidates': list(order_candidates),
        'score_vector':     list(score_vec),
        'participant_powers': set(participant_powers),   # local_1c8
    }
    send_alliance_press(state, key=size_before, entry_data=entry1)
    _log.debug(
        "register_received_press: pass-1 entry from power_tok=0x%x, content=%s",
        from_power_tok, press_content,
    )

    # ── Pass 2: same candidates, watermark = size before pass-1 ──────────
    # C: local_150 = local_1f8 (= size before pass-1 insert);
    #    local_e4[0] = DAT_00bb65f4 (updated size = size_after);
    #    local_13c = param_12 (flag byte set before second iterator loop).
    size_after = len(state.g_broadcast_list)
    entry2: dict = dict(entry1)
    entry2['watermark']        = size_before   # local_150 = local_1f8
    entry2['registration_pass'] = 2             # plain XDO clauses in set A
    entry2['flag']             = flag           # local_13c = param_12
    entry2['order_candidates'] = list(order_candidates)
    entry2['participant_powers'] = set(participant_powers)
    send_alliance_press(state, key=size_after, entry_data=entry2)

    # C: DAT_00baed60 = puVar4 where puVar4 = DAT_00bb65f4 read during the
    # SECOND iterator loop (before pass-2's SendAlliancePress) = size_after.
    # Consumers check this as a boolean (> 0 means real press arrived).
    state.g_broadcast_list_watermark = size_after
    _log.debug(
        "register_received_press: watermark=%d (size_before=%d)",
        state.g_broadcast_list_watermark, size_before,
    )
    return int(gate_score)
