"""DAIDE <-> DipNet location, unit, and order translation.

Split from utils.py during the 2026-04 refactor.

Bidirectional translators between DAIDE protocol tokens and the DipNet
text format used by the ``diplomacy`` library. Organized bottom-up:

  * ``dipnet_location`` / ``daidefy_location``     — coast-aware location.
  * ``dipnet_unit``     / ``daidefy_unit``         — unit notation.
  * ``get_unit_power``                              — owner lookup via Game.
  * ``dipnet_order``    / ``daidefy_order``        — full order string.

Module-level deps: ``diplomacy.Game`` (for ``get_unit_power`` /
``daidefy_unit``), ``.tokens`` for the location lookup tables.
"""

from typing import List

from diplomacy import Game

from .tokens import DIPNET2DAIDE_LOC, DAIDE2DIPNET_LOC

def dipnet_location(loc: str) -> str:
    # coasts
    if " " in loc:
        loc = loc.replace("(", "").replace(")", "").strip()
        prov, coast = loc.split(" ")
        prov = prov.strip()
        coast = coast.strip()
        return "/".join([prov, coast[:-1]])
    else:
        if loc in DAIDE2DIPNET_LOC:
            return DAIDE2DIPNET_LOC[loc]

    return loc


def daidefy_location(loc: str, mto_prov_no_coast: bool = False) -> str:
    """Converts DipNet-style location to DAIDE-style location

    E.g.
    BUL/EC --> ( BUL ECS )
    STP/SC --> ( STP SCS )
    ENG    --> ECH
    PAR    --> PAR

    :param loc: DipNet-style province notation
    :return: DAIDE-style loc
    """
    if "/" in loc:
        prov, coast = loc.split("/")
        if mto_prov_no_coast:
            return prov
        coast += "S"
        return " ".join(["(", prov, coast, ")"])
    else:
        if loc in DIPNET2DAIDE_LOC:
            return DIPNET2DAIDE_LOC[loc]

    return loc


def dipnet_unit(unit: List[str]):
    assert len(unit) == 5 or len(unit) == 8
    if len(unit) == 5:
        # non coasts
        unit = unit[2:4]
        unit_type = unit[0][0]
        loc = dipnet_location(unit[1])
        return unit_type + " " + loc
    else:
        # coasts
        unit = unit[2:7]
        unit_type = unit[0][0]
        loc = dipnet_location(" ".join(unit[2:4]))
        return unit_type + " " + loc


def daidefy_unit(unit: List[str], game: Game | None = None, power=None) -> str:
    """Converts DipNet-style unit to DAIDE-style unit

    E.g. (for initial game state)
    A BUD --> AUS AMY BUD
    F TRI --> AUS FLT TRI
    A PAR --> FRA AMY PAR
    A MAR --> FRA AMY MAR

    :param dipnet_unit: DipNet-style unit notation
    :param unit_game_mapping: Mapping from DipNet-style units to powers
    :return: DAIDE-style unit
    """

    assert len(unit) == 2
    unit_type = "FLT" if unit[0] == "F" else "AMY"
    loc = daidefy_location(unit[1])
    loc_for_unit_power = (
        loc.split(" ")[1] if " " in loc and len(loc.split(" ")) > 3 else loc
    )

    if power is None:
        assert game is not None, "daidefy_unit requires game when power is None"
        pow = get_unit_power(game, loc_for_unit_power)
    else:
        pow = power
    return " ".join(["(", pow, unit_type, loc, ")"])


def get_unit_power(game: Game, unit: str) -> str:
    """
    Determine the controller of a unit based on the location
    """
    loc = dipnet_location(unit)
    loc_dict = game.get_orderable_locations()
    for pp, locs in loc_dict.items():
        if loc in locs:
            return pp[:3]
    return ""


def dipnet_order(order: str) -> str:
    """
    DAIDE -> DipNet order converter.
    """
    splitted = order.split(" ")

    if len(splitted) == 2 and splitted[1] == "WVE":
        return "WAIVE"

    is_coastal = splitted[3] == "("

    if is_coastal:
        unit = splitted[0:8]
        rest = splitted[8:]
    else:
        unit = splitted[0:5]
        rest = splitted[5:]

    dipnet_u = dipnet_unit(unit)

    if len(rest) == 0:
        return dipnet_u

    elif len(rest) == 1:
        # HLD/BLD/DSB/REM
        if rest[0] == "REM":
            return dipnet_u + " D"
        else:
            return dipnet_u + " " + rest[0][0]
    elif len(rest) == 2:
        # MTO/RTO
        if rest[0] == "RTO":
            return dipnet_u + " R " + dipnet_location(rest[1])
        else:
            return dipnet_u + " - " + dipnet_location(rest[1])
    else:
        move_type = rest[0]
        if move_type == "CTO":
            return dipnet_u + " - " + dipnet_location(rest[1]) + " VIA"
        elif move_type == "CVY":
            cvy_unit = dipnet_unit(rest[1:6])
            cto_loc = dipnet_location(rest[7])
            return dipnet_u + " C " + cvy_unit + " - " + cto_loc
        elif move_type == "MTO" or move_type == "RTO":
            # MTO/RTO coastal
            secondary_loc = dipnet_location(" ".join(rest[1:]))
            if move_type == "MTO":
                return dipnet_u + " - " + secondary_loc
            else:
                return dipnet_u + " R " + secondary_loc
        else:
            sub_order = dipnet_order(" ".join(rest[1:]))
            return dipnet_u + " S " + sub_order


def daidefy_order(
    game: Game, power: str, order: str, via_locs: list = [], dsb: bool = False, mto_prov_no_coast: bool = False
) -> str:
    """
    DipNet -> DAIDE order converter.
    """
    if order == "WAIVE":
        return power + " WVE"

    splitted = order.split(" ")
    unit_type, loc, *rest = splitted

    if len(rest) == 0:
        return daidefy_unit([unit_type, loc], game=game, power=None)

    # loc = loc if '/' not in loc else loc.split('/')[0]
    daide_unit_type = "FLT" if unit_type == "F" else "AMY"
    daide_loc = daidefy_location(loc)
    if " " in daide_loc:
        primary_unit_power = get_unit_power(game, daide_loc.split(" ")[1])
    else:
        primary_unit_power = get_unit_power(game, daide_loc)
    assert (
        primary_unit_power == power
    ), f"Power mismatch: {power} != {primary_unit_power}"

    daide_primary_unit = " ".join(
        ["(", primary_unit_power, daide_unit_type, daide_loc, ")"]
    )

    if rest[0] == "-":
        # either MTO or CTO
        if "VIA" in rest:
            # CTO
            assert len(rest) == 3, f"CTO order has more than 3 elements: {order}"
            to_loc = rest[1]

            daide_to_loc = daidefy_location(to_loc)

            return (
                daide_primary_unit
                + " CTO "
                + daide_to_loc
                + " VIA "
                + "( "
                + " ".join(via_locs)
                + " )"
            )

        else:
            # MTO
            assert len(rest) == 2, f"MTO order has more than 2 elements: {order}"
            to_loc = rest[1]
            daide_to_loc = daidefy_location(to_loc, mto_prov_no_coast=mto_prov_no_coast)

            return daide_primary_unit + " MTO " + daide_to_loc
    else:
        if "R" in rest:
            # RTO
            assert len(rest) == 2, f"RTO order has more than 2 elements: {order}"
            to_loc = rest[1]
            daide_to_loc = daidefy_location(to_loc)

            return daide_primary_unit + " RTO " + daide_to_loc
        elif "B" in rest:
            # BLD
            assert len(rest) == 1, f"BLD order has more than 1 element: {order}"
            return daide_primary_unit + " BLD"
        elif "D" in rest:
            # DSB or REM
            assert len(rest) == 1, f"DSB/REM order has more than 1 element: {order}"
            if dsb:
                return daide_primary_unit + " DSB"
            else:
                return daide_primary_unit + " REM"
        elif "S" in rest or "C" in rest:
            # SUP/CVY
            assert len(rest) > 2, f"SUP/CVY order has less than 3 elements: {order}"
            secondary_loc = rest[2]

            if "/" in secondary_loc:
                secondary_power = get_unit_power(game, secondary_loc.split("/")[0])
            else:
                secondary_power = get_unit_power(game, secondary_loc)

            secondary_move = daidefy_order(game, secondary_power, " ".join(rest[1:]), mto_prov_no_coast=True)
            if "S" in rest:
                if "( " not in secondary_move:
                    secondary_move = "( " + secondary_move + " )"
                result = daide_primary_unit + " SUP " + secondary_move

                if "H" in rest:
                    return result.replace(" HLD", "")

                return result
            else:
                assert "C" in rest, f"CVY order has no 'C' element: {order}"

                result = daide_primary_unit + " CVY " + secondary_move
                return result.replace("MTO", "CTO")

        elif "H" in rest:
            # HLD
            assert len(rest) == 1, f"HLD order has more than 1 element: {order}"
            return daide_primary_unit + " HLD"

    raise ValueError(f"Unhandled order: {order}")


