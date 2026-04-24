"""Per-order scoring and proposal evaluation for the Monte-Carlo loop.

Split from monte_carlo.py during the 2026-04 refactor.

- ``evaluate_order_score``    — ScoreOrderSet port; objective function used
  to score one g_OrderTable realisation for a given power.
- ``evaluate_order_proposal`` — EvaluateOrderProposal port; scores and,
  when appropriate, promotes a proposed order into the table, delegating
  to ``..moves.build_support_proposals`` for the SUP synthesis pass.

Module-level deps: ``..state.InnerGameState``,
``..moves.build_support_proposals``, and the field/order-type constants
from ``._flags``.
"""

from ..state import InnerGameState
from ..moves import build_support_proposals

from ._flags import (
    _F_ORDER_TYPE, _F_SECONDARY, _F_DEST_PROV, _F_DEST_COAST,
    _F_HOLD_WEIGHT,
    _F_CONVOY_LO, _F_CONVOY_HI,
    _F_CONVOY_LEG0, _F_CONVOY_LEG1, _F_CONVOY_DEPTH,
    _F_SOURCE_PROV, _F_TARGET_PROV, _F_ORDER_ASGN,
    _ORDER_HLD, _ORDER_MTO, _ORDER_SUP_HLD, _ORDER_SUP_MTO,
    _ORDER_CVY, _ORDER_CTO,
)


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
            if state.get_unit_type(prov) != 'F':
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

        # Snapshot per-order detail fields here.  g_OrderTable is reset at the
        # start of every MC trial *and* once per (power, trial) pair within a
        # single ProcessTurn call, so by the time bot.py reads it after the
        # outer power loop finishes, the table reflects only the last trial of
        # the last power — own-power orders captured in earlier trials are
        # already gone.  Store the full tuple now so candidate.orders is self-
        # contained and survives the resets.
        local_cac.append((
            prov,
            order_type,
            int(ot[prov, _F_DEST_PROV]),
            int(ot[prov, _F_DEST_COAST]),
            int(ot[prov, _F_SECONDARY]),
        ))

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
