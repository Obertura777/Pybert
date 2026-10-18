// sub_48235f @ 0x48235f
// hopper name: sub_48235f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48235f() {
    ebp = &var_78;
    arg_6c = *dword_4c8db8 ^ ebp;
    decomp_var_1cc = ebx;
    decomp_var_1d0 = edi;
    eax = sub_480086();
    decomp_var_1d8 = &decomp_var_124;
    edi = eax + 0x1d0;
    esp = (esp - 0x1e4) + 0x18;
    if (sub_48218b() != 0x0) {
            ebx = (arg_78 << 0x4) + esi;
            decomp_var_1d4 = ebx[0x12];
            eax = sub_47fd80(&decomp_var_14, decomp_var_1d4);
            esp = (esp - 0x8) + 0x8;
            if (eax != 0x0) {
                    eax = sub_47d630(&decomp_var_14);
                    decomp_var_118 = eax + 0x5;
                    eax = sub_481280(eax + 0x5);
                    esp = (esp - 0x8) + 0x8;
                    decomp_var_11c = eax;
                    if (eax != 0x0) {
                            decomp_var_130 = ebx[0x12];
                            decomp_var_120 = esi + arg_78 * 0x4 + 0xc;
                            decomp_var_134 = *(esi + arg_78 * 0x4 + 0xc);
                            decomp_var_128 = (arg_78 + 0x6) * 0x6 + esi;
                            sub_47c000(&decomp_var_150, (arg_78 + 0x6) * 0x6 + esi, 0x6);
                            decomp_var_140 = esi[0x1];
                            eax = sub_47db5e(decomp_var_11c + 0x4, decomp_var_118 - 0x4, &decomp_var_14);
                            esp = (esp - 0x18) + 0x18;
                            if (eax != 0x0) {
                                    sub_47a828();
                                    esp = (esp - 0x14) + 0x14;
                            }
                            ebx[0x12] = decomp_var_11c + 0x4;
                            *decomp_var_120 = decomp_var_13c & 0xffff;
                            sub_47c000(decomp_var_128, &decomp_var_13c, 0x6);
                            esp = (esp - 0xc) + 0xc;
                            if (arg_78 == 0x2) {
                                    decomp_var_118 = decomp_var_118 & 0x0;
                                    esi[0x1] = decomp_var_124;
                                    eax = edi[0x9];
                                    ecx = edi[0x8];
                                    decomp_var_128 = eax;
                                    eax = edi;
                                    while (true) {
                                            if (esi[0x1] == *eax) {
                                                    eax = decomp_var_118;
                                                    if (eax != 0x0) {
                                                            *edi = *(edi + eax * 0x8);
                                                            edi[0x1] = *(edi + eax * 0x8 + 0x4);
                                                            *(edi + eax * 0x8) = ecx;
                                                            *(edi + eax * 0x8 + 0x4) = decomp_var_128;
                                                            temp_0 = 0x1;
                                                    }
                                                    else {
                                                            temp_0 = 0x0;
                                                    }
                                                    break;
                                            }
                                            edx = *eax;
                                            decomp_var_118 = decomp_var_118 + 0x1;
                                            *eax = ecx;
                                            decomp_var_148 = edx;
                                            edx = eax[0x1];
                                            eax[0x1] = decomp_var_128;
                                            ecx = decomp_var_148;
                                            eax = eax + 0x8;
                                            decomp_var_128 = edx;
                                            if (decomp_var_118 < 0x5) {
                                                    continue;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    if (decomp_var_118 == 0x5) {
                                            eax = sub_48ac1f(0x0, 0x1, 0x4b3ac8, 0x7f, &decomp_var_114, esi[0x1], esi[0x5], 0x1);
                                            esp = (esp - 0x20) + 0x20;
                                            if (eax != 0x0) {
                                                    eax = 0x0;
                                                    do {
                                                            *(int16_t *)(ebp + (eax * 0x2 - 0x114)) = *(int16_t *)(ebp + (eax * 0x2 - 0x114)) & 0x1ff;
                                                            eax = eax + 0x1;
                                                    } while (eax < 0x7f);
                                                    eax = sub_47dc9a(&decomp_var_114, *dword_4c9510, 0xfe);
                                                    esp = (esp - 0xc) + 0xc;
                                                    edi[0x1] = (--eax - --eax + CARRY(EFLAGS(cf))) + 0x1;
                                            }
                                            else {
                                                    edi[0x1] = edi[0x1] & 0x0;
                                            }
                                            *edi = esi[0x1];
                                    }
                                    esi[0x2a] = edi[0x1];
                            }
                            if (arg_78 == 0x1) {
                                    esi[0x2] = decomp_var_124;
                            }
                            esp = (esp - 0x4) + 0x4;
                            if ((*(arg_78 * 0xc + 0x4b3a88))(esi) != 0x0) {
                                    decomp_var_1d0 = decomp_var_11c;
                                    ebx[0x12] = decomp_var_130;
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                                    *decomp_var_120 = decomp_var_134;
                                    esi[0x1] = decomp_var_140;
                            }
                            else {
                                    if (decomp_var_130 != 0x4c9518) {
                                            edi = (arg_78 + 0x5 << 0x4) + esi;
                                            esp = esp - 0x4;
                                            decomp_var_1d0 = *edi;
                                            if (InterlockedDecrement(decomp_var_1d0) == 0x0) {
                                                    decomp_var_1d0 = *edi;
                                                    sub_47c8f9();
                                                    sub_47c8f9();
                                                    ebx[0x13] = ebx[0x13] & 0x0;
                                                    esp = (esp - 0x8) + 0x8;
                                            }
                                    }
                                    *decomp_var_11c = 0x1;
                                    *((arg_78 + 0x5 << 0x4) + esi) = decomp_var_11c;
                            }
                    }
            }
    }
    eax = sub_47ad69();
    return eax;
}
