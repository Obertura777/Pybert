"""Regressions for ParseNOW's separate active and dislodged unit views."""

from pathlib import Path
import sys

from diplomacy import Game

_ROOT = Path(__file__).resolve().parents[1]
_PKG = _ROOT.name
if str(_ROOT.parent) not in sys.path:
    sys.path.insert(0, str(_ROOT.parent))

_now = __import__(
    f"{_PKG}.communications.inbound.now_parser",
    fromlist=["parse_now", "parse_now_unit"],
)
_snapshot = __import__(
    f"{_PKG}.heuristics.snapshot", fromlist=["snapshot_province_state"]
)
_strategy = __import__(f"{_PKG}.bot.strategy", fromlist=["_stabbed"])
_win = __import__(f"{_PKG}.heuristics.win", fromlist=["compute_build_delta"])
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])

parse_now = _now.parse_now
parse_now_unit = _now.parse_now_unit
snapshot_province_state = _snapshot.snapshot_province_state
_stabbed = _strategy._stabbed
compute_build_delta = _win.compute_build_delta
InnerGameState = _state.InnerGameState


def test_compute_build_delta_preserves_empty_centres_and_applies_fall_capture():
    state = InnerGameState()
    retained_sc, captured_sc, non_sc = 10, 11, 12
    state.sc_provinces = {retained_sc, captured_sc}
    state.g_sc_owner[retained_sc] = 0
    state.g_sc_owner[captured_sc] = 1
    state.unit_info = {
        captured_sc: {"power": 2, "type": "A", "coast": ""},
        non_sc: {"power": 2, "type": "A", "coast": ""},
    }

    assert compute_build_delta(state)

    assert state.g_sc_owner[retained_sc] == 0
    assert state.g_sc_owner[captured_sc] == 2
    assert state.g_sc_owner[non_sc] == 2
    assert state.sc_count[:3].tolist() == [1, 0, 1]
    assert state.g_board_sc_ownership[0, retained_sc] == 1
    assert state.g_board_sc_ownership[1, captured_sc] == 0
    assert state.g_board_sc_ownership[2, captured_sc] == 1
    assert state.g_build_delta[0] == {"flag": 1, "delta": 1}
    assert state.g_build_delta[1] == {"flag": 0, "delta": 0}
    assert state.g_build_delta[2] == {"flag": 0, "delta": 1}


def test_winter_now_computes_build_delta_before_hlo():
    state = InnerGameState()
    state.prov_to_id = {"VIE": 10}
    state.sc_provinces = {10}
    state.g_sc_owner[10] = 0

    assert parse_now(state, "NOW ( WIN 1901 ) ( AUS AMY VIE )")

    assert state.g_build_delta[0] == {"flag": 0, "delta": 0}


def test_winter_now_materializes_only_controlled_empty_own_home_centers():
    state = InnerGameState()
    state.prov_to_id = {"VIE": 10, "BUD": 11, "TRI": 12, "MUN": 13}
    state.sc_provinces = {10, 11, 12, 13}
    state.home_centers = {
        0: frozenset({10, 11, 12}),
        3: frozenset({13}),
    }
    state.albert_power_idx = 0
    state.g_hlo_received = True
    state.g_sc_owner[10] = 0  # own, empty, legal
    state.g_sc_owner[11] = 0  # own, but occupied below
    state.g_sc_owner[12] = 3  # own home, enemy-controlled
    state.g_sc_owner[13] = 0  # captured foreign home, never a legal site

    assert parse_now(state, "NOW ( WIN 1901 ) ( AUS AMY BUD )")

    assert state.g_available_home_centers == frozenset({10})


def test_non_winter_now_clears_available_home_center_snapshot():
    state = InnerGameState()
    state.prov_to_id = {"VIE": 10}
    state.g_available_home_centers = frozenset({10})

    assert parse_now(state, "NOW ( SPR 1902 ) ( AUS AMY VIE )")

    assert state.g_available_home_centers == frozenset()


def test_canonical_now_header_and_mrt_record_use_separate_unit_sets():
    state = InnerGameState()
    state.prov_to_id = {"ENG": 1, "LON": 2, "IRI": 3}

    assert parse_now(
        state,
        "NOW ( SUM 1902 ) "
        "( FRA FLT ENG ) "
        "( ENG FLT ENG MRT ( LON IRI ) )",
    )

    assert state.g_season == "SUM"
    assert state.g_year == 1902
    assert state.unit_info == {
        1: {"power": 2, "type": "F", "coast": ""},
    }
    assert state.dislodged_unit_info[1] == {
        "power": 1,
        "type": "F",
        "coast": "",
        "retreats": [
            {"province": 2, "coast": ""},
            {"province": 3, "coast": ""},
        ],
    }


def test_now_coast_location_is_not_mistaken_for_dislodgement():
    state = InnerGameState()
    state.prov_to_id = {"STP": 7}

    assert parse_now(state, "NOW ( SPR 1901 ) ( RUS FLT ( STP SCS ) )")

    assert state.unit_info[7] == {
        "power": 5,
        "type": "F",
        "coast": "SC",
    }
    assert state.dislodged_unit_info == {}


def test_daide_coast_normalization_preserves_coast_specific_reachability():
    state = InnerGameState()
    state.prov_to_id = {"STP": 7, "BOT": 8, "BAR": 9}
    state.fleet_coast_adj = {
        (7, "/SC"): [8],
        (7, "/NC"): [9],
    }

    assert parse_now_unit(state, ["RUS", "FLT", ["STP", "SCS"]])

    coast = state.unit_info[7]["coast"]
    assert coast == "SC"
    assert state.can_reach_by_type(7, 8, "F", coast)
    assert not state.can_reach_by_type(7, 9, "F", coast)


def test_resolved_south_coast_move_uses_scs_numeric_token():
    state = InnerGameState()
    state.fleet_coast_adj = {(7, "/SC"): [8]}

    assert state.resolve_fleet_coast(8, 7) == 0x4608


def test_dislodged_retreat_coast_is_normalized_for_order_serialization():
    state = InnerGameState()
    state.prov_to_id = {"ENG": 1, "SPA": 2}

    assert parse_now_unit(
        state,
        ["ENG", "FLT", "ENG", "MRT", [["SPA", "SCS"]]],
    )

    assert state.dislodged_unit_info[1]["retreats"] == [
        {"province": 2, "coast": "SC"},
    ]


def test_synchronize_from_game_filters_starred_units_from_active_board():
    game = Game()
    power_names = list(game.powers)
    units = {name: [] for name in power_names}
    retreats = {name: {} for name in power_names}
    units["ENGLAND"] = ["F NTH", "*F ENG"]
    units["FRANCE"] = ["F ENG"]
    retreats["ENGLAND"] = {"F ENG": ["LON", "IRI"]}
    game.set_state({"name": "S1902R", "units": units, "retreats": retreats})

    state = InnerGameState()
    state.synchronize_from_game(game)
    eng = state.prov_to_id["ENG"]

    assert state.unit_info[eng]["power"] == 2
    assert state.unit_info[eng]["type"] == "F"
    assert state.dislodged_unit_info[eng] == {
        "power": 1,
        "type": "F",
        "coast": "",
        "retreats": ["LON", "IRI"],
    }


def test_synchronize_matches_coasted_result_to_base_history_record():
    base_game = Game()

    class HistoryGame:
        map = base_game.map
        powers = base_game.powers
        order_history = {
            "S1901M": {"RUSSIA": ["F STP/SC H"]},
        }
        result_history = {
            "S1901M": {"F STP/SC": ["bounce"]},
        }

        @staticmethod
        def get_centers():
            return base_game.get_centers()

        @staticmethod
        def get_units():
            return base_game.get_units()

        @staticmethod
        def get_current_phase():
            return base_game.get_current_phase()

    state = InnerGameState()
    state.synchronize_from_game(HistoryGame())

    record = state.g_order_hist_list[0]
    assert record["src_province"] == state.prov_to_id["STP"]
    assert record["src_coast"] == "SC"
    assert record["flag_b"] == 1


def test_snapshot_and_stabbed_compare_active_units_with_sc_control():
    state = InnerGameState()
    state.g_num_powers = 3
    state.albert_power_idx = 0
    state.g_season = "SPR"
    state.unit_info[5] = {"power": 1, "type": "F", "coast": ""}
    state.sc_provinces = {5}
    state.g_sc_owner[5] = 0

    snapshot_province_state(state)

    assert int(state.g_ally_designation_b[5]) == 0  # SC controller
    assert int(state.g_ally_designation_a[5]) == 1

    _stabbed(state)

    assert int(state.g_stab_flag[0, 1]) == 1
