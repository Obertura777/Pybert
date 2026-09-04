"""Regressions for ProcessTurn's precommitted three-unit move ring."""

import os
import sys


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state = __import__(f"{_pkg_name}.state", fromlist=["InnerGameState"])
_trial = __import__(f"{_pkg_name}.monte_carlo.trial", fromlist=["process_turn"])
_rng = __import__(f"{_pkg_name}.rng", fromlist=["seed"])

InnerGameState = _state.InnerGameState
process_turn = _trial.process_turn


def _ring_state():
    state = InnerGameState()
    state.albert_power_idx = 0
    state.g_num_powers = 7
    state.num_provinces = 4
    state.num_valid_provinces = 4
    state.valid_provinces = frozenset({1, 2, 3})
    state.land_provinces = state.valid_provinces
    state.unit_info = {
        1: {"power": 0, "type": "A", "coast": ""},
        2: {"power": 0, "type": "A", "coast": ""},
        3: {"power": 0, "type": "A", "coast": ""},
    }
    state.adj_matrix = {
        1: [2, 3],
        2: [1, 3],
        3: [1, 2],
    }
    state.g_sc_ownership[0, [1, 2, 3]] = 1
    state.g_ring_convoy_enabled = 1
    state.g_ring_prov_a = 1
    state.g_ring_prov_b = 2
    state.g_ring_prov_c = 3
    return state


def _capture_trial_orders(monkeypatch, state):
    snapshots = []
    monkeypatch.setattr(
        _trial,
        "evaluate_order_proposal",
        lambda current, _power, **_kwargs: snapshots.append(
            [
                (
                    int(current.g_order_table[province, 0]),
                    int(current.g_order_table[province, 2]),
                )
                for province in (1, 2, 3)
            ]
        ),
    )

    _rng.seed(1)
    process_turn(state, 0, num_trials=1)
    return snapshots


def test_ring_moves_are_committed_before_destination_units_leave(monkeypatch):
    """BuildOrder_MTO itself must not reject an as-yet-unordered occupant.

    ProcessTurn.c commits A→B, B→C, C→A in that order.  The recovered
    BuildOrder_MTO has no occupancy gate; the later ordinary-candidate tail
    owns self-bump handling.  Applying that later gate inside the builder
    turns every first ring edge into HLD because B has not been written yet.
    """
    state = _ring_state()

    assert _capture_trial_orders(monkeypatch, state) == [
        [(2, 2), (2, 3), (2, 1)]
    ]
    # Before the final C→A BuildOrder_MTO, ProcessTurn caches A's existing
    # A→B record for AssignSupportOrder's conflict-resolution tail.
    assert state.g_last_mto_insert == (2, 2)


def test_any_accepted_xdo_source_blocks_alberts_ring(monkeypatch):
    state = _ring_state()
    state.g_xdo_order_move_by_power = {0: {2: 3}}

    snapshots = _capture_trial_orders(monkeypatch, state)

    assert snapshots != [[(2, 2), (2, 3), (2, 1)]]
