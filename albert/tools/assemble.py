"""Turn rea_driver batch_*.json Evidence into per-function pseudocode files plus an index.

usage: assemble.py BATCH_DIR ENTRIES_JSON NAME_MAP_JSON|- OUT_DIR [EVIDENCE_DIR]
Failed functions get REA procedure_assembly from EVIDENCE_DIR/asm_<hex>.json when present.
"""
import json, sys, os, glob, csv, re
bdir, entries_json, name_map, out = sys.argv[1:5]
evdir = sys.argv[5] if len(sys.argv) > 5 else None
names = json.load(open(name_map))["names"] if name_map != "-" else {}
meta = {e["address"]: e for e in json.load(open(entries_json))}
items, evid = {}, {}
for fn in sorted(glob.glob(os.path.join(bdir, "*batch_*.json"))):
    d = json.load(open(fn))
    for it in d["normalized_result"]["items"]:
        items[it["address"]] = it; evid[it["address"]] = d["evidence_id"]
subject = d["subject"]
aliases = {}  # container -> [(entry address, pybert name)] for entries Hopper merged into a preceding procedure
apath = os.path.join(out, "aliases.csv")
if os.path.exists(apath):
    for r in csv.DictReader(open(apath)):
        if r["hopper_container"]: aliases.setdefault(r["hopper_container"], []).append((r["address"], r["pybert_name"]))
fdir = os.path.join(out, "functions"); os.makedirs(fdir, exist_ok=True)
safe = lambda s: re.sub(r"[^A-Za-z0-9_]", "_", s)
rows = []
for a in sorted(items, key=lambda x: int(x, 16)):
    it = items[a]; m = meta.get(a, {})
    hop = (it.get("procedure") or {}).get("name") or ""
    known = names.get(a, "")
    label = known or hop or "sub_" + a[2:]
    ok = it["status"] == "ok" and it.get("pseudocode") is not None
    refs = ",".join(k for k in ("called", "pointer", "immediate") if m.get(k))
    hdr = (f"// {label} @ {a}\n// hopper name: {hop}\n" + (f"// pybert name: {known}\n" if known else "") +
           "".join(f"// contains unmarked entry {x}{' (' + nm + ')' if nm else ''}\n" for x, nm in aliases.get(a, [])) +
           f"// referenced by: {refs}\n// source: REA batch_decompile (Hopper) evidence {evid[a]}\n"
           f"// binary: {subject['name']} sha256 {subject['digest']['sha256']}\n")
    body = (f"{label}() {{\n{it['pseudocode']}}}\n" if ok else
            "// DECOMPILE FAILED: " + json.dumps(it.get("error") or it.get("procedure", {}).get("error"))[:600] + "\n")
    asm = os.path.join(evdir, f"asm_{a[2:]}.json") if evdir else ""
    if not ok and os.path.exists(asm):
        body += "\n// Fallback: REA procedure_assembly (Hopper)\n/*\n" + json.load(open(asm))["normalized_result"] + "\n*/\n"
    fname = f"{a[2:]}_{safe(label)}.c"
    open(os.path.join(fdir, fname), "w").write(hdr + "\n" + body)

    rows.append([a, hop, known, refs, "ok" if ok else "failed", (it.get("pseudocode") or "").count("\n"), "functions/" + fname])
with open(os.path.join(out, "index.csv"), "w", newline="") as f:
    w = csv.writer(f); w.writerow(["address", "hopper_name", "pybert_name", "referenced_by", "status", "lines", "file"]); w.writerows(rows)
print(len(rows), "functions;", sum(r[4] == "ok" for r in rows), "ok;", sum(bool(r[2]) for r in rows), "named")
