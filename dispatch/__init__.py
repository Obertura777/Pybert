"""Order dispatch layer — facade for the split dispatch package.

Re-exports the flat public API of the original ``albert.dispatch``
module so external callers (``albert.bot``, ``albert.communications``)
keep working unchanged. Organized into five internal submodules:

  * ``._errors``   — 18 error-code sentinels and the shared
    ``logger`` tied to the ``albert.dispatch`` name.
  * ``.alliance``  — ``check_order_alliance`` (alliance / promise / trust).
  * ``.legality``  — ``_is_legal_mto`` + ``is_convoy_reachable`` predicates.
  * ``.orders``    — ``parse_destination_with_coast`` + ``dispatch_single_order``.
  * ``.validator`` — ``validate_and_dispatch_order`` (public entry point).
"""

from ._errors import (
    logger,
    _ERR_MALFORMED_UNIT,
    _ERR_BAD_PROVINCE,
    _ERR_POWER_MISMATCH,
    _ERR_NO_TARGET,
    _ERR_ADJACENCY,
    _ERR_NO_SUP_UNIT,
    _ERR_CVY_NO_ARMY,
    _ERR_CVY_REACH,
    _ERR_UNKNOWN_ORDER,
    _ERR_ALLY_TRUST_A,
    _ERR_ALLY_TRUST_B,
    _ERR_ALLY_TRUST_C,
    _ERR_DUP_OWN,
    _ERR_DUP_OTHER,
    _ERR_COUNTER_REC,
    _ERR_PROMISE_SAME,
    _ERR_PROMISE_DIFF,
)
from .alliance import check_order_alliance
from .legality import _is_legal_mto, is_convoy_reachable
from .orders import parse_destination_with_coast, dispatch_single_order
from .validator import validate_and_dispatch_order
