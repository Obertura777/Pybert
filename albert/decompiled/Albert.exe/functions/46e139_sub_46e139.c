// sub_46e139 @ 0x46e139
// hopper name: sub_46e139
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46e139() {
    decomp_var_18 = ebx;
    esp = esp - 0x8;
    decomp_var_1c = edi;
    ecx[0x28] = 0x0;
    var_10 = ecx;
    var_4 = 0x0;
    var_8 = 0x0;
    var_14 = 0x4;
    var_C = 0x0;
    ebx = dword_4c86bc;
    if (*dword_4c86bc != 0x0) {
            esp = esp - 0x4;
            decomp_var_20 = esi;
            do {
                    esp = esp - 0x14;
                    eax = RegOpenKeyExA(0x80000001, *ebx, 0x0, 0x1, &var_4);
                    if (eax == 0x0) {
                            esi = ebx[0x1];
                            while (true) {
                                    eax = *esi;
                                    if (eax == 0x0) {
                                            break;
                                    }
                                    esp = esp - 0x18;
                                    eax = RegQueryValueExA(var_4, eax, 0x0, &var_C, &var_8, &var_14);
                                    if (eax == 0x0 && var_C == 0x4) {
                                            ecx = esi[0x1];
                                            eax = var_10;
                                            if (var_8 != 0x0) {
                                                    eax[0x28] = eax[0x28] | ecx;
                                            }
                                            else {
                                                    eax[0x28] = eax[0x28] & !ecx;
                                            }
                                    }
                                    var_8 = 0x0;
                                    var_14 = 0x4;
                                    var_C = 0x0;
                                    esi = esi + 0x8;
                            }
                            esp = esp - 0x4;
                            RegCloseKey(var_4);
                            var_4 = 0x0;
                    }
                    ebx = ebx + 0x8;
            } while (*ebx != 0x0);
            esp = esp + 0x4;
    }
    return 0x1;
}
