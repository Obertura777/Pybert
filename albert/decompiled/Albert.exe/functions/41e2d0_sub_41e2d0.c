// sub_41e2d0 @ 0x41e2d0
// hopper name: sub_41e2d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41e2d0() {
    var_C = *0x0;
    decomp_var_9c = esi;
    decomp_var_a0 = edi;
    esp = esp - 0xa4;
    var_A4 = *dword_4c8db8 ^ &decomp_var_a0;
    *0x0 = &var_C;
    var_64 = ecx;
    *(int16_t *)arg_0 = 0x0;
    sub_465870();
    sub_465870();
    sub_465870();
    eax = sub_401e30();
    var_7C = eax;
    eax[0x11] = 0x1;
    var_7C[0x1] = var_7C;
    *var_7C = var_7C;
    var_7C[0x2] = var_7C;
    eax = sub_401e30();
    var_88 = eax;
    eax[0x11] = 0x1;
    var_88[0x1] = var_88;
    *var_88 = var_88;
    var_88[0x2] = var_88;
    ebp = *(int8_t *)(ecx[0x2] + 0x2424) & 0xff;
    if (sub_465930() != 0x4) goto .l16;
    goto loc_41e3e6;

.l16:
    edi = arg_28;
    *(int16_t *)edi = *(int16_t *)word_4c6d28;
    goto loc_41e92f;

loc_41e3e6:
    edi = 0x0;
    eax = sub_466480(&var_4C, &arg_14);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466060(&var_4C, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466060(&var_4C, 0x3);
    sub_465ff0(eax);
    sub_465fa0();
    esi = sub_465930();
    var_6C = sub_465930();
    var_60 = sub_465930();
    sub_401950(var_7C[0x1]);
    var_7C[0x1] = var_7C;
    *var_7C = var_7C;
    var_7C[0x2] = var_7C;
    esp = esp - 0x2c;
    sub_401950(var_88[0x1]);
    var_88[0x1] = var_88;
    *var_88 = var_88;
    var_88[0x2] = var_88;
    if (esi > 0x0) {
            &var_A4 = &var_A4;
            do {
                    eax = sub_465900(&var_6E, edi);
                    esp = esp - 0x10;
                    var_74 = *(int8_t *)eax & 0xff;
                    eax = sub_404ce0(&var_58, &var_74, var_A4);
                    edi = edi + 0x1;
            } while (edi < esi);
    }
    ebx = 0x0;
    if (var_6C <= 0x0) goto loc_41e5d6;
    goto loc_41e54f;

loc_41e92f:
    sub_403430(&var_10, &var_3C, *var_38, &var_3C, var_38);
    sub_47c8f9();
    sub_403430(&var_10, &var_30, *var_2C, &var_30, var_2C);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = edi;
    *0x0 = arg_40;
    return eax;

loc_41e5d6:
    var_58 = 0x0;
    if (var_6C > 0x0) {
            esi = var_60;
            do {
                    esp = esp - 0x8;
                    eax = sub_465900(&var_6E, var_58);
                    ebx = *(int8_t *)eax & 0xff;
                    if (ebx != ebp) {
                            var_68 = 0x0;
                            if (esi > 0x0) {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&var_74, var_68);
                                    bool_165 = *(int8_t *)byte_baed5f != 0x1;
                                    eax = *(int8_t *)eax & 0xff;
                                    if (!bool_165) {
                                            esi = *(ebx * 0x8 + 0x4cf568);
                                            edi = *(ebx * 0x8 + 0x4cf56c);
                                            if ((esi | edi) == 0x0) {
                                                    ecx = ebp * 0x15;
                                                    if (*((ecx + ebx) * 0x4 + 0x634e90) >= 0x0) {
                                                            if ((*(eax * 0x8 + 0x4cf568) != 0x1 || *(eax * 0x8 + 0x4cf56c) != 0x0) && *((ecx + eax) * 0x4 + 0x634e90) >= 0x0) {
                                                                    ecx = ebx * 0x15;
                                                                    if (*((ecx + eax) * 0x4 + 0xba2888) <= 0x0) {
                                                                            edx = ebp * 0x15 + ebx;
                                                                            bool_141 = *(edx * 0x8 + 0x4d552c) > 0x0;
                                                                            if (*(edx * 0x8 + 0x4d552c) >= 0x0 && (bool_141 || *(edx * 0x8 + 0x4d5528) >= 0x3)) {
                                                                                    ecx = ecx + ebp;
                                                                                    bool_295 = *(ecx * 0x8 + 0x4d552c) < 0x0;
                                                                                    bool_178 = *(ecx * 0x8 + 0x4d552c) > 0x0;
                                                                                    if (!bool_295 && (bool_178 || *(ecx * 0x8 + 0x4d5528) >= 0x1)) {
                                                                                            if ((esi != 0x1 || edi != 0x0) && *(edx * 0x4 + 0x634e90) >= 0x0 && *(ebx * 0x4 + 0xb9fdd8) == eax && *(edx * 0x4 + 0x6340c0) <= 0x3 && *dword_4c6bc4 != eax && *(ebp * 0x4 + 0x633ec0) < 0x2) {
                                                                                                    edx = var_64[0x2];
                                                                                                    edx = edx[0x901];
                                                                                                    if (edx > 0x0) {
                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                            esi = edx;
                                                                                                            &var_A4 = &var_A4;
                                                                                                            do {
                                                                                                                    eax = eax + 0x4;
                                                                                                                    ecx = ecx + 0x4;
                                                                                                                    esi = esi - 0x1;
                                                                                                            } while (esi != 0x0);
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            ecx = ebx * 0x15;
                                                            if (*((ecx + eax) * 0x4 + 0xba2888) <= 0x0) {
                                                                    edx = ebp * 0x15 + ebx;
                                                                    bool_141 = *(edx * 0x8 + 0x4d552c) > 0x0;
                                                                    if (*(edx * 0x8 + 0x4d552c) >= 0x0 && (bool_141 || *(edx * 0x8 + 0x4d5528) >= 0x3)) {
                                                                            ecx = ecx + ebp;
                                                                            bool_295 = *(ecx * 0x8 + 0x4d552c) < 0x0;
                                                                            bool_178 = *(ecx * 0x8 + 0x4d552c) > 0x0;
                                                                            if (!bool_295 && (bool_178 || *(ecx * 0x8 + 0x4d5528) >= 0x1)) {
                                                                                    if ((esi != 0x1 || edi != 0x0) && *(edx * 0x4 + 0x634e90) >= 0x0 && *(ebx * 0x4 + 0xb9fdd8) == eax && *(edx * 0x4 + 0x6340c0) <= 0x3 && *dword_4c6bc4 != eax && *(ebp * 0x4 + 0x633ec0) < 0x2) {
                                                                                            edx = var_64[0x2];
                                                                                            edx = edx[0x901];
                                                                                            if (edx > 0x0) {
                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                    esi = edx;
                                                                                                    &var_A4 = &var_A4;
                                                                                                    do {
                                                                                                            eax = eax + 0x4;
                                                                                                            ecx = ecx + 0x4;
                                                                                                            esi = esi - 0x1;
                                                                                                    } while (esi != 0x0);
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    ecx = ebx * 0x15;
                                                    if (*((ecx + eax) * 0x4 + 0xba2888) <= 0x0) {
                                                            edx = ebp * 0x15 + ebx;
                                                            bool_141 = *(edx * 0x8 + 0x4d552c) > 0x0;
                                                            if (*(edx * 0x8 + 0x4d552c) >= 0x0 && (bool_141 || *(edx * 0x8 + 0x4d5528) >= 0x3)) {
                                                                    ecx = ecx + ebp;
                                                                    bool_295 = *(ecx * 0x8 + 0x4d552c) < 0x0;
                                                                    bool_178 = *(ecx * 0x8 + 0x4d552c) > 0x0;
                                                                    if (!bool_295 && (bool_178 || *(ecx * 0x8 + 0x4d5528) >= 0x1)) {
                                                                            if ((esi != 0x1 || edi != 0x0) && *(edx * 0x4 + 0x634e90) >= 0x0 && *(ebx * 0x4 + 0xb9fdd8) == eax && *(edx * 0x4 + 0x6340c0) <= 0x3 && *dword_4c6bc4 != eax && *(ebp * 0x4 + 0x633ec0) < 0x2) {
                                                                                    edx = var_64[0x2];
                                                                                    edx = edx[0x901];
                                                                                    if (edx > 0x0) {
                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                            esi = edx;
                                                                                            &var_A4 = &var_A4;
                                                                                            do {
                                                                                                    eax = eax + 0x4;
                                                                                                    ecx = ecx + 0x4;
                                                                                                    esi = esi - 0x1;
                                                                                            } while (esi != 0x0);
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                            esi = var_38;
                                            eax = var_40 + 0x1;
                                            var_40 = eax;
                                            if (eax < esi) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    else {
                                            if (*(eax * 0x8 + 0x4cf568) == 0x1 && *(eax * 0x8 + 0x4cf56c) == 0x0) {
                                                    esi = var_38;
                                                    eax = var_40 + 0x1;
                                                    var_40 = eax;
                                                    if (eax < esi) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    ecx = ebx * 0x15;
                                                    if (*((ecx + eax) * 0x4 + 0xba2888) <= 0x0) {
                                                            ecx = ecx + ebp;
                                                            bool_226 = *(ecx * 0x8 + 0x4d552c) > 0x0;
                                                            if (*(ecx * 0x8 + 0x4d552c) >= 0x0 && (bool_226 || *(ecx * 0x8 + 0x4d5528) >= 0x1)) {
                                                                    if (*(ebx * 0x8 + 0x4cf568) == 0x1) {
                                                                            if (*(ebx * 0x8 + 0x4cf56c) != 0x0) {
                                                                                    ecx = ebp * 0x15 + ebx;
                                                                                    if (*(ecx * 0x4 + 0x634e90) >= 0x0) {
                                                                                            esi = *(ecx * 0x8 + 0x4d552c);
                                                                                            bool_42 = esi < 0x0;
                                                                                            edi = *(ecx * 0x8 + 0x4d5528);
                                                                                            if (esi <= 0x0) {
                                                                                                    if (!bool_42) {
                                                                                                            if (edi < 0x3) {
                                                                                                                    if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                                            bool_302 = esi > 0x0;
                                                                                                                            if (esi >= 0x0) {
                                                                                                                                    if (!bool_302) {
                                                                                                                                            if (edi >= 0x1) {
                                                                                                                                                    esi = *(ebx * 0x4 + 0xb9fdd8);
                                                                                                                                                    if (esi == eax) {
                                                                                                                                                            if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                                                                                    if (*(eax * 0x8 + 0x4d5480) == 0x1) {
                                                                                                                                                                            if (*(eax * 0x8 + 0x4d5484) != 0x0) {
                                                                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                                            esi = edx;
                                                                                                                                                                                                            do {
                                                                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                                                                    }
                                                                                                                                                                                            }
                                                                                                                                                                                    }
                                                                                                                                                                                    esi = var_38;
                                                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                                                    var_40 = eax;
                                                                                                                                                                                    if (eax < esi) {
                                                                                                                                                                                            continue;
                                                                                                                                                                                    }
                                                                                                                                                                                    break;
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    esi = var_38;
                                                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                                                    var_40 = eax;
                                                                                                                                                                                    if (eax < esi) {
                                                                                                                                                                                            continue;
                                                                                                                                                                                    }
                                                                                                                                                                                    break;
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                            esi = edx;
                                                                                                                                                                                            do {
                                                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                            esi = var_38;
                                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                                            var_40 = eax;
                                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                            esi = edx;
                                                                                                                                                                                            do {
                                                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    esi = var_38;
                                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                                    var_40 = eax;
                                                                                                                                                                    if (eax < esi) {
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            esi = var_38;
                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                            var_40 = eax;
                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    esi = var_38;
                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                    var_40 = eax;
                                                                                                                                                    if (eax < esi) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            esi = *(ebx * 0x4 + 0xb9fdd8);
                                                                                                                                            if (esi == eax) {
                                                                                                                                                    edx = *(int8_t *)byte_baed68;
                                                                                                                                                    if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                                                                            if (*(eax * 0x8 + 0x4d5480) == 0x1) {
                                                                                                                                                                    if (*(eax * 0x8 + 0x4d5484) != 0x0) {
                                                                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                                    esi = edx;
                                                                                                                                                                                                    do {
                                                                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                                                                            }
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                            esi = var_38;
                                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                                            var_40 = eax;
                                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            esi = var_38;
                                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                                            var_40 = eax;
                                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                    esi = edx;
                                                                                                                                                                                    do {
                                                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    esi = var_38;
                                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                                    var_40 = eax;
                                                                                                                                                                    if (eax < esi) {
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && edx == 0x0) {
                                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                            esi = edx;
                                                                                                                                                                            do {
                                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            esi = var_38;
                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                            var_40 = eax;
                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    esi = var_38;
                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                    var_40 = eax;
                                                                                                                                                    if (eax < esi) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    esi = var_38;
                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                    var_40 = eax;
                                                                                                                                    if (eax < esi) {
                                                                                                                                            continue;
                                                                                                                                    }
                                                                                                                                    break;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            esi = var_38;
                                                                                                                            eax = var_40 + 0x1;
                                                                                                                            var_40 = eax;
                                                                                                                            if (eax < esi) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    esi = *(ebx * 0x4 + 0xb9fdd8);
                                                                                                                    if (esi == eax) {
                                                                                                                            if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                                                    if (*(eax * 0x8 + 0x4d5480) == 0x1) {
                                                                                                                                            if (*(eax * 0x8 + 0x4d5484) != 0x0) {
                                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                    esi = edx;
                                                                                                                                                                    do {
                                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    esi = var_38;
                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                    var_40 = eax;
                                                                                                                                                    if (eax < esi) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    esi = var_38;
                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                    var_40 = eax;
                                                                                                                                                    if (eax < esi) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                    esi = edx;
                                                                                                                                                                    do {
                                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                            esi = var_38;
                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                            var_40 = eax;
                                                                                                                                            if (eax < esi) {
                                                                                                                                                    continue;
                                                                                                                                            }
                                                                                                                                            break;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                            esi = edx;
                                                                                                                                                            do {
                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    esi = var_38;
                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                    var_40 = eax;
                                                                                                                                    if (eax < esi) {
                                                                                                                                            continue;
                                                                                                                                    }
                                                                                                                                    break;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            esi = var_38;
                                                                                                                            eax = var_40 + 0x1;
                                                                                                                            var_40 = eax;
                                                                                                                            if (eax < esi) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                                    bool_159 = esi > 0x0;
                                                                                                                    if (esi >= 0x0) {
                                                                                                                            if (!bool_159) {
                                                                                                                                    if (edi >= 0x1) {
                                                                                                                                            esi = *(ebx * 0x4 + 0xb9fdd8);
                                                                                                                                            if (esi == eax) {
                                                                                                                                                    if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                                                                            if (*(eax * 0x8 + 0x4d5480) == 0x1) {
                                                                                                                                                                    if (*(eax * 0x8 + 0x4d5484) != 0x0) {
                                                                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                                    esi = edx;
                                                                                                                                                                                                    do {
                                                                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                                                                            }
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                            esi = var_38;
                                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                                            var_40 = eax;
                                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            esi = var_38;
                                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                                            var_40 = eax;
                                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                            esi = edx;
                                                                                                                                                                                            do {
                                                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    esi = var_38;
                                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                                    var_40 = eax;
                                                                                                                                                                    if (eax < esi) {
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                    esi = edx;
                                                                                                                                                                                    do {
                                                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            esi = var_38;
                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                            var_40 = eax;
                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    esi = var_38;
                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                    var_40 = eax;
                                                                                                                                                    if (eax < esi) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            esi = var_38;
                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                            var_40 = eax;
                                                                                                                                            if (eax < esi) {
                                                                                                                                                    continue;
                                                                                                                                            }
                                                                                                                                            break;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    esi = *(ebx * 0x4 + 0xb9fdd8);
                                                                                                                                    if (esi == eax) {
                                                                                                                                            edx = *(int8_t *)byte_baed68;
                                                                                                                                            if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                                                                    if (*(eax * 0x8 + 0x4d5480) == 0x1) {
                                                                                                                                                            if (*(eax * 0x8 + 0x4d5484) != 0x0) {
                                                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                    esi = edx;
                                                                                                                                                                                    do {
                                                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    esi = var_38;
                                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                                    var_40 = eax;
                                                                                                                                                                    if (eax < esi) {
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    esi = var_38;
                                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                                    var_40 = eax;
                                                                                                                                                                    if (eax < esi) {
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                    esi = edx;
                                                                                                                                                                                    do {
                                                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            esi = var_38;
                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                            var_40 = eax;
                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                            if (edx == 0x0) {
                                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                            esi = edx;
                                                                                                                                                                            do {
                                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    esi = var_38;
                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                    var_40 = eax;
                                                                                                                                                    if (eax < esi) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            esi = var_38;
                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                            var_40 = eax;
                                                                                                                                            if (eax < esi) {
                                                                                                                                                    continue;
                                                                                                                                            }
                                                                                                                                            break;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            esi = var_38;
                                                                                                                            eax = var_40 + 0x1;
                                                                                                                            var_40 = eax;
                                                                                                                            if (eax < esi) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    esi = var_38;
                                                                                                                    eax = var_40 + 0x1;
                                                                                                                    var_40 = eax;
                                                                                                                    if (eax < esi) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    esi = *(ebx * 0x4 + 0xb9fdd8);
                                                                                                    if (esi == eax) {
                                                                                                            if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                                    if (*(eax * 0x8 + 0x4d5480) == 0x1) {
                                                                                                                            if (*(eax * 0x8 + 0x4d5484) != 0x0) {
                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                            esi = edx;
                                                                                                                                                            do {
                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    esi = var_38;
                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                    var_40 = eax;
                                                                                                                                    if (eax < esi) {
                                                                                                                                            continue;
                                                                                                                                    }
                                                                                                                                    break;
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    esi = var_38;
                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                    var_40 = eax;
                                                                                                                                    if (eax < esi) {
                                                                                                                                            continue;
                                                                                                                                    }
                                                                                                                                    break;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                    if (edx > 0x0) {
                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                            esi = edx;
                                                                                                                                            do {
                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                            } while (esi != 0x0);
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            esi = var_38;
                                                                                                                            eax = var_40 + 0x1;
                                                                                                                            var_40 = eax;
                                                                                                                            if (eax < esi) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                            if (edx > 0x0) {
                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                    esi = edx;
                                                                                                                                    do {
                                                                                                                                            eax = eax + 0x4;
                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                            esi = esi - 0x1;
                                                                                                                                    } while (esi != 0x0);
                                                                                                                            }
                                                                                                                    }
                                                                                                                    esi = var_38;
                                                                                                                    eax = var_40 + 0x1;
                                                                                                                    var_40 = eax;
                                                                                                                    if (eax < esi) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            esi = var_38;
                                                                                                            eax = var_40 + 0x1;
                                                                                                            var_40 = eax;
                                                                                                            if (eax < esi) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            esi = var_38;
                                                                                            eax = var_40 + 0x1;
                                                                                            var_40 = eax;
                                                                                            if (eax < esi) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esi = var_38;
                                                                                    eax = var_40 + 0x1;
                                                                                    var_40 = eax;
                                                                                    if (eax < esi) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = ebp * 0x15 + ebx;
                                                                            if (*(ecx * 0x4 + 0x634e90) >= 0x0) {
                                                                                    esi = *(ecx * 0x8 + 0x4d552c);
                                                                                    bool_264 = esi < 0x0;
                                                                                    edi = *(ecx * 0x8 + 0x4d5528);
                                                                                    if (esi <= 0x0) {
                                                                                            if (!bool_264) {
                                                                                                    if (edi < 0x3) {
                                                                                                            if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                                    bool_183 = esi > 0x0;
                                                                                                                    if (esi >= 0x0) {
                                                                                                                            if (!bool_183) {
                                                                                                                                    if (edi >= 0x1) {
                                                                                                                                            esi = *(ebx * 0x4 + 0xb9fdd8);
                                                                                                                                            if (esi == eax) {
                                                                                                                                                    edx = *(int8_t *)byte_baed68;
                                                                                                                                                    if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                                                                            if (*(eax * 0x8 + 0x4d5480) == 0x1) {
                                                                                                                                                                    if (*(eax * 0x8 + 0x4d5484) != 0x0) {
                                                                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                                    esi = edx;
                                                                                                                                                                                                    do {
                                                                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                                                                            }
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                            esi = var_38;
                                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                                            var_40 = eax;
                                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            esi = var_38;
                                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                                            var_40 = eax;
                                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                            esi = edx;
                                                                                                                                                                                            do {
                                                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    esi = var_38;
                                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                                    var_40 = eax;
                                                                                                                                                                    if (eax < esi) {
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && edx == 0x0) {
                                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                            esi = edx;
                                                                                                                                                                            do {
                                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            esi = var_38;
                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                            var_40 = eax;
                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    esi = var_38;
                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                    var_40 = eax;
                                                                                                                                                    if (eax < esi) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            esi = var_38;
                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                            var_40 = eax;
                                                                                                                                            if (eax < esi) {
                                                                                                                                                    continue;
                                                                                                                                            }
                                                                                                                                            break;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    esi = *(ebx * 0x4 + 0xb9fdd8);
                                                                                                                                    if (esi == eax) {
                                                                                                                                            if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                                                                    if (*(eax * 0x8 + 0x4d5480) == 0x1) {
                                                                                                                                                            if (*(eax * 0x8 + 0x4d5484) != 0x0) {
                                                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                            esi = edx;
                                                                                                                                                                                            do {
                                                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    esi = var_38;
                                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                                    var_40 = eax;
                                                                                                                                                                    if (eax < esi) {
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    esi = var_38;
                                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                                    var_40 = eax;
                                                                                                                                                                    if (eax < esi) {
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                            esi = edx;
                                                                                                                                                                            do {
                                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            esi = var_38;
                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                            var_40 = eax;
                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                    esi = edx;
                                                                                                                                                                    do {
                                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    esi = var_38;
                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                    var_40 = eax;
                                                                                                                                                    if (eax < esi) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            esi = var_38;
                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                            var_40 = eax;
                                                                                                                                            if (eax < esi) {
                                                                                                                                                    continue;
                                                                                                                                            }
                                                                                                                                            break;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            esi = var_38;
                                                                                                                            eax = var_40 + 0x1;
                                                                                                                            var_40 = eax;
                                                                                                                            if (eax < esi) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    esi = var_38;
                                                                                                                    eax = var_40 + 0x1;
                                                                                                                    var_40 = eax;
                                                                                                                    if (eax < esi) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            esi = *(ebx * 0x4 + 0xb9fdd8);
                                                                                                            if (esi == eax) {
                                                                                                                    if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                                            if (*(eax * 0x8 + 0x4d5480) == 0x1) {
                                                                                                                                    if (*(eax * 0x8 + 0x4d5484) != 0x0) {
                                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                    esi = edx;
                                                                                                                                                                    do {
                                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                            esi = var_38;
                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                            var_40 = eax;
                                                                                                                                            if (eax < esi) {
                                                                                                                                                    continue;
                                                                                                                                            }
                                                                                                                                            break;
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            esi = var_38;
                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                            var_40 = eax;
                                                                                                                                            if (eax < esi) {
                                                                                                                                                    continue;
                                                                                                                                            }
                                                                                                                                            break;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                    esi = edx;
                                                                                                                                                    do {
                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    esi = var_38;
                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                    var_40 = eax;
                                                                                                                                    if (eax < esi) {
                                                                                                                                            continue;
                                                                                                                                    }
                                                                                                                                    break;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                    esi = edx;
                                                                                                                                                    do {
                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            esi = var_38;
                                                                                                                            eax = var_40 + 0x1;
                                                                                                                            var_40 = eax;
                                                                                                                            if (eax < esi) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    esi = var_38;
                                                                                                                    eax = var_40 + 0x1;
                                                                                                                    var_40 = eax;
                                                                                                                    if (eax < esi) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                            bool_34 = esi > 0x0;
                                                                                                            if (esi >= 0x0) {
                                                                                                                    if (!bool_34) {
                                                                                                                            if (edi >= 0x1) {
                                                                                                                                    esi = *(ebx * 0x4 + 0xb9fdd8);
                                                                                                                                    if (esi == eax) {
                                                                                                                                            if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                                                                    if (*(eax * 0x8 + 0x4d5480) == 0x1) {
                                                                                                                                                            if (*(eax * 0x8 + 0x4d5484) != 0x0) {
                                                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                            esi = edx;
                                                                                                                                                                                            do {
                                                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    esi = var_38;
                                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                                    var_40 = eax;
                                                                                                                                                                    if (eax < esi) {
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    esi = var_38;
                                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                                    var_40 = eax;
                                                                                                                                                                    if (eax < esi) {
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                                    esi = edx;
                                                                                                                                                                                    do {
                                                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            esi = var_38;
                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                            var_40 = eax;
                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3) {
                                                                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                            esi = edx;
                                                                                                                                                                            do {
                                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    esi = var_38;
                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                    var_40 = eax;
                                                                                                                                                    if (eax < esi) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            esi = var_38;
                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                            var_40 = eax;
                                                                                                                                            if (eax < esi) {
                                                                                                                                                    continue;
                                                                                                                                            }
                                                                                                                                            break;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    esi = var_38;
                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                    var_40 = eax;
                                                                                                                                    if (eax < esi) {
                                                                                                                                            continue;
                                                                                                                                    }
                                                                                                                                    break;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            esi = *(ebx * 0x4 + 0xb9fdd8);
                                                                                                                            if (esi == eax) {
                                                                                                                                    if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                                                            if (*(eax * 0x8 + 0x4d5480) == 0x1) {
                                                                                                                                                    if (*(eax * 0x8 + 0x4d5484) != 0x0) {
                                                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                            esi = edx;
                                                                                                                                                                            do {
                                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            esi = var_38;
                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                            var_40 = eax;
                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            esi = var_38;
                                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                                            var_40 = eax;
                                                                                                                                                            if (eax < esi) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                            if (edx > 0x0) {
                                                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                                                    esi = edx;
                                                                                                                                                                    do {
                                                                                                                                                                            eax = eax + 0x4;
                                                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                                                            esi = esi - 0x1;
                                                                                                                                                                    } while (esi != 0x0);
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    esi = var_38;
                                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                                    var_40 = eax;
                                                                                                                                                    if (eax < esi) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                                    if (edx > 0x0) {
                                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                                            esi = edx;
                                                                                                                                                            do {
                                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                                            } while (esi != 0x0);
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                            esi = var_38;
                                                                                                                                            eax = var_40 + 0x1;
                                                                                                                                            var_40 = eax;
                                                                                                                                            if (eax < esi) {
                                                                                                                                                    continue;
                                                                                                                                            }
                                                                                                                                            break;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    esi = var_38;
                                                                                                                                    eax = var_40 + 0x1;
                                                                                                                                    var_40 = eax;
                                                                                                                                    if (eax < esi) {
                                                                                                                                            continue;
                                                                                                                                    }
                                                                                                                                    break;
                                                                                                                            }
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    esi = var_38;
                                                                                                                    eax = var_40 + 0x1;
                                                                                                                    var_40 = eax;
                                                                                                                    if (eax < esi) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            esi = var_38;
                                                                                                            eax = var_40 + 0x1;
                                                                                                            var_40 = eax;
                                                                                                            if (eax < esi) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            esi = *(ebx * 0x4 + 0xb9fdd8);
                                                                                            if (esi == eax) {
                                                                                                    if (*(int8_t *)byte_baed68 == 0x1) {
                                                                                                            if (*(eax * 0x8 + 0x4d5480) == 0x1) {
                                                                                                                    if (*(eax * 0x8 + 0x4d5484) != 0x0) {
                                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                                    if (edx > 0x0) {
                                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                                            esi = edx;
                                                                                                                                            do {
                                                                                                                                                    eax = eax + 0x4;
                                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                                    esi = esi - 0x1;
                                                                                                                                            } while (esi != 0x0);
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            esi = var_38;
                                                                                                                            eax = var_40 + 0x1;
                                                                                                                            var_40 = eax;
                                                                                                                            if (eax < esi) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            esi = var_38;
                                                                                                                            eax = var_40 + 0x1;
                                                                                                                            var_40 = eax;
                                                                                                                            if (eax < esi) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                            edx = *(var_64[0x2] + 0x2404);
                                                                                                                            if (edx > 0x0) {
                                                                                                                                    ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                                    eax = eax * 0x54 + 0xba2888;
                                                                                                                                    esi = edx;
                                                                                                                                    do {
                                                                                                                                            eax = eax + 0x4;
                                                                                                                                            ecx = ecx + 0x4;
                                                                                                                                            esi = esi - 0x1;
                                                                                                                                    } while (esi != 0x0);
                                                                                                                            }
                                                                                                                    }
                                                                                                                    esi = var_38;
                                                                                                                    eax = var_40 + 0x1;
                                                                                                                    var_40 = eax;
                                                                                                                    if (eax < esi) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            if (esi == eax && *(ecx * 0x4 + 0x6340c0) <= 0x3 && *(int8_t *)byte_baed68 == 0x0) {
                                                                                                                    edx = *(var_64[0x2] + 0x2404);
                                                                                                                    if (edx > 0x0) {
                                                                                                                            ecx = ebp * 0x54 + 0x6340c0;
                                                                                                                            eax = eax * 0x54 + 0xba2888;
                                                                                                                            esi = edx;
                                                                                                                            do {
                                                                                                                                    eax = eax + 0x4;
                                                                                                                                    ecx = ecx + 0x4;
                                                                                                                                    esi = esi - 0x1;
                                                                                                                            } while (esi != 0x0);
                                                                                                                    }
                                                                                                            }
                                                                                                            esi = var_38;
                                                                                                            eax = var_40 + 0x1;
                                                                                                            var_40 = eax;
                                                                                                            if (eax < esi) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    esi = var_38;
                                                                                                    eax = var_40 + 0x1;
                                                                                                    var_40 = eax;
                                                                                                    if (eax < esi) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esi = var_38;
                                                                                    eax = var_40 + 0x1;
                                                                                    var_40 = eax;
                                                                                    if (eax < esi) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    esi = var_38;
                                                                    eax = var_40 + 0x1;
                                                                    var_40 = eax;
                                                                    if (eax < esi) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            esi = var_38;
                                                            eax = var_40 + 0x1;
                                                            var_40 = eax;
                                                            if (eax < esi) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                            }
                    }
                    eax = var_30 + 0x1;
                    var_30 = eax;
            } while (eax < var_44);
    }
    if (var_65 != 0x0 && var_67 != 0x0) {
            if (var_66 != 0x0) {
                    if (var_68 == 0x1) {
                            edi = arg_28;
                            *(int16_t *)edi = *(int16_t *)word_4c6d48;
                    }
                    else {
                            edi = arg_28;
                            *(int16_t *)edi = *(int16_t *)word_4c6d28;
                    }
            }
            else {
                    edi = arg_28;
                    *(int16_t *)edi = *(int16_t *)word_4c6d28;
            }
    }
    else {
            edi = arg_28;
            *(int16_t *)edi = *(int16_t *)word_4c6d28;
    }
    goto loc_41e92f;

loc_41e54f:
    goto loc_41e550;

loc_41e550:
    eax = sub_465900(&var_6E, ebx);
    esi = *(int8_t *)eax & 0xff;
    esp = esp - 0x10;
    var_74 = esi;
    eax = sub_404ce0(&var_4C, &var_74, var_A4);
    edi = var_88;
    esp = esp - 0x8;
    eax = sub_401ff0(&var_58, &var_74, var_A4, decomp_var_a0, decomp_var_9c);
    esi = eax;
    eax = *esi;
    if (eax == 0x0 || eax != &var_8C) {
            sub_47a948();
    }
    ebx = ebx + 0x1;
    if (ebx < var_6C) {
            continue;
    }
    break;
}
