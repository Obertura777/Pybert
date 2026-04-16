"""Press-evaluation pipeline — facade for the split evaluators package.

Originally a single 2,552-line ``evaluators.py``.  Split into
submodules during the 2026-04 refactor; the flat public surface is
preserved by the re-exports below so nothing external needs to change.

Internal organisation:

* ``_common``       — constants + shared helpers (``_pow_idx``,
  ``_flatten_section``, ``_extract_powers``, ``_extract_provs``,
  ``_ally_trust_ok``).
* ``_evals``        — per-token evaluators (``_eval_pce`` / ``_eval_dmz``
  / ``_eval_aly`` / ``_eval_slo`` / ``_eval_drw`` / ``_eval_not_pce`` /
  ``_eval_not_dmz`` / ``_eval_sub_xdo`` / ``_eval_single_xdo``) plus the
  XDO clause split (``_split_xdo_clauses``) and headline scorer
  (``_cal_value``).
* ``press``         — ``evaluate_press`` (``FUN_0042fc40``): public
  press-evaluation entrypoint.
* ``flags``         — ``compute_order_dip_flags`` (``FUN_004113d0``):
  order-table → DIP-flag derivation.
* ``handlers``      — YES-branch press handlers (``_handle_pce`` /
  ``_handle_aly`` / ``_handle_dmz`` / ``_handle_xdo``), XDO scoring
  helpers (``_score_support_opp`` / ``_score_sup_attacker``), and the
  ``cal_move`` dispatcher.
* ``cancellation``  — NOT-branch handlers (``_cancel_pce`` /
  ``_remove_dmz`` / ``_not_xdo``).
"""

from ._common import (
    _POWER_NAMES,
    _NEUTRAL_POWER,
    _pow_idx,
    _flatten_section,
    _extract_powers,
    _extract_provs,
    _ally_trust_ok,
)
from ._evals import (
    _eval_pce,
    _eval_dmz,
    _eval_aly,
    _split_xdo_clauses,
    _cal_value,
    _eval_slo,
    _eval_drw,
    _eval_not_pce,
    _eval_not_dmz,
    _eval_sub_xdo,
    _eval_single_xdo,
)
from .press import evaluate_press
from .flags import compute_order_dip_flags
from .handlers import (
    _handle_pce,
    _handle_aly,
    _handle_dmz,
    _handle_xdo,
    _score_support_opp,
    _score_sup_attacker,
    cal_move,
)
from .cancellation import _cancel_pce, _remove_dmz, _not_xdo
