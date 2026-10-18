// sub_44bd40 @ 0x44bd40
// hopper name: sub_44bd40
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_44bd40() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    var_14 = *dword_4c8db8 ^ &var_C4;
    var_C8 = ebx;
    decomp_var_cc = esi;
    var_D0 = edi;
    *0x0 = &var_C;
    esi = ecx;
    eax = sub_4103b0();
    eax[0x21] = 0x1;
    eax[0x1] = eax;
    *eax = eax;
    eax[0x2] = eax;
    var_D8 = 0x3;
    esp = esp - 0xdc;
    decomp_var_dc = 0x4b13ac;
    var_4 = 0x0;
    var_78 = arg_0;
    var_18 = 0xf;
    var_1C = 0x0;
    var_2C = 0x0;
    sub_402650(0x4b13ac, 0x3);
    eax = esi[0x2];
    ebx = eax + 0x24cc;
    var_C = 0x1;
    var_B8 = ebx;
    var_B4 = *eax[0x934];
    goto loc_44be21;

loc_44be21:
    eax = esi[0x2];
    ecx = eax[0x934];
    eax = eax + 0x24cc;
    var_6C = ecx;
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (var_B4 == var_6C) goto .l74;
    goto loc_44be4e;

.l74:
    break;

loc_44be4e:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (var_B4 == ebx[0x1]) {
            sub_47a948();
    }
    eax = var_B4[0x3];
    edx = eax + eax * 0x8;
    eax = esi[0x2];
    ecx = *(eax + edx * 0x4 + 0xc);
    eax = eax + edx * 0x4 + 0x8;
    edi = eax;
    var_C8 = eax;
    var_9C = edi;
    var_98 = *ecx;
    goto loc_44be90;
    esp = esp - 0x4;
    sub_46db50();
    eax = sub_4273a0(decomp_var_e0);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    ecx = esi[0x2];
    sub_45abe0();
    esp = (esp - 0x10) + 0x10;
    if (arg_0 <= 0x0) goto loc_44c83f;
    goto loc_44bfb9;

loc_44be90:
    var_78 = eax[0x1];
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (var_98 != var_78) {
            if (var_B4 == ebx[0x1]) {
                    sub_47a948();
            }
            ebx = var_B4[0x3];
            var_94 = ebx;
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (var_98 == edi[0x1]) {
                    sub_47a948();
            }
            eax = sub_41c1e0(&var_94);
            ecx = *eax;
            var_68 = ecx + 0x1f4;
            esp = esp - 0xc;
            var_64 = eax[0x1] + 0x0 + CARRY(EFLAGS(cf));
            eax = sub_41a010(&var_44, &var_68, decomp_var_dc);
            sub_401590();
            edi = var_9C;
            ebx = var_B8;
            eax = var_C8;
            continue;
    }
    break;

loc_44c83f:
    if (var_10 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    sub_4150e0(&var_34, &var_B4, *var_B0, &var_B4, var_B0);
    sub_47c8f9();
    *0x0 = var_4;
    eax = sub_47ad69();
    &var_BC = ebp;
    return eax;

loc_44bfb9:
    if (var_B8 == 0x0) goto loc_44c812;
    goto loc_44bfc5;
    sub_401520();
    ebx = var_B8;
    continue;

loc_44c812:
    if (var_7C > 0x0) {
            eax = sub_45abe0();
            *dword_baed34 = *dword_baed34 + 0x1;
            esp = (esp - 0xc) + 0xc - 0x4;
            sub_45fc20(eax);
            temp_8 = 0x2;
    }
    else {
            temp_8 = 0x1;
    }
    break;

loc_44bfc5:
    var_C4 = 0x0;
    var_A4 = 0x0;
    eax = var_A8[0x2];
    esi = eax + 0x24b4;
    edi = *eax[0x92e];
    var_6C = esi;
    var_68 = edi;
    goto loc_44bff0;
    goto loc_44c83f;

loc_44bff0:
    eax = var_A8[0x2];
    ebx = eax[0x92e];
    eax = eax + 0x24b4;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            sub_407720(edi + 0xc) + 0x4;
            sub_46db50();
            eax = sub_4273a0(decomp_var_dc);
            if (eax[0x6] >= 0x10) {
                    ebx = eax[0x1];
            }
            else {
                    ebx = eax + 0x4;
            }
            eax = ebx;
            edx = eax + 0x1;
            do {
                    ecx = *(int8_t *)eax;
                    eax = eax + 0x1;
            } while (ecx != 0x0);
            edi = var_1C;
            esi = eax - edx;
            eax = edi;
            if (edi >= esi) {
                    eax = esi;
            }
            ecx = var_2C;
            if (var_18 < 0x10) {
                    ecx = &var_2C;
            }
            var_D8 = eax;
            esp = (esp - 0xc) + 0xc;
            if (sub_40cd30(ecx, ebx, var_D8) != 0x0) {
                    var_C0 = var_C0 + 0x1;
                    sub_401520();
                    edi = var_64;
                    esi = var_68;
                    continue;
            }
            if (edi < esi) {
                    var_C0 = var_C0 + 0x1;
                    sub_401520();
                    edi = var_64;
                    esi = var_68;
                    continue;
            }
            if (edi == esi) {
                    var_A0 = var_A0 + 0x1;
                    sub_401520();
                    edi = var_64;
                    esi = var_68;
                    continue;
            }
            var_C0 = var_C0 + 0x1;
            sub_401520();
            edi = var_64;
            esi = var_68;
            continue;
    }
    break;
    eax = var_A8[0x2];
    esi = eax + 0x2474;
    edi = *eax[0x91e];
    var_84 = edi;
    &var_D8 = &var_D8;
    goto loc_44c110;

loc_44c110:
    eax = var_A8[0x2];
    ebx = eax[0x91e];
    eax = eax + 0x2474;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            var_8C = edi[0x8];
            sub_46db50();
            eax = sub_4273a0(decomp_var_dc);
            if (eax[0x6] >= 0x10) {
                    ebx = eax[0x1];
            }
            else {
                    ebx = eax + 0x4;
            }
            eax = ebx;
            edx = eax + 0x1;
            do {
                    ecx = *(int8_t *)eax;
                    eax = eax + 0x1;
            } while (ecx != 0x0);
            edi = var_1C;
            esi = eax - edx;
            eax = edi;
            if (edi >= esi) {
                    eax = esi;
            }
            ecx = var_2C;
            if (var_18 < 0x10) {
                    ecx = &var_2C;
            }
            esp = (esp - 0xc) + 0xc;
            if (sub_40cd30(ecx, ebx, eax) != 0x0) {
                    var_C0 = var_C0 + 0x1;
                    sub_40e680();
                    edi = var_80;
                    esi = var_84;
                    continue;
            }
            if (edi < esi) {
                    var_C0 = var_C0 + 0x1;
                    sub_40e680();
                    edi = var_80;
                    esi = var_84;
                    continue;
            }
            if (edi == esi) {
                    var_A0 = var_A0 + 0x1;
                    sub_40e680();
                    edi = var_80;
                    esi = var_84;
                    continue;
            }
            var_C0 = var_C0 + 0x1;
            sub_40e680();
            edi = var_80;
            esi = var_84;
            continue;
    }
    break;
    ecx = var_C4;
    eax = var_A4;
    var_80 = eax + ecx;
    if (ecx > 0x0) {
            var_C4 = eax * 0x64 / ecx;
            asm { fild       dword [esp+0xd8+var_C4] };
    }
    else {
            asm { fld        dword [dword_value_1120403456] };
    }
    ebx = var_A4;
    asm { fstp       dword [esp+0xd4+var_A0] };
    sub_447460(ebx[0x1346], ebx[0x1347], ebx[0x1348], ebx[0x1349]);
    var_D8 = ebx[0x137f];
    esp = esp - 0x1c;
    sub_41cd70(ebx + 0x4e00, ebx[0x137e], var_D8);
    eax = var_C4;
    edi = eax[0x1];
    esi = edi;
    if (edi[0x21] == 0x0) {
            do {
                    sub_40faf0(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x21] == 0x0);
            eax = var_C4;
    }
    eax[0x1] = eax;
    var_C0 = 0x0;
    *var_C4 = var_C4;
    var_C4[0x2] = var_C4;
    eax = ebx[0x2];
    ecx = eax + 0x24cc;
    var_BC = ecx;
    var_B8 = *eax[0x934];
    goto loc_44c2f0;

loc_44c2f0:
    eax = ebx[0x2];
    esi = eax[0x934];
    eax = eax + 0x24cc;
    if (ecx == 0x0 || ecx != eax) {
            sub_47a948();
    }
    if (var_B4 == esi) goto .l34;
    goto loc_44c315;

.l34:
    break;

loc_44c315:
    eax = ebx[0x2];
    edi = *eax[0x91e];
    esi = eax + 0x2474;
    var_8C = esi;
    var_88 = edi;
    goto loc_44c340;
    esi = *var_C0;
    if (esi == var_C0) {
            sub_47a948();
    }
    esp = esp - 0x4;
    sub_46db50();
    eax = sub_4273a0(decomp_var_e0);
    if (eax[0x6] >= 0x10) {
            edi = eax[0x1];
    }
    else {
            edi = eax + 0x4;
    }
    if (esi == var_BC) {
            sub_47a948();
    }
    esp = esp - 0x4;
    sub_46db50();
    eax = sub_4273a0(decomp_var_dc);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    var_D8 = edi;
    sub_45abe0();
    esp = (esp - 0x10) + 0x10;
    var_9C = &var_BC;
    var_98 = esi;
    sub_40f6f0();
    edi = var_B8;
    if (var_9C == 0x0 || var_9C != &var_BC) {
            sub_47a948();
    }
    if (var_98 != edi) {
            if (esi == var_B8) {
                    sub_47a948();
            }
            if ((esi[0x4] | esi[0x5]) != 0x0) {
                    if (var_9C == 0x0) {
                            sub_47a948();
                    }
                    if (var_98 == var_9C[0x1]) {
                            sub_47a948();
                    }
                    if (esi == var_B8) {
                            sub_47a948();
                    }
                    if (var_98 == var_9C[0x1]) {
                            sub_47a948();
                    }
                    if (esi == var_B8) {
                            sub_47a948();
                    }
                    if (var_98 == var_9C[0x1]) {
                            sub_47a948();
                    }
            }
    }
    if (esi == var_B8) {
            sub_47a948();
    }
    eax = esi[0x6];
    edi = var_6C << 0x8;
    var_C0 = edi;
    if ((*((eax + edi) * 0x8 + 0x5460e8) | *((eax + edi) * 0x8 + 0x5460ec)) == 0x0) {
            if (esi == var_B8) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            sub_46db50();
            eax = sub_4273a0(var_D8);
            if (eax[0x6] >= 0x10) {
                    edx = eax[0x1];
            }
            else {
                    edx = eax + 0x4;
            }
            eax = edx;
            edi = eax + 0x1;
            do {
                    ecx = *(int8_t *)eax;
                    eax = eax + 0x1;
            } while (ecx != 0x0);
            edi = eax - edi;
            eax = var_18;
            if (eax >= edi) {
                    eax = edi;
            }
            ecx = var_28;
            if (var_14 < 0x10) {
                    ecx = &var_28;
            }
            var_D8 = edx;
            esp = (esp - 0xc) + 0xc;
            if (sub_40cd30(ecx, var_D8, eax) == 0x0) {
                    eax = var_18;
                    if (eax >= edi) {
                            if (eax != edi) {
                                    eax = var_78 * 0x64 / ebx[0xfff];
                                    if (eax > 0x2a) {
                                            asm { fld        dword [aWaivingDBuilds+20] };
                                            asm { fcomp      dword [esp+0xd0+var_9C] };
                                            asm { fnstsw     ax };
                                            if ((HIBYTE(eax) & 0x41) == 0x0) {
                                                    ecx = sub_47b678();
                                                    if (((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x64 < 0x32) {
                                                            if (esi == var_B4) {
                                                                    sub_47a948();
                                                            }
                                                            esi[0xe] = *(int16_t *)word_4c6c08;
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            eax = var_78 * 0x64 / ebx[0xfff];
                            if (eax > 0x2a) {
                                    asm { fld        dword [aWaivingDBuilds+20] };
                                    asm { fcomp      dword [esp+0xd0+var_9C] };
                                    asm { fnstsw     ax };
                                    if ((HIBYTE(eax) & 0x41) == 0x0) {
                                            ecx = sub_47b678();
                                            if (((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x64 < 0x32) {
                                                    if (esi == var_B4) {
                                                            sub_47a948();
                                                    }
                                                    esi[0xe] = *(int16_t *)word_4c6c08;
                                            }
                                    }
                            }
                    }
            }
            else {
                    eax = var_78 * 0x64 / ebx[0xfff];
                    if (eax > 0x2a) {
                            asm { fld        dword [aWaivingDBuilds+20] };
                            asm { fcomp      dword [esp+0xd0+var_9C] };
                            asm { fnstsw     ax };
                            if ((HIBYTE(eax) & 0x41) == 0x0) {
                                    ecx = sub_47b678();
                                    if (((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x64 < 0x32) {
                                            if (esi == var_B4) {
                                                    sub_47a948();
                                            }
                                            esi[0xe] = *(int16_t *)word_4c6c08;
                                    }
                            }
                    }
            }
            edi = var_BC;
    }
    if (esi == var_B4) {
            sub_47a948();
    }
    esp = esp - 0x8;
    var_D8 = esi[0x6];
    edx = esi[0xe];
    ecx = ebx[0x2];
    sub_460f60(var_D8, edx);
    if (esi == var_B4) {
            sub_47a948();
    }
    esi = esi[0x6];
    *((edi + esi) * 0x8 + 0x520ce8) = 0x1;
    *((edi + esi) * 0x8 + 0x520cec) = 0x0;
    edi = *var_B4;
    var_78 = esi;
    esi = &var_B8;
    goto loc_44c78c;

loc_44c340:
    eax = var_A8[0x2];
    ebx = eax[0x91e];
    eax = eax + 0x2474;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            bool_78 = edi != esi[0x1];
            ebx = edi[0x3];
            if (!bool_78) {
                    sub_47a948();
            }
            var_8C = edi[0x8];
            if (var_B4 == 0x0) {
                    sub_47a948();
            }
            if (var_B0 == var_B4[0x1]) {
                    sub_47a948();
            }
            if (ebx == var_B0[0x3]) {
                    var_A9 = 0x0;
            }
            sub_40e680();
            edi = var_84;
            esi = var_88;
            continue;
    }
    break;

loc_44c78c:
    var_6C = edi;
    var_70 = esi;
    goto loc_44c794;
    if (var_A9 != 0x1) {
            sub_401520();
            ebx = var_A8;
            ecx = var_B4;
            continue;
    }
    esi = var_B4;
    if (esi == 0x0) {
            sub_47a948();
    }
    if (var_B0 == esi[0x1]) {
            sub_47a948();
    }
    eax = var_B0[0x3];
    ecx = eax + eax * 0x8;
    eax = var_A8[0x2];
    eax = eax + ecx * 0x4 + 0x8;
    ebx = *eax[0x1];
    esi = eax;
    var_C4 = eax;
    var_98 = esi;
    var_94 = ebx;
    &var_D8 = &var_D8;
    goto loc_44c420;

loc_44c794:
    ebx = var_B4;
    if (esi == 0x0 || esi != &var_B8) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi[0x6] != var_78) {
                    ecx = &var_70;
                    sub_40f6f0();
                    edi = var_6C;
                    esi = var_70;
                    continue;
            }
            temp_7 = 0x0;
            break;
    }
    else {
            temp_7 = 0x1;
            break;
    }
    goto .l3;

loc_44c420:
    edi = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (ebx != edi) {
            if (var_B0 == var_B4[0x1]) {
                    sub_47a948();
            }
            edi = var_B0[0x3];
            var_90 = edi;
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebx == esi[0x1]) {
                    sub_47a948();
            }
            var_8C = ebx[0x6];
            eax = sub_41c1e0(&var_90);
            var_54 = *eax + 0x1f4;
            esp = esp - 0xc;
            eax = sub_41a010(&var_64, &var_54, var_D8);
            sub_401590();
            ebx = var_94;
            esi = var_98;
            eax = var_C4;
            continue;
    }
    break;

.l3:
    if (temp_7 == 0x0) {
            var_D8 = esi;
            esp = esp - 0xc;
            ecx = &var_B8;
            eax = sub_412800(&var_38, var_D8, edi, var_D0, decomp_var_cc, var_C8, var_C4, var_C0, var_BC, var_B8, var_B4, var_B0, var_AC, var_A8, var_A4, var_A0, var_9C, var_98);
            esi = *eax;
            edi = eax[0x1];
            continue;
    }
    break;
    sub_401520();
    ebx = var_A8;
    ecx = var_B4;
    continue;
    *dword_baed34 = *dword_baed34 + 0x1;
    eax = var_74 - 0x1;
    var_74 = eax;
    if (eax > 0x0) {
            continue;
    }
    temp_8 = 0x0;
    break;
}
