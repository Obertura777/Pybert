// EvaluatePress @ 0x42fc40
// hopper name: sub_42fc40
// pybert name: EvaluatePress
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

EvaluatePress() {
    decomp_var_c = *0x0;
    decomp_var_8c = ebp;
    decomp_var_94 = edi;
    esp = esp - 0x98;
    decomp_var_98 = *dword_4c8db8 ^ &decomp_var_94;
    *0x0 = &decomp_var_c;
    edi = ecx;
    decomp_var_80 = edi;
    ebp = arg_0;
    *(int16_t *)ebp = 0x0;
    sub_465870();
    sub_465870();
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            (*(*eax + 0xc))() + 0x10;
            sub_410cf0(*(*dword_bb65d8 + 0x4));
            eax = *dword_bb65d8;
            eax[0x1] = eax;
            eax = *dword_bb65d8;
            *dword_bb65dc = 0x0;
            *eax = eax;
            eax = *dword_bb65d8;
            eax[0x2] = eax;
            eax = sub_466060(&decomp_var_4c, 0x1);
            sub_465ff0(eax);
            sub_465fa0();
            esp = esp - 0x18;
            decomp_var_a0 = &decomp_var_74;
            eax = sub_465900(decomp_var_a0, 0x0);
            edx = *(int16_t *)word_4c6d8c;
            if (*(int16_t *)word_4c6d8c != *(int16_t *)eax) {
                    decomp_var_80 = 0x0;
                    eax = sub_465930();
                    ecx = 0x0;
                    decomp_var_78 = eax - 0x1;
                    if (eax > 0x1) {
                            do {
                                    esi = ecx + 0x1;
                                    eax = sub_466060(&decomp_var_4c, esi);
                                    sub_465ff0(eax);
                                    sub_465fa0();
                                    esp = esp - 0x14;
                                    eax = sub_465900(&decomp_var_74, 0x0);
                                    if (*(int16_t *)word_4c6d0c != *(int16_t *)eax) {
                                            eax = sub_466060(&decomp_var_2c, 0x1);
                                            esp = esp - 0xc;
                                            sub_465ff0(eax);
                                            sub_465fa0();
                                    }
                                    esp = esp - 0x8;
                                    decomp_var_a0 = &decomp_var_7a;
                                    eax = sub_465900(decomp_var_a0, 0x0);
                                    edx = *(int16_t *)word_4c6df8;
                                    if (*(int16_t *)word_4c6df8 != *(int16_t *)eax) {
                                            decomp_var_80 = decomp_var_80 + 0x1;
                                    }
                                    ecx = esi;
                            } while (ecx < decomp_var_78);
                            if (decomp_var_80 > 0x1) {
                                    sub_465f60(&arg_18);
                                    decomp_var_ac = ecx;
                                    decomp_var_5c = &decomp_var_ac;
                                    decomp_var_ac = arg_14;
                                    edx = &arg_4;
                                    decomp_var_74 = &decomp_var_bc;
                                    sub_465f60(edx);
                                    esp = esp - 0x30;
                                    eax = sub_426350();
                                    eax = *(int16_t *)eax & 0xffff;
                                    bool_13 = *(int16_t *)word_4c6d48 == eax;
                                    *(int16_t *)ebp = eax;
                            }
                    }
                    eax = 0x0;
                    if (decomp_var_a0 > 0x0) {
                            esi = eax + 0x1;
                            decomp_var_9c = 0x0;
                            eax = sub_466060(&decomp_var_74, esi);
                            sub_465ff0(eax);
                            sub_465fa0();
                            edx = &decomp_var_94;
                            sub_465ff0(edx);
                            esp = esp - 0x18;
                            eax = sub_465900(&decomp_var_a2, 0x0);
                            if (*(int16_t *)word_4c6d0c != *(int16_t *)eax) {
                                    edx = &decomp_var_44;
                                    esp = esp - 0xc;
                                    sub_465ff0(sub_466060(edx, 0x1));
                                    sub_465fa0();
                            }
                            esp = esp - 0x8;
                            decomp_var_c8 = &decomp_var_84;
                            bool_20 = *(int16_t *)word_4c6df8 != *(int16_t *)sub_465900(decomp_var_c8, 0x0);
                            eax = 0x1;
                            if (!bool_20) {
                                    eax = decomp_var_9c;
                            }
                            if (decomp_var_a8 > 0x1) {
                                    if (eax == 0x0) {
                                            eax = sub_465f60(&decomp_var_c);
                                            decomp_var_d4 = ecx;
                                            decomp_var_d4 = decomp_var_10;
                                            eax = sub_465f60(&decomp_var_94);
                                            decomp_var_e8 = &decomp_var_98;
                                            ecx = *(int16_t *)sub_42c040() & 0xffff;
                                            edx = &decomp_var_bc;
                                            *(int16_t *)ebp = ecx;
                                            esp = esp - 0x38;
                                            sub_419300(&decomp_var_7c, edx, decomp_var_e8);
                                            if ((*(int16_t *)word_4c6d48 & 0xffff) != *(int16_t *)ebp) {
                                                    decomp_var_d1 = 0x0;
                                            }
                                            eax = esi;
                                            if (eax < decomp_var_c8) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    else {
                                            eax = esi;
                                            if (eax < decomp_var_c8) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    eax = sub_465f60(&decomp_var_c);
                                    decomp_var_d4 = ecx;
                                    decomp_var_d4 = decomp_var_10;
                                    eax = sub_465f60(&decomp_var_94);
                                    decomp_var_e8 = &decomp_var_98;
                                    ecx = *(int16_t *)sub_42c040() & 0xffff;
                                    edx = &decomp_var_bc;
                                    *(int16_t *)ebp = ecx;
                                    esp = esp - 0x38;
                                    sub_419300(&decomp_var_7c, edx, decomp_var_e8);
                                    if ((*(int16_t *)word_4c6d48 & 0xffff) != *(int16_t *)ebp) {
                                            decomp_var_d1 = 0x0;
                                    }
                                    eax = esi;
                                    if (eax < decomp_var_c8) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    if (decomp_var_d1 == 0x0) {
                            bool_11 = *(int8_t *)(*(*dword_bb65d8 + 0x4) + 0x1d) != 0x0;
                            *(int16_t *)ebp = *(int16_t *)word_4c6d28;
                            if (!bool_11) {
                                    eax = sub_430060();
                            }
                            else {
                                    eax = *dword_bb65d8;
                                    eax[0x1] = eax;
                                    eax = *dword_bb65d8;
                                    *dword_bb65dc = 0x0;
                                    *eax = eax;
                                    eax = *dword_bb65d8;
                                    eax[0x2] = eax;
                                    eax = decomp_var_a0 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], *(int16_t *)word_4c6d28 | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            (*(**eax + 0x4))(eax);
                                    }
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = ebp;
                                    *0x0 = decomp_var_5c;
                            }
                    }
                    else {
                            *(int16_t *)ebp = *(int16_t *)word_4c6d48;
                            eax = decomp_var_a0 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            if (edx <= 0x1) {
                                    esp = esp - 0x4;
                                    (*(**eax + 0x4))(eax);
                            }
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            eax = ebp;
                            *0x0 = decomp_var_5c;
                    }
            }
            else {
                    esi = 0x0;
                    edx = &decomp_var_70;
                    esp = esp - 0x8;
                    decomp_var_a0 = edx;
                    if (*(int16_t *)word_4c6dc0 != *(int16_t *)sub_465900(decomp_var_a0, 0x0)) {
                            eax = sub_465930();
                            ecx = 0x0;
                            if (eax - 0x1 > esi) {
                                    edi = arg_14;
                                    &decomp_var_98 = &decomp_var_98;
                                    while (true) {
                                            esi = ecx + 0x1;
                                            decomp_var_a0 = &decomp_var_1c;
                                            sub_465ff0(sub_466060(decomp_var_a0, esi));
                                            sub_465fa0();
                                            decomp_var_54 = &decomp_var_a8;
                                            eax = sub_465f60(&arg_18);
                                            decomp_var_ac = ecx;
                                            decomp_var_ac = edi;
                                            edx = &decomp_var_6c;
                                            decomp_var_5c = &decomp_var_bc;
                                            sub_465f60(edx);
                                            esp = esp - 0x3c;
                                            decomp_var_c0 = &decomp_var_70;
                                            eax = sub_42c040();
                                            eax = *(int16_t *)eax & 0xffff;
                                            bool_40 = *(int16_t *)word_4c6d48 != eax;
                                            *(int16_t *)ebp = eax;
                                            if (bool_40) {
                                                    ecx = esi;
                                                    if (ecx < decomp_var_a0) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            decomp_var_a9 = 0x1;
                                            if (*dword_bb65dc == 0x0) {
                                                    edx = &decomp_var_54;
                                                    esp = esp - 0x8;
                                                    eax = sub_419300(edx, &decomp_var_94, decomp_var_c0);
                                                    ecx = esi;
                                                    if (ecx < decomp_var_a0) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    ecx = sub_47b678();
                                                    edx = ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x64;
                                                    if (edx > 0x32) {
                                                            esp = esp - 0x4;
                                                            sub_410cf0(*(*dword_bb65d8 + 0x4));
                                                            eax = *dword_bb65d8;
                                                            eax[0x1] = eax;
                                                            eax = *dword_bb65d8;
                                                            *dword_bb65dc = 0x0;
                                                            *eax = eax;
                                                            eax = *dword_bb65d8;
                                                            eax[0x2] = eax;
                                                            edx = &decomp_var_74;
                                                            esp = esp - 0x8;
                                                            eax = sub_419300(edx, &decomp_var_94, decomp_var_c0);
                                                            ecx = esi;
                                                            if (ecx < decomp_var_a0) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            ecx = esi;
                                                            if (ecx < decomp_var_a0) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    if (decomp_var_a9 == 0x0) {
                                            *(int16_t *)ebp = *(int16_t *)word_4c6d28;
                                    }
                                    else {
                                            *(int16_t *)ebp = *(int16_t *)word_4c6d48;
                                    }
                            }
                            else {
                                    *(int16_t *)ebp = *(int16_t *)word_4c6d28;
                            }
                    }
                    else {
                            sub_465f60(&arg_18);
                            decomp_var_ac = ecx;
                            decomp_var_ac = arg_14;
                            edx = &arg_4;
                            sub_465f60(edx);
                            esp = esp - 0x30;
                            decomp_var_c0 = &decomp_var_70;
                            eax = sub_42c040();
                            eax = *(int16_t *)eax & 0xffff;
                            bool_9 = *(int16_t *)word_4c6d48 != eax;
                            *(int16_t *)ebp = eax;
                            if (!bool_9) {
                                    edx = &decomp_var_74;
                                    esp = esp - 0x8;
                                    sub_419300(edx, &decomp_var_20, decomp_var_c0);
                            }
                    }
                    eax = decomp_var_a0 - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    if (edx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    eax = ebp;
                    *0x0 = decomp_var_5c;
            }
    }
    return eax;
}
