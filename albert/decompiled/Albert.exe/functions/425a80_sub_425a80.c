// sub_425a80 @ 0x425a80
// hopper name: sub_425a80
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_425a80() {
    eax = sub_4103b0();
    ecx[0x1] = eax;
    eax[0x21] = 0x1;
    eax = ecx[0x1];
    eax[0x1] = eax;
    eax = ecx[0x1];
    *eax = eax;
    eax = ecx[0x1];
    eax[0x2] = eax;
    ecx[0x2] = 0x0;
    eax = ecx;
    return eax;
}
