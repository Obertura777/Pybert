// sub_473dd9 @ 0x473dd9
// hopper name: sub_473dd9
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_473dd9() {
    esp = esp - 0x8;
    esi = GetDlgItem(arg_0, arg_4);
    if (esi != 0x0) {
            esp = esp - 0x4;
            if (GetTopWindow(esi) != 0x0) {
                    esp = esp - 0xc;
                    if (sub_473dd9(esi, arg_4, arg_8) == 0x0) {
                            esp = esp - 0x4;
                            decomp_var_14 = esi;
                            if (arg_8 == 0x0) {
                                    sub_473aee(decomp_var_14);
                            }
                            else {
                                    if (sub_473b15() == 0x0) {
                                            esp = esp - 0x4;
                                            eax = GetTopWindow(arg_0);
                                            while (true) {
                                                    esi = eax;
                                                    if (esi != 0x0) {
                                                            esp = esp - 0xc;
                                                            if (sub_473dd9(esi, arg_4, arg_8) == 0x0) {
                                                                    esp = esp - 0x8;
                                                                    eax = GetWindow(esi, 0x2);
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                    }
                            }
                    }
            }
            else {
                    esp = esp - 0x4;
                    decomp_var_14 = esi;
                    if (arg_8 == 0x0) {
                            sub_473aee(decomp_var_14);
                    }
                    else {
                            if (sub_473b15() == 0x0) {
                                    esp = esp - 0x4;
                                    eax = GetTopWindow(arg_0);
                                    while (true) {
                                            esi = eax;
                                            if (esi != 0x0) {
                                                    esp = esp - 0xc;
                                                    if (sub_473dd9(esi, arg_4, arg_8) == 0x0) {
                                                            esp = esp - 0x8;
                                                            eax = GetWindow(esi, 0x2);
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                            }
                    }
            }
    }
    else {
            esp = esp - 0x4;
            eax = GetTopWindow(arg_0);
            while (true) {
                    esi = eax;
                    if (esi != 0x0) {
                            esp = esp - 0xc;
                            if (sub_473dd9(esi, arg_4, arg_8) == 0x0) {
                                    esp = esp - 0x8;
                                    eax = GetWindow(esi, 0x2);
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    temp_0 = 0x0;
                    break;
            }
    }
    return;
}
