// sub_486982 @ 0x486982
// hopper name: sub_486982
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_486982() {
    decomp_var_4 = esi;
    esi = arg_0;
    esp = (esp - 0xc) + 0x8;
    if (sub_48e150(sub_4867ae(esi)) != 0x0) {
            if (esi == sub_486807() + 0x20) {
                    *dword_bc6894 = *dword_bc6894 + 0x1;
                    if ((esi[0x6] & 0x10c) == 0x0) {
                            decomp_var_8 = ebx;
                            esp = esp - 0x8;
                            decomp_var_c = edi;
                            edi = 0xbc6898;
                            if (*edi == 0x0) {
                                    eax = sub_481280(0x1000);
                                    esp = (esp - 0x4) + 0x4;
                                    *edi = eax;
                                    if (eax == 0x0) {
                                            esi[0x2] = esi + 0x14;
                                            *esi = esi + 0x14;
                                            esp = (esp - 0x4) + 0x4;
                                            esi[0x6] = 0x2;
                                            esi[0x1] = 0x2;
                                    }
                                    else {
                                            edi = *edi;
                                            esi[0x2] = edi;
                                            *esi = edi;
                                            esi[0x6] = 0x1000;
                                            esi[0x1] = 0x1000;
                                    }
                            }
                            else {
                                    edi = *edi;
                                    esi[0x2] = edi;
                                    *esi = edi;
                                    esi[0x6] = 0x1000;
                                    esi[0x1] = 0x1000;
                            }
                            esi[0x3] = esi[0x3] | 0x1102;
                            eax = 0x1;
                    }
                    else {
                            eax = 0x0;
                    }
            }
            else {
                    if (esi == sub_486807() + 0x40) {
                            *dword_bc6894 = *dword_bc6894 + 0x1;
                            if ((esi[0x6] & 0x10c) == 0x0) {
                                    decomp_var_8 = ebx;
                                    esp = esp - 0x8;
                                    decomp_var_c = edi;
                                    edi = 0xbc689c;
                                    if (*edi == 0x0) {
                                            eax = sub_481280(0x1000);
                                            esp = (esp - 0x4) + 0x4;
                                            *edi = eax;
                                            if (eax == 0x0) {
                                                    esi[0x2] = esi + 0x14;
                                                    *esi = esi + 0x14;
                                                    esp = (esp - 0x4) + 0x4;
                                                    esi[0x6] = 0x2;
                                                    esi[0x1] = 0x2;
                                            }
                                            else {
                                                    edi = *edi;
                                                    esi[0x2] = edi;
                                                    *esi = edi;
                                                    esi[0x6] = 0x1000;
                                                    esi[0x1] = 0x1000;
                                            }
                                    }
                                    else {
                                            edi = *edi;
                                            esi[0x2] = edi;
                                            *esi = edi;
                                            esi[0x6] = 0x1000;
                                            esi[0x1] = 0x1000;
                                    }
                                    esi[0x3] = esi[0x3] | 0x1102;
                                    eax = 0x1;
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
    else {
            eax = 0x0;
    }
    return eax;
}
