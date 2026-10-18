// sub_100025b0 @ 0x100025b0
// hopper name: sub_100025b0
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100025b0() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esi = arg_0;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = arg_c;
    ebx = 0x0;
    *(int16_t *)edi = 0x1a48;
    edi[0x1] = 0x100;
    edi[0x4] = arg_8;
    eax = *esi;
    if (*(int16_t *)eax == 0x1a48) {
            eax = eax + 0x2;
            *esi = eax;
            if (*(int16_t *)eax == 0x40) {
                    eax = eax + 0x2;
                    *esi = eax;
                    ecx = eax + 0x2;
                    if (eax[0x1] != 0x8243) {
                            esp = (esp - 0x8) + 0x8;
                            if (sub_10002830(esi, edi + 0x8) != 0x0) {
                                    edi[0x34] = *(int16_t *)*esi;
                                    *esi = *esi + 0x2;
                                    eax = edi[0x34];
                                    bool_43 = eax == 0x2343;
                                    if (eax <= 0x2343) {
                                            if (!bool_43) {
                                                    if (eax != 0x2043) {
                                                            if (eax == 0x2143) {
                                                                    esp = (esp - 0x8) + 0x8;
                                                                    if (sub_10002830(esi, edi + 0x70) != 0x0) {
                                                                            eax = *esi;
                                                                            if (*(int16_t *)eax == 0x2043) {
                                                                                    *esi = eax + 0x2;
                                                                                    decomp_var_10 = edi[0x39];
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_14 = edi + 0x6a;
                                                                                    esp = (esp - 0x4) + 0xc;
                                                                                    if (sub_10002990(esi, decomp_var_14, decomp_var_10) != 0x0) {
                                                                                            eax = *esi;
                                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                                    eax = eax + 0x2;
                                                                                                    *esi = eax;
                                                                                                    if (*(int16_t *)eax == 0x40) {
                                                                                                            *esi = eax + 0x2;
                                                                                                            edi[0x7e] = eax[0x1];
                                                                                                            edx = *esi;
                                                                                                            eax = edx + 0x2;
                                                                                                            *esi = edx + 0x2;
                                                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                                                    ebx = 0x1;
                                                                                                                    *esi = eax + 0x2;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            eax = ebx;
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
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = *esi;
                                                                    if (*(int16_t *)eax == 0x140) {
                                                                            eax = eax + 0x2;
                                                                            *esi = eax;
                                                                            if (*(int16_t *)eax == 0x40) {
                                                                                    *esi = eax + 0x2;
                                                                                    edi[0x7e] = eax[0x1];
                                                                                    edx = *esi;
                                                                                    eax = edx + 0x2;
                                                                                    *esi = edx + 0x2;
                                                                                    if (*(int16_t *)eax == 0x140) {
                                                                                            ebx = 0x1;
                                                                                            *esi = eax + 0x2;
                                                                                    }
                                                                            }
                                                                    }
                                                                    eax = ebx;
                                                            }
                                                    }
                                                    else {
                                                            esp = (esp - 0xc) + 0xc;
                                                            if (sub_10002990(esi, edi + 0x6a, 0x42) != 0x0) {
                                                                    eax = *esi;
                                                                    if (*(int16_t *)eax == 0x2543) {
                                                                            eax = eax + 0x2;
                                                                            *esi = eax;
                                                                            if (*(int16_t *)eax == 0x40) {
                                                                                    *esi = eax + 0x2;
                                                                                    edi[0x68] = 0x0;
                                                                                    eax = *esi;
                                                                                    ecx = *(int16_t *)eax;
                                                                                    if (ecx != 0x140) {
                                                                                            do {
                                                                                                    *esi = eax + 0x2;
                                                                                                    *(int16_t *)(edi + edi[0x68] * 0x2 + 0xd2) = ecx;
                                                                                                    edi[0x68] = edi[0x68] + 0x1;
                                                                                                    eax = *esi;
                                                                                                    ecx = *(int16_t *)eax;
                                                                                            } while (ecx != 0x140);
                                                                                    }
                                                                                    eax = *esi;
                                                                                    if (*(int16_t *)eax == 0x140) {
                                                                                            *esi = eax + 0x2;
                                                                                            eax = *esi;
                                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                                    eax = eax + 0x2;
                                                                                                    *esi = eax;
                                                                                                    if (*(int16_t *)eax == 0x40) {
                                                                                                            *esi = eax + 0x2;
                                                                                                            edi[0x7e] = eax[0x1];
                                                                                                            edx = *esi;
                                                                                                            eax = edx + 0x2;
                                                                                                            *esi = edx + 0x2;
                                                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                                                    *esi = eax + 0x2;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            eax = 0x1;
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
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                            }
                                            else {
                                                    decomp_var_10 = edi[0x5];
                                                    esp = esp - 0x8;
                                                    decomp_var_14 = edi + 0x6a;
                                                    esp = (esp - 0x4) + 0xc;
                                                    if (sub_10002990(esi, decomp_var_14, decomp_var_10) != 0x0) {
                                                            eax = *esi;
                                                            if (*(int16_t *)eax == 0x140) {
                                                                    eax = eax + 0x2;
                                                                    *esi = eax;
                                                                    if (*(int16_t *)eax == 0x40) {
                                                                            *esi = eax + 0x2;
                                                                            edi[0x7e] = eax[0x1];
                                                                            edx = *esi;
                                                                            eax = edx + 0x2;
                                                                            *esi = edx + 0x2;
                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                    ebx = 0x1;
                                                                                    *esi = eax + 0x2;
                                                                            }
                                                                    }
                                                            }
                                                            eax = ebx;
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                    }
                                    else {
                                            if (eax != 0x2443) {
                                                    if (eax == 0x4143) {
                                                            decomp_var_10 = edi[0x5];
                                                            esp = esp - 0x8;
                                                            decomp_var_14 = edi + 0x6a;
                                                            esp = (esp - 0x4) + 0xc;
                                                            if (sub_10002990(esi, decomp_var_14, decomp_var_10) != 0x0) {
                                                                    eax = *esi;
                                                                    if (*(int16_t *)eax == 0x140) {
                                                                            eax = eax + 0x2;
                                                                            *esi = eax;
                                                                            if (*(int16_t *)eax == 0x40) {
                                                                                    *esi = eax + 0x2;
                                                                                    edi[0x7e] = eax[0x1];
                                                                                    edx = *esi;
                                                                                    eax = edx + 0x2;
                                                                                    *esi = edx + 0x2;
                                                                                    if (*(int16_t *)eax == 0x140) {
                                                                                            ebx = 0x1;
                                                                                            *esi = eax + 0x2;
                                                                                    }
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
                                                                    eax = eax + 0x2;
                                                                    *esi = eax;
                                                                    if (*(int16_t *)eax == 0x40) {
                                                                            *esi = eax + 0x2;
                                                                            edi[0x7e] = eax[0x1];
                                                                            edx = *esi;
                                                                            eax = edx + 0x2;
                                                                            *esi = edx + 0x2;
                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                    ebx = 0x1;
                                                                                    *esi = eax + 0x2;
                                                                            }
                                                                    }
                                                            }
                                                            eax = ebx;
                                                    }
                                            }
                                            else {
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (sub_10002830(esi, edi + 0x70) != 0x0) {
                                                            eax = *esi;
                                                            if (*(int16_t *)eax == 0x2343) {
                                                                    *esi = eax + 0x2;
                                                                    esp = (esp - 0xc) + 0xc;
                                                                    if (sub_10002990(esi, edi + 0x6a, edi[0x39]) != 0x0) {
                                                                            eax = *esi;
                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                    eax = eax + 0x2;
                                                                                    *esi = eax;
                                                                                    if (*(int16_t *)eax == 0x40) {
                                                                                            *esi = eax + 0x2;
                                                                                            edi[0x7e] = eax[0x1];
                                                                                            edx = *esi;
                                                                                            eax = edx + 0x2;
                                                                                            *esi = edx + 0x2;
                                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                                    ebx = 0x1;
                                                                                                    *esi = eax + 0x2;
                                                                                            }
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
                                                                            eax = eax + 0x2;
                                                                            *esi = eax;
                                                                            if (*(int16_t *)eax == 0x40) {
                                                                                    *esi = eax + 0x2;
                                                                                    edi[0x7e] = eax[0x1];
                                                                                    edx = *esi;
                                                                                    eax = edx + 0x2;
                                                                                    *esi = edx + 0x2;
                                                                                    if (*(int16_t *)eax == 0x140) {
                                                                                            ebx = 0x1;
                                                                                            *esi = eax + 0x2;
                                                                                    }
                                                                            }
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
                    }
                    else {
                            edx = HIBYTE(*(int16_t *)eax);
                            *esi = ecx;
                            edi[0x4] = edx;
                            edi[0x34] = *(int16_t *)*esi;
                            *esi = *esi + 0x2;
                            eax = edi[0x34];
                            bool_77 = eax == 0x2343;
                            if (eax <= 0x2343) {
                                    if (!bool_77) {
                                            if (eax != 0x2043) {
                                                    if (eax == 0x2143) {
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (sub_10002830(esi, edi + 0x70) != 0x0) {
                                                                    eax = *esi;
                                                                    if (*(int16_t *)eax == 0x2043) {
                                                                            *esi = eax + 0x2;
                                                                            decomp_var_10 = edi[0x39];
                                                                            esp = esp - 0x8;
                                                                            decomp_var_14 = edi + 0x6a;
                                                                            esp = (esp - 0x4) + 0xc;
                                                                            if (sub_10002990(esi, decomp_var_14, decomp_var_10) != 0x0) {
                                                                                    eax = *esi;
                                                                                    if (*(int16_t *)eax == 0x140) {
                                                                                            eax = eax + 0x2;
                                                                                            *esi = eax;
                                                                                            if (*(int16_t *)eax == 0x40) {
                                                                                                    *esi = eax + 0x2;
                                                                                                    edi[0x7e] = eax[0x1];
                                                                                                    edx = *esi;
                                                                                                    eax = edx + 0x2;
                                                                                                    *esi = edx + 0x2;
                                                                                                    if (*(int16_t *)eax == 0x140) {
                                                                                                            ebx = 0x1;
                                                                                                            *esi = eax + 0x2;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    eax = ebx;
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
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            eax = *esi;
                                                            if (*(int16_t *)eax == 0x140) {
                                                                    eax = eax + 0x2;
                                                                    *esi = eax;
                                                                    if (*(int16_t *)eax == 0x40) {
                                                                            *esi = eax + 0x2;
                                                                            edi[0x7e] = eax[0x1];
                                                                            edx = *esi;
                                                                            eax = edx + 0x2;
                                                                            *esi = edx + 0x2;
                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                    ebx = 0x1;
                                                                                    *esi = eax + 0x2;
                                                                            }
                                                                    }
                                                            }
                                                            eax = ebx;
                                                    }
                                            }
                                            else {
                                                    esp = (esp - 0xc) + 0xc;
                                                    if (sub_10002990(esi, edi + 0x6a, 0x42) != 0x0) {
                                                            eax = *esi;
                                                            if (*(int16_t *)eax == 0x2543) {
                                                                    eax = eax + 0x2;
                                                                    *esi = eax;
                                                                    if (*(int16_t *)eax == 0x40) {
                                                                            *esi = eax + 0x2;
                                                                            edi[0x68] = 0x0;
                                                                            eax = *esi;
                                                                            ecx = *(int16_t *)eax;
                                                                            if (ecx != 0x140) {
                                                                                    *esi = eax + 0x2;
                                                                                    *(int16_t *)(edi + edi[0x68] * 0x2 + 0xd2) = ecx;
                                                                                    edi[0x68] = edi[0x68] + 0x1;
                                                                                    eax = *esi;
                                                                                    ecx = *(int16_t *)eax;
                                                                                    if (ecx != 0x140) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            eax = *esi;
                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                    *esi = eax + 0x2;
                                                                                    eax = *esi;
                                                                                    if (*(int16_t *)eax == 0x140) {
                                                                                            eax = eax + 0x2;
                                                                                            *esi = eax;
                                                                                            if (*(int16_t *)eax == 0x40) {
                                                                                                    *esi = eax + 0x2;
                                                                                                    edi[0x7e] = eax[0x1];
                                                                                                    edx = *esi;
                                                                                                    eax = edx + 0x2;
                                                                                                    *esi = edx + 0x2;
                                                                                                    if (*(int16_t *)eax == 0x140) {
                                                                                                            *esi = eax + 0x2;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    eax = 0x1;
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
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                    }
                                    else {
                                            decomp_var_10 = edi[0x5];
                                            esp = esp - 0x8;
                                            decomp_var_14 = edi + 0x6a;
                                            esp = (esp - 0x4) + 0xc;
                                            if (sub_10002990(esi, decomp_var_14, decomp_var_10) != 0x0) {
                                                    eax = *esi;
                                                    if (*(int16_t *)eax == 0x140) {
                                                            eax = eax + 0x2;
                                                            *esi = eax;
                                                            if (*(int16_t *)eax == 0x40) {
                                                                    *esi = eax + 0x2;
                                                                    edi[0x7e] = eax[0x1];
                                                                    edx = *esi;
                                                                    eax = edx + 0x2;
                                                                    *esi = edx + 0x2;
                                                                    if (*(int16_t *)eax == 0x140) {
                                                                            ebx = 0x1;
                                                                            *esi = eax + 0x2;
                                                                    }
                                                            }
                                                    }
                                                    eax = ebx;
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                            }
                            else {
                                    if (eax != 0x2443) {
                                            if (eax == 0x4143) {
                                                    decomp_var_10 = edi[0x5];
                                                    esp = esp - 0x8;
                                                    decomp_var_14 = edi + 0x6a;
                                                    esp = (esp - 0x4) + 0xc;
                                                    if (sub_10002990(esi, decomp_var_14, decomp_var_10) != 0x0) {
                                                            eax = *esi;
                                                            if (*(int16_t *)eax == 0x140) {
                                                                    eax = eax + 0x2;
                                                                    *esi = eax;
                                                                    if (*(int16_t *)eax == 0x40) {
                                                                            *esi = eax + 0x2;
                                                                            edi[0x7e] = eax[0x1];
                                                                            edx = *esi;
                                                                            eax = edx + 0x2;
                                                                            *esi = edx + 0x2;
                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                    ebx = 0x1;
                                                                                    *esi = eax + 0x2;
                                                                            }
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
                                                            eax = eax + 0x2;
                                                            *esi = eax;
                                                            if (*(int16_t *)eax == 0x40) {
                                                                    *esi = eax + 0x2;
                                                                    edi[0x7e] = eax[0x1];
                                                                    edx = *esi;
                                                                    eax = edx + 0x2;
                                                                    *esi = edx + 0x2;
                                                                    if (*(int16_t *)eax == 0x140) {
                                                                            ebx = 0x1;
                                                                            *esi = eax + 0x2;
                                                                    }
                                                            }
                                                    }
                                                    eax = ebx;
                                            }
                                    }
                                    else {
                                            esp = (esp - 0x8) + 0x8;
                                            if (sub_10002830(esi, edi + 0x70) != 0x0) {
                                                    eax = *esi;
                                                    if (*(int16_t *)eax == 0x2343) {
                                                            *esi = eax + 0x2;
                                                            esp = (esp - 0xc) + 0xc;
                                                            if (sub_10002990(esi, edi + 0x6a, edi[0x39]) != 0x0) {
                                                                    eax = *esi;
                                                                    if (*(int16_t *)eax == 0x140) {
                                                                            eax = eax + 0x2;
                                                                            *esi = eax;
                                                                            if (*(int16_t *)eax == 0x40) {
                                                                                    *esi = eax + 0x2;
                                                                                    edi[0x7e] = eax[0x1];
                                                                                    edx = *esi;
                                                                                    eax = edx + 0x2;
                                                                                    *esi = edx + 0x2;
                                                                                    if (*(int16_t *)eax == 0x140) {
                                                                                            ebx = 0x1;
                                                                                            *esi = eax + 0x2;
                                                                                    }
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
                                                                    eax = eax + 0x2;
                                                                    *esi = eax;
                                                                    if (*(int16_t *)eax == 0x40) {
                                                                            *esi = eax + 0x2;
                                                                            edi[0x7e] = eax[0x1];
                                                                            edx = *esi;
                                                                            eax = edx + 0x2;
                                                                            *esi = edx + 0x2;
                                                                            if (*(int16_t *)eax == 0x140) {
                                                                                    ebx = 0x1;
                                                                                    *esi = eax + 0x2;
                                                                            }
                                                                    }
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
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
