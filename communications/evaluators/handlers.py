"""Press-action YES-branch handlers and the CAL_MOVE dispatcher.

Split from communications/evaluators.py during the 2026-04 refactor.

Holds the YES-branch handlers that actually commit the consequences of
accepted proposals, their XDO scoring helpers, and the ``cal_move``
dispatcher that routes each inbound proposal to the right handler or
NOT-branch cancellation routine.

Public names:
  * ``_handle_pce`` / ``_handle_aly`` / ``_handle_dmz`` / ``_handle_xdo``
      — YES-branch handlers (accept a proposal and update game state).
  * ``_score_support_opp`` / ``_score_sup_attacker``
      — XDO scoring helpers used by ``_handle_xdo``.
  * ``cal_move``
      — CAL_MOVE / __thiscall dispatcher: routes YES or NOT press actions
        to the appropriate handler in this slice or the cancellation slice.

Cross-module deps:
  * ``.flags.compute_order_dip_flags``       — used by ``_handle_pce``.
  * ``.cancellation`` NOT-branch handlers    — ``cal_move`` dispatches
    into ``_cancel_pce`` / ``_remove_dmz`` / ``_not_xdo``.
  * ``..state.InnerGameState``.
"""

from ...state import InnerGameState
from .flags import compute_order_dip_flags
from .cancellation import _cancel_pce, _remove_dmz, _not_xdo


def _handle_pce(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named function PCE() at address 0x0041dc10.

    Evaluates a PCE (peace) proposal from another power.  Called from
    cal_move() when the leading press token is 'PCE'.

    tokens[0] == 'PCE'; tokens[1:] == power indices included in the proposal.

    Algorithm:
      1. For every ordered pair (power_i, power_j) of PCE powers where i != j:
           - If power_i == own_power: mark power_j as PCE-applied this turn
             (g_turn_order_hist_lo[power_j] = 2).
           - Compute new trust = max(1, 3 − g_stab_counter[i,j]), capped at 3
             when _g_NearEndGameFactor >= 4.0.
           - Update g_ally_trust_score[i,j] / g_ally_trust_score_hi[i,j] if the
             new trust (as uint64) exceeds the current value.
      2. If any score was updated: log + BuildAllianceMsg(0x66) (recalc notice).
      3. If g_press_flag == 1 (trust-override / press mode active):
           - Scan all 7 powers; if any power still has a pending PCE flag
             (g_turn_order_hist_lo == 1) or has zero trust despite having
             a DiplomacyState entry, the peace deal is not yet complete.
           - If ALL powers accepted: log, BuildAllianceMsg(0x65), restore
             g_ally_trust_score[own,*] from g_diplomacy_state_a/B snapshot.
      4. If changed: call ComputeOrderDipFlags (FUN_004113d0) — ported in flags.py.

    Returns True if the trust matrix was updated (signals GOF recalculation).
    """
    # Cross-slice call: helpers still in package __init__.py.  Deferred import
    # at call time avoids a circular import during package initialisation.
    from ..alliance import build_alliance_msg

    import logging
    _log = logging.getLogger(__name__)

    own_power  = getattr(state, 'albert_power_idx', 0)
    num_powers = 7

    # tokens[1:] are the power indices inside PCE ( pow1 pow2 ... )
    from ._common import _extract_powers
    pce_powers = _extract_powers(tokens[1:])
    n = len(pce_powers)

    changed = False

    # ── Double loop: all ordered pairs (i, j), i != j ────────────────────────
    for i in range(n):
        power_i = pce_powers[i]   # uVar16
        for j in range(n):
            if i == j:
                continue
            power_j = pce_powers[j]   # uVar12

            # If own power is in the pair: mark power_j as PCE-applied
            # C: if (uVar16 == uVar4) { DAT_004d53d8[uVar12*2] = 2; DAT_004d53dc[uVar12*2] = 0; }
            if power_i == own_power:
                state.g_turn_order_hist_lo[power_j] = 2
                state.g_turn_order_hist_hi[power_j] = 0

            # Compute trust: 3 − g_stab_counter[i,j] clamped to [1, 3]
            # When near-end-game (factor >= 4.0) always use 3.
            # C: uVar9 = 3; if (_g_NearEndGameFactor < 4.0) uVar9 = max(1, 3-stab)
            if state.g_near_end_game_factor < 4.0:
                trust = 3 - int(state.g_stab_counter[power_i, power_j])
                if trust < 1:
                    trust = 1
            else:
                trust = 3

            # int64 sign-extend trust → (trust_hi, trust_lo)
            # C: iVar14 = (int)uVar9 >> 0x1f  → 0 for positive trust
            trust_hi = trust >> 31   # always 0 for trust in [1,3]

            curr_hi = int(state.g_ally_trust_score_hi[power_i, power_j])
            curr_lo = int(state.g_ally_trust_score[power_i, power_j])

            # Update if (trust_hi, trust) > (curr_hi, curr_lo) as uint64.
            # C: curr_hi <= trust_hi AND (curr_hi < trust_hi OR curr_lo_uint < trust_uint)
            if curr_hi <= trust_hi and (curr_hi < trust_hi or curr_lo < trust):
                state.g_ally_trust_score[power_i, power_j]    = trust
                state.g_ally_trust_score_hi[power_i, power_j] = trust_hi
                changed = True

    # ── If any score changed: log + BuildAllianceMsg(0x66) ───────────────────
    if changed:
        powers_str = ' '.join(str(p) for p in pce_powers)
        _log.debug("Recalculating: Because we have applied a peace deal %s", powers_str)
        # C: BuildAllianceMsg(&DAT_00bbf638, &pvStack_38, 0x66)
        build_alliance_msg(state, 0x66)

    # ── All-powers-accepted check (only when g_press_flag == 1) ───────────────
    # C: if (DAT_00baed68 == '\x01') { ... if (bVar3) goto LAB_0041deab; ... }
    if state.g_press_flag == 1:
        dipl_a_arr = getattr(state, 'g_diplomacy_state_a', None)
        dipl_b_arr = getattr(state, 'g_diplomacy_state_b', None)
        not_all_accepted = False
        for i in range(num_powers):
            # Condition 1: pending PCE flag (sent but not yet applied)
            # C: DAT_004d53d8[i*2] == 1 AND DAT_004d53dc[i*2] == 0
            if int(state.g_turn_order_hist_lo[i]) == 1 and int(state.g_turn_order_hist_hi[i]) == 0:
                not_all_accepted = True

            # Condition 2: own has no trust with power i despite diplomatic state
            # C: g_ally_trust_score[own*21+i]==0 AND g_ally_trust_score_hi==0
            #    AND (DAT_004d5480[i*2]!=0 OR DAT_004d5484[i*2]!=0)
            t_lo = int(state.g_ally_trust_score[own_power, i])
            t_hi = int(state.g_ally_trust_score_hi[own_power, i])
            dipl_a = int(dipl_a_arr[i]) if dipl_a_arr is not None else 0
            dipl_b = int(dipl_b_arr[i]) if dipl_b_arr is not None else 0
            if t_lo == 0 and t_hi == 0 and (dipl_a != 0 or dipl_b != 0):
                not_all_accepted = True

        if not not_all_accepted:
            # All powers accepted — restore trust from DiplomacyState snapshot
            _log.debug("ALL powers have accepted PCE: return to original plan")
            # C lines 143-169: CString copy-on-write branch on pvStack_4c —
            # if (ref_count < 0 || head != sentinel) allocate new buffer else addref.
            # Pure string-management; absorbed as no-op in Python.
            build_alliance_msg(state, 0x65)

            # C lines 170-178: restore g_AllyTrustScore[own_power, *] from
            # DAT_004d5480/4 snapshot.  No null-guard in C (BSS globals are
            # always accessible, zero-initialised if never written to).
            for i in range(num_powers):
                a = int(dipl_a_arr[i]) if dipl_a_arr is not None else 0
                b = int(dipl_b_arr[i]) if dipl_b_arr is not None else 0
                state.g_ally_trust_score[own_power, i]    = a
                state.g_ally_trust_score_hi[own_power, i] = b
            changed = True

    # ── If changed: ComputeOrderDipFlags (FUN_004113d0) ─────────────────────
    # C: LAB_0041deab falls through to FUN_004113d0 when cStack_52 == '\x01'
    if changed:
        compute_order_dip_flags(state)

    return changed


def _handle_aly(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named function ALY() (decompile-verified against decompiled.txt).

    Called from cal_move() when the leading press token is 'ALY'.

    tokens layout (from CAL_MOVE pre-processing):
        tokens[0] == 'ALY'
        tokens[1..] == powers listed in ALY ( p1 p2 ... ) VSS ( v1 v2 ... )
    The raw press list still contains both the ALY sub-list and the VSS
    sub-list; we extract them via the same GetSubList(index=1) / (index=3)
    convention used in the C code.

    Algorithm (decompile §ALY, decompiled.txt lines 57–143):

      uStack_74 = own_power   (from *(param_1+8)+0x2424)
      local_58  = GetSubList(press_list, 1)  → ALY power list
      local_48  = GetSubList(press_list, 3)  → VSS power list

      For each aly_power in ALY list:
        For each vss_power in VSS list:
          if aly_power == own_power: skip            (line 83)
          idx = vss_power + aly_power * 21           (line 84)
          if g_ally_matrix[idx] < 1:
              g_ally_matrix[idx] = 1; changed = True  (lines 85–88)
          if g_EnemyDesired == 1 and g_ally_trust_score_hi[aly,vss] >= 0:
              g_ally_trust_score[aly,vss]    = 0       (lines 89–93)
              g_ally_trust_score_hi[aly,vss] = 0
              g_relation_score[aly,vss]     = 0
              changed = True
          own_idx = own_power * 21 + aly_power       (line 95)
          if trust[own→aly] == 0 (both lo and hi)
             AND enemy_flag_lo[aly] == 0
             AND enemy_flag_hi[aly] == 0:            (lines 96–97)
              build PCE(own, aly_power) and call _handle_pce()
              changed = True                         (lines 98–112)

      If changed:
        log "Recalculating: Because we have applied an ALY: (%s)"
        BuildAllianceMsg(0x66)

      Returns True (\\x01) if anything was changed.

    Global mapping:
      own_power           ← *(param_1+8)+0x2424  = state.albert_power_idx
      g_ally_matrix        ← &g_ally_matrix[row*21+col]  (char, 21×21 flat)
      g_EnemyDesired      ← DAT_00baed5f  = state.g_stabbed_flag / g_EnemyDesired
      g_ally_trust_score    ← &g_ally_trust_score[idx*2]   (lo word of uint64)
      g_ally_trust_score_hi ← &g_ally_trust_score_hi[idx*2](hi word of uint64)
      g_relation_score     ← DAT_00634e90  = state.g_relation_score[row,col]
      g_enemy_flag         ← DAT_004cf568/6c  = state.g_enemy_flag[power] lo/hi

    Callee added to Unchecked: none new (BuildAllianceMsg already unchecked).
    """
    # Cross-slice call: helpers still in package __init__.py.  Deferred import
    # at call time avoids a circular import during package initialisation.
    from ..alliance import build_alliance_msg

    import logging as _logging
    _log = _logging.getLogger(__name__)

    own_power = getattr(state, 'albert_power_idx', 0)

    # ── Extract ALY and VSS power sub-lists ──────────────────────────────────
    # C: GetSubList(&stack0x4, apuStack_68, 1) → local_58 (ALY powers)
    #    GetSubList(&stack0x4, apuStack_68, 3) → local_48 (VSS powers)
    from ._common import _extract_powers
    if len(tokens) >= 4 and str(tokens[2]).upper() == 'VSS':
        aly_powers = _extract_powers(tokens[1])
        vss_powers = _extract_powers(tokens[3])
    else:
        try:
            vss_idx = tokens.index('VSS')
            aly_powers = _extract_powers(tokens[1:vss_idx])
            vss_powers = _extract_powers(tokens[vss_idx + 1:])
        except ValueError:
            aly_powers = _extract_powers(tokens[1:])
            vss_powers = []

    changed = False

    # ── Double loop: ALY × VSS ────────────────────────────────────────────────
    for aly_power in aly_powers:          # uVar5 / bVar2
        for vss_power in vss_powers:      # *pbVar6 (inner)

            # C line 83: if (uVar5 != uStack_74) { ... }
            if aly_power == own_power:
                continue

            # C line 84: iVar7 = (uint)*pbVar6 + uVar5 * 0x15
            # iVar7 is used as flat index into g_ally_matrix (21-wide)
            idx = int(vss_power) + aly_power * 21    # iVar7

            # C lines 85–88: g_ally_matrix[iVar7] < 1  → set to 1
            if int(state.g_ally_matrix[aly_power, vss_power]) < 1:
                state.g_ally_matrix[aly_power, vss_power] = 1
                changed = True

            # C lines 89–93: g_EnemyDesired==1 AND trust_hi[aly,vss] >= 0
            #   → zero g_ally_trust_score, g_ally_trust_score_hi, g_relation_score
            enemy_desired = int(getattr(state, 'g_stabbed_flag', 0))   # DAT_00baed5f
            trust_hi_av = int(state.g_ally_trust_score_hi[aly_power, vss_power])
            if enemy_desired == 1 and trust_hi_av >= 0:
                # C: (&g_ally_trust_score)[iVar7*2] = 0; (&g_ally_trust_score_hi)[iVar7*2] = 0
                state.g_ally_trust_score[aly_power, vss_power]    = 0
                state.g_ally_trust_score_hi[aly_power, vss_power] = 0
                # C: (&DAT_00634e90)[iVar7] = 0   — g_relation_score
                state.g_relation_score[aly_power, vss_power]     = 0
                changed = True

            # C line 95: iVar7 = uStack_74 * 0x15 + uVar5  (own→aly direction)
            # C lines 96–97: trust[own→aly] == 0 AND enemy flags of aly_power == 0
            trust_lo_oa = int(state.g_ally_trust_score[own_power, aly_power])
            trust_hi_oa = int(state.g_ally_trust_score_hi[own_power, aly_power])

            # DAT_004cf568[uVar5*2] and DAT_004cf56c[uVar5*2]:
            # these are the lo/hi int32 words of g_enemy_flag for aly_power
            enemy_flag = getattr(state, 'g_enemy_flag', None)
            if enemy_flag is not None:
                ef_lo = int(enemy_flag[aly_power])
                # hi word — stored in a separate array or second element
                ef_hi_arr = getattr(state, 'g_enemy_flag_hi', None)
                ef_hi = int(ef_hi_arr[aly_power]) if ef_hi_arr is not None else 0
            else:
                ef_lo = ef_hi = 0

            if (trust_lo_oa == 0 and trust_hi_oa == 0
                    and ef_lo == 0 and ef_hi == 0):
                # C lines 98–112: build PCE(own, aly_power) and evaluate it
                # C: local_90[0] = token for own_power side
                #    local_8c[0] = bVar2 | 0x4100  (aly_power with DAIDE power flag)
                # In Python: synthesise tokens list for _handle_pce
                pce_tokens = ['PCE', own_power, aly_power]
                _handle_pce(state, pce_tokens)
                changed = True

    # ── Log + BuildAllianceMsg if anything changed ───────────────────────────
    if changed:
        aly_str = ' '.join(str(p) for p in aly_powers)
        _log.debug(
            "Recalculating: Because we have applied an ALY: (%s)", aly_str
        )
        # C: BuildAllianceMsg(&DAT_00bbf638, apuStack_68, (int*)&puStack_7c=0x66)
        build_alliance_msg(state, 0x66)

    return changed


def _handle_dmz(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named function DMZ() (decompile-verified against decompiled.txt).

    Called from cal_move() when the leading press token is 'DMZ'.

    C signature: char __fastcall DMZ(int param_1)
    param_1 is the press token-stream pointer (stack0x00000004 in the caller).
    Returns '\x01' (True) if the DMZ agreement was applied / any state changed.

    Token layout after CAL_MOVE preprocessing:
        tokens[0] == 'DMZ'
        tokens[1..n] == powers in the DMZ  (sublist index 1 in C)
        tokens[n+1..] == provinces in the DMZ  (sublist index 2 in C)

    Algorithm (faithful to decompile):

      own_power  = albert_power_idx  (piStack_88)
      dmz_powers = GetSubList(press, 1)  → local_74  (the DMZ power list)
      dmz_provs  = GetSubList(press, 2)  → local_48  (the DMZ province list)

      Outer double loop over dmz_powers (i, j):
        Condition: (i != j) OR len(dmz_powers) == 1.
        Inner loop over dmz_provs (province k):

          piVar4  = dmz_powers[i]   (outer power; piStack_ac saved copy)
          piVar9  = dmz_provs[k]    (the province being DMZ'd; piStack_b0)

          BRANCH A — piVar4 == own_power:
            Walk g_dmz_order_list (DAT_00bb65e4, sentinel DAT_00bb65e0).
            For each record rec where rec.owner_power != own_power:
              iVar10 = rec.owner_power
              iStack_34 = DAT_00bb6f2c[iVar10*3]   (_Myhead sentinel of g_ally_promise_list[iVar10])
              puVar7 = GameBoard_GetPowerRec(DAT_00bb6f28+iVar10*0xc, buf, &province_k)
              if puVar7[1] == iStack_34:  ← province NOT YET in g_ally_promise_list[rec_owner]
                StdMap_FindOrInsert(…)    ← insert province_k into g_ally_promise_list[rec_owner]
                cStack_b1 = '\x01'

          BRANCH B — piVar4 != own_power:
            iVar10 = DAT_00bb702c[piVar4*3]   (_Myhead sentinel of g_ally_counter_list[piVar4])
            puVar11 = DAT_00bb7028 + piVar4*0xc
            puVar7 = GameBoard_GetPowerRec(puVar11, buf, &province_k)
            if puVar7[1] == iVar10:  ← province NOT YET in g_ally_counter_list[outer_power]
              StdMap_FindOrInsert(puVar11, …) ← insert province_k into g_ally_counter_list[outer_power]
              cStack_b1 = '\x01'
            Walk g_active_dmz_list (DAT_00bb7134, sentinel DAT_00bb7130):
              For each rec where rec[3]==piVar4 AND rec[4]==piVar9:
                FUN_00412280(…) → erase from g_active_dmz_list

      If cStack_b1 == '\x01':
        SEND_LOG("Recalculating: Because we have applied a DMZ: (%s)")
        BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)

      Returns cStack_b1  (True if any change, False otherwise)

    Global mapping:
      own_power           ← state.albert_power_idx
      g_dmz_order_list    ← state.g_dmz_order_list     list[dict{owner_power,…}]
      g_ally_promise_list ← state.g_ally_promise_list  dict[power → list[{'dest_prov': int}]]
                            DAT_00bb6f28/2c — inserted here (BRANCH A), erased by _remove_dmz
      g_ally_counter_list ← state.g_ally_counter_list  dict[power → list[{'dest_prov': int}]]
                            DAT_00bb7028/2c — inserted here (BRANCH B), erased by _remove_dmz
      g_active_dmz_list   ← state.g_active_dmz_list    list[dict{power,province}]
    """
    # Cross-slice call: helpers still in package __init__.py.  Deferred import
    # at call time avoids a circular import during package initialisation.
    from ..alliance import build_alliance_msg

    import logging as _logging
    _log = _logging.getLogger(__name__)

    own_power = getattr(state, 'albert_power_idx', 0)

    # ── Extract DMZ powers (sublist 1) and DMZ provinces (sublist 2) ──────────
    # C: GetSubList(&stack4, &pvStack_64, 1) → local_74  (power list)
    #    GetSubList(&stack4, &pvStack_64, 2) → local_48  (province list)
    from ._common import _extract_powers, _extract_provs
    dmz_powers = _extract_powers(tokens[1] if len(tokens) > 1 else [])
    dmz_provs = _extract_provs(state, tokens[2] if len(tokens) > 2 else [])

    if not dmz_powers or not dmz_provs:
        return False

    # uStack_80 = FUN_00465930(local_74)  — count of dmz_powers
    # uStack_8c = FUN_00465930(local_48)  — count of dmz_provs
    n_powers = len(dmz_powers)   # uStack_80
    n_provs  = len(dmz_provs)    # uStack_8c

    # cStack_b1 — return value / changed flag
    changed = False

    # Lazy-init DMZ state lists if not present on state
    if not hasattr(state, 'g_dmz_order_list'):
        state.g_dmz_order_list = []   # DAT_00bb65e0/e4: list[dict{owner_power,provinces}]
    if not hasattr(state, 'g_active_dmz_list'):
        state.g_active_dmz_list = []  # DAT_00bb7130/34: list[dict{power, province}]

    g_dmz_order_list: list = state.g_dmz_order_list
    g_active_dmz_list: list = state.g_active_dmz_list
    # BRANCH A writes: DAT_00bb6f28[rec_owner*0xc] → g_ally_promise_list[rec_owner]
    # BRANCH B writes: DAT_00bb7028[outer_power*0xc] → g_ally_counter_list[outer_power]
    # Same structures read/erased by _remove_dmz and probed by _eval_not_dmz.
    g_promise: dict = getattr(state, 'g_ally_promise_list', None) or {}
    if not hasattr(state, 'g_ally_promise_list') or state.g_ally_promise_list is None:
        state.g_ally_promise_list = g_promise
    g_counter: dict = getattr(state, 'g_ally_counter_list', None) or {}
    if not hasattr(state, 'g_ally_counter_list') or state.g_ally_counter_list is None:
        state.g_ally_counter_list = g_counter

    # ── Outer double loop: powers i, j ────────────────────────────────────────
    # C: if (0 < (int)uVar3) { do { ... } while (iStack_90 < (int)uVar3); }
    # Outer i (iStack_90), inner j (iStack_84):
    #   condition inner body runs: (i != j) OR (uVar3 == 1)
    for i_idx in range(n_powers):
        outer_power = dmz_powers[i_idx]  # piVar4 / piStack_ac

        for j_idx in range(n_powers):
            # C: if (((iVar10 != iVar13) || (uVar3 == 1)) && (iStack_a4 = 0, 0 < (int)uStack_8c))
            if i_idx == j_idx and n_powers != 1:
                continue

            # ── Inner k loop: each DMZ province ─────────────────────────────
            for k_idx in range(n_provs):
                province = dmz_provs[k_idx]   # piVar9 / piStack_b0

                if outer_power == own_power:
                    # ── BRANCH A: own power is in the DMZ pair ────────────────
                    # C lines 97–140: walk g_dmz_order_list (DAT_00bb65e4 .. sentinel DAT_00bb65e0)
                    # For each rec where rec.owner_power != own_power:
                    #   iStack_34 = DAT_00bb6f2c[rec_owner*3]  (_Myhead of g_ally_promise_list[rec_owner])
                    #   puVar7 = GameBoard_GetPowerRec(DAT_00bb6f28+rec_owner*0xc, buf, &province)
                    #   if puVar7[1] == iStack_34:  ← province NOT YET in g_ally_promise_list[rec_owner]
                    #     StdMap_FindOrInsert(...)   ← insert province
                    #     cStack_b1 = '\x01'
                    for rec in list(g_dmz_order_list):
                        rec_owner = int(rec.get('owner_power', -1))
                        if rec_owner == own_power:
                            continue
                        prom_list = g_promise.setdefault(rec_owner, [])
                        already = any(e.get('dest_prov') == province for e in prom_list)
                        if not already:
                            # puVar7[1] == iStack_34: province absent → insert
                            prom_list.append({'dest_prov': province})
                            changed = True

                else:
                    # ── BRANCH B: non-own outer power ─────────────────────────
                    # C lines 143–185:
                    #   iVar10 = DAT_00bb702c[piVar4*3]  (_Myhead of g_ally_counter_list[outer_power])
                    #   puVar11 = DAT_00bb7028 + piVar4*0xc
                    #   puVar7 = GameBoard_GetPowerRec(puVar11, buf, &province)
                    #   if puVar7[1] == iVar10:  ← province NOT YET in g_ally_counter_list[outer_power]
                    #     cStack_b1 = '\x01'; StdMap_FindOrInsert → insert
                    cnt_list = g_counter.setdefault(outer_power, [])
                    already = any(e.get('dest_prov') == province for e in cnt_list)
                    if not already:
                        cnt_list.append({'dest_prov': province})
                        changed = True

                    # ── Walk g_active_dmz_list: remove matching entry ───────────
                    # C lines 153–184:
                    # Walk DAT_00bb7134 list; for each rec:
                    #   if ppiVar12[3] == piStack_ac (outer_power)
                    #      AND ppiVar12[4] == piVar9 (province matches):
                    #     FUN_00412280(DAT_00bb7130, ..., rec)  → erase from list
                    #   else if power matches but province differs → advance (no erase)
                    #  (restart iteration after erase matches C do-while restart)
                    #
                    # Fix 2026-04-21 (C-1): Previously had inverted condition
                    # (rec_province != province) which erased OTHER provinces'
                    # DMZ records instead of the matching one.  C line 169:
                    #   if (ppiVar12[4] != piVar9) goto LAB_00420474  → advance
                    #   FUN_00412280(...)  → erase when province MATCHES
                    restart = True
                    while restart:
                        restart = False
                        for idx, active_rec in enumerate(list(g_active_dmz_list)):
                            rec_power   = int(active_rec.get('power', -1))
                            rec_province = int(active_rec.get('province', -1))
                            if rec_power == outer_power and rec_province == province:
                                # FUN_00412280: erase this stale DMZ entry
                                # C: ppiStack_94 = (int**)*DAT_00bb7134 after erase
                                #    (the list head is reset to the new front)
                                try:
                                    g_active_dmz_list.remove(active_rec)
                                except ValueError:
                                    pass
                                restart = True
                                break

    # ── Post-loop: if changed, log and BuildAllianceMsg ───────────────────────
    # C lines 198–220:
    #   FUN_0046b050(...)  → serialize province list (absorbed as debug log)
    #   SEND_LOG("Recalculating: Because we have applied a DMZ: (%s)")
    #   BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)
    if changed:
        prov_str = ' '.join(str(p) for p in dmz_provs)
        _log.debug(
            "Recalculating: Because we have applied a DMZ: (%s)", prov_str
        )
        # C: BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)
        build_alliance_msg(state, 0x66)

    return changed


def _handle_xdo(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named function XDO() (decompile-verified against decompiled.txt).

    Called from cal_move() when the leading press token is 'XDO'.
    Preceded by FUN_00405090 prep in the caller (provides in_stack_00000018 =
    the outer candidate-proposal list, passed as the second state-based
    parameter here via state.g_xdo_candidate_list).

    Algorithm (faithful to decompile, decompiled.txt lines 2–266):

      1. Init three empty local token lists (local_40, local_2c, local_1c).
         Allocate a local proposal sentinel (local_74).
      2. GetSubList(&stack4, 1) → local_40 = XDO inner content
         (the full order triple: unit, order-type, destination).
      3. Element 0 of sublist 0 → bVar3 = sender power (byte).
         FUN_00465930(local_40) → uVar11 = element count of local_40.
         FUN_00419300(DAT_00bb65f8 + bVar3*0xc, ..., local_40)
           → register this XDO proposal into sender's proposal map
             (g_xdo_proposal_by_sender[sender_power]).
      4. Element 2 of sublist 0 → pvStack_80 = destination/scope province.
         StdMap_FindOrInsert(DAT_00bb6bf8 + bVar3*0xc, ..., pvStack_80)
           → g_xdo_dest_by_sender[sender_power][dest_prov] = dest_prov
         StdMap_FindOrInsert(DAT_00bb713c, ..., pvStack_80)
           → g_xdo_global_dest_map[dest_prov] = dest_prov
      5. Element 0 of sublist 1 → sVar4 = order command token (short).
      6a. If MTO or CTO:
            Element 0 of sublist 2 → ppiStack_7c = destination province.
            Loop over g_xdo_candidate_list (in_stack_00000018):
              ScoreSupportOpp(DAT_00bb67f8 + entry.power * 0xc, buf,
                               (dest_prov, dest_prov))
      6b. If SUP:
            local_2c = GetSubList(local_40, 2)  (the supported unit sub-token)
            sublist-1 element 0 → unused (supported unit identity)
            sublist-2 element 0 → ppiVar14 = supported power
            sublist-0 of sublist-2 of local_40  element 0 → bVar3 re-read
              = province of the unit being supported (piStack_b0)
            StdMap_FindOrInsert(DAT_00bb713c, ..., ppiStack_7c)
              → g_xdo_global_dest_map[ppiStack_7c] = ppiStack_7c
            If uVar11 == 5 (SUP MTO — 5-element XDO):
              ScoreSupportOpp(DAT_00bb69f8 + bVar3*0xc, buf,
                               (ppiVar14, ppiVar16))
              Loop over g_xdo_candidate_list:
                FUN_004193f0(DAT_00bb68f8 + entry.power*0xc, buf,
                              (dest_prov, dest_prov))
            Else (SUP HLD):
              StdMap_FindOrInsert(DAT_00bb6af8 + bVar3*0xc, ...,
                                   ppiStack_7c)
              Loop over g_xdo_candidate_list:
                FUN_004193f0(DAT_00bb68f8 + entry.power*0xc, buf,
                              (dest_prov, dest_prov))
      7. Log "Recalculating: Because we have applied a XDO: (%s)" +
         BuildAllianceMsg(0x66).
      8. Clear local_74 sentinel via SerializeOrders (absorbed as no-op).
         Clear in_stack_00000018 = g_xdo_candidate_list via SerializeOrders
         + _free (absorbed as list clear).
      9. Return True (\x01).

    New global state fields:
      g_xdo_proposal_by_sender : dict[int, list]  — DAT_00bb65f8 per-power list
      g_xdo_dest_by_sender     : dict[int, dict]  — DAT_00bb6bf8 per-power map
      g_xdo_global_dest_map    : dict             — DAT_00bb713c global map
      g_xdo_order_move_by_power : dict[int, dict] — DAT_00bb69f8 per-power src→dest
      g_xdo_order_hold_by_power : dict[int, set]  — DAT_00bb6af8 per-power hold set
      g_xdo_candidate_list      : list[dict]       — in_stack_00000018 from FUN_00405090

    Unchecked callees: ScoreSupportOpp (DAT_00bb67f8/00bb69f8 paths),
                       FUN_004193f0 (DAT_00bb68f8 path),
                       FUN_00419300 (XDO proposal registration).
    """
    from ..alliance import build_alliance_msg
    from ..alliance import _ordered_token_seq_insert
    from ._common import _pow_idx
    from ..parsers import _split_top_level_groups

    import logging as _logging
    _log = _logging.getLogger(__name__)

    if len(tokens) < 2:
        return True

    # ── Step 2: parse XDO body ────────────────────────────────────────────────
    # C: GetSubList(&stack4, 1) → local_40 = XDO inner content.
    # tokens = ['XDO', '(', body_tokens..., ')']
    # _split_top_level_groups(tokens) → ['XDO', [inner_tokens...]]
    outer = _split_top_level_groups(tokens)
    if len(outer) < 2 or not isinstance(outer[1], list):
        return True
    # local_40: top-level items within the XDO body paren group.
    body: list = _split_top_level_groups(outer[1])
    if not body or not isinstance(body[0], list):
        return True

    # ── Step 3: bVar3 = sender power (element 0 of sublist 0) ────────────────
    # C: GetSubList(local_40, 0) + GetListElement(0) → low byte = power index
    unit_triple: list = body[0]   # e.g. ['ENG', 'AMY', 'LON']
    _pw: "int | None" = _pow_idx(unit_triple[0]) if unit_triple else None
    sender_power: int = _pw if _pw is not None else 0

    # uVar11 = FUN_00465930(local_40) = number of top-level items (not raw tokens)
    uVar11: int = len(body)

    # FUN_00419300: register XDO proposal for the sender in g_xdo_proposal_by_sender
    _ordered_token_seq_insert(
        state.g_xdo_proposal_by_sender.setdefault(sender_power, []),
        tokens[1:],
    )

    # ── Step 4: pvStack_80 = element 2 of sublist 0 (source province) ─────────
    # C: GetSubList(local_40, 0) + GetListElement(2) → low byte = province code
    src_prov: str = unit_triple[2] if len(unit_triple) > 2 else ''

    def province_id(value):
        """Translate DAIDE province tokens to the integer IDs used by MC."""
        if isinstance(value, int):
            return value
        token = str(value).upper()
        lookup = getattr(state, 'prov_to_id', {}) or {}
        return lookup.get(token, lookup.get(token.split('/')[0], value))

    if not hasattr(state, 'g_xdo_dest_by_sender'):
        state.g_xdo_dest_by_sender = {}
    state.g_xdo_dest_by_sender.setdefault(sender_power, {})[src_prov] = src_prov

    if not hasattr(state, 'g_xdo_global_dest_map'):
        state.g_xdo_global_dest_map = {}
    state.g_xdo_global_dest_map[src_prov] = src_prov

    # ── Step 5: sVar4 = order command (element 0 of sublist 1) ───────────────
    # C: GetSubList(local_40, 1) + GetListElement(0) → short = command token
    order_cmd: str = str(body[1]).upper() if len(body) > 1 and isinstance(body[1], str) else ''

    # Candidate list from FUN_00405090 / in_stack_00000018 (set by caller in gof.py).
    candidate_list: list = getattr(state, 'g_xdo_candidate_list', [])

    if order_cmd in ('MTO', 'CTO'):
        # ── Step 6a: MTO / CTO ────────────────────────────────────────────────
        # C: GetSubList(local_40, 2) + GetListElement(0) → ppiStack_7c = dest prov
        dest_item = body[2] if len(body) > 2 else None
        if isinstance(dest_item, list):
            mto_dest: str = dest_item[0] if dest_item else ''
        else:
            mto_dest = str(dest_item) if dest_item is not None else ''

        # C loop: ScoreSupportOpp(&DAT_00bb67f8 + entry_power*0xc, buf, &pvStack_88)
        # pvStack_88 = pvStack_80 = src_prov  →  key = src_prov
        for entry in candidate_list:
            entry_power: int = int(entry.get('power', entry.get('node_power', 0)))
            _score_support_opp(state, 'DAT_00bb67f8', entry_power, (src_prov, mto_dest))

    elif order_cmd == 'SUP':
        # ── Step 6b: SUP ──────────────────────────────────────────────────────
        # local_2c = GetSubList(local_40, 2) = supported unit sub-token content
        sup_unit: list = body[2] if len(body) > 2 and isinstance(body[2], list) else []
        # e.g. sup_unit = ['FRA', 'AMY', 'PAR']

        # bVar3 re-read: element 0 of sub-list 0 of local_2c = power of supported unit
        # C: GetSubList(local_2c, 0) + GetListElement(0) → FRA power byte
        _sp: "int | None" = _pow_idx(sup_unit[0]) if sup_unit else None
        sup_power_idx: int = _sp if _sp is not None else 0

        # ppiVar14: element 0 of sub-list 2 of local_2c = province of supported unit
        # C: GetSubList(local_2c, 2) + GetListElement(0) → PAR province byte
        sup_unit_prov: str = sup_unit[2] if len(sup_unit) > 2 else ''

        # StdMap_FindOrInsert(DAT_00bb713c, ..., ppiStack_7c = ppiVar14 = sup_unit_prov)
        state.g_xdo_global_dest_map[sup_unit_prov] = sup_unit_prov

        if uVar11 == 5:
            # SUP MTO: body[3] = 'MTO', body[4] = MTO destination
            # ppiVar16 = element 0 of sublist 4 of local_40
            dest_item = body[4] if len(body) > 4 else None
            if isinstance(dest_item, list):
                ppiVar16: str = dest_item[0] if dest_item else ''
            else:
                ppiVar16 = str(dest_item) if dest_item is not None else ''

            # ScoreSupportOpp(&DAT_00bb69f8 + bVar3_reread*0xc, buf, &ppiStack_90)
            # ppiStack_90 = ppiVar14 = sup_unit_prov  →  key = sup_unit_prov
            _score_support_opp(
                state,
                'DAT_00bb69f8',
                sup_power_idx,
                (province_id(sup_unit_prov), province_id(ppiVar16)),
            )

            # C loop: FUN_004193f0(&DAT_00bb68f8 + entry_power*0xc, buf, &pvStack_50)
            # pvStack_50 = pvStack_80 = src_prov  →  key = src_prov
            for entry in candidate_list:
                entry_power = int(entry.get('power', entry.get('node_power', 0)))
                _score_sup_attacker(state, 'DAT_00bb68f8', entry_power, (src_prov, src_prov))
        else:
            # SUP HLD: StdMap_FindOrInsert(DAT_00bb6af8 + bVar3_reread*0xc, ..., ppiStack_7c)
            # table index = bVar3_reread = sup_power_idx; key = ppiStack_7c = sup_unit_prov
            hold_sets = state.g_xdo_order_hold_by_power
            hold_sets.setdefault(sup_power_idx, set()).add(province_id(sup_unit_prov))

            # C loop: FUN_004193f0(&DAT_00bb68f8 + entry_power*0xc, buf, &pvStack_50)
            # pvStack_50 = pvStack_80 = src_prov  →  key = src_prov
            for entry in candidate_list:
                entry_power = int(entry.get('power', entry.get('node_power', 0)))
                _score_sup_attacker(state, 'DAT_00bb68f8', entry_power, (src_prov, src_prov))

    # ── Step 7: log + BuildAllianceMsg ───────────────────────────────────────
    _log.debug(
        "Recalculating: Because we have applied a XDO: (%s)",
        ' '.join(str(t) for t in tokens[1:]),
    )
    build_alliance_msg(state, 0x66)

    # ── Step 8: clear candidate list (in_stack_00000018 freed by caller) ─────
    if hasattr(state, 'g_xdo_candidate_list'):
        state.g_xdo_candidate_list = []

    return True


def _score_support_opp(
    state: InnerGameState,
    base_offset: str,
    power: int,
    args: tuple,
) -> tuple:
    """
    ScoreSupportOpp (FUN_00404fd0) — MSVC std::map<int,int> find-or-insert.

    C signature:
      void __thiscall ScoreSupportOpp(void *this, void **param_1, int *param_2)

    this     = &table[power * 0xc]  — per-power (or per-province) map object
    param_1  = output: [0]=iterator_base, [1]=node_ptr, [2]=was_inserted
    param_2  = pointer to key (= args[0]); args[1] passed through to the
               BST insert helper FUN_00403ca0 but not used by this function.

    Node layout (MSVC release std::map<int,int>):
      +0x00  left child ptr      (ppiVar4[0])
      +0x04  parent ptr          (ppiVar4[1])
      +0x08  right child ptr     (ppiVar4[2])
      +0x0C  key   (int)         (ppiVar4[3])  ← compared against *param_2
      +0x10  value (int)         (ppiVar4[4])  ← param_2[1] on pair inserts
      +0x14  _Color byte
      +0x15  _Isnil byte         ← sentinel check: == '\\0' means real node

    Algorithm: BST lower-bound walk; if key already present return its node
    (was_inserted=False); else allocate a node via FUN_00403ca0
    (was_inserted=True).  DAT_00bb69f8 passes a two-int source/destination
    pair; the simpler opportunity maps only rely on a default-zero value.
    FUN_00401400 = BST iterator-decrement (predecessor).

    Python tables:
      'DAT_00bb67f8' → state.g_xdo_mto_opp_score[power][key]   (MTO/CTO path)
      'DAT_00bb69f8' → state.g_xdo_order_move_by_power[power]
                       [source] = destination (XDO SUP-MTO path)

    Returns (sub_table, key, was_inserted).  Call sites that only need the
    insertion side effect may discard the return value.

    Callees: FUN_00401400 (BST predecessor), FUN_00403ca0 (BST insert).
    """
    _TABLE_ATTR: dict = {
        'DAT_00bb67f8': 'g_xdo_mto_opp_score',
        'DAT_00bb69f8': 'g_xdo_order_move_by_power',
    }
    attr: str = _TABLE_ATTR.get(base_offset, base_offset)
    if not hasattr(state, attr):
        setattr(state, attr, {})
    table: dict = getattr(state, attr)
    sub: dict = table.setdefault(power, {})
    key = args[0]  # province name (str) in Python port; int in C
    was_inserted: bool = key not in sub
    if was_inserted:
        # DAT_00bb69f8 receives the full {source, destination} pair at XDO.c:166.
        # Other ScoreSupportOpp users retain their existing zero-valued insert.
        sub[key] = args[1] if base_offset == 'DAT_00bb69f8' else 0
    return sub, key, was_inserted


def _score_sup_attacker(
    state: InnerGameState,
    base_offset: str,
    power: int,
    args: tuple,
) -> tuple:
    """
    Port of FUN_004193f0 — MSVC std::map<int,int> find-or-insert.

    C signature (decompiled.txt lines 2–50):
      void __thiscall FUN_004193f0(void *this, void **param_1, int *param_2)

    this     = &DAT_00bb68f8 + entry_power*0xc  — per-power attacker-score map
    param_1  = output: [0]=iterator_base, [1]=node_ptr, [2]=was_inserted
    param_2  = pointer to key (args[0])

    Algorithm is structurally identical to ScoreSupportOpp (FUN_00404fd0):
      BST lower-bound walk using the node layout
        +0x00 left, +0x04 parent, +0x08 right, +0x0C key (int),
        +0x10 value (int), +0x19 isnil byte (== '\\0' → real node)
      If key found: return existing node, was_inserted=False.
      Else: allocate zero-valued node via FUN_004136d0, was_inserted=True.
      FUN_0040e5f0 = BST iterator-decrement (predecessor).

    Python table:
      'DAT_00bb68f8' → state.g_xdo_sup_attacker_score[power][key]

    Callees (absorbed into dict operations):
      FUN_0040e5f0 (BST predecessor / iterator-decrement)
      FUN_004136d0 (BST insert helper)
    """
    attr = 'g_xdo_sup_attacker_score'
    if not hasattr(state, attr):
        setattr(state, attr, {})
    table: dict = getattr(state, attr)
    sub: dict = table.setdefault(power, {})
    key = args[0]  # province name (str) in Python port; int in C
    was_inserted: bool = key not in sub
    if was_inserted:
        sub[key] = 0   # zero-initialise mapped int (mirrors default-construct)
    return sub, key, was_inserted


def cal_move(state: InnerGameState, press_tokens: list) -> bool:
    """
    Port of CAL_MOVE (named; __thiscall).

    Dispatches a press proposal token list to the appropriate DAIDE keyword
    handler based on the leading token.  Called per inner-list entry in
    EvaluateOrderProposalsAndSendGOF; returns True (1) to trigger the GOF
    commit path.

    press_tokens: flat list of DAIDE token strings for the proposal, e.g.
        ['PCE', ...] or ['NOT', 'XDO', ...] (NOT wrapper already unwrapped
        at the C level via GetSubList/AppendList before the inner dispatch).

    C structure:
      1. GetListElement(list, &out, 0) — read first token (position 0; all
         else-branch calls also read position 0: Ghidra artifact of the
         same register being reused, not list advancement).
      2. if PCE  → FUN_00465f60(local, list) + PCE(this)
         if ALY  → FUN_00465f60(local, list) + ALY(this)
         if DMZ  → FUN_00465f60(local, list) + DMZ(this)
         if XDO  → FUN_00405090(...) + FUN_00465f60(local, list) + XDO()
         if NOT  → GetSubList(list, tmp, 1) + AppendList(list, tmp) +
                   FreeList(tmp)  [unwrap NOT(…)] then:
             if PCE → FUN_00465f60 + CANCEL(this)
             if DMZ → FUN_00465f60 + REMOVE_DMZ(this)
             if XDO → FUN_00405090 + FUN_00465f60 + NOT_XDO()
      3. FreeList(list) + SerializeOrders(…) + _free(…)
    """
    if not press_tokens:
        return False

    # C TokenSeq elements preserve sub-list boundaries.  String-mode inbound
    # press is flat and contains literal parentheses, so reconstruct those
    # boundaries at this dispatcher edge.
    if '(' in press_tokens or ')' in press_tokens:
        from ..parsers import _split_top_level_groups
        press_tokens = _split_top_level_groups(press_tokens)

    first = press_tokens[0]

    if first == 'PCE':
        # C: FUN_00465f60 copies list to local; PCE(this) gets that local
        return bool(_handle_pce(state, press_tokens))

    if first == 'ALY':
        return bool(_handle_aly(state, press_tokens))

    if first == 'DMZ':
        return bool(_handle_dmz(state, press_tokens))

    if first == 'XDO':
        # C: FUN_00405090 preps a target ptr; FUN_00465f60 copies list to local
        return bool(_handle_xdo(state, press_tokens))

    if first == 'NOT':
        # C: GetSubList extracts the inner parenthesised content of NOT(…),
        # AppendList flattens it back into the working list, FreeList frees the
        # temp wrapper.  Net effect: inner tokens of NOT are exposed for the
        # second-level dispatch.
        inner_tokens = press_tokens[1:]   # strip leading NOT token
        if len(inner_tokens) == 1 and isinstance(inner_tokens[0], list):
            from ..parsers import _split_top_level_groups
            nested = inner_tokens[0]
            inner_tokens = (
                _split_top_level_groups(nested)
                if '(' in nested or ')' in nested else list(nested)
            )
        if not inner_tokens:
            return False
        inner_first = inner_tokens[0]
        if inner_first == 'PCE':
            return bool(_cancel_pce(state, inner_tokens))
        if inner_first == 'DMZ':
            return bool(_remove_dmz(state, inner_tokens))
        if inner_first == 'XDO':
            return bool(_not_xdo(state, inner_tokens))

    return False
