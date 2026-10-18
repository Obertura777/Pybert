// sub_460480 @ 0x460480
// hopper name: sub_460480
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_460480() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    edi = arg_4;
    esi = ecx;
    if (arg_10 < edi) {
            sub_492fd5();
    }
    ebx = arg_8;
    eax = arg_10 - edi;
    if (eax < ebx) {
            ebx = eax;
    }
    eax = esi[0x5];
    if ((ecx | 0xffffffff) - eax <= ebx) {
            sub_492f96();
    }
    if (eax + ebx < eax) {
            sub_492f96();
    }
    if (ebx > 0x0) {
            edi = esi[0x5];
            edi = edi + ebx;
            if (edi > 0xfffffffe) {
                    sub_492f96();
            }
            eax = esi[0x6];
            bool_15 = eax <= edi;
            if (eax < edi) {
                    esp = esp - 0x8;
                    sub_401c20(edi, esi[0x5]);
                    if (!bool_15) {
                            if (arg_14 >= 0x10) {
                                    ebp = arg_0;
                            }
                            else {
                                    ebp = &arg_0;
                            }
                            eax = esi[0x6];
                            if (eax >= 0x10) {
                                    edx = esi[0x1];
                            }
                            else {
                                    edx = esi + 0x4;
                            }
                            ecx = esi[0x5];
                            sub_47a5af(ecx + edx, eax - ecx, ebp + arg_4, ebx);
                            esp = (esp - 0x10) + 0x10;
                            bool_13 = esi[0x6] < 0x10;
                            esi[0x5] = edi;
                            if (!bool_13) {
                                    *(int8_t *)(esi[0x1] + edi) = 0x0;
                            }
                            else {
                                    *(int8_t *)(esi + 0x4 + edi) = 0x0;
                            }
                    }
            }
            else {
                    bool_10 = edi <= 0x0;
                    if (edi == 0x0) {
                            esi[0x5] = edi;
                            if (eax >= 0x10) {
                                    *(int8_t *)esi[0x1] = 0x0;
                            }
                            else {
                                    esi[0x4] = 0x0;
                            }
                    }
                    else {
                            if (!bool_10) {
                                    if (arg_14 >= 0x10) {
                                            ebp = arg_0;
                                    }
                                    else {
                                            ebp = &arg_0;
                                    }
                                    eax = esi[0x6];
                                    if (eax >= 0x10) {
                                            edx = esi[0x1];
                                    }
                                    else {
                                            edx = esi + 0x4;
                                    }
                                    ecx = esi[0x5];
                                    sub_47a5af(ecx + edx, eax - ecx, ebp + arg_4, ebx);
                                    esp = (esp - 0x10) + 0x10;
                                    bool_6 = esi[0x6] < 0x10;
                                    esi[0x5] = edi;
                                    if (!bool_6) {
                                            *(int8_t *)(esi[0x1] + edi) = 0x0;
                                    }
                                    else {
                                            *(int8_t *)(esi + 0x4 + edi) = 0x0;
                                    }
                            }
                    }
            }
    }
    return;
}
