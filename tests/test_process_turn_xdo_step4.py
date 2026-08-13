"""Regression tests for ProcessTurn Step 4's accepted-XDO constraints."""

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
    fromlist=["_apply_step4_xdo_constraint"],
)
_handlers = __import__(
    f"{_pkg_name}.communications.evaluators.handlers",
    fromlist=["_handle_xdo"],
)

InnerGameState = _state.InnerGameState
_apply_step4_xdo_constraint = _trial._apply_step4_xdo_constraint
_handle_xdo = _handlers._handle_xdo


OWN = 1  # ENG in the canonical AUS, ENG, FRA, GER, ITA, RUS, TUR ordering
SRC = 10
DEST = 20
OTHER = 30
CANDIDATES = [(100.0, DEST), (80.0, OTHER), (60.0, SRC)]


def test_step4_move_collapses_candidates_to_mapped_destination():
    state = InnerGameState()
    state.g_xdo_order_move_by_power[OWN] = {SRC: DEST}

    assert _apply_step4_xdo_constraint(
        state, OWN, OWN, SRC, CANDIDATES
    ) == [(100.0, DEST)]


def test_step4_hold_collapses_candidates_to_source():
    state = InnerGameState()
    state.g_xdo_order_hold_by_power[OWN] = {SRC}

    assert _apply_step4_xdo_constraint(
        state, OWN, OWN, SRC, CANDIDATES
    ) == [(60.0, SRC)]


def test_step4_skips_move_constraint_when_own_destination_unit_is_holding():
    state = InnerGameState()
    state.g_xdo_order_move_by_power[OWN] = {SRC: DEST}
    state.unit_info[DEST] = {'power': OWN, 'type': 'A', 'coast': ''}
    state.g_order_table[DEST, 0] = 1  # HLD

    assert _apply_step4_xdo_constraint(
        state, OWN, OWN, SRC, CANDIDATES
    ) == CANDIDATES


def test_step4_does_not_apply_another_powers_constraint():
    state = InnerGameState()
    state.g_xdo_order_move_by_power[OWN] = {SRC: DEST}

    assert _apply_step4_xdo_constraint(
        state, 2, OWN, SRC, CANDIDATES
    ) == CANDIDATES


def test_step4_leaves_candidates_when_proposed_destination_is_not_available():
    state = InnerGameState()
    state.g_xdo_order_move_by_power[OWN] = {SRC: 99}

    assert _apply_step4_xdo_constraint(
        state, OWN, OWN, SRC, CANDIDATES
    ) == CANDIDATES


def test_xdo_sup_mto_populates_step4_move_container():
    state = InnerGameState()
    state.prov_to_id = {'LON': SRC, 'PAR': OTHER, 'BUR': DEST}
    state.g_xdo_candidate_list = []
    tokens = [
        'XDO', '(',
        '(', 'ENG', 'AMY', 'LON', ')',
        'SUP', '(', 'ENG', 'AMY', 'PAR', ')', 'MTO', 'BUR',
        ')',
    ]

    assert _handle_xdo(state, tokens)
    assert state.g_xdo_order_move_by_power[OWN] == {OTHER: DEST}


def test_xdo_sup_hld_populates_step4_hold_container():
    state = InnerGameState()
    state.prov_to_id = {'LON': SRC, 'PAR': OTHER}
    state.g_xdo_candidate_list = []
    tokens = [
        'XDO', '(',
        '(', 'ENG', 'AMY', 'LON', ')',
        'SUP', '(', 'ENG', 'AMY', 'PAR', ')',
        ')',
    ]

    assert _handle_xdo(state, tokens)
    assert state.g_xdo_order_hold_by_power[OWN] == {OTHER}
