"""Draw-vote, move-history post-processing, and press-pressure computation.

Split from heuristics.py during the 2026-04 refactor.

- ``compute_draw_vote``    — Nash-stability check for the DRW vote
- ``post_process_orders``  — decay + update move-history matrix
- ``compute_press``        — per-power adjacency pressure matrix

Stab/deviate detection lives in bot.strategy (_stabbed, _deviate_move).

Module-level deps: ``numpy``, ``..state.InnerGameState``.
"""

from collections import deque

import numpy as np

from ..state import InnerGameState


def compute_draw_vote(state: InnerGameState, friendly_powers: set) -> bool:
    """
    Port of ComputeDrawVote (FUN_004440e0).

    Nash-stability check. Returns True only when the powers outside the
    proposed draw set have no unresolved frontier choices and the draw-set
    powers cannot reach an outside-controlled supply centre.

    Called via the FUN_0044c9d0 wrapper which builds `friendly_powers`:
        own_power ∪ { p : curr_sc_cnt[p] > 0 AND trust(own,p) > 1 }
    param_1 in the C = std::map<power_id, sentinel> (the friendly-powers set).
    Step 2 does Map_Find(param_1, unit+0x18) where unit+0x18 = power field
    (NOT province — doc comment was wrong; confirmed by iVar6+0x18 = power
    throughout _build_gof_seq and _move_analysis).

    Internally mirrors local_108 (province metadata map) and local_e4 (reach map).
    """
    if not friendly_powers:
        return False

    # --- Step 1: Province metadata init (local_108) + reach-map init (local_e4) ---
    # local_108[prov]: [flag_a, supporter, flag_b, committed_votes,
    #                   free_candidates, no_order, _, _, _, resolved, ..., fully_committed]
    def _new_meta():
        return {
            'flag_a': 0,          # [0]  set when entry is pre-resolved (free_candidates<=1)
            'supporter': -1,      # [1]  province ID of assigned supporter (-1 = none)
            'committed': 0,       # [2]  committed flag (no/one free target)
            'committed_votes': 0, # [3]  count of committed backers
            'free_candidates': 0, # [4]  total free-move candidate count
            'no_order': 0,        # [5]  1 = unit's power NOT in friendly_powers
            'resolved': 0,        # +9   forced-commitment resolved flag
            'fully_committed': 0, # +0x19 fully-committed flag (required for draw)
        }

    province_meta: dict = {}

    # local_e4 is keyed by the complete adjacency key, not just the province:
    #     (province, AMY) or (province, FLT/coast).
    # Keeping the unit/coast component matters here.  A fleet cannot flood
    # through an inland province, an army cannot cross a sea, and a fleet
    # arriving at one coast of SPA/STP/BUL must continue from that coast.
    reachable_states: set[tuple[int, str, str]] = set()

    def _normalise_unit(info: dict) -> tuple[str, str]:
        unit_type = str(info.get('type', 'A')).upper()
        unit_type = 'F' if unit_type in ('F', 'FLT') else 'A'
        coast = str(info.get('coast', '') or '').upper()
        if coast and not coast.startswith('/'):
            coast = '/' + coast
        return unit_type, coast

    def _typed_adjacencies(
        src: int, unit_type: str, coast: str = '',
    ) -> list[tuple[int, str, str]]:
        return state.get_reachable_edges(src, unit_type, coast)

    def _is_non_water(province: int) -> bool:
        # Board byte +4 is zero for water and one for every land/coast
        # province.  The source adds an AMY reach key whenever that byte is 1.
        return province not in getattr(state, 'water_provinces', frozenset())

    for prov in state.adj_matrix:
        province_meta.setdefault(prov, _new_meta())
        for adj in state.adj_matrix.get(prov, []):
            province_meta.setdefault(adj, _new_meta())

    # --- Step 2: Unit-to-power-set correlation ---
    # C: Map_Find(param_1, unit+0x18) where unit+0x18 = unit.power (power field).
    # If unit.power NOT in friendly_powers → mark province as no_order=1 (non-friendly).
    # If unit.power IN friendly_powers → seed its exact unit/coast reach key.
    for prov, unit_data in state.unit_info.items():
        province_meta.setdefault(prov, _new_meta())
        unit_power = unit_data.get('power', -1)
        if unit_power not in friendly_powers:
            province_meta[prov]['no_order'] = 1   # non-friendly unit
        else:
            unit_type, coast = _normalise_unit(unit_data)
            reachable_states.add((prov, unit_type, coast))
            if _is_non_water(prov):
                reachable_states.add((prov, 'A', ''))

    # --- Step 3: Adjacency flood-fill from friendly unit provinces ---
    # ComputeDrawVote.c:220-282 expands a live reach key when the adjacent
    # province's large-record flag at +0x14 is zero. That flag is set above
    # for a non-friendly unit, so empty/friendly provinces are passable and
    # non-friendly occupied provinces block the flood. The old port had this
    # test backwards and expanded only into hostile units.
    queue = deque(sorted(reachable_states))
    while queue:
        prov, unit_type, coast = queue.popleft()
        for next_state in _typed_adjacencies(prov, unit_type, coast):
            adj = next_state[0]
            if province_meta[adj]['no_order'] != 0:
                continue  # a non-friendly unit blocks this province
            additions = [next_state]
            if _is_non_water(adj):
                additions.append((adj, 'A', ''))
            for addition in additions:
                if addition not in reachable_states:
                    reachable_states.add(addition)
                    queue.append(addition)

    # --- Step 4: reachable foreign-controller supply-centre check ---
    # C:285-316 walks the reach-key map, reads province byte +3 and the
    # category-0x41 controller token at +0x20, and rejects the draw only when
    # a reachable supply centre is controlled by a power outside param_1.
    # It does not reject merely because some non-friendly unit exists.
    vote = True
    for prov in {entry[0] for entry in reachable_states}:
        if (prov in state.sc_provinces
                and int(state.g_sc_owner[prov]) not in friendly_powers):
            vote = False
            break

    if not vote:
        return False

    # --- Supporter assignment pre-pass ---
    # C walks every *reachable typed key*, gathers adjacent non-member units
    # into a per-source set, then increments each such unit once for that
    # source province.  The old port walked non-member units and incremented
    # their empty/friendly neighbours, reversing both ends of the relation.
    frontier_by_source: dict[int, set[int]] = {}
    for prov, unit_type, coast in sorted(reachable_states):
        frontier = frontier_by_source.setdefault(prov, set())
        for adj, _dst_type, _dst_coast in _typed_adjacencies(
            prov, unit_type, coast,
        ):
            if province_meta[adj]['no_order'] == 1:
                frontier.add(adj)
                province_meta[adj]['supporter'] = prov
    for frontier in frontier_by_source.values():
        for adj in frontier:
            province_meta[adj]['free_candidates'] += 1

    # Pre-resolution applies to units outside the proposed draw set.  Those
    # with zero/one reachable frontier square are already forced; units with
    # multiple choices lose the single-supporter shortcut.
    for prov, unit_data in state.unit_info.items():
        if unit_data.get('power', -1) in friendly_powers:
            continue
        meta = province_meta.get(prov, _new_meta())
        if meta['free_candidates'] > 1:
            meta['supporter'] = -1   # reset supporter; will be handled by sub-pass B
        else:
            meta['flag_a'] = 1
            meta['resolved'] = 1

    # --- Step 5: Iterative resolution (outer loop runs while progress is made) ---
    for _outer in range(10):
        if not vote:
            break

        # Sub-pass A: mark committed units (entries with flag_a=1, committed=0)
        for prov, unit_data in state.unit_info.items():
            if unit_data.get('power', -1) in friendly_powers:
                continue
            meta = province_meta[prov]
            if meta.get('flag_a', 0) != 1 or meta.get('committed', 0) == 1:
                continue
            supporter = meta.get('supporter', -1)
            free_count = 0
            free_target = -1
            unit_type, coast = _normalise_unit(unit_data)
            for adj, _dst_type, _dst_coast in _typed_adjacencies(
                prov, unit_type, coast,
            ):
                adj_meta = province_meta.get(adj, {})
                if adj_meta.get('no_order', 0) != 1:
                    continue
                if adj_meta.get('resolved', 0) != 0:
                    continue
                if adj == free_target:
                    continue   # dedup
                via_supporter = True
                if supporter != -1:
                    via_supporter = state.can_reach(supporter, adj)
                if via_supporter:
                    free_count += 1
                    free_target = adj
            if free_count == 0:
                meta['committed'] = 1
            elif free_count == 1:
                meta['committed'] = 1
                province_meta.setdefault(free_target, _new_meta())
                province_meta[free_target]['committed_votes'] += 1
            else:
                vote = False

        # Check fully-committed after sub-pass A
        for meta in province_meta.values():
            if meta.get('resolved', 0) == 1:
                total = meta.get('free_candidates', 0)
                backed = meta.get('committed_votes', 0)
                if total - 1 <= backed:
                    meta['fully_committed'] = 1

        if not vote:
            break

        # Sub-pass B: resolve remaining via IsLegalMove (can_reach)
        progress = False
        for prov, unit_data in state.unit_info.items():
            if unit_data.get('power', -1) in friendly_powers:
                continue
            meta = province_meta[prov]
            if meta.get('resolved', 0) != 0:
                continue
            supporter = meta.get('supporter', -1)
            legal_count = 0
            committed_targets: list = []
            unit_type, coast = _normalise_unit(unit_data)
            for adj, _dst_type, _dst_coast in _typed_adjacencies(
                prov, unit_type, coast,
            ):
                adj_meta = province_meta.get(adj, {})
                if adj_meta.get('no_order', 0) != 1:
                    continue
                if adj_meta.get('flag_a', 0) != 1:
                    continue
                if adj_meta.get('committed', 0) == 1:
                    continue
                if supporter == -1:
                    legal = state.can_reach(prov, adj)
                else:
                    legal = (state.can_reach(supporter, adj)
                             and state.can_reach(prov, adj))
                if legal:
                    legal_count += 1
                    committed_targets.append(adj)

            total = meta.get('free_candidates', 0)
            committed_votes = meta.get('committed_votes', 0)
            remaining = total - legal_count - committed_votes
            if remaining < 2:
                if remaining == 1:
                    progress = True
                    meta['resolved'] = 1
                    for t in committed_targets:
                        province_meta.setdefault(t, _new_meta())['committed'] = 1
            else:
                vote = False

        # Re-check fully-committed after sub-pass B
        for meta in province_meta.values():
            if meta.get('resolved', 0) == 1:
                total = meta.get('free_candidates', 0)
                backed = meta.get('committed_votes', 0)
                if total - 1 <= backed:
                    meta['fully_committed'] = 1

        if not progress:
            break

    # --- Step 6: Final validation ---
    if vote:
        for meta in province_meta.values():
            if meta.get('resolved', 0) == 1 and meta.get('fully_committed', 0) == 0:
                vote = False
                break

    return vote

# ── PostProcessOrders ─────────────────────────────────────────────────────────

def post_process_orders(state: InnerGameState) -> None:
    """
    Port of PostProcessOrders (FUN_00411120).

    Updates g_move_history_matrix from the submitted-order history list.
    Two passes:
      Pass 1 — decay all entries by 3 (floor 0)
      Pass 2 — update from submitted-order history:
                 flag_A=1,flag_B=0 → successful support  (+10, cap 201)
                 flag_B=1          → bounced src row → zero
                 flag_C=1          → full conflict → zero row+col

    Research.md §2039.
    """
    num_powers = 7
    num_provinces = 256

    # Pass 1 — uniform decay
    state.g_move_history_matrix -= 3
    np.clip(state.g_move_history_matrix, 0, None, out=state.g_move_history_matrix)

    # Pass 2 — update from order history list
    for rec in getattr(state, 'g_order_hist_list', []):
        power    = int(rec.get('power', -1))
        src_prov = int(rec.get('src_province', -1))
        dst_prov = int(rec.get('dst_province', -1))
        flag_a   = int(rec.get('flag_a', 0))   # support order
        flag_b   = int(rec.get('flag_b', 0))   # mover bounced / support cut
        flag_c   = int(rec.get('flag_c', 0))   # full conflict / dislodgement

        if not (0 <= power < num_powers): continue
        if not (0 <= src_prov < num_provinces): continue
        if not (0 <= dst_prov < num_provinces): continue

        # Check 1 (C++ order): flag_a=1 and flag_b=0 → successful support → +10
        # C checks `if (val < 0xc9)` (< 201) then adds 10 unconditionally,
        # allowing values up to 210.  No secondary cap.
        if flag_a == 1 and flag_b == 0:
            cur = int(state.g_move_history_matrix[power, src_prov, dst_prov])
            if cur < 201:
                state.g_move_history_matrix[power, src_prov, dst_prov] = cur + 10

        # Check 2: flag_c=1 → full conflict → zero src row, dst row, dst column (independent if)
        if flag_c == 1:
            state.g_move_history_matrix[power, src_prov, :] = 0
            state.g_move_history_matrix[power, dst_prov, :] = 0
            state.g_move_history_matrix[power, :, dst_prov] = 0

        # Check 3: flag_b=1 → unit disrupted at src → zero src row (independent if)
        if flag_b == 1:
            state.g_move_history_matrix[power, src_prov, :] = 0


# ── Self-proposal generator ──────────────────────────────────────────────────

def _legacy_generate_self_proposals(state: InnerGameState, own_power: int,
                            *, skip_power: int = -1) -> int:
    """Deprecated synthetic proposal generator, retained for archaeology.

    This is intentionally private and unused. GenerateOrders never inserts
    these proposals in the C binary; proposal trees are populated only from
    actual press before ProcessTurn performs its ordinary adjacency walk.

    Mirrors the C bot's SerializeOrders → RegisterProposalOrders flow:
    for each unit, the best-scored reachable adjacent province becomes
    an MTO proposal in g_general_orders.  The scoring source is
    g_candidate_scores (heat-BFS output from GenerateOrders), which is
    the same data the C bot serializes after ApplyInfluenceScores.

    For own_power, proposals also go into g_alliance_orders (mirrors
    the trust gate in score_order_candidates_from_broadcast).

    When *skip_power* >= 0, that power is excluded from proposal
    generation so its units enter MC Phase 2 (adjacency-walk
    randomisation) instead of receiving pre-assigned orders.

    Returns the number of proposals inserted.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    num_powers = 7
    inserted = 0

    if not hasattr(state, 'g_general_orders'):
        state.g_general_orders = {}
    if not hasattr(state, 'g_alliance_orders'):
        state.g_alliance_orders = {}
    if not state._id_to_prov:
        state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}

    sc_set: set = set(getattr(state, 'sc_provinces', set()))

    for power in range(num_powers):
        if power == skip_power:
            continue
        # Phase 1: Score all candidate destinations per unit using
        # g_candidate_scores (the BFS heat diffusion output from
        # GenerateOrders, matching what C serializes)
        unit_candidates: list = []
        for prov, info in list(state.unit_info.items()):
            if info['power'] != power:
                continue
            unit_type = info.get('type', 'A')

            candidates: list = []
            if unit_type in ('A', 'AMY'):
                raw_adj = state.get_adjacent_provinces(prov)
                adj_list = [a for a in raw_adj if a not in state.water_provinces]
            elif unit_type in ('F', 'FLT'):
                adj_list = list(state.fleet_adj_matrix.get(prov, []))
                if not adj_list:
                    _coast = info.get('coast', '')
                    if _coast:
                        adj_list = list(
                            getattr(state, 'fleet_coast_adj', {}).get(
                                (prov, '/' + _coast.upper()), []))
            else:
                adj_list = list(state.get_adjacent_provinces(prov))

            for adj in adj_list:
                # Primary: final_score_set (normalized strategic value from
                # score_order_candidates_all_powers).  Using the same scores
                # that drive the MC trial gives more faithful enemy predictions
                # than the raw BFS heat + giant SC bonus, which overwrote the
                # BFS signal and caused every enemy to always target the nearest
                # unowned SC regardless of actual strategic context.
                score = state.fss(power, adj, unit_type)

                # Fallback when final_score_set is zero (province outside BFS
                # coverage): revert to BFS heat + SC bonus so we always have
                # some non-zero ranking to work with.
                if score == 0.0:
                    score = float(state.g_candidate_scores[power, adj])
                    if adj in sc_set:
                        adj_owner = int(state.g_sc_owner[adj])
                        if adj_owner < 0:
                            score += 500.0
                        elif adj_owner != power:
                            score += 300.0
                    score += float(state.g_max_province_score[adj]) * 0.1
                    if score == 0.0:
                        score += float(state.g_heat_movement[power, adj]) * 0.01
                        if score == 0.0:
                            score = 0.001

                candidates.append((score, adj))

            if candidates:
                candidates.sort(reverse=True)
                unit_candidates.append((prov, unit_type, candidates))

        # Phase 2: Greedy collision-free assignment (highest-scored first)
        claimed_dests: set = set()
        assignments: list = []

        pq = []
        for prov, unit_type, cands in unit_candidates:
            if cands:
                pq.append((cands[0][0], prov, unit_type, cands, 0))
        pq.sort(key=lambda x: x[0], reverse=True)

        assigned_units: set = set()
        while pq:
            best_score, prov, unit_type, cands, idx = pq.pop(0)
            if prov in assigned_units:
                continue
            chosen = None
            for i in range(idx, len(cands)):
                s, adj = cands[i]
                if adj not in claimed_dests:
                    chosen = (s, adj, i)
                    break
            if chosen is None:
                continue
            s, adj, ci = chosen
            claimed_dests.add(adj)
            assigned_units.add(prov)
            assignments.append((prov, unit_type, adj))

        # Phase 3: Emit proposals
        for prov, unit_type, best_adj in assignments:
            prov_name = state._id_to_prov.get(prov, str(prov))
            adj_name = state._id_to_prov.get(best_adj, str(best_adj))
            order_seq = {
                'type': 'MTO',
                'unit': f"{unit_type} {prov_name}",
                'target': adj_name,
            }

            state.g_general_orders.setdefault(power, []).append(order_seq)
            inserted += 1

            if power == own_power:
                state.g_alliance_orders.setdefault(power, []).append(order_seq)
                inserted += 1

    if inserted:
        _log.debug(
            "generate_self_proposals: inserted %d proposals "
            "(general: %s, alliance: %s)",
            inserted,
            sorted(state.g_general_orders.keys()),
            sorted(state.g_alliance_orders.keys()),
        )
    return inserted


# ── ComputePress ─────────────────────────────────────────────────────────────

def compute_press(state: InnerGameState, own_power: int = 0) -> None:  # noqa: ARG001
    """
    Port of ComputePress (FUN_004401f0).

    Builds per-power adjacency-pressure matrix. For each unit of any power,
    calls adjacency lookup, then for each adjacent uncontrolled supply centre
    (invalid/neutral controller power token) sets
    g_press_matrix[power][province] = 1 and increments g_press_count[power].

    Result: g_press_matrix (bool 2D, stride 0x100) + g_press_count (count vec).

    Research.md §1295 / §2568 note.
    """
    state.g_press_matrix.fill(0)
    state.g_press_count.fill(0)

    for prov, info in state.unit_info.items():
        power = info['power']
        unit_type = info.get('type', 'A')
        unit_coast = str(info.get('coast', '') or '')

        # C uses AdjacencyList_FilterByUnitType with the complete unit token.
        # In particular, a fleet on STP/NC, SPA/NC, or BUL/EC must not see
        # destinations reachable only from the province's other coast.
        adj_list = [
            adj for adj in state.get_unit_adjacencies(prov)
            if state.can_reach_by_type(prov, adj, unit_type, unit_coast)
        ]

        for adj in adj_list:
            if adj not in state.sc_provinces:
                continue
            # Province +0x20 is the SC controller's category-0x41 power token.
            adj_pow = int(state.g_sc_owner[adj])
            if not 0 <= adj_pow < int(state.g_num_powers):
                if state.g_press_matrix[power, adj] == 0:
                    state.g_press_matrix[power, adj] = 1
                    state.g_press_count[power] += 1
