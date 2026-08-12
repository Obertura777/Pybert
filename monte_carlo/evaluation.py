"""Per-order scoring and proposal evaluation for the Monte-Carlo loop.

Split from monte_carlo.py during the 2026-04 refactor.

- ``evaluate_order_score``    — ScoreOrderSet port; objective function used
  to score one g_order_table realisation for a given power.
- ``evaluate_order_proposal`` — EvaluateOrderProposal port; scores and,
  when appropriate, promotes a proposed order into the table, delegating
  to ``..moves.build_support_proposals`` for the SUP synthesis pass.

Module-level deps: ``..state.InnerGameState``,
``..moves.build_support_proposals``, and the field/order-type constants
from ``._flags``.
"""

import logging

from ..state import InnerGameState
from ..moves import build_support_proposals

_dbg_log = logging.getLogger("pybert.scoring_dbg")

from ._flags import (
    _F_ORDER_TYPE, _F_SECONDARY, _F_DEST_PROV, _F_DEST_COAST,
    _F_HOLD_WEIGHT,
    _F_CONVOY_LO, _F_CONVOY_HI,
    _F_CONVOY_LEG0, _F_CONVOY_LEG1, _F_CONVOY_DEPTH,
    _F_INCOMING_MOVE,
    _F_THREAT_TOTAL, _F_TARGET_PROV, _F_ORDER_ASGN,
    _F_SUP_TARGET,
    _CONVOY_DEPTH_COMPLETE,
    _ORDER_HLD, _ORDER_MTO, _ORDER_SUP_HLD, _ORDER_SUP_MTO,
    _ORDER_CVY, _ORDER_CTO,
)


def evaluate_order_score(power_idx: int, state: InnerGameState) -> float:
    """
    Port of ScoreOrderSet (FUN_00437600).  Monte Carlo objective function.

    Reads committed order assignments from state.g_order_table and scores the
    complete trial position for `power_idx`.  Six passes A–F mirroring the
    decompiled C.  Returns an accumulated float score (the original returns a
    ulonglong via PackScoreU64 banker-rounding; we keep full precision here).

    Globals consumed (all on InnerGameState):
      Pass A: g_own_reach_score, g_ally_reach_score, g_sc_ownership, g_enemy_presence,
              g_attack_count, g_attack_history, g_max_prov_score_per_power,
              g_province_weight, g_max_province_score
              → g_unit_move_prob, g_order_table[_F_CONVOY_LO/_F_CONVOY_HI]
      Pass B: g_unit_move_prob, g_convoy_chain_score, g_support_demand
              → g_fleet_support_score
      Pass C: g_proximity_score, g_sc_ownership, g_enemy_presence, g_unit_move_prob,
              g_order_table[_F_CONVOY_DEPTH]
              → g_order_table[_F_HOLD_WEIGHT]
      Pass D: unit_info, adj_matrix, g_enemy_reach_score, g_unit_reach_score,
              g_order_table[_F_ORDER_TYPE/_F_TARGET_PROV/_F_ORDER_ASGN]
              → g_cut_support_risk
      Pass E: g_season, g_order_table[_F_ORDER_TYPE]
              → g_order_table[_F_RETREAT_CNT/_F_RETREAT_FLAG]
      Pass F: g_fleet_support_score, g_unit_move_prob, g_cut_support_risk,
              g_convoy_source_prov, g_convoy_chain_score, g_support_demand,
              g_attack_history, g_sc_ownership, g_attack_count,
              g_max_prov_score_per_power
              → returns accumulated score
    """
    ot = state.g_order_table  # shape (256, 30), dtype float64
    state.g_fleet_support_score.fill(0.0)
    state.g_unit_move_prob.fill(0.0)

    # ── Pass A: Unit-order probability ──────────────────────────────────────
    # Two-level gate (EvaluateOrderScore.c:83-87):
    #   Outer: skip when g_own_reach_score < 0, or both own and ally reach are 0.
    #   Inner: field[13] (_F_INCOMING_MOVE) >= 1 → main path; == 0 with field[15] > 0
    #          and the -1 sentinel on fields [18,19] → fallback path; else skip.
    # Outputs: g_unit_move_prob[prov], ot[prov, _F_CONVOY_LO/_F_CONVOY_HI].
    for prov in range(256):
        own_r = int(state.g_own_reach_score[power_idx, prov])
        ally_r = float(state.g_ally_reach_score[power_idx, prov])
        if own_r < 0 or (own_r == 0 and ally_r == 0.0):
            continue

        incoming = int(ot[prov, _F_INCOMING_MOVE])
        if incoming < 1:
            target_v = int(ot[prov, _F_TARGET_PROV])
            if (incoming == 0
                    and target_v > 0
                    and (int(ot[prov, _F_SUP_TARGET]) & int(ot[prov, _F_SUP_TARGET + 1])) == -1):
                # Fallback: no incoming attack but potential target set, no support committed.
                # C: uVar3 reassigned to field[15]; iStack_fc = 0 (since target_v > 0).
                own_sc_f = int(state.g_sc_ownership[power_idx, prov])
                ep       = int(state.g_enemy_presence[power_idx, prov])
                if own_sc_f == 0:
                    if own_r > 0 or ally_r > target_v:
                        move_prob = 1.0
                    elif own_r == 0 and ally_r == float(target_v):
                        move_prob = 0.25 if ep == 1 else 0.33
                    else:
                        if ep != 1:
                            move_prob = 0.25
                        else:
                            # C byte+3 of unit record: 0=army/empty, 1=fleet at bicoastal
                            # coastal position (AssignSupportOrder.c:94 checks == '\x01').
                            # Python: type=='F' and coast!='' identifies bicoastal fleets.
                            ui = state.unit_info.get(prov, {})
                            is_bicoastal = (ui.get('type') == 'F'
                                            and ui.get('coast', '') != '')
                            move_prob = 0.05 if is_bicoastal else 0.15
                else:
                    src_prov_f = int(ot[prov, _F_THREAT_TOTAL])
                    prov_wt    = float(state.g_province_weight[power_idx, prov])
                    if src_prov_f == 1:
                        move_prob = min(prov_wt, 1.0)
                    else:
                        move_prob = min(target_v * 0.5, 1.0)
                state.g_unit_move_prob[prov] = move_prob
                max_s = float(state.g_max_province_score[prov])
                ot[prov, _F_CONVOY_LO] = -max_s
                ot[prov, _F_CONVOY_HI] = -max_s
            continue

        target_prov = int(ot[prov, _F_TARGET_PROV])
        src_prov    = int(ot[prov, _F_THREAT_TOTAL])
        has_move    = src_prov != target_prov

        own_sc      = int(state.g_sc_ownership[power_idx, prov])
        enemy_pres  = int(state.g_enemy_presence[power_idx, prov])
        atk_count   = float(state.g_attack_count[power_idx, prov])
        atk_history = float(state.g_attack_history[power_idx, prov])
        # C reads g_MaxProvinceScore[power*0x100+prov] (DAT_0055b0e8) here —
        # bound in Python as g_max_prov_score_per_power.  This used to read
        # g_defense_score, a duplicate binding of the same C global that
        # nothing ever wrote, so the value was always 0.
        def_score   = float(state.g_max_prov_score_per_power[power_idx, prov])
        prov_weight = float(state.g_province_weight[power_idx, prov])

        if own_sc == 1:
            # Row 1: own SC province — weight by province desirability
            # C line 125: field[0x10]==1 → prov_weight; else field[0xf]*0.5
            if src_prov != target_prov:
                if int(ot[prov, _F_THREAT_TOTAL]) == 1:
                    move_prob = min(prov_weight, 1.0)
                else:
                    move_prob = min(float(ot[prov, _F_TARGET_PROV]) * 0.5, 1.0)
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
                        # g_attack_history * 0.25 + g_defense_score * 0.15
                        move_prob = max(0.0, min(1.0, atk_history * 0.25 + def_score * 0.15))
                else:
                    move_prob = 0.05

        state.g_unit_move_prob[prov] = move_prob
        # Negate defense score into order-table fields [6] and [7] (int64 lo/hi words)
        ot[prov, _F_CONVOY_LO] = -def_score
        ot[prov, _F_CONVOY_HI] = -def_score

    # ── Pass B: Fleet support score update (3 iterations) ───────────────────
    # Propagates convoy-chain depth scores to fleet-adjacent provinces.
    # "Full support" (opp list empty): threshold = chain_score * move_prob * 0.2
    # "Partial support" (opp list non-empty): threshold *= 0.75
    #
    # C condition: head==tail on the per-province support-opportunity sub-list
    # (DAT_00baed74), keyed by target_prov.  g_support_demand (DAT_00baeddc) is
    # a different global and was the wrong proxy.
    #
    # C (EvaluateOrderScore.c:264–329) iterates all provinces with order type 2
    # (MTO), not just fleets.  Guards: _F_INCOMING_MOVE > 0 and _F_ORDER_ASGN < 2
    # (piVar14[0xb] > 0 and piVar14[0x12] < 2 with piVar14 at _F_DEST_PROV).
    _sup_opp_targets: set[int] = {
        opp['target_prov']
        for opp in getattr(state, 'g_support_opportunities_set', [])
    }
    for _ in range(3):
        for prov in range(256):
            if int(ot[prov, _F_ORDER_TYPE]) != _ORDER_MTO:
                continue
            if int(ot[prov, _F_INCOMING_MOVE]) <= 0:
                continue
            if int(ot[prov, _F_ORDER_ASGN]) >= 2:
                continue

            move_prob = float(state.g_unit_move_prob[prov])
            if move_prob > 0.5:
                move_prob = 0.5  # cap per decompile: DAT_00baeda8 * 0.5

            chain_score = float(state.g_convoy_chain_score[prov])

            for adj_prov in state.get_unit_adjacencies(prov):
                fleet_score = float(state.g_fleet_support_score[adj_prov])
                if fleet_score < 0.0:
                    continue  # negative sentinel — skip

                # cond1: adj's support-opportunity sub-list is empty (head==tail)
                has_full_support = adj_prov not in _sup_opp_targets

                if has_full_support:
                    threshold = chain_score * move_prob * 0.2
                else:
                    threshold = chain_score * move_prob * 0.2 * 0.75

                if fleet_score < threshold:
                    state.g_fleet_support_score[adj_prov] = threshold

    # ── Pass C: Hold-weight computation ─────────────────────────────────────
    # Writes g_order_table[prov, _F_HOLD_WEIGHT].
    # Higher values cause AssignHoldSupports to prefer defending over moving.
    for prov in range(256):
        if not state.has_unit(prov):
            continue

        proximity    = float(state.g_proximity_score[power_idx, prov])
        own_sc       = int(state.g_sc_ownership[power_idx, prov])
        enemy_pres   = int(state.g_enemy_presence[power_idx, prov])
        move_prob    = float(state.g_unit_move_prob[prov])
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
            # g_enemy_presence==1 → 0.2/proximity;  ==0 → 0.4/proximity
            if enemy_pres == 1:
                hold_w = 0.2 / proximity
            else:
                hold_w = 0.4 / proximity

        ot[prov, _F_HOLD_WEIGHT] = hold_w

    # ── Pass D: Cut-support risk ─────────────────────────────────────────────
    # Iterates every unit.  For each adjacent province:
    #   own unit adjacencies → accumulate g_unit_reach_score, skipping adj that
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
                    local_128 += float(state.g_unit_reach_score[adj_prov])
            else:
                # Enemy unit: threatens support if it can reach AND is unassigned
                if (state.g_enemy_reach_score[unit_power, adj_prov] == 1 and
                        int(ot[adj_prov, _F_ORDER_ASGN]) == 0):
                    local_128 += 1.0

        local_128 = max(0.0, min(1.0, local_128))

        if unit_power == power_idx:
            state.g_cut_support_risk[prov] = -(1.0 - local_128)
        else:
            state.g_cut_support_risk[prov] =  (1.0 - local_128)

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
    # C initialises local_120 = 500.0.
    # Main branch per unit:
    #   C reads (float)(longlong)fields[6,7] * (float)field[4] — i.e.
    #   convoy_chain_score (or negated defense from Pass A) × hold_weight.
    #   HLD / CVY sentinel: (field18 & field19) == -1 → additive only.
    #   Non-HLD: accumulates convoy_source_score on top.
    # Post-main per-province:
    #   CVY           → +fleet_score
    #   CTO/CTO_CHAIN → +chain_depth + support_demand + fleet_score
    #   move_prob==1.0 with high attack history on unowned SC → +fleet_score*0.4
    #   cut_risk != 0 → +cut_risk * 100
    #
    # Additionally, for the power being scored, each MTO destination's province
    # score contributes to the total — this is the channel through which the MC
    # trial's order choices actually differentiate candidate quality.
    local_120 = 500.0

    for prov in range(256):
        if not state.has_unit(prov):
            continue

        order_type  = int(ot[prov, _F_ORDER_TYPE])
        fleet_score = float(state.g_fleet_support_score[prov])
        move_prob   = float(state.g_unit_move_prob[prov])
        cut_risk    = float(state.g_cut_support_risk[prov])

        # C reads fields[6,7] (convoy chain score / negated defense) × field[4]
        # (hold_weight).  In Python the order table is float64, so read directly.
        order_score = float(ot[prov, _F_CONVOY_LO])
        hold_weight = float(ot[prov, _F_HOLD_WEIGHT])

        # Sentinel: fields 18/19 are -1.0 when unassigned (C uint32 0xffffffff = int32 -1).
        # trial.py initialises both to -1.0; assign_support_order writes real scores.
        # Bitwise AND on float64 never reaches 0xffffffff — compare directly to sentinel.
        is_sentinel = (ot[prov, _F_SUP_TARGET] == -1.0 and ot[prov, _F_SUP_TARGET + 1] == -1.0)
        # C: (local_e8 & uStack_e4)==0xffffffff  →  sentinel; (int)puVar15[-2]==5  →  chain complete.
        # puVar15[-2] = field 20 (_F_ORDER_ASGN), NOT field 0 (_F_ORDER_TYPE).
        is_hld_like = is_sentinel or int(ot[prov, _F_ORDER_ASGN]) == _CONVOY_DEPTH_COMPLETE

        if is_hld_like:
            local_120 += order_score * hold_weight
        else:
            local_118 = order_score * hold_weight + local_120
            # C EvaluateOrderScore.c:683 — local_120 = (float)(longlong)puVar15[-3] + local_118
            # puVar15[-3] = field 18 (_F_SUP_TARGET), written by assign_support_order
            # to final_score_set[power, src].  The -1.0 sentinel means unset → 0.
            src_score = float(ot[prov, _F_SUP_TARGET])
            if src_score < 0.0:
                src_score = 0.0
            local_120 = src_score + local_118

            # C: +100 when field13 (_F_INCOMING_MOVE) == 0 OR field20 (_F_ORDER_ASGN) == MTO,
            # AND the unit's owner differs from the secondary target's owner, AND season == FAL.
            order_asgn = int(ot[prov, _F_ORDER_ASGN])
            if int(ot[prov, _F_INCOMING_MOVE]) == 0 or order_asgn == _ORDER_MTO:
                secondary_prov = int(ot[prov, _F_SECONDARY])
                unit_owner = state.get_unit_power(prov)
                target_owner = (state.get_unit_power(secondary_prov)
                                if state.has_unit(secondary_prov) else None)
                if unit_owner != target_owner and season == 'FAL':
                    local_120 += 100.0

        # After convoy-complete (CVY): PackScoreU64 adds packed fleet contribution
        if order_type == _ORDER_CVY:
            local_120 += fleet_score

        # CTO: chain depth + support demand bonus + fleet score
        if order_type == _ORDER_CTO:
            chain_depth = int(ot[prov, _F_CONVOY_DEPTH])
            sup_demand  = int(state.g_support_demand[prov])
            local_120  += float(chain_depth + sup_demand)
            local_120  += fleet_score

        # Definitely-moving unit with sustained historical attack pressure
        if move_prob == 1.0:
            atk_history = float(state.g_attack_history[power_idx, prov])
            own_sc      = int(state.g_sc_ownership[power_idx, prov])
            atk_count   = float(state.g_attack_count[power_idx, prov])
            def_score   = float(state.g_max_prov_score_per_power[power_idx, prov])
            if atk_history > 10.0 and own_sc == 0 and atk_count > 0.0 and def_score > 0.0:
                local_120 += fleet_score * 0.4

        # Cut-support risk: 100× multiplier (from decompile)
        if cut_risk != 0.0:
            local_120 += cut_risk * 100.0

    return local_120


def insert_candidate_record(state: InnerGameState, candidate: dict,
                             trial_idx: int = 0) -> tuple:
    """Port of InsertCandidateRecord — BST insert into g_candidate_record_list.

    The C function maintains a sorted BST keyed on the order combination so
    that two MC trials producing identical orders for a power share one record.
    On a duplicate the existing node's per-trial score slot is updated rather
    than discarding the new score (matching the TrialEvaluateOrders field-copy
    that follows InsertCandidateRecord in EvaluateOrderProposal.c:918-920).
    Returns (inserted, record): inserted=False means an identical order set
    already existed and record is that existing entry.
    """
    key = (candidate['power'], tuple(sorted(candidate['orders'])))
    key_map: dict = state.__dict__.setdefault('_candidate_key_map', {})
    if key in key_map:
        existing = state.g_candidate_record_list[key_map[key]]
        ts = existing['trial_scores']
        if trial_idx < len(ts):
            ts[trial_idx] = candidate['score']
        return False, existing
    # Pre-allocate 30-slot array (matches C's 30-element per-trial arrays in
    # the candidate record struct copied by TrialEvaluateOrders).
    candidate['trial_scores'] = [0.0] * 30
    candidate['trial_scores'][min(trial_idx, 29)] = candidate['score']
    key_map[key] = len(state.g_candidate_record_list)
    state.g_candidate_record_list.append(candidate)
    return True, candidate


def evaluate_order_proposal(state: InnerGameState, power_idx: int,
                             trial_idx: int = 0) -> None:
    """
    Port of FUN_0044e070 = EvaluateOrderProposal.

    Per-power proposal evaluation called once per power per MC trial.

    Step 1 — Build order sequences from g_order_table.
      In the original binary this constructs DAIDE token sequences; in Python the
      order table is authoritative and no token encoding is needed.  The loop is
      retained as a pass to identify which provinces have active orders.

    Step 2 — Iterate own units; build local_cac (order accumulator), detect
      deviations (local_d31), compute pressure penalty local_d04.
        local_d04 = 500  if province has no SUB entry and order ∉ {MTO, CTO}
        local_d04 = 750  if province is in the alternate-order candidate list
        local_d31 = 1    if order deviates from the expected order in g_deviation_tree

    Step 3 — Score all powers based on own order types.
      Accumulates aiStack_a9c[power] (heat_scores) using province-indexed score arrays.
      MTO/CTO:   proximity vs own-reach comparison; near-end and normal branches.
      SUP_MTO:   check reach arrays at support source → +src+500+dest per power.
      SUP_HLD:   check reach arrays at src/dest     → +src+750+dest per power.
      HLD/CVY:   check reach arrays at province     → +province+4000 per power.

    Step 4 — Early-game adjacency bonus (only when NearEndGameFactor==1.0 and
      DeceitLevel==1).  +160 per trusted-power province adjacent to ≥2 own orders.

    Step 5 — Finalize: zero own heat entry, call evaluate_order_score (ScoreOrderSet),
      insert candidate record into g_candidate_record_list, call build_support_proposals.
    """
    ot = state.g_order_table
    NUM_POWERS = 7
    own_power = getattr(state, 'albert_power_idx', -1)

    # ── Step 1 — Rebuild unit-list node order types (DAIDE encoding skipped) ─
    # C: ResetPerTrialState clears unit-list node field 0x20 (order type on node)
    # only — NOT g_OrderTable.  Step 1 rebuilds node field 0x20 by reading
    # g_OrderTable and calling BuildOrder_CTO_Ring (MTO), FUN_00460770 (SUP_HLD),
    # FUN_004607f0 (SUP_MTO), BuildOrder_CVY (CVY), BuildOrder_CTO (CTO).
    # AssignSupportOrder fields (6, 18, 19, 20) survive from move generation.
    # Python: g_order_table is authoritative (no separate node structs), so
    # this step is a no-op.  active_provs is enumerated for structural parity.
    active_provs = [
        prov for prov in range(256) if int(ot[prov, _F_ORDER_TYPE]) != 0
    ]
    _ = active_provs  # enumerated; node reconstruction elided in Python

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

        # Snapshot per-order detail fields here.  g_order_table is reset at the
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

        # Deviation detection: applies only to Albert's own power (C line 214)
        if power_idx == own_power:
            expected = state.g_deviation_tree.get((power_idx, prov), 0)
            if expected != 0 and expected != order_type:
                local_d31 = 1

        # SUB-map check (C lines 256-278): runs for ANY power_idx, not just own.
        # If province IS in committed order map and order is not MTO/CTO → 500.
        if prov in state.g_sub_order_map:
            if order_type not in (_ORDER_MTO, _ORDER_CTO):
                local_d04 = 500

        # Alternate-order list (C lines 279-320): own_power only.
        # For MTO/CTO: skip 750 iff current dest matches expected dest in record
        # (C line 311: ppiVar11[9] == found_node[4]).  For other order types: always 750.
        if power_idx == own_power:
            alt_map = state.g_alt_order_list.get(power_idx, {})
            if prov in alt_map:
                if order_type in (_ORDER_MTO, _ORDER_CTO):
                    if int(ot[prov, _F_DEST_PROV]) != alt_map[prov]:
                        local_d04 = 750
                else:
                    local_d04 = 750

    # ── Gate: duplicate-record and deviation check (C lines 327–358) ───────────
    # C: BST search for local_cac in g_CandidateRecordList; if result == sentinel
    # (no existing match) AND local_d31 != 1 (no deviation), enter the scoring and
    # proposal block.  Walk A/B, Steps 3–5, and BuildSupportProposals are ALL
    # inside this gate in the original binary.
    # Python: _candidate_key_map provides an O(1) lookup instead of the BST walk.
    _gate_key = (power_idx, tuple(sorted(local_cac)))
    _already_exists = _gate_key in state.__dict__.setdefault('_candidate_key_map', {})

    if not _already_exists and local_d31 == 0:
        # ── Walk A: committed-order serialisation (C lines 375–440) ─────────
        # FUN_00433a20 re-serialises each committed order into local_648/local_cbc.
        # Python: local_cac already holds the full data; no-op here.

        # ── Walk B: conviction/deceit trust adjustment (C lines 443–488) ─────
        # DAT_00baed68 == 1 (g_deceit_level) gates this block.
        # For own MTO units whose destination holds an enemy Army, assign
        # local_d24 from ally-trust scores (last qualifying unit wins — C assigns,
        # not accumulates).  Feeds C line 887:
        #   local_c10 = global_base + local_d04 + local_d24
        local_d24 = 0
        if state.g_deceit_level == 1:
            for prov, info in state.unit_info.items():
                if info['power'] != power_idx:
                    continue
                order_type = int(ot[prov, _F_ORDER_TYPE])
                if order_type == 0:
                    continue
                if order_type != _ORDER_MTO:
                    continue
                dest_prov = int(ot[prov, _F_DEST_PROV])
                # C line 455: byte+3 of dest unit record — 0 means no unit present
                if not state.has_unit(dest_prov):
                    continue
                # C lines 460-464: type != 'A' → power set to 0x14 (invalid) → skip fleet
                dest_unit_type = state.get_unit_type(dest_prov)
                if dest_unit_type in ('F', 'FLT'):
                    continue
                dest_power = state.get_unit_power(dest_prov)
                if dest_power is None or dest_power == power_idx:
                    continue
                # C lines 467-483: assign (not +=) local_d24 from trust direction
                trust_fwd = float(state.g_ally_trust_score[power_idx, dest_power])
                if trust_fwd < 1.0:
                    local_d24 = 50         # 0x32 — low forward trust
                else:
                    trust_rev = float(state.g_ally_trust_score[dest_power, power_idx])
                    if trust_rev > 1.0:
                        local_d24 = 150    # 0x96 — high mutual trust
                    else:
                        local_d24 = 110    # 0x6e — medium trust

        # ── Step 3 — per-power heat score accumulation ───────────────────────
        heat_scores = [0] * NUM_POWERS
        # local_c1c: near-end conviction bonus accumulated once per own MTO/CTO
        # unit (C line 129 init, line 564 += 0x32).  Stored in candidate record.
        local_c1c = 0

        for prov, info in state.unit_info.items():
            if info['power'] != power_idx:
                continue

            order_type = int(ot[prov, _F_ORDER_TYPE])
            if order_type == 0:
                continue

            src = prov

            if order_type in (_ORDER_MTO, _ORDER_CTO):
                dest = int(ot[prov, _F_DEST_PROV])

                # Near-end SC-under-threat conviction check (C lines 531–563).
                # Evaluated BEFORE the per-power loop.  When it fires, +50 goes
                # to local_c1c and the per-power heat loop is skipped for this
                # unit (C: goto LAB_0044ee24 → LAB_0044f133, bypassing LAB_0044ee60).
                own_r_src  = float(state.g_own_reach_score[power_idx, src])
                ally_r_src = float(state.g_ally_reach_score[power_idx, src])
                prox_src   = float(state.g_proximity_score[power_idx, src])
                _skip_heat = False

                # C lines 531–562: own SC + lead flag + NearEnd > 5
                #   + proximity[param_1,src] > own_reach + ally_reach
                if (state.g_near_end_game_factor > 5.0
                        and state.g_other_power_lead_flag == 1
                        and int(state.g_sc_ownership[power_idx, src]) == 1
                        and prox_src > own_r_src + ally_r_src):
                    local_c1c += 50
                    _skip_heat = True
                # C LAB_0044edc1: NearEnd > 6 fallback (no SC-ownership requirement)
                elif (state.g_near_end_game_factor > 6.0
                        and state.g_other_power_lead_flag == 1
                        and prox_src > own_r_src + ally_r_src):
                    local_c1c += 50
                    _skip_heat = True

                if not _skip_heat:
                    for power in range(NUM_POWERS):
                        if state.g_near_end_game_factor > 6.0 and state.g_other_power_lead_flag == 1:
                            # Near-end branch: proximity[power,src] > own_reach + ally_reach at src
                            prox  = float(state.g_proximity_score[power, src])
                            own_r = float(state.g_own_reach_score[power_idx, src])
                            ally_r = float(state.g_ally_reach_score[power_idx, src])
                            if prox > own_r + ally_r:
                                heat_scores[power] += src + dest + 1000
                        else:
                            # Normal branch: proximity[power,src] > own_reach[power_idx,src]
                            prox  = float(state.g_proximity_score[power, src])
                            own_r = float(state.g_own_reach_score[power_idx, src])
                            if prox > own_r:
                                # H1 fix: filter adjacencies by unit type, matching C's
                                # AdjacencyList_FilterByUnitType (EvaluateOrderProposal.c:485-552).
                                unit_type = info.get('type', 'A')
                                for adj_q in state.get_unit_adjacencies(prov):
                                    if unit_type in ('A', 'AMY') and adj_q in state.water_provinces:
                                        continue
                                    if unit_type in ('F', 'FLT') and adj_q in state.land_provinces:
                                        continue
                                    if state.g_own_reach_score[power_idx, adj_q] > 1:
                                        heat_scores[power] += src + dest + 1000
                                        break

            elif order_type == _ORDER_SUP_MTO:
                dest = int(ot[prov, _F_DEST_PROV])

                for power in range(NUM_POWERS):
                    if (state.g_own_reach_score[power_idx, src] > 0
                            or state.g_convoy_support[power_idx, src] > 0
                            or state.g_convoy_reach[power_idx, src] > 0
                            or state.g_support_reach[power_idx, src] > 0):
                        heat_scores[power] += src + 500 + dest

            elif order_type == _ORDER_SUP_HLD:
                dest = int(ot[prov, _F_SECONDARY])

                for power in range(NUM_POWERS):
                    if (state.g_own_reach_score[power_idx, src] > 0
                            or state.g_convoy_reach[power_idx, dest] > 0
                            or state.g_support_reach[power_idx, src] > 0):
                        heat_scores[power] += src + 0x2ee + dest  # 0x2ee = 750

            elif order_type in (_ORDER_HLD, _ORDER_CVY):
                for power in range(NUM_POWERS):
                    if (state.g_own_reach_score[power_idx, src] > 0
                            or state.g_support_reach[power_idx, src] > 0):
                        heat_scores[power] += src + 4000

        # ── Step 4 — early-game adjacency bonus ──────────────────────────────
        early_game_bonus = 0
        if state.g_near_end_game_factor == 1.0 and state.g_deceit_level == 1:
            # H1 fix: filter adjacencies by unit type (armies skip water, fleets skip land)
            adj_order_count = [0] * 256
            for prov, info in state.unit_info.items():
                if info['power'] != power_idx:
                    continue
                unit_type = info.get('type', 'A')
                for adj in state.get_unit_adjacencies(prov):
                    if unit_type in ('A', 'AMY') and adj in state.water_provinces:
                        continue
                    if unit_type in ('F', 'FLT') and adj in state.land_provinces:
                        continue
                    adj_order_count[adj] += 1

            for prov in range(256):
                if not state.has_unit(prov):
                    continue
                unit_power = state.get_unit_power(prov)
                if unit_power == power_idx:
                    continue
                trust_lo = int(state.g_ally_trust_score[power_idx, unit_power])
                trust_hi = int(state.g_ally_trust_score_hi[power_idx, unit_power])
                # C: (-1 < trust_hi) && (trust_hi > 0 || (uint)trust_lo > 1) && adj_count > 1
                if trust_hi >= 0 and (trust_hi > 0 or trust_lo > 1) and adj_order_count[prov] > 1:
                    early_game_bonus += 0xa0  # +160 per qualifying province
            state.g_early_game_bonus += early_game_bonus

        # ── Step 5 — finalize, score, record, and propose ────────────────────
        heat_scores[power_idx] = 0  # zero own entry (no self-pressure)

        score = evaluate_order_score(power_idx, state)

        candidate = {
            'power': power_idx,
            'orders': local_cac,
            'score': score,
            'final_dim_score': score,
            'heat_scores': heat_scores,
            'deviation': local_d31,
            'pressure_cost': local_d04,
            'trust_adjustment': local_d24,
            'conviction_bonus': local_c1c,
            'early_game_bonus': early_game_bonus,
            'sc_count': int(state.sc_count[power_idx]),
        }
        insert_candidate_record(state, candidate, trial_idx)

        if power_idx == 3 and _dbg_log.isEnabledFor(logging.DEBUG):
            id2n = getattr(state, '_id_to_prov', {})
            _order_names = {0: 'NUL', 1: 'HLD', 2: 'MTO', 3: 'SUP_HLD',
                            4: 'SUP_MTO', 5: 'SUP_MTO', 6: 'CTO', 7: 'CVY'}
            _summary = []
            for entry in local_cac:
                _p = entry[0]
                _ot = entry[1]
                _dst = entry[2] if len(entry) > 2 else _p
                _pn = id2n.get(_p, str(_p))
                _dn = id2n.get(_dst, str(_dst))
                _otn = _order_names.get(_ot, str(_ot))
                _summary.append(f"{_pn}:{_otn}→{_dn}" if _ot == 2 else f"{_pn}:{_otn}")
            _dbg_log.debug(
                "EVAL_DBG[GER] score=%.1f orders=[%s]",
                score, ", ".join(_summary),
            )

        build_support_proposals(state, power_idx)
