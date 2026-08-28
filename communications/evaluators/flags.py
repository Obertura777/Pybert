"""Board-state flag computation (``FUN_004113d0``).

Split from communications/evaluators.py during the 2026-04 refactor.

Holds ``compute_order_dip_flags`` — the port of ``FUN_004113d0``.
Walks the current order table and derives the DIP-flag bitmask used by
the handlers and senders to decide whether to propose / accept orders.

Module-level deps: ``..state.InnerGameState``.
"""

from ...state import InnerGameState
from ._common import _NEUTRAL_POWER


def _flag_unit_power(unit) -> int | None:
    """Return ComputeOrderDipFlags' power value for a board occupant.

    C reads the unit token's high byte and preserves its power only for AMY;
    every other present unit type is represented as neutral power 0x14.
    """
    if unit is None:
        return None
    unit_type = str(unit.get('type', '')).upper()
    if unit_type in ('A', 'AMY', 'ARMY'):
        return int(unit.get('power', _NEUTRAL_POWER))
    return _NEUTRAL_POWER


def _exact_enemy(state: InnerGameState, power: int, num_powers: int) -> bool:
    return (
        0 <= power < num_powers
        and int(state.g_enemy_flag[power]) == 1
        and int(state.g_enemy_flag_hi[power]) == 0
    )


def _split_less_than(lo: int, hi: int, limit: int) -> bool:
    """C split-int64 comparison: signed high, then unsigned low."""
    return hi < 0 or (hi < 1 and (lo & 0xFFFFFFFF) < limit)


def compute_order_dip_flags(state: InnerGameState) -> None:
    """
    Port of ComputeOrderDipFlags (FUN_004113d0).

    Re-initialises the three diplomatic flags on every g_order_list node:
      flag1 (+0x1c): True  = province is genuinely contested vs. ordering power
      flag2 (+0x1d): True  = bilateral ally coordination is viable
      flag3 (+0x1e): True  = ordering power distrusts a unit at/near the province

    Called unconditionally from HOSTILITY Block 3 so that ProposeDMZ always
    sees fresh flags.

    Callees (all absorbed / already in unchecked.md):
      FUN_0047a948            — MSVC iterator validity assertion
      TreeIterator_Advance    — adjacency-set BST iterator step
      std_Tree_IteratorIncrement — g_order_list std::map iterator advance
    """
    own      = getattr(state, 'albert_power_idx', 0)
    press_on = (state.g_press_flag == 1)
    num_powers = int(getattr(state, 'g_num_powers', 7))
    dipl_a   = getattr(state, 'g_diplomacy_state_a', None)
    dipl_b   = getattr(state, 'g_diplomacy_state_b', None)

    for entry in state.g_order_list:
        province       = int(entry['province'])
        ordering_power = int(entry['ally_power'])

        # ── Init (lines 48/52/56 of decompile) ───────────────────────────────
        flag1 = True
        flag2 = True
        flag3 = False

        # ── Phase 1a: DAT_00ba2f70 check (lines 57–68) ──────────────────────────────
        # This is InitPositionForOrders' home-controller adjacency spread, not
        # the board province's current SC controller token.
        dip_owner = (int(state.g_order_dip_owner[province])
                     if province < len(state.g_order_dip_owner) else -1)
        if dip_owner == ordering_power:
            flag1 = False
        elif dip_owner == own:
            flag2 = False

        # ── Phase 1b: board unit at province (lines 69–85) ───────────────────
        # Unit belonging to own_power → not contested (flag1=0)
        # Unit belonging to ordering_power → ordering power already there (flag2=0)
        unit = state.unit_info.get(province)
        occ = _flag_unit_power(unit)
        if occ is not None and occ != _NEUTRAL_POWER:
            if occ == own:
                flag1 = False
            elif occ == ordering_power:
                flag2 = False

        # ── Phase 2: trust/stab check at province (lines 86–115) ─────────────
        # Only runs when a unit is present (*(char*)(board+prov*0x24+3) != '\0').
        if unit is not None:
            # Clear flag2 when the occupant is not a trustworthy ally of own_power:
            #   neutral, enemy-stab flagged, own unit, or zero trust.
            if occ == _NEUTRAL_POWER:
                flag2 = False
            elif _exact_enemy(state, occ, num_powers):
                flag2 = False
            elif occ == own:
                flag2 = False
            elif 0 <= occ < num_powers and (
                int(state.g_ally_trust_score[own, occ]) == 0 and
                int(state.g_ally_trust_score_hi[own, occ]) == 0
            ):
                flag2 = False

            # Set flag3 when ordering_power does not trust the occupant
            # (occ is neutral or ordering_power has zero trust in occ).
            if occ != ordering_power:
                if occ == _NEUTRAL_POWER or (
                    0 <= occ < num_powers and
                    int(state.g_ally_trust_score[ordering_power, occ]) == 0 and
                    int(state.g_ally_trust_score_hi[ordering_power, occ]) == 0
                ):
                    flag3 = True

        # ── Phase 3: adjacent-province units (inner loop, lines 116–177) ─────
        for adj_prov in state.get_unit_adjacencies(province):
            adj_unit = state.unit_info.get(adj_prov)
            if adj_unit is None:
                continue
            occ = _flag_unit_power(adj_unit)

            # Enemy-stab flag always clears flag2 (lines 142–147).
            if _exact_enemy(state, occ, num_powers):
                flag2 = False

            # Press-on block (lines 148–164).
            if press_on:
                # Ordering power's own unit at adj → skip remaining checks for
                # this adj province (goto LAB_004116fa in C).
                if occ == ordering_power:
                    continue
                if (occ != own and occ != _NEUTRAL_POWER
                        and 0 <= occ < num_powers):
                    t_hi = int(state.g_ally_trust_score_hi[own, occ])
                    t_lo = int(state.g_ally_trust_score[own, occ])
                    d_b  = int(dipl_b[occ]) if dipl_b is not None else 0
                    d_a  = int(dipl_a[occ]) if dipl_a is not None else 0
                    # int64 trust < 2  OR  DiplomacyState < 2
                    if (_split_less_than(t_lo, t_hi, 2)
                            or _split_less_than(d_a, d_b, 2)):
                        flag2 = False

            # flag3: ordering_power does not trust this adjacent occupant
            # (lines 165–172).
            if occ != ordering_power and occ != own and occ != _NEUTRAL_POWER:
                if (0 <= occ < num_powers and
                        int(state.g_ally_trust_score[ordering_power, occ]) == 0 and
                        int(state.g_ally_trust_score_hi[ordering_power, occ]) == 0):
                    flag3 = True

        # ── Write back ────────────────────────────────────────────────────────
        entry['flag1'] = flag1
        entry['flag2'] = flag2
        entry['flag3'] = flag3
