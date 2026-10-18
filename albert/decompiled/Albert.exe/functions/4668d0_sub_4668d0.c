// sub_4668d0 @ 0x4668d0
// hopper name: sub_4668d0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4668d0() {
    edx = ecx[0x9];
    eax = *edx;
    if (eax != 0x0 && ecx[0xf] < eax) {
            ecx[0xf] = eax;
    }
    ebx = arg_c;
    esp = esp - 0xc;
    if ((ebx & 0x1) != 0x0) {
            esi = *ecx[0x8];
            if (esi != 0x0) {
                    eax = arg_8;
                    if (eax == 0x2) {
                            edx = ecx[0x4];
                            edx = arg_4 + (ecx[0xf] - *edx);
                    }
                    else {
                            if (eax == 0x1) {
                                    if ((ebx & 0x2) == 0x0) {
                                            edx = arg_4 + (esi - *ecx[0x4]);
                                    }
                                    else {
                                            edx = 0xffffffff;
                                    }
                            }
                            else {
                                    if (eax != 0x0) {
                                            edx = 0xffffffff;
                                    }
                                    else {
                                            edx = arg_4;
                                    }
                            }
                    }
                    if (edx >= 0x0) {
                            eax = ecx[0x4];
                            eax = *eax;
                            esp = (esp - 0x4) + 0x4;
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
                    eax = arg_20;
                    *eax = edx;
                    eax[0x2] = 0x0;
                    eax[0x3] = 0x0;
                    eax[0x4] = 0x0;
            }
            else {
                    if ((ebx & 0x2) != 0x0) {
                            esi = *edx;
                            if (esi != 0x0) {
                                    eax = arg_8;
                                    if (eax == 0x2) {
                                            edx = ecx[0x4];
                                            edx = arg_4 + (ecx[0xf] - *edx);
                                    }
                                    else {
                                            if (eax == 0x1) {
                                                    edx = arg_4 + (esi - *ecx[0x4]);
                                            }
                                            else {
                                                    edx = 0xffffffff;
                                                    if (eax == 0x0) {
                                                            edx = arg_4;
                                                    }
                                            }
                                    }
                                    if (edx >= 0x0) {
                                            eax = ecx[0x4];
                                            eax = *eax;
                                            if (edx <= ecx[0xf] - eax) {
                                                    eax = eax - esi;
                                                    esi = ecx[0xd];
                                                    *esi = *esi - eax + edx;
                                                    ecx = ecx[0x9];
                                                    *ecx = *ecx + eax + edx;
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
                    eax = arg_20;
                    *eax = edx;
                    eax[0x2] = 0x0;
                    eax[0x3] = 0x0;
                    eax[0x4] = 0x0;
            }
    }
    else {
            if ((ebx & 0x2) != 0x0) {
                    esi = *edx;
                    if (esi != 0x0) {
                            eax = arg_8;
                            if (eax == 0x2) {
                                    edx = ecx[0x4];
                                    edx = arg_4 + (ecx[0xf] - *edx);
                            }
                            else {
                                    if (eax == 0x1) {
                                            edx = arg_4 + (esi - *ecx[0x4]);
                                    }
                                    else {
                                            edx = 0xffffffff;
                                            if (eax == 0x0) {
                                                    edx = arg_4;
                                            }
                                    }
                            }
                            if (edx >= 0x0) {
                                    eax = ecx[0x4];
                                    eax = *eax;
                                    if (edx <= ecx[0xf] - eax) {
                                            eax = eax - esi;
                                            esi = ecx[0xd];
                                            *esi = *esi - eax + edx;
                                            ecx = ecx[0x9];
                                            *ecx = *ecx + eax + edx;
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
            eax = arg_20;
            *eax = edx;
            eax[0x2] = 0x0;
            eax[0x3] = 0x0;
            eax[0x4] = 0x0;
    }
    return eax;
}
