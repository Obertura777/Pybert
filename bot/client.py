"""AlbertClient — NetworkGame adapter wrapping the Albert bot pipeline.

Split from bot.py during the 2026-04 refactor (slice 5/5).

The class ties together the extracted submodules (``analysis``, ``gof``,
``orders``, ``strategy``) and the external subsystems (``communications``,
``dispatch``, ``heuristics``, ``monte_carlo``, ``state``, ``utils``).  It
owns the lifecycle: connect → join → play → turn-loop → disconnect.

Kept in a dedicated module so ``bot/__init__.py`` can stay a thin re-export
manifest.
"""

import asyncio
import copy
import logging
import random
import time

import numpy as np
from diplomacy.client.connection import connect

from ..state import InnerGameState
from ..monte_carlo import (
    process_turn,
    update_score_state,
    check_time_limit,
    _F_ORDER_TYPE, _F_DEST_PROV, _F_DEST_COAST,
)
from ..communications import (
    parse_message,
    dispatch_scheduled_press,
    cancel_prior_press,
    _send_ally_press_by_power,
)
from ..heuristics import (
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
from ..dispatch import validate_and_dispatch_order

from ._shared import _POWER_NAMES
from .orders import (
    _populate_retreat_orders,
    _format_retreat_commands,
    _build_order_seq_from_table,
)
from .gof import _send_gof, _evaluate_order_proposals_and_send_gof
from .analysis import (
    _phase_handler, _analyze_position, _move_analysis,
    _post_process_orders, _compute_press,
    _cleanup_turn, _prepare_draw_vote_set,
    _rank_candidates_for_power,
    _game_phase, _game_status,
)
from .strategy import (
    _stabbed, _deviate_move, _friendly, _hostility, _post_friendly_update,
)

logger = logging.getLogger(__name__)


class AlbertClient:
    # DONE(api): #4 — play() uses NetworkGame notification callbacks
    #   (GameProcessed, GameStatusUpdate, GameMessageReceived) with a 30s
    #   heartbeat safety-net poll instead of 2s blind polling.
    # DONE(api): #5 — _validate_orders() checks submitted orders against
    #   game.get_all_possible_orders() before every set_orders() call.
    #   Logs warnings for illegal orders without blocking submission.
    # DONE(api): #6 — send_is_bot() and set_comm_status() called after join.
    def __init__(self, power_name: str, host: str, port: int, *,
                 username: str | None = None, password: str = 'password',
                 game_id: str | None = None):
        self.power_name = power_name
        self.host = host
        self.port = port
        self.username = username or f'Albert_{power_name}'
        self.password = password
        self.target_game_id = game_id   # None = auto-pick first available
        self.state = InnerGameState()
        self.connection = None
        self.game = None
        self.current_phase = None

    async def play(self):
        """
        Main event loop connecting to the diplomacy server.

        Uses NetworkGame notification callbacks (GameProcessed,
        GameStatusUpdate, GameMessageReceived) for reactive phase handling
        instead of a fixed-interval poll loop.  A lightweight 30s heartbeat
        poll remains as a safety net (catches missed notifications or
        server reconnects).
        """
        self.connection = await connect(self.host, self.port)
        channel = await self.connection.authenticate(
            username=self.username,
            password=self.password,
        )

        logger.info(f"Albert successfully authenticated as {self.power_name}"
                     f" (user={self.username!r})")

        if self.target_game_id:
            target_game_id = self.target_game_id
        else:
            games = await channel.list_games()
            if not games:
                logger.warning("No active games found on the server.")
                return
            # `list_games()` returns DataGameInfo records (attribute access),
            # but older builds returned plain dicts. Support both.
            first = games[0]
            target_game_id = first['game_id'] if isinstance(first, dict) else first.game_id

        logger.info(f"Joining game: {target_game_id}")

        self.game = await channel.join_game(game_id=target_game_id, power_name=self.power_name)

        # ── Announce bot metadata to server ──────────────────────────────
        try:
            if hasattr(self.game, 'send_is_bot'):
                self.game.send_is_bot(is_bot=True)
            if hasattr(self.game, 'set_comm_status'):
                self.game.set_comm_status(comm_status='ready')
            logger.info("Announced bot metadata to server.")
        except Exception as exc:
            logger.debug("Bot metadata announcement failed (non-fatal): %s", exc)

        # ── Register notification callbacks ──────────────────────────────
        done_event = asyncio.Event()

        def _on_game_processed(game, notification):
            """Called by the diplomacy lib after each phase processes."""
            phase = _game_phase(game)
            if phase == self.current_phase:
                return  # duplicate notification
            self.current_phase = phase
            logger.info(f"[notification] New phase: {phase}")
            try:
                self.on_game_update(game)
            except Exception as exc:
                logger.exception(f"on_game_update raised: {exc}")

        def _on_game_status_update(game, notification):
            """Called when game status changes (completed, canceled, etc.)."""
            status = getattr(notification, 'status', '') or ''
            logger.info(f"[notification] Game status: {status}")
            if status in ('completed', 'canceled'):
                done_event.set()

        def _on_message_received(game, notification):
            """Called when a press message arrives between phases."""
            msg = getattr(notification, 'message', None)
            if msg is None:
                return
            sender = getattr(msg, 'sender', '') or ''
            if sender == self.power_name:
                return  # skip own messages
            body = getattr(msg, 'message', '') or ''
            logger.debug("[notification] press from %s: %r", sender, body)
            try:
                self.on_message_received(sender, body)
            except Exception:
                logger.exception("on_message_received raised for %r", body)

        if hasattr(self.game, 'add_on_game_processed'):
            self.game.add_on_game_processed(_on_game_processed)
            self.game.add_on_game_status_update(_on_game_status_update)
            self.game.add_on_game_message_received(_on_message_received)
            logger.info("Registered notification callbacks (reactive mode).")
        else:
            logger.info("NetworkGame notifications not available; using poll mode.")

        # ── Process the initial phase (game may already be in progress) ──
        phase = _game_phase(self.game)
        status = _game_status(self.game)
        if status in ('completed', 'canceled'):
            logger.info("Game already finished — exiting.")
            return
        if phase and phase != 'FORMING':
            self.current_phase = phase
            logger.info(f"Initial phase: {phase}")
            try:
                self.on_game_update(self.game)
            except Exception as exc:
                logger.exception(f"on_game_update raised on initial phase: {exc}")

        # ── Wait for game end, with a heartbeat safety-net poll ──────────
        HEARTBEAT = 30  # seconds between fallback polls
        while not done_event.is_set():
            try:
                await asyncio.wait_for(done_event.wait(), timeout=HEARTBEAT)
            except asyncio.TimeoutError:
                pass  # heartbeat tick — check for missed phase changes

            # Safety-net: detect phase changes the notification may have missed
            try:
                phase = _game_phase(self.game)
                status = _game_status(self.game)
            except Exception as exc:
                logger.exception(f"Albert heartbeat: error reading state: {exc}")
                continue

            if status in ('completed', 'canceled'):
                logger.info("Game finished (heartbeat) — exiting Albert loop")
                return

            if phase and phase != self.current_phase:
                self.current_phase = phase
                logger.info(f"Missed-notification catch-up: {phase}")
                try:
                    self.on_game_update(self.game)
                except Exception as exc:
                    logger.exception(f"on_game_update raised: {exc}")

        logger.info("Game finished — exiting Albert loop")

    # ── NOW-handler entry point ──────────────────────────────────────────────

    def on_game_update(self, game_object):
        """
        Triggered when NOW or SCO received (or state polled).
        Mirrors the NOW handler → vtable+0xe8 → GenerateAndSubmitOrders call chain.

        Also drains inbound game.messages and feeds each new one to
        on_message_received between synchronize_from_game and order generation.
        synchronize_from_game intentionally does NOT clear g_BroadcastList
        (matching the C binary's accumulate-forever semantics), so press
        registered here survives into the translator/corroboration pass.
        """
        self.game = game_object
        self.state.synchronize_from_game(game_object)
        self._drain_incoming_press(game_object)

        if _game_phase(game_object) != 'COMPLETED' and _game_status(game_object) != 'completed':
            self.generate_and_submit_orders()

    def _drain_incoming_press(self, game_object) -> None:
        """Walk new game.messages and dispatch each through on_message_received.

        Tracks (time_sent, sender, recipient) tuples to dedupe across polls.
        Skips messages we sent ourselves.
        """
        if not hasattr(self, '_seen_msg_ids') or self._seen_msg_ids is None:
            self._seen_msg_ids = set()
        msgs = getattr(game_object, 'messages', None)
        if msgs is None:
            return
        try:
            seq = list(msgs.values()) if hasattr(msgs, 'values') else list(msgs)
        except Exception:
            return
        for m in seq:
            msg_id = (
                getattr(m, 'time_sent', None),
                getattr(m, 'sender', None),
                getattr(m, 'recipient', None),
            )
            if msg_id in self._seen_msg_ids:
                continue
            self._seen_msg_ids.add(msg_id)
            sender = getattr(m, 'sender', '') or ''
            if sender == self.power_name:
                continue
            body = getattr(m, 'message', '') or ''
            logger.debug("[albert<-press] from %s: %r", sender, body)
            try:
                self.on_message_received(sender, body)
            except Exception:
                logger.exception("on_message_received raised for %r", body)

    # ── GenerateAndSubmitOrders ──────────────────────────────────────────────

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

    # ── DM wire helper ───────────────────────────────────────────────────────

    def _send_dm(self, msg: object) -> None:
        """
        Send DAIDE direct-message using python-diplomacy NetworkGame API.

        Per-power fan-out — Albert never broadcasts to ``GLOBAL``.  Even when
        the underlying DAIDE press is logically a broadcast (GOF, BCC, an
        XDO PRP intended for everyone), python-diplomacy treats GLOBAL as a
        "system / all observers" channel that bypasses the per-power inbox
        and shows up untargeted in the message log.  The C original always
        addressed press to a specific recipient power; reproducing that here
        means iterating ``self.game.powers`` and emitting one Message per
        non-self power.

        Three further things to get right:

        * ``Message`` requires a ``phase`` field — python-diplomacy's
          validator raises ``TypeException: Expected type <class 'str'>,
          got type <class 'NoneType'>`` if it's omitted, and the per-phase
          server log gives no hint which key was missing.

        * On a NetworkGame the wire path is the async
          ``game.send_game_message(message=...)`` — ``add_message`` is
          a server-only API and asserts ``self.is_server_game()`` on a
          client-side game.  ``send_game_message`` returns a tornado-wrapped
          Future that's already in-flight on the connection's IO loop, so
          we just attach an error callback rather than awaiting.

        * Re-checking the phase before dispatch dodges the common race
          where the server has already advanced past ``phase`` while
          Albert was scoring trials.
        """
        logger.debug("SendDM: %r", msg)
        if self.game is None:
            return
        try:
            from diplomacy import Message
        except ImportError:
            logger.warning("diplomacy.Message not available; cannot send DAIDE press.")
            return

        # Determine recipient set.  An explicit per-power recipient on the
        # message object wins; otherwise fan out to every other power.
        msg_recipient = getattr(msg, 'recipient', None)
        powers_attr = getattr(self.game, 'powers', None) or {}
        try:
            all_powers = list(powers_attr.keys())
        except AttributeError:
            all_powers = list(powers_attr)
        if msg_recipient and msg_recipient not in ('GLOBAL', 'ALL', None):
            recipients = [msg_recipient]
        else:
            recipients = [p for p in all_powers if p != self.power_name]
        if not recipients:
            logger.debug("_send_dm: no recipients (powers=%r); dropping", all_powers)
            return

        # Phase-staleness guard: compare the phase Albert was scoring for
        # (captured by play() into self.current_phase before on_game_update
        # ran) against the server's now-current phase.  If the server has
        # advanced — common when MC scoring takes longer than the deadline —
        # drop the entire fan-out instead of paying N round-trip
        # GamePhaseException rejections.
        scoring_phase = getattr(self, 'current_phase', None) or ''
        server_phase  = getattr(self.game, 'current_short_phase', None) or ''
        if scoring_phase and server_phase and scoring_phase != server_phase:
            logger.debug(
                "_send_dm: skipping stale message (built for %s, server is"
                " now at %s)", scoring_phase, server_phase,
            )
            return
        # Use the server's current phase on the wire — Message validates
        # phase against the live game state, so an off-by-one would be
        # rejected even if scoring_phase == server_phase a moment ago.
        phase = server_phase or scoring_phase

        body = str(msg)
        is_network = hasattr(self.game, 'send_game_message')
        import asyncio as _asyncio

        for recipient in recipients:
            try:
                message_obj = Message(
                    sender=self.power_name,
                    recipient=recipient,
                    phase=phase,
                    message=body,
                )
            except Exception as exc:
                logger.warning(
                    "_send_dm: Message validation failed (recipient=%r,"
                    " phase=%r): %s: %s",
                    recipient, phase, type(exc).__name__, exc,
                )
                continue

            if is_network:
                _SEND_RETRIES = 3
                for _attempt in range(_SEND_RETRIES):
                    try:
                        fut = self.game.send_game_message(message=message_obj)
                        if _asyncio.iscoroutine(fut):
                            try:
                                loop = _asyncio.get_running_loop()
                                fut = loop.create_task(fut)
                            except RuntimeError:
                                _asyncio.run(fut)
                                break
                        if hasattr(fut, 'add_done_callback'):
                            def _log_send_error(f, _r=recipient, _p=phase):
                                try:
                                    f.result()
                                except Exception as exc:
                                    logger.warning(
                                        "_send_dm: send_game_message rejected"
                                        " (recipient=%r, phase=%r): %s: %s",
                                        _r, _p, type(exc).__name__, exc,
                                    )
                            fut.add_done_callback(_log_send_error)
                        break  # dispatch succeeded
                    except Exception as exc:
                        if _attempt < _SEND_RETRIES - 1:
                            _delay = 0.5 * (2 ** _attempt)
                            logger.info(
                                "_send_dm: send_game_message attempt %d/%d"
                                " failed (recipient=%r, phase=%r): %s —"
                                " retrying in %.1fs",
                                _attempt + 1, _SEND_RETRIES,
                                recipient, phase, exc, _delay,
                            )
                            import time as _time
                            _time.sleep(_delay)
                        else:
                            logger.warning(
                                "_send_dm: send_game_message failed after"
                                " %d attempts (recipient=%r, phase=%r):"
                                " %s: %s",
                                _SEND_RETRIES, recipient, phase,
                                type(exc).__name__, exc,
                            )
            else:
                # Server-game / offline path (kept for unit tests).
                try:
                    self.game.add_message(message_obj)
                except Exception as exc:
                    logger.warning(
                        "_send_dm: add_message rejected (recipient=%r,"
                        " phase=%r): %s: %s",
                        recipient, phase, type(exc).__name__, exc,
                    )

    # ── BuildAndSendSUB helper ───────────────────────────────────────────────

    def _build_and_send_sub(self, best_orders: list) -> None:
        """
        Port of BuildAndSendSUB (FUN_00457890).

        In the C bot this is a multi-trial proposal-scoring loop over
        g_BroadcastList; Monte Carlo (process_turn) plays that role in Python,
        so only the surrounding press/submission scaffold is ported here.

        Structure (mirroring FUN_00457890 at each labelled site):
          1. ScheduledPressDispatch     — pre-loop flush (line 252).
          2. CheckTimeLimit             — abort if MTL already fired (line 291).
          3. Order submission           — RegisterProposalOrders / ScoreOrderCandidates
                                         collapsed to game.set_orders (MC already ran).
          4. UpdateScoreState           — refresh ally order tables after commit
                                         (line 395 inside inner loop, post-submission).
          5. SendAllyPressByPower loop  — for each power when g_HistoryCounter > 0
                                         (lines 659–666).
          6. g_ProposalHistoryMap press — iterate received/sent proposals, check
                                         province overlap and trust, send DM press
                                         (lines 847–1271; STUB — awaits RECEIVE_PROPOSAL
                                         / RESPOND / g_ProposalHistoryMap port).
          7. CancelPriorPress           — withdraw stale prior-press token (line 693).

        Callees still unported: ScoreOrderCandidates (FUN_004559c0),
        RECEIVE_PROPOSAL, RESPOND, SendAlliancePress,
        FUN_00419300, FUN_00466ed0, FUN_00466f80, FUN_00465df0,
        FUN_00465930, FUN_00465d90, FUN_00465cf0, FUN_00410cf0,
        FUN_00443ed0.
        FUN_00422a90 ported as validate_and_dispatch_order (dispatch.py).
        """
        own_power_idx = getattr(self.state, 'albert_power_idx', 0)
        n_powers = int(getattr(self.state, 'n_powers', 7))

        # ── 1. ScheduledPressDispatch — pre-loop press flush (line 252) ──────
        dispatch_scheduled_press(self.state, self._send_dm)

        # ── 2. CheckTimeLimit (line 291) — MTL guard ─────────────────────────
        if check_time_limit(self.state):
            logger.warning("MTL expired before BuildAndSendSUB — skipping SUB")
            return

        # Pick the highest-scoring candidate for OUR power. process_turn
        # appends one candidate record per (power, trial), so best_orders
        # holds candidates for all 7 powers — we want our own.
        own_candidates = [c for c in best_orders if c.get('power') == own_power_idx]
        if own_candidates:
            best = max(own_candidates, key=lambda c: float(c.get('score', 0.0)))
            order_pairs = best.get('orders', [])
        else:
            best = None
            order_pairs = []

        self.state.g_SubmittedOrders = []
        # Restore g_OrderTable from the candidate snapshot for our own provinces.
        # process_turn resets g_OrderTable per-trial and per-power, so by the
        # time we read it here it reflects the *last* trial of the *last*
        # power — not the trial that produced the chosen own-power candidate.
        # The candidate carries the per-order field snapshot (see
        # evaluate_order_proposal in monte_carlo.py); rehydrate the relevant
        # rows before calling _build_order_seq_from_table.
        from ..monte_carlo import _F_SECONDARY as _MC_F_SECONDARY  # local import
        for entry in order_pairs:
            if len(entry) >= 5:
                prov, order_type, dest_prov, dest_coast, secondary = entry[:5]
                self.state.g_OrderTable[prov, _F_ORDER_TYPE] = float(order_type)
                self.state.g_OrderTable[prov, _F_DEST_PROV]  = float(dest_prov)
                self.state.g_OrderTable[prov, _F_DEST_COAST] = float(dest_coast)
                self.state.g_OrderTable[prov, _MC_F_SECONDARY] = float(secondary)
            else:
                prov = entry[0]
            seq = _build_order_seq_from_table(self.state, prov)
            if seq is not None:
                validate_and_dispatch_order(self.state, own_power_idx, seq)

        formatted = list(getattr(self.state, 'g_SubmittedOrders', []))

        # Safety net: if MC still produced no usable orders for our units,
        # default every own unit to a HOLD. process_turn now seeds
        # g_OrderTable[prov, _F_ORDER_TYPE] = _ORDER_HLD for every own unit
        # at trial start (Phase 1b'), so MC normally returns a non-empty
        # candidate even on a fresh / no-press game. This branch only
        # triggers if a trial bug or upstream reset clears the table after
        # seeding — submitting HOLDs is strictly better than nothing
        # (which would be civil disorder) and keeps the test harness alive.
        if not formatted:
            try:
                state = self.game.get_state() if self.game is not None else {}
                units = list(state.get('units', {}).get(self.power_name, []))
            except Exception:
                units = []
            formatted = [f"{u} H" for u in units]
            if formatted:
                logger.info(
                    "MC produced no orders for %s — defaulting %d units to HOLD",
                    self.power_name, len(formatted),
                )
        logger.info("SUB — %d orders for %s: %s",
                    len(formatted), self.power_name, formatted)

        if self.game is not None:
            self._validate_orders(formatted)
            try:
                self.game.set_orders(power_name=self.power_name, orders=formatted, wait=False)
            except TypeError:
                # Older diplomacy lib doesn't support wait kwarg
                self.game.set_orders(power_name=self.power_name, orders=formatted)

        # ── 3b. RankCandidatesForPower — inner-loop candidate selection ─────
        # C: FUN_00424850(piVar10, '\0') called per-power in BuildAndSendSUB
        # inner loop after ScoreOrderCandidates.  In Python, MC has already
        # run; call once per power to rank g_CandidateRecordList entries.
        for power_i in range(n_powers):
            _rank_candidates_for_power(self.state, power_i)

        # ── 4. UpdateScoreState — post-commit refresh (line 395) ─────────────
        update_score_state(self.state)

        # ── 5. SendAllyPressByPower loop (lines 659–666) ─────────────────────
        # C: if puVar18[4] == DAT_00baed60 AND g_HistoryCounter > 0:
        #      for i in range(n_powers): SendAllyPressByPower(i)
        # The g_BroadcastList node condition collapses to "own proposal processed"
        # which is always true here after order submission.
        if self.state.g_HistoryCounter > 0:
            for power_i in range(n_powers):
                _send_ally_press_by_power(self.state, power_i)

        # ── 6a. RECEIVE_PROPOSAL + EvaluatePress + RESPOND pass ───────────────
        # C: BuildAndSendSUB outer loop (lines 490–569) processes g_BroadcastList
        #    entries where received_flag==1 AND type_flag==0 AND
        #    trial_count == g_PressProposalsCap.
        # Python: MC already ran; treat all received entries as fully scored.
        # After RESPOND, C calls FUN_00457520 (EvaluateOrderProposalsAndSendGOF).
        from ..communications import (
            receive_proposal as _receive_proposal,
            evaluate_press   as _evaluate_press,
            respond          as _respond,
        )
        press_cap = getattr(self.state, 'g_PressProposalsCap', 30)
        for _entry in list(self.state.g_BroadcastList):
            if not _entry.get('received_flag'):
                continue
            if _entry.get('type_flag', 0) != 0:
                continue
            # Python MC already ran; treat trial_count as complete.
            _entry['trial_count'] = press_cap

            _from_tok  = _entry.get('from_power_tok', 0)
            _from_idx  = _from_tok & 0xff
            _prop_toks = _entry.get('sublist3', _entry.get('press_content', []))

            # RECEIVE_PROPOSAL — dedup + log + PrepareAllyPressEntry
            _receive_proposal(self.state, _from_idx, _prop_toks, self._send_dm)

            # EvaluatePress = FUN_0042fc40 → YES (0x481C) or REJ (0x4814)
            _sVar2 = _evaluate_press(self.state, _entry)

            # RESPOND = albert/Source/RESPOND.c
            _st = _entry.get('sched_time', 0)
            _respond(
                self.state,
                press_list=_entry,
                response_type=_sVar2,
                elapsed_lo=_st & 0xFFFFFFFF,
                elapsed_hi=(_st >> 32) & 0xFFFFFFFF,
                send_fn=self._send_dm,
            )
            # C line 569: FUN_00457520 = EvaluateOrderProposalsAndSendGOF
            _evaluate_order_proposals_and_send_gof(self.state, self._send_dm)

        # ── 6b. g_DealList press deal matching (lines 847–1271, g_HistoryCounter>19)
        # C iterates g_BroadcastList for own-proposal entries; for each entry
        #   with trust ≥ 1/2 and province overlap, sends SUB press via
        #   SendAlliancePress.  Proxy: iterate g_DealList (trust ≥ 3, overlap).
        if self.state.g_HistoryCounter > 19:
            from ..communications import send_alliance_press
            submitted_provs = {prov for prov, _ in order_pairs}
            for deal in list(getattr(self.state, 'g_DealList', [])):
                other = deal.get('power', -1)
                if other < 0:
                    continue
                trust = int(self.state.g_AllyTrustScore[own_power_idx, other])
                if trust < 3:
                    continue
                deal_provs = deal.get('province_set', set())
                overlap = deal_provs & submitted_provs
                if overlap:
                    press_seq = f"PRP ( PCE ( {own_power_idx} {other} ) )"
                    send_alliance_press(
                        self.state,
                        key=other,
                        entry_data={
                            'power':        other,
                            'province_set': overlap,
                            'press_seq':    press_seq,
                        },
                    )
                    logger.debug(
                        "Deal match: queued alliance press to power %d "
                        "(trust=%d, overlap=%s)",
                        other, trust, overlap,
                    )

        # ── 7. CancelPriorPress — DM send with TokenSeq_Count guard (line 693)
        cancel_prior_press(self.state, own_power_idx, self._send_dm)

    # ── Draw vote ─────────────────────────────────────────────────────────────

    def _submit_draw_vote(self) -> None:
        """Submit a YES draw vote to the server/game.

        Only called when Albert actually wants a draw (g_draw_sent == 1).
        The server defaults to neutral each phase, so we never need to
        explicitly send NO or NEUTRAL — only YES when we want it.
        """
        if self.game is None:
            return
        try:
            # NetworkGame (server): async vote request
            if hasattr(self.game, 'vote') and callable(self.game.vote):
                self.game.vote(vote='yes')
            else:
                # Local Game: set directly on the power object
                power = self.game.powers.get(self.power_name)
                if power is not None:
                    power.vote = 'yes'
            logger.info("Draw vote: submitted YES to server")
        except Exception as exc:
            logger.warning("Draw vote: failed to submit YES: %s", exc)

    # ── Order validation ──────────────────────────────────────────────────

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

    # ── Adjustment (build/remove) order submission ─────────────────────────

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

    # ── Press handler ────────────────────────────────────────────────────────

    def on_message_received(self, sender: str, msg: str) -> None:
        """Triggered when a press message (FRM) arrives."""
        parse_message(self.state, sender, msg)
