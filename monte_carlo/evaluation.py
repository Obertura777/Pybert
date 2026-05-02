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
    _F_SOURCE_PROV, _F_TARGET_PROV, _F_ORDER_ASGN,
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
      Pass A: g_threat_level, g_sc_ownership, g_enemy_presence, g_attack_count,
              g_attack_history, g_defense_score, g_province_weight
              → g_unit_move_prob, g_order_table[_F_DEF_NEG_*]
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
              g_attack_history, g_sc_ownership, g_attack_count, g_defense_score
              → returns accumulated score
    """
    ot = state.g_order_table  # shape (256, 30), dtype float64
    state.g_fleet_support_score.fill(0.0)
    state.g_unit_move_prob.fill(0.0)

    # ── Pass A: Unit-order probability ──────────────────────────────────────
    # Gate: order_table[prov, 13] (_F_INCOMING_MOVE) is the threat-level field
    # that guards entry; C line 86: uVar3 = local_f4[0xd]; skip when <= 0.
    # Written to g_unit_move_prob[prov] and negated defense into fields [6]/[7].
    for prov in range(256):
        if int(ot[prov, _F_INCOMING_MOVE]) <= 0:
            continue

        target_prov = int(ot[prov, _F_TARGET_PROV])
        src_prov    = int(ot[prov, _F_SOURCE_PROV])
        has_move    = src_prov != target_prov

        own_sc      = int(state.g_sc_ownership[power_idx, prov])
        enemy_pres  = int(state.g_enemy_presence[power_idx, prov])
        atk_count   = float(state.g_attack_count[power_idx, prov])
        atk_history = float(state.g_attack_history[power_idx, prov])
        def_score   = float(state.g_defense_score[power_idx, prov])
        prov_weight = float(state.g_province_weight[power_idx, prov])

        if own_sc == 1:
            # Row 1: own SC province — weight by province desirability
            # C line 125: field[0x10]==1 → prov_weight; else field[0xf]*0.5
            if src_prov != target_prov:
                if int(ot[prov, _F_SOURCE_PROV]) == 1:
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
    _sup_opp_targets: set[int] = {
        opp['target_prov']
        for opp in getattr(state, 'g_support_opportunities_set', [])
    }
    for _ in range(3):
        for prov in range(256):
            if state.get_unit_type(prov) != 'F':
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
            def_score   = float(state.g_defense_score[power_idx, prov])
            if atk_history > 10.0 and own_sc == 0 and atk_count > 0.0 and def_score > 0.0:
                local_120 += fleet_score * 0.4

        # Cut-support risk: 100× multiplier (from decompile)
        if cut_risk != 0.0:
            local_120 += cut_risk * 100.0

    # ── Destination-discrimination bonus ────────────────────────────────────
    # The else branch above adds ot[src, _F_SUP_TARGET] = final_score_set[power, src]
    # (the source province score), which is constant for all orders from a given
    # unit — it does NOT vary with destination.  Destination discrimination in the
    # C comes from fleet-support and convoy-chain scoring passes (Pass B / puVar15[-8]
    # fleet_score accumulation) that aren't fully ported.  Compensate by adding
    # each own unit's end-of-province final_score_set entry directly: destination
    # for MTO/CTO, source for HLD/CVY/SUP_*.  Crediting both move and stay
    # alternatives prevents the bot from gratuitously vacating would-be-captured
    # SCs in Fall (e.g. A SPA - MAR) just because MTO had a unilateral lead.
    #
    # Fall capture bonus: ending FAL at an unowned SC gains that SC next turn —
    # a strategic +1 SC.  Mirrors EvaluateOrderScore.c L692-694, scaled up to
    # dominate BFS-derived destination scores (a corner SC like SPA can otherwise
    # lose to a central non-SC like GAS whose heat-diffusion value is higher).
    fall_capture = season == 'FAL'
    sc_provinces = getattr(state, 'sc_provinces', frozenset())
    for prov, info in state.unit_info.items():
        if info['power'] != power_idx:
            continue
        o = int(ot[prov, _F_ORDER_TYPE])
        if o == _ORDER_MTO or o == _ORDER_CTO:
            end_prov = int(ot[prov, _F_DEST_PROV])
        else:
            end_prov = prov
        # final_score_set is (7, 256) — province scores from score_order_candidates
        local_120 += float(state.final_score_set[power_idx, end_prov])
        if (fall_capture
                and end_prov in sc_provinces
                and state.g_sc_ownership[power_idx, end_prov] == 0):
            local_120 += 500.0

    return local_120


def evaluate_order_proposal(state: InnerGameState, power_idx: int) -> None:
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

        # Deviation detection: applies only to Albert's own power
        if power_idx == own_power:
            expected = state.g_deviation_tree.get((power_idx, prov), 0)
            if expected != 0 and expected != order_type:
                local_d31 = 1

            # SUB-map check: province not in committed order map and not MTO/CTO → 500
            if prov in state.g_sub_order_map:
                if order_type not in (_ORDER_MTO, _ORDER_CTO):
                    local_d04 = 500

            # Alternate-order list: → 750 (overrides 500)
            alt_list = state.g_alt_order_list.get(power_idx, set())
            if prov in alt_list:
                local_d04 = 750

    # ── No-deviation committed-order copy (C lines 358–440) ─────────────────
    # Gate: (ppiVar9 == local_cdc) && (local_d31 != 1).
    # The ppiVar9==local_cdc check tests whether g_CandidateRecordList is at
    # its sentinel (no prior matching entry); in Python that check collapses to
    # local_d31 == 0 since the list-sentinel comparison has no Python analogue.
    #
    # Walk A (lines 375–440, FUN_00433a20 serialisation): copies fields
    # 0x0c/0x20–0x38 from each committed order entry and serialises them into
    # the local candidate buffer (local_648/local_cbc).  In Python, local_cac
    # already contains this data from Step 2; no separate pass is needed.
    #
    # Walk B (lines 443–488, DAT_00baed68 trust branch): for MTO orders whose
    # destination is occupied by an enemy Army, compute local_d24 from the
    # ally-trust scores.  The result feeds C line 887:
    #   local_c10 = global_base + local_d04 + local_d24
    # Python stores it in candidate['trust_adjustment'].
    local_d24 = 0
    if local_d31 == 0:
        for prov, info in state.unit_info.items():
            if info['power'] != power_idx:
                continue
            order_type = int(ot[prov, _F_ORDER_TYPE])
            # Walk A: all non-zero orders are re-serialised (FUN_00433a20);
            # in Python this is implicit in local_cac — nothing extra needed.
            if order_type == 0:
                continue
            # Walk B: trust-adjustment applies only to MTO (field_0x20 == 2)
            if order_type != _ORDER_MTO:
                continue
            dest_prov = int(ot[prov, _F_DEST_PROV])
            # Line 455: gate on unit presence at destination
            if not state.has_unit(dest_prov):
                continue
            # Lines 460-464: Army-only check — fleet at dest skips trust scoring
            dest_unit_type = state.get_unit_type(dest_prov)
            if dest_unit_type in ('F', 'FLT'):
                continue
            dest_power = state.get_unit_power(dest_prov)
            if dest_power is None or dest_power == power_idx:
                continue
            # Lines 467-483: forward/reverse trust accumulates into local_d24
            # C adds per-unit (not assigns): multiple MTO units each contribute.
            trust_fwd = float(state.g_ally_trust_score[power_idx, dest_power])
            if trust_fwd < 1.0:
                local_d24 += 50        # low forward trust
            else:
                trust_rev = float(state.g_ally_trust_score[dest_power, power_idx])
                if trust_rev > 1.0:
                    local_d24 += 150   # high mutual trust
                else:
                    local_d24 += 110   # medium trust

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
                if (state.g_other_power_lead_flag == 1
                        and state.g_near_end_game_factor > 5.0
                        and state.g_sc_ownership[power_idx, src] == 1):
                    heat_scores[power] += 50

                if state.g_near_end_game_factor > 6.0 and state.g_other_power_lead_flag == 1:
                    # Near-end branch: DAT_005460ec > DAT_0058f8ec + DAT_005658ec
                    # (g_proximity_score > g_own_reach_score + g_ally_reach_score at src)
                    prox  = float(state.g_proximity_score[power, src])
                    own_r = float(state.g_own_reach_score[power_idx, src])
                    ally_r = float(state.g_ally_reach_score[power_idx, src])
                    if prox > own_r + ally_r:
                        heat_scores[power] += src + dest + 1000
                else:
                    # Normal branch: DAT_005460ec[src+power*0x40] > DAT_0058f8ec[src+param_1*0x40]
                    prox  = float(state.g_proximity_score[power, src])
                    own_r = float(state.g_own_reach_score[power_idx, src])
                    if prox > own_r:
                        # H1 fix: filter adjacencies by unit type, matching C's
                        # AdjacencyList_FilterByUnitType (EvaluateOrderProposal.c:485-552).
                        # Without this, fleets see landlocked adjacencies and armies
                        # see sea zones, inflating heat scores for unreachable provinces.
                        unit_type = info.get('type', 'A')
                        for adj_q in state.get_unit_adjacencies(prov):
                            # Skip provinces this unit type cannot reach
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
                # Any reach array non-zero at support source → press this province
                if (state.g_own_reach_score[power_idx, src] > 0
                        or state.g_convoy_support[power_idx, src] > 0
                        or state.g_convoy_reach[power_idx, src] > 0
                        or state.g_support_reach[power_idx, src] > 0):
                    heat_scores[power] += src + 500 + dest

        elif order_type == _ORDER_SUP_HLD:
            dest = int(ot[prov, _F_SECONDARY])  # province being held/supported

            for power in range(NUM_POWERS):
                # DAT_0058f8ec[src*8] > 0 OR DAT_005c48ec[dest*8] > 0 OR DAT_005ba0ec[src*8] > 0
                if (state.g_own_reach_score[power_idx, src] > 0
                        or state.g_convoy_reach[power_idx, dest] > 0
                        or state.g_support_reach[power_idx, src] > 0):
                    heat_scores[power] += src + 0x2ee + dest  # 0x2ee = 750

        elif order_type in (_ORDER_HLD, _ORDER_CVY):
            for power in range(NUM_POWERS):
                # DAT_0058f8ec[dest*8] > 0 OR DAT_005ba0ec[dest*8] > 0
                if (state.g_own_reach_score[power_idx, src] > 0
                        or state.g_support_reach[power_idx, src] > 0):
                    heat_scores[power] += src + 4000

    # ── Step 4 — early-game adjacency bonus ──────────────────────────────────
    early_game_bonus = 0
    if state.g_near_end_game_factor == 1.0 and state.g_deceit_level == 1:
        # Count how many own-unit adjacencies cover each province
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
            trust = float(state.g_ally_trust_score[power_idx, unit_power])
            if trust >= 2 and adj_order_count[prov] > 1:
                early_game_bonus += 0xa0  # +160 per qualifying province
        state.g_early_game_bonus += early_game_bonus

    # ── Step 5 — finalize, score, record, and propose ────────────────────────
    heat_scores[power_idx] = 0  # zero own entry (no self-pressure)

    score = evaluate_order_score(power_idx, state)

    candidate = {
        'power': power_idx,
        'orders': local_cac,
        'score': score,
        'trial_scores': [score],
        'final_dim_score': score,
        'heat_scores': heat_scores,
        'deviation': local_d31,
        'pressure_cost': local_d04,
        'trust_adjustment': local_d24,
        'early_game_bonus': early_game_bonus,
        'sc_count': int(state.sc_count[power_idx]),
    }
    state.g_candidate_record_list.append(candidate)

    # Debug: log candidate details for Germany (power 3)
    if power_idx == 3 and _dbg_log.isEnabledFor(logging.DEBUG):
        id2n = getattr(state, '_id_to_prov', {})
        _order_names = {0: 'NUL', 1: 'HLD', 2: 'MTO', 3: 'SUP_HLD',
                        4: 'SUP_MTO', 5: 'SUP_MTO', 6: 'CTO', 7: 'CVY'}
        _summary = []
        for entry in local_cac:
            p = entry[0]
            ot = entry[1]
            dst = entry[2] if len(entry) > 2 else p
            pn = id2n.get(p, str(p))
            dn = id2n.get(dst, str(dst))
            otn = _order_names.get(ot, str(ot))
            _summary.append(f"{pn}:{otn}→{dn}" if ot == 2 else f"{pn}:{otn}")
        _dbg_log.debug(
            "EVAL_DBG[GER] score=%.1f orders=[%s]",
            score, ", ".join(_summary),
        )

    build_support_proposals(state, power_idx)
