// sub_426350 @ 0x426350
// hopper name: sub_426350
// contains unmarked entry 0x4266b6 (CAL_VALUE)
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_426350() {
    decomp_var_8 = 0x4964ce;
    decomp_var_c = *0x0;
    decomp_var_ec = edi;
    esp = esp - 0xf0;
    decomp_var_f0 = *dword_4c8db8 ^ &decomp_var_ec;
    *0x0 = &decomp_var_c;
    edx = *(int8_t *)(ecx[0x2] + 0x2424) & 0xff;
    *(int16_t *)arg_0 = 0x0;
    decomp_var_84 = edx;
    eax = sub_47020b();
    if (eax != 0x0) goto loc_4263cd;
    goto loc_4263c3;

loc_4263cd:
    decomp_var_98 = (*(*eax + 0xc))() + 0x10;
    decomp_var_db = 0x0;
    eax = sub_40fd90();
    eax[0x1d] = 0x1;
    eax[0x1] = eax;
    *eax = eax;
    eax[0x2] = eax;
    sub_465870();
    sub_465870();
    eax = sub_40fd90();
    decomp_var_c4 = eax;
    eax[0x1d] = 0x1;
    decomp_var_c4[0x1] = decomp_var_c4;
    *decomp_var_c4 = decomp_var_c4;
    decomp_var_c4[0x2] = decomp_var_c4;
    eax = sub_40fd90();
    decomp_var_b8 = eax;
    eax[0x1d] = 0x1;
    decomp_var_b8[0x1] = decomp_var_b8;
    *decomp_var_b8 = decomp_var_b8;
    decomp_var_b8[0x2] = decomp_var_b8;
    decomp_var_94 = 0x0;
    decomp_var_90 = 0x0;
    sub_410cf0(decomp_var_c4[0x1]);
    decomp_var_c4[0x1] = decomp_var_c4;
    decomp_var_c0 = 0x0;
    *decomp_var_c4 = decomp_var_c4;
    decomp_var_c4[0x2] = decomp_var_c4;
    sub_410cf0(decomp_var_b8[0x1]);
    decomp_var_b8[0x1] = decomp_var_b8;
    decomp_var_b4 = 0x0;
    *decomp_var_b8 = decomp_var_b8;
    decomp_var_b8[0x2] = decomp_var_b8;
    eax = sub_40fed0();
    decomp_var_ac = eax;
    eax[0x21] = 0x1;
    decomp_var_ac[0x1] = decomp_var_ac;
    *decomp_var_ac = decomp_var_ac;
    decomp_var_ac[0x2] = decomp_var_ac;
    edx = &decomp_var_d8;
    esp = esp - 0x10;
    if (*(int16_t *)word_4c6d8c == *(int16_t *)sub_465900(edx, 0x0)) goto loc_426799;
    goto loc_42655e;

loc_4263c3:
    eax = sub_40b5a0(0x80004005);
    return eax;

loc_426799:
    edi = 0x0;
    esp = esp - 0x8;
    ebx = 0x0;
    eax = sub_465900(&decomp_var_8c, 0x0);
    if (*(int16_t *)word_4c6d0c != *(int16_t *)eax) {
            edx = &decomp_var_74;
            esp = esp - 0xc;
            sub_465ff0(sub_466060(edx, 0x1));
            sub_465fa0();
            ebx = 0x1;
    }
    esp = esp - 0x8;
    eax = sub_465900(&decomp_var_8c, edi);
    if (*(int16_t *)word_4c6df8 == *(int16_t *)eax) goto loc_426f7d;
    goto loc_42681c;

loc_42655e:
    edi = 0x0;
    ebp = sub_465930() - 0x1;
    ecx = 0x0;
    if (ebp <= 0x0) goto .l8;
    goto loc_426570;

loc_426f7d:
    decomp_var_f4 = edi;
    eax = sub_47b26f(decomp_var_f4);
    decomp_var_fc = &decomp_var_98;
    esi = (eax - *dword_ba2880) + 0x2710;
    sub_410c10(decomp_var_fc, "Could not find matching sequence", decomp_var_f4);
    decomp_var_a4 = esi;
    eax = *(**(decomp_var_98 - 0x10) + 0x10);
    esi = decomp_var_98 - 0x10;
    esp = (esp - 0xc) + 0xc;
    eax = (eax)();
    edx = esi + 0xc;
    if (esi[0x3] >= edi) {
            if (eax == *esi) {
                    edi = esi;
                    *edx = lock intrinsic_xadd(*edx, 0x1);
            }
            else {
                    esp = esp - 0x8;
                    edi = (**eax)(esi[0x1], 0x1);
                    if (edi == 0x0) {
                            sub_40b6d0();
                    }
                    edi[0x1] = esi[0x1];
                    eax = esi[0x1];
                    decomp_var_108 = eax + 0x1;
                    decomp_var_10c = edi + 0x10;
                    sub_47a5af(decomp_var_10c, decomp_var_108, esi + 0x10, eax + 0x1);
                    esp = (esp - 0x10) + 0x10;
            }
    }
    else {
            esp = esp - 0x8;
            edi = (**eax)(esi[0x1], 0x1);
            if (edi == 0x0) {
                    sub_40b6d0();
            }
            edi[0x1] = esi[0x1];
            eax = esi[0x1];
            decomp_var_108 = eax + 0x1;
            decomp_var_10c = edi + 0x10;
            sub_47a5af(decomp_var_10c, decomp_var_108, esi + 0x10, eax + 0x1);
            esp = (esp - 0x10) + 0x10;
    }
    decomp_var_100 = &decomp_var_b0;
    esp = esp - 0x8;
    sub_419e60(&decomp_var_80, decomp_var_100, decomp_var_fc);
    eax = edi + 0x10 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
    if (ecx <= 0x1) {
            esp = esp - 0x4;
            decomp_var_100 = eax;
            (*(**eax + 0x4))(decomp_var_100);
    }
    sub_4220e0(&decomp_var_c0);
    sub_465f60(&arg_8);
    decomp_var_120 = ecx;
    decomp_var_120 = arg_4;
    edx = &decomp_var_8;
    esp = esp - 0x3c;
    decomp_var_134 = edx;
    sub_465f60(decomp_var_134);
    edi = sub_426140(decomp_var_130, decomp_var_12c, decomp_var_128, decomp_var_124, decomp_var_120, decomp_var_11c, decomp_var_118, decomp_var_114, decomp_var_110, decomp_var_10c, decomp_var_108);
    if (0x0 == 0x1) {
            if (edi < 0x0) {
                    decomp_var_134 = 0x0;
                    eax = sub_47b26f(0x0);
                    decomp_var_138 = edi;
                    decomp_var_13c = 0x4afdc8;
                    decomp_var_140 = &decomp_var_d8;
                    sub_410c10(decomp_var_140, 0x4afdc8, decomp_var_138);
                    eax = *(**(decomp_var_d8 - 0x10) + 0x10);
                    esi = decomp_var_d8 - 0x10;
                    esp = (esp - 0x10) + 0x10;
                    eax = (eax)();
                    edx = esi + 0xc;
                    if (esi[0x3] >= 0x0) {
                            if (eax == *esi) {
                                    edi = esi;
                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                            }
                            else {
                                    esp = esp - 0x8;
                                    edi = (**eax)(esi[0x1], 0x1);
                                    if (edi == 0x0) {
                                            sub_40b6d0();
                                    }
                                    edi[0x1] = esi[0x1];
                                    eax = esi[0x1];
                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                    esp = (esp - 0x10) + 0x10;
                            }
                    }
                    else {
                            esp = esp - 0x8;
                            edi = (**eax)(esi[0x1], 0x1);
                            if (edi == 0x0) {
                                    sub_40b6d0();
                            }
                            edi[0x1] = esi[0x1];
                            eax = esi[0x1];
                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                            esp = (esp - 0x10) + 0x10;
                    }
                    esp = esp - 0x8;
                    eax = sub_419e60(&decomp_var_c4, &decomp_var_f4, decomp_var_140);
                    eax = edi + 0x10 - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    if (decomp_var_12a == 0x1) {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6cf0;
                    }
                    else {
                            if (decomp_var_129 == 0x1) {
                                    ebp = decomp_var_4c;
                                    *(int16_t *)ebp = *(int16_t *)word_4c6d90;
                            }
                            else {
                                    ebp = decomp_var_4c;
                                    *(int16_t *)ebp = *(int16_t *)word_4c6d28;
                            }
                    }
            }
            else {
                    ebp = decomp_var_4c;
                    *(int16_t *)ebp = *(int16_t *)word_4c6d48;
            }
    }
    else {
            if (decomp_var_12a == 0x1) {
                    ebp = decomp_var_4c;
                    *(int16_t *)ebp = *(int16_t *)word_4c6cf0;
            }
            else {
                    if (decomp_var_129 == 0x1) {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6d90;
                    }
                    else {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6d28;
                    }
            }
    }
    sub_41abc0(&decomp_var_c4, &decomp_var_100, *decomp_var_fc, &decomp_var_100, decomp_var_fc);
    sub_47c8f9();
    sub_419cb0(&decomp_var_c4, &decomp_var_10c, *decomp_var_108, &decomp_var_10c, decomp_var_108);
    sub_47c8f9();
    sub_419cb0(&decomp_var_c4, &decomp_var_118, *decomp_var_114, &decomp_var_118, decomp_var_114);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    esp = (((esp - 0x18) + 0x4 - 0x18) + 0x4 - 0x18) + 0x4 - 0xc;
    sub_419cb0(&decomp_var_c4, &decomp_var_d0, *decomp_var_cc, &decomp_var_d0, decomp_var_cc);
    sub_47c8f9();
    esp = (esp - 0xc) + 0x4;
    esi[0x3] = lock intrinsic_xadd(esi[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**esi + 0x4))(esi);
    }
    sub_465fa0();
    sub_465fa0();
    eax = ebp;
    *0x0 = decomp_var_5c;
    return eax;

loc_42681c:
    if (ebx == 0x0) {
            edx = &arg_4;
            esp = esp - 0x8;
            eax = sub_419300(&decomp_var_74, edx, decomp_var_f0);
    }
    else {
            edx = &decomp_var_74;
            esp = esp - 0x8;
            eax = sub_419300(edx, &arg_4, decomp_var_f0);
    }
    ecx = 0xbb65ec;
    ebx = **dword_bb65f0;
    decomp_var_d0 = 0xbb65ec;
    decomp_var_cc = **dword_bb65f0;
    goto loc_4266c5;

.l8:
    decomp_var_f4 = edi;
    eax = sub_47b26f(decomp_var_f4);
    decomp_var_fc = &decomp_var_98;
    esi = (eax - *dword_ba2880) + 0x2710;
    sub_410c10(decomp_var_fc, "Could not find matching sequence", decomp_var_f4);
    decomp_var_a4 = esi;
    eax = *(**(decomp_var_98 - 0x10) + 0x10);
    esi = decomp_var_98 - 0x10;
    esp = (esp - 0xc) + 0xc;
    eax = (eax)();
    edx = esi + 0xc;
    if (esi[0x3] >= edi) {
            if (eax == *esi) {
                    edi = esi;
                    *edx = lock intrinsic_xadd(*edx, 0x1);
            }
            else {
                    esp = esp - 0x8;
                    edi = (**eax)(esi[0x1], 0x1);
                    if (edi == 0x0) {
                            sub_40b6d0();
                    }
                    edi[0x1] = esi[0x1];
                    eax = esi[0x1];
                    decomp_var_108 = eax + 0x1;
                    decomp_var_10c = edi + 0x10;
                    sub_47a5af(decomp_var_10c, decomp_var_108, esi + 0x10, eax + 0x1);
                    esp = (esp - 0x10) + 0x10;
            }
    }
    else {
            esp = esp - 0x8;
            edi = (**eax)(esi[0x1], 0x1);
            if (edi == 0x0) {
                    sub_40b6d0();
            }
            edi[0x1] = esi[0x1];
            eax = esi[0x1];
            decomp_var_108 = eax + 0x1;
            decomp_var_10c = edi + 0x10;
            sub_47a5af(decomp_var_10c, decomp_var_108, esi + 0x10, eax + 0x1);
            esp = (esp - 0x10) + 0x10;
    }
    decomp_var_100 = &decomp_var_b0;
    esp = esp - 0x8;
    sub_419e60(&decomp_var_80, decomp_var_100, decomp_var_fc);
    eax = edi + 0x10 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
    if (ecx <= 0x1) {
            esp = esp - 0x4;
            decomp_var_100 = eax;
            (*(**eax + 0x4))(decomp_var_100);
    }
    sub_4220e0(&decomp_var_c0);
    sub_465f60(&arg_8);
    decomp_var_120 = ecx;
    decomp_var_120 = arg_4;
    edx = &decomp_var_8;
    esp = esp - 0x3c;
    decomp_var_134 = edx;
    sub_465f60(decomp_var_134);
    edi = sub_426140(decomp_var_130, decomp_var_12c, decomp_var_128, decomp_var_124, decomp_var_120, decomp_var_11c, decomp_var_118, decomp_var_114, decomp_var_110, decomp_var_10c, decomp_var_108);
    if (0x0 == 0x1) {
            if (edi < 0x0) {
                    decomp_var_134 = 0x0;
                    eax = sub_47b26f(0x0);
                    decomp_var_138 = edi;
                    decomp_var_13c = 0x4afdc8;
                    decomp_var_140 = &decomp_var_d8;
                    sub_410c10(decomp_var_140, 0x4afdc8, decomp_var_138);
                    eax = *(**(decomp_var_d8 - 0x10) + 0x10);
                    esi = decomp_var_d8 - 0x10;
                    esp = (esp - 0x10) + 0x10;
                    eax = (eax)();
                    edx = esi + 0xc;
                    if (esi[0x3] >= 0x0) {
                            if (eax == *esi) {
                                    edi = esi;
                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                            }
                            else {
                                    esp = esp - 0x8;
                                    edi = (**eax)(esi[0x1], 0x1);
                                    if (edi == 0x0) {
                                            sub_40b6d0();
                                    }
                                    edi[0x1] = esi[0x1];
                                    eax = esi[0x1];
                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                    esp = (esp - 0x10) + 0x10;
                            }
                    }
                    else {
                            esp = esp - 0x8;
                            edi = (**eax)(esi[0x1], 0x1);
                            if (edi == 0x0) {
                                    sub_40b6d0();
                            }
                            edi[0x1] = esi[0x1];
                            eax = esi[0x1];
                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                            esp = (esp - 0x10) + 0x10;
                    }
                    esp = esp - 0x8;
                    eax = sub_419e60(&decomp_var_c4, &decomp_var_f4, decomp_var_140);
                    eax = edi + 0x10 - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    if (decomp_var_12a == 0x1) {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6cf0;
                    }
                    else {
                            if (decomp_var_129 == 0x1) {
                                    ebp = decomp_var_4c;
                                    *(int16_t *)ebp = *(int16_t *)word_4c6d90;
                            }
                            else {
                                    ebp = decomp_var_4c;
                                    *(int16_t *)ebp = *(int16_t *)word_4c6d28;
                            }
                    }
            }
            else {
                    ebp = decomp_var_4c;
                    *(int16_t *)ebp = *(int16_t *)word_4c6d48;
            }
    }
    else {
            if (decomp_var_12a == 0x1) {
                    ebp = decomp_var_4c;
                    *(int16_t *)ebp = *(int16_t *)word_4c6cf0;
            }
            else {
                    if (decomp_var_129 == 0x1) {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6d90;
                    }
                    else {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6d28;
                    }
            }
    }
    sub_41abc0(&decomp_var_c4, &decomp_var_100, *decomp_var_fc, &decomp_var_100, decomp_var_fc);
    sub_47c8f9();
    sub_419cb0(&decomp_var_c4, &decomp_var_10c, *decomp_var_108, &decomp_var_10c, decomp_var_108);
    sub_47c8f9();
    sub_419cb0(&decomp_var_c4, &decomp_var_118, *decomp_var_114, &decomp_var_118, decomp_var_114);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    esp = (((esp - 0x18) + 0x4 - 0x18) + 0x4 - 0x18) + 0x4 - 0xc;
    sub_419cb0(&decomp_var_c4, &decomp_var_d0, *decomp_var_cc, &decomp_var_d0, decomp_var_cc);
    sub_47c8f9();
    esp = (esp - 0xc) + 0x4;
    esi[0x3] = lock intrinsic_xadd(esi[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**esi + 0x4))(esi);
    }
    sub_465fa0();
    sub_465fa0();
    eax = ebp;
    *0x0 = decomp_var_5c;
    return eax;

loc_426570:
    do {
            esi = ecx + 0x1;
            eax = sub_466060(&decomp_var_64, esi);
            sub_465ff0(eax);
            sub_465fa0();
            eax = sub_465ff0(&decomp_var_54);
            esp = esp - 0x18;
            ebx = 0x0;
            eax = sub_465900(&decomp_var_d8, edi);
            if (*(int16_t *)word_4c6d0c != *(int16_t *)eax) {
                    eax = sub_466060(&decomp_var_2c, 0x1);
                    esp = esp - 0xc;
                    sub_465ff0(eax);
                    sub_465fa0();
                    ebx = 0x1;
            }
            esp = esp - 0x8;
            eax = sub_465900(&decomp_var_8c, edi);
            edx = *(int16_t *)word_4c6df8;
            if (*(int16_t *)word_4c6df8 != *(int16_t *)eax) {
                    decomp_var_db = 0x1;
                    if (ebx == 0x0) {
                            decomp_var_f4 = &decomp_var_54;
                            esp = esp - 0x8;
                            decomp_var_f8 = &decomp_var_74;
                    }
                    else {
                            decomp_var_f4 = &decomp_var_54;
                            esp = esp - 0x8;
                            decomp_var_f8 = &decomp_var_44;
                    }
                    sub_419300(decomp_var_f8, decomp_var_f4, decomp_var_f0);
                    edx = &decomp_var_a4;
                    esp = esp - 0x8;
                    eax = sub_419300(edx, &decomp_var_1c, decomp_var_f0);
            }
            ecx = esi;
    } while (ecx < ebp);
    if (decomp_var_db != 0x1) goto .l9;
    goto .l2;

loc_4266c5:
    edi = 0x0;
    if (ecx == 0x0 || ecx != 0xbb65ec) {
            sub_47a948();
    }
    if (ebx == *dword_bb65f0) goto .l38;
    goto loc_4266e4;

.l9:
    decomp_var_f4 = edi;
    eax = sub_47b26f(decomp_var_f4);
    decomp_var_fc = &decomp_var_98;
    esi = (eax - *dword_ba2880) + 0x2710;
    sub_410c10(decomp_var_fc, "Could not find matching sequence", decomp_var_f4);
    decomp_var_a4 = esi;
    eax = *(**(decomp_var_98 - 0x10) + 0x10);
    esi = decomp_var_98 - 0x10;
    esp = (esp - 0xc) + 0xc;
    eax = (eax)();
    edx = esi + 0xc;
    if (esi[0x3] >= edi) {
            if (eax == *esi) {
                    edi = esi;
                    *edx = lock intrinsic_xadd(*edx, 0x1);
            }
            else {
                    esp = esp - 0x8;
                    edi = (**eax)(esi[0x1], 0x1);
                    if (edi == 0x0) {
                            sub_40b6d0();
                    }
                    edi[0x1] = esi[0x1];
                    eax = esi[0x1];
                    decomp_var_108 = eax + 0x1;
                    decomp_var_10c = edi + 0x10;
                    sub_47a5af(decomp_var_10c, decomp_var_108, esi + 0x10, eax + 0x1);
                    esp = (esp - 0x10) + 0x10;
            }
    }
    else {
            esp = esp - 0x8;
            edi = (**eax)(esi[0x1], 0x1);
            if (edi == 0x0) {
                    sub_40b6d0();
            }
            edi[0x1] = esi[0x1];
            eax = esi[0x1];
            decomp_var_108 = eax + 0x1;
            decomp_var_10c = edi + 0x10;
            sub_47a5af(decomp_var_10c, decomp_var_108, esi + 0x10, eax + 0x1);
            esp = (esp - 0x10) + 0x10;
    }
    decomp_var_100 = &decomp_var_b0;
    esp = esp - 0x8;
    sub_419e60(&decomp_var_80, decomp_var_100, decomp_var_fc);
    eax = edi + 0x10 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
    if (ecx <= 0x1) {
            esp = esp - 0x4;
            decomp_var_100 = eax;
            (*(**eax + 0x4))(decomp_var_100);
    }
    sub_4220e0(&decomp_var_c0);
    sub_465f60(&arg_8);
    decomp_var_120 = ecx;
    decomp_var_120 = arg_4;
    edx = &decomp_var_8;
    esp = esp - 0x3c;
    decomp_var_134 = edx;
    sub_465f60(decomp_var_134);
    edi = sub_426140(decomp_var_130, decomp_var_12c, decomp_var_128, decomp_var_124, decomp_var_120, decomp_var_11c, decomp_var_118, decomp_var_114, decomp_var_110, decomp_var_10c, decomp_var_108);
    if (0x0 == 0x1) {
            if (edi < 0x0) {
                    decomp_var_134 = 0x0;
                    eax = sub_47b26f(0x0);
                    decomp_var_138 = edi;
                    decomp_var_13c = 0x4afdc8;
                    decomp_var_140 = &decomp_var_d8;
                    sub_410c10(decomp_var_140, 0x4afdc8, decomp_var_138);
                    eax = *(**(decomp_var_d8 - 0x10) + 0x10);
                    esi = decomp_var_d8 - 0x10;
                    esp = (esp - 0x10) + 0x10;
                    eax = (eax)();
                    edx = esi + 0xc;
                    if (esi[0x3] >= 0x0) {
                            if (eax == *esi) {
                                    edi = esi;
                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                            }
                            else {
                                    esp = esp - 0x8;
                                    edi = (**eax)(esi[0x1], 0x1);
                                    if (edi == 0x0) {
                                            sub_40b6d0();
                                    }
                                    edi[0x1] = esi[0x1];
                                    eax = esi[0x1];
                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                    esp = (esp - 0x10) + 0x10;
                            }
                    }
                    else {
                            esp = esp - 0x8;
                            edi = (**eax)(esi[0x1], 0x1);
                            if (edi == 0x0) {
                                    sub_40b6d0();
                            }
                            edi[0x1] = esi[0x1];
                            eax = esi[0x1];
                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                            esp = (esp - 0x10) + 0x10;
                    }
                    esp = esp - 0x8;
                    eax = sub_419e60(&decomp_var_c4, &decomp_var_f4, decomp_var_140);
                    eax = edi + 0x10 - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    if (decomp_var_12a == 0x1) {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6cf0;
                    }
                    else {
                            if (decomp_var_129 == 0x1) {
                                    ebp = decomp_var_4c;
                                    *(int16_t *)ebp = *(int16_t *)word_4c6d90;
                            }
                            else {
                                    ebp = decomp_var_4c;
                                    *(int16_t *)ebp = *(int16_t *)word_4c6d28;
                            }
                    }
            }
            else {
                    ebp = decomp_var_4c;
                    *(int16_t *)ebp = *(int16_t *)word_4c6d48;
            }
    }
    else {
            if (decomp_var_12a == 0x1) {
                    ebp = decomp_var_4c;
                    *(int16_t *)ebp = *(int16_t *)word_4c6cf0;
            }
            else {
                    if (decomp_var_129 == 0x1) {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6d90;
                    }
                    else {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6d28;
                    }
            }
    }
    sub_41abc0(&decomp_var_c4, &decomp_var_100, *decomp_var_fc, &decomp_var_100, decomp_var_fc);
    sub_47c8f9();
    sub_419cb0(&decomp_var_c4, &decomp_var_10c, *decomp_var_108, &decomp_var_10c, decomp_var_108);
    sub_47c8f9();
    sub_419cb0(&decomp_var_c4, &decomp_var_118, *decomp_var_114, &decomp_var_118, decomp_var_114);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    esp = (((esp - 0x18) + 0x4 - 0x18) + 0x4 - 0x18) + 0x4 - 0xc;
    sub_419cb0(&decomp_var_c4, &decomp_var_d0, *decomp_var_cc, &decomp_var_d0, decomp_var_cc);
    sub_47c8f9();
    esp = (esp - 0xc) + 0x4;
    esi[0x3] = lock intrinsic_xadd(esi[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**esi + 0x4))(esi);
    }
    sub_465fa0();
    sub_465fa0();
    eax = ebp;
    *0x0 = decomp_var_5c;
    return eax;

.l2:
    ecx = 0xbb65ec;
    ebx = **dword_bb65f0;
    decomp_var_d0 = 0xbb65ec;
    decomp_var_cc = **dword_bb65f0;
    goto .l16;

.l38:
    temp_0 = 0x0;
    break;

loc_4266e4:
    esi = &decomp_var_c8;
    ebp = *decomp_var_c4;
    decomp_var_db = 0x1;
    decomp_var_d8 = esi;
    decomp_var_d4 = ebp;
    goto loc_426700;

.l16:
    edi = 0x0;
    if (ecx == 0x0 || ecx != 0xbb65ec) {
            sub_47a948();
    }
    if (ebx == *dword_bb65f0) goto .l17;
    goto .l15;
    if (temp_0 == 0x0) goto .l10;
    goto loc_426a8f;

loc_426700:
    edi = decomp_var_c4;
    if (esi == 0x0 || esi != &decomp_var_c8) {
            sub_47a948();
    }
    if (ebp != edi) {
            if (decomp_var_d0 == 0x0) {
                    sub_47a948();
            }
            if (ebx == decomp_var_d0[0x1]) {
                    sub_47a948();
            }
            edi = ebx + 0x30;
            decomp_var_40 = ebx[0xd];
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            ebx = &arg_8;
            if (decomp_var_cc == decomp_var_d0[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x1];
            esi = eax[0x1];
            ebp = eax;
            if (esi[0x1d] != 0x0) {
                    decomp_var_8c = edi;
                    if (ebp != edi[0x1]) {
                            esp = esp - 0x4;
                            eax = sub_465cf0(&arg_8);
                            if (eax == 0x0) {
                                    eax = &decomp_var_8c;
                            }
                            else {
                                    decomp_var_2c = edi;
                                    eax = &decomp_var_2c;
                            }
                    }
                    else {
                            decomp_var_2c = edi;
                            eax = &decomp_var_2c;
                    }
                    ecx = *eax;
                    esi = eax[0x1];
                    if (ecx == 0x0 || ecx != edi) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_40) {
                            decomp_var_db = 0x0;
                    }
                    sub_401590();
                    ebp = decomp_var_d4;
                    esi = decomp_var_d8;
                    ebx = decomp_var_cc;
                    continue;
            }
            do {
                    esp = esp - 0x4;
                    if (sub_465cf0(ebx) != 0x0) {
                            esi = esi[0x2];
                    }
                    else {
                            ebp = esi;
                            esi = *esi;
                    }
            } while (esi[0x1d] == 0x0);
            decomp_var_8c = edi;
            if (ebp != edi[0x1]) {
                    esp = esp - 0x4;
                    eax = sub_465cf0(&arg_8);
                    if (eax == 0x0) {
                            eax = &decomp_var_8c;
                    }
                    else {
                            decomp_var_2c = edi;
                            eax = &decomp_var_2c;
                    }
            }
            else {
                    decomp_var_2c = edi;
                    eax = &decomp_var_2c;
            }
            ecx = *eax;
            esi = eax[0x1];
            if (ecx == 0x0 || ecx != edi) {
                    sub_47a948();
            }
            if (esi == decomp_var_40) {
                    decomp_var_db = 0x0;
            }
            sub_401590();
            ebp = decomp_var_d4;
            esi = decomp_var_d8;
            ebx = decomp_var_cc;
            continue;
    }
    break;

.l17:
    temp_0 = 0x0;
    break;

.l15:
    esi = &decomp_var_c8;
    ebp = *decomp_var_c4;
    decomp_var_db = 0x1;
    decomp_var_d8 = esi;
    decomp_var_d4 = ebp;
    goto .l20;

.l10:
    decomp_var_f4 = edi;
    ebx = 0x0;
    eax = sub_47b26f(decomp_var_f4);
    decomp_var_fc = &decomp_var_98;
    esi = (eax - *dword_ba2880) + 0x2710;
    sub_410c10(decomp_var_fc, "Could not find matching sequence", decomp_var_f4);
    decomp_var_a4 = esi;
    eax = *(**(decomp_var_98 - 0x10) + 0x10);
    esi = decomp_var_98 - 0x10;
    esp = (esp - 0xc) + 0xc;
    eax = (eax)();
    edx = esi + 0xc;
    if (esi[0x3] >= edi) {
            if (eax == *esi) {
                    edi = esi;
                    *edx = lock intrinsic_xadd(*edx, 0x1);
            }
            else {
                    esp = esp - 0x8;
                    edi = (**eax)(esi[0x1], 0x1);
                    if (edi == 0x0) {
                            sub_40b6d0();
                    }
                    edi[0x1] = esi[0x1];
                    eax = esi[0x1];
                    decomp_var_108 = eax + 0x1;
                    decomp_var_10c = edi + 0x10;
                    sub_47a5af(decomp_var_10c, decomp_var_108, esi + 0x10, eax + 0x1);
                    esp = (esp - 0x10) + 0x10;
            }
    }
    else {
            esp = esp - 0x8;
            edi = (**eax)(esi[0x1], 0x1);
            if (edi == 0x0) {
                    sub_40b6d0();
            }
            edi[0x1] = esi[0x1];
            eax = esi[0x1];
            decomp_var_108 = eax + 0x1;
            decomp_var_10c = edi + 0x10;
            sub_47a5af(decomp_var_10c, decomp_var_108, esi + 0x10, eax + 0x1);
            esp = (esp - 0x10) + 0x10;
    }
    decomp_var_100 = &decomp_var_b0;
    esp = esp - 0x8;
    sub_419e60(&decomp_var_80, decomp_var_100, decomp_var_fc);
    eax = edi + 0x10 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
    if (ecx <= 0x1) {
            esp = esp - 0x4;
            decomp_var_100 = eax;
            (*(**eax + 0x4))(decomp_var_100);
    }
    goto loc_42705f;

loc_426a8f:
    eax = decomp_var_ac;
    edi = eax[0x1];
    bool_40 = edi[0x21] != 0x0;
    decomp_var_8c = ebx[0x4];
    esi = edi;
    if (!bool_40) {
            do {
                    sub_410d70(esi[0x2]);
                    esi = *esi;
                    sub_465fa0();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x21] == 0x0);
            eax = decomp_var_ac;
    }
    eax[0x1] = eax;
    *decomp_var_ac = decomp_var_ac;
    decomp_var_ac[0x2] = decomp_var_ac;
    edi = *decomp_var_c4;
    esi = &decomp_var_c8;
    decomp_var_d8 = esi;
    decomp_var_d4 = edi;
    goto loc_426b00;
    edx = decomp_var_b8;
    esi = &decomp_var_bc;
    ebp = *edx;
    decomp_var_d8 = esi;
    decomp_var_d4 = ebp;
    goto loc_4268f2;
    if (temp_0 == 0x0) goto .l5;
    goto .l4;

.l20:
    edi = decomp_var_c4;
    if (esi == 0x0 || esi != &decomp_var_c8) {
            sub_47a948();
    }
    if (ebp != edi) {
            if (decomp_var_d0 == 0x0) {
                    sub_47a948();
            }
            if (ebx == decomp_var_d0[0x1]) {
                    sub_47a948();
            }
            edi = ebx + 0x30;
            decomp_var_40 = ebx[0xd];
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            ebx = &arg_8;
            if (decomp_var_cc == decomp_var_d0[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x1];
            esi = eax[0x1];
            ebp = eax;
            if (esi[0x1d] != 0x0) {
                    decomp_var_8c = edi;
                    if (ebp != edi[0x1]) {
                            esp = esp - 0x4;
                            eax = sub_465cf0(&arg_8);
                            if (eax == 0x0) {
                                    eax = &decomp_var_8c;
                            }
                            else {
                                    decomp_var_2c = edi;
                                    eax = &decomp_var_2c;
                            }
                    }
                    else {
                            decomp_var_2c = edi;
                            eax = &decomp_var_2c;
                    }
                    ecx = *eax;
                    esi = eax[0x1];
                    if (ecx == 0x0 || ecx != edi) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_40) {
                            decomp_var_db = 0x0;
                    }
                    sub_401590();
                    ebp = decomp_var_d4;
                    esi = decomp_var_d8;
                    ebx = decomp_var_cc;
                    continue;
            }
            do {
                    esp = esp - 0x4;
                    if (sub_465cf0(ebx) != 0x0) {
                            esi = esi[0x2];
                    }
                    else {
                            ebp = esi;
                            esi = *esi;
                    }
            } while (esi[0x1d] == 0x0);
            decomp_var_8c = edi;
            if (ebp != edi[0x1]) {
                    esp = esp - 0x4;
                    eax = sub_465cf0(&arg_8);
                    if (eax == 0x0) {
                            eax = &decomp_var_8c;
                    }
                    else {
                            decomp_var_2c = edi;
                            eax = &decomp_var_2c;
                    }
            }
            else {
                    decomp_var_2c = edi;
                    eax = &decomp_var_2c;
            }
            ecx = *eax;
            esi = eax[0x1];
            if (ecx == 0x0 || ecx != edi) {
                    sub_47a948();
            }
            if (esi == decomp_var_40) {
                    decomp_var_db = 0x0;
            }
            sub_401590();
            ebp = decomp_var_d4;
            esi = decomp_var_d8;
            ebx = decomp_var_cc;
            continue;
    }
    break;

loc_42705f:
    sub_4220e0(&decomp_var_c0);
    sub_465f60(&arg_8);
    decomp_var_120 = ecx;
    decomp_var_120 = arg_4;
    edx = &decomp_var_8;
    esp = esp - 0x3c;
    decomp_var_134 = edx;
    sub_465f60(decomp_var_134);
    edi = sub_426140(decomp_var_130, decomp_var_12c, decomp_var_128, decomp_var_124, decomp_var_120, decomp_var_11c, decomp_var_118, decomp_var_114, decomp_var_110, decomp_var_10c, decomp_var_108);
    if (ebx == 0x1) {
            if (edi < 0x0) {
                    decomp_var_134 = 0x0;
                    eax = sub_47b26f(0x0);
                    decomp_var_138 = edi;
                    decomp_var_13c = 0x4afdc8;
                    decomp_var_140 = &decomp_var_d8;
                    sub_410c10(decomp_var_140, 0x4afdc8, decomp_var_138);
                    eax = *(**(decomp_var_d8 - 0x10) + 0x10);
                    esi = decomp_var_d8 - 0x10;
                    esp = (esp - 0x10) + 0x10;
                    eax = (eax)();
                    edx = esi + 0xc;
                    if (esi[0x3] >= 0x0) {
                            if (eax == *esi) {
                                    edi = esi;
                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                            }
                            else {
                                    esp = esp - 0x8;
                                    edi = (**eax)(esi[0x1], 0x1);
                                    if (edi == 0x0) {
                                            sub_40b6d0();
                                    }
                                    edi[0x1] = esi[0x1];
                                    eax = esi[0x1];
                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                    esp = (esp - 0x10) + 0x10;
                            }
                    }
                    else {
                            esp = esp - 0x8;
                            edi = (**eax)(esi[0x1], 0x1);
                            if (edi == 0x0) {
                                    sub_40b6d0();
                            }
                            edi[0x1] = esi[0x1];
                            eax = esi[0x1];
                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                            esp = (esp - 0x10) + 0x10;
                    }
                    esp = esp - 0x8;
                    eax = sub_419e60(&decomp_var_c4, &decomp_var_f4, decomp_var_140);
                    eax = edi + 0x10 - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    if (decomp_var_12a == 0x1) {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6cf0;
                    }
                    else {
                            if (decomp_var_129 == 0x1) {
                                    ebp = decomp_var_4c;
                                    *(int16_t *)ebp = *(int16_t *)word_4c6d90;
                            }
                            else {
                                    ebp = decomp_var_4c;
                                    *(int16_t *)ebp = *(int16_t *)word_4c6d28;
                            }
                    }
            }
            else {
                    ebp = decomp_var_4c;
                    *(int16_t *)ebp = *(int16_t *)word_4c6d48;
            }
    }
    else {
            if (decomp_var_12a == 0x1) {
                    ebp = decomp_var_4c;
                    *(int16_t *)ebp = *(int16_t *)word_4c6cf0;
            }
            else {
                    if (decomp_var_129 == 0x1) {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6d90;
                    }
                    else {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6d28;
                    }
            }
    }
    sub_41abc0(&decomp_var_c4, &decomp_var_100, *decomp_var_fc, &decomp_var_100, decomp_var_fc);
    sub_47c8f9();
    sub_419cb0(&decomp_var_c4, &decomp_var_10c, *decomp_var_108, &decomp_var_10c, decomp_var_108);
    sub_47c8f9();
    sub_419cb0(&decomp_var_c4, &decomp_var_118, *decomp_var_114, &decomp_var_118, decomp_var_114);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    esp = (((esp - 0x18) + 0x4 - 0x18) + 0x4 - 0x18) + 0x4 - 0xc;
    sub_419cb0(&decomp_var_c4, &decomp_var_d0, *decomp_var_cc, &decomp_var_d0, decomp_var_cc);
    sub_47c8f9();
    esp = (esp - 0xc) + 0x4;
    esi[0x3] = lock intrinsic_xadd(esi[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**esi + 0x4))(esi);
    }
    sub_465fa0();
    sub_465fa0();
    eax = ebp;
    *0x0 = decomp_var_5c;
    return eax;

loc_426b00:
    ebp = decomp_var_c4;
    if (esi == 0x0 || esi != &decomp_var_c8) {
            sub_47a948();
    }
    if (edi != ebp) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            sub_465f60(edi + 0xc);
            decomp_var_34 = 0x1;
            esp = esp - 0xc;
            eax = sub_41a100(&decomp_var_74, &decomp_var_44, decomp_var_f0);
            sub_465fa0();
            sub_401590();
            edi = decomp_var_d4;
            esi = decomp_var_d8;
            continue;
    }
    break;

loc_4268f2:
    edi = decomp_var_b8;
    if (esi == 0x0 || esi != &decomp_var_bc) {
            sub_47a948();
    }
    if (ebp != edi) {
            if (decomp_var_d0 == 0x0) {
                    sub_47a948();
            }
            if (ebx == decomp_var_d0[0x1]) {
                    sub_47a948();
            }
            edx = ebx[0x10];
            edi = ebx + 0x3c;
            decomp_var_70 = edx;
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            ebx = &arg_8;
            if (decomp_var_cc == decomp_var_d0[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x1];
            esi = eax[0x1];
            ebp = eax;
            if (esi[0x1d] != 0x0) {
                    decomp_var_64 = edi;
                    if (ebp != edi[0x1]) {
                            esp = esp - 0x4;
                            eax = sub_465cf0(&arg_8);
                            if (eax == 0x0) {
                                    eax = &decomp_var_64;
                            }
                            else {
                                    edx = edi[0x1];
                                    decomp_var_a4 = edi;
                                    eax = &decomp_var_a4;
                            }
                    }
                    else {
                            edx = edi[0x1];
                            decomp_var_a4 = edi;
                            eax = &decomp_var_a4;
                    }
                    ecx = *eax;
                    esi = eax[0x1];
                    if (ecx == 0x0 || ecx != edi) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_70) {
                            decomp_var_db = 0x0;
                    }
                    sub_401590();
                    ebp = decomp_var_d4;
                    esi = decomp_var_d8;
                    ebx = decomp_var_cc;
                    continue;
            }
            &decomp_var_f0 = &decomp_var_f0;
            do {
                    esp = esp - 0x4;
                    if (sub_465cf0(ebx) != 0x0) {
                            esi = esi[0x2];
                    }
                    else {
                            ebp = esi;
                            esi = *esi;
                    }
            } while (esi[0x1d] == 0x0);
            decomp_var_64 = edi;
            if (ebp != edi[0x1]) {
                    esp = esp - 0x4;
                    eax = sub_465cf0(&arg_8);
                    if (eax == 0x0) {
                            eax = &decomp_var_64;
                    }
                    else {
                            edx = edi[0x1];
                            decomp_var_a4 = edi;
                            eax = &decomp_var_a4;
                    }
            }
            else {
                    edx = edi[0x1];
                    decomp_var_a4 = edi;
                    eax = &decomp_var_a4;
            }
            ecx = *eax;
            esi = eax[0x1];
            if (ecx == 0x0 || ecx != edi) {
                    sub_47a948();
            }
            if (esi == decomp_var_70) {
                    decomp_var_db = 0x0;
            }
            sub_401590();
            ebp = decomp_var_d4;
            esi = decomp_var_d8;
            ebx = decomp_var_cc;
            continue;
    }
    break;

.l5:
    decomp_var_f4 = edi;
    ebx = 0x0;
    eax = sub_47b26f(decomp_var_f4);
    decomp_var_fc = &decomp_var_98;
    esi = (eax - *dword_ba2880) + 0x2710;
    sub_410c10(decomp_var_fc, "Could not find matching sequence", decomp_var_f4);
    decomp_var_a4 = esi;
    eax = *(**(decomp_var_98 - 0x10) + 0x10);
    esi = decomp_var_98 - 0x10;
    esp = (esp - 0xc) + 0xc;
    eax = (eax)();
    edx = esi + 0xc;
    if (esi[0x3] >= edi) {
            if (eax == *esi) {
                    edi = esi;
                    *edx = lock intrinsic_xadd(*edx, 0x1);
            }
            else {
                    esp = esp - 0x8;
                    edi = (**eax)(esi[0x1], 0x1);
                    if (edi == 0x0) {
                            sub_40b6d0();
                    }
                    edi[0x1] = esi[0x1];
                    eax = esi[0x1];
                    decomp_var_108 = eax + 0x1;
                    decomp_var_10c = edi + 0x10;
                    sub_47a5af(decomp_var_10c, decomp_var_108, esi + 0x10, eax + 0x1);
                    esp = (esp - 0x10) + 0x10;
            }
    }
    else {
            esp = esp - 0x8;
            edi = (**eax)(esi[0x1], 0x1);
            if (edi == 0x0) {
                    sub_40b6d0();
            }
            edi[0x1] = esi[0x1];
            eax = esi[0x1];
            decomp_var_108 = eax + 0x1;
            decomp_var_10c = edi + 0x10;
            sub_47a5af(decomp_var_10c, decomp_var_108, esi + 0x10, eax + 0x1);
            esp = (esp - 0x10) + 0x10;
    }
    decomp_var_100 = &decomp_var_b0;
    esp = esp - 0x8;
    sub_419e60(&decomp_var_80, decomp_var_100, decomp_var_fc);
    eax = edi + 0x10 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
    if (ecx <= 0x1) {
            esp = esp - 0x4;
            decomp_var_100 = eax;
            (*(**eax + 0x4))(decomp_var_100);
    }
    goto .l3;

.l4:
    eax = decomp_var_ac;
    edi = eax[0x1];
    bool_101 = edi[0x21] != 0x0;
    decomp_var_8c = ebx[0x4];
    esi = edi;
    if (!bool_101) {
            do {
                    sub_410d70(esi[0x2]);
                    esi = *esi;
                    sub_465fa0();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x21] == 0x0);
            eax = decomp_var_ac;
    }
    eax[0x1] = eax;
    *decomp_var_ac = decomp_var_ac;
    decomp_var_ac[0x2] = decomp_var_ac;
    edi = *decomp_var_c4;
    esi = &decomp_var_c8;
    decomp_var_d8 = esi;
    decomp_var_d4 = edi;
    goto .l12;
    edx = decomp_var_b8;
    esi = &decomp_var_bc;
    ebp = *edx;
    decomp_var_d8 = esi;
    decomp_var_d4 = ebp;
    goto .l21;
    edx = decomp_var_b8;
    edi = *edx;
    esi = &decomp_var_bc;
    decomp_var_d8 = esi;
    decomp_var_d4 = edi;
    goto .l13;
    if (decomp_var_d0 == 0x0) {
            sub_47a948();
    }
    if (ebx == decomp_var_d0[0x1]) {
            sub_47a948();
    }
    if (ebx[0x18] == 0x0) {
            sub_40f470();
            ebx = decomp_var_cc;
            ecx = decomp_var_d0;
            continue;
    }
    if (ebx == decomp_var_d0[0x1]) {
            sub_47a948();
    }
    if (ebx[0x7] != 0x0) {
            sub_40f470();
            ebx = decomp_var_cc;
            ecx = decomp_var_d0;
            continue;
    }
    edx = decomp_var_d0;
    esi = decomp_var_c0;
    if (ebx == edx[0x1]) {
            sub_47a948();
    }
    if (esi != ebx[0xe]) {
            sub_40f470();
            ebx = decomp_var_cc;
            ecx = decomp_var_d0;
            continue;
    }
    esi = decomp_var_b4;
    if (ebx == decomp_var_d0[0x1]) {
            sub_47a948();
    }
    if (esi != ebx[0x11]) {
            sub_40f470();
            ebx = decomp_var_cc;
            ecx = decomp_var_d0;
            continue;
    }
    if (decomp_var_db != 0x1) {
            sub_40f470();
            ebx = decomp_var_cc;
            ecx = decomp_var_d0;
            continue;
    }
    if (ebx == decomp_var_d0[0x1]) {
            sub_47a948();
            temp_0 = 0x1;
    }
    else {
            temp_0 = 0x1;
    }
    break;

.l3:
    sub_4220e0(&decomp_var_c0);
    sub_465f60(&arg_8);
    decomp_var_120 = ecx;
    decomp_var_120 = arg_4;
    edx = &decomp_var_8;
    esp = esp - 0x3c;
    decomp_var_134 = edx;
    sub_465f60(decomp_var_134);
    edi = sub_426140(decomp_var_130, decomp_var_12c, decomp_var_128, decomp_var_124, decomp_var_120, decomp_var_11c, decomp_var_118, decomp_var_114, decomp_var_110, decomp_var_10c, decomp_var_108);
    if (ebx == 0x1) {
            if (edi < 0x0) {
                    decomp_var_134 = 0x0;
                    eax = sub_47b26f(0x0);
                    decomp_var_138 = edi;
                    decomp_var_13c = 0x4afdc8;
                    decomp_var_140 = &decomp_var_d8;
                    sub_410c10(decomp_var_140, 0x4afdc8, decomp_var_138);
                    eax = *(**(decomp_var_d8 - 0x10) + 0x10);
                    esi = decomp_var_d8 - 0x10;
                    esp = (esp - 0x10) + 0x10;
                    eax = (eax)();
                    edx = esi + 0xc;
                    if (esi[0x3] >= 0x0) {
                            if (eax == *esi) {
                                    edi = esi;
                                    *edx = lock intrinsic_xadd(*edx, 0x1);
                            }
                            else {
                                    esp = esp - 0x8;
                                    edi = (**eax)(esi[0x1], 0x1);
                                    if (edi == 0x0) {
                                            sub_40b6d0();
                                    }
                                    edi[0x1] = esi[0x1];
                                    eax = esi[0x1];
                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                    esp = (esp - 0x10) + 0x10;
                            }
                    }
                    else {
                            esp = esp - 0x8;
                            edi = (**eax)(esi[0x1], 0x1);
                            if (edi == 0x0) {
                                    sub_40b6d0();
                            }
                            edi[0x1] = esi[0x1];
                            eax = esi[0x1];
                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                            esp = (esp - 0x10) + 0x10;
                    }
                    esp = esp - 0x8;
                    eax = sub_419e60(&decomp_var_c4, &decomp_var_f4, decomp_var_140);
                    eax = edi + 0x10 - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    if (decomp_var_12a == 0x1) {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6cf0;
                    }
                    else {
                            if (decomp_var_129 == 0x1) {
                                    ebp = decomp_var_4c;
                                    *(int16_t *)ebp = *(int16_t *)word_4c6d90;
                            }
                            else {
                                    ebp = decomp_var_4c;
                                    *(int16_t *)ebp = *(int16_t *)word_4c6d28;
                            }
                    }
            }
            else {
                    ebp = decomp_var_4c;
                    *(int16_t *)ebp = *(int16_t *)word_4c6d48;
            }
    }
    else {
            if (decomp_var_12a == 0x1) {
                    ebp = decomp_var_4c;
                    *(int16_t *)ebp = *(int16_t *)word_4c6cf0;
            }
            else {
                    if (decomp_var_129 == 0x1) {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6d90;
                    }
                    else {
                            ebp = decomp_var_4c;
                            *(int16_t *)ebp = *(int16_t *)word_4c6d28;
                    }
            }
    }
    sub_41abc0(&decomp_var_c4, &decomp_var_100, *decomp_var_fc, &decomp_var_100, decomp_var_fc);
    sub_47c8f9();
    sub_419cb0(&decomp_var_c4, &decomp_var_10c, *decomp_var_108, &decomp_var_10c, decomp_var_108);
    sub_47c8f9();
    sub_419cb0(&decomp_var_c4, &decomp_var_118, *decomp_var_114, &decomp_var_118, decomp_var_114);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    esp = (((esp - 0x18) + 0x4 - 0x18) + 0x4 - 0x18) + 0x4 - 0xc;
    sub_419cb0(&decomp_var_c4, &decomp_var_d0, *decomp_var_cc, &decomp_var_d0, decomp_var_cc);
    sub_47c8f9();
    esp = (esp - 0xc) + 0x4;
    esi[0x3] = lock intrinsic_xadd(esi[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**esi + 0x4))(esi);
    }
    sub_465fa0();
    sub_465fa0();
    eax = ebp;
    *0x0 = decomp_var_5c;
    return eax;

.l12:
    ebp = decomp_var_c4;
    if (esi == 0x0 || esi != &decomp_var_c8) {
            sub_47a948();
    }
    if (edi != ebp) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            sub_465f60(edi + 0xc);
            decomp_var_34 = 0x1;
            esp = esp - 0xc;
            eax = sub_41a100(&decomp_var_74, &decomp_var_44, decomp_var_f0);
            sub_465fa0();
            sub_401590();
            edi = decomp_var_d4;
            esi = decomp_var_d8;
            continue;
    }
    break;

.l21:
    edi = decomp_var_b8;
    if (esi == 0x0 || esi != &decomp_var_bc) {
            sub_47a948();
    }
    if (ebp != edi) {
            if (decomp_var_d0 == 0x0) {
                    sub_47a948();
            }
            if (ebx == decomp_var_d0[0x1]) {
                    sub_47a948();
            }
            edx = ebx[0x10];
            edi = ebx + 0x3c;
            decomp_var_70 = edx;
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            ebx = &arg_8;
            if (decomp_var_cc == decomp_var_d0[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x1];
            esi = eax[0x1];
            ebp = eax;
            if (esi[0x1d] != 0x0) {
                    decomp_var_64 = edi;
                    if (ebp != edi[0x1]) {
                            esp = esp - 0x4;
                            eax = sub_465cf0(&arg_8);
                            if (eax == 0x0) {
                                    eax = &decomp_var_64;
                            }
                            else {
                                    edx = edi[0x1];
                                    decomp_var_a4 = edi;
                                    eax = &decomp_var_a4;
                            }
                    }
                    else {
                            edx = edi[0x1];
                            decomp_var_a4 = edi;
                            eax = &decomp_var_a4;
                    }
                    ecx = *eax;
                    esi = eax[0x1];
                    if (ecx == 0x0 || ecx != edi) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_70) {
                            decomp_var_db = 0x0;
                    }
                    sub_401590();
                    ebp = decomp_var_d4;
                    esi = decomp_var_d8;
                    ebx = decomp_var_cc;
                    continue;
            }
            &decomp_var_f0 = &decomp_var_f0;
            do {
                    esp = esp - 0x4;
                    if (sub_465cf0(ebx) != 0x0) {
                            esi = esi[0x2];
                    }
                    else {
                            ebp = esi;
                            esi = *esi;
                    }
            } while (esi[0x1d] == 0x0);
            decomp_var_64 = edi;
            if (ebp != edi[0x1]) {
                    esp = esp - 0x4;
                    eax = sub_465cf0(&arg_8);
                    if (eax == 0x0) {
                            eax = &decomp_var_64;
                    }
                    else {
                            edx = edi[0x1];
                            decomp_var_a4 = edi;
                            eax = &decomp_var_a4;
                    }
            }
            else {
                    edx = edi[0x1];
                    decomp_var_a4 = edi;
                    eax = &decomp_var_a4;
            }
            ecx = *eax;
            esi = eax[0x1];
            if (ecx == 0x0 || ecx != edi) {
                    sub_47a948();
            }
            if (esi == decomp_var_70) {
                    decomp_var_db = 0x0;
            }
            sub_401590();
            ebp = decomp_var_d4;
            esi = decomp_var_d8;
            ebx = decomp_var_cc;
            continue;
    }
    break;

.l13:
    ebp = decomp_var_b8;
    if (esi == 0x0 || esi != &decomp_var_bc) {
            sub_47a948();
    }
    if (edi != ebp) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            sub_465f60(edi + 0xc);
            decomp_var_34 = 0x0;
            edx = &decomp_var_74;
            esp = esp - 0xc;
            eax = sub_41a100(edx, &decomp_var_44, decomp_var_f0);
            sub_465fa0();
            sub_401590();
            edi = decomp_var_d4;
            esi = decomp_var_d8;
            continue;
    }
    break;
    edx = decomp_var_b8;
    edi = *edx;
    esi = &decomp_var_bc;
    decomp_var_d8 = esi;
    decomp_var_d4 = edi;
    goto loc_426ba6;
    if (decomp_var_d0 == 0x0) {
            sub_47a948();
    }
    if (ebx == decomp_var_d0[0x1]) {
            sub_47a948();
    }
    if (ebx[0x18] == 0x0) {
            sub_40f470();
            ebx = decomp_var_cc;
            ecx = decomp_var_d0;
            continue;
    }
    if (ebx == decomp_var_d0[0x1]) {
            sub_47a948();
    }
    if (ebx[0x7] != 0x0) {
            sub_40f470();
            ebx = decomp_var_cc;
            ecx = decomp_var_d0;
            continue;
    }
    edx = decomp_var_d0;
    esi = decomp_var_c0;
    if (ebx == edx[0x1]) {
            sub_47a948();
    }
    if (esi != ebx[0xe]) {
            sub_40f470();
            ebx = decomp_var_cc;
            ecx = decomp_var_d0;
            continue;
    }
    esi = decomp_var_b4;
    if (ebx == decomp_var_d0[0x1]) {
            sub_47a948();
    }
    if (esi != ebx[0x11]) {
            sub_40f470();
            ebx = decomp_var_cc;
            ecx = decomp_var_d0;
            continue;
    }
    if (decomp_var_db != 0x1) {
            sub_40f470();
            ebx = decomp_var_cc;
            ecx = decomp_var_d0;
            continue;
    }
    if (ebx == decomp_var_d0[0x1]) {
            sub_47a948();
            temp_0 = 0x1;
    }
    else {
            temp_0 = 0x1;
    }
    break;
    edi = *dword_bb65f0;
    eax = edi[0x1];
    ecx = edi;
    if (eax[0xe9] == 0x0) {
            &decomp_var_f0 = &decomp_var_f0;
            do {
                    edx = eax[0x4];
                    if (edx < decomp_var_8c) {
                            eax = eax[0x2];
                    }
                    else {
                            ecx = eax;
                            eax = *eax;
                    }
            } while (eax[0xe9] == 0x0);
    }
    decomp_var_a4 = 0xbb65ec;
    if (ecx != *dword_bb65f0 && decomp_var_8c >= ecx[0x4]) {
            eax = &decomp_var_a4;
    }
    else {
            decomp_var_64 = 0xbb65ec;
            eax = &decomp_var_64;
    }
    ebp = *eax;
    esi = eax[0x1];
    if (ebp == 0x0) {
            sub_47a948();
    }
    if (esi == arg_0) {
            sub_47a948();
    }
    decomp_var_8c = esi[0xd0] & 0xff;
    if (esi == arg_0) {
            sub_47a948();
    }
    if (esi[0x27] > 0x0) {
            if (esi == arg_0) {
                    sub_47a948();
            }
            edi = *dword_bb65f0;
            eax = edi[0x1];
            ecx = edi;
            if (eax[0xe9] == 0x0) {
                    edx = esi[0x27];
                    do {
                            if (eax[0x4] < edx) {
                                    eax = eax[0x2];
                            }
                            else {
                                    ecx = eax;
                                    eax = *eax;
                            }
                    } while (eax[0xe9] == 0x0);
            }
            decomp_var_a0 = ecx;
            decomp_var_a4 = 0xbb65ec;
            if (ecx != *dword_bb65f0) {
                    edx = esi[0x27];
                    if (edx >= ecx[0x4]) {
                            ebx = decomp_var_a4;
                            decomp_var_90 = decomp_var_a0;
                    }
                    else {
                            edi = *dword_bb65f0;
                            decomp_var_64 = 0xbb65ec;
                            ebx = decomp_var_64;
                            decomp_var_90 = edi;
                    }
            }
            else {
                    edi = *dword_bb65f0;
                    decomp_var_64 = 0xbb65ec;
                    ebx = decomp_var_64;
                    decomp_var_90 = edi;
            }
    }
    else {
            ebx = decomp_var_94;
    }
    if (esi == arg_0) {
            sub_47a948();
    }
    if (esi[0x27] > 0x0) {
            if (ebx == 0x0 || ebx != 0xbb65ec) {
                    sub_47a948();
            }
            if (decomp_var_90 != *dword_bb65f0) {
                    if (ebx == 0x0) {
                            sub_47a948();
                    }
                    if (decomp_var_90 == ebx[0x1]) {
                            sub_47a948();
                    }
                    edx = decomp_var_84;
                    eax = decomp_var_90;
                    if (*(eax + edx * 0x4 + 0x48) > 0xfffec780) {
                            if (eax == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (*(decomp_var_90 + decomp_var_8c * 0x4 + 0x48) > 0xfffec780) {
                                    if (esi == arg_0) {
                                            sub_47a948();
                                    }
                                    edx = decomp_var_90;
                                    if (edx == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    ebx = *(esi + decomp_var_84 * 0x4 + 0x48);
                                    ebx = ebx - *(decomp_var_90 + decomp_var_84 * 0x4 + 0x48);
                                    bool_17 = esi != arg_0;
                                    if (esi == arg_0) {
                                            sub_47a948();
                                    }
                            }
                            else {
                                    if (esi == arg_0) {
                                            sub_47a948();
                                    }
                                    ebx = *(esi + decomp_var_84 * 0x4 + 0x48);
                            }
                    }
                    else {
                            if (esi == arg_0) {
                                    sub_47a948();
                            }
                            ebx = *(esi + decomp_var_84 * 0x4 + 0x48);
                    }
            }
            else {
                    if (esi == arg_0) {
                            sub_47a948();
                    }
                    ebx = *(esi + decomp_var_84 * 0x4 + 0x48);
            }
    }
    else {
            if (esi == arg_0) {
                    sub_47a948();
            }
            ebx = *(esi + decomp_var_84 * 0x4 + 0x48);
    }
    if (!bool_17) {
            sub_47a948();
    }
    esp = (esp - 0x4) + 0x4;
    edi = (sub_47b26f(0x0) - *dword_ba2880) + 0x2710;
    if (esi == arg_0) {
            sub_47a948();
    }
    decomp_var_f4 = ebx;
    decomp_var_fc = "Our Delta value for sequence (%d) is (%d)";
    decomp_var_100 = &decomp_var_98;
    sub_410c10(decomp_var_100, "Our Delta value for sequence (%d) is (%d)", esi[0x4]);
    eax = *(**(decomp_var_98 - 0x10) + 0x10);
    esi = decomp_var_98 - 0x10;
    esp = (esp - 0x10) + 0x10;
    decomp_var_a4 = edi;
    eax = (eax)();
    ecx = esi + 0xc;
    if (esi[0x3] >= 0x0) {
            if (eax == *esi) {
                    edi = esi;
                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
            }
            else {
                    esp = esp - 0x8;
                    edi = (**eax)(esi[0x1], 0x1);
                    if (edi == 0x0) {
                            sub_40b6d0();
                    }
                    edi[0x1] = esi[0x1];
                    eax = esi[0x1];
                    decomp_var_10c = eax + 0x1;
                    sub_47a5af(edi + 0x10, decomp_var_10c, esi + 0x10, eax + 0x1);
                    esp = (esp - 0x10) + 0x10;
            }
    }
    else {
            esp = esp - 0x8;
            edi = (**eax)(esi[0x1], 0x1);
            if (edi == 0x0) {
                    sub_40b6d0();
            }
            edi[0x1] = esi[0x1];
            eax = esi[0x1];
            decomp_var_10c = eax + 0x1;
            sub_47a5af(edi + 0x10, decomp_var_10c, esi + 0x10, eax + 0x1);
            esp = (esp - 0x10) + 0x10;
    }
    esp = esp - 0x8;
    decomp_var_108 = &decomp_var_84;
    sub_419e60(decomp_var_108, &decomp_var_b4, decomp_var_100);
    eax = edi + 0x10 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
    if (ecx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    if (ebx > 0xffffff38) {
            ebx = 0x1;
    }
    else {
            if (ebx <= 0xfffe7960) {
                    ebx = 0x0;
            }
            else {
                    if (ebx <= 0xfffea070) {
                            ebx = 0x0;
                    }
                    else {
                            ebx = 0x0;
                    }
            }
    }
    goto loc_42705f;

loc_426ba6:
    ebp = decomp_var_b8;
    if (esi == 0x0 || esi != &decomp_var_bc) {
            sub_47a948();
    }
    if (edi != ebp) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            sub_465f60(edi + 0xc);
            decomp_var_34 = 0x0;
            edx = &decomp_var_74;
            esp = esp - 0xc;
            eax = sub_41a100(edx, &decomp_var_44, decomp_var_f0);
            sub_465fa0();
            sub_401590();
            edi = decomp_var_d4;
            esi = decomp_var_d8;
            continue;
    }
    break;
    edi = *dword_bb65f0;
    eax = edi[0x1];
    ecx = edi;
    if (eax[0xe9] == 0x0) {
            &decomp_var_f0 = &decomp_var_f0;
            do {
                    edx = eax[0x4];
                    if (edx < decomp_var_8c) {
                            eax = eax[0x2];
                    }
                    else {
                            ecx = eax;
                            eax = *eax;
                    }
            } while (eax[0xe9] == 0x0);
    }
    decomp_var_a4 = 0xbb65ec;
    if (ecx != *dword_bb65f0 && decomp_var_8c >= ecx[0x4]) {
            eax = &decomp_var_a4;
    }
    else {
            decomp_var_64 = 0xbb65ec;
            eax = &decomp_var_64;
    }
    ebp = *eax;
    esi = eax[0x1];
    if (ebp == 0x0) {
            sub_47a948();
    }
    if (esi == arg_0) {
            sub_47a948();
    }
    decomp_var_8c = esi[0xd0] & 0xff;
    if (esi == arg_0) {
            sub_47a948();
    }
    if (esi[0x27] > 0x0) {
            if (esi == arg_0) {
                    sub_47a948();
            }
            edi = *dword_bb65f0;
            eax = edi[0x1];
            ecx = edi;
            if (eax[0xe9] == 0x0) {
                    edx = esi[0x27];
                    do {
                            if (eax[0x4] < edx) {
                                    eax = eax[0x2];
                            }
                            else {
                                    ecx = eax;
                                    eax = *eax;
                            }
                    } while (eax[0xe9] == 0x0);
            }
            edi = *dword_bb65f0;
            decomp_var_a0 = ecx;
            decomp_var_a4 = 0xbb65ec;
            if (ecx != *dword_bb65f0) {
                    edx = esi[0x27];
                    if (edx >= ecx[0x4]) {
                            ebx = decomp_var_a4;
                            decomp_var_90 = decomp_var_a0;
                    }
                    else {
                            edi = *dword_bb65f0;
                            decomp_var_64 = 0xbb65ec;
                            ebx = decomp_var_64;
                            decomp_var_90 = edi;
                    }
            }
            else {
                    decomp_var_64 = 0xbb65ec;
                    ebx = decomp_var_64;
                    decomp_var_90 = edi;
            }
    }
    else {
            ebx = decomp_var_94;
    }
    if (esi == arg_0) {
            sub_47a948();
    }
    if (esi[0x27] > 0x0) {
            if (ebx == 0x0 || ebx != 0xbb65ec) {
                    sub_47a948();
            }
            if (decomp_var_90 != *dword_bb65f0) {
                    if (ebx == 0x0) {
                            sub_47a948();
                    }
                    if (decomp_var_90 == ebx[0x1]) {
                            sub_47a948();
                    }
                    edx = decomp_var_84;
                    eax = decomp_var_90;
                    if (*(eax + edx * 0x4 + 0x48) > 0xfffec780) {
                            if (eax == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (*(decomp_var_90 + decomp_var_8c * 0x4 + 0x48) > 0xfffec780) {
                                    if (esi == arg_0) {
                                            sub_47a948();
                                    }
                                    edx = decomp_var_90;
                                    if (edx == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    ebx = *(esi + decomp_var_84 * 0x4 + 0x48);
                                    ebx = ebx - *(decomp_var_90 + decomp_var_84 * 0x4 + 0x48);
                                    if (esi == arg_0) {
                                            sub_47a948();
                                    }
                            }
                            else {
                                    bool_119 = esi != arg_0;
                                    if (esi == arg_0) {
                                            sub_47a948();
                                    }
                                    ebx = *(esi + decomp_var_84 * 0x4 + 0x48);
                            }
                    }
                    else {
                            if (esi == arg_0) {
                                    sub_47a948();
                            }
                            ebx = *(esi + decomp_var_84 * 0x4 + 0x48);
                    }
            }
            else {
                    if (esi == arg_0) {
                            sub_47a948();
                    }
                    ebx = *(esi + decomp_var_84 * 0x4 + 0x48);
            }
    }
    else {
            if (esi == arg_0) {
                    sub_47a948();
            }
            ebx = *(esi + decomp_var_84 * 0x4 + 0x48);
    }
    if (!bool_119) {
            sub_47a948();
    }
    esp = (esp - 0x4) + 0x4;
    edi = (sub_47b26f(0x0) - *dword_ba2880) + 0x2710;
    if (esi == arg_0) {
            sub_47a948();
    }
    decomp_var_f4 = ebx;
    decomp_var_fc = "Our Delta value for sequence (%d) is (%d)";
    decomp_var_100 = &decomp_var_98;
    sub_410c10(decomp_var_100, "Our Delta value for sequence (%d) is (%d)", esi[0x4]);
    eax = *(**(decomp_var_98 - 0x10) + 0x10);
    esi = decomp_var_98 - 0x10;
    esp = (esp - 0x10) + 0x10;
    decomp_var_a4 = edi;
    eax = (eax)();
    ecx = esi + 0xc;
    if (esi[0x3] >= 0x0) {
            if (eax == *esi) {
                    edi = esi;
                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
            }
            else {
                    esp = esp - 0x8;
                    edi = (**eax)(esi[0x1], 0x1);
                    if (edi == 0x0) {
                            sub_40b6d0();
                    }
                    edi[0x1] = esi[0x1];
                    eax = esi[0x1];
                    decomp_var_10c = eax + 0x1;
                    sub_47a5af(edi + 0x10, decomp_var_10c, esi + 0x10, eax + 0x1);
                    esp = (esp - 0x10) + 0x10;
            }
    }
    else {
            esp = esp - 0x8;
            edi = (**eax)(esi[0x1], 0x1);
            if (edi == 0x0) {
                    sub_40b6d0();
            }
            edi[0x1] = esi[0x1];
            eax = esi[0x1];
            decomp_var_10c = eax + 0x1;
            sub_47a5af(edi + 0x10, decomp_var_10c, esi + 0x10, eax + 0x1);
            esp = (esp - 0x10) + 0x10;
    }
    esp = esp - 0x8;
    decomp_var_108 = &decomp_var_84;
    sub_419e60(decomp_var_108, &decomp_var_b4, decomp_var_100);
    eax = edi + 0x10 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
    if (ecx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    if (ebx > 0xffffff38) {
            ebx = 0x1;
    }
    else {
            if (ebx <= 0xfffe7960) {
                    ebx = 0x0;
            }
            else {
                    if (ebx <= 0xfffea070) {
                            ebx = 0x0;
                    }
                    else {
                            ebx = 0x0;
                    }
            }
    }
    goto .l3;
}
