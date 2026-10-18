// sub_10002f50 @ 0x10002f50
// hopper name: sub_10002f50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10002f50() {
    decomp_var_30 = ebx;
    ecx = arg_4;
    ebx = arg_c;
    ebp = arg_8;
    esp = esp - 0x3c;
    edi = arg_10;
    eax = *(int8_t *)edi;
    var_28 = 0x1;
    edx = HIBYTE(ecx);
    var_29 = ecx;
    if ((eax & 0x1) != 0x0) {
            if (edx != 0x4b) {
                    *(int8_t *)edi = eax & 0xfe;
                    if (*ebx >= 0x2) {
                            *(int8_t *)*ebp = 0x27;
                            *ebp = *ebp + 0x1;
                            *ebx = *ebx - 0x1;
                            *(int8_t *)*ebp = 0x20;
                            *ebp = *ebp + 0x1;
                            ecx = arg_4;
                            *ebx = *ebx - 0x1;
                            if ((edx & 0xc0) == 0x0) {
                                    eax = _itoa(ecx & 0x3fff, &var_24, 0xa);
                                    arg_14 = &var_18;
                                    ecx = ecx | 0xffffffff;
                                    esp = (esp - 0xc) + 0xc;
                                    asm { repne scasb al, byte [edi] };
                                    ecx = !ecx - 0x1;
                                    arg_18 = ecx;
                            }
                            else {
                                    if (edx == 0x4b) {
                                            eax = *(int8_t *)edi;
                                            if ((eax & 0x1) == 0x0) {
                                                    ecx = var_29;
                                                    *(int8_t *)edi = eax | 0x1;
                                                    arg_10 = 0x27;
                                            }
                                            else {
                                                    arg_10 = var_29;
                                            }
                                            ecx = ecx | 0xffffffff;
                                            eax = 0x0;
                                            asm { repne scasb al, byte [edi] };
                                            ecx = !ecx - 0x1;
                                            var_28 = eax;
                                    }
                                    else {
                                            edx = arg_0[0x1];
                                            sub_100066d0(edx, &arg_4, 0x2, &arg_8, &arg_c);
                                            ecx = arg_c;
                                            esp = (esp - 0x14) + 0x14;
                                    }
                            }
                            eax = *ebx;
                            bool_18 = true;
                            bool_17 = true;
                            if (ecx + 0x1 <= eax) {
                                    *ebx = eax - ecx;
                                    edi = *ebp;
                                    *edi = *arg_14;
                                    asm { rep movsb  byte [edi], byte [esi] };
                                    edx = *ebp;
                                    *ebp = edx + arg_18;
                                    eax = edx + arg_18;
                                    if (var_1C != 0x0) {
                                            *(int8_t *)eax = 0x20;
                                            *ebp = *ebp + 0x1;
                                            *ebx = *ebx - 0x1;
                                    }
                                    eax = 0x1;
                            }
                            else {
                                    eax = 0x1;
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
            else {
                    if ((edx & 0xc0) == 0x0) {
                            eax = _itoa(ecx & 0x3fff, &var_24, 0xa);
                            arg_14 = &var_18;
                            ecx = ecx | 0xffffffff;
                            esp = (esp - 0xc) + 0xc;
                            asm { repne scasb al, byte [edi] };
                            ecx = !ecx - 0x1;
                            arg_18 = ecx;
                    }
                    else {
                            if (edx == 0x4b) {
                                    eax = *(int8_t *)edi;
                                    if ((eax & 0x1) == 0x0) {
                                            ecx = var_29;
                                            *(int8_t *)edi = eax | 0x1;
                                            arg_10 = 0x27;
                                    }
                                    else {
                                            arg_10 = var_29;
                                    }
                                    ecx = ecx | 0xffffffff;
                                    eax = 0x0;
                                    asm { repne scasb al, byte [edi] };
                                    ecx = !ecx - 0x1;
                                    var_28 = eax;
                            }
                            else {
                                    sub_100066d0(arg_0[0x1], &arg_4, 0x2, &arg_8, &arg_c);
                                    ecx = arg_c;
                                    esp = (esp - 0x14) + 0x14;
                            }
                    }
                    eax = *ebx;
                    bool_10 = true;
                    bool_9 = true;
                    if (ecx + 0x1 <= eax) {
                            *ebx = eax - ecx;
                            edi = *ebp;
                            *edi = *arg_14;
                            asm { rep movsb  byte [edi], byte [esi] };
                            edx = *ebp;
                            *ebp = edx + arg_18;
                            eax = edx + arg_18;
                            if (var_1C != 0x0) {
                                    *(int8_t *)eax = 0x20;
                                    *ebp = *ebp + 0x1;
                                    *ebx = *ebx - 0x1;
                            }
                            eax = 0x1;
                    }
                    else {
                            eax = 0x0;
                    }
            }
    }
    else {
            if ((edx & 0xc0) == 0x0) {
                    eax = _itoa(ecx & 0x3fff, &var_24, 0xa);
                    arg_14 = &var_18;
                    ecx = ecx | 0xffffffff;
                    esp = (esp - 0xc) + 0xc;
                    asm { repne scasb al, byte [edi] };
                    ecx = !ecx - 0x1;
                    arg_18 = ecx;
            }
            else {
                    if (edx == 0x4b) {
                            eax = *(int8_t *)edi;
                            if ((eax & 0x1) == 0x0) {
                                    ecx = var_29;
                                    *(int8_t *)edi = eax | 0x1;
                                    arg_10 = 0x27;
                            }
                            else {
                                    arg_10 = var_29;
                            }
                            ecx = ecx | 0xffffffff;
                            eax = 0x0;
                            asm { repne scasb al, byte [edi] };
                            ecx = !ecx - 0x1;
                            var_28 = eax;
                    }
                    else {
                            edx = arg_0[0x1];
                            sub_100066d0(edx, &arg_4, 0x2, &arg_8, &arg_c);
                            ecx = arg_c;
                            esp = (esp - 0x14) + 0x14;
                    }
            }
            eax = *ebx;
            bool_7 = true;
            bool_6 = true;
            if (ecx + 0x1 <= eax) {
                    *ebx = eax - ecx;
                    edi = *ebp;
                    *edi = *arg_14;
                    asm { rep movsb  byte [edi], byte [esi] };
                    edx = *ebp;
                    *ebp = edx + arg_18;
                    eax = edx + arg_18;
                    if (var_1C != 0x0) {
                            *(int8_t *)eax = 0x20;
                            *ebp = *ebp + 0x1;
                            *ebx = *ebx - 0x1;
                    }
                    eax = 0x1;
            }
            else {
                    eax = 0x0;
            }
    }
    return eax;
}
