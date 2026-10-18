"""Extract comparable facts from REA analyze_function dossiers.

calls      direct callee addresses (REA callees facet)
cmp_ints   immediates compared against (thresholds)
numbers    integer immediates (non-address, not memory displacements) and x87/SSE floating constants
           loaded from .rdata, resolved to their values from the PE bytes
strings    REA referenced_strings
blocks     REA basic_blocks count
Facts are restricted to the requested function's own recursive-descent body (fn_body.py), because a
Hopper procedure can span several original functions; body_coverage = share of the body the dossier lists.
Body instructions the REA dossier does not list (Hopper split the function) are read with capstone so the
facts cover the whole body; capstone_insns counts them.
usage: bin_facts.py AF_DIR BINARY KNOWN_ENTRIES_JSON OUT_JSON
"""
import glob, json, os, re, struct, sys, pefile
af_dir, exe, known_json, out = sys.argv[1:5]
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from fn_body import bodies
reqs = [os.path.basename(f)[:-5] for f in glob.glob(os.path.join(af_dir, "*.json"))]
BODY = bodies(exe, [int(a, 16) for a in reqs], [int(a, 16) for a in json.load(open(known_json))])
pe = pefile.PE(exe); base = pe.OPTIONAL_HEADER.ImageBase
def read(va, n):
    for s in pe.sections:
        lo = base + s.VirtualAddress
        if lo <= va < lo + s.SizeOfRawData: return s.get_data()[va - lo: va - lo + n]
    return None
IMG_LO, IMG_HI = 0x400000, 0xbd0000
MEMF = re.compile(r"\b(qword|dword|tword)\s*\[(?:0x)?([0-9a-f]{6,8})\]|\b(qword|dword)\s*\[(?:dbl|flt|qword|dword)_([0-9a-f]{6})\]")
IMM = re.compile(r"(?:,|\b(?:push|cmp|imul|mov|add|sub|and|or|xor|test))\s+(-?0x[0-9a-f]+|-?\d+)\s*$")
FPU = re.compile(r"\b(f\w+|movsd|movss|cvt\w+|mulsd|addsd|subsd|divsd|comisd|ucomisd)\b")
res = {}
for f in glob.glob(os.path.join(af_dir, "*.json")):
    d = json.load(open(f)); n = d["normalized_result"]; a = n["procedure"]["address"]
    nums, fl, cmps, calls = set(), set(), set(), set()
    req = os.path.basename(f)[:-5]; body = BODY[int(req, 16)]
    asm = [l for l in n.get("assembly") or [] if int(l.split(":")[0], 16) in body]
    import capstone as _cs
    if not hasattr(sys.modules[__name__], "_MD"):
        sys.modules[__name__]._MD = _cs.Cs(_cs.CS_ARCH_X86, _cs.CS_MODE_32)
        _t = [x for x in pe.sections if x.Name.startswith(b".text")][0]
        sys.modules[__name__]._TXT = (base + _t.VirtualAddress, _t.get_data())
    have = {int(l.split(":")[0], 16) for l in asm}; tlo, tcode = _TXT; extra = []
    for va in sorted(body - have):
        ins = next(_MD.disasm(tcode[va - tlo: va - tlo + 16], va), None)
        if ins is None: continue
        op = re.sub(r"\bptr \[(0x[0-9a-f]+)\]", r"[\1]", ins.op_str)
        op = re.sub(r"\bcall (0x[0-9a-f]+)", r"call \1", op)
        extra.append(f"{hex(va)}: {ins.mnemonic} {op}".rstrip())
    asm = asm + extra
    for line in asm:
        cm = re.match(r"call\s+(?:sub_|j_sub_)?(?:0x)?([0-9a-f]{6})\b", line.split(": ", 1)[-1])
        if cm: calls.add("0x" + cm.group(1))
        ins = line.split(": ", 1)[-1]
        for m in re.finditer(r"\b(qword|dword)_value_(-?\d+)\b(?!\+)", ins):  # Hopper names a literal by its bit pattern; "+8" = a neighbour, skip
            bits = int(m.group(2)); fmt = ("<Q", "<d") if m.group(1) == "qword" else ("<I", "<f")
            try: fl.add(round(struct.unpack(fmt[1], struct.pack(fmt[0], bits))[0], 9))
            except struct.error: pass
        if FPU.search(ins):
            for m in MEMF.finditer(ins):
                kind = m.group(1) or m.group(3); va = int(m.group(2) or m.group(4), 16)
                if 0x4ad000 <= va < 0x4c6000:  # .rdata only: constants, not mutable globals
                    b = read(va, 8 if kind == "qword" else 4)
                    if b: v = struct.unpack("<d" if kind == "qword" else "<f", b)[0]; fl.add(round(v, 9))
        if "[" in ins.split(",")[-1] and not ins.startswith("push"): continue
        m = IMM.search(ins)
        if m:
            v = int(m.group(1), 16) if "0x" in m.group(1) else int(m.group(1))
            if v >= 0x80000000: v -= 1 << 32
            if IMG_LO <= v < IMG_HI: continue  # an address, not a constant
            if ins.startswith(("sub esp", "add esp", "and esp")): continue
            nums.add(v)
            if ins.startswith("cmp"): cmps.add(v)
    res[req] = {"resolved": a, "name": n["procedure"]["name"], "calls": sorted(calls),
              "dossier_calls": sorted({c["address"] for c in n.get("callees") or []}),
              "body_insns": len(body), "body_coverage": round((len(asm) - len(extra)) / max(1, len(body)), 3), "capstone_insns": len(extra),
              "callers": sorted({c["address"] for c in n.get("callers") or []}),
              "ints": sorted(nums), "cmp_ints": sorted(cmps), "floats": sorted(fl),
              "strings": sorted({s.get("value", "") for s in n.get("referenced_strings") or []}),
              "blocks": sum(1 for b in n.get("basic_blocks") or [] if int(b["start"], 16) in body), "insns": len(n.get("assembly") or []),
              "evidence_id": d["evidence_id"]}
json.dump(res, open(out, "w"), indent=1); print(len(res), "functions")
