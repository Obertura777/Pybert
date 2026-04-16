"""DAIDE byte-level helpers.

Split from utils.py during the 2026-04 refactor.

Low-level helpers for DAIDE protocol (hex payload <-> token list, hex
codec, and text sanitization). These are the leaf helpers the
translation layer (``.translate``) and the message processors
(``.messages``) compose on top of.

Module-level deps: ``.tokens`` for HEX2DAIDE / DAIDE2HEX lookups.
"""

from typing import List

from .tokens import HEX2DAIDE, DAIDE2HEX

def sanitize_daide(daide: str, result:List[str]) -> List[str]:
    """
        Function to sanitize messy daide format e.g., no spaces between items
        Assumes string only contains 3-letter daide tokens, spaces, and parens
    """
    if len(daide) > 0:
        first = daide[0]
        item, rest = None, None
        
        if first.isspace():
            return sanitize_daide(daide[1:], result)
        elif first.isalpha() and first.isupper():
            item, rest = daide[:3], daide[3:]
        else:
            # assume is braces
            item, rest = daide[:1], daide[1:]
        appended = result.copy()
        appended.append(item)
        return sanitize_daide(rest, appended)
    else:
        return result


def split_by_two_characters(s):
    return [s[i : i + 2] for i in range(0, len(s), 2)]


def convert(payload):
    octets = split_by_two_characters(payload)

    new_octets = []

    # fix the octets
    for oo in octets:
        if len(oo) == 6:
            new_octets.append(oo[:2])
            new_octets.append(oo[2:4])
            new_octets.append(oo[4:])
        else:
            new_octets.append(oo)

    out = []
    curr = []

    while len(new_octets) > 0:
        item = new_octets.pop(0)
        curr.append(item)

        if len(curr) == 2:
            out.append("".join(curr))
            curr = []

    result = []

    for x in out:
        if x[:2].upper() == "4B":
            decimal = int(x[2:], 16)
            result.append(chr(decimal))

        else:
            if x.upper() in HEX2DAIDE:
                result.append(HEX2DAIDE[x.upper()])
            else:
                result.append(x)

    return result


def convert_to_hex(message):
    return "".join([DAIDE2HEX.get(c, c) for c in message]).lower()


def decimal_to_hex(decimal):
    return hex(decimal)[2:].zfill(4)


def hex_to_decimal(hex):
    return int(hex, 16)


def cal_remaining_len(data):
    return len(data) // 2


