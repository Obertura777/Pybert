"""Support-order enumeration, assignment, and proposal generation.

Split from moves.py during the 2026-04 refactor.

Three support-chain helpers consumed by ``generate_orders`` and the MC
trial loop:

  * ``build_support_opportunities``  — populate ``g_support_opportunities_set``
    with candidate (supporter, target-province, recipient-prov) triples.
  * ``assign_support_order``         — commit a support order to
    ``g_order_table`` (sets ``_F_ORDER_ASGN`` / chain-conflict flags).
  * ``build_support_proposals``      — build ``g_support_proposals`` diffs
    suitable for outgoing DAIDE press XDO/SUG tokens.

Module-level deps: ``..state.InnerGameState``.
"""

from ..state import InnerGameState
from ._constants import (
    _F_ORDER_TYPE,
    _F_DEST_PROV,
    _F_INCOMING_MOVE,
    _F_ORDER_ASGN,
    _ORDER_MTO,
    _ORDER_CTO,
    _ORDER_CVY,
)

def build_support_opportunities(state: InnerGameState):
    """
    Port of FUN_004460a0 = BuildSupportOpportunities.

    Triangle-geometry pass: for each power pow, for each own unit U at province p,
    scan U's adjacency q; if three gates pass, for each r adj to q (r != p, own
    SC-territory) walk r's adjacency s — if s == p, the triangle p-q-r-p is closed
    and (U at p → q, W at r supports U into q) is a legal support pair. Appends
    one record per closed triangle to g_support_opportunities_set.

    Gates on q (the attack target):
      1. g_top_reach_flag[q] == 1  (DAT_005b98e8 lo=1, hi=0)
      2. g_sc_ownership[pow, q] == 1
      3. OrderedSet rank of q matches g_max_province_score[q]  (q is top-scored
         target for this power)

    Gate on r (the supporter position):
      - g_sc_ownership[pow, r] == 1
      - r != p

    See docs/funcs/BuildSupportOpportunities.md for full notes.
    """
    # Fresh list each call; C clears DAT_00baed74 linked list at entry.
    state.g_support_opportunities_set = []
    # Maintain legacy alias for downstream consumers that read g_support_proposals.
    state.g_support_proposals = state.g_support_opportunities_set

    num_powers = 7

    # For Gate 3 we need a per-power "top-scored target" check. final_score_set
    # (Albert.final_score_set[pow, prov]) is the per-power score we compare against
    # the global g_max_province_score[prov]. Fall back to permissive when either
    # table isn't populated.
    has_final = hasattr(state, 'final_score_set')

    for power in range(num_powers):
        # Walk units owned by this power (C: unit_list where unit[0x18] == power)
        for p, info in list(state.unit_info.items()):
            if info.get('power') != power:
                continue

            # --- first adjacency: q = potential attack target ---------------
            for q in state.get_adjacent_provinces(p):
                # Gate 1: g_top_reach_flag[q] == 1
                if int(state.g_top_reach_flag[q]) != 1:
                    continue
                # Gate 2: q is in this power's SC-ownership region
                if int(state.g_sc_ownership[power, q]) != 1:
                    continue
                # Gate 3: q is the top-scored target (OrderedSet key matches)
                if has_final:
                    fs = float(state.final_score_set[power, q])
                    mx = float(state.g_max_province_score[q])
                    if fs != mx:
                        continue

                # --- second adjacency: r = potential supporter province -----
                for r in state.get_adjacent_provinces(q):
                    # Supporter must be on own SC territory
                    if int(state.g_sc_ownership[power, r]) != 1:
                        continue
                    # r != p (C line 155: piVar6[3] != local_2c)
                    if r == p:
                        continue

                    # --- third adjacency: s; if s == p the triangle closes ---
                    if p in state.get_adjacent_provinces(r):
                        state.g_support_opportunities_set.append({
                            'power':           power,
                            'score':           float(state.g_max_province_score[q]),
                            'mover_prov':      p,   # U source (p)
                            'target_prov':     q,   # U destination (q)
                            'supporter_prov':  r,   # W position (r)
                            # coast tokens omitted (Python adj matrix is coast-agnostic)
                        })


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
      1  Adjacency-confirm gate (g_SupportableFlag + g_unit_presence + adj walk)
      2  Occupancy check (src empty / own unit / enemy-at-dst)
      3  LAB_00441475: 0.85 score threshold → write g_SupportScoreLo/Hi, g_convoy_chain_score
      4  LAB_0044150f: build-center support commit (threat gate → g_SupportConfirmed)
      5  Convoy fleet conflict resolution (g_last_mto_insert single-node check)
      6  Section 3: proximity score update (g_proximity_score / g_coverage_flag)
    """
    # ── Section 1 — Adjacency-confirm gate ─────────────────────────────────
    # g_enemy_reach_score (DAT_00535ce8) is the lo-word of a 64-bit counter
    # whose hi-word is g_enemy_pressure_secondary (DAT_00535cec); see the
    # CARRY4 64-bit-add at ScoreProvinces.c:404-409.  The C gate reads
    # 'lo==1 && hi==0' (= int64 value == 1), and the LAB_0044150f goto
    # reads 'lo!=0 || hi!=0' (= int64 != 0).  Consult both halves — same
    # pattern as monte_carlo/trial.py:371-384 and heuristics/scoring.py:145.
    # Fixed 2026-04-18 (AUDIT_moves_and_messages.md #1): previous read of
    # only the lo word could misclassify any counter value whose lo half
    # happened to equal 1 regardless of the hi half.
    reach_lo = int(state.g_enemy_reach_score[power_idx, src_prov])
    reach_hi = int(state.g_enemy_pressure_secondary[power_idx, src_prov])
    reach_eq_1 = (reach_lo == 1 and reach_hi == 0)
    reach_eq_0 = (reach_lo == 0 and reach_hi == 0)

    # DAT_004f6ce8[dst + power*0x40]: g_enemy_presence — 1 = enemy unit present
    # at dst_prov from power_idx's perspective.  The C gate (line 33-34)
    # checks the int64 (lo==1, hi==0); Python mirrors with the lo/hi pair.
    # Fixed 2026-04-20 (audit #1): was checking own-unit presence (inverted).
    enemy_pres_lo = int(state.g_enemy_presence[power_idx, dst_prov])
    enemy_pres_hi = 0  # hi-word of int64; always 0 for non-negative int32 stores
    dst_has_enemy = (enemy_pres_lo == 1 and enemy_pres_hi == 0)

    bVar16 = False  # adjacency confirmed
    if reach_eq_1 and dst_has_enemy:
        bVar16 = dst_prov in state.adj_matrix.get(src_prov, [])

    # C gate (lines 62-65): goto LAB_0044150f (skip score) unless
    #   (reach==1 AND hi==0 AND enemy_pres==1 AND hi==0 AND bVar16) OR
    #   (reach==0 AND hi==0).
    # bVar16 = True already implies reach==1 AND enemy present, so the
    # combined condition simplifies to: reach_eq_0 OR bVar16.
    go_to_score = reach_eq_0 or bVar16

    # ── Section 2 — Occupancy check (C lines 66-84) ──────────────────────
    # C: *(char *)(iVar4 + 3 + param_2 * 0x24) — province record byte at
    # offset 3.  '\0' = empty/no special → fall through to LAB_00441475.
    # Non-'\0': unit-type/power-index check.  '\x01' sub-case skips score
    # when unit power matches param_1.  Python approximation: if src has a
    # non-own unit AND dst has an own unit, skip to LAB_0044150f.
    if go_to_score:
        src_unit = state.unit_info.get(src_prov)
        if src_unit is not None and src_unit['power'] != power_idx:
            dst_unit = state.unit_info.get(dst_prov)
            if dst_unit is not None and dst_unit['power'] == power_idx:
                go_to_score = False  # goto LAB_0044150f

    # ── LAB_00441475 — Score threshold and SUP assignment ──────────────────
    if go_to_score:
        # Scores from Albert.final_score_set[power] (this+pow*0xc+0x4000)
        score_dst = float(state.final_score_set[power_idx, dst_prov])
        score_src = float(state.final_score_set[power_idx, src_prov])
        # g_ProvinceBaseScore = DAT_006040e8 (state.g_attack_count)
        base_score = float(state.g_attack_count[power_idx, src_prov])

        if score_src * 0.85 < score_dst or base_score > 0:
            # g_SupportScoreLo/Hi → order table fields [18][19]
            state.g_order_table[src_prov, 18] = score_src
            state.g_order_table[src_prov, 19] = 0.0
            # g_convoy_chain_score / g_OrderScoreLo → order table [6] (dual-use)
            state.g_convoy_chain_score[src_prov] = score_src
            state.g_order_table[src_prov, 6] = score_src
            # g_order_score_hi → order table [7]
            state.g_order_score_hi[src_prov] = 0.0
            state.g_order_table[src_prov, 7] = 0.0

    # ── LAB_0044150f — Build-center support commit ──────────────────────────
    # g_OrderCommitted2 = DAT_00baeddc (state.g_support_demand, order table [15])
    if (int(state.g_support_demand[dst_prov]) == 1
            and state.g_build_order_pending[power_idx, dst_prov] == 0):

        # g_threat_level (DAT_0058f8e8) = threat level at dst for this power
        # g_sc_ownership[pow,dst] gates the two branches (C line 114 / 116):
        #   branch 1: threat > 1 (>=2) AND dst NOT own-SC
        #   branch 2: threat > 2 (>=3) AND dst IS own-SC
        # Both branches also require DAT_00520cec == 0 (hi-word of pressure;
        # always true for non-negative int32 values → elided)
        threat = int(state.g_threat_level[power_idx, dst_prov])
        own_sc_at_dst = int(state.g_sc_ownership[power_idx, dst_prov])

        if threat != -1 and (
            (threat >= 2 and own_sc_at_dst == 0) or
            (threat >= 3 and own_sc_at_dst == 1)
        ):
            if int(state.g_support_demand[src_prov]) != 1:
                # Validate: src adjacent to dst AND dst is a home build-center
                # for this power (C: GameBoard_GetPowerRec lookup against
                # gamestate+0x24b4 build-center list). 2026-04-14 — tightened
                # from the prior src-SCOwnership heuristic to the correct
                # dst-home-center membership check via state.home_centers.
                home = state.home_centers.get(power_idx, frozenset())
                src_valid = (
                    dst_prov in state.adj_matrix.get(src_prov, [])
                    and dst_prov in home
                    and int(state.g_sc_ownership[power_idx, dst_prov]) == 1
                )
                if src_valid:
                    sup_confirmed  = int(state.g_order_table[dst_prov, 20])
                    # C: (DAT_00baede8[dst*0x1e] & DAT_00baedec[dst*0x1e]) == 0xffffffff.
                    # Both score_lo (field 18) and score_hi (field 19) must be
                    # the -1 sentinel for "unset". Fixed 2026-04-14 — was
                    # `== 0.0` which conflated zero-score with unset.
                    score_unset    = (state.g_order_table[dst_prov, 18] == -1.0
                                      and state.g_order_table[dst_prov, 19] == -1.0)
                    # g_unit_presence == {0,0}: power has NO unit at dst
                    dst_empty      = (state.unit_info.get(dst_prov, {}).get('power', -1)
                                      != power_idx)

                    if sup_confirmed == 0 and score_unset and dst_empty and flag == 0:
                        state.g_order_table[dst_prov, 20] = 1       # g_SupportConfirmed
                        state.g_convoy_source_prov[dst_prov] = float(src_prov)  # g_SupportTarget

    # ── Convoy fleet conflict resolution (C LAB_00441685, lines 146-184) ────
    # Gated 2026-04-14: C runs GameBoard_GetPowerRec against gamestate+0x24b4
    # (build-center list) and only clears the cached MTO's support-commit when
    # `piVar13[1] != iVar14` — i.e. dst is NOT in this power's build-center
    # list. Python mirrors with `dst_prov not in home_centers[power_idx]`.
    # Previously fired unconditionally; over-fire was usually harmless when
    # g_last_mto_insert was None, but observable on re-entry after a genuine
    # home-center commit.
    home = state.home_centers.get(power_idx, frozenset())
    if dst_prov not in home and state.g_last_mto_insert is not None:
        node_type, node_prov = state.g_last_mto_insert
        if node_type == 2 and int(state.g_order_table[node_prov, 20]) == 1:
            state.g_order_table[node_prov, 20] = 0
            state.g_convoy_source_prov[node_prov] = float(0xffffffff)  # g_SupportTarget = unset

    # ── Section 3 — Proximity score update (C lines 186-232) ──────────────
    # Gate: g_enemy_presence[power_idx, dst_prov] == 1.  The C code then
    # reads the actual unit at dst_prov to get its owner power and walks
    # adjacencies to update g_proximity_score for that power.
    # Fixed 2026-04-20 (audit #1): was gated on own-unit, now on enemy.
    if dst_has_enemy:
        w_unit = state.unit_info.get(dst_prov)
        if w_unit is not None:
            w_power = w_unit['power']
            for a in state.adj_matrix.get(dst_prov, []):
                if a != src_prov:
                    state.g_proximity_score[w_power, a] += 1
                if a == src_prov and int(state.g_threat_level[w_power, src_prov]) == 1:
                    state.g_proximity_score[w_power, src_prov] += 2


def build_support_proposals(state: 'InnerGameState', power_idx: int) -> None:
    """
    Port of FUN_0043e370 = BuildSupportProposals.

    For each unit belonging to *power_idx*, determines the unit's target province
    (dest) and counts threatening powers via g_coverage_flag / g_proximity_score.

      0 threats  — no action.
      1 threat + convoy order + press off
                 — alliance handshake: set g_xdo_press_sent for units adjacent to
                   dest whose power != power_idx; no XDO content emitted.
      2+ threats — outer loop over each threatening power (local_1ec).
                   For each threatening power whose score exceeds the unit's base
                   score, determine priority then scan all units for candidate
                   supporters, filtering by:
                     1. unit2.power != power_idx
                     2. unit2.power != threatening power (local_1ec)
                     3. unit2.power != g_ally_designation_b[dest]
                     4. unit2.power != g_ally_designation_a[dest]
                     5. g_order_table[unit2_prov, _F_INCOMING_MOVE] == 0
                   If unit2 can reach dest, emit XDO SUP proposal (deduped via
                   g_proposal_history; priority added to existing entry if seen).

    Globals written:
      g_proposal_history — map of key → priority accumulator
      g_xdo_press_sent[power_idx, unit2_power] — 1 when press flagged
      g_xdo_press_proposals — list of proposal dicts (consumed by ComputePress)
    """
    ot = state.g_order_table
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

        # base score for this province (g_ProvinceBaseScore = g_order_table field 13)
        base_score = int(ot[dest, _F_INCOMING_MOVE])

        # ── Count threatening powers ──────────────────────────────────────────
        # g_coverage_flag[other, dest] = DAT_00ba4370[dest + other*0x100]
        # g_proximity_score[other, dest] = DAT_00ba4370[dest+0x1500 + other*0x100]
        threat_count = 0
        max_threat = 0
        for other in range(num_powers):
            if other == power_idx:
                continue
            coverage = int(state.g_coverage_flag[other, dest])
            proximity = int(state.g_proximity_score[other, dest])
            score = coverage - (proximity if proximity > 0 else 0)
            if score > max_threat:
                max_threat = score
            if score > 0:
                threat_count += 1

        if threat_count < 2:
            # 0 or 1 threat: only act for convoy order with press off
            # decompile line 169: order_type check uses own_prov's field (iVar1+0x20), i.e. _ORDER_CVY
            # C: (&DAT_00baedf0)[own_prov * 0x1e] == 5. Decompile label
            # (DAT_00baedf0 = g_SupportConfirmed, field 20) is a Ghidra
            # mis-symbol — field 20's domain is {0,1} per AssignSupportOrder
            # writes, so `==5` can't be g_SupportConfirmed. Actual read is
            # field 0 (g_OrderState, 5=CVY). Verified 2026-04-14.
            if (threat_count == 1
                    and int(ot[own_prov, _F_ORDER_TYPE]) == _ORDER_CVY
                    and state.g_press_flag == 0):
                for unit2_prov, u2_info in state.unit_info.items():
                    if u2_info['power'] == power_idx:
                        continue
                    if dest in state.get_unit_adjacencies(unit2_prov):
                        # C Branch 1 (lines 218-273): write to g_proposal_history_map
                        # with priority increment 1, plus set g_xdo_press_sent.
                        key = (unit2_prov * 1000 + own_prov) * 1000 + dest
                        phm = getattr(state, 'g_proposal_history_map', None)
                        if phm is not None:
                            existing = None
                            for rec in phm:
                                if rec.get('key') == key:
                                    existing = rec
                                    break
                            if existing is not None:
                                existing['score'] = existing.get('score', 0) + 1
                            else:
                                phm.append({
                                    'key':          key,
                                    'power':        power_idx,
                                    'province':     own_prov,
                                    'score':        1,
                                    'target_power': u2_info['power'],
                                    'src_prov':     own_prov,
                                    'dst_prov':     dest,
                                })
                        state.g_xdo_press_sent[power_idx, u2_info['power']] = 1
        else:
            # 2+ threats — outer loop over all powers as threatening-power candidates
            # (local_1ec in decompile, iterates 0..numPowers with local_1c4 striding
            #  through g_proximity_score columns)
            for threat_power in range(num_powers):
                if threat_power == power_idx:
                    continue

                # Re-score this specific threatening power (same formula as threat loop)
                t_coverage  = int(state.g_coverage_flag[threat_power, dest])
                t_proximity = int(state.g_proximity_score[threat_power, dest])
                t_score = t_coverage - (t_proximity if t_proximity > 0 else 0)

                # Decompile line 290-291: skip if score <= 0 OR score <= base_score - is_move
                if t_score <= 0:
                    continue
                if t_score <= base_score - is_move:
                    continue

                # Priority logic (decompile lines 292-303):
                # C reads DAT_00634e90 = g_relation_score (pow*21+other, int32).
                # NOT g_ally_trust_score — that's at a different address (float64).
                # Fixed 2026-04-14 — was previously reading g_ally_trust_score.
                trust = int(state.g_relation_score[power_idx, threat_power])
                if trust < 0xf:
                    # priority=8 when: g_ally_designation_b[dest] == power_idx
                    #                  AND dest == own_prov AND base_score < t_score
                    if (int(state.g_ally_designation_b[dest]) == power_idx
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
                    if unit2_power == int(state.g_ally_designation_b[dest]):
                        continue
                    # Filter 4: not ally-A designated power for dest
                    if unit2_power == int(state.g_ally_designation_a[dest]):
                        continue
                    # Filter 5: unit2's province must have no incoming move
                    # (g_ProvinceBaseScore[unit2_prov * 0x1e] == 0, i.e. _F_INCOMING_MOVE)
                    if int(ot[unit2_prov, _F_INCOMING_MOVE]) != 0:
                        continue

                    if dest not in state.get_unit_adjacencies(unit2_prov):
                        continue

                    key = (unit2_prov * 1000 + own_prov) * 1000 + dest
                    phm = getattr(state, 'g_proposal_history_map', None)
                    if key in state.g_proposal_history:
                        # Already proposed: accumulate priority into existing entry
                        # (decompile line 388-389: *(local_1bc + 0x24) += local_1c8)
                        for prop in state.g_xdo_press_proposals:
                            if prop.get('key') == key:
                                prop['priority'] += priority
                                break
                        # C Branch 2: also accumulate into g_proposal_history_map
                        if phm is not None:
                            for rec in phm:
                                if rec.get('key') == key:
                                    rec['score'] = rec.get('score', 0) + priority
                                    break
                        continue

                    state.g_proposal_history.add(key)
                    state.g_xdo_press_sent[power_idx, unit2_power] = 1
                    state.g_xdo_press_proposals.append({
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
                    # C Branch 2 (lines 370-445): insert new entry into
                    # g_proposal_history_map so Phase 1e exploit pass has
                    # candidates for MC exploration across trials.
                    if phm is not None:
                        phm.append({
                            'key':          key,
                            'power':        power_idx,
                            'province':     own_prov,
                            'score':        priority,
                            'target_power': unit2_power,
                            'src_prov':     own_prov,
                            'dst_prov':     dest,
                        })


