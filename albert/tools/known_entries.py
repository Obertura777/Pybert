"""Known function entries for fn_body.py: E8 call targets, data pointers, immediates, exports, entry point.

Plain JMP targets are excluded on purpose: Hopper's split points inside one function are often only
jumped to, and treating them as entries would cut bodies short (e.g. ComputeWinterBuilds 0x445be0).
usage: known_entries.py BINARY OUT_JSON
"""
import json, struct, sys, pefile
exe, out = sys.argv[1:3]
pe = pefile.PE(exe); base = pe.OPTIONAL_HEADER.ImageBase
t = [s for s in pe.sections if s.Name.startswith(b".text")][0]; tva = base + t.VirtualAddress; code = t.get_data()
lo, hi = tva, tva + len(code); ent = {base + pe.OPTIONAL_HEADER.AddressOfEntryPoint}
for i in range(len(code) - 5):
    if code[i] == 0xE8:
        x = tva + i + 5 + struct.unpack_from("<i", code, i + 1)[0]
        if lo <= x < hi: ent.add(x)
    if code[i] == 0x68 or 0xB8 <= code[i] <= 0xBF:  # push imm32 / mov r32, imm32 of a code address
        v = struct.unpack_from("<I", code, i + 1)[0]
        if lo <= v < hi and code[v - lo - 1] in (0xCC, 0x90, 0xC3, 0xC2): ent.add(v)
for s in pe.sections:
    if s.Name.startswith(b".text"): continue
    b = s.get_data()
    for i in range(0, len(b) - 3, 4):
        v = struct.unpack_from("<I", b, i)[0]
        if lo <= v < hi: ent.add(v)
json.dump(sorted(hex(x) for x in ent), open(out, "w")); print(len(ent), "entries")
