"""Show REA assembly around each use of a floating constant in a dossier (Hopper names literals qword_value_<bits>).

usage: float_context.py AF_DIR ADDR VALUE [ADDR VALUE ...]
"""
import json, os, re, struct, sys
d = sys.argv[1]; args = sys.argv[2:]
for a, val in zip(args[::2], args[1::2]):
    asm = json.load(open(os.path.join(d, a + ".json")))["normalized_result"]["assembly"]
    want = float(val)
    for i, l in enumerate(asm):
        for m in re.finditer(r"\b(qword|dword)_value_(-?\d+)\b", l):
            fmt = ("<Q", "<d") if m.group(1) == "qword" else ("<I", "<f")
            v = struct.unpack(fmt[1], struct.pack(fmt[0], int(m.group(2))))[0]
            if abs(v - want) < 1e-6 * max(1, abs(want)):
                print(f"== {a} {val} @ {l.split(':')[0]}")
                for x in asm[max(0, i - 5): i + 4]: print("   ", re.sub(r"(qword|dword)_value_-?\d+", f"<{v:g}>", x) if x == l else x)
