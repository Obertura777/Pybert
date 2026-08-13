"""Scheduled press dispatch and ThennAction execution.

DAIDE scheduled-press queue: enqueue, gate, and execute THN/SND entries stored
in state.g_master_order_list.  Extracted from communications.py during
the 2026-04 structural refactor; behaviour preserved verbatim.

Contents:

- dispatch_scheduled_press   — main dispatch loop (port of FUN_004424e0)
- _fun_004117d0              — pending-proposal participant scanner
- _press_gate_check          — thin alias used by ScheduledPressDispatch
- _press_list_count          — per-power press-history size
- _find_press_token          — per-power press-history token lookup
- _press_token_found         — port of FUN_00401050 (iterator truthiness)
- _renegotiate_pce           — FUN_00438b30 PRP(PCE) renegotiation path
- _execute_aly_vss           — FUN_004325a0 PRP(ALY/VSS) build + send
- _execute_xdo               — FUN_00433510 XDO proposal scan / send
- _execute_then_action       — FUN_00439c30 ThennAction dispatcher

Cross-slice callees (_prepare_ally_press_entry and propose_dmz) live in
.senders, which in turn imports from this module; the two call sites
below therefore use a deferred "from .senders import …" to break the cycle.
"""

import time as _time

from ..state import InnerGameState
from ..dispatch.validator import validate_and_dispatch_order
from .tokens import _TOK_ALY, _TOK_DMZ, _TOK_PCE, _TOK_VSS, _TOK_XDO
from .evaluators._common import _POWER_NAMES as _PN


def dispatch_scheduled_press(state: InnerGameState, send_fn=None) -> None:
    """
    Port of FUN_004424e0 = ScheduledPressDispatch.

    Iterates g_master_order_list (DAT_00bb65bc/c0) and sends any enqueued press
    messages whose scheduled delivery time has elapsed since g_turn_start_time
    (DAT_00ba2880/84).

    For each due entry:
      - press_type == 'SND' → call send_fn(data), accumulate target_power into
        a running power-list, then call SendAllyPressByPower for every power in
        the cumulative list (C: local_58 accumulator + inner count loop).
      - press_type == 'THN' → extract first data element (power index) and call
        ExecuteThennAction (FUN_00439c30).

    After dispatching, removes the entry from the list.

    The C binary restarts its linked-list scan after removing each due entry.
    Dispatch callbacks can append THN entries, so the Python loop likewise
    mutates the live list instead of rebuilding it from a stale snapshot.

    Research.md §5271.

    Parameters
    ----------
    state   : InnerGameState
    send_fn : optional callable(data) — wire to SendDM; defaults to a no-op log
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (
        lambda data: _log.debug("DispatchScheduledPress: SND %r", data)
    )

    # C: __time64(0) - CONCAT44(DAT_00ba2884, DAT_00ba2880)
    # DAT_00ba2880 is g_turn_start_time, set at the top of
    # GenerateAndSubmitOrders (bot.py Step 1).
    turn_start = float(getattr(state, 'g_turn_start_time', 0.0))
    elapsed = _time.time() - turn_start

    # C: local_58 — accumulates target-power bytes across all dispatched SND
    # entries so that SendAllyPressByPower is called for every recipient seen
    # so far (not just the current entry's recipient).
    cumulative_snd_powers: list = []

    master = getattr(state, 'g_master_order_list', [])
    while True:
        due_index = next(
            (i for i, candidate in enumerate(master)
             if elapsed >= float(candidate.get('scheduled_time', 0.0))),
            None,
        )
        if due_index is None:
            break

        # C removes the node after executing it.  Pop first so callbacks see
        # the live queue without this entry and any appended work is retained.
        entry = master.pop(due_index)

        press_type = entry.get('press_type', '')
        data       = entry.get('data', [])

        if press_type == 'SND':
            # C: SendDM(param_1, node+6) — send the press message.
            _send(data)

            # C: GetSubList(node+6, local_38, 2) → all power bytes from position
            # 2+ in the token sequence (local_2c in RESPOND, local_c8 in deceit).
            # Deceit path stores 'target_power' (single int, sender only).
            # Normal path stores 'target_powers' (list: sender + non-own proposal powers).
            target = entry.get('target_power')
            if target is not None:
                cumulative_snd_powers.append(int(target))
            for _t in entry.get('target_powers', []):
                _ti = int(_t)
                if _ti not in cumulative_snd_powers:
                    cumulative_snd_powers.append(_ti)

            # C: for i in 0..len(local_58): SendAllyPressByPower(local_58[i])
            # Uses the cumulative list (all SND recipients so far).
            from .senders import send_ally_press_by_power as _send_ally_press_by_power
            for pwr in cumulative_snd_powers:
                _send_ally_press_by_power(state, pwr)

        elif press_type == 'THN':
            # C: GetSubList(node+6, local_28, 1) → first data element
            # ExecuteThennAction(param_1, *first_arg)
            if data:
                _execute_then_action(state, int(data[0]), send_fn=_send)
        # entry consumed by the pop above


def _fun_004117d0(state: InnerGameState, param_1: int) -> bool:
    """
    Port of FUN_004117d0 (0x004117d0).

    Scans g_pos_analysis_list for an unresolved proposal. ``param_1 == -1``
    asks whether any proposal is pending; a non-negative value restricts the
    search to proposals whose +0xc participant map contains that power.

    C node layout (undefined4* units; offsets in bytes in parens):
      +8        resolved flag — 0 = active, 1 = done
      +0xc/0xd  participant-power map and head

    EvaluateOrderProposalsAndSendGOF marks a node resolved after every
    participant appears in the +0xf affirmative map. Until then this gate
    prevents another THN action for the same participant and keeps the
    fallback GOF hold-back active.
    """
    for entry in getattr(state, 'g_pos_analysis_list', []):
        # C: if (*(char*)(puVar1+8) != '\0') → node already processed → skip
        if (entry.get('processed', False)
                or entry.get('board_satisfied', False)
                or entry.get('processed_flag', 0) != 0):
            continue

        participants = set(entry.get('participant_powers', set()))
        if participants and (param_1 == -1 or param_1 in participants):
            return True

    return False


def _press_gate_check(state: InnerGameState, power: int) -> bool:
    """
    Port of FUN_004117d0((int)param_1) called from SendAllyPressByPower.

    Returns True when an unresolved proposal includes *power*, causing the
    caller to defer another press action for that power.

    """
    return _fun_004117d0(state, power)


def _press_list_count(state: InnerGameState, power: int) -> int:
    """
    Port of DAT_00bb6e14[power * 3] — _Mysize field of the per-power press std::map.
    Returns the number of allowed press tokens registered for power.
    Confirmed: structure is std::map<ushort> (RB-tree); key = raw DAIDE token ushort.
    See FUN_00418ed0 / FUN_004108a0 decompiles (2026-04-13).
    """
    return len(state.g_press_history.get(power, set()))


def _find_press_token(state: InnerGameState, power: int, token: int) -> object:
    """
    Port of FUN_004108a0(&DAT_00bb6e10 + power * 0xc, local_scratch, &token).
    Searches the per-power allowed-press std::map for raw ushort token value.
    Returns a truthy sentinel if found, None if not (models found_node != _Myhead).

    Confirmed from FUN_004108a0 decompile (2026-04-13):
      - lower_bound RB-tree traversal; key at node+0x0c as ushort
      - arg2 dereferenced as *arg2 (ushort value, not pointer comparison)
      - not-found → param_1[1] = _Myhead sentinel

    Pass integer DAIDE token constants: PCE=_TOK_PCE, ALY=_TOK_ALY, etc.
    """
    return token if token in state.g_press_history.get(power, set()) else None


def _press_token_found(result: object, state: InnerGameState, power: int) -> bool:
    """
    Port of FUN_00401050(pvVar3, ppuVar7).

    pvVar3  = local_8 = iterator returned by FUN_004108a0: {map_obj, found_node}
    ppuVar7 = &local_10 = {base_ptr=map_obj, local_c=snapshot_node_ptr}

    Real logic:
      1. Assert: local_8[0] (map_obj) != 0 AND == base_ptr  (AssertFail otherwise)
      2. return CONCAT31(upper3(found_node), found_node != snapshot_node_ptr)
         low byte = (found_node != snapshot)

    When the snapshot is initialised to myhead (the map sentinel = "not found"),
    (found_node != snapshot) reduces to (found_node != myhead) = "token was found".
    Callee FUN_0047a948 = AssertFail (already documented).

    The assertion guard and CONCAT31 upper bytes are irrelevant to callers, which
    only check (char)result != 0.  `result is not None` correctly models this.
    """
    return result is not None


def _renegotiate_pce(state: InnerGameState, power: int, send_fn=None) -> bool:
    """
    Port of FUN_00438b30(this, param_1).

    Proposes PRP(PCE(own, power)) in Spring when all eligibility gates pass.
    Called from ExecuteThennAction when the PCE press-list count changed since
    the saved snapshot — i.e. a new PCE message arrived mid-dispatch.

    Gate conditions (must all be true to enter):
      1. power != own                                          (not self)
      2. g_turn_order_hist_lo/Hi[power] == 0                   (PCE not sent this turn)
      3. g_ally_trust_score[own, power] == 0 (both words)      (no current own→power trust)
      4. g_press_flag == 1  OR  g_ally_trust_score[power, own] == 0  (press mode or no reverse trust)
      5. g_enemy_flag[power] == 0                             (power not designated enemy)
      6. g_influence_matrix_b[own, power] > 0.0               (positive influence toward power)
      7. g_relation_score[own, power] >= 0                    (not hostile relation)
      8. g_season == 'SPR'                                    (Spring phase only)

    Secondary gate (after PCE found in press history):
      g_influence_matrix_b[own, power] > 17.0  OR
      g_influence_rank_flag[own, power] < 4     OR
      g_deceit_level > 1

    Returns True if PRP(PCE) was dispatched.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (lambda msg: _log.debug("_renegotiate_pce: %s", msg))

    own = getattr(state, 'albert_power_idx', 0)

    # Gate 1: not self
    if power == own:
        return False

    # Gate 2: g_turn_order_hist_lo[power] == 0 && g_turn_order_hist_hi[power] == 0
    #          (DAT_004d53d8[power*2] == 0 && DAT_004d53dc[power*2] == 0)
    if int(state.g_turn_order_hist_lo[power]) != 0 or int(state.g_turn_order_hist_hi[power]) != 0:
        return False

    # Gate 3: g_ally_trust_score[own, power] == 0 (both lo and hi words)
    #          ((&g_ally_trust_score)[iVar1*2] == 0 && (&g_ally_trust_score_hi)[iVar1*2] == 0)
    if int(state.g_ally_trust_score[own, power]) != 0 or int(state.g_ally_trust_score_hi[own, power]) != 0:
        return False

    # Gate 4: press mode OR no reverse trust
    #          (DAT_00baed68 == '\x01' || (g_ally_trust_score[power,own] both == 0))
    press_mode = (getattr(state, 'g_press_flag', 0) == 1)
    if not press_mode:
        if int(state.g_ally_trust_score[power, own]) != 0 or int(state.g_ally_trust_score_hi[power, own]) != 0:
            return False

    # Gate 5: power not designated enemy
    #          (&DAT_004cf568)[power*2] == 0 && (&DAT_004cf56c)[power*2] == 0
    if (int(state.g_enemy_flag[power]) != 0
            or int(getattr(state, 'g_enemy_flag_hi', [0] * 7)[power]) != 0):
        return False

    # Gate 6 & 7: positive influence AND non-negative relation
    #          0.0 < g_influence_matrix_b[iVar1] && -1 < DAT_00634e90[iVar1]
    inf_b = float(state.g_influence_matrix_b[own, power])
    if inf_b <= 0.0:
        return False
    if int(state.g_relation_score[own, power]) < 0:
        return False

    # Gate 8: Spring phase only (SPR == *(short *)(iVar2 + 0x244a))
    if getattr(state, 'g_season', '') != 'SPR':
        return False

    # Inner check: PCE entry must exist in press history for this power
    #   this_00 = FUN_004108a0(press_list_base, apuStack_4c, &PCE)
    #   uVar5   = FUN_00401050(this_00, ppuVar6)  → non-zero if found
    pce_result = _find_press_token(state, power, _TOK_PCE)
    if not _press_token_found(pce_result, state, power):
        return False

    # Secondary gate: strong influence OR top-4 rank OR multi-year game
    #   17.0 < g_influence_matrix_b[iVar1] || DAT_006340c0[iVar1] < 4 || 1 < g_deceit_level
    rank = int(state.g_influence_rank_flag[own, power])
    deceit = int(getattr(state, 'g_deceit_level', 0))
    if not (inf_b > 17.0 or rank < 4 or deceit > 1):
        return False

    # All gates passed — mark PCE as sent this turn and dispatch PRP(PCE(own, power))
    # DAT_004d53d8[power*2] = 1; DAT_004d53dc[power*2] = 0
    state.g_turn_order_hist_lo[power] = 1
    state.g_turn_order_hist_hi[power] = 0

    # PROPOSE(this): send PRP ( PCE ( own power ) )
    # C: local_68[0] = (ushort)param_1 & 0xff | 0x4100  → DAIDE power token for param_1
    #    FUN_00466540(local_64, apuStack_1c, local_68)   → [own_tok, target_tok]
    #    FUN_00466f80(&PCE, &puStack_5c, ppuVar6)        → PCE ( own target )
    #    FUN_00466f80(&PRP, apuStack_4c, ppuVar6)        → PRP ( PCE ( own target ) )
    # Route through propose() for proposal-tree dedup and game-state validation.
    from .senders import propose as _propose
    own_tok  = _PN[own]  if 0 <= own  < len(_PN) else str(own)
    pow_tok  = _PN[power] if 0 <= power < len(_PN) else str(power)
    return _propose(state, f"PRP ( PCE ( {own_tok} {pow_tok} ) )", [power], send_fn=_send)


def _execute_aly_vss(state: InnerGameState, power: int, send_fn=None) -> bool:
    """
    Port of FUN_004325a0(this, param_1).

    Called (from _execute_then_action) when ALY and VSS entries are both present
    in press history for *power* (= param_1 = target power index).

    Logic (faithful to decompile):
      own        = albert_power_idx  (this+8+0x2424)
      mutual_enemy = g_mutual_enemy_table[power]  (DAT_00b9fdd8[param_1])

      Gate 1: mutual_enemy >= 0  (valid)
      Gate 2: g_ally_matrix[power, mutual_enemy] == 0  (no existing alliance)

      bVar3: scan all powers — any p where g_ally_matrix[p, mutual_enemy] == 1 (tentative)

      own_row = own * 21
      Condition A: g_influence_rank_flag[own, power] < 4  AND  g_press_flag == 1
      Condition B: bVar3  AND  g_press_flag == 1
                   AND  g_diplomacy_state_a[mutual_enemy] == 1
                   AND  g_diplomacy_state_b[mutual_enemy] == 0
      Condition C: g_enemy_flag[mutual_enemy] == 1
                   AND  g_influence_rank_flag[own, mutual_enemy] < 4
                   AND  raw[mutual_enemy, own] / (raw[own, mutual_enemy] + 1) < 4.5
                   AND  (raw[mutual_enemy, own] > 5  OR  raw[own, mutual_enemy] > 5)

      If any condition fires:
        Send PRP ( ALY ( own power ) VSS ( mutual_enemy ) ) to power.
        g_ally_matrix[power, mutual_enemy] = -4  (cooling-off / proposal-sent marker)
        return True

    Returns False if no proposal was sent.

    NOTE: g_diplomacy_state_a/B (DAT_004d5480/4) are written by CAL_BOARD block 4;
    they are per-power int64 snapshots (lo/hi split). If not yet on the state object
    the code falls back to 0, making condition B unreachable.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (
        lambda msg: _log.debug("FUN_004325a0 PROPOSE: %s", msg)
    )

    own = getattr(state, 'albert_power_idx', 0)
    num_powers = 7

    # iVar2 = g_mutual_enemy_table[param_1]
    mutual_enemy = int(state.g_mutual_enemy_table[power])

    # Gate 1: mutual enemy must be valid
    if mutual_enemy < 0:
        return False

    # Gate 2: g_ally_matrix[power*21 + mutual_enemy] == 0  (neutral; not already allied)
    if int(state.g_ally_matrix[power, mutual_enemy]) != 0:
        return False

    # bVar3: any power has tentative alliance (== 1) with mutual_enemy
    # C loop: piVar8 starts at &g_ally_matrix[mutual_enemy] then strides +21 per row
    bVar3 = any(int(state.g_ally_matrix[p, mutual_enemy]) == 1 for p in range(num_powers))

    press_on = (int(getattr(state, 'g_press_flag', 0)) == 1)

    # Condition A: g_influence_rank_flag[own, power] < 4  AND  press mode on
    # C: DAT_006340c0[own*21 + param_1] < 4  &&  DAT_00baed68 == 1
    rank_own_target = int(state.g_influence_rank_flag[own, power])
    cond_a = (rank_own_target < 4) and press_on

    # Condition B: bVar3 AND press on AND DiplomacyStateA[mutual_enemy]==1 AND B==0
    # C: bVar3 && DAT_00baed68==1 && DAT_004d5480[iVar2*2]==1 && DAT_004d5484[iVar2*2]==0
    _dipl_a_arr = getattr(state, 'g_diplomacy_state_a', None)
    _dipl_b_arr = getattr(state, 'g_diplomacy_state_b', None)
    dipl_a = int(_dipl_a_arr[mutual_enemy]) if _dipl_a_arr is not None else 0
    dipl_b = int(_dipl_b_arr[mutual_enemy]) if _dipl_b_arr is not None else 0
    cond_b = bVar3 and press_on and (dipl_a == 1) and (dipl_b == 0)

    # Condition C: mutual_enemy is strategic enemy AND in our top-3 influence rank
    #              AND influence ratio < 4.5 AND significant mutual influence
    # C: DAT_004cf568[iVar2*2]==1 && DAT_004cf56c[iVar2*2]==0  (g_enemy_flag[mutual_enemy])
    #    DAT_006340c0[own*21 + mutual_enemy] < 4                (g_influence_rank_flag)
    #    raw[mutual_enemy, own] / (raw[own, mutual_enemy] + 1) < 4.5
    #    raw[mutual_enemy, own] > 5  OR  raw[own, mutual_enemy] > 5
    enemy_flag = int(state.g_enemy_flag[mutual_enemy])
    enemy_flag_hi = int(
        getattr(state, 'g_enemy_flag_hi', [0] * 7)[mutual_enemy]
    )
    rank_own_mutual = int(state.g_influence_rank_flag[own, mutual_enemy])
    raw_mutual_own = float(state.g_influence_matrix_raw[mutual_enemy, own])
    raw_own_mutual = float(state.g_influence_matrix_raw[own, mutual_enemy])
    ratio = raw_mutual_own / (raw_own_mutual + 1.0)
    cond_c = (
        (enemy_flag == 1 and enemy_flag_hi == 0) and
        (rank_own_mutual < 4) and
        (ratio < 4.5) and
        (raw_mutual_own > 5.0 or raw_own_mutual > 5.0)
    )

    if not (cond_a or cond_b or cond_c):
        return False

    # --- Build and send PRP ( ALY ( own power ) VSS ( mutual_enemy ) ) ---
    # C: local_80 = target token, local_7c = own token, local_78 = mutual_enemy token
    #    FUN_00466540(local_7c, local_1c, local_80)  → [own, target] pair
    #    FUN_00466f80(&ALY, ...)                      → ALY (own target)
    #    FUN_00466ed0(&VSS, ..., local_78)            → VSS (mutual_enemy)
    #    FUN_00466330(aly_list, ..., vss_list)        → concatenate
    #    FUN_00466f80(&PRP, ...)                      → PRP (ALY (...) VSS (...))
    #    auStack_a8 = [power]  (recipient list)
    #    auStack_b8 = PRP(...)  (press content)
    #    PROPOSE(this)
    # Route through propose() for proposal-tree dedup and game-state validation.
    from .senders import propose as _propose
    sent = _propose(
        state,
        f"PRP ( ALY ( {_PN[own] if 0 <= own < len(_PN) else own} "
        f"{_PN[power] if 0 <= power < len(_PN) else power} ) "
        f"VSS ( {_PN[mutual_enemy] if 0 <= mutual_enemy < len(_PN) else mutual_enemy} ) )",
        [power],
        send_fn=_send,
    )
    if not sent:
        return False

    # Mark g_ally_matrix[power*21 + mutual_enemy] = 0xfffffffc = -4 (cooling-off)
    # C: (&g_ally_matrix)[(int)(puVar6 + iVar2)] = 0xfffffffc
    state.g_ally_matrix[power, mutual_enemy] = -4

    return True


def _execute_xdo(state: InnerGameState, power: int, send_fn=None) -> None:
    """
    Port of FUN_00433510(this, param_1) — param_1 = sender power index.

    Searches g_broadcast_list for already-sent own proposals (type_flag==1,
    sent==True, history_flag>0) whose board state no longer matches the
    expected order (GameBoard_GetPowerRec check) and which have not yet been
    submitted as an XDO proposal (g_xdo_proposal_list dedup).

    Scores each candidate via score_vector[own] and score_vector[power]
    (C: node[0x12+power] − baseline[power] delta pair).  Accumulates all
    candidates that strictly improve the running best total (score_own + score_sender
    > best_score) with score_own > 0 and score_sender > −800.

    After iteration: sends each accumulated PRP(XDO) via send_fn (PROPOSE macro)
    and registers the token-sequence dedup key in g_xdo_proposal_list
    (FUN_00419300 equivalent) to prevent re-sending the same proposal.

    Unchecked callees: FUN_00410980, FUN_00419300,
                       FUN_004109f0, FUN_0040fa80, FUN_0040dfe0,
                       FUN_0040f470, FUN_00465f60, PROPOSE macro.
    FUN_00422a90 ported as validate_and_dispatch_order (commit=False).
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (
        lambda msg: _log.debug("_execute_xdo: PROPOSE %s", msg)
    )

    own: int = getattr(state, 'albert_power_idx', 0)
    best_score: int = -20000          # local_a4

    # Accumulators (local_4c = dedup keys, local_3c = PRP list).
    accumulated_dedup_keys: list = []
    accumulated_prp: list = []

    # g_xdo_proposal_list — set of token-tuple keys already submitted as XDO
    # proposals.  Mirrors C's FUN_00410980/FUN_00419300 full-key-sequence lookup.
    # DAT_00bb6df4 / DAT_00bb6df8 sentinel.
    xdo_sent: set = getattr(state, 'g_xdo_proposal_list', set())

    for node in getattr(state, 'g_broadcast_list', []):
        # Gate 1: type_flag == 1  (node[7] == 1) — self-generated proposals only
        if node.get('type_flag', 0) != 1:
            continue

        # Gate 2: history_flag > 0  (C: (int)node[0x27] > 0)
        # node[0x27] = AllianceRecord+0x9c = history_flag in the Python model.
        # Earlier port read 'count' (nonexistent field) → gate always failed.
        if node.get('history_flag', 0) <= 0:
            continue

        # Gate 3: sent_flag == 1  (*(char*)(node+6) == '\x01')
        if not node.get('sent', False):
            continue

        # Retrieve the XDO token sequence from order_candidates.
        # C node stores the token list inline; Python mirrors it as
        # order_candidates[0]['tokens'] (set by emit_xdo_proposals_to_broadcast).
        candidates = node.get('order_candidates', [])
        if not candidates:
            continue
        tokens: list = candidates[0].get('tokens', [])
        if not tokens:
            continue

        # GameBoard_GetPowerRec check: skip when board already satisfies order.
        # C: puVar4[1] != local_50 → board order for *power* changed since proposal.
        # When 'order_match' is absent (no board-state snapshot in entry), the
        # check is conservatively skipped so the proposal is always evaluated.
        board_order = getattr(state, 'g_board_orders', {}).get(power)
        expected    = node.get('order_match')
        if board_order is not None and expected is not None and board_order == expected:
            continue

        # FUN_00410980: dedup against g_xdo_proposal_list using full token tuple.
        dedup_key = tuple(tokens)
        if dedup_key in xdo_sent:
            continue

        # Score computation from score_vector (C: node[power+0x12] − baseline[power]).
        # Python uses legitimacy_gate scores stored per-power in score_vector.
        score_vector: list = node.get('score_vector', [0] * 7)
        score_own:    int  = score_vector[own]   if own   < len(score_vector) else 0
        score_sender: int  = score_vector[power] if power < len(score_vector) else 0

        # FUN_00422a90 (commit=False) gate — skip invalid orders.
        order_seq_dict = candidates[0].get('order_seq')
        if order_seq_dict is not None:
            if validate_and_dispatch_order(state, own, order_seq_dict, commit=False) != 0:
                continue

        # Accumulate whenever this beats the running best combined score.
        total: int = score_own + score_sender
        if score_own > 0 and score_sender > -800 and total > best_score:
            best_score = total
            accumulated_dedup_keys.append(dedup_key)
            accumulated_prp.append({
                'tokens':      tokens,
                'score_own':   score_own,
                'score_sender': score_sender,
            })

    if not accumulated_prp:
        return  # bVar1 == false

    # bVar1 == true: send all accumulated PRP(XDO) proposals (PROPOSE macro).
    # C: PROPOSE(local_9c) → build PRP ( XDO ( … ) ) and dispatch.
    #    FUN_00419300 then registers the key in g_xdo_proposal_list.
    # Route through propose() for proposal-tree dedup and game-state validation.
    from .senders import propose as _propose
    sent_keys: list = []
    for prp, dedup_key in zip(accumulated_prp, accumulated_dedup_keys):
        msg = f"PRP ( {' '.join(str(t) for t in prp['tokens'])} )"
        _log.debug(
            "_execute_xdo: PRP(XDO) score_own=%d score_sender=%d",
            prp['score_own'], prp['score_sender'],
        )
        if _propose(state, msg, [power], send_fn=_send):
            sent_keys.append(dedup_key)

    # FUN_00419300: register proposed token-tuple keys in g_xdo_proposal_list.
    for dedup_key in sent_keys:
        xdo_sent.add(dedup_key)
    state.g_xdo_proposal_list = xdo_sent


def _execute_then_action(state: InnerGameState, power: int, send_fn=None) -> None:
    """
    Port of ExecuteThennAction (FUN_00439c30).

    Executes conditional THN press actions dispatched by ScheduledPressDispatch.
    param_1 = power (sender power index); puVar6 = own power (albert_power_idx).

    Control flow (faithful to decompile):
      1. Gate: FUN_004117d0(power) → skip if non-zero.
      2. If history > 9: PCE list check + optional renegotiation (FUN_00438b30).
      3. Bidirectional trust gate (own→sender AND sender→own); override via
         g_press_flag (DAT_00baed68).
      4. If history > 9: ALY+VSS → FUN_004325a0 (sets action_taken).
      5. If history < 20 → return.
      6. If not action_taken AND near_end_game < 3.0: DMZ check → ProposeDMZ.
      7. If history < 20 → return (redundant guard, preserved from decompile).
      8. If action_taken → return.
      9. XDO check → final trust gate → FUN_00433510.

    Unchecked callees: FUN_004117d0, FUN_004108a0, FUN_00401050,
                       FUN_00438b30, FUN_004325a0, FUN_00433510.
    Verified callee: ProposeDMZ (FUN_00432960).
    """
    # Cross-slice call: ``propose_dmz`` lives in ``.senders`` and ``senders``
    # already imports from this module — a module-level import here would
    # create a real circular import.  Deferred import at call time is safe
    # because both submodules are fully loaded by then.
    from .senders import propose_dmz

    own = getattr(state, 'albert_power_idx', 0)
    action_taken = False  # local_15

    # 1. Gate check: FUN_004117d0((int)param_1) — non-zero → skip.
    if _press_gate_check(state, power):
        return

    # 2. PCE renegotiation check (only when history > 9).
    #    C: iVar5 = DAT_00bb6e14[power*3]  = _Myhead (sentinel ptr) of press map.
    #       puVar2 = FUN_004108a0(...)      → (container, found_node).
    #       if (puVar2[1] != iVar5)         → found_node != _Myhead = PCE was found.
    #    The earlier Python port read iVar5 as _Mysize and the condition as
    #    "count changed", which never fires.  Correct interpretation: if PCE
    #    token exists in press history, attempt renegotiation.
    if state.g_history_counter > 9:
        pce_result = _find_press_token(state, power, _TOK_PCE)  # FUN_004108a0(..., &PCE)
        if _press_token_found(pce_result, state, power):        # found_node != _Myhead
            if _renegotiate_pce(state, power, send_fn=send_fn):  # FUN_00438b30
                return

    # 3. Bidirectional trust gate.
    #    iVar5         = own * 21 + power  (own → sender direction)
    #    reverse index = own + power * 21  (sender → own direction)
    thi_os = int(state.g_ally_trust_score_hi[own, power])          # trust_hi own→sender
    tlo_os = int(state.g_ally_trust_score[own, power])             # trust_lo own→sender
    thi_so = int(state.g_ally_trust_score_hi[power, own])          # trust_hi sender→own
    tlo_so = int(state.g_ally_trust_score[power, own])             # trust_lo sender→own

    # Trust < 3 condition: hi < 0 OR (hi < 1 AND lo < 3)
    def _trust_below_3(hi: int, lo: int) -> bool:
        return hi < 0 or (hi < 1 and lo < 3)

    trust_override = (getattr(state, 'g_press_flag', 0) == 1)  # DAT_00baed68

    if _trust_below_3(thi_os, tlo_os):
        # own→sender trust < 3: allow only if override flag set
        if not trust_override:
            return
    elif _trust_below_3(thi_so, tlo_so):
        # sender→own trust < 3 (own→sender was OK): same fallback
        if not trust_override:
            return

    # 4. ALY + VSS check (history > 9).
    if state.g_history_counter > 9:
        aly_result = _find_press_token(state, power, _TOK_ALY)   # FUN_004108a0(..., &ALY)
        if _press_token_found(aly_result, state, power):         # FUN_00401050
            vss_result = _find_press_token(state, power, _TOK_VSS)  # FUN_004108a0(..., &VSS)
            if _press_token_found(vss_result, state, power):
                action_taken = _execute_aly_vss(state, power, send_fn=send_fn)   # FUN_004325a0

    # 5. First history-20 gate.
    if state.g_history_counter < 20:
        return

    # 6. DMZ check: only if no action yet and not near end-game.
    if not action_taken and state.g_near_end_game_factor < 3.0:
        dmz_result = _find_press_token(state, power, _TOK_DMZ)   # FUN_004108a0(..., &DMZ)
        if _press_token_found(dmz_result, state, power):
            # Extra condition (lines 80-83 of decompile):
            #   DAT_00baed68 == 0  OR  g_diplomacy_state_b[power] > 1
            dipl_b = int(getattr(state, 'g_diplomacy_state_b', [0] * 8)[power])  # DAT_004d5484[power]
            dipl_a = int(getattr(state, 'g_diplomacy_state_a', [0] * 8)[power])  # DAT_004d5480[power]
            dipl_ok = not trust_override or (dipl_b >= 0 and (dipl_b > 0 or dipl_a > 1))
            if dipl_ok:
                action_taken = bool(propose_dmz(state, power, send_fn=send_fn))  # FUN_00432960

    # 7. Second history-20 guard (matches decompile; effectively dead code).
    if state.g_history_counter < 20:
        return

    # 8. If any action was taken, done.
    if action_taken:
        return

    # 9. XDO check.
    xdo_result = _find_press_token(state, power, _TOK_XDO)       # FUN_004108a0(..., &XDO)
    if not _press_token_found(xdo_result, state, power):         # FUN_00401050
        return

    # Final trust gate for XDO execution.
    # Strong path: both directions >= 3 → execute.
    trust_os_strong = thi_os >= 0 and (thi_os > 0 or tlo_os > 2)
    trust_so_strong = thi_so > 0 or (thi_so >= 0 and tlo_so > 2)

    if trust_os_strong and trust_so_strong:
        _execute_xdo(state, power, send_fn=send_fn)               # FUN_00433510
        return

    # Weak path: own SC count must be exactly 1, and sender trust must be ≥ 0 and ≠ 0.
    if getattr(state, 'curr_sc_cnt', [0] * 8)[own] != 1:
        return
    if thi_so < 0:
        return
    if thi_so < 1 and tlo_so == 0:
        return
    _execute_xdo(state, power, send_fn=send_fn)                   # FUN_00433510
