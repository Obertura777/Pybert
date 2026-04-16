"""Albert DAIDE / press-handling subpackage.

Originally a single 6,174-line ``communications.py``.  Split into
submodules during the 2026-04 refactor:

- ``tokens``      — DAIDE token primitives and press-type token constants
- ``parsers``     — XDO / press-content text and token parsers (pure, no state)
- ``scheduling``  — scheduled-press dispatch queue + ThennAction execution
- ``senders``     — outbound press senders, proposal builders, dispatch loop
- ``evaluators``  — press-evaluation pipeline, legitimacy handlers, proposal scoring

All public names previously importable as ``albert.communications.X`` remain
available at that path via the re-exports below; nothing external should need
to change.
"""

import time as _time

from ..state import InnerGameState
from ..monte_carlo import check_time_limit

# ── Re-exports from submodules (preserve flat public surface) ────────────────
from .tokens import (
    _TOK_ALY, _TOK_DMZ, _TOK_ORR, _TOK_PCE, _TOK_AND, _TOK_VSS, _TOK_XDO,
    _token_seq_copy,
    _token_seq_overlap,
    _token_seq_no_overlap,
    _token_seq_concat_single,
    _token_seq_count,
    _token_seq_less,
    _wrap_single_token,
    _get_daide_context_ptr,
)
from .parsers import (
    _DAIDE_TO_ORDER_TYPE_TAG,
    _extract_top_paren_groups,
    _parse_xdo_candidates,
    _split_top_level_groups,
    _parse_unit_triple,
    _parse_destination,
    _parse_xdo_body_to_order,
)
from .scheduling import (
    dispatch_scheduled_press,
    _send_ally_press_by_power,
    _fun_004117d0,
    _press_gate_check,
    _press_list_count,
    _find_press_token,
    _press_token_found,
    _renegotiate_pce,
    _execute_aly_vss,
    _execute_xdo,
    _execute_then_action,
)
from .senders import (
    send_alliance_press,
    emit_xdo_proposals_to_broadcast,
    score_order_candidates_from_broadcast,
    propose_dmz,
    _update_relation_history,
    friendly,
    _friendly_peace_signal_check,
    cancel_prior_press,
    _is_game_active,
    _check_server_reachable,
    dispatch_press_and_fallback_gof,
    _prepare_ally_press_entry,
)
from .evaluators import (
    _POWER_NAMES, _NEUTRAL_POWER,
    _pow_idx, _eval_pce,
    _flatten_section, _extract_powers, _extract_provs, _ally_trust_ok,
    _eval_dmz, _eval_aly, _split_xdo_clauses, _cal_value,
    _eval_slo, _eval_drw, _eval_not_pce, _eval_not_dmz,
    _eval_sub_xdo, _eval_single_xdo, evaluate_press,
    compute_order_dip_flags, cal_move,
    _handle_pce, _handle_aly, _handle_dmz, _handle_xdo,
    _score_support_opp, _score_sup_attacker,
    _cancel_pce, _remove_dmz, _not_xdo,
)



def process_hst(state: InnerGameState, message: str):
    """
    Port of ParseHSTResponse (FUN_0041b410).
    Maps host capability tables.
    """
    import re
    import random
    
    # Parse LVL
    lvl_match = re.search(r'LVL(?:\s*\(\s*(\d+)\s*\)|.*?(\d+))', message)
    if lvl_match:
        lvl = int(lvl_match.group(1) or lvl_match.group(2))
        state.g_HistoryCounter = lvl

    # Parse MTL 
    mtl_match = re.search(r'MTL(?:\s*\(\s*(\d+)\s*\)|.*?(\d+))', message)
    if mtl_match:
        mtl = int(mtl_match.group(1) or mtl_match.group(2))
        state.g_MoveTimeLimit = mtl

    # Initialize per-game press threshold randomization (0-98)
    state.g_PressThreshRandom = random.randrange(50) + random.randrange(50)
    
    # Force press level config override if needed
    if getattr(state, 'g_ForceDisablePress', 0) == 1:
        state.g_HistoryCounter = 0

    # Populate per-power allowed-press-type maps (DAT_00bb6e10[p*0xc]).
    # C: RegisterAllowedPressToken called for each token in g_AllowedPressTokenList[0..lvl-1].
    # Threshold table (research.md §3548-3552):
    #   lvl > 9:  adds PCE, ALY, VSS, DMZ
    #   lvl > 19: adds XDO
    #   lvl > 29: adds AND, ORR
    lvl = state.g_HistoryCounter
    allowed: set = set()
    if lvl > 9:
        allowed |= {_TOK_PCE, _TOK_ALY, _TOK_VSS, _TOK_DMZ}
    if lvl > 19:
        allowed.add(_TOK_XDO)
    if lvl > 29:
        allowed |= {_TOK_AND, _TOK_ORR}
    num_powers = getattr(state, 'g_NumPowers', 7)
    state.g_press_history = {p: set(allowed) for p in range(num_powers)}

import re


# ── FUN_0042c970: ack-matcher ────────────────────────────────────────────────

# DAIDE verdict tokens used by the ack-matcher to route bookkeeping between
# the role-B (YES-ack) and role-C (REJ/BWX-ack) sets.
_ACK_TOK_YES = 0x481C
_ACK_TOK_REJ = 0x4814
_ACK_TOK_BWX = 0x4A02


def ack_matcher(
    state: "InnerGameState",
    sender_power: int,
    ack_tok: int,
    proposal_tokens: "list | None" = None,
) -> int:
    """
    Port of FUN_0042c970 — the ack-matcher that walks ``g_PosAnalysisList``
    (DAT_00bb65c8) looking for an unprocessed received-proposal whose
    sender matches an incoming YES/REJ/BWX ack, then runs role-set
    bookkeeping for each match.

    C semantics (from FRMHandler.md + daide_semantics_notes.md):

      For each node in DAT_00bb65c8 where ``node.processed_flag == 0``:
        * Primary sender-match: check slots at +0xc and +0xf against
          ``sender_power`` (both must match — the same power is stored
          in both slots in practice).
        * On non-YES acks (REJ / BWX), an additional check at +0x12 is
          required to match.
        * If matched:
            - ``YES`` → StdMap_FindOrInsert into role-B sub-tree.
            - ``REJ`` / ``BWX`` → StdMap_FindOrInsert into role-C
              sub-tree; additionally *reset* role-C's sub-list.
            - Emit a ``+10000``-keyed event into ``DAT_00bbf638``
              (``g_AllianceMsgTree``) for each match.

      **Note:** the C does NOT set ``processed_flag = 1`` on the node —
      the ack does not retire the proposal from the tree. We mirror
      that here (the flag is only consulted as a read-side filter).

      Returns 1 if any node matched, 0 otherwise.

    The ``proposal_tokens`` parameter is optional; when provided it is
    used as an additional overlap gate against ``node.tokens`` to
    disambiguate when multiple pending proposals share a sender (the C
    disambiguates via identity of the local copy; in Python the natural
    proxy is a token-set overlap).
    """
    import logging as _logging
    import time as _t
    _log = _logging.getLogger(__name__)

    is_yes = (ack_tok == _ACK_TOK_YES)
    match_count = 0

    for entry in getattr(state, 'g_PosAnalysisList', []):
        if not isinstance(entry, dict):
            continue
        if entry.get('processed_flag', 0) != 0:
            continue

        # Primary sender-power match (C: slots +0xc and +0xf).
        if entry.get('sender_power') != sender_power:
            continue

        # Non-YES acks require the +0x12 secondary slot to also match
        # (in Python ``sender_power`` already represents both slots, so
        # the extra check is structural: we simply accept when the
        # primary match holds).
        # Optional token-set overlap gate for disambiguation.
        if proposal_tokens is not None:
            entry_tokens = entry.get('token_set') or frozenset(entry.get('tokens', []))
            if not _token_seq_overlap(list(entry_tokens), list(proposal_tokens)):
                continue

        # ── Role-set bookkeeping ──────────────────────────────────────────
        if is_yes:
            entry.setdefault('role_b_set', set()).add(sender_power)
        else:
            # REJ / BWX path: insert into role-C and reset the sub-list.
            role_c = entry.setdefault('role_c_set', set())
            role_c.add(sender_power)
            # C: "on REJ/BWX also resets role-C's +0x16 sub-list" — clear
            # any accumulated secondary state for this entry.
            entry['role_c_sub'] = []

        # ── +10000-keyed event into g_AllianceMsgTree ─────────────────────
        # C: BuildAllianceMsg(&DAT_00bbf638, buf, elapsed_sec + 10000).
        state.g_AllianceMsgTree.add(int(_t.time()) + 10000)

        match_count += 1
        _log.debug(
            "ack_matcher: matched sender=%d tok=0x%x (role=%s) match_count=%d",
            sender_power, ack_tok, 'B' if is_yes else 'C', match_count,
        )

    return 1 if match_count > 0 else 0


# ── FUN_0042cd70: HUH ERR-strip replay ───────────────────────────────────────

def huh_err_strip_replay(
    state: "InnerGameState",
    sender_power: int,
    huh_body_tokens: list,
) -> int:
    """
    Port of FUN_0042cd70 — inbound-HUH handler that salvages the
    successfully-parsed subset of our own press as an implicit ack.

    C flow (from FRMHandler.md:141 + follow-up #234):

      1. Allocate a filtered buffer.
      2. Walk the HUH body, copying tokens while skipping ``ERR``
         sentinels (the peer inserts ``ERR`` at positions they could
         not parse).
      3. Log ``"message :%s"`` with the filtered remainder.
      4. If the filtered remainder is non-empty, call the ack-matcher
         on it — the parseable subset is thereby treated as a de-facto
         YES-ack against our pending proposals.

    Returns the ack-matcher's return (1 = any node matched, 0 = none)
    or 0 when the filtered remainder is empty.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    # Strip ERR tokens (both string-mode 'ERR' and the raw ushort code).
    _ERR_TOK_STR = 'ERR'
    _ERR_TOK_INT = 0x4D00  # DAIDE ERR token code (canonical)
    filtered = [
        t for t in huh_body_tokens
        if not (
            (isinstance(t, str) and t.upper() == _ERR_TOK_STR)
            or (isinstance(t, int) and t == _ERR_TOK_INT)
        )
    ]

    _log.debug("huh_err_strip_replay: message :%r", filtered)

    if not filtered:
        return 0

    # Replay through ack-matcher. The peer's parsed subset is treated as
    # an implicit YES-ack — we can't know which verdict they would have
    # sent, but the ack-matcher's YES path is the "affirmative role-B"
    # bookkeeping which matches the salvage intent.
    return ack_matcher(
        state, sender_power, _ACK_TOK_YES, proposal_tokens=filtered,
    )


# ── FUN_0041c0f0: inbound TRY stance-token updater ───────────────────────────

# DAIDE token numeric codes for stance/press tokens that appear in a TRY body.
# Extends the set used for g_press_history keys; mirrors DAT_00bb6f0c's
# canonical vocabulary order on the C side.
_STANCE_TOKEN_CODES = {
    'PCE': _TOK_PCE,
    'ALY': _TOK_ALY,
    'VSS': _TOK_VSS,
    'DMZ': _TOK_DMZ,
    'AND': _TOK_AND,
    'ORR': _TOK_ORR,
    'XDO': _TOK_XDO,
    'PRP': 0x4A11,
    'YES': 0x4A12,
    'REJ': 0x4A13,
    'BWX': 0x4A14,
    'HUH': 0x4A15,
    'TRY': 0x4A16,
    'FCT': 0x4A17,
    'THK': 0x4A18,
    'WHY': 0x4A19,
    'IDK': 0x4A1A,
    'SUG': 0x4A1B,
    'HOW': 0x4A1D,
    'QRY': 0x4A1E,
    'NOT': 0x4A20,
    'NAR': 0x4A21,
    'CCL': 0x4A22,
    'FRM': 0x4A23,
    'SND': 0x4A24,
}


def process_try(
    state: "InnerGameState",
    sender_id: int,
    try_body_tokens: list,
) -> None:
    """
    Port of FUN_0041c0f0 — inbound TRY stance-token updater.

    Consumes the body of an inbound ``FRM(sender)(TRY(tok₁ tok₂ ...))``
    message. **Replaces** Albert's stored stance-token set for ``sender``
    (the C DAT_00bb6e10[sender * 0xc] slot) with the tokens listed in the
    TRY body. Sends no reply.

    Used by downstream hostility scoring (HOSTILITY.c) which queries
    ``std::set::find(g_press_history[sender], PCE)`` etc. to read how
    the sender has declared their stance.

    The C shape (from ExecuteThennAction.md + ParseHSTResponse.md):
        clear g_press_history[sender]           # manual RB-tree teardown
        for tok in body:
            RegisterAllowedPressToken(g_press_history[sender], tok)

    Parameters
    ----------
    sender_id : int
        Power index of the TRY sender (0..6).
    try_body_tokens : list
        Tokens as strings (e.g. ``['PCE', 'ALY']``) or ints. Strings are
        resolved via ``_STANCE_TOKEN_CODES``; unknown strings are ignored.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    # Replace (not merge) — C clears the slot before re-inserting.
    new_set: set = set()
    for tok in try_body_tokens:
        if isinstance(tok, str):
            code = _STANCE_TOKEN_CODES.get(tok.upper())
            if code is None:
                continue
            new_set.add(code)
        elif isinstance(tok, int):
            new_set.add(tok)

    state.g_press_history[sender_id] = new_set
    _log.debug(
        "process_try: sender=%d stance-tokens replaced with %r",
        sender_id, new_set,
    )


# ── FUN_00426140: per-order legitimacy gate ──────────────────────────────────

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


# ── DELAY_REVIEW ─────────────────────────────────────────────────────────────

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


# ── RegisterReceivedPress = FUN_00431310 ─────────────────────────────────────

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
        own_power_idx = getattr(state, 'own_power_index', None)
        if own_power_idx is None:
            own_power_idx = getattr(state, 'g_OwnPowerIndex', 0)
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


def process_frm_message(state: InnerGameState, sender: str, sub_message: str):
    """
    Port of process_frm and FRIENDLY logic (FUN_0042dc40).
    Updates g_AllyMatrix and sets relation tracking arrays by unpacking FRM envelopes.
    Also calls register_received_press (FUN_00431310) for incoming XDO/PRP proposals.
    """
    power_names = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]

    sender_upper = sender.upper()
    if sender_upper not in power_names:
        return

    sender_id = power_names.index(sender_upper)

    # ── XDO / PRP press proposal → register for BuildAndSendSUB processing ──
    # C: FUN_00431310 called when FRM contains a press proposal (XDO/PRP body).
    # Parse the FRM envelope: FRM ( from ) ( to... ) ( press_content )
    if 'XDO' in sub_message or 'PRP' in sub_message:
        groups = _extract_top_paren_groups(sub_message)
        # groups[0] = from_power names, groups[1] = to_power names, groups[2] = content
        if len(groups) >= 3:
            to_str = groups[1]
            content_str = groups[2]
        elif len(groups) >= 2:
            to_str = groups[0]   # FRM keyword stripped; fallback
            content_str = groups[1]
        else:
            to_str = ''
            content_str = groups[0] if groups else sub_message

        # Build to-power token list
        to_power_toks = [
            power_names.index(p) | 0x4100
            for p in to_str.upper().split()
            if p in power_names
        ]
        # from-power token (sender already parsed above)
        from_power_tok = sender_id | 0x4100
        # press content as a token list (strings for Python string-mode press)
        press_tokens = content_str.split()

        # C FRMHandler (PRP branch): `if (!DELAY_REVIEW(body)) { EvaluatePress(...) }`.
        # DELAY_REVIEW returns 1 to defer review on novel low-score proposals;
        # returns 0 to proceed with EvaluatePress + RESPOND. In SPR/FAL movement
        # phases C just drops deferred proposals; in retreat/winter it emits
        # REJ. We mirror the movement-phase drop (simplest parity) and skip
        # register_received_press entirely when the gate says delay.
        if delay_review(state, press_tokens):
            import logging as _logging
            _logging.getLogger(__name__).debug(
                "process_frm_message: DELAY_REVIEW=1 → dropping press_tokens=%r",
                press_tokens,
            )
        else:
            register_received_press(
                state,
                press_content=press_tokens,
                from_power_tok=from_power_tok,
                to_power_toks=to_power_toks,
            )

    # ── YES / REJ / BWX inbound: ack against our pending proposal (FUN_0042c970) ──
    # C: FRMHandler body_tok ∈ {YES, REJ, BWX} → ack_matcher over DAT_00bb65c8.
    for ack_name, ack_tok in (('YES', _ACK_TOK_YES), ('REJ', _ACK_TOK_REJ), ('BWX', _ACK_TOK_BWX)):
        # Detect the ack verbatim at top level — a simple `ack_name (` probe
        # mirrors the FRMHandler body-token check.
        if f'{ack_name} (' in sub_message:
            match = re.search(rf'{ack_name} \(([^()]*)\)', sub_message)
            body = match.group(1).split() if match else []
            ack_matcher(state, sender_id, ack_tok,
                        proposal_tokens=body if body else None)

    # ── HUH inbound: peer ERR-strip replay salvage (FUN_0042cd70) ──────────
    # C: FRMHandler body_tok == HUH → huh_err_strip_replay, which strips
    # ERR tokens from the echoed body and replays the remainder through the
    # ack-matcher.
    if 'HUH (' in sub_message:
        match = re.search(r'HUH \((.*)\)', sub_message)
        if match:
            huh_body = match.group(1).split()
            huh_err_strip_replay(state, sender_id, huh_body)

    # ── TRY inbound: sender declares their stance tokens toward us (FUN_0041c0f0) ──
    # C: replaces DAT_00bb6e10[sender*0xc] with body tokens; no reply. Consumed
    # by HOSTILITY.c for stance-based scoring.
    if 'TRY' in sub_message and 'TRY (' in sub_message:
        match = re.search(r'TRY \(([^()]*)\)', sub_message)
        if match:
            try_body = match.group(1).split()
            process_try(state, sender_id, try_body)

    # Process explicit DAIDE ALY proposals/confirmations.
    if "ALY (" in sub_message:
        match = re.search(r'ALY \((.*?)\)', sub_message)
        if match:
            allies = match.group(1).split()
            for ally in allies:
                ally_upper = ally.strip().upper()
                if ally_upper in power_names:
                    ally_id = power_names.index(ally_upper)
                    if ally_id != sender_id:
                        # Establish explicit bilateral bounds
                        state.g_AllyMatrix[sender_id, ally_id] = 1
                        state.g_AllyMatrix[ally_id, sender_id] = 1

                        # Increment trust progressively
                        state.g_AllyTrustScore[sender_id, ally_id] += 1.0
                        state.g_AllyTrustScore[ally_id, sender_id] += 1.0

    # Process explicit rejections
    elif "REJ (" in sub_message and "ALY" in sub_message:
        match = re.search(r'ALY \((.*?)\)', sub_message)
        if match:
            allies = match.group(1).split()
            for ally in allies:
                ally_upper = ally.strip().upper()
                if ally_upper in power_names:
                    ally_id = power_names.index(ally_upper)
                    if ally_id != sender_id:
                        # Break alliance mapping forcefully
                        state.g_AllyMatrix[sender_id, ally_id] = 0
                        state.g_AllyMatrix[ally_id, sender_id] = 0

                        # Degrade trust aggressively on rejections
                        current_trust = state.g_AllyTrustScore[sender_id, ally_id]
                        state.g_AllyTrustScore[sender_id, ally_id] = max(0.0, current_trust - 2.0)

def parse_message(state: InnerGameState, sender: str, message: str):
    """
    Main communication ingest port (FUN_0045f1f0).
    Hooks into bot.py's message receiver.
    """
    if "HST" in message:
        process_hst(state, message)
    elif "FRM" in message:
        process_frm_message(state, sender, message)


# ── RECEIVE_PROPOSAL ─────────────────────────────────────────────────────────

def receive_proposal(
    state: "InnerGameState",
    sender_power: int,
    proposal_tokens: list,
    send_fn=None,
) -> None:
    """
    Port of RECEIVE_PROPOSAL (named; no binary address recovered by Ghidra).

    Deduplicates an incoming proposal press against g_PosAnalysisList
    (DAT_00bb65c8/cc).  If this proposal has not yet been recorded:

      1. Appends its token sequence to g_PosAnalysisList.
      2. Logs "We have received the proposal: %s" (mirrors C SEND_LOG).
      3. Adds sender_power to g_AllianceMsgTree (DAT_00bbf638) — the Python
         equivalent of BuildAllianceMsg's sorted-BST insert.
      4. Calls _prepare_ally_press_entry(state, sender_power) [FUN_00418db0
         stub — marks the sender's press-entry as pending for RESPOND].

    C parameters (recovered as in_stack offsets by Ghidra, pushed by caller):
      +0x14  sender_power     — byte index of the sending power
      +0x18  proposal_tokens  — ordered token list (iterated for map inserts)
      +0x04  sub_tokens       — token list used by FUN_00465d90 overlap check
                                (same data as proposal_tokens in practice;
                                 Python uses proposal_tokens for both roles)

    Called from BuildAndSendSUB when:
      puVar18[0x2c] == 1  (has-received-proposal flag set)
      puVar18[7]    == 0  (not yet marked as sent)

    Callees absorbed inline:
      FUN_00465870  — std::list default-constructor → []
      FUN_0047020b  — get own-power context ptr (→ state.albert_power_idx)
      FUN_004243a0  — init analysis-record struct (→ absorbed, no Python state)
      FUN_00465930  — TokenSeq_Count (→ len())
      FUN_00401950  — list content destructor (→ no-op; locals start empty)
      StdMap_FindOrInsert  — std::map lower-bound+insert (→ set.add / dict)
      FUN_00419cb0  — list/range iterator init for g_PosAnalysisList (→ loop)
      FUN_00411a80  — bind iteration to DAT_00bb65d4 secondary sentinel (→ loop)
      GetListElement  — indexed token fetch (→ list index)
      FUN_00465d90  — token-seq overlap bool (→ frozenset intersection)
      GameBoard_GetPowerRec — power-record lookup (→ absorbed; inner loop only
                              fires for nodes with power_count>0, which never
                              occurs for freshly inserted entries → no-op)
      TreeIterator_Advance  — BST iterator step (→ absorbed in loop)
      FUN_0040f860  — std::list::iterator++ (→ Python for-loop)
      FUN_00465f60  — token-list copy (→ list())
      FUN_004223c0  — analysis-struct copy/init (→ absorbed)
      FUN_00430370  — std::list insert at sentinel (→ list.append)
      FUN_00421400  — free analysis struct (→ no-op)
      FreeList      — free temp token list (→ no-op)
      FUN_0046b050  — token-list → string repr (→ str(), already in unchecked)
      SEND_LOG      — debug/log sink (→ logging.info)
      BuildAllianceMsg — BST insert of sender into DAT_00bbf638
                         (→ g_AllianceMsgTree.add; already in unchecked)
      FUN_00418db0  — PrepareAllyPressEntry (→ _prepare_ally_press_entry stub)
    """
    import logging as _log_module
    _log = _log_module.getLogger(__name__)

    # ── Overlap check against g_PosAnalysisList ───────────────────────────────
    # C outer loop iterates g_PosAnalysisList nodes; FUN_00465d90(node+4, &stack4)
    # returns True when node's token set overlaps the incoming proposal.
    # The inner power-record loop uses piStack_c8 which is always empty for
    # freshly inserted entries (power_count == 0), so it never executes and
    # acStack_102[0] stays '\x01' → the outer loop breaks immediately on any
    # overlap, treating the proposal as already seen.
    proposal_set = frozenset(proposal_tokens)
    already_seen = any(
        proposal_set & entry['token_set']
        for entry in state.g_PosAnalysisList
    )

    if already_seen:
        return

    # ── Insert into g_PosAnalysisList ────────────────────────────────────────
    # C: FUN_00465f60(copy, &stack4)  →  copy proposal token list
    #    FUN_004223c0(analysis, record)  →  init analysis struct (absorbed)
    #    FUN_00430370(&sentinel, &iter, copy)  →  std::list insert
    state.g_PosAnalysisList.append({
        'tokens': list(proposal_tokens),
        'token_set': proposal_set,
        'power_count': 0,   # C node[0xe]; always 0 for newly inserted entries
        # ── Ack-matcher schema extension (2026-04-14) ──────────────────────
        # FUN_0042c970 keys sender-match against C node offsets +0xc/+0xf/+0x12.
        # +0xc / +0xf both hold the sender power (primary check on any ack).
        # +0x12 is the secondary slot consulted on non-YES (REJ/BWX) acks.
        # In the Python model a single ``sender_power`` captures both.
        'sender_power':     sender_power,
        'processed_flag':   0,          # C node[+8]; 0 = unprocessed, set by ack-matcher bookkeeping
        'role_b_set':       set(),      # C node[+0x0e / per-role sub-tree] — YES-ack role-B set
        'role_c_set':       set(),      # C node[+0x16 / per-role sub-tree] — REJ/BWX role-C set
    })

    # ── Log ──────────────────────────────────────────────────────────────────
    # C: FUN_0046b050(&stack4, buf) → string repr of token list
    #    SEND_LOG(&pvStack_ec, L"We have received the proposal: %s")
    _log.info("We have received the proposal: %s", proposal_tokens)

    # ── BuildAllianceMsg — record sender in g_AllianceMsgTree ────────────────
    # C: puStack_f4 = (int)(elapsed_seconds + 10000)
    #    BuildAllianceMsg(&DAT_00bbf638, &pvStack_e8, (int *)&puStack_f4)
    # Python models g_AllianceMsgTree keyed by power index rather than by the
    # C timestamp value (elapsed_seconds + 10000).
    build_alliance_msg(state, sender_power)

    # ── PrepareAllyPressEntry — FUN_00418db0(sender_power) ───────────────────
    # C: final call; marks sender's per-power press-entry as pending so that
    #    RESPOND / SendAllyPressByPower can schedule the DM reply.
    _prepare_ally_press_entry(state, sender_power)


# ── RESPOND ───────────────────────────────────────────────────────────────────

def _respond_walk_pos_analysis(
    state: "InnerGameState",
    sublist3: list,
    sender_power: int,
    response_type: int,
    own_power: int,
) -> None:
    """
    LAB_00421ebc — walk g_PosAnalysisList for proposals matching *sublist3*
    and register *own_power* in g_DeviationTree for each match.

    C flow (decompiled.txt lines 261–316):
      Iterate g_PosAnalysisList (DAT_00bb65c8/cc sentinel loop):
        FUN_00465d90(node+0x10, local_3c) — token-seq overlap check.
        If overlap:
          iStack_68 = node[0x34]  (power-count field)
          GameBoard_GetPowerRec(node+0x30, apuStack_8c, &uStack_c4)
          if puVar13[1] != iStack_68                  ← power-count mismatch
             AND (YES != param_2 OR g_PowerActiveTurn[sender] == 1):
               StdMap_FindOrInsert(node+0x48, &send_time, &uStack_c4)
        FUN_0040f860(&iter)  ← advance list iterator

    GameBoard_GetPowerRec (power-count mismatch check) is absorbed — the check
    fires conservatively whenever the token sets overlap.
    StdMap_FindOrInsert → g_DeviationTree[(token_key, own_power)] insert.
    FUN_00465d90        → frozenset intersection (already used in receive_proposal).
    FUN_0047a948        → AssertFail (absorbed).
    FUN_0040f860        → list iterator advance (absorbed as Python for-loop).
    """
    _YES = 0x481c
    g_active = getattr(state, 'g_PowerActiveTurn', None)
    sender_active = bool(g_active is not None and g_active[sender_power])

    sublist3_set = frozenset(sublist3)
    if not sublist3_set:
        return

    for entry in state.g_PosAnalysisList:
        entry_set = entry.get('token_set', frozenset())
        if not (entry_set & sublist3_set):
            continue
        # C: (puVar13[1] != iStack_68) — power-count mismatch; absorbed as True.
        # C: (YES != param_2 || g_PowerActiveTurn[sender] == 1)
        if response_type != _YES or sender_active:
            key = (frozenset(entry['tokens']), own_power)
            state.g_DeviationTree[key] = state.g_DeviationTree.get(key, 0)
            if 'deviation_powers' not in entry:
                entry['deviation_powers'] = set()
            entry['deviation_powers'].add(own_power)


def respond(
    state: "InnerGameState",
    press_list: dict,
    response_type: int,
    elapsed_lo: int = 0,
    elapsed_hi: int = 0,
    send_fn=None,
) -> None:
    """
    Port of RESPOND (named; called from BuildAndSendSUB after RECEIVE_PROPOSAL).

    Generates Albert's reply to an incoming ally press and queues it for dispatch.

    C signature:
      void __thiscall RESPOND(void *this, void *param_1, short param_2,
                               uint param_3, int param_4)

    Mapping:
      this      → state
      param_1   → press_list  — incoming press as a dict with three sublists:
                    'sublist1': [sender_power_token]   e.g. [0x4103] for GER
                    'sublist2': [power_tokens …]        powers named in proposal
                    'sublist3': [order_tokens …]        XDO/PRP content
      param_2   → response_type  YES=0x481c, REJ=0x4814, HUH=0x4806
      param_3   → elapsed_lo     low-word of current timestamp (uint32)
      param_4   → elapsed_hi     high-word of current timestamp (int32)

    Deception path (REJ + single power + enemy + trust gate):
      If g_EnemyFlag[sender]==1 AND sender's trust toward own is positive AND
      relation >= 0 AND random gate fails to trigger avoidance → respond YES
      (deceitfully accept).  Logs "We are DECEITFULLY responding to: (%s)".
      Sets g_PowerActiveTurn[sender] = 1.

    Normal path:
      Echoes response_type unchanged.
      Logs "Our response to a message was: %s".

    Both paths: enqueue SND entry into g_MasterOrderList, update
    g_AllianceMsgTree, then walk g_PosAnalysisList via
    _respond_walk_pos_analysis.

    HUH path:
      FUN_0040d4d0 (absorbed) + _send_ally_press_by_power(sender) → schedule
      THN response.  Skips queueing step; goes straight to proposal-list walk.

    Timing (non-tournament mode):
      target = elapsed_since_session_start + rand(0–7) + 5 s
      If target < best_ally_turn_score  → push to best_score + 2 s
      If g_MoveTimeLimitSec > 0        → cap at limit − 20 s
    Timing (tournament mode / g_PressInstant != 0):
      target = elapsed_since_session_start  (send immediately)

    Callees absorbed inline:
      FUN_00465870  list init          → []
      FUN_0047020b  own-context ptr    → state.albert_power_idx
      GetSubList    sublist extraction → press_list['sublistN']
      AppendList / FreeList            → Python list ops
      FUN_004658f0  first token        → list[0]
      FUN_00465930  TokenSeq_Count     → len()
      FUN_00465f30  wrap token→list    → [token]
      FUN_00466480  filter by type     → absorbed in power-loop
      FUN_00466f80  prefix+content     → [type_token] + sublist3
      FUN_00466e10  add power token    → list.append
      FUN_00466c40  concat token lists → list + list
      FUN_00465f60  copy token list    → list()
      FUN_00419c30  enqueue press      → g_MasterOrderList.append
      FUN_0046b050  serialize tokens   → str()
      SEND_LOG                         → logging.debug
      BuildAllianceMsg                 → g_AllianceMsgTree.add
      FUN_0040d4d0  HUH forward        → absorbed (no-op)
      ATL::CSimpleStringT::CloneData   → absorbed
      LOCK / UNLOCK                    → absorbed
    """
    import logging as _logging
    import random as _random

    _log = _logging.getLogger(__name__)

    # DAIDE token constants (from daide_client/tokens.h)
    _YES = 0x481c
    _REJ = 0x4814
    _HUH = 0x4806

    own_power: int = getattr(state, 'albert_power_idx', 0)
    # DAT_00baed32 — tournament mode (g_PressInstant in Python)
    tournament_mode: int = int(getattr(state, 'g_PressInstant', 0))

    # ── Extract sublists ─────────────────────────────────────────────────────
    # C: GetSubList(param_1, buf, 1/2/3)
    sublist1: list = press_list.get('sublist1', [])   # sender power token(s)
    sublist2: list = press_list.get('sublist2', [])   # powers in proposal
    sublist3: list = press_list.get('sublist3', [])   # order content

    # local_c8[0] = FUN_004658f0(local_1c, &uStack_8e) → first token of sublist1
    # (byte)local_c8[0] extracts the low byte = power index (0-6)
    sender_token: int = sublist1[0] if sublist1 else 0
    sender_power: int = sender_token & 0xff

    # uStack_c4 = *(byte *)(*(int *)(this+8) + 0x2424) — own power index
    # (already extracted above as own_power)

    # ── Initial best ally turn-score lookup ──────────────────────────────────
    # C: iVar16 = -1; puStack_bc = 0xffffffff
    #    if (DAT_00ba27b4[power*8] >= 0): iVar16 = ...; puStack_bc = ...
    g_turn_score = getattr(state, 'g_TurnScore', None)
    best_score_hi: int = -1
    best_score_lo: int = 0xffffffff

    if g_turn_score is not None and sender_power < len(g_turn_score):
        val = int(g_turn_score[sender_power])
        hi_val = val >> 32
        lo_val = val & 0xffffffff
        if hi_val >= 0:
            best_score_hi = hi_val
            best_score_lo = lo_val

    # ── Power-list loop (local_4c = sublist2) — update best turn score ───────
    # C: uStack_84 = FUN_00465930(local_4c)  (count of entries)
    #    for each entry != own_power: FUN_00466480 filter + score comparison
    power_count: int = len(sublist2)
    for pw_token in sublist2:
        pw_idx = pw_token & 0xff
        if pw_idx == own_power:
            continue
        if g_turn_score is not None and pw_idx < len(g_turn_score):
            val = int(g_turn_score[pw_idx])
            hi_val = val >> 32
            lo_val = val & 0xffffffff
            if hi_val >= 0 and (
                hi_val > best_score_hi
                or (hi_val == best_score_hi and lo_val > best_score_lo)
            ):
                best_score_hi = hi_val
                best_score_lo = lo_val

    # ── Compute target send time ──────────────────────────────────────────────
    elapsed: float = _time.time() - float(getattr(state, 'g_turn_start_time', 0.0))

    if not tournament_mode:
        # C: uVar17 = (rand() / 0x17) & 0x80000007  → 0-7 (mod-8 random)
        rand_val = _random.randint(0, 0x7fff)
        rand_offset = (rand_val // 23) % 8          # 0-7 units
        target = elapsed + rand_offset + 5.0

        # C: if (pvVar8 <= iVar16 && ...): puVar20 = puStack_bc + 2
        # Push target forward past best ally's score + 2 s if needed
        if best_score_hi >= 0:
            best_f = float(best_score_hi) * float(2**32) + float(best_score_lo)
            if target <= best_f:
                target = best_f + 2.0

        # C: if (0 < DAT_00624ef4): cap at limit - 0x14
        move_limit = int(getattr(state, 'g_MoveTimeLimitSec', 0))
        if move_limit > 0:
            cap = float(move_limit - 20)
            if target > cap:
                target = cap
    else:
        # Tournament mode: send at current elapsed (no random delay)
        target = elapsed

    # ── HUH path ─────────────────────────────────────────────────────────────
    # C: if (HUH == param_2) { FUN_0040d4d0(...); SendAllyPressByPower(sender); goto end }
    if response_type == _HUH:
        # FUN_0040d4d0(local_6c, param_1) — unknown HUH forward handler; absorbed
        _send_ally_press_by_power(state, sender_power)
        _respond_walk_pos_analysis(state, sublist3, sender_power, response_type, own_power)
        return

    # ── REJ + single ally power → potential deceit YES ───────────────────────
    # C: if ((REJ == param_2) && (uStack_84 == 1)) { ... } else { LAB_00421d01: ... }
    if response_type == _REJ and power_count == 1:
        uVar17 = sender_power

        # Gate 1: sender must be designated enemy
        # C: (&DAT_004cf568)[uVar17*2] == 1  AND  (&DAT_004cf56c)[uVar17*2] == 0
        # Python: g_EnemyFlag[sender] == 1 (int32; hi-word of int64 is always 0)
        g_enemy = getattr(state, 'g_EnemyFlag', None)
        enemy_flag = int(g_enemy[uVar17]) if g_enemy is not None else 0

        if enemy_flag == 1:
            # Gate 2: trust and relation check
            # C: iVar18 = uVar17*21 + own_power  (sender→own direction in int64 array)
            trust_hi = int(state.g_AllyTrustScore_Hi[uVar17, own_power])
            trust_lo = int(state.g_AllyTrustScore[uVar17, own_power])
            # g_RelationScore[own_power, uVar17]  (DAT_00634e90[own*21+sender])
            relation = int(state.g_RelationScore[own_power, uVar17])

            # Condition to SKIP deceit (goto normal path):
            #   (trust_hi < 0 OR (trust_hi < 1 AND trust_lo == 0) OR relation < 0)
            #   AND random passes
            low_trust = (
                trust_hi < 0
                or (trust_hi < 1 and trust_lo == 0)
                or relation < 0
            )

            aggressiveness = int(getattr(state, 'g_DMZAggressiveness', 0))
            press_mode = int(getattr(state, 'g_PressFlag', 0)) == 1

            # C: (iVar18 = rand(), (iVar18 / 0x17) % 0x14 + aggressiveness < 0x51)
            r1 = _random.randint(0, 0x7fff)
            rand_check1 = (r1 // 23) % 20 + aggressiveness < 81

            if press_mode:
                # C: DAT_00baed68 == '\x01': RandUpTo(n)(0x14) + aggressiveness < 0x47
                r2 = _random.randint(0, 20)
                rand_check2 = r2 + aggressiveness < 71
                random_passes = rand_check1 and rand_check2
            else:
                random_passes = rand_check1

            skip_deceit = low_trust and random_passes

            if not skip_deceit:
                # ── Deceit path: respond YES instead of REJ ───────────────────
                # C: FUN_00466f80(&YES, &local_6c, local_3c) → [YES] + sublist3
                response_tokens = [_YES] + list(sublist3)

                _log.debug("We are DECEITFULLY responding to: (%s)", response_tokens)

                # C: (&DAT_00633768)[(byte)local_c8[0]] = 1
                g_active = getattr(state, 'g_PowerActiveTurn', None)
                if g_active is not None:
                    g_active[sender_power] = 1

                # C: FUN_00419c30(&DAT_00bb65bc, apuStack_7c, (uint*)&puStack_bc)
                state.g_MasterOrderList.append({
                    'scheduled_time': target,
                    'press_type':     'SND',
                    'data':           response_tokens,
                    'target_power':   sender_power,
                })

                # C: BuildAllianceMsg(&DAT_00bbf638, apuStack_7c, (int*)&puStack_bc)
                build_alliance_msg(state, sender_power)

                _respond_walk_pos_analysis(
                    state, sublist3, sender_power, response_type, own_power
                )
                return

    # ── Normal path (LAB_00421d01) ────────────────────────────────────────────
    # C: FUN_00466f80(&param_2, &local_6c, local_3c) → [response_type] + sublist3
    response_tokens = [response_type] + list(sublist3)

    _log.debug("Our response to a message was: %s", response_tokens)

    # C: FUN_00419c30(&DAT_00bb65bc, apuStack_7c, (uint*)&puStack_ac)
    state.g_MasterOrderList.append({
        'scheduled_time': target,
        'press_type':     'SND',
        'data':           response_tokens,
        'target_power':   sender_power,
    })

    # C: BuildAllianceMsg(&DAT_00bbf638, apuStack_7c, (int*)&puStack_bc)
    build_alliance_msg(state, sender_power)

    _respond_walk_pos_analysis(state, sublist3, sender_power, response_type, own_power)


# ── AllianceTree insert (FUN_00414a10 / FUN_00413fd0) ────────────────────────

def alliance_tree_find_or_insert(state: "InnerGameState", key: int) -> tuple:
    """AllianceTree_FindOrInsert — MSVC ``std::set<int>`` BST insert + RB fixup.

    addr: ``0x00414a10``
    C signature: ``void __thiscall FUN_00414a10(void *this, void **param_1,
                    char param_2, int **param_3, undefined4 *param_4)``

    This is the MSVC ``std::set<int>::insert`` fast-path called by
    ``BuildAllianceMsg`` (``FUN_00413fd0``) after the BST descent has located
    the insertion slot.  The C implementation:

      1. Rejects inserts when ``*(uint*)(this+8) > 0x1ffffffd`` (size limit) —
         throws ``std::length_error("map/set<T> too long")``.
      2. Calls ``FUN_00411c40`` (``operator_new(0x18)``-based node ctor) to
         allocate a 24-byte RB-tree node and initialise its fields::

             node[+0x00] = param_1            # _Left  (left child ptr)
             node[+0x04] = param_2            # _Parent (parent ptr)
             node[+0x08] = param_3            # _Right  (right child ptr)
             node[+0x0C] = *param_4           # int key (e.g. elapsed_s+10000)
             node[+0x10] = CSimpleStringT     # cloned ATL CString ptr
                             .CloneData(param_4[1] - 0x10) + 0x10
             byte(node+0x14) = param_5        # _Color (0=RED, nonzero=BLACK)
             byte(node+0x15) = 0              # _Isnil = 0 (real node)
      3. Increments ``*(this+8)`` (``_Mysize``).
      4. Links the new node into the min/max bookkeeping pointers held in
         ``*(this+4)`` (``_Myhead``).
      5. RB-tree colour fixup while ``parent.color == red``:
           - Uncle is red   → recolour uncle + parent black, grandparent red,
                              walk up.
           - Uncle is black + new node is inner child → rotate to make it outer
                              (``FUN_0040f170`` left-rotate or ``FUN_0040e050``
                              right-rotate on parent), then fall through.
           - Uncle is black + new node is outer child → recolour parent black,
                              grandparent red, rotate grandparent the other way.
      6. Forces root black: ``*(this+4)->_Parent.color = black``.
      7. Writes ``param_1[0] = this`` (container back-pointer) and
         ``param_1[1] = new_node`` (node pointer).

    In Python ``g_AllianceMsgTree`` (``DAT_00bbf638``) is a plain ``set``; all
    pointer-wiring and RB rebalancing collapse to a single ``set.add``.  The
    return value mirrors the C ``param_1`` pair:

      (container_set, key, was_inserted: bool)

    Callees (C):
      FUN_00411c40 — 24-byte RB-tree node allocator (left/parent/right +
                     int key + ATL CString clone + color + isnil)
      FUN_0040f170 — RB-tree left-rotation (insert fixup)
      FUN_0040e050 — RB-tree right-rotation (insert fixup)
      FUN_00402650 — ``std::length_error`` constructor (exception path only)
      FUN_00402a30 — MSVC exception rethrow helper (exception path only)
    """
    was_inserted = key not in state.g_AllianceMsgTree
    state.g_AllianceMsgTree.add(key)
    return state.g_AllianceMsgTree, key, was_inserted


def build_alliance_msg(state: "InnerGameState", key: int) -> tuple:
    """BuildAllianceMsg — insert a power key into the alliance BST.

    addr: ``0x00413fd0``
    C signature: ``void __thiscall BuildAllianceMsg(void *this,
                    undefined4 *param_1, int *param_2)``

    Traverses the ``std::set<int>`` rooted at ``this`` (``DAT_00bbf638``) to
    find the insertion slot for ``*param_2`` (power index), then delegates the
    actual insert + RB fixup to ``AllianceTree_FindOrInsert`` (``FUN_00414a10``).
    Writes the resulting ``(container, node)`` pair plus a proposal-active flag
    into the caller's ``param_1`` output buffer::

        param_1[0] = container_ptr   (this)
        param_1[1] = node_ptr        (new or existing node)
        param_1[2] = 1               (proposal-active flag, set by caller)

    BST traversal uses ``node+0x0`` (left) / ``node+0x8`` (right) child pointers
    and compares ``*param_2`` against ``node+0xc`` (key).  Nil sentinel check:
    ``*(char*)(node + 0x15) == '\\0'``.

    Returns the same ``(container, key, flag=1)`` triple that the C caller reads
    from its stack buffer.
    """
    container, node, _ = alliance_tree_find_or_insert(state, key)
    return container, node, 1   # param_1[2] = 1 (proposal-active flag)


# ── STL tree copy (FUN_00401d70) ──────────────────────────────────────────────

def _stl_tree_copy(dest: list, source: list) -> list:
    """MSVC ``std::_Tree::_Copy`` — recursive BST deep-copy.

    addr: ``0x00401d70``
    C signature: ``undefined4 * __thiscall FUN_00401d70(void *this,
                     undefined4 *param_1, undefined4 param_2)``

    Recursively copies the BST rooted at *param_1* into the destination tree
    (*this*), allocating each new node via ``FUN_00401b40`` (_Buynode), then
    wiring left/right children from the recursive results.

    Node layout for this tree type (compact, 18 bytes minimum):
      +0x00  ``_Left``   — left-child pointer  (param_1[0])
      +0x04  ``_Parent`` — parent pointer      (param_1[1])
      +0x08  ``_Right``  — right-child pointer (param_1[2])
      +0x0C  ``_Value``  — key/value data       (param_1+3; passed to _Buynode)
      +0x10  ``_Color``  — RB-tree color byte
      +0x11  ``_Isnil``  — non-zero = sentinel/nil node
                           (checked at +0x11; distinct from g_OrderList which
                           uses +0x21; this is a smaller per-proposal-orders
                           tree type)

    Control flow:
      if param_1._Isnil == 0  (real node):
          puVar1  = _Buynode(head, parent=param_2, left=head,
                             val=param_1.value, color=param_1.color)
          if sentinel._Isnil != 0:   # always true for the sentinel
              local_18 = puVar1      # track begin / return root copy
          puVar1.left  = _Copy(this, param_1.left,  puVar1)
          puVar1.right = _Copy(this, param_1.right, puVar1)
          return puVar1
      else:                          # nil sentinel node
          return this->_Myhead       # return destination sentinel unchanged

    In Python the tree is a sorted ``list[dict]``; all pointer/coloring
    bookkeeping disappears.  The function reduces to a deep-copy of the
    source list into (and replacing) the destination list.

    Callees (C):
      FUN_00401b40 — ``std::_Tree::_Buynode``: allocates + initialises one
                     node with (head, parent, left=head, value, color);
                     see unchecked.md
    """
    import copy
    dest.clear()
    dest.extend(copy.deepcopy(source))
    return dest


# ── STL tree erase (FUN_00402b70) ─────────────────────────────────────────────

def _stl_tree_erase_node(tree: list, idx: int) -> int:
    """MSVC ``std::_Tree::erase(iterator)`` — erase one node from the sorted list.

    addr: ``0x00402b70``
    C signature: ``void __thiscall FUN_00402b70(void *this, int *param_1,
                    int param_2, int **param_3)``

    Operates on the same per-proposal-orders tree type as ``_stl_tree_copy``
    (compact node layout: ``_Color`` at ``+0x10``, ``_Isnil`` at ``+0x11``).

    C algorithm:
      1. Validate *param_3* (the node to erase) is not the nil sentinel
         (``*(char*)(param_3 + 0x11) != 0`` → throws
         ``std::out_of_range("invalid map/set<T> iterator")`` via
         ``FUN_00402650`` + ``FUN_00402a30``).
      2. ``TreeIterator_Advance(&param_2)`` — advance *param_2* to the
         in-order successor of *param_3*.
      3. Determine the replacement / splice node:
         - left child non-nil  → replacement = left child
         - else                → replacement = right child
         (The two-child splice branch guarded by ``param_3 != _Memory`` is dead
         code: ``_Memory = param_3`` at entry, so the condition is always
         false; Ghidra emits the branch but it is unreachable.)
      4. Update all parent/child back-pointers bypassing the erased node;
         update header's leftmost (``this+4``→``*header``) and rightmost
         (``this+4``→``header[2]``) via ``FUN_004010a0`` / ``FUN_00401080``
         when the erased node was the current begin or end.
      5. RB-tree delete fixup (``LAB_00402ce5``): iterate up the tree
         correcting colours via left-rotations (``FUN_004016a0``) and
         right-rotations (``FUN_004010c0``).
      6. ``_free(_Memory)`` + ``this->_Mysize -= 1``.
      7. Write successor iterator into ``*param_1``.

    Node layout (same tree type as ``_stl_tree_copy``):
      +0x00  ``_Left``   — left child
      +0x04  ``_Parent`` — parent
      +0x08  ``_Right``  — right child
      +0x0C  ``_Value``  — 4-byte key/value
      +0x10  ``_Color``  — RB colour byte (0 = red, 1 = black)
      +0x11  ``_Isnil``  — non-zero = sentinel/nil node

    Python representation: the tree is a sorted ``list[dict]``; all
    pointer/colour bookkeeping disappears.  The function reduces to removing
    the entry at *idx* and returning the new index of the successor (which,
    after deletion, is automatically ``idx``).

    Raises ``IndexError`` if *idx* is out of range (mirrors the C
    ``std::out_of_range`` throw for the end-sentinel / past-the-end check).

    Callees (C):
      FUN_00402650         — ``std::string`` ctor from ``(char*, size_t)``
                             builds the "invalid map/set<T> iterator" message
      FUN_00402a30         — ``std::out_of_range`` constructor
      TreeIterator_Advance — in-order successor step (Ghidra-named; analogous
                             to ``std_Tree_IteratorIncrement`` at 0x0040f6f0
                             but for this compact tree type; address unknown)
      FUN_004010a0         — leftmost-descendant finder; returns new begin
                             after the old leftmost node is erased
      FUN_00401080         — rightmost-descendant finder; returns new end
                             (rightmost) after the old rightmost node is erased
      FUN_004016a0         — RB-tree left-rotation used in delete fixup
      FUN_004010c0         — RB-tree right-rotation used in delete fixup
    """
    if idx < 0 or idx >= len(tree):
        raise IndexError("invalid map/set<T> iterator")
    tree.pop(idx)
    # After deletion 'idx' naturally addresses the former successor (or
    # len(tree) when the erased entry was the last), matching the C behaviour
    # where *param_1 is set to the advanced iterator after the node is freed.
    return idx


# ── HostilityRecord ───────────────────────────────────────────────────────────

def build_hostility_record(src: dict) -> dict:
    """Copy constructor for HostilityRecord.

    C: ``undefined * __thiscall BuildHostilityRecord(void *this, undefined *param_1)``

    Copies every field from *src* (param_1) into a new record (this) using the
    appropriate per-field copy operation, then returns the destination.  In
    Python, all C field copies collapse to a single ``copy.deepcopy``.

    Struct layout (C offset → Python key):
      +0x00  1B   'flag_0'        — leading flag/type byte
      +0x04  4B   'int_4'         — dword
      +0x08  4B   'int_8'         — dword
      +0x0c  12B  'obj_0c'        — 12-byte token/proposal object
                                    (FUN_00405090 copy constructor)
      +0x18  12B  'obj_18'        — 12-byte object
                                    (FUN_0041c3c0 copy constructor)
      +0x24  12B  'obj_24'        — 12-byte object
                                    (FUN_0041c3c0 copy constructor)
      +0x30  84B  'trust_row'     — 21×int32 raw copy (one g_AllyTrustScore row)
      +0x84  4B   'int_84'        — dword
      +0x88  16B  'token_list_88' — token list (FUN_00465f60 copy)
      +0x98  1B   'flag_98'       — flag byte
      +0xa0  4B   'int_a0'        — dword
      +0xa4  4B   'int_a4'        — dword
      +0xa8  16B  'token_list_a8' — token list (FUN_00465f60 copy)
      +0xb8  2B   'word_b8'       — word
      +0xbc  16B  'token_list_bc' — token list (FUN_00465f60 copy)

    Callees (C):
      FUN_00405090  — 12-byte object copy (already in unchecked)
      FUN_0041c3c0  — 12-byte STL set copy constructor (see below)
      FUN_00465f60  — token-list copy (already in unchecked)
    """
    import copy
    return copy.deepcopy(src)


def _ordered_token_seq_insert(container: list, key_seq) -> tuple:
    """Port of FUN_00419300 — MSVC ``std::set<TokenSeq>::insert(value)``.

    addr: ``0x00419300``
    C signature: ``void __thiscall FUN_00419300(void *this,
                    void **param_1, void **param_2)``

    The C body is a full MSVC RB-tree insert for a ``std::set`` whose element
    type is a token-sequence list.  It descends the tree from root using
    ``FUN_00465cf0`` (token-sequence less-than comparator, ``+0x1d`` sentinel
    flag) to locate the insertion point, then detects duplicates in two paths:

      * Last BST step went LEFT (``local_c != 0``, ``param_2 < parent.key``):
        if parent is the leftmost node → fast-insert (no predecessor possible);
        otherwise call ``FUN_00401790`` to step back to the in-order
        predecessor and re-check ``FUN_00465cf0(predecessor.key, param_2)``.
        If predecessor >= param_2 the keys are equal → no insert.
      * Last BST step went RIGHT (``local_c == 0``, ``param_2 >= parent.key``):
        check ``FUN_00465cf0(parent.key, param_2)``; if parent >= param_2 the
        keys are equal → no insert.

    On successful insert, ``FUN_004134d0`` allocates and splices a new RB-tree
    node.  The result is written through *param_1*:

      param_1[0]  — iterator node pointer (existing or newly inserted)
      param_1[1]  — iterator ``_Myhead`` (header/sentinel pointer)
      param_1[2]  — bool: 1 = new node inserted, 0 = key already existed

    The 12-byte ``this`` layout::

        +0  allocator/compare  (zeroed)
        +4  _Myhead            (sentinel node ptr; [0]=leftmost, [1]=root, [2]=rightmost)
        +8  _Mysize            (element count)

    Sentinel node: ``node + 0x1d`` = ``_Isnil`` flag (0 = real node, 1 = nil).

    Python mapping:
      *container*  — sorted ``list[tuple]`` representing the BST in-order
                     contents; Python lexicographic tuple comparison matches
                     ``FUN_00465cf0`` semantics exactly.
      *key_seq*    — iterable token sequence; normalised to ``tuple``.
      Returns ``(key_tuple, inserted: bool)``.

    Callees absorbed:
      FUN_00465cf0 — TokenSeq less-than comparator (tuple ``<``)
      FUN_004134d0 — RB-tree node allocate-and-insert (``list.insert`` via bisect)
      FUN_00401790 — in-order predecessor step (not required in Python)
    """
    import bisect
    key = tuple(key_seq)
    idx = bisect.bisect_left(container, key)
    if idx < len(container) and container[idx] == key:
        return (container[idx], False)
    container.insert(idx, key)
    return (key, True)


def _copy_stl_ordered_set(src):
    """Copy constructor for a 12-byte MSVC ``std::set<int>`` (FUN_0041c3c0).

    C signature: ``void * __thiscall FUN_0041c3c0(void *this, int param_1)``

    Called from BuildHostilityRecord for the 'obj_18' and 'obj_24' fields::

        FUN_0041c3c0((void *)(this + 0x18), (int)(param_1 + 0x18))
        FUN_0041c3c0((void *)(this + 0x24), (int)(param_1 + 0x24))

    The C++ body has two phases:

    **Phase 1 — default-construct an empty set (``this``)**:

    * ``FUN_0040fd90()`` — ``operator_new(0x20)``; zeros offsets 0/4/8
      (``_Left``/``_Parent``/``_Right``); sets ``+0x1c = 1`` (``_Color =
      BLACK``); explicitly sets ``+0x1d = 0`` (``_Isnil`` starts as 0 —
      NOT yet a sentinel; the caller marks it).  Returns the raw pointer
      in EAX (Ghidra shows ``void`` return but value survives in EAX).
      Same structural role as ``FUN_00401e30`` inside ``StdSet_Init``
      (``FUN_00405660``).
    * Stores the sentinel at ``this+4`` (``_Myhead``).
    * Marks the sentinel: ``sentinel+0x1d = 1`` (``_Isnil`` flag) and sets
      ``_Left = _Parent = _Right = sentinel`` (circular self-links for an
      empty RB-tree head).  These two steps are done by the caller
      (``FUN_0041c3c0``), not by ``FUN_0040fd90``.
    * Sets ``this+8 = 0`` (``_Mysize``).

    **Phase 2 — copy-assign from source**:

    * ``FUN_00411a80(this, param_1)`` — the MSVC ``_Tree::_Copy`` helper;
      walks the source tree in-order and inserts each element into ``this``.

    The 12-byte container layout is::

        this+0   4B  allocator/compare (unused — zero-initialised by caller)
        this+4   4B  _Myhead  (sentinel node ptr)
        this+8   4B  _Mysize  (element count)

    Python absorption: both phases collapse to ``copy.deepcopy(src)`` because
    ``src`` is already the correct Python container (``set`` of ints).

    Callees (C) — absorbed:
      FUN_0040fd90  — allocate BST sentinel node (absorbed as Python alloc)
      FUN_00411a80  — MSVC ``_Tree::_Copy``: outer copy driver; calls
                      FUN_00410db0 on the source root (absorbed as deepcopy)
      FUN_00410db0  — MSVC ``_Tree::_Copy_nodes``: recursive pre-order node
                      copy; for each non-nil src node calls FUN_0040fdd0 to
                      allocate a dst node (copying key at src+0x0c and color
                      byte at src+0x1c), then recurses into left (*src) and
                      right (src[2]) with parent=new_node; returns new_node
                      or dst sentinel (absorbed as deepcopy)
      FUN_0040fdd0  — MSVC ``_Tree::_Buynode``: allocates a raw tree node,
                      sets _Left=_Right=sentinel, _Parent=arg2, copies key
                      from arg4, sets _Color=arg5 (absorbed as Python alloc)
    """
    import copy
    return copy.deepcopy(src)
