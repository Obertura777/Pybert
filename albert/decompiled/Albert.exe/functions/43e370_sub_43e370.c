// sub_43e370 @ 0x43e370
// hopper name: sub_43e370
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5603afdb33265f2ea0acc9a81cbc14c61d166c3a97fb9b974c9d4823276f52ec
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_43e370() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_8 = sub_4975d0;
    var_C = *0x0;
    decomp_var_1f0 = ebx;
    decomp_var_1f4 = esi;
    decomp_var_1f8 = edi;
    esp = esp - 0x1fc;
    *0x0 = &var_C;
    ebx = ecx;
    var_1CC = ebx;
    sub_465870();
    sub_4064f0();
    sub_465870();
    sub_465870();
    eax = ebx[0x2];
    edi = eax + 0x2450;
    esi = *eax[0x915];
    var_180 = edi;
    goto loc_43e420;

loc_43e420:
    eax = ebx[0x2];
    ecx = eax[0x915];
    eax = eax + 0x2450;
    var_130 = ecx;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi == var_130) goto .l40;
    goto loc_43e44f;

.l40:
    break;

loc_43e44f:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != arg_0) {
            sub_401390();
            esi = var_170;
            edi = var_174;
            ebx = var_1C0;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x8] == 0x0) {
            sub_401390();
            esi = var_170;
            edi = var_174;
            ebx = var_1C0;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    bool_2 = esi != edi[0x1];
    var_1D4 = esi[0x3];
    if (!bool_2) {
            sub_47a948();
    }
    if (esi[0x8] != 0x2) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x8] != 0x6) {
                    eax = var_1D4;
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi[0x9];
            }
    }
    else {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x9];
    }
    ebx = ebx[0x2];
    edx = *(((eax << 0x4) - eax) * 0x8 + 0xbaedd4);
    esi = 0x0;
    var_1D4 = ebx;
    ebx = ebx[0x901];
    edi = 0x0;
    var_1E0 = eax;
    var_1DC = 0x0;
    var_1A4 = edx;
    if (ebx <= 0x0) {
            sub_401390();
            esi = var_170;
            edi = var_174;
            ebx = var_1C0;
            continue;
    }
    edx = eax * 0x4 + 0xba4370;
    do {
            if (esi != arg_0) {
                    ecx = edx[0x1500];
                    eax = *edx;
                    if (ecx >= 0x1) {
                            eax = eax - ecx;
                    }
                    if (edi < eax) {
                            edi = eax;
                    }
                    if (eax > 0x0) {
                            var_1DC = var_1DC + 0x1;
                    }
            }
            esi = esi + 0x1;
            edx = edx + 0x400;
    } while (esi < ebx);
    eax = var_1DC;
    if (eax <= 0x1) goto loc_43ea62;
    goto loc_43e54d;
    sub_465fa0();
    sub_465fa0();
    sub_406440();
    eax = sub_465fa0();
    *0x0 = var_8;
    &decomp_var_1e8 = ebp;
    return eax;

loc_43ea62:
    if (eax <= 0x0) {
            sub_401390();
            esi = var_170;
            edi = var_174;
            ebx = var_1C0;
            continue;
    }
    if (*(((var_1D0 << 0x4) - var_1D0) * 0x8 + 0xbaedf0) != 0x5 || *(int8_t *)byte_baed68 != 0x0) {
            sub_401390();
            esi = var_170;
            edi = var_174;
            ebx = var_1C0;
            continue;
    }
    esi = var_1D4 + 0x2450;
    edi = *var_1D4[0x915];
    var_1CC = esi;
    var_1C8 = edi;
    goto loc_43eaa0;

loc_43e54d:
    var_1DC = 0x0;
    var_1B4 = var_1E0 * 0x4 + 0xba9770;
    goto loc_43e564;

loc_43eaa0:
    eax = var_1C4[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi == ebx) goto .l34;
    goto loc_43eac3;

loc_43e564:
    edi = *(var_1B4 - 0x5400);
    eax = *var_1B4;
    if (eax > 0x0) {
            edi = edi - eax;
    }
    edx = arg_0;
    if (var_1DC == edx || edi <= 0x0 || var_1A4 - (var_1D5 & 0xff) >= edi) goto loc_43ea1b;
    goto loc_43e59e;

.l34:
    break;

loc_43eac3:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    if (edi[0x6] == arg_0) {
            sub_401390();
            edi = var_1C4;
            esi = var_1C8;
            continue;
    }
    if (edi == esi[0x1]) {
            sub_47a948();
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_1f8 = edi + 0x14;
    ebx = sub_4075b0(decomp_var_1f8, decomp_var_1f4);
    esi = ebx;
    var_1C0 = esi;
    var_1BC = *ebx[0x1];
    goto loc_43eb30;

loc_43ea1b:
    ecx = var_1C0[0x2];
    var_1B0 = var_1B0 + 0x400;
    bool_33 = var_1D8 + 0x1 < ecx[0x901];
    var_1D8 = var_1D8 + 0x1;
    var_1D0 = ecx;
    if (bool_33) {
            continue;
    }
    break;

loc_43e59e:
    eax = edx;
    if (*((edx * 0x15 + var_1DC) * 0x4 + 0x634e90) < 0xf) {
            ecx = var_1E0;
            edx = eax & 0x80000000 ? 0xffffffff : 0x0;
            if (*(ecx * 0x8 + 0x4d2610) == eax) {
                    if (*(ecx * 0x8 + 0x4d2614) == edx) {
                            if (ecx == var_1D0) {
                                    if (edi > var_1A4) {
                                            var_1B8 = 0x8;
                                    }
                                    else {
                                            var_1B8 = 0x4;
                                    }
                            }
                            else {
                                    var_1B8 = 0x4;
                            }
                    }
                    else {
                            var_1B8 = 0x4;
                    }
            }
            else {
                    var_1B8 = 0x4;
            }
    }
    else {
            var_1B8 = 0x1;
    }
    esi = var_1D0 + 0x2450;
    edi = *var_1D0[0x915];
    var_1C8 = esi;
    var_1C4 = edi;
    goto loc_43e610;
    sub_401390();
    esi = var_170;
    edi = var_174;
    ebx = var_1C0;
    continue;

loc_43eb30:
    var_140 = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (var_1B8 != var_140) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (var_1B8 == esi[0x1]) {
                    sub_47a948();
            }
            if (var_1B8[0x3] != var_1DC) {
                    sub_40f400();
                    esi = var_1BC;
                    continue;
            }
            if (edi == var_1C8[0x1]) {
                    sub_47a948();
            }
            esi = edi[0x3];
            esi = (esi * 0x3e8 + var_1CC) * 0x3e8 + var_1DC;
            decomp_var_1f4 = &var_1A4;
            esp = esp - 0x8;
            decomp_var_1f8 = &var_9C;
            var_1A4 = esi;
            eax = sub_410910(decomp_var_1f8, decomp_var_1f4, decomp_var_1f0, decomp_var_1ec, decomp_var_1e8);
            ebx = *eax;
            var_1A8 = eax[0x1];
            var_138 = *dword_baed98;
            if (ebx == 0x0 || ebx != 0xbaed94) {
                    sub_47a948();
            }
            eax = var_1A8;
            if (eax != var_138) {
                    if (ebx == 0x0) {
                            sub_47a948();
                            eax = var_1A8;
                    }
                    if (eax == ebx[0x1]) {
                            sub_47a948();
                            eax = var_1A8;
                    }
                    eax[0x9] = eax[0x9] + 0x1;
                    ebx = var_1D0;
                    sub_40f400();
                    esi = var_1BC;
                    continue;
            }
            sub_465f30(0x4c6d38);
            esp = esp - 0x8;
            eax = sub_465ff0(&var_CC);
            arg_0 = 0x3;
            sub_465fa0();
            ebx = var_1C8;
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            var_198 = edi[0x3];
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            ebx = arg_0;
            eax = sub_465ff0(&var_16C);
            var_18C = var_1DC;
            eax = sub_465f60(&var_184);
            decomp_var_1f4 = &var_124;
            esp = esp - 0x10;
            decomp_var_1f8 = &var_8C;
            sub_419240(decomp_var_1f8, decomp_var_1f4, decomp_var_1f0);
            arg_0 = 0x3;
            sub_465fa0();
            if (edi == var_1C8[0x1]) {
                    sub_47a948();
            }
            *(int8_t *)(edi[0x6] * 0x15 + ebx + 0xbaeb70) = 0x1;
            ebx = var_1D0;
            sub_40f400();
            esi = var_1BC;
            continue;
    }
    break;

loc_43e610:
    eax = var_1C0[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi == ebx) goto .l25;
    goto loc_43e637;
    sub_401390();
    edi = var_1C4;
    esi = var_1C8;
    continue;

.l25:
    break;

loc_43e637:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    if (edi[0x6] == arg_0) {
            sub_401390();
            edi = var_1C4;
            esi = var_1C8;
            continue;
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    if (edi[0x6] == var_1D8) {
            sub_401390();
            edi = var_1C4;
            esi = var_1C8;
            continue;
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    eax = edi[0x6];
    ecx = var_1DC;
    edx = eax & 0x80000000 ? 0xffffffff : 0x0;
    if (eax != *(ecx * 0x8 + 0x4d2610)) goto loc_43e695;
    goto loc_43e688;

loc_43e695:
    if (edi == esi[0x1]) {
            sub_47a948();
            ecx = var_1DC;
    }
    eax = edi[0x6];
    edx = eax & 0x80000000 ? 0xffffffff : 0x0;
    if (eax != *(ecx * 0x8 + 0x4d2e10)) goto .l4;
    goto loc_43e6b0;

loc_43e688:
    if (edx == *(ecx * 0x8 + 0x4d2614)) {
            sub_401390();
            edi = var_1C4;
            esi = var_1C8;
            continue;
    }
    if (edi == esi[0x1]) {
            sub_47a948();
            ecx = var_1DC;
    }
    eax = edi[0x6];
    edx = eax & 0x80000000 ? 0xffffffff : 0x0;
    if (eax != *(ecx * 0x8 + 0x4d2e10)) goto loc_43e6bd;
    goto .l7;

.l4:
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    eax = edi[0x3];
    if (*(((eax << 0x4) - eax) * 0x8 + 0xbaedd4) != 0x0) {
            sub_401390();
            edi = var_1C4;
            esi = var_1C8;
            continue;
    }
    if (edi == esi[0x1]) {
            sub_47a948();
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_1f4 = edi + 0x14;
    esi = sub_4075b0(decomp_var_1f4, decomp_var_1f0);
    ebx = esi;
    var_1D0 = esi;
    var_1BC = ebx;
    var_1B8 = *esi[0x1];
    goto .l8;

loc_43e6b0:
    if (edx == *(ecx * 0x8 + 0x4d2e14)) {
            sub_401390();
            edi = var_1C4;
            esi = var_1C8;
            continue;
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    eax = edi[0x3];
    if (*(((eax << 0x4) - eax) * 0x8 + 0xbaedd4) != 0x0) {
            sub_401390();
            edi = var_1C4;
            esi = var_1C8;
            continue;
    }
    if (edi == esi[0x1]) {
            sub_47a948();
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_1f4 = edi + 0x14;
    esi = sub_4075b0(decomp_var_1f4, decomp_var_1f0);
    ebx = esi;
    var_1D0 = esi;
    var_1BC = ebx;
    var_1B8 = *esi[0x1];
    goto .l10;

loc_43e6bd:
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    eax = edi[0x3];
    if (*(((eax << 0x4) - eax) * 0x8 + 0xbaedd4) != 0x0) {
            sub_401390();
            edi = var_1C4;
            esi = var_1C8;
            continue;
    }
    if (edi == esi[0x1]) {
            sub_47a948();
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_1f4 = edi + 0x14;
    esi = sub_4075b0(decomp_var_1f4, decomp_var_1f0);
    ebx = esi;
    var_1D0 = esi;
    var_1BC = ebx;
    var_1B8 = *esi[0x1];
    goto .l9;

.l7:
    if (edx == *(ecx * 0x8 + 0x4d2e14)) {
            sub_401390();
            edi = var_1C4;
            esi = var_1C8;
            continue;
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    eax = edi[0x3];
    if (*(((eax << 0x4) - eax) * 0x8 + 0xbaedd4) != 0x0) {
            sub_401390();
            edi = var_1C4;
            esi = var_1C8;
            continue;
    }
    if (edi == esi[0x1]) {
            sub_47a948();
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_1f4 = edi + 0x14;
    esi = sub_4075b0(decomp_var_1f4, decomp_var_1f0);
    ebx = esi;
    var_1D0 = esi;
    var_1BC = ebx;
    var_1B8 = *esi[0x1];
    goto loc_43e722;

.l8:
    var_158 = esi[0x1];
    if (ebx == 0x0 || ebx != esi) {
            sub_47a948();
    }
    if (var_1B8 != var_158) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (var_1B8 == ebx[0x1]) {
                    sub_47a948();
            }
            if (var_1B8[0x3] != var_1DC) {
                    sub_40f400();
                    ebx = var_1B8;
                    continue;
            }
            if (edi == var_1C8[0x1]) {
                    sub_47a948();
            }
            esi = edi[0x3];
            esi = (esi * 0x3e8 + var_1CC) * 0x3e8 + var_1DC;
            decomp_var_1f4 = &var_1A4;
            esp = esp - 0x8;
            decomp_var_1f8 = &var_94;
            var_1A4 = esi;
            eax = sub_410910(decomp_var_1f8, decomp_var_1f4, decomp_var_1f0, decomp_var_1ec, decomp_var_1e8);
            ebx = *eax;
            var_1A8 = eax[0x1];
            var_130 = *dword_baed98;
            if (ebx == 0x0 || ebx != 0xbaed94) {
                    sub_47a948();
            }
            eax = var_1A8;
            if (eax != var_130) {
                    if (ebx == 0x0) {
                            sub_47a948();
                            eax = var_1A8;
                    }
                    if (eax == ebx[0x1]) {
                            sub_47a948();
                            eax = var_1A8;
                    }
                    eax[0x9] = eax[0x9] + var_1B4;
                    esi = var_1D0;
                    sub_40f400();
                    ebx = var_1BC;
                    continue;
            }
            if (edi == var_1C8[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            sub_42e120(edi + 0x10);
            ecx = var_1DC;
            eax = sub_463690(&var_B8, &var_70);
            sub_465ff0(eax);
            sub_465fa0();
            eax = sub_466f80(&var_A8, &var_150);
            esp = esp - 0x18;
            sub_465ff0(eax);
            sub_465fa0();
            ebx = var_1C4;
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            var_194 = edi[0x3];
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            ebx = arg_0;
            var_184 = 0x1;
            eax = sub_465ff0(&var_168);
            var_18C = var_1C8;
            eax = sub_465f60(&var_180);
            decomp_var_1f0 = &var_F4;
            esp = esp - 0x10;
            decomp_var_1f4 = &var_7C;
            sub_419240(decomp_var_1f4, decomp_var_1f0, decomp_var_1ec);
            sub_465fa0();
            if (edi == var_1C4[0x1]) {
                    sub_47a948();
            }
            esi = var_1CC;
            *(int8_t *)(edi[0x6] * 0x15 + ebx + 0xbaeb70) = 0x1;
            sub_40f400();
            ebx = var_1B8;
            continue;
    }
    break;

.l10:
    var_158 = esi[0x1];
    if (ebx == 0x0 || ebx != esi) {
            sub_47a948();
    }
    if (var_1B8 != var_158) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (var_1B8 == ebx[0x1]) {
                    sub_47a948();
            }
            if (var_1B8[0x3] != var_1DC) {
                    sub_40f400();
                    ebx = var_1B8;
                    continue;
            }
            if (edi == var_1C8[0x1]) {
                    sub_47a948();
            }
            esi = edi[0x3];
            esi = (esi * 0x3e8 + var_1CC) * 0x3e8 + var_1DC;
            decomp_var_1f4 = &var_1A4;
            esp = esp - 0x8;
            decomp_var_1f8 = &var_94;
            var_1A4 = esi;
            eax = sub_410910(decomp_var_1f8, decomp_var_1f4, decomp_var_1f0, decomp_var_1ec, decomp_var_1e8);
            ebx = *eax;
            var_1A8 = eax[0x1];
            var_130 = *dword_baed98;
            if (ebx == 0x0 || ebx != 0xbaed94) {
                    sub_47a948();
            }
            eax = var_1A8;
            if (eax != var_130) {
                    if (ebx == 0x0) {
                            sub_47a948();
                            eax = var_1A8;
                    }
                    if (eax == ebx[0x1]) {
                            sub_47a948();
                            eax = var_1A8;
                    }
                    eax[0x9] = eax[0x9] + var_1B4;
                    esi = var_1D0;
                    sub_40f400();
                    ebx = var_1BC;
                    continue;
            }
            if (edi == var_1C8[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            sub_42e120(edi + 0x10);
            ecx = var_1DC;
            eax = sub_463690(&var_B8, &var_70);
            sub_465ff0(eax);
            sub_465fa0();
            eax = sub_466f80(&var_A8, &var_150);
            esp = esp - 0x18;
            sub_465ff0(eax);
            sub_465fa0();
            ebx = var_1C4;
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            var_194 = edi[0x3];
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            ebx = arg_0;
            var_184 = 0x1;
            eax = sub_465ff0(&var_168);
            var_18C = var_1C8;
            eax = sub_465f60(&var_180);
            decomp_var_1f0 = &var_F4;
            esp = esp - 0x10;
            decomp_var_1f4 = &var_7C;
            sub_419240(decomp_var_1f4, decomp_var_1f0, decomp_var_1ec);
            sub_465fa0();
            if (edi == var_1C4[0x1]) {
                    sub_47a948();
            }
            esi = var_1CC;
            *(int8_t *)(edi[0x6] * 0x15 + ebx + 0xbaeb70) = 0x1;
            sub_40f400();
            ebx = var_1B8;
            continue;
    }
    break;

.l9:
    var_158 = esi[0x1];
    if (ebx == 0x0 || ebx != esi) {
            sub_47a948();
    }
    if (var_1B8 != var_158) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (var_1B8 == ebx[0x1]) {
                    sub_47a948();
            }
            if (var_1B8[0x3] != var_1DC) {
                    sub_40f400();
                    ebx = var_1B8;
                    continue;
            }
            if (edi == var_1C8[0x1]) {
                    sub_47a948();
            }
            esi = edi[0x3];
            esi = (esi * 0x3e8 + var_1CC) * 0x3e8 + var_1DC;
            decomp_var_1f4 = &var_1A4;
            esp = esp - 0x8;
            decomp_var_1f8 = &var_94;
            var_1A4 = esi;
            eax = sub_410910(decomp_var_1f8, decomp_var_1f4, decomp_var_1f0, decomp_var_1ec, decomp_var_1e8);
            ebx = *eax;
            var_1A8 = eax[0x1];
            var_130 = *dword_baed98;
            if (ebx == 0x0 || ebx != 0xbaed94) {
                    sub_47a948();
            }
            eax = var_1A8;
            if (eax != var_130) {
                    if (ebx == 0x0) {
                            sub_47a948();
                            eax = var_1A8;
                    }
                    if (eax == ebx[0x1]) {
                            sub_47a948();
                            eax = var_1A8;
                    }
                    eax[0x9] = eax[0x9] + var_1B4;
                    esi = var_1D0;
                    sub_40f400();
                    ebx = var_1BC;
                    continue;
            }
            if (edi == var_1C8[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            sub_42e120(edi + 0x10);
            ecx = var_1DC;
            eax = sub_463690(&var_B8, &var_70);
            sub_465ff0(eax);
            sub_465fa0();
            eax = sub_466f80(&var_A8, &var_150);
            esp = esp - 0x18;
            sub_465ff0(eax);
            sub_465fa0();
            ebx = var_1C4;
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            var_194 = edi[0x3];
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            ebx = arg_0;
            var_184 = 0x1;
            eax = sub_465ff0(&var_168);
            var_18C = var_1C8;
            eax = sub_465f60(&var_180);
            decomp_var_1f0 = &var_F4;
            esp = esp - 0x10;
            decomp_var_1f4 = &var_7C;
            sub_419240(decomp_var_1f4, decomp_var_1f0, decomp_var_1ec);
            sub_465fa0();
            if (edi == var_1C4[0x1]) {
                    sub_47a948();
            }
            esi = var_1CC;
            *(int8_t *)(edi[0x6] * 0x15 + ebx + 0xbaeb70) = 0x1;
            sub_40f400();
            ebx = var_1B8;
            continue;
    }
    break;

loc_43e722:
    var_158 = esi[0x1];
    if (ebx == 0x0 || ebx != esi) {
            sub_47a948();
    }
    if (var_1B8 != var_158) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (var_1B8 == ebx[0x1]) {
                    sub_47a948();
            }
            if (var_1B8[0x3] != var_1DC) {
                    sub_40f400();
                    ebx = var_1B8;
                    continue;
            }
            if (edi == var_1C8[0x1]) {
                    sub_47a948();
            }
            esi = edi[0x3];
            esi = (esi * 0x3e8 + var_1CC) * 0x3e8 + var_1DC;
            decomp_var_1f4 = &var_1A4;
            esp = esp - 0x8;
            decomp_var_1f8 = &var_94;
            var_1A4 = esi;
            eax = sub_410910(decomp_var_1f8, decomp_var_1f4, decomp_var_1f0, decomp_var_1ec, decomp_var_1e8);
            ebx = *eax;
            var_1A8 = eax[0x1];
            var_130 = *dword_baed98;
            if (ebx == 0x0 || ebx != 0xbaed94) {
                    sub_47a948();
            }
            eax = var_1A8;
            if (eax != var_130) {
                    if (ebx == 0x0) {
                            sub_47a948();
                            eax = var_1A8;
                    }
                    if (eax == ebx[0x1]) {
                            sub_47a948();
                            eax = var_1A8;
                    }
                    eax[0x9] = eax[0x9] + var_1B4;
                    esi = var_1D0;
                    sub_40f400();
                    ebx = var_1BC;
                    continue;
            }
            if (edi == var_1C8[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            sub_42e120(edi + 0x10);
            ecx = var_1DC;
            eax = sub_463690(&var_B8, &var_70);
            sub_465ff0(eax);
            sub_465fa0();
            eax = sub_466f80(&var_A8, &var_150);
            esp = esp - 0x18;
            sub_465ff0(eax);
            sub_465fa0();
            ebx = var_1C4;
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            var_194 = edi[0x3];
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            ebx = arg_0;
            var_184 = 0x1;
            eax = sub_465ff0(&var_168);
            var_18C = var_1C8;
            eax = sub_465f60(&var_180);
            decomp_var_1f0 = &var_F4;
            esp = esp - 0x10;
            decomp_var_1f4 = &var_7C;
            sub_419240(decomp_var_1f4, decomp_var_1f0, decomp_var_1ec);
            sub_465fa0();
            if (edi == var_1C4[0x1]) {
                    sub_47a948();
            }
            esi = var_1CC;
            *(int8_t *)(edi[0x6] * 0x15 + ebx + 0xbaeb70) = 0x1;
            sub_40f400();
            ebx = var_1B8;
            continue;
    }
    break;
    sub_401390();
    edi = var_1C4;
    esi = var_1C8;
    continue;
    sub_401390();
    edi = var_1C4;
    esi = var_1C8;
    continue;
    sub_401390();
    edi = var_1C4;
    esi = var_1C8;
    continue;
    sub_401390();
    edi = var_1C4;
    esi = var_1C8;
    continue;
}
