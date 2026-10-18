// sub_479b05 @ 0x479b05
// hopper name: sub_479b05
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479b05() {
    eax = ecx;
    ecx = arg_0;
    if (ecx < 0x4) {
            ecx = 0x4;
            esp = (esp - 0x4) + 0x4;
    }
    edx = arg_4;
    if (edx <= 0x1) {
            edx = 0x40;
    }
    eax[0x3] = eax[0x3] & 0x0;
    eax[0x2] = eax[0x2] & 0x0;
    *eax = ecx;
    eax[0x1] = edx;
    return eax;
}
