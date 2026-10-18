"""Dump PE metadata (sections, imports, exports, version info, string tables) to text."""
import sys, pefile, hashlib
path = sys.argv[1]
pe = pefile.PE(path)
data = open(path, 'rb').read()
out = [f"# {path.split('/')[-1]}", f"sha256 {hashlib.sha256(data).hexdigest()}", f"size {len(data)}",
       f"machine {hex(pe.FILE_HEADER.Machine)}  timestamp {pe.FILE_HEADER.TimeDateStamp} ({__import__('datetime').datetime.utcfromtimestamp(pe.FILE_HEADER.TimeDateStamp)} UTC)",
       f"image_base {hex(pe.OPTIONAL_HEADER.ImageBase)}  entry {hex(pe.OPTIONAL_HEADER.ImageBase + pe.OPTIONAL_HEADER.AddressOfEntryPoint)}",
       f"linker {pe.OPTIONAL_HEADER.MajorLinkerVersion}.{pe.OPTIONAL_HEADER.MinorLinkerVersion}  subsystem {pe.OPTIONAL_HEADER.Subsystem}", "", "## Sections"]
for s in pe.sections:
    out.append(f"{s.Name.rstrip(b'\0').decode():8} va {hex(pe.OPTIONAL_HEADER.ImageBase + s.VirtualAddress)} vsize {hex(s.Misc_VirtualSize)} raw {hex(s.SizeOfRawData)}")
if hasattr(pe, 'VS_FIXEDFILEINFO'):
    out += ["", "## Version info"]
    for fi in getattr(pe, 'FileInfo', []):
        for e in fi:
            for st in getattr(e, 'StringTable', []):
                for k, v in st.entries.items(): out.append(f"{k.decode()}: {v.decode(errors='replace')}")
out += ["", "## Imports"]
for d in getattr(pe, 'DIRECTORY_ENTRY_IMPORT', []):
    out.append(f"{d.dll.decode()}")
    for i in d.imports:
        out.append(f"  {hex(i.address)} {i.name.decode() if i.name else 'ord_%d' % i.ordinal}")
if hasattr(pe, 'DIRECTORY_ENTRY_EXPORT'):
    out += ["", "## Exports"]
    for e in pe.DIRECTORY_ENTRY_EXPORT.symbols:
        out.append(f"  {hex(pe.OPTIONAL_HEADER.ImageBase + e.address)} ord {e.ordinal} {e.name.decode() if e.name else ''}")
if hasattr(pe, 'DIRECTORY_ENTRY_RESOURCE'):
    out += ["", "## String table resources (RT_STRING)"]
    for t in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        if t.id != 6: continue
        for n in t.directory.entries:
            for l in n.directory.entries:
                raw = pe.get_data(l.data.struct.OffsetToData, l.data.struct.Size); p = 0
                for k in range(16):
                    ln = int.from_bytes(raw[p:p+2], 'little'); p += 2
                    if ln: out.append(f"  {(n.id - 1) * 16 + k}: {raw[p:p+2*ln].decode('utf-16le')!r}")
                    p += 2 * ln
print("\n".join(out))
