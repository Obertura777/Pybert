"""NOT-branch press handlers: undo / cancel flows.

Split from communications/evaluators.py during the 2026-04 refactor.

Holds the cancellation / NOT-branch handlers invoked by ``cal_move`` when
an inbound press message revokes or contradicts a previously accepted
proposal.

Public names:
  * ``_cancel_pce``  — revoke an accepted PCE and rebuild enemy/ally state.
  * ``_remove_dmz``  — withdraw a DMZ commitment from the press ledger.
  * ``_not_xdo``     — cancel a previously promised XDO execution.

Module-level deps: ``..state.InnerGameState``.
"""

from ...state import InnerGameState


def _cancel_pce(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named export CANCEL(param_1).

    Called from CAL_MOVE's NOT-PCE branch when a NOT(PCE(...)) press is
    received, cancelling an active peace arrangement.

    Decompile walk (decompiled.txt lines 2-184):

    Setup
    -----
    - uStack_44 = own power index (param_1+8+0x2424, i.e. albert_power_idx).
    - FUN_00465f60 copies incoming press token-list into local_1c.
    - GetSubList(&token_list, &pvStack_38, 1) extracts sub-list 1
      (the PCE power set), AppendList-merges it back into token_list,
      FreeList releases the temp.
    - uVar3 = FUN_00465930(&token_list)  → count of powers in the PCE.

    First loop (lines 61-64): iterates i=0..N-1 calling GetListElement,
    populating uStack_58 (low byte = power token).  This is a read-only pass
    with no observable side-effects in Python; we model it as extracting the
    powers list.

    Main double loop (outer iStack_4c, inner iStack_50, lines 67-128):
    For each ordered pair (a = powers[i], b = powers[j]) where i ≠ j:

      idx = a * 21 + b   (flat index into trust matrices)

      Trust-zero branch (lines 79-85):
        if g_ally_trust_score_hi[idx*2] > 0
           OR (g_ally_trust_score_hi[idx*2] == 0 AND g_ally_trust_score[idx*2] != 0):
          → g_ally_trust_score[idx*2]    = 0
          → g_ally_trust_score_hi[idx*2] = 0
          → cStack_59 = '\x01'  (changed)

      Own-power branch (lines 86-122) — only when outer power a == own:
        if DAT_00bb6f30[b*3] != 0 OR DAT_00bb7030[b*3] != 0:
          → changed
        Walk & free linked list at DAT_00bb6f2c[b*3]:
          while node.isnil == 0: FUN_00401950(node[2]); node = node.next; free
          Reset sentinel links (prev=next=self) and count to 0.
        Walk & free linked list at DAT_00bb702c[b*3]:
          same pattern.

    Post loop (lines 129-167): if changed → log + BuildAllianceMsg(0x66) stub.
    Returns cStack_59.

    Python mapping of C globals:
      uStack_44              → state.albert_power_idx
      g_ally_trust_score       → state.g_ally_trust_score  (2-D array indexed [a, b])
      g_ally_trust_score_hi    → state.g_ally_trust_score_hi
      DAT_00bb6f2c[p*3]      → state.g_desig_list_a[p]   (list of records, cleared on cancel)
      DAT_00bb6f30[p*3]      → state.g_desig_count_a[p]  (int count)
      DAT_00bb702c[p*3]      → state.g_desig_list_b[p]
      DAT_00bb7030[p*3]      → state.g_desig_count_b[p]

    The C linked-list walk-and-free is absorbed as list.clear().
    """
    # Cross-slice call: helpers still in package __init__.py.  Deferred import
    # at call time avoids a circular import during package initialisation.
    from . import build_alliance_msg

    import logging as _logging
    _log = _logging.getLogger(__name__)

    own: int = getattr(state, 'albert_power_idx', 0)

    # ── Extract PCE powers from the token list ────────────────────────────────
    # GetSubList(&token_list, ..., 1) fetches the power sub-list (index 1).
    # In Python `tokens` already contains the unwrapped list from CAL_MOVE.
    # The PCE token is: PCE ( power1 power2 … ) → tokens[1:] are power bytes.
    pce_powers: list[int] = []
    for tok in tokens[1:]:
        try:
            p = int(tok) & 0xFF
            pce_powers.append(p)
        except (TypeError, ValueError):
            pass

    uVar3: int = len(pce_powers)   # FUN_00465930 result
    if uVar3 <= 0:
        return False

    changed: bool = False          # cStack_59

    # ── Main double loop ──────────────────────────────────────────────────────
    for i, a in enumerate(pce_powers):       # iStack_4c / uStack_48
        for j, b in enumerate(pce_powers):   # iStack_50 / uVar10
            if i == j:                        # if (iVar5 != iVar11) guard
                continue

            # idx = a * 21 + b  (flat index)
            idx: int = a * 21 + b

            # Trust-zero branch (lines 79-85)
            # Condition:
            #   (&g_ally_trust_score_hi)[idx*2] > 0
            #   OR ((&g_ally_trust_score_hi)[idx*2] == 0
            #        AND (&g_ally_trust_score)[idx*2] != 0)
            # Equivalent to: trust_hi > 0  OR  trust != 0  (when trust_hi == 0)
            try:
                t_hi = int(state.g_ally_trust_score_hi[a, b])
                t_lo = int(state.g_ally_trust_score[a, b])
            except Exception:
                t_hi = 0
                t_lo = 0

            trust_nonzero = (t_hi > 0) or (t_hi == 0 and t_lo != 0)
            if trust_nonzero:
                state.g_ally_trust_score[a, b]    = 0
                state.g_ally_trust_score_hi[a, b] = 0
                changed = True

            # Own-power branch (lines 86-122): a == own
            if a == own:
                # DAT_00bb6f30[b*3] and DAT_00bb7030[b*3] are count fields.
                g_desig_count_a = getattr(state, 'g_desig_count_a', {})
                g_desig_count_b = getattr(state, 'g_desig_count_b', {})
                cnt_a = int(g_desig_count_a.get(b, 0))
                cnt_b = int(g_desig_count_b.get(b, 0))

                if cnt_a != 0 or cnt_b != 0:
                    changed = True

                # Walk & free linked list A (DAT_00bb6f2c[b*3]) — lines 90-102.
                # Absorbed as list.clear(); sentinel reset (list now empty).
                g_desig_list_a = getattr(state, 'g_desig_list_a', {})
                if b in g_desig_list_a:
                    g_desig_list_a[b] = []
                else:
                    g_desig_list_a[b] = []
                state.g_desig_list_a = g_desig_list_a

                # Reset count field A (DAT_00bb6f30[b*3] = 0) — line 100.
                g_desig_count_a[b] = 0
                state.g_desig_count_a = g_desig_count_a

                # Walk & free linked list B (DAT_00bb702c[b*3]) — lines 103-122.
                g_desig_list_b = getattr(state, 'g_desig_list_b', {})
                if b in g_desig_list_b:
                    g_desig_list_b[b] = []
                else:
                    g_desig_list_b[b] = []
                state.g_desig_list_b = g_desig_list_b

                # Reset count field B (DAT_00bb7030[b*3] = 0) — line 120.
                g_desig_count_b[b] = 0
                state.g_desig_count_b = g_desig_count_b

    # ── Post-loop: log if changed ─────────────────────────────────────────────
    if changed:
        # FUN_0046b050 — string serializer for the token-list (absorbed as debug log).
        # SEND_LOG(..., L"Recalculating: Because we are CANCELLING: (%s)")
        _log.debug(
            "Recalculating: Because we are CANCELLING: (%s)",
            ' '.join(str(p) for p in pce_powers),
        )
        # C: BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)
        build_alliance_msg(state, 0x66)

    return changed


def _remove_dmz(state: InnerGameState, tokens: list) -> bool:
    """
    Port of named export REMOVE_DMZ(param_1) — decompile-verified.

    Called from cal_move()'s NOT-DMZ branch when a NOT(DMZ(...)) press is
    received, signalling that a previous DMZ arrangement is being revoked.

    Decompile walk (decompiled.txt lines 2-182):

    Setup
    -----
    - uStack_74 = own power index  (param_1+8+0x2424 = albert_power_idx)
    - local_60  = GetSubList(press, 1)  → DMZ power-list
    - local_34  = GetSubList(press, 2)  → DMZ province-list
    - uVar6   = FUN_00465930(local_60)  → n_powers
    - uStack_84 = FUN_00465930(local_34) → n_provs

    Triple loop (lines 78-134):
      outer i (iStack_7c):  0 .. n_powers-1
        outer_power = GetListElement(local_60, i) → uStack_88 / uVar13
      inner j (iStack_78):  0 .. n_powers-1
        j_power = GetListElement(local_60, j) → uStack_6c
        condition: (j != i) OR (n_powers == 1)
          inner k (iStack_94): 0 .. n_provs-1
            province = GetListElement(local_34, k) → uStack_80

            BRANCH A (uVar13 == uStack_74, i.e. outer_power == own):
              this = &DAT_00bb6f28 + uVar3 * 0xc
                     (uVar3 = uStack_6c = j_power)
              puVar8 = GameBoard_GetPowerRec(this, aiStack_14, &province)
              puVar14 = *puVar8          (lower-bound node)
              ppiVar12 = puVar8[1]       (found iterator)
              ppiVar2 = &DAT_00bb6f2c[uVar3 * 3]  (DesigListA head for j_power)
              if ppiVar12 != ppiVar2:
                FUN_00402b70(this, &apvStack_24, puVar14, ppiVar12)
                cStack_95 = '\\x01'   (changed)

            BRANCH B (outer_power != own):
              this = &DAT_00bb7028 + uVar13 * 0xc
                     (uVar13 = outer_power)
              puVar8 = GameBoard_GetPowerRec(this, aiStack_1c, &province)
              ppiVar2 = &DAT_00bb702c[uVar13 * 3]  (DesigListB head for outer_power)
              if ppiVar12 != ppiVar2:
                FUN_00402b70(this, &pvStack_50, puVar14, ppiVar12)
                cStack_95 = '\\x01'   (changed)

    Post-loop (lines 135-163):
      if changed:
        FUN_0046b050 → log "Recalculating: Because we removed a DMZ: %s"
        BuildAllianceMsg(0x66) — stub

    Python mapping:
      uStack_74            → state.albert_power_idx
      DAT_00bb6f28[p*0xc]  → designation map for p (BRANCH A — own side)
      DAT_00bb6f2c[p*3]    → g_desig_list_a[p]  (sentinel/head pointer)
      ppiVar12 != ppiVar2  → province is in g_desig_list_a[p] (non-empty find)
      DAT_00bb7028[p*0xc]  → designation map for p (BRANCH B — sender side)
      DAT_00bb702c[p*3]    → g_desig_list_b[p]
      FUN_00402b70         → std::map::insert / _Copy — absorbed as list membership

    FUN_0047a948 (AssertFail) is called when the GameBoard_GetPowerRec
    sanity-check fails (puVar14 == 0 or puVar14 != this); absorbed as
    a silent continue in Python (the iterator is invalid, so we skip).

    Callees absorbed:
      FUN_00465870 ✓ (list init — Python list literals)
      GetSubList ✓ (absorbed into token parsing)
      AppendList ✓ (absorbed)
      FreeList   ✓ (absorbed)
      FUN_00465930 ✓ (len())
      GetListElement ✓ (absorbed into indexed list access)
      GameBoard_GetPowerRec  → g_sc_owner membership check (absorbed)
      FUN_00402b70           → absorbed as `province in g_desig_list_a/B[p]`
      FUN_0047a948 (AssertFail) → absorbed as silent skip
      FUN_0046b050 ✓ (absorbed as debug log)
      BuildAllianceMsg   → stub (unchecked)
    """
    # Cross-slice call: helpers still in package __init__.py.  Deferred import
    # at call time avoids a circular import during package initialisation.
    from . import build_alliance_msg

    import logging as _logging
    _log = _logging.getLogger(__name__)

    own: int = getattr(state, 'albert_power_idx', 0)

    # ── Parse token stream ────────────────────────────────────────────────────
    # GetSubList(press, 1) → power list  (local_60)
    # GetSubList(press, 2) → province list (local_34)
    # In Python, `tokens` is the flat unwrapped list from cal_move().
    # Layout after CAL_MOVE strips the leading 'DMZ': [pow1 pow2 … prov1 prov2 …]
    # We split the same way as _handle_dmz: values < 7 are power indices,
    # values >= 7 are province indices.
    dmz_powers: list[int] = []
    dmz_provs:  list[int] = []
    for tok in tokens[1:]:
        try:
            v = int(tok)
        except (ValueError, TypeError):
            continue
        if v < 7:
            dmz_powers.append(v)
        else:
            dmz_provs.append(v)

    n_powers: int = len(dmz_powers)   # uVar6
    n_provs:  int = len(dmz_provs)    # uStack_84

    if n_powers == 0 or n_provs == 0:
        return False

    # Lazy-init designation-list state (same fields used by _cancel_pce).
    g_desig_list_a: dict = getattr(state, 'g_desig_list_a', {})
    g_desig_list_b: dict = getattr(state, 'g_desig_list_b', {})

    changed: bool = False   # cStack_95

    # ── Triple loop ───────────────────────────────────────────────────────────
    for i_idx in range(n_powers):                  # iStack_7c
        outer_power = dmz_powers[i_idx]            # uStack_88 / uVar13

        for j_idx in range(n_powers):              # iStack_78
            j_power = dmz_powers[j_idx]            # uStack_6c

            # Condition: (j != i) OR (n_powers == 1)
            # C: if (((iVar11 != iVar10) || (uVar6 == 1)) && (iStack_94 = 0, 0 < (int)uStack_84))
            if i_idx == j_idx and n_powers != 1:
                continue

            for k_idx in range(n_provs):           # iStack_94
                province = dmz_provs[k_idx]        # uStack_80

                if outer_power == own:
                    # ── BRANCH A: outer power is own ──────────────────────────
                    # C: this = &DAT_00bb6f28 + uVar3 * 0xc  (j_power = uVar3 = uStack_6c)
                    # GameBoard_GetPowerRec(this, aiStack_14, &province)
                    # ppiVar2 = &DAT_00bb6f2c[uVar3 * 3]  (DesigListA sentinel)
                    # if (ppiVar12 != ppiVar2) → found → FUN_00402b70 (erase) → changed
                    #
                    # Python absorption: remove province from j_power's designation list.
                    desig_a: list = g_desig_list_a.get(j_power, [])
                    if province in desig_a:
                        # FUN_00402b70 — _stl_tree_erase: remove the found entry.
                        desig_a.remove(province)
                        changed = True

                else:
                    # ── BRANCH B: non-own outer power ─────────────────────────
                    # C: this = &DAT_00bb7028 + uVar13 * 0xc  (outer_power = uVar13)
                    # GameBoard_GetPowerRec(this, aiStack_1c, &province)
                    # ppiVar2 = &DAT_00bb702c[uVar13 * 3]  (DesigListB sentinel)
                    # if (ppiVar12 != ppiVar2) → found → FUN_00402b70 (erase) → changed
                    desig_b: list = g_desig_list_b.get(outer_power, [])
                    if province in desig_b:
                        desig_b.remove(province)
                        changed = True

    # ── Post-loop: log if changed ─────────────────────────────────────────────
    # C lines 135-163:
    #   FUN_0046b050(press, &pvStack_50) → string of token list
    #   SEND_LOG(&iStack_8c, L"Recalculating: Because we removed a DMZ: %s")
    #   uStack_74 = 0x66; BuildAllianceMsg(&DAT_00bbf638, ..., &uStack_74)
    if changed:
        prov_str = ' '.join(str(p) for p in dmz_provs)
        _log.debug(
            "Recalculating: Because we removed a DMZ: (%s)", prov_str
        )
        # C: uStack_74 = 0x66; BuildAllianceMsg(&DAT_00bbf638, ..., &uStack_74)
        build_alliance_msg(state, 0x66)

    return changed


def _not_xdo(state: "InnerGameState", tokens: list) -> bool:
    """
    Port of named function NOT_XDO(void) — decompile-verified against decompiled.txt.

    Called from cal_move()'s NOT-XDO branch when a NOT(XDO(...)) press is
    received, cancelling a previously submitted XDO order proposal.

    Decompile walk (decompiled.txt lines 2-115):

    Setup / token extraction
    ------------------------
    - FUN_00465870(local_1c)         — init empty local token list.
    - GetSubList(&stack4, &pvStack_38, 1)
        → extract sub-list at index 1 from the incoming XDO press
          (the inner XDO order content: unit, order-cmd, dest, …).
    - AppendList(local_1c, ppvVar8)  — merge into local_1c.
    - FreeList(&pvStack_38)          — release temp.
    - GetSubList(local_1c, &pvStack_38, 0)
        → this = first sub-element of local_1c (the order content group).
    - GetListElement(this, &uStack_46, 0)
        → uStack_46 (low byte) = element 0 of that group.
          In practice this is the sender/unit province byte; used in
          the TreeIterator_Advance sentinel check but NOT stored separately.
    - FreeList(&pvStack_38).

    Registration loop (lines 56-72)
    ---------------------------------
    - pCStack_3c = *in_stack_00000018   (head of outer candidate list)
    - puStack_40 = &stack0x00000014     (iterator = current node)
    - while pCVar1 != in_stack_00000018 (not sentinel):
        FUN_00419300(
            &DAT_00bb66f8 + *(pCVar1+0xc) * 0xc,  — per-power NOT-XDO list
            &pvStack_38,
            local_1c                               — the extracted XDO content
        )
        TreeIterator_Advance(&puStack_40)

    Python absorption:
      in_stack_00000018 = state.g_xdo_candidate_list  (set by FUN_00405090 in caller)
      *(pCVar1+0xc)     = entry['power'] (power index from candidate node)
      DAT_00bb66f8 + p*0xc → state.g_not_xdo_list_by_sender[power]  (new field)
      FUN_00419300(…, local_1c) → append extracted XDO content to that list

    Post-loop cleanup (lines 73-114)
    -----------------------------------
    - FUN_0046b050 → serialize press token list to string (absorbed as debug log arg).
    - SEND_LOG("Recalculating: Because we have applied a NOT XDO: (%s)")
    - BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)  — stub (unchecked).
    - FreeList(local_1c)
    - FreeList(&stack4)
    - SerializeOrders + _free(in_stack_00000018) → clear g_xdo_candidate_list.
    - Returns CONCAT31(..., 1) → True always.

    New state field:
      g_not_xdo_list_by_sender : dict[int, list]  — DAT_00bb66f8 per-power list.
        Keyed by power index; each value is a list of extracted XDO content lists
        representing orders that the peer is retracting.

    Unchecked callees (retained as stubs/absorbed):
      FUN_00419300           — absorbed as list append
      BuildAllianceMsg       — unchecked stub
    """
    # Cross-slice call: helpers still in package __init__.py.  Deferred import
    # at call time avoids a circular import during package initialisation.
    from . import build_alliance_msg, _ordered_token_seq_insert

    import logging as _logging
    _log = _logging.getLogger(__name__)

    # ── Step 1: extract XDO inner content (GetSubList index 1) ───────────────
    # C: GetSubList(&stack4, &pvStack_38, 1)  → sub-list at index 1 of the
    #    incoming press (the XDO order content group).
    # In Python `tokens` is the flat unwrapped NOT-XDO list from cal_move().
    # Layout: ['XDO', sender_power, order_cmd, dest, ...]
    # We treat tokens[1:] as the XDO inner content (local_1c equivalent).
    xdo_content: list = list(tokens[1:]) if len(tokens) > 1 else []

    # ── Step 2: registration loop over in_stack_00000018 ─────────────────────
    # C: pCStack_3c = *in_stack_00000018 (head); puStack_40 = &stack0x14 (iter)
    # while pCVar1 != in_stack_00000018 (sentinel):
    #     FUN_00419300(&DAT_00bb66f8 + *(pCVar1+0xc)*0xc, &pvStack_38, local_1c)
    #     TreeIterator_Advance(&puStack_40)
    #
    # Absorbed: iterate g_xdo_candidate_list; for each entry append xdo_content
    # into g_not_xdo_list_by_sender[entry['power']].
    candidate_list: list = getattr(state, 'g_xdo_candidate_list', [])

    for entry in candidate_list:
        power: int = int(entry.get('power', entry.get('node_power', 0)))
        # FUN_00419300(&DAT_00bb66f8 + power*0xc, &pvStack_38, local_1c)
        # → inserts local_1c (XDO content) into the per-power NOT-XDO ordered set.
        _ordered_token_seq_insert(
            state.g_not_xdo_list_by_sender.setdefault(power, []),
            xdo_content,
        )

    # ── Post-loop: log + BuildAllianceMsg ─────────────────────────────────────
    # C: FUN_0046b050 → serialize token list → SEND_LOG("... NOT XDO: (%s)")
    _log.debug(
        "Recalculating: Because we have applied a NOT XDO: (%s)",
        ' '.join(str(t) for t in tokens[1:]),
    )
    # C: BuildAllianceMsg(&DAT_00bbf638, ..., 0x66)
    build_alliance_msg(state, 0x66)

    # ── Cleanup: clear candidate list (SerializeOrders + _free) ──────────────
    # C: SerializeOrders(&stack14,...) + _free(in_stack_00000018)
    if hasattr(state, 'g_xdo_candidate_list'):
        state.g_xdo_candidate_list = []

    # Always returns '\x01' (True) per decompile line 114.
    return True
