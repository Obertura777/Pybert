"""Inventory game-logic Python functions and the binary addresses each one claims to port.

usage: py_inventory.py REPO_ROOT NAME_MAP_JSON OUT_JSON
A function's "claimed" address is the first FUN_00xxxxxx / 0x00xxxxxx (in .text) in its docstring;
"mentioned" addresses are any others in its source segment (comments included).
"""
import ast, json, os, re, sys
root, name_map, out = sys.argv[1:4]
cname = {n: a for a, n in json.load(open(name_map))["names"].items()}  # C name -> address
snake = lambda n: re.sub(r"(?<!^)(?=[A-Z])", "_", n).lower()
by_snake = {snake(n): n for n in cname}
SCOPE = ["heuristics", "moves", "monte_carlo", "dispatch", "bot", "state.py", "rng.py"]
EXCLUDE = {"bot/client/_lifecycle.py", "bot/client/_press.py"}  # connection lifecycle / press transport
ADDR = re.compile(r"(?:FUN_|LAB_|0x)00?(4[0-9a-fA-F]{5})\b")
def in_text(a): return 0x401000 <= int(a, 16) < 0x4ac28e
BRANCH = (ast.If, ast.For, ast.While, ast.IfExp, ast.comprehension, ast.Try, ast.Match) if hasattr(ast, "Match") else (ast.If, ast.For, ast.While, ast.IfExp, ast.comprehension, ast.Try)
def module_consts(tree):
    """Module-level NAME = <number> (incl. simple unary/binops) so a Name reference resolves to its value."""
    out = {}
    for n in tree.body:
        if isinstance(n, (ast.Assign, ast.AnnAssign)):
            tgts = n.targets if isinstance(n, ast.Assign) else [n.target]
            try: v = ast.literal_eval(n.value)
            except Exception:
                try: v = eval(compile(ast.Expression(n.value), "<c>", "eval"), {"__builtins__": {}}, dict(out))
                except Exception: continue
            for t in tgts:
                if isinstance(t, ast.Name) and isinstance(v, (int, float)) and not isinstance(v, bool): out[t.id] = v
    return out
GLOBAL_CONSTS = {}
def facts(node, consts):
    calls, nums, strs, branches = set(), set(), set(), 0
    for n in ast.walk(node):
        if isinstance(n, ast.Call):
            f = n.func
            calls.add(f.id if isinstance(f, ast.Name) else f.attr if isinstance(f, ast.Attribute) else "?")
        elif isinstance(n, ast.Constant):
            if isinstance(n.value, bool): continue
            if isinstance(n.value, (int, float)): nums.add(n.value)
            elif isinstance(n.value, str) and n is not getattr(node.body[0], "value", None): strs.add(n.value)
        elif isinstance(n, (ast.Name, ast.Attribute)):
            k = n.id if isinstance(n, ast.Name) else n.attr
            if k in consts: nums.add(consts[k])
            elif k in GLOBAL_CONSTS: nums.add(GLOBAL_CONSTS[k])
        if isinstance(n, BRANCH) or isinstance(n, ast.BoolOp): branches += 1
    return sorted(calls), sorted(nums, key=float), sorted(strs), branches
# first pass: every module's constants, so imported names (e.g. moves._constants) resolve too
for top in SCOPE + ["utils"]:
    p = os.path.join(root, top)
    for f in ([p] if p.endswith(".py") else [os.path.join(d, x) for d, _, fs in os.walk(p) for x in fs if x.endswith(".py")]):
        try: GLOBAL_CONSTS.update(module_consts(ast.parse(open(f).read())))
        except SyntaxError: pass
funcs = []
for top in SCOPE:
    p = os.path.join(root, top)
    files = [p] if p.endswith(".py") else [os.path.join(d, f) for d, _, fs in os.walk(p) for f in fs if f.endswith(".py")]
    for f in sorted(files):
        rel = os.path.relpath(f, root)
        if rel in EXCLUDE or "__pycache__" in rel: continue
        src = open(f).read(); lines = src.splitlines(); tree = ast.parse(src); consts = module_consts(tree)
        for node in ast.walk(tree):
            if not isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef)): continue
            seg = "\n".join(lines[node.lineno - 1: node.end_lineno])
            doc = ast.get_docstring(node) or ""
            claimed = [("0x" + m.lower()) for m in ADDR.findall(doc) if in_text("0x" + m)]
            how = "docstring-address" if claimed else None
            if not claimed:
                hit = [n for n in cname if re.search(r"\b%s\b" % re.escape(n), doc)]
                if hit: claimed, how = [cname[hit[0]]], "docstring-cname:" + hit[0]
                elif node.name.lstrip("_") in by_snake:
                    claimed, how = [cname[by_snake[node.name.lstrip("_")]]], "snake-name:" + by_snake[node.name.lstrip("_")]
            mentioned = sorted({("0x" + m.lower()) for m in ADDR.findall(seg) if in_text("0x" + m)})
            funcs.append({"file": rel, "name": node.name, "line": node.lineno, "end": node.end_lineno,
                          "claimed": claimed[0] if claimed else None, "how": how, "mentioned": mentioned, **dict(zip(("calls", "numbers", "strings", "branches"), facts(node, consts)))})
json.dump(funcs, open(out, "w"), indent=1)
c = sum(1 for f in funcs if f["claimed"]); m = sum(1 for f in funcs if f["mentioned"])
print(len(funcs), "functions;", c, "claim an address;", m, "mention one;", len({f["claimed"] for f in funcs if f["claimed"]}), "distinct claimed")
