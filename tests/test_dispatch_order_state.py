"""Source-backed g_order_table coverage for DispatchSingleOrder."""

import os
import sys


_PKG_ROOT = os.path.dirname(os.path.dirname(__file__))
_PARENT = os.path.dirname(_PKG_ROOT)
if _PARENT not in sys.path:
    sys.path.insert(0, _PARENT)

_PKG = os.path.basename(_PKG_ROOT)
_state = __import__(f"{_PKG}.state", fromlist=["InnerGameState"])
_orders = __import__(
    f"{_PKG}.dispatch.orders", fromlist=["dispatch_single_order"]
)

InnerGameState = _state.InnerGameState
dispatch_single_order = _orders.dispatch_single_order
_moves = __import__(
    f"{_PKG}.moves",
    fromlist=["assign_support_order", "build_order_sup_hld"],
)
assign_support_order = _moves.assign_support_order
build_order_sup_hld = _moves.build_order_sup_hld


def _state_with_provinces() -> InnerGameState:
    state = InnerGameState()
    state.prov_to_id = {
        "LON": 10,
        "NTH": 11,
        "STP": 12,
        "STP/NC": 112,
        "STP/SC": 113,
    }
    state._id_to_prov = {pid: name for name, pid in state.prov_to_id.items()}
    return state


def test_dispatch_hold_writes_complete_source_order_record():
    state = _state_with_provinces()
    state.unit_info = {10: {"power": 0, "type": "A", "coast": ""}}
    state.final_score_set[0, 10] = 321

    dispatch_single_order(
        state, 0, {"type": "HLD", "unit": "A LON", "src_prov": 10}
    )

    assert state.g_order_table[10, 0] == 1
    assert state.g_order_table[10, 2] == 10
    assert state.g_order_table[10, 3] == 0x4200
    assert state.g_order_table[10, 6] == 321
    assert state.g_order_table[10, 7] == 0
    assert state.g_order_table[10, 13] == 1

    dispatch_single_order(
        state,
        0,
        {"type": "MTO", "unit": "A LON", "src_prov": 10,
         "target": "STP"},
    )
    assert state.g_order_table[10, 0] == 1
    assert state.g_submitted_orders == ["A LON H"]

    dispatch_single_order(
        state,
        0,
        {"type": "HLD", "unit": "A LON", "src_prov": 10},
        format_existing=True,
    )
    assert state.g_order_table[10, 0] == 1
    assert state.g_submitted_orders == ["A LON H", "A LON H"]


def test_dispatch_mto_preserves_coast_map_score_and_history():
    state = _state_with_provinces()
    state.unit_info = {11: {"power": 0, "type": "F", "coast": ""}}
    state.final_score_set_flt[0, 112] = 444
    state.g_move_history_matrix[0, 11, 12] = 7

    dispatch_single_order(
        state,
        0,
        {"type": "MTO", "unit": "F NTH", "src_prov": 11,
         "target": "STP/NC"},
    )

    assert state.g_order_table[11, 0] == 2
    assert state.g_order_table[11, 2] == 12
    assert state.g_order_table[11, 3] == 0x4600
    assert state.g_order_table[12, 6] == 444
    assert state.g_order_table[12, 17] == 7
    assert state.g_order_table[12, 13] == 1
    assert state.g_convoy_dst_list == [12]
    assert state.g_convoy_dst_to_src == {12: 11}
    assert state.g_submitted_orders == ["F NTH - STP/NC"]


def test_dispatch_mto_caches_destination_occupants_conflicting_move():
    state = _state_with_provinces()
    state.prov_to_id['BEL'] = 20
    state.prov_to_id['HOL'] = 21
    state._id_to_prov.update({20: 'BEL', 21: 'HOL'})
    state.unit_info = {
        10: {"power": 0, "type": "A", "coast": ""},
        20: {"power": 1, "type": "A", "coast": ""},
    }
    state.g_order_table[20, 0] = 2
    state.g_order_table[20, 2] = 21
    state.g_order_table[21, 20] = 1
    state.g_convoy_source_prov[21] = 20

    dispatch_single_order(
        state,
        0,
        {"type": "MTO", "unit": "A LON", "src_prov": 10,
         "target": "BEL"},
    )

    assert state.g_last_mto_insert == (2, 21)
    assert int(state.g_order_table[21, 20]) == 0
    assert int(state.g_convoy_source_prov[21]) == -1


def test_dispatch_plain_fleet_move_preserves_flt_destination_token():
    state = _state_with_provinces()
    state.prov_to_id["ENG"] = 13
    state._id_to_prov[13] = "ENG"
    state.unit_info = {11: {"power": 0, "type": "F", "coast": ""}}

    dispatch_single_order(
        state,
        0,
        {"type": "MTO", "unit": "F NTH", "src_prov": 11,
         "target": "ENG"},
    )

    assert state.g_order_table[11, 3] == 0x4201


def test_dispatch_cto_writes_route_depth_legs_and_destination_score():
    state = _state_with_provinces()
    state.unit_info = {10: {"power": 0, "type": "A", "coast": ""}}
    state.final_score_set[0, 12] = 555

    dispatch_single_order(
        state,
        0,
        {"type": "CTO", "unit": "A LON", "src_prov": 10,
         "target_dest": "STP", "convoy_legs": [11, 20, 21]},
    )

    assert state.g_order_table[10, 0] == 6
    assert state.g_order_table[10, 2] == 12
    assert state.g_order_table[10, 23] == 3
    assert tuple(state.g_order_table[10, 26:29]) == (11, 20, 21)
    assert state.g_order_table[12, 6] == 555
    assert state.g_order_table[12, 13] == 1
    assert state.g_convoy_dst_to_src == {12: 10}

    second = _state_with_provinces()
    second.unit_info = {10: {"power": 0, "type": "A", "coast": ""}}
    dispatch_single_order(
        second,
        0,
        {"type": "CTO", "unit": "A LON", "src_prov": 10,
         "target_dest": "STP", "convoy_legs": [1, 2, 3, 4]},
    )
    assert not second.g_order_table.any()
    assert second.g_submitted_orders == []


def test_trial_dispatch_cto_uses_explicit_via_without_submitting():
    state = _state_with_provinces()
    state.unit_info = {10: {"power": 0, "type": "A", "coast": ""}}

    dispatch_single_order(
        state,
        0,
        {"type": "CTO", "unit": "A LON", "src_prov": 10,
         "target_dest": "STP", "convoy_legs": [11, 20]},
        record_submission=False,
    )

    assert state.g_order_table[10, 0] == 6
    assert state.g_order_table[10, 23] == 2
    assert tuple(state.g_order_table[10, 26:28]) == (11, 20)
    assert state.g_submitted_orders == []


def test_dispatch_cvy_writes_army_source_token_and_fleet_score():
    state = _state_with_provinces()
    state.unit_info = {
        10: {"power": 0, "type": "A", "coast": ""},
        11: {"power": 0, "type": "F", "coast": ""},
    }
    state.g_max_prov_score_per_power[0, 11] = 777

    dispatch_single_order(
        state,
        0,
        {"type": "CVY", "unit": "F NTH", "src_prov": 11,
         "target_unit": "A LON", "target_dest": "STP"},
    )

    assert state.g_order_table[11, 0] == 5
    assert state.g_order_table[11, 1] == 10
    assert state.g_order_table[11, 2] == 12
    assert state.g_order_table[11, 3] == 0x4200
    assert state.g_order_table[11, 6] == 777
    assert state.g_order_table[11, 7] == 0
    assert state.g_order_table[11, 13] == 1


def test_dispatch_support_uses_recovered_support_builders_and_side_effects():
    state = _state_with_provinces()
    state.unit_info = {
        10: {"power": 0, "type": "A", "coast": ""},
        11: {"power": 1, "type": "F", "coast": ""},
    }
    state.final_score_set[0, 10] = 246

    dispatch_single_order(
        state,
        0,
        {"type": "SUP", "unit": "A LON", "src_prov": 10,
         "target_unit": "F NTH"},
    )

    assert state.g_order_table[10, 0] == 3
    assert state.g_order_table[10, 2] == 11
    assert state.g_order_table[10, 6] == 246
    assert state.g_order_table[10, 13] == 1
    # Zero threat takes BuildOrder_SUP_HLD's safe-chain path.
    assert state.g_order_table[11, 13] == 1
    # Supporting another power also executes the recovered trust side effect.
    assert state.g_support_trust_adj == 30
    assert state.g_convoy_active_flag[11] == 1


def test_public_support_builder_overwrites_an_existing_order_record():
    state = _state_with_provinces()
    state.unit_info = {
        10: {"power": 0, "type": "A", "coast": ""},
        11: {"power": 0, "type": "F", "coast": ""},
    }

    dispatch_single_order(
        state, 0, {"type": "HLD", "unit": "A LON", "src_prov": 10}
    )
    build_order_sup_hld(state, 0, 10, 11)

    # The recovered builder itself writes unconditionally. DispatchSingleOrder
    # has its own upstream node-order guard, but direct ProcessTurn builder
    # calls must not acquire a second, invented guard.
    assert int(state.g_order_table[10, 0]) == 3
    assert int(state.g_order_table[10, 2]) == 11


def test_support_move_chain_checks_attack_target_not_mover_adjacency():
    state = _state_with_provinces()
    state.unit_info = {
        10: {"power": 0, "type": "A", "coast": ""},
        11: {"power": 0, "type": "A", "coast": ""},
        20: {"power": 1, "type": "A", "coast": ""},
    }
    state.adj_matrix = {20: [10, 11]}
    state.g_threat_level[0, 10] = 1
    state.g_enemy_reach_score[0, 10] = 1
    state.g_enemy_presence[0, 20] = 1

    dispatch_single_order(
        state,
        0,
        {"type": "SUP", "unit": "A LON", "src_prov": 10,
         "target_unit": "A NTH", "target_dest": "STP"},
    )

    # The hostile unit can reach the supporter and mover, but not the attack
    # target. BuildOrder_SUP_MTO therefore marks a cut-chain conflict. The old
    # nested ProcessTurn copy tested mover adjacency and treated it as safe.
    assert state.g_order_table[12, 13] == 0
    assert state.g_order_table[12, 14] == 1


def _state_for_support_commit(source_demand: int) -> InnerGameState:
    state = _state_with_provinces()
    state.g_support_demand[10] = source_demand
    state.g_support_demand[12] = 1
    state.g_own_reach_score[0, 12] = 2
    state.g_order_table[12, 18] = -1
    state.g_order_table[12, 19] = -1
    return state


def test_support_commit_bypasses_home_center_gate_for_source_demand_one():
    state = _state_for_support_commit(1)
    state.g_sc_owner[12] = 4

    assign_support_order(state, 0, 10, 12, 0)

    assert int(state.g_order_table[12, 20]) == 1
    assert int(state.g_convoy_source_prov[12]) == 10


def test_support_commit_rejects_source_demand_other_than_zero_or_one():
    state = _state_for_support_commit(2)
    state.home_centers[0] = frozenset({12})
    state.g_sc_owner[12] = 0

    assign_support_order(state, 0, 10, 12, 0)

    assert int(state.g_order_table[12, 20]) == 0


def test_support_commit_uses_current_controller_without_adjacency_requirement():
    state = _state_for_support_commit(0)
    state.home_centers[0] = frozenset({12})
    state.g_sc_owner[12] = 0
    state.adj_matrix = {}

    assign_support_order(state, 0, 10, 12, 0)

    assert int(state.g_order_table[12, 20]) == 1


def test_support_commit_rejects_enemy_presence_at_destination():
    state = _state_for_support_commit(1)
    state.g_enemy_presence[0, 12] = 1

    assign_support_order(state, 0, 10, 12, 0)

    assert int(state.g_order_table[12, 20]) == 0


def test_public_support_move_clears_pending_target_assignment():
    state = _state_with_provinces()
    state.unit_info = {
        10: {"power": 0, "type": "A", "coast": ""},
        11: {"power": 0, "type": "A", "coast": ""},
    }
    state.g_order_table[12, 20] = 1
    state.g_convoy_source_prov[12] = 11

    dispatch_single_order(
        state,
        0,
        {"type": "SUP", "unit": "A LON", "src_prov": 10,
         "target_unit": "A NTH", "target_dest": "STP"},
    )

    assert int(state.g_order_table[12, 20]) == 0
    assert int(state.g_convoy_source_prov[12]) == -1


def test_assign_support_uses_destination_units_typed_reach_to_source():
    state = InnerGameState()
    source = 10
    destination = 20
    state.unit_info = {
        source: {"power": 0, "type": "F", "coast": ""},
        destination: {"power": 1, "type": "A", "coast": ""},
    }
    state.adj_matrix = {source: [destination], destination: [source]}
    state.fleet_adj_matrix = {source: [destination]}
    state.water_provinces = {source}
    state.g_enemy_reach_score[0, source] = 1
    state.g_enemy_presence[0, destination] = 1
    state.g_coverage_flag[1, source] = 1
    state.final_score_set_flt[0, source] = 10
    state.final_score_set_flt[0, destination] = 100
    state.g_order_table[source, 18:20] = -1

    assign_support_order(state, 0, source, destination, 0)

    # The army at destination cannot enter the sea source, so C's typed
    # destination→source adjacency confirmation fails and the score stays unset.
    assert tuple(state.g_order_table[source, 18:20]) == (-1, -1)
    assert int(state.g_proximity_score[1, source]) == 0


def test_assign_support_sc_gate_uses_controller_not_fleet_unit_token():
    state = InnerGameState()
    source, destination = 10, 20
    state.unit_info[source] = {"power": 0, "type": "F", "coast": ""}
    state.sc_provinces = {source}
    state.g_sc_owner[source] = 0
    state.final_score_set_flt[0, source] = 10
    state.final_score_set_flt[0, destination] = 100

    assign_support_order(state, 0, source, destination, 0)

    # +0x20 stores the SC controller's 0x41xx power token.  C therefore takes
    # the score branch for an own-controlled centre regardless of unit type.
    assert state.g_order_table[source, 18] == 10


def test_assign_support_sc_gate_does_not_use_army_occupant_as_controller():
    state = InnerGameState()
    source, destination = 10, 20
    state.unit_info[source] = {"power": 0, "type": "A", "coast": ""}
    state.sc_provinces = {source}
    state.g_sc_owner[source] = 1
    state.final_score_set[0, source] = 10
    state.final_score_set[0, destination] = 100

    assign_support_order(state, 0, source, destination, 0)

    # A foreign-controlled source SC followed by a non-SC destination takes
    # LAB_0044150f even when Albert's army currently occupies the source.
    assert state.g_order_table[source, 18] == 0
