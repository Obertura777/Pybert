import sys, os, struct
d=sys.argv[1]
r=lambda n: open(os.path.join(d,n),'rb').read()
pool=r('!_StringPool'); data=r('!_StringData')
cp=struct.unpack('<I',pool[:4])[0]; long_refs=bool(cp&0x80000000)
strs=[""]; off=0; i=4
while i<len(pool):
    ln,rc=struct.unpack('<HH',pool[i:i+4]); i+=4
    if ln==0 and rc!=0: ln=struct.unpack('<I',pool[i:i+4])[0]; i+=4
    strs.append(data[off:off+ln].decode('cp1252','replace')); off+=ln
sw=3 if long_refs else 2
def ref(b): return int.from_bytes(b,'little')
# _Columns: Table(s), Number(i2), Name(s), Type(i2)
def rows(raw, widths):
    n=len(raw)//sum(widths); cols=[]; p=0
    for w in widths: cols.append([raw[p+k*w:p+k*w+w] for k in range(n)]); p+=n*w
    return list(zip(*cols)) if cols else []
colraw=r('!_Columns')
cols={}
for t,num,name,typ in rows(colraw,[sw,2,sw,2]):
    cols.setdefault(strs[ref(t)],[]).append((ref(num)^0x8000,strs[ref(name)],ref(typ)^0x8000))
out=[]
for tbl in sorted(cols):
    spec=sorted(cols[tbl]); fn='!'+tbl
    if not os.path.exists(os.path.join(d,fn)): continue
    ws=[]
    for _,nm,ty in spec:
        if ty&0x800: ws.append(sw)          # string
        elif (ty&0xff)==4 and not ty&0x400: ws.append(4)
        else: ws.append(2 if (ty&0xff)<=2 else 4)
    raw=r(fn); out.append(f"== {tbl} ({' | '.join(n for _,n,_ in spec)})")
    for row in rows(raw,ws):
        vals=[]
        for (_,nm,ty),v,w in zip(spec,row,ws):
            x=ref(v)
            if ty&0x800: vals.append(strs[x])
            elif w==2: vals.append('' if x==0 else str(x-0x8000))
            else: vals.append('' if x==0 else str(x-0x80000000))
        out.append(' | '.join(vals))
print("\n".join(out))
