// sub_4771e2 @ 0x4771e2
// hopper name: sub_4771e2
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4771e2() {
    if (ecx == 0x0) {
            sub_46dedc();
    }
    eax = *ecx;
    eax = (*eax)();
    if (eax == 0x0) {
            sub_46dedc();
    }
    ecx = eax;
    eax = ecx;
    if (eax == 0x0) {
            sub_46dedc();
    }
    if (arg_0 == 0x0) {
            sub_46dedc();
    }
    while (eax != arg_0) {
            eax = eax[0x4];
            if (eax == 0x0) {
                    break;
            }
    }
    return;
}
