// sub_42d0b0 @ 0x42d0b0
// hopper name: sub_42d0b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_42d0b0() {
    &decomp_var_4 = &decomp_var_4 & 0xfffffff8;
    decomp_var_10 = *0x0;
    decomp_var_98 = ebx;
    decomp_var_9c = ebp;
    decomp_var_a0 = esi;
    decomp_var_a4 = edi;
    esp = esp - 0xa4;
    decomp_var_a8 = *dword_4c8db8 ^ &decomp_var_a4;
    *0x0 = &decomp_var_10;
    ebx = ecx;
    decomp_var_84 = *(int8_t *)(ebx[0x2] + 0x2424) & 0xff;
    eax = sub_47020b();
    if (eax == 0x0) {
            esp = esp - 0x4;
            decomp_var_ac = 0x80004005;
            eax = sub_40b5a0(0x80004005);
    }
    decomp_var_7c = (*(*eax + 0xc))() + 0x10;
    edx = 0x0;
    if (*(ebx[0x2] + 0x2404) > 0x0) {
            sub_42d150(decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88);
    }
    eax = ebx[0x2];
    ecx = eax[0x901];
    decomp_var_90 = 0x0;
    if (ecx <= 0x0) goto loc_42db01;
    goto loc_42d201;

loc_42db01:
    eax = decomp_var_90 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    *0x0 = decomp_var_28;
    &decomp_var_ac = decomp_var_b4;
    return;

loc_42d201:
    goto loc_42d210;

loc_42d210:
    decomp_var_8c = 0x0;
    if (ecx <= 0x0) goto loc_42dae5;
    goto loc_42d220;

loc_42dae5:
    eax = ebx[0x2];
    ecx = eax[0x901];
    edx = decomp_var_a4 + 0x1;
    decomp_var_a4 = edx;
    if (edx < ecx) {
            continue;
    }
    temp_1 = 0x2;
    break;

loc_42d220:
    edi = eax + 0x2450;
    esi = *edi[0x1];
    decomp_var_92 = 0x0;
    decomp_var_78 = edi;
    decomp_var_74 = esi;
    goto loc_42d240;

.l2:
    if (temp_1 != 0x0 && temp_1 != 0x1) {
            eax = decomp_var_90 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            if (edx <= 0x1) {
                    esp = esp - 0x4;
                    (*(**eax + 0x4))(eax);
            }
            *0x0 = decomp_var_28;
            &decomp_var_ac = decomp_var_b4;
    }
    return;

loc_42d240:
    eax = ebx[0x2];
    ebp = eax[0x915];
    eax = eax + 0x2450;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] != decomp_var_8c) {
                    sub_401390();
                    esi = decomp_var_74;
                    edi = decomp_var_78;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = esi[0x6];
            if (edx != decomp_var_90) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi[0x4];
                    if (*(int8_t *)(ebx[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) != 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi = esi[0x4];
                            eax = ebx[0x2];
                            edx = esi + esi * 0x8;
                            eax = *(int16_t *)(eax + edx * 0x4 + 0x20);
                            bool_718 = HIBYTE(eax) == 0x41;
                            eax = eax & 0xff;
                            if (!bool_718) {
                                    eax = 0x14;
                            }
                            if (eax == decomp_var_90) {
                                    decomp_var_92 = 0x1;
                            }
                    }
            }
            sub_401390();
            esi = decomp_var_74;
            edi = decomp_var_78;
            continue;
    }
    break;
    edi = ebx[0x2];
    eax = edi[0x924];
    edi = edi + 0x248c;
    esi = *eax;
    decomp_var_78 = edi;
    decomp_var_74 = esi;
    goto loc_42d310;

loc_42d310:
    eax = ebx[0x2];
    ebp = eax[0x924];
    eax = eax + 0x248c;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] != decomp_var_8c) {
                    sub_401390();
                    esi = decomp_var_74;
                    edi = decomp_var_78;
                    ebx = decomp_var_84;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = decomp_var_90;
            if (esi[0x6] == edx) {
                    sub_401390();
                    esi = decomp_var_74;
                    edi = decomp_var_78;
                    ebx = decomp_var_84;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x8] == 0x2) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_827 = esi != edi[0x1];
                    decomp_var_80 = esi[0x9];
                    if (!bool_827) {
                            sub_47a948();
                    }
                    eax = decomp_var_88;
                    if (esi[0x6] == eax) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            ecx = decomp_var_88;
                            if (esi[0x6] != ecx) {
                                    sub_401390();
                                    esi = decomp_var_74;
                                    edi = decomp_var_78;
                                    ebx = decomp_var_84;
                                    continue;
                            }
                            eax = decomp_var_90;
                            if (eax == ecx) {
                                    sub_401390();
                                    esi = decomp_var_74;
                                    edi = decomp_var_78;
                                    ebx = decomp_var_84;
                                    continue;
                            }
                            edx = &decomp_var_80;
                            esi = (eax + eax * 0x2) * 0x4 + 0xbb6f28;
                            decomp_var_b0 = edx;
                            esp = esp - 0x8;
                            decomp_var_b4 = &decomp_var_38;
                            ebp = esi[0x1];
                            edi = sub_401ff0(decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                            eax = *edi;
                            if (eax == 0x0 || eax != esi) {
                                    sub_47a948();
                            }
                            if (edi[0x1] != ebp) {
                                    decomp_var_92 = 0x1;
                            }
                            sub_401390();
                            esi = decomp_var_74;
                            edi = decomp_var_78;
                            ebx = decomp_var_84;
                            continue;
                    }
                    if (decomp_var_90 == eax) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            bool_780 = esi != edi[0x1];
                            eax = esi[0x6];
                            ebx = (eax + eax * 0x2) * 0x4 + 0xbb7028;
                            decomp_var_54 = *((eax + eax * 0x2) * 0x4 + 0xbb702c);
                            if (!bool_780) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_80;
                            decomp_var_b0 = edx;
                            esp = esp - 0x8;
                            decomp_var_b4 = &decomp_var_40;
                            eax = sub_401ff0(decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                            eax = *eax;
                            if (eax == 0x0 || eax != ebx) {
                                    sub_47a948();
                            }
                            if (arg_0 != decomp_var_54) {
                                    decomp_var_92 = 0x1;
                                    sub_401390();
                                    esi = decomp_var_74;
                                    edi = decomp_var_78;
                                    ebx = decomp_var_84;
                                    continue;
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            ecx = decomp_var_88;
                            if (esi[0x6] != ecx) {
                                    sub_401390();
                                    esi = decomp_var_74;
                                    edi = decomp_var_78;
                                    ebx = decomp_var_84;
                                    continue;
                            }
                            eax = decomp_var_90;
                            if (eax == ecx) {
                                    sub_401390();
                                    esi = decomp_var_74;
                                    edi = decomp_var_78;
                                    ebx = decomp_var_84;
                                    continue;
                            }
                            edx = &decomp_var_80;
                            esi = (eax + eax * 0x2) * 0x4 + 0xbb6f28;
                            decomp_var_b0 = edx;
                            esp = esp - 0x8;
                            decomp_var_b4 = &decomp_var_38;
                            ebp = esi[0x1];
                            edi = sub_401ff0(decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                            eax = *edi;
                            if (eax == 0x0 || eax != esi) {
                                    sub_47a948();
                            }
                            if (edi[0x1] != ebp) {
                                    decomp_var_92 = 0x1;
                            }
                            sub_401390();
                            esi = decomp_var_74;
                            edi = decomp_var_78;
                            ebx = decomp_var_84;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    ecx = decomp_var_88;
                    if (esi[0x6] != ecx) {
                            sub_401390();
                            esi = decomp_var_74;
                            edi = decomp_var_78;
                            ebx = decomp_var_84;
                            continue;
                    }
                    eax = decomp_var_90;
                    if (eax == ecx) {
                            sub_401390();
                            esi = decomp_var_74;
                            edi = decomp_var_78;
                            ebx = decomp_var_84;
                            continue;
                    }
                    edx = &decomp_var_80;
                    esi = (eax + eax * 0x2) * 0x4 + 0xbb6f28;
                    decomp_var_b0 = edx;
                    esp = esp - 0x8;
                    decomp_var_b4 = &decomp_var_38;
                    ebp = esi[0x1];
                    edi = sub_401ff0(decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                    eax = *edi;
                    if (eax == 0x0 || eax != esi) {
                            sub_47a948();
                    }
                    if (edi[0x1] != ebp) {
                            decomp_var_92 = 0x1;
                    }
                    sub_401390();
                    esi = decomp_var_74;
                    edi = decomp_var_78;
                    ebx = decomp_var_84;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x8] != 0x6) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x8] != 0x4) {
                            sub_401390();
                            esi = decomp_var_74;
                            edi = decomp_var_78;
                            ebx = decomp_var_84;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_831 = esi != edi[0x1];
                    decomp_var_80 = esi[0xc];
                    if (!bool_831) {
                            sub_47a948();
                    }
                    eax = decomp_var_88;
                    if (esi[0x6] == eax) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = decomp_var_88;
                            if (esi[0x6] != edx) {
                                    sub_401390();
                                    esi = decomp_var_74;
                                    edi = decomp_var_78;
                                    ebx = decomp_var_84;
                                    continue;
                            }
                            if (decomp_var_90 == edx) {
                                    sub_401390();
                                    esi = decomp_var_74;
                                    edi = decomp_var_78;
                                    ebx = decomp_var_84;
                                    continue;
                            }
                            decomp_var_b0 = &decomp_var_80;
                            edx = &decomp_var_48;
                            esi = (decomp_var_90 + decomp_var_90 * 0x2) * 0x4 + 0xbb6f28;
                            esp = esp - 0x8;
                            decomp_var_b4 = edx;
                            ebp = esi[0x1];
                            edi = sub_401ff0(decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                            eax = *edi;
                            if (eax == 0x0 || eax != esi) {
                                    sub_47a948();
                            }
                            if (edi[0x1] != ebp) {
                                    decomp_var_92 = 0x1;
                            }
                            sub_401390();
                            esi = decomp_var_74;
                            edi = decomp_var_78;
                            ebx = decomp_var_84;
                            continue;
                    }
                    if (decomp_var_90 == eax) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            bool_823 = esi != edi[0x1];
                            eax = esi[0x6];
                            ebx = (eax + eax * 0x2) * 0x4 + 0xbb7028;
                            decomp_var_5c = *((eax + eax * 0x2) * 0x4 + 0xbb702c);
                            if (!bool_823) {
                                    sub_47a948();
                            }
                            edx = &decomp_var_80;
                            decomp_var_b0 = edx;
                            esp = esp - 0x8;
                            decomp_var_b4 = &decomp_var_50;
                            eax = sub_401ff0(decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                            eax = *eax;
                            if (eax == 0x0 || eax != ebx) {
                                    sub_47a948();
                            }
                            if (arg_0 != decomp_var_5c) {
                                    decomp_var_92 = 0x1;
                                    sub_401390();
                                    esi = decomp_var_74;
                                    edi = decomp_var_78;
                                    ebx = decomp_var_84;
                                    continue;
                            }
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = decomp_var_88;
                            if (esi[0x6] != edx) {
                                    sub_401390();
                                    esi = decomp_var_74;
                                    edi = decomp_var_78;
                                    ebx = decomp_var_84;
                                    continue;
                            }
                            if (decomp_var_90 == edx) {
                                    sub_401390();
                                    esi = decomp_var_74;
                                    edi = decomp_var_78;
                                    ebx = decomp_var_84;
                                    continue;
                            }
                            decomp_var_b0 = &decomp_var_80;
                            edx = &decomp_var_48;
                            esi = (decomp_var_90 + decomp_var_90 * 0x2) * 0x4 + 0xbb6f28;
                            esp = esp - 0x8;
                            decomp_var_b4 = edx;
                            ebp = esi[0x1];
                            edi = sub_401ff0(decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                            eax = *edi;
                            if (eax == 0x0 || eax != esi) {
                                    sub_47a948();
                            }
                            if (edi[0x1] != ebp) {
                                    decomp_var_92 = 0x1;
                            }
                            sub_401390();
                            esi = decomp_var_74;
                            edi = decomp_var_78;
                            ebx = decomp_var_84;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = decomp_var_88;
                    if (esi[0x6] != edx) {
                            sub_401390();
                            esi = decomp_var_74;
                            edi = decomp_var_78;
                            ebx = decomp_var_84;
                            continue;
                    }
                    if (decomp_var_90 == edx) {
                            sub_401390();
                            esi = decomp_var_74;
                            edi = decomp_var_78;
                            ebx = decomp_var_84;
                            continue;
                    }
                    decomp_var_b0 = &decomp_var_80;
                    edx = &decomp_var_48;
                    esi = (decomp_var_90 + decomp_var_90 * 0x2) * 0x4 + 0xbb6f28;
                    esp = esp - 0x8;
                    decomp_var_b4 = edx;
                    ebp = esi[0x1];
                    edi = sub_401ff0(decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                    eax = *edi;
                    if (eax == 0x0 || eax != esi) {
                            sub_47a948();
                    }
                    if (edi[0x1] != ebp) {
                            decomp_var_92 = 0x1;
                    }
                    sub_401390();
                    esi = decomp_var_74;
                    edi = decomp_var_78;
                    ebx = decomp_var_84;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_782 = esi != edi[0x1];
            decomp_var_80 = esi[0x9];
            if (!bool_782) {
                    sub_47a948();
            }
            eax = decomp_var_88;
            if (esi[0x6] == eax) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    ecx = decomp_var_88;
                    if (esi[0x6] != ecx) {
                            sub_401390();
                            esi = decomp_var_74;
                            edi = decomp_var_78;
                            ebx = decomp_var_84;
                            continue;
                    }
                    eax = decomp_var_90;
                    if (eax == ecx) {
                            sub_401390();
                            esi = decomp_var_74;
                            edi = decomp_var_78;
                            ebx = decomp_var_84;
                            continue;
                    }
                    edx = &decomp_var_80;
                    esi = (eax + eax * 0x2) * 0x4 + 0xbb6f28;
                    decomp_var_b0 = edx;
                    esp = esp - 0x8;
                    decomp_var_b4 = &decomp_var_38;
                    ebp = esi[0x1];
                    edi = sub_401ff0(decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                    eax = *edi;
                    if (eax == 0x0 || eax != esi) {
                            sub_47a948();
                    }
                    if (edi[0x1] != ebp) {
                            decomp_var_92 = 0x1;
                    }
                    sub_401390();
                    esi = decomp_var_74;
                    edi = decomp_var_78;
                    ebx = decomp_var_84;
                    continue;
            }
            if (decomp_var_90 == eax) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    bool_753 = esi != edi[0x1];
                    eax = esi[0x6];
                    ebx = (eax + eax * 0x2) * 0x4 + 0xbb7028;
                    decomp_var_54 = *((eax + eax * 0x2) * 0x4 + 0xbb702c);
                    if (!bool_753) {
                            sub_47a948();
                    }
                    edx = &decomp_var_80;
                    decomp_var_b0 = edx;
                    esp = esp - 0x8;
                    decomp_var_b4 = &decomp_var_40;
                    eax = sub_401ff0(decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 != decomp_var_54) {
                            decomp_var_92 = 0x1;
                            sub_401390();
                            esi = decomp_var_74;
                            edi = decomp_var_78;
                            ebx = decomp_var_84;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    ecx = decomp_var_88;
                    if (esi[0x6] != ecx) {
                            sub_401390();
                            esi = decomp_var_74;
                            edi = decomp_var_78;
                            ebx = decomp_var_84;
                            continue;
                    }
                    eax = decomp_var_90;
                    if (eax == ecx) {
                            sub_401390();
                            esi = decomp_var_74;
                            edi = decomp_var_78;
                            ebx = decomp_var_84;
                            continue;
                    }
                    edx = &decomp_var_80;
                    esi = (eax + eax * 0x2) * 0x4 + 0xbb6f28;
                    decomp_var_b0 = edx;
                    esp = esp - 0x8;
                    decomp_var_b4 = &decomp_var_38;
                    ebp = esi[0x1];
                    edi = sub_401ff0(decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                    eax = *edi;
                    if (eax == 0x0 || eax != esi) {
                            sub_47a948();
                    }
                    if (edi[0x1] != ebp) {
                            decomp_var_92 = 0x1;
                    }
                    sub_401390();
                    esi = decomp_var_74;
                    edi = decomp_var_78;
                    ebx = decomp_var_84;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            ecx = decomp_var_88;
            if (esi[0x6] != ecx) {
                    sub_401390();
                    esi = decomp_var_74;
                    edi = decomp_var_78;
                    ebx = decomp_var_84;
                    continue;
            }
            eax = decomp_var_90;
            if (eax == ecx) {
                    sub_401390();
                    esi = decomp_var_74;
                    edi = decomp_var_78;
                    ebx = decomp_var_84;
                    continue;
            }
            edx = &decomp_var_80;
            esi = (eax + eax * 0x2) * 0x4 + 0xbb6f28;
            decomp_var_b0 = edx;
            esp = esp - 0x8;
            decomp_var_b4 = &decomp_var_38;
            ebp = esi[0x1];
            edi = sub_401ff0(decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4);
            eax = *edi;
            if (eax == 0x0 || eax != esi) {
                    sub_47a948();
            }
            if (edi[0x1] != ebp) {
                    decomp_var_92 = 0x1;
            }
            sub_401390();
            esi = decomp_var_74;
            edi = decomp_var_78;
            ebx = decomp_var_84;
            continue;
    }
    break;
    if (decomp_var_92 == 0x1) {
            esi = decomp_var_90;
            ecx = decomp_var_8c;
            eax = esi * 0x15 + ecx;
            *(eax * 0x4 + 0x62cc68) = 0x1;
            if (esi == decomp_var_88) {
                    esp = esp - 0x4;
                    sub_46db50();
                    eax = sub_4273a0(decomp_var_b0);
                    if (eax[0x6] >= 0x10) {
                            eax = eax[0x1];
                    }
                    else {
                            eax = eax + 0x4;
                    }
                    decomp_var_b0 = eax;
                    decomp_var_b4 = "We have been stabbed by (%s) during the turn";
                    decomp_var_b8 = &decomp_var_7c;
                    sub_410c10(decomp_var_b8, "We have been stabbed by (%s) during the turn", decomp_var_b0);
                    edx = *(**(decomp_var_7c - 0x10) + 0x10);
                    esi = decomp_var_7c - 0x10;
                    esp = (esp - 0xc) + 0xc;
                    eax = (edx)();
                    ecx = esi + 0xc;
                    if (esi[0x3] >= 0x0) {
                            if (eax == *esi) {
                                    edi = esi;
                                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
                                    esp = esp - 0x8;
                                    eax = sub_419e60(&decomp_var_3c, &decomp_var_7c, decomp_var_b8);
                                    eax = edi + 0x10 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            (*(**eax + 0x4))(eax);
                                    }
                                    decomp_var_bc = "Enemy desired because of stab";
                                    decomp_var_c0 = &decomp_var_88;
                                    *(int8_t *)byte_baed5f = 0x1;
                                    sub_410c10(decomp_var_c0, "Enemy desired because of stab", decomp_var_b8);
                                    edx = **(decomp_var_88 - 0x10);
                                    eax = edx[0x4];
                                    esi = decomp_var_88 - 0x10;
                                    esp = (esp - 0x8) + 0x8;
                                    eax = (eax)();
                                    ecx = esi + 0xc;
                                    if (esi[0x3] >= 0x0) {
                                            if (eax == *esi) {
                                                    edi = esi;
                                                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
                                                    esp = esp - 0x8;
                                                    eax = sub_419e60(&decomp_var_38, &decomp_var_7c, decomp_var_c0);
                                                    eax = edi + 0x10 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    ebx = decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2;
                                                    ebp = *(ebx[0x2edbcb] + 0x4);
                                                    esi = ebx + 0xbb6f28;
                                                    edi = ebp;
                                                    if (arg_d == 0x0) {
                                                            sub_401950(edi[0x2]);
                                                            edi = *edi;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x8) + 0x4;
                                                            ebp = edi;
                                                            if (edi[0x11] == 0x0) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    eax = esi[0x1];
                                                    eax[0x1] = eax;
                                                    eax = esi[0x1];
                                                    esi[0x2] = 0x0;
                                                    *eax = eax;
                                                    esi = esi[0x1];
                                                    esi[0x2] = esi;
                                                    ebp = *(ebx[0x2edc0b] + 0x4);
                                                    edi = ebx + 0xbb7028;
                                                    esi = ebp;
                                                    if (arg_d == 0x0) {
                                                            sub_401950(esi[0x2]);
                                                            esi = *esi;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x8) + 0x4;
                                                            ebp = esi;
                                                            if (esi[0x11] == 0x0) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    eax = edi[0x1];
                                                    ebx = decomp_var_98;
                                                    esi = decomp_var_a4;
                                                    eax[0x1] = eax;
                                                    eax = edi[0x1];
                                                    edi[0x2] = 0x0;
                                                    *eax = eax;
                                                    edi = edi[0x1];
                                                    eax = decomp_var_94;
                                                    edi[0x2] = edi;
                                                    edx = decomp_var_a0;
                                                    if (decomp_var_9c == edx) {
                                                            ebx = decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2;
                                                            esi = ebx + 0xbb6f28;
                                                            if (arg_d == 0x0) {
                                                                    sub_42d850();
                                                            }
                                                            eax = esi[0x1];
                                                            eax[0x1] = eax;
                                                            eax = esi[0x1];
                                                            esi[0x2] = 0x0;
                                                            *eax = eax;
                                                            esi = esi[0x1];
                                                            esi[0x2] = esi;
                                                            ebp = *(ebx[0x2edc0b] + 0x4);
                                                            edi = ebx + 0xbb7028;
                                                            esi = ebp;
                                                            if (arg_d == 0x0) {
                                                                    do {
                                                                            sub_401950(esi[0x2]);
                                                                            esi = *esi;
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x8) + 0x4;
                                                                            ebp = esi;
                                                                    } while (esi[0x11] == 0x0);
                                                            }
                                                            eax = edi[0x1];
                                                            ebx = decomp_var_98;
                                                            esi = decomp_var_a4;
                                                            eax[0x1] = eax;
                                                            eax = edi[0x1];
                                                            edi[0x2] = 0x0;
                                                            *eax = eax;
                                                            edi = edi[0x1];
                                                            eax = decomp_var_94;
                                                            edi[0x2] = edi;
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                    edx = decomp_var_a0;
                                                            }
                                                            else {
                                                                    edx = decomp_var_a0;
                                                                    *(eax * 0x4 + 0x62c580) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                            }
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cd0 != ecx && *(int16_t *)word_4c6cd4 != ecx) {
                                                                    if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                            }
                                                            else {
                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                            }
                                                            *(eax * 0x8 + 0x4d5528) = 0x0;
                                                            *(eax * 0x8 + 0x4d552c) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                            if (esi == decomp_var_9c) {
                                                                    if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                            *(int8_t *)byte_baed44 = 0x0;
                                                                    }
                                                                    esi = *dword_4c6bc4;
                                                                    if (*dword_4c6bc4 > 0xffffffff) {
                                                                            esi = *dword_4c6bc4;
                                                                            if (edx == *dword_4c6bc4) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    eax = *dword_4c6bc8;
                                                                                    ecx = *dword_4c6bcc;
                                                                                    esi = esi | 0xffffffff;
                                                                                    *dword_4c6bc4 = esi;
                                                                                    if (eax > 0xffffffff) {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                            esi = eax;
                                                                                            eax = eax | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            if (ecx > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = ecx;
                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    *dword_4c6bcc = ecx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                            }
                                                            else {
                                                                    esi = *dword_4c6bc4;
                                                                    ecx = *dword_4c6bcc;
                                                                    eax = *dword_4c6bc8;
                                                            }
                                                            if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff && decomp_var_a4 == esi) {
                                                                    *dword_4c6bc4 = 0xffffffff;
                                                                    if (eax > 0xffffffff) {
                                                                            *dword_4c6bc4 = eax;
                                                                            eax = eax | 0xffffffff;
                                                                            *dword_4c6bc8 = eax;
                                                                            if (ecx > 0xffffffff) {
                                                                                    eax = ecx;
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_a4 == decomp_var_9c) {
                                                                    if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                            eax = eax | 0xffffffff;
                                                                            *dword_4c6bc8 = eax;
                                                                    }
                                                            }
                                                            edx = decomp_var_9c;
                                                            if (decomp_var_a0 == edx && eax > 0xffffffff && decomp_var_a4 == eax) {
                                                                    *dword_4c6bc8 = 0xffffffff;
                                                                    if (ecx > 0xffffffff) {
                                                                            *dword_4c6bc8 = ecx;
                                                                            ecx = ecx | 0xffffffff;
                                                                            *dword_4c6bcc = ecx;
                                                                    }
                                                            }
                                                            eax = edx;
                                                            edx = decomp_var_a4;
                                                            if (edx == eax) {
                                                                    if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                            ecx = ecx | 0xffffffff;
                                                                            *dword_4c6bcc = ecx;
                                                                    }
                                                            }
                                                            if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                    if (edx == ecx) {
                                                                            *dword_4c6bcc = 0xffffffff;
                                                                    }
                                                            }
                                                            eax = ebx[0x2];
                                                            bool_312 = decomp_var_a0 + 0x1 < eax[0x901];
                                                            decomp_var_a0 = decomp_var_a0 + 0x1;
                                                            if (bool_312) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                                    else {
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                    edx = decomp_var_a0;
                                                            }
                                                            else {
                                                                    edx = decomp_var_a0;
                                                                    *(eax * 0x4 + 0x62c580) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                            }
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cd0 != ecx && *(int16_t *)word_4c6cd4 != ecx) {
                                                                    if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                            }
                                                            else {
                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                            }
                                                            *(eax * 0x8 + 0x4d5528) = 0x0;
                                                            *(eax * 0x8 + 0x4d552c) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                            if (esi == decomp_var_9c) {
                                                                    if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                            *(int8_t *)byte_baed44 = 0x0;
                                                                    }
                                                                    esi = *dword_4c6bc4;
                                                                    if (*dword_4c6bc4 > 0xffffffff) {
                                                                            esi = *dword_4c6bc4;
                                                                            if (edx == *dword_4c6bc4) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    eax = *dword_4c6bc8;
                                                                                    ecx = *dword_4c6bcc;
                                                                                    esi = esi | 0xffffffff;
                                                                                    *dword_4c6bc4 = esi;
                                                                                    if (eax > 0xffffffff) {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                            esi = eax;
                                                                                            eax = eax | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            if (ecx > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = ecx;
                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    *dword_4c6bcc = ecx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                            }
                                                            else {
                                                                    esi = *dword_4c6bc4;
                                                                    ecx = *dword_4c6bcc;
                                                                    eax = *dword_4c6bc8;
                                                            }
                                                            if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff && decomp_var_a4 == esi) {
                                                                    *dword_4c6bc4 = 0xffffffff;
                                                                    if (eax > 0xffffffff) {
                                                                            *dword_4c6bc4 = eax;
                                                                            eax = eax | 0xffffffff;
                                                                            *dword_4c6bc8 = eax;
                                                                            if (ecx > 0xffffffff) {
                                                                                    eax = ecx;
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_a4 == decomp_var_9c) {
                                                                    if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                            eax = eax | 0xffffffff;
                                                                            *dword_4c6bc8 = eax;
                                                                    }
                                                            }
                                                            edx = decomp_var_9c;
                                                            if (decomp_var_a0 == edx && eax > 0xffffffff && decomp_var_a4 == eax) {
                                                                    *dword_4c6bc8 = 0xffffffff;
                                                                    if (ecx > 0xffffffff) {
                                                                            *dword_4c6bc8 = ecx;
                                                                            ecx = ecx | 0xffffffff;
                                                                            *dword_4c6bcc = ecx;
                                                                    }
                                                            }
                                                            eax = edx;
                                                            edx = decomp_var_a4;
                                                            if (edx == eax) {
                                                                    if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                            ecx = ecx | 0xffffffff;
                                                                            *dword_4c6bcc = ecx;
                                                                    }
                                                            }
                                                            if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                    if (edx == ecx) {
                                                                            *dword_4c6bcc = 0xffffffff;
                                                                    }
                                                            }
                                                            eax = ebx[0x2];
                                                            bool_65 = decomp_var_a0 + 0x1 < eax[0x901];
                                                            decomp_var_a0 = decomp_var_a0 + 0x1;
                                                            if (bool_65) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ecx = esi[0x1];
                                                    edx = *eax;
                                                    edx = *edx;
                                                    esp = esp - 0x8;
                                                    edi = (edx)(ecx, 0x1);
                                                    if (edi != 0x0) {
                                                            edi[0x1] = esi[0x1];
                                                            eax = esi[0x1];
                                                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                            esp = (esp - 0x10) + 0x10;
                                                            esp = esp - 0x8;
                                                            eax = sub_419e60(&decomp_var_38, &decomp_var_7c, decomp_var_c0);
                                                            eax = edi + 0x10 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    (*(**eax + 0x4))(eax);
                                                            }
                                                            ebx = decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2;
                                                            ebp = *(ebx[0x2edbcb] + 0x4);
                                                            esi = ebx + 0xbb6f28;
                                                            edi = ebp;
                                                            if (arg_d == 0x0) {
                                                                    sub_401950(edi[0x2]);
                                                                    edi = *edi;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x8) + 0x4;
                                                                    ebp = edi;
                                                                    if (edi[0x11] == 0x0) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            eax = esi[0x1];
                                                            eax[0x1] = eax;
                                                            eax = esi[0x1];
                                                            esi[0x2] = 0x0;
                                                            *eax = eax;
                                                            esi = esi[0x1];
                                                            esi[0x2] = esi;
                                                            ebp = *(ebx[0x2edc0b] + 0x4);
                                                            edi = ebx + 0xbb7028;
                                                            esi = ebp;
                                                            if (arg_d == 0x0) {
                                                                    sub_401950(esi[0x2]);
                                                                    esi = *esi;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x8) + 0x4;
                                                                    ebp = esi;
                                                                    if (esi[0x11] == 0x0) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            eax = edi[0x1];
                                                            ebx = decomp_var_98;
                                                            esi = decomp_var_a4;
                                                            eax[0x1] = eax;
                                                            eax = edi[0x1];
                                                            edi[0x2] = 0x0;
                                                            *eax = eax;
                                                            edi = edi[0x1];
                                                            eax = decomp_var_94;
                                                            edi[0x2] = edi;
                                                            edx = decomp_var_a0;
                                                            if (decomp_var_9c == edx) {
                                                                    ebx = decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2;
                                                                    esi = ebx + 0xbb6f28;
                                                                    if (arg_d == 0x0) {
                                                                            sub_42d850();
                                                                    }
                                                                    eax = esi[0x1];
                                                                    eax[0x1] = eax;
                                                                    eax = esi[0x1];
                                                                    esi[0x2] = 0x0;
                                                                    *eax = eax;
                                                                    esi = esi[0x1];
                                                                    esi[0x2] = esi;
                                                                    ebp = *(ebx[0x2edc0b] + 0x4);
                                                                    edi = ebx + 0xbb7028;
                                                                    esi = ebp;
                                                                    if (arg_d == 0x0) {
                                                                            do {
                                                                                    sub_401950(esi[0x2]);
                                                                                    esi = *esi;
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x8) + 0x4;
                                                                                    ebp = esi;
                                                                            } while (esi[0x11] == 0x0);
                                                                    }
                                                                    eax = edi[0x1];
                                                                    ebx = decomp_var_98;
                                                                    esi = decomp_var_a4;
                                                                    eax[0x1] = eax;
                                                                    eax = edi[0x1];
                                                                    edi[0x2] = 0x0;
                                                                    *eax = eax;
                                                                    edi = edi[0x1];
                                                                    eax = decomp_var_94;
                                                                    edi[0x2] = edi;
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                            edx = decomp_var_a0;
                                                                    }
                                                                    else {
                                                                            edx = decomp_var_a0;
                                                                            *(eax * 0x4 + 0x62c580) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                                    }
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cd0 != ecx && *(int16_t *)word_4c6cd4 != ecx) {
                                                                            if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                                    *(eax * 0x8 + 0x4d5528) = 0x0;
                                                                    *(eax * 0x8 + 0x4d552c) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                                    if (esi == decomp_var_9c) {
                                                                            if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                                    *(int8_t *)byte_baed44 = 0x0;
                                                                            }
                                                                            esi = *dword_4c6bc4;
                                                                            if (*dword_4c6bc4 > 0xffffffff) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    if (edx == *dword_4c6bc4) {
                                                                                            esi = *dword_4c6bc4;
                                                                                            eax = *dword_4c6bc8;
                                                                                            ecx = *dword_4c6bcc;
                                                                                            esi = esi | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            if (eax > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = *dword_4c6bc8;
                                                                                                    esi = eax;
                                                                                                    eax = eax | 0xffffffff;
                                                                                                    *dword_4c6bc4 = esi;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    if (ecx > 0xffffffff) {
                                                                                                            ecx = *dword_4c6bcc;
                                                                                                            eax = ecx;
                                                                                                            ecx = ecx | 0xffffffff;
                                                                                                            *dword_4c6bc8 = eax;
                                                                                                            *dword_4c6bcc = ecx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi = *dword_4c6bc4;
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                                    if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff && decomp_var_a4 == esi) {
                                                                            *dword_4c6bc4 = 0xffffffff;
                                                                            if (eax > 0xffffffff) {
                                                                                    *dword_4c6bc4 = eax;
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                                    if (ecx > 0xffffffff) {
                                                                                            eax = ecx;
                                                                                            ecx = ecx | 0xffffffff;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            *dword_4c6bcc = ecx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    if (decomp_var_a4 == decomp_var_9c) {
                                                                            if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                            }
                                                                    }
                                                                    edx = decomp_var_9c;
                                                                    if (decomp_var_a0 == edx && eax > 0xffffffff && decomp_var_a4 == eax) {
                                                                            *dword_4c6bc8 = 0xffffffff;
                                                                            if (ecx > 0xffffffff) {
                                                                                    *dword_4c6bc8 = ecx;
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                                    eax = edx;
                                                                    edx = decomp_var_a4;
                                                                    if (edx == eax) {
                                                                            if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                                    if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                            if (edx == ecx) {
                                                                                    *dword_4c6bcc = 0xffffffff;
                                                                            }
                                                                    }
                                                                    eax = ebx[0x2];
                                                                    bool_383 = decomp_var_a0 + 0x1 < eax[0x901];
                                                                    decomp_var_a0 = decomp_var_a0 + 0x1;
                                                                    if (bool_383) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                            edx = decomp_var_a0;
                                                                    }
                                                                    else {
                                                                            edx = decomp_var_a0;
                                                                            *(eax * 0x4 + 0x62c580) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                                    }
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cd0 != ecx && *(int16_t *)word_4c6cd4 != ecx) {
                                                                            if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                                    *(eax * 0x8 + 0x4d5528) = 0x0;
                                                                    *(eax * 0x8 + 0x4d552c) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                                    if (esi == decomp_var_9c) {
                                                                            if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                                    *(int8_t *)byte_baed44 = 0x0;
                                                                            }
                                                                            esi = *dword_4c6bc4;
                                                                            if (*dword_4c6bc4 > 0xffffffff) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    if (edx == *dword_4c6bc4) {
                                                                                            esi = *dword_4c6bc4;
                                                                                            eax = *dword_4c6bc8;
                                                                                            ecx = *dword_4c6bcc;
                                                                                            esi = esi | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            if (eax > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = *dword_4c6bc8;
                                                                                                    esi = eax;
                                                                                                    eax = eax | 0xffffffff;
                                                                                                    *dword_4c6bc4 = esi;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    if (ecx > 0xffffffff) {
                                                                                                            ecx = *dword_4c6bcc;
                                                                                                            eax = ecx;
                                                                                                            ecx = ecx | 0xffffffff;
                                                                                                            *dword_4c6bc8 = eax;
                                                                                                            *dword_4c6bcc = ecx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi = *dword_4c6bc4;
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                                    if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff && decomp_var_a4 == esi) {
                                                                            *dword_4c6bc4 = 0xffffffff;
                                                                            if (eax > 0xffffffff) {
                                                                                    *dword_4c6bc4 = eax;
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                                    if (ecx > 0xffffffff) {
                                                                                            eax = ecx;
                                                                                            ecx = ecx | 0xffffffff;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            *dword_4c6bcc = ecx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    if (decomp_var_a4 == decomp_var_9c) {
                                                                            if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                            }
                                                                    }
                                                                    edx = decomp_var_9c;
                                                                    if (decomp_var_a0 == edx && eax > 0xffffffff && decomp_var_a4 == eax) {
                                                                            *dword_4c6bc8 = 0xffffffff;
                                                                            if (ecx > 0xffffffff) {
                                                                                    *dword_4c6bc8 = ecx;
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                                    eax = edx;
                                                                    edx = decomp_var_a4;
                                                                    if (edx == eax) {
                                                                            if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                                    if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                            if (edx == ecx) {
                                                                                    *dword_4c6bcc = 0xffffffff;
                                                                            }
                                                                    }
                                                                    eax = ebx[0x2];
                                                                    bool_656 = decomp_var_a0 + 0x1 < eax[0x901];
                                                                    decomp_var_a0 = decomp_var_a0 + 0x1;
                                                                    if (bool_656) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            ecx = esi[0x1];
                                            edx = *eax;
                                            edx = *edx;
                                            esp = esp - 0x8;
                                            edi = (edx)(ecx, 0x1);
                                            if (edi != 0x0) {
                                                    edi[0x1] = esi[0x1];
                                                    eax = esi[0x1];
                                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                    esp = (esp - 0x10) + 0x10;
                                                    esp = esp - 0x8;
                                                    eax = sub_419e60(&decomp_var_38, &decomp_var_7c, decomp_var_c0);
                                                    eax = edi + 0x10 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    ebx = decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2;
                                                    ebp = *(ebx[0x2edbcb] + 0x4);
                                                    esi = ebx + 0xbb6f28;
                                                    edi = ebp;
                                                    if (arg_d == 0x0) {
                                                            sub_401950(edi[0x2]);
                                                            edi = *edi;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x8) + 0x4;
                                                            ebp = edi;
                                                            if (edi[0x11] == 0x0) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    eax = esi[0x1];
                                                    eax[0x1] = eax;
                                                    eax = esi[0x1];
                                                    esi[0x2] = 0x0;
                                                    *eax = eax;
                                                    esi = esi[0x1];
                                                    esi[0x2] = esi;
                                                    ebp = *(ebx[0x2edc0b] + 0x4);
                                                    edi = ebx + 0xbb7028;
                                                    esi = ebp;
                                                    if (arg_d == 0x0) {
                                                            sub_401950(esi[0x2]);
                                                            esi = *esi;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x8) + 0x4;
                                                            ebp = esi;
                                                            if (esi[0x11] == 0x0) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    eax = edi[0x1];
                                                    ebx = decomp_var_98;
                                                    esi = decomp_var_a4;
                                                    eax[0x1] = eax;
                                                    eax = edi[0x1];
                                                    edi[0x2] = 0x0;
                                                    *eax = eax;
                                                    edi = edi[0x1];
                                                    eax = decomp_var_94;
                                                    edi[0x2] = edi;
                                                    edx = decomp_var_a0;
                                                    if (decomp_var_9c == edx) {
                                                            ebx = decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2;
                                                            esi = ebx + 0xbb6f28;
                                                            if (arg_d == 0x0) {
                                                                    sub_42d850();
                                                            }
                                                            eax = esi[0x1];
                                                            eax[0x1] = eax;
                                                            eax = esi[0x1];
                                                            esi[0x2] = 0x0;
                                                            *eax = eax;
                                                            esi = esi[0x1];
                                                            esi[0x2] = esi;
                                                            ebp = *(ebx[0x2edc0b] + 0x4);
                                                            edi = ebx + 0xbb7028;
                                                            esi = ebp;
                                                            if (arg_d == 0x0) {
                                                                    do {
                                                                            sub_401950(esi[0x2]);
                                                                            esi = *esi;
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x8) + 0x4;
                                                                            ebp = esi;
                                                                    } while (esi[0x11] == 0x0);
                                                            }
                                                            eax = edi[0x1];
                                                            ebx = decomp_var_98;
                                                            esi = decomp_var_a4;
                                                            eax[0x1] = eax;
                                                            eax = edi[0x1];
                                                            edi[0x2] = 0x0;
                                                            *eax = eax;
                                                            edi = edi[0x1];
                                                            eax = decomp_var_94;
                                                            edi[0x2] = edi;
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                    edx = decomp_var_a0;
                                                            }
                                                            else {
                                                                    edx = decomp_var_a0;
                                                                    *(eax * 0x4 + 0x62c580) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                            }
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cd0 != ecx && *(int16_t *)word_4c6cd4 != ecx) {
                                                                    if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                            }
                                                            else {
                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                            }
                                                            *(eax * 0x8 + 0x4d5528) = 0x0;
                                                            *(eax * 0x8 + 0x4d552c) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                            if (esi == decomp_var_9c) {
                                                                    if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                            *(int8_t *)byte_baed44 = 0x0;
                                                                    }
                                                                    esi = *dword_4c6bc4;
                                                                    if (*dword_4c6bc4 > 0xffffffff) {
                                                                            esi = *dword_4c6bc4;
                                                                            if (edx == *dword_4c6bc4) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    eax = *dword_4c6bc8;
                                                                                    ecx = *dword_4c6bcc;
                                                                                    esi = esi | 0xffffffff;
                                                                                    *dword_4c6bc4 = esi;
                                                                                    if (eax > 0xffffffff) {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                            esi = eax;
                                                                                            eax = eax | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            if (ecx > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = ecx;
                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    *dword_4c6bcc = ecx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                            }
                                                            else {
                                                                    esi = *dword_4c6bc4;
                                                                    ecx = *dword_4c6bcc;
                                                                    eax = *dword_4c6bc8;
                                                            }
                                                            if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff && decomp_var_a4 == esi) {
                                                                    *dword_4c6bc4 = 0xffffffff;
                                                                    if (eax > 0xffffffff) {
                                                                            *dword_4c6bc4 = eax;
                                                                            eax = eax | 0xffffffff;
                                                                            *dword_4c6bc8 = eax;
                                                                            if (ecx > 0xffffffff) {
                                                                                    eax = ecx;
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_a4 == decomp_var_9c) {
                                                                    if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                            eax = eax | 0xffffffff;
                                                                            *dword_4c6bc8 = eax;
                                                                    }
                                                            }
                                                            edx = decomp_var_9c;
                                                            if (decomp_var_a0 == edx && eax > 0xffffffff && decomp_var_a4 == eax) {
                                                                    *dword_4c6bc8 = 0xffffffff;
                                                                    if (ecx > 0xffffffff) {
                                                                            *dword_4c6bc8 = ecx;
                                                                            ecx = ecx | 0xffffffff;
                                                                            *dword_4c6bcc = ecx;
                                                                    }
                                                            }
                                                            eax = edx;
                                                            edx = decomp_var_a4;
                                                            if (edx == eax) {
                                                                    if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                            ecx = ecx | 0xffffffff;
                                                                            *dword_4c6bcc = ecx;
                                                                    }
                                                            }
                                                            if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                    if (edx == ecx) {
                                                                            *dword_4c6bcc = 0xffffffff;
                                                                    }
                                                            }
                                                            eax = ebx[0x2];
                                                            bool_257 = decomp_var_a0 + 0x1 < eax[0x901];
                                                            decomp_var_a0 = decomp_var_a0 + 0x1;
                                                            if (bool_257) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                                    else {
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                    edx = decomp_var_a0;
                                                            }
                                                            else {
                                                                    edx = decomp_var_a0;
                                                                    *(eax * 0x4 + 0x62c580) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                            }
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cd0 != ecx && *(int16_t *)word_4c6cd4 != ecx) {
                                                                    if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                            }
                                                            else {
                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                            }
                                                            *(eax * 0x8 + 0x4d5528) = 0x0;
                                                            *(eax * 0x8 + 0x4d552c) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                            if (esi == decomp_var_9c) {
                                                                    if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                            *(int8_t *)byte_baed44 = 0x0;
                                                                    }
                                                                    esi = *dword_4c6bc4;
                                                                    if (*dword_4c6bc4 > 0xffffffff) {
                                                                            esi = *dword_4c6bc4;
                                                                            if (edx == *dword_4c6bc4) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    eax = *dword_4c6bc8;
                                                                                    ecx = *dword_4c6bcc;
                                                                                    esi = esi | 0xffffffff;
                                                                                    *dword_4c6bc4 = esi;
                                                                                    if (eax > 0xffffffff) {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                            esi = eax;
                                                                                            eax = eax | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            if (ecx > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = ecx;
                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    *dword_4c6bcc = ecx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                            }
                                                            else {
                                                                    esi = *dword_4c6bc4;
                                                                    ecx = *dword_4c6bcc;
                                                                    eax = *dword_4c6bc8;
                                                            }
                                                            if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff && decomp_var_a4 == esi) {
                                                                    *dword_4c6bc4 = 0xffffffff;
                                                                    if (eax > 0xffffffff) {
                                                                            *dword_4c6bc4 = eax;
                                                                            eax = eax | 0xffffffff;
                                                                            *dword_4c6bc8 = eax;
                                                                            if (ecx > 0xffffffff) {
                                                                                    eax = ecx;
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_a4 == decomp_var_9c) {
                                                                    if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                            eax = eax | 0xffffffff;
                                                                            *dword_4c6bc8 = eax;
                                                                    }
                                                            }
                                                            edx = decomp_var_9c;
                                                            if (decomp_var_a0 == edx && eax > 0xffffffff && decomp_var_a4 == eax) {
                                                                    *dword_4c6bc8 = 0xffffffff;
                                                                    if (ecx > 0xffffffff) {
                                                                            *dword_4c6bc8 = ecx;
                                                                            ecx = ecx | 0xffffffff;
                                                                            *dword_4c6bcc = ecx;
                                                                    }
                                                            }
                                                            eax = edx;
                                                            edx = decomp_var_a4;
                                                            if (edx == eax) {
                                                                    if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                            ecx = ecx | 0xffffffff;
                                                                            *dword_4c6bcc = ecx;
                                                                    }
                                                            }
                                                            if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                    if (edx == ecx) {
                                                                            *dword_4c6bcc = 0xffffffff;
                                                                    }
                                                            }
                                                            eax = ebx[0x2];
                                                            bool_641 = decomp_var_a0 + 0x1 < eax[0x901];
                                                            decomp_var_a0 = decomp_var_a0 + 0x1;
                                                            if (bool_641) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    ecx = esi[0x1];
                                    edx = *eax;
                                    edx = *edx;
                                    decomp_var_bc = 0x1;
                                    esp = esp - 0x8;
                                    decomp_var_c0 = ecx;
                                    edi = (edx)(decomp_var_c0, 0x1);
                                    if (edi != 0x0) {
                                            edi[0x1] = esi[0x1];
                                            eax = esi[0x1];
                                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                            esp = (esp - 0x10) + 0x10;
                                            esp = esp - 0x8;
                                            eax = sub_419e60(&decomp_var_3c, &decomp_var_7c, decomp_var_b8);
                                            eax = edi + 0x10 - 0x10;
                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                            if (edx <= 0x1) {
                                                    esp = esp - 0x4;
                                                    (*(**eax + 0x4))(eax);
                                            }
                                            decomp_var_bc = "Enemy desired because of stab";
                                            decomp_var_c0 = &decomp_var_88;
                                            *(int8_t *)byte_baed5f = 0x1;
                                            sub_410c10(decomp_var_c0, "Enemy desired because of stab", decomp_var_b8);
                                            edx = **(decomp_var_88 - 0x10);
                                            eax = edx[0x4];
                                            esi = decomp_var_88 - 0x10;
                                            esp = (esp - 0x8) + 0x8;
                                            eax = (eax)();
                                            ecx = esi + 0xc;
                                            if (esi[0x3] >= 0x0) {
                                                    if (eax == *esi) {
                                                            edi = esi;
                                                            *ecx = lock intrinsic_xadd(*ecx, 0x1);
                                                            esp = esp - 0x8;
                                                            eax = sub_419e60(&decomp_var_38, &decomp_var_7c, decomp_var_c0);
                                                            eax = edi + 0x10 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    (*(**eax + 0x4))(eax);
                                                            }
                                                            ebx = decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2;
                                                            ebp = *(ebx[0x2edbcb] + 0x4);
                                                            esi = ebx + 0xbb6f28;
                                                            edi = ebp;
                                                            if (arg_d == 0x0) {
                                                                    sub_401950(edi[0x2]);
                                                                    edi = *edi;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x8) + 0x4;
                                                                    ebp = edi;
                                                                    if (edi[0x11] == 0x0) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            eax = esi[0x1];
                                                            eax[0x1] = eax;
                                                            eax = esi[0x1];
                                                            esi[0x2] = 0x0;
                                                            *eax = eax;
                                                            esi = esi[0x1];
                                                            esi[0x2] = esi;
                                                            ebp = *(ebx[0x2edc0b] + 0x4);
                                                            edi = ebx + 0xbb7028;
                                                            esi = ebp;
                                                            if (arg_d == 0x0) {
                                                                    sub_401950(esi[0x2]);
                                                                    esi = *esi;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x8) + 0x4;
                                                                    ebp = esi;
                                                                    if (esi[0x11] == 0x0) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            eax = edi[0x1];
                                                            ebx = decomp_var_98;
                                                            esi = decomp_var_a4;
                                                            eax[0x1] = eax;
                                                            eax = edi[0x1];
                                                            edi[0x2] = 0x0;
                                                            *eax = eax;
                                                            edi = edi[0x1];
                                                            eax = decomp_var_94;
                                                            edi[0x2] = edi;
                                                            edx = decomp_var_a0;
                                                            if (decomp_var_9c == edx) {
                                                                    ebx = decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2;
                                                                    esi = ebx + 0xbb6f28;
                                                                    if (arg_d == 0x0) {
                                                                            sub_42d850();
                                                                    }
                                                                    eax = esi[0x1];
                                                                    eax[0x1] = eax;
                                                                    eax = esi[0x1];
                                                                    esi[0x2] = 0x0;
                                                                    *eax = eax;
                                                                    esi = esi[0x1];
                                                                    esi[0x2] = esi;
                                                                    ebp = *(ebx[0x2edc0b] + 0x4);
                                                                    edi = ebx + 0xbb7028;
                                                                    esi = ebp;
                                                                    if (arg_d == 0x0) {
                                                                            do {
                                                                                    sub_401950(esi[0x2]);
                                                                                    esi = *esi;
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x8) + 0x4;
                                                                                    ebp = esi;
                                                                            } while (esi[0x11] == 0x0);
                                                                    }
                                                                    eax = edi[0x1];
                                                                    ebx = decomp_var_98;
                                                                    esi = decomp_var_a4;
                                                                    eax[0x1] = eax;
                                                                    eax = edi[0x1];
                                                                    edi[0x2] = 0x0;
                                                                    *eax = eax;
                                                                    edi = edi[0x1];
                                                                    eax = decomp_var_94;
                                                                    edi[0x2] = edi;
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                            edx = decomp_var_a0;
                                                                    }
                                                                    else {
                                                                            edx = decomp_var_a0;
                                                                            *(eax * 0x4 + 0x62c580) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                                    }
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cd0 != ecx && *(int16_t *)word_4c6cd4 != ecx) {
                                                                            if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                                    *(eax * 0x8 + 0x4d5528) = 0x0;
                                                                    *(eax * 0x8 + 0x4d552c) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                                    if (esi == decomp_var_9c) {
                                                                            if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                                    *(int8_t *)byte_baed44 = 0x0;
                                                                            }
                                                                            esi = *dword_4c6bc4;
                                                                            if (*dword_4c6bc4 > 0xffffffff) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    if (edx == *dword_4c6bc4) {
                                                                                            esi = *dword_4c6bc4;
                                                                                            eax = *dword_4c6bc8;
                                                                                            ecx = *dword_4c6bcc;
                                                                                            esi = esi | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            if (eax > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = *dword_4c6bc8;
                                                                                                    esi = eax;
                                                                                                    eax = eax | 0xffffffff;
                                                                                                    *dword_4c6bc4 = esi;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    if (ecx > 0xffffffff) {
                                                                                                            ecx = *dword_4c6bcc;
                                                                                                            eax = ecx;
                                                                                                            ecx = ecx | 0xffffffff;
                                                                                                            *dword_4c6bc8 = eax;
                                                                                                            *dword_4c6bcc = ecx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi = *dword_4c6bc4;
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                                    if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff && decomp_var_a4 == esi) {
                                                                            *dword_4c6bc4 = 0xffffffff;
                                                                            if (eax > 0xffffffff) {
                                                                                    *dword_4c6bc4 = eax;
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                                    if (ecx > 0xffffffff) {
                                                                                            eax = ecx;
                                                                                            ecx = ecx | 0xffffffff;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            *dword_4c6bcc = ecx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    if (decomp_var_a4 == decomp_var_9c) {
                                                                            if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                            }
                                                                    }
                                                                    edx = decomp_var_9c;
                                                                    if (decomp_var_a0 == edx && eax > 0xffffffff && decomp_var_a4 == eax) {
                                                                            *dword_4c6bc8 = 0xffffffff;
                                                                            if (ecx > 0xffffffff) {
                                                                                    *dword_4c6bc8 = ecx;
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                                    eax = edx;
                                                                    edx = decomp_var_a4;
                                                                    if (edx == eax) {
                                                                            if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                                    if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                            if (edx == ecx) {
                                                                                    *dword_4c6bcc = 0xffffffff;
                                                                            }
                                                                    }
                                                                    eax = ebx[0x2];
                                                                    bool_674 = decomp_var_a0 + 0x1 < eax[0x901];
                                                                    decomp_var_a0 = decomp_var_a0 + 0x1;
                                                                    if (bool_674) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                            edx = decomp_var_a0;
                                                                    }
                                                                    else {
                                                                            edx = decomp_var_a0;
                                                                            *(eax * 0x4 + 0x62c580) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                                    }
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cd0 != ecx && *(int16_t *)word_4c6cd4 != ecx) {
                                                                            if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                                    *(eax * 0x8 + 0x4d5528) = 0x0;
                                                                    *(eax * 0x8 + 0x4d552c) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                                    if (esi == decomp_var_9c) {
                                                                            if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                                    *(int8_t *)byte_baed44 = 0x0;
                                                                            }
                                                                            esi = *dword_4c6bc4;
                                                                            if (*dword_4c6bc4 > 0xffffffff) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    if (edx == *dword_4c6bc4) {
                                                                                            esi = *dword_4c6bc4;
                                                                                            eax = *dword_4c6bc8;
                                                                                            ecx = *dword_4c6bcc;
                                                                                            esi = esi | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            if (eax > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = *dword_4c6bc8;
                                                                                                    esi = eax;
                                                                                                    eax = eax | 0xffffffff;
                                                                                                    *dword_4c6bc4 = esi;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    if (ecx > 0xffffffff) {
                                                                                                            ecx = *dword_4c6bcc;
                                                                                                            eax = ecx;
                                                                                                            ecx = ecx | 0xffffffff;
                                                                                                            *dword_4c6bc8 = eax;
                                                                                                            *dword_4c6bcc = ecx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi = *dword_4c6bc4;
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                                    if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff && decomp_var_a4 == esi) {
                                                                            *dword_4c6bc4 = 0xffffffff;
                                                                            if (eax > 0xffffffff) {
                                                                                    *dword_4c6bc4 = eax;
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                                    if (ecx > 0xffffffff) {
                                                                                            eax = ecx;
                                                                                            ecx = ecx | 0xffffffff;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            *dword_4c6bcc = ecx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    if (decomp_var_a4 == decomp_var_9c) {
                                                                            if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                            }
                                                                    }
                                                                    edx = decomp_var_9c;
                                                                    if (decomp_var_a0 == edx && eax > 0xffffffff && decomp_var_a4 == eax) {
                                                                            *dword_4c6bc8 = 0xffffffff;
                                                                            if (ecx > 0xffffffff) {
                                                                                    *dword_4c6bc8 = ecx;
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                                    eax = edx;
                                                                    edx = decomp_var_a4;
                                                                    if (edx == eax) {
                                                                            if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                                    if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                            if (edx == ecx) {
                                                                                    *dword_4c6bcc = 0xffffffff;
                                                                            }
                                                                    }
                                                                    eax = ebx[0x2];
                                                                    bool_123 = decomp_var_a0 + 0x1 < eax[0x901];
                                                                    decomp_var_a0 = decomp_var_a0 + 0x1;
                                                                    if (bool_123) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = esi[0x1];
                                                            edx = *eax;
                                                            edx = *edx;
                                                            esp = esp - 0x8;
                                                            edi = (edx)(ecx, 0x1);
                                                            if (edi != 0x0) {
                                                                    edi[0x1] = esi[0x1];
                                                                    eax = esi[0x1];
                                                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                                    esp = (esp - 0x10) + 0x10;
                                                                    esp = esp - 0x8;
                                                                    eax = sub_419e60(&decomp_var_38, &decomp_var_7c, decomp_var_c0);
                                                                    eax = edi + 0x10 - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            (*(**eax + 0x4))(eax);
                                                                    }
                                                                    ebx = decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2;
                                                                    ebp = *(ebx[0x2edbcb] + 0x4);
                                                                    esi = ebx + 0xbb6f28;
                                                                    edi = ebp;
                                                                    if (arg_d == 0x0) {
                                                                            sub_401950(edi[0x2]);
                                                                            edi = *edi;
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x8) + 0x4;
                                                                            ebp = edi;
                                                                            if (edi[0x11] == 0x0) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    eax = esi[0x1];
                                                                    eax[0x1] = eax;
                                                                    eax = esi[0x1];
                                                                    esi[0x2] = 0x0;
                                                                    *eax = eax;
                                                                    esi = esi[0x1];
                                                                    esi[0x2] = esi;
                                                                    ebp = *(ebx[0x2edc0b] + 0x4);
                                                                    edi = ebx + 0xbb7028;
                                                                    esi = ebp;
                                                                    if (arg_d == 0x0) {
                                                                            sub_401950(esi[0x2]);
                                                                            esi = *esi;
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x8) + 0x4;
                                                                            ebp = esi;
                                                                            if (esi[0x11] == 0x0) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    eax = edi[0x1];
                                                                    ebx = decomp_var_98;
                                                                    esi = decomp_var_a4;
                                                                    eax[0x1] = eax;
                                                                    eax = edi[0x1];
                                                                    edi[0x2] = 0x0;
                                                                    *eax = eax;
                                                                    edi = edi[0x1];
                                                                    eax = decomp_var_94;
                                                                    edi[0x2] = edi;
                                                                    edx = decomp_var_a0;
                                                                    if (decomp_var_9c == edx) {
                                                                            ebx = decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2;
                                                                            esi = ebx + 0xbb6f28;
                                                                            if (arg_d == 0x0) {
                                                                                    sub_42d850();
                                                                            }
                                                                            eax = esi[0x1];
                                                                            eax[0x1] = eax;
                                                                            eax = esi[0x1];
                                                                            esi[0x2] = 0x0;
                                                                            *eax = eax;
                                                                            esi = esi[0x1];
                                                                            esi[0x2] = esi;
                                                                            ebp = *(ebx[0x2edc0b] + 0x4);
                                                                            edi = ebx + 0xbb7028;
                                                                            esi = ebp;
                                                                            if (arg_d == 0x0) {
                                                                                    do {
                                                                                            sub_401950(esi[0x2]);
                                                                                            esi = *esi;
                                                                                            sub_47c8f9();
                                                                                            esp = (esp - 0x8) + 0x4;
                                                                                            ebp = esi;
                                                                                    } while (esi[0x11] == 0x0);
                                                                            }
                                                                            eax = edi[0x1];
                                                                            ebx = decomp_var_98;
                                                                            esi = decomp_var_a4;
                                                                            eax[0x1] = eax;
                                                                            eax = edi[0x1];
                                                                            edi[0x2] = 0x0;
                                                                            *eax = eax;
                                                                            edi = edi[0x1];
                                                                            eax = decomp_var_94;
                                                                            edi[0x2] = edi;
                                                                            ecx = ebx[0x2];
                                                                            ecx = ecx[0x1225] & 0xffff;
                                                                            if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                                    edx = decomp_var_a0;
                                                                            }
                                                                            else {
                                                                                    edx = decomp_var_a0;
                                                                                    *(eax * 0x4 + 0x62c580) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                                            }
                                                                            ecx = ebx[0x2];
                                                                            ecx = ecx[0x1225] & 0xffff;
                                                                            if (*(int16_t *)word_4c6cd0 != ecx) {
                                                                                    if (*(int16_t *)word_4c6cd4 != ecx) {
                                                                                            if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                            }
                                                                            *(eax * 0x8 + 0x4d5528) = 0x0;
                                                                            *(eax * 0x8 + 0x4d552c) = 0x0;
                                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                                            if (esi == decomp_var_9c) {
                                                                                    if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                                            *(int8_t *)byte_baed44 = 0x0;
                                                                                    }
                                                                                    esi = *dword_4c6bc4;
                                                                                    if (*dword_4c6bc4 > 0xffffffff) {
                                                                                            esi = *dword_4c6bc4;
                                                                                            if (edx == *dword_4c6bc4) {
                                                                                                    esi = *dword_4c6bc4;
                                                                                                    eax = *dword_4c6bc8;
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    esi = esi | 0xffffffff;
                                                                                                    *dword_4c6bc4 = esi;
                                                                                                    if (eax > 0xffffffff) {
                                                                                                            ecx = *dword_4c6bcc;
                                                                                                            eax = *dword_4c6bc8;
                                                                                                            esi = eax;
                                                                                                            eax = eax | 0xffffffff;
                                                                                                            *dword_4c6bc4 = esi;
                                                                                                            *dword_4c6bc8 = eax;
                                                                                                            if (ecx > 0xffffffff) {
                                                                                                                    ecx = *dword_4c6bcc;
                                                                                                                    eax = ecx;
                                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                                    *dword_4c6bc8 = eax;
                                                                                                                    *dword_4c6bcc = ecx;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = *dword_4c6bc8;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esi = *dword_4c6bc4;
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                            if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff) {
                                                                                    if (decomp_var_a4 == esi) {
                                                                                            *dword_4c6bc4 = 0xffffffff;
                                                                                            if (eax > 0xffffffff) {
                                                                                                    *dword_4c6bc4 = eax;
                                                                                                    eax = eax | 0xffffffff;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    if (ecx > 0xffffffff) {
                                                                                                            eax = ecx;
                                                                                                            ecx = ecx | 0xffffffff;
                                                                                                            *dword_4c6bc8 = eax;
                                                                                                            *dword_4c6bcc = ecx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                            if (decomp_var_a4 == decomp_var_9c) {
                                                                                    if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                                            eax = eax | 0xffffffff;
                                                                                            *dword_4c6bc8 = eax;
                                                                                    }
                                                                            }
                                                                            edx = decomp_var_9c;
                                                                            if (decomp_var_a0 == edx && eax > 0xffffffff) {
                                                                                    if (decomp_var_a4 == eax) {
                                                                                            *dword_4c6bc8 = 0xffffffff;
                                                                                            if (ecx > 0xffffffff) {
                                                                                                    *dword_4c6bc8 = ecx;
                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                    *dword_4c6bcc = ecx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            eax = edx;
                                                                            edx = decomp_var_a4;
                                                                            if (edx == eax) {
                                                                                    if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                                            ecx = ecx | 0xffffffff;
                                                                                            *dword_4c6bcc = ecx;
                                                                                    }
                                                                            }
                                                                            if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                                    if (edx == ecx) {
                                                                                            *dword_4c6bcc = 0xffffffff;
                                                                                    }
                                                                            }
                                                                            eax = ebx[0x2];
                                                                            bool_655 = decomp_var_a0 + 0x1 < eax[0x901];
                                                                            decomp_var_a0 = decomp_var_a0 + 0x1;
                                                                            if (bool_655) {
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x2;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = ebx[0x2];
                                                                            ecx = ecx[0x1225] & 0xffff;
                                                                            if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                                    edx = decomp_var_a0;
                                                                            }
                                                                            else {
                                                                                    edx = decomp_var_a0;
                                                                                    *(eax * 0x4 + 0x62c580) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                                            }
                                                                            ecx = ebx[0x2];
                                                                            ecx = ecx[0x1225] & 0xffff;
                                                                            if (*(int16_t *)word_4c6cd0 != ecx) {
                                                                                    if (*(int16_t *)word_4c6cd4 != ecx) {
                                                                                            if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                            }
                                                                            *(eax * 0x8 + 0x4d5528) = 0x0;
                                                                            *(eax * 0x8 + 0x4d552c) = 0x0;
                                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                                            if (esi == decomp_var_9c) {
                                                                                    if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                                            *(int8_t *)byte_baed44 = 0x0;
                                                                                    }
                                                                                    esi = *dword_4c6bc4;
                                                                                    if (*dword_4c6bc4 > 0xffffffff) {
                                                                                            esi = *dword_4c6bc4;
                                                                                            if (edx == *dword_4c6bc4) {
                                                                                                    esi = *dword_4c6bc4;
                                                                                                    eax = *dword_4c6bc8;
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    esi = esi | 0xffffffff;
                                                                                                    *dword_4c6bc4 = esi;
                                                                                                    if (eax > 0xffffffff) {
                                                                                                            ecx = *dword_4c6bcc;
                                                                                                            eax = *dword_4c6bc8;
                                                                                                            esi = eax;
                                                                                                            eax = eax | 0xffffffff;
                                                                                                            *dword_4c6bc4 = esi;
                                                                                                            *dword_4c6bc8 = eax;
                                                                                                            if (ecx > 0xffffffff) {
                                                                                                                    ecx = *dword_4c6bcc;
                                                                                                                    eax = ecx;
                                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                                    *dword_4c6bc8 = eax;
                                                                                                                    *dword_4c6bcc = ecx;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = *dword_4c6bc8;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esi = *dword_4c6bc4;
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                            if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff) {
                                                                                    if (decomp_var_a4 == esi) {
                                                                                            *dword_4c6bc4 = 0xffffffff;
                                                                                            if (eax > 0xffffffff) {
                                                                                                    *dword_4c6bc4 = eax;
                                                                                                    eax = eax | 0xffffffff;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    if (ecx > 0xffffffff) {
                                                                                                            eax = ecx;
                                                                                                            ecx = ecx | 0xffffffff;
                                                                                                            *dword_4c6bc8 = eax;
                                                                                                            *dword_4c6bcc = ecx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                            if (decomp_var_a4 == decomp_var_9c) {
                                                                                    if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                                            eax = eax | 0xffffffff;
                                                                                            *dword_4c6bc8 = eax;
                                                                                    }
                                                                            }
                                                                            edx = decomp_var_9c;
                                                                            if (decomp_var_a0 == edx && eax > 0xffffffff) {
                                                                                    if (decomp_var_a4 == eax) {
                                                                                            *dword_4c6bc8 = 0xffffffff;
                                                                                            if (ecx > 0xffffffff) {
                                                                                                    *dword_4c6bc8 = ecx;
                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                    *dword_4c6bcc = ecx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            eax = edx;
                                                                            edx = decomp_var_a4;
                                                                            if (edx == eax) {
                                                                                    if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                                            ecx = ecx | 0xffffffff;
                                                                                            *dword_4c6bcc = ecx;
                                                                                    }
                                                                            }
                                                                            if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                                    if (edx == ecx) {
                                                                                            *dword_4c6bcc = 0xffffffff;
                                                                                    }
                                                                            }
                                                                            eax = ebx[0x2];
                                                                            bool_412 = decomp_var_a0 + 0x1 < eax[0x901];
                                                                            decomp_var_a0 = decomp_var_a0 + 0x1;
                                                                            if (bool_412) {
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x2;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    ecx = esi[0x1];
                                                    edx = *eax;
                                                    edx = *edx;
                                                    esp = esp - 0x8;
                                                    edi = (edx)(ecx, 0x1);
                                                    if (edi != 0x0) {
                                                            edi[0x1] = esi[0x1];
                                                            eax = esi[0x1];
                                                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                            esp = (esp - 0x10) + 0x10;
                                                            esp = esp - 0x8;
                                                            eax = sub_419e60(&decomp_var_38, &decomp_var_7c, decomp_var_c0);
                                                            eax = edi + 0x10 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    (*(**eax + 0x4))(eax);
                                                            }
                                                            ebx = decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2;
                                                            ebp = *(ebx[0x2edbcb] + 0x4);
                                                            esi = ebx + 0xbb6f28;
                                                            edi = ebp;
                                                            if (arg_d == 0x0) {
                                                                    sub_401950(edi[0x2]);
                                                                    edi = *edi;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x8) + 0x4;
                                                                    ebp = edi;
                                                                    if (edi[0x11] == 0x0) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            eax = esi[0x1];
                                                            eax[0x1] = eax;
                                                            eax = esi[0x1];
                                                            esi[0x2] = 0x0;
                                                            *eax = eax;
                                                            esi = esi[0x1];
                                                            esi[0x2] = esi;
                                                            ebp = *(ebx[0x2edc0b] + 0x4);
                                                            edi = ebx + 0xbb7028;
                                                            esi = ebp;
                                                            if (arg_d == 0x0) {
                                                                    sub_401950(esi[0x2]);
                                                                    esi = *esi;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x8) + 0x4;
                                                                    ebp = esi;
                                                                    if (esi[0x11] == 0x0) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            eax = edi[0x1];
                                                            ebx = decomp_var_98;
                                                            esi = decomp_var_a4;
                                                            eax[0x1] = eax;
                                                            eax = edi[0x1];
                                                            edi[0x2] = 0x0;
                                                            *eax = eax;
                                                            edi = edi[0x1];
                                                            eax = decomp_var_94;
                                                            edi[0x2] = edi;
                                                            edx = decomp_var_a0;
                                                            if (decomp_var_9c == edx) {
                                                                    ebx = decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2;
                                                                    esi = ebx + 0xbb6f28;
                                                                    if (arg_d == 0x0) {
                                                                            sub_42d850();
                                                                    }
                                                                    eax = esi[0x1];
                                                                    eax[0x1] = eax;
                                                                    eax = esi[0x1];
                                                                    esi[0x2] = 0x0;
                                                                    *eax = eax;
                                                                    esi = esi[0x1];
                                                                    esi[0x2] = esi;
                                                                    ebp = *(ebx[0x2edc0b] + 0x4);
                                                                    edi = ebx + 0xbb7028;
                                                                    esi = ebp;
                                                                    if (arg_d == 0x0) {
                                                                            do {
                                                                                    sub_401950(esi[0x2]);
                                                                                    esi = *esi;
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x8) + 0x4;
                                                                                    ebp = esi;
                                                                            } while (esi[0x11] == 0x0);
                                                                    }
                                                                    eax = edi[0x1];
                                                                    ebx = decomp_var_98;
                                                                    esi = decomp_var_a4;
                                                                    eax[0x1] = eax;
                                                                    eax = edi[0x1];
                                                                    edi[0x2] = 0x0;
                                                                    *eax = eax;
                                                                    edi = edi[0x1];
                                                                    eax = decomp_var_94;
                                                                    edi[0x2] = edi;
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                            edx = decomp_var_a0;
                                                                    }
                                                                    else {
                                                                            edx = decomp_var_a0;
                                                                            *(eax * 0x4 + 0x62c580) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                                    }
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cd0 != ecx) {
                                                                            if (*(int16_t *)word_4c6cd4 != ecx) {
                                                                                    if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                                    *(eax * 0x8 + 0x4d5528) = 0x0;
                                                                    *(eax * 0x8 + 0x4d552c) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                                    if (esi == decomp_var_9c) {
                                                                            if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                                    *(int8_t *)byte_baed44 = 0x0;
                                                                            }
                                                                            esi = *dword_4c6bc4;
                                                                            if (*dword_4c6bc4 > 0xffffffff) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    if (edx == *dword_4c6bc4) {
                                                                                            esi = *dword_4c6bc4;
                                                                                            eax = *dword_4c6bc8;
                                                                                            ecx = *dword_4c6bcc;
                                                                                            esi = esi | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            if (eax > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = *dword_4c6bc8;
                                                                                                    esi = eax;
                                                                                                    eax = eax | 0xffffffff;
                                                                                                    *dword_4c6bc4 = esi;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    if (ecx > 0xffffffff) {
                                                                                                            ecx = *dword_4c6bcc;
                                                                                                            eax = ecx;
                                                                                                            ecx = ecx | 0xffffffff;
                                                                                                            *dword_4c6bc8 = eax;
                                                                                                            *dword_4c6bcc = ecx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi = *dword_4c6bc4;
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                                    if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff) {
                                                                            if (decomp_var_a4 == esi) {
                                                                                    *dword_4c6bc4 = 0xffffffff;
                                                                                    if (eax > 0xffffffff) {
                                                                                            *dword_4c6bc4 = eax;
                                                                                            eax = eax | 0xffffffff;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            if (ecx > 0xffffffff) {
                                                                                                    eax = ecx;
                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    *dword_4c6bcc = ecx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    if (decomp_var_a4 == decomp_var_9c) {
                                                                            if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                            }
                                                                    }
                                                                    edx = decomp_var_9c;
                                                                    if (decomp_var_a0 == edx && eax > 0xffffffff) {
                                                                            if (decomp_var_a4 == eax) {
                                                                                    *dword_4c6bc8 = 0xffffffff;
                                                                                    if (ecx > 0xffffffff) {
                                                                                            *dword_4c6bc8 = ecx;
                                                                                            ecx = ecx | 0xffffffff;
                                                                                            *dword_4c6bcc = ecx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    eax = edx;
                                                                    edx = decomp_var_a4;
                                                                    if (edx == eax) {
                                                                            if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                                    if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                            if (edx == ecx) {
                                                                                    *dword_4c6bcc = 0xffffffff;
                                                                            }
                                                                    }
                                                                    eax = ebx[0x2];
                                                                    bool_220 = decomp_var_a0 + 0x1 < eax[0x901];
                                                                    decomp_var_a0 = decomp_var_a0 + 0x1;
                                                                    if (bool_220) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                            edx = decomp_var_a0;
                                                                    }
                                                                    else {
                                                                            edx = decomp_var_a0;
                                                                            *(eax * 0x4 + 0x62c580) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                                    }
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cd0 != ecx) {
                                                                            if (*(int16_t *)word_4c6cd4 != ecx) {
                                                                                    if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                                    *(eax * 0x8 + 0x4d5528) = 0x0;
                                                                    *(eax * 0x8 + 0x4d552c) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                                    if (esi == decomp_var_9c) {
                                                                            if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                                    *(int8_t *)byte_baed44 = 0x0;
                                                                            }
                                                                            esi = *dword_4c6bc4;
                                                                            if (*dword_4c6bc4 > 0xffffffff) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    if (edx == *dword_4c6bc4) {
                                                                                            esi = *dword_4c6bc4;
                                                                                            eax = *dword_4c6bc8;
                                                                                            ecx = *dword_4c6bcc;
                                                                                            esi = esi | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            if (eax > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = *dword_4c6bc8;
                                                                                                    esi = eax;
                                                                                                    eax = eax | 0xffffffff;
                                                                                                    *dword_4c6bc4 = esi;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    if (ecx > 0xffffffff) {
                                                                                                            ecx = *dword_4c6bcc;
                                                                                                            eax = ecx;
                                                                                                            ecx = ecx | 0xffffffff;
                                                                                                            *dword_4c6bc8 = eax;
                                                                                                            *dword_4c6bcc = ecx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi = *dword_4c6bc4;
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                                    if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff) {
                                                                            if (decomp_var_a4 == esi) {
                                                                                    *dword_4c6bc4 = 0xffffffff;
                                                                                    if (eax > 0xffffffff) {
                                                                                            *dword_4c6bc4 = eax;
                                                                                            eax = eax | 0xffffffff;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            if (ecx > 0xffffffff) {
                                                                                                    eax = ecx;
                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    *dword_4c6bcc = ecx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    if (decomp_var_a4 == decomp_var_9c) {
                                                                            if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                            }
                                                                    }
                                                                    edx = decomp_var_9c;
                                                                    if (decomp_var_a0 == edx && eax > 0xffffffff) {
                                                                            if (decomp_var_a4 == eax) {
                                                                                    *dword_4c6bc8 = 0xffffffff;
                                                                                    if (ecx > 0xffffffff) {
                                                                                            *dword_4c6bc8 = ecx;
                                                                                            ecx = ecx | 0xffffffff;
                                                                                            *dword_4c6bcc = ecx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    eax = edx;
                                                                    edx = decomp_var_a4;
                                                                    if (edx == eax) {
                                                                            if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                                    if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                            if (edx == ecx) {
                                                                                    *dword_4c6bcc = 0xffffffff;
                                                                            }
                                                                    }
                                                                    eax = ebx[0x2];
                                                                    bool_117 = decomp_var_a0 + 0x1 < eax[0x901];
                                                                    decomp_var_a0 = decomp_var_a0 + 0x1;
                                                                    if (bool_117) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            temp_0 = 0x1;
                                            break;
                                    }
                            }
                    }
                    else {
                            ecx = esi[0x1];
                            edx = *eax;
                            edx = *edx;
                            decomp_var_bc = 0x1;
                            esp = esp - 0x8;
                            decomp_var_c0 = ecx;
                            edi = (edx)(decomp_var_c0, 0x1);
                            if (edi != 0x0) {
                                    edi[0x1] = esi[0x1];
                                    eax = esi[0x1];
                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                    esp = (esp - 0x10) + 0x10;
                                    esp = esp - 0x8;
                                    eax = sub_419e60(&decomp_var_3c, &decomp_var_7c, decomp_var_b8);
                                    eax = edi + 0x10 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            (*(**eax + 0x4))(eax);
                                    }
                                    decomp_var_bc = "Enemy desired because of stab";
                                    decomp_var_c0 = &decomp_var_88;
                                    *(int8_t *)byte_baed5f = 0x1;
                                    sub_410c10(decomp_var_c0, "Enemy desired because of stab", decomp_var_b8);
                                    edx = **(decomp_var_88 - 0x10);
                                    eax = edx[0x4];
                                    esi = decomp_var_88 - 0x10;
                                    esp = (esp - 0x8) + 0x8;
                                    eax = (eax)();
                                    ecx = esi + 0xc;
                                    if (esi[0x3] >= 0x0) {
                                            if (eax == *esi) {
                                                    edi = esi;
                                                    *ecx = lock intrinsic_xadd(*ecx, 0x1);
                                                    esp = esp - 0x8;
                                                    eax = sub_419e60(&decomp_var_38, &decomp_var_7c, decomp_var_c0);
                                                    eax = edi + 0x10 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    ebx = decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2;
                                                    ebp = *(ebx[0x2edbcb] + 0x4);
                                                    esi = ebx + 0xbb6f28;
                                                    edi = ebp;
                                                    if (arg_d == 0x0) {
                                                            sub_401950(edi[0x2]);
                                                            edi = *edi;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x8) + 0x4;
                                                            ebp = edi;
                                                            if (edi[0x11] == 0x0) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    eax = esi[0x1];
                                                    eax[0x1] = eax;
                                                    eax = esi[0x1];
                                                    esi[0x2] = 0x0;
                                                    *eax = eax;
                                                    esi = esi[0x1];
                                                    esi[0x2] = esi;
                                                    ebp = *(ebx[0x2edc0b] + 0x4);
                                                    edi = ebx + 0xbb7028;
                                                    esi = ebp;
                                                    if (arg_d == 0x0) {
                                                            do {
                                                                    sub_401950(esi[0x2]);
                                                                    esi = *esi;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x8) + 0x4;
                                                                    ebp = esi;
                                                            } while (esi[0x11] == 0x0);
                                                    }
                                                    eax = edi[0x1];
                                                    ebx = decomp_var_98;
                                                    esi = decomp_var_a4;
                                                    eax[0x1] = eax;
                                                    eax = edi[0x1];
                                                    edi[0x2] = 0x0;
                                                    *eax = eax;
                                                    edi = edi[0x1];
                                                    eax = decomp_var_94;
                                                    edi[0x2] = edi;
                                                    edx = decomp_var_a0;
                                                    if (decomp_var_9c == edx) {
                                                            ebx = decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2;
                                                            esi = ebx + 0xbb6f28;
                                                            if (arg_d == 0x0) {
                                                                    sub_42d850();
                                                            }
                                                            eax = esi[0x1];
                                                            eax[0x1] = eax;
                                                            eax = esi[0x1];
                                                            esi[0x2] = 0x0;
                                                            *eax = eax;
                                                            esi = esi[0x1];
                                                            esi[0x2] = esi;
                                                            ebp = *(ebx[0x2edc0b] + 0x4);
                                                            edi = ebx + 0xbb7028;
                                                            esi = ebp;
                                                            if (arg_d == 0x0) {
                                                                    do {
                                                                            sub_401950(esi[0x2]);
                                                                            esi = *esi;
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x8) + 0x4;
                                                                            ebp = esi;
                                                                    } while (esi[0x11] == 0x0);
                                                            }
                                                            eax = edi[0x1];
                                                            ebx = decomp_var_98;
                                                            esi = decomp_var_a4;
                                                            eax[0x1] = eax;
                                                            eax = edi[0x1];
                                                            edi[0x2] = 0x0;
                                                            *eax = eax;
                                                            edi = edi[0x1];
                                                            eax = decomp_var_94;
                                                            edi[0x2] = edi;
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                    edx = decomp_var_a0;
                                                            }
                                                            else {
                                                                    edx = decomp_var_a0;
                                                                    *(eax * 0x4 + 0x62c580) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                            }
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cd0 != ecx) {
                                                                    if (*(int16_t *)word_4c6cd4 != ecx) {
                                                                            if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                            }
                                                            else {
                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                            }
                                                            *(eax * 0x8 + 0x4d5528) = 0x0;
                                                            *(eax * 0x8 + 0x4d552c) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                            if (esi == decomp_var_9c) {
                                                                    if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                            *(int8_t *)byte_baed44 = 0x0;
                                                                    }
                                                                    esi = *dword_4c6bc4;
                                                                    if (*dword_4c6bc4 > 0xffffffff) {
                                                                            esi = *dword_4c6bc4;
                                                                            if (edx == *dword_4c6bc4) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    eax = *dword_4c6bc8;
                                                                                    ecx = *dword_4c6bcc;
                                                                                    esi = esi | 0xffffffff;
                                                                                    *dword_4c6bc4 = esi;
                                                                                    if (eax > 0xffffffff) {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                            esi = eax;
                                                                                            eax = eax | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            if (ecx > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = ecx;
                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    *dword_4c6bcc = ecx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                            }
                                                            else {
                                                                    esi = *dword_4c6bc4;
                                                                    ecx = *dword_4c6bcc;
                                                                    eax = *dword_4c6bc8;
                                                            }
                                                            if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff) {
                                                                    if (decomp_var_a4 == esi) {
                                                                            *dword_4c6bc4 = 0xffffffff;
                                                                            if (eax > 0xffffffff) {
                                                                                    *dword_4c6bc4 = eax;
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                                    if (ecx > 0xffffffff) {
                                                                                            eax = ecx;
                                                                                            ecx = ecx | 0xffffffff;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            *dword_4c6bcc = ecx;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_a4 == decomp_var_9c) {
                                                                    if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                            eax = eax | 0xffffffff;
                                                                            *dword_4c6bc8 = eax;
                                                                    }
                                                            }
                                                            edx = decomp_var_9c;
                                                            if (decomp_var_a0 == edx && eax > 0xffffffff) {
                                                                    if (decomp_var_a4 == eax) {
                                                                            *dword_4c6bc8 = 0xffffffff;
                                                                            if (ecx > 0xffffffff) {
                                                                                    *dword_4c6bc8 = ecx;
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                            }
                                                            eax = edx;
                                                            edx = decomp_var_a4;
                                                            if (edx == eax) {
                                                                    if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                            ecx = ecx | 0xffffffff;
                                                                            *dword_4c6bcc = ecx;
                                                                    }
                                                            }
                                                            if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                    if (edx == ecx) {
                                                                            *dword_4c6bcc = 0xffffffff;
                                                                    }
                                                            }
                                                            eax = ebx[0x2];
                                                            bool_445 = decomp_var_a0 + 0x1 < eax[0x901];
                                                            decomp_var_a0 = decomp_var_a0 + 0x1;
                                                            if (bool_445) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                                    else {
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                    edx = decomp_var_a0;
                                                            }
                                                            else {
                                                                    edx = decomp_var_a0;
                                                                    *(eax * 0x4 + 0x62c580) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                            }
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cd0 != ecx) {
                                                                    if (*(int16_t *)word_4c6cd4 != ecx) {
                                                                            if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                            }
                                                            else {
                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                            }
                                                            *(eax * 0x8 + 0x4d5528) = 0x0;
                                                            *(eax * 0x8 + 0x4d552c) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                            if (esi == decomp_var_9c) {
                                                                    if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                            *(int8_t *)byte_baed44 = 0x0;
                                                                    }
                                                                    esi = *dword_4c6bc4;
                                                                    if (*dword_4c6bc4 > 0xffffffff) {
                                                                            esi = *dword_4c6bc4;
                                                                            if (edx == *dword_4c6bc4) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    eax = *dword_4c6bc8;
                                                                                    ecx = *dword_4c6bcc;
                                                                                    esi = esi | 0xffffffff;
                                                                                    *dword_4c6bc4 = esi;
                                                                                    if (eax > 0xffffffff) {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                            esi = eax;
                                                                                            eax = eax | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            if (ecx > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = ecx;
                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    *dword_4c6bcc = ecx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                            }
                                                            else {
                                                                    esi = *dword_4c6bc4;
                                                                    ecx = *dword_4c6bcc;
                                                                    eax = *dword_4c6bc8;
                                                            }
                                                            if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff) {
                                                                    if (decomp_var_a4 == esi) {
                                                                            *dword_4c6bc4 = 0xffffffff;
                                                                            if (eax > 0xffffffff) {
                                                                                    *dword_4c6bc4 = eax;
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                                    if (ecx > 0xffffffff) {
                                                                                            eax = ecx;
                                                                                            ecx = ecx | 0xffffffff;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            *dword_4c6bcc = ecx;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_a4 == decomp_var_9c) {
                                                                    if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                            eax = eax | 0xffffffff;
                                                                            *dword_4c6bc8 = eax;
                                                                    }
                                                            }
                                                            edx = decomp_var_9c;
                                                            if (decomp_var_a0 == edx && eax > 0xffffffff) {
                                                                    if (decomp_var_a4 == eax) {
                                                                            *dword_4c6bc8 = 0xffffffff;
                                                                            if (ecx > 0xffffffff) {
                                                                                    *dword_4c6bc8 = ecx;
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                            }
                                                            eax = edx;
                                                            edx = decomp_var_a4;
                                                            if (edx == eax) {
                                                                    if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                            ecx = ecx | 0xffffffff;
                                                                            *dword_4c6bcc = ecx;
                                                                    }
                                                            }
                                                            if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                    if (edx == ecx) {
                                                                            *dword_4c6bcc = 0xffffffff;
                                                                    }
                                                            }
                                                            eax = ebx[0x2];
                                                            bool_350 = decomp_var_a0 + 0x1 < eax[0x901];
                                                            decomp_var_a0 = decomp_var_a0 + 0x1;
                                                            if (bool_350) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ecx = esi[0x1];
                                                    edx = *eax;
                                                    edx = *edx;
                                                    esp = esp - 0x8;
                                                    edi = (edx)(ecx, 0x1);
                                                    if (edi != 0x0) {
                                                            edi[0x1] = esi[0x1];
                                                            eax = esi[0x1];
                                                            sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                            esp = (esp - 0x10) + 0x10;
                                                            esp = esp - 0x8;
                                                            eax = sub_419e60(&decomp_var_38, &decomp_var_7c, decomp_var_c0);
                                                            eax = edi + 0x10 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    (*(**eax + 0x4))(eax);
                                                            }
                                                            ebx = decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2;
                                                            ebp = *(ebx[0x2edbcb] + 0x4);
                                                            esi = ebx + 0xbb6f28;
                                                            edi = ebp;
                                                            if (arg_d == 0x0) {
                                                                    sub_401950(edi[0x2]);
                                                                    edi = *edi;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x8) + 0x4;
                                                                    ebp = edi;
                                                                    if (edi[0x11] == 0x0) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            eax = esi[0x1];
                                                            eax[0x1] = eax;
                                                            eax = esi[0x1];
                                                            esi[0x2] = 0x0;
                                                            *eax = eax;
                                                            esi = esi[0x1];
                                                            esi[0x2] = esi;
                                                            ebp = *(ebx[0x2edc0b] + 0x4);
                                                            edi = ebx + 0xbb7028;
                                                            esi = ebp;
                                                            if (arg_d == 0x0) {
                                                                    sub_401950(esi[0x2]);
                                                                    esi = *esi;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x8) + 0x4;
                                                                    ebp = esi;
                                                                    if (esi[0x11] == 0x0) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            eax = edi[0x1];
                                                            ebx = decomp_var_98;
                                                            esi = decomp_var_a4;
                                                            eax[0x1] = eax;
                                                            eax = edi[0x1];
                                                            edi[0x2] = 0x0;
                                                            *eax = eax;
                                                            edi = edi[0x1];
                                                            eax = decomp_var_94;
                                                            edi[0x2] = edi;
                                                            edx = decomp_var_a0;
                                                            if (decomp_var_9c == edx) {
                                                                    ebx = decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2;
                                                                    esi = ebx + 0xbb6f28;
                                                                    if (arg_d == 0x0) {
                                                                            sub_42d850();
                                                                    }
                                                                    eax = esi[0x1];
                                                                    eax[0x1] = eax;
                                                                    eax = esi[0x1];
                                                                    esi[0x2] = 0x0;
                                                                    *eax = eax;
                                                                    esi = esi[0x1];
                                                                    esi[0x2] = esi;
                                                                    ebp = *(ebx[0x2edc0b] + 0x4);
                                                                    edi = ebx + 0xbb7028;
                                                                    esi = ebp;
                                                                    if (arg_d == 0x0) {
                                                                            do {
                                                                                    sub_401950(esi[0x2]);
                                                                                    esi = *esi;
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x8) + 0x4;
                                                                                    ebp = esi;
                                                                            } while (esi[0x11] == 0x0);
                                                                    }
                                                                    eax = edi[0x1];
                                                                    ebx = decomp_var_98;
                                                                    esi = decomp_var_a4;
                                                                    eax[0x1] = eax;
                                                                    eax = edi[0x1];
                                                                    edi[0x2] = 0x0;
                                                                    *eax = eax;
                                                                    edi = edi[0x1];
                                                                    eax = decomp_var_94;
                                                                    edi[0x2] = edi;
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                            edx = decomp_var_a0;
                                                                    }
                                                                    else {
                                                                            edx = decomp_var_a0;
                                                                            *(eax * 0x4 + 0x62c580) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                                    }
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cd0 != ecx) {
                                                                            if (*(int16_t *)word_4c6cd4 != ecx) {
                                                                                    if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                                    *(eax * 0x8 + 0x4d5528) = 0x0;
                                                                    *(eax * 0x8 + 0x4d552c) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                                    if (esi == decomp_var_9c) {
                                                                            if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                                    *(int8_t *)byte_baed44 = 0x0;
                                                                            }
                                                                            esi = *dword_4c6bc4;
                                                                            if (*dword_4c6bc4 > 0xffffffff) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    if (edx == *dword_4c6bc4) {
                                                                                            esi = *dword_4c6bc4;
                                                                                            eax = *dword_4c6bc8;
                                                                                            ecx = *dword_4c6bcc;
                                                                                            esi = esi | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            if (eax > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = *dword_4c6bc8;
                                                                                                    esi = eax;
                                                                                                    eax = eax | 0xffffffff;
                                                                                                    *dword_4c6bc4 = esi;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    if (ecx > 0xffffffff) {
                                                                                                            ecx = *dword_4c6bcc;
                                                                                                            eax = ecx;
                                                                                                            ecx = ecx | 0xffffffff;
                                                                                                            *dword_4c6bc8 = eax;
                                                                                                            *dword_4c6bcc = ecx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi = *dword_4c6bc4;
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                                    if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff) {
                                                                            if (decomp_var_a4 == esi) {
                                                                                    *dword_4c6bc4 = 0xffffffff;
                                                                                    if (eax > 0xffffffff) {
                                                                                            *dword_4c6bc4 = eax;
                                                                                            eax = eax | 0xffffffff;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            if (ecx > 0xffffffff) {
                                                                                                    eax = ecx;
                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    *dword_4c6bcc = ecx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    if (decomp_var_a4 == decomp_var_9c) {
                                                                            if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                            }
                                                                    }
                                                                    edx = decomp_var_9c;
                                                                    if (decomp_var_a0 == edx && eax > 0xffffffff) {
                                                                            if (decomp_var_a4 == eax) {
                                                                                    *dword_4c6bc8 = 0xffffffff;
                                                                                    if (ecx > 0xffffffff) {
                                                                                            *dword_4c6bc8 = ecx;
                                                                                            ecx = ecx | 0xffffffff;
                                                                                            *dword_4c6bcc = ecx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    eax = edx;
                                                                    edx = decomp_var_a4;
                                                                    if (edx == eax) {
                                                                            if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                                    if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                            if (edx == ecx) {
                                                                                    *dword_4c6bcc = 0xffffffff;
                                                                            }
                                                                    }
                                                                    eax = ebx[0x2];
                                                                    bool_393 = decomp_var_a0 + 0x1 < eax[0x901];
                                                                    decomp_var_a0 = decomp_var_a0 + 0x1;
                                                                    if (bool_393) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                            edx = decomp_var_a0;
                                                                    }
                                                                    else {
                                                                            edx = decomp_var_a0;
                                                                            *(eax * 0x4 + 0x62c580) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                                    }
                                                                    ecx = ebx[0x2];
                                                                    ecx = ecx[0x1225] & 0xffff;
                                                                    if (*(int16_t *)word_4c6cd0 != ecx) {
                                                                            if (*(int16_t *)word_4c6cd4 != ecx) {
                                                                                    if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                                    *(eax * 0x8 + 0x4d5528) = 0x0;
                                                                    *(eax * 0x8 + 0x4d552c) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                                    *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                                    if (esi == decomp_var_9c) {
                                                                            if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                                    *(int8_t *)byte_baed44 = 0x0;
                                                                            }
                                                                            esi = *dword_4c6bc4;
                                                                            if (*dword_4c6bc4 > 0xffffffff) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    if (edx == *dword_4c6bc4) {
                                                                                            esi = *dword_4c6bc4;
                                                                                            eax = *dword_4c6bc8;
                                                                                            ecx = *dword_4c6bcc;
                                                                                            esi = esi | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            if (eax > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = *dword_4c6bc8;
                                                                                                    esi = eax;
                                                                                                    eax = eax | 0xffffffff;
                                                                                                    *dword_4c6bc4 = esi;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    if (ecx > 0xffffffff) {
                                                                                                            ecx = *dword_4c6bcc;
                                                                                                            eax = ecx;
                                                                                                            ecx = ecx | 0xffffffff;
                                                                                                            *dword_4c6bc8 = eax;
                                                                                                            *dword_4c6bcc = ecx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi = *dword_4c6bc4;
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                                    if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff) {
                                                                            if (decomp_var_a4 == esi) {
                                                                                    *dword_4c6bc4 = 0xffffffff;
                                                                                    if (eax > 0xffffffff) {
                                                                                            *dword_4c6bc4 = eax;
                                                                                            eax = eax | 0xffffffff;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            if (ecx > 0xffffffff) {
                                                                                                    eax = ecx;
                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    *dword_4c6bcc = ecx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    if (decomp_var_a4 == decomp_var_9c) {
                                                                            if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                            }
                                                                    }
                                                                    edx = decomp_var_9c;
                                                                    if (decomp_var_a0 == edx && eax > 0xffffffff) {
                                                                            if (decomp_var_a4 == eax) {
                                                                                    *dword_4c6bc8 = 0xffffffff;
                                                                                    if (ecx > 0xffffffff) {
                                                                                            *dword_4c6bc8 = ecx;
                                                                                            ecx = ecx | 0xffffffff;
                                                                                            *dword_4c6bcc = ecx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    eax = edx;
                                                                    edx = decomp_var_a4;
                                                                    if (edx == eax) {
                                                                            if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                                    if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                            if (edx == ecx) {
                                                                                    *dword_4c6bcc = 0xffffffff;
                                                                            }
                                                                    }
                                                                    eax = ebx[0x2];
                                                                    bool_156 = decomp_var_a0 + 0x1 < eax[0x901];
                                                                    decomp_var_a0 = decomp_var_a0 + 0x1;
                                                                    if (bool_156) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            ecx = esi[0x1];
                                            edx = *eax;
                                            edx = *edx;
                                            esp = esp - 0x8;
                                            edi = (edx)(ecx, 0x1);
                                            if (edi != 0x0) {
                                                    edi[0x1] = esi[0x1];
                                                    eax = esi[0x1];
                                                    sub_47a5af(edi + 0x10, eax + 0x1, esi + 0x10, eax + 0x1);
                                                    esp = (esp - 0x10) + 0x10;
                                                    esp = esp - 0x8;
                                                    eax = sub_419e60(&decomp_var_38, &decomp_var_7c, decomp_var_c0);
                                                    eax = edi + 0x10 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    ebx = decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2 + decomp_var_a0 + decomp_var_a0 * 0x2;
                                                    ebp = *(ebx[0x2edbcb] + 0x4);
                                                    esi = ebx + 0xbb6f28;
                                                    edi = ebp;
                                                    if (arg_d == 0x0) {
                                                            sub_401950(edi[0x2]);
                                                            edi = *edi;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x8) + 0x4;
                                                            ebp = edi;
                                                            if (edi[0x11] == 0x0) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    eax = esi[0x1];
                                                    eax[0x1] = eax;
                                                    eax = esi[0x1];
                                                    esi[0x2] = 0x0;
                                                    *eax = eax;
                                                    esi = esi[0x1];
                                                    esi[0x2] = esi;
                                                    ebp = *(ebx[0x2edc0b] + 0x4);
                                                    edi = ebx + 0xbb7028;
                                                    esi = ebp;
                                                    if (arg_d == 0x0) {
                                                            sub_401950(esi[0x2]);
                                                            esi = *esi;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x8) + 0x4;
                                                            ebp = esi;
                                                            if (esi[0x11] == 0x0) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    eax = edi[0x1];
                                                    ebx = decomp_var_98;
                                                    esi = decomp_var_a4;
                                                    eax[0x1] = eax;
                                                    eax = edi[0x1];
                                                    edi[0x2] = 0x0;
                                                    *eax = eax;
                                                    edi = edi[0x1];
                                                    eax = decomp_var_94;
                                                    edi[0x2] = edi;
                                                    edx = decomp_var_a0;
                                                    if (decomp_var_9c == edx) {
                                                            ebx = decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2;
                                                            esi = ebx + 0xbb6f28;
                                                            if (arg_d == 0x0) {
                                                                    sub_42d850();
                                                            }
                                                            eax = esi[0x1];
                                                            eax[0x1] = eax;
                                                            eax = esi[0x1];
                                                            esi[0x2] = 0x0;
                                                            *eax = eax;
                                                            esi = esi[0x1];
                                                            esi[0x2] = esi;
                                                            ebp = *(ebx[0x2edc0b] + 0x4);
                                                            edi = ebx + 0xbb7028;
                                                            esi = ebp;
                                                            if (arg_d == 0x0) {
                                                                    do {
                                                                            sub_401950(esi[0x2]);
                                                                            esi = *esi;
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x8) + 0x4;
                                                                            ebp = esi;
                                                                    } while (esi[0x11] == 0x0);
                                                            }
                                                            eax = edi[0x1];
                                                            ebx = decomp_var_98;
                                                            esi = decomp_var_a4;
                                                            eax[0x1] = eax;
                                                            eax = edi[0x1];
                                                            edi[0x2] = 0x0;
                                                            *eax = eax;
                                                            edi = edi[0x1];
                                                            eax = decomp_var_94;
                                                            edi[0x2] = edi;
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                    edx = decomp_var_a0;
                                                            }
                                                            else {
                                                                    edx = decomp_var_a0;
                                                                    *(eax * 0x4 + 0x62c580) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                            }
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cd0 != ecx) {
                                                                    if (*(int16_t *)word_4c6cd4 != ecx) {
                                                                            if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                            }
                                                            else {
                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                            }
                                                            *(eax * 0x8 + 0x4d5528) = 0x0;
                                                            *(eax * 0x8 + 0x4d552c) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                            if (esi == decomp_var_9c) {
                                                                    if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                            *(int8_t *)byte_baed44 = 0x0;
                                                                    }
                                                                    esi = *dword_4c6bc4;
                                                                    if (*dword_4c6bc4 > 0xffffffff) {
                                                                            esi = *dword_4c6bc4;
                                                                            if (edx == *dword_4c6bc4) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    eax = *dword_4c6bc8;
                                                                                    ecx = *dword_4c6bcc;
                                                                                    esi = esi | 0xffffffff;
                                                                                    *dword_4c6bc4 = esi;
                                                                                    if (eax > 0xffffffff) {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                            esi = eax;
                                                                                            eax = eax | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            if (ecx > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = ecx;
                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    *dword_4c6bcc = ecx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                            }
                                                            else {
                                                                    esi = *dword_4c6bc4;
                                                                    ecx = *dword_4c6bcc;
                                                                    eax = *dword_4c6bc8;
                                                            }
                                                            if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff) {
                                                                    if (decomp_var_a4 == esi) {
                                                                            *dword_4c6bc4 = 0xffffffff;
                                                                            if (eax > 0xffffffff) {
                                                                                    *dword_4c6bc4 = eax;
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                                    if (ecx > 0xffffffff) {
                                                                                            eax = ecx;
                                                                                            ecx = ecx | 0xffffffff;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            *dword_4c6bcc = ecx;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_a4 == decomp_var_9c) {
                                                                    if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                            eax = eax | 0xffffffff;
                                                                            *dword_4c6bc8 = eax;
                                                                    }
                                                            }
                                                            edx = decomp_var_9c;
                                                            if (decomp_var_a0 == edx && eax > 0xffffffff) {
                                                                    if (decomp_var_a4 == eax) {
                                                                            *dword_4c6bc8 = 0xffffffff;
                                                                            if (ecx > 0xffffffff) {
                                                                                    *dword_4c6bc8 = ecx;
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                            }
                                                            eax = edx;
                                                            edx = decomp_var_a4;
                                                            if (edx == eax) {
                                                                    if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                            ecx = ecx | 0xffffffff;
                                                                            *dword_4c6bcc = ecx;
                                                                    }
                                                            }
                                                            if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                    if (edx == ecx) {
                                                                            *dword_4c6bcc = 0xffffffff;
                                                                    }
                                                            }
                                                            eax = ebx[0x2];
                                                            bool_431 = decomp_var_a0 + 0x1 < eax[0x901];
                                                            decomp_var_a0 = decomp_var_a0 + 0x1;
                                                            if (bool_431) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                                    else {
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                                                    edx = decomp_var_a0;
                                                            }
                                                            else {
                                                                    edx = decomp_var_a0;
                                                                    *(eax * 0x4 + 0x62c580) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                                                            }
                                                            ecx = ebx[0x2];
                                                            ecx = ecx[0x1225] & 0xffff;
                                                            if (*(int16_t *)word_4c6cd0 != ecx) {
                                                                    if (*(int16_t *)word_4c6cd4 != ecx) {
                                                                            if (*(int16_t *)word_4c6cc4 == ecx) {
                                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                                    }
                                                            }
                                                            else {
                                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                                            }
                                                            *(eax * 0x8 + 0x4d5528) = 0x0;
                                                            *(eax * 0x8 + 0x4d552c) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                                                            *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                                                            if (esi == decomp_var_9c) {
                                                                    if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                                                            *(int8_t *)byte_baed44 = 0x0;
                                                                    }
                                                                    esi = *dword_4c6bc4;
                                                                    if (*dword_4c6bc4 > 0xffffffff) {
                                                                            esi = *dword_4c6bc4;
                                                                            if (edx == *dword_4c6bc4) {
                                                                                    esi = *dword_4c6bc4;
                                                                                    eax = *dword_4c6bc8;
                                                                                    ecx = *dword_4c6bcc;
                                                                                    esi = esi | 0xffffffff;
                                                                                    *dword_4c6bc4 = esi;
                                                                                    if (eax > 0xffffffff) {
                                                                                            ecx = *dword_4c6bcc;
                                                                                            eax = *dword_4c6bc8;
                                                                                            esi = eax;
                                                                                            eax = eax | 0xffffffff;
                                                                                            *dword_4c6bc4 = esi;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            if (ecx > 0xffffffff) {
                                                                                                    ecx = *dword_4c6bcc;
                                                                                                    eax = ecx;
                                                                                                    ecx = ecx | 0xffffffff;
                                                                                                    *dword_4c6bc8 = eax;
                                                                                                    *dword_4c6bcc = ecx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = *dword_4c6bcc;
                                                                                    eax = *dword_4c6bc8;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = *dword_4c6bcc;
                                                                            eax = *dword_4c6bc8;
                                                                    }
                                                            }
                                                            else {
                                                                    esi = *dword_4c6bc4;
                                                                    ecx = *dword_4c6bcc;
                                                                    eax = *dword_4c6bc8;
                                                            }
                                                            if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff) {
                                                                    if (decomp_var_a4 == esi) {
                                                                            *dword_4c6bc4 = 0xffffffff;
                                                                            if (eax > 0xffffffff) {
                                                                                    *dword_4c6bc4 = eax;
                                                                                    eax = eax | 0xffffffff;
                                                                                    *dword_4c6bc8 = eax;
                                                                                    if (ecx > 0xffffffff) {
                                                                                            eax = ecx;
                                                                                            ecx = ecx | 0xffffffff;
                                                                                            *dword_4c6bc8 = eax;
                                                                                            *dword_4c6bcc = ecx;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_a4 == decomp_var_9c) {
                                                                    if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                                                            eax = eax | 0xffffffff;
                                                                            *dword_4c6bc8 = eax;
                                                                    }
                                                            }
                                                            edx = decomp_var_9c;
                                                            if (decomp_var_a0 == edx && eax > 0xffffffff) {
                                                                    if (decomp_var_a4 == eax) {
                                                                            *dword_4c6bc8 = 0xffffffff;
                                                                            if (ecx > 0xffffffff) {
                                                                                    *dword_4c6bc8 = ecx;
                                                                                    ecx = ecx | 0xffffffff;
                                                                                    *dword_4c6bcc = ecx;
                                                                            }
                                                                    }
                                                            }
                                                            eax = edx;
                                                            edx = decomp_var_a4;
                                                            if (edx == eax) {
                                                                    if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                                                            ecx = ecx | 0xffffffff;
                                                                            *dword_4c6bcc = ecx;
                                                                    }
                                                            }
                                                            if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                                                    if (edx == ecx) {
                                                                            *dword_4c6bcc = 0xffffffff;
                                                                    }
                                                            }
                                                            eax = ebx[0x2];
                                                            bool_479 = decomp_var_a0 + 0x1 < eax[0x901];
                                                            decomp_var_a0 = decomp_var_a0 + 0x1;
                                                            if (bool_479) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    temp_0 = 0x1;
                                    break;
                            }
                    }
            }
            else {
                    edx = decomp_var_a0;
                    if (decomp_var_9c == edx) {
                            ebx = decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2 + decomp_var_a4 + decomp_var_a4 * 0x2;
                            esi = ebx + 0xbb6f28;
                            if (arg_d == 0x0) {
                                    sub_42d850();
                            }
                            eax = esi[0x1];
                            eax[0x1] = eax;
                            eax = esi[0x1];
                            esi[0x2] = 0x0;
                            *eax = eax;
                            esi = esi[0x1];
                            esi[0x2] = esi;
                            ebp = *(ebx[0x2edc0b] + 0x4);
                            edi = ebx + 0xbb7028;
                            esi = ebp;
                            if (arg_d == 0x0) {
                                    do {
                                            sub_401950(esi[0x2]);
                                            esi = *esi;
                                            sub_47c8f9();
                                            esp = (esp - 0x8) + 0x4;
                                            ebp = esi;
                                    } while (esi[0x11] == 0x0);
                            }
                            eax = edi[0x1];
                            ebx = decomp_var_98;
                            esi = decomp_var_a4;
                            eax[0x1] = eax;
                            eax = edi[0x1];
                            edi[0x2] = 0x0;
                            *eax = eax;
                            edi = edi[0x1];
                            eax = decomp_var_94;
                            edi[0x2] = edi;
                            ecx = ebx[0x2];
                            ecx = ecx[0x1225] & 0xffff;
                            if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                    edx = decomp_var_a0;
                            }
                            else {
                                    edx = decomp_var_a0;
                                    *(eax * 0x4 + 0x62c580) = 0x1;
                                    *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                            }
                            ecx = ebx[0x2];
                            ecx = ecx[0x1225] & 0xffff;
                            if (*(int16_t *)word_4c6cd0 != ecx) {
                                    if (*(int16_t *)word_4c6cd4 != ecx) {
                                            if (*(int16_t *)word_4c6cc4 == ecx) {
                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                            }
                                    }
                                    else {
                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                    }
                            }
                            else {
                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                            }
                            *(eax * 0x8 + 0x4d5528) = 0x0;
                            *(eax * 0x8 + 0x4d552c) = 0x0;
                            *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                            *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                            if (esi == decomp_var_9c) {
                                    if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                            *(int8_t *)byte_baed44 = 0x0;
                                    }
                                    esi = *dword_4c6bc4;
                                    if (*dword_4c6bc4 > 0xffffffff) {
                                            esi = *dword_4c6bc4;
                                            if (edx == *dword_4c6bc4) {
                                                    esi = *dword_4c6bc4;
                                                    eax = *dword_4c6bc8;
                                                    ecx = *dword_4c6bcc;
                                                    esi = esi | 0xffffffff;
                                                    *dword_4c6bc4 = esi;
                                                    if (eax > 0xffffffff) {
                                                            ecx = *dword_4c6bcc;
                                                            eax = *dword_4c6bc8;
                                                            esi = eax;
                                                            eax = eax | 0xffffffff;
                                                            *dword_4c6bc4 = esi;
                                                            *dword_4c6bc8 = eax;
                                                            if (ecx > 0xffffffff) {
                                                                    ecx = *dword_4c6bcc;
                                                                    eax = ecx;
                                                                    ecx = ecx | 0xffffffff;
                                                                    *dword_4c6bc8 = eax;
                                                                    *dword_4c6bcc = ecx;
                                                            }
                                                    }
                                            }
                                            else {
                                                    ecx = *dword_4c6bcc;
                                                    eax = *dword_4c6bc8;
                                            }
                                    }
                                    else {
                                            ecx = *dword_4c6bcc;
                                            eax = *dword_4c6bc8;
                                    }
                            }
                            else {
                                    esi = *dword_4c6bc4;
                                    ecx = *dword_4c6bcc;
                                    eax = *dword_4c6bc8;
                            }
                            if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff) {
                                    if (decomp_var_a4 == esi) {
                                            *dword_4c6bc4 = 0xffffffff;
                                            if (eax > 0xffffffff) {
                                                    *dword_4c6bc4 = eax;
                                                    eax = eax | 0xffffffff;
                                                    *dword_4c6bc8 = eax;
                                                    if (ecx > 0xffffffff) {
                                                            eax = ecx;
                                                            ecx = ecx | 0xffffffff;
                                                            *dword_4c6bc8 = eax;
                                                            *dword_4c6bcc = ecx;
                                                    }
                                            }
                                    }
                            }
                            if (decomp_var_a4 == decomp_var_9c) {
                                    if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                            eax = eax | 0xffffffff;
                                            *dword_4c6bc8 = eax;
                                    }
                            }
                            edx = decomp_var_9c;
                            if (decomp_var_a0 == edx && eax > 0xffffffff) {
                                    if (decomp_var_a4 == eax) {
                                            *dword_4c6bc8 = 0xffffffff;
                                            if (ecx > 0xffffffff) {
                                                    *dword_4c6bc8 = ecx;
                                                    ecx = ecx | 0xffffffff;
                                                    *dword_4c6bcc = ecx;
                                            }
                                    }
                            }
                            eax = edx;
                            edx = decomp_var_a4;
                            if (edx == eax) {
                                    if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                            ecx = ecx | 0xffffffff;
                                            *dword_4c6bcc = ecx;
                                    }
                            }
                            if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                    if (edx == ecx) {
                                            *dword_4c6bcc = 0xffffffff;
                                    }
                            }
                            eax = ebx[0x2];
                            bool_660 = decomp_var_a0 + 0x1 < eax[0x901];
                            decomp_var_a0 = decomp_var_a0 + 0x1;
                            if (bool_660) {
                                    continue;
                            }
                            temp_0 = 0x2;
                            break;
                    }
                    else {
                            ecx = ebx[0x2];
                            ecx = ecx[0x1225] & 0xffff;
                            if (*(int16_t *)word_4c6cc8 != ecx && *(int16_t *)word_4c6ccc != ecx) {
                                    edx = decomp_var_a0;
                            }
                            else {
                                    edx = decomp_var_a0;
                                    *(eax * 0x4 + 0x62c580) = 0x1;
                                    *((edx * 0x15 + esi) * 0x4 + 0x62c580) = 0x1;
                            }
                            ecx = ebx[0x2];
                            ecx = ecx[0x1225] & 0xffff;
                            if (*(int16_t *)word_4c6cd0 != ecx) {
                                    if (*(int16_t *)word_4c6cd4 != ecx) {
                                            if (*(int16_t *)word_4c6cc4 == ecx) {
                                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                            }
                                    }
                                    else {
                                            *(eax * 0x4 + 0x62be98) = 0x1;
                                            *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                                    }
                            }
                            else {
                                    *(eax * 0x4 + 0x62be98) = 0x1;
                                    *((edx * 0x15 + esi) * 0x4 + 0x62be98) = 0x1;
                            }
                            *(eax * 0x8 + 0x4d5528) = 0x0;
                            *(eax * 0x8 + 0x4d552c) = 0x0;
                            *((edx * 0x15 + esi) * 0x8 + 0x4d5528) = 0x0;
                            *((edx * 0x15 + esi) * 0x8 + 0x4d552c) = 0x0;
                            if (esi == decomp_var_9c) {
                                    if (*(int8_t *)byte_baed44 == 0x1 && edx != *byte_4c6bc0) {
                                            *(int8_t *)byte_baed44 = 0x0;
                                    }
                                    esi = *dword_4c6bc4;
                                    if (*dword_4c6bc4 > 0xffffffff) {
                                            esi = *dword_4c6bc4;
                                            if (edx == *dword_4c6bc4) {
                                                    esi = *dword_4c6bc4;
                                                    eax = *dword_4c6bc8;
                                                    ecx = *dword_4c6bcc;
                                                    esi = esi | 0xffffffff;
                                                    *dword_4c6bc4 = esi;
                                                    if (eax > 0xffffffff) {
                                                            ecx = *dword_4c6bcc;
                                                            eax = *dword_4c6bc8;
                                                            esi = eax;
                                                            eax = eax | 0xffffffff;
                                                            *dword_4c6bc4 = esi;
                                                            *dword_4c6bc8 = eax;
                                                            if (ecx > 0xffffffff) {
                                                                    ecx = *dword_4c6bcc;
                                                                    eax = ecx;
                                                                    ecx = ecx | 0xffffffff;
                                                                    *dword_4c6bc8 = eax;
                                                                    *dword_4c6bcc = ecx;
                                                            }
                                                    }
                                            }
                                            else {
                                                    ecx = *dword_4c6bcc;
                                                    eax = *dword_4c6bc8;
                                            }
                                    }
                                    else {
                                            ecx = *dword_4c6bcc;
                                            eax = *dword_4c6bc8;
                                    }
                            }
                            else {
                                    esi = *dword_4c6bc4;
                                    ecx = *dword_4c6bcc;
                                    eax = *dword_4c6bc8;
                            }
                            if (decomp_var_a0 == decomp_var_9c && esi > 0xffffffff) {
                                    if (decomp_var_a4 == esi) {
                                            *dword_4c6bc4 = 0xffffffff;
                                            if (eax > 0xffffffff) {
                                                    *dword_4c6bc4 = eax;
                                                    eax = eax | 0xffffffff;
                                                    *dword_4c6bc8 = eax;
                                                    if (ecx > 0xffffffff) {
                                                            eax = ecx;
                                                            ecx = ecx | 0xffffffff;
                                                            *dword_4c6bc8 = eax;
                                                            *dword_4c6bcc = ecx;
                                                    }
                                            }
                                    }
                            }
                            if (decomp_var_a4 == decomp_var_9c) {
                                    if (eax > 0xffffffff && decomp_var_a0 == eax) {
                                            eax = eax | 0xffffffff;
                                            *dword_4c6bc8 = eax;
                                    }
                            }
                            edx = decomp_var_9c;
                            if (decomp_var_a0 == edx && eax > 0xffffffff) {
                                    if (decomp_var_a4 == eax) {
                                            *dword_4c6bc8 = 0xffffffff;
                                            if (ecx > 0xffffffff) {
                                                    *dword_4c6bc8 = ecx;
                                                    ecx = ecx | 0xffffffff;
                                                    *dword_4c6bcc = ecx;
                                            }
                                    }
                            }
                            eax = edx;
                            edx = decomp_var_a4;
                            if (edx == eax) {
                                    if (ecx > 0xffffffff && decomp_var_a0 == ecx) {
                                            ecx = ecx | 0xffffffff;
                                            *dword_4c6bcc = ecx;
                                    }
                            }
                            if (decomp_var_a0 == eax && ecx > 0xffffffff) {
                                    if (edx == ecx) {
                                            *dword_4c6bcc = 0xffffffff;
                                    }
                            }
                            eax = ebx[0x2];
                            bool_690 = decomp_var_a0 + 0x1 < eax[0x901];
                            decomp_var_a0 = decomp_var_a0 + 0x1;
                            if (bool_690) {
                                    continue;
                            }
                            temp_0 = 0x2;
                            break;
                    }
            }
    }
    else {
            eax = ebx[0x2];
            bool_12 = decomp_var_a0 + 0x1 < eax[0x901];
            decomp_var_a0 = decomp_var_a0 + 0x1;
            if (bool_12) {
                    continue;
            }
            temp_0 = 0x2;
            break;
    }
    goto .l3;

.l3:
    if (temp_0 != 0x0) {
            if (temp_0 != 0x1) {
                    eax = ebx[0x2];
                    ecx = eax[0x901];
                    edx = decomp_var_a4 + 0x1;
                    decomp_var_a4 = edx;
                    if (edx < ecx) {
                            continue;
                    }
                    temp_1 = 0x2;
                    break;
            }
            else {
                    sub_40b6d0();
                    temp_1 = 0x0;
                    break;
            }
    }
    else {
            temp_1 = 0x1;
            break;
    }
    goto .l2;
}
