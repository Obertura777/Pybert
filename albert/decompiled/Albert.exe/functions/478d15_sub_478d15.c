// sub_478d15 @ 0x478d15
// hopper name: sub_478d15
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_478d15() {
    eax = arg_0;
    if (eax[0x1] == 0xffff) {
            eax = eax + 0x1a;
    }
    else {
            eax = eax + 0x12;
    }
    if (*(int16_t *)eax == 0xffff) {
            eax = eax + 0x4;
    }
    else {
            do {
                    ecx = *(int16_t *)eax;
                    eax = eax + 0x2;
            } while (ecx != 0x0);
    }
    if (*(int16_t *)eax == 0xffff) {
            eax = eax + 0x4;
    }
    else {
            ecx = *(int16_t *)eax;
            eax = eax + 0x2;
            if (ecx != 0x0) {
                    continue;
            }
            break;
    }
    do {
            ecx = *(int16_t *)eax;
            eax = eax + 0x2;
    } while (ecx != 0x0);
    return eax;
}
