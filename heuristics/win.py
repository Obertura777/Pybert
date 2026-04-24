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
# SPR/FAL movement-phase weights.  C stores these at Albert+0x4d38 (SPR/SUM)
# and Albert+0x4d98 (FAL/AUT) as 10 int64 values.  The Python
# get_candidate_score always returns the same value regardless of iteration
# index (simplified fallback), so the individual weights don't matter as
# much as their relative scale.  Values below are inferred from the WIN
# weight patterns and the C binary's tournament-calibrated defaults.
_SPR_FAL_WEIGHTS: list = [100, 80, 60, 40, 20, 10, 5, 3, 2, 1]

# DAIDE short power names (index matches power_idx 0-6: AUS…TUR).
_WIN_DAIDE_POWER_NAMES: list = ['AUS', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR']


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

    Baseline score 1.0 marks membership; score_order_candidates_own_power
    will overwrite with the weighted dot-product in Pass 1.

    C: candidate set lives at Albert+own_power*0x78+0x361c; count stored at
    Albert+0x4e50; limit (delta) at Albert+0x4e54.
    """
    state.g_candidate_scores[own_power].fill(0.0)
    home_provs = state.home_centers.get(own_power, frozenset())
    for prov in home_provs:
        if state.g_sc_ownership[own_power, prov] == 1 and prov not in state.unit_info:
            state.g_candidate_scores[own_power, prov] = 1.0


def populate_remove_candidates(state: InnerGameState, own_power: int) -> None:
    """Seed g_candidate_scores[own_power] with eligible WIN remove provinces.

    Mirrors FUN_0040ab10 for the REMOVE branch (unit_count > sc_count).
    Every province that holds an own unit is a candidate.

    C: candidate set lives at Albert+own_power*0x78+0x361c; count at
    Albert+0x4df8; limit (delta) at Albert+0x4dfc.
    """
    state.g_candidate_scores[own_power].fill(0.0)
    for prov, unit_data in state.unit_info.items():
        if unit_data.get('power') == own_power:
            state.g_candidate_scores[own_power, prov] = 1.0


def compute_win_builds(state: InnerGameState, delta: int) -> None:
    """Port of FUN_00442040 — select top `delta` build candidates and emit BLD orders.

    Called from send_GOF when unit_count < sc_count (BUILD phase).

    Algorithm:
      1. Collect all provinces where g_candidate_scores[own_power, prov] > 0.
      2. Sort by score descending (highest strategic value first).
      3. Take up to `delta` provinces; any shortfall becomes waives.
      4. For each selected province determine unit type:
           FLT — if province is coastal (any adjacent province is a water province).
           AMY — otherwise (inland).
         Type-determination chain (confirmed by FUN_00461010 decompile):
           FUN_00442040 outer loop calls UnitList_FindOrInsert(inner+0x2450, prov)
           which creates the unit record and sets type at node+20 based on province
           coastal status.  FUN_00461010 then finds that record, reads the type
           from node+0x14 (+20), and inserts {prov_ptr, type, 0} into the build
           BST at inner+0x2474 via FUN_00404ef0.  The coastal heuristic below
           mirrors UnitList_FindOrInsert's initialization logic.
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
    for prov in range(256):
        score = float(state.g_candidate_scores[own_power, prov])
        if score > 0.0:
            candidates.append((score, prov))

    candidates.sort(reverse=True)
    selected = candidates[:delta]

    for _, prov in selected:
        is_coastal = any(adj in state.water_provinces
                         for adj in state.adj_matrix.get(prov, []))
        unit_type = 'FLT' if is_coastal else 'AMY'
        prov_name = id_to_prov.get(prov, str(prov))
        state.g_build_order_list.append(f'( {power_name} {unit_type} {prov_name} ) BLD')

    state.g_waive_count = max(0, delta - len(selected))


def compute_win_removes(state: InnerGameState, delta: int) -> None:
    """Port of FUN_0044bd40 — select bottom `delta` remove candidates and emit REM orders.

    Called from send_GOF when unit_count > sc_count (REMOVE phase).

    Algorithm:
      1. Collect all own-unit provinces where g_candidate_scores[own_power, prov] > 0.
      2. Sort by score ascending (lowest strategic value first — remove those first).
         Confirmed by decompile of FUN_0044bd40: BuildOrderSpec uses score+0x7d
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
    for prov, unit_data in state.unit_info.items():
        if unit_data.get('power') != own_power:
            continue
        score = float(state.g_candidate_scores[own_power, prov])
        if score > 0.0:
            candidates.append((score, prov))

    candidates.sort()          # ascending: lowest score removed first
    selected = candidates[:delta]

    for _, prov in selected:
        raw_type = state.unit_info[prov].get('type', 'A')
        unit_type = 'FLT' if raw_type == 'F' else 'AMY'
        prov_name = id_to_prov.get(prov, str(prov))
        state.g_build_order_list.append(f'( {power_name} {unit_type} {prov_name} ) REM')
