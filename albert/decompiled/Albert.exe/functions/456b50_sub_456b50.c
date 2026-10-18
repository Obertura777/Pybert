// sub_456b50 @ 0x456b50
// hopper name: sub_456b50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_456b50() {
    &decomp_var_4 = &decomp_var_4 & 0xfffffff8;
    decomp_var_10 = *0x0;
    decomp_var_50 = ebx;
    decomp_var_5c = edi;
    decomp_var_60 = *dword_4c8db8 ^ &decomp_var_5c;
    *0x0 = &decomp_var_10;
    ebp = ecx;
    sub_465870();
    ecx = *dword_bbf60c;
    esi = arg_4[0x2424] & 0xff;
    sub_446630(ecx[0x1]);
    eax = *dword_bbf60c;
    eax[0x1] = eax;
    eax = *dword_bbf60c;
    *dword_bbf610 = 0x0;
    *eax = eax;
    eax = *dword_bbf60c;
    eax[0x2] = eax;
    esp = esp - 0x64;
    sub_411b00(*(*dword_baed98 + 0x4));
    eax = *dword_baed98;
    eax[0x1] = eax;
    eax = *dword_baed98;
    *dword_baed9c = 0x0;
    *eax = eax;
    eax = *dword_baed98;
    eax[0x2] = eax;
    *dword_baed34 = 0x0;
    *dword_baed48 = 0x0;
    *dword_baed4c = 0x0;
    *dword_baed50 = 0x0;
    sub_4340d0();
    sub_460be0(decomp_var_60, decomp_var_5c, decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48);
    eax = arg_4[0x1225] & 0xffff;
    if (*(int16_t *)word_4c6cc4 != eax) {
            if (*(int16_t *)word_4c6cc8 != eax) {
                    if (*(int16_t *)word_4c6ccc != eax) {
                            if (*(int16_t *)word_4c6cd0 != eax) {
                                    decomp_var_64 = arg_4d20;
                                    decomp_var_68 = arg_4d1c;
                                    decomp_var_6c = arg_4d18;
                                    esp = esp - 0x10;
                                    decomp_var_70 = arg_4d14;
                                    sub_447460(decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64);
                                    if (arg_4[0x92f] > arg_4[0x938]) {
                                            edx = arg_4e4c;
                                            decomp_var_74 = arg_4e50;
                                            decomp_var_78 = edx;
                                            esp = esp - 0xc;
                                            decomp_var_7c = &arg_4e54;
                                            sub_41cd70(decomp_var_7c, decomp_var_78, decomp_var_74);
                                    }
                                    else {
                                            edx = arg_4df4;
                                            decomp_var_74 = arg_4df8;
                                            decomp_var_78 = edx;
                                            esp = esp - 0xc;
                                            decomp_var_7c = &arg_4dfc;
                                            sub_41cd70(decomp_var_7c, decomp_var_78, decomp_var_74);
                                    }
                            }
                            else {
                                    decomp_var_64 = arg_4d30;
                                    decomp_var_68 = arg_4d2c;
                                    decomp_var_6c = arg_4d28;
                                    decomp_var_70 = arg_4d24;
                                    sub_447460(decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64);
                                    ecx = arg_4de8;
                                    decomp_var_74 = arg_4df0;
                                    edx = arg_4de4;
                                    esp = esp - 0x18;
                                    decomp_var_78 = arg_4dec;
                                    eax = &arg_4d94;
                                    decomp_var_7c = ecx;
                                    esp = esp - 0xc;
                                    sub_44a040(eax, edx, decomp_var_7c);
                            }
                    }
                    else {
                            decomp_var_64 = arg_4d30;
                            decomp_var_68 = arg_4d2c;
                            decomp_var_6c = arg_4d28;
                            decomp_var_70 = arg_4d24;
                            sub_447460(decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64);
                            ecx = arg_4de8;
                            decomp_var_74 = arg_4df0;
                            edx = arg_4de4;
                            esp = esp - 0x18;
                            decomp_var_78 = arg_4dec;
                            eax = &arg_4d94;
                            decomp_var_7c = ecx;
                            esp = esp - 0xc;
                            sub_44a040(eax, edx, decomp_var_7c);
                    }
            }
            else {
                    decomp_var_64 = arg_4d20;
                    decomp_var_68 = arg_4d1c;
                    decomp_var_6c = arg_4d18;
                    decomp_var_70 = arg_4d14;
                    sub_447460(decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64);
                    ecx = arg_4d88;
                    decomp_var_74 = arg_4d90;
                    edx = arg_4d84;
                    esp = esp - 0x18;
                    decomp_var_78 = arg_4d8c;
                    eax = &arg_4d34;
                    decomp_var_7c = ecx;
                    esp = esp - 0xc;
                    sub_44a040(eax, edx, decomp_var_7c);
            }
    }
    else {
            decomp_var_64 = arg_4d20;
            decomp_var_68 = arg_4d1c;
            decomp_var_6c = arg_4d18;
            decomp_var_70 = arg_4d14;
            sub_447460(decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64);
            ecx = arg_4d88;
            decomp_var_74 = arg_4d90;
            edx = arg_4d84;
            esp = esp - 0x18;
            decomp_var_78 = arg_4d8c;
            eax = &arg_4d34;
            decomp_var_7c = ecx;
            esp = esp - 0xc;
            sub_44a040(eax, edx, decomp_var_7c);
    }
    eax = sub_47b26f(0x0);
    esp = (esp - 0x4) + 0x4;
    eax = eax - *dword_ba2880;
    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
    bool_5 = *(esi * 0x4 + 0x62e460) == 0x0;
    *dword_ba2878 = eax;
    *dword_ba287c = edx;
    if (bool_5) goto loc_4573b8;
    goto loc_456d93;

loc_4573b8:
    eax = arg_4[0x1225] & 0xffff;
    if (*(int16_t *)word_4c6cc4 != eax) {
            if (*(int16_t *)word_4c6ccc == eax) {
                    *dword_62cc64 = *dword_4c6bbc;
                    sub_443ed0();
                    sub_465fa0();
                    *0x0 = decomp_var_2c;
                    &decomp_var_68 = decomp_var_70;
            }
            else {
                    edx = arg_4;
                    eax = edx[0x1225] & 0xffff;
                    if (*(int16_t *)word_4c6cc8 != eax) {
                            if (*(int16_t *)word_4c6cd0 != eax) {
                                    if (*(int16_t *)word_4c6cd4 == eax) {
                                            eax = edx;
                                            if (eax[0x92f] > eax[0x938]) {
                                                    esp = esp - 0x4;
                                                    sub_442040(eax[0x92f] - eax[0x938], decomp_var_7c);
                                            }
                                            else {
                                                    if (eax[0x92f] < eax[0x938]) {
                                                            esp = esp - 0x4;
                                                            sub_44bd40(eax[0x938] - eax[0x92f], decomp_var_7c);
                                                    }
                                            }
                                            if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                                    esi = *dword_baed34 * 0x7d0 + 0x1388;
                                                    ecx = sub_47b678();
                                                    esp = esp - 0x4;
                                                    Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                            }
                                            sub_45aa40();
                                            *dword_62cc64 = *dword_4c6bbc;
                                            *(int8_t *)byte_baed6d = 0x1;
                                            sub_443ed0();
                                            sub_465fa0();
                                            *0x0 = decomp_var_2c;
                                            &decomp_var_68 = decomp_var_70;
                                    }
                                    else {
                                            sub_443ed0();
                                            sub_465fa0();
                                            *0x0 = decomp_var_2c;
                                            &decomp_var_68 = decomp_var_70;
                                    }
                            }
                            else {
                                    sub_4418e0(decomp_var_7c, decomp_var_78, decomp_var_74);
                                    if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                            esi = (*dword_baed34 + 0x2) * 0x7d0;
                                            ecx = sub_47b678();
                                            esp = esp - 0x4;
                                            Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                    }
                                    sub_45aa40();
                                    *dword_62cc64 = *dword_4c6bbc;
                                    *(int8_t *)byte_baed6d = 0x1;
                                    sub_443ed0();
                                    sub_465fa0();
                                    *0x0 = decomp_var_2c;
                                    &decomp_var_68 = decomp_var_70;
                            }
                    }
                    else {
                            sub_4418e0(decomp_var_7c, decomp_var_78, decomp_var_74);
                            if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                    esi = (*dword_baed34 + 0x2) * 0x7d0;
                                    ecx = sub_47b678();
                                    esp = esp - 0x4;
                                    Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                            }
                            sub_45aa40();
                            *dword_62cc64 = *dword_4c6bbc;
                            *(int8_t *)byte_baed6d = 0x1;
                            sub_443ed0();
                            sub_465fa0();
                            *0x0 = decomp_var_2c;
                            &decomp_var_68 = decomp_var_70;
                    }
            }
    }
    else {
            *dword_62cc64 = *dword_4c6bbc;
            sub_443ed0();
            sub_465fa0();
            *0x0 = decomp_var_2c;
            &decomp_var_68 = decomp_var_70;
    }
    return;

loc_456d93:
    eax = arg_4[0x1225] & 0xffff;
    if (*(int16_t *)word_4c6cc4 == eax) goto .l2;
    goto loc_456da6;

.l2:
    ebx = 0x0;
    sub_43dfb0(decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64, decomp_var_60, decomp_var_5c);
    sub_43d910();
    edx = arg_4;
    edi = 0x0;
    if (edx[0x901] > 0x0) {
            esi = 0xbb6cfc;
            do {
                    eax = *esi;
                    *(edi * 0x4 + 0xb9fe88) = ebx;
                    esp = esp - 0x4;
                    sub_410cf0(eax[0x1]);
                    eax = *esi;
                    eax[0x1] = eax;
                    eax = *esi;
                    esi[0x1] = ebx;
                    *eax = eax;
                    eax = *esi;
                    eax[0x2] = eax;
                    edx = arg_4;
                    edi = edi + 0x1;
                    esi = esi + 0xc;
            } while (edi < edx[0x901]);
    }
    decomp_var_5c = 0xa;
    goto .l4;

loc_456da6:
    if (*(int16_t *)word_4c6ccc != eax) goto loc_4573af;
    goto loc_456db3;

.l4:
    if (arg_4[0x901] > 0x0) {
            sub_456e30(decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c, 0x62e460, decomp_var_64, decomp_var_60, decomp_var_5c, decomp_var_58);
    }
    decomp_var_5c = decomp_var_5c - 0x1;
    if (decomp_var_5c != 0x0) {
            continue;
    }
    ecx = *dword_bb65f0;
    *dword_62cc64 = 0x0;
    esi = *ecx;
    edi = 0xbb65ec;
    decomp_var_58 = 0xbb65ec;
    decomp_var_54 = esi;
    &decomp_var_7c = &decomp_var_7c;
    goto .l7;

loc_4573af:
    ebx = 0x0;
    if (*(esi * 0x4 + 0x62e460) == 0x0) {
            eax = arg_4[0x1225] & 0xffff;
            if (*(int16_t *)word_4c6cc4 != eax) {
                    if (*(int16_t *)word_4c6ccc == eax) {
                            *dword_62cc64 = *dword_4c6bbc;
                            sub_443ed0();
                            sub_465fa0();
                            *0x0 = decomp_var_2c;
                            &decomp_var_68 = decomp_var_70;
                    }
                    else {
                            edx = arg_4;
                            eax = edx[0x1225] & 0xffff;
                            if (*(int16_t *)word_4c6cc8 != eax) {
                                    if (*(int16_t *)word_4c6cd0 != eax) {
                                            if (*(int16_t *)word_4c6cd4 == eax) {
                                                    eax = edx;
                                                    if (eax[0x92f] > eax[0x938]) {
                                                            esp = esp - 0x4;
                                                            sub_442040(eax[0x92f] - eax[0x938], decomp_var_7c);
                                                    }
                                                    else {
                                                            if (eax[0x92f] < eax[0x938]) {
                                                                    esp = esp - 0x4;
                                                                    sub_44bd40(eax[0x938] - eax[0x92f], decomp_var_7c);
                                                            }
                                                    }
                                                    if (*dword_baed34 > ebx && *(int8_t *)byte_baed32 == 0x0) {
                                                            esi = *dword_baed34 * 0x7d0 + 0x1388;
                                                            ecx = sub_47b678();
                                                            esp = esp - 0x4;
                                                            Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                                    }
                                                    sub_45aa40();
                                                    *dword_62cc64 = *dword_4c6bbc;
                                                    *(int8_t *)byte_baed6d = 0x1;
                                                    sub_443ed0();
                                                    sub_465fa0();
                                                    *0x0 = decomp_var_2c;
                                                    &decomp_var_68 = decomp_var_70;
                                            }
                                            else {
                                                    sub_443ed0();
                                                    sub_465fa0();
                                                    *0x0 = decomp_var_2c;
                                                    &decomp_var_68 = decomp_var_70;
                                            }
                                    }
                                    else {
                                            sub_4418e0(decomp_var_7c, decomp_var_78, decomp_var_74);
                                            if (*dword_baed34 > ebx && *(int8_t *)byte_baed32 == 0x0) {
                                                    esi = (*dword_baed34 + 0x2) * 0x7d0;
                                                    ecx = sub_47b678();
                                                    esp = esp - 0x4;
                                                    Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                            }
                                            sub_45aa40();
                                            *dword_62cc64 = *dword_4c6bbc;
                                            *(int8_t *)byte_baed6d = 0x1;
                                            sub_443ed0();
                                            sub_465fa0();
                                            *0x0 = decomp_var_2c;
                                            &decomp_var_68 = decomp_var_70;
                                    }
                            }
                            else {
                                    sub_4418e0(decomp_var_7c, decomp_var_78, decomp_var_74);
                                    if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                            esi = (*dword_baed34 + 0x2) * 0x7d0;
                                            ecx = sub_47b678();
                                            esp = esp - 0x4;
                                            Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                    }
                                    sub_45aa40();
                                    *dword_62cc64 = *dword_4c6bbc;
                                    *(int8_t *)byte_baed6d = 0x1;
                                    sub_443ed0();
                                    sub_465fa0();
                                    *0x0 = decomp_var_2c;
                                    &decomp_var_68 = decomp_var_70;
                            }
                    }
            }
            else {
                    *dword_62cc64 = *dword_4c6bbc;
                    sub_443ed0();
                    sub_465fa0();
                    *0x0 = decomp_var_2c;
                    &decomp_var_68 = decomp_var_70;
            }
    }
    else {
            edx = arg_4;
            eax = edx[0x1225] & 0xffff;
            if (*(int16_t *)word_4c6cc8 != eax) {
                    if (*(int16_t *)word_4c6cd0 != eax) {
                            if (*(int16_t *)word_4c6cd4 == eax) {
                                    eax = edx;
                                    if (eax[0x92f] > eax[0x938]) {
                                            esp = esp - 0x4;
                                            sub_442040(eax[0x92f] - eax[0x938], decomp_var_7c);
                                    }
                                    else {
                                            if (eax[0x92f] < eax[0x938]) {
                                                    esp = esp - 0x4;
                                                    sub_44bd40(eax[0x938] - eax[0x92f], decomp_var_7c);
                                            }
                                    }
                                    if (*dword_baed34 > ebx && *(int8_t *)byte_baed32 == 0x0) {
                                            esi = *dword_baed34 * 0x7d0 + 0x1388;
                                            ecx = sub_47b678();
                                            esp = esp - 0x4;
                                            Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                    }
                                    sub_45aa40();
                                    *dword_62cc64 = *dword_4c6bbc;
                                    *(int8_t *)byte_baed6d = 0x1;
                                    sub_443ed0();
                                    sub_465fa0();
                                    *0x0 = decomp_var_2c;
                                    &decomp_var_68 = decomp_var_70;
                            }
                            else {
                                    sub_443ed0();
                                    sub_465fa0();
                                    *0x0 = decomp_var_2c;
                                    &decomp_var_68 = decomp_var_70;
                            }
                    }
                    else {
                            sub_4418e0(decomp_var_7c, decomp_var_78, decomp_var_74);
                            if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                    esi = (*dword_baed34 + 0x2) * 0x7d0;
                                    ecx = sub_47b678();
                                    esp = esp - 0x4;
                                    Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                            }
                            sub_45aa40();
                            *dword_62cc64 = *dword_4c6bbc;
                            *(int8_t *)byte_baed6d = 0x1;
                            sub_443ed0();
                            sub_465fa0();
                            *0x0 = decomp_var_2c;
                            &decomp_var_68 = decomp_var_70;
                    }
            }
            else {
                    sub_4418e0(decomp_var_7c, decomp_var_78, decomp_var_74);
                    if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                            esi = (*dword_baed34 + 0x2) * 0x7d0;
                            ecx = sub_47b678();
                            esp = esp - 0x4;
                            Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                    }
                    sub_45aa40();
                    *dword_62cc64 = *dword_4c6bbc;
                    *(int8_t *)byte_baed6d = 0x1;
                    sub_443ed0();
                    sub_465fa0();
                    *0x0 = decomp_var_2c;
                    &decomp_var_68 = decomp_var_70;
            }
    }
    return;

loc_456db3:
    ebx = 0x0;
    sub_43dfb0(decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64, decomp_var_60, decomp_var_5c);
    sub_43d910();
    edx = arg_4;
    edi = 0x0;
    if (edx[0x901] > 0x0) {
            esi = 0xbb6cfc;
            do {
                    eax = *esi;
                    *(edi * 0x4 + 0xb9fe88) = ebx;
                    esp = esp - 0x4;
                    sub_410cf0(eax[0x1]);
                    eax = *esi;
                    eax[0x1] = eax;
                    eax = *esi;
                    esi[0x1] = ebx;
                    *eax = eax;
                    eax = *esi;
                    eax[0x2] = eax;
                    edx = arg_4;
                    edi = edi + 0x1;
                    esi = esi + 0xc;
            } while (edi < edx[0x901]);
    }
    decomp_var_5c = 0xa;
    goto loc_456e12;

.l7:
    if (edi == 0x0 || edi != 0xbb65ec) {
            sub_47a948();
    }
    if (esi != *dword_bb65f0) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x8] = 0x0;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    ebx = *(esi[0xd] + 0x4);
                    edi = esi + 0x30;
                    ebp = ebx;
                    if (ebx[0x1d] == 0x0) {
                            sub_410cf0(arg_4);
                            ebp = *ebp;
                            sub_465fa0();
                            sub_47c8f9();
                            esp = (esp - 0x8) + 0x4;
                            ebx = ebp;
                            if (arg_19 == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    eax = edi[0x1];
                    ebx = decomp_var_58;
                    eax[0x1] = eax;
                    eax = edi[0x1];
                    edi[0x2] = 0x0;
                    *eax = eax;
                    edi = edi[0x1];
                    edi[0x2] = edi;
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    esi[0x7] = 0x0;
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    esi[0x18] = 0x0;
                    eax = sub_466f80(&decomp_var_50, 0xbc1e0c);
                    edi = eax;
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    sub_465ff0(edi);
                    sub_465fa0();
                    ebp = decomp_var_64;
                    edx = arg_4;
                    edi = 0x0;
                    if (edx[0x901] > 0x0) {
                            ebx = esi + 0x48;
                            do {
                                    if (esi == decomp_var_58[0x1]) {
                                            sub_47a948();
                                    }
                                    *ebx = 0x0;
                                    edi = edi + 0x1;
                                    ebx = ebx + 0x4;
                            } while (edi < arg_4[0x901]);
                            ebx = decomp_var_58;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    esi[0xb0] = 0x0;
                    sub_40f470();
                    esi = decomp_var_54;
                    edi = decomp_var_58;
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x7] == 0x1) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi[0x7] = 0xffffffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = *dword_4c6bbc;
                            esi[0x8] = *dword_4c6bbc;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi[0x18] = 0x1;
                            sub_40f470();
                            esi = decomp_var_54;
                            edi = decomp_var_58;
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x7] == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    if (esi[0x18] == 0x0) {
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            esi[0x8] = 0x0;
                                    }
                            }
                            sub_40f470();
                            esi = decomp_var_54;
                            edi = decomp_var_58;
                    }
            }
            continue;
    }
    break;

loc_456e12:
    if (arg_4[0x901] > 0x0) {
            sub_456e30(decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c, 0x62e460, decomp_var_64, decomp_var_60, decomp_var_5c, decomp_var_58);
    }
    decomp_var_5c = decomp_var_5c - 0x1;
    if (decomp_var_5c != 0x0) {
            continue;
    }
    ecx = *dword_bb65f0;
    *dword_62cc64 = 0x0;
    esi = *ecx;
    edi = 0xbb65ec;
    decomp_var_58 = 0xbb65ec;
    decomp_var_54 = esi;
    &decomp_var_7c = &decomp_var_7c;
    goto loc_456f90;
    eax = sub_47b26f(0x0);
    esp = (esp - 0x4) + 0x4;
    eax = eax - *dword_ba2880;
    bool_133 = true;
    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
    eax = eax - *dword_ba2878;
    edx = edx - *dword_ba287c + CARRY(EFLAGS(cf));
    *dword_ba2870 = eax;
    *dword_ba2874 = edx;
    *dword_62e4b4 = 0x0;
    *dword_62e45c = 0x0;
    *dword_62d34c = 0x0;
    *dword_b95368 = 0x0;
    *dword_b9536c = 0x0;
    *dword_b95370 = 0x0;
    *dword_b95374 = 0x0;
    *dword_b95378 = 0x0;
    *dword_b9537c = 0x0;
    *dword_b95380 = 0x0;
    *dword_b95384 = 0x0;
    *dword_b95388 = 0x0;
    *dword_b9538c = 0x0;
    *dword_b95390 = 0x0;
    *dword_b95394 = 0x0;
    *dword_b95398 = 0x0;
    *dword_b9539c = 0x0;
    *dword_b953a0 = 0x0;
    *dword_b953a4 = 0x0;
    *dword_b953a8 = 0x0;
    *dword_b953ac = 0x0;
    *dword_b953b0 = 0x0;
    *dword_b953b4 = 0x0;
    *dword_b953b8 = 0x0;
    *dword_b953bc = 0x0;
    *dword_b953c0 = 0x0;
    *dword_b953c4 = 0x0;
    *dword_b953c8 = 0x0;
    *dword_b953cc = 0x0;
    *dword_b953d0 = 0x0;
    *dword_b953d4 = 0x0;
    *dword_b953d8 = 0x0;
    *dword_b953dc = 0x0;
    *dword_b953e0 = 0x0;
    *dword_b953e4 = 0x0;
    *dword_b953e8 = 0x0;
    *dword_b953ec = 0x0;
    *dword_b953f0 = 0x0;
    *dword_b953f4 = 0x0;
    *dword_b953f8 = 0x0;
    *dword_b953fc = 0x0;
    *dword_b95400 = 0x0;
    *dword_b95404 = 0x0;
    *dword_b95408 = 0x0;
    *dword_b9540c = 0x0;
    *dword_b95410 = 0x0;
    *dword_b95414 = 0x0;
    *dword_b95418 = 0x0;
    *dword_b9541c = 0x0;
    *dword_b95420 = 0x0;
    *dword_b95424 = 0x0;
    *dword_b95428 = 0x0;
    *dword_b9542c = 0x0;
    *dword_b95430 = 0x0;
    *dword_b95434 = 0x0;
    *dword_b95438 = 0x0;
    *dword_b9543c = 0x0;
    *dword_b95440 = 0x0;
    *dword_b95444 = 0x0;
    *dword_b95448 = 0x0;
    *dword_b9544c = 0x0;
    *dword_b95450 = 0x0;
    *dword_b95454 = 0x0;
    *dword_b95458 = 0x0;
    *dword_b9545c = 0x0;
    *dword_b95460 = 0x0;
    *dword_b95464 = 0x0;
    *dword_b95468 = 0x0;
    *dword_b9546c = 0x0;
    *dword_b95470 = 0x0;
    *dword_b95474 = 0x0;
    *dword_b95478 = 0x0;
    *dword_b9547c = 0x0;
    *dword_b95480 = 0x0;
    *dword_b95484 = 0x0;
    *dword_b95488 = 0x0;
    *dword_b9548c = 0x0;
    *dword_b95490 = 0x0;
    *dword_b95494 = 0x0;
    *dword_b95498 = 0x0;
    *dword_b9549c = 0x0;
    *dword_b954a0 = 0x0;
    *dword_b954a4 = 0x0;
    *dword_b954a8 = 0x0;
    *dword_b954ac = 0x0;
    *dword_b954b0 = 0x0;
    *dword_b954b4 = 0x0;
    *dword_b954b8 = 0x0;
    *dword_b954bc = 0x0;
    *dword_b954c0 = 0x0;
    *dword_b954c4 = 0x0;
    *dword_b954c8 = 0x0;
    *dword_b954cc = 0x0;
    *(int8_t *)byte_baed46 = 0x1;
    *(int8_t *)byte_baed6d = 0x0;
    sub_457890();
    esi = decomp_var_60;
    temp_3 = 0x1;
    break;

loc_456f90:
    if (edi == 0x0 || edi != 0xbb65ec) {
            sub_47a948();
    }
    if (esi != *dword_bb65f0) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x8] = 0x0;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    ebx = *(esi[0xd] + 0x4);
                    edi = esi + 0x30;
                    ebp = ebx;
                    if (ebx[0x1d] == 0x0) {
                            sub_410cf0(arg_4);
                            ebp = *ebp;
                            sub_465fa0();
                            sub_47c8f9();
                            esp = (esp - 0x8) + 0x4;
                            ebx = ebp;
                            if (arg_19 == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    eax = edi[0x1];
                    ebx = decomp_var_58;
                    eax[0x1] = eax;
                    eax = edi[0x1];
                    edi[0x2] = 0x0;
                    *eax = eax;
                    edi = edi[0x1];
                    edi[0x2] = edi;
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    esi[0x7] = 0x0;
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    esi[0x18] = 0x0;
                    eax = sub_466f80(&decomp_var_50, 0xbc1e0c);
                    edi = eax;
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    sub_465ff0(edi);
                    sub_465fa0();
                    ebp = decomp_var_64;
                    edx = arg_4;
                    edi = 0x0;
                    if (edx[0x901] > 0x0) {
                            ebx = esi + 0x48;
                            do {
                                    if (esi == decomp_var_58[0x1]) {
                                            sub_47a948();
                                    }
                                    *ebx = 0x0;
                                    edi = edi + 0x1;
                                    ebx = ebx + 0x4;
                            } while (edi < arg_4[0x901]);
                            ebx = decomp_var_58;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    esi[0xb0] = 0x0;
                    sub_40f470();
                    esi = decomp_var_54;
                    edi = decomp_var_58;
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x7] == 0x1) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi[0x7] = 0xffffffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = *dword_4c6bbc;
                            esi[0x8] = *dword_4c6bbc;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi[0x18] = 0x1;
                            sub_40f470();
                            esi = decomp_var_54;
                            edi = decomp_var_58;
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x7] == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    if (esi[0x18] == 0x0) {
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            esi[0x8] = 0x0;
                                    }
                            }
                            sub_40f470();
                            esi = decomp_var_54;
                            edi = decomp_var_58;
                    }
            }
            continue;
    }
    break;
    if (temp_3 != 0x0) {
            if (*(esi * 0x4 + 0x62e460) == 0x0) {
                    eax = arg_4[0x1225] & 0xffff;
                    if (*(int16_t *)word_4c6cc4 != eax) {
                            if (*(int16_t *)word_4c6ccc == eax) {
                                    *dword_62cc64 = *dword_4c6bbc;
                                    sub_443ed0();
                                    sub_465fa0();
                                    *0x0 = decomp_var_2c;
                                    &decomp_var_68 = decomp_var_70;
                            }
                            else {
                                    edx = arg_4;
                                    eax = edx[0x1225] & 0xffff;
                                    if (*(int16_t *)word_4c6cc8 != eax) {
                                            if (*(int16_t *)word_4c6cd0 != eax) {
                                                    if (*(int16_t *)word_4c6cd4 == eax) {
                                                            eax = edx;
                                                            if (eax[0x92f] > eax[0x938]) {
                                                                    esp = esp - 0x4;
                                                                    sub_442040(eax[0x92f] - eax[0x938], decomp_var_7c);
                                                            }
                                                            else {
                                                                    if (eax[0x92f] < eax[0x938]) {
                                                                            esp = esp - 0x4;
                                                                            sub_44bd40(eax[0x938] - eax[0x92f], decomp_var_7c);
                                                                    }
                                                            }
                                                            if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                                                    esi = *dword_baed34 * 0x7d0 + 0x1388;
                                                                    ecx = sub_47b678();
                                                                    esp = esp - 0x4;
                                                                    Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                                            }
                                                            sub_45aa40();
                                                            *dword_62cc64 = *dword_4c6bbc;
                                                            *(int8_t *)byte_baed6d = 0x1;
                                                            sub_443ed0();
                                                            sub_465fa0();
                                                            *0x0 = decomp_var_2c;
                                                            &decomp_var_68 = decomp_var_70;
                                                    }
                                                    else {
                                                            sub_443ed0();
                                                            sub_465fa0();
                                                            *0x0 = decomp_var_2c;
                                                            &decomp_var_68 = decomp_var_70;
                                                    }
                                            }
                                            else {
                                                    sub_4418e0(decomp_var_7c, decomp_var_78, decomp_var_74);
                                                    if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                                            esi = (*dword_baed34 + 0x2) * 0x7d0;
                                                            ecx = sub_47b678();
                                                            esp = esp - 0x4;
                                                            Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                                    }
                                                    sub_45aa40();
                                                    *dword_62cc64 = *dword_4c6bbc;
                                                    *(int8_t *)byte_baed6d = 0x1;
                                                    sub_443ed0();
                                                    sub_465fa0();
                                                    *0x0 = decomp_var_2c;
                                                    &decomp_var_68 = decomp_var_70;
                                            }
                                    }
                                    else {
                                            sub_4418e0(decomp_var_7c, decomp_var_78, decomp_var_74);
                                            if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                                    esi = (*dword_baed34 + 0x2) * 0x7d0;
                                                    ecx = sub_47b678();
                                                    esp = esp - 0x4;
                                                    Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                            }
                                            sub_45aa40();
                                            *dword_62cc64 = *dword_4c6bbc;
                                            *(int8_t *)byte_baed6d = 0x1;
                                            sub_443ed0();
                                            sub_465fa0();
                                            *0x0 = decomp_var_2c;
                                            &decomp_var_68 = decomp_var_70;
                                    }
                            }
                    }
                    else {
                            *dword_62cc64 = *dword_4c6bbc;
                            sub_443ed0();
                            sub_465fa0();
                            *0x0 = decomp_var_2c;
                            &decomp_var_68 = decomp_var_70;
                    }
            }
            else {
                    edx = arg_4;
                    eax = edx[0x1225] & 0xffff;
                    if (*(int16_t *)word_4c6cc8 != eax) {
                            if (*(int16_t *)word_4c6cd0 != eax) {
                                    if (*(int16_t *)word_4c6cd4 == eax) {
                                            eax = edx;
                                            if (eax[0x92f] > eax[0x938]) {
                                                    esp = esp - 0x4;
                                                    sub_442040(eax[0x92f] - eax[0x938], decomp_var_7c);
                                            }
                                            else {
                                                    if (eax[0x92f] < eax[0x938]) {
                                                            esp = esp - 0x4;
                                                            sub_44bd40(eax[0x938] - eax[0x92f], decomp_var_7c);
                                                    }
                                            }
                                            if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                                    esi = *dword_baed34 * 0x7d0 + 0x1388;
                                                    ecx = sub_47b678();
                                                    esp = esp - 0x4;
                                                    Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                            }
                                            sub_45aa40();
                                            *dword_62cc64 = *dword_4c6bbc;
                                            *(int8_t *)byte_baed6d = 0x1;
                                            sub_443ed0();
                                            sub_465fa0();
                                            *0x0 = decomp_var_2c;
                                            &decomp_var_68 = decomp_var_70;
                                    }
                                    else {
                                            sub_443ed0();
                                            sub_465fa0();
                                            *0x0 = decomp_var_2c;
                                            &decomp_var_68 = decomp_var_70;
                                    }
                            }
                            else {
                                    sub_4418e0(decomp_var_7c, decomp_var_78, decomp_var_74);
                                    if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                            esi = (*dword_baed34 + 0x2) * 0x7d0;
                                            ecx = sub_47b678();
                                            esp = esp - 0x4;
                                            Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                    }
                                    sub_45aa40();
                                    *dword_62cc64 = *dword_4c6bbc;
                                    *(int8_t *)byte_baed6d = 0x1;
                                    sub_443ed0();
                                    sub_465fa0();
                                    *0x0 = decomp_var_2c;
                                    &decomp_var_68 = decomp_var_70;
                            }
                    }
                    else {
                            sub_4418e0(decomp_var_7c, decomp_var_78, decomp_var_74);
                            if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                    esi = (*dword_baed34 + 0x2) * 0x7d0;
                                    ecx = sub_47b678();
                                    esp = esp - 0x4;
                                    Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                            }
                            sub_45aa40();
                            *dword_62cc64 = *dword_4c6bbc;
                            *(int8_t *)byte_baed6d = 0x1;
                            sub_443ed0();
                            sub_465fa0();
                            *0x0 = decomp_var_2c;
                            &decomp_var_68 = decomp_var_70;
                    }
            }
    }
    return;
    eax = sub_47b26f(0x0);
    esp = (esp - 0x4) + 0x4;
    eax = eax - *dword_ba2880;
    bool_102 = true;
    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
    eax = eax - *dword_ba2878;
    edx = edx - *dword_ba287c + CARRY(EFLAGS(cf));
    *dword_ba2870 = eax;
    *dword_ba2874 = edx;
    *dword_62e4b4 = 0x0;
    *dword_62e45c = 0x0;
    *dword_62d34c = 0x0;
    *dword_b95368 = 0x0;
    *dword_b9536c = 0x0;
    *dword_b95370 = 0x0;
    *dword_b95374 = 0x0;
    *dword_b95378 = 0x0;
    *dword_b9537c = 0x0;
    *dword_b95380 = 0x0;
    *dword_b95384 = 0x0;
    *dword_b95388 = 0x0;
    *dword_b9538c = 0x0;
    *dword_b95390 = 0x0;
    *dword_b95394 = 0x0;
    *dword_b95398 = 0x0;
    *dword_b9539c = 0x0;
    *dword_b953a0 = 0x0;
    *dword_b953a4 = 0x0;
    *dword_b953a8 = 0x0;
    *dword_b953ac = 0x0;
    *dword_b953b0 = 0x0;
    *dword_b953b4 = 0x0;
    *dword_b953b8 = 0x0;
    *dword_b953bc = 0x0;
    *dword_b953c0 = 0x0;
    *dword_b953c4 = 0x0;
    *dword_b953c8 = 0x0;
    *dword_b953cc = 0x0;
    *dword_b953d0 = 0x0;
    *dword_b953d4 = 0x0;
    *dword_b953d8 = 0x0;
    *dword_b953dc = 0x0;
    *dword_b953e0 = 0x0;
    *dword_b953e4 = 0x0;
    *dword_b953e8 = 0x0;
    *dword_b953ec = 0x0;
    *dword_b953f0 = 0x0;
    *dword_b953f4 = 0x0;
    *dword_b953f8 = 0x0;
    *dword_b953fc = 0x0;
    *dword_b95400 = 0x0;
    *dword_b95404 = 0x0;
    *dword_b95408 = 0x0;
    *dword_b9540c = 0x0;
    *dword_b95410 = 0x0;
    *dword_b95414 = 0x0;
    *dword_b95418 = 0x0;
    *dword_b9541c = 0x0;
    *dword_b95420 = 0x0;
    *dword_b95424 = 0x0;
    *dword_b95428 = 0x0;
    *dword_b9542c = 0x0;
    *dword_b95430 = 0x0;
    *dword_b95434 = 0x0;
    *dword_b95438 = 0x0;
    *dword_b9543c = 0x0;
    *dword_b95440 = 0x0;
    *dword_b95444 = 0x0;
    *dword_b95448 = 0x0;
    *dword_b9544c = 0x0;
    *dword_b95450 = 0x0;
    *dword_b95454 = 0x0;
    *dword_b95458 = 0x0;
    *dword_b9545c = 0x0;
    *dword_b95460 = 0x0;
    *dword_b95464 = 0x0;
    *dword_b95468 = 0x0;
    *dword_b9546c = 0x0;
    *dword_b95470 = 0x0;
    *dword_b95474 = 0x0;
    *dword_b95478 = 0x0;
    *dword_b9547c = 0x0;
    *dword_b95480 = 0x0;
    *dword_b95484 = 0x0;
    *dword_b95488 = 0x0;
    *dword_b9548c = 0x0;
    *dword_b95490 = 0x0;
    *dword_b95494 = 0x0;
    *dword_b95498 = 0x0;
    *dword_b9549c = 0x0;
    *dword_b954a0 = 0x0;
    *dword_b954a4 = 0x0;
    *dword_b954a8 = 0x0;
    *dword_b954ac = 0x0;
    *dword_b954b0 = 0x0;
    *dword_b954b4 = 0x0;
    *dword_b954b8 = 0x0;
    *dword_b954bc = 0x0;
    *dword_b954c0 = 0x0;
    *dword_b954c4 = 0x0;
    *dword_b954c8 = 0x0;
    *dword_b954cc = 0x0;
    *(int8_t *)byte_baed46 = 0x1;
    *(int8_t *)byte_baed6d = 0x0;
    sub_457890();
    esi = decomp_var_60;
    temp_3 = 0x1;
    break;
    if (temp_3 != 0x0) {
            if (*(esi * 0x4 + 0x62e460) == 0x0) {
                    eax = arg_4[0x1225] & 0xffff;
                    if (*(int16_t *)word_4c6cc4 != eax) {
                            if (*(int16_t *)word_4c6ccc == eax) {
                                    *dword_62cc64 = *dword_4c6bbc;
                                    sub_443ed0();
                                    sub_465fa0();
                                    *0x0 = decomp_var_2c;
                                    &decomp_var_68 = decomp_var_70;
                            }
                            else {
                                    edx = arg_4;
                                    eax = edx[0x1225] & 0xffff;
                                    if (*(int16_t *)word_4c6cc8 != eax) {
                                            if (*(int16_t *)word_4c6cd0 != eax) {
                                                    if (*(int16_t *)word_4c6cd4 == eax) {
                                                            eax = edx;
                                                            if (eax[0x92f] > eax[0x938]) {
                                                                    esp = esp - 0x4;
                                                                    sub_442040(eax[0x92f] - eax[0x938], decomp_var_7c);
                                                            }
                                                            else {
                                                                    if (eax[0x92f] < eax[0x938]) {
                                                                            esp = esp - 0x4;
                                                                            sub_44bd40(eax[0x938] - eax[0x92f], decomp_var_7c);
                                                                    }
                                                            }
                                                            if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                                                    esi = *dword_baed34 * 0x7d0 + 0x1388;
                                                                    ecx = sub_47b678();
                                                                    esp = esp - 0x4;
                                                                    Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                                            }
                                                            sub_45aa40();
                                                            *dword_62cc64 = *dword_4c6bbc;
                                                            *(int8_t *)byte_baed6d = 0x1;
                                                            sub_443ed0();
                                                            sub_465fa0();
                                                            *0x0 = decomp_var_2c;
                                                            &decomp_var_68 = decomp_var_70;
                                                    }
                                                    else {
                                                            sub_443ed0();
                                                            sub_465fa0();
                                                            *0x0 = decomp_var_2c;
                                                            &decomp_var_68 = decomp_var_70;
                                                    }
                                            }
                                            else {
                                                    sub_4418e0(decomp_var_7c, decomp_var_78, decomp_var_74);
                                                    if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                                            esi = (*dword_baed34 + 0x2) * 0x7d0;
                                                            ecx = sub_47b678();
                                                            esp = esp - 0x4;
                                                            Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                                    }
                                                    sub_45aa40();
                                                    *dword_62cc64 = *dword_4c6bbc;
                                                    *(int8_t *)byte_baed6d = 0x1;
                                                    sub_443ed0();
                                                    sub_465fa0();
                                                    *0x0 = decomp_var_2c;
                                                    &decomp_var_68 = decomp_var_70;
                                            }
                                    }
                                    else {
                                            sub_4418e0(decomp_var_7c, decomp_var_78, decomp_var_74);
                                            if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                                    esi = (*dword_baed34 + 0x2) * 0x7d0;
                                                    ecx = sub_47b678();
                                                    esp = esp - 0x4;
                                                    Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                            }
                                            sub_45aa40();
                                            *dword_62cc64 = *dword_4c6bbc;
                                            *(int8_t *)byte_baed6d = 0x1;
                                            sub_443ed0();
                                            sub_465fa0();
                                            *0x0 = decomp_var_2c;
                                            &decomp_var_68 = decomp_var_70;
                                    }
                            }
                    }
                    else {
                            *dword_62cc64 = *dword_4c6bbc;
                            sub_443ed0();
                            sub_465fa0();
                            *0x0 = decomp_var_2c;
                            &decomp_var_68 = decomp_var_70;
                    }
            }
            else {
                    edx = arg_4;
                    eax = edx[0x1225] & 0xffff;
                    if (*(int16_t *)word_4c6cc8 != eax) {
                            if (*(int16_t *)word_4c6cd0 != eax) {
                                    if (*(int16_t *)word_4c6cd4 == eax) {
                                            eax = edx;
                                            if (eax[0x92f] > eax[0x938]) {
                                                    esp = esp - 0x4;
                                                    sub_442040(eax[0x92f] - eax[0x938], decomp_var_7c);
                                            }
                                            else {
                                                    if (eax[0x92f] < eax[0x938]) {
                                                            esp = esp - 0x4;
                                                            sub_44bd40(eax[0x938] - eax[0x92f], decomp_var_7c);
                                                    }
                                            }
                                            if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                                    esi = *dword_baed34 * 0x7d0 + 0x1388;
                                                    ecx = sub_47b678();
                                                    esp = esp - 0x4;
                                                    Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                            }
                                            sub_45aa40();
                                            *dword_62cc64 = *dword_4c6bbc;
                                            *(int8_t *)byte_baed6d = 0x1;
                                            sub_443ed0();
                                            sub_465fa0();
                                            *0x0 = decomp_var_2c;
                                            &decomp_var_68 = decomp_var_70;
                                    }
                                    else {
                                            sub_443ed0();
                                            sub_465fa0();
                                            *0x0 = decomp_var_2c;
                                            &decomp_var_68 = decomp_var_70;
                                    }
                            }
                            else {
                                    sub_4418e0(decomp_var_7c, decomp_var_78, decomp_var_74);
                                    if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                            esi = (*dword_baed34 + 0x2) * 0x7d0;
                                            ecx = sub_47b678();
                                            esp = esp - 0x4;
                                            Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                                    }
                                    sub_45aa40();
                                    *dword_62cc64 = *dword_4c6bbc;
                                    *(int8_t *)byte_baed6d = 0x1;
                                    sub_443ed0();
                                    sub_465fa0();
                                    *0x0 = decomp_var_2c;
                                    &decomp_var_68 = decomp_var_70;
                            }
                    }
                    else {
                            sub_4418e0(decomp_var_7c, decomp_var_78, decomp_var_74);
                            if (*dword_baed34 > 0x0 && *(int8_t *)byte_baed32 == 0x0) {
                                    esi = (*dword_baed34 + 0x2) * 0x7d0;
                                    ecx = sub_47b678();
                                    esp = esp - 0x4;
                                    Sleep(esi + ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x1770);
                            }
                            sub_45aa40();
                            *dword_62cc64 = *dword_4c6bbc;
                            *(int8_t *)byte_baed6d = 0x1;
                            sub_443ed0();
                            sub_465fa0();
                            *0x0 = decomp_var_2c;
                            &decomp_var_68 = decomp_var_70;
                    }
            }
    }
    return;
}
