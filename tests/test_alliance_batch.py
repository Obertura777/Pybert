"""Parity checks for batched alliance candidate evaluation."""

import os
import sys

import numpy as np


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state = __import__(f'{_pkg_name}.state', fromlist=['InnerGameState'])
_primitives = __import__(
    f'{_pkg_name}.heuristics._primitives',
    fromlist=['evaluate_alliance_score', 'evaluate_alliance_scores_batch'],
)

InnerGameState = _state.InnerGameState
evaluate_alliance_score = _primitives.evaluate_alliance_score
evaluate_alliance_scores_batch = _primitives.evaluate_alliance_scores_batch


def test_batched_alliance_scores_match_scalar_candidates_exactly():
    rng = np.random.default_rng(20260828)
    state = InnerGameState()
    state.albert_power_idx = 0
    state.g_near_end_game_factor = 4.0
    state.g_deceit_level = 2
    state.g_press_flag = 0
    state.g_best_ally_slot0 = 1
    state.sc_count[:] = [6, 7, 4, 3, 5, 2, 1]
    state.unit_info = {
        10: {'power': 0, 'type': 'A', 'coast': ''},
        20: {'power': 1, 'type': 'F', 'coast': ''},
        30: {'power': 2, 'type': 'A', 'coast': ''},
    }
    state.water_provinces = {20, 21}
    state.fleet_adj_matrix = {20: [21], 21: [20, 22]}
    state.g_relation_score[:] = rng.integers(0, 25, size=(7, 7))
    state.g_ally_trust_score[:] = rng.integers(0, 5, size=(7, 7))
    state.g_ally_trust_score_hi[:] = rng.integers(0, 2, size=(7, 7))
    state.g_own_reach_score[:] = rng.integers(0, 6, size=(7, 256))
    state.g_enemy_reach_score[:] = rng.integers(0, 6, size=(7, 256))
    state.g_unit_province_reach[:] = rng.integers(0, 20, size=(7, 256))
    state.g_attack_history[:] = rng.integers(0, 15, size=(7, 256))
    state.g_sc_ownership[:] = rng.integers(0, 2, size=(7, 256))
    state.g_board_sc_ownership[:] = rng.integers(0, 2, size=(7, 256))
    state.g_threat_level[:] = rng.integers(0, 4, size=(7, 256))
    state.g_friendly_unit_flag[:] = rng.integers(0, 2, size=(7, 256))
    state.final_score_set[:] = rng.integers(0, 2000, size=(7, 256))
    state.final_score_set_flt[:] = rng.integers(0, 2000, size=(7, 256))

    batch_size = 4
    key_weight = rng.integers(0, 4, size=(batch_size, 7, 256), dtype=np.int32)
    key_weight_flt = rng.integers(
        0, 4, size=(batch_size, 7, 256), dtype=np.int32
    )
    mc_pressure = rng.integers(
        0, 8, size=(batch_size, 7, 256), dtype=np.int32
    )
    mc_fleet_pressure = rng.integers(
        0, 8, size=(batch_size, 7, 256), dtype=np.int32
    )
    order_type = np.zeros((batch_size, 256), dtype=np.int16)
    order_dest = np.zeros_like(order_type)
    order_type[:, 10] = [2, 1, 6, 2]
    order_dest[:, 10] = [11, 10, 12, 13]
    order_type[:, 20] = [1, 2, 1, 2]
    order_dest[:, 20] = [20, 21, 20, 22]

    expected = []
    expected_last_desirability = None
    for index in range(batch_size):
        state.g_key_weight[:] = key_weight[index]
        state.g_key_weight_flt[:] = key_weight_flt[index]
        state.g_mc_province_pressure[:] = mc_pressure[index]
        state.g_mc_fleet_pressure[:] = mc_fleet_pressure[index]
        state.g_order_table[:, 0] = order_type[index]
        state.g_order_table[:, 2] = order_dest[index]
        expected.append(evaluate_alliance_score(state, 0, 12))
        expected_last_desirability = state.g_alliance_desirability.copy()

    actual = evaluate_alliance_scores_batch(
        state,
        0,
        12,
        key_weight,
        key_weight_flt,
        mc_pressure,
        mc_fleet_pressure,
        order_type,
        order_dest,
    )

    assert actual.tolist() == expected
    np.testing.assert_array_equal(
        state.g_alliance_desirability, expected_last_desirability
    )
