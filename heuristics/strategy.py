"""Draw-vote, stab/hostility detection, move-history post-processing,
self-proposal generation, and press-pressure computation.

Split from heuristics.py during the 2026-04 refactor.

- ``compute_draw_vote``          — Nash-stability check for the DRW vote
- ``detect_stabs_and_hostility`` — update AllyMatrix/TrustScore from board outcomes
- ``post_process_orders``        — decay + update move-history matrix
- ``generate_self_proposals``    — seed g_GeneralOrders when no press arrives
- ``compute_press``              — per-power adjacency pressure matrix

Module-level deps: ``numpy``, ``..state.InnerGameState``.
"""

import numpy as np

from ..state import InnerGameState


def compute_draw_vote(state: InnerGameState, friendly_powers: set) -> bool:
    """
    Port of ComputeDrawVote (FUN_004440e0).

    Nash-stability check. Returns True (vote draw) only if all friendly-power
    units are fully committed with no profitable unilateral deviations.

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
    reach_map: dict = {}   # local_e4: province → bool (reachable without conflict)

    for prov in state.adj_matrix:
        province_meta.setdefault(prov, _new_meta())
        for adj in state.adj_matrix.get(prov, []):
            reach_map.setdefault(adj, False)

    # --- Step 2: Unit-to-power-set correlation ---
    # C: Map_Find(param_1, unit+0x18) where unit+0x18 = unit.power (power field).
    # If unit.power NOT in friendly_powers → mark province as no_order=1 (non-friendly).
    # If unit.power IN friendly_powers → mark province as reachable (local_e4=1).
    for prov, unit_data in state.unit_info.items():
        province_meta.setdefault(prov, _new_meta())
        unit_power = unit_data.get('power', -1)
        if unit_power not in friendly_powers:
            province_meta[prov]['no_order'] = 1   # non-friendly unit
        else:
            reach_map[prov] = True                # friendly unit: province is reachable

    # --- Step 3: Adjacency flood-fill from submitted-order provinces ---
    # Expand reach to adjacent provinces that have no submitted order.
    changed = True
    while changed:
        changed = False
        for prov, reachable in list(reach_map.items()):
            if not reachable:
                continue
            if province_meta.get(prov, {}).get('no_order', 0):
                continue  # unsubmitted province is not a seed
            for adj in state.adj_matrix.get(prov, []):
                adj_meta = province_meta.get(adj, {})
                if adj_meta.get('no_order', 0) == 0:
                    continue  # adj already has submitted order
                if not reach_map.get(adj, False):
                    reach_map[adj] = True
                    changed = True

    # --- Step 4: First draw-vote candidate check ---
    # C step 4: if unit.power NOT in friendly_powers and no_order==1 → don't draw.
    # "power_lookup NOT in param_1" = unit.power not in friendly_powers.
    vote = True
    for prov in list(state.unit_info.keys()):
        meta = province_meta.get(prov, {})
        unit_power = state.unit_info.get(prov, {}).get('power', -1)
        if unit_power not in friendly_powers and meta.get('no_order', 0) == 1:
            vote = False

    if not vote:
        return False

    # --- Supporter assignment pre-pass ---
    # For each non-friendly-power province (no_order=1), count free-move candidates
    # among its neighbours and assign itself as supporter to those neighbours.
    prev_no_order_prov = -1
    for prov in sorted(province_meta.keys()):
        meta = province_meta.get(prov, {})
        if meta.get('no_order', 0) != 1:
            continue
        if prov != prev_no_order_prov:
            for adj in state.adj_matrix.get(prov, []):
                province_meta.setdefault(adj, _new_meta())
                province_meta[adj]['free_candidates'] += 1
            prev_no_order_prov = prov
        for adj in state.adj_matrix.get(prov, []):
            adj_meta = province_meta.get(adj, {})
            if adj_meta.get('no_order', 0) == 1:
                adj_meta['supporter'] = prov

    # Pre-resolution: for friendly-power units with free_candidates <= 1, mark resolved.
    for prov, unit_data in state.unit_info.items():
        if unit_data.get('power', -1) not in friendly_powers:
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
        for prov, meta in province_meta.items():
            if meta.get('flag_a', 0) != 1 or meta.get('committed', 0) == 1:
                continue
            supporter = meta.get('supporter', -1)
            free_count = 0
            free_target = -1
            for adj in state.adj_matrix.get(prov, []):
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
        for prov, meta in province_meta.items():
            if meta.get('resolved', 0) != 0:
                continue
            supporter = meta.get('supporter', -1)
            legal_count = 0
            committed_targets: list = []
            for adj in state.adj_matrix.get(prov, []):
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

def detect_stabs_and_hostility(state: InnerGameState, power_idx: int):
    """
    Evaluates phase changes mapping DEVIATE_MOVE and STABBED states
    functionally altering Trust and Alliance networks dynamically.
    """
    for prov in range(256):
        owner_id = -1
        occupier_id = state.get_unit_power(prov)
        
        # Scan ownership arrays
        for p in range(7):
            if state.g_SCOwnership[p, prov] == 1:
                owner_id = p
                break
                
        # Condition A: We own the SC, but someone else occupies it
        if owner_id == power_idx and occupier_id != -1 and occupier_id != power_idx:
            # If the occupier was formally bound in our trust matrix...
            if state.g_AllyMatrix[power_idx, occupier_id] == 1:
                # STABBED scenario mapping
                state.g_AllyMatrix[power_idx, occupier_id] = 0
                state.g_AllyTrustScore[power_idx, occupier_id] = 0.0
                state.g_DeceitLevel += 1
                
                # Escalate positional threat score heavily
                state.g_ThreatLevel[occupier_id, prov] = int(state.g_ThreatLevel[occupier_id, prov]) + 10
                
        # Condition B: We attacked an ally's SC
        elif owner_id != -1 and owner_id != power_idx and occupier_id == power_idx:
            # We breached bounds
            if state.g_AllyMatrix[power_idx, owner_id] == 1:
                # DEVIATE_MOVE mapping
                state.g_AllyMatrix[power_idx, owner_id] = 0
                # Our trust crashes as retaliation is mapped
                state.g_AllyTrustScore[power_idx, owner_id] = max(0, state.g_AllyTrustScore[power_idx, owner_id] / 2.0)


    # NOTE 2026-04-14: C CAL_BOARD does not call UpdateRelationHistory.
    # That call was spurious — removed. UpdateRelationHistory is invoked
    # from FRIENDLY (communications.friendly Phase 2) and HOSTILITY
    # (bot._hostility Block 6, pending wire-in).


# ── PostProcessOrders ─────────────────────────────────────────────────────────

def post_process_orders(state: InnerGameState) -> None:
    """
    Port of PostProcessOrders (FUN_00411120).

    Updates g_MoveHistoryMatrix from the submitted-order history list.
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
    state.g_MoveHistoryMatrix -= 3
    np.clip(state.g_MoveHistoryMatrix, 0, None, out=state.g_MoveHistoryMatrix)

    # Pass 2 — update from order history list
    for rec in getattr(state, 'g_OrderHistList', []):
        power    = int(rec.get('power', -1))
        src_prov = int(rec.get('src_prov', -1))
        dst_prov = int(rec.get('dst_prov', -1))
        flag_a   = int(rec.get('flag_a', 0))   # support survived
        flag_b   = int(rec.get('flag_b', 0))   # mover bounced / support cut
        flag_c   = int(rec.get('flag_c', 0))   # full conflict / dislodgement

        if not (0 <= power < num_powers): continue
        if not (0 <= src_prov < num_provinces): continue
        if not (0 <= dst_prov < num_provinces): continue

        # Check 1 (C++ order): flag_a=1 and flag_b=0 → successful support → +10 capped at 201
        if flag_a == 1 and flag_b == 0:
            cur = int(state.g_MoveHistoryMatrix[power, src_prov, dst_prov])
            if cur < 201:
                state.g_MoveHistoryMatrix[power, src_prov, dst_prov] = min(cur + 10, 201)

        # Check 2: flag_c=1 → full conflict → zero src row, dst row, dst column (independent if)
        if flag_c == 1:
            state.g_MoveHistoryMatrix[power, src_prov, :] = 0
            state.g_MoveHistoryMatrix[power, dst_prov, :] = 0
            state.g_MoveHistoryMatrix[power, :, dst_prov] = 0

        # Check 3: flag_b=1 → unit disrupted at src → zero src row (independent if)
        if flag_b == 1:
            state.g_MoveHistoryMatrix[power, src_prov, :] = 0


# ── Self-proposal generator ──────────────────────────────────────────────────

def generate_self_proposals(state: InnerGameState, own_power: int) -> int:
    """Generate MTO proposals for all powers and inject into g_GeneralOrders.

    In the C binary, non-hold orders are driven by the press pipeline:
    other bots send PRP(XDO(...)) → register_received_press →
    g_BroadcastList → score_order_candidates_from_broadcast →
    g_GeneralOrders → MC Phase 1c.  In standalone / NO_PRESS mode
    that pipeline is empty, so all orders default to hold.

    This function replaces the press round-trip by generating proposals
    directly from FinalScoreSet — for each unit, the highest-scored
    reachable province becomes an MTO proposal in g_GeneralOrders.
    The MC trial loop's Phase 1c then dispatches these into g_OrderTable,
    allowing the MC to choose between holds and moves.

    For the own power, proposals also go into g_AllianceOrders (mirrors
    the trust gate in score_order_candidates_from_broadcast).

    Returns the number of proposals inserted.
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    fs = state.FinalScoreSet
    num_powers = 7
    inserted = 0

    if not hasattr(state, 'g_GeneralOrders'):
        state.g_GeneralOrders = {}
    if not hasattr(state, 'g_AllianceOrders'):
        state.g_AllianceOrders = {}
    if not state._id_to_prov:
        state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}

    # Determine which provinces are SCs (supply centers).
    # state.sc_provinces is a set of province *IDs* (ints), populated
    # by synchronize_from_game from game.map.scs.
    sc_set: set = set(getattr(state, 'sc_provinces', set()))

    for power in range(num_powers):
        for prov, info in list(state.unit_info.items()):
            if info['power'] != power:
                continue
            unit_type = info.get('type', 'A')

            # Score each adjacent province using multiple signals:
            #   1. FinalScoreSet[power, adj]  (strategic value from heat diffusion)
            #   2. SC bonus: +500 for unowned SCs, +300 for enemy SCs
            #   3. Adjacency influence: g_MaxProvinceScore[adj] (cross-power max)
            # Threshold: must beat 0 (any positive score means "worth considering")
            candidates: list = []  # [(score, adj)]
            for adj in state.get_adjacent_provinces(prov):
                # Skip provinces occupied by own unit
                adj_unit = state.unit_info.get(adj)
                if adj_unit is not None and adj_unit['power'] == power:
                    continue

                score = float(fs[power, adj])

                # SC bonus for unowned supply centers
                if adj in sc_set:
                    adj_owner = -1
                    for p2 in range(num_powers):
                        if state.g_SCOwnership[p2, adj] == 1:
                            adj_owner = p2
                            break
                    if adj_owner < 0:
                        score += 500.0   # neutral unowned SC
                    elif adj_owner != power:
                        score += 300.0   # enemy SC

                # Cross-power influence score as tiebreaker
                score += float(state.g_MaxProvinceScore[adj]) * 0.1

                if score > 0:
                    candidates.append((score, adj))

            if not candidates:
                continue

            # Sort descending, take top 2 (give MC some variety)
            candidates.sort(reverse=True)
            for _score, best_adj in candidates[:2]:
                prov_name = state._id_to_prov.get(prov, str(prov))
                adj_name = state._id_to_prov.get(best_adj, str(best_adj))
                order_seq = {
                    'type': 'MTO',
                    'unit': f"{unit_type} {prov_name}",
                    'target': adj_name,
                }

                state.g_GeneralOrders.setdefault(power, []).append(order_seq)
                inserted += 1

                # Own power also goes into alliance orders
                if power == own_power:
                    state.g_AllianceOrders.setdefault(power, []).append(order_seq)
                    inserted += 1

    if inserted:
        _log.debug(
            "generate_self_proposals: inserted %d proposals "
            "(general: %s, alliance: %s)",
            inserted,
            sorted(state.g_GeneralOrders.keys()),
            sorted(state.g_AllianceOrders.keys()),
        )
    return inserted


# ── ComputePress ─────────────────────────────────────────────────────────────

def compute_press(state: InnerGameState, own_power: int = 0) -> None:  # noqa: ARG001
    """
    Port of ComputePress (FUN_004401f0).

    Builds per-power adjacency-pressure matrix.  For each unit of any power,
    calls adjacency lookup, then for each adjacent *occupied* province
    (non-army coast token, or power-token == 0x14) sets
    g_PressMatrix[power][province] = 1 and increments g_PressCount[power].

    Result: g_PressMatrix (bool 2D, stride 0x100) + g_PressCount (count vec).

    Research.md §1295 / §2568 note.
    """
    state.g_PressMatrix.fill(0)
    state.g_PressCount.fill(0)

    for prov, info in state.unit_info.items():
        power = info['power']

        for adj in state.get_unit_adjacencies(prov):
            adj_power = state.get_unit_power(adj)
            if adj_power == -1:
                continue
            adj_info = state.unit_info.get(adj, {})
            # Condition: adjacent province is occupied, and is not an army
            # (fleet or non-army coast) or has power-token 0x14
            adj_type = adj_info.get('type', '')
            if adj_type == 'F' or adj_type == '':
                if state.g_PressMatrix[power, adj] == 0:
                    state.g_PressMatrix[power, adj] = 1
                    state.g_PressCount[power] += 1
