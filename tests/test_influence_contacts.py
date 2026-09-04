"""Source-parity regressions for ApplyInfluenceScores contact matrices."""

from pathlib import Path
import sys


_ROOT = Path(__file__).resolve().parents[1]
_PKG = _ROOT.name
if str(_ROOT.parent) not in sys.path:
    sys.path.insert(0, str(_ROOT.parent))

_influence = __import__(
    f"{_PKG}.heuristics.influence",
    fromlist=[
        "apply_influence_scores",
        "set_opening_targets",
        "_compute_apply_heat_score", "_normalize_movement_heat",
        "_is_append_order_province", "_max_pair_support_score",
        "_populate_global_province_score", "_populate_unit_adjacency_count",
        "_populate_contact_matrices", "_populate_influence_ratio",
    ],
)
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])
_strategy = __import__(
    f"{_PKG}.heuristics.strategy",
    fromlist=["compute_press", "compute_draw_vote"],
)
_analysis = __import__(
    f"{_PKG}.bot.analysis", fromlist=["_cleanup_turn"],
)

_populate_contact_matrices = _influence._populate_contact_matrices
apply_influence_scores = _influence.apply_influence_scores
set_opening_targets = _influence.set_opening_targets
_populate_influence_ratio = _influence._populate_influence_ratio
_compute_apply_heat_score = _influence._compute_apply_heat_score
_normalize_movement_heat = _influence._normalize_movement_heat
_populate_unit_adjacency_count = _influence._populate_unit_adjacency_count
_max_pair_support_score = _influence._max_pair_support_score
_is_append_order_province = _influence._is_append_order_province
_populate_global_province_score = _influence._populate_global_province_score
InnerGameState = _state.InnerGameState
compute_press = _strategy.compute_press
compute_draw_vote = _strategy.compute_draw_vote
_cleanup_turn = _analysis._cleanup_turn


def test_cleanup_turn_uses_full_split_trust_divisor():
    state = InnerGameState()
    state.g_influence_matrix_raw[0, 1] = 100.0
    state.g_influence_matrix_raw[0, 2] = 100.0
    state.g_ally_trust_score_hi[0, 1] = 1

    _cleanup_turn(state)

    assert state.g_influence_matrix[0, 1] < 1.0
    assert state.g_influence_matrix[0, 2] > 99.0


def test_opening_target_uses_sc_controller_not_live_unit_type():
    state = InnerGameState()
    controlled, neutral = 10, 20
    state.g_deceit_level = 1
    state.g_season = 'SPR'
    state.sc_provinces = {controlled, neutral}
    state.g_sc_owner[controlled] = 0
    state.unit_info[neutral] = {'power': 1, 'type': 'A', 'coast': ''}
    state.g_global_province_score[[controlled, neutral]] = 1
    state.g_heat_movement_b[0, [controlled, neutral]] = [100, 2]

    set_opening_targets(state)

    # The neutral controller token is eligible even if a live army currently
    # occupies the centre; the much hotter controlled SC is excluded.
    assert state.g_opening_target[0] == neutral


def test_compute_press_marks_uncontrolled_sc_not_fleet_occupant():
    state = InnerGameState()
    source, target = 10, 20
    state.unit_info = {
        source: {'power': 0, 'type': 'A', 'coast': ''},
        target: {'power': 1, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix[source] = [target]
    state.sc_provinces = {target}

    compute_press(state)

    assert state.g_press_matrix[0, target] == 1
    assert state.g_press_count[0] == 1

    state.g_sc_owner[target] = 1
    compute_press(state)
    assert state.g_press_matrix[0, target] == 0
    assert state.g_press_count[0] == 0


def test_compute_press_filters_fleet_source_coast():
    state = InnerGameState()
    split_coast, north_target, south_target = 10, 20, 30
    state.adj_matrix = {
        split_coast: [north_target, south_target],
        north_target: [split_coast],
        south_target: [split_coast],
    }
    state.fleet_adj_matrix = {
        split_coast: [north_target, south_target],
    }
    state.fleet_coast_adj = {
        (split_coast, '/NC'): [north_target],
        (split_coast, '/SC'): [south_target],
    }
    state.unit_info = {
        split_coast: {'power': 0, 'type': 'F', 'coast': 'NC'},
    }
    state.sc_provinces = {north_target, south_target}
    state.g_sc_owner[[north_target, south_target]] = -1

    compute_press(state)

    assert state.g_press_matrix[0, north_target] == 1
    assert state.g_press_matrix[0, south_target] == 0
    assert state.g_press_count[0] == 1


def test_draw_vote_ignores_disconnected_non_friendly_unit():
    state = InnerGameState()
    state.adj_matrix = {1: [], 2: []}
    state.unit_info = {
        1: {'power': 0, 'type': 'A', 'coast': ''},
        2: {'power': 1, 'type': 'A', 'coast': ''},
    }

    assert compute_draw_vote(state, {0})


def test_draw_vote_rejects_reachable_foreign_controlled_sc():
    state = InnerGameState()
    state.adj_matrix = {1: [2], 2: [1]}
    state.unit_info = {1: {'power': 0, 'type': 'A', 'coast': ''}}
    state.sc_provinces = {2}
    state.g_sc_owner[2] = 1

    assert not compute_draw_vote(state, {0})

    state.g_sc_owner[2] = 0
    assert compute_draw_vote(state, {0})


def test_draw_vote_army_reach_does_not_flood_across_water():
    state = InnerGameState()
    land, sea, foreign_sc = 1, 2, 3
    state.adj_matrix = {
        land: [sea],
        sea: [land, foreign_sc],
        foreign_sc: [sea],
    }
    state.water_provinces = frozenset({sea})
    state.land_provinces = frozenset({land, foreign_sc})
    state.unit_info = {land: {'power': 0, 'type': 'A', 'coast': ''}}
    state.sc_provinces = {foreign_sc}
    state.g_sc_owner[foreign_sc] = 1

    # The province-only port incorrectly crossed the sea and rejected this
    # draw.  C's local_e4 keeps the AMY token in the flood key.
    assert compute_draw_vote(state, {0})


def test_draw_vote_fleet_reach_keeps_arrival_coast():
    state = InnerGameState()
    source_sea, split_coast, other_sea, foreign_sc = 1, 2, 3, 4
    state.adj_matrix = {
        source_sea: [split_coast],
        split_coast: [source_sea, other_sea],
        other_sea: [split_coast, foreign_sc],
        foreign_sc: [other_sea],
    }
    state.water_provinces = frozenset({source_sea, other_sea})
    state.land_provinces = frozenset()
    state.fleet_adj_matrix = {
        source_sea: [split_coast],
        split_coast: [source_sea, other_sea],
        other_sea: [split_coast, foreign_sc],
        foreign_sc: [other_sea],
    }
    state.fleet_coast_adj = {
        (split_coast, '/NC'): [source_sea],
        (split_coast, '/SC'): [other_sea],
    }
    state.unit_info = {
        source_sea: {'power': 0, 'type': 'F', 'coast': ''},
    }
    state.sc_provinces = {foreign_sc}
    state.g_sc_owner[foreign_sc] = 1

    # The fleet arrives on /NC.  It cannot leave through /SC, and the AMY
    # companion key added on land cannot enter other_sea either.
    assert compute_draw_vote(state, {0})


def test_draw_vote_fleet_reaches_foreign_sc_through_legal_seas():
    state = InnerGameState()
    first_sea, second_sea, foreign_sc = 1, 2, 3
    state.adj_matrix = {
        first_sea: [second_sea],
        second_sea: [first_sea, foreign_sc],
        foreign_sc: [second_sea],
    }
    state.water_provinces = frozenset({first_sea, second_sea})
    state.land_provinces = frozenset()
    state.fleet_adj_matrix = {
        first_sea: [second_sea],
        second_sea: [first_sea, foreign_sc],
        foreign_sc: [second_sea],
    }
    state.unit_info = {
        first_sea: {'power': 0, 'type': 'F', 'coast': ''},
    }
    state.sc_provinces = {foreign_sc}
    state.g_sc_owner[foreign_sc] = 1

    assert not compute_draw_vote(state, {0})


def test_draw_vote_counts_reachable_frontiers_against_outside_unit():
    state = InnerGameState()
    left, outside, right = 1, 2, 3
    state.adj_matrix = {
        left: [outside],
        outside: [left, right],
        right: [outside],
    }
    state.land_provinces = frozenset({left, outside, right})
    state.unit_info = {
        left: {'power': 0, 'type': 'A', 'coast': ''},
        outside: {'power': 1, 'type': 'A', 'coast': ''},
        right: {'power': 0, 'type': 'A', 'coast': ''},
    }

    # The outside unit has two reachable frontier squares, so its choice is
    # unresolved and the draw is rejected.  The old port reversed this edge
    # and treated the two draw-member units as independently forced.
    assert not compute_draw_vote(state, {0})


def test_contact_matrices_walk_each_sc_once_for_each_outer_power():
    state = InnerGameState()
    state.sc_provinces = {10, 20, 30}
    state.g_sc_owner[10] = 1
    state.g_sc_owner[20] = 2
    state.g_sc_owner[30] = -1

    state.g_influence_ratio[0, 10] = 1.5
    state.g_influence_ratio[0, 20] = 1.0
    state.g_influence_ratio[2, 10] = 3.0
    state.g_unit_adjacency_count[0, 10] = 7
    state.g_unit_adjacency_count[1, 10] = 11
    state.g_unit_adjacency_count[2, 10] = 13

    # Unit topology is deliberately duplicative. The source pass does not
    # iterate units or their adjacencies, so it must not multiply the SC hit.
    state.unit_info = {
        40: {'power': 0, 'type': 'A', 'coast': ''},
        41: {'power': 0, 'type': 'A', 'coast': ''},
    }
    state.adj_matrix[40] = [10]
    state.adj_matrix[41] = [10]

    _populate_contact_matrices(state)

    assert state.g_contact_count[0, 1] == 1
    assert state.g_contact_weighted[0, 1] == 7
    assert state.g_contact_owner_count[0, 1] == 11
    assert state.g_contact_count[2, 1] == 1
    assert state.g_contact_weighted[2, 1] == 13
    assert state.g_contact_owner_count[2, 1] == 11
    assert int(state.g_contact_count.sum()) == 2


def test_influence_ratio_uses_controlled_sc_and_controller_heat():
    state = InnerGameState()
    state.sc_provinces = {10}
    state.g_sc_owner[10] = 0
    state.g_heat_score[0, 10] = 10
    state.g_heat_score[1, 10] = 20
    state.g_heat_score[2, 10] = 30
    # An army outside the SC set must not create a ratio entry.
    state.unit_info[20] = {'power': 1, 'type': 'A', 'coast': ''}
    state.g_heat_score[1, 20] = 999

    _populate_influence_ratio(state)

    assert state.g_influence_ratio[0, 10] == 30 / 11
    assert state.g_influence_ratio[1, 10] == 20 / 11
    assert state.g_influence_ratio[2, 10] == 30 / 11
    assert not state.g_influence_ratio[:, 20].any()


def test_movement_heat_channels_use_distinct_integer_denominators():
    state = InnerGameState()
    state.g_num_powers = 1
    state.num_valid_provinces = 2
    state.g_heat_movement[0, :2] = [10, 5]
    state.g_heat_movement_b[0, :2] = [10, 5]
    state.g_heat_movement[0, 2] = 1000
    state.g_heat_movement_b[0, 2] = 1000

    _normalize_movement_heat(state)

    assert state.g_heat_movement[0, :2].tolist() == [90, 45]
    assert state.g_heat_movement_b[0, :2].tolist() == [100, 50]
    assert state.g_heat_movement[0, 2] == 1000
    assert state.g_heat_movement_b[0, 2] == 1000


def test_apply_heat_aggregates_round_two_without_repinning():
    state = InnerGameState()
    state.g_num_powers = 1
    state.valid_provinces = frozenset({0, 1})
    state.land_provinces = {0, 1}
    state.water_provinces = set()
    state.adj_matrix = {0: [1], 1: [0]}
    state.unit_info = {0: {'power': 0, 'type': 'A', 'coast': ''}}
    state.g_heat_movement[0, :2] = [91, 73]
    state.g_heat_movement_b[0, :2] = [82, 64]

    _compute_apply_heat_score(state)

    assert state.g_heat_score[0, :2].tolist() == [400, 400]
    # Apply's private six-set diffusion must not overwrite GenerateOrders heat.
    assert state.g_heat_movement[0, :2].tolist() == [91, 73]
    assert state.g_heat_movement_b[0, :2].tolist() == [82, 64]


def test_apply_heat_keeps_army_and_fleet_topologies_separate():
    state = InnerGameState()
    state.g_num_powers = 1
    state.valid_provinces = frozenset({0, 1})
    state.water_provinces = {0}
    state.land_provinces = {1}
    state.adj_matrix = {0: [1], 1: [0]}
    state.fleet_adj_matrix = {0: []}
    state.unit_info = {0: {'power': 0, 'type': 'F', 'coast': ''}}

    _compute_apply_heat_score(state)

    assert state.g_heat_score[0, 0] == 200
    assert state.g_heat_score[0, 1] == 0


def test_unit_adjacency_count_filters_each_live_unit_by_type():
    state = InnerGameState()
    state.g_num_powers = 1
    state.water_provinces = {2}
    state.land_provinces = {3}
    state.adj_matrix = {0: [1, 2], 4: [1, 3]}
    state.fleet_adj_matrix = {4: [1]}
    state.unit_info = {
        0: {'power': 0, 'type': 'A', 'coast': ''},
        4: {'power': 0, 'type': 'F', 'coast': ''},
    }

    _populate_unit_adjacency_count(state)

    assert state.g_unit_adjacency_count[0, 0] == 1
    assert state.g_unit_adjacency_count[0, 1] == 2
    assert state.g_unit_adjacency_count[0, 2] == 0
    assert state.g_unit_adjacency_count[0, 3] == 0
    assert state.g_unit_adjacency_count[0, 4] == 1


def test_pair_support_max_excludes_either_powers_home_centers():
    state = InnerGameState()
    state.valid_provinces = frozenset({10, 11, 12})
    state.home_centers = {0: frozenset({10}), 1: frozenset({11})}
    scores = state.g_global_province_score.copy()
    scores[10] = 1000
    scores[11] = 900
    scores[12] = 80

    assert _max_pair_support_score(state, scores, 0, 1) == 80


def test_append_order_gate_accepts_empty_controlled_but_not_neutral_sc():
    state = InnerGameState()
    state.sc_provinces = {10, 11}
    state.g_sc_owner[10] = 0
    state.unit_info = {20: {'power': 1, 'type': 'A', 'coast': ''}}

    assert _is_append_order_province(state, 10)
    assert not _is_append_order_province(state, 11)
    assert not _is_append_order_province(state, 20)
    assert _is_append_order_province(state, 30)


def test_global_province_score_uses_integer_normalization():
    state = InnerGameState()
    state.g_num_powers = 2
    state.g_heat_movement[0, :2] = [2, 1]
    state.g_heat_movement[1, :2] = [1, 1]

    _populate_global_province_score(state)

    assert state.g_global_province_score[:2].tolist() == [100, 66]


def test_apply_appends_empty_non_sc_and_controlled_sc_destinations():
    state = InnerGameState()
    state.valid_provinces = frozenset({0, 1, 2, 3})
    state.num_valid_provinces = 4
    state.land_provinces = {0, 1, 2, 3}
    state.water_provinces = set()
    state.sc_provinces = {3}
    state.g_sc_owner[3] = 0
    state.adj_matrix = {
        0: [2, 3],
        1: [2, 3],
        2: [0, 1],
        3: [0, 1],
    }
    state.unit_info = {
        0: {'power': 0, 'type': 'A', 'coast': ''},
        1: {'power': 1, 'type': 'A', 'coast': ''},
    }
    state.g_heat_movement[1, 2:4] = 10
    state.g_heat_movement_b[0, 2:4] = 10
    state.g_influence_matrix_b[0, 1] = 1

    apply_influence_scores(state, own_power=0)

    assert {entry['province'] for entry in state.g_order_list} == {2, 3}
    controlled = next(
        entry for entry in state.g_order_list if entry['province'] == 3
    )
    assert controlled['flag1'] is False
