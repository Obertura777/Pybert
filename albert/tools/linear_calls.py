"""Independent check: linearly disassemble from an address (capstone) until the first ret/int3 run, list call targets.

usage: linear_calls.py BINARY ADDR [ADDR...]
"""
import sys, pefile, capstone
pe = pefile.PE(sys.argv[1]); base = pe.OPTIONAL_HEADER.ImageBase
t = [s for s in pe.sections if s.Name.startswith(b".text")][0]; tva = base + t.VirtualAddress; code = t.get_data()
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
for a in sys.argv[2:]:
    va = int(a, 16); calls, n, end = [], 0, None
    # follow fallthrough; stop at ret followed by padding or the next function prologue
    for ins in md.disasm(code[va - tva: va - tva + 0x4000], va):
        n += 1
        if ins.mnemonic == "call" and ins.op_str.startswith("0x"): calls.append(ins.op_str)
        if ins.mnemonic in ("ret", "retn"):
            nxt = code[ins.address + ins.size - tva: ins.address + ins.size - tva + 3]
            if nxt[:1] in (b"\xcc", b"\x90") or nxt[:3] == b"\x55\x8b\xec" or nxt[:1] == b"\x6a" and False: end = hex(ins.address); break
    print(a, "insns", n, "end", end, "calls", sorted(set(calls)))
