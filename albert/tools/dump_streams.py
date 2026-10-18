import olefile, sys, os
src, out = sys.argv[1], sys.argv[2]
def decode(name):
    # MSI stream-name compression (base64-ish packing into 0x3800-0x4840)
    tbl="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz._"
    r=""
    for ch in name:
        c=ord(ch)
        if 0x3800<=c<0x4800:
            c-=0x3800; r+=tbl[c&0x3f]+tbl[(c>>6)&0x3f]
        elif 0x4800<=c<0x4840: r+=tbl[c-0x4800]
        elif c==0x4840: r+="!"
        else: r+=ch
    return r
o=olefile.OleFileIO(src)
for e in o.listdir():
    n="/".join(decode(p) for p in e).replace("\x05","_")
    d=o.openstream(e).read()
    fn=os.path.join(out,n.replace("/","_"))
    open(fn,"wb").write(d); print(len(d), repr(n), d[:4])
