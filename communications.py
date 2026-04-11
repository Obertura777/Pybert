from .state import InnerGameState

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

import re

def process_frm_message(state: InnerGameState, sender: str, sub_message: str):
    """
    Port of process_frm and FRIENDLY logic (FUN_0042dc40).
    Updates g_AllyMatrix and sets relation tracking arrays by unpacking FRM envelopes.
    """
    power_names = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]
    
    sender_upper = sender.upper()
    if sender_upper not in power_names:
        return
        
    sender_id = power_names.index(sender_upper)
    
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


# ── DispatchScheduledPress (was PrepareOrderGenState) ────────────────────────

import time as _time
from .monte_carlo import check_time_limit

def dispatch_scheduled_press(state: InnerGameState, send_fn=None) -> None:
    """
    Port of FUN_004424e0 = DispatchScheduledPress (renamed from PrepareOrderGenState).

    Iterates g_MasterOrderList and sends any enqueued press messages whose
    scheduled delivery time has elapsed since g_SessionStartTime.

    For each due entry:
      - press_type == 'SND' → call send_fn(data), then invoke per-power ally press
      - press_type == 'THN' → extract first arg and execute the THEN action

    After dispatching, removes the entry from the list.

    Research.md §5271.

    Parameters
    ----------
    state   : InnerGameState
    send_fn : optional callable(data) — wire to SendDM; defaults to a no-op log
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (lambda data: _log.debug("DispatchScheduledPress: SND %r", data))

    elapsed = _time.time() - float(getattr(state, 'g_SessionStartTime', 0.0))
    remaining: list = []

    for entry in list(getattr(state, 'g_MasterOrderList', [])):
        scheduled_time = float(entry.get('scheduled_time', 0.0))
        if elapsed <= scheduled_time:
            remaining.append(entry)
            continue

        press_type = entry.get('press_type', '')
        data       = entry.get('data', [])

        if press_type == 'SND':
            _send(data)
            # Send per-power ally press for each power byte in results
            for power_byte in entry.get('results', []):
                _send_ally_press_by_power(state, int(power_byte), _send)

        elif press_type == 'THN':
            # Execute THEN action: first element of data is the power index
            if data:
                _execute_then_action(state, int(data[0]))
        # entry consumed — do NOT add to remaining

    state.g_MasterOrderList = remaining


def _send_ally_press_by_power(state: InnerGameState, power: int, send_fn) -> None:
    """
    Port of SendAllyPressByPower (FUN_00421570).
    Sends pending ally direct-message press for the given power index.
    """
    # Gather any pending DM entries for this power from g_BroadcastList
    for entry in getattr(state, 'g_BroadcastList', []):
        if entry.get('power') == power and not entry.get('sent', False):
            send_fn(entry.get('data', []))
            entry['sent'] = True


def _press_gate_check(state: InnerGameState, power: int) -> bool:
    """
    Stub for FUN_004117d0((int)param_1).
    Returns True when this power's press channel should be skipped.
    Original: non-zero → skip. Stubbed as always False (proceed).
    UNCHECKED — FUN_004117d0 not yet verified.
    """
    return False


def _press_list_count(state: InnerGameState, power: int) -> int:
    """
    Stub for DAT_00bb6e14[power * 3].
    Returns the current count field of the press-history list for power.
    UNCHECKED — FUN_004108a0 / DAT_00bb6e14 not yet verified.
    """
    history = getattr(state, 'g_press_history', {})
    return len(history.get(power, []))


def _find_press_token(state: InnerGameState, power: int, token_type: str) -> object:
    """
    Stub for FUN_004108a0(&DAT_00bb6e10 + power * 0xc, local_8, &TOKEN).
    Searches the press-history list for `power` for an entry of `token_type`.
    Returns the found entry, or None.
    UNCHECKED — FUN_004108a0 not yet verified.
    """
    for entry in getattr(state, 'g_press_history', {}).get(power, []):
        if entry.get('type') == token_type:
            return entry
    return None


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
      2. g_TurnOrderHist_Lo/Hi[power] == 0                   (PCE not sent this turn)
      3. g_AllyTrustScore[own, power] == 0 (both words)      (no current own→power trust)
      4. g_PressFlag == 1  OR  g_AllyTrustScore[power, own] == 0  (press mode or no reverse trust)
      5. g_EnemyFlag[power] == 0                             (power not designated enemy)
      6. g_InfluenceMatrix_B[own, power] > 0.0               (positive influence toward power)
      7. g_RelationScore[own, power] >= 0                    (not hostile relation)
      8. g_season == 'SPR'                                    (Spring phase only)

    Secondary gate (after PCE found in press history):
      g_InfluenceMatrix_B[own, power] > 17.0  OR
      g_InfluenceRankFlag[own, power] < 4     OR
      g_DeceitLevel > 1

    Returns True if PRP(PCE) was dispatched.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (lambda msg: _log.debug("_renegotiate_pce: %s", msg))

    own = getattr(state, 'albert_power_idx', 0)

    # Gate 1: not self
    if power == own:
        return False

    # Gate 2: g_TurnOrderHist_Lo[power] == 0 && g_TurnOrderHist_Hi[power] == 0
    #          (DAT_004d53d8[power*2] == 0 && DAT_004d53dc[power*2] == 0)
    if int(state.g_TurnOrderHist_Lo[power]) != 0 or int(state.g_TurnOrderHist_Hi[power]) != 0:
        return False

    # Gate 3: g_AllyTrustScore[own, power] == 0 (both lo and hi words)
    #          ((&g_AllyTrustScore)[iVar1*2] == 0 && (&g_AllyTrustScore_Hi)[iVar1*2] == 0)
    if int(state.g_AllyTrustScore[own, power]) != 0 or int(state.g_AllyTrustScore_Hi[own, power]) != 0:
        return False

    # Gate 4: press mode OR no reverse trust
    #          (DAT_00baed68 == '\x01' || (g_AllyTrustScore[power,own] both == 0))
    press_mode = (getattr(state, 'g_PressFlag', 0) == 1)
    if not press_mode:
        if int(state.g_AllyTrustScore[power, own]) != 0 or int(state.g_AllyTrustScore_Hi[power, own]) != 0:
            return False

    # Gate 5: power not designated enemy
    #          (&DAT_004cf568)[power*2] == 0 && (&DAT_004cf56c)[power*2] == 0
    if int(state.g_EnemyFlag[power]) != 0:
        return False

    # Gate 6 & 7: positive influence AND non-negative relation
    #          0.0 < g_InfluenceMatrix_B[iVar1] && -1 < DAT_00634e90[iVar1]
    inf_b = float(state.g_InfluenceMatrix_B[own, power])
    if inf_b <= 0.0:
        return False
    if int(state.g_RelationScore[own, power]) < 0:
        return False

    # Gate 8: Spring phase only (SPR == *(short *)(iVar2 + 0x244a))
    if getattr(state, 'g_season', '') != 'SPR':
        return False

    # Inner check: PCE entry must exist in press history for this power
    #   this_00 = FUN_004108a0(press_list_base, apuStack_4c, &PCE)
    #   uVar5   = FUN_00401050(this_00, ppuVar6)  → non-zero if found
    pce_result = _find_press_token(state, power, 'PCE')
    if not _press_token_found(pce_result, state, power):
        return False

    # Secondary gate: strong influence OR top-4 rank OR multi-year game
    #   17.0 < g_InfluenceMatrix_B[iVar1] || DAT_006340c0[iVar1] < 4 || 1 < g_DeceitLevel
    rank = int(state.g_InfluenceRankFlag[own, power])
    deceit = int(getattr(state, 'g_DeceitLevel', 0))
    if not (inf_b > 17.0 or rank < 4 or deceit > 1):
        return False

    # All gates passed — mark PCE as sent this turn and dispatch PRP(PCE(own, power))
    # DAT_004d53d8[power*2] = 1; DAT_004d53dc[power*2] = 0
    state.g_TurnOrderHist_Lo[power] = 1
    state.g_TurnOrderHist_Hi[power] = 0

    # PROPOSE(this): send PRP ( PCE ( own power ) )
    # C: local_68[0] = (ushort)param_1 & 0xff | 0x4100  → DAIDE power token for param_1
    #    FUN_00466540(local_64, apuStack_1c, local_68)   → [own_tok, target_tok]
    #    FUN_00466f80(&PCE, &puStack_5c, ppuVar6)        → PCE ( own target )
    #    FUN_00466f80(&PRP, apuStack_4c, ppuVar6)        → PRP ( PCE ( own target ) )
    _send(f"PRP ( PCE ( {own} {power} ) )")

    return True


def _execute_aly_vss(state: InnerGameState, power: int, send_fn=None) -> bool:
    """
    Port of FUN_004325a0(this, param_1).

    Called (from _execute_then_action) when ALY and VSS entries are both present
    in press history for *power* (= param_1 = target power index).

    Logic (faithful to decompile):
      own        = albert_power_idx  (this+8+0x2424)
      mutual_enemy = g_MutualEnemyTable[power]  (DAT_00b9fdd8[param_1])

      Gate 1: mutual_enemy >= 0  (valid)
      Gate 2: g_AllyMatrix[power, mutual_enemy] == 0  (no existing alliance)

      bVar3: scan all powers — any p where g_AllyMatrix[p, mutual_enemy] == 1 (tentative)

      own_row = own * 21
      Condition A: g_InfluenceRankFlag[own, power] < 4  AND  g_PressFlag == 1
      Condition B: bVar3  AND  g_PressFlag == 1
                   AND  g_DiplomacyStateA[mutual_enemy] == 1
                   AND  g_DiplomacyStateB[mutual_enemy] == 0
      Condition C: g_EnemyFlag[mutual_enemy] == 1
                   AND  g_InfluenceRankFlag[own, mutual_enemy] < 4
                   AND  raw[mutual_enemy, own] / (raw[own, mutual_enemy] + 1) < 4.5
                   AND  (raw[mutual_enemy, own] > 5  OR  raw[own, mutual_enemy] > 5)

      If any condition fires:
        Send PRP ( ALY ( own power ) VSS ( mutual_enemy ) ) to power.
        g_AllyMatrix[power, mutual_enemy] = -4  (cooling-off / proposal-sent marker)
        return True

    Returns False if no proposal was sent.

    NOTE: g_DiplomacyStateA/B (DAT_004d5480/4) are written by CAL_BOARD block 4;
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

    # iVar2 = g_MutualEnemyTable[param_1]
    mutual_enemy = int(state.g_MutualEnemyTable[power])

    # Gate 1: mutual enemy must be valid
    if mutual_enemy < 0:
        return False

    # Gate 2: g_AllyMatrix[power*21 + mutual_enemy] == 0  (neutral; not already allied)
    if int(state.g_AllyMatrix[power, mutual_enemy]) != 0:
        return False

    # bVar3: any power has tentative alliance (== 1) with mutual_enemy
    # C loop: piVar8 starts at &g_AllyMatrix[mutual_enemy] then strides +21 per row
    bVar3 = any(int(state.g_AllyMatrix[p, mutual_enemy]) == 1 for p in range(num_powers))

    press_on = (int(getattr(state, 'g_PressFlag', 0)) == 1)

    # Condition A: g_InfluenceRankFlag[own, power] < 4  AND  press mode on
    # C: DAT_006340c0[own*21 + param_1] < 4  &&  DAT_00baed68 == 1
    rank_own_target = int(state.g_InfluenceRankFlag[own, power])
    cond_a = (rank_own_target < 4) and press_on

    # Condition B: bVar3 AND press on AND DiplomacyStateA[mutual_enemy]==1 AND B==0
    # C: bVar3 && DAT_00baed68==1 && DAT_004d5480[iVar2*2]==1 && DAT_004d5484[iVar2*2]==0
    _dipl_a_arr = getattr(state, 'g_DiplomacyStateA', None)
    _dipl_b_arr = getattr(state, 'g_DiplomacyStateB', None)
    dipl_a = int(_dipl_a_arr[mutual_enemy]) if _dipl_a_arr is not None else 0
    dipl_b = int(_dipl_b_arr[mutual_enemy]) if _dipl_b_arr is not None else 0
    cond_b = bVar3 and press_on and (dipl_a == 1) and (dipl_b == 0)

    # Condition C: mutual_enemy is strategic enemy AND in our top-3 influence rank
    #              AND influence ratio < 4.5 AND significant mutual influence
    # C: DAT_004cf568[iVar2*2]==1 && DAT_004cf56c[iVar2*2]==0  (g_EnemyFlag[mutual_enemy])
    #    DAT_006340c0[own*21 + mutual_enemy] < 4                (g_InfluenceRankFlag)
    #    raw[mutual_enemy, own] / (raw[own, mutual_enemy] + 1) < 4.5
    #    raw[mutual_enemy, own] > 5  OR  raw[own, mutual_enemy] > 5
    enemy_flag = int(state.g_EnemyFlag[mutual_enemy])
    rank_own_mutual = int(state.g_InfluenceRankFlag[own, mutual_enemy])
    raw_mutual_own = float(state.g_InfluenceMatrix_Raw[mutual_enemy, own])
    raw_own_mutual = float(state.g_InfluenceMatrix_Raw[own, mutual_enemy])
    ratio = raw_mutual_own / (raw_own_mutual + 1.0)
    cond_c = (
        (enemy_flag == 1) and
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
    _send(f"PRP ( ALY ( {own} {power} ) VSS ( {mutual_enemy} ) )")

    # Mark g_AllyMatrix[power*21 + mutual_enemy] = 0xfffffffc = -4 (cooling-off)
    # C: (&g_AllyMatrix)[(int)(puVar6 + iVar2)] = 0xfffffffc
    state.g_AllyMatrix[power, mutual_enemy] = -4

    return True


def _execute_xdo(state: InnerGameState, power: int) -> None:
    """
    Port of FUN_00433510(this, param_1) — param_1 = sender power index.

    Searches g_BroadcastList for already-sent own proposals (type_flag==1,
    sent==True, count>0) whose current board state no longer matches the
    expected order (GameBoard_GetPowerRec check) and which have not yet been
    submitted as an XDO proposal (g_XdoProposalList dedup).

    For each such candidate, computes per-power score deltas (iVar5 = own
    gain, iVar8 = sender gain) via two paths:
      • count >= 1 AND alt_scores valid (not −1000000): use alt_scores.
      • otherwise (LAB_004337b0 fallback): node.scores[p] − node.baseline[p].

    Accumulates ALL candidates that strictly improve the running best total
    (iVar5 + iVar8 > best_score) with iVar5 > 0 and iVar8 > −800, mirroring
    the C loop which appends to local_3c/local_4c on every new maximum.

    After iteration, if any candidates were found:
      • Logs each accumulated PRP(XDO) proposal (PROPOSE macro equivalent).
      • Registers all proposed order sequences in g_XdoProposalList
        (FUN_00419300 equivalent) so the same compound key is not re-sent.

    Simplification vs. C: the compound order-sequence key used by
    FUN_00410980/FUN_00419300 is approximated here as a per-province set;
    the C code passes the full accumulated order-sequence list as the lookup
    key.

    Unchecked callees: FUN_00410980, FUN_00419300, FUN_00422a90,
                       FUN_004109f0, FUN_0040fa80, FUN_0040dfe0,
                       FUN_0040f470, FUN_00465f60, PROPOSE macro.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    own: int = getattr(state, 'albert_power_idx', 0)
    best_score: int = -20000          # local_a4

    # Accumulators (local_4c = province list, local_3c = PRP list).
    accumulated_provinces: list = []
    accumulated_prp: list = []

    # g_XdoProposalList — set of order-seq keys already submitted as XDO
    # proposals (approximated as per-province dedup; C uses compound key).
    # DAT_00bb6df4 / DAT_00bb6df8 sentinel.
    xdo_sent: set = getattr(state, 'g_XdoProposalList', set())

    for node in getattr(state, 'g_BroadcastList', []):
        # Gate 1: type_flag == 1  (node[7] == 1)
        if node.get('type_flag', 0) != 1:
            continue

        # Gate 2: count > 0  ((int)node[0x27] > 0)
        count: int = int(node.get('count', 0))
        if count <= 0:
            continue

        # Gate 3: sent_flag == 1  (*(char*)(node+6) == '\x01')
        if not node.get('sent', False):
            continue

        # GameBoard_GetPowerRec check: puVar4[1] != local_50.
        # Skip when the board's current order for *power* still matches the
        # proposal's expected order (already satisfied on the board).
        province = node.get('province')
        if province is None:
            continue
        board_order = node.get('board_orders', {}).get(power)
        expected    = node.get('order_match')
        if board_order is not None and board_order == expected:
            continue

        # FUN_00410980: check if province already submitted (not-found → process).
        # C: if (puVar4[1] == iVar5) → "not found in g_XdoProposalList → evaluate".
        if province in xdo_sent:
            continue

        # Trust baseline lookup (FUN_0040fa80 + FUN_004109f0 at node+0x8c).
        # Always executed here since count > 0 was already verified (the inner
        # redundant check at C line 149 is always true at this point).
        baseline: dict = node.get('baseline', {})   # power → int

        # Score computation — two paths (mirror of LAB_004337b0 / else branch):
        #   C else branch (count >= 1): try alternative scores from current node
        #     at offset +0x38 + power*4 (FUN_0040fa80(&local_ac) + ...).
        #     FUN_0040dfe0 checks validity of the baseline iterator; if it or
        #     either alt score is −1000000, fall through to LAB_004337b0.
        #   C LAB_004337b0 (direct): node[power+0x12] − baseline[power].
        score_own: int
        score_sender: int
        if count >= 1:
            alt: dict = node.get('alt_scores', {})
            a_own    = alt.get(own,   -1000000)
            a_sender = alt.get(power, -1000000)
            # FUN_0040dfe0 validity gate + sentinel checks (−1000000 == invalid).
            if a_own != -1000000 and a_sender != -1000000:
                score_own    = a_own
                score_sender = a_sender
            else:
                # LAB_004337b0 fallback
                scores       = node.get('scores', {})
                score_own    = scores.get(own,   0) - baseline.get(own,   0)
                score_sender = scores.get(power, 0) - baseline.get(power, 0)
        else:
            # LAB_004337b0: direct delta (dead path here since count>0 checked
            # above, but kept for structural fidelity with the decompile).
            scores       = node.get('scores', {})
            score_own    = scores.get(own,   0) - baseline.get(own,   0)
            score_sender = scores.get(power, 0) - baseline.get(power, 0)

        # FUN_00422a90(this) == 0: press-send gate (unchecked; treated as 0).
        # Accumulate whenever this beats the running best combined score.
        total: int = score_own + score_sender
        if score_own > 0 and score_sender > -800 and total > best_score:
            best_score = total
            accumulated_provinces.append(province)
            # Build PRP(XDO) note — power token: (power & 0xFF) | 0x4100
            power_token = (power & 0xFF) | 0x4100
            order_seq   = node.get('proposal_seq', [])
            accumulated_prp.append({
                'power_token': power_token,
                'order_seq':   order_seq,
                'province':    province,
                'score_own':   score_own,
                'score_sender': score_sender,
            })

    if not accumulated_prp:
        return  # bVar1 == false

    # bVar1 == true: send all accumulated PRP(XDO) proposals (PROPOSE macro).
    # C: local_b4[0] = (byte)param_1 | 0x4100
    #    FUN_00465f30/AppendList/FUN_00465f60 wrap the token + proposals
    #    PROPOSE(local_9c)
    #    FUN_00419300 registers in g_XdoProposalList
    power_token = (power & 0xFF) | 0x4100
    for prp in accumulated_prp:
        _log.debug(
            "_execute_xdo: PRP(XDO) power_token=0x%04x province=%s "
            "score_own=%d score_sender=%d seq=%s",
            prp['power_token'], prp['province'],
            prp['score_own'], prp['score_sender'], prp['order_seq'],
        )

    # FUN_00419300: register proposed provinces in g_XdoProposalList.
    for prov in accumulated_provinces:
        xdo_sent.add(prov)
    state.g_XdoProposalList = xdo_sent


def _execute_then_action(state: InnerGameState, power: int) -> None:
    """
    Port of ExecuteThennAction (FUN_00439c30).

    Executes conditional THN press actions dispatched by ScheduledPressDispatch.
    param_1 = power (sender power index); puVar6 = own power (albert_power_idx).

    Control flow (faithful to decompile):
      1. Gate: FUN_004117d0(power) → skip if non-zero.
      2. If history > 9: PCE list check + optional renegotiation (FUN_00438b30).
      3. Bidirectional trust gate (own→sender AND sender→own); override via
         g_TrustOverride (DAT_00baed68).
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
    own = getattr(state, 'albert_power_idx', 0)
    action_taken = False  # local_15

    # 1. Gate check: FUN_004117d0((int)param_1) — non-zero → skip.
    if _press_gate_check(state, power):
        return

    # 2. PCE list consistency check (only when history > 9).
    #    iVar5 = DAT_00bb6e14[power * 3] saved before lookup; puVar2[1] compared after.
    #    In Python the lookup is synchronous so counts never diverge — _renegotiate_pce
    #    will never fire, but the call sequence is preserved for fidelity.
    if state.g_HistoryCounter > 9:
        saved_count = _press_list_count(state, power)           # DAT_00bb6e14[power * 3]
        pce_result  = _find_press_token(state, power, 'PCE')    # FUN_004108a0(..., &PCE)
        # puVar2[1] (count field of result) vs iVar5 (saved count)
        pce_count_after = len(pce_result) if isinstance(pce_result, list) else saved_count
        if pce_count_after != saved_count:
            if _renegotiate_pce(state, power):                  # FUN_00438b30
                return

    # 3. Bidirectional trust gate.
    #    iVar5         = own * 21 + power  (own → sender direction)
    #    reverse index = own + power * 21  (sender → own direction)
    thi_os = int(state.g_AllyTrustScore_Hi[own, power])          # trust_hi own→sender
    tlo_os = int(state.g_AllyTrustScore[own, power])             # trust_lo own→sender
    thi_so = int(state.g_AllyTrustScore_Hi[power, own])          # trust_hi sender→own
    tlo_so = int(state.g_AllyTrustScore[power, own])             # trust_lo sender→own

    # Trust < 3 condition: hi < 0 OR (hi < 1 AND lo < 3)
    def _trust_below_3(hi: int, lo: int) -> bool:
        return hi < 0 or (hi < 1 and lo < 3)

    trust_override = (getattr(state, 'g_TrustOverride', 0) == 1)  # DAT_00baed68

    if _trust_below_3(thi_os, tlo_os):
        # own→sender trust < 3: allow only if override flag set
        if not trust_override:
            return
    elif _trust_below_3(thi_so, tlo_so):
        # sender→own trust < 3 (own→sender was OK): same fallback
        if not trust_override:
            return

    # 4. ALY + VSS check (history > 9).
    if state.g_HistoryCounter > 9:
        aly_result = _find_press_token(state, power, 'ALY')     # FUN_004108a0(..., &ALY)
        if _press_token_found(aly_result, state, power):         # FUN_00401050
            vss_result = _find_press_token(state, power, 'VSS') # FUN_004108a0(..., &VSS)
            if _press_token_found(vss_result, state, power):
                action_taken = _execute_aly_vss(state, power)   # FUN_004325a0

    # 5. First history-20 gate.
    if state.g_HistoryCounter < 20:
        return

    # 6. DMZ check: only if no action yet and not near end-game.
    if not action_taken and state.g_NearEndGameFactor < 3.0:
        dmz_result = _find_press_token(state, power, 'DMZ')     # FUN_004108a0(..., &DMZ)
        if _press_token_found(dmz_result, state, power):
            # Extra condition (lines 80-83 of decompile):
            #   DAT_00baed68 == 0  OR  g_DiplomacyStateB[power] > 1
            dipl_b = int(getattr(state, 'g_DiplomacyStateB', [0] * 8)[power])  # DAT_004d5484[power]
            dipl_a = int(getattr(state, 'g_DiplomacyStateA', [0] * 8)[power])  # DAT_004d5480[power]
            dipl_ok = not trust_override or (dipl_b > 0 and (dipl_b > 1 or dipl_a > 1))
            if dipl_ok:
                action_taken = bool(propose_dmz(state, power))  # FUN_00432960

    # 7. Second history-20 guard (matches decompile; effectively dead code).
    if state.g_HistoryCounter < 20:
        return

    # 8. If any action was taken, done.
    if action_taken:
        return

    # 9. XDO check.
    xdo_result = _find_press_token(state, power, 'XDO')         # FUN_004108a0(..., &XDO)
    if not _press_token_found(xdo_result, state, power):         # FUN_00401050
        return

    # Final trust gate for XDO execution.
    # Strong path: both directions >= 3 → execute.
    trust_os_strong = thi_os >= 0 and (thi_os > 0 or tlo_os > 2)
    trust_so_strong = thi_so > 0 or (thi_so >= 0 and tlo_so > 2)

    if trust_os_strong and trust_so_strong:
        _execute_xdo(state, power)                               # FUN_00433510
        return

    # Weak path: own SC count must be exactly 1, and sender trust must be ≥ 0 and ≠ 0.
    if getattr(state, 'curr_sc_cnt', [0] * 8)[own] != 1:
        return
    if thi_so < 0:
        return
    if thi_so < 1 and tlo_so == 0:
        return
    _execute_xdo(state, power)                                   # FUN_00433510


# ── ProposeDMZ ────────────────────────────────────────────────────────────────

def propose_dmz(state: InnerGameState,
                ally_power: int,
                send_fn=None) -> bool:
    """
    Port of ProposeDMZ (FUN_00432960).

    Iterates g_OrderList looking for contested provinces and sends DMZ
    proposals to *ally_power* via DAIDE PRP(DMZ(...)) press.

    Returns True if at least one proposal was sent.

    Three message types (research.md §1381):
      ≥2 contested  → PRP ( DMZ ( own ally ) prov1 prov2 … )
      1 bilateral   → PRP ( DMZ ( own ally ) prov )
      1 unilateral  → PRP ( DMZ ally prov )

    g_DMZAggressiveness = DAT_004c6bd4/4 − 4 ∈ [−4, 20] (randomised per game).
    Proposals to the same (power, province) pair are capped at 2.

    Research.md §1381.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (lambda msg: _log.debug("ProposeDMZ: %s", msg))

    own_power = getattr(state, 'albert_power_idx', 0)
    threshold = int(getattr(state, 'g_DMZAggressiveness', 0))
    sent = False

    contested: list = []   # entries with flag1=1

    for entry in getattr(state, 'g_OrderList', []):
        if entry.get('done', False):
            continue
        province  = int(entry.get('province', -1))
        flag1     = bool(entry.get('flag1', False))
        flag2     = bool(entry.get('flag2', False))
        flag3     = bool(entry.get('flag3', False))
        score     = int(entry.get('score', 0))

        if province < 0 or not flag1:
            continue

        # Cap per (power, province) at 2 proposals
        key = (ally_power, province)
        if state.g_SentProposals.get(key, 0) >= 2:
            continue

        if score < threshold:
            continue

        contested.append({'province': province, 'flag2': flag2, 'flag3': flag3})

    if len(contested) >= 2:
        provinces = [c['province'] for c in contested]
        prov_str = ' '.join(str(p) for p in provinces)
        msg = f"PRP ( DMZ ( {own_power} {ally_power} ) {prov_str} )"
        _send(msg)
        for c in contested:
            key = (ally_power, c['province'])
            state.g_SentProposals[key] = state.g_SentProposals.get(key, 0) + 1
        sent = True

    elif len(contested) == 1:
        c = contested[0]
        province = c['province']
        key = (ally_power, province)
        if c['flag2'] and not c['flag3']:
            msg = f"PRP ( DMZ ( {own_power} {ally_power} ) {province} )"
        else:
            msg = f"PRP ( DMZ {ally_power} {province} )"
        _send(msg)
        state.g_SentProposals[key] = state.g_SentProposals.get(key, 0) + 1
        sent = True

    # Mark proposed entries as done
    if sent:
        proposed_provs = {c['province'] for c in contested}
        for entry in state.g_OrderList:
            if int(entry.get('province', -1)) in proposed_provs:
                entry['done'] = True

    return sent


# ── FRIENDLY ─────────────────────────────────────────────────────────────────

def friendly(state: InnerGameState) -> None:
    """
    Port of FRIENDLY (FUN_0042dc40).

    Per-turn power×power relationship update engine called from
    GenerateAndSubmitOrders between PhaseHandler(1) and PhaseHandler(2).

    Three phases (research.md §4364 / decompiled.txt):
      Phase 1 — update g_RelationScore for each (row, col) power pair
      Phase 2 — UpdateRelationHistory (FUN_0040d7e0)
      Phase 3 — upgrade/downgrade g_AllyMatrix based on trust thresholds
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    num_powers = 7
    own_power  = getattr(state, 'albert_power_idx', 0)
    season     = getattr(state, 'g_season', 'SPR')
    season_rewards = season in ('FAL', 'WIN')

    # Phase 1 — per-power-pair relationship score update
    for row in range(num_powers):
        for col in range(num_powers):
            if row == col:
                continue

            # Eliminated power: zero out trust/relation for BOTH [row,col] and [col,row].
            # The reverse-direction clear pre-zeros pairs that won't reach the eliminated
            # branch when row=eliminated (since the check is on col's sc_count, not row's).
            if int(state.sc_count[col]) == 0:
                state.g_AllyTrustScore[row, col]    = 0
                state.g_AllyTrustScore_Hi[row, col] = 0
                state.g_TrustExtended_Lo[row, col]  = 0
                state.g_TrustExtended_Hi[row, col]  = 0
                state.g_RelationScore[row, col]      = 0
                # symmetric clear (*piVar3 / iStack_34 writes in decompiled)
                state.g_AllyTrustScore[col, row]    = 0
                state.g_AllyTrustScore_Hi[col, row] = 0
                state.g_TrustExtended_Lo[col, row]  = 0
                state.g_TrustExtended_Hi[col, row]  = 0
                state.g_RelationScore[col, row]      = 0
                continue

            stab      = int(state.g_StabFlag[row, col])
            cease     = int(state.g_CeaseFire[row, col])
            coop      = int(state.g_CoopFlag[row, col])
            some_coop = int(state.g_SomeCoopScore[row, col])
            trust_lo  = int(state.g_AllyTrustScore[row, col])
            trust_hi  = int(state.g_AllyTrustScore_Hi[row, col])
            peace_sig = int(state.g_PeaceSignal[row, col])
            neutral   = int(state.g_NeutralFlag[row, col])
            relation  = int(state.g_RelationScore[row, col])
            rel_sym   = int(state.g_RelationScore[col, row])
            rank      = int(state.g_InfluenceRankFlag[row, col])
            stab_n    = int(state.g_StabCounter[row, col])

            if stab == 1:
                # Two-path stab penalty based on relation levels and influence rank.
                # Low-score path: at least one relation < 10 AND rank < 4
                if (rel_sym < 10 or relation < 10) and rank < 4:
                    if rel_sym > 4 and relation > 4:
                        # Both scores > 4: normal penalty n*-10-10, applied symmetrically
                        penalty  = stab_n * (-10) - 10
                        relation = max(relation + penalty, -50)
                        rel_sym  = max(rel_sym  + penalty, -50)
                        state.g_RelationScore[row, col] = relation
                        state.g_RelationScore[col, row] = rel_sym
                        state.g_StabCounter[row, col]   += 1
                    else:
                        # At least one score ≤ 4: zero both directions
                        state.g_RelationScore[row, col] = 0
                        state.g_RelationScore[col, row] = 0
                else:
                    # High-score / high-rank stab: larger penalty n*-20-70
                    penalty  = stab_n * (-20) - 70
                    relation = max(relation + penalty, -50)
                    rel_sym  = max(rel_sym  + penalty, -50)
                    state.g_RelationScore[row, col] = relation
                    state.g_RelationScore[col, row] = rel_sym
                    state.g_StabCounter[row, col]   += 1
                    # Clear betrayal counters for own power's other allies (cancel pending peace)
                    if row == own_power:
                        for k in range(num_powers):
                            if k != col:
                                state.g_BetrayalCounter[k] = 0
                _log.debug("FRIENDLY: stab (%d,%d) → rel=%d sym=%d",
                           row, col,
                           int(state.g_RelationScore[row, col]),
                           int(state.g_RelationScore[col, row]))

            elif cease == 1:
                # Cease-fire: cap both directions at 0
                if relation > 0:
                    state.g_RelationScore[row, col] = 0
                if rel_sym > 0:
                    state.g_RelationScore[col, row] = 0

            elif stab == 0 and coop == 0 and some_coop == 0 and season_rewards:
                # Normal relationship update (FAL/WIN only).
                # "Alliance confirmed" path requires: trust > 0 AND peace_signal == 1
                # AND neutral == 0 AND relation ≤ 49.
                alliance = (trust_hi >= 0 and (trust_hi >= 1 or trust_lo != 0) and
                            peace_sig == 1 and neutral == 0 and relation <= 49)

                if not alliance:
                    # Block A: symmetric partner has active trust, no peace signal → +5
                    sym_hi = int(state.g_AllyTrustScore_Hi[col, row])
                    sym_lo = int(state.g_AllyTrustScore[col, row])
                    if (sym_hi >= 0 and (sym_hi > 0 or sym_lo != 0) and
                            peace_sig == 0 and relation < 50):
                        relation += 5
                        state.g_RelationScore[row, col] = min(relation, 50)
                        if row == own_power:
                            _friendly_peace_signal_check(state, col, trust_lo, trust_hi,
                                                         neutral, peace_sig, relation, _log)
                    else:
                        # Block B: trust/neutral flags present, or relation < 0, or deceit < 2
                        b_cond = (trust_lo != 0 or trust_hi != 0 or neutral != 0 or
                                  relation < 0 or state.g_DeceitLevel < 2)
                        if b_cond:
                            if trust_lo == 0 and trust_hi == 0 and relation < 0:
                                # Organic recovery: +10, capped at 0
                                relation += 10
                                if relation > 0:
                                    relation = 0
                                state.g_RelationScore[row, col] = relation
                            elif (trust_lo == 0 and trust_hi == 0 and
                                  relation > 0 and neutral == 1):
                                # Neutral+positive: reset to 0
                                state.g_RelationScore[row, col] = 0
                        else:
                            # Block C: set tentative trust (row != own_power only)
                            if row != own_power:
                                state.g_AllyTrustScore[row, col]    = 1
                                state.g_AllyTrustScore_Hi[row, col] = 0
                                state.g_RelationScore[row, col]     = 0
                            else:
                                # LAB_0042df19: own_power — peace signal dispatch
                                _friendly_peace_signal_check(state, col, trust_lo, trust_hi,
                                                             neutral, peace_sig, relation, _log)

                    if int(state.g_RelationScore[row, col]) > 50:
                        state.g_RelationScore[row, col] = 50

                else:
                    # Block D: alliance confirmed — accumulate relation (+5 deceitful, +10 honest)
                    gain = 5 if state.g_DeceitLevel == 1 else 10
                    state.g_RelationScore[row, col] = relation + gain
                    if row == own_power:
                        _friendly_peace_signal_check(state, col, trust_lo, trust_hi,
                                                     neutral, peace_sig, relation, _log)
                    if int(state.g_RelationScore[row, col]) > 50:
                        state.g_RelationScore[row, col] = 50

    # Phase 2 — UpdateRelationHistory (FUN_0040d7e0).
    # Enforces a _safe_pow(1.8, trust_lo/10) minimum floor on every positive trust entry.
    for row in range(num_powers):
        for col in range(num_powers):
            if row == col:
                continue
            trust_lo = int(state.g_AllyTrustScore[row, col])
            trust_hi = int(state.g_AllyTrustScore_Hi[row, col])
            # Guard: trust > 0 (trust_hi >= 0 AND (trust_hi > 0 OR trust_lo != 0))
            if trust_hi >= 0 and (trust_hi > 0 or trust_lo != 0):
                floor_val = float(int(1.8 ** (trust_lo // 10)))
                if float(state.g_AllyTrustScore[row, col]) < floor_val:
                    state.g_AllyTrustScore[row, col] = floor_val

    # Phase 3 — g_AllyMatrix alliance state transitions.
    # trust_hi < 0 OR (trust_hi < 1 AND trust_lo < 5) → downgrade full (2) → tentative (1)
    # otherwise → upgrade tentative (1) → full (2)
    for row in range(num_powers):
        for col in range(num_powers):
            if row == col:
                continue
            trust_lo = int(state.g_AllyTrustScore[row, col])
            trust_hi = int(state.g_AllyTrustScore_Hi[row, col])
            ally_val = int(state.g_AllyMatrix[row, col])
            if trust_hi < 0 or (trust_hi < 1 and trust_lo < 5):
                if ally_val == 2:
                    state.g_AllyMatrix[row, col] = 1   # full → tentative
            else:
                if ally_val == 1:
                    state.g_AllyMatrix[row, col] = 2   # tentative → full


def _friendly_peace_signal_check(state: InnerGameState, col: int,
                                  trust_lo: int, trust_hi: int,
                                  neutral: int, peace_sig: int,
                                  relation: int, _log) -> None:
    """LAB_0042df19 sub-routine: log/clear betrayal counter when own power receives peace signal."""
    if (trust_lo == 0 and trust_hi == 0 and neutral == 0 and
            peace_sig == 1 and relation >= 0):
        state.g_BetrayalCounter[col] = 0
        _log.debug("FRIENDLY: getting peace signal from power %d", col)


# ── CancelPriorPress ──────────────────────────────────────────────────────────

def cancel_prior_press(state: InnerGameState,
                       own_power: int,
                       send_fn=None) -> None:
    """
    Port of CancelPriorPress (FUN_0040e8e0).

    Sends NOT(g_prior_press_token) via SendDM to withdraw a prior press
    proposal.  Guarded by g_cancel_press_sent (once-per-turn flag).
    Fires when:
      - curr_sc_cnt[own_power] > 0, OR
      - reconnect flag is set (param_1+8+0x24bc in original)

    Research.md §1319 / §2570 note.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (lambda msg: _log.debug("CancelPriorPress: %s", msg))

    # Once-per-turn guard
    if getattr(state, 'g_cancel_press_sent', 0) == 1:
        return

    token = getattr(state, 'g_prior_press_token', None)
    if token is None:
        return

    own_sc = int(state.sc_count[own_power]) if hasattr(state, 'sc_count') else 1
    reconnect = bool(getattr(state, 'g_reconnect_flag', False))

    if own_sc > 0 or reconnect:
        msg = f"NOT ( {token} )"
        _send(msg)
        state.g_cancel_press_sent = 1
        state.g_prior_press_token = None


# ── DispatchPressAndFallbackGOF ───────────────────────────────────────────────

def _is_game_active(state: InnerGameState) -> bool:
    """
    Port of FUN_00411740.

    When DAT_00baed46 (g_baed46) != 1: returns True unconditionally.
    When DAT_00baed46 == 1: iterates g_BroadcastList; if ANY proposal has its
    sent flag == 0 (not yet sent), returns False.  Returns True if all proposals
    have been sent (or the list is empty).

    C detail: puVar3 is undefined4*, so '*(char*)(puVar3 + 6)' is pointer
    arithmetic — offset = 6 * 4 = 24 bytes — reaching the sent_flag char at
    offset 24 of each proposal record (same field as puVar5[6] in
    BuildAndSendSUB).

    Callees: FUN_0047a948 = AssertFail (already documented);
             FUN_0040f470 = MSVC list iterator advance (see unchecked list).
    """
    if getattr(state, 'g_baed46', 0) != 1:
        return True
    for entry in getattr(state, 'g_BroadcastList', []):
        if not entry.get('sent', True):
            return False
    return True


def _check_server_reachable(state: InnerGameState, mode: int = -1) -> bool:
    """
    Stub for FUN_004117d0 (unchecked).

    Called as FUN_004117d0(-1) in FUN_00443ed0.  Returns '\x01' when the
    server is reachable; '\0' when the connection is lost.
    """
    return bool(getattr(state, 'g_server_reachable', True))


def dispatch_press_and_fallback_gof(state: InnerGameState,
                                    param_1: object,
                                    send_fn=None) -> None:
    """
    Port of FUN_00443ed0.

    Dispatches pending scheduled press, waits while active game processing
    is in flight (DAT_00bb65c4 != 0), then polls until one of two conditions
    warrants a fallback bare GOF send:
      (a) server becomes unreachable  (FUN_004117d0(-1) returns 0), OR
      (b) elapsed time since session start > g_base_wait_time + 25 s.

    When the fallback GOF fires: records elapsed time into g_elapsed_press_time,
    sends "GOF" via SendDM, and clears the GOF-pending flag
    (DAT_00baed47 → g_cancel_press_sent = 0).

    Does nothing if g_cancel_press_sent != 1 (GOF not pending) at any check
    point.

    Called from BuildAndSendSUB at LAB_004591b3 (loop exit) as
    FUN_00443ed0(pvVar22).

    Global mapping:
      DAT_00bb65c4  → state.g_processing_active   (nonzero while game processes)
      DAT_00baed47  → state.g_cancel_press_sent    (1 = fallback GOF still needed)
      DAT_00ba2880/84 → state.g_SessionStartTime   (int64 reference timestamp)
      DAT_00ba2858/5c → state.g_base_wait_time     (int64 base threshold seconds)
      DAT_00ba2860/64 → state.g_elapsed_press_time (int64 recorded elapsed time)

    Unchecked callees:
      FUN_00411740 → _is_game_active(state)
      FUN_004117d0 → _check_server_reachable(state, -1)
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _send = send_fn if send_fn is not None else (
        lambda msg: _log.debug("dispatch_press_and_fallback_gof: %r", msg))

    # C: FUN_00465870(local_2c) — init empty token list (Python: implicit list)
    # C: ScheduledPressDispatch(param_1)
    dispatch_scheduled_press(state, _send)

    # ── Phase 1: flush press while processing active ──────────────────────────
    # C: while (DAT_00bb65c4 != 0)
    while getattr(state, 'g_processing_active', 0) != 0:
        # C: if (CheckTimeLimit()) break
        if check_time_limit(state):
            break
        # C: if (DAT_00baed47 != '\x01') goto LAB_004440b4
        if getattr(state, 'g_cancel_press_sent', 0) != 1:
            return
        # C: if (FUN_00411740() != '\x01') break
        if not _is_game_active(state):
            break
        _time.sleep(1)
        # C: ScheduledPressDispatch(param_1)
        dispatch_scheduled_press(state, _send)

    # ── Phase 2: poll until fallback GOF conditions are met ──────────────────
    # C: do { ... } while(true)
    session_start = float(getattr(state, 'g_SessionStartTime', 0.0))
    base_wait     = float(getattr(state, 'g_base_wait_time',   0.0))

    while True:
        # C: if (DAT_00baed47 != '\x01') goto LAB_004440b4
        if getattr(state, 'g_cancel_press_sent', 0) != 1:
            return

        game_ok      = _is_game_active(state)
        time_expired = check_time_limit(state)
        processing   = getattr(state, 'g_processing_active', 0) != 0
        server_ok    = _check_server_reachable(state, -1)
        now          = _time.time()
        elapsed      = now - session_start
        time_over    = elapsed > base_wait + 25.0

        # C: outer if-condition triggers inner re-check block when any fail
        outer_trigger = (
            not game_ok
            or time_expired
            or processing
            or not server_ok
            or time_over
        )

        if outer_trigger:
            # ── Inner re-check (C mirrors all conditions before sending) ─────
            if getattr(state, 'g_cancel_press_sent', 0) != 1:
                return
            if not _is_game_active(state):
                return
            if check_time_limit(state):
                return
            if getattr(state, 'g_processing_active', 0) != 0:
                return

            # C: cVar3 = FUN_004117d0(-1); if (cVar3 != '\0') { time check }
            server_ok2 = _check_server_reachable(state, -1)
            if server_ok2:
                elapsed2 = _time.time() - session_start
                if elapsed2 <= base_wait + 25.0:
                    # C: goto LAB_004440b4 — still within window, do not send
                    return

            # ── Send fallback bare GOF ────────────────────────────────────────
            # C: _DAT_00ba2860 = __time64(0) - CONCAT44(_DAT_00ba2884,_DAT_00ba2880)
            state.g_elapsed_press_time = _time.time() - session_start
            # C: FUN_00465f30(local_1c, &GOF) + AppendList + SendDM
            _send("GOF")
            _log.debug("Fallback bare GOF sent (elapsed=%.1fs)",
                       state.g_elapsed_press_time)
            # C: DAT_00baed47 = '\0'
            state.g_cancel_press_sent = 0
            return

        # C: Sleep(1000) — no trigger yet, keep polling
        _time.sleep(1)


# ── CAL_MOVE ─────────────────────────────────────────────────────────────────

def cal_move(state: InnerGameState, press_tokens: list) -> bool:
    """
    Port of CAL_MOVE (named; __thiscall).

    Dispatches a press proposal token list to the appropriate DAIDE keyword
    handler based on the leading token.  Called per inner-list entry in
    EvaluateOrderProposalsAndSendGOF; returns True (1) to trigger the GOF
    commit path.

    press_tokens: flat list of DAIDE token strings for the proposal, e.g.
        ['PCE', ...] or ['NOT', 'XDO', ...] (NOT wrapper already unwrapped
        at the C level via GetSubList/AppendList before the inner dispatch).

    C structure:
      1. GetListElement(list, &out, 0) — read first token (position 0; all
         else-branch calls also read position 0: Ghidra artifact of the
         same register being reused, not list advancement).
      2. if PCE  → FUN_00465f60(local, list) + PCE(this)
         if ALY  → FUN_00465f60(local, list) + ALY(this)
         if DMZ  → FUN_00465f60(local, list) + DMZ(this)
         if XDO  → FUN_00405090(...) + FUN_00465f60(local, list) + XDO()
         if NOT  → GetSubList(list, tmp, 1) + AppendList(list, tmp) +
                   FreeList(tmp)  [unwrap NOT(…)] then:
             if PCE → FUN_00465f60 + CANCEL(this)
             if DMZ → FUN_00465f60 + REMOVE_DMZ(this)
             if XDO → FUN_00405090 + FUN_00465f60 + NOT_XDO()
      3. FreeList(list) + SerializeOrders(…) + _free(…)
    """
    if not press_tokens:
        return False

    first = press_tokens[0]

    if first == 'PCE':
        # C: FUN_00465f60 copies list to local; PCE(this) gets that local
        return bool(_handle_pce(state, press_tokens))

    if first == 'ALY':
        return bool(_handle_aly(state, press_tokens))

    if first == 'DMZ':
        return bool(_handle_dmz(state, press_tokens))

    if first == 'XDO':
        # C: FUN_00405090 preps a target ptr; FUN_00465f60 copies list to local
        return bool(_handle_xdo(state, press_tokens))

    if first == 'NOT':
        # C: GetSubList extracts the inner parenthesised content of NOT(…),
        # AppendList flattens it back into the working list, FreeList frees the
        # temp wrapper.  Net effect: inner tokens of NOT are exposed for the
        # second-level dispatch.
        inner_tokens = press_tokens[1:]   # strip leading NOT token
        if not inner_tokens:
            return False
        inner_first = inner_tokens[0]
        if inner_first == 'PCE':
            return bool(_cancel_pce(state, inner_tokens))
        if inner_first == 'DMZ':
            return bool(_remove_dmz(state, inner_tokens))
        if inner_first == 'XDO':
            return bool(_not_xdo(state, inner_tokens))

    return False


# ── Callee stubs (all UNCHECKED — addresses unknown) ─────────────────────────

def _handle_pce(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named function PCE() at address 0x0041dc10.

    Evaluates a PCE (peace) proposal from another power.  Called from
    cal_move() when the leading press token is 'PCE'.

    tokens[0] == 'PCE'; tokens[1:] == power indices included in the proposal.

    Algorithm:
      1. For every ordered pair (power_i, power_j) of PCE powers where i != j:
           - If power_i == own_power: mark power_j as PCE-applied this turn
             (g_TurnOrderHist_Lo[power_j] = 2).
           - Compute new trust = max(1, 3 − g_StabCounter[i,j]), capped at 3
             when _g_NearEndGameFactor >= 4.0.
           - Update g_AllyTrustScore[i,j] / g_AllyTrustScore_Hi[i,j] if the
             new trust (as uint64) exceeds the current value.
      2. If any score was updated: log + BuildAllianceMsg(0x66) (recalc notice).
      3. If g_PressFlag == 1 (trust-override / press mode active):
           - Scan all 7 powers; if any power still has a pending PCE flag
             (g_TurnOrderHist_Lo == 1) or has zero trust despite having
             a DiplomacyState entry, the peace deal is not yet complete.
           - If ALL powers accepted: log, BuildAllianceMsg(0x65), restore
             g_AllyTrustScore[own,*] from g_DiplomacyStateA/B snapshot.
      4. If changed: call ComputeOrderDipFlags (FUN_004113d0) — not yet ported.

    Returns True if the trust matrix was updated (signals GOF recalculation).
    """
    import logging
    _log = logging.getLogger(__name__)

    own_power  = getattr(state, 'albert_power_idx', 0)
    num_powers = 7

    # tokens[1:] are the power indices inside PCE ( pow1 pow2 ... )
    pce_powers = [int(t) for t in tokens[1:]]
    n = len(pce_powers)

    changed = False

    # ── Double loop: all ordered pairs (i, j), i != j ────────────────────────
    for i in range(n):
        power_i = pce_powers[i]   # uVar16
        for j in range(n):
            if i == j:
                continue
            power_j = pce_powers[j]   # uVar12

            # If own power is in the pair: mark power_j as PCE-applied
            # C: if (uVar16 == uVar4) { DAT_004d53d8[uVar12*2] = 2; DAT_004d53dc[uVar12*2] = 0; }
            if power_i == own_power:
                state.g_TurnOrderHist_Lo[power_j] = 2
                state.g_TurnOrderHist_Hi[power_j] = 0

            # Compute trust: 3 − g_StabCounter[i,j] clamped to [1, 3]
            # When near-end-game (factor >= 4.0) always use 3.
            # C: uVar9 = 3; if (_g_NearEndGameFactor < 4.0) uVar9 = max(1, 3-stab)
            if state.g_NearEndGameFactor < 4.0:
                trust = 3 - int(state.g_StabCounter[power_i, power_j])
                if trust < 1:
                    trust = 1
            else:
                trust = 3

            # int64 sign-extend trust → (trust_hi, trust_lo)
            # C: iVar14 = (int)uVar9 >> 0x1f  → 0 for positive trust
            trust_hi = trust >> 31   # always 0 for trust in [1,3]

            curr_hi = int(state.g_AllyTrustScore_Hi[power_i, power_j])
            curr_lo = int(state.g_AllyTrustScore[power_i, power_j])

            # Update if (trust_hi, trust) > (curr_hi, curr_lo) as uint64.
            # C: curr_hi <= trust_hi AND (curr_hi < trust_hi OR curr_lo_uint < trust_uint)
            if curr_hi <= trust_hi and (curr_hi < trust_hi or curr_lo < trust):
                state.g_AllyTrustScore[power_i, power_j]    = trust
                state.g_AllyTrustScore_Hi[power_i, power_j] = trust_hi
                changed = True

    # ── If any score changed: log + BuildAllianceMsg(0x66) ───────────────────
    if changed:
        powers_str = ' '.join(str(p) for p in pce_powers)
        _log.debug("Recalculating: Because we have applied a peace deal %s", powers_str)
        # BuildAllianceMsg(&DAT_00bbf638, &pvStack_38, 0x66) — not yet ported

    # ── All-powers-accepted check (only when g_PressFlag == 1) ───────────────
    # C: if (DAT_00baed68 == '\x01') { ... if (bVar3) goto LAB_0041deab; ... }
    if state.g_PressFlag == 1:
        dipl_a_arr = getattr(state, 'g_DiplomacyStateA', None)
        dipl_b_arr = getattr(state, 'g_DiplomacyStateB', None)
        not_all_accepted = False
        for i in range(num_powers):
            # Condition 1: pending PCE flag (sent but not yet applied)
            # C: DAT_004d53d8[i*2] == 1 AND DAT_004d53dc[i*2] == 0
            if int(state.g_TurnOrderHist_Lo[i]) == 1 and int(state.g_TurnOrderHist_Hi[i]) == 0:
                not_all_accepted = True

            # Condition 2: own has no trust with power i despite diplomatic state
            # C: g_AllyTrustScore[own*21+i]==0 AND g_AllyTrustScore_Hi==0
            #    AND (DAT_004d5480[i*2]!=0 OR DAT_004d5484[i*2]!=0)
            t_lo = int(state.g_AllyTrustScore[own_power, i])
            t_hi = int(state.g_AllyTrustScore_Hi[own_power, i])
            dipl_a = int(dipl_a_arr[i]) if dipl_a_arr is not None else 0
            dipl_b = int(dipl_b_arr[i]) if dipl_b_arr is not None else 0
            if t_lo == 0 and t_hi == 0 and (dipl_a != 0 or dipl_b != 0):
                not_all_accepted = True

        if not not_all_accepted:
            # All powers accepted — restore trust from DiplomacyState snapshot
            _log.debug("ALL powers have accepted PCE: return to original plan")
            # BuildAllianceMsg(&DAT_00bbf638, &pvStack_38, 0x65) — not yet ported

            # C: puVar11 = &g_AllyTrustScore + uVar4*0x2a; copies DAT_004d5480/4 into it
            if dipl_a_arr is not None and dipl_b_arr is not None:
                for i in range(num_powers):
                    state.g_AllyTrustScore[own_power, i]    = int(dipl_a_arr[i])
                    state.g_AllyTrustScore_Hi[own_power, i] = int(dipl_b_arr[i])
            changed = True

    # ── If changed: ComputeOrderDipFlags (FUN_004113d0) ─────────────────────
    # C: LAB_0041deab falls through to FUN_004113d0 when cStack_52 == '\x01'
    if changed:
        # TODO: port ComputeOrderDipFlags (FUN_004113d0); skipped — not yet implemented
        pass

    return changed


def _handle_aly(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named function ALY() (decompile-verified against decompiled.txt).

    Called from cal_move() when the leading press token is 'ALY'.

    tokens layout (from CAL_MOVE pre-processing):
        tokens[0] == 'ALY'
        tokens[1..] == powers listed in ALY ( p1 p2 ... ) VSS ( v1 v2 ... )
    The raw press list still contains both the ALY sub-list and the VSS
    sub-list; we extract them via the same GetSubList(index=1) / (index=3)
    convention used in the C code.

    Algorithm (decompile §ALY, decompiled.txt lines 57–143):

      uStack_74 = own_power   (from *(param_1+8)+0x2424)
      local_58  = GetSubList(press_list, 1)  → ALY power list
      local_48  = GetSubList(press_list, 3)  → VSS power list

      For each aly_power in ALY list:
        For each vss_power in VSS list:
          if aly_power == own_power: skip            (line 83)
          idx = vss_power + aly_power * 21           (line 84)
          if g_AllyMatrix[idx] < 1:
              g_AllyMatrix[idx] = 1; changed = True  (lines 85–88)
          if g_EnemyDesired == 1 and g_AllyTrustScore_Hi[aly,vss] >= 0:
              g_AllyTrustScore[aly,vss]    = 0       (lines 89–93)
              g_AllyTrustScore_Hi[aly,vss] = 0
              g_RelationScore[aly,vss]     = 0
              changed = True
          own_idx = own_power * 21 + aly_power       (line 95)
          if trust[own→aly] == 0 (both lo and hi)
             AND enemy_flag_lo[aly] == 0
             AND enemy_flag_hi[aly] == 0:            (lines 96–97)
              build PCE(own, aly_power) and call _handle_pce()
              changed = True                         (lines 98–112)

      If changed:
        log "Recalculating: Because we have applied an ALY: (%s)"
        BuildAllianceMsg(0x66) — stub

      Returns True (\\x01) if anything was changed.

    Global mapping:
      own_power           ← *(param_1+8)+0x2424  = state.albert_power_idx
      g_AllyMatrix        ← &g_AllyMatrix[row*21+col]  (char, 21×21 flat)
      g_EnemyDesired      ← DAT_00baed5f  = state.g_StabbedFlag / g_EnemyDesired
      g_AllyTrustScore    ← &g_AllyTrustScore[idx*2]   (lo word of uint64)
      g_AllyTrustScore_Hi ← &g_AllyTrustScore_Hi[idx*2](hi word of uint64)
      g_RelationScore     ← DAT_00634e90  = state.g_RelationScore[row,col]
      g_EnemyFlag         ← DAT_004cf568/6c  = state.g_EnemyFlag[power] lo/hi

    Callee added to Unchecked: none new (BuildAllianceMsg already unchecked).
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    own_power = getattr(state, 'albert_power_idx', 0)

    # ── Extract ALY and VSS power sub-lists ──────────────────────────────────
    # C: GetSubList(&stack0x4, apuStack_68, 1) → local_58 (ALY powers)
    #    GetSubList(&stack0x4, apuStack_68, 3) → local_48 (VSS powers)
    # tokens layout after CAL_MOVE: ['ALY', aly_p1, aly_p2, ..., 'VSS', vss_p1, ...]
    # Find the VSS boundary inside the token list.
    try:
        vss_idx = tokens.index('VSS')
        aly_powers = [int(t) for t in tokens[1:vss_idx]]
        vss_powers = [int(t) for t in tokens[vss_idx + 1:]]
    except ValueError:
        # No VSS keyword — treat entire token payload as ALY powers, VSS list empty.
        aly_powers = [int(t) for t in tokens[1:]]
        vss_powers = []

    changed = False

    # ── Double loop: ALY × VSS ────────────────────────────────────────────────
    for aly_power in aly_powers:          # uVar5 / bVar2
        for vss_power in vss_powers:      # *pbVar6 (inner)

            # C line 83: if (uVar5 != uStack_74) { ... }
            if aly_power == own_power:
                continue

            # C line 84: iVar7 = (uint)*pbVar6 + uVar5 * 0x15
            # iVar7 is used as flat index into g_AllyMatrix (21-wide)
            idx = int(vss_power) + aly_power * 21    # iVar7

            # C lines 85–88: g_AllyMatrix[iVar7] < 1  → set to 1
            if int(state.g_AllyMatrix[aly_power, vss_power]) < 1:
                state.g_AllyMatrix[aly_power, vss_power] = 1
                changed = True

            # C lines 89–93: g_EnemyDesired==1 AND trust_hi[aly,vss] >= 0
            #   → zero g_AllyTrustScore, g_AllyTrustScore_Hi, g_RelationScore
            enemy_desired = int(getattr(state, 'g_StabbedFlag', 0))   # DAT_00baed5f
            trust_hi_av = int(state.g_AllyTrustScore_Hi[aly_power, vss_power])
            if enemy_desired == 1 and trust_hi_av >= 0:
                # C: (&g_AllyTrustScore)[iVar7*2] = 0; (&g_AllyTrustScore_Hi)[iVar7*2] = 0
                state.g_AllyTrustScore[aly_power, vss_power]    = 0
                state.g_AllyTrustScore_Hi[aly_power, vss_power] = 0
                # C: (&DAT_00634e90)[iVar7] = 0   — g_RelationScore
                state.g_RelationScore[aly_power, vss_power]     = 0
                changed = True

            # C line 95: iVar7 = uStack_74 * 0x15 + uVar5  (own→aly direction)
            # C lines 96–97: trust[own→aly] == 0 AND enemy flags of aly_power == 0
            trust_lo_oa = int(state.g_AllyTrustScore[own_power, aly_power])
            trust_hi_oa = int(state.g_AllyTrustScore_Hi[own_power, aly_power])

            # DAT_004cf568[uVar5*2] and DAT_004cf56c[uVar5*2]:
            # these are the lo/hi int32 words of g_EnemyFlag for aly_power
            enemy_flag = getattr(state, 'g_EnemyFlag', None)
            if enemy_flag is not None:
                ef_lo = int(enemy_flag[aly_power])
                # hi word — stored in a separate array or second element
                ef_hi_arr = getattr(state, 'g_EnemyFlag_Hi', None)
                ef_hi = int(ef_hi_arr[aly_power]) if ef_hi_arr is not None else 0
            else:
                ef_lo = ef_hi = 0

            if (trust_lo_oa == 0 and trust_hi_oa == 0
                    and ef_lo == 0 and ef_hi == 0):
                # C lines 98–112: build PCE(own, aly_power) and evaluate it
                # C: local_90[0] = token for own_power side
                #    local_8c[0] = bVar2 | 0x4100  (aly_power with DAIDE power flag)
                # In Python: synthesise tokens list for _handle_pce
                pce_tokens = ['PCE', own_power, aly_power]
                _handle_pce(state, pce_tokens)
                changed = True

    # ── Log + BuildAllianceMsg if anything changed ───────────────────────────
    if changed:
        aly_str = ' '.join(str(p) for p in aly_powers)
        _log.debug(
            "Recalculating: Because we have applied an ALY: (%s)", aly_str
        )
        # BuildAllianceMsg(&DAT_00bbf638, apuStack_68, (int*)&puStack_7c=0x66)
        # Not yet ported — stub omitted intentionally.

    return changed


def _handle_dmz(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named function DMZ() (decompile-verified against decompiled.txt).

    Called from cal_move() when the leading press token is 'DMZ'.

    C signature: char __fastcall DMZ(int param_1)
    param_1 is the press token-stream pointer (stack0x00000004 in the caller).
    Returns '\x01' (True) if the DMZ agreement was applied / any state changed.

    Token layout after CAL_MOVE preprocessing:
        tokens[0] == 'DMZ'
        tokens[1..n] == powers in the DMZ  (sublist index 1 in C)
        tokens[n+1..] == provinces in the DMZ  (sublist index 2 in C)

    Algorithm (faithful to decompile):

      own_power  = albert_power_idx  (piStack_88)
      dmz_powers = GetSubList(press, 1)  → local_74  (the DMZ power list)
      dmz_provs  = GetSubList(press, 2)  → local_48  (the DMZ province list)

      Outer double loop over dmz_powers (i, j):
        Condition: (i != j) OR len(dmz_powers) == 1.
        Inner loop over dmz_provs (province k):

          piVar4  = dmz_powers[i]   (outer power; piStack_ac saved copy)
          piVar9  = dmz_provs[k]    (the province being DMZ'd; piStack_b0)

          BRANCH A — piVar4 == own_power:
            Walk g_DmzOrderList (DAT_00bb65e4, sentinel DAT_00bb65e0).
            For each record rec:
              if rec.owner_power == own_power: skip  (*(pCVar8+0xc) == piStack_88)
              iVar10 = rec.owner_power
              iStack_34 = DAT_00bb6f2c[iVar10*3]  (province-tree record for that power)
              call GameBoard_GetPowerRec(DAT_00bb6f28+iVar10*0xc, aiStack_30, province_k)
                → check record validity (non-null, non-sentinel)
              if puVar7[1] == iStack_34:   (province k belongs to this power's territory)
                cStack_b1 = '\x01'         (DMZ accepted for this province/power)
                StdMap_FindOrInsert(owner_power_base, apvStack_18, province_k)
                  → g_ActiveDmzMap[province_k] = rec.owner_power  (record the DMZ)

          BRANCH B — piVar4 != own_power:
            iVar10 = DAT_00bb702c[piVar4*3]  (this power's province-tree record)
            puVar11 = DAT_00bb7028 + piVar4*0xc  (power-record base address)
            GameBoard_GetPowerRec(puVar11, aiStack_28, province_k)
            if puVar7[1] == iVar10:   (province k is in this power's territory)
              cStack_b1 = '\x01'
              StdMap_FindOrInsert(puVar11, &pvStack_64, province_k)
                → g_ActiveDmzMap[province_k] = piVar4
            Walk g_ActiveDmzList (DAT_00bb7134, sentinel DAT_00bb7130):
              For each rec:
                if rec[3] == piVar4 (outer power)
                   AND rec[4] != piVar9 (different province than current):
                  FUN_00412280(DAT_00bb7130, aiStack_20, (int)puVar11, rec)
                    → remove this stale DMZ entry  (erase from g_ActiveDmzList)

      If cStack_b1 == '\x01':
        FUN_0046b050(...)  (serialize DMZ token list to string — absorbed as log)
        SEND_LOG("Recalculating: Because we have applied a DMZ: (%s)")
        BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)  (stub)

      Returns cStack_b1  (True if any change, False otherwise)

    Global mapping:
      own_power       ← state.albert_power_idx
      g_DmzOrderList  ← state.g_DmzOrderList   list[dict]:
                          each entry: {'owner_power': int, 'provinces': set, 'active': bool}
      g_ActiveDmzMap  ← state.g_ActiveDmzMap    dict: {province: power} — accepted DMZ entries
      g_ActiveDmzList ← state.g_ActiveDmzList   list[dict]:
                          each entry: {'power': int, 'province': int} — active agreements
      g_ScOwner       ← state.g_ScOwner[province]  — province SC owner index
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    own_power = getattr(state, 'albert_power_idx', 0)

    # ── Extract DMZ powers (sublist 1) and DMZ provinces (sublist 2) ──────────
    # C: GetSubList(&stack4, &pvStack_64, 1) → local_74  (power list)
    #    GetSubList(&stack4, &pvStack_64, 2) → local_48  (province list)
    # tokens layout: ['DMZ', pow1, pow2, ..., prov1, prov2, ...]
    # We split on the first integer run vs a possible explicit list separator.
    # In practice CAL_MOVE passes the raw sub-token list; we extract two int groups.
    dmz_powers: list = []
    dmz_provs:  list = []
    # Simple heuristic: collect ints from tokens[1:]; power indices are small (<7),
    # province indices can be larger.  The C GetSubList(1) returns the first nested
    # parenthesised group and GetSubList(2) the second.  With flat token lists we
    # rely on the split being signalled by a non-int sentinel, or fall back to
    # "first group = powers (values < 7), second group = provinces".
    # More robust: if tokens contain explicit sentinels they were stripped by CAL_MOVE.
    # We therefore split by value: tokens < 7 are powers, ≥ 7 are provinces.
    for tok in tokens[1:]:
        try:
            v = int(tok)
        except (ValueError, TypeError):
            continue
        if v < 7:
            dmz_powers.append(v)
        else:
            dmz_provs.append(v)

    if not dmz_powers or not dmz_provs:
        return False

    # uStack_80 = FUN_00465930(local_74)  — count of dmz_powers
    # uStack_8c = FUN_00465930(local_48)  — count of dmz_provs
    n_powers = len(dmz_powers)   # uStack_80
    n_provs  = len(dmz_provs)    # uStack_8c

    # cStack_b1 — return value / changed flag
    changed = False

    # Lazy-init the two DMZ state dicts if not present on state
    if not hasattr(state, 'g_DmzOrderList'):
        state.g_DmzOrderList = []   # DAT_00bb65e0/e4: list[dict{owner_power,provinces}]
    if not hasattr(state, 'g_ActiveDmzMap'):
        state.g_ActiveDmzMap = {}   # DAT_00bb6f28/*: {province: power}
    if not hasattr(state, 'g_ActiveDmzList'):
        state.g_ActiveDmzList = []  # DAT_00bb7130/34: list[dict{power, province}]

    g_DmzOrderList: list = state.g_DmzOrderList
    g_ActiveDmzMap: dict = state.g_ActiveDmzMap
    g_ActiveDmzList: list = state.g_ActiveDmzList

    # ── Outer double loop: powers i, j ────────────────────────────────────────
    # C: if (0 < (int)uVar3) { do { ... } while (iStack_90 < (int)uVar3); }
    # Outer i (iStack_90), inner j (iStack_84):
    #   condition inner body runs: (i != j) OR (uVar3 == 1)
    for i_idx in range(n_powers):
        outer_power = dmz_powers[i_idx]  # piVar4 / piStack_ac

        for j_idx in range(n_powers):
            # C: if (((iVar10 != iVar13) || (uVar3 == 1)) && (iStack_a4 = 0, 0 < (int)uStack_8c))
            if i_idx == j_idx and n_powers != 1:
                continue

            # ── Inner k loop: each DMZ province ─────────────────────────────
            for k_idx in range(n_provs):
                province = dmz_provs[k_idx]   # piVar9 / piStack_b0

                if outer_power == own_power:
                    # ── BRANCH A: own power is in the DMZ pair ────────────────
                    # C lines 97–140: walk g_DmzOrderList (DAT_00bb65e4 .. sentinel DAT_00bb65e0)
                    # For each rec:
                    #   if rec.owner_power == own_power: skip
                    #   iVar10 = rec.owner_power
                    #   puVar7 = GameBoard_GetPowerRec(base+owner*0xc, buf, &province)
                    #   if puVar7[1] == iStack_34: → StdMap_FindOrInsert + changed
                    for rec in list(g_DmzOrderList):
                        rec_owner = int(rec.get('owner_power', -1))
                        # C: if (*(int*)(pCVar8+0xc) != piStack_88) → process; else next
                        if rec_owner == own_power:
                            # skip: the decompile skips when owner == own_power
                            # (outer block only runs the body when rec_owner != piStack_88)
                            continue
                        # GameBoard_GetPowerRec check:
                        # "does province k fall within rec_owner's territory?"
                        # In Python: check g_ScOwner for this province.
                        sc_owner = int(state.g_ScOwner[province]) if province < len(state.g_ScOwner) else -1
                        if sc_owner == rec_owner:
                            # puVar7[1] == iStack_34 → accept: cStack_b1 = '\x01'
                            changed = True
                            # StdMap_FindOrInsert: register the accepted DMZ for this province
                            # absorb as: g_ActiveDmzMap[province] = rec_owner
                            g_ActiveDmzMap[province] = rec_owner

                else:
                    # ── BRANCH B: non-own outer power ─────────────────────────
                    # C lines 143–185:
                    # puVar11 = &DAT_00bb7028 + piVar4*0xc  (outer_power's base)
                    # GameBoard_GetPowerRec check → province k in outer_power's territory?
                    sc_owner = int(state.g_ScOwner[province]) if province < len(state.g_ScOwner) else -1
                    if sc_owner == outer_power:
                        # cStack_b1 = '\x01'; StdMap_FindOrInsert → accept DMZ
                        changed = True
                        g_ActiveDmzMap[province] = outer_power

                    # ── Walk g_ActiveDmzList: remove stale entries ─────────────
                    # C lines 153–184:
                    # Walk DAT_00bb7134 list; for each rec:
                    #   if ppiVar12[3] == piStack_ac (outer_power)
                    #      AND ppiVar12[4] != piVar9 (province k was NOT this province):
                    #     FUN_00412280(DAT_00bb7130, ..., rec)  → erase from list
                    #  (restart iteration after erase matches C do-while restart)
                    restart = True
                    while restart:
                        restart = False
                        for idx, active_rec in enumerate(list(g_ActiveDmzList)):
                            rec_power   = int(active_rec.get('power', -1))
                            rec_province = int(active_rec.get('province', -1))
                            if rec_power == outer_power and rec_province != province:
                                # FUN_00412280: erase this stale DMZ entry
                                # C: ppiStack_94 = (int**)*DAT_00bb7134 after erase
                                #    (the list head is reset to the new front)
                                try:
                                    g_ActiveDmzList.remove(active_rec)
                                except ValueError:
                                    pass
                                restart = True
                                break

    # ── Post-loop: if changed, log and BuildAllianceMsg ───────────────────────
    # C lines 198–220:
    #   FUN_0046b050(...)  → serialize province list (absorbed as debug log)
    #   SEND_LOG("Recalculating: Because we have applied a DMZ: (%s)")
    #   BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)  (stub)
    if changed:
        prov_str = ' '.join(str(p) for p in dmz_provs)
        _log.debug(
            "Recalculating: Because we have applied a DMZ: (%s)", prov_str
        )
        # BuildAllianceMsg(&DAT_00bbf638, ..., 0x66) — not yet ported (stub)

    return changed


def _handle_xdo(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named function XDO() (decompile-verified against decompiled.txt).

    Called from cal_move() when the leading press token is 'XDO'.
    Preceded by FUN_00405090 prep in the caller (provides in_stack_00000018 =
    the outer candidate-proposal list, passed as the second state-based
    parameter here via state.g_xdo_candidate_list).

    Algorithm (faithful to decompile, decompiled.txt lines 2–266):

      1. Init three empty local token lists (local_40, local_2c, local_1c).
         Allocate a local proposal sentinel (local_74).
      2. GetSubList(&stack4, 1) → local_40 = XDO inner content
         (the full order triple: unit, order-type, destination).
      3. Element 0 of sublist 0 → bVar3 = sender power (byte).
         FUN_00465930(local_40) → uVar11 = element count of local_40.
         FUN_00419300(DAT_00bb65f8 + bVar3*0xc, ..., local_40)
           → register this XDO proposal into sender's proposal map
             (g_XdoProposalBySender[sender_power]).
      4. Element 2 of sublist 0 → pvStack_80 = destination/scope province.
         StdMap_FindOrInsert(DAT_00bb6bf8 + bVar3*0xc, ..., pvStack_80)
           → g_XdoDestBySender[sender_power][dest_prov] = dest_prov
         StdMap_FindOrInsert(DAT_00bb713c, ..., pvStack_80)
           → g_XdoGlobalDestMap[dest_prov] = dest_prov
      5. Element 0 of sublist 1 → sVar4 = order command token (short).
      6a. If MTO or CTO:
            Element 0 of sublist 2 → ppiStack_7c = destination province.
            Loop over g_xdo_candidate_list (in_stack_00000018):
              ScoreSupportOpp(DAT_00bb67f8 + entry.power * 0xc, buf,
                               (dest_prov, dest_prov))
      6b. If SUP:
            local_2c = GetSubList(local_40, 2)  (the supported unit sub-token)
            sublist-1 element 0 → unused (supported unit identity)
            sublist-2 element 0 → ppiVar14 = supported power
            sublist-0 of sublist-2 of local_40  element 0 → bVar3 re-read
              = province of the unit being supported (piStack_b0)
            StdMap_FindOrInsert(DAT_00bb713c, ..., ppiStack_7c)
              → g_XdoGlobalDestMap[ppiStack_7c] = ppiStack_7c
            If uVar11 == 5 (SUP MTO — 5-element XDO):
              ScoreSupportOpp(DAT_00bb69f8 + bVar3*0xc, buf,
                               (ppiVar14, ppiVar16))
              Loop over g_xdo_candidate_list:
                FUN_004193f0(DAT_00bb68f8 + entry.power*0xc, buf,
                              (dest_prov, dest_prov))
            Else (SUP HLD):
              StdMap_FindOrInsert(DAT_00bb6af8 + bVar3*0xc, ...,
                                   ppiStack_7c)
              Loop over g_xdo_candidate_list:
                FUN_004193f0(DAT_00bb68f8 + entry.power*0xc, buf,
                              (dest_prov, dest_prov))
      7. Log "Recalculating: Because we have applied a XDO: (%s)" +
         BuildAllianceMsg(0x66) stub.
      8. Clear local_74 sentinel via SerializeOrders (absorbed as no-op).
         Clear in_stack_00000018 = g_xdo_candidate_list via SerializeOrders
         + _free (absorbed as list clear).
      9. Return True (\x01).

    New global state fields:
      g_XdoProposalBySender : dict[int, list]  — DAT_00bb65f8 per-power list
      g_XdoDestBySender     : dict[int, dict]  — DAT_00bb6bf8 per-power map
      g_XdoGlobalDestMap    : dict             — DAT_00bb713c global map
      g_xdo_candidate_list  : list[dict]       — in_stack_00000018 from FUN_00405090

    Unchecked callees: ScoreSupportOpp (DAT_00bb67f8/00bb69f8 paths),
                       FUN_004193f0 (DAT_00bb68f8 path),
                       FUN_00419300 (XDO proposal registration),
                       BuildAllianceMsg (stub).
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    # ── Parse token stream ────────────────────────────────────────────────────
    # Expected layout after CAL_MOVE: ['XDO', sender_power, order_cmd, dest_prov, ...]
    # Mirrors C layer: GetSubList(press, 1) → local_40 = XDO inner content.
    # De-serialised here from the flat token list.
    if len(tokens) < 2:
        return True   # always returns 1 per decompile; just no-op if malformed

    # ──  Step 3: sender power = element 0 (byte) of sublist 0 ────────────────
    # C: GetSubList(local_40, pvStack_6c, 0) + GetListElement(puVar9, uStack_92, 0)
    #    bVar3 = *pbVar10  (byte)
    try:
        sender_power: int = int(tokens[1]) & 0xFF    # bVar3
    except (IndexError, ValueError):
        sender_power = 0

    # uVar11 = FUN_00465930(local_40) = count of token slots in local_40
    # In our flat layout the effective "count" is the number of non-keyword tokens.
    payload = tokens[1:]     # local_40 equivalent
    uVar11  = len(payload)   # C: FUN_00465930

    # FUN_00419300: register XDO proposal for the sender in g_XdoProposalBySender
    # C: FUN_00419300(&DAT_00bb65f8 + bVar3*0xc, &pvStack_50, local_40)
    if not hasattr(state, 'g_XdoProposalBySender'):
        state.g_XdoProposalBySender = {}
    state.g_XdoProposalBySender.setdefault(sender_power, []).append(list(payload))

    # ── Step 4: destination/scope province = element 2 of sublist 0 ──────────
    # C: GetSubList(local_40, pvStack_6c, 0) + GetListElement(puVar9, uStack_92, 2)
    #    pvStack_80 = (void*)(uint)*pbVar10
    try:
        dest_prov: int = int(tokens[3]) & 0xFF       # pvStack_80
    except (IndexError, ValueError):
        dest_prov = 0

    # DAT_00bb6bf8 + sender*0xc: per-sender destination map
    if not hasattr(state, 'g_XdoDestBySender'):
        state.g_XdoDestBySender = {}
    state.g_XdoDestBySender.setdefault(sender_power, {})[dest_prov] = dest_prov

    # DAT_00bb713c: global destination map
    if not hasattr(state, 'g_XdoGlobalDestMap'):
        state.g_XdoGlobalDestMap = {}
    state.g_XdoGlobalDestMap[dest_prov] = dest_prov

    # ── Step 5: order command = element 0 of sublist 1 ───────────────────────
    # C: GetSubList(local_40, pvStack_6c, 1) + GetListElement(puVar9, uStack_92, 0)
    #    sVar4 = *psVar12  (short — MTO/CTO/SUP etc.)
    try:
        order_cmd: str = str(tokens[2])   # sVar4
    except IndexError:
        order_cmd = ''

    # Candidate list provided by the caller via FUN_00405090 / in_stack_00000018.
    # Absorbed into state.g_xdo_candidate_list.
    candidate_list: list = getattr(state, 'g_xdo_candidate_list', [])

    if order_cmd in ('MTO', 'CTO'):
        # ── Step 6a: MTO / CTO branch ─────────────────────────────────────────
        # C: GetSubList(local_40, pvStack_6c, 2) + GetListElement(0)
        #    ppiStack_7c = destination province
        try:
            mto_dest: int = int(tokens[4]) & 0xFF     # ppiStack_7c
        except (IndexError, ValueError):
            mto_dest = dest_prov

        # Loop over in_stack_00000018 (candidate entries from caller):
        #   ScoreSupportOpp(&DAT_00bb67f8 + entry.power * 0xc, buf, (mto_dest, dest_prov))
        for entry in candidate_list:
            entry_power: int = int(entry.get('power', entry.get('node_power', 0)))
            _score_support_opp(
                state,
                base_offset='DAT_00bb67f8',
                power=entry_power,
                args=(mto_dest, dest_prov),
            )

    elif order_cmd == 'SUP':
        # ── Step 6b: SUP branch ───────────────────────────────────────────────
        # local_2c = GetSubList(local_40, 2)  (the supported-unit sub-token group)
        # sublist-1 element 0 → supported unit identity (unused)
        # sublist-2 element 0 → ppiVar14 = supported power
        try:
            sup_power: int = int(tokens[4]) & 0xFF    # ppiVar14
        except (IndexError, ValueError):
            sup_power = 0

        # GetSubList(local_40, pvStack_50, 2) + GetSubList(puVar9, pvStack_6c, 0)
        # GetListElement(0) → bVar3 re-read = province of supported unit (piStack_b0)
        try:
            sup_unit_prov: int = int(tokens[3]) & 0xFF   # bVar3 re-read
        except (IndexError, ValueError):
            sup_unit_prov = 0

        # StdMap_FindOrInsert(DAT_00bb713c, ..., ppiStack_7c = ppiVar14)
        state.g_XdoGlobalDestMap[sup_power] = sup_power

        if uVar11 == 5:
            # SUP MTO (5-element XDO: XDO sender cmd sup_power dest_prov)
            # ppiVar16 = element 4 of local_40 = final MTO destination
            try:
                ppiVar16: int = int(tokens[5]) & 0xFF
            except (IndexError, ValueError):
                ppiVar16 = 0

            # ScoreSupportOpp(DAT_00bb69f8 + sup_unit_prov*0xc, buf, (sup_power, ppiVar16))
            _score_support_opp(
                state,
                base_offset='DAT_00bb69f8',
                power=sup_unit_prov,
                args=(sup_power, ppiVar16),
            )

            # Loop over in_stack_00000018:
            #   FUN_004193f0(&DAT_00bb68f8 + entry.power*0xc, buf, (dest_prov, dest_prov))
            for entry in candidate_list:
                entry_power = int(entry.get('power', entry.get('node_power', 0)))
                _score_sup_attacker(
                    state,
                    base_offset='DAT_00bb68f8',
                    power=entry_power,
                    args=(dest_prov, dest_prov),
                )
        else:
            # SUP HLD
            # StdMap_FindOrInsert(DAT_00bb6af8 + sup_unit_prov*0xc, ..., ppiStack_7c = sup_power)
            if not hasattr(state, 'g_XdoSupHldMap'):
                state.g_XdoSupHldMap = {}
            state.g_XdoSupHldMap.setdefault(sup_unit_prov, {})[sup_power] = sup_power

            # Loop over in_stack_00000018:
            #   FUN_004193f0(&DAT_00bb68f8 + entry.power*0xc, buf, (dest_prov, dest_prov))
            for entry in candidate_list:
                entry_power = int(entry.get('power', entry.get('node_power', 0)))
                _score_sup_attacker(
                    state,
                    base_offset='DAT_00bb68f8',
                    power=entry_power,
                    args=(dest_prov, dest_prov),
                )

    # ── Step 7: log + BuildAllianceMsg stub ──────────────────────────────────
    _log.debug("Recalculating: Because we have applied a XDO: (%s)", ' '.join(str(t) for t in tokens[1:]))
    # BuildAllianceMsg(&DAT_00bbf638, ..., 0x66) — not yet ported (stub)

    # ── Step 8: clear candidate list (in_stack_00000018 freed by caller) ─────
    # C: SerializeOrders(local_78, ...) — clears local sentinel set (no-op)
    # C: SerializeOrders(&stack0x14, ...) + _free(in_stack_00000018)
    if hasattr(state, 'g_xdo_candidate_list'):
        state.g_xdo_candidate_list = []

    # Always returns '\x01' (True) per decompile line 265.
    return True


def _score_support_opp(state: InnerGameState,
                       base_offset: str,
                       power: int,
                       args: tuple) -> None:
    """
    Stub for ScoreSupportOpp (called from _handle_xdo MTO/CTO branch and
    SUP-MTO branch).

    C signature (inferred):
      ScoreSupportOpp(&DAT_00bb67f8 + power*0xc, &pvStack_6c, (int*)&{arg0, arg1})

    Called from _handle_xdo MTO/CTO branch as:
      ScoreSupportOpp(&DAT_00bb67f8 + entry_power*0xc, buf, (mto_dest, dest_prov))
    Called from _handle_xdo SUP-MTO branch as:
      ScoreSupportOpp(&DAT_00bb69f8 + sup_unit_prov*0xc, buf, (sup_power, ppiVar16))

    Not yet decompiled.  UNCHECKED.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _log.debug("ScoreSupportOpp STUB: base=%s power=%d args=%s",
               base_offset, power, args)


def _score_sup_attacker(state: InnerGameState,
                        base_offset: str,
                        power: int,
                        args: tuple) -> None:
    """
    Stub for FUN_004193f0 (called from _handle_xdo SUP branch loops).

    C signature (inferred):
      FUN_004193f0(&DAT_00bb68f8 + entry_power*0xc, &pvStack_6c, (int*)&{arg0, arg1})

    Not yet decompiled.  UNCHECKED.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)
    _log.debug("FUN_004193f0 STUB: base=%s power=%d args=%s",
               base_offset, power, args)


def _cancel_pce(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named export CANCEL(param_1).

    Called from CAL_MOVE's NOT-PCE branch when a NOT(PCE(...)) press is
    received, cancelling an active peace arrangement.

    Decompile walk (decompiled.txt lines 2-184):

    Setup
    -----
    - uStack_44 = own power index (param_1+8+0x2424, i.e. albert_power_idx).
    - FUN_00465f60 copies incoming press token-list into local_1c.
    - GetSubList(&token_list, &pvStack_38, 1) extracts sub-list 1
      (the PCE power set), AppendList-merges it back into token_list,
      FreeList releases the temp.
    - uVar3 = FUN_00465930(&token_list)  → count of powers in the PCE.

    First loop (lines 61-64): iterates i=0..N-1 calling GetListElement,
    populating uStack_58 (low byte = power token).  This is a read-only pass
    with no observable side-effects in Python; we model it as extracting the
    powers list.

    Main double loop (outer iStack_4c, inner iStack_50, lines 67-128):
    For each ordered pair (a = powers[i], b = powers[j]) where i ≠ j:

      idx = a * 21 + b   (flat index into trust matrices)

      Trust-zero branch (lines 79-85):
        if g_AllyTrustScore_Hi[idx*2] > 0
           OR (g_AllyTrustScore_Hi[idx*2] == 0 AND g_AllyTrustScore[idx*2] != 0):
          → g_AllyTrustScore[idx*2]    = 0
          → g_AllyTrustScore_Hi[idx*2] = 0
          → cStack_59 = '\x01'  (changed)

      Own-power branch (lines 86-122) — only when outer power a == own:
        if DAT_00bb6f30[b*3] != 0 OR DAT_00bb7030[b*3] != 0:
          → changed
        Walk & free linked list at DAT_00bb6f2c[b*3]:
          while node.isnil == 0: FUN_00401950(node[2]); node = node.next; free
          Reset sentinel links (prev=next=self) and count to 0.
        Walk & free linked list at DAT_00bb702c[b*3]:
          same pattern.

    Post loop (lines 129-167): if changed → log + BuildAllianceMsg(0x66) stub.
    Returns cStack_59.

    Python mapping of C globals:
      uStack_44              → state.albert_power_idx
      g_AllyTrustScore       → state.g_AllyTrustScore  (2-D array indexed [a, b])
      g_AllyTrustScore_Hi    → state.g_AllyTrustScore_Hi
      DAT_00bb6f2c[p*3]      → state.g_DesigListA[p]   (list of records, cleared on cancel)
      DAT_00bb6f30[p*3]      → state.g_DesigCountA[p]  (int count)
      DAT_00bb702c[p*3]      → state.g_DesigListB[p]
      DAT_00bb7030[p*3]      → state.g_DesigCountB[p]

    The C linked-list walk-and-free is absorbed as list.clear().
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    own: int = getattr(state, 'albert_power_idx', 0)

    # ── Extract PCE powers from the token list ────────────────────────────────
    # GetSubList(&token_list, ..., 1) fetches the power sub-list (index 1).
    # In Python `tokens` already contains the unwrapped list from CAL_MOVE.
    # The PCE token is: PCE ( power1 power2 … ) → tokens[1:] are power bytes.
    pce_powers: list[int] = []
    for tok in tokens[1:]:
        try:
            p = int(tok) & 0xFF
            pce_powers.append(p)
        except (TypeError, ValueError):
            pass

    uVar3: int = len(pce_powers)   # FUN_00465930 result
    if uVar3 <= 0:
        return False

    changed: bool = False          # cStack_59

    # ── Main double loop ──────────────────────────────────────────────────────
    for i, a in enumerate(pce_powers):       # iStack_4c / uStack_48
        for j, b in enumerate(pce_powers):   # iStack_50 / uVar10
            if i == j:                        # if (iVar5 != iVar11) guard
                continue

            # idx = a * 21 + b  (flat index)
            idx: int = a * 21 + b

            # Trust-zero branch (lines 79-85)
            # Condition:
            #   (&g_AllyTrustScore_Hi)[idx*2] > 0
            #   OR ((&g_AllyTrustScore_Hi)[idx*2] == 0
            #        AND (&g_AllyTrustScore)[idx*2] != 0)
            # Equivalent to: trust_hi > 0  OR  trust != 0  (when trust_hi == 0)
            try:
                t_hi = int(state.g_AllyTrustScore_Hi[a, b])
                t_lo = int(state.g_AllyTrustScore[a, b])
            except Exception:
                t_hi = 0
                t_lo = 0

            trust_nonzero = (t_hi > 0) or (t_hi == 0 and t_lo != 0)
            if trust_nonzero:
                state.g_AllyTrustScore[a, b]    = 0
                state.g_AllyTrustScore_Hi[a, b] = 0
                changed = True

            # Own-power branch (lines 86-122): a == own
            if a == own:
                # DAT_00bb6f30[b*3] and DAT_00bb7030[b*3] are count fields.
                g_DesigCountA = getattr(state, 'g_DesigCountA', {})
                g_DesigCountB = getattr(state, 'g_DesigCountB', {})
                cnt_a = int(g_DesigCountA.get(b, 0))
                cnt_b = int(g_DesigCountB.get(b, 0))

                if cnt_a != 0 or cnt_b != 0:
                    changed = True

                # Walk & free linked list A (DAT_00bb6f2c[b*3]) — lines 90-102.
                # Absorbed as list.clear(); sentinel reset (list now empty).
                g_DesigListA = getattr(state, 'g_DesigListA', {})
                if b in g_DesigListA:
                    g_DesigListA[b] = []
                else:
                    g_DesigListA[b] = []
                state.g_DesigListA = g_DesigListA

                # Reset count field A (DAT_00bb6f30[b*3] = 0) — line 100.
                g_DesigCountA[b] = 0
                state.g_DesigCountA = g_DesigCountA

                # Walk & free linked list B (DAT_00bb702c[b*3]) — lines 103-122.
                g_DesigListB = getattr(state, 'g_DesigListB', {})
                if b in g_DesigListB:
                    g_DesigListB[b] = []
                else:
                    g_DesigListB[b] = []
                state.g_DesigListB = g_DesigListB

                # Reset count field B (DAT_00bb7030[b*3] = 0) — line 120.
                g_DesigCountB[b] = 0
                state.g_DesigCountB = g_DesigCountB

    # ── Post-loop: log if changed ─────────────────────────────────────────────
    if changed:
        # FUN_0046b050 — string serializer for the token-list (absorbed as debug log).
        # SEND_LOG(..., L"Recalculating: Because we are CANCELLING: (%s)")
        _log.debug(
            "Recalculating: Because we are CANCELLING: (%s)",
            ' '.join(str(p) for p in pce_powers),
        )
        # BuildAllianceMsg(&DAT_00bbf638, ..., 0x66) — stub
        # (BuildAllianceMsg is unchecked; no Python port yet)

    return changed


def _remove_dmz(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named export REMOVE_DMZ(param_1) — decompile-verified.

    Called from cal_move()'s NOT-DMZ branch when a NOT(DMZ(...)) press is
    received, signalling that a previous DMZ arrangement is being revoked.

    Decompile walk (decompiled.txt lines 2-182):

    Setup
    -----
    - uStack_74 = own power index  (param_1+8+0x2424 = albert_power_idx)
    - local_60  = GetSubList(press, 1)  → DMZ power-list
    - local_34  = GetSubList(press, 2)  → DMZ province-list
    - uVar6   = FUN_00465930(local_60)  → n_powers
    - uStack_84 = FUN_00465930(local_34) → n_provs

    Triple loop (lines 78-134):
      outer i (iStack_7c):  0 .. n_powers-1
        outer_power = GetListElement(local_60, i) → uStack_88 / uVar13
      inner j (iStack_78):  0 .. n_powers-1
        j_power = GetListElement(local_60, j) → uStack_6c
        condition: (j != i) OR (n_powers == 1)
          inner k (iStack_94): 0 .. n_provs-1
            province = GetListElement(local_34, k) → uStack_80

            BRANCH A (uVar13 == uStack_74, i.e. outer_power == own):
              this = &DAT_00bb6f28 + uVar3 * 0xc
                     (uVar3 = uStack_6c = j_power)
              puVar8 = GameBoard_GetPowerRec(this, aiStack_14, &province)
              puVar14 = *puVar8          (lower-bound node)
              ppiVar12 = puVar8[1]       (found iterator)
              ppiVar2 = &DAT_00bb6f2c[uVar3 * 3]  (DesigListA head for j_power)
              if ppiVar12 != ppiVar2:
                FUN_00402b70(this, &apvStack_24, puVar14, ppiVar12)
                cStack_95 = '\\x01'   (changed)

            BRANCH B (outer_power != own):
              this = &DAT_00bb7028 + uVar13 * 0xc
                     (uVar13 = outer_power)
              puVar8 = GameBoard_GetPowerRec(this, aiStack_1c, &province)
              ppiVar2 = &DAT_00bb702c[uVar13 * 3]  (DesigListB head for outer_power)
              if ppiVar12 != ppiVar2:
                FUN_00402b70(this, &pvStack_50, puVar14, ppiVar12)
                cStack_95 = '\\x01'   (changed)

    Post-loop (lines 135-163):
      if changed:
        FUN_0046b050 → log "Recalculating: Because we removed a DMZ: %s"
        BuildAllianceMsg(0x66) — stub

    Python mapping:
      uStack_74            → state.albert_power_idx
      DAT_00bb6f28[p*0xc]  → designation map for p (BRANCH A — own side)
      DAT_00bb6f2c[p*3]    → g_DesigListA[p]  (sentinel/head pointer)
      ppiVar12 != ppiVar2  → province is in g_DesigListA[p] (non-empty find)
      DAT_00bb7028[p*0xc]  → designation map for p (BRANCH B — sender side)
      DAT_00bb702c[p*3]    → g_DesigListB[p]
      FUN_00402b70         → std::map::insert / _Copy — absorbed as list membership

    FUN_0047a948 (AssertFail) is called when the GameBoard_GetPowerRec
    sanity-check fails (puVar14 == 0 or puVar14 != this); absorbed as
    a silent continue in Python (the iterator is invalid, so we skip).

    Callees absorbed:
      FUN_00465870 ✓ (list init — Python list literals)
      GetSubList ✓ (absorbed into token parsing)
      AppendList ✓ (absorbed)
      FreeList   ✓ (absorbed)
      FUN_00465930 ✓ (len())
      GetListElement ✓ (absorbed into indexed list access)
      GameBoard_GetPowerRec  → g_ScOwner membership check (absorbed)
      FUN_00402b70           → absorbed as `province in g_DesigListA/B[p]`
      FUN_0047a948 (AssertFail) → absorbed as silent skip
      FUN_0046b050 ✓ (absorbed as debug log)
      BuildAllianceMsg   → stub (unchecked)
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    own: int = getattr(state, 'albert_power_idx', 0)

    # ── Parse token stream ────────────────────────────────────────────────────
    # GetSubList(press, 1) → power list  (local_60)
    # GetSubList(press, 2) → province list (local_34)
    # In Python, `tokens` is the flat unwrapped list from cal_move().
    # Layout after CAL_MOVE strips the leading 'DMZ': [pow1 pow2 … prov1 prov2 …]
    # We split the same way as _handle_dmz: values < 7 are power indices,
    # values >= 7 are province indices.
    dmz_powers: list[int] = []
    dmz_provs:  list[int] = []
    for tok in tokens[1:]:
        try:
            v = int(tok)
        except (ValueError, TypeError):
            continue
        if v < 7:
            dmz_powers.append(v)
        else:
            dmz_provs.append(v)

    n_powers: int = len(dmz_powers)   # uVar6
    n_provs:  int = len(dmz_provs)    # uStack_84

    if n_powers == 0 or n_provs == 0:
        return False

    # Lazy-init designation-list state (same fields used by _cancel_pce).
    g_DesigListA: dict = getattr(state, 'g_DesigListA', {})
    g_DesigListB: dict = getattr(state, 'g_DesigListB', {})

    changed: bool = False   # cStack_95

    # ── Triple loop ───────────────────────────────────────────────────────────
    for i_idx in range(n_powers):                  # iStack_7c
        outer_power = dmz_powers[i_idx]            # uStack_88 / uVar13

        for j_idx in range(n_powers):              # iStack_78
            j_power = dmz_powers[j_idx]            # uStack_6c

            # Condition: (j != i) OR (n_powers == 1)
            # C: if (((iVar11 != iVar10) || (uVar6 == 1)) && (iStack_94 = 0, 0 < (int)uStack_84))
            if i_idx == j_idx and n_powers != 1:
                continue

            for k_idx in range(n_provs):           # iStack_94
                province = dmz_provs[k_idx]        # uStack_80

                if outer_power == own:
                    # ── BRANCH A: outer power is own ──────────────────────────
                    # C: this = &DAT_00bb6f28 + uVar3 * 0xc  (j_power = uVar3 = uStack_6c)
                    # GameBoard_GetPowerRec(this, aiStack_14, &province)
                    #   → puVar8[1] = iterator into j_power's designation map
                    # ppiVar2 = &DAT_00bb6f2c[uVar3 * 3]  (DesigListA sentinel)
                    # if (ppiVar12 != ppiVar2) → found → FUN_00402b70 → changed
                    #
                    # Python absorption: "province is in j_power's designation list"
                    desig_a: list = g_DesigListA.get(j_power, [])
                    if province in desig_a:
                        # FUN_00402b70 — inserts a copy into local stack slot
                        # (side-effect on the local buffer irrelevant in Python)
                        changed = True

                else:
                    # ── BRANCH B: non-own outer power ─────────────────────────
                    # C: this = &DAT_00bb7028 + uVar13 * 0xc  (outer_power = uVar13)
                    # GameBoard_GetPowerRec(this, aiStack_1c, &province)
                    # ppiVar2 = &DAT_00bb702c[uVar13 * 3]  (DesigListB sentinel)
                    # if (ppiVar12 != ppiVar2) → found → FUN_00402b70 → changed
                    desig_b: list = g_DesigListB.get(outer_power, [])
                    if province in desig_b:
                        changed = True

    # ── Post-loop: log if changed ─────────────────────────────────────────────
    # C lines 135-163:
    #   FUN_0046b050(press, &pvStack_50) → string of token list
    #   SEND_LOG(&iStack_8c, L"Recalculating: Because we removed a DMZ: %s")
    #   uStack_74 = 0x66; BuildAllianceMsg(&DAT_00bbf638, ..., &uStack_74)
    if changed:
        prov_str = ' '.join(str(p) for p in dmz_provs)
        _log.debug(
            "Recalculating: Because we removed a DMZ: (%s)", prov_str
        )
        # BuildAllianceMsg(&DAT_00bbf638, ..., 0x66) — stub (unchecked)

    return changed


def _not_xdo(state: "InnerGameState", tokens: list) -> bool:
    """
    Port of named function NOT_XDO(void) — decompile-verified against decompiled.txt.

    Called from cal_move()'s NOT-XDO branch when a NOT(XDO(...)) press is
    received, cancelling a previously submitted XDO order proposal.

    Decompile walk (decompiled.txt lines 2-115):

    Setup / token extraction
    ------------------------
    - FUN_00465870(local_1c)         — init empty local token list.
    - GetSubList(&stack4, &pvStack_38, 1)
        → extract sub-list at index 1 from the incoming XDO press
          (the inner XDO order content: unit, order-cmd, dest, …).
    - AppendList(local_1c, ppvVar8)  — merge into local_1c.
    - FreeList(&pvStack_38)          — release temp.
    - GetSubList(local_1c, &pvStack_38, 0)
        → this = first sub-element of local_1c (the order content group).
    - GetListElement(this, &uStack_46, 0)
        → uStack_46 (low byte) = element 0 of that group.
          In practice this is the sender/unit province byte; used in
          the TreeIterator_Advance sentinel check but NOT stored separately.
    - FreeList(&pvStack_38).

    Registration loop (lines 56-72)
    ---------------------------------
    - pCStack_3c = *in_stack_00000018   (head of outer candidate list)
    - puStack_40 = &stack0x00000014     (iterator = current node)
    - while pCVar1 != in_stack_00000018 (not sentinel):
        FUN_00419300(
            &DAT_00bb66f8 + *(pCVar1+0xc) * 0xc,  — per-power NOT-XDO list
            &pvStack_38,
            local_1c                               — the extracted XDO content
        )
        TreeIterator_Advance(&puStack_40)

    Python absorption:
      in_stack_00000018 = state.g_xdo_candidate_list  (set by FUN_00405090 in caller)
      *(pCVar1+0xc)     = entry['power'] (power index from candidate node)
      DAT_00bb66f8 + p*0xc → state.g_NotXdoListBySender[power]  (new field)
      FUN_00419300(…, local_1c) → append extracted XDO content to that list

    Post-loop cleanup (lines 73-114)
    -----------------------------------
    - FUN_0046b050 → serialize press token list to string (absorbed as debug log arg).
    - SEND_LOG("Recalculating: Because we have applied a NOT XDO: (%s)")
    - BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)  — stub (unchecked).
    - FreeList(local_1c)
    - FreeList(&stack4)
    - SerializeOrders + _free(in_stack_00000018) → clear g_xdo_candidate_list.
    - Returns CONCAT31(..., 1) → True always.

    New state field:
      g_NotXdoListBySender : dict[int, list]  — DAT_00bb66f8 per-power list.
        Keyed by power index; each value is a list of extracted XDO content lists
        representing orders that the peer is retracting.

    Unchecked callees (retained as stubs/absorbed):
      FUN_00419300           — absorbed as list append
      BuildAllianceMsg       — unchecked stub
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    # ── Step 1: extract XDO inner content (GetSubList index 1) ───────────────
    # C: GetSubList(&stack4, &pvStack_38, 1)  → sub-list at index 1 of the
    #    incoming press (the XDO order content group).
    # In Python `tokens` is the flat unwrapped NOT-XDO list from cal_move().
    # Layout: ['XDO', sender_power, order_cmd, dest, ...]
    # We treat tokens[1:] as the XDO inner content (local_1c equivalent).
    xdo_content: list = list(tokens[1:]) if len(tokens) > 1 else []

    # ── Step 2: registration loop over in_stack_00000018 ─────────────────────
    # C: pCStack_3c = *in_stack_00000018 (head); puStack_40 = &stack0x14 (iter)
    # while pCVar1 != in_stack_00000018 (sentinel):
    #     FUN_00419300(&DAT_00bb66f8 + *(pCVar1+0xc)*0xc, &pvStack_38, local_1c)
    #     TreeIterator_Advance(&puStack_40)
    #
    # Absorbed: iterate g_xdo_candidate_list; for each entry append xdo_content
    # into g_NotXdoListBySender[entry['power']].
    candidate_list: list = getattr(state, 'g_xdo_candidate_list', [])

    if not hasattr(state, 'g_NotXdoListBySender'):
        state.g_NotXdoListBySender = {}

    for entry in candidate_list:
        power: int = int(entry.get('power', entry.get('node_power', 0)))
        # FUN_00419300(&DAT_00bb66f8 + power*0xc, &pvStack_38, local_1c)
        # → appends local_1c (XDO content) into the per-power NOT-XDO list.
        state.g_NotXdoListBySender.setdefault(power, []).append(list(xdo_content))

    # ── Post-loop: log + BuildAllianceMsg stub ────────────────────────────────
    # C: FUN_0046b050 → serialize token list → SEND_LOG("... NOT XDO: (%s)")
    _log.debug(
        "Recalculating: Because we have applied a NOT XDO: (%s)",
        ' '.join(str(t) for t in tokens[1:]),
    )
    # BuildAllianceMsg(&DAT_00bbf638, ..., 0x66) — stub (unchecked)

    # ── Cleanup: clear candidate list (SerializeOrders + _free) ──────────────
    # C: SerializeOrders(&stack14,...) + _free(in_stack_00000018)
    if hasattr(state, 'g_xdo_candidate_list'):
        state.g_xdo_candidate_list = []

    # Always returns '\x01' (True) per decompile line 114.
    return True
