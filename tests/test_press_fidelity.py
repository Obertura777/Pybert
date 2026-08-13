"""Regression coverage for source-backed press-port semantics."""

import os
import sys
from unittest.mock import patch


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state_mod = __import__(f'{_pkg_name}.state', fromlist=['InnerGameState'])
_tokens_mod = __import__(f'{_pkg_name}.communications.tokens', fromlist=['_token_seq_equal'])
_press_mod = __import__(f'{_pkg_name}.communications.evaluators.press', fromlist=['evaluate_press'])
_evals_mod = __import__(f'{_pkg_name}.communications.evaluators._evals', fromlist=['_eval_single_xdo'])
_handlers_mod = __import__(f'{_pkg_name}.communications.evaluators.handlers', fromlist=['cal_move'])
_respond_mod = __import__(f'{_pkg_name}.communications.inbound.respond', fromlist=['receive_proposal'])
_ack_mod = __import__(f'{_pkg_name}.communications.inbound.ack', fromlist=['ack_matcher'])
_scheduling_mod = __import__(f'{_pkg_name}.communications.scheduling', fromlist=['dispatch_scheduled_press'])
_senders_mod = __import__(f'{_pkg_name}.communications.senders', fromlist=['cancel_prior_press'])
_parsers_mod = __import__(f'{_pkg_name}.communications.parsers', fromlist=['_parse_xdo_candidates'])
_gof_mod = __import__(f'{_pkg_name}.bot.gof', fromlist=['_evaluate_order_proposals_and_send_gof'])

InnerGameState = _state_mod.InnerGameState


def test_token_sequence_helper_is_ordered_equality_not_set_overlap():
    assert _tokens_mod._token_seq_equal(['XDO', 'PAR'], ['XDO', 'PAR'])
    assert not _tokens_mod._token_seq_equal(['XDO', 'PAR'], ['XDO', 'BUR'])
    assert not _tokens_mod._token_seq_equal(['A', 'B'], ['B', 'A'])


def test_single_evaluator_reconstructs_wire_sublists():
    state = InnerGameState()
    state.albert_power_idx = 2  # FRA
    state.g_enemy_flag[:] = 0
    state.g_relation_score[:] = 0

    assert _evals_mod._eval_single_xdo(
        state, ['PCE', '(', 'ENG', 'FRA', ')'], from_power=1,
    ) == 0x481C
    assert _evals_mod._eval_single_xdo(
        state, ['NOT', '(', 'PCE', '(', 'ENG', 'FRA', ')', ')'],
        from_power=1,
    ) == 0x481C


def test_xdo_parser_preserves_not_wrapper_for_negative_clause_catalog():
    cands = _parsers_mod._parse_xdo_candidates(
        'AND ( XDO ( ( ENG AMY LON ) HLD ) ) '
        '( NOT ( XDO ( ( FRA AMY PAR ) HLD ) ) )'
    )
    assert cands[0]['tokens'][0] == 'XDO'
    assert cands[1]['tokens'][:3] == ['NOT', '(', 'XDO']
    assert cands[1]['tokens'][-1] == ')'


def test_xdo_parser_attaches_decoded_order_for_legitimacy_gate():
    cands = _parsers_mod._parse_xdo_candidates(
        'XDO ( ( ENG AMY LON ) HLD )'
    )
    assert cands == [{
        'tokens': ['XDO', '(', '(', 'ENG', 'AMY', 'LON', ')', 'HLD', ')'],
        'type_flag': 0,
        'power': 1,
        'order_seq': {'type': 'HLD', 'unit': 'A LON'},
    }]


def test_evaluate_press_clears_prior_accepts_and_uses_and_sublists():
    state = InnerGameState()
    state.albert_power_idx = 2
    state.g_enemy_flag[:] = 0
    state.g_relation_score[:] = 0
    state.g_accepted_proposals[:] = [['stale']]

    verdict = _press_mod.evaluate_press(state, {
        'from_power_tok': 0x4101,
        'sublist3': [
            'AND',
            '(', 'PCE', '(', 'ENG', 'FRA', ')', ')',
            '(', 'SLO', '(', 'FRA', ')', ')',
        ],
    })

    assert verdict == 0x481C
    assert ['stale'] not in state.g_accepted_proposals
    assert len(state.g_accepted_proposals) == 2


def test_context_sensitive_evaluators_use_recipients_plus_sender():
    state = InnerGameState()
    state.albert_power_idx = 2  # FRA

    # _eval_slo.c counts unique message participants, not SLO targets.
    assert _evals_mod._eval_slo(
        state, [['FRA']], from_power=1, context_powers=[2, 1],
    ) == 0x4814
    assert _evals_mod._eval_slo(
        state, [['FRA']], from_power=2, context_powers=[2, 2],
    ) == 0x481C

    # _eval_aly.c requires every ALY member to occur in recipients+sender.
    state.g_enemy_flag[3] = 1  # confirmed VSS enemy makes pair gate a no-op
    assert _evals_mod._eval_aly(
        state, [['FRA', 'ENG'], 'VSS', ['GER']],
        from_power=1, context_powers=[2, 1],
    ) == 0x481C
    assert _evals_mod._eval_aly(
        state, [['FRA', 'ENG'], 'VSS', ['GER']],
        from_power=1, context_powers=[1],
    ) == 0x4814


def test_dmz_evaluator_checks_every_message_participant():
    state = InnerGameState()
    state.albert_power_idx = 2  # FRA
    state.g_press_flag = 0
    for participant in (1, 3):
        state.g_ally_trust_score[2, participant] = 3
        state.g_ally_trust_score[participant, 2] = 1
        state.g_relation_score[2, participant] = 0

    state.g_order_list[:] = [{
        'province': 5, 'ally_power': 1, 'flag1': False, 'flag2': True,
    }]
    rest = [['FRA', 'ENG', 'GER'], [5]]
    assert _evals_mod._eval_dmz(
        state, rest, from_power=1, context_powers=[2, 1, 3],
    ) == 0x4814

    state.g_order_list.append({
        'province': 5, 'ally_power': 3, 'flag1': False, 'flag2': True,
    })
    assert _evals_mod._eval_dmz(
        state, rest, from_power=1, context_powers=[2, 1, 3],
    ) == 0x481C


def test_receive_proposal_copies_evaluate_press_accept_tree():
    state = InnerGameState()
    state.g_turn_start_time = 100.0
    state.g_accepted_proposals[:] = [
        ['PCE', ['ENG', 'FRA']],
        ['SLO', ['FRA']],
    ]

    with patch.object(_respond_mod._time, 'time', return_value=105.0):
        _respond_mod.receive_proposal(state, 1, ['AND', '...'])

    assert [e['tokens'] for e in state.g_pos_analysis_list[0]['press_entries']] == [
        ['PCE', ['ENG', 'FRA']],
        ['SLO', ['FRA']],
    ]
    assert 10005 in state.g_alliance_msg_tree


def test_received_proposal_dedup_includes_exact_participant_set():
    state = InnerGameState()
    tokens = ['PRP', '(', 'PCE', ')']

    _respond_mod.receive_proposal(
        state, 1, tokens, participant_powers=[2],
    )
    _respond_mod.receive_proposal(
        state, 1, tokens, participant_powers=[3],
    )
    _respond_mod.receive_proposal(
        state, 1, tokens, participant_powers=[2],
    )

    assert len(state.g_pos_analysis_list) == 2
    assert [entry['participant_powers'] for entry in state.g_pos_analysis_list] == [
        {1, 2}, {1, 3},
    ]


def test_proposal_becomes_actionable_only_after_every_participant_yes():
    state = InnerGameState()
    state.albert_power_idx = 2
    message = 'PRP ( PCE ( FRA ENG ) )'

    assert _senders_mod.propose(state, message, [1], lambda _message: None)
    entry = state.g_pos_analysis_list[0]
    assert entry['participant_powers'] == {1, 2}
    assert entry['role_b_set'] == {2}

    _gof_mod._evaluate_order_proposals_and_send_gof(state, lambda _message: None)
    assert not entry.get('processed', False)
    assert _scheduling_mod._fun_004117d0(state, 1)

    assert _ack_mod.ack_matcher(
        state, 1, _ack_mod._ACK_TOK_YES, proposal_tokens=message.split(),
    ) == 1
    _gof_mod._evaluate_order_proposals_and_send_gof(state, lambda _message: None)
    assert entry['processed'] is True
    assert entry['processed_flag'] == 1
    assert not _scheduling_mod._fun_004117d0(state, 1)


def test_cal_move_applies_parenthesized_pce():
    state = InnerGameState()
    state.albert_power_idx = 2
    changed = _handlers_mod.cal_move(
        state, ['PCE', '(', 'ENG', 'FRA', ')'],
    )
    assert changed
    assert state.g_ally_trust_score[1, 2] == 3
    assert state.g_ally_trust_score[2, 1] == 3


def test_cancel_prior_press_sends_fixed_not_gof_without_synthetic_token():
    state = InnerGameState()
    state.sc_count[0] = 1
    sent = []
    _senders_mod.cancel_prior_press(state, 0, sent.append)
    assert sent == ['NOT ( GOF )']
    assert state.g_cancel_press_sent == 1


def test_scheduled_dispatch_retains_callback_appended_thn_entry():
    state = InnerGameState()
    state.g_turn_start_time = 100.0
    state.g_master_order_list[:] = [{
        'scheduled_time': 1.0,
        'press_type': 'SND',
        'data': {'message': 'YES (...)', 'recipient': 'ENGLAND'},
        'target_power': 1,
    }]

    with (
        patch.object(_scheduling_mod._time, 'time', return_value=105.0),
        patch.object(_senders_mod._time, 'time', return_value=105.0),
        patch.object(_senders_mod._random, 'randint', return_value=0),
    ):
        _scheduling_mod.dispatch_scheduled_press(state, lambda _msg: None)

    assert len(state.g_master_order_list) == 1
    assert state.g_master_order_list[0]['press_type'] == 'THN'
    assert state.g_master_order_list[0]['data'] == [1]


def test_respond_uses_record_timestamp_not_current_wall_clock():
    state = InnerGameState()
    state.albert_power_idx = 2
    state.g_turn_start_time = 100
    state.g_press_instant = 1

    with patch.object(_respond_mod._time, 'time', return_value=999999.0):
        _respond_mod.respond(
            state,
            {'sublist1': [0x4101], 'sublist2': [0x4102], 'sublist3': ['PCE']},
            0x481C,
            elapsed_lo=105,
            elapsed_hi=0,
        )

    assert state.g_master_order_list[0]['scheduled_time'] == 5.0


def test_propose_records_tracking_entry_before_send_callback():
    state = InnerGameState()
    state.albert_power_idx = 2
    observed_lengths = []

    assert _senders_mod.propose(
        state,
        'PRP ( PCE ( FRA ENG ) )',
        [1],
        lambda _message: observed_lengths.append(len(state.g_pos_analysis_list)),
    )
    assert observed_lengths == [1]
