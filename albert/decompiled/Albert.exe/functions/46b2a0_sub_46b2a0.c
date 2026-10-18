// sub_46b2a0 @ 0x46b2a0
// hopper name: sub_46b2a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46b2a0() {
    eax = ecx[0x1];
    esp = esp - 0x10;
    decomp_var_10 = edi;
    edi = eax[0x1];
    var_C = eax;
    if (edi[0x2d] == 0x0) {
            decomp_var_14 = ebx;
            esp = esp - 0xc;
            ebp = arg_0[0x5];
            var_4 = arg_0[0x6];
            do {
                    bool_10 = edi[0x9] < 0x10;
                    ebx = edi[0x8];
                    if (!bool_10) {
                            edx = edi[0x4];
                    }
                    else {
                            edx = edi + 0x10;
                    }
                    esi = ebp;
                    ecx = esi;
                    if (esi >= ebx) {
                            ecx = ebx;
                    }
                    eax = arg_4;
                    if (saved_fp >= 0x10) {
                            eax = *eax;
                    }
                    eax = sub_40cd30(eax, edx, ecx);
                    esp = (esp - 0xc) + 0xc;
                    bool_3 = eax >= 0x0;
                    if (eax != 0x0) {
                            if (!bool_3) {
                                    var_8 = edi;
                                    edi = *edi;
                            }
                            else {
                                    edi = edi[0x2];
                            }
                            if (edi[0x2d] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (esi < ebx) {
                            var_8 = edi;
                            edi = *edi;
                            if (edi[0x2d] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    bool_11 = esi >= ebx;
                    if (!bool_11) {
                            var_8 = edi;
                            edi = *edi;
                    }
                    else {
                            edi = edi[0x2];
                    }
            } while (edi[0x2d] == 0x0);
            eax = var_4;
            esp = esp + 0xc;
    }
    return eax;
}
