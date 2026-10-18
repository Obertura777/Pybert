"""Harvest `Name (FUN_00xxxxxx)` style annotations from the Pybert port into an address->name map."""
import re, sys, os, json, collections
root, out = sys.argv[1], sys.argv[2]
pat = re.compile(r"\b([A-Z][A-Za-z0-9_]{3,})\s*(?:\(|=|/|@|\s)\s*`{0,2}(?:FUN_|0x)00?(4[0-9a-fA-F]{5})\b")
stop = {"Callee", "Callees", "Calls", "Call", "Else", "Then", "See", "Note", "From", "Port", "Ported", "Called", "Caller", "Callers", "Also", "Same", "Mirrors", "Matches", "Like", "Inside", "Uses"}
hits = collections.defaultdict(collections.Counter)
for dp, dn, fn in os.walk(root):
    dn[:] = [d for d in dn if d not in {".git", ".venv", "albert", "__pycache__", "games"}]
    for f in fn:
        if not f.endswith((".py", ".md", ".c", ".C")): continue
        for m in pat.finditer(open(os.path.join(dp, f), errors="replace").read()):
            name, addr = m.group(1), "0x" + m.group(2).lower()
            if name in stop or name.startswith(("DAT_", "FUN_", "LAB_", "PTR_", "DOUBLE_")): continue
            hits[addr][name] += 1
amap, conflicts = {}, {}
for a, c in sorted(hits.items()):
    (n, k), *rest = c.most_common()
    amap[a] = n
    if rest: conflicts[a] = dict(c)
json.dump({"names": amap, "conflicts": conflicts}, open(out, "w"), indent=1)
print(len(amap), "names,", len(conflicts), "conflicts")
