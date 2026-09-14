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

# DAT_00bb6f0c press-token lists (ParseHSTResponse.c:102-294).  Each block
# assigns the whole list (AppendList is TokenList::operator=), so the last
# block whose LVL test passes wins.  DAT_004c6e14 holds 0x4A26, CCL.
_PRESS_TOKEN_CODES = {
    'YES': 0x481C, 'REJ': 0x4814, 'BWX': 0x4A02, 'NOT': 0x480D,
    'CCL': 0x4A26, 'SLO': 0x4816, 'DRW': 0x4801, 'PRP': 0x4A13,
    'PCE': _TOK_PCE, 'DMZ': _TOK_DMZ, 'ALY': _TOK_ALY, 'VSS': _TOK_VSS,
    'XDO': _TOK_XDO, 'AND': _TOK_AND, 'ORR': _TOK_ORR,
}
_BASE_PRESS_LIST = ('YES', 'REJ', 'BWX', 'NOT', 'CCL', 'SLO', 'DRW')
_LVL10_PRESS_LIST = _BASE_PRESS_LIST + ('PRP', 'PCE', 'DMZ', 'ALY', 'VSS')
_LVL20_PRESS_LIST = _LVL10_PRESS_LIST + ('XDO',)
_LVL30_PRESS_LIST = _LVL20_PRESS_LIST + ('AND', 'ORR')
# DAT_00baed40 == 1 (minimal press) replaces the list with YES REJ BWX.
_MINIMAL_PRESS_LIST = ('YES', 'REJ', 'BWX')


def _allowed_press_tokens(level: int, minimal: bool) -> tuple:
    if minimal:
        return _MINIMAL_PRESS_LIST
    if level > 29:
        return _LVL30_PRESS_LIST
    if level > 19:
        return _LVL20_PRESS_LIST
    if level > 9:
        return _LVL10_PRESS_LIST
    return _BASE_PRESS_LIST


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

    # ── Allowed press tokens (DAT_00bb6f0c) and per-power sets ───────────────
    # C: the LVL blocks assign DAT_00bb6f0c; the per-power loop then clears
    # DAT_00bb6e10[p*0xc] and registers every token of that list.
    allowed_names = _allowed_press_tokens(int(state.g_history_counter), minimal)
    state.g_allowed_press_token_list = list(allowed_names)
    allowed = {_PRESS_TOKEN_CODES[name] for name in allowed_names}

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

    # ── CRT seed (ParseHSTResponse.c:338-339) ────────────────────────────────
    # The function Ghidra names SetTurnDeadline (0x0047b66b) is the CRT
    # srand: it stores its argument in __getptd()->_holdrand.  C seeds the
    # stream with __time64(NULL) + own_power * 1000 and immediately draws
    # DAT_004c6bd4 = (rand/0x17)%50 + (rand/0x17)%50 from it.
    own_power = int(getattr(state, 'albert_power_idx', 0))
    _random.seed(int(_time.time()) + own_power * 1000)
    state.g_press_thresh_random = _random.randrange(50) + _random.randrange(50)
