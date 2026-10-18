// sub_466a30 @ 0x466a30
// hopper name: sub_466a30
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_466a30() {
    esp = esp - 0x8;
    edi = ecx[0x9];
    edx = arg_c + arg_4;
    eax = *edi;
    if (eax != 0x0 && ecx[0xf] < eax) {
            ecx[0xf] = eax;
    }
    if (edx != 0xffffffff) {
            ebx = arg_1c;
            esp = esp - 0x8;
            if ((ebx & 0x1) != 0x0) {
                    esi = *ecx[0x8];
                    if (esi != 0x0) {
                            if (edx >= 0x0) {
                                    eax = ecx[0x4];
                                    eax = *eax;
                                    if (edx <= ecx[0xf] - eax) {
                                            eax = eax - esi;
                                            esi = ecx[0xc];
                                            *esi = *esi - eax + edx;
                                            esi = ecx[0x8];
                                            *esi = *esi + eax + edx;
                                            if ((ebx & 0x2) != 0x0) {
                                                    edi = ecx[0x9];
                                                    ebx = *edi;
                                                    if (ebx != 0x0) {
                                                            esi = *ecx[0x8];
                                                            eax = ecx[0xd];
                                                            eax = *eax;
                                                            *edi = esi;
                                                            *ecx[0xd] = eax + ebx - esi;
                                                    }
                                            }
                                    }
                                    else {
                                            edx = 0xffffffff;
                                    }
                            }
                            else {
                                    edx = 0xffffffff;
                            }
                            esp = esp + 0x8;
                            eax = arg_20;
                            *eax = edx;
                            eax[0x2] = 0x0;
                            eax[0x3] = 0x0;
                            eax[0x4] = 0x0;
                    }
                    else {
                            if ((ebx & 0x2) != 0x0) {
                                    edi = *edi;
                                    if (edi != 0x0) {
                                            if (edx >= 0x0) {
                                                    eax = ecx[0x4];
                                                    eax = *eax;
                                                    if (edx <= ecx[0xf] - eax) {
                                                            esi = ecx[0xd];
                                                            *esi = *esi - (eax - edi) + edx;
                                                            ecx = ecx[0x9];
                                                            *ecx = *ecx + (eax - edi) + edx;
                                                    }
                                                    else {
                                                            edx = 0xffffffff;
                                                    }
                                            }
                                            else {
                                                    edx = 0xffffffff;
                                            }
                                    }
                                    else {
                                            edx = 0xffffffff;
                                    }
                            }
                            else {
                                    edx = 0xffffffff;
                            }
                            esp = esp + 0x8;
                            eax = arg_20;
                            *eax = edx;
                            eax[0x2] = 0x0;
                            eax[0x3] = 0x0;
                            eax[0x4] = 0x0;
                    }
            }
            else {
                    if ((ebx & 0x2) != 0x0) {
                            edi = *edi;
                            if (edi != 0x0) {
                                    if (edx >= 0x0) {
                                            eax = ecx[0x4];
                                            eax = *eax;
                                            if (edx <= ecx[0xf] - eax) {
                                                    esi = ecx[0xd];
                                                    *esi = *esi - (eax - edi) + edx;
                                                    ecx = ecx[0x9];
                                                    *ecx = *ecx + (eax - edi) + edx;
                                            }
                                            else {
                                                    edx = 0xffffffff;
                                            }
                                    }
                                    else {
                                            edx = 0xffffffff;
                                    }
                            }
                            else {
                                    edx = 0xffffffff;
                            }
                    }
                    else {
                            edx = 0xffffffff;
                    }
                    esp = esp + 0x8;
                    eax = arg_20;
                    *eax = edx;
                    eax[0x2] = 0x0;
                    eax[0x3] = 0x0;
                    eax[0x4] = 0x0;
            }
    }
    else {
            eax = arg_20;
            *eax = edx;
            eax[0x2] = 0x0;
            eax[0x3] = 0x0;
            eax[0x4] = 0x0;
    }
    return eax;
}
