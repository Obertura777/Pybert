// RESPOND @ 0x4216f0
// hopper name: sub_4216f0
// pybert name: RESPOND
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

RESPOND() {
    decomp_var_c = *0x0;
    decomp_var_cc = ebx;
    decomp_var_d0 = ebp;
    decomp_var_d4 = esi;
    decomp_var_d8 = edi;
    esp = esp - 0xdc;
    decomp_var_dc = *dword_4c8db8 ^ &decomp_var_d8;
    *0x0 = &decomp_var_c;
    esi = ecx;
    decomp_var_6c = esi;
    sub_465870();
    sub_465870();
    sub_465870();
    sub_465870();
    sub_465870();
    eax = sub_47020b();
    if (eax != 0x0) goto loc_4217a7;
    goto loc_42179d;

loc_4217a7:
    edi = 0x0;
    decomp_var_c0 = (*(*eax + 0xc))() + 0x10;
    decomp_var_c4 = *(int8_t *)(esi[0x2] + 0x2424) & 0xff;
    eax = sub_466060(&decomp_var_ac, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_4658f0(&decomp_var_8e);
    eax = sub_466060(&decomp_var_ac, 0x2);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466060(&decomp_var_ac, 0x3);
    sub_465ff0(eax);
    sub_465fa0();
    ebp = ebp | 0xffffffff;
    decomp_var_bc = ebp;
    eax = sub_465f30(&decomp_var_c8);
    esp = esp - 0x30;
    eax = sub_465ff0(&decomp_var_ac);
    sub_465fa0();
    ecx = *((decomp_var_c8 & 0xff) * 0x8 + 0xba27b0);
    eax = *((decomp_var_c8 & 0xff) * 0x8 + 0xba27b4);
    bool_3 = eax > 0x0;
    if (eax >= 0x0) {
            if (!bool_3) {
                    edi = 0x0;
                    if (ecx >= 0x0) {
                            decomp_var_bc = ecx;
                            ebp = eax;
                    }
            }
            else {
                    decomp_var_bc = ecx;
                    ebp = eax;
            }
    }
    eax = sub_465930();
    decomp_var_84 = eax;
    if (eax > 0x0) {
            esp = esp - 0x8;
            eax = sub_465900(&decomp_var_8e, edi);
            esi = *(int8_t *)eax & 0xff;
            if (esi != decomp_var_c4) {
                    eax = sub_465900(&decomp_var_8c, edi);
                    eax = sub_466480(&decomp_var_ac, eax);
                    esp = esp - 0x14;
                    sub_465ff0(eax);
                    sub_465fa0();
                    eax = *(esi * 0x8 + 0xba27b0);
                    esi = *(esi * 0x8 + 0xba27b4);
                    bool_461 = esi > 0x0;
                    if (esi >= 0x0) {
                            if (!bool_461) {
                                    if (eax >= 0x0) {
                                            bool_459 = esi > ebp;
                                            if (esi >= ebp) {
                                                    if (bool_459 || eax > decomp_var_bc) {
                                                            decomp_var_bc = eax;
                                                            ebp = esi;
                                                    }
                                            }
                                            edi = edi + 0x1;
                                            if (edi < decomp_var_84) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    else {
                                            edi = edi + 0x1;
                                            if (edi < decomp_var_84) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    bool_462 = esi > ebp;
                                    if (esi >= ebp) {
                                            if (bool_462 || eax > decomp_var_bc) {
                                                    decomp_var_bc = eax;
                                                    ebp = esi;
                                            }
                                    }
                                    edi = edi + 0x1;
                                    if (edi < decomp_var_84) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            edi = edi + 0x1;
                            if (edi < decomp_var_84) {
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    edi = edi + 0x1;
                    if (edi < decomp_var_84) {
                            continue;
                    }
                    break;
            }
    }
    if (*(int8_t *)byte_baed32 == 0x0) {
            ecx = sub_47b678();
            eax = (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4)) & 0x80000007;
            if (eax < 0x0) {
                    eax = (eax - 0x1 | 0xfffffff8) + 0x1;
            }
            edi = eax - *dword_ba2880;
            bool_30 = true;
            esi = (eax & 0x80000000 ? 0xffffffff : 0x0) - *dword_ba2884 + CARRY(EFLAGS(cf));
            esi = esi + arg_c + CARRY(EFLAGS(cf));
            edi = edi + arg_8 + 0x5;
            esi = esi + 0x0 + CARRY(EFLAGS(cf));
            bool_7 = esi < ebp;
            if (esi <= ebp) {
                    eax = decomp_var_bc;
                    if (bool_7 || edi < eax) {
                            edi = eax + 0x2;
                            esi = ebp + 0x0 + CARRY(EFLAGS(cf));
                    }
            }
            if (*dword_624ef4 > 0x0) {
                    eax = *dword_624ef4;
                    eax = eax - 0x14;
                    edx = eax & 0x80000000 ? 0xffffffff : 0x0;
                    bool_11 = esi > edx;
                    if (esi >= edx && (bool_11 || edi > eax)) {
                            edi = eax;
                            esi = edx;
                    }
            }
    }
    else {
            edi = arg_8 - *dword_ba2880;
            esi = arg_c - *dword_ba2884 + CARRY(EFLAGS(cf));
    }
    eax = arg_4;
    edx = edi + 0x2710;
    decomp_var_8c = edx;
    if (*(int16_t *)word_4c6cf0 != eax) goto loc_421a86;
    goto loc_421a61;

loc_42179d:
    eax = sub_40b5a0(0x80004005);
    return eax;

loc_421a86:
    if (*(int16_t *)word_4c6d28 != eax || decomp_var_84 != 0x1) goto loc_421d01;
    goto loc_421aa2;

loc_421a61:
    sub_40d4d0(arg_0);
    esp = esp - 0x8;
    sub_421570(decomp_var_c8 & 0xff);
    goto loc_421ebc;

loc_421d01:
    eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
    ebp = eax;
    sub_466f80(&decomp_var_bc, 0xbc1e0c);
    eax = sub_466c40(&decomp_var_7c, &decomp_var_2c);
    eax = sub_466c40(&decomp_var_ac, ebp);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    decomp_var_a8 = esi;
    eax = sub_465f60(&decomp_var_5c);
    eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
    sub_465fa0();
    esp = esp - 0x34;
    eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    ebx = 0x5;
    eax = sub_410c10(&decomp_var_c0, "Our response to a message was: %s", eax);
    esp = (esp - 0xc) + 0xc;
    if (decomp_var_94 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
    esp = (esp - 0x4) + 0x4 - 0x8;
    eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
    eax = esi - 0x10;
    edx = eax + 0xc;
    *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
    goto loc_421eb0;

loc_421aa2:
    edx = decomp_var_c8 & 0xff;
    if (*(edx * 0x8 + 0x4cf568) != 0x1 || *(edx * 0x8 + 0x4cf56c) != 0x0) goto loc_421d01;
    goto loc_421ac2;

loc_421ebc:
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_bc = 0xbb65c8;
    decomp_var_b8 = **dword_bb65cc;
    goto .l46;

loc_421eb0:
    if (!bool_25) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    goto loc_421ebc;

loc_421ac2:
    ecx = decomp_var_c4;
    eax = edx * 0x15 + ecx;
    bool_53 = *(eax * 0x8 + 0x4d552c) > 0x0;
    if (*(eax * 0x8 + 0x4d552c) < 0x0) goto .l9;
    goto loc_421ad7;

.l46:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_3c;
            esp = esp - 0x4;
            if (sub_465d90(edx) == 0x0) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_419 = esi != edi[0x1];
            ebx = esi + 0x30;
            decomp_var_68 = esi[0xd];
            if (!bool_419) {
                    sub_47a948();
            }
            edx = &decomp_var_8c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_68) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (*(int16_t *)word_4c6d48 == arg_4) {
                    edx = decomp_var_c8 & 0xff;
                    if (edx[0x633768] != 0x1) {
                            sub_40f860();
                            esi = decomp_var_b8;
                            edi = decomp_var_bc;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_411 = esi != edi[0x1];
                    ebx = esi + 0x48;
                    decomp_var_80 = esi[0x13];
                    if (!bool_411) {
                            sub_47a948();
                    }
                    edx = &decomp_var_7c;
                    esp = esp - 0x8;
                    eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_80) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_ac;
                            esp = esp - 0x8;
                            eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
                    }
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_415 = esi != edi[0x1];
            ebx = esi + 0x48;
            decomp_var_80 = esi[0x13];
            if (!bool_415) {
                    sub_47a948();
            }
            edx = &decomp_var_7c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_80) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_ac;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
            }
            sub_40f860();
            esi = decomp_var_b8;
            edi = decomp_var_bc;
            continue;
    }
    break;

.l9:
    ecx = sub_47b678();
    edx = (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4)) & 0x80000000 ? 0xffffffff : 0x0;
    if (((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x14 + *dword_4c6bd4 > 0x50) goto .l10;
    goto loc_421b20;

loc_421ad7:
    if (bool_53) goto loc_421ae3;
    goto loc_421ad9;
    eax = decomp_var_c0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;

.l10:
    eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
    ebp = eax;
    sub_466f80(&decomp_var_bc, 0xbc1e0c);
    eax = sub_466e10(&decomp_var_7c, &decomp_var_c8);
    eax = sub_466c40(&decomp_var_ac, ebp);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    decomp_var_a8 = esi;
    eax = sub_465f60(&decomp_var_5c);
    eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
    sub_465fa0();
    esp = esp - 0x34;
    *(int8_t *)((decomp_var_c8 & 0xff) + 0x633768) = 0x1;
    eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    eax = sub_410c10(&decomp_var_c0, "We are DECEITFULLY responding to: (%s)", eax);
    esp = (esp - 0xc) + 0xc;
    bool_42 = decomp_var_94 > 0x10;
    if (decomp_var_94 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
    esp = (esp - 0x4) + 0x4 - 0x8;
    eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
    eax = esi - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    edx = edx - 0x1;
    if (!bool_42) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_bc = 0xbb65c8;
    decomp_var_b8 = **dword_bb65cc;
    goto .l37;

loc_421b20:
    if (*(int8_t *)byte_baed68 != 0x1) goto .l14;
    goto loc_421b2d;

loc_421ae3:
    if (*((ecx * 0x15 + edx) * 0x4 + 0x634e90) >= 0x0) goto .l21;
    goto loc_421af2;

loc_421ad9:
    if (*(eax * 0x8 + 0x4d5528) <= 0x0) goto .l27;
    goto .l33;

.l37:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_3c;
            esp = esp - 0x4;
            if (sub_465d90(edx) == 0x0) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_200 = esi != edi[0x1];
            ebx = esi + 0x30;
            decomp_var_68 = esi[0xd];
            if (!bool_200) {
                    sub_47a948();
            }
            edx = &decomp_var_8c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_68) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (*(int16_t *)word_4c6d48 == arg_4) {
                    edx = decomp_var_c8 & 0xff;
                    if (edx[0x633768] != 0x1) {
                            sub_40f860();
                            esi = decomp_var_b8;
                            edi = decomp_var_bc;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_181 = esi != edi[0x1];
                    ebx = esi + 0x48;
                    decomp_var_80 = esi[0x13];
                    if (!bool_181) {
                            sub_47a948();
                    }
                    edx = &decomp_var_7c;
                    esp = esp - 0x8;
                    eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_80) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_ac;
                            esp = esp - 0x8;
                            eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
                    }
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_188 = esi != edi[0x1];
            ebx = esi + 0x48;
            decomp_var_80 = esi[0x13];
            if (!bool_188) {
                    sub_47a948();
            }
            edx = &decomp_var_7c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_80) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_ac;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
            }
            sub_40f860();
            esi = decomp_var_b8;
            edi = decomp_var_bc;
            continue;
    }
    break;

.l14:
    eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
    ebp = eax;
    sub_466f80(&decomp_var_bc, 0xbc1e0c);
    eax = sub_466c40(&decomp_var_7c, &decomp_var_2c);
    eax = sub_466c40(&decomp_var_ac, ebp);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    decomp_var_a8 = esi;
    eax = sub_465f60(&decomp_var_5c);
    eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
    sub_465fa0();
    esp = esp - 0x34;
    eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    eax = sub_410c10(&decomp_var_c0, "Our response to a message was: %s", eax);
    esp = (esp - 0xc) + 0xc;
    bool_38 = decomp_var_94 > 0x10;
    if (decomp_var_94 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
    esp = (esp - 0x4) + 0x4 - 0x8;
    eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
    eax = esi - 0x10;
    edx = eax + 0xc;
    *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
    if (!bool_38) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_bc = 0xbb65c8;
    decomp_var_b8 = **dword_bb65cc;
    goto .l35;

loc_421b2d:
    esp = esp - 0x4;
    if (sub_40d070(0x14) + *dword_4c6bd4 > 0x46) {
            eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
            ebp = eax;
            sub_466f80(&decomp_var_bc, 0xbc1e0c);
            eax = sub_466e10(&decomp_var_7c, &decomp_var_c8);
            eax = sub_466c40(&decomp_var_ac, ebp);
            sub_465ff0(eax);
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            decomp_var_a8 = esi;
            eax = sub_465f60(&decomp_var_5c);
            eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
            sub_465fa0();
            esp = esp - 0x34;
            *(int8_t *)((decomp_var_c8 & 0xff) + 0x633768) = 0x1;
            eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            ebx = 0x5;
            eax = sub_410c10(&decomp_var_c0, "We are DECEITFULLY responding to: (%s)", eax);
            esp = (esp - 0xc) + 0xc;
            bool_25 = decomp_var_94 > 0x10;
            if (decomp_var_94 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
            esp = (esp - 0x4) + 0x4 - 0x8;
            eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
            eax = esi - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            edx = edx - 0x1;
    }
    else {
            eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
            ebp = eax;
            sub_466f80(&decomp_var_bc, 0xbc1e0c);
            eax = sub_466c40(&decomp_var_7c, &decomp_var_2c);
            eax = sub_466c40(&decomp_var_ac, ebp);
            sub_465ff0(eax);
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            decomp_var_a8 = esi;
            eax = sub_465f60(&decomp_var_5c);
            eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
            sub_465fa0();
            esp = esp - 0x34;
            eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            ebx = 0x5;
            eax = sub_410c10(&decomp_var_c0, "Our response to a message was: %s", eax);
            esp = (esp - 0xc) + 0xc;
            if (decomp_var_94 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
            esp = (esp - 0x4) + 0x4 - 0x8;
            eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
            eax = esi - 0x10;
            edx = eax + 0xc;
            *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
    }
    goto loc_421eb0;

.l21:
    eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
    ebp = eax;
    sub_466f80(&decomp_var_bc, 0xbc1e0c);
    eax = sub_466e10(&decomp_var_7c, &decomp_var_c8);
    eax = sub_466c40(&decomp_var_ac, ebp);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    decomp_var_a8 = esi;
    eax = sub_465f60(&decomp_var_5c);
    eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
    sub_465fa0();
    esp = esp - 0x34;
    *(int8_t *)((decomp_var_c8 & 0xff) + 0x633768) = 0x1;
    eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    eax = sub_410c10(&decomp_var_c0, "We are DECEITFULLY responding to: (%s)", eax);
    esp = (esp - 0xc) + 0xc;
    bool_77 = decomp_var_94 > 0x10;
    if (decomp_var_94 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
    esp = (esp - 0x4) + 0x4 - 0x8;
    eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
    eax = esi - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    edx = edx - 0x1;
    if (!bool_77) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_bc = 0xbb65c8;
    decomp_var_b8 = **dword_bb65cc;
    goto .l40;

loc_421af2:
    ecx = sub_47b678();
    edx = (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4)) & 0x80000000 ? 0xffffffff : 0x0;
    if (((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x14 + *dword_4c6bd4 > 0x50) goto .l15;
    goto .l5;

.l27:
    ecx = sub_47b678();
    edx = (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4)) & 0x80000000 ? 0xffffffff : 0x0;
    if (((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x14 + *dword_4c6bd4 > 0x50) goto .l29;
    goto .l12;

.l33:
    if (*((ecx * 0x15 + edx) * 0x4 + 0x634e90) >= 0x0) goto .l19;
    goto .l34;
    eax = decomp_var_c0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;

.l35:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_3c;
            esp = esp - 0x4;
            if (sub_465d90(edx) == 0x0) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_132 = esi != edi[0x1];
            ebx = esi + 0x30;
            decomp_var_68 = esi[0xd];
            if (!bool_132) {
                    sub_47a948();
            }
            edx = &decomp_var_8c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_68) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (*(int16_t *)word_4c6d48 == arg_4) {
                    edx = decomp_var_c8 & 0xff;
                    if (edx[0x633768] != 0x1) {
                            sub_40f860();
                            esi = decomp_var_b8;
                            edi = decomp_var_bc;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_139 = esi != edi[0x1];
                    ebx = esi + 0x48;
                    decomp_var_80 = esi[0x13];
                    if (!bool_139) {
                            sub_47a948();
                    }
                    edx = &decomp_var_7c;
                    esp = esp - 0x8;
                    eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_80) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_ac;
                            esp = esp - 0x8;
                            eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
                    }
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_137 = esi != edi[0x1];
            ebx = esi + 0x48;
            decomp_var_80 = esi[0x13];
            if (!bool_137) {
                    sub_47a948();
            }
            edx = &decomp_var_7c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_80) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_ac;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
            }
            sub_40f860();
            esi = decomp_var_b8;
            edi = decomp_var_bc;
            continue;
    }
    break;

.l40:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_3c;
            esp = esp - 0x4;
            if (sub_465d90(edx) == 0x0) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_268 = esi != edi[0x1];
            ebx = esi + 0x30;
            decomp_var_68 = esi[0xd];
            if (!bool_268) {
                    sub_47a948();
            }
            edx = &decomp_var_8c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_68) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (*(int16_t *)word_4c6d48 == arg_4) {
                    edx = decomp_var_c8 & 0xff;
                    if (edx[0x633768] != 0x1) {
                            sub_40f860();
                            esi = decomp_var_b8;
                            edi = decomp_var_bc;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_256 = esi != edi[0x1];
                    ebx = esi + 0x48;
                    decomp_var_80 = esi[0x13];
                    if (!bool_256) {
                            sub_47a948();
                    }
                    edx = &decomp_var_7c;
                    esp = esp - 0x8;
                    eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_80) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_ac;
                            esp = esp - 0x8;
                            eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
                    }
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_271 = esi != edi[0x1];
            ebx = esi + 0x48;
            decomp_var_80 = esi[0x13];
            if (!bool_271) {
                    sub_47a948();
            }
            edx = &decomp_var_7c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_80) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_ac;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
            }
            sub_40f860();
            esi = decomp_var_b8;
            edi = decomp_var_bc;
            continue;
    }
    break;

.l15:
    eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
    ebp = eax;
    sub_466f80(&decomp_var_bc, 0xbc1e0c);
    eax = sub_466e10(&decomp_var_7c, &decomp_var_c8);
    eax = sub_466c40(&decomp_var_ac, ebp);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    decomp_var_a8 = esi;
    eax = sub_465f60(&decomp_var_5c);
    eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
    sub_465fa0();
    esp = esp - 0x34;
    *(int8_t *)((decomp_var_c8 & 0xff) + 0x633768) = 0x1;
    eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    eax = sub_410c10(&decomp_var_c0, "We are DECEITFULLY responding to: (%s)", eax);
    esp = (esp - 0xc) + 0xc;
    bool_65 = decomp_var_94 > 0x10;
    if (decomp_var_94 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
    esp = (esp - 0x4) + 0x4 - 0x8;
    eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
    eax = esi - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    edx = edx - 0x1;
    if (!bool_65) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_bc = 0xbb65c8;
    decomp_var_b8 = **dword_bb65cc;
    goto .l39;

.l5:
    if (*(int8_t *)byte_baed68 != 0x1) goto .l23;
    goto .l6;

.l29:
    eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
    ebp = eax;
    sub_466f80(&decomp_var_bc, 0xbc1e0c);
    eax = sub_466e10(&decomp_var_7c, &decomp_var_c8);
    eax = sub_466c40(&decomp_var_ac, ebp);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    decomp_var_a8 = esi;
    eax = sub_465f60(&decomp_var_5c);
    eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
    sub_465fa0();
    esp = esp - 0x34;
    *(int8_t *)((decomp_var_c8 & 0xff) + 0x633768) = 0x1;
    eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    eax = sub_410c10(&decomp_var_c0, "We are DECEITFULLY responding to: (%s)", eax);
    esp = (esp - 0xc) + 0xc;
    bool_94 = decomp_var_94 > 0x10;
    if (decomp_var_94 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
    esp = (esp - 0x4) + 0x4 - 0x8;
    eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
    eax = esi - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    edx = edx - 0x1;
    if (!bool_94) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_bc = 0xbb65c8;
    decomp_var_b8 = **dword_bb65cc;
    goto .l41;

.l12:
    if (*(int8_t *)byte_baed68 != 0x1) goto .l25;
    goto .l26;

.l19:
    eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
    ebp = eax;
    sub_466f80(&decomp_var_bc, 0xbc1e0c);
    eax = sub_466e10(&decomp_var_7c, &decomp_var_c8);
    eax = sub_466c40(&decomp_var_ac, ebp);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    decomp_var_a8 = esi;
    eax = sub_465f60(&decomp_var_5c);
    eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
    sub_465fa0();
    esp = esp - 0x34;
    *(int8_t *)((decomp_var_c8 & 0xff) + 0x633768) = 0x1;
    eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    eax = sub_410c10(&decomp_var_c0, "We are DECEITFULLY responding to: (%s)", eax);
    esp = (esp - 0xc) + 0xc;
    bool_73 = decomp_var_94 > 0x10;
    if (decomp_var_94 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
    esp = (esp - 0x4) + 0x4 - 0x8;
    eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
    eax = esi - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    edx = edx - 0x1;
    if (!bool_73) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_bc = 0xbb65c8;
    decomp_var_b8 = **dword_bb65cc;
    goto .l43;

.l34:
    ecx = sub_47b678();
    edx = (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4)) & 0x80000000 ? 0xffffffff : 0x0;
    if (((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x14 + *dword_4c6bd4 > 0x50) goto .l17;
    goto .l31;
    eax = decomp_var_c0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;
    eax = decomp_var_c0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;

.l39:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_3c;
            esp = esp - 0x4;
            if (sub_465d90(edx) == 0x0) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_233 = esi != edi[0x1];
            ebx = esi + 0x30;
            decomp_var_68 = esi[0xd];
            if (!bool_233) {
                    sub_47a948();
            }
            edx = &decomp_var_8c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_68) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (*(int16_t *)word_4c6d48 == arg_4) {
                    edx = decomp_var_c8 & 0xff;
                    if (edx[0x633768] != 0x1) {
                            sub_40f860();
                            esi = decomp_var_b8;
                            edi = decomp_var_bc;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_236 = esi != edi[0x1];
                    ebx = esi + 0x48;
                    decomp_var_80 = esi[0x13];
                    if (!bool_236) {
                            sub_47a948();
                    }
                    edx = &decomp_var_7c;
                    esp = esp - 0x8;
                    eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_80) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_ac;
                            esp = esp - 0x8;
                            eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
                    }
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_246 = esi != edi[0x1];
            ebx = esi + 0x48;
            decomp_var_80 = esi[0x13];
            if (!bool_246) {
                    sub_47a948();
            }
            edx = &decomp_var_7c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_80) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_ac;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
            }
            sub_40f860();
            esi = decomp_var_b8;
            edi = decomp_var_bc;
            continue;
    }
    break;

.l23:
    eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
    ebp = eax;
    sub_466f80(&decomp_var_bc, 0xbc1e0c);
    eax = sub_466c40(&decomp_var_7c, &decomp_var_2c);
    eax = sub_466c40(&decomp_var_ac, ebp);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    decomp_var_a8 = esi;
    eax = sub_465f60(&decomp_var_5c);
    eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
    sub_465fa0();
    esp = esp - 0x34;
    eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    eax = sub_410c10(&decomp_var_c0, "Our response to a message was: %s", eax);
    esp = (esp - 0xc) + 0xc;
    bool_81 = decomp_var_94 > 0x10;
    if (decomp_var_94 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
    esp = (esp - 0x4) + 0x4 - 0x8;
    eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
    eax = esi - 0x10;
    edx = eax + 0xc;
    *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
    if (!bool_81) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_bc = 0xbb65c8;
    decomp_var_b8 = **dword_bb65cc;
    goto .l45;

.l6:
    esp = esp - 0x4;
    if (sub_40d070(0x14) + *dword_4c6bd4 > 0x46) {
            eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
            ebp = eax;
            sub_466f80(&decomp_var_bc, 0xbc1e0c);
            eax = sub_466e10(&decomp_var_7c, &decomp_var_c8);
            eax = sub_466c40(&decomp_var_ac, ebp);
            sub_465ff0(eax);
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            decomp_var_a8 = esi;
            eax = sub_465f60(&decomp_var_5c);
            eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
            sub_465fa0();
            esp = esp - 0x34;
            *(int8_t *)((decomp_var_c8 & 0xff) + 0x633768) = 0x1;
            eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_c0, "We are DECEITFULLY responding to: (%s)", eax);
            esp = (esp - 0xc) + 0xc;
            bool_52 = decomp_var_94 > 0x10;
            if (decomp_var_94 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
            esp = (esp - 0x4) + 0x4 - 0x8;
            eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
            eax = esi - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            edx = edx - 0x1;
    }
    else {
            eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
            ebp = eax;
            sub_466f80(&decomp_var_bc, 0xbc1e0c);
            eax = sub_466c40(&decomp_var_7c, &decomp_var_2c);
            eax = sub_466c40(&decomp_var_ac, ebp);
            sub_465ff0(eax);
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            decomp_var_a8 = esi;
            eax = sub_465f60(&decomp_var_5c);
            eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
            sub_465fa0();
            esp = esp - 0x34;
            eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_c0, "Our response to a message was: %s", eax);
            esp = (esp - 0xc) + 0xc;
            if (decomp_var_94 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
            esp = (esp - 0x4) + 0x4 - 0x8;
            eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
            eax = esi - 0x10;
            edx = eax + 0xc;
            *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
    }
    if (!bool_52) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_bc = 0xbb65c8;
    decomp_var_b8 = **dword_bb65cc;
    goto .l47;

.l41:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_3c;
            esp = esp - 0x4;
            if (sub_465d90(edx) == 0x0) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_281 = esi != edi[0x1];
            ebx = esi + 0x30;
            decomp_var_68 = esi[0xd];
            if (!bool_281) {
                    sub_47a948();
            }
            edx = &decomp_var_8c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_68) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (*(int16_t *)word_4c6d48 == arg_4) {
                    edx = decomp_var_c8 & 0xff;
                    if (edx[0x633768] != 0x1) {
                            sub_40f860();
                            esi = decomp_var_b8;
                            edi = decomp_var_bc;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_287 = esi != edi[0x1];
                    ebx = esi + 0x48;
                    decomp_var_80 = esi[0x13];
                    if (!bool_287) {
                            sub_47a948();
                    }
                    edx = &decomp_var_7c;
                    esp = esp - 0x8;
                    eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_80) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_ac;
                            esp = esp - 0x8;
                            eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
                    }
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_282 = esi != edi[0x1];
            ebx = esi + 0x48;
            decomp_var_80 = esi[0x13];
            if (!bool_282) {
                    sub_47a948();
            }
            edx = &decomp_var_7c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_80) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_ac;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
            }
            sub_40f860();
            esi = decomp_var_b8;
            edi = decomp_var_bc;
            continue;
    }
    break;

.l25:
    eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
    ebp = eax;
    sub_466f80(&decomp_var_bc, 0xbc1e0c);
    eax = sub_466c40(&decomp_var_7c, &decomp_var_2c);
    eax = sub_466c40(&decomp_var_ac, ebp);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    decomp_var_a8 = esi;
    eax = sub_465f60(&decomp_var_5c);
    eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
    sub_465fa0();
    esp = esp - 0x34;
    eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    eax = sub_410c10(&decomp_var_c0, "Our response to a message was: %s", eax);
    esp = (esp - 0xc) + 0xc;
    bool_85 = decomp_var_94 > 0x10;
    if (decomp_var_94 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
    esp = (esp - 0x4) + 0x4 - 0x8;
    eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
    eax = esi - 0x10;
    edx = eax + 0xc;
    *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
    if (!bool_85) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_bc = 0xbb65c8;
    decomp_var_b8 = **dword_bb65cc;
    goto .l44;

.l26:
    esp = esp - 0x4;
    if (sub_40d070(0x14) + *dword_4c6bd4 > 0x46) {
            eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
            ebp = eax;
            sub_466f80(&decomp_var_bc, 0xbc1e0c);
            eax = sub_466e10(&decomp_var_7c, &decomp_var_c8);
            eax = sub_466c40(&decomp_var_ac, ebp);
            sub_465ff0(eax);
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            decomp_var_a8 = esi;
            eax = sub_465f60(&decomp_var_5c);
            eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
            sub_465fa0();
            esp = esp - 0x34;
            *(int8_t *)((decomp_var_c8 & 0xff) + 0x633768) = 0x1;
            eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_c0, "We are DECEITFULLY responding to: (%s)", eax);
            esp = (esp - 0xc) + 0xc;
            bool_90 = decomp_var_94 > 0x10;
            if (decomp_var_94 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
            esp = (esp - 0x4) + 0x4 - 0x8;
            eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
            eax = esi - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            edx = edx - 0x1;
    }
    else {
            eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
            ebp = eax;
            sub_466f80(&decomp_var_bc, 0xbc1e0c);
            eax = sub_466c40(&decomp_var_7c, &decomp_var_2c);
            eax = sub_466c40(&decomp_var_ac, ebp);
            sub_465ff0(eax);
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            decomp_var_a8 = esi;
            eax = sub_465f60(&decomp_var_5c);
            eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
            sub_465fa0();
            esp = esp - 0x34;
            eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_c0, "Our response to a message was: %s", eax);
            esp = (esp - 0xc) + 0xc;
            if (decomp_var_94 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
            esp = (esp - 0x4) + 0x4 - 0x8;
            eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
            eax = esi - 0x10;
            edx = eax + 0xc;
            *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
    }
    if (!bool_90) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_bc = 0xbb65c8;
    decomp_var_b8 = **dword_bb65cc;
    goto .l36;

.l43:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_3c;
            esp = esp - 0x4;
            if (sub_465d90(edx) == 0x0) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_339 = esi != edi[0x1];
            ebx = esi + 0x30;
            decomp_var_68 = esi[0xd];
            if (!bool_339) {
                    sub_47a948();
            }
            edx = &decomp_var_8c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_68) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (*(int16_t *)word_4c6d48 == arg_4) {
                    edx = decomp_var_c8 & 0xff;
                    if (edx[0x633768] != 0x1) {
                            sub_40f860();
                            esi = decomp_var_b8;
                            edi = decomp_var_bc;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_340 = esi != edi[0x1];
                    ebx = esi + 0x48;
                    decomp_var_80 = esi[0x13];
                    if (!bool_340) {
                            sub_47a948();
                    }
                    edx = &decomp_var_7c;
                    esp = esp - 0x8;
                    eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_80) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_ac;
                            esp = esp - 0x8;
                            eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
                    }
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_352 = esi != edi[0x1];
            ebx = esi + 0x48;
            decomp_var_80 = esi[0x13];
            if (!bool_352) {
                    sub_47a948();
            }
            edx = &decomp_var_7c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_80) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_ac;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
            }
            sub_40f860();
            esi = decomp_var_b8;
            edi = decomp_var_bc;
            continue;
    }
    break;

.l17:
    eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
    ebp = eax;
    sub_466f80(&decomp_var_bc, 0xbc1e0c);
    eax = sub_466e10(&decomp_var_7c, &decomp_var_c8);
    eax = sub_466c40(&decomp_var_ac, ebp);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    decomp_var_a8 = esi;
    eax = sub_465f60(&decomp_var_5c);
    eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
    sub_465fa0();
    esp = esp - 0x34;
    *(int8_t *)((decomp_var_c8 & 0xff) + 0x633768) = 0x1;
    eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    eax = sub_410c10(&decomp_var_c0, "We are DECEITFULLY responding to: (%s)", eax);
    esp = (esp - 0xc) + 0xc;
    bool_69 = decomp_var_94 > 0x10;
    if (decomp_var_94 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
    esp = (esp - 0x4) + 0x4 - 0x8;
    eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
    eax = esi - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    edx = edx - 0x1;
    if (!bool_69) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_bc = 0xbb65c8;
    decomp_var_b8 = **dword_bb65cc;
    goto loc_421ed1;

.l31:
    if (*(int8_t *)byte_baed68 != 0x1) goto .l8;
    goto .l32;
    eax = decomp_var_c0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;

.l45:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_3c;
            esp = esp - 0x4;
            if (sub_465d90(edx) == 0x0) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_391 = esi != edi[0x1];
            ebx = esi + 0x30;
            decomp_var_68 = esi[0xd];
            if (!bool_391) {
                    sub_47a948();
            }
            edx = &decomp_var_8c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_68) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (*(int16_t *)word_4c6d48 == arg_4) {
                    edx = decomp_var_c8 & 0xff;
                    if (edx[0x633768] != 0x1) {
                            sub_40f860();
                            esi = decomp_var_b8;
                            edi = decomp_var_bc;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_397 = esi != edi[0x1];
                    ebx = esi + 0x48;
                    decomp_var_80 = esi[0x13];
                    if (!bool_397) {
                            sub_47a948();
                    }
                    edx = &decomp_var_7c;
                    esp = esp - 0x8;
                    eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_80) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_ac;
                            esp = esp - 0x8;
                            eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
                    }
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_389 = esi != edi[0x1];
            ebx = esi + 0x48;
            decomp_var_80 = esi[0x13];
            if (!bool_389) {
                    sub_47a948();
            }
            edx = &decomp_var_7c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_80) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_ac;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
            }
            sub_40f860();
            esi = decomp_var_b8;
            edi = decomp_var_bc;
            continue;
    }
    break;

.l47:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_3c;
            esp = esp - 0x4;
            if (sub_465d90(edx) == 0x0) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_441 = esi != edi[0x1];
            ebx = esi + 0x30;
            decomp_var_68 = esi[0xd];
            if (!bool_441) {
                    sub_47a948();
            }
            edx = &decomp_var_8c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_68) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (*(int16_t *)word_4c6d48 == arg_4) {
                    edx = decomp_var_c8 & 0xff;
                    if (edx[0x633768] != 0x1) {
                            sub_40f860();
                            esi = decomp_var_b8;
                            edi = decomp_var_bc;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_444 = esi != edi[0x1];
                    ebx = esi + 0x48;
                    decomp_var_80 = esi[0x13];
                    if (!bool_444) {
                            sub_47a948();
                    }
                    edx = &decomp_var_7c;
                    esp = esp - 0x8;
                    eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_80) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_ac;
                            esp = esp - 0x8;
                            eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
                    }
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_451 = esi != edi[0x1];
            ebx = esi + 0x48;
            decomp_var_80 = esi[0x13];
            if (!bool_451) {
                    sub_47a948();
            }
            edx = &decomp_var_7c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_80) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_ac;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
            }
            sub_40f860();
            esi = decomp_var_b8;
            edi = decomp_var_bc;
            continue;
    }
    break;
    eax = decomp_var_c0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;

.l44:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_3c;
            esp = esp - 0x4;
            if (sub_465d90(edx) == 0x0) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_372 = esi != edi[0x1];
            ebx = esi + 0x30;
            decomp_var_68 = esi[0xd];
            if (!bool_372) {
                    sub_47a948();
            }
            edx = &decomp_var_8c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_68) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (*(int16_t *)word_4c6d48 == arg_4) {
                    edx = decomp_var_c8 & 0xff;
                    if (edx[0x633768] != 0x1) {
                            sub_40f860();
                            esi = decomp_var_b8;
                            edi = decomp_var_bc;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_370 = esi != edi[0x1];
                    ebx = esi + 0x48;
                    decomp_var_80 = esi[0x13];
                    if (!bool_370) {
                            sub_47a948();
                    }
                    edx = &decomp_var_7c;
                    esp = esp - 0x8;
                    eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_80) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_ac;
                            esp = esp - 0x8;
                            eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
                    }
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_358 = esi != edi[0x1];
            ebx = esi + 0x48;
            decomp_var_80 = esi[0x13];
            if (!bool_358) {
                    sub_47a948();
            }
            edx = &decomp_var_7c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_80) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_ac;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
            }
            sub_40f860();
            esi = decomp_var_b8;
            edi = decomp_var_bc;
            continue;
    }
    break;

.l36:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_3c;
            esp = esp - 0x4;
            if (sub_465d90(edx) == 0x0) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_170 = esi != edi[0x1];
            ebx = esi + 0x30;
            decomp_var_68 = esi[0xd];
            if (!bool_170) {
                    sub_47a948();
            }
            edx = &decomp_var_8c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_68) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (*(int16_t *)word_4c6d48 == arg_4) {
                    edx = decomp_var_c8 & 0xff;
                    if (edx[0x633768] != 0x1) {
                            sub_40f860();
                            esi = decomp_var_b8;
                            edi = decomp_var_bc;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_156 = esi != edi[0x1];
                    ebx = esi + 0x48;
                    decomp_var_80 = esi[0x13];
                    if (!bool_156) {
                            sub_47a948();
                    }
                    edx = &decomp_var_7c;
                    esp = esp - 0x8;
                    eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_80) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_ac;
                            esp = esp - 0x8;
                            eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
                    }
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_165 = esi != edi[0x1];
            ebx = esi + 0x48;
            decomp_var_80 = esi[0x13];
            if (!bool_165) {
                    sub_47a948();
            }
            edx = &decomp_var_7c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_80) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_ac;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
            }
            sub_40f860();
            esi = decomp_var_b8;
            edi = decomp_var_bc;
            continue;
    }
    break;
    eax = decomp_var_c0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;

loc_421ed1:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_3c;
            esp = esp - 0x4;
            if (sub_465d90(edx) == 0x0) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_118 = esi != edi[0x1];
            ebx = esi + 0x30;
            decomp_var_68 = esi[0xd];
            if (!bool_118) {
                    sub_47a948();
            }
            edx = &decomp_var_8c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_68) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (*(int16_t *)word_4c6d48 == arg_4) {
                    edx = decomp_var_c8 & 0xff;
                    if (edx[0x633768] != 0x1) {
                            sub_40f860();
                            esi = decomp_var_b8;
                            edi = decomp_var_bc;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_122 = esi != edi[0x1];
                    ebx = esi + 0x48;
                    decomp_var_80 = esi[0x13];
                    if (!bool_122) {
                            sub_47a948();
                    }
                    edx = &decomp_var_7c;
                    esp = esp - 0x8;
                    eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_80) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_ac;
                            esp = esp - 0x8;
                            eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
                    }
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_130 = esi != edi[0x1];
            ebx = esi + 0x48;
            decomp_var_80 = esi[0x13];
            if (!bool_130) {
                    sub_47a948();
            }
            edx = &decomp_var_7c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_80) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_ac;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
            }
            sub_40f860();
            esi = decomp_var_b8;
            edi = decomp_var_bc;
            continue;
    }
    break;

.l8:
    eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
    ebp = eax;
    sub_466f80(&decomp_var_bc, 0xbc1e0c);
    eax = sub_466c40(&decomp_var_7c, &decomp_var_2c);
    eax = sub_466c40(&decomp_var_ac, ebp);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    decomp_var_a8 = esi;
    eax = sub_465f60(&decomp_var_5c);
    eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
    sub_465fa0();
    esp = esp - 0x34;
    eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    eax = sub_410c10(&decomp_var_c0, "Our response to a message was: %s", eax);
    esp = (esp - 0xc) + 0xc;
    bool_57 = decomp_var_94 > 0x10;
    if (decomp_var_94 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
    esp = (esp - 0x4) + 0x4 - 0x8;
    eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
    eax = esi - 0x10;
    edx = eax + 0xc;
    *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
    if (!bool_57) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_bc = 0xbb65c8;
    decomp_var_b8 = **dword_bb65cc;
    goto .l42;

.l32:
    esp = esp - 0x4;
    if (sub_40d070(0x14) + *dword_4c6bd4 > 0x46) {
            eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
            ebp = eax;
            sub_466f80(&decomp_var_bc, 0xbc1e0c);
            eax = sub_466e10(&decomp_var_7c, &decomp_var_c8);
            eax = sub_466c40(&decomp_var_ac, ebp);
            sub_465ff0(eax);
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            decomp_var_a8 = esi;
            eax = sub_465f60(&decomp_var_5c);
            eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
            sub_465fa0();
            esp = esp - 0x34;
            *(int8_t *)((decomp_var_c8 & 0xff) + 0x633768) = 0x1;
            eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_c0, "We are DECEITFULLY responding to: (%s)", eax);
            esp = (esp - 0xc) + 0xc;
            bool_105 = decomp_var_94 > 0x10;
            if (decomp_var_94 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
            esp = (esp - 0x4) + 0x4 - 0x8;
            eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
            eax = esi - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            edx = edx - 0x1;
    }
    else {
            eax = sub_466f80(&decomp_var_6c, &decomp_var_3c);
            ebp = eax;
            sub_466f80(&decomp_var_bc, 0xbc1e0c);
            eax = sub_466c40(&decomp_var_7c, &decomp_var_2c);
            eax = sub_466c40(&decomp_var_ac, ebp);
            sub_465ff0(eax);
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            decomp_var_a8 = esi;
            eax = sub_465f60(&decomp_var_5c);
            eax = sub_419c30(&decomp_var_7c, &decomp_var_ac, decomp_var_dc);
            sub_465fa0();
            esp = esp - 0x34;
            eax = sub_46b050(&decomp_var_ac, decomp_var_dc, decomp_var_d8);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_c0, "Our response to a message was: %s", eax);
            esp = (esp - 0xc) + 0xc;
            if (decomp_var_94 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = sub_40bfa0(decomp_var_c0 - 0x10) + 0x10;
            esp = (esp - 0x4) + 0x4 - 0x8;
            eax = sub_419e60(&decomp_var_7c, &decomp_var_bc, decomp_var_dc);
            eax = esi - 0x10;
            edx = eax + 0xc;
            *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
    }
    if (!bool_105) {
            edx = **eax;
            esp = esp - 0x4;
            (edx[0x1])(eax);
    }
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_bc = 0xbb65c8;
    decomp_var_b8 = **dword_bb65cc;
    goto .l38;
    eax = decomp_var_c0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;
    eax = decomp_var_c0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;
    eax = decomp_var_c0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;
    eax = decomp_var_c0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;
    eax = decomp_var_c0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;

.l42:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_3c;
            esp = esp - 0x4;
            if (sub_465d90(edx) == 0x0) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_316 = esi != edi[0x1];
            ebx = esi + 0x30;
            decomp_var_68 = esi[0xd];
            if (!bool_316) {
                    sub_47a948();
            }
            edx = &decomp_var_8c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_68) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (*(int16_t *)word_4c6d48 == arg_4) {
                    edx = decomp_var_c8 & 0xff;
                    if (edx[0x633768] != 0x1) {
                            sub_40f860();
                            esi = decomp_var_b8;
                            edi = decomp_var_bc;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_310 = esi != edi[0x1];
                    ebx = esi + 0x48;
                    decomp_var_80 = esi[0x13];
                    if (!bool_310) {
                            sub_47a948();
                    }
                    edx = &decomp_var_7c;
                    esp = esp - 0x8;
                    eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_80) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_ac;
                            esp = esp - 0x8;
                            eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
                    }
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_319 = esi != edi[0x1];
            ebx = esi + 0x48;
            decomp_var_80 = esi[0x13];
            if (!bool_319) {
                    sub_47a948();
            }
            edx = &decomp_var_7c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_80) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_ac;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
            }
            sub_40f860();
            esi = decomp_var_b8;
            edi = decomp_var_bc;
            continue;
    }
    break;

.l38:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_3c;
            esp = esp - 0x4;
            if (sub_465d90(edx) == 0x0) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_219 = esi != edi[0x1];
            ebx = esi + 0x30;
            decomp_var_68 = esi[0xd];
            if (!bool_219) {
                    sub_47a948();
            }
            edx = &decomp_var_8c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_68) {
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (*(int16_t *)word_4c6d48 == arg_4) {
                    edx = decomp_var_c8 & 0xff;
                    if (edx[0x633768] != 0x1) {
                            sub_40f860();
                            esi = decomp_var_b8;
                            edi = decomp_var_bc;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_214 = esi != edi[0x1];
                    ebx = esi + 0x48;
                    decomp_var_80 = esi[0x13];
                    if (!bool_214) {
                            sub_47a948();
                    }
                    edx = &decomp_var_7c;
                    esp = esp - 0x8;
                    eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_80) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_ac;
                            esp = esp - 0x8;
                            eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
                    }
                    sub_40f860();
                    esi = decomp_var_b8;
                    edi = decomp_var_bc;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_208 = esi != edi[0x1];
            ebx = esi + 0x48;
            decomp_var_80 = esi[0x13];
            if (!bool_208) {
                    sub_47a948();
            }
            edx = &decomp_var_7c;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == decomp_var_80) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_ac;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &decomp_var_c4, decomp_var_dc);
            }
            sub_40f860();
            esi = decomp_var_b8;
            edi = decomp_var_bc;
            continue;
    }
    break;
    eax = decomp_var_c0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;
    eax = decomp_var_c0 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = decomp_var_c;
    return eax;
}
