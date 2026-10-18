// sub_48826e @ 0x48826e
// hopper name: sub_48826e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48826e() {
    eax = arg_0[0x4];
    decomp_var_10 = ebx;
    decomp_var_14 = esi;
    esp = esp - 0xc;
    decomp_var_18 = edi;
    edx = arg_4 - arg_0[0x3];
    edx = edx >> 0xf;
    var_C = edx * 0x204 + eax + 0x144;
    ecx = *(arg_4 - 0x4);
    esi = arg_8 + 0x17 & 0xfffffff0;
    ecx = ecx - 0x1;
    bool_14 = esi >= ecx;
    edi = ecx + (arg_4 - 0x4);
    ebx = *edi;
    arg_8 = ecx;
    var_4 = ebx;
    if (esi > ecx) {
            if ((ebx & 0x1) == 0x0 && esi <= ebx + ecx) {
                    ecx = (SAR(var_4, 0x4)) - 0x1;
                    var_8 = ecx;
                    if (ecx > 0x3f) {
                            ecx = 0x3f;
                            esp = (esp - 0x4) + 0x4;
                            var_8 = 0x3f;
                    }
                    if (edi[0x1] == edi[0x2]) {
                            if (ecx < 0x20) {
                                    ebx = !(0x80000000 >> ecx);
                                    *(eax + edx * 0x4 + 0x44) = *(eax + edx * 0x4 + 0x44) & ebx;
                                    *(int8_t *)(var_8 + eax + 0x4) = *(int8_t *)(var_8 + eax + 0x4) - 0x1;
                                    if (*(int8_t *)ecx == 0x0) {
                                            *arg_0 = *arg_0 & ebx;
                                    }
                            }
                            else {
                                    ebx = !(0x80000000 >> ecx - 0x20);
                                    *(eax + edx * 0x4 + 0xc4) = *(eax + edx * 0x4 + 0xc4) & ebx;
                                    *(int8_t *)(var_8 + eax + 0x4) = *(int8_t *)(var_8 + eax + 0x4) - 0x1;
                                    if (*(int8_t *)ecx == 0x0) {
                                            arg_0[0x1] = arg_0[0x1] & ebx;
                                    }
                            }
                    }
                    *(edi[0x2] + 0x4) = edi[0x1];
                    *(edi[0x1] + 0x8) = edi[0x2];
                    var_4 = var_4 + (arg_8 - esi);
                    if (var_4 > 0x0) {
                            edi = (SAR(var_4, 0x4)) - 0x1;
                            ecx = arg_4 + (esi - 0x4);
                            if (edi > 0x3f) {
                                    edi = 0x3f;
                                    esp = (esp - 0x4) + 0x4;
                            }
                            ecx[0x1] = *(var_C + edi * 0x8 + 0x4);
                            ecx[0x2] = var_C + edi * 0x8;
                            *(var_C + edi * 0x8 + 0x4) = ecx;
                            *(ecx[0x1] + 0x8) = ecx;
                            if (ecx[0x1] == ecx[0x2]) {
                                    ecx = *(int8_t *)(edi + eax + 0x4);
                                    arg_B = ecx;
                                    *(int8_t *)(edi + eax + 0x4) = ecx + 0x1;
                                    if (edi < 0x20) {
                                            if (arg_B == 0x0) {
                                                    *arg_0 = *arg_0 | 0x80000000 >> edi;
                                            }
                                            eax = eax + edx * 0x4 + 0x44;
                                            ecx = edi;
                                    }
                                    else {
                                            if (arg_B == 0x0) {
                                                    arg_0[0x1] = arg_0[0x1] | 0x80000000 >> edi - 0x20;
                                            }
                                            eax = eax + edx * 0x4 + 0xc4;
                                            ecx = edi - 0x20;
                                    }
                                    *eax = *eax | 0x80000000 >> ecx;
                            }
                            edx = arg_4;
                            *(edx + (esi - 0x4)) = var_4;
                            *(var_4 + (edx + (esi - 0x4) - 0x4)) = var_4;
                    }
                    else {
                            edx = arg_4;
                    }
                    *(edx - 0x4) = esi + 0x1;
                    *(edx + (esi - 0x8)) = esi + 0x1;
                    eax = 0x1;
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            if (!bool_14) {
                    arg_8 = arg_8 - esi;
                    ecx = esi + 0x1;
                    *(arg_4 - 0x4) = ecx;
                    ebx = arg_4 + (esi - 0x4);
                    esi = (SAR(arg_8, 0x4)) - 0x1;
                    arg_4 = ebx;
                    *(ebx - 0x4) = ecx;
                    if (esi > 0x3f) {
                            esi = 0x3f;
                            esp = (esp - 0x4) + 0x4;
                    }
                    if ((var_4 & 0x1) == 0x0) {
                            esi = (SAR(var_4, 0x4)) - 0x1;
                            if (esi > 0x3f) {
                                    esi = 0x3f;
                                    esp = (esp - 0x4) + 0x4;
                            }
                            if (edi[0x1] == edi[0x2]) {
                                    if (esi < 0x20) {
                                            ebx = !(0x80000000 >> esi);
                                            *(eax + edx * 0x4 + 0x44) = *(eax + edx * 0x4 + 0x44) & ebx;
                                            *(int8_t *)(esi + eax + 0x4) = *(int8_t *)(esi + eax + 0x4) - 0x1;
                                            if (*(int8_t *)esi == 0x0) {
                                                    *arg_0 = *arg_0 & ebx;
                                            }
                                    }
                                    else {
                                            ebx = !(0x80000000 >> esi - 0x20);
                                            *(eax + edx * 0x4 + 0xc4) = *(eax + edx * 0x4 + 0xc4) & ebx;
                                            *(int8_t *)(esi + eax + 0x4) = *(int8_t *)(esi + eax + 0x4) - 0x1;
                                            if (*(int8_t *)ecx == 0x0) {
                                                    arg_0[0x1] = arg_0[0x1] & ebx;
                                            }
                                    }
                                    ebx = arg_4;
                            }
                            *(edi[0x2] + 0x4) = edi[0x1];
                            *(edi[0x1] + 0x8) = edi[0x2];
                            esi = arg_8 + var_4;
                            arg_8 = esi;
                            esi = (SAR(esi, 0x4)) - 0x1;
                            if (esi > 0x3f) {
                                    esi = 0x3f;
                                    esp = (esp - 0x4) + 0x4;
                            }
                    }
                    edi = *(var_C + esi * 0x8 + 0x4);
                    ebx[0x2] = var_C + esi * 0x8;
                    ebx[0x1] = edi;
                    *(var_C + esi * 0x8 + 0x4) = ebx;
                    *(ebx[0x1] + 0x8) = ebx;
                    if (ebx[0x1] == ebx[0x2]) {
                            ecx = *(int8_t *)(esi + eax + 0x4);
                            arg_7 = ecx;
                            *(int8_t *)(esi + eax + 0x4) = ecx + 0x1;
                            if (esi < 0x20) {
                                    if (arg_7 == 0x0) {
                                            *arg_0 = *arg_0 | 0x80000000 >> esi;
                                    }
                                    eax = eax + edx * 0x4 + 0x44;
                                    ecx = esi;
                            }
                            else {
                                    if (arg_7 == 0x0) {
                                            arg_0[0x1] = arg_0[0x1] | 0x80000000 >> esi - 0x20;
                                    }
                                    eax = eax + edx * 0x4 + 0xc4;
                                    ecx = esi - 0x20;
                            }
                            *eax = *eax | 0x80000000 >> ecx;
                    }
                    *ebx = arg_8;
                    *(arg_8 + (ebx - 0x4)) = arg_8;
            }
            eax = 0x1;
    }
    return eax;
}
