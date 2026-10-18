// ScoreOrderCandidates @ 0x4559c0
// hopper name: sub_4559c0
// pybert name: ScoreOrderCandidates
// contains unmarked entry 0x455fd0 (EnumerateHoldOrders)
// contains unmarked entry 0x456460
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

ScoreOrderCandidates() {
    decomp_var_c = *0x0;
    decomp_var_5b8 = esi;
    decomp_var_5bc = edi;
    decomp_var_5c0 = *dword_4c8db8 ^ &decomp_var_5bc;
    *0x0 = &decomp_var_c;
    ebp = ecx;
    decomp_var_594 = ebp;
    decomp_var_584 = 0x0;
    sub_47bba4();
    sub_47bba4();
    esp = esp - 0x5fc;
    sub_47bba4();
    decomp_var_5c4 = sub_41cc10;
    decomp_var_5c8 = sub_4220b0;
    esp = esp - 0x14;
    sub_47bba4();
    sub_465870();
    sub_465870();
    sub_465870();
    eax = sub_47020b();
    if (eax != 0x0) goto loc_455ae8;
    goto loc_455ade;

loc_455ae8:
    (*(*eax + 0xc))() + 0x10;
    edi = 0x0;
    decomp_var_4 = 0x9;
    decomp_var_59c = arg_4[0x2424] & 0xff;
    if (arg_4[0x901] > 0x0) {
            esi = 0xbb6cfc;
            do {
                    esp = esp - 0x4;
                    decomp_var_5c4 = *(*esi + 0x4);
                    sub_410cf0(decomp_var_5c4);
                    eax = *esi;
                    eax[0x1] = eax;
                    eax = *esi;
                    esi[0x1] = 0x0;
                    *eax = eax;
                    eax = *esi;
                    eax[0x2] = eax;
                    edi = edi + 0x1;
                    esi = esi + 0xc;
            } while (edi < arg_4[0x901]);
    }
    esi = **dword_bbf60c;
    edi = 0xbbf608;
    decomp_var_590 = 0xbbf608;
    decomp_var_58c = **dword_bbf60c;
    goto loc_455b65;

loc_455ade:
    eax = sub_40b5a0(0x80004005);
    return eax;

loc_455b65:
    if (edi == 0x0 || edi != 0xbbf608) {
            sub_47a948();
    }
    if (esi != *dword_bbf60c) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_5c4 = esi + 0x1c;
            esp = esp - 0x8;
            decomp_var_5c8 = &decomp_var_5a8;
            ebx = sub_401ff0(decomp_var_5c8, decomp_var_5c4, decomp_var_5c0, decomp_var_5bc, decomp_var_5b8);
            eax = *ebx;
            if (eax == 0x0 || eax != 0xbc1e00) {
                    sub_47a948();
            }
            if (ebx[0x1] == *dword_bc1e04) {
                    sub_40f260();
                    esi = decomp_var_58c;
                    edi = decomp_var_590;
                    ebp = decomp_var_594;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            asm { fldz };
            asm { fstp       dword [esi+0x58] };
            if (esi == edi[0x1]) {
                    sub_47a948();
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
            }
            esi[0x9] = esi[0x8];
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x50] = 0x0;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x10] = 0x0;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x11] = 0x0;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x51] = 0x0;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0xa] = 0x2710;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            asm { fld        dword [dword_value_1176256512] };
            asm { fstp       dword [esi+0x30] };
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0xb] = 0x0;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0xd] = 0x0;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            ebx = 0x0;
            asm { fldz };
            eax = decomp_var_594;
            asm { fstp       dword [esi+0x1c4] };
            if (*(eax[0x2] + 0x2400) > ebx) {
                    ebp = esi + 0x21c;
                    do {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            *ebp = 0x0;
                            ebx = ebx + 0x1;
                            ebp = &arg_0;
                    } while (ebx < *(decomp_var_594[0x2] + 0x2400));
            }
            ebx = esi + 0xd4;
            do {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    asm { fldz };
                    asm { fstp       dword [ebx-0x78] };
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    *ebx = 0x0;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    ebx[0x1e] = 0x0;
                    ebx = ebx + 0x4;
            } while (&decomp_var_1 != 0x0);
            sub_40f260();
            esi = decomp_var_58c;
            edi = decomp_var_590;
            ebp = decomp_var_594;
            continue;
    }
    break;
    esi = *arg_4;
    edi = &arg_0;
    decomp_var_5a8 = edi;
    decomp_var_5a4 = esi;
    goto loc_455d30;

loc_455d30:
    ebx = arg_4;
    if (edi == 0x0 || edi != &arg_0) {
            sub_47a948();
    }
    if (esi != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = sub_466060(&decomp_var_4a0, 0x1);
            sub_465ff0(eax);
            sub_465fa0();
            eax = sub_466060(&decomp_var_4f0, 0x0);
            eax = sub_465900(&decomp_var_59e, 0x0);
            sub_465fa0();
            sub_419300(&decomp_var_54c, &decomp_var_57c, decomp_var_5c0);
            eax = sub_419300(&decomp_var_470, &decomp_var_57c, decomp_var_5c0);
            edi = sub_465930();
            eax = sub_466060(&decomp_var_4b0, 0x1);
            decomp_var_5c4 = 0x0;
            esp = esp - 0x3c;
            decomp_var_5c8 = &decomp_var_5aa;
            esi = *(int16_t *)sub_465900(decomp_var_5c8, 0x0);
            decomp_var_4 = 0x9;
            sub_465fa0();
            if (*(int16_t *)word_4c6c20 == esi) {
                    eax = sub_466060(&decomp_var_4d0, 0x2);
                    sub_465ff0(eax);
                    sub_465fa0();
                    eax = sub_466060(&decomp_var_4e0, 0x2);
                    eax = sub_466060(&decomp_var_500, 0x0);
                    esp = esp - 0x24;
                    eax = sub_465900(&decomp_var_57e, 0x0);
                    esi = *(int8_t *)eax & 0xff;
                    sub_465fa0();
                    decomp_var_4 = 0x9;
                    sub_465fa0();
                    if (edi == 0x5) {
                            sub_465aa0();
                            eax = sub_466060(&decomp_var_540, 0x4);
                            edi = eax;
                            eax = sub_466480(&decomp_var_530, word_4c6c1c);
                            eax = sub_466330(&decomp_var_4c0, edi);
                            sub_465ff0(eax);
                            sub_465fa0();
                            sub_465fa0();
                            decomp_var_4 = 0x9;
                            sub_465fa0();
                            eax = sub_419300(&decomp_var_480, &decomp_var_520, decomp_var_5c0);
                            decomp_var_5c4 = &decomp_var_520;
                            esp = esp - 0x2c;
                            decomp_var_5c8 = &decomp_var_490;
                    }
                    else {
                            decomp_var_5c4 = &decomp_var_568;
                            esp = esp - 0x8;
                            decomp_var_5c8 = &decomp_var_510;
                    }
                    sub_419300(decomp_var_5c8, decomp_var_5c4, decomp_var_5c0);
            }
            sub_401590();
            esi = decomp_var_5a4;
            edi = decomp_var_5a8;
            continue;
    }
    break;
    esi = *arg_10;
    edi = &arg_c;
    decomp_var_5a8 = edi;
    decomp_var_5a4 = esi;
    goto loc_456044;

loc_456044:
    ebx = arg_10;
    if (edi == 0x0 || edi != &arg_c) {
            sub_47a948();
    }
    if (esi != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = sub_466060(&decomp_var_540, 0x1);
            sub_465ff0(eax);
            sub_465fa0();
            eax = sub_466060(&decomp_var_530, 0x0);
            eax = sub_465900(&decomp_var_57e, 0x0);
            decomp_var_4 = 0x9;
            sub_465fa0();
            decomp_var_5c4 = &decomp_var_57c;
            esp = esp - 0x24;
            decomp_var_5c8 = &decomp_var_510;
            sub_419300(decomp_var_5c8, decomp_var_5c4, decomp_var_5c0);
            sub_401590();
            esi = decomp_var_5a4;
            edi = decomp_var_5a8;
            continue;
    }
    break;
    esi = 0x0;
    if (arg_4[0x901] <= 0x0) goto loc_456198;
    goto loc_456131;

loc_456198:
    ebp = 0x0;
    decomp_var_590 = 0x0;
    if (*(decomp_var_59c[0x2] + 0x2404) <= 0x0) goto loc_456945;
    goto loc_4561b1;

loc_456131:
    edi = 0xbb6d00;
    goto loc_456136;

loc_456945:
    ecx = decomp_var_59c;
    esi = 0x0;
    decomp_var_5a4 = 0x0;
    if (*(ecx[0x2] + 0x2404) <= 0x0) goto loc_4569c7;
    goto loc_45695a;

loc_4561b1:
    esp = esp - 0x8;
    eax = sub_401ff0(&decomp_var_554, &decomp_var_590, decomp_var_5c8, decomp_var_5c4, decomp_var_5c0);
    esi = eax;
    eax = *esi;
    if (eax == 0x0 || eax != 0xbc1e00) {
            sub_47a948();
    }
    if (esi[0x1] == *dword_bc1e04) goto loc_45692b;
    goto loc_4561e8;

loc_456136:
    eax = *(esi * 0x4 + 0x62e460);
    if (eax > 0x0 && *edi != 0x0) {
            edx = HIDWORD(0x66666667 * (eax * *dword_4c6bb8 + 0xa));
            eax = (SAR(edx, 0x2) >> 0x1f) + (SAR(edx, 0x2));
            bool_16 = *dword_4c6bbc != 0x0;
            *(int8_t *)byte_baed5c = 0x0;
            if (!bool_16 && esi != decomp_var_59c) {
                    eax = 0x1;
            }
            decomp_var_5c4 = eax;
            esp = esp - 0x8;
            decomp_var_5c8 = esi;
            sub_44f5c0();
    }
    esi = esi + 0x1;
    edi = edi + 0xc;
    if (esi < arg_4[0x901]) {
            continue;
    }
    break;

loc_4569c7:
    eax = decomp_var_558 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
    if (ecx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_47b6f8();
    sub_47b6f8();
    sub_47b6f8();
    sub_47b6f8();
    sub_419cb0(&decomp_var_554, &decomp_var_4, *saved_fp, &decomp_var_4, saved_fp);
    sub_47c8f9();
    sub_419cb0(&decomp_var_554, &arg_4, *arg_8, &arg_4, arg_8);
    sub_47c8f9();
    eax = decomp_var_574;
    *0x0 = decomp_var_14;
    return eax;

loc_45695a:
    ebp = decomp_var_574;
    goto loc_456960;

loc_45692b:
    ebp = &arg_fffffffffffffffd;
    decomp_var_590 = ebp;
    if (ebp < *(decomp_var_59c[0x2] + 0x2404)) {
            continue;
    }
    break;

loc_4561e8:
    esi = 0xbbf608;
    edi = **dword_bbf60c;
    *(&decomp_var_5c8 + ebp * 0x4 + 0x170) = 0x0;
    decomp_var_598 = 0xbbf608;
    decomp_var_594 = edi;
    goto loc_456210;

loc_456960:
    esp = esp - 0x8;
    eax = sub_401ff0(&decomp_var_554, &decomp_var_5a4, decomp_var_5c8, decomp_var_5c4, decomp_var_5c0);
    edi = eax;
    eax = *edi;
    if (eax == 0x0 || eax != 0xbc1e00) {
            sub_47a948();
    }
    if (edi[0x1] != *dword_bc1e04) {
            if (*(&decomp_var_5c8 + (esi + esi * 0x2) * 0x4 + 0x1cc) != 0x0) {
                    eax = *(&decomp_var_5c8 + esi * 0x4 + 0x170);
                    if (eax < ebp) {
                            ebp = eax;
                    }
            }
    }
    ecx = decomp_var_59c[0x2];
    esi = esi + 0x1;
    decomp_var_5a4 = esi;
    if (esi < ecx[0x901]) {
            continue;
    }
    break;

loc_456210:
    if (esi == 0x0 || esi != 0xbbf608) {
            sub_47a948();
    }
    if (edi == *dword_bbf60c) goto .l36;
    goto loc_45622f;
    decomp_var_574 = ebp;
    goto loc_4569c7;

.l36:
    break;

loc_45622f:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    if (ebp != edi[0x7]) {
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    esi = decomp_var_594;
    if (esi == decomp_var_598[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    sub_465ff0(esi + 0xc);
    decomp_var_5a0 = sub_465930();
    edi = decomp_var_590 + decomp_var_590 * 0x2 + decomp_var_590 + decomp_var_590 * 0x2 + decomp_var_590 + decomp_var_590 * 0x2 + decomp_var_590 + decomp_var_590 * 0x2;
    decomp_var_5b2 = 0x1;
    decomp_var_5a4 = edi;
    if (*(&decomp_var_5c8 + edi + 0x1cc) == 0x0) goto loc_456386;
    goto loc_456299;

loc_456386:
    if (*(&decomp_var_5c8 + edi + 0x3c4) == 0x0) goto .l8;
    goto loc_456394;

loc_456299:
    esi = &decomp_var_5c8 + edi + 0x1c4;
    decomp_var_5b0 = esi;
    decomp_var_5ac = **(&decomp_var_5c8 + edi + 0x1c8);
    goto loc_4562c0;

.l8:
    if (*(&decomp_var_5c8 + edi + 0x2c8) == 0x0) goto .l14;
    goto .l18;

loc_456394:
    esi = &decomp_var_5c8 + edi + 0x3bc;
    decomp_var_5b0 = esi;
    decomp_var_5ac = **(&decomp_var_5c8 + edi + 0x3c0);
    &decomp_var_5c8 = &decomp_var_5c8;
    goto .l65;

loc_4562c0:
    ebx = *(&decomp_var_5c8 + edi + 0x1c8);
    eax = &decomp_var_5c8 + edi + 0x1c4;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (decomp_var_5ac != ebx) {
            ebp = 0x2;
            decomp_var_5a6 = 0x0;
            if (decomp_var_5a0 > 0x2) {
                    do {
                            esp = esp - 0x8;
                            eax = sub_466060(&decomp_var_548, ebp);
                            ebx = eax;
                            if (esi == 0x0) {
                                    sub_47a948();
                            }
                            if (decomp_var_5ac == esi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x4;
                            ebx = sub_465d90(ebx);
                            sub_465fa0();
                            if (ebx != 0x0) {
                                    decomp_var_5a6 = 0x1;
                            }
                            ebp = &arg_fffffffffffffffd;
                    } while (ebp < decomp_var_5a0);
                    if (decomp_var_5a6 == 0x0) {
                            decomp_var_5b2 = 0x0;
                    }
            }
            else {
                    decomp_var_5b2 = 0x0;
            }
            sub_401590();
            esi = decomp_var_5b0;
            continue;
    }
    break;

.l14:
    if (*(&decomp_var_5c8 + edi + 0x4c0) == 0x0) {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    eax = *(&decomp_var_5c8 + decomp_var_5a4 + 0x4bc);
    ebx = &decomp_var_5c8 + decomp_var_5a4 + 0x4b8;
    edi = ebx;
    decomp_var_5a4 = ebx;
    decomp_var_5b0 = edi;
    decomp_var_5ac = *eax;
    goto .l60;

.l18:
    ebp = &decomp_var_5c8 + edi + 0x2c0;
    decomp_var_5b0 = ebp;
    decomp_var_5ac = **(&decomp_var_5c8 + edi + 0x2c4);
    goto loc_4564a0;

.l65:
    ebx = *(&decomp_var_5c8 + edi + 0x3c0);
    eax = &decomp_var_5c8 + edi + 0x3bc;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (decomp_var_5ac != ebx) {
            ebp = 0x2;
            if (decomp_var_5a0 <= 0x2) {
                    sub_401590();
                    esi = decomp_var_5b0;
                    edi = decomp_var_5a4;
                    continue;
            }
            edi = decomp_var_5ac + 0xc;
            do {
                    esp = esp - 0x8;
                    eax = sub_466060(&decomp_var_538, ebp);
                    ebx = eax;
                    if (esi == 0x0) {
                            sub_47a948();
                    }
                    if (decomp_var_5ac == esi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    ebx = sub_465d90(ebx);
                    sub_465fa0();
                    if (ebx != 0x0) {
                            decomp_var_5b2 = 0x0;
                    }
                    ebp = &arg_fffffffffffffffd;
            } while (ebp < decomp_var_5a0);
            sub_401590();
            esi = decomp_var_5b0;
            edi = decomp_var_5a4;
            continue;
    }
    break;
    if (decomp_var_5b2 != 0x1) {
            if (decomp_var_5b2 == 0x0) {
                    esi = decomp_var_594;
                    edi = decomp_var_598;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x50] = 0x1;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x9] = 0xff676980;
            }
            else {
                    *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            }
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    if (*(&decomp_var_5c8 + edi + 0x3c4) == 0x0) goto loc_45646b;
    goto .l10;

.l60:
    esi = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (decomp_var_5ac == esi) goto .l63;
    goto .l62;

loc_4564a0:
    esi = *(&decomp_var_5c8 + edi + 0x2c4);
    eax = &decomp_var_5c8 + edi + 0x2c0;
    if (ebp == 0x0 || ebp != eax) {
            sub_47a948();
    }
    if (decomp_var_5ac == esi) goto .l24;
    goto loc_4564c5;
    if (decomp_var_5b2 != 0x1) {
            if (decomp_var_5b2 == 0x0) {
                    esi = decomp_var_594;
                    edi = decomp_var_598;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x50] = 0x1;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x9] = 0xff676980;
            }
            else {
                    *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            }
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    if (*(&decomp_var_5c8 + edi + 0x2c8) == 0x0) goto .l4;
    goto .l6;

loc_45646b:
    if (*(&decomp_var_5c8 + edi + 0x2c8) == 0x0) goto .l15;
    goto .l3;

.l10:
    esi = &decomp_var_5c8 + edi + 0x3bc;
    decomp_var_5b0 = esi;
    decomp_var_5ac = **(&decomp_var_5c8 + edi + 0x3c0);
    &decomp_var_5c8 = &decomp_var_5c8;
    goto loc_4563b0;

.l63:
    break;

.l62:
    esi = 0x2;
    if (decomp_var_5a0 <= 0x2) {
            sub_401590();
            edi = decomp_var_5b0;
            continue;
    }
    ebp = decomp_var_5a0;
    goto .l64;

.l24:
    break;

loc_4564c5:
    esi = 0x2;
    decomp_var_5a6 = 0x0;
    if (decomp_var_5a0 <= 0x2) goto loc_456717;
    goto loc_4564d9;

.l4:
    if (*(&decomp_var_5c8 + edi + 0x4c0) == 0x0) {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    eax = *(&decomp_var_5c8 + decomp_var_5a4 + 0x4bc);
    ebx = &decomp_var_5c8 + decomp_var_5a4 + 0x4b8;
    edi = ebx;
    decomp_var_5a4 = ebx;
    decomp_var_5b0 = edi;
    decomp_var_5ac = *eax;
    goto .l69;

.l6:
    ebp = &decomp_var_5c8 + edi + 0x2c0;
    decomp_var_5b0 = ebp;
    decomp_var_5ac = **(&decomp_var_5c8 + edi + 0x2c4);
    goto .l78;

.l15:
    if (*(&decomp_var_5c8 + edi + 0x4c0) == 0x0) {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    eax = *(&decomp_var_5c8 + decomp_var_5a4 + 0x4bc);
    ebx = &decomp_var_5c8 + decomp_var_5a4 + 0x4b8;
    edi = ebx;
    decomp_var_5a4 = ebx;
    decomp_var_5b0 = edi;
    decomp_var_5ac = *eax;
    goto .l73;

.l3:
    ebp = &decomp_var_5c8 + edi + 0x2c0;
    decomp_var_5b0 = ebp;
    decomp_var_5ac = **(&decomp_var_5c8 + edi + 0x2c4);
    goto .l42;

loc_4563b0:
    ebx = *(&decomp_var_5c8 + edi + 0x3c0);
    eax = &decomp_var_5c8 + edi + 0x3bc;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (decomp_var_5ac != ebx) {
            ebp = 0x2;
            if (decomp_var_5a0 <= 0x2) {
                    sub_401590();
                    esi = decomp_var_5b0;
                    edi = decomp_var_5a4;
                    continue;
            }
            edi = decomp_var_5ac + 0xc;
            do {
                    esp = esp - 0x8;
                    eax = sub_466060(&decomp_var_538, ebp);
                    ebx = eax;
                    if (esi == 0x0) {
                            sub_47a948();
                    }
                    if (decomp_var_5ac == esi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    ebx = sub_465d90(ebx);
                    sub_465fa0();
                    if (ebx != 0x0) {
                            decomp_var_5b2 = 0x0;
                    }
                    ebp = &arg_fffffffffffffffd;
            } while (ebp < decomp_var_5a0);
            sub_401590();
            esi = decomp_var_5b0;
            edi = decomp_var_5a4;
            continue;
    }
    break;
    if (decomp_var_5b2 == 0x0) {
            esi = decomp_var_594;
            edi = decomp_var_598;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x50] = 0x1;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x9] = 0xff676980;
    }
    else {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
    }
    sub_40f260();
    edi = decomp_var_594;
    ebp = decomp_var_590;
    esi = decomp_var_598;
    continue;

.l64:
    eax = sub_466060(&decomp_var_488, esi);
    eax = sub_466060(&decomp_var_498, 0x0);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    eax = sub_466060(&decomp_var_468, esi);
    eax = sub_466060(&decomp_var_478, 0x1);
    esp = esp - 0x2c;
    eax = sub_465900(&decomp_var_55e, 0x0);
    ebx = *(int16_t *)eax;
    sub_465fa0();
    sub_465fa0();
    if (edi == 0x0) {
            sub_47a948();
    }
    if (decomp_var_5ac == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_465d90(&decomp_var_570);
    if (eax != 0x0 && (*(int16_t *)word_4c6c1c == ebx || *(int16_t *)word_4c6c10 == ebx)) {
            decomp_var_5b2 = 0x0;
    }
    esi = esi + 0x1;
    if (esi < ebp) {
            continue;
    }
    break;
    if (decomp_var_5b2 != 0x1) {
            if (decomp_var_5b2 == 0x0) {
                    esi = decomp_var_594;
                    edi = decomp_var_598;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x50] = 0x1;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x9] = 0xff676980;
            }
            else {
                    *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            }
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    if (*(&decomp_var_5c8 + edi + 0x4c0) == 0x0) {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    eax = *(&decomp_var_5c8 + decomp_var_5a4 + 0x4bc);
    ebx = &decomp_var_5c8 + decomp_var_5a4 + 0x4b8;
    edi = ebx;
    decomp_var_5a4 = ebx;
    decomp_var_5b0 = edi;
    decomp_var_5ac = *eax;
    goto .l21;

loc_456717:
    decomp_var_5b2 = 0x0;
    goto loc_45671c;

loc_4564d9:
    &decomp_var_5c8 = &decomp_var_5c8;
    goto loc_4564e0;

.l69:
    esi = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (decomp_var_5ac == esi) goto .l67;
    goto .l66;

.l78:
    esi = *(&decomp_var_5c8 + edi + 0x2c4);
    eax = &decomp_var_5c8 + edi + 0x2c0;
    if (ebp == 0x0 || ebp != eax) {
            sub_47a948();
    }
    if (decomp_var_5ac == esi) goto .l79;
    goto .l77;

.l73:
    esi = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (decomp_var_5ac == esi) goto .l74;
    goto .l72;

.l42:
    esi = *(&decomp_var_5c8 + edi + 0x2c4);
    eax = &decomp_var_5c8 + edi + 0x2c0;
    if (ebp == 0x0 || ebp != eax) {
            sub_47a948();
    }
    if (decomp_var_5ac == esi) goto .l40;
    goto .l44;
    if (decomp_var_5b2 != 0x1) {
            if (decomp_var_5b2 == 0x0) {
                    esi = decomp_var_594;
                    edi = decomp_var_598;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x50] = 0x1;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x9] = 0xff676980;
            }
            else {
                    *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            }
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    if (*(&decomp_var_5c8 + edi + 0x2c8) == 0x0) goto loc_45673d;
    goto loc_456479;
    ebx = decomp_var_5a4;
    sub_401590();
    edi = decomp_var_5b0;
    continue;

.l21:
    esi = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (decomp_var_5ac == esi) goto .l23;
    goto .l22;

loc_45671c:
    sub_401590();
    ebp = decomp_var_5b0;
    edi = decomp_var_5a4;
    continue;

loc_4564e0:
    eax = sub_466060(&decomp_var_4e8, esi);
    eax = sub_466060(&decomp_var_4c8, 0x0);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    eax = sub_466060(&decomp_var_4d8, esi);
    eax = sub_466060(&decomp_var_508, 0x1);
    esp = esp - 0x2c;
    eax = sub_465900(&decomp_var_586, 0x0);
    edi = *(int16_t *)eax;
    sub_465fa0();
    sub_465fa0();
    if (ebp == 0x0) {
            sub_47a948();
    }
    ebx = decomp_var_5ac;
    if (ebx == arg_0) {
            sub_47a948();
    }
    eax = sub_466060(&decomp_var_4b8, 0x0);
    decomp_var_58c = decomp_var_58c | 0x1;
    esp = esp - 0xc;
    eax = sub_465d90(&decomp_var_570);
    if (eax != 0x0 && (*(int16_t *)word_4c6c1c == edi || *(int16_t *)word_4c6c10 == edi)) {
            ebx = 0x1;
    }
    else {
            ebx = 0x0;
    }
    if ((decomp_var_58c & 0x1) != 0x0) {
            decomp_var_58c = decomp_var_58c & 0xfffffffe;
            sub_465fa0();
    }
    if (ebx != 0x0) {
            eax = sub_466060(&decomp_var_4a8, esi);
            eax = sub_466060(&decomp_var_4f8, 0x2);
            esp = esp - 0x18;
            eax = sub_465900(&decomp_var_55c, 0x0);
            edi = *(int16_t *)eax;
            sub_465fa0();
            sub_465fa0();
            if (decomp_var_5ac == arg_0) {
                    sub_47a948();
            }
            eax = sub_466060(&decomp_var_518, 0x2);
            esp = esp - 0x10;
            eax = sub_465900(&decomp_var_55a, 0x0);
            bool_155 = edi == *(int16_t *)eax;
            sub_465fa0();
            if (!bool_155) {
                    decomp_var_5a6 = 0x1;
            }
    }
    esi = esi + 0x1;
    if (esi < decomp_var_5a0) {
            continue;
    }
    break;

.l67:
    break;

.l66:
    esi = 0x2;
    if (decomp_var_5a0 <= 0x2) {
            sub_401590();
            edi = decomp_var_5b0;
            continue;
    }
    ebp = decomp_var_5a0;
    goto .l70;

.l79:
    break;

.l77:
    esi = 0x2;
    decomp_var_5a6 = 0x0;
    if (decomp_var_5a0 <= 0x2) goto .l82;
    goto .l81;

.l74:
    break;

.l72:
    esi = 0x2;
    if (decomp_var_5a0 <= 0x2) {
            sub_401590();
            edi = decomp_var_5b0;
            continue;
    }
    ebp = decomp_var_5a0;
    goto .l75;

.l40:
    break;

.l44:
    esi = 0x2;
    decomp_var_5a6 = 0x0;
    if (decomp_var_5a0 <= 0x2) goto .l41;
    goto .l39;

loc_45673d:
    if (*(&decomp_var_5c8 + edi + 0x4c0) == 0x0) {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    eax = *(&decomp_var_5c8 + decomp_var_5a4 + 0x4bc);
    ebx = &decomp_var_5c8 + decomp_var_5a4 + 0x4b8;
    edi = ebx;
    decomp_var_5a4 = ebx;
    decomp_var_5b0 = edi;
    decomp_var_5ac = *eax;
    goto .l50;

loc_456479:
    ebp = &decomp_var_5c8 + edi + 0x2c0;
    decomp_var_5b0 = ebp;
    decomp_var_5ac = **(&decomp_var_5c8 + edi + 0x2c4);
    goto .l55;

.l23:
    break;

.l22:
    esi = 0x2;
    if (decomp_var_5a0 <= 0x2) {
            sub_401590();
            edi = decomp_var_5b0;
            continue;
    }
    ebp = decomp_var_5a0;
    goto .l26;
    if (decomp_var_5a6 == 0x0) {
            decomp_var_5b2 = 0x0;
    }
    goto loc_45671c;
    if (decomp_var_5b2 == 0x0) {
            esi = decomp_var_594;
            edi = decomp_var_598;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x50] = 0x1;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x9] = 0xff676980;
    }
    else {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
    }
    sub_40f260();
    edi = decomp_var_594;
    ebp = decomp_var_590;
    esi = decomp_var_598;
    continue;

.l70:
    eax = sub_466060(&decomp_var_488, esi);
    eax = sub_466060(&decomp_var_498, 0x0);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    eax = sub_466060(&decomp_var_468, esi);
    eax = sub_466060(&decomp_var_478, 0x1);
    esp = esp - 0x2c;
    eax = sub_465900(&decomp_var_55e, 0x0);
    ebx = *(int16_t *)eax;
    sub_465fa0();
    sub_465fa0();
    if (edi == 0x0) {
            sub_47a948();
    }
    if (decomp_var_5ac == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_465d90(&decomp_var_570);
    if (eax != 0x0 && (*(int16_t *)word_4c6c1c == ebx || *(int16_t *)word_4c6c10 == ebx)) {
            decomp_var_5b2 = 0x0;
    }
    esi = esi + 0x1;
    if (esi < ebp) {
            continue;
    }
    break;
    if (decomp_var_5b2 != 0x1) {
            if (decomp_var_5b2 == 0x0) {
                    esi = decomp_var_594;
                    edi = decomp_var_598;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x50] = 0x1;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x9] = 0xff676980;
            }
            else {
                    *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            }
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    if (*(&decomp_var_5c8 + edi + 0x4c0) == 0x0) {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    eax = *(&decomp_var_5c8 + decomp_var_5a4 + 0x4bc);
    ebx = &decomp_var_5c8 + decomp_var_5a4 + 0x4b8;
    edi = ebx;
    decomp_var_5a4 = ebx;
    decomp_var_5b0 = edi;
    decomp_var_5ac = *eax;
    goto loc_456770;

.l82:
    decomp_var_5b2 = 0x0;
    goto .l76;

.l81:
    &decomp_var_5c8 = &decomp_var_5c8;
    goto .l83;
    if (decomp_var_5b2 == 0x0) {
            esi = decomp_var_594;
            edi = decomp_var_598;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x50] = 0x1;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x9] = 0xff676980;
    }
    else {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
    }
    sub_40f260();
    edi = decomp_var_594;
    ebp = decomp_var_590;
    esi = decomp_var_598;
    continue;

.l75:
    eax = sub_466060(&decomp_var_488, esi);
    eax = sub_466060(&decomp_var_498, 0x0);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    eax = sub_466060(&decomp_var_468, esi);
    eax = sub_466060(&decomp_var_478, 0x1);
    esp = esp - 0x2c;
    eax = sub_465900(&decomp_var_55e, 0x0);
    ebx = *(int16_t *)eax;
    sub_465fa0();
    sub_465fa0();
    if (edi == 0x0) {
            sub_47a948();
    }
    if (decomp_var_5ac == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_465d90(&decomp_var_570);
    if (eax != 0x0 && (*(int16_t *)word_4c6c1c == ebx || *(int16_t *)word_4c6c10 == ebx)) {
            decomp_var_5b2 = 0x0;
    }
    esi = esi + 0x1;
    if (esi < ebp) {
            continue;
    }
    break;
    if (decomp_var_5b2 != 0x1) {
            if (decomp_var_5b2 == 0x0) {
                    esi = decomp_var_594;
                    edi = decomp_var_598;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x50] = 0x1;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x9] = 0xff676980;
            }
            else {
                    *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            }
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    if (*(&decomp_var_5c8 + edi + 0x4c0) == 0x0) {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    eax = *(&decomp_var_5c8 + decomp_var_5a4 + 0x4bc);
    ebx = &decomp_var_5c8 + decomp_var_5a4 + 0x4b8;
    edi = ebx;
    decomp_var_5a4 = ebx;
    decomp_var_5b0 = edi;
    decomp_var_5ac = *eax;
    goto .l30;

.l41:
    decomp_var_5b2 = 0x0;
    goto .l45;

.l39:
    &decomp_var_5c8 = &decomp_var_5c8;
    goto .l46;

.l50:
    esi = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (decomp_var_5ac == esi) goto .l49;
    goto .l47;

.l55:
    esi = *(&decomp_var_5c8 + edi + 0x2c4);
    eax = &decomp_var_5c8 + edi + 0x2c0;
    if (ebp == 0x0 || ebp != eax) {
            sub_47a948();
    }
    if (decomp_var_5ac == esi) goto .l57;
    goto .l52;
    if (decomp_var_5b2 == 0x0) {
            esi = decomp_var_594;
            edi = decomp_var_598;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x50] = 0x1;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x9] = 0xff676980;
    }
    else {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
    }
    sub_40f260();
    edi = decomp_var_594;
    ebp = decomp_var_590;
    esi = decomp_var_598;
    continue;

.l26:
    eax = sub_466060(&decomp_var_488, esi);
    eax = sub_466060(&decomp_var_498, 0x0);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    eax = sub_466060(&decomp_var_468, esi);
    eax = sub_466060(&decomp_var_478, 0x1);
    esp = esp - 0x2c;
    eax = sub_465900(&decomp_var_55e, 0x0);
    ebx = *(int16_t *)eax;
    sub_465fa0();
    sub_465fa0();
    if (edi == 0x0) {
            sub_47a948();
    }
    if (decomp_var_5ac == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_465d90(&decomp_var_570);
    if (eax != 0x0 && (*(int16_t *)word_4c6c1c == ebx || *(int16_t *)word_4c6c10 == ebx)) {
            decomp_var_5b2 = 0x0;
    }
    esi = esi + 0x1;
    if (esi < ebp) {
            continue;
    }
    break;
    ebx = decomp_var_5a4;
    sub_401590();
    edi = decomp_var_5b0;
    continue;

loc_456770:
    esi = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (decomp_var_5ac == esi) goto .l27;
    goto loc_45678a;

.l76:
    sub_401590();
    ebp = decomp_var_5b0;
    edi = decomp_var_5a4;
    continue;

.l83:
    eax = sub_466060(&decomp_var_4e8, esi);
    eax = sub_466060(&decomp_var_4c8, 0x0);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    eax = sub_466060(&decomp_var_4d8, esi);
    eax = sub_466060(&decomp_var_508, 0x1);
    esp = esp - 0x2c;
    eax = sub_465900(&decomp_var_586, 0x0);
    edi = *(int16_t *)eax;
    sub_465fa0();
    sub_465fa0();
    if (ebp == 0x0) {
            sub_47a948();
    }
    ebx = decomp_var_5ac;
    if (ebx == arg_0) {
            sub_47a948();
    }
    eax = sub_466060(&decomp_var_4b8, 0x0);
    decomp_var_58c = decomp_var_58c | 0x1;
    esp = esp - 0xc;
    eax = sub_465d90(&decomp_var_570);
    if (eax != 0x0 && (*(int16_t *)word_4c6c1c == edi || *(int16_t *)word_4c6c10 == edi)) {
            ebx = 0x1;
    }
    else {
            ebx = 0x0;
    }
    if ((decomp_var_58c & 0x1) != 0x0) {
            decomp_var_58c = decomp_var_58c & 0xfffffffe;
            sub_465fa0();
    }
    if (ebx != 0x0) {
            eax = sub_466060(&decomp_var_4a8, esi);
            eax = sub_466060(&decomp_var_4f8, 0x2);
            esp = esp - 0x18;
            eax = sub_465900(&decomp_var_55c, 0x0);
            edi = *(int16_t *)eax;
            sub_465fa0();
            sub_465fa0();
            if (decomp_var_5ac == arg_0) {
                    sub_47a948();
            }
            eax = sub_466060(&decomp_var_518, 0x2);
            esp = esp - 0x10;
            eax = sub_465900(&decomp_var_55a, 0x0);
            bool_262 = edi == *(int16_t *)eax;
            sub_465fa0();
            if (!bool_262) {
                    decomp_var_5a6 = 0x1;
            }
    }
    esi = esi + 0x1;
    if (esi < decomp_var_5a0) {
            continue;
    }
    break;
    ebx = decomp_var_5a4;
    sub_401590();
    edi = decomp_var_5b0;
    continue;

.l30:
    esi = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (decomp_var_5ac == esi) goto .l28;
    goto .l31;

.l45:
    sub_401590();
    ebp = decomp_var_5b0;
    edi = decomp_var_5a4;
    continue;

.l46:
    eax = sub_466060(&decomp_var_4e8, esi);
    eax = sub_466060(&decomp_var_4c8, 0x0);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    eax = sub_466060(&decomp_var_4d8, esi);
    eax = sub_466060(&decomp_var_508, 0x1);
    esp = esp - 0x2c;
    eax = sub_465900(&decomp_var_586, 0x0);
    edi = *(int16_t *)eax;
    sub_465fa0();
    sub_465fa0();
    if (ebp == 0x0) {
            sub_47a948();
    }
    ebx = decomp_var_5ac;
    if (ebx == arg_0) {
            sub_47a948();
    }
    eax = sub_466060(&decomp_var_4b8, 0x0);
    decomp_var_58c = decomp_var_58c | 0x1;
    esp = esp - 0xc;
    eax = sub_465d90(&decomp_var_570);
    if (eax != 0x0 && (*(int16_t *)word_4c6c1c == edi || *(int16_t *)word_4c6c10 == edi)) {
            ebx = 0x1;
    }
    else {
            ebx = 0x0;
    }
    if ((decomp_var_58c & 0x1) != 0x0) {
            decomp_var_58c = decomp_var_58c & 0xfffffffe;
            sub_465fa0();
    }
    if (ebx != 0x0) {
            eax = sub_466060(&decomp_var_4a8, esi);
            eax = sub_466060(&decomp_var_4f8, 0x2);
            esp = esp - 0x18;
            eax = sub_465900(&decomp_var_55c, 0x0);
            edi = *(int16_t *)eax;
            sub_465fa0();
            sub_465fa0();
            if (decomp_var_5ac == arg_0) {
                    sub_47a948();
            }
            eax = sub_466060(&decomp_var_518, 0x2);
            esp = esp - 0x10;
            eax = sub_465900(&decomp_var_55a, 0x0);
            bool_167 = edi == *(int16_t *)eax;
            sub_465fa0();
            if (!bool_167) {
                    decomp_var_5a6 = 0x1;
            }
    }
    esi = esi + 0x1;
    if (esi < decomp_var_5a0) {
            continue;
    }
    break;

.l49:
    break;

.l47:
    esi = 0x2;
    if (decomp_var_5a0 <= 0x2) {
            sub_401590();
            edi = decomp_var_5b0;
            continue;
    }
    ebp = decomp_var_5a0;
    goto .l51;

.l57:
    break;

.l52:
    esi = 0x2;
    decomp_var_5a6 = 0x0;
    if (decomp_var_5a0 <= 0x2) goto .l58;
    goto .l53;
    ebx = decomp_var_5a4;
    sub_401590();
    edi = decomp_var_5b0;
    continue;

.l27:
    break;

loc_45678a:
    esi = 0x2;
    if (decomp_var_5a0 <= 0x2) {
            sub_401590();
            edi = decomp_var_5b0;
            continue;
    }
    ebp = decomp_var_5a0;
    goto loc_4567a0;
    if (decomp_var_5a6 == 0x0) {
            decomp_var_5b2 = 0x0;
    }
    goto .l76;

.l28:
    break;

.l31:
    esi = 0x2;
    if (decomp_var_5a0 <= 0x2) {
            sub_401590();
            edi = decomp_var_5b0;
            continue;
    }
    ebp = decomp_var_5a0;
    goto .l32;
    if (decomp_var_5a6 == 0x0) {
            decomp_var_5b2 = 0x0;
    }
    goto .l45;
    if (decomp_var_5b2 == 0x0) {
            esi = decomp_var_594;
            edi = decomp_var_598;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x50] = 0x1;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x9] = 0xff676980;
    }
    else {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
    }
    sub_40f260();
    edi = decomp_var_594;
    ebp = decomp_var_590;
    esi = decomp_var_598;
    continue;

.l51:
    eax = sub_466060(&decomp_var_488, esi);
    eax = sub_466060(&decomp_var_498, 0x0);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    eax = sub_466060(&decomp_var_468, esi);
    eax = sub_466060(&decomp_var_478, 0x1);
    esp = esp - 0x2c;
    eax = sub_465900(&decomp_var_55e, 0x0);
    ebx = *(int16_t *)eax;
    sub_465fa0();
    sub_465fa0();
    if (edi == 0x0) {
            sub_47a948();
    }
    if (decomp_var_5ac == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_465d90(&decomp_var_570);
    if (eax != 0x0 && (*(int16_t *)word_4c6c1c == ebx || *(int16_t *)word_4c6c10 == ebx)) {
            decomp_var_5b2 = 0x0;
    }
    esi = esi + 0x1;
    if (esi < ebp) {
            continue;
    }
    break;
    if (decomp_var_5b2 != 0x1) {
            if (decomp_var_5b2 == 0x0) {
                    esi = decomp_var_594;
                    edi = decomp_var_598;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x50] = 0x1;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x9] = 0xff676980;
            }
            else {
                    *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            }
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    if (*(&decomp_var_5c8 + edi + 0x4c0) == 0x0) {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
            sub_40f260();
            edi = decomp_var_594;
            ebp = decomp_var_590;
            esi = decomp_var_598;
            continue;
    }
    eax = *(&decomp_var_5c8 + decomp_var_5a4 + 0x4bc);
    ebx = &decomp_var_5c8 + decomp_var_5a4 + 0x4b8;
    edi = ebx;
    decomp_var_5a4 = ebx;
    decomp_var_5b0 = edi;
    decomp_var_5ac = *eax;
    goto .l33;

.l58:
    decomp_var_5b2 = 0x0;
    goto .l54;

.l53:
    &decomp_var_5c8 = &decomp_var_5c8;
    goto .l59;
    if (decomp_var_5b2 == 0x0) {
            esi = decomp_var_594;
            edi = decomp_var_598;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x50] = 0x1;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x9] = 0xff676980;
    }
    else {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
    }
    sub_40f260();
    edi = decomp_var_594;
    ebp = decomp_var_590;
    esi = decomp_var_598;
    continue;

loc_4567a0:
    eax = sub_466060(&decomp_var_488, esi);
    eax = sub_466060(&decomp_var_498, 0x0);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    eax = sub_466060(&decomp_var_468, esi);
    eax = sub_466060(&decomp_var_478, 0x1);
    esp = esp - 0x2c;
    eax = sub_465900(&decomp_var_55e, 0x0);
    ebx = *(int16_t *)eax;
    sub_465fa0();
    sub_465fa0();
    if (edi == 0x0) {
            sub_47a948();
    }
    if (decomp_var_5ac == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_465d90(&decomp_var_570);
    if (eax != 0x0 && (*(int16_t *)word_4c6c1c == ebx || *(int16_t *)word_4c6c10 == ebx)) {
            decomp_var_5b2 = 0x0;
    }
    esi = esi + 0x1;
    if (esi < ebp) {
            continue;
    }
    break;
    if (decomp_var_5b2 == 0x0) {
            esi = decomp_var_594;
            edi = decomp_var_598;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x50] = 0x1;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x9] = 0xff676980;
    }
    else {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
    }
    sub_40f260();
    edi = decomp_var_594;
    ebp = decomp_var_590;
    esi = decomp_var_598;
    continue;

.l32:
    eax = sub_466060(&decomp_var_488, esi);
    eax = sub_466060(&decomp_var_498, 0x0);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    eax = sub_466060(&decomp_var_468, esi);
    eax = sub_466060(&decomp_var_478, 0x1);
    esp = esp - 0x2c;
    eax = sub_465900(&decomp_var_55e, 0x0);
    ebx = *(int16_t *)eax;
    sub_465fa0();
    sub_465fa0();
    if (edi == 0x0) {
            sub_47a948();
    }
    if (decomp_var_5ac == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_465d90(&decomp_var_570);
    if (eax != 0x0 && (*(int16_t *)word_4c6c1c == ebx || *(int16_t *)word_4c6c10 == ebx)) {
            decomp_var_5b2 = 0x0;
    }
    esi = esi + 0x1;
    if (esi < ebp) {
            continue;
    }
    break;
    ebx = decomp_var_5a4;
    sub_401590();
    edi = decomp_var_5b0;
    continue;

.l33:
    esi = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (decomp_var_5ac == esi) goto .l37;
    goto .l34;

.l54:
    sub_401590();
    ebp = decomp_var_5b0;
    edi = decomp_var_5a4;
    continue;

.l59:
    eax = sub_466060(&decomp_var_4e8, esi);
    eax = sub_466060(&decomp_var_4c8, 0x0);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    eax = sub_466060(&decomp_var_4d8, esi);
    eax = sub_466060(&decomp_var_508, 0x1);
    esp = esp - 0x2c;
    eax = sub_465900(&decomp_var_586, 0x0);
    edi = *(int16_t *)eax;
    sub_465fa0();
    sub_465fa0();
    if (ebp == 0x0) {
            sub_47a948();
    }
    ebx = decomp_var_5ac;
    if (ebx == arg_0) {
            sub_47a948();
    }
    eax = sub_466060(&decomp_var_4b8, 0x0);
    decomp_var_58c = decomp_var_58c | 0x1;
    esp = esp - 0xc;
    eax = sub_465d90(&decomp_var_570);
    if (eax != 0x0 && (*(int16_t *)word_4c6c1c == edi || *(int16_t *)word_4c6c10 == edi)) {
            ebx = 0x1;
    }
    else {
            ebx = 0x0;
    }
    if ((decomp_var_58c & 0x1) != 0x0) {
            decomp_var_58c = decomp_var_58c & 0xfffffffe;
            sub_465fa0();
    }
    if (ebx != 0x0) {
            eax = sub_466060(&decomp_var_4a8, esi);
            eax = sub_466060(&decomp_var_4f8, 0x2);
            esp = esp - 0x18;
            eax = sub_465900(&decomp_var_55c, 0x0);
            edi = *(int16_t *)eax;
            sub_465fa0();
            sub_465fa0();
            if (decomp_var_5ac == arg_0) {
                    sub_47a948();
            }
            eax = sub_466060(&decomp_var_518, 0x2);
            esp = esp - 0x10;
            eax = sub_465900(&decomp_var_55a, 0x0);
            bool_206 = edi == *(int16_t *)eax;
            sub_465fa0();
            if (!bool_206) {
                    decomp_var_5a6 = 0x1;
            }
    }
    esi = esi + 0x1;
    if (esi < decomp_var_5a0) {
            continue;
    }
    break;
    ebx = decomp_var_5a4;
    sub_401590();
    edi = decomp_var_5b0;
    continue;
    ebx = decomp_var_5a4;
    sub_401590();
    edi = decomp_var_5b0;
    continue;

.l37:
    break;

.l34:
    esi = 0x2;
    if (decomp_var_5a0 <= 0x2) {
            sub_401590();
            edi = decomp_var_5b0;
            continue;
    }
    ebp = decomp_var_5a0;
    goto .l38;
    if (decomp_var_5a6 == 0x0) {
            decomp_var_5b2 = 0x0;
    }
    goto .l54;
    if (decomp_var_5b2 == 0x0) {
            esi = decomp_var_594;
            edi = decomp_var_598;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x50] = 0x1;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi[0x9] = 0xff676980;
    }
    else {
            *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) = *(&decomp_var_5c8 + decomp_var_590 * 0x4 + 0x170) + 0x1;
    }
    sub_40f260();
    edi = decomp_var_594;
    ebp = decomp_var_590;
    esi = decomp_var_598;
    continue;

.l38:
    eax = sub_466060(&decomp_var_488, esi);
    eax = sub_466060(&decomp_var_498, 0x0);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    eax = sub_466060(&decomp_var_468, esi);
    eax = sub_466060(&decomp_var_478, 0x1);
    esp = esp - 0x2c;
    eax = sub_465900(&decomp_var_55e, 0x0);
    ebx = *(int16_t *)eax;
    sub_465fa0();
    sub_465fa0();
    if (edi == 0x0) {
            sub_47a948();
    }
    if (decomp_var_5ac == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_465d90(&decomp_var_570);
    if (eax != 0x0 && (*(int16_t *)word_4c6c1c == ebx || *(int16_t *)word_4c6c10 == ebx)) {
            decomp_var_5b2 = 0x0;
    }
    esi = esi + 0x1;
    if (esi < ebp) {
            continue;
    }
    break;
    ebx = decomp_var_5a4;
    sub_401590();
    edi = decomp_var_5b0;
    continue;
}
