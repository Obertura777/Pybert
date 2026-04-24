"""Main order-dispatch entry point.

Split from dispatch.py during the 2026-04 refactor.

Holds ``validate_and_dispatch_order`` — port of ``FUN_00422a90``.
This is the public entry point consumed by ``albert.bot`` and the
inbound-press pipeline: it validates an incoming order across the
alliance/legality/convoy gates and, on success, commits it via
``dispatch_single_order``.

Module-level deps:
  * ``..state.InnerGameState`` for the game-state object.
  * ``.alliance.check_order_alliance`` for the alliance-family gate.
  * ``.legality._is_legal_mto`` / ``.legality.is_convoy_reachable`` for
    the adjacency + convoy-reach predicates.
  * ``.orders.dispatch_single_order`` for the commit step.
  * Dispatch-family error sentinels and shared logger from ``._errors``.
"""

from ..state import InnerGameState

from ._errors import (
    logger,
    _ERR_MALFORMED_UNIT,
    _ERR_BAD_PROVINCE,
    _ERR_POWER_MISMATCH,
    _ERR_NO_TARGET,
    _ERR_ADJACENCY,
    _ERR_NO_SUP_UNIT,
    _ERR_CVY_NO_ARMY,
    _ERR_CVY_REACH,
    _ERR_UNKNOWN_ORDER,
)
from .alliance import check_order_alliance
from .legality import _is_legal_mto, is_convoy_reachable
from .orders import dispatch_single_order

def validate_and_dispatch_order(
    state: InnerGameState,
    own_power_idx: int,
    order_seq: dict,
    commit: bool = True,
) -> int:
    """
    Port of FUN_00422a90 — ValidateAndDispatchDaideOrder.

    ``commit=False`` runs legality + trust scoring (FUN_00422a90 +
    FUN_0041d360) but skips dispatch_single_order, so the order is
    *evaluated* without being executed. Used by the FUN_00426140
    legitimacy gate, which needs pure scoring over candidate clauses.

    Takes a parsed DAIDE order token sequence (expressed here as the
    dispatch_single_order-compatible dict used throughout the Python rewrite),
    validates it against the current game state, and — if valid — commits it
    by calling dispatch_single_order.

    Mirrors the C control flow faithfully (decompiled.txt lines 69–873):

      Unit validation block (skipped for WVE/BLD — neither appear as valid
      movement orders and both produce _ERR_UNKNOWN_ORDER at the dispatch
      switch, matching the C fall-through to return -0x15f91):
        1. Parse unit string → province name → prov_id via state.prov_to_id.
        2. Look up unit_data in state.unit_info[prov_id].
        3. Check unit_data['power'] == own_power_idx  (C: piStack_84[1] !=
           iStack_48 → return -0x14c09).

      Order-type dispatch:
        HLD → success (C: `if HLD goto LAB_00423fb5`; no check_order_alliance call).
        MTO → target present; _is_legal_mto adjacency gate (FUN_00460b30);
              check_order_alliance (FUN_0041d360) → dispatch_single_order.
        SUP → target_unit present; FUN_004619f0 convoy/legality check
              (ported as is_convoy_reachable); supporter-side adjacency
              check; two check_order_alliance calls for SUP-MTO, one for
              SUP-HLD → dispatch_single_order.
        CTO → target_dest present; FUN_004619f0 (ported as
              is_convoy_reachable); check_order_alliance →
              dispatch_single_order.
        CVY → target_unit (army) validated; FUN_004619f0 convoy reachability
              (army prov → dest); check_order_alliance → dispatch_single_order.
        other → return _ERR_UNKNOWN_ORDER  (C: return -0x15f91).

    Returns 0 on success, negative error code on failure.

    Unchecked callees absorbed here:
      FUN_004619f0  convoy reachability     → ported as is_convoy_reachable (SUP-MTO + CTO + CVY)
    """
    order_type: str = order_seq.get('type', '')
    unit_str:   str = order_seq.get('unit', '')

    # ── Unit existence + power ownership ─────────────────────────────────────
    # C: `if ((WVE != uStack_94) && (BLD != uStack_94))` block, lines 156–238.
    # WVE / BLD have no unit — skip the block for those tokens; they still hit
    # _ERR_UNKNOWN_ORDER at the dispatch switch below.
    if order_type not in ('WVE', 'BLD'):
        # Parse "A PAR" → 'PAR', "F LON/NCS" → 'LON'
        parts = unit_str.split()
        if len(parts) < 2:
            logger.debug("validate_and_dispatch_order: malformed unit string %r", unit_str)
            return _ERR_MALFORMED_UNIT

        prov_raw = parts[1].split('/')[0].upper()
        prov_id  = state.prov_to_id.get(prov_raw)
        if prov_id is None:
            logger.debug("validate_and_dispatch_order: unknown province %r", prov_raw)
            return _ERR_BAD_PROVINCE

        unit_data = state.unit_info.get(prov_id)
        if unit_data is None:
            logger.debug(
                "validate_and_dispatch_order: no unit at province %r (id %d)",
                prov_raw, prov_id,
            )
            return _ERR_MALFORMED_UNIT

        # C: piStack_84[1] != iStack_48 → power mismatch → return -0x14c09
        if unit_data.get('power') != own_power_idx:
            logger.debug(
                "validate_and_dispatch_order: power mismatch at %r: "
                "unit.power=%d own=%d",
                prov_raw, unit_data.get('power'), own_power_idx,
            )
            return _ERR_POWER_MISMATCH

    # ── Order-type dispatch ───────────────────────────────────────────────────
    if order_type == 'HLD':
        # C: `if (HLD == uStack_94) goto LAB_00423fb5` — success, no
        # check_order_alliance call.  HLD has no destination.
        if commit:
            dispatch_single_order(state, own_power_idx, order_seq)
        return 0

    if order_type == 'MTO':
        # C: ParseDestinationWithCoast + FUN_00460b30 adjacency gate (line 293).
        target = order_seq.get('target', '')
        if not target:
            return _ERR_NO_TARGET
        dest_prov_id = state.prov_to_id.get(target.split('/')[0].upper())
        # FUN_00460b30: adjacency / legal-move gate (with unit-type filtering).
        moving_unit_type = unit_data.get('type', '') if unit_data else ''
        if dest_prov_id is None or not _is_legal_mto(state, prov_id, dest_prov_id, moving_unit_type):
            logger.debug(
                "validate_and_dispatch_order: MTO adjacency check failed "
                "%r → %r", prov_raw, target,
            )
            return _ERR_ADJACENCY
        # check_order_alliance (FUN_0041d360): validate alliance constraints on dest.
        dest_power   = state.get_unit_power(dest_prov_id) if dest_prov_id is not None else -1
        if dest_prov_id is not None:
            rc = check_order_alliance(state, own_power_idx, dest_prov_id,
                                      own_power_idx, dest_power)
            if rc != 0:
                return rc
        if commit:
            dispatch_single_order(state, own_power_idx, order_seq)
        return 0

    if order_type == 'SUP':
        # C lines 318–554: supported-unit lookup, FUN_0040dfe0 end-check,
        # IsLegalMove on source, FUN_004619f0 convoy-reachability (ported,
        # not a stub — see is_convoy_reachable above). Two check_order_alliance
        # calls for SUP-MTO (lines 515+537); one via LAB_00423083 for SUP-HLD.
        # Supporter-side adjacency check (was KNOWN GAP; now wired at L489-501):
        #   SUP-MTO: supporter must reach target_dest (plain adjacency).
        #   SUP-HLD: supporter must reach supported unit's province.
        #   Both map to error -0x186c1 / -0x186c3; checked below.
        target_unit = order_seq.get('target_unit', '')
        if not target_unit:
            return _ERR_NO_SUP_UNIT
        # Resolve supported unit's province and type for the is_convoy_reachable call.
        # Resolve dest province: SUP-MTO has target_dest; SUP-HLD does not.
        target_dest = order_seq.get('target_dest', '')
        sup_parts = target_unit.split()
        sup_unit_type = sup_parts[0] if sup_parts else ''        # 'A' or 'F'
        sup_prov_name = (sup_parts[1].split('/')[0].upper()
                         if len(sup_parts) >= 2 else '')
        sup_prov_id = state.prov_to_id.get(sup_prov_name) if sup_prov_name else None
        check_prov_name = (target_dest if target_dest else
                           target_unit.split()[1].split('/')[0]
                           if len(target_unit.split()) >= 2 else '')
        check_prov_id = (state.prov_to_id.get(check_prov_name.upper())
                         if check_prov_name else None)
        # FUN_004619f0: is_convoy_reachable on the supported unit → support target.
        # Applied for SUP-MTO (target_dest present); SUP-HLD trivially passes
        # (no destination province to validate convoy reachability against).
        if target_dest and sup_prov_id is not None and check_prov_id is not None:
            if not is_convoy_reachable(state, sup_prov_id, sup_unit_type, check_prov_id):
                logger.debug(
                    "validate_and_dispatch_order: SUP convoy-legality failed "
                    "%r → %r", sup_prov_name, target_dest,
                )
                return _ERR_ADJACENCY
        # Supporter-side adjacency check (FUN_00422a90 lines 95, SUP-HLD equiv):
        #   SUP-MTO: supporter must reach target_dest
        #   SUP-HLD: supporter must reach supported unit's province
        # prov_id is the supporter's province. check_prov_id is the province the
        # supporter needs to reach (target_dest for MTO, supported unit's prov
        # for HLD). Plain adjacency — no convoy fallback for supporter.
        if check_prov_id is not None and prov_id != check_prov_id:
            if check_prov_id not in state.adj_matrix.get(prov_id, []):
                logger.debug(
                    "validate_and_dispatch_order: SUP supporter %r not adjacent "
                    "to %r", prov_raw, check_prov_name,
                )
                return _ERR_ADJACENCY

        # SUP-MTO dual alliance check (C lines 515+537):
        # First check: supported unit's current province (where unit currently sits).
        # Second check: target destination (where unit is moving to).
        # SUP-HLD has only one check (the supported unit's province IS the target).
        if target_dest and sup_prov_id is not None:
            sup_dest_power = state.get_unit_power(sup_prov_id)
            rc = check_order_alliance(state, own_power_idx, sup_prov_id,
                                      own_power_idx, sup_dest_power)
            if rc != 0:
                return rc

        # Second check: target destination (existing check for SUP-MTO/HLD)
        if check_prov_id is not None:
            dest_power = state.get_unit_power(check_prov_id)
            rc = check_order_alliance(state, own_power_idx, check_prov_id,
                                      own_power_idx, dest_power)
            if rc != 0:
                return rc
        if commit:
            dispatch_single_order(state, own_power_idx, order_seq)
        return 0

    if order_type == 'CTO':
        # C lines 669–704: convoy-through route, FUN_004619f0.
        target_dest = order_seq.get('target_dest', '')
        if not target_dest:
            return _ERR_NO_TARGET
        dest_prov_id = state.prov_to_id.get(target_dest.split('/')[0].upper())
        # FUN_004619f0: is_convoy_reachable — ordering army (prov_id, unit_type) → dest.
        # param_1 = army unit_data, param_2 = dest_prov, param_3 = -1.
        cto_unit_type = unit_data.get('type', '') if unit_data else ''
        if dest_prov_id is not None and not is_convoy_reachable(
            state, prov_id, cto_unit_type, dest_prov_id
        ):
            logger.debug(
                "validate_and_dispatch_order: CTO convoy-legality failed "
                "%r → %r", prov_raw, target_dest,
            )
            return _ERR_ADJACENCY
        dest_power   = state.get_unit_power(dest_prov_id) if dest_prov_id is not None else -1
        if dest_prov_id is not None:
            rc = check_order_alliance(state, own_power_idx, dest_prov_id,
                                      own_power_idx, dest_power)
            if rc != 0:
                return rc
        if commit:
            dispatch_single_order(state, own_power_idx, order_seq)
        return 0

    if order_type == 'CVY':
        # C lines 461–600: fleet CVY validation (FUN_00422a90 / decompiled.txt).
        # Ordering unit (element 0) = fleet; element 2 = army being conveyed.
        # FUN_004619f0 is called with the ARMY's unit_data and dest province
        # (decompiled.txt line 547); returns -0x186e1 if reachability fails.
        target_dest = order_seq.get('target_dest', '')
        if not target_dest:
            return _ERR_NO_TARGET
        dest_prov_id = state.prov_to_id.get(target_dest.split('/')[0].upper())
        # Extract army from target_unit (e.g. "A BRE").
        # C: GetSubList(local_6c, .., 2) → army sublist; GetListElement(.., 2) = province id.
        cvy_army_str  = order_seq.get('target_unit', '')
        cvy_parts     = cvy_army_str.split()
        army_prov_id  = None
        if len(cvy_parts) >= 2:
            army_prov_id = state.prov_to_id.get(cvy_parts[1].split('/')[0].upper())
        # C: AMY == unit.type check + FUN_004619f0 convoy-reachability.
        if dest_prov_id is not None and army_prov_id is not None:
            army_unit = state.unit_info.get(army_prov_id)
            if army_unit is None or army_unit.get('type') != 'A':
                logger.debug(
                    "validate_and_dispatch_order: CVY army not found or not AMY at %r",
                    cvy_parts[1] if len(cvy_parts) >= 2 else cvy_army_str,
                )
                return _ERR_CVY_NO_ARMY
            if not is_convoy_reachable(state, army_prov_id, 'A', dest_prov_id):
                logger.debug(
                    "validate_and_dispatch_order: CVY convoy-reachability failed "
                    "%r → %r", cvy_parts[1] if len(cvy_parts) >= 2 else '?', target_dest,
                )
                return _ERR_CVY_REACH
        dest_power = state.get_unit_power(dest_prov_id) if dest_prov_id is not None else -1
        if dest_prov_id is not None:
            rc = check_order_alliance(state, own_power_idx, dest_prov_id,
                                      own_power_idx, dest_power)
            if rc != 0:
                return rc
        if commit:
            dispatch_single_order(state, own_power_idx, order_seq)
        return 0

    # WVE / BLD and any unrecognised token — C: return -0x15f91 (lines 529–541)
    logger.debug("validate_and_dispatch_order: unknown order type %r", order_type)
    return _ERR_UNKNOWN_ORDER
