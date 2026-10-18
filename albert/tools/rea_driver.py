"""Drive the REA MCP server over stdio so bulk results go to disk instead of an agent context.

usage: rea_driver.py BINARY ENTRIES_JSON|- OUTDIR [CHUNK] [--inventory]
  ENTRIES_JSON  list of {"address": ...} from select_entries.py; "-" skips decompilation
  --inventory   also save list_procedures / list_strings / binary_overview Evidence
  --analyze ADDRS_JSON  run analyze_function for each address in the JSON list, save OUTDIR/af/<addr>.json
  --call NAME TOOL JSON_ARGS   run any extra REA tool on the open target, save to OUTDIR/NAME.json (repeatable)
"""
import json, subprocess, sys, os, time
inventory = "--inventory" in sys.argv
argv, calls, args, analyze = sys.argv[1:], [], [], []
while argv:
    a = argv.pop(0)
    if a == "--analyze": analyze = json.load(open(argv.pop(0)))
    elif a == "--call": calls.append((argv.pop(0), argv.pop(0), json.loads(argv.pop(0))))
    elif a != "--inventory": args.append(a)
exe, entries_json, outdir = args[:3]
chunk = int(args[3]) if len(args) > 3 else 250
os.makedirs(outdir, exist_ok=True)
p = subprocess.Popen(["npx", "-y", "rea-agents@6.5.0", "--mcp"], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                     stderr=open(os.path.join(outdir, "server.log"), "w"), text=True, bufsize=1)
nid = 0
def call(method, params=None, notify=False):
    global nid
    msg = {"jsonrpc": "2.0", "method": method}
    if params is not None: msg["params"] = params
    if not notify: nid += 1; msg["id"] = nid
    p.stdin.write(json.dumps(msg) + "\n"); p.stdin.flush()
    if notify: return None
    while True:
        line = p.stdout.readline()
        if not line: raise SystemExit("server exited")
        r = json.loads(line)
        if r.get("id") == nid: return r
def tool(name, args):
    r = call("tools/call", {"name": name, "arguments": args})
    if "error" in r: raise RuntimeError(r["error"])
    res = r["result"]
    txt = "".join(c.get("text", "") for c in res.get("content", []))
    if res.get("isError"): raise RuntimeError(txt[:2000])
    return res.get("structuredContent") or json.loads(txt)
call("initialize", {"protocolVersion": "2025-06-18", "capabilities": {}, "clientInfo": {"name": "pybert-driver", "version": "1"}})
call("notifications/initialized", notify=True)
print(json.dumps(tool("open_binary", {"path": exe}))[:300], flush=True)
if inventory:
    for t in ("binary_overview", "list_procedures", "list_strings"):
        json.dump(tool(t, {}), open(os.path.join(outdir, t + ".json"), "w"))
        print("saved", t, flush=True)
for name, t, targs in calls:
    try: json.dump(tool(t, targs), open(os.path.join(outdir, name + ".json"), "w")); print("saved", name, flush=True)
    except RuntimeError as e: print("failed", name, str(e)[:300], flush=True)
if analyze: os.makedirs(os.path.join(outdir, "af"), exist_ok=True)
for k, a in enumerate(analyze):
    fn = os.path.join(outdir, "af", a + ".json")
    if os.path.exists(fn): continue
    try: json.dump(tool("analyze_function", {"procedure": a}), open(fn, "w"))
    except RuntimeError as e: json.dump({"error": str(e)[:4000], "address": a}, open(fn + ".err", "w"))
    if k % 50 == 0: print("analyzed", k, "/", len(analyze), flush=True)
addrs = [] if entries_json == "-" else [e["address"] for e in json.load(open(entries_json))]
def decompile(lo, hi):
    fn = os.path.join(outdir, "batch_%05d_%05d.json" % (lo, hi))
    if os.path.exists(fn): return
    t = time.time()
    try:
        r = tool("batch_decompile", {"addresses": addrs[lo:hi]})
    except RuntimeError as e:
        if "resource_constraint" not in str(e): raise
        if hi - lo == 1:  # a single function too large for the stdio budget
            json.dump({"oversized": addrs[lo], "error": str(e)[:4000]}, open(fn + ".oversized", "w"))
            print(lo, "oversized", addrs[lo], flush=True); return
        mid = (lo + hi) // 2; decompile(lo, mid); decompile(mid, hi); return
    json.dump(r, open(fn, "w"))
    nr = r["normalized_result"]
    print(lo, hi, nr["succeeded"], nr["failed"], "%.1fs" % (time.time()-t), flush=True)
for i in range(0, len(addrs), chunk):
    decompile(i, min(i + chunk, len(addrs)))
tool("close_binary", {})
p.stdin.close(); p.wait(timeout=60)
