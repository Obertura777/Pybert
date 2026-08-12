"""NOW message parser (ParseNOW / ParseNOWUnit from Source/communications/).

Split from communications/inbound.py during the 2026-04 refactor.

Holds the NOW message parser suite:

  * ``parse_now``       — extracts season/year tokens, initialises per-power
                          unit tracking structures, dispatches unit parsing.
  * ``parse_now_unit``  — extracts power, unit type (A/F), province, coast info;
                          writes into ``state.unit_info`` keyed by province ID.

Cross-module deps: ``...state.InnerGameState``.

C References:
  * ParseNOW       = FUN_0045aeb0 (Source/communications/ParseNOW.c)
  * ParseNOWUnit   = FUN_0045af40 (Source/communications/ParseNOWUnit.c)
"""

import logging as _logging

from ...state import InnerGameState
from ...heuristics.win import compute_build_delta
from ..parsers import _extract_top_paren_groups

_log = _logging.getLogger(__name__)

_DAIDE_POWER_NAMES = ["AUS", "ENG", "FRA", "GER", "ITA", "RUS", "TUR"]


def parse_now_unit(state: InnerGameState, unit_tokens: list) -> bool:
    """
    Parse a single unit entry from NOW message.

    Port of ParseNOWUnit (Source/communications/ParseNOWUnit.c).

    Extracts power, unit type (A/F), and province from a unit token list.
    Handles three province/coast encodings:
      - subgroup:       token[2]=='(' → inner ( province coast ) group
                        (C: FUN_004658e0 detects first element of local_b4 is a sub-list)
      - embedded coast: 'SPA/SC'
      - separate token: 'SPA', 'SC' — FLT only (C: else-if FLT branch, lines 164-169)
    Writes the extracted unit info into ``state.unit_info`` keyed by integer
    province ID (via ``state.prov_to_id``).

    The C code writes into two separate ordered-set/map structures:
      - inner+0x2450 (all-powers non-coasted unit set)
      - inner+0x245c (all-powers coasted unit set)
      - inner+0x24b4 / inner+0x24c0 (own-power unit maps, non-coast / coast)
    Python consolidates all four into ``state.unit_info``.

    Args:
        state: InnerGameState; must have ``prov_to_id`` populated by
               ``synchronize_from_game`` before this is called.
        unit_tokens: whitespace-split tokens from one NOW unit group,
                     e.g. ['AUS', 'AMY', 'BUD'] or ['FRA', 'FLT', 'SPA/SC']
                     or ['FRA', 'FLT', 'SPA', 'SC'] or
                     ['ENG', 'FLT', '(', 'LON', 'NC', ')'].

    Returns:
        True if unit parsed and recorded; False on any parse error
        (C breaks out of the outer unit loop on the first error).
    """
    if len(unit_tokens) < 3:
        _log.warning("parse_now_unit: unit_tokens too short: %r", unit_tokens)
        return False

    # --- power (element 0) ---
    # C line 62-66: GetListElement(0) → local_d0; validity check against
    # *(param_1+0x2404) which is g_num_powers.
    power_str = str(unit_tokens[0]).upper()
    if power_str not in _DAIDE_POWER_NAMES:
        _log.warning("parse_now_unit: unknown power %r", power_str)
        return False
    power_idx = _DAIDE_POWER_NAMES.index(power_str)
    num_powers = getattr(state, 'g_num_powers', len(_DAIDE_POWER_NAMES))
    if power_idx >= num_powers:
        _log.warning("parse_now_unit: power_idx %d >= num_powers %d", power_idx, num_powers)
        return False

    # --- unit type (element 1) ---
    unit_type_str = str(unit_tokens[1]).upper()
    if unit_type_str in ('AMY', 'A'):
        unit_type_char = 'A'
    elif unit_type_str in ('FLT', 'F'):
        unit_type_char = 'F'
    else:
        _log.warning("parse_now_unit: invalid unit_type %r", unit_type_str)
        return False

    # --- province + optional coast (element 2, optionally element 3) ---
    # C: GetSubList(2...) → local_b4; FUN_004658e0 tests whether local_b4[0] is a sublist.
    #
    # Encoding 1 — subgroup ( prov coast ):
    #   After _extract_top_paren_groups strips the outer NOW-unit parens, a
    #   DAIDE fleet-at-coast group like "ENG FLT ( LON NC )" is split by
    #   whitespace into ["ENG","FLT","(","LON","NC",")"].  Detect the leading
    #   "(" and collect the inner tokens.
    #   C equivalent: FUN_004658e0(local_b4)==true branch (lines 76-90).
    #
    # Encoding 2 — separate coast token:
    #   "FRA FLT SPA SC" → token[2]="SPA", token[3]="SC".
    #   C equivalent: else-if (FLT == uVar1) branch (lines 164-169).
    #   ONLY valid for FLT — AMY with a 4th token is an error (local_c8=2).
    #
    # Encoding 3 — embedded coast: "FRA FLT SPA/SC" → split on '/'.
    prov_code: str
    coast_suffix: str

    if str(unit_tokens[2]) == '(':
        # Subgroup format: collect tokens until matching ')'.
        inner: list[str] = []
        depth = 1
        j = 3
        while j < len(unit_tokens):
            t = str(unit_tokens[j])
            if t == '(':
                depth += 1
            elif t == ')':
                depth -= 1
                if depth == 0:
                    break
            else:
                inner.append(t.upper())
            j += 1
        if not inner:
            _log.warning("parse_now_unit: empty province sub-group in %r", unit_tokens)
            return False
        prov_code = inner[0]
        coast_suffix = ('/' + inner[1]) if len(inner) >= 2 else ''
        # NOTE: C 5-token ParseDestinationWithCoast loop (ParseNOWUnit lines
        # 122-138) is not implemented; that path handles an extended DAIDE
        # format not seen in standard Standard-map NOW messages.
    elif '/' in str(unit_tokens[2]):
        # Embedded coast: 'SPA/SC'
        prov_code, coast_tag = str(unit_tokens[2]).upper().split('/', 1)
        coast_suffix = '/' + coast_tag
    elif unit_type_char == 'F' and len(unit_tokens) >= 4:
        # C else-if (FLT == uVar1) — separate coast token, FLT only.
        prov_code = str(unit_tokens[2]).upper()
        coast_suffix = '/' + str(unit_tokens[3]).upper()
    else:
        prov_code = str(unit_tokens[2]).upper()
        coast_suffix = ''

    # --- province ID lookup (C uses integer province index; Python mirrors this) ---
    prov_to_id = getattr(state, 'prov_to_id', None)
    if not prov_to_id:
        _log.warning("parse_now_unit: prov_to_id not populated (synchronize_from_game not called?)")
        return False
    prov_id = prov_to_id.get(prov_code, -1)
    if prov_id < 0:
        _log.warning("parse_now_unit: unknown province %r", prov_code)
        return False

    # --- duplicate province check ---
    # C: AdjacencyList_LowerBound + if (local_cc[1] == local_90) → local_c8 = 2.
    if prov_id in state.unit_info:
        _log.warning("parse_now_unit: duplicate province %r (id=%d)", prov_code, prov_id)
        return False

    # --- write into state.unit_info (C: UnitList_FindOrInsert at inner+0x2450/0x245c) ---
    state.unit_info[prov_id] = {
        'power': power_idx,
        'type': unit_type_char,
        'coast': coast_suffix,
    }

    _log.debug(
        "parse_now_unit: power=%s(%d) type=%s prov=%s(id=%d) coast=%r",
        power_str, power_idx, unit_type_char, prov_code, prov_id, coast_suffix,
    )
    return True


def parse_now(state: InnerGameState, message: str) -> bool:
    """
    Parse NOW (current game state snapshot) message.

    Port of ParseNOW (Source/communications/ParseNOW.c).

    Extracts season token and year from NOW message header.  Before parsing
    units it explicitly clears all per-turn unit snapshot structures (C clears
    six separate data structures; Python consolidates them):

      - ``state.unit_info``               ← C inner+0x2450 / +0x245c ordered sets
      - ``state.g_build_order_list``      ← C inner+0x2478 BST
      - ``state.g_build_order_list_size`` ← C inner+0x247c BST size
      - ``state.g_waive_count``           ← C inner+0x2480

    After all units are parsed, performs the WIN-season post-processing from
    C ParseNOW lines 122-172: finds own-power units occupying enemy home SCs
    and records them in ``state.g_enemy_home_occupied`` (Python equivalent of
    the C ordered set / map at inner+0x2450 / inner+0x24cc that inner+0x24cc
    has no known reader per SetOwnPower.c analysis, so functional impact is
    informational only).

    NOW message format:
      NOW ( season ) ( year ) ( unit1 ) ( unit2 ) ... ( unitN )

    Example:
      NOW ( SUM ) ( 1901 ) ( AUS A BUD ) ( ENG F LON )

    Error recovery: C stops processing remaining units at the first
    ParseNOWUnit failure (SEH-based break-on-exception).  Python mirrors this
    by returning False immediately instead of continuing.

    Args:
        state: InnerGameState to populate with unit info
        message: raw NOW message string

    Returns:
        True if parse successful, False on error
    """
    # Extract top-level paren groups: groups[0]=season, [1]=year, [2:]=units
    groups = _extract_top_paren_groups(message)
    if len(groups) < 2:
        _log.warning("parse_now: message too short: %r", message[:100])
        return False

    season_str = groups[0].strip()
    year_str   = groups[1].strip()

    valid_seasons = ['SPR', 'SUM', 'FAL', 'AUT', 'WIN']
    if season_str not in valid_seasons:
        _log.warning("parse_now: invalid season %r", season_str)
        return False

    try:
        year = int(year_str)
    except ValueError:
        _log.warning("parse_now: invalid year %r", year_str)
        return False

    state.g_season = season_str
    state.g_year   = year
    _log.debug("parse_now: season=%s year=%d", season_str, year)

    # --- Explicit list-clearing (C ParseNOW lines 69-99) ---
    # C clears six linked-list / BST structures before repopulating from the
    # incoming NOW snapshot.  Python equivalents:
    state.unit_info.clear()                # inner+0x2450 (all-unit ordered set)
                                           # inner+0x245c (coasted-unit ordered set)
                                           # inner+0x24b4 (own-power non-coast map)
                                           # inner+0x24c0 (own-power coast map)
    state.g_build_order_list      = []     # inner+0x2478 (WIN build BST)
    state.g_build_order_list_size = 0      # inner+0x247c
    state.g_waive_count           = 0      # inner+0x2480

    # --- Parse each unit entry (groups[2:]) ---
    for i, unit_group in enumerate(groups[2:]):
        unit_tokens = unit_group.split()
        if not unit_tokens:
            continue

        success = parse_now_unit(state, unit_tokens)
        if not success:
            # C breaks out of the unit loop on first ParseNOWUnit error.
            _log.warning("parse_now: parse_now_unit failed at index %d: %r", i, unit_group)
            return False

    _log.info("parse_now: parsed %d units (season=%s year=%d)",
              len(state.unit_info), season_str, year)

    # --- WIN-season post-processing (C ParseNOW lines 122-172) ---
    # C line 122-123: if season==WIN, call ComputeBuildDelta (FUN_0040ab10)
    # which stamps province[p]+0x20 with unit-holder token for every unit.
    # C lines 125-168: iterate inner+0x243c (enemy home SCs from SetOwnPower),
    # checking province[p]+0x20 == own_power_token; insert matching provinces
    # into the ordered set at +0x2450 and map at +0x24cc (g_enemy_home_occupied).
    # Python: compute_build_delta stamps g_sc_owner (equivalent of +0x20 field);
    # home_centers supplies enemy home SCs (from handle_mdf+hlo_dispatch or
    # synchronize_from_game — same set as SetOwnPower's +0x243c map).
    if season_str == 'WIN' and getattr(state, 'g_hlo_received', False):
        own_power = getattr(state, 'albert_power_idx', -1)
        # Mirror C line 122-123: ComputeBuildDelta before enemy-home-SC loop.
        compute_build_delta(state)
        home_centers = getattr(state, 'home_centers', {}) or {}
        if own_power >= 0 and not home_centers:
            _log.warning("parse_now: WIN season but home_centers empty — "
                         "synchronize_from_game or handle_mdf+hlo_dispatch not called; "
                         "g_enemy_home_occupied will be empty")
        if own_power >= 0 and home_centers:
            enemy_home_scs = frozenset(
                p
                for pid, provs in home_centers.items()
                if pid != own_power
                for p in provs
            )
            # C inner+0x24cc: enemy home SCs where province[p]+0x20 == own_power_token.
            # g_sc_owner[prov] is the Python equivalent of that stamped field.
            state.g_enemy_home_occupied = frozenset(
                prov
                for prov in enemy_home_scs
                if prov < 256 and state.g_sc_owner[prov] == own_power
            )
            if state.g_enemy_home_occupied:
                _log.debug(
                    "parse_now: own power(%d) occupies %d enemy home SC(s): %r",
                    own_power, len(state.g_enemy_home_occupied),
                    sorted(state.g_enemy_home_occupied),
                )

    return True
