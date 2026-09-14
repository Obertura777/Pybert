"""Binary-backed regressions for Albert's inbound press lifecycle.

Each test pins behaviour read from the Albert.exe decompilation:

* FRM handler FUN_0045a2f0, DELAY_REVIEW 0x00438e60, FUN_00431310
* FUN_0042c970 (reply matcher), HUH 0x0042cd70, FUN_0040d4d0 (HUH/TRY reply)
* RECEIVE_PROPOSAL 0x00431fe0, RESPOND 0x004216f0, PROPOSE
* EvaluateOrderProposalsAndSendGOF 0x00457520, FUN_0045a090 (own YES
  delivered), ScheduledPressDispatch 0x004424e0, ParseHSTResponse 0x0041b410
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
_state_mod = __import__(f'{_pkg_name}.state', fromlist=['InnerGameState'])
_frm_mod = __import__(f'{_pkg_name}.communications.inbound.frm', fromlist=['parse_message'])
_gate_mod = __import__(f'{_pkg_name}.communications.inbound.gate', fromlist=['delay_review'])
_ack_mod = __import__(f'{_pkg_name}.communications.inbound.ack', fromlist=['ack_matcher'])
_respond_mod = __import__(f'{_pkg_name}.communications.inbound.respond', fromlist=['respond'])
_history_mod = __import__(f'{_pkg_name}.communications.inbound.history', fromlist=['process_hst'])
_yes_mod = __import__(
    f'{_pkg_name}.communications.inbound.yes_handlers',
    fromlist=['handle_own_press_delivered'],
)
_tokens_mod = __import__(f'{_pkg_name}.communications.tokens', fromlist=['_c_sublist'])
_senders_mod = __import__(f'{_pkg_name}.communications.senders', fromlist=['propose'])
_scheduling_mod = __import__(
    f'{_pkg_name}.communications.scheduling', fromlist=['dispatch_scheduled_press'])
_gof_mod = __import__(f'{_pkg_name}.bot.gof', fromlist=['_evaluate_order_proposals_and_send_gof'])
_evals_mod = __import__(f'{_pkg_name}.communications.evaluators._evals', fromlist=['_cal_value'])
_rng = __import__(f'{_pkg_name}.rng', fromlist=['seed'])

InnerGameState = _state_mod.InnerGameState

ENG, FRA, GER = 1, 2, 3
XDO_BODY = "XDO ( ( ENG AMY LON ) MTO WAL )"
XDO_PRP = f"PRP ( {XDO_BODY} )"


def _press_state(season: str = 'SPR') -> InnerGameState:
    state = InnerGameState()
    state.albert_power_idx = FRA
    state.g_season = season
    state.g_history_counter = 100
    state.g_press_instant = 1
    state.g_turn_start_time = time.time()
    return state


def _tokens(text: str) -> list:
    return _tokens_mod._wire_tokens(text)


def _queued_snd(state) -> list:
    return [e['data'] for e in state.g_master_order_list if e['press_type'] == 'SND']


# ── Token primitives ──────────────────────────────────────────────────────────

def test_token_equality_is_false_for_empty_lists():
    """FUN_00465d90 returns false when either buffer is null."""
    assert not _tokens_mod._token_seq_equal([], [])
    assert not _tokens_mod._token_seq_equal(['PRP'], [])


def test_getsublist_returns_group_interiors_and_single_tokens():
    content = _tokens("YES ( PRP ( PCE ( ENG FRA ) ) )")
    assert _tokens_mod._c_sublist(content, 0) == ['YES']
    assert _tokens_mod._c_sublist(content, 1) == _tokens("PRP ( PCE ( ENG FRA ) )")
    assert _tokens_mod._c_sublist(content, 2) == []


# ── FRM handler ───────────────────────────────────────────────────────────────

def test_proposal_before_press_level_is_answered_with_huh_and_try():
    """0x0045a4d7: PRP needs g_HistoryCounter > 0; otherwise FUN_0040d4d0."""
    state = _press_state()
    state.g_history_counter = 0
    state.g_allowed_press_token_list = ['YES', 'REJ', 'BWX']
    sent = []

    _frm_mod.parse_message(state, 'ENGLAND', 'PRP ( PCE ( ENG FRA ) )', send_fn=sent.append)

    assert sent[:2] == [
        {'message': 'HUH ( ERR PRP ( PCE ( ENG FRA ) ) )', 'recipient': 'ENGLAND'},
        {'message': 'TRY ( YES REJ BWX )', 'recipient': 'ENGLAND'},
    ]
    assert state.g_pos_analysis_list == []


def test_unknown_press_token_gets_huh_and_try_but_huh_and_try_do_not():
    state = _press_state()
    sent = []
    _frm_mod.parse_message(state, 'ENGLAND', 'FCT ( PCE ( ENG FRA ) )', send_fn=sent.append)
    assert [m['message'] for m in sent[:1]] == ['HUH ( ERR FCT ( PCE ( ENG FRA ) ) )']

    sent.clear()
    _frm_mod.parse_message(state, 'ENGLAND', 'TRY ( PCE ALY )', send_fn=sent.append)
    assert sent == []
    assert state.g_press_history[ENG] == {0x4A10, 0x4A00}


def test_non_xdo_proposal_is_answered_at_once_and_never_registered():
    """DELAY_REVIEW returns 0 without FUN_00431310 when no clause is XDO."""
    state = _press_state()
    sent = []

    _frm_mod.parse_message(state, 'ENGLAND', 'PRP ( PCE ( ENG FRA ) )', send_fn=sent.append)

    assert state.g_broadcast_list == []
    assert sent[0] == {'message': 'YES ( PRP ( PCE ( ENG FRA ) ) )', 'recipient': 'ENGLAND'}
    record = state.g_pos_analysis_list[0]
    assert record['tokens'] == _tokens('PRP ( PCE ( ENG FRA ) )')
    assert record['participant_powers'] == {ENG, FRA}


def test_undecided_xdo_proposal_is_registered_and_left_unanswered_in_spring():
    """Score 0 → delayed; SPR/FAL send nothing, BuildAndSendSUB answers later."""
    state = _press_state('SPR')
    sent = []
    with patch.object(_gate_mod, 'legitimacy_gate', return_value=0):
        _frm_mod.parse_message(state, 'ENGLAND', XDO_PRP, send_fn=sent.append)

    assert sent == []
    assert state.g_pos_analysis_list == []
    first, second = state.g_broadcast_list
    assert (first['sent'], second['sent']) == (False, False)
    assert (first['flag'], second['flag']) == (0, 1)
    assert (first['registration_pass'], second['registration_pass']) == (1, 2)
    assert second['watermark'] == first['key']
    assert state.g_broadcast_list_watermark == second['key']
    assert first['sublist3'] == _tokens(XDO_PRP)


def test_undecided_xdo_proposal_is_rejected_outside_spring_and_fall():
    """0x0045a5ea: season not SPR and not FAL → RESPOND(REJ); SUM included."""
    for season in ('SUM', 'AUT', 'WIN'):
        state = _press_state(season)
        sent = []
        with patch.object(_gate_mod, 'legitimacy_gate', return_value=0):
            _frm_mod.parse_message(state, 'ENGLAND', XDO_PRP, send_fn=sent.append)
        assert sent[0] == {'message': f'REJ ( {XDO_PRP} )', 'recipient': 'ENGLAND'}, season
        assert len(state.g_broadcast_list) == 2


def test_decided_xdo_proposal_is_registered_flagged_and_answered_at_once():
    state = _press_state('SPR')
    sent = []
    with (
        patch.object(_gate_mod, 'legitimacy_gate', return_value=7),
        patch.object(_evals_mod, '_cal_value', return_value=0x4814),
    ):
        _frm_mod.parse_message(state, 'ENGLAND', XDO_PRP, send_fn=sent.append)

    assert all(entry['sent'] for entry in state.g_broadcast_list)
    assert sent[0] == {'message': f'REJ ( {XDO_PRP} )', 'recipient': 'ENGLAND'}


def test_repeated_undecided_proposal_matches_the_live_record():
    """DELAY_REVIEW's catalog walk: an unflagged record with the same set A /
    set B stops the walk — nothing is registered and the answer is immediate."""
    state = _press_state('SPR')
    sent = []
    with (
        patch.object(_gate_mod, 'legitimacy_gate', return_value=0),
        patch.object(_evals_mod, '_cal_value', return_value=0x4814),
    ):
        _frm_mod.parse_message(state, 'ENGLAND', XDO_PRP, send_fn=sent.append)
        assert sent == []
        _frm_mod.parse_message(state, 'GERMANY', XDO_PRP, send_fn=sent.append)

    assert len(state.g_broadcast_list) == 2
    assert sent[0] == {'message': f'REJ ( {XDO_PRP} )', 'recipient': 'GERMANY'}


def test_orr_proposal_registers_the_whole_set_once_per_clause():
    """0x0043985c: FUN_00431310 per candidate, each with the full set; only
    the last second-pass record carries the flag; the maximum score counts."""
    state = _press_state('SPR')
    other = "XDO ( ( ENG FLT LON ) MTO NTH )"
    content = f"PRP ( ORR ( {XDO_BODY} ) ( {other} ) )"
    scores = iter([0, 0])
    with patch.object(_gate_mod, 'legitimacy_gate', side_effect=lambda *a, **k: next(scores)):
        delayed = _gate_mod.delay_review(state, _tokens(content), ENG, [FRA])

    assert delayed is True
    assert [e['flag'] for e in state.g_broadcast_list] == [0, 0, 0, 1]
    assert all(len(e['order_candidates']) == 2 for e in state.g_broadcast_list)


def test_orr_orientation_and_register_return_value():
    state = _press_state('SPR')
    with patch.object(_gate_mod, 'legitimacy_gate', return_value=-40):
        score = _gate_mod.register_received_press(
            state, _tokens(XDO_PRP), 0x4101, [0x4102], flag=1,
        )
    assert score == -40
    first, second = state.g_broadcast_list
    plain = {XDO_BODY}
    assert _gate_mod._entry_clause_sets(first) == (set(), plain)
    assert _gate_mod._entry_clause_sets(second) == (plain, set())


# ── Replies ───────────────────────────────────────────────────────────────────

def _own_proposal(state, message=None, recipients=(ENG,)):
    message = message or 'PRP ( PCE ( FRA ENG ) )'
    assert _senders_mod.propose(state, message, list(recipients), lambda _m: None)
    return state.g_pos_analysis_list[-1]


def test_rejection_marks_responded_and_rejected_and_retires_the_proposal():
    """FUN_0042c970: any non-YES reply goes into +0x3c and +0x48 and clears
    the clause list; EvaluateOrderProposalsAndSendGOF then retires the node
    without CAL_MOVE."""
    state = _press_state()
    record = _own_proposal(state)
    assert record['press_entries'] == [{'tokens': _tokens('PCE ( FRA ENG )')}]

    scheduled = []
    with (
        patch.object(_gof_mod, '_send_gof') as send_gof,
        patch.object(_senders_mod, 'send_ally_press_by_power',
                     side_effect=lambda _state, power: scheduled.append(power)),
    ):
        _frm_mod.parse_message(
            state, 'ENGLAND', 'REJ ( PRP ( PCE ( FRA ENG ) ) )', send_fn=lambda _m: None,
        )

    assert record['role_b_set'] == {FRA, ENG}
    assert record['role_c_set'] == {ENG}
    assert record['press_entries'] == []
    assert record['processed_flag'] == 1
    send_gof.assert_not_called()
    assert state.g_ally_trust_score[ENG, FRA] == 0
    # SendAllyPressByPower(sender) runs for a reply from another power.
    assert scheduled == [ENG]


def test_acceptance_applies_the_own_proposal_clause():
    state = _press_state()
    record = _own_proposal(state)
    with patch.object(_gof_mod, '_send_gof'):
        _frm_mod.parse_message(
            state, 'ENGLAND', 'YES ( PRP ( PCE ( FRA ENG ) ) )', send_fn=lambda _m: None,
        )
    assert record['processed_flag'] == 1
    assert state.g_ally_trust_score[ENG, FRA] == 3
    assert state.g_ally_trust_score[FRA, ENG] == 3


def test_reply_without_the_proposal_body_matches_nothing():
    state = _press_state()
    record = _own_proposal(state)
    assert _ack_mod.ack_matcher(state, ENG, _ack_mod._ACK_TOK_YES, []) == 0
    assert record['role_b_set'] == {FRA}


def test_peer_huh_counts_as_a_rejection():
    """HUH (0x0042cd70) replays the ERR-stripped body with token HUH."""
    state = _press_state()
    record = _own_proposal(state)
    with patch.object(_gof_mod, '_send_gof'):
        _frm_mod.parse_message(
            state, 'ENGLAND', 'HUH ( ERR PRP ( PCE ( FRA ENG ) ) )', send_fn=lambda _m: None,
        )
    assert record['role_c_set'] == {ENG}
    assert record['processed_flag'] == 1


def test_err_strip_reproduces_the_lagging_index_quirk():
    assert _ack_mod._strip_err_tokens(['ERR', 'A', 'B']) == ['A', 'B']
    assert _ack_mod._strip_err_tokens(['A', 'ERR', 'B']) == ['A', 'B']
    # Second ERR: the test reads the output index, so it looks at 'B' and
    # copies the ERR through while dropping the final token.
    assert _ack_mod._strip_err_tokens(['A', 'ERR', 'B', 'ERR', 'C']) == ['A', 'B', 'ERR']


def test_unmatched_yes_to_an_acceptable_proposal_is_recorded_with_albert():
    """0x0045a714: EvaluatePress, RECEIVE_PROPOSAL(sender), then
    FUN_0042c970(proposal, own power, YES)."""
    state = _press_state()
    with patch.object(_gof_mod, '_send_gof'):
        _frm_mod.parse_message(
            state, 'ENGLAND', 'YES ( PRP ( PCE ( ENG FRA ) ) )', send_fn=lambda _m: None,
        )
    record = state.g_pos_analysis_list[0]
    assert record['tokens'] == _tokens('PRP ( PCE ( ENG FRA ) )')
    assert record['role_b_set'] == {ENG, FRA}
    assert record['processed_flag'] == 1


# ── RESPOND ───────────────────────────────────────────────────────────────────

def test_huh_verdict_sends_huh_and_try_and_queues_nothing():
    state = _press_state()
    state.g_allowed_press_token_list = ['YES', 'REJ']
    content = _tokens('PRP ( PCE ( ENG FRA ) )')
    _respond_mod.receive_proposal(state, ENG, content, participant_powers=[FRA])
    sent = []

    _respond_mod.respond(
        state,
        {'sublist1': [0x4101], 'sublist2': [0x4102], 'sublist3': content},
        0x4806, elapsed_lo=int(time.time()), send_fn=sent.append,
    )

    assert sent == [
        {'message': 'HUH ( ERR PRP ( PCE ( ENG FRA ) ) )', 'recipient': 'ENGLAND'},
        {'message': 'TRY ( YES REJ )', 'recipient': 'ENGLAND'},
    ]
    assert _queued_snd(state) == []
    assert state.g_pos_analysis_list[0]['role_c_set'] == {FRA}


def test_rejection_adds_albert_to_the_rejection_set_not_a_side_table():
    state = _press_state()
    content = _tokens('PRP ( PCE ( ENG FRA ) )')
    _respond_mod.receive_proposal(state, ENG, content, participant_powers=[FRA])

    _respond_mod.respond(
        state,
        {'sublist1': [0x4101], 'sublist2': [0x4102, 0x4103], 'sublist3': content},
        0x4814, elapsed_lo=int(time.time()),
    )

    assert state.g_pos_analysis_list[0]['role_c_set'] == {FRA}
    assert state.g_deviation_tree == {}
    (data,) = _queued_snd(state)
    # local_2c: the sender, then every recipient that is not Albert.
    assert data['recipients'] == ['ENGLAND', 'GERMANY']


def test_deceit_gate_draws_randoms_only_after_the_trust_test():
    """RESPOND's && chain: no rand() unless the trust test holds."""
    state = _press_state()
    state.g_enemy_flag[ENG] = 1
    state.g_ally_trust_score[ENG, FRA] = 5
    state.g_press_thresh_random = 50
    content = _tokens('PRP ( PCE ( ENG FRA ) )')
    _rng.seed(1)
    _respond_mod.respond(
        state,
        {'sublist1': [0x4101], 'sublist2': [0x4102], 'sublist3': content},
        0x4814, elapsed_lo=int(time.time()),
    )
    assert _rng.getstate() == 1
    (data,) = _queued_snd(state)
    assert data['message'] == 'YES ( PRP ( PCE ( ENG FRA ) ) )'


# ── Proposal completion and delivery ─────────────────────────────────────────

def test_xdo_clause_sees_the_responded_powers():
    """FUN_00405090 hands CAL_MOVE a copy of the responded set (+0x3c)."""
    state = _press_state()
    state.g_pos_analysis_list.append({
        'tokens': _tokens(XDO_PRP),
        'participant_powers': {ENG, FRA},
        'role_b_set': {ENG, FRA},
        'role_c_set': set(),
        'processed_flag': 0,
        'press_entries': [{'tokens': _tokens(XDO_BODY)}],
    })
    seen = []

    def fake_cal_move(_state, _tokens_arg):
        seen.append(list(_state.g_xdo_candidate_list))
        return False

    with patch(f'{_pkg_name}.communications.cal_move', side_effect=fake_cal_move):
        _gof_mod._evaluate_order_proposals_and_send_gof(state, lambda _m: None)

    assert seen == [[{'power': ENG}, {'power': FRA}]]


def test_delivered_own_yes_credits_albert_and_evaluates():
    """FUN_0045a090 on YES ( SND ... ( YES ( PRP ... ) ) )."""
    state = _press_state()
    content = _tokens('PRP ( PCE ( ENG FRA ) )')
    state.g_pos_analysis_list.append({
        'tokens': content,
        'participant_powers': {ENG, FRA},
        'role_b_set': {ENG},
        'role_c_set': set(),
        'processed_flag': 0,
        'press_entries': [],
    })
    _yes_mod.handle_own_press_delivered(state, 'YES ( PRP ( PCE ( ENG FRA ) ) )')
    assert state.g_pos_analysis_list[0]['role_b_set'] == {ENG, FRA}
    assert state.g_pos_analysis_list[0]['processed_flag'] == 1


def test_dispatch_confirms_delivered_yes_after_the_dispatch_finishes():
    state = _press_state()
    content = _tokens('PRP ( PCE ( ENG FRA ) )')
    state.g_pos_analysis_list.append({
        'tokens': content,
        'participant_powers': {ENG, FRA},
        'role_b_set': {ENG},
        'role_c_set': set(),
        'processed_flag': 0,
        'press_entries': [],
    })
    state.g_master_order_list.append({
        'scheduled_time': 0.0,
        'press_type': 'SND',
        'data': {'message': 'YES ( PRP ( PCE ( ENG FRA ) ) )', 'recipient': 'ENGLAND'},
        'target_powers': [ENG],
    })

    _scheduling_mod.dispatch_scheduled_press(state, lambda _m: None)

    assert state.g_pos_analysis_list[0]['role_b_set'] == {ENG, FRA}
    assert state.g_press_delivery_queue == []
    assert state.g_press_dispatch_depth == 0


def test_undelivered_yes_is_not_confirmed():
    state = _press_state()
    content = _tokens('PRP ( PCE ( ENG FRA ) )')
    state.g_pos_analysis_list.append({
        'tokens': content, 'participant_powers': {ENG, FRA},
        'role_b_set': {ENG}, 'role_c_set': set(), 'processed_flag': 0,
        'press_entries': [],
    })
    state.g_master_order_list.append({
        'scheduled_time': 0.0, 'press_type': 'SND',
        'data': {'message': 'YES ( PRP ( PCE ( ENG FRA ) ) )', 'recipient': 'ENGLAND'},
        'target_powers': [ENG],
    })
    _scheduling_mod.dispatch_scheduled_press(state, lambda _m: False)
    assert state.g_pos_analysis_list[0]['role_b_set'] == {ENG}


def test_dispatch_schedules_thn_for_each_message_s_own_recipients():
    """local_58 is assigned per SND (AppendList is operator=), not accumulated;
    and pruning THN entries must not leave the dispatcher on a stale list."""
    state = _press_state()
    state.g_master_order_list.extend([
        {'scheduled_time': 0.0, 'press_type': 'SND',
         'data': {'message': 'REJ ( PRP ( PCE ( ENG FRA ) ) )', 'recipient': 'ENGLAND'},
         'target_powers': [ENG]},
        {'scheduled_time': 0.0, 'press_type': 'SND',
         'data': {'message': 'REJ ( PRP ( PCE ( GER FRA ) ) )', 'recipient': 'GERMANY'},
         'target_powers': [GER]},
    ])
    sent = []
    scheduled = []
    real = _senders_mod.send_ally_press_by_power

    def spy(current, power):
        scheduled.append(power)
        real(current, power)

    with patch.object(_senders_mod, 'send_ally_press_by_power', side_effect=spy):
        _scheduling_mod.dispatch_scheduled_press(state, sent.append)

    assert [m['recipient'] for m in sent] == ['ENGLAND', 'GERMANY']
    assert scheduled == [ENG, GER]
    thn = [e['data'] for e in state.g_master_order_list if e['press_type'] == 'THN']
    assert thn == [[ENG], [GER]]
    assert _queued_snd(state) == []


def test_propose_records_its_body_as_the_clause_and_the_proposal_time():
    state = _press_state()
    state.g_turn_start_time = time.time() - 42
    record = _own_proposal(state, 'PRP ( ALY ( FRA ENG ) VSS ( GER ) )')
    assert record['press_entries'] == [{'tokens': _tokens('ALY ( FRA ENG ) VSS ( GER )')}]
    assert 41 <= state.g_base_wait_time <= 43


# ── HLO press setup ───────────────────────────────────────────────────────────

def test_hlo_press_token_list_uses_ccl_and_assigns_the_last_block():
    state = InnerGameState()
    state.albert_power_idx = 3
    with patch.object(_history_mod._time, 'time', return_value=1_000_000.0):
        _history_mod.process_hst(state, 'LVL 100')
    assert state.g_allowed_press_token_list == [
        'YES', 'REJ', 'BWX', 'NOT', 'CCL', 'SLO', 'DRW',
        'PRP', 'PCE', 'DMZ', 'ALY', 'VSS', 'XDO', 'AND', 'ORR',
    ]
    assert 0x4A26 in state.g_press_history[0]

    # srand(time + own_power * 1000) precedes the two DAT_004c6bd4 draws.
    _rng.seed(1_000_000 + 3 * 1000)
    expected = _rng.randrange(50) + _rng.randrange(50)
    assert state.g_press_thresh_random == expected

    minimal = InnerGameState()
    minimal.g_minimal_press_mode = 1
    _history_mod.process_hst(minimal, 'LVL 100')
    assert minimal.g_history_counter == 0
    assert minimal.g_allowed_press_token_list == ['YES', 'REJ', 'BWX']


def test_press_threshold_feeds_proposedmz_as_quarter_minus_four():
    state = InnerGameState()
    state.g_press_thresh_random = 50
    assert int(state.g_press_thresh_random / 4) - 4 == 8


def test_cal_value_scores_the_second_pass_record_against_the_first():
    """CAL_VALUE.c:225-357 matches plain clauses against set A, so of the two
    FUN_00431310 records only the second-pass one matches; its reference key
    names the first-pass record, whose score is the subtraction baseline."""
    state = _press_state('SPR')
    state.g_broadcast_list.append({'key': 0, 'sent': True, 'type_flag': 0,
                                   'order_candidates': [{'tokens': ['SUB'], 'type_flag': 0}]})
    with patch.object(_gate_mod, 'legitimacy_gate', return_value=5):
        _gate_mod.register_received_press(state, _tokens(XDO_PRP), 0x4101, [0x4102], flag=1)
    _, first, second = state.g_broadcast_list
    first['score_vector'] = [5000] * 7
    second['score_vector'] = [4000] * 7

    with patch(f'{_pkg_name}.communications.legitimacy_gate', return_value=0):
        verdict = _evals_mod._cal_value(state, _tokens(XDO_BODY))

    # delta = 4000 - 5000 = -1000 lies in [-89999, -199): REJ.  Scoring the
    # first-pass record without a baseline would have given 5000: YES.
    assert verdict == 0x4814
