import logging
from .state import InnerGameState

logger = logging.getLogger(__name__)

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
        # BuildOrder_CTO translating convoy fleet actions
        target_army = order_seq.get('target_unit', '')
        dest_prov = order_seq.get('target_dest', '')
        formatted_order = f"{unit_str} C {target_army} - {dest_prov}"
        
    elif token_head == 'CVY':
        # BuildOrder_CVY translating the army moving via convoy
        dest_prov = order_seq.get('target_dest', '')
        formatted_order = f"{unit_str} - {dest_prov} VIA"
        
    else:
        logger.warning(f"Unknown DAIDE dispatch token branch: {token_head}")

    # Accumulate finalized python sequence strings for submit_orders handler in bot.py
    if not hasattr(state, 'g_OrderList'):
        state.g_OrderList = []
        
    if formatted_order:
        state.g_OrderList.append(formatted_order)
        logger.debug(f"Pushed to generalized SUB sequence: {formatted_order}")
