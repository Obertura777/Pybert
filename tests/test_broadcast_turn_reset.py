"""Movement-turn broadcast node reset chronology from send_GOF.c."""

import os
import sys


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state_mod = __import__(f'{_pkg_name}.state', fromlist=['InnerGameState'])
_orders_mod = __import__(
    f'{_pkg_name}.bot.client._orders',
    fromlist=[
        '_prepare_broadcast_nodes_for_movement',
        '_prepare_proposal_orders_for_turn',
    ],
)

InnerGameState = _state_mod.InnerGameState
prepare = _orders_mod._prepare_broadcast_nodes_for_movement
prepare_proposals = _orders_mod._prepare_proposal_orders_for_turn


def test_movement_broadcast_reset_normalizes_all_node_classes():
    state = InnerGameState()
    state.g_press_proposals_cap = 30
    prior_zero = {
        'key': 0, 'sent': True, 'type_flag': 1, 'trial_count': 17,
        'score_vector': [9] * 7, 'order_candidates': [{'tokens': ['XDO']}],
    }
    own = {'key': 2, 'sent': False, 'type_flag': 1, 'trial_count': 4}
    received = {'key': 3, 'sent': False, 'type_flag': 0, 'trial_count': 8}
    completed_received = {
        'key': 4, 'sent': True, 'type_flag': 0, 'trial_count': 12,
    }
    state.g_broadcast_list[:] = [prior_zero, own, received, completed_received]

    base = prepare(state)

    assert state.g_broadcast_list[0] is base
    for entry in (base, prior_zero):
        assert entry['sent'] is False
        assert entry['received_flag'] is False
        assert entry['type_flag'] == 0
        assert entry['trial_count'] == 0
        assert entry['score_vector'] == [0] * 7
        assert entry['order_candidates'] == [
            {'tokens': ['SUB'], 'type_flag': 0}
        ]
    assert own == {
        'key': 2, 'sent': True, 'type_flag': -1, 'trial_count': 30,
    }
    assert received == {
        'key': 3, 'sent': False, 'type_flag': 0, 'trial_count': 0,
    }
    assert completed_received == {
        'key': 4, 'sent': True, 'type_flag': 0, 'trial_count': 12,
    }


def test_no_press_leaves_process_turn_proposal_trees_empty():
    state = InnerGameState()
    state.g_minimal_press_mode = 1
    state.g_general_orders = {
        0: [{'type': 'MTO', 'tokens': ['stale']}],
        3: [{'type': 'HLD'}],
    }
    state.g_alliance_orders = {0: [{'type': 'SUP'}]}
    state.g_candidate_record_list = [{'power': 0}]
    state._candidate_key_map = {('stale',): state.g_candidate_record_list[0]}

    prepare_proposals(state)

    assert state.g_general_orders == {}
    assert state.g_alliance_orders == {}
    assert state.g_candidate_record_list == []
    assert not hasattr(state, '_candidate_key_map')
