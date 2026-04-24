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
    turn_counter = state.g_near_end_game_factor
    score = 0
    
    if max_threatening_adj_scs == 0:
        convoy_reach = state.g_convoy_reach_count[power_id, province_id]
        if convoy_reach > 0:
            own_reach = state.g_own_reach_score[power_id, province_id]
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
            total_reach = state.g_total_reach_score[power_id, province_id]
            own_reach = state.g_own_reach_score[power_id, province_id]
            
            if (total_reach + 1) <= own_reach:
                score = ((pct - 50) * 150) // 100 + 50
            else:
                score = 50
        else:
            score = 50

    if state.g_uniform_mode == 1 and state.g_near_end_game_factor < 3.0:
        if score == 0 and state.g_enemy_mobility_count[power_id, province_id] > 0:
            score = 2
            
    return score


def compute_winter_builds(state: InnerGameState, build_candidate_list, own_power: int):
    """
    Port of FUN_00445be0 / ComputeWinterBuilds.
    Scores winter build-order candidates.

    C algorithm:
      For each province_id (outer tree iterator on g_BuildCandidateList):
        Read unit descriptor at province_id:
          uVar2 = *(ushort*)(gamestate + province_id * 0x24 + 0x20)
          high byte = unit type char ('A' → local_3c = coast_lo, else local_3c = 0x14)
          Armies use the low byte (coast index) for comparisons;
          Fleets use sentinel 0x14 (never matches any real coast).

        For each order in the province's sub-list (inner tree walk):
          order_score = min(*(double*)(iVar6 + 0x20), 30.0)  — capped to 30.0

          Section 1 (iVar3 != local_c): target != province_id
            local_4c += 10000.0 / order_score

          Section 2 (g_SCOwnership check):
            if g_SCOwnership[own_power, target] == 1:
              UnitList_FindOrInsert → get unit record at target
              if order.coast_short == unit_record.coast_short:
                local_4c += 10000.0 / order_score

          Section 3 (g_friendly_unit_flag / g_established_ally_flag):
            if friendly_flag[target] == 1 OR established_ally_flag[target] == 1:
              → jump to LAB_00445f2e
            elif g_stab_flag[target] == 1 OR g_retreat_flag[target] == 1:
              → jump to LAB_00445f2e  (same ally-unit-bonus path)
            else: skip

            LAB_00445f2e:
              UnitList_FindOrInsert → get unit record at target
              if order.coast_short == unit_record.coast_short:
                if (unit_record.power == local_3c) OR
                   (local_3c == 0x14 AND unit_record.power != own_power):
                  local_48 += 10000.0 / order_score

                if local_3c == own_power:
                  if NOT (stab_flag[target] == 1 OR retreat_flag[target] == 1):
                    if NOT (g_friendly_unit_flag[target] == 1 OR g_established_ally_flag[target] == 1):
                      → skip trust check
                  ally_idx = own_power * 21 + unit_record.power
                  if trust_hi[ally_idx] < 1 AND (trust_hi < 0 OR trust_lo < 3):
                    local_48 += 10000.0 / order_score

    Fix 2026-04-21 (H-1): Previously read non-existent order.coast attribute.
    Now extracts unit type from state.unit_info and uses coast comparison from
    order.target_coast vs unit record's coast (matching C's *(short*)(iVar6+0x14)
    == *(short*)(ppiVar10+1) pattern).
    """
    for province_id, sub_list in build_candidate_list.items():
        local_4c = 0.0  # position score A — own unit fitness
        local_48 = 0.0  # position score B — ally unit fitness

        # C: uVar2 = *(ushort*)(gamestate + province_id * 0x24 + 0x20)
        # high byte = type char; low byte = coast index.
        # If type == 'A': local_3c = coast_lo (the army's province coast).
        # Else (FLT): local_3c = 0x14 (sentinel — never matches a real power).
        unit_at_prov = state.unit_info.get(province_id)
        if unit_at_prov is not None and unit_at_prov.get('type', 'A') == 'A':
            local_3c = unit_at_prov.get('coast', 0)   # army coast index
        else:
            local_3c = 0x14  # fleet sentinel

        for order in sub_list:
            target = order.target_province
            order_score = min(order.score, 30.0)
            if order_score <= 0.001:
                order_score = 0.001

            # Section 1: target != province_id
            # C: if (iVar3 != local_c) → local_4c += 10000.0 / fVar12
            if target != province_id:
                local_4c += 10000.0 / order_score

            # Section 2: g_SCOwnership[own_power, target] == 1
            # C: UnitList_FindOrInsert → compare coast shorts
            iVar11 = own_power * 0x100
            if int(state.g_sc_ownership[own_power, target]) == 1:
                target_unit = state.unit_info.get(target)
                order_coast = getattr(order, 'target_coast', getattr(order, 'coast', 0)) or 0
                unit_coast = target_unit.get('coast', 0) if target_unit else -1
                if order_coast == unit_coast:
                    local_4c += 10000.0 / order_score

            # Section 3: friendly/ally unit bonus (local_48)
            # C checks 4 flag arrays; any hit → LAB_00445f2e
            # Updated 2026-04-21: g_friendly_unit_flag and g_established_ally_flag
            # are now 2D [outer_power, prov]; index via own_power.
            f_flag = getattr(state, 'g_friendly_unit_flag', np.zeros((7, 256)))
            e_flag = getattr(state, 'g_established_ally_flag', np.zeros((7, 256)))
            if f_flag.ndim == 2:
                friendly_flag = int(f_flag[own_power, target])
                ally_flag = int(e_flag[own_power, target])
            else:
                # Fallback for 1D (shouldn't happen after this fix)
                friendly_flag = int(f_flag[target]) if f_flag.ndim == 1 else 0
                ally_flag = int(e_flag[target]) if e_flag.ndim == 1 else 0
            stab_flag = int(getattr(state, 'g_stab_unit_flag', np.zeros(256))[target])
            retreat_flag = int(getattr(state, 'g_retreat_unit_flag', np.zeros(256))[target])

            enter_ally_bonus = (friendly_flag == 1 or ally_flag == 1 or
                                stab_flag == 1 or retreat_flag == 1)
            if enter_ally_bonus:
                # LAB_00445f2e: UnitList_FindOrInsert → compare coast shorts
                target_unit = state.unit_info.get(target)
                order_coast = getattr(order, 'target_coast', getattr(order, 'coast', 0)) or 0
                unit_coast = target_unit.get('coast', 0) if target_unit else -1
                if order_coast == unit_coast:
                    # C: if (ppiVar10[2] == local_3c) OR
                    #       (local_3c == 0x14 AND ppiVar10[2] != piVar5)
                    unit_power = target_unit.get('power', -1) if target_unit else -1
                    if (unit_power == local_3c) or (local_3c == 0x14 and unit_power != own_power):
                        local_48 += 10000.0 / order_score

                    # C: if (local_3c == piVar5) — i.e. local_3c == own_power
                    if local_3c == own_power:
                        # Check stab/retreat flags first; then friendly/ally flags
                        # C: if NOT (stab OR retreat) AND NOT (friendly OR ally) → skip
                        if stab_flag == 1 or retreat_flag == 1 or friendly_flag == 1 or ally_flag == 1:
                            # Trust gate: C uses stride 21, but Python arrays are (7,7).
                            # Fixed 2026-04-21: use correct flat index for (7,7): own_power * 7 + unit_power
                            try:
                                t_hi = int(state.g_ally_trust_score_hi[own_power, unit_power])
                                t_lo = int(state.g_ally_trust_score[own_power, unit_power])
                            except (IndexError, AttributeError):
                                t_hi = 0
                                t_lo = 0
                            if t_hi < 1 and (t_hi < 0 or t_lo < 3):
                                local_48 += 10000.0 / order_score

        state.g_winter_score_a[province_id] = local_4c
        state.g_winter_score_b[province_id] = local_48


def _safe_pow(base: float, exp: float) -> float:
    """FUN_0047b370 proxy. Returns base**exp; returns 0.0 if base <= 0."""
    if base <= 0.0:
        return 0.0
    return base ** exp


def _float_to_int64(value: float) -> int:
    """Port of FloatToInt64 / PackScoreU64 (Source/utils/FloatToInt64.c).

    Both C functions perform:
      1. ROUND (x87 FRNDINT — banker's rounding, round-to-even)
      2. Remainder check:  frac = value - rounded
      3. Truncation correction: subtract/add 1 if |frac| >= 0.5
         (via ``0x80000000 < (uint)-(float)(frac)`` test)

    Net effect: the correction always undoes the ROUND half-up/half-down
    ambiguity, producing **truncation toward zero** for values exactly at
    ±0.5 boundaries.  For all other values the result is the same as
    ``round()`` (banker's).

    Python ``int()`` truncates toward zero unconditionally — which is
    close but diverges for e.g. 2.7 → int gives 2, round gives 3.
    Python ``round()`` does banker's rounding — matches the ROUND step
    but lacks the correction.  The safest portable match is ``int(round(v))``
    with a tie-break toward zero, which is what we implement here.
    """
    if value == 0.0:
        return 0
    r = round(value)           # banker's round (matches FRNDINT)
    frac = value - float(r)
    # Correction: if remainder magnitude >= 0.5 (exactly at .5 boundary),
    # C truncates toward zero → undo the round-away-from-zero.
    if abs(frac) >= 0.5:
        if value > 0:
            r -= 1
        else:
            r += 1
    return int(r)


def evaluate_alliance_score(state: InnerGameState, own_power: int) -> None:
    """
    Port of EvaluateAllianceScore (FUN_0043bd20).

    Complex per-power desirability scoring using unit positions, trust levels,
    threat assessment, and alliance history. Writes state.g_alliance_desirability[power].

    Algorithm phases:
      0. Setup: initialize accumulators and weights based on NearEndGameFactor
      1. Unit-list walk: populate province_visit and per-unit scoring arrays
      2. Province threat scoring: compute threat_score from reach arrays
      3. Per-province occupation scoring: apply trust-gated penalties/bonuses
      4. Fleet adjacency scoring: score uncertain-trust fleet interactions
      5. Final accumulation: trust-weighted per-power scoring
    """
    num_powers = 7
    num_provinces = 256
    state.g_alliance_desirability.fill(0.0)

    # --- Phase 0: Setup ---
    win_threshold = state.win_threshold  # typically 18
    near_end_factor = float(state.g_near_end_game_factor)

    # Weight factors based on NearEndGameFactor
    enemy_weight = 50
    ally_weight = 50
    if near_end_factor >= 3.0 and int(state.sc_count[own_power]) > 2:
        if near_end_factor < 5.0:
            enemy_weight = 80
            ally_weight = 70
        elif near_end_factor >= 6.0:
            enemy_weight = 120
            ally_weight = 100
        else:  # 5.0 <= near_end_factor < 6.0
            enemy_weight = 100
            ally_weight = 90

    # Initialize per-power accumulators
    main_score = np.full(num_powers, 5000.0, dtype=np.float64)
    deduction = np.zeros(num_powers, dtype=np.float64)
    enemy_penalty = np.zeros(num_powers, dtype=np.float64)
    ally_affinity = np.zeros(num_powers, dtype=np.float64)
    threat_a = np.zeros(num_powers, dtype=np.float64)
    threat_b = np.zeros(num_powers, dtype=np.float64)
    opening_bonus = np.zeros(num_powers, dtype=np.float64)

    # Initialize per-power × province arrays
    province_visit = np.zeros((num_powers, num_provinces), dtype=np.float64)
    threat_score = np.zeros((num_powers, num_provinces), dtype=np.float64)
    fleet_adj_score = np.zeros((num_powers, num_provinces), dtype=np.float64)
    prov_move_count = np.zeros(num_provinces, dtype=np.float64)

    # --- Phase 1: Unit-list walk ---
    # For each unit, accumulate province visit scores and per-power heat contributions
    for prov, unit_data in state.unit_info.items():
        power = unit_data.get('power', -1)
        if power < 0 or power >= num_powers:
            continue

        # Add unit's province heat to prov_move_count
        heat = float(state.g_heat_movement[power, prov]) if hasattr(state, 'g_heat_movement') else 0.0
        prov_move_count[prov] += heat

        # For each other power, add reachability contribution to province_visit
        for other_power in range(num_powers):
            province_visit[other_power, prov] += heat

    # --- Phase 2: Province threat scoring ---
    # For each province, compute threat from g_own_reach_score and g_enemy_reach_score
    for prov in range(num_provinces):
        for outer_power in range(num_powers):
            combined_threat = 0.0
            for inner_power in range(num_powers):
                if inner_power != outer_power:
                    own_reach = float(state.g_own_reach_score[inner_power, prov])
                    enemy_reach = float(state.g_enemy_reach_score[inner_power, prov])
                    combined_threat += max(own_reach, enemy_reach)

            # Apply near-end-game factor logic
            if near_end_factor <= 5.0:
                threat_score[outer_power, prov] = max(threat_score[outer_power, prov], combined_threat)
            else:
                threat_score[outer_power, prov] += combined_threat

    # --- Phase 3: Per-province occupation scoring ---
    # For provinces with units, apply trust-gated penalties and bonuses
    for prov, unit_data in state.unit_info.items():
        unit_power = unit_data.get('power', -1)
        if unit_power < 0:
            continue

        # For the power owning this unit
        for outer_power in range(num_powers):
            if outer_power == unit_power:
                # Own unit: compare threat vs local accumulation
                threat_val = threat_score[outer_power, prov]
                province_visits = province_visit[outer_power, prov]

                if threat_val > province_visits:
                    diff = threat_val - province_visits
                    if diff < win_threshold:
                        if province_visits * 3 < threat_val * 2:
                            enemy_penalty[outer_power] += 10
                        elif province_visits < threat_val:
                            enemy_penalty[outer_power] += 5
                        else:
                            enemy_penalty[outer_power] -= 10
                    else:
                        enemy_penalty[outer_power] += 20
            else:
                # Other power's unit: check trust and threat levels
                trust_hi = int(state.g_ally_trust_score_hi[outer_power, unit_power]) if hasattr(state, 'g_ally_trust_score_hi') else 0
                trust_lo = int(state.g_ally_trust_score[outer_power, unit_power]) if hasattr(state, 'g_ally_trust_score') else 0
                own_reach = float(state.g_own_reach_score[outer_power, prov])
                threat_val = threat_score[outer_power, prov]

                # Apply trust-weighted scoring
                if own_reach > 0:
                    if trust_hi < 1 and (trust_hi < 0 or trust_lo < 3):
                        ally_affinity[outer_power] -= 10
                    elif threat_val > 0:
                        ally_affinity[outer_power] += 5

    # --- Phase 4: Fleet-chain BFS scoring (C lines 748-862) ---
    # For each province with a fleet, get fleet-filtered adjacencies and walk
    # the chain.  For each fleet-adjacent province, look up unit presence via
    # the unit_info dict. If the unit's reach for the evaluated power > 0,
    # compute a score based on whether the unit at the adjacent province
    # belongs to the same owner (factor 0.1, cap 20) or different (0.05, cap 10).
    # local_a808[power*256 + prov] accumulates the fleet-chain scores.
    local_a808 = np.zeros((num_powers, num_provinces), dtype=np.float64)

    for prov, unit_data in state.unit_info.items():
        unit_power = unit_data.get('power', -1)
        unit_type = unit_data.get('type', 'A')
        if unit_power < 0 or unit_type in ('A', 'AMY'):
            continue  # fleet-only pass

        # For each evaluated power, check if reach > 0
        for eval_power in range(num_powers):
            reach_val = float(state.g_own_reach_score[eval_power, prov]) \
                if hasattr(state, 'g_own_reach_score') else 0.0
            if reach_val <= 0:
                continue

            # Compute base_score: ((affinity + 50) * reach) / num_powers
            affinity = float(main_score[eval_power])  # puVar8[piStack_102e8 + 5]
            base_score = int(((affinity + 50) * reach_val) / num_powers)

            # Get fleet-filtered adjacency list
            raw_adj = state.adj_matrix.get(prov, [])
            fleet_adj = [a for a in raw_adj if a not in state.land_provinces]

            for adj_prov in fleet_adj:
                adj_unit = state.unit_info.get(adj_prov)
                if adj_unit is None:
                    continue
                adj_reach = float(state.g_own_reach_score[eval_power, adj_prov]) \
                    if hasattr(state, 'g_own_reach_score') else 0.0
                if adj_reach <= 0:
                    continue

                # GameBoard_GetPowerRec: check if adj province owner == prov owner
                adj_owner = adj_unit.get('power', -1)
                if adj_owner == unit_power:
                    # Same owner: factor 0.1, cap 20
                    new_val = (adj_reach * base_score * 0.1) / num_powers
                    if new_val > local_a808[eval_power, adj_prov]:
                        local_a808[eval_power, adj_prov] = min(new_val, 20.0)
                else:
                    # Different owner: factor 0.05, cap 10
                    new_val = (adj_reach * base_score * 0.05) / num_powers
                    if new_val > local_a808[eval_power, adj_prov]:
                        local_a808[eval_power, adj_prov] = min(new_val, 10.0)

    # Transfer local_a808 into fleet_adj_score (used by Phase 5)
    fleet_adj_score[:] = local_a808

    # --- Phase 5: Final accumulation ---
    for power in range(num_powers):
        if power == own_power:
            continue

        # Accumulate fleet adjacency scores
        main_score[power] += float(np.sum(fleet_adj_score[power]))

        # Apply penalties
        main_score[power] -= enemy_penalty[power]
        main_score[power] += ally_affinity[power]

        # Retrieve trust and relation scores
        trust_score = int(state.g_ally_trust_score[own_power, power]) if hasattr(state, 'g_ally_trust_score') else 0
        trust_hi = int(state.g_ally_trust_score_hi[own_power, power]) if hasattr(state, 'g_ally_trust_score_hi') else 0
        relation_score = int(state.g_relation_score[own_power, power]) if hasattr(state, 'g_relation_score') else 0
        deceit_level = int(getattr(state, 'g_deceit_level', 0))

        # Final trust-weighted scoring (C lines 1068-1098)
        # Branch 1: untrusted / unknown → enemy weight
        # C: (trust==0 && trust_hi==0) || (trust==1 && trust_hi==0 && relation<0xb)
        if (trust_score == 0 and trust_hi == 0) or \
           (trust_score == 1 and trust_hi == 0 and relation_score < 11):
            # Enemy scoring: pull toward 2000 baseline
            score_adj = (2000.0 - main_score[power]) * enemy_weight
        # Branch 2: trusted ally → ally weight
        # C: (trust_hi>=0 && (trust_hi>0 || trust!=0) && relation>0x13) ||
        #    (trust_hi>=0 && (trust_hi>0 || trust>2) && deceit_level>1)
        elif ((trust_hi >= 0 and (trust_hi > 0 or trust_score != 0) and relation_score > 19) or
              (trust_hi >= 0 and (trust_hi > 0 or trust_score > 2) and deceit_level > 1)):
            # Ally scoring: reward above 2000 baseline
            # C has special handling for piStack_1027c (leading power) and DAT_004c6bc4
            score_adj = (main_score[power] - 2000.0) * ally_weight
        else:
            score_adj = 0.0

        state.g_alliance_desirability[power] = score_adj
