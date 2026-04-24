"""HST history-message parser.

Split from communications/inbound.py during the 2026-04 refactor.

Holds ``process_hst`` — the port of ``ParseHSTResponse`` (FUN_0041b410),
which consumes a history (HST) message from the server and updates the
inner game state with the observed per-turn record.

Module-level deps: ``...state.InnerGameState``; DAIDE press-type
token constants from ``..tokens``.
"""

from ...state import InnerGameState
from ..tokens import (
    _TOK_ALY, _TOK_AND, _TOK_DMZ, _TOK_ORR, _TOK_PCE, _TOK_VSS, _TOK_XDO,
)


def process_hst(state: InnerGameState, message: str):
    """
    Port of ParseHSTResponse (FUN_0041b410).
    Maps host capability tables.
    """
    import re
    import random
    
    # Parse LVL
    lvl_match = re.search(r'LVL(?:\s*\(\s*(\d+)\s*\)|.*?(\d+))', message)
    if lvl_match:
        lvl = int(lvl_match.group(1) or lvl_match.group(2))
        state.g_HistoryCounter = lvl

    # Parse MTL 
    mtl_match = re.search(r'MTL(?:\s*\(\s*(\d+)\s*\)|.*?(\d+))', message)
    if mtl_match:
        mtl = int(mtl_match.group(1) or mtl_match.group(2))
        state.g_MoveTimeLimit = mtl

    # Initialize per-game press threshold randomization (0-98)
    state.g_PressThreshRandom = random.randrange(50) + random.randrange(50)
    
    # Force press level config override if needed
    if getattr(state, 'g_ForceDisablePress', 0) == 1:
        state.g_HistoryCounter = 0

    # Populate per-power allowed-press-type maps (DAT_00bb6e10[p*0xc]).
    # C: RegisterAllowedPressToken called for each token in g_AllowedPressTokenList[0..lvl-1].
    # Threshold table (research.md §3548-3552):
    #   lvl > 9:  adds PCE, ALY, VSS, DMZ
    #   lvl > 19: adds XDO
    #   lvl > 29: adds AND, ORR
    lvl = state.g_HistoryCounter
    allowed: set = set()
    if lvl > 9:
        allowed |= {_TOK_PCE, _TOK_ALY, _TOK_VSS, _TOK_DMZ}
    if lvl > 19:
        allowed.add(_TOK_XDO)
    if lvl > 29:
        allowed |= {_TOK_AND, _TOK_ORR}
    num_powers = getattr(state, 'g_NumPowers', 7)
    state.g_press_history = {p: set(allowed) for p in range(num_powers)}
