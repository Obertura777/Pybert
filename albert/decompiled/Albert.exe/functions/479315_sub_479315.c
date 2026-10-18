// sub_479315 @ 0x479315
// hopper name: sub_479315
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479315() {
    eax = ecx;
    ecx = arg_0;
    *eax = 0x4b381c;
    if (ecx <= 0x0) {
            ecx = 0xa;
    }
    eax[0x1] = 0x0;
    eax[0x2] = 0x11;
    eax[0x3] = 0x0;
    eax[0x4] = 0x0;
    eax[0x5] = 0x0;
    eax[0x6] = ecx;
    return eax;
}
