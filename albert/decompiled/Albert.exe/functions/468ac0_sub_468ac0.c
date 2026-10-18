// sub_468ac0 @ 0x468ac0
// hopper name: sub_468ac0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_468ac0() {
    decomp_var_8 = esi;
    esp = esp - 0x8;
    decomp_var_c = edi;
    edi = arg_0;
    esi = ecx;
    if (esi[0x5] < edi) {
            sub_492fd5();
    }
    ebp = arg_4;
    if ((eax | 0xffffffff) - esi[0x5] <= ebp) {
            sub_492f96();
    }
    if (ebp > 0x0) {
            esp = esp - 0x4;
            decomp_var_10 = ebx;
            ebx = esi[0x5];
            ebx = ebx + ebp;
            if (ebx > 0xfffffffe) {
                    sub_492f96();
            }
            eax = esi[0x6];
            bool_9 = eax <= ebx;
            if (eax < ebx) {
                    esp = esp - 0x8;
                    sub_401c20(ebx, esi[0x5]);
                    if (!bool_9) {
                            eax = esi[0x6];
                            if (eax >= 0x10) {
                                    arg_0 = esi[0x1];
                            }
                            else {
                                    arg_0 = esi + 0x4;
                            }
                            if (eax >= 0x10) {
                                    ecx = esi[0x1];
                            }
                            else {
                                    ecx = esi + 0x4;
                            }
                            sub_47a62a(ecx + edi + ebp, eax - edi - ebp, arg_0 + edi, esi[0x5] - edi);
                            esp = (esp - 0x10) + 0x10 - 0xc;
                            sub_4600b0(edi, ebp, arg_8, decomp_var_10, decomp_var_c, decomp_var_8);
                            bool_12 = esi[0x6] < 0x10;
                            esi[0x5] = ebx;
                            if (!bool_12) {
                                    *(int8_t *)(esi[0x1] + ebx) = 0x0;
                            }
                            else {
                                    *(int8_t *)(esi + 0x4 + ebx) = 0x0;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            esp = esp + 0x4;
                    }
            }
            else {
                    bool_10 = ebx <= 0x0;
                    if (ebx == 0x0) {
                            esi[0x5] = ebx;
                            if (eax >= 0x10) {
                                    *(int8_t *)esi[0x1] = ebx;
                            }
                            else {
                                    esi[0x4] = 0x0;
                            }
                    }
                    else {
                            if (!bool_10) {
                                    eax = esi[0x6];
                                    if (eax >= 0x10) {
                                            arg_0 = esi[0x1];
                                    }
                                    else {
                                            arg_0 = esi + 0x4;
                                    }
                                    if (eax >= 0x10) {
                                            ecx = esi[0x1];
                                    }
                                    else {
                                            ecx = esi + 0x4;
                                    }
                                    sub_47a62a(ecx + edi + ebp, eax - edi - ebp, arg_0 + edi, esi[0x5] - edi);
                                    esp = (esp - 0x10) + 0x10 - 0xc;
                                    sub_4600b0(edi, ebp, arg_8, decomp_var_10, decomp_var_c, decomp_var_8);
                                    bool_4 = esi[0x6] < 0x10;
                                    esi[0x5] = ebx;
                                    if (!bool_4) {
                                            *(int8_t *)(esi[0x1] + ebx) = 0x0;
                                    }
                                    else {
                                            *(int8_t *)(esi + 0x4 + ebx) = 0x0;
                                            esp = esp + 0x4;
                                    }
                            }
                            else {
                                    esp = esp + 0x4;
                            }
                    }
            }
    }
    return;
}
