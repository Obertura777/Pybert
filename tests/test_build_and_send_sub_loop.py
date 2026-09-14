"""BuildAndSendSUB node loop, proposal records and press lifecycle hooks.

Pinned against the Albert.exe decompilation: BuildAndSendSUB 0x00457890,
ScoreOrderCandidates 0x004559c0, send_GOF 0x00456b50, FUN_00459280,
AwaitPressAndSendGOF 0x00443ed0, XDO 0x00420630.
"""

import os
import sys
import time
from unittest.mock import patch


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_client_mod = __import__(f"{_pkg_name}.bot.client", fromlist=["AlbertClient"])
_press_mod = __import__(f"{_pkg_name}.bot.client._press", fromlist=["_PressMixin"])
_orders_mod = __import__(f"{_pkg_name}.bot.client._orders", fromlist=["_OrdersMixin"])
_senders_mod = __import__(
    f"{_pkg_name}.communications.senders",
    fromlist=["score_order_candidates_from_broadcast"],
)
_handlers_mod = __import__(
    f"{_pkg_name}.communications.evaluators.handlers", fromlist=["cal_move"])
_trial_mod = __import__(f"{_pkg_name}.monte_carlo.trial", fromlist=["_ORDER_SUP_MTO"])

AlbertClient = _client_mod.AlbertClient

AUS, ENG, FRA, GER, ITA = 0, 1, 2, 3, 4


def _client() -> AlbertClient:
    client = AlbertClient("AUSTRIA", "example.invalid", 8432)
    client.state.albert_power_idx = AUS
    client.game = None
    return client


# ── Node completion ───────────────────────────────────────────────────────────

def test_finished_node_scores_participants_from_candidate_records():
    """BuildAndSendSUB.c:395-470."""
    client = _client()
    state = client.state
    state.albert_power_idx = AUS
    # puVar5[9] is the live score, puVar5[0x16] the ranker's weight.
    state.g_candidate_record_list = [
        {'power': AUS, 'score': 1000, 'base_score': 1, 'weight': 0.5, 'output_score': 9},
        {'power': AUS, 'score': 400, 'weight': 0.25},
        {'power': AUS, 'score': 9999, 'weight': 0.0, 'output_score': 50},
        {'power': ITA, 'score': 777, 'weight': -1.0},
        {'power': GER, 'score': 300, 'weight': 1.0},
    ]
    node = {'key': 2, 'flag': 0, 'type_flag': 1, 'participant_powers': {AUS, ITA},
            'score_vector': [5] * 7}
    client._finish_broadcast_node(node, 7)
    assert node['sent'] is True
    # AUS: 1000*0.5 + 400*0.25 = 600; ITA: no positive output -> -1000000;
    # GER is not a participant and keeps its value.
    assert node['score_vector'] == [600, 5, 5, 5, -1000000, 5, 5]

    base = {'key': 0, 'flag': 0, 'type_flag': 0,
            'participant_powers': set(range(7)), 'score_vector': [5] * 7}
    client._finish_broadcast_node(base, 7)
    assert base['score_vector'][ITA] == 0
    assert base['score_vector'][GER] == 300


# ── ScoreOrderCandidates for one node ─────────────────────────────────────────

def test_node_scoring_uses_set_a_and_runs_process_turn_for_those_powers():
    """ScoreOrderCandidates.c:96-340: general orders from set A only, the
    SUP-MTO supported move for the supported power, then ProcessTurn."""
    state = client_state = _client().state
    state.albert_power_idx = AUS
    state.g_unit_count[:] = 0
    state.g_unit_count[ITA] = 2
    state.g_unit_count[AUS] = 3
    state.g_general_orders = {GER: [{'type': 'stale'}]}
    support = ['XDO', '(', '(', 'ITA', 'AMY', 'VEN', ')', 'SUP',
               '(', 'AUS', 'AMY', 'VIE', ')', 'MTO', 'TYR', ')']
    node = {'key': 3, 'clause_set_a': [support],
            'clause_set_b': [['XDO', '(', '(', 'GER', 'AMY', 'MUN', ')', 'HLD', ')']]}
    runs = []
    with patch(f"{_pkg_name}.monte_carlo.process_turn",
               side_effect=lambda _s, power, num_trials: runs.append((power, num_trials))):
        inserted = _senders_mod.score_order_candidates_from_broadcast(state, node)

    assert inserted == 2
    assert state.g_general_orders == {
        ITA: [{'type': 'SUP', 'unit': 'A VEN', 'target_unit': 'A VIE',
               'target_dest': 'TYR', 'target_coast': ''}],
        AUS: [{'type': 'MTO', 'unit': 'A VIE', 'target': 'TYR', 'coast': ''}],
    }
    # (units * 260 + 10) // 10 trials, powers in index order.
    assert runs == [(AUS, 79), (ITA, 53)]
    assert client_state.g_alliance_orders == {}


def test_agreed_xdo_feeds_the_first_process_turn_pass():
    """XDO() inserts the body into DAT_00bb65f8[unit power]."""
    state = _client().state
    state.albert_power_idx = AUS
    changed = _handlers_mod.cal_move(
        state, ['XDO', '(', '(', 'ITA', 'AMY', 'VEN', ')', 'MTO', 'TYR', ')'])
    assert changed
    assert state.g_alliance_orders[ITA] == [
        {'type': 'MTO', 'unit': 'A VEN', 'target': 'TYR', 'coast': ''}]


# ── Proposal records ──────────────────────────────────────────────────────────

def _history_state():
    client = _client()
    state = client.state
    state.albert_power_idx = AUS
    state.g_press_proposals_cap = 30
    state.prov_to_id = {'VIE': 12, 'VEN': 71, 'TYR': 5, 'MUN': 9}
    state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}
    state.unit_info = {
        12: {'power': AUS, 'type': 'A'},
        71: {'power': ITA, 'type': 'A'},
        9: {'power': GER, 'type': 'A'},
    }
    state.g_ally_designation_a[:] = -1
    state.g_ally_designation_a_hi[:] = -1
    state.g_ally_designation_b[:] = -1
    state.g_ally_designation_b_hi[:] = -1
    state.g_ally_designation_c[:] = -1
    state.g_ally_designation_c_hi[:] = -1
    state.g_proposal_history_map = [
        # ITA asked to support AUS VIE -> TYR: Albert is the mover.
        {'type': 'XDO_SUP', 'power': ITA, 'province': 71, 'target_power': AUS,
         'src_prov': 12, 'dst_prov': 5},
        # GER asked likewise; GER does not trust Albert.
        {'type': 'XDO_SUP', 'power': GER, 'province': 9, 'target_power': AUS,
         'src_prov': 12, 'dst_prov': 5},
        # A one-threat SUB handshake is never proposed.
        {'power': ITA, 'province': 71, 'target_power': AUS,
         'src_prov': 12, 'dst_prov': 5},
    ]
    state.g_ally_trust_score[ITA, AUS] = 3
    return client, state


def test_proposal_records_follow_the_history_map_gates():
    """BuildAndSendSUB.c:648-1195."""
    client, state = _history_state()
    with patch.object(_press_mod, 'validate_and_dispatch_order', return_value=0):
        client._insert_proposal_records()

    base, record = state.g_broadcast_list
    assert base['sublist3'] == ['SUB'] and base['type_flag'] == 1
    assert base['watermark'] is None
    assert record['sublist3'] == ['XDO', '(', '(', 'ITA', 'AMY', 'VEN', ')', 'SUP',
                                  '(', 'AUS', 'AMY', 'VIE', ')', 'MTO', 'TYR', ')']
    assert record['clause_set_a'] == [record['sublist3']]
    assert record['participant_powers'] == {AUS, ITA}
    assert record['watermark'] == base['key']
    assert state.g_broadcast_list_watermark == record['key']
    # FUN_00422a90 == 0 leaves the record for the trials, and files it in N0.
    assert record['sent'] is False and record['trial_count'] == 0
    assert base['clause_set_b'] == [record['sublist3']]
    assert base['participant_powers'] == {AUS, ITA}
    assert base['sent'] is False


def test_decided_proposal_record_is_done_and_n0_without_set_b_is_retired():
    client, state = _history_state()
    with patch.object(_press_mod, 'validate_and_dispatch_order', return_value=-5):
        client._insert_proposal_records()
    base, record = state.g_broadcast_list
    assert record['sent'] is True and record['trial_count'] == 30
    assert record['score_vector'] == [-5] * 7
    assert base['clause_set_b'] == []
    assert base['sent'] is True and base['trial_count'] == 30


def test_designated_destination_trusted_by_the_supporter_scores_minus_200000():
    client, state = _history_state()
    state.g_ally_designation_b[5] = GER
    state.g_ally_designation_b_hi[5] = 0
    state.g_ally_trust_score[ITA, GER] = 3
    with patch.object(_press_mod, 'validate_and_dispatch_order', return_value=0) as check:
        client._insert_proposal_records()
    record = state.g_broadcast_list[1]
    assert record['score_vector'] == [-200000] * 7
    check.assert_not_called()


def test_albert_offers_a_support_only_when_it_already_plans_it_three_times():
    client, state = _history_state()
    state.g_proposal_history_map = [
        {'type': 'XDO_SUP', 'power': AUS, 'province': 12, 'target_power': ITA,
         'src_prov': 71, 'dst_prov': 5},
    ]
    state.g_ally_trust_score[AUS, ITA] = 3
    sup = (12, _trial_mod._ORDER_SUP_MTO, 5, 0, 71)
    state.g_current_best_order = {AUS: [[sup]] * 2 + [[]] * 28}
    with patch.object(_press_mod, 'validate_and_dispatch_order', return_value=0):
        client._insert_proposal_records()
    assert len(state.g_broadcast_list) == 1

    state.g_broadcast_list.clear()
    state.g_current_best_order = {AUS: [[sup]] * 3 + [[]] * 27}
    with patch.object(_press_mod, 'validate_and_dispatch_order', return_value=0) as check:
        client._insert_proposal_records()
    record = state.g_broadcast_list[1]
    # The partner is the mover, and the order is checked as that power.
    assert record['participant_powers'] == {AUS, ITA}
    assert check.call_args.args[1] == ITA


# ── The node loop ─────────────────────────────────────────────────────────────

def test_node_loop_submits_once_snapshots_at_the_base_and_restarts():
    client, state = _history_state()
    state.g_history_counter = 100
    state.g_press_proposals_cap = 1
    state.g_baed6d = 0
    base = {'key': 0, 'sent': False, 'type_flag': 0, 'trial_count': 0,
            'participant_powers': set(range(7))}
    state.g_broadcast_list[:] = [base]
    calls = []

    def trials(_state, node, cap, dispatch_fn=None):
        calls.append(('trials', node.get('key')))
        node['trial_count'] = cap
        return True

    with (
        patch.object(_press_mod, '_advance_broadcast_proposal_trials', side_effect=trials),
        patch.object(_press_mod, 'check_time_limit', return_value=False),
        patch.object(_press_mod, 'validate_and_dispatch_order', return_value=0),
        patch.object(AlbertClient, '_submit_sub_orders',
                     lambda self, _best: calls.append('submit')),
        patch.object(AlbertClient, '_await_press_and_send_gof',
                     lambda self: calls.append('await')),
        patch.object(AlbertClient, '_answer_delayed_proposal', lambda self, _e: None),
    ):
        state.g_current_best_order = {AUS: [['base-orders']]}
        client._build_and_send_sub([])

    # Base trials, submission, proposal records inserted (N0 + one record,
    # both unfinished), restart, their trials, then AwaitPressAndSendGOF.
    assert calls == [('trials', 0), 'submit', ('trials', 1), ('trials', 2), 'await']
    assert state.g_baed6d == 1
    assert state.g_best_order_backup == {AUS: [['base-orders']]}


def test_per_message_hook_reenters_build_and_send_sub_only_while_it_is_live():
    """FUN_00459280."""
    client = _client()
    seen = []
    with (
        patch.object(AlbertClient, '_build_and_send_sub',
                     lambda self, best: seen.append('sub')),
        patch.object(AlbertClient, '_await_press_and_send_gof',
                     lambda self: seen.append('await')),
    ):
        client.state.g_baed46 = 1
        client._after_inbound_message()
        client.state.g_baed46 = 0
        client._after_inbound_message()
        client.state.g_game_over = True
        client._after_inbound_message()
    assert seen == ['sub', 'await']


def test_await_sends_gof_only_after_a_not_gof_and_once_press_settles():
    client = _client()
    state = client.state
    state.albert_power_idx = AUS
    state.g_turn_start_time = time.time()
    sent = []
    client._send_dm = sent.append
    rechecks = []
    client._schedule_gof_recheck = lambda delay: rechecks.append(round(delay))

    client._await_press_and_send_gof()
    assert sent == []

    state.g_cancel_press_sent = 1
    state.g_pos_analysis_list.append({
        'tokens': ['PRP'], 'participant_powers': {AUS, ENG},
        'role_b_set': {AUS}, 'processed_flag': 0,
    })
    client._await_press_and_send_gof()
    assert sent == [] and rechecks == [25]

    state.g_base_wait_time = -30.0
    client._await_press_and_send_gof()
    assert sent == ['GOF']
    assert state.g_cancel_press_sent == 0


def test_send_gof_pass_arms_build_and_send_sub_for_a_movement_phase():
    client = _client()
    state = client.state
    state.albert_power_idx = AUS
    state.g_unit_count[AUS] = 3
    state.g_baed6d = 1
    seen = []
    with (
        patch.object(_orders_mod, '_run_send_gof_candidate_pass', return_value=[]),
        patch.object(AlbertClient, '_build_and_send_sub',
                     lambda self, best: seen.append((self.state.g_baed46, self.state.g_baed6d))),
    ):
        client._send_gof_pass('SPR', AUS, 7)
    assert seen == [(1, 0)]
