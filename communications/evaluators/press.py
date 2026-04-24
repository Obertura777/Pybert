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
      - On YES: registers accepted tokens in DAT_00bb65d4 (g_AcceptedProposals).

    CAL_VALUE (FUN_004266b6): wired to _cal_value() for multi-XDO AND coherence.
    FUN_0042c040 = _eval_single_xdo: type dispatcher (PCE/DMZ/ALY/XDO/SLO/DRW/NOT/SUB).
    """
    import random as _random
    import logging as _logging
    _log = _logging.getLogger(__name__)

    _YES, _REJ = 0x481C, 0x4814
    _AND, _ORR, _XDO = 0x4A01, 0x4A0F, 0x4A1F

    # C: clears DAT_00bb65d8 (scratch list) at start of each call.
    # Python: use local scratch; nothing to clear on state.

    press = entry.get('sublist3', entry.get('press_content', []))
    order_cands = entry.get('order_candidates', [])

    if not press and not order_cands:
        return _REJ

    # Extract from_power index for sub-evaluator calls.
    _from_tok = entry.get('from_power_tok', 0)
    _from_pow = (_from_tok & 0x7f) if isinstance(_from_tok, int) and _from_tok >= 0x4100 else 0

    # Identify first token (may be string like 'AND' or int like 0x4A01)
    first = press[0] if press else None
    first_is_and = (first == _AND or str(first).upper() == 'AND')
    first_is_orr = (first == _ORR or str(first).upper() == 'ORR')

    if first_is_and:
        # ── AND path ─────────────────────────────────────────────────────
        # Count XDO sub-proposals among order_cands.
        xdo_count = sum(
            1 for c in order_cands
            if (c.get('tokens') or [''])[0] in (_XDO, 'XDO')
        )

        result_ok = True

        # CAL_VALUE: coherence check for multi-XDO compound proposals.
        # C: if (1 < local_80): psVar5 = CAL_VALUE(this, &uStack_7a)
        if xdo_count > 1:
            cal_verdict = _cal_value(state, press)
            if cal_verdict != _YES:
                result_ok = False

        if result_ok:
            for cand in order_cands:
                tok = cand.get('tokens', [])
                r = _eval_single_xdo(state, tok, _from_pow)
                if r == _YES:
                    # C: FUN_00419300(&DAT_00bb65d4, apvStack_2c, local_6c)
                    state.g_AcceptedProposals.append(tok)
                else:
                    result_ok = False

        if not result_ok:
            state.g_AcceptedProposals.clear()  # C: cleanup loop on failure
            _log.debug("evaluate_press: AND proposal rejected")
            return _REJ

        _log.debug("evaluate_press: AND proposal accepted")
        return _YES

    elif first_is_orr:
        # ── ORR path ─────────────────────────────────────────────────────
        # DAT_00bb65dc == 0 check: scratch list empty at start of call.
        scratch: list = []   # DAT_00bb65d8 analog
        scratch_count = 0    # DAT_00bb65dc analog

        for cand in order_cands:
            tok = cand.get('tokens', [])
            r = _eval_single_xdo(state, tok, _from_pow)
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
            state.g_AcceptedProposals.append(scratch)
            _log.debug("evaluate_press: ORR proposal accepted")
            return _YES

        _log.debug("evaluate_press: ORR proposal rejected")
        return _REJ

    else:
        # ── Single proposal path ─────────────────────────────────────────
        tok = order_cands[0].get('tokens', press) if order_cands else press
        r = _eval_single_xdo(state, tok, _from_pow)
        if r == _YES:
            # C: FUN_00419300(&DAT_00bb65d4, apvStack_4c, &stack0x00000008)
            state.g_AcceptedProposals.append(tok)
            _log.debug("evaluate_press: single proposal accepted")
        else:
            _log.debug("evaluate_press: single proposal rejected")
        return r
