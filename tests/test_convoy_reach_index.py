"""Source-backed coverage for EnumerateConvoyReach's static reach index."""

import math
import os
import sys

from diplomacy import Game


_PKG_ROOT = os.path.dirname(os.path.dirname(__file__))
_PARENT = os.path.dirname(_PKG_ROOT)
if _PARENT not in sys.path:
    sys.path.insert(0, _PARENT)

_PKG = os.path.basename(_PKG_ROOT)
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])
_convoy = __import__(
    f"{_PKG}.moves.convoy",
    fromlist=["enumerate_convoy_reach", "_harmonic_dist_weight"],
)
_primitives = __import__(
    f"{_PKG}.heuristics._primitives",
    fromlist=["BuildOrderSpec", "compute_winter_builds"],
)
_orders = __import__(
    f"{_PKG}.bot.orders",
    fromlist=["_build_position_urgency", "_init_scoring_state"],
)

InnerGameState = _state.InnerGameState
BuildOrderSpec = _primitives.BuildOrderSpec
compute_winter_builds = _primitives.compute_winter_builds
enumerate_convoy_reach = _convoy.enumerate_convoy_reach
_harmonic_dist_weight = _convoy._harmonic_dist_weight
_build_position_urgency = _orders._build_position_urgency
_init_scoring_state = _orders._init_scoring_state


def _find_record(state, destination, source, source_type, destination_type,
                 source_coast="", destination_coast=""):
    return next(
        record
        for record in state.g_build_candidate_list[destination]
        if record.source_province == source
        and record.source_unit_type == source_type
        and record.source_coast == source_coast
        and record.destination_unit_type == destination_type
        and record.destination_coast == destination_coast
    )


def test_enumeration_builds_static_direct_convoy_and_coast_reach_records():
    state = InnerGameState()
    state.synchronize_from_game(Game())

    enumerate_convoy_reach(state)

    coast_variant_ids = {
        variant
        for variants in state.coast_variants.values()
        for variant in variants
    }
    assert len(state.g_build_candidate_list) == 75
    assert not coast_variant_ids.intersection(state.g_build_candidate_list)
    assert sum(map(len, state.g_build_candidate_list.values())) == 7_226

    lon = state.prov_to_id["LON"]
    wal = state.prov_to_id["WAL"]
    bre = state.prov_to_id["BRE"]
    nth = state.prov_to_id["NTH"]
    bot = state.prov_to_id["BOT"]
    bar = state.prov_to_id["BAR"]
    stp = state.prov_to_id["STP"]

    assert _find_record(state, lon, lon, "AMY", "AMY").score == 1.0
    assert math.isclose(
        _find_record(state, lon, wal, "AMY", "AMY").score,
        _harmonic_dist_weight(1, 7.0),
    )
    assert math.isclose(
        _find_record(state, lon, nth, "FLT", "FLT").score,
        _harmonic_dist_weight(1, 7.0),
    )

    # LON -> ENG -> BRE is a one-fleet convoy: combined wave distance 2.
    assert _find_record(state, bre, lon, "AMY", "AMY").score == 675.0

    assert math.isclose(
        _find_record(
            state, stp, bot, "FLT", "FLT", destination_coast="SC"
        ).score,
        _harmonic_dist_weight(1, 7.0),
    )
    assert math.isclose(
        _find_record(
            state, stp, bar, "FLT", "FLT", destination_coast="NC"
        ).score,
        _harmonic_dist_weight(1, 7.0),
    )
    # BOT reaches SC directly. NC is still reachable, but only by a longer
    # route around Scandinavia; coast identity must keep those scores apart.
    assert _find_record(
        state, stp, bot, "FLT", "FLT", destination_coast="NC"
    ).score > _find_record(
        state, stp, bot, "FLT", "FLT", destination_coast="SC"
    ).score


def test_position_urgency_uses_distance_and_exact_source_unit_token():
    state = InnerGameState()
    destination = 10
    army_source = 20
    fleet_source = 30
    wrong_coast_source = 40
    state.unit_info = {
        army_source: {"power": 1, "type": "A", "coast": ""},
        fleet_source: {"power": 2, "type": "F", "coast": "SC"},
        wrong_coast_source: {"power": 3, "type": "F", "coast": "NC"},
    }
    state.sc_provinces = {destination}
    state.g_sc_owner[destination] = 0
    state.g_build_candidate_list = {
        destination: [
            BuildOrderSpec(
                army_source, "AMY", "", "AMY", "", 2.0
            ),
            BuildOrderSpec(
                fleet_source, "FLT", "SC", "AMY", "", 4.0
            ),
            BuildOrderSpec(
                wrong_coast_source, "FLT", "SC", "AMY", "", 1.0
            ),
        ],
    }

    urgency = _build_position_urgency(state)

    assert urgency[1, destination] == 5_000.0
    assert urgency[2, destination] == 2_500.0
    assert urgency[3, destination] == 0.0


def test_position_urgency_ignores_uncontrolled_sc_destinations():
    state = InnerGameState()
    state.unit_info = {
        10: {"power": 0, "type": "F", "coast": ""},
        20: {"power": 1, "type": "A", "coast": ""},
    }
    state.sc_provinces = {10}
    state.g_build_candidate_list = {
        10: [BuildOrderSpec(20, "AMY", "", "FLT", "", 1.0)],
    }

    assert not _build_position_urgency(state).any()


def test_scoring_state_projects_capture_from_sc_controller_without_unit():
    state = InnerGameState()
    destination, source = 10, 20
    state.sc_provinces = {destination}
    state.g_sc_owner[destination] = 1
    state.unit_info[source] = {
        "power": 0, "type": "A", "coast": "",
    }
    state.g_build_candidate_list = {
        destination: [
            BuildOrderSpec(source, "AMY", "", "AMY", "", 2.0),
        ],
    }

    _init_scoring_state(state)

    assert state.g_target_sc_cnt[0] == 1
    assert state.g_target_sc_cnt[1] == -1


def test_compute_winter_builds_uses_candidate_cap_and_live_token_channels():
    state = InnerGameState()
    destination = 10
    own_source = 20
    foreign_source = 30
    empty_build_source = 40
    state.sc_provinces = {destination}
    state.g_sc_owner[destination] = 0
    state.unit_info = {
        destination: {"power": 0, "type": "A", "coast": ""},
        own_source: {"power": 0, "type": "A", "coast": ""},
        foreign_source: {"power": 1, "type": "F", "coast": "SC"},
    }
    state.g_sc_ownership[0, own_source] = 1
    state.g_established_ally_flag[0, foreign_source] = 1
    state.g_adjustment_build_candidates = [{
        "province": empty_build_source,
        "unit_type": "AMY",
        "coast": "",
    }]
    state.g_build_candidate_list = {
        destination: [
            BuildOrderSpec(
                empty_build_source, "AMY", "", "AMY", "", 40.0
            ),
            BuildOrderSpec(
                own_source, "AMY", "", "AMY", "", 2.0
            ),
            BuildOrderSpec(
                foreign_source, "FLT", "SC", "AMY", "", 4.0
            ),
        ],
    }

    compute_winter_builds(state, 0)

    assert math.isclose(
        state.g_winter_score_a[destination],
        10_000.0 / 30.0 + 10_000.0 / 2.0,
    )
    assert state.g_winter_score_b[destination] == 2_500.0

    # Direct callers without the materialized candidate list derive the same
    # legal token set from build delta and persistent board ownership.
    state.g_adjustment_build_candidates.clear()
    state.g_build_delta = {0: {"flag": 1, "delta": 1}}
    state.home_centers = {0: frozenset({empty_build_source})}
    state.g_board_sc_ownership[0, empty_build_source] = 1

    compute_winter_builds(state, 0)

    assert math.isclose(
        state.g_winter_score_a[destination],
        10_000.0 / 30.0 + 10_000.0 / 2.0,
    )
