// sub_4024f0 @ 0x4024f0
// hopper name: sub_4024f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4024f0() {
    decomp_var_4 = ebx;
    ebx = arg_0;
    decomp_var_8 = ebp;
    ebp = arg_4;
    decomp_var_c = esi;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    esi = ecx;
    if (ebx[0x5] < ebp) {
            sub_492fd5();
    }
    edi = ebx[0x5];
    eax = arg_8;
    edi = edi - ebp;
    if (eax < edi) {
            edi = eax;
    }
    if (esi == ebx) {
            sub_401a70();
            sub_401a70();
    }
    else {
            if (edi > 0xfffffffe) {
                    sub_492f96();
            }
            eax = esi[0x6];
            bool_7 = eax <= edi;
            if (eax < edi) {
                    esp = esp - 0x8;
                    sub_401c20(edi, esi[0x5]);
                    if (!bool_7) {
                            if (ebx[0x6] >= 0x10) {
                                    edx = ebx[0x1];
                            }
                            else {
                                    edx = ebx + 0x4;
                            }
                            ecx = esi[0x6];
                            ebx = esi + 0x4;
                            if (ecx >= 0x10) {
                                    eax = *ebx;
                            }
                            else {
                                    eax = ebx;
                            }
                            sub_47a5af(eax, ecx, edx + ebp, edi);
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
                                    if (ebx[0x6] >= 0x10) {
                                            edx = ebx[0x1];
                                    }
                                    else {
                                            edx = ebx + 0x4;
                                    }
                                    ecx = esi[0x6];
                                    ebx = esi + 0x4;
                                    if (ecx >= 0x10) {
                                            eax = *ebx;
                                    }
                                    else {
                                            eax = ebx;
                                    }
                                    sub_47a5af(eax, ecx, edx + ebp, edi);
                                    esp = (esp - 0x10) + 0x10;
                                    bool_9 = esi[0x6] < 0x10;
                                    esi[0x5] = edi;
                                    if (!bool_9) {
                                            ebx = *ebx;
                                    }
                                    *(int8_t *)(ebx + edi) = 0x0;
                            }
                    }
            }
    }
    return;
}
