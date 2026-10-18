// sub_48ff25 @ 0x48ff25
// hopper name: sub_48ff25
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48ff25() {
    ecx = arg_0[0x5] & 0xffff;
    decomp_var_30 = ebx;
    var_14 = ecx & 0x8000;
    var_20 = *(arg_0 + 0x6);
    ebx = (ecx & 0x7fff) - 0x3fff;
    bool_7 = true;
    bool_6 = true;
    bool_5 = true;
    esp = esp - 0x8;
    decomp_var_34 = edi;
    var_1C = *(arg_0 + 0x2);
    var_18 = (*(int16_t *)arg_0 & 0xffff) << 0x10;
    if (ebx != 0xffffc001) goto loc_48ff8f;
    goto loc_48ff68;

loc_48ff8f:
    arg_0 = arg_0 & 0x0;
    esp = esp - 0x4;
    decomp_var_38 = esi;
    var_2C = var_20;
    var_2C = var_20;
    var_2C = var_20;
    esi = *dword_4c9f84;
    esi = esi - 0x1;
    eax = SAR(esi + 0x1 + ((esi + 0x1 & 0x80000000 ? 0xffffffff : 0x0) & 0x1f), 0x5);
    edx = esi + 0x1 & 0x8000001f;
    var_10 = ebx;
    var_C = eax;
    if (edx < 0x0) {
            edx = (edx - 0x1 | 0xffffffe0) + 0x1;
    }
    edi = ebp + (eax * 0x4 - 0x20);
    esp = (esp - 0x4) + 0x4;
    ecx = 0x1f - edx;
    eax = 0x1 << ecx;
    bool_73 = eax != 0x0;
    var_8 = ecx;
    if (eax == 0x0) goto loc_49006d;
    goto loc_48ffe0;

loc_48ff68:
    eax = 0x0;
    while (true) {
            ebx = 0x0;
            bool_63 = true;
            bool_62 = true;
            bool_61 = true;
            if (*(ebp + (eax * 0x4 - 0x20)) != 0x0) {
                    eax = 0x0;
                    edi = &var_20;
                    asm { stosd      dword [edi], eax };
                    asm { stosd      dword [edi], eax };
                    esp = esp - 0x4;
                    decomp_var_38 = 0x2;
                    asm { stosd      dword [edi], eax };
                    eax = decomp_var_38;
                    esp = esp + 0x4;
                    break;
            }
            eax = eax + 0x1;
            if (eax < 0x3) {
                    continue;
            }
            eax = 0x0;
            break;
    }
    goto loc_490424;

loc_49006d:
    *edi = *edi & (eax | 0xffffffff) << var_8;
    eax = var_C + 0x1;
    bool_9 = true;
    if (eax < 0x3) {
            esp = (esp - 0x4) + 0x4;
            asm { rep stosd  dword [edi], eax };
    }
    if (arg_0 != 0x0) {
            ebx = ebx + 0x1;
    }
    ecx = *dword_4c9f80 - *dword_4c9f84;
    bool_12 = true;
    bool_11 = true;
    bool_10 = true;
    if (ebx >= ecx) goto loc_4900b2;
    goto loc_4900a5;

loc_48ffe0:
    eax = var_C;
    while (true) {
            if (bool_73) {
                    ecx = 0x1f;
                    esp = (esp - 0x4) + 0x4;
                    eax = SAR(esi + ((esi & 0x80000000 ? 0xffffffff : 0x0) & 0x1f), 0x5);
                    esi = esi & 0x8000001f;
                    if (esi < 0x0) {
                            esi = (esi - 0x1 | 0xffffffe0) + 0x1;
                            temp_2 = 0x1;
                    }
                    else {
                            temp_2 = 0x1;
                    }
                    break;
            }
            eax = eax + 0x1;
            if (eax < 0x3) {
                    continue;
            }
            temp_2 = 0x0;
            break;
    }
    if (temp_2 == 0x0) goto loc_49006d;
    goto loc_490019;

loc_490424:
    esp = (esp - 0x4) + 0x4;
    ebx = ebx << 0x1f - *dword_4c9f88;
    ebx = ebx | -var_14 - -var_14 + CARRY(EFLAGS(cf)) & 0x80000000 | var_20;
    if (*dword_4c9f8c == 0x40) {
            arg_4[0x1] = ebx;
            *arg_4 = var_1C;
    }
    else {
            if (*dword_4c9f8c == 0x20) {
                    *arg_4 = ebx;
            }
    }
    return eax;

loc_4900b2:
    eax = *dword_4c9f80;
    bool_16 = true;
    bool_15 = true;
    if (ebx > eax) goto loc_4902c9;
    goto loc_4900ba;

loc_4900a5:
    eax = 0x0;
    edi = &var_20;
    asm { stosd      dword [edi], eax };
    asm { stosd      dword [edi], eax };
    asm { stosd      dword [edi], eax };
    goto loc_4902bf;

loc_490019:
    var_4 = var_4 & 0x0;
    edx = 0x1 << ecx - esi;
    ecx = ebp + (eax * 0x4 - 0x20);
    arg_0 = *ecx + edx;
    esi = *ecx;
    bool_34 = arg_0 >= esi;
    if (arg_0 < esi || !bool_34) goto loc_490058;
    goto loc_49005f;
    return eax;

loc_4902c9:
    bool_28 = true;
    bool_27 = true;
    bool_26 = true;
    if (ebx >= *dword_4c9f7c) {
            ecx = *dword_4c9f88;
            eax = 0x0;
            edi = &var_20;
            asm { stosd      dword [edi], eax };
            asm { stosd      dword [edi], eax };
            asm { stosd      dword [edi], eax };
            var_20 = var_20 | 0x80000000;
            eax = SAR(ecx + ((ecx & 0x80000000 ? 0xffffffff : 0x0) & 0x1f), 0x5);
            edx = ecx & 0x8000001f;
            if (edx < 0x0) {
                    edx = (edx - 0x1 | 0xffffffe0) + 0x1;
            }
            var_C = var_C & 0x0;
            arg_0 = arg_0 & 0x0;
            var_4 = 0x20 - edx;
            edi = !((edi | 0xffffffff) << edx);
            do {
                    esi = *(ebp + (arg_0 * 0x4 - 0x20));
                    *(ebp + (arg_0 * 0x4 - 0x20)) = esi >> edx | var_C;
                    arg_0 = arg_0 + 0x1;
                    var_C = (esi & edi) << var_4;
            } while (arg_0 < 0x3);
            edx = 0x2;
            esp = (esp - 0x4) + 0x4;
            ecx = &var_18 - (eax << 0x2);
            do {
                    if (edx >= eax) {
                            *(ebp + (edx * 0x4 - 0x20)) = *ecx;
                    }
                    else {
                            *(ebp + (edx * 0x4 - 0x20)) = *(ebp + (edx * 0x4 - 0x20)) & 0x0;
                    }
                    edx = edx - 0x1;
                    ecx = ecx - 0x4;
            } while (edx >= 0x0);
            ebx = *dword_4c9f90 + *dword_4c9f7c;
            eax = 0x1;
    }
    else {
            ecx = *dword_4c9f88;
            var_20 = var_20 & 0x7fffffff;
            ebx = ebx + *dword_4c9f90;
            eax = SAR(ecx + ((ecx & 0x80000000 ? 0xffffffff : 0x0) & 0x1f), 0x5);
            edx = ecx & 0x8000001f;
            if (edx < 0x0) {
                    edx = (edx - 0x1 | 0xffffffe0) + 0x1;
            }
            var_C = var_C & 0x0;
            arg_0 = arg_0 & 0x0;
            var_4 = 0x20 - edx;
            esi = !((esi | 0xffffffff) << edx);
            do {
                    edi = *(ebp + (arg_0 * 0x4 - 0x20));
                    *(ebp + (arg_0 * 0x4 - 0x20)) = edi >> edx | var_C;
                    arg_0 = arg_0 + 0x1;
                    var_C = (edi & esi) << var_4;
            } while (arg_0 < 0x3);
            edx = 0x2;
            esp = (esp - 0x4) + 0x4;
            ecx = &var_18 - (eax << 0x2);
            do {
                    if (edx >= eax) {
                            *(ebp + (edx * 0x4 - 0x20)) = *ecx;
                    }
                    else {
                            *(ebp + (edx * 0x4 - 0x20)) = *(ebp + (edx * 0x4 - 0x20)) & 0x0;
                    }
                    edx = edx - 0x1;
                    ecx = ecx - 0x4;
            } while (edx >= 0x0);
            eax = 0x0;
    }
    goto loc_490423;

loc_4900ba:
    eax = *dword_4c9f80;
    edi = &var_20;
    *edi = var_2C;
    *edi = var_2C;
    edx = eax - var_10;
    eax = SAR((eax - var_10) + ((eax - var_10 & 0x80000000 ? 0xffffffff : 0x0) & 0x1f), 0x5);
    edx = edx & 0x8000001f;
    *edi = var_2C;
    if (edx < 0x0) {
            edx = (edx - 0x1 | 0xffffffe0) + 0x1;
    }
    var_C = var_C & 0x0;
    arg_0 = arg_0 & 0x0;
    var_4 = 0x20 - edx;
    edi = !((edi | 0xffffffff) << edx);
    do {
            esi = *(ebp + (arg_0 * 0x4 - 0x20));
            *(ebp + (arg_0 * 0x4 - 0x20)) = esi >> edx | var_C;
            arg_0 = arg_0 + 0x1;
            var_C = (esi & edi) << var_4;
    } while (arg_0 < 0x3);
    edx = 0x2;
    esp = (esp - 0x4) + 0x4;
    ecx = &var_18 - (eax << 0x2);
    do {
            if (edx >= eax) {
                    *(ebp + (edx * 0x4 - 0x20)) = *ecx;
            }
            else {
                    *(ebp + (edx * 0x4 - 0x20)) = *(ebp + (edx * 0x4 - 0x20)) & 0x0;
            }
            edx = edx - 0x1;
            ecx = ecx - 0x4;
    } while (edx >= 0x0);
    esi = *dword_4c9f84;
    esi = esi - 0x1;
    eax = SAR(esi + 0x1 + ((esi + 0x1 & 0x80000000 ? 0xffffffff : 0x0) & 0x1f), 0x5);
    edx = esi + 0x1 & 0x8000001f;
    var_C = eax;
    if (edx < 0x0) {
            edx = (edx - 0x1 | 0xffffffe0) + 0x1;
    }
    esp = (esp - 0x4) + 0x4;
    ecx = 0x1f - edx;
    bool_50 = 0x1 << ecx != 0x0;
    ebx = ebp + (eax * 0x4 - 0x20);
    var_10 = ecx;
    if (0x1 << ecx == 0x0) goto loc_490210;
    goto loc_49018e;

loc_4902bf:
    ebx = 0x0;
    eax = 0x2;
    esp = (esp - 0x4) + 0x4;
    goto loc_490423;

loc_490058:
    while (true) {
            var_4 = 0x1;
            while (true) {
                    eax = eax - 0x1;
                    *ecx = arg_0;
                    ecx = var_4;
                    if (eax < 0x0) {
                            break;
                    }
                    else {
                            if (ecx != 0x0) {
                                    var_4 = var_4 & 0x0;
                                    ecx = ebp + (eax * 0x4 - 0x20);
                                    edx = *ecx;
                                    bool_65 = edx + 0x1 >= edx;
                                    arg_0 = edx + 0x1;
                                    if (edx + 0x1 >= edx) {
                                            if (bool_65) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    else {
                                            break;
                                    }
                            }
                            else {
                                    break;
                            }
                    }
            }
    }

loc_49005f:
    while (true) {
            eax = eax - 0x1;
            *ecx = arg_0;
            ecx = var_4;
            if (eax < 0x0) {
                    temp_0 = 0x1;
                    break;
            }
            else {
                    if (ecx != 0x0) {
                            var_4 = var_4 & 0x0;
                            ecx = ebp + (eax * 0x4 - 0x20);
                            edx = *ecx;
                            esi = edx + 0x1;
                            bool_38 = esi >= edx;
                            arg_0 = esi;
                            if (esi >= edx) {
                                    if (bool_38) {
                                            continue;
                                    }
                                    temp_0 = 0x0;
                                    break;
                            }
                            else {
                                    temp_0 = 0x0;
                                    break;
                            }
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    if (temp_0 == 0x0) {
            do {
                    var_4 = 0x1;
                    while (true) {
                            eax = eax - 0x1;
                            *ecx = arg_0;
                            ecx = var_4;
                            if (eax < 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            else {
                                    if (ecx != 0x0) {
                                            var_4 = var_4 & 0x0;
                                            ecx = ebp + (eax * 0x4 - 0x20);
                                            edx = *ecx;
                                            esi = edx + 0x1;
                                            bool_53 = esi >= edx;
                                            arg_0 = esi;
                                            if (esi >= edx) {
                                                    if (bool_53) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                    }
                                    else {
                                            temp_0 = 0x1;
                                            break;
                                    }
                            }
                    }
            } while (temp_0 == 0x0);
    }
    arg_0 = ecx;
    goto loc_49006d;

loc_490423:
    esp = esp + 0x4;
    goto loc_490424;

loc_490210:
    *ebx = *ebx & (eax | 0xffffffff) << var_10;
    eax = var_C + 0x1;
    bool_19 = true;
    if (eax < 0x3) {
            esp = (esp - 0x4) + 0x4;
            edi = ebp + (eax * 0x4 - 0x20);
            asm { rep stosd  dword [edi], eax };
    }
    ecx = *dword_4c9f88;
    eax = SAR(ecx + 0x1 + ((ecx + 0x1 & 0x80000000 ? 0xffffffff : 0x0) & 0x1f), 0x5);
    edx = ecx + 0x1 & 0x8000001f;
    if (edx < 0x0) {
            edx = (edx - 0x1 | 0xffffffe0) + 0x1;
    }
    var_C = var_C & 0x0;
    arg_0 = arg_0 & 0x0;
    var_4 = 0x20 - edx;
    edi = !((edi | 0xffffffff) << edx);
    do {
            esi = *(ebp + (arg_0 * 0x4 - 0x20));
            *(ebp + (arg_0 * 0x4 - 0x20)) = esi >> edx | var_C;
            arg_0 = arg_0 + 0x1;
            var_C = (esi & edi) << var_4;
    } while (arg_0 < 0x3);
    edx = 0x2;
    esp = (esp - 0x4) + 0x4;
    ecx = &var_18 - (eax << 0x2);
    do {
            if (edx >= eax) {
                    *(ebp + (edx * 0x4 - 0x20)) = *ecx;
            }
            else {
                    *(ebp + (edx * 0x4 - 0x20)) = *(ebp + (edx * 0x4 - 0x20)) & 0x0;
            }
            edx = edx - 0x1;
            ecx = ecx - 0x4;
    } while (edx >= 0x0);
    goto loc_4902bf;

loc_49018e:
    while (true) {
            if (bool_50) {
                    ecx = 0x1f;
                    esp = (esp - 0x4) + 0x4;
                    eax = SAR(esi + ((esi & 0x80000000 ? 0xffffffff : 0x0) & 0x1f), 0x5);
                    esi = esi & 0x8000001f;
                    if (esi < 0x0) {
                            esi = (esi - 0x1 | 0xffffffe0) + 0x1;
                            temp_3 = 0x1;
                    }
                    else {
                            temp_3 = 0x1;
                    }
                    break;
            }
            eax = eax + 0x1;
            if (eax < 0x3) {
                    continue;
            }
            temp_3 = 0x0;
            break;
    }
    if (temp_3 == 0x0) goto loc_490210;

loc_4901c4:
    arg_0 = arg_0 & 0x0;
    edx = 0x1 << ecx - esi;
    ecx = ebp + (eax * 0x4 - 0x20);
    esi = *ecx;
    edi = esi + edx;
    if (edi < esi || edi < edx) {
            arg_0 = 0x1;
    }
    *ecx = edi;
    ecx = arg_0;
    goto loc_49020d;

loc_49020d:
    eax = eax - 0x1;
    if (eax < 0x0) {
            temp_1 = 0x0;
            break;
    }
    else {
            if (ecx != 0x0) {
                    ecx = ebp + (eax * 0x4 - 0x20);
                    edx = *ecx;
                    esi = edx + 0x1;
                    edi = 0x0;
                    if (esi < edx || esi < 0x1) {
                            edi = 0x1;
                    }
                    *ecx = esi;
                    ecx = edi;
                    continue;
            }
            temp_1 = 0x1;
            break;
    }
    goto .l2;

.l2:
    goto loc_490210;
}
