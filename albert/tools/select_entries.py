"""Reduce Hopper's over-split procedure list to real entries: call/jmp targets, data pointers, immediates.

usage: select_entries.py LIST_PROCEDURES_JSON BINARY OUT_JSON
"""
import json, sys, struct, pefile
procs_file, exe, out = sys.argv[1:4]
procs = json.load(open(procs_file))['normalized_result']
starts = {int(p['address'],16): p['value'] for p in procs}
pe = pefile.PE(exe); base = pe.OPTIONAL_HEADER.ImageBase
called, ptr, imm = set(), set(), set()
for s in pe.sections:
    va = base + s.VirtualAddress; b = s.get_data()
    name = s.Name.rstrip(b'\0').decode()
    if name == '.text':
        for i in range(len(b)-5):
            if b[i] == 0xE8:
                t = va+i+5+struct.unpack_from('<i', b, i+1)[0]
                if t in starts: called.add(t)
            if b[i] == 0x68 or 0xB8 <= b[i] <= 0xBF or (i >= 2 and b[i-1] == 0xC7) or (i >= 2 and b[i-2] == 0xC7) or (i >= 3 and b[i-3] == 0xC7):
                v = struct.unpack_from('<I', b, i+1)[0]
                if v in starts: imm.add(v)
            if b[i] == 0xE9:
                t = va+i+5+struct.unpack_from('<i', b, i+1)[0]
                if t in starts: called.add(t)
    if name == ".text": continue
    for i in range(0, len(b)-3, 4):
        v = struct.unpack_from('<I', b, i)[0]
        if v in starts: ptr.add(v)
entry = base + pe.OPTIONAL_HEADER.AddressOfEntryPoint
exports = {base + e.address for e in getattr(getattr(pe, "DIRECTORY_ENTRY_EXPORT", None), "symbols", []) if base + e.address in starts}
keep = sorted(called | ptr | imm | exports | {entry})
print('procs', len(starts), 'called', len(called), 'ptr', len(ptr), 'imm', len(imm), 'keep', len(keep), 'entry', hex(entry))
json.dump([{'address': hex(a), 'name': starts.get(a, ''), 'called': a in called, 'pointer': a in ptr, 'immediate': a in imm} for a in keep], open(out, 'w'))
