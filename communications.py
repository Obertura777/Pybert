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


def _execute_then_action(state: InnerGameState, power: int) -> None:
    """
    Port of ExecuteThennAction (FUN_00439c30).
    Executes the THN (Then) conditional press action for the given power.
    """
    history = getattr(state, 'g_HistoryCounter', 0)
    trust_hi = int(state.g_AllyTrustScore_Hi[state.albert_power_idx, power])
    trust_lo = int(state.g_AllyTrustScore[state.albert_power_idx, power])
    
    # Needs valid trust (trust_hi >= 0 or trust_hi < 1 and trust_lo >= 3)
    has_trust = trust_hi >= 0 or (trust_hi < 1 and trust_lo >= 3)
    if not has_trust:
        return

    # Defer complex nested logic to individual DMZ, XDO handler helpers
    # which mirror the logic evaluated by the FUN_00401050 / VSS calls
    if history > 9:
        if propose_dmz(state, power):
            return 
    
    if history >= 20:
        # XDO handling would be executed via proposing cross-unit operations
        pass


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

    Three phases (research.md §4364):
      Phase 1 — update g_RelationScore for each (row, col) power pair
      Phase 2 — UpdateRelationHistory (FUN_0040d7e0, simplified)
      Phase 3 — upgrade/downgrade g_AllyMatrix based on trust thresholds
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    num_powers = 7
    season = getattr(state, 'g_season', 'SPR')
    season_rewards = season in ('FAL', 'WIN')   # relation gain only in FAL/WIN

    # Phase 1 — per-power-pair relationship score update
    for row in range(num_powers):
        for col in range(num_powers):
            if row == col:
                continue

            # Eliminated power: zero out all trust/relation for that slot
            if int(state.sc_count[col]) == 0:
                state.g_AllyTrustScore[row, col]    = 0
                state.g_AllyTrustScore_Hi[row, col] = 0
                state.g_TrustExtended_Lo[row, col]  = 0
                state.g_TrustExtended_Hi[row, col]  = 0
                state.g_RelationScore[row, col]      = 0
                state.g_AllyMatrix[row, col]         = 0
                continue

            stab      = int(state.g_StabFlag[row, col])
            cease     = int(state.g_CeaseFire[row, col])
            coop      = int(state.g_CoopFlag[row, col])
            trust_lo  = int(state.g_AllyTrustScore[row, col])
            trust_hi  = int(state.g_AllyTrustScore_Hi[row, col])
            peace_sig = int(state.g_PeaceSignal[row, col])
            relation  = int(state.g_RelationScore[row, col])

            if stab == 1:
                # Stab penalty: −10, −20, −30, … capped at −50
                penalty = state.g_StabCounter[row, col] * (-10) - 10
                relation += int(penalty)
                if relation < -50:
                    relation = -50
                state.g_RelationScore[row, col] = relation
                state.g_StabCounter[row, col]   += 1
                _log.debug("FRIENDLY: stab penalty %d→%d for (%d,%d)", penalty, relation, row, col)

            elif cease == 1:
                # Cease-fire: cap relation at 0
                if relation > 0:
                    state.g_RelationScore[row, col] = 0

            elif stab == 0 and cease == 0 and coop == 0 and season_rewards:
                # Normal relationship update (FAL/WIN only)
                no_alliance = (trust_hi < 0) or (trust_hi < 1 and trust_lo == 0)
                if no_alliance:
                    if peace_sig == 1 and relation < 50:
                        relation += 5
                        state.g_RelationScore[row, col] = relation
                    elif trust_lo > 0 and peace_sig == 0:
                        state.g_RelationScore[row, col] = 1
                        state.g_AllyTrustScore_Hi[row, col] = 0
                    elif trust_lo == 0 and trust_hi == 0 and relation < 0:
                        relation += 10
                        if relation > 0:
                            relation = 0
                        state.g_RelationScore[row, col] = relation
                else:
                    # Alliance confirmed — accumulate relation
                    gain = 5 if state.g_DeceitLevel == 1 else 10
                    relation = min(relation + gain, 50)
                    state.g_RelationScore[row, col] = relation

    # Phase 2 — UpdateRelationHistory (FUN_0040d7e0)
    # Enforces a safe_pow-derived minimum floor on positive g_AllyTrustScore.
    for row in range(num_powers):
        for col in range(num_powers):
            if row == col:
                continue
            current_trust = float(state.g_AllyTrustScore[row, col])
            if current_trust > 0:
                # _safe_pow: ST1=1.8 (DAT_004afa10), ST0=trust_lo/10 (integer divide).
                # floor = FloatToInt64(pow(1.8, trust_lo / 10))
                trust_lo = int(state.g_AllyTrustScore[row, col])
                floor_val = float(int(1.8 ** (trust_lo // 10)))
                if current_trust < floor_val:
                    state.g_AllyTrustScore[row, col] = floor_val

    # Phase 3 — g_AllyMatrix alliance state transitions
    # trust_hi ≥ 5 → upgrade tentative (1) → full (2)
    # trust_hi < 0 OR (trust_hi < 1 AND trust_lo < 5) → downgrade full (2) → tentative (1)
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
