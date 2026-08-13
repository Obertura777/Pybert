"""Focused parity tests for ProcessTurn's two designation readers."""

import os
import sys


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state = __import__(f"{_pkg_name}.state", fromlist=["InnerGameState"])
_trial = __import__(
    f"{_pkg_name}.monte_carlo.trial",
    fromlist=["_step3_designation_trust", "_apply_step3_support_filter"],
)

InnerGameState = _state.InnerGameState
_step3_designation_trust = _trial._step3_designation_trust
_apply_step3_support_filter = _trial._apply_step3_support_filter


DEST = 17
POWER = 1
OWN_POWER = 0


def _state_with_designations(c=2, a=3, b=4):
    state = InnerGameState()
    for name, designated_power in (("c", c), ("a", a), ("b", b)):
        getattr(state, f"g_ally_designation_{name}")[DEST] = designated_power
        getattr(state, f"g_ally_designation_{name}_hi")[DEST] = 0
        state.g_relation_score[POWER, designated_power] = 10
        state.g_ally_trust_score[POWER, designated_power] = designated_power * 10
        state.g_ally_trust_score_hi[POWER, designated_power] = designated_power
    return state


def test_step3_slot_b_overwrites_c_and_a():
    state = _state_with_designations()

    assert _step3_designation_trust(state, POWER, OWN_POWER, DEST) == (40, 4)


def test_step3_slot_a_overwrites_c_when_b_is_unset_and_threat_is_low():
    state = _state_with_designations()
    state.g_ally_designation_b_hi[DEST] = -1
    state.g_threat_level[3, DEST] = 1

    assert _step3_designation_trust(state, POWER, OWN_POWER, DEST) == (30, 3)


def test_step3_slot_a_does_not_overwrite_c_when_threat_is_two_or_more():
    state = _state_with_designations()
    state.g_ally_designation_b_hi[DEST] = -1
    state.g_threat_level[3, DEST] = 2

    assert _step3_designation_trust(state, POWER, OWN_POWER, DEST) == (20, 2)


def test_step3_slot_a_does_not_apply_when_it_designates_power_index():
    state = _state_with_designations(a=POWER)
    state.g_ally_designation_b_hi[DEST] = -1
    state.g_threat_level[POWER, DEST] = 0

    assert _step3_designation_trust(state, POWER, OWN_POWER, DEST) == (20, 2)


def test_step3_reachable_destination_does_not_register_support():
    state = InnerGameState()
    state.g_support_opp_map = {}

    threshold = _apply_step3_support_filter(
        state, POWER, OWN_POWER, 8, [(50.0, DEST)], 100.0, {DEST: True}
    )

    assert threshold == 100.0
    assert state.g_support_opp_map == {}


def test_step3_records_first_ordinary_support_opportunity():
    state = InnerGameState()
    state.g_support_opp_map = {}

    threshold = _apply_step3_support_filter(
        state, POWER, OWN_POWER, 8, [(50.0, DEST), (40.0, 18)], 100.0, {}
    )

    assert threshold == 100.0
    assert state.g_support_opp_map == {8: DEST}


def test_step3_class1_candidate_at_threshold_updates_threshold_and_exits():
    state = InnerGameState()
    state.g_support_opp_map = {}
    state.g_prov_target_flag[POWER, DEST] = 1

    threshold = _apply_step3_support_filter(
        state, POWER, OWN_POWER, 8, [(120.0, DEST), (40.0, 18)], 100.0, {}
    )

    assert threshold == 120.0
    assert state.g_support_opp_map == {}


def test_step3_class1_candidate_below_threshold_is_kept_without_update():
    state = InnerGameState()
    state.g_support_opp_map = {}
    state.g_prov_target_flag[POWER, DEST] = 1

    threshold = _apply_step3_support_filter(
        state, POWER, OWN_POWER, 8, [(50.0, DEST)], 100.0, {}
    )

    assert threshold == 100.0
    assert state.g_support_opp_map == {}


def test_step3_claimed_class1_destination_registers_support():
    state = InnerGameState()
    state.g_support_opp_map = {}
    state.g_prov_target_flag[POWER, DEST] = 1
    state.g_order_table[DEST, 13] = 1

    _apply_step3_support_filter(
        state, POWER, OWN_POWER, 8, [(50.0, DEST)], 100.0, {}
    )

    assert state.g_support_opp_map == {8: DEST}
