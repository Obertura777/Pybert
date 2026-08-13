"""Monte-Carlo order-table field indices and order-type constants.

Split from monte_carlo.py during the 2026-04 refactor. These are the
numeric field positions into the g_order_table row-per-province table and
the six order-type tags consumed by the dispatch/evaluation pipeline.
No runtime behavior — this module is constants only.
"""

# ── Order-table field indices ────────────────────────────────────────────────
# g_order_table[prov, field]  mirrors  DAT_00baeda0[prov*0x1e + field*4]
# Layout from research.md §DispatchSingleOrder "complete field map (updated)"
# and §AssignSupportOrder.  Field [3] is ushort read via ptr-to-short at
# stride 0x3c × 2 = 0x78 (same row width as the int fields).
_F_ORDER_TYPE    =  0   # 1=HLD 2=MTO 3=SUP_HLD 4=SUP_MTO 5=CVY 6=CTO (DAT_00baeda0)
_F_SECONDARY     =  1   # CVY: army_prov; SUP: target_prov (DAT_00baeda4)
_F_DEST_PROV     =  2   # destination province (MTO/CTO/CVY) (DAT_00baeda8)
_F_DEST_COAST    =  3   # destination coast token, ushort (DAT_00baedac)
_F_MOVE_PROB     =  4   # unit move probability, written by EvaluateOrderScore (DAT_00baedb0)
# Compatibility alias for older callers.  This field is not Pass C's
# reach/hold factor; that is field 21 below.
_F_HOLD_WEIGHT   = _F_MOVE_PROB
_F_CTO_DEST_PROP = 23   # CTO convoy leg count (DAT_00baedfc)
_F_CONVOY_LO     =  6   # convoy chain score lo / negated defense score (DAT_00baedb8)
_F_CONVOY_HI     =  7   # convoy chain score hi (DAT_00baedbc)
_F_SELECTED_SCORE_LO = 8  # selected final_score_set lo (DAT_00baedc0)
_F_SELECTED_SCORE_HI = 9  # selected final_score_set hi (DAT_00baedc4)
_F_CONVOY_DEPTH  = 23   # CTO convoy leg count (DAT_00baedfc)
_F_CONVOY_LEG0   = 26   # CTO convoy leg 0 (DAT_00baee08)
_F_CONVOY_LEG1   = 27   # CTO convoy leg 1 (DAT_00baee0c)
_F_CONVOY_LEG2   = 28   # CTO convoy leg 2 (DAT_00baee10)
_F_INCOMING_MOVE = 13   # 1 = province has incoming MTO/CTO (DAT_00baedd4)
                        # Also: accumulator bumped by BuildOrder_SUP_*/_HLD
                        # tails when the support chain passes the "no enemy
                        # can cut this chain" adjacency scan.
_F_SUP_SRC_LO    = 14   # support source province low word (§ScoreOrderSet)
                        # Dual-use: BuildOrder_SUP_*/_MTO tails bump this
                        # as a "chain conflict" accumulator when the chain
                        # is vulnerable to a cut.  Consumed by
                        # EvaluateOrderScore (L584, L711).  Alias below.
_F_SUP_CHAIN_CONFLICT = _F_SUP_SRC_LO   # DAT_00baedd8
_F_TARGET_PROV   = 15   # target province for order scoring (§ScoreOrderSet)
_F_THREAT_TOTAL   = 16   # summed enemy reach on this province (DAT_00baede0);
                         # written only at ProcessTurn.c:1487, read only as
                         # `== 1` / `== 2`.  Never a province id.
_F_MOVE_HISTORY  = 17   # per-source/destination move history (DAT_00baede4)
# Compatibility alias retained for callers outside the package.  The old
# name was a field-identification error; this is not a support count.
_F_SUP_COUNT     = _F_MOVE_HISTORY
_F_SUP_TARGET    = 18   # AssignSupportOrder: assigned target-role province (DAT_00baede8)
_F_ORDER_ASGN    = 20   # dual-use: "support order committed" (1) or convoy chain depth (DAT_00baedf0)
_F_UNIT_REACH_SCORE = 21  # cut-support reach/hold factor (DAT_00baedf4)
_CONVOY_DEPTH_COMPLETE = 5  # _F_ORDER_ASGN value meaning convoy chain is resolved
_F_CUM_SCORE     = 29   # trailing per-order score field (DAT_00baee14)

# Order type constants (g_order_table[prov, _F_ORDER_TYPE])
_ORDER_HLD      = 1
_ORDER_MTO      = 2
_ORDER_SUP_HLD  = 3
_ORDER_SUP_MTO  = 4
_ORDER_CVY      = 5
_ORDER_CTO      = 6
