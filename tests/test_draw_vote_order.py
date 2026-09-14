"""GenerateAndSubmitOrders sends its draw vote before send_GOF.

Pinned against the decompilation: GenerateAndSubmitOrders.c:482-521 calls
PrepareDrawVoteSet, sends DRW or NOT ( DRW ) and sets DAT_00baed5d, then runs
NormalizeInfluenceMatrix and send_GOF.
"""

import os
import sys
from unittest.mock import patch


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_client_mod = __import__(f'{_pkg_name}.bot.client', fromlist=['AlbertClient'])
_orders_mod = __import__(f'{_pkg_name}.bot.client._orders', fromlist=['_OrdersMixin'])

AlbertClient = _client_mod.AlbertClient


def test_draw_vote_is_sent_before_send_gof():
    client = AlbertClient('GERMANY', 'example.invalid', 8432)
    client.game = object()
    state = client.state
    state.g_minimal_press_mode = 1
    state.g_position_orders_initialized = True
    state.g_season = 'SPR'
    events = []

    def stub(name):
        return lambda *args, **kwargs: events.append(name)

    def draw_vote_set(draw_state):
        events.append('prepare_draw_vote_set')
        draw_state.g_draw_sent = 1

    monte_carlo = __import__(f'{_pkg_name}.monte_carlo', fromlist=['generate_orders'])
    names = ['_phase_handler', '_analyze_position', '_move_analysis',
             '_post_process_orders', '_compute_press', '_stabbed', '_deviate_move',
             '_friendly', '_post_friendly_update', '_insert_base_broadcast_node',
             '_hostility', '_cleanup_turn', 'cancel_prior_press']
    patches = [patch.object(_orders_mod, n, stub(n)) for n in names]
    patches += [
        patch.object(_orders_mod, '_prepare_draw_vote_set', draw_vote_set),
        patch.object(monte_carlo, 'generate_orders', stub('generate_orders')),
        patch.object(AlbertClient, '_submit_draw_vote', lambda self: events.append('DRW')),
        patch.object(AlbertClient, '_send_gof_pass', lambda self, *a: events.append('send_GOF')),
    ]
    for p in patches:
        p.start()
    try:
        client.generate_and_submit_orders()
    finally:
        for p in reversed(patches):
            p.stop()

    tail = [e for e in events if e in ('prepare_draw_vote_set', 'DRW', '_cleanup_turn', 'send_GOF')]
    assert tail == ['prepare_draw_vote_set', 'DRW', '_cleanup_turn', 'send_GOF']
