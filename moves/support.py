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
    _F_SECONDARY,
    _F_DEST_PROV,
    _F_CONVOY_LO,
    _F_CONVOY_HI,
    _F_INCOMING_MOVE,
    _F_SUP_CHAIN_CONFLICT,
    _F_THREAT_TOTAL,
    _F_ORDER_ASGN,
    _ORDER_MTO,
    _ORDER_SUP_HLD,
    _ORDER_SUP_MTO,
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

    for power in range(num_powers):
        # Walk units owned by this power (C: unit_list where unit[0x18] == power)
        for p, info in list(state.unit_info.items()):
            if info.get('power') != power:
                continue
            unit_type = info.get('type', 'A')
            unit_coast = info.get('coast', '')

            # --- first adjacency: q = potential attack target ---------------
            for q in state.get_adjacent_provinces(p):
                if not state.can_reach_by_type(p, q, unit_type, unit_coast):
                    continue
                # Gate 1: g_top_reach_flag[q] == 1
                if int(state.g_top_reach_flag[q]) != 1:
                    continue
                # Gate 2: q is in this power's SC-ownership region
                if int(state.g_sc_ownership[power, q]) != 1:
                    continue
                # Gate 3: ordered-set node value == g_MaxProvinceScore[power, q].
                # C checks lo+hi int64 fields (lines 110-111); hi-word is always 0
                # for non-negative scores, so this reduces to a single float compare.
                if state.fss(power, q, unit_type) != float(state.g_max_prov_score_per_power[power, q]):
                    continue

                # --- second adjacency: r = potential supporter province -----
                # C does not walk the province-only adjacency here: after
                # canonicalising q's token key it calls
                # AdjacencyList_FilterByUnitType again.  Keep the same moving
                # unit channel across the complete p-q-r-p triangle.
                for r in state.get_adjacent_provinces(q):
                    if not state.can_reach_by_type(q, r, unit_type):
                        continue
                    # Supporter must be on own SC territory
                    if int(state.g_sc_ownership[power, r]) != 1:
                        continue
                    # r != p (C line 155: piVar6[3] != local_2c)
                    if r == p:
                        continue

                    # --- third adjacency: s; if s == p the triangle closes ---
                    if state.can_reach_by_type(r, p, unit_type):
                        state.g_support_opportunities_set.append({
                            'power':           power,
                            'score':           float(state.g_max_province_score[q]),
                            'mover_prov':      p,   # U source (p)
                            'target_prov':     q,   # U destination (q)
                            'supporter_prov':  r,   # W position (r)
                            # C retains edge coast tokens in the record.  Python
                            # consumers use province identity and re-check the
                            # actual supporter's coast before emitting an order.
                        })

    # C stores entries in a BST keyed on score (ScoreSupportOpp.c).  Consumers
    # iterate in BST in-order (ascending) but the first match per supporter wins
    # in trial.py — so descending sort gives highest-scored opportunity priority.
    state.g_support_opportunities_set.sort(key=lambda e: e['score'], reverse=True)


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

    # ── Section 2 — Occupancy check (C lines 66-104) ──────────────────────
    # Province record: byte at offset 3 = the SUPPLY-CENTRE flag (NOT
    # occupancy — see project_scoring_pipeline; ComputeBuildDelta uses the
    # identical test to tally each power's centres).  ushort at offset 0x20 =
    # (hi='A' if Army)(lo=power_idx).  The corrected decision tree is spelled
    # out at the gate below.
    # CORRECTED 2026-08-25.  The comment above read province-record byte +3 as
    # OCCUPANCY; it is the SUPPLY-CENTRE flag -- established in
    # project_scoring_pipeline, where ComputeBuildDelta uses the identical test
    # `pbVar5[-0x1d] != 0` to build each power's centre tally.  So C's decision
    # tree here is about SUPPLY CENTRES, not about who is standing where:
    #
    #   src NOT a supply centre                      -> LAB_00441475 (score)
    #   src IS a supply centre:
    #       own ARMY on src                          -> LAB_00441475 (score)
    #       else, dst NOT a supply centre            -> LAB_0044150f (skip)
    #       else, dst IS a supply centre:
    #           own ARMY on dst                      -> LAB_0044150f (skip)
    #           else                                 -> LAB_00441475 (score)
    #
    # (Both unit tests downgrade a non-army occupant to the 0x14 sentinel
    # first, C:86-89 and :98-101 -- finding 13 in project_port_audit_patterns.)
    # The port gated on occupancy instead, which is why supports came out at
    # 66 against Albert's 111.
    if go_to_score and src_prov in state.sc_provinces:
        _su = state.unit_info.get(src_prov)
        _src_own_army = (_su is not None
                         and _su.get('type', 'A') in ('A', 'AMY')
                         and int(_su.get('power', -1)) == power_idx)
        if not _src_own_army:
            if dst_prov not in state.sc_provinces:
                go_to_score = False
            else:
                _du = state.unit_info.get(dst_prov)
                _dst_own_army = (_du is not None
                                 and _du.get('type', 'A') in ('A', 'AMY')
                                 and int(_du.get('power', -1)) == power_idx)
                if _dst_own_army:
                    go_to_score = False

    # ── LAB_00441475 — Score threshold and SUP assignment ──────────────────
    if go_to_score:
        # Scores from Albert.final_score_set[power] (this+pow*0xc+0x4000)
        # The destination lookup uses the source unit's token/coast (the stack
        # word immediately after param_3), not the unit occupying destination.
        _st = (state.unit_info.get(src_prov) or {}).get('type')
        score_dst = state.fss(power_idx, dst_prov, _st)
        score_src = state.fss(power_idx, src_prov, _st)
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

        # g_own_reach_score (DAT_0058f8e8)[(dst+pow*0x40)*2] — own unit reach count at dst
        # g_sc_ownership[pow,dst] gates the two branches (C line 114 / 116):
        #   branch 1: reach > 1 (>=2) AND dst NOT own-SC
        #   branch 2: reach > 2 (>=3) AND dst IS own-SC
        # Both branches also require DAT_00520cec == 0 (hi-word of pressure;
        # always true for non-negative int32 values → elided)
        threat = int(state.g_own_reach_score[power_idx, dst_prov])
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
                if a == src_prov and int(state.g_coverage_flag[w_power, src_prov]) == 1:
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
                                # C line 239: FUN_00465f30(local_e0, &SUB) — bare
                                # SUB token queued for broadcast (receiver HUHs it;
                                # purpose is the g_xdo_press_sent flag + history record).
                                state.g_xdo_press_proposals.append({
                                    'type':       'SUB_HANDSHAKE',
                                    'key':        key,
                                    'to_power':   u2_info['power'],
                                    'from_power': power_idx,
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
                                    rec['priority'] = rec['score']
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
                            'type':         'XDO_SUP',
                            'power':        power_idx,
                            'province':     own_prov,
                            'score':        priority,
                            'priority':     priority,
                            'target_power': unit2_power,
                            'src_prov':     own_prov,
                            'dst_prov':     dest,
                            'supporter_prov': unit2_prov,
                            'supporter_power': unit2_power,
                            'mover_prov':   own_prov,
                            'dest':         dest,
                            'from_power':   power_idx,
                            'to_power':     unit2_power,
                        })


def build_order_sup_mto(
    state: InnerGameState,
    power_idx: int,
    supporter: int,
    mover: int,
    target: int,
) -> None:
    """Port of BuildOrder_SUP_MTO (Source/moves/BuildOrder_SUP_MTO.c).

    Commits a SUP_MTO order for *supporter* covering *mover*'s attack on
    *target*, then runs three side-effect passes:

      1. Order-table setup (C L26-44): writes order type, mover/target
         provinces, score fields, and registers the convoy fleet.
      2. Trust-tier gate (C L45-59): when the mover belongs to a different
         power, classifies the relationship into one of three tiers:
           A (trust == 0)  → g_support_trust_adj = 30
           B (trust 1-4)   → g_support_trust_adj = 10
           C (trust >= 5)  → g_support_trust_adj = -10
         and sets g_convoy_active_flag[target] = 1.
      3. Chain-robustness scan (C L62-196): threat gate (g_threat_level vs
         g_enemy_reach_score) → per-qualifying-unit adjacency walk tracking
         b1/b2/b3/b7 → chain_ok determination.
         Outcome: bump target's _F_INCOMING_MOVE (chain ok, with optional
         2-point g_proximity_score boost when b3 fires) or
         _F_SUP_CHAIN_CONFLICT (chain cut).

    Parameters mirror the C: supporter=param_2, mover=param_3, target=param_4.
    """
    # Guard: unit already carries an order
    if int(state.g_order_table[supporter, _F_ORDER_TYPE]) != 0:
        return

    # ── Order-table setup (C L26-44) ──────────────────────────────────────
    state.g_order_table[supporter, _F_ORDER_TYPE]    = float(_ORDER_SUP_MTO)
    state.g_order_table[supporter, _F_SECONDARY]     = float(mover)
    state.g_order_table[supporter, _F_DEST_PROV]     = float(target)
    state.g_order_table[supporter, _F_INCOMING_MOVE] = 1.0

    score_lo = state.fss(power_idx, supporter,
                         (state.unit_info.get(supporter) or {}).get('type'))
    state.g_convoy_chain_score[supporter]            = score_lo
    state.g_order_table[supporter, _F_CONVOY_LO]     = score_lo
    state.g_order_table[supporter, _F_CONVOY_HI]     = 0.0
    state.g_order_score_hi[supporter]                = 0.0

    if state.unit_info.get(supporter, {}).get('type') == 'A':
        state.g_order_table[supporter, 24] = 0.0
        state.g_order_table[supporter, 25] = 0.0

    from .convoy import register_convoy_fleet  # deferred: convoy.py imports support.py
    register_convoy_fleet(state, power_idx, supporter)

    # ── Trust-tier gate (C L45-59) ────────────────────────────────────────
    # Fires when the mover belongs to an ally rather than power_idx itself.
    # DAT_00633f14 = g_support_trust_adj; g_ConvoyActiveFlag[target] = 1.
    mover_power = state.unit_info.get(mover, {}).get('power', power_idx)
    if mover_power != power_idx:
        trust_lo = float(state.g_ally_trust_score[power_idx, mover_power])
        trust_hi = int(state.g_ally_trust_score_hi[power_idx, mover_power])
        if trust_lo == 0.0 and trust_hi == 0:
            state.g_support_trust_adj = 30          # tier A: zero trust
        elif trust_hi < 1 and (trust_hi < 0 or trust_lo < 5):
            state.g_support_trust_adj = 10          # tier B: low trust (1-4)
        else:
            state.g_support_trust_adj = -10         # tier C: established (>=5)
        state.g_convoy_active_flag[target] = 1

    # ── Chain-robustness scan (C L62-196) ────────────────────────────────
    # Threat gate (C L63-64): DAT_005460e8 = g_threat_level vs g_enemy_reach_score.
    threat = int(state.g_threat_level[power_idx, supporter])
    er     = int(state.g_enemy_reach_score[power_idx, supporter])
    # Unlike BuildOrder_SUP_HLD.c:57, BuildOrder_SUP_MTO.c:62 has no
    # "threat == 0 → success" short-circuit: it runs the chain scan whenever
    # threat equals enemy-reach, and 0 == 0 is the common case.  The
    # short-circuit was copied over from the SUP_HLD port; removed 2026-08-12.
    if threat != er:
        state.g_order_table[target, _F_SUP_CHAIN_CONFLICT] += 1.0
        return

    chain_ok = True   # bVar15
    b3       = False  # threat-delta flag; value from last qualifying unit (C semantics)

    for this_prov, this_unit in state.unit_info.items():
        # Unit gate: enemy_presence (DAT_004f6ce8) OR established_ally_flag (DAT_0050bce8)
        ep_flag = int(state.g_enemy_presence[power_idx, this_prov]) == 1
        ea_flag = int(state.g_established_ally_flag[power_idx, this_prov]) == 1
        if not (ep_flag or ea_flag):
            continue

        # C resets bVar1..bVar7 at LAB_00440fce for each qualifying unit.
        b1 = False   # some adj == supporter
        b2 = False   # some adj == target OR this_prov == target
        b3 = False   # adj==mover AND this_prov==target AND g_threat_level delta==1
        b7 = False   # sister-supporter on own SC covering same target

        unit_type = this_unit.get('type', 'A')
        adjs = [p for p in state.adj_matrix.get(this_prov, [])
                if state.can_reach_by_type(this_prov, p, unit_type)]

        for adj_prov in adjs:
            # bVar1 (C L117-119)
            if adj_prov == supporter:
                b1 = True
            # bVar2 (C L120-125): adj==target OR unit-is-at-target
            if adj_prov == target or this_prov == target:
                b2 = True
            # bVar3 (C L129-136): adj==mover, unit-at-target, threat-delta==1
            if adj_prov == mover and this_prov == target:
                unit_power = this_unit.get('power', 0)
                # C reads g_ThreatScore[unit.power * 0x100 + adj], the
                # per-power coverage counter built by ScoreProvinces Section 2
                # — bound here as g_coverage_flag.  g_threat_level is
                # DAT_005460e8, a different array with a different stride.
                t_sc   = int(state.g_coverage_flag[unit_power, mover])
                base_sc = int(state.g_order_table[target, _F_INCOMING_MOVE])
                if t_sc - base_sc == 1:
                    b3 = True
            # bVar7 (C L141-167): sister-supporter on own SC with SUP_MTO→target
            if (adj_prov != supporter
                    and adj_prov != target
                    and this_prov != target
                    and int(state.g_sc_ownership[power_idx, adj_prov]) == 1
                    and int(state.g_order_table[adj_prov, _F_ORDER_TYPE]) == _ORDER_SUP_MTO
                    and int(state.g_order_table[adj_prov, _F_DEST_PROV]) == target
                    and int(state.g_order_table[adj_prov, _F_THREAT_TOTAL]) == 1):
                b7 = True

        # Post-check for b7 (C L172-183): discard unless supporter's field-16 == 1;
        # if field-16 == 2 AND b1 AND b2 → skip this unit's conflict check entirely.
        if b7:
            sup_f16 = int(state.g_order_table[supporter, _F_THREAT_TOTAL])
            if sup_f16 != 1:
                if sup_f16 == 2 and b1 and b2:
                    continue
                b7 = False

        if b1 and not b2 and not b7:
            chain_ok = False

    # ── Outcome bump (C L198-220) ─────────────────────────────────────────
    if chain_ok:
        state.g_order_table[target, _F_INCOMING_MOVE] += 1.0
        # bVar3 proximity boost (C L202-207): enemy at target exerts exactly
        # one net threat on mover → add 2 to g_proximity_score[target_power, mover].
        if b3:
            target_unit = state.unit_info.get(target)
            if target_unit is not None:
                t_power = target_unit.get('power', 0)
                state.g_proximity_score[t_power, mover] += 2
    else:
        state.g_order_table[target, _F_SUP_CHAIN_CONFLICT] += 1.0


def build_order_sup_hld(
    state: InnerGameState,
    power_idx: int,
    src_prov: int,
    dst_prov: int,
) -> None:
    """Port of BuildOrder_SUP_HLD (Source/moves/BuildOrder_SUP_HLD.c).

    Registers a hold-support order (type 3) for the unit at *src_prov*
    covering the unit at *dst_prov*, then runs three passes absent from the
    older assign_support_order path:

      1. Order-table setup (C L27-38): writes type=SUP_HLD, dest=dst_prov,
         score fields, clears coast fields for armies, calls RegisterConvoyFleet.

      2. Trust-tier gate (C L39-53): fires when dst unit belongs to an ally.
         Classifies the trust relationship into A/B/C and writes
         g_support_trust_adj (DAT_00633f14) + g_convoy_active_flag[dst_prov].
           A (trust == 0)  → g_support_trust_adj = 30
           B (trust 1-4)   → g_support_trust_adj = 10
           C (trust ≥ 5)   → g_support_trust_adj = −10

      3. Chain-robustness scan (C L55-188): threat gate (g_threat_level vs
         g_enemy_reach_score) then a per-qualifying-unit adjacency walk.
         For each unit where g_enemy_presence or g_established_ally_flag
         is 1 at (power_idx, unit.prov), walks the type-filtered adjacency
         list tracking:
           bVar2 — some adj == src_prov
           bVar3 — some adj == dst_prov
           bVar8 — an adjacent own-SC province has a confirmed SUP_HLD to dst
         If bVar2 AND NOT bVar3 AND NOT bVar8: abort flag fires.

    Outcome:
      Normal  → state.g_order_table[dst_prov, _F_INCOMING_MOVE] += 1
      Aborted → state.g_order_table[dst_prov, _F_SUP_CHAIN_CONFLICT] += 1
    """
    if int(state.g_order_table[src_prov, _F_ORDER_TYPE]) != 0:
        return

    # ── Order-table setup (C L27-38) ─────────────────────────────────────
    state.g_order_table[src_prov, _F_ORDER_TYPE]    = float(_ORDER_SUP_HLD)
    state.g_order_table[src_prov, _F_DEST_PROV]     = float(dst_prov)
    state.g_order_table[src_prov, _F_INCOMING_MOVE] = 1.0

    score_lo = state.fss(power_idx, src_prov,
                         (state.unit_info.get(src_prov) or {}).get('type'))
    state.g_convoy_chain_score[src_prov]         = score_lo
    state.g_order_table[src_prov, _F_CONVOY_LO]  = score_lo
    state.g_order_table[src_prov, _F_CONVOY_HI]  = 0.0
    state.g_order_score_hi[src_prov]             = 0.0

    if state.unit_info.get(src_prov, {}).get('type') == 'A':
        state.g_order_table[src_prov, 24] = 0.0
        state.g_order_table[src_prov, 25] = 0.0

    from .convoy import register_convoy_fleet
    register_convoy_fleet(state, power_idx, src_prov)

    # ── Trust-tier gate (C L39-53) ────────────────────────────────────────
    # Fires when the unit being supported belongs to a different power.
    dst_unit = state.unit_info.get(dst_prov)
    if dst_unit is not None and dst_unit.get('power', power_idx) != power_idx:
        dst_power = dst_unit['power']
        trust_lo  = float(state.g_ally_trust_score[power_idx, dst_power])
        trust_hi  = int(state.g_ally_trust_score_hi[power_idx, dst_power])
        if trust_lo == 0.0 and trust_hi == 0:
            state.g_support_trust_adj = 30      # tier A: no trust
        elif trust_hi < 1 and (trust_hi < 0 or trust_lo < 5):
            state.g_support_trust_adj = 10      # tier B: low trust (1–4)
        else:
            state.g_support_trust_adj = -10     # tier C: established (≥5)
        state.g_convoy_active_flag[dst_prov] = 1

    # ── Chain-robustness scan (C L55-188) ────────────────────────────────
    # DAT_005460e8 = g_threat_level (max enemy reach per power/prov).
    threat = int(state.g_threat_level[power_idx, src_prov])
    if threat == 0:
        # C: threat == 0 → skip unit walk, proceed directly to success bump.
        state.g_order_table[dst_prov, _F_INCOMING_MOVE] += 1.0
        return

    er = int(state.g_enemy_reach_score[power_idx, src_prov])
    if threat != er:
        state.g_order_table[dst_prov, _F_SUP_CHAIN_CONFLICT] += 1.0
        return

    chain_ok = True   # bVar13

    for this_prov, this_unit in state.unit_info.items():
        # Gate: enemy_presence (DAT_004f6ce8) OR established_ally_flag (DAT_0050bce8)
        ep_flag = int(state.g_enemy_presence[power_idx, this_prov]) == 1
        ea_flag = int(state.g_established_ally_flag[power_idx, this_prov]) == 1
        if not (ep_flag or ea_flag):
            continue

        unit_type = this_unit.get('type', 'A')
        adjs = [p for p in state.adj_matrix.get(this_prov, [])
                if state.can_reach_by_type(this_prov, p, unit_type)]

        bVar2 = False   # some adj == src_prov
        bVar3 = False   # some adj == dst_prov
        bVar8 = False   # flanking own SUP_HLD to dst confirmed

        for adj_prov in adjs:
            if adj_prov == src_prov:
                bVar2 = True
            if adj_prov == dst_prov:
                bVar3 = True
            # C L127-155: flanking support check — own SC province with
            # confirmed SUP_HLD pointing at dst_prov and field-16 == 1.
            if (adj_prov != src_prov
                    and adj_prov != dst_prov
                    and int(state.g_sc_ownership[power_idx, adj_prov]) == 1
                    and int(state.g_order_table[adj_prov, _F_ORDER_TYPE]) == _ORDER_SUP_HLD
                    and int(state.g_order_table[adj_prov, _F_DEST_PROV]) == dst_prov
                    and int(state.g_order_table[adj_prov, _F_THREAT_TOTAL]) == 1):
                bVar8 = True

        # C L158-171: bVar8 re-evaluated against src's field-16 slot value.
        if bVar8:
            src_f16 = int(state.g_order_table[src_prov, _F_THREAT_TOTAL])
            if src_f16 == 1:
                pass    # bVar8 confirmed
            elif src_f16 == 2 and bVar2 and bVar3:
                continue  # goto next unit without testing abort
            else:
                bVar8 = False
        else:
            bVar8 = False

        if bVar2 and not bVar3 and not bVar8:
            chain_ok = False

    if chain_ok:
        state.g_order_table[dst_prov, _F_INCOMING_MOVE] += 1.0
    else:
        state.g_order_table[dst_prov, _F_SUP_CHAIN_CONFLICT] += 1.0
