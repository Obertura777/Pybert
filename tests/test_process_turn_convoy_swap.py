"""Regression tests for ProcessTurn's C:2757-2865 convoy-swap path."""

import os
import sys


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state = __import__(f"{_pkg_name}.state", fromlist=["InnerGameState"])
_trial = __import__(
    f"{_pkg_name}.monte_carlo.trial", fromlist=["_apply_convoy_swap"]
)

InnerGameState = _state.InnerGameState
_apply_convoy_swap = _trial._apply_convoy_swap


POWER = 1
SOURCE = 10
DEST = 20
ASSIGNED = 40


def _pending_state():
    state = InnerGameState()
    state.g_order_table[DEST, 20] = 1
    state.g_convoy_source_prov[DEST] = ASSIGNED
    state.final_score_set[POWER, SOURCE] = 123
    state.final_score_set[POWER, ASSIGNED] = 456
    return state


def test_convoy_swap_promotes_pending_assignment_when_mover_demand_is_one():
    state = _pending_state()
    state.g_support_demand[SOURCE] = 1

    assert _apply_convoy_swap(
        state, POWER, SOURCE, DEST, rand_value=61 * 0x17
    )
    assert state.g_order_table[DEST, 20] == 2
    assert state.g_order_table[SOURCE, 20] == 5
    assert state.g_order_table[ASSIGNED, 20] == 5
    assert state.g_order_table[SOURCE, 13] == 1
    assert state.g_order_table[ASSIGNED, 13] == 1
    assert state.g_order_table[SOURCE, 6] == 123
    assert state.g_order_table[ASSIGNED, 6] == 456
    assert state.g_order_table[ASSIGNED, 24] == -1
    assert state.g_order_table[ASSIGNED, 25] == -1


def test_convoy_swap_random_gate_is_strictly_greater_than_sixty():
    state = _pending_state()
    state.g_support_demand[SOURCE] = 1

    assert not _apply_convoy_swap(
        state, POWER, SOURCE, DEST, rand_value=60 * 0x17
    )
    assert state.g_order_table[DEST, 20] == 1


def test_convoy_swap_accepts_zero_source_demand_for_own_destination_unit():
    state = _pending_state()
    state.unit_info[DEST] = {'power': POWER, 'type': 'A', 'coast': ''}

    assert _apply_convoy_swap(
        state, POWER, SOURCE, DEST, rand_value=61 * 0x17
    )


def test_convoy_swap_rejects_other_source_demand_without_own_unit_exception():
    state = _pending_state()
    state.g_support_demand[SOURCE] = 2

    assert not _apply_convoy_swap(
        state, POWER, SOURCE, DEST, rand_value=61 * 0x17
    )


def test_convoy_swap_rejects_missing_support_assignment():
    state = _pending_state()
    state.g_support_demand[SOURCE] = 1
    state.g_convoy_source_prov[DEST] = -1

    assert not _apply_convoy_swap(
        state, POWER, SOURCE, DEST, rand_value=61 * 0x17
    )
