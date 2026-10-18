// sub_46f8ec @ 0x46f8ec
// hopper name: sub_46f8ec
// referenced by: called,pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46f8ec() {
    var_8 = ebp;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    if (arg_0 <= 0x0) {
            edi = ecx[0x8];
            if (edi != 0x0) {
                    ebp = 0x0;
                    eax = edi[0x8];
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            decomp_var_14 = eax;
                            if (IsWindowVisible(decomp_var_14) != 0x0) {
                                    decomp_var_14 = ebp;
                                    decomp_var_18 = 0x1;
                                    decomp_var_1c = 0x363;
                                    sub_474101();
                                    esp = esp - 0x2c;
                                    sub_4743dc(edi[0x8], 0x363, 0x1, ebp, 0x1, 0x1);
                            }
                    }
            }
            sub_4715ba() + 0x74;
            esi = *(sub_46e822() + 0x8);
            while (true) {
                    ebp = 0x0;
                    if (esi == 0x0) {
                            break;
                    }
                    if (esi[0x8] == ebp) {
                            esi = esi[0x1b];
                            continue;
                    }
                    if (esi == edi) {
                            esi = esi[0x1b];
                            continue;
                    }
                    ebp = 0x0;
                    if (esi[0x28] == 0x0) {
                            esp = esp - 0x4;
                            sub_476779(ebp);
                    }
                    esp = esp - 0x4;
                    if (IsWindowVisible(esi[0x8]) != 0x0) {
                            sub_474101();
                            esp = esp - 0x2c;
                            sub_4743dc(esi[0x8], 0x363, 0x1, ebp, 0x1, 0x1);
                            eax = esi[0x28];
                            if (eax > ebp) {
                                    esp = esp - 0x4;
                                    sub_476779(eax);
                            }
                            esi[0x28] = esi[0x28] | 0xffffffff;
                            esi = esi[0x1b];
                            continue;
                    }
                    if (esi[0x28] >= ebp) {
                            sub_474101();
                            esp = esp - 0x2c;
                            sub_4743dc(esi[0x8], 0x363, 0x1, ebp, 0x1, 0x1);
                            eax = esi[0x28];
                            if (eax > ebp) {
                                    esp = esp - 0x4;
                                    sub_476779(eax);
                            }
                            esi[0x28] = esi[0x28] | 0xffffffff;
                            esi = esi[0x1b];
                            continue;
                    }
                    eax = esi[0x28];
                    if (eax > ebp) {
                            esp = esp - 0x4;
                            sub_476779(eax);
                    }
                    esi[0x28] = esi[0x28] | 0xffffffff;
                    esi = esi[0x1b];
            }
    }
    else {
            sub_4715ba() + 0x74;
            if (*(sub_46e822() + 0x10) == 0x0) {
                    sub_478191();
                    esp = esp - 0x4;
                    decomp_var_14 = 0x1;
                    sub_4783a2(0x1);
            }
    }
    eax = var_8 < 0x0 ? 0x1 : 0x0;
    return eax;
}
