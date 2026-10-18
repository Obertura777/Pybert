// exp_vos_trace_initialise @ 0x100068f0
// hopper name: exp_vos_trace_initialise
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_trace_initialise() {
    ebp = arg_0;
    esp = esp - 0x4;
    decomp_var_8 = edi;
    ecx = ecx | 0xffffffff;
    asm { repne scasb al, byte [edi] };
    if (!ecx <= 0x7d) {
            eax = sub_10006830();
            *dword_1000ab2c = eax;
            if (eax != 0x0) {
                    esp = esp - 0xc;
                    *(*dword_1000ab2c + 0x10c) = CreateMutexA(0x0, 0x0, 0x0);
                    if (*(*dword_1000ab2c + 0x10c) == 0x0) {
                            esp = esp - 0x4;
                            decomp_var_c = *dword_1000ab2c;
                            free(decomp_var_c);
                            esp = esp + 0x4;
                            *dword_1000ab2c = 0x0;
                            eax = 0x0 != 0x0 ? 0x1 : 0x0;
                    }
                    else {
                            decomp_var_c = 0x1000aaec;
                            esp = (esp - 0x8) + 0x8;
                            **dword_1000ab2c = fopen(ebp, 0x1000aaec);
                            if (**dword_1000ab2c == 0x0) {
                                    CloseHandle(*(*dword_1000ab2c + 0x10c));
                                    esp = esp - 0x8;
                                    decomp_var_4 = *dword_1000ab2c;
                                    free(decomp_var_c);
                                    esp = esp + 0x4;
                                    *dword_1000ab2c = 0x0;
                                    eax = 0x0 != 0x0 ? 0x1 : 0x0;
                            }
                            else {
                                    *(*dword_1000ab2c + 0x108) = arg_c & 0xff;
                                    *(*dword_1000ab2c + 0x104) = arg_10;
                                    ecx = *dword_1000ab2c;
                                    *dword_1000ab30 = arg_14;
                                    *dword_1000ab34 = arg_18;
                                    strncpy(ecx + 0x4, ebp, 0x7c);
                                    esp = esp - 0x1c;
                                    strncpy(*dword_1000ab2c + 0x80, ebp, 0x7c);
                                    ebp = *dword_1000ab2c;
                                    ecx = ecx | 0xffffffff;
                                    edx = &arg_7c;
                                    asm { repne scasb al, byte [edi] };
                                    decomp_var_4 = (0x80 - !ecx) + 0x1;
                                    ecx = !ecx - 0x1 | 0xffffffff;
                                    esp = esp - 0x8;
                                    decomp_var_8 = 0x1000aaf0;
                                    asm { repne scasb al, byte [edi] };
                                    strncpy((!ecx - 0x1) + ebp + 0x80, decomp_var_8, decomp_var_4);
                                    eax = 0x114;
                                    ecx = 0x3;
                                    esp = (esp - 0x4) + 0x28;
                                    do {
                                            eax = eax + 0xc;
                                            ecx = ecx - 0x1;
                                            *(eax + (*dword_1000ab2c - 0xc)) = 0x0;
                                    } while (ecx != 0x0);
                                    *(*dword_1000ab2c + 0x138) = 0x0;
                                    *(int8_t *)(*dword_1000ab2c + 0x13c) = 0x0;
                                    *(int8_t *)(*dword_1000ab2c + 0x110) = 0x0;
                                    eax = *dword_1000ab2c;
                                    eax = eax != 0x0 ? 0x1 : 0x0;
                            }
                    }
            }
            else {
                    eax = eax != 0x0 ? 0x1 : 0x0;
            }
    }
    else {
            *dword_1000ab2c = 0x0;
            eax = 0x0 != 0x0 ? 0x1 : 0x0;
    }
    return eax;
}
