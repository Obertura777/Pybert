// sub_474ead @ 0x474ead
// hopper name: sub_474ead
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_474ead() {
    eax = arg_0;
    ecx = arg_4;
    if (*eax == *ecx) {
            if (eax[0x1] == ecx[0x1]) {
                    if (eax[0x2] == ecx[0x2]) {
                            if (eax[0x3] == ecx[0x3]) {
                                    eax = 0x1;
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
