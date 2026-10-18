// sub_402650 @ 0x402650
// hopper name: sub_402650
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_402650() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    esp = esp - 0xc;
    decomp_var_c = esi;
    esi = ecx;
    ecx = esi[0x6];
    ebx = esi + 0x4;
    if (ecx >= 0x10) {
            eax = *ebx;
    }
    else {
            eax = ebx;
    }
    ebp = arg_0;
    if (ebp >= eax) {
            if (ecx >= 0x10) {
                    eax = *ebx;
            }
            else {
                    eax = ebx;
            }
            if (esi[0x5] + eax > ebp) {
                    if (ecx >= 0x10) {
                            ebx = *ebx;
                    }
                    sub_4024f0(esi, ebp - ebx, arg_4);
            }
            else {
                    esp = esp - 0x4;
                    decomp_var_10 = edi;
                    edi = arg_4;
                    if (edi > 0xfffffffe) {
                            sub_492f96();
                    }
                    eax = esi[0x6];
                    bool_19 = eax <= edi;
                    if (eax < edi) {
                            esp = esp - 0x8;
                            sub_401c20(edi, esi[0x5]);
                            if (!bool_19) {
                                    ecx = esi[0x6];
                                    if (ecx >= 0x10) {
                                            eax = *ebx;
                                    }
                                    else {
                                            eax = ebx;
                                    }
                                    sub_47a5af(eax, ecx, ebp, edi);
                                    esp = (esp - 0x10) + 0x10;
                                    bool_13 = esi[0x6] < 0x10;
                                    esi[0x5] = edi;
                                    if (!bool_13) {
                                            ebx = *ebx;
                                    }
                                    *(int8_t *)(ebx + edi) = 0x0;
                            }
                    }
                    else {
                            bool_20 = edi <= 0x0;
                            if (edi == 0x0) {
                                    esi[0x5] = edi;
                                    if (eax >= 0x10) {
                                            ebx = *ebx;
                                    }
                                    *(int8_t *)ebx = 0x0;
                            }
                            else {
                                    if (!bool_20) {
                                            ecx = esi[0x6];
                                            if (ecx >= 0x10) {
                                                    eax = *ebx;
                                            }
                                            else {
                                                    eax = ebx;
                                            }
                                            sub_47a5af(eax, ecx, ebp, edi);
                                            esp = (esp - 0x10) + 0x10;
                                            bool_14 = esi[0x6] < 0x10;
                                            esi[0x5] = edi;
                                            if (!bool_14) {
                                                    ebx = *ebx;
                                            }
                                            *(int8_t *)(ebx + edi) = 0x0;
                                    }
                            }
                    }
            }
    }
    else {
            esp = esp - 0x4;
            decomp_var_10 = edi;
            edi = arg_4;
            if (edi > 0xfffffffe) {
                    sub_492f96();
            }
            eax = esi[0x6];
            bool_11 = eax <= edi;
            if (eax < edi) {
                    esp = esp - 0x8;
                    sub_401c20(edi, esi[0x5]);
                    if (!bool_11) {
                            ecx = esi[0x6];
                            if (ecx >= 0x10) {
                                    eax = *ebx;
                            }
                            else {
                                    eax = ebx;
                            }
                            sub_47a5af(eax, ecx, ebp, edi);
                            esp = (esp - 0x10) + 0x10;
                            bool_10 = esi[0x6] < 0x10;
                            esi[0x5] = edi;
                            if (!bool_10) {
                                    ebx = *ebx;
                            }
                            *(int8_t *)(ebx + edi) = 0x0;
                    }
            }
            else {
                    bool_8 = edi <= 0x0;
                    if (edi == 0x0) {
                            esi[0x5] = edi;
                            if (eax >= 0x10) {
                                    ebx = *ebx;
                            }
                            *(int8_t *)ebx = 0x0;
                    }
                    else {
                            if (!bool_8) {
                                    ecx = esi[0x6];
                                    if (ecx >= 0x10) {
                                            eax = *ebx;
                                    }
                                    else {
                                            eax = ebx;
                                    }
                                    sub_47a5af(eax, ecx, ebp, edi);
                                    esp = (esp - 0x10) + 0x10;
                                    bool_6 = esi[0x6] < 0x10;
                                    esi[0x5] = edi;
                                    if (!bool_6) {
                                            ebx = *ebx;
                                    }
                                    *(int8_t *)(ebx + edi) = 0x0;
                            }
                    }
            }
    }
    return;
}
