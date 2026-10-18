// sub_40fb30 @ 0x40fb30
// hopper name: sub_40fb30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40fb30() {
    edx = ecx[0x1];
    eax = edx[0x1];
    if (eax[0xe9] == 0x0) {
            esp = esp - 0x4;
            esi = *arg_4;
            do {
                    if (eax[0x4] < esi) {
                            eax = eax[0x2];
                    }
                    else {
                            edx = eax;
                            eax = *eax;
                    }
            } while (eax[0xe9] == 0x0);
    }
    eax = arg_8;
    eax[0x1] = edx;
    *eax = ecx;
    return eax;
}
