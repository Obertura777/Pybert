"""DAT_00baed7c token-key candidate-weight lifecycle regressions."""

import os
import sys
from unittest.mock import patch


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state_mod = __import__(f'{_pkg_name}.state', fromlist=['InnerGameState'])
_hold_mod = __import__(
    f'{_pkg_name}.moves.hold',
    fromlist=['enumerate_hold_orders', 'compute_safe_reach'],
)
_primitives_mod = __import__(
    f'{_pkg_name}.heuristics._primitives',
    fromlist=['evaluate_alliance_score'],
)
_trial_mod = __import__(
    f'{_pkg_name}.monte_carlo.trial',
    fromlist=['_live_unit_adjacencies', '_update_ally_order_score'],
)

InnerGameState = _state_mod.InnerGameState
enumerate_hold_orders = _hold_mod.enumerate_hold_orders
compute_safe_reach = _hold_mod.compute_safe_reach
evaluate_alliance_score = _primitives_mod.evaluate_alliance_score
_update_ally_order_score = _trial_mod._update_ally_order_score
_live_unit_adjacencies = _trial_mod._live_unit_adjacencies


def _candidate(orders):
    return {
        'power': 0,
        'orders': orders,
        'score': 1000,
        'base_score': 1000,
        'heat_scores': [0] * 7,
        'trial_scores': [500],
        'final_dim_score': 500,
        'other_score': 0,
        'rank_penalty': 0,
        'min_rank': 10000,
        'max_rank': 0,
        'running_avg': 10000.0,
        'processed': 0,
        'pareto_flag': 0,
        'weight': 0.0,
        'output_score': 0.0,
    }


def _selected_slots(orders):
    return {
        power: ([orders] * 30 if power == 0 else [[]] * 30)
        for power in range(7)
    }


def test_enumerate_hold_orders_seeds_owner_key_and_preserves_reach_scores():
    state = InnerGameState()
    army, fleet = 10, 20
    state.unit_info = {
        army: {'power': 0, 'type': 'A', 'coast': ''},
        fleet: {'power': 1, 'type': 'F', 'coast': ''},
    }
    state.adj_matrix = {army: [], fleet: []}
    state.fleet_adj_matrix = {fleet: []}
    state._id_to_prov = {army: 'LON', fleet: 'NTH'}
    state.final_score_set[0, army] = 111
    state.final_score_set_flt[1, fleet] = 222

    enumerate_hold_orders(state, 0)

    assert state.key_weight(0, army, 'A') == 30
    assert state.key_weight(1, fleet, 'F') == 30
    assert state.key_weight(0, fleet, 'F') == 0
    # Hold-sequence serialization has no C write to these matrices.
    assert state.g_unit_province_reach[0, army] == 111
    assert state.g_unit_province_reach[1, fleet] == 222


def test_hold_reach_uses_typed_fleet_adjacency_not_raw_coastal_border():
    state = InnerGameState()
    source, land_only_neighbor = 10, 20
    state.unit_info[source] = {
        'power': 0, 'type': 'F', 'coast': '',
    }
    state.adj_matrix = {
        source: [land_only_neighbor], land_only_neighbor: [source],
    }
    state.fleet_adj_matrix = {source: []}
    state._id_to_prov = {source: 'ANK'}
    state.final_score_set_flt[0, source] = 10
    state.final_score_set_flt[0, land_only_neighbor] = 999

    enumerate_hold_orders(state, 0)

    assert int(state.g_max_non_ally_reach[0, source]) == 10


def test_hold_reach_gives_ally_designation_a_final_precedence():
    state = InnerGameState()
    source, adjacent = 10, 20
    state.unit_info[source] = {
        'power': 0, 'type': 'A', 'coast': '',
    }
    state.adj_matrix = {source: [adjacent], adjacent: [source]}
    state._id_to_prov = {source: 'LON'}
    state.final_score_set[0, source] = 10
    state.final_score_set[0, adjacent] = 999
    state.g_ally_designation_c[adjacent] = 2
    state.g_ally_designation_a[adjacent] = 1
    state.g_ally_trust_score[0, 2] = 0
    state.g_ally_trust_score[0, 1] = 5

    enumerate_hold_orders(state, 0)

    # EnumerateHoldOrders reads C, B, then A. The trusted slot-A designation
    # therefore wins and suppresses the adjacent province from the non-ally max.
    assert int(state.g_max_non_ally_reach[0, source]) == 10


def test_safe_reach_does_not_make_a_fleet_contest_its_own_province():
    state = InnerGameState()
    source = 10
    state.unit_info[source] = {
        'power': 0, 'type': 'F', 'coast': '',
    }
    state.adj_matrix = {source: []}
    state.fleet_adj_matrix = {source: []}
    state.final_score_set_flt[0, source] = 123

    compute_safe_reach(state)

    assert int(state.g_safe_reach_score[source]) == 123


def test_safe_reach_marks_unoccupied_neutral_centers_contested():
    state = InnerGameState()
    source, neutral_center = 10, 20
    state.unit_info[source] = {
        'power': 0, 'type': 'A', 'coast': '',
    }
    state.adj_matrix = {
        source: [neutral_center], neutral_center: [source],
    }
    state.sc_provinces = {neutral_center}
    state.final_score_set[0, source] = 10
    state.final_score_set[0, neutral_center] = 100

    compute_safe_reach(state)

    assert int(state.g_safe_reach_score[source]) == -1


def test_safe_reach_ignores_terrain_invalid_enemy_army_adjacency():
    state = InnerGameState()
    sea, coast = 10, 20
    state.unit_info = {
        sea: {'power': 0, 'type': 'F', 'coast': ''},
        coast: {'power': 1, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix = {sea: [coast], coast: [sea]}
    state.fleet_adj_matrix = {sea: []}
    state.water_provinces = frozenset({sea})
    state.final_score_set_flt[0, sea] = 77

    compute_safe_reach(state)

    assert int(state.g_safe_reach_score[sea]) == 77


def test_evaluate_alliance_score_consumes_live_key_weight():
    state = InnerGameState()
    province = 10
    state.final_score_set[0, province] = 100
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)
    state.g_key_weight[0, province] = 4

    score = evaluate_alliance_score(state, 0, trial_weight=4)

    assert score == baseline + 100


def test_alliance_move_bonus_requires_unit_to_control_occupied_sc():
    state = InnerGameState()
    source, destination = 10, 11
    state.unit_info[source] = {'power': 0, 'type': 'A', 'coast': ''}
    state.sc_provinces = {source}
    state.g_enemy_reach_score[0, source] = 1
    state.g_unit_province_reach[0, source] = 100
    state.g_order_table[source, 0] = 2
    state.g_order_table[source, 2] = destination
    state.final_score_set[0, source] = 100
    state.final_score_set[0, destination] = 200

    state.g_sc_owner[source] = 1
    foreign_control = evaluate_alliance_score(state, 0, trial_weight=4)
    state.g_sc_owner[source] = 0
    own_control = evaluate_alliance_score(state, 0, trial_weight=4)

    assert own_control == foreign_control + 100


def test_trusted_foreign_sc_cancels_ordinary_key_contribution():
    state = InnerGameState()
    province = 10
    state.sc_provinces = {province}
    state.g_sc_owner[province] = 1
    state.final_score_set[0, province] = 100

    state.g_ally_trust_score[0, 1] = 3
    trusted_baseline = evaluate_alliance_score(state, 0, trial_weight=4)
    state.g_key_weight[0, province] = 4
    trusted = evaluate_alliance_score(state, 0, trial_weight=4)

    state.g_key_weight[0, province] = 0
    state.g_ally_trust_score[0, 1] = 2
    hostile_baseline = evaluate_alliance_score(state, 0, trial_weight=4)
    state.g_key_weight[0, province] = 4
    hostile = evaluate_alliance_score(state, 0, trial_weight=4)

    assert trusted == trusted_baseline
    assert hostile == hostile_baseline + 100


def test_non_sc_pressure_adjustment_uses_sc_marker_and_press_gate():
    state = InnerGameState()
    province = 10
    state.unit_info[province] = {
        'power': 0, 'type': 'A', 'coast': '',
    }
    state.g_mc_province_pressure[0, province] = 10
    state.g_mc_province_pressure[1, province] = 6

    state.g_press_flag = 0
    non_sc_press_off = evaluate_alliance_score(
        state, 0, trial_weight=10,
    )
    state.g_press_flag = 1
    non_sc_press_on = evaluate_alliance_score(
        state, 0, trial_weight=10,
    )

    # 6*3 < 10*2 selects C's +10 band. Occupying the province does not
    # suppress it because board byte +3 is the SC marker, not unit presence.
    assert non_sc_press_off == non_sc_press_on + 10

    state.sc_provinces = {province}
    state.g_sc_owner[province] = 0
    state.g_press_flag = 0
    sc_press_off = evaluate_alliance_score(state, 0, trial_weight=10)
    state.g_press_flag = 1
    sc_press_on = evaluate_alliance_score(state, 0, trial_weight=10)

    assert sc_press_off == sc_press_on


def test_sc_opening_bonus_uses_per_power_path_and_deduction_gate():
    state = InnerGameState()
    opening_sc, defended_sc = 10, 11
    state.sc_provinces = {opening_sc}
    state.g_sc_owner[opening_sc] = 1
    state.g_mc_province_pressure[0, opening_sc] = 10
    state.g_threat_path_score[0, opening_sc] = 3
    state.g_max_prov_score_per_power[0, opening_sc] = 23

    without_opening = InnerGameState()
    without_opening.sc_provinces = {opening_sc}
    without_opening.g_sc_owner[opening_sc] = 1
    baseline = evaluate_alliance_score(without_opening, 0, trial_weight=10)
    opening = evaluate_alliance_score(state, 0, trial_weight=10)

    assert opening == baseline + 20

    # Threatening an own-controlled centre writes C's deduction scratch and
    # suppresses all opening bonus for that power.
    state.sc_provinces.add(defended_sc)
    state.g_sc_owner[defended_sc] = 0
    state.g_mc_province_pressure[1, defended_sc] = 8

    defended = evaluate_alliance_score(state, 0, trial_weight=10)

    assert defended == baseline


def test_sc_controller_phase_does_not_score_unit_occupancy():
    state = InnerGameState()
    province = 10
    baseline = evaluate_alliance_score(state, 0, trial_weight=10)

    state.unit_info[province] = {'power': 1, 'type': 'A', 'coast': ''}
    state.g_own_reach_score[0, province] = 1
    occupied = evaluate_alliance_score(state, 0, trial_weight=10)

    assert occupied == baseline


def test_controlled_sc_pressure_cost_uses_other_power_pressure_and_press_gate():
    state = InnerGameState()
    province = 10
    state.g_near_end_game_factor = 1.0
    state.sc_provinces = {province}
    state.g_sc_owner[province] = 0
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)

    state.g_relation_score[0, 1] = 10
    state.g_mc_province_pressure[1, province] = 4
    pressured = evaluate_alliance_score(state, 0, trial_weight=4)

    # Inner cost: trunc(20 + (4 - 0) * 10 / 4) = 30.
    # Visit deficit: trunc(30 + (4 - 0) * 10 / 4) = 40.
    assert pressured == baseline - 40

    state.g_press_flag = 1
    press_enabled = evaluate_alliance_score(state, 0, trial_weight=4)
    assert press_enabled == baseline


def test_foreign_key_weight_subtracts_reachable_token_score():
    state = InnerGameState()
    province = 10
    state.final_score_set[0, province] = 100
    state.g_own_reach_score[0, province] = 1
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)

    state.g_key_weight[1, province] = 4
    foreign_key = evaluate_alliance_score(state, 0, trial_weight=4)

    assert foreign_key == baseline - 100

    state.g_other_power_lead_flag = 1
    state.g_relation_score[0, 1] = 30
    defensive = evaluate_alliance_score(state, 0, trial_weight=4)

    assert defensive == baseline


def test_token_score_division_truncates_negative_values_toward_zero():
    state = InnerGameState()
    province = 10
    state.final_score_set[0, province] = -5
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)

    state.g_key_weight[0, province] = 1
    weighted = evaluate_alliance_score(state, 0, trial_weight=4)

    assert weighted == baseline - 1


def test_candidate_record_cost_fields_are_subtracted_from_own_score():
    state = InnerGameState()
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)

    adjusted = evaluate_alliance_score(
        state,
        0,
        trial_weight=4,
        ring_convoy_score=20,
        early_game_bonus=30,
        rank_penalty=40,
        other_score=2,
        conviction_bonus=7,
    )

    # Candidate maximum: trunc(7 * (0 + 3) / 8) = 2.
    assert adjusted == baseline - 192


def test_foreign_key_tracks_own_unit_province_maximum():
    state = InnerGameState()
    province = 10
    state.final_score_set[0, province] = 100
    state.g_own_reach_score[0, province] = 1
    state.g_sc_ownership[0, province] = 1
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)

    state.g_key_weight[1, province] = 4
    scored = evaluate_alliance_score(state, 0, trial_weight=4)

    # -100 foreign-key deduction, then
    # -trunc(100 * (0 + 3) / 8) = -37 province-maximum penalty.
    assert scored == baseline - 137


def test_candidate_maximum_penalty_uses_dominance_divisor_and_history():
    state = InnerGameState()
    state.g_near_end_game_factor = 5.0
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)

    ordinary = evaluate_alliance_score(
        state, 0, trial_weight=4, conviction_bonus=100,
    )
    state.g_leading_flag = 1
    leading = evaluate_alliance_score(
        state,
        0,
        trial_weight=4,
        conviction_bonus=10,
        previous_maximum_base=100,
    )

    assert ordinary == baseline - 100
    assert leading == baseline - 50


def test_water_fleet_chain_uses_static_home_membership_and_reversed_cap():
    state = InnerGameState()
    water, adjacent = 20, 21
    state.water_provinces = {water}
    state.fleet_adj_matrix = {water: [adjacent]}
    state.g_key_weight[0, water] = 4
    state.g_key_weight[0, adjacent] = 4
    state.final_score_set[0, water] = 750
    # Current ownership must not affect GameBoard_GetPowerRec's static set.
    state.g_board_sc_ownership[0, adjacent] = 1

    non_home = evaluate_alliance_score(state, 0, trial_weight=4)
    state.home_centers[0] = frozenset({adjacent})
    home = evaluate_alliance_score(state, 0, trial_weight=4)

    # Non-home arm caps at 20; home arm caps at 10.
    assert non_home == home + 10


def test_per_unit_move_bonus_truncates_each_integer_division():
    state = InnerGameState()
    sources = (10, 11)
    destination = 20
    for source in sources:
        state.unit_info[source] = {
            'power': 0, 'type': 'A', 'coast': '',
        }
        state.g_enemy_reach_score[0, source] = 1
        state.g_unit_province_reach[0, source] = 5
        state.g_key_weight[0, source] = 1
        state.g_order_table[source, 0] = 2
        state.g_order_table[source, 2] = destination
    state.final_score_set[0, destination] = 100

    state.g_press_flag = 1
    without_bonus = evaluate_alliance_score(state, 0, trial_weight=4)
    state.g_press_flag = 0
    with_bonus = evaluate_alliance_score(state, 0, trial_weight=4)

    # Each unit contributes trunc((4 - 1) * 5 / 4) = 3, not 3.75.
    assert with_bonus == without_bonus + 6


def test_opponent_score_is_scaled_by_second_influence_matrix():
    state = InnerGameState()
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)

    state.g_influence_matrix_b[0, 1] = 50.0
    scaled = evaluate_alliance_score(state, 0, trial_weight=4)

    # Enemy arm: (2000 - 5000) * 50 * 50 / 10000 = -750.
    assert scaled == baseline - 750


def test_whole_board_attack_count_adds_minimum_score_twice():
    state = InnerGameState()
    province = 10
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)
    state.g_own_reach_score[0, province] = 1
    state.g_threat_level[0, province] = 1
    state.g_attack_count[0, province] = 1
    state.g_min_prov_score_per_power[0, province] = 80

    scored = evaluate_alliance_score(state, 0, trial_weight=4)

    assert scored == baseline + 160


def test_whole_board_attack_history_uses_three_quarter_weight():
    state = InnerGameState()
    province = 10
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)
    state.g_own_reach_score[0, province] = 1
    state.g_threat_level[0, province] = 1
    state.g_attack_history[0, province] = 11
    state.g_min_prov_score_per_power[0, province] = 80

    scored = evaluate_alliance_score(state, 0, trial_weight=4)

    assert scored == baseline + 140


def test_spring_hostile_sc_key_uses_counter_scaling():
    state = InnerGameState()
    province = 10
    state.g_near_end_game_factor = 1.0
    state.g_season = 'SPR'
    state.sc_provinces = {province}
    state.g_sc_owner[province] = 1
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)

    state.g_key_weight[0, province] = 4
    scored = evaluate_alliance_score(state, 0, trial_weight=4)

    assert scored == baseline + 100


def test_fall_foreign_key_on_controlled_sc_reduces_counter():
    state = InnerGameState()
    province = 10
    state.g_near_end_game_factor = 1.0
    state.g_season = 'FAL'
    state.sc_provinces = {province}
    state.g_sc_owner[province] = 0
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)

    state.g_key_weight[1, province] = 4
    scored = evaluate_alliance_score(state, 0, trial_weight=4)

    assert scored == baseline - 300


def test_spring_designated_home_center_adds_unmoved_bonus():
    state = InnerGameState()
    province = 10
    state.g_season = 'SPR'
    state.home_centers[0] = frozenset({province})
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)

    state.g_ally_designation_b[province] = 0
    state.g_ally_designation_b_hi[province] = 0
    designated = evaluate_alliance_score(state, 0, trial_weight=4)

    assert designated == baseline + 10


def test_fall_designated_home_center_scales_positive_counter_b():
    state = InnerGameState()
    home, foreign_sc = 10, 11
    state.g_near_end_game_factor = 1.0
    state.g_season = 'FAL'
    state.home_centers[0] = frozenset({home})
    state.sc_provinces = {foreign_sc}
    state.g_sc_owner[foreign_sc] = 1
    state.g_key_weight[0, foreign_sc] = 4
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)

    state.g_ally_designation_b[home] = 0
    state.g_ally_designation_b_hi[home] = 0
    designated = evaluate_alliance_score(state, 0, trial_weight=4)

    # ((4 unmoved * counter_b 4 * 20) / 4) / 4 = 20.
    assert designated == baseline + 20


def test_update_ally_score_writes_source_key_and_primary_pressure():
    state = InnerGameState()
    source, adjacent = 10, 11
    orders = [(source, 1, source, 0, 0)]
    state.unit_info = {
        source: {'power': 0, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix = {source: [adjacent], adjacent: [source]}
    state.sc_count[0] = 1
    state.g_candidate_record_list = [_candidate(orders)]
    state.g_current_best_order = _selected_slots(orders)

    with patch(
        f'{_pkg_name}.heuristics.evaluate_alliance_score', return_value=0,
    ):
        _update_ally_order_score(state, 0)

    assert state.key_weight(0, source, 'A') == 4
    assert state.g_mc_province_pressure[0, source] == 4
    assert state.g_mc_province_pressure[0, adjacent] == 4
    assert state.g_mc_fleet_pressure[0, adjacent] == 0


def test_foreign_or_empty_sc_routes_key_adjacency_to_fleet_pressure():
    state = InnerGameState()
    source, target_sc, adjacent = 10, 20, 21
    orders = [(source, 3, target_sc, 0, 0)]
    state.unit_info = {
        source: {'power': 0, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix = {
        source: [target_sc], target_sc: [source, adjacent], adjacent: [target_sc],
    }
    state.sc_provinces = {target_sc}
    state.sc_count[0] = 1
    state.g_candidate_record_list = [_candidate(orders)]
    state.g_current_best_order = _selected_slots(orders)

    with patch(
        f'{_pkg_name}.heuristics.evaluate_alliance_score', return_value=0,
    ):
        _update_ally_order_score(state, 0)

    assert state.key_weight(0, target_sc, 'A') == 4
    assert state.g_mc_province_pressure[0, target_sc] == 4
    assert state.g_mc_fleet_pressure[0, adjacent] == 4
    assert state.g_mc_province_pressure[0, adjacent] == 0


def test_owned_sc_routes_key_adjacency_to_primary_pressure():
    state = InnerGameState()
    source, target_sc, adjacent = 10, 20, 21
    orders = [(source, 3, target_sc, 0, 0)]
    state.unit_info = {
        source: {'power': 0, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix = {
        source: [target_sc], target_sc: [source, adjacent], adjacent: [target_sc],
    }
    state.sc_provinces = {target_sc}
    state.g_sc_owner[target_sc] = 0
    state.sc_count[0] = 1
    state.g_candidate_record_list = [_candidate(orders)]
    state.g_current_best_order = _selected_slots(orders)

    with patch(
        f'{_pkg_name}.heuristics.evaluate_alliance_score', return_value=0,
    ):
        _update_ally_order_score(state, 0)

    assert state.key_weight(0, target_sc, 'A') == 4
    assert state.g_mc_province_pressure[0, target_sc] == 4
    assert state.g_mc_province_pressure[0, adjacent] == 4
    assert state.g_mc_fleet_pressure[0, adjacent] == 0


def test_support_move_uses_destination_key_not_secondary_or_zero():
    state = InnerGameState()
    supporter, mover, destination = 10, 11, 20
    orders = [(supporter, 4, destination, 0, mover)]
    state.unit_info = {
        supporter: {'power': 0, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix = {supporter: [], destination: []}
    state.sc_count[0] = 1
    state.g_candidate_record_list = [_candidate(orders)]
    state.g_current_best_order = _selected_slots(orders)

    with patch(
        f'{_pkg_name}.heuristics.evaluate_alliance_score', return_value=0,
    ):
        _update_ally_order_score(state, 0)

    assert state.key_weight(0, destination, 'A') == 4
    assert state.key_weight(0, mover, 'A') == 0
    assert state.key_weight(0, 0, 'A') == 0


def test_ally_score_live_fleet_adjacencies_keep_source_coast():
    state = InnerGameState()
    split_coast, north_target, south_target = 10, 20, 30
    state.adj_matrix = {
        split_coast: [north_target, south_target],
        north_target: [split_coast],
        south_target: [split_coast],
    }
    state.fleet_adj_matrix = {
        split_coast: [north_target, south_target],
    }
    state.fleet_coast_adj = {
        (split_coast, '/NC'): [north_target],
        (split_coast, '/SC'): [south_target],
    }
    fleet = {'power': 0, 'type': 'F', 'coast': 'NC'}

    assert _live_unit_adjacencies(state, split_coast, fleet) == [north_target]
