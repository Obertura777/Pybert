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
    f'{_pkg_name}.moves.hold', fromlist=['enumerate_hold_orders'],
)
_primitives_mod = __import__(
    f'{_pkg_name}.heuristics._primitives',
    fromlist=['evaluate_alliance_score'],
)
_trial_mod = __import__(
    f'{_pkg_name}.monte_carlo.trial',
    fromlist=['_update_ally_order_score'],
)

InnerGameState = _state_mod.InnerGameState
enumerate_hold_orders = _hold_mod.enumerate_hold_orders
evaluate_alliance_score = _primitives_mod.evaluate_alliance_score
_update_ally_order_score = _trial_mod._update_ally_order_score


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


def test_evaluate_alliance_score_consumes_live_key_weight():
    state = InnerGameState()
    province = 10
    state.final_score_set[0, province] = 100
    baseline = evaluate_alliance_score(state, 0, trial_weight=4)
    state.g_key_weight[0, province] = 4

    score = evaluate_alliance_score(state, 0, trial_weight=4)

    assert score == baseline + 100


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
