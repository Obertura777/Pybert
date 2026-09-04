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
    fromlist=[
        'populate_build_candidates', 'populate_remove_candidates',
        'compute_win_builds', 'compute_win_removes',
    ],
)
_scoring_mod = __import__(
    f'{_pkg_name}.heuristics.scoring',
    fromlist=['score_provinces', 'score_order_candidates_own_power'],
)

InnerGameState = _state_mod.InnerGameState
populate_build_candidates = _win_mod.populate_build_candidates
populate_remove_candidates = _win_mod.populate_remove_candidates
compute_win_builds = _win_mod.compute_win_builds
compute_win_removes = _win_mod.compute_win_removes


def test_coastal_build_site_generates_army_and_fleet_candidates():
    state = InnerGameState()
    state.home_centers = {0: frozenset({10})}
    state.g_board_sc_ownership[0, 10] = 1
    state.fleet_adj_matrix = {10: [11]}

    populate_build_candidates(state, 0)

    assert state.g_adjustment_candidate_provinces == {10}
    assert state.g_adjustment_build_candidates == [
        {'province': 10, 'unit_type': 'AMY', 'coast': ''},
        {'province': 10, 'unit_type': 'FLT', 'coast': ''},
    ]
    assert state.g_available_home_centers == frozenset({10})


def test_build_site_uses_board_ownership_not_unit_presence_scratch():
    state = InnerGameState()
    state.home_centers = {0: frozenset({10, 11})}
    state.g_board_sc_ownership[0, 10] = 1
    # A stale/synthetic scratch hit must not make an unowned home centre legal.
    state.g_sc_ownership[0, 11] = 1

    populate_build_candidates(state, 0)

    assert state.g_adjustment_candidate_provinces == {10}


def test_remove_candidate_membership_does_not_depend_on_positive_score():
    state = InnerGameState()
    state.unit_info = {10: {'power': 0, 'type': 'A', 'coast': ''}}
    state.g_candidate_bfs[0, 0, 10] = -2500

    populate_remove_candidates(state, 0)

    assert state.g_adjustment_candidate_provinces == {10}
    assert state.g_candidate_bfs[0, 0, 10] == -2500


def test_equal_score_removes_consume_reverse_unit_key_insertion_order():
    state = InnerGameState()
    state.albert_power_idx = 0
    state._id_to_prov = {10: 'LON', 20: 'EDI'}
    state.unit_info = {
        10: {'power': 0, 'type': 'A', 'coast': ''},
        20: {'power': 0, 'type': 'A', 'coast': ''},
    }
    state.g_adjustment_candidate_provinces = {10, 20}
    state.g_candidate_scores[0, 10] = 100
    state.g_candidate_scores[0, 20] = 100

    compute_win_removes(state, 1)

    assert state.g_build_order_list == ['( AUS AMY EDI ) REM']


def test_builds_rescore_before_each_selection_and_exclude_used_site(monkeypatch):
    state = InnerGameState()
    state.albert_power_idx = 0
    state._id_to_prov = {10: 'LON', 20: 'EDI'}
    state.g_adjustment_build_candidates = [
        {'province': 10, 'unit_type': 'AMY', 'coast': ''},
        {'province': 20, 'unit_type': 'AMY', 'coast': ''},
    ]
    score_calls = []

    monkeypatch.setattr(_scoring_mod, 'score_provinces', lambda *args: None)

    def score_candidates(candidate_state, *_args):
        score_calls.append(len(candidate_state.g_selected_build_candidates))
        if not candidate_state.g_selected_build_candidates:
            candidate_state.g_adjustment_candidate_scores = {
                (10, 'AMY', ''): 10,
                (20, 'AMY', ''): 20,
            }
        else:
            candidate_state.g_adjustment_candidate_scores = {
                (10, 'AMY', ''): 30,
                (20, 'AMY', ''): -100,
            }

    monkeypatch.setattr(
        _scoring_mod, 'score_order_candidates_own_power', score_candidates
    )

    compute_win_builds(state, 2)

    assert score_calls == [0, 1]
    assert state.g_build_order_list == [
        '( AUS AMY EDI ) BLD',
        '( AUS AMY LON ) BLD',
    ]


def test_equal_score_builds_preserve_ascending_source_insertion(monkeypatch):
    state = InnerGameState()
    state.albert_power_idx = 0
    state._id_to_prov = {10: 'LON', 20: 'EDI'}
    state.g_adjustment_build_candidates = [
        {'province': 20, 'unit_type': 'AMY', 'coast': ''},
        {'province': 10, 'unit_type': 'FLT', 'coast': ''},
        {'province': 10, 'unit_type': 'AMY', 'coast': ''},
    ]

    monkeypatch.setattr(_scoring_mod, 'score_provinces', lambda *args: None)

    def equal_scores(candidate_state, *_args):
        candidate_state.g_adjustment_candidate_scores = {
            (20, 'AMY', ''): 100,
            (10, 'FLT', ''): 100,
            (10, 'AMY', ''): 100,
        }

    monkeypatch.setattr(
        _scoring_mod, 'score_order_candidates_own_power', equal_scores
    )

    compute_win_builds(state, 1)

    assert state.g_build_order_list == ['( AUS AMY LON ) BLD']
