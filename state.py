import logging
from typing import Any

import numpy as np

logger = logging.getLogger(__name__)

_POWER_NAMES_STATE = ["AUSTRIA", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "RUSSIA", "TURKEY"]


def _parse_retreat_order(order_str: str, power: int, prov_to_id: dict) -> dict | None:
    """Parse a DAIDE-style retreat order string into a g_retreat_list record.

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
    """Parse a DAIDE-style movement order string into a g_order_hist_list record.

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
    g_active_dmz_list: "Any"
    g_active_dmz_map: "Any"
    g_alliance_orders: "Any"
    # g_alliance_orders_present removed: phantom global. The C binary reads
    # `&DAT_00bb6d00 + p*0xc` which is the std::set _Mysize field of slot p
    # inside g_alliance_orders, not a separate array. Use len(...) instead.
    g_ally_order_history: "Any"
    # g_convoy_route moved to __init__ (2026-04-16): initialised as dict and
    # populated per-trial by moves.convoy.populate_convoy_routes().  Previously
    # a class-level annotation only, which caused hasattr() checks to pass
    # without the attribute actually existing at trial time → convoy orders
    # were never emitted.
    # g_coop_flag removed 2026-04-16: phantom alias of g_coop_score_flag_b
    # (DAT_0062be98).  Reader in senders.py now uses g_coop_score_flag_b
    # directly; writer in bot/strategy.py already used the canonical name.
    g_desig_count_a: "Any"
    g_desig_count_b: "Any"
    g_desig_list_a: "Any"
    g_desig_list_b: "Any"
    g_dmz_order_list: "Any"
    # g_general_orders_present removed: phantom global (see g_alliance_orders_present).
    g_lone_lead_power: "Any"
    # g_move_time_limit removed: phantom alias of g_move_time_limit_sec
    # (DAT_00624ef4 — MTL deadline in seconds).  The canonical
    # attribute is declared in __init__ as `self.g_move_time_limit_sec`.
    g_order_history: "Any"
    g_other_score: "Any"
    g_press_candidate_a: "Any"
    g_press_candidate_b: "Any"
    g_press_thresh_random: "Any"
    g_proposal_history_map: "Any"
    g_ring_coast_a: "Any"
    g_ring_coast_b: "Any"
    g_ring_coast_c: "Any"
    g_ring_convoy_enabled: "Any"
    g_ring_convoy_score: "Any"
    g_ring_prov_a: "Any"
    g_ring_prov_b: "Any"
    g_ring_prov_c: "Any"
    # g_some_coop_score removed 2026-04-16: phantom alias of g_coop_score_flag_a
    # (DAT_0062c580).  Reader in senders.py now uses g_coop_score_flag_a
    # directly; writer in bot/strategy.py already used the canonical name.
    g_stab_mode: "Any"
    g_support_opportunities_set: "Any"
    g_support_proposals: "Any"
    g_support_trust_adj: "Any"
    g_trial_list2: "Any"
    g_trial_map: "Any"
    g_unit_presence: "Any"
    g_victory_threshold: "Any"
    g_xdo_dest_by_sender: "Any"
    g_xdo_global_dest_map: "Any"
    g_xdo_sup_hld_map: "Any"
    g_baed6d: "Any"
    g_one_shot_press: "Any"
    g_pending_orders_A: "Any"
    g_pending_orders_B: "Any"
    g_trust_counter: "Any"
    g_turn_start_time: "Any"
    g_xdo_candidate_list: "Any"

    def __init__(self):
        # 1. Global Game State
        self.g_near_end_game_factor = 0.0
        self.g_deceit_level = 0
        self.g_max_province_score = np.zeros(256, dtype=np.float64)
        self.g_min_score = np.zeros(256, dtype=np.float64)
        
        # 2. Heuristics & Map Variables
        # DAT_006040e8[pow*0x800+prov*8] — int64[pow*256+prov]
        self.g_attack_count = np.zeros((7, 256), dtype=np.float64)
        # DAT_005a48e8[pow*0x800+prov*8] — int64[pow*256+prov]; >10 = danger zone
        self.g_attack_history = np.zeros((7, 256), dtype=np.float64)
        # DAT_0055b0e8[pow*0x800+prov*8] — int64[pow*256+prov]
        self.g_defense_score = np.zeros((7, 256), dtype=np.float64)
        # DAT_004f6ce8[pow*0x800+prov*8] — int64[pow*256+prov]; 1 = enemy unit present
        # Fixed 2026-04-20: int32→int64 to match C stride 0x800=2048 bytes/row
        self.g_enemy_presence = np.zeros((7, 256), dtype=np.int64)
        # DAT_00535ce8[pow*0x800+prov*8] — int64[pow*256+prov]; 1 = enemy can reach
        # Fixed 2026-04-20: int32→int64 to match C stride
        self.g_enemy_reach_score = np.zeros((7, 256), dtype=np.int64)
        self.g_sc_ownership = np.zeros((7, 256), dtype=np.int32)
        # M10 fix: int32→int64 to match C stride 0x800=2048 bytes/row
        # (consistent with g_enemy_presence and g_enemy_reach_score upgrades).
        self.g_target_flag = np.zeros((7, 256), dtype=np.int64)
        
        self.g_influence_matrix_raw = np.zeros((7, 7), dtype=np.float64)
        self.g_influence_matrix = np.zeros((7, 7), dtype=np.float64)
        self.g_alliance_score = np.zeros((7, 7), dtype=np.float64)
        self.g_ally_trust_score = np.zeros((7, 7), dtype=np.float64)
        self.g_ally_matrix = np.zeros((7, 7), dtype=np.int32)
        
        # Buffers for Heat Diffusion
        self.g_candidate_scores = np.zeros((7, 256), dtype=np.float64)
        # DAT_004ec2f0/f4[pow*0x800+prov*8] — movement heat scores (primary copy)
        self.g_heat_movement = np.zeros((7, 256), dtype=np.float64)
        # DAT_005af0e8/ec[pow*0x800+prov*8] — second copy of movement heat scores
        self.g_heat_movement_b = np.zeros((7, 256), dtype=np.float64)
        # DAT_004d62f0/f4[pow*0x100+prov] — BFS-accumulated influence heat score
        self.g_heat_score = np.zeros((7, 256), dtype=np.float64)
        self.g_global_province_score = np.zeros(256, dtype=np.float64)

        # DAT_00b76a28[pow*0x40+prov] — Albert's influence / owner's influence ratio
        # double[power*0x40+province]; values > 1.0 mean Albert projects more influence
        self.g_influence_ratio = np.zeros((7, 256), dtype=np.float64)
        # DAT_004e1af0/f4[pow*0x100+prov] — reachable-unit count per province
        self.g_unit_adjacency_count = np.zeros((7, 256), dtype=np.int64)
        # DAT_00b75578[pow*0x3f+other] — raw adjacency contact count per power pair
        self.g_contact_count = np.zeros((7, 7), dtype=np.int32)
        # DAT_00b755cc[pow*0x3f+other] — weighted adjacency contact count
        self.g_contact_weighted = np.zeros((7, 7), dtype=np.int32)
        # DAT_00b75620[pow*0x3f+other] — owner-side adjacency count
        self.g_contact_owner_count = np.zeros((7, 7), dtype=np.int32)
        # DAT_00ba2f70[province] — per-province SC owner index; -1 = unoccupied
        # Alias of g_sc_owner (written by SnapshotProvinceState / ParseNOW)
        self.g_sc_owner = np.full(256, -1, dtype=np.int32)
        # DAT_004DA2F0[pow*0x100+prov] — 2D history-gate array; int64[pow*0x100+prov]
        # Non-zero means activity recorded for (power, province); gate in Pass 5
        # of ApplyInfluenceScores. Writer TBD (see Q-AIS-NEW-3 in OpenQuestions.md).
        self.g_history_gate = np.zeros((7, 256), dtype=np.int64)
        
        # 3. Adjacency lists and internal maps
        self.g_province_access_flag = np.zeros((7, 256), dtype=np.int32)
        self.g_coverage_flag = np.zeros((7, 256), dtype=np.int32)
        self.g_convoy_reach_count = np.zeros((7, 256), dtype=np.int32)
        self.g_own_reach_score = np.zeros((7, 256), dtype=np.int32)
        self.g_total_reach_score = np.zeros((7, 256), dtype=np.int32)
        self.g_enemy_mobility_count = np.zeros((7, 256), dtype=np.int32)
        self.g_threat_level = np.zeros((7, 256), dtype=np.int32)
        # DAT_00520ce8/ec[pow*0x100+prov] — enemy pressure/threat intensity per province
        self.g_enemy_pressure = np.zeros((7, 256), dtype=np.int32)
        # DAT_006190e8/ec[pow*0x40+prov*8] — {0} = no build pending; gate in AssignSupportOrder LAB_0044150f
        self.g_build_order_pending = np.zeros((7, 256), dtype=np.int32)
        self.g_province_weight = np.zeros((7, 256), dtype=np.float64)

        # DAT_005164e8[pow*0x100+prov] — g_friendly_unit_flag.
        # DAT_0050bce8[pow*0x100+prov] — g_established_ally_flag.
        # Both written by ScoreProvinces inside the outer-power loop
        # (ScoreProvinces.c:813-826).  C indexes them as [outer_power * 0x100 + prov],
        # making them 2D [7, 256].  Updated 2026-04-21: now 2D (7, 256) per outer_power.
        # FriendlyUnitFlag = 1 iff a non-hostile, non-Albert unit is at province.
        # EstablishedAllyFlag = 1 iff that unit's RelationScore (DAT_00634e90) is <= 9 —
        # note this is the OPPOSITE of "established" in the colloquial sense; the C
        # guard (line 819: `if 9 < relation goto advance`) explicitly skips the flag set
        # for relations > 9.  Kept as C-faithful name in spite of the counterintuitive
        # semantic; see ScoreProvinces.c:819 trace.
        self.g_friendly_unit_flag     = np.zeros((7, 256), dtype=np.int32)
        self.g_established_ally_flag  = np.zeros((7, 256), dtype=np.int32)

        # Flags
        self.g_uniform_mode = 0
        # DAT_00baed40 (char) — "guaranteed/minimal press" mode, set by the
        # `-G`/`-g` CLI arg.  Not yet wired to any CLI parser in the Python
        # port; any external caller can set this to 1 before game start to
        # force g_history_counter=0 in communications/inbound/history.py.
        self.g_minimal_press_mode = 0
        self.win_threshold = 18
        self.score_current = 0
        self.score_baseline = 0

        # DAT_005460e8[(prov+pow*0x40)*2] — float64[pow*256+prov]
        self.g_proximity_score = np.zeros((7, 256), dtype=np.float64)

        # 4. Monte Carlo Evaluation Variables

        # g_order_table: DAT_00baeda0[prov*0x1e + field*4]
        # 30-field per-province order state; fields defined by _F_* constants in monte_carlo.py
        self.g_order_table = np.zeros((256, 30), dtype=np.float64)

        # DAT_00baedb8[prov*0x1e] — order table [6]: convoy-chain depth score OR support order score lo-word (dual-use)
        self.g_convoy_chain_score = np.zeros(256, dtype=np.float64)
        # DAT_00baedbc[prov*0x1e] — order table [7]: hi-word companion (dual-use g_order_score_hi)
        self.g_order_score_hi = np.zeros(256, dtype=np.float64)
        # DAT_00baedf4[prov*0x1e] — unit adjacency reach score per province
        self.g_unit_reach_score = np.zeros(256, dtype=np.float64)
        # DAT_00baedf8[prov*0x1e] — cut-support risk: <0 = own unit, >0 = enemy
        self.g_cut_support_risk = np.zeros(256, dtype=np.float64)
        # DAT_00baeddc[prov*0x1e] — number of units demanding support to this province
        self.g_support_demand = np.zeros(256, dtype=np.int32)
        # DAT_00ba3770[province] — convoy source province score (0xffffffff = unset)
        self.g_convoy_source_prov = np.zeros(256, dtype=np.float64)

        # DAT_00633e90[province] — convoy active flag; set to 1 by BuildOrder_SUP_MTO /
        # BuildOrder_SUP_HLD when a support order targets a convoy fleet; read in Phase 1e
        # as a fallback acceptance gate.  Reset to 0 at the start of each trial.
        self.g_convoy_active_flag = np.zeros(256, dtype=np.int32)

        # DAT_00ba3b70[province] — per-province score flag; set to 1 by RegisterConvoyFleet
        # for adjacent provinces meeting the army-adj + target criteria; reset per trial.
        self.g_province_score_trial = np.zeros(256, dtype=np.int32)
        # DAT_00ba3f70[province] — count of own AMY-adjacent provinces; populated per trial
        # in Phase 1b unit scan; reset to 0 at the start of each trial.
        self.g_army_adj_count = np.zeros(256, dtype=np.int32)
        # Per-trial set of fleet provinces already processed by RegisterConvoyFleet.
        # Mirrors the char flag at this->ptr_at_8 + fleet * 0x24 + 4 in the C++ original.
        self.g_convoy_fleet_registered: set = set()

        # Albert+0x4CFC — sorted convoy fleet candidate list: list[tuple[int, int]] = (score, prov).
        # Populated by ScoreConvoyFleet (FUN_00419790) in process_turn Phase 1g;
        # drained by MoveCandidate (FUN_00411cf0) in Phase 2.  Sorted ascending by
        # score (remaining fleet count); Phase 2 processes from the front (lowest score).
        self.g_convoy_fleet_candidates: list = []

        # DAT_00bb65a0 / DAT_00bb65a4 — convoy destination list.
        # Populated by ConvoyList_Insert (FUN_0041c340) in BuildOrder_MTO/BuildConvoyOrders;
        # cleared at the start of each trial.  Each entry is a dst province index.
        self.g_convoy_dst_list: list = []

        # Companion map dst_province → src_province written by ConvoyList_Insert
        # (the node field set via *ppiVar5 = src immediately after insert).
        self.g_convoy_dst_to_src: dict = {}

        # Accumulator for formatted order strings produced by dispatch_single_order.
        # Reset at the start of each turn by the bot orchestrator (bot/client/_press.py)
        # before the MC loop dispatches orders.  NOT the same as g_order_list (the
        # dict-shaped structure consumed by press evaluators).
        self.g_submitted_orders: list = []

        # *(Albert+8 + prov*0x14 + 0x214) family — per-province convoy route
        # reachability struct populated by ProcessTurn's convoy chain BFS
        # (Source/ProcessTurn.c:1425–1929).  Each trial rewrites this.
        #
        # Per-destination shape (AUDIT_moves_and_messages.md #7, applied
        # 2026-04-18).  Keyed by (army_src → dst_prov → chain_info) so
        # that an army with two candidate destinations requiring different
        # fleet chains can pick the right fleets for each:
        #
        #     g_convoy_route[army_src][dst_prov] = {
        #         'fleet_count': int,            # len(fleets), 1..3
        #         'fleets':      [f1, f2, f3],   # province ids of convoying fleets
        #     }
        #
        # This matches the C layout where fleet_count is stored at offset
        # 0x214 of the per-province struct at stride 0x14 keyed on dst.
        # Readers should use moves.convoy._get_convoy_route(state, src, dst)
        # — a helper that returns (fleet_count, fleets) and tolerates the
        # legacy flat shape for any un-migrated caller.
        self.g_convoy_route: dict = {}

        # Current game season token: 'SPR'|'SUM'|'FAL'|'AUT'|'WIN'
        self.g_season = 'SPR'

        self.final_score_set = np.zeros((7, 256), dtype=np.float64)
        self.g_winter_score_a = np.zeros(256, dtype=np.float64)
        self.g_winter_score_b = np.zeros(256, dtype=np.float64)

        self.g_hold_weight = np.zeros(256, dtype=np.float64)
        self.g_unit_move_prob = np.zeros(256, dtype=np.float64)
        self.g_fleet_support_score = np.zeros(256, dtype=np.float64)

        # ── EnumerateHoldOrders output arrays ──────────────────────────────
        # g_unit_province_reach[power, province] = rank of province in power's
        # sorted province set (OrderedSet). Consumed by EvaluateAllianceScore
        # for weighted reach-based scoring.
        self.g_unit_province_reach = np.zeros((7, 256), dtype=np.int32)
        # g_max_non_ally_reach[power, province] = max OrderedSet rank among
        # adjacent non-ally provinces for this unit's power. Used internally
        # by EnumerateHoldOrders to drive the ally-trust comparison.
        self.g_max_non_ally_reach = np.zeros((7, 256), dtype=np.int32)

        # DAT_00bc1e1c — set of province IDs that are scoring / build targets;
        # consumed by EnumerateConvoyReach (BFS expansion gating).
        # Populated by the order-candidate pipeline before EnumerateConvoyReach runs.
        self.g_build_candidate_list: set = set()

        # this+0x2478 — build-candidate list for WIN phase; populated by WIN handler,
        # cleared by ResetPerTrialState at the start of each MC trial.
        # Each entry is a DAIDE order string (e.g. '( ENG FLT LON ) BLD').
        self.g_build_order_list: list = []
        # this+0x2480 — waive count for WIN phase; cleared by ResetPerTrialState.
        self.g_waive_count: int = 0

        # DAT_00baed68 — press-mode flag; 1 = ComputePress runs this turn, 0 = off
        self.g_press_flag: int = 0

        # DAT_004d2e10/14 — g_ally_designation_a: lo/hi int32 pair per province.
        # Lo = power booked as ally-A; hi = guard word (-1 = unset, >= 0 = valid).
        # C stores these as interleaved int32 pairs (DAT_004d2e10[prov*2] = lo,
        # DAT_004d2e14[prov*2] = hi).  Python stores lo in _a, hi in _a_hi.
        # Read by BuildSupportProposals to exclude designated ally-A from supporters.
        self.g_ally_designation_a = np.full(256, -1, dtype=np.int64)
        self.g_ally_designation_a_hi = np.full(256, -1, dtype=np.int32)

        # DAT_004d2610/14 — g_ally_designation_b: lo/hi int32 pair per province.
        # Lo = power booked as ally-B; hi = guard word.
        # Used by BuildSupportProposals for priority-8 (defend own SC) detection.
        self.g_ally_designation_b = np.full(256, -1, dtype=np.int64)
        self.g_ally_designation_b_hi = np.full(256, -1, dtype=np.int32)

        # DAT_004d3610/14 — g_ally_designation_c: lo/hi int32 pair per province.
        # Lo = power booked as ally-C; hi = guard word.
        # Third designation slot; read by check_order_alliance (FUN_0041d360).
        self.g_ally_designation_c = np.full(256, -1, dtype=np.int64)
        self.g_ally_designation_c_hi = np.full(256, -1, dtype=np.int32)

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
        self.g_proposal_history: set = set()

        # DAT_00baeb70[from_power + to_power * 0x15] — 1 = XDO press sent this turn.
        # Indexed as [from_power, to_power]; shape (7, 7).
        self.g_xdo_press_sent = np.zeros((7, 7), dtype=np.int32)

        # Accumulated XDO support-proposal dicts emitted by BuildSupportProposals.
        # Each dict: {'type','supporter_prov','supporter_power','mover_prov',
        #             'dest','priority','from_power','to_power'}
        self.g_xdo_press_proposals: list = []

        # DAT_00bb67f8[power*0xc] — per-power MTO/CTO attacker scoring map.
        # ScoreSupportOpp (FUN_00404fd0): key = dest_prov, value = int score.
        self.g_xdo_mto_opp_score: dict = {}

        # DAT_00bb69f8[prov*0xc] — per-supporting-unit-province SUP-MTO scoring map.
        # ScoreSupportOpp (FUN_00404fd0): key = sup_power, value = int score.
        self.g_xdo_sup_mto_score: dict = {}

        # DAT_00ba1fb0[province] — safe-reach score per province.
        # Set to max sorted-set rank of reachable uncontested provinces; 0xffffffff = no safe move.
        # Written by ComputeSafeReach; uint32 sentinel matches original C 0xffffffff.
        self.g_safe_reach_score = np.full(256, 0xffffffff, dtype=np.uint32)

        # DAT_005658e8[pow*0x40+prov] — allied units' reachability (trust > 0).
        # Written by EnumerateHoldOrders reach loop when trust > 0.
        self.g_ally_reach_score = np.zeros((7, 256), dtype=np.float64)

        # DAT_005ba0e8[pow*0x100+prov] — provinces reachable via 2-hop move (support chain reach).
        # Written by ScoreOrderCandidates_AllPowers adjacency expansion.
        self.g_support_reach = np.zeros((7, 256), dtype=np.float64)

        # DAT_005c48e8[pow*0x100+prov] — provinces reachable via convoy chain.
        # Written by ScoreOrderCandidates_AllPowers BFS convoy expansion.
        self.g_convoy_reach = np.zeros((7, 256), dtype=np.float64)

        # DAT_005cf0e8[pow*0x100+prov] — provinces convoy-supportable via a fleet unit.
        # Written by ScoreOrderCandidates_AllPowers fleet-support analysis.
        self.g_convoy_support = np.zeros((7, 256), dtype=np.float64)

        # DAT_00baed69 — 1 = another power is close to solo victory (defensive mode).
        self.g_other_power_lead_flag: int = 0

        # DAT_0062be94 — early-game adjacency score accumulator (Turn 1 only).
        self.g_early_game_bonus: int = 0

        # DAT_00bbf60c — global list of candidate proposal records.
        # Each entry: {'power', 'orders', 'score', 'heat_scores', 'deviation', 'pressure_cost'}.
        self.g_candidate_record_list: list = []

        # DAT_00bb6cf8[pow*0xc] — per-power general candidate order sequences.
        # Maps power_idx -> [order_seq, ...] where each order_seq is a dict with
        # at least {'type': str}.  Cleared by _destroy_candidate_tree (FUN_00410cf0)
        # at the start of each ScoreOrderCandidates pass.
        self.g_general_orders: dict = {}

        # DAT_00bb65b4/b8 — cached std::set iterator (g_last_mto_insert).
        # Stores (type: int, province: int) of the last MTO/fleet insert, or None = set.end().
        # AssignSupportOrder reads this to undo a conflicting fleet support commitment.
        self.g_last_mto_insert: tuple | None = None

        # DAT_00bb66f8[power*0xc] — per-power deviation-detection tree.
        # Maps (power, prov) -> expected order type; 0 = no expectation recorded.
        self.g_deviation_tree: dict = {}

        # DAT_00bb6e00 — order-position map: set of province IDs that have a committed SUB entry.
        # Populated by DispatchSingleOrder; used to detect missing order assignments.
        self.g_sub_order_map: set = set()

        # DAT_00bb69fc[power*3] — alternate order list per power.
        # Maps power -> set of province IDs on the alternate order candidate list.
        self.g_alt_order_list: dict = {}

        # DAT_005b98e8/ec[province] — per-province rescore sentinel.
        # Initialised to -1 (0xffffffff) by GenerateOrders; written to 0/1 by
        # ScoreOrderCandidates_AllPowers during the MC trial loop.
        self.g_needs_rescore = np.full(256, -1, dtype=np.int64)

        # ── ScoreOrderCandidates_AllPowers extra globals (ported 2026-04-14) ──
        # DAT_0055b0e8/ec[(prov+pow*0x40)*2] — per-power province max score (int64)
        self.g_max_prov_score_per_power = np.full((7, 256), -(1 << 62), dtype=np.int64)
        # DAT_005508e8/ec — per-power province min score (int64)
        self.g_min_prov_score_per_power = np.full((7, 256), (1 << 62), dtype=np.int64)
        # DAT_005cf0e8/ec[(prov+pow*0x100)*2] — support-candidate mark
        self.g_support_candidate_mark = np.zeros((7, 256), dtype=np.int64)
        # DAT_005700e8/ec[(prov+pow*0x40)*2] — best-reachable-via-enemy threat path score
        self.g_threat_path_score = np.zeros((7, 256), dtype=np.int64)
        # DAT_005ee8e8/ec — classified-province secondary marker (0=unclassified, -1=flanked)
        self.g_target_flag2 = np.zeros((7, 256), dtype=np.int64)
        # DAT_0052b4e8/ec — secondary attack counter (paired with g_attack_count)
        self.g_attack_count2 = np.zeros((7, 256), dtype=np.int64)
        # DAT_00535ce8/ec — secondary enemy pressure (additional to g_enemy_reach_score)
        self.g_enemy_pressure_secondary = np.zeros((7, 256), dtype=np.int64)
        # (g_ally_history_count was a stale alias for g_relation_score / DAT_00634e90;
        #  removed 2026-04-14 — see g_relation_score declaration below.)
        # DAT_004d2e10/14 — ally-designation-E counterpart (paired with _A)
        self.g_ally_designation_e = np.full(256, -1, dtype=np.int64)
        # DAT_005c48e8/ec — direct reach flag (1-hop BFS target)
        self.g_direct_reach_flag = np.zeros((7, 256), dtype=np.int64)
        # DAT_005ba0e8/ec — extended reach flag (2-hop via unit)
        self.g_extended_reach_flag = np.zeros((7, 256), dtype=np.int64)
        # DAT_005b98e8/ec — top-reach flag (per-province, shared with NeedsRescore codepath)
        self.g_top_reach_flag = np.zeros(256, dtype=np.int64)
        # g_prov_target_flag[pow, prov] — primary target classification (1/2/-10/0)
        self.g_prov_target_flag = np.zeros((7, 256), dtype=np.int64)

        # g_opening_target[power] — per-power opening deception target province.
        # -1 = no target.  Set in SPR when g_deceit_level == 1.
        self.g_opening_target = np.full(7, -1, dtype=np.int32)

        # ── CAL_BOARD globals ────────────────────────────────────────────────
        # DAT_006238e8[power] — pow(sc_count, sc_count)*100+1
        self.g_power_exp_score = np.zeros(7, dtype=np.float64)
        # DAT_0062e360[power] — sc_count*100/total
        self.g_sc_percent = np.zeros(7, dtype=np.float64)
        # DAT_004cf568[power] — 1 = this power is designated enemy this turn
        self.g_enemy_flag = np.zeros(7, dtype=np.int32)
        # DAT_004cf56c[power] — hi-word of the int64 pair whose lo-word is
        # g_enemy_flag.  C code rarely writes non-zero here (int32 store into
        # int64 leaves hi=0), so this array is effectively always zero; kept
        # so communications/evaluators/handlers.py:283 can index it directly
        # instead of defaulting.  No writer exists on the Python side yet —
        # add one if a C code path that writes DAT_004cf56c is ported.
        self.g_enemy_flag_hi = np.zeros(7, dtype=np.int32)
        # DAT_00633ec0[power] — count of genuine enemies for each power
        self.g_enemy_count = np.zeros(7, dtype=np.int32)
        # DAT_00633e68[power] — 1 = ally is distressed (attacked by both top enemies)
        self.g_ally_distress_flag = np.zeros(7, dtype=np.int32)
        # DAT_00633780[pow*21+other] — -2=self, -1=unranked, 1-N=rank
        self.g_rank_matrix = np.full((7, 7), -1, dtype=np.int32)
        np.fill_diagonal(self.g_rank_matrix, -2)
        # DAT_00baed6a — 1 = Albert dominant leader (>75% SC influence, gap >2%)
        self.g_leading_flag: int = 0
        # DAT_0062480c — index of power close to solo victory
        self.g_near_victory_power: int = -1
        # DAT_00baed2a — 1 = send DRW proposal this turn
        self.g_request_draw_flag: int = 0
        # DAT_00baed30 — 1 = map static for many turns → request draw
        self.g_static_map_flag: int = 0
        # DAT_00baed6b — 1 = own power exactly 1 SC from winning
        self.g_one_sc_from_win: int = 0
        # DAT_00633f18[pow*5+rank] — top-N preferred alliance targets (1-indexed)
        self.g_ally_pref_ranking = np.full((7, 5), -1, dtype=np.int32)
        # DAT_006340c0[pow*21+other] — selection-sort visit flag: -1=unranked, -2=self, 1-N=rank
        self.g_influence_rank_flag = np.full((7, 7), -1, dtype=np.int32)
        np.fill_diagonal(self.g_influence_rank_flag, -2)
        # DAT_00baed6c — 1 = war mode (a power has >80% SCs)
        self.g_war_mode_flag: int = 0
        # DAT_00baed5f — 1 = Albert was stabbed; triggers enemy-desired mode
        self.g_stabbed_flag: int = 0
        # DAT_00baed69 — 1 = another power is close to solo victory
        # (already defined as g_other_power_lead_flag above)
        # g_influence_matrix_alt is the same array as g_influence_matrix (alias)
        # DAT_00b81ff0 — trust-adjusted, noise-perturbed, row-normalised influence matrix
        # (self.g_influence_matrix already declared above)

        # Own power index (0-based); set at turn start by AlbertBot from power_name.
        # C: *(byte *)(state->inner + 0x2424)
        self.albert_power_idx: int = 0

        # DAT_00624124 — C-faithful name for Albert's own power index.
        # Mirror of albert_power_idx kept in sync by bot/client/_orders.py so
        # that code paths still using the C name (e.g. trial.py:849) resolve
        # correctly.  Previously read but never written → getattr defaulted
        # to albert_power_idx which is correct, but left the identity check
        # permissive (never distinguished own from other powers in the
        # "g_albert_power != power_index" branch).
        self.g_albert_power: int = 0

        # Diplomacy is a 7-power game; the C binary uses this as a shape
        # bound in several per-power loops.  Previously only read via
        # getattr(..., 7) fallback; providing a real default makes the
        # attribute visible to later writers (e.g. variant host negotiation
        # where num_powers differs).
        self.g_num_powers: int = 7

        # True once the server has sent an OFF or SMR message (game ended).
        # Read by bot/client/_orders.py:125 as a loop-exit guard.  No Python
        # writer yet — the game-end inbound handler is not ported; when it
        # is, it should set this to True.  Default False preserves the
        # previous getattr(..., False) semantics while making the attribute
        # real so writers don't silently no-op via typos.
        self.g_game_over: bool = False

        # ── HLO handler state (C offsets relative to inner_state) ──────────
        # +0x2448 — "HLO received" flag; set to 1 by HLO_Dispatch.
        self.g_hlo_received: bool = False
        # +0x2428 — passcode from server (sign-extended 14-bit DAIDE field).
        self.g_passcode: int = 0
        # +0x242c — variant TokenList from HLO message (e.g. ['LVL', '10']).
        self.g_variant_list: list = []

        # ── GOF tracking ──────────────────────────────────────────────────
        # True after Albert sends GOF (go-flag), cleared by YES(NOT(GOF))
        # or server REJ(GOF).
        self.g_gof_sent: bool = False

        # ── TME deadline tracking ─────────────────────────────────────────
        # Wall-clock deadline from server TME messages (time.time() + secs).
        self.g_tme_deadline: float = 0.0

        # ── SCO handler state ─────────────────────────────────────────────
        # Updated by SCO messages; maps power_idx → SC count from server.
        # Separate from self.sc_count which is derived locally each turn.
        self.g_sco_power_sc_count = np.zeros(7, dtype=np.int32)

        # ── ORD handler state ─────────────────────────────────────────────
        # Last batch of ORD (adjudicated orders) from the server.
        self.g_ord_results: list = []

        # ── MIS handler state ─────────────────────────────────────────────
        # MIS (missing orders) power list from server.
        self.g_mis_powers: list = []

        # ── CCD handler state ─────────────────────────────────────────────
        # Set of power indices reported as civil-disorder (disconnected).
        self.g_ccd_powers: set = set()

        # ── OUT handler state ─────────────────────────────────────────────
        # Set of power indices reported as eliminated.
        self.g_out_powers: set = set()

        # ── OFF handler state ─────────────────────────────────────────────
        # True when server has sent OFF (game over, server shutting down).
        self.g_off_received: bool = False

        # ── MAP/MDF handler state ─────────────────────────────────────────
        # MAP name string from server.
        self.g_map_name: str = ''
        # MDF adjacency/province data from server (raw token list).
        self.g_mdf_data: list = []

        # ── SVE/LOD handler state ─────────────────────────────────────────
        # Last SVE (save) game name from server.
        self.g_sve_game_name: str = ''

        # ── THX handler state ─────────────────────────────────────────────
        # Last THX (order acknowledgment) result list.
        self.g_thx_results: list = []

        # ── ADM handler state ─────────────────────────────────────────────
        # Last ADM (admin) message from server.
        self.g_adm_message: str = ''

        # DAT_00baed2b — result of PrepareDrawVoteSet / ComputeDrawVote.
        # 1 = propose DRW this turn; 0 = do not.
        self.g_draw_sent: int = 0

        # Current SC counts and targets derived each turn from g_sc_ownership
        # sc_count[power] — int[7]; filled by synchronize_from_game / cal_board
        self.sc_count = np.zeros(7, dtype=np.int32)
        # target_sc_count[power] — int[7]; win threshold per power (all 18 in std Dip)
        self.target_sc_count = np.full(7, 18, dtype=np.int32)

        # DAT_004cf4c0[power*2] — g_enemy_slot priority queue (top-3 enemies, -1=empty)
        self.g_enemy_slot: Any = np.full(3, -1, dtype=np.int32)

        # ── PostProcessOrders (move-history matrix) ──────────────────────────
        # DAT_00635578[power*0x10000+src*0x100+dst] — fading move-history table
        # Decays 3/turn; +10 on successful support; zeroed on disruption.
        self.g_move_history_matrix = np.zeros((7, 256, 256), dtype=np.int32)

        # ── ComputePress globals ─────────────────────────────────────────────
        # DAT_00b85768[power*0x100+province] — bool: 1 = power presses this province
        self.g_press_matrix = np.zeros((7, 256), dtype=np.int32)
        # DAT_00b85710[power] — count of provinces this power presses
        self.g_press_count = np.zeros(7, dtype=np.int32)

        # ── ProposeDMZ globals ───────────────────────────────────────────────
        # DAT_00bb7130 — per-(power,province) proposal send-count tracking
        self.g_sent_proposals: dict = {}    # {(power, province): count}
        # DAT_004c6bd4 / 4 − 4 — randomized DMZ aggressiveness ∈ [−4, 20]
        self.g_dmz_aggressiveness: int = 0
        # Press proposal candidate slate built by ApplyInfluenceScores / ProposeDMZ
        # Each entry: {'flag1': bool, 'flag2': bool, 'flag3': bool, 'province': int,
        #              'ally_power': int, 'score': int, 'done': bool}
        self.g_order_list: list = []

        # Retreat order list iterated by _build_gof_seq FAL/AUT branch (this+0x245c/2460).
        # Each entry: {'province': int, 'unit_type': str, 'unit_coast': str,
        #              'power': int, 'order_type': int,
        #              'dest_province': int, 'dest_coast': int}
        # order_type: 0 or 8 = DSB, 7 = RTO.  Populated before _send_gof is called.
        self.g_retreat_order_list: list = []

        # Albert+0x248c/0x2490 — g_retreat_list: ordered-set of retreat-phase order nodes.
        # Written by ORD handler when season == SUM or AUT; cleared at retreat-phase start.
        # Each entry: {'src_province': int, 'unit_type': int, 'power': int,
        #              'order_type': int (2=MTO,3=SUP-HLD,4=SUP-MTO,6=CTO,7=RTO,8=DSB),
        #              'dst_province': int, 'sup_src': int, 'sup_dst': int, 'endgame_flag': int}
        # In Python, populated from game.order_history at synchronize_from_game time.
        self.g_retreat_list: list = []

        # Albert+0x2498/0x249c — g_order_hist_list: ordered-set of movement-phase order nodes.
        # Written by ORD handler when season == SPR or FAL; cleared at retreat-phase start.
        # Same node layout as g_retreat_list.  Populated from game.order_history.
        self.g_order_hist_list: list = []

        # Lazy-built reverse map: province_id (int) → province name (str).
        # Built on first use from prov_to_id; cached here for all callers.
        self._id_to_prov: dict = {}

        # Home supply centers per power: dict[power_idx → frozenset[prov_id]].
        # Populated once during synchronize_from_game from game.map.homes.
        # Used by populate_build_candidates to gate legal build locations.
        self.home_centers: dict = {}

        # ── UpdateScoreState / BuildAndSendSUB globals ───────────────────────
        # DAT_0062e460[power] — unit count; non-zero = power has live units
        self.g_unit_count = np.zeros(7, dtype=np.int32)
        # DAT_00bc1e04 — current round number
        self.g_current_round: int = 0
        # DAT_00bc1e00 per-power game-board round records; power → last seen round
        # Used by UpdateScoreState to detect stale-round ally order tables.
        self.g_power_round_record: dict = {}  # {power_idx: round_number}
        # DAT_00baed48 — cumulative score counter
        self.g_cum_score: int = 0
        # DAT_0062d34c — score baseline (subtracted from cumulative)
        self.g_score_baseline: int = 0
        # DAT_0062e4b4 — alternative score accumulator
        self.g_score_alt: int = 0

        # ── CheckTimeLimit globals ───────────────────────────────────────────
        # g_network_state+0x20 — MTL timeout flag; set by timer thread when MTL fires
        self.mtl_expired: int = 0

        # ── BuildAndSendSUB globals ──────────────────────────────────────────
        # DAT_00bb65f0 — outer broadcast proposal list
        self.g_broadcast_list: list = []
        # DAT_00baed60 — g_broadcast_list size watermark after RegisterReceivedPress
        self.g_broadcast_list_watermark: int = 0
        # DAT_00bb6df4 — XDO proposal dedup set (compound order-seq keys;
        # approximated here as per-province set; C uses FUN_00410980/FUN_00419300)
        self.g_xdo_proposal_list: set = set()
        # DAT_00bb65f8[power*0xc] — per-sender XDO proposal ordered set.
        # Populated by FUN_00419300 in _handle_xdo; sorted list[tuple] per power.
        self.g_xdo_proposal_by_sender: dict = {}
        # DAT_00bb66f8[power*0xc] — per-power NOT-XDO retraction ordered set.
        # Populated by FUN_00419300 in _not_xdo; sorted list[tuple] per power.
        # Note: DAT_00bb66f8 is also mapped to g_deviation_tree (different usage
        # context in RECEIVE_PROPOSAL vs. cal_not_xdo).
        self.g_not_xdo_list_by_sender: dict = {}
        # DAT_004c6bbc — MC trial cap per proposal (difficulty=100 → 30)
        self.g_press_proposals_cap: int = 30
        # DAT_00b95368/58/e0[trial*4] — per-trial score tracking arrays
        self.g_trial_score_a: list = []
        self.g_trial_score_b: list = []
        self.g_trial_score_c: list = []
        # DAT_00bbf690/94[pow*0x3c] — current best order sequence per-power
        self.g_current_best_order: dict = {}
        # DAT_00bc0a40/44[pow*0xf0] — backup of best orders at best-trial point
        self.g_best_order_backup: dict = {}
        # DAT_00baed94/98 — press deal records (earlier proposals received)
        self.g_deal_list: list = []
        # DAT_00bb65c8/cc — position analysis list (g_own_proposal_map in C); each entry:
        #   {'tokens': list, 'token_set': frozenset, 'power_count': int}
        # Cleared each turn.  Used by RECEIVE_PROPOSAL for proposal dedup.
        self.g_pos_analysis_list: list = []
        # DAT_00bb65d4 — accepted proposals this turn (YES results from EvaluatePress)
        self.g_accepted_proposals: list = []
        # DAT_00bbf638 — alliance-message BST; in Python modelled as a set of
        # power indices inserted by BuildAllianceMsg / receive_proposal.
        self.g_alliance_msg_tree: set = set()
        # DAT_00bb69fc[power*3] — per-power alternate order list
        # (already declared as g_alt_order_list above)
        # g_history_counter > 19 gates some press sending
        self.g_history_counter: int = 0
        # DAT_00bb6e10[p*0xc] — per-power allowed-press-type std::map<ushort>.
        # Populated by process_hst from g_allowed_press_token_list thresholds.
        # Key = raw DAIDE ushort token int (PCE=0x4A10, ALY=0x4A00, etc.).
        self.g_press_history: dict = {}  # {power_int: set[int]}

        # ── DispatchScheduledPress globals ───────────────────────────────────
        # DAT_00bb65c0 — master scheduled press list
        # Each entry: {'scheduled_time': float, 'press_type': str,
        #              'data': list, 'sent': bool}
        self.g_master_order_list: list = []
        # DAT_00ba2884:ba2880 — session start time (int64 Unix timestamp)
        self.g_session_start_time: float = 0.0
        # DAT_00ba2858:ba285c — base wait threshold (seconds); GOF fires when
        #   elapsed > g_base_wait_time + 25 s  (FUN_00443ed0)
        self.g_base_wait_time: float = 0.0
        # DAT_00bb65c4 — nonzero while the game engine is actively processing
        #   (FUN_00443ed0 polls this before sending fallback GOF)
        self.g_processing_active: int = 0
        # DAT_00ba2860:ba2864 — elapsed time recorded by FUN_00443ed0 at GOF send
        self.g_elapsed_press_time: float = 0.0
        # DAT_00baed32 — 0 = randomised delay; non-zero = send immediately at elapsed
        self.g_press_instant: int = 0
        # DAT_00624ef4 — move time limit in seconds; 0 = no deadline
        self.g_move_time_limit_sec: int = 0

        # ── CancelPriorPress globals ─────────────────────────────────────────
        # DAT_004c6ce4 — prior press token to cancel (NOT message)
        self.g_prior_press_token: object = None
        # DAT_00baed47 — once-per-turn send guard
        self.g_cancel_press_sent: int = 0

        # ── EvaluateAllianceScore scratch ────────────────────────────────────
        # Computed per turn; shape (7,) — per-power desirability score
        self.g_alliance_desirability = np.zeros(7, dtype=np.float64)

        # ── FRIENDLY globals ─────────────────────────────────────────────────
        # DAT_004d552c[pow*21+other] — hi-word of ally trust score (≥5 = full trust threshold)
        # Paired with g_ally_trust_score (lo-word); both int.  Alliance upgrades when hi≥5.
        self.g_ally_trust_score_hi = np.zeros((7, 7), dtype=np.int32)

        # DAT_00634e90[pow*21+other] — relationship score: −50=hated, 0=neutral, +50=allied
        self.g_relation_score = np.zeros((7, 7), dtype=np.int32)
        # Cumulative relation history (UpdateRelationHistory / FUN_0040d7e0 accumulator)
        self.g_relation_history = np.zeros((7, 7), dtype=np.int32)
        # DAT_0062cc68[pow*21+other] — 1 = pow stabbed other this game
        self.g_stab_flag = np.zeros((7, 7), dtype=np.int32)
        # DAT_0062b0c8[pow*21+other] — 1 = cease-fire declared between pow and other
        self.g_cease_fire = np.zeros((7, 7), dtype=np.int32)
        # DAT_0062be98[pow*21+other] — cooperation score flag (fall/autumn season)
        self.g_coop_score_flag_b = np.zeros((7, 7), dtype=np.int32)
        # DAT_0062a9e0[pow*21+other] — 1 = peace overture signal received from other
        self.g_peace_signal = np.zeros((7, 7), dtype=np.int32)
        # DAT_0062b7b0[pow*21+other] — non-zero = neutral/cease-fire state suppresses relation gain
        self.g_neutral_flag = np.zeros((7, 7), dtype=np.int32)
        # DAT_0062a2f8[pow*21+other] — count of consecutive stab-penalty steps applied
        self.g_stab_counter = np.zeros((7, 7), dtype=np.int32)
        # DAT_0062c580[pow*21+other] — cooperation score flag (spring/summer season)
        self.g_coop_score_flag_a = np.zeros((7, 7), dtype=np.int32)
        # DAT_004d4610/14[pow*21+other] — extended trust lo/hi words (cleared for eliminated)
        self.g_trust_extended_lo = np.zeros((7, 7), dtype=np.int32)
        self.g_trust_extended_hi = np.zeros((7, 7), dtype=np.int32)

        # ── PostProcessOrders globals ────────────────────────────────────────
        # Submitted-order list filled by DispatchSingleOrder / SUB handling:
        # each entry: {'power': int, 'src_prov': int, 'dst_prov': int,
        #              'flag_A': bool, 'flag_B': bool, 'flag_C': bool}
        self.g_submitted_order_list: list = []

        self.prov_to_id = {}
        self.adj_matrix = {}
        # M11 fix: coast-specific adjacency for fleets at multi-coast provinces.
        # Maps (prov_id, coast_suffix) → [adj_prov_ids] where coast_suffix is
        # e.g. '/NC', '/SC', '/EC'.  Only populated for provinces with coasts.
        # can_reach_by_type checks this when a fleet has a known coast.
        self.fleet_coast_adj: dict = {}
        # Fleet-specific adjacency matrix: prov_id → [adj_prov_ids] containing
        # only fleet-reachable neighbours.  Built during synchronize_from_game
        # using game.map.abuts('F', src, '-', dst) as the authoritative check.
        # This correctly excludes land-only borders (e.g. ANK→SMY, SEV→MOS)
        # that the terrain-only filter (not in land_provinces) missed.
        # Used by can_reach_by_type and MC trial fleet filtering.
        self.fleet_adj_matrix: dict = {}
        self.unit_info = {} # prov_id -> {'power': int, 'type': 'A'/'F', 'coast': str}
        # Set of province IDs whose underlying province type is 'WATER' (sea zones).
        # Populated once during synchronize_from_game from game.map.area_type().
        # Mirrors the flag at inner_state + prov_id * 0x24 + 4 == '\0' in the C++ original.
        self.water_provinces: frozenset = frozenset()
        # Set of province IDs whose area_type is 'LAND' (landlocked — no fleet access).
        # COAST provinces are in neither water_provinces nor land_provinces.
        self.land_provinces: frozenset = frozenset()

        # ── PhaseHandler snapshots (FUN_0040df20) ────────────────────────────
        # DAT_0062e4b8 — phase×power snapshot of g_ally_trust_score lo-word
        self.g_trust_snapshot    = np.zeros((4 * 21, 7), dtype=np.float64)
        # g_ally_trust_score hi-word snapshot (paired with lo-word per 64-bit struct)
        self.g_trust_snapshot_hi = np.zeros((4 * 21, 7), dtype=np.int32)
        # DAT_00631bd8 — phase×power snapshot of g_relation_score (DAT_00634e90)
        self.g_influence_snapshot = np.zeros((4 * 21, 7), dtype=np.int32)

        # ── MOVE_ANALYSIS / HOSTILITY opening-phase globals ──────────────────
        # DAT_00baed4x — opening sticky-mode flag; 1 = single original enemy found
        self.g_opening_sticky_mode: int = 0
        # DAT_00baed4x — power index of identified single original enemy
        self.g_opening_enemy: int = -1
        # DAT_00baed45 — 1 = best ally is fully pressured this turn
        self.g_ally_under_attack: int = 0
        # DAT_004c6bc4/c8/cc — top-3 opening ally candidates (-1 = empty)
        self.g_best_ally_slot0: int = -1
        self.g_best_ally_slot1: int = -1
        self.g_best_ally_slot2: int = -1
        # DAT_00baed42 — set when 3rd-proximity ally randomly selected
        self.g_triple_front_mode2: int = 0
        # DAT_00baed43 — set when all-front mode selected (≥ 75 random roll)
        self.g_triple_front_flag: int = 0

        # ── HOSTILITY globals (FUN_~0x42F200) ────────────────────────────────
        # DAT_00b9fdd8[power] — best mutual enemy per power (-1 = none)
        self.g_mutual_enemy_table = np.full(7, -1, dtype=np.int32)
        # DAT_004cf4c0[power] — betrayal counter; increments when formerly hostile goes neutral
        self.g_betrayal_counter  = np.zeros(7, dtype=np.int64)
        # DAT_004d55c8[power] — ally press dispatch counter (reset on first press turn)
        self.g_ally_press_count   = np.zeros(7, dtype=np.int32)
        # DAT_004d6248[power] — ally press hi-word counter
        self.g_ally_press_hi      = np.zeros(7, dtype=np.int32)
        # DAT_004d5480[power*2] / DAT_004d5484[power*2] — per-power int64 snapshot of
        # Albert's trust toward that power (lo-word / hi-word respectively).  Written
        # by HOSTILITY Block 4 every SPR/FAL press-on turn: zeroed first, then when
        # g_history_counter > 0 overwritten with g_ally_trust_score[own, p] before press
        # dispatch.  Read by evaluators/_common.py, evaluators/flags.py,
        # evaluators/handlers.py, scheduling.py (both _execute_aly_vss and DMZ gate).
        self.g_diplomacy_state_a  = np.zeros(7, dtype=np.int32)
        self.g_diplomacy_state_b  = np.zeros(7, dtype=np.int32)
        # DAT_0062480c — power index of the committed strategic enemy
        self.g_committed_enemy: int = -1
        # DAT_00633f20[power*5+rank] — pre-sorted power proximity ranks (stride 5)
        # Populated by map-init; None until set externally.
        self.g_power_proximity_rank: np.ndarray | None = None
        # DAT_00b84948[pow*21+other] — second influence scratch matrix (zeroed each turn)
        self.g_influence_matrix_b = np.zeros((7, 7), dtype=np.float64)
        # DAT_004d53d8[power*2] — lo-word: 1 = PCE proposal sent to this power this turn
        # DAT_004d53dc[power*2] — hi-word companion (always 0 after write)
        # Both zeroed each turn in the per-power reset loop.
        self.g_turn_order_hist_lo = np.zeros(7, dtype=np.int32)
        self.g_turn_order_hist_hi = np.zeros(7, dtype=np.int32)

        # DAT_00ba27b0[power*8] / DAT_00ba27b4[power*8] — per-power turn score (int64);
        # cleared in the per-power reset loop.  Used by RESPOND to track the best-scoring
        # ally's timestamp for response-timing gating.
        self.g_turn_score = np.zeros(7, dtype=np.int64)

        # DAT_00633768[power] — per-power active-turn flag; cleared each turn, set to 1
        # by RESPOND deceit path for the sender power.  Gated in the g_pos_analysis_list
        # walk: when response is YES, only register deviation entry if flag is set.
        self.g_power_active_turn = np.zeros(7, dtype=np.int32)

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

            # Build adjacency graph, water-province set, and land-province set.
            # Also build fleet_adj_matrix — fleet-specific adjacency that only
            # includes fleet-reachable neighbours.  Built using
            # game.map.abuts('F', src, '-', dst) as the authoritative check.
            # The diplomacy library's abut_list case convention (lowercase =
            # army-only) is incomplete — some coastal provinces list inland
            # neighbours as uppercase even though fleets cannot traverse them
            # (e.g. SEV lists 'MOS' uppercase but F SEV - MOS is illegal).
            water_prov_ids = set()
            land_prov_ids = set()
            for prov in self.prov_to_id:
                base_prov = prov.split('/')[0] if '/' in prov else prov
                pid = self.prov_to_id[prov]
                self.adj_matrix[pid] = []
                seen_adj_ids: set = set()
                for adj in game.map.abut_list(prov):
                    adj_base = adj.split('/')[0].upper() if '/' in adj else adj.upper()
                    adj_id = _upper_lookup.get(adj_base, -1)
                    if adj_id >= 0 and adj_id not in seen_adj_ids:
                        self.adj_matrix[pid].append(adj_id)
                        seen_adj_ids.add(adj_id)
                # Canonicalise adjacency order (AUDIT_moves_and_messages.md #6).
                # The C binary walks an OrderedSet keyed on province id, so
                # tie-break outcomes (first scorer wins, first supporter wins,
                # etc.) are deterministic by ascending province id. python-
                # diplomacy's abut_list returns map-definition order, which
                # may differ. Sort once at build time so every downstream
                # iteration matches C.
                self.adj_matrix[pid].sort()
                atype = game.map.area_type(base_prov)
                if atype == 'WATER':
                    water_prov_ids.add(pid)
                elif atype == 'LAND':
                    land_prov_ids.add(pid)
                # COAST provinces are in neither set — accessible by both unit types

            # Build fleet_adj_matrix using game.map.abuts('F', ...) as the
            # authoritative source.  For each province, check which of its
            # adj_matrix neighbours a fleet can actually reach.  This handles
            # all edge cases: land-only borders between coastal provinces
            # (ANK→SMY), inland neighbours of coastal provinces (SEV→MOS),
            # and multi-coast restrictions.
            _id_to_base: dict = {}
            for _name, _pid in self.prov_to_id.items():
                if '/' not in _name:
                    _id_to_base[_pid] = _name
            for pid, adj_ids in self.adj_matrix.items():
                src_name = _id_to_base.get(pid, '')
                if not src_name:
                    # Coast-suffixed entry — share parent's fleet adjacency
                    continue
                fleet_ids: list = []
                for adj_id in adj_ids:
                    dst_name = _id_to_base.get(adj_id, '')
                    if not dst_name:
                        continue
                    # game.map.abuts returns truthy (1) if legal, 0 if not.
                    # Also try coasted variants for multi-coast destinations.
                    if game.map.abuts('F', src_name, '-', dst_name):
                        fleet_ids.append(adj_id)
                    else:
                        # Try coasted variants (BUL/EC, BUL/SC, SPA/NC, etc.)
                        for coast in ('/NC', '/SC', '/EC', '/WC'):
                            if game.map.abuts('F', src_name, '-', dst_name + coast):
                                fleet_ids.append(adj_id)
                                break
                self.fleet_adj_matrix[pid] = fleet_ids  # already sorted (from adj_matrix)

            # M11 fix: build coast-specific fleet adjacency for multi-coast
            # provinces (STP, SPA, BUL).  Fleets on STP/NC can only reach
            # provinces adjacent to the north coast, not the south coast.
            self.fleet_coast_adj = {}
            for prov in self.prov_to_id:
                if '/' in prov:
                    # This IS a coast entry (e.g. 'STP/NC')
                    base, coast_suffix = prov.split('/', 1)
                    base_upper = base.upper()
                    pid = _upper_lookup.get(base_upper, -1)
                    if pid < 0:
                        continue
                    coast_key = '/' + coast_suffix.upper()
                    coast_adjs = set()
                    for adj in game.map.abut_list(prov):
                        adj_base = adj.split('/')[0].upper() if '/' in adj else adj.upper()
                        adj_id = _upper_lookup.get(adj_base, -1)
                        if adj_id >= 0:
                            coast_adjs.add(adj_id)
                    self.fleet_coast_adj[(pid, coast_key)] = sorted(coast_adjs)

            self.water_provinces = frozenset(water_prov_ids)
            self.land_provinces = frozenset(land_prov_ids)

            # Valid province IDs — the set of provinces that exist on the
            # game map.  C's per-province loops check an "alive" flag at
            # offset +3 of the per-province record (stride 0x24); provinces
            # beyond the map have this flag as '\0' and are skipped.  In
            # Python we use the adj_matrix key set as the equivalent gate.
            # Any loop that iterates `range(256)` for province scoring
            # should instead iterate `state.valid_provinces`.
            self.valid_provinces: frozenset = frozenset(self.adj_matrix.keys())
            self.num_valid_provinces: int = max(self.valid_provinces) + 1 if self.valid_provinces else 0

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
        self.g_sc_ownership.fill(0)
        self.g_sc_owner.fill(-1)
        self.g_own_reach_score.fill(0)
        self.unit_info.clear()
        # ── Per-call resets (mirror GenerateAndSubmitOrders.c top-of-fn) ──
        # The C binary explicitly reinitialises these at the top of every
        # GenerateAndSubmitOrders call:
        #   g_pos_analysis_list (DAT_00bb65cc)  — sentinel-list reinit, line 92-96
        #   g_press_sent_matrix (line 243)      — zeroed in per-power loop
        #   g_xdo_press_proposals               — staging for ComputePress, drained
        # Mirror that here.
        self.g_xdo_press_sent.fill(0)
        self.g_xdo_press_proposals.clear()
        self.g_pos_analysis_list.clear()

        # ── DO NOT clear: the following globals accumulate forever in C. ──
        # Wiping them in Python would break multi-phase commitment semantics
        # and re-emit dedup'd alliance/proposal events on every phase.
        #
        # g_broadcast_list     (DAT_00bb65ec) — received DAIDE press; the only
        #     write site is register_received_press, no destructor. An XDO
        #     announced in S1901M must still penalise contradicting
        #     candidates in F1901M+ until superseded.
        #
        # g_alliance_msg_tree   (DAT_00bbf638) — set of alliance-event keys
        #     used by BuildAllianceMsg/CheckAndInsertAllianceTreeEntry as a
        #     dedup so the same alliance event isn't re-broadcast. Inserts
        #     happen in CAL_BOARD/CAL_VALUE/FRIENDLY/GOF; no clear anywhere.
        #
        # g_accepted_proposals (DAT_00bb65d4) — tokens we've agreed to. Sole
        #     C write: CAL_VALUE.c:174 (FUN_00419300 = set_insert). Never
        #     cleared on the success path; only the failure-cleanup loop in
        #     RESPOND drains it (already mirrored in communications.py).
        #
        # g_proposal_history   (g_proposal_history_map) — keyed by proposal
        #     digest; used by BuildSupportProposals/BuildAndSendSUB/Process-
        #     Turn for "have we proposed/seen this before?" dedup. Only
        #     StdMap_FindOrInsert / StdMap_Insert in the C; no destructor.
        #
        # g_broadcast_list_watermark IS per-call (register_received_press
        # snapshots and rewinds it) — safe to clamp here for newcomers.
        self.g_broadcast_list_watermark = 0

        # Parse Ownership
        for power_name, centers in game.get_centers().items():
            if power_name in power_to_id:
                p_id = power_to_id[power_name]
                for center in centers:
                    prov = center.split('/')[0] if '/' in center else center
                    if prov in self.prov_to_id:
                        prov_id = self.prov_to_id[prov]
                        self.g_sc_ownership[p_id, prov_id] = 1
                        self.g_sc_owner[prov_id] = p_id
                        
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
                            # C initializes g_own_reach_score to 0; EnumerateHoldOrders
                            # populates it during scoring.  Do NOT seed to 1 here.
                            # Fixed 2026-04-23 (audit finding STA-1): was incorrectly
                            # setting to 1, inflating reach counts before scoring.
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
        self.g_near_end_game_factor = near_end

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

        # Populate g_retreat_list and g_order_hist_list from game order history.
        # g_retreat_list  = most-recent completed retreat phase (R suffix) orders.
        # g_order_hist_list = most-recent completed movement phase (M suffix) orders.
        # Both are cleared and repopulated each synchronize call (Python timing
        # differs from C++ ORD-handler timing; we read history instead).
        order_history = getattr(game, 'order_history', None)
        if order_history is not None and self.prov_to_id:
            self.g_retreat_list = []
            self.g_order_hist_list = []
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
                                self.g_retreat_list.append(rec)

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
                                self.g_order_hist_list.append(rec)

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

    def can_reach_by_type(self, src_prov: int, dst_prov: int,
                          unit_type: str, src_coast: str = '') -> bool:
        """Province adjacency gate with unit-type and coast filtering.

        Fleets can move to WATER or COAST provinces but NOT LAND (landlocked).
        Armies can move to LAND or COAST provinces but NOT WATER (sea zones).

        M11 fix: for fleets at multi-coast provinces (STP, SPA, BUL), if
        ``src_coast`` is provided (e.g. ``'/NC'``, ``'/SC'``), the check
        uses coast-specific adjacency from ``fleet_coast_adj`` instead of
        the base adjacency matrix.  This matches C's two-level coast-
        filtered search in AdjacencyList_FilterByUnitType.

        ``unit_type`` should be ``'F'`` or ``'A'`` (as stored in
        ``unit_info``), though ``'FLT'``/``'AMY'`` are also accepted.
        Falls back to ``can_reach`` for unknown types.
        """
        logger.debug("can_reach_by_type: src=%d dst=%d type=%s adj=%s", 
             src_prov, dst_prov, unit_type, self.adj_matrix.get(src_prov, []))
        # Fleet coast-specific adjacency check
        if unit_type in ('F', 'FLT') and src_coast:
            coast_key = src_coast.upper() if src_coast.startswith('/') else '/' + src_coast.upper()
            coast_adjs = self.fleet_coast_adj.get((src_prov, coast_key))
            if coast_adjs is not None:
                # Have coast-specific data: only allow destinations reachable
                # from this specific coast
                return dst_prov in coast_adjs
            # No coast data for this coast → fall through to base adjacency

        if unit_type in ('F', 'FLT'):
            # Use fleet_adj_matrix which only contains fleet-reachable
            # neighbours (uppercase entries from abut_list).  This correctly
            # excludes land-only borders between coastal provinces
            # (e.g. ANK→SMY) that the terrain-only filter missed.
            return dst_prov in self.fleet_adj_matrix.get(src_prov, [])
        if unit_type in ('A', 'AMY'):
            if dst_prov not in self.adj_matrix.get(src_prov, []):
                return False
            if dst_prov in self.water_provinces:
                return False   # army cannot enter sea zone
            return True
        # Unknown unit type — fall back to basic adjacency
        return dst_prov in self.adj_matrix.get(src_prov, [])

    def resolve_fleet_coast(self, src_prov: int, dst_prov: int) -> int:
        """Return the DAIDE coast token for a fleet moving from *src_prov* to
        *dst_prov*, or 0 if *dst_prov* is not a multi-coast province.

        In the C binary, each adjacency-list edge carries a coast token so
        ``BuildOrder_MTO`` receives the correct coast from the candidate BST
        node.  The Python ``adj_matrix`` only stores province IDs (no per-edge
        coast), so the MC trial passes ``coast=0`` everywhere.

        This helper performs a reverse lookup on ``fleet_coast_adj``:
        for each ``(dst_prov, coast_suffix)`` entry, check whether *src_prov*
        appears in the adjacency set.  If so, convert the suffix to the DAIDE
        coast token and return it.

        Standard multi-coast provinces: BUL (/EC, /SC), SPA (/NC, /SC),
        STP (/NC, /SC).
        """
        # Quick check: does dst_prov appear as a multi-coast province at all?
        # fleet_coast_adj keys are (prov_id, '/XX') tuples.
        _COAST_SUFFIX_TO_DAIDE = {
            '/NC': 0x4600, '/NE': 0x4602, '/EC': 0x4604,
            '/SC': 0x4606, '/WC': 0x460C, '/NW': 0x460E,
        }
        for (pid, coast_suffix), adj_list in self.fleet_coast_adj.items():
            if pid == dst_prov and src_prov in adj_list:
                return _COAST_SUFFIX_TO_DAIDE.get(coast_suffix, 0)
        return 0

    def get_max_threatening_adj_scs(self, prov_id: int, power_id: int) -> int:
        """Port of the tree-walk in EvaluateProvinceScore (FUN_00433ce0).

        Iterates provinces adjacent to *prov_id*.  For each adjacent province
        occupied by a unit belonging to a power other than *power_id*, checks:
          1. g_friendly_unit_flag[power_id, adj] — if set, this is a friendly
             unit and should NOT be counted as threatening.
          2. g_established_ally_flag[power_id, adj] — same exclusion.
          3. AdjacencyList_FilterByUnitType — the enemy unit must be able to
             actually reach *prov_id* given its unit type (army vs fleet
             terrain).  Python proxies this via ``can_reach_by_type``.

        Returns the maximum SC count among threatening (non-friendly,
        non-established-ally) adjacent enemy powers.

        Fix 2026-04-21 (H-1): Added friendly/established-ally exclusion and
        unit-type reachability check to match C tree walk.
        """
        max_scs = 0
        for adj in self.adj_matrix.get(prov_id, []):
            enemy_id = self.get_unit_power(adj)
            if enemy_id == -1 or enemy_id == power_id:
                continue
            # C: if g_friendly_unit_flag[power*0x100 + adj] == (1,0) → skip
            # Use 2D indexing when available, else 1D fallback.
            friendly_flag = 0
            ally_flag = 0
            if hasattr(self, 'g_friendly_unit_flag'):
                f = self.g_friendly_unit_flag
                if f.ndim == 2:
                    friendly_flag = int(f[power_id, adj])
                else:
                    friendly_flag = int(f[adj])
            if hasattr(self, 'g_established_ally_flag'):
                e = self.g_established_ally_flag
                if e.ndim == 2:
                    ally_flag = int(e[power_id, adj])
                else:
                    ally_flag = int(e[adj])
            if friendly_flag == 1 or ally_flag == 1:
                continue
            # C: AdjacencyList_FilterByUnitType + SubList_Find — verify
            # the enemy unit can actually reach prov_id.
            enemy_type = self.get_unit_type(adj)
            if enemy_type and not self.can_reach_by_type(adj, prov_id, enemy_type):
                continue
            sc_count = int(np.sum(self.g_sc_ownership[enemy_id]))
            if sc_count > max_scs:
                max_scs = sc_count
        return max_scs

    def candidate_set_contains(self, power: int, province: int) -> bool:
        return self.g_candidate_scores[power, province] > 0

    def get_candidate_score(self, power: int, province: int, iteration: int) -> float:
        return self.g_candidate_scores[power, province] # simplified fallback

    def get_enemy_reach(self, power_id: int, province: int) -> int:
        return int(self.g_enemy_reach_score[power_id, province])

    def get_trial_order_table(self, trial_state_data: np.ndarray):
        return {}
