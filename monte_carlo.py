import copy
import random
import numpy as np
from .state import InnerGameState
from .heuristics import score_order_candidates_all_powers
from .moves import enumerate_hold_orders, enumerate_convoy_reach, compute_safe_reach, build_support_opportunities, build_support_proposals

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


def process_turn(state: InnerGameState, num_trials: int = 4000) -> list:
    """
    Orchestrator of the Monte Carlo loop (BuildAndSendSUB / ScoreOrderCandidates).

    1. generate_orders — full influence-matrix pipeline + order enumeration.
    2. score_order_candidates_all_powers — dot-product scoring of enumerated candidates.
    3. MC trial loop: EvaluateOrderProposal per trial, track best candidate.
    """
    own_power = getattr(state, 'albert_power_idx', 0)

    # Full influence-matrix + enumeration pipeline
    generate_orders(state, own_power)

    # Dot-product scoring of enumerated candidates with random round weights
    round_weights = [random.uniform(0.8, 1.2) for _ in range(10)]
    score_order_candidates_all_powers(state, round_weights, own_power)

    # BuildSupportProposals runs once per power after candidate scoring
    for p in range(7):
        build_support_proposals(state, p)

    best_candidate_set = []
    max_score = -1.0

    for _ in range(num_trials):
        state.g_CandidateRecordList.clear()
        for p in range(7):
            evaluate_order_proposal(state, p)

        own_records = [r for r in state.g_CandidateRecordList if r['power'] == own_power]
        if own_records:
            best = max(own_records, key=lambda r: r['score'])
            if best['score'] > max_score:
                max_score = best['score']
                best_candidate_set = [best]

    return best_candidate_set


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
