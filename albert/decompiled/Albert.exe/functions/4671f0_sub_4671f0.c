// sub_4671f0 @ 0x4671f0
// hopper name: sub_4671f0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4671f0() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esi = ecx;
    esp = esp - 0xc;
    decomp_var_c = edi;
    if ((esi[0x40] & 0x8) != 0x0) {
            edi = esi[0x9];
            edx = *edi;
            if (edx != 0x0) {
                    ecx = esi[0xf];
                    if (edx < ecx) {
                            eax = esi[0xd];
                            eax = *eax;
                            *edi = ecx;
                            eax = eax + edx - ecx;
                            *esi[0xd] = eax;
                    }
            }
    }
    ebx = arg_0;
    if (ebx == 0xffffffff) {
            eax = 0x0;
    }
    else {
            edx = *esi[0x9];
            if (edx != 0x0) {
                    eax = esi[0xd];
                    if (edx < *eax + edx) {
                            *eax = *eax - 0x1;
                            esi = esi[0x9];
                            eax = *esi;
                            *esi = eax + 0x1;
                            *(int8_t *)eax = ebx;
                            eax = ebx;
                    }
                    else {
                            if ((esi[0x40] & 0x2) != 0x0) {
                                    eax = eax | 0xffffffff;
                            }
                            else {
                                    esp = esp - 0x4;
                                    if (edx == 0x0) {
                                            ebp = 0x0;
                                    }
                                    else {
                                            eax = esi[0xd];
                                            ecx = esi[0x4];
                                            ebp = *eax;
                                            ebp = ebp - *ecx;
                                            ebp = ebp + edx;
                                    }
                                    eax = ebp >> 0x1;
                                    ebx = ebp;
                                    if (eax < 0x20) {
                                            eax = 0x20;
                                    }
                                    edi = 0x0;
                                    if (eax > 0x0) {
                                            while (true) {
                                                    if (0x7fffffff - eax >= ebp) {
                                                            if (eax > 0x0) {
                                                                    ebx = eax + ebp;
                                                                    esp = (esp - 0x8) + 0x8;
                                                                    edi = sub_401620(ebx);
                                                                    temp_0 = 0x1;
                                                            }
                                                            else {
                                                                    temp_0 = 0x0;
                                                            }
                                                            break;
                                                    }
                                                    eax = eax >> 0x1;
                                                    if (eax != 0x0) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                    }
                                    if (ebp > 0x0) {
                                            sub_47a5af(edi, ebx, *esi[0x4], ebp);
                                            esp = (esp - 0x10) + 0x10;
                                    }
                                    if ((esi[0x40] & 0x1) != 0x0) {
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    esi[0x10] = esi[0x10] | 0x1;
                                    if (ebp == 0x0) {
                                            ecx = esi[0x5];
                                            esi[0xf] = edi;
                                            *ecx = edi;
                                            *esi[0x9] = edi;
                                            *esi[0xd] = ebx;
                                            ecx = esi[0x4];
                                            bool_23 = (esi[0x40] & 0x4) != 0x0;
                                            *ecx = edi;
                                            edx = esi[0x8];
                                            if (!bool_23) {
                                                    *edx = edi;
                                                    *esi[0xc] = 0x1;
                                            }
                                            else {
                                                    *edx = 0x0;
                                                    *esi[0xc] = edi;
                                            }
                                    }
                                    else {
                                            eax = esi[0x4];
                                            edx = esi[0x9];
                                            esi[0xf] = esi[0xf] + (edi - *eax);
                                            ecx = *eax;
                                            eax = *edx;
                                            edx = esi[0x5];
                                            *edx = *edx + (edi - ecx);
                                            *esi[0x9] = (eax - ecx) + edi;
                                            *esi[0xd] = (edi - (eax - ecx) + edi) + ebx;
                                            if ((esi[0x40] & 0x4) != 0x0) {
                                                    *esi[0x4] = edi;
                                                    edx = esi[0x8];
                                                    *edx = 0x0;
                                                    *esi[0xc] = edi;
                                            }
                                            else {
                                                    eax = esi[0x8];
                                                    eax = *eax;
                                                    edx = esi[0x4];
                                                    eax = eax - *edx;
                                                    ecx = esi[0x9];
                                                    ecx = *ecx;
                                                    *edx = edi;
                                                    *esi[0x8] = eax + edi;
                                                    *esi[0xc] = (ecx - eax + edi) + 0x1;
                                            }
                                    }
                                    eax = esi[0xd];
                                    *eax = *eax - 0x1;
                                    esi = esi[0x9];
                                    eax = *esi;
                                    *esi = eax + 0x1;
                                    *(int8_t *)eax = arg_c;
                                    eax = arg_c;
                            }
                    }
            }
            else {
                    if ((esi[0x40] & 0x2) != 0x0) {
                            eax = eax | 0xffffffff;
                    }
                    else {
                            esp = esp - 0x4;
                            if (edx == 0x0) {
                                    ebp = 0x0;
                            }
                            else {
                                    eax = esi[0xd];
                                    ecx = esi[0x4];
                                    ebp = *eax;
                                    ebp = ebp - *ecx;
                                    ebp = ebp + edx;
                            }
                            eax = ebp >> 0x1;
                            ebx = ebp;
                            if (eax < 0x20) {
                                    eax = 0x20;
                            }
                            edi = 0x0;
                            if (eax > 0x0) {
                                    while (true) {
                                            if (0x7fffffff - eax >= ebp) {
                                                    if (eax > 0x0) {
                                                            ebx = eax + ebp;
                                                            esp = (esp - 0x8) + 0x8;
                                                            edi = sub_401620(ebx);
                                                            temp_0 = 0x1;
                                                    }
                                                    else {
                                                            temp_0 = 0x0;
                                                    }
                                                    break;
                                            }
                                            eax = eax >> 0x1;
                                            if (eax != 0x0) {
                                                    continue;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                            }
                            if (ebp > 0x0) {
                                    sub_47a5af(edi, ebx, *esi[0x4], ebp);
                                    esp = (esp - 0x10) + 0x10;
                            }
                            if ((esi[0x40] & 0x1) != 0x0) {
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                            esi[0x10] = esi[0x10] | 0x1;
                            if (ebp == 0x0) {
                                    ecx = esi[0x5];
                                    esi[0xf] = edi;
                                    *ecx = edi;
                                    *esi[0x9] = edi;
                                    *esi[0xd] = ebx;
                                    ecx = esi[0x4];
                                    bool_8 = (esi[0x40] & 0x4) != 0x0;
                                    *ecx = edi;
                                    edx = esi[0x8];
                                    if (!bool_8) {
                                            *edx = edi;
                                            *esi[0xc] = 0x1;
                                    }
                                    else {
                                            *edx = 0x0;
                                            *esi[0xc] = edi;
                                    }
                            }
                            else {
                                    eax = esi[0x4];
                                    edx = esi[0x9];
                                    esi[0xf] = esi[0xf] + (edi - *eax);
                                    ecx = *eax;
                                    eax = *edx;
                                    edx = esi[0x5];
                                    *edx = *edx + (edi - ecx);
                                    *esi[0x9] = (eax - ecx) + edi;
                                    *esi[0xd] = (edi - (eax - ecx) + edi) + ebx;
                                    if ((esi[0x40] & 0x4) != 0x0) {
                                            *esi[0x4] = edi;
                                            edx = esi[0x8];
                                            *edx = 0x0;
                                            *esi[0xc] = edi;
                                    }
                                    else {
                                            eax = esi[0x8];
                                            eax = *eax;
                                            edx = esi[0x4];
                                            eax = eax - *edx;
                                            ecx = esi[0x9];
                                            ecx = *ecx;
                                            *edx = edi;
                                            *esi[0x8] = eax + edi;
                                            *esi[0xc] = (ecx - eax + edi) + 0x1;
                                    }
                            }
                            eax = esi[0xd];
                            *eax = *eax - 0x1;
                            esi = esi[0x9];
                            eax = *esi;
                            *esi = eax + 0x1;
                            *(int8_t *)eax = arg_c;
                            eax = arg_c;
                    }
            }
    }
    return eax;
}
