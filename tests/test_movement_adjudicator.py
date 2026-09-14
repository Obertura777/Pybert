"""MapAndUnits movement adjudicator port (Albert.exe FUN_0040b4b0 family)."""

from pathlib import Path
import random
import sys


_ROOT = Path(__file__).resolve().parents[1]
_PKG = _ROOT.name
if str(_ROOT.parent) not in sys.path:
    sys.path.insert(0, str(_ROOT.parent))

_adj = __import__(f"{_PKG}.monte_carlo.adjudicator", fromlist=["adjudicate_movement"])
Unit = _adj.Unit
adjudicate_movement = _adj.adjudicate_movement
HLD, MTO, SUP_HLD, SUP_MTO, CVY, CTO = (
    _adj.HLD, _adj.MTO, _adj.SUP_HLD, _adj.SUP_MTO, _adj.CVY, _adj.CTO)

POWERS = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]


def _flags(units, prov):
    unit = units[prov]
    return unit.moved, unit.bounced, unit.dislodged, unit.dislodged_by


def test_supported_move_beats_unsupported_rival_into_empty_province():
    units = adjudicate_movement({
        10: Unit(10, 2, MTO, dest=1),
        9: Unit(9, 3, MTO, dest=1),
        60: Unit(60, 2, SUP_MTO, other=10, other_dest=1),
    })
    assert _flags(units, 10) == (1, 0, 0, -1)
    assert _flags(units, 9) == (0, 1, 0, -1)


def test_attack_with_support_dislodges_and_records_attacker():
    units = adjudicate_movement({
        1: Unit(1, 0, HLD),
        2: Unit(2, 1, MTO, dest=1),
        3: Unit(3, 1, SUP_MTO, other=2, other_dest=1),
    })
    assert _flags(units, 2) == (1, 0, 0, -1)
    assert _flags(units, 1) == (0, 0, 1, 2)


def test_support_from_the_defenders_power_never_counts_for_dislodgement():
    units = adjudicate_movement({
        1: Unit(1, 0, HLD),
        2: Unit(2, 1, MTO, dest=1),
        3: Unit(3, 0, SUP_MTO, other=2, other_dest=1),
    })
    assert _flags(units, 2) == (0, 1, 0, -1)
    assert _flags(units, 1) == (0, 0, 0, -1)


def test_support_matches_on_province_not_coast():
    """FUN_004083d0 compares destination provinces; the coast word is separate."""
    units = adjudicate_movement({
        26: Unit(26, 2, MTO, dest=75),          # F MAO - SPA (any coast)
        38: Unit(38, 1, MTO, dest=75),          # F GAS - SPA
        60: Unit(60, 1, SUP_MTO, other=26, other_dest=75),
    })
    assert units[26].moved == 1
    assert units[38].bounced == 1


def test_convoyed_attack_cuts_support_directed_against_the_army():
    """FUN_0040ace0 calls FUN_004095a0 on the destination unconditionally."""
    units = adjudicate_movement({
        57: Unit(57, 2, CTO, dest=53, route=(23,)),   # A KIE - DEN via HEL
        23: Unit(23, 0, CVY, other=57, other_dest=53),
        53: Unit(53, 3, SUP_MTO, other=3, other_dest=57),
        3: Unit(3, 6, MTO, dest=57),                   # A RUH - KIE
    })
    assert units[53].cut == 1
    assert _flags(units, 3) == (0, 1, 0, -1)
    assert _flags(units, 57) == (0, 1, 0, -1)


def test_head_to_head_stronger_side_dislodges_the_other():
    units = adjudicate_movement({
        1: Unit(1, 0, MTO, dest=2),
        2: Unit(2, 1, MTO, dest=1),
        3: Unit(3, 0, SUP_MTO, other=1, other_dest=2),
    })
    assert _flags(units, 1) == (1, 0, 0, -1)
    assert _flags(units, 2) == (0, 1, 1, 1)


def test_unsupported_circle_of_movement_all_move():
    units = adjudicate_movement({
        1: Unit(1, 0, MTO, dest=2),
        2: Unit(2, 1, MTO, dest=3),
        3: Unit(3, 2, MTO, dest=1),
    })
    assert all(units[p].moved == 1 for p in (1, 2, 3))


def test_disrupted_convoy_stops_the_army():
    units = adjudicate_movement({
        10: Unit(10, 0, CTO, dest=30, route=(20,)),
        20: Unit(20, 0, CVY, other=10, other_dest=30),
        21: Unit(21, 1, MTO, dest=20),
        22: Unit(22, 1, SUP_MTO, other=21, other_dest=20),
    })
    assert units[20].dislodged == 1
    assert units[10].disrupted == 1 and units[10].moved == 0


def _random_case(seed):
    from diplomacy import Game

    rng = random.Random(seed)
    game = Game(map_name="standard", rules=["NO_PRESS"])
    game.set_current_phase("S1901M")
    game.clear_units()
    locations = {}
    for loc in game.map.locs:
        base = loc.split('/')[0].upper()
        if game.map.area_type(base) != 'SHUT':
            locations.setdefault(base, []).append(loc.upper())
    placed = {power: [] for power in POWERS}
    for base in rng.sample(sorted(locations), rng.randint(10, 28)):
        area = game.map.area_type(base)
        unit_type = 'F' if area == 'WATER' else 'A' if area == 'LAND' else rng.choice('AF')
        coasts = [loc for loc in locations[base] if '/' in loc]
        loc = rng.choice(coasts) if unit_type == 'F' and coasts else base
        placed[rng.choice(POWERS)].append(f"{unit_type} {loc}")
    for power, units in placed.items():
        game.set_units(power, units)
    possible = game.get_all_possible_orders()
    chosen = {}
    for power, locs in game.get_orderable_locations().items():
        orders = []
        for loc in locs:
            options = [o for o in possible.get(loc, [])
                       if ' C ' not in o and 'VIA' not in o and '/' not in ' '.join(o.split()[3:])]
            if options:
                orders.append(rng.choice(options))
        chosen[power] = orders
        game.set_orders(power, orders)
    return game, chosen


def test_matches_the_diplomacy_adjudicator_on_random_coastless_order_sets():
    def base(loc):
        return loc.split('/')[0].upper()

    for seed in range(60):
        game, chosen = _random_case(seed)
        ids = {name: i for i, name in enumerate(sorted({base(l) for l in game.map.locs}))}
        units = {}
        for power, unit_list in game.get_units().items():
            for text in unit_list:
                prov = ids[base(text.split()[1])]
                units[prov] = Unit(prov, POWERS.index(power), HLD)
        orders = {}
        for power, order_list in chosen.items():
            for order in order_list:
                parts = order.split()
                unit = units[ids[base(parts[1])]]
                orders[base(parts[1])] = order
                if parts[2] == '-':
                    unit.order, unit.dest = MTO, ids[base(parts[3])]
                elif parts[2] == 'S' and '-' in parts:
                    unit.order = SUP_MTO
                    unit.other, unit.other_dest = ids[base(parts[4])], ids[base(parts[6])]
                elif parts[2] == 'S':
                    unit.order, unit.other = SUP_HLD, ids[base(parts[4])]
        adjudicate_movement(units)
        game.process()
        results = game.result_history.last_value()
        for text, result in results.items():
            name = base(text.split()[1])
            unit = units[ids[name]]
            names = {str(r) for r in result}
            moved = int(orders.get(name, '').split()[2:3] == ['-'] and 'bounce' not in names)
            assert (unit.moved, unit.bounced, unit.dislodged) == (
                moved, int('bounce' in names), int('dislodged' in names)
            ), (seed, text, result)
