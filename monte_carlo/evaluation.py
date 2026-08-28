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


# ScoreOrderCandidates normalizes a best province key to 1000 + 15.  Gaining
# a supply centre is worth more than merely occupying one province: it also
# buys another unit at the following adjustment.  The recovered evaluator
# accounts for the positional score but has no Python-side projection of that
# future unit, which made an empty owned home centre worth ~1015 while an army
# poised to capture SPA/POR was worth only the destination's small positional
# score.  Two normalized province values represent those two durable assets.
_NEW_SUPPLY_CENTER_OCCUPATION_BONUS = 2.0 * 1015.0

from ._flags import (
    _F_ORDER_TYPE, _F_SECONDARY, _F_DEST_PROV, _F_DEST_COAST,
    _F_MOVE_PROB, _F_UNIT_REACH_SCORE,
    _F_CONVOY_LO, _F_CONVOY_HI,
    _F_SELECTED_SCORE_LO, _F_SELECTED_SCORE_HI,
    _F_CONVOY_LEG0, _F_CONVOY_LEG1, _F_CONVOY_LEG2, _F_CONVOY_DEPTH,
    _F_INCOMING_MOVE,
    _F_THREAT_TOTAL, _F_TARGET_PROV, _F_ORDER_ASGN,
    _F_SUP_CHAIN_CONFLICT, _F_MOVE_HISTORY,
    _F_SUP_TARGET,
    _CONVOY_DEPTH_COMPLETE,
    _ORDER_HLD, _ORDER_MTO, _ORDER_SUP_HLD, _ORDER_SUP_MTO,
    _ORDER_CVY, _ORDER_CTO,
)


def snapshot_order_entry(order_table, prov: int) -> tuple:
    """Capture one order with its complete 30-field table row.

    The first five values retain the legacy Python tuple layout used by the
    ranking and diagnostic code.  The trailing tuple mirrors the complete C
    trial-order record, including CTO convoy legs and bookkeeping fields that
    otherwise disappear when ``g_order_table`` is reset for the next trial.
    """
    row = tuple(float(value) for value in order_table[prov, :30])
    return (
        int(prov),
        int(order_table[prov, _F_ORDER_TYPE]),
        int(order_table[prov, _F_DEST_PROV]),
        int(order_table[prov, _F_DEST_COAST]),
        int(order_table[prov, _F_SECONDARY]),
        row,
    )


def restore_order_entry(order_table, entry, *, full_row: bool = False) -> int:
    """Restore a candidate-order snapshot and return its province.

    ``full_row`` is used for final submission, where the serializer needs CTO
    route legs.  Monte-Carlo staging uses the semantic order fields only, as
    the C ordered-set reconstruction does, so trial-local score fields can be
    recomputed normally.
    """
    prov = int(entry[0])
    if full_row:
        order_table[prov, :] = 0.0
        if len(entry) > 5 and isinstance(entry[5], (list, tuple)):
            row = entry[5]
            width = min(len(row), order_table.shape[1])
            order_table[prov, :width] = row[:width]

    order_type = int(entry[1]) if len(entry) > 1 else 0
    order_table[prov, _F_ORDER_TYPE] = float(order_type)
    if len(entry) > 2:
        order_table[prov, _F_DEST_PROV] = float(entry[2])
    if len(entry) > 3:
        order_table[prov, _F_DEST_COAST] = float(entry[3])
    if len(entry) > 4:
        order_table[prov, _F_SECONDARY] = float(entry[4])

    # CTO's convoy list is part of the C order record, rather than one of the
    # common five scalar fields copied for MTO/SUP/CVY orders.
    if order_type == _ORDER_CTO and len(entry) > 5 and isinstance(entry[5], (list, tuple)):
        row = entry[5]
        for field in (
            _F_CONVOY_LEG0, _F_CONVOY_LEG1, _F_CONVOY_LEG2,
            _F_CONVOY_DEPTH,
        ):
            if field < len(row):
                order_table[prov, field] = float(row[field])
    return prov


def candidate_orders_key(power: int, orders) -> tuple:
    """Return the C-equivalent identity for a serialized order set.

    Full table rows are preservation payload, not part of the DAIDE order
    sequence compared by ``FUN_00465cf0``.  Restrict duplicate detection to
    the five semantic scalar fields so transient score columns do not turn the
    same submitted orders into distinct Monte-Carlo candidates.
    """
    semantic_orders = []
    for entry in orders:
        if not isinstance(entry, (list, tuple)):
            continue
        semantic_orders.append(tuple(entry[:5]))
    return int(power), tuple(sorted(semantic_orders))


def candidate_record_key(record: dict) -> tuple:
    """Return and cache a candidate record's immutable semantic order key.

    Candidate order snapshots are fixed when ``InsertCandidateRecord`` creates
    the record; later scoring rounds mutate scores and rank metadata only.  C
    retains a direct pointer to the tree node, whereas the old Python port
    repeatedly rebuilt and sorted the same tuple key to rediscover that node.
    Keeping the key on the record preserves the public list/dict model while
    making identity lookup proportional to the number of selected slots, not
    the number of orders times every candidate-rescore pass.
    """
    cached = record.get('_orders_key')
    if cached is None:
        cached = candidate_orders_key(
            int(record.get('power', -1)), record.get('orders', [])
        )
        record['_orders_key'] = cached
    return cached


def _projected_new_supply_center_count(
    power_idx: int,
    state: InnerGameState,
) -> int:
    """Count unowned supply centres occupied by this complete order set.

    Candidate evaluation is intentionally order-set based.  Looking at one
    order at a time cannot distinguish ``GAS-SPA, SPA-POR`` (two projected
    captures) from vacating SPA without a replacement.  Only uncontested
    destinations are credited here; attacks on an enemy-occupied centre still
    rely on the existing threat/support evaluator rather than receiving a
    speculative capture reward.
    """
    ot = state.g_order_table
    projected_occupied: set[int] = set()

    for source, unit in state.unit_info.items():
        if int(unit.get('power', -1)) != power_idx:
            continue
        order_type = int(ot[source, _F_ORDER_TYPE])
        if order_type in (_ORDER_MTO, _ORDER_CTO):
            destination = int(ot[source, _F_DEST_PROV])
            occupant = state.unit_info.get(destination)
            if (occupant is not None
                    and int(occupant.get('power', -1)) != power_idx):
                continue
            projected_occupied.add(destination)
        elif order_type != 0:
            # HLD, SUP and CVY keep the unit in its current province.
            projected_occupied.add(int(source))

    return sum(
        1
        for province in projected_occupied
        if (province in state.sc_provinces
            and int(state.g_board_sc_ownership[power_idx, province]) == 0)
    )


def evaluate_order_score(power_idx: int, state: InnerGameState) -> float:
    """
    Port of ScoreOrderSet (FUN_00437600).  Monte Carlo objective function.

    Reads committed order assignments from state.g_order_table and scores the
    complete trial position for `power_idx`.  Six passes A–F mirroring the
    decompiled C.  Returns an accumulated float score (the original returns a
    ulonglong via PackScoreU64 banker-rounding; we keep full precision here).

    Globals consumed (all on InnerGameState):
      Pass A: g_own_reach_score, g_sc_ownership, g_enemy_presence,
              g_attack_count, g_attack_history, g_max_prov_score_per_power,
              g_province_weight
              → g_unit_move_prob, g_order_table[_F_CONVOY_LO/_F_CONVOY_HI]
      Pass B: order-table counts/scores, attack state, fleet adjacency
              → g_unit_move_prob, g_fleet_support_score
      Pass C: g_threat_level, g_sc_ownership, g_enemy_presence, g_unit_move_prob,
              g_order_table[_F_INCOMING_MOVE]
              → g_order_table[_F_UNIT_REACH_SCORE]
      Pass D: unit_info, adj_matrix, g_enemy_reach_score, g_unit_reach_score,
              g_order_table[_F_ORDER_TYPE/_F_TARGET_PROV/_F_ORDER_ASGN]
              → g_cut_support_risk
      Pass E: g_season, province occupancy, attack history/count,
              g_order_table selected-score/support fields
              → conditionally clears g_order_table selected-score pair
      Pass F: g_fleet_support_score, g_unit_move_prob, g_cut_support_risk,
              g_convoy_source_prov, g_convoy_chain_score, g_support_demand,
              g_attack_history, g_sc_ownership, g_attack_count,
              g_max_prov_score_per_power
              → returns accumulated score
    """
    ot = state.g_order_table  # shape (256, 30), dtype float64
    # ProcessTurn clears the complete order table once at trial start.  C's
    # EvaluateOrderScore does not clear fields 4 or 24 here: move builders may
    # already have written the fleet/order contribution in field 24.

    # ── Pass A: Unit-order probability ──────────────────────────────────────
    # Two-level gate (EvaluateOrderScore.c:83-87):
    #   Outer: skip unless the signed int64 g_own_reach_score is positive.
    #   Inner: field[13] (_F_INCOMING_MOVE) >= 1 → main path; == 0 with field[15] > 0
    #          and the -1 sentinel on fields [18,19] → fallback path; else skip.
    # Outputs: g_unit_move_prob[prov], ot[prov, _F_CONVOY_LO/_F_CONVOY_HI].
    for prov in range(256):
        # DAT_0058f8e8/ec is one signed int64.  Python stores that scalar in
        # g_own_reach_score; g_ally_reach_score is DAT_005658e8, a different
        # global and must not be substituted for the high dword.
        own_r = int(state.g_own_reach_score[power_idx, prov])
        if own_r <= 0:
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
                    if own_r > target_v:
                        move_prob = 1.0
                    elif own_r == target_v:
                        move_prob = 0.25 if ep == 1 else 0.33
                    else:
                        if ep != 1:
                            move_prob = 0.25
                        else:
                            # Province-record byte +3 is the supply-centre
                            # flag. C assigns 0.05 on an SC and 0.15 elsewhere.
                            move_prob = 0.05 if prov in state.sc_provinces else 0.15
                else:
                    src_prov_f = int(ot[prov, _F_THREAT_TOTAL])
                    prov_wt    = float(state.g_province_weight[power_idx, prov])
                    if src_prov_f == 1:
                        move_prob = min(prov_wt, 1.0)
                    else:
                        move_prob = min(target_v * 0.5, 1.0)
                state.g_unit_move_prob[prov] = move_prob
                # C reads the signed int64 DAT_0055b0e8/ec pair for this
                # power/province.  g_max_province_score is a different,
                # one-dimensional aggregate.
                max_s = float(state.g_max_prov_score_per_power[power_idx, prov])
                ot[prov, _F_CONVOY_LO] = -max_s
                ot[prov, _F_CONVOY_HI] = 0.0
            continue

        # Main path (C:143-258).  The old port replaced this decision tree
        # with an unrelated own-SC/attack-vs-defense heuristic.  Fields 13,
        # 14 and 15 are respectively the incoming count, base/support count,
        # and peak hostile reach.  FUN_0040e890 is the x87 power helper: the
        # decompiler exposes the low dword 0x33333333 of double 0.3, applied
        # to field 17 / 10.
        base_count = int(ot[prov, _F_INCOMING_MOVE + 1])
        target_count = int(ot[prov, _F_TARGET_PROV])
        move_history = int(ot[prov, _F_MOVE_HISTORY])
        enemy_presence = int(state.g_enemy_presence[power_idx, prov])
        attack_count = int(state.g_attack_count[power_idx, prov])
        attack_history = int(state.g_attack_history[power_idx, prov])
        is_supply_center = prov in state.sc_provinces
        order_type = int(ot[prov, _F_ORDER_TYPE])
        order_assigned = int(ot[prov, _F_ORDER_ASGN])
        move_prob = 0.0

        complex_path = (
            (attack_count <= 0 or enemy_presence != 0)
            and order_type not in (
                _ORDER_HLD, _ORDER_SUP_HLD, _ORDER_SUP_MTO, _ORDER_CVY,
            )
            and order_assigned < 2
        )

        if complex_path:
            # C performs integer division before the x87 power call.
            history_base = max(move_history, 0) // 10
            history_term = float(history_base) ** 0.3
            if incoming + 1 < target_count and is_supply_center:
                move_prob = (
                    history_term * 0.1
                    + (incoming - 1) * 0.25
                    + base_count * 0.15
                )
            elif incoming < target_count:
                if is_supply_center:
                    move_prob = (
                        (incoming - 1) * 0.25
                        + history_term * 0.1
                        + 0.05
                        + base_count * 0.15
                    )
                else:
                    move_prob = (
                        history_term * 0.15
                        + 0.1
                        + (incoming - 1) * 0.25
                        + base_count * 0.15
                    )
            elif incoming == target_count:
                use_contested_formula = (
                    attack_history < 11
                    or enemy_presence != 0
                    or (is_supply_center and state.g_season != 'SPR')
                )
                if not use_contested_formula:
                    move_prob = 0.8
                else:
                    if (not is_supply_center
                            and attack_history < 10
                            and move_history < 15):
                        offset = 0.25 - enemy_presence * 0.1
                    else:
                        offset = 0.15
                    move_prob = (
                        (incoming - 1) * 0.3
                        + history_term * 0.2
                        + offset
                        + base_count * 0.2
                    )
            elif incoming > target_count:
                move_prob = 1.0
        elif incoming >= target_count:
            move_prob = 1.0
        elif is_supply_center:
            move_prob = (incoming - 1) * 0.3 + 0.15 + base_count * 0.25
        else:
            move_prob = (incoming - 1) * 0.3 + 0.35 + base_count * 0.25

        state.g_unit_move_prob[prov] = min(move_prob, 1.0)

    # ── Pass B: Fleet support score update (3 iterations) ───────────────────
    # First, C:264-329 performs three relaxation passes that propagate a
    # destination's move probability back to its MTO source.  The old port
    # skipped this loop and went directly to fleet-adjacency propagation.
    for _ in range(3):
        for prov in range(ot.shape[0]):
            if int(ot[prov, _F_ORDER_TYPE]) != _ORDER_MTO:
                continue

            incoming = int(ot[prov, _F_INCOMING_MOVE])
            order_assigned = int(ot[prov, _F_ORDER_ASGN])
            dest = int(ot[prov, _F_DEST_PROV])
            if not 0 <= dest < ot.shape[0]:
                continue

            if incoming > 0 and order_assigned < 2:
                attack = int(state.g_attack_count[power_idx, prov])
                history = int(state.g_attack_history[power_idx, prov])
                enemy = int(state.g_enemy_presence[power_idx, prov])
                support_hi = int(ot[prov, _F_SUP_TARGET + 1])
                may_relax = (
                    (attack == 0 and (history < 11 or enemy == 1))
                    or support_hi >= 0
                )
                if may_relax:
                    forced_contested = False
                    if (int(ot[dest, _F_INCOMING_MOVE])
                            == int(ot[dest, _F_TARGET_PROV])):
                        dest_attack = int(state.g_attack_count[power_idx, dest])
                        dest_history = int(state.g_attack_history[power_idx, dest])
                        dest_enemy = int(state.g_enemy_presence[power_idx, dest])
                        if (dest_attack > 0
                                or (dest_history > 10 and dest_enemy == 0)):
                            ot[prov, _F_MOVE_PROB] = 0.3
                            # C jumps to LAB_00437bfa, bypassing the sibling
                            # minimum-propagation comparison below.
                            forced_contested = True
                    if (not forced_contested
                            and float(ot[dest, _F_MOVE_PROB])
                            < float(ot[prov, _F_MOVE_PROB])):
                        # EvaluateOrderScore.c:294-297: this is a sibling of
                        # the destination-count equality, not nested inside it.
                        ot[prov, _F_MOVE_PROB] = ot[dest, _F_MOVE_PROB]

            # C tests field 7's sign as the high dword of the signed field
            # 6/7 pair. Python keeps that signed scalar in field 6.
            if (incoming == 0
                    and float(ot[prov, _F_CONVOY_LO]) < 0.0
                    and int(ot[prov, _F_TARGET_PROV]) == 1
                    and int(ot[dest, _F_INCOMING_MOVE])
                    == int(ot[dest, _F_TARGET_PROV])):
                dest_attack = int(state.g_attack_count[power_idx, dest])
                dest_history = int(state.g_attack_history[power_idx, dest])
                dest_enemy = int(state.g_enemy_presence[power_idx, dest])
                if (dest_attack <= 0
                        and (dest_history < 11 or dest_enemy != 0)):
                    ot[prov, _F_MOVE_PROB] = ot[dest, _F_MOVE_PROB]
                else:
                    ot[prov, _F_MOVE_PROB] = 0.5

    # Then C:330-410 performs one fleet-adjacency propagation.  It selects sea
    # provinces whose incoming/base count is exactly one, not MTO source rows.
    # The 0.75 factor is controlled by whether the evaluated power is in the
    # adjacent province's home-power set; it has no support-opportunity gate.
    home_centers = getattr(state, 'home_centers', {})
    own_home_centers = home_centers.get(power_idx, frozenset())
    for prov in getattr(state, 'water_provinces', frozenset()):
        if int(ot[prov, _F_INCOMING_MOVE]) != 1:
            continue

        move_prob = float(ot[prov, _F_MOVE_PROB])
        if 0.5 < move_prob < 1.0:
            move_prob = 0.5
        chain_score = float(ot[prov, _F_CONVOY_LO])

        fleet_adjs = getattr(state, 'fleet_adj_matrix', {}).get(prov, [])
        for adj_prov in fleet_adjs:
            fleet_score = float(ot[adj_prov, 24])
            if fleet_score < 0.0:
                continue
            threshold = chain_score * move_prob * 0.2
            if adj_prov in own_home_centers:
                threshold *= 0.75
            if fleet_score < threshold:
                ot[adj_prov, 24] = threshold

    # ── Pass C: unit reach/hold factor ───────────────────────────────────────
    # EvaluateOrderScore.c:414-455 writes field 21 (DAT_00baedf4).  Pass D
    # accumulates it over adjacent friendly units.  The old port overwrote
    # field 4's Pass-A move probability and left field 21 permanently zero.
    for prov in range(ot.shape[0]):
        threat = float(state.g_threat_level[power_idx, prov])
        own_sc = int(state.g_sc_ownership[power_idx, prov])
        enemy_pres = int(state.g_enemy_presence[power_idx, prov])
        incoming_move = int(ot[prov, _F_INCOMING_MOVE])

        if threat == 0.0 and own_sc == 0 and incoming_move == 0:
            ot[prov, _F_UNIT_REACH_SCORE] = 1.0
        elif (threat == 0.0 and incoming_move == 0 and own_sc == 1
              and int(ot[prov, _F_ORDER_TYPE]) == _ORDER_MTO
              and int(ot[prov, _F_ORDER_ASGN]) < 2):
            dest = int(ot[prov, _F_DEST_PROV])
            if (0 <= dest < ot.shape[0]
                    and int(ot[dest, _F_INCOMING_MOVE])
                    == int(ot[dest, _F_TARGET_PROV])):
                dest_attack = float(state.g_attack_count[power_idx, dest])
                ot[prov, _F_UNIT_REACH_SCORE] = (
                    float(ot[dest, _F_MOVE_PROB]) if dest_attack <= 0.0 else 0.3
                )
            else:
                ot[prov, _F_UNIT_REACH_SCORE] = 1.0
        elif incoming_move == 0 and threat != 0.0:
            if enemy_pres == 1:
                ot[prov, _F_UNIT_REACH_SCORE] = 0.2 / threat
            elif enemy_pres == 0 and threat > 0.0:
                ot[prov, _F_UNIT_REACH_SCORE] = 0.4 / threat

    # ── Pass D: Cut-support risk ─────────────────────────────────────────────
    # C only scores units whose row field 13 is nonzero.  It does not clamp
    # the adjacency sum: own-unit contributions are positive (sum-1), while
    # enemy contributions are negative (1-sum).
    for prov, info in state.unit_info.items():
        unit_power = info['power']
        if int(ot[prov, _F_INCOMING_MOVE]) < 1:
            continue
        local_128 = 0.0
        unit_type = info.get('type', '')
        unit_coast = info.get('coast', '')

        for adj_prov in state.get_unit_adjacencies(prov):
            if not state.can_reach_by_type(
                    prov, adj_prov, unit_type, unit_coast):
                continue
            if unit_power != power_idx:
                if (int(state.g_enemy_reach_score[power_idx, adj_prov]) == 1
                        and int(ot[adj_prov, _F_INCOMING_MOVE]) == 0):
                    local_128 += 1.0
                    continue
                if (int(state.g_sc_ownership[power_idx, adj_prov]) == 1
                        and int(ot[adj_prov, _F_ORDER_TYPE]) == _ORDER_MTO
                        and int(ot[adj_prov, _F_DEST_PROV]) == prov):
                    continue
            local_128 += float(ot[adj_prov, _F_UNIT_REACH_SCORE])

        if local_128 < 1.0:
            ot[prov, 22] = 0.0
        elif (unit_power == power_idx
              and int(ot[prov, _F_TARGET_PROV])
              > int(ot[prov, _F_INCOMING_MOVE])):
            ot[prov, 22] = local_128 - 1.0
        elif (unit_power != power_idx
              and int(ot[prov, _F_INCOMING_MOVE])
              + int(ot[prov, _F_SUP_CHAIN_CONFLICT]) > 1):
            ot[prov, 22] = 1.0 - local_128
        else:
            ot[prov, 22] = 0.0

    # ── Pass E: selected-score validity reset ────────────────────────────────
    # EvaluateOrderScore.c:610-660 conditionally clears columns 8/9, the
    # selected final_score_set pair written by ProcessTurn.c:1508-1509.  The
    # old port mistook these columns for retreat/convoy fields and therefore
    # erased CTO route legs while leaving every selected score active.
    season = state.g_season

    for prov in range(ot.shape[0]):
        order_type = int(ot[prov, _F_ORDER_TYPE])
        selected_lo = float(ot[prov, _F_SELECTED_SCORE_LO])
        selected_hi = float(ot[prov, _F_SELECTED_SCORE_HI])
        if selected_hi < 0.0 or (selected_hi < 1.0 and selected_lo == 0.0):
            continue

        sup_lo = float(ot[prov, _F_SUP_TARGET])
        sup_hi = float(ot[prov, _F_SUP_TARGET + 1])
        enters_conditional_keep_path = (
            sup_hi < 1.0
            and (sup_hi < 0.0 or sup_lo == 0.0)
            and order_type not in (
                _ORDER_HLD, _ORDER_SUP_HLD, _ORDER_SUP_MTO, _ORDER_CVY
            )
            and int(ot[prov, _F_ORDER_ASGN]) != _CONVOY_DEPTH_COMPLETE
        )
        # Once the structural gate is entered, C falls through to
        # LAB_00438831 (clear) unless one of the explicit history/season
        # branches jumps to LAB_00438839 (keep).
        clear_selected = True

        if enters_conditional_keep_path:
            dest = int(ot[prov, _F_DEST_PROV])
            # InitPositionForOrders.c counts byte +3 across provinces and
            # derives the victory threshold as count/2+1, directly proving
            # this is the supply-centre flag.
            src_is_sc = prov in state.sc_provinces
            dest_is_sc = dest in state.sc_provinces
            enter_history_gate = not src_is_sc

            if src_is_sc:
                # C:615-637: an SC source normally clears immediately. The
                # narrow Fall MTO/CTO-to-SC-destination path reaches
                # history only when its support-demand/attack gates pass.
                if (season == 'FAL'
                        and order_type in (_ORDER_MTO, _ORDER_CTO)
                        and dest_is_sc
                        and int(ot[prov, _F_TARGET_PROV]) == 1
                        and float(ot[dest, _F_TARGET_PROV]) > 0.0):
                    src_is_attacked = (
                        float(ot[prov, _F_INCOMING_MOVE]) > 0.0
                        and int(state.g_attack_count[power_idx, prov]) > 0
                    )
                    dest_is_unopposed = (
                        int(state.g_attack_count[power_idx, dest]) <= 0
                        and float(ot[dest, _F_INCOMING_MOVE])
                        <= float(ot[dest, _F_TARGET_PROV])
                    )
                    enter_history_gate = not src_is_attacked and dest_is_unopposed

            if enter_history_gate:
                # Python stores the full signed C int64 rather than separate
                # low/high dwords.  The C tests on DAT_005a48ec (signed high)
                # plus g_AttackHistory (unsigned low) reduce to these signed
                # comparisons for the values represented by this port.
                history = int(state.g_attack_history[power_idx, prov])
                if history < 11:
                    clear_selected = False
                elif (season == 'FAL'
                        and order_type in (_ORDER_MTO, _ORDER_CTO)):
                    clear_selected = not (
                        dest_is_sc
                        and int(state.g_attack_count[power_idx, dest]) <= 0
                    )
                elif (season != 'SPR'
                        or order_type not in (_ORDER_MTO, _ORDER_CTO)):
                    clear_selected = False

        if clear_selected:
            ot[prov, _F_SELECTED_SCORE_LO] = 0.0
            ot[prov, _F_SELECTED_SCORE_HI] = 0.0

    # ── Pass F: Cumulative score accumulation ────────────────────────────────
    # C initialises local_120 = 500.0.
    # Main branch per unit:
    #   C reads (float)(longlong)fields[6,7] * (float)field[4] — i.e.
    #   convoy_chain_score × move probability.
    #   HLD / CVY sentinel: (field18 & field19) == -1 → additive only.
    #   Non-HLD: accumulates convoy_source_score on top.
    # Post-main per-province:
    #   positive field-24 pair → +fleet/order contribution
    #   move_prob==1.0 with high attack history on unowned SC → +fleet_score*0.4
    #   cut_risk != 0 → +cut_risk * 100
    #
    local_120 = 500.0

    num_provinces = int(getattr(state, 'num_valid_provinces', 0)) or 256
    own_home_centers = getattr(state, 'home_centers', {}).get(
        power_idx, frozenset()
    )
    for prov in range(num_provinces):

        order_type  = int(ot[prov, _F_ORDER_TYPE])
        fleet_score = float(state.g_fleet_support_score[prov])
        move_prob   = float(state.g_unit_move_prob[prov])
        cut_risk    = float(state.g_cut_support_risk[prov])

        # C reads fields[6,7] (convoy chain score / negated defense) × field[4]
        # (move probability).  In Python the order table is float64, so read directly.
        order_score = float(ot[prov, _F_CONVOY_LO])
        move_weight = float(ot[prov, _F_MOVE_PROB])

        # Sentinel: fields 18/19 are -1.0 when unassigned (C uint32 0xffffffff = int32 -1).
        # trial.py initialises both to -1.0; assign_support_order writes real scores.
        # Bitwise AND on float64 never reaches 0xffffffff — compare directly to sentinel.
        is_sentinel = (ot[prov, _F_SUP_TARGET] == -1.0 and ot[prov, _F_SUP_TARGET + 1] == -1.0)
        # C: (local_e8 & uStack_e4)==0xffffffff  →  sentinel; (int)puVar15[-2]==5  →  chain complete.
        # puVar15[-2] = field 20 (_F_ORDER_ASGN), NOT field 0 (_F_ORDER_TYPE).
        is_hld_like = is_sentinel or int(ot[prov, _F_ORDER_ASGN]) == _CONVOY_DEPTH_COMPLETE

        if is_hld_like:
            local_120 += order_score * move_weight
        else:
            local_118 = order_score * move_weight + local_120
            # C EvaluateOrderScore.c:683 — local_120 = (float)(longlong)puVar15[-3] + local_118
            # puVar15[-3] = the signed field 18/19 pair written by
            # assign_support_order.
            src_score = float(ot[prov, _F_SUP_TARGET])
            local_120 = src_score + local_118

            # C: +100 in Fall when field13 is zero or field20 is 2 and the
            # evaluated power is a home power of this province.
            order_asgn = int(ot[prov, _F_ORDER_ASGN])
            if int(ot[prov, _F_INCOMING_MOVE]) == 0 or order_asgn == _ORDER_MTO:
                if prov in own_home_centers and season == 'FAL':
                    local_120 += 100.0

        # C:699 adds the selected final_score_set pair after the main branch
        # and its Fall bonus, for every province row.
        local_120 += float(ot[prov, _F_SELECTED_SCORE_LO])

        # C adds the signed field-24/25 pair whenever it is positive.  The
        # type-5 PackScoreU64 immediately beforehand only materializes the
        # x87 value in that same pair; builders already store the Python value.
        if fleet_score > 0.0:
            local_120 += fleet_score

        # SUP_HLD/SUP_MTO: C adds the supported destination's chain-conflict
        # and incoming-move fields (EvaluateOrderScore.c:709-714).  The old
        # port instead invented a CTO-only convoy-depth bonus at this site.
        if order_type in (_ORDER_SUP_HLD, _ORDER_SUP_MTO):
            dest = int(ot[prov, _F_DEST_PROV])
            if 0 <= dest < ot.shape[0]:
                local_120 += float(
                    ot[dest, _F_SUP_CHAIN_CONFLICT]
                    + ot[dest, _F_INCOMING_MOVE]
                )

        # Definitely-moving unit with sustained historical attack pressure
        if move_prob == 1.0:
            attack_history = float(state.g_attack_history[power_idx, prov])
            own_unit = int(state.g_sc_ownership[power_idx, prov])
            order_score = float(ot[prov, _F_CONVOY_LO])
            if (attack_history > 10.0
                    and own_unit == 0
                    and order_score > 0.0
                    and float(ot[prov, _F_TARGET_PROV]) > 0.0
                    and float(ot[prov, _F_INCOMING_MOVE]) > 0.0):
                local_120 += order_score * 0.4

        # Cut-support risk: 100× multiplier (from decompile)
        if cut_risk != 0.0:
            local_120 += cut_risk * 100.0

    # The positional score maps strongly value already-controlled centres but
    # do not project the ownership update caused by the candidate orders.  In
    # particular, a fall army on neutral SPA was repeatedly sent back to MAR,
    # and GAS-SPA was evaluated independently from SPA-POR, so France could
    # wander for years without banking either centre.  Credit the complete
    # set for each new, uncontested SC occupation.  Applying the value to the
    # complete set naturally rewards backfills instead of hard-coding any
    # country or province.
    new_centres = _projected_new_supply_center_count(power_idx, state)
    local_120 += new_centres * _NEW_SUPPLY_CENTER_OCCUPATION_BONUS

    return local_120


def insert_candidate_record(state: InnerGameState, candidate: dict,
                             trial_idx: int = 0) -> tuple:
    """Port of InsertCandidateRecord — BST insert into g_candidate_record_list.

    The C function maintains a sorted BST keyed on the order combination so
    that two MC trials producing identical orders for a power share one record.
    Forward iteration is lexicographic by the serialized SUB key.  A duplicate
    returns the existing node unchanged; ``TrialEvaluateOrders`` constructs the
    proposed value *before* insertion, and C never copies it over an existing
    node.

    Python keeps the records in that same key order.  This matters even though
    most consumers re-sort by score: C's stable equal-score insertion inherits
    candidate-tree order, not Monte-Carlo discovery order.
    Returns (inserted, record): inserted=False means an identical order set
    already existed and record is that existing entry.
    """
    import bisect

    key = candidate_record_key(candidate)
    key_map = state.__dict__.get('_candidate_key_map')
    ordered_keys = state.__dict__.get('_candidate_keys')
    if (not isinstance(key_map, dict)
            or not isinstance(ordered_keys, list)
            or len(ordered_keys) != len(state.g_candidate_record_list)
            or len(key_map) != len(state.g_candidate_record_list)):
        # The C tree is authoritative and self-indexing.  Rebuild Python's
        # acceleration structures if a direct caller replaced/pre-populated
        # the public list or supplied an older index-valued key map.
        keyed_records = sorted([
            (candidate_record_key(record), record)
            for record in state.g_candidate_record_list
        ], key=lambda pair: pair[0])
        state.g_candidate_record_list[:] = [record for _, record in keyed_records]
        ordered_keys = [record_key for record_key, _ in keyed_records]
        key_map = {
            record_key: record for record_key, record in keyed_records
        }
        state.__dict__['_candidate_keys'] = ordered_keys
        state.__dict__['_candidate_key_map'] = key_map
    if key in key_map:
        return False, key_map[key]
    # Pre-allocate 30-slot array (matches C's 30-element per-trial arrays in
    # the candidate record struct copied by TrialEvaluateOrders).
    # EvaluateOrderProposal zeroes all three 30-slot arrays before constructing
    # TrialEvaluateOrders.  UpdateAllyOrderScore writes the round-indexed
    # Pareto slots later; EvaluateOrderScore belongs only in fields 8/9 here.
    candidate['trial_scores'] = [0.0] * 30
    # TrialEvaluateOrders constructor defaults consumed by FUN_00424850.
    candidate.setdefault('base_score', candidate['score'])
    candidate.setdefault('min_rank', 10000)
    candidate.setdefault('max_rank', 0)
    candidate.setdefault('running_avg', 10000.0)
    candidate.setdefault('round_count', 0)
    candidate.setdefault('processed', 0)
    candidate.setdefault('pareto_flag', 0)
    candidate.setdefault('weight', 0.0)
    candidate.setdefault('output_score', 0.0)
    position = bisect.bisect_left(ordered_keys, key)
    state.g_candidate_record_list.insert(position, candidate)
    ordered_keys.insert(position, key)
    key_map[key] = candidate
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
        local_cac.append(snapshot_order_entry(ot, prov))

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
    _gate_key = candidate_orders_key(power_idx, local_cac)
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
        # EvaluateOrderProposal.c:885 — this is an accepted proposal counter,
        # so duplicates and deviations rejected by the outer gate do not
        # increment it.  RankCandidatesForPower uses it as its selection
        # threshold and BuildAndSendSUB adds it to g_CumScore.
        state.g_power_call_count[power_idx] += 1

        candidate = {
            'power': power_idx,
            'orders': local_cac,
            'score': score,
            'final_dim_score': 0,
            'heat_scores': heat_scores,
            'deviation': local_d31,
            'pressure_cost': local_d04,
            'trust_adjustment': local_d24,
            'conviction_bonus': local_c1c,
            'early_game_bonus': early_game_bonus,
            # TrialEvaluateOrders fields 0x13 and 0x15.  The ranker uses
            # other_score for its Pareto margin and rank_penalty in the
            # near-end retirement guard.
            'other_score': int(getattr(state, 'g_other_score', 0)),
            'rank_penalty': int(getattr(state, 'g_support_trust_adj', 0)) + local_d04 + local_d24,
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
