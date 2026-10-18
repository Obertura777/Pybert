// UpdateAllyOrderScore @ 0x442770
// hopper name: sub_442770
// pybert name: UpdateAllyOrderScore
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

UpdateAllyOrderScore() {
    &decomp_var_4 = &decomp_var_4 & 0xfffffff8;
    decomp_var_10 = *0x0;
    decomp_var_18 = *dword_4c8db8 ^ &decomp_var_b58;
    decomp_var_b5c = ebx;
    decomp_var_b60 = esi;
    decomp_var_b64 = edi;
    esp = esp - 0xb64;
    decomp_var_b68 = *dword_4c8db8 ^ &decomp_var_b64;
    *0x0 = &decomp_var_10;
    esi = ecx;
    decomp_var_b4c = esi;
    eax = sub_4103b0();
    decomp_var_b0c = eax;
    eax[0x21] = 0x1;
    decomp_var_b0c[0x1] = decomp_var_b0c;
    *decomp_var_b0c = decomp_var_b0c;
    decomp_var_b0c[0x2] = decomp_var_b0c;
    sub_465870();
    decomp_var_220 = 0xf;
    decomp_var_234 = 0x0;
    sub_465870();
    if (*dword_62cc64 < 0x8) {
            decomp_var_b04 = *dword_62cc64 + 0x4;
    }
    else {
            decomp_var_b04 = 0x1e;
    }
    sub_47bba4();
    esp = esp - 0x1c;
    sub_45ff80(0x0, 0x0);
    edi = 0xbbf608;
    decomp_var_b18 = 0xbbf608;
    decomp_var_b14 = **dword_bbf60c;
    &decomp_var_b68 = &decomp_var_b68;
    goto loc_442890;

loc_442890:
    ebx = 0x0;
    decomp_var_ac8 = *dword_bbf60c;
    if (edi == 0x0 || edi != 0xbbf608) {
            sub_47a948();
    }
    eax = decomp_var_b14;
    if (eax == decomp_var_ac8) goto loc_443dc0;
    goto loc_4428bf;

loc_443dc0:
    sub_424850(arg_4, 0x1, decomp_var_b68, decomp_var_b64, decomp_var_b60, decomp_var_b5c, decomp_var_b58, decomp_var_b54, decomp_var_b50, decomp_var_b4c, decomp_var_b48, decomp_var_b44, decomp_var_b40, decomp_var_b3c, decomp_var_b38, decomp_var_b34, decomp_var_b30, decomp_var_b2c, decomp_var_b28, decomp_var_b24);
    esp = esp - 0x18;
    sub_47b6f8();
    sub_465fa0();
    if (decomp_var_220 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
            temp_3 = 0x1;
    }
    else {
            temp_3 = 0x1;
    }
    break;

loc_4428bf:
    if (edi == 0x0) {
            sub_47a948();
            eax = decomp_var_b14;
    }
    if (eax == edi[0x1]) {
            sub_47a948();
            eax = decomp_var_b14;
    }
    if (eax[0x7] != arg_4) {
            sub_40f260();
            edi = decomp_var_b18;
            continue;
    }
    if (eax == edi[0x1]) {
            sub_47a948();
            eax = decomp_var_b14;
    }
    if (eax[0x50] != 0x0) {
            sub_40f260();
            edi = decomp_var_b18;
            continue;
    }
    eax = 0xbaed7c;
    decomp_var_b24 = 0xbaed7c;
    decomp_var_b20 = **dword_baed80;
    goto loc_442913;
    if (temp_3 != 0x0) {
            sub_465fa0();
            sub_4150e0(&decomp_var_ab4, &decomp_var_b10, *decomp_var_b0c, &decomp_var_b10, decomp_var_b0c);
            sub_47c8f9();
            *0x0 = decomp_var_10;
            sub_47ad69();
            &decomp_var_b58 = ebp;
    }
    return;

loc_442913:
    if (eax == 0x0 || eax != 0xbaed7c) {
            sub_47a948();
    }
    edi = *dword_baed80;
    eax = esi[0x2];
    if (decomp_var_b20 != edi) {
            ebx = 0x0;
            if (eax[0x901] <= 0x0) {
                    sub_40f380();
                    eax = decomp_var_b24;
                    continue;
            }
            edi = decomp_var_b20 + 0x68;
            do {
                    if (decomp_var_b24 == 0x0) {
                            sub_47a948();
                    }
                    if (decomp_var_b20 == decomp_var_b24[0x1]) {
                            sub_47a948();
                    }
                    *edi = 0x0;
                    ebx = ebx + 0x1;
                    edi = edi + 0x4;
            } while (ebx < *(esi[0x2] + 0x2404));
            sub_40f380();
            eax = decomp_var_b24;
            continue;
    }
    break;
    edi = 0x0;
    if (eax[0x900] > 0x0) {
            ecx = eax[0x901];
            do {
                    ebx = 0x0;
                    edx = 0x0;
                    if (ecx > 0x0) {
                            eax = edi * 0x4;
                            do {
                                    eax[0x2e6a60] = ebx;
                                    eax[0x2e5560] = ebx;
                                    ecx = esi[0x2];
                                    ecx = ecx[0x901];
                                    edx = edx + 0x1;
                                    eax = eax + 0x400;
                            } while (edx < ecx);
                    }
                    edi = edi + 0x1;
            } while (edi < *(esi[0x2] + 0x2400));
    }
    eax = 0x0;
    if (*(esi[0x2] + 0x2404) > 0x0) {
            &decomp_var_b68 = &decomp_var_b68;
            do {
                    *(eax * 0x4 + 0xb9fe30) = 0x0;
                    eax = eax + 0x1;
            } while (eax < *(esi[0x2] + 0x2404));
    }
    edi = *(*dword_bbf660 + 0x4);
    ebx = edi;
    if (edi[0x19] == 0x0) {
            sub_40fb70(ebx[0x2]);
            ebx = *ebx;
            sub_47c8f9();
            esp = (esp - 0x8) + 0x4;
            edi = ebx;
            if (ebx[0x19] == 0x0) {
                    continue;
            }
            break;
    }
    eax = *dword_bbf660;
    eax[0x1] = eax;
    eax = *dword_bbf660;
    *dword_bbf664 = 0x0;
    *eax = eax;
    eax = *dword_bbf660;
    eax[0x2] = eax;
    decomp_var_b50 = 0x0;
    if (decomp_var_b04 <= 0x0) goto loc_442b77;
    goto loc_442a63;

loc_442b77:
    ecx = *dword_bbf660;
    *dword_62e4b4 = *dword_62e4b4 + decomp_var_b04;
    ebx = 0xbbf65c;
    edi = *ecx;
    decomp_var_b3c = 0xbbf65c;
    decomp_var_b38 = edi;
    goto loc_442ba0;

loc_442a63:
    sub_442a70(decomp_var_b68, decomp_var_b64, decomp_var_b60, decomp_var_b5c, decomp_var_b58, decomp_var_b54, decomp_var_b50, decomp_var_b4c, decomp_var_b48, decomp_var_b44);
    temp_3 = 0x0;
    break;

loc_442ba0:
    if (ebx == 0x0 || ebx != 0xbbf65c) {
            sub_47a948();
    }
    if (edi == *dword_bbf660) goto .l107;
    goto loc_442bbf;

.l107:
    temp_2 = 0x1;
    break;

loc_442bbf:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    *dword_62e45c = *dword_62e45c + (edi[0x4] - 0x1);
    edx = decomp_var_b4c[0x2];
    ecx = edx[0x900];
    eax = 0x0;
    if (ecx > 0x0) {
            &decomp_var_b68 = &decomp_var_b68;
            do {
                    *(&decomp_var_b68 + eax * 0x4 + 0x12c) = 0x0;
                    *(&decomp_var_b68 + eax * 0x4 + 0x52c) = 0x0;
                    eax = eax + 0x1;
            } while (eax < ecx);
    }
    decomp_var_b50 = 0x0;
    if (edx[0x901] <= 0x0) goto .l5;
    goto loc_442c25;
    if (temp_2 == 0x0) goto .l142;
    goto loc_44392b;

.l5:
    if (decomp_var_b14 == decomp_var_b18[0x1]) {
            sub_47a948();
    }
    esi = *decomp_var_b14[0x188];
    edi = decomp_var_b14 + 0x61c;
    ebx = edi;
    decomp_var_b50 = edi;
    decomp_var_b34 = ebx;
    decomp_var_b30 = esi;
    goto .l9;

loc_442c25:
    decomp_var_b40 = 0x0;
    goto loc_442c29;

.l142:
    temp_3 = 0x0;
    break;

loc_44392b:
    esi = **dword_baed80;
    eax = 0xbaed7c;
    decomp_var_b24 = 0xbaed7c;
    decomp_var_b20 = **dword_baed80;
    goto loc_443942;

.l9:
    if (decomp_var_b14 == decomp_var_b18[0x1]) {
            sub_47a948();
    }
    decomp_var_a90 = edi[0x1];
    if (ebx == 0x0 || ebx != edi) {
            sub_47a948();
    }
    if (esi != decomp_var_a90) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            decomp_var_b54 = esi + 0xc;
            esp = esp - 0x8;
            eax = sub_402060(&decomp_var_ab4, esi + 0xc, decomp_var_b68, decomp_var_b64, decomp_var_b60);
            bool_188 = esi != ebx[0x1];
            edx = *eax;
            edi = eax[0x1];
            decomp_var_b48 = edx;
            if (!bool_188) {
                    sub_47a948();
            }
            if (decomp_var_b48 == 0x0) {
                    sub_47a948();
            }
            if (edi == decomp_var_b48[0x1]) {
                    sub_47a948();
            }
            edi[0x8] = decomp_var_b54[0x1];
            if (edi == decomp_var_b48[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x8];
            eax = eax - 0x2;
            if (eax > 0x4) {
                    sub_40e310();
                    esi = decomp_var_b30;
                    ebx = decomp_var_b34;
                    edi = decomp_var_b50;
                    continue;
            }
            if (*(eax * 0x4 + switch_table) != 0x0) {
                    if (*(eax * 0x4 + switch_table) != 0x1) {
                            if (*(eax * 0x4 + switch_table) != 0x2) {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (edi == decomp_var_b48[0x1]) {
                                            sub_47a948();
                                    }
                                    edi[0x9] = decomp_var_b54[0x2];
                                    edi[0xa] = decomp_var_b54[0x3];
                                    if (edi == decomp_var_b48[0x1]) {
                                            sub_47a948();
                                    }
                                    ecx = edi[0xe];
                                    eax = *ecx;
                                    esi = edi + 0x34;
                                    *ecx = ecx;
                                    ecx = esi[0x1];
                                    ecx[0x1] = ecx;
                                    bool_185 = eax == esi[0x1];
                                    esi[0x2] = 0x0;
                                    if (!bool_185) {
                                            &decomp_var_b68 = &decomp_var_b68;
                                            do {
                                                    decomp_var_b58 = *eax;
                                                    sub_47c8f9();
                                                    eax = decomp_var_b58;
                                                    esp = (esp - 0x4) + 0x4;
                                            } while (eax != esi[0x1]);
                                    }
                                    if (decomp_var_b30 == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (edi == decomp_var_b48[0x1]) {
                                            sub_47a948();
                                    }
                                    edi = decomp_var_b54 + 0x18;
                                    if (esi == edi) {
                                            sub_40e310();
                                            esi = decomp_var_b30;
                                            ebx = decomp_var_b34;
                                            edi = decomp_var_b50;
                                            continue;
                                    }
                                    ebx = edi[0x1];
                                    ecx = esi[0x1];
                                    eax = *ecx;
                                    edx = *ebx;
                                    *ecx = ecx;
                                    ecx = esi[0x1];
                                    ecx[0x1] = ecx;
                                    bool_189 = eax == esi[0x1];
                                    decomp_var_ad8 = edx;
                                    esi[0x2] = 0x0;
                                    if (!bool_189) {
                                            decomp_var_b58 = *eax;
                                            sub_47c8f9();
                                            eax = decomp_var_b58;
                                            esp = (esp - 0x4) + 0x4;
                                            if (eax != esi[0x1]) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    esp = esp - 0x1c;
                                    sub_4054c0(esi, *esi[0x1], edi, decomp_var_ad8, edi, ebx);
                            }
                            else {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (edi == decomp_var_b48[0x1]) {
                                            sub_47a948();
                                    }
                                    edi[0xb] = decomp_var_b54[0x4];
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (edi == decomp_var_b48[0x1]) {
                                            sub_47a948();
                                    }
                                    edi[0xc] = decomp_var_b54[0x5];
                            }
                    }
                    else {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (edi == decomp_var_b48[0x1]) {
                                    sub_47a948();
                            }
                            edi[0xb] = decomp_var_b54[0x4];
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (edi == decomp_var_b48[0x1]) {
                            sub_47a948();
                    }
                    edi[0xb] = decomp_var_b54[0x4];
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (edi == decomp_var_b48[0x1]) {
                            sub_47a948();
                    }
                    edi[0x9] = decomp_var_b54[0x2];
                    edi[0xa] = decomp_var_b54[0x3];
            }
            sub_40e310();
            esi = decomp_var_b30;
            ebx = decomp_var_b34;
            edi = decomp_var_b50;
            continue;
    }
    break;

loc_442c29:
    eax = decomp_var_b50;
    if (eax == arg_4) goto .l6;
    goto loc_442c36;

loc_443942:
    if (eax == 0x0 || eax != 0xbaed7c) {
            sub_47a948();
    }
    if (esi == *dword_baed80) goto .l111;
    goto loc_443960;
    sub_40b560();
    ebx = decomp_var_b4c[0x2];
    esi = *ebx[0x915];
    ebx = ebx + 0x2450;
    decomp_var_b48 = ebx;
    decomp_var_b44 = esi;
    goto .l18;

.l6:
    decomp_var_b40 = decomp_var_b40 + 0x1e;
    bool_196 = decomp_var_b50 + 0x1 < *(decomp_var_b4c[0x2] + 0x2404);
    decomp_var_b50 = decomp_var_b50 + 0x1;
    if (bool_196) {
            continue;
    }
    temp_1 = 0x1;
    break;

loc_442c36:
    if (*(eax * 0x4 + 0x62e460) <= 0x0) goto .l11;
    goto loc_442c46;

.l111:
    break;

loc_443960:
    decomp_var_b58 = 0x0;
    if (*(decomp_var_b4c[0x2] + 0x2404) <= 0x0) {
            sub_40f380();
            esi = decomp_var_b20;
            eax = decomp_var_b24;
            continue;
    }
    decomp_var_b50 = 0x0;
    decomp_var_b40 = esi + 0x68;
    goto loc_443982;

.l18:
    eax = decomp_var_b4c[0x2];
    edx = eax[0x915];
    edi = decomp_var_b38;
    eax = eax + 0x2450;
    decomp_var_aa8 = edx;
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi == decomp_var_aa8) goto .l26;
    goto .l19;

.l10:
    if (temp_1 == 0x0) goto .l106;
    goto loc_442fb3;

.l11:
    decomp_var_b40 = decomp_var_b40 + 0x1e;
    bool_193 = decomp_var_b50 + 0x1 < *(decomp_var_b4c[0x2] + 0x2404);
    decomp_var_b50 = decomp_var_b50 + 0x1;
    if (bool_193) {
            continue;
    }
    temp_1 = 0x1;
    break;

loc_442c46:
    if (edi == decomp_var_b3c[0x1]) {
            sub_47a948();
    }
    esi = edi[0x5];
    bool_197 = *((esi + decomp_var_b40) * 0x8 + 0xbbf690) != 0x0;
    esi = (esi + decomp_var_b40) * 0x8 + 0xbbf690;
    if (!bool_197) {
            sub_47a948();
    }
    if (esi[0x1] == *(*esi + 0x4)) {
            sub_47a948();
    }
    ebx = esi[0x1];
    eax = *ebx[0x188];
    ebx = ebx + 0x61c;
    decomp_var_b34 = ebx;
    decomp_var_b30 = eax;
    &decomp_var_b68 = &decomp_var_b68;
    goto loc_442ca0;
    esi = decomp_var_b14;
    edi = decomp_var_b18;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    *dword_62b0c4 = esi + 0x1c;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    *dword_633ebc = esi[0x15];
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    *dword_62c57c = esi[0xe];
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    *dword_62be94 = esi[0xf];
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    *dword_633e64 = esi[0x13];
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x10];
    *qword_62e358 = eax;
    *dword_62e35c = eax & 0x80000000 ? 0xffffffff : 0x0;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x11];
    *dword_62db50 = eax;
    *dword_62db54 = eax & 0x80000000 ? 0xffffffff : 0x0;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    *dword_6240cc = esi[0x12];
    esp = esp - 0x8;
    ebx = sub_43bd20(arg_4, decomp_var_b04);
    decomp_var_b58 = ebx;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    esi[0x10] = *qword_62e358;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    esi[0x11] = *dword_62db50;
    if (*dword_62cc64 >= 0x1) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x9];
            ebx = (SAR(eax - (eax & 0x80000000 ? 0xffffffff : 0x0), 0x1)) + (SAR(decomp_var_b58 - (decomp_var_b58 & 0x80000000 ? 0xffffffff : 0x0), 0x1));
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    esi[0x9] = decomp_var_b58;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    *(esi + *dword_62cc64 * 0x4 + 0xd4) = decomp_var_b58;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    *(esi + *dword_62cc64 * 0x4 + 0x14c) = ebx;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    esi[0xd] = *dword_62cc64;
    esi = decomp_var_b4c;
    sub_40f260();
    edi = decomp_var_b18;
    continue;

loc_443982:
    edi = decomp_var_b24;
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (*decomp_var_b40 <= 0x0) goto loc_443c01;
    goto loc_4439a6;

.l26:
    break;

.l19:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x6b] != 0x1) goto .l21;
    goto .l20;

.l106:
    temp_2 = 0x0;
    break;

loc_442fb3:
    if (decomp_var_b14 == decomp_var_b18[0x1]) {
            sub_47a948();
    }
    esi = *decomp_var_b14[0x188];
    edi = decomp_var_b14 + 0x61c;
    ebx = edi;
    decomp_var_b50 = edi;
    decomp_var_b34 = ebx;
    decomp_var_b30 = esi;
    goto loc_442fe5;

loc_442ca0:
    if (edi == decomp_var_b3c[0x1]) {
            sub_47a948();
    }
    esi = edi[0x5];
    bool_206 = *((esi + decomp_var_b40) * 0x8 + 0xbbf690) != 0x0;
    esi = (esi + decomp_var_b40) * 0x8 + 0xbbf690;
    if (!bool_206) {
            sub_47a948();
    }
    if (esi[0x1] == *(*esi + 0x4)) {
            sub_47a948();
    }
    eax = esi[0x1];
    esi = eax[0x188];
    eax = eax + 0x61c;
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (decomp_var_b30 != esi) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (decomp_var_b30 == ebx[0x1]) {
                    sub_47a948();
            }
            esi = decomp_var_b30 + 0xc;
            esp = esp - 0x8;
            decomp_var_b54 = esi;
            eax = sub_402060(&decomp_var_a84, esi, decomp_var_b68, decomp_var_b64, decomp_var_b60);
            bool_202 = decomp_var_b30 != ebx[0x1];
            ecx = *eax;
            edi = eax[0x1];
            decomp_var_b48 = ecx;
            if (!bool_202) {
                    sub_47a948();
            }
            if (decomp_var_b48 == 0x0) {
                    sub_47a948();
            }
            if (edi == decomp_var_b48[0x1]) {
                    sub_47a948();
            }
            edi[0x8] = esi[0x1];
            if (edi == decomp_var_b48[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x8];
            eax = eax - 0x2;
            if (eax > 0x4) {
                    sub_40e310();
                    ebx = decomp_var_b34;
                    edi = decomp_var_b38;
                    continue;
            }
            if (*(eax * 0x4 + switch_table) == 0x0) {
                    if (decomp_var_b30 == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (edi == decomp_var_b48[0x1]) {
                            sub_47a948();
                    }
                    edi[0xb] = esi[0x4];
                    if (decomp_var_b30 == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (edi == decomp_var_b48[0x1]) {
                            sub_47a948();
                    }
                    edi[0x9] = esi[0x2];
                    edi[0xa] = esi[0x3];
                    sub_40e310();
                    ebx = decomp_var_b34;
                    edi = decomp_var_b38;
                    continue;
            }
            if (*(eax * 0x4 + switch_table) == 0x1) {
                    if (decomp_var_b30 == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (edi == decomp_var_b48[0x1]) {
                            sub_47a948();
                    }
                    edi[0xb] = esi[0x4];
                    sub_40e310();
                    ebx = decomp_var_b34;
                    edi = decomp_var_b38;
                    continue;
            }
            if (*(eax * 0x4 + switch_table) == 0x2) {
                    if (decomp_var_b30 == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (edi == decomp_var_b48[0x1]) {
                            sub_47a948();
                    }
                    edi[0xb] = esi[0x4];
                    if (decomp_var_b30 == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (edi == decomp_var_b48[0x1]) {
                            sub_47a948();
                    }
                    edi[0xc] = esi[0x5];
                    sub_40e310();
                    ebx = decomp_var_b34;
                    edi = decomp_var_b38;
                    continue;
            }
            if (decomp_var_b30 == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi == decomp_var_b48[0x1]) {
                    sub_47a948();
            }
            edi[0x9] = esi[0x2];
            edi[0xa] = esi[0x3];
            if (edi == decomp_var_b48[0x1]) {
                    sub_47a948();
            }
            ecx = edi[0xe];
            eax = *ecx;
            esi = edi + 0x34;
            *ecx = ecx;
            ecx = esi[0x1];
            ecx[0x1] = ecx;
            bool_205 = eax == esi[0x1];
            esi[0x2] = 0x0;
            if (!bool_205) {
                    sub_442ee0(decomp_var_b68, decomp_var_b64, decomp_var_b60, decomp_var_b5c);
            }
            if (decomp_var_b30 == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi == decomp_var_b48[0x1]) {
                    sub_47a948();
            }
            edi = decomp_var_b54 + 0x18;
            if (esi == edi) {
                    sub_40e310();
                    ebx = decomp_var_b34;
                    edi = decomp_var_b38;
                    continue;
            }
            ebx = edi[0x1];
            decomp_var_ac0 = *ebx;
            ecx = esi[0x1];
            eax = *ecx;
            *ecx = ecx;
            ecx = esi[0x1];
            ecx[0x1] = ecx;
            bool_220 = eax == esi[0x1];
            esi[0x2] = 0x0;
            if (!bool_220) {
                    decomp_var_b58 = *eax;
                    sub_47c8f9();
                    eax = decomp_var_b58;
                    esp = (esp - 0x4) + 0x4;
                    if (eax != esi[0x1]) {
                            continue;
                    }
                    break;
            }
            esp = esp - 0x1c;
            sub_4054c0(esi, *esi[0x1], edi, decomp_var_ac0, edi, ebx);
            sub_40e310();
            ebx = decomp_var_b34;
            edi = decomp_var_b38;
            continue;
    }
    temp_0 = 0x1;
    break;

loc_443c01:
    decomp_var_b40 = decomp_var_b40 + 0x4;
    decomp_var_b50 = decomp_var_b50 + 0x100;
    bool_330 = decomp_var_b58 + 0x1 < *(decomp_var_b4c[0x2] + 0x2404);
    decomp_var_b58 = decomp_var_b58 + 0x1;
    if (bool_330) {
            continue;
    }
    break;

loc_4439a6:
    edi = decomp_var_b24;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    ebx = esi[0x3];
    ebx = (ebx + decomp_var_b50) * 0x4 + 0xb9a980;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    *ebx = *ebx + *decomp_var_b40;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    ebx = decomp_var_b4c;
    if (*(int8_t *)(ebx[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) == 0x0) goto loc_443b11;
    goto loc_4439f6;
    eax = decomp_var_b4c[0x2];
    edi = *eax[0x915];
    esi = eax + 0x2450;
    decomp_var_b48 = esi;
    decomp_var_b44 = edi;
    &decomp_var_b68 = &decomp_var_b68;
    goto .l14;

.l21:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x6a] != 0x1) goto .l24;
    goto .l22;

.l20:
    if (esi == ebx[0x1]) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_b58 = sub_41c270(esi + 0x24) + esi[0x6] * 0x4 + 0x54;
    if (edi == decomp_var_b3c[0x1]) {
            sub_47a948();
    }
    *decomp_var_b58 = *decomp_var_b58 + edi[0x4];
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    eax = esi[0x9];
    eax = &decomp_var_b68 + eax * 0x4 + 0x12c;
    decomp_var_b58 = eax;
    if (edi == decomp_var_b3c[0x1]) {
            sub_47a948();
            eax = decomp_var_b58;
    }
    *eax = *eax + edi[0x4];
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != arg_4) {
            edi = decomp_var_b48;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x69] == 0x1) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edi = decomp_var_b38;
                    bool_267 = edi != decomp_var_b3c[0x1];
                    esi = esi[0x9];
                    esi = &decomp_var_b68 + esi * 0x4 + 0x12c;
                    if (!bool_267) {
                            sub_47a948();
                    }
                    *esi = *esi + edi[0x4];
            }
            sub_401390();
            esi = decomp_var_b44;
            ebx = decomp_var_b48;
            continue;
    }
    decomp_var_b58 = 0x0;
    if (*(decomp_var_b4c[0x2] + 0x2404) <= 0x0) {
            edi = decomp_var_b48;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x69] == 0x1) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edi = decomp_var_b38;
                    bool_267 = edi != decomp_var_b3c[0x1];
                    esi = esi[0x9];
                    esi = &decomp_var_b68 + esi * 0x4 + 0x12c;
                    if (!bool_267) {
                            sub_47a948();
                    }
                    *esi = *esi + edi[0x4];
            }
            sub_401390();
            esi = decomp_var_b44;
            ebx = decomp_var_b48;
            continue;
    }
    eax = 0x0;
    decomp_var_b50 = 0x0;
    goto .l29;

loc_442fe5:
    if (decomp_var_b14 == decomp_var_b18[0x1]) {
            sub_47a948();
    }
    decomp_var_a90 = edi[0x1];
    if (ebx == 0x0 || ebx != edi) {
            sub_47a948();
    }
    if (esi != decomp_var_a90) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            decomp_var_b54 = esi + 0xc;
            esp = esp - 0x8;
            eax = sub_402060(&decomp_var_ab4, esi + 0xc, decomp_var_b68, decomp_var_b64, decomp_var_b60);
            bool_105 = esi != ebx[0x1];
            edx = *eax;
            edi = eax[0x1];
            decomp_var_b48 = edx;
            if (!bool_105) {
                    sub_47a948();
            }
            if (decomp_var_b48 == 0x0) {
                    sub_47a948();
            }
            if (edi == decomp_var_b48[0x1]) {
                    sub_47a948();
            }
            edi[0x8] = decomp_var_b54[0x1];
            if (edi == decomp_var_b48[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x8];
            eax = eax - 0x2;
            if (eax > 0x4) {
                    sub_40e310();
                    esi = decomp_var_b30;
                    ebx = decomp_var_b34;
                    edi = decomp_var_b50;
                    continue;
            }
            if (*(eax * 0x4 + switch_table) != 0x0) {
                    if (*(eax * 0x4 + switch_table) != 0x1) {
                            if (*(eax * 0x4 + switch_table) != 0x2) {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (edi == decomp_var_b48[0x1]) {
                                            sub_47a948();
                                    }
                                    edi[0x9] = decomp_var_b54[0x2];
                                    edi[0xa] = decomp_var_b54[0x3];
                                    if (edi == decomp_var_b48[0x1]) {
                                            sub_47a948();
                                    }
                                    ecx = edi[0xe];
                                    eax = *ecx;
                                    esi = edi + 0x34;
                                    *ecx = ecx;
                                    ecx = esi[0x1];
                                    ecx[0x1] = ecx;
                                    bool_95 = eax == esi[0x1];
                                    esi[0x2] = 0x0;
                                    if (!bool_95) {
                                            &decomp_var_b68 = &decomp_var_b68;
                                            do {
                                                    decomp_var_b58 = *eax;
                                                    sub_47c8f9();
                                                    eax = decomp_var_b58;
                                                    esp = (esp - 0x4) + 0x4;
                                            } while (eax != esi[0x1]);
                                    }
                                    if (decomp_var_b30 == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (edi == decomp_var_b48[0x1]) {
                                            sub_47a948();
                                    }
                                    edi = decomp_var_b54 + 0x18;
                                    if (esi == edi) {
                                            sub_40e310();
                                            esi = decomp_var_b30;
                                            ebx = decomp_var_b34;
                                            edi = decomp_var_b50;
                                            continue;
                                    }
                                    ebx = edi[0x1];
                                    ecx = esi[0x1];
                                    eax = *ecx;
                                    edx = *ebx;
                                    *ecx = ecx;
                                    ecx = esi[0x1];
                                    ecx[0x1] = ecx;
                                    bool_90 = eax == esi[0x1];
                                    decomp_var_ad8 = edx;
                                    esi[0x2] = 0x0;
                                    if (!bool_90) {
                                            decomp_var_b58 = *eax;
                                            sub_47c8f9();
                                            eax = decomp_var_b58;
                                            esp = (esp - 0x4) + 0x4;
                                            if (eax != esi[0x1]) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    esp = esp - 0x1c;
                                    sub_4054c0(esi, *esi[0x1], edi, decomp_var_ad8, edi, ebx);
                            }
                            else {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (edi == decomp_var_b48[0x1]) {
                                            sub_47a948();
                                    }
                                    edi[0xb] = decomp_var_b54[0x4];
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (edi == decomp_var_b48[0x1]) {
                                            sub_47a948();
                                    }
                                    edi[0xc] = decomp_var_b54[0x5];
                            }
                    }
                    else {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (edi == decomp_var_b48[0x1]) {
                                    sub_47a948();
                            }
                            edi[0xb] = decomp_var_b54[0x4];
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (edi == decomp_var_b48[0x1]) {
                            sub_47a948();
                    }
                    edi[0xb] = decomp_var_b54[0x4];
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (edi == decomp_var_b48[0x1]) {
                            sub_47a948();
                    }
                    edi[0x9] = decomp_var_b54[0x2];
                    edi[0xa] = decomp_var_b54[0x3];
            }
            sub_40e310();
            esi = decomp_var_b30;
            ebx = decomp_var_b34;
            edi = decomp_var_b50;
            continue;
    }
    break;
    if (temp_0 != 0x0) {
            decomp_var_b40 = decomp_var_b40 + 0x1e;
            bool_199 = decomp_var_b50 + 0x1 < *(decomp_var_b4c[0x2] + 0x2404);
            decomp_var_b50 = decomp_var_b50 + 0x1;
            if (bool_199) {
                    continue;
            }
            temp_1 = 0x1;
            break;
    }
    else {
            temp_1 = 0x0;
            break;
    }
    goto .l10;
    sub_40f380();
    esi = decomp_var_b20;
    eax = decomp_var_b24;
    continue;

loc_443b11:
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(esi + 0x10, decomp_var_b68);
    ebx = *eax[0x1];
    edi = eax;
    decomp_var_b1c = eax;
    decomp_var_b54 = 0xffffffff;
    decomp_var_b2c = edi;
    decomp_var_b28 = ebx;
    goto .l33;

loc_4439f6:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    eax = *(int16_t *)(ebx[0x2] + (eax + eax * 0x8) * 0x4 + 0x20);
    bool_323 = HIBYTE(eax) == 0x41;
    eax = eax & 0xff;
    if (!bool_323) {
            eax = 0x14;
    }
    if (eax == decomp_var_b58) goto .l31;
    goto loc_443a25;

.l14:
    eax = decomp_var_b4c[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi == ebx) goto .l13;
    goto .l16;

.l24:
    if (esi == ebx[0x1]) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_b58 = sub_41c270(esi + 0x10) + esi[0x6] * 0x4 + 0x54;
    if (edi == decomp_var_b3c[0x1]) {
            sub_47a948();
    }
    *decomp_var_b58 = *decomp_var_b58 + edi[0x4];
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    eax = esi[0x4];
    eax = &decomp_var_b68 + eax * 0x4 + 0x12c;
    decomp_var_b58 = eax;
    if (edi == decomp_var_b3c[0x1]) {
            sub_47a948();
            eax = decomp_var_b58;
    }
    *eax = *eax + edi[0x4];
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != arg_4 || *(decomp_var_b4c[0x2] + 0x2404) <= 0x0) {
            edi = decomp_var_b48;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x69] == 0x1) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edi = decomp_var_b38;
                    bool_267 = edi != decomp_var_b3c[0x1];
                    esi = esi[0x9];
                    esi = &decomp_var_b68 + esi * 0x4 + 0x12c;
                    if (!bool_267) {
                            sub_47a948();
                    }
                    *esi = *esi + edi[0x4];
            }
            sub_401390();
            esi = decomp_var_b44;
            ebx = decomp_var_b48;
            continue;
    }
    ebx = 0x0;
    decomp_var_b50 = 0x0;
    goto .l27;

.l22:
    decomp_var_b54 = 0xffffffff;
    if (esi == ebx[0x1]) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(esi + 0x14, decomp_var_b68);
    edi = *eax[0x1];
    ebx = eax;
    decomp_var_b1c = eax;
    decomp_var_b2c = ebx;
    decomp_var_b28 = edi;
    goto .l28;

.l29:
    if (eax != arg_4 && *(eax * 0x4 + 0x62e460) > 0x0) {
            if (edi == decomp_var_b3c[0x1]) {
                    sub_47a948();
            }
            edi = decomp_var_b38[0x5];
            bool_305 = *((edi + decomp_var_b50) * 0x8 + 0xbbf690) != 0x0;
            edi = (edi + decomp_var_b50) * 0x8 + 0xbbf690;
            if (!bool_305) {
                    sub_47a948();
            }
            if (edi[0x1] == *(*edi + 0x4)) {
                    sub_47a948();
            }
            edi = edi[0x1];
            edi = edi + 0xc;
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = decomp_var_b58;
            *(edi + esi[0x9] * 0x4 + 0x210) = 0x1;
            edi = decomp_var_b38;
    }
    decomp_var_b50 = decomp_var_b50 + 0x1e;
    eax = eax + 0x1;
    decomp_var_b58 = eax;
    if (eax < *(decomp_var_b4c[0x2] + 0x2404)) {
            continue;
    }
    break;
    sub_40b560();
    ebx = decomp_var_b4c[0x2];
    esi = *ebx[0x915];
    ebx = ebx + 0x2450;
    decomp_var_b48 = ebx;
    decomp_var_b44 = esi;
    goto loc_443299;

.l33:
    eax = decomp_var_b1c;
    decomp_var_aa0 = eax[0x1];
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (ebx != decomp_var_aa0) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            if (ebx[0x3] != decomp_var_b54) {
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = ebx[0x3];
                    eax = (eax + decomp_var_b50) * 0x4 + 0xb9a980;
                    decomp_var_b54 = eax;
                    if (esi == decomp_var_b24[0x1]) {
                            sub_47a948();
                            eax = decomp_var_b54;
                    }
                    *eax = *eax + *decomp_var_b40;
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_b54 = ebx[0x3];
            }
            sub_40f400();
            ebx = decomp_var_b28;
            edi = decomp_var_b2c;
            continue;
    }
    break;

.l31:
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(esi + 0x10, decomp_var_b68);
    ebx = *eax[0x1];
    edi = eax;
    decomp_var_b1c = eax;
    decomp_var_b54 = 0xffffffff;
    decomp_var_b2c = edi;
    decomp_var_b28 = ebx;
    goto loc_443b60;

loc_443a25:
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(esi + 0x10, decomp_var_b68);
    ebx = *eax[0x1];
    edi = eax;
    decomp_var_b1c = eax;
    decomp_var_b54 = 0xffffffff;
    decomp_var_b2c = edi;
    decomp_var_b28 = ebx;
    goto loc_443a70;

.l13:
    break;

.l16:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    if (edi[0x6a] != 0x1) {
            sub_401390();
            edi = decomp_var_b44;
            esi = decomp_var_b48;
            continue;
    }
    eax = decomp_var_b0c;
    ebx = eax[0x1];
    esi = ebx;
    if (ebx[0x21] == 0x0) {
            do {
                    sub_40faf0(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    ebx = esi;
            } while (esi[0x21] == 0x0);
            eax = decomp_var_b0c;
    }
    esi = decomp_var_b48;
    eax[0x1] = eax;
    *decomp_var_b0c = decomp_var_b0c;
    decomp_var_b0c[0x2] = decomp_var_b0c;
    if (edi == esi[0x1]) {
            sub_47a948();
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(edi + 0x14, decomp_var_b68);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_b1c = eax;
    decomp_var_b2c = ebx;
    decomp_var_b28 = esi;
    goto .l17;

.l27:
    if (ebx != arg_4 && *(ebx * 0x4 + 0x62e460) > 0x0) {
            if (decomp_var_b38 == decomp_var_b3c[0x1]) {
                    sub_47a948();
            }
            edi = decomp_var_b38[0x5];
            bool_295 = *((edi + decomp_var_b50) * 0x8 + 0xbbf690) != 0x0;
            edi = (edi + decomp_var_b50) * 0x8 + 0xbbf690;
            if (!bool_295) {
                    sub_47a948();
            }
            if (edi[0x1] == *(*edi + 0x4)) {
                    sub_47a948();
            }
            edi = edi[0x1];
            edi = edi + 0xc;
            if (esi == decomp_var_b48[0x1]) {
                    sub_47a948();
            }
            *(edi + esi[0x4] * 0x4 + 0x210) = 0x1;
    }
    decomp_var_b50 = decomp_var_b50 + 0x1e;
    ebx = ebx + 0x1;
    if (ebx < *(decomp_var_b4c[0x2] + 0x2404)) {
            continue;
    }
    break;

.l28:
    eax = decomp_var_b1c;
    decomp_var_ab8 = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (edi != decomp_var_ab8) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi[0x3] != decomp_var_b54) {
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    eax = edi[0x3];
                    eax = &decomp_var_b68 + eax * 0x4 + 0x52c;
                    decomp_var_b58 = eax;
                    if (decomp_var_b38 == decomp_var_b3c[0x1]) {
                            sub_47a948();
                            eax = decomp_var_b58;
                    }
                    *eax = *eax + decomp_var_b38[0x4];
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_b54 = edi[0x3];
            }
            sub_40f400();
            edi = decomp_var_b28;
            ebx = decomp_var_b2c;
            continue;
    }
    break;
    edi = decomp_var_b48;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x69] == 0x1) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edi = decomp_var_b38;
            bool_267 = edi != decomp_var_b3c[0x1];
            esi = esi[0x9];
            esi = &decomp_var_b68 + esi * 0x4 + 0x12c;
            if (!bool_267) {
                    sub_47a948();
            }
            *esi = *esi + edi[0x4];
    }
    sub_401390();
    esi = decomp_var_b44;
    ebx = decomp_var_b48;
    continue;

loc_443299:
    eax = decomp_var_b4c[0x2];
    edx = eax[0x915];
    edi = decomp_var_b38;
    eax = eax + 0x2450;
    decomp_var_aa8 = edx;
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi == decomp_var_aa8) goto .l74;
    goto loc_4432d0;
    decomp_var_b40 = decomp_var_b40 + 0x4;
    decomp_var_b50 = decomp_var_b50 + 0x100;
    bool_322 = decomp_var_b58 + 0x1 < *(decomp_var_b4c[0x2] + 0x2404);
    decomp_var_b58 = decomp_var_b58 + 0x1;
    if (bool_322) {
            continue;
    }
    break;

loc_443b60:
    eax = decomp_var_b1c;
    decomp_var_aa0 = eax[0x1];
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (ebx != decomp_var_aa0) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            if (ebx[0x3] != decomp_var_b54) {
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = ebx[0x3];
                    eax = (eax + decomp_var_b50) * 0x4 + 0xb9a980;
                    decomp_var_b54 = eax;
                    if (esi == decomp_var_b24[0x1]) {
                            sub_47a948();
                            eax = decomp_var_b54;
                    }
                    *eax = *eax + *decomp_var_b40;
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_b54 = ebx[0x3];
            }
            sub_40f400();
            ebx = decomp_var_b28;
            edi = decomp_var_b2c;
            continue;
    }
    break;

loc_443a70:
    eax = decomp_var_b1c;
    decomp_var_a88 = eax[0x1];
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (ebx != decomp_var_a88) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            if (ebx[0x3] != decomp_var_b54) {
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = ebx[0x3];
                    eax = (eax + decomp_var_b50) * 0x4 + 0xb95580;
                    decomp_var_b54 = eax;
                    if (esi == decomp_var_b24[0x1]) {
                            sub_47a948();
                            eax = decomp_var_b54;
                    }
                    *eax = *eax + *decomp_var_b40;
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_b54 = ebx[0x3];
            }
            sub_40f400();
            ebx = decomp_var_b28;
            edi = decomp_var_b2c;
            continue;
    }
    break;
    sub_40e680();
    edi = decomp_var_b38;
    ebx = decomp_var_b3c;
    continue;

.l17:
    eax = decomp_var_b1c;
    decomp_var_a98 = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_a98) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (*(&decomp_var_b68 + esi[0x3] * 0x4 + 0x12c) == 0x0) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (*(&decomp_var_b68 + esi[0x3] * 0x4 + 0x52c) < 0x2) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (edi == decomp_var_b48[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x3] != edi[0x18]) {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    ebx = esi[0x3];
                                    bool_249 = edi != decomp_var_b48[0x1];
                                    esi = esi[0x4];
                                    decomp_var_b00 = ebx;
                                    if (!bool_249) {
                                            sub_47a948();
                                    }
                                    eax = sub_41c1e0(&decomp_var_b00);
                                    decomp_var_aec = *eax;
                                    esp = esp - 0xc;
                                    eax = sub_41a010(&decomp_var_a48, &decomp_var_aec, decomp_var_b68);
                            }
                    }
            }
            sub_40f400();
            esi = decomp_var_b28;
            ebx = decomp_var_b2c;
            continue;
    }
    break;

.l74:
    break;

loc_4432d0:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x6b] != 0x1) goto loc_44342a;
    goto loc_4432ed;
    decomp_var_b40 = decomp_var_b40 + 0x4;
    decomp_var_b50 = decomp_var_b50 + 0x100;
    bool_335 = decomp_var_b58 + 0x1 < *(decomp_var_b4c[0x2] + 0x2404);
    decomp_var_b58 = decomp_var_b58 + 0x1;
    if (bool_335) {
            continue;
    }
    break;
    decomp_var_b40 = decomp_var_b40 + 0x4;
    decomp_var_b50 = decomp_var_b50 + 0x100;
    bool_319 = decomp_var_b58 + 0x1 < *(decomp_var_b4c[0x2] + 0x2404);
    decomp_var_b58 = decomp_var_b58 + 0x1;
    if (bool_319) {
            continue;
    }
    break;
    esi = *decomp_var_b0c;
    if (esi != decomp_var_b0c) {
            if (edi == decomp_var_b48[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            eax = sub_41c270(esi + 0x18);
            ecx = edi[0x6];
            edi = decomp_var_b38;
            esi = eax + ecx * 0x4 + 0x54;
            if (edi == decomp_var_b3c[0x1]) {
                    sub_47a948();
            }
            *esi = *esi + edi[0x4];
    }
    sub_401390();
    edi = decomp_var_b44;
    esi = decomp_var_b48;
    continue;
    eax = decomp_var_b4c[0x2];
    edi = *eax[0x915];
    esi = eax + 0x2450;
    decomp_var_b48 = esi;
    decomp_var_b44 = edi;
    &decomp_var_b68 = &decomp_var_b68;
    goto loc_4436d0;

loc_44342a:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x6a] != 0x1) goto loc_443529;
    goto loc_44343e;

loc_4432ed:
    if (esi == ebx[0x1]) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_b58 = sub_41c270(esi + 0x24) + esi[0x6] * 0x4 + 0x54;
    if (edi == decomp_var_b3c[0x1]) {
            sub_47a948();
    }
    *decomp_var_b58 = *decomp_var_b58 + edi[0x4];
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    eax = esi[0x9];
    eax = &decomp_var_b68 + eax * 0x4 + 0x12c;
    decomp_var_b58 = eax;
    if (edi == decomp_var_b3c[0x1]) {
            sub_47a948();
            eax = decomp_var_b58;
    }
    *eax = *eax + edi[0x4];
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != arg_4) {
            edi = decomp_var_b48;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x69] == 0x1) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edi = decomp_var_b38;
                    bool_117 = edi != decomp_var_b3c[0x1];
                    esi = esi[0x9];
                    esi = &decomp_var_b68 + esi * 0x4 + 0x12c;
                    if (!bool_117) {
                            sub_47a948();
                    }
                    *esi = *esi + edi[0x4];
            }
            sub_401390();
            esi = decomp_var_b44;
            ebx = decomp_var_b48;
            continue;
    }
    decomp_var_b58 = 0x0;
    if (*(decomp_var_b4c[0x2] + 0x2404) <= 0x0) {
            edi = decomp_var_b48;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x69] == 0x1) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edi = decomp_var_b38;
                    bool_117 = edi != decomp_var_b3c[0x1];
                    esi = esi[0x9];
                    esi = &decomp_var_b68 + esi * 0x4 + 0x12c;
                    if (!bool_117) {
                            sub_47a948();
                    }
                    *esi = *esi + edi[0x4];
            }
            sub_401390();
            esi = decomp_var_b44;
            ebx = decomp_var_b48;
            continue;
    }
    eax = 0x0;
    decomp_var_b50 = 0x0;
    goto loc_443393;

loc_4436d0:
    eax = decomp_var_b4c[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi == ebx) goto .l88;
    goto loc_4436f7;

loc_443529:
    if (esi == ebx[0x1]) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_b58 = sub_41c270(esi + 0x10) + esi[0x6] * 0x4 + 0x54;
    if (edi == decomp_var_b3c[0x1]) {
            sub_47a948();
    }
    *decomp_var_b58 = *decomp_var_b58 + edi[0x4];
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    eax = esi[0x4];
    eax = &decomp_var_b68 + eax * 0x4 + 0x12c;
    decomp_var_b58 = eax;
    if (edi == decomp_var_b3c[0x1]) {
            sub_47a948();
            eax = decomp_var_b58;
    }
    *eax = *eax + edi[0x4];
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != arg_4 || *(decomp_var_b4c[0x2] + 0x2404) <= 0x0) {
            edi = decomp_var_b48;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x69] == 0x1) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edi = decomp_var_b38;
                    bool_117 = edi != decomp_var_b3c[0x1];
                    esi = esi[0x9];
                    esi = &decomp_var_b68 + esi * 0x4 + 0x12c;
                    if (!bool_117) {
                            sub_47a948();
                    }
                    *esi = *esi + edi[0x4];
            }
            sub_401390();
            esi = decomp_var_b44;
            ebx = decomp_var_b48;
            continue;
    }
    ebx = 0x0;
    decomp_var_b50 = 0x0;
    goto loc_4435cb;

loc_44343e:
    decomp_var_b54 = 0xffffffff;
    if (esi == ebx[0x1]) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(esi + 0x14, decomp_var_b68);
    edi = *eax[0x1];
    ebx = eax;
    decomp_var_b1c = eax;
    decomp_var_b2c = ebx;
    decomp_var_b28 = edi;
    goto loc_443487;

loc_443393:
    if (eax != arg_4 && *(eax * 0x4 + 0x62e460) > 0x0) {
            if (edi == decomp_var_b3c[0x1]) {
                    sub_47a948();
            }
            edi = decomp_var_b38[0x5];
            bool_158 = *((edi + decomp_var_b50) * 0x8 + 0xbbf690) != 0x0;
            edi = (edi + decomp_var_b50) * 0x8 + 0xbbf690;
            if (!bool_158) {
                    sub_47a948();
            }
            if (edi[0x1] == *(*edi + 0x4)) {
                    sub_47a948();
            }
            edi = edi[0x1];
            edi = edi + 0xc;
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = decomp_var_b58;
            *(edi + esi[0x9] * 0x4 + 0x210) = 0x1;
            edi = decomp_var_b38;
    }
    decomp_var_b50 = decomp_var_b50 + 0x1e;
    eax = eax + 0x1;
    decomp_var_b58 = eax;
    if (eax < *(decomp_var_b4c[0x2] + 0x2404)) {
            continue;
    }
    break;

.l88:
    break;

loc_4436f7:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    if (edi[0x6a] != 0x1) {
            sub_401390();
            edi = decomp_var_b44;
            esi = decomp_var_b48;
            continue;
    }
    eax = decomp_var_b0c;
    ebx = eax[0x1];
    esi = ebx;
    if (ebx[0x21] == 0x0) {
            do {
                    sub_40faf0(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    ebx = esi;
            } while (esi[0x21] == 0x0);
            eax = decomp_var_b0c;
    }
    esi = decomp_var_b48;
    eax[0x1] = eax;
    *decomp_var_b0c = decomp_var_b0c;
    decomp_var_b0c[0x2] = decomp_var_b0c;
    if (edi == esi[0x1]) {
            sub_47a948();
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(edi + 0x14, decomp_var_b68);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_b1c = eax;
    decomp_var_b2c = ebx;
    decomp_var_b28 = esi;
    goto loc_4437a4;

loc_4435cb:
    if (ebx != arg_4 && *(ebx * 0x4 + 0x62e460) > 0x0) {
            if (decomp_var_b38 == decomp_var_b3c[0x1]) {
                    sub_47a948();
            }
            edi = decomp_var_b38[0x5];
            bool_154 = *((edi + decomp_var_b50) * 0x8 + 0xbbf690) != 0x0;
            edi = (edi + decomp_var_b50) * 0x8 + 0xbbf690;
            if (!bool_154) {
                    sub_47a948();
            }
            if (edi[0x1] == *(*edi + 0x4)) {
                    sub_47a948();
            }
            edi = edi[0x1];
            edi = edi + 0xc;
            if (esi == decomp_var_b48[0x1]) {
                    sub_47a948();
            }
            *(edi + esi[0x4] * 0x4 + 0x210) = 0x1;
    }
    decomp_var_b50 = decomp_var_b50 + 0x1e;
    ebx = ebx + 0x1;
    if (ebx < *(decomp_var_b4c[0x2] + 0x2404)) {
            continue;
    }
    break;

loc_443487:
    eax = decomp_var_b1c;
    decomp_var_ab8 = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (edi != decomp_var_ab8) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi[0x3] != decomp_var_b54) {
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    eax = edi[0x3];
                    eax = &decomp_var_b68 + eax * 0x4 + 0x52c;
                    decomp_var_b58 = eax;
                    if (decomp_var_b38 == decomp_var_b3c[0x1]) {
                            sub_47a948();
                            eax = decomp_var_b58;
                    }
                    *eax = *eax + decomp_var_b38[0x4];
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_b54 = edi[0x3];
            }
            sub_40f400();
            edi = decomp_var_b28;
            ebx = decomp_var_b2c;
            continue;
    }
    break;
    edi = decomp_var_b48;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x69] == 0x1) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edi = decomp_var_b38;
            bool_117 = edi != decomp_var_b3c[0x1];
            esi = esi[0x9];
            esi = &decomp_var_b68 + esi * 0x4 + 0x12c;
            if (!bool_117) {
                    sub_47a948();
            }
            *esi = *esi + edi[0x4];
    }
    sub_401390();
    esi = decomp_var_b44;
    ebx = decomp_var_b48;
    continue;
    sub_40e680();
    edi = decomp_var_b38;
    ebx = decomp_var_b3c;
    continue;

loc_4437a4:
    eax = decomp_var_b1c;
    decomp_var_a98 = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_a98) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (*(&decomp_var_b68 + esi[0x3] * 0x4 + 0x12c) != 0x0) {
                    sub_40f400();
                    esi = decomp_var_b28;
                    ebx = decomp_var_b2c;
                    continue;
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (*(&decomp_var_b68 + esi[0x3] * 0x4 + 0x52c) >= 0x2) {
                    sub_40f400();
                    esi = decomp_var_b28;
                    ebx = decomp_var_b2c;
                    continue;
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi == decomp_var_b48[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] != edi[0x18]) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    ebx = esi[0x3];
                    bool_75 = edi != decomp_var_b48[0x1];
                    esi = esi[0x4];
                    decomp_var_b00 = ebx;
                    if (!bool_75) {
                            sub_47a948();
                    }
                    eax = sub_41c1e0(&decomp_var_b00);
                    decomp_var_aec = *eax;
                    esp = esp - 0xc;
                    eax = sub_41a010(&decomp_var_a48, &decomp_var_aec, decomp_var_b68);
            }
            sub_40f400();
            esi = decomp_var_b28;
            ebx = decomp_var_b2c;
            continue;
    }
    break;
    esi = *decomp_var_b0c;
    if (esi != decomp_var_b0c) {
            if (edi == decomp_var_b48[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            eax = sub_41c270(esi + 0x18);
            ecx = edi[0x6];
            edi = decomp_var_b38;
            esi = eax + ecx * 0x4 + 0x54;
            if (edi == decomp_var_b3c[0x1]) {
                    sub_47a948();
            }
            *esi = *esi + edi[0x4];
    }
    sub_401390();
    edi = decomp_var_b44;
    esi = decomp_var_b48;
    continue;
}
