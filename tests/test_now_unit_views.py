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
    fromlist=["parse_now"],
)
_snapshot = __import__(
    f"{_PKG}.heuristics.snapshot", fromlist=["snapshot_province_state"]
)
_strategy = __import__(f"{_PKG}.bot.strategy", fromlist=["_stabbed"])
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])

parse_now = _now.parse_now
snapshot_province_state = _snapshot.snapshot_province_state
_stabbed = _strategy._stabbed
InnerGameState = _state.InnerGameState


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
        "coast": "/SCS",
    }
    assert state.dislodged_unit_info == {}


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
