// sub_419c30 @ 0x419c30
// hopper name: sub_419c30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_419c30() {
    edx = ecx[0x1];
    eax = edx[0x1];
    decomp_var_c = ebx;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    edi = arg_4;
    var_8 = 0x1;
    if (eax[0x29] == 0x0) {
            ebp = *edi;
            esp = esp - 0x8;
            esi = edi[0x1];
            do {
                    bool_6 = esi > eax[0x5];
                    bool_3 = esi < eax[0x5];
                    edx = eax;
                    if (bool_6) {
                            eax = eax[0x2];
                            var_8 = 0x0;
                            if (eax[0x29] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (bool_3) {
                            eax = *eax;
                            var_8 = 0x1;
                            if (eax[0x29] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (ebp < eax[0x4]) {
                            eax = *eax;
                            var_8 = 0x1;
                    }
                    else {
                            eax = eax[0x2];
                            var_8 = 0x0;
                    }
            } while (eax[0x29] == 0x0);
            esp = esp + 0x8;
    }
    eax = sub_414070(&saved_fp, saved_fp, edx, edi, var_8, decomp_var_4, saved_fp, arg_0, arg_4);
    ecx = eax;
    eax = arg_8;
    edx = *ecx;
    ecx = ecx[0x1];
    eax[0x8] = 0x1;
    *eax = edx;
    eax[0x1] = ecx;
    return eax;
}
