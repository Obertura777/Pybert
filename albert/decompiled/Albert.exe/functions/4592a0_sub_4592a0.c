// sub_4592a0 @ 0x4592a0
// hopper name: sub_4592a0
// contains unmarked entry 0x459548 (GenerateAndSubmitOrders)
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4592a0() {
    var_C = *0x0;
    decomp_var_210 = ebx;
    var_214 = ebp;
    var_218 = esi;
    *0x0 = &var_C;
    esi = ecx;
    sub_465870();
    sub_465870();
    var_1FC = *(int8_t *)(esi[0x2] + 0x2424) & 0xff;
    sub_422960();
    eax = sub_47b26f(0x0);
    *dword_ba2884 = edx;
    edx = *dword_bb65c0;
    *dword_ba2880 = eax;
    sub_410cb0(edx[0x1]);
    eax = *dword_bb65c0;
    eax[0x1] = eax;
    eax = *dword_bb65c0;
    *dword_bb65c4 = 0x0;
    *eax = eax;
    eax = *dword_bb65c0;
    eax[0x2] = eax;
    sub_419ed0(*(*dword_bbf63c + 0x4));
    eax = *dword_bbf63c;
    eax[0x1] = eax;
    eax = *dword_bbf63c;
    *dword_bbf640 = 0x0;
    *eax = eax;
    eax = *dword_bbf63c;
    eax[0x2] = eax;
    *dword_62cc64 = 0x0;
    *dword_ba2858 = 0x0;
    *dword_ba285c = 0x0;
    sub_465ff0(arg_0);
    eax = sub_466060(&var_1F8, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466f80(&var_1F8, 0xbc1e0c);
    sub_465ff0(eax);
    sub_465fa0();
    edx = *dword_bb65cc;
    *(int8_t *)byte_baed46 = 0x0;
    sub_4303f0(edx[0x1]);
    eax = *dword_bb65cc;
    eax[0x1] = eax;
    eax = *dword_bb65cc;
    *dword_bb65d0 = 0x0;
    *eax = eax;
    eax = *dword_bb65cc;
    eax[0x2] = eax;
    sub_40faf0(*(*dword_bb6f20 + 0x4));
    eax = *dword_bb6f20;
    eax[0x1] = eax;
    eax = *dword_bb6f20;
    *dword_bb6f24 = 0x0;
    *eax = eax;
    eax = *dword_bb6f20;
    eax[0x2] = eax;
    sub_430500(*(*dword_bb65f0 + 0x4));
    eax = *dword_bb65f0;
    eax[0x1] = eax;
    eax = *dword_bb65f0;
    *dword_bb65f4 = 0x0;
    *eax = eax;
    eax = *dword_bb65f0;
    eax[0x2] = eax;
    esp = (esp - 0x224) + 0x4 - 0x34;
    sub_410cf0(*(*dword_bb6df8 + 0x4));
    eax = *dword_bb6df8;
    eax[0x1] = eax;
    eax = *dword_bb6df8;
    *dword_bb6dfc = 0x0;
    *eax = eax;
    eax = *dword_bb6df8;
    eax[0x2] = eax;
    esp = esp - 0x4;
    sub_401950(*(*dword_bb7140 + 0x4));
    eax = *dword_bb7140;
    eax[0x1] = eax;
    eax = *dword_bb7140;
    *dword_bb7144 = 0x0;
    *eax = eax;
    eax = *dword_bb7140;
    eax[0x2] = eax;
    *(int8_t *)byte_baed5e = 0x0;
    *(int8_t *)byte_baed47 = 0x0;
    eax = esi[0x2];
    if (eax[0x2449] == 0x0 && (eax[0x92f] > 0x0 || eax[0x938] > 0x0)) {
            sub_40e8e0();
    }
    if (*(int8_t *)byte_baed68 == 0x1) {
            *(int8_t *)byte_baed68 = 0x0;
    }
    if (*(int8_t *)byte_4c6bdc == 0x1) {
            *(int8_t *)byte_baed68 = 0x1;
            *(int8_t *)byte_4c6bdc = 0x0;
    }
    eax = esi[0x2];
    if (eax[0x2449] != 0x0) goto loc_45a02f;
    goto loc_459573;

loc_45a02f:
    sub_41cc50();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = saved_fp;
    return eax;

loc_459573:
    ebx = 0x0;
    ecx = eax[0x901];
    var_20C = 0x0;
    do {
            edx = 0x0;
            if (ecx > ebx) {
                    eax = var_20C;
                    do {
                            edi = **dword_bbf618;
                            eax[0x2efda4] = 0xbbf614;
                            eax[0x2efda5] = edi;
                            eax[0x2f0290] = 0xbbf614;
                            eax[0x2f0291] = edi;
                            ecx = esi[0x2];
                            ecx = ecx[0x901];
                            edx = edx + 0x1;
                            eax = eax + 0xf0;
                    } while (edx < ecx);
            }
            eax = var_20C + 0x8;
            var_20C = eax;
    } while (eax < 0xf0);
    ebx = 0x0;
    esp = esp - 0x4;
    sub_40df20(0x0);
    var_200 = 0x0;
    if (*(esi[0x2] + 0x2404) <= 0x0) goto loc_4599f7;
    goto loc_4595fa;

loc_4599f7:
    if (*(int16_t *)word_4c6cc4 == *(int16_t *)(esi[0x2] + 0x244a)) {
            *dword_baed64 = *dword_baed64 + 0x1;
    }
    ecx = *(int16_t *)word_4c6cc4;
    eax = esi[0x2];
    eax = eax[0x1225] & 0xffff;
    if (ecx == eax || *(int16_t *)word_4c6ccc == eax) {
            sub_4119d0();
    }
    if (*dword_baed64 == 0x1 && *(int8_t *)byte_baed68 == ebx && *(int16_t *)word_4c6ccc == *(int16_t *)(esi[0x2] + 0x244a)) {
            if (*(var_1F4 * 0x4 + dword_623990) != ebx) {
                    sub_435210();
            }
    }
    *(int8_t *)byte_baed6d = ebx;
    sub_4466e0();
    eax = *(int16_t *)(esi[0x2] + 0x244a) & 0xffff;
    if (*(int16_t *)word_4c6cc4 == eax || *(int16_t *)word_4c6ccc == eax) {
            sub_411120();
    }
    if (*(int8_t *)byte_baed68 == 0x1) {
            sub_4401f0();
    }
    if (*(var_1F4 * 0x4 + dword_623990) != ebx) {
            if (*(int8_t *)byte_baed33 == ebx) {
                    ebx = 0x0;
                    sub_40bba0();
                    var_1E0 = 0x0;
                    edi = sub_40bfa0(var_200 - 0x10) + 0x10;
                    esp = (esp - 0x8) + 0x4 - 0x8;
                    eax = sub_419e60(&var_1F4, &var_1E0, decomp_var_21c);
                    eax = edi - 0x10;
                    edx = eax + 0xc;
                    *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            edx = **eax;
                            esp = esp - 0x4;
                            (edx[0x1])(eax);
                    }
                    eax = var_200 - 0x10;
                    saved_fp = 0x2;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    if (edx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    if (*dword_baed64 <= 0x1) {
                            eax = *(int16_t *)(esi[0x2] + 0x244a) & 0xffff;
                            if (*(int16_t *)word_4c6cd0 != eax) {
                                    if (*(int16_t *)word_4c6cd4 != eax) {
                                            if (*dword_baed64 == 0x1 && *(int16_t *)word_4c6cc4 != eax) {
                                                    sub_42d0b0();
                                            }
                                    }
                                    else {
                                            sub_439ed0();
                                    }
                            }
                            else {
                                    sub_439ed0();
                            }
                    }
                    else {
                            sub_439ed0();
                    }
                    var_1DC = ebx;
                    if (*(esi[0x2] + 0x2404) > ebx) {
                            var_204 = ebx;
                            do {
                                    ebp = *(var_204[0x2ed9ff] + 0x4);
                                    edi = var_204 + 0xbb67f8;
                                    var_1FC = ebp;
                                    if (arg_11 == ebx) {
                                            &var_218 = &var_218;
                                            do {
                                                    sub_4019f0(arg_4);
                                                    ebp = *ebp;
                                                    sub_47c8f9();
                                                    esp = (esp - 0x8) + 0x4;
                                                    var_1FC = ebp;
                                            } while (arg_11 == ebx);
                                    }
                                    eax = edi[0x1];
                                    eax[0x1] = eax;
                                    eax = edi[0x1];
                                    edi[0x2] = ebx;
                                    *eax = eax;
                                    edi = edi[0x1];
                                    edi[0x2] = edi;
                                    ebp = *(var_204[0x2eda3f] + 0x4);
                                    edi = var_204 + 0xbb68f8;
                                    var_1FC = ebp;
                                    if (arg_15 == ebx) {
                                            sub_40fb70(arg_4);
                                            ebp = *ebp;
                                            sub_47c8f9();
                                            esp = (esp - 0x8) + 0x4;
                                            var_1FC = ebp;
                                            if (arg_15 == ebx) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    eax = edi[0x1];
                                    var_204 = var_204 + 0xc;
                                    eax[0x1] = eax;
                                    eax = edi[0x1];
                                    edi[0x2] = ebx;
                                    *eax = eax;
                                    edi = edi[0x1];
                                    edi[0x2] = edi;
                                    bool_85 = var_1DC + 0x1 < *(esi[0x2] + 0x2404);
                                    var_1DC = var_1DC + 0x1;
                            } while (bool_85);
                    }
                    sub_40df20(0x1);
                    sub_42db50();
                    esp = esp - 0x8;
                    sub_40df20(0x2);
                    sub_40d8c0(var_218);
                    eax = *(int16_t *)(esi[0x2] + 0x244a) & 0xffff;
                    if (*(int16_t *)word_4c6cc4 != eax) {
                            if (*(int16_t *)word_4c6ccc != eax) {
                                    if (*(int16_t *)word_4c6cd4 == eax) {
                                            sub_42ee90();
                                    }
                                    esp = esp - 0x4;
                                    sub_40df20(0x3);
                                    sub_40cdc0();
                                    sub_456b50();
                                    sub_41cc50();
                                    sub_465fa0();
                                    eax = sub_465fa0();
                                    *0x0 = saved_fp;
                            }
                            else {
                                    eax = var_19C;
                                    ebp = eax[0x1];
                                    edi = ebp;
                                    if (arg_19 == ebx) {
                                            do {
                                                    sub_410cf0(edi[0x2]);
                                                    edi = *edi;
                                                    sub_465fa0();
                                                    sub_47c8f9();
                                                    esp = (esp - 0x8) + 0x4;
                                                    ebp = edi;
                                            } while (edi[0x1d] == ebx);
                                            eax = var_19C;
                                    }
                                    eax[0x1] = eax;
                                    *var_19C = var_19C;
                                    var_19C[0x2] = var_19C;
                                    eax = var_190;
                                    edi = eax[0x1];
                                    ebp = edi;
                                    if (edi[0x1d] == ebx) {
                                            do {
                                                    sub_410cf0(arg_4);
                                                    ebp = *ebp;
                                                    sub_465fa0();
                                                    sub_47c8f9();
                                                    esp = (esp - 0x8) + 0x4;
                                                    edi = ebp;
                                            } while (arg_19 == ebx);
                                            eax = var_190;
                                    }
                                    eax[0x1] = eax;
                                    *var_190 = var_190;
                                    var_190[0x2] = var_190;
                                    eax = sub_466f80(&var_1EC, 0xbc1e0c);
                                    esp = esp - 0xc;
                                    sub_465ff0(eax);
                                    sub_465fa0();
                                    edx = esi[0x2];
                                    edi = 0x0;
                                    var_1F8 = 0x0;
                                    if (edx[0x901] > ebx) {
                                            esp = esp - 0x8;
                                            eax = sub_404ce0(&var_1EC, &var_1F8, var_214);
                                            edx = esi[0x2];
                                            *(&var_214 + edi * 0x4 + 0x8c) = ebx;
                                            edi = edi + 0x1;
                                            var_1F8 = edi;
                                            if (edi < edx[0x901]) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    sub_465f30(word_4c6d18);
                                    sub_465ff0(&var_1EC);
                                    sub_465fa0();
                                    sub_465f30(word_4c6d18);
                                    sub_465ff0(&var_1EC);
                                    sub_465fa0();
                                    sub_47b26f(ebx);
                                    var_D8 = ebx;
                                    eax = sub_4222a0(&var_1B8);
                                    eax = sub_430480(&var_1EC, &var_D8, var_214);
                                    sub_41cc50();
                                    sub_42ee90();
                                    esp = (esp - 0x14) + 0x4 - 0x10;
                                    sub_40df20(0x3);
                                    sub_44c9d0();
                                    if (*(int8_t *)byte_baed29 != 0x1) {
                                            if (*(int8_t *)byte_baed2a != 0x1) {
                                                    if (*(int8_t *)byte_baed2b != 0x1) {
                                                            if (*(int8_t *)byte_baed30 != 0x1) {
                                                                    sub_465870();
                                                                    eax = sub_466ed0(&var_1D8, word_4c6cdc);
                                                                    sub_465ff0(eax);
                                                                    sub_465fa0();
                                                                    esp = esp - 0x10;
                                                                    sub_45a9b0(&var_1EC);
                                                                    *(int8_t *)byte_baed5d = ebx;
                                                            }
                                                            else {
                                                                    sub_465870();
                                                                    sub_465f30(word_4c6cdc);
                                                                    sub_465ff0(&var_1D8);
                                                                    sub_465fa0();
                                                                    esp = esp - 0xc;
                                                                    sub_45a9b0(&var_1EC);
                                                                    *(int8_t *)byte_baed5d = 0x1;
                                                            }
                                                    }
                                                    else {
                                                            sub_465870();
                                                            sub_465f30(word_4c6cdc);
                                                            sub_465ff0(&var_1D8);
                                                            sub_465fa0();
                                                            esp = esp - 0xc;
                                                            sub_45a9b0(&var_1EC);
                                                            *(int8_t *)byte_baed5d = 0x1;
                                                    }
                                            }
                                            else {
                                                    sub_465870();
                                                    sub_465f30(word_4c6cdc);
                                                    sub_465ff0(&var_1D8);
                                                    sub_465fa0();
                                                    esp = esp - 0xc;
                                                    sub_45a9b0(&var_1EC);
                                                    *(int8_t *)byte_baed5d = 0x1;
                                            }
                                    }
                                    else {
                                            sub_465870();
                                            sub_465f30(word_4c6cdc);
                                            sub_465ff0(&var_1D8);
                                            sub_465fa0();
                                            esp = esp - 0xc;
                                            sub_45a9b0(&var_1EC);
                                            *(int8_t *)byte_baed5d = 0x1;
                                    }
                                    sub_465fa0();
                                    sub_40cdc0();
                                    sub_456b50();
                                    sub_41cc50();
                                    sub_465fa0();
                                    eax = sub_465fa0();
                                    *0x0 = saved_fp;
                            }
                    }
                    else {
                            ebx = 0x0;
                            eax = var_19C;
                            ebp = eax[0x1];
                            edi = ebp;
                            if (arg_19 == ebx) {
                                    do {
                                            sub_410cf0(edi[0x2]);
                                            edi = *edi;
                                            sub_465fa0();
                                            sub_47c8f9();
                                            esp = (esp - 0x8) + 0x4;
                                            ebp = edi;
                                    } while (edi[0x1d] == ebx);
                                    eax = var_19C;
                            }
                            ebx = 0x0;
                            eax[0x1] = eax;
                            *var_19C = var_19C;
                            var_19C[0x2] = var_19C;
                            eax = var_190;
                            edi = eax[0x1];
                            ebp = edi;
                            if (edi[0x1d] == 0x0) {
                                    do {
                                            sub_410cf0(arg_4);
                                            ebp = *ebp;
                                            sub_465fa0();
                                            sub_47c8f9();
                                            esp = (esp - 0x8) + 0x4;
                                            edi = ebp;
                                    } while (arg_19 == ebx);
                                    eax = var_190;
                            }
                            eax[0x1] = eax;
                            *var_190 = var_190;
                            var_190[0x2] = var_190;
                            eax = sub_466f80(&var_1EC, 0xbc1e0c);
                            esp = esp - 0xc;
                            sub_465ff0(eax);
                            sub_465fa0();
                            edx = esi[0x2];
                            edi = 0x0;
                            var_1F8 = 0x0;
                            if (edx[0x901] > ebx) {
                                    do {
                                            esp = esp - 0x8;
                                            eax = sub_404ce0(&var_1EC, &var_1F8, var_214);
                                            edx = esi[0x2];
                                            *(&var_214 + edi * 0x4 + 0x8c) = ebx;
                                            edi = edi + 0x1;
                                            var_1F8 = edi;
                                    } while (edi < edx[0x901]);
                            }
                            ebx = 0x0;
                            sub_465f30(word_4c6d18);
                            sub_465ff0(&var_1EC);
                            sub_465fa0();
                            sub_465f30(word_4c6d18);
                            sub_465ff0(&var_1EC);
                            sub_465fa0();
                            sub_47b26f(0x0);
                            var_D8 = 0x0;
                            eax = sub_4222a0(&var_1B8);
                            eax = sub_430480(&var_1EC, &var_D8, var_214);
                            sub_41cc50();
                            sub_42ee90();
                            esp = (esp - 0x14) + 0x4 - 0x10;
                            sub_40df20(0x3);
                            sub_44c9d0();
                            if (*(int8_t *)byte_baed29 != 0x1) {
                                    if (*(int8_t *)byte_baed2a != 0x1) {
                                            if (*(int8_t *)byte_baed2b != 0x1) {
                                                    if (*(int8_t *)byte_baed30 != 0x1) {
                                                            sub_465870();
                                                            eax = sub_466ed0(&var_1D8, word_4c6cdc);
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            esp = esp - 0x10;
                                                            sub_45a9b0(&var_1EC);
                                                            *(int8_t *)byte_baed5d = ebx;
                                                    }
                                                    else {
                                                            sub_465870();
                                                            sub_465f30(word_4c6cdc);
                                                            sub_465ff0(&var_1D8);
                                                            sub_465fa0();
                                                            esp = esp - 0xc;
                                                            sub_45a9b0(&var_1EC);
                                                            *(int8_t *)byte_baed5d = 0x1;
                                                    }
                                            }
                                            else {
                                                    sub_465870();
                                                    sub_465f30(word_4c6cdc);
                                                    sub_465ff0(&var_1D8);
                                                    sub_465fa0();
                                                    esp = esp - 0xc;
                                                    sub_45a9b0(&var_1EC);
                                                    *(int8_t *)byte_baed5d = 0x1;
                                            }
                                    }
                                    else {
                                            sub_465870();
                                            sub_465f30(word_4c6cdc);
                                            sub_465ff0(&var_1D8);
                                            sub_465fa0();
                                            esp = esp - 0xc;
                                            sub_45a9b0(&var_1EC);
                                            *(int8_t *)byte_baed5d = 0x1;
                                    }
                            }
                            else {
                                    sub_465870();
                                    sub_465f30(word_4c6cdc);
                                    sub_465ff0(&var_1D8);
                                    sub_465fa0();
                                    esp = esp - 0xc;
                                    sub_45a9b0(&var_1EC);
                                    *(int8_t *)byte_baed5d = 0x1;
                            }
                            sub_465fa0();
                            sub_40cdc0();
                            sub_456b50();
                            sub_41cc50();
                            sub_465fa0();
                            eax = sub_465fa0();
                            *0x0 = saved_fp;
                    }
            }
            else {
                    sub_40cdc0();
                    sub_456b50();
                    sub_41cc50();
                    sub_465fa0();
                    eax = sub_465fa0();
                    *0x0 = saved_fp;
            }
    }
    else {
            sub_40cdc0();
            sub_456b50();
            sub_41cc50();
            sub_465fa0();
            eax = sub_465fa0();
            *0x0 = saved_fp;
    }
    return eax;

loc_4595fa:
    var_204 = 0xbaeb70;
    var_1E4 = 0x4d5528;
    var_1E8 = 0xba2888;
    edi = 0x0;
    goto loc_459614;

loc_459614:
    *(var_200 * 0x4 + 0xb9fd80) = ebx;
    *(var_200 * 0x8 + 0x4d53d8) = ebx;
    *(var_200 * 0x8 + 0x4d53dc) = ebx;
    *(var_200 * 0x8 + 0xba27b0) = ebx;
    *(var_200 * 0x8 + 0xba27b4) = ebx;
    var_200[0x633768] = ebx;
    eax = edi[0x2ed97f];
    eax = eax[0x1];
    ebp = edi + 0xbb65f8;
    var_208 = eax;
    var_20C = eax;
    if (eax[0x1d] == ebx) {
            sub_410cf0(var_20C[0x2]);
            var_20C = *var_20C;
            sub_465fa0();
            sub_47c8f9();
            esp = (esp - 0x8) + 0x4;
            var_208 = var_20C;
            if (var_20C[0x1d] == ebx) {
                    continue;
            }
            break;
    }
    arg_0[0x1] = arg_0;
    *arg_0 = arg_0;
    eax = edi[0x2ed9bf];
    eax = eax[0x1];
    ebp = edi + 0xbb66f8;
    var_208 = eax;
    var_20C = eax;
    if (eax[0x1d] == ebx) {
            sub_410cf0(var_20C[0x2]);
            var_20C = *var_20C;
            sub_465fa0();
            sub_47c8f9();
            esp = (esp - 0x8) + 0x4;
            var_208 = var_20C;
            if (var_20C[0x1d] == ebx) {
                    continue;
            }
            break;
    }
    arg_0[0x1] = arg_0;
    *arg_0 = arg_0;
    eax = edi[0x2edaff];
    eax = eax[0x1];
    ebp = edi + 0xbb6bf8;
    var_208 = eax;
    var_20C = eax;
    if (eax[0x11] == ebx) {
            sub_401950(var_20C[0x2]);
            var_20C = *var_20C;
            sub_47c8f9();
            esp = (esp - 0x8) + 0x4;
            var_208 = var_20C;
            if (var_20C[0x11] == ebx) {
                    continue;
            }
            break;
    }
    arg_0[0x1] = arg_0;
    *arg_0 = arg_0;
    eax = edi[0x2eda7f];
    eax = eax[0x1];
    ebp = edi + 0xbb69f8;
    var_208 = eax;
    var_20C = eax;
    if (eax[0x15] == ebx) {
            sub_4019f0(var_20C[0x2]);
            var_20C = *var_20C;
            sub_47c8f9();
            esp = (esp - 0x8) + 0x4;
            var_208 = var_20C;
            if (var_20C[0x15] == ebx) {
                    continue;
            }
            break;
    }
    arg_0[0x1] = arg_0;
    *arg_0 = arg_0;
    eax = edi[0x2edabf];
    eax = eax[0x1];
    ebp = edi + 0xbb6af8;
    var_208 = eax;
    var_20C = eax;
    if (eax[0x11] == ebx) {
            sub_401950(var_20C[0x2]);
            var_20C = *var_20C;
            sub_47c8f9();
            esp = (esp - 0x8) + 0x4;
            var_208 = var_20C;
            if (var_20C[0x11] == ebx) {
                    continue;
            }
            break;
    }
    arg_0[0x1] = arg_0;
    *arg_0 = arg_0;
    arg_4 = arg_0;
    eax = 0x0;
    if (*(esi[0x2] + 0x2404) <= ebx) goto loc_4598ed;
    goto loc_459859;

loc_4598ed:
    edx = var_200;
    goto loc_4598f1;

loc_459859:
    ecx = var_1E8;
    var_208 = var_1E4;
    edx = var_200;
    var_20C = edx * 0x8 + 0x4d5528;
    goto loc_459874;

loc_4598f1:
    if (edx != var_1F4 && *(edx * 0x4 + dword_623990) == ebx) {
            eax = edi[0x2edbcb];
            eax = eax[0x1];
            ebp = edi + 0xbb6f28;
            var_200 = eax;
            var_204 = eax;
            if (eax[0x11] == ebx) {
                    sub_401950(var_204[0x2]);
                    var_204 = *var_204;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    var_200 = var_204;
                    if (var_204[0x11] == ebx) {
                            continue;
                    }
                    break;
            }
            arg_0[0x1] = arg_0;
            *arg_0 = arg_0;
            arg_4 = arg_0;
            ebp = *(edi[0x2edc0b] + 0x4);
            var_200 = ebp;
            if (arg_d == ebx) {
                    do {
                            sub_401950(arg_4);
                            ebp = *ebp;
                            sub_47c8f9();
                            esp = (esp - 0x8) + 0x4;
                            var_200 = ebp;
                    } while (arg_d == ebx);
            }
            eax = edi[0x2edc0b];
            edx = var_1F8;
            eax[0x1] = eax;
            eax = edi[0x2edc0b];
            edi[0x2edc0c] = ebx;
            *eax = eax;
            eax = edi[0x2edc0b];
            eax[0x2] = eax;
    }
    var_1E0 = var_1E0 + 0x54;
    var_1DC = var_1DC + 0xa8;
    var_1FC = var_1FC + 0x15;
    edi = edi + 0xc;
    var_1F8 = edx + 0x1;
    if (edx + 0x1 < *(esi[0x2] + 0x2404)) {
            continue;
    }
    break;

loc_459874:
    *(int8_t *)(eax + var_204) = ebx;
    if (edx != var_1FC) {
            if (*(edx * 0x4 + dword_623990) == ebx) {
                    *var_208 = ebx;
                    *var_20C = ebx;
                    arg_0 = ebx;
                    *ecx = ebx;
                    var_204 = var_204 + 0x8;
                    var_208 = var_208 + 0xa8;
                    eax = eax + 0x1;
                    ecx = ecx + 0x4;
                    if (eax < arg_2400) {
                            continue;
                    }
                    break;
            }
            else {
                    if (*ecx < ebx) {
                            edx = esi[0x2];
                            edx = edx[0x1225] & 0xffff;
                            if (*(int16_t *)word_4c6cc4 == edx || *(int16_t *)word_4c6ccc == edx) {
                                    *ecx = *ecx + 0x1;
                            }
                            edx = var_200;
                    }
                    var_204 = var_204 + 0x8;
                    var_208 = var_208 + 0xa8;
                    eax = eax + 0x1;
                    ecx = ecx + 0x4;
                    if (eax < arg_2400) {
                            continue;
                    }
                    break;
            }
    }
    else {
            if (*ecx < ebx) {
                    edx = esi[0x2];
                    edx = edx[0x1225] & 0xffff;
                    if (*(int16_t *)word_4c6cc4 == edx || *(int16_t *)word_4c6ccc == edx) {
                            *ecx = *ecx + 0x1;
                    }
                    edx = var_200;
            }
            var_204 = var_204 + 0x8;
            var_208 = var_208 + 0xa8;
            eax = eax + 0x1;
            ecx = ecx + 0x4;
            if (eax < arg_2400) {
                    continue;
            }
            break;
    }
    goto loc_4598f1;
}
