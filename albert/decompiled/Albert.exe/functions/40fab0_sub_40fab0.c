// sub_40fab0 @ 0x40fab0
// hopper name: sub_40fab0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40fab0() {
    ecx = *(ecx[0x1] + 0x4);
    if (ecx[0x15] == 0x0) {
            decomp_var_4 = esi;
            esp = esp - 0x8;
            edi = arg_0;
            esi = *edi;
            do {
                    edx = ecx[0x3];
                    bool_5 = edx != esi;
                    if (edx < esi) {
                            ecx = ecx[0x2];
                            if (ecx[0x15] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (bool_5) {
                            ecx = *ecx;
                            if (ecx[0x15] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (ecx[0x8] < edi[0x2]) {
                            ecx = ecx[0x2];
                    }
                    else {
                            ecx = *ecx;
                    }
            } while (ecx[0x15] == 0x0);
    }
    return;
}
