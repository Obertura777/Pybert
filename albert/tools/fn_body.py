"""Recursive-descent function bodies (capstone), to trim REA/Hopper dossiers to one original function.

Hopper sometimes merges neighbouring MSVC functions into one procedure, so a dossier can carry another
function's constants. From an entry we follow fallthrough, conditional and unconditional jumps and
`jmp [reg*4+table]` switch tables; we stop at ret, and treat a jump to another known entry as a tail call.
usage (library): bodies(binary, entries, known_entries) -> {entry: set(instruction addresses)}
usage (cli):     fn_body.py BINARY ENTRIES_JSON KNOWN_ENTRIES_JSON OUT_JSON
"""
import json, struct, sys
import capstone, pefile


def bodies(exe, entries, known):
    pe = pefile.PE(exe); base = pe.OPTIONAL_HEADER.ImageBase
    t = [s for s in pe.sections if s.Name.startswith(b".text")][0]
    lo = base + t.VirtualAddress; code = t.get_data(); hi = lo + len(code)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
    known = set(known)

    def rd32(va):
        for s in pe.sections:
            sl = base + s.VirtualAddress
            if sl <= va < sl + s.SizeOfRawData - 3: return struct.unpack_from("<I", s.get_data(), va - sl)[0]
        return None

    out = {}
    for e in entries:
        seen, work = set(), [e]
        while work and len(seen) < 60000:
            pc = work.pop()
            while lo <= pc < hi and pc not in seen:
                ins = next(md.disasm(code[pc - lo: pc - lo + 16], pc), None)
                if ins is None: break
                seen.add(pc)
                m = ins.mnemonic
                if m in ("ret", "retn", "retf", "int3", "hlt"): break
                if m == "jmp" or (m.startswith("j") and m != "jmp"):
                    op = ins.operands[0]
                    if op.type == capstone.x86.X86_OP_IMM:
                        tgt = op.imm
                        if tgt in known and tgt != e: pass  # tail call into another function
                        else: work.append(tgt)
                    elif op.type == capstone.x86.X86_OP_MEM and op.mem.scale == 4 and op.mem.disp:
                        tbl = op.mem.disp & 0xffffffff
                        for k in range(512):  # switch table: consecutive code pointers
                            v = rd32(tbl + 4 * k)
                            if v is None or not (lo <= v < hi): break  # case labels are always internal
                            work.append(v)
                    if m == "jmp": break
                pc += ins.size
        out[e] = seen
    return out


if __name__ == "__main__":
    exe, ent, kn, out = sys.argv[1:5]
    b = bodies(exe, [int(a, 16) for a in json.load(open(ent))], [int(a, 16) for a in json.load(open(kn))])
    json.dump({hex(k): len(v) for k, v in b.items()}, open(out, "w"), indent=0)
