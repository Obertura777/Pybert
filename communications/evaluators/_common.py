"""Shared helpers and constants for the evaluator slices.

Split from communications/evaluators.py during the 2026-04 refactor.

Module-level contents:
  * ``_POWER_NAMES``, ``_NEUTRAL_POWER``  — constants (power list + neutral slot).
  * ``_pow_idx``        — DAIDE power-token → 0-based index lookup.
  * ``_flatten_section``— recursive token-list flattener (lists of lists → list).
  * ``_extract_powers`` — pull power tokens out of a press section.
  * ``_extract_provs``  — pull province tokens out of a press section.
  * ``_ally_trust_ok``  — alliance-trust predicate used by PCE/DMZ/ALY evals.

Module-level deps: ``..state.InnerGameState``.
"""

from ...state import InnerGameState

# Module-level constants shared across the evaluators.
_POWER_NAMES = ('AUS', 'ENG', 'FRA', 'GER', 'ITA', 'RUS', 'TUR')
_NEUTRAL_POWER = 0x14  # 20 — placeholder power index for "no unit / neutral"


def _pow_idx(tok) -> "int | None":
    """Return 0-based power index from a DAIDE power token or name string."""
    if isinstance(tok, int):
        if 0x4100 <= tok <= 0x4106:
            return tok & 0x7f
        return None
    s = str(tok).upper()
    return _POWER_NAMES.index(s) if s in _POWER_NAMES else None


def _flatten_section(section) -> list:
    """Return ``section`` as a flat list of tokens.

    DAIDE sub-lists arrive as nested Python lists/tuples (string-mode press)
    or as flat token streams.  Both are normalised to a flat list.
    """
    if isinstance(section, (list, tuple)):
        out: list = []
        for tok in section:
            if isinstance(tok, (list, tuple)):
                out.extend(_flatten_section(tok))
            else:
                out.append(tok)
        return out
    return [section]


def _extract_powers(section) -> list:
    """Extract a list of 0-based power indices from a DAIDE power sub-list."""
    out: list = []
    for tok in _flatten_section(section):
        p = _pow_idx(tok)
        if p is not None:
            out.append(p)
    return out


def _extract_provs(state: "InnerGameState", section) -> list:
    """Extract province IDs (state.prov_to_id) from a DAIDE province sub-list.

    Tokens may be raw province names ('MUN'), DAIDE province ints, or already
    resolved IDs.  Returns the list in input order, dropping unknown tokens.
    """
    p2id = getattr(state, 'prov_to_id', {}) or {}
    out: list = []
    for tok in _flatten_section(section):
        if isinstance(tok, int):
            # Already a province ID, or a DAIDE prov token; accept the ID
            # path (DAIDE-int → name resolution is server-mode and not
            # plumbed through string-mode press).
            if tok in getattr(state, '_id_to_prov', {}) or 0 <= tok < 256:
                out.append(int(tok))
            continue
        name = str(tok).upper()
        if name in p2id:
            out.append(int(p2id[name]))
    return out


def _ally_trust_ok(state: "InnerGameState", own: int, other: int) -> bool:
    """Replicate the bVar2 ally-trust check used by _eval_dmz.

    C (_eval_dmz.c lines 173-185):
      Forward (own→other):
        Hi[own,other] >= 0 AND (Hi > 0 OR Lo[own,other] > 2)
      Reverse (other→own):
        Hi[other,own] >= 0 AND (Hi > 0 OR Lo[other,own] != 0)
        AND NOT enemy_flag[other]
        AND relation_score[own,other] >= 0
        AND (press_mode == 0
             OR diplomacy_state_b[other] > 0
             OR (diplomacy_state_b[other] >= 0 AND diplomacy_state_a[other] > 1))
    """
    try:
        hi_fwd = int(state.g_ally_trust_score_hi[own, other])
        lo_fwd = int(state.g_ally_trust_score[own, other])
    except Exception:
        return False
    if hi_fwd < 0 or (hi_fwd == 0 and lo_fwd <= 2):
        return False
    try:
        hi_rev = int(state.g_ally_trust_score_hi[other, own])
        lo_rev = int(state.g_ally_trust_score[other, own])
    except Exception:
        return False
    if hi_rev < 0 or (hi_rev == 0 and lo_rev == 0):
        return False
    if int(getattr(state, 'g_enemy_flag', [0] * 7)[other]) == 1:
        return False
    try:
        rel = int(state.g_relation_score[own, other])  # DAT_00634e90
    except Exception:
        rel = 0
    if rel < 0:
        return False
    press_mode = int(getattr(state, 'g_press_flag', 0)) == 1
    if press_mode:
        try:
            ds_b = int(getattr(state, 'g_diplomacy_state_b', [0] * 8)[other])  # DAT_004d5484
            ds_a = int(getattr(state, 'g_diplomacy_state_a', [0] * 8)[other])  # DAT_004d5480
        except Exception:
            ds_a = ds_b = 0
        if not (ds_b > 0 or (ds_b >= 0 and ds_a > 1)):
            return False
    return True
