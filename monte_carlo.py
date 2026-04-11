import copy
import random
import numpy as np
from .state import InnerGameState
from .heuristics import score_order_candidates_all_powers
from .moves import enumerate_hold_orders, enumerate_convoy_reach, compute_safe_reach, build_support_opportunities, build_support_proposals, assign_support_order, register_convoy_fleet

# ── Order-table field indices ────────────────────────────────────────────────
# g_OrderTable[prov, field]  mirrors  DAT_00baeda0[prov*0x1e + field*4]
# Layout from research.md §DispatchSingleOrder "complete field map (updated)"
# and §AssignSupportOrder.  Field [3] is ushort read via ptr-to-short at
# stride 0x3c × 2 = 0x78 (same row width as the int fields).
_F_ORDER_TYPE    =  0   # 1=HLD 2=MTO 3=SUP_HLD 4=SUP_MTO 5=CVY 6=CTO (DAT_00baeda0)
_F_SECONDARY     =  1   # CVY: army_prov; SUP: target_prov (DAT_00baeda4)
_F_DEST_PROV     =  2   # destination province (MTO/CTO/CVY) (DAT_00baeda8)
_F_DEST_COAST    =  3   # destination coast token, ushort (DAT_00baedac)
_F_HOLD_WEIGHT   =  4   # hold weight, written by ScoreOrderSet (DAT_00baedb0)
_F_CTO_DEST_PROP =  5   # CTO destination province property (DAT_00baedfc)
_F_CONVOY_LO     =  6   # convoy chain score lo / negated defense score (DAT_00baedb8)
_F_CONVOY_HI     =  7   # convoy chain score hi (DAT_00baedbc)
_F_CONVOY_LEG0   =  8   # CTO convoy leg 0 (DAT_00baee08)
_F_CONVOY_LEG1   =  9   # CTO convoy leg 1 (DAT_00baee0c)
_F_CONVOY_LEG2   = 10   # CTO convoy leg 2 (DAT_00baee10)
_F_CONVOY_DEPTH  = 11   # convoy chain depth (§ProcessTurn)
_F_INCOMING_MOVE = 13   # 1 = province has incoming MTO/CTO (DAT_00baedd4)
_F_SUP_SRC_LO    = 14   # support source province low word (§ScoreOrderSet)
_F_TARGET_PROV   = 15   # target province for order scoring (§ScoreOrderSet)
_F_SOURCE_PROV   = 16   # source province; SUP = supported unit's province
_F_SUP_COUNT     = 17   # count of units supporting this order
_F_SUP_TARGET    = 18   # AssignSupportOrder: assigned target-role province (DAT_00baede8)
_F_ORDER_ASGN    = 20   # 1 = support order committed (DAT_00baedf0)
_F_CUM_SCORE     = 27   # cumulative trial score

# Order type constants (g_OrderTable[prov, _F_ORDER_TYPE])
_ORDER_HLD      = 1
_ORDER_MTO      = 2
_ORDER_SUP_HLD  = 3
_ORDER_SUP_MTO  = 4
_ORDER_CVY      = 5
_ORDER_CTO      = 6


def trial_evaluate_orders(state: InnerGameState, trial_candidate: dict) -> dict:
    """
    State duplicator for trial resolutions.  Deep-copies the candidate order
    dict so each MC trial is isolated.  The caller is responsible for loading
    trial_candidate into state.g_OrderTable before calling evaluate_order_score.
    """
    return copy.deepcopy(trial_candidate)


def evaluate_order_score(power_idx: int, state: InnerGameState) -> float:
    """
    Port of ScoreOrderSet (FUN_00437600).  Monte Carlo objective function.

    Reads committed order assignments from state.g_OrderTable and scores the
    complete trial position for `power_idx`.  Six passes A–F mirroring the
    decompiled C.  Returns an accumulated float score (the original returns a
    ulonglong via PackScoreU64 banker-rounding; we keep full precision here).

    Globals consumed (all on InnerGameState):
      Pass A: g_ThreatLevel, g_SCOwnership, g_EnemyPresence, g_AttackCount,
              g_AttackHistory, g_DefenseScore, g_ProvinceWeight
              → g_UnitMoveProb, g_OrderTable[_F_DEF_NEG_*]
      Pass B: g_UnitMoveProb, g_ConvoyChainScore, g_SupportDemand
              → g_FleetSupportScore
      Pass C: g_ProximityScore, g_SCOwnership, g_EnemyPresence, g_UnitMoveProb,
              g_OrderTable[_F_CONVOY_DEPTH]
              → g_OrderTable[_F_HOLD_WEIGHT]
      Pass D: unit_info, adj_matrix, g_EnemyReachScore, g_UnitReachScore,
              g_OrderTable[_F_ORDER_TYPE/_F_TARGET_PROV/_F_ORDER_ASGN]
              → g_CutSupportRisk
      Pass E: g_season, g_OrderTable[_F_ORDER_TYPE]
              → g_OrderTable[_F_RETREAT_CNT/_F_RETREAT_FLAG]
      Pass F: g_FleetSupportScore, g_UnitMoveProb, g_CutSupportRisk,
              g_ConvoySourceProv, g_ConvoyChainScore, g_SupportDemand,
              g_AttackHistory, g_SCOwnership, g_AttackCount, g_DefenseScore
              → returns accumulated score
    """
    ot = state.g_OrderTable  # shape (256, 30), dtype float64

    # ── Pass A: Unit-order probability ──────────────────────────────────────
    # For each province under threat for power_idx, estimate the probability
    # that the assigned order will succeed.  Written to g_UnitMoveProb[prov]
    # and negated into order-table defense fields [6]/[7].
    for prov in range(256):
        if state.g_ThreatLevel[power_idx, prov] <= 0:
            continue

        has_move    = int(ot[prov, _F_ORDER_ASGN]) >= 1
        target_prov = int(ot[prov, _F_TARGET_PROV])
        src_prov    = int(ot[prov, _F_SOURCE_PROV])

        own_sc      = int(state.g_SCOwnership[power_idx, prov])
        enemy_pres  = int(state.g_EnemyPresence[power_idx, prov])
        atk_count   = float(state.g_AttackCount[power_idx, prov])
        atk_history = float(state.g_AttackHistory[power_idx, prov])
        def_score   = float(state.g_DefenseScore[power_idx, prov])
        prov_weight = float(state.g_ProvinceWeight[power_idx, prov])

        if own_sc == 1:
            # Row 1: own SC province — weight by province desirability
            if has_move and src_prov != target_prov:
                raw = ot[prov, _F_SOURCE_PROV] * 0.5
                move_prob = min(prov_weight if prov_weight > 0.0 else raw, 1.0)
            else:
                move_prob = min(prov_weight, 1.0) if prov_weight > 0.0 else 0.3

        elif enemy_pres == 0:
            # Row 2: uncontested province
            if atk_count > def_score and def_score > 0.0:
                move_prob = 1.0
            elif atk_count > 0.0:
                move_prob = 0.8
            else:
                move_prob = min(prov_weight, 1.0) if prov_weight > 0.0 else 0.5

        else:
            # Enemy present — rows 3-7
            if atk_count == def_score:
                # Row 3: balanced contest
                move_prob = 0.33

            elif atk_count > def_score:
                # Rows 5-6: attack surplus
                if def_score > 0.0:
                    move_prob = min(1.0, 0.8 + (atk_count - def_score) * 0.1)
                else:
                    move_prob = 1.0 if (has_move and atk_count > 0.0) else 0.8

            else:
                # atk_count < def_score — rows 4 and 7
                if def_score > 0.0 and atk_count > 0.0:
                    ratio = atk_count / def_score
                    if ratio < 0.5:
                        # Row 4: heavily outnumbered
                        move_prob = max(0.05, min(0.15, ratio * 0.3))
                    else:
                        # Row 7: retreat / losing conditions
                        # g_AttackHistory * 0.25 + g_DefenseScore * 0.15
                        move_prob = max(0.0, min(1.0, atk_history * 0.25 + def_score * 0.15))
                else:
                    move_prob = 0.05

        state.g_UnitMoveProb[prov] = move_prob
        # Negate defense score into order-table fields [6] and [7] (int64 lo/hi words)
        ot[prov, _F_CONVOY_LO] = -def_score
        ot[prov, _F_CONVOY_HI] = -def_score

    # ── Pass B: Fleet support score update (3 iterations) ───────────────────
    # Propagates convoy-chain depth scores to fleet-adjacent provinces.
    # "Full support" (demand==0): threshold = chain_score * move_prob * 0.2
    # "Partial support" (demand>0): threshold *= 0.75
    for _ in range(3):
        for prov in range(256):
            if state.get_unit_type(prov) != 'FLT':
                continue

            move_prob = float(state.g_UnitMoveProb[prov])
            if move_prob > 0.5:
                move_prob = 0.5  # cap per decompile: DAT_00baeda8 * 0.5

            chain_score = float(state.g_ConvoyChainScore[prov])

            for adj_prov in state.get_unit_adjacencies(prov):
                fleet_score = float(state.g_FleetSupportScore[adj_prov])
                if fleet_score < 0.0:
                    continue  # negative sentinel — skip

                # cond1: adj's support-opportunity list is empty
                # (head==tail in MSVC STL); approximated by g_SupportDemand==0
                has_full_support = (state.g_SupportDemand[adj_prov] == 0)

                if has_full_support:
                    threshold = chain_score * move_prob * 0.2
                else:
                    threshold = chain_score * move_prob * 0.2 * 0.75

                if fleet_score < threshold:
                    state.g_FleetSupportScore[adj_prov] = threshold

    # ── Pass C: Hold-weight computation ─────────────────────────────────────
    # Writes g_OrderTable[prov, _F_HOLD_WEIGHT].
    # Higher values cause AssignHoldSupports to prefer defending over moving.
    for prov in range(256):
        if not state.has_unit(prov):
            continue

        proximity    = float(state.g_ProximityScore[power_idx, prov])
        own_sc       = int(state.g_SCOwnership[power_idx, prov])
        enemy_pres   = int(state.g_EnemyPresence[power_idx, prov])
        move_prob    = float(state.g_UnitMoveProb[prov])
        convoy_depth = int(ot[prov, _F_CONVOY_DEPTH])

        if proximity == 0.0:
            # piVar14[0xb]==0: no convoy depth assigned
            if own_sc == 0 and convoy_depth == 0:
                hold_w = 1.0             # isolated non-SC: hold firmly
            elif own_sc == 1:
                hold_w = move_prob if move_prob > 0.0 else 0.3
            else:
                hold_w = 1.0
        else:
            # g_EnemyPresence==1 → 0.2/proximity;  ==0 → 0.4/proximity
            if enemy_pres == 1:
                hold_w = 0.2 / proximity
            else:
                hold_w = 0.4 / proximity

        ot[prov, _F_HOLD_WEIGHT] = hold_w

    # ── Pass D: Cut-support risk ─────────────────────────────────────────────
    # Iterates every unit.  For each adjacent province:
    #   own unit adjacencies → accumulate g_UnitReachScore, skipping adj that
    #     are MTO-ing into our province (they can't cut support from there)
    #   enemy unit adjacencies → +1.0 if enemy reach==1 AND not already assigned
    #     a support order  (DAT_00baedd4[adj*0x1e] == 0, i.e. _F_ORDER_ASGN==0)
    # Clipped to [0,1]; signed: own→negative, enemy→positive.
    for prov, info in state.unit_info.items():
        unit_power = info['power']
        local_128  = 0.0

        for adj_prov in state.get_unit_adjacencies(prov):
            if unit_power == power_idx:
                # Own unit adjacency
                adj_order  = int(ot[adj_prov, _F_ORDER_TYPE])
                adj_target = int(ot[adj_prov, _F_TARGET_PROV])
                if adj_order == _ORDER_MTO and adj_target == prov:
                    pass   # moving away — cannot cut our support here
                else:
                    local_128 += float(state.g_UnitReachScore[adj_prov])
            else:
                # Enemy unit: threatens support if it can reach AND is unassigned
                if (state.g_EnemyReachScore[unit_power, adj_prov] == 1 and
                        int(ot[adj_prov, _F_ORDER_ASGN]) == 0):
                    local_128 += 1.0

        local_128 = max(0.0, min(1.0, local_128))

        if unit_power == power_idx:
            state.g_CutSupportRisk[prov] = -(1.0 - local_128)
        else:
            state.g_CutSupportRisk[prov] =  (1.0 - local_128)

    # ── Pass E: Retreat-order validity reset ─────────────────────────────────
    # Zeroes piVar14[8] (retreat_count) and piVar14[9] (retreat_flag) for
    # units not in a valid retreat phase or order type.
    # SPR/FAL = movement phases; SUM/AUT = retreat phases.
    season = state.g_season
    is_retreat_phase = season in ('SUM', 'AUT')

    for prov in range(256):
        if not state.has_unit(prov):
            continue
        order_type = int(ot[prov, _F_ORDER_TYPE])
        if not is_retreat_phase or order_type not in (_ORDER_HLD, _ORDER_SUP_HLD):
            ot[prov, _F_CONVOY_LEG0] = 0.0
            ot[prov, _F_CONVOY_LEG1] = 0.0

    # ── Pass F: Cumulative score accumulation ────────────────────────────────
    # Running sum local_120:
    #   HLD / CVY  →  direct: fleet_score * move_prob
    #   all others →  g_ConvoySourceProv + fleet_score * move_prob + prior
    #                 + FAL bonus if SUP_HLD with adjacency alternatives
    # Post-main-branch per-province:
    #   CVY           → +fleet_score      (PackScoreU64 approximated additive)
    #   CTO/CTO_CHAIN → +chain_depth + support_demand + fleet_score
    #   move_prob==1.0 with high attack history on unowned SC → +fleet_score*0.4
    #   cut_risk != 0 → +cut_risk * 100
    local_120 = 0.0

    for prov in range(256):
        if not state.has_unit(prov):
            continue

        order_type  = int(ot[prov, _F_ORDER_TYPE])
        fleet_score = float(state.g_FleetSupportScore[prov])
        move_prob   = float(state.g_UnitMoveProb[prov])
        cut_risk    = float(state.g_CutSupportRisk[prov])

        if order_type in (_ORDER_HLD, _ORDER_CVY):
            local_120 += fleet_score * move_prob
        else:
            local_118 = fleet_score * move_prob + local_120
            # g_ConvoySourceProv: province-ID score set by ProcessTurn ring/convoy
            # logic.  Sentinel 0xffffffff (-1) treated as zero contribution.
            src_score = float(state.g_ConvoySourceProv[prov])
            if src_score < 0.0:
                src_score = 0.0
            local_120 = src_score + local_118

            # FAL bonus: SUP_HLD unit that still has adjacency options available
            # (src_adj_head != src_adj_tail = non-empty MSVC STL list)
            if order_type == _ORDER_SUP_HLD and season == 'FAL':
                if state.get_unit_adjacencies(prov):
                    local_120 += 100.0

        # After convoy-complete (CVY): PackScoreU64 adds packed fleet contribution
        if order_type == _ORDER_CVY:
            local_120 += fleet_score

        # CTO: chain depth + support demand bonus + fleet score
        if order_type == _ORDER_CTO:
            chain_depth = int(ot[prov, _F_CONVOY_DEPTH])
            sup_demand  = int(state.g_SupportDemand[prov])
            local_120  += float(chain_depth + sup_demand)
            local_120  += fleet_score

        # Definitely-moving unit with sustained historical attack pressure
        if move_prob == 1.0:
            atk_history = float(state.g_AttackHistory[power_idx, prov])
            own_sc      = int(state.g_SCOwnership[power_idx, prov])
            atk_count   = float(state.g_AttackCount[power_idx, prov])
            def_score   = float(state.g_DefenseScore[power_idx, prov])
            # Threshold >10 from research.md §ScoreOrderSet globals table
            if atk_history > 10.0 and own_sc == 0 and atk_count > 0.0 and def_score > 0.0:
                local_120 += fleet_score * 0.4

        # Cut-support risk: 100× multiplier (from decompile)
        if cut_risk != 0.0:
            local_120 += cut_risk * 100.0

    return local_120


def evaluate_order_proposal(state: InnerGameState, power_idx: int) -> None:
    """
    Port of FUN_0044e070 = EvaluateOrderProposal.

    Per-power proposal evaluation called once per power per MC trial.

    Step 1 — Build order sequences from g_OrderTable.
      In the original binary this constructs DAIDE token sequences; in Python the
      order table is authoritative and no token encoding is needed.  The loop is
      retained as a pass to identify which provinces have active orders.

    Step 2 — Iterate own units; build local_cac (order accumulator), detect
      deviations (local_d31), compute pressure penalty local_d04.
        local_d04 = 500  if province has no SUB entry and order ∉ {MTO, CTO}
        local_d04 = 750  if province is in the alternate-order candidate list
        local_d31 = 1    if order deviates from the expected order in g_DeviationTree

    Step 3 — Score all powers based on own order types.
      Accumulates aiStack_a9c[power] (heat_scores) using province-indexed score arrays.
      MTO/CTO:   proximity vs own-reach comparison; near-end and normal branches.
      SUP_MTO:   check reach arrays at support source → +src+500+dest per power.
      SUP_HLD:   check reach arrays at src/dest     → +src+750+dest per power.
      HLD/CVY:   check reach arrays at province     → +province+4000 per power.

    Step 4 — Early-game adjacency bonus (only when NearEndGameFactor==1.0 and
      DeceitLevel==1).  +160 per trusted-power province adjacent to ≥2 own orders.

    Step 5 — Finalize: zero own heat entry, call evaluate_order_score (ScoreOrderSet),
      insert candidate record into g_CandidateRecordList, call build_support_proposals.
    """
    ot = state.g_OrderTable
    NUM_POWERS = 7
    own_power = getattr(state, 'albert_power_idx', -1)

    # ── Step 1 — identify active provinces (DAIDE encoding skipped) ─────────
    active_provs = [
        prov for prov in range(256) if int(ot[prov, _F_ORDER_TYPE]) != 0
    ]
    _ = active_provs  # enumerated; token-sequence construction elided in Python

    # ── Step 2 — own-unit accumulator, deviation flag, pressure cost ─────────
    local_d31 = 0   # deviation flag
    local_d04 = 0   # pressure/cost
    local_cac = []  # (prov, order_type) pairs — mirrors inner_state sequence accumulator

    for prov, info in state.unit_info.items():
        if info['power'] != power_idx:
            continue

        order_type = int(ot[prov, _F_ORDER_TYPE])
        if order_type == 0:
            continue

        local_cac.append((prov, order_type))

        # Deviation detection: applies only to Albert's own power
        if power_idx == own_power:
            expected = state.g_DeviationTree.get((power_idx, prov), 0)
            if expected != 0 and expected != order_type:
                local_d31 = 1

            # SUB-map check: province not in committed order map and not MTO/CTO → 500
            if prov not in state.g_SubOrderMap:
                if order_type not in (_ORDER_MTO, _ORDER_CTO):
                    local_d04 = 500

            # Alternate-order list: → 750 (overrides 500)
            alt_list = state.g_AltOrderList.get(power_idx, set())
            if prov in alt_list:
                local_d04 = 750

    # ── Step 3 — per-power heat score accumulation ───────────────────────────
    heat_scores = [0] * NUM_POWERS

    for prov, info in state.unit_info.items():
        if info['power'] != power_idx:
            continue

        order_type = int(ot[prov, _F_ORDER_TYPE])
        if order_type == 0:
            continue

        src = prov

        if order_type in (_ORDER_MTO, _ORDER_CTO):
            dest = int(ot[prov, _F_DEST_PROV])

            for power in range(NUM_POWERS):
                # Allied-SC-under-threat bonus (any endgame defensive pressure)
                if (state.g_OtherPowerLeadFlag == 1
                        and state.g_NearEndGameFactor > 5.0
                        and state.g_SCOwnership[power_idx, src] == 1):
                    heat_scores[power] += 50

                if state.g_NearEndGameFactor > 6.0 and state.g_OtherPowerLeadFlag == 1:
                    # Near-end branch: DAT_005460ec > DAT_0058f8ec + DAT_005658ec
                    # (g_ProximityScore > g_OwnReachScore + g_AllyReachScore at src)
                    prox  = float(state.g_ProximityScore[power, src])
                    own_r = float(state.g_OwnReachScore[power_idx, src])
                    ally_r = float(state.g_AllyReachScore[power_idx, src])
                    if prox > own_r + ally_r:
                        heat_scores[power] += src + dest + 1000
                else:
                    # Normal branch: DAT_005460ec[src+power*0x40] > DAT_0058f8ec[src+param_1*0x40]
                    prox  = float(state.g_ProximityScore[power, src])
                    own_r = float(state.g_OwnReachScore[power_idx, src])
                    if prox > own_r:
                        for adj_q in state.get_unit_adjacencies(prov):
                            if state.g_OwnReachScore[power_idx, adj_q] > 1:
                                heat_scores[power] += src + dest + 1000
                                break

        elif order_type == _ORDER_SUP_MTO:
            dest = int(ot[prov, _F_DEST_PROV])

            for power in range(NUM_POWERS):
                # Any reach array non-zero at support source → press this province
                if (state.g_OwnReachScore[power_idx, src] > 0
                        or state.g_ConvoySupport[power_idx, src] > 0
                        or state.g_ConvoyReach[power_idx, src] > 0
                        or state.g_SupportReach[power_idx, src] > 0):
                    heat_scores[power] += src + 500 + dest

        elif order_type == _ORDER_SUP_HLD:
            dest = int(ot[prov, _F_SECONDARY])  # province being held/supported

            for power in range(NUM_POWERS):
                # DAT_0058f8ec[src*8] > 0 OR DAT_005c48ec[dest*8] > 0 OR DAT_005ba0ec[src*8] > 0
                if (state.g_OwnReachScore[power_idx, src] > 0
                        or state.g_ConvoyReach[power_idx, dest] > 0
                        or state.g_SupportReach[power_idx, src] > 0):
                    heat_scores[power] += src + 0x2ee + dest  # 0x2ee = 750

        elif order_type in (_ORDER_HLD, _ORDER_CVY):
            for power in range(NUM_POWERS):
                # DAT_0058f8ec[dest*8] > 0 OR DAT_005ba0ec[dest*8] > 0
                if (state.g_OwnReachScore[power_idx, src] > 0
                        or state.g_SupportReach[power_idx, src] > 0):
                    heat_scores[power] += src + 4000

    # ── Step 4 — early-game adjacency bonus ──────────────────────────────────
    early_game_bonus = 0
    if state.g_NearEndGameFactor == 1.0 and state.g_DeceitLevel == 1:
        # Count how many own-unit adjacencies cover each province
        adj_order_count = [0] * 256
        for prov, info in state.unit_info.items():
            if info['power'] != power_idx:
                continue
            for adj in state.get_unit_adjacencies(prov):
                adj_order_count[adj] += 1

        for prov in range(256):
            if not state.has_unit(prov):
                continue
            unit_power = state.get_unit_power(prov)
            if unit_power == power_idx:
                continue
            trust = float(state.g_AllyTrustScore[power_idx, unit_power])
            if trust >= 2 and adj_order_count[prov] > 1:
                early_game_bonus += 0xa0  # +160 per qualifying province
        state.g_EarlyGameBonus += early_game_bonus

    # ── Step 5 — finalize, score, record, and propose ────────────────────────
    heat_scores[power_idx] = 0  # zero own entry (no self-pressure)

    score = evaluate_order_score(power_idx, state)

    candidate = {
        'power': power_idx,
        'orders': local_cac,
        'score': score,
        'heat_scores': heat_scores,
        'deviation': local_d31,
        'pressure_cost': local_d04,
        'early_game_bonus': early_game_bonus,
    }
    state.g_CandidateRecordList.append(candidate)

    build_support_proposals(state, power_idx)


def generate_orders(state: InnerGameState, own_power: int) -> None:
    """
    Port of FUN_004466e0 = GenerateOrders(Albert *this).

    Master turn-evaluation driver.  Computes the full influence-matrix pipeline,
    populates g_CandidateScores, g_AllianceScore, and g_OpeningTarget, then
    triggers the order-enumeration pipeline.

    Phases (research.md §GenerateOrders — FUN_004466e0 / §generate_orders):
      Phase 0  — Zero all scoring tables and influence matrices.
      Phase 1  — Per-power loop: urgency seed → 5-round BFS heat diffusion →
                 candidate scores → g_HeatMovement → g_InfluenceMatrix accumulation.
      Phase 3  — Snapshot g_InfluenceMatrix → g_InfluenceMatrix_Raw.
      Phase 4  — Per-power noise injection (_safe_pow approx).
      Phase 5  — Row-normalize g_InfluenceMatrix to row-sums of 100.
      Phase 6  — Asymmetric g_AllianceScore from Raw matrix.
      Phase 7  — g_OpeningTarget per power (SPR + g_DeceitLevel==1 only).
      Finally  — enumerate_hold_orders, enumerate_convoy_reach, compute_safe_reach,
                 build_support_opportunities (mirrors post-loop calls in binary).
    """
    NUM_POWERS   = 7
    NUM_PROVINCES = 256

    # Record own power so that downstream MC functions can resolve Albert's index.
    state.albert_power_idx = own_power

    # ── Phase 0 — Init ───────────────────────────────────────────────────────
    state.g_CandidateScores.fill(0)
    state.g_HeatMovement.fill(0)
    state.g_TargetFlag.fill(0)
    state.g_InfluenceMatrix.fill(0)
    state.g_InfluenceMatrix_Raw.fill(0)
    state.g_AllianceScore.fill(0)
    state.g_GlobalProvinceScore.fill(0)
    state.g_NeedsRescore.fill(-1)   # 0xffffffff sentinel

    # ── Phase 1 — Per-power heat diffusion + candidate scoring ───────────────
    for p in range(NUM_POWERS):
        curr_sc  = int(np.sum(state.g_SCOwnership[p]))
        target_sc = 18  # standard Diplomacy win threshold

        # 1a — Province urgency scoring → heat_build seed (aiStack_6018 equivalent)
        # research.md §5440–5451: g_StickyModeActive → 5000; SC-need formula otherwise.
        heat_build_seed = np.zeros(NUM_PROVINCES, dtype=np.float64)
        for prov in range(NUM_PROVINCES):
            if state.get_unit_power(prov) != p:
                heat_build_seed[prov] = 0.0
            elif state.g_UniformMode == 1:          # g_StickyModeActive / g_UniformMode
                heat_build_seed[prov] = 5000.0
            elif target_sc > curr_sc:
                heat_build_seed[prov] = float((target_sc - curr_sc + 2) * 500)
            else:
                heat_build_seed[prov] = 1000.0

        # 1b — 5-round BFS → heat_build (auStack_3818 equivalent)
        # Each round: cur[p] = sum(prev[q] for q in adj[p]) / 5
        heat_build = heat_build_seed.copy()
        for _ in range(5):
            nxt = np.zeros(NUM_PROVINCES, dtype=np.float64)
            for prov in range(NUM_PROVINCES):
                adjs = state.get_unit_adjacencies(prov)
                if adjs:
                    nxt[prov] = sum(heat_build[q] for q in adjs) / 5.0
            heat_build = nxt

        # 1c — Home-unit seed → heat_move seed (local_3018 equivalent, +5000 per own unit)
        heat_move_seed = np.zeros(NUM_PROVINCES, dtype=np.float64)
        for prov, info in state.unit_info.items():
            if info['power'] == p:
                heat_move_seed[prov] = 5000.0

        # 1d — 5-round BFS → heat_move (auStack_818 equivalent)
        heat_move = heat_move_seed.copy()
        for _ in range(5):
            nxt = np.zeros(NUM_PROVINCES, dtype=np.float64)
            for prov in range(NUM_PROVINCES):
                adjs = state.get_unit_adjacencies(prov)
                if adjs:
                    nxt[prov] = sum(heat_move[q] for q in adjs) / 5.0
            heat_move = nxt

        # 1e — Accumulate g_GlobalProvinceScore
        for prov in range(NUM_PROVINCES):
            state.g_GlobalProvinceScore[prov] += heat_build[prov] + heat_move[prov]

        # 1f — Build ordered set, populate g_CandidateScores (top-N by heat_move)
        # OrderedSet_FindOrInsert_64bit: sorted ascending; copy into g_CandidateScores.
        # Albert+0x3ff8 (unit limit) approximated by the power's actual unit count.
        own_units = sorted(
            (heat_move[prov], prov)
            for prov in range(NUM_PROVINCES)
            if state.get_unit_power(prov) == p
        )
        for count, (score, prov) in enumerate(own_units):
            if count >= len(own_units):
                break
            state.g_CandidateScores[p, prov] = score

        # 1g — Copy heat_move → g_HeatMovement[p]
        state.g_HeatMovement[p] = heat_move

        # 1h — Accumulate g_InfluenceMatrix[col, p]
        # research.md §5516–5522: g_InfluenceMatrix_B[col*21+p] =
        #   Σ(heat_build + heat_move) for provinces where unit.power != col AND col != p.
        # Empty provinces (unit_power == -1) contribute; -1 != col for all valid col.
        for col in range(NUM_POWERS):
            if col == p:
                continue
            total = 0.0
            for prov in range(NUM_PROVINCES):
                if state.get_unit_power(prov) != col:
                    total += heat_build[prov] + heat_move[prov]
            state.g_InfluenceMatrix[col, p] = total

    # ── Phase 3–4 — Snapshot Raw, inject noise ────────────────────────────────
    # Phase 3: copy g_InfluenceMatrix → g_InfluenceMatrix_Raw
    state.g_InfluenceMatrix_Raw = state.g_InfluenceMatrix.copy()

    # Phase 4: per-cell noise via _safe_pow (FUN_0047b370).
    # Formula: B[i][j] += pow(B[i][j] / (sum[j] + 1), 0.3) * 500.0
    # where sum[j] = column sum of Raw for power j (g_PowerInfluenceSum[col]).
    # ST1=base=B[i][j]/(sum[j]+1), ST0=exponent=0.3 (DAT_004af9f8).
    col_sums = np.sum(state.g_InfluenceMatrix_Raw, axis=0).astype(float)  # shape (NUM_POWERS,)
    for i in range(NUM_POWERS):
        for j in range(NUM_POWERS):
            base = state.g_InfluenceMatrix[i, j] / (col_sums[j] + 1.0)
            state.g_InfluenceMatrix[i, j] += (base ** 0.3) * 500.0

    # ── Phase 5 — Row-normalize g_InfluenceMatrix to row-sums of 100 ─────────
    for i in range(NUM_POWERS):
        row_sum = float(np.sum(state.g_InfluenceMatrix[i]))
        if row_sum != 0.0:
            state.g_InfluenceMatrix[i] *= 100.0 / row_sum

    # ── Phase 6 — Compute asymmetric g_AllianceScore ─────────────────────────
    # research.md §5568–5584:
    #   col_sum[row] = column sum of Raw over all rows (= total influence directed at row)
    #   A = Raw[row][col], B = Raw[col][row]
    #   A < B → col threatens row more → g_AllianceScore[row][col] = -3*(A/(B+1))*(B/col_sum)
    #   else  → row dominates col      → g_AllianceScore[row][col] = +3*(B/(A+1))*(B/col_sum)
    for row in range(NUM_POWERS):
        col_sum = float(np.sum(state.g_InfluenceMatrix_Raw[:, row]))
        curr_sc_row = int(np.sum(state.g_SCOwnership[row]))
        for col in range(NUM_POWERS):
            if col == row:
                continue
            curr_sc_col = int(np.sum(state.g_SCOwnership[col]))
            if curr_sc_row == 0 or curr_sc_col == 0:
                state.g_AllianceScore[row, col] = 0.0
            else:
                A = float(state.g_InfluenceMatrix_Raw[row, col])
                B = float(state.g_InfluenceMatrix_Raw[col, row])
                denom = col_sum if col_sum != 0.0 else 1.0
                if A < B:
                    state.g_AllianceScore[row, col] = -3.0 * (A / (B + 1.0)) * (B / denom)
                else:
                    state.g_AllianceScore[row, col] =  3.0 * (B / (A + 1.0)) * (B / denom)

    # ── Phase 7 — Compute g_OpeningTarget ────────────────────────────────────
    # research.md §5594–5607: only when g_DeceitLevel==1 AND season==SPR.
    # Lowest-g_GlobalProvinceScore non-own-unit province wins (inverse weighting).
    state.g_OpeningTarget.fill(-1)
    if state.g_DeceitLevel == 1 and state.g_season == 'SPR':
        for p in range(NUM_POWERS):
            best_score = float('-inf')
            for prov in range(NUM_PROVINCES):
                unit_power = state.get_unit_power(prov)
                if unit_power != -1 and unit_power != p:
                    gps = float(state.g_GlobalProvinceScore[prov])
                    if gps > 0.0:
                        sc = random.uniform(0.0, 1.0) * 2.0 / gps
                        if sc > best_score:
                            best_score = sc
                            state.g_OpeningTarget[p] = prov

    # ── Order enumeration pipeline ───────────────────────────────────────────
    # Mirrors the post-loop calls in the binary (EnumerateHoldOrders,
    # EnumerateConvoyReach, ComputeSafeReach, BuildSupportOpportunities).
    for p in range(NUM_POWERS):
        enumerate_hold_orders(state, p)
        enumerate_convoy_reach(state, p)
    compute_safe_reach(state)
    build_support_opportunities(state)


def process_turn(state: InnerGameState, power_index: int, num_trials: int = 4000) -> None:
    """
    Port of FUN_00453220 = ProcessTurn(Albert *this, int **power_index, int num_trials).

    Per-power Monte Carlo order-assignment engine.  Called by ScoreOrderCandidates
    once per active power.  Runs ``num_trials`` independent MC trials for
    ``power_index`` and accumulates results into state.g_CandidateRecordList.

    Signature matches decompiled: __thiscall ProcessTurn(param_1_00, power_index, num_trials)
      param_1_00  → state (Albert *this)
      power_index → the power being simulated this call
      num_trials  → number of Monte Carlo iterations

    Phase 0 — Setup (once per call)
    --------------------------------
    0a. Build reachable-province set (g_ReachableProvinces) by scanning the ally-
        shared order-history list for power_index (or own-power variant when
        power_index == own_power).
    0b. Per-power order-history copy: copy g_OrderHistory[p] → local per-power sets.
    0c. Ally flag scan: local_76f = 1 if g_XdoPressSent[power_index, p] for any p.
    0d. Random start offset for the cyclical power-expand pass.

    Phase 1 — Monte Carlo trial loop (num_trials iterations)
    ----------------------------------------------------------
    Each trial:
    1a. Per-trial state reset:
        - clear g_SupportTrustAdj / g_RingConvoyScore / g_EarlyGameAdjScore / g_OtherScore
        - clear g_ConvoyDstList, g_TrialList2, g_TrialMap
        - reset g_OrderTable all-provinces (order type 0, coast -1, other fields 0)
        - reset g_ConvoySourceProv[prov] = -1, g_ConvoyActiveFlag[prov] = 0,
          g_ProvinceScore[prov] = 0, g_ArmyAdjCount[prov] = 0
        - reset g_UnitPresence[power, prov] = -1 for all power,prov
    1b. Unit list scan:
        - g_UnitPresence[unit.power, unit.province] = 0
        - for own armies: g_ArmyAdjCount[adj]++ for each AMY-adjacent province
    1c. Dispatch existing orders (priority HLD→MTO→CTO→CVY→SUP):
        - If power_index == own_power (or trusted ally): dispatch g_AllianceOrders[power_index]
        - Dispatch g_GeneralOrders[power_index] (second pass)
    1d. Ring-convoy check (if g_RingConvoyEnabled):
        - Verify ring A→B, B→C, C→A is still intact; build MTO orders if valid.
    1e. Random exploit pass (15% chance; 35% if late-game + has_ally):
        - Cycle through allied powers looking for defection / secondary targets.
        - Insert matching proposal records from g_DealList into local candidate set.
    1f. Support assignment:
        - Find own unordered SC provinces → call assign_hold_supports.
    1g. Convoy chain assignment:
        - Iterate g_ConvoyDstList; score / rank fleet candidates via score_convoy_fleet.
    1h. Target-bonus scoring:
        - +150/+75 per MTO/CTO unit moving to a flagged target province.
        - +50 per SUP_MTO into an SC-gaining support.
    1i. Call evaluate_order_proposal(state, power_index) once per trial.

    Callees (unported stubs where noted):
      reset_per_trial_state   — FUN_00460be0; resets board-level snapshot
      dispatch_single_order   — dispatch.py; already ported
      assign_hold_supports    — FUN_0041d270; STUB
      score_convoy_fleet      — BST insert-with-score; STUB
      move_candidate          — BST erase/pop from Albert+0x4cfc; STUB
      build_order_mto         — writes MTO into g_OrderTable; STUB
      insert_order_candidate  — inserts candidate into local set; STUB
      evaluate_order_proposal — monte_carlo.py; already ported
    """
    import logging
    logger = logging.getLogger(__name__)

    own_power: int = getattr(state, 'albert_power_idx', 0)
    num_provinces: int = int(getattr(state, 'num_provinces',
                                     state.g_OrderTable.shape[0]))
    num_powers: int = 7

    # ── helpers for unported stubs ────────────────────────────────────────────
    def _reset_per_trial_state() -> None:
        """Port of FUN_00460be0 = ResetPerTrialState.

        Three C operations:
        (1) For each node in active unit list (this+0x2450/54): clear node+0x20 =
            the order-assigned pointer (ppiVar8[4] in DispatchSingleOrder).  Python
            has no per-node flag; the equivalent is g_OrderTable being zeroed at the
            end of this trial-reset block (line ~914), so no explicit work here.
        (2) Same for retreat unit list (this+0x245c/60) — same reasoning.
        (3) Free all nodes of the build-candidate list at this+0x2478 (calling
            FUN_0040fb70 on each node[2] then _free(node)), reset list sentinel to
            empty, clear size field (this+0x247c = 0) and waive count
            (this+0x2480 = 0).  Python: clear g_build_order_list and zero
            g_waive_count.
        """
        if hasattr(state, 'g_build_order_list'):
            state.g_build_order_list.clear()
        state.g_waive_count = 0

    def _assign_hold_supports(candidates: dict) -> None:
        """FUN_0041d270 = AssignHoldSupports — decompile-verified.

        Clears g_ConvoyFleetCandidates (Albert+0x4cfc) then re-populates it
        from *candidates* (own unordered SC provinces) with random scores.

        Decompile trace:
          1. FUN_004019f0(root) + sentinel reset → clear BST → .clear()
          2. Iterate param_1 (candidate std::set) in tree order.
          3. Per node: province = *(node+0xC)  [MSVC release layout:
             node[0]=_Left, node[1]=_Parent, node[2]=_Right, node[3]=key]
          4. score = (_rand() // 0x17) % 0x7c17 + 500
             MSVC _rand() ∈ [0, RAND_MAX=32767=0x7fff]
             → score ∈ [500, 1924]
          5. ScoreConvoyFleet(this+0x4cfc, buf, &score) → bisect.insort
        """
        state.g_ConvoyFleetCandidates.clear()
        for prov in candidates:
            r = random.randint(0, 32767)  # MSVC _rand() ∈ [0, RAND_MAX=0x7fff]
            score = (r // 0x17) % 0x7c17 + 500
            _score_convoy_fleet(prov, score)

    def _score_convoy_fleet(prov: int, score: int) -> None:
        """ScoreConvoyFleet (FUN_00419790) — BST insert into g_ConvoyFleetCandidates.

        Mirrors MSVC std::map<int,int>::insert: lower-bound traversal (decompiled
        loop at FUN_00419790) followed by FUN_00413ba0 (actual RB-tree node alloc
        + link).  In Python the sorted list replaces the RB-tree; bisect.insort
        keeps it ordered by score ascending (same traversal direction as the C
        loop: key > node[3] → go left, i.e. larger keys are to the left, so the
        BST is effectively descending — but the Python list is ascending; Phase 2
        drains from the front, which is lowest score first).
        """
        import bisect
        bisect.insort(state.g_ConvoyFleetCandidates, (score, prov))

    def _move_candidate(prov: int) -> None:
        """MoveCandidate (FUN_00411cf0) — BST erase from g_ConvoyFleetCandidates.

        Removes the existing entry for *prov* (if any) before re-inserting with
        an updated score.  Mirrors std::map::erase(iterator).
        """
        state.g_ConvoyFleetCandidates = [
            e for e in state.g_ConvoyFleetCandidates if e[1] != prov
        ]

    def _build_order_mto(src: int, dst: int, coast: int) -> None:
        """Port of BuildOrder_MTO — write MTO into g_OrderTable.

        Decompile-verified (decompiled.txt).  Signature:
          __thiscall BuildOrder_MTO(this, power, src_province, dst_province, coast)

        Stubbed callees:
          ClearConvoyState()        — clears per-convoy temp state; trial reset covers it
          BuildOrder_CTO_Ring(...)  — builds CTO ring chain; unknown decompile
          RegisterConvoyFleet(...)  — registers fleet candidate; unknown decompile
        """
        # ClearConvoyState() — STUB (per-trial reset at Phase 1a covers observable effect)

        # Determine unit type at src (AMY vs FLT)
        is_army = (state.unit_info.get(src, {}).get('type') == 'AMY')

        # BuildOrder_CTO_Ring(gamestate, src, dst, coast) — STUB

        # ConvoyList_Insert(&DAT_00bb65a0, &dst): append dst to convoy dst list; record dst→src
        if dst not in state.g_ConvoyDstList:
            state.g_ConvoyDstList.append(dst)
        if not hasattr(state, 'g_ConvoyDstToSrc'):
            state.g_ConvoyDstToSrc = {}
        state.g_ConvoyDstToSrc[dst] = src

        # g_OrderTable[src]: write MTO order type, destination, coast
        state.g_OrderTable[src, _F_ORDER_TYPE] = float(_ORDER_MTO)
        state.g_OrderTable[src, _F_DEST_PROV]  = float(dst)
        state.g_OrderTable[src, _F_DEST_COAST] = float(coast)

        # g_ProvinceBaseScore[dst] = 1: mark dst as having an incoming move
        state.g_OrderTable[dst, _F_INCOMING_MOVE] = 1.0

        # OrderedSet_FindOrInsert(this + power*0xc + 0x4000, &dst):
        # inherit dst's candidate score (FinalScoreSet) into convoy chain score fields
        score_lo = float(state.FinalScoreSet[power_index, dst])
        score_hi = 0.0
        state.g_ConvoyChainScore[dst]        = score_lo
        state.g_OrderScoreHi[dst]            = score_hi
        state.g_OrderTable[dst, _F_CONVOY_LO] = score_lo
        state.g_OrderTable[dst, _F_CONVOY_HI] = score_hi

        # DAT_00baede4[dst*0x1e] = g_MoveHistoryMatrix[dst + (src + power*0x40)*0x40]
        # Python layout: g_MoveHistoryMatrix[power, src, dst]
        state.g_OrderTable[dst, _F_SUP_COUNT] = float(
            state.g_MoveHistoryMatrix[power_index, src, dst]
        )

        # If AMY and convoy chain depth at src ≠ 5 (not complete): clear dst score fields
        # DAT_00baedf0[src*0x1e] = _F_ORDER_ASGN holds convoy chain depth in this context
        if is_army and int(state.g_OrderTable[src, _F_ORDER_ASGN]) != 5:
            state.g_OrderTable[dst, 24] = 0.0  # DAT_00baee00[dst*0x1e]
            state.g_OrderTable[dst, 25] = 0.0  # DAT_00baee04[dst*0x78]

        register_convoy_fleet(state, power_index, dst)

        # AssignSupportOrder(this, power, src, dst, coast, NULL)
        assign_support_order(state, power_index, src, dst, coast, flag=0)

    def _insert_order_candidate(candidate_list: list, score: int, entry: dict) -> dict:
        """InsertOrderCandidate — BST sorted insert keyed on score (ascending).

        Mirrors the C++ `InsertOrderCandidate` / `FUN_004153b0` pair:
          - Descends the BST comparing node[3] < *param_2 (go left) until sentinel.
          - Allocates a new node (or returns existing) and links it.
          - Returns {container, node, is_new=1} via param_1; here returns the entry dict.

        Python representation: candidate_list is a list of (score, entry_dict) tuples
        maintained in ascending score order via bisect.  Duplicate keys are allowed
        (same score → inserted to the right of existing equal-key entries).
        """
        import bisect
        keys = [s for s, _ in candidate_list]
        pos = bisect.bisect_right(keys, score)
        new_entry = dict(entry)
        new_entry['score'] = score
        candidate_list.insert(pos, (score, new_entry))
        return new_entry

    # ── lazy-init per-trial arrays not yet on state ───────────────────────────
    if not hasattr(state, 'g_UnitPresence'):
        state.g_UnitPresence = np.full((num_powers, num_provinces), -1, dtype=np.int32)
    if not hasattr(state, 'g_ConvoyActiveFlag'):
        state.g_ConvoyActiveFlag = np.zeros(num_provinces, dtype=np.int32)
    if not hasattr(state, 'g_ConvoyDstList'):
        state.g_ConvoyDstList = []
    if not hasattr(state, 'g_TrialList2'):
        state.g_TrialList2 = []
    if not hasattr(state, 'g_TrialMap'):
        state.g_TrialMap = {}
    if not hasattr(state, 'g_SupportTrustAdj'):
        state.g_SupportTrustAdj = 0
    if not hasattr(state, 'g_RingConvoyScore'):
        state.g_RingConvoyScore = 0
    if not hasattr(state, 'g_OtherScore'):
        state.g_OtherScore = 0
    if not hasattr(state, 'g_RingConvoyEnabled'):
        state.g_RingConvoyEnabled = 0
    if not hasattr(state, 'g_RingProv_A'):
        state.g_RingProv_A = -1
    if not hasattr(state, 'g_RingProv_B'):
        state.g_RingProv_B = -1
    if not hasattr(state, 'g_RingProv_C'):
        state.g_RingProv_C = -1
    if not hasattr(state, 'g_RingCoast_A'):
        state.g_RingCoast_A = 0
    if not hasattr(state, 'g_RingCoast_B'):
        state.g_RingCoast_B = 0
    if not hasattr(state, 'g_RingCoast_C'):
        state.g_RingCoast_C = 0
    if not hasattr(state, 'g_AllianceOrders'):
        state.g_AllianceOrders = {}          # {power: [order_seq, ...]}
    if not hasattr(state, 'g_GeneralOrders'):
        state.g_GeneralOrders = {}           # {power: [order_seq, ...]}
    if not hasattr(state, 'g_AllianceOrdersPresent'):
        state.g_AllianceOrdersPresent = np.zeros(num_powers, dtype=np.int32)
    if not hasattr(state, 'g_GeneralOrdersPresent'):
        state.g_GeneralOrdersPresent = np.zeros(num_powers, dtype=np.int32)
    if not hasattr(state, 'g_OrderHistory'):
        state.g_OrderHistory = {}            # {power: [{province, ...}, ...]}
    if not hasattr(state, 'g_AllyOrderHistory'):
        state.g_AllyOrderHistory = {}        # {power: [{province, ...}, ...]}
    if not hasattr(state, 'g_ProposalHistoryMap'):
        # DAT_00baed98 — proposal history map; mirrors state.g_DealList
        state.g_ProposalHistoryMap = getattr(state, 'g_DealList', [])
    if not hasattr(state, 'g_StabMode'):
        state.g_StabMode = 0                 # DAT_00baed69

    # ── Phase 0 — Setup ───────────────────────────────────────────────────────

    # 0a. Build reachable-province set (g_ReachableProvinces) for power_index.
    #     Mirrors the StdMap_FindOrInsert(&DAT_00bb7124, ...) scan in decompile.
    g_ReachableProvinces = {}  # {prov: True}; DAT_00bb7124
    if power_index == own_power:
        # own power: scan ally-shared order history (DAT_00bb7028[power_index])
        for entry in state.g_AllyOrderHistory.get(power_index, []):
            prov = entry.get('province', -1)
            if prov >= 0:
                g_ReachableProvinces[prov] = True
    else:
        # ally: only scan when relation > 9 OR trust (hi > 0, or hi >= 0 and lo > 5)
        trust_lo = int(state.g_AllyTrustScore[own_power, power_index])
        trust_hi = int(state.g_AllyTrustScore_Hi[own_power, power_index])
        rel      = int(state.g_RelationHistory[own_power, power_index])
        if rel > 9 or (trust_hi > 0) or (trust_hi >= 0 and trust_lo > 5):
            for entry in state.g_AllyOrderHistory.get(power_index, []):
                prov = entry.get('province', -1)
                if prov >= 0:
                    g_ReachableProvinces[prov] = True

    # 0b. Per-power order-history snapshot (auStack_138[p] in decompile).
    #     Mirrors the DAT_00bb6f2c[p] copy loop.
    per_power_order_sets: list = [
        dict(state.g_OrderHistory.get(p, {})) for p in range(num_powers)
    ]

    # 0c. Ally flag scan: local_76f = 1 if any g_XdoPressSent[power_index, p] == 1.
    has_ally: bool = bool(
        np.any(state.g_XdoPressSent[power_index] == 1)
    )

    # 0d. Random start offset for the cyclical power-expand pass.
    rand_power_start: int = random.randrange(num_powers)
    rand_power_cursor: int = rand_power_start

    # ── Phase 1 — Monte Carlo trial loop ─────────────────────────────────────
    # Mirror of the do { ... } while (iStack_684 < num_trials) block.

    for _trial in range(num_trials):

        # 1a. Per-trial state reset ────────────────────────────────────────────
        state.g_SupportTrustAdj   = 0     # DAT_00633f14
        state.g_RingConvoyScore   = 0     # DAT_0062c57c
        state.g_EarlyGameBonus    = 0     # DAT_0062be94 (g_EarlyGameAdjScore)
        state.g_OtherScore        = 0     # DAT_0062b7ac

        _reset_per_trial_state()           # FUN_00460be0

        # Clear per-trial lists (DAT_00bb65a4 / DAT_00bbf648 / DAT_00bb6e04).
        state.g_ConvoyDstList.clear()
        state.g_TrialList2.clear()
        state.g_TrialMap.clear()

        # Reset per-province order-table fields.
        # Mirrors the loop over 0..numProvinces zeroing DAT_00baedac fields.
        state.g_OrderTable[:num_provinces, :] = 0.0
        state.g_OrderTable[:num_provinces, _F_DEST_COAST] = -1.0   # 0xffffffff
        state.g_ConvoySourceProv[:num_provinces]  = -1.0  # g_SupportAssignmentMap sentinel
        state.g_ConvoyActiveFlag[:num_provinces]  = 0
        state.g_ProvinceScoreTrial[:num_provinces] = 0
        state.g_ArmyAdjCount[:num_provinces]      = 0
        state.g_ConvoyFleetRegistered.clear()

        # Reset unit-presence matrix (g_UnitPresence[power*0x100+prov] = -1).
        state.g_UnitPresence[:, :num_provinces] = -1

        # 1b. Unit list scan ───────────────────────────────────────────────────
        # Mirrors: for each unit in this+8+0x2450 { g_UnitPresence[...] = 0;
        #           if own AMY: g_ArmyAdjCount[adj]++ }
        for prov, unit in state.unit_info.items():
            p_u  = unit['power']
            utyp = unit.get('type', '')
            state.g_UnitPresence[p_u, prov] = 0

            if p_u == power_index and utyp == 'AMY':
                for adj in state.get_unit_adjacencies(prov):
                    state.g_ArmyAdjCount[adj] += 1

        # 1c. Dispatch existing orders (priority HLD→MTO→CTO→CVY→SUP) ─────────
        # First pass: alliance orders (DAT_00bb65f8[power*0xc]) — own or trusted ally.
        from .dispatch import dispatch_single_order as _dso
        dispatch_first_pass = False
        if power_index == own_power:
            dispatch_first_pass = True
        else:
            trust_lo2 = int(state.g_AllyTrustScore[own_power, power_index])
            trust_hi2 = int(state.g_AllyTrustScore_Hi[own_power, power_index])
            if trust_hi2 > 0 or (trust_hi2 >= 0 and trust_lo2 > 2):
                dispatch_first_pass = True

        _ORDER_PRIORITY = [_ORDER_HLD, _ORDER_MTO, _ORDER_CTO, _ORDER_CVY, _ORDER_SUP_MTO]
        _ORDER_TYPE_MAP  = {
            _ORDER_HLD: 'HLD', _ORDER_MTO: 'MTO', _ORDER_CTO: 'CTO',
            _ORDER_CVY: 'CVY', _ORDER_SUP_MTO: 'SUP',
        }

        if dispatch_first_pass and state.g_AllianceOrdersPresent[power_index]:
            for order_type in _ORDER_PRIORITY:
                for order_seq in state.g_AllianceOrders.get(power_index, []):
                    if order_seq.get('type') == _ORDER_TYPE_MAP.get(order_type):
                        _dso(state, power_index, order_seq)

        # Second pass: general orders (DAT_00bb6cf8[power*0xc]) — unconditional.
        if state.g_GeneralOrdersPresent[power_index]:
            for order_type in _ORDER_PRIORITY:
                for order_seq in state.g_GeneralOrders.get(power_index, []):
                    if order_seq.get('type') == _ORDER_TYPE_MAP.get(order_type):
                        _dso(state, power_index, order_seq)

        # 1d. Ring-convoy check (DAT_00baed5c == 1) ───────────────────────────
        if state.g_RingConvoyEnabled == 1:
            ring_broken = False
            pA, pB, pC = state.g_RingProv_A, state.g_RingProv_B, state.g_RingProv_C
            if (int(state.g_OrderTable[pA, _F_ORDER_TYPE]) == _ORDER_MTO and
                    int(state.g_OrderTable[pA, _F_DEST_PROV]) != pB):
                ring_broken = True
            if (int(state.g_OrderTable[pB, _F_ORDER_TYPE]) == _ORDER_MTO and
                    int(state.g_OrderTable[pB, _F_DEST_PROV]) != pC):
                ring_broken = True
            if (int(state.g_OrderTable[pC, _F_ORDER_TYPE]) == _ORDER_MTO and
                    int(state.g_OrderTable[pC, _F_DEST_PROV]) != pA):
                ring_broken = True

            # Also check whether unit is absent from ring province (own-power gate).
            if power_index == own_power:
                # Mirroring: FUN_00402140 checks whether ring prov is in own order set.
                ring_in_set = (pA in per_power_order_sets[power_index] and
                               pB in per_power_order_sets[power_index] and
                               pC in per_power_order_sets[power_index])
                if not ring_in_set:
                    ring_broken = True
            # If ring intact: build the three MTO orders.
            if not ring_broken:
                _build_order_mto(pA, pB, state.g_RingCoast_A)
                _build_order_mto(pB, pC, state.g_RingCoast_B)
                _build_order_mto(pC, pA, state.g_RingCoast_C)

        # 1e. Random exploit pass (15% chance; 35% if late-game ally mode) ────
        # Mirrors: if (iVar20 < 0x0f) { ... } else if (...) goto LAB_004505d1
        r_exploit = random.randrange(100)
        do_exploit = r_exploit < 15
        if (not do_exploit and has_ally
                and state.g_NearEndGameFactor > 6.0
                and getattr(state, 'g_AlbertPower', own_power) != power_index
                and r_exploit < 35):
            do_exploit = True

        if do_exploit:
            # Advance cyclical power cursor to next allied power.
            rand_power_cursor = (rand_power_cursor + 1) % num_powers
            # Find an allied power.
            exploit_power = rand_power_cursor
            for _ in range(num_powers):
                if state.g_XdoPressSent[power_index, exploit_power]:
                    break
                exploit_power = (exploit_power + 1) % num_powers

            # Determine secondary target for stab scoring (65% × late-game).
            secondary_target = -1
            r2 = random.randrange(100)
            if (r2 < 65 and state.g_StabMode == 1
                    and state.g_NearEndGameFactor > 6.0):
                trust_lo3 = int(state.g_AllyTrustScore[own_power, exploit_power])
                trust_hi3 = int(state.g_AllyTrustScore_Hi[own_power, exploit_power])
                if trust_hi3 > 0 or (trust_hi3 >= 0 and trust_lo3 != 0):
                    secondary_target = (exploit_power + 1) % num_powers
                    for _ in range(num_powers):
                        st_lo = int(state.g_AllyTrustScore[own_power, secondary_target])
                        st_hi = int(state.g_AllyTrustScore_Hi[own_power, secondary_target])
                        if st_lo == 0 and st_hi == 0:
                            secondary_target = -1
                            break
                        if secondary_target == exploit_power:
                            secondary_target = -1
                            break
                        secondary_target = (secondary_target + 1) % num_powers

            # Build exploit candidate set (local_6e4).
            # InsertOrderCandidate inserts unconditionally — no count limit here.
            exploit_candidates: list = []   # [(score, entry_dict), ...] ascending

            # Scan proposal history (DAT_00baed98 / g_DealList) for matching entries.
            for rec in list(state.g_ProposalHistoryMap):
                if rec.get('power') != power_index:
                    continue
                rec_prov = rec.get('province', -1)
                # Check reachable / alt order set match (mirrors GameBoard_GetPowerRec).
                if rec_prov not in per_power_order_sets[power_index]:
                    continue
                score = rec.get('score', 0)
                entry = {
                    'unit_prov':    rec_prov,
                    'target_power': rec.get('target_power', -1),
                    'via_prov':     rec.get('src_prov', -1),
                    'dst_prov':     rec.get('dst_prov', -1),
                }
                # Primary insert: auStack_204 call site.
                if rec.get('target_power') == exploit_power:
                    _insert_order_candidate(exploit_candidates, score, entry)
                # Secondary insert: auStack_150 call site.
                # Condition: target_power == secondary_target AND via_prov == dst_prov.
                if secondary_target >= 0 and rec.get('target_power') == secondary_target:
                    if rec.get('src_prov') == rec.get('dst_prov'):
                        _insert_order_candidate(exploit_candidates, score, entry)

            # Count cap computed AFTER insertions (mirrors decompile: lines 81–102
            # overwrite ppiStack_7bc with the cap after the insertion loop).
            r3 = random.randrange(100)
            if secondary_target < 0:
                if r3 < 65:
                    count_cap = 1
                elif r3 < 84:
                    count_cap = 2
                else:
                    count_cap = 4 + int(r3 > 89)
            else:
                if r3 < 40:
                    count_cap = 1
                elif r3 < 60:
                    count_cap = 2
                elif r3 < 80:
                    count_cap = 3
                else:
                    count_cap = 4 + int(r3 > 89)

            # Consumption loop (decompile lines 103–246):
            # Iterate local_6e4 ascending by score; 60% rand gate + total count cap.
            # Trust/convoy conditions (via_prov vs dst_prov branch, relay province
            # lookup via g_ConvoyProv1/2/3 and g_AllyDesignation_A, reachability via
            # GameBoard_GetPowerRec) are not yet fully decompiled — stubbed below.
            consumed = 0
            for _score, cand in exploit_candidates:
                if random.randrange(100) >= 60:     # < 0x3c = 60% gate
                    continue
                if consumed >= count_cap:
                    break
                unit_prov = cand['unit_prov']
                if int(state.g_UnitPresence[power_index, unit_prov]) == -1:
                    continue
                # STUB: trust/convoy route check unported (needs full Phase-1e decompile).
                state.g_OrderTable[unit_prov, _F_ORDER_TYPE] = float(_ORDER_CTO)
                state.g_ConvoyActiveFlag[unit_prov] = 1
                consumed += 1

        # 1f. Support assignment ───────────────────────────────────────────────
        # Find own unordered SC provinces; call AssignHoldSupports.
        # Mirrors: for each prov where g_SCOwnership[power_index,prov]==1 AND
        #          g_OrderTable[prov,0]==0 → add to support_candidates.
        support_candidates: dict = {}
        for prov in range(num_provinces):
            if (state.g_SCOwnership[power_index, prov] == 1 and
                    int(state.g_OrderTable[prov, _F_ORDER_TYPE]) == 0):
                support_candidates[prov] = True
        _assign_hold_supports(support_candidates)

        # 1g. Convoy chain assignment ─────────────────────────────────────────
        # Iterate g_ConvoyDstList (DAT_00bb65a4); for each prov with enemy presence /
        # SC ownership: find in Albert+0x4cfc candidate list → ScoreConvoyFleet.
        fleet_pool_a = 0x7ffb   # ppiStack_7c0 initial value (from decompile line 1239)
        inserted_count = 0
        for prov in list(state.g_ConvoyDstList):
            iVar20 = power_index * 0x100 + prov
            enemy_hi  = int(state.g_EnemyPresence[power_index, prov])
            sc_own    = int(state.g_SCOwnership[power_index, prov])
            if enemy_hi > 0 or (enemy_hi >= 0 and sc_own != 0):
                # Mirrors: find ppiStack_7bc in Albert+0x4cfc where node[4]==prov
                # then MoveCandidate + StdMap_FindOrInsert + ScoreConvoyFleet.
                inserted_count += 1
                fleet_pool_a -= 1
                _move_candidate(prov)
                _score_convoy_fleet(prov, fleet_pool_a)

        # Own-power only: second convoy pass (lines 1294–1390 in decompile).
        if power_index == own_power:
            pass  # STUB: second convoy pass (pool-B scoring, decompile lines 1294+)

        # 1h. Target-bonus scoring ────────────────────────────────────────────
        # Pass 1: MTO/CTO toward target-flagged provinces (+150 or +75).
        # Pass 2: RTO / unit-presence check (lines 2909–2940 in decompile).
        # Pass 3: SUP_MTO toward SC-gaining flag (+50, lines 2958–3032).
        for prov, unit in state.unit_info.items():
            if unit['power'] != power_index:
                continue
            order_type = int(state.g_OrderTable[prov, _F_ORDER_TYPE])
            press_active = bool(state.g_PressFlag)

            if order_type in (_ORDER_MTO, _ORDER_CTO):
                dest = int(state.g_OrderTable[prov, _F_DEST_PROV])
                tflag = int(state.g_TargetFlag[power_index, dest])
                if tflag == 2:
                    state.g_EarlyGameBonus += 150 if press_active else 75

            elif order_type == _ORDER_SUP_MTO:
                via = int(state.g_OrderTable[prov, _F_SECONDARY])
                iVar20 = via + power_index * 0x100
                tflag_via = int(state.g_TargetFlag[power_index, via])
                sc_hi = int(state.g_SCOwnership[power_index, via])
                if (tflag_via == 2 and sc_hi == 0 and
                        state.g_HistoryCounter == 0):
                    state.g_EarlyGameBonus += 50

        # 1i. Evaluate order proposal for this power (once per trial). ─────────
        # Mirrors: EvaluateOrderProposal(param_1_00, power_index) at decompile line 3747.
        evaluate_order_proposal(state, power_index)


# ── UpdateScoreState ──────────────────────────────────────────────────────────

def _update_ally_order_score(state: InnerGameState, power: int) -> None:
    """
    Port of UpdateAllyOrderScore (FUN_00442770).
    Pass 1 sub-function of UpdateScoreState.
    """
    if getattr(state, 'g_CandidateRecordList', None) is None:
        return

    candidates = [c for c in state.g_CandidateRecordList if c.get('power') == power]
    if not candidates:
        return

    if hasattr(state, 'g_SubOrderMap'):
        state.g_SubOrderMap.clear()

    # Re-evaluate ally-directed pressure accumulation natively
    own_power = getattr(state, 'albert_power_idx', 0)
    for c in candidates:
        score = c.get('score', 0)
        c['score_alt'] = score + getattr(state, 'g_CumScore', 0)
        
    # Native EvaluateAllianceScore analog to update the matrices
    from .heuristics import compute_influence_matrix
    compute_influence_matrix(state)


def _refresh_order_table(state: InnerGameState, power: int) -> None:
    """
    Port of RefreshOrderTable (FUN_00424490).
    Rebuilds g_OrderTable entries for the given power.
    """
    import random
    
    candidates = [c for c in state.g_CandidateRecordList if c.get('power') == power]
    if not candidates:
        return
        
    num_candidates = len(candidates)
    
    # Monte Carlo probabilistic selection modeling
    selected_idx = 0
    if num_candidates > 1:
        # Re-creating the randomized float matching distribution map (1000 - pressure)
        max_score = sum(1000 - min(1000, max(0, int(c.get('pressure_cost', 0)))) for c in candidates)
        if max_score > 0:
            threshold = random.randrange(1000)
            
            accum = 0.0
            for i, c in enumerate(candidates):
                cost_val = min(1000, max(0, int(c.get('pressure_cost', 0))))
                score = 1000.0 - cost_val
                
                if (score + accum) > threshold:
                    selected_idx = i
                    break
                accum += score

    selected_candidate = candidates[selected_idx]
    
    # 3. Apply selected orders to g_OrderTable fields mapped locally
    for prov, order_type in selected_candidate.get('orders', []):
        state.g_OrderTable[prov, _F_ORDER_TYPE] = float(order_type)


def update_score_state(state: InnerGameState) -> None:
    """
    Port of UpdateScoreState (FUN_0044c8e0).

    Two-phase order-table refresh.  For each power that has an active alliance
    (g_UnitCount[power] > 0) whose per-power game-board record predates
    g_CurrentRound:

      Pass 1 → UpdateAllyOrderScore (FUN_00442770)
      Pass 2 → RefreshOrderTable    (FUN_00424490)

    Semantics: "stale" means the game board recorded a different round for
    this power than the current simulation round, so its order table needs
    refreshing before the next trial.

    Research.md §5323.
    """
    num_powers = len(state.g_UnitCount)

    # Pass 1 — update ally order scores for stale-round powered alliances
    for power in range(num_powers):
        if state.g_UnitCount[power] <= 0:
            continue
        power_round = state.g_PowerRoundRecord.get(power, 0)
        if power_round != state.g_CurrentRound:
            _update_ally_order_score(state, power)

    # Pass 2 — refresh order table entries for the same stale powers
    for power in range(num_powers):
        if state.g_UnitCount[power] <= 0:
            continue
        power_round = state.g_PowerRoundRecord.get(power, 0)
        if power_round != state.g_CurrentRound:
            _refresh_order_table(state, power)


# ── CheckTimeLimit ────────────────────────────────────────────────────────────

def check_time_limit(state: InnerGameState) -> bool:
    """
    Port of CheckTimeLimit (CheckTimeLimit).

    In the original binary: mutex-protected read of
    g_NetworkState->field_0x20 (the MTL timeout flag set by the timer thread
    when the Move Time Limit fires).  Returns True if time has expired.

    Python equivalent: reads state.mtl_expired directly (GIL guarantees
    atomicity for simple int reads; no additional lock needed).

    Research.md §5358.
    """
    return int(getattr(state, 'mtl_expired', 0)) != 0
