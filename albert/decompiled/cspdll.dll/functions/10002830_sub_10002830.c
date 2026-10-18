// sub_10002830 @ 0x10002830
// hopper name: sub_10002830
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10002830() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esi = arg_0;
    ebx = 0x0;
    esp = esp - 0xc;
    decomp_var_c = edi;
    eax = *esi;
    if (*(int16_t *)eax == 0x40) {
            edi = arg_4;
            *esi = eax + 0x2;
            ecx = eax[0x1];
            *esi = eax + 0x4;
            *(int16_t *)edi = HIBYTE(ecx);
            edi[0x1] = *(int16_t *)*esi;
            eax = *esi;
            *esi = eax + 0x2;
            ecx = eax[0x1];
            eax = eax + 0x4;
            *esi = eax;
            if (ecx == 0x40) {
                    ecx = *(int16_t *)eax;
                    *esi = eax + 0x2;
                    edi[0x2] = HIBYTE(ecx);
                    eax = *esi;
                    ecx = *(int16_t *)eax;
                    *esi = eax + 0x2;
                    edi[0x3] = 0x1 << ((ecx & 0xffff) >> 0x9) + 0x3;
                    eax = *esi;
                    if (*(int16_t *)eax == 0x140) {
                            *esi = eax + 0x2;
                            edi[0x6] = 0x0;
                            if (*(int16_t *)*esi == 0x449) {
                                    edi[0x2] = 0x1;
                                    eax = *esi;
                                    if (*(int16_t *)eax == 0x449) {
                                            eax = eax + 0x2;
                                            *esi = eax;
                                            if (*(int16_t *)eax == 0x40) {
                                                    *esi = eax + 0x2;
                                                    if (eax[0x1] != 0x140) {
                                                            while (true) {
                                                                    esp = (esp - 0xc) + 0xc;
                                                                    if (sub_10002990(esi, edi + edi[0x6] * 0x4 + 0xe, edi[0x1]) == 0x0) {
                                                                            temp_0 = 0x0;
                                                                            break;
                                                                    }
                                                                    edi[0x6] = edi[0x6] + 0x1;
                                                                    if (*(int16_t *)*esi != 0x140) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                            if (temp_0 != 0x0) {
                                                                    eax = *esi;
                                                                    if (*(int16_t *)eax == 0x140) {
                                                                            *esi = eax + 0x2;
                                                                            eax = *esi;
                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                    ebx = 0x1;
                                                                                    *esi = eax + 0x2;
                                                                            }
                                                                    }
                                                                    eax = ebx;
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            eax = *esi;
                                                            if (*(int16_t *)eax == 0x140) {
                                                                    *esi = eax + 0x2;
                                                                    eax = *esi;
                                                                    if (*(int16_t *)eax == 0x140) {
                                                                            ebx = 0x1;
                                                                            *esi = eax + 0x2;
                                                                    }
                                                            }
                                                            eax = ebx;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    edi[0x2] = 0x0;
                                    eax = *esi;
                                    if (*(int16_t *)eax == 0x140) {
                                            ebx = 0x1;
                                            *esi = eax + 0x2;
                                    }
                                    eax = ebx;
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
            else {
                    eax = edi[0x1];
                    edi[0x2] = HIBYTE(ecx);
                    if (eax == 0x42) {
                            edi[0x3] = 0x1;
                            edi[0x6] = 0x0;
                            if (*(int16_t *)*esi == 0x449) {
                                    edi[0x2] = 0x1;
                                    eax = *esi;
                                    if (*(int16_t *)eax == 0x449) {
                                            eax = eax + 0x2;
                                            *esi = eax;
                                            if (*(int16_t *)eax == 0x40) {
                                                    *esi = eax + 0x2;
                                                    if (eax[0x1] != 0x140) {
                                                            while (true) {
                                                                    esp = (esp - 0xc) + 0xc;
                                                                    if (sub_10002990(esi, edi + edi[0x6] * 0x4 + 0xe, edi[0x1]) == 0x0) {
                                                                            temp_0 = 0x0;
                                                                            break;
                                                                    }
                                                                    edi[0x6] = edi[0x6] + 0x1;
                                                                    if (*(int16_t *)*esi != 0x140) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                            if (temp_0 != 0x0) {
                                                                    eax = *esi;
                                                                    if (*(int16_t *)eax == 0x140) {
                                                                            *esi = eax + 0x2;
                                                                            eax = *esi;
                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                    ebx = 0x1;
                                                                                    *esi = eax + 0x2;
                                                                            }
                                                                    }
                                                                    eax = ebx;
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            eax = *esi;
                                                            if (*(int16_t *)eax == 0x140) {
                                                                    *esi = eax + 0x2;
                                                                    eax = *esi;
                                                                    if (*(int16_t *)eax == 0x140) {
                                                                            ebx = 0x1;
                                                                            *esi = eax + 0x2;
                                                                    }
                                                            }
                                                            eax = ebx;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    edi[0x2] = 0x0;
                                    eax = *esi;
                                    if (*(int16_t *)eax == 0x140) {
                                            ebx = 0x1;
                                            *esi = eax + 0x2;
                                    }
                                    eax = ebx;
                            }
                    }
                    else {
                            if (eax == 0x142) {
                                    edi[0x3] = 0x8000;
                                    edi[0x6] = 0x0;
                                    if (*(int16_t *)*esi == 0x449) {
                                            edi[0x2] = 0x1;
                                            eax = *esi;
                                            if (*(int16_t *)eax == 0x449) {
                                                    eax = eax + 0x2;
                                                    *esi = eax;
                                                    if (*(int16_t *)eax == 0x40) {
                                                            *esi = eax + 0x2;
                                                            if (eax[0x1] != 0x140) {
                                                                    while (true) {
                                                                            esp = (esp - 0xc) + 0xc;
                                                                            if (sub_10002990(esi, edi + edi[0x6] * 0x4 + 0xe, edi[0x1]) == 0x0) {
                                                                                    temp_0 = 0x0;
                                                                                    break;
                                                                            }
                                                                            edi[0x6] = edi[0x6] + 0x1;
                                                                            if (*(int16_t *)*esi != 0x140) {
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                                    if (temp_0 != 0x0) {
                                                                            eax = *esi;
                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                    *esi = eax + 0x2;
                                                                                    eax = *esi;
                                                                                    if (*(int16_t *)eax == 0x140) {
                                                                                            ebx = 0x1;
                                                                                            *esi = eax + 0x2;
                                                                                    }
                                                                            }
                                                                            eax = ebx;
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = *esi;
                                                                    if (*(int16_t *)eax == 0x140) {
                                                                            *esi = eax + 0x2;
                                                                            eax = *esi;
                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                    ebx = 0x1;
                                                                                    *esi = eax + 0x2;
                                                                            }
                                                                    }
                                                                    eax = ebx;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            edi[0x2] = 0x0;
                                            eax = *esi;
                                            if (*(int16_t *)eax == 0x140) {
                                                    ebx = 0x1;
                                                    *esi = eax + 0x2;
                                            }
                                            eax = ebx;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
