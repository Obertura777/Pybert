"""Dispatch error codes and shared logger.

Split from dispatch.py during the 2026-04 refactor.

Return-value sentinels used by ``check_order_alliance`` (alliance
family) and ``validate_and_dispatch_order`` (dispatch family), plus a
shared ``logger`` tied explicitly to the ``albert.dispatch`` name so
logger identity matches the pre-refactor monolith regardless of which
submodule emits the record.

No behaviour; constants only.
"""

import logging

logger = logging.getLogger("albert.dispatch")

# ── Dispatch-family codes (FUN_00422a90 return values) ───────────────────
_ERR_MALFORMED_UNIT   = -0x186a1   # malformed / missing unit field
_ERR_BAD_PROVINCE     = -0x186a5   # province not in prov_to_id
_ERR_POWER_MISMATCH   = -0x14c09   # unit belongs to a different power
_ERR_NO_TARGET        = -0x186aa   # MTO / CTO / CVY missing destination
_ERR_ADJACENCY        = -0x186aa   # FUN_00460b30 adjacency gate failed
_ERR_NO_SUP_UNIT      = -0x186b4   # SUP missing target unit
_ERR_CVY_NO_ARMY      = -0x186d7   # CVY: army not in orders / wrong type
_ERR_CVY_REACH        = -0x186e1   # CVY: FUN_004619f0 convoy-reachability failed
_ERR_UNKNOWN_ORDER    = -0x15f91   # order type not HLD/MTO/SUP/CTO/CVY

# ── Alliance-family codes (FUN_0041d360 = check_order_alliance) ──────────
# All in range -0x13881 .. -0x138B2 (= 0xFFFEC77F .. 0xFFFEC74E as unsigned 32-bit)
_ERR_ALLY_TRUST_B    = -0x13881   # 0xFFFEC77F — slot-B designation has non-zero trust
_ERR_ALLY_TRUST_A    = -0x13882   # 0xFFFEC77E — slot-A designation has non-zero trust
_ERR_ALLY_TRUST_C    = -0x13883   # 0xFFFEC77D — slot-C designation has non-zero trust
_ERR_DUP_OWN         = -0x1388A   # 0xFFFEC776 — promise-list conflict, own-unit context
_ERR_DUP_OTHER       = -0x13894   # 0xFFFEC76C — promise-list conflict, other-unit context
_ERR_COUNTER_REC     = -0x1389E   # 0xFFFEC762 — counter-list consistency check failed
_ERR_PROMISE_SAME    = -0x138A8   # 0xFFFEC758 — FUN_00401050, dest == ordering context
_ERR_PROMISE_DIFF    = -0x138B2   # 0xFFFEC74E — FUN_00401050, dest != own-power context
