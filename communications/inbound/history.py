"""HST history-message parser.

Split from communications/inbound.py during the 2026-04 refactor.

Holds ``process_hst`` — the port of ``ParseHSTResponse`` (FUN_0041b410),
which consumes a history (HST) message from the server and updates the
inner game state with the observed per-turn record.

Module-level deps: ``...state.InnerGameState``; DAIDE press-type
token constants from ``..tokens``.
"""

import re as _re
from ... import rng as _random
import time as _time

from ...state import InnerGameState
from ..tokens import (
    _TOK_ALY, _TOK_AND, _TOK_DMZ, _TOK_ORR, _TOK_PCE, _TOK_VSS, _TOK_XDO,
)

# Base press tokens registered unconditionally (YES..DRW block in C).
# C: FUN_00466540(&YES,…,&REJ) then FUN_00466480 x6 builds
#    {YES, REJ, BWX, NOT, DAT_004c6e14, SLO, DRW}.
# DAT_004c6e14 xrefs (0041b631/0041b750/0041b953/0041bb8f PUSH; 0042c603 MOV word READ):
#   _eval_single_xdo.c line 186 checks DAT_004c6e14 == first_token, strips sublist[1],
#   then matches PCE / DMZ inside — the standard PRP(…) unwrap pattern.
#   DAT_004c6e14 = PRP = 0x4A13 (confirmed from utils/tokens.py "4A13":"PRP").
#   The lvl>9 block also PUSHes &PRP explicitly — duplicate insert into the ordered set,
#   which is idempotent.
_TOK_YES_PRESS = 0x481C   # YES  (utils/tokens.py "481C":"YES")
_TOK_REJ_PRESS = 0x4814   # REJ  (utils/tokens.py "4814":"REJ")
_TOK_BWX_PRESS = 0x4A02   # BWX  (utils/tokens.py "4A02":"BWX")
_TOK_NOT_PRESS = 0x480D   # NOT  (utils/tokens.py "480D":"NOT")
_TOK_SLO       = 0x4816   # SLO  (utils/tokens.py "4816":"SLO")
_TOK_DRW       = 0x4801   # DRW  (utils/tokens.py "4801":"DRW")
_TOK_PRP       = 0x4A13   # PRP = DAT_004c6e14 (utils/tokens.py "4A13":"PRP")

# Unconditional base set: always registered regardless of level.
_BASE_PRESS_TOKENS: frozenset = frozenset({
    _TOK_YES_PRESS, _TOK_REJ_PRESS, _TOK_BWX_PRESS,
    _TOK_NOT_PRESS, _TOK_PRP, _TOK_SLO, _TOK_DRW,
})

# Minimal-press set (DAT_00baed40 == 1): only YES/REJ/BWX + g_history_counter forced to 0.
_MINIMAL_PRESS_TOKENS: frozenset = frozenset({
    _TOK_YES_PRESS, _TOK_REJ_PRESS, _TOK_BWX_PRESS,
})


def process_hst(state: InnerGameState, message: str) -> None:
    """
    Port of ParseHSTResponse (FUN_0041b410).

    Reads LVL (press level) and MTL (move time limit) from the HST/HLO
    variant string, registers allowed press-token sets for each power, and
    sets the turn deadline.
    """
    # ── LVL (press level) ────────────────────────────────────────────────────
    # C lines 88-101: GetListElement(local_6c,…,1) → sign-extend 14-bit token.
    # g_history_counter = 0 when g_minimal_press_mode is set (line 99-101).
    lvl_match = _re.search(r'LVL(?:\s*\(\s*(-?\d+)\s*\)|[ \t]+(-?\d+))', message)
    if lvl_match:
        raw = int(lvl_match.group(1) or lvl_match.group(2))
        if raw & 0x2000:          # sign-extend 14-bit DAIDE token (C lines 94-96)
            raw |= ~0x1fff
        state.g_history_counter = raw

    # ── Minimal-press override (DAT_00baed40) ────────────────────────────────
    minimal = (int(getattr(state, 'g_minimal_press_mode', 0)) == 1
               or int(getattr(state, 'g_ForceDisablePress', 0)) == 1)
    if minimal:
        state.g_history_counter = 0

    # ── Press threshold randomization ────────────────────────────────────────
    # C line 346: DAT_004c6bd4 = (rand/0x17%50) + (rand/0x17%50)
    state.g_press_thresh_random = _random.randrange(50) + _random.randrange(50)

    # ── Per-power allowed-press-type maps (DAT_00bb6e10[p*0xc]) ─────────────
    # C lines 102-294: four AppendList blocks build g_allowed_press_token_list,
    # then the per-power loop calls RegisterAllowedPressToken for each entry.
    #
    # Block 1 (unconditional):  YES REJ BWX NOT PRP SLO DRW
    # Block 2 (lvl > 9):        + PCE DMZ ALY VSS  (PRP re-inserted — idempotent)
    # Block 3 (lvl > 19):       + XDO
    # Block 4 (lvl > 29):       + AND ORR
    # Minimal override (line 284-294): {YES REJ BWX} only
    if minimal:
        allowed: frozenset = _MINIMAL_PRESS_TOKENS
    else:
        lvl = state.g_history_counter
        allowed = set(_BASE_PRESS_TOKENS)
        if lvl > 9:
            allowed |= {_TOK_PCE, _TOK_ALY, _TOK_VSS, _TOK_DMZ}
        if lvl > 19:
            allowed.add(_TOK_XDO)
        if lvl > 29:
            allowed |= {_TOK_AND, _TOK_ORR}
        allowed = frozenset(allowed)

    num_powers = getattr(state, 'g_num_powers', 7)
    state.g_press_history = {p: set(allowed) for p in range(num_powers)}

    # ── MTL (move time limit) ────────────────────────────────────────────────
    # C lines 327-337: GetListElement(local_5c,…) checks MTL token, reads value,
    # sign-extends 14-bit, stores to DAT_00624ef4 (g_move_time_limit_sec).
    # C: DAT_00624ef4 = local_13c (the canonical name is
    # g_move_time_limit_sec (see research.md:1484, docs/GlobalDataRefs.md:79).
    # Consumers (communications/scheduling.py:132,133,160,
    # communications/inbound/respond.py:345) all read g_move_time_limit_sec, and
    # state.__init__ declares it as `self.g_move_time_limit_sec: int = 0`.
    # Previously wrote the phantom name g_move_time_limit, so the HST value
    # never reached the press-scheduling code.
    mtl_match = _re.search(r'MTL(?:\s*\(\s*(-?\d+)\s*\)|[ \t]+(-?\d+))', message)
    if mtl_match:
        raw_mtl = int(mtl_match.group(1) or mtl_match.group(2))
        if raw_mtl & 0x2000:      # sign-extend 14-bit DAIDE token (C lines 333-335)
            raw_mtl |= ~0x1fff
        state.g_move_time_limit_sec = raw_mtl

    # ── Turn deadline (SetTurnDeadline) ──────────────────────────────────────
    # C line 338-339: _Var13 = __time64(0); SetTurnDeadline(_Var13 + uVar11*1000)
    # uVar11 carries the MTL value after the CONCAT22 update; *1000 converts to ms.
    # Python: store absolute deadline in epoch-seconds so check_time_limit callers
    # can compare against time.time().
    if state.g_move_time_limit_sec > 0:
        state.g_turn_deadline = _time.time() + state.g_move_time_limit_sec
