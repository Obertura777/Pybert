"""Monte-Carlo candidate order-generation pipeline.

Split from monte_carlo.py during the 2026-04 refactor.

``generate_orders`` runs Albert's influence-scoring pre-pass.  The source
routine does not run the final-score-dependent hold/safe-reach enumeration;
that belongs to ``send_GOF`` after ``ScoreOrderCandidates_AllPowers``.  The
``apply_influence_scores`` call is deferred into ``..heuristics`` to avoid the
heuristics→monte_carlo import cycle.

Module-level deps: ``numpy`` and ``..state.InnerGameState``.
"""


import numpy as np

from ..state import InnerGameState
from ..heuristics._primitives import _safe_pow, _signed_int_div


def _initial_build_heat_seed(
    state: InnerGameState,
    power: int,
    valid_provinces,
) -> np.ndarray:
    """Build GenerateOrders.c's owned-home-centre build-heat seed."""
    seed = np.zeros(256, dtype=np.int64)
    current = int(state.sc_count[power])
    target = int(state.g_target_sc_cnt[power])
    home_centres = state.home_centers.get(power, frozenset())
    for province in valid_provinces:
        if (province not in home_centres
                or int(state.g_sc_owner[province]) != power):
            continue
        if int(getattr(state, 'g_press_flag', 0)) == 1:
            seed[province] = 5000
        elif target > current:
            seed[province] = (target - current + 2) * 500
        else:
            seed[province] = 1000
    return seed


def _diffuse_integer_heat(
    seed: np.ndarray,
    valid_provinces,
    adjacency: dict,
    rounds: int = 5,
) -> np.ndarray:
    """Run GenerateOrders.c's signed-int64 adjacency diffusion."""
    current = np.asarray(seed, dtype=np.int64).copy()
    for _ in range(rounds):
        following = np.zeros(256, dtype=np.int64)
        for province in valid_provinces:
            total = sum(int(current[adj]) for adj in adjacency.get(province, ()))
            following[province] = _signed_int_div(total, 5)
        current = following
    return current


def _populate_candidate_scores_from_heat(
    state: InnerGameState,
    power: int,
    valid_provinces,
    heat_move: np.ndarray,
) -> None:
    """Populate GenerateOrders' bounded heat ranking for one power."""
    top_n = int(getattr(state, 'win_threshold', 18))
    scored = sorted(
        ((heat_move[province], province) for province in valid_provinces
         if heat_move[province] > 0),
        reverse=True,
    )
    count = 0
    for score, province in scored:
        if count >= top_n:
            break
        # GenerateOrders.c:433-438 compares the province +0x20 power token
        # directly; it does not first test the supply-centre byte. This also
        # preserves the source's winter overlay behavior on non-centres.
        if int(state.g_sc_owner[province]) == power:
            continue
        state.g_candidate_scores[power, province] = score
        count += 1


def _sum_influence_heat(
    state: InnerGameState,
    source_power: int,
    excluded_home_power: int,
    valid_provinces,
    heat_build: np.ndarray,
    heat_move: np.ndarray,
) -> float:
    """Return GenerateOrders' influence cell before normalization."""
    if source_power == excluded_home_power:
        return 0.0
    excluded_homes = state.home_centers.get(
        excluded_home_power, frozenset()
    )
    return sum(
        heat_build[province] + heat_move[province]
        for province in valid_provinces
        if province not in excluded_homes
    )


def generate_orders(state: InnerGameState, own_power: int) -> None:
    """
    Port of FUN_004466e0 = GenerateOrders(Albert *this).

    Master turn-evaluation driver.  Computes the full influence-matrix pipeline,
    populates g_candidate_scores, g_alliance_score, and g_opening_target.

    Phases (research.md §GenerateOrders — FUN_004466e0 / §generate_orders):
      Phase 0  — Zero all scoring tables and influence matrices.
      Phase 1  — Per-power loop: urgency seed → 5-round BFS heat diffusion →
                 candidate scores → g_heat_movement → g_influence_matrix accumulation.
      Phase 3  — Snapshot g_influence_matrix → g_influence_matrix_raw.
      Phase 4  — Per-power noise injection (_safe_pow approx).
      Phase 5  — Row-normalize g_influence_matrix to row-sums of 100.
      Phase 6  — Asymmetric g_alliance_score from Raw matrix (via compute_alliance_score).
      Phase 7  — g_opening_target per power (SPR + g_deceit_level==1 only).
      Finally  — refresh the Python live convoy-route cache. In Albert,
                 EnumerateConvoyReach belongs to InitPositionForOrders and the
                 live convoy route BFS is embedded inside ProcessTurn.
    """
    NUM_POWERS   = 7
    NUM_PROVINCES = 256
    # Valid province IDs (C checks "alive" flag, skips non-existent ones).
    valid_provs = tuple(
        getattr(state, 'valid_provinces', None) or range(NUM_PROVINCES)
    )

    # Record own power so that downstream MC functions can resolve Albert's index.
    state.albert_power_idx = own_power

    # ── InitScoringState ─────────────────────────────────────────────────────
    # C: InitScoringState is called first thing in GenerateOrders (line 100).
    # Lazy import avoids the bot.orders→monte_carlo→generation circular dep.
    from ..bot.orders import _init_scoring_state
    _init_scoring_state(state)

    # ── Phase 0 — Init ───────────────────────────────────────────────────────
    # Note: g_candidate_scores, g_target_flag, and several reach arrays are
    # already zeroed by _init_scoring_state above (GenerateOrders.c:102-130).
    state.g_heat_movement.fill(0)
    state.g_influence_matrix.fill(0)
    state.g_influence_matrix_raw.fill(0)
    state.g_influence_matrix_b.fill(0)
    state.g_alliance_score.fill(0)
    state.g_global_province_score.fill(0)
    state.g_needs_rescore.fill(-1)   # 0xffffffff sentinel

    # ── Phase 1 — Per-power heat diffusion + candidate scoring ───────────────
    for p in range(NUM_POWERS):
        # 1a — Province urgency scoring → heat_build seed (aiStack_6018 equivalent)
        # GameBoard_GetPowerRec checks the province's home-power set, then
        # +0x20 checks current SC control. Own-controlled home centres seed it.
        heat_build_seed = _initial_build_heat_seed(state, p, valid_provs)

        # 1b — 5-round BFS → heat_build (auStack_3818 equivalent)
        # Each round uses signed int64 ``__alldiv(..., 5)``.
        heat_build = _diffuse_integer_heat(
            heat_build_seed, valid_provs, state.adj_matrix
        )

        # 1c — Home-unit seed → heat_move seed (local_3018 equivalent, +5000 per own unit)
        heat_move_seed = np.zeros(NUM_PROVINCES, dtype=np.int64)
        for prov, info in state.unit_info.items():
            if info['power'] == p:
                heat_move_seed[prov] = 5000

        # 1d — 5-round BFS → heat_move (auStack_818 equivalent)
        heat_move = _diffuse_integer_heat(
            heat_move_seed, valid_provs, state.adj_matrix
        )

        # 1e — Build ordered set, populate g_candidate_scores (top-N by heat_move)
        # C (GenerateOrders.c:400–468): provinces sorted descending by heat_move
        # are inserted into an ordered set; the iterator takes at most win_threshold
        # entries, skipping any province controlled by this power. The +0x20
        # word is an SC-controller power token, not a unit token.
        # Albert+0x3ff8 = the limit field (= win_threshold, set at Albert+0x3ffc by
        # InitPositionForOrders). Non-SCs and foreign/uncontrolled SCs remain.
        _populate_candidate_scores_from_heat(state, p, valid_provs, heat_move)

        # 1f — Copy heat_move into both ApplyInfluenceScores input channels.
        # GenerateOrders.c:457-460 writes the same int64 score to
        # DAT_005af0e8 and DAT_004ec2f0; ApplyInfluenceScores normalizes them
        # differently but does not replace them with its private diffusion.
        state.g_heat_movement[p] = heat_move
        state.g_heat_movement_b[p] = heat_move

        # 1g — Accumulate g_influence_matrix[col, p]
        # GenerateOrders.c:359-373 checks whether `col` belongs to the
        # province's +0x14 home-power set and separately requires p != col.
        # Live unit ownership is not read in this pass.
        for col in range(NUM_POWERS):
            state.g_influence_matrix[col, p] = _sum_influence_heat(
                state, p, col, valid_provs, heat_build, heat_move
            )

    # ── Phase 3–4 — Snapshot Raw, inject noise ────────────────────────────────
    # Phase 3: copy g_influence_matrix → g_influence_matrix_raw (in-place to
    # preserve any external references to the array object).
    state.g_influence_matrix_raw[:] = state.g_influence_matrix
    # g_InfluenceMatrix_B (GenerateOrders.c:352-383) uses the same per-power gate
    # and heat arrays as Phase 1h; it equals the pre-normalization raw matrix.
    state.g_influence_matrix_b[:] = state.g_influence_matrix_raw

    # Phase 4: per-cell noise via _safe_pow (FUN_0047b370).
    # Formula: B[i][j] += pow(B[i][j] / (sum[j] + 1), 0.3) * 500.0
    # where sum[j] = column sum of Raw for power j (g_PowerInfluenceSum[col]).
    # ST1=base=B[i][j]/(sum[j]+1), ST0=exponent=0.3 (DAT_004af9f8).
    col_sums = np.sum(state.g_influence_matrix_raw, axis=0).astype(float)  # shape (NUM_POWERS,)
    for i in range(NUM_POWERS):
        for j in range(NUM_POWERS):
            base = state.g_influence_matrix[i, j] / (col_sums[j] + 1.0)
            state.g_influence_matrix[i, j] += _safe_pow(base, 0.3) * 500.0

    # ── Phase 5 — Row-normalize g_influence_matrix to row-sums of 100 ─────────
    for i in range(NUM_POWERS):
        row_sum = float(np.sum(state.g_influence_matrix[i]))
        if row_sum != 0.0:
            state.g_influence_matrix[i] *= 100.0 / row_sum

    # ── Phase 6 — Compute asymmetric g_alliance_score ─────────────────────────
    # Delegated to compute_alliance_score (heuristics/influence.py).
    # C condition (GenerateOrders.c:593): (A < B) == (A == B) simplifies to
    # A > B → -3*(A/(B+1))*(B/col_sum); else +3*(B/(A+1))*(B/col_sum).
    # where A = Raw[row][col], B = Raw[col][row],
    # col_sum = column sum of Raw for column=row.
    from ..heuristics import apply_influence_scores, set_opening_targets, compute_alliance_score
    compute_alliance_score(state)

    # ── ApplyInfluenceScores ────────────────────────────────────────────────
    # C binary: GenerateOrders.c L619 calls ApplyInfluenceScores after the
    # per-power heat/influence loop.  This populates g_unit_adjacency_count,
    # normalizes the two GenerateOrders-owned movement-heat copies, and —
    # crucially — fills g_order_list, which downstream feeds g_general_orders
    # via the press
    # translator pipeline.  Without this call g_order_list stays empty and
    # the MC trial loop (ProcessTurn Phase 1c) has no orders to dispatch.
    apply_influence_scores(state, own_power)
    set_opening_targets(state)
