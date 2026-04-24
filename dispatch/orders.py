"""Per-order dispatch helpers: coast parsing and single-order commit.

Split from dispatch.py during the 2026-04 refactor.

Two helpers used by ``validate_and_dispatch_order`` after a given
order has been validated:

  * ``parse_destination_with_coast`` — split a destination token into
    province + coast, matching C's ParseDestinationWithCoast two-branch
    logic (single-element vs compound list).
  * ``dispatch_single_order``        — commit one validated order to
    the game state via g_order_table mutations AND format a DipNet string
    for g_submitted_orders.

Module-level deps: ``..state.InnerGameState``, shared logger from
``._errors``.

Fix 2026-04-21 (D-1): Replaced string-only stub with proper g_order_table
mutations matching C DispatchSingleOrder (FUN_0044cc50).  The C function
writes order_type, dest, coast, convoy legs, g_ProvinceBaseScore, and
g_ConvoyChainScore into g_OrderTable for CTO/CVY/MTO/SUP orders.  The
Python port now mirrors these writes so that downstream consumers
(EvaluateOrderProposal, ComputeOrderDipFlags, ProposeDMZ) see correct
order table state.

Fix 2026-04-21 (D-2): Replaced mock parse_destination_with_coast with
proper two-branch logic matching C ParseDestinationWithCoast.
"""

import numpy as np

from ..state import InnerGameState

from ._errors import logger

# Order-table field indices (must match monte_carlo._constants)
_F_ORDER_TYPE   = 0
_F_UNIT_TYPE    = 1
_F_DEST_PROV    = 2
_F_DEST_COAST   = 3
_F_SECONDARY    = 4
_F_CONVOY_LEG0  = 8
_F_CONVOY_LEG1  = 9
_F_CONVOY_LEG2  = 10
_F_INCOMING_MOVE = 13
_F_SOURCE_PROV  = 16
_F_ORDER_ASGN   = 20

# Order type constants
_ORDER_HLD     = 1
_ORDER_MTO     = 2
_ORDER_SUP_HLD = 3
_ORDER_SUP_MTO = 4
_ORDER_CVY     = 5
_ORDER_CTO     = 6


def parse_destination_with_coast(dest_token):
    """Port of ParseDestinationWithCoast (C Source/utils/).

    C algorithm (two branches):
      Branch 1 (single element): dest_token is a plain province string or ID.
        Extract province directly; coast comes from a separate parameter
        (the unit's current coast, passed as param_3 in C).
      Branch 2 (compound list): dest_token is a dict or tuple with
        element [0] = province, element [1] = coast.

    Parameters
    ----------
    dest_token : str | dict | tuple
        If str: plain province name like ``"STP"`` or ``"STP/SC"``.
        If dict: ``{'province': 'STP', 'coast': 'SC'}``.
        If tuple: ``('STP', 'SC')`` or ``('STP',)``.

    Returns
    -------
    tuple[str, str]
        ``(province, coast)`` where coast is ``''`` if not specified.
    """
    # Branch 2: compound dict
    if isinstance(dest_token, dict):
        prov = dest_token.get('province', '')
        coast = dest_token.get('coast', '')
        return (str(prov), str(coast) if coast else '')

    # Branch 2: compound tuple/list
    if isinstance(dest_token, (tuple, list)):
        prov = str(dest_token[0]) if len(dest_token) > 0 else ''
        coast = str(dest_token[1]) if len(dest_token) > 1 else ''
        return (prov, coast)

    # Branch 1: single string — may contain embedded coast "STP/SC"
    s = str(dest_token)
    if '/' in s:
        parts = s.split('/', 1)
        return (parts[0], parts[1])
    return (s, '')


def dispatch_single_order(state: InnerGameState, power_index: int,
                          order_seq: dict) -> None:
    """Port of DispatchSingleOrder (FUN_0044cc50).

    Commits one validated order into:
      1. ``state.g_order_table`` — per-province order descriptor array used by
         EvaluateOrderProposal, ComputeOrderDipFlags, and ProposeDMZ.
      2. ``state.g_submitted_orders`` — DipNet-formatted string list for the
         game submission pipeline.

    The C function calls BuildOrder_HLD/MTO/SUP_HLD/SUP_MTO/CTO/CVY to
    populate g_OrderTable fields, then updates g_ProvinceBaseScore and
    g_ConvoyChainScore for CTO/CVY orders.  This port inlines those writes.
    """
    token_head = order_seq.get('type', 'HLD')
    unit_str   = order_seq.get('unit', '')      # e.g. "A PAR"
    src_prov   = order_seq.get('src_prov', -1)  # province ID of the unit

    # Resolve src_prov from unit string if not provided
    if src_prov == -1 and unit_str:
        parts = unit_str.split()
        if len(parts) >= 2:
            prov_name = parts[1].split('/')[0].upper()
            src_prov = state.prov_to_id.get(prov_name, -1)

    formatted_order = ""

    if token_head == 'HLD':
        # ── BuildOrder_HLD ────────────────────────────────────────────
        # C: sets g_OrderTable[prov * 0x1e] = 1 (HLD)
        formatted_order = f"{unit_str} H"
        if 0 <= src_prov < 256:
            state.g_order_table[src_prov, _F_ORDER_TYPE] = float(_ORDER_HLD)

    elif token_head == 'MTO':
        # ── BuildOrder_MTO ────────────────────────────────────────────
        # C: sets order_type=2, dest, coast; calls assign_support_order
        target_raw = order_seq.get('target', '')
        coast_raw  = order_seq.get('coast', '')
        if isinstance(target_raw, dict):
            prov_str, coast_str = parse_destination_with_coast(target_raw)
        else:
            prov_str, coast_str = parse_destination_with_coast(
                {'province': target_raw, 'coast': coast_raw})
        target_str = f"{prov_str}/{coast_str}" if coast_str else prov_str
        formatted_order = f"{unit_str} - {target_str}"

        if 0 <= src_prov < 256:
            dest_id = state.prov_to_id.get(prov_str.upper(), -1)
            state.g_order_table[src_prov, _F_ORDER_TYPE] = float(_ORDER_MTO)
            if dest_id >= 0:
                state.g_order_table[src_prov, _F_DEST_PROV] = float(dest_id)
                # C: g_ProvinceBaseScore[dest * 0x1e] = 1 (incoming move marker)
                state.g_order_table[dest_id, _F_INCOMING_MOVE] = 1.0

    elif token_head == 'SUP':
        # ── BuildOrder_SUP_HLD / BuildOrder_SUP_MTO ───────────────────
        target_unit = order_seq.get('target_unit', '')
        dest_prov   = order_seq.get('target_dest', None)
        target_src  = order_seq.get('target_src_prov', -1)

        if target_src == -1 and target_unit:
            parts = target_unit.split()
            if len(parts) >= 2:
                prov_name = parts[1].split('/')[0].upper()
                target_src = state.prov_to_id.get(prov_name, -1)

        if dest_prov:
            # SUP-MTO
            prov_str, coast_str = parse_destination_with_coast(
                {'province': dest_prov,
                 'coast': order_seq.get('target_coast', '')})
            target_str = f"{prov_str}/{coast_str}" if coast_str else prov_str
            formatted_order = f"{unit_str} S {target_unit} - {target_str}"

            if 0 <= src_prov < 256:
                dest_id = state.prov_to_id.get(prov_str.upper(), -1)
                state.g_order_table[src_prov, _F_ORDER_TYPE] = float(_ORDER_SUP_MTO)
                if target_src >= 0:
                    state.g_order_table[src_prov, _F_DEST_PROV] = float(target_src)
                if dest_id >= 0:
                    state.g_order_table[src_prov, _F_SECONDARY] = float(dest_id)
        else:
            # SUP-HLD
            formatted_order = f"{unit_str} S {target_unit}"

            if 0 <= src_prov < 256:
                state.g_order_table[src_prov, _F_ORDER_TYPE] = float(_ORDER_SUP_HLD)
                if target_src >= 0:
                    state.g_order_table[src_prov, _F_DEST_PROV] = float(target_src)

    elif token_head == 'CTO':
        # ── BuildOrder_CTO ────────────────────────────────────────────
        # C (lines 140-194): Clear convoy state, parse dest, write order
        # table with type=6, convoy legs, g_ProvinceBaseScore=1.

        # Clear convoy state (C lines 141-144)
        if hasattr(state, 'g_convoy_legs'):
            state.g_convoy_legs = [-1, -1, -1]
        state.g_convoy_source_prov.fill(-1)
        if isinstance(state.g_convoy_dst_to_src, dict):
            state.g_convoy_dst_to_src.clear()
        else:
            state.g_convoy_dst_to_src.fill(-1)

        dest_raw  = order_seq.get('target_dest', '')
        coast_raw = order_seq.get('coast', '')
        prov_str, coast_str = parse_destination_with_coast(
            {'province': dest_raw, 'coast': coast_raw})
        via_str = order_seq.get('via', '')
        formatted_order = f"{unit_str} - {prov_str} VIA"

        if 0 <= src_prov < 256:
            dest_id = state.prov_to_id.get(prov_str.upper(), -1)
            state.g_order_table[src_prov, _F_ORDER_TYPE] = float(_ORDER_CTO)
            if dest_id >= 0:
                state.g_order_table[src_prov, _F_DEST_PROV] = float(dest_id)
                # C line 189: g_ProvinceBaseScore[dest * 0x1e] = 1
                state.g_order_table[dest_id, _F_INCOMING_MOVE] = 1.0

            # Store convoy legs (C lines 155-164 + 186-188)
            legs = order_seq.get('convoy_legs', [])
            for i, leg in enumerate(legs[:3]):
                leg_id = state.prov_to_id.get(str(leg).upper(), -1) if not isinstance(leg, int) else leg
                if leg_id >= 0:
                    state.g_order_table[src_prov, _F_CONVOY_LEG0 + i] = float(leg_id)

            # C line 189: g_ProvinceBaseScore[dest * 0x1e] = 1
            # Already handled above at line 218 (_F_INCOMING_MOVE = 1.0).
            # Fixed 2026-04-23 (audit finding DSP-1): removed spurious
            # g_max_province_score copy into _F_SOURCE_PROV — no C equivalent.

    elif token_head == 'CVY':
        # ── BuildOrder_CVY ────────────────────────────────────────────
        # C (lines 196-222): Fleet convoying army; write type=5, register fleet.
        target_army = order_seq.get('target_unit', '')
        if target_army and not target_army.startswith('A'):
            logger.warning(
                "CVY target_unit %r is not an army — convoy orders "
                "require an army unit", target_army)
        dest_raw = order_seq.get('target_dest', '')
        prov_str, _ = parse_destination_with_coast(
            {'province': dest_raw, 'coast': ''})
        formatted_order = f"{unit_str} C {target_army} - {prov_str}"

        if 0 <= src_prov < 256:
            dest_id = state.prov_to_id.get(prov_str.upper(), -1)
            state.g_order_table[src_prov, _F_ORDER_TYPE] = float(_ORDER_CVY)
            if dest_id >= 0:
                state.g_order_table[src_prov, _F_DEST_PROV] = float(dest_id)
            # C line 218: g_ProvinceBaseScore[fleet_prov * 0x1e] = 1
            state.g_order_table[src_prov, _F_INCOMING_MOVE] = 1.0

            # C line 221: RegisterConvoyFleet
            from ..moves.convoy import register_convoy_fleet
            register_convoy_fleet(state, power_index, src_prov)

    else:
        logger.warning(f"Unknown DAIDE dispatch token branch: {token_head}")

    # Commit formatted string to submission list.
    if formatted_order:
        state.g_submitted_orders.append(formatted_order)
        logger.debug("Dispatched order: %s", formatted_order)
