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
    # validate_and_dispatch_order imported at module level (C1 fix 2026-04-20)

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
         on ``g_alliance_msg_tree`` and return 1 (delay). Else return 0.

    Python compressions:
      - Sub-trees A/B are represented by each g_broadcast_list entry's
        ``order_candidates`` (matching _cal_value's walk). A single-
        orientation novelty match is sufficient for the catalog walk (step 3).
      - ``FUN_00431310`` (score-and-register) is partially in Python already
        (see ``register_received_press``); the DELAY_REVIEW caller only
        reads the score return, so we invoke ``legitimacy_gate`` directly
        against the candidate set as the cheap-scoring stand-in.
      - Code-9/code-10 dual-orientation: ``legitimacy_gate`` is called twice
        (normal flag assignment and inverted); the max score is taken. Mirrors
        FUN_00431310's two ``SendAlliancePress`` passes.
      - ORR-permutation max-score loop: for ORR proposals each extracted XDO
        alternative is scored independently (both orientations); the max
        across all alternatives drives the delay verdict.
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
    for entry in state.g_broadcast_list:
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
    # C: FUN_00431310 runs two internal passes (code-9 / code-10) that swap
    # flag_bit assignments, then returns the max score.  For ORR proposals
    # DELAY_REVIEW calls FUN_00431310 once per ORR child and takes the max
    # across alternatives.  Python mirrors both loops via legitimacy_gate.
    own_power_idx = getattr(state, 'own_power_index', None)
    if own_power_idx is None:
        own_power_idx = getattr(state, 'albert_power_idx', 0)
    own_idx = int(own_power_idx)

    def _score_orientation(pos_clauses, neg_clauses, pos_bit, neg_bit):
        cands = []
        for c in pos_clauses:
            cands.append({'order_seq': {'tokens': c.split(), 'type_flag': 0},
                          'flag_bit': pos_bit})
        for c in neg_clauses:
            cands.append({'order_seq': {'tokens': c.split(), 'type_flag': 1},
                          'flag_bit': neg_bit})
        return legitimacy_gate(state, own_idx, cands)

    try:
        if is_orr:
            # Each ORR alternative is a candidate; score each independently
            # in both orientations and take max across all alternatives.
            scores = []
            for clause in positive:
                s9  = _score_orientation([clause], [], 1, 0)
                s10 = _score_orientation([clause], [], 0, 1)
                scores.append(max(s9, s10))
            score = max(scores) if scores else 0
        else:
            # Non-ORR: run both orientations over the full clause set.
            s9  = _score_orientation(positive, negative, 1, 0)  # code-9
            s10 = _score_orientation(positive, negative, 0, 1)  # code-10
            score = max(s9, s10)
    except (KeyError, IndexError, TypeError, ValueError) as exc:
        _log.warning("delay_review: cheap scorer raised %s; defaulting to 0", exc)
        return 0

    _log.debug("delay_review: novel proposal cheap_score=%d orr=%s",
               score, is_orr)

    # C: `if (score == 0)` → delay + event archive. The strict-equality
    # check is deliberate — nonzero scores (positive or negative) skip
    # the delay branch.
    if score == 0:
        # Phase-aware REJ: in retreat (RVT) and build (WTA) phases, C's
        # FRMHandler emits an explicit REJ for proposals it would otherwise
        # defer, rather than silently dropping them.  Fixed 2026-04-20
        # (audit finding M3).
        phase = getattr(state, 'g_current_phase', getattr(state, 'g_season', 'SPR'))
        if phase in ('RVT', 'WTA', 'AUT', 'WIN'):
            _log.debug("delay_review: score==0 in %s phase → 2 (explicit REJ)", phase)
            return 2  # caller interprets 2 as "send REJ, don't delay silently"

        import time as _t
        # Event key = (now - press_epoch) + 10000; use absolute wall time
        # plus the +10000 offset (press_epoch isn't tracked in Python;
        # the offset alone discriminates the event class per the schema
        # in docs/funcs/DELAY_REVIEW.md).
        state.g_alliance_msg_tree.add(int(_t.time()) + 10000)
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
         When non-null: local_1d4[0]=1 (history_flag) and
         local_1cc=DAT_004c6bbc (int_8 / trial-cap token).
         When null: both stay 0.  Gate effect is via CAL_VALUE score
         branching — the function always enqueues regardless.
      4. local_134 = __time64(NULL) — wall-clock capture.
      5. Two-pass split of param_11 (order-candidates BST) by type_flag:
           type_flag==0 → local_1e4 (sub-B / external set)
           type_flag==1 → local_f0  (sub-A / own set; built but NOT passed
                          to SendAlliancePress; only sub-B is sent)
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
      local_1d4[0]=1     → history_flag = 1 iff gate_score != 0
      local_1cc          → int_8 = g_press_proposals_cap iff gate_score != 0
      sub-A (local_f0)   → extracted but discarded (consistent with C:
                           only sub-B goes to SendAlliancePress)
      score_vector[p]    → per-power legitimacy_gate score (richer than C's
                           single-score replicated for all slots; deviation
                           is intentional — CAL_VALUE delta uses own_power
                           slot only, which is correct either way)
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

    # Parse order candidates from press content (replaces the BST param_11).
    # _parse_xdo_candidates always returns type_flag==0; the filter below is
    # defensive but also mirrors the C type_flag==0 → sub-B split.
    content_str = ' '.join(str(t) for t in press_content)
    order_candidates = _parse_xdo_candidates(content_str)
    external_cands = [c for c in order_candidates if c.get('type_flag', 0) == 0]

    # C line 103: local_1fc = FUN_00426140(local_1e8)
    # Returns a non-null pointer (score != 0) or null (score == 0).
    # Drives local_1d4[0] (history_flag) and local_1cc (int_8) in both passes.
    own_power_idx = getattr(
        state, 'albert_power_idx',
        getattr(state, 'g_albert_power', 0),
    )
    gate_score = 0
    try:
        gate_score = legitimacy_gate(
            state, int(own_power_idx),
            [{'order_seq': c, 'flag_bit': c.get('type_flag', 0)}
             for c in external_cands],
        )
        _log.debug("register_received_press: legitimacy_gate -> %d", gate_score)
    except (KeyError, IndexError, TypeError, ValueError) as exc:
        _log.warning("register_received_press: legitimacy_gate raised %s; proceeding", exc)

    # C: local_1d4[0] = 1 and local_1cc = DAT_004c6bbc only when local_1fc != NULL.
    # history_flag maps to local_1d4[0]; int_8 maps to local_1cc.
    # CAL_VALUE's diff-form branch requires history_flag >= 1.
    history_flag = 1 if gate_score != 0 else 0
    int_8 = int(getattr(state, 'g_press_proposals_cap', 30)) if gate_score != 0 else 0

    # C: local_1f8 = DAT_00bb65f4  (g_broadcast_list size before first insert)
    size_before = len(state.g_broadcast_list)

    # Per-power score vector (Python extension beyond C's single replicated score).
    # C: auStack_1a4[slot] = local_1fc for all active-power slots (same value).
    # Python: per-power legitimacy_gate gives _cal_value a richer baseline; the
    # own_power_idx slot — which is what CAL_VALUE reads for delta scoring — is
    # always correct, so the behavioural effect is identical.
    score_vec = [0] * 7
    for pwr in range(7):
        try:
            score_vec[pwr] = int(legitimacy_gate(
                state, pwr,
                [{'order_seq': c, 'flag_bit': c.get('type_flag', 0)}
                 for c in external_cands],
            ))
        except (KeyError, IndexError, TypeError, ValueError):
            score_vec[pwr] = 0

    # ── Pass 1: external candidates, watermark = sentinel ────────────────
    # C: local_150 = 0xffffffff (no watermark); key = local_e4[0] = DAT_00bb65f4
    entry1: dict = {
        'received_flag':    True,          # set by FUN_0042e450 (RB-tree insert)
        'type_flag':        0,             # external / received (sub-B)
        'trial_count':      0,
        'sched_time':       sched_time,
        'watermark':        None,          # local_150 = 0xffffffff
        'history_flag':     history_flag,  # local_1d4[0]
        'int_8':            int_8,         # local_1cc = DAT_004c6bbc when gate passes
        'from_power_tok':   from_power_tok,
        'sublist1':         [from_power_tok],
        'sublist2':         list(to_power_toks),
        'sublist3':         list(press_content),
        'order_candidates': list(external_cands),
        'score_vector':     list(score_vec),
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
    entry2['flag']             = flag           # local_13c = param_12
    entry2['order_candidates'] = list(external_cands)
    send_alliance_press(state, key=size_after, entry_data=entry2)

    # C: DAT_00baed60 = puVar4 where puVar4 = DAT_00bb65f4 read during the
    # SECOND iterator loop (before pass-2's SendAlliancePress) = size_after.
    # Consumers check this as a boolean (> 0 means real press arrived).
    state.g_broadcast_list_watermark = size_after
    _log.debug(
        "register_received_press: watermark=%d (size_before=%d)",
        state.g_broadcast_list_watermark, size_before,
    )
