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


def _execute_aly_vss(state: InnerGameState, power: int) -> bool:
    """
    Stub for FUN_004325a0(this, param_1).
    Called when ALY and VSS entries are both present in the press history.
    Executes the ALY/VSS response action.
    Returns True if an action was taken.
    UNCHECKED — FUN_004325a0 not yet verified.
    """
    return False


def _execute_xdo(state: InnerGameState, power: int) -> None:
    """
    Stub for FUN_00433510(this, param_1).
    Executes the XDO (cross-diplomacy order) action for the given power.
    UNCHECKED — FUN_00433510 not yet verified.
    """
    pass


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
    Stub for FUN_00411740 (unchecked).

    Returns '\x01' in C when game is still running / our turn is active.
    """
    return bool(getattr(state, 'g_game_active', True))


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
        return bool(_handle_xdo(press_tokens))

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
            return bool(_not_xdo(inner_tokens))

    return False


# ── Callee stubs (all UNCHECKED — addresses unknown) ─────────────────────────

def _handle_pce(state: InnerGameState, tokens: list) -> bool:
    """Stub for named function PCE(). Evaluates a PCE (peace) proposal."""
    return False  # STUB


def _handle_aly(state: InnerGameState, tokens: list) -> bool:
    """Stub for named function ALY(). Evaluates an ALY (alliance) proposal."""
    return False  # STUB


def _handle_dmz(state: InnerGameState, tokens: list) -> bool:
    """Stub for named function DMZ(). Evaluates a DMZ proposal."""
    return False  # STUB


def _handle_xdo(tokens: list) -> bool:
    """Stub for named function XDO(). Evaluates an order in an XDO wrapper."""
    return False  # STUB


def _cancel_pce(state: InnerGameState, tokens: list) -> bool:
    """Stub for named function CANCEL(). Cancels an active PCE arrangement."""
    return False  # STUB


def _remove_dmz(state: InnerGameState, tokens: list) -> bool:
    """Stub for named function REMOVE_DMZ(). Removes a DMZ arrangement."""
    return False  # STUB


def _not_xdo(tokens: list) -> bool:
    """Stub for named function NOT_XDO(). Cancels a previously submitted order."""
    return False  # STUB
