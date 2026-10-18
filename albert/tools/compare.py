"""Compare REA facts for Albert.exe game-logic functions against their Python ports.

Inputs (all produced by the other tools in this folder):
  py_functions.json               Python inventory + per-function facts (py_inventory.py)
  bin_facts.json                  REA analyze_function facts per address (bin_facts.py)
  source_locations_verified.json  ../Source Ghidra names located in the binary by exact callee sets
  name_map.json                   names/addresses cited by the port
usage: compare.py COMPARE_DIR NAME_MAP_JSON DECOMP_INDEX_CSV OUT_JSON

Pairing (binary address <- Python function):
  1. the Python function cites a ../Source name (docstring) whose location is callee-verified -> that address
  2. otherwise the address the docstring claims
Each pairing records whether the docstring's own address agrees with the verified one.

Per pair, the Python side is the function plus the unpaired helpers it calls (transitively, same scope),
because the port routinely splits one C function into private helpers.
"""
import csv, json, os, re, sys

cdir, name_map_path, index_csv, out = sys.argv[1:5]
py = json.load(open(os.path.join(cdir, "py_functions.json")))
bf = json.load(open(os.path.join(cdir, "bin_facts.json")))
src = json.load(open(os.path.join(cdir, "source_locations_verified.json")))
names = json.load(open(name_map_path))["names"]
hop_lines = {r["address"]: int(r["lines"]) for r in csv.DictReader(open(index_csv))}

# Cited addresses that are labels inside a larger function: no call, jump or pointer reaches them and
# they are not preceded by inter-function padding (checked with pefile/capstone; see README).
NOT_ENTRIES = {"0x427960": "0x427620", "0x42c730": "0x42c040", "0x42dc40": "0x42db50", "0x43a000": "0x439ed0",
               "0x4498d0": "0x447460", "0x455fd0": "0x4559c0", "0x459548": "0x4592a0"}
# Pairings established from REA evidence where the docstring's first sentence cites a callee instead:
#   apply_influence_scores says "sole caller of AppendOrder / FUN_00419d80"; REA's only caller of 0x419d80
#   is 0x436470, whose pow exponents (8, 9, 4) and /100 denominators match the Python.
MANUAL_PAIRS = {"apply_influence_scores": "0x436470"}
SMALL_INT = 8          # |n| <= 8 is loop/flag/index noise on both sides
FLOAT_TOL = 1e-6

def doc_of(f):
    lines = open(f["file"]).read().splitlines()[f["line"] - 1:f["end"]]
    m = re.search(r'("""|\'\'\')(.*?)\1', "\n".join(lines), re.S)
    return m.group(2) if m else ""

# --- pair Python functions with binary addresses -------------------------------------------------
# Only the docstring's first sentence names the subject; later sentences cite callers/callees.
#   "Port of NAME (FUN_x)", "NAME (FUN_x).", "FUN_x — ...", "Port of FUN_x = NAME"   -> role "port"
#   "Port NAME.c:12-40's ...", "Apply the X arm of NAME", "Normalize NAME' ..."       -> role "slice" (part of NAME)
verified = {k: v["address"] for k, v in src.items() if v["verified"]}
known = dict({n: a for a, n in names.items()}, **verified)   # verified Ghidra locations win over cited ones
ADDR_RE = re.compile(r"\bFUN_00([4][0-9a-f]{5})\b|\b0x00([4][0-9a-f]{5})\b", re.I)
def first_sentence(doc):
    d = doc.strip().split("\n\n")[0].replace("\n", " ")
    m = re.match(r"(.+?\.)(\s|$)", d)
    return m.group(1) if m else d
for f in py:
    fs = first_sentence(doc_of(f))
    nm = next((n for n in sorted(known, key=len, reverse=True) if re.search(r"\b%s\b" % re.escape(n), fs)), None)
    am = ADDR_RE.search(fs); cited = ("0x" + (am.group(1) or am.group(2)).lower()) if am else None
    head = re.match(r"^\s*(?:(?:full\s+)?port(?:ed)?(?:\s+of)?\s+)?(?:FUN_00[0-9a-f]{6}\s*(?:=|—|-)\s*)?([A-Za-z_][A-Za-z0-9_]*)\b", fs, re.I)
    is_port = bool(re.match(r"^\s*(?:full\s+)?port(?:ed)?\s+of\b|^\s*FUN_00", fs, re.I) or (nm and head and head.group(1) == nm and ".c:" not in fs))
    f["first_sentence"] = fs[:200]
    f["source_name"] = nm
    if nm or cited:
        f["address"] = known.get(nm) if nm else cited
        f["role"] = "port" if is_port and ".c:" not in fs else "slice"
        f["pair_basis"] = ("name:" + nm) if nm else "address"
        f["label_conflict"] = bool(nm and cited and cited != f["address"])
        f["claimed"] = cited
    else:
        f["address"], f["role"], f["pair_basis"], f["label_conflict"] = None, None, None, False

for f in py:
    if f["name"] in MANUAL_PAIRS:
        f["address"], f["role"], f["pair_basis"], f["label_conflict"] = MANUAL_PAIRS[f["name"]], "port", "manual-rea-evidence", False
paired = [f for f in py if f["address"]]
by_addr = {}
for f in paired: by_addr.setdefault(f["address"], []).append(f)
by_name = {}
for f in py: by_name.setdefault(f["name"], []).append(f)
addr_names = {a: {f["name"] for f in fs} for a, fs in by_addr.items()}

def closure(f):
    """f plus unpaired helpers reachable by name; a name shared by several defs is skipped (ambiguous)."""
    seen, stack, out_ = {id(f)}, [f], [f]
    while stack:
        g = stack.pop()
        for c in g["calls"]:
            cands = by_name.get(c, [])
            if len(cands) != 1: continue
            h = cands[0]
            if h["address"] or id(h) in seen: continue
            seen.add(id(h)); stack.append(h); out_.append(h)
    return out_

def num_in(v, pool):
    # magnitudes: the Python AST stores -3.0 as USub(3.0), so signs are not comparable
    return any(abs(abs(float(v)) - abs(float(p))) <= FLOAT_TOL * max(1.0, abs(float(v))) for p in pool)

def distinct_ints(xs): return {x for x in xs if abs(x) > SMALL_INT}
def distinct_floats(xs): return {x for x in xs if x not in (0.0, 1.0, -1.0)}

rows = []
for a, fs in sorted(by_addr.items(), key=lambda kv: int(kv[0], 16)):
    b = bf.get(a)
    if not b:
        rows.append({"address": a, "python_ports": [f"{f['file']}:{f['name']}" for f in fs], "status": "no-rea-dossier"}); continue
    cl = [g for f in fs for g in closure(f)]
    pcalls = {c for g in cl for c in g["calls"]}
    pnums = {n for g in cl for n in g["numbers"]}
    pbranches = sum(g["branches"] for g in cl)

    # callees: which REA callees have Python counterparts, and does the port call them?
    callee_rows = []
    for c in b["calls"]:
        if c == a: continue
        if c in addr_names:
            callee_rows.append({"address": c, "python": sorted(addr_names[c]), "called_by_port": bool(addr_names[c] & pcalls)})
        else:
            callee_rows.append({"address": c, "python": None, "hopper_lines": hop_lines.get(c)})
    ported = [r for r in callee_rows if r["python"]]
    missing = [r for r in ported if not r["called_by_port"]]
    unported = [r for r in callee_rows if not r["python"] and (r.get("hopper_lines") or 0) >= 25]

    bf_set, bi_cmp, bi_all = distinct_floats(b["floats"]), distinct_ints(b["cmp_ints"]), distinct_ints(b["ints"])
    floats_missing = sorted(x for x in bf_set if not num_in(x, pnums))
    cmp_missing = sorted(x for x in bi_cmp if not num_in(x, pnums))
    py_only = sorted(x for x in pnums if isinstance(x, float) and x not in (0.0, 1.0)
                     and not num_in(x, b["floats"] + b["ints"]) and abs(x) > SMALL_INT)
    rows.append({
        "address": a, "resolved": b["resolved"], "hopper_name": b["name"], "evidence_id": b["evidence_id"],
        "python_ports": [f"{f['file']}:{f['line']}:{f['name']}" for f in fs if f["role"] == "port"],
        "python_slices": [f"{f['file']}:{f['line']}:{f['name']}" for f in fs if f["role"] == "slice"],
        "pair_basis": sorted({f["pair_basis"] for f in fs}),
        "label_conflict": [f"{f['name']} cites {f['claimed']}" for f in fs if f["label_conflict"]],
        "not_a_function_entry": NOT_ENTRIES.get(a),
        "body_insns": b["body_insns"], "dossier_body_coverage": b["body_coverage"],
        "helpers_folded": len(cl) - len(fs),
        "size": {"rea_blocks": b["blocks"], "rea_insns": b["insns"], "py_branches": pbranches},
        "callees": {"total": len(callee_rows), "with_python_port": len(ported), "port_calls_them": len(ported) - len(missing),
                    "not_called_by_port": missing, "nontrivial_unported": unported},
        "constants": {"binary_floats": sorted(bf_set), "floats_absent_in_port": floats_missing,
                      "binary_cmp_thresholds": sorted(bi_cmp), "cmp_thresholds_absent_in_port": cmp_missing,
                      "port_floats_absent_in_binary": py_only},
        "strings": b["strings"],
    })

json.dump({"pairs": rows,
           "unpaired_python": [f"{f['file']}:{f['line']}:{f['name']}" for f in py if not f["address"]]},
          open(out, "w"), indent=1)
print(len(rows), "pairs;", sum(1 for f in py if not f["address"]), "unpaired python functions")
