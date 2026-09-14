"""MapAndUnits movement adjudicator (Albert.exe ``FUN_0040b4b0`` family).

UpdateAllyOrderScore stages a complete order set into the unit table at
inner+0x2450 and calls ``FUN_0040b560``, which dispatches SPR/FAL to the
DAIDE framework's movement adjudicator below.  Albert then weights every unit
by the result bytes this code writes: +0x6b moved, +0x6a dislodged (with the
dislodging unit at +0x60) and +0x69 bounced.

The port keeps the binary's containers and their iteration order:

  +0x24e8  moves        multimap destination -> moving unit (insertion order)
  +0x24f4  supports     set of supporting units
  +0x2500  convoys      set of convoying fleets
  +0x250c  convoyed     set of convoyed armies
  +0x2518  subversion   map army -> [subverted army, subverter count, flag]
  +0x2524  circles      set, circles of movement
  +0x2530  h2h_equal    set, balanced head-to-head battles
  +0x253c  h2h_strong   set, head-to-head battles with a stronger side
  +0x2548  standoffs    set of standoff provinces

Units are keyed by province id, as ``ParseNOWUnit`` keys them.  UpdateAllyOrderScore
disables the illegal-order pass (``FUN_0045ff80(inner, 0, 0)`` clears
inner+0x24b3), so ``FUN_00407d00`` is not ported.
"""

from __future__ import annotations

HLD = 1
MTO = 2
SUP_HLD = 3
SUP_MTO = 4
CVY = 5
CTO = 6
FAILED = 9  # working order written to every failed move


class Unit:
    """One inner+0x2450 unit record with its adjudication fields."""

    __slots__ = (
        'prov', 'power', 'order', 'dest', 'other', 'other_dest', 'route',
        'work', 'supports', 'dislodge_supports', 'counts_for_dislodge',
        'chain', 'circle', 'dislodged_by',
        'cto_void', 'cvy_void', 'disrupted', 'sup_void', 'cut',
        'bounced', 'dislodged', 'moved',
    )

    def __init__(self, prov: int, power: int, order: int = HLD, dest: int = -1,
                 other: int = -1, other_dest: int = -1, route=()):
        self.prov = prov                  # +0x10
        self.power = power                # +0x18
        self.order = order                # +0x20
        self.dest = dest                  # +0x24
        self.other = other                # +0x2c supported / convoyed unit
        self.other_dest = other_dest      # +0x30
        self.route = tuple(route)         # +0x34 convoy route (fleet provinces)
        self.work = order                 # +0x40
        self.supports: set = set()        # +0x44 set, size at +0x4c
        self.dislodge_supports = 0        # +0x50
        self.counts_for_dislodge = False  # +0x54
        self.chain = -1                   # +0x58
        self.circle = 0                   # +0x5c
        self.dislodged_by = -1            # +0x60
        self.cto_void = 0                 # +0x64
        self.cvy_void = 0                 # +0x65
        self.disrupted = 0                # +0x66
        self.sup_void = 0                 # +0x67
        self.cut = 0                      # +0x68
        self.bounced = 0                  # +0x69
        self.dislodged = 0                # +0x6a
        self.moved = 0                    # +0x6b


class MovementAdjudicator:
    """Resolve one staged movement order set exactly as FUN_0040b4b0 does."""

    def __init__(self, units: dict[int, Unit]):
        self.units = units
        self.moves: dict[int, list[int]] = {}
        self.supports: set[int] = set()
        self.convoys: set[int] = set()
        self.convoyed: set[int] = set()
        self.subversion: dict[int, list[int]] = {}
        self.circles: set[int] = set()
        self.h2h_equal: set[int] = set()
        self.h2h_strong: set[int] = set()
        self.standoffs: set[int] = set()

    # ── FUN_0040b4b0 ────────────────────────────────────────────────────────
    def run(self) -> dict[int, Unit]:
        self._initialise()
        self._cancel_inconsistent_convoys()
        self._cancel_inconsistent_supports()
        self._direct_attacks_cut_support()
        self._build_support_chains()
        self._build_convoy_subversion()

        futile_checked = False
        indomitable_checked = False
        while True:
            while self._resolve_unsubverted_convoys():
                pass
            if not futile_checked:
                futile_checked = True
                if self._check_futile_convoys():
                    continue
            if indomitable_checked:
                break
            indomitable_checked = True
            if not self._check_indomitable_convoys():
                break

        self._resolve_circles_of_subversion()
        self._classify_moves()
        self._resolve_circles_of_movement()
        self._resolve_strong_head_to_heads()
        self._resolve_equal_head_to_heads()
        while self.moves:
            self._resolve_attacks_on(min(self.moves))
        return self.units

    # ── FUN_004058d0 ────────────────────────────────────────────────────────
    def _initialise(self) -> None:
        for prov in sorted(self.units):
            unit = self.units[prov]
            unit.work = unit.order
            unit.supports = set()
            unit.dislodge_supports = 0
            unit.counts_for_dislodge = False
            unit.cto_void = unit.cvy_void = unit.disrupted = unit.sup_void = 0
            unit.cut = unit.bounced = unit.dislodged = unit.moved = 0
            unit.chain = -1
            if unit.order == MTO:
                self.moves.setdefault(unit.dest, []).append(prov)
            elif unit.order in (SUP_HLD, SUP_MTO):
                self.supports.add(prov)
            elif unit.order == CVY:
                self.convoys.add(prov)
            elif unit.order == CTO:
                self.convoyed.add(prov)

    # ── FUN_004080f0 ────────────────────────────────────────────────────────
    def _cancel_inconsistent_convoys(self) -> None:
        units = self.units
        for prov in sorted(self.convoyed):
            army = units[prov]
            consistent = True
            for fleet_prov in army.route:
                fleet = units.get(fleet_prov)
                if (fleet is None or fleet.work != CVY or fleet.other != army.prov
                        or fleet.other_dest != army.dest):
                    consistent = False
            if not consistent:
                army.work = FAILED
                army.cto_void = 1
                self.convoyed.discard(prov)
        for prov in sorted(self.convoys):
            fleet = units[prov]
            army = units.get(fleet.other)
            if (army is None or army.order != CTO or army.prov != fleet.other
                    or army.dest != fleet.other_dest or army.work != CTO):
                fleet.cvy_void = 1
                fleet.work = HLD
                self.convoys.discard(prov)

    # ── FUN_004083d0 ────────────────────────────────────────────────────────
    def _cancel_inconsistent_supports(self) -> None:
        units = self.units
        for prov in sorted(self.supports):
            support = units[prov]
            target = units.get(support.other)
            keep = False
            if target is None:
                support.sup_void = 1
            elif support.work != SUP_HLD:
                if target.order in (MTO, CTO) and target.dest == support.other_dest:
                    keep = target.work in (MTO, CTO)
                else:
                    support.sup_void = 1
            elif target.work in (MTO, CTO, FAILED):
                support.sup_void = 1
            else:
                keep = True
            if not keep:
                support.work = HLD
                self.supports.discard(prov)

    # ── FUN_00408540 ────────────────────────────────────────────────────────
    def _direct_attacks_cut_support(self) -> None:
        units = self.units
        for dest in sorted(self.moves):
            for mover_prov in list(self.moves.get(dest, ())):
                mover = units[mover_prov]
                target = units.get(mover.dest)
                if (target is not None and target.power != mover.power
                        and (target.work == SUP_HLD
                             or (target.work == SUP_MTO
                                 and target.other_dest != mover.prov))):
                    target.cut = 1
                    target.work = HLD
                    self.supports.discard(target.prov)

    # ── FUN_00408660 ────────────────────────────────────────────────────────
    def _build_support_chains(self) -> None:
        units = self.units
        for prov in sorted(self.supports):
            support = units[prov]
            supported = units[support.other]
            supported.supports.add(prov)
            if support.work == SUP_MTO:
                target = units.get(support.other_dest)
                if target is not None and (target.power == support.power
                                           or target.power == supported.power):
                    continue
                support.counts_for_dislodge = True
                supported.dislodge_supports += 1

    # ── FUN_00408790 ────────────────────────────────────────────────────────
    def _build_convoy_subversion(self) -> None:
        units = self.units
        for prov in sorted(self.convoyed):
            subverts = -1
            army = units[prov]
            target = units.get(army.dest)
            if target is not None and target.power != army.power:
                if target.work == SUP_HLD:
                    supported = units.get(target.other)
                    if supported is not None and supported.work == CVY:
                        subverts = supported.other
                elif target.work == SUP_MTO:
                    attacked = units.get(target.other_dest)
                    if attacked is not None and attacked.work == CVY:
                        subverts = attacked.other
            self.subversion[prov] = [subverts, 0, 0]
        for prov in sorted(self.subversion):
            subverts = self.subversion[prov][0]
            if subverts != -1 and subverts in self.subversion:
                entry = self.subversion[subverts]
                entry[2] = 1
                entry[1] += 1

    # ── strength queries: FUN_00409640 / FUN_00409790 / FUN_004090d0 ──────
    def _strongest(self, prov: int):
        best = -1
        best_unit = -1
        best_dislodge = -1
        second = -1
        for mover_prov in self.moves.get(prov, ()):
            mover = self.units[mover_prov]
            strength = len(mover.supports)
            if best < strength:
                best_dislodge = mover.dislodge_supports
                best_unit = mover_prov
                second = best
                best = strength
            elif second < strength:
                second = strength
        return best, best_unit, best_dislodge, second

    def _attack_winner(self, prov: int, include_defender: bool) -> int:
        _best, best_unit, best_dislodge, second = self._strongest(prov)
        if include_defender:
            defender = self.units.get(prov)
            hold = len(defender.supports) if defender is not None else 0
            if second < hold:
                second = hold
        if second < best_dislodge and 0 < best_dislodge:
            return best_unit
        return -1

    def _empty_province_winner(self, prov: int) -> int:
        best, best_unit, _dislodge, second = self._strongest(prov)
        return best_unit if second < best else -1

    def _circle_status(self, dest: int, attacker: int) -> int:
        best, best_unit, best_dislodge, second = self._strongest(dest)
        if best == second:
            return 2
        if best_unit != attacker:
            return 4 if (best_dislodge >= 1 and best_dislodge > second) else 3
        if 0 < best_dislodge and second < best_dislodge:
            return 0
        return 1

    # ── result writers ─────────────────────────────────────────────────────
    def _fail(self, unit: Unit) -> None:
        unit.work = FAILED
        unit.supports = set()
        unit.dislodge_supports = 0
        unit.bounced = 1

    def _move_succeeds(self, winner: int) -> None:            # FUN_00409250
        unit = self.units[winner]
        unit.moved = 1
        for mover_prov in self.moves.pop(unit.dest, ()):
            if mover_prov != winner:
                self._fail(self.units[mover_prov])

    def _standoff(self, prov: int) -> None:                   # FUN_004093f0
        for mover_prov in self.moves.pop(prov, ()):
            self._fail(self.units[mover_prov])
        self.standoffs.add(prov)

    def _move_fails(self, unit: Unit) -> None:                # FUN_00404bc0
        self._fail(unit)
        movers = self.moves.get(unit.dest)
        if movers is not None:
            movers[:] = [prov for prov in movers if prov != unit.prov]
            if not movers:
                del self.moves[unit.dest]

    def _cut_support_at(self, prov: int) -> None:             # FUN_004095a0
        unit = self.units.get(prov)
        if unit is None or unit.work not in (SUP_HLD, SUP_MTO):
            return
        supported = self.units.get(unit.other)
        if supported is None:
            return
        supported.supports.discard(prov)
        if unit.counts_for_dislodge:
            supported.dislodge_supports -= 1
        unit.work = HLD
        unit.cut = 1

    def _dislodge(self, prov: int, attacker: int) -> None:
        unit = self.units[prov]
        unit.dislodged = 1
        unit.dislodged_by = attacker

    def _break_convoy(self, army: Unit) -> None:
        for fleet_prov in army.route:
            fleet = self.units.get(fleet_prov)
            if fleet is not None:
                fleet.work = HLD
        army.work = FAILED
        army.disrupted = 1
        army.supports = set()
        army.dislodge_supports = 0

    def _next_subversion_key(self, key: int):
        later = [k for k in self.subversion if k > key]
        return min(later) if later else None

    # ── FUN_0040ace0 ────────────────────────────────────────────────────────
    def _resolve_unsubverted_convoys(self) -> bool:
        changed = False
        for army_prov in sorted(self.subversion):
            entry = self.subversion.get(army_prov)
            if entry is None or entry[2] != 0:
                continue
            army = self.units[army_prov]
            dislodged_any = False
            for fleet_prov in army.route:
                winner = self._attack_winner(fleet_prov, True)
                if winner == -1:
                    self._standoff(fleet_prov)
                else:
                    self._cut_support_at(fleet_prov)
                    self._move_succeeds(winner)
                    self._dislodge(fleet_prov, winner)
                    dislodged_any = True
            if dislodged_any:
                self._break_convoy(army)
            else:
                self._cut_support_at(army.dest)
                self.moves.setdefault(army.dest, []).append(army_prov)
            if entry[0] != -1:
                subverted = self.subversion.setdefault(entry[0], [0, 0, 0])
                subverted[1] -= 1
                if subverted[1] == 0:
                    subverted[2] = 0
            del self.subversion[army_prov]
            changed = True
        return changed

    def _supported_reference(self, army: Unit):
        target = self.units.get(army.dest)
        if target is None:
            return None, None, None
        if target.work == SUP_HLD:
            return target, target.other, target.other
        if target.work == SUP_MTO:
            return target, target.other_dest, target.other
        return target, None, None

    # ── FUN_0040afa0 ────────────────────────────────────────────────────────
    def _check_futile_convoys(self) -> bool:
        changed = False
        key = min(self.subversion) if self.subversion else None
        while key is not None:
            entry = self.subversion.get(key)
            if entry is not None and entry[0] != -1:
                army = self.units[key]
                target = self.units.get(army.dest)
                if target is not None and target.work == SUP_HLD:
                    reference = target.other
                elif target is not None:
                    reference = target.other_dest
                else:
                    reference = -1
                subverted_prov = entry[0]
                subverted = self.units[subverted_prov]
                dislodged_any = False
                for fleet_prov in subverted.route:
                    if fleet_prov == reference:
                        continue
                    winner = self._attack_winner(fleet_prov, True)
                    if winner == -1:
                        self._standoff(fleet_prov)
                    else:
                        self._cut_support_at(fleet_prov)
                        self._move_succeeds(winner)
                        self._dislodge(fleet_prov, winner)
                        dislodged_any = True
                if dislodged_any:
                    self._break_convoy(subverted)
                    subverted_entry = self.subversion.get(subverted_prov)
                    if subverted_entry is not None:
                        onward = self.subversion.get(subverted_entry[0])
                        if onward is not None:
                            onward[1] = 0
                            onward[2] = 0
                    entry[0] = -1
                    self.subversion.pop(subverted_prov, None)
                    changed = True
            key = self._next_subversion_key(key)
        return changed

    # ── FUN_0040a030 ────────────────────────────────────────────────────────
    def _check_indomitable_convoys(self) -> bool:
        changed = False
        key = min(self.subversion) if self.subversion else None
        while key is not None:
            entry = self.subversion.get(key)
            if entry is not None and entry[0] != -1:
                army = self.units[key]
                target, contested, supported_prov = self._supported_reference(army)
                if target is not None and contested is not None:
                    supported = self.units.get(supported_prov)
                    if supported is not None and contested != -1:
                        subverted_prov = entry[0]
                        subverted = self.units[subverted_prov]
                        subverted_entry = self.subversion.get(subverted_prov)
                        if subverted_entry is not None:
                            with_support = self._attack_winner(contested, True)
                            supported.supports.discard(target.prov)
                            if target.counts_for_dislodge:
                                supported.dislodge_supports -= 1
                            without_support = self._attack_winner(contested, True)
                            supported.supports.add(target.prov)
                            if target.counts_for_dislodge:
                                supported.dislodge_supports += 1
                            if with_support == -1:
                                if without_support == -1:
                                    subverted_entry[1] = 0
                                    subverted_entry[2] = 0
                                    entry[0] = -1
                                    changed = True
                                else:
                                    subverted_entry[2] = 4
                            elif without_support != -1:
                                self._break_convoy(subverted)
                                subverted_entry[1] = 0
                                subverted_entry[2] = 0
                                entry[0] = -1
                                changed = True
            key = self._next_subversion_key(key)
        return changed

    # ── FUN_004089d0 ────────────────────────────────────────────────────────
    def _resolve_circles_of_subversion(self) -> None:
        while self.subversion:
            start = min(self.subversion)
            paradox = False
            current = start
            seen = set()
            while True:
                entry = self.subversion.get(current)
                if entry is None or current in seen:
                    break
                seen.add(current)
                if entry[2] == 4:
                    paradox = True
                current = entry[0]
                if current == start:
                    break
            if paradox:
                current = start
                seen = set()
                while current in self.subversion and current not in seen:
                    seen.add(current)
                    for fleet_prov in self.units[current].route:
                        for mover_prov in self.moves.pop(fleet_prov, ()):
                            self._fail(self.units[mover_prov])
                    current = self.subversion[current][0]
                    if current == start:
                        break
            current = min(self.subversion)
            while current in self.subversion:
                self._break_convoy(self.units[current])
                onward = self.subversion[current][0]
                del self.subversion[current]
                current = onward

    # ── FUN_00408ed0 ────────────────────────────────────────────────────────
    def _classify_moves(self) -> None:
        units = self.units
        counter = 0
        for dest in sorted(self.moves):
            for mover_prov in list(self.moves[dest]):
                unit = units[mover_prov]
                last_convoy = -1
                index = counter
                broke = False
                while unit.chain == -1:
                    if unit.work not in (MTO, CTO):
                        broke = True
                        break
                    unit.chain = index
                    if unit.work == CTO:
                        last_convoy = index
                    index += 1
                    following = units.get(unit.dest)
                    if following is None:
                        broke = True
                        break
                    unit = following
                if broke:
                    counter = index
                    continue
                entry_index = unit.chain
                if entry_index < counter:
                    counter = index
                    continue
                counter = index
                if index - entry_index < 3 and last_convoy < entry_index:
                    other = units[unit.dest]
                    if len(other.supports) < unit.dislodge_supports:
                        self.h2h_strong.add(unit.prov)
                    elif len(unit.supports) < other.dislodge_supports:
                        self.h2h_strong.add(other.prov)
                    else:
                        self.h2h_equal.add(unit.prov)
                else:
                    self.circles.add(unit.prov)

    # ── FUN_0040a380 ────────────────────────────────────────────────────────
    def _resolve_circles_of_movement(self) -> None:
        units = self.units
        for start in sorted(self.circles):
            ring: list[int] = []
            problem_index = -1
            unit = units[start]
            while True:
                ring.append(unit.prov)
                unit.circle = self._circle_status(unit.dest, unit.prov)
                if unit.circle not in (0, 1):
                    problem_index = len(ring) - 1
                unit = units[unit.dest]
                if unit.prov == start:
                    break
            if problem_index == -1:
                # List order, which is reverse traversal order.
                for prov in reversed(ring):
                    self._move_succeeds(prov)
                continue
            # The binary pushes each unit at the list front, so "next" is the
            # previously visited unit: the one moving into this province.
            def step(index: int) -> int:
                return index - 1 if index > 0 else len(ring) - 1

            problem = units[ring[problem_index]]
            if problem.circle == 2:
                self._standoff(problem.dest)
            elif problem.circle == 4:
                self._move_fails(problem)
            else:
                index = step(problem_index)
                neighbour = units[ring[index]]
                if neighbour.circle == 4:
                    self._move_fails(neighbour)
                elif neighbour.circle == 0:
                    while True:
                        index = step(index)
                        neighbour = units[ring[index]]
                        if neighbour.circle in (4, 3):
                            self._move_fails(neighbour)
                        elif neighbour.circle == 2:
                            self._standoff(neighbour.dest)
                        if neighbour.circle not in (1, 0):
                            break
                else:
                    self._standoff(neighbour.dest)

    # ── FUN_0040a720 ────────────────────────────────────────────────────────
    def _resolve_strong_head_to_heads(self) -> None:
        units = self.units
        for prov in sorted(self.h2h_strong):
            strong = units[prov]
            weak = units[strong.dest]
            winner_at_weak = self._attack_winner(weak.prov, False)
            if winner_at_weak == strong.prov:
                self._move_fails(weak)
                self._move_succeeds(strong.prov)
                self._dislodge(weak.prov, strong.prov)
                continue
            winner_at_strong = self._attack_winner(strong.prov, False)
            self._move_fails(weak)
            if winner_at_weak == -1:
                self._standoff(weak.prov)
            else:
                self._move_succeeds(winner_at_weak)
                self._dislodge(weak.prov, winner_at_weak)
            if winner_at_strong == -1 or winner_at_strong == weak.prov:
                self._standoff(strong.prov)
            else:
                self._move_succeeds(winner_at_strong)
                self._dislodge(strong.prov, winner_at_strong)

    # ── FUN_0040a870 ────────────────────────────────────────────────────────
    def _resolve_equal_head_to_heads(self) -> None:
        units = self.units
        for prov in sorted(self.h2h_equal):
            first = units[prov]
            second = units[first.dest]
            winner_at_first = self._attack_winner(first.prov, False)
            winner_at_second = self._attack_winner(second.prov, False)
            if winner_at_first == second.prov or winner_at_first == -1:
                self._standoff(first.prov)
            else:
                self._move_succeeds(winner_at_first)
                self._dislodge(first.prov, winner_at_first)
            if winner_at_second == first.prov or winner_at_second == -1:
                self._standoff(second.prov)
            else:
                self._move_succeeds(winner_at_second)
                self._dislodge(second.prov, winner_at_second)

    # ── FUN_0040b350 / FUN_0040a990 ─────────────────────────────────────────
    def _resolve_attacks_on(self, prov: int) -> None:
        unit = self.units.get(prov)
        occupied = False
        if unit is not None:
            if unit.work in (MTO, CTO) and not unit.moved:
                self._resolve_attacks_on(unit.dest)
            occupied = not unit.moved
        if occupied:
            winner = self._attack_winner(prov, True)
            if winner == -1:
                self._standoff(prov)
                return
            self._cut_support_at(prov)
            self._move_succeeds(winner)
            self._dislodge(prov, winner)
            return
        winner = self._empty_province_winner(prov)
        if winner == -1:
            self._standoff(prov)
        else:
            self._move_succeeds(winner)


def adjudicate_movement(units: dict[int, Unit]) -> dict[int, Unit]:
    """Adjudicate a staged movement order set in place and return it."""
    return MovementAdjudicator(units).run()
