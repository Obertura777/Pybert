"""WIN army substitution and send_GOF's post-commit pause draw.

Pinned against the Albert.exe disassembly: FUN_0044bd40 0x0044c618-0x0044c82c
(army-for-fleet switch, DAT_00baed34 per build and once for a waive),
FUN_00442040 0x004421b4 (per removal), CommitMoveCandidatesPostPress
0x00441f73 (per retreat), send_GOF 0x00456c03 (reset) and
0x0045745e-0x004574c6 (Sleep with a (rand()/23)%6000 jitter before SUB).
"""

import os
import sys
from unittest.mock import patch


_pkg_root = os.path.dirname(os.path.dirname(__file__))
_parent = os.path.dirname(_pkg_root)
if _parent not in sys.path:
    sys.path.insert(0, _parent)

_pkg_name = os.path.basename(_pkg_root)
_state_mod = __import__(f'{_pkg_name}.state', fromlist=['InnerGameState'])
_win_mod = __import__(
    f'{_pkg_name}.heuristics.win',
    fromlist=['compute_win_builds', 'compute_win_removes'],
)
_scoring_mod = __import__(
    f'{_pkg_name}.heuristics.scoring',
    fromlist=['score_provinces', 'score_order_candidates_own_power'],
)
_rng = __import__(f'{_pkg_name}.rng', fromlist=['seed'])
_client_mod = __import__(f'{_pkg_name}.bot.client', fromlist=['AlbertClient'])
_orders_mod = __import__(f'{_pkg_name}.bot.client._orders', fromlist=['_OrdersMixin'])

InnerGameState = _state_mod.InnerGameState
AlbertClient = _client_mod.AlbertClient
compute_win_builds = _win_mod.compute_win_builds
compute_win_removes = _win_mod.compute_win_removes

AUS = 0


def _seed_with_first_draw(predicate) -> int:
    """Return a CRT seed whose first (rand()/23)%100 satisfies predicate."""
    for seed in range(1, 1000):
        _rng.seed(seed)
        if predicate(_rng.randrange(100)):
            return seed
    raise AssertionError('no seed found')


def _one_step(seed: int) -> int:
    _rng.seed(seed)
    _rng.raw_rand()
    return _rng.getstate()


def _build_state(monkeypatch, armies: int, fleets: int, candidates, scores):
    state = InnerGameState()
    state.albert_power_idx = AUS
    state.win_threshold = 18
    state._id_to_prov = {10: 'TRI', 11: 'VIE', 12: 'BUD'}
    state.unit_info = {}
    prov = 40
    for _ in range(armies):
        state.unit_info[prov] = {'power': AUS, 'type': 'A', 'coast': ''}
        prov += 1
    for _ in range(fleets):
        state.unit_info[prov] = {'power': AUS, 'type': 'F', 'coast': ''}
        prov += 1
    # Another power's fleets never enter Albert's own-unit set (+0x24b4).
    state.unit_info[90] = {'power': 1, 'type': 'F', 'coast': ''}
    state.g_adjustment_build_candidates = list(candidates)
    monkeypatch.setattr(_scoring_mod, 'score_provinces', lambda *args: None)

    def fixed_scores(candidate_state, *_args):
        candidate_state.g_adjustment_candidate_scores = dict(scores)

    monkeypatch.setattr(
        _scoring_mod, 'score_order_candidates_own_power', fixed_scores
    )
    return state


def test_fleet_heavy_power_near_the_win_threshold_builds_an_army(monkeypatch):
    # 2 armies, 6 fleets: 8*100/18 = 44 > 42 and 200/6 = 33.0 < 35.0.
    state = _build_state(
        monkeypatch, 2, 6,
        [{'province': 10, 'unit_type': 'FLT', 'coast': ''}],
        {(10, 'FLT', ''): 50},
    )
    seed = _seed_with_first_draw(lambda draw: draw < 50)
    _rng.seed(seed)

    compute_win_builds(state, 1)

    assert state.g_build_order_list == ['( AUS AMY TRI ) BLD']
    assert state.g_selected_build_candidates == [
        {'province': 10, 'unit_type': 'AMY', 'coast': ''},
    ]
    assert _rng.getstate() == _one_step(seed)


def test_failed_draw_keeps_the_fleet(monkeypatch):
    state = _build_state(
        monkeypatch, 2, 6,
        [{'province': 10, 'unit_type': 'FLT', 'coast': ''}],
        {(10, 'FLT', ''): 50},
    )
    seed = _seed_with_first_draw(lambda draw: draw >= 50)
    _rng.seed(seed)

    compute_win_builds(state, 1)

    assert state.g_build_order_list == ['( AUS FLT TRI ) BLD']
    assert _rng.getstate() == _one_step(seed)


def test_no_draw_unless_every_preceding_condition_holds(monkeypatch):
    cases = [
        # (armies, fleets, threat, unit type)
        (2, 6, 1, 'FLT'),    # threatened site
        (2, 6, 0, 'AMY'),    # already an army
        (2, 5, 0, 'FLT'),    # 7*100/18 = 38, not past 42
        (3, 6, 0, 'FLT'),    # 300/6 = 50.0, not below 35.0
    ]
    for armies, fleets, threat, unit_type in cases:
        state = _build_state(
            monkeypatch, armies, fleets,
            [{'province': 10, 'unit_type': unit_type, 'coast': ''}],
            {(10, unit_type, ''): 50},
        )
        state.g_threat_level[AUS, 10] = threat
        _rng.seed(7)

        compute_win_builds(state, 1)

        assert state.g_build_order_list == [f'( AUS {unit_type} TRI ) BLD']
        assert _rng.getstate() == 7, (armies, fleets, threat, unit_type)


def test_fleetless_power_uses_a_ratio_of_one_hundred(monkeypatch):
    # 8 armies, 0 fleets: the ratio is 100.0, so a fleet build is never switched.
    state = _build_state(
        monkeypatch, 8, 0,
        [{'province': 10, 'unit_type': 'FLT', 'coast': ''}],
        {(10, 'FLT', ''): 50},
    )
    _rng.seed(7)

    compute_win_builds(state, 1)

    assert state.g_build_order_list == ['( AUS FLT TRI ) BLD']
    assert _rng.getstate() == 7


def test_counts_include_builds_already_chosen_this_pass(monkeypatch):
    # First build switches to an army: 3 armies vs 6 fleets gives 50.0, so the
    # second build's condition fails before its draw.
    state = _build_state(
        monkeypatch, 2, 6,
        [
            {'province': 10, 'unit_type': 'FLT', 'coast': ''},
            {'province': 11, 'unit_type': 'FLT', 'coast': ''},
        ],
        {(10, 'FLT', ''): 50, (11, 'FLT', ''): 40},
    )
    seed = _seed_with_first_draw(lambda draw: draw < 50)
    _rng.seed(seed)

    compute_win_builds(state, 2)

    assert state.g_build_order_list == [
        '( AUS AMY TRI ) BLD',
        '( AUS FLT VIE ) BLD',
    ]
    assert _rng.getstate() == _one_step(seed)


def test_each_build_and_one_waive_are_counted(monkeypatch):
    state = _build_state(
        monkeypatch, 1, 0,
        [{'province': 10, 'unit_type': 'AMY', 'coast': ''}],
        {(10, 'AMY', ''): 50},
    )
    state.g_order_commit_count = 0
    calls = []
    monkeypatch.setattr(
        _scoring_mod, 'score_provinces', lambda *args: calls.append('score')
    )

    compute_win_builds(state, 3)

    assert state.g_build_order_list == ['( AUS AMY TRI ) BLD']
    assert state.g_waive_count == 2
    assert state.g_order_commit_count == 2
    # The candidate-count test precedes rescoring: no scoring once none remain.
    assert calls == ['score']


def test_each_removal_is_counted():
    state = InnerGameState()
    state.albert_power_idx = AUS
    state._id_to_prov = {10: 'TRI', 11: 'VIE', 12: 'BUD'}
    state.unit_info = {
        prov: {'power': AUS, 'type': 'A', 'coast': ''} for prov in (10, 11, 12)
    }
    state.g_adjustment_candidate_provinces = {10, 11, 12}
    state.g_order_commit_count = 0

    compute_win_removes(state, 2)

    assert len(state.g_build_order_list) == 2
    assert state.g_order_commit_count == 2


# ── send_GOF pause draw ───────────────────────────────────────────────────────

def _client() -> AlbertClient:
    client = AlbertClient('AUSTRIA', 'example.invalid', 8432)
    client.state.albert_power_idx = AUS
    client.game = None
    return client


def _reset_pass(state, *_args):
    state.g_order_commit_count = 0
    return []


def _run_win_pass(client, commits: int):
    state = client.state
    state.g_build_delta = {AUS: {'flag': 1, 'delta': 1}}
    events = []

    def builds(build_state, _delta):
        build_state.g_order_commit_count += commits

    with (
        patch.object(_orders_mod, '_run_send_gof_candidate_pass', _reset_pass),
        patch.object(_orders_mod, 'populate_build_candidates', lambda *a: None),
        patch.object(_orders_mod, 'score_provinces', lambda *a: None),
        patch.object(_orders_mod, 'score_order_candidates_own_power', lambda *a: None),
        patch.object(_orders_mod, 'compute_win_builds', builds),
        patch.object(AlbertClient, '_submit_adjustment_orders',
                     lambda self: events.append(('submit', _rng.getstate()))),
        patch.object(AlbertClient, '_await_press_and_send_gof',
                     lambda self: events.append(('await', _rng.getstate()))),
    ):
        _rng.seed(11)
        client._send_gof_pass('WIN', AUS, 7)
    return events


def test_adjustment_pass_draws_the_pause_jitter_before_sub():
    client = _client()
    client.state.g_order_commit_count = 5    # stale value from an earlier pass
    client.state.g_press_instant = 0

    events = _run_win_pass(client, 1)

    assert events == [('submit', _one_step(11)), ('await', _one_step(11))]


def test_no_pause_draw_without_commits_or_with_immediate_dispatch():
    client = _client()
    client.state.g_order_commit_count = 5
    client.state.g_press_instant = 0
    assert _run_win_pass(client, 0) == [('submit', 11), ('await', 11)]

    client = _client()
    client.state.g_press_instant = 1
    assert _run_win_pass(client, 2) == [('submit', 11), ('await', 11)]


def test_retreat_pass_counts_each_retreat_and_draws_before_sub():
    client = _client()
    client.game = object()
    client.state.g_press_instant = 0
    events = []
    records = [
        {'province': 10, 'unit_type': 'A', 'order_type': 7},
        {'province': 11, 'unit_type': 'F', 'order_type': 8},
    ]

    with (
        patch.object(_orders_mod, '_run_send_gof_candidate_pass', _reset_pass),
        patch.object(_orders_mod, '_populate_retreat_orders',
                     lambda *a: list(records)),
        patch.object(_orders_mod, '_format_retreat_commands',
                     lambda _state: ['A TRI R VEN', 'F VIE D']),
        patch.object(AlbertClient, '_validate_orders', lambda self, orders: None),
        patch.object(AlbertClient, '_schedule_set_orders',
                     lambda self, orders: events.append(('submit', _rng.getstate()))),
        patch.object(AlbertClient, '_await_press_and_send_gof',
                     lambda self: events.append(('await', _rng.getstate()))),
    ):
        _rng.seed(11)
        client._send_gof_pass('AUT', AUS, 7)

    assert client.state.g_order_commit_count == 2
    assert events == [('submit', _one_step(11)), ('await', _one_step(11))]
