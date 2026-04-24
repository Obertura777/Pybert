"""Small scoring primitives used throughout heuristics.

Split from heuristics.py during the 2026-04 refactor.

- ``evaluate_province_score`` — EvaluateProvinceScore (FUN_00433ce0)
- ``compute_winter_builds``   — ComputeWinterBuilds (FUN_00445be0)
- ``_safe_pow``                — pow with base<=0 guard (FUN_0047b370 proxy)
- ``evaluate_alliance_score`` — EvaluateAllianceScore (FUN_0043bd20)

These are leaf primitives — they depend only on ``numpy`` and
``InnerGameState``.  ``_safe_pow`` is re-imported by sibling modules
(``influence``) that need the base<=0 guard.
"""

import numpy as np

from ..state import InnerGameState

def evaluate_province_score(state: InnerGameState, province_id: int, power_id: int) -> int:
    """
    Port of FUN_00433ce0 / EvaluateProvinceScore.
    
    A granular scoring heuristic to evaluate the strategic desirability of acquiring 
    or holding a specific province for a given power. It acts as an input scalar to 
    the Monte Carlo system.
    """
    max_threatening_adj_scs = state.get_max_threatening_adj_scs(province_id, power_id)
    turn_counter = state.g_NearEndGameFactor
    score = 0
    
    if max_threatening_adj_scs == 0:
        convoy_reach = state.g_ConvoyReachCount[power_id, province_id]
        if convoy_reach > 0:
            own_reach = state.g_OwnReachScore[power_id, province_id]
            if own_reach == 0:
                score = 50 if turn_counter <= 6.0 else 100
            else:
                score = 2 if turn_counter <= 6.0 else 15
        else:
            score = 0
    else:
        win_threshold = state.win_threshold 
        pct = (max_threatening_adj_scs * 100) // win_threshold
        
        if pct > 50:
            total_reach = state.g_TotalReachScore[power_id, province_id]
            own_reach = state.g_OwnReachScore[power_id, province_id]
            
            if (total_reach + 1) <= own_reach:
                score = ((pct - 50) * 150) // 100 + 50
            else:
                score = 50
        else:
            score = 50

    if state.g_UniformMode == 1 and state.g_NearEndGameFactor < 3.0:
        if score == 0 and state.g_EnemyMobilityCount[power_id, province_id] > 0:
            score = 2
            
    return score


def compute_winter_builds(state: InnerGameState, build_candidate_list, own_power: int):
    """
    Port of FUN_00445be0 / ComputeWinterBuilds.
    Scores winter build-order candidates.
    """
    for province_id, sub_list in build_candidate_list.items():
        local_4c = 0.0  # position score A — own unit fitness
        local_48 = 0.0  # position score B — ally unit fitness
        
        unit_coast = 0
        
        for order in sub_list:
            target = order.target_province
            order_score = min(order.score, 30.0)
            if order_score <= 0.001:
                order_score = 0.001
            
            if target != province_id:
                local_4c += 10000.0 / order_score
            
            if state.g_SCOwnership[own_power, target] == 1:
                if getattr(order, 'coast', None) == unit_coast:
                    local_4c += 10000.0 / order_score
                    
            if getattr(state, 'g_FriendlyUnitFlag', np.zeros(256))[target] == 1 or getattr(state, 'g_EstablishedAllyFlag', np.zeros(256))[target] == 1:
                if getattr(order, 'coast', None) == unit_coast:
                    ally = getattr(order, 'power', -1)
                    trust = getattr(order, 'trust', 0)
                    if (ally == own_power) or (trust < 3 and getattr(state, 'g_EstablishedAllyFlag', np.zeros(256))[target] == 1):
                        local_48 += 10000.0 / order_score
                        
        state.g_WinterScore_A[province_id] = local_4c
        state.g_WinterScore_B[province_id] = local_48


def _safe_pow(base: float, exp: float) -> float:
    """FUN_0047b370 proxy. Returns base**exp; returns 0.0 if base <= 0."""
    if base <= 0.0:
        return 0.0
    return base ** exp


def evaluate_alliance_score(state: InnerGameState, own_power: int) -> None:
    """
    Port of EvaluateAllianceScore (FUN_0043bd20).

    Builds per-power desirability scores using trust, enemy reach, SC balance,
    and attack history.  Writes state.g_AllianceDesirability[power].

    Final formula (from research.md §2543 note):
      enemies: (2000 - enemy_score) × weight
      allies:  (ally_score - 2000)  × weight

    Result is stored in state.g_AllianceDesirability[power].
    """
    num_powers = 7
    state.g_AllianceDesirability.fill(0.0)

    own_sc = int(state.sc_count[own_power])

    for power in range(num_powers):
        if power == own_power:
            continue

        trust    = float(state.g_AllyTrustScore[own_power, power])
        enemy_r  = float(np.sum(state.g_EnemyReachScore[own_power]))
        ally_r   = float(np.sum(state.g_AllyReachScore[own_power]))
        atk_hist = float(np.sum(state.g_AttackHistory[own_power]))
        sc_diff  = float(state.sc_count[power] - own_sc)
        influence = float(state.g_InfluenceMatrix[own_power, power])

        # Weight = SC-balance influence factor
        weight = max(0.5, min(2.0, (influence + 1.0) / 50.0))

        if state.g_EnemyFlag[power]:
            # Enemy: score decreases with enemy reach and attack history
            enemy_score = min(2000.0, enemy_r * 100.0 + atk_hist * 50.0 + sc_diff * 20.0)
            desirability = (2000.0 - enemy_score) * weight
        else:
            # Ally: score increases with alliance trust and SC synergy
            ally_score = min(2000.0, trust * 200.0 + ally_r * 50.0 - sc_diff * 10.0)
            desirability = (ally_score - 2000.0) * weight

        state.g_AllianceDesirability[power] = desirability
