import bisect

import numpy as np

from .state import InnerGameState

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
        if unit_data['type'] == 'AMY':
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


def build_support_opportunities(state: InnerGameState):
    """
    Port of FUN_004460a0. Identifies which units can support other 
    moves based on exact nested AdjacencyList_FilterByUnitType checks.
    """
    state.g_SupportProposals = []
    state.g_ProximityScore = getattr(state, 'g_ProximityScore', {})
    
    for src_prov in range(256):
        if state.has_unit(src_prov):
            unit_power = state.get_unit_power(src_prov)
            
            # Sub-list 1: Direct Adjacencies
            for adj_prov in state.get_unit_adjacencies(src_prov):
                # Update proximity buffers
                state.g_ProximityScore[src_prov] = state.g_ProximityScore.get(src_prov, 0) + 1
                if state.g_CoverageFlag[unit_power, adj_prov] == 1:
                    state.g_ProximityScore[src_prov] += 2
                    
                # Nested safety check targeting support eligibility (similar to Ghidra)
                is_safe = (state.g_SCOwnership[unit_power, adj_prov] == 1 and state.get_enemy_reach(unit_power, adj_prov) == 0)
                
                if is_safe:
                    # Sub-list 2: Secondary Adjacencies
                    for sup_prov in state.get_unit_adjacencies(adj_prov):
                        if sup_prov != src_prov and state.has_unit(sup_prov):
                            candidate = {
                                'power': unit_power,
                                'mover_prov': src_prov,
                                'target_prov': adj_prov,
                                'supporter_prov': sup_prov,
                                'score': state.g_MaxProvinceScore[adj_prov]
                            }
                            state.g_SupportProposals.append(candidate)

def assign_support_order(
    state: InnerGameState,
    power_idx: int,
    src_prov: int,
    dst_prov: int,
    _coast: int,
    flag: int = 0,      # param_5: 1 when called from BuildConvoyOrders — suppresses build-center commit
) -> None:
    """
    Port of FUN_004412c0 (AssignSupportOrder).
    See docs/funcs/AssignSupportOrder.md for full decompile notes.

    Sections:
      1  Adjacency-confirm gate (g_SupportableFlag + g_UnitPresence + adj walk)
      2  Occupancy check (src empty / own unit / enemy-at-dst)
      3  LAB_00441475: 0.85 score threshold → write g_SupportScoreLo/Hi, g_ConvoyChainScore
      4  LAB_0044150f: build-center support commit (threat gate → g_SupportConfirmed)
      5  Convoy fleet conflict resolution (g_LastMTOInsert single-node check)
      6  Section 3: proximity score update (g_ProximityScore / g_CoverageFlag)
    """
    # ── Section 1 — Adjacency-confirm gate ─────────────────────────────────
    # g_SupportableFlag = DAT_00535ce8 (state.g_EnemyReachScore); {1,0} = src can support
    supportable = int(state.g_EnemyReachScore[power_idx, src_prov])
    # g_UnitPresence[(dst+pow*0x40)*8]: power has a unit at dst_prov
    dst_has_own_unit = (state.unit_info.get(dst_prov, {}).get('power', -1) == power_idx)

    bVar16 = False  # adjacency confirmed
    if supportable == 1 and dst_has_own_unit:
        bVar16 = dst_prov in state.adj_matrix.get(src_prov, [])

    # Gate 2: abort → skip score assignment, fall through to build-center commit
    go_to_score = not ((not bVar16 or supportable != 1) and supportable != 0)

    # ── Section 2 — Occupancy check ────────────────────────────────────────
    if go_to_score:
        src_unit = state.unit_info.get(src_prov)
        if src_unit is not None and src_unit['power'] != power_idx:
            # src occupied by enemy or ally — skip SUP if dst is also own unit
            dst_unit = state.unit_info.get(dst_prov)
            if dst_unit is not None and dst_unit['power'] == power_idx:
                go_to_score = False  # goto LAB_0044150f

    # ── LAB_00441475 — Score threshold and SUP assignment ──────────────────
    if go_to_score:
        # Scores from Albert.FinalScoreSet[power] (this+pow*0xc+0x4000)
        score_dst = float(state.FinalScoreSet[power_idx, dst_prov])
        score_src = float(state.FinalScoreSet[power_idx, src_prov])
        # g_ProvinceBaseScore = DAT_006040e8 (state.g_AttackCount)
        base_score = float(state.g_AttackCount[power_idx, src_prov])

        if score_src * 0.85 < score_dst or base_score > 0:
            # g_SupportScoreLo/Hi → order table fields [18][19]
            state.g_OrderTable[src_prov, 18] = score_src
            state.g_OrderTable[src_prov, 19] = 0.0
            # g_ConvoyChainScore / g_OrderScoreLo → order table [6] (dual-use)
            state.g_ConvoyChainScore[src_prov] = score_src
            state.g_OrderTable[src_prov, 6] = score_src
            # g_OrderScoreHi → order table [7]
            state.g_OrderScoreHi[src_prov] = 0.0
            state.g_OrderTable[src_prov, 7] = 0.0

    # ── LAB_0044150f — Build-center support commit ──────────────────────────
    # g_OrderCommitted2 = DAT_00baeddc (state.g_SupportDemand, order table [15])
    if (int(state.g_SupportDemand[dst_prov]) == 1
            and state.g_BuildOrderPending[power_idx, dst_prov] == 0):

        # g_ThreatLevel (DAT_0058f8e8), g_EnemyPressure (DAT_00520ce8)
        threat   = int(state.g_ThreatLevel[power_idx, dst_prov])
        pressure = int(state.g_EnemyPressure[power_idx, dst_prov])

        if threat != -1 and (
            (threat >= 2 and pressure == 0) or
            (threat >= 3 and pressure == 1)
        ):
            if int(state.g_SupportDemand[src_prov]) != 1:
                # Validate: src adjacent to dst AND src is own SC (gamestate+0x24b4 list)
                src_valid = (
                    dst_prov in state.adj_matrix.get(src_prov, [])
                    and state.g_SCOwnership[power_idx, src_prov] == 1
                )
                if src_valid:
                    sup_confirmed  = int(state.g_OrderTable[dst_prov, 20])
                    # Unassigned sentinel: both fields == 0.0 (C equiv: both == 0xffffffff)
                    score_unset    = (state.g_OrderTable[dst_prov, 18] == 0.0
                                      and state.g_OrderTable[dst_prov, 19] == 0.0)
                    # g_UnitPresence == {0,0}: power has NO unit at dst
                    dst_empty      = (state.unit_info.get(dst_prov, {}).get('power', -1)
                                      != power_idx)

                    if sup_confirmed == 0 and score_unset and dst_empty and flag == 0:
                        state.g_OrderTable[dst_prov, 20] = 1       # g_SupportConfirmed
                        state.g_ConvoySourceProv[dst_prov] = float(src_prov)  # g_SupportTarget

    # ── Convoy fleet conflict resolution ────────────────────────────────────
    # g_LastMTOInsert: (type, province) of cached last insert node, None = set.end()
    if state.g_LastMTOInsert is not None:
        node_type, node_prov = state.g_LastMTOInsert
        if node_type == 2 and int(state.g_OrderTable[node_prov, 20]) == 1:
            state.g_OrderTable[node_prov, 20] = 0
            state.g_ConvoySourceProv[node_prov] = float(0xffffffff)  # g_SupportTarget = unset

    # ── Section 3 — Proximity score update ──────────────────────────────────
    if dst_has_own_unit:
        w_unit = state.unit_info.get(dst_prov)
        if w_unit is not None:
            w_power = w_unit['power']
            for a in state.adj_matrix.get(dst_prov, []):
                if a != src_prov:
                    state.g_ProximityScore[w_power, a] += 1
                if a == src_prov and int(state.g_CoverageFlag[w_power, src_prov]) == 1:
                    state.g_ProximityScore[w_power, src_prov] += 2

# ── g_OrderTable field indices (subset needed here; full list in monte_carlo.py) ─
_F_ORDER_TYPE    =  0   # 1=HLD 2=MTO 3=SUP_HLD 4=SUP_MTO 5=CVY 6=CTO
_F_DEST_PROV     =  2   # destination province (MTO/CTO)
_F_INCOMING_MOVE = 13   # 1 = province has incoming MTO/CTO (DAT_00baedd4 = g_ProvinceBaseScore)
_F_ORDER_ASGN    = 20   # 1 = support order committed

_ORDER_MTO = 2
_ORDER_CVY = 5
_ORDER_CTO = 6

_MAX_CONVOY_CHAIN_DEPTH = 10  # 0xb bound from research.md §EnumerateConvoyReach


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
        if unit_type != 'AMY':
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
                if state.get_unit_type(adj) != 'FLT':
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
                        reach_candidates.append((adj, 'AMY', fc_wave))

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
                            reach_candidates.append((adj, 'AMY', wave + 1))
            local_1a8 += 1

        # Commit convoy reach counts for all discovered destinations
        for prov in free_destinations | army_reach:
            state.g_ConvoyReachCount[power_idx, prov] += 1


def build_support_proposals(state: 'InnerGameState', power_idx: int) -> None:
    """
    Port of FUN_0043e370 = BuildSupportProposals.

    For each unit belonging to *power_idx*, determines the unit's target province
    (dest) and counts threatening powers via g_CoverageFlag / g_ProximityScore.

      0 threats  — no action.
      1 threat + convoy order + press off
                 — alliance handshake: set g_XdoPressSent for units adjacent to
                   dest whose power != power_idx; no XDO content emitted.
      2+ threats — outer loop over each threatening power (local_1ec).
                   For each threatening power whose score exceeds the unit's base
                   score, determine priority then scan all units for candidate
                   supporters, filtering by:
                     1. unit2.power != power_idx
                     2. unit2.power != threatening power (local_1ec)
                     3. unit2.power != g_AllyDesignation_B[dest]
                     4. unit2.power != g_AllyDesignation_A[dest]
                     5. g_OrderTable[unit2_prov, _F_INCOMING_MOVE] == 0
                   If unit2 can reach dest, emit XDO SUP proposal (deduped via
                   g_ProposalHistory; priority added to existing entry if seen).

    Globals written:
      g_ProposalHistory — map of key → priority accumulator
      g_XdoPressSent[power_idx, unit2_power] — 1 when press flagged
      g_XdoPressProposals — list of proposal dicts (consumed by ComputePress)
    """
    ot = state.g_OrderTable
    num_powers = 7

    for own_prov, info in list(state.unit_info.items()):
        if info['power'] != power_idx:
            continue

        order_type = int(ot[own_prov, _F_ORDER_TYPE])
        if order_type == 0:
            continue

        # dest: where the unit is headed (or its current province for non-moves)
        # local_1e5 in decompile: 1 if MTO/CTO (used as base_score adjustment)
        if order_type in (_ORDER_MTO, _ORDER_CTO):
            dest = int(ot[own_prov, _F_DEST_PROV])
            is_move = 1
        else:
            dest = own_prov
            is_move = 0

        # base score for this province (g_ProvinceBaseScore = g_OrderTable field 13)
        base_score = int(ot[dest, _F_INCOMING_MOVE])

        # ── Count threatening powers ──────────────────────────────────────────
        # g_CoverageFlag[other, dest] = DAT_00ba4370[dest + other*0x100]
        # g_ProximityScore[other, dest] = DAT_00ba4370[dest+0x1500 + other*0x100]
        threat_count = 0
        max_threat = 0
        for other in range(num_powers):
            if other == power_idx:
                continue
            coverage = int(state.g_CoverageFlag[other, dest])
            proximity = int(state.g_ProximityScore[other, dest])
            score = coverage - (proximity if proximity > 0 else 0)
            if score > max_threat:
                max_threat = score
            if score > 0:
                threat_count += 1

        if threat_count < 2:
            # 0 or 1 threat: only act for convoy order with press off
            # decompile line 169: order_type check uses own_prov's field (iVar1+0x20), i.e. _ORDER_CVY
            if (threat_count == 1
                    and int(ot[own_prov, _F_ORDER_TYPE]) == _ORDER_CVY
                    and state.g_PressFlag == 0):
                for unit2_prov, u2_info in state.unit_info.items():
                    if u2_info['power'] == power_idx:
                        continue
                    if dest in state.get_unit_adjacencies(unit2_prov):
                        state.g_XdoPressSent[power_idx, u2_info['power']] = 1
        else:
            # 2+ threats — outer loop over all powers as threatening-power candidates
            # (local_1ec in decompile, iterates 0..numPowers with local_1c4 striding
            #  through g_ProximityScore columns)
            for threat_power in range(num_powers):
                if threat_power == power_idx:
                    continue

                # Re-score this specific threatening power (same formula as threat loop)
                t_coverage  = int(state.g_CoverageFlag[threat_power, dest])
                t_proximity = int(state.g_ProximityScore[threat_power, dest])
                t_score = t_coverage - (t_proximity if t_proximity > 0 else 0)

                # Decompile line 290-291: skip if score <= 0 OR score <= base_score - is_move
                if t_score <= 0:
                    continue
                if t_score <= base_score - is_move:
                    continue

                # Priority logic (decompile lines 292-303):
                # trust = g_AllyTrustScore[power_idx * 0x15 + threat_power] (lo-word, int)
                trust = int(state.g_AllyTrustScore[power_idx, threat_power])
                if trust < 0xf:
                    # priority=8 when: g_AllyDesignation_B[dest] == power_idx
                    #                  AND dest == own_prov AND base_score < t_score
                    if (int(state.g_AllyDesignation_B[dest]) == power_idx
                            and dest == own_prov
                            and base_score < t_score):
                        priority = 8
                    else:
                        priority = 4
                else:
                    priority = 1

                # Inner loop: find supporter candidates
                for unit2_prov, u2_info in list(state.unit_info.items()):
                    unit2_power = u2_info['power']

                    # Filter 1: not own power
                    if unit2_power == power_idx:
                        continue
                    # Filter 2: not the threatening power
                    if unit2_power == threat_power:
                        continue
                    # Filter 3: not ally-B designated power for dest
                    if unit2_power == int(state.g_AllyDesignation_B[dest]):
                        continue
                    # Filter 4: not ally-A designated power for dest
                    if unit2_power == int(state.g_AllyDesignation_A[dest]):
                        continue
                    # Filter 5: unit2's province must have no incoming move
                    # (g_ProvinceBaseScore[unit2_prov * 0x1e] == 0, i.e. _F_INCOMING_MOVE)
                    if int(ot[unit2_prov, _F_INCOMING_MOVE]) != 0:
                        continue

                    if dest not in state.get_unit_adjacencies(unit2_prov):
                        continue

                    key = (unit2_prov * 1000 + own_prov) * 1000 + dest
                    if key in state.g_ProposalHistory:
                        # Already proposed: accumulate priority into existing entry
                        # (decompile line 388-389: *(local_1bc + 0x24) += local_1c8)
                        for prop in state.g_XdoPressProposals:
                            if prop.get('key') == key:
                                prop['priority'] += priority
                                break
                        continue

                    state.g_ProposalHistory.add(key)
                    state.g_XdoPressSent[power_idx, unit2_power] = 1
                    state.g_XdoPressProposals.append({
                        'type':            'XDO_SUP',
                        'key':             key,
                        'supporter_prov':  unit2_prov,
                        'supporter_power': unit2_power,
                        'mover_prov':      own_prov,
                        'dest':            dest,
                        'priority':        priority,
                        'from_power':      power_idx,
                        'to_power':        unit2_power,
                    })

def build_convoy_orders(state: InnerGameState, power_idx: int, src_prov: int, dst_prov: int) -> None:
    """
    Port of FUN_0044b760 = BuildConvoyOrders.
    
    Builds the complete CTO + CVY order chain for a convoy attempt. Reads
    g_MaxProvinceScore to seed each fleet's score, while the army inherits
    the ordered-set score for the destination province.
    """
    fleet_count = state.g_ConvoyRoute.get(src_prov, {}).get('fleet_count', 0)
    if fleet_count <= 0:
        return
        
    route = state.g_ConvoyRoute[src_prov].get('fleets', [])
    
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
        
        if not hasattr(state, 'g_ConvoyFleetList'):
            state.g_ConvoyFleetList = []
        state.g_ConvoyFleetList.append((power_idx, fleet_i))
        
        assign_support_order(state, power_idx, src_prov, dst_prov, 0, flag=1)
