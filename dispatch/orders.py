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

from ..state import InnerGameState

from ._errors import logger

# Order-table field indices and order-type codes.
# Imported from the canonical definitions rather than redeclared: this module
# previously defined _F_SECONDARY = 4, which collided with _F_HOLD_WEIGHT and
# disagreed with moves/_constants.py and monte_carlo/_flags.py (both 1).
from ..moves._constants import (  # noqa: E402
    _F_ORDER_TYPE,
    _F_SECONDARY,
    _F_DEST_PROV,
    _F_DEST_COAST,
    _F_CONVOY_LEG0,
    _F_CONVOY_LO,
    _F_CONVOY_HI,
    _F_CONVOY_DEPTH,
    _F_INCOMING_MOVE,
    _F_THREAT_TOTAL,
    _F_ORDER_ASGN,
    _ORDER_MTO,
    _ORDER_CVY,
    _ORDER_CTO,
    _UNIT_TOKEN_AMY,
    _unit_location_token,
)

_F_CONVOY_LEG1  = _F_CONVOY_LEG0 + 1
_F_CONVOY_LEG2  = _F_CONVOY_LEG0 + 2
_F_MOVE_HISTORY = 17
_F_FLEET_SCORE  = 24
_F_FLEET_SCORE_HI = 25
_ORDER_HLD      = 1

def _destination_score(
    state: InnerGameState,
    power: int,
    province: int,
    unit_type: str,
    coast: str = '',
) -> float:
    """Read the token-keyed final score used by the C order builders."""
    if unit_type not in ('F', 'FLT'):
        return float(state.final_score_set[power, province])
    if coast:
        if not state._id_to_prov:
            state._id_to_prov = {
                pid: name for name, pid in state.prov_to_id.items()
            }
        base = state._id_to_prov.get(province, '').split('/')[0]
        variant = state.prov_to_id.get(
            base + '/' + str(coast).upper().lstrip('/')
        )
        if variant is not None:
            return float(state.final_score_set_flt[power, variant])
    return float(state.final_score_set_flt[power, province])


def _register_convoy_destination(
    state: InnerGameState,
    destination: int,
    source: int,
) -> None:
    """Mirror ConvoyList_Insert(DAT_00bb65a0, destination)."""
    if destination not in state.g_convoy_dst_list:
        state.g_convoy_dst_list.append(destination)
    state.g_convoy_dst_to_src[destination] = source


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


def _format_order_seq(order_seq: dict) -> str:
    """Format an already-built order without mutating its C order record."""
    order_type = order_seq.get('type', '')
    unit = order_seq.get('unit', '')
    if order_type == 'HLD':
        return f"{unit} H"
    if order_type == 'MTO':
        province, parsed_coast = parse_destination_with_coast(
            order_seq.get('target', '')
        )
        coast = str(order_seq.get('coast', '') or parsed_coast)
        target = f"{province}/{coast}" if coast else province
        return f"{unit} - {target}"
    if order_type == 'SUP':
        supported = order_seq.get('target_unit', '')
        destination = order_seq.get('target_dest')
        if not destination:
            return f"{unit} S {supported}"
        province, parsed_coast = parse_destination_with_coast(destination)
        coast = str(order_seq.get('target_coast', '') or parsed_coast)
        target = f"{province}/{coast}" if coast else province
        return f"{unit} S {supported} - {target}"
    if order_type == 'CTO':
        province, _ = parse_destination_with_coast(
            order_seq.get('target_dest', '')
        )
        return f"{unit} - {province} VIA"
    if order_type == 'CVY':
        province, _ = parse_destination_with_coast(
            order_seq.get('target_dest', '')
        )
        return f"{unit} C {order_seq.get('target_unit', '')} - {province}"
    return ''


def dispatch_single_order(
    state: InnerGameState,
    power_index: int,
    order_seq: dict,
    *,
    format_existing: bool = False,
    record_submission: bool = True,
) -> None:
    """Port of DispatchSingleOrder (FUN_0044cc50).

    Commits one validated order into:
      1. ``state.g_order_table`` — per-province order descriptor array used by
         EvaluateOrderProposal, ComputeOrderDipFlags, and ProposeDMZ.
      2. Optionally, ``state.g_submitted_orders`` — DipNet-formatted string
         list for the game submission pipeline.  ProcessTurn uses
         ``record_submission=False`` because C dispatches negotiated orders
         into its per-trial table without submitting them once per trial.

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

    # DispatchSingleOrder.c commits only while the unit record's order field
    # (ppiVar8[4], node +0x20) is zero. All BuildOrder_* callees write that
    # same field; a second order for one source is therefore a successful
    # no-op rather than an overwrite or an additional submitted string.
    if (0 <= src_prov < 256
            and int(state.g_order_table[src_prov, _F_ORDER_TYPE]) != 0):
        if format_existing and record_submission:
            formatted_order = _format_order_seq(order_seq)
            if formatted_order:
                state.g_submitted_orders.append(formatted_order)
                logger.debug("Serialized existing order: %s", formatted_order)
        return

    formatted_order = ""

    if token_head == 'HLD':
        # ── BuildOrder_HLD ────────────────────────────────────────────
        # C: sets g_OrderTable[prov * 0x1e] = 1 (HLD)
        formatted_order = f"{unit_str} H"
        if 0 <= src_prov < 256:
            unit = state.unit_info.get(src_prov, {})
            unit_type = str(unit.get('type', 'A')).upper()
            state.g_order_table[src_prov, _F_ORDER_TYPE] = float(_ORDER_HLD)
            state.g_order_table[src_prov, _F_DEST_PROV] = float(src_prov)
            state.g_order_table[src_prov, _F_DEST_COAST] = float(
                _unit_location_token(unit_type, unit.get('coast', ''))
            )
            state.g_order_table[src_prov, _F_INCOMING_MOVE] = 1.0
            state.g_order_table[src_prov, _F_CONVOY_LO] = _destination_score(
                state, power_index, src_prov, unit_type,
                str(unit.get('coast', '')),
            )
            state.g_order_table[src_prov, _F_CONVOY_HI] = 0.0
            if unit_type in ('A', 'AMY'):
                state.g_order_table[src_prov, _F_FLEET_SCORE] = 0.0
                state.g_order_table[src_prov, _F_FLEET_SCORE_HI] = 0.0
            from ..moves.convoy import register_convoy_fleet
            register_convoy_fleet(state, power_index, src_prov)

    elif token_head == 'MTO':
        # ── BuildOrder_MTO ────────────────────────────────────────────
        # C: sets order_type=2, dest, coast; calls assign_support_order
        target_raw = order_seq.get('target', '')
        coast_raw  = order_seq.get('coast', '')
        prov_str, parsed_coast = parse_destination_with_coast(target_raw)
        coast_str = str(coast_raw or parsed_coast)
        target_str = f"{prov_str}/{coast_str}" if coast_str else prov_str
        formatted_order = f"{unit_str} - {target_str}"

        if 0 <= src_prov < 256:
            dest_id = state.prov_to_id.get(prov_str.upper(), -1)
            unit_type = str(
                state.unit_info.get(src_prov, {}).get('type', 'A')
            ).upper()
            location_token = _unit_location_token(unit_type, coast_str)
            state.g_order_table[src_prov, _F_ORDER_TYPE] = float(_ORDER_MTO)
            if dest_id >= 0:
                # DispatchSingleOrder caches the UnitList lookup for the MTO
                # destination immediately before BuildOrder_MTO. The later
                # AssignSupportOrder conflict block reads that occupant's
                # existing order type and destination. A missing unit yields
                # the set end iterator and cannot trigger the block.
                if dest_id in state.unit_info:
                    state.g_last_mto_insert = (
                        int(state.g_order_table[dest_id, _F_ORDER_TYPE]),
                        int(state.g_order_table[dest_id, _F_DEST_PROV]),
                    )
                else:
                    state.g_last_mto_insert = None
                state.g_order_table[src_prov, _F_DEST_PROV] = float(dest_id)
                state.g_order_table[src_prov, _F_DEST_COAST] = float(
                    location_token
                )
                # C: g_ProvinceBaseScore[dest * 0x1e] = 1 (incoming move marker)
                state.g_order_table[dest_id, _F_INCOMING_MOVE] = 1.0
                _register_convoy_destination(state, dest_id, src_prov)
                state.g_order_table[dest_id, _F_CONVOY_LO] = (
                    _destination_score(
                        state, power_index, dest_id, unit_type, coast_str
                    )
                )
                state.g_order_table[dest_id, _F_CONVOY_HI] = 0.0
                state.g_order_table[dest_id, _F_MOVE_HISTORY] = float(
                    state.g_move_history_matrix[
                        power_index, src_prov, dest_id
                    ]
                )
                if unit_type in ('A', 'AMY'):
                    state.g_order_table[dest_id, _F_FLEET_SCORE] = 0.0
                    state.g_order_table[dest_id, _F_FLEET_SCORE_HI] = 0.0
                from ..moves.convoy import register_convoy_fleet
                from ..moves.support import assign_support_order
                register_convoy_fleet(state, power_index, dest_id)
                assign_support_order(
                    state, power_index, src_prov, dest_id,
                    location_token,
                )

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
            prov_str, parsed_coast = parse_destination_with_coast(dest_prov)
            coast_str = str(
                order_seq.get('target_coast', '') or parsed_coast
            )
            target_str = f"{prov_str}/{coast_str}" if coast_str else prov_str
            formatted_order = f"{unit_str} S {target_unit} - {target_str}"
            dest_id = state.prov_to_id.get(prov_str.upper(), -1)
            if (0 <= src_prov < 256
                    and target_src >= 0
                    and dest_id >= 0):
                from ..moves.support import build_order_sup_mto
                build_order_sup_mto(
                    state, power_index, src_prov, target_src, dest_id
                )
        else:
            # SUP-HLD
            formatted_order = f"{unit_str} S {target_unit}"

            if 0 <= src_prov < 256 and target_src >= 0:
                from ..moves.support import build_order_sup_hld
                build_order_sup_hld(
                    state, power_index, src_prov, target_src
                )

    elif token_head == 'CTO':
        # ── BuildOrder_CTO ────────────────────────────────────────────
        # C (lines 140-194): Clear convoy state, parse dest, write order
        # table with type=6, convoy legs, g_ProvinceBaseScore=1.

        # C:144 calls ClearConvoyState(), which is a no-op — Source/utils/clear.c
        # is `void ClearConvoyState(void) { return; }`; it is the
        # eh_vector_ctor/dtor_iterator callback, which is why it appears at
        # nearly every basic-block boundary in the decompile.  This used to wipe
        # g_convoy_source_prov and g_convoy_dst_to_src.  g_convoy_dst_to_src IS
        # C's DAT_00bb65a0, built by ConvoyList_Insert (BuildOrder_MTO.c:23,
        # BuildConvoyOrders.c:28, DispatchSingleOrder.c:179) and read at
        # ProcessTurn.c:2493/2697 to decide SUP_MTO, so clearing it here
        # discarded every earlier move registration.

        dest_raw  = order_seq.get('target_dest', '')
        coast_raw = order_seq.get('coast', '')
        prov_str, parsed_coast = parse_destination_with_coast(dest_raw)
        coast_str = str(coast_raw or parsed_coast)
        legs = list(order_seq.get('convoy_legs', []))
        # DispatchSingleOrder.c commits CTO only when TokenSeq_Count(via) < 4.
        if len(legs) >= 4:
            return
        formatted_order = f"{unit_str} - {prov_str} VIA"

        if 0 <= src_prov < 256:
            dest_id = state.prov_to_id.get(prov_str.upper(), -1)
            state.g_order_table[src_prov, _F_ORDER_TYPE] = float(_ORDER_CTO)
            if dest_id >= 0:
                state.g_order_table[src_prov, _F_DEST_PROV] = float(dest_id)
                state.g_order_table[src_prov, _F_DEST_COAST] = float(
                    _UNIT_TOKEN_AMY
                )
                # C line 189: g_ProvinceBaseScore[dest * 0x1e] = 1
                state.g_order_table[dest_id, _F_INCOMING_MOVE] = 1.0
                _register_convoy_destination(state, dest_id, src_prov)
                state.g_order_table[dest_id, _F_CONVOY_LO] = (
                    _destination_score(
                        state, power_index, dest_id, 'A', coast_str
                    )
                )
                state.g_order_table[dest_id, _F_CONVOY_HI] = 0.0

            # Store convoy legs (C lines 155-164 + 186-188)
            state.g_order_table[src_prov, _F_CONVOY_DEPTH] = float(
                len(legs)
            )
            for i, leg in enumerate(legs[:3]):
                leg_id = state.prov_to_id.get(str(leg).upper(), -1) if not isinstance(leg, int) else leg
                if leg_id >= 0:
                    state.g_order_table[src_prov, _F_CONVOY_LEG0 + i] = float(leg_id)

            # C line 189: g_ProvinceBaseScore[dest * 0x1e] = 1
            # Already handled above at line 218 (_F_INCOMING_MOVE = 1.0).
            # Fixed 2026-04-23 (audit finding DSP-1): removed spurious
            # g_max_province_score copy into _F_THREAT_TOTAL — no C equivalent.

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
            target_parts = target_army.split()
            army_source = -1
            if len(target_parts) >= 2:
                army_source = state.prov_to_id.get(
                    target_parts[1].split('/')[0].upper(), -1
                )
            if army_source >= 0:
                state.g_order_table[src_prov, _F_SECONDARY] = float(
                    army_source
                )
            if dest_id >= 0:
                state.g_order_table[src_prov, _F_DEST_PROV] = float(dest_id)
            state.g_order_table[src_prov, _F_DEST_COAST] = float(
                _UNIT_TOKEN_AMY
            )
            # C line 218: g_ProvinceBaseScore[fleet_prov * 0x1e] = 1
            state.g_order_table[src_prov, _F_INCOMING_MOVE] = 1.0
            state.g_order_table[src_prov, _F_CONVOY_LO] = float(
                state.g_max_prov_score_per_power[power_index, src_prov]
            )
            state.g_order_table[src_prov, _F_CONVOY_HI] = 0.0

            # C line 221: RegisterConvoyFleet
            from ..moves.convoy import register_convoy_fleet
            register_convoy_fleet(state, power_index, src_prov)

    else:
        logger.warning(f"Unknown DAIDE dispatch token branch: {token_head}")

    # Commit formatted string to submission list.
    if formatted_order and record_submission:
        state.g_submitted_orders.append(formatted_order)
        logger.debug("Dispatched order: %s", formatted_order)
