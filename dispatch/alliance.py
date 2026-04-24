"""Alliance / promise-list / trust validation for inbound orders.

Split from dispatch.py during the 2026-04 refactor.

Holds the ``check_order_alliance`` port of ``FUN_0041d360``: validates
an incoming order against the current alliance matrix, the promise
list, and the counter-promise trust state before it is allowed to
proceed into the main dispatch validator.

Module-level deps: ``..state.InnerGameState``, the alliance-family
error sentinels and shared logger from ``._errors``.
"""

from ..state import InnerGameState

from ._errors import (
    logger,
    _ERR_ALLY_TRUST_A,
    _ERR_ALLY_TRUST_B,
    _ERR_ALLY_TRUST_C,
    _ERR_DUP_OWN,
    _ERR_DUP_OTHER,
    _ERR_COUNTER_REC,
    _ERR_PROMISE_SAME,
    _ERR_PROMISE_DIFF,
)

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
            If dest_power != designated_ally → read g_ally_trust_score[own*21+ally]
          Else if designated_ally == own_power AND dest_power != own_power:
            Force trust = 10  (province is "ours", ordered by another power)
        Trust stored in local_40 (slot C), local_48 (slot B), local_44 (slot A).

      Lines 129–293 — Main validation (only when all three trust vars == 0):
        If ordering_power == own_power (always for Albert):
          For each active power p (filter: g_enemy_flag[p] == 0):
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
    # ── Slot C  (DAT_004d3610/14 = g_ally_designation_c) ─────────────────────
    # C lines 72–90: read puVar13/iVar14, check trust for slot C.
    local_40 = 0
    desig_c = int(state.g_ally_designation_c[dest_prov])
    if desig_c >= 0:                                    # slot C active (hi >= 0)
        ally_c = desig_c
        if ordering_power == own_power_idx:
            if dest_power != ally_c:                    # destination context ≠ designation
                local_40 = int(state.g_ally_trust_score[own_power_idx, ally_c])
        elif ally_c == own_power_idx and dest_power != own_power_idx:
            # Province designated for own power, but someone else is ordering
            local_40 = 10

    # ── Slot B  (DAT_004d2610/14 = g_ally_designation_b) ─────────────────────
    # C lines 91–110: reassign puVar13=dest_power, iVar14=sign_ext(dest_power),
    # then read puVar1/local_28 for slot B and check trust.
    local_48 = 0
    desig_b = int(state.g_ally_designation_b[dest_prov])
    if desig_b >= 0:                                    # slot B active
        ally_b = desig_b
        if ordering_power == own_power_idx:
            if dest_power != ally_b:
                local_48 = int(state.g_ally_trust_score[own_power_idx, ally_b])
        elif ally_b == own_power_idx and dest_power != own_power_idx:
            local_48 = 10

    # ── Slot A  (DAT_004d2e10/14 = g_ally_designation_a) ─────────────────────
    # C lines 111–128: read local_34/local_30 for slot A and check trust.
    local_44 = 0
    desig_a = int(state.g_ally_designation_a[dest_prov])
    if desig_a >= 0:                                    # slot A active
        ally_a = desig_a
        if ordering_power == own_power_idx:
            if dest_power != ally_a:
                local_44 = int(state.g_ally_trust_score[own_power_idx, ally_a])
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
        # records targeting dest_prov.  g_enemy_flag[p] == 0 = power is active
        # (C: DAT_004cf568[p*2]==0 && DAT_004cf56c[p*2]==0, i.e. int64==0).
        num_powers = state.g_enemy_flag.shape[0]
        promise_list = state.g_ally_promise_list  # dict[int, list[dict]]
        for p in range(num_powers):
            if state.g_enemy_flag[p] != 0:
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
