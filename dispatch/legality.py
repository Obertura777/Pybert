"""Pre-dispatch legality checks: adjacency and convoy reachability.

Split from dispatch.py during the 2026-04 refactor.

Two short predicates used by ``validate_and_dispatch_order`` before a
move / convoy order is committed to ``g_order_table``:

  * ``_is_legal_mto``       — province-adjacency gate.
  * ``is_convoy_reachable`` — ``FUN_004619f0`` convoy-path BFS gate.

Both are pure-query helpers — no side effects, no error codes, no
logger usage.

Module-level deps: ``..state.InnerGameState``.
"""

from ..state import InnerGameState

def _is_legal_mto(state: InnerGameState, src_prov_id: int, dst_prov_id: int,
                   unit_type: str = '') -> bool:
    """
    Port of FUN_00460b30 — adjacency gate for MTO orders.

    C summary (two-level lower-bound search):
      1. Resolves the province struct at inner_state + src_prov * 0x24 + 8.
      2. Calls AdjacencyList_LowerBound with the unit's coast/type token
         (ushort at param_1+4) to locate the first adjacency node whose
         unit-type mask matches the moving unit (army vs fleet).
      3. If a valid node exists (node != end-sentinel), calls
         IsLegalMove_Alt / SubList_LowerBound_Coast (FUN_00460ac0) on the
         node's sub-list with the (dst_province_id, dst_coast_token) key.
      4. Returns 1 (legal) if the sub-list contains the destination, 0
         (illegal) otherwise.

    Python translation: checks province adjacency via adj_matrix AND enforces
    unit-type terrain rules:
      - Fleets cannot move to LAND (landlocked) provinces.
      - Armies cannot move to WATER (sea) provinces.
      - COAST provinces are accessible by both.

    Callees absorbed (infrastructure only — no separate port needed):
      AdjacencyList_LowerBound  — lower-bound on outer adjacency list
      SubList_LowerBound_Coast  (FUN_00460ac0) — coast-aware sub-list search
      AssertFail                (FUN_0047a948) — error handler
    """
    if unit_type:
        return state.can_reach_by_type(src_prov_id, dst_prov_id, unit_type)
    return state.can_reach(src_prov_id, dst_prov_id)


def is_convoy_reachable(
    state: InnerGameState,
    src_prov: int,
    unit_type: str,
    dest_prov: int,
    extra: int = -1,
) -> bool:
    """
    Port of FUN_004619f0 — convoy / move-legality check.

    C signature:
        char __thiscall FUN_004619f0(void *this, int *param_1, int *param_2, int param_3)
    Called as:
        FUN_004619f0(inner_state, unit_data, dest_prov, -1)
    where *param_1 = src province id, param_1[3] = unit type (AMY token),
    (int)param_2 = dest province id, param_3 = -1.

    Algorithm (decompiled.txt):
      1. IsLegalMove check (direct adjacency): if src can directly reach dest → True.
      2. Early-exit conditions:
           - Unit is not an army               → False  (C: AMY != param_1[3])
           - Dest province flag at +4 is 0     → False  (C: flag=='\0'; water prov)
      3. BFS through fleet-occupied water provinces:
           a. Seed queue with all provinces adjacent to src (the outer+inner
              adjacency-sublist double-loop building local_48).
           b. If extra (param_3) != -1, pre-mark it visited (C: StdMap_FindOrInsert
              into local_3c before the BFS while).
           c. Pop province p; skip if already visited.
           d. If p is water (flag==0): check unit list (this+0x2450/0x2454); if
              a unit exists there (fleet), expand p's adjacency into queue.
           e. Else (p is land, flag!=0): if p == dest_prov → return True.
      4. Return False if queue exhausted.

    The visited-set (local_3c) and BFS queue (local_44 + local_48) are
    implemented here as plain Python sets; the STL ordered-set / map
    internals are not observable from outside.
    """
    # Step 1: IsLegalMove — direct adjacency
    if state.can_reach(src_prov, dest_prov):
        return True

    # Step 2: Only armies convoy; destination must be a land/coastal province.
    # C: (AMY == (short)param_1[3]) — army unit type check.
    # C: (*(char *)(this + dest_prov*0x24 + 4) != '\0') — dest flag non-zero = land.
    if unit_type != 'A':
        return False
    if dest_prov in state.water_provinces:
        return False

    # Step 3: BFS through fleet-occupied water provinces.
    # local_3c = visited set; seeded with src (C: StdMap_FindOrInsert(local_3c, ..., param_1)).
    visited: set = {src_prov}
    if extra != -1:
        visited.add(extra)

    # Seed queue from src adjacency list (the outer+inner adjacency-sublist double-loop
    # that inserts adjacent province ids into local_48 before the BFS while).
    queue: set = set(state.adj_matrix.get(src_prov, []))

    while queue:
        prov = next(iter(queue))
        queue.discard(prov)
        if prov in visited:
            continue
        visited.add(prov)

        if prov in state.water_provinces:
            # C: flag=='\0' branch — check unit list at this+0x2450/0x2454.
            # If a fleet is present (OrderedSet_FindOrInsert finds it), expand
            # its adjacency sublist into local_48.
            unit = state.unit_info.get(prov)
            if unit is not None and unit['type'] == 'F':
                for adj in state.adj_matrix.get(prov, []):
                    if adj not in visited:
                        queue.add(adj)
        else:
            # C: else-if (piVar9 == param_2) → local_85 = '\x01' (found destination)
            if prov == dest_prov:
                return True

    return False


