"""Convoy reach enumeration and convoy-order assembly.

Split from moves.py during the 2026-04 refactor.

Convoy-chain pipeline called from ``generate_orders`` and the MC trial
loop:

  * ``enumerate_convoy_reach``   — port of ``FUN_0043ee00``; builds the
    persistent all-board movement/convoy reach index ``DAT_00bc1e1c``.
  * ``register_convoy_fleet``    — register a fleet onto an existing
    convoy chain (``g_convoy_route``).
  * ``build_convoy_orders``      — commit the winning convoy orders
    (``_ORDER_CVY`` / ``_ORDER_CTO``) to ``g_order_table``, calling into
    ``.support.assign_support_order`` for each convoying fleet.

Module-level deps: ``..state.InnerGameState``, ``.support.assign_support_order``.
"""

import heapq
import logging
from collections import deque
from collections.abc import Iterable

from ..state import InnerGameState
from .support import assign_support_order

logger = logging.getLogger(__name__)
from ._constants import (
    _F_ORDER_TYPE,
    _F_DEST_PROV,
    _F_DEST_COAST,
    _F_INCOMING_MOVE,
    _F_CONVOY_DEPTH,
    _F_CONVOY_LEG0,
    _F_CONVOY_LEG1,
    _F_CONVOY_LEG2,
    _F_SECONDARY,
    _F_THREAT_TOTAL,
    _ORDER_MTO,
    _ORDER_CVY,
    _ORDER_CTO,
    _unit_location_token,
    _MAX_CONVOY_CHAIN_DEPTH,
)


def _filtered_adj(state: InnerGameState, prov: int, unit_type: str) -> list:
    """Return adjacencies filtered by unit type, matching C's
    AdjacencyList_FilterByUnitType.  Armies skip water; fleets skip land."""
    if unit_type in ('A', 'AMY'):
        raw = state.get_unit_adjacencies(prov)
        return [a for a in raw if a not in state.water_provinces]
    if unit_type in ('F', 'FLT'):
        return list(state.fleet_adj_matrix.get(prov, []))
    return list(state.get_unit_adjacencies(prov))


def _harmonic_dist_weight(n: int, base: float) -> float:
    """
    Harmonic-mean distance-decay weight at BFS depth n.
    Formula from research.md §EnumerateConvoyReach score detail:
      1 / (1/base^n  +  1/(1.5^n × 30))
    The stored distance score rises with depth; its inverse contribution in
    InitScoringState and ComputeWinterBuilds therefore decays with distance.
    """
    base_pow = base ** n if n > 0 else 1.0
    exp15    = 1.5  ** n if n > 0 else 1.0
    return 1.0 / (1.0 / base_pow + 1.0 / (exp15 * 30.0))


def _topology_base_provinces(state: InnerGameState) -> list[int]:
    """Return C-style province ids, excluding Python coast-variant ids."""
    variants = {
        variant
        for coast_ids in getattr(state, 'coast_variants', {}).values()
        for variant in coast_ids
    }
    valid = set(getattr(state, 'valid_provinces', ()) or state.adj_matrix)
    valid.difference_update(variants)
    valid.difference_update(getattr(state, 'shut_provinces', ()))
    return sorted(valid)


def _fleet_tokens_for_province(
    state: InnerGameState,
    province: int,
) -> list[str]:
    """Return the legal FLT/coast tokens for one base province."""
    coast_tokens = sorted(
        str(coast).upper().lstrip('/')
        for pid, coast in state.fleet_coast_adj
        if pid == province
    )
    if coast_tokens:
        return coast_tokens
    if (province in state.water_provinces
            or (province not in state.land_provinces
                and bool(state.fleet_adj_matrix.get(province)))):
        return ['']
    return []


def _fleet_state_adjacencies(
    state: InnerGameState,
    province: int,
    coast: str,
) -> list[tuple[int, str]]:
    """Return destination (province, coast) fleet-token states."""
    if coast:
        raw = state.fleet_coast_adj.get((province, '/' + coast), ())
    else:
        raw = state.fleet_adj_matrix.get(province, ())

    result: list[tuple[int, str]] = []
    for destination in raw:
        destination = int(destination)
        destination_coasts = _fleet_tokens_for_province(state, destination)
        if not destination_coasts:
            continue
        if destination_coasts == ['']:
            result.append((destination, ''))
            continue
        for destination_coast in destination_coasts:
            reverse_adjacencies = state.fleet_coast_adj.get(
                (destination, '/' + destination_coast), ()
            )
            if province in reverse_adjacencies:
                result.append((destination, destination_coast))
    return result


def _convoy_dist_weight(distance: int) -> float:
    """C's convoy/post-landing weight: 300 * 1.5**distance."""
    return 300.0 * (1.5 ** int(distance))


def enumerate_convoy_reach(
    state: InnerGameState,
    power_idx: int | None = None,
) -> None:
    """Build DAT_00bc1e1c's persistent all-board reach index.

    The recovered routine has no power-index parameter. It walks every legal
    province/unit-token source, inserts ordinary movement reach records with
    the 7/8-and-1.5 harmonic distance weights, and augments army reach through
    possible sea convoy chains and post-landing army movement. power_idx
    remains an ignored compatibility parameter for older direct callers.

    The outer C tree is keyed by destination province plus destination
    unit/coast token. Python groups those outer keys by base province while
    retaining both tokens on each BuildOrderSpec.
    """
    from ..heuristics._primitives import BuildOrderSpec

    base_provinces = _topology_base_provinces(state)
    base_set = set(base_provinces)
    water = set(state.water_provinces) & base_set
    landlocked = set(state.land_provinces) & base_set

    # target-key -> source-key -> record. This mirrors each outer tree node's
    # inner ordered set; first insertion is the shortest source path.
    outer_records: dict[
        tuple[int, str, str],
        dict[tuple[int, str, str], BuildOrderSpec],
    ] = {}

    def ensure_outer(destination: int, unit_type: str, coast: str = '') -> None:
        outer_records.setdefault((destination, unit_type, coast), {})

    for province in base_provinces:
        if province not in water:
            ensure_outer(province, 'AMY')
        for coast in _fleet_tokens_for_province(state, province):
            ensure_outer(province, 'FLT', coast)

    def insert(
        destination: int,
        destination_type: str,
        destination_coast: str,
        source: int,
        source_type: str,
        source_coast: str,
        score: float,
    ) -> bool:
        target_key = (destination, destination_type, destination_coast)
        inner = outer_records.setdefault(target_key, {})
        source_key = (source, source_type, source_coast)
        if source_key in inner:
            return False
        inner[source_key] = BuildOrderSpec(
            source_province=source,
            source_unit_type=source_type,
            source_coast=source_coast,
            destination_unit_type=destination_type,
            destination_coast=destination_coast,
            score=float(score),
        )
        return True

    army_adjacencies = {
        province: [
            int(adj) for adj in state.adj_matrix.get(province, ())
            if adj in base_set and adj not in water
        ]
        for province in base_provinces
        if province not in water
    }

    for source in base_provinces:
        if source not in water:
            source_key = (source, 'AMY', '')
            direct_distance = {source: 0}
            queue = deque([source])
            insert(source, 'AMY', '', *source_key, 1.0)
            while queue:
                current = queue.popleft()
                next_distance = direct_distance[current] + 1
                for destination in army_adjacencies.get(current, ()):
                    if destination in direct_distance:
                        continue
                    direct_distance[destination] = next_distance
                    queue.append(destination)
                    insert(
                        destination, 'AMY', '', *source_key,
                        _harmonic_dist_weight(next_distance, 7.0),
                    )

            # Seed the possible fleet chain from every ordinarily reachable
            # coast. Sea waves retain the combined land/sea distance.
            max_direct_distance = max(direct_distance.values(), default=0)
            sea_distance: dict[int, int] = {}
            sea_heap: list[tuple[int, int]] = []
            for coast_province, land_distance in direct_distance.items():
                for fleet_coast in _fleet_tokens_for_province(
                    state, coast_province
                ):
                    for adjacent, _ in _fleet_state_adjacencies(
                        state, coast_province, fleet_coast
                    ):
                        if adjacent not in water:
                            continue
                        distance = land_distance + 1
                        if distance < sea_distance.get(adjacent, 1 << 30):
                            sea_distance[adjacent] = distance
                            heapq.heappush(sea_heap, (distance, adjacent))

            sea_expansion_limit = max_direct_distance + 3
            while sea_heap:
                distance, sea_province = heapq.heappop(sea_heap)
                if distance != sea_distance.get(sea_province):
                    continue
                if distance >= sea_expansion_limit:
                    continue
                for adjacent, _ in _fleet_state_adjacencies(
                    state, sea_province, ''
                ):
                    if adjacent not in water:
                        continue
                    next_distance = distance + 1
                    if next_distance < sea_distance.get(adjacent, 1 << 30):
                        sea_distance[adjacent] = next_distance
                        heapq.heappush(sea_heap, (next_distance, adjacent))

            # Land from eligible fleet-chain waves, then perform the source's
            # final ten-wave army expansion on the far side of the convoy.
            remote_distance: dict[int, int] = {}
            remote_heap: list[tuple[int, int]] = []
            landing_sea_limit = max_direct_distance + 1
            for sea_province, distance in sea_distance.items():
                if distance > landing_sea_limit:
                    continue
                for destination, _ in _fleet_state_adjacencies(
                    state, sea_province, ''
                ):
                    if destination in water or destination in landlocked:
                        continue
                    landing_distance = distance + 1
                    if destination in direct_distance:
                        continue
                    if landing_distance < remote_distance.get(
                        destination, 1 << 30
                    ):
                        remote_distance[destination] = landing_distance
                        heapq.heappush(
                            remote_heap, (landing_distance, destination)
                        )

            while remote_heap:
                distance, destination = heapq.heappop(remote_heap)
                if distance != remote_distance.get(destination):
                    continue
                insert(
                    destination, 'AMY', '', *source_key,
                    _convoy_dist_weight(distance),
                )
                if distance >= _MAX_CONVOY_CHAIN_DEPTH:
                    continue
                for adjacent in army_adjacencies.get(destination, ()):
                    if adjacent in direct_distance:
                        continue
                    next_distance = distance + 1
                    if next_distance < remote_distance.get(adjacent, 1 << 30):
                        remote_distance[adjacent] = next_distance
                        heapq.heappush(
                            remote_heap, (next_distance, adjacent)
                        )

        for source_coast in _fleet_tokens_for_province(state, source):
            source_key = (source, 'FLT', source_coast)
            source_state = (source, source_coast)
            distances = {source_state: 0}
            queue = deque([source_state])
            insert(source, 'FLT', source_coast, *source_key, 1.0)
            while queue:
                current_province, current_coast = queue.popleft()
                next_distance = (
                    distances[(current_province, current_coast)] + 1
                )
                for destination_state in _fleet_state_adjacencies(
                    state, current_province, current_coast
                ):
                    if destination_state in distances:
                        continue
                    distances[destination_state] = next_distance
                    queue.append(destination_state)
                    destination, destination_coast = destination_state
                    insert(
                        destination, 'FLT', destination_coast, *source_key,
                        _harmonic_dist_weight(next_distance, 7.0),
                    )

    token_order = {
        ('AMY', ''): 0,
        ('FLT', ''): 1,
        ('FLT', 'NC'): 2,
        ('FLT', 'NE'): 3,
        ('FLT', 'EC'): 4,
        ('FLT', 'SE'): 5,
        ('FLT', 'SC'): 6,
        ('FLT', 'SW'): 7,
        ('FLT', 'WC'): 8,
        ('FLT', 'NW'): 9,
    }
    state.g_build_candidate_list.clear()
    for target_key in sorted(
        outer_records,
        key=lambda key: (
            key[0], token_order.get((key[1], key[2]), 99)
        ),
    ):
        destination = target_key[0]
        inner = outer_records[target_key]
        target_list = state.g_build_candidate_list.setdefault(destination, [])
        target_list.extend(
            inner[source_key]
            for source_key in sorted(
                inner,
                key=lambda key: (
                    key[0], token_order.get((key[1], key[2]), 99)
                ),
            )
        )

def register_convoy_fleet(state: InnerGameState, power_idx: int, fleet_prov: int) -> None:
    """
    Port of RegisterConvoyFleet (Source/moves/RegisterConvoyFleet.c).

    Guard: province-record byte +4 is zero only for water provinces.  Albert
    therefore scans adjacency only when the registered fleet is at sea.

    For each FLT-adjacent province adj:
      if g_army_adj_count[adj] > 0:
        C: (-1 < access) AND (access > 0 OR g_ProvTargetFlag != 0)
        mark g_province_score_trial[adj] = 1
    """
    if fleet_prov not in state.water_provinces:
        return
    for adj in state.fleet_adj_matrix.get(fleet_prov, []):
        if state.g_army_adj_count[adj] > 0:
            # C (RegisterConvoyFleet.c:32-33): DAT_005ee8ec is the HI word of
            # the same int64 whose LO word is g_ProvTargetFlag (DAT_005ee8e8),
            # i.e. g_target_flag2 — NOT g_province_access_flag.  score_provinces
            # writes -1 there for flanked provinces, which must be excluded.
            access = int(state.g_target_flag2[power_idx, adj])
            target = int(state.g_prov_target_flag[power_idx, adj])
            if access > -1 and (access > 0 or target != 0):
                state.g_province_score_trial[adj] = 1


def populate_convoy_routes(state: InnerGameState, power_idx: int) -> None:
    """
    Narrow port of ProcessTurn's convoy-chain BFS
    (Source/ProcessTurn.c:1425-1929 - per-trial convoy route table init
    plus the fleet-chain walk that threads armies across water).

    For each army owned by ``power_idx``, enumerates *every* destination
    reachable via a fleet chain (1, 2, or 3 fleets) and records the
    shortest chain for each (src, dst) pair in
    ``state.g_convoy_route[army_src][dst_prov]``.  Armies with no viable
    chain are absent from the outer dict.

    This per-destination keying matches the C layout
    (Source/ProcessTurn.c:1628 etc., stride 0x14 at +0x214): an army
    with two candidate destinations requiring different fleet chains
    gets the right fleets for each.  Previously this was destination-
    blind (one chain per source), which caused the wrong fleets to be
    committed on per-turn re-evaluation.  Fixed 2026-04-18
    (AUDIT_moves_and_messages.md #7).

    Mutates only ``state.g_convoy_route``.
    """
    for src_prov, unit_data in list(state.unit_info.items()):
        if unit_data.get('power') != power_idx:
            continue
        if unit_data.get('type') != 'A':
            continue

        _populate_convoy_routes_for_src(state, src_prov)


def _populate_convoy_routes_for_src(
    state: InnerGameState,
    army_src: int,
    eligible_fleets: Iterable[int] | None = None,
) -> dict[int, tuple[int, ...]]:
    """Replace one army's route table with the current ProcessTurn BFS.

    ProcessTurn resets its five-int route record before constructing each
    unit's candidate tree.  Replacing, rather than merging, the Python entry
    prevents a route from an earlier trial (or from the generation pre-pass)
    surviving after its fleet has acquired an order.
    """
    chains_by_dst = _enumerate_convoy_chains_for_src(
        state, army_src, eligible_fleets=eligible_fleets
    )
    if chains_by_dst:
        state.g_convoy_route[army_src] = {
            dst: {'fleet_count': len(chain), 'fleets': list(chain)}
            for dst, chain in chains_by_dst.items()
        }
    else:
        state.g_convoy_route.pop(army_src, None)
    return chains_by_dst


def _get_convoy_route(state: InnerGameState, src_prov: int, dst_prov: int):
    """
    Public helper used by the MC readers to look up the fleet chain for
    a specific (src, dst) convoy pair.  Returns ``(fleet_count, fleets)``.
    ``fleet_count == 0`` and an empty list mean "no chain registered".

    Tolerates the legacy destination-blind shape
    (``g_convoy_route[src] = {'fleet_count': ..., 'fleets': [...]}``) so
    callers or test fixtures still holding that shape continue to work
    during the migration.  Prefer the new nested shape for fresh writes.
    """
    src_entry = state.g_convoy_route.get(src_prov)
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


def _enumerate_convoy_chains_for_src(
    state: InnerGameState,
    army_src: int,
    eligible_fleets: Iterable[int] | None = None,
) -> dict[int, tuple[int, ...]]:
    """
    Port ProcessTurn.c:1674-1940's source-ordered fleet-chain walk.

    Returns ``{dst_prov: chain}`` where ``dst_prov`` is a non-water,
    non-source landing province and ``chain`` is the first shortest fleet
    tuple (1..3 elements) that convoys ``army_src`` to ``dst_prov``.

    C does not expand a generic graph frontier.  At each depth it walks the
    current ``g_convoy_fleet_candidates`` tree in iterator order; a fleet takes
    the first adjacent route of depth ``n-1`` and then exposes all of its land
    neighbours.  ``eligible_fleets`` preserves that order.  The generation
    pre-pass may omit it, in which case unit insertion order is the best
    deterministic approximation; ProcessTurn always supplies the live tree.

    Direct army destinations already have route depth zero in C and cannot be
    overwritten by convoy propagation.  Occupancy is deliberately irrelevant
    for a landing: C checks the province terrain byte only, so an enemy fleet
    on a coastal land province does not remove that legal attack candidate.
    """
    MAX_CHAIN = 3

    army_power = state.unit_info.get(army_src, {}).get('power')
    if army_power is None:
        return {}

    if eligible_fleets is None:
        ordered_candidates = list(state.unit_info)
    else:
        ordered_candidates = list(eligible_fleets)

    # A std::map/tree cannot expose the same unit twice.  Preserve the first
    # occurrence in case a synthetic fixture supplies duplicates.
    ordered_fleets: list[int] = []
    seen: set[int] = set()
    for prov in ordered_candidates:
        prov = int(prov)
        if prov in seen:
            continue
        seen.add(prov)
        unit = state.unit_info.get(prov, {})
        if (unit.get('power') == army_power
                and unit.get('type') in ('F', 'FLT')
                and prov in state.water_provinces):
            ordered_fleets.append(prov)
    if not ordered_fleets:
        return {}

    direct_or_source = set(_filtered_adj(state, army_src, 'A'))
    direct_or_source.add(army_src)
    route_by_fleet: dict[int, tuple[int, ...]] = {}
    result: dict[int, tuple[int, ...]] = {}

    for depth in range(1, MAX_CHAIN + 1):
        added_this_depth = False
        for fleet in ordered_fleets:
            if fleet in route_by_fleet:
                continue
            fleet_adj = _filtered_adj(state, fleet, 'F')
            parent_route: tuple[int, ...] | None = None
            if depth == 1:
                if army_src in fleet_adj:
                    parent_route = ()
            else:
                for adjacent in fleet_adj:
                    route = route_by_fleet.get(adjacent)
                    if route is not None and len(route) == depth - 1:
                        parent_route = route
                        break
            if parent_route is None:
                continue

            chain = parent_route + (fleet,)
            route_by_fleet[fleet] = chain
            added_this_depth = True
            for adjacent in fleet_adj:
                if (adjacent in state.water_provinces
                        or adjacent in direct_or_source):
                    continue
                result.setdefault(adjacent, chain)
        if not added_this_depth:
            break

    return result


def score_convoy_fleet(state: InnerGameState, prov: int, score: int) -> None:
    """Port of ScoreConvoyFleet (FUN_00419790).

    BST insert into ``g_convoy_fleet_candidates`` keyed by score.  The C
    comparator is ``std::greater<int>``: a larger key descends left, while a
    smaller or equal key descends right.  Iteration from ``head->_Left`` is
    therefore descending, and equal-score nodes retain insertion order.

    Plain ``bisect.insort((score, province))`` was doubly wrong: it put the
    lowest score first and used province as an invented equal-key tiebreaker.
    """
    import bisect
    descending_keys = [-int(existing_score)
                       for existing_score, _ in state.g_convoy_fleet_candidates]
    position = bisect.bisect_right(descending_keys, -int(score))
    state.g_convoy_fleet_candidates.insert(position, (int(score), int(prov)))


def build_convoy_orders(state: InnerGameState, power_idx: int, src_prov: int, dst_prov: int, coast: int = 0) -> None:
    """
    Port of FUN_0044b760 = BuildConvoyOrders.

    Builds the complete CTO + CVY order chain for a convoy attempt. Reads
    g_max_province_score to seed each fleet's score, while the army inherits
    the ordered-set score for the destination province.
    """
    # Validate that populate_convoy_routes() has been called for this power.
    # C builds routes inline; Python pre-computes them via populate_convoy_routes.
    # Fixed 2026-04-23 (audit finding MOV-2): warn if routes are empty.
    if not state.g_convoy_route:
        logger.warning(
            "build_convoy_orders called but g_convoy_route is empty — "
            "populate_convoy_routes() was likely not called for power %d. "
            "Convoy orders will be skipped.", power_idx)

    # ClearConvoyState() — no-op in C (Source/utils/clear.c:2-6); acknowledged.

    fleet_count, route = _get_convoy_route(state, src_prov, dst_prov)
    if fleet_count <= 0:
        return
    if coast == 0:
        coast = _unit_location_token('A')

    # Army setup (CTO)
    state.g_order_table[src_prov, _F_ORDER_TYPE] = _ORDER_CTO
    state.g_order_table[src_prov, _F_DEST_PROV] = dst_prov
    state.g_order_table[src_prov, _F_DEST_COAST] = coast
    state.g_order_table[src_prov, _F_CONVOY_DEPTH] = fleet_count
    
    if len(route) > 0:
        state.g_order_table[src_prov, _F_CONVOY_LEG0] = route[0]
    if len(route) > 1:
        state.g_order_table[src_prov, _F_CONVOY_LEG1] = route[1]
    if len(route) > 2:
        state.g_order_table[src_prov, _F_CONVOY_LEG2] = route[2]
        
    # ConvoyList_Insert(&DAT_00bb65a0, &dst) inserts the key and returns its
    # mapped-value slot.  DAT_00bb65a4 is the same std::map's head pointer,
    # not a second container.  Python retains a list for ordered key walks, so
    # keep it synchronized with the mapping just as BuildOrder_MTO does.
    if dst_prov not in state.g_convoy_dst_list:
        state.g_convoy_dst_list.append(dst_prov)
    state.g_convoy_dst_to_src[dst_prov] = src_prov

    # Mark the DESTINATION province as having an incoming move.
    # C: (&g_ProvinceBaseScore)[(int)army_province * 0x1e] = 1; — the Ghidra
    # local named `army_province` is param_3, which BuildConvoyOrders passes to
    # BuildOrder_CTO(this, src_province, dst_province, ...) as dst_province.
    # Corroborated by DispatchSingleOrder.c (CTO branch) and BuildOrder_MTO.c,
    # which both mark the destination.
    # Fixed 2026-08-12: the 2026-04-23 "MOV-1 fix" moved this to src_prov,
    # inverting the C behaviour.
    state.g_order_table[dst_prov, _F_INCOMING_MOVE] = 1.0

    # Army inherits the destination's score, stored against the destination
    # (C: g_ConvoyChainScore[army_province * 0x1e], where the Ghidra local
    # `army_province` is the destination — see the note above).
    #
    # C (BuildConvoyOrders.c:42-44):
    #     ppiVar4 = OrderedSet_FindOrInsert(this + power*0xc + 0x4000, &dst);
    #     g_ConvoyChainScore[dst * 0x1e] = *ppiVar4;
    # `this + power*0xc + 0x4000` is the per-power province SCORE map — bound
    # here as state.final_score_set — the same set BuildOrder_MTO.c:29 reads
    # for a plain move.
    #
    # Fixed 2026-08-18: this read `get_candidate_score(power, dst, 0)`, which
    # is the BFS ROUND-0 set at `this + power*0x78 + 0x361c` — a different
    # container holding the RAW, UNNORMALIZED seed
    # (attack_count*build_weight + build_order_pending*move_weight), values in
    # the tens or hundreds of thousands.  final_score_set is normalized to
    # roughly 0-1000 by score_order_candidates_all_powers Pass 2.
    #
    # Measured consequence: in an F1902 France position, convoy destination BRE
    # carried convoy-chain score 420000 where the plain-move path gave 954.
    # evaluate_order_score sums this field, so EVERY convoy candidate scored
    # ~591000 against ~3700 for the best hold and ~4800 for the best move —
    # a ~600x thumb on the scale that made all seven bots convoy nearly every
    # turn and made an army abandon a neutral centre it had just captured.
    score = float(state.final_score_set[power_idx, dst_prov])
    state.g_convoy_chain_score[dst_prov] = score
    state.g_order_score_hi[dst_prov] = 0.0


    # Fleet setup (CVY)
    for fleet_i in route:
        # C: g_ConvoyChainScore[fleet] = g_MaxProvinceScore[power*0x100+fleet]
        # — the per-power array, not the 1-D cross-power maximum.
        # ScoreOrderCandidates_AllPowers.c:193-201 stores the maximum across
        # every (province, token) key in this one province-indexed table.  It
        # does not keep a second fleet-only maximum.
        max_score = float(state.g_max_prov_score_per_power[power_idx, fleet_i])
        state.g_convoy_chain_score[fleet_i] = max_score
        state.g_order_score_hi[fleet_i] = 0.0

        state.g_order_table[fleet_i, _F_ORDER_TYPE] = _ORDER_CVY
        # C: (&DAT_00baeda4)[fleet * 0x1e] = param_2 — column 1 holds the
        # convoyed army's province; the CVY serializer reads _F_SECONDARY.
        state.g_order_table[fleet_i, _F_SECONDARY] = src_prov
        state.g_order_table[fleet_i, _F_DEST_PROV] = dst_prov
        state.g_order_table[fleet_i, _F_DEST_COAST] = coast
        # C: (&g_ProvinceBaseScore)[fleet * 0x1e] = 1 — each convoying fleet
        # gets the same incoming-move flag as the army.
        state.g_order_table[fleet_i, _F_INCOMING_MOVE] = 1

        register_convoy_fleet(state, power_idx, fleet_i)

    # 4-iteration MoveCandidate rescoring loop (BuildConvoyOrders.c:97-134).
    # Each pass scans g_convoy_fleet_candidates from the front for the first
    # candidate whose province matches one of the convoy legs; if found it is
    # removed (MoveCandidate = BST erase).  The loop runs exactly 4 times
    # regardless of whether a match is found each pass.
    leg_provs = set(route)
    for _ in range(4):
        for i, (_score, cand_prov) in enumerate(state.g_convoy_fleet_candidates):
            if cand_prov in leg_provs:
                state.g_convoy_fleet_candidates.pop(i)
                break

    assign_support_order(state, power_idx, src_prov, dst_prov, coast, flag=1)
