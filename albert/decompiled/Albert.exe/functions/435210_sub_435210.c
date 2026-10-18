// sub_435210 @ 0x435210
// hopper name: sub_435210
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_84a29276878deed2f6f82f4902efd1af3068bd2f0c5f74171e6c8513865ea0d2
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_435210() {
    &decomp_var_4 = &decomp_var_4 & 0xfffffff8;
    decomp_var_14 = ecx;
    sub_47bf20();
    decomp_var_1c = ebp;
    decomp_var_24 = edi;
    esp = esp - 0x24;
    decomp_var_28 = *dword_4c8db8 ^ &decomp_var_24;
    *0x0 = &arg_bd64;
    esi = ecx;
    decomp_var_10 = esi;
    arg_1c = *(int8_t *)(esi[0x2] + 0x2424) & 0xff;
    eax = sub_47020b();
    if (eax != 0x0) goto loc_435278;
    goto loc_43526e;

loc_435278:
    decomp_var_8 = (*(*eax + 0xc))() + 0x10;
    edx = esi[0x2];
    esi = edx[0x901];
    decomp_var_c = 0x0;
    if (esi > 0x0) {
            eax = arg_1c * 0xa8 + 0x4d5528;
            decomp_var_14 = eax;
            ebp = 0x0;
            while (true) {
                    bool_310 = eax[0x1] < 0x0;
                    bool_309 = eax[0x1] > 0x0;
                    ecx = *eax;
                    *(&decomp_var_28 + decomp_var_c * 0x4 + 0x7c) = ecx;
                    if (!bool_309) {
                            if (!bool_310) {
                                    bool_308 = true;
                                    bool_307 = true;
                                    bool_306 = true;
                            }
                    }
                    decomp_var_14 = decomp_var_14 + 0x8;
                    eax = 0x0;
                    asm { rep stosd  dword [edi], eax };
                    asm { rep stosd  dword [edi], eax };
                    asm { rep stosd  dword [edi], eax };
                    ebp = &arg_50;
                    bool_305 = decomp_var_c + 0x1 < esi;
                    decomp_var_c = decomp_var_c + 0x1;
                    if (!bool_305) {
                            break;
                    }
                    eax = decomp_var_14;
            }
    }
    decomp_var_c = 0x0;
    if (esi <= 0x0) goto loc_435889;
    goto loc_43534a;

loc_43526e:
    eax = sub_40b5a0(0x80004005);
    return eax;

loc_435889:
    ebp = arg_1c;
    ebx = 0x0;
    if (*(decomp_var_10[0x2] + 0x2404) <= 0x0) goto loc_4359cb;
    goto loc_4358a2;

loc_43534a:
    goto loc_435350;

loc_4359cb:
    if (*dword_baed64 != 0x1) goto .l26;
    goto loc_4359d8;

loc_4358a2:
    while (true) {
            if (ebx == ebp) {
                    edx = decomp_var_24[0x2];
                    ebx = ebx + 0x1;
                    if (ebx < edx[0x901]) {
                            continue;
                    }
                    temp_4 = 0x1;
                    break;
            }
            esp = esp - 0x4;
            decomp_var_14 = ebx & 0xff | 0x4100;
            sub_46db50();
            eax = sub_4273a0(decomp_var_2c);
            if (eax[0x6] >= 0x10) {
                    ecx = eax[0x1];
            }
            else {
                    ecx = eax + 0x4;
            }
            decomp_var_2c = *(&decomp_var_28 + ebp * 0x15 + ebx + ebp * 0x15 + ebx + ebp * 0x15 + ebx + ebp * 0x15 + ebx + 0x7bc);
            decomp_var_30 = *(&decomp_var_28 + ebp * 0x15 + ebx + ebp * 0x15 + ebx + ebp * 0x15 + ebx + ebp * 0x15 + ebx + 0xd4);
            decomp_var_34 = ecx;
            decomp_var_38 = "Our Moves Analysis shows (%s) moved %d units of %d to pressuring provinces";
            decomp_var_3c = &decomp_var_8;
            sub_410c10(decomp_var_3c, "Our Moves Analysis shows (%s) moved %d units of %d to pressuring provinces", decomp_var_34);
            eax = *(**(decomp_var_8 - 0x10) + 0x10);
            esi = decomp_var_8 - 0x10;
            esp = (esp - 0x14) + 0x14;
            eax = (eax)();
            edx = esi + 0xc;
            if (esi[0x3] >= 0x0) {
                    if (eax == *esi) {
                            edi = esi;
                            *edx = lock intrinsic_xadd(*edx, 0x1);
                            decomp_var_8 = edi + 0x10;
                            decomp_var_40 = &decomp_var_c;
                            esp = esp - 0x8;
                            decomp_var_44 = &arg_18;
                            sub_419e60(decomp_var_44, decomp_var_40, decomp_var_3c);
                            eax = edi + 0x10 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            if (edx <= 0x1) {
                                    esp = esp - 0x4;
                                    decomp_var_40 = eax;
                                    (*(**eax + 0x4))(decomp_var_40);
                            }
                            edx = decomp_var_24[0x2];
                            ebx = ebx + 0x1;
                            if (ebx < edx[0x901]) {
                                    continue;
                            }
                            temp_4 = 0x1;
                            break;
                    }
                    else {
                            ecx = esi[0x1];
                            edx = *eax;
                            edx = *edx;
                            decomp_var_40 = 0x1;
                            esp = esp - 0x8;
                            decomp_var_44 = ecx;
                            edi = (edx)(decomp_var_44, 0x1);
                            if (edi != 0x0) {
                                    edi[0x1] = esi[0x1];
                                    eax = esi[0x1];
                                    decomp_var_48 = eax + 0x1;
                                    decomp_var_4c = edi + 0x10;
                                    sub_47a5af(decomp_var_4c, decomp_var_48, esi + 0x10, eax + 0x1);
                                    esp = (esp - 0x10) + 0x10;
                                    decomp_var_8 = edi + 0x10;
                                    decomp_var_40 = &decomp_var_c;
                                    esp = esp - 0x8;
                                    decomp_var_44 = &arg_18;
                                    sub_419e60(decomp_var_44, decomp_var_40, decomp_var_3c);
                                    eax = edi + 0x10 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            decomp_var_40 = eax;
                                            (*(**eax + 0x4))(decomp_var_40);
                                    }
                                    edx = decomp_var_24[0x2];
                                    ebx = ebx + 0x1;
                                    if (ebx < edx[0x901]) {
                                            continue;
                                    }
                                    temp_4 = 0x1;
                                    break;
                            }
                            else {
                                    temp_4 = 0x0;
                                    break;
                            }
                    }
            }
            else {
                    ecx = esi[0x1];
                    edx = *eax;
                    edx = *edx;
                    decomp_var_40 = 0x1;
                    esp = esp - 0x8;
                    decomp_var_44 = ecx;
                    edi = (edx)(decomp_var_44, 0x1);
                    if (edi != 0x0) {
                            edi[0x1] = esi[0x1];
                            eax = esi[0x1];
                            decomp_var_48 = eax + 0x1;
                            decomp_var_4c = edi + 0x10;
                            sub_47a5af(decomp_var_4c, decomp_var_48, esi + 0x10, eax + 0x1);
                            esp = (esp - 0x10) + 0x10;
                            decomp_var_8 = edi + 0x10;
                            decomp_var_40 = &decomp_var_c;
                            esp = esp - 0x8;
                            decomp_var_44 = &arg_18;
                            sub_419e60(decomp_var_44, decomp_var_40, decomp_var_3c);
                            eax = edi + 0x10 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            if (edx <= 0x1) {
                                    esp = esp - 0x4;
                                    decomp_var_40 = eax;
                                    (*(**eax + 0x4))(decomp_var_40);
                            }
                            edx = decomp_var_24[0x2];
                            ebx = ebx + 0x1;
                            if (ebx < edx[0x901]) {
                                    continue;
                            }
                            temp_4 = 0x1;
                            break;
                    }
                    else {
                            temp_4 = 0x0;
                            break;
                    }
            }
    }
    if (temp_4 == 0x0) goto j_sub_40b6d0_436378;
    goto .l37;

loc_435350:
    decomp_var_14 = 0x0;
    if (esi <= 0x0) goto loc_435869;
    goto loc_435360;

.l26:
    eax = decomp_var_38 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            decomp_var_5c = eax;
            eax = *(**eax + 0x4);
            eax = (eax)(decomp_var_5c);
    }
    *0x0 = arg_bd34;
    &decomp_var_44 = decomp_var_4c;
    return eax;

loc_4359d8:
    if (*(int8_t *)byte_baed68 != 0x0) goto .l8;
    goto loc_4359e5;

j_sub_40b6d0_436378:
    eax = sub_40b6d0();
    return eax;

.l37:
    if (*dword_baed64 != 0x1) goto .l38;
    goto .l18;

loc_435869:
    edx = decomp_var_10[0x2];
    esi = edx[0x901];
    bool_362 = decomp_var_c + 0x1 < esi;
    decomp_var_c = decomp_var_c + 0x1;
    if (bool_362) {
            continue;
    }
    break;

loc_435360:
    eax = edx[0x900];
    bool_367 = true;
    if (eax > 0x0) {
            *(&decomp_var_28 + (decomp_var_c << 0xb) + 0x158c) = 0x0;
            *(&decomp_var_28 + (decomp_var_c << 0xb) + 0x1590) = 0x0;
            *(&decomp_var_28 + (decomp_var_c << 0xb) + 0x1594) = *(&decomp_var_28 + (decomp_var_c << 0xb) + 0x158c);
    }
    arg_0 = 0x0;
    if (eax <= 0x0) goto loc_4354af;
    goto loc_43539a;

.l8:
    eax = decomp_var_38 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            decomp_var_5c = eax;
            eax = *(**eax + 0x4);
            eax = (eax)(decomp_var_5c);
    }
    *0x0 = arg_bd34;
    &decomp_var_44 = decomp_var_4c;
    return eax;

loc_4359e5:
    eax = decomp_var_24[0x2];
    if (*(int16_t *)word_4c6ccc != eax[0x1225]) goto .l27;
    goto loc_435a00;

.l38:
    eax = decomp_var_38 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            decomp_var_5c = eax;
            eax = *(**eax + 0x4);
            eax = (eax)(decomp_var_5c);
    }
    *0x0 = arg_bd34;
    &decomp_var_44 = decomp_var_4c;
    return eax;

.l18:
    if (*(int8_t *)byte_baed68 != 0x0) goto .l24;
    goto .l12;

loc_4354af:
    esi = arg_4 + 0x248c;
    ebx = *arg_4[0x924];
    arg_14 = esi;
    arg_18 = ebx;
    goto loc_4354d0;

loc_43539a:
    ecx = 0x0;
    decomp_var_4 = 0x0;
    ebp = &arg_2a18;
    goto loc_4353b0;

.l27:
    eax = decomp_var_38 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            decomp_var_5c = eax;
            eax = *(**eax + 0x4);
            eax = (eax)(decomp_var_5c);
    }
    *0x0 = arg_bd34;
    &decomp_var_44 = decomp_var_4c;
    return eax;

loc_435a00:
    eax = eax[0x901];
    edi = decomp_var_24;
    edx = 0x0;
    if (eax <= 0x0) goto loc_435a6f;
    goto loc_435a10;

.l24:
    eax = decomp_var_38 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            decomp_var_5c = eax;
            eax = *(**eax + 0x4);
            eax = (eax)(decomp_var_5c);
    }
    *0x0 = arg_bd34;
    &decomp_var_44 = decomp_var_4c;
    return eax;

.l12:
    eax = decomp_var_24[0x2];
    if (*(int16_t *)word_4c6ccc != eax[0x1225]) goto .l11;
    goto .l19;

loc_4354d0:
    edi = arg_4[0x924];
    eax = arg_4 + 0x248c;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (ebx == edi) goto .l73;
    goto loc_4354f3;

loc_4353b0:
    if (*(int8_t *)(ecx + edx + 0x3) == 0x0) goto loc_435487;
    goto loc_4353bb;

loc_435a6f:
    eax = *(edi[0x2] + 0x2404);
    decomp_var_20 = 0x0;
    if (eax <= 0x0) goto .l5;
    goto loc_435a86;

loc_435a10:
    esi = 0x0;
    goto loc_435a17;

.l11:
    eax = decomp_var_38 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            decomp_var_5c = eax;
            eax = *(**eax + 0x4);
            eax = (eax)(decomp_var_5c);
    }
    *0x0 = arg_bd34;
    &decomp_var_44 = decomp_var_4c;
    return eax;

.l19:
    eax = eax[0x901];
    edi = decomp_var_24;
    edx = 0x0;
    if (eax <= 0x0) goto .l20;
    goto .l21;

.l73:
    break;

loc_4354f3:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (ebx == esi[0x1]) {
            sub_47a948();
    }
    if (ebx[0x6] != decomp_var_14) {
            sub_401390();
            esi = arg_14;
            ebx = arg_18;
            continue;
    }
    esi = arg_18;
    edi = arg_14;
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_2c = arg_18 + 0x14;
    ebx = sub_4075b0(decomp_var_2c, decomp_var_28);
    edi = *ebx[0x1];
    ebp = ebx;
    arg_c = ebp;
    arg_10 = edi;
    goto loc_435560;

loc_435487:
    edx = decomp_var_10[0x2];
    ecx = ecx + 0x24;
    ebp = &arg_8;
    bool_368 = arg_0 + 0x1 < edx[0x900];
    arg_0 = arg_0 + 0x1;
    decomp_var_4 = ecx;
    if (bool_368) {
            continue;
    }
    break;

loc_4353bb:
    edx = *(int16_t *)(ecx + edx + 0x20);
    eax = edx & 0xff;
    if (HIBYTE(edx) != 0x41) {
            eax = 0x14;
    }
    if (eax != decomp_var_c) goto loc_435487;
    goto loc_4353d7;

.l5:
    edx = *(edi[0x2] + 0x2404);
    ecx = 0x0;
    if (edx <= 0x0) goto .l2;
    goto .l6;

loc_435a86:
    ecx = 0x0;
    asm { fld        dword [aSeemsSAndSHave+60] };
    decomp_var_10 = ecx;
    asm { fldz };
    goto loc_435a92;

loc_435a17:
    if (edx != ebp) {
            ecx = 0x0;
            if (eax > 0x0) {
                    if (edx != ecx) {
                            eax = esi + ecx;
                            bool_281 = *(eax * 0x8 + 0x4d552c) > 0x0;
                            bool_279 = *(eax * 0x8 + 0x4d552c) < 0x0;
                            if (!bool_281) {
                                    if (bool_279 || *(eax * 0x8 + 0x4d5528) < 0x5) {
                                            *(eax * 0x8 + 0x4d5528) = 0x1;
                                            *(eax * 0x8 + 0x4d552c) = 0x0;
                                    }
                            }
                    }
                    ecx = ecx + 0x1;
                    if (ecx < *(edi[0x2] + 0x2404)) {
                            continue;
                    }
                    break;
            }
    }
    eax = *(edi[0x2] + 0x2404);
    edx = edx + 0x1;
    esi = esi + 0x15;
    if (edx < eax) {
            continue;
    }
    break;

.l20:
    eax = *(edi[0x2] + 0x2404);
    decomp_var_20 = 0x0;
    if (eax <= 0x0) goto .l22;
    goto .l13;

.l21:
    esi = 0x0;
    goto .l44;
    edx = arg_4;
    bool_366 = decomp_var_14 + 0x1 < edx[0x901];
    decomp_var_14 = decomp_var_14 + 0x1;
    if (bool_366) {
            continue;
    }
    break;

loc_435560:
    esi = ebx[0x1];
    if (ebp == 0x0 || ebp != ebx) {
            sub_47a948();
    }
    if (edi != esi) {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (edi == arg_0) {
                    sub_47a948();
            }
            eax = edi[0x3];
            esi = decomp_var_c << 0x8;
            eax = eax + esi;
            if (*(&decomp_var_28 + eax * 0x8 + 0x158c) == 0x1 && *(&decomp_var_28 + eax * 0x8 + 0x1590) == 0x0) {
                    if (edi == arg_0) {
                            sub_47a948();
                    }
                    eax = edi[0x3];
                    *(&decomp_var_28 + (eax + esi) * 0x8 + 0x158c) = 0x2;
                    *(&decomp_var_28 + (eax + esi) * 0x8 + 0x1590) = 0x0;
            }
            sub_40f400();
            edi = arg_10;
            ebp = arg_c;
            continue;
    }
    break;

loc_4353d7:
    edi = ebp;
    esi = *arg_0;
    arg_20 = edi;
    arg_24 = esi;
    goto loc_4353e8;

.l2:
    if (decomp_var_22 == 0x1) {
            ecx = 0x0;
            if (edx > 0x0) {
                    while (true) {
                            if (*(&decomp_var_4c + ecx * 0x4 + 0x7c) >= 0x2) {
                                    ecx = ecx + 0x1;
                                    if (ecx < edx) {
                                            continue;
                                    }
                                    temp_5 = 0x0;
                                    break;
                            }
                            if (ecx != ebp) {
                                    eax = *(&decomp_var_4c + ecx * 0x4 + 0x7c);
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d5528) = eax;
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d552c) = eax & 0x80000000 ? 0xffffffff : 0x0;
                                    temp_5 = 0x1;
                                    break;
                            }
                            ecx = ecx + 0x1;
                            if (ecx < edx) {
                                    continue;
                            }
                            temp_5 = 0x0;
                            break;
                    }
            }
    }
    goto .l3;

.l6:
    eax = ebp * 0xa8 + 0x4d5528;
    goto .l40;

loc_435a92:
    ebx = 0x0;
    if (eax <= 0x0) goto loc_435f6c;
    goto loc_435a9c;

.l22:
    edx = *(edi[0x2] + 0x2404);
    ecx = 0x0;
    if (edx <= 0x0) goto .l28;
    goto .l23;

.l13:
    ecx = 0x0;
    asm { fld        dword [aSeemsSAndSHave+60] };
    decomp_var_10 = ecx;
    asm { fldz };
    goto .l48;

.l44:
    if (edx != ebp) {
            ecx = 0x0;
            if (eax > 0x0) {
                    if (edx != ecx) {
                            eax = esi + ecx;
                            bool_478 = *(eax * 0x8 + 0x4d552c) < 0x0;
                            if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                    if (bool_478 || *(eax * 0x8 + 0x4d5528) < 0x5) {
                                            *(eax * 0x8 + 0x4d5528) = 0x1;
                                            *(eax * 0x8 + 0x4d552c) = 0x0;
                                    }
                            }
                    }
                    ecx = ecx + 0x1;
                    if (ecx < *(edi[0x2] + 0x2404)) {
                            continue;
                    }
                    break;
            }
    }
    eax = *(edi[0x2] + 0x2404);
    edx = edx + 0x1;
    esi = esi + 0x15;
    if (edx < eax) {
            continue;
    }
    break;
    ebp = *ebx[0x1];
    edi = decomp_var_c;
    esi = ebx;
    arg_c = esi;
    arg_10 = ebp;
    goto loc_4355f2;

loc_4353e8:
    ebx = arg_0;
    if (edi == 0x0 || edi != ebp) {
            sub_47a948();
    }
    if (esi != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            ecx = decomp_var_10[0x2];
            if (*(int8_t *)(ecx + (eax + eax * 0x8) * 0x4 + 0x3) == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = (decomp_var_c << 0x8) + esi[0x3];
                    *(&decomp_var_28 + eax * 0x8 + 0x158c) = 0x1;
                    *(&decomp_var_28 + eax * 0x8 + 0x1590) = 0x0;
                    sub_401520();
                    esi = arg_24;
                    edi = arg_20;
                    continue;
            }
            ecx = *(int16_t *)(decomp_var_4 + ecx + 0x20);
            eax = ecx & 0xff;
            if (HIBYTE(ecx) != 0x41) {
                    eax = 0x14;
            }
            if (eax != decomp_var_14) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = (decomp_var_c << 0x8) + esi[0x3];
                    *(&decomp_var_28 + eax * 0x8 + 0x158c) = 0x1;
                    *(&decomp_var_28 + eax * 0x8 + 0x1590) = 0x0;
                    sub_401520();
                    esi = arg_24;
                    edi = arg_20;
                    continue;
            }
            sub_401520();
            esi = arg_24;
            edi = arg_20;
            continue;
    }
    break;

.l3:
    edx = *dword_4c6bc4;
    eax = ebp * 0x15;
    ecx = eax + *dword_4c6bc4;
    bool_84 = *(ecx * 0x8 + 0x4d552c) < 0x0;
    if (*(ecx * 0x8 + 0x4d552c) <= 0x0 && (bool_84 || *(ecx * 0x8 + 0x4d5528) < 0x2)) {
            edx = *dword_4c6bc4;
            edx = edx | 0xffffffff;
            *dword_4c6bc4 = edx;
    }
    ecx = *dword_4c6bc8;
    esi = eax + *dword_4c6bc8;
    bool_91 = *(esi * 0x8 + 0x4d552c) > 0x0;
    bool_73 = *(esi * 0x8 + 0x4d552c) < 0x0;
    if (!bool_91 && (bool_73 || *(esi * 0x8 + 0x4d5528) < 0x2)) {
            ecx = *dword_4c6bc8;
            ecx = ecx | 0xffffffff;
            *dword_4c6bc8 = ecx;
    }
    esi = *dword_4c6bcc;
    eax = eax + *dword_4c6bcc;
    bool_87 = *(eax * 0x8 + 0x4d552c) > 0x0;
    bool_86 = *(eax * 0x8 + 0x4d552c) < 0x0;
    if (!bool_87 && (bool_86 || *(eax * 0x8 + 0x4d5528) < 0x2)) {
            esi = *dword_4c6bcc;
            esi = esi | 0xffffffff;
            *dword_4c6bcc = esi;
    }
    bool_246 = edx != 0xffffffff;
    if (edx == 0xffffffff) {
            bool_70 = ecx != edx;
            if (ecx > edx) {
                    edx = ecx;
                    ecx = ecx | 0xffffffff;
                    *dword_4c6bc4 = edx;
                    *dword_4c6bc8 = ecx;
                    if (esi > 0xffffffff) {
                            ecx = esi;
                            esi = esi | 0xffffffff;
                            *dword_4c6bc8 = ecx;
                            *dword_4c6bcc = esi;
                    }
            }
            else {
                    if (!bool_70 && esi > 0xffffffff) {
                            ecx = esi;
                            esi = esi | 0xffffffff;
                            *dword_4c6bc8 = ecx;
                            *dword_4c6bcc = esi;
                    }
            }
    }
    else {
            if (!bool_246 && esi > 0xffffffff) {
                    ecx = esi;
                    esi = esi | 0xffffffff;
                    *dword_4c6bc8 = ecx;
                    *dword_4c6bcc = esi;
            }
    }
    bool_74 = edx <= 0xffffffff;
    if (edx == 0xffffffff) {
            if (ecx == edx) {
                    bool_10 = esi <= edx;
                    if (esi > edx) {
                            edx = esi;
                            *dword_4c6bc4 = edx;
                            *dword_4c6bcc = 0xffffffff;
                            if (!bool_10) {
                                    ebx = 0x0;
                                    if (*(decomp_var_34[0x2] + 0x2404) > 0x0) {
                                            while (true) {
                                                    if (ebx == ebp) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    if (ebx == edx) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    eax = edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx;
                                                    ecx = *(&decomp_var_4c + eax + 0xd4);
                                                    if (ecx <= 0x1) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    if (ecx != *(&decomp_var_4c + eax + 0x7bc)) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    esp = esp - 0x4;
                                                    decomp_var_38 = edx & 0xff | 0x4100;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_50);
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    decomp_var_50 = eax;
                                                    decomp_var_54 = "It would seem our best ally (%s) has been severely pressured by another power ";
                                                    decomp_var_58 = &decomp_var_2c;
                                                    sub_410c10(decomp_var_58, "It would seem our best ally (%s) has been severely pressured by another power ", decomp_var_50);
                                                    edx = **(decomp_var_2c - 0x10);
                                                    eax = edx[0x4];
                                                    esi = decomp_var_2c - 0x10;
                                                    esp = (esp - 0xc) + 0xc;
                                                    eax = (eax)();
                                                    ecx = esi + 0xc;
                                                    if (esi[0x3] >= 0x0) {
                                                            if (eax == *esi) {
                                                                    edi = esi;
                                                                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
                                                                    esp = esp - 0x8;
                                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                                    eax = edi + 0x10 - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            (*(**eax + 0x4))(eax);
                                                                    }
                                                                    edx = *dword_4c6bc4;
                                                                    *(int8_t *)byte_baed45 = 0x1;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                            continue;
                                                                    }
                                                                    temp_3 = 0x0;
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = esi[0x1];
                                                                    edx = *eax;
                                                                    edx = *edx;
                                                                    esp = esp - 0x8;
                                                                    edi = (edx)(ecx, 0x1);
                                                                    if (edi != 0x0) {
                                                                            edi[0x1] = esi[0x1];
                                                                            eax = esi[0x1];
                                                                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            esp = esp - 0x8;
                                                                            eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                                            eax = edi + 0x10 - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    (*(**eax + 0x4))(eax);
                                                                            }
                                                                            edx = *dword_4c6bc4;
                                                                            *(int8_t *)byte_baed45 = 0x1;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                                    continue;
                                                                            }
                                                                            temp_3 = 0x0;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_3 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            ecx = esi[0x1];
                                                            edx = *eax;
                                                            edx = *edx;
                                                            esp = esp - 0x8;
                                                            edi = (edx)(ecx, 0x1);
                                                            if (edi != 0x0) {
                                                                    edi[0x1] = esi[0x1];
                                                                    eax = esi[0x1];
                                                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                                    esp = (esp - 0x10) + 0x10;
                                                                    esp = esp - 0x8;
                                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                                    eax = edi + 0x10 - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            (*(**eax + 0x4))(eax);
                                                                    }
                                                                    edx = *dword_4c6bc4;
                                                                    *(int8_t *)byte_baed45 = 0x1;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                            continue;
                                                                    }
                                                                    temp_3 = 0x0;
                                                                    break;
                                                            }
                                                            else {
                                                                    temp_3 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            if (temp_3 != 0x0) {
                                                    eax = sub_40b6d0();
                                            }
                                            else {
                                                    ebx = decomp_var_40;
                                                    esi = *(ebx[0x2] + 0x2404);
                                                    if (esi > 0x0) {
                                                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                                    }
                                                    else {
                                                            if (*(int8_t *)byte_baed43 == 0x1) {
                                                                    edx = 0x0;
                                                                    ecx = 0x0;
                                                                    if (esi > 0x0) {
                                                                            eax = &arg_4d5524;
                                                                            do {
                                                                                    if (*eax == 0x3) {
                                                                                            edx = 0x0;
                                                                                            if (eax[0x1] == 0x0) {
                                                                                                    edx = 0x0;
                                                                                                    *eax = 0x1;
                                                                                                    eax[0x1] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = ecx + 0x1;
                                                                                    eax = eax + 0x8;
                                                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                                                    }
                                                            }
                                                            eax = decomp_var_38 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    decomp_var_5c = eax;
                                                                    eax = *(**eax + 0x4);
                                                                    eax = (eax)(decomp_var_5c);
                                                            }
                                                            *0x0 = arg_bd34;
                                                            &decomp_var_44 = decomp_var_4c;
                                                    }
                                            }
                                    }
                                    else {
                                            ebx = decomp_var_40;
                                            esi = *(ebx[0x2] + 0x2404);
                                            if (esi > 0x0) {
                                                    eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                            }
                                            else {
                                                    if (*(int8_t *)byte_baed43 == 0x1) {
                                                            edx = 0x0;
                                                            ecx = 0x0;
                                                            if (esi > 0x0) {
                                                                    eax = &arg_4d5524;
                                                                    do {
                                                                            if (*eax == 0x3) {
                                                                                    edx = 0x0;
                                                                                    if (eax[0x1] == 0x0) {
                                                                                            edx = 0x0;
                                                                                            *eax = 0x1;
                                                                                            eax[0x1] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = ecx + 0x1;
                                                                            eax = eax + 0x8;
                                                                    } while (ecx < *(ebx[0x2] + 0x2404));
                                                            }
                                                    }
                                                    eax = decomp_var_38 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            decomp_var_5c = eax;
                                                            eax = *(**eax + 0x4);
                                                            eax = (eax)(decomp_var_5c);
                                                    }
                                                    *0x0 = arg_bd34;
                                                    &decomp_var_44 = decomp_var_4c;
                                            }
                                    }
                            }
                            else {
                                    ebx = decomp_var_40;
                                    esi = *(ebx[0x2] + 0x2404);
                                    if (esi > 0x0) {
                                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                    }
                                    else {
                                            if (*(int8_t *)byte_baed43 == 0x1) {
                                                    edx = 0x0;
                                                    ecx = 0x0;
                                                    if (esi > 0x0) {
                                                            eax = &arg_4d5524;
                                                            do {
                                                                    if (*eax == 0x3) {
                                                                            edx = 0x0;
                                                                            if (eax[0x1] == 0x0) {
                                                                                    edx = 0x0;
                                                                                    *eax = 0x1;
                                                                                    eax[0x1] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = ecx + 0x1;
                                                                    eax = eax + 0x8;
                                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                                    }
                                            }
                                            eax = decomp_var_38 - 0x10;
                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                            if (edx <= 0x1) {
                                                    esp = esp - 0x4;
                                                    decomp_var_5c = eax;
                                                    eax = *(**eax + 0x4);
                                                    eax = (eax)(decomp_var_5c);
                                            }
                                            *0x0 = arg_bd34;
                                            &decomp_var_44 = decomp_var_4c;
                                    }
                            }
                    }
                    else {
                            ebx = decomp_var_40;
                            esi = *(ebx[0x2] + 0x2404);
                            if (esi > 0x0) {
                                    eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                            }
                            else {
                                    if (*(int8_t *)byte_baed43 == 0x1) {
                                            edx = 0x0;
                                            ecx = 0x0;
                                            if (esi > 0x0) {
                                                    eax = &arg_4d5524;
                                                    do {
                                                            if (*eax == 0x3) {
                                                                    edx = 0x0;
                                                                    if (eax[0x1] == 0x0) {
                                                                            edx = 0x0;
                                                                            *eax = 0x1;
                                                                            eax[0x1] = 0x0;
                                                                    }
                                                            }
                                                            ecx = ecx + 0x1;
                                                            eax = eax + 0x8;
                                                    } while (ecx < *(ebx[0x2] + 0x2404));
                                            }
                                    }
                                    eax = decomp_var_38 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            decomp_var_5c = eax;
                                            eax = *(**eax + 0x4);
                                            eax = (eax)(decomp_var_5c);
                                    }
                                    *0x0 = arg_bd34;
                                    &decomp_var_44 = decomp_var_4c;
                            }
                    }
            }
            else {
                    ebx = decomp_var_40;
                    esi = *(ebx[0x2] + 0x2404);
                    if (esi > 0x0) {
                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                    }
                    else {
                            if (*(int8_t *)byte_baed43 == 0x1) {
                                    edx = 0x0;
                                    ecx = 0x0;
                                    if (esi > 0x0) {
                                            eax = &arg_4d5524;
                                            do {
                                                    if (*eax == 0x3) {
                                                            edx = 0x0;
                                                            if (eax[0x1] == 0x0) {
                                                                    edx = 0x0;
                                                                    *eax = 0x1;
                                                                    eax[0x1] = 0x0;
                                                            }
                                                    }
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x8;
                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                    }
                            }
                            eax = decomp_var_38 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            if (edx <= 0x1) {
                                    esp = esp - 0x4;
                                    decomp_var_5c = eax;
                                    eax = *(**eax + 0x4);
                                    eax = (eax)(decomp_var_5c);
                            }
                            *0x0 = arg_bd34;
                            &decomp_var_44 = decomp_var_4c;
                    }
            }
    }
    else {
            if (!bool_74) {
                    ebx = 0x0;
                    if (*(decomp_var_34[0x2] + 0x2404) > 0x0) {
                            while (true) {
                                    if (ebx == ebp) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    if (ebx == edx) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    eax = edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx;
                                    ecx = *(&decomp_var_4c + eax + 0xd4);
                                    if (ecx <= 0x1) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    if (ecx != *(&decomp_var_4c + eax + 0x7bc)) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    esp = esp - 0x4;
                                    decomp_var_38 = edx & 0xff | 0x4100;
                                    sub_46db50();
                                    eax = sub_4273a0(decomp_var_50);
                                    if (eax[0x6] >= 0x10) {
                                            eax = eax[0x1];
                                    }
                                    else {
                                            eax = eax + 0x4;
                                    }
                                    decomp_var_50 = eax;
                                    decomp_var_54 = "It would seem our best ally (%s) has been severely pressured by another power ";
                                    decomp_var_58 = &decomp_var_2c;
                                    sub_410c10(decomp_var_58, "It would seem our best ally (%s) has been severely pressured by another power ", decomp_var_50);
                                    edx = **(decomp_var_2c - 0x10);
                                    eax = edx[0x4];
                                    esi = decomp_var_2c - 0x10;
                                    esp = (esp - 0xc) + 0xc;
                                    eax = (eax)();
                                    ecx = esi + 0xc;
                                    if (esi[0x3] >= 0x0) {
                                            if (eax == *esi) {
                                                    edi = esi;
                                                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
                                                    esp = esp - 0x8;
                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                    eax = edi + 0x10 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    edx = *dword_4c6bc4;
                                                    *(int8_t *)byte_baed45 = 0x1;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                            continue;
                                                    }
                                                    temp_3 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    ecx = esi[0x1];
                                                    edx = *eax;
                                                    edx = *edx;
                                                    esp = esp - 0x8;
                                                    edi = (edx)(ecx, 0x1);
                                                    if (edi != 0x0) {
                                                            edi[0x1] = esi[0x1];
                                                            eax = esi[0x1];
                                                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                            esp = (esp - 0x10) + 0x10;
                                                            esp = esp - 0x8;
                                                            eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                            eax = edi + 0x10 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    (*(**eax + 0x4))(eax);
                                                            }
                                                            edx = *dword_4c6bc4;
                                                            *(int8_t *)byte_baed45 = 0x1;
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    else {
                                                            temp_3 = 0x1;
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            ecx = esi[0x1];
                                            edx = *eax;
                                            edx = *edx;
                                            esp = esp - 0x8;
                                            edi = (edx)(ecx, 0x1);
                                            if (edi != 0x0) {
                                                    edi[0x1] = esi[0x1];
                                                    eax = esi[0x1];
                                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                    esp = (esp - 0x10) + 0x10;
                                                    esp = esp - 0x8;
                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                    eax = edi + 0x10 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    edx = *dword_4c6bc4;
                                                    *(int8_t *)byte_baed45 = 0x1;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                            continue;
                                                    }
                                                    temp_3 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    temp_3 = 0x1;
                                                    break;
                                            }
                                    }
                            }
                            if (temp_3 != 0x0) {
                                    eax = sub_40b6d0();
                            }
                            else {
                                    ebx = decomp_var_40;
                                    esi = *(ebx[0x2] + 0x2404);
                                    if (esi > 0x0) {
                                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                    }
                                    else {
                                            if (*(int8_t *)byte_baed43 == 0x1) {
                                                    edx = 0x0;
                                                    ecx = 0x0;
                                                    if (esi > 0x0) {
                                                            eax = &arg_4d5524;
                                                            do {
                                                                    if (*eax == 0x3) {
                                                                            edx = 0x0;
                                                                            if (eax[0x1] == 0x0) {
                                                                                    edx = 0x0;
                                                                                    *eax = 0x1;
                                                                                    eax[0x1] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = ecx + 0x1;
                                                                    eax = eax + 0x8;
                                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                                    }
                                            }
                                            eax = decomp_var_38 - 0x10;
                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                            if (edx <= 0x1) {
                                                    esp = esp - 0x4;
                                                    decomp_var_5c = eax;
                                                    eax = *(**eax + 0x4);
                                                    eax = (eax)(decomp_var_5c);
                                            }
                                            *0x0 = arg_bd34;
                                            &decomp_var_44 = decomp_var_4c;
                                    }
                            }
                    }
                    else {
                            ebx = decomp_var_40;
                            esi = *(ebx[0x2] + 0x2404);
                            if (esi > 0x0) {
                                    eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                            }
                            else {
                                    if (*(int8_t *)byte_baed43 == 0x1) {
                                            edx = 0x0;
                                            ecx = 0x0;
                                            if (esi > 0x0) {
                                                    eax = &arg_4d5524;
                                                    do {
                                                            if (*eax == 0x3) {
                                                                    edx = 0x0;
                                                                    if (eax[0x1] == 0x0) {
                                                                            edx = 0x0;
                                                                            *eax = 0x1;
                                                                            eax[0x1] = 0x0;
                                                                    }
                                                            }
                                                            ecx = ecx + 0x1;
                                                            eax = eax + 0x8;
                                                    } while (ecx < *(ebx[0x2] + 0x2404));
                                            }
                                    }
                                    eax = decomp_var_38 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            decomp_var_5c = eax;
                                            eax = *(**eax + 0x4);
                                            eax = (eax)(decomp_var_5c);
                                    }
                                    *0x0 = arg_bd34;
                                    &decomp_var_44 = decomp_var_4c;
                            }
                    }
            }
            else {
                    ebx = decomp_var_40;
                    esi = *(ebx[0x2] + 0x2404);
                    if (esi > 0x0) {
                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                    }
                    else {
                            if (*(int8_t *)byte_baed43 == 0x1) {
                                    edx = 0x0;
                                    ecx = 0x0;
                                    if (esi > 0x0) {
                                            eax = &arg_4d5524;
                                            do {
                                                    if (*eax == 0x3) {
                                                            edx = 0x0;
                                                            if (eax[0x1] == 0x0) {
                                                                    edx = 0x0;
                                                                    *eax = 0x1;
                                                                    eax[0x1] = 0x0;
                                                            }
                                                    }
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x8;
                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                    }
                            }
                            eax = decomp_var_38 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            if (edx <= 0x1) {
                                    esp = esp - 0x4;
                                    decomp_var_5c = eax;
                                    eax = *(**eax + 0x4);
                                    eax = (eax)(decomp_var_5c);
                            }
                            *0x0 = arg_bd34;
                            &decomp_var_44 = decomp_var_4c;
                    }
            }
    }
    return eax;

.l40:
    bool_355 = eax[0x1] < 0x0;
    if (eax[0x1] <= 0x0) {
            if (!bool_355) {
                    if (*eax < 0x2 && ecx != ebp) {
                            decomp_var_21 = 0x1;
                    }
            }
            else {
                    if (ecx != ebp) {
                            decomp_var_21 = 0x1;
                    }
            }
    }
    ecx = ecx + 0x1;
    eax = eax + 0x8;
    if (ecx < edx) {
            continue;
    }
    break;

loc_435f6c:
    eax = *(decomp_var_34[0x2] + 0x2404);
    decomp_var_20 = decomp_var_20 + 0x15;
    ecx = ecx + 0x1;
    decomp_var_30 = ecx;
    if (ecx < eax) {
            continue;
    }
    ebp = decomp_var_4;
    asm { fstp       st1 };
    edi = decomp_var_34;
    asm { fstp       st0 };
    temp_2 = 0x3;
    break;

loc_435a9c:
    decomp_var_4 = ecx * 0x4;
    ebp = 0x0;
    goto loc_435ab0;

.l28:
    if (decomp_var_22 == 0x1) {
            ecx = 0x0;
            if (edx > 0x0) {
                    while (true) {
                            if (*(&decomp_var_4c + ecx * 0x4 + 0x7c) >= 0x2) {
                                    ecx = ecx + 0x1;
                                    if (ecx < edx) {
                                            continue;
                                    }
                                    temp_5 = 0x0;
                                    break;
                            }
                            if (ecx != ebp) {
                                    eax = *(&decomp_var_4c + ecx * 0x4 + 0x7c);
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d5528) = eax;
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d552c) = eax & 0x80000000 ? 0xffffffff : 0x0;
                                    temp_5 = 0x1;
                                    break;
                            }
                            ecx = ecx + 0x1;
                            if (ecx < edx) {
                                    continue;
                            }
                            temp_5 = 0x0;
                            break;
                    }
            }
    }
    goto .l29;

.l23:
    eax = ebp * 0xa8 + 0x4d5528;
    goto .l39;

.l48:
    ebx = 0x0;
    if (eax <= 0x0) goto .l50;
    goto .l49;

loc_4355f2:
    arg_30 = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (ebp != arg_30) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            eax = (edi << 0x8) + arg_8;
            bool_442 = *(&decomp_var_28 + eax * 0x8 + 0x1590) > 0x0;
            bool_438 = *(&decomp_var_28 + eax * 0x8 + 0x1590) < 0x0;
            if (!bool_442) {
                    if (bool_438) {
                            sub_40f400();
                            ebp = arg_10;
                            esi = arg_c;
                            continue;
                    }
                    if (*(&decomp_var_28 + eax * 0x8 + 0x158c) < 0x2) {
                            sub_40f400();
                            ebp = arg_10;
                            esi = arg_c;
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
    goto .l42;
    ecx = decomp_var_4;
    goto loc_435487;
    if (decomp_var_21 == 0x0 && decomp_var_22 == 0x1) {
            ecx = 0x0;
            if (edx > 0x0) {
                    while (true) {
                            if (*(&decomp_var_4c + ecx * 0x4 + 0x7c) >= 0x2) {
                                    ecx = ecx + 0x1;
                                    if (ecx < edx) {
                                            continue;
                                    }
                                    temp_5 = 0x0;
                                    break;
                            }
                            if (ecx != ebp) {
                                    eax = *(&decomp_var_4c + ecx * 0x4 + 0x7c);
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d5528) = eax;
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d552c) = eax & 0x80000000 ? 0xffffffff : 0x0;
                                    temp_5 = 0x1;
                                    break;
                            }
                            ecx = ecx + 0x1;
                            if (ecx < edx) {
                                    continue;
                            }
                            temp_5 = 0x0;
                            break;
                    }
            }
    }
    goto .l3;

.l45:
    if (temp_2 == 0x0) goto .l31;
    goto .l111;

loc_435ab0:
    if (ecx != ebx) {
            ecx = decomp_var_10 + ebx;
            edx = *(&decomp_var_3c + ecx * 0x4 + 0x7bc);
            decomp_var_18 = edx;
            if (edx > 0x0) {
                    asm { fild       dword [esp+ecx*4+0x3c+152] };
                    asm { fidiv      dword [esp+0x3c+-24] };
                    asm { fstp       dword [esp+0x3c+-40] };
            }
            else {
                    asm { fxch       st0, st1 };
                    asm { fst        dword [esp+0x3c+-40] };
                    asm { fxch       st0, st1 };
            }
            ebp = 0x0;
            edi = decomp_var_4;
            eax = *(&decomp_var_3c + edi + 0x7bc);
            decomp_var_18 = eax;
            if (eax > 0x0) {
                    asm { fild       dword [esp+edi+0x3c+152] };
                    asm { fidiv      dword [esp+0x3c+-24] };
                    asm { fstp       dword [esp+0x3c+-24] };
            }
            else {
                    asm { fxch       st0, st1 };
                    asm { fst        dword [esp+0x3c+-24] };
                    asm { fxch       st0, st1 };
            }
            asm { fld        dword [esp+0x3c+-40] };
            asm { fucom      st2 };
            asm { fnstsw     ax };
            asm { fstp       st2 };
            if (PARITY(HIBYTE(eax) & 0x44)) {
                    asm { fld        st0 };
                    asm { fucomp     st2 };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x44)) {
                            ebp = 0x0;
                            *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + 0x1;
                            asm { fstp       st1 };
                            bool_702 = asm { fstp       st1 };
                            asm { fcomp      dword [esp+0x3c+-24] };
                            *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                            asm { fnstsw     ax };
                            if (!PARITY(HIBYTE(eax) & 0x44)) {
                                    ebp = 0x0;
                                    esp = esp - 0x4;
                                    *(ecx * 0x8 + 0x4d5528) = 0x5;
                                    *(ecx * 0x8 + 0x4d552c) = 0x0;
                                    decomp_var_28 = ebx & 0xff | 0x4100;
                                    sub_46db50();
                                    eax = sub_4273a0(decomp_var_40);
                                    if (eax[0x6] >= 0x10) {
                                            esi = eax[0x1];
                                    }
                                    else {
                                            esi = eax + 0x4;
                                    }
                                    esp = esp - 0x4;
                                    decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                    sub_46db50();
                                    eax = sub_4273a0(decomp_var_40);
                                    if (eax[0x6] >= 0x10) {
                                            eax = eax[0x1];
                                    }
                                    else {
                                            eax = eax + 0x4;
                                    }
                                    decomp_var_40 = esi;
                                    decomp_var_44 = eax;
                                    decomp_var_48 = "Seems (%s) and (%s) have applied no pressure to each other";
                                    decomp_var_4c = &decomp_var_1c;
                                    sub_410c10(decomp_var_4c, "Seems (%s) and (%s) have applied no pressure to each other", decomp_var_44);
                                    eax = *(**(decomp_var_1c - 0x10) + 0x10);
                                    esi = decomp_var_1c - 0x10;
                                    esp = (esp - 0x10) + 0x10;
                                    decomp_var_c = 0x2;
                                    eax = (eax)();
                                    edx = esi + 0xc;
                                    if (esi[0x3] >= ebp) {
                                            if (eax == *esi) {
                                                    edi = esi;
                                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                                                    edi = edi + 0x10;
                                                    edx = &decomp_var_1c;
                                                    eax = &arg_8;
                                                    decomp_var_50 = edx;
                                                    esp = esp - 0x8;
                                                    decomp_var_54 = eax;
                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                    eax = edi - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            decomp_var_50 = eax;
                                                            (*(**eax + 0x4))(decomp_var_50);
                                                    }
                                                    esi = 0x1;
                                                    ecx = decomp_var_34;
                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                    edx = ecx[0x2];
                                                    asm { fldz };
                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                    ecx = decomp_var_30;
                                                    ebx = ebx + esi;
                                                    if (ebx < edx[0x901]) {
                                                            continue;
                                                    }
                                                    temp_1 = 0x3;
                                                    break;
                                            }
                                            else {
                                                    decomp_var_50 = 0x1;
                                                    esp = esp - 0x8;
                                                    decomp_var_54 = esi[0x1];
                                                    ecx = eax;
                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                    if (edi != ebp) {
                                                            edi[0x1] = esi[0x1];
                                                            eax = esi[0x1];
                                                            decomp_var_58 = eax + 0x1;
                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                            esp = (esp - 0x10) + 0x10;
                                                            edi = edi + 0x10;
                                                            edx = &decomp_var_1c;
                                                            eax = &arg_8;
                                                            decomp_var_50 = edx;
                                                            esp = esp - 0x8;
                                                            decomp_var_54 = eax;
                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                            eax = edi - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    decomp_var_50 = eax;
                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                            }
                                                            esi = 0x1;
                                                            ecx = decomp_var_34;
                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                            edx = ecx[0x2];
                                                            asm { fldz };
                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                            ecx = decomp_var_30;
                                                            ebx = ebx + esi;
                                                            if (ebx < edx[0x901]) {
                                                                    continue;
                                                            }
                                                            temp_1 = 0x3;
                                                            break;
                                                    }
                                                    else {
                                                            temp_1 = 0x0;
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            decomp_var_50 = 0x1;
                                            esp = esp - 0x8;
                                            decomp_var_54 = esi[0x1];
                                            ecx = eax;
                                            edi = (**eax)(decomp_var_54, 0x1);
                                            if (edi != ebp) {
                                                    edi[0x1] = esi[0x1];
                                                    eax = esi[0x1];
                                                    decomp_var_58 = eax + 0x1;
                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                    esp = (esp - 0x10) + 0x10;
                                                    edi = edi + 0x10;
                                                    edx = &decomp_var_1c;
                                                    eax = &arg_8;
                                                    decomp_var_50 = edx;
                                                    esp = esp - 0x8;
                                                    decomp_var_54 = eax;
                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                    eax = edi - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            decomp_var_50 = eax;
                                                            (*(**eax + 0x4))(decomp_var_50);
                                                    }
                                                    esi = 0x1;
                                                    ecx = decomp_var_34;
                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                    edx = ecx[0x2];
                                                    asm { fldz };
                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                    ecx = decomp_var_30;
                                                    ebx = ebx + esi;
                                                    if (ebx < edx[0x901]) {
                                                            continue;
                                                    }
                                                    temp_1 = 0x3;
                                                    break;
                                            }
                                            else {
                                                    temp_1 = 0x0;
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    esi = 0x1;
                                    ecx = decomp_var_34;
                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                    edx = ecx[0x2];
                                    asm { fldz };
                                    decomp_var_14 = decomp_var_14 + 0x54;
                                    ecx = decomp_var_30;
                                    ebx = ebx + esi;
                                    if (ebx < edx[0x901]) {
                                            continue;
                                    }
                                    temp_1 = 0x3;
                                    break;
                            }
                    }
                    else {
                            asm { fld1 };
                            asm { fucomp     st2 };
                            asm { fnstsw     ax };
                            if (!PARITY(HIBYTE(eax) & 0x44)) {
                                    if (edx == 0x1) {
                                            ebp = 0x0;
                                            if (*(&decomp_var_3c + ecx * 0x4 + 0xea4) == 0x0) {
                                                    ebp = 0x0;
                                                    if (*(&decomp_var_3c + edi + 0xea4) == 0x0) {
                                                            ebp = 0x0;
                                                            bool_755 = *(ecx * 0x8 + 0x4d552c) > 0x0;
                                                            if (*(ecx * 0x8 + 0x4d552c) >= 0x0) {
                                                                    if (!bool_755) {
                                                                            if (*(ecx * 0x8 + 0x4d5528) > 0x1) {
                                                                                    *(ecx * 0x8 + 0x4d5528) = 0x2;
                                                                                    asm { fstp       st1 };
                                                                                    *(ecx * 0x8 + 0x4d552c) = ebp;
                                                                                    asm { fstp       st0 };
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_28 = ebx & 0xff | 0x4100;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_40);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            esi = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            esi = eax + 0x4;
                                                                                    }
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_40);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            eax = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x4;
                                                                                    }
                                                                                    decomp_var_40 = esi;
                                                                                    decomp_var_44 = eax;
                                                                                    decomp_var_48 = 0x4b0e38;
                                                                                    decomp_var_4c = &decomp_var_1c;
                                                                                    sub_410c10(decomp_var_4c, 0x4b0e38, decomp_var_44);
                                                                                    esi = decomp_var_1c - 0x10;
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                                                    edx = esi + 0xc;
                                                                                    if (esi[0x3] >= ebp) {
                                                                                            if (eax == *esi) {
                                                                                                    edi = esi;
                                                                                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                                                    edi = edi + 0x10;
                                                                                                    edx = &saved_fp;
                                                                                                    eax = &arg_20;
                                                                                                    decomp_var_50 = edx;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = eax;
                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                    eax = edi - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                    if (edx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_50 = eax;
                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                    }
                                                                                                    esi = 0x1;
                                                                                                    ecx = decomp_var_34;
                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                    edx = ecx[0x2];
                                                                                                    asm { fldz };
                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                    ecx = decomp_var_30;
                                                                                                    ebx = ebx + esi;
                                                                                                    if (ebx < edx[0x901]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    decomp_var_50 = 0x1;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = esi[0x1];
                                                                                                    ecx = eax;
                                                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                                                    if (edi != ebp) {
                                                                                                            edi[0x1] = esi[0x1];
                                                                                                            eax = esi[0x1];
                                                                                                            decomp_var_58 = eax + 0x1;
                                                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                            edi = edi + 0x10;
                                                                                                            edx = &saved_fp;
                                                                                                            eax = &arg_20;
                                                                                                            decomp_var_50 = edx;
                                                                                                            esp = esp - 0x8;
                                                                                                            decomp_var_54 = eax;
                                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                            eax = edi - 0x10;
                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                            if (edx <= 0x1) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    decomp_var_50 = eax;
                                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                                            }
                                                                                                            esi = 0x1;
                                                                                                            ecx = decomp_var_34;
                                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                            edx = ecx[0x2];
                                                                                                            asm { fldz };
                                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                            ecx = decomp_var_30;
                                                                                                            ebx = ebx + esi;
                                                                                                            if (ebx < edx[0x901]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            temp_1 = 0x3;
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_1 = 0x1;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ebp = 0x0;
                                                                                            decomp_var_50 = 0x1;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = esi[0x1];
                                                                                            ecx = eax;
                                                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                                                            if (edi != 0x0) {
                                                                                                    edi[0x1] = esi[0x1];
                                                                                                    eax = esi[0x1];
                                                                                                    decomp_var_58 = eax + 0x1;
                                                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                    edi = edi + 0x10;
                                                                                                    edx = &saved_fp;
                                                                                                    eax = &arg_20;
                                                                                                    decomp_var_50 = edx;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = eax;
                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                    eax = edi - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                    if (edx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_50 = eax;
                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                    }
                                                                                                    esi = 0x1;
                                                                                                    ecx = decomp_var_34;
                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                    edx = ecx[0x2];
                                                                                                    asm { fldz };
                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                    ecx = decomp_var_30;
                                                                                                    ebx = ebx + esi;
                                                                                                    if (ebx < edx[0x901]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_1 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fxch       st0, st1 };
                                                                                    asm { fcomp      qword [qword_value_4603129179135383962] };
                                                                                    asm { fnstsw     ax };
                                                                                    bool_718 = (HIBYTE(eax) & 0x5) > 0x0;
                                                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                                            esi = 0x1;
                                                                                            ebp = 0x0;
                                                                                            asm { fcomp      dword [esp+0x3c+-24] };
                                                                                            *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + esi;
                                                                                            *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                                                            asm { fnstsw     ax };
                                                                                            if (!PARITY(HIBYTE(eax) & 0x44)) {
                                                                                                    *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + esi;
                                                                                                    bool_648 = *(ecx * 0x8 + 0x4d5528) < 0x0;
                                                                                                    esp = esp - 0x4;
                                                                                                    *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                                                                    decomp_var_28 = ebx & 0xff | 0x4100;
                                                                                                    sub_46db50();
                                                                                                    eax = sub_4273a0(decomp_var_40);
                                                                                                    if (!bool_648) {
                                                                                                            esi = eax[0x1];
                                                                                                    }
                                                                                                    else {
                                                                                                            esi = eax + 0x4;
                                                                                                    }
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                                                                    sub_46db50();
                                                                                                    eax = sub_4273a0(decomp_var_40);
                                                                                                    if (eax[0x6] >= 0x10) {
                                                                                                            eax = eax[0x1];
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = eax + 0x4;
                                                                                                    }
                                                                                                    decomp_var_40 = esi;
                                                                                                    decomp_var_44 = eax;
                                                                                                    decomp_var_48 = "Seems (%s) and (%s) have applied little pressure to each other";
                                                                                                    decomp_var_4c = &decomp_var_1c;
                                                                                                    sub_410c10(decomp_var_4c, "Seems (%s) and (%s) have applied little pressure to each other", decomp_var_44);
                                                                                                    esi = decomp_var_1c - 0x10;
                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                    eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                                                                    edx = esi + 0xc;
                                                                                                    if (esi[0x3] >= ebp) {
                                                                                                            if (eax == *esi) {
                                                                                                                    edi = esi;
                                                                                                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                                                                    edi = edi + 0x10;
                                                                                                                    edx = &decomp_var_c;
                                                                                                                    eax = &arg_14;
                                                                                                                    decomp_var_50 = edx;
                                                                                                                    esp = esp - 0x8;
                                                                                                                    decomp_var_54 = eax;
                                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                                    eax = edi - 0x10;
                                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                                    if (edx <= 0x1) {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            decomp_var_50 = eax;
                                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                                    }
                                                                                                                    esi = 0x1;
                                                                                                                    ecx = decomp_var_34;
                                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                                    edx = ecx[0x2];
                                                                                                                    asm { fldz };
                                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                                    ecx = decomp_var_30;
                                                                                                                    ebx = ebx + esi;
                                                                                                                    if (ebx < edx[0x901]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    temp_1 = 0x3;
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    decomp_var_50 = 0x1;
                                                                                                                    esp = esp - 0x8;
                                                                                                                    decomp_var_54 = esi[0x1];
                                                                                                                    ecx = eax;
                                                                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                                                                    if (edi != ebp) {
                                                                                                                            edi[0x1] = esi[0x1];
                                                                                                                            eax = esi[0x1];
                                                                                                                            decomp_var_58 = eax + 0x1;
                                                                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                            edi = edi + 0x10;
                                                                                                                            edx = &decomp_var_c;
                                                                                                                            eax = &arg_14;
                                                                                                                            decomp_var_50 = edx;
                                                                                                                            esp = esp - 0x8;
                                                                                                                            decomp_var_54 = eax;
                                                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                                            eax = edi - 0x10;
                                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                                            if (edx <= 0x1) {
                                                                                                                                    esp = esp - 0x4;
                                                                                                                                    decomp_var_50 = eax;
                                                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                                                            }
                                                                                                                            esi = 0x1;
                                                                                                                            ecx = decomp_var_34;
                                                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                                            edx = ecx[0x2];
                                                                                                                            asm { fldz };
                                                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                                            ecx = decomp_var_30;
                                                                                                                            ebx = ebx + esi;
                                                                                                                            if (ebx < edx[0x901]) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            temp_1 = 0x3;
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            temp_1 = 0x2;
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            ebp = 0x0;
                                                                                                            decomp_var_50 = 0x1;
                                                                                                            esp = esp - 0x8;
                                                                                                            decomp_var_54 = esi[0x1];
                                                                                                            ecx = eax;
                                                                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                                                                            if (edi != 0x0) {
                                                                                                                    edi[0x1] = esi[0x1];
                                                                                                                    eax = esi[0x1];
                                                                                                                    decomp_var_58 = eax + 0x1;
                                                                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                    edi = edi + 0x10;
                                                                                                                    edx = &decomp_var_c;
                                                                                                                    eax = &arg_14;
                                                                                                                    decomp_var_50 = edx;
                                                                                                                    esp = esp - 0x8;
                                                                                                                    decomp_var_54 = eax;
                                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                                    eax = edi - 0x10;
                                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                                    if (edx <= 0x1) {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            decomp_var_50 = eax;
                                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                                    }
                                                                                                                    esi = 0x1;
                                                                                                                    ecx = decomp_var_34;
                                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                                    edx = ecx[0x2];
                                                                                                                    asm { fldz };
                                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                                    ecx = decomp_var_30;
                                                                                                                    ebx = ebx + esi;
                                                                                                                    if (ebx < edx[0x901]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    temp_1 = 0x3;
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    temp_1 = 0x2;
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_34;
                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                    edx = ecx[0x2];
                                                                                                    asm { fldz };
                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                    ecx = decomp_var_30;
                                                                                                    ebx = ebx + esi;
                                                                                                    if (ebx < edx[0x901]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fstp       st0 };
                                                                                            bool_729 = asm { fstp       st0 };
                                                                                            if (!bool_718) {
                                                                                                    if (bool_729 || *(ecx * 0x8 + 0x4d5528) < 0x5) {
                                                                                                            ebp = 0x0;
                                                                                                            *(ecx * 0x8 + 0x4d5528) = 0x1;
                                                                                                            *(ecx * 0x8 + 0x4d552c) = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            esi = 0x1;
                                                                                            ecx = decomp_var_34;
                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                            edx = ecx[0x2];
                                                                                            asm { fldz };
                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                            ecx = decomp_var_30;
                                                                                            ebx = ebx + esi;
                                                                                            if (ebx < edx[0x901]) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x3;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebp = 0x0;
                                                                            *(ecx * 0x8 + 0x4d5528) = 0x2;
                                                                            asm { fstp       st1 };
                                                                            *(ecx * 0x8 + 0x4d552c) = ebp;
                                                                            asm { fstp       st0 };
                                                                            esp = esp - 0x4;
                                                                            decomp_var_28 = ebx & 0xff | 0x4100;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_40);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    esi = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    esi = eax + 0x4;
                                                                            }
                                                                            esp = esp - 0x4;
                                                                            decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_40);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            decomp_var_40 = esi;
                                                                            decomp_var_44 = eax;
                                                                            decomp_var_48 = 0x4b0e38;
                                                                            decomp_var_4c = &decomp_var_1c;
                                                                            sub_410c10(decomp_var_4c, 0x4b0e38, decomp_var_44);
                                                                            esi = decomp_var_1c - 0x10;
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                                            edx = esi + 0xc;
                                                                            if (esi[0x3] >= ebp) {
                                                                                    if (eax == *esi) {
                                                                                            edi = esi;
                                                                                            *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                                            edi = edi + 0x10;
                                                                                            edx = &saved_fp;
                                                                                            eax = &arg_20;
                                                                                            decomp_var_50 = edx;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = eax;
                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                            eax = edi - 0x10;
                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                            if (edx <= 0x1) {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_50 = eax;
                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                            }
                                                                                            esi = 0x1;
                                                                                            ecx = decomp_var_34;
                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                            edx = ecx[0x2];
                                                                                            asm { fldz };
                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                            ecx = decomp_var_30;
                                                                                            ebx = ebx + esi;
                                                                                            if (ebx < edx[0x901]) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x3;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            decomp_var_50 = 0x1;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = esi[0x1];
                                                                                            ecx = eax;
                                                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                                                            if (edi != ebp) {
                                                                                                    edi[0x1] = esi[0x1];
                                                                                                    eax = esi[0x1];
                                                                                                    decomp_var_58 = eax + 0x1;
                                                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                    edi = edi + 0x10;
                                                                                                    edx = &saved_fp;
                                                                                                    eax = &arg_20;
                                                                                                    decomp_var_50 = edx;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = eax;
                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                    eax = edi - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                    if (edx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_50 = eax;
                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                    }
                                                                                                    esi = 0x1;
                                                                                                    ecx = decomp_var_34;
                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                    edx = ecx[0x2];
                                                                                                    asm { fldz };
                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                    ecx = decomp_var_30;
                                                                                                    ebx = ebx + esi;
                                                                                                    if (ebx < edx[0x901]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_1 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebp = 0x0;
                                                                                    decomp_var_50 = 0x1;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_54 = esi[0x1];
                                                                                    ecx = eax;
                                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                                    if (edi != 0x0) {
                                                                                            edi[0x1] = esi[0x1];
                                                                                            eax = esi[0x1];
                                                                                            decomp_var_58 = eax + 0x1;
                                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                            edi = edi + 0x10;
                                                                                            edx = &saved_fp;
                                                                                            eax = &arg_20;
                                                                                            decomp_var_50 = edx;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = eax;
                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                            eax = edi - 0x10;
                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                            if (edx <= 0x1) {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_50 = eax;
                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                            }
                                                                                            esi = 0x1;
                                                                                            ecx = decomp_var_34;
                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                            edx = ecx[0x2];
                                                                                            asm { fldz };
                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                            ecx = decomp_var_30;
                                                                                            ebx = ebx + esi;
                                                                                            if (ebx < edx[0x901]) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x3;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_1 = 0x1;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    asm { fxch       st0, st1 };
                                                                    asm { fcomp      qword [qword_value_4603129179135383962] };
                                                                    asm { fnstsw     ax };
                                                                    bool_706 = (HIBYTE(eax) & 0x5) > 0x0;
                                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                            esi = 0x1;
                                                                            ebp = 0x0;
                                                                            asm { fcomp      dword [esp+0x3c+-24] };
                                                                            *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + esi;
                                                                            *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                                            asm { fnstsw     ax };
                                                                            if (!PARITY(HIBYTE(eax) & 0x44)) {
                                                                                    ebp = 0x0;
                                                                                    *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + 0x1;
                                                                                    bool_651 = *(ecx * 0x8 + 0x4d5528) < 0x0;
                                                                                    esp = esp - 0x4;
                                                                                    *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + 0x0 + CARRY(EFLAGS(cf));
                                                                                    decomp_var_28 = ebx & 0xff | 0x4100;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_40);
                                                                                    if (!bool_651) {
                                                                                            esi = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            esi = eax + 0x4;
                                                                                    }
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_40);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            eax = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x4;
                                                                                    }
                                                                                    decomp_var_40 = esi;
                                                                                    decomp_var_44 = eax;
                                                                                    decomp_var_48 = "Seems (%s) and (%s) have applied little pressure to each other";
                                                                                    decomp_var_4c = &decomp_var_1c;
                                                                                    sub_410c10(decomp_var_4c, "Seems (%s) and (%s) have applied little pressure to each other", decomp_var_44);
                                                                                    esi = decomp_var_1c - 0x10;
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                                                    edx = esi + 0xc;
                                                                                    if (esi[0x3] >= ebp) {
                                                                                            if (eax == *esi) {
                                                                                                    edi = esi;
                                                                                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                                                    edi = edi + 0x10;
                                                                                                    edx = &decomp_var_c;
                                                                                                    eax = &arg_14;
                                                                                                    decomp_var_50 = edx;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = eax;
                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                    eax = edi - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                    if (edx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_50 = eax;
                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                    }
                                                                                                    esi = 0x1;
                                                                                                    ecx = decomp_var_34;
                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                    edx = ecx[0x2];
                                                                                                    asm { fldz };
                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                    ecx = decomp_var_30;
                                                                                                    ebx = ebx + esi;
                                                                                                    if (ebx < edx[0x901]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    decomp_var_50 = 0x1;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = esi[0x1];
                                                                                                    ecx = eax;
                                                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                                                    if (edi != ebp) {
                                                                                                            edi[0x1] = esi[0x1];
                                                                                                            eax = esi[0x1];
                                                                                                            decomp_var_58 = eax + 0x1;
                                                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                            edi = edi + 0x10;
                                                                                                            edx = &decomp_var_c;
                                                                                                            eax = &arg_14;
                                                                                                            decomp_var_50 = edx;
                                                                                                            esp = esp - 0x8;
                                                                                                            decomp_var_54 = eax;
                                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                            eax = edi - 0x10;
                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                            if (edx <= 0x1) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    decomp_var_50 = eax;
                                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                                            }
                                                                                                            esi = 0x1;
                                                                                                            ecx = decomp_var_34;
                                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                            edx = ecx[0x2];
                                                                                                            asm { fldz };
                                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                            ecx = decomp_var_30;
                                                                                                            ebx = ebx + esi;
                                                                                                            if (ebx < edx[0x901]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            temp_1 = 0x3;
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_1 = 0x2;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ebp = 0x0;
                                                                                            decomp_var_50 = 0x1;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = esi[0x1];
                                                                                            ecx = eax;
                                                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                                                            if (edi != 0x0) {
                                                                                                    edi[0x1] = esi[0x1];
                                                                                                    eax = esi[0x1];
                                                                                                    decomp_var_58 = eax + 0x1;
                                                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                    edi = edi + 0x10;
                                                                                                    edx = &decomp_var_c;
                                                                                                    eax = &arg_14;
                                                                                                    decomp_var_50 = edx;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = eax;
                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                    eax = edi - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                    if (edx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_50 = eax;
                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                    }
                                                                                                    esi = 0x1;
                                                                                                    ecx = decomp_var_34;
                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                    edx = ecx[0x2];
                                                                                                    asm { fldz };
                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                    ecx = decomp_var_30;
                                                                                                    ebx = ebx + esi;
                                                                                                    if (ebx < edx[0x901]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_1 = 0x2;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_34;
                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                    edx = ecx[0x2];
                                                                                    asm { fldz };
                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                    ecx = decomp_var_30;
                                                                                    ebx = ebx + esi;
                                                                                    if (ebx < edx[0x901]) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x3;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            asm { fstp       st0 };
                                                                            bool_624 = asm { fstp       st0 };
                                                                            if (!bool_706) {
                                                                                    if (bool_624 || *(ecx * 0x8 + 0x4d5528) < 0x5) {
                                                                                            ebp = 0x0;
                                                                                            *(ecx * 0x8 + 0x4d5528) = 0x1;
                                                                                            *(ecx * 0x8 + 0x4d552c) = 0x0;
                                                                                    }
                                                                            }
                                                                            esi = 0x1;
                                                                            ecx = decomp_var_34;
                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                            edx = ecx[0x2];
                                                                            asm { fldz };
                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                            ecx = decomp_var_30;
                                                                            ebx = ebx + esi;
                                                                            if (ebx < edx[0x901]) {
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x3;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            asm { fxch       st0, st1 };
                                                            asm { fcomp      qword [qword_value_4603129179135383962] };
                                                            asm { fnstsw     ax };
                                                            bool_641 = (HIBYTE(eax) & 0x5) > 0x0;
                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                    esi = 0x1;
                                                                    asm { fcomp      dword [esp+0x3c+-24] };
                                                                    *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + esi;
                                                                    *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                                    asm { fnstsw     ax };
                                                                    if (!PARITY(HIBYTE(eax) & 0x44)) {
                                                                            *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + 0x1;
                                                                            bool_617 = *(ecx * 0x8 + 0x4d5528) < 0x0;
                                                                            esp = esp - 0x4;
                                                                            *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + 0x0 + CARRY(EFLAGS(cf));
                                                                            decomp_var_28 = ebx & 0xff | 0x4100;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_40);
                                                                            if (!bool_617) {
                                                                                    esi = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    esi = eax + 0x4;
                                                                            }
                                                                            esp = esp - 0x4;
                                                                            decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_40);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            ebp = 0x0;
                                                                            decomp_var_40 = esi;
                                                                            decomp_var_44 = eax;
                                                                            decomp_var_48 = "Seems (%s) and (%s) have applied little pressure to each other";
                                                                            decomp_var_4c = &decomp_var_1c;
                                                                            sub_410c10(decomp_var_4c, "Seems (%s) and (%s) have applied little pressure to each other", decomp_var_44);
                                                                            esi = decomp_var_1c - 0x10;
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                                            edx = esi + 0xc;
                                                                            if (esi[0x3] >= 0x0) {
                                                                                    if (eax == *esi) {
                                                                                            edi = esi;
                                                                                            *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                                            edi = edi + 0x10;
                                                                                            edx = &decomp_var_c;
                                                                                            eax = &arg_14;
                                                                                            decomp_var_50 = edx;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = eax;
                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                            eax = edi - 0x10;
                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                            if (edx <= 0x1) {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_50 = eax;
                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                            }
                                                                                            esi = 0x1;
                                                                                            ecx = decomp_var_34;
                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                            edx = ecx[0x2];
                                                                                            asm { fldz };
                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                            ecx = decomp_var_30;
                                                                                            ebx = ebx + esi;
                                                                                            if (ebx < edx[0x901]) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x3;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            decomp_var_50 = 0x1;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = esi[0x1];
                                                                                            ecx = eax;
                                                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                                                            if (edi != ebp) {
                                                                                                    edi[0x1] = esi[0x1];
                                                                                                    eax = esi[0x1];
                                                                                                    decomp_var_58 = eax + 0x1;
                                                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                    edi = edi + 0x10;
                                                                                                    edx = &decomp_var_c;
                                                                                                    eax = &arg_14;
                                                                                                    decomp_var_50 = edx;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = eax;
                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                    eax = edi - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                    if (edx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_50 = eax;
                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                    }
                                                                                                    esi = 0x1;
                                                                                                    ecx = decomp_var_34;
                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                    edx = ecx[0x2];
                                                                                                    asm { fldz };
                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                    ecx = decomp_var_30;
                                                                                                    ebx = ebx + esi;
                                                                                                    if (ebx < edx[0x901]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_1 = 0x2;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    decomp_var_50 = 0x1;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_54 = esi[0x1];
                                                                                    ecx = eax;
                                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                                    if (edi != ebp) {
                                                                                            edi[0x1] = esi[0x1];
                                                                                            eax = esi[0x1];
                                                                                            decomp_var_58 = eax + 0x1;
                                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                            edi = edi + 0x10;
                                                                                            edx = &decomp_var_c;
                                                                                            eax = &arg_14;
                                                                                            decomp_var_50 = edx;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = eax;
                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                            eax = edi - 0x10;
                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                            if (edx <= 0x1) {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_50 = eax;
                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                            }
                                                                                            esi = 0x1;
                                                                                            ecx = decomp_var_34;
                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                            edx = ecx[0x2];
                                                                                            asm { fldz };
                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                            ecx = decomp_var_30;
                                                                                            ebx = ebx + esi;
                                                                                            if (ebx < edx[0x901]) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x3;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_1 = 0x2;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi = 0x1;
                                                                            ecx = decomp_var_34;
                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                            edx = ecx[0x2];
                                                                            asm { fldz };
                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                            ecx = decomp_var_30;
                                                                            ebx = ebx + esi;
                                                                            if (ebx < edx[0x901]) {
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x3;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    asm { fstp       st0 };
                                                                    bool_647 = asm { fstp       st0 };
                                                                    if (!bool_641) {
                                                                            if (bool_647 || *(ecx * 0x8 + 0x4d5528) < 0x5) {
                                                                                    ebp = 0x0;
                                                                                    *(ecx * 0x8 + 0x4d5528) = 0x1;
                                                                                    *(ecx * 0x8 + 0x4d552c) = 0x0;
                                                                            }
                                                                    }
                                                                    esi = 0x1;
                                                                    ecx = decomp_var_34;
                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                    edx = ecx[0x2];
                                                                    asm { fldz };
                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                    ecx = decomp_var_30;
                                                                    ebx = ebx + esi;
                                                                    if (ebx < edx[0x901]) {
                                                                            continue;
                                                                    }
                                                                    temp_1 = 0x3;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    asm { fxch       st0, st1 };
                                                    asm { fcomp      qword [qword_value_4603129179135383962] };
                                                    asm { fnstsw     ax };
                                                    bool_630 = (HIBYTE(eax) & 0x5) > 0x0;
                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                            esi = 0x1;
                                                            ebp = 0x0;
                                                            asm { fcomp      dword [esp+0x3c+-24] };
                                                            *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + esi;
                                                            *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                            asm { fnstsw     ax };
                                                            if (!PARITY(HIBYTE(eax) & 0x44)) {
                                                                    ebp = 0x0;
                                                                    *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + 0x1;
                                                                    bool_719 = *(ecx * 0x8 + 0x4d5528) < 0x0;
                                                                    esp = esp - 0x4;
                                                                    *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + 0x0 + CARRY(EFLAGS(cf));
                                                                    decomp_var_28 = ebx & 0xff | 0x4100;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_40);
                                                                    if (!bool_719) {
                                                                            esi = eax[0x1];
                                                                    }
                                                                    else {
                                                                            esi = eax + 0x4;
                                                                    }
                                                                    esp = esp - 0x4;
                                                                    decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_40);
                                                                    if (eax[0x6] >= 0x10) {
                                                                            eax = eax[0x1];
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x4;
                                                                    }
                                                                    decomp_var_40 = esi;
                                                                    decomp_var_44 = eax;
                                                                    decomp_var_48 = "Seems (%s) and (%s) have applied little pressure to each other";
                                                                    decomp_var_4c = &decomp_var_1c;
                                                                    sub_410c10(decomp_var_4c, "Seems (%s) and (%s) have applied little pressure to each other", decomp_var_44);
                                                                    esi = decomp_var_1c - 0x10;
                                                                    esp = (esp - 0x10) + 0x10;
                                                                    eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                                    edx = esi + 0xc;
                                                                    if (esi[0x3] >= ebp) {
                                                                            if (eax == *esi) {
                                                                                    edi = esi;
                                                                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                                    edi = edi + 0x10;
                                                                                    edx = &decomp_var_c;
                                                                                    eax = &arg_14;
                                                                                    decomp_var_50 = edx;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_54 = eax;
                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                    eax = edi - 0x10;
                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                    if (edx <= 0x1) {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_50 = eax;
                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                    }
                                                                                    esi = 0x1;
                                                                                    ecx = decomp_var_34;
                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                    edx = ecx[0x2];
                                                                                    asm { fldz };
                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                    ecx = decomp_var_30;
                                                                                    ebx = ebx + esi;
                                                                                    if (ebx < edx[0x901]) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x3;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    decomp_var_50 = 0x1;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_54 = esi[0x1];
                                                                                    ecx = eax;
                                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                                    if (edi != ebp) {
                                                                                            edi[0x1] = esi[0x1];
                                                                                            eax = esi[0x1];
                                                                                            decomp_var_58 = eax + 0x1;
                                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                            edi = edi + 0x10;
                                                                                            edx = &decomp_var_c;
                                                                                            eax = &arg_14;
                                                                                            decomp_var_50 = edx;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = eax;
                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                            eax = edi - 0x10;
                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                            if (edx <= 0x1) {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_50 = eax;
                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                            }
                                                                                            esi = 0x1;
                                                                                            ecx = decomp_var_34;
                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                            edx = ecx[0x2];
                                                                                            asm { fldz };
                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                            ecx = decomp_var_30;
                                                                                            ebx = ebx + esi;
                                                                                            if (ebx < edx[0x901]) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x3;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_1 = 0x2;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebp = 0x0;
                                                                            decomp_var_50 = 0x1;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_54 = esi[0x1];
                                                                            ecx = eax;
                                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                                            if (edi != 0x0) {
                                                                                    edi[0x1] = esi[0x1];
                                                                                    eax = esi[0x1];
                                                                                    decomp_var_58 = eax + 0x1;
                                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    edi = edi + 0x10;
                                                                                    edx = &decomp_var_c;
                                                                                    eax = &arg_14;
                                                                                    decomp_var_50 = edx;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_54 = eax;
                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                    eax = edi - 0x10;
                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                    if (edx <= 0x1) {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_50 = eax;
                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                    }
                                                                                    esi = 0x1;
                                                                                    ecx = decomp_var_34;
                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                    edx = ecx[0x2];
                                                                                    asm { fldz };
                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                    ecx = decomp_var_30;
                                                                                    ebx = ebx + esi;
                                                                                    if (ebx < edx[0x901]) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x3;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_1 = 0x2;
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    esi = 0x1;
                                                                    ecx = decomp_var_34;
                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                    edx = ecx[0x2];
                                                                    asm { fldz };
                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                    ecx = decomp_var_30;
                                                                    ebx = ebx + esi;
                                                                    if (ebx < edx[0x901]) {
                                                                            continue;
                                                                    }
                                                                    temp_1 = 0x3;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            asm { fstp       st0 };
                                                            bool_665 = asm { fstp       st0 };
                                                            if (!bool_630) {
                                                                    if (bool_665 || *(ecx * 0x8 + 0x4d5528) < 0x5) {
                                                                            *(ecx * 0x8 + 0x4d5528) = 0x1;
                                                                            *(ecx * 0x8 + 0x4d552c) = ebp;
                                                                    }
                                                            }
                                                            esi = 0x1;
                                                            ecx = decomp_var_34;
                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                            edx = ecx[0x2];
                                                            asm { fldz };
                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                            ecx = decomp_var_30;
                                                            ebx = ebx + esi;
                                                            if (ebx < edx[0x901]) {
                                                                    continue;
                                                            }
                                                            temp_1 = 0x3;
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            asm { fxch       st0, st1 };
                                            asm { fcomp      qword [qword_value_4603129179135383962] };
                                            asm { fnstsw     ax };
                                            bool_633 = (HIBYTE(eax) & 0x5) > 0x0;
                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                    esi = 0x1;
                                                    ebp = 0x0;
                                                    asm { fcomp      dword [esp+0x3c+-24] };
                                                    *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + esi;
                                                    *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x44)) {
                                                            ebp = 0x0;
                                                            *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + 0x1;
                                                            bool_656 = *(ecx * 0x8 + 0x4d5528) < 0x0;
                                                            esp = esp - 0x4;
                                                            *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + 0x0 + CARRY(EFLAGS(cf));
                                                            decomp_var_28 = ebx & 0xff | 0x4100;
                                                            sub_46db50();
                                                            eax = sub_4273a0(decomp_var_40);
                                                            if (!bool_656) {
                                                                    esi = eax[0x1];
                                                            }
                                                            else {
                                                                    esi = eax + 0x4;
                                                            }
                                                            esp = esp - 0x4;
                                                            decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                            sub_46db50();
                                                            eax = sub_4273a0(decomp_var_40);
                                                            if (eax[0x6] >= 0x10) {
                                                                    eax = eax[0x1];
                                                            }
                                                            else {
                                                                    eax = eax + 0x4;
                                                            }
                                                            decomp_var_40 = esi;
                                                            decomp_var_44 = eax;
                                                            decomp_var_48 = "Seems (%s) and (%s) have applied little pressure to each other";
                                                            decomp_var_4c = &decomp_var_1c;
                                                            sub_410c10(decomp_var_4c, "Seems (%s) and (%s) have applied little pressure to each other", decomp_var_44);
                                                            esi = decomp_var_1c - 0x10;
                                                            esp = (esp - 0x10) + 0x10;
                                                            eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                            edx = esi + 0xc;
                                                            if (esi[0x3] >= ebp) {
                                                                    if (eax == *esi) {
                                                                            edi = esi;
                                                                            *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                            edi = edi + 0x10;
                                                                            edx = &decomp_var_c;
                                                                            eax = &arg_14;
                                                                            decomp_var_50 = edx;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_54 = eax;
                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                            eax = edi - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_50 = eax;
                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                            }
                                                                            esi = 0x1;
                                                                            ecx = decomp_var_34;
                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                            edx = ecx[0x2];
                                                                            asm { fldz };
                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                            ecx = decomp_var_30;
                                                                            ebx = ebx + esi;
                                                                            if (ebx < edx[0x901]) {
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x3;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ebp = 0x0;
                                                                            decomp_var_50 = 0x1;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_54 = esi[0x1];
                                                                            ecx = eax;
                                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                                            if (edi != 0x0) {
                                                                                    edi[0x1] = esi[0x1];
                                                                                    eax = esi[0x1];
                                                                                    decomp_var_58 = eax + 0x1;
                                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    edi = edi + 0x10;
                                                                                    edx = &decomp_var_c;
                                                                                    eax = &arg_14;
                                                                                    decomp_var_50 = edx;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_54 = eax;
                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                    eax = edi - 0x10;
                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                    if (edx <= 0x1) {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_50 = eax;
                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                    }
                                                                                    esi = 0x1;
                                                                                    ecx = decomp_var_34;
                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                    edx = ecx[0x2];
                                                                                    asm { fldz };
                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                    ecx = decomp_var_30;
                                                                                    ebx = ebx + esi;
                                                                                    if (ebx < edx[0x901]) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x3;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_1 = 0x2;
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    ebp = 0x0;
                                                                    decomp_var_50 = 0x1;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_54 = esi[0x1];
                                                                    ecx = eax;
                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                    if (edi != 0x0) {
                                                                            edi[0x1] = esi[0x1];
                                                                            eax = esi[0x1];
                                                                            decomp_var_58 = eax + 0x1;
                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            edi = edi + 0x10;
                                                                            edx = &decomp_var_c;
                                                                            eax = &arg_14;
                                                                            decomp_var_50 = edx;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_54 = eax;
                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                            eax = edi - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_50 = eax;
                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                            }
                                                                            esi = 0x1;
                                                                            ecx = decomp_var_34;
                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                            edx = ecx[0x2];
                                                                            asm { fldz };
                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                            ecx = decomp_var_30;
                                                                            ebx = ebx + esi;
                                                                            if (ebx < edx[0x901]) {
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x3;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_1 = 0x2;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            esi = 0x1;
                                                            ecx = decomp_var_34;
                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                            edx = ecx[0x2];
                                                            asm { fldz };
                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                            ecx = decomp_var_30;
                                                            ebx = ebx + esi;
                                                            if (ebx < edx[0x901]) {
                                                                    continue;
                                                            }
                                                            temp_1 = 0x3;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    asm { fstp       st0 };
                                                    bool_722 = asm { fstp       st0 };
                                                    if (!bool_633) {
                                                            if (bool_722 || *(ecx * 0x8 + 0x4d5528) < 0x5) {
                                                                    ebp = 0x0;
                                                                    *(ecx * 0x8 + 0x4d5528) = 0x1;
                                                                    *(ecx * 0x8 + 0x4d552c) = 0x0;
                                                            }
                                                    }
                                                    esi = 0x1;
                                                    ecx = decomp_var_34;
                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                    edx = ecx[0x2];
                                                    asm { fldz };
                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                    ecx = decomp_var_30;
                                                    ebx = ebx + esi;
                                                    if (ebx < edx[0x901]) {
                                                            continue;
                                                    }
                                                    temp_1 = 0x3;
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    asm { fxch       st0, st1 };
                                    asm { fcomp      qword [qword_value_4603129179135383962] };
                                    asm { fnstsw     ax };
                                    bool_761 = (HIBYTE(eax) & 0x5) > 0x0;
                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                            ebp = 0x0;
                                            esi = 0x1;
                                            asm { fcomp      dword [esp+0x3c+-24] };
                                            *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + esi;
                                            *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                            asm { fnstsw     ax };
                                            if (!PARITY(HIBYTE(eax) & 0x44)) {
                                                    *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + 0x1;
                                                    bool_694 = *(ecx * 0x8 + 0x4d5528) < 0x0;
                                                    esp = esp - 0x4;
                                                    *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                    decomp_var_28 = ebx & 0xff | 0x4100;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_40);
                                                    if (!bool_694) {
                                                            esi = eax[0x1];
                                                    }
                                                    else {
                                                            esi = eax + 0x4;
                                                    }
                                                    esp = esp - 0x4;
                                                    decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_40);
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    ebp = 0x0;
                                                    decomp_var_40 = esi;
                                                    decomp_var_44 = eax;
                                                    decomp_var_48 = "Seems (%s) and (%s) have applied little pressure to each other";
                                                    decomp_var_4c = &decomp_var_1c;
                                                    sub_410c10(decomp_var_4c, "Seems (%s) and (%s) have applied little pressure to each other", decomp_var_44);
                                                    esi = decomp_var_1c - 0x10;
                                                    esp = (esp - 0x10) + 0x10;
                                                    eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                    edx = esi + 0xc;
                                                    if (esi[0x3] >= 0x0) {
                                                            if (eax == *esi) {
                                                                    edi = esi;
                                                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                    edi = edi + 0x10;
                                                                    edx = &decomp_var_c;
                                                                    eax = &arg_14;
                                                                    decomp_var_50 = edx;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_54 = eax;
                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                    eax = edi - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            decomp_var_50 = eax;
                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                    }
                                                                    esi = 0x1;
                                                                    ecx = decomp_var_34;
                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                    edx = ecx[0x2];
                                                                    asm { fldz };
                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                    ecx = decomp_var_30;
                                                                    ebx = ebx + esi;
                                                                    if (ebx < edx[0x901]) {
                                                                            continue;
                                                                    }
                                                                    temp_1 = 0x3;
                                                                    break;
                                                            }
                                                            else {
                                                                    decomp_var_50 = 0x1;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_54 = esi[0x1];
                                                                    ecx = eax;
                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                    if (edi != ebp) {
                                                                            edi[0x1] = esi[0x1];
                                                                            eax = esi[0x1];
                                                                            decomp_var_58 = eax + 0x1;
                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            edi = edi + 0x10;
                                                                            edx = &decomp_var_c;
                                                                            eax = &arg_14;
                                                                            decomp_var_50 = edx;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_54 = eax;
                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                            eax = edi - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_50 = eax;
                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                            }
                                                                            esi = 0x1;
                                                                            ecx = decomp_var_34;
                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                            edx = ecx[0x2];
                                                                            asm { fldz };
                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                            ecx = decomp_var_30;
                                                                            ebx = ebx + esi;
                                                                            if (ebx < edx[0x901]) {
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x3;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_1 = 0x2;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            decomp_var_50 = 0x1;
                                                            esp = esp - 0x8;
                                                            decomp_var_54 = esi[0x1];
                                                            ecx = eax;
                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                            if (edi != ebp) {
                                                                    edi[0x1] = esi[0x1];
                                                                    eax = esi[0x1];
                                                                    decomp_var_58 = eax + 0x1;
                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                    esp = (esp - 0x10) + 0x10;
                                                                    edi = edi + 0x10;
                                                                    edx = &decomp_var_c;
                                                                    eax = &arg_14;
                                                                    decomp_var_50 = edx;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_54 = eax;
                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                    eax = edi - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            decomp_var_50 = eax;
                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                    }
                                                                    esi = 0x1;
                                                                    ecx = decomp_var_34;
                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                    edx = ecx[0x2];
                                                                    asm { fldz };
                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                    ecx = decomp_var_30;
                                                                    ebx = ebx + esi;
                                                                    if (ebx < edx[0x901]) {
                                                                            continue;
                                                                    }
                                                                    temp_1 = 0x3;
                                                                    break;
                                                            }
                                                            else {
                                                                    temp_1 = 0x2;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    esi = 0x1;
                                                    ecx = decomp_var_34;
                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                    edx = ecx[0x2];
                                                    asm { fldz };
                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                    ecx = decomp_var_30;
                                                    ebx = ebx + esi;
                                                    if (ebx < edx[0x901]) {
                                                            continue;
                                                    }
                                                    temp_1 = 0x3;
                                                    break;
                                            }
                                    }
                                    else {
                                            asm { fstp       st0 };
                                            bool_638 = asm { fstp       st0 };
                                            if (!bool_761) {
                                                    if (bool_638 || *(ecx * 0x8 + 0x4d5528) < 0x5) {
                                                            ebp = 0x0;
                                                            *(ecx * 0x8 + 0x4d5528) = 0x1;
                                                            *(ecx * 0x8 + 0x4d552c) = 0x0;
                                                    }
                                            }
                                            esi = 0x1;
                                            ecx = decomp_var_34;
                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                            edx = ecx[0x2];
                                            asm { fldz };
                                            decomp_var_14 = decomp_var_14 + 0x54;
                                            ecx = decomp_var_30;
                                            ebx = ebx + esi;
                                            if (ebx < edx[0x901]) {
                                                    continue;
                                            }
                                            temp_1 = 0x3;
                                            break;
                                    }
                            }
                    }
            }
            else {
                    asm { fstp       st1 };
                    asm { fstp       st0 };
                    esi = 0x1;
                    ecx = decomp_var_34;
                    asm { fld        dword [aSeemsSAndSHave+60] };
                    edx = ecx[0x2];
                    asm { fldz };
                    decomp_var_14 = decomp_var_14 + 0x54;
                    ecx = decomp_var_30;
                    ebx = ebx + esi;
                    if (ebx < edx[0x901]) {
                            continue;
                    }
                    temp_1 = 0x3;
                    break;
            }
    }
    else {
            asm { fstp       st1 };
            asm { fstp       st0 };
            esi = 0x1;
            ecx = decomp_var_34;
            asm { fld        dword [aSeemsSAndSHave+60] };
            edx = ecx[0x2];
            asm { fldz };
            decomp_var_14 = decomp_var_14 + 0x54;
            ecx = decomp_var_30;
            ebx = ebx + esi;
            if (ebx < edx[0x901]) {
                    continue;
            }
            temp_1 = 0x3;
            break;
    }
    goto .l46;

.l29:
    edx = *dword_4c6bc4;
    eax = ebp * 0x15;
    ecx = eax + *dword_4c6bc4;
    bool_208 = *(ecx * 0x8 + 0x4d552c) < 0x0;
    if (*(ecx * 0x8 + 0x4d552c) <= 0x0 && (bool_208 || *(ecx * 0x8 + 0x4d5528) < 0x2)) {
            edx = *dword_4c6bc4;
            edx = edx | 0xffffffff;
            *dword_4c6bc4 = edx;
    }
    ecx = *dword_4c6bc8;
    esi = eax + *dword_4c6bc8;
    bool_215 = *(esi * 0x8 + 0x4d552c) > 0x0;
    bool_197 = *(esi * 0x8 + 0x4d552c) < 0x0;
    if (!bool_215 && (bool_197 || *(esi * 0x8 + 0x4d5528) < 0x2)) {
            ecx = *dword_4c6bc8;
            ecx = ecx | 0xffffffff;
            *dword_4c6bc8 = ecx;
    }
    esi = *dword_4c6bcc;
    eax = eax + *dword_4c6bcc;
    bool_211 = *(eax * 0x8 + 0x4d552c) > 0x0;
    bool_210 = *(eax * 0x8 + 0x4d552c) < 0x0;
    if (!bool_211 && (bool_210 || *(eax * 0x8 + 0x4d5528) < 0x2)) {
            esi = *dword_4c6bcc;
            esi = esi | 0xffffffff;
            *dword_4c6bcc = esi;
    }
    bool_252 = edx != 0xffffffff;
    if (edx == 0xffffffff) {
            bool_194 = ecx != edx;
            if (ecx > edx) {
                    edx = ecx;
                    ecx = ecx | 0xffffffff;
                    *dword_4c6bc4 = edx;
                    *dword_4c6bc8 = ecx;
                    if (esi > 0xffffffff) {
                            ecx = esi;
                            esi = esi | 0xffffffff;
                            *dword_4c6bc8 = ecx;
                            *dword_4c6bcc = esi;
                    }
            }
            else {
                    if (!bool_194 && esi > 0xffffffff) {
                            ecx = esi;
                            esi = esi | 0xffffffff;
                            *dword_4c6bc8 = ecx;
                            *dword_4c6bcc = esi;
                    }
            }
    }
    else {
            if (!bool_252 && esi > 0xffffffff) {
                    ecx = esi;
                    esi = esi | 0xffffffff;
                    *dword_4c6bc8 = ecx;
                    *dword_4c6bcc = esi;
            }
    }
    bool_198 = edx <= 0xffffffff;
    if (edx == 0xffffffff) {
            if (ecx == edx) {
                    bool_234 = esi <= edx;
                    if (esi > edx) {
                            edx = esi;
                            *dword_4c6bc4 = edx;
                            *dword_4c6bcc = 0xffffffff;
                            if (!bool_234) {
                                    ebx = 0x0;
                                    if (*(decomp_var_34[0x2] + 0x2404) > 0x0) {
                                            while (true) {
                                                    if (ebx == ebp) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    if (ebx == edx) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    eax = edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx;
                                                    ecx = *(&decomp_var_4c + eax + 0xd4);
                                                    if (ecx <= 0x1) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    if (ecx != *(&decomp_var_4c + eax + 0x7bc)) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    esp = esp - 0x4;
                                                    decomp_var_38 = edx & 0xff | 0x4100;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_50);
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    decomp_var_50 = eax;
                                                    decomp_var_54 = "It would seem our best ally (%s) has been severely pressured by another power ";
                                                    decomp_var_58 = &decomp_var_2c;
                                                    sub_410c10(decomp_var_58, "It would seem our best ally (%s) has been severely pressured by another power ", decomp_var_50);
                                                    edx = **(decomp_var_2c - 0x10);
                                                    eax = edx[0x4];
                                                    esi = decomp_var_2c - 0x10;
                                                    esp = (esp - 0xc) + 0xc;
                                                    eax = (eax)();
                                                    ecx = esi + 0xc;
                                                    if (esi[0x3] >= 0x0) {
                                                            if (eax == *esi) {
                                                                    edi = esi;
                                                                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
                                                                    esp = esp - 0x8;
                                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                                    eax = edi + 0x10 - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            (*(**eax + 0x4))(eax);
                                                                    }
                                                                    edx = *dword_4c6bc4;
                                                                    *(int8_t *)byte_baed45 = 0x1;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                            continue;
                                                                    }
                                                                    temp_3 = 0x0;
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = esi[0x1];
                                                                    edx = *eax;
                                                                    edx = *edx;
                                                                    esp = esp - 0x8;
                                                                    edi = (edx)(ecx, 0x1);
                                                                    if (edi != 0x0) {
                                                                            edi[0x1] = esi[0x1];
                                                                            eax = esi[0x1];
                                                                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            esp = esp - 0x8;
                                                                            eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                                            eax = edi + 0x10 - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    (*(**eax + 0x4))(eax);
                                                                            }
                                                                            edx = *dword_4c6bc4;
                                                                            *(int8_t *)byte_baed45 = 0x1;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                                    continue;
                                                                            }
                                                                            temp_3 = 0x0;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_3 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            ecx = esi[0x1];
                                                            edx = *eax;
                                                            edx = *edx;
                                                            esp = esp - 0x8;
                                                            edi = (edx)(ecx, 0x1);
                                                            if (edi != 0x0) {
                                                                    edi[0x1] = esi[0x1];
                                                                    eax = esi[0x1];
                                                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                                    esp = (esp - 0x10) + 0x10;
                                                                    esp = esp - 0x8;
                                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                                    eax = edi + 0x10 - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            (*(**eax + 0x4))(eax);
                                                                    }
                                                                    edx = *dword_4c6bc4;
                                                                    *(int8_t *)byte_baed45 = 0x1;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                            continue;
                                                                    }
                                                                    temp_3 = 0x0;
                                                                    break;
                                                            }
                                                            else {
                                                                    temp_3 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            if (temp_3 != 0x0) {
                                                    eax = sub_40b6d0();
                                            }
                                            else {
                                                    ebx = decomp_var_40;
                                                    esi = *(ebx[0x2] + 0x2404);
                                                    if (esi > 0x0) {
                                                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                                    }
                                                    else {
                                                            if (*(int8_t *)byte_baed43 == 0x1) {
                                                                    edx = 0x0;
                                                                    ecx = 0x0;
                                                                    if (esi > 0x0) {
                                                                            eax = &arg_4d5524;
                                                                            do {
                                                                                    if (*eax == 0x3) {
                                                                                            edx = 0x0;
                                                                                            if (eax[0x1] == 0x0) {
                                                                                                    edx = 0x0;
                                                                                                    *eax = 0x1;
                                                                                                    eax[0x1] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = ecx + 0x1;
                                                                                    eax = eax + 0x8;
                                                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                                                    }
                                                            }
                                                            eax = decomp_var_38 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    decomp_var_5c = eax;
                                                                    eax = *(**eax + 0x4);
                                                                    eax = (eax)(decomp_var_5c);
                                                            }
                                                            *0x0 = arg_bd34;
                                                            &decomp_var_44 = decomp_var_4c;
                                                    }
                                            }
                                    }
                                    else {
                                            ebx = decomp_var_40;
                                            esi = *(ebx[0x2] + 0x2404);
                                            if (esi > 0x0) {
                                                    eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                            }
                                            else {
                                                    if (*(int8_t *)byte_baed43 == 0x1) {
                                                            edx = 0x0;
                                                            ecx = 0x0;
                                                            if (esi > 0x0) {
                                                                    eax = &arg_4d5524;
                                                                    do {
                                                                            if (*eax == 0x3) {
                                                                                    edx = 0x0;
                                                                                    if (eax[0x1] == 0x0) {
                                                                                            edx = 0x0;
                                                                                            *eax = 0x1;
                                                                                            eax[0x1] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = ecx + 0x1;
                                                                            eax = eax + 0x8;
                                                                    } while (ecx < *(ebx[0x2] + 0x2404));
                                                            }
                                                    }
                                                    eax = decomp_var_38 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            decomp_var_5c = eax;
                                                            eax = *(**eax + 0x4);
                                                            eax = (eax)(decomp_var_5c);
                                                    }
                                                    *0x0 = arg_bd34;
                                                    &decomp_var_44 = decomp_var_4c;
                                            }
                                    }
                            }
                            else {
                                    ebx = decomp_var_40;
                                    esi = *(ebx[0x2] + 0x2404);
                                    if (esi > 0x0) {
                                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                    }
                                    else {
                                            if (*(int8_t *)byte_baed43 == 0x1) {
                                                    edx = 0x0;
                                                    ecx = 0x0;
                                                    if (esi > 0x0) {
                                                            eax = &arg_4d5524;
                                                            do {
                                                                    if (*eax == 0x3) {
                                                                            edx = 0x0;
                                                                            if (eax[0x1] == 0x0) {
                                                                                    edx = 0x0;
                                                                                    *eax = 0x1;
                                                                                    eax[0x1] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = ecx + 0x1;
                                                                    eax = eax + 0x8;
                                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                                    }
                                            }
                                            eax = decomp_var_38 - 0x10;
                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                            if (edx <= 0x1) {
                                                    esp = esp - 0x4;
                                                    decomp_var_5c = eax;
                                                    eax = *(**eax + 0x4);
                                                    eax = (eax)(decomp_var_5c);
                                            }
                                            *0x0 = arg_bd34;
                                            &decomp_var_44 = decomp_var_4c;
                                    }
                            }
                    }
                    else {
                            ebx = decomp_var_40;
                            esi = *(ebx[0x2] + 0x2404);
                            if (esi > 0x0) {
                                    eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                            }
                            else {
                                    if (*(int8_t *)byte_baed43 == 0x1) {
                                            edx = 0x0;
                                            ecx = 0x0;
                                            if (esi > 0x0) {
                                                    eax = &arg_4d5524;
                                                    do {
                                                            if (*eax == 0x3) {
                                                                    edx = 0x0;
                                                                    if (eax[0x1] == 0x0) {
                                                                            edx = 0x0;
                                                                            *eax = 0x1;
                                                                            eax[0x1] = 0x0;
                                                                    }
                                                            }
                                                            ecx = ecx + 0x1;
                                                            eax = eax + 0x8;
                                                    } while (ecx < *(ebx[0x2] + 0x2404));
                                            }
                                    }
                                    eax = decomp_var_38 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            decomp_var_5c = eax;
                                            eax = *(**eax + 0x4);
                                            eax = (eax)(decomp_var_5c);
                                    }
                                    *0x0 = arg_bd34;
                                    &decomp_var_44 = decomp_var_4c;
                            }
                    }
            }
            else {
                    ebx = decomp_var_40;
                    esi = *(ebx[0x2] + 0x2404);
                    if (esi > 0x0) {
                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                    }
                    else {
                            if (*(int8_t *)byte_baed43 == 0x1) {
                                    edx = 0x0;
                                    ecx = 0x0;
                                    if (esi > 0x0) {
                                            eax = &arg_4d5524;
                                            do {
                                                    if (*eax == 0x3) {
                                                            edx = 0x0;
                                                            if (eax[0x1] == 0x0) {
                                                                    edx = 0x0;
                                                                    *eax = 0x1;
                                                                    eax[0x1] = 0x0;
                                                            }
                                                    }
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x8;
                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                    }
                            }
                            eax = decomp_var_38 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            if (edx <= 0x1) {
                                    esp = esp - 0x4;
                                    decomp_var_5c = eax;
                                    eax = *(**eax + 0x4);
                                    eax = (eax)(decomp_var_5c);
                            }
                            *0x0 = arg_bd34;
                            &decomp_var_44 = decomp_var_4c;
                    }
            }
    }
    else {
            if (!bool_198) {
                    ebx = 0x0;
                    if (*(decomp_var_34[0x2] + 0x2404) > 0x0) {
                            while (true) {
                                    if (ebx == ebp) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    if (ebx == edx) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    eax = edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx;
                                    ecx = *(&decomp_var_4c + eax + 0xd4);
                                    if (ecx <= 0x1) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    if (ecx != *(&decomp_var_4c + eax + 0x7bc)) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    esp = esp - 0x4;
                                    decomp_var_38 = edx & 0xff | 0x4100;
                                    sub_46db50();
                                    eax = sub_4273a0(decomp_var_50);
                                    if (eax[0x6] >= 0x10) {
                                            eax = eax[0x1];
                                    }
                                    else {
                                            eax = eax + 0x4;
                                    }
                                    decomp_var_50 = eax;
                                    decomp_var_54 = "It would seem our best ally (%s) has been severely pressured by another power ";
                                    decomp_var_58 = &decomp_var_2c;
                                    sub_410c10(decomp_var_58, "It would seem our best ally (%s) has been severely pressured by another power ", decomp_var_50);
                                    edx = **(decomp_var_2c - 0x10);
                                    eax = edx[0x4];
                                    esi = decomp_var_2c - 0x10;
                                    esp = (esp - 0xc) + 0xc;
                                    eax = (eax)();
                                    ecx = esi + 0xc;
                                    if (esi[0x3] >= 0x0) {
                                            if (eax == *esi) {
                                                    edi = esi;
                                                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
                                                    esp = esp - 0x8;
                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                    eax = edi + 0x10 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    edx = *dword_4c6bc4;
                                                    *(int8_t *)byte_baed45 = 0x1;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                            continue;
                                                    }
                                                    temp_3 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    ecx = esi[0x1];
                                                    edx = *eax;
                                                    edx = *edx;
                                                    esp = esp - 0x8;
                                                    edi = (edx)(ecx, 0x1);
                                                    if (edi != 0x0) {
                                                            edi[0x1] = esi[0x1];
                                                            eax = esi[0x1];
                                                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                            esp = (esp - 0x10) + 0x10;
                                                            esp = esp - 0x8;
                                                            eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                            eax = edi + 0x10 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    (*(**eax + 0x4))(eax);
                                                            }
                                                            edx = *dword_4c6bc4;
                                                            *(int8_t *)byte_baed45 = 0x1;
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    else {
                                                            temp_3 = 0x1;
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            ecx = esi[0x1];
                                            edx = *eax;
                                            edx = *edx;
                                            esp = esp - 0x8;
                                            edi = (edx)(ecx, 0x1);
                                            if (edi != 0x0) {
                                                    edi[0x1] = esi[0x1];
                                                    eax = esi[0x1];
                                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                    esp = (esp - 0x10) + 0x10;
                                                    esp = esp - 0x8;
                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                    eax = edi + 0x10 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    edx = *dword_4c6bc4;
                                                    *(int8_t *)byte_baed45 = 0x1;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                            continue;
                                                    }
                                                    temp_3 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    temp_3 = 0x1;
                                                    break;
                                            }
                                    }
                            }
                            if (temp_3 != 0x0) {
                                    eax = sub_40b6d0();
                            }
                            else {
                                    ebx = decomp_var_40;
                                    esi = *(ebx[0x2] + 0x2404);
                                    if (esi > 0x0) {
                                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                    }
                                    else {
                                            if (*(int8_t *)byte_baed43 == 0x1) {
                                                    edx = 0x0;
                                                    ecx = 0x0;
                                                    if (esi > 0x0) {
                                                            eax = &arg_4d5524;
                                                            do {
                                                                    if (*eax == 0x3) {
                                                                            edx = 0x0;
                                                                            if (eax[0x1] == 0x0) {
                                                                                    edx = 0x0;
                                                                                    *eax = 0x1;
                                                                                    eax[0x1] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = ecx + 0x1;
                                                                    eax = eax + 0x8;
                                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                                    }
                                            }
                                            eax = decomp_var_38 - 0x10;
                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                            if (edx <= 0x1) {
                                                    esp = esp - 0x4;
                                                    decomp_var_5c = eax;
                                                    eax = *(**eax + 0x4);
                                                    eax = (eax)(decomp_var_5c);
                                            }
                                            *0x0 = arg_bd34;
                                            &decomp_var_44 = decomp_var_4c;
                                    }
                            }
                    }
                    else {
                            ebx = decomp_var_40;
                            esi = *(ebx[0x2] + 0x2404);
                            if (esi > 0x0) {
                                    eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                            }
                            else {
                                    if (*(int8_t *)byte_baed43 == 0x1) {
                                            edx = 0x0;
                                            ecx = 0x0;
                                            if (esi > 0x0) {
                                                    eax = &arg_4d5524;
                                                    do {
                                                            if (*eax == 0x3) {
                                                                    edx = 0x0;
                                                                    if (eax[0x1] == 0x0) {
                                                                            edx = 0x0;
                                                                            *eax = 0x1;
                                                                            eax[0x1] = 0x0;
                                                                    }
                                                            }
                                                            ecx = ecx + 0x1;
                                                            eax = eax + 0x8;
                                                    } while (ecx < *(ebx[0x2] + 0x2404));
                                            }
                                    }
                                    eax = decomp_var_38 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            decomp_var_5c = eax;
                                            eax = *(**eax + 0x4);
                                            eax = (eax)(decomp_var_5c);
                                    }
                                    *0x0 = arg_bd34;
                                    &decomp_var_44 = decomp_var_4c;
                            }
                    }
            }
            else {
                    ebx = decomp_var_40;
                    esi = *(ebx[0x2] + 0x2404);
                    if (esi > 0x0) {
                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                    }
                    else {
                            if (*(int8_t *)byte_baed43 == 0x1) {
                                    edx = 0x0;
                                    ecx = 0x0;
                                    if (esi > 0x0) {
                                            eax = &arg_4d5524;
                                            do {
                                                    if (*eax == 0x3) {
                                                            edx = 0x0;
                                                            if (eax[0x1] == 0x0) {
                                                                    edx = 0x0;
                                                                    *eax = 0x1;
                                                                    eax[0x1] = 0x0;
                                                            }
                                                    }
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x8;
                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                    }
                            }
                            eax = decomp_var_38 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            if (edx <= 0x1) {
                                    esp = esp - 0x4;
                                    decomp_var_5c = eax;
                                    eax = *(**eax + 0x4);
                                    eax = (eax)(decomp_var_5c);
                            }
                            *0x0 = arg_bd34;
                            &decomp_var_44 = decomp_var_4c;
                    }
            }
    }
    return eax;

.l39:
    bool_346 = eax[0x1] > 0x0;
    bool_343 = eax[0x1] < 0x0;
    if (!bool_346) {
            if (!bool_343) {
                    if (*eax < 0x2 && ecx != ebp) {
                            decomp_var_21 = 0x1;
                    }
            }
            else {
                    if (ecx != ebp) {
                            decomp_var_21 = 0x1;
                    }
            }
    }
    ecx = ecx + 0x1;
    eax = eax + 0x8;
    if (ecx < edx) {
            continue;
    }
    break;

.l50:
    eax = *(decomp_var_34[0x2] + 0x2404);
    decomp_var_20 = decomp_var_20 + 0x15;
    ecx = ecx + 0x1;
    decomp_var_30 = ecx;
    if (ecx < eax) {
            continue;
    }
    ebp = decomp_var_4;
    asm { fstp       st1 };
    edi = decomp_var_34;
    asm { fstp       st0 };
    temp_2 = 0x3;
    break;

.l49:
    decomp_var_4 = ecx * 0x4;
    ebp = 0x0;
    goto .l53;

.l42:
    if (temp_0 == 0x0) {
            *(&decomp_var_28 + (edi * 0x15 + decomp_var_14) * 0x4 + 0x7bc) = *(&decomp_var_28 + (edi * 0x15 + decomp_var_14) * 0x4 + 0x7bc) + 0x1;
    }
    esi = arg_18;
    ebx = arg_14;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x8] == 0x2) goto loc_435723;
    goto loc_435684;

.l31:
    eax = sub_40b6d0();
    return eax;

.l111:
    if (temp_2 == 0x1) goto .l32;
    goto .l112;

.l46:
    if (temp_1 != 0x0) {
            if (temp_1 != 0x1) {
                    if (temp_1 != 0x2) {
                            eax = *(decomp_var_34[0x2] + 0x2404);
                            decomp_var_20 = decomp_var_20 + 0x15;
                            ecx = ecx + 0x1;
                            decomp_var_30 = ecx;
                            if (ecx < eax) {
                                    continue;
                            }
                            ebp = decomp_var_4;
                            asm { fstp       st1 };
                            edi = decomp_var_34;
                            asm { fstp       st0 };
                            temp_2 = 0x3;
                            break;
                    }
                    else {
                            temp_2 = 0x2;
                            break;
                    }
            }
            else {
                    temp_2 = 0x1;
                    break;
            }
    }
    else {
            temp_2 = 0x0;
            break;
    }
    goto .l45;
    if (decomp_var_21 == 0x0 && decomp_var_22 == 0x1) {
            ecx = 0x0;
            if (edx > 0x0) {
                    while (true) {
                            if (*(&decomp_var_4c + ecx * 0x4 + 0x7c) >= 0x2) {
                                    ecx = ecx + 0x1;
                                    if (ecx < edx) {
                                            continue;
                                    }
                                    temp_5 = 0x0;
                                    break;
                            }
                            if (ecx != ebp) {
                                    eax = *(&decomp_var_4c + ecx * 0x4 + 0x7c);
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d5528) = eax;
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d552c) = eax & 0x80000000 ? 0xffffffff : 0x0;
                                    temp_5 = 0x1;
                                    break;
                            }
                            ecx = ecx + 0x1;
                            if (ecx < edx) {
                                    continue;
                            }
                            temp_5 = 0x0;
                            break;
                    }
            }
    }
    goto .l29;

.l51:
    if (temp_2 == 0x0) goto .l14;
    goto .l35;

.l53:
    if (ecx != ebx) {
            ecx = decomp_var_10 + ebx;
            edx = *(&decomp_var_3c + ecx * 0x4 + 0x7bc);
            decomp_var_18 = edx;
            if (edx > 0x0) {
                    asm { fild       dword [esp+ecx*4+0x3c+152] };
                    asm { fidiv      dword [esp+0x3c+-24] };
                    asm { fstp       dword [esp+0x3c+-40] };
            }
            else {
                    asm { fxch       st0, st1 };
                    asm { fst        dword [esp+0x3c+-40] };
                    asm { fxch       st0, st1 };
            }
            ebp = 0x0;
            edi = decomp_var_4;
            eax = *(&decomp_var_3c + edi + 0x7bc);
            decomp_var_18 = eax;
            if (eax > 0x0) {
                    asm { fild       dword [esp+edi+0x3c+152] };
                    asm { fidiv      dword [esp+0x3c+-24] };
                    asm { fstp       dword [esp+0x3c+-24] };
            }
            else {
                    asm { fxch       st0, st1 };
                    asm { fst        dword [esp+0x3c+-24] };
                    asm { fxch       st0, st1 };
            }
            asm { fld        dword [esp+0x3c+-40] };
            asm { fucom      st2 };
            asm { fnstsw     ax };
            asm { fstp       st2 };
            if (PARITY(HIBYTE(eax) & 0x44)) {
                    asm { fld        st0 };
                    asm { fucomp     st2 };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x44)) {
                            *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + 0x1;
                            asm { fstp       st1 };
                            bool_1022 = asm { fstp       st1 };
                            asm { fcomp      dword [esp+0x3c+-24] };
                            *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                            asm { fnstsw     ax };
                            if (!PARITY(HIBYTE(eax) & 0x44)) {
                                    esp = esp - 0x4;
                                    *(ecx * 0x8 + 0x4d5528) = 0x5;
                                    *(ecx * 0x8 + 0x4d552c) = 0x0;
                                    decomp_var_28 = ebx & 0xff | 0x4100;
                                    sub_46db50();
                                    eax = sub_4273a0(decomp_var_40);
                                    if (eax[0x6] >= 0x10) {
                                            esi = eax[0x1];
                                    }
                                    else {
                                            esi = eax + 0x4;
                                    }
                                    esp = esp - 0x4;
                                    decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                    sub_46db50();
                                    eax = sub_4273a0(decomp_var_40);
                                    if (eax[0x6] >= 0x10) {
                                            eax = eax[0x1];
                                    }
                                    else {
                                            eax = eax + 0x4;
                                    }
                                    ebp = 0x0;
                                    decomp_var_40 = esi;
                                    decomp_var_44 = eax;
                                    decomp_var_48 = "Seems (%s) and (%s) have applied no pressure to each other";
                                    decomp_var_4c = &decomp_var_1c;
                                    sub_410c10(decomp_var_4c, "Seems (%s) and (%s) have applied no pressure to each other", decomp_var_44);
                                    eax = *(**(decomp_var_1c - 0x10) + 0x10);
                                    esi = decomp_var_1c - 0x10;
                                    esp = (esp - 0x10) + 0x10;
                                    decomp_var_c = 0x2;
                                    eax = (eax)();
                                    edx = esi + 0xc;
                                    if (esi[0x3] >= 0x0) {
                                            if (eax == *esi) {
                                                    edi = esi;
                                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                                                    edi = edi + 0x10;
                                                    edx = &decomp_var_1c;
                                                    eax = &arg_8;
                                                    decomp_var_50 = edx;
                                                    esp = esp - 0x8;
                                                    decomp_var_54 = eax;
                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                    eax = edi - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            decomp_var_50 = eax;
                                                            (*(**eax + 0x4))(decomp_var_50);
                                                    }
                                                    esi = 0x1;
                                                    ecx = decomp_var_34;
                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                    edx = ecx[0x2];
                                                    asm { fldz };
                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                    ecx = decomp_var_30;
                                                    ebx = ebx + esi;
                                                    if (ebx < edx[0x901]) {
                                                            continue;
                                                    }
                                                    temp_1 = 0x3;
                                                    break;
                                            }
                                            else {
                                                    ebp = 0x0;
                                                    decomp_var_50 = 0x1;
                                                    esp = esp - 0x8;
                                                    decomp_var_54 = esi[0x1];
                                                    ecx = eax;
                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                    if (edi != 0x0) {
                                                            edi[0x1] = esi[0x1];
                                                            eax = esi[0x1];
                                                            decomp_var_58 = eax + 0x1;
                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                            esp = (esp - 0x10) + 0x10;
                                                            edi = edi + 0x10;
                                                            edx = &decomp_var_1c;
                                                            eax = &arg_8;
                                                            decomp_var_50 = edx;
                                                            esp = esp - 0x8;
                                                            decomp_var_54 = eax;
                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                            eax = edi - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    decomp_var_50 = eax;
                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                            }
                                                            esi = 0x1;
                                                            ecx = decomp_var_34;
                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                            edx = ecx[0x2];
                                                            asm { fldz };
                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                            ecx = decomp_var_30;
                                                            ebx = ebx + esi;
                                                            if (ebx < edx[0x901]) {
                                                                    continue;
                                                            }
                                                            temp_1 = 0x3;
                                                            break;
                                                    }
                                                    else {
                                                            temp_1 = 0x0;
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            decomp_var_50 = 0x1;
                                            esp = esp - 0x8;
                                            decomp_var_54 = esi[0x1];
                                            ecx = eax;
                                            edi = (**eax)(decomp_var_54, 0x1);
                                            if (edi != ebp) {
                                                    edi[0x1] = esi[0x1];
                                                    eax = esi[0x1];
                                                    decomp_var_58 = eax + 0x1;
                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                    esp = (esp - 0x10) + 0x10;
                                                    edi = edi + 0x10;
                                                    edx = &decomp_var_1c;
                                                    eax = &arg_8;
                                                    decomp_var_50 = edx;
                                                    esp = esp - 0x8;
                                                    decomp_var_54 = eax;
                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                    eax = edi - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            decomp_var_50 = eax;
                                                            (*(**eax + 0x4))(decomp_var_50);
                                                    }
                                                    esi = 0x1;
                                                    ecx = decomp_var_34;
                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                    edx = ecx[0x2];
                                                    asm { fldz };
                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                    ecx = decomp_var_30;
                                                    ebx = ebx + esi;
                                                    if (ebx < edx[0x901]) {
                                                            continue;
                                                    }
                                                    temp_1 = 0x3;
                                                    break;
                                            }
                                            else {
                                                    temp_1 = 0x0;
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    esi = 0x1;
                                    ecx = decomp_var_34;
                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                    edx = ecx[0x2];
                                    asm { fldz };
                                    decomp_var_14 = decomp_var_14 + 0x54;
                                    ecx = decomp_var_30;
                                    ebx = ebx + esi;
                                    if (ebx < edx[0x901]) {
                                            continue;
                                    }
                                    temp_1 = 0x3;
                                    break;
                            }
                    }
                    else {
                            asm { fld1 };
                            asm { fucomp     st2 };
                            asm { fnstsw     ax };
                            if (!PARITY(HIBYTE(eax) & 0x44)) {
                                    if (edx == 0x1) {
                                            ebp = 0x0;
                                            if (*(&decomp_var_3c + ecx * 0x4 + 0xea4) == 0x0) {
                                                    ebp = 0x0;
                                                    if (*(&decomp_var_3c + edi + 0xea4) == 0x0) {
                                                            ebp = 0x0;
                                                            bool_1005 = *(ecx * 0x8 + 0x4d552c) > 0x0;
                                                            if (*(ecx * 0x8 + 0x4d552c) >= 0x0) {
                                                                    if (!bool_1005) {
                                                                            esi = 0x1;
                                                                            if (*(ecx * 0x8 + 0x4d5528) > 0x1) {
                                                                                    *(ecx * 0x8 + 0x4d5528) = 0x2;
                                                                                    asm { fstp       st1 };
                                                                                    *(ecx * 0x8 + 0x4d552c) = ebp;
                                                                                    asm { fstp       st0 };
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_28 = ebx & 0xff | 0x4100;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_40);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            esi = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            esi = eax + 0x4;
                                                                                    }
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_40);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            eax = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x4;
                                                                                    }
                                                                                    decomp_var_40 = esi;
                                                                                    decomp_var_44 = eax;
                                                                                    decomp_var_48 = 0x4b0e38;
                                                                                    decomp_var_4c = &decomp_var_1c;
                                                                                    sub_410c10(decomp_var_4c, 0x4b0e38, decomp_var_44);
                                                                                    esi = decomp_var_1c - 0x10;
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                                                    edx = esi + 0xc;
                                                                                    if (esi[0x3] >= ebp) {
                                                                                            if (eax == *esi) {
                                                                                                    edi = esi;
                                                                                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                                                    edi = edi + 0x10;
                                                                                                    edx = &saved_fp;
                                                                                                    eax = &arg_20;
                                                                                                    decomp_var_50 = edx;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = eax;
                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                    eax = edi - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                    if (edx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_50 = eax;
                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                    }
                                                                                                    esi = 0x1;
                                                                                                    ecx = decomp_var_34;
                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                    edx = ecx[0x2];
                                                                                                    asm { fldz };
                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                    ecx = decomp_var_30;
                                                                                                    ebx = ebx + esi;
                                                                                                    if (ebx < edx[0x901]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    decomp_var_50 = 0x1;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = esi[0x1];
                                                                                                    ecx = eax;
                                                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                                                    if (edi != ebp) {
                                                                                                            edi[0x1] = esi[0x1];
                                                                                                            eax = esi[0x1];
                                                                                                            decomp_var_58 = eax + 0x1;
                                                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                            edi = edi + 0x10;
                                                                                                            edx = &saved_fp;
                                                                                                            eax = &arg_20;
                                                                                                            decomp_var_50 = edx;
                                                                                                            esp = esp - 0x8;
                                                                                                            decomp_var_54 = eax;
                                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                            eax = edi - 0x10;
                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                            if (edx <= 0x1) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    decomp_var_50 = eax;
                                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                                            }
                                                                                                            esi = 0x1;
                                                                                                            ecx = decomp_var_34;
                                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                            edx = ecx[0x2];
                                                                                                            asm { fldz };
                                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                            ecx = decomp_var_30;
                                                                                                            ebx = ebx + esi;
                                                                                                            if (ebx < edx[0x901]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            temp_1 = 0x3;
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_1 = 0x1;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            decomp_var_50 = 0x1;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = esi[0x1];
                                                                                            ecx = eax;
                                                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                                                            if (edi != ebp) {
                                                                                                    edi[0x1] = esi[0x1];
                                                                                                    eax = esi[0x1];
                                                                                                    decomp_var_58 = eax + 0x1;
                                                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                    edi = edi + 0x10;
                                                                                                    edx = &saved_fp;
                                                                                                    eax = &arg_20;
                                                                                                    decomp_var_50 = edx;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = eax;
                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                    eax = edi - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                    if (edx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_50 = eax;
                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                    }
                                                                                                    esi = 0x1;
                                                                                                    ecx = decomp_var_34;
                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                    edx = ecx[0x2];
                                                                                                    asm { fldz };
                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                    ecx = decomp_var_30;
                                                                                                    ebx = ebx + esi;
                                                                                                    if (ebx < edx[0x901]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_1 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fxch       st0, st1 };
                                                                                    asm { fcomp      qword [qword_value_4603129179135383962] };
                                                                                    asm { fnstsw     ax };
                                                                                    bool_885 = (HIBYTE(eax) & 0x5) > 0x0;
                                                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                                            asm { fcomp      dword [esp+0x3c+-24] };
                                                                                            *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + esi;
                                                                                            *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                                                            asm { fnstsw     ax };
                                                                                            if (!PARITY(HIBYTE(eax) & 0x44)) {
                                                                                                    *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + 0x1;
                                                                                                    bool_908 = *(ecx * 0x8 + 0x4d5528) < 0x0;
                                                                                                    esp = esp - 0x4;
                                                                                                    *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                                                                    decomp_var_28 = ebx & 0xff | 0x4100;
                                                                                                    sub_46db50();
                                                                                                    eax = sub_4273a0(decomp_var_40);
                                                                                                    if (!bool_908) {
                                                                                                            esi = eax[0x1];
                                                                                                    }
                                                                                                    else {
                                                                                                            esi = eax + 0x4;
                                                                                                    }
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                                                                    sub_46db50();
                                                                                                    eax = sub_4273a0(decomp_var_40);
                                                                                                    if (eax[0x6] >= 0x10) {
                                                                                                            eax = eax[0x1];
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = eax + 0x4;
                                                                                                    }
                                                                                                    decomp_var_40 = esi;
                                                                                                    decomp_var_44 = eax;
                                                                                                    decomp_var_48 = "Seems (%s) and (%s) have applied little pressure to each other";
                                                                                                    decomp_var_4c = &decomp_var_1c;
                                                                                                    sub_410c10(decomp_var_4c, "Seems (%s) and (%s) have applied little pressure to each other", decomp_var_44);
                                                                                                    esi = decomp_var_1c - 0x10;
                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                    eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                                                                    edx = esi + 0xc;
                                                                                                    if (esi[0x3] >= ebp) {
                                                                                                            if (eax == *esi) {
                                                                                                                    edi = esi;
                                                                                                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                                                                    edi = edi + 0x10;
                                                                                                                    edx = &decomp_var_c;
                                                                                                                    eax = &arg_14;
                                                                                                                    decomp_var_50 = edx;
                                                                                                                    esp = esp - 0x8;
                                                                                                                    decomp_var_54 = eax;
                                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                                    eax = edi - 0x10;
                                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                                    if (edx <= 0x1) {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            decomp_var_50 = eax;
                                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                                    }
                                                                                                                    esi = 0x1;
                                                                                                                    ecx = decomp_var_34;
                                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                                    edx = ecx[0x2];
                                                                                                                    asm { fldz };
                                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                                    ecx = decomp_var_30;
                                                                                                                    ebx = ebx + esi;
                                                                                                                    if (ebx < edx[0x901]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    temp_1 = 0x3;
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    decomp_var_50 = 0x1;
                                                                                                                    esp = esp - 0x8;
                                                                                                                    decomp_var_54 = esi[0x1];
                                                                                                                    ecx = eax;
                                                                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                                                                    if (edi != ebp) {
                                                                                                                            edi[0x1] = esi[0x1];
                                                                                                                            eax = esi[0x1];
                                                                                                                            decomp_var_58 = eax + 0x1;
                                                                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                            edi = edi + 0x10;
                                                                                                                            edx = &decomp_var_c;
                                                                                                                            eax = &arg_14;
                                                                                                                            decomp_var_50 = edx;
                                                                                                                            esp = esp - 0x8;
                                                                                                                            decomp_var_54 = eax;
                                                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                                            eax = edi - 0x10;
                                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                                            if (edx <= 0x1) {
                                                                                                                                    esp = esp - 0x4;
                                                                                                                                    decomp_var_50 = eax;
                                                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                                                            }
                                                                                                                            esi = 0x1;
                                                                                                                            ecx = decomp_var_34;
                                                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                                            edx = ecx[0x2];
                                                                                                                            asm { fldz };
                                                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                                            ecx = decomp_var_30;
                                                                                                                            ebx = ebx + esi;
                                                                                                                            if (ebx < edx[0x901]) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            temp_1 = 0x3;
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            temp_1 = 0x2;
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            decomp_var_50 = 0x1;
                                                                                                            esp = esp - 0x8;
                                                                                                            decomp_var_54 = esi[0x1];
                                                                                                            ecx = eax;
                                                                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                                                                            if (edi != ebp) {
                                                                                                                    edi[0x1] = esi[0x1];
                                                                                                                    eax = esi[0x1];
                                                                                                                    decomp_var_58 = eax + 0x1;
                                                                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                    edi = edi + 0x10;
                                                                                                                    edx = &decomp_var_c;
                                                                                                                    eax = &arg_14;
                                                                                                                    decomp_var_50 = edx;
                                                                                                                    esp = esp - 0x8;
                                                                                                                    decomp_var_54 = eax;
                                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                                    eax = edi - 0x10;
                                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                                    if (edx <= 0x1) {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            decomp_var_50 = eax;
                                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                                    }
                                                                                                                    esi = 0x1;
                                                                                                                    ecx = decomp_var_34;
                                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                                    edx = ecx[0x2];
                                                                                                                    asm { fldz };
                                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                                    ecx = decomp_var_30;
                                                                                                                    ebx = ebx + esi;
                                                                                                                    if (ebx < edx[0x901]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    temp_1 = 0x3;
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    temp_1 = 0x2;
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    esi = 0x1;
                                                                                                    ecx = decomp_var_34;
                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                    edx = ecx[0x2];
                                                                                                    asm { fldz };
                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                    ecx = decomp_var_30;
                                                                                                    ebx = ebx + esi;
                                                                                                    if (ebx < edx[0x901]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fstp       st0 };
                                                                                            bool_894 = asm { fstp       st0 };
                                                                                            if (!bool_885) {
                                                                                                    if (bool_894 || *(ecx * 0x8 + 0x4d5528) < 0x5) {
                                                                                                            *(ecx * 0x8 + 0x4d5528) = 0x1;
                                                                                                            *(ecx * 0x8 + 0x4d552c) = ebp;
                                                                                                    }
                                                                                            }
                                                                                            esi = 0x1;
                                                                                            ecx = decomp_var_34;
                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                            edx = ecx[0x2];
                                                                                            asm { fldz };
                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                            ecx = decomp_var_30;
                                                                                            ebx = ebx + esi;
                                                                                            if (ebx < edx[0x901]) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x3;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(ecx * 0x8 + 0x4d5528) = 0x2;
                                                                            asm { fstp       st1 };
                                                                            *(ecx * 0x8 + 0x4d552c) = ebp;
                                                                            asm { fstp       st0 };
                                                                            esp = esp - 0x4;
                                                                            decomp_var_28 = ebx & 0xff | 0x4100;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_40);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    esi = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    esi = eax + 0x4;
                                                                            }
                                                                            esp = esp - 0x4;
                                                                            decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_40);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            ebp = 0x0;
                                                                            decomp_var_40 = esi;
                                                                            decomp_var_44 = eax;
                                                                            decomp_var_48 = 0x4b0e38;
                                                                            decomp_var_4c = &decomp_var_1c;
                                                                            sub_410c10(decomp_var_4c, 0x4b0e38, decomp_var_44);
                                                                            esi = decomp_var_1c - 0x10;
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                                            edx = esi + 0xc;
                                                                            if (esi[0x3] >= 0x0) {
                                                                                    if (eax == *esi) {
                                                                                            edi = esi;
                                                                                            *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                                            edi = edi + 0x10;
                                                                                            edx = &saved_fp;
                                                                                            eax = &arg_20;
                                                                                            decomp_var_50 = edx;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = eax;
                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                            eax = edi - 0x10;
                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                            if (edx <= 0x1) {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_50 = eax;
                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                            }
                                                                                            esi = 0x1;
                                                                                            ecx = decomp_var_34;
                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                            edx = ecx[0x2];
                                                                                            asm { fldz };
                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                            ecx = decomp_var_30;
                                                                                            ebx = ebx + esi;
                                                                                            if (ebx < edx[0x901]) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x3;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ebp = 0x0;
                                                                                            decomp_var_50 = 0x1;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = esi[0x1];
                                                                                            ecx = eax;
                                                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                                                            if (edi != 0x0) {
                                                                                                    edi[0x1] = esi[0x1];
                                                                                                    eax = esi[0x1];
                                                                                                    decomp_var_58 = eax + 0x1;
                                                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                    edi = edi + 0x10;
                                                                                                    edx = &saved_fp;
                                                                                                    eax = &arg_20;
                                                                                                    decomp_var_50 = edx;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = eax;
                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                    eax = edi - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                    if (edx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_50 = eax;
                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                    }
                                                                                                    esi = 0x1;
                                                                                                    ecx = decomp_var_34;
                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                    edx = ecx[0x2];
                                                                                                    asm { fldz };
                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                    ecx = decomp_var_30;
                                                                                                    ebx = ebx + esi;
                                                                                                    if (ebx < edx[0x901]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_1 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebp = 0x0;
                                                                                    decomp_var_50 = 0x1;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_54 = esi[0x1];
                                                                                    ecx = eax;
                                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                                    if (edi != 0x0) {
                                                                                            edi[0x1] = esi[0x1];
                                                                                            eax = esi[0x1];
                                                                                            decomp_var_58 = eax + 0x1;
                                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                            edi = edi + 0x10;
                                                                                            edx = &saved_fp;
                                                                                            eax = &arg_20;
                                                                                            decomp_var_50 = edx;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = eax;
                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                            eax = edi - 0x10;
                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                            if (edx <= 0x1) {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_50 = eax;
                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                            }
                                                                                            esi = 0x1;
                                                                                            ecx = decomp_var_34;
                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                            edx = ecx[0x2];
                                                                                            asm { fldz };
                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                            ecx = decomp_var_30;
                                                                                            ebx = ebx + esi;
                                                                                            if (ebx < edx[0x901]) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x3;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_1 = 0x1;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    asm { fxch       st0, st1 };
                                                                    asm { fcomp      qword [qword_value_4603129179135383962] };
                                                                    asm { fnstsw     ax };
                                                                    bool_965 = (HIBYTE(eax) & 0x5) > 0x0;
                                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                            esi = 0x1;
                                                                            asm { fcomp      dword [esp+0x3c+-24] };
                                                                            *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + esi;
                                                                            *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                                            asm { fnstsw     ax };
                                                                            if (!PARITY(HIBYTE(eax) & 0x44)) {
                                                                                    *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + 0x1;
                                                                                    bool_958 = *(ecx * 0x8 + 0x4d5528) < 0x0;
                                                                                    esp = esp - 0x4;
                                                                                    *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                                                    decomp_var_28 = ebx & 0xff | 0x4100;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_40);
                                                                                    if (!bool_958) {
                                                                                            esi = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            esi = eax + 0x4;
                                                                                    }
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_40);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            eax = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x4;
                                                                                    }
                                                                                    decomp_var_40 = esi;
                                                                                    decomp_var_44 = eax;
                                                                                    decomp_var_48 = "Seems (%s) and (%s) have applied little pressure to each other";
                                                                                    decomp_var_4c = &decomp_var_1c;
                                                                                    sub_410c10(decomp_var_4c, "Seems (%s) and (%s) have applied little pressure to each other", decomp_var_44);
                                                                                    esi = decomp_var_1c - 0x10;
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                                                    edx = esi + 0xc;
                                                                                    if (esi[0x3] >= ebp) {
                                                                                            if (eax == *esi) {
                                                                                                    edi = esi;
                                                                                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                                                    edi = edi + 0x10;
                                                                                                    edx = &decomp_var_c;
                                                                                                    eax = &arg_14;
                                                                                                    decomp_var_50 = edx;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = eax;
                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                    eax = edi - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                    if (edx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_50 = eax;
                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                    }
                                                                                                    esi = 0x1;
                                                                                                    ecx = decomp_var_34;
                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                    edx = ecx[0x2];
                                                                                                    asm { fldz };
                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                    ecx = decomp_var_30;
                                                                                                    ebx = ebx + esi;
                                                                                                    if (ebx < edx[0x901]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ebp = 0x0;
                                                                                                    decomp_var_50 = 0x1;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = esi[0x1];
                                                                                                    ecx = eax;
                                                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                                                    if (edi != 0x0) {
                                                                                                            edi[0x1] = esi[0x1];
                                                                                                            eax = esi[0x1];
                                                                                                            decomp_var_58 = eax + 0x1;
                                                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                            edi = edi + 0x10;
                                                                                                            edx = &decomp_var_c;
                                                                                                            eax = &arg_14;
                                                                                                            decomp_var_50 = edx;
                                                                                                            esp = esp - 0x8;
                                                                                                            decomp_var_54 = eax;
                                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                            eax = edi - 0x10;
                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                            if (edx <= 0x1) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    decomp_var_50 = eax;
                                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                                            }
                                                                                                            esi = 0x1;
                                                                                                            ecx = decomp_var_34;
                                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                            edx = ecx[0x2];
                                                                                                            asm { fldz };
                                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                            ecx = decomp_var_30;
                                                                                                            ebx = ebx + esi;
                                                                                                            if (ebx < edx[0x901]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            temp_1 = 0x3;
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_1 = 0x2;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            decomp_var_50 = 0x1;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = esi[0x1];
                                                                                            ecx = eax;
                                                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                                                            if (edi != ebp) {
                                                                                                    edi[0x1] = esi[0x1];
                                                                                                    eax = esi[0x1];
                                                                                                    decomp_var_58 = eax + 0x1;
                                                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                    edi = edi + 0x10;
                                                                                                    edx = &decomp_var_c;
                                                                                                    eax = &arg_14;
                                                                                                    decomp_var_50 = edx;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = eax;
                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                    eax = edi - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                    if (edx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_50 = eax;
                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                    }
                                                                                                    esi = 0x1;
                                                                                                    ecx = decomp_var_34;
                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                    edx = ecx[0x2];
                                                                                                    asm { fldz };
                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                    ecx = decomp_var_30;
                                                                                                    ebx = ebx + esi;
                                                                                                    if (ebx < edx[0x901]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_1 = 0x2;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esi = 0x1;
                                                                                    ecx = decomp_var_34;
                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                    edx = ecx[0x2];
                                                                                    asm { fldz };
                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                    ecx = decomp_var_30;
                                                                                    ebx = ebx + esi;
                                                                                    if (ebx < edx[0x901]) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x3;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            asm { fstp       st0 };
                                                                            bool_891 = asm { fstp       st0 };
                                                                            if (!bool_965) {
                                                                                    if (bool_891 || *(ecx * 0x8 + 0x4d5528) < 0x5) {
                                                                                            *(ecx * 0x8 + 0x4d5528) = 0x1;
                                                                                            *(ecx * 0x8 + 0x4d552c) = ebp;
                                                                                    }
                                                                            }
                                                                            esi = 0x1;
                                                                            ecx = decomp_var_34;
                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                            edx = ecx[0x2];
                                                                            asm { fldz };
                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                            ecx = decomp_var_30;
                                                                            ebx = ebx + esi;
                                                                            if (ebx < edx[0x901]) {
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x3;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            asm { fxch       st0, st1 };
                                                            asm { fcomp      qword [qword_value_4603129179135383962] };
                                                            asm { fnstsw     ax };
                                                            bool_881 = (HIBYTE(eax) & 0x5) > 0x0;
                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                    esi = 0x1;
                                                                    asm { fcomp      dword [esp+0x3c+-24] };
                                                                    *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + esi;
                                                                    *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                                    asm { fnstsw     ax };
                                                                    if (!PARITY(HIBYTE(eax) & 0x44)) {
                                                                            *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + 0x1;
                                                                            bool_982 = *(ecx * 0x8 + 0x4d5528) < 0x0;
                                                                            esp = esp - 0x4;
                                                                            *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                                            decomp_var_28 = ebx & 0xff | 0x4100;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_40);
                                                                            if (!bool_982) {
                                                                                    esi = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    esi = eax + 0x4;
                                                                            }
                                                                            esp = esp - 0x4;
                                                                            decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_40);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            decomp_var_40 = esi;
                                                                            decomp_var_44 = eax;
                                                                            decomp_var_48 = "Seems (%s) and (%s) have applied little pressure to each other";
                                                                            decomp_var_4c = &decomp_var_1c;
                                                                            sub_410c10(decomp_var_4c, "Seems (%s) and (%s) have applied little pressure to each other", decomp_var_44);
                                                                            esi = decomp_var_1c - 0x10;
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                                            edx = esi + 0xc;
                                                                            if (esi[0x3] >= ebp) {
                                                                                    if (eax == *esi) {
                                                                                            edi = esi;
                                                                                            *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                                            edi = edi + 0x10;
                                                                                            edx = &decomp_var_c;
                                                                                            eax = &arg_14;
                                                                                            decomp_var_50 = edx;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = eax;
                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                            eax = edi - 0x10;
                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                            if (edx <= 0x1) {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_50 = eax;
                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                            }
                                                                                            esi = 0x1;
                                                                                            ecx = decomp_var_34;
                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                            edx = ecx[0x2];
                                                                                            asm { fldz };
                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                            ecx = decomp_var_30;
                                                                                            ebx = ebx + esi;
                                                                                            if (ebx < edx[0x901]) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x3;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ebp = 0x0;
                                                                                            decomp_var_50 = 0x1;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = esi[0x1];
                                                                                            ecx = eax;
                                                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                                                            if (edi != 0x0) {
                                                                                                    edi[0x1] = esi[0x1];
                                                                                                    eax = esi[0x1];
                                                                                                    decomp_var_58 = eax + 0x1;
                                                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                    edi = edi + 0x10;
                                                                                                    edx = &decomp_var_c;
                                                                                                    eax = &arg_14;
                                                                                                    decomp_var_50 = edx;
                                                                                                    esp = esp - 0x8;
                                                                                                    decomp_var_54 = eax;
                                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                                    eax = edi - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                    if (edx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_50 = eax;
                                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                                    }
                                                                                                    esi = 0x1;
                                                                                                    ecx = decomp_var_34;
                                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                                    edx = ecx[0x2];
                                                                                                    asm { fldz };
                                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                                    ecx = decomp_var_30;
                                                                                                    ebx = ebx + esi;
                                                                                                    if (ebx < edx[0x901]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x3;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_1 = 0x2;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    decomp_var_50 = 0x1;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_54 = esi[0x1];
                                                                                    ecx = eax;
                                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                                    if (edi != ebp) {
                                                                                            edi[0x1] = esi[0x1];
                                                                                            eax = esi[0x1];
                                                                                            decomp_var_58 = eax + 0x1;
                                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                            edi = edi + 0x10;
                                                                                            edx = &decomp_var_c;
                                                                                            eax = &arg_14;
                                                                                            decomp_var_50 = edx;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = eax;
                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                            eax = edi - 0x10;
                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                            if (edx <= 0x1) {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_50 = eax;
                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                            }
                                                                                            esi = 0x1;
                                                                                            ecx = decomp_var_34;
                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                            edx = ecx[0x2];
                                                                                            asm { fldz };
                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                            ecx = decomp_var_30;
                                                                                            ebx = ebx + esi;
                                                                                            if (ebx < edx[0x901]) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x3;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_1 = 0x2;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi = 0x1;
                                                                            ecx = decomp_var_34;
                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                            edx = ecx[0x2];
                                                                            asm { fldz };
                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                            ecx = decomp_var_30;
                                                                            ebx = ebx + esi;
                                                                            if (ebx < edx[0x901]) {
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x3;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    asm { fstp       st0 };
                                                                    bool_858 = asm { fstp       st0 };
                                                                    if (!bool_881) {
                                                                            if (bool_858 || *(ecx * 0x8 + 0x4d5528) < 0x5) {
                                                                                    ebp = 0x0;
                                                                                    *(ecx * 0x8 + 0x4d5528) = 0x1;
                                                                                    *(ecx * 0x8 + 0x4d552c) = 0x0;
                                                                            }
                                                                    }
                                                                    esi = 0x1;
                                                                    ecx = decomp_var_34;
                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                    edx = ecx[0x2];
                                                                    asm { fldz };
                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                    ecx = decomp_var_30;
                                                                    ebx = ebx + esi;
                                                                    if (ebx < edx[0x901]) {
                                                                            continue;
                                                                    }
                                                                    temp_1 = 0x3;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    asm { fxch       st0, st1 };
                                                    asm { fcomp      qword [qword_value_4603129179135383962] };
                                                    asm { fnstsw     ax };
                                                    bool_947 = (HIBYTE(eax) & 0x5) > 0x0;
                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                            esi = 0x1;
                                                            ebp = 0x0;
                                                            asm { fcomp      dword [esp+0x3c+-24] };
                                                            *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + esi;
                                                            *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                            asm { fnstsw     ax };
                                                            if (!PARITY(HIBYTE(eax) & 0x44)) {
                                                                    ebp = 0x0;
                                                                    *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + 0x1;
                                                                    bool_902 = *(ecx * 0x8 + 0x4d5528) < 0x0;
                                                                    esp = esp - 0x4;
                                                                    *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + 0x0 + CARRY(EFLAGS(cf));
                                                                    decomp_var_28 = ebx & 0xff | 0x4100;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_40);
                                                                    if (!bool_902) {
                                                                            esi = eax[0x1];
                                                                    }
                                                                    else {
                                                                            esi = eax + 0x4;
                                                                    }
                                                                    esp = esp - 0x4;
                                                                    decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_40);
                                                                    if (eax[0x6] >= 0x10) {
                                                                            eax = eax[0x1];
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x4;
                                                                    }
                                                                    decomp_var_40 = esi;
                                                                    decomp_var_44 = eax;
                                                                    decomp_var_48 = "Seems (%s) and (%s) have applied little pressure to each other";
                                                                    decomp_var_4c = &decomp_var_1c;
                                                                    sub_410c10(decomp_var_4c, "Seems (%s) and (%s) have applied little pressure to each other", decomp_var_44);
                                                                    esi = decomp_var_1c - 0x10;
                                                                    esp = (esp - 0x10) + 0x10;
                                                                    eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                                    edx = esi + 0xc;
                                                                    if (esi[0x3] >= ebp) {
                                                                            if (eax == *esi) {
                                                                                    edi = esi;
                                                                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                                    edi = edi + 0x10;
                                                                                    edx = &decomp_var_c;
                                                                                    eax = &arg_14;
                                                                                    decomp_var_50 = edx;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_54 = eax;
                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                    eax = edi - 0x10;
                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                    if (edx <= 0x1) {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_50 = eax;
                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                    }
                                                                                    esi = 0x1;
                                                                                    ecx = decomp_var_34;
                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                    edx = ecx[0x2];
                                                                                    asm { fldz };
                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                    ecx = decomp_var_30;
                                                                                    ebx = ebx + esi;
                                                                                    if (ebx < edx[0x901]) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x3;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ebp = 0x0;
                                                                                    decomp_var_50 = 0x1;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_54 = esi[0x1];
                                                                                    ecx = eax;
                                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                                    if (edi != 0x0) {
                                                                                            edi[0x1] = esi[0x1];
                                                                                            eax = esi[0x1];
                                                                                            decomp_var_58 = eax + 0x1;
                                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                            edi = edi + 0x10;
                                                                                            edx = &decomp_var_c;
                                                                                            eax = &arg_14;
                                                                                            decomp_var_50 = edx;
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_54 = eax;
                                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                            eax = edi - 0x10;
                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                            if (edx <= 0x1) {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_50 = eax;
                                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                                            }
                                                                                            esi = 0x1;
                                                                                            ecx = decomp_var_34;
                                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                            edx = ecx[0x2];
                                                                                            asm { fldz };
                                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                                            ecx = decomp_var_30;
                                                                                            ebx = ebx + esi;
                                                                                            if (ebx < edx[0x901]) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x3;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_1 = 0x2;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebp = 0x0;
                                                                            decomp_var_50 = 0x1;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_54 = esi[0x1];
                                                                            ecx = eax;
                                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                                            if (edi != 0x0) {
                                                                                    edi[0x1] = esi[0x1];
                                                                                    eax = esi[0x1];
                                                                                    decomp_var_58 = eax + 0x1;
                                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    edi = edi + 0x10;
                                                                                    edx = &decomp_var_c;
                                                                                    eax = &arg_14;
                                                                                    decomp_var_50 = edx;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_54 = eax;
                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                    eax = edi - 0x10;
                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                    if (edx <= 0x1) {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_50 = eax;
                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                    }
                                                                                    esi = 0x1;
                                                                                    ecx = decomp_var_34;
                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                    edx = ecx[0x2];
                                                                                    asm { fldz };
                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                    ecx = decomp_var_30;
                                                                                    ebx = ebx + esi;
                                                                                    if (ebx < edx[0x901]) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x3;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_1 = 0x2;
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    esi = 0x1;
                                                                    ecx = decomp_var_34;
                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                    edx = ecx[0x2];
                                                                    asm { fldz };
                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                    ecx = decomp_var_30;
                                                                    ebx = ebx + esi;
                                                                    if (ebx < edx[0x901]) {
                                                                            continue;
                                                                    }
                                                                    temp_1 = 0x3;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            asm { fstp       st0 };
                                                            bool_1012 = asm { fstp       st0 };
                                                            if (!bool_947) {
                                                                    if (bool_1012 || *(ecx * 0x8 + 0x4d5528) < 0x5) {
                                                                            ebp = 0x0;
                                                                            *(ecx * 0x8 + 0x4d5528) = 0x1;
                                                                            *(ecx * 0x8 + 0x4d552c) = 0x0;
                                                                    }
                                                            }
                                                            esi = 0x1;
                                                            ecx = decomp_var_34;
                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                            edx = ecx[0x2];
                                                            asm { fldz };
                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                            ecx = decomp_var_30;
                                                            ebx = ebx + esi;
                                                            if (ebx < edx[0x901]) {
                                                                    continue;
                                                            }
                                                            temp_1 = 0x3;
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            asm { fxch       st0, st1 };
                                            asm { fcomp      qword [qword_value_4603129179135383962] };
                                            asm { fnstsw     ax };
                                            bool_873 = (HIBYTE(eax) & 0x5) > 0x0;
                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                    esi = 0x1;
                                                    asm { fcomp      dword [esp+0x3c+-24] };
                                                    *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + esi;
                                                    *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x44)) {
                                                            *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + 0x1;
                                                            bool_916 = *(ecx * 0x8 + 0x4d5528) < 0x0;
                                                            esp = esp - 0x4;
                                                            *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + 0x0 + CARRY(EFLAGS(cf));
                                                            decomp_var_28 = ebx & 0xff | 0x4100;
                                                            sub_46db50();
                                                            eax = sub_4273a0(decomp_var_40);
                                                            if (!bool_916) {
                                                                    esi = eax[0x1];
                                                            }
                                                            else {
                                                                    esi = eax + 0x4;
                                                            }
                                                            esp = esp - 0x4;
                                                            decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                            sub_46db50();
                                                            eax = sub_4273a0(decomp_var_40);
                                                            if (eax[0x6] >= 0x10) {
                                                                    eax = eax[0x1];
                                                            }
                                                            else {
                                                                    eax = eax + 0x4;
                                                            }
                                                            ebp = 0x0;
                                                            decomp_var_40 = esi;
                                                            decomp_var_44 = eax;
                                                            decomp_var_48 = "Seems (%s) and (%s) have applied little pressure to each other";
                                                            decomp_var_4c = &decomp_var_1c;
                                                            sub_410c10(decomp_var_4c, "Seems (%s) and (%s) have applied little pressure to each other", decomp_var_44);
                                                            esi = decomp_var_1c - 0x10;
                                                            esp = (esp - 0x10) + 0x10;
                                                            eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                            edx = esi + 0xc;
                                                            if (esi[0x3] >= 0x0) {
                                                                    if (eax == *esi) {
                                                                            edi = esi;
                                                                            *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                            edi = edi + 0x10;
                                                                            edx = &decomp_var_c;
                                                                            eax = &arg_14;
                                                                            decomp_var_50 = edx;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_54 = eax;
                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                            eax = edi - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_50 = eax;
                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                            }
                                                                            esi = 0x1;
                                                                            ecx = decomp_var_34;
                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                            edx = ecx[0x2];
                                                                            asm { fldz };
                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                            ecx = decomp_var_30;
                                                                            ebx = ebx + esi;
                                                                            if (ebx < edx[0x901]) {
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x3;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ebp = 0x0;
                                                                            decomp_var_50 = 0x1;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_54 = esi[0x1];
                                                                            ecx = eax;
                                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                                            if (edi != 0x0) {
                                                                                    edi[0x1] = esi[0x1];
                                                                                    eax = esi[0x1];
                                                                                    decomp_var_58 = eax + 0x1;
                                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    edi = edi + 0x10;
                                                                                    edx = &decomp_var_c;
                                                                                    eax = &arg_14;
                                                                                    decomp_var_50 = edx;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_54 = eax;
                                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                    eax = edi - 0x10;
                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                    if (edx <= 0x1) {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_50 = eax;
                                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                                    }
                                                                                    esi = 0x1;
                                                                                    ecx = decomp_var_34;
                                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                                    edx = ecx[0x2];
                                                                                    asm { fldz };
                                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                                    ecx = decomp_var_30;
                                                                                    ebx = ebx + esi;
                                                                                    if (ebx < edx[0x901]) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x3;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_1 = 0x2;
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    ebp = 0x0;
                                                                    decomp_var_50 = 0x1;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_54 = esi[0x1];
                                                                    ecx = eax;
                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                    if (edi != 0x0) {
                                                                            edi[0x1] = esi[0x1];
                                                                            eax = esi[0x1];
                                                                            decomp_var_58 = eax + 0x1;
                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            edi = edi + 0x10;
                                                                            edx = &decomp_var_c;
                                                                            eax = &arg_14;
                                                                            decomp_var_50 = edx;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_54 = eax;
                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                            eax = edi - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_50 = eax;
                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                            }
                                                                            esi = 0x1;
                                                                            ecx = decomp_var_34;
                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                            edx = ecx[0x2];
                                                                            asm { fldz };
                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                            ecx = decomp_var_30;
                                                                            ebx = ebx + esi;
                                                                            if (ebx < edx[0x901]) {
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x3;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_1 = 0x2;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            esi = 0x1;
                                                            ecx = decomp_var_34;
                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                            edx = ecx[0x2];
                                                            asm { fldz };
                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                            ecx = decomp_var_30;
                                                            ebx = ebx + esi;
                                                            if (ebx < edx[0x901]) {
                                                                    continue;
                                                            }
                                                            temp_1 = 0x3;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ebp = 0x0;
                                                    asm { fstp       st0 };
                                                    bool_886 = asm { fstp       st0 };
                                                    if (!bool_873) {
                                                            if (bool_886 || *(ecx * 0x8 + 0x4d5528) < 0x5) {
                                                                    ebp = 0x0;
                                                                    *(ecx * 0x8 + 0x4d5528) = 0x1;
                                                                    *(ecx * 0x8 + 0x4d552c) = 0x0;
                                                            }
                                                    }
                                                    esi = 0x1;
                                                    ecx = decomp_var_34;
                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                    edx = ecx[0x2];
                                                    asm { fldz };
                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                    ecx = decomp_var_30;
                                                    ebx = ebx + esi;
                                                    if (ebx < edx[0x901]) {
                                                            continue;
                                                    }
                                                    temp_1 = 0x3;
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    asm { fxch       st0, st1 };
                                    asm { fcomp      qword [qword_value_4603129179135383962] };
                                    asm { fnstsw     ax };
                                    bool_911 = (HIBYTE(eax) & 0x5) > 0x0;
                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                            ebp = 0x0;
                                            esi = 0x1;
                                            asm { fcomp      dword [esp+0x3c+-24] };
                                            *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + esi;
                                            *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + ebp + CARRY(EFLAGS(cf));
                                            asm { fnstsw     ax };
                                            if (!PARITY(HIBYTE(eax) & 0x44)) {
                                                    *(ecx * 0x8 + 0x4d5528) = *(ecx * 0x8 + 0x4d5528) + 0x1;
                                                    bool_914 = *(ecx * 0x8 + 0x4d5528) < 0x0;
                                                    esp = esp - 0x4;
                                                    *(ecx * 0x8 + 0x4d552c) = *(ecx * 0x8 + 0x4d552c) + 0x0 + CARRY(EFLAGS(cf));
                                                    decomp_var_28 = ebx & 0xff | 0x4100;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_40);
                                                    if (!bool_914) {
                                                            esi = eax[0x1];
                                                    }
                                                    else {
                                                            esi = eax + 0x4;
                                                    }
                                                    esp = esp - 0x4;
                                                    decomp_var_28 = decomp_var_20 & 0xff | 0x4100;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_40);
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    ebp = 0x0;
                                                    decomp_var_40 = esi;
                                                    decomp_var_44 = eax;
                                                    decomp_var_48 = "Seems (%s) and (%s) have applied little pressure to each other";
                                                    decomp_var_4c = &decomp_var_1c;
                                                    sub_410c10(decomp_var_4c, "Seems (%s) and (%s) have applied little pressure to each other", decomp_var_44);
                                                    esi = decomp_var_1c - 0x10;
                                                    esp = (esp - 0x10) + 0x10;
                                                    eax = (*(**(decomp_var_1c - 0x10) + 0x10))();
                                                    edx = esi + 0xc;
                                                    if (esi[0x3] >= 0x0) {
                                                            if (eax == *esi) {
                                                                    edi = esi;
                                                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                                                                    edi = edi + 0x10;
                                                                    edx = &decomp_var_c;
                                                                    eax = &arg_14;
                                                                    decomp_var_50 = edx;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_54 = eax;
                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                    eax = edi - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            decomp_var_50 = eax;
                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                    }
                                                                    esi = 0x1;
                                                                    ecx = decomp_var_34;
                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                    edx = ecx[0x2];
                                                                    asm { fldz };
                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                    ecx = decomp_var_30;
                                                                    ebx = ebx + esi;
                                                                    if (ebx < edx[0x901]) {
                                                                            continue;
                                                                    }
                                                                    temp_1 = 0x3;
                                                                    break;
                                                            }
                                                            else {
                                                                    decomp_var_50 = 0x1;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_54 = esi[0x1];
                                                                    ecx = eax;
                                                                    edi = (**eax)(decomp_var_54, 0x1);
                                                                    if (edi != ebp) {
                                                                            edi[0x1] = esi[0x1];
                                                                            eax = esi[0x1];
                                                                            decomp_var_58 = eax + 0x1;
                                                                            sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            edi = edi + 0x10;
                                                                            edx = &decomp_var_c;
                                                                            eax = &arg_14;
                                                                            decomp_var_50 = edx;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_54 = eax;
                                                                            sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                            eax = edi - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_50 = eax;
                                                                                    (*(**eax + 0x4))(decomp_var_50);
                                                                            }
                                                                            esi = 0x1;
                                                                            ecx = decomp_var_34;
                                                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                                                            edx = ecx[0x2];
                                                                            asm { fldz };
                                                                            decomp_var_14 = decomp_var_14 + 0x54;
                                                                            ecx = decomp_var_30;
                                                                            ebx = ebx + esi;
                                                                            if (ebx < edx[0x901]) {
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x3;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_1 = 0x2;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            decomp_var_50 = 0x1;
                                                            esp = esp - 0x8;
                                                            decomp_var_54 = esi[0x1];
                                                            ecx = eax;
                                                            edi = (**eax)(decomp_var_54, 0x1);
                                                            if (edi != ebp) {
                                                                    edi[0x1] = esi[0x1];
                                                                    eax = esi[0x1];
                                                                    decomp_var_58 = eax + 0x1;
                                                                    sub_47a5af(edi + 0x10, decomp_var_58, esi + 0x10, eax + 0x1);
                                                                    esp = (esp - 0x10) + 0x10;
                                                                    edi = edi + 0x10;
                                                                    edx = &decomp_var_c;
                                                                    eax = &arg_14;
                                                                    decomp_var_50 = edx;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_54 = eax;
                                                                    sub_419e60(decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                    eax = edi - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            decomp_var_50 = eax;
                                                                            (*(**eax + 0x4))(decomp_var_50);
                                                                    }
                                                                    esi = 0x1;
                                                                    ecx = decomp_var_34;
                                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                                    edx = ecx[0x2];
                                                                    asm { fldz };
                                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                                    ecx = decomp_var_30;
                                                                    ebx = ebx + esi;
                                                                    if (ebx < edx[0x901]) {
                                                                            continue;
                                                                    }
                                                                    temp_1 = 0x3;
                                                                    break;
                                                            }
                                                            else {
                                                                    temp_1 = 0x2;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    esi = 0x1;
                                                    ecx = decomp_var_34;
                                                    asm { fld        dword [aSeemsSAndSHave+60] };
                                                    edx = ecx[0x2];
                                                    asm { fldz };
                                                    decomp_var_14 = decomp_var_14 + 0x54;
                                                    ecx = decomp_var_30;
                                                    ebx = ebx + esi;
                                                    if (ebx < edx[0x901]) {
                                                            continue;
                                                    }
                                                    temp_1 = 0x3;
                                                    break;
                                            }
                                    }
                                    else {
                                            ebp = 0x0;
                                            asm { fstp       st0 };
                                            bool_920 = asm { fstp       st0 };
                                            if (!bool_911) {
                                                    if (bool_920 || *(ecx * 0x8 + 0x4d5528) < 0x5) {
                                                            ebp = 0x0;
                                                            *(ecx * 0x8 + 0x4d5528) = 0x1;
                                                            *(ecx * 0x8 + 0x4d552c) = 0x0;
                                                    }
                                            }
                                            esi = 0x1;
                                            ecx = decomp_var_34;
                                            asm { fld        dword [aSeemsSAndSHave+60] };
                                            edx = ecx[0x2];
                                            asm { fldz };
                                            decomp_var_14 = decomp_var_14 + 0x54;
                                            ecx = decomp_var_30;
                                            ebx = ebx + esi;
                                            if (ebx < edx[0x901]) {
                                                    continue;
                                            }
                                            temp_1 = 0x3;
                                            break;
                                    }
                            }
                    }
            }
            else {
                    asm { fstp       st1 };
                    asm { fstp       st0 };
                    esi = 0x1;
                    ecx = decomp_var_34;
                    asm { fld        dword [aSeemsSAndSHave+60] };
                    edx = ecx[0x2];
                    asm { fldz };
                    decomp_var_14 = decomp_var_14 + 0x54;
                    ecx = decomp_var_30;
                    ebx = ebx + esi;
                    if (ebx < edx[0x901]) {
                            continue;
                    }
                    temp_1 = 0x3;
                    break;
            }
    }
    else {
            asm { fstp       st1 };
            asm { fstp       st0 };
            esi = 0x1;
            ecx = decomp_var_34;
            asm { fld        dword [aSeemsSAndSHave+60] };
            edx = ecx[0x2];
            asm { fldz };
            decomp_var_14 = decomp_var_14 + 0x54;
            ecx = decomp_var_30;
            ebx = ebx + esi;
            if (ebx < edx[0x901]) {
                    continue;
            }
            temp_1 = 0x3;
            break;
    }
    goto .l52;

loc_435723:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    esi = esi[0x9];
    edx = *(&decomp_var_28 + ((edi << 0x8) + esi) * 0x8 + 0x1590);
    eax = &decomp_var_28 + ((edi << 0x8) + esi) * 0x8 + 0x158c;
    ecx = *eax;
    arg_0 = esi;
    if (ecx != 0x2) {
            if (ecx == 0x3) {
                    if (edx == 0x0) {
                            *(&decomp_var_28 + (edi * 0x15 + decomp_var_14) * 0x4 + 0xd4) = *(&decomp_var_28 + (edi * 0x15 + decomp_var_14) * 0x4 + 0xd4) - 0x1;
                            *eax = 0x2;
                            eax[0x1] = edx;
                    }
            }
            sub_401390();
            esi = arg_14;
            ebx = arg_18;
            continue;
    }
    if (edx != 0x0) {
            if (ecx == 0x3) {
                    if (edx == 0x0) {
                            *(&decomp_var_28 + (edi * 0x15 + decomp_var_14) * 0x4 + 0xd4) = *(&decomp_var_28 + (edi * 0x15 + decomp_var_14) * 0x4 + 0xd4) - 0x1;
                            *eax = 0x2;
                            eax[0x1] = edx;
                    }
            }
            sub_401390();
            esi = arg_14;
            ebx = arg_18;
            continue;
    }
    eax[0x1] = edx;
    esi = decomp_var_c * 0x15 + decomp_var_14 + decomp_var_c * 0x15 + decomp_var_14 + decomp_var_c * 0x15 + decomp_var_14 + decomp_var_c * 0x15 + decomp_var_14;
    *(&decomp_var_28 + esi + 0xd4) = *(&decomp_var_28 + esi + 0xd4) + 0x1;
    *eax = 0x3;
    eax = decomp_var_10[0x2];
    edi = eax + 0x2450;
    ebp = *eax[0x915];
    arg_4 = edi;
    arg_8 = ebp;
    &decomp_var_28 = &decomp_var_28;
    goto .l43;

loc_435684:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x8] != 0x6) {
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x8] != 0x4) {
                    sub_401390();
                    esi = arg_14;
                    ebx = arg_18;
                    continue;
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            bool_419 = esi != ebx[0x1];
            ebp = esi[0xc];
            if (!bool_419) {
                    sub_47a948();
            }
            esi = esi[0xb];
            edx = edi & 0x80000000 ? 0xffffffff : 0x0;
            if (*(esi * 0x8 + 0x4d1610) == edi) {
                    if (*(esi * 0x8 + 0x4d1614) != edx) {
                            eax = (edi << 0x8) + ebp;
                            bool_411 = *(&decomp_var_28 + eax * 0x8 + 0x1590) > 0x0;
                            if (*(&decomp_var_28 + eax * 0x8 + 0x1590) >= 0x0) {
                                    if (bool_411 || *(&decomp_var_28 + eax * 0x8 + 0x158c) >= 0x2) {
                                            *(&decomp_var_28 + (edi * 0x15 + decomp_var_14) * 0x4 + 0xd4) = *(&decomp_var_28 + (edi * 0x15 + decomp_var_14) * 0x4 + 0xd4) + 0x1;
                                    }
                            }
                    }
            }
            else {
                    eax = (edi << 0x8) + ebp;
                    bool_405 = *(&decomp_var_28 + eax * 0x8 + 0x1590) < 0x0;
                    bool_390 = *(&decomp_var_28 + eax * 0x8 + 0x1590) > 0x0;
                    if (!bool_405) {
                            if (bool_390 || *(&decomp_var_28 + eax * 0x8 + 0x158c) >= 0x2) {
                                    *(&decomp_var_28 + (edi * 0x15 + decomp_var_14) * 0x4 + 0xd4) = *(&decomp_var_28 + (edi * 0x15 + decomp_var_14) * 0x4 + 0xd4) + 0x1;
                            }
                    }
            }
            sub_401390();
            esi = arg_14;
            ebx = arg_18;
            continue;
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    esi = esi[0x9];
    edx = *(&decomp_var_28 + ((edi << 0x8) + esi) * 0x8 + 0x1590);
    eax = &decomp_var_28 + ((edi << 0x8) + esi) * 0x8 + 0x158c;
    ecx = *eax;
    arg_0 = esi;
    if (ecx != 0x2) {
            if (ecx == 0x3) {
                    if (edx == 0x0) {
                            *(&decomp_var_28 + (edi * 0x15 + decomp_var_14) * 0x4 + 0xd4) = *(&decomp_var_28 + (edi * 0x15 + decomp_var_14) * 0x4 + 0xd4) - 0x1;
                            *eax = 0x2;
                            eax[0x1] = edx;
                    }
            }
            sub_401390();
            esi = arg_14;
            ebx = arg_18;
            continue;
    }
    if (edx != 0x0) {
            if (ecx == 0x3) {
                    if (edx == 0x0) {
                            *(&decomp_var_28 + (edi * 0x15 + decomp_var_14) * 0x4 + 0xd4) = *(&decomp_var_28 + (edi * 0x15 + decomp_var_14) * 0x4 + 0xd4) - 0x1;
                            *eax = 0x2;
                            eax[0x1] = edx;
                    }
            }
            sub_401390();
            esi = arg_14;
            ebx = arg_18;
            continue;
    }
    eax[0x1] = edx;
    esi = decomp_var_c * 0x15 + decomp_var_14 + decomp_var_c * 0x15 + decomp_var_14 + decomp_var_c * 0x15 + decomp_var_14 + decomp_var_c * 0x15 + decomp_var_14;
    *(&decomp_var_28 + esi + 0xd4) = *(&decomp_var_28 + esi + 0xd4) + 0x1;
    *eax = 0x3;
    eax = decomp_var_10[0x2];
    edi = eax + 0x2450;
    ebp = *eax[0x915];
    arg_4 = edi;
    arg_8 = ebp;
    &decomp_var_28 = &decomp_var_28;
    goto loc_4357a0;

.l32:
    eax = sub_40b6d0();
    return eax;

.l112:
    if (temp_2 == 0x2) goto .l33;
    goto loc_435f99;

.l14:
    eax = sub_40b6d0();
    return eax;

.l35:
    if (temp_2 == 0x1) goto .l15;
    goto .l36;

.l52:
    if (temp_1 != 0x0) {
            if (temp_1 != 0x1) {
                    if (temp_1 != 0x2) {
                            eax = *(decomp_var_34[0x2] + 0x2404);
                            decomp_var_20 = decomp_var_20 + 0x15;
                            ecx = ecx + 0x1;
                            decomp_var_30 = ecx;
                            if (ecx < eax) {
                                    continue;
                            }
                            ebp = decomp_var_4;
                            asm { fstp       st1 };
                            edi = decomp_var_34;
                            asm { fstp       st0 };
                            temp_2 = 0x3;
                            break;
                    }
                    else {
                            temp_2 = 0x2;
                            break;
                    }
            }
            else {
                    temp_2 = 0x1;
                    break;
            }
    }
    else {
            temp_2 = 0x0;
            break;
    }
    goto .l51;

.l43:
    eax = decomp_var_10[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (ebp != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebp == edi[0x1]) {
                    sub_47a948();
            }
            if (arg_14 == decomp_var_14) {
                    if (ebp == edi[0x1]) {
                            sub_47a948();
                    }
                    if (arg_c == arg_0) {
                            *(&decomp_var_28 + esi + 0xea4) = *(&decomp_var_28 + esi + 0xea4) + 0x1;
                    }
            }
            sub_401390();
            ebp = arg_8;
            edi = arg_4;
            continue;
    }
    break;

loc_4357a0:
    eax = decomp_var_10[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (ebp != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebp == edi[0x1]) {
                    sub_47a948();
            }
            if (arg_14 == decomp_var_14) {
                    if (ebp == edi[0x1]) {
                            sub_47a948();
                    }
                    if (arg_c == arg_0) {
                            *(&decomp_var_28 + esi + 0xea4) = *(&decomp_var_28 + esi + 0xea4) + 0x1;
                    }
            }
            sub_401390();
            ebp = arg_8;
            edi = arg_4;
            continue;
    }
    break;

.l33:
    eax = sub_40b6d0();
    return eax;

loc_435f99:
    edx = *(edi[0x2] + 0x2404);
    ecx = 0x0;
    if (edx <= 0x0) goto loc_435fe6;
    goto loc_435fad;

.l15:
    eax = sub_40b6d0();
    return eax;

.l36:
    if (temp_2 == 0x2) goto .l16;
    goto .l30;
    sub_401390();
    esi = arg_14;
    ebx = arg_18;
    continue;
    sub_401390();
    esi = arg_14;
    ebx = arg_18;
    continue;

loc_435fe6:
    if (decomp_var_22 == 0x1) {
            ecx = 0x0;
            if (edx > 0x0) {
                    while (true) {
                            if (*(&decomp_var_4c + ecx * 0x4 + 0x7c) >= 0x2) {
                                    ecx = ecx + 0x1;
                                    if (ecx < edx) {
                                            continue;
                                    }
                                    temp_5 = 0x0;
                                    break;
                            }
                            if (ecx != ebp) {
                                    eax = *(&decomp_var_4c + ecx * 0x4 + 0x7c);
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d5528) = eax;
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d552c) = eax & 0x80000000 ? 0xffffffff : 0x0;
                                    temp_5 = 0x1;
                                    break;
                            }
                            ecx = ecx + 0x1;
                            if (ecx < edx) {
                                    continue;
                            }
                            temp_5 = 0x0;
                            break;
                    }
            }
    }
    goto loc_436020;

loc_435fad:
    eax = ebp * 0xa8 + 0x4d5528;
    goto .l47;

.l16:
    eax = sub_40b6d0();
    return eax;

.l30:
    edx = *(edi[0x2] + 0x2404);
    ecx = 0x0;
    if (edx <= 0x0) goto .l9;
    goto .l34;

loc_436020:
    edx = *dword_4c6bc4;
    eax = ebp * 0x15;
    ecx = eax + *dword_4c6bc4;
    bool_48 = *(ecx * 0x8 + 0x4d552c) > 0x0;
    bool_32 = *(ecx * 0x8 + 0x4d552c) < 0x0;
    if (!bool_48 && (bool_32 || *(ecx * 0x8 + 0x4d5528) < 0x2)) {
            edx = *dword_4c6bc4;
            edx = edx | 0xffffffff;
            *dword_4c6bc4 = edx;
    }
    ecx = *dword_4c6bc8;
    esi = eax + *dword_4c6bc8;
    bool_41 = *(esi * 0x8 + 0x4d552c) < 0x0;
    if (*(esi * 0x8 + 0x4d552c) <= 0x0 && (bool_41 || *(esi * 0x8 + 0x4d5528) < 0x2)) {
            ecx = *dword_4c6bc8;
            ecx = ecx | 0xffffffff;
            *dword_4c6bc8 = ecx;
    }
    esi = *dword_4c6bcc;
    eax = eax + *dword_4c6bcc;
    bool_38 = *(eax * 0x8 + 0x4d552c) > 0x0;
    bool_31 = *(eax * 0x8 + 0x4d552c) < 0x0;
    if (!bool_38 && (bool_31 || *(eax * 0x8 + 0x4d5528) < 0x2)) {
            esi = *dword_4c6bcc;
            esi = esi | 0xffffffff;
            *dword_4c6bcc = esi;
    }
    bool_249 = edx != 0xffffffff;
    if (edx == 0xffffffff) {
            bool_108 = ecx != edx;
            if (ecx > edx) {
                    edx = ecx;
                    ecx = ecx | 0xffffffff;
                    *dword_4c6bc4 = edx;
                    *dword_4c6bc8 = ecx;
                    if (esi > 0xffffffff) {
                            ecx = esi;
                            esi = esi | 0xffffffff;
                            *dword_4c6bc8 = ecx;
                            *dword_4c6bcc = esi;
                    }
            }
            else {
                    if (!bool_108 && esi > 0xffffffff) {
                            ecx = esi;
                            esi = esi | 0xffffffff;
                            *dword_4c6bc8 = ecx;
                            *dword_4c6bcc = esi;
                    }
            }
    }
    else {
            if (!bool_249 && esi > 0xffffffff) {
                    ecx = esi;
                    esi = esi | 0xffffffff;
                    *dword_4c6bc8 = ecx;
                    *dword_4c6bcc = esi;
            }
    }
    bool_42 = edx <= 0xffffffff;
    if (edx == 0xffffffff) {
            if (ecx == edx) {
                    bool_116 = esi <= edx;
                    if (esi > edx) {
                            edx = esi;
                            *dword_4c6bc4 = edx;
                            *dword_4c6bcc = 0xffffffff;
                            if (!bool_116) {
                                    ebx = 0x0;
                                    if (*(decomp_var_34[0x2] + 0x2404) > 0x0) {
                                            while (true) {
                                                    if (ebx == ebp) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    if (ebx == edx) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    eax = edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx;
                                                    ecx = *(&decomp_var_4c + eax + 0xd4);
                                                    if (ecx <= 0x1) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    if (ecx != *(&decomp_var_4c + eax + 0x7bc)) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    esp = esp - 0x4;
                                                    decomp_var_38 = edx & 0xff | 0x4100;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_50);
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    decomp_var_50 = eax;
                                                    decomp_var_54 = "It would seem our best ally (%s) has been severely pressured by another power ";
                                                    decomp_var_58 = &decomp_var_2c;
                                                    sub_410c10(decomp_var_58, "It would seem our best ally (%s) has been severely pressured by another power ", decomp_var_50);
                                                    edx = **(decomp_var_2c - 0x10);
                                                    eax = edx[0x4];
                                                    esi = decomp_var_2c - 0x10;
                                                    esp = (esp - 0xc) + 0xc;
                                                    eax = (eax)();
                                                    ecx = esi + 0xc;
                                                    if (esi[0x3] >= 0x0) {
                                                            if (eax == *esi) {
                                                                    edi = esi;
                                                                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
                                                                    esp = esp - 0x8;
                                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                                    eax = edi + 0x10 - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            (*(**eax + 0x4))(eax);
                                                                    }
                                                                    edx = *dword_4c6bc4;
                                                                    *(int8_t *)byte_baed45 = 0x1;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                            continue;
                                                                    }
                                                                    temp_3 = 0x0;
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = esi[0x1];
                                                                    edx = *eax;
                                                                    edx = *edx;
                                                                    esp = esp - 0x8;
                                                                    edi = (edx)(ecx, 0x1);
                                                                    if (edi != 0x0) {
                                                                            edi[0x1] = esi[0x1];
                                                                            eax = esi[0x1];
                                                                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            esp = esp - 0x8;
                                                                            eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                                            eax = edi + 0x10 - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    (*(**eax + 0x4))(eax);
                                                                            }
                                                                            edx = *dword_4c6bc4;
                                                                            *(int8_t *)byte_baed45 = 0x1;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                                    continue;
                                                                            }
                                                                            temp_3 = 0x0;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_3 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            ecx = esi[0x1];
                                                            edx = *eax;
                                                            edx = *edx;
                                                            esp = esp - 0x8;
                                                            edi = (edx)(ecx, 0x1);
                                                            if (edi != 0x0) {
                                                                    edi[0x1] = esi[0x1];
                                                                    eax = esi[0x1];
                                                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                                    esp = (esp - 0x10) + 0x10;
                                                                    esp = esp - 0x8;
                                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                                    eax = edi + 0x10 - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            (*(**eax + 0x4))(eax);
                                                                    }
                                                                    edx = *dword_4c6bc4;
                                                                    *(int8_t *)byte_baed45 = 0x1;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                            continue;
                                                                    }
                                                                    temp_3 = 0x0;
                                                                    break;
                                                            }
                                                            else {
                                                                    temp_3 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            if (temp_3 != 0x0) {
                                                    eax = sub_40b6d0();
                                            }
                                            else {
                                                    ebx = decomp_var_40;
                                                    esi = *(ebx[0x2] + 0x2404);
                                                    if (esi > 0x0) {
                                                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                                    }
                                                    else {
                                                            if (*(int8_t *)byte_baed43 == 0x1) {
                                                                    edx = 0x0;
                                                                    ecx = 0x0;
                                                                    if (esi > 0x0) {
                                                                            eax = &arg_4d5524;
                                                                            do {
                                                                                    if (*eax == 0x3) {
                                                                                            edx = 0x0;
                                                                                            if (eax[0x1] == 0x0) {
                                                                                                    edx = 0x0;
                                                                                                    *eax = 0x1;
                                                                                                    eax[0x1] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = ecx + 0x1;
                                                                                    eax = eax + 0x8;
                                                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                                                    }
                                                            }
                                                            eax = decomp_var_38 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    decomp_var_5c = eax;
                                                                    eax = *(**eax + 0x4);
                                                                    eax = (eax)(decomp_var_5c);
                                                            }
                                                            *0x0 = arg_bd34;
                                                            &decomp_var_44 = decomp_var_4c;
                                                    }
                                            }
                                    }
                                    else {
                                            ebx = decomp_var_40;
                                            esi = *(ebx[0x2] + 0x2404);
                                            if (esi > 0x0) {
                                                    eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                            }
                                            else {
                                                    if (*(int8_t *)byte_baed43 == 0x1) {
                                                            edx = 0x0;
                                                            ecx = 0x0;
                                                            if (esi > 0x0) {
                                                                    eax = &arg_4d5524;
                                                                    do {
                                                                            if (*eax == 0x3) {
                                                                                    edx = 0x0;
                                                                                    if (eax[0x1] == 0x0) {
                                                                                            edx = 0x0;
                                                                                            *eax = 0x1;
                                                                                            eax[0x1] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = ecx + 0x1;
                                                                            eax = eax + 0x8;
                                                                    } while (ecx < *(ebx[0x2] + 0x2404));
                                                            }
                                                    }
                                                    eax = decomp_var_38 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            decomp_var_5c = eax;
                                                            eax = *(**eax + 0x4);
                                                            eax = (eax)(decomp_var_5c);
                                                    }
                                                    *0x0 = arg_bd34;
                                                    &decomp_var_44 = decomp_var_4c;
                                            }
                                    }
                            }
                            else {
                                    ebx = decomp_var_40;
                                    esi = *(ebx[0x2] + 0x2404);
                                    if (esi > 0x0) {
                                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                    }
                                    else {
                                            if (*(int8_t *)byte_baed43 == 0x1) {
                                                    edx = 0x0;
                                                    ecx = 0x0;
                                                    if (esi > 0x0) {
                                                            eax = &arg_4d5524;
                                                            do {
                                                                    if (*eax == 0x3) {
                                                                            edx = 0x0;
                                                                            if (eax[0x1] == 0x0) {
                                                                                    edx = 0x0;
                                                                                    *eax = 0x1;
                                                                                    eax[0x1] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = ecx + 0x1;
                                                                    eax = eax + 0x8;
                                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                                    }
                                            }
                                            eax = decomp_var_38 - 0x10;
                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                            if (edx <= 0x1) {
                                                    esp = esp - 0x4;
                                                    decomp_var_5c = eax;
                                                    eax = *(**eax + 0x4);
                                                    eax = (eax)(decomp_var_5c);
                                            }
                                            *0x0 = arg_bd34;
                                            &decomp_var_44 = decomp_var_4c;
                                    }
                            }
                    }
                    else {
                            ebx = decomp_var_40;
                            esi = *(ebx[0x2] + 0x2404);
                            if (esi > 0x0) {
                                    eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                            }
                            else {
                                    if (*(int8_t *)byte_baed43 == 0x1) {
                                            edx = 0x0;
                                            ecx = 0x0;
                                            if (esi > 0x0) {
                                                    eax = &arg_4d5524;
                                                    do {
                                                            if (*eax == 0x3) {
                                                                    edx = 0x0;
                                                                    if (eax[0x1] == 0x0) {
                                                                            edx = 0x0;
                                                                            *eax = 0x1;
                                                                            eax[0x1] = 0x0;
                                                                    }
                                                            }
                                                            ecx = ecx + 0x1;
                                                            eax = eax + 0x8;
                                                    } while (ecx < *(ebx[0x2] + 0x2404));
                                            }
                                    }
                                    eax = decomp_var_38 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            decomp_var_5c = eax;
                                            eax = *(**eax + 0x4);
                                            eax = (eax)(decomp_var_5c);
                                    }
                                    *0x0 = arg_bd34;
                                    &decomp_var_44 = decomp_var_4c;
                            }
                    }
            }
            else {
                    ebx = decomp_var_40;
                    esi = *(ebx[0x2] + 0x2404);
                    if (esi > 0x0) {
                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                    }
                    else {
                            if (*(int8_t *)byte_baed43 == 0x1) {
                                    edx = 0x0;
                                    ecx = 0x0;
                                    if (esi > 0x0) {
                                            eax = &arg_4d5524;
                                            do {
                                                    if (*eax == 0x3) {
                                                            edx = 0x0;
                                                            if (eax[0x1] == 0x0) {
                                                                    edx = 0x0;
                                                                    *eax = 0x1;
                                                                    eax[0x1] = 0x0;
                                                            }
                                                    }
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x8;
                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                    }
                            }
                            eax = decomp_var_38 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            if (edx <= 0x1) {
                                    esp = esp - 0x4;
                                    decomp_var_5c = eax;
                                    eax = *(**eax + 0x4);
                                    eax = (eax)(decomp_var_5c);
                            }
                            *0x0 = arg_bd34;
                            &decomp_var_44 = decomp_var_4c;
                    }
            }
    }
    else {
            if (!bool_42) {
                    ebx = 0x0;
                    if (*(decomp_var_34[0x2] + 0x2404) > 0x0) {
                            while (true) {
                                    if (ebx == ebp) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    if (ebx == edx) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    eax = edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx;
                                    ecx = *(&decomp_var_4c + eax + 0xd4);
                                    if (ecx <= 0x1) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    if (ecx != *(&decomp_var_4c + eax + 0x7bc)) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    esp = esp - 0x4;
                                    decomp_var_38 = edx & 0xff | 0x4100;
                                    sub_46db50();
                                    eax = sub_4273a0(decomp_var_50);
                                    if (eax[0x6] >= 0x10) {
                                            eax = eax[0x1];
                                    }
                                    else {
                                            eax = eax + 0x4;
                                    }
                                    decomp_var_50 = eax;
                                    decomp_var_54 = "It would seem our best ally (%s) has been severely pressured by another power ";
                                    decomp_var_58 = &decomp_var_2c;
                                    sub_410c10(decomp_var_58, "It would seem our best ally (%s) has been severely pressured by another power ", decomp_var_50);
                                    edx = **(decomp_var_2c - 0x10);
                                    eax = edx[0x4];
                                    esi = decomp_var_2c - 0x10;
                                    esp = (esp - 0xc) + 0xc;
                                    eax = (eax)();
                                    ecx = esi + 0xc;
                                    if (esi[0x3] >= 0x0) {
                                            if (eax == *esi) {
                                                    edi = esi;
                                                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
                                                    esp = esp - 0x8;
                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                    eax = edi + 0x10 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    edx = *dword_4c6bc4;
                                                    *(int8_t *)byte_baed45 = 0x1;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                            continue;
                                                    }
                                                    temp_3 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    ecx = esi[0x1];
                                                    edx = *eax;
                                                    edx = *edx;
                                                    esp = esp - 0x8;
                                                    edi = (edx)(ecx, 0x1);
                                                    if (edi != 0x0) {
                                                            edi[0x1] = esi[0x1];
                                                            eax = esi[0x1];
                                                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                            esp = (esp - 0x10) + 0x10;
                                                            esp = esp - 0x8;
                                                            eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                            eax = edi + 0x10 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    (*(**eax + 0x4))(eax);
                                                            }
                                                            edx = *dword_4c6bc4;
                                                            *(int8_t *)byte_baed45 = 0x1;
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    else {
                                                            temp_3 = 0x1;
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            ecx = esi[0x1];
                                            edx = *eax;
                                            edx = *edx;
                                            esp = esp - 0x8;
                                            edi = (edx)(ecx, 0x1);
                                            if (edi != 0x0) {
                                                    edi[0x1] = esi[0x1];
                                                    eax = esi[0x1];
                                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                    esp = (esp - 0x10) + 0x10;
                                                    esp = esp - 0x8;
                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                    eax = edi + 0x10 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    edx = *dword_4c6bc4;
                                                    *(int8_t *)byte_baed45 = 0x1;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                            continue;
                                                    }
                                                    temp_3 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    temp_3 = 0x1;
                                                    break;
                                            }
                                    }
                            }
                            if (temp_3 != 0x0) {
                                    eax = sub_40b6d0();
                            }
                            else {
                                    ebx = decomp_var_40;
                                    esi = *(ebx[0x2] + 0x2404);
                                    if (esi > 0x0) {
                                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                    }
                                    else {
                                            if (*(int8_t *)byte_baed43 == 0x1) {
                                                    edx = 0x0;
                                                    ecx = 0x0;
                                                    if (esi > 0x0) {
                                                            eax = &arg_4d5524;
                                                            do {
                                                                    if (*eax == 0x3) {
                                                                            edx = 0x0;
                                                                            if (eax[0x1] == 0x0) {
                                                                                    edx = 0x0;
                                                                                    *eax = 0x1;
                                                                                    eax[0x1] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = ecx + 0x1;
                                                                    eax = eax + 0x8;
                                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                                    }
                                            }
                                            eax = decomp_var_38 - 0x10;
                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                            if (edx <= 0x1) {
                                                    esp = esp - 0x4;
                                                    decomp_var_5c = eax;
                                                    eax = *(**eax + 0x4);
                                                    eax = (eax)(decomp_var_5c);
                                            }
                                            *0x0 = arg_bd34;
                                            &decomp_var_44 = decomp_var_4c;
                                    }
                            }
                    }
                    else {
                            ebx = decomp_var_40;
                            esi = *(ebx[0x2] + 0x2404);
                            if (esi > 0x0) {
                                    eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                            }
                            else {
                                    if (*(int8_t *)byte_baed43 == 0x1) {
                                            edx = 0x0;
                                            ecx = 0x0;
                                            if (esi > 0x0) {
                                                    eax = &arg_4d5524;
                                                    do {
                                                            if (*eax == 0x3) {
                                                                    edx = 0x0;
                                                                    if (eax[0x1] == 0x0) {
                                                                            edx = 0x0;
                                                                            *eax = 0x1;
                                                                            eax[0x1] = 0x0;
                                                                    }
                                                            }
                                                            ecx = ecx + 0x1;
                                                            eax = eax + 0x8;
                                                    } while (ecx < *(ebx[0x2] + 0x2404));
                                            }
                                    }
                                    eax = decomp_var_38 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            decomp_var_5c = eax;
                                            eax = *(**eax + 0x4);
                                            eax = (eax)(decomp_var_5c);
                                    }
                                    *0x0 = arg_bd34;
                                    &decomp_var_44 = decomp_var_4c;
                            }
                    }
            }
            else {
                    ebx = decomp_var_40;
                    esi = *(ebx[0x2] + 0x2404);
                    if (esi > 0x0) {
                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                    }
                    else {
                            if (*(int8_t *)byte_baed43 == 0x1) {
                                    edx = 0x0;
                                    ecx = 0x0;
                                    if (esi > 0x0) {
                                            eax = &arg_4d5524;
                                            do {
                                                    if (*eax == 0x3) {
                                                            edx = 0x0;
                                                            if (eax[0x1] == 0x0) {
                                                                    edx = 0x0;
                                                                    *eax = 0x1;
                                                                    eax[0x1] = 0x0;
                                                            }
                                                    }
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x8;
                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                    }
                            }
                            eax = decomp_var_38 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            if (edx <= 0x1) {
                                    esp = esp - 0x4;
                                    decomp_var_5c = eax;
                                    eax = *(**eax + 0x4);
                                    eax = (eax)(decomp_var_5c);
                            }
                            *0x0 = arg_bd34;
                            &decomp_var_44 = decomp_var_4c;
                    }
            }
    }
    return eax;

.l47:
    bool_833 = eax[0x1] < 0x0;
    if (eax[0x1] <= 0x0) {
            if (!bool_833) {
                    if (*eax < 0x2 && ecx != ebp) {
                            decomp_var_21 = 0x1;
                    }
            }
            else {
                    if (ecx != ebp) {
                            decomp_var_21 = 0x1;
                    }
            }
    }
    ecx = ecx + 0x1;
    eax = eax + 0x8;
    if (ecx < edx) {
            continue;
    }
    break;

.l9:
    if (decomp_var_22 == 0x1) {
            ecx = 0x0;
            if (edx > 0x0) {
                    while (true) {
                            if (*(&decomp_var_4c + ecx * 0x4 + 0x7c) >= 0x2) {
                                    ecx = ecx + 0x1;
                                    if (ecx < edx) {
                                            continue;
                                    }
                                    temp_5 = 0x0;
                                    break;
                            }
                            if (ecx != ebp) {
                                    eax = *(&decomp_var_4c + ecx * 0x4 + 0x7c);
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d5528) = eax;
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d552c) = eax & 0x80000000 ? 0xffffffff : 0x0;
                                    temp_5 = 0x1;
                                    break;
                            }
                            ecx = ecx + 0x1;
                            if (ecx < edx) {
                                    continue;
                            }
                            temp_5 = 0x0;
                            break;
                    }
            }
    }
    goto .l10;

.l34:
    eax = ebp * 0xa8 + 0x4d5528;
    goto loc_435fc0;
    if (decomp_var_21 == 0x0 && decomp_var_22 == 0x1) {
            ecx = 0x0;
            if (edx > 0x0) {
                    while (true) {
                            if (*(&decomp_var_4c + ecx * 0x4 + 0x7c) >= 0x2) {
                                    ecx = ecx + 0x1;
                                    if (ecx < edx) {
                                            continue;
                                    }
                                    temp_5 = 0x0;
                                    break;
                            }
                            if (ecx != ebp) {
                                    eax = *(&decomp_var_4c + ecx * 0x4 + 0x7c);
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d5528) = eax;
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d552c) = eax & 0x80000000 ? 0xffffffff : 0x0;
                                    temp_5 = 0x1;
                                    break;
                            }
                            ecx = ecx + 0x1;
                            if (ecx < edx) {
                                    continue;
                            }
                            temp_5 = 0x0;
                            break;
                    }
            }
    }
    goto loc_436020;

.l10:
    edx = *dword_4c6bc4;
    eax = ebp * 0x15;
    ecx = eax + *dword_4c6bc4;
    bool_224 = *(ecx * 0x8 + 0x4d552c) < 0x0;
    if (*(ecx * 0x8 + 0x4d552c) <= 0x0 && (bool_224 || *(ecx * 0x8 + 0x4d5528) < 0x2)) {
            edx = *dword_4c6bc4;
            edx = edx | 0xffffffff;
            *dword_4c6bc4 = edx;
    }
    ecx = *dword_4c6bc8;
    esi = eax + *dword_4c6bc8;
    bool_227 = *(esi * 0x8 + 0x4d552c) > 0x0;
    bool_143 = *(esi * 0x8 + 0x4d552c) < 0x0;
    if (!bool_227 && (bool_143 || *(esi * 0x8 + 0x4d5528) < 0x2)) {
            ecx = *dword_4c6bc8;
            ecx = ecx | 0xffffffff;
            *dword_4c6bc8 = ecx;
    }
    esi = *dword_4c6bcc;
    eax = eax + *dword_4c6bcc;
    bool_221 = *(eax * 0x8 + 0x4d552c) < 0x0;
    if (*(eax * 0x8 + 0x4d552c) <= 0x0 && (bool_221 || *(eax * 0x8 + 0x4d5528) < 0x2)) {
            esi = *dword_4c6bcc;
            esi = esi | 0xffffffff;
            *dword_4c6bcc = esi;
    }
    bool_255 = edx != 0xffffffff;
    if (edx == 0xffffffff) {
            bool_174 = ecx != edx;
            if (ecx > edx) {
                    edx = ecx;
                    ecx = ecx | 0xffffffff;
                    *dword_4c6bc4 = edx;
                    *dword_4c6bc8 = ecx;
                    if (esi > 0xffffffff) {
                            ecx = esi;
                            esi = esi | 0xffffffff;
                            *dword_4c6bc8 = ecx;
                            *dword_4c6bcc = esi;
                    }
            }
            else {
                    if (!bool_174 && esi > 0xffffffff) {
                            ecx = esi;
                            esi = esi | 0xffffffff;
                            *dword_4c6bc8 = ecx;
                            *dword_4c6bcc = esi;
                    }
            }
    }
    else {
            if (!bool_255 && esi > 0xffffffff) {
                    ecx = esi;
                    esi = esi | 0xffffffff;
                    *dword_4c6bc8 = ecx;
                    *dword_4c6bcc = esi;
            }
    }
    bool_130 = edx <= 0xffffffff;
    if (edx == 0xffffffff) {
            if (ecx == edx) {
                    bool_182 = esi <= edx;
                    if (esi > edx) {
                            edx = esi;
                            *dword_4c6bc4 = edx;
                            *dword_4c6bcc = 0xffffffff;
                            if (!bool_182) {
                                    ebx = 0x0;
                                    if (*(decomp_var_34[0x2] + 0x2404) > 0x0) {
                                            while (true) {
                                                    if (ebx == ebp) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    if (ebx == edx) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    eax = edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx;
                                                    ecx = *(&decomp_var_4c + eax + 0xd4);
                                                    if (ecx <= 0x1) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    if (ecx != *(&decomp_var_4c + eax + 0x7bc)) {
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    esp = esp - 0x4;
                                                    decomp_var_38 = edx & 0xff | 0x4100;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_50);
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    decomp_var_50 = eax;
                                                    decomp_var_54 = "It would seem our best ally (%s) has been severely pressured by another power ";
                                                    decomp_var_58 = &decomp_var_2c;
                                                    sub_410c10(decomp_var_58, "It would seem our best ally (%s) has been severely pressured by another power ", decomp_var_50);
                                                    edx = **(decomp_var_2c - 0x10);
                                                    eax = edx[0x4];
                                                    esi = decomp_var_2c - 0x10;
                                                    esp = (esp - 0xc) + 0xc;
                                                    eax = (eax)();
                                                    ecx = esi + 0xc;
                                                    if (esi[0x3] >= 0x0) {
                                                            if (eax == *esi) {
                                                                    edi = esi;
                                                                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
                                                                    esp = esp - 0x8;
                                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                                    eax = edi + 0x10 - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            (*(**eax + 0x4))(eax);
                                                                    }
                                                                    edx = *dword_4c6bc4;
                                                                    *(int8_t *)byte_baed45 = 0x1;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                            continue;
                                                                    }
                                                                    temp_3 = 0x0;
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = esi[0x1];
                                                                    edx = *eax;
                                                                    edx = *edx;
                                                                    esp = esp - 0x8;
                                                                    edi = (edx)(ecx, 0x1);
                                                                    if (edi != 0x0) {
                                                                            edi[0x1] = esi[0x1];
                                                                            eax = esi[0x1];
                                                                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            esp = esp - 0x8;
                                                                            eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                                            eax = edi + 0x10 - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    (*(**eax + 0x4))(eax);
                                                                            }
                                                                            edx = *dword_4c6bc4;
                                                                            *(int8_t *)byte_baed45 = 0x1;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                                    continue;
                                                                            }
                                                                            temp_3 = 0x0;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_3 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            ecx = esi[0x1];
                                                            edx = *eax;
                                                            edx = *edx;
                                                            esp = esp - 0x8;
                                                            edi = (edx)(ecx, 0x1);
                                                            if (edi != 0x0) {
                                                                    edi[0x1] = esi[0x1];
                                                                    eax = esi[0x1];
                                                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                                    esp = (esp - 0x10) + 0x10;
                                                                    esp = esp - 0x8;
                                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                                    eax = edi + 0x10 - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            (*(**eax + 0x4))(eax);
                                                                    }
                                                                    edx = *dword_4c6bc4;
                                                                    *(int8_t *)byte_baed45 = 0x1;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                            continue;
                                                                    }
                                                                    temp_3 = 0x0;
                                                                    break;
                                                            }
                                                            else {
                                                                    temp_3 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            if (temp_3 != 0x0) {
                                                    eax = sub_40b6d0();
                                            }
                                            else {
                                                    ebx = decomp_var_40;
                                                    esi = *(ebx[0x2] + 0x2404);
                                                    if (esi > 0x0) {
                                                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                                    }
                                                    else {
                                                            if (*(int8_t *)byte_baed43 == 0x1) {
                                                                    edx = 0x0;
                                                                    ecx = 0x0;
                                                                    if (esi > 0x0) {
                                                                            eax = &arg_4d5524;
                                                                            do {
                                                                                    if (*eax == 0x3) {
                                                                                            edx = 0x0;
                                                                                            if (eax[0x1] == 0x0) {
                                                                                                    edx = 0x0;
                                                                                                    *eax = 0x1;
                                                                                                    eax[0x1] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = ecx + 0x1;
                                                                                    eax = eax + 0x8;
                                                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                                                    }
                                                            }
                                                            eax = decomp_var_38 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    decomp_var_5c = eax;
                                                                    eax = *(**eax + 0x4);
                                                                    eax = (eax)(decomp_var_5c);
                                                            }
                                                            *0x0 = arg_bd34;
                                                            &decomp_var_44 = decomp_var_4c;
                                                    }
                                            }
                                    }
                                    else {
                                            ebx = decomp_var_40;
                                            esi = *(ebx[0x2] + 0x2404);
                                            if (esi > 0x0) {
                                                    eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                            }
                                            else {
                                                    if (*(int8_t *)byte_baed43 == 0x1) {
                                                            edx = 0x0;
                                                            ecx = 0x0;
                                                            if (esi > 0x0) {
                                                                    eax = &arg_4d5524;
                                                                    do {
                                                                            if (*eax == 0x3) {
                                                                                    edx = 0x0;
                                                                                    if (eax[0x1] == 0x0) {
                                                                                            edx = 0x0;
                                                                                            *eax = 0x1;
                                                                                            eax[0x1] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = ecx + 0x1;
                                                                            eax = eax + 0x8;
                                                                    } while (ecx < *(ebx[0x2] + 0x2404));
                                                            }
                                                    }
                                                    eax = decomp_var_38 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            decomp_var_5c = eax;
                                                            eax = *(**eax + 0x4);
                                                            eax = (eax)(decomp_var_5c);
                                                    }
                                                    *0x0 = arg_bd34;
                                                    &decomp_var_44 = decomp_var_4c;
                                            }
                                    }
                            }
                            else {
                                    ebx = decomp_var_40;
                                    esi = *(ebx[0x2] + 0x2404);
                                    if (esi > 0x0) {
                                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                    }
                                    else {
                                            if (*(int8_t *)byte_baed43 == 0x1) {
                                                    edx = 0x0;
                                                    ecx = 0x0;
                                                    if (esi > 0x0) {
                                                            eax = &arg_4d5524;
                                                            do {
                                                                    if (*eax == 0x3) {
                                                                            edx = 0x0;
                                                                            if (eax[0x1] == 0x0) {
                                                                                    edx = 0x0;
                                                                                    *eax = 0x1;
                                                                                    eax[0x1] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = ecx + 0x1;
                                                                    eax = eax + 0x8;
                                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                                    }
                                            }
                                            eax = decomp_var_38 - 0x10;
                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                            if (edx <= 0x1) {
                                                    esp = esp - 0x4;
                                                    decomp_var_5c = eax;
                                                    eax = *(**eax + 0x4);
                                                    eax = (eax)(decomp_var_5c);
                                            }
                                            *0x0 = arg_bd34;
                                            &decomp_var_44 = decomp_var_4c;
                                    }
                            }
                    }
                    else {
                            ebx = decomp_var_40;
                            esi = *(ebx[0x2] + 0x2404);
                            if (esi > 0x0) {
                                    eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                            }
                            else {
                                    if (*(int8_t *)byte_baed43 == 0x1) {
                                            edx = 0x0;
                                            ecx = 0x0;
                                            if (esi > 0x0) {
                                                    eax = &arg_4d5524;
                                                    do {
                                                            if (*eax == 0x3) {
                                                                    edx = 0x0;
                                                                    if (eax[0x1] == 0x0) {
                                                                            edx = 0x0;
                                                                            *eax = 0x1;
                                                                            eax[0x1] = 0x0;
                                                                    }
                                                            }
                                                            ecx = ecx + 0x1;
                                                            eax = eax + 0x8;
                                                    } while (ecx < *(ebx[0x2] + 0x2404));
                                            }
                                    }
                                    eax = decomp_var_38 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            decomp_var_5c = eax;
                                            eax = *(**eax + 0x4);
                                            eax = (eax)(decomp_var_5c);
                                    }
                                    *0x0 = arg_bd34;
                                    &decomp_var_44 = decomp_var_4c;
                            }
                    }
            }
            else {
                    ebx = decomp_var_40;
                    esi = *(ebx[0x2] + 0x2404);
                    if (esi > 0x0) {
                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                    }
                    else {
                            if (*(int8_t *)byte_baed43 == 0x1) {
                                    edx = 0x0;
                                    ecx = 0x0;
                                    if (esi > 0x0) {
                                            eax = &arg_4d5524;
                                            do {
                                                    if (*eax == 0x3) {
                                                            edx = 0x0;
                                                            if (eax[0x1] == 0x0) {
                                                                    edx = 0x0;
                                                                    *eax = 0x1;
                                                                    eax[0x1] = 0x0;
                                                            }
                                                    }
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x8;
                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                    }
                            }
                            eax = decomp_var_38 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            if (edx <= 0x1) {
                                    esp = esp - 0x4;
                                    decomp_var_5c = eax;
                                    eax = *(**eax + 0x4);
                                    eax = (eax)(decomp_var_5c);
                            }
                            *0x0 = arg_bd34;
                            &decomp_var_44 = decomp_var_4c;
                    }
            }
    }
    else {
            if (!bool_130) {
                    ebx = 0x0;
                    if (*(decomp_var_34[0x2] + 0x2404) > 0x0) {
                            while (true) {
                                    if (ebx == ebp) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    if (ebx == edx) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    eax = edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx + edx * 0x15 + ebx;
                                    ecx = *(&decomp_var_4c + eax + 0xd4);
                                    if (ecx <= 0x1) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    if (ecx != *(&decomp_var_4c + eax + 0x7bc)) {
                                            ebx = ebx + 0x1;
                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                                    esp = esp - 0x4;
                                    decomp_var_38 = edx & 0xff | 0x4100;
                                    sub_46db50();
                                    eax = sub_4273a0(decomp_var_50);
                                    if (eax[0x6] >= 0x10) {
                                            eax = eax[0x1];
                                    }
                                    else {
                                            eax = eax + 0x4;
                                    }
                                    decomp_var_50 = eax;
                                    decomp_var_54 = "It would seem our best ally (%s) has been severely pressured by another power ";
                                    decomp_var_58 = &decomp_var_2c;
                                    sub_410c10(decomp_var_58, "It would seem our best ally (%s) has been severely pressured by another power ", decomp_var_50);
                                    edx = **(decomp_var_2c - 0x10);
                                    eax = edx[0x4];
                                    esi = decomp_var_2c - 0x10;
                                    esp = (esp - 0xc) + 0xc;
                                    eax = (eax)();
                                    ecx = esi + 0xc;
                                    if (esi[0x3] >= 0x0) {
                                            if (eax == *esi) {
                                                    edi = esi;
                                                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
                                                    esp = esp - 0x8;
                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                    eax = edi + 0x10 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    edx = *dword_4c6bc4;
                                                    *(int8_t *)byte_baed45 = 0x1;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                            continue;
                                                    }
                                                    temp_3 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    ecx = esi[0x1];
                                                    edx = *eax;
                                                    edx = *edx;
                                                    esp = esp - 0x8;
                                                    edi = (edx)(ecx, 0x1);
                                                    if (edi != 0x0) {
                                                            edi[0x1] = esi[0x1];
                                                            eax = esi[0x1];
                                                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                            esp = (esp - 0x10) + 0x10;
                                                            esp = esp - 0x8;
                                                            eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                            eax = edi + 0x10 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    (*(**eax + 0x4))(eax);
                                                            }
                                                            edx = *dword_4c6bc4;
                                                            *(int8_t *)byte_baed45 = 0x1;
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    else {
                                                            temp_3 = 0x1;
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            ecx = esi[0x1];
                                            edx = *eax;
                                            edx = *edx;
                                            esp = esp - 0x8;
                                            edi = (edx)(ecx, 0x1);
                                            if (edi != 0x0) {
                                                    edi[0x1] = esi[0x1];
                                                    eax = esi[0x1];
                                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                    esp = (esp - 0x10) + 0x10;
                                                    esp = esp - 0x8;
                                                    eax = sub_419e60(&arg_8, &decomp_var_28, decomp_var_58);
                                                    eax = edi + 0x10 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    edx = *dword_4c6bc4;
                                                    *(int8_t *)byte_baed45 = 0x1;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < *(decomp_var_40[0x2] + 0x2404)) {
                                                            continue;
                                                    }
                                                    temp_3 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    temp_3 = 0x1;
                                                    break;
                                            }
                                    }
                            }
                            if (temp_3 != 0x0) {
                                    eax = sub_40b6d0();
                            }
                            else {
                                    ebx = decomp_var_40;
                                    esi = *(ebx[0x2] + 0x2404);
                                    if (esi > 0x0) {
                                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                                    }
                                    else {
                                            if (*(int8_t *)byte_baed43 == 0x1) {
                                                    edx = 0x0;
                                                    ecx = 0x0;
                                                    if (esi > 0x0) {
                                                            eax = &arg_4d5524;
                                                            do {
                                                                    if (*eax == 0x3) {
                                                                            edx = 0x0;
                                                                            if (eax[0x1] == 0x0) {
                                                                                    edx = 0x0;
                                                                                    *eax = 0x1;
                                                                                    eax[0x1] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = ecx + 0x1;
                                                                    eax = eax + 0x8;
                                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                                    }
                                            }
                                            eax = decomp_var_38 - 0x10;
                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                            if (edx <= 0x1) {
                                                    esp = esp - 0x4;
                                                    decomp_var_5c = eax;
                                                    eax = *(**eax + 0x4);
                                                    eax = (eax)(decomp_var_5c);
                                            }
                                            *0x0 = arg_bd34;
                                            &decomp_var_44 = decomp_var_4c;
                                    }
                            }
                    }
                    else {
                            ebx = decomp_var_40;
                            esi = *(ebx[0x2] + 0x2404);
                            if (esi > 0x0) {
                                    eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                            }
                            else {
                                    if (*(int8_t *)byte_baed43 == 0x1) {
                                            edx = 0x0;
                                            ecx = 0x0;
                                            if (esi > 0x0) {
                                                    eax = &arg_4d5524;
                                                    do {
                                                            if (*eax == 0x3) {
                                                                    edx = 0x0;
                                                                    if (eax[0x1] == 0x0) {
                                                                            edx = 0x0;
                                                                            *eax = 0x1;
                                                                            eax[0x1] = 0x0;
                                                                    }
                                                            }
                                                            ecx = ecx + 0x1;
                                                            eax = eax + 0x8;
                                                    } while (ecx < *(ebx[0x2] + 0x2404));
                                            }
                                    }
                                    eax = decomp_var_38 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            decomp_var_5c = eax;
                                            eax = *(**eax + 0x4);
                                            eax = (eax)(decomp_var_5c);
                                    }
                                    *0x0 = arg_bd34;
                                    &decomp_var_44 = decomp_var_4c;
                            }
                    }
            }
            else {
                    ebx = decomp_var_40;
                    esi = *(ebx[0x2] + 0x2404);
                    if (esi > 0x0) {
                            eax = sub_436290(decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c);
                    }
                    else {
                            if (*(int8_t *)byte_baed43 == 0x1) {
                                    edx = 0x0;
                                    ecx = 0x0;
                                    if (esi > 0x0) {
                                            eax = &arg_4d5524;
                                            do {
                                                    if (*eax == 0x3) {
                                                            edx = 0x0;
                                                            if (eax[0x1] == 0x0) {
                                                                    edx = 0x0;
                                                                    *eax = 0x1;
                                                                    eax[0x1] = 0x0;
                                                            }
                                                    }
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x8;
                                            } while (ecx < *(ebx[0x2] + 0x2404));
                                    }
                            }
                            eax = decomp_var_38 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            if (edx <= 0x1) {
                                    esp = esp - 0x4;
                                    decomp_var_5c = eax;
                                    eax = *(**eax + 0x4);
                                    eax = (eax)(decomp_var_5c);
                            }
                            *0x0 = arg_bd34;
                            &decomp_var_44 = decomp_var_4c;
                    }
            }
    }
    return eax;

loc_435fc0:
    bool_272 = eax[0x1] > 0x0;
    bool_270 = eax[0x1] < 0x0;
    if (!bool_272) {
            if (!bool_270) {
                    if (*eax < 0x2 && ecx != ebp) {
                            decomp_var_21 = 0x1;
                    }
            }
            else {
                    if (ecx != ebp) {
                            decomp_var_21 = 0x1;
                    }
            }
    }
    ecx = ecx + 0x1;
    eax = eax + 0x8;
    if (ecx < edx) {
            continue;
    }
    break;
    if (decomp_var_21 == 0x0 && decomp_var_22 == 0x1) {
            ecx = 0x0;
            if (edx > 0x0) {
                    while (true) {
                            if (*(&decomp_var_4c + ecx * 0x4 + 0x7c) >= 0x2) {
                                    ecx = ecx + 0x1;
                                    if (ecx < edx) {
                                            continue;
                                    }
                                    temp_5 = 0x0;
                                    break;
                            }
                            if (ecx != ebp) {
                                    eax = *(&decomp_var_4c + ecx * 0x4 + 0x7c);
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d5528) = eax;
                                    *((ebp * 0x15 + ecx) * 0x8 + 0x4d552c) = eax & 0x80000000 ? 0xffffffff : 0x0;
                                    temp_5 = 0x1;
                                    break;
                            }
                            ecx = ecx + 0x1;
                            if (ecx < edx) {
                                    continue;
                            }
                            temp_5 = 0x0;
                            break;
                    }
            }
    }
    goto .l10;
}
