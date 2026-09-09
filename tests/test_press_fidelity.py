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
_gate_mod = __import__(
    f'{_pkg_name}.communications.inbound.gate',
    fromlist=['register_received_press'],
)
_press_mod_sub = __import__(
    f'{_pkg_name}.bot.client._press',
    fromlist=['_advance_broadcast_proposal_trials'],
)
_ack_mod = __import__(f'{_pkg_name}.communications.inbound.ack', fromlist=['ack_matcher'])
_scheduling_mod = __import__(f'{_pkg_name}.communications.scheduling', fromlist=['dispatch_scheduled_press'])
_senders_mod = __import__(f'{_pkg_name}.communications.senders', fromlist=['cancel_prior_press'])
_parsers_mod = __import__(f'{_pkg_name}.communications.parsers', fromlist=['_parse_xdo_candidates'])
_gof_mod = __import__(f'{_pkg_name}.bot.gof', fromlist=['_evaluate_order_proposals_and_send_gof'])
_support_mod = __import__(
    f'{_pkg_name}.moves.support', fromlist=['build_support_proposals'])

InnerGameState = _state_mod.InnerGameState


def test_support_proposal_history_is_indexed_by_prospective_supporter():
    state = InnerGameState()
    requester = 2
    supporter_power = 3
    mover = 11
    supporter = 10
    destination = 12
    state.unit_info = {
        mover: {'power': requester, 'type': 'A', 'coast': ''},
        supporter: {'power': supporter_power, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix[supporter] = [destination]
    state.g_order_table[mover, 0] = 2
    state.g_order_table[mover, 2] = destination
    state.g_coverage_flag[0, destination] = 1
    state.g_coverage_flag[1, destination] = 1
    # A nonzero high word means this int64 designation is not power 3 even
    # though its low word is 3; it must not exclude the supporter.
    state.g_ally_designation_b[destination] = supporter_power
    state.g_ally_designation_b_hi[destination] = 1
    state.g_proposal_history_map = []

    _support_mod.build_support_proposals(state, requester)

    record = state.g_proposal_history_map[0]
    assert record['power'] == supporter_power
    assert record['province'] == supporter
    assert record['target_power'] == requester
    assert record['src_prov'] == mover
    assert record['dst_prov'] == destination
    assert state.g_xdo_press_sent[supporter_power, requester] == 1
    assert state.g_xdo_press_sent[requester, supporter_power] == 0


def test_one_threat_handshake_uses_completed_convoy_field_not_order_type():
    def run(order_type, convoy_state):
        state = InnerGameState()
        requester, supporter_power = 2, 3
        mover, supporter, destination = 11, 10, 12
        state.unit_info = {
            mover: {'power': requester, 'type': 'A', 'coast': ''},
            supporter: {'power': supporter_power, 'type': 'A', 'coast': ''},
        }
        state.g_order_table[mover, 0] = order_type
        state.g_order_table[mover, 2] = destination
        state.g_order_table[mover, 20] = convoy_state
        target = destination if order_type in (2, 6) else mover
        state.adj_matrix[supporter] = [target]
        state.g_coverage_flag[0, target] = 1
        _support_mod.build_support_proposals(state, requester)
        return state

    completed_move = run(order_type=2, convoy_state=5)
    assert len(completed_move.g_proposal_history_map) == 1
    assert completed_move.g_xdo_press_proposals[0]['type'] == 'SUB_HANDSHAKE'

    incomplete_convoy_order = run(order_type=5, convoy_state=0)
    assert incomplete_convoy_order.g_proposal_history_map == []
    assert incomplete_convoy_order.g_xdo_press_proposals == []


def test_support_history_map_deduplicates_across_handshake_and_xdo_branches():
    state = InnerGameState()
    requester, supporter_power = 2, 3
    mover, supporter, destination = 11, 10, 12
    state.unit_info = {
        mover: {'power': requester, 'type': 'A', 'coast': ''},
        supporter: {'power': supporter_power, 'type': 'A', 'coast': ''},
    }
    state.g_order_table[mover, 0] = 2
    state.g_order_table[mover, 2] = destination
    state.g_order_table[mover, 20] = 5
    state.adj_matrix[supporter] = [destination]
    state.g_coverage_flag[0, destination] = 1

    _support_mod.build_support_proposals(state, requester)
    state.g_coverage_flag[1, destination] = 1
    _support_mod.build_support_proposals(state, requester)

    assert len(state.g_proposal_history_map) == 1
    assert state.g_proposal_history_map[0]['score'] == 9
    assert [p['type'] for p in state.g_xdo_press_proposals] == [
        'SUB_HANDSHAKE',
    ]


def test_support_proposal_requires_supporters_typed_reach():
    state = InnerGameState()
    requester = 2
    supporter_power = 3
    mover = 11
    supporter = 10
    destination = 12
    state.unit_info = {
        mover: {'power': requester, 'type': 'F', 'coast': ''},
        supporter: {'power': supporter_power, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix[supporter] = [destination]
    state.water_provinces = {destination}
    state.g_order_table[mover, 0] = 2
    state.g_order_table[mover, 2] = destination
    state.g_coverage_flag[0, destination] = 1
    state.g_coverage_flag[1, destination] = 1
    state.g_proposal_history_map = []

    _support_mod.build_support_proposals(state, requester)

    assert state.g_proposal_history_map == []
    assert state.g_xdo_press_sent[supporter_power, requester] == 0


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


def test_sub_not_xdo_arm_is_dead_and_answers_huh():
    """_eval_single_xdo.c:238-243 never descends into the SUB/PRP NOT payload.

    The top-level NOT arm (line 131) runs GetSubList(input, 1) before
    re-testing element 0, so `NOT (XDO ...)` reaches CAL_VALUE.  The SUB/PRP
    arm only calls AppendList(local_48, input) and then re-reads element 0 of
    the same list, which is still NOT -- so `XDO != *psVar4` always holds and
    control jumps to LAB_0042c5e4 (HUH).  Albert therefore scores a bare
    `NOT (XDO ...)` but HUHs the identical clause wrapped in PRP.
    """
    state = InnerGameState()
    state.albert_power_idx = 2  # FRA

    wrapped = ['PRP', '(', 'NOT', '(', 'XDO', '(', '(', 'ENG', 'AMY', 'LON',
               ')', 'HLD', ')', ')', ')']
    assert _evals_mod._eval_single_xdo(state, wrapped, from_power=1) == 0x4806

    # The unwrapped form still reaches CAL_VALUE rather than HUH.
    bare = ['NOT', '(', 'XDO', '(', '(', 'ENG', 'AMY', 'LON', ')', 'HLD', ')',
            ')']
    assert _evals_mod._eval_single_xdo(state, bare, from_power=1) != 0x4806

    # SUB XDO remains the unconditional REJ of _eval_sub_xdo (FUN_0040d450).
    sub_xdo = ['PRP', '(', 'XDO', '(', '(', 'ENG', 'AMY', 'LON', ')', 'HLD',
               ')', ')']
    assert _evals_mod._eval_single_xdo(state, sub_xdo, from_power=1) == 0x4814


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


def test_xdo_parser_normalizes_daide_destination_coasts():
    candidates = _parsers_mod._parse_xdo_candidates(
        'XDO ( ( RUS FLT BOT ) MTO ( STP SCS ) ) '
        'XDO ( ( FRA FLT MAO ) SUP ( FRA FLT GAS ) '
        'MTO ( SPA NCS ) )'
    )

    assert candidates[0]['order_seq'] == {
        'type': 'MTO', 'unit': 'F BOT', 'target': 'STP', 'coast': 'SC',
    }
    assert candidates[1]['order_seq'] == {
        'type': 'SUP', 'unit': 'F MAO', 'target_unit': 'F GAS',
        'target_dest': 'SPA', 'target_coast': 'NC',
    }


def test_xdo_parser_resolves_nested_coast_in_unit_location():
    candidates = _parsers_mod._parse_xdo_candidates(
        'XDO ( ( RUS FLT ( STP SCS ) ) HLD )'
    )

    assert candidates[0]['order_seq'] == {'type': 'HLD', 'unit': 'F STP'}


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

    # _eval_slo.c sizes the set built from the SLO power sublist (local_4c),
    # not the participant set (local_40, never read).  YES iff the SLO names
    # exactly one distinct power and that power is Albert.
    assert _evals_mod._eval_slo(
        state, [['FRA']], from_power=1, context_powers=[2, 1],
    ) == 0x481C
    assert _evals_mod._eval_slo(
        state, [['FRA']], from_power=2, context_powers=[2, 2],
    ) == 0x481C
    # Someone else soloing is rejected regardless of the participant set.
    assert _evals_mod._eval_slo(
        state, [['ENG']], from_power=1, context_powers=[2, 1],
    ) == 0x4814
    # A two-power SLO fails the local_4c == 1 gate even though Albert occurs.
    assert _evals_mod._eval_slo(
        state, [['FRA', 'ENG']], from_power=1, context_powers=[2],
    ) == 0x4814
    # Repeated tokens collapse in the set, so FRA twice still passes.
    assert _evals_mod._eval_slo(
        state, [['FRA', 'FRA']], from_power=1, context_powers=[2, 1],
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


def test_not_dmz_ledger_gate_clears_on_absence_from_the_dmz_power_set():
    """_eval_not_dmz.c:203-208 clears bVar4 when the participant is ABSENT.

    ``piVar13[1] == ppiVar5`` compares the found node against the set's head
    sentinel, so it is the ``find() == end()`` test — the same idiom as
    _eval_aly.c:127, where the flag means "every ALY power was a
    participant".
    """
    def _run(dmz_powers):
        state = InnerGameState()
        state.albert_power_idx = 2                      # FRA
        state.g_ally_counter_list = {1: [{'dest_prov': 5}]}
        state.g_ally_promise_list = {1: [{'dest_prov': 5}]}
        return _evals_mod._eval_not_dmz(
            state, [dmz_powers, [5]], from_power=1, context_powers=[1],
        )

    # ENG is in both ledgers for province 5 but is not named in the DMZ, so
    # bVar4 clears and the verdict is REJ.
    assert _run(['GER']) == 0x4814
    # Naming ENG in the DMZ leaves bVar4 set, so the same ledgers give YES.
    assert _run(['ENG', 'FRA']) == 0x481C


def test_not_dmz_bwx_gate_counts_dmz_powers_not_participants():
    """The verdict block reads uVar10 = local_90 = len(DMZ power sublist).

    ``uVar9`` (the doubled participant count) only gates the ``>= 3`` early
    BWX; the sender-membership tests at _eval_not_dmz.c:255 and :265 are
    driven by the DMZ power list length.
    """
    def _run(dmz_powers, participants):
        state = InnerGameState()
        state.albert_power_idx = 2                      # FRA
        # Empty ledgers for the sender clear bVar3 and select the BWX path.
        state.g_ally_counter_list = {}
        state.g_ally_promise_list = {}
        return _evals_mod._eval_not_dmz(
            state, [dmz_powers, [5]], from_power=1,
            context_powers=participants,
        )

    # One DMZ power that is not the sender → BWX.
    assert _run(['GER'], [1]) == 0x4A02
    # One DMZ power that IS the sender → falls through to YES.
    assert _run(['ENG'], [1]) == 0x481C
    # Two DMZ powers including the sender → falls through to YES.
    assert _run(['ENG', 'GER'], [1]) == 0x481C
    # Two DMZ powers excluding the sender → BWX.
    assert _run(['GER', 'ITA'], [1]) == 0x4A02
    # An empty DMZ power list never reaches either membership test.
    assert _run([], [1]) == 0x481C
    # Two participants double to four, tripping the uVar9 >= 3 early BWX
    # before the DMZ list is consulted at all.
    assert _run(['ENG'], [1, 3]) == 0x4A02


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


def test_execute_aly_vss_deduplicates_exact_offer_across_phase_resets():
    state = InnerGameState()
    state.albert_power_idx = 2  # FRA
    state.g_press_flag = 1
    state.g_mutual_enemy_table[3] = 5  # GER target, RUS enemy
    state.g_influence_rank_flag[2, 3] = 0
    sent = []

    assert _scheduling_mod._execute_aly_vss(state, 3, send_fn=sent.append)
    assert sent == [{
        'message': 'PRP ( ALY ( FRA GER ) VSS ( RUS ) )',
        'recipient': 'GERMANY',
    }]
    assert state.g_aly_proposal_history == {(2, 3, 5)}

    # Simulate the transient structures being reset for a later phase.  The
    # persistent exact-offer history must still suppress the blind repeat.
    state.g_pos_analysis_list.clear()
    state.g_ally_matrix.fill(0)

    assert not _scheduling_mod._execute_aly_vss(state, 3, send_fn=sent.append)
    assert len(sent) == 1


def test_execute_aly_vss_allows_changed_mutual_enemy():
    state = InnerGameState()
    state.albert_power_idx = 2  # FRA
    state.g_press_flag = 1
    state.g_influence_rank_flag[2, 3] = 0
    state.g_mutual_enemy_table[3] = 5
    sent = []

    assert _scheduling_mod._execute_aly_vss(state, 3, send_fn=sent.append)

    state.g_pos_analysis_list.clear()
    state.g_ally_matrix.fill(0)
    state.g_mutual_enemy_table[3] = 6  # strategic enemy changed to TUR

    assert _scheduling_mod._execute_aly_vss(state, 3, send_fn=sent.append)
    assert [entry['message'] for entry in sent] == [
        'PRP ( ALY ( FRA GER ) VSS ( RUS ) )',
        'PRP ( ALY ( FRA GER ) VSS ( TUR ) )',
    ]
    assert state.g_aly_proposal_history == {(2, 3, 5), (2, 3, 6)}


def test_execute_xdo_consumes_support_history_and_validates_recipient_power():
    state = InnerGameState()
    state.albert_power_idx = 2  # FRA
    state._id_to_prov = {10: 'KIE', 11: 'BUR', 12: 'MUN'}
    state.unit_info = {
        10: {'power': 3, 'type': 'A'},
        11: {'power': 2, 'type': 'A'},
    }
    state.g_xdo_press_proposals[:] = [{
        'type': 'XDO_SUP', 'priority': 4,
        'from_power': 2, 'to_power': 3,
        'supporter_prov': 10, 'mover_prov': 11, 'dest': 12,
    }]
    sent = []

    with patch.object(
            _scheduling_mod, 'validate_and_dispatch_order', return_value=0,
    ) as validate:
        _scheduling_mod._execute_xdo(state, 3, send_fn=sent.append)

    validate.assert_called_once_with(
        state,
        3,
        {
            'type': 'SUP', 'unit': 'A KIE',
            'target_unit': 'A BUR', 'target_dest': 'MUN',
            'target_coast': '',
        },
        commit=False,
    )
    assert sent == [{
        'message': (
            'PRP ( XDO ( ( GER AMY KIE ) SUP '
            '( FRA AMY BUR ) MTO MUN ) )'
        ),
        'recipient': 'GERMANY',
    }]
    assert state.g_pos_analysis_list[0]['participant_powers'] == {2, 3}


def test_execute_xdo_rejects_other_movers_and_wrong_recipient():
    state = InnerGameState()
    state.albert_power_idx = 2
    state._id_to_prov = {10: 'KIE', 11: 'BUR', 12: 'MUN'}
    state.unit_info = {
        10: {'power': 3, 'type': 'A'},
        11: {'power': 0, 'type': 'A'},
    }
    state.g_xdo_press_proposals[:] = [{
        'type': 'XDO_SUP', 'priority': 4,
        'from_power': 0, 'to_power': 3,
        'supporter_prov': 10, 'mover_prov': 11, 'dest': 12,
    }]
    sent = []
    _scheduling_mod._execute_xdo(state, 3, send_fn=sent.append)
    assert sent == []

    state.g_xdo_press_proposals[0]['from_power'] = 2
    with patch.object(
            _scheduling_mod, 'validate_and_dispatch_order', return_value=0,
    ) as validate:
        _scheduling_mod._execute_xdo(state, 1, send_fn=sent.append)
    validate.assert_not_called()
    assert sent == []


def test_then_action_reaches_generated_xdo_for_strong_trust_pair():
    state = InnerGameState()
    state.albert_power_idx = 2
    state.g_history_counter = 20
    state.g_press_history = {3: {_scheduling_mod._TOK_XDO}}
    state.g_ally_trust_score[2, 3] = 3
    state.g_ally_trust_score[3, 2] = 3
    state._id_to_prov = {10: 'KIE', 11: 'BUR', 12: 'MUN'}
    state.unit_info = {
        10: {'power': 3, 'type': 'A'},
        11: {'power': 2, 'type': 'A'},
    }
    state.g_xdo_press_proposals[:] = [{
        'type': 'XDO_SUP', 'priority': 4,
        'from_power': 2, 'to_power': 3,
        'supporter_prov': 10, 'mover_prov': 11, 'dest': 12,
    }]
    sent = []

    with patch.object(
            _scheduling_mod, 'validate_and_dispatch_order', return_value=0,
    ):
        _scheduling_mod._execute_then_action(state, 3, send_fn=sent.append)

    assert sent == [{
        'message': (
            'PRP ( XDO ( ( GER AMY KIE ) SUP '
            '( FRA AMY BUR ) MTO MUN ) )'
        ),
        'recipient': 'GERMANY',
    }]


def test_execute_xdo_survives_staging_clear_via_persistent_history():
    state = InnerGameState()
    state.albert_power_idx = 2
    state._id_to_prov = {10: 'KIE', 11: 'BUR', 12: 'MUN'}
    state.unit_info = {
        10: {'power': 3, 'type': 'A'},
        11: {'power': 2, 'type': 'A'},
    }
    state.g_xdo_press_proposals.clear()
    state.g_proposal_history_map = [{
        'key': 10011012,
        'type': 'XDO_SUP', 'score': 4,
        'from_power': 2, 'to_power': 3,
        'supporter_prov': 10, 'mover_prov': 11, 'dest': 12,
    }]
    sent = []

    with patch.object(
            _scheduling_mod, 'validate_and_dispatch_order', return_value=0,
    ):
        _scheduling_mod._execute_xdo(state, 3, send_fn=sent.append)

    assert sent[0]['recipient'] == 'GERMANY'
    assert sent[0]['message'].startswith('PRP ( XDO')


def test_propose_dmz_decodes_c_flags_and_tracks_the_proposal():
    state = InnerGameState()
    state.albert_power_idx = 2  # FRA
    state._id_to_prov = {10: 'BUR', 11: 'MUN'}
    state.g_dmz_aggressiveness = 0
    state.g_order_list[:] = [
        {
            'power': 3, 'province': 10, 'score': 2, 'done': False,
            'flag1': True, 'flag2': True, 'flag3': False,
        },
        {
            'power': 3, 'province': 11, 'score': 3, 'done': False,
            'flag1': True, 'flag2': True, 'flag3': False,
        },
    ]
    sent = []

    assert _senders_mod.propose_dmz(state, 3, send_fn=sent.append)

    assert sent == [{
        'message': 'PRP ( DMZ ( FRA GER ) BUR MUN )',
        'recipient': 'GERMANY',
    }]
    assert all(entry['done'] for entry in state.g_order_list)
    assert state.g_pos_analysis_list[0]['tokens'] == (
        'PRP ( DMZ ( FRA GER ) BUR MUN )'.split()
    )


def test_cal_value_scores_only_nodes_whose_record_flag_byte_is_set():
    """CAL_VALUE.c:341 gates on `*(char *)(puVar24 + 6) != '\\0'`.

    The map node holds _Myval = pair<Key(8B), Record> at node+0x10, so
    node+0x18 is record +0x00 -- the byte senders.py documents as
    `node+24 / node[6]` and the port carries as `sent`.  A received entry is
    only scorable once that byte is set: either register_received_press
    admitted it through the legitimacy gate, or BuildAndSendSUB.c:386 marked
    it finished.  `received_flag` was a third alias for the same byte, set
    unconditionally.

    Also covers the matched path itself, which raised NameError on
    `matched_index` -- the debug call evaluates its arguments eagerly, so
    every successful match crashed.
    """
    toks = ['XDO', '(', '(', 'ENG', 'AMY', 'LON', ')', 'HLD', ')']

    def _run(sent):
        state = InnerGameState()
        state.albert_power_idx = 2
        state.g_broadcast_list[:] = [{
            'sent': sent,
            'received_flag': True,
            'type_flag': 0,
            'order_candidates': [{'tokens': list(toks), 'type_flag': 0}],
            'score_vector': [0] * 7,
            'target_power': 1,
        }]
        before = len(state.g_alliance_msg_tree)
        verdict = _evals_mod._cal_value(state, toks)
        # The no-match arm archives through BuildAllianceMsg before returning.
        return verdict, len(state.g_alliance_msg_tree) > before

    verdict, unmatched = _run(False)
    assert unmatched is True
    assert verdict == 0x4814

    verdict, unmatched = _run(True)
    assert unmatched is False
    assert verdict == 0x481C


def test_gated_proposal_enters_the_broadcast_list_already_at_the_trial_cap():
    """local_1cc is record +0x08 -- BuildAndSendSUB's puVar18[8].

    register_received_press.c:150-158 stores DAT_004c6bbc there when the
    legitimacy gate returns non-null, and BuildAndSendSUB.c:220 breaks out of
    the trial loop on `DAT_004c6bbc <= puVar18[8]`.  A gated proposal is
    therefore inserted already at the cap and runs no trials.
    """
    def _run(gate_score):
        state = InnerGameState()
        state.g_press_proposals_cap = 30
        with patch.object(_gate_mod, 'legitimacy_gate', return_value=gate_score):
            _gate_mod.register_received_press(
                state, ['PCE', '(', 'ENG', 'FRA', ')'], 0x4101, [0x4102],
            )
        return state.g_broadcast_list

    gated = _run(5)
    assert all(e['history_flag'] == 1 for e in gated)
    assert all(e['trial_count'] == 30 for e in gated)
    # The two keys must not disagree: they were one C dword.
    assert all('int_8' not in e for e in gated)
    # local_1d4[0] is record +0x00 = the byte BuildAndSendSUB.c:215 gates on,
    # so a gated proposal is enqueued already flagged and runs no trials.
    assert all(e['sent'] is True for e in gated)
    # ...but it is still answerable: RESPOND sits outside the sent guard.
    assert all(e['received_flag'] is True and e['type_flag'] == 0
               for e in gated)

    ungated = _run(0)
    assert all(e['history_flag'] == 0 for e in ungated)
    assert all(e['trial_count'] == 0 for e in ungated)
    assert all(e['sent'] is False for e in ungated)


def test_broadcast_node_at_the_cap_runs_no_trials():
    """BuildAndSendSUB.c:220 breaks before the first iteration."""
    state = InnerGameState()
    state.g_unit_count[0] = 1
    ran = []
    with (
        patch.object(_press_mod_sub, 'update_score_state',
                     lambda _s: ran.append('update')),
        patch.object(_press_mod_sub, 'check_time_limit', return_value=False),
    ):
        completed = _press_mod_sub._advance_broadcast_proposal_trials(
            state, {'trial_count': 30}, 30,
        )
    assert completed is True
    assert ran == []


def test_propose_dmz_first_pass_requires_flag3_clear():
    """ProposeDMZ.c:110-111 reads flag3, not an active-DMZ lookup.

    Iterator_GetData returns node+0xc, so its +0x12 is node+0x1e — the same
    byte the two single-province arms read directly at :216 and :243.
    """
    def _run(flag3):
        state = InnerGameState()
        state.albert_power_idx = 2
        state._id_to_prov = {10: 'BUR', 11: 'MUN'}
        state.g_dmz_aggressiveness = 0
        state.g_order_list[:] = [
            {'power': 3, 'province': p, 'score': 2, 'done': False,
             'flag1': True, 'flag2': True, 'flag3': flag3}
            for p in (10, 11)
        ]
        sent = []
        return _senders_mod.propose_dmz(state, 3, send_fn=sent.append), sent

    ok, sent = _run(False)
    assert ok and sent[0]['message'] == 'PRP ( DMZ ( FRA GER ) BUR MUN )'
    # flag3 set blocks the multi-province pass and both single-province arms.
    ok, sent = _run(True)
    assert not ok and sent == []


def test_propose_dmz_tracks_proposals_in_the_active_dmz_list():
    """The send-count records live in g_active_dmz_list (DAT_00bb7130/34).

    Fields are {power (+0), province (+4), count (+8)}; FUN_00419df0 inserts
    with count 1 and the single-province arms increment to a cap of 2.
    """
    state = InnerGameState()
    state.albert_power_idx = 2
    state._id_to_prov = {10: 'BUR', 11: 'MUN'}
    state.g_dmz_aggressiveness = 0
    state.g_order_list[:] = [
        {'power': 3, 'province': p, 'score': 2, 'done': False,
         'flag1': True, 'flag2': True, 'flag3': False}
        for p in (10, 11)
    ]
    assert _senders_mod.propose_dmz(state, 3, send_fn=lambda _m: None)
    assert state.g_active_dmz_list == [
        {'power': 3, 'province': 10, 'count': 1},
        {'power': 3, 'province': 11, 'count': 1},
    ]

    # A pre-existing record excludes the province from the multi-province pass.
    state2 = InnerGameState()
    state2.albert_power_idx = 2
    state2._id_to_prov = {10: 'BUR', 11: 'MUN'}
    state2.g_dmz_aggressiveness = 0
    state2.g_active_dmz_list = [{'power': 3, 'province': 10, 'count': 1}]
    state2.g_order_list[:] = [
        {'power': 3, 'province': p, 'score': 2, 'done': False,
         'flag1': True, 'flag2': True, 'flag3': False}
        for p in (10, 11)
    ]
    sent = []
    assert _senders_mod.propose_dmz(state2, 3, send_fn=sent.append)
    # Only MUN survived the first pass, so the single-province arm fires and
    # BUR's existing record is bumped rather than duplicated.
    assert sent[0]['message'] == 'PRP ( DMZ ( FRA GER ) BUR )'
    assert state2.g_active_dmz_list == [{'power': 3, 'province': 10, 'count': 2}]


def test_propose_dmz_aborts_when_the_send_count_is_already_capped():
    """ProposeDMZ.c:331 — bVar2 with count >= 2 jumps to LAB_004334b0.

    That exit leaves the success byte unset and returns; it does not fall
    through to the next order-list entry.
    """
    state = InnerGameState()
    state.albert_power_idx = 2
    state._id_to_prov = {10: 'BUR', 11: 'MUN'}
    state.g_dmz_aggressiveness = 0
    state.g_active_dmz_list = [{'power': 3, 'province': 10, 'count': 2}]
    state.g_order_list[:] = [
        {'power': 3, 'province': 10, 'score': 2, 'done': False,
         'flag1': True, 'flag2': True, 'flag3': False},
        {'power': 3, 'province': 11, 'score': 3, 'done': False,
         'flag1': True, 'flag2': True, 'flag3': False},
    ]
    sent = []
    assert not _senders_mod.propose_dmz(state, 3, send_fn=sent.append)
    assert sent == []
    # MUN is never reached, so it acquires no record.
    assert state.g_active_dmz_list == [{'power': 3, 'province': 10, 'count': 2}]


def test_propose_dmz_marking_loop_covers_every_matching_order_entry():
    """C re-walks the whole order list per province (ProposeDMZ.c:257-283)."""
    state = InnerGameState()
    state.albert_power_idx = 2
    state._id_to_prov = {10: 'BUR', 11: 'MUN'}
    state.g_dmz_aggressiveness = 0
    duplicate = {'power': 3, 'province': 10, 'score': 1, 'done': False,
                 'flag1': False, 'flag2': False, 'flag3': False}
    state.g_order_list[:] = [
        {'power': 3, 'province': 10, 'score': 2, 'done': False,
         'flag1': True, 'flag2': True, 'flag3': False},
        {'power': 3, 'province': 11, 'score': 3, 'done': False,
         'flag1': True, 'flag2': True, 'flag3': False},
        duplicate,
    ]
    assert _senders_mod.propose_dmz(state, 3, send_fn=lambda _m: None)
    # The duplicate never qualified on its own flags but shares (power, prov).
    assert duplicate['done'] is True


def test_propose_dmz_excludes_existing_counter_designation():
    state = InnerGameState()
    state.albert_power_idx = 2
    state._id_to_prov = {10: 'BUR'}
    state.g_dmz_aggressiveness = 0
    state.g_ally_counter_list = {3: [{'dest_prov': 10}]}
    state.g_order_list[:] = [{
        'ally_power': 3, 'province': 10, 'score': 2, 'done': False,
        'flag1': True, 'flag2': True, 'flag3': False,
    }]
    sent = []

    assert not _senders_mod.propose_dmz(state, 3, send_fn=sent.append)
    assert sent == []


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
