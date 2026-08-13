"""WIN-phase build/remove candidate generation and order emission.

Split from heuristics.py during the 2026-04 refactor.

- ``populate_build_candidates``  — seed BUILD-phase candidate set
- ``populate_remove_candidates`` — seed REMOVE-phase candidate set
- ``compute_win_builds``         — rank and emit BLD orders
- ``compute_win_removes``        — rank and emit REM orders

Module-level deps: ``..state.InnerGameState``.  Owns the tuning-weight
constants ``_WIN_BUILD_WEIGHTS``, ``_WIN_REMOVE_WEIGHTS``,
``_SPR_FAL_WEIGHTS`` and the DAIDE-short-name table
``_WIN_DAIDE_POWER_NAMES``.
"""

from ..state import InnerGameState



# ── WIN build/remove pipeline ─────────────────────────────────────────────────
#
# Weight constants read from the Albert object at runtime (stored as int64 pairs
# at 8-byte stride).  Confirmed from research.md BotObject offset table.
#   REMOVE vector at Albert+0x4e00 stride 8: [50, 70, 100, 70, 10, 5, 3, 2, 1]
#   BUILD  vector at Albert+0x4e58 stride 8: [100, 90, 70, 40, 20, 10, 5, 3, 2]
_WIN_REMOVE_WEIGHTS: list = [50, 70, 100, 70, 10, 5, 3, 2, 1]
_WIN_BUILD_WEIGHTS:  list = [100, 90, 70, 40, 20, 10, 5, 3, 2]
# SPR/FAL round weights — Albert ctor @ 0x00425e03 / 0x00425ead.
# 10 × uint64 at stride 8; rounds 0–9 correspond to BFS depths 0–9.
# SPR and FAL differ only in rounds 0 and 1 (swapped).
# All 10 values confirmed from ctor dump 0x425dc2–0x425e8b:
#   EBX=5 @ 0x425dc2, EAX=1000 @ 0x425ded, EBP=10 @ 0x425df2, ECX=3 @ 0x425e91.
_SPR_ROUND_WEIGHTS: list = [500, 1000, 30, 10, 6, 5, 4, 3, 2, 1000]
_FAL_ROUND_WEIGHTS: list = [1000,  500, 30, 10, 6, 5, 4, 3, 2, 1000]
_SPR_FAL_WEIGHTS = _SPR_ROUND_WEIGHTS  # backward-compat alias

# DAIDE short power names (index matches power_idx 0-6: AUS…TUR).
_WIN_DAIDE_POWER_NAMES: list = ['AUS', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']


def compute_build_delta(state: InnerGameState) -> bool:
    """Port of FUN_0040ab10 (ComputeBuildDelta).

    Called from the WIN-season NOW path.  Counts SC and unit totals for
    every power, writes per-power build/remove flag and count into
    ``state.g_build_delta``, and returns True when any power's SC count
    differs from its unit count.

    ``state.g_build_delta[p]`` is a dict ``{'flag': int, 'delta': int}``
    where ``flag == 1`` means BUILD (SC > units) and ``flag == 0`` means
    REMOVE (units >= SC).  ``delta`` is the absolute difference.

    C stores the same data in a std::map at ``this+0x2468``; the BST
    candidate fields (``candidates_ptr``, ``candidate_bst``) from that
    struct are not needed in Python because candidate seeding is done by
    ``populate_build_candidates`` / ``populate_remove_candidates``.
    """
    num_powers = 7
    unit_counts = [0] * num_powers
    # Mirror C:79 — stamp province unit-holder field (province[prov]+0x20 = power|0x4100)
    # so g_sc_owner is fresh before _hostility / compute_influence_matrix read it.
    state.g_sc_owner.fill(-1)
    for prov, info in state.unit_info.items():
        p = int(info['power'])
        if 0 <= p < num_powers:
            unit_counts[p] += 1
            if prov < 256:
                state.g_sc_owner[prov] = p

    imbalance = False
    build_delta: dict = {}
    for p in range(num_powers):
        sc    = int(state.sc_count[p])
        units = unit_counts[p]
        if units < sc:
            build_delta[p] = {'flag': 1, 'delta': sc - units}
        else:
            build_delta[p] = {'flag': 0, 'delta': units - sc}
        if sc != units:
            imbalance = True

    state.g_build_delta = build_delta
    return imbalance


def populate_build_candidates(state: InnerGameState, own_power: int) -> None:
    """Seed g_candidate_scores[own_power] with eligible WIN build provinces.

    Mirrors the candidate-ordered-set population that FUN_0040ab10
    (`ComputeBuildDelta`) performs for the BUILD branch
    (unit_count < sc_count).  In the C code `ComputeBuildDelta` is called
    from the ParseNOW WIN-season path; in the Python rewrite the WIN
    build/remove pipeline is driven directly from
    `generate_and_submit_orders` (bot.py) after `synchronize_from_game`.  A province is eligible when:
      • it is one of own_power's home supply centres  (state.home_centers)
      • own_power currently owns it                   (g_sc_ownership[own,prov]==1)
      • no unit currently stands there                (prov not in unit_info)

    Preserves the g_attack_count-based BFS values from score_provinces for
    eligible provinces so that score_order_candidates_own_power sees the same
    round-0 differentiation that the C BST ordering uses.  Non-eligible
    provinces are zeroed across all rounds so candidate_set_contains and the
    scoring pass skip them.  A floor of 1.0 at round 0 ensures candidate
    membership is visible when g_attack_count is 0.

    C: candidate set lives at Albert+own_power*0x78+0x361c; count stored at
    Albert+0x4e50; limit (delta) at Albert+0x4e54.
    """
    home_provs = state.home_centers.get(own_power, frozenset())
    state.g_adjustment_build_candidates = []
    state.g_adjustment_candidate_scores = {}
    state.g_adjustment_candidate_provinces = set()
    for prov in range(256):
        is_eligible = (
            prov in home_provs
            and state.g_sc_ownership[own_power, prov] == 1
            and prov not in state.unit_info
        )
        if not is_eligible:
            state.g_candidate_bfs[own_power, :, prov] = 0.0
            continue
        state.g_adjustment_candidate_provinces.add(prov)

        # ScoreOrderCandidates_OwnPower iterates keys containing both the
        # province and the AMY/FLT coast token. Armies are legal at every home
        # centre; fleets are additional candidates at coastal centres.
        state.g_adjustment_build_candidates.append({
            'province': prov, 'unit_type': 'AMY', 'coast': '',
        })
        coast_keys = sorted(
            coast for (pid, coast) in state.fleet_coast_adj
            if pid == prov
        )
        if coast_keys:
            for coast in coast_keys:
                state.g_adjustment_build_candidates.append({
                    'province': prov, 'unit_type': 'FLT', 'coast': coast,
                })
        elif state.fleet_adj_matrix.get(prov):
            state.g_adjustment_build_candidates.append({
                'province': prov, 'unit_type': 'FLT', 'coast': '',
            })


def populate_remove_candidates(state: InnerGameState, own_power: int) -> None:
    """Seed g_candidate_scores[own_power] with eligible WIN remove provinces.

    Mirrors FUN_0040ab10 for the REMOVE branch (unit_count > sc_count).
    Every province that holds an own unit is a candidate.

    Preserves g_attack_count-based BFS values from score_provinces for
    eligible provinces; zeros all rounds for non-eligible provinces.
    Floor of 1.0 at round 0 when g_attack_count is 0.

    C: candidate set lives at Albert+own_power*0x78+0x361c; count at
    Albert+0x4df8; limit (delta) at Albert+0x4dfc.
    """
    state.g_adjustment_build_candidates = []
    state.g_adjustment_candidate_scores = {}
    state.g_adjustment_candidate_provinces = set()
    for prov in range(256):
        is_eligible = (
            prov in state.unit_info
            and state.unit_info[prov].get('power') == own_power
        )
        if not is_eligible:
            state.g_candidate_bfs[own_power, :, prov] = 0.0
        else:
            state.g_adjustment_candidate_provinces.add(prov)


def compute_win_builds(state: InnerGameState, delta: int) -> None:
    """Port of FUN_0044bd40 — select top `delta` build candidates and emit BLD orders.

    Called from send_GOF when unit_count < sc_count (BUILD phase).

    Algorithm:
      1. Collect all provinces in the candidate set (candidate_set_contains).
      2. Sort by g_candidate_scores descending (highest strategic value first).
      3. Take up to `delta` provinces; any shortfall becomes waives.
      4. For each selected province determine unit type:
           FLT — if province is coastal (any adjacent province is a water province).
           AMY — otherwise (inland).
         Candidate identity preserves province plus AMY/FLT coast token; coastal
         home centres therefore admit both army and fleet builds.
      5. Append '( POWER AMY/FLT PROV ) BLD' to state.g_build_order_list.
      6. Set state.g_waive_count = delta - len(selected).

    C: inserts BST nodes into this+0x2474/0x2478 via FUN_00404ef0 (called from
       FUN_00461010); FUN_00461010 clears this+0x2488 = 0 after each insertion
       (marks "build order placed"); sets this+0x2480 = waive count.
    """
    own_power = state.albert_power_idx
    power_name = _WIN_DAIDE_POWER_NAMES[own_power] if 0 <= own_power < 7 else 'UNO'

    if not state._id_to_prov:
        state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}
    id_to_prov = state._id_to_prov

    candidates: list = []
    for candidate in state.g_adjustment_build_candidates:
        prov = int(candidate['province'])
        unit_type = str(candidate['unit_type'])
        coast = str(candidate.get('coast', ''))
        key = (prov, unit_type, coast)
        score = float(state.g_adjustment_candidate_scores.get(
            key, state.g_candidate_scores[own_power, prov]))
        # AMY (0x4200) precedes FLT (0x4201) on an otherwise equal C key.
        type_tie = 1 if unit_type == 'AMY' else 0
        candidates.append((score, prov, type_tie, unit_type, coast))

    candidates.sort(reverse=True)
    selected: list[tuple] = []
    selected_provinces: set[int] = set()
    for candidate in candidates:
        prov = int(candidate[1])
        if prov in selected_provinces:
            continue
        selected.append(candidate)
        selected_provinces.add(prov)
        if len(selected) == delta:
            break

    for _, prov, _, unit_type, coast_suffix in selected:
        prov_name = id_to_prov.get(prov, str(prov))
        if unit_type == 'FLT' and coast_suffix:
            prov_name = prov_name + coast_suffix

        state.g_build_order_list.append(f'( {power_name} {unit_type} {prov_name} ) BLD')
        state.g_build_order_list_size += 1

    state.g_waive_count = max(0, delta - len(selected))


def compute_win_removes(state: InnerGameState, delta: int) -> None:
    """Port of FUN_00442040 — select bottom `delta` remove candidates and emit REM orders.

    Called from send_GOF when unit_count > sc_count (REMOVE phase).

    Algorithm:
      1. Collect all provinces in the candidate set (candidate_set_contains).
      2. Sort by g_candidate_scores ascending (lowest strategic value first — remove those first).
         Confirmed by decompile of FUN_00442040: BuildOrderSpec uses score+0x7d
         and the first element popped (lowest) is the one removed.
      3. Take up to `delta` provinces.
      4. Unit type is read directly from unit_info[prov]['type'].
      5. Append '( POWER AMY/FLT PROV ) REM' to state.g_build_order_list.

    C: inserts BST nodes into this+0x2474/0x2478; sets this+0x2488 = 0 (remove flag).
    """
    own_power = state.albert_power_idx
    power_name = _WIN_DAIDE_POWER_NAMES[own_power] if 0 <= own_power < 7 else 'UNO'

    if not state._id_to_prov:
        state._id_to_prov = {v: k for k, v in state.prov_to_id.items()}
    id_to_prov = state._id_to_prov

    candidates: list = []
    for prov in state.g_adjustment_candidate_provinces:
        score = float(state.g_candidate_scores[own_power, prov])
        candidates.append((score, prov))

    candidates.sort()          # ascending: lowest score removed first
    selected = candidates[:delta]

    for _, prov in selected:
        raw_type = state.unit_info[prov].get('type', 'A')
        unit_type = 'FLT' if raw_type == 'F' else 'AMY'
        prov_name = id_to_prov.get(prov, str(prov))
        state.g_build_order_list.append(f'( {power_name} {unit_type} {prov_name} ) REM')
        state.g_build_order_list_size += 1
