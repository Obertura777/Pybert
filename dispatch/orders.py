"""Per-order dispatch helpers: coast parsing and single-order commit.

Split from dispatch.py during the 2026-04 refactor.

Two short helpers used by ``validate_and_dispatch_order`` after a given
order has been validated:

  * ``parse_destination_with_coast`` — split a ``"PROV/CST"`` token.
  * ``dispatch_single_order``        — commit one validated order to
    the game via the ``state.game`` adapter.

Module-level deps: ``..state.InnerGameState``, shared logger from
``._errors``.
"""

from ..state import InnerGameState

from ._errors import logger

def parse_destination_with_coast(dest_token: dict):
    # Mocking ParseDestinationWithCoast
    prov = dest_token.get('province')
    coast = dest_token.get('coast', '')
    if coast:
        return f"{prov}/{coast}"
    return prov


def dispatch_single_order(state: InnerGameState, power_index: int, order_seq: dict):
    """
    Port of FUN_0044cc50. The core multiplexer for tactical order distribution.
    Takes internal logical order definitions from the monte_carlo evaluator buffer
    and multiplexes them into DipNet formatted strings native to python-diplomacy.
    """
    token_head = order_seq.get('type', 'HLD')
    unit_str = order_seq.get('unit', '') # e.g. "A PAR"
    
    formatted_order = ""
    
    if token_head == 'HLD':
        # Translates BuildOrder_HLD logic
        formatted_order = f"{unit_str} H"
        
    elif token_head == 'MTO':
        # Translates BuildOrder_MTO logic
        target_str = parse_destination_with_coast({'province': order_seq.get('target', ''), 'coast': order_seq.get('coast', '')})
        formatted_order = f"{unit_str} - {target_str}"
        
    elif token_head == 'SUP':
        target_unit = order_seq.get('target_unit', '')
        dest_prov = order_seq.get('target_dest', None)
        
        # Branch determining SUP_MTO or SUP_HLD logic paths
        if dest_prov:
            target_str = parse_destination_with_coast({'province': dest_prov, 'coast': order_seq.get('target_coast', '')})
            formatted_order = f"{unit_str} S {target_unit} - {target_str}"
        else:
            formatted_order = f"{unit_str} S {target_unit}"
            
    elif token_head == 'CTO':
        # BuildOrder_CTO: army moving to destination via convoy
        # C: DispatchSingleOrder lines 140-144 calls ClearConvoyState() and
        # zeroes g_ConvoySourceProv before CTO dispatch to avoid stale routing
        # data from a previous trial. Fixed 2026-04-20 (audit finding C8).
        if hasattr(state, 'g_ConvoySourceProv'):
            state.g_ConvoySourceProv.fill(-1)
        if hasattr(state, 'g_ConvoyDstToSrc'):
            state.g_ConvoyDstToSrc.clear() if isinstance(state.g_ConvoyDstToSrc, dict) else state.g_ConvoyDstToSrc.fill(-1)
        dest_prov = order_seq.get('target_dest', '')
        formatted_order = f"{unit_str} - {dest_prov} VIA"

    elif token_head == 'CVY':
        # BuildOrder_CVY: fleet convoying an army to destination
        target_army = order_seq.get('target_unit', '')
        if target_army and not target_army.startswith('A'):
            logger.warning(
                "CVY target_unit %r is not an army — convoy orders "
                "require an army unit", target_army)
        dest_prov = order_seq.get('target_dest', '')
        formatted_order = f"{unit_str} C {target_army} - {dest_prov}"
        
    else:
        logger.warning(f"Unknown DAIDE dispatch token branch: {token_head}")

    # Accumulate finalized python sequence strings for submit_orders handler in bot.py.
    # NB: this is *not* the C g_OrderList (a std::map of dict-shaped entries used
    # by ComputeOrderDipFlags / ProposeDMZ in communications.py).  We use a
    # distinct name to avoid feeding plain strings into the dict-iterating call
    # sites — see communications.py compute_order_dip_flags / ProposeDMZ.
    if not hasattr(state, 'g_SubmittedOrders'):
        state.g_SubmittedOrders = []

    if formatted_order:
        state.g_SubmittedOrders.append(formatted_order)
        logger.debug(f"Pushed to generalized SUB sequence: {formatted_order}")


