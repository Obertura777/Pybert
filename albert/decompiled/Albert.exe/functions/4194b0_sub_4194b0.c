// sub_4194b0 @ 0x4194b0
// hopper name: sub_4194b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4194b0() {
    decomp_var_10 = ebp;
    ebp = arg_4;
    decomp_var_14 = esi;
    esp = esp - 0x18;
    decomp_var_18 = edi;
    edi = ecx;
    ecx = edi[0x1];
    eax = ecx[0x1];
    esi = ecx;
    ecx = 0x1;
    var_C = 0x1;
    if (eax[0x39] == 0x0) {
            edx = *ebp;
            do {
                    ecx = eax[0x4];
                    bool_12 = edx != ecx;
                    esi = eax;
                    if (edx < ecx) {
                            eax = *eax;
                            ecx = 0x1;
                            var_C = 0x1;
                            if (eax[0x39] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (bool_12) {
                            eax = eax[0x2];
                            ecx = 0x0;
                            var_C = 0x0;
                            if (eax[0x39] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (arg_0 >= eax[0xa]) {
                            eax = eax[0x2];
                            ecx = 0x0;
                            var_C = 0x0;
                    }
                    else {
                            eax = *eax;
                            ecx = 0x1;
                            var_C = 0x1;
                    }
            } while (eax[0x39] == 0x0);
    }
    edx = esi;
    var_4 = edx;
    var_8 = edi;
    if (ecx != 0x0) {
            if (esi == *edi[0x1]) {
                    decomp_var_1c = ebp;
                    decomp_var_20 = esi;
                    decomp_var_24 = 0x1;
                    esp = esp - 0x10;
                    decomp_var_28 = &var_8;
                    ecx = sub_4138d0(decomp_var_28, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, var_8);
                    edx = *ecx;
                    eax = arg_0;
                    ecx = ecx[0x1];
                    *eax = edx;
                    eax[0x1] = ecx;
                    eax[0x8] = 0x1;
            }
            else {
                    sub_40f760();
                    edx = var_4;
                    eax = edx[0x4];
                    ecx = *ebp;
                    bool_8 = eax != ecx;
                    if (eax >= ecx) {
                            if (!bool_8 && edx[0xa] < arg_0) {
                                    decomp_var_1c = ebp;
                                    decomp_var_20 = esi;
                                    decomp_var_24 = var_C;
                                    esp = esp - 0x10;
                                    decomp_var_28 = &var_8;
                                    ecx = sub_4138d0(decomp_var_28, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, var_8);
                                    edx = *ecx;
                                    eax = arg_0;
                                    ecx = ecx[0x1];
                                    *eax = edx;
                                    eax[0x1] = ecx;
                                    eax[0x8] = 0x1;
                            }
                            else {
                                    eax = arg_0;
                                    *eax = var_8;
                                    eax[0x1] = edx;
                                    eax[0x8] = 0x0;
                            }
                    }
                    else {
                            decomp_var_1c = ebp;
                            decomp_var_20 = esi;
                            decomp_var_24 = var_C;
                            esp = esp - 0x10;
                            decomp_var_28 = &var_8;
                            ecx = sub_4138d0(decomp_var_28, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, var_8);
                            edx = *ecx;
                            eax = arg_0;
                            ecx = ecx[0x1];
                            *eax = edx;
                            eax[0x1] = ecx;
                            eax[0x8] = 0x1;
                    }
            }
    }
    else {
            eax = edx[0x4];
            ecx = *ebp;
            bool_3 = eax != ecx;
            if (eax >= ecx) {
                    if (!bool_3 && edx[0xa] < arg_0) {
                            decomp_var_1c = ebp;
                            decomp_var_20 = esi;
                            decomp_var_24 = var_C;
                            esp = esp - 0x10;
                            decomp_var_28 = &var_8;
                            ecx = sub_4138d0(decomp_var_28, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, var_8);
                            edx = *ecx;
                            eax = arg_0;
                            ecx = ecx[0x1];
                            *eax = edx;
                            eax[0x1] = ecx;
                            eax[0x8] = 0x1;
                    }
                    else {
                            eax = arg_0;
                            *eax = var_8;
                            eax[0x1] = edx;
                            eax[0x8] = 0x0;
                    }
            }
            else {
                    decomp_var_1c = ebp;
                    decomp_var_20 = esi;
                    decomp_var_24 = var_C;
                    esp = esp - 0x10;
                    decomp_var_28 = &var_8;
                    ecx = sub_4138d0(decomp_var_28, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, var_8);
                    edx = *ecx;
                    eax = arg_0;
                    ecx = ecx[0x1];
                    *eax = edx;
                    eax[0x1] = ecx;
                    eax[0x8] = 0x1;
            }
    }
    return eax;
}
