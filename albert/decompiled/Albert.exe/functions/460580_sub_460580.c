// sub_460580 @ 0x460580
// hopper name: sub_460580
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_460580() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esi = ecx;
    edx = esi[0x6];
    esp = esp - 0xc;
    decomp_var_c = edi;
    ebx = esi + 0x4;
    if (edx >= 0x10) {
            ecx = *ebx;
    }
    else {
            ecx = ebx;
    }
    eax = arg_0;
    if (eax >= ecx) {
            if (edx >= 0x10) {
                    ecx = *ebx;
            }
            else {
                    ecx = ebx;
            }
            if (esi[0x5] + ecx > eax) {
                    if (edx >= 0x10) {
                            ebx = *ebx;
                    }
                    eax = sub_460480();
            }
            else {
                    eax = esi[0x5];
                    esp = esp - 0x4;
                    decomp_var_10 = ebp;
                    ebp = arg_4;
                    if ((edx | 0xffffffff) - eax <= ebp) {
                            sub_492f96();
                    }
                    if (eax + ebp < eax) {
                            sub_492f96();
                    }
                    if (ebp > 0x0) {
                            edi = esi[0x5];
                            edi = edi + ebp;
                            if (edi > 0xfffffffe) {
                                    sub_492f96();
                            }
                            eax = esi[0x6];
                            bool_19 = eax <= edi;
                            if (eax < edi) {
                                    esp = esp - 0x8;
                                    sub_401c20(edi, esi[0x5]);
                                    if (!bool_19) {
                                            eax = esi[0x6];
                                            if (eax >= 0x10) {
                                                    edx = *ebx;
                                            }
                                            else {
                                                    edx = ebx;
                                            }
                                            ecx = esi[0x5];
                                            sub_47a5af(ecx + edx, eax - ecx, arg_0, ebp);
                                            esp = (esp - 0x10) + 0x10;
                                            bool_26 = esi[0x6] < 0x10;
                                            esi[0x5] = edi;
                                            if (!bool_26) {
                                                    ebx = *ebx;
                                            }
                                            *(int8_t *)(ebx + edi) = 0x0;
                                    }
                                    eax = esi;
                            }
                            else {
                                    bool_21 = edi <= 0x0;
                                    if (edi == 0x0) {
                                            esi[0x5] = edi;
                                            if (eax >= 0x10) {
                                                    ebx = *ebx;
                                            }
                                            eax = esi;
                                            *(int8_t *)ebx = 0x0;
                                    }
                                    else {
                                            if (!bool_21) {
                                                    eax = esi[0x6];
                                                    if (eax >= 0x10) {
                                                            edx = *ebx;
                                                    }
                                                    else {
                                                            edx = ebx;
                                                    }
                                                    ecx = esi[0x5];
                                                    sub_47a5af(ecx + edx, eax - ecx, arg_0, ebp);
                                                    esp = (esp - 0x10) + 0x10;
                                                    bool_30 = esi[0x6] < 0x10;
                                                    esi[0x5] = edi;
                                                    if (!bool_30) {
                                                            ebx = *ebx;
                                                    }
                                                    *(int8_t *)(ebx + edi) = 0x0;
                                            }
                                            eax = esi;
                                    }
                            }
                    }
                    else {
                            eax = esi;
                    }
            }
    }
    else {
            eax = esi[0x5];
            esp = esp - 0x4;
            decomp_var_10 = ebp;
            ebp = arg_4;
            if ((edx | 0xffffffff) - eax <= ebp) {
                    sub_492f96();
            }
            if (eax + ebp < eax) {
                    sub_492f96();
            }
            if (ebp > 0x0) {
                    edi = esi[0x5];
                    edi = edi + ebp;
                    if (edi > 0xfffffffe) {
                            sub_492f96();
                    }
                    eax = esi[0x6];
                    bool_13 = eax <= edi;
                    if (eax < edi) {
                            esp = esp - 0x8;
                            sub_401c20(edi, esi[0x5]);
                            if (!bool_13) {
                                    eax = esi[0x6];
                                    if (eax >= 0x10) {
                                            edx = *ebx;
                                    }
                                    else {
                                            edx = ebx;
                                    }
                                    ecx = esi[0x5];
                                    sub_47a5af(ecx + edx, eax - ecx, arg_0, ebp);
                                    esp = (esp - 0x10) + 0x10;
                                    bool_10 = esi[0x6] < 0x10;
                                    esi[0x5] = edi;
                                    if (!bool_10) {
                                            ebx = *ebx;
                                    }
                                    *(int8_t *)(ebx + edi) = 0x0;
                            }
                            eax = esi;
                    }
                    else {
                            bool_14 = edi <= 0x0;
                            if (edi == 0x0) {
                                    esi[0x5] = edi;
                                    if (eax >= 0x10) {
                                            ebx = *ebx;
                                    }
                                    eax = esi;
                                    *(int8_t *)ebx = 0x0;
                            }
                            else {
                                    if (!bool_14) {
                                            eax = esi[0x6];
                                            if (eax >= 0x10) {
                                                    edx = *ebx;
                                            }
                                            else {
                                                    edx = ebx;
                                            }
                                            ecx = esi[0x5];
                                            sub_47a5af(ecx + edx, eax - ecx, arg_0, ebp);
                                            esp = (esp - 0x10) + 0x10;
                                            bool_5 = esi[0x6] < 0x10;
                                            esi[0x5] = edi;
                                            if (!bool_5) {
                                                    ebx = *ebx;
                                            }
                                            *(int8_t *)(ebx + edi) = 0x0;
                                    }
                                    eax = esi;
                            }
                    }
            }
            else {
                    eax = esi;
            }
    }
    return eax;
}
