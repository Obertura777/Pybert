"""DAIDE incoming-message processors.

Split from utils.py during the 2026-04 refactor.

Each ``process_<TAG>`` function takes the tokenized payload of an
incoming DAIDE message of that type and returns/updates the DipNet
representation the bot consumes. Ordered loosely by arrival frequency:

  * ``process_now`` — NOW (current-positions broadcast).
  * ``process_ord`` — ORD (order adjudication results).
  * ``process_sco`` — SCO (supply-center ownership update).
  * ``process_mrt`` — MRT (retreat orders requested).
  * ``process_frm`` — FRM (inter-power press message).

Module-level deps: ``.tokens.POWER_NAMES``, ``.translate`` for
``dipnet_location`` / ``dipnet_unit``.
"""

from typing import List

from .tokens import POWER_NAMES
from .translate import dipnet_location, dipnet_unit

def process_now(info: str) -> List[str]:
    assert "NOW" in info, f"Invalid NOW message: {info}"
    splitted = info.strip().split(" ")[1:]

    result = []
    curr = []
    stack = []

    while len(splitted) > 0:
        # get the first item in list
        item = splitted.pop(0)

        if item == ")":
            # closing bracket
            if len(stack) == 1 and stack[0] == "(":
                # add to result
                result.append(" ".join(curr))
                # reset
                curr = []
                stack = []
            elif stack[-1] == "(":
                # inner closing brackets -- costal case
                stack.pop()
                curr.append(item)
            else:
                stack.append(item)
        elif item == "(":
            # inner starting bracket -- costal case
            if len(stack) > 0:
                curr.append(item)
            stack.append(item)
        else:
            curr.append(item)

    assert len(stack) == 0, f"Invalid NOW message: {info}"
    assert len(curr) == 0, f"Invalid NOW message: {info}"

    return result


def process_ord(message: str) -> List[str]:
    assert "ORD" in message, f"Invalid ORD message: {message}"
    splitted = message.strip().split(" ")[1:]

    result = []
    curr = []
    stack = []

    while len(splitted) > 0:
        # get the first item in list
        item = splitted.pop(0)

        if item == ")":
            # closing bracket
            if len(stack) == 1 and stack[0] == "(":
                # add to result
                result.append(" ".join(curr))
                # reset
                curr = []
                stack = []
            elif stack[-1] == "(":
                # inner closing brackets -- costal case
                stack.pop()
                curr.append(item)
            else:
                stack.append(item)
        elif item == "(":
            # inner starting bracket -- costal case
            if len(stack) > 0:
                curr.append(item)
            stack.append(item)
        else:
            curr.append(item)

    assert len(stack) == 0, f"Invalid NOW message: {message}"
    assert len(curr) == 0, f"Invalid NOW message: {message}"

    return result


def process_sco(dist):
    assert "SCO" in dist, f"Invalid SCO message: {dist}"
    splitted = dist.strip().split(" ")[1:]
    result = {}
    curr_p = None

    for item in splitted:
        if item == ")":
            continue
        elif item == "(":
            continue
        elif item == "UNO":
            return result
        else:
            if item in POWER_NAMES.keys():
                if POWER_NAMES[item] not in result:
                    result[POWER_NAMES[item]] = []
                curr_p = POWER_NAMES[item]
            else:
                result[curr_p].append(dipnet_location(item))

    return result


def process_mrt(message: str):
    assert "MRT" in message, f"Invalid MRT message: {message}"
    splitted = message.strip().split(" ")[2:-1]
        
    is_coast = splitted[2] == '('
    
    if is_coast:
        unit = splitted[0:6]
        rest = splitted[6:]
    else:
        unit = splitted[0:3]
        rest = splitted[3:]
        
    retreat_power = unit[0]
    
    unit = ["("] + unit + [")"]
        
    dipnet_u = dipnet_unit(unit)
    
    assert rest[0] == 'MRT', f"message {message} does not have MRT"
    
    start = rest.index('(') + 1
    end = rest.index(')')
    
    retreat_locs = rest[start:end]
    dipnet_retreat_locs = [dipnet_location(loc) for loc in retreat_locs]

    return retreat_power, dipnet_u, dipnet_retreat_locs


def process_frm(msg):
    assert "FRM" in msg, f"Invalid FRM message: {msg}"
    splitted = msg.strip().split(" ")[1:]

    result = []
    curr = []
    stack = []

    while len(splitted) > 0:
        # get the first item in list
        item = splitted.pop(0)

        if item == ")":
            # closing bracket
            if len(stack) == 1 and stack[0] == "(":
                # add to result
                result.append(" ".join(curr))
                # reset
                curr = []
                stack = []
            elif stack[-1] == "(":
                # inner closing brackets -- costal case
                stack.pop()
                curr.append(item)
            else:
                stack.append(item)
        elif item == "(":
            # inner starting bracket -- costal case
            if len(stack) > 0:
                curr.append(item)
            stack.append(item)
        else:
            curr.append(item)

    assert len(stack) == 0, f"Invalid NOW message: {msg}"
    assert len(curr) == 0, f"Invalid NOW message: {msg}"
    assert len(result) == 3, f"Invalid FRM message: {msg}"
    splitted = result[1].split(" ")

    return result[0], splitted, result[2]


