"""Write REA/Hopper typed strings plus a raw ASCII/UTF-16LE scan of every PE section (VA-addressed)."""
import sys, json, re, pefile
exe, rea_json, out = sys.argv[1:4]
pe = pefile.PE(exe); base = pe.OPTIONAL_HEADER.ImageBase
lines = ["# REA list_strings (Hopper typed string objects)"]
for s in json.load(open(rea_json))["normalized_result"]:
    lines.append(f"{s['address']}\t{s['value']!r}")
lines.append("\n# Raw scan: ASCII (>=4) and UTF-16LE (>=4) runs per section")
for sec in pe.sections:
    name = sec.Name.rstrip(b"\0").decode(); va = base + sec.VirtualAddress; b = sec.get_data()
    for m in re.finditer(rb"[\x20-\x7e\t\r\n]{4,}", b):
        lines.append(f"{hex(va + m.start())}\t{name}\tascii\t{m.group().decode()!r}")
    for m in re.finditer(rb"(?:[\x20-\x7e]\x00){4,}", b):
        lines.append(f"{hex(va + m.start())}\t{name}\tutf16\t{m.group().decode('utf-16le')!r}")
open(out, "w").write("\n".join(lines) + "\n"); print(len(lines), "lines")
