"""Classify binary functions that touch game globals but have no paired Python port.

For each: its known name (port citations or callee-verified ../Source location), and every Python file
in the repo that mentions its address or name. Classes:
  press-module   only cited from communications/ (press/negotiation; outside the game-logic scope)
  cited-unpaired cited inside the game-logic scope but no function's first docstring sentence claims it
  unreferenced   nothing in the repo mentions it
usage: classify_unported.py UNPORTED_JSON NAME_MAP_JSON SOURCE_VERIFIED_JSON OUT_JSON
"""
import json, os, re, sys
unp, nmap, sver, out = sys.argv[1:5]
names = json.load(open(nmap))["names"]
for k, v in json.load(open(sver)).items():
    if v["verified"]: names.setdefault(v["address"], k)
py = {}
for d, dn, fs in os.walk("."):
    dn[:] = [x for x in dn if x not in {".git", ".venv", "albert", "__pycache__", "games", "tests"}]
    for f in fs:
        if f.endswith(".py"): py[os.path.relpath(os.path.join(d, f))] = open(os.path.join(d, f)).read()
res = []
for u in json.load(open(unp)):
    a = u["address"]; h = a[2:]; nm = names.get(a)
    pat = re.compile(r"(?:FUN_00|0x00)%s\b" % h + (r"|\b%s\b" % re.escape(nm) if nm else ""), re.I)
    hits = sorted(f for f, t in py.items() if pat.search(t))
    cls = "unreferenced" if not hits else ("press-module" if all(f.startswith("communications") for f in hits) else "cited-unpaired")
    res.append(dict(u, name=nm, cited_in=hits, cls=cls))
json.dump(res, open(out, "w"), indent=1)
import collections; print(collections.Counter(r["cls"] for r in res))
for r in sorted(res, key=lambda r: -r["hopper_lines"]):
    print(r["address"], r["hopper_lines"], r["name"], r["cls"], r["cited_in"][:3])
