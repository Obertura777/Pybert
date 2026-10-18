// sub_48e3bb @ 0x48e3bb
// hopper name: sub_48e3bb
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48e3bb() {
    ecx = arg_0;
    esp = esp - 0xc;
    decomp_var_c = edi;
    if (ecx >= 0x0) {
            if (ecx < *dword_bc7228) {
                    esi = (ecx & 0x1f) * 0x28;
                    edi = (SAR(ecx, 0x5)) * 0x4 + dword_bc7240;
                    eax = *edi;
                    eax = eax + esi;
                    if ((eax[0x4] & 0x1) != 0x0) {
                            if (*eax != 0xffffffff) {
                                    if (*dword_4c8e20 == 0x1) {
                                            ecx = ecx - 0x0;
                                            if (ecx != 0x0) {
                                                    ecx = ecx - 0x1;
                                                    if (ecx != 0x0) {
                                                            if (ecx == 0x1) {
                                                                    decomp_var_10 = 0x0;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_14 = 0xfffffff4;
                                                                    SetStdHandle(decomp_var_14, decomp_var_10);
                                                            }
                                                    }
                                                    else {
                                                            decomp_var_10 = 0x0;
                                                            esp = esp - 0x8;
                                                            decomp_var_14 = 0xfffffff5;
                                                            SetStdHandle(decomp_var_14, decomp_var_10);
                                                    }
                                            }
                                            else {
                                                    decomp_var_10 = 0x0;
                                                    esp = esp - 0x8;
                                                    decomp_var_14 = 0xfffffff6;
                                                    SetStdHandle(decomp_var_14, decomp_var_10);
                                            }
                                    }
                                    eax = *edi;
                                    *(esi + eax) = *(esi + eax) | 0xffffffff;
                                    eax = 0x0;
                            }
                            else {
                                    *sub_47d812() = 0x9;
                                    eax = sub_47d825();
                                    *eax = 0x0;
                                    eax = eax | 0xffffffff;
                            }
                    }
                    else {
                            *sub_47d812() = 0x9;
                            eax = sub_47d825();
                            *eax = 0x0;
                            eax = eax | 0xffffffff;
                    }
            }
            else {
                    *sub_47d812() = 0x9;
                    eax = sub_47d825();
                    *eax = 0x0;
                    eax = eax | 0xffffffff;
            }
    }
    else {
            *sub_47d812() = 0x9;
            eax = sub_47d825();
            *eax = 0x0;
            eax = eax | 0xffffffff;
    }
    return eax;
}
