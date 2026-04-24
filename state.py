import logging
from typing import Any

import numpy as np

logger = logging.getLogger(__name__)

_POWER_NAMES_STATE = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]


def _parse_retreat_order(order_str: str, power: int, prov_to_id: dict) -> dict | None:
    """Parse a DAIDE-style retreat order string into a g_RetreatList record.

    Handles:
      "A PAR R BUR"  → order_type=7 (RTO), dst_province=BUR
      "A PAR D"      → order_type=8 (DSB), dst_province=-1
    """
    parts = order_str.split()
    if len(parts) < 2:
        return None
    unit_char = parts[0].upper()          # 'A' or 'F'
    src_str   = parts[1].split('/')[0]    # strip coast
    src_prov  = prov_to_id.get(src_str, -1)
    if src_prov < 0:
        return None
    unit_type = 0 if unit_char != 'F' else 1

    if len(parts) >= 3:
        action = parts[2].upper()
        if action == 'R' and len(parts) >= 4:
            dst_str  = parts[3].split('/')[0]
            dst_prov = prov_to_id.get(dst_str, -1)
            return {
                'src_province': src_prov, 'unit_type': unit_type, 'power': power,
                'order_type': 7, 'dst_province': dst_prov,
                'sup_src': -1, 'sup_dst': -1, 'endgame_flag': 0,
            }
        if action == 'D':
            return {
                'src_province': src_prov, 'unit_type': unit_type, 'power': power,
                'order_type': 8, 'dst_province': -1,
                'sup_src': -1, 'sup_dst': -1, 'endgame_flag': 0,
            }
    return None


def _parse_movement_order(order_str: str, power: int, prov_to_id: dict) -> dict | None:
    """Parse a DAIDE-style movement order string into a g_OrderHistList record.

    Handles MTO, SUP-HLD, SUP-MTO, CVY, CTO, HLD.
    """
    parts = order_str.split()
    if len(parts) < 2:
        return None
    unit_char = parts[0].upper()
    src_str   = parts[1].split('/')[0]
    src_prov  = prov_to_id.get(src_str, -1)
    if src_prov < 0:
        return None
    unit_type = 0 if unit_char != 'F' else 1

    rec = {
        'src_province': src_prov, 'unit_type': unit_type, 'power': power,
        'order_type': 1,  # HLD default
        'dst_province': -1, 'sup_src': -1, 'sup_dst': -1, 'endgame_flag': 0,
    }

    if len(parts) == 2 or (len(parts) == 3 and parts[2].upper() == 'H'):
        rec['order_type'] = 1  # HLD
        return rec

    if len(parts) >= 3:
        action = parts[2].upper()
        if action == '-':
            # MTO or CTO
            if len(parts) >= 4:
                dst_str  = parts[3].split('/')[0]
                dst_prov = prov_to_id.get(dst_str, -1)
                rec['dst_province'] = dst_prov
                # 'VIA' suffix → convoy transport (CTO type 6)
                rec['order_type'] = 6 if len(parts) > 4 and parts[4].upper() == 'VIA' else 2
            return rec
        if action == 'S':
            # Support: "A PAR S A BUR" (SUP-HLD) or "A PAR S A BRE - PIE" (SUP-MTO)
            # Supported unit starts at parts[3] (skip optional unit-type token at parts[3])
            # Diplomacy library format: "A PAR S A BUR" or "A PAR S F NTH - NWG"
            if len(parts) >= 4:
                sup_src_str = parts[3].split('/')[0] if parts[3].upper() not in ('A', 'F') else (parts[4].split('/')[0] if len(parts) > 4 else '')
                # Handle "A PAR S A BUR" where parts[3]='A', parts[4]='BUR'
                idx = 3
                if parts[idx].upper() in ('A', 'F'):
                    idx += 1
                if idx < len(parts):
                    sup_src_str = parts[idx].split('/')[0]
                    sup_src = prov_to_id.get(sup_src_str, -1)
                    rec['sup_src'] = sup_src
                    # Check for '-' (SUP-MTO)
                    if idx + 1 < len(parts) and parts[idx + 1] == '-' and idx + 2 < len(parts):
                        sup_dst_str = parts[idx + 2].split('/')[0]
                        rec['sup_dst'] = prov_to_id.get(sup_dst_str, -1)
                        rec['order_type'] = 4  # SUP-MTO
                    else:
                        rec['order_type'] = 3  # SUP-HLD
            return rec
        if action == 'C':
            # CVY: "F NTH C A LON - HOL"
            rec['order_type'] = 5
            return rec
    return rec


class InnerGameState:
    # Dynamically-populated attributes (may be assigned lazily by other modules
    # via `hasattr(...)` guards). Declared here so the static type checker knows
    # they exist on every InnerGameState instance.
    g_ActiveDmzList: "Any"
    g_ActiveDmzMap: "Any"
    g_AllianceOrders: "Any"
    # g_AllianceOrdersPresent removed: phantom global. The C binary reads
    # `&DAT_00bb6d00 + p*0xc` which is the std::set _Mysize field of slot p
    # inside g_AllianceOrders, not a separate array. Use len(...) instead.
    g_AllyOrderHistory: "Any"
    g_ConvoyRoute: "Any"
    g_CoopFlag: "Any"
    g_DesigCountA: "Any"
    g_DesigCountB: "Any"
    g_DesigListA: "Any"
    g_DesigListB: "Any"
    g_DmzOrderList: "Any"
    # g_GeneralOrdersPresent removed: phantom global (see g_AllianceOrdersPresent).
    g_LoneLeadPower: "Any"
    g_MoveTimeLimit: "Any"
    g_OrderHistory: "Any"
    g_OtherScore: "Any"
    g_PressCandidateA: "Any"
    g_PressCandidateB: "Any"
    g_PressThreshRandom: "Any"
    g_ProposalHistoryMap: "Any"
    g_RingCoast_A: "Any"
    g_RingCoast_B: "Any"
    g_RingCoast_C: "Any"
    g_RingConvoyEnabled: "Any"
    g_RingConvoyScore: "Any"
    g_RingProv_A: "Any"
    g_RingProv_B: "Any"
    g_RingProv_C: "Any"
    g_SomeCoopScore: "Any"
    g_StabMode: "Any"
    g_SupportOpportunitiesSet: "Any"
    g_SupportProposals: "Any"
    g_SupportTrustAdj: "Any"
    g_TrialList2: "Any"
    g_TrialMap: "Any"
    g_UnitPresence: "Any"
    g_VictoryThreshold: "Any"
    g_XdoDestBySender: "Any"
    g_XdoGlobalDestMap: "Any"
    g_XdoSupHldMap: "Any"
    g_baed6d: "Any"
    g_one_shot_press: "Any"
    g_pending_orders_A: "Any"
    g_pending_orders_B: "Any"
    g_trust_counter: "Any"
    g_turn_start_time: "Any"
    g_xdo_candidate_list: "Any"

    def __init__(self):
        # 1. Global Game State
        self.g_NearEndGameFactor = 0.0
        self.g_DeceitLevel = 0
        self.g_MaxProvinceScore = np.zeros(256, dtype=np.float64)
        self.g_MinScore = np.zeros(256, dtype=np.float64)
        
        # 2. Heuristics & Map Variables
        # DAT_006040e8[pow*0x800+prov*8] — int64[pow*256+prov]
        self.g_AttackCount = np.zeros((7, 256), dtype=np.float64)
        # DAT_005a48e8[pow*0x800+prov*8] — int64[pow*256+prov]; >10 = danger zone
        self.g_AttackHistory = np.zeros((7, 256), dtype=np.float64)
        # DAT_0055b0e8[pow*0x800+prov*8] — int64[pow*256+prov]
        self.g_DefenseScore = np.zeros((7, 256), dtype=np.float64)
        # DAT_004f6ce8[pow*0x800+prov*8] — int64[pow*256+prov]; 1 = enemy unit present
        self.g_EnemyPresence = np.zeros((7, 256), dtype=np.int32)
        # DAT_00535ce8[pow*0x800+prov*8] — int64[pow*256+prov]; 1 = enemy can reach
        self.g_EnemyReachScore = np.zeros((7, 256), dtype=np.int32)
        self.g_SCOwnership = np.zeros((7, 256), dtype=np.int32)
        self.g_TargetFlag = np.zeros((7, 256), dtype=np.int32)
        
        self.g_InfluenceMatrix_Raw = np.zeros((7, 7), dtype=np.float64)
        self.g_InfluenceMatrix = np.zeros((7, 7), dtype=np.float64)
        self.g_AllianceScore = np.zeros((7, 7), dtype=np.float64)
        self.g_AllyTrustScore = np.zeros((7, 7), dtype=np.float64)
        self.g_AllyMatrix = np.zeros((7, 7), dtype=np.int32)
        
        # Buffers for Heat Diffusion
        self.g_CandidateScores = np.zeros((7, 256), dtype=np.float64)
        # DAT_004ec2f0/f4[pow*0x800+prov*8] — movement heat scores (primary copy)
        self.g_HeatMovement = np.zeros((7, 256), dtype=np.float64)
        # DAT_005af0e8/ec[pow*0x800+prov*8] — second copy of movement heat scores
        self.g_HeatMovement_B = np.zeros((7, 256), dtype=np.float64)
        # DAT_004d62f0/f4[pow*0x100+prov] — BFS-accumulated influence heat score
        self.g_HeatScore = np.zeros((7, 256), dtype=np.float64)
        self.g_GlobalProvinceScore = np.zeros(256, dtype=np.float64)

        # DAT_00b76a28[pow*0x40+prov] — Albert's influence / owner's influence ratio
        # double[power*0x40+province]; values > 1.0 mean Albert projects more influence
        self.g_InfluenceRatio = np.zeros((7, 256), dtype=np.float64)
        # DAT_004e1af0/f4[pow*0x100+prov] — reachable-unit count per province
        self.g_UnitAdjacencyCount = np.zeros((7, 256), dtype=np.int64)
        # DAT_00b75578[pow*0x3f+other] — raw adjacency contact count per power pair
        self.g_ContactCount = np.zeros((7, 7), dtype=np.int32)
        # DAT_00b755cc[pow*0x3f+other] — weighted adjacency contact count
        self.g_ContactWeighted = np.zeros((7, 7), dtype=np.int32)
        # DAT_00b75620[pow*0x3f+other] — owner-side adjacency count
        self.g_ContactOwnerCount = np.zeros((7, 7), dtype=np.int32)
        # DAT_00ba2f70[province] — per-province SC owner index; -1 = unoccupied
        # Alias of g_ScOwner (written by SnapshotProvinceState / ParseNOW)
        self.g_ScOwner = np.full(256, -1, dtype=np.int32)
        # DAT_004DA2F0[pow*0x100+prov] — 2D history-gate array; int64[pow*0x100+prov]
        # Non-zero means activity recorded for (power, province); gate in Pass 5
        # of ApplyInfluenceScores. Writer TBD (see Q-AIS-NEW-3 in OpenQuestions.md).
        self.g_HistoryGate = np.zeros((7, 256), dtype=np.int64)
        
        # 3. Adjacency lists and internal maps
        self.g_ProvinceAccessFlag = np.zeros((7, 256), dtype=np.int32)
        self.g_CoverageFlag = np.zeros((7, 256), dtype=np.int32)
        self.g_ConvoyReachCount = np.zeros((7, 256), dtype=np.int32)
        self.g_OwnReachScore = np.zeros((7, 256), dtype=np.int32)
        self.g_TotalReachScore = np.zeros((7, 256), dtype=np.int32)
        self.g_EnemyMobilityCount = np.zeros((7, 256), dtype=np.int32)
        self.g_ThreatLevel = np.zeros((7, 256), dtype=np.int32)
        # DAT_00520ce8/ec[pow*0x100+prov] — enemy pressure/threat intensity per province
        self.g_EnemyPressure = np.zeros((7, 256), dtype=np.int32)
        # DAT_006190e8/ec[pow*0x40+prov*8] — {0} = no build pending; gate in AssignSupportOrder LAB_0044150f
        self.g_BuildOrderPending = np.zeros((7, 256), dtype=np.int32)
        self.g_ProvinceWeight = np.zeros((7, 256), dtype=np.float64)
        
        # Flags
        self.g_UniformMode = 0
        self.win_threshold = 18
        self.ScoreCurrent = 0
        self.ScoreBaseline = 0

        # DAT_005460e8[(prov+pow*0x40)*2] — float64[pow*256+prov]
        self.g_ProximityScore = np.zeros((7, 256), dtype=np.float64)

        # 4. Monte Carlo Evaluation Variables

        # g_OrderTable: DAT_00baeda0[prov*0x1e + field*4]
        # 30-field per-province order state; fields defined by _F_* constants in monte_carlo.py
        self.g_OrderTable = np.zeros((256, 30), dtype=np.float64)

        # DAT_00baedb8[prov*0x1e] — order table [6]: convoy-chain depth score OR support order score lo-word (dual-use)
        self.g_ConvoyChainScore = np.zeros(256, dtype=np.float64)
        # DAT_00baedbc[prov*0x1e] — order table [7]: hi-word companion (dual-use g_OrderScoreHi)
        self.g_OrderScoreHi = np.zeros(256, dtype=np.float64)
        # DAT_00baedf4[prov*0x1e] — unit adjacency reach score per province
        self.g_UnitReachScore = np.zeros(256, dtype=np.float64)
        # DAT_00baedf8[prov*0x1e] — cut-support risk: <0 = own unit, >0 = enemy
        self.g_CutSupportRisk = np.zeros(256, dtype=np.float64)
        # DAT_00baeddc[prov*0x1e] — number of units demanding support to this province
        self.g_SupportDemand = np.zeros(256, dtype=np.int32)
        # DAT_00ba3770[province] — convoy source province score (0xffffffff = unset)
        self.g_ConvoySourceProv = np.zeros(256, dtype=np.float64)

        # DAT_00633e90[province] — convoy active flag; set to 1 by BuildOrder_SUP_MTO /
        # BuildOrder_SUP_HLD when a support order targets a convoy fleet; read in Phase 1e
        # as a fallback acceptance gate.  Reset to 0 at the start of each trial.
        self.g_ConvoyActiveFlag = np.zeros(256, dtype=np.int32)

        # DAT_00ba3b70[province] — per-province score flag; set to 1 by RegisterConvoyFleet
        # for adjacent provinces meeting the army-adj + target criteria; reset per trial.
        self.g_ProvinceScoreTrial = np.zeros(256, dtype=np.int32)
        # DAT_00ba3f70[province] — count of own AMY-adjacent provinces; populated per trial
        # in Phase 1b unit scan; reset to 0 at the start of each trial.
        self.g_ArmyAdjCount = np.zeros(256, dtype=np.int32)
        # Per-trial set of fleet provinces already processed by RegisterConvoyFleet.
        # Mirrors the char flag at this->ptr_at_8 + fleet * 0x24 + 4 in the C++ original.
        self.g_ConvoyFleetRegistered: set = set()

        # Albert+0x4CFC — sorted convoy fleet candidate list: list[tuple[int, int]] = (score, prov).
        # Populated by ScoreConvoyFleet (FUN_00419790) in process_turn Phase 1g;
        # drained by MoveCandidate (FUN_00411cf0) in Phase 2.  Sorted ascending by
        # score (remaining fleet count); Phase 2 processes from the front (lowest score).
        self.g_ConvoyFleetCandidates: list = []

        # DAT_00bb65a0 / DAT_00bb65a4 — convoy destination list.
        # Populated by ConvoyList_Insert (FUN_0041c340) in BuildOrder_MTO/BuildConvoyOrders;
        # cleared at the start of each trial.  Each entry is a dst province index.
        self.g_ConvoyDstList: list = []

        # Companion map dst_province → src_province written by ConvoyList_Insert
        # (the node field set via *ppiVar5 = src immediately after insert).
        self.g_ConvoyDstToSrc: dict = {}

        # Current game season token: 'SPR'|'SUM'|'FAL'|'AUT'|'WIN'
        self.g_season = 'SPR'

        self.FinalScoreSet = np.zeros((7, 256), dtype=np.float64)
        self.g_WinterScore_A = np.zeros(256, dtype=np.float64)
        self.g_WinterScore_B = np.zeros(256, dtype=np.float64)

        self.g_HoldWeight = np.zeros(256, dtype=np.float64)
        self.g_UnitMoveProb = np.zeros(256, dtype=np.float64)
        self.g_FleetSupportScore = np.zeros(256, dtype=np.float64)

        # DAT_00bc1e1c — set of province IDs that are scoring / build targets;
        # consumed by EnumerateConvoyReach (BFS expansion gating).
        # Populated by the order-candidate pipeline before EnumerateConvoyReach runs.
        self.g_BuildCandidateList: set = set()

        # this+0x2478 — build-candidate list for WIN phase; populated by WIN handler,
        # cleared by ResetPerTrialState at the start of each MC trial.
        # Each entry is a DAIDE order string (e.g. '( ENG FLT LON ) BLD').
        self.g_build_order_list: list = []
        # this+0x2480 — waive count for WIN phase; cleared by ResetPerTrialState.
        self.g_waive_count: int = 0

        # DAT_00baed68 — press-mode flag; 1 = ComputePress runs this turn, 0 = off
        self.g_PressFlag: int = 0

        # DAT_004d2e10/14 — g_AllyDesignation_A: int64[province], power booked as ally-A for
        # that province; -1 = none. Read by BuildSupportProposals to exclude the designated
        # ally-A power from supporter candidates.
        self.g_AllyDesignation_A = np.full(256, -1, dtype=np.int64)

        # DAT_004d2610/14 — g_AllyDesignation_B: int64[province], power booked as ally-B for
        # that province; -1 = none. Used by BuildSupportProposals for priority-8 (defend own SC)
        # detection and to exclude the designated ally-B power from supporter candidates.
        self.g_AllyDesignation_B = np.full(256, -1, dtype=np.int64)

        # DAT_004d3610/14 — g_AllyDesignation_C: int64[province], power booked as ally-C for
        # that province; -1 = none. Third designation slot; read by check_order_alliance
        # (FUN_0041d360) and cleared during late-game retreat.
        self.g_AllyDesignation_C = np.full(256, -1, dtype=np.int64)

        # DAT_00bb6f28/2c — g_ally_promise_list: per-power ally promise records.
        # dict[power_idx -> list[dict{'dest_prov': int, ...}]]
        # Cleared per turn; written by alliance management; read by check_order_alliance
        # to detect province-ordering conflicts against outstanding ally promises.
        self.g_ally_promise_list: dict = {}

        # DAT_00bb7028/2c — g_ally_counter_list: per-power counter-proposal records.
        # dict[power_idx -> list[dict{'dest_prov': int, ...}]]
        # Cleared per turn; written by alliance management; read by check_order_alliance
        # post-loop to verify counter-list consistency for the destination power.
        self.g_ally_counter_list: dict = {}

        # DAT_00baed94 — proposal history; set of int keys
        # key = (unit2_prov * 1000 + own_prov) * 1000 + dest
        # Prevents duplicate XDO support proposals within a turn.
        self.g_ProposalHistory: set = set()

        # DAT_00baeb70[from_power + to_power * 0x15] — 1 = XDO press sent this turn.
        # Indexed as [from_power, to_power]; shape (7, 7).
        self.g_XdoPressSent = np.zeros((7, 7), dtype=np.int32)

        # Accumulated XDO support-proposal dicts emitted by BuildSupportProposals.
        # Each dict: {'type','supporter_prov','supporter_power','mover_prov',
        #             'dest','priority','from_power','to_power'}
        self.g_XdoPressProposals: list = []

        # DAT_00bb67f8[power*0xc] — per-power MTO/CTO attacker scoring map.
        # ScoreSupportOpp (FUN_00404fd0): key = dest_prov, value = int score.
        self.g_xdo_mto_opp_score: dict = {}

        # DAT_00bb69f8[prov*0xc] — per-supporting-unit-province SUP-MTO scoring map.
        # ScoreSupportOpp (FUN_00404fd0): key = sup_power, value = int score.
        self.g_xdo_sup_mto_score: dict = {}

        # DAT_00ba1fb0[province] — safe-reach score per province.
        # Set to max sorted-set rank of reachable uncontested provinces; 0xffffffff = no safe move.
        # Written by ComputeSafeReach; uint32 sentinel matches original C 0xffffffff.
        self.g_SafeReachScore = np.full(256, 0xffffffff, dtype=np.uint32)

        # DAT_005658e8[pow*0x40+prov] — allied units' reachability (trust > 0).
        # Written by EnumerateHoldOrders reach loop when trust > 0.
        self.g_AllyReachScore = np.zeros((7, 256), dtype=np.float64)

        # DAT_005ba0e8[pow*0x100+prov] — provinces reachable via 2-hop move (support chain reach).
        # Written by ScoreOrderCandidates_AllPowers adjacency expansion.
        self.g_SupportReach = np.zeros((7, 256), dtype=np.float64)

        # DAT_005c48e8[pow*0x100+prov] — provinces reachable via convoy chain.
        # Written by ScoreOrderCandidates_AllPowers BFS convoy expansion.
        self.g_ConvoyReach = np.zeros((7, 256), dtype=np.float64)

        # DAT_005cf0e8[pow*0x100+prov] — provinces convoy-supportable via a fleet unit.
        # Written by ScoreOrderCandidates_AllPowers fleet-support analysis.
        self.g_ConvoySupport = np.zeros((7, 256), dtype=np.float64)

        # DAT_00baed69 — 1 = another power is close to solo victory (defensive mode).
        self.g_OtherPowerLeadFlag: int = 0

        # DAT_0062be94 — early-game adjacency score accumulator (Turn 1 only).
        self.g_EarlyGameBonus: int = 0

        # DAT_00bbf60c — global list of candidate proposal records.
        # Each entry: {'power', 'orders', 'score', 'heat_scores', 'deviation', 'pressure_cost'}.
        self.g_CandidateRecordList: list = []

        # DAT_00bb6cf8[pow*0xc] — per-power general candidate order sequences.
        # Maps power_idx -> [order_seq, ...] where each order_seq is a dict with
        # at least {'type': str}.  Cleared by _destroy_candidate_tree (FUN_00410cf0)
        # at the start of each ScoreOrderCandidates pass.
        self.g_GeneralOrders: dict = {}

        # DAT_00bb65b4/b8 — cached std::set iterator (g_LastMTOInsert).
        # Stores (type: int, province: int) of the last MTO/fleet insert, or None = set.end().
        # AssignSupportOrder reads this to undo a conflicting fleet support commitment.
        self.g_LastMTOInsert: tuple | None = None

        # DAT_00bb66f8[power*0xc] — per-power deviation-detection tree.
        # Maps (power, prov) -> expected order type; 0 = no expectation recorded.
        self.g_DeviationTree: dict = {}

        # DAT_00bb6e00 — order-position map: set of province IDs that have a committed SUB entry.
        # Populated by DispatchSingleOrder; used to detect missing order assignments.
        self.g_SubOrderMap: set = set()

        # DAT_00bb69fc[power*3] — alternate order list per power.
        # Maps power -> set of province IDs on the alternate order candidate list.
        self.g_AltOrderList: dict = {}

        # DAT_005b98e8/ec[province] — per-province rescore sentinel.
        # Initialised to -1 (0xffffffff) by GenerateOrders; written to 0/1 by
        # ScoreOrderCandidates_AllPowers during the MC trial loop.
        self.g_NeedsRescore = np.full(256, -1, dtype=np.int64)

        # ── ScoreOrderCandidates_AllPowers extra globals (ported 2026-04-14) ──
        # DAT_0055b0e8/ec[(prov+pow*0x40)*2] — per-power province max score (int64)
        self.g_MaxProvScorePerPower = np.full((7, 256), -(1 << 62), dtype=np.int64)
        # DAT_005508e8/ec — per-power province min score (int64)
        self.g_MinProvScorePerPower = np.full((7, 256), (1 << 62), dtype=np.int64)
        # DAT_005cf0e8/ec[(prov+pow*0x100)*2] — support-candidate mark
        self.g_SupportCandidateMark = np.zeros((7, 256), dtype=np.int64)
        # DAT_005700e8/ec[(prov+pow*0x40)*2] — best-reachable-via-enemy threat path score
        self.g_ThreatPathScore = np.zeros((7, 256), dtype=np.int64)
        # DAT_005ee8e8/ec — classified-province secondary marker (0=unclassified, -1=flanked)
        self.g_TargetFlag2 = np.zeros((7, 256), dtype=np.int64)
        # DAT_0052b4e8/ec — secondary attack counter (paired with g_AttackCount)
        self.g_AttackCount2 = np.zeros((7, 256), dtype=np.int64)
        # DAT_00535ce8/ec — secondary enemy pressure (additional to g_EnemyReachScore)
        self.g_EnemyPressureSecondary = np.zeros((7, 256), dtype=np.int64)
        # (g_AllyHistoryCount was a stale alias for g_RelationScore / DAT_00634e90;
        #  removed 2026-04-14 — see g_RelationScore declaration below.)
        # DAT_004d2e10/14 — ally-designation-E counterpart (paired with _A)
        self.g_AllyDesignation_E = np.full(256, -1, dtype=np.int64)
        # DAT_005c48e8/ec — direct reach flag (1-hop BFS target)
        self.g_DirectReachFlag = np.zeros((7, 256), dtype=np.int64)
        # DAT_005ba0e8/ec — extended reach flag (2-hop via unit)
        self.g_ExtendedReachFlag = np.zeros((7, 256), dtype=np.int64)
        # DAT_005b98e8/ec — top-reach flag (per-province, shared with NeedsRescore codepath)
        self.g_TopReachFlag = np.zeros(256, dtype=np.int64)
        # g_ProvTargetFlag[pow, prov] — primary target classification (1/2/-10/0)
        self.g_ProvTargetFlag = np.zeros((7, 256), dtype=np.int64)

        # g_OpeningTarget[power] — per-power opening deception target province.
        # -1 = no target.  Set in SPR when g_DeceitLevel == 1.
        self.g_OpeningTarget = np.full(7, -1, dtype=np.int32)

        # ── CAL_BOARD globals ────────────────────────────────────────────────
        # DAT_006238e8[power] — pow(sc_count, sc_count)*100+1
        self.g_PowerExpScore = np.zeros(7, dtype=np.float64)
        # DAT_0062e360[power] — sc_count*100/total
        self.g_SCPercent = np.zeros(7, dtype=np.float64)
        # DAT_004cf568[power] — 1 = this power is designated enemy this turn
        self.g_EnemyFlag = np.zeros(7, dtype=np.int32)
        # DAT_00633ec0[power] — count of genuine enemies for each power
        self.g_EnemyCount = np.zeros(7, dtype=np.int32)
        # DAT_00633e68[power] — 1 = ally is distressed (attacked by both top enemies)
        self.g_AllyDistressFlag = np.zeros(7, dtype=np.int32)
        # DAT_00633780[pow*21+other] — -2=self, -1=unranked, 1-N=rank
        self.g_RankMatrix = np.full((7, 7), -1, dtype=np.int32)
        np.fill_diagonal(self.g_RankMatrix, -2)
        # DAT_00baed6a — 1 = Albert dominant leader (>75% SC influence, gap >2%)
        self.g_LeadingFlag: int = 0
        # DAT_0062480c — index of power close to solo victory
        self.g_NearVictoryPower: int = -1
        # DAT_00baed2a — 1 = send DRW proposal this turn
        self.g_RequestDrawFlag: int = 0
        # DAT_00baed30 — 1 = map static for many turns → request draw
        self.g_StaticMapFlag: int = 0
        # DAT_00baed6b — 1 = own power exactly 1 SC from winning
        self.g_OneScFromWin: int = 0
        # DAT_00633f18[pow*5+rank] — top-N preferred alliance targets (1-indexed)
        self.g_AllyPrefRanking = np.full((7, 5), -1, dtype=np.int32)
        # DAT_006340c0[pow*21+other] — selection-sort visit flag: -1=unranked, -2=self, 1-N=rank
        self.g_InfluenceRankFlag = np.full((7, 7), -1, dtype=np.int32)
        np.fill_diagonal(self.g_InfluenceRankFlag, -2)
        # DAT_00baed6c — 1 = war mode (a power has >80% SCs)
        self.g_WarModeFlag: int = 0
        # DAT_00baed5f — 1 = Albert was stabbed; triggers enemy-desired mode
        self.g_StabbedFlag: int = 0
        # DAT_00baed69 — 1 = another power is close to solo victory
        # (already defined as g_OtherPowerLeadFlag above)
        # g_InfluenceMatrix_Alt is the same array as g_InfluenceMatrix (alias)
        # DAT_00b81ff0 — trust-adjusted, noise-perturbed, row-normalised influence matrix
        # (self.g_InfluenceMatrix already declared above)

        # Own power index (0-based); set at turn start by AlbertBot from power_name.
        # C: *(byte *)(state->inner + 0x2424)
        self.albert_power_idx: int = 0

        # DAT_00baed2b — result of PrepareDrawVoteSet / ComputeDrawVote.
        # 1 = propose DRW this turn; 0 = do not.
        self.g_draw_sent: int = 0

        # Current SC counts and targets derived each turn from g_SCOwnership
        # sc_count[power] — int[7]; filled by synchronize_from_game / cal_board
        self.sc_count = np.zeros(7, dtype=np.int32)
        # target_sc_count[power] — int[7]; win threshold per power (all 18 in std Dip)
        self.target_sc_count = np.full(7, 18, dtype=np.int32)

        # DAT_004cf4c0[power*2] — g_EnemySlot priority queue (top-3 enemies, -1=empty)
        self.g_EnemySlot: Any = np.full(3, -1, dtype=np.int32)

        # ── PostProcessOrders (move-history matrix) ──────────────────────────
        # DAT_00635578[power*0x10000+src*0x100+dst] — fading move-history table
        # Decays 3/turn; +10 on successful support; zeroed on disruption.
        self.g_MoveHistoryMatrix = np.zeros((7, 256, 256), dtype=np.int32)

        # ── ComputePress globals ─────────────────────────────────────────────
        # DAT_00b85768[power*0x100+province] — bool: 1 = power presses this province
        self.g_PressMatrix = np.zeros((7, 256), dtype=np.int32)
        # DAT_00b85710[power] — count of provinces this power presses
        self.g_PressCount = np.zeros(7, dtype=np.int32)

        # ── ProposeDMZ globals ───────────────────────────────────────────────
        # DAT_00bb7130 — per-(power,province) proposal send-count tracking
        self.g_SentProposals: dict = {}    # {(power, province): count}
        # DAT_004c6bd4 / 4 − 4 — randomized DMZ aggressiveness ∈ [−4, 20]
        self.g_DMZAggressiveness: int = 0
        # Press proposal candidate slate built by ApplyInfluenceScores / ProposeDMZ
        # Each entry: {'flag1': bool, 'flag2': bool, 'flag3': bool, 'province': int,
        #              'ally_power': int, 'score': int, 'done': bool}
        self.g_OrderList: list = []

        # Retreat order list iterated by _build_gof_seq FAL/AUT branch (this+0x245c/2460).
        # Each entry: {'province': int, 'unit_type': str, 'unit_coast': str,
        #              'power': int, 'order_type': int,
        #              'dest_province': int, 'dest_coast': int}
        # order_type: 0 or 8 = DSB, 7 = RTO.  Populated before _send_gof is called.
        self.g_retreat_order_list: list = []

        # Albert+0x248c/0x2490 — g_RetreatList: ordered-set of retreat-phase order nodes.
        # Written by ORD handler when season == SUM or AUT; cleared at retreat-phase start.
        # Each entry: {'src_province': int, 'unit_type': int, 'power': int,
        #              'order_type': int (2=MTO,3=SUP-HLD,4=SUP-MTO,6=CTO,7=RTO,8=DSB),
        #              'dst_province': int, 'sup_src': int, 'sup_dst': int, 'endgame_flag': int}
        # In Python, populated from game.order_history at synchronize_from_game time.
        self.g_RetreatList: list = []

        # Albert+0x2498/0x249c — g_OrderHistList: ordered-set of movement-phase order nodes.
        # Written by ORD handler when season == SPR or FAL; cleared at retreat-phase start.
        # Same node layout as g_RetreatList.  Populated from game.order_history.
        self.g_OrderHistList: list = []

        # Lazy-built reverse map: province_id (int) → province name (str).
        # Built on first use from prov_to_id; cached here for all callers.
        self._id_to_prov: dict = {}

        # Home supply centers per power: dict[power_idx → frozenset[prov_id]].
        # Populated once during synchronize_from_game from game.map.homes.
        # Used by populate_build_candidates to gate legal build locations.
        self.home_centers: dict = {}

        # ── UpdateScoreState / BuildAndSendSUB globals ───────────────────────
        # DAT_0062e460[power] — unit count; non-zero = power has live units
        self.g_UnitCount = np.zeros(7, dtype=np.int32)
        # DAT_00bc1e04 — current round number
        self.g_CurrentRound: int = 0
        # DAT_00bc1e00 per-power game-board round records; power → last seen round
        # Used by UpdateScoreState to detect stale-round ally order tables.
        self.g_PowerRoundRecord: dict = {}  # {power_idx: round_number}
        # DAT_00baed48 — cumulative score counter
        self.g_CumScore: int = 0
        # DAT_0062d34c — score baseline (subtracted from cumulative)
        self.g_ScoreBaseline: int = 0
        # DAT_0062e4b4 — alternative score accumulator
        self.g_ScoreAlt: int = 0

        # ── CheckTimeLimit globals ───────────────────────────────────────────
        # g_NetworkState+0x20 — MTL timeout flag; set by timer thread when MTL fires
        self.mtl_expired: int = 0

        # ── BuildAndSendSUB globals ──────────────────────────────────────────
        # DAT_00bb65f0 — outer broadcast proposal list
        self.g_BroadcastList: list = []
        # DAT_00baed60 — g_BroadcastList size watermark after RegisterReceivedPress
        self.g_BroadcastListWatermark: int = 0
        # DAT_00bb6df4 — XDO proposal dedup set (compound order-seq keys;
        # approximated here as per-province set; C uses FUN_00410980/FUN_00419300)
        self.g_XdoProposalList: set = set()
        # DAT_00bb65f8[power*0xc] — per-sender XDO proposal ordered set.
        # Populated by FUN_00419300 in _handle_xdo; sorted list[tuple] per power.
        self.g_XdoProposalBySender: dict = {}
        # DAT_00bb66f8[power*0xc] — per-power NOT-XDO retraction ordered set.
        # Populated by FUN_00419300 in _not_xdo; sorted list[tuple] per power.
        # Note: DAT_00bb66f8 is also mapped to g_DeviationTree (different usage
        # context in RECEIVE_PROPOSAL vs. cal_not_xdo).
        self.g_NotXdoListBySender: dict = {}
        # DAT_004c6bbc — MC trial cap per proposal (difficulty=100 → 30)
        self.g_PressProposalsCap: int = 30
        # DAT_00b95368/58/e0[trial*4] — per-trial score tracking arrays
        self.g_TrialScoreA: list = []
        self.g_TrialScoreB: list = []
        self.g_TrialScoreC: list = []
        # DAT_00bbf690/94[pow*0x3c] — current best order sequence per-power
        self.g_CurrentBestOrder: dict = {}
        # DAT_00bc0a40/44[pow*0xf0] — backup of best orders at best-trial point
        self.g_BestOrderBackup: dict = {}
        # DAT_00baed94/98 — press deal records (earlier proposals received)
        self.g_DealList: list = []
        # DAT_00bb65c8/cc — position analysis list (g_OwnProposalMap in C); each entry:
        #   {'tokens': list, 'token_set': frozenset, 'power_count': int}
        # Cleared each turn.  Used by RECEIVE_PROPOSAL for proposal dedup.
        self.g_PosAnalysisList: list = []
        # DAT_00bb65d4 — accepted proposals this turn (YES results from EvaluatePress)
        self.g_AcceptedProposals: list = []
        # DAT_00bbf638 — alliance-message BST; in Python modelled as a set of
        # power indices inserted by BuildAllianceMsg / receive_proposal.
        self.g_AllianceMsgTree: set = set()
        # DAT_00bb69fc[power*3] — per-power alternate order list
        # (already declared as g_AltOrderList above)
        # g_HistoryCounter > 19 gates some press sending
        self.g_HistoryCounter: int = 0
        # DAT_00bb6e10[p*0xc] — per-power allowed-press-type std::map<ushort>.
        # Populated by process_hst from g_AllowedPressTokenList thresholds.
        # Key = raw DAIDE ushort token int (PCE=0x4A10, ALY=0x4A00, etc.).
        self.g_press_history: dict = {}  # {power_int: set[int]}

        # ── DispatchScheduledPress globals ───────────────────────────────────
        # DAT_00bb65c0 — master scheduled press list
        # Each entry: {'scheduled_time': float, 'press_type': str,
        #              'data': list, 'sent': bool}
        self.g_MasterOrderList: list = []
        # DAT_00ba2884:ba2880 — session start time (int64 Unix timestamp)
        self.g_SessionStartTime: float = 0.0
        # DAT_00ba2858:ba285c — base wait threshold (seconds); GOF fires when
        #   elapsed > g_base_wait_time + 25 s  (FUN_00443ed0)
        self.g_base_wait_time: float = 0.0
        # DAT_00bb65c4 — nonzero while the game engine is actively processing
        #   (FUN_00443ed0 polls this before sending fallback GOF)
        self.g_processing_active: int = 0
        # DAT_00ba2860:ba2864 — elapsed time recorded by FUN_00443ed0 at GOF send
        self.g_elapsed_press_time: float = 0.0
        # DAT_00baed32 — 0 = randomised delay; non-zero = send immediately at elapsed
        self.g_PressInstant: int = 0
        # DAT_00624ef4 — move time limit in seconds; 0 = no deadline
        self.g_MoveTimeLimitSec: int = 0

        # ── CancelPriorPress globals ─────────────────────────────────────────
        # DAT_004c6ce4 — prior press token to cancel (NOT message)
        self.g_prior_press_token: object = None
        # DAT_00baed47 — once-per-turn send guard
        self.g_cancel_press_sent: int = 0

        # ── EvaluateAllianceScore scratch ────────────────────────────────────
        # Computed per turn; shape (7,) — per-power desirability score
        self.g_AllianceDesirability = np.zeros(7, dtype=np.float64)

        # ── FRIENDLY globals ─────────────────────────────────────────────────
        # DAT_004d552c[pow*21+other] — hi-word of ally trust score (≥5 = full trust threshold)
        # Paired with g_AllyTrustScore (lo-word); both int.  Alliance upgrades when hi≥5.
        self.g_AllyTrustScore_Hi = np.zeros((7, 7), dtype=np.int32)

        # DAT_00634e90[pow*21+other] — relationship score: −50=hated, 0=neutral, +50=allied
        self.g_RelationScore = np.zeros((7, 7), dtype=np.int32)
        # Cumulative relation history (UpdateRelationHistory / FUN_0040d7e0 accumulator)
        self.g_RelationHistory = np.zeros((7, 7), dtype=np.int32)
        # DAT_0062cc68[pow*21+other] — 1 = pow stabbed other this game
        self.g_StabFlag = np.zeros((7, 7), dtype=np.int32)
        # DAT_0062b0c8[pow*21+other] — 1 = cease-fire declared between pow and other
        self.g_CeaseFire = np.zeros((7, 7), dtype=np.int32)
        # DAT_0062be98[pow*21+other] — cooperation score flag (fall/autumn season)
        self.g_CoopScoreFlag_B = np.zeros((7, 7), dtype=np.int32)
        # DAT_0062a9e0[pow*21+other] — 1 = peace overture signal received from other
        self.g_PeaceSignal = np.zeros((7, 7), dtype=np.int32)
        # DAT_0062b7b0[pow*21+other] — non-zero = neutral/cease-fire state suppresses relation gain
        self.g_NeutralFlag = np.zeros((7, 7), dtype=np.int32)
        # DAT_0062a2f8[pow*21+other] — count of consecutive stab-penalty steps applied
        self.g_StabCounter = np.zeros((7, 7), dtype=np.int32)
        # DAT_0062c580[pow*21+other] — cooperation score flag (spring/summer season)
        self.g_CoopScoreFlag_A = np.zeros((7, 7), dtype=np.int32)
        # DAT_004d4610/14[pow*21+other] — extended trust lo/hi words (cleared for eliminated)
        self.g_TrustExtended_Lo = np.zeros((7, 7), dtype=np.int32)
        self.g_TrustExtended_Hi = np.zeros((7, 7), dtype=np.int32)

        # ── PostProcessOrders globals ────────────────────────────────────────
        # Submitted-order list filled by DispatchSingleOrder / SUB handling:
        # each entry: {'power': int, 'src_prov': int, 'dst_prov': int,
        #              'flag_A': bool, 'flag_B': bool, 'flag_C': bool}
        self.g_SubmittedOrderList: list = []

        self.prov_to_id = {}
        self.adj_matrix = {}
        self.unit_info = {} # prov_id -> {'power': int, 'type': 'A'/'F', 'coast': str}
        # Set of province IDs whose underlying province type is 'WATER' (sea zones).
        # Populated once during synchronize_from_game from game.map.area_type().
        # Mirrors the flag at inner_state + prov_id * 0x24 + 4 == '\0' in the C++ original.
        self.water_provinces: frozenset = frozenset()
        # Set of province IDs whose area_type is 'LAND' (landlocked — no fleet access).
        # COAST provinces are in neither water_provinces nor land_provinces.
        self.land_provinces: frozenset = frozenset()

        # ── PhaseHandler snapshots (FUN_0040df20) ────────────────────────────
        # DAT_0062e4b8 — phase×power snapshot of g_AllyTrustScore lo-word
        self.g_TrustSnapshot    = np.zeros((4 * 21, 7), dtype=np.float64)
        # g_AllyTrustScore hi-word snapshot (paired with lo-word per 64-bit struct)
        self.g_TrustSnapshot_Hi = np.zeros((4 * 21, 7), dtype=np.int32)
        # DAT_00631bd8 — phase×power snapshot of g_RelationScore (DAT_00634e90)
        self.g_InfluenceSnapshot = np.zeros((4 * 21, 7), dtype=np.int32)

        # ── MOVE_ANALYSIS / HOSTILITY opening-phase globals ──────────────────
        # DAT_00baed4x — opening sticky-mode flag; 1 = single original enemy found
        self.g_OpeningStickyMode: int = 0
        # DAT_00baed4x — power index of identified single original enemy
        self.g_OpeningEnemy: int = -1
        # DAT_00baed45 — 1 = best ally is fully pressured this turn
        self.g_AllyUnderAttack: int = 0
        # DAT_004c6bc4/c8/cc — top-3 opening ally candidates (-1 = empty)
        self.g_BestAllySlot0: int = -1
        self.g_BestAllySlot1: int = -1
        self.g_BestAllySlot2: int = -1
        # DAT_00baed42 — set when 3rd-proximity ally randomly selected
        self.g_TripleFrontMode2: int = 0
        # DAT_00baed43 — set when all-front mode selected (≥ 75 random roll)
        self.g_TripleFrontFlag: int = 0

        # ── HOSTILITY globals (FUN_~0x42F200) ────────────────────────────────
        # DAT_00b9fdd8[power] — best mutual enemy per power (-1 = none)
        self.g_MutualEnemyTable = np.full(7, -1, dtype=np.int32)
        # DAT_004cf4c0[power] — betrayal counter; increments when formerly hostile goes neutral
        self.g_BetrayalCounter  = np.zeros(7, dtype=np.int64)
        # DAT_004d55c8[power] — ally press dispatch counter (reset on first press turn)
        self.g_AllyPressCount   = np.zeros(7, dtype=np.int32)
        # DAT_004d6248[power] — ally press hi-word counter
        self.g_AllyPressHi      = np.zeros(7, dtype=np.int32)
        # DAT_0062480c — power index of the committed strategic enemy
        self.g_CommittedEnemy: int = -1
        # DAT_00633f20[power*5+rank] — pre-sorted power proximity ranks (stride 5)
        # Populated by map-init; None until set externally.
        self.g_PowerProximityRank: np.ndarray | None = None
        # DAT_00b84948[pow*21+other] — second influence scratch matrix (zeroed each turn)
        self.g_InfluenceMatrix_B = np.zeros((7, 7), dtype=np.float64)
        # DAT_004d53d8[power*2] — lo-word: 1 = PCE proposal sent to this power this turn
        # DAT_004d53dc[power*2] — hi-word companion (always 0 after write)
        # Both zeroed each turn in the per-power reset loop.
        self.g_TurnOrderHist_Lo = np.zeros(7, dtype=np.int32)
        self.g_TurnOrderHist_Hi = np.zeros(7, dtype=np.int32)

        # DAT_00ba27b0[power*8] / DAT_00ba27b4[power*8] — per-power turn score (int64);
        # cleared in the per-power reset loop.  Used by RESPOND to track the best-scoring
        # ally's timestamp for response-timing gating.
        self.g_TurnScore = np.zeros(7, dtype=np.int64)

        # DAT_00633768[power] — per-power active-turn flag; cleared each turn, set to 1
        # by RESPOND deceit path for the sender power.  Gated in the g_PosAnalysisList
        # walk: when response is YES, only register deviation entry if flag is set.
        self.g_PowerActiveTurn = np.zeros(7, dtype=np.int32)

    def synchronize_from_game(self, game):
        """
        Takes the current game state (`diplomacy.Game` object) 
        and updates Albert's internal numpy matrix arrays.
        """
        power_names = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]
        power_to_id = {p: i for i, p in enumerate(power_names)}
        
        if not self.prov_to_id:
            for prov in game.map.locs:
                if prov not in self.prov_to_id:
                    self.prov_to_id[prov] = len(self.prov_to_id)
            # Add uppercase aliases for lowercase parent provinces
            # (e.g. 'spa' → id 63 also gets 'SPA' → id 63).  This ensures
            # prov_to_id lookups work regardless of casing.
            _aliases = {}
            for name, pid in self.prov_to_id.items():
                upper = name.upper()
                if upper != name and upper not in self.prov_to_id:
                    _aliases[upper] = pid
            self.prov_to_id.update(_aliases)
            
            # Build case-insensitive reverse map for adjacency resolution.
            # game.map.abut_list can return mixed-case names (e.g. 'gas' for
            # GAS) and coast-suffixed names (e.g. 'SPA/SC').  We normalise
            # by stripping the coast suffix and upper-casing.
            _upper_lookup: dict = {}
            for _p in self.prov_to_id:
                _key = _p.split('/')[0].upper() if '/' in _p else _p.upper()
                # Prefer the non-coast entry (e.g. 'GAS' over 'GAS/NC')
                if _key not in _upper_lookup or '/' not in _p:
                    _upper_lookup[_key] = self.prov_to_id[_p]

            # Build adjacency graph, water-province set, and land-province set
            water_prov_ids = set()
            land_prov_ids = set()
            for prov in self.prov_to_id:
                base_prov = prov.split('/')[0] if '/' in prov else prov
                self.adj_matrix[self.prov_to_id[prov]] = []
                seen_adj_ids: set = set()
                for adj in game.map.abut_list(prov):
                    adj_base = adj.split('/')[0].upper() if '/' in adj else adj.upper()
                    adj_id = _upper_lookup.get(adj_base, -1)
                    if adj_id >= 0 and adj_id not in seen_adj_ids:
                        self.adj_matrix[self.prov_to_id[prov]].append(adj_id)
                        seen_adj_ids.add(adj_id)
                atype = game.map.area_type(base_prov)
                pid = self.prov_to_id[prov]
                if atype == 'WATER':
                    water_prov_ids.add(pid)
                elif atype == 'LAND':
                    land_prov_ids.add(pid)
                # COAST provinces are in neither set — accessible by both unit types
            self.water_provinces = frozenset(water_prov_ids)
            self.land_provinces = frozenset(land_prov_ids)

            # Build supply-centre set (province IDs of all SCs on the map).
            self.sc_provinces = set()
            for sc_name in getattr(game.map, 'scs', []):
                sc_base = sc_name.split('/')[0].upper()
                sc_id = _upper_lookup.get(sc_base, -1)
                if sc_id >= 0:
                    self.sc_provinces.add(sc_id)

            # Build _id_to_prov reverse map.  Always store the uppercase
            # non-coast canonical form so downstream order strings match
            # what the diplomacy lib and dispatch validator expect.
            # E.g. id 63 → 'SPA' (not 'spa' or 'SPA/SC').
            self._id_to_prov = {}
            for name, pid in self.prov_to_id.items():
                canon = name.split('/')[0].upper()
                existing = self._id_to_prov.get(pid)
                if existing is None:
                    self._id_to_prov[pid] = canon
                # All variants of the same base map to the same canon, so
                # no further preference logic needed.

            # Build home-SC map: power_idx → frozenset of province IDs.
            # game.map.homes is a dict of power_name → [home_sc_name, ...]
            homes = getattr(game.map, 'homes', {})
            for power_name, home_scs in homes.items():
                if power_name in power_to_id:
                    p_id = power_to_id[power_name]
                    prov_ids = frozenset(
                        _upper_lookup[sc.split('/')[0].upper()]
                        for sc in home_scs
                        if sc.split('/')[0].upper() in _upper_lookup
                    )
                    self.home_centers[p_id] = prov_ids

        # Reset turn specific structures
        self.g_SCOwnership.fill(0)
        self.g_ScOwner.fill(-1)
        self.g_OwnReachScore.fill(0)
        self.unit_info.clear()
        # ── Per-call resets (mirror GenerateAndSubmitOrders.c top-of-fn) ──
        # The C binary explicitly reinitialises these at the top of every
        # GenerateAndSubmitOrders call:
        #   g_PosAnalysisList (DAT_00bb65cc)  — sentinel-list reinit, line 92-96
        #   g_PressSentMatrix (line 243)      — zeroed in per-power loop
        #   g_XdoPressProposals               — staging for ComputePress, drained
        # Mirror that here.
        self.g_XdoPressSent.fill(0)
        self.g_XdoPressProposals.clear()
        self.g_PosAnalysisList.clear()

        # ── DO NOT clear: the following globals accumulate forever in C. ──
        # Wiping them in Python would break multi-phase commitment semantics
        # and re-emit dedup'd alliance/proposal events on every phase.
        #
        # g_BroadcastList     (DAT_00bb65ec) — received DAIDE press; the only
        #     write site is register_received_press, no destructor. An XDO
        #     announced in S1901M must still penalise contradicting
        #     candidates in F1901M+ until superseded.
        #
        # g_AllianceMsgTree   (DAT_00bbf638) — set of alliance-event keys
        #     used by BuildAllianceMsg/CheckAndInsertAllianceTreeEntry as a
        #     dedup so the same alliance event isn't re-broadcast. Inserts
        #     happen in CAL_BOARD/CAL_VALUE/FRIENDLY/GOF; no clear anywhere.
        #
        # g_AcceptedProposals (DAT_00bb65d4) — tokens we've agreed to. Sole
        #     C write: CAL_VALUE.c:174 (FUN_00419300 = set_insert). Never
        #     cleared on the success path; only the failure-cleanup loop in
        #     RESPOND drains it (already mirrored in communications.py).
        #
        # g_ProposalHistory   (g_ProposalHistoryMap) — keyed by proposal
        #     digest; used by BuildSupportProposals/BuildAndSendSUB/Process-
        #     Turn for "have we proposed/seen this before?" dedup. Only
        #     StdMap_FindOrInsert / StdMap_Insert in the C; no destructor.
        #
        # g_BroadcastListWatermark IS per-call (register_received_press
        # snapshots and rewinds it) — safe to clamp here for newcomers.
        self.g_BroadcastListWatermark = 0

        # Parse Ownership
        for power_name, centers in game.get_centers().items():
            if power_name in power_to_id:
                p_id = power_to_id[power_name]
                for center in centers:
                    prov = center.split('/')[0] if '/' in center else center
                    if prov in self.prov_to_id:
                        prov_id = self.prov_to_id[prov]
                        self.g_SCOwnership[p_id, prov_id] = 1
                        self.g_ScOwner[prov_id] = p_id
                        
        # Register Unit Ownership
        for power_name, units in game.get_units().items():
            if power_name in power_to_id:
                p_id = power_to_id[power_name]
                for unit_str in units:
                    parts = unit_str.split()
                    if len(parts) >= 2:
                        unit_type = parts[0]
                        prov = parts[1].split('/')[0]
                        coast = parts[1].split('/')[1] if '/' in parts[1] else ''
                        if prov in self.prov_to_id:
                            prov_id = self.prov_to_id[prov]
                            self.g_OwnReachScore[p_id, prov_id] = 1
                            self.unit_info[prov_id] = {'power': p_id, 'type': unit_type, 'coast': coast}
                            
        # Populate sc_count from current centers
        self.sc_count.fill(0)
        for power_name, centers in game.get_centers().items():
            if power_name in power_to_id:
                self.sc_count[power_to_id[power_name]] = len(centers)

        # Seed NearEndGameFactor with the same formula cal_board uses
        # (max over all powers of (sc[k] - win_threshold + 9), floor 1.0).
        # cal_board() recomputes this properly when it runs; this seed
        # covers the first SPR phase where cal_board hasn't fired yet.
        wt = int(self.win_threshold) or 1
        near_end = 1.0
        for k in range(7):
            factor = float(int(self.sc_count[k]) - wt + 9)
            if factor > near_end:
                near_end = factor
        self.g_NearEndGameFactor = near_end

        # Season token: SPR/SUM/FAL/AUT/WIN from phase string e.g. "S1901M"/"F1901R"/"W1901A"
        # Phase format: [S|F|W] + year + [M|R|A]
        #   S+M=SPR, S+R=SUM, F+M=FAL, F+R=AUT, W+A=WIN
        # Try get_current_phase (diplomacy.Game) first, then get_phase (NetworkGame)
        if hasattr(game, 'get_current_phase'):
            _phase_raw: Any = game.get_current_phase()
        elif hasattr(game, 'get_phase'):
            _phase_raw = game.get_phase()
        else:
            _phase_raw = ''
        phase: str = str(_phase_raw) if _phase_raw is not None else ''
        if len(phase) >= 2:
            phase_type   = phase[-1:].upper()   # 'M', 'R', or 'A'
            season_letter = phase[:1].upper()   # 'S', 'F', or 'W'
            if phase_type == 'M':
                self.g_season = 'SPR' if season_letter == 'S' else 'FAL'
            elif phase_type == 'R':
                self.g_season = 'SUM' if season_letter == 'S' else 'AUT'
            elif phase_type == 'A':
                self.g_season = 'WIN'
            else:
                self.g_season = 'SPR'

        # Populate g_RetreatList and g_OrderHistList from game order history.
        # g_RetreatList  = most-recent completed retreat phase (R suffix) orders.
        # g_OrderHistList = most-recent completed movement phase (M suffix) orders.
        # Both are cleared and repopulated each synchronize call (Python timing
        # differs from C++ ORD-handler timing; we read history instead).
        order_history = getattr(game, 'order_history', None)
        if order_history is not None and self.prov_to_id:
            self.g_RetreatList = []
            self.g_OrderHistList = []
            last_retreat_key  = None
            last_movement_key = None
            for ph_key in reversed(list(order_history.keys())):
                ph_str = str(ph_key)
                if last_retreat_key is None and ph_str.endswith('R'):
                    last_retreat_key = ph_key
                if last_movement_key is None and ph_str.endswith('M'):
                    last_movement_key = ph_key
                if last_retreat_key is not None and last_movement_key is not None:
                    break

            if last_retreat_key is not None:
                retreat_phase_orders = order_history[last_retreat_key]
                if isinstance(retreat_phase_orders, dict):
                    for pwr_name, orders_list in retreat_phase_orders.items():
                        p_id = power_to_id.get(pwr_name, -1)
                        if p_id < 0 or not orders_list:
                            continue
                        for ord_str in orders_list:
                            rec = _parse_retreat_order(ord_str, p_id, self.prov_to_id)
                            if rec is not None:
                                self.g_RetreatList.append(rec)

            if last_movement_key is not None:
                movement_phase_orders = order_history[last_movement_key]
                if isinstance(movement_phase_orders, dict):
                    for pwr_name, orders_list in movement_phase_orders.items():
                        p_id = power_to_id.get(pwr_name, -1)
                        if p_id < 0 or not orders_list:
                            continue
                        for ord_str in orders_list:
                            rec = _parse_movement_order(ord_str, p_id, self.prov_to_id)
                            if rec is not None:
                                self.g_OrderHistList.append(rec)

    def get_unit_type(self, prov_id: int):
        return self.unit_info.get(prov_id, {}).get('type', None)
        
    def has_unit(self, prov_id: int):
        return prov_id in self.unit_info

    def has_own_unit(self, power_id: int, prov_id: int):
        return self.unit_info.get(prov_id, {}).get('power', -1) == power_id

    def get_unit_power(self, prov_id: int):
        return self.unit_info.get(prov_id, {}).get('power', -1)

    def get_unit_adjacencies(self, prov_id: int):
        return self.adj_matrix.get(prov_id, [])

    def get_adjacent_provinces(self, prov_id: int):
        """Alias for get_unit_adjacencies — matches C AdjacencyList_FilterByUnitType."""
        return self.adj_matrix.get(prov_id, [])

    def get_power_units(self, power_id: int):
        """Provinces where a unit belonging to `power_id` resides."""
        return [p for p, info in self.unit_info.items() if info.get('power', -1) == power_id]

    def get_unit_owner(self, prov_id: int):
        """Alias for get_unit_power — returns None when no unit present."""
        return self.unit_info.get(prov_id, {}).get('power', None)

    def can_reach(self, src_prov: int, dst_prov: int):
        return dst_prov in self.adj_matrix.get(src_prov, [])

    def can_reach_by_type(self, src_prov: int, dst_prov: int, unit_type: str) -> bool:
        """Province adjacency gate with unit-type filtering.

        Fleets can move to WATER or COAST provinces but NOT LAND (landlocked).
        Armies can move to LAND or COAST provinces but NOT WATER (sea zones).

        ``unit_type`` should be ``'F'`` or ``'A'`` (as stored in
        ``unit_info``), though ``'FLT'``/``'AMY'`` are also accepted.
        Falls back to ``can_reach`` for unknown types.
        """
        if dst_prov not in self.adj_matrix.get(src_prov, []):
            return False
        if unit_type in ('F', 'FLT') and dst_prov in self.land_provinces:
            return False   # fleet cannot enter landlocked province
        if unit_type in ('A', 'AMY') and dst_prov in self.water_provinces:
            return False   # army cannot enter sea zone
        return True

    def get_max_threatening_adj_scs(self, prov_id: int, power_id: int) -> int:
        max_scs = 0
        for adj in self.adj_matrix.get(prov_id, []):
            enemy_id = self.get_unit_power(adj)
            if enemy_id != -1 and enemy_id != power_id:
                sc_count = np.sum(self.g_SCOwnership[enemy_id])
                if sc_count > max_scs:
                    max_scs = sc_count
        return max_scs

    def CandidateSet_contains(self, power: int, province: int) -> bool:
        return self.g_CandidateScores[power, province] > 0

    def get_candidate_score(self, power: int, province: int, iteration: int) -> float:
        return self.g_CandidateScores[power, province] # simplified fallback

    def get_enemy_reach(self, power_id: int, province: int) -> int:
        return int(self.g_EnemyReachScore[power_id, province])

    def get_trial_order_table(self, trial_state_data: np.ndarray):
        return {}
