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

    Still open:
      Q-AIS-NEW-1  g_HistoryGate writer unknown → gate always fires until resolved
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
            if info is None or info['type'] != 'AMY':
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
    # Gate: zero both scores if g_HistoryGate[power_a/b][prov] == 0
    #   (Q-AIS-NEW-1: g_HistoryGate writer unknown; all entries currently 0,
    #    so no g_OrderList entries will be built until Q-AIS-NEW-1 is resolved)
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
                # Gate on g_HistoryGate (DAT_004DA2F0)
                if (state.g_HistoryGate[power_a, prov] == 0 or
                        state.g_HistoryGate[power_b, prov] == 0):
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
                    if unit['type'] == 'AMY':
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
            
    # Pass 2 - Score normalization
    global_max = np.max(state.g_MaxProvinceScore)
    threshold = global_max / 100.0
    
    for power in range(7):
        for province in range(256):
            if state.FinalScoreSet[power, province] > 0:
                score = state.FinalScoreSet[power, province]
                if score >= threshold and global_max > 0:
                    score = (score * 1000.0 / global_max) + 15.0
                else:
                    if score == 0:
                        score = 1.0
                    elif score == state.g_MinScore[province]:
                        import random
                        score = float(random.randint(1, 10))
                    else:
                        score = 1.0
                    if score > 10.0:
                        score = 10.0
                        
                state.FinalScoreSet[power, province] = score
                
                # Pass 3 - Army random variation
                if state.get_unit_type(province) == "AMY":
                    if score < state.g_MaxProvinceScore[province]:
                        import random
                        score *= random.uniform(0.9, 1.1)
                        state.FinalScoreSet[power, province] = score

    # Pass 4 - g_ProvinceAccessFlag initialization
    for power in range(7):
        for province in range(256):
            if state.has_unit(province):
                own_sc = state.g_SCOwnership[power, province]
                if own_sc == 0 and state.g_TargetFlag[power, province] != 2:
                    own_reach = state.g_OwnReachScore[power, province]
                    if own_reach == 0:
                        if state.g_SCOwnership[power, province] != 0 or state.g_TotalReachScore[power, province] != 0:
                            state.g_ProvinceAccessFlag[power, province] = 1
                    else:
                        enemy_reach = state.get_enemy_reach(power, province)
                        if state.has_own_unit(power, province) and enemy_reach == 0:
                            state.g_ProvinceAccessFlag[power, province] = 2
                        elif state.has_own_unit(power, province) and enemy_reach == 0:
                            state.g_ProvinceAccessFlag[power, province] = 1

def compute_draw_vote(state: InnerGameState, submitted_orders: list, power_name: str) -> bool:
    """
    Port of ComputeDrawVote / FUN_004440e0.
    Nash-stability check returning True if all units are fully committed.
    Returns False if any unit has >= 2 uncommitted free-move targets.
    """
    if not submitted_orders:
        return False
        
    power_names = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]
    power_id = power_names.index(power_name) if power_name in power_names else 0
        
    # Translate local_108 metadata tracker
    for prov_id, info in state.unit_info.items():
        if info['power'] == power_id:
            # Flood fill / reachability proxy
            free_moves_available = 0
            
            for adj in state.get_unit_adjacencies(prov_id):
                # Count adjacencies without immediate conflict
                if not state.has_unit(adj):
                    free_moves_available += 1
                    
            if free_moves_available >= 2:
                # >=2 uncommitted free-move targets breaks stability
                return False
                
    return True

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
                state.g_ThreatLevel[occupier_id, prov] = state.g_ThreatLevel.get((occupier_id, prov), 0) + 10
                
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
      - g_SCPercent      (SC percentage per power)
      - g_EnemyCount     (genuine enemy count per power)
      - g_RankMatrix / g_AllyPrefRanking  (influence ranking)
      - g_EnemyFlag      (designated enemies for this turn)
      - g_LeadingFlag / g_OtherPowerLeadFlag / g_NearVictoryPower
      - g_RequestDrawFlag / g_StaticMapFlag
      - g_OneScFromWin
    """
    num_powers = 7
    win_threshold = int(state.win_threshold)
    total_sc = int(np.sum(state.sc_count))
    if total_sc == 0:
        total_sc = 1  # guard against divide-by-zero at game start

    # ── Phase 1: exponential score + NearEndGameFactor ───────────────────────
    # g_PowerExpScore[k] = pow(sc_k, sc_k) * 100 + 1
    near_end = 1.0
    for k in range(num_powers):
        sc = int(state.sc_count[k])
        exp_score = (sc ** sc) * 100.0 + 1.0 if sc > 0 else 1.0
        state.g_PowerExpScore[k] = exp_score

        pct = sc * 100.0 / total_sc
        state.g_SCPercent[k] = pct
        if pct > 80.0:
            state.g_WarModeFlag = 1

        # NearEndGameFactor = max_k(sc[k] - win_threshold + 9)
        factor = float(sc - win_threshold + 9)
        if factor > near_end:
            near_end = factor

    # Clamp: if own SC ≤ 1 or ≤ 2 with factor < 5 → override
    own_sc = int(state.sc_count[own_power])
    if own_sc <= 1 or (own_sc <= 2 and near_end < 7.0):
        if own_sc <= 2 and near_end < 5.0:
            near_end = 5.0
        else:
            near_end = 8.0
    state.g_NearEndGameFactor = near_end

    # One-SC-from-win flag
    state.g_OneScFromWin = 1 if (win_threshold - own_sc == 1) else 0

    # ── Phase 2: g_EnemyCount + g_RankMatrix init ────────────────────────────
    state.g_EnemyCount.fill(0)
    state.g_AllyDistressFlag.fill(0)
    state.g_RankMatrix.fill(-1)
    np.fill_diagonal(state.g_RankMatrix, -2)

    for row in range(num_powers):
        for col in range(num_powers):
            if row == col:
                continue
            trust_lo = float(state.g_AllyTrustScore[row, col])
            trust_hi = float(getattr(state, 'g_AllyTrustScore_Hi',
                                     np.zeros((7, 7)))[row, col])
            influence = float(state.g_InfluenceMatrix[row, col])
            col_sc = int(state.sc_count[col])
            if (trust_hi < 1
                    and (trust_hi < 0 or trust_lo < 2)
                    and influence > 0
                    and col_sc > 2):
                state.g_EnemyCount[row] += 1

    # ── Phase 3: top feared powers from influence matrix ─────────────────────
    own_influence_row = state.g_InfluenceMatrix[own_power].copy()
    own_influence_row[own_power] = -1.0  # exclude self
    top3 = sorted(range(num_powers), key=lambda k: own_influence_row[k], reverse=True)[:3]

    # ── Phase 4: g_EnemyFlag selection ───────────────────────────────────────
    state.g_EnemyFlag.fill(0)
    state.g_LeadingFlag = 0
    state.g_OtherPowerLeadFlag = 0
    state.g_NearVictoryPower = -1

    # SC percentage lead of most dangerous power (excluding own)
    own_pct = float(state.g_SCPercent[own_power])
    max_pct = max((float(state.g_SCPercent[k]) for k in range(num_powers)
                   if k != own_power), default=0.0)
    lead = max_pct - own_pct
    leading_power = int(np.argmax([state.g_SCPercent[k] if k != own_power else 0.0
                                   for k in range(num_powers)]))

    if max_pct >= 60.0 and lead > 15.0:
        # Another power is threatening solo victory
        state.g_OtherPowerLeadFlag = 1
        state.g_NearVictoryPower = leading_power
        # Set all as enemy except own power
        for k in range(num_powers):
            if k != own_power:
                state.g_EnemyFlag[k] = 1
    elif state.g_StabbedFlag == 1:
        # Forced enemy: use top-3 by influence
        for k in top3:
            if int(state.sc_count[k]) > 0:
                state.g_EnemyFlag[k] = 1
                break
    else:
        # Peacetime: select top feared power as enemy
        for k in top3:
            trust = float(state.g_AllyTrustScore[own_power, k])
            if trust <= 0 and k != own_power:
                state.g_EnemyFlag[k] = 1
                break

    # Leading-flag: own power has >75% of own-row influence and >2% SC gap
    own_row_sum = float(np.sum(state.g_InfluenceMatrix[own_power]))
    own_row_own = float(state.g_InfluenceMatrix[own_power, own_power])
    if own_row_sum > 0 and (own_row_own / own_row_sum) > 0.75 and own_pct > (max_pct + 2.0):
        state.g_LeadingFlag = 1
        state.g_EnemyFlag.fill(0)
        for k in range(num_powers):
            if k != own_power:
                state.g_EnemyFlag[k] = 1

    # ── Phase 5: draw / static-map flags ─────────────────────────────────────
    # Request draw when own SC ≥ 60% and well ahead, or map is static
    own_total_pct = (own_sc * 100) // total_sc if total_sc > 0 else 0
    if own_total_pct >= 60 and lead < 0:        # we are ahead
        state.g_RequestDrawFlag = 1
    elif getattr(state, 'g_StaticMapFlag', 0):
        state.g_RequestDrawFlag = 1
    else:
        state.g_RequestDrawFlag = 0

    # ── Phase 6: alliance-agreement → enemy (honor ally's enemies) ───────────
    for pow_a in range(num_powers):
        for pow_b in range(num_powers):
            if (int(state.g_AllyMatrix[pow_a, pow_b]) == 1
                    and state.g_EnemyFlag[pow_b] == 0
                    and int(state.g_AllyMatrix[own_power, pow_b]) == 1
                    and float(state.g_AllyTrustScore[own_power, pow_b]) < 1):
                state.g_EnemyFlag[pow_b] = 1
                state.g_AllyTrustScore[own_power, pow_b] = 0


# ── ComputeInfluenceMatrix / NormalizeInfluenceMatrix ────────────────────────

def compute_influence_matrix(state: InnerGameState, own_power: int = 0) -> None:  # noqa: ARG001
    """
    Port of ComputeInfluenceMatrix (FUN_0040d8c0) — ranking phase.

    Assumes g_InfluenceMatrix (= g_InfluenceMatrix_Alt) has already been
    populated and row-normalised by generate_orders (inlined pipeline).
    Performs:
      Phase 5 — initialise g_AllyPrefRanking / g_InfluenceRankFlag
      Phase 6 — insertion-sort to build ranked alliance preference list

    Research.md §4292.
    """
    num_powers = 7

    # Phase 5 — init ranking arrays
    state.g_AllyPrefRanking.fill(-1)
    state.g_InfluenceRankFlag.fill(-1)
    for p in range(num_powers):
        state.g_AllyPrefRanking[p, 0] = p           # slot 0 = own power (sentinel)
        state.g_InfluenceRankFlag[p, p] = -2         # self = skip

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

    # Section 3 — per-unit presence flags
    for prov, info in state.unit_info.items():
        power = info['power']
        trust = float(state.g_AllyTrustScore[own_power, power]) if power != own_power else 1.0
        if power == own_power:
            state.g_SCOwnership[own_power, prov] = 1
        elif trust < 0:
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
                history = 0  # g_AllyHistoryCount — approximated as 0

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

        # Section 4e — convoy/mobility counts (simplified 2-hop expansion)
        for prov, info in state.unit_info.items():
            for adj in state.get_unit_adjacencies(prov):
                adj_power = state.get_unit_power(adj)
                if adj_power != -1:
                    for adj2 in state.get_unit_adjacencies(adj):
                        if g_UnitPresence[prov] == 1 and state.g_SCOwnership[own_power, adj2] == 0:
                            state.g_ConvoyReachCount[own_power, adj2] += 1
                        if info['power'] != own_power:
                            state.g_EnemyMobilityCount[own_power, adj2] += 1

        # Section 4h — province score assignment (main scoring pass)
        if outer_power == own_power:
            for prov in range(num_provinces):
                if state.g_SCOwnership[own_power, prov] == 1 or prov in state.unit_info:
                    score = evaluate_province_score(state, prov, own_power)
                    state.g_AttackCount[own_power, prov] = float(score)
                    # max-accumulate
                    if float(score) > state.g_MaxProvinceScore[prov]:
                        state.g_MaxProvinceScore[prov] = float(score)


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
        if state.get_unit_type(prov) == 'AMY':
            if normalized < state.g_MaxProvinceScore[prov]:
                scores[prov] = _random.randint(0, 2 ** 32 - 1)

    # Write back into g_CandidateScores for own power
    for prov, val in scores.items():
        state.g_CandidateScores[own_power, prov] = float(val)


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

        if flag_a == 1 and flag_b == 0:
            # Successful uncut support → +10, capped at 201
            cur = int(state.g_MoveHistoryMatrix[power, src_prov, dst_prov])
            if cur < 201:
                state.g_MoveHistoryMatrix[power, src_prov, dst_prov] = min(cur + 10, 201)

        elif flag_b == 1:
            # Unit disrupted at src → zero entire src row
            state.g_MoveHistoryMatrix[power, src_prov, :] = 0

        elif flag_c == 1:
            # Full conflict → zero row and column for both src and dst
            state.g_MoveHistoryMatrix[power, src_prov, :] = 0
            state.g_MoveHistoryMatrix[power, dst_prov, :] = 0
            state.g_MoveHistoryMatrix[power, :, dst_prov] = 0


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
            if adj_type == 'FLT' or adj_type == '':
                if state.g_PressMatrix[power, adj] == 0:
                    state.g_PressMatrix[power, adj] = 1
                    state.g_PressCount[power] += 1
