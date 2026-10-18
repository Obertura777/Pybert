// DELAY_REVIEW @ 0x438e60
// hopper name: sub_438e60
// pybert name: DELAY_REVIEW
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5603afdb33265f2ea0acc9a81cbc14c61d166c3a97fb9b974c9d4823276f52ec
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

DELAY_REVIEW() {
    decomp_var_c = *0x0;
    decomp_var_dc = ebx;
    decomp_var_e0 = ebp;
    decomp_var_e4 = esi;
    decomp_var_e8 = edi;
    decomp_var_ec = *dword_4c8db8 ^ &decomp_var_e8;
    *0x0 = &decomp_var_c;
    decomp_var_88 = ecx;
    decomp_var_d6 = 0x0;
    decomp_var_d5 = 0x0;
    eax = sub_40fed0();
    decomp_var_b8 = eax;
    eax[0x21] = 0x1;
    decomp_var_b8[0x1] = decomp_var_b8;
    *decomp_var_b8 = decomp_var_b8;
    decomp_var_b8[0x2] = decomp_var_b8;
    sub_465870();
    esp = esp - 0xf0;
    eax = sub_465f60(&arg_0);
    eax = sub_40fd90();
    decomp_var_80 = eax;
    eax[0x1d] = 0x1;
    decomp_var_80[0x1] = decomp_var_80;
    *decomp_var_80 = decomp_var_80;
    decomp_var_80[0x2] = decomp_var_80;
    eax = sub_40fd90();
    decomp_var_d0 = eax;
    eax[0x1d] = 0x1;
    decomp_var_d0[0x1] = decomp_var_d0;
    *decomp_var_d0 = decomp_var_d0;
    decomp_var_d0[0x2] = decomp_var_d0;
    eax = sub_40fd90();
    decomp_var_c4 = eax;
    eax[0x1d] = 0x1;
    decomp_var_c4[0x1] = decomp_var_c4;
    *decomp_var_c4 = decomp_var_c4;
    decomp_var_c4[0x2] = decomp_var_c4;
    eax = sub_47020b();
    if (eax != 0x0) goto loc_438fbd;
    goto loc_438fb3;

loc_438fbd:
    decomp_var_78 = (*(*eax + 0xc))() + 0x10;
    sub_410cf0(decomp_var_d0[0x1]);
    decomp_var_d0[0x1] = decomp_var_d0;
    decomp_var_cc = 0x0;
    *decomp_var_d0 = decomp_var_d0;
    decomp_var_d0[0x2] = decomp_var_d0;
    sub_410cf0(decomp_var_c4[0x1]);
    decomp_var_c4[0x1] = decomp_var_c4;
    decomp_var_c0 = 0x0;
    *decomp_var_c4 = decomp_var_c4;
    decomp_var_c4[0x2] = decomp_var_c4;
    eax = sub_466060(&decomp_var_48, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    esp = esp - 0x1c;
    eax = sub_465900(&decomp_var_60, 0x0);
    if (*(int16_t *)word_4c6d8c == *(int16_t *)eax) goto loc_4390a9;
    goto loc_439087;

loc_438fb3:
    eax = sub_40b5a0(0x80004005);
    return eax;

loc_4390a9:
    esi = 0x0;
    edx = &decomp_var_b0;
    esp = esp - 0x8;
    if (*(int16_t *)word_4c6dc0 != *(int16_t *)sub_465900(edx, 0x0)) {
            decomp_var_d5 = 0x1;
    }
    edi = sub_465930() - 0x1;
    ecx = 0x0;
    if (edi <= esi) goto .l9;
    goto loc_4390ea;

loc_439087:
    edx = &decomp_var_b0;
    esp = esp - 0x8;
    if (*(int16_t *)word_4c6dc0 != *(int16_t *)sub_465900(edx, 0x0)) goto loc_4392ed;
    goto .l19;

.l9:
    eax = decomp_var_78 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_419cb0(&decomp_var_48, &decomp_var_c8, *decomp_var_c4, &decomp_var_c8, decomp_var_c4);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_d4, *decomp_var_d0, &decomp_var_d4, decomp_var_d0);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_84, *decomp_var_80, &decomp_var_84, decomp_var_80);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_41abc0(&decomp_var_48, &decomp_var_bc, *decomp_var_b8, &decomp_var_bc, decomp_var_b8);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    eax = 0x0;
    *0x0 = decomp_var_c;
    return eax;

loc_4390ea:
    do {
            esi = ecx + 0x1;
            edx = &decomp_var_98;
            sub_465ff0(sub_466060(edx, esi));
            sub_465fa0();
            esp = esp - 0x14;
            ebx = 0x0;
            eax = sub_465900(&decomp_var_b0, 0x0);
            if (*(int16_t *)word_4c6d0c != *(int16_t *)eax) {
                    edx = &decomp_var_a8;
                    esp = esp - 0xc;
                    sub_465ff0(sub_466060(edx, 0x1));
                    sub_465fa0();
                    ebx = 0x1;
            }
            esp = esp - 0x8;
            decomp_var_f4 = &decomp_var_60;
            if (*(int16_t *)word_4c6df8 != *(int16_t *)sub_465900(decomp_var_f4, 0x0)) {
                    decomp_var_d6 = 0x1;
                    if (ebx == 0x0) {
                            edx = &decomp_var_2c;
                            decomp_var_f0 = edx;
                            esp = esp - 0x8;
                            decomp_var_f4 = &decomp_var_48;
                    }
                    else {
                            decomp_var_f0 = &decomp_var_2c;
                            edx = &decomp_var_74;
                            esp = esp - 0x8;
                            decomp_var_f4 = edx;
                    }
                    sub_419300(decomp_var_f4, decomp_var_f0, decomp_var_ec);
            }
            ecx = esi;
    } while (ecx < edi);
    if (decomp_var_d6 != 0x1) goto .l3;
    goto .l2;

loc_4392ed:
    esi = 0x0;
    esp = esp - 0x8;
    ebx = 0x0;
    eax = sub_465900(&decomp_var_b0, 0x0);
    if (*(int16_t *)word_4c6d0c != *(int16_t *)eax) {
            edx = &decomp_var_48;
            esp = esp - 0xc;
            sub_465ff0(sub_466060(edx, 0x1));
            sub_465fa0();
            ebx = 0x1;
    }
    esp = esp - 0x8;
    eax = sub_465900(&decomp_var_b0, esi);
    if (*(int16_t *)word_4c6df8 == *(int16_t *)eax) goto loc_439a9f;
    goto loc_43937a;

.l19:
    edx = &decomp_var_b0;
    esp = esp - 0x8;
    if (*(int16_t *)word_4c6dc0 != *(int16_t *)sub_465900(edx, 0x0)) {
            decomp_var_d5 = 0x1;
    }
    edi = sub_465930() - 0x1;
    ecx = 0x0;
    if (edi <= 0x0) goto .l5;
    goto .l20;

.l3:
    eax = decomp_var_78 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_419cb0(&decomp_var_48, &decomp_var_c8, *decomp_var_c4, &decomp_var_c8, decomp_var_c4);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_d4, *decomp_var_d0, &decomp_var_d4, decomp_var_d0);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_84, *decomp_var_80, &decomp_var_84, decomp_var_80);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_41abc0(&decomp_var_48, &decomp_var_bc, *decomp_var_b8, &decomp_var_bc, decomp_var_b8);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    eax = 0x0;
    *0x0 = decomp_var_c;
    return eax;

.l2:
    ecx = 0xbb65ec;
    ebx = **dword_bb65f0;
    decomp_var_98 = 0xbb65ec;
    decomp_var_94 = **dword_bb65f0;
    goto .l38;

loc_439a9f:
    eax = decomp_var_78 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_419cb0(&decomp_var_48, &decomp_var_c8, *decomp_var_c4, &decomp_var_c8, decomp_var_c4);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_d4, *decomp_var_d0, &decomp_var_d4, decomp_var_d0);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_84, *decomp_var_80, &decomp_var_84, decomp_var_80);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_41abc0(&decomp_var_48, &decomp_var_bc, *decomp_var_b8, &decomp_var_bc, decomp_var_b8);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    eax = 0x0;
    *0x0 = decomp_var_c;
    return eax;

loc_43937a:
    if (ebx == 0x0) {
            edx = &arg_0;
            esp = esp - 0x8;
            decomp_var_f4 = &decomp_var_48;
            sub_419300(decomp_var_f4, edx, decomp_var_ec);
    }
    else {
            edx = &decomp_var_48;
            esp = esp - 0x8;
            decomp_var_f4 = edx;
            eax = sub_419300(decomp_var_f4, &arg_0, decomp_var_ec);
    }
    ecx = 0xbb65ec;
    ebx = **dword_bb65f0;
    decomp_var_98 = 0xbb65ec;
    decomp_var_94 = **dword_bb65f0;
    goto .l27;

.l5:
    eax = decomp_var_78 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_419cb0(&decomp_var_48, &decomp_var_c8, *decomp_var_c4, &decomp_var_c8, decomp_var_c4);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_d4, *decomp_var_d0, &decomp_var_d4, decomp_var_d0);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_84, *decomp_var_80, &decomp_var_84, decomp_var_80);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_41abc0(&decomp_var_48, &decomp_var_bc, *decomp_var_b8, &decomp_var_bc, decomp_var_b8);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    eax = 0x0;
    *0x0 = decomp_var_c;
    return eax;

.l20:
    do {
            esi = ecx + 0x1;
            edx = &decomp_var_98;
            sub_465ff0(sub_466060(edx, esi));
            sub_465fa0();
            esp = esp - 0x14;
            ebx = 0x0;
            eax = sub_465900(&decomp_var_b0, 0x0);
            if (*(int16_t *)word_4c6d0c != *(int16_t *)eax) {
                    edx = &decomp_var_a8;
                    esp = esp - 0xc;
                    sub_465ff0(sub_466060(edx, 0x1));
                    sub_465fa0();
                    ebx = 0x1;
            }
            esp = esp - 0x8;
            decomp_var_f4 = &decomp_var_60;
            if (*(int16_t *)word_4c6df8 != *(int16_t *)sub_465900(decomp_var_f4, 0x0)) {
                    decomp_var_d6 = 0x1;
                    if (ebx == 0x0) {
                            edx = &decomp_var_2c;
                            decomp_var_f0 = edx;
                            esp = esp - 0x8;
                            decomp_var_f4 = &decomp_var_48;
                    }
                    else {
                            decomp_var_f0 = &decomp_var_2c;
                            edx = &decomp_var_74;
                            esp = esp - 0x8;
                            decomp_var_f4 = edx;
                    }
                    sub_419300(decomp_var_f4, decomp_var_f0, decomp_var_ec);
            }
            ecx = esi;
    } while (ecx < edi);
    if (decomp_var_d6 != 0x1) goto .l4;
    goto .l17;

.l38:
    if (ecx == 0x0 || ecx != 0xbb65ec) {
            sub_47a948();
    }
    if (ebx == *dword_bb65f0) goto .l36;
    goto .l34;

.l27:
    if (ecx == 0x0 || ecx != 0xbb65ec) {
            sub_47a948();
    }
    if (ebx == *dword_bb65f0) goto .l24;
    goto .l26;

.l4:
    eax = decomp_var_78 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_419cb0(&decomp_var_48, &decomp_var_c8, *decomp_var_c4, &decomp_var_c8, decomp_var_c4);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_d4, *decomp_var_d0, &decomp_var_d4, decomp_var_d0);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_84, *decomp_var_80, &decomp_var_84, decomp_var_80);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_41abc0(&decomp_var_48, &decomp_var_bc, *decomp_var_b8, &decomp_var_bc, decomp_var_b8);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    eax = 0x0;
    *0x0 = decomp_var_c;
    return eax;

.l17:
    ecx = 0xbb65ec;
    ebx = **dword_bb65f0;
    decomp_var_98 = 0xbb65ec;
    decomp_var_94 = **dword_bb65f0;
    goto loc_439213;

.l36:
    eax = decomp_var_b8;
    edi = eax[0x1];
    esi = edi;
    if (edi[0x21] == 0x0) {
            temp_0 = 0x1;
    }
    else {
            temp_0 = 0x2;
    }
    break;

.l34:
    if (decomp_var_d5 != 0x0) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    esi = &decomp_var_d4;
    ebp = *decomp_var_d0;
    decomp_var_d6 = 0x1;
    decomp_var_a8 = esi;
    decomp_var_a4 = ebp;
    goto .l40;

.l24:
    eax = decomp_var_b8;
    edi = eax[0x1];
    esi = edi;
    if (edi[0x21] == 0x0) {
            temp_0 = 0x1;
    }
    else {
            temp_0 = 0x2;
    }
    break;

.l26:
    if (decomp_var_d5 != 0x0) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    esi = &decomp_var_d4;
    ebp = *decomp_var_d0;
    decomp_var_d6 = 0x1;
    decomp_var_a8 = esi;
    decomp_var_a4 = ebp;
    goto .l31;

loc_439213:
    if (ecx == 0x0 || ecx != 0xbb65ec) {
            sub_47a948();
    }
    if (ebx == *dword_bb65f0) goto loc_4395e3;
    goto loc_439232;
    if (temp_0 == 0x0) goto .l7;
    goto .l28;

.l40:
    edi = decomp_var_d0;
    if (esi == 0x0 || esi != &decomp_var_d4) {
            sub_47a948();
    }
    if (ebp != edi) {
            if (decomp_var_98 == 0x0) {
                    sub_47a948();
            }
            if (ebx == decomp_var_98[0x1]) {
                    sub_47a948();
            }
            edi = ebx + 0x30;
            decomp_var_5c = ebx[0xd];
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            ebx = &arg_8;
            if (decomp_var_94 == decomp_var_98[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x1];
            esi = eax[0x1];
            ebp = eax;
            if (esi[0x1d] == 0x0) {
                    esp = esp - 0x4;
                    if (sub_465cf0(ebx) != 0x0) {
                            esi = esi[0x2];
                    }
                    else {
                            ebp = esi;
                            esi = *esi;
                    }
                    if (esi[0x1d] == 0x0) {
                            continue;
                    }
                    break;
            }
            decomp_var_74 = edi;
            if (ebp != edi[0x1]) {
                    esp = esp - 0x4;
                    eax = sub_465cf0(&arg_8);
                    if (eax == 0x0) {
                            eax = &decomp_var_74;
                    }
                    else {
                            decomp_var_50 = edi;
                            eax = &decomp_var_50;
                    }
            }
            else {
                    decomp_var_50 = edi;
                    eax = &decomp_var_50;
            }
            ecx = *eax;
            esi = eax[0x1];
            if (ecx == 0x0 || ecx != edi) {
                    sub_47a948();
            }
            if (esi == decomp_var_5c) {
                    decomp_var_d6 = 0x0;
            }
            sub_401590();
            ebp = decomp_var_a4;
            esi = decomp_var_a8;
            ebx = decomp_var_94;
            continue;
    }
    break;
    if (temp_0 == 0x0) goto .l10;
    goto .l8;

.l31:
    edi = decomp_var_d0;
    if (esi == 0x0 || esi != &decomp_var_d4) {
            sub_47a948();
    }
    if (ebp != edi) {
            if (decomp_var_98 == 0x0) {
                    sub_47a948();
            }
            if (ebx == decomp_var_98[0x1]) {
                    sub_47a948();
            }
            edi = ebx + 0x30;
            decomp_var_5c = ebx[0xd];
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            ebx = &arg_8;
            if (decomp_var_94 == decomp_var_98[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x1];
            esi = eax[0x1];
            ebp = eax;
            if (esi[0x1d] == 0x0) {
                    esp = esp - 0x4;
                    if (sub_465cf0(ebx) != 0x0) {
                            esi = esi[0x2];
                    }
                    else {
                            ebp = esi;
                            esi = *esi;
                    }
                    if (esi[0x1d] == 0x0) {
                            continue;
                    }
                    break;
            }
            decomp_var_74 = edi;
            if (ebp != edi[0x1]) {
                    esp = esp - 0x4;
                    eax = sub_465cf0(&arg_8);
                    if (eax == 0x0) {
                            eax = &decomp_var_74;
                    }
                    else {
                            decomp_var_50 = edi;
                            eax = &decomp_var_50;
                    }
            }
            else {
                    decomp_var_50 = edi;
                    eax = &decomp_var_50;
            }
            ecx = *eax;
            esi = eax[0x1];
            if (ecx == 0x0 || ecx != edi) {
                    sub_47a948();
            }
            if (esi == decomp_var_5c) {
                    decomp_var_d6 = 0x0;
            }
            sub_401590();
            ebp = decomp_var_a4;
            esi = decomp_var_a8;
            ebx = decomp_var_94;
            continue;
    }
    break;

loc_4395e3:
    eax = decomp_var_b8;
    edi = eax[0x1];
    esi = edi;
    if (edi[0x21] == 0x0) {
            temp_0 = 0x1;
    }
    else {
            temp_0 = 0x2;
    }
    break;

loc_439232:
    if (decomp_var_d5 != 0x0) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    esi = &decomp_var_d4;
    ebp = *decomp_var_d0;
    decomp_var_d6 = 0x1;
    decomp_var_a8 = esi;
    decomp_var_a4 = ebp;
    goto loc_439256;

.l7:
    ebx = 0x0;
    goto loc_439aa3;

.l28:
    if (temp_0 == 0x1) {
            do {
                    sub_410d70(esi[0x2]);
                    esi = *esi;
                    sub_465fa0();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x21] == 0x0);
            eax = decomp_var_b8;
    }
    eax[0x1] = eax;
    decomp_var_b4 = 0x0;
    *decomp_var_b8 = decomp_var_b8;
    decomp_var_b8[0x2] = decomp_var_b8;
    edx = decomp_var_d0;
    edi = *edx;
    esi = &decomp_var_d4;
    decomp_var_a8 = esi;
    decomp_var_a4 = edi;
    goto .l32;
    edx = decomp_var_c4;
    esi = &decomp_var_c8;
    ebp = *edx;
    decomp_var_a8 = esi;
    decomp_var_a4 = ebp;
    goto .l39;

.l10:
    ebx = 0x0;
    goto .l12;

.l8:
    if (temp_0 == 0x1) {
            do {
                    sub_410d70(esi[0x2]);
                    esi = *esi;
                    sub_465fa0();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x21] == 0x0);
            eax = decomp_var_b8;
    }
    eax[0x1] = eax;
    decomp_var_b4 = 0x0;
    *decomp_var_b8 = decomp_var_b8;
    decomp_var_b8[0x2] = decomp_var_b8;
    edx = decomp_var_d0;
    edi = *edx;
    esi = &decomp_var_d4;
    decomp_var_a8 = esi;
    decomp_var_a4 = edi;
    goto loc_439646;
    edx = decomp_var_c4;
    esi = &decomp_var_c8;
    ebp = *edx;
    decomp_var_a8 = esi;
    decomp_var_a4 = ebp;
    goto .l30;
    if (temp_0 == 0x0) goto .l18;
    goto .l16;

loc_439256:
    edi = decomp_var_d0;
    if (esi == 0x0 || esi != &decomp_var_d4) {
            sub_47a948();
    }
    if (ebp != edi) {
            if (decomp_var_98 == 0x0) {
                    sub_47a948();
            }
            if (ebx == decomp_var_98[0x1]) {
                    sub_47a948();
            }
            edi = ebx + 0x30;
            decomp_var_5c = ebx[0xd];
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            ebx = &arg_8;
            if (decomp_var_94 == decomp_var_98[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x1];
            esi = eax[0x1];
            ebp = eax;
            if (esi[0x1d] == 0x0) {
                    esp = esp - 0x4;
                    if (sub_465cf0(ebx) != 0x0) {
                            esi = esi[0x2];
                    }
                    else {
                            ebp = esi;
                            esi = *esi;
                    }
                    if (esi[0x1d] == 0x0) {
                            continue;
                    }
                    break;
            }
            decomp_var_74 = edi;
            if (ebp != edi[0x1]) {
                    esp = esp - 0x4;
                    eax = sub_465cf0(&arg_8);
                    if (eax == 0x0) {
                            eax = &decomp_var_74;
                    }
                    else {
                            decomp_var_50 = edi;
                            eax = &decomp_var_50;
                    }
            }
            else {
                    decomp_var_50 = edi;
                    eax = &decomp_var_50;
            }
            ecx = *eax;
            esi = eax[0x1];
            if (ecx == 0x0 || ecx != edi) {
                    sub_47a948();
            }
            if (esi == decomp_var_5c) {
                    decomp_var_d6 = 0x0;
            }
            sub_401590();
            ebp = decomp_var_a4;
            esi = decomp_var_a8;
            ebx = decomp_var_94;
            continue;
    }
    break;

loc_439aa3:
    eax = decomp_var_78 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_419cb0(&decomp_var_48, &decomp_var_c8, *decomp_var_c4, &decomp_var_c8, decomp_var_c4);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_d4, *decomp_var_d0, &decomp_var_d4, decomp_var_d0);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_84, *decomp_var_80, &decomp_var_84, decomp_var_80);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_41abc0(&decomp_var_48, &decomp_var_bc, *decomp_var_b8, &decomp_var_bc, decomp_var_b8);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    eax = ebx;
    *0x0 = decomp_var_c;
    return eax;

.l32:
    ebx = decomp_var_d0;
    if (esi == 0x0 || esi != &decomp_var_d4) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            sub_465f60(edi + 0xc);
            edx = &decomp_var_48;
            esp = esp - 0xc;
            decomp_var_f4 = edx;
            eax = sub_41a100(decomp_var_f4, &decomp_var_74, decomp_var_ec);
            sub_465fa0();
            sub_401590();
            edi = decomp_var_a4;
            esi = decomp_var_a8;
            continue;
    }
    break;

.l39:
    edi = decomp_var_c4;
    if (esi == 0x0 || esi != &decomp_var_c8) {
            sub_47a948();
    }
    if (ebp != edi) {
            if (decomp_var_98 == 0x0) {
                    sub_47a948();
            }
            if (ebx == decomp_var_98[0x1]) {
                    sub_47a948();
            }
            edx = ebx[0x10];
            edi = ebx + 0x3c;
            decomp_var_44 = edx;
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            ebx = &arg_8;
            if (decomp_var_94 == decomp_var_98[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x1];
            esi = eax[0x1];
            ebp = eax;
            if (esi[0x1d] != 0x0) {
                    decomp_var_58 = edi;
                    if (ebp != edi[0x1]) {
                            esp = esp - 0x4;
                            eax = sub_465cf0(&arg_8);
                            if (eax == 0x0) {
                                    eax = &decomp_var_58;
                            }
                            else {
                                    edx = edi[0x1];
                                    decomp_var_b0 = edi;
                                    eax = &decomp_var_b0;
                            }
                    }
                    else {
                            edx = edi[0x1];
                            decomp_var_b0 = edi;
                            eax = &decomp_var_b0;
                    }
                    ecx = *eax;
                    esi = eax[0x1];
                    if (ecx == 0x0 || ecx != edi) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_44) {
                            decomp_var_d6 = 0x0;
                    }
                    sub_401590();
                    ebp = decomp_var_a4;
                    esi = decomp_var_a8;
                    ebx = decomp_var_94;
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
            decomp_var_58 = edi;
            if (ebp != edi[0x1]) {
                    esp = esp - 0x4;
                    eax = sub_465cf0(&arg_8);
                    if (eax == 0x0) {
                            eax = &decomp_var_58;
                    }
                    else {
                            edx = edi[0x1];
                            decomp_var_b0 = edi;
                            eax = &decomp_var_b0;
                    }
            }
            else {
                    edx = edi[0x1];
                    decomp_var_b0 = edi;
                    eax = &decomp_var_b0;
            }
            ecx = *eax;
            esi = eax[0x1];
            if (ecx == 0x0 || ecx != edi) {
                    sub_47a948();
            }
            if (esi == decomp_var_44) {
                    decomp_var_d6 = 0x0;
            }
            sub_401590();
            ebp = decomp_var_a4;
            esi = decomp_var_a8;
            ebx = decomp_var_94;
            continue;
    }
    break;

.l12:
    eax = decomp_var_78 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_419cb0(&decomp_var_48, &decomp_var_c8, *decomp_var_c4, &decomp_var_c8, decomp_var_c4);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_d4, *decomp_var_d0, &decomp_var_d4, decomp_var_d0);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_84, *decomp_var_80, &decomp_var_84, decomp_var_80);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_41abc0(&decomp_var_48, &decomp_var_bc, *decomp_var_b8, &decomp_var_bc, decomp_var_b8);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    eax = ebx;
    *0x0 = decomp_var_c;
    return eax;

loc_439646:
    ebx = decomp_var_d0;
    if (esi == 0x0 || esi != &decomp_var_d4) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            sub_465f60(edi + 0xc);
            edx = &decomp_var_48;
            esp = esp - 0xc;
            decomp_var_f4 = edx;
            eax = sub_41a100(decomp_var_f4, &decomp_var_74, decomp_var_ec);
            sub_465fa0();
            sub_401590();
            edi = decomp_var_a4;
            esi = decomp_var_a8;
            continue;
    }
    break;

.l30:
    edi = decomp_var_c4;
    if (esi == 0x0 || esi != &decomp_var_c8) {
            sub_47a948();
    }
    if (ebp != edi) {
            if (decomp_var_98 == 0x0) {
                    sub_47a948();
            }
            if (ebx == decomp_var_98[0x1]) {
                    sub_47a948();
            }
            edx = ebx[0x10];
            edi = ebx + 0x3c;
            decomp_var_44 = edx;
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            ebx = &arg_8;
            if (decomp_var_94 == decomp_var_98[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x1];
            esi = eax[0x1];
            ebp = eax;
            if (esi[0x1d] != 0x0) {
                    decomp_var_58 = edi;
                    if (ebp != edi[0x1]) {
                            esp = esp - 0x4;
                            eax = sub_465cf0(&arg_8);
                            if (eax == 0x0) {
                                    eax = &decomp_var_58;
                            }
                            else {
                                    edx = edi[0x1];
                                    decomp_var_b0 = edi;
                                    eax = &decomp_var_b0;
                            }
                    }
                    else {
                            edx = edi[0x1];
                            decomp_var_b0 = edi;
                            eax = &decomp_var_b0;
                    }
                    ecx = *eax;
                    esi = eax[0x1];
                    if (ecx == 0x0 || ecx != edi) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_44) {
                            decomp_var_d6 = 0x0;
                    }
                    sub_401590();
                    ebp = decomp_var_a4;
                    esi = decomp_var_a8;
                    ebx = decomp_var_94;
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
            decomp_var_58 = edi;
            if (ebp != edi[0x1]) {
                    esp = esp - 0x4;
                    eax = sub_465cf0(&arg_8);
                    if (eax == 0x0) {
                            eax = &decomp_var_58;
                    }
                    else {
                            edx = edi[0x1];
                            decomp_var_b0 = edi;
                            eax = &decomp_var_b0;
                    }
            }
            else {
                    edx = edi[0x1];
                    decomp_var_b0 = edi;
                    eax = &decomp_var_b0;
            }
            ecx = *eax;
            esi = eax[0x1];
            if (ecx == 0x0 || ecx != edi) {
                    sub_47a948();
            }
            if (esi == decomp_var_44) {
                    decomp_var_d6 = 0x0;
            }
            sub_401590();
            ebp = decomp_var_a4;
            esi = decomp_var_a8;
            ebx = decomp_var_94;
            continue;
    }
    break;

.l18:
    ebx = 0x0;
    goto .l14;

.l16:
    if (temp_0 == 0x1) {
            do {
                    sub_410d70(esi[0x2]);
                    esi = *esi;
                    sub_465fa0();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x21] == 0x0);
            eax = decomp_var_b8;
    }
    eax[0x1] = eax;
    decomp_var_b4 = 0x0;
    *decomp_var_b8 = decomp_var_b8;
    decomp_var_b8[0x2] = decomp_var_b8;
    edx = decomp_var_d0;
    edi = *edx;
    esi = &decomp_var_d4;
    decomp_var_a8 = esi;
    decomp_var_a4 = edi;
    goto .l22;
    edx = decomp_var_c4;
    esi = &decomp_var_c8;
    ebp = *edx;
    decomp_var_a8 = esi;
    decomp_var_a4 = ebp;
    goto loc_439450;
    edi = *decomp_var_c4;
    esi = &decomp_var_c8;
    decomp_var_a8 = esi;
    decomp_var_a4 = edi;
    goto .l42;
    if (decomp_var_98 == 0x0) {
            sub_47a948();
    }
    if (ebx == decomp_var_98[0x1]) {
            sub_47a948();
    }
    if (ebx[0x18] == 0x1) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    if (ebx == decomp_var_98[0x1]) {
            sub_47a948();
    }
    if (ebx[0x7] != 0x0) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    edx = decomp_var_98;
    esi = decomp_var_cc;
    if (ebx == edx[0x1]) {
            sub_47a948();
    }
    if (esi != ebx[0xe]) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    eax = decomp_var_98;
    esi = decomp_var_c0;
    if (ebx == eax[0x1]) {
            eax = sub_47a948();
    }
    if (esi != ebx[0x11]) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    if (decomp_var_d6 != 0x1) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    temp_0 = 0x0;
    break;
    edi = *decomp_var_c4;
    esi = &decomp_var_c8;
    decomp_var_a8 = esi;
    decomp_var_a4 = edi;
    goto loc_4396e0;
    if (decomp_var_98 == 0x0) {
            sub_47a948();
    }
    if (ebx == decomp_var_98[0x1]) {
            sub_47a948();
    }
    if (ebx[0x18] == 0x1) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    if (ebx == decomp_var_98[0x1]) {
            sub_47a948();
    }
    if (ebx[0x7] != 0x0) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    edx = decomp_var_98;
    esi = decomp_var_cc;
    if (ebx == edx[0x1]) {
            sub_47a948();
    }
    if (esi != ebx[0xe]) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    eax = decomp_var_98;
    esi = decomp_var_c0;
    if (ebx == eax[0x1]) {
            eax = sub_47a948();
    }
    if (esi != ebx[0x11]) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    if (decomp_var_d6 != 0x1) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    temp_0 = 0x0;
    break;

.l14:
    eax = decomp_var_78 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_419cb0(&decomp_var_48, &decomp_var_c8, *decomp_var_c4, &decomp_var_c8, decomp_var_c4);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_d4, *decomp_var_d0, &decomp_var_d4, decomp_var_d0);
    sub_47c8f9();
    sub_419cb0(&decomp_var_48, &decomp_var_84, *decomp_var_80, &decomp_var_84, decomp_var_80);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_41abc0(&decomp_var_48, &decomp_var_bc, *decomp_var_b8, &decomp_var_bc, decomp_var_b8);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    eax = ebx;
    *0x0 = decomp_var_c;
    return eax;

.l22:
    ebx = decomp_var_d0;
    if (esi == 0x0 || esi != &decomp_var_d4) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            sub_465f60(edi + 0xc);
            edx = &decomp_var_48;
            esp = esp - 0xc;
            decomp_var_f4 = edx;
            eax = sub_41a100(decomp_var_f4, &decomp_var_74, decomp_var_ec);
            sub_465fa0();
            sub_401590();
            edi = decomp_var_a4;
            esi = decomp_var_a8;
            continue;
    }
    break;

loc_439450:
    edi = decomp_var_c4;
    if (esi == 0x0 || esi != &decomp_var_c8) {
            sub_47a948();
    }
    if (ebp != edi) {
            if (decomp_var_98 == 0x0) {
                    sub_47a948();
            }
            if (ebx == decomp_var_98[0x1]) {
                    sub_47a948();
            }
            edx = ebx[0x10];
            edi = ebx + 0x3c;
            decomp_var_44 = edx;
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            ebx = &arg_8;
            if (decomp_var_94 == decomp_var_98[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x1];
            esi = eax[0x1];
            ebp = eax;
            if (esi[0x1d] != 0x0) {
                    decomp_var_58 = edi;
                    if (ebp != edi[0x1]) {
                            esp = esp - 0x4;
                            eax = sub_465cf0(&arg_8);
                            if (eax == 0x0) {
                                    eax = &decomp_var_58;
                            }
                            else {
                                    edx = edi[0x1];
                                    decomp_var_b0 = edi;
                                    eax = &decomp_var_b0;
                            }
                    }
                    else {
                            edx = edi[0x1];
                            decomp_var_b0 = edi;
                            eax = &decomp_var_b0;
                    }
                    ecx = *eax;
                    esi = eax[0x1];
                    if (ecx == 0x0 || ecx != edi) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_44) {
                            decomp_var_d6 = 0x0;
                    }
                    sub_401590();
                    ebp = decomp_var_a4;
                    esi = decomp_var_a8;
                    ebx = decomp_var_94;
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
            decomp_var_58 = edi;
            if (ebp != edi[0x1]) {
                    esp = esp - 0x4;
                    eax = sub_465cf0(&arg_8);
                    if (eax == 0x0) {
                            eax = &decomp_var_58;
                    }
                    else {
                            edx = edi[0x1];
                            decomp_var_b0 = edi;
                            eax = &decomp_var_b0;
                    }
            }
            else {
                    edx = edi[0x1];
                    decomp_var_b0 = edi;
                    eax = &decomp_var_b0;
            }
            ecx = *eax;
            esi = eax[0x1];
            if (ecx == 0x0 || ecx != edi) {
                    sub_47a948();
            }
            if (esi == decomp_var_44) {
                    decomp_var_d6 = 0x0;
            }
            sub_401590();
            ebp = decomp_var_a4;
            esi = decomp_var_a8;
            ebx = decomp_var_94;
            continue;
    }
    break;

.l42:
    ebp = 0x0;
    ebx = decomp_var_c4;
    if (esi == 0x0 || esi != &decomp_var_c8) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == ebp) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            sub_465f60(edi + 0xc);
            edx = &decomp_var_74;
            esp = esp - 0xc;
            decomp_var_f4 = &decomp_var_48;
            sub_41a100(decomp_var_f4, edx, decomp_var_ec);
            sub_465fa0();
            sub_401590();
            edi = decomp_var_a4;
            esi = decomp_var_a8;
            continue;
    }
    break;

loc_4396e0:
    ebp = 0x0;
    ebx = decomp_var_c4;
    if (esi == 0x0 || esi != &decomp_var_c8) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == ebp) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            sub_465f60(edi + 0xc);
            edx = &decomp_var_74;
            esp = esp - 0xc;
            decomp_var_f4 = &decomp_var_48;
            sub_41a100(decomp_var_f4, edx, decomp_var_ec);
            sub_465fa0();
            sub_401590();
            edi = decomp_var_a4;
            esi = decomp_var_a8;
            continue;
    }
    break;
    edi = *decomp_var_c4;
    esi = &decomp_var_c8;
    decomp_var_a8 = esi;
    decomp_var_a4 = edi;
    goto .l41;
    if (decomp_var_98 == 0x0) {
            sub_47a948();
    }
    if (ebx == decomp_var_98[0x1]) {
            sub_47a948();
    }
    if (ebx[0x18] == 0x1) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    if (ebx == decomp_var_98[0x1]) {
            sub_47a948();
    }
    if (ebx[0x7] != 0x0) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    edx = decomp_var_98;
    esi = decomp_var_cc;
    if (ebx == edx[0x1]) {
            sub_47a948();
    }
    if (esi != ebx[0xe]) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    eax = decomp_var_98;
    esi = decomp_var_c0;
    if (ebx == eax[0x1]) {
            eax = sub_47a948();
    }
    if (esi != ebx[0x11]) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    if (decomp_var_d6 != 0x1) {
            sub_40f470();
            ebx = decomp_var_94;
            ecx = decomp_var_98;
            continue;
    }
    temp_0 = 0x0;
    break;
    decomp_var_b0 = 0xfff85ee0;
    if (decomp_var_d5 == 0x0) {
            eax = sub_4220e0(&decomp_var_bc);
            eax = sub_465f60(&arg_14);
            decomp_var_110 = ecx;
            decomp_var_110 = arg_10;
            edx = &decomp_var_1c;
            esp = esp - 0x40;
            sub_465f60(edx);
            decomp_var_b0 = sub_431310(decomp_var_120, decomp_var_11c, decomp_var_118, decomp_var_114, decomp_var_110, decomp_var_10c, decomp_var_108, decomp_var_104, decomp_var_100, decomp_var_fc, decomp_var_f8, decomp_var_f4, decomp_var_f0, decomp_var_ec);
    }
    else {
            esi = arg_10;
            edi = decomp_var_88;
            decomp_var_58 = decomp_var_b4;
            ecx = &decomp_var_bc;
            decomp_var_60 = 0x0;
            decomp_var_74 = ecx;
            decomp_var_70 = *decomp_var_b8;
            &decomp_var_ec = &decomp_var_ec;
            while (true) {
                    ebx = decomp_var_b8;
                    if (ecx != 0x0) {
                            edx = &decomp_var_bc;
                            if (ecx != edx) {
                                    sub_47a948();
                            }
                    }
                    else {
                            sub_47a948();
                    }
                    if (decomp_var_70 == ebx) {
                            break;
                    }
                    eax = decomp_var_60 + 0x1;
                    decomp_var_60 = eax;
                    if (eax == decomp_var_58) {
                            decomp_var_f0 = 0x1;
                            decomp_var_100 = &decomp_var_bc;
                            sub_4220e0(decomp_var_100);
                            edx = &arg_14;
                            sub_465f60(edx);
                            decomp_var_110 = ecx;
                            decomp_var_110 = esi;
                            esp = esp - 0x40;
                            decomp_var_124 = &decomp_var_1c;
                    }
                    else {
                            decomp_var_f0 = 0x0;
                            decomp_var_100 = &decomp_var_bc;
                            sub_4220e0(decomp_var_100);
                            eax = sub_465f60(&arg_14);
                            decomp_var_110 = ecx;
                            decomp_var_110 = esi;
                            edx = &decomp_var_1c;
                            esp = esp - 0x40;
                            decomp_var_124 = edx;
                    }
                    sub_465f60(decomp_var_124);
                    eax = sub_431310(decomp_var_120, decomp_var_11c, decomp_var_118, decomp_var_114, decomp_var_110, decomp_var_10c, decomp_var_108, decomp_var_104, decomp_var_100, decomp_var_fc, decomp_var_f8, decomp_var_f4, decomp_var_f0, decomp_var_ec);
                    if (eax > decomp_var_b0) {
                            decomp_var_b0 = eax;
                    }
                    sub_40f6f0();
                    ecx = decomp_var_74;
            }
    }
    if (decomp_var_b0 == 0x0) {
            sub_47b26f(0x0);
            esi = (sub_47b26f(0x0) - *dword_ba2880) + 0x2710;
            esp = (esp - 0x8) + 0x8 - 0x4;
            decomp_var_44 = edx;
            eax = sub_46b050(&decomp_var_48, decomp_var_ec, decomp_var_e8);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_78, 0x4b0f8c, eax);
            esp = (esp - 0xc) + 0xc;
            if (decomp_var_30 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            ebp = 0x0;
            decomp_var_74 = esi;
            edx = *(**(decomp_var_78 - 0x10) + 0x10);
            esi = decomp_var_78 - 0x10;
            eax = (edx)();
            ecx = esi + 0xc;
            if (esi[0x3] >= 0x0) {
                    if (eax == *esi) {
                            edi = esi;
                            *ecx = lock intrinsic_xadd(*ecx, 0x1);
                    }
                    else {
                            ecx = esi[0x1];
                            edx = *eax;
                            edx = *edx;
                            esp = esp - 0x8;
                            edi = (edx)(ecx, 0x1);
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
                    ecx = esi[0x1];
                    edx = *eax;
                    edx = *edx;
                    esp = esp - 0x8;
                    edi = (edx)(ecx, 0x1);
                    if (edi == ebp) {
                            sub_40b6d0();
                    }
                    edi[0x1] = esi[0x1];
                    eax = esi[0x1];
                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                    esp = (esp - 0x10) + 0x10;
            }
            esp = esp - 0x8;
            eax = sub_419e60(&decomp_var_48, &decomp_var_74, decomp_var_ec);
            eax = edi + 0x10 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            edx = edx - 0x1;
            if (edx <= 0x0) {
                    edx = **eax;
                    esp = esp - 0x4;
                    (edx[0x1])(eax);
            }
            ebx = 0x1;
    }
    else {
            ebx = 0x0;
    }
    goto loc_439aa3;
    decomp_var_b0 = 0xfff85ee0;
    if (decomp_var_d5 == 0x0) {
            eax = sub_4220e0(&decomp_var_bc);
            eax = sub_465f60(&arg_14);
            decomp_var_110 = ecx;
            decomp_var_110 = arg_10;
            edx = &decomp_var_1c;
            esp = esp - 0x40;
            sub_465f60(edx);
            decomp_var_b0 = sub_431310(decomp_var_120, decomp_var_11c, decomp_var_118, decomp_var_114, decomp_var_110, decomp_var_10c, decomp_var_108, decomp_var_104, decomp_var_100, decomp_var_fc, decomp_var_f8, decomp_var_f4, decomp_var_f0, decomp_var_ec);
    }
    else {
            esi = arg_10;
            edi = decomp_var_88;
            decomp_var_58 = decomp_var_b4;
            ecx = &decomp_var_bc;
            decomp_var_60 = 0x0;
            decomp_var_74 = ecx;
            decomp_var_70 = *decomp_var_b8;
            &decomp_var_ec = &decomp_var_ec;
            while (true) {
                    ebp = 0x0;
                    ebx = decomp_var_b8;
                    if (ecx != 0x0) {
                            edx = &decomp_var_bc;
                            if (ecx != edx) {
                                    sub_47a948();
                            }
                    }
                    else {
                            sub_47a948();
                    }
                    if (decomp_var_70 == ebx) {
                            break;
                    }
                    eax = decomp_var_60 + 0x1;
                    decomp_var_60 = eax;
                    if (eax == decomp_var_58) {
                            decomp_var_f0 = 0x1;
                            decomp_var_100 = &decomp_var_bc;
                            sub_4220e0(decomp_var_100);
                            edx = &arg_14;
                            sub_465f60(edx);
                            decomp_var_110 = ecx;
                            decomp_var_110 = esi;
                            esp = esp - 0x40;
                            decomp_var_124 = &decomp_var_1c;
                    }
                    else {
                            decomp_var_f0 = ebp;
                            decomp_var_100 = &decomp_var_bc;
                            sub_4220e0(decomp_var_100);
                            eax = sub_465f60(&arg_14);
                            decomp_var_110 = ecx;
                            decomp_var_110 = esi;
                            edx = &decomp_var_1c;
                            esp = esp - 0x40;
                            decomp_var_124 = edx;
                    }
                    sub_465f60(decomp_var_124);
                    eax = sub_431310(decomp_var_120, decomp_var_11c, decomp_var_118, decomp_var_114, decomp_var_110, decomp_var_10c, decomp_var_108, decomp_var_104, decomp_var_100, decomp_var_fc, decomp_var_f8, decomp_var_f4, decomp_var_f0, decomp_var_ec);
                    if (eax > decomp_var_b0) {
                            decomp_var_b0 = eax;
                    }
                    sub_40f6f0();
                    ecx = decomp_var_74;
            }
    }
    if (decomp_var_b0 == 0x0) {
            sub_47b26f(0x0);
            esi = (sub_47b26f(0x0) - *dword_ba2880) + 0x2710;
            esp = (esp - 0x8) + 0x8 - 0x4;
            decomp_var_44 = edx;
            eax = sub_46b050(&decomp_var_48, decomp_var_ec, decomp_var_e8);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_78, 0x4b0f8c, eax);
            esp = (esp - 0xc) + 0xc;
            if (decomp_var_30 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            decomp_var_74 = esi;
            edx = *(**(decomp_var_78 - 0x10) + 0x10);
            esi = decomp_var_78 - 0x10;
            eax = (edx)();
            ecx = esi + 0xc;
            if (esi[0x3] >= 0x0) {
                    if (eax == *esi) {
                            edi = esi;
                            *ecx = lock intrinsic_xadd(*ecx, 0x1);
                    }
                    else {
                            ecx = esi[0x1];
                            edx = *eax;
                            edx = *edx;
                            esp = esp - 0x8;
                            edi = (edx)(ecx, 0x1);
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
                    ecx = esi[0x1];
                    edx = *eax;
                    edx = *edx;
                    esp = esp - 0x8;
                    edi = (edx)(ecx, 0x1);
                    if (edi == 0x0) {
                            sub_40b6d0();
                    }
                    edi[0x1] = esi[0x1];
                    eax = esi[0x1];
                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                    esp = (esp - 0x10) + 0x10;
            }
            esp = esp - 0x8;
            eax = sub_419e60(&decomp_var_48, &decomp_var_74, decomp_var_ec);
            eax = edi + 0x10 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            edx = edx - 0x1;
            if (edx <= 0x0) {
                    edx = **eax;
                    esp = esp - 0x4;
                    (edx[0x1])(eax);
            }
            ebx = 0x1;
    }
    else {
            ebx = 0x0;
    }
    goto .l12;

.l41:
    ebx = decomp_var_c4;
    if (esi == 0x0 || esi != &decomp_var_c8) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            sub_465f60(edi + 0xc);
            edx = &decomp_var_74;
            esp = esp - 0xc;
            decomp_var_f4 = &decomp_var_48;
            sub_41a100(decomp_var_f4, edx, decomp_var_ec);
            sub_465fa0();
            sub_401590();
            edi = decomp_var_a4;
            esi = decomp_var_a8;
            continue;
    }
    break;
    decomp_var_b0 = 0xfff85ee0;
    if (decomp_var_d5 == 0x0) {
            eax = sub_4220e0(&decomp_var_bc);
            eax = sub_465f60(&arg_14);
            decomp_var_110 = ecx;
            decomp_var_110 = arg_10;
            edx = &decomp_var_1c;
            esp = esp - 0x40;
            sub_465f60(edx);
            decomp_var_b0 = sub_431310(decomp_var_120, decomp_var_11c, decomp_var_118, decomp_var_114, decomp_var_110, decomp_var_10c, decomp_var_108, decomp_var_104, decomp_var_100, decomp_var_fc, decomp_var_f8, decomp_var_f4, decomp_var_f0, decomp_var_ec);
    }
    else {
            esi = arg_10;
            edi = decomp_var_88;
            decomp_var_58 = decomp_var_b4;
            ecx = &decomp_var_bc;
            decomp_var_60 = 0x0;
            decomp_var_74 = ecx;
            decomp_var_70 = *decomp_var_b8;
            &decomp_var_ec = &decomp_var_ec;
            while (true) {
                    ebp = 0x0;
                    ebx = decomp_var_b8;
                    if (ecx != 0x0) {
                            edx = &decomp_var_bc;
                            if (ecx != edx) {
                                    sub_47a948();
                            }
                    }
                    else {
                            sub_47a948();
                    }
                    if (decomp_var_70 == ebx) {
                            break;
                    }
                    eax = decomp_var_60 + 0x1;
                    decomp_var_60 = eax;
                    if (eax == decomp_var_58) {
                            decomp_var_f0 = 0x1;
                            decomp_var_100 = &decomp_var_bc;
                            sub_4220e0(decomp_var_100);
                            edx = &arg_14;
                            sub_465f60(edx);
                            decomp_var_110 = ecx;
                            decomp_var_110 = esi;
                            esp = esp - 0x40;
                            decomp_var_124 = &decomp_var_1c;
                    }
                    else {
                            decomp_var_f0 = ebp;
                            decomp_var_100 = &decomp_var_bc;
                            sub_4220e0(decomp_var_100);
                            eax = sub_465f60(&arg_14);
                            decomp_var_110 = ecx;
                            decomp_var_110 = esi;
                            edx = &decomp_var_1c;
                            esp = esp - 0x40;
                            decomp_var_124 = edx;
                    }
                    sub_465f60(decomp_var_124);
                    eax = sub_431310(decomp_var_120, decomp_var_11c, decomp_var_118, decomp_var_114, decomp_var_110, decomp_var_10c, decomp_var_108, decomp_var_104, decomp_var_100, decomp_var_fc, decomp_var_f8, decomp_var_f4, decomp_var_f0, decomp_var_ec);
                    if (eax > decomp_var_b0) {
                            decomp_var_b0 = eax;
                    }
                    sub_40f6f0();
                    ecx = decomp_var_74;
            }
    }
    if (decomp_var_b0 == 0x0) {
            sub_47b26f(0x0);
            esi = (sub_47b26f(0x0) - *dword_ba2880) + 0x2710;
            esp = (esp - 0x8) + 0x8 - 0x4;
            decomp_var_44 = edx;
            eax = sub_46b050(&decomp_var_48, decomp_var_ec, decomp_var_e8);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_78, 0x4b0f8c, eax);
            esp = (esp - 0xc) + 0xc;
            if (decomp_var_30 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            ebp = 0x0;
            decomp_var_74 = esi;
            edx = *(**(decomp_var_78 - 0x10) + 0x10);
            esi = decomp_var_78 - 0x10;
            eax = (edx)();
            ecx = esi + 0xc;
            if (esi[0x3] >= 0x0) {
                    if (eax == *esi) {
                            edi = esi;
                            *ecx = lock intrinsic_xadd(*ecx, 0x1);
                    }
                    else {
                            ecx = esi[0x1];
                            edx = *eax;
                            edx = *edx;
                            esp = esp - 0x8;
                            edi = (edx)(ecx, 0x1);
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
                    ecx = esi[0x1];
                    edx = *eax;
                    edx = *edx;
                    esp = esp - 0x8;
                    edi = (edx)(ecx, 0x1);
                    if (edi == ebp) {
                            sub_40b6d0();
                    }
                    edi[0x1] = esi[0x1];
                    eax = esi[0x1];
                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                    esp = (esp - 0x10) + 0x10;
            }
            esp = esp - 0x8;
            eax = sub_419e60(&decomp_var_48, &decomp_var_74, decomp_var_ec);
            eax = edi + 0x10 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            edx = edx - 0x1;
            if (edx <= 0x0) {
                    edx = **eax;
                    esp = esp - 0x4;
                    (edx[0x1])(eax);
            }
            ebx = 0x1;
    }
    else {
            ebx = 0x0;
    }
    goto .l14;
}
