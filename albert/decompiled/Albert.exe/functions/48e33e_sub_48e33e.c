// sub_48e33e @ 0x48e33e
// hopper name: sub_48e33e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48e33e() {
    eax = arg_0;
    esp = esp - 0x8;
    if (eax >= 0x0) {
            if (eax < *dword_bc7228) {
                    esi = (eax & 0x1f) * 0x28;
                    edi = (SAR(eax, 0x5)) * 0x4 + dword_bc7240;
                    if (*(esi + *edi) == 0xffffffff) {
                            esp = esp - 0x4;
                            decomp_var_c = ebx;
                            ebx = arg_4;
                            if (*dword_4c8e20 == 0x1) {
                                    eax = eax - 0x0;
                                    if (eax != 0x0) {
                                            eax = eax - 0x1;
                                            if (eax != 0x0) {
                                                    if (eax == 0x1) {
                                                            decomp_var_10 = ebx;
                                                            esp = esp - 0x8;
                                                            decomp_var_14 = 0xfffffff4;
                                                            SetStdHandle(decomp_var_14, decomp_var_10);
                                                    }
                                            }
                                            else {
                                                    decomp_var_10 = ebx;
                                                    esp = esp - 0x8;
                                                    decomp_var_14 = 0xfffffff5;
                                                    SetStdHandle(decomp_var_14, decomp_var_10);
                                            }
                                    }
                                    else {
                                            decomp_var_10 = ebx;
                                            esp = esp - 0x8;
                                            decomp_var_14 = 0xfffffff6;
                                            SetStdHandle(decomp_var_14, decomp_var_10);
                                    }
                            }
                            *(esi + *edi) = ebx;
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
                    else {
                            *sub_47d812() = 0x9;
                            eax = sub_47d825();
                            *eax = *eax & 0x0;
                            eax = eax | 0xffffffff;
                    }
            }
            else {
                    *sub_47d812() = 0x9;
                    eax = sub_47d825();
                    *eax = *eax & 0x0;
                    eax = eax | 0xffffffff;
            }
    }
    else {
            *sub_47d812() = 0x9;
            eax = sub_47d825();
            *eax = *eax & 0x0;
            eax = eax | 0xffffffff;
    }
    return eax;
}
