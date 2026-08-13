"""WIN adjustment candidate identity and membership regressions."""

import os
import sys


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state_mod = __import__(f'{_pkg_name}.state', fromlist=['InnerGameState'])
_win_mod = __import__(
    f'{_pkg_name}.heuristics.win',
    fromlist=['populate_build_candidates', 'populate_remove_candidates'],
)

InnerGameState = _state_mod.InnerGameState
populate_build_candidates = _win_mod.populate_build_candidates
populate_remove_candidates = _win_mod.populate_remove_candidates


def test_coastal_build_site_generates_army_and_fleet_candidates():
    state = InnerGameState()
    state.home_centers = {0: frozenset({10})}
    state.g_sc_ownership[0, 10] = 1
    state.fleet_adj_matrix = {10: [11]}

    populate_build_candidates(state, 0)

    assert state.g_adjustment_candidate_provinces == {10}
    assert state.g_adjustment_build_candidates == [
        {'province': 10, 'unit_type': 'AMY', 'coast': ''},
        {'province': 10, 'unit_type': 'FLT', 'coast': ''},
    ]


def test_remove_candidate_membership_does_not_depend_on_positive_score():
    state = InnerGameState()
    state.unit_info = {10: {'power': 0, 'type': 'A', 'coast': ''}}
    state.g_candidate_bfs[0, 0, 10] = -2500

    populate_remove_candidates(state, 0)

    assert state.g_adjustment_candidate_provinces == {10}
    assert state.g_candidate_bfs[0, 0, 10] == -2500
