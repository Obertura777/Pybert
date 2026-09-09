"""Monte-Carlo trial loop (ProcessTurn) and its auxiliaries.

Split from monte_carlo.py during the 2026-04 refactor.  This is the core of
the MC engine:

- ``trial_evaluate_orders``    — deep-copy a candidate order set for an
                                 isolated trial.
- ``process_turn``             — 1 200+ line port of FUN_0044c9d0; the full
                                 MC trial loop (Phases 1a–5) that dispatches
                                 candidate orders into ``g_order_table``,
                                 scores each realisation, and rolls up the
                                 per-province best-score tables.
- ``_update_ally_order_score`` — adjust ally-order score after Phase 3.
- ``_refresh_order_table``     — rebuild ``g_order_table`` between trials.
- ``update_score_state``       — composite helper used by Phase 5.
- ``check_time_limit``         — read ``state.mtl_expired`` atomically.

Module-level deps: ``copy``, ``random``, ``numpy``, ``..state.InnerGameState``,
three enumerators from ``..moves``, ``evaluate_order_proposal`` from
``.evaluation``, and field/order-type constants from ``._flags``.
"""

import collections
import copy
import logging
import time
from .. import rng as random

import numpy as np

_dbg_log = logging.getLogger("pybert.scoring_dbg")

from ..state import InnerGameState
from ..dispatch.orders import dispatch_single_order
from ..moves import (
    assign_support_order,
    assign_hold_supports,
    register_convoy_fleet,
    score_convoy_fleet,
    build_convoy_orders,
    build_order_sup_hld as _source_build_order_sup_hld,
    build_order_sup_mto as _source_build_order_sup_mto,
)

from ._flags import (
    _F_ORDER_TYPE, _F_SECONDARY, _F_DEST_PROV, _F_DEST_COAST,
    _F_CONVOY_LO, _F_CONVOY_HI,
    _F_SELECTED_SCORE_LO, _F_SELECTED_SCORE_HI,
    _F_INCOMING_MOVE, _F_SUP_CHAIN_CONFLICT,
    _F_THREAT_TOTAL, _F_MOVE_HISTORY, _F_ORDER_ASGN,
    _ORDER_HLD, _ORDER_MTO, _ORDER_SUP_HLD, _ORDER_SUP_MTO,
    _ORDER_CVY, _ORDER_CTO,
)
from .evaluation import (
    candidate_orders_key,
    candidate_record_key,
    evaluate_order_proposal,
    restore_order_entry,
)
from ..moves._constants import _unit_location_token


def _live_unit_adjacencies(
    state: InnerGameState, province: int, unit: dict,
) -> list[int]:
    """Return C's exact AdjacencyList_FilterByUnitType result for a unit."""
    unit_type = str(unit.get('type', 'A')).upper()
    coast = str(unit.get('coast', '') or '')
    return [
        int(adjacent)
        for adjacent in state.get_unit_adjacencies(province)
        if state.can_reach_by_type(
            province, int(adjacent), unit_type, coast,
        )
    ]


def trial_evaluate_orders(state: InnerGameState, trial_candidate: dict) -> dict:
    """
    State duplicator for trial resolutions.  Deep-copies the candidate order
    dict so each MC trial is isolated.  The caller is responsible for loading
    trial_candidate into state.g_order_table before calling evaluate_order_score.
    """
    return copy.deepcopy(trial_candidate)


def _step3_designation_trust(
    state: InnerGameState,
    power_index: int,
    own_power: int,
    dest: int,
    num_powers: int = 7,
) -> tuple[int, int]:
    """Return ProcessTurn Step 3's designation-derived trust pair.

    C:2016-2041 evaluates the slots in C, A, B order.  Each qualifying slot
    overwrites the pair, so B has final precedence.  Unlike the later order
    emission block, A is not an "only if empty" fallback: it is guarded by the
    designated power differing from ``power_index`` and by that power's threat
    at ``dest`` being below 2.
    """
    trust_lo = 0
    trust_hi = 0

    def read_slot(arr_lo, arr_hi) -> tuple[int, int] | None:
        if not 0 <= dest < len(arr_lo):
            return None
        slot_lo = int(arr_lo[dest])
        slot_hi = int(arr_hi[dest])
        if slot_hi < 0 or not 0 <= slot_lo < num_powers:
            return None
        relation = int(state.g_relation_score[power_index, slot_lo])
        if relation <= 9 and power_index != own_power:
            return None
        return (
            int(state.g_ally_trust_score[power_index, slot_lo]),
            int(state.g_ally_trust_score_hi[power_index, slot_lo]),
        )

    # Slot C (DAT_004d3610/14).
    slot_trust = read_slot(
        state.g_ally_designation_c,
        state.g_ally_designation_c_hi,
    )
    if slot_trust is not None:
        trust_lo, trust_hi = slot_trust

    # Slot A (g_AllyDesignation_A): C additionally rejects our own power and
    # requires DAT_005460e8/ec[A, dest] to represent a threat value below 2.
    if 0 <= dest < len(state.g_ally_designation_a):
        slot_a = int(state.g_ally_designation_a[dest])
        if (slot_a != power_index and 0 <= slot_a < num_powers
                and int(state.g_threat_level[slot_a, dest]) < 2):
            slot_trust = read_slot(
                state.g_ally_designation_a,
                state.g_ally_designation_a_hi,
            )
            if slot_trust is not None:
                trust_lo, trust_hi = slot_trust

    # Slot B (DAT_004d2610/14) is evaluated last and overwrites unconditionally
    # when its validity/relation checks pass.
    slot_trust = read_slot(
        state.g_ally_designation_b,
        state.g_ally_designation_b_hi,
    )
    if slot_trust is not None:
        trust_lo, trust_hi = slot_trust

    return trust_lo, trust_hi


def _apply_step3_support_filter(
    state: InnerGameState,
    power_index: int,
    own_power: int,
    source: int,
    candidates: list[tuple],
    score_threshold: float,
    reachable_provinces: dict,
    num_powers: int = 7,
) -> float:
    """Run ProcessTurn C:1987-2085 and return its updated threshold.

    Despite the historical Python name/comment, this block does not remove a
    candidate.  ``DAT_00bb7124`` is the reachable/history set assembled at
    the start of ProcessTurn, not a unit-occupancy lookup.  Candidates outside
    that set and without designation trust are registered with
    ``ScoreSupportOpp`` unless they are class-1/unmarked/unclaimed.  In that
    final case a candidate at or above the threshold replaces the threshold
    and exits the walk; a lower candidate is simply advanced past.
    """
    for candidate in candidates:
        cand_score, dest = candidate[:2]
        dest = int(dest)
        trust_lo, trust_hi = _step3_designation_trust(
            state, power_index, own_power, dest, num_powers
        )
        if dest in reachable_provinces or trust_lo != 0 or trust_hi != 0:
            continue

        target_class = (
            int(state.g_prov_target_flag[power_index, dest])
            if 0 <= dest < 256 else 0
        )
        companion = (
            int(state.g_target_flag2[power_index, dest])
            if 0 <= dest < 256 else 0
        )
        incoming = (
            int(state.g_order_table[dest, _F_INCOMING_MOVE])
            if 0 <= dest < state.g_order_table.shape[0] else 0
        )
        if target_class != 1 or companion != 0 or incoming != 0:
            state.g_support_opp_map.setdefault(source, dest)
            continue

        if float(cand_score) >= float(score_threshold):
            score_threshold = float(cand_score)
            break

    return score_threshold


def _accumulate_other_score(
    state: InnerGameState,
    power_index: int,
    own_power: int,
) -> int:
    """Port ProcessTurn.c:3695-3746's late support-opportunity scan.

    ``DAT_00bbf644`` is the same ``std::map<int, int>`` populated by Step 3's
    ``ScoreSupportOpp`` call: source province is the key and candidate
    destination is the value.  The old port invented a second, never-written
    ``g_trial_list2`` container and consequently pinned ``g_other_score`` to
    zero.
    """
    added = 0
    support_opps = state.g_support_opp_map
    for unit_prov, unit in state.unit_info.items():
        # ParseNOWUnit.c:155-159 inserts Albert's own standard-form units into
        # gamestate+0x24b4, which is the fixed outer list used by this block.
        if int(unit.get('power', -1)) != own_power:
            continue
        if not 0 <= unit_prov < state.g_order_table.shape[0]:
            continue
        dest = int(state.g_order_table[unit_prov, _F_DEST_PROV])
        if not 0 <= dest < state.g_order_table.shape[0]:
            continue
        if (int(state.g_prov_target_flag[power_index, dest]) != 1
                or int(state.g_target_flag2[power_index, dest]) != 0):
            continue
        if (int(state.g_province_score_trial[dest]) != 0
                and unit.get('type', 'A') not in ('F', 'FLT')):
            continue
        if unit_prov not in support_opps:
            continue
        opp_dest = int(support_opps[unit_prov])
        if (0 <= opp_dest < state.g_order_table.shape[0]
                and int(state.g_order_table[opp_dest, _F_INCOMING_MOVE]) == 0):
            state.g_other_score += 1
            added += 1
    return added


def _apply_step4_xdo_constraint(
    state: InnerGameState,
    power_index: int,
    own_power: int,
    source: int,
    candidates: list[tuple],
) -> list[tuple]:
    """Apply ProcessTurn Step 4's accepted-XDO move/hold constraint.

    DAT_00bb69f8 supplies a source→destination move, while membership in
    DAT_00bb6af8 means the proposed destination is the source itself (hold).
    The sole exception is an XDO move whose destination already contains our
    own unit with a HLD order; C leaves that unit's candidate list untouched.
    """
    if power_index != own_power:
        return candidates


    move_map = state.g_xdo_order_move_by_power.get(power_index, {})
    hold_set = state.g_xdo_order_hold_by_power.get(power_index, set())
    if source in move_map:
        proposed_dest = move_map[source]
        dest_unit = state.unit_info.get(proposed_dest)
        own_unit_holding = (
            dest_unit is not None
            and int(dest_unit.get('power', -1)) == power_index
            and 0 <= proposed_dest < state.g_order_table.shape[0]
            and int(state.g_order_table[proposed_dest, _F_ORDER_TYPE]) == _ORDER_HLD
        )
        if own_unit_holding:
            return candidates
    elif source in hold_set:
        proposed_dest = source
    else:
        return candidates

    matching = [candidate for candidate in candidates
                if int(candidate[1]) == proposed_dest]
    # C first scans for the proposed destination and only enters its removal
    # pass when a matching candidate exists.
    return matching if matching else candidates


def _build_negotiated_province_context(
    state: InnerGameState,
    power_index: int,
    own_power: int,
    num_powers: int,
) -> tuple[dict[int, bool], list[dict[int, int]]]:
    """Build ProcessTurn's DMZ reach set and accepted-XDO snapshots.

    ``DAT_00bb6f28`` and ``DAT_00bb7028`` are the already-ported DMZ
    promise/counter maps. ``DAT_00bb69f8`` is the per-power accepted XDO
    source→destination map populated by ``XDO.c``. Earlier Python code read
    three phantom "history"/"alternate" containers that nothing populated.
    """
    reachable: dict[int, bool] = {}

    def add_record(record) -> None:
        if isinstance(record, dict):
            province = record.get('dest_prov', record.get('province', -1))
        else:
            province = record
        try:
            province = int(province)
        except (TypeError, ValueError):
            return
        if province >= 0:
            reachable[province] = True

    if power_index == own_power:
        # ProcessTurn.c:401-427 scans every non-enemy promise map for Albert.
        for power in range(num_powers):
            enemy_lo = int(state.g_enemy_flag[power])
            enemy_hi = int(state.g_enemy_flag_hi[power])
            if enemy_lo != 0 or enemy_hi != 0:
                continue
            for record in state.g_ally_promise_list.get(power, ()):
                add_record(record)
    else:
        # ProcessTurn.c:430-464 scans this power's counter map only when the
        # relation/trust gate permits sharing negotiated territory.
        trust_lo = int(state.g_ally_trust_score[own_power, power_index])
        trust_hi = int(state.g_ally_trust_score_hi[own_power, power_index])
        relation = int(state.g_relation_score[own_power, power_index])
        if relation > 9 or trust_hi > 0 or (trust_hi >= 0 and trust_lo > 5):
            for record in state.g_ally_counter_list.get(power_index, ()):
                add_record(record)

    xdo_maps = getattr(state, 'g_xdo_order_move_by_power', {}) or {}
    per_power_xdo = [
        dict(xdo_maps.get(power, {})) for power in range(num_powers)
    ]
    return reachable, per_power_xdo


def _resolve_own_occupied_destination(
    state: InnerGameState,
    power_index: int,
    mover: int,
    destination: int,
) -> tuple[bool, bool]:
    """Port ProcessTurn.c:2579-2694's own-occupied destination tail.

    Returns ``(emit_move, rejected)``. A stationary pressured occupant is
    supported in place; an unordered occupant causes the mover to be requeued
    with the destination candidate's decremented score; otherwise the move is
    either allowed into a vacating province or rejected.
    """
    if int(state.g_sc_ownership[power_index, destination]) != 1:
        return True, False

    dest_order = int(state.g_order_table[destination, _F_ORDER_TYPE])
    if dest_order != 0:
        if int(state.g_order_table[destination, _F_ORDER_ASGN]) > 1:
            return False, True
        if dest_order in (_ORDER_MTO, _ORDER_CTO):
            return True, False
        if (int(state.g_support_demand[destination])
                <= int(state.g_order_table[destination, _F_INCOMING_MOVE])):
            return False, True

        # BuildOrder_SUP_HLD's ordered-set guard expects an empty mover slot.
        state.g_order_table[mover, _F_ORDER_TYPE] = 0
        _source_build_order_sup_hld(
            state, power_index, mover, destination
        )
        return False, False

    entry_score = next(
        (score for score, province in state.g_convoy_fleet_candidates
         if province == destination),
        None,
    )
    if entry_score is None or entry_score < 0:
        return False, True

    score_convoy_fleet(state, mover, int(entry_score) - 1)
    state.g_province_base[mover] += 1
    return False, False


def _dedupe_step5_fleet_candidates(candidates: list[tuple]) -> list[tuple]:
    """Apply ProcessTurn C:2184-2234 to one fleet's candidate tree.

    ``piStack_70c`` is a temporary set created empty immediately before the
    walk.  C inserts each candidate's destination into that set and removes a
    candidate only when its destination is already present.  After a removal
    it clears the set and restarts the walk.  The net result is stable
    destination de-duplication of *this candidate list*; it does not inspect
    orders assigned to other fleets.
    """
    seen: set[int] = set()
    deduped: list[tuple] = []
    for candidate in candidates:
        dest = int(candidate[1])
        if dest in seen:
            continue
        seen.add(dest)
        deduped.append(candidate)
    return deduped


def _apply_step1_source_dedup(
    state: InnerGameState,
    source: int,
    candidates: list[tuple],
) -> list[tuple]:
    """Apply ProcessTurn C:1944-1977's source/hold removal gate."""
    if (source not in state.g_sub_order_map
            or len(candidates) <= 1
            or int(state.g_province_base[source]) >= 500):
        return candidates
    return [candidate for candidate in candidates
            if int(candidate[1]) != source]


def _apply_step6_target_filter(
    state: InnerGameState,
    power_index: int,
    source: int,
    candidates: list[tuple],
    score_threshold: float,
) -> list[tuple]:
    """Apply ProcessTurn's target-class pruning at C:2235-2391.

    A class-1 or class-2 destination with companion marker zero is removed
    when its score is below the source threshold.  The exception in both C
    branches is a province marked by ``RegisterConvoyFleet`` that is also in
    the source province's adjacency map (the per-province maps at +0x2a1c).

    C's two class-2 blocks split on ``current_outer_candidate.dest == dest``
    and ``!=`` and then execute the same removal gate, so together they cover
    every class-2 destination.  Both blocks stop pruning once the persistent
    ``g_ProvinceBase[source]`` retry counter reaches 5000.  Class 1 has no
    such counter gate.
    """
    if score_threshold <= 0:
        return candidates

    source_adjacencies = set(state.adj_matrix.get(source, ()))
    filtered: list[tuple] = []
    for candidate in candidates:
        score, dest = candidate[:2]
        dest = int(dest)
        if not 0 <= dest < 256:
            filtered.append(candidate)
            continue

        target_class = int(state.g_prov_target_flag[power_index, dest])
        companion = int(state.g_target_flag2[power_index, dest])
        below_threshold = float(score) < float(score_threshold)
        counter_allows_removal = (
            target_class == 1
            or int(state.g_province_base[source]) < 5000
        )
        if (target_class in (1, 2)
                and companion == 0
                and below_threshold
                and counter_allows_removal):
            convoy_exception = (
                int(state.g_province_score_trial[dest]) != 0
                and dest in source_adjacencies
            )
            if not convoy_exception:
                continue
        filtered.append(candidate)
    return filtered


def _apply_convoy_swap(
    state: InnerGameState,
    power_index: int,
    source: int,
    destination: int,
    rand_value: int | None = None,
    require_source_ready: bool = False,
) -> bool:
    """Port ProcessTurn's two ``LAB_00453cac`` convoy-swap entries.

    When a destination already has a registered mover and a pending support
    assignment, C occasionally resolves that assignment as a complete convoy
    chain instead of making ``source`` emit SUP_MTO.  The random expression is
    the binary's ``(rand() / 0x17) % 100 > 60``.  ``rand_value`` exists only so
    the boundary can be tested without replacing the module RNG.

    The late HLD support sweep (C:3247-3318) reaches the same promotion label,
    but only after additionally requiring ``source`` to have one incoming move
    and no support-chain conflict.  Those checks occur *after* C consumes the
    random value, so ``require_source_ready`` deliberately tests them below the
    random gate.  The main Phase-2 entry (C:2757-2865) leaves the option false.
    """
    if int(state.g_order_table[destination, _F_ORDER_ASGN]) != 1:
        return False

    roll_source = random.randint(0, 32767) if rand_value is None else rand_value
    if (int(roll_source) // 0x17) % 100 <= 60:
        return False

    if require_source_ready and (
        int(state.g_order_table[source, _F_INCOMING_MOVE]) != 1
        or int(state.g_order_table[source, _F_SUP_CHAIN_CONFLICT]) != 0
    ):
        return False

    source_demand = int(state.g_support_demand[source])
    own_home_controlled_destination = (
        destination in state.home_centers.get(power_index, frozenset())
        and int(state.g_sc_owner[destination]) == power_index
    )
    if source_demand != 1 and not (
            own_home_controlled_destination and source_demand == 0):
        return False

    assigned = int(state.g_convoy_source_prov[destination])
    if not 0 <= assigned < state.g_order_table.shape[0]:
        return False

    # C:2772-2829.  Destination advances from pending (1) to consumed (2);
    # source and its assigned province become complete convoy-chain members.
    state.g_order_table[destination, _F_ORDER_ASGN] += 1.0
    state.g_order_table[source, _F_ORDER_ASGN] = 5.0
    state.g_order_table[assigned, _F_ORDER_ASGN] = 5.0
    state.g_order_table[assigned, 24] = -1.0
    state.g_order_table[assigned, 25] = -1.0

    source_score = state.fss(power_index, source,
                             (state.unit_info.get(source) or {}).get('type'))
    assigned_score = state.fss(power_index, assigned,
                               (state.unit_info.get(assigned) or {}).get('type'))
    state.g_convoy_chain_score[source] = source_score
    state.g_order_score_hi[source] = 0.0
    state.g_order_table[source, _F_CONVOY_LO] = source_score
    state.g_order_table[source, _F_CONVOY_HI] = 0.0
    state.g_convoy_chain_score[assigned] = assigned_score
    state.g_order_score_hi[assigned] = 0.0
    state.g_order_table[assigned, _F_CONVOY_LO] = assigned_score
    state.g_order_table[assigned, _F_CONVOY_HI] = 0.0
    state.g_order_table[source, _F_INCOMING_MOVE] = 1.0
    state.g_order_table[assigned, _F_INCOMING_MOVE] = 1.0
    return True


def _post_phase_move_support_allowed(
    state: InnerGameState,
    power_index: int,
    destination: int,
    pass_index: int,
) -> bool:
    """Return C:3088-3130's SUP-MTO eligibility for one destination.

    The first pass accepts an unclaimed destination whenever its incoming
    count is *at most* its support demand.  The second pass additionally
    admits over-covered destinations whose signed total-reach value is
    positive.  Assignment state 2 is terminal in both passes.
    """
    if int(state.g_order_table[destination, _F_ORDER_ASGN]) == 2:
        return False
    incoming = int(state.g_order_table[destination, _F_INCOMING_MOVE])
    demand = int(state.g_support_demand[destination])
    if incoming <= demand:
        return True
    return (
        pass_index > 0
        and int(state.g_total_reach_score[power_index, destination]) > 0
    )


def _post_phase_hold_support_allowed(
    state: InnerGameState,
    power_index: int,
    destination: int,
    pass_index: int,
) -> bool:
    """Return ProcessTurn.c:3099-3157's SUP-HLD eligibility.

    The non-move-map branch is deliberately stricter than the SUP-MTO branch:
    the supported province's current strength must be *below* its support
    demand. On the second pass, a positive total-reach marker admits the
    province even when that strict comparison fails.
    """
    incoming = int(state.g_order_table[destination, _F_INCOMING_MOVE])
    demand = int(state.g_support_demand[destination])
    if incoming < demand:
        return True
    return (
        pass_index > 0
        and int(state.g_total_reach_score[power_index, destination]) > 0
    )


def _build_post_phase_mto(
    state: InnerGameState,
    power_index: int,
    source: int,
    destination: int,
) -> None:
    """Write ProcessTurn.c:3285-3297's late-sweep MTO record.

    This is deliberately smaller than ``BuildOrder_MTO``.  The recovered path
    calls ``BuildOrder_CTO_Ring`` and then manually writes the move-map entry,
    order fields, incoming marker, and destination score.  It does not perform
    BuildOrder_MTO's move-history, convoy-registration, or support-assignment
    tail calls.
    """
    unit = state.unit_info.get(source) or {}
    unit_type = unit.get('type', 'A')
    coast = 0
    if unit_type in ('F', 'FLT'):
        coast = state.resolve_fleet_coast(source, destination)
    if coast == 0:
        coast = _unit_location_token(unit_type)

    if destination not in state.g_convoy_dst_list:
        state.g_convoy_dst_list.append(destination)
    state.g_convoy_dst_to_src[destination] = source
    state.g_order_table[source, _F_ORDER_TYPE] = float(_ORDER_MTO)
    state.g_order_table[source, _F_DEST_PROV] = float(destination)
    state.g_order_table[source, _F_DEST_COAST] = float(coast)
    state.g_order_table[destination, _F_INCOMING_MOVE] = 1.0

    score = state.fss(power_index, destination, unit_type)
    state.g_convoy_chain_score[destination] = score
    state.g_order_score_hi[destination] = 0.0
    state.g_order_table[destination, _F_CONVOY_LO] = score
    state.g_order_table[destination, _F_CONVOY_HI] = 0.0


def _apply_post_phase_support_sweep(
    state: InnerGameState,
    power_index: int,
) -> None:
    """Port ProcessTurn.c:3033-3640's two late HLD support passes."""
    for support_pass in range(2):
        for unit_prov, unit in state.unit_info.items():
            if int(unit.get('power', -1)) != power_index:
                continue
            if int(state.g_order_table[unit_prov, _F_ORDER_TYPE]) != _ORDER_HLD:
                continue

            best_dst = None
            best_mover = None
            best_score = 0.0
            unit_type = unit.get('type', 'A')
            unit_coast = unit.get('coast', '')
            for adj_prov in state.adj_matrix.get(unit_prov, []):
                if not state.can_reach_by_type(
                    unit_prov, adj_prov, unit_type, unit_coast
                ):
                    continue

                mover = (state.g_convoy_dst_to_src or {}).get(adj_prov)
                if mover is None:
                    target_unit = state.unit_info.get(adj_prov)
                    if (target_unit is None
                            or int(target_unit.get('power', -1)) != power_index):
                        continue
                    target_order = int(
                        state.g_order_table[adj_prov, _F_ORDER_TYPE]
                    )
                    if target_order in (_ORDER_MTO, _ORDER_CTO):
                        continue
                    if not _post_phase_hold_support_allowed(
                        state, power_index, adj_prov, support_pass
                    ):
                        continue
                elif not _post_phase_move_support_allowed(
                        state, power_index, adj_prov, support_pass):
                    continue

                score = state.fss(power_index, adj_prov, unit_type)
                if score > best_score:
                    best_score = score
                    best_dst = adj_prov
                    best_mover = mover

            if best_dst is None:
                continue
            state.g_order_table[unit_prov, _F_ORDER_TYPE] = 0.0
            if best_mover is None:
                _source_build_order_sup_hld(
                    state,
                    power_index,
                    unit_prov,
                    best_dst,
                    late_sweep=True,
                )
            else:
                # C:3247-3318.  A pending assignment at this destination can
                # consume the held unit as a move instead of support.  The
                # late entry adds source incoming/conflict gates, but consumes
                # its random roll before testing them.
                if _apply_convoy_swap(
                    state,
                    power_index,
                    unit_prov,
                    best_dst,
                    require_source_ready=True,
                ):
                    _build_post_phase_mto(
                        state, power_index, unit_prov, best_dst
                    )
                    continue
                _source_build_order_sup_mto(
                    state,
                    power_index,
                    unit_prov,
                    best_mover,
                    best_dst,
                    late_sweep=True,
                )


def _candidate_tree_score(
    state: InnerGameState,
    power_index: int,
    province: int,
    unit_type: str,
) -> int:
    """Build ProcessTurn's deterministic score for one province/token key."""
    score = int(state.fss(power_index, province, unit_type))
    if unit_type in ('A', 'AMY'):
        score += int(state.g_province_score_trial[province])
    return score


def _reset_trial_proximity_score(
    state: InnerGameState,
    num_powers: int,
    num_provinces: int,
) -> None:
    """Port ProcessTurn.c:588-624's per-trial proximity reset.

    Every matrix cell starts at the signed ``-1`` sentinel.  The source then
    walks the active-unit list and changes only the cell belonging to that
    unit's owner and province to zero.  BuildSupportProposals mutates nearby
    cells later in the trial, so omitting this reset makes proximity pressure
    accumulate across trials and eventually suppresses all support requests.
    """
    state.g_proximity_score[:num_powers, :num_provinces] = -1
    for province, unit in state.unit_info.items():
        power = int(unit.get('power', -1))
        if 0 <= power < num_powers and 0 <= province < num_provinces:
            state.g_proximity_score[power, province] = 0


def _recompute_trial_support_demand(
    state: InnerGameState,
    power_index: int,
    num_powers: int,
    num_provinces: int,
) -> None:
    """Port ProcessTurn.c:1440-1492's live threat aggregation."""
    designated = np.zeros(num_provinces, dtype=bool)
    for slot_lo, slot_hi in (
        (state.g_ally_designation_b, state.g_ally_designation_b_hi),
        (state.g_ally_designation_a, state.g_ally_designation_a_hi),
        (state.g_ally_designation_c, state.g_ally_designation_c_hi),
    ):
        designated |= (
            np.asarray(slot_lo[:num_provinces], dtype=np.int64) == power_index
        ) & (np.asarray(slot_hi[:num_provinces], dtype=np.int64) == 0)

    trust_lo = np.asarray(
        state.g_ally_trust_score[power_index, :num_powers], dtype=np.int64
    )
    trust_hi = np.asarray(
        state.g_ally_trust_score_hi[power_index, :num_powers], dtype=np.int64
    )
    relation = np.asarray(
        state.g_relation_score[power_index, :num_powers], dtype=np.int64
    )
    base_hostile = ((trust_lo == 0) & (trust_hi == 0)) | (relation < 10)
    trust_lo_unsigned = trust_lo.astype(np.uint32).astype(np.uint64)
    conditional_hostile = (
        (trust_hi >= 0)
        & ((trust_hi > 0) | (trust_lo_unsigned > 1))
    )
    hostile = base_hostile[:, None] | (
        conditional_hostile[:, None] & ~designated[None, :]
    )
    hostile[power_index, :] = False

    raw = np.asarray(
        state.g_coverage_flag[:num_powers, :num_provinces], dtype=np.int64
    )
    proximity = np.asarray(
        state.g_proximity_score[:num_powers, :num_provinces], dtype=np.int64
    )
    adjusted = np.where(proximity > 0, raw - proximity, raw)
    gated = np.where(hostile, adjusted, 0)
    state.g_support_demand[:num_provinces] = np.maximum(
        0, np.max(gated, axis=0)
    )
    state.g_order_table[:num_provinces, _F_THREAT_TOTAL] = np.sum(
        gated, axis=0
    )


def _secondary_exploit_enabled(
    state: InnerGameState,
    random_percent: int,
) -> bool:
    """Return ProcessTurn.c:846-847's secondary-target gate.

    ``DAT_00baed69`` is the canonical near-victory flag populated by
    ``CAL_BOARD`` and modelled as ``g_other_power_lead_flag``.  The former
    ``g_stab_mode`` alias was initialized locally but never written, leaving
    this branch permanently disabled.
    """
    return (
        int(random_percent) < 65
        and int(state.g_other_power_lead_flag) == 1
        and float(state.g_near_end_game_factor) > 6.0
    )


def _select_secondary_exploit_target(
    state: InnerGameState,
    power_index: int,
    exploit_power: int,
    random_percent: int,
    num_powers: int,
) -> int:
    """Port ProcessTurn.c:846-888's secondary allied-power walk."""
    if not _secondary_exploit_enabled(state, random_percent):
        return -1

    trust_lo = int(state.g_ally_trust_score[power_index, exploit_power])
    trust_hi = int(state.g_ally_trust_score_hi[power_index, exploit_power])
    if trust_hi < 0 or (trust_hi == 0 and trust_lo == 0):
        return -1

    candidate = exploit_power + 1
    if candidate == num_powers:
        candidate = 0

    # C tests the negotiated/press-sent matrix first. Only while the current
    # power is absent does it take a random one- or two-slot step, skip one
    # zero-trust power, and stop if the walk returns to exploit_power.
    while not state.g_xdo_press_sent[power_index, candidate]:
        step = 2 if random.randrange(100) < 50 else 1
        candidate += step
        if candidate >= num_powers:
            candidate = 0

        candidate_lo = int(
            state.g_ally_trust_score[power_index, candidate]
        )
        candidate_hi = int(
            state.g_ally_trust_score_hi[power_index, candidate]
        )
        if candidate_lo == 0 and candidate_hi == 0:
            candidate += 1
            if candidate >= num_powers:
                candidate = 0

        if candidate == exploit_power:
            return -1

    return candidate


def _remove_first_convoy_candidate(state: InnerGameState, prov: int) -> bool:
    """Erase the first iterator-order convoy candidate for ``prov``.

    ``MoveCandidate`` receives a concrete tree iterator, so one call erases
    exactly one node.  The candidate tree is a multiset keyed by score and may
    contain more than one node whose payload province is the same.
    """
    for index, (_score, candidate_prov) in enumerate(
            state.g_convoy_fleet_candidates):
        if int(candidate_prov) == int(prov):
            state.g_convoy_fleet_candidates.pop(index)
            return True
    return False


def _insert_order_candidate(candidate_list: list, score: int, entry: dict) -> dict:
    """Insert an exploit-order candidate in C tree iteration order.

    ``InsertOrderCandidate`` uses ``std::greater<int>``: larger scores descend
    left, smaller or equal scores descend right.  Iteration is therefore
    descending, with equal-score entries retaining insertion order.
    """
    import bisect

    descending_keys = [-int(existing_score)
                       for existing_score, _ in candidate_list]
    position = bisect.bisect_right(descending_keys, -int(score))
    new_entry = dict(entry)
    new_entry['score'] = int(score)
    candidate_list.insert(position, (int(score), new_entry))
    return new_entry


def _proposal_support_trust_allowed(
    state: InnerGameState,
    power_index: int,
    own_power: int,
    mover: int,
    destination: int,
    num_powers: int,
) -> bool:
    """Port ProcessTurn.c:1030-1145's proposal-support trust gate.

    BuildSupportProposals records either support-to-hold (mover == destination)
    or support-to-move requests.  The two source branches use slightly
    different designation tests before the common negotiated-province reject.
    This helper covers only those designation tests; accepted-XDO and DMZ map
    membership are checked by the caller at their source locations.
    """

    def designation(arr_lo, arr_hi, province: int) -> tuple[int, int]:
        if not 0 <= province < len(arr_lo):
            return -1, -1
        return int(arr_lo[province]), int(arr_hi[province])

    def trust_for(designated: int, guard_hi: int) -> tuple[int, int] | None:
        if guard_hi < 0 or not 0 <= designated < num_powers:
            return None
        if (power_index != own_power
                and int(state.g_relation_score[power_index, designated]) <= 9):
            return None
        return (
            int(state.g_ally_trust_score[power_index, designated]),
            int(state.g_ally_trust_score_hi[power_index, designated]),
        )

    b_lo, b_hi = designation(
        state.g_ally_designation_b,
        state.g_ally_designation_b_hi,
        destination,
    )
    a_lo, a_hi = designation(
        state.g_ally_designation_a,
        state.g_ally_designation_a_hi,
        destination,
    )
    c_lo, c_hi = designation(
        state.g_ally_designation_c,
        state.g_ally_designation_c_hi,
        destination,
    )
    trust_b = trust_for(b_lo, b_hi)
    trust_a = trust_for(a_lo, a_hi)
    trust_c = trust_for(c_lo, c_hi)

    if mover == destination:
        # C:1057 starts true, then positive B/C trust invalidates the support
        # unless that designation is the same power as ally-A at the target.
        allowed = True
        if trust_b is not None and trust_b[0] > 0 and (a_lo, a_hi) != (b_lo, b_hi):
            allowed = False
        if trust_c is not None and trust_c[0] > 0 and (a_lo, a_hi) != (c_lo, c_hi):
            allowed = False
        return allowed

    mover_a_lo, mover_a_hi = designation(
        state.g_ally_designation_a,
        state.g_ally_designation_a_hi,
        mover,
    )
    # ProcessTurn.c:1114-1131.  With no qualifying designations all three
    # pointers are null and the request is admissible.  Otherwise positive
    # B-trust admits it only when B agrees with mover-A and either target-A is
    # absent or agrees with B.
    if trust_b is None:
        return trust_a is None and trust_c is None
    if trust_b[0] <= 0 or (b_lo, b_hi) != (mover_a_lo, mover_a_hi):
        return False
    return trust_a is None or (b_lo, b_hi) == (a_lo, a_hi)


def _build_proposal_support_order(
    state: InnerGameState,
    power_index: int,
    supporter: int,
    mover: int,
    destination: int,
    requester_power: int,
) -> None:
    """Write ProcessTurn.c:1151-1203's proposal-exploit support order.

    This direct source path is not either public BuildOrder_SUP function.  It
    writes the low-level ring/order record, source score, requester trust tier,
    and target convoy-active flag, but performs neither convoy registration nor
    the public builders' chain-robustness update at the supported destination.
    """
    order_type = _ORDER_SUP_HLD if mover == destination else _ORDER_SUP_MTO
    state.g_order_table[supporter, _F_ORDER_TYPE] = float(order_type)
    if order_type == _ORDER_SUP_MTO:
        state.g_order_table[supporter, _F_SECONDARY] = float(mover)
    state.g_order_table[supporter, _F_DEST_PROV] = float(destination)
    state.g_order_table[supporter, _F_INCOMING_MOVE] = 1.0

    unit_type = (state.unit_info.get(supporter) or {}).get('type')
    score = state.fss(power_index, supporter, unit_type)
    state.g_convoy_chain_score[supporter] = score
    state.g_order_score_hi[supporter] = 0.0
    state.g_order_table[supporter, _F_CONVOY_LO] = score
    state.g_order_table[supporter, _F_CONVOY_HI] = 0.0
    if unit_type in ('A', 'AMY'):
        state.g_order_table[supporter, 24] = 0.0
        state.g_order_table[supporter, 25] = 0.0

    if 0 <= requester_power < state.g_ally_trust_score.shape[1]:
        trust_lo = float(
            state.g_ally_trust_score[power_index, requester_power]
        )
        trust_hi = int(
            state.g_ally_trust_score_hi[power_index, requester_power]
        )
        if trust_lo == 0.0 and trust_hi == 0:
            state.g_support_trust_adj = 30
        elif trust_hi < 1 and (trust_hi < 0 or trust_lo < 5):
            state.g_support_trust_adj = 10
        else:
            state.g_support_trust_adj = -10
    state.g_convoy_active_flag[destination] = 1


def _apply_proposal_support_candidate(
    state: InnerGameState,
    power_index: int,
    own_power: int,
    candidate: dict,
    reachable_provinces: dict[int, bool],
    accepted_xdo: dict[int, int],
    num_powers: int,
    primary_partner: int | None = None,
) -> bool:
    """Consume one ProposalHistory record as C Phase 1e support.

    Returns whether an order was committed.  The recovered record layout is
    supporter source in ``unit_prov``, supported source in ``via_prov``, and
    supported destination in ``dst_prov``.
    """
    supporter = int(candidate.get('unit_prov', -1))
    mover = int(candidate.get('via_prov', -1))
    destination = int(candidate.get('dst_prov', -1))
    unit = state.unit_info.get(supporter)
    if unit is None or int(unit.get('power', -1)) != power_index:
        return False
    if int(state.g_order_table[supporter, _F_ORDER_TYPE]) != 0:
        return False

    # ProcessTurn.c:904/915 requires both accepted-XDO lookups to return end;
    # C:1136-1145 then rejects a supporter source claimed by the negotiated
    # DMZ/promise map.
    if supporter in accepted_xdo or destination in accepted_xdo:
        return False
    if supporter in reachable_provinces:
        return False
    if not state.can_reach_by_type(
        supporter,
        destination,
        unit.get('type', 'A'),
        unit.get('coast', ''),
    ):
        return False
    if not _proposal_support_trust_allowed(
        state, power_index, own_power, mover, destination, num_powers
    ):
        return False

    if mover != destination and mover not in state.unit_info:
        return False
    _build_proposal_support_order(
        state,
        power_index,
        supporter,
        mover,
        destination,
        int(candidate.get('target_power', -1))
        if primary_partner is None else int(primary_partner),
    )
    return int(state.g_order_table[supporter, _F_ORDER_TYPE]) in (
        _ORDER_SUP_HLD, _ORDER_SUP_MTO
    )


def process_turn(state: InnerGameState, power_index: int, num_trials: int = -1) -> None:
    """
    Port of FUN_00453220 = ProcessTurn(Albert *this, int **power_index, int num_trials).

    Per-power Monte Carlo order-assignment engine.  Called by ScoreOrderCandidates
    once per active power.  Runs ``num_trials`` independent MC trials for
    ``power_index`` and accumulates results into state.g_candidate_record_list.

    Signature matches decompiled: __thiscall ProcessTurn(param_1_00, power_index, num_trials)
      param_1_00  → state (Albert *this)
      power_index → the power being simulated this call
      num_trials  → number of Monte Carlo iterations; if -1 (default), computed from
                    state per ScoreOrderCandidates.c:331–334:
                    (unit_count[p] * g_trial_scale + 10) // 10, or 1 for non-own
                    powers when g_press_proposals_cap == 0.

    Phase 0 — Setup (once per call)
    --------------------------------
    0a. Build reachable-province set from the DMZ promise/counter maps.
    0b. Snapshot each power's accepted-XDO source→destination map.
    0c. Ally flag scan: local_76f = 1 if g_xdo_press_sent[power_index, p] for any p.
    0d. Random start offset for the cyclical power-expand pass.

    Phase 1 — Monte Carlo trial loop (num_trials iterations)
    ----------------------------------------------------------
    Each trial:
    1a. Per-trial state reset:
        - clear g_support_trust_adj / g_ring_convoy_score / g_EarlyGameAdjScore / g_other_score
        - clear g_convoy_dst_list, g_support_opp_map, g_trial_map
        - reset g_order_table all-provinces (order type 0, coast -1, other fields 0)
        - reset g_convoy_source_prov[prov] = -1, g_convoy_active_flag[prov] = 0,
          g_ProvinceScore[prov] = 0, g_army_adj_count[prov] = 0
        - reset g_unit_presence[power, prov] = -1 for all power,prov
    1b. Unit list scan:
        - g_unit_presence[unit.power, unit.province] = 0
        - for own armies: g_army_adj_count[adj]++ for each AMY-adjacent province
    1c. Dispatch existing orders (priority HLD→MTO→CTO→CVY→SUP):
        - If power_index == own_power (or trusted ally): dispatch g_alliance_orders[power_index]
        - Dispatch g_general_orders[power_index] (second pass)
    1d. Ring-convoy check (if g_ring_convoy_enabled):
        - Verify ring A→B, B→C, C→A is still intact; build MTO orders if valid.
    1e. Random proposal-support pass (15%; 35% if late-game + has_ally):
        - Select matching proposal-history records for the simulated supporter.
        - Emit SUP_HLD or SUP_MTO after trust, XDO/DMZ, and reachability gates.
    1f. Support assignment:
        - Find own unordered SC provinces → call assign_hold_supports.
    1g. Convoy chain assignment:
        - Iterate g_convoy_dst_list; score / rank fleet candidates via score_convoy_fleet.
    1h. Target-bonus scoring:
        - +150/+75 per MTO/CTO unit moving to a flagged target province.
        - +50 per SUP_MTO into an SC-gaining support.
    1i. Call evaluate_order_proposal(state, power_index) once per trial.

    Ported callees:
      reset_per_trial_state   — FUN_00460be0; resets board-level snapshot
      dispatch_single_order   — dispatch.py; already ported
      assign_hold_supports    — FUN_0041d270; ported (moves.hold)
      score_convoy_fleet      — BST insert-with-score; ported (moves.convoy)
      move_candidate          — BST erase/pop from Albert+0x4cfc; ported as
                                _remove_first_convoy_candidate
      build_order_mto         — writes MTO into g_order_table; ported (inner func)
      insert_order_candidate  — FUN_004153b0; std::_Tree::_Insert for
                                InsertOrderCandidate tree; ported as
                                _insert_order_candidate
      evaluate_order_proposal — monte_carlo.py; already ported
    """
    import logging
    logger = logging.getLogger(__name__)

    own_power: int = getattr(state, 'albert_power_idx', 0)

    # ScoreOrderCandidates.c:331–334: compute per-power trial count when the
    # caller did not supply one explicitly.
    if num_trials < 0:
        _uc = getattr(state, 'g_unit_count', [])
        _scale = int(getattr(state, 'g_trial_scale', 260))
        num_trials = max(1, (int(_uc[power_index]) * _scale + 10) // 10)
    # ScoreOrderCandidates.c:333–335: clamp non-own powers to 1 trial when
    # press proposals are disabled.  Applied unconditionally so callers that
    # pass explicit num_trials are also guarded.
    if int(getattr(state, 'g_press_proposals_cap', 30)) == 0 and power_index != own_power:
        num_trials = 1

    num_provinces: int = int(getattr(state, 'num_provinces',
                                     state.g_order_table.shape[0]))
    num_powers: int = 7

    # ── local source-equivalent helpers ────────────────────────────────────────────
    def _reset_per_trial_state() -> None:
        """Port of FUN_00460be0 = ResetPerTrialState.

        C operations (see Source/monte_carlo/ResetPerTrialState.c):
        (1) Walk active unit list (this+0x2450/54): clear node+0x20 per unit.
        (2) Walk retreat unit list (this+0x245c/60): same.
        (3) Walk and free all BST nodes at this+0x2478 (lines 52-60).
        (4) Reset BST sentinel: sentinel[1]=sentinel, *sentinel=sentinel,
            sentinel[2]=sentinel (lines 61, 63, 64).
        (5) this+0x247c = 0  — BST _Mysize counter (line 62).
        (6) this+0x2480 = 0  — waive count (line 65).
        Python: (3)+(4)+(5) are all implicit in list.clear(); tracked
        explicitly via g_build_order_list_size for offset parity.
        """
        # (1) Active unit list — clear per-unit order-assigned pointer.
        for prov in state.unit_info:
            state.g_order_table[prov, _F_ORDER_TYPE] = 0.0
        # (2) Retreat unit list — clear per-unit order-assigned pointer.
        for entry in getattr(state, 'g_retreat_order_list', []):
            entry['order_type'] = 0
        # (3)+(4) Free BST nodes + reset sentinel → list.clear().
        state.g_build_order_list.clear()
        # (5) this+0x247c = 0 — BST size counter.
        state.g_build_order_list_size = 0
        # (6) this+0x2480 = 0 — waive count.
        state.g_waive_count = 0

    def _build_order_hld(src: int) -> None:
        """Port of BuildOrder_HLD (Source/moves/BuildOrder_HLD.c).

        The port previously wrote only col 0 at all eight emission sites.  C
        writes six fields; the load-bearing ones are col 13 = 1
        (g_ProvinceBaseScore) and col 6 = final_score_set[power][src]
        (g_ConvoyChainScore), the order-score channel EvaluateOrderScore reads
        at evaluation.py:539.  Without col 6 a held unit contributed 0 where C
        contributes fss(self), suppressing holds as an order class (the port
        emitted 0 holds against Albert's 21).
        """
        u = state.unit_info.get(src) or {}
        utype = u.get('type', 'A')
        ot = state.g_order_table
        ot[src, _F_ORDER_TYPE]    = float(_ORDER_HLD)          # C: g_OrderTable = 1
        ot[src, _F_DEST_PROV]     = float(src)                 # C: DAT_00baeda8 = self
        ot[src, _F_DEST_COAST]    = float(_unit_location_token(
            utype, u.get('coast', '')
        ))                                                       # C: DAT_00baedac = unit token
        ot[src, _F_INCOMING_MOVE] = 1.0                        # C: g_ProvinceBaseScore = 1
        _fs = state.fss(power_index, src, utype)
        ot[src, _F_CONVOY_LO]     = float(_fs)                 # C: g_ConvoyChainScore
        ot[src, _F_CONVOY_HI]     = 0.0                        # C: DAT_00baedbc
        if utype in ('A', 'AMY'):                              # C: if (AMY)
            ot[src, 24] = 0.0
            ot[src, 25] = 0.0
        # C tail call at BuildOrder_HLD.c:24.  Measured inert on S1901M (no
        # convoys in spring 1901) but faithful; it marks fleet-adjacency
        # convoy candidates, which matters in convoy-bearing phases.
        register_convoy_fleet(state, power_index, src)

    def _build_order_mto(src: int, dst: int, coast: int) -> None:
        """Port of BuildOrder_MTO — write MTO into g_order_table.

        Decompile-verified (decompiled.txt).  Signature:
          __thiscall BuildOrder_MTO(this, power, src_province, dst_province, coast)

        Recovered callees:
          ClearConvoyState()        — empty callback (Source/utils/clear.c)
          BuildOrder_CTO_Ring(...)  — builds CTO ring chain; decompile-verified (BuildOrder_CTO.c:67)
          RegisterConvoyFleet(...)  — decompile-verified (RegisterConvoyFleet.c); called at end of fn
        """
        # ClearConvoyState() is an empty callback; no Python action is needed.

        # Every recovered ProcessTurn call site caches the UnitList lookup for
        # the destination before invoking BuildOrder_MTO. AssignSupportOrder's
        # conflict tail consumes the occupant's pre-existing order record.
        if dst in state.unit_info:
            state.g_last_mto_insert = (
                int(state.g_order_table[dst, _F_ORDER_TYPE]),
                int(state.g_order_table[dst, _F_DEST_PROV]),
            )
        else:
            state.g_last_mto_insert = None

        # Determine unit type at src (AMY vs FLT)
        unit_type = state.unit_info.get(src, {}).get('type', '')
        is_army = (unit_type == 'A')

        # Unit-type terrain gate: fleets cannot enter landlocked provinces,
        # armies cannot enter sea zones.  Silently reject — the trial will
        # fall back to the default HLD seeded in Phase 1b'.
        if unit_type in ('F', 'FLT') and dst in state.land_provinces:
            return
        if unit_type in ('A', 'AMY') and dst in state.water_provinces:
            return

        # ── Coast resolution for multi-coast destinations ────────────────
        # In C, each adjacency-list edge carries a coast token (piVar7[4]),
        # so the BST candidate node already has the correct coast when
        # BuildOrder_MTO is called.  The Python adj_matrix only stores
        # province IDs, so callers pass coast=0.  Resolve it here for
        # fleet moves to multi-coast provinces (BUL, SPA, STP).
        if coast == 0 and unit_type in ('F', 'FLT'):
            coast = state.resolve_fleet_coast(src, dst)
        if coast == 0:
            coast = _unit_location_token(unit_type)

        # BuildOrder_CTO_Ring(gamestate, src, dst, coast)
        # OrderedSet_FindOrInsert(this+0x2450, &src): insert src into active-unit set.
        # If src already present (iVar2 == iVar3 sentinel) → early return, no-op.
        # Otherwise write node+0x20=2 (MTO ring), node+0x24=dst, node+0x28=coast.
        # Python: g_order_table proxies the ordered-set node fields; guard on
        # _F_ORDER_TYPE != 0 mirrors the "already inserted" early-return.
        if int(state.g_order_table[src, _F_ORDER_TYPE]) == 0:
            state.g_order_table[src, _F_ORDER_TYPE] = float(_ORDER_MTO)  # 2 = MTO ring
            state.g_order_table[src, _F_DEST_PROV]  = float(dst)
            state.g_order_table[src, _F_DEST_COAST] = float(coast)

        # ConvoyList_Insert(&DAT_00bb65a0, &dst): append dst to convoy dst list; record dst→src
        if dst not in state.g_convoy_dst_list:
            state.g_convoy_dst_list.append(dst)
        if not hasattr(state, 'g_convoy_dst_to_src'):
            state.g_convoy_dst_to_src = {}
        state.g_convoy_dst_to_src[dst] = src

        # g_order_table[src]: write MTO order type, destination, coast
        state.g_order_table[src, _F_ORDER_TYPE] = float(_ORDER_MTO)
        state.g_order_table[src, _F_DEST_PROV]  = float(dst)
        state.g_order_table[src, _F_DEST_COAST] = float(coast)

        # g_ProvinceBaseScore[dst] = 1: mark dst as having an incoming move
        state.g_order_table[dst, _F_INCOMING_MOVE] = 1.0

        # OrderedSet_FindOrInsert(this + power*0xc + 0x4000, &dst):
        # inherit dst's candidate score (final_score_set) into convoy chain score fields
        score_lo = state.fss(power_index, dst,
                             (state.unit_info.get(src) or {}).get('type'))
        score_hi = 0.0
        state.g_convoy_chain_score[dst]        = score_lo
        state.g_order_score_hi[dst]            = score_hi
        state.g_order_table[dst, _F_CONVOY_LO] = score_lo
        state.g_order_table[dst, _F_CONVOY_HI] = score_hi

        # DAT_00baede4[dst*0x1e] = g_move_history_matrix[dst + (src + power*0x40)*0x40]
        # Python layout: g_move_history_matrix[power, src, dst]
        state.g_order_table[dst, _F_MOVE_HISTORY] = float(
            state.g_move_history_matrix[power_index, src, dst]
        )

        # If AMY and convoy chain depth at src ≠ 5 (not complete): clear dst score fields
        # DAT_00baedf0[src*0x1e] = _F_ORDER_ASGN holds convoy chain depth in this context
        if is_army and int(state.g_order_table[src, _F_ORDER_ASGN]) != 5:
            state.g_order_table[dst, 24] = 0.0  # DAT_00baee00[dst*0x1e]
            state.g_order_table[dst, 25] = 0.0  # DAT_00baee04[dst*0x78]

        register_convoy_fleet(state, power_index, dst)

        # AssignSupportOrder(this, power, src, dst, coast, NULL)
        assign_support_order(state, power_index, src, dst, coast, flag=0)

    # ── lazy-init per-trial arrays not yet on state ───────────────────────────
    if not hasattr(state, 'g_unit_presence'):
        state.g_unit_presence = np.full((num_powers, num_provinces), -1, dtype=np.int32)
    if not hasattr(state, 'g_convoy_active_flag'):
        state.g_convoy_active_flag = np.zeros(num_provinces, dtype=np.int32)
    if not hasattr(state, 'g_convoy_dst_list'):
        state.g_convoy_dst_list = []
    if not hasattr(state, 'g_trial_map'):
        state.g_trial_map = {}
    if not hasattr(state, 'g_support_trust_adj'):
        state.g_support_trust_adj = 0
    if not hasattr(state, 'g_ring_convoy_score'):
        state.g_ring_convoy_score = 0
    if not hasattr(state, 'g_other_score'):
        state.g_other_score = 0
    if not hasattr(state, 'g_ring_convoy_enabled'):
        state.g_ring_convoy_enabled = 0
    if not hasattr(state, 'g_ring_prov_a'):
        state.g_ring_prov_a = -1
    if not hasattr(state, 'g_ring_prov_b'):
        state.g_ring_prov_b = -1
    if not hasattr(state, 'g_ring_prov_c'):
        state.g_ring_prov_c = -1
    if not hasattr(state, 'g_ring_coast_a'):
        state.g_ring_coast_a = 0
    if not hasattr(state, 'g_ring_coast_b'):
        state.g_ring_coast_b = 0
    if not hasattr(state, 'g_ring_coast_c'):
        state.g_ring_coast_c = 0
    if not hasattr(state, 'g_alliance_orders'):
        state.g_alliance_orders = {}          # {power: [order_seq, ...]}
    if not hasattr(state, 'g_general_orders'):
        state.g_general_orders = {}           # {power: [order_seq, ...]}
    # NB: g_alliance_orders_present / g_general_orders_present do NOT exist as
    # separate globals in the C binary.  ScoreOrderCandidates.c reads them as
    # `&DAT_00bb6d00 + p*0xc`, which is the `_Mysize` field (offset +8) of the
    # std::set<order_record> at slot p inside g_general_orders (each slot is
    # 0xc bytes: comparator/_Myhead/_Mysize).  Same for the alliance variant.
    # We model the "is populated" check as `len(state.g_general_orders.get(p,
    # ())) > 0` directly — no parallel array — to avoid the parallel-state
    # rot that bit us before (always-zero array → 1c never dispatched even
    # when orders existed).
    if not hasattr(state, 'g_proposal_history_map'):
        # DAT_00baed98 — proposal history map; mirrors state.g_deal_list
        state.g_proposal_history_map = getattr(state, 'g_deal_list', [])
    # ── Phase 0 — Setup ───────────────────────────────────────────────────────

    # 0a/0b. Negotiated DMZ reach plus accepted-XDO source maps.
    reachable_provinces, per_power_order_sets = (
        _build_negotiated_province_context(
            state, power_index, own_power, num_powers
        )
    )

    # 0c. Ally flag scan: local_76f = 1 if any g_xdo_press_sent[power_index, p] == 1.
    has_ally: bool = bool(
        np.any(state.g_xdo_press_sent[power_index] == 1)
    )

    # 0d. Random start offset for the cyclical power-expand pass.
    rand_power_start: int = random.randrange(num_powers)
    rand_power_cursor: int = rand_power_start

    # ── Phase 1 — Monte Carlo trial loop ─────────────────────────────────────
    # Mirror of the do { ... } while (iStack_684 < num_trials) block.

    for _trial in range(num_trials):

        # 1a. Per-trial state reset ────────────────────────────────────────────
        state.g_support_trust_adj   = 0     # DAT_00633f14
        state.g_ring_convoy_score   = 0     # DAT_0062c57c
        state.g_early_game_bonus    = 0     # DAT_0062be94 (g_EarlyGameAdjScore)
        state.g_other_score        = 0     # DAT_0062b7ac

        _reset_per_trial_state()           # FUN_00460be0

        # Clear per-trial containers (DAT_00bb65a4 / DAT_00bbf648 /
        # DAT_00bb6e04). DAT_00bbf648 is the head of g_support_opp_map below,
        # not a separate list.
        state.g_convoy_dst_list.clear()
        state.g_trial_map.clear()
        # C:510-522 clears the dst→src move map itself at the top of every
        # trial — the tree-destroy walk followed by resetting the header's
        # _Left/_Parent/_Right to self is MSVC's std::map::clear().  Python's
        # list is only the ordered-key view of this same C map, so both Python
        # representations must be cleared together.  Otherwise trial 2+ can
        # find a stale source and support its own move.
        state.g_convoy_dst_to_src.clear()
        # Same omission for the convoy-rescore map (C `&DAT_00bb6e00`, bound as
        # g_sub_order_map): C:536-547 clears it per trial with the same
        # tree-destroy + reset-header sequence.  Step 1's source-province dedup
        # and monte_carlo/evaluation.py:517 both read it, so a map that only
        # ever grew let trial 2+ see trial 1's memberships.
        state.g_sub_order_map.clear()

        # Reset per-province order-table fields.
        # Mirrors the loop over 0..numProvinces zeroing DAT_00baedac fields.
        state.g_order_table[:num_provinces, :] = 0.0
        state.g_order_table[:num_provinces, _F_DEST_COAST] = -1.0   # 0xffffffff
        # g_SupportScoreLo/Hi (fields 18/19) use -1.0 as "unset" sentinel
        # to match C's (lo & hi) == 0xffffffff AssignSupportOrder check.
        # Fixed 2026-04-14 — was 0.0, which conflated "zero score" with "unset".
        state.g_order_table[:num_provinces, 18] = -1.0
        state.g_order_table[:num_provinces, 19] = -1.0
        # H3 verified: g_convoy_source_prov IS g_SupportAssignmentMap — C uses a
        # single array at one address for both support assignment and convoy
        # source tracking.  ProcessTurn.c:580 resets it to 0xffffffff each
        # trial, then support and convoy dispatch write sequentially (no conflict).
        state.g_convoy_source_prov[:num_provinces]  = -1.0  # g_SupportAssignmentMap sentinel (0xffffffff)
        state.g_convoy_active_flag[:num_provinces]  = 0
        state.g_province_score_trial[:num_provinces] = 0
        if hasattr(state, 'g_convoy_source_score'):
            state.g_convoy_source_score[:num_provinces] = 0.0
        state.g_army_adj_count[:num_provinces]      = 0
        state.g_convoy_fleet_registered.clear()
        # DAT_00bbf644 — per-trial ScoreSupportOpp map (src_prov → dest_prov).
        state.g_support_opp_map: dict = {}

        # Reset unit-presence matrix (g_unit_presence[power*0x100+prov] = -1).
        state.g_unit_presence[:, :num_provinces] = -1

        # ProcessTurn.c:588-624 resets the full proximity matrix to -1 and
        # then zeroes the owner/province cell of every active unit.  This is a
        # trial-local accumulator used by BuildSupportProposals.
        _reset_trial_proximity_score(state, num_powers, num_provinces)

        # 1b. Unit list scan ───────────────────────────────────────────────────
        # Mirrors: for each unit in this+8+0x2450 { g_unit_presence[...] = 0;
        #           if own AMY: g_army_adj_count[adj]++ }
        for prov, unit in state.unit_info.items():
            p_u  = unit['power']
            utyp = unit.get('type', '')
            state.g_unit_presence[p_u, prov] = 0

            if p_u == power_index and utyp in ('A', 'AMY'):
                for adj, _edge_type, _edge_coast in state.get_reachable_edges(
                    prov, utyp, unit.get('coast', ''),
                ):
                    state.g_army_adj_count[adj] += 1

        # 1b'. Default-HOLD seed — MOVED to after evaluate_order_proposal ────
        # H2 fix: In C, units without orders remain at order_type==0 and are
        # skipped by EvaluateOrderProposal (which checks order_type != 0).
        # Pre-seeding HLD before dispatch made all own units enter the HLD
        # branch of Step 3, inflating heat scores for units that C would skip.
        #
        # The HLD seed is now applied AFTER evaluate_order_proposal (see
        # "1b'-post" below) so that evaluation matches C's skip-zero behavior,
        # while still ensuring every unit has an order for submission.

        # 1c. Dispatch existing orders (priority HLD→MTO→CTO→CVY→SUP) ─────────
        # First pass: alliance orders (DAT_00bb65f8[power*0xc]) — own or trusted ally.
        # Use the same source-backed DispatchSingleOrder port as the validated
        # order path.  Formatting is suppressed because C only projects these
        # negotiated orders into the per-trial table here; it does not append
        # them to the final submission list once per Monte Carlo trial.
        dispatch_first_pass = False
        if power_index == own_power:
            dispatch_first_pass = True
        else:
            trust_lo2 = int(state.g_ally_trust_score[own_power, power_index])
            trust_hi2 = int(state.g_ally_trust_score_hi[own_power, power_index])
            if trust_hi2 > 0 or (trust_hi2 >= 0 and trust_lo2 > 2):
                dispatch_first_pass = True

        # Priority mirrors ProcessTurn's loop order: HLD → MTO → CTO → CVY → SUP.
        # SUP is last because it can depend on the mover's MTO landing first.
        _DISPATCH_PRIORITY = ['HLD', 'MTO', 'CTO', 'CVY', 'SUP']

        if dispatch_first_pass and len(state.g_alliance_orders.get(power_index, ())) > 0:
            for wanted_type in _DISPATCH_PRIORITY:
                for order_seq in state.g_alliance_orders.get(power_index, []):
                    if (order_seq.get('type') or '').upper() == wanted_type:
                        dispatch_single_order(
                            state, power_index, order_seq,
                            record_submission=False,
                        )

        # Second pass: general orders (DAT_00bb6cf8[power*0xc]) — unconditional.
        if len(state.g_general_orders.get(power_index, ())) > 0:
            for wanted_type in _DISPATCH_PRIORITY:
                for order_seq in state.g_general_orders.get(power_index, []):
                    if (order_seq.get('type') or '').upper() == wanted_type:
                        dispatch_single_order(
                            state, power_index, order_seq,
                            record_submission=False,
                        )

        # HOLD-DBG: after Phase 1c — log what was dispatched for own-power units.
        # Fires once per turn (trial 0 only) to trace why units hold.
        if _trial == 0 and power_index == own_power:
            _id2n = getattr(state, '_id_to_prov', {})
            _pnames = ['AUT', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']
            _pname = _pnames[power_index] if power_index < len(_pnames) else str(power_index)
            _after1c = {
                _id2n.get(p, str(p)): int(state.g_order_table[p, _F_ORDER_TYPE])
                for p, u in state.unit_info.items()
                if u.get('power') == power_index
            }
            _gen_cnt = len(state.g_general_orders.get(power_index, []))
            _ali_cnt = len(state.g_alliance_orders.get(power_index, []))
            logger.info(
                "HOLD_DBG[%s] trial=0 after Phase1c: "
                "gen_orders=%d ali_orders=%d  unit_ot_after_dispatch=%s",
                _pname, _gen_cnt, _ali_cnt, _after1c,
            )

        # 1d. Ring-convoy check (DAT_00baed5c == 1) ───────────────────────────
        if state.g_ring_convoy_enabled == 1:
            ring_broken = False
            pA, pB, pC = state.g_ring_prov_a, state.g_ring_prov_b, state.g_ring_prov_c
            if (int(state.g_order_table[pA, _F_ORDER_TYPE]) == _ORDER_MTO and
                    int(state.g_order_table[pA, _F_DEST_PROV]) != pB):
                ring_broken = True
            if (int(state.g_order_table[pB, _F_ORDER_TYPE]) == _ORDER_MTO and
                    int(state.g_order_table[pB, _F_DEST_PROV]) != pC):
                ring_broken = True
            if (int(state.g_order_table[pC, _F_ORDER_TYPE]) == _ORDER_MTO and
                    int(state.g_order_table[pC, _F_DEST_PROV]) != pA):
                ring_broken = True

            # Also check whether unit is absent from ring province (own-power gate).
            if power_index == own_power:
                # ProcessTurn.c:756-781 nests three find()==end() checks and
                # reaches the builder only when NONE of the ring sources is
                # constrained by Albert's accepted-XDO move map.  The old port
                # inverted this and required all three sources to be present.
                if any(
                    province in per_power_order_sets[power_index]
                    for province in (pA, pB, pC)
                ):
                    ring_broken = True
            # If ring intact: build the three MTO orders.
            if not ring_broken:
                _build_order_mto(pA, pB, state.g_ring_coast_a)
                _build_order_mto(pB, pC, state.g_ring_coast_b)
                _build_order_mto(pC, pA, state.g_ring_coast_c)

        # 1e. Random exploit pass ─────────────────────────────────────────────
        # C:816-820 and 1210-1211 share one roll.  Any power with a proposal
        # partner enters below 15%; non-Albert powers also enter below 35% in
        # the late-game branch.  The separate 65%/other-power-lead roll occurs
        # *inside* this block when choosing a secondary target (C:843-880).
        r_exploit = random.randrange(100)
        do_exploit = bool(
            has_ally
            and (
                r_exploit < 15
                or (
                    power_index != own_power
                    and r_exploit < 35
                    and state.g_near_end_game_factor > 6.0
                )
            )
        )

        if do_exploit:
            # Advance cyclical power cursor to next allied power.
            rand_power_cursor = (rand_power_cursor + 1) % num_powers
            # Find an allied power.
            exploit_power = rand_power_cursor
            for _ in range(num_powers):
                if state.g_xdo_press_sent[power_index, exploit_power]:
                    break
                exploit_power = (exploit_power + 1) % num_powers

            # Determine secondary target for stab scoring (65% × late-game).
            r2 = random.randrange(100)
            secondary_target = _select_secondary_exploit_target(
                state,
                power_index,
                exploit_power,
                r2,
                num_powers,
            )

            # Build exploit candidate list (local_6e0 in C — temporary scored list)
            # C's local_6e4 is the temporary scored candidate tree. The
            # persistent DAT_00bb69f8 accepted-XDO map is read here but is not
            # mutated by this proposal-history scan.
            exploit_candidates: list = []   # [(score, entry_dict), ...] descending

            # Scan proposal history (DAT_00baed98 / g_deal_list) for matching entries.
            for rec in list(state.g_proposal_history_map):
                if rec.get('power') != power_index:
                    continue
                rec_prov = rec.get('province', -1)
                dst_prov = rec.get('dst_prov', -1)
                # Both accepted-XDO probes at C:904/915 must return end.
                if (rec_prov in per_power_order_sets[power_index]
                        or dst_prov in per_power_order_sets[power_index]):
                    continue
                score = rec.get('score', 0)
                entry = {
                    'unit_prov':    rec_prov,
                    'target_power': rec.get('target_power', -1),
                    'via_prov':     rec.get('src_prov', -1),
                    'dst_prov':     rec.get('dst_prov', -1),
                }
                # Primary insert: auStack_204 call site (C line 939).
                if rec.get('target_power') == exploit_power:
                    _insert_order_candidate(exploit_candidates, score, entry)
                # Secondary insert: auStack_150 call site (C line 966).
                # Condition: target_power == secondary_target AND via_prov == dst_prov.
                if secondary_target >= 0 and rec.get('target_power') == secondary_target:
                    if rec.get('src_prov') == rec.get('dst_prov'):
                        _insert_order_candidate(exploit_candidates, score, entry)

            # Count cap computed AFTER insertions (mirrors decompile: lines 81–102
            # overwrite ppiStack_7bc with the cap after the insertion loop).
            r3 = random.randrange(100)
            if secondary_target < 0:
                # C: if (iVar20 < 0x41) cap=1; else cap = (0x54 < iVar20) + 2
                # → [0,64]→1, [65,84]→2, [85,99]→3
                if r3 < 65:
                    count_cap = 1
                else:
                    count_cap = 2 + int(r3 > 84)
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
            # Iterate local_6e4 descending by score; 60% rand gate + total count cap.
            # Full trust/convoy conditions are implemented below:
            #   - relay province reads via g_ally_designation_b/c (≈ g_ConvoyProv1/2)
            #     and g_ally_designation_a (≈ g_ConvoyProv3 / ally guard)
            #   - three-probe trust accumulation (relay3, relay1, ally_a last-wins)
            #   - early-game mutual-trust path vs. not-early-game low-trust gate
            #   - reachability via reachable_provinces (≈ GameBoard_GetPowerRec)
            #   - convoy route dispatch via _get_convoy_route / build_convoy_orders
            consumed = 0
            for _score, cand in exploit_candidates:
                if random.randrange(100) >= 60:     # < 0x3c = 60% gate
                    continue
                if consumed >= count_cap:
                    break
                unit_prov = cand['unit_prov']
                if int(state.g_unit_presence[power_index, unit_prov]) == -1:
                    continue

                if _apply_proposal_support_candidate(
                    state,
                    power_index,
                    own_power,
                    cand,
                    reachable_provinces,
                    per_power_order_sets[power_index],
                    num_powers,
                    primary_partner=exploit_power,
                ):
                    consumed += 1

        # 1f. Support assignment ───────────────────────────────────────────────
        # Seed the live peak/sum threat fields before the candidate-tree walk.
        # The source refreshes them per unit because proximity can change.
        _recompute_trial_support_demand(
            state, power_index, num_powers, num_provinces
        )

        # Find own unordered SC provinces; call AssignHoldSupports.
        # Mirrors: for each prov where g_sc_ownership[power_index,prov]==1 AND
        #          g_order_table[prov,0]==0 → add to support_candidates.
        support_candidates: dict = {}
        for prov in range(num_provinces):
            if (state.g_sc_ownership[power_index, prov] == 1 and
                    int(state.g_order_table[prov, _F_ORDER_TYPE]) == 0):
                support_candidates[prov] = True
        if _trial == 0 and power_index == 3 and _dbg_log.isEnabledFor(logging.DEBUG):
            id2n = getattr(state, '_id_to_prov', {})
            _sc_provs = [(id2n.get(p, str(p)), int(state.g_sc_ownership[3, p]))
                         for p in range(num_provinces) if state.g_sc_ownership[3, p] == 1]
            _ot_provs = [(id2n.get(p, str(p)), int(state.g_order_table[p, _F_ORDER_TYPE]))
                         for p in range(num_provinces) if int(state.g_order_table[p, _F_ORDER_TYPE]) != 0]
            _unit_provs = [(id2n.get(p, str(p)), u.get('power'), u.get('type'))
                           for p, u in state.unit_info.items() if u.get('power') == 3]
            _dbg_log.debug(
                "MC_DBG[GER] Phase1f: sc_provs=%s  ordered_provs=%s  "
                "own_units=%s  support_cands=%s  g_convoy_fleet_cands_before=%d",
                _sc_provs, _ot_provs, _unit_provs,
                [id2n.get(p, str(p)) for p in support_candidates],
                len(state.g_convoy_fleet_candidates),
            )
        assign_hold_supports(state, support_candidates)

        # AssignHoldSupports only ranks the shared candidate tree. Support
        # orders are emitted later by the candidate resolver and two-pass sweep.

        # 1g. Convoy chain assignment ─────────────────────────────────────────
        # Iterate g_convoy_dst_list (DAT_00bb65a4); for each prov with enemy presence /
        # SC ownership: find in Albert+0x4cfc candidate list → ScoreConvoyFleet.
        fleet_pool_a = 0x7ffb   # ppiStack_7c0 initial value (from decompile line 1239)
        inserted_count = 0
        for prov in list(state.g_convoy_dst_list):
            iVar20 = power_index * 0x100 + prov
            enemy_hi  = int(state.g_enemy_presence[power_index, prov])
            sc_own    = int(state.g_sc_ownership[power_index, prov])
            if enemy_hi > 0 or (enemy_hi >= 0 and sc_own != 0):
                # Mirrors: find ppiStack_7bc in Albert+0x4cfc where node[4]==prov
                # then MoveCandidate + StdMap_FindOrInsert + ScoreConvoyFleet.
                inserted_count += 1
                fleet_pool_a -= 1
                _remove_first_convoy_candidate(state, prov)
                state.g_sub_order_map.add(prov)
                score_convoy_fleet(state, prov, fleet_pool_a)

        # Own-power only: second convoy pass (ProcessTurn.c lines 1294–1409).
        # Iterates g_convoy_fleet_candidates (Albert+0x4cfc); for candidates with
        # score < 0x7e1f (Phase 1f SC-province entries) whose dst is in
        # g_MoveList[own_power] (= state.g_convoy_dst_to_src, populated by
        # _build_order_mto), re-scores up to two candidates with pool-B scores
        # then restarts the outer loop from the beginning.
        #
        # pool-B initial score: ppiStack_7b4 = 0x7fff - (1 + inserted_count) * 4
        #   = 0x7ffb - 4 * inserted_count  (ppiStack_79c starts at 1 in C).
        # Two scoring ops per found candidate (fleet-prov sub-pass + dst sub-pass),
        # each decrementing fleet_pool_b by 1.
        #
        # C lookup key matching details:
        #   ppiStack_7bc (fleet/src prov) = g_MoveList node value [4] → army_src
        #     via state.g_convoy_dst_to_src[dst]; score check mirrors Phase 1g check.
        #   ppiStack_7c0 (dst prov) = *(candidate + 0x10) = candidate dst province.
        #   LAB_004516fb = advance (skip candidate, no restart).
        #   LAB_0045162d = second sub-pass (dst re-score, always reached).
        #   LAB_004516f1  = restart outer loop (ppiStack_790 = first element).
        if power_index == own_power:
            fleet_pool_b = 0x7ffb - 4 * inserted_count
            found = True
            while found:
                found = False
                for cand_score, dst in list(state.g_convoy_fleet_candidates):
                    if cand_score >= 0x7e1f:
                        # LAB_004516fb: score too high (Phase 1g/1h candidate) → advance
                        continue
                    # g_MoveList[own_power] lookup: is dst a target of own MTO?
                    army_src = state.g_convoy_dst_to_src.get(dst)
                    if army_src is None:
                        # LAB_004516fb: no own-power MTO targets this province → advance
                        continue
                    # First sub-pass (lines 1347–1375): optional — score army_src candidate
                    # if army_src passes the enemy-presence / SC-ownership gate.
                    # Mirrors: if (-1 < g_enemy_presence[power, fleet_prov]) and
                    #          (g_enemy_presence > 0 or g_sc_ownership != 0).
                    src_enemy = int(state.g_enemy_presence[power_index, army_src])
                    src_sc    = int(state.g_sc_ownership[power_index, army_src])
                    if src_enemy > 0 or (src_enemy >= 0 and src_sc != 0):
                        _remove_first_convoy_candidate(state, army_src)
                        state.g_sub_order_map.add(army_src)
                        fleet_pool_b -= 1
                        score_convoy_fleet(state, army_src, fleet_pool_b)
                    # LAB_0045162d: second sub-pass (lines 1378–1400) — always score dst.
                    _remove_first_convoy_candidate(state, dst)
                    fleet_pool_b -= 1
                    score_convoy_fleet(state, dst, fleet_pool_b)
                    # LAB_004516f1: restart outer loop from beginning.
                    found = True
                    break

        # 1g.5  Default-hold backfill ─────────────────────────────────────────
        # Units that pass through 1c–1g without acquiring an explicit order
        # default to HLD.  The C binary's resolver treats _F_ORDER_TYPE == 0
        # the same as HLD; we set it explicitly so evaluate_order_proposal sees
        # real candidates. Received press may populate g_general_orders and
        # make 1c produce explicit orders, but units that nothing touches still
        # need this seed before Phase 2's adjacency walk.
        for prov, unit in state.unit_info.items():
            if unit['power'] != power_index:
                continue
            if int(state.g_order_table[prov, _F_ORDER_TYPE]) == 0:
                _build_order_hld(prov)

        # Phase 2: Adjacency walk + post-processing ─────────────────────────
        # ProcessTurn.c lines 1411-2900.  For each unordered unit in
        # g_convoy_fleet_candidates, score reachable adjacencies, then apply
        # the full C post-processing pipeline before selecting a destination.
        #
        # Fix 2026-04-21 (MC-1): Full port of post-processing including:
        #   - Source-province dedup (lines 1950-1977)
        #   - Water-province score threshold (lines 1978-1986)
        #   - 3-slot ally-trust filtering (lines 1990-2068)
        #   - XDO press integration (lines 2086-2182) — own_power only
        #   - Fleet dedup (lines 2184-2234) — FLT units only
        #   - Target-flag filtering (lines 2235-2391)
        #   - Probabilistic final selection (lines 2392-2750)
        #     → BuildOrder_MTO / BuildConvoyOrders / BuildOrder_HLD
        _mc_dbg = (_trial == 0 and power_index == own_power
                   and _dbg_log.isEnabledFor(logging.DEBUG))
        if _mc_dbg:
            id2n = getattr(state, '_id_to_prov', {})
            _dbg_log.debug(
                "MC_DBG[p%d] trial=0  final_score_set nonzero: %s",
                power_index,
                [(id2n.get(p, str(p)), float(state.final_score_set[power_index, p]))
                 for p in range(256) if state.final_score_set[power_index, p] != 0],
            )
            _dbg_log.debug(
                "MC_DBG[p%d] Phase2 g_convoy_fleet_candidates=%s",
                power_index,
                [(s, id2n.get(p, str(p))) for s, p in state.g_convoy_fleet_candidates],
            )

        # HOLD-DBG: log state entering Phase 2 (trial 0, own power only).
        if _trial == 0 and power_index == own_power:
            _id2n = getattr(state, '_id_to_prov', {})
            _pnames = ['AUT', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']
            _pname = _pnames[power_index] if power_index < len(_pnames) else str(power_index)
            _fleet_cands_own = [
                (_id2n.get(p, str(p)), s)
                for s, p in state.g_convoy_fleet_candidates
                if state.unit_info.get(p, {}).get('power') == power_index
            ]
            _pre_p2_ots = {
                _id2n.get(p, str(p)): int(state.g_order_table[p, _F_ORDER_TYPE])
                for p, u in state.unit_info.items()
                if u.get('power') == power_index
            }
            _fss_nonzero = int(np.count_nonzero(state.final_score_set[power_index, :256]))
            logger.info(
                "HOLD_DBG[%s] entering Phase2: fleet_cands_own=%s  "
                "unit_ot_pre_phase2=%s  final_score_set_nonzero=%d",
                _pname, _fleet_cands_own, _pre_p2_ots, _fss_nonzero,
            )
        for _cand_score, cand_prov in list(state.g_convoy_fleet_candidates):
            unit = state.unit_info.get(cand_prov)
            if unit is None:
                continue
            if unit['power'] != power_index:
                continue

            # C:1440-1492 recomputes these fields for every candidate unit;
            # support builders can change proximity between iterations.
            _recompute_trial_support_demand(
                state, power_index, num_powers, num_provinces
            )

            # ProcessTurn.c:1508-1509 copies the selected province score pair
            # into order-table columns 8/9 before candidate construction.
            # EvaluateOrderScore later adds this pair unconditionally for each
            # unit, making it the primary per-order score channel.
            state.g_order_table[cand_prov, _F_SELECTED_SCORE_LO] = state.fss(
                power_index, cand_prov, unit['type']
            )
            state.g_order_table[cand_prov, _F_SELECTED_SCORE_HI] = 0.0

            # AdjacencyList_FilterByUnitType (C line 1517-1519)
            # Fleets use fleet_adj_matrix which only contains fleet-reachable
            # neighbours (built from uppercase abut_list entries).  This
            # correctly excludes land-only borders between coastal provinces
            # (e.g. ANK→SMY) that the old terrain-only filter missed.
            utype = unit['type']
            if utype in ('A', 'AMY'):
                raw_adj = state.adj_matrix.get(cand_prov, [])
                adj_list = [a for a in raw_adj if a not in state.water_provinces]
            elif utype in ('F', 'FLT'):
                adj_list = list(state.fleet_adj_matrix.get(cand_prov, []))
                # Fallback for coast-variant units stored at base province ID
                # (e.g. F STP/SC stored at STP base id=66 with coast='SC').
                if not adj_list:
                    _coast = unit.get('coast', '')
                    if _coast:
                        _coast_key = '/' + _coast.upper()
                        adj_list = list(
                            getattr(state, 'fleet_coast_adj', {}).get(
                                (cand_prov, _coast_key), []))
            else:
                adj_list = list(state.adj_matrix.get(cand_prov, []))

            if not adj_list:
                continue

            # 30% random gate (C line 1523: (rand()/0x17)%100 < 0x1e)
            r_gate = random.randint(0, 32767)
            scored_mode = (r_gate // 0x17) % 100 < 0x1e

            # ── Inner scoring loop: build candidate list ──────────────────
            # C accumulates into a BST (local_784); we use a sorted list of
            # (score_lo, score_hi, dest_prov) tuples to mirror the BST ordering.
            cand_list: list[tuple] = []  # [(score, dest_prov), ...]

            for adj_prov in adj_list:
                if scored_mode:
                    # C lines 1542-1558: three-level gate determines random
                    # vs deterministic scoring.
                    # Level 1 (C 1542-1544): g_enemy_presence[power, adj] > 0
                    #   → random 500+
                    # Level 2 (C 1548-1549): g_sc_ownership[power, adj] != 0
                    #   → deterministic (fall through to LAB_00451bb0)
                    # Level 3 (C 1553-1555): g_proximity_score[power, adj] > 0
                    #   → random 500+; else → deterministic
                    # Fixed 2026-04-28: was using wrong variables (g_own_reach_score
                    # instead of g_enemy_presence/g_proximity_score) and had the
                    # SC-ownership logic inverted — provinces with own units got
                    # random 500+ instead of deterministic, inflating owned-SC scores
                    # and causing units to move back to occupied SCs.
                    enemy_pres = int(state.g_enemy_presence[power_index, adj_prov])
                    sc = int(state.g_sc_ownership[power_index, adj_prov])
                    prox = float(state.g_proximity_score[power_index, adj_prov])
                    use_random = (enemy_pres > 0
                                  or (sc == 0 and prox > 0))
                    if use_random:
                        r2 = random.randint(0, 32767)
                        score = (r2 // 0x17) % 100 + 500
                    else:
                        # deterministic: enemy_pres <= 0 AND
                        #   (sc != 0 OR prox <= 0)
                        score = _candidate_tree_score(
                            state, power_index, adj_prov, utype
                        )
                else:
                    score = _candidate_tree_score(
                        state, power_index, adj_prov, utype
                    )
                    # (Own-SC penalty removed — scoring.py Pass 3c now
                    # applies the C-matching Adjustment 9 cap to
                    # final_score_set directly.)
                cand_list.append((score, adj_prov))

            # Post-loop: source unit's own entry (C lines 1632-1653).
            # Fixed 2026-04-28: was gated by `not scored_mode`, but C adds
            # the hold entry UNCONDITIONALLY after the adjacency loop.
            # Missing hold in scored_mode (30% of trials) forced units to
            # move away from unoccupied SCs instead of staying to capture.
            if adj_list:
                # After the C adjacency iterator reaches end, ppiVar24 is
                # reset to ppiStack_7b8 (the current unit record).  Therefore
                # DAT_00ba3b70 is indexed by the source province, not by the
                # first adjacency as the former Python port assumed.
                src_score = _candidate_tree_score(
                    state, power_index, cand_prov, utype
                )
                cand_list.append((src_score, cand_prov))

            # ProcessTurn C:1669 compares the current unit-type token with the
            # three-byte literal at PTR_DAT_004b13ac (AMY).  On equality its
            # C:1674-1940 BFS adds destinations reachable through 1-3 own
            # fleets, carrying the fleet legs in the per-destination route
            # struct.  This block follows the source/hold insertion in C, and
            # convoy landings use the OrderedSet score directly: unlike normal
            # adjacent army moves, DAT_00ba3b70 is not added here.
            if utype in ('A', 'AMY'):
                from ..moves.convoy import _populate_convoy_routes_for_src
                # The C BFS walks the live candidate tree, not every fleet on
                # the board.  Its iterator order also breaks ties between
                # same-depth routes.  Rebuild this source army's route record
                # now so final dispatch consumes the exact route that produced
                # the candidate destination.
                eligible_fleets = [
                    prov for _score, prov in state.g_convoy_fleet_candidates
                ]
                route_dests = _populate_convoy_routes_for_src(
                    state, cand_prov, eligible_fleets=eligible_fleets
                )
                if route_dests:
                    direct_dests = {int(candidate[1]) for candidate in cand_list}
                    for convoy_dest, _route in route_dests.items():
                        if convoy_dest in direct_dests:
                            continue
                        score = int(state.fss(
                            power_index, convoy_dest, utype
                        ))
                        cand_list.append((score, convoy_dest))

            if not cand_list:
                continue

            # Sort descending by score (C BST pops highest first)
            cand_list.sort(key=lambda x: x[0], reverse=True)

            if _mc_dbg:
                _pn = id2n.get(cand_prov, str(cand_prov))
                _dbg_log.debug(
                    "MC_DBG[GER] unit=%s@%-4s scored_mode=%s cands=%s",
                    utype, _pn, scored_mode,
                    [(f"{s:.0f}", id2n.get(d, str(d)))
                     for s, d in cand_list[:8]],
                )

            # ── Post-processing Step 1: source-province dedup (1950-1977) ─
            # C condition: (puVar10[1] != iStack_460) AND (cand_count > 1)
            #              AND (g_ProvinceBase[src] < 500)  → drop the
            # dest == src candidate, i.e. take away the hold option.
            #
            # Corrected 2026-08-12.  `&DAT_00bb6e00` is a std::map and
            # DAT_00bb6e04 is its _Myhead, i.e. end() — C:536-547 clears the
            # container through that pointer using the standard MSVC
            # tree-destroy + reset-header-to-self sequence, and C:1946 asserts
            # `*puVar10 == &DAT_00bb6e00` (container identity).  So
            # `puVar10[1] != iStack_460` means the find did NOT hit end(): the
            # source province is a MEMBER of that map.  It is not an SC-owner
            # comparison and DAT_00bb6e04 is not a power index; the previous
            # reading (2026-04-28) gated on g_sc_owner, which is unrelated.
            #
            # The map is populated by StdMap_FindOrInsert at C:1286/1372, the
            # two convoy-rescore passes — bound in Python as g_sub_order_map
            # (see the .add() calls beside score_convoy_fleet in Phase 1e/1g).
            cand_list = _apply_step1_source_dedup(
                state, cand_prov, cand_list
            )

            # ── Post-processing Step 2: score threshold (C:1978-1986) ─────
            # C: if the int64 pair DAT_005b98e8/ec[src] == 1 → threshold 0;
            # else threshold = final_score_set[power, src].  Used by the
            # target-flag filter in Step 6.
            #
            # Corrected 2026-08-12: DAT_005b98e8 is not a water-province
            # classification.  It is the per-province top-reach flag —
            # initialised to -1 by GenerateOrders.c:136, set to 0/1 by
            # ScoreOrderCandidates_AllPowers.c:512/580, and read the same way
            # by BuildSupportOpportunities.c:99.  Python binds it as
            # state.g_top_reach_flag (heuristics/scoring.py:318 writes it,
            # moves/support.py:74 reads it).  The old `cand_prov in
            # water_provinces` proxy was unrelated to it.
            #
            # C uses 0 where this used None; Step 6's guard tests
            # `threshold > 0`, so the two are equivalent there, but 0 is what C
            # actually stores.
            if int(state.g_top_reach_flag[cand_prov]) == 1:
                score_threshold = 0.0
            else:
                score_threshold = state.fss(power_index, cand_prov, utype)

            # ── Post-processing Step 3: trust/support scan (1990-2085) ─────
            # This updates the threshold and the per-trial support-opportunity
            # map.  It does not erase candidates; Step 6 owns target pruning.
            score_threshold = _apply_step3_support_filter(
                state,
                power_index,
                own_power,
                cand_prov,
                cand_list,
                score_threshold,
                reachable_provinces,
                num_powers,
            )

            # ── Post-processing Step 4: XDO press integration (2086-2182) ─
            # Only for own_power.  Step 4 reads the accepted-order containers
            # written at XDO.c:166/190, not the sender/global bookkeeping maps
            # written at XDO.c:90/91/155.
            cand_list = _apply_step4_xdo_constraint(
                state, power_index, own_power, cand_prov, cand_list
            )
            if not cand_list:
                continue

            # ── Post-processing Step 5: fleet dedup (2184-2234) ───────────
            # For FLT units, piStack_70c is a fresh temporary set.  It removes
            # duplicate destinations in this fleet's own candidate tree.
            if utype in ('F', 'FLT'):
                cand_list = _dedupe_step5_fleet_candidates(cand_list)

            # ── Post-processing Step 6: target-flag filter (2235-2391) ────
            cand_list = _apply_step6_target_filter(
                state, power_index, cand_prov, cand_list, score_threshold
            )

            # NOTE: the old "Step 6b self-bump filter" lived here.  It dropped
            # destinations occupied by a non-leaving own unit, and destinations
            # already claimed by another own mover.  Both are cases where C does
            # NOT drop the candidate — it emits SUP_HLD (C:2642) or SUP_MTO
            # (C:2896) instead.  Pre-filtering them turned every support
            # opportunity into "move somewhere else", which is why the port had
            # to synthesise supports afterwards by conscripting neighbours.
            # The emission tail below now handles both cases where C does.

            if not cand_list:
                continue

            # ── Post-processing Step 7: probabilistic final selection ─────
            # LAB_004531a8 (lines 2392-2750): pop best candidate, apply
            # score-ratio random gate, then dispatch.
            # C walks the BST from best to worst.  For each consecutive
            # pair (A=current, B=next) it computes:
            #   delta   = (A - B) * 5             [__allmul, line 2430]
            #   combined = delta + B               (= 5A - 4B, line 2433)
            #   divisor  = A + combined            (= 6A - 4B, line 2437)
            #   ratio    = (B * 100) / divisor     [__allmul/__alldiv, 2440-2442]
            #   if ratio <= rand(100) AND rand(100) > 20 → BREAK (keep A)
            # Otherwise advance: A ← B, fetch new B.
            # C line 2424: if score_cur == 0 (both lo/hi words) → ratio = 0.
            # Only overwrite HLD / unset orders — preserve Phase 1c MTO/SUP/CTO.
            # Hoisted out of the retry loop below: it concerns cand_prov, which
            # does not change between retries.
            cur_order = int(state.g_order_table[cand_prov, _F_ORDER_TYPE])
            if cur_order not in (0, _ORDER_HLD):
                continue

            # C wraps selection, gating and emission in a
            # `do { … } while (cStack_7c1 == '\0')` (C:2392-2905): whenever a
            # candidate is rejected, RemoveOrderCandidate drops it and the loop
            # re-runs the selection over what is left.  `remaining` is that
            # shrinking set; the port used to select once and give up, so a
            # rejection meant the unit held.
            remaining = list(cand_list)
            while remaining:
                selected_idx = 0  # start with best
                for i in range(len(remaining) - 1):
                    score_cur = remaining[i][0]       # A (current, higher)
                    score_nxt = remaining[i + 1][0]   # B (next, lower)
                    # C formula: ratio = B*100 / (6A - 4B)
                    if score_cur == 0:
                        ratio = 0
                    else:
                        diff_times_5 = (score_cur - score_nxt) * 5
                        combined = diff_times_5 + score_nxt       # 5A - 4B
                        divisor = score_cur + combined             # 6A - 4B
                        if divisor == 0:
                            ratio = 0
                        else:
                            ratio = int((score_nxt * 100) / divisor)
                    r1 = random.randrange(100)
                    if ratio <= r1:
                        r2 = random.randrange(100)
                        if r2 > 20:
                            break  # C: keep current candidate (line 2447)
                    # C: fall through → advance to next candidate (2448-2449)
                    selected_idx = i + 1
                selected_dest = remaining[selected_idx][1]

                # C:2475-2479 — dest == src → BuildOrder_HLD, unit done.  This
                # sits ahead of the trust gate in C, not after the dispatch.
                if selected_dest == cand_prov:
                    if _trial == 0 and power_index == own_power:
                        _id2n = getattr(state, '_id_to_prov', {})
                        _pnames = ['AUT', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']
                        _pname = _pnames[power_index] if power_index < len(_pnames) else str(power_index)
                        _top_cands = [(round(c[0], 1), _id2n.get(c[1], str(c[1])))
                                      for c in remaining[:5]]
                        logger.info(
                            "HOLD_DBG[%s] unit@%s SELF-SELECTED HOLD "
                            "(src scored highest)  top_cands=%s  filtered=%d→%d",
                            _pname,
                            _id2n.get(cand_prov, str(cand_prov)),
                            _top_cands,
                            len(adj_list),
                            len(cand_list),
                        )
                    _build_order_hld(cand_prov)
                    break

                # 3-slot trust re-check on selected destination (C 2496-2547)
                # This emission block intentionally differs from Step 3: it
                # evaluates C, B, A and applies A only if trust is still empty.
                trust_lo_final = 0
                trust_hi_final = 0
                emission_desig_slots = [
                    (state.g_ally_designation_c, state.g_ally_designation_c_hi),
                    (state.g_ally_designation_b, state.g_ally_designation_b_hi),
                    (state.g_ally_designation_a, state.g_ally_designation_a_hi),
                ]
                for arr_lo, arr_hi in emission_desig_slots:
                    slot_lo = int(arr_lo[selected_dest]) if selected_dest < 256 else -1
                    slot_hi = int(arr_hi[selected_dest]) if selected_dest < 256 else -1
                    if slot_hi < 0:
                        continue
                    if arr_lo is state.g_ally_designation_a and (trust_lo_final != 0 or trust_hi_final != 0):
                        continue
                    if 0 <= slot_lo < num_powers:
                        rel = int(state.g_relation_score[power_index, slot_lo]) if slot_lo < 7 else 0
                        if rel > 9 or power_index == own_power:
                            # C indexes the flat 21-stride g_AllyTrustScore as
                            # [power*0x15 + slot]; the Python array is 2D (7,7),
                            # so the equivalent is [power, slot].  The former
                            # `.flat[]` form indexed 49 elements with stride 21 —
                            # correct only for power 0, wrong cell for 1-2,
                            # IndexError for 3-6 (swallowed), leaving the gate
                            # inert for six powers.
                            trust_lo_final = int(state.g_ally_trust_score[power_index, slot_lo])
                            trust_hi_final = int(state.g_ally_trust_score_hi[power_index, slot_lo])

                # C:2543-2546: if selected_dest IS in ally-claimed territory
                # (found in reachable_provinces), override trust to (lo=3, hi=0)
                # → gate rejects.  Prior port incorrectly used "foreign unit at
                # dest", which blocked all attacks.
                if selected_dest in reachable_provinces:
                    trust_lo_final, trust_hi_final = 3, 0

                # Trust gate (C lines 2547-2574).  C control flow:
                #   branch A (not_early or desig_b_hi < 0) → LAB_004536b5
                #   branch B: mutual-trust test —
                #       mutual trust holds → goto LAB_004536b5 (same gate as A)
                #       mutual trust fails → falls into LAB_004536bf, no gate
                #   LAB_004536b5 (C:2549): low trust → LAB_004536bf, else REJECT
                #   LAB_004536bf (C:2574): g_ConvoyActiveFlag[dest] > 0 → REJECT
                not_early = (state.g_press_flag != 1) or (state.g_near_end_game_factor >= 2.0)
                desig_b_hi_sel = int(state.g_ally_designation_b_hi[selected_dest]) if selected_dest < 256 else -1
                # "Low trust" = no ally claims on this territory → safe to enter.
                low_trust = trust_hi_final < 1 and (trust_hi_final < 0 or trust_lo_final == 0)
                if not_early or desig_b_hi_sel < 0:
                    reaches_accept = low_trust
                else:
                    # Early-game mutual trust path
                    mutual_trust = False
                    desig_b_lo = int(state.g_ally_designation_b[selected_dest]) if selected_dest < 256 else -1
                    if 0 <= desig_b_lo < num_powers:
                        fwd_hi = int(state.g_ally_trust_score_hi[power_index, desig_b_lo])
                        fwd_lo = float(state.g_ally_trust_score[power_index, desig_b_lo])
                        if fwd_hi >= 0 and (fwd_hi > 0 or fwd_lo > 1):
                            rev_hi = int(state.g_ally_trust_score_hi[desig_b_lo, power_index])
                            rev_lo = float(state.g_ally_trust_score[desig_b_lo, power_index])
                            if rev_hi >= 0 and (rev_hi > 0 or rev_lo > 1):
                                mutual_trust = True
                    # No mutual trust → C skips the gate entirely and accepts.
                    reaches_accept = low_trust if mutual_trust else True

                # C:2574 — the only read of g_ConvoyActiveFlag in ProcessTurn.c,
                # and it REJECTS.  The flag is written by
                # BuildOrder_SUP_HLD/SUP_MTO on the supported province when the
                # supported unit is foreign, i.e. "we already committed support
                # here" → don't also move into it.
                accepted_final = reaches_accept and int(state.g_convoy_active_flag[selected_dest]) <= 0

                if _mc_dbg:
                    _pn = id2n.get(cand_prov, str(cand_prov))
                    _dn = id2n.get(selected_dest, str(selected_dest))
                    _dbg_log.debug(
                        "MC_DBG[GER] unit@%-4s → %-4s  accepted=%s  "
                        "trust_final=(%d,%d)",
                        _pn, _dn, accepted_final,
                        trust_lo_final, trust_hi_final,
                    )

                if not accepted_final:
                    # HOLD-DBG: log the trust-gate rejection.
                    if _trial == 0 and power_index == own_power:
                        _id2n = getattr(state, '_id_to_prov', {})
                        _pnames = ['AUT', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']
                        _pname = _pnames[power_index] if power_index < len(_pnames) else str(power_index)
                        _top_cands = [(round(c[0], 1), _id2n.get(c[1], str(c[1])))
                                      for c in remaining[:5]]
                        logger.info(
                            "HOLD_DBG[%s] unit@%s→%s TRUST-GATE REJECTED "
                            "(trust_final=lo=%d hi=%d  in_reachable=%s)  top_cands=%s",
                            _pname,
                            _id2n.get(cand_prov, str(cand_prov)),
                            _id2n.get(selected_dest, str(selected_dest)),
                            trust_lo_final, trust_hi_final,
                            selected_dest in reachable_provinces,
                            _top_cands,
                        )
                    remaining.pop(selected_idx)
                    continue

                # ── LAB_004536bf tail (C:2579-2694) ───────────────────────
                # Is the destination occupied by one of OUR units?
                # g_sc_ownership[p, x] == 1 means "power p has a unit at x"
                # (heuristics/scoring.py:477) — despite the name, it is unit
                # presence, not supply-centre ownership.
                emit_move, rejected = _resolve_own_occupied_destination(
                    state, power_index, cand_prov, selected_dest
                )

                if rejected:
                    remaining.pop(selected_idx)
                    continue

                # ── LAB_00453a2c (C:2696-2903) ────────────────────────────
                # Is another own unit already ordered into this destination?
                # g_convoy_dst_to_src is C's DAT_00bb65a0 move map.
                _mover = state.g_convoy_dst_to_src.get(selected_dest)
                if _mover == cand_prov:
                    # Defensive: a unit must never support its own move.  C
                    # cannot reach this (the map is cleared per trial and a unit
                    # that has emitted its MTO breaks out of the retry loop),
                    # but a stale entry here would emit an illegal order.
                    _mover = None
                if _mover is None:
                    # C:2702-2750 — nobody else is going there.
                    if emit_move:
                        state.g_order_table[cand_prov, _F_ORDER_TYPE] = 0.0
                        from ..moves.convoy import _get_convoy_route
                        fleet_count, _route = _get_convoy_route(
                            state, cand_prov, selected_dest
                        )
                        # A destination the army can already walk to is an
                        # ordinary MTO, never a convoy.  C reaches
                        # BuildConvoyOrders only for a destination recorded as a
                        # convoy LANDING by the ProcessTurn convoy BFS (the
                        # +0x210 == -5 / +0x214 depth markers, C:1739-1922);
                        # a province sitting in the unit's own adjacency list is
                        # dispatched by BuildOrder_MTO instead.  The port had no
                        # such test and preferred a convoy whenever any fleet
                        # chain happened to exist, emitting gratuitous orders
                        # like `A APU - NAP VIA` and `A BUL - CON VIA`.
                        #
                        # Measured 2026-08-24 (F1901M, 25 games, 7 powers,
                        # 550 orders): Albert emits ZERO adjacent-destination
                        # convoys in 18; the port emitted 11 of 45.  Adding this
                        # clause takes the port to 0 of 40 and moves every
                        # metric the right way -- per-unit 136->141/550,
                        # exact-set 2->3/175, neutral-SC 114->121/175.
                        route_available = (
                            fleet_count > 0
                            and selected_dest not in adj_list
                            and all(
                                int(state.g_order_table[fleet, _F_ORDER_TYPE])
                                in (0, _ORDER_HLD)
                                for fleet in _route
                            )
                        )
                        if route_available:
                            build_convoy_orders(
                                state, power_index, cand_prov, selected_dest, 0
                            )
                        elif fleet_count > 0 and selected_dest not in adj_list:
                            # Non-adjacent candidates exist only via convoy. If
                            # their fleet route was consumed by an earlier unit,
                            # C's inline route state can no longer select them.
                            # Remove this candidate and retry the next one.
                            state.g_order_table[cand_prov, _F_ORDER_TYPE] = float(
                                _ORDER_HLD
                            )
                            remaining.pop(selected_idx)
                            continue
                        else:
                            _build_order_mto(cand_prov, selected_dest, 0)
                    break
                # C:2757-2865 — a pending support assignment on this occupied
                # destination can be promoted to a completed convoy chain.  On
                # success C jumps past SUP_MTO emission to LAB_00453f34.
                if _apply_convoy_swap(
                    state,
                    power_index,
                    cand_prov,
                    selected_dest,
                ):
                    if emit_move:
                        state.g_order_table[cand_prov, _F_ORDER_TYPE] = 0.0
                        _build_order_mto(cand_prov, selected_dest, 0)
                    break
                # C:2873-2898 — support that mover instead of contesting the
                # province, provided it is not already over-supported.
                if (int(state.g_order_table[selected_dest, _F_INCOMING_MOVE])
                        <= int(state.g_support_demand[selected_dest])
                        and int(state.g_order_table[selected_dest, _F_ORDER_ASGN]) != 2):
                    # A convoy-only landing is a legal move candidate for an
                    # army, but that does not make the army adjacent enough to
                    # support somebody else's move there.  C's SUP_MTO builder
                    # is reached through a coast/type-filtered candidate node;
                    # Python's merged list also contains convoy-only nodes, so
                    # enforce the supporter-side move adjacency before using
                    # this branch.
                    _supporter = state.unit_info.get(cand_prov, {})
                    if not state.can_reach_by_type(
                        cand_prov,
                        selected_dest,
                        _supporter.get('type', 'A'),
                        _supporter.get('coast', ''),
                    ):
                        remaining.pop(selected_idx)
                        continue
                    state.g_order_table[cand_prov, _F_ORDER_TYPE] = 0.0
                    _source_build_order_sup_mto(
                        state, power_index, cand_prov, _mover,
                        selected_dest,
                    )
                    break
                # C:2901-2903 — otherwise drop this destination and retry.
                remaining.pop(selected_idx)

        # HOLD-DBG: summarize final unit orders after Phase 2 (trial 0 only).
        if _trial == 0 and power_index == own_power:
            _id2n = getattr(state, '_id_to_prov', {})
            _pnames = ['AUT', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']
            _pname = _pnames[power_index] if power_index < len(_pnames) else str(power_index)
            _fleet_provs = {p for _, p in state.g_convoy_fleet_candidates}
            _post_p2 = []
            for _pp, _uu in state.unit_info.items():
                if _uu.get('power') != power_index:
                    continue
                _ot = int(state.g_order_table[_pp, _F_ORDER_TYPE])
                _dst = int(state.g_order_table[_pp, _F_DEST_PROV]) if _ot not in (0, 1) else None
                _in_cands = _pp in _fleet_provs
                _post_p2.append((
                    _id2n.get(_pp, str(_pp)),
                    _ot,
                    _id2n.get(_dst, str(_dst)) if _dst is not None else '-',
                    'in_cands' if _in_cands else 'NOT_IN_CANDS',
                ))
            logger.info(
                "HOLD_DBG[%s] after Phase2: unit_orders=%s",
                _pname, _post_p2,
            )

        # 1h. Target-bonus scoring ────────────────────────────────────────────
        # Pass 1: MTO/CTO toward target-flagged provinces (+150 or +75).
        # Pass 2: RTO / unit-presence check (lines 2909–2940 in decompile).
        # Pass 3: SUP_MTO toward SC-gaining flag (+50, lines 2958–3032).
        for prov, unit in state.unit_info.items():
            if unit['power'] != power_index:
                continue
            order_type = int(state.g_order_table[prov, _F_ORDER_TYPE])
            press_active = (state.g_press_flag == 1)   # C: DAT_00baed68 == '\x01'

            # C tests g_TargetFlag (0x5e40e8, hi word DAT_005e40ec) here — a
            # DIFFERENT array from g_ProvTargetFlag (0x5ee8e8), which this same
            # function uses at decompile line 3717.  g_TargetFlag is bound as
            # state.g_target_flag (written by SnapshotProvinceState with 1/2);
            # g_prov_target_flag is ScoreProvinces' classification.
            # Corrected 2026-08-12: both sites read g_prov_target_flag.
            if order_type in (_ORDER_MTO, _ORDER_CTO):
                dest = int(state.g_order_table[prov, _F_DEST_PROV])
                tflag = int(state.g_target_flag[power_index, dest])
                if tflag == 2:
                    state.g_early_game_bonus += 150 if press_active else 75

            elif order_type == _ORDER_SUP_MTO:
                # C (decompile 3021-3027) uses TWO different node offsets:
                #   node+0x2c = the supported unit's province  → _F_SECONDARY
                #   node+0x30 = that unit's destination        → _F_DEST_PROV
                # The SC gate is on +0x2c; only the target-flag test is on
                # +0x30.  Corrected 2026-08-12: both read _F_DEST_PROV.
                supported = int(state.g_order_table[prov, _F_SECONDARY])
                dest = int(state.g_order_table[prov, _F_DEST_PROV])
                # C's second operand is DAT_00520cec — the HI word of
                # g_SCOwnership, i.e. the pair is one int64 == 0 test, not a
                # separate enemy-presence check (0x4f6ce8).
                sc_at_supported = int(state.g_sc_ownership[power_index, supported])
                if sc_at_supported == 0:
                    tflag_dest = int(state.g_target_flag[power_index, dest])
                    if (tflag_dest == 2) or (press_active and state.g_history_counter == 0):
                        state.g_early_game_bonus += 50

        # 1h.5  Post-Phase-2 HLD→SUP sweep (C lines 3033–3640) ─────────────
        # Runs after ALL MTOs are finalised (distinct from Phase 2's inline
        # scan at C 1784–1808 which fires per-MTO-assignment).  Iterates
        # own-power HLD units. C makes two passes and considers both a
        # destination in the move map (SUP_MTO, incoming <= demand) and an own
        # occupied non-moving destination (SUP_HLD, incoming < demand). The
        # second pass also admits a positive total-reach marker.
        #
        # In the move-map branch C skips only when
        # DAT_00baeddc[adj] < g_ProvinceBaseScore[adj], so equality is
        # eligible.  The second pass can override that skip through the
        # positive DAT_0052b4e8/ec marker.
        _apply_post_phase_support_sweep(state, power_index)

        # C:3641-3693 refreshes the live aggregates after both support passes.
        _recompute_trial_support_demand(
            state, power_index, num_powers, num_provinces
        )

        # ProcessTurn.c:3695-3746 consumes the Step-3 ScoreSupportOpp map and
        # rolls qualifying own-unit opportunities into candidate field 12.
        _accumulate_other_score(state, power_index, own_power)

        # Every own unit must reach EvaluateOrderProposal with a serializable
        # order.  Several C retry branches clear a staging order before either
        # rebuilding it or falling through to BuildOrder_HLD; Python's
        # collapsed table can otherwise retain zero after a rejected convoy.
        for prov, unit in state.unit_info.items():
            if (unit.get('power') == power_index
                    and int(state.g_order_table[prov, _F_ORDER_TYPE]) == 0):
                _build_order_hld(prov)

        # 1i. Evaluate order proposal for this power (once per trial). ─────────
        # Mirrors: EvaluateOrderProposal(param_1_00, power_index) at decompile line 3747.
        evaluate_order_proposal(state, power_index, trial_idx=_trial)

        # 1b'-post. Default-HOLD seed for unassigned own units ────────────────
        # H2 fix: In C, EvaluateOrderProposal skips units with order_type==0.
        # After evaluation, seed HLD for any own units that still have no
        # order so that the submission pipeline has a valid order for every
        # unit.  Dispatch passes (1c-1h) already wrote non-zero order types
        # for units with movement/support/convoy orders; only truly idle
        # units remain at 0 here.
        for prov, unit in state.unit_info.items():
            if unit['power'] == power_index:
                if int(state.g_order_table[prov, _F_ORDER_TYPE]) == 0:
                    _build_order_hld(prov)


# ── UpdateScoreState ──────────────────────────────────────────────────────────

def _build_alliance_candidate_batches(
    state: InnerGameState,
    power: int,
    candidate_records: list[dict],
    ordered_slot_groups: tuple,
    num_powers: int,
    num_provinces: int,
    water_provs: set,
) -> tuple[np.ndarray, np.ndarray, np.ndarray, np.ndarray,
           np.ndarray, np.ndarray]:
    """Build UpdateAllyOrderScore's candidate-varying inputs in batches.

    The scalar C loop materializes one staging order table per candidate and
    selected-slot group.  Candidate own-unit sources and selected ally-unit
    sources are disjoint, so Python can form the same unions with a leading
    candidate axis, then propagate pressure/key contributions per unit across
    all candidates at once.
    """
    candidate_count = len(candidate_records)
    shape = (candidate_count, num_powers, num_provinces)
    key_weight = np.zeros(shape, dtype=np.int32)
    key_weight_flt = np.zeros(shape, dtype=np.int32)
    mc_pressure = np.zeros(shape, dtype=np.int32)
    mc_fleet_pressure = np.zeros(shape, dtype=np.int32)

    candidate_type = np.zeros(
        (candidate_count, num_provinces), dtype=np.int16
    )
    candidate_dest = np.zeros_like(candidate_type)
    for index, candidate in enumerate(candidate_records):
        for entry in candidate.get('orders', []):
            if not isinstance(entry, (list, tuple)) or len(entry) < 3:
                continue
            province = int(entry[0])
            if not 0 <= province < num_provinces:
                continue
            candidate_type[index, province] = int(entry[1])
            candidate_dest[index, province] = int(entry[2])

    all_indices = np.arange(candidate_count, dtype=np.intp)
    final_order_type = candidate_type.copy()
    final_order_dest = candidate_dest.copy()
    support_types = (_ORDER_SUP_HLD, _ORDER_SUP_MTO, _ORDER_CVY)

    for _slot_score, slot, group_weight in ordered_slot_groups:
        ally_type = np.zeros(num_provinces, dtype=np.int16)
        ally_dest = np.zeros(num_provinces, dtype=np.int16)
        for ally_power in range(num_powers):
            if ally_power == power or int(state.sc_count[ally_power]) <= 0:
                continue
            slot_list = state.g_current_best_order.get(ally_power, [])
            if slot >= len(slot_list):
                continue
            for entry in slot_list[slot]:
                if not isinstance(entry, (list, tuple)) or len(entry) < 3:
                    continue
                province = int(entry[0])
                order_type = int(entry[1])
                if (not 0 <= province < num_provinces
                        or order_type <= 0 or ally_type[province] != 0):
                    continue
                ally_type[province] = order_type
                ally_dest[province] = int(entry[2])

        ally_sources = ally_type != 0
        order_type = candidate_type.copy()
        order_dest = candidate_dest.copy()
        order_type[:, ally_sources] = ally_type[ally_sources]
        order_dest[:, ally_sources] = ally_dest[ally_sources]
        final_order_type = order_type
        final_order_dest = order_dest

        pressure_own = np.zeros(
            (candidate_count, num_provinces), dtype=np.int16
        )
        pressure_adj = np.zeros_like(pressure_own)
        fleet_expansion: dict[int, np.ndarray] = {}

        # Phase (f): staging order table -> own/adjacent pressure.
        for province, unit in state.unit_info.items():
            province = int(province)
            if not 0 <= province < num_provinces:
                continue
            types = order_type[:, province]
            active = types != 0
            if not np.any(active):
                continue
            committed = np.isin(types, support_types)
            committed_indices = all_indices[committed]
            committed_dest = order_dest[committed, province].astype(
                np.intp, copy=False
            )
            valid = (
                (committed_dest >= 0) & (committed_dest < num_provinces)
            )
            if np.any(valid):
                np.add.at(
                    pressure_own,
                    (committed_indices[valid], committed_dest[valid]),
                    1,
                )

            ordinary = active & ~committed
            if unit.get('type', 'A') in ('F', 'FLT'):
                for adjacent in _live_unit_adjacencies(
                    state, province, unit,
                ):
                    adjacent = int(adjacent)
                    if 0 <= adjacent < num_provinces:
                        pressure_adj[ordinary, adjacent] += 1
            else:
                pressure_own[ordinary, province] += 1

        # Phase (f2): first viable generated destination for each fleet.
        for province, unit in state.unit_info.items():
            province = int(province)
            if (unit.get('type', 'A') not in ('F', 'FLT')
                    or not 0 <= province < num_provinces):
                continue
            active = order_type[:, province] != 0
            expansion = np.full(candidate_count, -1, dtype=np.int16)
            for adjacent in _live_unit_adjacencies(
                state, province, unit,
            ):
                adjacent = int(adjacent)
                if adjacent == 0 or not 0 <= adjacent < num_provinces:
                    continue
                choose = (
                    active & (expansion < 0)
                    & (pressure_own[:, adjacent] == 0)
                    & (pressure_adj[:, adjacent] < 2)
                )
                expansion[choose] = adjacent
            fleet_expansion[province] = expansion

        # Phases (g/g2): derive sparse token keys and propagate each key's
        # weighted province/adjacency contribution.  Per-unit additions are
        # equivalent to C's grouped map additions because all values are ints.
        for province, unit in state.unit_info.items():
            province = int(province)
            unit_power = int(unit.get('power', -1))
            if (not 0 <= province < num_provinces
                    or not 0 <= unit_power < num_powers
                    or int(state.sc_count[unit_power]) <= 0):
                continue
            types = order_type[:, province]
            active = types != 0
            if not np.any(active):
                continue
            unit_type = unit.get('type', 'A')
            committed = np.isin(types, support_types)
            keys = np.full(candidate_count, -1, dtype=np.int16)
            keys[committed] = order_dest[committed, province]
            if unit_type in ('F', 'FLT'):
                ordinary = active & ~committed
                expansion = fleet_expansion.get(province)
                if expansion is not None:
                    keys[ordinary] = expansion[ordinary]
                key_table = key_weight_flt
                adjacency_table = state.fleet_adj_matrix
            else:
                keys[active & ~committed] = province
                key_table = key_weight
                adjacency_table = state.adj_matrix

            valid_key = active & (keys >= 0) & (keys < num_provinces)
            if not np.any(valid_key):
                continue
            valid_indices = all_indices[valid_key]
            valid_keys = keys[valid_key].astype(np.intp, copy=False)
            np.add.at(
                key_table,
                (valid_indices, unit_power, valid_keys),
                group_weight,
            )
            np.add.at(
                mc_pressure,
                (valid_indices, unit_power, valid_keys),
                group_weight,
            )

            for key in np.unique(valid_keys):
                key = int(key)
                key_indices = all_indices[valid_key & (keys == key)]
                controller = int(state.g_sc_owner[key])
                target = (
                    mc_fleet_pressure
                    if key in state.sc_provinces and controller != unit_power
                    else mc_pressure
                )
                adjacencies = adjacency_table.get(key, [])
                if unit_type not in ('F', 'FLT'):
                    adjacencies = [
                        adjacent for adjacent in adjacencies
                        if adjacent not in water_provs
                    ]
                for adjacent in sorted(set(adjacencies)):
                    adjacent = int(adjacent)
                    if 0 <= adjacent < num_provinces:
                        target[key_indices, unit_power, adjacent] += group_weight

    if candidate_count:
        state.g_key_weight[:] = key_weight[-1]
        state.g_key_weight_flt[:] = key_weight_flt[-1]
        state.g_mc_province_pressure[:] = mc_pressure[-1]
        state.g_mc_fleet_pressure[:] = mc_fleet_pressure[-1]
        state.g_order_table[:, _F_ORDER_TYPE] = final_order_type[-1]
        state.g_order_table[:, _F_DEST_PROV] = final_order_dest[-1]
        state.g_order_table[:, _F_DEST_COAST] = 0.0
        state.g_order_table[:, _F_SECONDARY] = 0.0

    return (
        key_weight,
        key_weight_flt,
        mc_pressure,
        mc_fleet_pressure,
        final_order_type,
        final_order_dest,
    )

def _update_ally_order_score(state: InnerGameState, power: int) -> None:
    """
    Port of UpdateAllyOrderScore (FUN_00442770).
    Pass 1 sub-function of UpdateScoreState.

    C algorithm (1107 lines):
      Outer loop: iterate g_CandidateRecordList for entries where candidate.power == param_1.
      For each non-skipped candidate:
        (b)  Clear g_mc_province_pressure / g_mc_fleet_pressure and staging area.
        (c)  Compute round count local_b08 = min(trial_counter+4, 30).
             C groups those slots in a map keyed by the sum of each selected
             candidate's heat_scores[power] across all powers.  Each map node
             stores the first slot with that key and a multiplicity count.
        BST walk — one pass per distinct key, in ascending-key order:
             Ally orders come from the representative slot, own orders come
             from this candidate, and pressure accumulation is weighted by the
             key's multiplicity.
          (e) For each ally power ≠ current with sc_count > 0, copy
              g_bbf694[ally*30+0].order_list into staging via FindOrInsert.
          (d) Insert candidate's own orders via FindOrInsert.
          (f) Recompute pressure_own/pressure_adj from full accumulated staging set.
          (g) Accumulate g_mc_province_pressure with weight = local_b08.
        (h)  Call EvaluateAllianceScore (once per candidate).
        (i)  Store result in candidate['alliance_score'] / ['alliance_score_avg'].
    """
    if getattr(state, 'g_candidate_record_list', None) is None:
        return

    num_provinces = 256
    num_powers = len(state.g_unit_count)
    # DAT_0062cc64 is BuildAndSendSUB's current proposal-trial counter.  It is
    # unrelated to g_HistoryCounter (the DAIDE press level); conflating them
    # made full-press games evaluate 30 slots on their first trial instead of
    # C's four.
    trial_counter = int(getattr(state, 'g_n_trials_completed', 0))
    local_b08 = min(trial_counter + 4, 30) if trial_counter < 8 else 30
    water_provs = getattr(state, 'water_provinces', set())

    from ..heuristics import evaluate_alliance_score

    candidate_by_key = state.__dict__.get('_candidate_key_map')
    if (not isinstance(candidate_by_key, dict)
            or len(candidate_by_key) != len(state.g_candidate_record_list)):
        candidate_by_key = {
            candidate_record_key(rec): rec
            for rec in state.g_candidate_record_list
        }
        state.__dict__['_candidate_key_map'] = candidate_by_key

    # C reconstructs this score-group tree inside every candidate iteration,
    # but every input comes from the selected per-power slots and ``power``;
    # the candidate currently being rescored is not consulted.  Build the
    # mathematically identical groups once per power/round.  This preserves
    # tree-key ordering, representative slots, multiplicities, and all score
    # accumulator increments below while avoiding hundreds of thousands of
    # repeated selected-record lookups.
    slot_groups: dict[int, list[int]] = {}
    for slot in range(local_b08):
        slot_score = 0
        for selected_power in range(num_powers):
            selected_records = state.g_current_best_order_records.get(
                selected_power, [])
            if slot < len(selected_records):
                selected_record = selected_records[slot]
            else:
                selected_slots = state.g_current_best_order.get(
                    selected_power, [])
                if slot >= len(selected_slots):
                    continue
                selected_orders = selected_slots[slot]
                selected_key = candidate_orders_key(
                    selected_power, selected_orders)
                selected_record = candidate_by_key.get(selected_key)
            if selected_record is None:
                continue
            heat_scores = selected_record.get('heat_scores', [])
            if power < len(heat_scores):
                slot_score += int(heat_scores[power])
        if slot_score in slot_groups:
            slot_groups[slot_score][1] += 1
        else:
            slot_groups[slot_score] = [slot, 1]
    ordered_slot_groups = tuple(
        (score, slot, group_weight)
        for score, (slot, group_weight) in sorted(slot_groups.items())
    )
    duplicate_group_count = sum(
        group_weight - 1
        for _, _, group_weight in ordered_slot_groups
    )
    # Reused group-local staging arrays.  C allocates these fixed buffers once
    # in the function stack frame and clears them for each group; doing the
    # same avoids allocating two 256-element NumPy arrays per group/candidate.
    pressure_own = np.zeros(num_provinces, dtype=np.int32)
    pressure_adj = np.zeros(num_provinces, dtype=np.int32)
    candidate_records = [
        candidate for candidate in state.g_candidate_record_list
        if candidate.get('power') == power
        and not candidate.get('skip_flag', False)
    ]
    candidate_count = len(candidate_records)

    if candidate_count > 1:
        state.g_score_alt += local_b08 * candidate_count
        state.g_score_group_duplicates += (
            duplicate_group_count * candidate_count
        )
        (
            batch_key_weight,
            batch_key_weight_flt,
            batch_mc_pressure,
            batch_mc_fleet_pressure,
            batch_order_type,
            batch_order_dest,
        ) = _build_alliance_candidate_batches(
            state,
            power,
            candidate_records,
            ordered_slot_groups,
            num_powers,
            num_provinces,
            water_provs,
        )
        from ..heuristics import evaluate_alliance_scores_batch
        alliance_deltas = evaluate_alliance_scores_batch(
            state,
            power,
            local_b08,
            batch_key_weight,
            batch_key_weight_flt,
            batch_mc_pressure,
            batch_mc_fleet_pressure,
            batch_order_type,
            batch_order_dest,
            ring_convoy_scores=np.asarray([
                int(candidate.get('ring_convoy_score', 0))
                for candidate in candidate_records
            ], dtype=np.int64),
            early_game_bonuses=np.asarray([
                int(candidate.get('early_game_bonus', 0))
                for candidate in candidate_records
            ], dtype=np.int64),
            rank_penalties=np.asarray([
                int(candidate.get('rank_penalty', 0))
                for candidate in candidate_records
            ], dtype=np.int64),
            other_scores=np.asarray([
                int(candidate.get('other_score', 0))
                for candidate in candidate_records
            ], dtype=np.int64),
            conviction_bonuses=np.asarray([
                int(candidate.get('conviction_bonus', 0))
                for candidate in candidate_records
            ], dtype=np.int64),
            previous_maximum_bases=np.asarray([
                int(candidate.get('alliance_maximum_base', 0))
                for candidate in candidate_records
            ], dtype=np.int64),
        )
        maximum_bases = np.asarray(
            getattr(
                state,
                'g_last_alliance_maximum_bases',
                np.zeros(candidate_count, dtype=np.int64),
            ),
            dtype=np.int64,
        )
        for candidate, alliance_delta, maximum_base in zip(
                candidate_records, alliance_deltas, maximum_bases):
            candidate['alliance_maximum_base'] = int(maximum_base)
            new_score = int(candidate.get(
                'base_score', candidate.get('score', 0)
            )) + int(alliance_delta)
            old_score = int(candidate.get('score', 0))
            avg_score = (
                old_score // 2 + new_score // 2
                if trial_counter > 0 else new_score
            )
            candidate['alliance_score'] = new_score
            candidate['alliance_score_avg'] = avg_score
            candidate['round_count'] = trial_counter
            candidate.setdefault('base_score', candidate.get('score', 0))
            candidate['score'] = new_score
            trial_scores = candidate.setdefault('trial_scores', [])
            while len(trial_scores) <= trial_counter:
                trial_scores.append(0)
            trial_scores[trial_counter] = new_score
            candidate['final_dim_score'] = avg_score

        from ..bot.analysis import _rank_candidates_for_power
        _rank_candidates_for_power(state, power, flag=1)
        return

    batch_key_weight = np.empty(
        (candidate_count, num_powers, num_provinces), dtype=np.int32
    )
    batch_key_weight_flt = np.empty_like(batch_key_weight)
    batch_mc_pressure = np.empty_like(batch_key_weight)
    batch_mc_fleet_pressure = np.empty_like(batch_key_weight)
    batch_order_type = np.empty(
        (candidate_count, num_provinces), dtype=np.int16
    )
    batch_order_dest = np.empty_like(batch_order_type)

    for batch_index, c in enumerate(candidate_records):

        # ── Phase (b): clear MC pressure arrays ──────────────────────────────
        # C: lines 150–200 — clear g_baed7c record[0x1a+p] and DAT_00b9a980/b95580
        state.g_mc_province_pressure.fill(0)
        state.g_mc_fleet_pressure.fill(0)
        state.g_key_weight.fill(0)
        state.g_key_weight_flt.fill(0)

        # Clear staging area for this candidate.
        # C: the staging OrderedSet (+0x2450) is rebuilt empty for each candidate.
        state.g_order_table[:, _F_ORDER_TYPE] = 0.0
        state.g_order_table[:, _F_DEST_PROV] = 0.0
        state.g_order_table[:, _F_DEST_COAST] = 0.0
        state.g_order_table[:, _F_SECONDARY] = 0.0

        # UpdateAllyOrderScore.c:265/282. The first accumulator counts every
        # selected slot examined for every candidate; the second counts only
        # duplicates collapsed into an existing score-key group.
        state.g_score_alt += local_b08
        state.g_score_group_duplicates += duplicate_group_count

        for _slot_score, r, group_weight in ordered_slot_groups:
            # Per-group delta records.  DAT_00baed7c retains the cumulative
            # candidate weights, while the global pressure arrays receive this
            # group's contribution exactly once.
            group_key_weight: dict[tuple[int, int], int] = {}
            group_key_weight_flt: dict[tuple[int, int], int] = {}

            def _add_record_weight(unit_power: int, province: int,
                                   unit_type: str) -> None:
                if not (0 <= unit_power < num_powers
                        and 0 <= province < num_provinces):
                    return
                state.add_key_weight(
                    unit_power, province, group_weight, unit_type
                )
                table = (group_key_weight_flt
                         if unit_type in ('F', 'FLT')
                         else group_key_weight)
                key = (unit_power, province)
                table[key] = table.get(key, 0) + group_weight
            # ── Phase (e): ally orders for slot r (FindOrInsert) ─────────────
            # C: lines 293–462 — for each ally_power with sc_count > 0, walk
            # g_bbf694[ally*30+r].order_list, insert each entry via FindOrInsert.
            # Ally orders go first; own orders cannot overwrite them.
            for ally_power in range(num_powers):
                if ally_power == power or int(state.sc_count[ally_power]) <= 0:
                    continue
                slot_list = state.g_current_best_order.get(ally_power, [])
                if r >= len(slot_list):
                    continue
                slot_orders = slot_list[r]
                if not isinstance(slot_orders, (list, tuple)):
                    continue
                # Each DAT_00bbf690/694 slot points to one complete candidate
                # record and its full order list.  The previous port treated a
                # slot as one unit order, losing the rest of the ally's set.
                for ao in slot_orders:
                    if not isinstance(ao, (list, tuple)) or len(ao) < 2:
                        continue
                    ap, aot = int(ao[0]), int(ao[1])
                    if ap < 0 or ap >= num_provinces or aot <= 0:
                        continue
                    if int(state.g_order_table[ap, _F_ORDER_TYPE]) != 0:
                        continue
                    restore_order_entry(state.g_order_table, ao)

            # ── Phase (d): own orders for slot r (FindOrInsert) ──────────────
            # C: lines 464–604 — walk candidate's own order list, insert via
            # OrderedSet_FindOrInsert.  Own orders cannot overwrite ally entries.
            for order_entry in c.get('orders', []):
                if not isinstance(order_entry, (list, tuple)) or len(order_entry) < 2:
                    continue
                prov = int(order_entry[0])
                if prov < 0 or prov >= num_provinces:
                    continue
                if int(state.g_order_table[prov, _F_ORDER_TYPE]) != 0:
                    continue
                # Candidate snapshots use the same semantic five-field layout
                # for every order type: source, type, destination, coast,
                # secondary unit.  Reuse the canonical reconstruction so SUP
                # destinations are neither overwritten by the secondary field
                # nor silently left at province zero.
                restore_order_entry(state.g_order_table, order_entry)

            # ── Phase (f): pressure arrays from staging ───────────────────────
            # C: lines 607–785 — three flag branches per staging node:
            #   flag 0x6b (committed support/convoy): pressure_own[staging.dest_prov]
            #   flag 0x6a (fleet MTO):                pressure_adj[each fleet adj] (dedup)
            #   else (non-fleet ordered unit):         pressure_own[unit.prov]
            # Both arrays feed the fleet-expansion gate in Phase (f2).
            pressure_own.fill(0)  # apiStack_a40
            pressure_adj.fill(0)  # apiStack_640

            for prov, unit in state.unit_info.items():
                order_type = int(state.g_order_table[prov, _F_ORDER_TYPE])
                if order_type == 0:
                    continue
                utype = unit.get('type', 'A')

                if order_type in (_ORDER_SUP_HLD, _ORDER_SUP_MTO, _ORDER_CVY):
                    # flag 0x6b: committed order — marks staging.dest_prov
                    dest = int(state.g_order_table[prov, _F_DEST_PROV])
                    if 0 <= dest < num_provinces:
                        pressure_own[dest] += 1
                elif utype in ('F', 'FLT'):
                    # flag 0x6a: FLEET — adjacency pressure (deduplicated).
                    #
                    # 2026-08-27: the `and order_type == _ORDER_MTO` half of
                    # this test was dropped.  Record flag +0x6a is not written
                    # in any recovered source, so its meaning is inferred from
                    # its readers.  PostProcessOrders.c:62-84 bumps
                    # g_MoveHistoryMatrix[power][src][dst] on
                    # `+0x69 == 1 && +0x6a == 0` and clears the whole [src] row
                    # on `+0x6a == 1` (:114-125).  Reading +0x6a as "this unit
                    # is a FLEET" makes both consistent — armies accumulate
                    # move history, fleets do not.  Reading it as "fleet AND
                    # MTO" does not: a moving fleet would then never record a
                    # move and would erase its own history instead.
                    #
                    # The narrow reading also made this function structurally
                    # blind to holding fleets: they fell through to the
                    # own-province branch below and claimed their own key,
                    # while moving fleets got an adjacency key or none at all.
                    # Measured on F1901M FRANCE, that asymmetry was worth
                    # ~11,900 alliance points in favour of `F MAO H` over every
                    # `F MAO - x` — against a spread of ~1,200 between the
                    # destinations themselves, so the fleet never moved.
                    last_seen = -1
                    for adj in _live_unit_adjacencies(state, prov, unit):
                        if adj != last_seen and adj < num_provinces:
                            pressure_adj[adj] += 1
                            last_seen = adj
                else:
                    # else: non-fleet ordered unit — marks own province as occupied
                    pressure_own[prov] += 1

            # ── Phase (f2): fleet expansion pass ─────────────────────────────
            # C: lines 802–877 — for each +0x6a unit (a FLEET, whatever its
            # order — see Phase (f)), check fleet adjacencies.
            # A unit earns ally-record credit (Phase g) only if ≥1 adjacent province
            # satisfies all three gates:
            #   pressure_own[adj] == 0   (not occupied / targeted by another order)
            #   pressure_adj[adj] < 2    (fewer than 2 fleets already adjacent)
            #   adj != 0                 (C: adj != staging+0x60, zero-initialised)
            fleet_expansion_dest: dict[int, int] = {}

            for prov, unit in state.unit_info.items():
                # Any ordered fleet takes C's +0x6a path (see Phase (f)).
                if int(state.g_order_table[prov, _F_ORDER_TYPE]) == 0:
                    continue
                if unit.get('type', 'A') not in ('F', 'FLT'):
                    continue
                for adj in _live_unit_adjacencies(state, prov, unit):
                    if adj == 0:
                        continue
                    if pressure_own[adj] != 0:
                        continue
                    if pressure_adj[adj] >= 2:
                        continue
                    fleet_expansion_dest[prov] = adj
                    break

            # ── Phase (g): write DAT_00baed7c key weights ───────────────────
            # UpdateAllyOrderScore.c:628/724/883 selects a token key, then
            # adds the score-group multiplicity (node field 4) to that key's
            # record[unit.power + 0x15].  Ally-record weight is 0 for:
            #   • unordered units (flag never set in Phase f)
            #   • fleet MTO units with no expansion opportunity (Phase f2 absent)
            for prov, unit in state.unit_info.items():
                unit_power = unit.get('power', -1)
                if unit_power < 0 or int(state.sc_count[unit_power]) <= 0:
                    continue
                order_type = int(state.g_order_table[prov, _F_ORDER_TYPE])
                if order_type == 0:
                    continue
                utype = unit.get('type', 'A')
                if order_type in (_ORDER_SUP_HLD, _ORDER_SUP_MTO, _ORDER_CVY):
                    # flag 0x6b: key at staging+0x24 (destination key).
                    dest = int(state.g_order_table[prov, _F_DEST_PROV])
                    _add_record_weight(unit_power, dest, utype)
                    continue

                # flag 0x6a: the first viable generated fleet order spec
                # supplies its destination key at UpdateAllyOrderScore.c:883.
                if utype in ('F', 'FLT'):
                    dest = fleet_expansion_dest.get(prov)
                    if dest is None:
                        continue
                    _add_record_weight(unit_power, dest, 'F')
                    continue

                # Default ordered-unit branch: source unit key.
                _add_record_weight(unit_power, prov, utype)

            # ── Phase (g2): records → MC pressure arrays ────────────────────
            # C:896-1034. Every positive key weight contributes at its own
            # province, then across type-filtered adjacency. On an SC controlled
            # by a different/neutral power, adjacency goes to the secondary
            # fleet-pressure table; otherwise it stays in province pressure.
            for key_type, sparse_weights in (
                    ('A', group_key_weight), ('F', group_key_weight_flt)):
                # The dense implementation walked power then province in
                # ascending order.  Sorting sparse keys retains that order,
                # although all writes are commutative integer additions.
                for (unit_power, prov), weight in sorted(
                        sparse_weights.items()):
                    state.g_mc_province_pressure[unit_power, prov] += weight

                    use_fleet_pressure = (
                        int(prov) in state.sc_provinces
                        and int(state.g_sc_owner[int(prov)]) != unit_power
                    )

                    if key_type == 'F':
                        adj_list = state.fleet_adj_matrix.get(int(prov), [])
                    else:
                        adj_list = [
                            adj for adj in state.adj_matrix.get(int(prov), [])
                            if adj not in water_provs
                        ]
                    target = (state.g_mc_fleet_pressure
                              if use_fleet_pressure
                              else state.g_mc_province_pressure)
                    for adj in sorted(set(adj_list)):
                        target[unit_power, adj] += weight

        # Snapshot only the candidate-varying evaluator inputs.  C calls the
        # scalar evaluator here; the Python batch below preserves this record
        # order while evaluating the fixed board dimensions in one NumPy pass.
        batch_key_weight[batch_index] = state.g_key_weight
        batch_key_weight_flt[batch_index] = state.g_key_weight_flt
        batch_mc_pressure[batch_index] = state.g_mc_province_pressure
        batch_mc_fleet_pressure[batch_index] = state.g_mc_fleet_pressure
        batch_order_type[batch_index] = state.g_order_table[:, _F_ORDER_TYPE]
        batch_order_dest[batch_index] = state.g_order_table[:, _F_DEST_PROV]

    # ── Phase (h): EvaluateAllianceScore — once per candidate ────────────────
    # A single-record scalar fallback retains the focused-test/diagnostic API;
    # production powers contain many records and use the batched equivalent.
    if candidate_count == 1:
        alliance_deltas = np.asarray([
            evaluate_alliance_score(
                state,
                power,
                local_b08,
                ring_convoy_score=int(candidate_records[0].get(
                    'ring_convoy_score', 0
                )),
                early_game_bonus=int(candidate_records[0].get(
                    'early_game_bonus', 0
                )),
                rank_penalty=int(candidate_records[0].get(
                    'rank_penalty', 0
                )),
                other_score=int(candidate_records[0].get('other_score', 0)),
                conviction_bonus=int(candidate_records[0].get(
                    'conviction_bonus', 0
                )),
                previous_maximum_base=int(candidate_records[0].get(
                    'alliance_maximum_base', 0
                )),
            )
        ], dtype=np.int64)
        candidate_records[0]['alliance_maximum_base'] = int(getattr(
            state, 'g_last_alliance_maximum_base', 0
        ))
    elif candidate_count:
        from ..heuristics import evaluate_alliance_scores_batch
        alliance_deltas = evaluate_alliance_scores_batch(
            state,
            power,
            local_b08,
            batch_key_weight,
            batch_key_weight_flt,
            batch_mc_pressure,
            batch_mc_fleet_pressure,
            batch_order_type,
            batch_order_dest,
            ring_convoy_scores=np.asarray([
                int(candidate.get('ring_convoy_score', 0))
                for candidate in candidate_records
            ], dtype=np.int64),
            early_game_bonuses=np.asarray([
                int(candidate.get('early_game_bonus', 0))
                for candidate in candidate_records
            ], dtype=np.int64),
            rank_penalties=np.asarray([
                int(candidate.get('rank_penalty', 0))
                for candidate in candidate_records
            ], dtype=np.int64),
            other_scores=np.asarray([
                int(candidate.get('other_score', 0))
                for candidate in candidate_records
            ], dtype=np.int64),
            conviction_bonuses=np.asarray([
                int(candidate.get('conviction_bonus', 0))
                for candidate in candidate_records
            ], dtype=np.int64),
            previous_maximum_bases=np.asarray([
                int(candidate.get('alliance_maximum_base', 0))
                for candidate in candidate_records
            ], dtype=np.int64),
        )
        for candidate, maximum_base in zip(
            candidate_records,
            np.asarray(
                getattr(
                    state,
                    'g_last_alliance_maximum_bases',
                    np.zeros(candidate_count, dtype=np.int64),
                ),
                dtype=np.int64,
            ),
        ):
            candidate['alliance_maximum_base'] = int(maximum_base)
    else:
        alliance_deltas = np.empty(0, dtype=np.int64)

    for c, alliance_delta in zip(candidate_records, alliance_deltas):
        alliance_delta = int(alliance_delta)
        # Candidate field 8 is the live EvaluateOrderScore result and field 9
        # is initialized from it before the alliance rounds. Preserve that
        # candidate-specific component when applying the alliance evaluation;
        # otherwise positions whose alliance delta is identical for every
        # candidate collapse to insertion order (notably Germany's opening
        # KIE-hold candidate).
        new_score = int(c.get('base_score', c.get('score', 0))) + alliance_delta

        # ── Phase (i): store per-candidate result ─────────────────────────────
        # C: lines 1071–1101 — puVar5[9] = new_score; average with previous if
        # trial_counter > 0; store round count.
        # For rounds after zero C averages the new result with candidate field
        # 9, i.e. the preceding live alliance score.
        old_score = int(c.get('score', 0))
        avg_score = (old_score // 2 + new_score // 2) if trial_counter > 0 else new_score
        c['alliance_score'] = new_score
        c['alliance_score_avg'] = avg_score
        c['round_count'] = trial_counter
        # UpdateAllyOrderScore writes the new alliance score to candidate field
        # 9, while field 8 retains EvaluateOrderScore for the next reset.
        c.setdefault('base_score', c.get('score', 0))
        c['score'] = new_score

        # C also writes two PER-ROUND slots (decompile 1092-1098):
        #   puVar5[trial_counter + 0x35] = new_score
        #   puVar5[trial_counter + 0x53] = avg_score
        # _rank_candidates_for_power's Pareto filter reads exactly these —
        # trial_scores[t] across t = 0..trial_counter, and the current
        # round's 0x53 slot as the tie-break dimension.  Without them every
        # comparison was 0-vs-0 and nothing could ever be dominated.
        # Added 2026-08-12.
        trial_scores = c.setdefault('trial_scores', [])
        while len(trial_scores) <= trial_counter:
            trial_scores.append(0)
        trial_scores[trial_counter] = new_score
        c['final_dim_score'] = avg_score

    # C tail-call: FUN_00424850((int *)param_1, '\x01').  This is not a
    # conviction/deceit dispatcher as previously assumed — it is
    # RankCandidatesForPower, already ported as _rank_candidates_for_power for
    # the param_2 == '\0' call site in BuildAndSendSUB.  It prunes dominated
    # candidates, assigns each survivor a share of the remaining probability
    # mass, and writes the per-candidate selection probability the order
    # picker consumes.  Wired up 2026-08-12 (was a documented no-op).
    from ..bot.analysis import _rank_candidates_for_power
    _rank_candidates_for_power(state, power, flag=1)


def _refresh_order_table(state: InnerGameState, power: int) -> None:
    """
    Port of RefreshOrderTable (FUN_00424490).

    Populates g_current_best_order[power] with 30 complete candidate order
    sets using RefreshOrderTable.c's score-ordered rejection walk.

    The C code sorts candidates by the integer conversion of
    RankCandidatesForPower's weight, walks that tree from greatest to least,
    and compares a 0..999 MSVC-rand draw against a complement threshold.
    First-slot SC gates abort that walk and use the first tree element.

    Fix 2026-04-20 (M-MC-3): previously wrote to g_order_table (wrong target)
    and missed the SC threshold gates entirely.
    """
    candidates = [c for c in state.g_candidate_record_list if c.get('power') == power]
    if not candidates:
        return

    # C's temporary tree holds a pair of pointers to each candidate record;
    # each DAT_00bbf690/694 slot therefore selects the candidate's complete
    # order list.  Do not flatten unit orders across candidates: that creates
    # hybrid sets which never existed in any trial.
    candidate_pool: list = []  # [(orders, weight, insertion_idx, record), ...]
    for insertion_idx, c in enumerate(candidates):
        # RefreshOrderTable.c inserts FloatToInt64(candidate[0x16]) into its
        # temporary tree.  RankCandidatesForPower writes that field; Python
        # binds it as ``weight``.  ``pressure_cost`` is local_c10's input and
        # must not bypass the ranker's probability calculation here.
        # FloatToInt64 truncates toward zero.  Preserve negative and >1000
        # values here; the C tree key is not clamped.
        selection_weight = int(float(c.get('weight', 0)))
        orders = c.get('orders', [])
        if isinstance(orders, (list, tuple)) and orders:
            candidate_pool.append((orders, selection_weight, insertion_idx, c))

    if not candidate_pool:
        return

    # FUN_00419fa0 stores the integer weight as the ordered-map key.  Its
    # comparator body is not present in Source; the surrounding selection
    # arithmetic is coherent with the established descending traversal (zero
    # weight records form the terminal fallback band).  Equal-key order also
    # remains unavailable, so retain insertion order as the stable analogue.
    candidate_pool.sort(key=lambda entry: (-entry[1], entry[2]))

    # SC threshold gates (C:157-186).  On slot zero, a failing gate breaks the
    # traversal and the post-loop fallback selects the tree's first element.
    own_power = int(getattr(state, 'albert_power_idx', 0))
    war_mode = getattr(state, 'g_war_mode_flag', 0)
    press_flag = getattr(state, 'g_press_flag', 0)
    sc_cnt = int(state.sc_count[power]) if power < len(state.sc_count) else 0

    def _passes_sc_gate(selection_weight: int, slot_idx: int) -> bool:
        """Return False when C breaks to the first-tree-element fallback."""
        if slot_idx != 0:
            return True
        # Gate 1: war mode AND not own power → reject if score < 50
        if war_mode == 1 and own_power != power:
            if selection_weight < 50:
                return False
        # Gate 2: SC count < 4 AND press off → reject if score < 50
        if sc_cnt < 4 and press_flag == 0:
            if selection_weight < 50:
                return False
        # Gate 3: SC count < 6 → reject if score < 20
        if sc_cnt < 6:
            if selection_weight < 20:
                return False
        return True

    # Fill 30 slots via the C rejection walk.
    _MAX_SLOTS = 30
    result_orders: list = []
    result_records: list = []

    for slot_idx in range(_MAX_SLOTS):
        first = candidate_pool[0]
        sel = first
        previous_weight = 0.0  # local_58

        # The decompiled loop always looks one node ahead.  Reaching end does
        # not select the terminal node; control falls through to `*head`, the
        # first tree element.  This is why a terminal zero-weight band behaves
        # like a sentinel/fallback in the original.
        for idx, entry in enumerate(candidate_pool[:-1]):
            current_weight = int(entry[1])
            next_weight = int(candidate_pool[idx + 1][1])
            if current_weight < 1 or next_weight < 1:
                complement = 0.0
            else:
                complement = float(1000 - current_weight) - previous_weight

            # C draws count=(rand()/23)%3 + 1 and retains only the final draw.
            draw_count = (random.randint(0, 0x7fff) // 0x17) % 3 + 1
            roll = 0
            for _ in range(draw_count):
                roll = (random.randint(0, 0x7fff) // 0x17) % 1000

            # Decompiled condition `fVar1 < roll != (fVar1 == roll)` is the
            # compiler's unordered-aware spelling of fVar1 <= roll.  That
            # exits to the common selection label with the current iterator.
            if complement <= float(roll):
                sel = entry
                break

            # C applies all three slot-zero gates to the look-ahead node
            # (ppiVar5[3]), not the current candidate.
            if not _passes_sc_gate(next_weight, slot_idx):
                sel = first
                break

            previous_weight += float(current_weight)

        result_orders.append(copy.deepcopy(list(sel[0])))
        result_records.append(sel[3])

    # Write to g_current_best_order (DAT_00bbf690/94) — NOT g_order_table.
    state.g_current_best_order[power] = result_orders
    state.g_current_best_order_records[power] = result_records


def update_score_state(state: InnerGameState) -> None:
    """
    Port of UpdateScoreState (FUN_0044c8e0).

    Two-phase order-table refresh.  For each power that has live units
    (DAT_0062e460 / g_unit_count[power] > 0) and is a member of DAT_00bc1e00 —
    the participant power set of the broadcast proposal BuildAndSendSUB is
    currently running trials for:

      Pass 1 → UpdateAllyOrderScore (FUN_00442770)
      Pass 2 → RefreshOrderTable    (FUN_00424490)

    Both loops read ``iVar1 = DAT_00bc1e04`` (the container's head sentinel)
    and take the branch on ``puVar3[1] != iVar1``, i.e. ``find(power) !=
    end()``.  BuildAndSendSUB.c:283-305 runs the same membership test inline,
    and BuildAndSendSUB.c:231-234 destroys the container by passing
    DAT_00bc1e04 as the head argument of SerializeOrders — so DAT_00bc1e04 is
    a node pointer, not a round counter.

    Research.md §5323.
    """
    num_powers = len(state.g_unit_count)
    participants = state.g_proposal_order_powers

    # Pass 1 — update ally order scores for participating, live-unit powers
    for power in range(num_powers):
        if state.g_unit_count[power] <= 0:
            continue
        if power in participants:
            _update_ally_order_score(state, power)

    # Pass 2 — refresh order table entries for the same powers
    for power in range(num_powers):
        if state.g_unit_count[power] <= 0:
            continue
        if power in participants:
            _refresh_order_table(state, power)


# ── CheckTimeLimit ────────────────────────────────────────────────────────────

def check_time_limit(state: InnerGameState) -> bool:
    """
    Port of CheckTimeLimit (CheckTimeLimit).

    In the original binary: mutex-protected read of
    g_network_state->field_0x20 (the MTL timeout flag set by the timer thread
    when the Move Time Limit fires).  Returns True if time has expired.

    Python has no network timer thread that writes ``mtl_expired``.  Honor an
    explicit external flag first, then reproduce that timer's observable
    behavior by comparing the current wall clock with ``g_turn_deadline``.
    Latch expiry onto the flag so later hot-loop checks avoid repeated clock
    comparisons and see a stable result.

    Research.md §5358.
    """
    if int(getattr(state, 'mtl_expired', 0)) != 0:
        return True
    deadline = float(getattr(state, 'g_turn_deadline', 0.0))
    if deadline > 0.0 and time.time() >= deadline:
        state.mtl_expired = 1
        return True
    return False
