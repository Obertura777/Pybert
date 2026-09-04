"""Unit-token legality regressions for the recovered IsLegalMove gates."""

import os
import sys


_PKG_ROOT = os.path.dirname(os.path.dirname(__file__))
_PARENT = os.path.dirname(_PKG_ROOT)
if _PARENT not in sys.path:
    sys.path.insert(0, _PARENT)

_PKG = os.path.basename(_PKG_ROOT)
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])
_legality = __import__(
    f"{_PKG}.dispatch.legality",
    fromlist=["_is_legal_mto", "is_convoy_reachable"],
)
_validator = __import__(
    f"{_PKG}.dispatch.validator",
    fromlist=["validate_and_dispatch_order"],
)
_alliance = __import__(
    f"{_PKG}.dispatch.alliance", fromlist=["check_order_alliance"]
)
_errors = __import__(f"{_PKG}.dispatch._errors", fromlist=["_ERR_ADJACENCY"])

InnerGameState = _state.InnerGameState
_is_legal_mto = _legality._is_legal_mto
is_convoy_reachable = _legality.is_convoy_reachable
validate_and_dispatch_order = _validator.validate_and_dispatch_order
check_order_alliance = _alliance.check_order_alliance
_ERR_ADJACENCY = _errors._ERR_ADJACENCY


def test_convoy_legality_direct_gate_rejects_fleet_army_only_border():
    state = InnerGameState()
    source, destination = 10, 11
    state.unit_info = {
        source: {"power": 0, "type": "F", "coast": ""},
    }
    state.adj_matrix = {source: [destination]}
    state.fleet_adj_matrix = {source: []}

    assert not is_convoy_reachable(state, source, "F", destination)


def test_move_and_convoy_direct_gates_use_live_multi_coast_token():
    state = InnerGameState()
    source, destination = 10, 11
    state.unit_info = {
        source: {"power": 0, "type": "F", "coast": "NC"},
    }
    state.adj_matrix = {source: [destination]}
    state.fleet_adj_matrix = {source: [destination]}
    state.fleet_coast_adj = {
        (source, "/NC"): [],
        (source, "/SC"): [destination],
    }

    assert not _is_legal_mto(state, source, destination, "F", "NC")
    assert not is_convoy_reachable(state, source, "F", destination)


def test_fleet_move_gate_is_destination_province_only_like_source():
    state = InnerGameState()
    source, destination, other_source = 10, 11, 12
    state.unit_info = {
        source: {"power": 0, "type": "F", "coast": ""},
    }
    state.adj_matrix = {source: [destination]}
    state.fleet_adj_matrix = {source: [destination]}
    state.fleet_coast_adj = {
        (destination, "/NC"): [other_source],
        (destination, "/SC"): [source],
    }

    assert _is_legal_mto(state, source, destination, "F", "")


def test_convoy_legality_keeps_direct_army_move_fast_path():
    state = InnerGameState()
    source, destination = 10, 11
    state.unit_info = {
        source: {"power": 0, "type": "A", "coast": ""},
    }
    state.adj_matrix = {source: [destination]}

    assert is_convoy_reachable(state, source, "AMY", destination)


def test_supporter_legality_rejects_fleet_across_army_only_border():
    state = InnerGameState()
    supporter, supported = 10, 11
    state.prov_to_id = {"LON": supporter, "PAR": supported}
    state.unit_info = {
        supporter: {"power": 0, "type": "F", "coast": ""},
        supported: {"power": 0, "type": "A", "coast": ""},
    }
    state.adj_matrix = {
        supporter: [supported],
        supported: [supporter],
    }
    state.fleet_adj_matrix = {supporter: []}

    result = validate_and_dispatch_order(
        state,
        0,
        {"type": "SUP", "unit": "F LON", "target_unit": "A PAR"},
        commit=False,
    )

    assert result == _ERR_ADJACENCY


def test_validator_parses_destination_coast_but_source_legality_ignores_it():
    state = InnerGameState()
    source, destination, other_source = 10, 11, 12
    state.prov_to_id = {"BOT": source, "STP": destination}
    state.unit_info = {
        source: {"power": 0, "type": "F", "coast": ""},
    }
    state.adj_matrix = {source: [destination]}
    state.fleet_adj_matrix = {source: [destination]}
    state.fleet_coast_adj = {
        (destination, "/NC"): [other_source],
        (destination, "/SC"): [source],
    }

    north = validate_and_dispatch_order(
        state,
        0,
        {"type": "MTO", "unit": "F BOT", "target": "STP/NC"},
        commit=False,
    )
    south = validate_and_dispatch_order(
        state,
        0,
        {"type": "MTO", "unit": "F BOT", "target": "STP/SC"},
        commit=False,
    )
    compound_south = validate_and_dispatch_order(
        state,
        0,
        {"type": "MTO", "unit": "F BOT",
         "target": {"province": "STP", "coast": "SC"}},
        commit=False,
    )

    assert north == 0
    assert south == 0
    assert compound_south == 0


def test_validator_rejects_unresolved_supported_and_convoy_units():
    state = InnerGameState()
    state.prov_to_id = {"LON": 10, "PAR": 11}
    state.unit_info = {
        10: {"power": 0, "type": "F", "coast": ""},
    }

    missing_supported = validate_and_dispatch_order(
        state,
        0,
        {"type": "SUP", "unit": "F LON", "target_unit": "A PAR"},
        commit=False,
    )
    missing_convoy_army = validate_and_dispatch_order(
        state,
        0,
        {"type": "CVY", "unit": "F LON", "target_unit": "A PAR",
         "target_dest": "LON"},
        commit=False,
    )
    unknown_convoy_destination = validate_and_dispatch_order(
        state,
        0,
        {"type": "CVY", "unit": "F LON", "target_unit": "A PAR",
         "target_dest": "XXX"},
        commit=False,
    )

    assert missing_supported != 0
    assert missing_convoy_army != 0
    assert unknown_convoy_destination != 0


def test_alliance_slots_use_high_word_as_activity_guard():
    state = InnerGameState()
    destination = 10
    state.g_ally_trust_score[0, 1] = 5

    for slot in ("a", "b", "c"):
        low = getattr(state, f"g_ally_designation_{slot}")
        high = getattr(state, f"g_ally_designation_{slot}_hi")
        low[destination] = 1
        high[destination] = -1
        assert check_order_alliance(state, 0, destination, 0, 2) == 0
        low[destination] = -1


def test_alliance_slots_enforce_trust_when_high_word_is_active():
    state = InnerGameState()
    destination = 10
    state.g_ally_trust_score[0, 1] = 5

    for slot in ("a", "b", "c"):
        low = getattr(state, f"g_ally_designation_{slot}")
        high = getattr(state, f"g_ally_designation_{slot}_hi")
        low[destination] = 1
        high[destination] = 0
        assert check_order_alliance(state, 0, destination, 0, 2) != 0
        low[destination] = -1
        high[destination] = -1
