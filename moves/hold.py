"""Hold-weight population and safe-reach scoring.

Split from moves.py during the 2026-04 refactor.

Two early-pipeline helpers run by ``generate_orders`` before support and
convoy enumeration:

  * ``enumerate_hold_orders`` — populate ``g_HoldWeight`` from threat level.
  * ``compute_safe_reach``    — port of ``FUN_0043dfb0`` computing the
    per-unit safe-reach score (``g_SafeReachScore``).

Module-level deps: ``bisect``, ``numpy``, ``..state.InnerGameState``.
"""

import bisect

import numpy as np

from ..state import InnerGameState

def enumerate_hold_orders(state: InnerGameState, power_idx: int):
    """
    Generate all basic hold orders for alive units.
    Populates candidate matrix paths natively.
    """
    for prov in range(256):
        if state.has_own_unit(power_idx, prov):
            if state.g_ThreatLevel[power_idx, prov] > 0:
                state.g_HoldWeight[prov] = max(state.g_HoldWeight[prov], 0.4)
            else:
                state.g_HoldWeight[prov] = 1.0


def compute_safe_reach(state: InnerGameState):
    """
    Port of FUN_0043dfb0 = ComputeSafeReach.

    Builds a [province][power] contestedness matrix, then for each unit checks
    whether its province and all adjacent provinces are uncontested from its
    power's perspective.  If so, writes the max sorted-set rank across those
    provinces to g_SafeReachScore[unit.province]; otherwise leaves the sentinel
    0xffffffff in place.

    Phase 1 — initialise g_SafeReachScore and contested matrix.
    Phase 2 — for each unit, mark unit.province + adjacencies contested for all
               other powers  (AdjacencyList call #1).
    Phase 3 — province token pass: AMY units re-mark their own province for
               other powers (redundant but faithful to binary); FLT units mark
               their province contested for ALL powers including their own
               (fleets block army safe-reach universally).
    Phase 4 — second unit pass: compute max sorted-set rank across unit.province
               and adjacencies; store to g_SafeReachScore only when all squares
               are uncontested  (AdjacencyList call #2).
    """
    num_provinces = 256
    num_powers = 7

    # Phase 1 — initialise
    state.g_SafeReachScore = np.full(num_provinces, 0xFFFFFFFF, dtype=np.uint32)
    contested = np.zeros((num_provinces, num_powers), dtype=np.int32)

    # Phase 2 — mark unit province + adjacencies contested for all other powers
    for prov_id, unit_data in state.unit_info.items():
        unit_power = unit_data['power']
        for power in range(num_powers):
            if power != unit_power:
                contested[prov_id, power] = 1
        for adj_prov in state.get_unit_adjacencies(prov_id):
            for power in range(num_powers):
                if power != unit_power:
                    contested[adj_prov, power] = 1

    # Phase 3 — province token pass
    # AMY: re-mark province for other powers (same as Phase 2, harmless).
    # FLT: power_idx = 0x14 (no valid power) → all 7 powers get contested=1,
    #      including the fleet owner — fleets block safe-reach for everyone.
    for prov_id, unit_data in state.unit_info.items():
        if unit_data['type'] == 'A':
            unit_power = unit_data['power']
            for power in range(num_powers):
                if power != unit_power:
                    contested[prov_id, power] = 1
        else:
            # FLT (or unknown): power_idx = 0x14 → for power != 0x14 covers 0-6
            for power in range(num_powers):
                contested[prov_id, power] = 1

    # Phase 4 — compute safe-reach scores using per-power sorted province sets.
    # OrderedSet_FindOrInsert returns the 0-based rank of the province in the
    # sorted set (ascending by province_id, matching SortedList_Insert key order).
    power_sets: list[list[int]] = [[] for _ in range(num_powers)]

    def _find_or_insert(sorted_set: list, province: int) -> int:
        idx = bisect.bisect_left(sorted_set, province)
        if idx >= len(sorted_set) or sorted_set[idx] != province:
            sorted_set.insert(idx, province)
        return idx

    for prov_id, unit_data in state.unit_info.items():
        unit_power = unit_data['power']
        adj = state.get_unit_adjacencies(prov_id)

        score = _find_or_insert(power_sets[unit_power], prov_id)
        is_safe = (contested[prov_id, unit_power] != 1)

        for adj_prov in adj:
            adj_rank = _find_or_insert(power_sets[unit_power], adj_prov)
            if adj_rank > score:
                score = adj_rank
            if contested[adj_prov, unit_power] == 1:
                is_safe = False

        if is_safe:
            state.g_SafeReachScore[prov_id] = score


