// sub_46f483 @ 0x46f483
// hopper name: sub_46f483
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46f483() {
    decomp_var_8 = ebx;
    decomp_var_c = ebp;
    decomp_var_10 = esi;
    esp = esp - 0x14;
    var_4 = ecx;
    esi = (*(*ecx + 0x28))(edi, decomp_var_10, decomp_var_c, decomp_var_8, var_4);
    if (*esi != 0x0) {
            ebx = arg_4;
            while (true) {
                    eax = ebx[0x1];
                    decomp_var_14 = 0x0;
                    esp = esp - 0x8;
                    decomp_var_18 = 0x0;
                    if (eax < 0xc000) {
                            esp = esp - 0x8;
                            eax = sub_472033(esi[0x1], eax, decomp_var_18, decomp_var_14);
                            if (eax != 0x0) {
                                    temp_1 = 0x0;
                                    break;
                            }
                            else {
                                    eax = (*esi)();
                                    esi = eax;
                                    if (*esi != 0x0) {
                                            continue;
                                    }
                                    temp_1 = 0x1;
                                    break;
                            }
                    }
                    else {
                            eax = esi[0x1];
                            while (true) {
                                    esp = esp - 0x8;
                                    eax = sub_472033(eax, 0xc000, decomp_var_14, decomp_var_10);
                                    if (eax != 0x0) {
                                            if (*eax[0x4] != ebx[0x1]) {
                                                    decomp_var_10 = 0x0;
                                                    esp = esp - 0x8;
                                                    decomp_var_14 = 0x0;
                                                    eax = eax + 0x18;
                                                    continue;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    temp_0 = 0x1;
                                    break;
                            }
                            if (temp_0 != 0x0) {
                                    eax = (*esi)();
                                    esi = eax;
                                    if (*esi != 0x0) {
                                            continue;
                                    }
                                    temp_1 = 0x1;
                                    break;
                            }
                            else {
                                    temp_1 = 0x0;
                                    break;
                            }
                    }
            }
            if (temp_1 != 0x0) {
                    eax = 0x0;
            }
            else {
                    esp = esp - 0x8;
                    (eax[0x5])(ebx[0x2], ebx[0x3]);
                    eax = 0x1;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
