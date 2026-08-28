"""SnapshotProvinceState — per-province designation and target-flag refresh.

Port of SnapshotProvinceState (Source/bot/SnapshotProvinceState.c).

Called once per turn boundary, before order-generation heuristics run.
Writes:
  g_ally_designation_b/a/c    — per-province army-owner designation slots
  g_assault_flag               — per-province assault designation (4th slot)
  g_target_flag                — (7, 256) reachability/coordination flags
Then copies a season snapshot (lo + hi words):
  SPR/FAL → g_spr_desig_b/a/c (+_hi), g_AttackMap
  SUM/AUT → g_sum_desig_b/a/c (+_hi)
"""

import numpy as np

from ..state import InnerGameState

_NUM_PROVINCES = 256
_NUM_POWERS    = 7


def snapshot_province_state(state: InnerGameState) -> None:
    """Port of SnapshotProvinceState.

    Phases
    ------
    1  Reset all four designation slots (b, a, c, d) to -1 / -1.
    2  Set designation_b (SC controller) and designation_c (-2 sentinel for
       every supply centre) from province control records.
    3  Set designation_a (all-unit owner) from unit_info.
    4  When NOT in g_other_power_lead_flag mode:
       4a  Propagate designation_c outward from each controlled SC.
       4b  Mark adjacent non-SCs as target_flag = 1 for each power.
       4c  Promote coordinated-ally targets to flag 2.
       4d  Demote non-ally targets back to 1 then clear to 0.
    5  When deceit_level < 2 and ally_under_attack:
       Identify provinces suitable for sharing with the best ally and
       update designation_c + g_alliance_msg_tree.
    6  Copy season snapshot.
    """
    own_power = int(state.albert_power_idx)
    num_powers = int(getattr(state, 'g_num_powers', _NUM_POWERS))
    num_provinces = int(getattr(state, 'num_valid_provinces', _NUM_PROVINCES))
    if num_provinces <= 0:
        num_provinces = _NUM_PROVINCES
    sc_provinces = {
        int(prov) for prov in getattr(state, 'sc_provinces', set())
        if 0 <= int(prov) < num_provinces
    }

    # ── Phase 1: Reset ────────────────────────────────────────────────────────
    active_provs = np.s_[:num_provinces]
    state.g_ally_designation_b[active_provs] = -1
    state.g_ally_designation_b_hi[active_provs] = -1
    state.g_ally_designation_a[active_provs] = -1
    state.g_ally_designation_a_hi[active_provs] = -1
    state.g_ally_designation_c[active_provs] = -1
    state.g_ally_designation_c_hi[active_provs] = -1
    state.g_assault_flag[active_provs] = -1
    state.g_assault_flag_hi[active_provs] = -1

    # ── Phase 2: designation_b + initial designation_c from SC records ───────
    # Province byte +3 is the supply-centre flag. The token at +0x20 carries
    # its controlling power (category 'A', low byte power index).
    for prov in sc_provinces:
        state.g_ally_designation_c[prov]    = -2
        state.g_ally_designation_c_hi[prov] = -1
        owner = int(state.g_sc_owner[prov])
        if 0 <= owner < num_powers:
            state.g_ally_designation_b[prov]    = owner
            state.g_ally_designation_b_hi[prov] = 0

    # ── Phase 3: designation_a from unit list ─────────────────────────────────
    # C: iterates the unit linked-list; for each unit:
    #   a lo = unit.owner,  a hi = unit.owner >> 31  (always 0)
    for prov, info in state.unit_info.items():
        if prov >= num_provinces:
            continue
        power = int(info['power'])
        state.g_ally_designation_a[prov]    = power
        state.g_ally_designation_a_hi[prov] = 0

    if not state.g_other_power_lead_flag:
        # ── Phase 4a: propagate designation_c outward from controlled SCs ─────
        # For each controlled SC of power P, walk its unfiltered
        # adjacency list.  Empty adjacent provinces inherit P; if a
        # province already has a different claim, mark it contested (-2).
        # Supply centres were set to -2 in Phase 2 and are skipped
        # because (-2 & -1) = 0xfffffffe ≠ 0xffffffff (unset sentinel).
        for prov in sc_provinces:
            power = int(state.g_sc_owner[prov])
            if not (0 <= power < num_powers):
                continue
            for adj in state.adj_matrix.get(prov, []):
                if adj >= num_provinces:
                    continue
                c_lo = int(state.g_ally_designation_c[adj])
                c_hi = int(state.g_ally_designation_c_hi[adj])
                if c_lo == -1 and c_hi == -1:       # unset
                    state.g_ally_designation_c[adj]    = power
                    state.g_ally_designation_c_hi[adj] = 0
                else:                               # already claimed
                    if c_lo != power or c_hi != 0:
                        state.g_ally_designation_c[adj]    = -2
                        state.g_ally_designation_c_hi[adj] = -1

        # ── Phase 4b: initial target flags ────────────────────────────────────
        # For each controlled SC of power V, mark adjacent non-SC provinces
        # as target_flag[V, adj] = 1.
        for prov in sc_provinces:
            power = int(state.g_sc_owner[prov])
            if not (0 <= power < num_powers):
                continue
            for adj in state.adj_matrix.get(prov, []):
                if adj < num_provinces and adj not in sc_provinces:
                    state.g_target_flag[power, adj] = 1
                    state.g_attack_count2[power, adj] = 0

        # ── Phase 4c: promote to 2 for coordinated ally targets ───────────────
        # Condition: trust_hi[victim, other] >= 0
        #        AND (trust_hi > 0  OR  trust_lo > 1)
        for victim in range(num_powers):
            for other in range(num_powers):
                if victim == other:
                    continue
                t_hi = int(state.g_ally_trust_score_hi[victim, other])
                t_lo = int(state.g_ally_trust_score[victim, other]) & 0xFFFFFFFF
                if not (t_hi >= 0 and (t_hi > 0 or t_lo > 1)):
                    continue
                for prov in sc_provinces:
                    if int(state.g_sc_owner[prov]) != other:
                        continue
                    for adj in state.adj_matrix.get(prov, []):
                        if adj < num_provinces and state.g_target_flag[victim, adj] == 1:
                            state.g_target_flag[victim, adj] = 2
                            state.g_attack_count2[victim, adj] = 0

        # ── Phase 4d: demote and clear near non-ally units ────────────────────
        # Condition for "not allied": trust_hi < 1 AND (trust_hi < 0 OR trust_lo < 2)
        for victim in range(num_powers):
            # Pass 1: for each non-ally army, demote its adjacent 2-targets back to 1.
            for other in range(num_powers):
                if victim == other:
                    continue
                t_hi = int(state.g_ally_trust_score_hi[victim, other])
                t_lo = int(state.g_ally_trust_score[victim, other]) & 0xFFFFFFFF
                if not (t_hi < 1 and (t_hi < 0 or t_lo < 2)):
                    continue
                for prov in sc_provinces:
                    if int(state.g_sc_owner[prov]) != other:
                        continue
                    for adj in state.adj_matrix.get(prov, []):
                        if adj < num_provinces and state.g_target_flag[victim, adj] == 2:
                            state.g_target_flag[victim, adj] = 1
                            state.g_attack_count2[victim, adj] = 0

            # Pass 2: for every non-victim unit that is not allied with victim,
            # clear target_flag[victim, adj] = 0 for all unit-type-filtered adjs.
            for prov, info in state.unit_info.items():
                if prov >= num_provinces:
                    continue
                owner = int(info['power'])
                if owner == victim:
                    continue
                t_hi = int(state.g_ally_trust_score_hi[victim, owner])
                t_lo = int(state.g_ally_trust_score[victim, owner]) & 0xFFFFFFFF
                if not (t_hi < 1 and (t_hi < 0 or t_lo < 2)):
                    continue
                utype = info.get('type', 'A')
                coast = info.get('coast', '')
                adjs = [
                    adj for adj in state.adj_matrix.get(prov, [])
                    if state.can_reach_by_type(prov, adj, utype, coast)
                ]
                for adj in adjs:
                    if adj < num_provinces:
                        state.g_target_flag[victim, adj] = 0
                        state.g_attack_count2[victim, adj] = 0

    # ── Phase 5: Alliance sharing proposals ──────────────────────────────────
    # C:442-714  Only when g_deceit_level < 2 and best ally is under attack.
    # C: DAT_00baed45 == '\x01'  ↔  state.g_ally_under_attack == 1
    if state.g_deceit_level < 2 and getattr(state, 'g_ally_under_attack', 0) == 1:
        reach = np.full(num_provinces, -1, dtype=np.int32)

        def _adjs(prov: int, utype: str) -> list:
            coast = state.unit_info.get(prov, {}).get('coast', '')
            return [
                adj for adj in state.adj_matrix.get(prov, [])
                if state.can_reach_by_type(prov, adj, utype, coast)
            ]

        # Pass 1 — own units: mark every unit-reachable adjacent province
        # -1 → 0 (first claim), anything else → -10 (contested reach)
        for prov, info in state.unit_info.items():
            if prov >= num_provinces or int(info['power']) != own_power:
                continue
            for adj in _adjs(prov, info.get('type', 'A')):
                if adj >= num_provinces:
                    continue
                if reach[adj] == -1:
                    reach[adj] = 0
                else:
                    reach[adj] = -10

        # Pass 2 — own units on SCs: upgrade adjacent SCs 0 → 1
        for prov, info in state.unit_info.items():
            if prov >= num_provinces or int(info['power']) != own_power:
                continue
            if prov not in sc_provinces:
                continue
            for adj in _adjs(prov, info.get('type', 'A')):
                if adj < num_provinces and adj in sc_provinces and reach[adj] == 0:
                    reach[adj] = 1

        # Pass 3 — best-ally units: provinces with reach == 1 become
        # shared strategic targets; log alliance message.
        # C: DAT_004c6bc4  ↔  g_best_ally_slot0
        best_ally = int(getattr(state, 'g_best_ally_slot0', -1))
        if best_ally >= 0:
            for prov, info in state.unit_info.items():
                if prov >= num_provinces or int(info['power']) != best_ally:
                    continue
                for adj in _adjs(prov, info.get('type', 'A')):
                    if adj >= num_provinces:
                        continue
                    if reach[adj] == 1:
                        state.g_ally_designation_c[adj]    = best_ally
                        state.g_ally_designation_c_hi[adj] = 0
                        if hasattr(state, 'g_alliance_msg_tree'):
                            state.g_alliance_msg_tree.add(3)

    # ── Phase 6: Season snapshot ──────────────────────────────────────────────
    season = state.g_season
    if season in ('SPR', 'FAL'):
        # C lines 718-726: copy designation lo+hi to SPR/FAL snapshot slots.
        state.g_spr_desig_b[active_provs] = state.g_ally_designation_b[active_provs]
        state.g_spr_desig_b_hi[active_provs] = state.g_ally_designation_b_hi[active_provs]
        state.g_spr_desig_a[active_provs] = state.g_ally_designation_a[active_provs]
        state.g_spr_desig_a_hi[active_provs] = state.g_ally_designation_a_hi[active_provs]
        state.g_spr_desig_c[active_provs] = state.g_ally_designation_c[active_provs]
        state.g_spr_desig_c_hi[active_provs] = state.g_ally_designation_c_hi[active_provs]
        # g_AttackMap mirrors g_target_flag for all powers at movement-phase end.
        state.g_AttackMap[:num_powers, :num_provinces] = state.g_target_flag[
            :num_powers, :num_provinces
        ]
    elif season in ('SUM', 'AUT'):
        # C lines 744-750: copy designation lo+hi to SUM/AUT snapshot slots.
        state.g_sum_desig_b[active_provs] = state.g_ally_designation_b[active_provs]
        state.g_sum_desig_b_hi[active_provs] = state.g_ally_designation_b_hi[active_provs]
        state.g_sum_desig_a[active_provs] = state.g_ally_designation_a[active_provs]
        state.g_sum_desig_a_hi[active_provs] = state.g_ally_designation_a_hi[active_provs]
        state.g_sum_desig_c[active_provs] = state.g_ally_designation_c[active_provs]
        state.g_sum_desig_c_hi[active_provs] = state.g_ally_designation_c_hi[active_provs]
        # SUM/AUT: no target-flag snapshot (C omits this copy for retreat seasons)
