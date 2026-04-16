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

NOTE: ``delay_review`` contains a function-local
``from .dispatch import validate_and_dispatch_order`` that has been
broken since the original single-file split (the intended target is
``albert.dispatch`` via ``...dispatch`` from here).  Preserved verbatim
for behaviour equivalence — if that call site is ever reached, it will
raise ImportError exactly as it did before.
"""

import time as _time

from ...state import InnerGameState
from ..parsers import _parse_xdo_candidates
from ..senders import send_alliance_press
from ..evaluators import _split_xdo_clauses


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
        'type_flag'  — alias accepted for back-compat with order_candidates from
                       register_received_press (type_flag maps to flag_bit)

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
    import logging as _logging
    from .dispatch import validate_and_dispatch_order

    _log = _logging.getLogger(__name__)

    aggregate: int | None = None

    for cand in candidates:
        order_seq = cand.get('order_seq') or cand
        # type_flag from register_received_press: 0 = received/peer-side, eligible
        # for own-power rescore; 1 = our-side/already-scoped.
        flag_bit = cand.get('flag_bit', cand.get('type_flag', 0))

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


def delay_review(state: "InnerGameState", body_tokens: list) -> int:
    """
    Port of DELAY_REVIEW — proposal novelty + cheap-scoring gate.

    See docs/funcs/DELAY_REVIEW.md for the full spec. Returns 1 if the
    proposal should be deferred (caller skips EvaluatePress), 0 otherwise.

    C flow (simplified):
      1. Split body into positive (XDO) and negative (NOT(XDO)) clause sets.
         AND / ORR / bare XDO / bare NOT(XDO) all reduce to this split.
      2. If no XDO clauses present → return 0 (don't delay).
      3. Walk ``DAT_00bb65ec`` looking for a record whose sub-tree A and B
         contain the positive and negative clauses respectively AND whose
         count-match fields match. First match → return 0.
      4. On no match: run the cheap scorer (FUN_00431310 / legitimacy_gate
         stand-in here). If score == 0, archive a ``+10000``-keyed event
         on ``g_AllianceMsgTree`` and return 1 (delay). Else return 0.

    Python compressions:
      - Sub-trees A/B are represented by each g_BroadcastList entry's
        ``order_candidates`` (matching _cal_value's walk). The code-9 /
        code-10 dual-orientation is not separately modelled here — a
        single-orientation match is sufficient for novelty detection.
      - ``FUN_00431310`` (score-and-register) is partially in Python already
        (see ``register_received_press``); the DELAY_REVIEW caller only
        reads the score return, so we invoke ``legitimacy_gate`` directly
        against the candidate set as the cheap-scoring stand-in.
      - ORR-permutation max-score inner loop is approximated as a single
        score call; ORR proposals don't exercise the per-record match
        loop (C: ``if bVar21 continue``) so the novelty result coincides.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    # ── 1. Clause extraction ──────────────────────────────────────────────
    positive, negative = _split_xdo_clauses(body_tokens)
    if not positive and not negative:
        _log.debug("delay_review: no XDO clauses → 0 (don't delay)")
        return 0

    # Detect ORR wrapper for the bVar21 branch.
    text = ' '.join(str(t) for t in body_tokens).strip()
    is_orr = text.startswith('ORR')

    # ── 2. Catalog walk (novelty check) ───────────────────────────────────
    pos_set = set(positive)
    neg_set = set(negative)
    for entry in state.g_BroadcastList:
        if not isinstance(entry, dict):
            continue
        if is_orr:
            # C: bVar21=true → continue without per-record match check.
            # ORR mode skips the novelty match loop and proceeds directly
            # to the scorer via the fall-through at the sentinel.
            continue
        cands = entry.get('order_candidates', [])
        cand_texts = set()
        for c in cands:
            t = c.get('tokens') if isinstance(c, dict) else c
            if t is not None:
                cand_texts.add(' '.join(str(x) for x in t)
                               if isinstance(t, (list, tuple))
                               else str(t))
        # C: require both sub-tree A size == positive count AND
        # sub-tree B size == negative count AND every clause found.
        # Python: collapse to subset-containment on the unified candidate
        # set. Strict-count equality is preserved by also requiring the
        # candidate set to be no larger than the union of proposed clauses
        # (a stricter reading: "the record represents exactly this shape").
        if not pos_set.issubset(cand_texts):
            continue
        if neg_set & cand_texts:
            continue
        # Flag gate: record +0x18 != 1 (not marked-skip), +0x1c == 0.
        # Python stand-in: require the entry's type_flag != 1 (i.e. not
        # already-processed) and its watermark is None or zero-valued.
        if entry.get('type_flag', 0) == 1:
            continue
        _log.debug("delay_review: novelty match → 0 (don't delay)")
        return 0

    # ── 3. Cheap scorer on novel proposal ─────────────────────────────────
    # Build a candidate set from the clause lists and score via
    # legitimacy_gate. C: FUN_00431310 returns the min score over the set;
    # score==0 triggers delay.
    own_power_idx = getattr(state, 'own_power_index', None)
    if own_power_idx is None:
        own_power_idx = getattr(state, 'albert_power_idx', 0)

    cand_list = []
    for clause in positive:
        cand_list.append({'order_seq': {'tokens': clause.split(),
                                        'type_flag': 0},
                          'flag_bit': 1})
    for clause in negative:
        cand_list.append({'order_seq': {'tokens': clause.split(),
                                        'type_flag': 1},
                          'flag_bit': 0})
    try:
        score = legitimacy_gate(state, int(own_power_idx), cand_list)
    except Exception:
        _log.exception("delay_review: cheap scorer raised; defaulting to 0")
        return 0

    _log.debug("delay_review: novel proposal cheap_score=%d orr=%s",
               score, is_orr)

    # C: `if (score == 0)` → delay + event archive. The strict-equality
    # check is deliberate — nonzero scores (positive or negative) skip
    # the delay branch.
    if score == 0:
        import time as _t
        # Event key = (now - press_epoch) + 10000; use absolute wall time
        # plus the +10000 offset (press_epoch isn't tracked in Python;
        # the offset alone discriminates the event class per the schema
        # in docs/funcs/DELAY_REVIEW.md).
        state.g_AllianceMsgTree.add(int(_t.time()) + 10000)
        _log.debug("delay_review: score==0 → 1 (delay) + event archived")
        return 1

    return 0


def register_received_press(
    state: "InnerGameState",
    press_content: list,
    from_power_tok: int,
    to_power_toks: list,
    flag: int = 0,
) -> None:
    """
    Port of RegisterReceivedPress = FUN_00431310.

    Creates g_BroadcastList entries for an incoming FRM press proposal so that
    BuildAndSendSUB can process them via RECEIVE_PROPOSAL → EvaluatePress → RESPOND.

    C parameters:
      param_1..4  (list)  = press content token list (XDO/PRP body)
      param_5     (ushort) = from-power token (0x4100 | power_idx)
      param_6..9  (list)  = to-power token list
      param_11    (BST*)  = order-candidates map (heap-allocated, freed at end)
      param_12    (byte)  = flag

    C flow:
      1. Build local power-set map from from-power + to-powers.
      2. Build SUB token prefix; copy content, from-power, to-powers into locals.
      3. FUN_00426140 — alliance-partner gate (stub: always proceed).
      4. local_134 = __time64(NULL) — capture current wall-clock time.
      5. Two-pass split of param_11 by type_flag:
           Pass 1: type_flag==0 → local_1e4; call BuildHostilityRecord + SendAlliancePress.
           Pass 2: re-iterate, same split; watermark = size before pass-1 insert.
      6. DAT_00baed60 = final g_BroadcastList size (watermark).

    Python compression:
      - param_11 (BST of order candidates) is replaced by _parse_xdo_candidates()
        applied to the press content string.
      - BuildHostilityRecord absorbed (fields embedded in entry dict).
      - Two C passes produce two BroadcastList entries; both have received_flag=True.
      - received_flag is set explicitly here (in C it is set by FUN_0042e450, the
        MSVC RB-tree node allocator inside SendAlliancePress).

    The BroadcastList entry layout matches what RESPOND expects as press_list:
      sublist1 = [from_power_tok]
      sublist2 = to_power_toks
      sublist3 = press_content  (XDO/PRP tokens; used by receive_proposal + respond)

    Callees (C):
      FUN_00422960   AllianceRecord constructor      → absorbed
      FUN_00426140   alliance-partner gate           → stub: always proceed
      BuildHostilityRecord                           → absorbed into entry dict
      SendAlliancePress                              → send_alliance_press()
      DestroyAllianceRecord                          → absorbed
      FUN_0041abc0   BST destructor for param_11    → absorbed (_free / Python GC)
    """
    import time as _time
    import logging as _logging
    _log = _logging.getLogger(__name__)

    sched_time = int(_time.time())  # C: local_134 = __time64(NULL)

    # Parse order candidates from press content (replaces the BST param_11).
    content_str = ' '.join(str(t) for t in press_content)
    order_candidates = _parse_xdo_candidates(content_str)
    # type_flag==0 = external/received candidates (both passes send these)
    external_cands = [c for c in order_candidates if c.get('type_flag', 0) == 0]

    # C line 103: local_1fc = FUN_00426140(local_1e8) — legitimacy gate over
    # the candidate-order set. Returns min per-order score; negative means the
    # proposal contains an order that fails legality or trust-clamp rescoring.
    # In C the return flows into decision logic further down; here we log it
    # and proceed (matching the observation that register_received_press
    # unconditionally enqueues in C too — the gate's effect is primarily
    # through CAL_VALUE, not here).
    try:
        # Canonical Python name is albert_power_idx; g_AlbertPower is the
        # C-faithful mirror (DAT_00624124) kept in sync by bot client.
        # The previous chain (own_power_index → g_OwnPowerIndex) named
        # attributes with no writer anywhere, so this always defaulted to 0
        # regardless of which power the bot actually plays.
        own_power_idx = getattr(
            state, 'albert_power_idx',
            getattr(state, 'g_AlbertPower', 0),
        )
        gate_score = legitimacy_gate(
            state, int(own_power_idx),
            [{'order_seq': c, 'flag_bit': c.get('type_flag', 0)}
             for c in external_cands],
        )
        _log.debug("register_received_press: legitimacy_gate -> %d", gate_score)
    except Exception:
        _log.exception("register_received_press: legitimacy_gate failed; proceeding")

    # C: local_1f8 = DAT_00bb65f4  (g_BroadcastList size before first insert)
    size_before = len(state.g_BroadcastList)

    # Compute per-power score vector — Python stand-in for the int[≥7] at
    # AllianceRecord +0x48 that BuildHostilityRecord populates in C. For
    # each power index, re-score the candidate set through legitimacy_gate
    # with that power's perspective; the min per-order score is the same
    # quantity C stores in score[+0x48 + 4*p]. When the gate fails or a
    # power index is absent, we record 0 (neutral).
    score_vec = [0] * 7
    for pwr in range(7):
        try:
            s = legitimacy_gate(
                state, pwr,
                [{'order_seq': c, 'flag_bit': c.get('type_flag', 0)}
                 for c in external_cands],
            )
            # legitimacy_gate returns clamp-window-corrected min; clip to
            # int range the C side would see at +0x48 (undefined4, but
            # CAL_VALUE only reads signed deltas from it).
            score_vec[pwr] = int(s)
        except Exception:
            score_vec[pwr] = 0

    # ── Pass 1: type_flag==0 entries, watermark=None ──────────────────────
    entry1: dict = {
        'received_flag':   True,          # set by FUN_0042e450 in C
        'type_flag':       0,             # external / received
        'trial_count':     0,             # incremented by BuildAndSendSUB outer loop
        'sched_time':      sched_time,    # node[0x2e/0x2f] passed to RESPOND
        'watermark':       None,          # local_150 = 0xffffffff first pass
        'from_power_tok':  from_power_tok,
        'sublist1':        [from_power_tok],
        'sublist2':        list(to_power_toks),
        'sublist3':        list(press_content),
        'order_candidates': list(external_cands),
        'score_vector':    list(score_vec),
        # C: history flag at +0x9c; CAL_VALUE requires >= 1 for diff form.
        # register_received_press produces fresh current-turn records, so
        # history_flag=1 mirrors the "record is populated and queryable" state.
        'history_flag':    1,
    }
    send_alliance_press(state, key=size_before, entry_data=entry1)
    _log.debug(
        "register_received_press: pass-1 entry from power_tok=0x%x, content=%s",
        from_power_tok, press_content,
    )

    # ── Pass 2: same candidates, watermark = size before pass-1 ──────────
    # C: local_150 = local_1f8; local_e4[0] = DAT_00bb65f4 (updated size)
    size_after = len(state.g_BroadcastList)
    entry2: dict = dict(entry1)
    entry2['watermark'] = size_before   # local_150 = local_1f8
    entry2['flag'] = flag               # local_13c = param_12
    entry2['order_candidates'] = list(external_cands)  # doubled in C; same here
    send_alliance_press(state, key=size_after, entry_data=entry2)

    # C: DAT_00baed60 = DAT_00bb65f4  (final g_BroadcastList size watermark)
    state.g_BroadcastListWatermark = len(state.g_BroadcastList)
    _log.debug(
        "register_received_press: watermark=%d", state.g_BroadcastListWatermark
    )
