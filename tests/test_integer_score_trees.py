"""Regressions for recovered signed-int64 score-tree arithmetic."""

import os
import sys

import numpy as np


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state_mod = __import__(f'{_pkg_name}.state', fromlist=['InnerGameState'])
_generation = __import__(
    f'{_pkg_name}.monte_carlo.generation',
    fromlist=[
        '_initial_build_heat_seed', '_diffuse_integer_heat',
        '_populate_candidate_scores_from_heat', '_sum_influence_heat',
    ],
)
_scoring = __import__(
    f'{_pkg_name}.heuristics.scoring',
    fromlist=['score_order_candidates_all_powers', 'score_provinces'],
)

InnerGameState = _state_mod.InnerGameState
_initial_build_heat_seed = _generation._initial_build_heat_seed
_diffuse_integer_heat = _generation._diffuse_integer_heat
_populate_candidate_scores_from_heat = (
    _generation._populate_candidate_scores_from_heat
)
_sum_influence_heat = _generation._sum_influence_heat
score_order_candidates_all_powers = (
    _scoring.score_order_candidates_all_powers
)
score_provinces = _scoring.score_provinces


def test_generate_orders_build_heat_is_seeded_by_owned_home_centres():
    state = InnerGameState()
    state.sc_count[0] = 3
    state.g_target_sc_cnt[0] = 5
    state.unit_info = {
        10: {'power': 0, 'type': 'A'},
        11: {'power': 0, 'type': 'F'},
        12: {'power': 1, 'type': 'A'},
    }
    state.home_centers = {0: frozenset({10, 11, 12})}
    state.g_sc_owner[[10, 11]] = 0
    state.g_sc_owner[12] = 1

    seed = _initial_build_heat_seed(state, 0, (10, 11, 12, 13))

    assert seed[10] == 2000
    assert seed[11] == 2000
    assert seed[12] == 0
    assert seed[13] == 0


def test_generate_orders_influence_gate_uses_home_set_not_live_unit():
    state = InnerGameState()
    foreign_home, foreign_unit, ordinary = 10, 11, 12
    state.home_centers = {1: frozenset({foreign_home})}
    state.unit_info[foreign_unit] = {'power': 1, 'type': 'A', 'coast': ''}
    heat_build = np.zeros(256, dtype=np.int64)
    heat_move = np.zeros(256, dtype=np.int64)
    heat_move[[foreign_home, foreign_unit, ordinary]] = [100, 20, 3]

    total = _sum_influence_heat(
        state, 0, 1, (foreign_home, foreign_unit, ordinary),
        heat_build, heat_move,
    )

    assert total == 23


def test_generate_orders_heat_diffusion_uses_signed_integer_division():
    seed = np.zeros(256, dtype=np.int64)
    seed[10] = 6
    seed[11] = -6

    result = _diffuse_integer_heat(
        seed,
        (10, 11),
        {10: [11], 11: [10]},
        rounds=1,
    )

    # C __alldiv truncates -6/5 toward zero; Python // would produce -2.
    assert result[10] == -1
    assert result[11] == 1


def test_generate_orders_heat_ranking_skips_own_power_token_not_live_unit():
    state = InnerGameState()
    owned_sc, stamped_non_sc, own_army, fallback = 10, 11, 12, 13
    state.win_threshold = 2
    state.sc_provinces = {owned_sc}
    state.g_sc_owner[owned_sc] = 0
    state.g_sc_owner[stamped_non_sc] = 0
    state.unit_info[own_army] = {'power': 0, 'type': 'A', 'coast': ''}
    heat = np.zeros(256, dtype=np.int64)
    heat[[owned_sc, stamped_non_sc, own_army, fallback]] = [100, 95, 90, 80]

    _populate_candidate_scores_from_heat(
        state, 0, (owned_sc, stamped_non_sc, own_army, fallback), heat
    )

    assert state.g_candidate_scores[0, owned_sc] == 0
    assert state.g_candidate_scores[0, stamped_non_sc] == 0
    assert state.g_candidate_scores[0, own_army] == 90
    assert state.g_candidate_scores[0, fallback] == 80


def test_final_score_normalization_uses_integer_tree_division():
    state = InnerGameState()
    province = 10
    state.valid_provinces = frozenset({province})
    state.land_provinces = frozenset()
    state.water_provinces = frozenset()
    state.g_candidate_bfs[0, 0, province] = 2
    state._bfs_flt = state.g_candidate_bfs.copy()
    state._bfs_flt[0, 0, province] = 3

    score_order_candidates_all_powers(state, [1] + [0] * 9, -1)

    # AMY: 2*1000/3 truncates to 666, then +15 = 681.  Phase 1c replaces
    # that with the shared province maximum 1015 minus 681.
    assert state.final_score_set[0, province] == 334
    assert state.final_score_set_flt[0, province] == 1015


def test_zero_minimum_is_promoted_before_low_score_normalization():
    state = InnerGameState()
    low, high, zero = 10, 11, 12
    state.valid_provinces = frozenset({low, high, zero})
    state.land_provinces = frozenset()
    state.water_provinces = frozenset()
    state.g_candidate_bfs[0, 0, low] = 1
    state.g_candidate_bfs[0, 0, high] = 10_000
    state._bfs_flt = state.g_candidate_bfs.copy()

    score_order_candidates_all_powers(state, [1] + [0] * 9, -1)

    # ScoreOrderCandidates_AllPowers changes a zero tree minimum to one.
    # The raw-one node therefore takes the exact-minimum branch and stores 1.
    assert state.final_score_set[0, low] == 1
    assert state.final_score_set_flt[0, low] == 1


def test_score_provinces_resets_persistent_retry_counters():
    state = InnerGameState()
    province = 10
    state.valid_provinces = frozenset({province})
    state.adj_matrix = {province: []}
    state.fleet_adj_matrix = {province: []}
    state.g_province_base[province] = 600

    score_provinces(state, move_weight=1, build_weight=1, own_power=0)

    assert state.g_province_base[province] == 0
