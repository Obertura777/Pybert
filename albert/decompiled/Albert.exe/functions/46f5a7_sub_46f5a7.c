// sub_46f5a7 @ 0x46f5a7
// hopper name: sub_46f5a7
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46f5a7() {
    ecx = *(sub_4715ed() + 0x4);
    if (ecx != 0x0) {
            eax = *ecx;
            eax = (eax[0x16])(arg_0);
    }
    else {
            esp = esp - 0x4;
            decomp_var_4 = edi;
            edi = arg_0;
            if (*(sub_4715ed(decomp_var_4) + 0x4) != 0x0) {
                    if (*edi == 0x0) {
                            esp = esp - 0x4;
                            if (sub_46f483(edi, decomp_var_4) != 0x0) {
                                    eax = 0x1;
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_8 = esi;
                                    eax = sub_46e5d5();
                                    esi = eax;
                                    if (esi != 0x0) {
                                            eax = esi[0x8];
                                    }
                                    esp = esp - 0x8;
                                    if (sub_473e50(eax, edi, decomp_var_8) != 0x0) {
                                            eax = 0x1;
                                    }
                                    else {
                                            if (esi != 0x0) {
                                                    esp = esp - 0x4;
                                                    sub_473aee(*edi);
                                                    if (sub_474d7e() != esi) {
                                                            eax = *esi;
                                                            esp = esp - 0x4;
                                                            eax = (eax[0x40])(edi);
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            decomp_var_8 = esi;
                            eax = sub_46e5d5();
                            esi = eax;
                            if (esi != 0x0) {
                                    eax = esi[0x8];
                            }
                            esp = esp - 0x8;
                            if (sub_473e50(eax, edi, decomp_var_8) != 0x0) {
                                    eax = 0x1;
                            }
                            else {
                                    if (esi != 0x0) {
                                            esp = esp - 0x4;
                                            sub_473aee(*edi);
                                            if (sub_474d7e() != esi) {
                                                    eax = *esi;
                                                    esp = esp - 0x4;
                                                    eax = (eax[0x40])(edi);
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                    }
            }
            else {
                    esp = esp - 0x4;
                    decomp_var_8 = esi;
                    eax = sub_46e5d5();
                    esi = eax;
                    if (esi != 0x0) {
                            eax = esi[0x8];
                    }
                    esp = esp - 0x8;
                    if (sub_473e50(eax, edi, decomp_var_8) != 0x0) {
                            eax = 0x1;
                    }
                    else {
                            if (esi != 0x0) {
                                    esp = esp - 0x4;
                                    sub_473aee(*edi);
                                    if (sub_474d7e() != esi) {
                                            eax = *esi;
                                            esp = esp - 0x4;
                                            eax = (eax[0x40])(edi);
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
            }
    }
    return eax;
}
