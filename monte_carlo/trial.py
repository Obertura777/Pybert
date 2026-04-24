"""Monte-Carlo trial loop (ProcessTurn) and its auxiliaries.

Split from monte_carlo.py during the 2026-04 refactor.  This is the core of
the MC engine:

- ``trial_evaluate_orders``    — deep-copy a candidate order set for an
                                 isolated trial.
- ``process_turn``             — 1 200+ line port of FUN_0044c9d0; the full
                                 MC trial loop (Phases 1a–5) that dispatches
                                 candidate orders into ``g_OrderTable``,
                                 scores each realisation, and rolls up the
                                 per-province best-score tables.
- ``_update_ally_order_score`` — adjust ally-order score after Phase 3.
- ``_refresh_order_table``     — rebuild ``g_OrderTable`` between trials.
- ``update_score_state``       — composite helper used by Phase 5.
- ``check_time_limit``         — read ``state.mtl_expired`` atomically.

Module-level deps: ``copy``, ``random``, ``numpy``, ``..state.InnerGameState``,
three enumerators from ``..moves``, ``evaluate_order_proposal`` from
``.evaluation``, and field/order-type constants from ``._flags``.
"""

import copy
import random

import numpy as np

from ..state import InnerGameState
from ..moves import (
    assign_support_order,
    register_convoy_fleet,
    build_convoy_orders,
)

from ._flags import (
    _F_ORDER_TYPE, _F_SECONDARY, _F_DEST_PROV, _F_DEST_COAST,
    _F_CONVOY_LO, _F_CONVOY_HI,
    _F_INCOMING_MOVE, _F_SUP_CHAIN_CONFLICT,
    _F_SOURCE_PROV, _F_SUP_COUNT, _F_ORDER_ASGN,
    _ORDER_HLD, _ORDER_MTO, _ORDER_SUP_HLD, _ORDER_SUP_MTO,
    _ORDER_CVY, _ORDER_CTO,
)
from .evaluation import evaluate_order_proposal


def trial_evaluate_orders(state: InnerGameState, trial_candidate: dict) -> dict:
    """
    State duplicator for trial resolutions.  Deep-copies the candidate order
    dict so each MC trial is isolated.  The caller is responsible for loading
    trial_candidate into state.g_OrderTable before calling evaluate_order_score.
    """
    return copy.deepcopy(trial_candidate)


def process_turn(state: InnerGameState, power_index: int, num_trials: int = 4000) -> None:
    """
    Port of FUN_00453220 = ProcessTurn(Albert *this, int **power_index, int num_trials).

    Per-power Monte Carlo order-assignment engine.  Called by ScoreOrderCandidates
    once per active power.  Runs ``num_trials`` independent MC trials for
    ``power_index`` and accumulates results into state.g_CandidateRecordList.

    Signature matches decompiled: __thiscall ProcessTurn(param_1_00, power_index, num_trials)
      param_1_00  → state (Albert *this)
      power_index → the power being simulated this call
      num_trials  → number of Monte Carlo iterations

    Phase 0 — Setup (once per call)
    --------------------------------
    0a. Build reachable-province set (g_ReachableProvinces) by scanning the ally-
        shared order-history list for power_index (or own-power variant when
        power_index == own_power).
    0b. Per-power order-history copy: copy g_OrderHistory[p] → local per-power sets.
    0c. Ally flag scan: local_76f = 1 if g_XdoPressSent[power_index, p] for any p.
    0d. Random start offset for the cyclical power-expand pass.

    Phase 1 — Monte Carlo trial loop (num_trials iterations)
    ----------------------------------------------------------
    Each trial:
    1a. Per-trial state reset:
        - clear g_SupportTrustAdj / g_RingConvoyScore / g_EarlyGameAdjScore / g_OtherScore
        - clear g_ConvoyDstList, g_TrialList2, g_TrialMap
        - reset g_OrderTable all-provinces (order type 0, coast -1, other fields 0)
        - reset g_ConvoySourceProv[prov] = -1, g_ConvoyActiveFlag[prov] = 0,
          g_ProvinceScore[prov] = 0, g_ArmyAdjCount[prov] = 0
        - reset g_UnitPresence[power, prov] = -1 for all power,prov
    1b. Unit list scan:
        - g_UnitPresence[unit.power, unit.province] = 0
        - for own armies: g_ArmyAdjCount[adj]++ for each AMY-adjacent province
    1c. Dispatch existing orders (priority HLD→MTO→CTO→CVY→SUP):
        - If power_index == own_power (or trusted ally): dispatch g_AllianceOrders[power_index]
        - Dispatch g_GeneralOrders[power_index] (second pass)
    1d. Ring-convoy check (if g_RingConvoyEnabled):
        - Verify ring A→B, B→C, C→A is still intact; build MTO orders if valid.
    1e. Random exploit pass (15% chance; 35% if late-game + has_ally):
        - Cycle through allied powers looking for defection / secondary targets.
        - Insert matching proposal records from g_DealList into local candidate set.
    1f. Support assignment:
        - Find own unordered SC provinces → call assign_hold_supports.
    1g. Convoy chain assignment:
        - Iterate g_ConvoyDstList; score / rank fleet candidates via score_convoy_fleet.
    1h. Target-bonus scoring:
        - +150/+75 per MTO/CTO unit moving to a flagged target province.
        - +50 per SUP_MTO into an SC-gaining support.
    1i. Call evaluate_order_proposal(state, power_index) once per trial.

    Callees (unported stubs where noted):
      reset_per_trial_state   — FUN_00460be0; resets board-level snapshot
      dispatch_single_order   — dispatch.py; already ported
      assign_hold_supports    — FUN_0041d270; ported (inner func)
      score_convoy_fleet      — BST insert-with-score; ported (inner func)
      move_candidate          — BST erase/pop from Albert+0x4cfc; ported (inner func)
      build_order_mto         — writes MTO into g_OrderTable; ported (inner func)
      insert_order_candidate  — FUN_004153b0; std::_Tree::_Insert for InsertOrderCandidate tree; ported inline as _insert_order_candidate (bisect-sorted list)
      evaluate_order_proposal — monte_carlo.py; already ported
    """
    import logging
    logger = logging.getLogger(__name__)

    own_power: int = getattr(state, 'albert_power_idx', 0)
    num_provinces: int = int(getattr(state, 'num_provinces',
                                     state.g_OrderTable.shape[0]))
    num_powers: int = 7

    # ── helpers for unported stubs ────────────────────────────────────────────
    def _reset_per_trial_state() -> None:
        """Port of FUN_00460be0 = ResetPerTrialState.

        Three C operations:
        (1) For each node in active unit list (this+0x2450/54): clear node+0x20 =
            the order-assigned pointer (ppiVar8[4] in DispatchSingleOrder).  Python
            has no per-node flag; the equivalent is g_OrderTable being zeroed at the
            end of this trial-reset block (line ~914), so no explicit work here.
        (2) Same for retreat unit list (this+0x245c/60) — same reasoning.
        (3) Free all nodes of the build-candidate list at this+0x2478 (calling
            FUN_0040fb70 on each node[2] then _free(node)), reset list sentinel to
            empty, clear size field (this+0x247c = 0) and waive count
            (this+0x2480 = 0).  Python: clear g_build_order_list and zero
            g_waive_count.
        """
        if hasattr(state, 'g_build_order_list'):
            state.g_build_order_list.clear()
        state.g_waive_count = 0

    def _assign_hold_supports(candidates: dict) -> None:
        """FUN_0041d270 = AssignHoldSupports — decompile-verified.

        Clears g_ConvoyFleetCandidates (Albert+0x4cfc) then re-populates it
        from *candidates* (own unordered SC provinces) with random scores.

        Decompile trace:
          1. FUN_004019f0(root) + sentinel reset → clear BST → .clear()
          2. Iterate param_1 (candidate std::set) in tree order.
          3. Per node: province = *(node+0xC)  [MSVC release layout:
             node[0]=_Left, node[1]=_Parent, node[2]=_Right, node[3]=key]
          4. score = (_rand() // 0x17) % 0x7c17 + 500
             MSVC _rand() ∈ [0, RAND_MAX=32767=0x7fff]
             → score ∈ [500, 1924]
          5. ScoreConvoyFleet(this+0x4cfc, buf, &score) → bisect.insort
        """
        state.g_ConvoyFleetCandidates.clear()
        for prov in candidates:
            r = random.randint(0, 32767)  # MSVC _rand() ∈ [0, RAND_MAX=0x7fff]
            score = (r // 0x17) % 0x7c17 + 500
            _score_convoy_fleet(prov, score)

    def _score_convoy_fleet(prov: int, score: int) -> None:
        """ScoreConvoyFleet (FUN_00419790) — BST insert into g_ConvoyFleetCandidates.

        Mirrors MSVC std::map<int,int>::insert: lower-bound traversal (decompiled
        loop at FUN_00419790) followed by FUN_00413ba0 (actual RB-tree node alloc
        + link).  In Python the sorted list replaces the RB-tree; bisect.insort
        keeps it ordered by score ascending (same traversal direction as the C
        loop: key > node[3] → go left, i.e. larger keys are to the left, so the
        BST is effectively descending — but the Python list is ascending; Phase 2
        drains from the front, which is lowest score first).
        """
        import bisect
        bisect.insort(state.g_ConvoyFleetCandidates, (score, prov))

    def _move_candidate(prov: int) -> None:
        """MoveCandidate (FUN_00411cf0) — BST erase from g_ConvoyFleetCandidates.

        Removes the existing entry for *prov* (if any) before re-inserting with
        an updated score.  Mirrors std::map::erase(iterator).
        """
        state.g_ConvoyFleetCandidates = [
            e for e in state.g_ConvoyFleetCandidates if e[1] != prov
        ]

    def _build_order_mto(src: int, dst: int, coast: int) -> None:
        """Port of BuildOrder_MTO — write MTO into g_OrderTable.

        Decompile-verified (decompiled.txt).  Signature:
          __thiscall BuildOrder_MTO(this, power, src_province, dst_province, coast)

        Stubbed callees:
          ClearConvoyState()        — clears per-convoy temp state; trial reset covers it
          BuildOrder_CTO_Ring(...)  — builds CTO ring chain; decompile-verified (BuildOrder_CTO.c:67)
          RegisterConvoyFleet(...)  — registers fleet candidate; unknown decompile
        """
        # ClearConvoyState() — STUB (per-trial reset at Phase 1a covers observable effect)

        # Determine unit type at src (AMY vs FLT)
        unit_type = state.unit_info.get(src, {}).get('type', '')
        is_army = (unit_type == 'A')

        # Unit-type terrain gate: fleets cannot enter landlocked provinces,
        # armies cannot enter sea zones.  Silently reject — the trial will
        # fall back to the default HLD seeded in Phase 1b'.
        if unit_type in ('F', 'FLT') and dst in state.land_provinces:
            return
        if unit_type in ('A', 'AMY') and dst in state.water_provinces:
            return

        # BuildOrder_CTO_Ring(gamestate, src, dst, coast)
        # OrderedSet_FindOrInsert(this+0x2450, &src): insert src into active-unit set.
        # If src already present (iVar2 == iVar3 sentinel) → early return, no-op.
        # Otherwise write node+0x20=2 (MTO ring), node+0x24=dst, node+0x28=coast.
        # Python: g_OrderTable proxies the ordered-set node fields; guard on
        # _F_ORDER_TYPE != 0 mirrors the "already inserted" early-return.
        if int(state.g_OrderTable[src, _F_ORDER_TYPE]) == 0:
            state.g_OrderTable[src, _F_ORDER_TYPE] = float(_ORDER_MTO)  # 2 = MTO ring
            state.g_OrderTable[src, _F_DEST_PROV]  = float(dst)
            state.g_OrderTable[src, _F_DEST_COAST] = float(coast)

        # ConvoyList_Insert(&DAT_00bb65a0, &dst): append dst to convoy dst list; record dst→src
        if dst not in state.g_ConvoyDstList:
            state.g_ConvoyDstList.append(dst)
        if not hasattr(state, 'g_ConvoyDstToSrc'):
            state.g_ConvoyDstToSrc = {}
        state.g_ConvoyDstToSrc[dst] = src

        # g_OrderTable[src]: write MTO order type, destination, coast
        state.g_OrderTable[src, _F_ORDER_TYPE] = float(_ORDER_MTO)
        state.g_OrderTable[src, _F_DEST_PROV]  = float(dst)
        state.g_OrderTable[src, _F_DEST_COAST] = float(coast)

        # g_ProvinceBaseScore[dst] = 1: mark dst as having an incoming move
        state.g_OrderTable[dst, _F_INCOMING_MOVE] = 1.0

        # OrderedSet_FindOrInsert(this + power*0xc + 0x4000, &dst):
        # inherit dst's candidate score (FinalScoreSet) into convoy chain score fields
        score_lo = float(state.FinalScoreSet[power_index, dst])
        score_hi = 0.0
        state.g_ConvoyChainScore[dst]        = score_lo
        state.g_OrderScoreHi[dst]            = score_hi
        state.g_OrderTable[dst, _F_CONVOY_LO] = score_lo
        state.g_OrderTable[dst, _F_CONVOY_HI] = score_hi

        # DAT_00baede4[dst*0x1e] = g_MoveHistoryMatrix[dst + (src + power*0x40)*0x40]
        # Python layout: g_MoveHistoryMatrix[power, src, dst]
        state.g_OrderTable[dst, _F_SUP_COUNT] = float(
            state.g_MoveHistoryMatrix[power_index, src, dst]
        )

        # If AMY and convoy chain depth at src ≠ 5 (not complete): clear dst score fields
        # DAT_00baedf0[src*0x1e] = _F_ORDER_ASGN holds convoy chain depth in this context
        if is_army and int(state.g_OrderTable[src, _F_ORDER_ASGN]) != 5:
            state.g_OrderTable[dst, 24] = 0.0  # DAT_00baee00[dst*0x1e]
            state.g_OrderTable[dst, 25] = 0.0  # DAT_00baee04[dst*0x78]

        register_convoy_fleet(state, power_index, dst)

        # AssignSupportOrder(this, power, src, dst, coast, NULL)
        assign_support_order(state, power_index, src, dst, coast, flag=0)

    def _build_order_sup_hld(supporter: int, supported: int) -> None:
        """Port of BuildOrder_SUP_HLD (Source/BuildOrder/BuildOrder_SUP_HLD.c).

        Signature: BuildOrder_SUP_HLD(this, power, supporter_prov, supported_prov)

        Writes _ORDER_SUP_HLD (=3) into g_OrderTable[supporter] with the
        supported province in _F_DEST_PROV (DAT_00baeda8 — decompile line 29).
        Inherits supporter's candidate score into g_ConvoyChainScore /
        _F_CONVOY_LO/HI; clears convoy legs if the supporter is an army.
        Then registers the supporter as a convoy-fleet candidate and runs
        the ally-trust side-effect branch against the supported unit's power.

        Stubbed callees (observable state covered elsewhere):
          FUN_00460770(gs, supporter, supported) — convoy-chain bookkeeping;
                        per-trial reset at Phase 1a covers its effect.
          UnitList_FindOrInsert — active-unit set membership. The decompile's
                        "already inserted" early-return maps to the
                        _F_ORDER_TYPE != 0 guard below.
          The long adjacency-scan tail (decompile lines 57-187) is a score-
                        adjustment pass that bumps g_ConvoyActiveFlag /
                        g_ProvinceBaseScore depending on support-chain
                        topology; not modelled in Python yet — scoring uses
                        the simpler post-trial heat path.
        """
        # "Already inserted" early-return: supporter already has an order.
        if int(state.g_OrderTable[supporter, _F_ORDER_TYPE]) != 0:
            return

        # Core write (decompile lines 28-30):
        #   g_OrderTable[supporter, 0]  = 3           (SUP_HLD)
        #   g_OrderTable[supporter, 2]  = supported   (DAT_00baeda8)
        #   g_ProvinceBaseScore[supporter] = 1 → order_table[_F_INCOMING_MOVE]
        state.g_OrderTable[supporter, _F_ORDER_TYPE] = float(_ORDER_SUP_HLD)
        state.g_OrderTable[supporter, _F_DEST_PROV]  = float(supported)
        state.g_OrderTable[supporter, _F_DEST_COAST] = 0.0
        state.g_OrderTable[supporter, _F_INCOMING_MOVE] = 1.0

        # OrderedSet_FindOrInsert(this + power*0xc + 0x4000, supporter):
        # inherit supporter's FinalScoreSet entry into convoy-chain scores.
        score_lo = float(state.FinalScoreSet[power_index, supporter])
        state.g_ConvoyChainScore[supporter]       = score_lo
        state.g_OrderScoreHi[supporter]           = 0.0
        state.g_OrderTable[supporter, _F_CONVOY_LO] = score_lo
        state.g_OrderTable[supporter, _F_CONVOY_HI] = 0.0

        # If supporter is AMY: clear [24]/[25] (DAT_00baee00/04 —  SUP_HLD lines 34-37)
        is_army = (state.unit_info.get(supporter, {}).get('type') == 'A')
        if is_army:
            state.g_OrderTable[supporter, 24] = 0.0
            state.g_OrderTable[supporter, 25] = 0.0

        # RegisterConvoyFleet(this, power, supporter)
        register_convoy_fleet(state, power_index, supporter)

        # Chain-robustness adjacency tail (decompile L55–190).
        # Bumps supported's _F_INCOMING_MOVE when the chain is robust, or
        # supported's _F_SUP_CHAIN_CONFLICT when an enemy can cut it.
        _sup_chain_tail(supporter, supported, supported)

    def _sup_chain_tail(supporter: int, supported: int, accum_prov: int) -> None:
        """Shared adjacency-scan tail for BuildOrder_SUP_HLD / SUP_MTO.

        Ported from Source/BuildOrder/BuildOrder_SUP_HLD.c L55-190 and
        Source/BuildOrder/BuildOrder_SUP_MTO.c L61-220.  Both functions run
        the same structural scan against the unit list, with accumulator
        going to the supported (HLD) or target (MTO) province.

        Semantics (simplified from the C):
          1. Threat gate — if no enemy unit can reach the supporter
             (g_ProximityScore[power, supporter] is zero), skip the scan
             and unconditionally bump _F_INCOMING_MOVE.
          2. Threat-mismatch short-circuit — if the proximity score at the
             supporter doesn't equal the bare enemy_reach count, some
             non-reach enemy pressure is present; treat as chain-broken
             immediately (bump _F_SUP_CHAIN_CONFLICT).
          3. Otherwise scan every unit whose province is enemy-reachable
             or under secondary pressure; inspect its adjacency list for:
               - whether it's adjacent to the supporter (b_sup)
               - whether it's adjacent to the supported (b_tgt)
               - whether any *other* adjacent own SC-province already
                 carries a SUP_HLD/SUP_MTO onto the same supported with
                 _F_INCOMING_MOVE set (b_chain — the "sister supporter"
                 case that keeps the chain standing).
             A conflicting unit (b_sup && !b_tgt && !b_chain) flips the
             chain-ok flag off.
          4. Bump _F_INCOMING_MOVE (chain ok) or _F_SUP_CHAIN_CONFLICT
             (chain broken) on accum_prov.

        Simplifications from the literal decompile:
          - The "chain topology flag" branch (DAT_00baede0 == 1/2) is
            elided — nothing in the codebase currently writes that field
            to those sentinel values, so the branch is effectively dead.
        Fixed 2026-04-20 (M-MC-1): adjacency scan now uses
        can_reach_by_type for coast-aware filtering instead of raw
        adj_matrix, matching C's AdjacencyList_FilterByUnitType.
        """
        # Threat gate (L55-57, and L61-64 for SUP_MTO).
        threat = float(state.g_ProximityScore[power_index, supporter])
        if threat == 0.0:
            state.g_OrderTable[accum_prov, _F_INCOMING_MOVE] += 1.0
            return

        er = float(state.g_EnemyReachScore[power_index, supporter])
        if threat != er:
            # Chain immediately broken by non-reach pressure.
            state.g_OrderTable[accum_prov, _F_SUP_CHAIN_CONFLICT] += 1.0
            return

        # Adjacency scan — uses unit-type-aware adjacency (coast filtering).
        chain_ok = True
        for this_prov, this_unit in state.unit_info.items():
            # Skip if no enemy pressure at this unit's province (C has
            # two sequential gates on g_EnemyReachScore and a secondary
            # pressure array; we check either).
            er_flag = int(state.g_EnemyReachScore[power_index, this_prov]) == 1
            sec_flag = int(state.g_EnemyPressureSecondary[power_index, this_prov]) == 1
            if not (er_flag or sec_flag):
                continue

            # C uses AdjacencyList_FilterByUnitType to get only provinces
            # this unit can legally reach given its type (army/fleet).
            unit_type = this_unit.get('type', 'A')
            adjs = [p for p in state.adj_matrix.get(this_prov, [])
                    if state.can_reach_by_type(this_prov, p, unit_type)]
            b_sup = supporter in adjs
            b_tgt = supported in adjs

            b_chain = False
            for adj_prov in adjs:
                if adj_prov in (supporter, supported):
                    continue
                if state.g_SCOwnership[power_index, adj_prov] != 1:
                    continue
                otype = int(state.g_OrderTable[adj_prov, _F_ORDER_TYPE])
                if otype not in (_ORDER_SUP_HLD, _ORDER_SUP_MTO):
                    continue
                if int(state.g_OrderTable[adj_prov, _F_DEST_PROV]) != supported:
                    continue
                if int(state.g_OrderTable[adj_prov, _F_INCOMING_MOVE]) != 1:
                    continue
                b_chain = True
                break

            if b_sup and not b_tgt and not b_chain:
                chain_ok = False

        if chain_ok:
            state.g_OrderTable[accum_prov, _F_INCOMING_MOVE] += 1.0
        else:
            state.g_OrderTable[accum_prov, _F_SUP_CHAIN_CONFLICT] += 1.0

    def _build_order_sup_mto(supporter: int, mover: int, target: int) -> None:
        """Port of BuildOrder_SUP_MTO (Source/BuildOrder/BuildOrder_SUP_MTO.c).

        Signature: BuildOrder_SUP_MTO(this, power, supporter, mover, target)

        Writes _ORDER_SUP_MTO (=4) into g_OrderTable[supporter] — the mover's
        province in _F_SECONDARY (DAT_00baeda4, decompile L33), the target
        province in _F_DEST_PROV (DAT_00baeda8, decompile L34). Inherits the
        supporter's FinalScoreSet entry into convoy-chain score fields and
        clears convoy legs if the supporter is an army.

        Stubbed callees (same pattern as SUP_HLD):
          FUN_004607f0 — per-support bookkeeping; per-trial reset covers it.
          Ally-trust / enemy-adjacency tail (decompile L60-212) bumps
          g_ConvoyActiveFlag / g_ProvinceBaseScore / g_ProximityScore based
          on chain topology; not yet modelled — post-trial heat path covers
          observable scoring.
        """
        if int(state.g_OrderTable[supporter, _F_ORDER_TYPE]) != 0:
            return

        state.g_OrderTable[supporter, _F_ORDER_TYPE] = float(_ORDER_SUP_MTO)
        state.g_OrderTable[supporter, _F_SECONDARY] = float(mover)
        state.g_OrderTable[supporter, _F_DEST_PROV] = float(target)
        state.g_OrderTable[supporter, _F_INCOMING_MOVE] = 1.0

        score_lo = float(state.FinalScoreSet[power_index, supporter])
        state.g_ConvoyChainScore[supporter]         = score_lo
        state.g_OrderScoreHi[supporter]             = 0.0
        state.g_OrderTable[supporter, _F_CONVOY_LO] = score_lo
        state.g_OrderTable[supporter, _F_CONVOY_HI] = 0.0

        is_army = (state.unit_info.get(supporter, {}).get('type') == 'A')
        if is_army:
            state.g_OrderTable[supporter, 24] = 0.0
            state.g_OrderTable[supporter, 25] = 0.0

        register_convoy_fleet(state, power_index, supporter)

        # Chain-robustness adjacency tail (decompile L61–220).  For
        # SUP_MTO the accumulator lands on the *target* province (param_4
        # in the C), not the mover.  The `supported` arg mirrors the
        # "supported unit" used in the adjacency scan — here the mover,
        # because the SUP_MTO scan checks whether an enemy that can reach
        # the supporter can also reach the mover.
        _sup_chain_tail(supporter, mover, target)

    def _prov_from_unit_str(unit_str: str) -> int:
        """Parse 'A PAR' / 'F LON/NCS' → prov_id; -1 if unknown.

        DAIDE unit strings are "<type> <province>[/<coast>]".  For MC trial
        purposes we strip the coast — the adjacency matrix is coast-agnostic
        so integer prov_id suffices.
        """
        if not unit_str:
            return -1
        parts = unit_str.split()
        if len(parts) < 2:
            return -1
        prov_name = parts[1].split('/')[0]
        return int(state.prov_to_id.get(prov_name, -1))

    def _dispatch_to_order_table(order_seq: dict) -> None:
        """Project a press-agreed order_seq dict into g_OrderTable.

        Mirrors the side-effects of the C DispatchSingleOrder switch
        (ProcessTurn.c Phase 1c), which calls BuildOrder_{HLD,MTO,CTO,CVY,
        SUP_HLD,SUP_MTO} on the per-power order sets.  The Python pipeline
        previously used dispatch.dispatch_single_order which only formats
        DAIDE output strings — so press-agreed orders never made it into
        the MC trial state.  This helper closes that gap by calling the
        same nested _build_order_* helpers Phase 1d/1f.5/1f.7 already use.

        Silent no-op when:
          - unit province can't be parsed
          - the unit at that province doesn't belong to power_index
          - the supporter/mover/target referenced in a SUP doesn't resolve
          - order_type is HLD and the slot already carries an explicit
            non-HLD order (don't clobber move/support commitments)
        """
        otype = (order_seq.get('type') or '').upper()
        src = _prov_from_unit_str(order_seq.get('unit', ''))
        if src < 0:
            return
        # Sanity: the order must describe a unit this power actually owns.
        unit = state.unit_info.get(src)
        if unit is None or unit.get('power') != power_index:
            return

        if otype == 'HLD':
            # Only seed HLD if slot is still empty — never overwrite an
            # already-built MTO/SUP/CTO/CVY.  (Phase 1b' has usually
            # pre-seeded HLD anyway; this is idempotent in that case.)
            if int(state.g_OrderTable[src, _F_ORDER_TYPE]) == 0:
                state.g_OrderTable[src, _F_ORDER_TYPE] = float(_ORDER_HLD)
            return

        if otype == 'MTO':
            dst = int(state.prov_to_id.get(order_seq.get('target', ''), -1))
            if dst < 0:
                return
            # Upgrade default HLD to MTO — clear first so _build_order_mto's
            # "already inserted" guard (order_type != 0) doesn't short-circuit.
            if int(state.g_OrderTable[src, _F_ORDER_TYPE]) == _ORDER_HLD:
                state.g_OrderTable[src, _F_ORDER_TYPE] = 0.0
            _build_order_mto(src, dst, 0)
            return

        if otype == 'SUP':
            supported = _prov_from_unit_str(order_seq.get('target_unit', ''))
            if supported < 0:
                return
            target_dest = order_seq.get('target_dest')
            if target_dest:
                # SUP_MTO form: S <supported> MTO <target_dest>
                tgt = int(state.prov_to_id.get(target_dest, -1))
                if tgt < 0:
                    return
                if int(state.g_OrderTable[src, _F_ORDER_TYPE]) == _ORDER_HLD:
                    state.g_OrderTable[src, _F_ORDER_TYPE] = 0.0
                _build_order_sup_mto(src, supported, tgt)
            else:
                # SUP_HLD form: S <supported>
                if int(state.g_OrderTable[src, _F_ORDER_TYPE]) == _ORDER_HLD:
                    state.g_OrderTable[src, _F_ORDER_TYPE] = 0.0
                _build_order_sup_hld(src, supported)
            return

        if otype == 'CTO':
            dst = int(state.prov_to_id.get(order_seq.get('target_dest', ''), -1))
            if dst < 0:
                return
            # build_convoy_orders handles the full CTO + CVY chain, but it
            # requires state.g_ConvoyRoute[src][dst] to be populated for
            # this specific destination (route-planning output, per-dst
            # shape from Fix #7).  If unavailable, fall back to a direct
            # CTO write without the fleet CVY chain — mirrors the C
            # fallback when no valid convoy route is registered.
            from ..moves.convoy import _get_convoy_route
            _fc, _ = _get_convoy_route(state, src, dst)
            if _fc > 0:
                build_convoy_orders(state, power_index, src, dst)
            else:
                if int(state.g_OrderTable[src, _F_ORDER_TYPE]) == _ORDER_HLD:
                    state.g_OrderTable[src, _F_ORDER_TYPE] = 0.0
                state.g_OrderTable[src, _F_ORDER_TYPE] = float(_ORDER_CTO)
                state.g_OrderTable[src, _F_DEST_PROV]  = float(dst)
            return

        if otype == 'CVY':
            # Fleet convoying an army: S = fleet, target_unit = army being
            # convoyed, target_dest = army's destination.
            army_prov = _prov_from_unit_str(order_seq.get('target_unit', ''))
            dst = int(state.prov_to_id.get(order_seq.get('target_dest', ''), -1))
            if army_prov < 0 or dst < 0:
                return
            if int(state.g_OrderTable[src, _F_ORDER_TYPE]) == _ORDER_HLD:
                state.g_OrderTable[src, _F_ORDER_TYPE] = 0.0
            state.g_OrderTable[src, _F_ORDER_TYPE]  = float(_ORDER_CVY)
            state.g_OrderTable[src, _F_SOURCE_PROV] = float(army_prov)
            state.g_OrderTable[src, _F_DEST_PROV]   = float(dst)
            return

    def _insert_order_candidate(candidate_list: list, score: int, entry: dict) -> dict:
        """InsertOrderCandidate — BST sorted insert keyed on score (ascending).

        Mirrors the C++ `InsertOrderCandidate` / `FUN_004153b0` pair:
          - Descends the BST comparing node[3] < *param_2 (go left) until sentinel.
          - Allocates a new node (or returns existing) and links it.
          - Returns {container, node, is_new=1} via param_1; here returns the entry dict.

        `FUN_00410480` (`std_Tree_Buynode` for InsertOrderCandidate tree) is absorbed
        here.  In C++ it called `operator_new(0x3c)` (60-byte node) then
        `FUN_0040fa10(node, head, parent, head, data_ptr, color=0)`:

          Confirmed node layout (60 bytes / 0x3c):
            [0x00] _Left   = head   (param_1)
            [0x04] _Parent = parent (param_2)
            [0x08] _Right  = head   (param_3)
            [0x0c..0x27]  7-int payload — data_ptr[0..6] (slots 3–9)
                          data_ptr[0] = score (BST key)
            [0x28..0x37]  16-byte TokenSeq — FUN_00465f60(node+0x28, data_ptr+7)
                          (slots 10–13; data_ptr[7] = buf ptr, data_ptr[8] = count)
            [0x38]        color byte = param_6 = 0 (RED in MSVC RB-tree)
            [0x39]        0 (isNil = false)

        In Python this collapses to `dict(entry)` (payload copy) +
        `candidate_list.insert(pos, ...)` (linking).  No Albert logic — pure STL
        boilerplate; no separate Python function is needed.

        Python representation: candidate_list is a list of (score, entry_dict) tuples
        maintained in ascending score order via bisect.  Duplicate keys are allowed
        (same score → inserted to the right of existing equal-key entries).
        """
        import bisect
        keys = [s for s, _ in candidate_list]
        pos = bisect.bisect_right(keys, score)
        new_entry = dict(entry)
        new_entry['score'] = score
        candidate_list.insert(pos, (score, new_entry))
        return new_entry

    # ── lazy-init per-trial arrays not yet on state ───────────────────────────
    if not hasattr(state, 'g_UnitPresence'):
        state.g_UnitPresence = np.full((num_powers, num_provinces), -1, dtype=np.int32)
    if not hasattr(state, 'g_ConvoyActiveFlag'):
        state.g_ConvoyActiveFlag = np.zeros(num_provinces, dtype=np.int32)
    if not hasattr(state, 'g_ConvoyDstList'):
        state.g_ConvoyDstList = []
    if not hasattr(state, 'g_TrialList2'):
        state.g_TrialList2 = []
    if not hasattr(state, 'g_TrialMap'):
        state.g_TrialMap = {}
    if not hasattr(state, 'g_SupportTrustAdj'):
        state.g_SupportTrustAdj = 0
    if not hasattr(state, 'g_RingConvoyScore'):
        state.g_RingConvoyScore = 0
    if not hasattr(state, 'g_OtherScore'):
        state.g_OtherScore = 0
    if not hasattr(state, 'g_RingConvoyEnabled'):
        state.g_RingConvoyEnabled = 0
    if not hasattr(state, 'g_RingProv_A'):
        state.g_RingProv_A = -1
    if not hasattr(state, 'g_RingProv_B'):
        state.g_RingProv_B = -1
    if not hasattr(state, 'g_RingProv_C'):
        state.g_RingProv_C = -1
    if not hasattr(state, 'g_RingCoast_A'):
        state.g_RingCoast_A = 0
    if not hasattr(state, 'g_RingCoast_B'):
        state.g_RingCoast_B = 0
    if not hasattr(state, 'g_RingCoast_C'):
        state.g_RingCoast_C = 0
    if not hasattr(state, 'g_AllianceOrders'):
        state.g_AllianceOrders = {}          # {power: [order_seq, ...]}
    if not hasattr(state, 'g_GeneralOrders'):
        state.g_GeneralOrders = {}           # {power: [order_seq, ...]}
    # NB: g_AllianceOrdersPresent / g_GeneralOrdersPresent do NOT exist as
    # separate globals in the C binary.  ScoreOrderCandidates.c reads them as
    # `&DAT_00bb6d00 + p*0xc`, which is the `_Mysize` field (offset +8) of the
    # std::set<order_record> at slot p inside g_GeneralOrders (each slot is
    # 0xc bytes: comparator/_Myhead/_Mysize).  Same for the alliance variant.
    # We model the "is populated" check as `len(state.g_GeneralOrders.get(p,
    # ())) > 0` directly — no parallel array — to avoid the parallel-state
    # rot that bit us before (always-zero array → 1c never dispatched even
    # when orders existed).
    if not hasattr(state, 'g_OrderHistory'):
        state.g_OrderHistory = {}            # {power: [{province, ...}, ...]}
    if not hasattr(state, 'g_AllyOrderHistory'):
        state.g_AllyOrderHistory = {}        # {power: [{province, ...}, ...]}
    if not hasattr(state, 'g_ProposalHistoryMap'):
        # DAT_00baed98 — proposal history map; mirrors state.g_DealList
        state.g_ProposalHistoryMap = getattr(state, 'g_DealList', [])
    if not hasattr(state, 'g_StabMode'):
        state.g_StabMode = 0                 # DAT_00baed69

    # ── Phase 0 — Setup ───────────────────────────────────────────────────────

    # 0a. Build reachable-province set (g_ReachableProvinces) for power_index.
    #     Mirrors the StdMap_FindOrInsert(&DAT_00bb7124, ...) scan in decompile.
    g_ReachableProvinces = {}  # {prov: True}; DAT_00bb7124
    if power_index == own_power:
        # own power: scan ally-shared order history (DAT_00bb7028[power_index])
        for entry in state.g_AllyOrderHistory.get(power_index, []):
            prov = entry.get('province', -1)
            if prov >= 0:
                g_ReachableProvinces[prov] = True
    else:
        # ally: only scan when relation > 9 OR trust (hi > 0, or hi >= 0 and lo > 5)
        trust_lo = int(state.g_AllyTrustScore[own_power, power_index])
        trust_hi = int(state.g_AllyTrustScore_Hi[own_power, power_index])
        rel      = int(state.g_RelationHistory[own_power, power_index])
        if rel > 9 or (trust_hi > 0) or (trust_hi >= 0 and trust_lo > 5):
            for entry in state.g_AllyOrderHistory.get(power_index, []):
                prov = entry.get('province', -1)
                if prov >= 0:
                    g_ReachableProvinces[prov] = True

    # 0b. Per-power order-history snapshot (auStack_138[p] in decompile).
    #     Mirrors the DAT_00bb6f2c[p] copy loop.
    per_power_order_sets: list = [
        dict(state.g_OrderHistory.get(p, {})) for p in range(num_powers)
    ]

    # 0c. Ally flag scan: local_76f = 1 if any g_XdoPressSent[power_index, p] == 1.
    has_ally: bool = bool(
        np.any(state.g_XdoPressSent[power_index] == 1)
    )

    # 0d. Random start offset for the cyclical power-expand pass.
    rand_power_start: int = random.randrange(num_powers)
    rand_power_cursor: int = rand_power_start

    # ── Phase 1 — Monte Carlo trial loop ─────────────────────────────────────
    # Mirror of the do { ... } while (iStack_684 < num_trials) block.

    for _trial in range(num_trials):

        # 1a. Per-trial state reset ────────────────────────────────────────────
        state.g_SupportTrustAdj   = 0     # DAT_00633f14
        state.g_RingConvoyScore   = 0     # DAT_0062c57c
        state.g_EarlyGameBonus    = 0     # DAT_0062be94 (g_EarlyGameAdjScore)
        state.g_OtherScore        = 0     # DAT_0062b7ac

        _reset_per_trial_state()           # FUN_00460be0

        # Clear per-trial lists (DAT_00bb65a4 / DAT_00bbf648 / DAT_00bb6e04).
        state.g_ConvoyDstList.clear()
        state.g_TrialList2.clear()
        state.g_TrialMap.clear()

        # Reset per-province order-table fields.
        # Mirrors the loop over 0..numProvinces zeroing DAT_00baedac fields.
        state.g_OrderTable[:num_provinces, :] = 0.0
        state.g_OrderTable[:num_provinces, _F_DEST_COAST] = -1.0   # 0xffffffff
        # g_SupportScoreLo/Hi (fields 18/19) use -1.0 as "unset" sentinel
        # to match C's (lo & hi) == 0xffffffff AssignSupportOrder check.
        # Fixed 2026-04-14 — was 0.0, which conflated "zero score" with "unset".
        state.g_OrderTable[:num_provinces, 18] = -1.0
        state.g_OrderTable[:num_provinces, 19] = -1.0
        # H3 verified: g_ConvoySourceProv IS g_SupportAssignmentMap — C uses a
        # single array at one address for both support assignment and convoy
        # source tracking.  ProcessTurn.c:580 resets it to 0xffffffff each
        # trial, then support and convoy dispatch write sequentially (no conflict).
        state.g_ConvoySourceProv[:num_provinces]  = -1.0  # g_SupportAssignmentMap sentinel (0xffffffff)
        state.g_ConvoyActiveFlag[:num_provinces]  = 0
        state.g_ProvinceScoreTrial[:num_provinces] = 0
        state.g_ArmyAdjCount[:num_provinces]      = 0
        state.g_ConvoyFleetRegistered.clear()

        # Reset unit-presence matrix (g_UnitPresence[power*0x100+prov] = -1).
        state.g_UnitPresence[:, :num_provinces] = -1

        # 1b. Unit list scan ───────────────────────────────────────────────────
        # Mirrors: for each unit in this+8+0x2450 { g_UnitPresence[...] = 0;
        #           if own AMY: g_ArmyAdjCount[adj]++ }
        for prov, unit in state.unit_info.items():
            p_u  = unit['power']
            utyp = unit.get('type', '')
            state.g_UnitPresence[p_u, prov] = 0

            if p_u == power_index and utyp == 'A':
                for adj in state.get_unit_adjacencies(prov):
                    state.g_ArmyAdjCount[adj] += 1

        # 1b'. Default-HOLD seed — MOVED to after evaluate_order_proposal ────
        # H2 fix: In C, units without orders remain at order_type==0 and are
        # skipped by EvaluateOrderProposal (which checks order_type != 0).
        # Pre-seeding HLD before dispatch made all own units enter the HLD
        # branch of Step 3, inflating heat scores for units that C would skip.
        #
        # The HLD seed is now applied AFTER evaluate_order_proposal (see
        # "1b'-post" below) so that evaluation matches C's skip-zero behavior,
        # while still ensuring every unit has an order for submission.

        # 1c. Dispatch existing orders (priority HLD→MTO→CTO→CVY→SUP) ─────────
        # First pass: alliance orders (DAT_00bb65f8[power*0xc]) — own or trusted ally.
        # Now writes into g_OrderTable via _dispatch_to_order_table (was
        # previously calling dispatch.dispatch_single_order, which only
        # formats DAIDE strings and so left g_OrderTable untouched —
        # meaning press-agreed orders never entered MC trials).
        dispatch_first_pass = False
        if power_index == own_power:
            dispatch_first_pass = True
        else:
            trust_lo2 = int(state.g_AllyTrustScore[own_power, power_index])
            trust_hi2 = int(state.g_AllyTrustScore_Hi[own_power, power_index])
            if trust_hi2 > 0 or (trust_hi2 >= 0 and trust_lo2 > 2):
                dispatch_first_pass = True

        # Priority mirrors ProcessTurn's loop order: HLD → MTO → CTO → CVY → SUP.
        # SUP is last because it can depend on the mover's MTO landing first.
        _DISPATCH_PRIORITY = ['HLD', 'MTO', 'CTO', 'CVY', 'SUP']

        if dispatch_first_pass and len(state.g_AllianceOrders.get(power_index, ())) > 0:
            for wanted_type in _DISPATCH_PRIORITY:
                for order_seq in state.g_AllianceOrders.get(power_index, []):
                    if (order_seq.get('type') or '').upper() == wanted_type:
                        _dispatch_to_order_table(order_seq)

        # Second pass: general orders (DAT_00bb6cf8[power*0xc]) — unconditional.
        if len(state.g_GeneralOrders.get(power_index, ())) > 0:
            for wanted_type in _DISPATCH_PRIORITY:
                for order_seq in state.g_GeneralOrders.get(power_index, []):
                    if (order_seq.get('type') or '').upper() == wanted_type:
                        _dispatch_to_order_table(order_seq)

        # 1d. Ring-convoy check (DAT_00baed5c == 1) ───────────────────────────
        if state.g_RingConvoyEnabled == 1:
            ring_broken = False
            pA, pB, pC = state.g_RingProv_A, state.g_RingProv_B, state.g_RingProv_C
            if (int(state.g_OrderTable[pA, _F_ORDER_TYPE]) == _ORDER_MTO and
                    int(state.g_OrderTable[pA, _F_DEST_PROV]) != pB):
                ring_broken = True
            if (int(state.g_OrderTable[pB, _F_ORDER_TYPE]) == _ORDER_MTO and
                    int(state.g_OrderTable[pB, _F_DEST_PROV]) != pC):
                ring_broken = True
            if (int(state.g_OrderTable[pC, _F_ORDER_TYPE]) == _ORDER_MTO and
                    int(state.g_OrderTable[pC, _F_DEST_PROV]) != pA):
                ring_broken = True

            # Also check whether unit is absent from ring province (own-power gate).
            if power_index == own_power:
                # Mirroring: FUN_00402140 checks whether ring prov is in own order set.
                ring_in_set = (pA in per_power_order_sets[power_index] and
                               pB in per_power_order_sets[power_index] and
                               pC in per_power_order_sets[power_index])
                if not ring_in_set:
                    ring_broken = True
            # If ring intact: build the three MTO orders.
            if not ring_broken:
                _build_order_mto(pA, pB, state.g_RingCoast_A)
                _build_order_mto(pB, pC, state.g_RingCoast_B)
                _build_order_mto(pC, pA, state.g_RingCoast_C)

        # 1e. Random exploit pass (15% chance; 35% if late-game ally mode) ────
        # Mirrors: if (iVar20 < 0x0f) { ... } else if (...) goto LAB_004505d1
        r_exploit = random.randrange(100)
        do_exploit = r_exploit < 15
        if (not do_exploit and has_ally
                and state.g_NearEndGameFactor > 6.0
                and getattr(state, 'g_AlbertPower', own_power) != power_index
                and r_exploit < 35):
            do_exploit = True

        if do_exploit:
            # Advance cyclical power cursor to next allied power.
            rand_power_cursor = (rand_power_cursor + 1) % num_powers
            # Find an allied power.
            exploit_power = rand_power_cursor
            for _ in range(num_powers):
                if state.g_XdoPressSent[power_index, exploit_power]:
                    break
                exploit_power = (exploit_power + 1) % num_powers

            # Determine secondary target for stab scoring (65% × late-game).
            secondary_target = -1
            r2 = random.randrange(100)
            if (r2 < 65 and state.g_StabMode == 1
                    and state.g_NearEndGameFactor > 6.0):
                trust_lo3 = int(state.g_AllyTrustScore[own_power, exploit_power])
                trust_hi3 = int(state.g_AllyTrustScore_Hi[own_power, exploit_power])
                if trust_hi3 > 0 or (trust_hi3 >= 0 and trust_lo3 != 0):
                    secondary_target = (exploit_power + 1) % num_powers
                    for _ in range(num_powers):
                        st_lo = int(state.g_AllyTrustScore[own_power, secondary_target])
                        st_hi = int(state.g_AllyTrustScore_Hi[own_power, secondary_target])
                        if st_lo == 0 and st_hi == 0:
                            secondary_target = -1
                            break
                        if secondary_target == exploit_power:
                            secondary_target = -1
                            break
                        secondary_target = (secondary_target + 1) % num_powers

            # Build exploit candidate set (local_6e4).
            # InsertOrderCandidate inserts unconditionally — no count limit here.
            exploit_candidates: list = []   # [(score, entry_dict), ...] ascending

            # Scan proposal history (DAT_00baed98 / g_DealList) for matching entries.
            for rec in list(state.g_ProposalHistoryMap):
                if rec.get('power') != power_index:
                    continue
                rec_prov = rec.get('province', -1)
                # Check reachable / alt order set match (mirrors GameBoard_GetPowerRec).
                if rec_prov not in per_power_order_sets[power_index]:
                    continue
                score = rec.get('score', 0)
                entry = {
                    'unit_prov':    rec_prov,
                    'target_power': rec.get('target_power', -1),
                    'via_prov':     rec.get('src_prov', -1),
                    'dst_prov':     rec.get('dst_prov', -1),
                }
                # Primary insert: auStack_204 call site.
                if rec.get('target_power') == exploit_power:
                    _insert_order_candidate(exploit_candidates, score, entry)
                # Secondary insert: auStack_150 call site.
                # Condition: target_power == secondary_target AND via_prov == dst_prov.
                if secondary_target >= 0 and rec.get('target_power') == secondary_target:
                    if rec.get('src_prov') == rec.get('dst_prov'):
                        _insert_order_candidate(exploit_candidates, score, entry)

            # Count cap computed AFTER insertions (mirrors decompile: lines 81–102
            # overwrite ppiStack_7bc with the cap after the insertion loop).
            r3 = random.randrange(100)
            if secondary_target < 0:
                if r3 < 65:
                    count_cap = 1
                elif r3 < 84:
                    count_cap = 2
                else:
                    count_cap = 4 + int(r3 > 89)
            else:
                if r3 < 40:
                    count_cap = 1
                elif r3 < 60:
                    count_cap = 2
                elif r3 < 80:
                    count_cap = 3
                else:
                    count_cap = 4 + int(r3 > 89)

            # Consumption loop (decompile lines 103–246):
            # Iterate local_6e4 ascending by score; 60% rand gate + total count cap.
            # Trust/convoy conditions (via_prov vs dst_prov branch, relay province
            # lookup via g_ConvoyProv1/2/3 and g_AllyDesignation_A, reachability via
            # GameBoard_GetPowerRec) are not yet fully decompiled — stubbed below.
            consumed = 0
            for _score, cand in exploit_candidates:
                if random.randrange(100) >= 60:     # < 0x3c = 60% gate
                    continue
                if consumed >= count_cap:
                    break
                unit_prov = cand['unit_prov']
                if int(state.g_UnitPresence[power_index, unit_prov]) == -1:
                    continue

                # Phase-1e: convoy trust/route check
                # Ported from ProcessTurn.c lines 2463–2751.
                army_src = unit_prov
                dst      = cand['dst_prov']
                coast    = 0  # coast not carried in the candidate dict

                # Self-move: ordered to own province → hold and stop candidate scan.
                if dst == army_src:
                    state.g_OrderTable[army_src, _F_ORDER_TYPE] = float(_ORDER_HLD)
                    consumed += 1
                    break

                # Register dst in convoy destination tracking.
                if dst not in state.g_ConvoyDstList:
                    state.g_ConvoyDstList.append(dst)

                # Read relay province tables (interleaved lo/hi int32 pairs in C).
                # Python stores each as a single int64; sign encodes the hi guard word.
                #   relay3 ← g_AllyDesignation_C  (DAT_004d3610 = g_ConvoyProv3)
                #   relay1 ← g_AllyDesignation_B  (proxy for g_ConvoyProv1, same stride)
                #   ally_a ← g_AllyDesignation_A
                def _relay(arr, prov):
                    v = int(arr[prov])
                    return v, (-1 if v < 0 else 0)

                relay3_lo, relay3_hi = _relay(state.g_AllyDesignation_C, dst)
                relay1_lo, relay1_hi = _relay(state.g_AllyDesignation_B, dst)
                ally_a_lo, ally_a_hi = _relay(state.g_AllyDesignation_A, dst)

                # Three-probe trust accumulation (last-wins; ally_a only if still zero).
                trust_lo = trust_hi = 0
                probes = [
                    (relay3_lo, relay3_hi, False),
                    (relay1_lo, relay1_hi, False),
                    (ally_a_lo, ally_a_hi, True),
                ]
                for probe_lo, guard_hi, is_ally_a in probes:
                    if guard_hi < 0:
                        continue
                    if is_ally_a and (trust_lo != 0 or trust_hi != 0):
                        continue
                    if 0 <= probe_lo < num_powers:
                        # g_AllyHistoryCount threshold: `> 9` = trusted ally.
                        # Fixed 2026-04-14 — DAT_00634e90 is g_RelationScore
                        # (formerly labeled g_AllyHistoryCount); state.py has
                        # both names but only g_RelationScore is populated.
                        history = int(state.g_RelationScore[power_index, probe_lo])
                        if history > 9 or power_index == own_power:
                            trust_lo = float(state.g_AllyTrustScore[power_index, probe_lo])
                            trust_hi = int(state.g_AllyTrustScore_Hi[power_index, probe_lo])

                # Route check: unreachable dst → force trust to (3, 0) (always passes gate).
                if dst not in g_ReachableProvinces:
                    trust_lo, trust_hi = 3, 0

                # Trust gate.
                # not_early_game: DAT_00baed68 (g_PressFlag) != 1  OR  g_NearEndGameFactor >= 2.0
                not_early_game = (state.g_PressFlag != 1) or (state.g_NearEndGameFactor >= 2.0)
                accepted = False
                if not_early_game or relay1_hi < 0:
                    # Main path: accept when trust meets threshold.
                    if not (trust_hi < 1 and (trust_hi < 0 or trust_lo == 0)):
                        accepted = True
                else:
                    # Early-game mutual-trust path.
                    if 0 <= relay1_lo < num_powers:
                        fwd_hi = int(state.g_AllyTrustScore_Hi[power_index, relay1_lo])
                        fwd_lo = float(state.g_AllyTrustScore[power_index, relay1_lo])
                        if fwd_hi >= 0 and (fwd_hi > 0 or fwd_lo > 1):
                            rev_hi = int(state.g_AllyTrustScore_Hi[relay1_lo, power_index])
                            rev_lo = float(state.g_AllyTrustScore[relay1_lo, power_index])
                            if rev_hi >= 0 and (rev_hi > 0 or rev_lo > 1):
                                accepted = True  # mutual high trust
                    if not accepted:
                        # Fallback: active convoy chain at dst, or pool-B scoring.
                        if int(state.g_ConvoyActiveFlag[dst]) > 0:
                            accepted = True
                        elif int(state.g_SCOwnership[power_index, dst]) == 1:
                            # Pool-B scoring sub-path (item #6; partially decoded).
                            _score_convoy_fleet(dst, 0x7ffb)
                            # Not accepted; continue to next candidate.

                if not accepted:
                    continue  # ClearConvoyState + RemoveOrderCandidate

                # Accept: dispatch on whether dst is a coastal province.
                # province_has_coast mirrors Albert.province_property[dst*0x14+0x214] > 0.
                province_has_coast = any(
                    adj in state.water_provinces
                    for adj in state.adj_matrix.get(dst, [])
                )
                if not province_has_coast:
                    _build_order_mto(army_src, dst, coast)
                else:
                    # build_convoy_orders requires g_ConvoyRoute[src][dst]
                    # pre-populated with the fleet chain for this dst
                    # (per-dst shape from Fix #7).  If unavailable, fall
                    # back to a direct MTO write — matches the C fallback
                    # when route planning has not registered a valid
                    # fleet chain for the (src, dst) pair.
                    from ..moves.convoy import _get_convoy_route
                    _fc, _ = _get_convoy_route(state, army_src, dst)
                    if _fc > 0:
                        build_convoy_orders(state, power_index, army_src, dst)
                    else:
                        if int(state.g_OrderTable[army_src, _F_ORDER_TYPE]) == _ORDER_HLD:
                            state.g_OrderTable[army_src, _F_ORDER_TYPE] = 0.0
                        _build_order_mto(army_src, dst, coast)
                consumed += 1

        # 1f. Support assignment ───────────────────────────────────────────────
        # Find own unordered SC provinces; call AssignHoldSupports.
        # Mirrors: for each prov where g_SCOwnership[power_index,prov]==1 AND
        #          g_OrderTable[prov,0]==0 → add to support_candidates.
        support_candidates: dict = {}
        for prov in range(num_provinces):
            if (state.g_SCOwnership[power_index, prov] == 1 and
                    int(state.g_OrderTable[prov, _F_ORDER_TYPE]) == 0):
                support_candidates[prov] = True
        _assign_hold_supports(support_candidates)

        # 1f.5  Emit SUP HLD orders for confirmed supports ─────────────────────
        # _assign_hold_supports only fills the g_ConvoyFleetCandidates BST with
        # random scores — it doesn't write any order_type.  The C binary's
        # ProcessTurn pipeline (decompile line 2642) calls BuildOrder_SUP_HLD
        # out of the convoy-chain second pass after assign_support_order has
        # set g_SupportConfirmed + g_SupportTarget on the supported province.
        #
        # Here we walk own-power unordered units, probe adjacent support-
        # candidate provinces via assign_support_order, and emit SUP HLD when
        # the commit fires (dst[20]==1, g_ConvoySourceProv[dst]==src).  Each
        # supporter gets at most one SUP HLD per trial — matches C's
        # single-commit semantics (RegisterConvoyFleet → g_LastMTOInsert
        # conflict branch).
        if power_index == own_power:
            for src_prov, unit in state.unit_info.items():
                if unit['power'] != power_index:
                    continue
                # Allow HLD default (from Phase 1b') to be upgraded to SUP_HLD.
                # Skip only if supporter already has an explicit move/support/cvy
                # order — the C "already inserted" sentinel guards the SUP
                # order itself, not a pre-existing default HLD.
                cur = int(state.g_OrderTable[src_prov, _F_ORDER_TYPE])
                if cur not in (0, _ORDER_HLD):
                    continue
                for dst_prov in state.adj_matrix.get(src_prov, []):
                    if dst_prov not in support_candidates:
                        continue
                    if int(state.g_OrderTable[dst_prov, _F_ORDER_ASGN]) == 1:
                        # already confirmed by a different supporter this trial
                        continue
                    assign_support_order(state, power_index, src_prov, dst_prov, 0)
                    confirmed = int(state.g_OrderTable[dst_prov, _F_ORDER_ASGN])
                    target    = int(state.g_ConvoySourceProv[dst_prov])
                    # ConvoySourceProv is stored as float; -1 sentinel comes back as ~4.29e9.
                    if confirmed == 1 and target == src_prov:
                        # Clear the default HLD so _build_order_sup_hld's own
                        # "already inserted" guard (order_type != 0) doesn't fire.
                        state.g_OrderTable[src_prov, _F_ORDER_TYPE] = 0.0
                        _build_order_sup_hld(src_prov, dst_prov)
                        break  # one SUP HLD per supporter

        # 1f.7  Emit SUP MTO orders from g_SupportOpportunitiesSet ─────────────
        # build_support_opportunities populates g_SupportOpportunitiesSet during
        # Phase 0 setup with (mover, target, supporter) triples that satisfy
        # the triangle-geometry gate (defensive only — requires own-SC target).
        if power_index == own_power:
            sup_opps = getattr(state, 'g_SupportOpportunitiesSet', None) or []
            consumed_supporters: set = set()
            for opp in sup_opps:
                if int(opp.get('power', -1)) != power_index:
                    continue
                supporter = int(opp['supporter_prov'])
                mover     = int(opp['mover_prov'])
                target    = int(opp['target_prov'])

                if supporter in consumed_supporters:
                    continue
                sup_unit = state.unit_info.get(supporter)
                if sup_unit is None or sup_unit['power'] != power_index:
                    continue
                cur = int(state.g_OrderTable[supporter, _F_ORDER_TYPE])
                if cur not in (0, _ORDER_HLD):
                    continue
                mover_ot   = int(state.g_OrderTable[mover, _F_ORDER_TYPE])
                mover_dst  = int(state.g_OrderTable[mover, _F_DEST_PROV])
                if mover_ot not in (_ORDER_MTO, _ORDER_CTO) or mover_dst != target:
                    continue
                if target not in state.adj_matrix.get(supporter, []):
                    continue

                state.g_OrderTable[supporter, _F_ORDER_TYPE] = 0.0
                _build_order_sup_mto(supporter, mover, target)
                consumed_supporters.add(supporter)

        # 1f.8  Direct adjacency SUP MTO — C second pass port ─────────────────
        # ProcessTurn.c lines 1411-1800+: after the MTO adjacency walk generates
        # a move for unit X from province A to target B, re-iterate the unit
        # candidate BST and find any own-power unit Y at province C (adjacent
        # to B) that can support X's move.  The C code forcefully OVERWRITES
        # existing MTO orders with support assignments (via BuildOrderSpec).
        #
        # The C second pass has a 30% random gate (line 1523) controlling
        # which adjacency walk entries generate scored MTOs vs plain MTOs.
        # The support assignment happens for each generated MTO regardless.
        #
        # Python implementation: post-hoc scan after Phase 1c dispatches all
        # g_GeneralOrders.  Collect own-power MTO/CTO orders, then find
        # adjacent own-power units to convert to SUP_MTO.  Unlike Phase 1f.7,
        # this allows overwriting existing MTO orders (matching C behavior).
        # A random gate (50%) prevents every trial from having identical
        # support patterns — the MC evaluation picks the best combination.
        if power_index == own_power:
            # Collect all own-power MTO/CTO targets: {target_prov: mover_prov}
            mto_targets: dict = {}
            for prov, unit in state.unit_info.items():
                if unit['power'] != power_index:
                    continue
                ot = int(state.g_OrderTable[prov, _F_ORDER_TYPE])
                if ot in (_ORDER_MTO, _ORDER_CTO):
                    dst = int(state.g_OrderTable[prov, _F_DEST_PROV])
                    if dst not in mto_targets:
                        mto_targets[dst] = prov

            # Find supporters: own-power units adjacent to an MTO target.
            # Allow overwriting existing MTO (C second pass does this).
            # Constraints matching C behavior:
            #   - At most ONE supporter per MTO target (C inner loop fires
            #     once per BST entry, then moves on).
            #   - Random gate (50%) when overwriting an existing MTO —
            #     ensures candidate diversity across trials.
            if not hasattr(consumed_supporters, '__contains__'):
                consumed_supporters = set()
            supported_targets: set = set()  # max 1 supporter per target
            for sup_prov, sup_unit in state.unit_info.items():
                if sup_unit['power'] != power_index:
                    continue
                if sup_prov in consumed_supporters:
                    continue
                cur = int(state.g_OrderTable[sup_prov, _F_ORDER_TYPE])
                # Allow overwrite of HLD, empty (0), or MTO.
                # Do NOT overwrite SUP_HLD, SUP_MTO, CVY, CTO — those are
                # higher-commitment orders from earlier phases.
                if cur not in (0, _ORDER_HLD, _ORDER_MTO):
                    continue
                # Random gate: 50% chance when overwriting an existing MTO.
                if cur == _ORDER_MTO and random.randrange(100) >= 50:
                    continue
                # Check each adjacent province for an incoming own MTO.
                for adj_prov in state.adj_matrix.get(sup_prov, []):
                    if adj_prov in mto_targets and adj_prov not in supported_targets:
                        mover_prov = mto_targets[adj_prov]
                        if mover_prov == sup_prov:
                            continue  # can't support own move
                        state.g_OrderTable[sup_prov, _F_ORDER_TYPE] = 0.0
                        _build_order_sup_mto(sup_prov, mover_prov, adj_prov)
                        consumed_supporters.add(sup_prov)
                        supported_targets.add(adj_prov)
                        break  # one SUP_MTO per supporter

        # 1g. Convoy chain assignment ─────────────────────────────────────────
        # Iterate g_ConvoyDstList (DAT_00bb65a4); for each prov with enemy presence /
        # SC ownership: find in Albert+0x4cfc candidate list → ScoreConvoyFleet.
        fleet_pool_a = 0x7ffb   # ppiStack_7c0 initial value (from decompile line 1239)
        inserted_count = 0
        for prov in list(state.g_ConvoyDstList):
            iVar20 = power_index * 0x100 + prov
            enemy_hi  = int(state.g_EnemyPresence[power_index, prov])
            sc_own    = int(state.g_SCOwnership[power_index, prov])
            if enemy_hi > 0 or (enemy_hi >= 0 and sc_own != 0):
                # Mirrors: find ppiStack_7bc in Albert+0x4cfc where node[4]==prov
                # then MoveCandidate + StdMap_FindOrInsert + ScoreConvoyFleet.
                inserted_count += 1
                fleet_pool_a -= 1
                _move_candidate(prov)
                _score_convoy_fleet(prov, fleet_pool_a)

        # Own-power only: second convoy pass (ProcessTurn.c lines 1294–1409).
        # Iterates g_ConvoyFleetCandidates (Albert+0x4cfc); for candidates with
        # score < 0x7e1f (Phase 1f SC-province entries) whose dst is in
        # g_MoveList[own_power] (= state.g_ConvoyDstToSrc, populated by
        # _build_order_mto), re-scores up to two candidates with pool-B scores
        # then restarts the outer loop from the beginning.
        #
        # pool-B initial score: ppiStack_7b4 = 0x7fff - (1 + inserted_count) * 4
        #   = 0x7ffb - 4 * inserted_count  (ppiStack_79c starts at 1 in C).
        # Two scoring ops per found candidate (fleet-prov sub-pass + dst sub-pass),
        # each decrementing fleet_pool_b by 1.
        #
        # C lookup key matching details:
        #   ppiStack_7bc (fleet/src prov) = g_MoveList node value [4] → army_src
        #     via state.g_ConvoyDstToSrc[dst]; score check mirrors Phase 1g check.
        #   ppiStack_7c0 (dst prov) = *(candidate + 0x10) = candidate dst province.
        #   LAB_004516fb = advance (skip candidate, no restart).
        #   LAB_0045162d = second sub-pass (dst re-score, always reached).
        #   LAB_004516f1  = restart outer loop (ppiStack_790 = first element).
        if power_index == own_power:
            fleet_pool_b = 0x7ffb - 4 * inserted_count
            found = True
            while found:
                found = False
                for cand_score, dst in list(state.g_ConvoyFleetCandidates):
                    if cand_score >= 0x7e1f:
                        # LAB_004516fb: score too high (Phase 1g/1h candidate) → advance
                        continue
                    # g_MoveList[own_power] lookup: is dst a target of own MTO?
                    army_src = state.g_ConvoyDstToSrc.get(dst)
                    if army_src is None:
                        # LAB_004516fb: no own-power MTO targets this province → advance
                        continue
                    # First sub-pass (lines 1347–1375): optional — score army_src candidate
                    # if army_src passes the enemy-presence / SC-ownership gate.
                    # Mirrors: if (-1 < g_EnemyPresence[power, fleet_prov]) and
                    #          (g_EnemyPresence > 0 or g_SCOwnership != 0).
                    src_enemy = int(state.g_EnemyPresence[power_index, army_src])
                    src_sc    = int(state.g_SCOwnership[power_index, army_src])
                    if src_enemy > 0 or (src_enemy >= 0 and src_sc != 0):
                        _move_candidate(army_src)
                        fleet_pool_b -= 1
                        _score_convoy_fleet(army_src, fleet_pool_b)
                    # LAB_0045162d: second sub-pass (lines 1378–1400) — always score dst.
                    _move_candidate(dst)
                    fleet_pool_b -= 1
                    _score_convoy_fleet(dst, fleet_pool_b)
                    # LAB_004516f1: restart outer loop from beginning.
                    found = True
                    break

        # 1g.5  Default-hold backfill ─────────────────────────────────────────
        # Units that pass through 1c–1g without acquiring an explicit order
        # default to HLD.  The C binary's resolver treats _F_ORDER_TYPE == 0
        # the same as HLD; we set it explicitly so evaluate_order_proposal
        # sees real candidates.  g_GeneralOrders is populated by
        # generate_self_proposals (no-press) or score_order_candidates_from_broadcast
        # (press), so 1c fires and produces MTO orders — but units that
        # nothing touches still need this seed.
        for prov, unit in state.unit_info.items():
            if unit['power'] != power_index:
                continue
            if int(state.g_OrderTable[prov, _F_ORDER_TYPE]) == 0:
                state.g_OrderTable[prov, _F_ORDER_TYPE] = float(_ORDER_HLD)

        # 1h. Target-bonus scoring ────────────────────────────────────────────
        # Pass 1: MTO/CTO toward target-flagged provinces (+150 or +75).
        # Pass 2: RTO / unit-presence check (lines 2909–2940 in decompile).
        # Pass 3: SUP_MTO toward SC-gaining flag (+50, lines 2958–3032).
        for prov, unit in state.unit_info.items():
            if unit['power'] != power_index:
                continue
            order_type = int(state.g_OrderTable[prov, _F_ORDER_TYPE])
            press_active = bool(state.g_PressFlag)

            if order_type in (_ORDER_MTO, _ORDER_CTO):
                dest = int(state.g_OrderTable[prov, _F_DEST_PROV])
                tflag = int(state.g_TargetFlag[power_index, dest])
                if tflag == 2:
                    state.g_EarlyGameBonus += 150 if press_active else 75

            elif order_type == _ORDER_SUP_MTO:
                via = int(state.g_OrderTable[prov, _F_SECONDARY])
                iVar20 = via + power_index * 0x100
                tflag_via = int(state.g_TargetFlag[power_index, via])
                sc_hi = int(state.g_SCOwnership[power_index, via])
                if (tflag_via == 2 and sc_hi == 0 and
                        state.g_HistoryCounter == 0):
                    state.g_EarlyGameBonus += 50

        # 1i. Evaluate order proposal for this power (once per trial). ─────────
        # Mirrors: EvaluateOrderProposal(param_1_00, power_index) at decompile line 3747.
        evaluate_order_proposal(state, power_index)

        # 1b'-post. Default-HOLD seed for unassigned own units ────────────────
        # H2 fix: In C, EvaluateOrderProposal skips units with order_type==0.
        # After evaluation, seed HLD for any own units that still have no
        # order so that the submission pipeline has a valid order for every
        # unit.  Dispatch passes (1c-1h) already wrote non-zero order types
        # for units with movement/support/convoy orders; only truly idle
        # units remain at 0 here.
        for prov, unit in state.unit_info.items():
            if unit['power'] == power_index:
                if int(state.g_OrderTable[prov, _F_ORDER_TYPE]) == 0:
                    state.g_OrderTable[prov, _F_ORDER_TYPE] = float(_ORDER_HLD)


# ── UpdateScoreState ──────────────────────────────────────────────────────────

def _update_ally_order_score(state: InnerGameState, power: int) -> None:
    """
    Port of UpdateAllyOrderScore (FUN_00442770).
    Pass 1 sub-function of UpdateScoreState.
    """
    if getattr(state, 'g_CandidateRecordList', None) is None:
        return

    candidates = [c for c in state.g_CandidateRecordList if c.get('power') == power]
    if not candidates:
        return

    if hasattr(state, 'g_SubOrderMap'):
        state.g_SubOrderMap.clear()

    # Re-evaluate ally-directed pressure accumulation natively
    own_power = getattr(state, 'albert_power_idx', 0)
    for c in candidates:
        score = c.get('score', 0)
        c['score_alt'] = score + getattr(state, 'g_CumScore', 0)
        
    # Native EvaluateAllianceScore analog to update the matrices
    from ..heuristics import compute_influence_matrix
    compute_influence_matrix(state)


def _refresh_order_table(state: InnerGameState, power: int) -> None:
    """
    Port of RefreshOrderTable (FUN_00424490).

    Populates g_CurrentBestOrder[power] with up to 30 (province, order_type)
    pairs selected from the candidate pool via weighted random sampling.

    The C code iterates a local BST of order entries and for each of the 30
    slots independently selects one entry using (1000 - pressure_cost) weights
    with supply-center threshold gates that reject low-quality candidates for
    weak powers.

    Fix 2026-04-20 (M-MC-3): previously wrote to g_OrderTable (wrong target)
    and missed the SC threshold gates entirely.
    """
    import random

    candidates = [c for c in state.g_CandidateRecordList if c.get('power') == power]
    if not candidates:
        return

    # Flatten individual order entries from all candidates into a pool.
    # Each entry carries the pressure_cost of its parent candidate.
    order_pool: list = []  # [(prov, order_type, pressure_cost), ...]
    for c in candidates:
        cost = min(1000, max(0, int(c.get('pressure_cost', 0))))
        for prov, order_type in c.get('orders', []):
            order_pool.append((prov, order_type, cost))

    if not order_pool:
        return

    # SC threshold gates (C: lines 157-186 of RefreshOrderTable.c).
    # On the FIRST slot (local_54 == 0), reject entries with cost < threshold
    # depending on game state.
    own_power = getattr(state, 'g_AlbertPower', getattr(state, 'albert_power_idx', 0))
    war_mode = getattr(state, 'g_WarModeFlag', 0)
    press_flag = getattr(state, 'g_PressFlag', 0)
    sc_cnt = int(state.sc_count[power]) if power < len(state.sc_count) else 0

    def _passes_sc_gate(cost: int, slot_idx: int) -> bool:
        """Return False if entry should be rejected on first-slot SC gates."""
        if slot_idx != 0:
            return True
        score_val = 1000 - cost
        # Gate 1: war mode AND not own power → reject if score < 50
        if war_mode == 1 and own_power != power:
            if score_val < 50:
                return False
        # Gate 2: SC count < 4 AND press off → reject if score < 50
        if sc_cnt < 4 and press_flag == 0:
            if score_val < 50:
                return False
        # Gate 3: SC count < 6 → reject if score < 20
        if sc_cnt < 6:
            if score_val < 20:
                return False
        return True

    # Fill up to 30 slots via per-slot weighted random selection.
    _MAX_SLOTS = 30
    result_orders: list = []

    for slot_idx in range(_MAX_SLOTS):
        if not order_pool:
            break

        # Weighted selection: weight = 1000 - cost for entries that pass gates.
        eligible = [(p, ot, c) for p, ot, c in order_pool if _passes_sc_gate(c, slot_idx)]
        if not eligible:
            # If no entries pass the gate, fall back to the full pool.
            eligible = order_pool

        # Compute accumulated weights.
        weights = [1000.0 - c for (_, _, c) in eligible]
        total_weight = sum(weights)
        if total_weight <= 0:
            # All entries have cost >= 1000; pick uniformly.
            sel = eligible[random.randrange(len(eligible))]
        else:
            # C uses rand()/0x17 % 1000 with possible multi-roll; simplify to
            # single threshold in [0, total_weight).
            threshold = random.random() * total_weight
            accum = 0.0
            sel = eligible[-1]  # fallback
            for entry in eligible:
                accum += 1000.0 - entry[2]
                if accum > threshold:
                    sel = entry
                    break

        result_orders.append((sel[0], sel[1]))

    # Write to g_CurrentBestOrder (DAT_00bbf690/94) — NOT g_OrderTable.
    state.g_CurrentBestOrder[power] = result_orders


def update_score_state(state: InnerGameState) -> None:
    """
    Port of UpdateScoreState (FUN_0044c8e0).

    Two-phase order-table refresh.  For each power that has an active alliance
    (g_UnitCount[power] > 0) whose per-power game-board record predates
    g_CurrentRound:

      Pass 1 → UpdateAllyOrderScore (FUN_00442770)
      Pass 2 → RefreshOrderTable    (FUN_00424490)

    Semantics: "stale" means the game board recorded a different round for
    this power than the current simulation round, so its order table needs
    refreshing before the next trial.

    Research.md §5323.
    """
    num_powers = len(state.g_UnitCount)

    # Pass 1 — update ally order scores for stale-round powered alliances
    for power in range(num_powers):
        if state.g_UnitCount[power] <= 0:
            continue
        power_round = state.g_PowerRoundRecord.get(power, 0)
        if power_round != state.g_CurrentRound:
            _update_ally_order_score(state, power)

    # Pass 2 — refresh order table entries for the same stale powers
    for power in range(num_powers):
        if state.g_UnitCount[power] <= 0:
            continue
        power_round = state.g_PowerRoundRecord.get(power, 0)
        if power_round != state.g_CurrentRound:
            _refresh_order_table(state, power)


# ── CheckTimeLimit ────────────────────────────────────────────────────────────

def check_time_limit(state: InnerGameState) -> bool:
    """
    Port of CheckTimeLimit (CheckTimeLimit).

    In the original binary: mutex-protected read of
    g_NetworkState->field_0x20 (the MTL timeout flag set by the timer thread
    when the Move Time Limit fires).  Returns True if time has expired.

    Python equivalent: reads state.mtl_expired directly (GIL guarantees
    atomicity for simple int reads; no additional lock needed).

    Research.md §5358.
    """
    return int(getattr(state, 'mtl_expired', 0)) != 0
