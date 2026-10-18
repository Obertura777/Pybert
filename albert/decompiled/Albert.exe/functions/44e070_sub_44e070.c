// sub_44e070 @ 0x44e070
// hopper name: sub_44e070
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_44e070() {
    &decomp_var_4 = &decomp_var_4 & 0xfffffff8;
    decomp_var_10 = *0x0;
    decomp_var_d4c = edi;
    esp = esp - 0xd4c;
    decomp_var_d50 = *dword_4c8db8 ^ &decomp_var_d4c;
    *0x0 = &decomp_var_10;
    ebx = ecx;
    decomp_var_d40 = ebx;
    eax = sub_410050();
    eax[0x31] = 0x1;
    eax[0x1] = eax;
    *eax = eax;
    edi = 0x0;
    eax[0x2] = eax;
    sub_4018e0();
    sub_465870();
    sub_465870();
    decomp_var_d20 = 0x0;
    decomp_var_d2c = *(int8_t *)(ebx[0x2] + 0x2424) & 0xff;
    sub_460be0(decomp_var_d50, decomp_var_d4c, decomp_var_d48, decomp_var_d44, decomp_var_d40, decomp_var_d3c, decomp_var_d38);
    if (*(ebx[0x2] + 0x2400) > 0x0) {
            esi = 0xbaeda0;
            do {
                    eax = *esi;
                    if (eax != 0x0) {
                            if (eax == 0x1) {
                                    esp = esp - 0x4;
                                    sub_460670(esi[0x2]);
                            }
                            else {
                                    if (eax == 0x2) {
                                            decomp_var_d58 = esi[0x2];
                                            esp = esp - 0xc;
                                            sub_4606e0(edi, decomp_var_d58, esi[0x6]);
                                    }
                                    else {
                                            if (eax == 0x3) {
                                                    esp = esp - 0x8;
                                                    decomp_var_d58 = edi;
                                                    sub_460770(decomp_var_d58, esi[0x2]);
                                            }
                                            else {
                                                    if (eax == 0x4) {
                                                            decomp_var_d54 = esi[0x2];
                                                            decomp_var_d58 = esi[0x1];
                                                            esp = esp - 0xc;
                                                            sub_4607f0(edi, decomp_var_d58, decomp_var_d54);
                                                    }
                                                    else {
                                                            if (eax == 0x5) {
                                                                    eax = esi[0x2];
                                                                    decomp_var_d58 = esi[0x1];
                                                                    esp = esp - 0xc;
                                                                    sub_460880(edi, decomp_var_d58, eax);
                                                            }
                                                            else {
                                                                    if (eax == 0x6) {
                                                                            eax = esi[0x1a];
                                                                            if (eax >= 0x0) {
                                                                                    ebx[0xa84] = eax;
                                                                            }
                                                                            eax = esi[0x1b];
                                                                            if (eax >= 0x0) {
                                                                                    ebx[0xa85] = eax;
                                                                            }
                                                                            eax = esi[0x1c];
                                                                            if (eax >= 0x0) {
                                                                                    ebx[0xa86] = eax;
                                                                            }
                                                                            decomp_var_d58 = esi[0x17];
                                                                            esp = esp - 0x10;
                                                                            sub_461560(edi, esi[0x2], decomp_var_d58, ebx + 0x2a10, decomp_var_d50);
                                                                    }
                                                                    else {
                                                                            decomp_var_d58 = 0x0;
                                                                            esp = esp - 0xc;
                                                                            sub_4700ea(0x4b13b4, 0x0, 0x0);
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                    edi = edi + 0x1;
                    esi = esi + 0x78;
            } while (edi < *(ebx[0x2] + 0x2400));
    }
    eax = sub_466f80(&decomp_var_cb4, 0xbc1e0c);
    esp = esp - 0xc;
    sub_465ff0(eax);
    decomp_var_4 = 0x3;
    sub_465fa0();
    eax = ebx[0x2];
    edi = eax + 0x2450;
    esi = *eax[0x915];
    decomp_var_d38 = edi;
    decomp_var_d34 = esi;
    goto loc_44e2d0;

loc_44e2d0:
    eax = ebx[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] != arg_4) {
                    sub_401390();
                    esi = decomp_var_d28;
                    edi = decomp_var_d2c;
                    ebx = decomp_var_d30;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x8] == 0x0) {
                    sub_401390();
                    esi = decomp_var_d28;
                    edi = decomp_var_d2c;
                    ebx = decomp_var_d30;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = sub_463690(&decomp_var_c4c, esi + 0x10);
            esp = esp - 0xc;
            sub_465ff0(eax);
            sub_465fa0();
            if (arg_4 != decomp_var_d24) {
                    eax = sub_466c40(&decomp_var_c54, &decomp_var_c88);
                    esp = esp - 0xc;
                    sub_465ff0(eax);
                    arg_4 = 0x3;
                    sub_465fa0();
                    bool_1871 = esi != decomp_var_d2c[0x1];
                    decomp_var_cf4 = *dword_bb6e04;
                    if (!bool_1871) {
                            sub_47a948();
                    }
                    ebx = esi + 0x10;
                    esp = esp - 0x8;
                    eax = sub_401ff0(&decomp_var_ca8, ebx, decomp_var_d40, decomp_var_d3c, decomp_var_d38);
                    edi = eax;
                    eax = *edi;
                    if (eax == 0x0 || eax != 0xbb6e00) {
                            sub_47a948();
                    }
                    if (edi[0x1] != decomp_var_cf4) {
                            if (esi == decomp_var_d2c[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x8] != 0x2) {
                                    if (esi == decomp_var_d2c[0x1]) {
                                            sub_47a948();
                                    }
                                    if (esi[0x8] != 0x6) {
                                            decomp_var_cf0 = 0x1f4;
                                    }
                            }
                    }
                    eax = arg_4;
                    if (eax != decomp_var_d1c) {
                            sub_401390();
                            esi = decomp_var_d28;
                            edi = decomp_var_d2c;
                            ebx = decomp_var_d30;
                            continue;
                    }
                    bool_1865 = esi != decomp_var_d2c[0x1];
                    edi = (eax + eax * 0x2) * 0x4 + 0xbb69f8;
                    decomp_var_cb4 = edi[0x1];
                    if (!bool_1865) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_402140(&decomp_var_cb0, ebx, decomp_var_d40, decomp_var_d3c, decomp_var_d38);
                    ebx = eax;
                    eax = *ebx;
                    if (eax == 0x0 || eax != edi) {
                            sub_47a948();
                    }
                    if (ebx[0x1] == decomp_var_cb4) {
                            sub_401390();
                            esi = decomp_var_d28;
                            edi = decomp_var_d2c;
                            ebx = decomp_var_d30;
                            continue;
                    }
                    if (esi == decomp_var_d2c[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_402140(&decomp_var_d0c, esi + 0x10, decomp_var_d40, decomp_var_d3c, decomp_var_d38);
                    edi = decomp_var_d2c;
                    bool_1854 = esi != edi[0x1];
                    ecx = eax[0x1];
                    ebx = *eax;
                    decomp_var_cbc = ecx;
                    if (!bool_1854) {
                            sub_47a948();
                    }
                    if (esi[0x8] != 0x2) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x8] == 0x6) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    if (ebx == 0x0) {
                                            sub_47a948();
                                    }
                                    if (decomp_var_cbc == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (esi[0x9] != decomp_var_cbc[0x4]) {
                                            decomp_var_cf0 = 0x2ee;
                                    }
                                    sub_401390();
                                    esi = decomp_var_d28;
                                    edi = decomp_var_d2c;
                                    ebx = decomp_var_d30;
                                    continue;
                            }
                            decomp_var_cf0 = 0x2ee;
                            sub_401390();
                            esi = decomp_var_d28;
                            edi = decomp_var_d2c;
                            ebx = decomp_var_d30;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (ebx == 0x0) {
                            sub_47a948();
                    }
                    if (decomp_var_cbc == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x9] != decomp_var_cbc[0x4]) {
                            decomp_var_cf0 = 0x2ee;
                    }
                    sub_401390();
                    esi = decomp_var_d28;
                    edi = decomp_var_d2c;
                    ebx = decomp_var_d30;
                    continue;
            }
            ebx = (arg_4 + arg_4 * 0x2) * 0x4 + 0xbb66f8;
            eax = ebx[0x1];
            edi = eax[0x1];
            decomp_var_d2c = eax;
            if (edi[0x1d] == 0x0) {
                    do {
                            esp = esp - 0x4;
                            eax = sub_465cf0(&decomp_var_c90);
                            if (eax != 0x0) {
                                    edi = edi[0x2];
                            }
                            else {
                                    decomp_var_d2c = edi;
                                    edi = *edi;
                            }
                    } while (edi[0x1d] == 0x0);
            }
            eax = decomp_var_d28;
            decomp_var_d08 = ebx;
            if (eax != ebx[0x1]) {
                    esp = esp - 0x4;
                    if (sub_465cf0(eax + 0xc) == 0x0) {
                            eax = &decomp_var_d08;
                    }
                    else {
                            decomp_var_d18 = ebx[0x1];
                            decomp_var_d1c = ebx;
                            eax = &decomp_var_d1c;
                    }
            }
            else {
                    decomp_var_d18 = ebx[0x1];
                    decomp_var_d1c = ebx;
                    eax = &decomp_var_d1c;
            }
            ecx = *eax;
            edi = eax[0x1];
            if (ecx == 0x0 || ecx != ebx) {
                    sub_47a948();
            }
            eax = sub_466c40(&decomp_var_c54, &decomp_var_c88);
            esp = esp - 0xc;
            sub_465ff0(eax);
            arg_4 = 0x3;
            sub_465fa0();
            bool_1871 = esi != decomp_var_d2c[0x1];
            decomp_var_cf4 = *dword_bb6e04;
            if (!bool_1871) {
                    sub_47a948();
            }
            ebx = esi + 0x10;
            esp = esp - 0x8;
            eax = sub_401ff0(&decomp_var_ca8, ebx, decomp_var_d40, decomp_var_d3c, decomp_var_d38);
            edi = eax;
            eax = *edi;
            if (eax == 0x0 || eax != 0xbb6e00) {
                    sub_47a948();
            }
            if (edi[0x1] != decomp_var_cf4) {
                    if (esi == decomp_var_d2c[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x8] != 0x2) {
                            if (esi == decomp_var_d2c[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x8] != 0x6) {
                                    decomp_var_cf0 = 0x1f4;
                            }
                    }
            }
            eax = arg_4;
            if (eax != decomp_var_d1c) {
                    sub_401390();
                    esi = decomp_var_d28;
                    edi = decomp_var_d2c;
                    ebx = decomp_var_d30;
                    continue;
            }
            bool_1865 = esi != decomp_var_d2c[0x1];
            edi = (eax + eax * 0x2) * 0x4 + 0xbb69f8;
            decomp_var_cb4 = edi[0x1];
            if (!bool_1865) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_402140(&decomp_var_cb0, ebx, decomp_var_d40, decomp_var_d3c, decomp_var_d38);
            ebx = eax;
            eax = *ebx;
            if (eax == 0x0 || eax != edi) {
                    sub_47a948();
            }
            if (ebx[0x1] == decomp_var_cb4) {
                    sub_401390();
                    esi = decomp_var_d28;
                    edi = decomp_var_d2c;
                    ebx = decomp_var_d30;
                    continue;
            }
            if (esi == decomp_var_d2c[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_402140(&decomp_var_d0c, esi + 0x10, decomp_var_d40, decomp_var_d3c, decomp_var_d38);
            edi = decomp_var_d2c;
            bool_1854 = esi != edi[0x1];
            ecx = eax[0x1];
            ebx = *eax;
            decomp_var_cbc = ecx;
            if (!bool_1854) {
                    sub_47a948();
            }
            if (esi[0x8] != 0x2) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x8] == 0x6) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (ebx == 0x0) {
                                    sub_47a948();
                            }
                            if (decomp_var_cbc == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x9] != decomp_var_cbc[0x4]) {
                                    decomp_var_cf0 = 0x2ee;
                            }
                            sub_401390();
                            esi = decomp_var_d28;
                            edi = decomp_var_d2c;
                            ebx = decomp_var_d30;
                            continue;
                    }
                    decomp_var_cf0 = 0x2ee;
                    sub_401390();
                    esi = decomp_var_d28;
                    edi = decomp_var_d2c;
                    ebx = decomp_var_d30;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (decomp_var_cbc == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x9] != decomp_var_cbc[0x4]) {
                    decomp_var_cf0 = 0x2ee;
            }
            sub_401390();
            esi = decomp_var_d28;
            edi = decomp_var_d2c;
            ebx = decomp_var_d30;
            continue;
    }
    break;
    eax = *dword_bbf60c;
    esi = eax[0x1];
    decomp_var_cd0 = eax;
    edi = eax;
    if (esi[0x629] == 0x0) {
            do {
                    esp = esp - 0x4;
                    eax = sub_465cf0(&decomp_var_c9c);
                    if (eax != 0x0) {
                            esi = esi[0x2];
                    }
                    else {
                            edi = esi;
                            esi = *esi;
                    }
            } while (esi[0x629] == 0x0);
    }
    decomp_var_d04 = 0xbbf608;
    if (edi != *dword_bbf60c) {
            esp = esp - 0x4;
            if (sub_465cf0(edi + 0xc) == 0x0) {
                    eax = &decomp_var_d04;
            }
            else {
                    decomp_var_d18 = 0xbbf608;
                    eax = &decomp_var_d18;
            }
    }
    else {
            decomp_var_d18 = 0xbbf608;
            eax = &decomp_var_d18;
    }
    ecx = *eax;
    esi = eax[0x1];
    if (ecx == 0x0 || ecx != 0xbbf608) {
            sub_47a948();
    }
    if (esi != decomp_var_cc4 || decomp_var_d19 == 0x1) goto loc_44f4f6;
    goto loc_44e68e;

loc_44f4f6:
    sub_465fa0();
    sub_465fa0();
    eax = *decomp_var_cd0;
    *decomp_var_cd0 = decomp_var_cd0;
    decomp_var_cd0[0x1] = decomp_var_cd0;
    ecx = decomp_var_cd0;
    if (eax != ecx) {
            sub_44f540();
    }
    sub_47c8f9();
    sub_4225b0(&decomp_var_ca4, &decomp_var_630, *decomp_var_62c, &decomp_var_630, decomp_var_62c);
    sub_47c8f9();
    *0x0 = arg_0;
    &decomp_var_d2c = ebp;
    return;

loc_44e68e:
    eax = decomp_var_d2c[0x2];
    ebx = eax + 0x2450;
    esi = *eax[0x915];
    decomp_var_d28 = ebx;
    decomp_var_d24 = esi;
    goto loc_44e6b0;

loc_44e6b0:
    eax = decomp_var_d2c[0x2];
    edi = eax[0x915];
    eax = eax + 0x2450;
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi == edi) goto .l117;
    goto loc_44e6d7;

.l117:
    break;

loc_44e6d7:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] == arg_4) {
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x8] != 0x0) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_ce8 = esi[0x8];
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_ce4 = esi[0x9];
                    decomp_var_ce0 = esi[0xa];
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_cd8 = esi[0xc];
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_cdc = esi[0xb];
                    eax = *decomp_var_cd0;
                    *decomp_var_cd0 = decomp_var_cd0;
                    decomp_var_cd0[0x1] = decomp_var_cd0;
                    if (eax != decomp_var_cd0) {
                            edi = *eax;
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                            eax = edi;
                            if (edi != decomp_var_cd0) {
                                    continue;
                            }
                            break;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    eax = esi + 0x34;
                    if (&decomp_var_cd4 != eax) {
                            ecx = eax[0x1];
                            esp = esp - 0x14;
                            sub_4226e0(eax, *ecx, eax, ecx);
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    eax = sub_405d20(&decomp_var_cd4);
                    esp = esp - 0xc;
                    eax = sub_433a20(&decomp_var_ca4, &decomp_var_c74, decomp_var_d3c);
                    eax = *decomp_var_c58;
                    *decomp_var_c58 = decomp_var_c58;
                    decomp_var_c58[0x1] = decomp_var_c58;
                    ecx = decomp_var_c58;
                    if (eax != ecx) {
                            &decomp_var_d3c = &decomp_var_d3c;
                            do {
                                    edi = *eax;
                                    sub_47c8f9();
                                    ecx = decomp_var_c58;
                                    esp = (esp - 0x4) + 0x4;
                                    eax = edi;
                            } while (edi != ecx);
                    }
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
    }
    if (*(int8_t *)byte_baed68 != 0x1) goto loc_44e99f;
    goto loc_44e89e;
    edx = decomp_var_d2c[0x2];
    eax = 0x0;
    if (edx[0x901] > 0x0) {
            ecx = edx;
            do {
                    *(&decomp_var_d3c + eax * 0x4 + 0x2b8) = 0x0;
                    eax = eax + 0x1;
            } while (eax < ecx[0x901]);
    }
    edi = edx + 0x2450;
    esi = *edx[0x915];
    decomp_var_d28 = edi;
    decomp_var_d24 = esi;
    goto loc_44e9fa;

loc_44e99f:
    sub_401390();
    esi = decomp_var_d24;
    ebx = decomp_var_d28;
    goto .l16;

loc_44e89e:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != arg_4) goto loc_44e99f;
    goto loc_44e8b4;

loc_44e9fa:
    ebx = decomp_var_d2c;
    eax = ebx[0x2];
    ecx = eax[0x915];
    eax = eax + 0x2450;
    decomp_var_ca8 = ecx;
    if (edi == 0x0 || edi != eax) {
            eax = sub_47a948();
    }
    if (esi == decomp_var_ca8) goto .l111;
    goto loc_44ea2d;

.l16:
    continue;

loc_44e8b4:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x8] != 0x2) goto loc_44e99f;
    goto loc_44e8c8;

.l111:
    break;

loc_44ea2d:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != arg_4) goto loc_44f15e;
    goto loc_44ea4c;

loc_44e8c8:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    eax = esi[0x9];
    if (*(int8_t *)(decomp_var_d2c[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) != 0x1) goto loc_44e99f;
    goto loc_44e8ea;
    asm { fld1 };
    asm { fcomp      dword [byte_4c6bdc+4] };
    asm { fnstsw     ax };
    if (PARITY(HIBYTE(eax) & 0x44)) goto loc_44f386;
    goto loc_44f187;

loc_44f15e:
    sub_401390();
    esi = decomp_var_d24;
    edi = decomp_var_d28;
    goto .l33;

loc_44ea4c:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x8] == 0x2) goto loc_44ecee;
    goto loc_44ea60;

loc_44e8ea:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    esi = esi[0x9];
    eax = decomp_var_d2c[0x2];
    eax = *(int16_t *)(eax + (esi + esi * 0x8) * 0x4 + 0x20);
    bool_19 = HIBYTE(eax) == 0x41;
    eax = eax & 0xff;
    if (!bool_19) {
            eax = 0x14;
    }
    edx = arg_4;
    if (eax == edx || eax == 0x14) goto loc_44e99f;
    goto loc_44e923;

loc_44f386:
    edi = arg_4;
    esi = 0x0;
    esp = esp - 0x4;
    decomp_var_d40 = edi;
    *(&decomp_var_d40 + edi * 0x4 + 0x2bc) = esi;
    sub_437600(decomp_var_d40, decomp_var_d3c, decomp_var_d38, decomp_var_d34, decomp_var_d30);
    asm { fldz };
    edx = decomp_var_cec;
    asm { fst        dword [esp+0xd3c+-3060] };
    ecx = *dword_633f14;
    asm { fld        dword [dword_value_1176256512] };
    *(edi * 0x4 + 0xb9fe88) = *(edi * 0x4 + 0xb9fe88) + 0x1;
    asm { fstp       dword [esp+0xd3c+-3100] };
    asm { fst        dword [esp+0xd3c+-2696] };
    ecx = ebx[0x2];
    decomp_var_c30 = edi;
    eax = 0x0;
    if (ecx[0x900] > esi) {
            *(&decomp_var_d3c + eax * 0x4 + 0x30c) = 0x0;
            eax = eax + 0x1;
            if (eax < ecx[0x900]) {
                    continue;
            }
            break;
    }
    eax = 0x0;
    do {
            esi = 0x0;
            asm { fst        dword [esp+eax*4+0xd3c+-3056] };
            *(&decomp_var_d3c + eax * 0x4 + 0x1c4) = esi;
            *(&decomp_var_d3c + eax * 0x4 + 0x23c) = esi;
            eax = eax + 0x1;
    } while (eax < 0x1e);
    edx = &decomp_var_c94;
    asm { fstp       st0 };
    sub_465f60(edx);
    sub_446540(&decomp_var_c30);
    eax = sub_44d6c0(&decomp_var_ca4, &decomp_var_620, decomp_var_d3c);
    sub_42ee00();
    esp = esp - 0x14;
    sub_43e370(edi, decomp_var_d3c);
    goto loc_44f4f6;

loc_44f187:
    if (*dword_baed64 == 0x1) {
            edx = ebx[0x2];
            bool_13 = true;
            if (edx[0x900] > 0x0) {
                    asm { rep stosd  dword [edi], eax };
            }
            sub_44f1d0(decomp_var_d3c, decomp_var_d38, decomp_var_d34, decomp_var_d30, decomp_var_d2c, edx + 0x2450, eax, decomp_var_d20, decomp_var_d1c, decomp_var_d18, decomp_var_d14);
    }
    edi = arg_4;
    esi = 0x0;
    esp = esp - 0x4;
    decomp_var_d40 = edi;
    *(&decomp_var_d40 + edi * 0x4 + 0x2bc) = esi;
    sub_437600(decomp_var_d40, decomp_var_d3c, decomp_var_d38, decomp_var_d34, decomp_var_d30);
    asm { fldz };
    edx = decomp_var_cec;
    asm { fst        dword [esp+0xd3c+-3060] };
    ecx = *dword_633f14;
    asm { fld        dword [dword_value_1176256512] };
    *(edi * 0x4 + 0xb9fe88) = *(edi * 0x4 + 0xb9fe88) + 0x1;
    asm { fstp       dword [esp+0xd3c+-3100] };
    asm { fst        dword [esp+0xd3c+-2696] };
    ecx = ebx[0x2];
    decomp_var_c30 = edi;
    eax = 0x0;
    if (ecx[0x900] > esi) {
            *(&decomp_var_d3c + eax * 0x4 + 0x30c) = 0x0;
            eax = eax + 0x1;
            if (eax < ecx[0x900]) {
                    continue;
            }
            break;
    }
    eax = 0x0;
    do {
            esi = 0x0;
            asm { fst        dword [esp+eax*4+0xd3c+-3056] };
            *(&decomp_var_d3c + eax * 0x4 + 0x1c4) = esi;
            *(&decomp_var_d3c + eax * 0x4 + 0x23c) = esi;
            eax = eax + 0x1;
    } while (eax < 0x1e);
    edx = &decomp_var_c94;
    asm { fstp       st0 };
    sub_465f60(edx);
    sub_446540(&decomp_var_c30);
    eax = sub_44d6c0(&decomp_var_ca4, &decomp_var_620, decomp_var_d3c);
    sub_42ee00();
    esp = esp - 0x14;
    sub_43e370(edi, decomp_var_d3c);
    sub_465fa0();
    sub_465fa0();
    eax = *decomp_var_cd0;
    *decomp_var_cd0 = decomp_var_cd0;
    decomp_var_cd0[0x1] = decomp_var_cd0;
    ecx = decomp_var_cd0;
    if (eax != ecx) {
            sub_44f540();
    }
    sub_47c8f9();
    sub_4225b0(&decomp_var_ca4, &decomp_var_630, *decomp_var_62c, &decomp_var_630, decomp_var_62c);
    sub_47c8f9();
    *0x0 = arg_0;
    &decomp_var_d2c = ebp;
    return;

.l33:
    continue;

loc_44ecee:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    esi = esi[0x4];
    asm { fld        dword [byte_4c6bdc+4] };
    ecx = arg_4;
    eax = ecx;
    edx = eax & 0x80000000 ? 0xffffffff : 0x0;
    decomp_var_cf4 = esi * 0x8;
    decomp_var_cfc = edx;
    if (*(esi * 0x8 + 0x4d2610) != eax) goto loc_44edc1;
    goto loc_44ed40;

loc_44ea60:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x8] == 0x6) goto loc_44ecee;
    goto loc_44ea74;

loc_44e923:
    ecx = edx * 0x15 + eax;
    bool_31 = *(ecx * 0x8 + 0x4d552c) < 0x0;
    if (*(ecx * 0x8 + 0x4d552c) > 0x0 || !bool_31 && *(ecx * 0x8 + 0x4d5528) > 0x1) goto loc_44e95e;
    goto loc_44e940;

loc_44edc1:
    asm { fcomp      dword [aWeHaveReceived_4b0d00+36] };
    asm { fnstsw     ax };
    if ((HIBYTE(eax) & 0x41) == 0x0 && *(int8_t *)byte_baed69 == 0x1) {
            eax = (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi;
            edx = *(eax + eax + 0x5460ec);
            esi = *(eax + eax + 0x58f8ec);
            ebx = *(eax + eax + 0x5460e8);
            edi = *(eax + eax + 0x58f8e8);
            eax = eax + eax;
            bool_70 = edx > esi;
            if (edx >= esi) {
                    if (!bool_70) {
                            if (ebx > edi) {
                                    ecx = eax[0x15963a];
                                    eax = eax[0x15963b];
                                    ecx = ecx + edi;
                                    bool_94 = edx < eax + esi + CARRY(EFLAGS(cf));
                                    if (edx <= eax + esi + CARRY(EFLAGS(cf))) {
                                            if (!bool_94) {
                                                    if (ebx <= ecx) {
                                                            decomp_var_c00 = decomp_var_c00 + 0x32;
                                                    }
                                            }
                                            else {
                                                    decomp_var_c00 = decomp_var_c00 + 0x32;
                                            }
                                    }
                            }
                    }
                    else {
                            ecx = eax[0x15963a];
                            eax = eax[0x15963b];
                            ecx = ecx + edi;
                            bool_94 = edx < eax + esi + CARRY(EFLAGS(cf));
                            if (edx <= eax + esi + CARRY(EFLAGS(cf))) {
                                    if (!bool_94) {
                                            if (ebx <= ecx) {
                                                    decomp_var_c00 = decomp_var_c00 + 0x32;
                                            }
                                    }
                                    else {
                                            decomp_var_c00 = decomp_var_c00 + 0x32;
                                    }
                            }
                    }
            }
    }
    goto loc_44ee2c;

loc_44ed40:
    eax = decomp_var_cf4[0x134985];
    if (eax != edx || *(int8_t *)byte_baed69 != 0x1) goto loc_44edc1;
    goto loc_44ed57;

loc_44ea74:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x8] != 0x4) goto loc_44eb72;
    goto loc_44ea88;

loc_44e95e:
    eax = eax * 0x15 + edx;
    bool_45 = *(eax * 0x8 + 0x4d552c) > 0x0;
    bool_43 = *(eax * 0x8 + 0x4d552c) < 0x0;
    if (bool_45) goto loc_44e997;
    goto loc_44e96d;

loc_44e940:
    decomp_var_d0c = 0x32;
    sub_401390();
    esi = decomp_var_d24;
    ebx = decomp_var_d28;
    goto .l15;

loc_44ee2c:
    decomp_var_d1c = 0x0;
    if (*(decomp_var_d28[0x2] + 0x2404) <= 0x0) goto loc_44f15e;
    goto loc_44ee48;

loc_44ed57:
    asm { fld        dword [aWeAreCloseToEl+60] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (PARITY(HIBYTE(eax) & 0x5)) goto loc_44edc1;
    goto loc_44ed66;

loc_44eb72:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x8] != 0x3) goto loc_44ec43;
    goto loc_44eb86;

loc_44ea88:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    bool_93 = esi != edi[0x1];
    ebx = esi[0xc];
    if (!bool_93) {
            sub_47a948();
    }
    eax = decomp_var_d2c;
    edx = eax[0x2];
    esi = esi[0x4];
    ecx = 0x0;
    if (edx[0x901] <= 0x0) goto loc_44f15e;
    goto loc_44eab7;

loc_44e997:
    decomp_var_d0c = 0x96;
    goto loc_44e99f;

loc_44e96d:
    if (bool_43) goto loc_44e979;
    goto loc_44e96f;

.l15:
    continue;

loc_44ee48:
    decomp_var_d14 = decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04;
    decomp_var_cf0 = decomp_var_cf0;
    goto loc_44ee60;

loc_44ed66:
    edx = *((ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + 0x5460e8);
    edi = *((ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + 0x58f8ec);
    ebx = *((ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + 0x58f8e8);
    eax = (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi + (ecx << 0x8) + esi;
    decomp_var_cc8 = edx;
    edx = eax[0x15183b];
    bool_65 = edx > edi;
    if (edx < edi) goto loc_44edc1;
    goto loc_44ed96;

loc_44ec43:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x8] == 0x1) goto loc_44ec67;
    goto loc_44ec53;

loc_44eb86:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    bool_92 = esi != edi[0x1];
    ebx = esi[0xb];
    decomp_var_d08 = ebx;
    if (!bool_92) {
            sub_47a948();
    }
    eax = decomp_var_d2c;
    edx = eax[0x2];
    esi = esi[0x4];
    ecx = 0x0;
    if (edx[0x901] <= 0x0) goto loc_44f15e;
    goto loc_44ebb9;

loc_44eab7:
    decomp_var_d18 = eax[0x2];
    edx = esi * 0x8;
    eax = ebx * 0x8;
    goto loc_44eacc;

loc_44e979:
    decomp_var_d0c = 0x6e;
    sub_401390();
    esi = decomp_var_d24;
    ebx = decomp_var_d28;
    goto .l15;

loc_44e96f:
    if (*(eax * 0x8 + 0x4d5528) <= 0x1) {
            decomp_var_d0c = 0x6e;
            sub_401390();
            esi = decomp_var_d24;
            ebx = decomp_var_d28;
            continue;
    }
    decomp_var_d0c = 0x96;
    sub_401390();
    esi = decomp_var_d24;
    ebx = decomp_var_d28;
    goto .l16;

loc_44ee60:
    eax = decomp_var_d14;
    bool_463 = eax[0x163e3b] > 0x0;
    bool_358 = eax[0x163e3b] < 0x0;
    if (bool_463 || !bool_358 && eax[0x163e3a] > 0x0) goto loc_44f0e6;
    goto loc_44ee80;

loc_44ed96:
    if (bool_65 || decomp_var_cc8 > ebx) goto loc_44ed9e;
    goto loc_44edbe;

loc_44ec67:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    edx = decomp_var_d2c;
    eax = edx[0x2];
    esi = esi[0x4];
    ecx = 0x0;
    if (eax[0x901] <= 0x0) goto loc_44f15e;
    goto loc_44ec89;

loc_44ec53:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x8] != 0x5) goto loc_44f15e;
    goto loc_44ec67;

loc_44ebb9:
    edi = eax[0x2];
    edx = ebx * 0x8 + 0x5c48e8;
    eax = esi * 0x8;
    goto loc_44ebd0;

loc_44eacc:
    bool_117 = edx[0x163e3b] > 0x0;
    if (edx[0x163e3b] < 0x0 || !bool_117 && edx[0x163e3a] <= 0x0) goto loc_44eae0;
    goto .l30;

loc_44f0e6:
    esi = decomp_var_d20;
    if (esi == decomp_var_d24[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_d3c = esi + 0x24;
    *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + *sub_41c1e0(decomp_var_d3c) + decomp_var_cb0 + decomp_var_d04 + 0x3e8;
    goto loc_44f133;

loc_44ee80:
    ecx = decomp_var_cf0;
    bool_361 = ecx[0x163e3b] < 0x0;
    if (ecx[0x163e3b] > 0x0 || !bool_361 && ecx[0x163e3a] > 0x0) goto loc_44f0e6;
    goto loc_44eea0;

loc_44ed9e:
    ecx = eax[0x15963a];
    eax = eax[0x15963b];
    ecx = ecx + ebx;
    eax = eax + edi + CARRY(EFLAGS(cf));
    bool_68 = edx < eax;
    if (edx > eax || !bool_68 && decomp_var_cc8 > ecx) goto loc_44edbe;
    goto loc_44edba;

loc_44edbe:
    ecx = arg_4;
    goto loc_44edc1;

loc_44ec89:
    edx = edx[0x2];
    eax = esi * 0x8;
    goto loc_44ec93;

loc_44ebd0:
    bool_1841 = eax[0x163e3b] < 0x0;
    if (eax[0x163e3b] > 0x0 || !bool_1841 && eax[0x163e3a] > 0x0) goto loc_44ec05;
    goto loc_44ebe4;

loc_44eae0:
    bool_103 = eax[0x173c3b] > 0x0;
    bool_102 = eax[0x173c3b] < 0x0;
    if (bool_103 || !bool_102 && eax[0x173c3a] > 0x0) goto .l30;
    goto loc_44eaf4;

.l30:
    *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) = *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) + esi + ebx + 0x7d0;
    goto loc_44eb3e;

loc_44f133:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_127 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_127) {
            continue;
    }
    break;

loc_44eea0:
    bool_411 = eax[0x173c3b] > 0x0;
    bool_214 = eax[0x173c3b] < 0x0;
    if (bool_411 || !bool_214 && eax[0x173c3a] > 0x0) goto .l192;
    goto loc_44eebc;

loc_44edba:
    asm { fstp       st0 };
    decomp_var_c00 = decomp_var_c00 + 0x32;
    goto loc_44ee2c;

loc_44ec93:
    bool_1852 = eax[0x163e3b] < 0x0;
    if (eax[0x163e3b] > 0x0) goto loc_44ecbb;
    goto loc_44ec9c;

loc_44ec05:
    *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) = *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) + esi + ebx + 0xbb8;
    ebx = decomp_var_d08;
    goto loc_44ec17;

loc_44ebe4:
    bool_1838 = edx[0x1] > 0x0;
    bool_1836 = edx[0x1] < 0x0;
    if (bool_1838) goto loc_44ec05;
    goto loc_44ebea;

loc_44eaf4:
    bool_115 = eax[0x17123b] > 0x0;
    bool_114 = eax[0x17123b] < 0x0;
    if (bool_115 || !bool_114 && eax[0x17123a] > 0x0) goto .l30;
    goto loc_44eb08;

loc_44eb3e:
    ecx = ecx + 0x1;
    eax = eax + 0x800;
    edx = edx + 0x800;
    if (ecx < decomp_var_d18[0x901]) {
            continue;
    }
    break;

.l192:
    esi = decomp_var_d20;
    if (esi == decomp_var_d24[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_d3c = esi + 0x24;
    ecx = arg_4 + arg_4 * 0x2;
    *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
    goto loc_44f133;

loc_44eebc:
    bool_219 = eax[0x17123b] < 0x0;
    if (eax[0x17123b] > 0x0 || !bool_219 && eax[0x17123a] > 0x0) goto .l192;
    goto loc_44eed8;

loc_44ecbb:
    *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) = *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) + esi + 0xfa0;
    goto loc_44ecc8;

loc_44ec9c:
    if (bool_1852 || eax[0x163e3a] <= 0x0) goto loc_44eca7;
    goto .l45;

loc_44ec17:
    ecx = ecx + 0x1;
    edx = edx + 0x800;
    eax = eax + 0x800;
    if (ecx < edi[0x901]) {
            continue;
    }
    break;

loc_44ebea:
    if (bool_1836 || *edx <= 0x0) goto loc_44ebf1;
    goto .l41;

loc_44eb08:
    bool_112 = eax[0x16e83b] > 0x0;
    bool_110 = eax[0x16e83b] < 0x0;
    if (bool_112) goto .l30;
    goto loc_44eb11;
    sub_401390();
    esi = decomp_var_d24;
    edi = decomp_var_d28;
    goto .l33;

loc_44eed8:
    bool_446 = ecx[0x17123b] < 0x0;
    if (ecx[0x17123b] > 0x0) goto .l192;
    goto loc_44eee5;

loc_44ecc8:
    ecx = ecx + 0x1;
    eax = eax + 0x800;
    if (ecx < edx[0x901]) {
            continue;
    }
    break;

loc_44eca7:
    bool_1853 = eax[0x16e83b] < 0x0;
    bool_1849 = eax[0x16e83b] > 0x0;
    if (!bool_1853) {
            if (!bool_1849) {
                    if (eax[0x16e83a] > 0x0) {
                            *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) = *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) + esi + 0xfa0;
                    }
            }
            else {
                    *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) = *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) + esi + 0xfa0;
            }
    }
    goto loc_44ecc8;

.l45:
    *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) = *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) + esi + 0xfa0;
    ecx = ecx + 0x1;
    eax = eax + 0x800;
    if (ecx < edx[0x901]) {
            continue;
    }
    break;
    sub_401390();
    esi = decomp_var_d24;
    edi = decomp_var_d28;
    goto .l33;

loc_44ebf1:
    bool_1845 = eax[0x16e83b] < 0x0;
    bool_1844 = eax[0x16e83b] > 0x0;
    if (!bool_1845) {
            if (!bool_1844) {
                    if (eax[0x16e83a] > 0x0) {
                            *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) = *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) + esi + ebx + 0xbb8;
                            ebx = decomp_var_d08;
                    }
            }
            else {
                    *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) = *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) + esi + ebx + 0xbb8;
                    ebx = decomp_var_d08;
            }
    }
    goto loc_44ec17;

.l41:
    *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) = *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) + esi + ebx + 0xbb8;
    ebx = decomp_var_d08;
    ecx = ecx + 0x1;
    edx = edx + 0x800;
    eax = eax + 0x800;
    if (ecx < edi[0x901]) {
            continue;
    }
    break;

loc_44eb11:
    if (bool_110 || eax[0x16e83a] <= 0x0) goto loc_44eb1c;
    goto .l29;

loc_44eee5:
    if (bool_446) goto .l122;
    goto loc_44eee7;
    sub_401390();
    esi = decomp_var_d24;
    edi = decomp_var_d28;
    continue;

loc_44eb1c:
    bool_108 = edx[0x16e83b] < 0x0;
    bool_107 = edx[0x16e83b] > 0x0;
    if (!bool_108) {
            if (!bool_107) {
                    if (edx[0x16e83a] > 0x0) {
                            *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) = *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) + esi + ebx + 0x7d0;
                    }
            }
            else {
                    *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) = *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) + esi + ebx + 0x7d0;
            }
    }
    goto loc_44eb3e;

.l29:
    *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) = *(&decomp_var_d3c + ecx * 0x4 + 0x2b8) + esi + ebx + 0x7d0;
    ecx = ecx + 0x1;
    eax = eax + 0x800;
    edx = edx + 0x800;
    if (ecx < decomp_var_d18[0x901]) {
            continue;
    }
    break;

.l122:
    bool_320 = ecx[0x16e83b] > 0x0;
    bool_253 = ecx[0x16e83b] < 0x0;
    if (bool_320) goto .l192;
    goto loc_44ef01;

loc_44eee7:
    if (ecx[0x17123a] > 0x0) goto .l61;
    goto loc_44eef4;

loc_44ef01:
    if (bool_253) goto loc_44ef10;
    goto .l187;

.l61:
    esi = decomp_var_d20;
    if (esi == decomp_var_d24[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_d3c = esi + 0x24;
    ecx = arg_4 + arg_4 * 0x2;
    *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_209 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_209) {
            continue;
    }
    break;

loc_44eef4:
    bool_400 = ecx[0x16e83b] < 0x0;
    if (ecx[0x16e83b] > 0x0) goto .l62;
    goto .l177;

loc_44ef10:
    bool_268 = eax[0x16e83b] > 0x0;
    bool_134 = eax[0x16e83b] < 0x0;
    if (bool_268) goto .l56;
    goto loc_44ef1d;

.l187:
    if (ecx[0x16e83a] > 0x0) goto .l63;
    goto .l229;

.l62:
    esi = decomp_var_d20;
    if (esi == decomp_var_d24[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_d3c = esi + 0x24;
    ecx = arg_4 + arg_4 * 0x2;
    *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_524 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_524) {
            continue;
    }
    break;

.l177:
    if (bool_400) goto .l124;
    goto loc_44ef03;

.l56:
    esi = decomp_var_d20;
    if (esi == decomp_var_d24[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_d3c = esi + 0x24;
    ecx = arg_4 + arg_4 * 0x2;
    *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_421 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_421) {
            continue;
    }
    break;

loc_44ef1d:
    if (bool_134) goto .l98;
    goto .l237;

.l63:
    esi = decomp_var_d20;
    if (esi == decomp_var_d24[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_d3c = esi + 0x24;
    ecx = arg_4 + arg_4 * 0x2;
    *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_308 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_308) {
            continue;
    }
    break;

.l229:
    bool_475 = eax[0x16e83b] > 0x0;
    bool_467 = eax[0x16e83b] < 0x0;
    if (bool_475) goto .l64;
    goto .l226;

.l124:
    bool_518 = eax[0x16e83b] < 0x0;
    if (eax[0x16e83b] > 0x0) goto .l81;
    goto .l247;

loc_44ef03:
    if (ecx[0x16e83a] > 0x0) goto .l270;
    goto .l89;

.l98:
    esi = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e14);
    ecx = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e10);
    bool_171 = esi > 0x0;
    if (esi < 0x0) goto .l216;
    goto .l23;

.l237:
    if (eax[0x16e83a] > 0x0) goto loc_44f0c8;
    goto .l44;

.l64:
    esi = decomp_var_d20;
    if (esi == decomp_var_d24[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_d3c = esi + 0x24;
    ecx = arg_4 + arg_4 * 0x2;
    *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_196 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_196) {
            continue;
    }
    break;

.l226:
    if (bool_467) goto .l24;
    goto loc_44ef1f;

.l81:
    esi = decomp_var_d20;
    if (esi == decomp_var_d24[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_d3c = esi + 0x24;
    ecx = arg_4 + arg_4 * 0x2;
    *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_535 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_535) {
            continue;
    }
    break;

.l247:
    if (bool_518) goto loc_44ef2c;
    goto .l38;

.l270:
    esi = decomp_var_d20;
    if (esi == decomp_var_d24[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_d3c = esi + 0x24;
    ecx = arg_4 + arg_4 * 0x2;
    *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_488 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_488) {
            continue;
    }
    break;

.l89:
    bool_271 = eax[0x16e83b] > 0x0;
    bool_224 = eax[0x16e83b] < 0x0;
    if (bool_271) goto .l112;
    goto .l55;

.l216:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_553 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_553) {
            continue;
    }
    break;

.l23:
    if (bool_171) goto .l113;
    goto .l174;

loc_44f0c8:
    esi = decomp_var_d20;
    if (esi == decomp_var_d24[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_d3c = esi + 0x24;
    ecx = arg_4 + arg_4 * 0x2;
    *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_120 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_120) {
            continue;
    }
    break;

.l44:
    esi = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e14);
    ecx = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e10);
    bool_534 = esi > 0x0;
    if (esi < 0x0) goto .l172;
    goto .l256;

.l24:
    esi = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e14);
    ecx = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e10);
    bool_501 = esi > 0x0;
    if (esi < 0x0) goto .l244;
    goto .l239;

loc_44ef1f:
    if (eax[0x16e83a] > 0x0) goto .l144;
    goto .l34;

loc_44ef2c:
    esi = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e14);
    ecx = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e10);
    bool_460 = esi > 0x0;
    if (esi < 0x0) goto .l42;
    goto .l222;

.l38:
    if (eax[0x16e83a] > 0x0) goto .l251;
    goto .l142;

.l112:
    esi = decomp_var_d20;
    if (esi == decomp_var_d24[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_d3c = esi + 0x24;
    ecx = arg_4 + arg_4 * 0x2;
    *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_453 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_453) {
            continue;
    }
    break;

.l55:
    if (bool_224) goto .l189;
    goto .l156;

.l113:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l60;
    goto .l178;

.l174:
    if (ecx < 0x0) goto .l27;
    goto .l206;

.l172:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_484 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_484) {
            continue;
    }
    break;

.l256:
    if (bool_534) goto .l59;
    goto .l103;

.l244:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_184 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_184) {
            continue;
    }
    break;

.l239:
    if (bool_501) goto .l31;
    goto .l218;

.l144:
    esi = decomp_var_d20;
    if (esi == decomp_var_d24[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_d3c = esi + 0x24;
    ecx = arg_4 + arg_4 * 0x2;
    *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_193 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_193) {
            continue;
    }
    break;

.l34:
    esi = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e14);
    ecx = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e10);
    bool_197 = esi > 0x0;
    if (esi < 0x0) goto .l95;
    goto .l36;

.l42:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_328 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_328) {
            continue;
    }
    break;

.l222:
    if (bool_460) goto .l28;
    goto loc_44ef4e;

.l251:
    esi = decomp_var_d20;
    if (esi == decomp_var_d24[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_d3c = esi + 0x24;
    ecx = arg_4 + arg_4 * 0x2;
    *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_494 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_494) {
            continue;
    }
    break;

.l142:
    esi = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e14);
    ecx = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e10);
    bool_230 = esi > 0x0;
    if (esi < 0x0) goto .l127;
    goto .l69;

.l189:
    esi = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e14);
    ecx = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e10);
    bool_122 = esi > 0x0;
    if (esi < 0x0) goto .l167;
    goto loc_44ef4c;

.l156:
    if (eax[0x16e83a] > 0x0) goto .l240;
    goto .l25;

.l60:
    if (ecx != decomp_var_cfc) goto .l74;
    goto .l88;

.l178:
    if (esi == edx) goto .l32;
    goto .l140;

.l27:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_300 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_300) {
            continue;
    }
    break;

.l206:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l153;
    goto .l20;

.l59:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto loc_44ef67;
    goto .l96;

.l103:
    if (ecx < 0x0) goto .l250;
    goto .l163;

.l31:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l266;
    goto .l83;

.l218:
    if (ecx < 0x0) goto .l51;
    goto .l234;

.l95:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_129 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_129) {
            continue;
    }
    break;

.l36:
    if (bool_197) goto .l46;
    goto .l78;

.l28:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l105;
    goto .l204;

loc_44ef4e:
    if (ecx < 0x0) goto .l170;
    goto loc_44ef56;

.l127:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_427 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_427) {
            continue;
    }
    break;

.l69:
    if (bool_230) goto .l151;
    goto .l93;

.l167:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_472 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_472) {
            continue;
    }
    break;

loc_44ef4c:
    if (bool_122) goto .l118;
    goto .l125;

.l240:
    esi = decomp_var_d20;
    if (esi == decomp_var_d24[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_d3c = esi + 0x24;
    ecx = arg_4 + arg_4 * 0x2;
    *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_384 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_384) {
            continue;
    }
    break;

.l25:
    esi = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e14);
    ecx = *(decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + decomp_var_d04 + 0x4d2e10);
    bool_301 = esi > 0x0;
    if (esi < 0x0) goto .l79;
    goto .l107;

.l74:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l315;

.l88:
    if (esi == decomp_var_cf8) goto .l53;
    goto .l58;

.l32:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_272 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_272) {
            continue;
    }
    break;

.l140:
    if (ecx != decomp_var_cfc) goto .l147;
    goto .l19;

.l153:
    if (ecx != decomp_var_cfc) goto .l166;
    goto .l232;

.l20:
    if (esi == edx) goto .l190;
    goto .l260;

loc_44ef67:
    if (ecx != decomp_var_cfc) goto .l17;
    goto .l146;

.l96:
    if (esi == edx) goto .l210;
    goto .l54;

.l250:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_202 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_202) {
            continue;
    }
    break;

.l163:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l85;
    goto .l243;

.l266:
    if (ecx != decomp_var_cfc) goto .l5;
    goto .l263;

.l83:
    if (esi == edx) goto .l141;
    goto .l37;

.l51:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_369 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_369) {
            continue;
    }
    break;

.l234:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l201;
    goto loc_44ef5f;

.l46:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l75;
    goto .l200;

.l78:
    if (ecx < 0x0) goto .l65;
    goto .l219;

.l105:
    if (ecx != decomp_var_cfc) goto .l128;
    goto .l123;

.l204:
    if (esi == edx) goto .l242;
    goto .l48;

.l170:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_478 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_478) {
            continue;
    }
    break;

loc_44ef56:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l265;
    goto .l158;

.l151:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l91;
    goto .l133;

.l93:
    if (ecx < 0x0) goto .l100;
    goto .l109;

.l118:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l252;
    goto .l268;

.l125:
    if (ecx < 0x0) goto .l245;
    goto .l154;

.l79:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_273 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_273) {
            continue;
    }
    break;

.l107:
    if (bool_301) goto .l257;
    goto .l21;

.l315:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_965 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_965) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_969 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_969) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_966 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_966) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l316;

.l53:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_545 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_545) {
            continue;
    }
    break;

.l58:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l313;

.l147:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l379;

.l19:
    if (esi == decomp_var_cf8) goto .l87;
    goto .l155;

.l166:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l296;

.l232:
    if (esi == decomp_var_cf8) goto .l152;
    goto .l214;

.l190:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_476 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_476) {
            continue;
    }
    break;

.l260:
    if (ecx != decomp_var_cfc) goto loc_44ef77;
    goto .l169;

.l17:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l368;

.l146:
    if (esi == decomp_var_cf8) goto .l43;
    goto .l110;

.l210:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_144 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_144) {
            continue;
    }
    break;

.l54:
    if (ecx != decomp_var_cfc) goto .l71;
    goto .l195;

.l85:
    if (ecx != decomp_var_cfc) goto .l92;
    goto .l199;

.l243:
    if (esi == edx) goto .l182;
    goto .l217;

.l5:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l334;

.l263:
    if (esi == decomp_var_cf8) goto .l3;
    goto .l186;

.l141:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_416 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_416) {
            continue;
    }
    break;

.l37:
    if (ecx != decomp_var_cfc) goto .l47;
    goto .l119;

.l201:
    if (ecx != decomp_var_cfc) goto .l207;
    goto .l9;

loc_44ef5f:
    if (esi == edx) goto .l181;
    goto .l254;

.l75:
    if (ecx != decomp_var_cfc) goto .l8;
    goto .l197;

.l200:
    if (esi == edx) goto .l145;
    goto .l262;

.l65:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_401 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_401) {
            continue;
    }
    break;

.l219:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l114;
    goto .l246;

.l128:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l312;

.l123:
    if (esi == decomp_var_cf8) goto .l26;
    goto .l149;

.l242:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_139 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_139) {
            continue;
    }
    break;

.l48:
    if (ecx != decomp_var_cfc) goto .l68;
    goto .l227;

.l265:
    if (ecx != decomp_var_cfc) goto .l4;
    goto .l57;

.l158:
    if (esi == edx) goto .l52;
    goto .l115;

.l91:
    if (ecx != decomp_var_cfc) goto .l102;
    goto .l228;

.l133:
    if (esi == edx) goto .l208;
    goto .l82;

.l100:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_382 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_382) {
            continue;
    }
    break;

.l109:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l235;
    goto .l148;

.l252:
    if (ecx != decomp_var_cfc) goto .l215;
    goto .l230;

.l268:
    if (esi == edx) goto .l213;
    goto .l135;

.l245:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_220 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_220) {
            continue;
    }
    break;

.l154:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l94;
    goto .l18;

.l257:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l12;
    goto .l176;

.l21:
    if (ecx < 0x0) goto .l129;
    goto .l136;

.l316:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_192 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_192) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_207 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_207) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l313:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_951 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_937 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_951) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_937) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_945 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_945) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_954 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_954) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l314;

.l379:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1606 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1596 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1606) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1596) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1605 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1605) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1604 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1604) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l380;

.l87:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_251 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_251) {
            continue;
    }
    break;

.l155:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l352;

.l296:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_772 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_772) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_755 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_755) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_771 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_771) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l295;

.l152:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_350 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_350) {
            continue;
    }
    break;

.l214:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l303;

loc_44ef77:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l298;

.l169:
    if (esi == decomp_var_cf8) goto .l73;
    goto .l139;

.l368:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1492 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1492) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1480 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1480) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1488 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1488) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l367;

.l43:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_191 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_191) {
            continue;
    }
    break;

.l110:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l376;

.l71:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l387;

.l195:
    if (esi == decomp_var_cf8) goto .l35;
    goto .l101;

.l92:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l366;

.l199:
    if (esi == decomp_var_cf8) goto .l203;
    goto .l168;

.l182:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_396 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_396) {
            continue;
    }
    break;

.l217:
    if (ecx != decomp_var_cfc) goto .l224;
    goto .l162;

.l334:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1146 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1146) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1142 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1142) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1147 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1147) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l333;

.l3:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_145 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_145) {
            continue;
    }
    break;

.l186:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l381;

.l47:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l283;

.l119:
    if (esi == decomp_var_cf8) goto .l10;
    goto .l80;

.l207:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l319;

.l9:
    if (esi == decomp_var_cf8) goto .l212;
    goto .l258;

.l181:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_465 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_465) {
            continue;
    }
    break;

.l254:
    if (ecx != decomp_var_cfc) goto .l264;
    goto .l159;

.l8:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l318;

.l197:
    if (esi == decomp_var_cf8) goto .l165;
    goto .l86;

.l145:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_169 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_169) {
            continue;
    }
    break;

.l262:
    if (ecx != decomp_var_cfc) goto .l97;
    goto .l138;

.l114:
    if (ecx != decomp_var_cfc) goto .l261;
    goto .l108;

.l246:
    if (esi == edx) goto .l255;
    goto .l22;

.l312:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_932 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_932) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_931 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_931) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_920 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_920) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l311;

.l26:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_264 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_264) {
            continue;
    }
    break;

.l149:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l372;

.l68:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l324;

.l227:
    if (esi == decomp_var_cf8) goto .l191;
    goto .l6;

.l4:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l386;

.l57:
    if (esi == decomp_var_cf8) goto .l188;
    goto .l185;

.l52:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_239 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_239) {
            continue;
    }
    break;

.l115:
    if (ecx != decomp_var_cfc) goto .l131;
    goto loc_44ef6d;

.l102:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l364;

.l228:
    if (esi == decomp_var_cf8) goto .l184;
    goto .l209;

.l208:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_200 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_200) {
            continue;
    }
    break;

.l82:
    if (ecx != decomp_var_cfc) goto .l90;
    goto .l193;

.l235:
    if (ecx != decomp_var_cfc) goto .l157;
    goto .l223;

.l148:
    if (esi == edx) goto .l76;
    goto .l267;

.l215:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l306;

.l230:
    if (esi == decomp_var_cf8) goto .l238;
    goto .l49;

.l213:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_337 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_337) {
            continue;
    }
    break;

.l135:
    if (ecx != decomp_var_cfc) goto .l84;
    goto .l241;

.l94:
    if (ecx != decomp_var_cfc) goto .l106;
    goto .l211;

.l18:
    if (esi == edx) goto .l259;
    goto .l99;

.l12:
    if (ecx != decomp_var_cfc) goto .l116;
    goto .l233;

.l176:
    if (esi == edx) goto .l171;
    goto .l180;

.l129:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_143 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_143) {
            continue;
    }
    break;

.l136:
    edx = decomp_var_d1c & 0x80000000 ? 0xffffffff : 0x0;
    if (ecx != decomp_var_d1c) goto .l202;
    goto .l220;

.l314:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_187 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_187) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_517 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_517) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l380:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_309 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_309) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_355 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_355) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l352:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1334 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1322 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1334) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1322) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1319 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1319) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1321 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1321) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l351;

.l295:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_338 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_338) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_158 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_158) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l303:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_854 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_849 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_854) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_849) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_848 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_848) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_842 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_842) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l304;

.l298:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_790 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_790) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_775 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_775) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_781 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_781) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l297;

.l73:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_449 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_449) {
            continue;
    }
    break;

.l139:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l370;

.l367:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_548 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_548) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_243 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_243) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l376:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1570 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1570) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1564 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1564) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1556 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1556) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l375;

.l387:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1694 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1694) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1676 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1676) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1691 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1691) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l388;

.l35:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_175 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_175) {
            continue;
    }
    break;

.l101:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l277;

.l366:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1468 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1456 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1468) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1456) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1455 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1455) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1459 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1459) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l365;

.l203:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_413 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_413) {
            continue;
    }
    break;

.l168:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l357;

.l224:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l307;

.l162:
    if (esi == decomp_var_cf8) goto .l67;
    goto .l134;

.l333:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_521 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_521) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_172 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_172) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l381:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1630 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1630) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1633 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1633) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1626 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1626) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l382;

.l283:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_651 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_651) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_647 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_647) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_635 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_635) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l284;

.l10:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_374 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_374) {
            continue;
    }
    break;

.l80:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l294;

.l319:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1005 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1005) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1014 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1014) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1013 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1013) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l320;

.l212:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_435 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_435) {
            continue;
    }
    break;

.l258:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l337;

.l264:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l389;

.l159:
    if (esi == decomp_var_cf8) goto .l66;
    goto .l132;

.l318:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_980 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_979 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_980) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_979) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_981 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_981) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_987 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_987) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l317;

.l165:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_333 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_333) {
            continue;
    }
    break;

.l86:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l355;

.l97:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l322;

.l138:
    if (esi == decomp_var_cf8) goto .l104;
    goto .l173;

.l261:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l325;

.l108:
    if (esi == decomp_var_cf8) goto .l249;
    goto .l14;

.l255:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_265 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_265) {
            continue;
    }
    break;

.l22:
    if (ecx != decomp_var_cfc) goto .l130;
    goto .l236;

.l311:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_364 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_364) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_248 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_248) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l372:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1533 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1533) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1529 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1529) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1520 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1520) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l371;

.l324:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1047 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1039 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1047) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1039) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1041 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1041) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1054 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1054) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l323;

.l191:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_394 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_394) {
            continue;
    }
    break;

.l6:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l336;

.l386:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1666 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1662 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1666) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1662) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1667 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1667) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1665 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1665) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l385;

.l188:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_502 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_502) {
            continue;
    }
    break;

.l185:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto loc_44efc0;

.l131:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l399;

loc_44ef6d:
    if (esi == decomp_var_cf8) goto .l164;
    goto .l248;

.l364:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1451 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1445 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1451) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1445) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1453 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1453) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1449 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1449) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l363;

.l184:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_387 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_387) {
            continue;
    }
    break;

.l209:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l393;

.l90:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l288;

.l193:
    if (esi == decomp_var_cf8) goto .l137;
    goto .l198;

.l157:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l330;

.l223:
    if (esi == decomp_var_cf8) goto .l273;
    goto .l194;

.l76:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_310 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_310) {
            continue;
    }
    break;

.l267:
    if (ecx != decomp_var_cfc) goto .l225;
    goto .l120;

.l306:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_871 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_871) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_855 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_855) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_870 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_870) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l305;

.l238:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_537 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_537) {
            continue;
    }
    break;

.l49:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l349;

.l84:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l383;

.l241:
    if (esi == decomp_var_cf8) goto .l231;
    goto .l121;

.l106:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l331;

.l211:
    if (esi == decomp_var_cf8) goto .l183;
    goto .l11;

.l259:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_526 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_526) {
            continue;
    }
    break;

.l99:
    if (ecx != decomp_var_cfc) goto .l39;
    goto .l70;

.l116:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l343;

.l233:
    if (esi == decomp_var_cf8) goto .l271;
    goto .l275;

.l171:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_162 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_162) {
            continue;
    }
    break;

.l180:
    if (ecx != decomp_var_cfc) goto .l13;
    goto .l161;

.l202:
    if (ecx != decomp_var_cfc) goto .l179;
    goto .l253;

.l220:
    if (esi == edx) goto .l150;
    goto .l7;

.l351:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_341 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_341) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_221 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_221) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l304:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_419 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_419) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_318 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_318) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l297:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_515 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_515) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_503 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_503) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l370:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1512 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1512) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1508 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1508) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1513 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1513) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l369;

.l375:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_270 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_270) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_147 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_147) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l388:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_186 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_186) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_525 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_525) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l277:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_594 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_594) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_591 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_591) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_586 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_586) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l278;

.l365:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_232 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_232) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_151 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_151) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l357:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1388 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1388) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1394 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1394) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1390 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1390) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l358;

.l307:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_884 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_884) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_893 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_893) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_877 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_877) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l308;

.l67:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_159 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_159) {
            continue;
    }
    break;

.l134:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l302;

.l382:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_439 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_439) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_404 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_404) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l284:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_447 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_447) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_440 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_440) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l294:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_752 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_752) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_741 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_741) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_745 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_745) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l293;

.l320:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_398 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_398) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_455 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_455) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l337:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1192 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1192) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1194 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1194) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1193 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1193) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l338;

.l389:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1706 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1706) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1704 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1704) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1702 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1702) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l390;

.l66:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_540 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_540) {
            continue;
    }
    break;

.l132:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l328;

.l317:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_212 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_212) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_514 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_514) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l355:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1371 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1371) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1358 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1358) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1357 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1357) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l356;

.l322:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1033 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1033) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1031 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1031) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1015 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1015) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l321;

.l104:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_281 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_281) {
            continue;
    }
    break;

.l173:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l339;

.l325:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1067 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1067) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1064 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1064) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1071 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1071) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l326;

.l249:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_507 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_507) {
            continue;
    }
    break;

.l14:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l377;

.l130:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l354;

.l236:
    if (esi == decomp_var_cf8) goto .l160;
    goto .l221;

.l371:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_490 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_490) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_340 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_340) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l323:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_181 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_181) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_206 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_206) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l336:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1161 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1156 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1161) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1156) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1159 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1159) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1157 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1157) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l335;

.l385:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_519 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_519) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_166 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_166) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

loc_44efc0:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_574 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_569 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_574) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_569) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_556 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_556) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_564 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_564) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l276;

.l399:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1803 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1796 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1803) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1796) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1814 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1814) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1812 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1812) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l400;

.l164:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_128 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_128) {
            continue;
    }
    break;

.l248:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l279;

.l363:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_246 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_246) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_327 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_327) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l393:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1743 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1742 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1743) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1742) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1754 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1754) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1736 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1736) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l394;

.l288:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_685 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_679 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_685) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_679) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_693 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_693) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_676 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_676) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l287;

.l137:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_325 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_325) {
            continue;
    }
    break;

.l198:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l345;

.l330:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1106 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1098 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1106) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1098) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1099 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1099) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1095 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1095) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l329;

.l273:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_539 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_539) {
            continue;
    }
    break;

.l194:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l402;

.l225:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l291;

.l120:
    if (esi == decomp_var_cf8) goto .l50;
    goto .l205;

.l305:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_142 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_142) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_198 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_198) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l349:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1308 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1308) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1305 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1305) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1312 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1312) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l350;

.l383:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1651 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1644 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1651) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1644) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1639 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1639) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1654 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1654) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l384;

.l231:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_542 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_542) {
            continue;
    }
    break;

.l121:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l341;

.l331:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1134 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1127 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1134) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1127) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1118 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1118) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1119 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1119) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l332;

.l183:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_471 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_471) {
            continue;
    }
    break;

.l11:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l392;

.l39:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l290;

.l70:
    if (esi == decomp_var_cf8) goto .l269;
    goto .l274;

.l343:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1249 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1249) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1247 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1247) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1241 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1241) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l344;

.l271:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_346 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_346) {
            continue;
    }
    break;

.l275:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l360;

.l13:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l395;

.l161:
    if (esi == decomp_var_cf8) goto .l40;
    goto .l126;

.l179:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l285;

.l253:
    if (esi == decomp_var_cf8) goto .l72;
    goto .l77;

.l150:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_330 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_330) {
            continue;
    }
    break;

.l7:
    if (ecx != decomp_var_cfc) goto .l143;
    goto .l196;

.l369:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_305 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_305) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_418 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_418) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l278:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_257 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_257) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_137 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_137) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l358:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_479 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_479) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_386 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_386) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l308:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_422 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_422) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_208 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_208) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l302:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_832 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_832) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_823 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_823) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_817 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_817) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l301;

.l293:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_313 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_313) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_211 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_211) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l338:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_505 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_505) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_385 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_385) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l390:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_497 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_497) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_204 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_204) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l328:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1093 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1081 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1093) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1081) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1089 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1089) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1080 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1080) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l327;

.l356:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_298 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_298) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_436 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_436) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l321:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_131 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_131) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_331 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_331) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l339:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1213 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1213) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1197 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1197) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1206 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1206) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l340;

.l326:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_357 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_357) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_554 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_554) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l377:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1589 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1589) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1578 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1578) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1593 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1593) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l378;

.l354:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1341 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1341) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1352 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1352) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1336 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1336) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l353;

.l160:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_312 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_312) {
            continue;
    }
    break;

.l221:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l347;

.l335:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_292 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_292) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_450 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_450) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l276:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_388 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_388) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_528 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_528) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l400:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_274 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_274) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_491 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_491) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l279:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_611 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_603 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_611) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_603) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_607 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_607) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_602 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_602) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l280;

.l394:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_523 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_523) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_445 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_445) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l287:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_229 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_229) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_179 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_179) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l345:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1274 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1262 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1274) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1262) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1265 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1265) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1271 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1271) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l346;

.l329:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_188 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_188) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_226 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_226) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l402:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1832 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1832) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1828 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1828) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1823 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1823) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l401;

.l291:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_724 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_724) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_732 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_732) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_715 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_715) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l292;

.l50:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_336 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_336) {
            continue;
    }
    break;

.l205:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l282;

.l350:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_141 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_141) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_347 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_347) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l384:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_262 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_262) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_293 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_293) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l341:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1226 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1217 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1226) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1217) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1228 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1228) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1224 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1224) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l342;

.l332:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_250 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_250) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_371 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_371) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l392:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1733 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1728 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1733) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1728) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1723 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1723) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1726 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1726) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l391;

.l290:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_703 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_697 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_703) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_697) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_699 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_699) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_701 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_701) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l289;

.l269:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_329 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_329) {
            continue;
    }
    break;

.l274:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l374;

.l344:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_217 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_217) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_429 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_429) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l360:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1412 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1395 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1412) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1395) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1400 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1400) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1409 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1409) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l359;

.l395:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1763 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1757 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1763) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1757) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1759 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1759) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1756 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1756) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l396;

.l40:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_266 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_266) {
            continue;
    }
    break;

.l126:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l299;

.l285:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_674 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_674) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_668 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_668) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_672 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_672) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l286;

.l72:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_303 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_303) {
            continue;
    }
    break;

.l77:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l361;

.l143:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l310;

.l196:
    if (esi == decomp_var_cf8) goto .l175;
    goto .l272;

.l301:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_296 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_296) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_123 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_123) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l327:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_295 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_295) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_513 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_513) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l340:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_363 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_363) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_247 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_247) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l378:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_138 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_138) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_469 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_469) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l353:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_222 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_222) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_282 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_282) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l347:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1294 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1294) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1284 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1284) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1292 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1292) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l348;

.l280:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_482 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_482) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_543 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_543) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l346:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_395 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_395) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_286 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_286) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l401:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_182 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_182) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_509 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_509) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l292:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_174 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_174) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_249 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_249) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l282:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_627 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_627) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_621 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_621) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_617 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_617) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l281;

.l342:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_156 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_156) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_360 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_360) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l391:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_278 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_278) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_234 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_234) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l289:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_335 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_335) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_148 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_148) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l374:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1547 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1547) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1539 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1539) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1548 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1548) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l373;

.l359:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_152 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_152) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_415 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_415) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l396:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_345 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_345) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_183 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_183) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l299:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_813 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_813) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_811 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_811) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_804 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_804) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l300;

.l286:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_284 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_284) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_392 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_392) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l361:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1433 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1430 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1433) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1430) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1422 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1422) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1428 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1428) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l362;

.l310:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_910 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_910) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_906 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_906) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_903 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_903) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l309;

.l175:
    decomp_var_cec = decomp_var_cec + 0x800;
    decomp_var_d10 = decomp_var_d10 + 0x800;
    bool_508 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
    decomp_var_d18 = decomp_var_d18 + 0x1;
    if (bool_508) {
            continue;
    }
    break;

.l272:
    eax = sub_407720(&decomp_var_d04);
    ecx = eax + 0x4;
    esp = esp - 0x8;
    decomp_var_d3c = ecx;
    eax = sub_4075b0(decomp_var_d3c, decomp_var_d38);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_cb8 = eax;
    decomp_var_d10 = ebx;
    decomp_var_d0c = esi;
    edi = decomp_var_d1c << 0x8;
    goto .l398;

.l348:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_431 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_431) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_276 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_276) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l281:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_510 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_510) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_390 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_390) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l373:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_316 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_316) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_442 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_442) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l300:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_441 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_441) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_397 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_397) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l362:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_349 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_349) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_425 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_425) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l309:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_444 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_444) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_125 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_125) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;

.l398:
    eax = decomp_var_cb8;
    decomp_var_c9c = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_c9c) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + edi;
            bool_1791 = *(eax * 0x8 + 0x58f8ec) < 0x0;
            bool_1777 = *(eax * 0x8 + 0x58f8ec) > 0x0;
            if (bool_1791) {
                    sub_40f400();
                    esi = decomp_var_d0c;
                    ebx = decomp_var_d10;
                    continue;
            }
            if (!bool_1777) {
                    if (*(eax * 0x8 + 0x58f8e8) <= 0x1) {
                            sub_40f400();
                            esi = decomp_var_d0c;
                            ebx = decomp_var_d10;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1792 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1792) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    ebx = arg_4;
                    ecx = esi[0x3];
                    edx = *((ecx + edi) * 0x8 + 0x52b4e8);
                    ecx = *((ecx + edi) * 0x8 + 0x52b4ec);
                    eax = (ebx << 0x8) + esi[0x3];
                    edx = edx - *(eax * 0x8 + 0x58f8e8);
                    ecx = ecx - *(eax * 0x8 + 0x58f8ec) + CARRY(EFLAGS(cf));
                    bool_1783 = ecx < 0x0;
                    if (ecx <= 0x0) {
                            if (bool_1783) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            if (edx <= 0x1) {
                                    sub_40f400();
                                    esi = decomp_var_d0c;
                                    ebx = decomp_var_d10;
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            temp_0 = 0x1;
                            break;
                    }
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l397;

.l397:
    if (temp_0 != 0x0) {
            esi = decomp_var_d20;
            if (esi == decomp_var_d24[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            decomp_var_d3c = esi + 0x24;
            ecx = ebx + ebx * 0x2;
            *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) = *(&decomp_var_d38 + decomp_var_d1c * 0x4 + 0x2b8) + decomp_var_cb0 + decomp_var_d04 + *sub_41c1e0(decomp_var_d3c) + 0x3e8;
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_180 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_180) {
                    continue;
            }
            break;
    }
    else {
            decomp_var_cec = decomp_var_cec + 0x800;
            decomp_var_d10 = decomp_var_d10 + 0x800;
            bool_124 = decomp_var_d18 + 0x1 < *(decomp_var_d24[0x2] + 0x2404);
            decomp_var_d18 = decomp_var_d18 + 0x1;
            if (bool_124) {
                    continue;
            }
            break;
    }
    goto loc_44f15e;
}
