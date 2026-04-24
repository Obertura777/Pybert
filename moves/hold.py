"""Hold-weight population, reach-matrix construction, and safe-reach scoring.

Split from moves.py during the 2026-04 refactor.

Early-pipeline helpers run by ``generate_orders`` before support and convoy
enumeration:

  * ``enumerate_hold_orders`` — full port of ``EnumerateHoldOrders``
    (``FUN_00455fd0``).  Populates ``g_hold_weight``, builds per-power
    ordered province sets, and fills ``g_unit_province_reach`` /
    ``g_max_non_ally_reach`` (consumed by ``EvaluateAllianceScore``).
    Phase 6 builds per-power default-hold DAIDE token sequences
    (``g_hold_order_seqs``) for the fallback submission path.
  * ``compute_safe_reach``    — port of ``FUN_0043dfb0`` computing the
    per-unit safe-reach score (``g_safe_reach_score``).

Module-level deps: ``bisect``, ``logging``, ``numpy``, ``..state.InnerGameState``.
"""

import bisect
import logging

import numpy as np

from ..state import InnerGameState

logger = logging.getLogger(__name__)

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
    # Slot A  — g_ally_designation_a[adj_prov]
    desig_a = int(state.g_ally_designation_a[adj_prov])
    if 0 <= desig_a < NUM_POWERS:
        t = int(state.g_ally_trust_score[unit_power * NUM_POWERS + desig_a]
                if state.g_ally_trust_score.ndim == 1
                else state.g_ally_trust_score[unit_power, desig_a])
        trust = t

    # Slot B  — g_ally_designation_b[adj_prov]
    desig_b = int(state.g_ally_designation_b[adj_prov])
    if 0 <= desig_b < NUM_POWERS:
        t = int(state.g_ally_trust_score[unit_power * NUM_POWERS + desig_b]
                if state.g_ally_trust_score.ndim == 1
                else state.g_ally_trust_score[unit_power, desig_b])
        trust = t

    # Slot C  — g_ally_designation_c[adj_prov]
    desig_c = int(state.g_ally_designation_c[adj_prov])
    if 0 <= desig_c < NUM_POWERS:
        t = int(state.g_ally_trust_score[unit_power * NUM_POWERS + desig_c]
                if state.g_ally_trust_score.ndim == 1
                else state.g_ally_trust_score[unit_power, desig_c])
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

    **Phase 1** — Zero ``g_unit_province_reach`` and ``g_max_non_ally_reach``.

    **Phase 2** — Walk every unit.  For each unit insert its province into
    every power's ordered province set and record the rank as
    ``g_unit_province_reach[power, province]``.  Then filter adjacencies by
    unit type, initialise ``g_max_non_ally_reach[unit.power, province]``, and
    walk adjacent provinces.  For each adjacent province that is NOT
    controlled by a trusted ally (checked via the three ``g_AllyDesignation``
    slots), insert it into the unit's power's ordered set; if the resulting
    rank exceeds the current ``g_max_non_ally_reach``, update it.

    **Phase 5** — Hold-weight population (the only part the prior stub had).

    **Phase 6** — Per-power hold-order sequence generation.  Calls
    ``BuildOrder_RTO`` (sets order type = HLD), ``FUN_00463690`` (DAIDE
    token serializer, ported as ``_build_movement_order_token``), and
    ``FUN_00466c40`` (token list concatenator).  Builds per-power default
    hold DAIDE sequences in ``g_hold_order_seqs[power]`` for the fallback
    submission path (``BuildAndSendSUB``).  Ported 2026-04-21 (MV-1 fix).
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
            if state.g_threat_level[power_idx, prov] > 0:
                state.g_hold_weight[prov] = max(state.g_hold_weight[prov], 0.4)
            else:
                state.g_hold_weight[prov] = 1.0

    # ── Phase 6: Hold-order sequence generation ─────────────────────────
    # Port of EnumerateHoldOrders.c lines 227-293.
    #
    # C algorithm:
    #   1. For each power with SC count > 0: clear DAT_00b954d0[power] = 0
    #   2. For each power (local_7c = 0..num_powers-1):
    #      a. ResetPerTrialState(gamestate)
    #      b. Build "SUB" prefix + DAT_00bc1e0c → token accumulator
    #      c. Walk UnitList: for each unit where unit.power == power:
    #         - BuildOrder_RTO(gamestate, prov, prov) → set order type = HLD (1)
    #         - FUN_00463690(gamestate, buf, unit_record) → serialize to DAIDE tokens
    #           (already ported as _build_movement_order_token in bot/orders.py)
    #         - FUN_00466c40(accum, buf, tokens) → concatenate with DAIDE brackets
    #      d. Store accumulated tokens in g_HoldOrderSeqs[power]
    #
    # FUN_00463690 is a switch on order type → DAIDE token serializer.
    # FUN_00466c40 is a token list concatenator (wraps in DAIDE parentheses).
    # BuildOrder_RTO simply sets the unit's order field to 1 (HLD).
    #
    # The Python bot's order submission path (_build_gof_seq in bot/gof.py)
    # constructs DAIDE tokens on-the-fly from the order table, so
    # g_hold_order_seqs is not consumed by the current submission pipeline.
    # We build it here for completeness and potential press-mode use.
    #
    # Fix 2026-04-21 (MV-1): Ported from Ghidra decompiles of FUN_00463690
    # and FUN_00466c40.
    _build_hold_order_seqs(state, power_idx)


def _build_reach_matrices(state: InnerGameState):
    """Phases 1-2 of EnumerateHoldOrders: build reach matrices.

    Populates:
      * ``state.g_unit_province_reach[power, province]`` — rank of *province*
        in *power*'s ordered province set.
      * ``state.g_max_non_ally_reach[power, province]``   — max rank among
        non-ally adjacent provinces for the unit's own power.
    """

    # ── Phase 1: Zero arrays ──────────────────────────────────────────────
    state.g_unit_province_reach[:] = 0
    state.g_max_non_ally_reach[:] = 0

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
        #   g_unit_province_reach[province + power*256] = rank
        for p in range(NUM_POWERS):
            rank = _find_or_insert(power_sets[p], prov_id)
            state.g_unit_province_reach[p, prov_id] = rank

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
        # C (lines 108-110): g_max_non_ally_reach[power*256+prov] =
        #                     g_unit_province_reach[power*256+prov]
        state.g_max_non_ally_reach[unit_power, prov_id] = \
            state.g_unit_province_reach[unit_power, prov_id]

        # 2d. Walk adjacencies — ally-trust gate.
        # C (lines 111-166): for each adj province, check 3 designation
        # arrays.  If the adjacent province is NOT controlled by a trusted
        # ally (trust == 0), insert it into the unit-power's ordered set and
        # update MaxNonAllyReach if the new rank exceeds the current value.
        for adj_prov in adj_list:
            trust = _get_ally_trust_for_adj(state, unit_power, adj_prov)
            if trust == 0:
                adj_rank = _find_or_insert(power_sets[unit_power], adj_prov)
                cur_max = state.g_max_non_ally_reach[unit_power, prov_id]
                if adj_rank > cur_max:
                    state.g_max_non_ally_reach[unit_power, prov_id] = adj_rank


def compute_safe_reach(state: InnerGameState):
    """
    Port of FUN_0043dfb0 = ComputeSafeReach.

    Builds a [province][power] contestedness matrix, then for each unit checks
    whether its province and all adjacent provinces are uncontested from its
    power's perspective.  If so, writes the max sorted-set rank across those
    provinces to g_safe_reach_score[unit.province]; otherwise leaves the sentinel
    0xffffffff in place.

    Phase 1 — initialise g_safe_reach_score and contested matrix.
    Phase 2 — for each unit, mark unit.province + adjacencies contested for all
               other powers  (AdjacencyList call #1).
    Phase 3 — province token pass: AMY units re-mark their own province for
               other powers (redundant but faithful to binary); FLT units mark
               their province contested for ALL powers including their own
               (fleets block army safe-reach universally).
    Phase 4 — second unit pass: compute max sorted-set rank across unit.province
               and adjacencies; store to g_safe_reach_score only when all squares
               are uncontested  (AdjacencyList call #2).
    """
    num_provinces = 256
    num_powers = 7

    # Phase 1 — initialise
    state.g_safe_reach_score = np.full(num_provinces, 0xFFFFFFFF, dtype=np.uint32)
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
            state.g_safe_reach_score[prov_id] = score


# ---------------------------------------------------------------------------
#  Phase 6 — Hold-order sequence generation
# ---------------------------------------------------------------------------

def _build_hold_order_seqs(state: InnerGameState, power_idx: int) -> None:
    """Port of EnumerateHoldOrders Phase 6 (lines 227-293).

    Builds per-power default-hold DAIDE token sequences and stores them
    in ``state.g_hold_order_seqs[power]``.  Only runs on the power_idx==0
    call (Phase 6 in C iterates all powers in one pass).

    C algorithm:
      1. For each power with SC count > 0: clear DAT_00b954d0[power] = 0.
      2. For each power (local_7c):
         a. ResetPerTrialState(gamestate)
         b. Prepend 'SUB' token (FUN_00466f80 with &SUB + DAT_00bc1e0c)
         c. Walk UnitList: for each unit where unit.power == local_7c:
            - BuildOrder_RTO(gamestate, prov, prov) → sets order type to HLD (1)
            - FUN_00463690(gamestate, buf, unit_record) → serialize order to
              DAIDE tokens (ported as _build_movement_order_token in bot/orders.py)
            - FUN_00466c40(accum, buf, tokens) → concatenate with DAIDE
              parenthesis wrapping
         d. Store in g_HoldOrderSeqs[power]

    FUN_00463690 switch cases:
      0/1 (HLD): ``( POWER AMY|FLT PROV ) HLD``
      2   (MTO): ``( POWER AMY|FLT PROV ) MTO DEST``
      3   (SUP_HLD): ``( POWER AMY|FLT PROV ) SUP ( TPOWER AMY|FLT TPROV )``
      4   (SUP_MTO): ``( POWER AMY|FLT PROV ) SUP ( TPOWER AMY|FLT TPROV ) MTO DEST``
      5   (CVY): ``( POWER AMY|FLT PROV ) CVY ( TPOWER AMY|FLT TPROV ) CTO DEST``
      6   (CTO): ``( POWER AMY|FLT PROV ) CTO DEST VIA ( fleet_chain )``

    Since Phase 6 forces all units to HLD via BuildOrder_RTO before serializing,
    only case 0/1 is ever hit.  The resulting token is:
      ``( POWER AMY|FLT PROV ) HLD``

    FUN_00466c40 concatenates token lists with DAIDE bracket separators
    (DAT_004c79b4/b8/7d14).  For the final sequence the structure is:
      ``SUB ( ( POWER AMY|FLT PROV1 ) HLD ) ( ( POWER AMY|FLT PROV2 ) HLD ) ...``

    Fix 2026-04-21 (MV-1): Ported from Ghidra decompiles of FUN_00463690
    and FUN_00466c40.
    """
    # Only run on the first call (power_idx == 0) since C Phase 6 loops all
    # powers in one pass.
    if power_idx != 0:
        return

    # Lazy-init the per-power hold order sequences dict
    if not hasattr(state, 'g_hold_order_seqs'):
        state.g_hold_order_seqs = {}

    # Lazy-import to avoid circular dependency (bot.orders → state → moves)
    from ..bot.orders import _build_movement_order_token
    from ..bot._shared import _DAIDE_POWER_NAMES

    num_powers = state.g_num_powers if hasattr(state, 'g_num_powers') else NUM_POWERS

    # Step 1: Clear per-power counter for powers with SCs
    # C: if (curr_sc_cnt[iVar10] != 0) DAT_00b954d0[iVar10] = 0
    # DAT_00b954d0 is not otherwise used in Python; skip for now.

    # Step 2: Per-power loop
    for power in range(num_powers):
        # C lines 204-226: clear per-power province reach arrays BEFORE
        # generating hold sequences.  C zeros g_UnitProvinceReach and
        # g_MaxNonAllyReach for each province before each power's pass.
        # Fixed 2026-04-23 (audit finding MOV-3): was missing, leaving
        # stale reach data from prior powers.
        state.g_unit_province_reach[power, :] = 0
        state.g_max_non_ally_reach[power, :] = 0

        # 2a. ResetPerTrialState — clear build list and waive count
        if hasattr(state, 'g_build_order_list'):
            state.g_build_order_list.clear()
        state.g_waive_count = 0

        # 2b. Build SUB prefix token
        # C: FUN_00466f80(&SUB, &local_58, &DAT_00bc1e0c)
        # DAT_00bc1e0c is the power-name token for the current power
        power_name = _DAIDE_POWER_NAMES[power] if power < len(_DAIDE_POWER_NAMES) else 'UNO'
        seq: list[str] = ['SUB']

        # 2c. Walk units: for each unit belonging to this power
        for prov, unit_data in state.unit_info.items():
            if unit_data.get('power') != power:
                continue

            # BuildOrder_RTO: set order type = HLD (1) in g_order_table
            # C: *(undefined4 *)(iVar2 + 0x20) = 1
            state.g_order_table[prov, 0] = 1.0  # _F_ORDER_TYPE = HLD

            # FUN_00463690: serialize order to DAIDE tokens
            # Since we just set HLD, this will produce: ( POWER AMY|FLT PROV ) HLD
            tok = _build_movement_order_token(state, prov)
            if tok is not None:
                # FUN_00466c40: wrap in DAIDE parentheses and concatenate
                seq.append(f'( {tok} )')

        # 2d. Store in g_hold_order_seqs[power]
        state.g_hold_order_seqs[power] = seq

    # Restore order table — Phase 6 was a serialization pass; the actual
    # order table will be rebuilt by the MC trial loop.  C achieves this
    # via ResetPerTrialState at the top of each trial; we zero explicitly
    # to avoid stale HLD entries leaking into subsequent phases.
    state.g_order_table[:, 0] = 0.0


