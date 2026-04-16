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
    # C: DAT_00624ef4 = *puVar7  (ParseHSTResponse) — the canonical name is
    # g_MoveTimeLimitSec (see research.md:1484, docs/GlobalDataRefs.md:79).
    # Consumers (communications/scheduling.py:132,133,160,
    # communications/inbound/respond.py:345) all read g_MoveTimeLimitSec, and
    # state.__init__ declares it as `self.g_MoveTimeLimitSec: int = 0`.
    # Previously wrote the phantom name g_MoveTimeLimit, so the HST value
    # never reached the press-scheduling code.
    mtl_match = re.search(r'MTL(?:\s*\(\s*(\d+)\s*\)|.*?(\d+))', message)
    if mtl_match:
        mtl = int(mtl_match.group(1) or mtl_match.group(2))
        state.g_MoveTimeLimitSec = mtl

    # Initialize per-game press threshold randomization (0-98)
    state.g_PressThreshRandom = random.randrange(50) + random.randrange(50)
    
    # Force press level config override if needed.
    # C: DAT_00baed40 (g_MinimalPressMode) — set to 1 by the `-G`/`-g` CLI arg
    # (docs/funcs/ParseCommandLineArg.md:11) for "guaranteed mode".  Read in
    # ParseHSTResponse.c:99 to force g_HistoryCounter = 0.  The Python port
    # doesn't parse a CLI arg so this branch is normally dead; retained for
    # fidelity.  Also accept the older `g_ForceDisablePress` Python name as a
    # fallback for any caller that sets it programmatically.
    if (int(getattr(state, 'g_MinimalPressMode', 0)) == 1
            or int(getattr(state, 'g_ForceDisablePress', 0)) == 1):
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
