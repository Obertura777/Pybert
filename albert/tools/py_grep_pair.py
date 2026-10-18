"""Grep the Python side of one comparison pair (ports + slices + folded helpers) for a regex.

usage: py_grep_pair.py COMPARISON_JSON PY_FUNCTIONS_JSON ADDR REGEX
"""
import json, re, sys
cmp, pyf, addr, rx = sys.argv[1:5]
pair = next(p for p in json.load(open(cmp))["pairs"] if p["address"] == addr)
py = json.load(open(pyf)); by = {f["name"]: f for f in py}
todo = [x.split(":")[-1] for x in pair.get("python_ports", []) + pair.get("python_slices", [])]
seen = set()
while todo:  # same helper folding as compare.py: unpaired, uniquely named callees
    n = todo.pop()
    if n in seen or n not in by: continue
    seen.add(n); f = by[n]
    for i, l in enumerate(open(f["file"]).read().splitlines()[f["line"] - 1:f["end"]]):
        if re.search(rx, l): print(f'{f["file"]}:{f["line"] + i}: {l.strip()[:150]}')
    todo += [c for c in f["calls"] if c in by and not by[c].get("claimed") and sum(1 for g in py if g["name"] == c) == 1]
print("searched:", sorted(seen))
