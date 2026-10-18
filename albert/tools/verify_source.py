"""Verify where each ../Source Ghidra function lives, using exact callee sets from REA dossiers.

For each Source function, candidates are its fingerprint top-3 (locate_source.py) plus the address the
port cites for that name. Score = share of Ghidra FUN_ callees present in REA's callee list; ties go to
the cited address, then to fewer extra callees. Only DISTINCTIVE callees count: ones called by fewer than
COMMON functions across the whole Hopper decompile (STL/CRT helpers such as 0x40f400 or 0x47a948 prove
nothing). verified = >= 2 distinctive Ghidra callees and >= 80% of them present.
usage: verify_source.py SOURCE_LOCATIONS_JSON BIN_FACTS_JSON NAME_MAP_JSON DECOMP_FUNCTIONS_DIR OUT_JSON
"""
import json, re, sys
locs, facts, nmap, ddir, out = sys.argv[1:6]
import glob, collections
COMMON = 40
freq = collections.Counter()
for f in glob.glob(ddir + "/*.c"):
    freq.update({"0x" + m for m in set(re.findall(r"\bsub_([0-9a-f]{6})\(", open(f).read()))})
bf = json.load(open(facts)); src = json.load(open(locs))
cited = {v: k for k, v in json.load(open(nmap))["names"].items()}
G = re.compile(r"\bFUN_00([4-9ab][0-9a-f]{5})\b", re.I)
res = {}
for name, v in src.items():
    g = {"0x" + m.lower() for m in G.findall(open(v["file"], errors="replace").read())}
    g = {c for c in g if freq[c] < COMMON}
    cands = list(dict.fromkeys(([cited[name]] if name in cited else []) + [a for a, _ in v.get("top", [])]))
    best = None
    for a in cands:
        if a not in bf or not g: continue
        rc = set(bf[a]["calls"]); cov = len(g & rc) / len(g)
        key = (round(cov, 6), a == cited.get(name), -len(rc - g))
        if best is None or key > best[0]: best = (key, a, cov, len(rc))
    res[name] = {"file": v["file"], "ghidra_callees": len(g), "address": best[1] if best else cited.get(name),
                 "callee_coverage": round(best[2], 3) if best else None, "rea_callees": best[3] if best else None,
                 "known_address": cited.get(name), "fingerprint_status": v["status"],
                 "verified": bool(best and best[2] >= 0.8 and len(g) >= 2)}
json.dump(res, open(out, "w"), indent=1)
ok = [k for k, v in res.items() if v["verified"]]
dis = [(k, v["known_address"], v["address"]) for k, v in res.items() if v["verified"] and v["known_address"] and v["known_address"] != v["address"]]
print("verified", len(ok), "of", len(res), "| cited-address disagreements:", dis)
