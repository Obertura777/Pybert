"""Order-generation mixin half of AlbertClient.

Split from bot/client.py during the 2026-04 refactor.

Holds the per-turn order-generation pipeline methods:

  * ``generate_and_submit_orders`` — the main 450-line routine that runs
    Monte-Carlo order search, scoring, filtering, and submission for
    the current phase.
  * ``_validate_orders``           — cross-checks submitted orders
    against ``game.get_all_possible_orders()``.
  * ``_submit_adjustment_orders``  — builds/removes phase submission.

Composed with ``_LifecycleMixin`` and ``_PressMixin`` to form
``AlbertClient``; cross-mixin method calls resolve through MRO at
call time.  Imports are minimised here (the mixin only uses
``self.X`` — the heavy imports are already pulled in by
``_lifecycle.py``), but a small set of names needed *at definition*
time (type hints, decorators, module-level references inside method
bodies) still live here.
"""

import asyncio
import copy
import logging
import random
import time

import numpy as np

from ...state import InnerGameState
from ...monte_carlo import (
    process_turn,
    update_score_state,
    check_time_limit,
    _F_ORDER_TYPE, _F_DEST_PROV, _F_DEST_COAST,
)
from ...communications import (
    parse_message,
    dispatch_scheduled_press,
    cancel_prior_press,
    _send_ally_press_by_power,
)
from ...heuristics import (
    score_provinces,
    score_order_candidates_all_powers,
    score_order_candidates_own_power,
    populate_build_candidates,
    populate_remove_candidates,
    compute_win_builds,
    compute_win_removes,
    _WIN_BUILD_WEIGHTS,
    _WIN_REMOVE_WEIGHTS,
    _SPR_FAL_WEIGHTS,
)
from ...dispatch import validate_and_dispatch_order

from .._shared import _POWER_NAMES
from ..orders import (
    _populate_retreat_orders,
    _format_retreat_commands,
    _build_order_seq_from_table,
)
from ..gof import _send_gof, _evaluate_order_proposals_and_send_gof
from ..analysis import (
    _phase_handler, _analyze_position, _move_analysis,
    _post_process_orders, _compute_press,
    _cleanup_turn, _prepare_draw_vote_set,
    _rank_candidates_for_power,
    _game_phase, _game_status,
)
from ..strategy import (
    _stabbed, _deviate_move, _friendly, _hostility, _post_friendly_update,
)

logger = logging.getLogger(__name__)


class _OrdersMixin:
    def generate_and_submit_orders(self) -> None:
        """
        Port of FUN_004592a0 = GenerateAndSubmitOrders.

        Called from on_game_update after board state is synchronized.
        Mirrors the full C++ execution flow documented in research.md
        §GenerateAndSubmitOrders — FUN_004592a0 ⭐.

        Execution flow (matching research.md §Execution flow):
          Step 1  Record turn-start timestamp.
          Step 2  Reset per-turn scalar flags.
          Step 3  Cancel stale orders if reconnecting.
          Step 4  Press-flag refresh.
          Step 5  Main AI block (skipped when game_over):
            5a  Reset press candidate tables.
            5b  PhaseHandler(0).
            5c  Per-power reset loop (trust counters, score matrices).
            5d  Phase checks: increment g_DeceitLevel (SPR), AnalyzePosition,
                MOVE_ANALYSIS (year-1 FAL, press-off, allied).
            5e  Clear g_baed6d sentinel.
            5f  GenerateOrders + MC selection (process_turn).
            5g  PostProcessOrders (SPR/FAL).
            5h  ComputePress (if press active).
            5i  Alliance block (STABBED / DEVIATE_MOVE / FRIENDLY / HOSTILITY /
                PhaseHandler 1–3).
            5j  BuildAndSendSUB (movement phases) + draw vote;
                or HOSTILITY + PhaseHandler(3) (retreat/adjustment).
          Step 6  CleanupTurn + GOF.
        """
        own_power_idx = (
            _POWER_NAMES.index(self.power_name)
            if self.power_name in _POWER_NAMES else 0
        )
        self.state.albert_power_idx = own_power_idx
        # Keep the C-faithful name (DAT_00624124) in sync with the Python
        # canonical albert_power_idx.  Consumers:
        #   * monte_carlo/trial.py:849 — "skip iteration-delta term for self"
        #     branch in ScoreOrderCandidates_AllPowers.
        #   * communications/inbound/gate.py fallback chain.
        # Previously read but never written → the branch silently defaulted
        # to albert_power_idx via getattr, which was correct by accident.
        self.state.g_AlbertPower = own_power_idx

        # Step 1 — record turn start timestamp (DAT_00ba2880 = __time64(0))
        self.state.g_turn_start_time = time.time()

        # Step 2 — reset per-turn scalar flags
        # Mirrors: DAT_0062cc64 / ba2858 / ba285c / baed46 / baed5e / baed47 = 0
        if not hasattr(self.state, 'g_pending_orders_A'):
            self.state.g_pending_orders_A = 0
        if not hasattr(self.state, 'g_pending_orders_B'):
            self.state.g_pending_orders_B = 0

        game_over: bool = getattr(self.state, 'g_game_over', False)

        # Step 3 — cancel stale pending orders if reconnecting
        # Condition: !game_over AND (pending_A != 0 OR pending_B != 0)
        if not game_over and (
            self.state.g_pending_orders_A != 0
            or self.state.g_pending_orders_B != 0
        ):
            logger.info("Stale pending orders found — cancelling (reconnect path)")
            self.state.g_pending_orders_A = 0
            self.state.g_pending_orders_B = 0

        # Step 4 — press flag refresh
        # Clear press flag, then re-arm from one-shot config flag (DAT_004c6bdc).
        # DAT_00baed68: 0 = press off, 1 = run ComputePress this turn.
        if self.state.g_PressFlag == 1:
            self.state.g_PressFlag = 0
        one_shot_press = getattr(self.state, 'g_one_shot_press', 0)
        if one_shot_press == 1:
            self.state.g_PressFlag = 1
            self.state.g_one_shot_press = 0

        if game_over:
            logger.info("Game-over flag set — skipping order generation")
            _cleanup_turn(self.state)
            _send_gof(self.state, self._send_dm)
            return

        # ── Step 5 — main AI block ──────────────────────────────────────────
        phase: str = self.state.g_season          # 'SPR'|'SUM'|'FAL'|'AUT'|'WIN'
        movement_phase: bool = phase in ('SPR', 'FAL')
        num_powers = 7

        # 5a — reset press candidate tables
        # DAT_00bbf690[power][30] and DAT_00bc0a40[power][30] — cleared to sentinel
        self.state.g_PressCandidateA = [[None] * 30 for _ in range(num_powers)]
        self.state.g_PressCandidateB = [[None] * 30 for _ in range(num_powers)]

        # 5b — PhaseHandler step 0
        _phase_handler(self.state, 0)

        # 5c — per-power reset loop
        # DAT_00ba2888[power] = signed trust/relationship counter:
        #   own/ally powers: converges +1 toward 0 each movement turn (started negative)
        #   non-ally powers: reset to 0
        if not hasattr(self.state, 'g_trust_counter'):
            self.state.g_trust_counter = np.zeros(num_powers, dtype=np.int32)

        for p in range(num_powers):
            ally_p = int(self.state.g_AllyMatrix[own_power_idx, p]) != 0
            is_self = (p == own_power_idx)
            for j in range(num_powers):
                if is_self or ally_p:
                    if self.state.g_trust_counter[j] < 0 and movement_phase:
                        self.state.g_trust_counter[j] += 1
                else:
                    self.state.g_trust_counter[j] = 0

        # 5d — phase-specific pre-processing

        # g_DeceitLevel (DAT_00baed64) = Spring-year counter; 0=pre-game, 1=year 1, …
        # Incremented each SPR. Also labelled "Deceit Level" in Albert's internal log.
        if phase == 'SPR':
            self.state.g_DeceitLevel += 1
            logger.debug(
                f"DeceitLevel = {self.state.g_DeceitLevel} "
                f"(Spring of year {self.state.g_DeceitLevel})"
            )

        if movement_phase:
            _analyze_position(self.state)

        # MOVE_ANALYSIS gate: year-1, press-off, Fall, allied own power
        ally_own: bool = int(self.state.g_AllyMatrix[own_power_idx, own_power_idx]) != 0
        if (
            self.state.g_DeceitLevel == 1
            and self.state.g_PressFlag == 0
            and phase == 'FAL'
            and ally_own
        ):
            _move_analysis(self.state)

        # 5e — DAT_00baed6d = 0  (deviation/retry sentinel cleared before GenerateOrders)
        self.state.g_baed6d = 0

        # 5f — GenerateOrders + ScoreOrderCandidates (FUN_004559c0)
        # ScoreOrderCandidates:
        #   Step 1: clear g_CandidateList2 (per-power secondary lists) → reset
        #            g_CandidateRecordList so each scoring pass starts fresh.
        #   Step 2: reset proposal records in g_CandidateRecordList for new round.
        #   Step 3: call ProcessTurn for each power where
        #             unit_count[p] > 0 AND general_orders_present[p] != 0.
        #            trial_count = (unit_count[p] * g_TrialScale + 10) // 10;
        #            if g_PressProposalsCap == 0 AND p != own_power: trial_count = 1.
        #   Steps 4–5: proposal matching / scoring (DAIDE token comparison) — absorbed
        #              into the MC candidate scoring: each ProcessTurn call populates
        #              g_CandidateRecordList entries with scored order sets.
        from ..monte_carlo import generate_orders
        generate_orders(self.state, own_power_idx)

        # ── ScoreProvinces + ScoreOrderCandidates_AllPowers ──────────────────
        # C binary (send_GOF.c lines 56–62): for SPR/FAL movement phases,
        # ScoreProvinces computes per-province strategic scores, then
        # ScoreOrderCandidates_AllPowers uses g_CandidateScores (populated by
        # generate_orders Phase 1f) to compute FinalScoreSet — the per-power
        # per-province value that the MC trial loop's _build_order_mto reads
        # when scoring MTO orders.  Without this call FinalScoreSet stays all
        # zeros and every MTO gets a zero convoy-chain score, making the MC
        # unable to distinguish good moves from bad ones.
        if movement_phase:
            try:
                score_provinces(self.state, 0, 0, own_power_idx)
            except Exception:
                logger.exception(
                    "score_provinces raised; continuing with default scores"
                )
            try:
                score_order_candidates_all_powers(
                    self.state, _SPR_FAL_WEIGHTS, own_power_idx)
            except Exception:
                logger.exception(
                    "score_order_candidates_all_powers raised; continuing"
                    " with empty FinalScoreSet"
                )

        # Step 1 — clear per-power g_CandidateList2 trees (FUN_00410cf0 per power)
        # C: for each power, FUN_00410cf0(root) post-order frees the RB-tree,
        # then resets the sentinel.  Python: clear each power's g_GeneralOrders
        # list via _destroy_candidate_tree, then reset the flat record list.
        if hasattr(self.state, 'g_GeneralOrders'):
            for _p in range(num_powers):
                _destroy_candidate_tree(self.state.g_GeneralOrders.get(_p))
            self.state.g_GeneralOrders = {}
        # Mirror the wipe for g_AllianceOrders — ScoreOrderCandidates' C
        # writer (Source/ScoreOrderCandidates.c lines 79–85) reconstructs all
        # four sibling 21×12B arrays per call, so a fresh translator pass needs
        # an empty alliance set too.
        if hasattr(self.state, 'g_AllianceOrders'):
            self.state.g_AllianceOrders = {}
        self.state.g_CandidateRecordList = []

        # Translate inbound press registry → per-power general / alliance order
        # sets so MC sub-pass 1c can dispatch received-XDO orders.  Without
        # this call the binary's press-driven MTO/SUP path is unreachable in
        # Python (g_GeneralOrders stays empty → 1c second pass is a no-op →
        # MC produces only default-HLD output).  See communications.py for the
        # ScoreOrderCandidates writer-loop port.
        # The C binary never clears DAT_00bb65ec (g_BroadcastList), so received
        # press accumulates for the lifetime of the game and the translator
        # rebuilds g_GeneralOrders / g_AllianceOrders from the accumulated set
        # on every call.  That, plus the per-phase wipe above, is what gives
        # press its multi-phase commitment semantics — no separate archive
        # needed.  See state.synchronize_from_game for the matching no-clear
        # rationale.
        from ..communications import score_order_candidates_from_broadcast
        try:
            score_order_candidates_from_broadcast(self.state)
        except Exception:
            logger.exception(
                "score_order_candidates_from_broadcast raised; continuing"
                " with empty g_GeneralOrders/g_AllianceOrders"
            )

        # Self-proposal fallback: when g_BroadcastList is empty (NO_PRESS
        # or standalone mode), generate MTO proposals from FinalScoreSet
        # and inject them into g_GeneralOrders so MC Phase 1c can dispatch
        # non-hold orders.  This replaces the press round-trip that normally
        # populates these tables via score_order_candidates_from_broadcast.
        # Only fires when g_GeneralOrders is still empty after the broadcast
        # pass — in a press game with active proposals, this is a no-op.
        if movement_phase and not self.state.g_GeneralOrders:
            from ..heuristics import generate_self_proposals
            try:
                n_self = generate_self_proposals(self.state, own_power_idx)
                if n_self:
                    logger.debug(
                        "Self-proposal fallback: generated %d proposals", n_self)
            except Exception:
                logger.exception(
                    "generate_self_proposals raised; continuing without "
                    "self-proposals"
                )

        # Step 3 — call ProcessTurn for every active power (DAT_0062e460 / g_UnitCount)
        # g_TrialScale = DAT_004c6bb8 = difficulty*2+60 (default difficulty=100 → 260)
        # g_PressProposalsCap = DAT_004c6bbc = (difficulty*3)//10 capped at 30
        trial_scale: int = getattr(self.state, 'g_TrialScale', 260)
        press_cap: int = getattr(self.state, 'g_PressProposalsCap', 30)
        unit_count = getattr(self.state, 'g_UnitCount', np.zeros(num_powers, dtype=np.int32))

        # ── 10-round ProcessTurn loop with support-opportunity re-pass ───────
        # C binary (send_GOF.c lines 114–169): runs ProcessTurn 10 rounds.
        # Each round: for every power with sc_count > 0, run ProcessTurn with
        # g_RingConvoyEnabled=0.  Then scan g_SupportOpportunitiesSet for
        # matching-power entries; for each hit, copy the ring provinces from
        # the opportunity into the state, set g_RingConvoyEnabled=1, and run
        # ProcessTurn AGAIN.  This second pass generates ring-convoy MTO
        # patterns (A→B→C→A) that are the primary mechanism for non-hold
        # orders even in NO_PRESS mode.
        #
        # In a full-press game the 10-round loop also accumulates proposal-
        # driven candidates that get refined by later BuildAndSendSUB passes.
        MC_ROUNDS = 10 if movement_phase else 1
        for _mc_round in range(MC_ROUNDS):
            for p in range(num_powers):
                if int(unit_count[p]) <= 0:
                    continue
                if press_cap == 0 and p != own_power_idx:
                    n_trials = 1
                else:
                    n_trials = (int(unit_count[p]) * trial_scale + 10) // 10

                # Primary pass: g_RingConvoyEnabled = 0
                self.state.g_RingConvoyEnabled = 0
                process_turn(self.state, p, num_trials=n_trials)

                # Support-opportunity re-pass: scan for matching entries and
                # run ProcessTurn again with ring convoy enabled.
                sup_opps = getattr(self.state, 'g_SupportOpportunitiesSet', None)
                if sup_opps:
                    for opp in sup_opps:
                        if int(opp.get('power', -1)) != p:
                            continue
                        # Copy ring provinces from the opportunity entry.
                        # C: memcpy(DAT_00bbf668, entry+0x10, 28); DAT_00baed5c=1
                        self.state.g_RingProv_A = int(opp.get('mover_prov', -1))
                        self.state.g_RingProv_B = int(opp.get('target_prov', -1))
                        self.state.g_RingProv_C = int(opp.get('supporter_prov', -1))
                        self.state.g_RingConvoyEnabled = 1
                        # Trial count for re-pass: sc_count[p] * 10 / 10 = sc_count[p]
                        re_trials = max(int(self.state.sc_count[p]), 1)
                        if press_cap == 0 and p != own_power_idx:
                            re_trials = 1
                        process_turn(self.state, p, num_trials=re_trials)
        # Candidate-vs-press corroboration penalty
        # (Source/ScoreOrderCandidates.c lines 342–630).  Marks candidates
        # whose orders disagree with received-press XDOs with a -2.5e36
        # score so MC's selector skips them.
        #
        # IMPORTANT: only fire when g_BroadcastList has actual received
        # press — NOT when g_GeneralOrders was populated by
        # generate_self_proposals.  Self-proposals are synthetic guidance
        # to give MC some MTO candidates; penalising everything else would
        # collapse the candidate set and re-produce all-holds.
        has_real_press = bool(getattr(self.state, 'g_BroadcastList', None))
        if has_real_press:
            try:
                from ..heuristics import apply_press_corroboration_penalty
                n_penalised = apply_press_corroboration_penalty(self.state)
                if n_penalised:
                    logger.debug(
                        "Press corroboration: penalised %d candidate(s) "
                        "for disagreeing with received XDOs",
                        n_penalised,
                    )
            except Exception:
                logger.exception(
                    "apply_press_corroboration_penalty raised; continuing"
                    " without press-corroboration penalty"
                )

        best_orders = self.state.g_CandidateRecordList  # populated by process_turn

        # 5g — PostProcessOrders (SPR/FAL only; runs after GenerateOrders, before SUB)
        if movement_phase:
            _post_process_orders(self.state)

        # 5h — ComputePress if press mode is active this turn
        if self.state.g_PressFlag == 1:
            _compute_press(self.state)

        # 5h.1 — Emit accumulated XDO support proposals into g_BroadcastList.
        # build_support_proposals (called per MC trial in process_turn Step 5)
        # accumulates proposals in g_XdoPressProposals.  Emit them now so
        # that BuildAndSendSUB's broadcast-list pass can see them, and so
        # that future calls to score_order_candidates_from_broadcast pick
        # them up.  This mirrors the C emission at BuildSupportProposals.c
        # lines 396–427 (FUN_00466f80 + AppendList inside the proposal loop).
        if movement_phase and getattr(self.state, 'g_XdoPressProposals', None):
            from ..communications import emit_xdo_proposals_to_broadcast
            try:
                n_emitted = emit_xdo_proposals_to_broadcast(self.state)
                if n_emitted:
                    logger.debug(
                        "Emitted %d XDO support proposals to g_BroadcastList",
                        n_emitted,
                    )
            except Exception:
                logger.exception(
                    "emit_xdo_proposals_to_broadcast raised; continuing"
                )

        # 5i — alliance-active block
        # Gate: ally[own_power] != 0 AND DAT_00baed33 == 0 (alliance debug flag off)
        alliance_debug: bool = getattr(self.state, 'g_alliance_debug', False)
        if ally_own and not alliance_debug:
            logger.debug("Alliance block active")

            # Year-1 non-SPR non-retreat: STABBED check.
            # Year >= 2 or retreat phase: DEVIATE_MOVE.
            if self.state.g_DeceitLevel < 2 and phase not in ('AUT', 'WIN'):
                if self.state.g_DeceitLevel == 1 and phase != 'SPR':
                    _stabbed(self.state)
            else:
                _deviate_move(self.state)

            _phase_handler(self.state, 1)
            _friendly(self.state)
            _phase_handler(self.state, 2)
            _post_friendly_update(self.state)

        # 5j — submit orders and draw vote (movement) OR retreat handling
        if movement_phase:
            _hostility(self.state)
            _phase_handler(self.state, 3)
            self._build_and_send_sub(best_orders)

            _prepare_draw_vote_set(self.state)

            # Only send a draw vote to the server when Albert wants a draw.
            # The server defaults to neutral (no draw), so we only need to
            # send YES when g_draw_sent is set; no need to send NO/neutral.
            if self.state.g_draw_sent and self.game is not None:
                self._submit_draw_vote()
        else:
            # Retreat / adjustment phase — no SUB, but HOSTILITY runs in WIN
            if phase == 'WIN':
                _hostility(self.state)

                # WIN build/remove candidate pipeline — mirrors send_GOF WIN branch:
                #   ResetPerTrialState → ScoreProvinces →
                #   populate candidates → ScoreOrderCandidates_OwnPower →
                #   FUN_00442040 (builds) or FUN_0044bd40 (removes)
                self.state.g_build_order_list.clear()   # ResetPerTrialState
                self.state.g_waive_count = 0

                # Save real SC ownership before score_provinces clobbers it.
                # score_provinces resets g_SCOwnership and repopulates it from
                # unit positions (not center ownership), which breaks
                # populate_build_candidates' eligibility check.
                saved_sc_ownership = self.state.g_SCOwnership.copy()

                score_provinces(self.state, 0, 0, own_power_idx)

                # Restore real SC ownership for build/remove candidate selection.
                self.state.g_SCOwnership[:] = saved_sc_ownership

                # Count units directly from unit_info (mirrors FUN_0040ab10 which
                # counts from the unit list rather than any cached counter).
                # g_UnitCount is only refreshed by _analyze_position in movement
                # phases, so it may be stale here.
                sc    = int(self.state.sc_count[own_power_idx])
                units = sum(
                    1 for u in self.state.unit_info.values()
                    if u.get('power') == own_power_idx
                )
                if units < sc:
                    # BUILD: unit_count < sc_count
                    populate_build_candidates(self.state, own_power_idx)
                    score_order_candidates_own_power(
                        self.state, _WIN_BUILD_WEIGHTS, own_power_idx)
                    compute_win_builds(self.state, sc - units)
                elif sc < units:
                    # REMOVE: sc_count < unit_count
                    populate_remove_candidates(self.state, own_power_idx)
                    score_order_candidates_own_power(
                        self.state, _WIN_REMOVE_WEIGHTS, own_power_idx)
                    compute_win_removes(self.state, units - sc)
                # else sc == units: no builds/removes, no waives — empty GOF

                # Submit build/remove/waive orders to the game engine.
                self._submit_adjustment_orders()

            _phase_handler(self.state, 3)

        # 5k — Retreat-phase order population (SUM/AUT only)
        # In the C binary, ParseNOW populates the retreat unit list at +0x245c
        # and order map at +0x24c0 directly from the NOW message.  The Python
        # port bypasses DAIDE parsing; instead, we read dislodged units from
        # game.powers[power].retreats and choose the best destination using
        # g_GlobalProvinceScore (populated by generate_orders).
        if phase in ('SUM', 'AUT') and self.game is not None:
            self.state.g_retreat_order_list = _populate_retreat_orders(
                self.state, self.game, self.power_name, own_power_idx)
            # Also submit retreat orders to the diplomacy game engine so
            # game.process() can advance to the next phase.
            retreat_cmds = _format_retreat_commands(self.state)
            if retreat_cmds:
                logger.info("Retreat orders for %s: %s",
                            self.power_name, retreat_cmds)
                self._validate_orders(retreat_cmds)
                try:
                    self.game.set_orders(
                        power_name=self.power_name, orders=retreat_cmds,
                        wait=False)
                except TypeError:
                    # Older diplomacy lib doesn't support wait kwarg
                    self.game.set_orders(
                        power_name=self.power_name, orders=retreat_cmds)
                except Exception:
                    logger.exception(
                        "Failed to submit retreat orders to game engine")

        # Step 6 — CleanupTurn + GOF
        _cleanup_turn(self.state)
        _send_gof(self.state, self._send_dm)


    def _validate_orders(self, orders: list[str]) -> None:
        """Check submitted orders against game.get_all_possible_orders().

        Logs warnings for any illegal orders.  Does not block submission —
        the server will void illegal orders anyway, but the log helps catch
        bugs in the MC pipeline.
        """
        if self.game is None:
            return
        try:
            possible = self.game.get_all_possible_orders()
        except Exception:
            return  # can't validate without the legal-orders map

        for order in orders:
            if order == 'WAIVE':
                continue
            # Extract the location from the order (first unit+loc token)
            parts = order.split()
            if len(parts) < 2:
                continue
            loc = parts[1]  # e.g. 'PAR' from 'A PAR H'
            # Handle coasted locs like 'STP/NC'
            legal = possible.get(loc, set())
            if not legal:
                # Try without coast for retreat/build orders
                base = loc.split('/')[0]
                legal = possible.get(base, set())
            if legal and order not in legal:
                logger.warning(
                    "ORDER VALIDATION: %r not in legal orders for %s "
                    "(sample legal: %s)",
                    order, loc, list(legal)[:3],
                )


    def _submit_adjustment_orders(self) -> None:
        """Translate g_build_order_list + g_waive_count into diplomacy-format
        orders and submit them to the game.

        g_build_order_list entries are DAIDE-style strings:
            '( FRA AMY PAR ) BLD'  →  'A PAR B'
            '( FRA FLT BRE ) BLD'  →  'F BRE B'
            '( FRA AMY MAR ) REM'  →  'A MAR D'
            '( FRA FLT NAP ) REM'  →  'F NAP D'
        g_waive_count waives       →  'WAIVE' per waive
        """
        if self.game is None:
            return

        orders: list[str] = []
        for entry in self.state.g_build_order_list:
            # Parse '( POWER UNIT_TYPE PROV ) BLD|REM'
            parts = entry.replace('(', '').replace(')', '').split()
            # Expected: [POWER, AMY|FLT, PROV, BLD|REM]
            if len(parts) < 4:
                logger.warning("Adjustment: unparseable entry %r", entry)
                continue
            _power, unit_daide, prov, action = parts[0], parts[1], parts[2], parts[-1]
            unit_letter = 'F' if unit_daide == 'FLT' else 'A'
            if action == 'BLD':
                orders.append(f"{unit_letter} {prov} B")
            elif action == 'REM':
                orders.append(f"{unit_letter} {prov} D")
            else:
                logger.warning("Adjustment: unknown action %r in %r", action, entry)

        for _ in range(self.state.g_waive_count):
            orders.append("WAIVE")

        if orders:
            logger.info("Adjustment orders for %s: %s", self.power_name, orders)
            self._validate_orders(orders)
            try:
                self.game.set_orders(
                    power_name=self.power_name, orders=orders, wait=False)
            except TypeError:
                self.game.set_orders(
                    power_name=self.power_name, orders=orders)
        else:
            logger.info("Adjustment: no builds/removes/waives for %s", self.power_name)
