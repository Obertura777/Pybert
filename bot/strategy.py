"""Strategy: stab/deviate/hostility/friendly/free-list helpers.

Split from bot.py during the 2026-04 refactor.

Contains the decompile's strategy-layer functions:

- ``_stab_enemy_slot_remove`` / ``_stab_clear_ally_list`` — 3-slot queue helpers
- ``_destroy_inner_list`` / ``free_list`` / ``_destroy_candidate_tree`` — C++ list/tree
  destructor ports (absorbed as Python list ops)
- ``_stabbed``                 — stab detection + ally-slot promotion
- ``_deviate_move``            — deviate-move planning
- ``_apply_deviate_stab``      — stab application helper
- ``_friendly``                — wrapper around heuristics.friendly
- ``_hostility``               — hostility evaluation
- ``_post_friendly_update``    — ComputeInfluenceMatrix wrapper (FUN_0040d8c0)

Module-level deps: ``..state.InnerGameState``, ``..communications.friendly``,
``..heuristics`` (``cal_board``, ``compute_influence_matrix``).  Two deferred
imports inside bodies (``compute_order_dip_flags``, ``_update_relation_history``)
are kept local to avoid tightening the communications ↔ bot coupling.
"""

import logging
import random

import numpy as np

from ..state import InnerGameState
from ..communications import friendly
from ..heuristics import cal_board, compute_influence_matrix

logger = logging.getLogger(__name__)


def _stab_enemy_slot_remove(slots, target):
    """Remove target from the 3-slot g_EnemySlot queue.

    Slot[0] removal left-shifts remaining entries (C lines 418-426 / 430-436).
    Slot[1] or slot[2] removal just clears that slot (C lines 437-455).
    """
    if slots[0] == target:
        slots[0] = slots[1] if slots[1] != -1 else -1
        if slots[1] != -1:
            slots[1] = slots[2] if slots[2] != -1 else -1
            slots[2] = -1
    elif slots[1] == target:
        slots[1] = -1
    elif slots[2] == target:
        slots[2] = -1


def _destroy_inner_list(container):
    """FUN_00401950 — recursive C linked-list destructor.

    C node layout: node[0]=_Next, node[2]=inner sub-data (also a list head),
    byte@+0x11=_Isnil (non-zero = sentinel node). Walks from the first real
    node to the sentinel, recursively calling itself on node[2] before
    freeing each node, then advances via node[0].

    Python: clears `container` in-place, recursing into any nested list/set
    elements (node[2] equivalents) before clearing the outer container.
    Python GC handles deallocation; only clearing is required.

    Callers and their Python mappings:
      - DAT_00bb65e4 teardown (EvaluateOrderProposalsAndSendGOF): called on
        node[2] of each g_DmzOrderList node to clear its inner province
        sub-list before the outer teardown loop frees the node.
      - DEVIATE_MOVE / STABBED: called on the first real node of
        g_AllyPromiseList[power] / g_AllyCounterList[power] to clear the
        per-power designation list on stab detection.
    """
    if container is None:
        return
    if isinstance(container, list):
        for item in container:
            if isinstance(item, (list, set)):
                _destroy_inner_list(item)
        container.clear()
    elif hasattr(container, 'clear'):
        container.clear()


def free_list(lst):
    """FUN_00465fa0 — Destructs and zeros a token-list structure.

    C layout (3-pointer / 12-byte header at param_1):
      param_1[0] : ptr to element vector; the dword at (ptr - 4) stores the
                   element count; the vector itself holds count × 2-byte tokens
                   (Diplomacy wire tokens, stored as shorts); each element is
                   destructed by ClearConvoyState before the block is freed.
      param_1[1] : capacity / end pointer — not touched by this function.
      param_1[2] : auxiliary allocation (separate heap block); freed and zeroed
                   independently.

    Both allocations are released and their header slots zeroed.

    Note: ClearConvoyState appears here as the eh_vector_destructor_iterator
    callback — it is the per-element destructor registered by the MSVC EH
    machinery, not the game-logic convoy-state reset of the same name.  For
    2-byte POD tokens the destructor is effectively a no-op.

    Python: clears the list in-place; GC handles deallocation; the auxiliary
    allocation has no Python analogue.
    """
    if lst is None:
        return
    if isinstance(lst, list):
        lst.clear()
    elif hasattr(lst, 'clear'):
        lst.clear()


def _destroy_candidate_tree(candidate_list):
    """FUN_00410cf0 — Post-order RB-tree destructor for g_CandidateList2 per-power trees.

    Node layout (g_GeneralOrders / g_CandidateList2, ~30 bytes):
      +0x00  _Left ptr     — iterated after freeing current node
      +0x04  _Parent ptr   — (unused during traversal)
      +0x08  _Right ptr    — recursed first
      +0x0C  value[0]      — ptr to embedded token/order list (freed by FreeList)
      +0x10  value[1..3]   — remaining payload fields
      +0x1C  _Color byte
      +0x1D  _Isnil byte   — non-zero = sentinel; loop runs while _Isnil == 0

    C traversal (post-order, right via recursion then left via iteration):
        while node._Isnil == 0:
            FUN_00410cf0(node._Right)       # recurse right subtree
            saved = node._Left
            FreeList(&node.value)           # free embedded list rooted at value[0]
            free(node)
            node = saved

    Called from ScoreOrderCandidates step 1 for each power as:
        FUN_00410cf0(*(int **)(sentinel._Parent))   # pass tree root

    Python: g_GeneralOrders[power] = [order_seq, ...] where each order_seq is a
    dict that may carry a nested token list.  Clear all embedded lists then clear
    the container — mirrors FreeList + free(node) without heap management.
    """
    if candidate_list is None:
        return
    if isinstance(candidate_list, list):
        for entry in candidate_list:
            if isinstance(entry, dict):
                for key in ('tokens', 'token_list', 'orders', 'sub_list'):
                    sub = entry.get(key)
                    if isinstance(sub, list):
                        free_list(sub)   # FreeList(&node.value)
                        break
        candidate_list.clear()
    elif hasattr(candidate_list, 'clear'):
        candidate_list.clear()


def _stab_clear_ally_list(state, attr, power_idx):
    """Clear g_AllyPromiseList[power_idx] or g_AllyCounterList[power_idx].

    Delegates to _destroy_inner_list (FUN_00401950) for the actual clearing.
    Supports dict-of-sets (preferred), list-of-sets, and legacy np.ndarray.
    """
    lst = getattr(state, attr, None)
    if lst is None:
        return
    if isinstance(lst, dict):
        sub = lst.get(power_idx)
        if sub is not None:
            _destroy_inner_list(sub)
        else:
            lst[power_idx] = set()
    elif isinstance(lst, list) and 0 <= power_idx < len(lst):
        sub = lst[power_idx]
        if isinstance(sub, (list, set)):
            _destroy_inner_list(sub)
        else:
            lst[power_idx] = 0
    elif hasattr(lst, '__setitem__'):
        try:
            lst[power_idx] = 0
        except (IndexError, ValueError):
            pass


def _stabbed(state: InnerGameState) -> None:
    """STABBED (FUN_0042c730). Stab detection for the move-order phase (Year-1).

    Double loop (outer=row=victim, inner=col=stabber). For each pair:

    Phase 0 — zero-init pass (identical to DEVIATE_MOVE):
      g_StabFlag, g_NeutralFlag, g_CeaseFire, g_PeaceSignal always;
      g_SomeCoopScore (DAT_0062c580) if SPR;
      g_CoopFlag (DAT_0062be98) if FAL.

    Phase 1 — unit-list proposed-order check (Albert+0x2450/54):
      For each unit of power col (not row): check if the unit's province has a
      per-province alliance record (Albert+prov*0x24) whose ally field == row.
      Python proxy: g_AllyDesignation_A/B[prov] == row.
      Sets stab_flag for this (row,col) pair.

    Phase 2 — submitted-order stab check (Albert+0x248c/90):
      For each submitted order by col (not row):
        MTO/CTO (type 2/6): dest must appear in g_AllyCounterList[col] (when
          col attacked row=own_power) or g_AllyPromiseList[row] (when col=own
          attacked row).
        SUP-MTO (type 4): same check using support-target province.
      If destination not found in expected list → stab_flag set.

    On stab (stab_flag==True):
      g_StabFlag[row, col] = 1.
      If row==own_power (victim): log + set g_StabbedFlag + clear stabber's
        ally lists + update g_EnemySlot (removal) + g_OpeningStickyMode.
      If col==own_power (stabber): clear victim's ally lists.
      Always: bilateral g_SomeCoopScore or g_CoopFlag; bilateral trust reset.
    """
    own_power = int(getattr(state, 'albert_power_idx', 0))
    num_powers = 7
    season = state.g_season

    # ── Phase 0: Init pass ────────────────────────────────────────────────────
    # Arrays: int[pow*21+other], stride 0x54=21*4 per row, 4 per col.
    # In Python they are (7,7); fill(0) is equivalent.
    state.g_StabFlag.fill(0)
    state.g_NeutralFlag.fill(0)
    state.g_CeaseFire.fill(0)
    state.g_PeaceSignal.fill(0)
    if season == 'SPR':
        state.g_CoopScoreFlag_A.fill(0)
    elif season == 'FAL':
        state.g_CoopScoreFlag_B.fill(0)

    # ── Phase 1: unit-list province-designation check (Albert+0x2450/54) ─────
    # C: for each unit node (iVar15) where unit.power==col and col!=row:
    #   byte  at Albert+3+prov*0x24        → nonzero = has ally designation
    #   ushort at Albert+0x20+prov*0x24    → hi='A', lo=designated ally power
    #   if hi!='A': lo = 0x14 (invalid)
    #   if lo == row: uStack_92 |= 1
    # Python proxy: g_AllyDesignation_A[prov]==row or g_AllyDesignation_B[prov]==row.
    stab_unit = np.zeros((num_powers, num_powers), dtype=bool)
    for prov, unit in state.unit_info.items():
        col = int(unit['power'])
        prov_id = int(prov) if not isinstance(prov, int) else prov
        if prov_id >= 256:
            continue
        desig_a = int(state.g_AllyDesignation_A[prov_id])
        desig_b = int(state.g_AllyDesignation_B[prov_id])
        for row in range(num_powers):
            if row == col:
                continue
            if desig_a == row or desig_b == row:
                stab_unit[row, col] = True

    # ── Phase 2: submitted-order stab check (Albert+0x248c/90) ───────────────
    # g_AllyCounterList[col]: set of expected dest provinces for col's moves
    #   (checked when col != own, row == own; C: DAT_00bb7028/2c per power)
    # g_AllyPromiseList[row]: set of expected dest provinces for own's moves
    #   into row's territory (C: DAT_00bb6f28/2c per power)
    # Submitted orders in g_SubmittedOrderList lack order_type; treated as MTO.
    ally_counter = getattr(state, 'g_AllyCounterList', None)
    ally_promise = getattr(state, 'g_AllyPromiseList', None)

    def _in_list(lst, power, dest):
        if lst is None:
            return False
        if isinstance(lst, dict):
            return dest in lst.get(power, set())
        if isinstance(lst, (list, np.ndarray)):
            try:
                entry = lst[power]
                if isinstance(entry, set):
                    return dest in entry
            except (IndexError, KeyError):
                pass
        return False

    stab_order = np.zeros((num_powers, num_powers), dtype=bool)
    for order in getattr(state, 'g_SubmittedOrderList', []):
        col = int(order.get('power', -1))
        if not (0 <= col < num_powers):
            continue
        dest = int(order.get('dst_prov', -1))
        if dest < 0:
            continue
        # Treat all submitted orders as MTO-type (order_type not in Python state).
        # Case A: attacker (col) hits own_power (row==own_power)
        if col != own_power:
            row = own_power
            if not _in_list(ally_counter, col, dest):
                stab_order[row, col] = True
        # Case B: own_power (col) moves into other power's (row) territory
        elif col == own_power:
            for row in range(num_powers):
                if row == col:
                    continue
                if not _in_list(ally_promise, row, dest):
                    stab_order[row, col] = True

    # ── Phase 3: apply stab consequences ─────────────────────────────────────
    slots = list(map(int, state.g_EnemySlot))
    for row in range(num_powers):
        for col in range(num_powers):
            if row == col:
                continue
            if not (stab_unit[row, col] or stab_order[row, col]):
                continue

            state.g_StabFlag[row, col] = 1

            # Victim == own_power (C lines 270-367)
            if row == own_power:
                logger.info("We have been stabbed by (%d) during the turn", col)
                state.g_StabbedFlag = 1
                logger.info("Enemy desired because of stab")
                _stab_clear_ally_list(state, 'g_AllyPromiseList', col)
                _stab_clear_ally_list(state, 'g_AllyCounterList', col)

            # Stabber == own_power (C lines 368-398)
            if col == own_power:
                _stab_clear_ally_list(state, 'g_AllyPromiseList', row)
                _stab_clear_ally_list(state, 'g_AllyCounterList', row)

            # Season-dependent bilateral CoopScore flags (C lines 399-413)
            if season in ('SUM', 'FAL'):
                state.g_CoopScoreFlag_A[row, col] = 1
                state.g_CoopScoreFlag_A[col, row] = 1
            else:  # AUT, WIN, SPR
                state.g_CoopScoreFlag_B[row, col] = 1
                state.g_CoopScoreFlag_B[col, row] = 1

            # Bilateral trust reset (C lines 409-413)
            state.g_AllyTrustScore[row, col] = 0
            state.g_AllyTrustScore_Hi[row, col] = 0
            state.g_AllyTrustScore[col, row] = 0
            state.g_AllyTrustScore_Hi[col, row] = 0

            # g_EnemySlot removal — victim==own: remove stabber;
            # stabber==own: remove victim (C lines 414-455).
            # Slot[0] removal left-shifts; slot[1]/[2] just cleared.
            if row == own_power:
                _stab_enemy_slot_remove(slots, col)
                # g_OpeningStickyMode (C lines 415-417)
                if state.g_OpeningStickyMode == 1 and col != state.g_OpeningEnemy:
                    state.g_OpeningStickyMode = 0
            if col == own_power:
                _stab_enemy_slot_remove(slots, row)

    state.g_EnemySlot = np.array(slots[:3], dtype=np.int32)


def _deviate_move(state: InnerGameState) -> None:
    """DEVIATE_MOVE (FUN_0043a000). Stab detection + consequence engine.
    Year >= 2 or retreat phase.

    Structure (outer loop = all 7 powers as victim perspective):
      Phase 0 – zero init pass (6 arrays, numPowers×numPowers)
      Phase 1 – retreat-list peace signal (g_RetreatList; LAB_0043a000 → do-loop line 162)
      Phase 2 – order-history retreat stab detection (g_OrderHistList type-7 records)
      Phase 3 – movement-order deviation stab (g_RetreatList; LAB_0043a175 line 382)
      On stab detected → _apply_deviate_stab consequences
    """
    own_power = getattr(state, 'albert_power_idx', 0)
    num_powers = 7
    season = state.g_season

    # Phase 0: Init pass — identical stride/layout in both STABBED and DEVIATE_MOVE
    state.g_StabFlag.fill(0)
    state.g_NeutralFlag.fill(0)
    state.g_CeaseFire.fill(0)
    state.g_PeaceSignal.fill(0)
    if season == 'SPR':
        state.g_CoopScoreFlag_A.fill(0)
    elif season == 'FAL':
        state.g_CoopScoreFlag_B.fill(0)

    # Phases 1 & 3 share one do-loop over g_RetreatList (decompile line 162;
    # Phase 3 continues at LAB_0043a175 line 382; UnitList_Advance at line 1323).
    # Outer loop is the victim-power loop; inner loop iterates g_RetreatList.
    retreat_list = getattr(state, 'g_RetreatList', [])
    attack_map   = getattr(state, 'g_AttackMap', None)  # int64[pow*0x100+prov]; 2=active

    for p in range(num_powers):
        for rec in retreat_list:
            other = int(rec.get('power', -1))
            if not (0 <= other < num_powers) or other == p:
                continue

            src_prov = int(rec.get('src_province', -1))
            dst_prov = int(rec.get('dst_province', -1))

            # ── Phase 1: retreat-zone peace signal (LAB_0043a000 do-loop) ───────
            # AdjacencyList_FilterByUnitType on src_prov → adjacent attack sources.
            # For each adj: if adj designated to p AND dst_prov designated to p
            #               → g_PeaceSignal[p, other] = 1.
            # C uses g_AllyDesignation_A/B/C (004d0e10/1610/1e10); Python uses the
            # available designation arrays as an approximation.
            if 0 <= dst_prov < 256:
                for adj in state.adj_matrix.get(src_prov, []):
                    if adj >= 256:
                        continue
                    adj_in_p = (
                        int(state.g_AllyDesignation_A[adj]) == p or
                        int(state.g_AllyDesignation_B[adj]) == p or
                        int(state.g_AllyDesignation_C[adj]) == p
                    )
                    dst_in_p = (
                        int(state.g_AllyDesignation_A[dst_prov]) == p or
                        int(state.g_AllyDesignation_B[dst_prov]) == p or
                        int(state.g_AllyDesignation_C[dst_prov]) == p
                    )
                    if adj_in_p and dst_in_p:
                        state.g_PeaceSignal[p, other] = 1
                        break

            # ── Phase 3: movement-order deviation stab (LAB_0043a175) ───────────
            order_type = int(rec.get('order_type', -1))
            sup_src    = int(rec.get('sup_src', -1))
            sup_dst    = int(rec.get('sup_dst', -1))
            endgame_flag = int(rec.get('endgame_flag', 0))

            # End-game override: g_NearEndGameFactor >= 4.0 AND sc_count[other] > 2
            # node+0x6b endgame_flag: if set AND in endgame path → treat as stab without trust
            endgame_override = (
                state.g_NearEndGameFactor >= 4.0 and
                int(state.sc_count[other]) > 2 and
                endgame_flag == 1
            )

            # Determine if this record constitutes a deviation into power p's territory
            deviation = False

            if order_type in (2, 6):  # MTO or CTO
                if 0 <= dst_prov < 256:
                    if (int(state.g_AllyDesignation_A[dst_prov]) == p or
                            int(state.g_AllyDesignation_B[dst_prov]) == p or
                            int(state.g_AllyDesignation_C[dst_prov]) == p):
                        deviation = True
                        # "Unduly pressured" sub-case (C lines ~4858-4860):
                        # attacker already had an active attack there (AttackMap==2)
                        # AND own power had a positive score → g_CeaseFire, not stab.
                        if (p == own_power and attack_map is not None and
                                0 <= other < 7 and 0 <= dst_prov < 256 and
                                int(attack_map[other, dst_prov]) == 2):
                            state.g_CeaseFire[p, other] = 1
                            logger.info(
                                "We have unduly pressured by (%d) during this turn", other)
                            deviation = False  # cease-fire set; not a stab

            elif order_type == 4:  # SUP-MTO
                if 0 <= sup_dst < 256:
                    if (int(state.g_AllyDesignation_A[sup_dst]) == p or
                            int(state.g_AllyDesignation_B[sup_dst]) == p or
                            int(state.g_AllyDesignation_C[sup_dst]) == p):
                        deviation = True
                elif 0 <= sup_src < 256:
                    for adj in state.adj_matrix.get(sup_src, []):
                        if adj >= 256:
                            continue
                        if (int(state.g_AllyDesignation_A[adj]) == p or
                                int(state.g_AllyDesignation_B[adj]) == p or
                                int(state.g_AllyDesignation_C[adj]) == p):
                            deviation = True
                            break
                if deviation and p == own_power:
                    logger.info(
                        "Power (%d) did not make his expected support order this turn", other)

            elif order_type == 3:  # SUP-HLD
                if 0 <= sup_src < 256:
                    for adj in state.adj_matrix.get(sup_src, []):
                        if adj >= 256:
                            continue
                        if (int(state.g_AllyDesignation_A[adj]) == p or
                                int(state.g_AllyDesignation_B[adj]) == p or
                                int(state.g_AllyDesignation_C[adj]) == p):
                            deviation = True
                            break
                if deviation and p == own_power:
                    logger.info(
                        "Power (%d) did not make his expected support order this turn", other)

            else:
                # Type ≠ 2/3/4/6 (e.g. RTO=7, DSB=8, HLD=1): "did not make expected move"
                # Only log when p is our own power (research.md §Phase 3).
                if p == own_power:
                    logger.info(
                        "Power (%d) did not make his expected move this turn", other)
                # No designation check; flag as deviation only for own-power victim.
                deviation = (p == own_power)

            if not deviation:
                continue

            # Final stab/neutral marking (LAB_0043aacd):
            # endgame_override OR trust[p][other] > 0 → stab
            if endgame_override or int(state.g_AllyTrustScore[p, other]) > 0:
                _apply_deviate_stab(state, other, p, own_power, num_powers, season)
            else:
                state.g_NeutralFlag[p, other] = 1
                if p == own_power:
                    logger.info("We have been attacked by (%d) during the turn", other)

    # Phase 2: order-history retreat stab detection (C: Albert+0x2498/0x249c = g_OrderHistList)
    # Outer loop uStack_1c0 = victim power p (0..numPowers-1).
    # Gate: trust[attacker + p*21] > 0.  Order type 7 = retreat order.
    # Checks expected_dest against ally designation; determines stab vs neutral.
    order_hist = getattr(state, 'g_OrderHistList', [])
    for p in range(num_powers):
        for rec in order_hist:
            attacker = int(rec.get('power', -1))
            if not (0 <= attacker < num_powers) or attacker == p:
                continue

            # Gate: trust[attacker + p*21] > 0  (C: g_AllyTrustScore_Hi check)
            if int(state.g_AllyTrustScore[attacker, p]) <= 0:
                continue

            order_type = int(rec.get('order_type', -1))
            if order_type != 7:
                continue  # phase 2 only handles retreat orders (type 7)

            expected_dest = int(rec.get('expected_dest', rec.get('dst_province', rec.get('dst_prov', -1))))
            if expected_dest < 0:
                continue

            # Check expected_dest against ally designation tables
            # C: DAT_004cf610/DAT_004cfe10 (two per-province designation arrays).
            # Python approximation via g_AllyDesignation_A/B indexed by province.
            desig_a = int(state.g_AllyDesignation_A[expected_dest]) if expected_dest < 256 else -1
            desig_b = int(state.g_AllyDesignation_B[expected_dest]) if expected_dest < 256 else -1
            if desig_a != p and desig_b != p:
                continue  # dest not in p's designated ally territory

            # Reverse-trust check determines stab vs neutral (C: lines 260-274)
            trust_pa = int(state.g_AllyTrustScore[p, attacker])
            if trust_pa <= 0:
                # Both directions ≤ 0 → neutral attack
                state.g_NeutralFlag[attacker, p] = 1
                if p == own_power:
                    logger.info("We have been attacked by (%d) during the retreat phase", attacker)
            else:
                # At least one direction > 0 → stab (LAB_0043bad4)
                _apply_deviate_stab(state, attacker, p, own_power, num_powers, season,
                                    retreat_phase=True)


def _apply_deviate_stab(state, attacker, p, own_power, num_powers, season,
                        retreat_phase=False):
    """Apply stab consequences from DEVIATE_MOVE (LAB_0043bad4 / LAB_0043b0b2).

    Sets g_StabFlag[attacker,p], bilateral CoopScoreFlag (season-dependent),
    bilateral trust reset, and — when p==own_power — clears AllyMatrix rows,
    manages g_EnemySlot (removal-based, C lines 1263-1321), g_OpeningStickyMode.
    """
    state.g_StabFlag[attacker, p] = 1

    # Bilateral CoopScoreFlag update (C lines 306-325):
    #   SUM or FAL → g_CoopScoreFlag_A[attacker+p*21] and [attacker*21+p]
    #   AUT, WIN, SPR → g_CoopScoreFlag_B (same indices)
    if season in ('SUM', 'FAL'):
        state.g_CoopScoreFlag_A[attacker, p] = 1
        state.g_CoopScoreFlag_A[p, attacker] = 1
    else:
        state.g_CoopScoreFlag_B[attacker, p] = 1
        state.g_CoopScoreFlag_B[p, attacker] = 1

    # Bilateral trust reset (C lines 358-366)
    state.g_AllyTrustScore[attacker, p] = 0
    state.g_AllyTrustScore[p, attacker] = 0

    if p == own_power:
        if retreat_phase:
            logger.info("We have been stabbed by (%d) during the retreat phase", attacker)
        else:
            logger.info("We have been stabbed by (%d) during the turn", attacker)

        # Clear per-power designation lists via _destroy_inner_list (FUN_00401950):
        # C: FUN_00401950(*(int**)(DAT_00bb6f2c[attacker*3]+4))  → g_AllyPromiseList
        #    FUN_00401950(*(int**)(DAT_00bb702c[attacker*3]+4))   → g_AllyCounterList
        _stab_clear_ally_list(state, 'g_AllyPromiseList', attacker)
        _stab_clear_ally_list(state, 'g_AllyCounterList', attacker)

        # Clear g_AllyMatrix[attacker row] (C lines 1219-1222)
        for j in range(num_powers):
            state.g_AllyMatrix[attacker, j] = 0

        # g_EnemySlot: REMOVAL-based management (C lines 1263-1321).
        # When attacker == slot[k]: remove attacker, shift remaining slots left.
        # This is distinct from STABBED's push-front insertion.
        slots = list(getattr(state, 'g_EnemySlot', np.array([-1, -1, -1])))
        if attacker in slots:
            idx = slots.index(attacker)
            slots.pop(idx)
            slots.append(-1)
        state.g_EnemySlot = slots[:3]

        # g_OpeningStickyMode (C lines 1254-1261)
        if getattr(state, 'g_OpeningStickyMode', 0) == 1:
            if getattr(state, 'g_OpeningEnemy', -1) != attacker:
                state.g_OpeningStickyMode = 0

    elif attacker == own_power:
        # We (own_power) stabbed victim p: clear own AllyMatrix row (C lines 1243-1249)
        for j in range(num_powers):
            state.g_AllyMatrix[own_power, j] = 0


def _friendly(state: InnerGameState) -> None:
    """FRIENDLY (FUN_0042dc40). Per-turn power×power relationship and alliance
    state update. research.md §4364."""
    friendly(state)


def _hostility(state: InnerGameState) -> None:
    """HOSTILITY (FUN_~0x42F200).

    Highest-level per-turn diplomatic strategy function.  research.md §6649.

    Block 1 — enemy activation: random roll gates g_EnemyDesired (= g_StabbedFlag).
    Block 2 — CAL_BOARD + mutual-enemy table (press_on or FAL/WIN).
    Block 3 — FUN_004113d0 (ComputeOrderDipFlags) — always; ported.
    Block 4 — press-on initialisation (SPR/FAL): trust from proximity, random ally.
    Block 5 — enemy-desired trust management (SPR/FAL): betrayal counter, peace overtures.
    Block 6 — UpdateRelationHistory when press off or near-end (embedded in friendly()).
    """
    num_powers = 7
    own_power  = getattr(state, 'albert_power_idx', 0)
    phase      = state.g_season
    press_on   = (state.g_PressFlag == 1)

    # g_EnemyDesired ≡ g_StabbedFlag (same address DAT_00baed5f)
    enemy_desired = state.g_StabbedFlag

    # ── Block 1: enemy activation check ──────────────────────────────────────
    # C: outer gate = g_EnemyDesired==0; inner gate = press_off (DAT_00baed68==0).
    # Threshold = (g_DeceitLevel + 3) * 15  → ~60 % year-1, ~75 % year-2.
    # C fires multiple rand calls but only the final value is used.
    if enemy_desired == 0 and not press_on:
        threshold = (state.g_DeceitLevel + 3) * 15
        if random.randrange(100) < threshold:
            state.g_StabbedFlag = 1
            enemy_desired = 1
            logger.debug(
                "HOSTILITY: enemy now desired (DeceitLevel=%d, threshold=%d)",
                state.g_DeceitLevel, threshold,
            )

    # ── Block 2: CAL_BOARD + mutual-enemy table ───────────────────────────────
    # C gate: press_on OR FAL OR WIN.
    if press_on or phase in ('FAL', 'WIN'):
        cal_board(state, own_power)

        # For each power a, find best mutual enemy c that minimises
        # rank[own_power,c] + rank[a,c].
        # Mandatory inner filter: rank[a,c] < 4.
        # Outer filter: rank[own_power,c] < 4  OR  c is the committed enemy.
        # C: a == own_power is excluded by the condition (uVar7 != local_70);
        #    g_MutualEnemyTable[own_power] stays -1.
        rank_mtx  = state.g_InfluenceRankFlag   # DAT_006340c0
        ally_slot0 = state.g_BestAllySlot0

        for a in range(num_powers):
            state.g_MutualEnemyTable[a] = -1
            if a == own_power:
                continue
            best_c, best_score = -1, 10_000
            for c in range(num_powers):
                if c == a or c == own_power:
                    continue
                if int(state.sc_count[c]) <= 0:
                    continue
                r_ac = int(rank_mtx[a, c])
                if r_ac >= 4:
                    continue  # mandatory inner filter
                r_own_c = int(rank_mtx[own_power, c])
                is_committed = (
                    enemy_desired and c == state.g_CommittedEnemy
                    and int(state.g_EnemyFlag[c]) != 0
                )
                if r_own_c >= 4 and not is_committed:
                    continue
                score = r_own_c + r_ac
                if score < best_score:
                    best_score, best_c = score, c
            state.g_MutualEnemyTable[a] = best_c

        if 0 <= ally_slot0 < num_powers and state.g_MutualEnemyTable[ally_slot0] >= 0:
            logger.debug(
                "HOSTILITY: good mutual enemy with best ally %d → power %d",
                ally_slot0, state.g_MutualEnemyTable[ally_slot0],
            )

    # ── Block 3: ComputeOrderDipFlags (FUN_004113d0) — always ────────────────
    from ..communications import compute_order_dip_flags
    compute_order_dip_flags(state)

    # ── SPR||FAL outer gate (wraps Blocks 4 and 5) ───────────────────────────
    if phase in ('SPR', 'FAL'):

        # ── Block 4: press-on per-turn initialisation ─────────────────────────
        # C: runs every SPR/FAL with press_on (not gated by g_HistoryCounter==0).
        if press_on:
            # Zero per-power press counters.
            state.g_AllyPressCount.fill(0)
            state.g_AllyPressHi.fill(0)

            # Trust init from g_InfluenceMatrix_B for ALL power pairs (not just own).
            # ≤ 17.0 → nearby (trust 5); > 17.0 → distant (trust 3).
            # C outer loop: uVar7 = 0..num_powers-1; inner: uVar12 = 0..num_powers-1.
            inf_b = state.g_InfluenceMatrix_B
            prox  = state.g_PowerProximityRank
            for a in range(num_powers):
                for p in range(num_powers):
                    if p == a:
                        continue
                    state.g_AllyTrustScore_Hi[a, p] = 0
                    state.g_AllyTrustScore[a, p] = (
                        5 if float(inf_b[a, p]) <= 17.0 else 3
                    )

                # Random ally selection for this power; only own_power updates slots.
                # C: puVar17[-1]=prox[base], puVar17[0]=prox[base+1], puVar17[1]=prox[base+2]
                # Trust is set for the PRIMARY target; slots hold the OTHER neighbors.
                if prox is not None:
                    base = a * 5
                    roll = random.randrange(100)
                    if roll < 25:
                        # Primary trust target = prox[base]; slots = [base+1, base+2]
                        ally_idx = int(prox[base])
                        state.g_AllyTrustScore[a, ally_idx] = 1
                        state.g_AllyTrustScore_Hi[a, ally_idx] = 0
                        if a == own_power:
                            state.g_BestAllySlot0 = int(prox[base + 1])
                            state.g_BestAllySlot1 = int(prox[base + 2])
                    elif roll < 50:
                        # Primary trust target = prox[base+1]; slots = [base, base+2]
                        ally_idx = int(prox[base + 1])
                        state.g_AllyTrustScore[a, ally_idx] = 1
                        state.g_AllyTrustScore_Hi[a, ally_idx] = 0
                        if a == own_power:
                            state.g_BestAllySlot0 = int(prox[base])
                            state.g_BestAllySlot1 = int(prox[base + 2])
                    elif roll < 75:
                        # Primary trust target = prox[base+2]; slots = [base, base+1]
                        ally_idx = int(prox[base + 2])
                        state.g_AllyTrustScore[a, ally_idx] = 1
                        state.g_AllyTrustScore_Hi[a, ally_idx] = 0
                        if a == own_power:
                            state.g_BestAllySlot0 = int(prox[base])
                            state.g_BestAllySlot1 = int(prox[base + 1])
                            state.g_TripleFrontMode2 = 1
                    else:
                        # Triple-front: no single primary; all three slots assigned.
                        state.g_TripleFrontFlag = 1
                        if a == own_power:
                            state.g_BestAllySlot0 = int(prox[base])
                            state.g_BestAllySlot1 = int(prox[base + 1])
                            state.g_BestAllySlot2 = int(prox[base + 2])
                            for attr in ('g_BestAllySlot0', 'g_BestAllySlot1', 'g_BestAllySlot2'):
                                if getattr(state, attr) == own_power:
                                    setattr(state, attr, -1)

            # g_HistoryCounter > 0 path: snapshot own-power trust row and send press.
            # C: saves g_AllyTrustScore[own_power, p] to DAT_004d5480/4, clears low trust,
            #    then calls SendAllyPressByPower(p) for each p.
            # Deferred: press dispatch requires send_fn; handled by caller after _hostility.

            # ── Near-end-game overrides (inside press_on + SPR/FAL block) ─────
            if state.g_NearEndGameFactor > 5.0:
                state.g_StabbedFlag = 1
                enemy_desired = 1
            if state.g_NearEndGameFactor > 3.0:
                cal_board(state, own_power)

        # ── Block 5: enemy-desired trust management ───────────────────────────
        # C: gated by g_StabbedFlag (g_EnemyDesired) inside SPR||FAL.
        if state.g_StabbedFlag == 1:
            inf_b = state.g_InfluenceMatrix_B

            # Betrayal-counter loop.
            # C: piVar18 iterates g_RelationScore[own_power, p] (row own, advancing by col).
            #    piVar8 iterates g_AllyTrustScore[own_power, p] (same row).
            for p in range(num_powers):
                if p == own_power or int(state.g_EnemyFlag[p]) != 0:
                    continue
                trust_op_lo = int(state.g_AllyTrustScore[own_power, p])
                trust_op_hi = int(state.g_AllyTrustScore_Hi[own_power, p])
                # C: both g_EnemyFlag[p] words must be 0 (already filtered above).
                if trust_op_lo == 0 and trust_op_hi == 0:
                    state.g_BetrayalCounter[p] += 1

                proximity = float(inf_b[own_power, p])
                relation  = int(state.g_RelationScore[own_power, p])
                if proximity > 14 or relation < 0:
                    state.g_BetrayalCounter[p] = 0

                if int(state.g_BetrayalCounter[p]) >= 10 and phase == 'SPR':
                    state.g_BetrayalCounter[p] = 0

            # SendAllyPressByPower for all powers when history > 0 (inside enemy block).
            # C: lines 618-622; deferred to caller (send_fn not available here).

            # "Changed our minds" loop.
            # C: piVar8 iterates g_AllyTrustScore[p, own_power] (column own_power);
            #    advances by full row (stride 21*2=42 ints) per iteration.
            for p in range(num_powers):
                if p == own_power:
                    continue
                trust_po_lo = int(state.g_AllyTrustScore[p, own_power])
                trust_po_hi = int(state.g_AllyTrustScore_Hi[p, own_power])
                # C: trust[p,own] > 0 = trust_hi >= 0 AND (trust_hi > 0 OR trust_lo != 0)
                if not (trust_po_hi >= 0 and (trust_po_hi > 0 or trust_po_lo != 0)):
                    continue
                trust_op_lo = int(state.g_AllyTrustScore[own_power, p])
                trust_op_hi = int(state.g_AllyTrustScore_Hi[own_power, p])
                proximity   = float(inf_b[own_power, p])
                relation    = int(state.g_RelationScore[own_power, p])
                if (trust_op_lo == 0 and trust_op_hi == 0
                        and int(state.g_EnemyFlag[p]) == 0
                        and proximity > 0.0 and relation >= 0):
                    state.g_AllyTrustScore[own_power, p]    = trust_po_lo
                    state.g_AllyTrustScore_Hi[own_power, p] = trust_po_hi
                    logger.debug("HOSTILITY: changed our minds about attacking power %d", p)

            # Peace overture loop.
            # C: g_HistoryCounter==0 path goes directly to LAB_0042f95f; history>0 path
            #    checks PCE in press history first (stubbed: always proceed).
            for p in range(num_powers):
                if p == own_power or int(state.g_EnemyFlag[p]) != 0:
                    continue
                sc = int(state.sc_count[p])
                if sc <= 0:
                    continue
                # sc > 2 OR phase == SPR
                if sc <= 2 and phase != 'SPR':
                    continue
                # phase == SPR OR g_NeutralFlag[own, p] == 0
                # C: DAT_0062b7b0 = g_NeutralFlag (not g_CeaseFire)
                if phase != 'SPR' and int(state.g_NeutralFlag[own_power, p]) != 0:
                    continue
                trust_op_lo = int(state.g_AllyTrustScore[own_power, p])
                trust_op_hi = int(state.g_AllyTrustScore_Hi[own_power, p])
                if trust_op_lo != 0 or trust_op_hi != 0:
                    continue
                # Both relation scores must be non-negative.
                # C: (&DAT_00634e90)[iVar9] = g_RelationScore[own,p]; *piStack_68 = g_RelationScore[p,own]
                if int(state.g_RelationScore[own_power, p]) < 0:
                    continue
                if int(state.g_RelationScore[p, own_power]) < 0:
                    continue
                # Random 15% gate OR betrayal counter < 2 (lo-word).
                betrayal_lo = int(state.g_BetrayalCounter[p]) & 0xFFFFFFFF
                rand_pass   = (random.randrange(100) < 15) or (betrayal_lo < 2)
                if not rand_pass:
                    continue
                # History or deceit gate: history==0 OR DeceitLevel > 1.
                if not (state.g_HistoryCounter == 0 or state.g_DeceitLevel > 1):
                    continue

                # Form peace: set bilateral trust; reset relation if not already at 50.
                prev_relation = int(state.g_RelationScore[own_power, p])
                state.g_AllyTrustScore[own_power, p]    = 1
                state.g_AllyTrustScore_Hi[own_power, p] = 0
                state.g_AllyTrustScore[p, own_power]    = 1
                state.g_AllyTrustScore_Hi[p, own_power] = 0
                if prev_relation != 50:
                    state.g_RelationScore[own_power, p] = 0
                    state.g_RelationScore[p, own_power] = 0
                logger.debug("HOSTILITY: attempting peace with power %d", p)

    # Block 6 — UpdateRelationHistory (HOSTILITY.c:510-512).
    # C: `if ((DAT_00baed68 == '\0') || (3.0 < _g_NearEndGameFactor))`
    # i.e., press off OR near-end-game phase. Added 2026-04-14 — was previously
    # missing; docstring mistakenly claimed it was "embedded in friendly()".
    near_end = float(getattr(state, 'g_NearEndGameFactor', 0.0))
    if (not press_on) or near_end > 3.0:
        from albert.communications import _update_relation_history
        _update_relation_history(state)


def _post_friendly_update(state: InnerGameState) -> None:
    """ComputeInfluenceMatrix (FUN_0040d8c0). Trust-adjusts g_InfluenceMatrix,
    adds noise, row-normalises to 100, builds g_AllyPrefRanking.
    research.md §4241."""
    own_power = getattr(state, 'albert_power_idx', 0)
    compute_influence_matrix(state, own_power)
