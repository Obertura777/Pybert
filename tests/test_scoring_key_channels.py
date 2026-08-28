"""Token-keyed province-score regressions from the recovered C tree layout."""

import os
import sys


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state_mod = __import__(f'{_pkg_name}.state', fromlist=['InnerGameState'])
_scoring_mod = __import__(
    f'{_pkg_name}.heuristics.scoring',
    fromlist=['score_order_candidates_all_powers'],
)
_support_mod = __import__(
    f'{_pkg_name}.moves.support',
    fromlist=['assign_support_order', 'build_support_opportunities'],
)

InnerGameState = _state_mod.InnerGameState
score_order_candidates_all_powers = _scoring_mod.score_order_candidates_all_powers
assign_support_order = _support_mod.assign_support_order
build_support_opportunities = _support_mod.build_support_opportunities


def test_phase_round_weights_match_recovered_constructor_stores():
    state = InnerGameState()

    assert state.g_spr_round_weights == [
        500, 1000, 30, 10, 6, 5, 4, 3, 2, 1000,
    ]
    assert state.g_fal_round_weights == [
        1000, 500, 30, 10, 6, 5, 4, 3, 2, 1000,
    ]


def test_army_and_fleet_keys_share_one_power_normalization_and_province_max():
    state = InnerGameState()
    coast = 10
    state.valid_provinces = frozenset({coast})
    state.land_provinces = frozenset()
    state.water_provinces = frozenset()
    state.adj_matrix = {coast: []}
    state.fleet_adj_matrix = {coast: []}
    state.g_candidate_bfs[0, 0, coast] = 50
    state._bfs_flt = state.g_candidate_bfs.copy()
    state._bfs_flt[0, 0, coast] = 100

    score_order_candidates_all_powers(state, [1] + [0] * 9, -1)

    # Both keys are normalised against the fleet key's maximum of 100.
    # AMY first becomes 515, then Phase 1c replaces it with 1015 - 515.
    assert state.final_score_set[0, coast] == 500
    assert state.final_score_set_flt[0, coast] == 1015
    assert state.g_max_prov_score_per_power[0, coast] == 1015


def test_round_zero_tree_domain_is_not_the_top_n_candidate_filter():
    state = InnerGameState()
    province = 12
    state.valid_provinces = frozenset({province})
    state.land_provinces = frozenset({province})
    state.water_provinces = frozenset()
    state.adj_matrix = {province: []}
    state.g_candidate_scores[0, province] = 0
    state.g_candidate_bfs[0, 0, province] = 25

    score_order_candidates_all_powers(state, [1] + [0] * 9, -1)

    # ScoreOrderCandidates_AllPowers iterates the +0x361c round-zero tree,
    # which is distinct from GenerateOrders' g_candidate_scores top-N table.
    assert state.final_score_set[0, province] == 1015


def test_support_destination_lookup_uses_moving_units_key_channel():
    state = InnerGameState()
    source, destination = 20, 21
    state.unit_info = {
        source: {'power': 0, 'type': 'F', 'coast': ''},
    }
    state.adj_matrix = {source: [destination], destination: [source]}
    state.fleet_adj_matrix = {source: [destination]}
    state.sc_provinces = set()
    state.final_score_set[0, destination] = 100
    state.final_score_set_flt[0, source] = 20
    state.final_score_set_flt[0, destination] = 10

    assign_support_order(state, 0, source, destination, 0)

    # 20 * .85 is not below the fleet destination score 10, so the support
    # score remains unset. Selecting the empty destination's default AMY
    # channel (100) would incorrectly take this branch.
    assert state.g_order_table[source, 18] == 0


def test_support_opportunity_filters_every_triangle_leg_by_unit_type():
    state = InnerGameState()
    source, target, supporter = 10, 11, 12
    state.unit_info = {
        source: {'power': 0, 'type': 'F', 'coast': ''},
    }
    # Province adjacency closes a triangle, but its target-supporter and
    # supporter-source edges are land-only and therefore unavailable to the
    # fleet token carried through the C adjacency walk.
    state.adj_matrix = {
        source: [target, supporter],
        target: [source, supporter],
        supporter: [source, target],
    }
    state.fleet_adj_matrix = {
        source: [target],
        target: [source],
        supporter: [],
    }
    state.g_top_reach_flag[target] = 1
    state.g_sc_ownership[0, target] = 1
    state.g_sc_ownership[0, supporter] = 1
    state.final_score_set_flt[0, target] = 75
    state.g_max_prov_score_per_power[0, target] = 75
    state.g_max_province_score[target] = 75

    build_support_opportunities(state)

    assert state.g_support_opportunities_set == []


def test_threat_path_scans_empty_supply_center_and_uses_shared_key_maximum():
    state = InnerGameState()
    threatened_sc, reachable, tail = 10, 11, 12
    state.valid_provinces = frozenset({threatened_sc, reachable, tail})
    state.sc_provinces = {threatened_sc}
    state.adj_matrix = {
        threatened_sc: [reachable],
        reachable: [threatened_sc, tail],
        tail: [reachable],
    }
    state.g_own_reach_score[0, threatened_sc] = 1
    state.g_sc_ownership[0, reachable] = 1
    state.final_score_set[0, reachable] = 5
    state.final_score_set_flt[0, reachable] = 20
    state.g_max_prov_score_per_power[0, reachable] = 20

    _scoring_mod._populate_threat_path_scores(state)

    # C enters on the SC flag even though the threatened centre is empty, and
    # its token-key loop sees the fleet-channel maximum.
    assert state.g_threat_path_score[0, threatened_sc] == 20


def test_threat_path_rejects_foreign_army_on_adjacent_supply_center():
    state = InnerGameState()
    threatened_sc, adjacent_sc, tail = 10, 11, 12
    state.valid_provinces = frozenset({threatened_sc, adjacent_sc, tail})
    state.sc_provinces = {threatened_sc, adjacent_sc}
    state.unit_info = {
        adjacent_sc: {'power': 1, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix = {
        threatened_sc: [adjacent_sc],
        adjacent_sc: [threatened_sc, tail],
        tail: [adjacent_sc],
    }
    state.g_own_reach_score[0, threatened_sc] = 1
    state.g_sc_ownership[0, adjacent_sc] = 1
    state.g_max_prov_score_per_power[0, adjacent_sc] = 99

    _scoring_mod._populate_threat_path_scores(state)

    assert state.g_threat_path_score[0, threatened_sc] == 0
