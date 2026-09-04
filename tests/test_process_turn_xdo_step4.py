"""Regression tests for ProcessTurn Step 4's accepted-XDO constraints."""

import os
import sys
from unittest.mock import patch


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state = __import__(f"{_pkg_name}.state", fromlist=["InnerGameState"])
_trial = __import__(
    f"{_pkg_name}.monte_carlo.trial",
    fromlist=[
        "_apply_proposal_support_candidate",
        "_apply_step4_xdo_constraint",
        "_build_negotiated_province_context",
        "_reset_trial_proximity_score",
        "_secondary_exploit_enabled",
        "_select_secondary_exploit_target",
    ],
)
_handlers = __import__(
    f"{_pkg_name}.communications.evaluators.handlers",
    fromlist=["_handle_xdo"],
)

InnerGameState = _state.InnerGameState
_apply_step4_xdo_constraint = _trial._apply_step4_xdo_constraint
_apply_proposal_support_candidate = (
    _trial._apply_proposal_support_candidate
)
_build_negotiated_province_context = (
    _trial._build_negotiated_province_context
)
_reset_trial_proximity_score = _trial._reset_trial_proximity_score
_secondary_exploit_enabled = _trial._secondary_exploit_enabled
_select_secondary_exploit_target = _trial._select_secondary_exploit_target
_handle_xdo = _handlers._handle_xdo


OWN = 1  # ENG in the canonical AUS, ENG, FRA, GER, ITA, RUS, TUR ordering
SRC = 10
DEST = 20
OTHER = 30
CANDIDATES = [(100.0, DEST), (80.0, OTHER), (60.0, SRC)]


def test_trial_proximity_reset_restores_sentinel_and_unit_cells():
    state = InnerGameState()
    state.g_proximity_score.fill(47)
    state.unit_info = {
        SRC: {'power': OWN, 'type': 'A'},
        OTHER: {'power': 3, 'type': 'F'},
    }

    _reset_trial_proximity_score(state, 7, 64)

    assert state.g_proximity_score[OWN, SRC] == 0
    assert state.g_proximity_score[3, OTHER] == 0
    assert state.g_proximity_score[OWN, DEST] == -1
    assert state.g_proximity_score[6, 63] == -1
    # Out-of-runtime columns are untouched, matching the bounded C loop.
    assert state.g_proximity_score[0, 64] == 47


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


def test_process_turn_context_uses_dmz_and_canonical_xdo_maps():
    state = InnerGameState()
    state.g_ally_promise_list = {
        0: [{'dest_prov': SRC}],
        2: [{'dest_prov': OTHER}],
    }
    state.g_enemy_flag[2] = 1
    state.g_xdo_order_move_by_power = {OWN: {SRC: DEST}}

    reachable, xdo_maps = _build_negotiated_province_context(
        state, OWN, OWN, 7
    )

    assert reachable == {SRC: True}
    assert xdo_maps[OWN] == {SRC: DEST}


def test_process_turn_context_uses_trusted_powers_dmz_counter_map():
    state = InnerGameState()
    foreign = 2
    state.g_ally_counter_list = {foreign: [{'dest_prov': DEST}]}
    state.g_relation_score[OWN, foreign] = 10

    reachable, _ = _build_negotiated_province_context(
        state, foreign, OWN, 7
    )

    assert reachable == {DEST: True}


def test_secondary_exploit_uses_canonical_near_victory_flag():
    state = InnerGameState()
    state.g_other_power_lead_flag = 1
    state.g_near_end_game_factor = 6.5

    assert _secondary_exploit_enabled(state, 64)
    assert not _secondary_exploit_enabled(state, 65)

    state.g_other_power_lead_flag = 0
    assert not _secondary_exploit_enabled(state, 0)


def test_secondary_exploit_walk_requires_press_sent_target():
    state = InnerGameState()
    state.g_other_power_lead_flag = 1
    state.g_near_end_game_factor = 6.5
    exploit_power = 1
    # Initial candidate 2 has trust but no negotiated press. Candidate 3 is
    # the first press-sent target reached by a one-slot C walk.
    state.g_ally_trust_score[OWN, exploit_power] = 1
    state.g_ally_trust_score[OWN, 2] = 1
    state.g_ally_trust_score[OWN, 3] = 1
    state.g_xdo_press_sent[OWN, exploit_power] = 1
    state.g_xdo_press_sent[OWN, 3] = 1

    with patch.object(_trial.random, 'randrange', return_value=99):
        target = _select_secondary_exploit_target(
            state, OWN, exploit_power, 0, 7
        )

    assert target == 3


def test_proposal_history_candidate_emits_foreign_move_support_not_move():
    state = InnerGameState()
    supporter = 10
    mover = 11
    destination = 12
    mover_power = 2
    state.albert_power_idx = OWN
    state.unit_info = {
        supporter: {'power': OWN, 'type': 'A', 'coast': ''},
        mover: {'power': mover_power, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix[supporter] = [destination]

    committed = _apply_proposal_support_candidate(
        state,
        OWN,
        OWN,
        {
            'unit_prov': supporter,
            'target_power': mover_power,
            'via_prov': mover,
            'dst_prov': destination,
        },
        {},
        {},
        7,
    )

    assert committed
    assert int(state.g_order_table[supporter, 0]) == 4  # SUP MTO
    assert int(state.g_order_table[supporter, 1]) == mover
    assert int(state.g_order_table[supporter, 2]) == destination
    assert int(state.g_convoy_active_flag[destination]) == 1
    assert state.g_support_trust_adj == 30
    # The proposal-exploit direct writer does not execute the public support
    # builder's convoy-registration or chain-strength tails.
    assert supporter not in state.g_convoy_fleet_registered
    assert int(state.g_order_table[destination, 13]) == 0
    assert int(state.g_order_table[destination, 14]) == 0


def test_secondary_proposal_uses_primary_partner_for_trust_adjustment():
    state = InnerGameState()
    supporter, mover, destination = 10, 11, 12
    secondary_partner, primary_partner = 2, 3
    state.albert_power_idx = OWN
    state.unit_info = {
        supporter: {'power': OWN, 'type': 'A', 'coast': ''},
        mover: {'power': secondary_partner, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix[supporter] = [destination]
    state.g_ally_trust_score[OWN, secondary_partner] = 5

    committed = _apply_proposal_support_candidate(
        state,
        OWN,
        OWN,
        {
            'unit_prov': supporter,
            'target_power': secondary_partner,
            'via_prov': mover,
            'dst_prov': destination,
        },
        {},
        {},
        7,
        primary_partner=primary_partner,
    )

    assert committed
    # ProcessTurn retains its primary cyclic partner in ppiStack_6fc even
    # when the record entered through the secondary-target insertion arm.
    assert state.g_support_trust_adj == 30


def test_proposal_support_rejects_accepted_xdo_and_dmz_sources():
    state = InnerGameState()
    supporter = 10
    mover = 11
    destination = 12
    state.unit_info = {
        supporter: {'power': OWN, 'type': 'A', 'coast': ''},
        mover: {'power': 2, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix[supporter] = [destination]
    candidate = {
        'unit_prov': supporter,
        'target_power': 2,
        'via_prov': mover,
        'dst_prov': destination,
    }

    assert not _apply_proposal_support_candidate(
        state, OWN, OWN, candidate, {}, {supporter: destination}, 7
    )
    assert not _apply_proposal_support_candidate(
        state, OWN, OWN, candidate, {supporter: True}, {}, 7
    )


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


def test_xdo_mto_populates_deviate_move_expectation():
    state = InnerGameState()
    state.prov_to_id = {'LON': SRC, 'BUR': DEST}
    state.g_xdo_candidate_list = [{'power': 0}]
    tokens = [
        'XDO', '(',
        '(', 'ENG', 'AMY', 'LON', ')', 'MTO', 'BUR',
        ')',
    ]

    assert _handle_xdo(state, tokens)
    assert state.g_xdo_mto_opp_score[0] == {SRC: DEST}


def test_xdo_sup_mto_populates_deviate_support_expectation():
    state = InnerGameState()
    state.prov_to_id = {'LON': SRC, 'PAR': OTHER, 'BUR': DEST}
    state.g_xdo_candidate_list = [{'power': 0}]
    tokens = [
        'XDO', '(',
        '(', 'ENG', 'AMY', 'LON', ')',
        'SUP', '(', 'ENG', 'AMY', 'PAR', ')', 'MTO', 'BUR',
        ')',
    ]

    assert _handle_xdo(state, tokens)
    assert state.g_xdo_sup_attacker_score[0] == {SRC: (OTHER, DEST)}
