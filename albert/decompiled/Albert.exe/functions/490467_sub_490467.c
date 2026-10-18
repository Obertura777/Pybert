// sub_490467 @ 0x490467
// hopper name: sub_490467
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_490467() {
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
    if (ebx != 0xffffc001) goto loc_4904d1;
    goto loc_4904aa;

loc_4904d1:
    arg_0 = arg_0 & 0x0;
    esp = esp - 0x4;
    decomp_var_38 = esi;
    var_2C = var_20;
    var_2C = var_20;
    var_2C = var_20;
    esi = *dword_4c9f9c;
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
    bool_58 = eax != 0x0;
    var_8 = ecx;
    if (eax == 0x0) goto loc_4905af;
    goto loc_490522;

loc_4904aa:
    eax = 0x0;
    while (true) {
            ebx = 0x0;
            bool_39 = true;
            bool_38 = true;
            bool_37 = true;
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
    goto loc_490966;

loc_4905af:
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
    ecx = *dword_4c9f98 - *dword_4c9f9c;
    bool_12 = true;
    bool_11 = true;
    bool_10 = true;
    if (ebx >= ecx) goto loc_4905f4;
    goto loc_4905e7;

loc_490522:
    eax = var_C;
    while (true) {
            if (bool_58) {
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
    if (temp_2 == 0x0) goto loc_4905af;
    goto loc_49055b;

loc_490966:
    esp = (esp - 0x4) + 0x4;
    ebx = ebx << 0x1f - *dword_4c9fa0;
    ebx = ebx | -var_14 - -var_14 + CARRY(EFLAGS(cf)) & 0x80000000 | var_20;
    if (*dword_4c9fa4 == 0x40) {
            arg_4[0x1] = ebx;
            *arg_4 = var_1C;
    }
    else {
            if (*dword_4c9fa4 == 0x20) {
                    *arg_4 = ebx;
            }
    }
    return eax;

loc_4905f4:
    eax = *dword_4c9f98;
    bool_16 = true;
    bool_15 = true;
    if (ebx > eax) goto loc_49080b;
    goto loc_4905fc;

loc_4905e7:
    eax = 0x0;
    edi = &var_20;
    asm { stosd      dword [edi], eax };
    asm { stosd      dword [edi], eax };
    asm { stosd      dword [edi], eax };
    goto loc_490801;

loc_49055b:
    var_4 = var_4 & 0x0;
    edx = 0x1 << ecx - esi;
    ecx = ebp + (eax * 0x4 - 0x20);
    arg_0 = *ecx + edx;
    esi = *ecx;
    bool_34 = arg_0 >= esi;
    if (arg_0 < esi || !bool_34) goto loc_49059a;
    goto loc_4905a1;
    return eax;

loc_49080b:
    bool_28 = true;
    bool_27 = true;
    bool_26 = true;
    if (ebx >= *dword_4c9f94) {
            ecx = *dword_4c9fa0;
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
            ebx = *dword_4c9fa8 + *dword_4c9f94;
            eax = 0x1;
    }
    else {
            ecx = *dword_4c9fa0;
            var_20 = var_20 & 0x7fffffff;
            ebx = ebx + *dword_4c9fa8;
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
    goto loc_490965;

loc_4905fc:
    eax = *dword_4c9f98;
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
    esi = *dword_4c9f9c;
    esi = esi - 0x1;
    eax = SAR(esi + 0x1 + ((esi + 0x1 & 0x80000000 ? 0xffffffff : 0x0) & 0x1f), 0x5);
    edx = esi + 0x1 & 0x8000001f;
    var_C = eax;
    if (edx < 0x0) {
            edx = (edx - 0x1 | 0xffffffe0) + 0x1;
    }
    esp = (esp - 0x4) + 0x4;
    ecx = 0x1f - edx;
    bool_47 = 0x1 << ecx != 0x0;
    ebx = ebp + (eax * 0x4 - 0x20);
    var_10 = ecx;
    if (0x1 << ecx == 0x0) goto loc_490752;
    goto loc_4906d0;

loc_490801:
    ebx = 0x0;
    eax = 0x2;
    esp = (esp - 0x4) + 0x4;
    goto loc_490965;

loc_49059a:
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
                                    bool_57 = edx + 0x1 >= edx;
                                    arg_0 = edx + 0x1;
                                    if (edx + 0x1 >= edx) {
                                            if (bool_57) {
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

loc_4905a1:
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
                            bool_45 = esi >= edx;
                            arg_0 = esi;
                            if (esi >= edx) {
                                    if (bool_45) {
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
                                            bool_66 = esi >= edx;
                                            arg_0 = esi;
                                            if (esi >= edx) {
                                                    if (bool_66) {
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
    goto loc_4905af;

loc_490965:
    esp = esp + 0x4;
    goto loc_490966;

loc_490752:
    *ebx = *ebx & (eax | 0xffffffff) << var_10;
    eax = var_C + 0x1;
    bool_19 = true;
    if (eax < 0x3) {
            esp = (esp - 0x4) + 0x4;
            edi = ebp + (eax * 0x4 - 0x20);
            asm { rep stosd  dword [edi], eax };
    }
    ecx = *dword_4c9fa0;
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
    goto loc_490801;

loc_4906d0:
    while (true) {
            if (bool_47) {
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
    if (temp_3 == 0x0) goto loc_490752;

loc_490706:
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
    goto loc_49074f;

loc_49074f:
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
    goto loc_490752;
}
