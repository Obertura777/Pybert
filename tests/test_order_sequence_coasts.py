"""Recovered unit-token serialization regressions for support orders."""

import os
import sys


_PKG_ROOT = os.path.dirname(os.path.dirname(__file__))
_PARENT = os.path.dirname(_PKG_ROOT)
if _PARENT not in sys.path:
    sys.path.insert(0, _PARENT)

_PKG = os.path.basename(_PKG_ROOT)
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])
_constants = __import__(
    f"{_PKG}.monte_carlo",
    fromlist=[
        "_F_ORDER_TYPE", "_F_DEST_PROV", "_F_SECONDARY",
        "_F_DEST_COAST", "_ORDER_SUP_HLD", "_ORDER_SUP_MTO",
    ],
)
_bot_orders = __import__(
    f"{_PKG}.bot.orders", fromlist=["_build_order_seq_from_table"]
)
_validator = __import__(
    f"{_PKG}.dispatch.validator", fromlist=["validate_and_dispatch_order"]
)

InnerGameState = _state.InnerGameState
_build_order_seq_from_table = _bot_orders._build_order_seq_from_table
validate_and_dispatch_order = _validator.validate_and_dispatch_order

_F_ORDER_TYPE = _constants._F_ORDER_TYPE
_F_DEST_PROV = _constants._F_DEST_PROV
_F_SECONDARY = _constants._F_SECONDARY
_F_DEST_COAST = _constants._F_DEST_COAST
_ORDER_SUP_HLD = _constants._ORDER_SUP_HLD
_ORDER_SUP_MTO = _constants._ORDER_SUP_MTO

POR, SPA, MAR = 10, 11, 12


def _support_state() -> InnerGameState:
    state = InnerGameState()
    state.prov_to_id = {"POR": POR, "SPA": SPA, "MAR": MAR}
    state._id_to_prov = {value: key for key, value in state.prov_to_id.items()}
    state.unit_info = {
        POR: {"power": 0, "type": "A", "coast": ""},
        SPA: {"power": 0, "type": "F", "coast": "SC"},
    }
    state.adj_matrix = {POR: [SPA, MAR], SPA: [POR, MAR], MAR: [POR, SPA]}
    state.fleet_adj_matrix = {SPA: [POR, MAR]}
    return state


def test_support_hold_sequence_preserves_supported_fleet_coast_round_trip():
    state = _support_state()
    state.g_order_table[POR, _F_ORDER_TYPE] = _ORDER_SUP_HLD
    state.g_order_table[POR, _F_DEST_PROV] = SPA

    order_seq = _build_order_seq_from_table(state, POR)

    assert order_seq == {
        "type": "SUP", "unit": "A POR", "target_unit": "F SPA/SC",
    }
    assert validate_and_dispatch_order(
        state, 0, order_seq, format_existing=True
    ) == 0
    assert state.g_submitted_orders == ["A POR S F SPA/SC"]


def test_support_move_sequence_preserves_supported_fleet_source_coast():
    state = _support_state()
    state.g_order_table[POR, _F_ORDER_TYPE] = _ORDER_SUP_MTO
    state.g_order_table[POR, _F_SECONDARY] = SPA
    state.g_order_table[POR, _F_DEST_PROV] = MAR
    state.g_order_table[POR, _F_DEST_COAST] = 0

    assert _build_order_seq_from_table(state, POR) == {
        "type": "SUP",
        "unit": "A POR",
        "target_unit": "F SPA/SC",
        "target_dest": "MAR",
        "target_coast": "",
    }
