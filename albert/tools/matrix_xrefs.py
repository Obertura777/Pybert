"""Every code reference into the five contiguous 21x21 double influence matrices (0xb81228-0xb85710).

Raw 4-byte scan of .text, attributed to the containing instruction via fn_body. Lines whose operand is
[esp + 0xb8] or an immediate that merely happens to match are false positives; filter them when reading.
usage: matrix_xrefs.py   (run with: uv run --with pefile --with capstone python -I)
"""
import sys, json, bisect, struct, csv
sys.path.insert(0, __import__("os").path.dirname(__file__))
import capstone, pefile
from fn_body import bodies
ROOT = __import__("os").path.dirname(__import__("os").path.dirname(__import__("os").path.abspath(__file__))) + "/"
exe = ROOT + "payload/Albert.exe"
known = json.load(open(ROOT + "compare/known_entries.json"))
known = known if isinstance(known, list) else known.get("entries", list(known))
known = sorted(int(k, 16) if isinstance(k, str) else k for k in known)
names = {int(r["address"], 16): (r["hopper_name"], r["pybert_name"]) for r in csv.DictReader(open(ROOT + "decompiled/Albert.exe/index.csv"))}
M = {0xb81228: "R_b81228", 0xb81ff0: "M0_b81ff0", 0xb82db8: "M1_b82db8", 0xb83b80: "M2_b83b80", 0xb84948: "M3_b84948"}
LO, HI = 0xb81228, 0xb84948 + 0xdc8
pe = pefile.PE(exe); base = pe.OPTIONAL_HEADER.ImageBase
t = [s for s in pe.sections if s.Name.startswith(b".text")][0]
tlo = base + t.VirtualAddress; code = t.get_data()
# raw byte scan for candidate displacements
hits = []
for off in range(len(code) - 3):
    v = struct.unpack_from("<I", code, off)[0]
    if LO - 0x40 <= v < HI + 0x40: hits.append(tlo + off)
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
def owner(va):
    i = bisect.bisect_right(known, va) - 1
    return known[i] if i >= 0 else None
# get instruction containing each hit by disassembling the owner's body
owners = sorted({owner(h) for h in hits})
B = bodies(exe, owners, known)
ins_at = {}
for e, addrs in B.items():
    for a in addrs: ins_at[a] = e
out = []
for h in hits:
    # find instruction start that covers h
    for back in range(1, 12):
        a = h - back
        if a in ins_at:
            ins = next(md.disasm(code[a - tlo:a - tlo + 16], a))
            if a + ins.size > h:
                e = ins_at[a]
                tgt = struct.unpack_from("<I", code, h - tlo)[0]
                mk = max(k for k in M if k <= tgt) if tgt >= LO else LO
                out.append((e, a, f"{ins.mnemonic} {ins.op_str}", M.get(mk, "?") if LO <= tgt < HI else "near", tgt - mk))
            break
    else:
        out.append((owner(h), h, "??", "", 0))
for e, a, txt, m, d in sorted(set(out)):
    n = names.get(e, ("?", ""))
    print(f"{e:#x} {n[0]:28s} {n[1]:32s} {a:#x}  {m:10s} +{d:#x}  {txt}")
