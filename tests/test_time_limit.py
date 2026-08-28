"""Move-time deadline lifecycle regression tests."""

import os
import sys
from unittest.mock import patch


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state = __import__(f'{_pkg_name}.state', fromlist=['InnerGameState'])
_trial = __import__(f'{_pkg_name}.monte_carlo.trial', fromlist=['check_time_limit'])
_orders = __import__(
    f'{_pkg_name}.bot.client._orders', fromlist=['_begin_turn_timing']
)

InnerGameState = _state.InnerGameState
check_time_limit = _trial.check_time_limit
_begin_turn_timing = _orders._begin_turn_timing


def test_begin_turn_rearms_deadline_and_clears_prior_expiry():
    state = InnerGameState()
    state.g_move_time_limit_sec = 90
    state.mtl_expired = 1
    state.g_turn_deadline = 12.0

    _begin_turn_timing(state, now=1000.0)

    assert state.g_turn_start_time == 1000.0
    assert state.g_turn_deadline == 1090.0
    assert state.mtl_expired == 0


def test_begin_turn_disarms_deadline_when_server_has_no_mtl():
    state = InnerGameState()
    state.g_move_time_limit_sec = 0
    state.g_turn_deadline = 12.0

    _begin_turn_timing(state, now=1000.0)

    assert state.g_turn_deadline == 0.0


def test_check_time_limit_latches_wall_clock_deadline():
    state = InnerGameState()
    state.g_turn_deadline = 100.0

    with patch(f'{_pkg_name}.monte_carlo.trial.time.time', return_value=99.9):
        assert check_time_limit(state) is False
    with patch(f'{_pkg_name}.monte_carlo.trial.time.time', return_value=100.0):
        assert check_time_limit(state) is True

    assert state.mtl_expired == 1
    # Once latched, no further wall-clock access is necessary.
    with patch(
        f'{_pkg_name}.monte_carlo.trial.time.time',
        side_effect=AssertionError('clock should not be read after expiry'),
    ):
        assert check_time_limit(state) is True


def test_explicit_external_timeout_still_takes_precedence():
    state = InnerGameState()
    state.mtl_expired = 1
    state.g_turn_deadline = 10_000.0

    assert check_time_limit(state) is True
