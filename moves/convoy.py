"""Convoy reach enumeration and convoy-order assembly.

Split from moves.py during the 2026-04 refactor.

Convoy-chain pipeline called from ``generate_orders`` and the MC trial
loop:

  * ``enumerate_convoy_reach``   — port of ``FUN_0043ee00``; populates
    ``g_ConvoyReachCount`` plus distance-decay weight tables
    ``g_WinterScore_A/B`` for each of a power's units.
  * ``register_convoy_fleet``    — register a fleet onto an existing
    convoy chain (``g_ConvoyRoute``).
  * ``build_convoy_orders``      — commit the winning convoy orders
    (``_ORDER_CVY`` / ``_ORDER_CTO``) to ``g_OrderTable``, calling into
    ``.support.assign_support_order`` for each convoying fleet.

Module-level deps: ``..state.InnerGameState``, ``.support.assign_support_order``.
"""

from ..state import InnerGameState
from .support import assign_support_order
from ._constants import (
    _F_ORDER_TYPE,
    _F_DEST_PROV,
    _F_INCOMING_MOVE,
    _F_ORDER_ASGN,
    _F_CONVOY_LEG0,
    _F_CONVOY_LEG1,
    _F_CONVOY_LEG2,
    _F_SOURCE_PROV,
    _ORDER_MTO,
    _ORDER_CVY,
    _ORDER_CTO,
    _MAX_CONVOY_CHAIN_DEPTH,
)


def _harmonic_dist_weight(n: int, base: float) -> float:
    """
    Harmonic-mean distance-decay weight at BFS depth n.
    Formula from research.md §EnumerateConvoyReach score detail:
      1 / (1/base^n  +  1/(1.5^n × 30))
    At n=0: ≈ 0.968 (near-full weight).  Decays then rises as 1.5^n dominates.
    """
    base_pow = base ** n if n > 0 else 1.0
    exp15    = 1.5  ** n if n > 0 else 1.0
    return 1.0 / (1.0 / base_pow + 1.0 / (exp15 * 30.0))


def enumerate_convoy_reach(state: InnerGameState, power_idx: int):
    """
    Port of FUN_0043ee00 = EnumerateConvoyReach.

    Multi-phase BFS enumerating all provinces reachable by each of power_idx's
    units, with full convoy-chain expansion for army units.

    Phase 1  Seed reachCandidates from the unit's province (wave 0).
    Phase 2  Main BFS through g_BuildCandidateList provinces; write distance-
             decay weights to g_WinterScore_A / g_WinterScore_B (base 7 / 8).
    Phase 3  (AMY only) Convoy sub-passes A–D:
             A  Seed fleetChainList from fleet neighbours of reached provinces;
                collect their unoccupied neighbours into freeDestinations.
             B  BFS-expand the fleet chain through further unoccupied provinces.
             C  From fleet chain, record occupied build-candidate neighbours
                as army-reachable convoy landing squares.
             D  10-hop convoy chain completion pass (MAX_CONVOY_CHAIN_DEPTH).

    Writes:
      g_ConvoyReachCount[power_idx, prov]  +1 for every convoy-reachable province
      g_WinterScore_A[prov]               max harmonic weight (base 7.0)
      g_WinterScore_B[prov]               max harmonic weight (base 8.0)

    Requires state.g_BuildCandidateList (set of target province IDs) to be
    populated before calling.  Falls back to all occupied/SC provinces if unset.
    """
    build_candidates: set = state.g_BuildCandidateList
    if not build_candidates:
        # Fallback: provinces that have any unit or are supply centres
        build_candidates = {
            prov for prov in range(256)
            if state.has_unit(prov) or state.g_SCOwnership[:, prov].any()
        }

    for src_prov, unit_data in list(state.unit_info.items()):
        if unit_data['power'] != power_idx:
            continue

        unit_type = unit_data['type']
        coast_tok = unit_data.get('coast', '')

        # ── Phase 1: seed reachCandidates with unit position at wave 0 ──────
        reach_candidates = [(src_prov, coast_tok, 0)]  # (prov, coast_tok, wave)
        in_reach = {src_prov}

        # ── Phase 2: main BFS through build-candidate adjacencies ────────────
        army_reach: set = set()
        bfs_wave = 0
        changed = True

        while changed and bfs_wave <= 256:
            changed = False
            # AdjacencyList call #1: neighbours at current wave
            for cur_prov, cur_coast, wave in [e for e in reach_candidates if e[2] == bfs_wave]:
                dist_weight_a = _harmonic_dist_weight(wave, 7.0)
                dist_weight_b = _harmonic_dist_weight(wave, 8.0)

                for adj in state.get_unit_adjacencies(cur_prov):
                    if adj not in build_candidates:
                        continue
                    # Score with harmonic distance-decay weights
                    if dist_weight_a > state.g_WinterScore_A[adj]:
                        state.g_WinterScore_A[adj] = dist_weight_a
                    if dist_weight_b > state.g_WinterScore_B[adj]:
                        state.g_WinterScore_B[adj] = dist_weight_b
                    army_reach.add(adj)
                    if adj not in in_reach:
                        in_reach.add(adj)
                        reach_candidates.append((adj, cur_coast, wave + 1))
                        changed = True

            bfs_wave += 1

        # ── Phase 3: army-only convoy expansion ─────────────────────────────
        if unit_type != 'A':
            for prov in army_reach:
                state.g_ConvoyReachCount[power_idx, prov] += 1
            continue

        fleet_chain: list = []       # (prov, coast_tok, wave) fleet chain nodes
        in_fleet_chain: set = set()
        free_destinations: set = set()

        # Sub-pass A: for each reached province, find adjacent fleet units;
        #   seed fleetChainList with those fleets and collect their unoccupied
        #   neighbours into freeDestinations.
        for cur_prov, cur_coast, wave in reach_candidates:
            # AdjacencyList call #2: fleet-type filter
            for adj in state.get_unit_adjacencies(cur_prov):
                if state.get_unit_type(adj) != 'F':
                    continue
                if adj not in in_fleet_chain:
                    in_fleet_chain.add(adj)
                    fleet_chain.append((adj, cur_coast, wave))
                for fleet_adj in state.get_unit_adjacencies(adj):
                    if not state.has_unit(fleet_adj):    # unoccupied
                        free_destinations.add(fleet_adj)

        # Sub-pass B: BFS-expand fleet chain through further unoccupied provinces.
        fc_idx = 0
        while fc_idx < len(fleet_chain):
            fc_prov, fc_coast, fc_wave = fleet_chain[fc_idx]
            fc_idx += 1
            # AdjacencyList call #3
            for adj in state.get_unit_adjacencies(fc_prov):
                if not state.has_unit(adj):              # unoccupied
                    free_destinations.add(adj)
                    if adj not in in_fleet_chain:
                        in_fleet_chain.add(adj)
                        fleet_chain.append((adj, fc_coast, fc_wave + 1))

        # Sub-pass C: from fleet chain, detect convoy landing on occupied
        #   build-candidate squares (army crosses to a contested province).
        for fc_prov, fc_coast, fc_wave in fleet_chain:
            # AdjacencyList call #4
            for adj in state.get_unit_adjacencies(fc_prov):
                if state.has_unit(adj) and adj in build_candidates:
                    army_reach.add(adj)
                    if adj not in in_reach:
                        in_reach.add(adj)
                        reach_candidates.append((adj, fc_coast, fc_wave))

        # Sub-pass D: 10-hop convoy chain completion pass.
        # local_1a8 counts from 0..MAX_CONVOY_CHAIN_DEPTH (< 0xb in original).
        local_1a8 = 0
        while local_1a8 < _MAX_CONVOY_CHAIN_DEPTH:
            for cur_prov, cur_coast, wave in [e for e in reach_candidates if e[2] == local_1a8]:
                # AdjacencyList call #5
                for adj in state.get_unit_adjacencies(cur_prov):
                    if adj in build_candidates and adj not in army_reach:
                        army_reach.add(adj)
                        if adj not in in_reach:
                            in_reach.add(adj)
                            reach_candidates.append((adj, 'A',wave + 1))
            local_1a8 += 1

        # Commit convoy reach counts for all discovered destinations
        for prov in free_destinations | army_reach:
            state.g_ConvoyReachCount[power_idx, prov] += 1


def register_convoy_fleet(state: InnerGameState, power_idx: int, fleet_prov: int) -> None:
    """
    Port of RegisterConvoyFleet.

    For fleet province `fleet_prov`, iterates all fleet-adjacent provinces.
    For each adjacent province `adj` where g_ArmyAdjCount[adj] > 0 AND
    g_ProvinceAccessFlag[power_idx, adj] > 0, marks g_ProvinceScoreTrial[adj] = 1.

    The C++ guard (offset +4 in province record) prevents double-processing the
    same province within a trial; in Python we use g_ConvoyFleetRegistered (a set
    reset per trial alongside g_ArmyAdjCount / g_ProvinceScoreTrial).

    AdjacencyList_FilterByUnitType(..., FLT) would return only fleet-navigable
    neighbours; the Python adj_matrix merges all adjacency types, so we use it
    as-is.  This is acceptable here because register_convoy_fleet is marking
    army-adjacent provinces for convoy scoring, not generating fleet move orders.
    Unit-type terrain filtering for actual moves is enforced in _build_order_mto
    (monte_carlo.py) and _is_legal_mto (dispatch.py).
    """
    if fleet_prov in state.g_ConvoyFleetRegistered:
        return
    for adj in state.get_unit_adjacencies(fleet_prov):
        if state.g_ArmyAdjCount[adj] > 0 and state.g_ProvinceAccessFlag[power_idx, adj] > 0:
            state.g_ProvinceScoreTrial[adj] = 1


def populate_convoy_routes(state: InnerGameState, power_idx: int) -> None:
    """
    Narrow port of ProcessTurn's convoy-chain BFS
    (Source/ProcessTurn.c:1425-1929 - per-trial convoy route table init
    plus the fleet-chain walk that threads armies across water).

    For each army owned by ``power_idx``, enumerates *every* destination
    reachable via a fleet chain (1, 2, or 3 fleets) and records the
    shortest chain for each (src, dst) pair in
    ``state.g_ConvoyRoute[army_src][dst_prov]``.  Armies with no viable
    chain are absent from the outer dict.

    This per-destination keying matches the C layout
    (Source/ProcessTurn.c:1628 etc., stride 0x14 at +0x214): an army
    with two candidate destinations requiring different fleet chains
    gets the right fleets for each.  Previously this was destination-
    blind (one chain per source), which caused the wrong fleets to be
    committed on per-turn re-evaluation.  Fixed 2026-04-18
    (AUDIT_moves_and_messages.md #7).

    Mutates only ``state.g_ConvoyRoute``.
    """
    for src_prov, unit_data in list(state.unit_info.items()):
        if unit_data.get('power') != power_idx:
            continue
        if unit_data.get('type') != 'A':
            continue

        chains_by_dst = _enumerate_convoy_chains_for_src(state, src_prov)
        if not chains_by_dst:
            # No viable chain - clear any stale entry from prior trials.
            state.g_ConvoyRoute.pop(src_prov, None)
            continue

        state.g_ConvoyRoute[src_prov] = {
            dst: {'fleet_count': len(chain), 'fleets': list(chain)}
            for dst, chain in chains_by_dst.items()
        }


def _get_convoy_route(state: InnerGameState, src_prov: int, dst_prov: int):
    """
    Public helper used by the MC readers to look up the fleet chain for
    a specific (src, dst) convoy pair.  Returns ``(fleet_count, fleets)``.
    ``fleet_count == 0`` and an empty list mean "no chain registered".

    Tolerates the legacy destination-blind shape
    (``g_ConvoyRoute[src] = {'fleet_count': ..., 'fleets': [...]}``) so
    callers or test fixtures still holding that shape continue to work
    during the migration.  Prefer the new nested shape for fresh writes.
    """
    src_entry = state.g_ConvoyRoute.get(src_prov)
    if not src_entry:
        return 0, []
    # Legacy flat shape: recognised by presence of 'fleet_count' at the
    # top of the src entry instead of a nested dst → info mapping.
    if 'fleet_count' in src_entry:
        return int(src_entry.get('fleet_count', 0)), list(src_entry.get('fleets', []))
    dst_entry = src_entry.get(dst_prov)
    if not dst_entry:
        return 0, []
    return int(dst_entry.get('fleet_count', 0)), list(dst_entry.get('fleets', []))


def _enumerate_convoy_chains_for_src(state: InnerGameState, army_src: int) -> dict:
    """
    BFS over fleet chains starting from fleets adjacent to ``army_src``.
    Returns ``{dst_prov: chain}`` where ``dst_prov`` is a non-fleet,
    non-source landing province and ``chain`` is the *shortest* fleet
    tuple (1..3 elements) that convoys ``army_src`` to ``dst_prov``.

    Depth-1 seeds are fleets directly adjacent to the army.  At each
    chain step we record every landing reachable via the terminal
    fleet (only the first — i.e. shortest — chain per dst wins, so a
    longer chain that also reaches the same dst does NOT overwrite).
    The BFS caps at 3 fleets, matching the C struct's three convoy-leg
    slots at +0x218, +0x21c, +0x220.
    """
    MAX_CHAIN = 3

    depth_1_fleets = [
        adj for adj in state.get_unit_adjacencies(army_src)
        if state.get_unit_type(adj) == 'F'
    ]
    if not depth_1_fleets:
        return {}

    result: dict = {}                           # dst -> shortest chain
    frontier = [(f,) for f in depth_1_fleets]
    visited_fleets = set(depth_1_fleets)

    for depth in range(1, MAX_CHAIN + 1):
        next_frontier: list = []
        for chain in frontier:
            terminal = chain[-1]
            # Record every landing square reachable from this terminal.
            for adj in state.get_unit_adjacencies(terminal):
                if adj == army_src:
                    continue
                if state.get_unit_type(adj) == 'F':
                    continue
                # First chain reaching this dst wins (BFS order →
                # shortest by fleet count).
                if adj not in result:
                    result[adj] = chain

            # Extend the chain through another fleet — but only if we
            # haven't hit the max chain length yet.
            if depth < MAX_CHAIN:
                for adj in state.get_unit_adjacencies(terminal):
                    if state.get_unit_type(adj) != 'F':
                        continue
                    if adj in visited_fleets:
                        continue
                    visited_fleets.add(adj)
                    next_frontier.append(chain + (adj,))
        if not next_frontier:
            break
        frontier = next_frontier

    return result


def build_convoy_orders(state: InnerGameState, power_idx: int, src_prov: int, dst_prov: int) -> None:
    """
    Port of FUN_0044b760 = BuildConvoyOrders.

    Builds the complete CTO + CVY order chain for a convoy attempt. Reads
    g_MaxProvinceScore to seed each fleet's score, while the army inherits
    the ordered-set score for the destination province.
    """
    fleet_count, route = _get_convoy_route(state, src_prov, dst_prov)
    if fleet_count <= 0:
        return
    
    # Army setup (CTO)
    state.g_OrderTable[src_prov, _F_ORDER_TYPE] = _ORDER_CTO
    state.g_OrderTable[src_prov, _F_DEST_PROV] = dst_prov
    state.g_OrderTable[src_prov, _F_ORDER_ASGN] = 1  # Order committed
    
    if len(route) > 0:
        state.g_OrderTable[src_prov, _F_CONVOY_LEG0] = route[0]
    if len(route) > 1:
        state.g_OrderTable[src_prov, _F_CONVOY_LEG1] = route[1]
    if len(route) > 2:
        state.g_OrderTable[src_prov, _F_CONVOY_LEG2] = route[2]
        
    state.g_ConvoyDstToSrc[dst_prov] = src_prov
    
    # Army inherits score from OrderedSet (via get_candidate_score)
    score = state.get_candidate_score(power_idx, dst_prov, 0)
    state.g_ConvoyChainScore[src_prov] = score
    state.g_OrderScoreHi[src_prov] = score
    
    # Fleet setup (CVY)
    for fleet_i in route:
        max_score = state.g_MaxProvinceScore[fleet_i]
        state.g_ConvoyChainScore[fleet_i] = max_score
        state.g_OrderScoreHi[fleet_i] = max_score
        
        state.g_OrderTable[fleet_i, _F_ORDER_TYPE] = _ORDER_CVY
        state.g_OrderTable[fleet_i, _F_SOURCE_PROV] = src_prov
        state.g_OrderTable[fleet_i, _F_DEST_PROV] = dst_prov
        state.g_OrderTable[fleet_i, _F_ORDER_ASGN] = 1
        
        register_convoy_fleet(state, power_idx, fleet_i)
        assign_support_order(state, power_idx, src_prov, dst_prov, 0, flag=1)


