"""SnapshotProvinceState — per-province designation and target-flag refresh.

Port of SnapshotProvinceState (Source/bot/SnapshotProvinceState.c).

Called once per turn boundary, before order-generation heuristics run.
Writes:
  g_ally_designation_b/a/c    — per-province army-owner designation slots
  g_target_flag                — (7, 256) reachability/coordination flags
Then copies a season snapshot:
  SPR/FAL → g_spr_desig_b/a/c, g_AttackMap
  SUM/AUT → g_sum_desig_b/a/c
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
    2  Set designation_b (army owner) and designation_c (-2 sentinel for
       every occupied province) from unit_info.
    3  Set designation_a (all-unit owner) from unit_info.
    4  When NOT in g_other_power_lead_flag mode:
       4a  Propagate designation_c outward from each army unit.
       4b  Mark empty adjacent provinces as target_flag = 1 for each power.
       4c  Promote coordinated-ally targets to flag 2.
       4d  Demote non-ally targets back to 1 then clear to 0.
    5  When deceit_level < 2 and ally_under_attack:
       Identify provinces suitable for sharing with the best ally and
       update designation_c + g_alliance_msg_tree.
    6  Copy season snapshot.
    """
    own_power = int(state.albert_power_idx)

    # ── Phase 1: Reset ────────────────────────────────────────────────────────
    state.g_ally_designation_b.fill(-1)
    state.g_ally_designation_b_hi.fill(-1)
    state.g_ally_designation_a.fill(-1)
    state.g_ally_designation_a_hi.fill(-1)
    state.g_ally_designation_c.fill(-1)
    state.g_ally_designation_c_hi.fill(-1)

    # ── Phase 2: designation_b + initial designation_c from unit table ────────
    # C: loops over province struct array; for each province with a unit:
    #   c lo = 0xfffffffe (-2), c hi = 0xffffffff (-1)   [all occupied]
    #   if unit type == 'A': b lo = power, b hi = 0      [army only]
    for prov, info in state.unit_info.items():
        if prov >= _NUM_PROVINCES:
            continue
        utype = info.get('type', 'A')
        power = int(info['power'])
        state.g_ally_designation_c[prov]    = -2
        state.g_ally_designation_c_hi[prov] = -1
        if utype == 'A':
            state.g_ally_designation_b[prov]    = power
            state.g_ally_designation_b_hi[prov] = 0

    # ── Phase 3: designation_a from unit list ─────────────────────────────────
    # C: iterates the unit linked-list; for each unit:
    #   a lo = unit.owner,  a hi = unit.owner >> 31  (always 0)
    for prov, info in state.unit_info.items():
        if prov >= _NUM_PROVINCES:
            continue
        power = int(info['power'])
        state.g_ally_designation_a[prov]    = power
        state.g_ally_designation_a_hi[prov] = 0

    if not state.g_other_power_lead_flag:
        # ── Phase 4a: propagate designation_c outward via army adjacencies ────
        # For each province whose army owns power P, walk its unfiltered
        # adjacency list.  Empty adjacent provinces inherit P; if a
        # province already has a different claim, mark it contested (-2).
        # Provinces with units were set to -2 in Phase 2 and are skipped
        # because (-2 & -1) = 0xfffffffe ≠ 0xffffffff (unset sentinel).
        for prov, info in state.unit_info.items():
            if prov >= _NUM_PROVINCES:
                continue
            if info.get('type', 'A') != 'A':
                continue
            power = int(info['power'])
            for adj in state.adj_matrix.get(prov, []):
                if adj >= _NUM_PROVINCES:
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
        # For each army unit of power V, mark empty adjacent provinces
        # as target_flag[V, adj] = 1.
        state.g_target_flag.fill(0)
        for prov, info in state.unit_info.items():
            if prov >= _NUM_PROVINCES:
                continue
            if info.get('type', 'A') != 'A':
                continue
            power = int(info['power'])
            for adj in state.adj_matrix.get(prov, []):
                if adj < _NUM_PROVINCES and adj not in state.unit_info:
                    state.g_target_flag[power, adj] = 1

        # ── Phase 4c: promote to 2 for coordinated ally targets ───────────────
        # Condition: trust_hi[victim, other] >= 0
        #        AND (trust_hi > 0  OR  trust_lo > 1)
        for victim in range(_NUM_POWERS):
            for other in range(_NUM_POWERS):
                if victim == other:
                    continue
                t_hi = int(state.g_ally_trust_score_hi[victim, other])
                t_lo = int(state.g_ally_trust_score[victim, other])
                if not (t_hi >= 0 and (t_hi > 0 or t_lo > 1)):
                    continue
                for prov, info in state.unit_info.items():
                    if prov >= _NUM_PROVINCES:
                        continue
                    if info.get('type', 'A') != 'A':
                        continue
                    if int(info['power']) != other:
                        continue
                    for adj in state.adj_matrix.get(prov, []):
                        if adj < _NUM_PROVINCES and state.g_target_flag[victim, adj] == 1:
                            state.g_target_flag[victim, adj] = 2

        # ── Phase 4d: demote and clear near non-ally units ────────────────────
        # Condition for "not allied": trust_hi < 1 AND (trust_hi < 0 OR trust_lo < 2)
        for victim in range(_NUM_POWERS):
            # Pass 1: for each non-ally army, demote its adjacent 2-targets back to 1.
            for other in range(_NUM_POWERS):
                if victim == other:
                    continue
                t_hi = int(state.g_ally_trust_score_hi[victim, other])
                t_lo = int(state.g_ally_trust_score[victim, other])
                if not (t_hi < 1 and (t_hi < 0 or t_lo < 2)):
                    continue
                for prov, info in state.unit_info.items():
                    if prov >= _NUM_PROVINCES:
                        continue
                    if info.get('type', 'A') != 'A':
                        continue
                    if int(info['power']) != other:
                        continue
                    for adj in state.adj_matrix.get(prov, []):
                        if adj < _NUM_PROVINCES and state.g_target_flag[victim, adj] == 2:
                            state.g_target_flag[victim, adj] = 1

            # Pass 2: for every non-victim unit that is not allied with victim,
            # clear target_flag[victim, adj] = 0 for all unit-type-filtered adjs.
            for prov, info in state.unit_info.items():
                if prov >= _NUM_PROVINCES:
                    continue
                owner = int(info['power'])
                if owner == victim:
                    continue
                t_hi = int(state.g_ally_trust_score_hi[owner, victim])
                t_lo = int(state.g_ally_trust_score[owner, victim])
                if not (t_hi < 1 and (t_hi < 0 or t_lo < 2)):
                    continue
                utype = info.get('type', 'A')
                if utype == 'F':
                    adjs = state.fleet_adj_matrix.get(prov, state.adj_matrix.get(prov, []))
                else:
                    adjs = state.adj_matrix.get(prov, [])
                for adj in adjs:
                    if adj < _NUM_PROVINCES:
                        state.g_target_flag[victim, adj] = 0

    # ── Phase 5: Alliance sharing proposals ──────────────────────────────────
    # C:442-714  Only when g_deceit_level < 2 and best ally is under attack.
    # C uses three passes over aiStack_418; simplified here: Pass 1 only marks
    # empty adjacent provinces (C also marks occupied ones then Pass 2 upgrades
    # them; net effect is identical).
    # C: DAT_00baed45 == '\x01'  ↔  state.g_ally_under_attack == 1
    if state.g_deceit_level < 2 and getattr(state, 'g_ally_under_attack', 0) == 1:
        reach = np.full(_NUM_PROVINCES, -1, dtype=np.int32)

        def _adjs(prov: int, utype: str) -> list:
            if utype == 'F':
                return state.fleet_adj_matrix.get(prov, state.adj_matrix.get(prov, []))
            return state.adj_matrix.get(prov, [])

        # Pass 1 — own units: mark empty adjacent provinces
        # -1 → 0 (first claim), anything else → -10 (contested reach)
        for prov, info in state.unit_info.items():
            if prov >= _NUM_PROVINCES or int(info['power']) != own_power:
                continue
            for adj in _adjs(prov, info.get('type', 'A')):
                if adj >= _NUM_PROVINCES or adj in state.unit_info:
                    continue
                if reach[adj] == -1:
                    reach[adj] = 0
                else:
                    reach[adj] = -10

        # Pass 2 — own units: upgrade occupied adjacent provinces 0 → 1
        for prov, info in state.unit_info.items():
            if prov >= _NUM_PROVINCES or int(info['power']) != own_power:
                continue
            for adj in _adjs(prov, info.get('type', 'A')):
                if adj < _NUM_PROVINCES and adj in state.unit_info and reach[adj] == 0:
                    reach[adj] = 1

        # Pass 3 — best-ally units: provinces with reach == 1 become
        # shared strategic targets; log alliance message.
        # C: DAT_004c6bc4  ↔  g_best_ally_slot0
        best_ally = int(getattr(state, 'g_best_ally_slot0', -1))
        if best_ally < 0 and hasattr(state, 'g_enemy_slot'):
            best_ally = int(state.g_enemy_slot[0])
        if best_ally >= 0:
            for prov, info in state.unit_info.items():
                if prov >= _NUM_PROVINCES or int(info['power']) != best_ally:
                    continue
                for adj in _adjs(prov, info.get('type', 'A')):
                    if adj >= _NUM_PROVINCES:
                        continue
                    if adj in state.unit_info and reach[adj] == 1:
                        state.g_ally_designation_c[adj]    = best_ally
                        state.g_ally_designation_c_hi[adj] = 0
                        if hasattr(state, 'g_alliance_msg_tree'):
                            state.g_alliance_msg_tree.add(best_ally)

    # ── Phase 6: Season snapshot ──────────────────────────────────────────────
    season = state.g_season
    if season in ('SPR', 'FAL'):
        state.g_spr_desig_b[:] = state.g_ally_designation_b
        state.g_spr_desig_a[:] = state.g_ally_designation_a
        state.g_spr_desig_c[:] = state.g_ally_designation_c
        # g_AttackMap mirrors g_target_flag for all powers at movement-phase end.
        state.g_AttackMap[:] = state.g_target_flag
    elif season in ('SUM', 'AUT'):
        state.g_sum_desig_b[:] = state.g_ally_designation_b
        state.g_sum_desig_a[:] = state.g_ally_designation_a
        state.g_sum_desig_c[:] = state.g_ally_designation_c
        # SUM/AUT: no target-flag snapshot (C omits this copy for retreat seasons)
