// sub_4791b2 @ 0x4791b2
// hopper name: sub_4791b2
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4791b2() {
    esp = esp - 0x4;
    esi = arg_0;
    *arg_8 = esi >> 0x4;
    edx = (esi >> 0x4) % ecx[0x2];
    *arg_4 = edx;
    ecx = ecx[0x1];
    if (ecx != 0x0) {
            eax = *(ecx + edx * 0x4);
            while (true) {
                    if (eax != 0x0) {
                            if (eax[0x1] != esi) {
                                    eax = *eax;
                                    continue;
                            }
                            temp_2 = 0x1;
                            break;
                    }
                    temp_2 = 0x0;
                    break;
            }
            if (temp_2 == 0x0) {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
