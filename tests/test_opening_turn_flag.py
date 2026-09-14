"""DAT_00baed68 is an opening-turn pulse, not a press-mode switch.

Pinned against Albert.exe: its only writers are GenerateAndSubmitOrders
0x00459548 (clear) and 0x00459557 (set from DAT_004c6bdc); DAT_004c6bdc is
initialised to 1 in .data (0x004c6bdc) and only cleared (0x0045955e).
"""

import os
import sys
from unittest.mock import patch


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state_mod = __import__(f'{_pkg_name}.state', fromlist=['InnerGameState'])
_client_mod = __import__(f'{_pkg_name}.bot.client', fromlist=['AlbertClient'])
_orders_mod = __import__(f'{_pkg_name}.bot.client._orders', fromlist=['_OrdersMixin'])

InnerGameState = _state_mod.InnerGameState
AlbertClient = _client_mod.AlbertClient


def test_pulse_is_armed_at_construction_and_fires_once():
    state = InnerGameState()
    assert state.g_press_flag == 0
    assert state.g_opening_turn_pending == 1

    flags = []
    for _ in range(3):
        _orders_mod._refresh_opening_turn_flag(state)
        flags.append(state.g_press_flag)

    assert flags == [1, 0, 0]
    assert state.g_opening_turn_pending == 0


def _generate_twice(minimal_press: int, history_counter: int) -> list[int]:
    client = AlbertClient('GERMANY', 'example.invalid', 8432)
    client.game = None
    state = client.state
    state.g_minimal_press_mode = minimal_press
    state.g_history_counter = history_counter
    state.g_position_orders_initialized = True
    state.g_game_over = True
    flags = []
    with (
        patch.object(_orders_mod, '_cleanup_turn', lambda _state: None),
        patch.object(AlbertClient, '_await_press_and_send_gof',
                     lambda self: flags.append(self.state.g_press_flag)),
        patch.object(AlbertClient, '_initialize_press_session', lambda self: None),
    ):
        client.generate_and_submit_orders()
        client.generate_and_submit_orders()
    return flags


def test_first_generation_is_the_opening_turn_in_no_press_games():
    # The port used to hold the flag at 0 whenever g_minimal_press_mode was set.
    assert _generate_twice(minimal_press=1, history_counter=0) == [1, 0]


def test_later_generations_clear_the_flag_in_press_games():
    # The port used to raise it on every turn once g_history_counter > 0.
    assert _generate_twice(minimal_press=0, history_counter=5) == [1, 0]
