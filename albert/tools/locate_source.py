"""Locate hand-named Ghidra functions in ../Source inside the Hopper decompile by address fingerprints.

Fingerprint = set of absolute addresses referenced (Ghidra FUN_/DAT_/PTR_/LAB_ vs Hopper sub_/dword_/byte_/word_/0x4xxxxx).
A Source function maps to the Hopper function with the highest Jaccard similarity, if it clears
MIN_SCORE and beats the runner-up by MARGIN.
usage: locate_source.py SOURCE_DIR HOPPER_FUNCTIONS_DIR OUT_JSON
"""
import os, re, sys, json, glob
src_dir, hop_dir, out = sys.argv[1:4]
MIN_SCORE, MARGIN = 0.30, 0.10
G = re.compile(r"\b(?:FUN|DAT|PTR|LAB|DOUBLE|FLOAT|QWORD|UNK|s_\w*?)_?00([4-9ab][0-9a-f]{5})\b", re.I)
H = re.compile(r"\b(?:sub|dword|byte|word|qword|float|double|loc|j_sub)_([4-9ab][0-9a-f]{5})\b|\b0x([4-9ab][0-9a-f]{5})\b", re.I)
def gfp(t): return {m.lower() for m in G.findall(t)}
def hfp(t): return {(a or b).lower() for a, b in H.findall(t)}
hop = {}
for f in glob.glob(os.path.join(hop_dir, "*.c")):
    t = open(f).read(); addr = "0x" + os.path.basename(f).split("_")[0]
    body = t.split("\n\n", 1)[1] if "\n\n" in t else t
    fp = hfp(body) - {addr[2:]}
    if fp: hop[addr] = fp
res = {}
for f in sorted(glob.glob(os.path.join(src_dir, "**", "*.[cC]"), recursive=True)):
    name = os.path.splitext(os.path.basename(f))[0]
    fp = gfp(open(f, errors="replace").read())
    if len(fp) < 2: res[name] = {"file": f, "status": "too-few-refs", "refs": len(fp)}; continue
    sc = sorted(((len(fp & h) / len(fp | h), a) for a, h in hop.items() if fp & h), reverse=True)[:3]
    best = sc[0] if sc else (0, None); second = sc[1][0] if len(sc) > 1 else 0
    ok = best[0] >= MIN_SCORE and best[0] - second >= MARGIN
    res[name] = {"file": f, "status": "matched" if ok else "ambiguous", "address": best[1], "score": round(best[0], 3),
                 "runner_up": round(second, 3), "refs": len(fp), "top": [(a, round(s, 3)) for s, a in sc]}
json.dump(res, open(out, "w"), indent=1)
import collections; print(collections.Counter(r["status"] for r in res.values()))
