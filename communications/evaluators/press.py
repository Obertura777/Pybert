"""Top-level press-evaluation entrypoint (``FUN_0042fc40``).

Split from communications/evaluators.py during the 2026-04 refactor.

Holds the public ``evaluate_press`` dispatcher — the port of
``FUN_0042fc40``.  Given an inbound DAIDE press message, routes through
the per-token evaluators in ``._evals`` and returns a YES/REJ/BWX ack.

Cross-module deps: per-token evaluators (``_eval_single_xdo`` + ``_cal_value``)
from ``._evals``, and ``..state.InnerGameState``.
"""

from ...state import InnerGameState
from ._evals import _cal_value, _eval_single_xdo


def _press_items(tokens: list) -> list:
    """Convert a flat parenthesized wire token list to C-style top-level items."""
    if not isinstance(tokens, list):
        return list(tokens) if tokens else []
    if '(' not in tokens and ')' not in tokens:
        return list(tokens)
    from ..parsers import _split_top_level_groups
    return _split_top_level_groups(tokens)


def _clause_items(item) -> list:
    if not isinstance(item, list):
        return [item]
    return _press_items(item)


def evaluate_press(state: "InnerGameState", entry: dict) -> int:
    """
    Port of EvaluatePress = FUN_0042fc40.

    Evaluates an AND / ORR / single-XDO press proposal and returns
    YES (0x481C) or REJ (0x4814).  The result is passed directly to
    RESPOND as param_2.

    C flow (decompiled.txt FUN_0042fc40):
      - Clears DAT_00bb65d8 scratch list at entry.
      - Gets first token of press content:
          AND  → count XDO sub-proposals; if count > 1 call CAL_VALUE
                 (FUN_004266b6) for combined score; then evaluate each
                 sub-proposal individually via FUN_0042c040.
                 All must pass → YES; any fail → REJ + clear accepted list.
          ORR  → evaluate each sub-proposal; first YES wins.
                 Random 51% gate: if scratch non-empty, may replace stored
                 accepted proposal with new YES one.
          else → single proposal: call FUN_0042c040 directly.
      - On YES: registers accepted tokens in DAT_00bb65d4 (g_accepted_proposals).

    CAL_VALUE (FUN_004266b6): wired to _cal_value() for multi-XDO AND coherence.
    FUN_0042c040 = _eval_single_xdo: type dispatcher (PCE/DMZ/ALY/XDO/SLO/DRW/NOT/SUB).
    """
    from ... import rng as _random
    import logging as _logging
    _log = _logging.getLogger(__name__)

    _YES, _REJ = 0x481C, 0x4814
    _AND, _ORR, _XDO, _NOT = 0x4A01, 0x4A0F, 0x4A1F, 0x480D

    # DAT_00bb65d8 is the header for DAT_00bb65d4, not a separate local
    # scratch container.  C destroys and reinitializes the accepted-proposal
    # tree at the start of every EvaluatePress call.
    state.g_accepted_proposals.clear()

    press = entry.get('sublist3', entry.get('press_content', []))
    order_cands = entry.get('order_candidates', [])

    if not press and not order_cands:
        return _REJ

    # Extract from_power index for sub-evaluator calls.
    _from_tok = entry.get('from_power_tok', 0)
    _from_pow = (_from_tok & 0x7f) if isinstance(_from_tok, int) and _from_tok >= 0x4100 else 0
    # Hidden C arguments at stack+0x1c/+0x18 are the FRM recipient list and
    # sender byte. Every context-sensitive evaluator first computes
    # FUN_00466480(recipients, sender), i.e. recipients followed by sender.
    from ._common import _extract_powers
    _context_powers = _extract_powers(entry.get('sublist2', [])) + [_from_pow]

    structured = _press_items(press)

    # Identify first token (may be string like 'AND' or int like 0x4A01)
    first = structured[0] if structured else None
    first_is_and = (first == _AND or str(first).upper() == 'AND')
    first_is_orr = (first == _ORR or str(first).upper() == 'ORR')

    if first_is_and:
        # ── AND path ─────────────────────────────────────────────────────
        # C first loop (lines 82-95): count XDO clauses, stripping NOT first.
        # NOT XDO(...) counts as an XDO clause for the CAL_VALUE gate.
        def _is_xdo_toks(toks):
            t = list(toks)
            while t and (t[0] == _NOT or str(t[0]).upper() == 'NOT'):
                t = t[1:]
                if len(t) == 1 and isinstance(t[0], list):
                    t = _clause_items(t[0])
            return bool(t) and (t[0] == _XDO or str(t[0]).upper() == 'XDO')

        clauses = [_clause_items(c) for c in structured[1:]]
        xdo_count = sum(1 for tok in clauses if _is_xdo_toks(tok))

        result_ok = True

        # CAL_VALUE: coherence check for multi-XDO compound proposals.
        # C: if (1 < local_80): psVar5 = CAL_VALUE(this, &uStack_7a)
        if xdo_count > 1:
            cal_verdict = _cal_value(state, press)
            if cal_verdict != _YES:
                result_ok = False

        # C: second loop runs unconditionally after CAL_VALUE (bVar10 set but
        # loop not aborted). Track pre-call length so failure cleanup is scoped
        for tok in clauses:
            # C second loop (lines 138-158): skip _eval_single_xdo for XDO
            # clauses when xdo_count >= 2 — CAL_VALUE already covered them.
            # Non-XDO clauses (PCE/DMZ/ALY/etc.) are always evaluated.
            if xdo_count >= 2 and _is_xdo_toks(tok):
                # CAL_VALUE inserts each compound XDO clause into
                # DAT_00bb65d4 during its extraction pass.
                if tok not in state.g_accepted_proposals:
                    state.g_accepted_proposals.append(tok)
                continue
            r = _eval_single_xdo(state, tok, _from_pow, _context_powers)
            if r == _YES:
                # C: FUN_00419300(&DAT_00bb65d4, apvStack_2c, local_6c)
                state.g_accepted_proposals.append(tok)
            else:
                result_ok = False

        if not result_ok:
            state.g_accepted_proposals.clear()
            _log.debug("evaluate_press: AND proposal rejected")
            return _REJ

        _log.debug("evaluate_press: AND proposal accepted")
        return _YES

    elif first_is_orr:
        # ── ORR path ─────────────────────────────────────────────────────
        # DAT_00bb65dc == 0 check: scratch list empty at start of call.
        scratch: list = []   # DAT_00bb65d8 analog
        scratch_count = 0    # DAT_00bb65dc analog

        clauses = [_clause_items(c) for c in structured[1:]]
        for tok in clauses:
            r = _eval_single_xdo(state, tok, _from_pow, _context_powers)
            if r == _YES:
                if scratch_count == 0:
                    scratch = tok
                    scratch_count = 1
                else:
                    # C: (rand()/0x17)%100 < 0x33  → values 0..50 keep (51%),
                    # 51..99 replace (49%).  Python inverts: >= 0x33 triggers replace.
                    rv = _random.randint(0, 0x7FFF)
                    if (rv // 23) % 100 >= 0x33:
                        scratch = tok

        if scratch_count > 0:
            # C: only the randomly-selected winner goes into the accepted list
            # (FUN_00419300 is called once after the loop, not per-iteration).
            state.g_accepted_proposals.append(scratch)
            _log.debug("evaluate_press: ORR proposal accepted")
            return _YES

        _log.debug("evaluate_press: ORR proposal rejected")
        return _REJ

    else:
        # ── Single proposal path ─────────────────────────────────────────
        tok = structured
        r = _eval_single_xdo(state, tok, _from_pow, _context_powers)
        if r == _YES:
            # C: FUN_00419300(&DAT_00bb65d4, apvStack_4c, &stack0x00000008)
            state.g_accepted_proposals.append(tok)
            _log.debug("evaluate_press: single proposal accepted")
        else:
            _log.debug("evaluate_press: single proposal rejected")
        return r
