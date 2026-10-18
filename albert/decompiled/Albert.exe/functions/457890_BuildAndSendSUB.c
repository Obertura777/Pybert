// BuildAndSendSUB @ 0x457890
// hopper name: sub_457890
// pybert name: BuildAndSendSUB
// contains unmarked entry 0x459230
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

BuildAndSendSUB() {
    &decomp_var_4 = &decomp_var_4 & 0xfffffff8;
    decomp_var_10 = *0x0;
    decomp_var_3e0 = ebx;
    decomp_var_3e4 = ebp;
    decomp_var_3e8 = esi;
    decomp_var_3ec = edi;
    esp = esp - 0x3ec;
    decomp_var_3f0 = *dword_4c8db8 ^ &decomp_var_3ec;
    *0x0 = &decomp_var_10;
    esi = ecx;
    decomp_var_3d4 = esi;
    sub_465870();
    decomp_var_3c8 = *(int8_t *)(esi[0x2] + 0x2424) & 0xff;
    eax = sub_47020b();
    if (eax == 0x0) {
            esp = esp - 0x4;
            decomp_var_3f4 = 0x80004005;
            eax = sub_40b5a0(0x80004005);
    }
    edx = *eax;
    decomp_var_380 = (edx[0x3])() + 0x10;
    sub_465870();
    sub_422960();
    sub_465870();
    sub_465870();
    sub_465870();
    sub_4424e0();
    ebp = **dword_bb65f0;
    decomp_var_3c0 = 0xbb65ec;
    decomp_var_3bc = **dword_bb65f0;
    goto loc_4579a1;

loc_4579a1:
    edi = decomp_var_3c0;
    goto loc_4579a5;

loc_4579a5:
    ebx = decomp_var_3d8;
    goto loc_4579a9;

loc_4579a9:
    if (edi == 0x0 || edi != 0xbb65ec) {
            sub_47a948();
    }
    if (ebp != *dword_bb65f0) {
            if (sub_45b860() == 0x0) {
                    if (edi == 0x0) {
                            sub_47a948();
                    }
                    if (ebp == edi[0x1]) {
                            sub_47a948();
                    }
                    if (arg_14 != 0x0) {
                            sub_40f470();
                            ebp = decomp_var_3bc;
                            edi = decomp_var_3c0;
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            else {
                    temp_0 = 0x1;
                    break;
            }
    }
    else {
            temp_0 = 0x1;
            break;
    }
    goto .l41;

.l41:
    if (temp_0 == 0x0) goto loc_4579f4;
    goto loc_4591b3;

loc_4579f4:
    if (ebp == edi[0x1]) {
            sub_47a948();
    }
    if (arg_1c >= *dword_4c6bbc || sub_45b860() != 0x0) goto .l76;
    goto loc_457a1c;

loc_4591b3:
    sub_443ed0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_41cc50();
    sub_465fa0();
    eax = decomp_var_380 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    edx = edx - 0x1;
    if (edx <= 0x0) {
            edx = **eax;
            esp = esp - 0x4;
            decomp_var_3f8 = eax;
            (edx[0x1])(decomp_var_3f8);
            temp_2 = 0x4;
    }
    else {
            temp_2 = 0x4;
    }
    break;

.l76:
    break;

loc_457a1c:
    if (ebp == edi[0x1]) {
            sub_47a948();
    }
    *dword_62cc64 = arg_1c;
    if (ebp == edi[0x1]) {
            sub_47a948();
    }
    edi = &arg_20;
    if (edi != 0xbc1e00) {
            eax = *dword_bc1e04;
            decomp_var_3fc = 0xbc1e00;
            decomp_var_400 = *eax;
            decomp_var_404 = 0xbc1e00;
            decomp_var_408 = &decomp_var_188;
            sub_403430(decomp_var_408, 0xbc1e00, decomp_var_400, 0xbc1e00, eax);
            esp = esp - 0x18;
            decomp_var_3f8 = edi;
            sub_402210(decomp_var_3f8);
    }
    if (*dword_62cc64 != 0x0) goto loc_457bcb;
    goto loc_457a79;
    if (temp_2 != 0x0) {
            if (temp_2 == 0x1) {
                    continue;
            }
            if (temp_2 == 0x2) {
                    continue;
            }
            if (temp_2 == 0x3) {
                    continue;
            }
            sub_465fa0();
            *0x0 = decomp_var_14;
            &decomp_var_3e0 = decomp_var_3e8;
            break;
    }
    else {
            break;
    }
    return;
    if (ebp == edi[0x1]) {
            sub_47a948();
    }
    edx = *dword_4c6bbc;
    if (arg_1c != *dword_4c6bbc) goto loc_4581fc;
    goto loc_457d88;

loc_457bcb:
    *(*dword_62cc64 * 0x4 + dword_b95368) = *dword_baed48 - *dword_62d34c;
    sub_44c8e0(decomp_var_40c);
    eax = *dword_62e4b4;
    edx = *dword_62cc64;
    ecx = eax - *dword_baed4c;
    *dword_baed4c = eax;
    *(edx * 0x4 + dword_b95458) = ecx;
    ecx = *dword_62d34c;
    esi = ecx - *dword_baed50;
    *dword_baed50 = ecx;
    *(edx * 0x4 + dword_b953e0) = esi;
    edi = **dword_bbf60c;
    esi = 0xbbf608;
    decomp_var_3bc = 0xbbf608;
    decomp_var_3b8 = **dword_bbf60c;
    &decomp_var_40c = &decomp_var_40c;
    goto loc_457c40;

loc_457a79:
    if (ebp == decomp_var_3c0[0x1]) {
            sub_47a948();
    }
    if (arg_c != 0x0) {
            esi = decomp_var_3c0;
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            decomp_var_3a8 = &decomp_var_400;
            esp = esp - 0x10;
            decomp_var_404 = &arg_38;
            sub_41c3c0(decomp_var_404);
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            decomp_var_3dc = &decomp_var_40c;
            esp = esp - 0x10;
            eax = sub_41c3c0(&arg_2c);
            sub_4559c0();
            ecx = *(ebx[0x2] + 0x2404);
            esi = 0x0;
            do {
                    edx = 0x0;
                    if (ecx > 0x0) {
                            eax = esi;
                            do {
                                    eax[0x2efda4] = eax[0x2f0290];
                                    eax[0x2efda5] = eax[0x2f0291];
                                    ecx = ebx[0x2];
                                    ecx = ecx[0x901];
                                    edx = edx + 0x1;
                                    eax = eax + 0xf0;
                            } while (edx < ecx);
                    }
                    esi = esi + 0x8;
            } while (esi < 0xf0);
    }
    esi = 0x0;
    decomp_var_3f4 = 0x0;
    if (*(ebx[0x2] + 0x2404) <= 0x0) goto loc_457bcb;
    goto loc_457b4d;

loc_4581fc:
    esi = decomp_var_41c;
    if (ebp == esi[0x1]) {
            sub_47a948();
    }
    if (arg_c != 0x0) goto .l159;
    goto loc_458214;

loc_457d88:
    edi = decomp_var_3c0;
    if (ebp == edi[0x1]) {
            sub_47a948();
    }
    esi = decomp_var_3cc * 0xf0 + 0xbbf690;
    arg_14 = 0x1;
    if (*esi == 0x0) {
            sub_47a948();
    }
    if (esi[0x1] == *(*esi + 0x4)) {
            sub_47a948();
    }
    esp = esp - 0x4;
    sub_465ff0(esi[0x1] + 0xc);
    if (ebp == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    decomp_var_3f8 = &decomp_var_390;
    sub_465ff0(decomp_var_3f8);
    edx = decomp_var_3d8[0x2];
    decomp_var_3c8 = 0x0;
    if (edx[0x901] <= 0x0) goto loc_457f93;
    goto loc_457e09;

loc_457c40:
    if (esi == 0x0 || esi != 0xbbf608) {
            sub_47a948();
    }
    if (edi != *dword_bbf60c) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
            }
            asm { fld        dword [edi+0x1c4] };
            asm { fstp       dword [edi+eax*4+0x5c] };
            sub_40f260();
            edi = decomp_var_3b8;
            esi = decomp_var_3bc;
            continue;
    }
    break;

loc_457b4d:
    goto loc_457b50;

.l159:
    temp_2 = 0x3;
    break;

loc_458214:
    if (ebp == esi[0x1]) {
            sub_47a948();
    }
    if (arg_1c != *dword_4c6bbc) goto .l158;
    goto loc_45822c;

loc_457f93:
    ebx = decomp_var_3c0;
    if (ebp == ebx[0x1]) {
            sub_47a948();
    }
    if (arg_ac == 0x1) {
            if (ebp == ebx[0x1]) {
                    sub_47a948();
            }
            if (arg_18 == 0x0) {
                    if (ebp == ebx[0x1]) {
                            sub_47a948();
                    }
                    ecx = &decomp_var_404;
                    decomp_var_3a8 = &decomp_var_404;
                    esp = esp - 0x14;
                    eax = sub_465f60(&arg_d0);
                    if (ebp == ebx[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    decomp_var_408 = ecx;
                    decomp_var_3dc = &decomp_var_408;
                    decomp_var_408 = arg_cc;
                    if (ebp == ebx[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_3d4 = &decomp_var_418;
                    eax = sub_465f60(&arg_bc);
                    esi = decomp_var_3d8;
                    esp = esp - 0x18;
                    decomp_var_41c = &decomp_var_37a;
                    eax = sub_42fc40();
                    bool_80 = ebp != ebx[0x1];
                    edi = *(int16_t *)eax;
                    if (!bool_80) {
                            sub_47a948();
                    }
                    ecx = &decomp_var_42c;
                    decomp_var_3d0 = &decomp_var_42c;
                    esp = esp - 0x14;
                    eax = sub_465f60(&arg_d0);
                    if (ebp == ebx[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    decomp_var_430 = ecx;
                    decomp_var_404 = &decomp_var_430;
                    decomp_var_430 = arg_cc;
                    if (ebp == ebx[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_3fc = &decomp_var_440;
                    esp = esp - 0x14;
                    eax = sub_465f60(&arg_bc);
                    sub_431fe0();
                    if (ebp == ebx[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_466ed0(&decomp_var_1fc, &arg_cc);
                    esi = eax;
                    if (ebp == ebx[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_466c40(&decomp_var_214, &arg_d0);
                    esi = eax;
                    if (ebp == ebx[0x1]) {
                            sub_47a948();
                    }
                    eax = sub_466c40(&decomp_var_224, &arg_bc);
                    esp = esp - 0xc;
                    sub_465ff0(eax);
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    if (ebp == ebx[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_448 = arg_b4;
                    decomp_var_44c = arg_b4;
                    decomp_var_44c = edi;
                    edi = decomp_var_424;
                    edx = &decomp_var_2b8;
                    decomp_var_3f4 = &decomp_var_44c;
                    esp = esp - 0x10;
                    decomp_var_450 = edx;
                    sub_4216f0();
                    sub_457520();
            }
            else {
                    edi = decomp_var_3d8;
            }
    }
    else {
            edi = decomp_var_3d8;
    }
    if (ebp == ebx[0x1]) {
            sub_47a948();
    }
    if (arg_c == *dword_baed60 && *dword_62a9dc > 0x0) {
            esi = 0x0;
            if (*(edi[0x2] + 0x2404) > 0x0) {
                    esp = esp - 0x4;
                    sub_421570(esi);
                    edx = edi[0x2];
                    esi = esi + 0x1;
                    if (esi < edx[0x901]) {
                            continue;
                    }
                    break;
            }
    }
    goto loc_4581fc;

loc_457e09:
    &decomp_var_3f4 = &decomp_var_3f4;
    goto loc_457e10;
    edi = decomp_var_3f0;
    sub_4424e0();
    if (*dword_624ef4 <= 0x0) {
            *dword_62cc64 = *dword_62cc64 + 0x1;
            if (ebp == decomp_var_3d8[0x1]) {
                    sub_47a948();
            }
            ebx = edi;
            edi = decomp_var_3d8;
            arg_1c = *dword_62cc64;
            continue;
    }
    ecx = sub_47b26f(0x0);
    eax = *dword_624ef4;
    esp = (esp - 0x4) + 0x4;
    ecx = ecx - *dword_ba2880;
    esi = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
    eax = eax - 0xa;
    bool_854 = esi > (eax & 0x80000000 ? 0xffffffff : 0x0);
    if (esi < (eax & 0x80000000 ? 0xffffffff : 0x0)) {
            *dword_62cc64 = *dword_62cc64 + 0x1;
            if (ebp == decomp_var_3d8[0x1]) {
                    sub_47a948();
            }
            ebx = edi;
            edi = decomp_var_3d8;
            arg_1c = *dword_62cc64;
            continue;
    }
    if (!bool_854) {
            if (ecx <= eax) {
                    *dword_62cc64 = *dword_62cc64 + 0x1;
                    if (ebp == decomp_var_3d8[0x1]) {
                            sub_47a948();
                    }
                    ebx = edi;
                    edi = decomp_var_3d8;
                    arg_1c = *dword_62cc64;
                    continue;
            }
            if (ebp == decomp_var_3d8[0x1]) {
                    sub_47a948();
            }
            if (arg_c != 0x0) {
                    *dword_62cc64 = *dword_62cc64 + 0x1;
                    if (ebp == decomp_var_3d8[0x1]) {
                            sub_47a948();
                    }
                    ebx = edi;
                    edi = decomp_var_3d8;
                    arg_1c = *dword_62cc64;
                    continue;
            }
            esi = decomp_var_3e4 * 0xf0 + 0xbbf690;
            if (*esi == 0x0) {
                    sub_47a948();
            }
            if (esi[0x1] == *(*esi + 0x4)) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            sub_465ff0(esi[0x1] + 0xc);
            if (sub_4658d0() > 0x1) {
                    esp = esp - 0x4;
                    eax = sub_45a9b0(&decomp_var_3a8);
            }
            *dword_62cc64 = *dword_62cc64 + 0x1;
            if (ebp == decomp_var_3d8[0x1]) {
                    sub_47a948();
            }
            ebx = edi;
            edi = decomp_var_3d8;
            arg_1c = *dword_62cc64;
            continue;
    }
    if (ebp == decomp_var_3d8[0x1]) {
            sub_47a948();
    }
    if (arg_c != 0x0) {
            *dword_62cc64 = *dword_62cc64 + 0x1;
            if (ebp == decomp_var_3d8[0x1]) {
                    sub_47a948();
            }
            ebx = edi;
            edi = decomp_var_3d8;
            arg_1c = *dword_62cc64;
            continue;
    }
    esi = decomp_var_3e4 * 0xf0 + 0xbbf690;
    if (*esi == 0x0) {
            sub_47a948();
    }
    if (esi[0x1] == *(*esi + 0x4)) {
            sub_47a948();
    }
    esp = esp - 0x4;
    sub_465ff0(esi[0x1] + 0xc);
    if (sub_4658d0() > 0x1) {
            esp = esp - 0x4;
            eax = sub_45a9b0(&decomp_var_3a8);
    }
    *dword_62cc64 = *dword_62cc64 + 0x1;
    if (ebp == decomp_var_3d8[0x1]) {
            sub_47a948();
    }
    ebx = edi;
    edi = decomp_var_3d8;
    arg_1c = *dword_62cc64;
    continue;

loc_457b50:
    if (*(esi * 0x4 + 0x62e460) > 0x0) {
            esp = esp - 0x8;
            eax = sub_401ff0(&decomp_var_1b8, &decomp_var_3f4, decomp_var_40c, decomp_var_408, decomp_var_404);
            edi = eax;
            eax = *edi;
            if (eax == 0x0 || eax != 0xbc1e00) {
                    sub_47a948();
            }
            if (edi[0x1] != *dword_bc1e04) {
                    sub_424850(esi, 0x0, decomp_var_40c, decomp_var_408, decomp_var_404, decomp_var_400, decomp_var_3fc, decomp_var_3f8, decomp_var_3f4, decomp_var_3f0, decomp_var_3ec, decomp_var_3e8, decomp_var_3e4, decomp_var_3e0, decomp_var_3dc, decomp_var_3d8, decomp_var_3d4, decomp_var_3d0, decomp_var_3cc, decomp_var_3c8);
                    esp = esp - 0xc;
                    sub_424490(esi, decomp_var_40c);
                    *dword_baed48 = *dword_baed48 + *(esi * 0x4 + 0xb9fe88);
            }
    }
    eax = decomp_var_3f0;
    esi = esi + 0x1;
    decomp_var_3f4 = esi;
    if (esi < *(eax[0x2] + 0x2404)) {
            continue;
    }
    break;

.l158:
    temp_2 = 0x3;
    break;

loc_45822c:
    if (*(int8_t *)byte_baed6d != 0x0) goto .l155;
    goto loc_458239;

loc_457e10:
    eax = *dword_bbf60c;
    asm { fldz };
    edi = *eax;
    asm { fstp       dword [esp+0x3f4+-976] };
    esi = 0xbbf608;
    decomp_var_3a4 = 0xbbf608;
    decomp_var_3a0 = edi;
    goto loc_457e30;
    ebx = eax;
    goto loc_457bcb;

.l155:
    temp_2 = 0x1;
    break;

loc_458239:
    eax = sub_47b26f(0x0);
    esp = (esp - 0x4) + 0x4;
    eax = eax - *dword_ba2870;
    bool_26 = true;
    bool_25 = true;
    edx = edx - *dword_ba2874 + CARRY(EFLAGS(cf));
    eax = eax - *dword_ba2878;
    edx = edx - *dword_ba287c + CARRY(EFLAGS(cf));
    eax = eax - *dword_ba2880;
    edx = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
    bool_24 = *(decomp_var_428 * 0xf0 + 0xbbf690) != 0x0;
    esi = decomp_var_428 * 0xf0 + 0xbbf690;
    *dword_ba2868 = eax;
    *dword_ba286c = edx;
    decomp_var_404 = esi;
    if (!bool_24) {
            sub_47a948();
    }
    if (esi[0x1] == *(*esi + 0x4)) {
            sub_47a948();
    }
    esp = esp - 0x4;
    sub_465ff0(esi[0x1] + 0xc);
    ebx = decomp_var_434;
    if (sub_4658d0() > 0x1) {
            esp = esp - 0x4;
            eax = sub_45a9b0(&decomp_var_3ec);
    }
    *(int8_t *)byte_baed6d = 0x1;
    esi = 0x0;
    if (*(ebx[0x2] + 0x2404) > 0x0) {
            edi = &arg_44;
            do {
                    if (ebp == decomp_var_41c[0x1]) {
                            sub_47a948();
                    }
                    *(esi * 0x4 + 0xb9fd80) = *edi;
                    esi = esi + 0x1;
                    edi = edi + 0x4;
            } while (esi < *(ebx[0x2] + 0x2404));
    }
    ecx = *(ebx[0x2] + 0x2404);
    esi = 0x0;
    while (true) {
            edx = 0x0;
            if (ecx > 0x0) {
                    sub_458330();
            }
            esi = esi + 0x8;
            if (esi < 0xf0) {
                    continue;
            }
            temp_1 = 0x1;
            break;
    }
    if (temp_1 == 0x0) goto .l153;
    goto loc_458368;

loc_457e30:
    if (esi == 0x0 || esi != 0xbbf608) {
            eax = sub_47a948();
    }
    if (edi != *dword_bbf60c) {
            if (esi == 0x0) {
                    eax = sub_47a948();
            }
            if (edi == esi[0x1]) {
                    eax = sub_47a948();
            }
            if (edi[0x7] != decomp_var_3c8) {
                    eax = sub_40f260();
                    edi = decomp_var_3a0;
                    esi = decomp_var_3a4;
                    continue;
            }
            if (edi == esi[0x1]) {
                    eax = sub_47a948();
            }
            asm { fldz };
            asm { fcomp      dword [edi+0x58] };
            asm { fnstsw     ax };
            if (!PARITY(HIBYTE(eax) & 0x5)) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                            if (edi == esi[0x1]) {
                                    sub_47a948();
                            }
                    }
                    asm { fild       dword [edi+0x24] };
                    asm { fmul       dword [edi+0x58] };
                    asm { fadd       dword [esp+0x3f4+-976] };
                    asm { fstp       dword [esp+0x3f4+-976] };
            }
            eax = sub_40f260();
            edi = decomp_var_3a0;
            esi = decomp_var_3a4;
            continue;
    }
    break;

.l153:
    temp_2 = 0x0;
    break;

loc_458368:
    if (*dword_62a9dc < 0x14) goto .l154;
    goto loc_458375;
    decomp_var_3f8 = &decomp_var_3c8;
    esp = esp - 0x8;
    decomp_var_3fc = &decomp_var_1b8;
    esi = sub_401ff0(decomp_var_3fc, decomp_var_3f8, decomp_var_3f4, decomp_var_3f0, decomp_var_3ec);
    eax = *esi;
    if (eax == 0x0 || eax != 0xbc1e00) {
            eax = sub_47a948();
    }
    if (esi[0x1] != *dword_bc1e04) {
            esi = decomp_var_3c0;
            if (ebp == esi[0x1]) {
                    eax = sub_47a948();
            }
            if (arg_c == 0x0) {
                    if (ebp == esi[0x1]) {
                            sub_47a948();
                    }
                    asm { fld        dword [esp+0x3f4+-976] };
                    asm { fdiv       qword [qword_value_4636737291354636288] };
                    esi = decomp_var_3c8;
                    *(ebp + esi * 0x4 + 0x48) = sub_47b5c0();
            }
            else {
                    asm { fldz };
                    asm { fcomp      dword [esp+0x3f4+-976] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x44)) {
                            if (ebp == esi[0x1]) {
                                    sub_47a948();
                            }
                            esi = decomp_var_3c8;
                            *(ebp + esi * 0x4 + 0x48) = 0xfff0bdc0;
                    }
                    else {
                            if (ebp == esi[0x1]) {
                                    sub_47a948();
                            }
                            asm { fld        dword [esp+0x3f4+-976] };
                            esi = decomp_var_3c8;
                            asm { fdiv       qword [qword_value_4636737291354636288] };
                            asm { fisub      dword [dword_b954cc+43188+esi*4] };
                            *(ebp + esi * 0x4 + 0x48) = sub_47b5c0();
                    }
            }
    }
    else {
            esi = decomp_var_3c8;
    }
    edx = decomp_var_3d8[0x2];
    decomp_var_3c8 = esi + 0x1;
    if (esi + 0x1 < edx[0x901]) {
            continue;
    }
    break;

.l154:
    temp_2 = 0x1;
    break;

loc_458375:
    if (*dword_624ef4 == 0x0) goto .l21;
    goto loc_45837e;

.l21:
    eax = decomp_var_39c;
    edi = eax[0x1];
    esi = edi;
    if (edi[0x11] == 0x0) {
            do {
                    sub_401950(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x11] == 0x0);
            eax = decomp_var_39c;
    }
    eax[0x1] = eax;
    *decomp_var_39c = decomp_var_39c;
    decomp_var_39c[0x2] = decomp_var_39c;
    eax = sub_404ce0(&decomp_var_194, &decomp_var_428, decomp_var_450);
    decomp_var_3ac = 0x0;
    eax = sub_466f80(&decomp_var_1f4, 0xbc1e0c);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465f30(0x4c6d38);
    eax = sub_465ff0(&decomp_var_28c);
    sub_465fa0();
    decomp_var_424 = decomp_var_428 & 0xff | 0x4100;
    decomp_var_42c = decomp_var_428 & 0xff | 0x4100;
    eax = sub_465f30(&decomp_var_42c);
    edx = &decomp_var_25c;
    sub_465ff0(edx);
    sub_465fa0();
    sub_47b26f(0x0);
    eax = decomp_var_390;
    esi = eax[0x1];
    esp = (esp - 0x28) + 0x4;
    edi = esi;
    if (esi[0x1d] == 0x0) {
            do {
                    sub_410cf0(edi[0x2]);
                    edi = *edi;
                    sub_465fa0();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    esi = edi;
            } while (edi[0x1d] == 0x0);
            eax = decomp_var_390;
    }
    eax[0x1] = eax;
    *decomp_var_390 = decomp_var_390;
    decomp_var_390[0x2] = decomp_var_390;
    eax = decomp_var_384;
    esi = eax[0x1];
    edi = esi;
    if (esi[0x1d] == 0x0) {
            do {
                    sub_410cf0(edi[0x2]);
                    edi = *edi;
                    sub_465fa0();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    esi = edi;
            } while (edi[0x1d] == 0x0);
            eax = decomp_var_384;
    }
    ebp = 0x0;
    eax[0x1] = eax;
    decomp_var_380 = 0x0;
    *decomp_var_384 = decomp_var_384;
    decomp_var_384[0x2] = decomp_var_384;
    ecx = ebx[0x2];
    edx = edx | 0xffffffff;
    decomp_var_3a8 = 0x1;
    eax = 0x0;
    if (ecx[0x901] > 0x0) {
            do {
                    *(&decomp_var_450 + eax * 0x4 + 0xd4) = ebp;
                    eax = eax + 0x1;
            } while (eax < ecx[0x901]);
    }
    sub_4222a0(&decomp_var_3ac);
    esp = esp - 0xc;
    eax = sub_430480(&decomp_var_17c, &decomp_var_14c, decomp_var_450);
    sub_41cc50();
    edx = *dword_bb65f0;
    eax = edx[0x1];
    ecx = edx;
    if (eax[0xe9] == 0x0) {
            if (eax[0x4] < *dword_bb65f4) {
                    eax = eax[0x2];
            }
            else {
                    ecx = eax;
                    eax = *eax;
            }
            if (eax[0xe9] == 0x0) {
                    continue;
            }
            break;
    }
    decomp_var_3b4 = 0xbb65ec;
    if (ecx != *dword_bb65f0 && *dword_bb65f4 >= ecx[0x4]) {
            eax = &decomp_var_3b4;
    }
    else {
            decomp_var_3c8 = *dword_bb65f0;
            decomp_var_3cc = 0xbb65ec;
            eax = &decomp_var_3cc;
    }
    edx = *eax;
    ebx = eax[0x1];
    esi = **dword_baed98;
    edi = 0xbaed94;
    decomp_var_414 = edx;
    decomp_var_410 = ebx;
    decomp_var_40c = 0xbaed94;
    decomp_var_408 = **dword_baed98;
    goto loc_458723;

loc_45837e:
    ecx = sub_47b26f(0x0);
    eax = *dword_624ef4;
    esp = (esp - 0x4) + 0x4;
    ecx = ecx - *dword_ba2880;
    esi = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
    eax = eax - 0xf;
    edx = eax & 0x80000000 ? 0xffffffff : 0x0;
    bool_79 = esi < edx;
    if (esi > edx) goto .l156;
    goto loc_4583a9;

loc_458723:
    if (edi == 0x0 || edi != 0xbaed94) {
            sub_47a948();
    }
    if (esi == *dword_baed98) goto .l73;
    goto loc_458742;

.l156:
    temp_2 = 0x2;
    break;

loc_4583a9:
    if (bool_79) goto .l5;
    goto loc_4583ab;

.l73:
    break;

loc_458742:
    decomp_var_42c = 0x0;
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    ebx = decomp_var_428;
    if (esi[0x4] == ebx) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = ebx * 0x15 + esi[0x6];
            bool_675 = *(eax * 0x8 + 0x4d552c) > 0x0;
            if (*(eax * 0x8 + 0x4d552c) >= 0x0) {
                    if (!bool_675) {
                            if (*(eax * 0x8 + 0x4d5528) >= 0x3) {
                                    esp = esp - 0x4;
                                    sub_465f30(0x4c6d38);
                                    decomp_var_420 = decomp_var_420 | 0x1;
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    esp = esp - 0x4;
                                    eax = sub_465df0(&decomp_var_27c);
                                    if (eax != 0x0) {
                                            ebx = 0x1;
                                    }
                                    else {
                                            ebx = 0x0;
                                    }
                            }
                            else {
                                    ebx = 0x0;
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            sub_465f30(0x4c6d38);
                            decomp_var_420 = decomp_var_420 | 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x4;
                            eax = sub_465df0(&decomp_var_27c);
                            if (eax != 0x0) {
                                    ebx = 0x1;
                            }
                            else {
                                    ebx = 0x0;
                            }
                    }
            }
            else {
                    ebx = 0x0;
            }
    }
    else {
            ebx = 0x0;
    }
    if ((decomp_var_420 & 0x1) != 0x0) {
            decomp_var_420 = decomp_var_420 & 0xfffffffe;
            sub_465fa0();
    }
    if (ebx != 0x0) {
            decomp_var_438 = 0x0;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = sub_466060(&decomp_var_1dc, 0x1);
            esp = esp - 0xc;
            sub_465ff0(eax);
            sub_465fa0();
            ebx = decomp_var_404;
            decomp_var_430 = 0x1e;
            do {
                    if (*ebx == 0x0) {
                            sub_47a948();
                    }
                    if (ebx[0x1] == *(*ebx + 0x4)) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    sub_465ff0(ebx[0x1] + 0xc);
                    ebp = sub_465930();
                    edi = 0x0;
                    if (ebp > 0x0) {
                            eax = sub_466060(&decomp_var_1bc, edi);
                            sub_465ff0(eax);
                            sub_465fa0();
                            esp = esp - 0x10;
                            eax = sub_465d90(&decomp_var_2b8);
                            if (eax != 0x0) {
                                    decomp_var_438 = decomp_var_438 + 0x1;
                            }
                            edi = edi + 0x1;
                            if (edi < ebp) {
                                    continue;
                            }
                            break;
                    }
                    ebx = ebx + 0x8;
                    decomp_var_430 = decomp_var_430 - 0x1;
            } while (decomp_var_430 != 0x0);
            if (decomp_var_438 > 0x2) {
                    decomp_var_42c = 0x1;
                    ebx = 0x1;
            }
            else {
                    edi = decomp_var_40c;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    ebx = decomp_var_428;
                    if (esi[0x6] == ebx) {
                            esp = esp - 0x4;
                            sub_465f30(0x4c6d38);
                            decomp_var_420 = decomp_var_420 | 0x2;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x4;
                            eax = sub_465df0(&decomp_var_26c);
                            if (eax != 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    eax = esi[0x4];
                                    eax = eax * 0x15 + ebx;
                                    bool_547 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                    if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                            if (!bool_547) {
                                                    if (*(eax * 0x8 + 0x4d5528) <= 0x2) {
                                                            ebx = 0x0;
                                                    }
                                                    else {
                                                            ebx = 0x1;
                                                    }
                                            }
                                            else {
                                                    ebx = 0x0;
                                            }
                                    }
                                    else {
                                            ebx = 0x1;
                                    }
                            }
                            else {
                                    ebx = 0x0;
                            }
                    }
                    else {
                            ebx = 0x0;
                    }
            }
    }
    else {
            edi = decomp_var_40c;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            ebx = decomp_var_428;
            if (esi[0x6] == ebx) {
                    esp = esp - 0x4;
                    sub_465f30(0x4c6d38);
                    decomp_var_420 = decomp_var_420 | 0x2;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_465df0(&decomp_var_26c);
                    if (eax != 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            eax = esi[0x4];
                            eax = eax * 0x15 + ebx;
                            bool_547 = *(eax * 0x8 + 0x4d552c) < 0x0;
                            if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                    if (!bool_547) {
                                            if (*(eax * 0x8 + 0x4d5528) <= 0x2) {
                                                    ebx = 0x0;
                                            }
                                            else {
                                                    ebx = 0x1;
                                            }
                                    }
                                    else {
                                            ebx = 0x0;
                                    }
                            }
                            else {
                                    ebx = 0x1;
                            }
                    }
                    else {
                            ebx = 0x0;
                    }
            }
            else {
                    ebx = 0x0;
            }
    }
    if ((decomp_var_420 & 0x2) != 0x0) {
            decomp_var_420 = decomp_var_420 & 0xfffffffd;
            sub_465fa0();
    }
    if (ebx == 0x0) {
            sub_40f7f0();
            esi = decomp_var_408;
            ebx = decomp_var_410;
            edi = decomp_var_40c;
            continue;
    }
    ebx = decomp_var_40c;
    decomp_var_438 = 0x0;
    decomp_var_430 = 0x0;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    bool_725 = esi != ebx[0x1];
    eax = esi[0x8];
    ebp = *(eax * 0x8 + 0x4d2610);
    decomp_var_3d0 = *(eax * 0x8 + 0x4d2614);
    if (!bool_725) {
            sub_47a948();
    }
    bool_489 = esi != ebx[0x1];
    eax = esi[0x8];
    decomp_var_3f4 = *(eax * 0x8 + 0x4d2e10);
    decomp_var_3f0 = *(eax * 0x8 + 0x4d2e14);
    if (!bool_489) {
            sub_47a948();
    }
    eax = esi[0x8];
    ecx = *(eax * 0x8 + 0x4d3614);
    bool_419 = ecx > 0x0;
    edi = *(eax * 0x8 + 0x4d3610);
    if (ecx >= 0x0) {
            if (!bool_419) {
                    if (edi >= 0x0) {
                            edx = decomp_var_428 & 0x80000000 ? 0xffffffff : 0x0;
                            if (edi == decomp_var_428) {
                                    if (ecx != edx) {
                                            if (esi == ebx[0x1]) {
                                                    sub_47a948();
                                            }
                                            decomp_var_430 = *((esi[0x4] * 0x15 + edi) * 0x8 + 0x4d5528);
                                    }
                            }
                            else {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_430 = *((esi[0x4] * 0x15 + edi) * 0x8 + 0x4d5528);
                            }
                    }
            }
            else {
                    edx = decomp_var_428 & 0x80000000 ? 0xffffffff : 0x0;
                    if (edi == decomp_var_428) {
                            if (ecx != edx) {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_430 = *((esi[0x4] * 0x15 + edi) * 0x8 + 0x4d5528);
                            }
                    }
                    else {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_430 = *((esi[0x4] * 0x15 + edi) * 0x8 + 0x4d5528);
                    }
            }
    }
    bool_602 = decomp_var_3d0 > 0x0;
    if (decomp_var_3d0 >= 0x0) {
            if (!bool_602) {
                    if (ebp >= 0x0) {
                            edx = decomp_var_428 & 0x80000000 ? 0xffffffff : 0x0;
                            if (ebp == decomp_var_428) {
                                    if (decomp_var_3d0 != edx) {
                                            if (esi == ebx[0x1]) {
                                                    sub_47a948();
                                            }
                                            decomp_var_438 = *((esi[0x4] * 0x15 + ebp) * 0x8 + 0x4d5528);
                                    }
                            }
                            else {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = *((esi[0x4] * 0x15 + ebp) * 0x8 + 0x4d5528);
                            }
                    }
            }
            else {
                    edx = decomp_var_428 & 0x80000000 ? 0xffffffff : 0x0;
                    if (ebp == decomp_var_428) {
                            if (decomp_var_3d0 != edx) {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = *((esi[0x4] * 0x15 + ebp) * 0x8 + 0x4d5528);
                            }
                    }
                    else {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = *((esi[0x4] * 0x15 + ebp) * 0x8 + 0x4d5528);
                    }
            }
    }
    bool_171 = decomp_var_3f0 > 0x0;
    if (decomp_var_3f0 < 0x0 || !bool_171 && decomp_var_3f4 < 0x0) goto loc_458b3f;
    goto loc_458a37;

.l5:
    eax = decomp_var_39c;
    edi = eax[0x1];
    esi = edi;
    if (edi[0x11] == 0x0) {
            do {
                    sub_401950(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x11] == 0x0);
            eax = decomp_var_39c;
    }
    eax[0x1] = eax;
    *decomp_var_39c = decomp_var_39c;
    decomp_var_39c[0x2] = decomp_var_39c;
    eax = sub_404ce0(&decomp_var_194, &decomp_var_428, decomp_var_450);
    decomp_var_3ac = 0x0;
    eax = sub_466f80(&decomp_var_1f4, 0xbc1e0c);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465f30(0x4c6d38);
    eax = sub_465ff0(&decomp_var_28c);
    sub_465fa0();
    decomp_var_424 = decomp_var_428 & 0xff | 0x4100;
    decomp_var_42c = decomp_var_428 & 0xff | 0x4100;
    eax = sub_465f30(&decomp_var_42c);
    edx = &decomp_var_25c;
    sub_465ff0(edx);
    sub_465fa0();
    sub_47b26f(0x0);
    eax = decomp_var_390;
    esi = eax[0x1];
    esp = (esp - 0x28) + 0x4;
    edi = esi;
    if (esi[0x1d] == 0x0) {
            do {
                    sub_410cf0(edi[0x2]);
                    edi = *edi;
                    sub_465fa0();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    esi = edi;
            } while (edi[0x1d] == 0x0);
            eax = decomp_var_390;
    }
    eax[0x1] = eax;
    *decomp_var_390 = decomp_var_390;
    decomp_var_390[0x2] = decomp_var_390;
    eax = decomp_var_384;
    esi = eax[0x1];
    edi = esi;
    if (esi[0x1d] == 0x0) {
            do {
                    sub_410cf0(edi[0x2]);
                    edi = *edi;
                    sub_465fa0();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    esi = edi;
            } while (edi[0x1d] == 0x0);
            eax = decomp_var_384;
    }
    ebp = 0x0;
    eax[0x1] = eax;
    decomp_var_380 = 0x0;
    *decomp_var_384 = decomp_var_384;
    decomp_var_384[0x2] = decomp_var_384;
    ecx = ebx[0x2];
    edx = edx | 0xffffffff;
    decomp_var_3a8 = 0x1;
    eax = 0x0;
    if (ecx[0x901] > 0x0) {
            do {
                    *(&decomp_var_450 + eax * 0x4 + 0xd4) = ebp;
                    eax = eax + 0x1;
            } while (eax < ecx[0x901]);
    }
    sub_4222a0(&decomp_var_3ac);
    esp = esp - 0xc;
    eax = sub_430480(&decomp_var_17c, &decomp_var_14c, decomp_var_450);
    sub_41cc50();
    edx = *dword_bb65f0;
    eax = edx[0x1];
    ecx = edx;
    if (eax[0xe9] == 0x0) {
            if (eax[0x4] < *dword_bb65f4) {
                    eax = eax[0x2];
            }
            else {
                    ecx = eax;
                    eax = *eax;
            }
            if (eax[0xe9] == 0x0) {
                    continue;
            }
            break;
    }
    decomp_var_3b4 = 0xbb65ec;
    if (ecx != *dword_bb65f0 && *dword_bb65f4 >= ecx[0x4]) {
            eax = &decomp_var_3b4;
    }
    else {
            decomp_var_3c8 = *dword_bb65f0;
            decomp_var_3cc = 0xbb65ec;
            eax = &decomp_var_3cc;
    }
    edx = *eax;
    ebx = eax[0x1];
    esi = **dword_baed98;
    edi = 0xbaed94;
    decomp_var_414 = edx;
    decomp_var_410 = ebx;
    decomp_var_40c = 0xbaed94;
    decomp_var_408 = **dword_baed98;
    goto .l43;

loc_4583ab:
    if (ecx >= eax) goto .l157;
    goto loc_4583b3;
    if (decomp_var_414 == 0x0) {
            sub_47a948();
    }
    edx = decomp_var_414;
    if (ebx == edx[0x1]) {
            sub_47a948();
    }
    if (ebx[0x11] == 0x0) {
            if (ebx == decomp_var_414[0x1]) {
                    sub_47a948();
            }
            ebx[0x18] = 0x1;
            if (ebx == decomp_var_414[0x1]) {
                    sub_47a948();
            }
            edx = *dword_4c6bbc;
            ebx[0x8] = *dword_4c6bbc;
    }
    edi = 0xbb65ec;
    ebp = **dword_bb65f0;
    decomp_var_41c = 0xbb65ec;
    decomp_var_418 = **dword_bb65f0;
    continue;

loc_458b3f:
    if (decomp_var_438 < 0x3) {
            if (decomp_var_430 < 0x3) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    bool_478 = esi != ebx[0x1];
                    eax = esi[0x4];
                    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
                    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
                    if (!bool_478) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    eax = esi[0x4];
                    ebp = eax + eax * 0x2;
                    eax = *(ebp * 0x4 + 0xbb65fc);
                    edi = eax[0x1];
                    ebp = ebp * 0x4 + 0xbb65f8;
                    ebx = eax;
                    if (edi[0x1d] == 0x0) {
                            esp = esp - 0x4;
                            if (sub_465cf0(esi + 0x28) != 0x0) {
                                    edi = edi[0x2];
                            }
                            else {
                                    ebx = edi;
                                    edi = *edi;
                            }
                            if (edi[0x1d] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    decomp_var_3c0 = ebx;
                    decomp_var_3c4 = ebp;
                    if (ebx != arg_0) {
                            esp = esp - 0x4;
                            if (sub_465cf0(ebx + 0xc) == 0x0) {
                                    eax = &decomp_var_3c4;
                                    ecx = *eax;
                                    edi = eax[0x1];
                                    if (ecx != 0x0) {
                                            if (ecx != decomp_var_438) {
                                                    sub_47a948();
                                            }
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    decomp_var_3bc = ebp;
                                    eax = &decomp_var_3bc;
                                    ecx = *eax;
                                    edi = eax[0x1];
                                    if (ecx != 0x0) {
                                            if (ecx != decomp_var_438) {
                                                    sub_47a948();
                                            }
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            decomp_var_3bc = ebp;
                            eax = &decomp_var_3bc;
                            ecx = *eax;
                            edi = eax[0x1];
                            if (ecx != 0x0) {
                                    if (ecx != decomp_var_438) {
                                            sub_47a948();
                                    }
                                    if (edi != decomp_var_290) {
                                            decomp_var_430 = 0xfffb6c20;
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x6];
                                            }
                                    }
                                    else {
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                    sub_465f30(&decomp_var_3f6);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                    eax = sub_465f30(&decomp_var_3f8);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                    }
                            }
                            else {
                                    sub_47a948();
                                    if (edi != decomp_var_290) {
                                            decomp_var_430 = 0xfffb6c20;
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x6];
                                            }
                                    }
                                    else {
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                    sub_465f30(&decomp_var_3f6);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                    eax = sub_465f30(&decomp_var_3f8);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    decomp_var_430 = 0xfffcf2c0;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
    }
    else {
            decomp_var_430 = 0xfffcf2c0;
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x6];
            }
    }
    goto loc_458d52;

loc_458a37:
    eax = decomp_var_428;
    edx = eax & 0x80000000 ? 0xffffffff : 0x0;
    if (decomp_var_3f4 != eax) goto .l38;
    goto loc_458a42;

.l43:
    if (edi == 0x0 || edi != 0xbaed94) {
            sub_47a948();
    }
    if (esi == *dword_baed98) goto .l45;
    goto .l47;

.l157:
    temp_2 = 0x2;
    break;

loc_4583b3:
    eax = decomp_var_39c;
    edi = eax[0x1];
    esi = edi;
    if (edi[0x11] == 0x0) {
            do {
                    sub_401950(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x11] == 0x0);
            eax = decomp_var_39c;
    }
    eax[0x1] = eax;
    *decomp_var_39c = decomp_var_39c;
    decomp_var_39c[0x2] = decomp_var_39c;
    eax = sub_404ce0(&decomp_var_194, &decomp_var_428, decomp_var_450);
    decomp_var_3ac = 0x0;
    eax = sub_466f80(&decomp_var_1f4, 0xbc1e0c);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465f30(0x4c6d38);
    eax = sub_465ff0(&decomp_var_28c);
    sub_465fa0();
    decomp_var_424 = decomp_var_428 & 0xff | 0x4100;
    decomp_var_42c = decomp_var_428 & 0xff | 0x4100;
    eax = sub_465f30(&decomp_var_42c);
    edx = &decomp_var_25c;
    sub_465ff0(edx);
    sub_465fa0();
    sub_47b26f(0x0);
    eax = decomp_var_390;
    esi = eax[0x1];
    esp = (esp - 0x28) + 0x4;
    edi = esi;
    if (esi[0x1d] == 0x0) {
            do {
                    sub_410cf0(edi[0x2]);
                    edi = *edi;
                    sub_465fa0();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    esi = edi;
            } while (edi[0x1d] == 0x0);
            eax = decomp_var_390;
    }
    eax[0x1] = eax;
    *decomp_var_390 = decomp_var_390;
    decomp_var_390[0x2] = decomp_var_390;
    eax = decomp_var_384;
    esi = eax[0x1];
    edi = esi;
    if (esi[0x1d] == 0x0) {
            do {
                    sub_410cf0(edi[0x2]);
                    edi = *edi;
                    sub_465fa0();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    esi = edi;
            } while (edi[0x1d] == 0x0);
            eax = decomp_var_384;
    }
    eax[0x1] = eax;
    decomp_var_380 = 0x0;
    *decomp_var_384 = decomp_var_384;
    decomp_var_384[0x2] = decomp_var_384;
    ecx = ebx[0x2];
    edx = edx | 0xffffffff;
    decomp_var_3a8 = 0x1;
    eax = 0x0;
    if (ecx[0x901] > 0x0) {
            do {
                    *(&decomp_var_450 + eax * 0x4 + 0xd4) = 0x0;
                    eax = eax + 0x1;
            } while (eax < ecx[0x901]);
    }
    sub_4222a0(&decomp_var_3ac);
    esp = esp - 0xc;
    eax = sub_430480(&decomp_var_17c, &decomp_var_14c, decomp_var_450);
    sub_41cc50();
    edx = *dword_bb65f0;
    eax = edx[0x1];
    ecx = edx;
    if (eax[0xe9] == 0x0) {
            if (eax[0x4] < *dword_bb65f4) {
                    eax = eax[0x2];
            }
            else {
                    ecx = eax;
                    eax = *eax;
            }
            if (eax[0xe9] == 0x0) {
                    continue;
            }
            break;
    }
    decomp_var_3b4 = 0xbb65ec;
    if (ecx != *dword_bb65f0 && *dword_bb65f4 >= ecx[0x4]) {
            eax = &decomp_var_3b4;
    }
    else {
            decomp_var_3c8 = *dword_bb65f0;
            decomp_var_3cc = 0xbb65ec;
            eax = &decomp_var_3cc;
    }
    edx = *eax;
    ebx = eax[0x1];
    esi = **dword_baed98;
    edi = 0xbaed94;
    decomp_var_414 = edx;
    decomp_var_410 = ebx;
    decomp_var_40c = 0xbaed94;
    decomp_var_408 = **dword_baed98;
    goto .l54;

loc_458d52:
    eax = decomp_var_39c;
    ebp = eax[0x1];
    edi = ebp;
    if (arg_d == 0x0) {
            do {
                    sub_401950(edi[0x2]);
                    edi = *edi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    ebp = edi;
            } while (edi[0x11] == 0x0);
            eax = decomp_var_39c;
    }
    eax[0x1] = eax;
    *decomp_var_39c = decomp_var_39c;
    decomp_var_39c[0x2] = decomp_var_39c;
    eax = sub_404ce0(&decomp_var_170, &decomp_var_428, decomp_var_450);
    esp = esp - 0x10;
    eax = sub_404ce0(&decomp_var_188, &decomp_var_438, decomp_var_450);
    eax = decomp_var_390;
    edi = eax[0x1];
    ebp = edi;
    if (edi[0x1d] != 0x0) {
            eax[0x1] = eax;
            *decomp_var_390 = decomp_var_390;
            decomp_var_390[0x2] = decomp_var_390;
            eax = decomp_var_384;
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
                    } while (arg_19 == 0x0);
                    eax = decomp_var_384;
            }
            eax[0x1] = eax;
            decomp_var_380 = 0x0;
            *decomp_var_384 = decomp_var_384;
            decomp_var_384[0x2] = decomp_var_384;
            if (decomp_var_414 == 0x0) {
                    sub_47a948();
            }
            ebx = decomp_var_410;
            if (ebx == decomp_var_414[0x1]) {
                    sub_47a948();
            }
            if (esi == arg_0) {
                    sub_47a948();
            }
            edi = esi + 0x28;
            eax = sub_419300(&decomp_var_158, edi, decomp_var_450);
            decomp_var_3a8 = 0x1;
            decomp_var_3ac = 0x0;
            eax = sub_466f80(&decomp_var_1cc, 0xbc1e0c);
            esp = esp - 0x14;
            sub_465ff0(eax);
            sub_465fa0();
            if (esi == arg_0) {
                    sub_47a948();
            }
            sub_465ff0(edi);
            decomp_var_42c = decomp_var_438 & 0xff | 0x4100;
            eax = sub_465f30(&decomp_var_42c);
            esp = esp - 0xc;
            eax = sub_465ff0(&decomp_var_24c);
            sub_465fa0();
            ecx = decomp_var_434[0x2];
            ebp = decomp_var_430;
            eax = 0x0;
            if (ecx[0x901] <= 0x0) {
                    edi = *dword_bb65f4;
                    sub_4222a0(&decomp_var_3ac);
                    esp = esp - 0xc;
                    eax = sub_430480(&decomp_var_1a0, &decomp_var_14c, decomp_var_450);
                    sub_41cc50();
                    *dword_baed60 = edi;
                    if (ebp != 0x0) {
                            sub_40f7f0();
                            esi = decomp_var_408;
                            ebx = decomp_var_410;
                            edi = decomp_var_40c;
                            continue;
                    }
                    if (esi == decomp_var_40c[0x1]) {
                            sub_47a948();
                    }
                    edi = decomp_var_414;
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_419300(&decomp_var_1ac, esi + 0x28, decomp_var_450);
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_530 = ebx != decomp_var_414[0x1];
                    ebp = ebx[0xa];
                    esi = ebx + 0x24;
                    if (!bool_530) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_401ff0(&decomp_var_23c, &decomp_var_438, decomp_var_450, decomp_var_44c, decomp_var_448);
                    edi = eax;
                    eax = *edi;
                    if (eax == 0x0 || eax != esi) {
                            sub_47a948();
                    }
                    if (edi[0x1] == ebp) {
                            if (ebx == decomp_var_414[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x8;
                            eax = sub_404ce0(&decomp_var_164, &decomp_var_438, decomp_var_450);
                    }
                    sub_40f7f0();
                    esi = decomp_var_408;
                    ebx = decomp_var_410;
                    edi = decomp_var_40c;
                    continue;
            }
            &decomp_var_450 = &decomp_var_450;
            do {
                    if (ebp == 0x0) {
                            *(&decomp_var_450 + eax * 0x4 + 0xd4) = 0x0;
                    }
                    else {
                            *(&decomp_var_450 + eax * 0x4 + 0xd4) = ebp;
                            decomp_var_3ac = 0x1;
                    }
                    eax = eax + 0x1;
            } while (eax < ecx[0x901]);
            edi = *dword_bb65f4;
            sub_4222a0(&decomp_var_3ac);
            esp = esp - 0xc;
            eax = sub_430480(&decomp_var_1a0, &decomp_var_14c, decomp_var_450);
            sub_41cc50();
            *dword_baed60 = edi;
            if (ebp != 0x0) {
                    sub_40f7f0();
                    esi = decomp_var_408;
                    ebx = decomp_var_410;
                    edi = decomp_var_40c;
                    continue;
            }
            if (esi == decomp_var_40c[0x1]) {
                    sub_47a948();
            }
            edi = decomp_var_414;
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_419300(&decomp_var_1ac, esi + 0x28, decomp_var_450);
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            bool_530 = ebx != decomp_var_414[0x1];
            ebp = ebx[0xa];
            esi = ebx + 0x24;
            if (!bool_530) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&decomp_var_23c, &decomp_var_438, decomp_var_450, decomp_var_44c, decomp_var_448);
            edi = eax;
            eax = *edi;
            if (eax == 0x0 || eax != esi) {
                    sub_47a948();
            }
            if (edi[0x1] == ebp) {
                    if (ebx == decomp_var_414[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_404ce0(&decomp_var_164, &decomp_var_438, decomp_var_450);
            }
            sub_40f7f0();
            esi = decomp_var_408;
            ebx = decomp_var_410;
            edi = decomp_var_40c;
            continue;
    }
    do {
            sub_410cf0(arg_4);
            ebp = *ebp;
            sub_465fa0();
            sub_47c8f9();
            esp = (esp - 0x8) + 0x4;
            edi = ebp;
    } while (arg_19 == 0x0);
    eax = decomp_var_390;
    eax[0x1] = eax;
    *decomp_var_390 = decomp_var_390;
    decomp_var_390[0x2] = decomp_var_390;
    eax = decomp_var_384;
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
            } while (arg_19 == 0x0);
            eax = decomp_var_384;
    }
    eax[0x1] = eax;
    decomp_var_380 = 0x0;
    *decomp_var_384 = decomp_var_384;
    decomp_var_384[0x2] = decomp_var_384;
    if (decomp_var_414 == 0x0) {
            sub_47a948();
    }
    ebx = decomp_var_410;
    if (ebx == decomp_var_414[0x1]) {
            sub_47a948();
    }
    if (esi == arg_0) {
            sub_47a948();
    }
    edi = esi + 0x28;
    eax = sub_419300(&decomp_var_158, edi, decomp_var_450);
    decomp_var_3a8 = 0x1;
    decomp_var_3ac = 0x0;
    eax = sub_466f80(&decomp_var_1cc, 0xbc1e0c);
    esp = esp - 0x14;
    sub_465ff0(eax);
    sub_465fa0();
    if (esi == arg_0) {
            sub_47a948();
    }
    sub_465ff0(edi);
    decomp_var_42c = decomp_var_438 & 0xff | 0x4100;
    eax = sub_465f30(&decomp_var_42c);
    esp = esp - 0xc;
    eax = sub_465ff0(&decomp_var_24c);
    sub_465fa0();
    ecx = decomp_var_434[0x2];
    ebp = decomp_var_430;
    eax = 0x0;
    if (ecx[0x901] <= 0x0) {
            edi = *dword_bb65f4;
            sub_4222a0(&decomp_var_3ac);
            esp = esp - 0xc;
            eax = sub_430480(&decomp_var_1a0, &decomp_var_14c, decomp_var_450);
            sub_41cc50();
            *dword_baed60 = edi;
            if (ebp != 0x0) {
                    sub_40f7f0();
                    esi = decomp_var_408;
                    ebx = decomp_var_410;
                    edi = decomp_var_40c;
                    continue;
            }
            if (esi == decomp_var_40c[0x1]) {
                    sub_47a948();
            }
            edi = decomp_var_414;
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_419300(&decomp_var_1ac, esi + 0x28, decomp_var_450);
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            bool_530 = ebx != decomp_var_414[0x1];
            ebp = ebx[0xa];
            esi = ebx + 0x24;
            if (!bool_530) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&decomp_var_23c, &decomp_var_438, decomp_var_450, decomp_var_44c, decomp_var_448);
            edi = eax;
            eax = *edi;
            if (eax == 0x0 || eax != esi) {
                    sub_47a948();
            }
            if (edi[0x1] == ebp) {
                    if (ebx == decomp_var_414[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_404ce0(&decomp_var_164, &decomp_var_438, decomp_var_450);
            }
            sub_40f7f0();
            esi = decomp_var_408;
            ebx = decomp_var_410;
            edi = decomp_var_40c;
            continue;
    }
    &decomp_var_450 = &decomp_var_450;
    do {
            if (ebp == 0x0) {
                    *(&decomp_var_450 + eax * 0x4 + 0xd4) = 0x0;
            }
            else {
                    *(&decomp_var_450 + eax * 0x4 + 0xd4) = ebp;
                    decomp_var_3ac = 0x1;
            }
            eax = eax + 0x1;
    } while (eax < ecx[0x901]);
    edi = *dword_bb65f4;
    sub_4222a0(&decomp_var_3ac);
    esp = esp - 0xc;
    eax = sub_430480(&decomp_var_1a0, &decomp_var_14c, decomp_var_450);
    sub_41cc50();
    *dword_baed60 = edi;
    if (ebp != 0x0) {
            sub_40f7f0();
            esi = decomp_var_408;
            ebx = decomp_var_410;
            edi = decomp_var_40c;
            continue;
    }
    if (esi == decomp_var_40c[0x1]) {
            sub_47a948();
    }
    edi = decomp_var_414;
    if (ebx == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    eax = sub_419300(&decomp_var_1ac, esi + 0x28, decomp_var_450);
    if (ebx == edi[0x1]) {
            sub_47a948();
    }
    bool_530 = ebx != decomp_var_414[0x1];
    ebp = ebx[0xa];
    esi = ebx + 0x24;
    if (!bool_530) {
            sub_47a948();
    }
    esp = esp - 0x8;
    eax = sub_401ff0(&decomp_var_23c, &decomp_var_438, decomp_var_450, decomp_var_44c, decomp_var_448);
    edi = eax;
    eax = *edi;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (edi[0x1] == ebp) {
            if (ebx == decomp_var_414[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_404ce0(&decomp_var_164, &decomp_var_438, decomp_var_450);
    }
    sub_40f7f0();
    esi = decomp_var_408;
    ebx = decomp_var_410;
    edi = decomp_var_40c;
    continue;

.l38:
    if (ebp != eax) goto .l8;
    goto .l39;

loc_458a42:
    if (decomp_var_3f0 == edx) goto .l26;
    goto loc_458a4c;

.l45:
    break;

.l47:
    decomp_var_42c = 0x0;
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    ebx = decomp_var_428;
    if (esi[0x4] == ebx) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = ebx * 0x15 + esi[0x6];
            bool_1306 = *(eax * 0x8 + 0x4d552c) > 0x0;
            if (*(eax * 0x8 + 0x4d552c) >= 0x0) {
                    if (!bool_1306) {
                            if (*(eax * 0x8 + 0x4d5528) >= 0x3) {
                                    esp = esp - 0x4;
                                    sub_465f30(0x4c6d38);
                                    decomp_var_420 = decomp_var_420 | 0x1;
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    esp = esp - 0x4;
                                    eax = sub_465df0(&decomp_var_27c);
                                    if (eax != 0x0) {
                                            ebx = 0x1;
                                    }
                                    else {
                                            ebx = 0x0;
                                    }
                            }
                            else {
                                    ebx = 0x0;
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            sub_465f30(0x4c6d38);
                            decomp_var_420 = decomp_var_420 | 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x4;
                            eax = sub_465df0(&decomp_var_27c);
                            if (eax != 0x0) {
                                    ebx = 0x1;
                            }
                            else {
                                    ebx = 0x0;
                            }
                    }
            }
            else {
                    ebx = 0x0;
            }
    }
    else {
            ebx = 0x0;
    }
    if ((decomp_var_420 & 0x1) != 0x0) {
            decomp_var_420 = decomp_var_420 & 0xfffffffe;
            sub_465fa0();
    }
    if (ebx != 0x0) {
            decomp_var_438 = 0x0;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = sub_466060(&decomp_var_1dc, 0x1);
            esp = esp - 0xc;
            sub_465ff0(eax);
            sub_465fa0();
            ebx = decomp_var_404;
            decomp_var_430 = 0x1e;
            do {
                    if (*ebx == 0x0) {
                            sub_47a948();
                    }
                    if (ebx[0x1] == *(*ebx + 0x4)) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    sub_465ff0(ebx[0x1] + 0xc);
                    ebp = sub_465930();
                    edi = 0x0;
                    if (ebp > 0x0) {
                            eax = sub_466060(&decomp_var_1bc, edi);
                            sub_465ff0(eax);
                            sub_465fa0();
                            esp = esp - 0x10;
                            eax = sub_465d90(&decomp_var_2b8);
                            if (eax != 0x0) {
                                    decomp_var_438 = decomp_var_438 + 0x1;
                            }
                            edi = edi + 0x1;
                            if (edi < ebp) {
                                    continue;
                            }
                            break;
                    }
                    ebx = ebx + 0x8;
                    decomp_var_430 = decomp_var_430 - 0x1;
            } while (decomp_var_430 != 0x0);
            if (decomp_var_438 > 0x2) {
                    decomp_var_42c = 0x1;
                    ebx = 0x1;
            }
            else {
                    edi = decomp_var_40c;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    ebx = decomp_var_428;
                    if (esi[0x6] == ebx) {
                            esp = esp - 0x4;
                            sub_465f30(0x4c6d38);
                            decomp_var_420 = decomp_var_420 | 0x2;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x4;
                            eax = sub_465df0(&decomp_var_26c);
                            if (eax != 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    eax = esi[0x4];
                                    eax = eax * 0x15 + ebx;
                                    bool_1207 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                    if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                            if (!bool_1207) {
                                                    if (*(eax * 0x8 + 0x4d5528) <= 0x2) {
                                                            ebx = 0x0;
                                                    }
                                                    else {
                                                            ebx = 0x1;
                                                    }
                                            }
                                            else {
                                                    ebx = 0x0;
                                            }
                                    }
                                    else {
                                            ebx = 0x1;
                                    }
                            }
                            else {
                                    ebx = 0x0;
                            }
                    }
                    else {
                            ebx = 0x0;
                    }
            }
    }
    else {
            edi = decomp_var_40c;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            ebx = decomp_var_428;
            if (esi[0x6] == ebx) {
                    esp = esp - 0x4;
                    sub_465f30(0x4c6d38);
                    decomp_var_420 = decomp_var_420 | 0x2;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_465df0(&decomp_var_26c);
                    if (eax != 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            eax = esi[0x4];
                            eax = eax * 0x15 + ebx;
                            bool_1207 = *(eax * 0x8 + 0x4d552c) < 0x0;
                            if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                    if (!bool_1207) {
                                            if (*(eax * 0x8 + 0x4d5528) <= 0x2) {
                                                    ebx = 0x0;
                                            }
                                            else {
                                                    ebx = 0x1;
                                            }
                                    }
                                    else {
                                            ebx = 0x0;
                                    }
                            }
                            else {
                                    ebx = 0x1;
                            }
                    }
                    else {
                            ebx = 0x0;
                    }
            }
            else {
                    ebx = 0x0;
            }
    }
    if ((decomp_var_420 & 0x2) != 0x0) {
            decomp_var_420 = decomp_var_420 & 0xfffffffd;
            sub_465fa0();
    }
    if (ebx == 0x0) {
            sub_40f7f0();
            esi = decomp_var_408;
            ebx = decomp_var_410;
            edi = decomp_var_40c;
            continue;
    }
    ebx = decomp_var_40c;
    decomp_var_438 = 0x0;
    decomp_var_430 = 0x0;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    bool_1032 = esi != ebx[0x1];
    eax = esi[0x8];
    ebp = *(eax * 0x8 + 0x4d2610);
    decomp_var_3d0 = *(eax * 0x8 + 0x4d2614);
    if (!bool_1032) {
            sub_47a948();
    }
    bool_1162 = esi != ebx[0x1];
    eax = esi[0x8];
    decomp_var_3f4 = *(eax * 0x8 + 0x4d2e10);
    decomp_var_3f0 = *(eax * 0x8 + 0x4d2e14);
    if (!bool_1162) {
            sub_47a948();
    }
    eax = esi[0x8];
    ecx = *(eax * 0x8 + 0x4d3614);
    bool_1168 = ecx > 0x0;
    edi = *(eax * 0x8 + 0x4d3610);
    if (ecx >= 0x0) {
            if (!bool_1168) {
                    if (edi >= 0x0) {
                            edx = decomp_var_428 & 0x80000000 ? 0xffffffff : 0x0;
                            if (edi == decomp_var_428) {
                                    if (ecx != edx) {
                                            if (esi == ebx[0x1]) {
                                                    sub_47a948();
                                            }
                                            decomp_var_430 = *((esi[0x4] * 0x15 + edi) * 0x8 + 0x4d5528);
                                    }
                            }
                            else {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_430 = *((esi[0x4] * 0x15 + edi) * 0x8 + 0x4d5528);
                            }
                    }
            }
            else {
                    edx = decomp_var_428 & 0x80000000 ? 0xffffffff : 0x0;
                    if (edi == decomp_var_428) {
                            if (ecx != edx) {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_430 = *((esi[0x4] * 0x15 + edi) * 0x8 + 0x4d5528);
                            }
                    }
                    else {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_430 = *((esi[0x4] * 0x15 + edi) * 0x8 + 0x4d5528);
                    }
            }
    }
    bool_1273 = decomp_var_3d0 > 0x0;
    if (decomp_var_3d0 >= 0x0) {
            if (!bool_1273) {
                    if (ebp >= 0x0) {
                            edx = decomp_var_428 & 0x80000000 ? 0xffffffff : 0x0;
                            if (ebp == decomp_var_428) {
                                    if (decomp_var_3d0 != edx) {
                                            if (esi == ebx[0x1]) {
                                                    sub_47a948();
                                            }
                                            decomp_var_438 = *((esi[0x4] * 0x15 + ebp) * 0x8 + 0x4d5528);
                                    }
                            }
                            else {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = *((esi[0x4] * 0x15 + ebp) * 0x8 + 0x4d5528);
                            }
                    }
            }
            else {
                    edx = decomp_var_428 & 0x80000000 ? 0xffffffff : 0x0;
                    if (ebp == decomp_var_428) {
                            if (decomp_var_3d0 != edx) {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = *((esi[0x4] * 0x15 + ebp) * 0x8 + 0x4d5528);
                            }
                    }
                    else {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = *((esi[0x4] * 0x15 + ebp) * 0x8 + 0x4d5528);
                    }
            }
    }
    bool_1280 = decomp_var_3f0 > 0x0;
    if (decomp_var_3f0 < 0x0 || !bool_1280 && decomp_var_3f4 < 0x0) goto .l48;
    goto .l42;

.l54:
    if (edi == 0x0 || edi != 0xbaed94) {
            sub_47a948();
    }
    if (esi == *dword_baed98) goto .l78;
    goto .l95;

.l8:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (*((esi[0x4] * 0x15 + decomp_var_3f4) * 0x8 + 0x4d5528) >= 0x3) {
            decomp_var_430 = 0xfffcf2c0;
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x6];
            }
    }
    else {
            if (decomp_var_438 < 0x3) {
                    if (decomp_var_430 < 0x3) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            bool_626 = esi != ebx[0x1];
                            eax = esi[0x4];
                            decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
                            decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
                            if (!bool_626) {
                                    sub_47a948();
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                            }
                            eax = esi[0x4];
                            ebp = eax + eax * 0x2;
                            eax = *(ebp * 0x4 + 0xbb65fc);
                            edi = eax[0x1];
                            ebp = ebp * 0x4 + 0xbb65f8;
                            ebx = eax;
                            if (edi[0x1d] == 0x0) {
                                    esp = esp - 0x4;
                                    if (sub_465cf0(esi + 0x28) != 0x0) {
                                            edi = edi[0x2];
                                    }
                                    else {
                                            ebx = edi;
                                            edi = *edi;
                                    }
                                    if (edi[0x1d] == 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                            decomp_var_3c0 = ebx;
                            decomp_var_3c4 = ebp;
                            if (ebx != arg_0) {
                                    esp = esp - 0x4;
                                    if (sub_465cf0(ebx + 0xc) == 0x0) {
                                            eax = &decomp_var_3c4;
                                            ecx = *eax;
                                            edi = eax[0x1];
                                            if (ecx != 0x0) {
                                                    if (ecx != decomp_var_438) {
                                                            sub_47a948();
                                                    }
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    sub_47a948();
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            decomp_var_3bc = ebp;
                                            eax = &decomp_var_3bc;
                                            ecx = *eax;
                                            edi = eax[0x1];
                                            if (ecx != 0x0) {
                                                    if (ecx != decomp_var_438) {
                                                            sub_47a948();
                                                    }
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    sub_47a948();
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    decomp_var_3bc = ebp;
                                    eax = &decomp_var_3bc;
                                    ecx = *eax;
                                    edi = eax[0x1];
                                    if (ecx != 0x0) {
                                            if (ecx != decomp_var_438) {
                                                    sub_47a948();
                                            }
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            decomp_var_430 = 0xfffcf2c0;
                            edi = decomp_var_40c;
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
            else {
                    decomp_var_430 = 0xfffcf2c0;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
    }
    goto loc_458d52;

.l39:
    if (decomp_var_3d0 == edx) goto .l25;
    goto loc_458a5d;

.l26:
    if (decomp_var_438 < 0x3) {
            if (decomp_var_430 < 0x3) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    bool_115 = esi != ebx[0x1];
                    eax = esi[0x4];
                    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
                    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
                    if (!bool_115) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    eax = esi[0x4];
                    ebp = eax + eax * 0x2;
                    eax = *(ebp * 0x4 + 0xbb65fc);
                    edi = eax[0x1];
                    ebp = ebp * 0x4 + 0xbb65f8;
                    ebx = eax;
                    if (edi[0x1d] == 0x0) {
                            esp = esp - 0x4;
                            if (sub_465cf0(esi + 0x28) != 0x0) {
                                    edi = edi[0x2];
                            }
                            else {
                                    ebx = edi;
                                    edi = *edi;
                            }
                            if (edi[0x1d] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    decomp_var_3c0 = ebx;
                    decomp_var_3c4 = ebp;
                    if (ebx != arg_0) {
                            esp = esp - 0x4;
                            if (sub_465cf0(ebx + 0xc) == 0x0) {
                                    eax = &decomp_var_3c4;
                                    ecx = *eax;
                                    edi = eax[0x1];
                                    if (ecx != 0x0) {
                                            if (ecx != decomp_var_438) {
                                                    sub_47a948();
                                            }
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    decomp_var_3bc = ebp;
                                    eax = &decomp_var_3bc;
                                    ecx = *eax;
                                    edi = eax[0x1];
                                    if (ecx != 0x0) {
                                            if (ecx != decomp_var_438) {
                                                    sub_47a948();
                                            }
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            decomp_var_3bc = ebp;
                            eax = &decomp_var_3bc;
                            ecx = *eax;
                            edi = eax[0x1];
                            if (ecx != 0x0) {
                                    if (ecx != decomp_var_438) {
                                            sub_47a948();
                                    }
                                    if (edi != decomp_var_290) {
                                            decomp_var_430 = 0xfffb6c20;
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x6];
                                            }
                                    }
                                    else {
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                    sub_465f30(&decomp_var_3f6);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                    eax = sub_465f30(&decomp_var_3f8);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                    }
                            }
                            else {
                                    sub_47a948();
                                    if (edi != decomp_var_290) {
                                            decomp_var_430 = 0xfffb6c20;
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x6];
                                            }
                                    }
                                    else {
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                    sub_465f30(&decomp_var_3f6);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                    eax = sub_465f30(&decomp_var_3f8);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    decomp_var_430 = 0xfffcf2c0;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
    }
    else {
            decomp_var_430 = 0xfffcf2c0;
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x6];
            }
    }
    goto loc_458d52;

loc_458a4c:
    if (ebp != eax) goto .l31;
    goto loc_458a50;
    if (decomp_var_414 == 0x0) {
            sub_47a948();
    }
    edx = decomp_var_414;
    if (ebx == edx[0x1]) {
            sub_47a948();
    }
    if (ebx[0x11] == 0x0) {
            if (ebx == decomp_var_414[0x1]) {
                    sub_47a948();
            }
            ebx[0x18] = 0x1;
            if (ebx == decomp_var_414[0x1]) {
                    sub_47a948();
            }
            edx = *dword_4c6bbc;
            ebx[0x8] = *dword_4c6bbc;
    }
    edi = 0xbb65ec;
    ebp = **dword_bb65f0;
    decomp_var_41c = 0xbb65ec;
    decomp_var_418 = **dword_bb65f0;
    continue;

.l48:
    if (decomp_var_438 < 0x3) {
            if (decomp_var_430 < 0x3) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    bool_1111 = esi != ebx[0x1];
                    eax = esi[0x4];
                    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
                    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
                    if (!bool_1111) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    eax = esi[0x4];
                    ebp = eax + eax * 0x2;
                    eax = *(ebp * 0x4 + 0xbb65fc);
                    edi = eax[0x1];
                    ebp = ebp * 0x4 + 0xbb65f8;
                    ebx = eax;
                    if (edi[0x1d] == 0x0) {
                            esp = esp - 0x4;
                            if (sub_465cf0(esi + 0x28) != 0x0) {
                                    edi = edi[0x2];
                            }
                            else {
                                    ebx = edi;
                                    edi = *edi;
                            }
                            if (edi[0x1d] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    decomp_var_3c0 = ebx;
                    decomp_var_3c4 = ebp;
                    if (ebx != arg_0) {
                            esp = esp - 0x4;
                            if (sub_465cf0(ebx + 0xc) == 0x0) {
                                    eax = &decomp_var_3c4;
                                    ecx = *eax;
                                    edi = eax[0x1];
                                    if (ecx != 0x0) {
                                            if (ecx != decomp_var_438) {
                                                    sub_47a948();
                                            }
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    decomp_var_3bc = ebp;
                                    eax = &decomp_var_3bc;
                                    ecx = *eax;
                                    edi = eax[0x1];
                                    if (ecx != 0x0) {
                                            if (ecx != decomp_var_438) {
                                                    sub_47a948();
                                            }
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            decomp_var_3bc = ebp;
                            eax = &decomp_var_3bc;
                            ecx = *eax;
                            edi = eax[0x1];
                            if (ecx != 0x0) {
                                    if (ecx != decomp_var_438) {
                                            sub_47a948();
                                    }
                                    if (edi != decomp_var_290) {
                                            decomp_var_430 = 0xfffb6c20;
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x6];
                                            }
                                    }
                                    else {
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                    sub_465f30(&decomp_var_3f6);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                    eax = sub_465f30(&decomp_var_3f8);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                    }
                            }
                            else {
                                    sub_47a948();
                                    if (edi != decomp_var_290) {
                                            decomp_var_430 = 0xfffb6c20;
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x6];
                                            }
                                    }
                                    else {
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                    sub_465f30(&decomp_var_3f6);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                    eax = sub_465f30(&decomp_var_3f8);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    decomp_var_430 = 0xfffcf2c0;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
    }
    else {
            decomp_var_430 = 0xfffcf2c0;
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x6];
            }
    }
    goto .l44;

.l42:
    eax = decomp_var_428;
    edx = eax & 0x80000000 ? 0xffffffff : 0x0;
    if (decomp_var_3f4 != eax || decomp_var_3f0 != edx) goto .l46;
    goto .l48;

.l78:
    break;

.l95:
    decomp_var_42c = 0x0;
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    ebx = decomp_var_428;
    if (esi[0x4] == ebx) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = ebx * 0x15 + esi[0x6];
            bool_2057 = *(eax * 0x8 + 0x4d552c) < 0x0;
            bool_1455 = *(eax * 0x8 + 0x4d552c) > 0x0;
            if (!bool_2057) {
                    if (!bool_1455) {
                            if (*(eax * 0x8 + 0x4d5528) >= 0x3) {
                                    esp = esp - 0x4;
                                    sub_465f30(0x4c6d38);
                                    decomp_var_420 = decomp_var_420 | 0x1;
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    esp = esp - 0x4;
                                    eax = sub_465df0(&decomp_var_27c);
                                    if (eax != 0x0) {
                                            ebx = 0x1;
                                    }
                                    else {
                                            ebx = 0x0;
                                    }
                            }
                            else {
                                    ebx = 0x0;
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            sub_465f30(0x4c6d38);
                            decomp_var_420 = decomp_var_420 | 0x1;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x4;
                            eax = sub_465df0(&decomp_var_27c);
                            if (eax != 0x0) {
                                    ebx = 0x1;
                            }
                            else {
                                    ebx = 0x0;
                            }
                    }
            }
            else {
                    ebx = 0x0;
            }
    }
    else {
            ebx = 0x0;
    }
    if ((decomp_var_420 & 0x1) != 0x0) {
            decomp_var_420 = decomp_var_420 & 0xfffffffe;
            sub_465fa0();
    }
    if (ebx != 0x0) {
            decomp_var_438 = 0x0;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = sub_466060(&decomp_var_1dc, 0x1);
            esp = esp - 0xc;
            sub_465ff0(eax);
            sub_465fa0();
            ebx = decomp_var_404;
            decomp_var_430 = 0x1e;
            do {
                    if (*ebx == 0x0) {
                            sub_47a948();
                    }
                    if (ebx[0x1] == *(*ebx + 0x4)) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    sub_465ff0(ebx[0x1] + 0xc);
                    ebp = sub_465930();
                    edi = 0x0;
                    if (ebp > 0x0) {
                            eax = sub_466060(&decomp_var_1bc, edi);
                            sub_465ff0(eax);
                            sub_465fa0();
                            esp = esp - 0x10;
                            eax = sub_465d90(&decomp_var_2b8);
                            if (eax != 0x0) {
                                    decomp_var_438 = decomp_var_438 + 0x1;
                            }
                            edi = edi + 0x1;
                            if (edi < ebp) {
                                    continue;
                            }
                            break;
                    }
                    ebx = ebx + 0x8;
                    decomp_var_430 = decomp_var_430 - 0x1;
            } while (decomp_var_430 != 0x0);
            if (decomp_var_438 > 0x2) {
                    decomp_var_42c = 0x1;
                    ebx = 0x1;
            }
            else {
                    edi = decomp_var_40c;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    ebx = decomp_var_428;
                    if (esi[0x6] == ebx) {
                            esp = esp - 0x4;
                            sub_465f30(0x4c6d38);
                            decomp_var_420 = decomp_var_420 | 0x2;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x4;
                            eax = sub_465df0(&decomp_var_26c);
                            if (eax != 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    eax = esi[0x4];
                                    eax = eax * 0x15 + ebx;
                                    bool_2027 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                    if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                            if (!bool_2027) {
                                                    if (*(eax * 0x8 + 0x4d5528) <= 0x2) {
                                                            ebx = 0x0;
                                                    }
                                                    else {
                                                            ebx = 0x1;
                                                    }
                                            }
                                            else {
                                                    ebx = 0x0;
                                            }
                                    }
                                    else {
                                            ebx = 0x1;
                                    }
                            }
                            else {
                                    ebx = 0x0;
                            }
                    }
                    else {
                            ebx = 0x0;
                    }
            }
    }
    else {
            edi = decomp_var_40c;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            ebx = decomp_var_428;
            if (esi[0x6] == ebx) {
                    esp = esp - 0x4;
                    sub_465f30(0x4c6d38);
                    decomp_var_420 = decomp_var_420 | 0x2;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_465df0(&decomp_var_26c);
                    if (eax != 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            eax = esi[0x4];
                            eax = eax * 0x15 + ebx;
                            bool_2027 = *(eax * 0x8 + 0x4d552c) < 0x0;
                            if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                    if (!bool_2027) {
                                            if (*(eax * 0x8 + 0x4d5528) <= 0x2) {
                                                    ebx = 0x0;
                                            }
                                            else {
                                                    ebx = 0x1;
                                            }
                                    }
                                    else {
                                            ebx = 0x0;
                                    }
                            }
                            else {
                                    ebx = 0x1;
                            }
                    }
                    else {
                            ebx = 0x0;
                    }
            }
            else {
                    ebx = 0x0;
            }
    }
    if ((decomp_var_420 & 0x2) != 0x0) {
            decomp_var_420 = decomp_var_420 & 0xfffffffd;
            sub_465fa0();
    }
    if (ebx == 0x0) {
            sub_40f7f0();
            esi = decomp_var_408;
            ebx = decomp_var_410;
            edi = decomp_var_40c;
            continue;
    }
    ebx = decomp_var_40c;
    decomp_var_438 = 0x0;
    decomp_var_430 = 0x0;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    bool_1847 = esi != ebx[0x1];
    eax = esi[0x8];
    ebp = *(eax * 0x8 + 0x4d2610);
    decomp_var_3d0 = *(eax * 0x8 + 0x4d2614);
    if (!bool_1847) {
            sub_47a948();
    }
    bool_1965 = esi != ebx[0x1];
    eax = esi[0x8];
    decomp_var_3f4 = *(eax * 0x8 + 0x4d2e10);
    decomp_var_3f0 = *(eax * 0x8 + 0x4d2e14);
    if (!bool_1965) {
            sub_47a948();
    }
    eax = esi[0x8];
    ecx = *(eax * 0x8 + 0x4d3614);
    bool_1386 = ecx > 0x0;
    edi = *(eax * 0x8 + 0x4d3610);
    if (ecx >= 0x0) {
            if (!bool_1386) {
                    if (edi >= 0x0) {
                            edx = decomp_var_428 & 0x80000000 ? 0xffffffff : 0x0;
                            if (edi == decomp_var_428) {
                                    if (ecx != edx) {
                                            if (esi == ebx[0x1]) {
                                                    sub_47a948();
                                            }
                                            decomp_var_430 = *((esi[0x4] * 0x15 + edi) * 0x8 + 0x4d5528);
                                    }
                            }
                            else {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_430 = *((esi[0x4] * 0x15 + edi) * 0x8 + 0x4d5528);
                            }
                    }
            }
            else {
                    edx = decomp_var_428 & 0x80000000 ? 0xffffffff : 0x0;
                    if (edi == decomp_var_428) {
                            if (ecx != edx) {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_430 = *((esi[0x4] * 0x15 + edi) * 0x8 + 0x4d5528);
                            }
                    }
                    else {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_430 = *((esi[0x4] * 0x15 + edi) * 0x8 + 0x4d5528);
                    }
            }
    }
    bool_1609 = decomp_var_3d0 > 0x0;
    if (decomp_var_3d0 >= 0x0) {
            if (!bool_1609) {
                    if (ebp >= 0x0) {
                            edx = decomp_var_428 & 0x80000000 ? 0xffffffff : 0x0;
                            if (ebp == decomp_var_428) {
                                    if (decomp_var_3d0 != edx) {
                                            if (esi == ebx[0x1]) {
                                                    sub_47a948();
                                            }
                                            decomp_var_438 = *((esi[0x4] * 0x15 + ebp) * 0x8 + 0x4d5528);
                                    }
                            }
                            else {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = *((esi[0x4] * 0x15 + ebp) * 0x8 + 0x4d5528);
                            }
                    }
            }
            else {
                    edx = decomp_var_428 & 0x80000000 ? 0xffffffff : 0x0;
                    if (ebp == decomp_var_428) {
                            if (decomp_var_3d0 != edx) {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = *((esi[0x4] * 0x15 + ebp) * 0x8 + 0x4d5528);
                            }
                    }
                    else {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = *((esi[0x4] * 0x15 + ebp) * 0x8 + 0x4d5528);
                    }
            }
    }
    bool_1867 = decomp_var_3f0 > 0x0;
    if (decomp_var_3f0 < 0x0 || !bool_1867 && decomp_var_3f4 < 0x0) goto .l62;
    goto .l51;

.l25:
    if (decomp_var_438 >= 0x3) goto .l6;
    goto .l33;

loc_458a5d:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (*((esi[0x4] * 0x15 + decomp_var_3f4) * 0x8 + 0x4d5528) < 0x3) goto .l18;
    goto .l7;

.l31:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (*((esi[0x4] * 0x15 + decomp_var_3f4) * 0x8 + 0x4d5528) >= 0x3) {
            decomp_var_430 = 0xfffcf2c0;
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x6];
            }
    }
    else {
            if (decomp_var_438 < 0x3) {
                    if (decomp_var_430 < 0x3) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            bool_335 = esi != ebx[0x1];
                            eax = esi[0x4];
                            decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
                            decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
                            if (!bool_335) {
                                    sub_47a948();
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                            }
                            eax = esi[0x4];
                            ebp = eax + eax * 0x2;
                            eax = *(ebp * 0x4 + 0xbb65fc);
                            edi = eax[0x1];
                            ebp = ebp * 0x4 + 0xbb65f8;
                            ebx = eax;
                            if (edi[0x1d] == 0x0) {
                                    esp = esp - 0x4;
                                    if (sub_465cf0(esi + 0x28) != 0x0) {
                                            edi = edi[0x2];
                                    }
                                    else {
                                            ebx = edi;
                                            edi = *edi;
                                    }
                                    if (edi[0x1d] == 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                            decomp_var_3c0 = ebx;
                            decomp_var_3c4 = ebp;
                            if (ebx != arg_0) {
                                    esp = esp - 0x4;
                                    if (sub_465cf0(ebx + 0xc) == 0x0) {
                                            eax = &decomp_var_3c4;
                                            ecx = *eax;
                                            edi = eax[0x1];
                                            if (ecx != 0x0) {
                                                    if (ecx != decomp_var_438) {
                                                            sub_47a948();
                                                    }
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    sub_47a948();
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            decomp_var_3bc = ebp;
                                            eax = &decomp_var_3bc;
                                            ecx = *eax;
                                            edi = eax[0x1];
                                            if (ecx != 0x0) {
                                                    if (ecx != decomp_var_438) {
                                                            sub_47a948();
                                                    }
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    sub_47a948();
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    decomp_var_3bc = ebp;
                                    eax = &decomp_var_3bc;
                                    ecx = *eax;
                                    edi = eax[0x1];
                                    if (ecx != 0x0) {
                                            if (ecx != decomp_var_438) {
                                                    sub_47a948();
                                            }
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            decomp_var_430 = 0xfffcf2c0;
                            edi = decomp_var_40c;
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
            else {
                    decomp_var_430 = 0xfffcf2c0;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
    }
    goto loc_458d52;

loc_458a50:
    if (decomp_var_3d0 == edx) goto .l27;
    goto .l9;

.l44:
    eax = decomp_var_39c;
    ebp = eax[0x1];
    edi = ebp;
    if (arg_d == 0x0) {
            do {
                    sub_401950(edi[0x2]);
                    edi = *edi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    ebp = edi;
            } while (edi[0x11] == 0x0);
            eax = decomp_var_39c;
    }
    eax[0x1] = eax;
    *decomp_var_39c = decomp_var_39c;
    decomp_var_39c[0x2] = decomp_var_39c;
    eax = sub_404ce0(&decomp_var_170, &decomp_var_428, decomp_var_450);
    esp = esp - 0x10;
    eax = sub_404ce0(&decomp_var_188, &decomp_var_438, decomp_var_450);
    eax = decomp_var_390;
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
            } while (arg_19 == 0x0);
            eax = decomp_var_390;
    }
    eax[0x1] = eax;
    *decomp_var_390 = decomp_var_390;
    decomp_var_390[0x2] = decomp_var_390;
    eax = decomp_var_384;
    edi = eax[0x1];
    ebp = edi;
    if (edi[0x1d] != 0x0) {
            eax[0x1] = eax;
            decomp_var_380 = 0x0;
            *decomp_var_384 = decomp_var_384;
            decomp_var_384[0x2] = decomp_var_384;
            if (decomp_var_414 == 0x0) {
                    sub_47a948();
            }
            ebx = decomp_var_410;
            if (ebx == decomp_var_414[0x1]) {
                    sub_47a948();
            }
            if (esi == arg_0) {
                    sub_47a948();
            }
            edi = esi + 0x28;
            eax = sub_419300(&decomp_var_158, edi, decomp_var_450);
            decomp_var_3a8 = 0x1;
            decomp_var_3ac = 0x0;
            eax = sub_466f80(&decomp_var_1cc, 0xbc1e0c);
            esp = esp - 0x14;
            sub_465ff0(eax);
            sub_465fa0();
            if (esi == arg_0) {
                    sub_47a948();
            }
            sub_465ff0(edi);
            decomp_var_42c = decomp_var_438 & 0xff | 0x4100;
            eax = sub_465f30(&decomp_var_42c);
            esp = esp - 0xc;
            eax = sub_465ff0(&decomp_var_24c);
            sub_465fa0();
            ecx = decomp_var_434[0x2];
            ebp = decomp_var_430;
            eax = 0x0;
            if (ecx[0x901] <= 0x0) {
                    edi = *dword_bb65f4;
                    sub_4222a0(&decomp_var_3ac);
                    esp = esp - 0xc;
                    eax = sub_430480(&decomp_var_1a0, &decomp_var_14c, decomp_var_450);
                    sub_41cc50();
                    *dword_baed60 = edi;
                    if (ebp != 0x0) {
                            sub_40f7f0();
                            esi = decomp_var_408;
                            ebx = decomp_var_410;
                            edi = decomp_var_40c;
                            continue;
                    }
                    if (esi == decomp_var_40c[0x1]) {
                            sub_47a948();
                    }
                    edi = decomp_var_414;
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_419300(&decomp_var_1ac, esi + 0x28, decomp_var_450);
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_1268 = ebx != decomp_var_414[0x1];
                    ebp = ebx[0xa];
                    esi = ebx + 0x24;
                    if (!bool_1268) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_401ff0(&decomp_var_23c, &decomp_var_438, decomp_var_450, decomp_var_44c, decomp_var_448);
                    edi = eax;
                    eax = *edi;
                    if (eax == 0x0 || eax != esi) {
                            sub_47a948();
                    }
                    if (edi[0x1] == ebp) {
                            if (ebx == decomp_var_414[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x8;
                            eax = sub_404ce0(&decomp_var_164, &decomp_var_438, decomp_var_450);
                    }
                    sub_40f7f0();
                    esi = decomp_var_408;
                    ebx = decomp_var_410;
                    edi = decomp_var_40c;
                    continue;
            }
            &decomp_var_450 = &decomp_var_450;
            do {
                    if (ebp == 0x0) {
                            *(&decomp_var_450 + eax * 0x4 + 0xd4) = 0x0;
                    }
                    else {
                            *(&decomp_var_450 + eax * 0x4 + 0xd4) = ebp;
                            decomp_var_3ac = 0x1;
                    }
                    eax = eax + 0x1;
            } while (eax < ecx[0x901]);
            edi = *dword_bb65f4;
            sub_4222a0(&decomp_var_3ac);
            esp = esp - 0xc;
            eax = sub_430480(&decomp_var_1a0, &decomp_var_14c, decomp_var_450);
            sub_41cc50();
            *dword_baed60 = edi;
            if (ebp != 0x0) {
                    sub_40f7f0();
                    esi = decomp_var_408;
                    ebx = decomp_var_410;
                    edi = decomp_var_40c;
                    continue;
            }
            if (esi == decomp_var_40c[0x1]) {
                    sub_47a948();
            }
            edi = decomp_var_414;
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_419300(&decomp_var_1ac, esi + 0x28, decomp_var_450);
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            bool_1268 = ebx != decomp_var_414[0x1];
            ebp = ebx[0xa];
            esi = ebx + 0x24;
            if (!bool_1268) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&decomp_var_23c, &decomp_var_438, decomp_var_450, decomp_var_44c, decomp_var_448);
            edi = eax;
            eax = *edi;
            if (eax == 0x0 || eax != esi) {
                    sub_47a948();
            }
            if (edi[0x1] == ebp) {
                    if (ebx == decomp_var_414[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_404ce0(&decomp_var_164, &decomp_var_438, decomp_var_450);
            }
            sub_40f7f0();
            esi = decomp_var_408;
            ebx = decomp_var_410;
            edi = decomp_var_40c;
            continue;
    }
    do {
            sub_410cf0(arg_4);
            ebp = *ebp;
            sub_465fa0();
            sub_47c8f9();
            esp = (esp - 0x8) + 0x4;
            edi = ebp;
    } while (arg_19 == 0x0);
    eax = decomp_var_384;
    eax[0x1] = eax;
    decomp_var_380 = 0x0;
    *decomp_var_384 = decomp_var_384;
    decomp_var_384[0x2] = decomp_var_384;
    if (decomp_var_414 == 0x0) {
            sub_47a948();
    }
    ebx = decomp_var_410;
    if (ebx == decomp_var_414[0x1]) {
            sub_47a948();
    }
    if (esi == arg_0) {
            sub_47a948();
    }
    edi = esi + 0x28;
    eax = sub_419300(&decomp_var_158, edi, decomp_var_450);
    decomp_var_3a8 = 0x1;
    decomp_var_3ac = 0x0;
    eax = sub_466f80(&decomp_var_1cc, 0xbc1e0c);
    esp = esp - 0x14;
    sub_465ff0(eax);
    sub_465fa0();
    if (esi == arg_0) {
            sub_47a948();
    }
    sub_465ff0(edi);
    decomp_var_42c = decomp_var_438 & 0xff | 0x4100;
    eax = sub_465f30(&decomp_var_42c);
    esp = esp - 0xc;
    eax = sub_465ff0(&decomp_var_24c);
    sub_465fa0();
    ecx = decomp_var_434[0x2];
    ebp = decomp_var_430;
    eax = 0x0;
    if (ecx[0x901] <= 0x0) {
            edi = *dword_bb65f4;
            sub_4222a0(&decomp_var_3ac);
            esp = esp - 0xc;
            eax = sub_430480(&decomp_var_1a0, &decomp_var_14c, decomp_var_450);
            sub_41cc50();
            *dword_baed60 = edi;
            if (ebp != 0x0) {
                    sub_40f7f0();
                    esi = decomp_var_408;
                    ebx = decomp_var_410;
                    edi = decomp_var_40c;
                    continue;
            }
            if (esi == decomp_var_40c[0x1]) {
                    sub_47a948();
            }
            edi = decomp_var_414;
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_419300(&decomp_var_1ac, esi + 0x28, decomp_var_450);
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            bool_1268 = ebx != decomp_var_414[0x1];
            ebp = ebx[0xa];
            esi = ebx + 0x24;
            if (!bool_1268) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&decomp_var_23c, &decomp_var_438, decomp_var_450, decomp_var_44c, decomp_var_448);
            edi = eax;
            eax = *edi;
            if (eax == 0x0 || eax != esi) {
                    sub_47a948();
            }
            if (edi[0x1] == ebp) {
                    if (ebx == decomp_var_414[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_404ce0(&decomp_var_164, &decomp_var_438, decomp_var_450);
            }
            sub_40f7f0();
            esi = decomp_var_408;
            ebx = decomp_var_410;
            edi = decomp_var_40c;
            continue;
    }
    &decomp_var_450 = &decomp_var_450;
    do {
            if (ebp == 0x0) {
                    *(&decomp_var_450 + eax * 0x4 + 0xd4) = 0x0;
            }
            else {
                    *(&decomp_var_450 + eax * 0x4 + 0xd4) = ebp;
                    decomp_var_3ac = 0x1;
            }
            eax = eax + 0x1;
    } while (eax < ecx[0x901]);
    edi = *dword_bb65f4;
    sub_4222a0(&decomp_var_3ac);
    esp = esp - 0xc;
    eax = sub_430480(&decomp_var_1a0, &decomp_var_14c, decomp_var_450);
    sub_41cc50();
    *dword_baed60 = edi;
    if (ebp != 0x0) {
            sub_40f7f0();
            esi = decomp_var_408;
            ebx = decomp_var_410;
            edi = decomp_var_40c;
            continue;
    }
    if (esi == decomp_var_40c[0x1]) {
            sub_47a948();
    }
    edi = decomp_var_414;
    if (ebx == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    eax = sub_419300(&decomp_var_1ac, esi + 0x28, decomp_var_450);
    if (ebx == edi[0x1]) {
            sub_47a948();
    }
    bool_1268 = ebx != decomp_var_414[0x1];
    ebp = ebx[0xa];
    esi = ebx + 0x24;
    if (!bool_1268) {
            sub_47a948();
    }
    esp = esp - 0x8;
    eax = sub_401ff0(&decomp_var_23c, &decomp_var_438, decomp_var_450, decomp_var_44c, decomp_var_448);
    edi = eax;
    eax = *edi;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (edi[0x1] == ebp) {
            if (ebx == decomp_var_414[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_404ce0(&decomp_var_164, &decomp_var_438, decomp_var_450);
    }
    sub_40f7f0();
    esi = decomp_var_408;
    ebx = decomp_var_410;
    edi = decomp_var_40c;
    continue;

.l46:
    if (ebp == eax) {
            if (decomp_var_3d0 != edx) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (*((esi[0x4] * 0x15 + decomp_var_3f4) * 0x8 + 0x4d5528) >= 0x3) {
                            decomp_var_430 = 0xfffcf2c0;
                            edi = decomp_var_40c;
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
                    else {
                            if (decomp_var_438 < 0x3) {
                                    if (decomp_var_430 < 0x3) {
                                            if (esi == ebx[0x1]) {
                                                    sub_47a948();
                                            }
                                            bool_1281 = esi != ebx[0x1];
                                            eax = esi[0x4];
                                            decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
                                            decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
                                            if (!bool_1281) {
                                                    sub_47a948();
                                                    if (esi == ebx[0x1]) {
                                                            sub_47a948();
                                                    }
                                            }
                                            eax = esi[0x4];
                                            ebp = eax + eax * 0x2;
                                            eax = *(ebp * 0x4 + 0xbb65fc);
                                            edi = eax[0x1];
                                            ebp = ebp * 0x4 + 0xbb65f8;
                                            ebx = eax;
                                            if (edi[0x1d] == 0x0) {
                                                    esp = esp - 0x4;
                                                    if (sub_465cf0(esi + 0x28) != 0x0) {
                                                            edi = edi[0x2];
                                                    }
                                                    else {
                                                            ebx = edi;
                                                            edi = *edi;
                                                    }
                                                    if (edi[0x1d] == 0x0) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            decomp_var_3c0 = ebx;
                                            decomp_var_3c4 = ebp;
                                            if (ebx != arg_0) {
                                                    esp = esp - 0x4;
                                                    if (sub_465cf0(ebx + 0xc) == 0x0) {
                                                            eax = &decomp_var_3c4;
                                                    }
                                                    else {
                                                            decomp_var_3bc = ebp;
                                                            eax = &decomp_var_3bc;
                                                    }
                                            }
                                            else {
                                                    decomp_var_3bc = ebp;
                                                    eax = &decomp_var_3bc;
                                            }
                                            ecx = *eax;
                                            edi = eax[0x1];
                                            if (ecx != 0x0) {
                                                    if (ecx != decomp_var_438) {
                                                            sub_47a948();
                                                    }
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    sub_47a948();
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            decomp_var_430 = 0xfffcf2c0;
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x6];
                                            }
                                    }
                            }
                            else {
                                    decomp_var_430 = 0xfffcf2c0;
                                    edi = decomp_var_40c;
                                    if (decomp_var_42c == 0x0) {
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            decomp_var_438 = esi[0x4];
                                    }
                                    else {
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            decomp_var_438 = esi[0x6];
                                    }
                            }
                    }
            }
            else {
                    if (decomp_var_438 < 0x3) {
                            if (decomp_var_430 < 0x3) {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    bool_1118 = esi != ebx[0x1];
                                    eax = esi[0x4];
                                    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
                                    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
                                    if (!bool_1118) {
                                            sub_47a948();
                                            if (esi == ebx[0x1]) {
                                                    sub_47a948();
                                            }
                                    }
                                    eax = esi[0x4];
                                    ebp = eax + eax * 0x2;
                                    eax = *(ebp * 0x4 + 0xbb65fc);
                                    edi = eax[0x1];
                                    ebp = ebp * 0x4 + 0xbb65f8;
                                    ebx = eax;
                                    if (edi[0x1d] == 0x0) {
                                            esp = esp - 0x4;
                                            if (sub_465cf0(esi + 0x28) != 0x0) {
                                                    edi = edi[0x2];
                                            }
                                            else {
                                                    ebx = edi;
                                                    edi = *edi;
                                            }
                                            if (edi[0x1d] == 0x0) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    decomp_var_3c0 = ebx;
                                    decomp_var_3c4 = ebp;
                                    if (ebx != arg_0) {
                                            esp = esp - 0x4;
                                            if (sub_465cf0(ebx + 0xc) == 0x0) {
                                                    eax = &decomp_var_3c4;
                                                    ecx = *eax;
                                                    edi = eax[0x1];
                                                    if (ecx != 0x0) {
                                                            if (ecx != decomp_var_438) {
                                                                    sub_47a948();
                                                            }
                                                            if (edi != decomp_var_290) {
                                                                    decomp_var_430 = 0xfffb6c20;
                                                                    edi = decomp_var_40c;
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                            else {
                                                                    edi = decomp_var_40c;
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                            sub_465f30(&decomp_var_3f6);
                                                                            esp = esp - 0x18;
                                                                            decomp_var_464 = ecx;
                                                                            decomp_var_430 = &decomp_var_464;
                                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            esp = esp - 0x14;
                                                                            sub_465f60(esi + 0x28);
                                                                            sub_422a90();
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                            eax = sub_465f30(&decomp_var_3f8);
                                                                            esp = esp - 0x18;
                                                                            decomp_var_464 = ecx;
                                                                            decomp_var_430 = &decomp_var_464;
                                                                            decomp_var_464 = decomp_var_424;
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            esp = esp - 0x14;
                                                                            sub_465f60(esi + 0x28);
                                                                            sub_422a90();
                                                                            if (decomp_var_42c == 0x0) {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    decomp_var_438 = esi[0x4];
                                                                            }
                                                                            else {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    decomp_var_438 = esi[0x6];
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            sub_47a948();
                                                            if (edi != decomp_var_290) {
                                                                    decomp_var_430 = 0xfffb6c20;
                                                                    edi = decomp_var_40c;
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                            else {
                                                                    edi = decomp_var_40c;
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                            sub_465f30(&decomp_var_3f6);
                                                                            esp = esp - 0x18;
                                                                            decomp_var_464 = ecx;
                                                                            decomp_var_430 = &decomp_var_464;
                                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            esp = esp - 0x14;
                                                                            sub_465f60(esi + 0x28);
                                                                            sub_422a90();
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                            eax = sub_465f30(&decomp_var_3f8);
                                                                            esp = esp - 0x18;
                                                                            decomp_var_464 = ecx;
                                                                            decomp_var_430 = &decomp_var_464;
                                                                            decomp_var_464 = decomp_var_424;
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            esp = esp - 0x14;
                                                                            sub_465f60(esi + 0x28);
                                                                            sub_422a90();
                                                                            if (decomp_var_42c == 0x0) {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    decomp_var_438 = esi[0x4];
                                                                            }
                                                                            else {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    decomp_var_438 = esi[0x6];
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    decomp_var_3bc = ebp;
                                                    eax = &decomp_var_3bc;
                                                    ecx = *eax;
                                                    edi = eax[0x1];
                                                    if (ecx == 0x0 || ecx != decomp_var_438) {
                                                            sub_47a948();
                                                    }
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            decomp_var_3bc = ebp;
                                            eax = &decomp_var_3bc;
                                            ecx = *eax;
                                            edi = eax[0x1];
                                            if (ecx != 0x0) {
                                                    if (ecx != decomp_var_438) {
                                                            sub_47a948();
                                                    }
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    sub_47a948();
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    decomp_var_430 = 0xfffcf2c0;
                                    edi = decomp_var_40c;
                                    if (decomp_var_42c == 0x0) {
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            decomp_var_438 = esi[0x4];
                                    }
                                    else {
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            decomp_var_438 = esi[0x6];
                                    }
                            }
                    }
                    else {
                            decomp_var_430 = 0xfffcf2c0;
                            edi = decomp_var_40c;
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    else {
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (*((esi[0x4] * 0x15 + decomp_var_3f4) * 0x8 + 0x4d5528) >= 0x3) {
                    decomp_var_430 = 0xfffcf2c0;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    if (decomp_var_438 < 0x3) {
                            if (decomp_var_430 < 0x3) {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    bool_1166 = esi != ebx[0x1];
                                    eax = esi[0x4];
                                    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
                                    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
                                    if (!bool_1166) {
                                            sub_47a948();
                                            if (esi == ebx[0x1]) {
                                                    sub_47a948();
                                            }
                                    }
                                    eax = esi[0x4];
                                    ebp = eax + eax * 0x2;
                                    eax = *(ebp * 0x4 + 0xbb65fc);
                                    edi = eax[0x1];
                                    ebp = ebp * 0x4 + 0xbb65f8;
                                    ebx = eax;
                                    if (edi[0x1d] == 0x0) {
                                            esp = esp - 0x4;
                                            if (sub_465cf0(esi + 0x28) != 0x0) {
                                                    edi = edi[0x2];
                                            }
                                            else {
                                                    ebx = edi;
                                                    edi = *edi;
                                            }
                                            if (edi[0x1d] == 0x0) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    decomp_var_3c0 = ebx;
                                    decomp_var_3c4 = ebp;
                                    if (ebx != arg_0) {
                                            esp = esp - 0x4;
                                            if (sub_465cf0(ebx + 0xc) == 0x0) {
                                                    eax = &decomp_var_3c4;
                                                    ecx = *eax;
                                                    edi = eax[0x1];
                                                    if (ecx != 0x0) {
                                                            if (ecx != decomp_var_438) {
                                                                    sub_47a948();
                                                            }
                                                            if (edi != decomp_var_290) {
                                                                    decomp_var_430 = 0xfffb6c20;
                                                                    edi = decomp_var_40c;
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                            else {
                                                                    edi = decomp_var_40c;
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                            sub_465f30(&decomp_var_3f6);
                                                                            esp = esp - 0x18;
                                                                            decomp_var_464 = ecx;
                                                                            decomp_var_430 = &decomp_var_464;
                                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            esp = esp - 0x14;
                                                                            sub_465f60(esi + 0x28);
                                                                            sub_422a90();
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                            eax = sub_465f30(&decomp_var_3f8);
                                                                            esp = esp - 0x18;
                                                                            decomp_var_464 = ecx;
                                                                            decomp_var_430 = &decomp_var_464;
                                                                            decomp_var_464 = decomp_var_424;
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            esp = esp - 0x14;
                                                                            sub_465f60(esi + 0x28);
                                                                            sub_422a90();
                                                                            if (decomp_var_42c == 0x0) {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    decomp_var_438 = esi[0x4];
                                                                            }
                                                                            else {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    decomp_var_438 = esi[0x6];
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            sub_47a948();
                                                            if (edi != decomp_var_290) {
                                                                    decomp_var_430 = 0xfffb6c20;
                                                                    edi = decomp_var_40c;
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                            else {
                                                                    edi = decomp_var_40c;
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                            sub_465f30(&decomp_var_3f6);
                                                                            esp = esp - 0x18;
                                                                            decomp_var_464 = ecx;
                                                                            decomp_var_430 = &decomp_var_464;
                                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            esp = esp - 0x14;
                                                                            sub_465f60(esi + 0x28);
                                                                            sub_422a90();
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                            eax = sub_465f30(&decomp_var_3f8);
                                                                            esp = esp - 0x18;
                                                                            decomp_var_464 = ecx;
                                                                            decomp_var_430 = &decomp_var_464;
                                                                            decomp_var_464 = decomp_var_424;
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            esp = esp - 0x14;
                                                                            sub_465f60(esi + 0x28);
                                                                            sub_422a90();
                                                                            if (decomp_var_42c == 0x0) {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    decomp_var_438 = esi[0x4];
                                                                            }
                                                                            else {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    decomp_var_438 = esi[0x6];
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    decomp_var_3bc = ebp;
                                                    eax = &decomp_var_3bc;
                                                    ecx = *eax;
                                                    edi = eax[0x1];
                                                    if (ecx != 0x0) {
                                                            if (ecx != decomp_var_438) {
                                                                    sub_47a948();
                                                            }
                                                            if (edi != decomp_var_290) {
                                                                    decomp_var_430 = 0xfffb6c20;
                                                                    edi = decomp_var_40c;
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                            else {
                                                                    edi = decomp_var_40c;
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                            sub_465f30(&decomp_var_3f6);
                                                                            esp = esp - 0x18;
                                                                            decomp_var_464 = ecx;
                                                                            decomp_var_430 = &decomp_var_464;
                                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            esp = esp - 0x14;
                                                                            sub_465f60(esi + 0x28);
                                                                            sub_422a90();
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                            eax = sub_465f30(&decomp_var_3f8);
                                                                            esp = esp - 0x18;
                                                                            decomp_var_464 = ecx;
                                                                            decomp_var_430 = &decomp_var_464;
                                                                            decomp_var_464 = decomp_var_424;
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            esp = esp - 0x14;
                                                                            sub_465f60(esi + 0x28);
                                                                            sub_422a90();
                                                                            if (decomp_var_42c == 0x0) {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    decomp_var_438 = esi[0x4];
                                                                            }
                                                                            else {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    decomp_var_438 = esi[0x6];
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            sub_47a948();
                                                            if (edi != decomp_var_290) {
                                                                    decomp_var_430 = 0xfffb6c20;
                                                                    edi = decomp_var_40c;
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                            else {
                                                                    edi = decomp_var_40c;
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                            sub_465f30(&decomp_var_3f6);
                                                                            esp = esp - 0x18;
                                                                            decomp_var_464 = ecx;
                                                                            decomp_var_430 = &decomp_var_464;
                                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            esp = esp - 0x14;
                                                                            sub_465f60(esi + 0x28);
                                                                            sub_422a90();
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                            eax = sub_465f30(&decomp_var_3f8);
                                                                            esp = esp - 0x18;
                                                                            decomp_var_464 = ecx;
                                                                            decomp_var_430 = &decomp_var_464;
                                                                            decomp_var_464 = decomp_var_424;
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            esp = esp - 0x14;
                                                                            sub_465f60(esi + 0x28);
                                                                            sub_422a90();
                                                                            if (decomp_var_42c == 0x0) {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    decomp_var_438 = esi[0x4];
                                                                            }
                                                                            else {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    decomp_var_438 = esi[0x6];
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            decomp_var_3bc = ebp;
                                            eax = &decomp_var_3bc;
                                            ecx = *eax;
                                            edi = eax[0x1];
                                            if (ecx != 0x0) {
                                                    if (ecx != decomp_var_438) {
                                                            sub_47a948();
                                                    }
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    sub_47a948();
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    decomp_var_430 = 0xfffcf2c0;
                                    edi = decomp_var_40c;
                                    if (decomp_var_42c == 0x0) {
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            decomp_var_438 = esi[0x4];
                                    }
                                    else {
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            decomp_var_438 = esi[0x6];
                                    }
                            }
                    }
                    else {
                            decomp_var_430 = 0xfffcf2c0;
                            edi = decomp_var_40c;
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    goto .l44;
    if (decomp_var_414 == 0x0) {
            sub_47a948();
    }
    edx = decomp_var_414;
    if (ebx == edx[0x1]) {
            sub_47a948();
    }
    if (ebx[0x11] == 0x0) {
            if (ebx == decomp_var_414[0x1]) {
                    sub_47a948();
            }
            ebx[0x18] = 0x1;
            if (ebx == decomp_var_414[0x1]) {
                    sub_47a948();
            }
            edx = *dword_4c6bbc;
            ebx[0x8] = *dword_4c6bbc;
    }
    edi = 0xbb65ec;
    ebp = **dword_bb65f0;
    decomp_var_41c = 0xbb65ec;
    decomp_var_418 = **dword_bb65f0;
    continue;

.l62:
    if (decomp_var_438 < 0x3) {
            if (decomp_var_430 < 0x3) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    bool_1659 = esi != ebx[0x1];
                    eax = esi[0x4];
                    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
                    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
                    if (!bool_1659) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    eax = esi[0x4];
                    ebp = eax + eax * 0x2;
                    eax = *(ebp * 0x4 + 0xbb65fc);
                    edi = eax[0x1];
                    ebp = ebp * 0x4 + 0xbb65f8;
                    ebx = eax;
                    if (edi[0x1d] == 0x0) {
                            esp = esp - 0x4;
                            if (sub_465cf0(esi + 0x28) != 0x0) {
                                    edi = edi[0x2];
                            }
                            else {
                                    ebx = edi;
                                    edi = *edi;
                            }
                            if (edi[0x1d] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    decomp_var_3c0 = ebx;
                    decomp_var_3c4 = ebp;
                    if (ebx != arg_0) {
                            esp = esp - 0x4;
                            if (sub_465cf0(ebx + 0xc) == 0x0) {
                                    eax = &decomp_var_3c4;
                                    ecx = *eax;
                                    edi = eax[0x1];
                                    if (ecx != 0x0) {
                                            if (ecx != decomp_var_438) {
                                                    sub_47a948();
                                            }
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    decomp_var_3bc = ebp;
                                    eax = &decomp_var_3bc;
                                    ecx = *eax;
                                    edi = eax[0x1];
                                    if (ecx != 0x0) {
                                            if (ecx != decomp_var_438) {
                                                    sub_47a948();
                                            }
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            decomp_var_3bc = ebp;
                            eax = &decomp_var_3bc;
                            ecx = *eax;
                            edi = eax[0x1];
                            if (ecx != 0x0) {
                                    if (ecx != decomp_var_438) {
                                            sub_47a948();
                                    }
                                    if (edi != decomp_var_290) {
                                            decomp_var_430 = 0xfffb6c20;
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x6];
                                            }
                                    }
                                    else {
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                    sub_465f30(&decomp_var_3f6);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                    eax = sub_465f30(&decomp_var_3f8);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                    }
                            }
                            else {
                                    sub_47a948();
                                    if (edi != decomp_var_290) {
                                            decomp_var_430 = 0xfffb6c20;
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x6];
                                            }
                                    }
                                    else {
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                    sub_465f30(&decomp_var_3f6);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                    eax = sub_465f30(&decomp_var_3f8);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    decomp_var_430 = 0xfffcf2c0;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
    }
    else {
            decomp_var_430 = 0xfffcf2c0;
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x6];
            }
    }
    goto .l82;

.l51:
    eax = decomp_var_428;
    edx = eax & 0x80000000 ? 0xffffffff : 0x0;
    if (decomp_var_3f4 != eax) goto .l101;
    goto .l90;

.l6:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto loc_458d52;

.l33:
    if (decomp_var_430 >= 0x3) goto .l30;
    goto .l36;

.l18:
    if (decomp_var_438 >= 0x3) goto .l22;
    goto .l19;

.l7:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto loc_458d52;

.l27:
    if (decomp_var_438 >= 0x3) goto .l28;
    goto .l34;

.l9:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (*((esi[0x4] * 0x15 + decomp_var_3f4) * 0x8 + 0x4d5528) < 0x3) goto loc_458b44;
    goto loc_458a83;

.l82:
    eax = decomp_var_39c;
    ebp = eax[0x1];
    edi = ebp;
    if (arg_d != 0x0) {
            eax[0x1] = eax;
            *decomp_var_39c = decomp_var_39c;
            decomp_var_39c[0x2] = decomp_var_39c;
            eax = sub_404ce0(&decomp_var_170, &decomp_var_428, decomp_var_450);
            esp = esp - 0x10;
            eax = sub_404ce0(&decomp_var_188, &decomp_var_438, decomp_var_450);
            eax = decomp_var_390;
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
                    } while (arg_19 == 0x0);
                    eax = decomp_var_390;
            }
            eax[0x1] = eax;
            *decomp_var_390 = decomp_var_390;
            decomp_var_390[0x2] = decomp_var_390;
            eax = decomp_var_384;
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
                    } while (arg_19 == 0x0);
                    eax = decomp_var_384;
            }
            eax[0x1] = eax;
            decomp_var_380 = 0x0;
            *decomp_var_384 = decomp_var_384;
            decomp_var_384[0x2] = decomp_var_384;
            if (decomp_var_414 == 0x0) {
                    sub_47a948();
            }
            ebx = decomp_var_410;
            if (ebx == decomp_var_414[0x1]) {
                    sub_47a948();
            }
            if (esi == arg_0) {
                    sub_47a948();
            }
            edi = esi + 0x28;
            eax = sub_419300(&decomp_var_158, edi, decomp_var_450);
            decomp_var_3a8 = 0x1;
            decomp_var_3ac = 0x0;
            eax = sub_466f80(&decomp_var_1cc, 0xbc1e0c);
            esp = esp - 0x14;
            sub_465ff0(eax);
            sub_465fa0();
            if (esi == arg_0) {
                    sub_47a948();
            }
            sub_465ff0(edi);
            decomp_var_42c = decomp_var_438 & 0xff | 0x4100;
            eax = sub_465f30(&decomp_var_42c);
            esp = esp - 0xc;
            eax = sub_465ff0(&decomp_var_24c);
            sub_465fa0();
            ecx = decomp_var_434[0x2];
            ebp = decomp_var_430;
            eax = 0x0;
            if (ecx[0x901] <= 0x0) {
                    edi = *dword_bb65f4;
                    sub_4222a0(&decomp_var_3ac);
                    esp = esp - 0xc;
                    eax = sub_430480(&decomp_var_1a0, &decomp_var_14c, decomp_var_450);
                    sub_41cc50();
                    *dword_baed60 = edi;
                    if (ebp == 0x0) {
                            if (esi == decomp_var_40c[0x1]) {
                                    sub_47a948();
                            }
                            edi = decomp_var_414;
                            if (ebx == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x8;
                            eax = sub_419300(&decomp_var_1ac, esi + 0x28, decomp_var_450);
                            if (ebx == edi[0x1]) {
                                    sub_47a948();
                            }
                            bool_1903 = ebx != decomp_var_414[0x1];
                            ebp = ebx[0xa];
                            esi = ebx + 0x24;
                            if (!bool_1903) {
                                    sub_47a948();
                            }
                            esp = esp - 0x8;
                            eax = sub_401ff0(&decomp_var_23c, &decomp_var_438, decomp_var_450, decomp_var_44c, decomp_var_448);
                            edi = eax;
                            eax = *edi;
                            if (eax == 0x0 || eax != esi) {
                                    sub_47a948();
                            }
                            if (edi[0x1] == ebp) {
                                    if (ebx == decomp_var_414[0x1]) {
                                            sub_47a948();
                                    }
                                    esp = esp - 0x8;
                                    eax = sub_404ce0(&decomp_var_164, &decomp_var_438, decomp_var_450);
                            }
                    }
                    sub_40f7f0();
                    esi = decomp_var_408;
                    ebx = decomp_var_410;
                    edi = decomp_var_40c;
                    continue;
            }
            &decomp_var_450 = &decomp_var_450;
            do {
                    if (ebp == 0x0) {
                            *(&decomp_var_450 + eax * 0x4 + 0xd4) = 0x0;
                    }
                    else {
                            *(&decomp_var_450 + eax * 0x4 + 0xd4) = ebp;
                            decomp_var_3ac = 0x1;
                    }
                    eax = eax + 0x1;
            } while (eax < ecx[0x901]);
            edi = *dword_bb65f4;
            sub_4222a0(&decomp_var_3ac);
            esp = esp - 0xc;
            eax = sub_430480(&decomp_var_1a0, &decomp_var_14c, decomp_var_450);
            sub_41cc50();
            *dword_baed60 = edi;
            if (ebp == 0x0) {
                    if (esi == decomp_var_40c[0x1]) {
                            sub_47a948();
                    }
                    edi = decomp_var_414;
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_419300(&decomp_var_1ac, esi + 0x28, decomp_var_450);
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_1903 = ebx != decomp_var_414[0x1];
                    ebp = ebx[0xa];
                    esi = ebx + 0x24;
                    if (!bool_1903) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_401ff0(&decomp_var_23c, &decomp_var_438, decomp_var_450, decomp_var_44c, decomp_var_448);
                    edi = eax;
                    eax = *edi;
                    if (eax == 0x0 || eax != esi) {
                            sub_47a948();
                    }
                    if (edi[0x1] == ebp) {
                            if (ebx == decomp_var_414[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x8;
                            eax = sub_404ce0(&decomp_var_164, &decomp_var_438, decomp_var_450);
                    }
            }
            sub_40f7f0();
            esi = decomp_var_408;
            ebx = decomp_var_410;
            edi = decomp_var_40c;
            continue;
    }
    do {
            sub_401950(edi[0x2]);
            edi = *edi;
            sub_47c8f9();
            esp = (esp - 0x8) + 0x4;
            ebp = edi;
    } while (edi[0x11] == 0x0);
    eax = decomp_var_39c;
    eax[0x1] = eax;
    *decomp_var_39c = decomp_var_39c;
    decomp_var_39c[0x2] = decomp_var_39c;
    eax = sub_404ce0(&decomp_var_170, &decomp_var_428, decomp_var_450);
    esp = esp - 0x10;
    eax = sub_404ce0(&decomp_var_188, &decomp_var_438, decomp_var_450);
    eax = decomp_var_390;
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
            } while (arg_19 == 0x0);
            eax = decomp_var_390;
    }
    eax[0x1] = eax;
    *decomp_var_390 = decomp_var_390;
    decomp_var_390[0x2] = decomp_var_390;
    eax = decomp_var_384;
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
            } while (arg_19 == 0x0);
            eax = decomp_var_384;
    }
    eax[0x1] = eax;
    decomp_var_380 = 0x0;
    *decomp_var_384 = decomp_var_384;
    decomp_var_384[0x2] = decomp_var_384;
    if (decomp_var_414 == 0x0) {
            sub_47a948();
    }
    ebx = decomp_var_410;
    if (ebx == decomp_var_414[0x1]) {
            sub_47a948();
    }
    if (esi == arg_0) {
            sub_47a948();
    }
    edi = esi + 0x28;
    eax = sub_419300(&decomp_var_158, edi, decomp_var_450);
    decomp_var_3a8 = 0x1;
    decomp_var_3ac = 0x0;
    eax = sub_466f80(&decomp_var_1cc, 0xbc1e0c);
    esp = esp - 0x14;
    sub_465ff0(eax);
    sub_465fa0();
    if (esi == arg_0) {
            sub_47a948();
    }
    sub_465ff0(edi);
    decomp_var_42c = decomp_var_438 & 0xff | 0x4100;
    eax = sub_465f30(&decomp_var_42c);
    esp = esp - 0xc;
    eax = sub_465ff0(&decomp_var_24c);
    sub_465fa0();
    ecx = decomp_var_434[0x2];
    ebp = decomp_var_430;
    eax = 0x0;
    if (ecx[0x901] <= 0x0) {
            edi = *dword_bb65f4;
            sub_4222a0(&decomp_var_3ac);
            esp = esp - 0xc;
            eax = sub_430480(&decomp_var_1a0, &decomp_var_14c, decomp_var_450);
            sub_41cc50();
            *dword_baed60 = edi;
            if (ebp == 0x0) {
                    if (esi == decomp_var_40c[0x1]) {
                            sub_47a948();
                    }
                    edi = decomp_var_414;
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_419300(&decomp_var_1ac, esi + 0x28, decomp_var_450);
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_1903 = ebx != decomp_var_414[0x1];
                    ebp = ebx[0xa];
                    esi = ebx + 0x24;
                    if (!bool_1903) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_401ff0(&decomp_var_23c, &decomp_var_438, decomp_var_450, decomp_var_44c, decomp_var_448);
                    edi = eax;
                    eax = *edi;
                    if (eax == 0x0 || eax != esi) {
                            sub_47a948();
                    }
                    if (edi[0x1] == ebp) {
                            if (ebx == decomp_var_414[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x8;
                            eax = sub_404ce0(&decomp_var_164, &decomp_var_438, decomp_var_450);
                    }
            }
            sub_40f7f0();
            esi = decomp_var_408;
            ebx = decomp_var_410;
            edi = decomp_var_40c;
            continue;
    }
    &decomp_var_450 = &decomp_var_450;
    do {
            if (ebp == 0x0) {
                    *(&decomp_var_450 + eax * 0x4 + 0xd4) = 0x0;
            }
            else {
                    *(&decomp_var_450 + eax * 0x4 + 0xd4) = ebp;
                    decomp_var_3ac = 0x1;
            }
            eax = eax + 0x1;
    } while (eax < ecx[0x901]);
    edi = *dword_bb65f4;
    sub_4222a0(&decomp_var_3ac);
    esp = esp - 0xc;
    eax = sub_430480(&decomp_var_1a0, &decomp_var_14c, decomp_var_450);
    sub_41cc50();
    *dword_baed60 = edi;
    if (ebp == 0x0) {
            if (esi == decomp_var_40c[0x1]) {
                    sub_47a948();
            }
            edi = decomp_var_414;
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_419300(&decomp_var_1ac, esi + 0x28, decomp_var_450);
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            bool_1903 = ebx != decomp_var_414[0x1];
            ebp = ebx[0xa];
            esi = ebx + 0x24;
            if (!bool_1903) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&decomp_var_23c, &decomp_var_438, decomp_var_450, decomp_var_44c, decomp_var_448);
            edi = eax;
            eax = *edi;
            if (eax == 0x0 || eax != esi) {
                    sub_47a948();
            }
            if (edi[0x1] == ebp) {
                    if (ebx == decomp_var_414[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_404ce0(&decomp_var_164, &decomp_var_438, decomp_var_450);
            }
    }
    sub_40f7f0();
    esi = decomp_var_408;
    ebx = decomp_var_410;
    edi = decomp_var_40c;
    continue;

.l101:
    if (ebp != eax) goto .l70;
    goto .l102;

.l90:
    if (decomp_var_3f0 == edx) goto .l86;
    goto .l59;

.l30:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto loc_458d52;

.l36:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    bool_756 = esi != ebx[0x1];
    eax = esi[0x4];
    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
    if (!bool_756) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    eax = esi[0x4];
    ebp = eax + eax * 0x2;
    eax = *(ebp * 0x4 + 0xbb65fc);
    edi = eax[0x1];
    ebp = ebp * 0x4 + 0xbb65f8;
    ebx = eax;
    if (edi[0x1d] == 0x0) {
            esp = esp - 0x4;
            if (sub_465cf0(esi + 0x28) != 0x0) {
                    edi = edi[0x2];
            }
            else {
                    ebx = edi;
                    edi = *edi;
            }
            if (edi[0x1d] == 0x0) {
                    continue;
            }
            break;
    }
    decomp_var_3c0 = ebx;
    decomp_var_3c4 = ebp;
    if (ebx == arg_0) goto .l14;
    goto .l13;

.l22:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto loc_458d52;

.l19:
    if (decomp_var_430 >= 0x3) goto .l24;
    goto loc_458b58;

.l28:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto loc_458d52;

.l34:
    if (decomp_var_430 >= 0x3) goto .l11;
    goto .l37;

loc_458b44:
    if (decomp_var_438 >= 0x3) goto .l12;
    goto loc_458b4e;

loc_458a83:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto loc_458d52;

.l70:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (*((esi[0x4] * 0x15 + decomp_var_3f4) * 0x8 + 0x4d5528) >= 0x3) {
            decomp_var_430 = 0xfffcf2c0;
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x6];
            }
    }
    else {
            if (decomp_var_438 < 0x3) {
                    if (decomp_var_430 < 0x3) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            bool_2054 = esi != ebx[0x1];
                            eax = esi[0x4];
                            decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
                            decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
                            if (!bool_2054) {
                                    sub_47a948();
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                            }
                            eax = esi[0x4];
                            ebp = eax + eax * 0x2;
                            eax = *(ebp * 0x4 + 0xbb65fc);
                            edi = eax[0x1];
                            ebp = ebp * 0x4 + 0xbb65f8;
                            ebx = eax;
                            if (edi[0x1d] == 0x0) {
                                    esp = esp - 0x4;
                                    if (sub_465cf0(esi + 0x28) != 0x0) {
                                            edi = edi[0x2];
                                    }
                                    else {
                                            ebx = edi;
                                            edi = *edi;
                                    }
                                    if (edi[0x1d] == 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                            decomp_var_3c0 = ebx;
                            decomp_var_3c4 = ebp;
                            if (ebx != arg_0) {
                                    esp = esp - 0x4;
                                    if (sub_465cf0(ebx + 0xc) == 0x0) {
                                            eax = &decomp_var_3c4;
                                            ecx = *eax;
                                            edi = eax[0x1];
                                            if (ecx != 0x0) {
                                                    if (ecx != decomp_var_438) {
                                                            sub_47a948();
                                                    }
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    sub_47a948();
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            decomp_var_3bc = ebp;
                                            eax = &decomp_var_3bc;
                                            ecx = *eax;
                                            edi = eax[0x1];
                                            if (ecx != 0x0) {
                                                    if (ecx != decomp_var_438) {
                                                            sub_47a948();
                                                    }
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    sub_47a948();
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    decomp_var_3bc = ebp;
                                    eax = &decomp_var_3bc;
                                    ecx = *eax;
                                    edi = eax[0x1];
                                    if (ecx != 0x0) {
                                            if (ecx != decomp_var_438) {
                                                    sub_47a948();
                                            }
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            decomp_var_430 = 0xfffcf2c0;
                            edi = decomp_var_40c;
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
            else {
                    decomp_var_430 = 0xfffcf2c0;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
    }
    goto .l82;

.l102:
    if (decomp_var_3d0 == edx) goto .l80;
    goto .l104;

.l86:
    if (decomp_var_438 < 0x3) {
            if (decomp_var_430 < 0x3) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    bool_1611 = esi != ebx[0x1];
                    eax = esi[0x4];
                    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
                    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
                    if (!bool_1611) {
                            sub_47a948();
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                    }
                    eax = esi[0x4];
                    ebp = eax + eax * 0x2;
                    eax = *(ebp * 0x4 + 0xbb65fc);
                    edi = eax[0x1];
                    ebp = ebp * 0x4 + 0xbb65f8;
                    ebx = eax;
                    if (edi[0x1d] == 0x0) {
                            esp = esp - 0x4;
                            if (sub_465cf0(esi + 0x28) != 0x0) {
                                    edi = edi[0x2];
                            }
                            else {
                                    ebx = edi;
                                    edi = *edi;
                            }
                            if (edi[0x1d] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    decomp_var_3c0 = ebx;
                    decomp_var_3c4 = ebp;
                    if (ebx != arg_0) {
                            esp = esp - 0x4;
                            if (sub_465cf0(ebx + 0xc) == 0x0) {
                                    eax = &decomp_var_3c4;
                                    ecx = *eax;
                                    edi = eax[0x1];
                                    if (ecx != 0x0) {
                                            if (ecx != decomp_var_438) {
                                                    sub_47a948();
                                            }
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    decomp_var_3bc = ebp;
                                    eax = &decomp_var_3bc;
                                    ecx = *eax;
                                    edi = eax[0x1];
                                    if (ecx != 0x0) {
                                            if (ecx != decomp_var_438) {
                                                    sub_47a948();
                                            }
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            decomp_var_3bc = ebp;
                            eax = &decomp_var_3bc;
                            ecx = *eax;
                            edi = eax[0x1];
                            if (ecx != 0x0) {
                                    if (ecx != decomp_var_438) {
                                            sub_47a948();
                                    }
                                    if (edi != decomp_var_290) {
                                            decomp_var_430 = 0xfffb6c20;
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x6];
                                            }
                                    }
                                    else {
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                    sub_465f30(&decomp_var_3f6);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                    eax = sub_465f30(&decomp_var_3f8);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                    }
                            }
                            else {
                                    sub_47a948();
                                    if (edi != decomp_var_290) {
                                            decomp_var_430 = 0xfffb6c20;
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x6];
                                            }
                                    }
                                    else {
                                            edi = decomp_var_40c;
                                            if (decomp_var_42c == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                    sub_465f30(&decomp_var_3f6);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_438 = esi[0x4];
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                    eax = sub_465f30(&decomp_var_3f8);
                                                    esp = esp - 0x18;
                                                    decomp_var_464 = ecx;
                                                    decomp_var_430 = &decomp_var_464;
                                                    decomp_var_464 = decomp_var_424;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x14;
                                                    sub_465f60(esi + 0x28);
                                                    sub_422a90();
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    decomp_var_430 = 0xfffcf2c0;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
    }
    else {
            decomp_var_430 = 0xfffcf2c0;
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x6];
            }
    }
    goto .l82;

.l59:
    if (ebp != eax) goto .l75;
    goto .l99;

.l14:
    decomp_var_3bc = ebp;
    eax = &decomp_var_3bc;
    ecx = *eax;
    edi = eax[0x1];
    if (ecx != 0x0) {
            if (ecx != decomp_var_438) {
                    sub_47a948();
            }
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    else {
            sub_47a948();
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    goto loc_458d52;

.l13:
    esp = esp - 0x4;
    if (sub_465cf0(ebx + 0xc) != 0x0) goto .l32;
    goto .l16;

.l24:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto loc_458d52;

loc_458b58:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    bool_616 = esi != ebx[0x1];
    eax = esi[0x4];
    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
    if (!bool_616) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    eax = esi[0x4];
    ebp = eax + eax * 0x2;
    eax = *(ebp * 0x4 + 0xbb65fc);
    edi = eax[0x1];
    ebp = ebp * 0x4 + 0xbb65f8;
    ebx = eax;
    if (edi[0x1d] == 0x0) {
            esp = esp - 0x4;
            if (sub_465cf0(esi + 0x28) != 0x0) {
                    edi = edi[0x2];
            }
            else {
                    ebx = edi;
                    edi = *edi;
            }
            if (edi[0x1d] == 0x0) {
                    continue;
            }
            break;
    }
    decomp_var_3c0 = ebx;
    decomp_var_3c4 = ebp;
    if (ebx == arg_0) goto .l23;
    goto loc_458be6;

.l11:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto loc_458d52;

.l37:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    bool_775 = esi != ebx[0x1];
    eax = esi[0x4];
    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
    if (!bool_775) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    eax = esi[0x4];
    ebp = eax + eax * 0x2;
    eax = *(ebp * 0x4 + 0xbb65fc);
    edi = eax[0x1];
    ebp = ebp * 0x4 + 0xbb65f8;
    ebx = eax;
    if (edi[0x1d] == 0x0) {
            esp = esp - 0x4;
            if (sub_465cf0(esi + 0x28) != 0x0) {
                    edi = edi[0x2];
            }
            else {
                    ebx = edi;
                    edi = *edi;
            }
            if (edi[0x1d] == 0x0) {
                    continue;
            }
            break;
    }
    decomp_var_3c0 = ebx;
    decomp_var_3c4 = ebp;
    if (ebx == arg_0) goto .l10;
    goto .l15;

.l12:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto loc_458d52;

loc_458b4e:
    if (decomp_var_430 >= 0x3) goto .l35;
    goto .l29;

.l80:
    if (decomp_var_438 >= 0x3) goto .l53;
    goto .l85;

.l104:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (*((esi[0x4] * 0x15 + decomp_var_3f4) * 0x8 + 0x4d5528) < 0x3) goto .l71;
    goto .l55;

.l75:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (*((esi[0x4] * 0x15 + decomp_var_3f4) * 0x8 + 0x4d5528) >= 0x3) {
            decomp_var_430 = 0xfffcf2c0;
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x6];
            }
    }
    else {
            if (decomp_var_438 < 0x3) {
                    if (decomp_var_430 < 0x3) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            bool_1763 = esi != ebx[0x1];
                            eax = esi[0x4];
                            decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
                            decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
                            if (!bool_1763) {
                                    sub_47a948();
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                            }
                            eax = esi[0x4];
                            ebp = eax + eax * 0x2;
                            eax = *(ebp * 0x4 + 0xbb65fc);
                            edi = eax[0x1];
                            ebp = ebp * 0x4 + 0xbb65f8;
                            ebx = eax;
                            if (edi[0x1d] == 0x0) {
                                    esp = esp - 0x4;
                                    if (sub_465cf0(esi + 0x28) != 0x0) {
                                            edi = edi[0x2];
                                    }
                                    else {
                                            ebx = edi;
                                            edi = *edi;
                                    }
                                    if (edi[0x1d] == 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                            decomp_var_3c0 = ebx;
                            decomp_var_3c4 = ebp;
                            if (ebx != arg_0) {
                                    esp = esp - 0x4;
                                    if (sub_465cf0(ebx + 0xc) == 0x0) {
                                            eax = &decomp_var_3c4;
                                            ecx = *eax;
                                            edi = eax[0x1];
                                            if (ecx != 0x0) {
                                                    if (ecx != decomp_var_438) {
                                                            sub_47a948();
                                                    }
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    sub_47a948();
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            decomp_var_3bc = ebp;
                                            eax = &decomp_var_3bc;
                                            ecx = *eax;
                                            edi = eax[0x1];
                                            if (ecx != 0x0) {
                                                    if (ecx != decomp_var_438) {
                                                            sub_47a948();
                                                    }
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    sub_47a948();
                                                    if (edi != decomp_var_290) {
                                                            decomp_var_430 = 0xfffb6c20;
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                                    else {
                                                            edi = decomp_var_40c;
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                                    sub_465f30(&decomp_var_3f6);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424 & 0xffff;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                                    eax = sub_465f30(&decomp_var_3f8);
                                                                    esp = esp - 0x18;
                                                                    decomp_var_464 = ecx;
                                                                    decomp_var_430 = &decomp_var_464;
                                                                    decomp_var_464 = decomp_var_424;
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    esp = esp - 0x14;
                                                                    sub_465f60(esi + 0x28);
                                                                    sub_422a90();
                                                                    if (decomp_var_42c == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x4];
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            decomp_var_438 = esi[0x6];
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    decomp_var_3bc = ebp;
                                    eax = &decomp_var_3bc;
                                    ecx = *eax;
                                    edi = eax[0x1];
                                    if (ecx != 0x0) {
                                            if (ecx != decomp_var_438) {
                                                    sub_47a948();
                                            }
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            sub_47a948();
                                            if (edi != decomp_var_290) {
                                                    decomp_var_430 = 0xfffb6c20;
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x6];
                                                    }
                                            }
                                            else {
                                                    edi = decomp_var_40c;
                                                    if (decomp_var_42c == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                                                            sub_465f30(&decomp_var_3f6);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424 & 0xffff;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_438 = esi[0x4];
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                                                            eax = sub_465f30(&decomp_var_3f8);
                                                            esp = esp - 0x18;
                                                            decomp_var_464 = ecx;
                                                            decomp_var_430 = &decomp_var_464;
                                                            decomp_var_464 = decomp_var_424;
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            esp = esp - 0x14;
                                                            sub_465f60(esi + 0x28);
                                                            sub_422a90();
                                                            if (decomp_var_42c == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x4];
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    decomp_var_438 = esi[0x6];
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            decomp_var_430 = 0xfffcf2c0;
                            edi = decomp_var_40c;
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
            else {
                    decomp_var_430 = 0xfffcf2c0;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
    }
    goto .l82;

.l99:
    if (decomp_var_3d0 == edx) goto .l57;
    goto .l69;

.l32:
    decomp_var_3bc = ebp;
    eax = &decomp_var_3bc;
    ecx = *eax;
    edi = eax[0x1];
    if (ecx == 0x0) goto loc_458c28;
    goto loc_458c22;

.l16:
    eax = &decomp_var_3c4;
    ecx = *eax;
    edi = eax[0x1];
    if (ecx != 0x0) {
            if (ecx != decomp_var_438) {
                    sub_47a948();
            }
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    else {
            sub_47a948();
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    goto loc_458d52;

.l23:
    decomp_var_3bc = ebp;
    eax = &decomp_var_3bc;
    goto loc_458c17;

loc_458be6:
    esp = esp - 0x4;
    if (sub_465cf0(ebx + 0xc) != 0x0) goto .l20;
    goto loc_458bf6;

.l10:
    decomp_var_3bc = ebp;
    eax = &decomp_var_3bc;
    ecx = *eax;
    edi = eax[0x1];
    if (ecx != 0x0) {
            if (ecx != decomp_var_438) {
                    sub_47a948();
            }
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    else {
            sub_47a948();
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    goto loc_458d52;

.l15:
    esp = esp - 0x4;
    if (sub_465cf0(ebx + 0xc) != 0x0) goto loc_458bff;
    goto .l17;

.l35:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto loc_458d52;

.l29:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    bool_674 = esi != ebx[0x1];
    eax = esi[0x4];
    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
    if (!bool_674) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    eax = esi[0x4];
    ebp = eax + eax * 0x2;
    eax = *(ebp * 0x4 + 0xbb65fc);
    edi = eax[0x1];
    ebp = ebp * 0x4 + 0xbb65f8;
    ebx = eax;
    if (edi[0x1d] == 0x0) {
            esp = esp - 0x4;
            if (sub_465cf0(esi + 0x28) != 0x0) {
                    edi = edi[0x2];
            }
            else {
                    ebx = edi;
                    edi = *edi;
            }
            if (edi[0x1d] == 0x0) {
                    continue;
            }
            break;
    }
    decomp_var_3c0 = ebx;
    decomp_var_3c4 = ebp;
    if (ebx != arg_0) {
            esp = esp - 0x4;
            if (sub_465cf0(ebx + 0xc) == 0x0) {
                    eax = &decomp_var_3c4;
            }
            else {
                    decomp_var_3bc = ebp;
                    eax = &decomp_var_3bc;
            }
    }
    else {
            decomp_var_3bc = ebp;
            eax = &decomp_var_3bc;
    }
    goto loc_458c17;

.l53:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto .l82;

.l85:
    if (decomp_var_430 >= 0x3) goto .l89;
    goto .l88;

.l71:
    if (decomp_var_438 >= 0x3) goto .l58;
    goto .l74;

.l55:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto .l82;

.l57:
    if (decomp_var_438 >= 0x3) goto .l91;
    goto .l100;

.l69:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (*((esi[0x4] * 0x15 + decomp_var_3f4) * 0x8 + 0x4d5528) < 0x3) goto .l93;
    goto .l84;

loc_458c28:
    sub_47a948();
    goto loc_458c2d;

loc_458c22:
    if (ecx != decomp_var_438) {
            sub_47a948();
    }
    if (edi != decomp_var_290) {
            decomp_var_430 = 0xfffb6c20;
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x6];
            }
    }
    else {
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                    sub_465f30(&decomp_var_3f6);
                    esp = esp - 0x18;
                    decomp_var_464 = ecx;
                    decomp_var_430 = &decomp_var_464;
                    decomp_var_464 = decomp_var_424 & 0xffff;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x14;
                    sub_465f60(esi + 0x28);
                    sub_422a90();
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                    eax = sub_465f30(&decomp_var_3f8);
                    esp = esp - 0x18;
                    decomp_var_464 = ecx;
                    decomp_var_430 = &decomp_var_464;
                    decomp_var_464 = decomp_var_424;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x14;
                    sub_465f60(esi + 0x28);
                    sub_422a90();
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
    }
    goto loc_458d52;

loc_458c17:
    ecx = *eax;
    edi = eax[0x1];
    if (ecx != 0x0) {
            if (ecx != decomp_var_438) {
                    sub_47a948();
            }
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    else {
            sub_47a948();
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    goto loc_458d52;

.l20:
    decomp_var_3bc = ebp;
    eax = &decomp_var_3bc;
    goto loc_458c17;

loc_458bf6:
    eax = &decomp_var_3c4;
    ecx = *eax;
    edi = eax[0x1];
    if (ecx != 0x0) {
            if (ecx != decomp_var_438) {
                    sub_47a948();
            }
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    else {
            sub_47a948();
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    goto loc_458d52;

loc_458bff:
    decomp_var_3bc = ebp;
    eax = &decomp_var_3bc;
    ecx = *eax;
    edi = eax[0x1];
    if (ecx == 0x0 || ecx != decomp_var_438) {
            sub_47a948();
    }
    goto loc_458c2d;

.l17:
    eax = &decomp_var_3c4;
    ecx = *eax;
    edi = eax[0x1];
    if (ecx != 0x0) {
            if (ecx != decomp_var_438) {
                    sub_47a948();
            }
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    else {
            sub_47a948();
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    goto loc_458d52;

.l89:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto .l82;

.l88:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    bool_1912 = esi != ebx[0x1];
    eax = esi[0x4];
    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
    if (!bool_1912) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    eax = esi[0x4];
    ebp = eax + eax * 0x2;
    eax = *(ebp * 0x4 + 0xbb65fc);
    edi = eax[0x1];
    ebp = ebp * 0x4 + 0xbb65f8;
    ebx = eax;
    if (edi[0x1d] == 0x0) {
            esp = esp - 0x4;
            if (sub_465cf0(esi + 0x28) != 0x0) {
                    edi = edi[0x2];
            }
            else {
                    ebx = edi;
                    edi = *edi;
            }
            if (edi[0x1d] == 0x0) {
                    continue;
            }
            break;
    }
    decomp_var_3c0 = ebx;
    decomp_var_3c4 = ebp;
    if (ebx == arg_0) goto .l63;
    goto .l61;

.l58:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto .l82;

.l74:
    if (decomp_var_430 >= 0x3) goto .l98;
    goto .l77;

.l91:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto .l82;

.l100:
    if (decomp_var_430 >= 0x3) goto .l96;
    goto .l79;

.l93:
    if (decomp_var_438 >= 0x3) goto .l97;
    goto .l66;

.l84:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto .l82;

loc_458c2d:
    if (edi != decomp_var_290) {
            decomp_var_430 = 0xfffb6c20;
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x6];
            }
    }
    else {
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                    sub_465f30(&decomp_var_3f6);
                    esp = esp - 0x18;
                    decomp_var_464 = ecx;
                    decomp_var_430 = &decomp_var_464;
                    decomp_var_464 = decomp_var_424 & 0xffff;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x14;
                    sub_465f60(esi + 0x28);
                    sub_422a90();
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                    eax = sub_465f30(&decomp_var_3f8);
                    esp = esp - 0x18;
                    decomp_var_464 = ecx;
                    decomp_var_430 = &decomp_var_464;
                    decomp_var_464 = decomp_var_424;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x14;
                    sub_465f60(esi + 0x28);
                    sub_422a90();
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
    }
    goto loc_458d52;

.l63:
    decomp_var_3bc = ebp;
    eax = &decomp_var_3bc;
    ecx = *eax;
    edi = eax[0x1];
    if (ecx != 0x0) {
            if (ecx != decomp_var_438) {
                    sub_47a948();
            }
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    else {
            sub_47a948();
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    goto .l82;

.l61:
    esp = esp - 0x4;
    if (sub_465cf0(ebx + 0xc) != 0x0) goto .l103;
    goto .l65;

.l98:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto .l82;

.l77:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    bool_1769 = esi != ebx[0x1];
    eax = esi[0x4];
    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
    if (!bool_1769) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    eax = esi[0x4];
    ebp = eax + eax * 0x2;
    eax = *(ebp * 0x4 + 0xbb65fc);
    edi = eax[0x1];
    ebp = ebp * 0x4 + 0xbb65f8;
    ebx = eax;
    if (edi[0x1d] == 0x0) {
            esp = esp - 0x4;
            if (sub_465cf0(esi + 0x28) != 0x0) {
                    edi = edi[0x2];
            }
            else {
                    ebx = edi;
                    edi = *edi;
            }
            if (edi[0x1d] == 0x0) {
                    continue;
            }
            break;
    }
    decomp_var_3c0 = ebx;
    decomp_var_3c4 = ebp;
    if (ebx == arg_0) goto .l94;
    goto .l49;

.l96:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto .l82;

.l79:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    bool_1384 = esi != ebx[0x1];
    eax = esi[0x4];
    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
    if (!bool_1384) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    eax = esi[0x4];
    ebp = eax + eax * 0x2;
    eax = *(ebp * 0x4 + 0xbb65fc);
    edi = eax[0x1];
    ebp = ebp * 0x4 + 0xbb65f8;
    ebx = eax;
    if (edi[0x1d] == 0x0) {
            esp = esp - 0x4;
            if (sub_465cf0(esi + 0x28) != 0x0) {
                    edi = edi[0x2];
            }
            else {
                    ebx = edi;
                    edi = *edi;
            }
            if (edi[0x1d] == 0x0) {
                    continue;
            }
            break;
    }
    decomp_var_3c0 = ebx;
    decomp_var_3c4 = ebp;
    if (ebx == arg_0) goto .l64;
    goto .l81;

.l97:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto .l82;

.l66:
    if (decomp_var_430 >= 0x3) goto .l72;
    goto .l67;

.l103:
    decomp_var_3bc = ebp;
    eax = &decomp_var_3bc;
    ecx = *eax;
    edi = eax[0x1];
    if (ecx == 0x0) goto .l60;
    goto .l50;

.l65:
    eax = &decomp_var_3c4;
    ecx = *eax;
    edi = eax[0x1];
    if (ecx != 0x0) {
            if (ecx != decomp_var_438) {
                    sub_47a948();
            }
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    else {
            sub_47a948();
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    goto .l82;

.l94:
    decomp_var_3bc = ebp;
    eax = &decomp_var_3bc;
    goto .l83;

.l49:
    esp = esp - 0x4;
    if (sub_465cf0(ebx + 0xc) != 0x0) goto .l92;
    goto .l52;

.l64:
    decomp_var_3bc = ebp;
    eax = &decomp_var_3bc;
    ecx = *eax;
    edi = eax[0x1];
    if (ecx != 0x0) {
            if (ecx != decomp_var_438) {
                    sub_47a948();
            }
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    else {
            sub_47a948();
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    goto .l82;

.l81:
    esp = esp - 0x4;
    if (sub_465cf0(ebx + 0xc) != 0x0) goto .l87;
    goto .l56;

.l72:
    decomp_var_430 = 0xfffcf2c0;
    edi = decomp_var_40c;
    if (decomp_var_42c == 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x4];
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            decomp_var_438 = esi[0x6];
    }
    goto .l82;

.l67:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    bool_1822 = esi != ebx[0x1];
    eax = esi[0x4];
    decomp_var_438 = (eax + eax * 0x2) * 0x4 + 0xbb65f8;
    decomp_var_290 = *((eax + eax * 0x2) * 0x4 + 0xbb65fc);
    if (!bool_1822) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    eax = esi[0x4];
    ebp = eax + eax * 0x2;
    eax = *(ebp * 0x4 + 0xbb65fc);
    edi = eax[0x1];
    ebp = ebp * 0x4 + 0xbb65f8;
    ebx = eax;
    if (edi[0x1d] == 0x0) {
            esp = esp - 0x4;
            if (sub_465cf0(esi + 0x28) != 0x0) {
                    edi = edi[0x2];
            }
            else {
                    ebx = edi;
                    edi = *edi;
            }
            if (edi[0x1d] == 0x0) {
                    continue;
            }
            break;
    }
    decomp_var_3c0 = ebx;
    decomp_var_3c4 = ebp;
    if (ebx != arg_0) {
            esp = esp - 0x4;
            if (sub_465cf0(ebx + 0xc) == 0x0) {
                    eax = &decomp_var_3c4;
            }
            else {
                    decomp_var_3bc = ebp;
                    eax = &decomp_var_3bc;
            }
    }
    else {
            decomp_var_3bc = ebp;
            eax = &decomp_var_3bc;
    }
    goto .l83;

.l60:
    sub_47a948();
    goto .l68;

.l50:
    if (ecx != decomp_var_438) {
            sub_47a948();
    }
    if (edi != decomp_var_290) {
            decomp_var_430 = 0xfffb6c20;
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x6];
            }
    }
    else {
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                    sub_465f30(&decomp_var_3f6);
                    esp = esp - 0x18;
                    decomp_var_464 = ecx;
                    decomp_var_430 = &decomp_var_464;
                    decomp_var_464 = decomp_var_424 & 0xffff;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x14;
                    sub_465f60(esi + 0x28);
                    sub_422a90();
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                    eax = sub_465f30(&decomp_var_3f8);
                    esp = esp - 0x18;
                    decomp_var_464 = ecx;
                    decomp_var_430 = &decomp_var_464;
                    decomp_var_464 = decomp_var_424;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x14;
                    sub_465f60(esi + 0x28);
                    sub_422a90();
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
    }
    goto .l82;

.l83:
    ecx = *eax;
    edi = eax[0x1];
    if (ecx != 0x0) {
            if (ecx != decomp_var_438) {
                    sub_47a948();
            }
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    else {
            sub_47a948();
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    goto .l82;

.l92:
    decomp_var_3bc = ebp;
    eax = &decomp_var_3bc;
    goto .l83;

.l52:
    eax = &decomp_var_3c4;
    ecx = *eax;
    edi = eax[0x1];
    if (ecx != 0x0) {
            if (ecx != decomp_var_438) {
                    sub_47a948();
            }
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    else {
            sub_47a948();
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    goto .l82;

.l87:
    decomp_var_3bc = ebp;
    eax = &decomp_var_3bc;
    ecx = *eax;
    edi = eax[0x1];
    if (ecx == 0x0 || ecx != decomp_var_438) {
            sub_47a948();
    }
    goto .l68;

.l56:
    eax = &decomp_var_3c4;
    ecx = *eax;
    edi = eax[0x1];
    if (ecx != 0x0) {
            if (ecx != decomp_var_438) {
                    sub_47a948();
            }
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    else {
            sub_47a948();
            if (edi != decomp_var_290) {
                    decomp_var_430 = 0xfffb6c20;
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
            else {
                    edi = decomp_var_40c;
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                            sub_465f30(&decomp_var_3f6);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424 & 0xffff;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                            eax = sub_465f30(&decomp_var_3f8);
                            esp = esp - 0x18;
                            decomp_var_464 = ecx;
                            decomp_var_430 = &decomp_var_464;
                            decomp_var_464 = decomp_var_424;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x14;
                            sub_465f60(esi + 0x28);
                            sub_422a90();
                            if (decomp_var_42c == 0x0) {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x4];
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    decomp_var_438 = esi[0x6];
                            }
                    }
            }
    }
    goto .l82;

.l68:
    if (edi != decomp_var_290) {
            decomp_var_430 = 0xfffb6c20;
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x6];
            }
    }
    else {
            edi = decomp_var_40c;
            if (decomp_var_42c == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_3f6 = esi[0x10] & 0xff | 0x4100;
                    sub_465f30(&decomp_var_3f6);
                    esp = esp - 0x18;
                    decomp_var_464 = ecx;
                    decomp_var_430 = &decomp_var_464;
                    decomp_var_464 = decomp_var_424 & 0xffff;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x14;
                    sub_465f60(esi + 0x28);
                    sub_422a90();
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_438 = esi[0x4];
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_3f8 = esi[0x18] & 0xff | 0x4100;
                    eax = sub_465f30(&decomp_var_3f8);
                    esp = esp - 0x18;
                    decomp_var_464 = ecx;
                    decomp_var_430 = &decomp_var_464;
                    decomp_var_464 = decomp_var_424;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x14;
                    sub_465f60(esi + 0x28);
                    sub_422a90();
                    if (decomp_var_42c == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x4];
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            decomp_var_438 = esi[0x6];
                    }
            }
    }
    goto .l82;
}
