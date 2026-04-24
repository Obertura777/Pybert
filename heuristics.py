import numpy as np
from .state import InnerGameState

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


def apply_influence_scores(state: InnerGameState, own_power: int):
    """
    Port of ApplyInfluenceScores (sole caller of AppendOrder / FUN_00419d80).

    Builds the press-proposal candidate slate in state.g_OrderList that
    ProposeDMZ later consumes.  Also computes g_HeatScore, g_InfluenceRatio,
    g_UnitAdjacencyCount, g_AttackHistory (move-bonus accumulation), and
    inter-power contact statistics.

    Resolved (see ApplyInfluenceScores.md for formulas):
      Q-AIS-1  g_PerPowerMoveBonus = g_AttackHistory (DAT_005a48e8)
      Q-AIS-2  Gate array = DAT_004DA2F0 (g_HistoryGate), pure 2D, NOT g_MoveHistoryMatrix
      Q-AIS-4  g_MoveScore = round(pow(heat_B,8)*pow(heat_A,9)/1e22); deterministic
      Q-AIS-5  g_SupportScore = round((heat_B*heat_A)^4/1e8); FloatToInt64 = converter
      Q-AIS-8  Contact matrix stride = 0x3f confirmed

    Resolved:
      Q-AIS-NEW-1  Gate is g_UnitAdjacencyCount (DAT_004e1af0), NOT DAT_004DA2F0
                    (which was end of g_HeatScore). Written by Pass 4 above.

    Still open:
      Q-AIS-NEW-2  sort_key FloatToInt64 arg unknown → using g_SupportScore[prov]
    """
    NUM_POWERS = 7
    NUM_PROVINCES = 256

    # ── Pass 1: Zero accumulators + 5-round BFS influence propagation ────────
    #
    # For each power:
    #   • All provinces in adjacency lists initialised to score 0 in ordered set
    #   • Own-power units seeded at base score 5000
    #   • 5 rounds: each province = sum(adjacent scores) / 5
    #   • Own-unit provinces re-pinned to 5000 each round (source stays "on")
    # Result written to g_HeatScore and to g_HeatMovement / g_HeatMovement_B
    # (the two arrays consumed by Pass 5's score formula).
    state.g_HeatScore.fill(0)
    state.g_HeatMovement.fill(0)
    state.g_HeatMovement_B.fill(0)

    for power in range(NUM_POWERS):
        scores = np.zeros(NUM_PROVINCES, dtype=np.int64)

        for prov_id, info in state.unit_info.items():
            if info['power'] == power:
                scores[prov_id] = 5000

        for _ in range(5):
            nxt = np.zeros(NUM_PROVINCES, dtype=np.int64)
            for prov in range(NUM_PROVINCES):
                adj = state.get_unit_adjacencies(prov)
                if adj:
                    nxt[prov] = sum(scores[q] for q in adj) // 5
            for prov_id, info in state.unit_info.items():
                if info['power'] == power:
                    nxt[prov_id] = max(nxt[prov_id], 5000)
            scores = nxt

        # ── Pass 2: Accumulate g_HeatScore ───────────────────────────────────
        for prov in range(NUM_PROVINCES):
            state.g_HeatScore[power, prov] = int(scores[prov])

        # Mirror into the two movement-heat arrays consumed by Pass 5.
        # DAT_004ec2f0 (g_HeatMovement) is power_b's input; DAT_005af0e8
        # (g_HeatMovement_B) is power_a's input. Both are filled identically
        # here and normalised to 100-scale in Pass 6 before Pass 5 reads them.
        state.g_HeatMovement[power] = scores.astype(np.float64)
        state.g_HeatMovement_B[power] = scores.astype(np.float64)

    # ── Pass 3: g_InfluenceRatio normalisation ────────────────────────────────
    #
    # For army-occupied provinces:
    #   owner == own_power → ratio = heat_a / global_max(g_HeatScore)
    #   otherwise          → ratio = heat_a / heat_owner   (may exceed 1.0)
    state.g_InfluenceRatio.fill(0.0)
    global_heat_max = float(np.max(state.g_HeatScore)) or 1.0

    for power_a in range(NUM_POWERS):
        for prov in range(NUM_PROVINCES):
            info = state.unit_info.get(prov)
            if info is None or info['type'] != 'A':
                continue
            owner = info['power']
            heat_a = float(state.g_HeatScore[power_a, prov])
            if owner == own_power:
                state.g_InfluenceRatio[power_a, prov] = heat_a / global_heat_max
            else:
                heat_owner = float(state.g_HeatScore[owner, prov])
                state.g_InfluenceRatio[power_a, prov] = (
                    heat_a / heat_owner if heat_owner > 0.0 else 0.0
                )

    # ── Pass 4: g_UnitAdjacencyCount ─────────────────────────────────────────
    #
    # g_UnitAdjacencyCount[power][province] = count of power's units that can
    # reach province (each unit counts its own province + all adjacencies).
    state.g_UnitAdjacencyCount.fill(0)
    for prov_id, info in state.unit_info.items():
        pw = info['power']
        for adj in state.get_unit_adjacencies(prov_id):
            state.g_UnitAdjacencyCount[pw, adj] += 1
        state.g_UnitAdjacencyCount[pw, prov_id] += 1

    # ── Pass 6 (early): Normalise g_HeatMovement / g_HeatMovement_B to 100 ───
    #
    # Must run before Pass 5 so the score formula has normalised inputs.
    # spec: DAT_004ec2f0[power][province] = value * 100 / max  (__allmul+__alldiv)
    for power in range(NUM_POWERS):
        max_mv = float(np.max(state.g_HeatMovement[power]))
        if max_mv > 0.0:
            state.g_HeatMovement[power] *= 100.0 / max_mv
        max_mv_b = float(np.max(state.g_HeatMovement_B[power]))
        if max_mv_b > 0.0:
            state.g_HeatMovement_B[power] *= 100.0 / max_mv_b

    # ── Pass 5: Per-pair scores + AppendOrder ─────────────────────────────────
    #
    # g_MoveScore[prov] = round(pow(heat_B, 8) * pow(heat_A, 9) / 1e22)
    #   heat_B = g_HeatMovement[power_b][prov]   exponent 8.0  (DAT_004b0a50)
    #   heat_A = g_HeatMovement_B[power_a][prov] exponent 9.0  (DAT_004b0f18)
    #   denom  = pow(100, 6) * pow(100, 5) = 1e12 * 1e10 = 1e22
    #
    # g_SupportScore[prov] = round((heat_B * heat_A)^4 / 1e8)
    #   exponent 4.0 (DAT_004b0f10) applied to both; denom = pow(100,2)^2 = 1e8
    #
    # Gate: zero both scores if g_UnitAdjacencyCount[power_a/b][prov] == 0
    #   (Q-AIS-NEW-1 RESOLVED: DAT_004DA2F0 was a misidentified address — it's
    #    the end of g_HeatScore. The actual gate is g_UnitAdjacencyCount, which
    #    is written by Pass 4 above. See GlobalDataRefs.md for confirmation.)
    #
    # g_AttackHistory[power_a][prov] += FloatToInt64(...) when best_move > 0
    #   (exact FloatToInt64 arg TBD — Q-AIS-NEW-2; using heat_a as placeholder)
    #
    # sort_key = FloatToInt64(ST0) — exact ST0 source TBD (Q-AIS-NEW-2)
    #   placeholder: g_SupportScore[prov]
    DENOM_MOVE    = 1e22   # pow(100,6) * pow(100,5)
    DENOM_SUPPORT = 1e8    # pow(100,2) ** 2
    EXP_MOVE_B    = 8.0    # DAT_004b0a50
    EXP_MOVE_A    = 9.0    # DAT_004b0f18
    EXP_SUPPORT   = 4.0    # DAT_004b0f10

    state.g_OrderList.clear()

    for power_a in range(NUM_POWERS):
        for power_b in range(NUM_POWERS):
            if power_a == power_b:
                continue

            move_scores    = np.zeros(NUM_PROVINCES, dtype=np.int64)
            support_scores = np.zeros(NUM_PROVINCES, dtype=np.int64)

            for prov in range(NUM_PROVINCES):
                # Gate on g_UnitAdjacencyCount (was misidentified as DAT_004DA2F0
                # "g_HistoryGate" — actually the tail of g_HeatScore; real gate is
                # g_UnitAdjacencyCount at DAT_004e1af0, written by Pass 4 above).
                if (state.g_UnitAdjacencyCount[power_a, prov] == 0 or
                        state.g_UnitAdjacencyCount[power_b, prov] == 0):
                    continue

                heat_b = float(state.g_HeatMovement[power_b, prov])
                heat_a = float(state.g_HeatMovement_B[power_a, prov])

                mv = _safe_pow(heat_b, EXP_MOVE_B) * _safe_pow(heat_a, EXP_MOVE_A)
                move_scores[prov] = int(mv / DENOM_MOVE) if DENOM_MOVE > 0 else 0

                sp = _safe_pow(heat_b, EXP_SUPPORT) * _safe_pow(heat_a, EXP_SUPPORT)
                support_scores[prov] = int(sp / DENOM_SUPPORT) if DENOM_SUPPORT > 0 else 0

            best_move    = int(np.max(move_scores))
            best_support = int(np.max(support_scores))

            # g_AttackHistory accumulation (= g_PerPowerMoveBonus, DAT_005a48e8)
            # FloatToInt64 arg TBD (Q-AIS-NEW-2); placeholder: heat_a value
            if best_move > 0:
                for prov in range(NUM_PROVINCES):
                    heat_a = float(state.g_HeatMovement_B[power_a, prov])
                    state.g_AttackHistory[power_a, prov] += int(heat_a)

            # Build g_OrderList press-proposal slate (own power only)
            if best_support > 0 and power_a == own_power:
                for prov in range(NUM_PROVINCES):
                    # sort_key = FloatToInt64(ST0); placeholder = support score
                    sort_key = int(support_scores[prov])
                    if sort_key == 0:
                        continue
                    if prov not in state.unit_info:
                        continue

                    flag1 = True
                    flag2 = True
                    flag3 = False

                    owner = int(state.g_ScOwner[prov])
                    if owner == own_power:
                        flag2 = False   # Albert owns province → unilateral
                    # owner == power_b: flag3 stays False (contested, bilateral)

                    unit = state.unit_info[prov]
                    if unit['type'] == 'A':
                        unit_power = unit['power']
                        if unit_power == own_power:
                            flag2 = False            # Albert's unit → unilateral
                        elif unit_power == power_b:
                            flag2 = True             # ally's unit → bilateral

                    # AppendOrder = std::map<int,OrderEntry>::insert keyed by sort_key
                    state.g_OrderList.append({
                        'flag1': flag1,
                        'flag2': flag2,
                        'flag3': flag3,
                        'province': prov,
                        'ally_power': power_b,
                        'score': sort_key,
                        'done': False,
                    })

    # g_OrderList mirrors std::map sort (ascending key = lowest score first in map;
    # ProposeDMZ iterates in order — descending score = highest priority first)
    state.g_OrderList.sort(key=lambda e: e['score'], reverse=True)

    # ── Pass 6 (cont.): g_GlobalProvinceScore + inter-power contact matrices ──
    state.g_GlobalProvinceScore.fill(0.0)
    for prov in range(NUM_PROVINCES):
        for power in range(NUM_POWERS):
            state.g_GlobalProvinceScore[prov] += state.g_HeatMovement[power, prov]
    global_prov_max = float(np.max(state.g_GlobalProvinceScore)) or 1.0
    state.g_GlobalProvinceScore *= 100.0 / global_prov_max

    # Contact matrices: stride 0x3f confirmed (Q-AIS-8 resolved)
    # Python (7,7) ndarray is equivalent to C [pow*0x3f+other] for 7 powers.
    state.g_ContactCount.fill(0)
    state.g_ContactWeighted.fill(0)
    state.g_ContactOwnerCount.fill(0)
    for prov_id, info in state.unit_info.items():
        pw = info['power']
        for adj in state.get_unit_adjacencies(prov_id):
            owner_r = int(state.g_ScOwner[adj])
            if owner_r < 0 or owner_r >= NUM_POWERS or owner_r == pw:
                continue
            if state.g_InfluenceRatio[pw, adj] > 1.0:
                state.g_ContactCount[pw, owner_r] += 1
                state.g_ContactWeighted[pw, owner_r] += int(
                    state.g_UnitAdjacencyCount[pw, adj]
                )
                state.g_ContactOwnerCount[pw, owner_r] += int(
                    state.g_UnitAdjacencyCount[owner_r, adj]
                )

def score_order_candidates_all_powers(state: InnerGameState, round_weights: list, dominant_power_idx: int):
    """
    Port of ScoreOrderCandidates_AllPowers / FUN_0044a040.
    Per-power per-province influence dot-product scoring pass.
    """
    dominance_weight = state.ScoreCurrent - state.ScoreBaseline
    
    for power in range(7):
        for province in range(256):
            if not state.CandidateSet_contains(power, province):
                continue
                
            total = 0.0
            for i in range(min(10, len(round_weights))):
                score = state.get_candidate_score(power, province, i)
                total += score * round_weights[i]
                
            if getattr(state, 'g_DominantPowerMode', 0) == 1 and power != dominant_power_idx:
                main_candidate_score = state.get_candidate_score(power, province, 0)
                total += main_candidate_score * dominance_weight
                
            state.g_MaxProvinceScore[province] = max(state.g_MaxProvinceScore[province], total)
            state.g_MinScore[province] = min(state.g_MinScore[province], total)
            
            state.FinalScoreSet[power, province] = total
            
    # Pass 2 - Score normalization (C Phase 1b, lines 131-211)
    # Rewritten 2026-04-14: per-power max/min now tracked via
    # g_MaxProvScorePerPower / g_MinProvScorePerPower (was only global).
    # Sub-threshold nonzero/non-min branch now uses _safe_pow sqrt proxy
    # instead of collapsing to 1.0.
    import math
    import random as _rnd
    global_max = np.max(state.g_MaxProvinceScore)
    threshold = global_max / 100.0
    # Off-by-one guard — C: if min == threshold → threshold = min+1
    global_min = float(np.min(state.g_MinScore))
    if global_min == threshold:
        threshold = global_min + 1.0

    for power in range(7):
        for province in range(256):
            raw_score = state.FinalScoreSet[power, province]
            if raw_score <= 0:
                continue
            if raw_score >= threshold and global_max > 0:
                score = (raw_score * 1000.0 / global_max) + 15.0
            else:
                if raw_score == 0:
                    score = 1.0
                elif raw_score == state.g_MinScore[province]:
                    score = float(_rnd.randint(1, 10))
                else:
                    # _safe_pow proxy — C applies pow(score/min, exponent).
                    # Exponent not recoverable from Ghidra; use 0.5 (sqrt)
                    # consistent with the CAL_BOARD parity notes.
                    denom = max(float(state.g_MinScore[province]), 1.0)
                    score = math.sqrt(max(raw_score / denom, 0.0))
                if score > 10.0:
                    score = 10.0

            state.FinalScoreSet[power, province] = score

            # Per-power max/min pair updates (C Phase 1b tail, lines 193-209)
            if hasattr(state, 'g_MaxProvScorePerPower'):
                if score > state.g_MaxProvScorePerPower[power, province]:
                    state.g_MaxProvScorePerPower[power, province] = score
                if score < state.g_MinProvScorePerPower[power, province]:
                    state.g_MinProvScorePerPower[power, province] = score

            # Pass 3 - AMY shortfall-pull toward max (C Phase 1c, lines 214-248)
            # Replaces former random 0.9-1.1 jitter with deterministic
            # "delta to per-power max" — pulls under-performing armies
            # toward the best-scoring province.
            if state.get_unit_type(province) == "AMY":
                per_pow_max = (state.g_MaxProvScorePerPower[power, province]
                               if hasattr(state, 'g_MaxProvScorePerPower')
                               else state.g_MaxProvinceScore[province])
                if score < per_pow_max:
                    state.FinalScoreSet[power, province] = float(per_pow_max) - score

    # Pass 3b - Recompute g_MaxProvinceScore from normalized FinalScoreSet.
    # In C (lines 192-201), g_MaxProvinceScore is updated DURING the
    # normalization loop, so it holds post-normalization values.  The Python
    # Pass 1 sets it from raw dot-product totals; we must refresh it here so
    # that downstream consumers (TopReachFlag, BuildSupportOpportunities)
    # see the correct normalized maxima.
    state.g_MaxProvinceScore[:] = 0
    for power in range(7):
        for province in range(256):
            v = float(state.FinalScoreSet[power, province])
            if v > state.g_MaxProvinceScore[province]:
                state.g_MaxProvinceScore[province] = v

    # Pass 4 - g_ProvTargetFlag classification (C Phase 3, lines 265-316)
    # Ported 2026-04-14 — fixes dead-code bug (enemy_reach==0 duplicate branch)
    # and adds g_AttackCount < 1 gate.
    for power in range(7):
        for province in range(256):
            if not state.has_unit(province):
                continue
            # C check: if province has no home-unit OR owner == this power
            unit_owner = getattr(state, 'get_unit_owner', lambda p: None)(province)
            if unit_owner is not None and unit_owner != power:
                continue
            # C: (g_AttackCount[key] < 1) AND (g_TargetFlag != 2 OR g_AttackCount2 != 0)
            attack_cnt = getattr(state, 'g_AttackCount', None)
            attack_cnt_val = attack_cnt[power, province] if attack_cnt is not None else 0
            tflag = state.g_TargetFlag[power, province] if hasattr(state, 'g_TargetFlag') else 0
            attack_cnt2 = getattr(state, 'g_AttackCount2', None)
            ac2_val = attack_cnt2[power, province] if attack_cnt2 is not None else 0
            if not (attack_cnt_val < 1 and (tflag != 2 or ac2_val != 0)):
                continue
            enemy_reach = state.get_enemy_reach(power, province)
            sc_own = state.g_SCOwnership[power, province]
            total_reach = state.g_TotalReachScore[power, province] if hasattr(state, 'g_TotalReachScore') else 0
            enemy_reach_score = state.g_EnemyReachScore[power, province] if hasattr(state, 'g_EnemyReachScore') else 0
            d535 = getattr(state, 'g_EnemyPressureSecondary', None)
            d535_val = d535[power, province] if d535 is not None else 0

            if enemy_reach < 0:
                # Fully safe — enemy cannot reach
                state.g_ProvTargetFlag[power, province] = 1
            elif enemy_reach == 0 and sc_own == 1 and enemy_reach_score == 0 and d535_val == 0:
                # Own SC, no enemy near
                state.g_ProvTargetFlag[power, province] = 1
            elif (enemy_reach == 1 and sc_own == 1 and total_reach == 0
                  and enemy_reach_score == 0 and d535_val == 0):
                # Own SC, 1-hop enemy — secondary priority
                state.g_ProvTargetFlag[power, province] = 2
            else:
                continue
            # C: (&DAT_005ee8ec)[iVar10 * 2] = 0 — clear the "classified" marker
            if hasattr(state, 'g_TargetFlag2'):
                state.g_TargetFlag2[power, province] = 0

    # Pass 5 - Enemy-adjacency denial (C Phase 4, lines 317-407)
    # For each own unit: if a 2-hop-reachable province is occupied by a
    # non-allied enemy, mark the 1-hop province as flanked (flag = -10).
    for power in range(7):
        for unit_prov in (state.get_power_units(power)
                          if hasattr(state, 'get_power_units') else []):
            for adj1 in (state.get_adjacent_provinces(unit_prov)
                         if hasattr(state, 'get_adjacent_provinces') else []):
                for adj2 in (state.get_adjacent_provinces(adj1)
                             if hasattr(state, 'get_adjacent_provinces') else []):
                    adj2_owner = (state.get_unit_owner(adj2)
                                  if hasattr(state, 'get_unit_owner') else None)
                    if adj2_owner is None or adj2_owner == power:
                        continue
                    # C: g_RelationScore[local_f4*21+owner] < 10 — not trusted ally.
                    # Fixed 2026-04-14 — was reading g_AllyHistoryCount (unpopulated);
                    # correct global is g_RelationScore (DAT_00634e90).
                    rel = getattr(state, 'g_RelationScore', None)
                    rel_val = rel[power, adj2_owner] if rel is not None else 0
                    if rel_val >= 10:
                        continue
                    if (state.g_ProvTargetFlag[power, adj1] == 1
                        and state.g_TargetFlag2[power, adj1] == 0):
                        state.g_ProvTargetFlag[power, adj1] = -10
                        state.g_TargetFlag2[power, adj1] = -1

    # Pass 6 - Multi-flanked restoration (C Phase 5, lines 408-480)
    # If a province has >1 neighbor also flagged -10, the local front is
    # contested everywhere — lift the flag back to 1.
    for power in range(7):
        for province in range(256):
            if state.g_ProvTargetFlag[power, province] != -10:
                continue
            flanked_neighbors = 0
            for adj in (state.get_adjacent_provinces(province)
                        if hasattr(state, 'get_adjacent_provinces') else []):
                if state.g_ProvTargetFlag[power, adj] == -10:
                    flanked_neighbors += 1
            if flanked_neighbors > 1:
                state.g_ProvTargetFlag[power, province] = 1
                if hasattr(state, 'g_TargetFlag2'):
                    state.g_TargetFlag2[power, province] = 0

    # Pass 7 - Direct-reach + extended-reach flagging (C Phase 10, lines 682-791)
    # For each own unit: mark adjacency as DirectReach=1 and 2-hop as ExtendedReach=1.
    g_DirectReach = getattr(state, 'g_DirectReachFlag', None)
    g_ExtReach = getattr(state, 'g_ExtendedReachFlag', None)
    if g_DirectReach is not None and g_ExtReach is not None:
        for power in range(7):
            for unit_prov in (state.get_power_units(power)
                              if hasattr(state, 'get_power_units') else []):
                for adj1 in (state.get_adjacent_provinces(unit_prov)
                             if hasattr(state, 'get_adjacent_provinces') else []):
                    g_DirectReach[power, adj1] = 1
                    for adj2 in (state.get_adjacent_provinces(adj1)
                                 if hasattr(state, 'get_adjacent_provinces') else []):
                        if state.has_unit(adj2):
                            g_ExtReach[power, adj2] = 1

        # Pass 7b - 3-round BFS flood-fill of DirectReach (C Phase 10b, lines 792-845)
        for power in range(7):
            for _ in range(3):
                frontier = [p for p in range(256) if g_DirectReach[power, p] == 1]
                for prov in frontier:
                    for adj in (state.get_adjacent_provinces(prov)
                                if hasattr(state, 'get_adjacent_provinces') else []):
                        g_DirectReach[power, adj] = 1

    # Pass 8 - Own-SC rescore reset (C Phase 6, lines 481-517)
    # For each own unit, if its final score is below per-power max → mark
    # g_NeedsRescore = 0 (needs support-score reconsideration).
    if hasattr(state, 'g_NeedsRescore') and hasattr(state, 'g_MaxProvScorePerPower'):
        for power in range(7):
            for unit_prov in (state.get_power_units(power)
                              if hasattr(state, 'get_power_units') else []):
                if (state.FinalScoreSet[power, unit_prov]
                    < state.g_MaxProvScorePerPower[power, unit_prov]):
                    state.g_NeedsRescore[unit_prov] = 0

        # Pass 9 - Support-assignment gate (C Phase 7, lines 518-589)
        # For each own unit adjacency: if pending-rescore AND own SC AND
        # no enemy pressure AND score hits per-power max → finalize.
        for power in range(7):
            for unit_prov in (state.get_power_units(power)
                              if hasattr(state, 'get_power_units') else []):
                for adj in (state.get_adjacent_provinces(unit_prov)
                            if hasattr(state, 'get_adjacent_provinces') else []):
                    if state.g_NeedsRescore[adj] != 0:
                        continue
                    if (state.g_SCOwnership[power, adj] == 1
                        and state.g_EnemyReachScore[power, adj] == 0):
                        score = state.FinalScoreSet[power, adj]
                        if score == state.g_MaxProvScorePerPower[power, adj]:
                            state.g_NeedsRescore[adj] = 1

    # Pass 9b - TopReachFlag population (C lines 481-589, Phase 7b)
    # Two sub-passes mirror the C unit walks:
    #   Sub-pass A (C lines 481-517): for each own unit, look up its
    #       FinalScoreSet entry against g_MaxProvinceScore.  If the unit's
    #       province score is BELOW the global max for that province, clear
    #       g_TopReachFlag[prov] = 0  (province is not a top-reach target).
    #   Sub-pass B (C lines 518-589): for each own unit, walk adjacency q.
    #       If g_TopReachFlag[q] == 0 AND g_SCOwnership[power, q] == 1 AND
    #       FinalScoreSet[power, q] == g_MaxProvinceScore[q], set
    #       g_TopReachFlag[q] = 1  (reachable top-scored own-SC province).
    # This populates the gate used by build_support_opportunities.
    for power in range(7):
        # Sub-pass A: clear TopReachFlag for under-performing unit provinces
        for unit_prov in (state.get_power_units(power)
                          if hasattr(state, 'get_power_units') else []):
            fs_val = float(state.FinalScoreSet[power, unit_prov])
            mx_val = float(state.g_MaxProvinceScore[unit_prov])
            if fs_val < mx_val:
                state.g_TopReachFlag[unit_prov] = 0

    for power in range(7):
        # Sub-pass B: mark reachable own-SC provinces that hit max score
        for unit_prov in (state.get_power_units(power)
                          if hasattr(state, 'get_power_units') else []):
            for q in (state.get_adjacent_provinces(unit_prov)
                      if hasattr(state, 'get_adjacent_provinces') else []):
                if int(state.g_TopReachFlag[q]) != 0:
                    continue  # already set or cleared with non-zero marker
                if int(state.g_SCOwnership[power, q]) != 1:
                    continue
                fs_q = float(state.FinalScoreSet[power, q])
                mx_q = float(state.g_MaxProvinceScore[q])
                if fs_q > 0 and fs_q == mx_q:
                    state.g_TopReachFlag[q] = 1

    # Pass 10 - BuildSupportOpportunities call (C Phase 8, line 590)
    try:
        from albert.moves import build_support_opportunities
        build_support_opportunities(state)
    except Exception:
        # build_support_opportunities may require richer state than a
        # stub; don't block the scoring pass for test harnesses.
        pass

    # Pass 11 - g_SupportCandidateMark via enemy-reachable ally-designated
    # adjacencies (C Phase 9, lines 591-681).
    g_SupMark = getattr(state, 'g_SupportCandidateMark', None)
    g_AllyE = getattr(state, 'g_AllyDesignation_E', None)
    if g_SupMark is not None and g_AllyE is not None:
        for power in range(7):
            for unit_prov in (state.get_power_units(power)
                              if hasattr(state, 'get_power_units') else []):
                for adj1 in (state.get_adjacent_provinces(unit_prov)
                             if hasattr(state, 'get_adjacent_provinces') else []):
                    if g_AllyE[adj1] < 0:
                        continue
                    # C: (&DAT_004d2e10)[adj*2] != local_f4 → designated for
                    # a different power. Without dual-orientation mirror we
                    # approximate via AllyDesignation_A ≠ own power.
                    if (hasattr(state, 'g_AllyDesignation_A')
                        and state.g_AllyDesignation_A[adj1] == power):
                        continue
                    if state.g_EnemyReachScore[power, adj1] <= 0:
                        continue
                    for adj2 in (state.get_adjacent_provinces(adj1)
                                 if hasattr(state, 'get_adjacent_provinces') else []):
                        g_SupMark[power, adj2] = 1

    # Pass 12 - g_ThreatPathScore (C Phase 11, lines 846-952)
    # For each non-own province with enemy unit and own-reach > 0: iterate
    # its adjacencies and record the max FinalScoreSet reachable via it.
    g_Threat = getattr(state, 'g_ThreatPathScore', None)
    if g_Threat is not None:
        for power in range(7):
            for province in range(256):
                if state.g_OwnReachScore[power, province] <= 0:
                    continue
                owner = (state.get_unit_owner(province)
                         if hasattr(state, 'get_unit_owner') else None)
                if owner is None or owner == power:
                    continue
                for adj in (state.get_adjacent_provinces(province)
                            if hasattr(state, 'get_adjacent_provinces') else []):
                    score = state.FinalScoreSet[power, adj]
                    if score > g_Threat[power, province]:
                        g_Threat[power, province] = score

def compute_draw_vote(state: InnerGameState, friendly_powers: set) -> bool:
    """
    Port of ComputeDrawVote (FUN_004440e0).

    Nash-stability check. Returns True (vote draw) only if all friendly-power
    units are fully committed with no profitable unilateral deviations.

    Called via the FUN_0044c9d0 wrapper which builds `friendly_powers`:
        own_power ∪ { p : curr_sc_cnt[p] > 0 AND trust(own,p) > 1 }
    param_1 in the C = std::map<power_id, sentinel> (the friendly-powers set).
    Step 2 does Map_Find(param_1, unit+0x18) where unit+0x18 = power field
    (NOT province — doc comment was wrong; confirmed by iVar6+0x18 = power
    throughout _build_gof_seq and _move_analysis).

    Internally mirrors local_108 (province metadata map) and local_e4 (reach map).
    """
    if not friendly_powers:
        return False

    # --- Step 1: Province metadata init (local_108) + reach-map init (local_e4) ---
    # local_108[prov]: [flag_a, supporter, flag_b, committed_votes,
    #                   free_candidates, no_order, _, _, _, resolved, ..., fully_committed]
    def _new_meta():
        return {
            'flag_a': 0,          # [0]  set when entry is pre-resolved (free_candidates<=1)
            'supporter': -1,      # [1]  province ID of assigned supporter (-1 = none)
            'committed': 0,       # [2]  committed flag (no/one free target)
            'committed_votes': 0, # [3]  count of committed backers
            'free_candidates': 0, # [4]  total free-move candidate count
            'no_order': 0,        # [5]  1 = unit's power NOT in friendly_powers
            'resolved': 0,        # +9   forced-commitment resolved flag
            'fully_committed': 0, # +0x19 fully-committed flag (required for draw)
        }

    province_meta: dict = {}
    reach_map: dict = {}   # local_e4: province → bool (reachable without conflict)

    for prov in state.adj_matrix:
        province_meta.setdefault(prov, _new_meta())
        for adj in state.adj_matrix.get(prov, []):
            reach_map.setdefault(adj, False)

    # --- Step 2: Unit-to-power-set correlation ---
    # C: Map_Find(param_1, unit+0x18) where unit+0x18 = unit.power (power field).
    # If unit.power NOT in friendly_powers → mark province as no_order=1 (non-friendly).
    # If unit.power IN friendly_powers → mark province as reachable (local_e4=1).
    for prov, unit_data in state.unit_info.items():
        province_meta.setdefault(prov, _new_meta())
        unit_power = unit_data.get('power', -1)
        if unit_power not in friendly_powers:
            province_meta[prov]['no_order'] = 1   # non-friendly unit
        else:
            reach_map[prov] = True                # friendly unit: province is reachable

    # --- Step 3: Adjacency flood-fill from submitted-order provinces ---
    # Expand reach to adjacent provinces that have no submitted order.
    changed = True
    while changed:
        changed = False
        for prov, reachable in list(reach_map.items()):
            if not reachable:
                continue
            if province_meta.get(prov, {}).get('no_order', 0):
                continue  # unsubmitted province is not a seed
            for adj in state.adj_matrix.get(prov, []):
                adj_meta = province_meta.get(adj, {})
                if adj_meta.get('no_order', 0) == 0:
                    continue  # adj already has submitted order
                if not reach_map.get(adj, False):
                    reach_map[adj] = True
                    changed = True

    # --- Step 4: First draw-vote candidate check ---
    # C step 4: if unit.power NOT in friendly_powers and no_order==1 → don't draw.
    # "power_lookup NOT in param_1" = unit.power not in friendly_powers.
    vote = True
    for prov in list(state.unit_info.keys()):
        meta = province_meta.get(prov, {})
        unit_power = state.unit_info.get(prov, {}).get('power', -1)
        if unit_power not in friendly_powers and meta.get('no_order', 0) == 1:
            vote = False

    if not vote:
        return False

    # --- Supporter assignment pre-pass ---
    # For each non-friendly-power province (no_order=1), count free-move candidates
    # among its neighbours and assign itself as supporter to those neighbours.
    prev_no_order_prov = -1
    for prov in sorted(province_meta.keys()):
        meta = province_meta.get(prov, {})
        if meta.get('no_order', 0) != 1:
            continue
        if prov != prev_no_order_prov:
            for adj in state.adj_matrix.get(prov, []):
                province_meta.setdefault(adj, _new_meta())
                province_meta[adj]['free_candidates'] += 1
            prev_no_order_prov = prov
        for adj in state.adj_matrix.get(prov, []):
            adj_meta = province_meta.get(adj, {})
            if adj_meta.get('no_order', 0) == 1:
                adj_meta['supporter'] = prov

    # Pre-resolution: for friendly-power units with free_candidates <= 1, mark resolved.
    for prov, unit_data in state.unit_info.items():
        if unit_data.get('power', -1) not in friendly_powers:
            continue
        meta = province_meta.get(prov, _new_meta())
        if meta['free_candidates'] > 1:
            meta['supporter'] = -1   # reset supporter; will be handled by sub-pass B
        else:
            meta['flag_a'] = 1
            meta['resolved'] = 1

    # --- Step 5: Iterative resolution (outer loop runs while progress is made) ---
    for _outer in range(10):
        if not vote:
            break

        # Sub-pass A: mark committed units (entries with flag_a=1, committed=0)
        for prov, meta in province_meta.items():
            if meta.get('flag_a', 0) != 1 or meta.get('committed', 0) == 1:
                continue
            supporter = meta.get('supporter', -1)
            free_count = 0
            free_target = -1
            for adj in state.adj_matrix.get(prov, []):
                adj_meta = province_meta.get(adj, {})
                if adj_meta.get('no_order', 0) != 1:
                    continue
                if adj_meta.get('resolved', 0) != 0:
                    continue
                if adj == free_target:
                    continue   # dedup
                via_supporter = True
                if supporter != -1:
                    via_supporter = state.can_reach(supporter, adj)
                if via_supporter:
                    free_count += 1
                    free_target = adj
            if free_count == 0:
                meta['committed'] = 1
            elif free_count == 1:
                meta['committed'] = 1
                province_meta.setdefault(free_target, _new_meta())
                province_meta[free_target]['committed_votes'] += 1
            else:
                vote = False

        # Check fully-committed after sub-pass A
        for meta in province_meta.values():
            if meta.get('resolved', 0) == 1:
                total = meta.get('free_candidates', 0)
                backed = meta.get('committed_votes', 0)
                if total - 1 <= backed:
                    meta['fully_committed'] = 1

        if not vote:
            break

        # Sub-pass B: resolve remaining via IsLegalMove (can_reach)
        progress = False
        for prov, meta in province_meta.items():
            if meta.get('resolved', 0) != 0:
                continue
            supporter = meta.get('supporter', -1)
            legal_count = 0
            committed_targets: list = []
            for adj in state.adj_matrix.get(prov, []):
                adj_meta = province_meta.get(adj, {})
                if adj_meta.get('no_order', 0) != 1:
                    continue
                if adj_meta.get('flag_a', 0) != 1:
                    continue
                if adj_meta.get('committed', 0) == 1:
                    continue
                if supporter == -1:
                    legal = state.can_reach(prov, adj)
                else:
                    legal = (state.can_reach(supporter, adj)
                             and state.can_reach(prov, adj))
                if legal:
                    legal_count += 1
                    committed_targets.append(adj)

            total = meta.get('free_candidates', 0)
            committed_votes = meta.get('committed_votes', 0)
            remaining = total - legal_count - committed_votes
            if remaining < 2:
                if remaining == 1:
                    progress = True
                    meta['resolved'] = 1
                    for t in committed_targets:
                        province_meta.setdefault(t, _new_meta())['committed'] = 1
            else:
                vote = False

        # Re-check fully-committed after sub-pass B
        for meta in province_meta.values():
            if meta.get('resolved', 0) == 1:
                total = meta.get('free_candidates', 0)
                backed = meta.get('committed_votes', 0)
                if total - 1 <= backed:
                    meta['fully_committed'] = 1

        if not progress:
            break

    # --- Step 6: Final validation ---
    if vote:
        for meta in province_meta.values():
            if meta.get('resolved', 0) == 1 and meta.get('fully_committed', 0) == 0:
                vote = False
                break

    return vote

def detect_stabs_and_hostility(state: InnerGameState, power_idx: int):
    """
    Evaluates phase changes mapping DEVIATE_MOVE and STABBED states
    functionally altering Trust and Alliance networks dynamically.
    """
    for prov in range(256):
        owner_id = -1
        occupier_id = state.get_unit_power(prov)
        
        # Scan ownership arrays
        for p in range(7):
            if state.g_SCOwnership[p, prov] == 1:
                owner_id = p
                break
                
        # Condition A: We own the SC, but someone else occupies it
        if owner_id == power_idx and occupier_id != -1 and occupier_id != power_idx:
            # If the occupier was formally bound in our trust matrix...
            if state.g_AllyMatrix[power_idx, occupier_id] == 1:
                # STABBED scenario mapping
                state.g_AllyMatrix[power_idx, occupier_id] = 0
                state.g_AllyTrustScore[power_idx, occupier_id] = 0.0
                state.g_DeceitLevel += 1
                
                # Escalate positional threat score heavily
                state.g_ThreatLevel[occupier_id, prov] = int(state.g_ThreatLevel[occupier_id, prov]) + 10
                
        # Condition B: We attacked an ally's SC
        elif owner_id != -1 and owner_id != power_idx and occupier_id == power_idx:
            # We breached bounds
            if state.g_AllyMatrix[power_idx, owner_id] == 1:
                # DEVIATE_MOVE mapping
                state.g_AllyMatrix[power_idx, owner_id] = 0
                # Our trust crashes as retaliation is mapped
                state.g_AllyTrustScore[power_idx, owner_id] = max(0, state.g_AllyTrustScore[power_idx, owner_id] / 2.0)


# ── CAL_BOARD ────────────────────────────────────────────────────────────────

def cal_board(state: InnerGameState, own_power: int) -> None:
    """
    Port of CAL_BOARD (FUN_00427960).

    Strategic board evaluation engine, called once per turn before order
    generation.  Computes:
      - _g_NearEndGameFactor
      - g_PowerExpScore  (super-exponential power score)
      - g_SCPercent      (SC percentage per power, relative to win_threshold)
      - g_EnemyCount     (genuine enemy count per power)
      - g_RankMatrix / g_AllyPrefRanking  (influence ranking)
      - g_EnemyFlag      (designated enemies for this turn)
      - g_LeadingFlag / g_OtherPowerLeadFlag / g_NearVictoryPower
      - g_RequestDrawFlag / g_StaticMapFlag
      - g_OneScFromWin
    """
    num_powers = 7
    win_threshold = int(state.win_threshold)
    if win_threshold == 0:
        win_threshold = 1  # guard against divide-by-zero

    trust_hi_mat = getattr(state, 'g_AllyTrustScore_Hi', np.zeros((7, 7), dtype=np.int64))

    # ── Phase 1a: per-power exponential score (Loop A in decompile) ──────────
    # g_PowerExpScore[k] = pow(min(sc_k, win_threshold), min(sc_k, win_threshold)) * 100 + 1
    for k in range(num_powers):
        sc = max(0, min(int(state.sc_count[k]), win_threshold))
        state.g_PowerExpScore[k] = (sc ** sc) * 100.0 + 1.0 if sc > 0 else 1.0

    # ── Phase 1b: NearEndGameFactor + g_SCPercent (Loop B in decompile) ──────
    # g_SCPercent[k] = sc[k] * 100 / win_threshold  (divisor = win threshold, NOT total SCs)
    # g_WarModeFlag reset to 0 before this loop (decompile line 121)
    state.g_WarModeFlag = 0
    near_end = 1.0

    own_sc = int(state.sc_count[own_power])
    # g_OneScFromWin checked before second loop (decompile line 118)
    state.g_OneScFromWin = 1 if (win_threshold - own_sc == 1) else 0

    # Leader tracking (decompile lines 125-147): DAT_00624124 = index of lone
    # leader (unique max-SC power); -1 if two or more powers tie for most SCs.
    lead_pow = -1
    lead_sc = -1
    lead_tied = 0
    for k in range(num_powers):
        sc = int(state.sc_count[k])
        pct = sc * 100.0 / win_threshold
        state.g_SCPercent[k] = pct
        if pct > 80.0:
            state.g_WarModeFlag = 1

        # NearEndGameFactor: running max of (sc[k] - win_threshold + 9)
        factor = float(sc - win_threshold + 9)
        if factor > near_end:
            near_end = factor

        # Track lone leader
        if sc > lead_sc:
            lead_sc = sc
            lead_pow = k
            lead_tied = 1
        elif sc == lead_sc:
            lead_tied += 1

        # Zero g_EnemyFlag in this loop (decompile lines 126-127)
        state.g_EnemyFlag[k] = 0

    # Lone-lead-power: only set if unique; archive "The lone lead power is (%s)"
    # event (DAT_00bbf638 key 0x28) when applicable (decompile lines 157-195).
    if lead_tied < 2:
        state.g_LoneLeadPower = lead_pow
        try:
            state.g_AllianceMsgTree.add(0x28)  # lone-lead-power event code
        except Exception:
            pass
    else:
        state.g_LoneLeadPower = -1

    # Opening-ally-slot promotion (decompile lines 148-156): if slot 0's
    # power has been reduced below 2 SCs, promote slot 1 → 0, slot 2 → 1.
    try:
        s0 = int(getattr(state, 'g_BestAllySlot0', -1))
        s1 = int(getattr(state, 'g_BestAllySlot1', -1))
        s2 = int(getattr(state, 'g_BestAllySlot2', -1))
        if 0 <= s0 < num_powers and int(state.sc_count[s0]) < 2:
            state.g_BestAllySlot0 = s1
            state.g_BestAllySlot1 = s2 if s2 >= 0 else -1
            state.g_BestAllySlot2 = -1
    except Exception:
        pass

    # ── Phase 1c: NearEndGameFactor clamping ──────────────────────────────────
    # C logic (decompile lines 314-388):
    #   if (own_sc > 1 OR near_end >= 7.0):      ← outer TRUE → keep or set 5.0
    #       if (own_sc > 2 OR near_end >= 5.0):  ← inner TRUE → keep
    #       else:                                 ← inner FALSE → 5.0 (close to elimination)
    #   else:                                     ← outer FALSE → 8.0 (about to be eliminated)
    if own_sc > 1 or near_end >= 7.0:
        if not (own_sc > 2 or near_end >= 5.0):
            near_end = 5.0  # close to elimination
        # else: keep computed near_end
    else:
        near_end = 8.0  # about to be eliminated
    state.g_NearEndGameFactor = near_end

    # ── Phase 2: g_EnemyCount + g_RankMatrix init ────────────────────────────
    state.g_EnemyCount.fill(0)
    state.g_AllyDistressFlag.fill(0)
    state.g_RankMatrix.fill(-1)
    np.fill_diagonal(state.g_RankMatrix, -2)

    for row in range(num_powers):
        for col in range(num_powers):
            if row == col:
                continue
            trust_lo = int(state.g_AllyTrustScore[row, col])
            trust_hi = int(trust_hi_mat[row, col])
            influence = float(state.g_InfluenceMatrix[row, col])
            col_sc = int(state.sc_count[col])
            if (trust_hi < 1
                    and (trust_hi < 0 or trust_lo < 2)
                    and influence > 0.0
                    and col_sc > 2):
                state.g_EnemyCount[row] += 1

    # ── Phase 3: top feared powers from influence matrix ─────────────────────
    own_influence_row = state.g_InfluenceMatrix[own_power].copy()
    own_influence_row[own_power] = -1.0  # exclude self
    top3 = sorted(range(num_powers), key=lambda k: own_influence_row[k], reverse=True)[:3]
    top_enemy_1 = top3[0] if len(top3) > 0 else own_power
    top_enemy_2 = top3[1] if len(top3) > 1 else own_power
    top_enemy_3 = top3[2] if len(top3) > 2 else own_power

    # ── Phase 4: find leading non-own power → local_fc / local_128 ───────────
    # local_fc  = int(g_SCPercent[leading_power]) — int-cast, like C FloatToInt64
    # local_128 = index of the non-own power with the highest SC%
    # (decompile lines 729-820; tie-breaking omitted — C uses trust/history)
    local_fc: int = -1
    local_128: int = own_power  # sentinel (own_power used when no rival found)
    for k in range(num_powers):
        if k == own_power:
            continue
        pct_int = int(state.g_SCPercent[k])   # FloatToInt64 truncates toward 0
        if pct_int > local_fc:
            local_fc = pct_int
            local_128 = k

    own_pct = float(state.g_SCPercent[own_power])

    # ── Phase 4a: draw / static-map request flags ─────────────────────────────
    # Decompile lines 821-876:
    #   local_fc >= 0x50(80) AND g_SCPercent[leading] > own_pct + 15  → draw
    #   local_fc >= 0x3c(60) AND g_SCPercent[leading] > own_pct + 25  → draw
    state.g_RequestDrawFlag = 0
    if local_128 != own_power:
        lead_pct = float(state.g_SCPercent[local_128])
        if local_fc >= 80 and lead_pct > own_pct + 15.0:
            state.g_RequestDrawFlag = 1
        elif local_fc >= 60 and lead_pct > own_pct + 25.0:
            state.g_RequestDrawFlag = 1
    if state.g_StaticMapFlag:
        state.g_RequestDrawFlag = 1

    # ── Phase 4b: near-victory enemy designation (local_fc > 0x3b = 59) ──────
    # Decompile lines 878-1090
    state.g_LeadingFlag = 0
    state.g_OtherPowerLeadFlag = 0
    state.g_NearVictoryPower = -1

    bVar26 = False  # keep-alliance override
    if local_fc > 59 and local_128 != own_power:
        lead_pct = float(state.g_SCPercent[local_128])
        # Keep-alliance condition (bVar26):
        #   trust_hi >= 0 AND (trust_hi > 0 OR trust_lo > 11)
        #   AND g_PowerExpScore[own] - g_PowerExpScore[leading] * 1.7 + 69 > 0
        #   AND g_InfluenceRankFlag[own][leading] in {1, 2}
        trust_hi_val = int(trust_hi_mat[own_power, local_128])
        trust_lo_val = int(state.g_AllyTrustScore[own_power, local_128])
        rank_flag = int(state.g_InfluenceRankFlag[own_power, local_128])
        exp_own = float(state.g_PowerExpScore[own_power])
        exp_lead = float(state.g_PowerExpScore[local_128])
        if (trust_hi_val >= 0
                and (trust_hi_val > 0 or trust_lo_val > 11)
                and (exp_own - exp_lead * 1.7 + 69.0) > 0.0
                and rank_flag in (1, 2)):
            bVar26 = True

        # Declare near-victory only if leading is actually ahead and no keep-alliance
        if lead_pct > own_pct and not bVar26:
            state.g_OtherPowerLeadFlag = 1
            state.g_NearVictoryPower = local_128
            # Set leading power as enemy; zero trust toward them
            state.g_EnemyFlag[local_128] = 1
            state.g_AllyTrustScore[own_power, local_128] = 0
            if hasattr(trust_hi_mat, '__setitem__'):
                trust_hi_mat[own_power, local_128] = 0
            # When local_fc >= 80: additionally zero trust *from* local_128 to all
            if local_fc >= 80:
                for p in range(num_powers):
                    if p != local_128:
                        state.g_AllyTrustScore[local_128, p] = 0
                        if hasattr(trust_hi_mat, '__setitem__'):
                            trust_hi_mat[local_128, p] = 0
            bVar26 = True  # signal "near-victory enemy selected"

    # ── LAB_0042ac27: post-enemy-selection routing ────────────────────────────
    # When g_OtherPowerLeadFlag==1: run near-victory weak-elim then JUMP TO END
    # (skips gang-up, distressed-ally, weak-elim, dominance, alliance-agreement)
    # When g_OtherPowerLeadFlag==0: run all remaining passes

    if state.g_OtherPowerLeadFlag:
        # ── Near-victory post-pass (decompile lines 1815–1924) ───────────────
        # When local_fc > 75 OR leading_pct <= own_pct OR own_pct > 20:
        #   If local_fc < 86 AND own_pct < leading_pct AND own_pct > 20:
        #     mark powers with sc < 2 as enemy ("1 SC even though power close to victory")
        # Else (local_fc <= 75 AND leading_pct > own_pct):
        #   mark powers with sc < 2 OR weak influence as enemy
        if local_128 != own_power:
            lead_pct = float(state.g_SCPercent[local_128])
            if local_fc > 75 or lead_pct <= own_pct or own_pct > 20.0:
                if local_fc < 86 and lead_pct > own_pct and own_pct > 20.0:
                    for p in range(num_powers):
                        if int(state.sc_count[p]) < 2:
                            state.g_EnemyFlag[p] = 1
                            state.g_AllyTrustScore[own_power, p] = 0
                            if hasattr(trust_hi_mat, '__setitem__'):
                                trust_hi_mat[own_power, p] = 0
            else:
                # local_fc <= 75 AND leading_pct > own_pct
                for p in range(num_powers):
                    sc_p = int(state.sc_count[p])
                    infl_own_p = float(state.g_InfluenceMatrix[own_power, p])
                    infl_p_own = float(state.g_InfluenceMatrix[p, own_power])
                    infl_raw_own_p = float(getattr(state, 'g_InfluenceMatrix_Raw',
                                                    state.g_InfluenceMatrix)[own_power, p])
                    infl_raw_p_p = float(getattr(state, 'g_InfluenceMatrix_Raw',
                                                  state.g_InfluenceMatrix)[p, p])
                    if (sc_p < 2
                            or (infl_own_p > 0.0 and p != own_power
                                and infl_raw_own_p / (infl_raw_p_p + 1.0) > 4.5
                                and infl_p_own > 10.0)):
                        state.g_EnemyFlag[p] = 1
                        state.g_AllyTrustScore[own_power, p] = 0
                        if hasattr(trust_hi_mat, '__setitem__'):
                            trust_hi_mat[own_power, p] = 0
        # goto LAB_0042bff2 — skip all remaining passes
        return  # early exit; function writes are complete

    # ── Phase 4c: normal enemy selection (LAB_00429317 branch) ───────────────
    # Simplified port; full decision tree has ~600 C lines.
    # Key paths implemented: opening-sticky, both-top-2-at-war, peacetime.
    if not bVar26:
        g_stabbed = int(getattr(state, 'g_StabbedFlag', 0))
        g_opening_sticky = int(getattr(state, 'g_OpeningStickyMode', 0))
        g_deceit = int(getattr(state, 'g_DeceitLevel', 0))
        g_opening_enemy = int(getattr(state, 'g_OpeningEnemy', -1))

        enemy_selected = False

        # Opening-sticky mode: keep fighting the designated opening enemy
        if g_opening_sticky == 1 and g_deceit < 3 and 0 <= g_opening_enemy < num_powers:
            state.g_EnemyFlag[g_opening_enemy] = 1
            state.g_AllyTrustScore[own_power, g_opening_enemy] = 0
            if hasattr(trust_hi_mat, '__setitem__'):
                trust_hi_mat[own_power, g_opening_enemy] = 0
            enemy_selected = True

        # Both top-2 at war with us (zero trust both ways) — peace-signal /
        # trust-history / random selection per decompile lines 1101-1223.
        t_hi_1 = int(trust_hi_mat[own_power, top_enemy_1])
        t_lo_1 = int(state.g_AllyTrustScore[own_power, top_enemy_1])
        t_hi_2 = int(trust_hi_mat[own_power, top_enemy_2])
        t_lo_2 = int(state.g_AllyTrustScore[own_power, top_enemy_2])
        both_zero = (t_hi_1 == 0 and t_lo_1 == 0
                     and t_hi_2 == 0 and t_lo_2 == 0
                     and top_enemy_2 != own_power)

        # g_RelationHistory (DAT_00634e90) is the "trust by history" score;
        # C tests DAT_00634e90[top_enemy_2] <= DAT_00634e90[top_enemy_1].
        rel_hist = getattr(state, 'g_RelationHistory', None)
        if rel_hist is not None:
            hist_1 = int(rel_hist[own_power, top_enemy_1])
            hist_2 = int(rel_hist[own_power, top_enemy_2])
        else:
            hist_1 = hist_2 = 0

        # Peace-channel state — prefer to fight the one NOT sending peace signals.
        # C reads DAT_004cf4c0/c4[p*2] as int64 pair; Python uses g_PeaceSignal
        # (per-pair) as a proxy — "peace signal received from other".
        peace_sig = getattr(state, 'g_PeaceSignal', None)
        def _peace_signal_from(p):
            if peace_sig is None or not (0 <= p < num_powers):
                return False
            return int(peace_sig[own_power, p]) != 0

        # C's "neutral-flag" pair check (DAT_0062b7b0[pow*21+other])
        neutral_flag = getattr(state, 'g_NeutralFlag', None)
        def _neutral(p):
            if neutral_flag is None or not (0 <= p < num_powers):
                return False
            return int(neutral_flag[own_power, p]) != 0

        if not enemy_selected and both_zero:
            # Decompile branch at line 1105: "We are at war with our top 2 enemies"
            if top_enemy_2 == own_power:
                state.g_EnemyFlag[top_enemy_1] = 1
                enemy_selected = True
            elif hist_2 <= hist_1:
                # Lines 1125-1196: peace-signal / random
                p1_peace = _peace_signal_from(top_enemy_1) and not _neutral(top_enemy_2)
                p2_peace = _peace_signal_from(top_enemy_2) and not _neutral(top_enemy_1)
                if p1_peace and not p2_peace:
                    # Target #1 sending peace signal → prefer #2 (avoid #1),
                    # but C's branch picks top_enemy_1 here (it's the one we
                    # just confirmed is "sending" so we fight it anyway).
                    # Reading the C carefully (line 1125-1137): if peace
                    # channel from #2 closed AND neutral on #1 → pick #1
                    # as enemy "because peace signal from enemy 2".
                    state.g_EnemyFlag[top_enemy_1] = 1
                elif p2_peace and not p1_peace:
                    state.g_EnemyFlag[top_enemy_2] = 1
                else:
                    # Random weighted selection (line 1163): rand()/0x17 % 100
                    import random as _random
                    r = _random.randint(0, 99)
                    if r < 50:
                        state.g_EnemyFlag[top_enemy_1] = 1
                    else:
                        state.g_EnemyFlag[top_enemy_2] = 1
                enemy_selected = True
            else:
                # hist_2 > hist_1 (we trust #2 less by history)
                state.g_EnemyFlag[top_enemy_1] = 1
                enemy_selected = True

        if not enemy_selected and (t_hi_1 == 0 and t_lo_1 == 0):
            state.g_EnemyFlag[top_enemy_1] = 1
            enemy_selected = True
        if not enemy_selected and (t_hi_2 == 0 and t_lo_2 == 0):
            state.g_EnemyFlag[top_enemy_2] = 1
            enemy_selected = True

        # Peace with top 3 — random weighted selection by alliance score
        # (decompile lines 1591-1714). Simplified: weight by (g_RelationHistory+
        # bias) across top_enemy_1..3 and pick via cumulative random draw.
        if not enemy_selected:
            import random as _random
            pool = [p for p in (top_enemy_1, top_enemy_2, top_enemy_3)
                    if p != own_power]
            if pool:
                weights = []
                for p in pool:
                    # Lower relation history / lower trust → higher weight as enemy
                    hist = int(rel_hist[own_power, p]) if rel_hist is not None else 0
                    t_lo = int(state.g_AllyTrustScore[own_power, p])
                    t_hi = int(trust_hi_mat[own_power, p])
                    # Baseline weight 100, penalty for positive trust/history
                    w = max(1, 100 - hist - (t_hi * 10 + t_lo))
                    weights.append(w)
                total_w = sum(weights)
                r = _random.randint(1, total_w)
                acc = 0
                for p, w in zip(pool, weights):
                    acc += w
                    if r <= acc:
                        state.g_EnemyFlag[p] = 1
                        enemy_selected = True
                        break

    # Opening best ally lookup (also used by gang-up and alliance-agreement)
    opening_best_ally = int(getattr(state, 'g_BestAllySlot0',
                                    getattr(state, 'g_OpeningBestAlly', -1)))

    # ── Gang-up logic (decompile lines 1470-1557, 1950-2060) ─────────────────
    # When we've committed to an enemy, check if a high-trust ally also has a
    # remaining top-feared power as *their* enemy — coordinate by redirecting
    # to the shared enemy.  C checks:
    #   - trust_hi[own, ally] > 0 OR trust_lo > 6   (high-trust ally)
    #   - ally != opening_best_ally                 (not a pass-through)
    #   - g_RankMatrix[target, own] < 2             (we're in their top-2 fear)
    #   - trust[ally, target] == 0                  (ally hostile to target)
    #   - g_InfluenceMatrix_Raw[target, own] / (raw[ally] + 1) > 1.0
    #
    # Simplified port: look for a high-trust ally among top3_feared whose own
    # relation with another top3_feared is hostile, then switch enemy to that
    # other power.
    g_infl_raw_gu = getattr(state, 'g_InfluenceMatrix_Raw', state.g_InfluenceMatrix)
    for ally in (top_enemy_1, top_enemy_2, top_enemy_3):
        if ally == own_power:
            continue
        ally_t_hi = int(trust_hi_mat[own_power, ally])
        ally_t_lo = int(state.g_AllyTrustScore[own_power, ally])
        # High-trust gate (hi>0 OR lo>6)
        if not (ally_t_hi > 0 or (ally_t_hi == 0 and ally_t_lo > 6)):
            continue
        if ally == opening_best_ally:
            # Don't redirect via opening ally (would burn opening selection)
            continue
        for target in (top_enemy_1, top_enemy_2, top_enemy_3):
            if target == own_power or target == ally:
                continue
            if state.g_EnemyFlag[target] != 0:
                continue  # already enemy
            # ally hostile to target (both trust words zero)
            ally_target_hi = int(trust_hi_mat[ally, target])
            ally_target_lo = int(state.g_AllyTrustScore[ally, target])
            if ally_target_hi != 0 or ally_target_lo != 0:
                continue
            # influence ratio gate: raw[target, own] / (raw[ally, ally] + 1) > 1
            try:
                ratio = (float(g_infl_raw_gu[target, own_power])
                         / (float(g_infl_raw_gu[ally, ally]) + 1.0))
            except (IndexError, ValueError):
                ratio = 0.0
            if ratio <= 1.0:
                continue
            # Rank-matrix gate: own is in target's top-2 feared
            if int(state.g_RankMatrix[target, own_power]) >= 2:
                continue
            # Gang-up fires: mark target enemy, clear ally trust toward target
            state.g_EnemyFlag[target] = 1
            state.g_AllyTrustScore[own_power, target] = 0
            if hasattr(trust_hi_mat, '__setitem__'):
                trust_hi_mat[own_power, target] = 0
            break  # one target per ally

    # ── LAB_0042b203: distressed-ally rescue (decompile lines 2077–2166) ──────
    # For each ally with g_AllyDistressFlag==1 that is not already an enemy:
    # If own trust toward top-1 or top-2 feared > 30 (in Hi word), look up
    # g_PowerProximityRank[ally][0] and [1]; if in own top-2/3 feared AND
    # g_RankMatrix[own][rank_neighbor] < 3 → set that neighbor as enemy.
    # NOTE: g_PowerProximityRank stride=0x14(20 bytes per power, 5 int32s per row).
    # Simplified: use own top3 as proxy for proximity rank.
    trust_threshold_hi = (
        int(trust_hi_mat[own_power, top_enemy_1]) > 30
        or int(trust_hi_mat[own_power, top_enemy_2]) > 30
    )
    for ally in range(num_powers):
        if (int(state.g_AllyDistressFlag[ally]) != 1
                or state.g_EnemyFlag[ally] != 0
                or not trust_threshold_hi):
            continue
        # Use g_PowerProximityRank[ally] — proxy via own top3 if unavailable
        prox_rank = getattr(state, 'g_PowerProximityRank', None)
        candidates = []
        if prox_rank is not None:
            # Access g_PowerProximityRank[ally][0] and [1] (stride 5 int32s per power)
            candidates = [int(prox_rank[ally, 0]), int(prox_rank[ally, 1])]
        else:
            candidates = [top_enemy_1, top_enemy_2]
        for neighbor in candidates:
            if not (0 <= neighbor < num_powers) or neighbor == own_power:
                continue
            if (neighbor in (top_enemy_2, top_enemy_3)  # in own top-2/3 feared
                    and int(state.g_RankMatrix[own_power, neighbor]) < 3):
                state.g_EnemyFlag[neighbor] = 1
                state.g_AllyTrustScore[own_power, neighbor] = 0
                if hasattr(trust_hi_mat, '__setitem__'):
                    trust_hi_mat[own_power, neighbor] = 0

    # ── Weak-elimination + SC-grab pass (decompile lines 2168–2283) ──────────
    g_deceit = int(getattr(state, 'g_DeceitLevel', 0))
    g_infl_raw = getattr(state, 'g_InfluenceMatrix_Raw', state.g_InfluenceMatrix)
    for p in range(num_powers):
        sc_p = int(state.sc_count[p])
        infl_own_p = float(state.g_InfluenceMatrix[own_power, p])
        infl_p_own = float(state.g_InfluenceMatrix[p, own_power])
        raw_own_p  = float(g_infl_raw[own_power, p])
        raw_p_own  = float(g_infl_raw[p, own_power])

        # Weak-elimination: g_DeceitLevel > 2 AND (sc < 3 OR high influence dominance)
        if g_deceit > 2 and (
                sc_p < 3 or (
                    infl_own_p > 0.0 and p != own_power
                    and raw_own_p / (raw_p_own + 1.0) > 4.5
                    and infl_p_own > 10.0
                )):
            state.g_EnemyFlag[p] = 1
            state.g_AllyTrustScore[own_power, p] = 0
            if hasattr(trust_hi_mat, '__setitem__'):
                trust_hi_mat[own_power, p] = 0

        # SC-grab: own_sc < 4 AND vulnerable unguarded SC (decompile lines
        # 2200-2276). C reads g_ContactWeighted (DAT_00b755cc) with ±21-int32
        # strides — interpretation as [own, p-1], [own, p], [own, p+1]
        # (adjacent-power contact counts). Proxy: use g_ContactWeighted row for
        # own_power, require prev/cur positive and next zero + target_sc > 3.
        if own_sc < 4 and p != own_power and sc_p > 3:
            cw = getattr(state, 'g_ContactWeighted', None)
            if cw is not None:
                p_prev = (p - 1) % num_powers
                p_next = (p + 1) % num_powers
                try:
                    if (int(cw[own_power, p_prev]) > 0
                            and int(cw[own_power, p]) > 0
                            and int(cw[own_power, p_next]) == 0):
                        state.g_EnemyFlag[p] = 1
                        state.g_AllyTrustScore[own_power, p] = 0
                        if hasattr(trust_hi_mat, '__setitem__'):
                            trust_hi_mat[own_power, p] = 0
                except (IndexError, ValueError):
                    pass

    # ── Dominance sweep (decompile lines 2284–2328) ───────────────────────────
    # MUST come after all per-power passes above.
    # DAT_00baed6a = 0 first (reset), then check condition.
    # Condition: g_SCPercent[own] > 75.0 AND own_pct - g_SCPercent[local_128] >= 2.0
    # (Note: uses local_128 not max_pct; uses >= not >)
    state.g_LeadingFlag = 0
    if local_128 != own_power:
        lead_pct_dominate = float(state.g_SCPercent[local_128])
        if own_pct > 75.0 and (own_pct - lead_pct_dominate) >= 2.0:
            state.g_LeadingFlag = 1
            for k in range(num_powers):
                if k != own_power:
                    state.g_EnemyFlag[k] = 1
                    state.g_AllyTrustScore[own_power, k] = 0
                    if hasattr(trust_hi_mat, '__setitem__'):
                        trust_hi_mat[own_power, k] = 0

    # ── Alliance-agreement → enemy (decompile lines 2329–2403) ──────────────
    # Honor ally's declared enemies; conditions (decompile lines 2356–2363):
    #   g_EnemyFlag[pow_b] == 0 (not yet enemy)
    #   auStack_dc[pow_a + 1] == 0  (pow_a has no prior alliance enforcement)
    #   g_AllyMatrix[own][pow_b] == 1  (own allied with pow_b)
    #   DAT_004c6bc4 != pow_b  (pow_b is not opening best ally)
    #   g_AllyTrustScore_Hi[own][pow_b] < 1 AND (Hi<0 OR Lo<2)  (low trust)
    # opening_best_ally defined above (shared with gang-up)
    # Track which pow_a rows have already set an enemy (auStack_dc equivalent)
    pow_a_enforced = [False] * num_powers
    for pow_a in range(num_powers):
        for pow_b in range(num_powers):
            if pow_a_enforced[pow_a]:
                continue
            t_hi_b = int(trust_hi_mat[own_power, pow_b])
            t_lo_b = int(state.g_AllyTrustScore[own_power, pow_b])
            if (state.g_EnemyFlag[pow_b] == 0
                    and int(state.g_AllyMatrix[pow_a, pow_b]) == 1
                    and int(state.g_AllyMatrix[own_power, pow_b]) == 1
                    and pow_b != opening_best_ally
                    and t_hi_b < 1 and (t_hi_b < 0 or t_lo_b < 2)):
                state.g_EnemyFlag[pow_b] = 1
                state.g_AllyTrustScore[own_power, pow_b] = 0
                if hasattr(trust_hi_mat, '__setitem__'):
                    trust_hi_mat[own_power, pow_b] = 0
                pow_a_enforced[pow_a] = True

    # NOTE 2026-04-14: C CAL_BOARD does not call UpdateRelationHistory.
    # That call was spurious — removed. UpdateRelationHistory is invoked
    # from FRIENDLY (communications.friendly Phase 2) and HOSTILITY
    # (bot._hostility Block 6, pending wire-in).


def update_relation_history(state) -> None:
    """
    Deprecated shim — delegates to ``communications._update_relation_history``.

    Removed 2026-04-14: the prior sqrt-based implementation had a dead-code bug
    (``if current < floor`` where ``floor = sqrt(current)`` is always ≤ current
    for current ≥ 1, so the floor was never applied). The canonical port lives
    in ``communications._update_relation_history`` and is called from
    ``friendly()`` Phase 2; HOSTILITY Block 6 also calls it (wired 2026-04-14).
    """
    from albert.communications import _update_relation_history
    _update_relation_history(state)


# ── ComputeInfluenceMatrix / NormalizeInfluenceMatrix ────────────────────────

def compute_influence_matrix(state: InnerGameState, own_power: int = 0) -> None:
    """
    Port of ComputeInfluenceMatrix (FUN_0040d8c0).

    All 6 phases from the decompile (decompiled.txt):
      Phase 1 — trust-adjust g_InfluenceMatrix_Raw → g_InfluenceMatrix
      Phase 2 — per-power row-sum via PackScoreU64 (banker's-round int64)
      Phase 3 — add _safe_pow noise: cell += pow(cell/(col_sum+1), 0.3) * 500
      Phase 4 — row-normalise each row to sum = 100
      Phase 5 — initialise g_AllyPrefRanking / g_InfluenceRankFlag
      Phase 6 — selection-sort to build ranked alliance preference list
    """
    num_powers = 7

    # Phase 1 — trust-adjust raw matrix
    # own_power row/col: copy raw directly (no scaling)
    # other pairs: trust_hi<0 OR (trust_hi<1 AND trust_lo<6) → divide by (trust_lo+1)
    #              otherwise (confirmed ally) → divide by 6.0
    for row in range(num_powers):
        for col in range(num_powers):
            raw = float(state.g_InfluenceMatrix_Raw[row, col])
            if row == own_power or col == own_power:
                state.g_InfluenceMatrix[row, col] = raw
            else:
                trust_hi = int(state.g_AllyTrustScore_Hi[row, col])
                trust_lo = int(state.g_AllyTrustScore[row, col])
                if trust_hi < 0 or (trust_hi < 1 and trust_lo < 6):
                    divisor = trust_lo + 1
                    state.g_InfluenceMatrix[row, col] = raw / divisor if divisor != 0 else raw
                else:
                    state.g_InfluenceMatrix[row, col] = raw / 6.0

    # Phase 2 — per-power row sum (PackScoreU64 = trunc toward zero, not banker's round;
    # FRNDINT is intermediate, correction code always restores truncation)
    power_sum = np.array(
        [int(float(np.sum(state.g_InfluenceMatrix[p]))) for p in range(num_powers)],
        dtype=np.int64,
    )

    # Phase 3 — noise injection: cell += _safe_pow(cell / (col_sum+1), 0.3) * 500
    for row in range(num_powers):
        for col in range(num_powers):
            col_sum = float(power_sum[col])
            base = float(state.g_InfluenceMatrix[row, col]) / (col_sum + 1.0)
            state.g_InfluenceMatrix[row, col] += _safe_pow(base, 0.3) * 500.0

    # Phase 4 — row-normalise to 100
    for row in range(num_powers):
        row_sum = float(np.sum(state.g_InfluenceMatrix[row]))
        if row_sum != 0.0:
            state.g_InfluenceMatrix[row] = (state.g_InfluenceMatrix[row] * 100.0) / row_sum

    # Phase 5 — init ranking arrays
    # All g_AllyPrefRanking slots initialised to own_power sentinel (per decompile)
    state.g_AllyPrefRanking.fill(own_power)
    state.g_InfluenceRankFlag.fill(-1)
    np.fill_diagonal(state.g_InfluenceRankFlag, -2)  # self = skip

    # Phase 6 — selection-sort to build ranked list (1-indexed ranks 1..numPowers-1)
    for p in range(num_powers):
        for rank in range(1, num_powers):
            best_col = -1
            best_val = -1.0
            for col in range(num_powers):
                if state.g_InfluenceRankFlag[p, col] == -1:  # unranked
                    val = float(state.g_InfluenceMatrix[p, col])
                    if val > best_val:
                        best_val = val
                        best_col = col
            if best_col == -1:
                break
            state.g_InfluenceRankFlag[p, best_col] = rank
            if rank < 5:
                state.g_AllyPrefRanking[p, rank] = best_col


def normalize_influence_matrix(state: InnerGameState) -> None:
    """
    Port of the row-normalisation step (Phase 4 of ComputeInfluenceMatrix).

    Normalises each row of g_InfluenceMatrix so it sums to 100.0.
    Research.md §4292 Phase 4.
    """
    num_powers = 7
    for row in range(num_powers):
        row_sum = float(np.sum(state.g_InfluenceMatrix[row]))
        if row_sum != 0.0:
            state.g_InfluenceMatrix[row] = (state.g_InfluenceMatrix[row] * 100.0) / row_sum


# ── ScoreProvinces ────────────────────────────────────────────────────────────

def score_provinces(state: InnerGameState,
                    move_weight: float,   # noqa: ARG001 – reserved for future weighting
                    build_weight: float,  # noqa: ARG001 – reserved for future weighting
                    own_power: int) -> None:
    """
    Port of ScoreProvinces (FUN_00447460).

    Per-trial Monte Carlo scoring kernel.  Iterates all powers, builds a
    reachability matrix from the unit list, applies trust-gated scoring, and
    fills the per-power candidate ordered sets used by order selection.

    Parameters mirror the C signature:
        (Albert *this, uint64 move_weight, uint64 build_weight)

    Research.md §2597.
    """
    num_powers = 7
    num_provinces = 256

    # Section 1 — zero 11 per-power-province tables
    state.g_OwnReachScore.fill(0)       # g_OwnReachScore   DAT_0058f8e8
    state.g_AllyReachScore.fill(0)      # g_AllyReachScore  DAT_005658e8
    state.g_EnemyReachScore.fill(0)     # g_EnemyReachScore DAT_00535ce8
    state.g_TotalReachScore.fill(0)     # g_TotalReachScore DAT_0052b4e8
    state.g_ThreatLevel.fill(0)         # g_ThreatScore     DAT_005460e8
    state.g_ConvoyReachCount.fill(0)    # g_ConvoyReachCount DAT_005850e8
    state.g_EnemyMobilityCount.fill(0)  # g_EnemyMobilityCount DAT_0057a8e8
    state.g_SCOwnership.fill(0)         # g_SCOwnership     DAT_00520ce8
    state.g_CoverageFlag.fill(0)        # g_CoverageFlag
    state.g_MaxProvinceScore.fill(0)
    state.g_MinScore.fill(1_000_000)    # g_MinScore sentinel

    # Friendly/unit-presence flags (new in this pass)
    g_FriendlyUnitFlag = np.zeros(num_provinces, dtype=np.int32)
    g_UnitPresence     = np.zeros(num_provinces, dtype=np.int32)

    # Section 2 — build reachability matrix from unit list
    # reachability[province][power] = units of power that can reach province
    reachability = np.zeros((num_provinces, num_powers), dtype=np.int32)

    for prov, info in state.unit_info.items():
        power = info['power']
        adj = state.get_unit_adjacencies(prov)
        seen = set()
        for a in adj:
            if a not in seen:
                reachability[a, power] += 1
                state.g_CoverageFlag[power, a] += 1
                seen.add(a)
        reachability[prov, power] += 1
        state.g_CoverageFlag[power, prov] += 1

    # Section 3 — per-unit presence flags.
    #
    # g_SCOwnership fix 2026-04-14: C populates g_SCOwnership[unit.power, prov]
    # for every unit across all powers (ScoreProvinces.c:781-787, inside the
    # outer-power loop, each iteration only writes its own power's row but
    # over the full outer-loop sweep every power gets its units marked).
    # The previous port only set own_power's row, leaving other powers' rows
    # at zero after Section 1's fill(0).  This broke any consumer that reads
    # `np.sum(g_SCOwnership[p])` for p != own_power — most visibly
    # Adjustment 8's owner_scs check and any SC-count-based heuristic.
    for prov, info in state.unit_info.items():
        power = info['power']
        state.g_SCOwnership[power, prov] = 1
        if power == own_power:
            continue
        trust = float(state.g_AllyTrustScore[own_power, power])
        if trust < 0:
            g_UnitPresence[prov] = 1
        else:
            g_FriendlyUnitFlag[prov] = 1

    # Section 4 — per-power outer loop: alliance-gated reach → scored tables
    for outer_power in range(num_powers):
        for prov in range(num_provinces):
            for inner_power in range(num_powers):
                reach = int(reachability[prov, inner_power])
                if reach == 0:
                    continue

                trust_lo = float(state.g_AllyTrustScore[outer_power, inner_power])
                # g_AllyHistoryCount = g_RelationScore (DAT_00634e90);
                # fixed 2026-04-14 — previously hardcoded to 0.
                history = int(state.g_RelationScore[outer_power, inner_power])

                if inner_power == outer_power:
                    if trust_lo == 0:
                        state.g_OwnReachScore[outer_power, prov] = reach
                else:
                    # Threat (best enemy reach)
                    if reach > state.g_ThreatLevel[outer_power, prov]:
                        if (trust_lo == 0 and history == 0) or history < 10 or trust_lo >= 0:
                            state.g_ThreatLevel[outer_power, prov] = reach

                    # Ally reach (trust > 0 or established history)
                    if trust_lo > 0 or history > 3:
                        state.g_AllyReachScore[outer_power, prov] += reach

                    # Enemy reach (uncertain trust)
                    if trust_lo <= 0:
                        state.g_EnemyReachScore[outer_power, prov] += reach

                    state.g_TotalReachScore[outer_power, prov] += reach

        # Section 4b — occupation scoring init
        for prov, info in state.unit_info.items():
            if info['power'] == outer_power:
                weight = 1 if state.g_OtherPowerLeadFlag else 5
                # g_ProvinceScore2 approximated via g_AttackCount
                state.g_AttackCount[outer_power, prov] = float(weight)

        # Section 4e — convoy/mobility counts (C: uncertain-trust fleet gate)
        # Updated 2026-04-14: adds the `g_AllyTrustScore < 1 AND < 0` test
        # (uncertain-trust fleet) that gates the 2-hop expansion in C. Prior
        # port expanded through every adjacency, over-counting by ~4x.
        for prov, info in state.unit_info.items():
            for adj in state.get_unit_adjacencies(prov):
                adj_power = state.get_unit_power(adj)
                if adj_power == -1:
                    continue
                # C gate: the unit at `adj` must be a fleet of uncertain trust.
                # Uncertain ≈ trust score unknown (< 1) AND hi-word < 0.
                trust_lo = float(state.g_AllyTrustScore[outer_power, adj_power])
                trust_hi = int(state.g_AllyTrustScore_Hi[outer_power, adj_power])
                if not (trust_lo < 1 and trust_hi < 0):
                    continue
                # Filter to fleet units only (C calls AdjacencyList_FilterByUnitType)
                if state.get_unit_type(adj) != 'F':
                    continue
                for adj2 in state.get_unit_adjacencies(adj):
                    if (g_UnitPresence[prov] == 1
                        and state.g_SCOwnership[own_power, adj2] == 0):
                        state.g_ConvoyReachCount[own_power, adj2] += 1
                    if info['power'] != own_power:
                        state.g_EnemyMobilityCount[own_power, adj2] += 1

        # Section 4h — province score assignment (main scoring pass)
        # Updated 2026-04-14: now runs for every `outer_power` (not just
        # `own_power`), mirroring C's per-power iteration. This populates
        # g_AttackCount[power, prov] for all powers, giving Albert a
        # per-opponent view of province priorities.
        #
        # Extended 2026-04-14 (pass 3): all 8 Section 4h post-adjustments
        # from ScoreProvinces.c lines 1000-1228 now ported:
        #   (1) home-center + has_adj_enemy clamp          → 80 / 150
        #   (2) ally territory /3 or zero                   → 0 or score/3
        #   (3) influence ratio boost (>0.95, near_end<3)   → 10
        #   (4) opening target match (score==0)             → 150
        #   (5) non-home-center unit-owner score            → 10 or 1
        #   (6) late-game trusted-ally suppression          → 0
        #   (7) free-province neighbor-SC heuristic         → 75 / 75·trust⁻¹
        #   (8) WIN sticky + SC-count bump                  → 5 ± 20/5
        # Symbol mappings (from GlobalDataRefs.md):
        #   DAT_00b85768 → g_PressMatrix, DAT_00b85710 → g_PressCount,
        #   DAT_004d2e14 → g_AllyDesignation_A hi-word,
        #   g_OpeningStickyMode already in state.
        # Remaining divergence: 10-round BFS propagation (C 492-638)
        # seeds +0x361c with AttackCount * DAT_006040ec and smooths 10
        # rounds.  Python populates g_CandidateScores from a 5-round
        # BFS on own-unit presence (apply_influence_scores, Phase 1f) —
        # different seed, rounds, and kernel.  Impact is low: WIN
        # phases overwrite g_CandidateScores, and non-WIN consumers
        # only use it as a boolean membership gate.  Re-audit
        # 2026-04-14 confirmed no value-level consumer in non-WIN
        # paths, so porting the C BFS would change boolean membership
        # at the edges but not any currently-read score value.

        # Precompute once per outer_power: does any non-home-center alive
        # province hold a unit of a different power?  (C local_5581 flag,
        # set at ScoreProvinces.c:963-972.)
        home = state.home_centers.get(outer_power, frozenset())
        has_adj_enemy = False
        for alive_prov in state.unit_info.keys():
            if alive_prov in home:
                continue
            uowner_a = state.get_unit_power(alive_prov)
            if uowner_a != -1 and uowner_a != outer_power:
                has_adj_enemy = True
                break

        near_end = float(state.g_NearEndGameFactor)

        # Broadened 2026-04-14 (pass 2) to all 256 provinces — matches C's
        # per-alive-province iteration (ScoreProvinces.c:982-991) so that
        # Adjustments 4 (opening target) and 5/6 (unit-owner branch) can
        # fire on provinces that are neither SC-owned nor unit-occupied
        # by outer_power.
        for prov in range(num_provinces):
            score = float(evaluate_province_score(state, prov, outer_power))

            is_home_center = prov in home
            uowner_here = (state.get_unit_power(prov)
                           if prov in state.unit_info else -1)

            # Adjustment 1 — home-center / non-home-center clamp.
            # C 1006-1021: if home center AND score != 0 AND has_adj_enemy → 80.
            # C 1014-1021: else if score > 15 AND has_adj_enemy           → 150.
            if is_home_center:
                if score != 0.0 and has_adj_enemy:
                    score = 80.0
            else:
                if score > 15.0 and has_adj_enemy:
                    score = 150.0

            # Adjustment 2 — ally territory /3 or zero (C 1022-1042).
            # Home center occupied by a trusted ally (trust > 4) with
            # matching g_AllyDesignation_A booking: zero out if no threat,
            # else divide by 3.  DAT_004d2e14 is the hi-word of the int64
            # g_AllyDesignation_A pair (GlobalDataRefs.md:23 — cross-paired
            # with DAT_004d0e10); in Python the int64 is stored whole, so
            # equality on the signed value subsumes the C two-word check.
            if (is_home_center and uowner_here != -1
                    and uowner_here != outer_power):
                trust_lo_a = float(state.g_AllyTrustScore[outer_power, uowner_here])
                trust_hi_a = int(state.g_AllyTrustScore_Hi[outer_power, uowner_here])
                trusted_ally = (trust_hi_a >= 0
                                and (trust_hi_a > 0 or trust_lo_a > 4))
                if (trusted_ally
                        and int(state.g_AllyDesignation_A[prov]) == uowner_here):
                    threat = int(state.g_ThreatLevel[outer_power, prov])
                    if threat <= 0:
                        score = 0.0
                    else:
                        score = score / 3.0

            # Adjustment 3 — influence ratio boost (C 1043-1047).
            # DAT_00b76a28 is indexed by (prov + power*0x40); maps to
            # state.g_InfluenceRatio[outer_power, prov].
            if (score == 0.0 and near_end < 3.0
                    and hasattr(state, 'g_InfluenceRatio')
                    and float(state.g_InfluenceRatio[outer_power, prov]) > 0.95):
                score = 10.0

            # Adjustment 4 — opening target match (C 1081-1084).
            # Only applies when province has no unit; C reaches this branch
            # via the unowned (uVar2 == 0x14) path.
            if (score == 0.0 and uowner_here == -1
                    and hasattr(state, 'g_OpeningTarget')
                    and int(state.g_OpeningTarget[outer_power]) == prov):
                score = 150.0

            # Adjustment 7 — free-province neighbor-SC heuristic (C 1086-1148).
            # Unoccupied province, no opening-target match: score driven by
            # max 75/trust across other powers that have press-matrix
            # presence at this province.  g_PressMatrix (DAT_00b85768) is
            # bool[pow, prov]; g_PressCount (DAT_00b85710) is int[pow].
            if (not is_home_center and uowner_here == -1
                    and hasattr(state, 'g_PressMatrix')
                    and hasattr(state, 'g_PressCount')):
                opening_match = (hasattr(state, 'g_OpeningTarget')
                                 and int(state.g_OpeningTarget[outer_power]) == prov)
                if not (opening_match and score == 150.0):
                    # Check if any non-outer power has presence here.
                    any_presence = any(
                        p != outer_power and int(state.g_PressMatrix[p, prov]) > 0
                        for p in range(num_powers)
                    )
                    if not any_presence:
                        score = 75.0  # 0x4b — default
                    else:
                        own_here = int(state.g_PressMatrix[own_power, prov]) > 0
                        best = 0.0
                        capped = False
                        for p in range(num_powers):
                            if p == outer_power:
                                continue
                            if int(state.g_PressMatrix[p, prov]) <= 0:
                                continue
                            tlo = float(state.g_AllyTrustScore[outer_power, p])
                            thi = int(state.g_AllyTrustScore_Hi[outer_power, p])
                            uncertain_p = (thi < 1 and (thi < 0 or tlo < 2))
                            if uncertain_p:
                                capped = True
                                break
                            if own_here and int(state.g_PressCount[p]) > 1:
                                capped = True
                                continue
                            if tlo <= 0:
                                capped = True
                                continue
                            ratio = 100.0 / tlo
                            if ratio > best:
                                best = 75.0 / tlo
                        score = 75.0 if capped else best

            # Adjustment 5 — non-home-center unit owner score (C 1150-1161).
            # Occupied-by-other-power path: trust-uncertain → 10, ally → 1.
            # Gated on `not is_home_center` — the home-center branch in C
            # (Adjustments 1 & 2) owns the home-center occupied case.
            if (not is_home_center and uowner_here != -1
                    and uowner_here != outer_power):
                trust_lo = float(state.g_AllyTrustScore[outer_power, uowner_here])
                trust_hi = int(state.g_AllyTrustScore_Hi[outer_power, uowner_here])
                uncertain = (trust_hi < 0
                             or (trust_hi < 1 and trust_lo < 2))
                score = 10.0 if uncertain else 1.0

                # Adjustment 8 — WIN sticky + SC-count bump (C 1162-1199).
                # Fires when outer_power owns > 2 supply centres.
                own_scs = int(np.sum(state.g_SCOwnership[outer_power]))
                if own_scs > 2:
                    deceit = int(getattr(state, 'g_DeceitLevel', 0))
                    sticky = int(getattr(state, 'g_OpeningStickyMode', 0))
                    season = getattr(state, 'g_season', 'SPR')
                    if (deceit < 2 and outer_power == own_power
                            and season == 'WIN' and sticky == 1
                            and not uncertain):
                        score = 5.0
                    # (else branch would call PackScoreU64 — left as current
                    #  `score` per user filter on RNG/FP parity.)
                    # Neighbor SC-count bump.
                    owner_scs = int(np.sum(state.g_SCOwnership[uowner_here]))
                    wt = int(getattr(state, 'win_threshold', 18)) or 18
                    if owner_scs < 2:
                        score += 20.0
                    elif (owner_scs * 100) // wt > 12:
                        score += 5.0

                # Adjustment 6 — late-game trusted-ally suppression
                # (C 1203-1207).  Nested inside Adjustment 5's branch.
                if (near_end > 5.0 and trust_hi >= 0
                        and (trust_hi > 0 or trust_lo > 10)):
                    score = 0.0

            state.g_AttackCount[outer_power, prov] = score
            # max-accumulate — only track global max from own_power's
            # perspective (C mirrors this via the Albert-specific max
            # tracker in Phase 5).
            if outer_power == own_power and score > state.g_MaxProvinceScore[prov]:
                state.g_MaxProvinceScore[prov] = score


# ── ScoreOrderCandidates: candidate-vs-press corroboration penalty ───────────
#
# Port of Source/ScoreOrderCandidates.c lines 342–630 — the matching/penalty
# pass that runs AFTER ProcessTurn has populated g_CandidateRecordList and
# AFTER score_order_candidates_from_broadcast has populated g_GeneralOrders /
# g_AllianceOrders from the inbound DAIDE press.
#
# Semantics (collapsed from the four nested loops in C):
#   For each candidate at province V where V holds a unit AND that unit's
#   power has any received-press orders (i.e. local_3fc[power] non-empty in
#   C, equivalently state.g_GeneralOrders[power] non-empty in Python):
#     scan received-press orders for that power; if NONE references V as
#     either the unit-province or the support/convoy target, the candidate
#     is considered to disagree with announced press → mark
#       record['type_flag'] = 1
#       record['score']     = -2.5e36  (C: 0xff676980 = -2.5e36 as float)
#     This makes MC's downstream selector skip the candidate.
#
# The full C version distinguishes local_3fc (general XDO), local_204 (own
# alliance XDO), local_300 (SUP-MTO), local_108 (SUP-HLD) and routes the
# match through GameBoard_GetPowerRec to skip already-committed orders.
# That granularity is collapsed here because:
#   (a) g_GeneralOrders is the union local_3fc∪local_300∪local_108 keyed by
#       proposer power — already populated by score_order_candidates_from_broadcast.
#   (b) g_AllianceOrders is the local_204 analogue — same writer.
#   (c) The "already on board" gate (puVar8[1] != iVar18) is implicit in
#       Python because g_board_orders is consulted separately by the MC
#       dispatch path; double-penalising committed orders is harmless since
#       MC doesn't re-pick them.

_PRESS_DISAGREE_PENALTY: float = -2.5e36   # C: 0xff676980 reinterpreted as f32


def apply_press_corroboration_penalty(state: InnerGameState) -> int:
    """
    Penalise g_CandidateRecordList entries whose orders disagree with
    received-press orders for the same province/unit-power.  Returns the
    number of candidates penalised.

    Mirrors the post-ProcessTurn matching pass in
    Source/ScoreOrderCandidates.c (lines 342–630), collapsed to operate
    over the already-populated g_GeneralOrders / g_AllianceOrders maps
    rather than re-staging them into per-province RB-trees.
    """
    received_general: dict = getattr(state, 'g_GeneralOrders', {}) or {}
    received_alliance: dict = getattr(state, 'g_AllianceOrders', {}) or {}
    candidates: list = getattr(state, 'g_CandidateRecordList', []) or []
    if not candidates or (not received_general and not received_alliance):
        return 0

    # Build per-power province-mention sets from received press orders.
    # An order "mentions" a province if the province appears as either the
    # unit's source, an MTO/CTO destination, a SUP/CVY target unit, or a
    # SUP/CVY destination.  This is the union of the four staging trees in C.
    #
    # _parse_xdo_body_to_order stores province NAMES (e.g. "LON") in the
    # 'unit'/'target'/'target_unit'/'target_dest' fields, while candidate
    # records use integer province IDs.  Translate via state.prov_to_id so
    # both halves speak the same vocabulary.
    prov_to_id: dict = getattr(state, 'prov_to_id', {}) or {}

    def _name_to_id(s):
        # Accepts either an int (already an ID), a "U PROV" unit string, or
        # a bare province name.  Returns int or None.
        if isinstance(s, int):
            return s
        if not isinstance(s, str):
            return None
        # Unit strings carry the unit type prefix: "A LON" / "F NTH".
        if len(s) >= 3 and s[1] == ' ':
            s = s[2:]
        return prov_to_id.get(s)

    def _mentioned_provs(order_seq: dict) -> set:
        out = set()
        for k in ('source', 'unit_prov', 'province', 'unit'):
            pid = _name_to_id(order_seq.get(k))
            if pid is not None:
                out.add(pid)
        for k in ('dest', 'target', 'target_unit', 'target_dest',
                  'convoy_leg0', 'convoy_leg1', 'convoy_leg2'):
            pid = _name_to_id(order_seq.get(k))
            if pid is not None:
                out.add(pid)
        return out

    press_by_power: dict = {}
    for source in (received_general, received_alliance):
        for power_idx, order_list in source.items():
            bucket = press_by_power.setdefault(int(power_idx), set())
            for entry in order_list or []:
                if not isinstance(entry, dict):
                    continue
                # order_seq is stored either nested under 'order_seq' (if the
                # caller wrapped it) or flat (the score_order_candidates_from_
                # broadcast writer appends the order dict directly).
                seq = entry.get('order_seq', entry)
                if isinstance(seq, dict):
                    bucket |= _mentioned_provs(seq)

    if not press_by_power:
        return 0

    penalised = 0

    # Python's g_CandidateRecordList differs structurally from C's: the C list
    # is one record per (power, province, ordered-action), whereas Python
    # collapses each ProcessTurn trial into a single whole-power candidate
    # `{'power': p, 'orders': [(prov, order_type, dest, dest_coast, secondary), ...]}`.
    # To preserve C's "candidate at V disagrees with announced press" semantics
    # under that collapse, walk each candidate's orders and penalise the whole
    # trial if ANY of its unit-provinces falls outside the press-mentioned set
    # for the candidate's own power.  Press from OTHER powers can never trigger
    # the penalty because a candidate of P only carries P's own orders.
    for record in candidates:
        # Already penalised on a prior pass — don't double-count.
        if record.get('type_flag', 0) == 1:
            continue
        power_idx = record.get('power')
        if power_idx is None:
            continue
        bucket = press_by_power.get(int(power_idx))
        if not bucket:
            # No press from this power → C's local_3fc[power] empty branch:
            # corroboration is vacuously satisfied; do not penalise.
            continue
        orders = record.get('orders') or []
        # Each entry is (prov, order_type, dest_prov, dest_coast, secondary).
        # The unit's province is the first element.
        disagrees = False
        for o in orders:
            try:
                prov = int(o[0]) if not isinstance(o, int) else int(o)
            except (TypeError, IndexError, ValueError):
                continue
            if prov not in bucket:
                disagrees = True
                break
        if disagrees:
            record['type_flag'] = 1
            record['score'] = _PRESS_DISAGREE_PENALTY
            penalised += 1

    return penalised


# ── ScoreOrderCandidates_OwnPower ─────────────────────────────────────────────

def score_order_candidates_own_power(state: InnerGameState,
                                     weight_vector: list,
                                     own_power: int) -> None:
    """
    Port of ScoreOrderCandidates_OwnPower (FUN_004498d0).

    Scores order candidates for own power only (lighter than the all-powers
    version).  Three passes: dot-product, normalise + max-accumulate,
    army dithering.

    Research.md §1624.
    """
    import random as _random

    num_provinces = 256

    # Pass 1 — dot product of weight_vector × candidate ordered sets
    local_max = 0.0
    scores: dict = {}

    for prov in range(num_provinces):
        if not state.CandidateSet_contains(own_power, prov):
            continue
        score = 0.0
        for i, w in enumerate(weight_vector[:10]):
            score += w * state.get_candidate_score(own_power, prov, i)
        # add base province score
        score += float(state.g_AttackCount[own_power, prov]) * float(weight_vector[0]) \
                 if weight_vector else 0.0
        scores[prov] = score
        if score > local_max:
            local_max = score

    if local_max <= 0.0:
        local_max = 1.0

    # Pass 2 — normalise to [0, 1000] + max-accumulate into g_MaxProvinceScore
    for prov, score in scores.items():
        normalized = int(score * 1000 / local_max)
        scores[prov] = normalized
        if normalized > state.g_MaxProvinceScore[prov]:
            state.g_MaxProvinceScore[prov] = float(normalized)

    # Pass 3 — army dithering: armies below global max get randomized
    for prov, normalized in scores.items():
        if state.get_unit_type(prov) == 'A':
            if normalized < state.g_MaxProvinceScore[prov]:
                scores[prov] = _random.randint(0, 2 ** 32 - 1)

    # Write back into g_CandidateScores for own power
    for prov, val in scores.items():
        state.g_CandidateScores[own_power, prov] = float(val)


# ── WIN build/remove pipeline ─────────────────────────────────────────────────
#
# Weight constants read from the Albert object at runtime (stored as int64 pairs
# at 8-byte stride).  Confirmed from research.md BotObject offset table.
#   REMOVE vector at Albert+0x4e00 stride 8: [50, 70, 100, 70, 10, 5, 3, 2, 1]
#   BUILD  vector at Albert+0x4e58 stride 8: [100, 90, 70, 40, 20, 10, 5, 3, 2]
_WIN_REMOVE_WEIGHTS: list = [50, 70, 100, 70, 10, 5, 3, 2, 1]
_WIN_BUILD_WEIGHTS:  list = [100, 90, 70, 40, 20, 10, 5, 3, 2]
# SPR/FAL movement-phase weights.  C stores these at Albert+0x4d38 (SPR/SUM)
# and Albert+0x4d98 (FAL/AUT) as 10 int64 values.  The Python
# get_candidate_score always returns the same value regardless of iteration
# index (simplified fallback), so the individual weights don't matter as
# much as their relative scale.  Values below are inferred from the WIN
# weight patterns and the C binary's tournament-calibrated defaults.
_SPR_FAL_WEIGHTS: list = [100, 80, 60, 40, 20, 10, 5, 3, 2, 1]

# DAIDE short power names (index matches power_idx 0-6: AUS…TUR).
_WIN_DAIDE_POWER_NAMES: list = ['AUS', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']


def populate_build_candidates(state: InnerGameState, own_power: int) -> None:
    """Seed g_CandidateScores[own_power] with eligible WIN build provinces.

    Mirrors the candidate-ordered-set population that FUN_0040ab10
    (`ComputeBuildDelta`) performs for the BUILD branch
    (unit_count < sc_count).  In the C code `ComputeBuildDelta` is called
    from the ParseNOW WIN-season path; in the Python rewrite the WIN
    build/remove pipeline is driven directly from
    `generate_and_submit_orders` (bot.py) after `synchronize_from_game`.  A province is eligible when:
      • it is one of own_power's home supply centres  (state.home_centers)
      • own_power currently owns it                   (g_SCOwnership[own,prov]==1)
      • no unit currently stands there                (prov not in unit_info)

    Baseline score 1.0 marks membership; score_order_candidates_own_power
    will overwrite with the weighted dot-product in Pass 1.

    C: candidate set lives at Albert+own_power*0x78+0x361c; count stored at
    Albert+0x4e50; limit (delta) at Albert+0x4e54.
    """
    state.g_CandidateScores[own_power].fill(0.0)
    home_provs = state.home_centers.get(own_power, frozenset())
    for prov in home_provs:
        if state.g_SCOwnership[own_power, prov] == 1 and prov not in state.unit_info:
            state.g_CandidateScores[own_power, prov] = 1.0


def populate_remove_candidates(state: InnerGameState, own_power: int) -> None:
    """Seed g_CandidateScores[own_power] with eligible WIN remove provinces.

    Mirrors FUN_0040ab10 for the REMOVE branch (unit_count > sc_count).
    Every province that holds an own unit is a candidate.

    C: candidate set lives at Albert+own_power*0x78+0x361c; count at
    Albert+0x4df8; limit (delta) at Albert+0x4dfc.
    """
    state.g_CandidateScores[own_power].fill(0.0)
    for prov, unit_data in state.unit_info.items():
        if unit_data.get('power') == own_power:
            state.g_CandidateScores[own_power, prov] = 1.0


def compute_win_builds(state: InnerGameState, delta: int) -> None:
    """Port of FUN_00442040 — select top `delta` build candidates and emit BLD orders.

    Called from send_GOF when unit_count < sc_count (BUILD phase).

    Algorithm:
      1. Collect all provinces where g_CandidateScores[own_power, prov] > 0.
      2. Sort by score descending (highest strategic value first).
      3. Take up to `delta` provinces; any shortfall becomes waives.
      4. For each selected province determine unit type:
           FLT — if province is coastal (any adjacent province is a water province).
           AMY — otherwise (inland).
         Type-determination chain (confirmed by FUN_00461010 decompile):
           FUN_00442040 outer loop calls UnitList_FindOrInsert(inner+0x2450, prov)
           which creates the unit record and sets type at node+20 based on province
           coastal status.  FUN_00461010 then finds that record, reads the type
           from node+0x14 (+20), and inserts {prov_ptr, type, 0} into the build
           BST at inner+0x2474 via FUN_00404ef0.  The coastal heuristic below
           mirrors UnitList_FindOrInsert's initialization logic.
      5. Append '( POWER AMY/FLT PROV ) BLD' to state.g_build_order_list.
      6. Set state.g_waive_count = delta - len(selected).

    C: inserts BST nodes into this+0x2474/0x2478 via FUN_00404ef0 (called from
       FUN_00461010); FUN_00461010 clears this+0x2488 = 0 after each insertion
       (marks "build order placed"); sets this+0x2480 = waive count.
    """
    own_power = state.albert_power_idx
    power_name = _WIN_DAIDE_POWER_NAMES[own_power] if 0 <= own_power < 7 else 'UNO'

    if not state._id_to_prov:
        state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}
    id_to_prov = state._id_to_prov

    candidates: list = []
    for prov in range(256):
        score = float(state.g_CandidateScores[own_power, prov])
        if score > 0.0:
            candidates.append((score, prov))

    candidates.sort(reverse=True)
    selected = candidates[:delta]

    for _, prov in selected:
        is_coastal = any(adj in state.water_provinces
                         for adj in state.adj_matrix.get(prov, []))
        unit_type = 'FLT' if is_coastal else 'AMY'
        prov_name = id_to_prov.get(prov, str(prov))
        state.g_build_order_list.append(f'( {power_name} {unit_type} {prov_name} ) BLD')

    state.g_waive_count = max(0, delta - len(selected))


def compute_win_removes(state: InnerGameState, delta: int) -> None:
    """Port of FUN_0044bd40 — select bottom `delta` remove candidates and emit REM orders.

    Called from send_GOF when unit_count > sc_count (REMOVE phase).

    Algorithm:
      1. Collect all own-unit provinces where g_CandidateScores[own_power, prov] > 0.
      2. Sort by score ascending (lowest strategic value first — remove those first).
         Confirmed by decompile of FUN_0044bd40: BuildOrderSpec uses score+0x7d
         and the first element popped (lowest) is the one removed.
      3. Take up to `delta` provinces.
      4. Unit type is read directly from unit_info[prov]['type'].
      5. Append '( POWER AMY/FLT PROV ) REM' to state.g_build_order_list.

    C: inserts BST nodes into this+0x2474/0x2478; sets this+0x2488 = 0 (remove flag).
    """
    own_power = state.albert_power_idx
    power_name = _WIN_DAIDE_POWER_NAMES[own_power] if 0 <= own_power < 7 else 'UNO'

    if not state._id_to_prov:
        state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}
    id_to_prov = state._id_to_prov

    candidates: list = []
    for prov, unit_data in state.unit_info.items():
        if unit_data.get('power') != own_power:
            continue
        score = float(state.g_CandidateScores[own_power, prov])
        if score > 0.0:
            candidates.append((score, prov))

    candidates.sort()          # ascending: lowest score removed first
    selected = candidates[:delta]

    for _, prov in selected:
        raw_type = state.unit_info[prov].get('type', 'A')
        unit_type = 'FLT' if raw_type == 'F' else 'AMY'
        prov_name = id_to_prov.get(prov, str(prov))
        state.g_build_order_list.append(f'( {power_name} {unit_type} {prov_name} ) REM')


# ── PostProcessOrders ─────────────────────────────────────────────────────────

def post_process_orders(state: InnerGameState) -> None:
    """
    Port of PostProcessOrders (FUN_00411120).

    Updates g_MoveHistoryMatrix from the submitted-order history list.
    Two passes:
      Pass 1 — decay all entries by 3 (floor 0)
      Pass 2 — update from submitted-order history:
                 flag_A=1,flag_B=0 → successful support  (+10, cap 201)
                 flag_B=1          → bounced src row → zero
                 flag_C=1          → full conflict → zero row+col

    Research.md §2039.
    """
    num_powers = 7
    num_provinces = 256

    # Pass 1 — uniform decay
    state.g_MoveHistoryMatrix -= 3
    np.clip(state.g_MoveHistoryMatrix, 0, None, out=state.g_MoveHistoryMatrix)

    # Pass 2 — update from order history list
    for rec in getattr(state, 'g_OrderHistList', []):
        power    = int(rec.get('power', -1))
        src_prov = int(rec.get('src_prov', -1))
        dst_prov = int(rec.get('dst_prov', -1))
        flag_a   = int(rec.get('flag_a', 0))   # support survived
        flag_b   = int(rec.get('flag_b', 0))   # mover bounced / support cut
        flag_c   = int(rec.get('flag_c', 0))   # full conflict / dislodgement

        if not (0 <= power < num_powers): continue
        if not (0 <= src_prov < num_provinces): continue
        if not (0 <= dst_prov < num_provinces): continue

        # Check 1 (C++ order): flag_a=1 and flag_b=0 → successful support → +10 capped at 201
        if flag_a == 1 and flag_b == 0:
            cur = int(state.g_MoveHistoryMatrix[power, src_prov, dst_prov])
            if cur < 201:
                state.g_MoveHistoryMatrix[power, src_prov, dst_prov] = min(cur + 10, 201)

        # Check 2: flag_c=1 → full conflict → zero src row, dst row, dst column (independent if)
        if flag_c == 1:
            state.g_MoveHistoryMatrix[power, src_prov, :] = 0
            state.g_MoveHistoryMatrix[power, dst_prov, :] = 0
            state.g_MoveHistoryMatrix[power, :, dst_prov] = 0

        # Check 3: flag_b=1 → unit disrupted at src → zero src row (independent if)
        if flag_b == 1:
            state.g_MoveHistoryMatrix[power, src_prov, :] = 0


# ── EvaluateAllianceScore ─────────────────────────────────────────────────────

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


# ── Self-proposal generator ──────────────────────────────────────────────────

def generate_self_proposals(state: InnerGameState, own_power: int) -> int:
    """Generate MTO proposals for all powers and inject into g_GeneralOrders.

    In the C binary, non-hold orders are driven by the press pipeline:
    other bots send PRP(XDO(...)) → register_received_press →
    g_BroadcastList → score_order_candidates_from_broadcast →
    g_GeneralOrders → MC Phase 1c.  In standalone / NO_PRESS mode
    that pipeline is empty, so all orders default to hold.

    This function replaces the press round-trip by generating proposals
    directly from FinalScoreSet — for each unit, the highest-scored
    reachable province becomes an MTO proposal in g_GeneralOrders.
    The MC trial loop's Phase 1c then dispatches these into g_OrderTable,
    allowing the MC to choose between holds and moves.

    For the own power, proposals also go into g_AllianceOrders (mirrors
    the trust gate in score_order_candidates_from_broadcast).

    Returns the number of proposals inserted.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    fs = state.FinalScoreSet
    num_powers = 7
    inserted = 0

    if not hasattr(state, 'g_GeneralOrders'):
        state.g_GeneralOrders = {}
    if not hasattr(state, 'g_AllianceOrders'):
        state.g_AllianceOrders = {}
    if not state._id_to_prov:
        state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}

    # Determine which provinces are SCs (supply centers).
    # state.sc_provinces is a set of province *IDs* (ints), populated
    # by synchronize_from_game from game.map.scs.
    sc_set: set = set(getattr(state, 'sc_provinces', set()))

    for power in range(num_powers):
        for prov, info in list(state.unit_info.items()):
            if info['power'] != power:
                continue
            unit_type = info.get('type', 'A')

            # Score each adjacent province using multiple signals:
            #   1. FinalScoreSet[power, adj]  (strategic value from heat diffusion)
            #   2. SC bonus: +500 for unowned SCs, +300 for enemy SCs
            #   3. Adjacency influence: g_MaxProvinceScore[adj] (cross-power max)
            # Threshold: must beat 0 (any positive score means "worth considering")
            candidates: list = []  # [(score, adj)]
            for adj in state.get_adjacent_provinces(prov):
                # Skip provinces occupied by own unit
                adj_unit = state.unit_info.get(adj)
                if adj_unit is not None and adj_unit['power'] == power:
                    continue

                score = float(fs[power, adj])

                # SC bonus for unowned supply centers
                if adj in sc_set:
                    adj_owner = -1
                    for p2 in range(num_powers):
                        if state.g_SCOwnership[p2, adj] == 1:
                            adj_owner = p2
                            break
                    if adj_owner < 0:
                        score += 500.0   # neutral unowned SC
                    elif adj_owner != power:
                        score += 300.0   # enemy SC

                # Cross-power influence score as tiebreaker
                score += float(state.g_MaxProvinceScore[adj]) * 0.1

                if score > 0:
                    candidates.append((score, adj))

            if not candidates:
                continue

            # Sort descending, take top 2 (give MC some variety)
            candidates.sort(reverse=True)
            for _score, best_adj in candidates[:2]:
                prov_name = state._id_to_prov.get(prov, str(prov))
                adj_name = state._id_to_prov.get(best_adj, str(best_adj))
                order_seq = {
                    'type': 'MTO',
                    'unit': f"{unit_type} {prov_name}",
                    'target': adj_name,
                }

                state.g_GeneralOrders.setdefault(power, []).append(order_seq)
                inserted += 1

                # Own power also goes into alliance orders
                if power == own_power:
                    state.g_AllianceOrders.setdefault(power, []).append(order_seq)
                    inserted += 1

    if inserted:
        _log.debug(
            "generate_self_proposals: inserted %d proposals "
            "(general: %s, alliance: %s)",
            inserted,
            sorted(state.g_GeneralOrders.keys()),
            sorted(state.g_AllianceOrders.keys()),
        )
    return inserted


# ── ComputePress ─────────────────────────────────────────────────────────────

def compute_press(state: InnerGameState, own_power: int = 0) -> None:  # noqa: ARG001
    """
    Port of ComputePress (FUN_004401f0).

    Builds per-power adjacency-pressure matrix.  For each unit of any power,
    calls adjacency lookup, then for each adjacent *occupied* province
    (non-army coast token, or power-token == 0x14) sets
    g_PressMatrix[power][province] = 1 and increments g_PressCount[power].

    Result: g_PressMatrix (bool 2D, stride 0x100) + g_PressCount (count vec).

    Research.md §1295 / §2568 note.
    """
    state.g_PressMatrix.fill(0)
    state.g_PressCount.fill(0)

    for prov, info in state.unit_info.items():
        power = info['power']

        for adj in state.get_unit_adjacencies(prov):
            adj_power = state.get_unit_power(adj)
            if adj_power == -1:
                continue
            adj_info = state.unit_info.get(adj, {})
            # Condition: adjacent province is occupied, and is not an army
            # (fleet or non-army coast) or has power-token 0x14
            adj_type = adj_info.get('type', '')
            if adj_type == 'F' or adj_type == '':
                if state.g_PressMatrix[power, adj] == 0:
                    state.g_PressMatrix[power, adj] = 1
                    state.g_PressCount[power] += 1
