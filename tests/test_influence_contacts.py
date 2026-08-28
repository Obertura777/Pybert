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
        "_compute_apply_heat_score", "_normalize_movement_heat",
        "_is_append_order_province", "_max_pair_support_score",
        "_populate_global_province_score", "_populate_unit_adjacency_count",
        "_populate_contact_matrices", "_populate_influence_ratio",
    ],
)
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])

_populate_contact_matrices = _influence._populate_contact_matrices
apply_influence_scores = _influence.apply_influence_scores
_populate_influence_ratio = _influence._populate_influence_ratio
_compute_apply_heat_score = _influence._compute_apply_heat_score
_normalize_movement_heat = _influence._normalize_movement_heat
_populate_unit_adjacency_count = _influence._populate_unit_adjacency_count
_max_pair_support_score = _influence._max_pair_support_score
_is_append_order_province = _influence._is_append_order_province
_populate_global_province_score = _influence._populate_global_province_score
InnerGameState = _state.InnerGameState


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


def test_append_order_gate_requires_an_empty_non_supply_province():
    state = InnerGameState()
    state.sc_provinces = {10}
    state.unit_info = {20: {'power': 1, 'type': 'A', 'coast': ''}}

    assert not _is_append_order_province(state, 10)
    assert not _is_append_order_province(state, 20)
    assert _is_append_order_province(state, 30)


def test_global_province_score_uses_integer_normalization():
    state = InnerGameState()
    state.g_num_powers = 2
    state.g_heat_movement[0, :2] = [2, 1]
    state.g_heat_movement[1, :2] = [1, 1]

    _populate_global_province_score(state)

    assert state.g_global_province_score[:2].tolist() == [100, 66]


def test_apply_appends_only_empty_non_supply_destinations():
    state = InnerGameState()
    state.valid_provinces = frozenset({0, 1, 2, 3})
    state.num_valid_provinces = 4
    state.land_provinces = {0, 1, 2, 3}
    state.water_provinces = set()
    state.sc_provinces = {3}
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

    assert {entry['province'] for entry in state.g_order_list} == {2}
