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

from __future__ import annotations

import asyncio
import copy
import logging
import random
import time
from typing import Any, Callable

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
    _destroy_candidate_tree,
)

logger = logging.getLogger(__name__)


class _OrdersMixin:
    # Declared for type checkers — assigned in _LifecycleMixin.__init__
    state: InnerGameState
    power_name: str
    game: Any
    current_phase: str | None

    # Cross-mixin methods (provided by _PressMixin)
    _send_dm: Callable[..., None]
    _build_and_send_sub: Callable[..., None]
    _submit_draw_vote: Callable[..., None]
    _validate_orders: Callable[..., None]

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
            5d  Phase checks: increment g_deceit_level (SPR), AnalyzePosition,
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
        self.state.g_albert_power = own_power_idx

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
        if self.state.g_press_flag == 1:
            self.state.g_press_flag = 0
        one_shot_press = getattr(self.state, 'g_one_shot_press', 0)
        if one_shot_press == 1:
            self.state.g_press_flag = 1
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
        self.state.g_press_candidate_a = [[None] * 30 for _ in range(num_powers)]
        self.state.g_press_candidate_b = [[None] * 30 for _ in range(num_powers)]

        # 5b — PhaseHandler step 0
        _phase_handler(self.state, 0)

        # 5c — per-power reset loop
        # DAT_00ba2888[power] = signed trust/relationship counter:
        #   own/ally powers: converges +1 toward 0 each movement turn (started negative)
        #   non-ally powers: reset to 0
        if not hasattr(self.state, 'g_trust_counter'):
            self.state.g_trust_counter = np.zeros(num_powers, dtype=np.int32)

        for p in range(num_powers):
            ally_p = int(self.state.g_ally_matrix[own_power_idx, p]) != 0
            is_self = (p == own_power_idx)
            for j in range(num_powers):
                if is_self or ally_p:
                    if self.state.g_trust_counter[j] < 0 and movement_phase:
                        self.state.g_trust_counter[j] += 1
                else:
                    self.state.g_trust_counter[j] = 0

        # 5d — phase-specific pre-processing

        # g_deceit_level (DAT_00baed64) = Spring-year counter; 0=pre-game, 1=year 1, …
        # Incremented each SPR. Also labelled "Deceit Level" in Albert's internal log.
        if phase == 'SPR':
            self.state.g_deceit_level += 1
            logger.debug(
                f"DeceitLevel = {self.state.g_deceit_level} "
                f"(Spring of year {self.state.g_deceit_level})"
            )

        if movement_phase:
            _analyze_position(self.state)

        # MOVE_ANALYSIS gate: year-1, press-off, Fall, allied own power
        ally_own: bool = int(self.state.g_ally_matrix[own_power_idx, own_power_idx]) != 0
        if (
            self.state.g_deceit_level == 1
            and self.state.g_press_flag == 0
            and phase == 'FAL'
            and ally_own
        ):
            _move_analysis(self.state)

        # 5e — DAT_00baed6d = 0  (deviation/retry sentinel cleared before GenerateOrders)
        self.state.g_baed6d = 0

        # 5f — GenerateOrders + ScoreOrderCandidates (FUN_004559c0)
        # ScoreOrderCandidates:
        #   Step 1: clear g_CandidateList2 (per-power secondary lists) → reset
        #            g_candidate_record_list so each scoring pass starts fresh.
        #   Step 2: reset proposal records in g_candidate_record_list for new round.
        #   Step 3: call ProcessTurn for each power where
        #             unit_count[p] > 0 AND general_orders_present[p] != 0.
        #            trial_count = (unit_count[p] * g_TrialScale + 10) // 10;
        #            if g_press_proposals_cap == 0 AND p != own_power: trial_count = 1.
        #   Steps 4–5: proposal matching / scoring (DAIDE token comparison) — absorbed
        #              into the MC candidate scoring: each ProcessTurn call populates
        #              g_candidate_record_list entries with scored order sets.
        from ...monte_carlo import generate_orders
        generate_orders(self.state, own_power_idx)

        # ── DIAGNOSTIC: log unit counts after generate_orders ────────────────
        _diag_units = sum(1 for u in self.state.unit_info.values()
                         if u.get('power') == own_power_idx)
        logger.info(
            "DIAG[%s] phase=%s unit_info_own=%d g_unit_count=%s "
            "g_general_orders_keys=%s",
            self.power_name, phase, _diag_units,
            list(self.state.g_unit_count),
            sorted(self.state.g_general_orders.keys())
            if hasattr(self.state, 'g_general_orders') else 'N/A',
        )

        # ── ScoreProvinces + ScoreOrderCandidates_AllPowers ──────────────────
        # C binary (send_GOF.c lines 56–62): for SPR/FAL movement phases,
        # ScoreProvinces computes per-province strategic scores, then
        # ScoreOrderCandidates_AllPowers uses g_candidate_scores (populated by
        # generate_orders Phase 1f) to compute final_score_set — the per-power
        # per-province value that the MC trial loop's _build_order_mto reads
        # when scoring MTO orders.  Without this call final_score_set stays all
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
                    " with empty final_score_set"
                )

        # Step 1 — clear per-power g_CandidateList2 trees (FUN_00410cf0 per power)
        # C: for each power, FUN_00410cf0(root) post-order frees the RB-tree,
        # then resets the sentinel.  Python: clear each power's g_general_orders
        # list via _destroy_candidate_tree, then reset the flat record list.
        if hasattr(self.state, 'g_general_orders'):
            for _p in range(num_powers):
                _destroy_candidate_tree(self.state.g_general_orders.get(_p))
            self.state.g_general_orders = {}
        # Mirror the wipe for g_alliance_orders — ScoreOrderCandidates' C
        # writer (Source/ScoreOrderCandidates.c lines 79–85) reconstructs all
        # four sibling 21×12B arrays per call, so a fresh translator pass needs
        # an empty alliance set too.
        if hasattr(self.state, 'g_alliance_orders'):
            self.state.g_alliance_orders = {}
        self.state.g_candidate_record_list = []

        # Translate inbound press registry → per-power general / alliance order
        # sets so MC sub-pass 1c can dispatch received-XDO orders.  Without
        # this call the binary's press-driven MTO/SUP path is unreachable in
        # Python (g_general_orders stays empty → 1c second pass is a no-op →
        # MC produces only default-HLD output).  See communications.py for the
        # ScoreOrderCandidates writer-loop port.
        # The C binary never clears DAT_00bb65ec (g_broadcast_list), so received
        # press accumulates for the lifetime of the game and the translator
        # rebuilds g_general_orders / g_alliance_orders from the accumulated set
        # on every call.  That, plus the per-phase wipe above, is what gives
        # press its multi-phase commitment semantics — no separate archive
        # needed.  See state.synchronize_from_game for the matching no-clear
        # rationale.
        # In NO_PRESS mode, g_broadcast_list only contains self-emitted XDO
        # support proposals from prior phases.  Reading them back via
        # score_order_candidates_from_broadcast would partially populate
        # g_general_orders with stale proposals (wrong positions), then
        # prevent generate_self_proposals from firing.  Skip entirely.
        _no_press = getattr(self.state, 'g_minimal_press_mode', 0) == 1
        if not _no_press:
            from ...communications import score_order_candidates_from_broadcast
            try:
                score_order_candidates_from_broadcast(self.state)
            except Exception:
                logger.exception(
                    "score_order_candidates_from_broadcast raised; continuing"
                    " with empty g_general_orders/g_alliance_orders"
                )

        # Self-proposal fallback: when g_broadcast_list is empty (NO_PRESS
        # or standalone mode), generate MTO proposals from final_score_set
        # and inject them into g_general_orders so MC Phase 1c can dispatch
        # non-hold orders.  This replaces the press round-trip that normally
        # populates these tables via score_order_candidates_from_broadcast.
        #
        # In NO_PRESS mode, the C binary's Phase 1c dispatches nothing for
        # the OWN power — all own-power order variation comes from Phase 2's
        # adjacency walk.  But other powers DO need proposals for scoring
        # context (evaluate_order_score reads all units' orders).
        # generate_self_proposals is called with skip_power=own_power so
        # that the own power's units enter Phase 2 (the MC randomization
        # path) while other powers get reasonable pre-assigned orders.
        if movement_phase and (_no_press or not self.state.g_general_orders):
            from ...heuristics import generate_self_proposals
            try:
                n_self = generate_self_proposals(
                    self.state, own_power_idx,
                    skip_power=own_power_idx if _no_press else -1,
                )
                if n_self:
                    logger.debug(
                        "Self-proposal fallback: generated %d proposals", n_self)
            except Exception:
                logger.exception(
                    "generate_self_proposals raised; continuing without "
                    "self-proposals"
                )

        # Step 3 — call ProcessTurn for every active power (DAT_0062e460 / g_unit_count)
        # g_TrialScale = DAT_004c6bb8 = difficulty*2+60 (default difficulty=100 → 260)
        # g_press_proposals_cap = DAT_004c6bbc = (difficulty*3)//10 capped at 30
        trial_scale: int = getattr(self.state, 'g_trial_scale', 260)
        press_cap: int = getattr(self.state, 'g_press_proposals_cap', 30)
        unit_count = getattr(self.state, 'g_unit_count', np.zeros(num_powers, dtype=np.int32))

        # ── 10-round ProcessTurn loop with support-opportunity re-pass ───────
        # C binary (send_GOF.c lines 114–169): runs ProcessTurn 10 rounds.
        # Each round: for every power with sc_count > 0, run ProcessTurn with
        # g_ring_convoy_enabled=0.  Then scan g_support_opportunities_set for
        # matching-power entries; for each hit, copy the ring provinces from
        # the opportunity into the state, set g_ring_convoy_enabled=1, and run
        # ProcessTurn AGAIN.  This second pass generates ring-convoy MTO
        # patterns (A→B→C→A) that are the primary mechanism for non-hold
        # orders even in NO_PRESS mode.
        #
        # In a full-press game the 10-round loop also accumulates proposal-
        # driven candidates that get refined by later BuildAndSendSUB passes.
        MC_ROUNDS = 10 if movement_phase else 1
        _mtl_fired = False
        for _mc_round in range(MC_ROUNDS):
            if _mtl_fired:
                break
            for p in range(num_powers):
                # CheckTimeLimit gate (C: BuildAndSendSUB.c line 207,221)
                if check_time_limit(self.state):
                    _mtl_fired = True
                    break
                if int(unit_count[p]) <= 0:
                    continue
                if press_cap == 0 and p != own_power_idx:
                    n_trials = 1
                else:
                    n_trials = (int(unit_count[p]) * trial_scale + 10) // 10

                # Primary pass: g_ring_convoy_enabled = 0
                self.state.g_ring_convoy_enabled = 0
                process_turn(self.state, p, num_trials=n_trials)

                # Support-opportunity re-pass: scan for matching entries and
                # run ProcessTurn again with ring convoy enabled.
                sup_opps = getattr(self.state, 'g_support_opportunities_set', None)
                if sup_opps:
                    for opp in sup_opps:
                        if check_time_limit(self.state):
                            _mtl_fired = True
                            break
                        if int(opp.get('power', -1)) != p:
                            continue
                        # Copy ring provinces from the opportunity entry.
                        # C: memcpy(DAT_00bbf668, entry+0x10, 28); DAT_00baed5c=1
                        self.state.g_ring_prov_a = int(opp.get('mover_prov', -1))
                        self.state.g_ring_prov_b = int(opp.get('target_prov', -1))
                        self.state.g_ring_prov_c = int(opp.get('supporter_prov', -1))
                        self.state.g_ring_convoy_enabled = 1
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
        # IMPORTANT: only fire when g_broadcast_list has actual received
        # press — NOT when g_general_orders was populated by
        # generate_self_proposals.  Self-proposals are synthetic guidance
        # to give MC some MTO candidates; penalising everything else would
        # collapse the candidate set and re-produce all-holds.
        #
        # g_broadcast_list accumulates forever (matching C).  It can contain
        # BOTH received-press entries AND self-emitted XDO support proposals
        # (written by emit_xdo_proposals_to_broadcast in step 5h.1).  The
        # corroboration penalty must only fire when there's genuine received
        # press from OTHER powers — not our own proposals.  In NO_PRESS mode
        # (g_minimal_press_mode == 1 or g_history_counter == 0 with no
        # incoming FRM messages) g_broadcast_list contains only self-emitted
        # entries.  Use the watermark: register_received_press bumps it when
        # real press arrives; self-emitted proposals do not.
        _bl = getattr(self.state, 'g_broadcast_list', None)
        _wm = getattr(self.state, 'g_broadcast_list_watermark', 0)
        _no_press = getattr(self.state, 'g_minimal_press_mode', 0) == 1
        has_real_press = bool(_bl) and _wm > 0 and not _no_press
        if has_real_press:
            try:
                from ...heuristics import apply_press_corroboration_penalty
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

        best_orders = self.state.g_candidate_record_list  # populated by process_turn

        # ── DIAGNOSTIC: log candidate record list stats ──────────────────────
        from collections import Counter as _Counter
        _power_counts = _Counter(c.get('power') for c in best_orders)
        _own_count = _power_counts.get(own_power_idx, 0)
        logger.info(
            "DIAG[%s] g_candidate_record_list size=%d own_power_candidates=%d "
            "per_power=%s",
            self.power_name, len(best_orders), _own_count,
            dict(_power_counts),
        )
        if _own_count > 0:
            _own_cands = [c for c in best_orders if c.get('power') == own_power_idx]
            _best = max(_own_cands, key=lambda c: float(c.get('score', 0.0)))
            _order_types = _Counter(
                e[1] if isinstance(e, (list, tuple)) and len(e) > 1 else '?'
                for e in _best.get('orders', [])
            )
            logger.info(
                "DIAG[%s] best_candidate: score=%.1f n_orders=%d order_types=%s",
                self.power_name, float(_best.get('score', 0)),
                len(_best.get('orders', [])), dict(_order_types),
            )

        # 5g — PostProcessOrders (SPR/FAL only; runs after GenerateOrders, before SUB)
        if movement_phase:
            _post_process_orders(self.state)

        # 5h — ComputePress if press mode is active this turn
        if self.state.g_press_flag == 1:
            _compute_press(self.state)

        # 5h.1 — Emit accumulated XDO support proposals into g_broadcast_list.
        # build_support_proposals (called per MC trial in process_turn Step 5)
        # accumulates proposals in g_xdo_press_proposals.  Emit them now so
        # that BuildAndSendSUB's broadcast-list pass can see them, and so
        # that future calls to score_order_candidates_from_broadcast pick
        # them up.  This mirrors the C emission at BuildSupportProposals.c
        # lines 396–427 (FUN_00466f80 + AppendList inside the proposal loop).
        # Skip XDO emission in NO_PRESS mode — it pollutes g_broadcast_list
        # with stale proposals that trigger the corroboration penalty and
        # partial g_general_orders population in subsequent phases.
        if (movement_phase
                and not _no_press
                and getattr(self.state, 'g_xdo_press_proposals', None)):
            from ...communications import emit_xdo_proposals_to_broadcast
            try:
                n_emitted = emit_xdo_proposals_to_broadcast(self.state)
                if n_emitted:
                    logger.debug(
                        "Emitted %d XDO support proposals to g_broadcast_list",
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
            if self.state.g_deceit_level < 2 and phase not in ('AUT', 'WIN'):
                if self.state.g_deceit_level == 1 and phase != 'SPR':
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
                # score_provinces resets g_sc_ownership and repopulates it from
                # unit positions (not center ownership), which breaks
                # populate_build_candidates' eligibility check.
                saved_sc_ownership = self.state.g_sc_ownership.copy()

                score_provinces(self.state, 0, 0, own_power_idx)

                # Restore real SC ownership for build/remove candidate selection.
                self.state.g_sc_ownership[:] = saved_sc_ownership

                # Count units directly from unit_info (mirrors FUN_0040ab10 which
                # counts from the unit list rather than any cached counter).
                # g_unit_count is only refreshed by _analyze_position in movement
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
        # g_global_province_score (populated by generate_orders).
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
                    self._schedule_set_orders(retreat_cmds)
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
            self._schedule_set_orders(orders)
        else:
            logger.info("Adjustment: no builds/removes/waives for %s", self.power_name)
