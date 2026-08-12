"""Shared g_order_table field indices and order-type constants.

Canonical source for constants consumed by convoy.py, support.py,
and external callers (monte_carlo, heuristics).  Extracted to break
the convoy ↔ support circular import.

Full field list lives in monte_carlo.py; this is the subset needed
by the moves package.
"""

# ── g_order_table field indices ───────────────────────────────────────────────
_F_ORDER_TYPE         =  0   # 1=HLD 2=MTO 3=SUP_HLD 4=SUP_MTO 5=CVY 6=CTO
_F_SECONDARY          =  1   # CVY: army province; SUP: mover province (DAT_00baeda4)
_F_DEST_PROV          =  2   # destination province (MTO/CTO/SUP target) (DAT_00baeda8)
_F_CONVOY_LO          =  6   # convoy-chain score lo-word / negated defense score (DAT_00baedb8)
_F_CONVOY_HI          =  7   # convoy-chain score hi-word (DAT_00baedbc)
_F_CONVOY_LEG0        =  8   # CTO convoy leg 0 (DAT_00baee08)
_F_CONVOY_LEG1        =  9   # CTO convoy leg 1 (DAT_00baee0c)
_F_CONVOY_LEG2        = 10   # CTO convoy leg 2 (DAT_00baee10)
_F_INCOMING_MOVE      = 13   # 1 = province has incoming MTO/CTO (DAT_00baedd4 = g_ProvinceBaseScore)
_F_SUP_CHAIN_CONFLICT = 14   # support-chain conflict accumulator (DAT_00baedd8)
_F_SOURCE_PROV        = 16   # source province; SUP = supported unit's province
_F_ORDER_ASGN         = 20   # 1 = support order committed

# ── order-type codes ─────────────────────────────────────────────────────────
_ORDER_MTO     = 2
_ORDER_SUP_HLD = 3
_ORDER_SUP_MTO = 4
_ORDER_CVY     = 5
_ORDER_CTO     = 6

# ── convoy limits ────────────────────────────────────────────────────────────
_MAX_CONVOY_CHAIN_DEPTH = 11  # C uses < 0xb (11 iterations: 0..10)
