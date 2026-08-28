"""Source-parity tests for CAL_BOARD's DAT_00633780 matrix."""

import os
import sys


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state = __import__(f"{_pkg_name}.state", fromlist=["InnerGameState"])
_board = __import__(
    f"{_pkg_name}.heuristics.board",
    fromlist=[
        "_populate_enemy_rank_matrix", "_apply_distressed_ally_rescue",
        "_apply_late_gang_up", "_apply_validated_top3_gang_up", "cal_board",
        "_apply_weak_elimination_and_sc_grab", "_fear_weighted_threshold",
        "_apply_dominance_sweep", "_apply_alliance_agreement_enemies",
    ],
)
_rng = __import__(f"{_pkg_name}.rng", fromlist=["randint"])

InnerGameState = _state.InnerGameState
_populate_enemy_rank_matrix = _board._populate_enemy_rank_matrix
_apply_distressed_ally_rescue = _board._apply_distressed_ally_rescue
_apply_late_gang_up = _board._apply_late_gang_up
_apply_validated_top3_gang_up = _board._apply_validated_top3_gang_up
_apply_weak_elimination_and_sc_grab = _board._apply_weak_elimination_and_sc_grab
_fear_weighted_threshold = _board._fear_weighted_threshold
_apply_dominance_sweep = _board._apply_dominance_sweep
_apply_alliance_agreement_enemies = _board._apply_alliance_agreement_enemies
cal_board = _board.cal_board


def test_enemy_rank_matrix_stores_count_with_current_enemy_excluded():
    state = InnerGameState()
    state.g_target_sc_cnt[:] = [3, 3, 3, 3, 2, 0, 0]
    state.g_influence_matrix.fill(0.0)
    state.g_influence_matrix[0, 1:4] = 10.0
    # Power 3 is trusted, so only powers 1 and 2 are live enemies of row 0.
    state.g_ally_trust_score[0, 3] = 2

    _populate_enemy_rank_matrix(state, state.g_ally_trust_score_hi)

    assert state.g_enemy_count[0] == 2
    assert state.g_rank_matrix[0].tolist() == [2, 1, 1, 2, 2, 2, 2]


def test_ally_distress_uses_enemy_exclusion_matrix_not_influence_rank():
    state = InnerGameState()
    state.g_stabbed_flag = 1
    state.win_threshold = 18
    state.g_target_sc_cnt[:] = [3, 3, 3, 3, 3, 0, 0]
    state.sc_count[:] = state.g_target_sc_cnt

    # Ally 1 is attacked by powers 2 and 3.  Each attacker has exactly two
    # enemies including us, so DAT_00633780[attacker, own] is 1.
    state.g_ally_trust_score[0, 1] = 7
    state.g_ally_pref_ranking[1, 1] = 2
    state.g_ally_pref_ranking[1, 2] = 3
    for attacker in (2, 3):
        state.g_influence_matrix[attacker, 0] = 10.0
        state.g_influence_matrix[attacker, 4] = 10.0

    # Deliberately contradict the old substitute.  C never reads this matrix
    # for the distress gate.
    state.g_influence_rank_flag[2, 0] = 5
    state.g_influence_rank_flag[3, 0] = 5

    cal_board(state, own_power=0)

    assert state.g_rank_matrix[2, 0] == 1
    assert state.g_rank_matrix[3, 0] == 1
    assert state.g_ally_distress_flag[1] == 1


def test_distressed_ally_rescue_uses_inverse_ranks_and_relation_gate():
    state = InnerGameState()
    own, top1, top2, ally = 0, 1, 2, 3
    state.g_ally_distress_flag[ally] = 1
    state.g_ally_pref_ranking[ally, 1:3] = [4, 5]
    state.g_ally_pref_ranking[own, 3:5] = [4, 5]
    state.g_rank_matrix[own, 4] = 2
    state.g_rank_matrix[own, 5] = 3
    state.g_ally_trust_score[own, 4] = 9
    state.g_ally_trust_score_hi[own, 4] = 2
    state.g_ally_trust_score[4, own] = 1

    # The old port read this high trust word as its threshold. C reads the
    # relation matrix and must do nothing while that score is at most 30.
    state.g_ally_trust_score_hi[own, top1] = 50
    _apply_distressed_ally_rescue(
        state, own, top1, top2, state.g_ally_trust_score_hi,
    )
    assert state.g_enemy_flag[4] == 0

    state.g_relation_score[own, top1] = 31
    _apply_distressed_ally_rescue(
        state, own, top1, top2, state.g_ally_trust_score_hi,
    )

    assert state.g_enemy_flag[4] == 1
    assert state.g_enemy_flag[5] == 0  # rank-matrix value 3 fails C's <3 gate
    assert state.g_ally_trust_score[own, 4] == 0
    assert state.g_ally_trust_score_hi[own, 4] == 0
    assert state.g_ally_trust_score[4, own] == 0


def test_late_gang_up_uses_source_threshold_matrix_orientation_and_ratio():
    state = InnerGameState()
    own, top1, top2, top3, top4 = 0, 1, 2, 3, 4

    # C accepts low-word trust 4 (the old generic loop required >6), even when
    # the ally is the opening choice. Top two remains hostile from own's view.
    state.g_ally_trust_score[own, top1] = 4
    state.g_best_ally_slot0 = top1
    state.g_rank_matrix[own, top2] = 2
    state.g_rank_matrix[top2, own] = 6  # opposite orientation is irrelevant
    state.g_influence_matrix_raw[top3, own] = 6.0
    state.g_influence_matrix_raw[own, top3] = 2.0
    state.g_ally_trust_score[own, top3] = 9
    state.g_ally_trust_score_hi[own, top3] = 1

    _apply_late_gang_up(
        state, own, top1, top2, top3, top4,
        state.g_ally_trust_score_hi,
    )

    assert state.g_enemy_flag[top3] == 1
    assert state.g_ally_trust_score[own, top3] == 0
    assert state.g_ally_trust_score_hi[own, top3] == 0


def test_late_gang_up_tries_inverse_rank_four_after_rank_three():
    state = InnerGameState()
    own, top1, top2, top3, top4 = 0, 1, 2, 3, 5
    state.g_ally_trust_score[own, top2] = 5
    state.g_rank_matrix[own, top1] = 1

    # Top two does not regard rank three as hostile, so C falls through to the
    # fourth feared power from DAT_00633f18[own, 4].
    state.g_ally_trust_score[top2, top3] = 1
    state.g_influence_matrix_raw[top4, own] = 8.0
    state.g_influence_matrix_raw[own, top4] = 3.0

    _apply_late_gang_up(
        state, own, top1, top2, top3, top4,
        state.g_ally_trust_score_hi,
    )

    assert state.g_enemy_flag[top3] == 0
    assert state.g_enemy_flag[top4] == 1


def test_late_gang_up_rejects_enemy_matrix_value_three():
    state = InnerGameState()
    own, top1, top2, top3, top4 = 0, 1, 2, 3, 4
    state.g_ally_trust_score[own, top1] = 7
    state.g_rank_matrix[own, top2] = 3
    state.g_influence_matrix_raw[top3, own] = 10.0

    _apply_late_gang_up(
        state, own, top1, top2, top3, top4,
        state.g_ally_trust_score_hi,
    )

    assert state.g_enemy_flag[top3] == 0


def test_normal_war_branch_keeps_second_enemy_when_source_inspection_is_false():
    state = InnerGameState()
    state.g_stabbed_flag = 1
    state.win_threshold = 18
    state.g_target_sc_cnt[:] = 3
    state.sc_count[:] = 3
    state.g_influence_matrix[0, 1:4] = [30.0, 25.0, 20.0]

    # We trust feared #1 but are hostile to #2 and #3. Since #2/#1 is above
    # 70%, C's 1296 condition is false and it validates current enemy #2.
    state.g_ally_trust_score[0, 1] = 4

    cal_board(state, own_power=0)

    assert state.g_enemy_flag[2] == 1
    assert state.g_enemy_flag[1] == 0
    assert state.g_enemy_flag[3] == 0


def test_normal_war_branch_validates_third_when_only_third_has_zero_trust():
    state = InnerGameState()
    state.g_stabbed_flag = 1
    state.win_threshold = 18
    state.g_target_sc_cnt[:] = 3
    state.sc_count[:] = 3
    state.g_influence_matrix[0, 1:4] = [30.0, 25.0, 20.0]
    state.g_ally_trust_score[0, 1:3] = [4, 4]

    cal_board(state, own_power=0)

    assert state.g_enemy_flag[3] == 1
    assert state.g_enemy_flag[1] == 0
    assert state.g_enemy_flag[2] == 0


def test_two_front_war_uses_second_peace_marker_arm():
    state = InnerGameState()
    state.g_stabbed_flag = 1
    state.win_threshold = 18
    state.g_target_sc_cnt[:] = 3
    state.sc_count[:] = 3
    state.g_influence_matrix[0, 1:4] = [30.0, 20.0, 10.0]

    # The clear #2 marker arm is disabled. C then tests #1's clear peace and
    # neutral markers and selects #2 without consuming the random fallback.
    state.g_peace_counter[2] = 1

    cal_board(state, own_power=0)

    assert state.g_enemy_flag[1] == 0
    assert state.g_enemy_flag[2] == 1


def test_fear_weighted_threshold_uses_trust_divisors_without_plus_one():
    assert _fear_weighted_threshold(30.0, 3, 20.0, 1) == 33
    assert _fear_weighted_threshold(30.0, 4, 20.0, 1) == 27


def test_cal_board_stops_when_hostility_does_not_desire_an_enemy():
    state = InnerGameState()
    state.win_threshold = 18
    state.g_target_sc_cnt[:] = 3
    state.sc_count[:] = 3
    state.g_influence_matrix[0, 1:4] = [30.0, 20.0, 10.0]
    state.g_ally_trust_score[0, 1:4] = [3, 1, 1]

    cal_board(state, own_power=0)

    assert state.g_enemy_flag.tolist() == [0] * 7


def test_peace_branch_uses_weighted_threshold_and_clears_reverse_marker(
        monkeypatch):
    state = InnerGameState()
    state.g_stabbed_flag = 1
    state.win_threshold = 18
    state.g_target_sc_cnt[:] = 3
    state.sc_count[:] = 3
    state.g_influence_matrix[0, 1:4] = [30.0, 20.0, 10.0]
    state.g_ally_trust_score[0, 1:4] = [3, 1, 1]
    state.g_ally_trust_score[2, 0] = 1

    # Each raw value maps to 20 after Albert's (rand()/0x17)%50, for a sum of
    # 40. The exact tier-weighted threshold is 33; the old unweighted formula
    # was 58 and therefore selected the opposite power.
    monkeypatch.setattr(_rng, "randint", lambda _start, _stop: 460)

    cal_board(state, own_power=0)

    assert state.g_enemy_flag[1] == 0
    assert state.g_enemy_flag[2] == 1
    assert state.g_ally_trust_score[2, 0] == 0


def test_peace_branch_rejects_negative_high_trust_word():
    state = InnerGameState()
    state.g_stabbed_flag = 1
    state.win_threshold = 18
    state.g_target_sc_cnt[:] = 3
    state.sc_count[:] = 3
    state.g_influence_matrix[0, 1:4] = [30.0, 20.0, 10.0]
    state.g_ally_trust_score[0, 1:4] = [2, 2, 2]
    state.g_ally_trust_score_hi[0, 3] = -1

    cal_board(state, own_power=0)

    assert state.g_enemy_flag.tolist() == [0] * 7


def test_validated_third_enemy_can_add_second_via_strong_first_ally():
    state = InnerGameState()
    own, top1, top2 = 0, 1, 2
    state.g_ally_trust_score[own, top1] = 7
    state.g_rank_matrix[own, top2] = 1
    state.g_influence_matrix_raw[top2, own] = 7.0
    state.g_influence_matrix_raw[own, top2] = 2.0

    _apply_validated_top3_gang_up(
        state, own, top1, top2, -1,
        state.g_ally_trust_score_hi,
    )

    assert state.g_enemy_flag[top2] == 1


def test_validated_third_enemy_can_add_first_via_strong_second_ally():
    state = InnerGameState()
    own, top1, top2 = 0, 1, 2
    state.g_ally_trust_score[own, top2] = 7
    state.g_rank_matrix[own, top1] = 1
    state.g_influence_matrix_raw[top1, own] = 7.0
    state.g_influence_matrix_raw[own, top1] = 2.0

    _apply_validated_top3_gang_up(
        state, own, top1, top2, -1,
        state.g_ally_trust_score_hi,
    )

    assert state.g_enemy_flag[top1] == 1


def test_weak_elimination_uses_target_pressure_over_own_pressure():
    state = InnerGameState()
    own, target = 0, 2
    state.g_deceit_level = 3
    state.g_target_sc_cnt[:] = 3
    state.g_influence_matrix[own, target] = 1.0
    state.g_influence_matrix[target, own] = 11.0
    state.g_influence_matrix_raw[target, own] = 10.0
    state.g_influence_matrix_raw[own, target] = 1.0
    state.g_ally_trust_score[target, own] = 1

    _apply_weak_elimination_and_sc_grab(
        state, own, state.g_ally_trust_score_hi,
    )

    assert state.g_enemy_flag[target] == 1
    assert state.g_ally_trust_score[target, own] == 0


def test_sc_grab_has_small_power_and_low_fear_independent_branches():
    state = InnerGameState()
    own, small_target, low_fear_target = 0, 2, 3
    state.g_target_sc_cnt[own] = 3
    state.g_target_sc_cnt[small_target] = 1
    state.g_target_sc_cnt[low_fear_target] = 1

    for target in (small_target, low_fear_target):
        state.g_contact_count[own, target] = 1
        state.g_contact_weighted[own, target] = 1

    _apply_weak_elimination_and_sc_grab(
        state, own, state.g_ally_trust_score_hi,
    )
    assert state.g_enemy_flag[small_target] == 1

    # C's second branch does not require own_sc < 4; inverse influence rank
    # greater than three is its alternative gate.
    state.g_enemy_flag.fill(0)
    state.g_target_sc_cnt[own] = 5
    state.g_influence_rank_flag[own, low_fear_target] = 4
    _apply_weak_elimination_and_sc_grab(
        state, own, state.g_ally_trust_score_hi,
    )
    assert state.g_enemy_flag[low_fear_target] == 1


def test_dominance_sweep_clears_both_enemy_word_and_reverse_marker():
    state = InnerGameState()
    own, leader, target = 0, 1, 2
    state.g_sc_percent[own] = 80.0
    state.g_sc_percent[leader] = 70.0
    state.g_enemy_flag_hi[target] = 9
    state.g_ally_trust_score[own, target] = 8
    state.g_ally_trust_score_hi[own, target] = 2
    state.g_ally_trust_score[target, own] = 1

    _apply_dominance_sweep(
        state, own, leader, state.g_ally_trust_score_hi,
    )

    assert state.g_leading_flag == 1
    assert state.g_enemy_flag[target] == 1
    assert state.g_enemy_flag_hi[target] == 0
    assert state.g_ally_trust_score[own, target] == 0
    assert state.g_ally_trust_score_hi[own, target] == 0
    assert state.g_ally_trust_score[target, own] == 0


def test_alliance_agreement_uses_final_power_ally_row_snapshot():
    state = InnerGameState()
    own, declaring, target, final_power = 0, 1, 2, 6
    state.g_ally_matrix[declaring, target] = 1
    state.g_ally_matrix[final_power, declaring] = 1
    # Prevent the final row itself from declaring power 1 an enemy; its row is
    # relevant here only because C leaves it in auStack_dc.
    state.g_ally_trust_score[final_power, declaring] = 2

    _apply_alliance_agreement_enemies(
        state, own, -1, state.g_ally_trust_score_hi,
    )

    assert state.g_enemy_flag[target] == 0


def test_alliance_agreement_can_honor_multiple_targets_and_cleans_reverse():
    state = InnerGameState()
    own, declaring = 0, 1
    targets = (2, 3)
    for target in targets:
        state.g_ally_matrix[declaring, target] = 1
        state.g_ally_trust_score[own, target] = 8
        state.g_ally_trust_score_hi[own, target] = 2
        state.g_ally_trust_score[target, own] = 1

    _apply_alliance_agreement_enemies(
        state, own, -1, state.g_ally_trust_score_hi,
    )

    for target in targets:
        assert state.g_enemy_flag[target] == 1
        assert state.g_enemy_flag_hi[target] == 0
        assert state.g_ally_trust_score[own, target] == 0
        assert state.g_ally_trust_score_hi[own, target] == 0
        assert state.g_ally_trust_score[target, own] == 0


def test_alliance_agreement_checks_high_enemy_word_and_unsigned_trust_low():
    state = InnerGameState()
    own, high_word_declarer, signed_low_declarer = 0, 1, 4
    high_word_target, signed_low_target = 2, 5
    state.g_ally_matrix[high_word_declarer, high_word_target] = 1
    state.g_enemy_flag_hi[high_word_declarer] = 1
    state.g_ally_matrix[signed_low_declarer, signed_low_target] = 1
    state.g_ally_trust_score[signed_low_declarer, signed_low_target] = -1

    _apply_alliance_agreement_enemies(
        state, own, -1, state.g_ally_trust_score_hi,
    )

    assert state.g_enemy_flag[high_word_target] == 0
    assert state.g_enemy_flag[signed_low_target] == 0
