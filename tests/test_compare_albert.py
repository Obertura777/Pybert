"""Tests for the offline Albert comparison diagnostics."""

from types import SimpleNamespace

from compare_albert import (
    _adjustment_candidate_sets,
    _extend_candidate_seed_coverage,
    _is_replayable_daide_press,
    _retreat_candidate_sets,
)


def test_candidate_seed_sweep_unions_pools_until_reference_is_found():
    candidates = [["A ROM - APU", "A VEN H"]]
    calls = []

    def capture(_state, _phase, _power, *, seed, capture_candidates,
                run_submission):
        calls.append((seed, capture_candidates, run_submission))
        pools = {
            0: [["A ROM - TUS", "A VEN - TRI"]],
            1: [["A ROM - TUS", "A VEN H"]],
        }
        return [], pools[seed]

    covered, seeds = _extend_candidate_seed_coverage(
        candidates, ["A VEN H", "A ROM - TUS"], {}, "S1901M", "ITALY",
        primary_seed=42, seed_count=3, capture_fn=capture)

    assert covered is True
    assert seeds == [42, 0, 1]
    assert calls == [(0, True, False), (1, True, False)]
    assert ["A ROM - TUS", "A VEN H"] in candidates


def test_candidate_seed_sweep_does_not_run_when_primary_pool_covers():
    candidates = [["F STP/SC - BOT", "A MOS - STP"]]

    def capture(*_args, **_kwargs):
        raise AssertionError("covered primary pool must not run another seed")

    covered, seeds = _extend_candidate_seed_coverage(
        candidates, ["A MOS - STP", "F STP/SC - BOT"], {}, "S1901M",
        "RUSSIA", primary_seed=42, seed_count=10, capture_fn=capture)

    assert covered is True
    assert seeds == [42]


def test_press_input_audit_does_not_parse_human_yes_as_daide():
    assert not _is_replayable_daide_press('Yes, I can support you to Belgium.')
    assert not _is_replayable_daide_press('Not sure yet.')
    assert _is_replayable_daide_press('YES ( PRP ( PCE ( ENG FRA ) ) )')
    assert _is_replayable_daide_press(
        'FRM ( ENG ) ( FRA ) ( PRP ( DMZ ( ENG FRA ) ( ENG ) ) )'
    )
    assert _is_replayable_daide_press('DRW')


def test_adjustment_coverage_preserves_army_and_fleet_at_coastal_build_site():
    state = SimpleNamespace(
        g_build_delta={0: {'flag': 1, 'delta': 1}},
        g_adjustment_build_candidates=[
            {'province': 4, 'unit_type': 'AMY', 'coast': ''},
            {'province': 4, 'unit_type': 'FLT', 'coast': ''},
        ],
        _id_to_prov={4: 'TRI'},
        unit_info={},
    )

    assert _adjustment_candidate_sets(state, 'AUSTRIA') == [
        ['A TRI B'], ['F TRI B'],
    ]


def test_adjustment_coverage_rejects_two_builds_in_same_province():
    state = SimpleNamespace(
        g_build_delta={5: {'flag': 1, 'delta': 2}},
        g_adjustment_build_candidates=[
            {'province': 1, 'unit_type': 'AMY', 'coast': ''},
            {'province': 1, 'unit_type': 'FLT', 'coast': ''},
            {'province': 2, 'unit_type': 'AMY', 'coast': ''},
        ],
        _id_to_prov={1: 'SEV', 2: 'WAR'},
        unit_info={},
    )

    assert _adjustment_candidate_sets(state, 'RUSSIA') == [
        ['A SEV B', 'A WAR B'],
        ['F SEV B', 'A WAR B'],
    ]


def test_retreat_coverage_includes_rto_and_disband_choices():
    state_data = {
        'retreats': {'ENGLAND': {'F NTH': ['EDI', 'NWG']}},
    }

    assert _retreat_candidate_sets(state_data, 'ENGLAND') == [
        ['F NTH R EDI'], ['F NTH R NWG'], ['F NTH D'],
    ]


def test_retreat_coverage_omits_forced_disbands_like_reference_files():
    state_data = {
        'retreats': {
            'RUSSIA': {
                'A BUD': ['GAL'],
                'F BLA': [],
            },
        },
    }

    assert _retreat_candidate_sets(state_data, 'RUSSIA') == [
        ['A BUD R GAL'],
        ['A BUD D'],
    ]


def test_retreat_coverage_rejects_shared_destination():
    state_data = {
        'retreats': {
            'ITALY': {'A ROM': ['APU'], 'F NAP': ['APU', 'ION']},
        },
    }

    sets = _retreat_candidate_sets(state_data, 'ITALY')
    assert ['A ROM R APU', 'F NAP R APU'] not in sets
    assert ['A ROM R APU', 'F NAP R ION'] in sets
