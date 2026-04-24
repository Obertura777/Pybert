"""NOW message parser (ParseNOW / ParseNOWUnit from Source/communications/).

Split from communications/inbound.py during the 2026-04 refactor.

Holds the NOW message parser suite:

  * ``parse_now``       — extracts season/year tokens, initializes per-power
                          alliance order trees, dispatches unit parsing.
  * ``parse_now_unit``  — extracts power, unit type (A/F), province, coast info;
                          inserts into per-power alliance order tracking.

Cross-module deps: ``...state.InnerGameState``.

C References:
  * ParseNOW       = FUN_0045aeb0 (Source/communications/ParseNOW.c)
  * ParseNOWUnit   = FUN_0045af40 (Source/communications/ParseNOWUnit.c)
"""

from ...state import InnerGameState
from ..parsers import _extract_top_paren_groups, _split_top_level_groups


def parse_now_unit(state: InnerGameState, unit_tokens: list) -> bool:
    """
    Parse a single unit entry from NOW message.

    Port of ParseNOWUnit (Source/communications/ParseNOWUnit.c).

    Extracts power, unit type (A/F), and province from a unit token list.
    For 5-element units, handles coast info (V/O suffix on province).
    Inserts the extracted unit info into per-power alliance order tracking
    (state.g_order_list, indexed by power).

    Args:
        state: InnerGameState with per-power order lists
        unit_tokens: list of tokens from a NOW unit entry

    Returns:
        True if unit parsed successfully, False if parse error
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    # Initialize g_order_list if not present (lazy init).
    if not hasattr(state, 'g_order_list'):
        state.g_order_list = [[] for _ in range(7)]

    # NOW unit format: ( power unit_type province [coast] )
    # power: 'AUS'|'ENG'|'FRA'|'GER'|'ITA'|'RUS'|'TUR'
    # unit_type: 'A'|'F'
    # province: 3-letter code, optionally with coast suffix (V/O)
    # Example: ( FRA F MAR )  — French fleet in Marseille
    # Example: ( FRA A SPA/SC ) — French army in Spain/south coast

    if len(unit_tokens) < 3:
        _log.warning("parse_now_unit: unit_tokens too short: %r", unit_tokens)
        return False

    # Extract power index
    daide_names = ["AUS", "ENG", "FRA", "GER", "ITA", "RUS", "TUR"]
    power_str = str(unit_tokens[0]).upper()
    if power_str not in daide_names:
        _log.warning("parse_now_unit: unknown power %r", power_str)
        return False
    power_idx = daide_names.index(power_str)

    # Extract unit type
    unit_type_str = str(unit_tokens[1]).upper()
    if unit_type_str not in ('A', 'F'):
        _log.warning("parse_now_unit: invalid unit_type %r", unit_type_str)
        return False
    unit_type = 0 if unit_type_str == 'A' else 1  # 0=Army, 1=Fleet

    # Extract province (may have coast suffix)
    prov_str = str(unit_tokens[2]).upper()
    # Handle coast suffix: "MAR/SC" → split on '/'
    if '/' in prov_str:
        prov_code = prov_str.split('/')[0]
        coast_code = prov_str.split('/')[1] if len(prov_str.split('/')) > 1 else None
    else:
        prov_code = prov_str
        coast_code = None

    # C code stores unit info as a record in g_order_list[power]
    # Record format: {'power': int, 'unit_type': int, 'province': str, 'coast': str}
    unit_record = {
        'power': power_idx,
        'unit_type': unit_type,
        'province': prov_code,
        'coast': coast_code,
    }

    # Append to per-power order list
    state.g_order_list[power_idx].append(unit_record)

    _log.debug(
        "parse_now_unit: power=%s(%d) unit_type=%s prov=%s coast=%s",
        power_str, power_idx, unit_type_str, prov_code, coast_code,
    )

    return True


def parse_now(state: InnerGameState, message: str) -> bool:
    """
    Parse NOW (current game state snapshot) message.

    Port of ParseNOW (Source/communications/ParseNOW.c).

    Extracts season token and year from NOW message header, then initializes
    per-power alliance order tracking lists and parses each unit entry via
    parse_now_unit().

    NOW message format:
      NOW ( season ) ( year ) ( unit1 ) ( unit2 ) ... ( unitN )

    Example:
      NOW ( SUM ) ( 1901 ) ( AUS A BUD ) ( ENG F LON )

    Args:
        state: InnerGameState to populate with unit info
        message: raw NOW message string

    Returns:
        True if parse successful, False on error
    """
    import logging as _logging
    _log = _logging.getLogger(__name__)

    # Extract top-level paren groups: NOW token + groups
    groups = _extract_top_paren_groups(message)
    if len(groups) < 2:
        _log.warning("parse_now: message too short: %r", message[:100])
        return False

    # groups[0] = season, groups[1] = year, groups[2:] = units
    season_str = groups[0].strip()
    year_str = groups[1].strip()

    # Validate season token
    valid_seasons = ['SPR', 'SUM', 'FAL', 'AUT', 'WIN']
    if season_str not in valid_seasons:
        _log.warning("parse_now: invalid season %r", season_str)
        return False

    # Parse year (should be int)
    try:
        year = int(year_str)
    except ValueError:
        _log.warning("parse_now: invalid year %r", year_str)
        return False

    # Store turn info in state
    state.g_season = season_str
    state.g_year = year

    _log.debug("parse_now: season=%s year=%d", season_str, year)

    # Initialize per-power order lists (clear any prior NOW snapshot)
    state.g_order_list = [[] for _ in range(7)]

    # Parse each unit entry (groups[2:])
    for i, unit_group in enumerate(groups[2:]):
        # unit_group is e.g. "AUS A BUD" or "ENG F LON"
        unit_tokens = unit_group.split()
        if not unit_tokens:
            continue

        success = parse_now_unit(state, unit_tokens)
        if not success:
            _log.warning("parse_now: parse_now_unit failed at index %d: %r", i, unit_group)
            # Continue parsing remaining units despite error
            continue

    _log.info("parse_now: parsed %d units from NOW message", sum(len(lst) for lst in state.g_order_list))
    return True
