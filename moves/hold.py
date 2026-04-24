"""Hold-weight population, reach-matrix construction, and safe-reach scoring.

Split from moves.py during the 2026-04 refactor.

Early-pipeline helpers run by ``generate_orders`` before support and convoy
enumeration:

  * ``enumerate_hold_orders`` — full port of ``EnumerateHoldOrders``
    (``FUN_00455fd0``).  Populates ``g_HoldWeight``, builds per-power
    ordered province sets, and fills ``g_UnitProvinceReach`` /
    ``g_MaxNonAllyReach`` (consumed by ``EvaluateAllianceScore``).
  * ``compute_safe_reach``    — port of ``FUN_0043dfb0`` computing the
    per-unit safe-reach score (``g_SafeReachScore``).

Module-level deps: ``bisect``, ``numpy``, ``..state.InnerGameState``.
"""

import bisect

import numpy as np

from ..state import InnerGameState

# ---------------------------------------------------------------------------
#  Helpers
# ---------------------------------------------------------------------------

NUM_POWERS = 7
NUM_PROVINCES = 256


def _find_or_insert(sorted_set: list, key: int) -> int:
    """Equivalent of C's OrderedSet_FindOrInsert.

    Inserts *key* into *sorted_set* (maintained in ascending order) if not
    already present and returns its 0-based position (the "rank").
    """
    idx = bisect.bisect_left(sorted_set, key)
    if idx >= len(sorted_set) or sorted_set[idx] != key:
        sorted_set.insert(idx, key)
    return idx


def _get_ally_trust_for_adj(state: InnerGameState,
                            unit_power: int,
                            adj_prov: int) -> int:
    """Check if *adj_prov* is controlled by a trusted ally of *unit_power*.

    Mirrors the three-layer ally-designation lookup at
    ``EnumerateHoldOrders.c:133-144``.  Returns the trust value (> 0 means
    trusted ally, 0 means non-ally).

    The C code checks three designation arrays (A, B, C) for the adjacent
    province.  Each array maps province → designated ally power.  If the
    designated power has non-zero trust with *unit_power*, we use that trust
    value.  Later designations overwrite earlier ones (C > B > A).
    """
    trust = 0
    # Slot A  — g_AllyDesignation_A[adj_prov]
    desig_a = int(state.g_AllyDesignation_A[adj_prov])
    if 0 <= desig_a < NUM_POWERS:
        t = int(state.g_AllyTrustScore[unit_power * NUM_POWERS + desig_a]
                if state.g_AllyTrustScore.ndim == 1
                else state.g_AllyTrustScore[unit_power, desig_a])
        trust = t

    # Slot B  — g_AllyDesignation_B[adj_prov]
    desig_b = int(state.g_AllyDesignation_B[adj_prov])
    if 0 <= desig_b < NUM_POWERS:
        t = int(state.g_AllyTrustScore[unit_power * NUM_POWERS + desig_b]
                if state.g_AllyTrustScore.ndim == 1
                else state.g_AllyTrustScore[unit_power, desig_b])
        trust = t

    # Slot C  — g_AllyDesignation_C[adj_prov]
    desig_c = int(state.g_AllyDesignation_C[adj_prov])
    if 0 <= desig_c < NUM_POWERS:
        t = int(state.g_AllyTrustScore[unit_power * NUM_POWERS + desig_c]
                if state.g_AllyTrustScore.ndim == 1
                else state.g_AllyTrustScore[unit_power, desig_c])
        trust = t

    return trust


# ---------------------------------------------------------------------------
#  EnumerateHoldOrders — full port
# ---------------------------------------------------------------------------

def enumerate_hold_orders(state: InnerGameState, power_idx: int):
    """Full port of EnumerateHoldOrders (FUN_00455fd0).

    Called once per power by ``generate_orders``.  On the **first call**
    (``power_idx == 0``) the function zeroes and rebuilds the global
    reach matrices for ALL powers (Phase 1-2 in the C code operate across
    all powers before Phase 6 iterates per-power).  Subsequent calls with
    ``power_idx > 0`` only run the per-power hold-weight pass unless the
    matrices are stale.

    **Phase 1** — Zero ``g_UnitProvinceReach`` and ``g_MaxNonAllyReach``.

    **Phase 2** — Walk every unit.  For each unit insert its province into
    every power's ordered province set and record the rank as
    ``g_UnitProvinceReach[power, province]``.  Then filter adjacencies by
    unit type, initialise ``g_MaxNonAllyReach[unit.power, province]``, and
    walk adjacent provinces.  For each adjacent province that is NOT
    controlled by a trusted ally (checked via the three ``g_AllyDesignation``
    slots), insert it into the unit's power's ordered set; if the resulting
    rank exceeds the current ``g_MaxNonAllyReach``, update it.

    **Phase 5** — Hold-weight population (the only part the prior stub had).

    **Phase 6** — Per-power hold-order sequence generation.  This calls
    ``BuildOrder_RTO``, ``FUN_00463690``, and ``FUN_00466c40`` which are
    opaque Ghidra stubs.  The Python trial loop already seeds HLD orders
    via ``trial.py:784-786`` and generates movement orders through its own
    pipeline, so this phase is **not yet ported**.  If you have access to
    cleaner Ghidra decompile output for FUN_00463690 / FUN_00466c40 please
    provide it so the hold-order sequence generation can be completed.
    """

    # ── Phase 1 + 2: Reach matrices (run once, on first power) ────────────
    # The C code loops all powers in Phase 1 and all units in Phase 2
    # before entering the per-power Phase 6 loop.  We gate on power_idx == 0
    # to avoid redundant rebuilds — generate_orders calls us in a
    # ``for p in range(NUM_POWERS): enumerate_hold_orders(state, p)`` loop.
    if power_idx == 0:
        _build_reach_matrices(state)

    # ── Phase 5: Hold-weight population ───────────────────────────────────
    for prov in range(NUM_PROVINCES):
        if state.has_own_unit(power_idx, prov):
            if state.g_ThreatLevel[power_idx, prov] > 0:
                state.g_HoldWeight[prov] = max(state.g_HoldWeight[prov], 0.4)
            else:
                state.g_HoldWeight[prov] = 1.0

    # ── Phase 6: Hold-order sequence generation ───────────────────────────
    # NOT YET PORTED — requires Ghidra decompile for FUN_00463690 and
    # FUN_00466c40.  The Python MC trial loop (trial.py) already seeds HLD
    # orders and generates candidates through its own pipeline.


def _build_reach_matrices(state: InnerGameState):
    """Phases 1-2 of EnumerateHoldOrders: build reach matrices.

    Populates:
      * ``state.g_UnitProvinceReach[power, province]`` — rank of *province*
        in *power*'s ordered province set.
      * ``state.g_MaxNonAllyReach[power, province]``   — max rank among
        non-ally adjacent provinces for the unit's own power.
    """

    # ── Phase 1: Zero arrays ──────────────────────────────────────────────
    state.g_UnitProvinceReach[:] = 0
    state.g_MaxNonAllyReach[:] = 0

    # Per-power ordered province sets.  C uses STL ordered-set (RB-tree);
    # we use sorted lists with bisect (same semantics, O(n) insert).
    power_sets: list[list[int]] = [[] for _ in range(NUM_POWERS)]

    # ── Phase 2: Walk units ───────────────────────────────────────────────
    unit_snapshot = list(state.unit_info.items())
    for prov_id, unit_data in unit_snapshot:
        unit_power = unit_data['power']
        unit_type = unit_data.get('type', 'A')   # 'A' or 'F'

        # 2a. Insert province into each power's ordered set and record rank.
        # C (lines 68-87): for each power, OrderedSet_FindOrInsert →
        #   g_UnitProvinceReach[province + power*256] = rank
        for p in range(NUM_POWERS):
            rank = _find_or_insert(power_sets[p], prov_id)
            state.g_UnitProvinceReach[p, prov_id] = rank

        # 2b. Get type-filtered adjacencies.
        # C (line 99): AdjacencyList_FilterByUnitType(gamestate, unit_type)
        raw_adjs = state.get_unit_adjacencies(prov_id)
        if unit_type in ('F', 'FLT'):
            adj_list = [a for a in raw_adjs
                        if a not in getattr(state, 'land_provinces', set())]
        elif unit_type in ('A', 'AMY'):
            adj_list = [a for a in raw_adjs
                        if a not in getattr(state, 'water_provinces', set())]
        else:
            adj_list = list(raw_adjs)

        # 2c. Initialise MaxNonAllyReach for this unit's province to its own
        #     UnitProvinceReach rank.
        # C (lines 108-110): g_MaxNonAllyReach[power*256+prov] =
        #                     g_UnitProvinceReach[power*256+prov]
        state.g_MaxNonAllyReach[unit_power, prov_id] = \
            state.g_UnitProvinceReach[unit_power, prov_id]

        # 2d. Walk adjacencies — ally-trust gate.
        # C (lines 111-166): for each adj province, check 3 designation
        # arrays.  If the adjacent province is NOT controlled by a trusted
        # ally (trust == 0), insert it into the unit-power's ordered set and
        # update MaxNonAllyReach if the new rank exceeds the current value.
        for adj_prov in adj_list:
            trust = _get_ally_trust_for_adj(state, unit_power, adj_prov)
            if trust == 0:
                adj_rank = _find_or_insert(power_sets[unit_power], adj_prov)
                cur_max = state.g_MaxNonAllyReach[unit_power, prov_id]
                if adj_rank > cur_max:
                    state.g_MaxNonAllyReach[unit_power, prov_id] = adj_rank


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
    # Snapshot unit_info to guard against mid-iteration mutation (audit M2).
    _unit_snapshot = list(state.unit_info.items())
    for prov_id, unit_data in _unit_snapshot:
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
    for prov_id, unit_data in _unit_snapshot:
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

    for prov_id, unit_data in _unit_snapshot:
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


