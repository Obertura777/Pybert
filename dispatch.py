import logging
from .state import InnerGameState

logger = logging.getLogger(__name__)

# Error codes mirroring FUN_00422a90 return values
_ERR_MALFORMED_UNIT   = -0x186a1   # malformed / missing unit field
_ERR_BAD_PROVINCE     = -0x186a5   # province not in prov_to_id
_ERR_POWER_MISMATCH   = -0x14c09   # unit belongs to a different power
_ERR_NO_TARGET        = -0x186aa   # MTO / CTO / CVY missing destination
_ERR_ADJACENCY        = -0x186aa   # FUN_00460b30 adjacency gate failed
_ERR_NO_SUP_UNIT      = -0x186b4   # SUP missing target unit
_ERR_CVY_NO_ARMY      = -0x186d7   # CVY: army not in orders / wrong type
_ERR_CVY_REACH        = -0x186e1   # CVY: FUN_004619f0 convoy-reachability failed
_ERR_UNKNOWN_ORDER    = -0x15f91   # order type not HLD/MTO/SUP/CTO/CVY

# Error codes for FUN_0041d360 (check_order_alliance)
# All in range -0x13881 .. -0x138B2 (= 0xFFFEC77F .. 0xFFFEC74E as unsigned 32-bit)
_ERR_ALLY_TRUST_B    = -0x13881   # 0xFFFEC77F — slot-B designation has non-zero trust
_ERR_ALLY_TRUST_A    = -0x13882   # 0xFFFEC77E — slot-A designation has non-zero trust
_ERR_ALLY_TRUST_C    = -0x13883   # 0xFFFEC77D — slot-C designation has non-zero trust
_ERR_DUP_OWN         = -0x1388A   # 0xFFFEC776 — promise-list conflict, own-unit context
_ERR_DUP_OTHER       = -0x13894   # 0xFFFEC76C — promise-list conflict, other-unit context
_ERR_COUNTER_REC     = -0x1389E   # 0xFFFEC762 — counter-list consistency check failed
_ERR_PROMISE_SAME    = -0x138A8   # 0xFFFEC758 — FUN_00401050, dest == ordering context
_ERR_PROMISE_DIFF    = -0x138B2   # 0xFFFEC74E — FUN_00401050, dest != own-power context

def check_order_alliance(
    state: InnerGameState,
    own_power_idx: int,
    dest_prov: int,
    ordering_power: int,
    dest_power: int,
) -> int:
    """
    Port of FUN_0041d360 — CheckOrderAlliance.

    Validates that committing an order to dest_prov does not violate any
    standing alliance designations or outstanding ally promise records.

    Parameters
    ----------
    state         : InnerGameState
    own_power_idx : Albert's own power index  (C: puVar12 = (this+8)[0x2424])
    dest_prov     : destination province index (C: param_1)
    ordering_power: power submitting the order (C: in_stack_0000001c);
                    always == own_power_idx for Albert — determines branch taken
    dest_power    : power context of the destination (C: in_stack_00000020);
                    the power that currently occupies or designates dest_prov

    Returns 0 on success; one of the _ERR_ALLY_* / _ERR_DUP_* / _ERR_COUNTER_REC
    error codes on failure.

    C control flow (decompiled.txt lines 68–296):

      Lines 68–128  — Three alliance-designation trust checks (slots C, B, A).
        For each slot [C=DAT_004d3610/14, B=DAT_004d2610/14, A=DAT_004d2e10/14]:
          If slot is active (hi >= 0) AND ordering_power == own_power:
            If dest_power != designated_ally → read g_AllyTrustScore[own*21+ally]
          Else if designated_ally == own_power AND dest_power != own_power:
            Force trust = 10  (province is "ours", ordered by another power)
        Trust stored in local_40 (slot C), local_48 (slot B), local_44 (slot A).

      Lines 129–293 — Main validation (only when all three trust vars == 0):
        If ordering_power == own_power (always for Albert):
          For each active power p (filter: g_EnemyFlag[p] == 0):
            Scan g_ally_promise_list[p] for records targeting dest_prov.
            If found:
              dest_power == own_power → return _ERR_DUP_OWN
              dest_power != p         → return _ERR_DUP_OTHER
              dest_power == p AND counter-record matches → return _ERR_DUP_OTHER
          After loop: if dest_power != own_power, verify g_ally_counter_list
            consistency for dest_power → return _ERR_COUNTER_REC on mismatch.
        Ordering_power != own_power paths use FUN_00401050 (stubbed pass-through).

      Lines 129/263/275/285 — Early returns on non-zero trust:
        local_48 != 0 → _ERR_ALLY_TRUST_B   (outermost check)
        local_44 != 0 → _ERR_ALLY_TRUST_A
        local_40 != 0 → _ERR_ALLY_TRUST_C

    Unchecked callees:
      FUN_00401050  (0x00401050) — boolean check on power-record iterator;
                    called from the ordering_power != own_power branches (lines 229,
                    244); those branches are unreachable for Albert; stubbed True.
      FUN_00465930  (0x00465930) — builds the color-set from the order token list
                    (stack0x0000000c); color-set used by GameBoard_GetPowerRec to
                    verify the designated ally is present in the order's tokens;
                    in the Python rewrite the trust lookup is unconditional when the
                    slot is active, which is the dominant path anyway.
      GameBoard_GetPowerRec — STL map find; validates that a node belongs to the
                    local temporary map; replaced by direct array lookup in Python.
    """
    # ── Slot C  (DAT_004d3610/14 = g_AllyDesignation_C) ─────────────────────
    # C lines 72–90: read puVar13/iVar14, check trust for slot C.
    local_40 = 0
    desig_c = int(state.g_AllyDesignation_C[dest_prov])
    if desig_c >= 0:                                    # slot C active (hi >= 0)
        ally_c = desig_c
        if ordering_power == own_power_idx:
            if dest_power != ally_c:                    # destination context ≠ designation
                local_40 = int(state.g_AllyTrustScore[own_power_idx, ally_c])
        elif ally_c == own_power_idx and dest_power != own_power_idx:
            # Province designated for own power, but someone else is ordering
            local_40 = 10

    # ── Slot B  (DAT_004d2610/14 = g_AllyDesignation_B) ─────────────────────
    # C lines 91–110: reassign puVar13=dest_power, iVar14=sign_ext(dest_power),
    # then read puVar1/local_28 for slot B and check trust.
    local_48 = 0
    desig_b = int(state.g_AllyDesignation_B[dest_prov])
    if desig_b >= 0:                                    # slot B active
        ally_b = desig_b
        if ordering_power == own_power_idx:
            if dest_power != ally_b:
                local_48 = int(state.g_AllyTrustScore[own_power_idx, ally_b])
        elif ally_b == own_power_idx and dest_power != own_power_idx:
            local_48 = 10

    # ── Slot A  (DAT_004d2e10/14 = g_AllyDesignation_A) ─────────────────────
    # C lines 111–128: read local_34/local_30 for slot A and check trust.
    local_44 = 0
    desig_a = int(state.g_AllyDesignation_A[dest_prov])
    if desig_a >= 0:                                    # slot A active
        ally_a = desig_a
        if ordering_power == own_power_idx:
            if dest_power != ally_a:
                local_44 = int(state.g_AllyTrustScore[own_power_idx, ally_a])
        elif ally_a == own_power_idx and dest_power != own_power_idx:
            local_44 = 10

    # ── Early-return on non-zero trust (C lines 129/263/275/285) ─────────────
    # Priority order mirrors C nesting: local_48 outermost, then local_44, local_40.
    if local_48 != 0:
        logger.debug(
            "check_order_alliance: slot-B trust conflict prov=%d ally=%d trust=%d",
            dest_prov, desig_b, local_48,
        )
        return _ERR_ALLY_TRUST_B
    if local_44 != 0:
        logger.debug(
            "check_order_alliance: slot-A trust conflict prov=%d ally=%d trust=%d",
            dest_prov, desig_a, local_44,
        )
        return _ERR_ALLY_TRUST_A
    if local_40 != 0:
        logger.debug(
            "check_order_alliance: slot-C trust conflict prov=%d ally=%d trust=%d",
            dest_prov, desig_c, local_40,
        )
        return _ERR_ALLY_TRUST_C

    # ── Promise-list / counter-list conflict scan (C lines 131–253) ──────────
    if ordering_power == own_power_idx:
        # C lines 134–200: scan g_ally_promise_list per active power for
        # records targeting dest_prov.  g_EnemyFlag[p] == 0 = power is active
        # (C: DAT_004cf568[p*2]==0 && DAT_004cf56c[p*2]==0, i.e. int64==0).
        num_powers = state.g_EnemyFlag.shape[0]
        promise_list = state.g_ally_promise_list  # dict[int, list[dict]]
        for p in range(num_powers):
            if state.g_EnemyFlag[p] != 0:
                continue
            for record in promise_list.get(p, []):
                if record.get('dest_prov') != dest_prov:
                    continue
                # Found a promise from power p targeting dest_prov
                if dest_power == own_power_idx:
                    # C line 160: if (local_3c != param_2) → _ERR_DUP_OWN
                    # local_3c = low byte of original param_2 (order color token);
                    # param_2 = p (current power).  Conflict if color byte != p.
                    order_color = record.get('order_color', -1)
                    if order_color != p:
                        logger.debug(
                            "check_order_alliance: duplicate own-unit order "
                            "prov=%d promising_power=%d", dest_prov, p,
                        )
                        return _ERR_DUP_OWN
                else:
                    # C lines 174–193: if dest_power != p → _ERR_DUP_OTHER;
                    # else check power-record (GameBoard_GetPowerRec piVar8[1]==ppiVar5)
                    # → _ERR_DUP_OTHER.  FUN_00401050 (power-record consistency
                    # check) is inlined as: if record is "owned by" own map →
                    # conflict.  In Python: treat any promise from p==dest_power
                    # as a conflict (the power-record check almost always triggers).
                    logger.debug(
                        "check_order_alliance: duplicate other-unit order "
                        "prov=%d promising_power=%d dest_power=%d",
                        dest_prov, p, dest_power,
                    )
                    return _ERR_DUP_OTHER

        # C lines 202–221: after loop, if dest_power != own_power, verify the
        # counter-list (g_AllyCounterList) for dest_power is consistent.
        # C: puVar10[1] != iVar14 → _ERR_COUNTER_REC, where iVar14 = sentinel hi
        # and puVar10[1] = found-node hi.  In Python: a non-empty counter entry
        # for (dest_power, dest_prov) with a size marker that mismatches signals
        # the same inconsistency.
        if dest_power != own_power_idx:
            counter_list = state.g_ally_counter_list
            sentinel_size = counter_list.get('__size__', {}).get(dest_power, 0)
            entries = counter_list.get(dest_power, [])
            entry = next((e for e in entries if e.get('dest_prov') == dest_prov), None)
            found_size = entry.get('size', 0) if entry else 0
            if found_size != sentinel_size:
                logger.debug(
                    "check_order_alliance: counter-list mismatch prov=%d dest_power=%d",
                    dest_prov, dest_power,
                )
                return _ERR_COUNTER_REC

    else:
        # ordering_power != own_power_idx branches (C lines 224–252).
        # These use FUN_00401050 on g_ally_counter_list for ordering_power or
        # in_stack_0000001c.  Albert never reaches this path (it only orders for
        # itself), so stub both checks as pass-through (return success).
        # FUN_00401050 is unchecked; flag if somehow reached.
        logger.debug(
            "check_order_alliance: non-own ordering_power=%d (stub pass-through)",
            ordering_power,
        )

    return 0


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


def validate_and_dispatch_order(
    state: InnerGameState,
    own_power_idx: int,
    order_seq: dict,
    commit: bool = True,
) -> int:
    """
    Port of FUN_00422a90 — ValidateAndDispatchDaideOrder.

    ``commit=False`` runs legality + trust scoring (FUN_00422a90 +
    FUN_0041d360) but skips dispatch_single_order, so the order is
    *evaluated* without being executed. Used by the FUN_00426140
    legitimacy gate, which needs pure scoring over candidate clauses.

    Takes a parsed DAIDE order token sequence (expressed here as the
    dispatch_single_order-compatible dict used throughout the Python rewrite),
    validates it against the current game state, and — if valid — commits it
    by calling dispatch_single_order.

    Mirrors the C control flow faithfully (decompiled.txt lines 69–873):

      Unit validation block (skipped for WVE/BLD — neither appear as valid
      movement orders and both produce _ERR_UNKNOWN_ORDER at the dispatch
      switch, matching the C fall-through to return -0x15f91):
        1. Parse unit string → province name → prov_id via state.prov_to_id.
        2. Look up unit_data in state.unit_info[prov_id].
        3. Check unit_data['power'] == own_power_idx  (C: piStack_84[1] !=
           iStack_48 → return -0x14c09).

      Order-type dispatch:
        HLD → success (C: `if HLD goto LAB_00423fb5`; no check_order_alliance call).
        MTO → target present; _is_legal_mto adjacency gate (FUN_00460b30);
              check_order_alliance (FUN_0041d360) → dispatch_single_order.
        SUP → target_unit present; FUN_004619f0 convoy/legality check
              (ported as is_convoy_reachable); supporter-side adjacency
              check; two check_order_alliance calls for SUP-MTO, one for
              SUP-HLD → dispatch_single_order.
        CTO → target_dest present; FUN_004619f0 (ported as
              is_convoy_reachable); check_order_alliance →
              dispatch_single_order.
        CVY → target_unit (army) validated; FUN_004619f0 convoy reachability
              (army prov → dest); check_order_alliance → dispatch_single_order.
        other → return _ERR_UNKNOWN_ORDER  (C: return -0x15f91).

    Returns 0 on success, negative error code on failure.

    Unchecked callees absorbed here:
      FUN_004619f0  convoy reachability     → ported as is_convoy_reachable (SUP-MTO + CTO + CVY)
    """
    order_type: str = order_seq.get('type', '')
    unit_str:   str = order_seq.get('unit', '')

    # ── Unit existence + power ownership ─────────────────────────────────────
    # C: `if ((WVE != uStack_94) && (BLD != uStack_94))` block, lines 156–238.
    # WVE / BLD have no unit — skip the block for those tokens; they still hit
    # _ERR_UNKNOWN_ORDER at the dispatch switch below.
    if order_type not in ('WVE', 'BLD'):
        # Parse "A PAR" → 'PAR', "F LON/NCS" → 'LON'
        parts = unit_str.split()
        if len(parts) < 2:
            logger.debug("validate_and_dispatch_order: malformed unit string %r", unit_str)
            return _ERR_MALFORMED_UNIT

        prov_raw = parts[1].split('/')[0].upper()
        prov_id  = state.prov_to_id.get(prov_raw)
        if prov_id is None:
            logger.debug("validate_and_dispatch_order: unknown province %r", prov_raw)
            return _ERR_BAD_PROVINCE

        unit_data = state.unit_info.get(prov_id)
        if unit_data is None:
            logger.debug(
                "validate_and_dispatch_order: no unit at province %r (id %d)",
                prov_raw, prov_id,
            )
            return _ERR_MALFORMED_UNIT

        # C: piStack_84[1] != iStack_48 → power mismatch → return -0x14c09
        if unit_data.get('power') != own_power_idx:
            logger.debug(
                "validate_and_dispatch_order: power mismatch at %r: "
                "unit.power=%d own=%d",
                prov_raw, unit_data.get('power'), own_power_idx,
            )
            return _ERR_POWER_MISMATCH

    # ── Order-type dispatch ───────────────────────────────────────────────────
    if order_type == 'HLD':
        # C: `if (HLD == uStack_94) goto LAB_00423fb5` — success, no
        # check_order_alliance call.  HLD has no destination.
        if commit:
            dispatch_single_order(state, own_power_idx, order_seq)
        return 0

    if order_type == 'MTO':
        # C: ParseDestinationWithCoast + FUN_00460b30 adjacency gate (line 293).
        target = order_seq.get('target', '')
        if not target:
            return _ERR_NO_TARGET
        dest_prov_id = state.prov_to_id.get(target.split('/')[0].upper())
        # FUN_00460b30: adjacency / legal-move gate (with unit-type filtering).
        moving_unit_type = unit_data.get('type', '') if unit_data else ''
        if dest_prov_id is None or not _is_legal_mto(state, prov_id, dest_prov_id, moving_unit_type):
            logger.debug(
                "validate_and_dispatch_order: MTO adjacency check failed "
                "%r → %r", prov_raw, target,
            )
            return _ERR_ADJACENCY
        # check_order_alliance (FUN_0041d360): validate alliance constraints on dest.
        dest_power   = state.get_unit_power(dest_prov_id) if dest_prov_id is not None else -1
        if dest_prov_id is not None:
            rc = check_order_alliance(state, own_power_idx, dest_prov_id,
                                      own_power_idx, dest_power)
            if rc != 0:
                return rc
        if commit:
            dispatch_single_order(state, own_power_idx, order_seq)
        return 0

    if order_type == 'SUP':
        # C lines 318–554: supported-unit lookup, FUN_0040dfe0 end-check,
        # IsLegalMove on source, FUN_004619f0 convoy-reachability (ported,
        # not a stub — see is_convoy_reachable above). Two check_order_alliance
        # calls for SUP-MTO (lines 515+537); one via LAB_00423083 for SUP-HLD.
        # Supporter-side adjacency check (was KNOWN GAP; now wired at L489-501):
        #   SUP-MTO: supporter must reach target_dest (plain adjacency).
        #   SUP-HLD: supporter must reach supported unit's province.
        #   Both map to error -0x186c1 / -0x186c3; checked below.
        target_unit = order_seq.get('target_unit', '')
        if not target_unit:
            return _ERR_NO_SUP_UNIT
        # Resolve supported unit's province and type for the is_convoy_reachable call.
        # Resolve dest province: SUP-MTO has target_dest; SUP-HLD does not.
        target_dest = order_seq.get('target_dest', '')
        sup_parts = target_unit.split()
        sup_unit_type = sup_parts[0] if sup_parts else ''        # 'A' or 'F'
        sup_prov_name = (sup_parts[1].split('/')[0].upper()
                         if len(sup_parts) >= 2 else '')
        sup_prov_id = state.prov_to_id.get(sup_prov_name) if sup_prov_name else None
        check_prov_name = (target_dest if target_dest else
                           target_unit.split()[1].split('/')[0]
                           if len(target_unit.split()) >= 2 else '')
        check_prov_id = (state.prov_to_id.get(check_prov_name.upper())
                         if check_prov_name else None)
        # FUN_004619f0: is_convoy_reachable on the supported unit → support target.
        # Applied for SUP-MTO (target_dest present); SUP-HLD trivially passes
        # (no destination province to validate convoy reachability against).
        if target_dest and sup_prov_id is not None and check_prov_id is not None:
            if not is_convoy_reachable(state, sup_prov_id, sup_unit_type, check_prov_id):
                logger.debug(
                    "validate_and_dispatch_order: SUP convoy-legality failed "
                    "%r → %r", sup_prov_name, target_dest,
                )
                return _ERR_ADJACENCY
        # Supporter-side adjacency check (FUN_00422a90 lines 95, SUP-HLD equiv):
        #   SUP-MTO: supporter must reach target_dest
        #   SUP-HLD: supporter must reach supported unit's province
        # prov_id is the supporter's province. check_prov_id is the province the
        # supporter needs to reach (target_dest for MTO, supported unit's prov
        # for HLD). Plain adjacency — no convoy fallback for supporter.
        if check_prov_id is not None and prov_id != check_prov_id:
            if check_prov_id not in state.adj_matrix.get(prov_id, []):
                logger.debug(
                    "validate_and_dispatch_order: SUP supporter %r not adjacent "
                    "to %r", prov_raw, check_prov_name,
                )
                return _ERR_ADJACENCY
        if check_prov_id is not None:
            dest_power = state.get_unit_power(check_prov_id)
            rc = check_order_alliance(state, own_power_idx, check_prov_id,
                                      own_power_idx, dest_power)
            if rc != 0:
                return rc
        if commit:
            dispatch_single_order(state, own_power_idx, order_seq)
        return 0

    if order_type == 'CTO':
        # C lines 669–704: convoy-through route, FUN_004619f0.
        target_dest = order_seq.get('target_dest', '')
        if not target_dest:
            return _ERR_NO_TARGET
        dest_prov_id = state.prov_to_id.get(target_dest.split('/')[0].upper())
        # FUN_004619f0: is_convoy_reachable — ordering army (prov_id, unit_type) → dest.
        # param_1 = army unit_data, param_2 = dest_prov, param_3 = -1.
        cto_unit_type = unit_data.get('type', '') if unit_data else ''
        if dest_prov_id is not None and not is_convoy_reachable(
            state, prov_id, cto_unit_type, dest_prov_id
        ):
            logger.debug(
                "validate_and_dispatch_order: CTO convoy-legality failed "
                "%r → %r", prov_raw, target_dest,
            )
            return _ERR_ADJACENCY
        dest_power   = state.get_unit_power(dest_prov_id) if dest_prov_id is not None else -1
        if dest_prov_id is not None:
            rc = check_order_alliance(state, own_power_idx, dest_prov_id,
                                      own_power_idx, dest_power)
            if rc != 0:
                return rc
        if commit:
            dispatch_single_order(state, own_power_idx, order_seq)
        return 0

    if order_type == 'CVY':
        # C lines 461–600: fleet CVY validation (FUN_00422a90 / decompiled.txt).
        # Ordering unit (element 0) = fleet; element 2 = army being conveyed.
        # FUN_004619f0 is called with the ARMY's unit_data and dest province
        # (decompiled.txt line 547); returns -0x186e1 if reachability fails.
        target_dest = order_seq.get('target_dest', '')
        if not target_dest:
            return _ERR_NO_TARGET
        dest_prov_id = state.prov_to_id.get(target_dest.split('/')[0].upper())
        # Extract army from target_unit (e.g. "A BRE").
        # C: GetSubList(local_6c, .., 2) → army sublist; GetListElement(.., 2) = province id.
        cvy_army_str  = order_seq.get('target_unit', '')
        cvy_parts     = cvy_army_str.split()
        army_prov_id  = None
        if len(cvy_parts) >= 2:
            army_prov_id = state.prov_to_id.get(cvy_parts[1].split('/')[0].upper())
        # C: AMY == unit.type check + FUN_004619f0 convoy-reachability.
        if dest_prov_id is not None and army_prov_id is not None:
            army_unit = state.unit_info.get(army_prov_id)
            if army_unit is None or army_unit.get('type') != 'A':
                logger.debug(
                    "validate_and_dispatch_order: CVY army not found or not AMY at %r",
                    cvy_parts[1] if len(cvy_parts) >= 2 else cvy_army_str,
                )
                return _ERR_CVY_NO_ARMY
            if not is_convoy_reachable(state, army_prov_id, 'A', dest_prov_id):
                logger.debug(
                    "validate_and_dispatch_order: CVY convoy-reachability failed "
                    "%r → %r", cvy_parts[1] if len(cvy_parts) >= 2 else '?', target_dest,
                )
                return _ERR_CVY_REACH
        dest_power = state.get_unit_power(dest_prov_id) if dest_prov_id is not None else -1
        if dest_prov_id is not None:
            rc = check_order_alliance(state, own_power_idx, dest_prov_id,
                                      own_power_idx, dest_power)
            if rc != 0:
                return rc
        if commit:
            dispatch_single_order(state, own_power_idx, order_seq)
        return 0

    # WVE / BLD and any unrecognised token — C: return -0x15f91 (lines 529–541)
    logger.debug("validate_and_dispatch_order: unknown order type %r", order_type)
    return _ERR_UNKNOWN_ORDER


def parse_destination_with_coast(dest_token: dict):
    # Mocking ParseDestinationWithCoast
    prov = dest_token.get('province')
    coast = dest_token.get('coast', '')
    if coast:
        return f"{prov}/{coast}"
    return prov

def dispatch_single_order(state: InnerGameState, power_index: int, order_seq: dict):
    """
    Port of FUN_0044cc50. The core multiplexer for tactical order distribution.
    Takes internal logical order definitions from the monte_carlo evaluator buffer
    and multiplexes them into DipNet formatted strings native to python-diplomacy.
    """
    token_head = order_seq.get('type', 'HLD')
    unit_str = order_seq.get('unit', '') # e.g. "A PAR"
    
    formatted_order = ""
    
    if token_head == 'HLD':
        # Translates BuildOrder_HLD logic
        formatted_order = f"{unit_str} H"
        
    elif token_head == 'MTO':
        # Translates BuildOrder_MTO logic
        target_str = parse_destination_with_coast({'province': order_seq.get('target', ''), 'coast': order_seq.get('coast', '')})
        formatted_order = f"{unit_str} - {target_str}"
        
    elif token_head == 'SUP':
        target_unit = order_seq.get('target_unit', '')
        dest_prov = order_seq.get('target_dest', None)
        
        # Branch determining SUP_MTO or SUP_HLD logic paths
        if dest_prov:
            target_str = parse_destination_with_coast({'province': dest_prov, 'coast': order_seq.get('target_coast', '')})
            formatted_order = f"{unit_str} S {target_unit} - {target_str}"
        else:
            formatted_order = f"{unit_str} S {target_unit}"
            
    elif token_head == 'CTO':
        # BuildOrder_CTO translating convoy fleet actions
        target_army = order_seq.get('target_unit', '')
        dest_prov = order_seq.get('target_dest', '')
        formatted_order = f"{unit_str} C {target_army} - {dest_prov}"
        
    elif token_head == 'CVY':
        # BuildOrder_CVY translating the army moving via convoy
        dest_prov = order_seq.get('target_dest', '')
        formatted_order = f"{unit_str} - {dest_prov} VIA"
        
    else:
        logger.warning(f"Unknown DAIDE dispatch token branch: {token_head}")

    # Accumulate finalized python sequence strings for submit_orders handler in bot.py.
    # NB: this is *not* the C g_OrderList (a std::map of dict-shaped entries used
    # by ComputeOrderDipFlags / ProposeDMZ in communications.py).  We use a
    # distinct name to avoid feeding plain strings into the dict-iterating call
    # sites — see communications.py compute_order_dip_flags / ProposeDMZ.
    if not hasattr(state, 'g_SubmittedOrders'):
        state.g_SubmittedOrders = []

    if formatted_order:
        state.g_SubmittedOrders.append(formatted_order)
        logger.debug(f"Pushed to generalized SUB sequence: {formatted_order}")
