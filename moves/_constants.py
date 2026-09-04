"""Shared g_order_table field indices and order-type constants.

Canonical source for constants consumed by convoy.py, support.py,
and external callers (monte_carlo, heuristics).  Extracted to break
the convoy ↔ support circular import.

Full field list lives in monte_carlo.py; this is the subset needed
by the moves package.
"""

from numbers import Integral

# ── g_order_table field indices ───────────────────────────────────────────────
_F_ORDER_TYPE         =  0   # 1=HLD 2=MTO 3=SUP_HLD 4=SUP_MTO 5=CVY 6=CTO
_F_SECONDARY          =  1   # CVY: army province; SUP: mover province (DAT_00baeda4)
_F_DEST_PROV          =  2   # destination province (MTO/CTO/SUP target) (DAT_00baeda8)
_F_DEST_COAST         =  3   # unit/coast token (DAT_00baedac)
_F_CONVOY_LO          =  6   # convoy-chain score lo-word / negated defense score (DAT_00baedb8)
_F_CONVOY_HI          =  7   # convoy-chain score hi-word (DAT_00baedbc)
_F_CONVOY_DEPTH       = 23   # CTO convoy leg count (DAT_00baedfc)
_F_CONVOY_LEG0        = 26   # CTO convoy leg 0 (DAT_00baee08)
_F_CONVOY_LEG1        = 27   # CTO convoy leg 1 (DAT_00baee0c)
_F_CONVOY_LEG2        = 28   # CTO convoy leg 2 (DAT_00baee10)
_F_INCOMING_MOVE      = 13   # 1 = province has incoming MTO/CTO (DAT_00baedd4 = g_ProvinceBaseScore)
_F_SUP_CHAIN_CONFLICT = 14   # support-chain conflict accumulator (DAT_00baedd8)
_F_THREAT_TOTAL        = 16   # summed enemy reach on this province (DAT_00baede0)
                              # Written once in all of C — ProcessTurn.c:1487 —
                              # and only ever read as `== 1` / `== 2`.  Never a
                              # province id: it was called _F_SOURCE_PROV until
                              # 2026-08-12, and three call sites wrote province
                              # ids into it, corrupting those tests.
_F_ORDER_ASGN         = 20   # support/convoy state; 1=committed, 5=convoy complete
_CONVOY_DEPTH_COMPLETE = 5

# ── order-type codes ─────────────────────────────────────────────────────────
_ORDER_MTO     = 2
_ORDER_SUP_HLD = 3
_ORDER_SUP_MTO = 4
_ORDER_CVY     = 5
_ORDER_CTO     = 6

# ── DAIDE unit/coast tokens ─────────────────────────────────────────────────
_UNIT_TOKEN_AMY = 0x4200
_UNIT_TOKEN_FLT = 0x4201
_COAST_STR_TO_TOKEN = {
    'NC': 0x4600,
    'NE': 0x4602,
    'EC': 0x4604,
    'SE': 0x4606,
    'SC': 0x4608,
    'SW': 0x460A,
    'WC': 0x460C,
    'NW': 0x460E,
}


def _unit_location_token(unit_type: object, coast: object = '') -> int:
    """Return the UnitList/ParseDestinationWithCoast token for a location."""
    if str(unit_type).upper() in ('A', 'AMY'):
        return _UNIT_TOKEN_AMY
    if isinstance(coast, Integral) and coast:
        return int(coast)
    coast_name = str(coast or '').upper().lstrip('/')
    return _COAST_STR_TO_TOKEN.get(coast_name, _UNIT_TOKEN_FLT)

# ── convoy limits ────────────────────────────────────────────────────────────
_MAX_CONVOY_CHAIN_DEPTH = 11  # C uses < 0xb (11 iterations: 0..10)
