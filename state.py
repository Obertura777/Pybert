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
    src_location = parts[1].upper()
    src_str, _, src_coast = src_location.partition('/')
    src_prov  = prov_to_id.get(src_str, -1)
    if src_prov < 0:
        return None
    unit_type = 0 if unit_char != 'F' else 1

    rec = {
        'src_province': src_prov, 'unit_type': unit_type, 'power': power,
        'src_coast': src_coast,
        'order_type': 1,  # HLD default
        'dst_province': -1, 'sup_src': -1, 'sup_dst': -1, 'endgame_flag': 0,
        'flag_a': 0, 'flag_b': 0, 'flag_c': 0,
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
                        # dst_province = sup_dst: matrix[power, supporter, sup_dst] += 10 on success
                        rec['dst_province'] = rec['sup_dst']
                    else:
                        rec['order_type'] = 3  # SUP-HLD
                        # dst_province = sup_src: matrix[power, supporter, sup_src] += 10 on success
                        rec['dst_province'] = rec['sup_src']
            # flag_a marks this as a support order; flag_b/c filled later from result_history
            rec['flag_a'] = 1
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
    g_support_opportunities_set: "Any"
    g_support_proposals: "Any"
    g_support_trust_adj: "Any"
    g_trial_map: "Any"
    g_unit_presence: "Any"
    g_victory_threshold: "Any"
    g_xdo_dest_by_sender: "Any"
    g_xdo_global_dest_map: "Any"
    g_xdo_order_move_by_power: "Any"
    g_xdo_order_hold_by_power: "Any"
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
        self.g_attack_count = np.zeros((7, 256), dtype=np.int64)
        # DAT_005a48e8[pow*0x800+prov*8] — int64[pow*256+prov]; >10 = danger zone
        self.g_attack_history = np.zeros((7, 256), dtype=np.int64)
        # g_defense_score was a second binding of DAT_0055b0e8, which is
        # already bound to g_max_prov_score_per_power (see below).  Nothing
        # wrote it, so every reader saw zeros.  Removed 2026-08-12; readers
        # now use g_max_prov_score_per_power.
        # DAT_004f6ce8[pow*0x800+prov*8] — int64[pow*256+prov]; 1 = enemy unit present
        # Fixed 2026-04-20: int32→int64 to match C stride 0x800=2048 bytes/row
        self.g_enemy_presence = np.zeros((7, 256), dtype=np.int64)
        # DAT_00535ce8[pow*0x800+prov*8] — int64[pow*256+prov]; 1 = enemy can reach
        # Fixed 2026-04-20: int32→int64 to match C stride
        self.g_enemy_reach_score = np.zeros((7, 256), dtype=np.int64)
        # DAT_00520ce8 — despite the name, C's g_SCOwnership is a *unit
        # presence* flag: ScoreProvinces.c:786 is its only writer and it sets
        # [power, prov] = 1 while walking the unit list.  synchronize_from_game
        # additionally seeds it from real centre ownership so the pre-scoring
        # consumers (WIN build/remove candidates) can read it, but the first
        # score_provinces call of a phase overwrites it with unit presence.
        # Anything that means "does this power own the supply centre here"
        # must read g_board_sc_ownership instead — see below.
        self.g_sc_ownership = np.zeros((7, 256), dtype=np.int32)
        # Board supply-centre ownership, [power, prov] = 1 when `power`
        # currently owns the centre at `prov`. C's GameBoard_GetPowerRec is a
        # different query over each province's static home-power set and maps
        # to ``home_centers``/``get_power_rec``. Written only by current-board
        # synchronization; never cleared by score_provinces.
        self.g_board_sc_ownership = np.zeros((7, 256), dtype=np.int32)
        # M10 fix: int32→int64 to match C stride 0x800=2048 bytes/row
        # (consistent with g_enemy_presence and g_enemy_reach_score upgrades).
        self.g_target_flag = np.zeros((7, 256), dtype=np.int64)
        
        self.g_influence_matrix_raw = np.zeros((7, 7), dtype=np.float64)
        self.g_influence_matrix = np.zeros((7, 7), dtype=np.float64)
        self.g_alliance_score = np.zeros((7, 7), dtype=np.float64)
        self.g_ally_trust_score = np.zeros((7, 7), dtype=np.float64)
        self.g_ally_matrix = np.zeros((7, 7), dtype=np.int32)
        # Exact ALY/VSS triplets already proposed by this bot.  Unlike
        # g_pos_analysis_list (per phase) and g_ally_matrix (which strategic
        # recalculation may clear), this set persists for the game so an
        # unchanged alliance proposal is not blindly repeated every phase.
        # Keys are (own_power, target_power, mutual_enemy).
        self.g_aly_proposal_history: set[tuple[int, int, int]] = set()
        
        # Buffers for Heat Diffusion
        # Every value is stored as a signed 64-bit lo/hi pair in Albert.
        self.g_candidate_scores = np.zeros((7, 256), dtype=np.int64)
        # 10-round BFS candidate sets: g_candidate_bfs[power, round, province]
        # Maps to C: Albert + power*0x78 + 0x361c + round*0xc (ordered sets).
        # Round 0 seeded by score_provinces with attack_count * seed_weight;
        # rounds 1-9 are BFS propagations (prev[self] + Σprev[adj]) / 5.
        # WIN phases overwrite round 0 for own_power with 1.0/0.0 membership.
        self.g_candidate_bfs = np.zeros((7, 10, 256), dtype=np.int64)
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
        # Board province token +0x20 — current SC controller; -1 = neutral.
        # This is not DAT_00ba2f70: InitPositionForOrders builds that separate
        # adjacency-spread scratch table below.
        self.g_sc_owner = np.full(256, -1, dtype=np.int32)
        # DAT_00ba2f70[province] — home-SC controller spread used by
        # ApplyInfluenceScores and ComputeOrderDipFlags. -2 means conflicting
        # adjacent spreads and -1 means no qualifying controller.
        self.g_order_dip_owner = np.full(256, -1, dtype=np.int32)
        self.g_position_orders_initialized = False
        # DAT_004DA2F0 was misidentified as a separate "history gate" array.
        # Q-AIS-NEW-1 (resolved): it is the tail of g_heat_score; the real Pass 5
        # gate is g_unit_adjacency_count (DAT_004e1af0). No separate array needed.
        
        # 3. Adjacency lists and internal maps
        # Unused as of 2026-08-12: its only reader (register_convoy_fleet) was
        # misreading it as the hi word of g_prov_target_flag and now uses
        # g_target_flag2 (DAT_005ee8ec).  Nothing writes this array; kept only
        # so external callers that touch it keep working.
        self.g_province_access_flag = np.zeros((7, 256), dtype=np.int32)
        self.g_coverage_flag = np.zeros((7, 256), dtype=np.int32)
        self.g_convoy_reach_count = np.zeros((7, 256), dtype=np.int32)
        self.g_own_reach_score = np.zeros((7, 256), dtype=np.int32)
        # DAT_0052b4e8/ec[pow*0x800+prov*8] — one signed int64 total-reach
        # value.  ProcessTurn reads the combined pair as a positive marker;
        # DAT_0052b4ec is not the companion of g_attack_count.
        self.g_total_reach_score = np.zeros((7, 256), dtype=np.int64)
        self.g_enemy_mobility_count = np.zeros((7, 256), dtype=np.int32)
        # DAT_005460e8/ec[(prov+pow*0x40)*2] — max enemy reach per (power, prov); int32 proxy for 64-bit C array
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
        # `-G`/`-g` CLI arg. Python's main/run_7bots press-mode options set
        # this to 1 before game start to force g_history_counter=0 in
        # communications/inbound/history.py.
        self.g_minimal_press_mode = 0
        self.win_threshold = 18
        self.score_current = 0
        self.score_baseline = 0

        # g_ProximityScore (Ghidra named, int32)[pow*0x100+prov] — adjacency-weighted proximity count
        self.g_proximity_score = np.zeros((7, 256), dtype=np.int32)

        # 4. Monte Carlo Evaluation Variables

        # g_order_table: DAT_00baeda0[prov*0x1e + field*4]
        # 30-field per-province order state; fields defined by _F_* constants in monte_carlo.py
        self.g_order_table = np.zeros((256, 30), dtype=np.float64)

        # DAT_00baedb8/bc[prov*0x1e] — g_OrderTable fields 6/7: convoy-chain
        # or order score int64 pair.  Keep views so move builders feed the
        # evaluator's row reads.
        self.g_convoy_chain_score = self.g_order_table[:, 6]
        self.g_order_score_hi = self.g_order_table[:, 7]
        # DAT_00baedf4[prov*0x1e] — unit adjacency reach/hold factor.  This is
        # g_OrderTable field 21, not separate storage.
        self.g_unit_reach_score = self.g_order_table[:, 21]
        # DAT_00baedf8[prov*0x1e] — field 22, cut-support contribution.
        self.g_cut_support_risk = self.g_order_table[:, 22]
        # DAT_00baeddc[prov*0x1e] — peak hostile reach / support demand.  This
        # is not separate storage in C: it is g_OrderTable field 15.  Keep a
        # live view so ProcessTurn's aggregate writer and EvaluateOrderScore's
        # row-field reader cannot diverge.
        self.g_support_demand = self.g_order_table[:, 15]
        # DAT_00ba3770[province] — convoy source province score (0xffffffff = unset)
        self.g_convoy_source_prov = np.zeros(256, dtype=np.float64)

        # DAT_00633e90[province] — convoy active flag; set to 1 by BuildOrder_SUP_MTO /
        # BuildOrder_SUP_HLD when a support order targets a convoy fleet; read in Phase 1e
        # as a fallback acceptance gate.  Reset to 0 at the start of each trial.
        self.g_convoy_active_flag = np.zeros(256, dtype=np.int32)

        # DAT_00ba3b70[province] — per-province score flag; set to 1 by RegisterConvoyFleet
        # for adjacent provinces meeting the army-adj + target criteria; reset per trial.
        self.g_province_score_trial = np.zeros(256, dtype=np.int32)
        # g_ProvinceBase[province] — persistent per-scoring-pass retry counter.
        # ScoreProvinces clears it once, ProcessTurn increments a source when
        # it defers that unit back into the fleet-candidate tree.  The 500 and
        # 5000 thresholds relax later candidate pruning.
        self.g_province_base = np.zeros(256, dtype=np.int32)
        # DAT_00ba3f70[province] — count of own AMY-adjacent provinces; populated per trial
        # in Phase 1b unit scan; reset to 0 at the start of each trial.
        self.g_army_adj_count = np.zeros(256, dtype=np.int32)
        # Legacy compatibility container. RegisterConvoyFleet's recovered
        # guard is province terrain, not a per-trial registration set.
        self.g_convoy_fleet_registered: set = set()

        # Albert+0x4CFC — score-descending, equal-key-stable convoy candidates:
        # list[tuple[int, int]] = (score, prov).
        # Populated by ScoreConvoyFleet (FUN_00419790) in process_turn Phase 1g;
        # drained by MoveCandidate (FUN_00411cf0) in Phase 2. Phase 2 processes
        # from the front, matching C's highest-score-first tree walk.
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
        # Current game year; set by ParseNOW.
        self.g_year: int = 0
        # WIN-phase: own home supply centres that are currently controlled and
        # empty (C inner+0x24cc; populated by the ParseNOW winter path). These
        # are the legal site keys consumed by FUN_0044bd40's build selector.
        self.g_available_home_centers: frozenset = frozenset()
        # Structured build tokens already selected during FUN_0044bd40's
        # iterative WIN loop. ScoreProvinces feeds each exact key back with a
        # -2500 adjustment before the next build is ranked.
        self.g_selected_build_candidates: list[dict] = []

        self.final_score_set = np.zeros((7, 256), dtype=np.int64)
        # ARMY-vs-FLEET score channel.  C keys final_score_set (and the BFS
        # round sets) by the PAIR (province, unit-type/coast token) -- see
        # ScoreProvinces.c:465-495 writing a two-word key and
        # ScoreOrderCandidates_AllPowers.c:92-93 reading it back, with Phase 1c
        # gating on `AMY == (short)local_e0`, the KEY's token.  So army-space
        # and fleet-space hold DIFFERENT values for the same province.  The
        # port stored one number per province; `final_score_set` now carries the
        # ARMY channel and this carries the FLEET channel.
        self.final_score_set_flt = np.zeros((7, 256), dtype=np.int64)
        self.g_winter_score_a = np.zeros(256, dtype=np.float64)
        self.g_winter_score_b = np.zeros(256, dtype=np.float64)

        # DAT_00baed7c record slots +0x15..+0x1b.  The map is keyed by
        # (province, unit/coast token), just like final_score_set; each record
        # stores one live candidate weight per power.  EnumerateHoldOrders
        # seeds the occupying unit's cell with 30 and UpdateAllyOrderScore
        # clears/rebuilds these weights for every candidate group.
        self.g_key_weight = np.zeros((7, 256), dtype=np.int32)      # AMY keys
        self.g_key_weight_flt = np.zeros((7, 256), dtype=np.int32)  # FLT keys
        # Legacy compatibility view.  The former per-province 0.4/1.0 model
        # had no C counterpart and has no production reader.
        self.g_hold_weight = np.zeros(256, dtype=np.float64)
        # DAT_00baedb0[prov*0x1e] — g_OrderTable field 4.
        self.g_unit_move_prob = self.g_order_table[:, 4]
        # DAT_00baee00[prov*0x1e] — field 24 (lo word of the fleet/order
        # contribution pair consumed by EvaluateOrderScore's final pass).
        self.g_fleet_support_score = self.g_order_table[:, 24]

        # ── EnumerateHoldOrders output arrays ──────────────────────────────
        # g_unit_province_reach[power, province] = that power's score for the
        # province, taken from final_score_set (C: OrderedSet_FindOrInsert on
        # gamestate+0x4000+power*0xc returns a pointer to the int64 score).
        # Consumed by EvaluateAllianceScore for weighted reach-based scoring.
        self.g_unit_province_reach = np.zeros((7, 256), dtype=np.float64)
        # g_max_non_ally_reach[power, province] = max of those scores across
        # the unit's province and its non-ally adjacencies. Used internally
        # by EnumerateHoldOrders to drive the ally-trust comparison.
        self.g_max_non_ally_reach = np.zeros((7, 256), dtype=np.float64)

        # DAT_00bc1e1c — persistent topology index built by
        # EnumerateConvoyReach.  C's outer tree is keyed by reachable
        # (destination province, unit/coast token); its inner tree stores every
        # (source province, unit/coast token) that can reach that destination,
        # plus distance weights.  Python groups the outer coast keys by base
        # province and keeps the destination token on each BuildOrderSpec.
        self.g_build_candidate_list: dict = {}

        # this+0x2478 — BST sentinel node pointer (build-candidate BST for WIN phase).
        # Python represents the whole BST as a list of DAIDE order strings.
        # Populated by WIN handler (ComputeWinterBuilds); cleared by ResetPerTrialState.
        self.g_build_order_list: list = []
        # WIN build candidates preserve C's full key: province plus unit/coast
        # token.  A province-only set cannot represent both A MAR B and
        # F MAR B, or STP's two fleet coasts.
        self.g_adjustment_build_candidates: list[dict] = []
        self.g_adjustment_candidate_scores: dict[tuple, float] = {}
        self.g_adjustment_candidate_provinces: set[int] = set()
        # this+0x247c — BST _Mysize counter; explicit in C (ResetPerTrialState line 62).
        # Python equivalent: always equals len(g_build_order_list); reset to 0 in sync.
        self.g_build_order_list_size: int = 0
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

        # DAT_004d3e10/14 — g_assault_flag: lo/hi int32 pair per province.
        # Fourth designation slot. Reset to -1 by SnapshotProvinceState Phase 1;
        # populated by order-generation functions (FUN pending port). Marks
        # provinces Albert is actively targeting for assault this turn.
        self.g_assault_flag = np.full(256, -1, dtype=np.int64)
        self.g_assault_flag_hi = np.full(256, -1, dtype=np.int32)

        # Per-province peace-zone flag. Reset to 0 by SnapshotProvinceState;
        # set by diplomatic-resolution logic (FRIENDLY/HOSTILITY ports pending).
        self.g_peace_zone = np.zeros(256, dtype=np.int32)

        # Per-province defense-zone flag. Reset to 0 by SnapshotProvinceState;
        # set by defensive-coverage logic (InitPositionForOrders port pending).
        self.g_defense_zone = np.zeros(256, dtype=np.int32)

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

        # DAT_00baeb70[column_power + row_power * 0x15].  BuildSupportProposals
        # writes [prospective_supporter, requesting_mover_power], and
        # ProcessTurn scans the row for the power currently being simulated.
        self.g_xdo_press_sent = np.zeros((7, 7), dtype=np.int32)

        # Accumulated XDO support-proposal dicts emitted by BuildSupportProposals.
        # Each dict: {'type','supporter_prov','supporter_power','mover_prov',
        #             'dest','priority','from_power','to_power'}
        self.g_xdo_press_proposals: list = []

        # DAT_00bb67f8[power*0xc] — expected MTO/CTO orders received via XDO.
        # key = submitted unit source, value = promised destination.
        self.g_xdo_mto_opp_score: dict = {}

        # DAT_00bb68f8[power*0xc] — expected support orders received via XDO.
        # key = submitted supporter source, value = (supported source, destination).
        self.g_xdo_sup_attacker_score: dict = {}

        # DAT_00bb69f8[power*0xc] — accepted XDO move constraints.
        # XDO.c:166 stores the supported unit's source → proposed destination;
        # ProcessTurn.c Step 4 reads this exact per-power map.
        self.g_xdo_order_move_by_power: dict[int, dict] = {}

        # DAT_00bb6af8[power*0xc] — accepted XDO hold constraints.
        # XDO.c:190 inserts the supported unit's province; ProcessTurn.c Step 4
        # treats membership as a proposed hold (destination == source).
        self.g_xdo_order_hold_by_power: dict[int, set] = {}

        # Compatibility aliases for the old, incorrect support-scoring names.
        # Keep them identity-linked so external callers see the corrected data.
        self.g_xdo_sup_mto_score = self.g_xdo_order_move_by_power
        self.g_xdo_sup_hld_map = self.g_xdo_order_hold_by_power

        # DAT_00ba1fb0[province] — safe-reach score per province.
        # Set to max sorted-set rank of reachable uncontested provinces; 0xffffffff = no safe move.
        # Written by ComputeSafeReach; uint32 sentinel matches original C 0xffffffff.
        # C: int[] seeded with 0xffffffff (= -1) and overwritten with the
        # province's per-power score, which is a float in this port — so the
        # array is float64 with a -1.0 sentinel rather than uint32.
        self.g_safe_reach_score = np.full(256, -1.0, dtype=np.float64)

        # DAT_005658e8[pow*0x40+prov] — allied units' reachability (trust > 0).
        # Written by EnumerateHoldOrders reach loop when trust > 0.
        self.g_ally_reach_score = np.zeros((7, 256), dtype=np.float64)

        # DAT_005ba0e8[pow*0x100+prov] — provinces reachable via 2-hop move (support chain reach).
        # Written by ScoreOrderCandidates_AllPowers adjacency expansion.
        self.g_support_reach = np.zeros((7, 256), dtype=np.float64)

        # DAT_005c48e8[pow*0x100+prov] — provinces reachable via convoy chain.
        # Written by ScoreOrderCandidates_AllPowers BFS convoy expansion.
        self.g_convoy_reach = np.zeros((7, 256), dtype=np.float64)

        # DAT_00baed69 — 1 = another power is close to solo victory (defensive mode).
        self.g_other_power_lead_flag: int = 0

        # DAT_0062be94 — early-game adjacency score accumulator (Turn 1 only).
        self.g_early_game_bonus: int = 0
        # DAT_0062b7ac — per-trial count produced by ProcessTurn's late scan
        # of the DAT_00bbf644 support-opportunity map.
        self.g_other_score: int = 0
        # DAT_00bbf644/648 — std::map<int,int> populated by Step 3's
        # ScoreSupportOpp(source, destination) calls and consumed late in the
        # same trial to compute g_other_score.
        self.g_support_opp_map: dict[int, int] = {}

        # DAT_00bbf60c — globally key-sorted unique candidate proposal records.
        # Each entry: {'power', 'orders', 'score', 'heat_scores', 'deviation', 'pressure_cost'}.
        self.g_candidate_record_list: list = []

        # DAT_00b9a980 / DAT_00b95580 — MC-computed per-power, per-province pressure arrays.
        # Populated by UpdateAllyOrderScore per candidate; read by EvaluateAllianceScore
        # Phase 2 to drive threat scoring.  Cleared and rebuilt for each candidate.
        self.g_mc_province_pressure = np.zeros((7, 256), dtype=np.int32)
        self.g_mc_fleet_pressure = np.zeros((7, 256), dtype=np.int32)

        # DAT_00bb6cf8[pow*0xc] — per-power general candidate order sequences.
        # Maps power_idx -> [order_seq, ...] where each order_seq is a dict with
        # at least {'type': str}.  Cleared by _destroy_candidate_tree (FUN_00410cf0)
        # at the start of each ScoreOrderCandidates pass.
        self.g_general_orders: dict = {}

        # DAT_00bb65b4/b8 — cached std::set iterator (g_last_mto_insert).
        # Stores (order type, order destination) from the unit occupying the
        # last MTO destination, or None when that UnitList lookup returned end.
        # AssignSupportOrder reads this to undo a conflicting fleet support commitment.
        self.g_last_mto_insert: tuple | None = None

        # DAT_00bb66f8[power*0xc] — per-power deviation-detection tree.
        # Maps (power, prov) -> expected order type; 0 = no expectation recorded.
        self.g_deviation_tree: dict = {}

        # DAT_00bb6e00 — order-position map: set of province IDs that have a committed SUB entry.
        # Populated by DispatchSingleOrder; used to detect missing order assignments.
        self.g_sub_order_map: set = set()

        # DAT_005b98e8/ec[province] — one per-province signed int64 sentinel.
        # GenerateOrders initialises it to -1; ScoreOrderCandidates clears
        # selected unit provinces to 0 and promotes qualifying reachable ones
        # to 1.  ``g_top_reach_flag`` below is a compatibility name for this
        # exact same storage, not a second table.
        self.g_needs_rescore = np.full(256, -1, dtype=np.int64)

        # ── ScoreOrderCandidates_AllPowers extra globals (ported 2026-04-14) ──
        # DAT_0055b0e8/ec[(prov+pow*0x40)*2] — per-power province max score (int64)
        self.g_max_prov_score_per_power = np.full((7, 256), -(1 << 62), dtype=np.int64)
        # DAT_005508e8/ec — per-power province min score (int64)
        self.g_min_prov_score_per_power = np.full((7, 256), (1 << 62), dtype=np.int64)
        # DAT_005cf0e8/ec[(prov+pow*0x100)*2] — one signed int64
        # support-candidate mark.  Do not split this into a second low-word
        # array: ScoreOrderCandidates writes {lo=1, hi=0}, and readers test the
        # combined value as positive.
        self.g_support_candidate_mark = np.zeros((7, 256), dtype=np.int64)
        # DAT_005700e8/ec[(prov+pow*0x40)*2] — best-reachable-via-enemy threat path score
        self.g_threat_path_score = np.zeros((7, 256), dtype=np.int64)
        # DAT_005ee8ec — high word paired with g_prov_target_flag
        # (DAT_005ee8e8).  Kept separate because recovered readers explicitly
        # inspect the two words when recognizing {1, 0}, {2, 0}, and {-10, -1}.
        self.g_target_flag2 = np.zeros((7, 256), dtype=np.int64)
        # DAT_005e40ec — high word paired with g_target_flag
        # (DAT_005e40e8).  This is unrelated to total reach at
        # DAT_0052b4e8/ec despite the old ``attack_count2`` compatibility name.
        self.g_attack_count2 = np.zeros((7, 256), dtype=np.int64)
        # (g_ally_history_count was a stale alias for g_relation_score / DAT_00634e90;
        #  removed 2026-04-14 — see g_relation_score declaration below.)
        # DAT_004d2e10/14 — ally-designation-E counterpart (paired with _A)
        self.g_ally_designation_e = np.full(256, -1, dtype=np.int64)
        # Compatibility alias for DAT_005b98e8/ec.  Keep object identity so a
        # reset or write through either recovered semantic name is visible to
        # every reader.
        self.g_top_reach_flag = self.g_needs_rescore
        # DAT_005ee8e8 — low word paired with g_target_flag2; primary target
        # classification (1/2/-10/0).
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
        # DAT_00633780: CAL_BOARD's enemy-count-with-column-excluded matrix.
        # This is distinct from DAT_006340c0 / g_influence_rank_flag.
        self.g_rank_matrix = np.zeros((7, 7), dtype=np.int32)
        # DAT_00baed6a — 1 = Albert dominant leader (>75% SC influence, gap
        # >=2%). EvaluateAllianceScore halves its candidate-maximum penalty
        # while this flag is set (Albert.exe 0x43d738-0x43d75d).
        self.g_leading_flag: int = 0
        # DAT_0062480c — index of power close to solo victory
        self.g_near_victory_power: int = -1
        # DAT_00baed29 — draw flag; setter not found in decompiled sources (no-op default)
        self.g_draw_flag_baed29: int = 0
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

        # True once the server has sent OFF, DRW, or SLO (game ended).  The
        # inbound dispatcher/server handlers set it and the order-generation
        # loop reads it as its exit guard.
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
        # Home supply centres per power parsed from MDF supply-centres block.
        # {power_name (str): [prov_name (str), ...]}  — base province names, no coasts.
        # C equivalent: province[p]+0x14 std::set<int>, populated by the on-MDF vtable
        # hook (+0xd8) in the Albert subclass.  Consumed by hlo_dispatch to build
        # home_centers (mirroring SetOwnPower building inner+0x243c).
        self.g_mdf_home_sc: dict = {}

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

        # Current board SC counts and targets, refreshed from game ownership.
        # sc_count[power] — int[7]; filled by synchronize_from_game / cal_board
        self.sc_count = np.zeros(7, dtype=np.int32)
        # target_sc_count[power] — int[7]; win threshold per power (all 18 in std Dip)
        self.target_sc_count = np.full(7, 18, dtype=np.int32)
        # C: target_sc_cnt[power] — projected SC count after optimal moves.
        # InitScoringState copies from sc_count, then adjusts per urgency comparison.
        # Consumed by GenerateOrders to seed per-province move weights:
        #   target > curr  → seed = (target - curr + 2) * 500
        #   target <= curr → seed = 1000
        self.g_target_sc_cnt = np.zeros(7, dtype=np.int32)

        # DAT_006239e8 — per-power-pair urgency ratio-of-ratios, shape (7, 7).
        # g_urgency_ratio[outer, inner] = avg(build_urgency[outer,p]/build_urgency[inner,p])
        #                               / avg(build_urgency[inner,p]/build_urgency[outer,p])
        # Default 10.0 when denominator is zero (matches C: 0x41200000).
        # Written by _init_scoring_state; may be consumed by undecompiled downstream functions.
        self.g_urgency_ratio = np.full((7, 7), 10.0, dtype=np.float64)

        # Legacy array mirror of the authoritative g_best_ally_slot0/1/2
        # fields below. DAT_004c6bc4/c8/cc are best-ally candidates, not an
        # independent enemy queue; strategy consequence helpers keep this
        # compatibility view synchronized.
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

        # g_retreat_list: ordered-set of retreat-phase order nodes.
        # C address is Albert+0x2498/0x249c — NOT 0x248c/0x2490 as this comment
        # claimed before 2026-08-12.  Evidence: DEVIATE_MOVE.c:248 walks 0x2498
        # testing node+0x20 == 7 (RTO) and logs "during the retreat phase",
        # while both STABBED.c and DEVIATE_MOVE.c walk 0x248c testing 2/4/6
        # (MTO/SUP_MTO/CTO).  The data held here is correct; only the address
        # attribution was swapped with g_order_hist_list below.
        # Each entry: {'src_province': int, 'unit_type': int, 'power': int,
        #              'order_type': int (2=MTO,3=SUP-HLD,4=SUP-MTO,6=CTO,7=RTO,8=DSB),
        #              'dst_province': int, 'sup_src': int, 'sup_dst': int, 'endgame_flag': int}
        # In Python, populated from game.order_history at synchronize_from_game time.
        self.g_retreat_list: list = []

        # Albert+0x248c/0x2490 — g_order_hist_list: movement-phase order nodes.
        # (Address corrected 2026-08-12; see g_retreat_list above.)  This is the
        # list STABBED and DEVIATE_MOVE Phases 1/3 walk.
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
        # DAT_00b9fe88[power] — accepted EvaluateOrderProposal count for the
        # current movement turn.  send_GOF.c resets this before its ten scoring
        # passes; EvaluateOrderProposal.c increments it inside the unique,
        # non-deviating proposal gate.  RankCandidatesForPower and
        # BuildAndSendSUB both consume the resulting per-power count.
        self.g_power_call_count = np.zeros(7, dtype=np.int32)
        # DAT_00bc1e00 — std::set<power_idx> holding the participant powers of
        # the broadcast proposal node BuildAndSendSUB is currently running
        # trials for.  BuildAndSendSUB.c:230-236 clears it and re-copies the
        # node's own participant set (RegisterProposalOrders) at the top of
        # every trial iteration; UpdateScoreState.c and BuildAndSendSUB.c:283
        # then gate their per-power work on membership in it.
        #
        # DAT_00bc1e04 is this container's head sentinel, NOT a round counter:
        # BuildAndSendSUB.c:231-234 passes it as the last argument of the
        # standard SerializeOrders tree-destroy call, and BuildAndSendSUB.c:285
        # types it `int **` before comparing it against an iterator's node
        # pointer.  Both loops are therefore `find(power) != end()` tests.
        self.g_proposal_order_powers: set = set()
        # DAT_00baed48 — cumulative score counter
        self.g_cum_score: int = 0
        # DAT_0062d34c — score baseline (subtracted from cumulative)
        self.g_score_baseline: int = 0
        # DAT_0062e4b4 — alternative score accumulator
        self.g_score_alt: int = 0
        # DAT_0062e45c — duplicate slot-group accumulator maintained beside
        # g_score_alt by UpdateAllyOrderScore (diagnostic/delta tracking).
        self.g_score_group_duplicates: int = 0

        # ScoreProvinces weights — Albert ctor @ 0x00425e03–0x00425e3d.
        # Passed as uint64 (lo/hi dword pair); hi halves are always 0.
        # Albert+0x4d18 = SPR move_weight  → 0x2bc = 700
        # Albert+0x4d20 = SPR build_weight → 0x12c = 300
        # Albert+0x4d28 = FAL move_weight  → 0x258 = 600
        # Albert+0x4d30 = FAL build_weight → 0x190 = 400
        self.g_spr_move_weight: int = 700
        self.g_spr_build_weight: int = 300
        self.g_fal_move_weight: int = 600
        self.g_fal_build_weight: int = 400

        # ScoreOrderCandidates_AllPowers round weights — Albert ctor @ 0x00425e03/0x00425ead.
        # 10 × uint64 per phase; passed as the second arg (weight array pointer).
        # Albert+0x4d38: SPR weights  Albert+0x4d98: FAL weights
        # Rounds 0/1 are swapped between phases; rounds 2–9 identical.
        # All values confirmed from ctor dump 0x425dc2–0x425e91:
        #   EBX=5 @ 0x425dc2, EAX=0x3e8 @ 0x425ded, EBP=0xa @ 0x425df2, ECX=3 @ 0x425e91.
        #   [0]=0x1f4(imm) [1]=EAX [2]=0x1e(imm) [3]=EBP [4]=0x6(imm)
        #   [5]=EBX=5      [6–8 follow as immediates] [9]=EAX=1000
        # dominance_weight (war-mode bonus) = fal[0] - spr[0] = 500.
        # Rounds 2-9 share the same constructor stores for SPR and FAL.  In
        # particular EAX still holds 0x3e8 at the round-9 stores, so both final
        # weights are 1000.  A corpus-tuned SPR value of 1 briefly improved
        # submitted-order matches but contradicted the recovered constructor.
        self.g_spr_round_weights: list = [500, 1000, 30, 10, 6, 5, 4, 3, 2, 1000]
        self.g_fal_round_weights: list = [1000,  500, 30, 10, 6, 5, 4, 3, 2, 1000]

        # ScoreOrderCandidates_OwnPower's separate g_AttackCount multiplier
        # (Albert+0x4df8 for removes, +0x4e50 for builds). The recovered
        # function proves both int64 fields exist, but their constructor
        # immediates are absent from the supplied source corpus.
        self.g_win_remove_attack_weight: int = 0
        self.g_win_build_attack_weight: int = 0

        # ── CheckTimeLimit globals ───────────────────────────────────────────
        # g_network_state+0x20 — MTL timeout flag; set by timer thread when MTL fires
        self.mtl_expired: int = 0

        # ── BuildAndSendSUB globals ──────────────────────────────────────────
        # DAT_00bb65f0 — outer broadcast proposal list
        self.g_broadcast_list: list = []
        # DAT_00baed60 — g_broadcast_list size watermark after RegisterReceivedPress
        self.g_broadcast_list_watermark: int = 0
        # DAT_00bb6df4 — XDO proposal dedup set; compound (province, order_type, target_dest)
        # keys mirroring C's FUN_00410980 (lookup) / FUN_00419300 (insert) key-sequence dedup.
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
        # _DAT_00baed4c / _DAT_00baed50 — previous accumulator snapshots used
        # to derive BuildAndSendSUB's per-trial delta arrays.
        self.g_trial_prev_score_alt: int = 0
        self.g_trial_prev_score_baseline: int = 0
        # DAT_00bbf690/94[pow*0x3c] — current best order sequence per-power
        self.g_current_best_order: dict = {}
        # Direct candidate-record pointers for the same slots.  The C table
        # stores node pointers; retaining them alongside the compatibility
        # order lists avoids reconstructing semantic keys during rescoring.
        self.g_current_best_order_records: dict = {}
        # DAT_00bc0a40/44[pow*0xf0] — backup of best orders at best-trial point
        self.g_best_order_backup: dict = {}
        # DAT_00baed94/98 — press deal records (earlier proposals received)
        self.g_deal_list: list = []
        # DAT_00baed98 is the authoritative proposal-history map used by
        # BuildSupportProposals.  Keep the semantic name bound to the same
        # container from construction, as send_GOF does after clearing it.
        self.g_proposal_history_map = self.g_deal_list
        # DAT_00bb65c8/cc — proposal-analysis list. Each entry carries exact
        # tokens plus participant, affirmative, and rejection power sets.
        # Cleared each turn; used for dedup, ACK bookkeeping, and GOF gating.
        self.g_pos_analysis_list: list = []
        # DAT_00bb65d4 — accepted proposals this turn (YES results from EvaluatePress)
        self.g_accepted_proposals: list = []
        # DAT_00bbf638 — alliance-message BST keyed by elapsed-time event ids.
        self.g_alliance_msg_tree: set = set()
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
        # DAT_00ba2884:ba2880 is g_turn_start_time, set at each order turn.
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
        # SetTurnDeadline target — absolute epoch-seconds. process_hst seeds it
        # for the current phase; GenerateAndSubmitOrders rearms it every turn.
        self.g_turn_deadline: float = 0.0

        # ── CancelPriorPress globals ─────────────────────────────────────────
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
        # g_relation_history was a second binding of the same C global
        # (DAT_00634e90) that no code ever wrote, so every reader saw zeros.
        # Removed 2026-08-12; readers now use g_relation_score.
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
        # Multi-coast provinces: base prov_id → tuple of coast-variant prov_ids
        # (e.g. SPA → (SPA/NC, SPA/SC)).  C keys its score trees by
        # (province, unit/coast TOKEN), so a coastal supply centre carries one
        # FLT key per coast and no plain-FLT key at all.  The port splits keys
        # across province ids instead, which leaves the base id holding a
        # fleet node with no fleet adjacency; this map lets the fleet BFS and
        # `fss()` recombine the coast tokens back into the base province the
        # way C's per-province dedup does.
        self.coast_variants: dict = {}
        # Fleet-specific adjacency matrix: prov_id → [adj_prov_ids] containing
        # only fleet-reachable neighbours.  Built during synchronize_from_game
        # using game.map.abuts('F', src, '-', dst) as the authoritative check.
        # This correctly excludes land-only borders (e.g. ANK→SMY, SEV→MOS)
        # that the terrain-only filter (not in land_provinces) missed.
        # Used by can_reach_by_type and MC trial fleet filtering.
        self.fleet_adj_matrix: dict = {}
        # ParseNOWUnit keeps ordinary and dislodged units in distinct C sets
        # (+0x2450 and +0x245c).  `unit_info` is the ordinary/active set used
        # by movement generation; dislodged units must never appear there.
        self.unit_info = {} # prov_id -> {'power': int, 'type': 'A'/'F', 'coast': str}
        self.dislodged_unit_info = {}
        # Set of province IDs whose underlying province type is 'WATER' (sea zones).
        # Populated once during synchronize_from_game from game.map.area_type().
        # Mirrors the flag at inner_state + prov_id * 0x24 + 4 == '\0' in the C++ original.
        self.water_provinces: frozenset = frozenset()
        # Set of province IDs whose area_type is 'LAND' (landlocked — no fleet access).
        # COAST provinces are in neither water_provinces nor land_provinces.
        self.land_provinces: frozenset = frozenset()
        # Set of province IDs whose area_type is 'SHUT' (impassable, e.g. Switzerland).
        # No unit can ever enter a SHUT province; they are excluded from adj_matrix
        # entirely so they never appear as valid move destinations.
        self.shut_provinces: frozenset = frozenset()
        # Province-record byte +3: nonzero for a supply centre. Populated from
        # the map's SC list during synchronization.
        self.sc_provinces: set = set()

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
        # DAT_00b9fdd8[power] — best mutual enemy per power (-1 = none).
        # CAL_BOARD temporarily fills the same storage with the near-victory
        # power before HOSTILITY's mutual-enemy rebuild.
        self.g_mutual_enemy_table = np.full(7, -1, dtype=np.int32)
        # DAT_004cf4c0[power*2] / DAT_004cf4c4[power*2] — per-power int64 peace counter.
        # Incremented (HOSTILITY Block 5) each turn that trust[own,p]==0 and
        # g_enemy_flag[p]==0; reset when trust>0 AND relation>14, or relation<0;
        # cleared when lo >= 10 and season == SPR.  Used in peace-overture gate
        # (HOSTILITY lines 447-448: counter_lo < 2 bypasses the 15% rand check).
        self.g_peace_counter  = np.zeros(7, dtype=np.int64)
        # DAT_004d55c8[power] — ally press dispatch counter (reset on first press turn)
        self.g_ally_press_count   = np.zeros(7, dtype=np.int32)
        # DAT_004d6248[power*2] — ally press hi-word counter (lo-word of int64 pair)
        self.g_ally_press_hi      = np.zeros(7, dtype=np.int32)
        # DAT_004d624c[power*2] — hi-word companion to g_ally_press_hi
        self.g_ally_press_hi_ext  = np.zeros(7, dtype=np.int32)
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

        # ── SnapshotProvinceState arrays ─────────────────────────────────────
        # DAT_004d0e10 — SPR/FAL snapshot of g_ally_designation_b lo
        self.g_spr_desig_b = np.full(256, -1, dtype=np.int64)
        # DAT_004d0e14 — SPR/FAL snapshot of g_ally_designation_b hi
        self.g_spr_desig_b_hi = np.full(256, -1, dtype=np.int32)
        # DAT_004d1610 — SPR/FAL snapshot of g_ally_designation_a lo
        self.g_spr_desig_a = np.full(256, -1, dtype=np.int64)
        # DAT_004d1614 — SPR/FAL snapshot of g_ally_designation_a hi
        self.g_spr_desig_a_hi = np.full(256, -1, dtype=np.int32)
        # DAT_004d1e10 — SPR/FAL snapshot of g_ally_designation_c lo
        self.g_spr_desig_c = np.full(256, -1, dtype=np.int64)
        # DAT_004d1e14 — SPR/FAL snapshot of g_ally_designation_c hi
        self.g_spr_desig_c_hi = np.full(256, -1, dtype=np.int32)

        # DAT_005d98e8/ec — SPR/FAL snapshot of g_target_flag (shape (7, 256)).
        # Read by _deviate_move (bot.strategy) as g_AttackMap; falls back to
        # g_target_flag when not populated by SnapshotProvinceState.
        self.g_AttackMap = np.zeros((7, 256), dtype=np.int64)

        # DAT_004cf610 — SUM/AUT snapshot of g_ally_designation_b lo
        self.g_sum_desig_b = np.full(256, -1, dtype=np.int64)
        # DAT_004cf614 — SUM/AUT snapshot of g_ally_designation_b hi
        self.g_sum_desig_b_hi = np.full(256, -1, dtype=np.int32)
        # DAT_004cfe10 — SUM/AUT snapshot of g_ally_designation_a lo
        self.g_sum_desig_a = np.full(256, -1, dtype=np.int64)
        # DAT_004cfe14 — SUM/AUT snapshot of g_ally_designation_a hi
        self.g_sum_desig_a_hi = np.full(256, -1, dtype=np.int32)
        # DAT_004d0610 — SUM/AUT snapshot of g_ally_designation_c lo
        self.g_sum_desig_c = np.full(256, -1, dtype=np.int64)
        # DAT_004d0614 — SUM/AUT snapshot of g_ally_designation_c hi
        self.g_sum_desig_c_hi = np.full(256, -1, dtype=np.int32)

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
            #
            # Pass 1: identify SHUT province IDs (impassable, e.g. Switzerland).
            # C's map data never includes SHUT provinces as valid destinations;
            # they are excluded from adj_matrix so they never appear as move
            # targets or BFS heat nodes.
            shut_prov_ids: set = set()
            for prov in self.prov_to_id:
                base_prov = prov.split('/')[0] if '/' in prov else prov
                if game.map.area_type(base_prov) == 'SHUT':
                    shut_prov_ids.add(self.prov_to_id[prov])
            self.shut_provinces = frozenset(shut_prov_ids)

            water_prov_ids = set()
            land_prov_ids = set()
            for prov in self.prov_to_id:
                base_prov = prov.split('/')[0] if '/' in prov else prov
                pid = self.prov_to_id[prov]
                if pid in shut_prov_ids:
                    continue  # SHUT provinces get no adj_matrix entry
                self.adj_matrix[pid] = []
                seen_adj_ids: set = set()
                for adj in game.map.abut_list(prov):
                    adj_base = adj.split('/')[0].upper() if '/' in adj else adj.upper()
                    adj_id = _upper_lookup.get(adj_base, -1)
                    if adj_id >= 0 and adj_id not in seen_adj_ids and adj_id not in shut_prov_ids:
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
                    # Populate fleet_adj_matrix for the coast-variant province ID
                    # (e.g. STP/SC id=65) so Phase 2 lookups work correctly.
                    coast_pid = self.prov_to_id.get(prov, -1)
                    if coast_pid >= 0 and coast_adjs:
                        self.fleet_adj_matrix[coast_pid] = sorted(coast_adjs)
                        self.coast_variants.setdefault(pid, []).append(coast_pid)

            # Freeze and sort so BFS iteration order is deterministic.
            self.coast_variants = {
                base: tuple(sorted(set(variants)))
                for base, variants in self.coast_variants.items()
            }

            self.water_provinces = frozenset(water_prov_ids)
            self.land_provinces = frozenset(land_prov_ids)

            # Valid province IDs — the set of provinces that exist on the
            # game map. Province-record byte +3 is the supply-centre flag, not a map-
            # validity flag; use the adjacency keys for validity instead.
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
        self.g_board_sc_ownership.fill(0)
        self.g_sc_owner.fill(-1)
        self.g_order_dip_owner.fill(-1)
        self.g_own_reach_score.fill(0)
        self.unit_info.clear()
        self.dislodged_unit_info.clear()
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
        # DAT_00bb65ec/f0/f4 — broadcast-record tree, header, and size.
        # GenerateAndSubmitOrders.c:92-101 destroys and reinitializes this
        # tree on every call.  synchronize_from_game runs before the client
        # drains the new phase's queued messages, so current-turn press is
        # registered after this clear while prior-phase nodes are discarded.
        self.g_broadcast_list.clear()

        # ── Do not clear here: these lifetimes end elsewhere or persist. ──
        # Wiping them during synchronization would break commitment semantics
        # or erase state before its source-faithful consumer runs.
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
        #     digest; used by BuildSupportProposals/BuildAndSendSUB/ProcessTurn.
        #     send_GOF clears it immediately before its ten ProcessTurn rounds,
        #     then BuildSupportProposals repopulates it within those rounds.
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
                        self.g_board_sc_ownership[p_id, prov_id] = 1
                        self.g_sc_owner[prov_id] = p_id
                        
        # Register unit ownership. diplomacy.Game.get_units() deliberately
        # includes dislodged units with a leading '*'; C ParseNOWUnit stores
        # those in +0x245c rather than the active +0x2450 set.
        for power_name, units in game.get_units().items():
            if power_name in power_to_id:
                p_id = power_to_id[power_name]
                for unit_str in units:
                    parts = unit_str.split()
                    if len(parts) >= 2:
                        is_dislodged = parts[0].startswith('*')
                        unit_type = parts[0].lstrip('*')
                        prov = parts[1].split('/')[0]
                        coast = parts[1].split('/')[1] if '/' in parts[1] else ''
                        if prov in self.prov_to_id:
                            prov_id = self.prov_to_id[prov]
                            # C initializes g_own_reach_score to 0; EnumerateHoldOrders
                            # populates it during scoring.  Do NOT seed to 1 here.
                            # Fixed 2026-04-23 (audit finding STA-1): was incorrectly
                            # setting to 1, inflating reach counts before scoring.
                            info = {
                                'power': p_id,
                                'type': unit_type,
                                'coast': coast,
                            }
                            if is_dislodged:
                                power = getattr(game, 'powers', {}).get(power_name)
                                retreat_map = getattr(power, 'retreats', {}) if power else {}
                                retreat_key = f"{unit_type} {parts[1]}"
                                info['retreats'] = list(retreat_map.get(retreat_key, []))
                                self.dislodged_unit_info[prov_id] = info
                            else:
                                self.unit_info[prov_id] = info
                            
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

                # Cross-reference result_history to set flag_b / flag_c on each record.
                # result_history[phase] is keyed by unit string ("A PAR", "F NTH", ...).
                # BOUNCE or CUT → flag_b=1; DISLODGED → flag_c=1.
                result_phase = {}
                raw_rh = getattr(game, 'result_history', None)
                if raw_rh is not None:
                    try:
                        result_phase = dict(raw_rh.get(last_movement_key, {}))
                    except Exception:
                        result_phase = {}
                if result_phase:
                    # Build lookup: (unit_type_int, province_id) → (flag_b, flag_c)
                    _result_lookup: dict = {}
                    for unit_str, results in result_phase.items():
                        parts = str(unit_str).strip().split()
                        if len(parts) < 2:
                            continue
                        u_type = 0 if parts[0].upper() == 'A' else 1
                        # Movement/retreat records store the base province ID.
                        # Prefer that same key for a coasted result such as
                        # ``F STP/SC``; choosing the coast-variant ID first
                        # prevents the result flags from matching the record.
                        prov_str = parts[1]
                        prov_id = self.prov_to_id.get(
                            prov_str.split('/')[0],
                            self.prov_to_id.get(prov_str, -1),
                        )
                        if prov_id < 0:
                            continue
                        flag_b = flag_c = 0
                        for r in results:
                            rname = str(r).lower()
                            if ':' in rname:
                                rname = rname.split(':', 1)[1]
                            if rname in ('bounce', 'cut'):
                                flag_b = 1
                            elif rname == 'dislodged':
                                flag_c = 1
                        _result_lookup[(u_type, prov_id)] = (flag_b, flag_c)
                    for rec in self.g_order_hist_list:
                        key = (int(rec.get('unit_type', 0)), int(rec.get('src_province', -1)))
                        fb, fc = _result_lookup.get(key, (0, 0))
                        rec['flag_b'] = fb
                        rec['flag_c'] = fc

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

    def get_power_rec(self, power_id: int, prov_id: int) -> bool:
        """Port of GameBoard_GetPowerRec (Source/utils/GameBoard_GetPowerRec.c).

        The C function is an STL ordered-set lower_bound lookup — it returns an
        iterator pair whose begin==end signals "not found".  Callers check
        found/not-found; the record value itself is not used beyond presence.

        The province record's set is the static list of powers for which the
        province is a home supply centre; it is not current control.  Use
        ``g_board_sc_ownership`` for current centre ownership and
        ``unit_info.get(prov_id)`` for unit presence.
        """
        return prov_id in self.home_centers.get(power_id, frozenset())

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
        # Fleet coast-specific source adjacency check
        if unit_type in ('F', 'FLT', 'FLEET') and src_coast:
            coast_key = src_coast.upper() if src_coast.startswith('/') else '/' + src_coast.upper()
            coast_adjs = self.fleet_coast_adj.get((src_prov, coast_key))
            if coast_adjs is not None:
                # Have coast-specific data: only allow destinations reachable
                # from this specific coast
                return dst_prov in coast_adjs
            # No coast data for this coast → fall through to base adjacency

        if unit_type in ('F', 'FLT', 'FLEET'):
            # Use fleet_adj_matrix which only contains fleet-reachable
            # neighbours (uppercase entries from abut_list).  This correctly
            # excludes land-only borders between coastal provinces
            # (e.g. ANK→SMY) that the terrain-only filter missed.
            _fadj = self.fleet_adj_matrix.get(src_prov, [])
            if _fadj:
                return dst_prov in _fadj
            # Fallback for units stored at base province ID but positioned on
            # a specific coast (e.g. F STP/SC stored at STP base id=66).
            # Check all coast variants of this province.
            for (_pid, _ck), _cadjs in self.fleet_coast_adj.items():
                if _pid == src_prov and dst_prov in _cadjs:
                    return True
            return False
        if unit_type in ('A', 'AMY', 'ARMY'):
            if dst_prov not in self.adj_matrix.get(src_prov, []):
                return False
            if dst_prov in self.water_provinces:
                return False   # army cannot enter sea zone
            return True
        # Unknown unit type — fall back to basic adjacency
        return dst_prov in self.adj_matrix.get(src_prov, [])

    def get_reachable_edges(
        self, src_prov: int, unit_type: str, src_coast: str = '',
    ) -> list[tuple[int, str, str]]:
        """Return C-style destination keys for a typed adjacency walk.

        Each result is ``(destination province, unit type, destination coast)``.
        C's adjacency nodes carry that complete key into chained lookups; a
        base-province-only result would let a fleet enter one coast and leave
        through another.
        """
        normalized_type = str(unit_type).upper()
        is_fleet = normalized_type in ('F', 'FLT', 'FLEET')
        is_army = normalized_type in ('A', 'AMY', 'ARMY')
        edge_type = 'F' if is_fleet else 'A'
        reach_type = edge_type if (is_fleet or is_army) else normalized_type
        result: list[tuple[int, str, str]] = []
        for destination in self.adj_matrix.get(src_prov, []):
            if not self.can_reach_by_type(
                src_prov, destination, reach_type, src_coast,
            ):
                continue
            if not is_fleet:
                result.append((int(destination), edge_type, ''))
                continue

            destination_coasts = sorted({
                str(coast).upper()
                for (province, coast), reverse_adjacencies
                in self.fleet_coast_adj.items()
                if int(province) == int(destination)
                and src_prov in reverse_adjacencies
            })
            if destination_coasts:
                result.extend(
                    (int(destination), edge_type, coast)
                    for coast in destination_coasts
                )
            else:
                result.append((int(destination), edge_type, ''))
        return result

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
            '/SE': 0x4606, '/SC': 0x4608, '/SW': 0x460A,
            '/WC': 0x460C, '/NW': 0x460E,
        }
        for (pid, coast_suffix), adj_list in self.fleet_coast_adj.items():
            if pid == dst_prov and src_prov in adj_list:
                return _COAST_SUFFIX_TO_DAIDE.get(coast_suffix, 0)
        return 0

    def get_max_threatening_adj_scs(self, prov_id: int, power_id: int) -> int:
        """Port of the tree-walk in EvaluateProvinceScore (FUN_00433ce0).

        Iterates provinces adjacent to *prov_id*.  For each adjacent province
        the C code gates on two independent SC-flag tables before scoring:
          1. DAT_004f6ce8 = g_enemy_presence[power_id, adj] — set when the
             unit at *adj* is a confirmed enemy of *power_id* (low trust).
          2. DAT_0050bce8 = g_established_ally_flag[power_id, adj] — set when
             the unit is from a power with high trust but relation score <= 9.
        If NEITHER flag is 1 the C code jumps to LAB_00433efb (loop advance),
        i.e. the province is skipped.  If EITHER is 1 the C code proceeds to a
        second FindOrInsert with a different key buffer (local_8 vs local_10)
        to read curr_sc_cnt for the adjacent unit's owner.
          3. AdjacencyList_FilterByUnitType + SubList_Find — the unit must be
             able to physically reach *prov_id* given its type (army/fleet).

        Returns the maximum curr_sc_cnt among qualifying adjacent powers.
        """
        max_scs = 0
        for adj in self.adj_matrix.get(prov_id, []):
            enemy_id = self.get_unit_power(adj)
            if enemy_id == -1 or enemy_id == power_id:
                continue
            # Dual-path SC gate: include only if g_enemy_presence OR
            # g_established_ally_flag is set; skip neutrals/friendlies.
            enemy_presence = int(self.g_enemy_presence[power_id, adj])
            established_ally = int(self.g_established_ally_flag[power_id, adj])
            if enemy_presence != 1 and established_ally != 1:
                continue
            # C: AdjacencyList_FilterByUnitType + SubList_Find — verify
            # the unit can actually reach prov_id.
            enemy_type = self.get_unit_type(adj)
            enemy_coast = str(self.unit_info.get(adj, {}).get('coast', ''))
            if enemy_type and not self.can_reach_by_type(
                    adj, prov_id, enemy_type, enemy_coast):
                continue
            sc_count = int(self.sc_count[enemy_id])
            if sc_count > max_scs:
                max_scs = sc_count
        return max_scs

    def candidate_set_contains(self, power: int, province: int) -> bool:
        return self.g_candidate_bfs[power, 0, province] > 0

    def fss(self, power: int, province: int, unit_type=None) -> float:
        """final_score_set for the (province, token) key implied by unit_type.

        C looks this up with a two-word key; the port splits it into an ARMY
        channel (`final_score_set`) and a FLEET channel (`final_score_set_flt`).
        Callers that know which unit is moving must say so.
        """
        if unit_type in ('F', 'FLT'):
            return float(self.final_score_set_flt[power, province])
        return float(self.final_score_set[power, province])

    def key_weight(self, power: int, province: int, unit_type=None) -> int:
        """Return DAT_00baed7c's live +0x15 weight for a token key."""
        table = self.g_key_weight_flt if unit_type in ('F', 'FLT') else self.g_key_weight
        return int(table[power, province])

    def add_key_weight(self, power: int, province: int, value: int,
                       unit_type=None) -> None:
        """Accumulate one UpdateAllyOrderScore group into a token key."""
        table = self.g_key_weight_flt if unit_type in ('F', 'FLT') else self.g_key_weight
        table[power, province] += int(value)

    def get_candidate_score(self, power: int, province: int, iteration: int) -> float:
        return float(self.g_candidate_bfs[power, iteration, province])

    def get_enemy_reach(self, power_id: int, province: int) -> int:
        return int(self.g_enemy_reach_score[power_id, province])

    def get_trial_order_table(self, trial_state_data: np.ndarray):
        return {}
