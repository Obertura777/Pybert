"""Regression tests for ProcessTurn post-processing steps 5 and 6."""

import os
import sys


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state = __import__(f"{_pkg_name}.state", fromlist=["InnerGameState"])
_trial = __import__(
    f"{_pkg_name}.monte_carlo.trial",
    fromlist=[
        "_dedupe_step5_fleet_candidates",
        "_apply_step6_target_filter",
    ],
)

InnerGameState = _state.InnerGameState
_dedupe_step5_fleet_candidates = _trial._dedupe_step5_fleet_candidates
_apply_step6_target_filter = _trial._apply_step6_target_filter


POWER = 2
SOURCE = 10
DEST = 20


def test_step5_stably_deduplicates_current_fleets_destinations():
    candidates = [(100.0, DEST), (90.0, 30), (80.0, DEST), (70.0, 30)]

    assert _dedupe_step5_fleet_candidates(candidates) == [
        (100.0, DEST),
        (90.0, 30),
    ]


def test_step6_removes_class1_candidate_below_threshold():
    state = InnerGameState()
    state.g_prov_target_flag[POWER, DEST] = 1

    assert _apply_step6_target_filter(
        state, POWER, SOURCE, [(99.0, DEST)], 100.0
    ) == []


def test_step6_removes_class2_candidate_below_threshold():
    state = InnerGameState()
    state.g_prov_target_flag[POWER, DEST] = 2

    assert _apply_step6_target_filter(
        state, POWER, SOURCE, [(99.0, DEST)], 100.0
    ) == []


def test_step6_keeps_candidate_at_threshold():
    state = InnerGameState()
    state.g_prov_target_flag[POWER, DEST] = 1

    assert _apply_step6_target_filter(
        state, POWER, SOURCE, [(100.0, DEST)], 100.0
    ) == [(100.0, DEST)]


def test_step6_nonzero_companion_marker_bypasses_filter():
    state = InnerGameState()
    state.g_prov_target_flag[POWER, DEST] = 1
    state.g_target_flag2[POWER, DEST] = -1

    assert _apply_step6_target_filter(
        state, POWER, SOURCE, [(1.0, DEST)], 100.0
    ) == [(1.0, DEST)]


def test_step6_registered_convoy_adjacent_destination_is_exception():
    state = InnerGameState()
    state.adj_matrix[SOURCE] = [DEST]
    state.g_prov_target_flag[POWER, DEST] = 2
    state.g_province_score_trial[DEST] = 1

    assert _apply_step6_target_filter(
        state, POWER, SOURCE, [(1.0, DEST)], 100.0
    ) == [(1.0, DEST)]


def test_step6_registered_nonadjacent_destination_is_removed():
    state = InnerGameState()
    state.g_prov_target_flag[POWER, DEST] = 1
    state.g_province_score_trial[DEST] = 1

    assert _apply_step6_target_filter(
        state, POWER, SOURCE, [(1.0, DEST)], 100.0
    ) == []
