// sub_487da4 @ 0x487da4
// hopper name: sub_487da4
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_487da4() {
    eax = arg_0[0x4];
    decomp_var_14 = esi;
    esp = esp - 0x8;
    decomp_var_18 = edi;
    edi = arg_4 - arg_0[0x3];
    esi = arg_4 - 0x4;
    edi = edi >> 0xf;
    var_10 = edi * 0x204 + eax + 0x144;
    ecx = *esi;
    ecx = ecx - 0x1;
    var_4 = ecx;
    if ((ecx & 0x1) == 0x0) {
            esp = esp - 0x4;
            decomp_var_1c = ebx;
            ebx = ecx + esi;
            var_C = *ebx;
            var_8 = *(esi - 0x4);
            edx = var_C;
            arg_4 = ebx;
            if ((edx & 0x1) == 0x0) {
                    edx = (SAR(edx, 0x4)) - 0x1;
                    if (edx > 0x3f) {
                            edx = 0x3f;
                            esp = (esp - 0x4) + 0x4;
                    }
                    if (ebx[0x1] == ebx[0x2]) {
                            if (edx < 0x20) {
                                    ebx = !(0x80000000 >> edx);
                                    *(eax + edi * 0x4 + 0x44) = *(eax + edi * 0x4 + 0x44) & ebx;
                                    *(int8_t *)(edx + eax + 0x4) = *(int8_t *)(edx + eax + 0x4) - 0x1;
                                    if (*(int8_t *)ecx == 0x0) {
                                            *arg_0 = *arg_0 & ebx;
                                    }
                            }
                            else {
                                    ebx = !(0x80000000 >> edx - 0x20);
                                    *(eax + edi * 0x4 + 0xc4) = *(eax + edi * 0x4 + 0xc4) & ebx;
                                    *(int8_t *)(edx + eax + 0x4) = *(int8_t *)(edx + eax + 0x4) - 0x1;
                                    if (*(int8_t *)ecx == 0x0) {
                                            arg_0[0x1] = arg_0[0x1] & ebx;
                                    }
                            }
                            ebx = arg_4;
                    }
                    ecx = var_4 + var_C;
                    *(ebx[0x2] + 0x4) = ebx[0x1];
                    *(arg_4[0x1] + 0x8) = arg_4[0x2];
                    var_4 = ecx;
            }
            edx = (SAR(ecx, 0x4)) - 0x1;
            if (edx > 0x3f) {
                    edx = 0x3f;
                    esp = (esp - 0x4) + 0x4;
            }
            var_C = var_8 & 0x1;
            if ((var_8 & 0x1) == 0x0) {
                    arg_4 = esi - var_8;
                    ebx = (SAR(var_8, 0x4)) - 0x1;
                    esp = (esp - 0x4) + 0x4;
                    if (ebx > 0x3f) {
                            ebx = 0x3f;
                    }
                    edx = (SAR(ecx + var_8, 0x4)) - 0x1;
                    var_4 = ecx + var_8;
                    if (edx > 0x3f) {
                            edx = 0x3f;
                    }
                    if (ebx != edx) {
                            if (arg_4[0x1] == arg_4[0x2]) {
                                    if (ebx < 0x20) {
                                            esi = !(0x80000000 >> ebx);
                                            *(eax + edi * 0x4 + 0x44) = *(eax + edi * 0x4 + 0x44) & esi;
                                            *(int8_t *)(ebx + eax + 0x4) = *(int8_t *)(ebx + eax + 0x4) - 0x1;
                                            if (*(int8_t *)(ebx + eax + 0x4) == 0x0) {
                                                    *arg_0 = *arg_0 & esi;
                                            }
                                    }
                                    else {
                                            esi = !(0x80000000 >> ebx - 0x20);
                                            *(eax + edi * 0x4 + 0xc4) = *(eax + edi * 0x4 + 0xc4) & esi;
                                            *(int8_t *)(ebx + eax + 0x4) = *(int8_t *)(ebx + eax + 0x4) - 0x1;
                                            if (*(int8_t *)(ebx + eax + 0x4) == 0x0) {
                                                    arg_0[0x1] = arg_0[0x1] & esi;
                                            }
                                    }
                            }
                            *(arg_4[0x2] + 0x4) = arg_4[0x1];
                            *(arg_4[0x1] + 0x8) = arg_4[0x2];
                    }
                    esi = arg_4;
            }
            else {
                    ebx = arg_0;
            }
            if (var_C == 0x0) {
                    if (ebx != edx) {
                            ebx = *(var_10 + edx * 0x8 + 0x4);
                            esi[0x2] = var_10 + edx * 0x8;
                            esi[0x1] = ebx;
                            *(var_10 + edx * 0x8 + 0x4) = esi;
                            *(esi[0x1] + 0x8) = esi;
                            if (esi[0x1] == esi[0x2]) {
                                    ecx = *(int8_t *)(edx + eax + 0x4);
                                    arg_7 = ecx;
                                    *(int8_t *)(edx + eax + 0x4) = ecx + 0x1;
                                    if (edx < 0x20) {
                                            if (arg_7 == 0x0) {
                                                    *arg_0 = *arg_0 | 0x80000000 >> edx;
                                            }
                                            *(eax + edi * 0x4 + 0x44) = *(eax + edi * 0x4 + 0x44) | 0x80000000 >> edx;
                                    }
                                    else {
                                            if (arg_7 == 0x0) {
                                                    arg_0[0x1] = arg_0[0x1] | 0x80000000 >> edx - 0x20;
                                            }
                                            *(eax + edi * 0x4 + 0xc4) = *(eax + edi * 0x4 + 0xc4) | 0x80000000 >> edx - 0x20;
                                    }
                            }
                    }
            }
            else {
                    ebx = *(var_10 + edx * 0x8 + 0x4);
                    esi[0x2] = var_10 + edx * 0x8;
                    esi[0x1] = ebx;
                    *(var_10 + edx * 0x8 + 0x4) = esi;
                    *(esi[0x1] + 0x8) = esi;
                    if (esi[0x1] == esi[0x2]) {
                            ecx = *(int8_t *)(edx + eax + 0x4);
                            arg_7 = ecx;
                            *(int8_t *)(edx + eax + 0x4) = ecx + 0x1;
                            if (edx < 0x20) {
                                    if (arg_7 == 0x0) {
                                            *arg_0 = *arg_0 | 0x80000000 >> edx;
                                    }
                                    *(eax + edi * 0x4 + 0x44) = *(eax + edi * 0x4 + 0x44) | 0x80000000 >> edx;
                            }
                            else {
                                    if (arg_7 == 0x0) {
                                            arg_0[0x1] = arg_0[0x1] | 0x80000000 >> edx - 0x20;
                                    }
                                    *(eax + edi * 0x4 + 0xc4) = *(eax + edi * 0x4 + 0xc4) | 0x80000000 >> edx - 0x20;
                            }
                    }
            }
            *esi = var_4;
            *(var_4 + (esi - 0x4)) = var_4;
            eax = var_10;
            *eax = *eax - 0x1;
            if (*eax == 0x0) {
                    if (*dword_bc69f0 != 0x0) {
                            esp = esp - 0xc;
                            VirtualFree((*dword_bc7224 << 0xf) + *(*dword_bc69f0 + 0xc), 0x8000, 0x4000);
                            ecx = *dword_bc7224;
                            eax = *dword_bc69f0;
                            eax[0x2] = eax[0x2] | 0x80000000 >> ecx;
                            eax = *dword_bc69f0;
                            eax = eax[0x4];
                            ecx = *dword_bc7224;
                            *(eax + ecx * 0x4 + 0xc4) = *(eax + ecx * 0x4 + 0xc4) & 0x0;
                            eax = *dword_bc69f0;
                            eax = eax[0x4];
                            eax[0x43] = eax[0x43] - 0x1;
                            if (*(int8_t *)(*(*dword_bc69f0 + 0x10) + 0x43) == 0x0) {
                                    eax = *dword_bc69f0;
                                    eax[0x1] = eax[0x1] & 0xfffffffe;
                            }
                            if (*(*dword_bc69f0 + 0x8) == 0xffffffff) {
                                    VirtualFree(*(*dword_bc69f0 + 0xc), 0x0, 0x8000);
                                    HeapFree(*dword_bc69f4, 0x0, *(*dword_bc69f0 + 0x10));
                                    ecx = *dword_bc7210;
                                    eax = *dword_bc69f0;
                                    sub_47f9a0(eax, eax + 0x14, (ecx * 0x14 - eax) + (*dword_bc7214 - 0x14));
                                    esp = (esp - 0x24) + 0xc;
                                    *dword_bc7210 = *dword_bc7210 - 0x1;
                                    if (arg_0 > *dword_bc69f0) {
                                            arg_0 = arg_0 - 0x14;
                                    }
                                    *dword_bc721c = *dword_bc7214;
                            }
                    }
                    eax = arg_0;
                    *dword_bc69f0 = eax;
                    *dword_bc7224 = edi;
            }
            esp = esp + 0x4;
    }
    return eax;
}
