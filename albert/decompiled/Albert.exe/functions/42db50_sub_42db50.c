// sub_42db50 @ 0x42db50
// hopper name: sub_42db50
// contains unmarked entry 0x42dc40 (FRIENDLY)
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_42db50() {
    &decomp_var_4 = &decomp_var_4 & 0xfffffff8;
    decomp_var_10 = *0x0;
    decomp_var_50 = ebx;
    decomp_var_54 = ebp;
    decomp_var_58 = esi;
    decomp_var_5c = edi;
    esp = esp - 0x5c;
    decomp_var_60 = *dword_4c8db8 ^ &decomp_var_5c;
    *0x0 = &decomp_var_10;
    edi = ecx;
    decomp_var_40 = edi;
    decomp_var_34 = *(int8_t *)(edi[0x2] + 0x2424) & 0xff;
    eax = sub_47020b();
    if (eax != 0x0) goto loc_42dbad;
    goto loc_42dba3;

loc_42dbad:
    edx = *eax;
    decomp_var_28 = (edx[0x3])() + 0x10;
    eax = edi[0x2];
    ecx = eax[0x901];
    decomp_var_44 = 0x0;
    if (ecx <= 0x0) goto loc_42e04f;
    goto loc_42dbd6;

loc_42dba3:
    eax = sub_40b5a0(0x80004005);
    return eax;

loc_42e04f:
    sub_40d7e0();
    eax = edi[0x2];
    eax = eax[0x901];
    esi = 0x0;
    if (eax > 0x0) {
            ebp = 0x4d5528;
            edi = 0xba2888;
            do {
                    edx = 0x0;
                    if (eax > 0x0) {
                            eax = edi;
                            ecx = ebp;
                            do {
                                    bool_1008 = ecx[0x1] < 0x0;
                                    bool_1007 = ecx[0x1] > 0x0;
                                    if (!bool_1008) {
                                            if (!bool_1007) {
                                                    if (*ecx >= 0x5) {
                                                            if (*eax == 0x1) {
                                                                    *eax = 0x2;
                                                            }
                                                    }
                                                    else {
                                                            if (*eax == 0x2) {
                                                                    *eax = 0x1;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (*eax == 0x1) {
                                                            *eax = 0x2;
                                                    }
                                            }
                                    }
                                    else {
                                            if (*eax == 0x2) {
                                                    *eax = 0x1;
                                            }
                                    }
                                    edx = edx + 0x1;
                                    ecx = ecx + 0x8;
                                    eax = eax + 0x4;
                            } while (edx < *(decomp_var_40[0x2] + 0x2404));
                    }
                    edx = decomp_var_40[0x2];
                    eax = edx[0x901];
                    esi = esi + 0x1;
                    edi = edi + 0x54;
                    ebp = &arg_a4;
            } while (esi < eax);
    }
    eax = decomp_var_28 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            decomp_var_64 = eax;
            eax = *(**eax + 0x4);
            eax = (eax)(decomp_var_64);
    }
    *0x0 = decomp_var_10;
    &decomp_var_4c = decomp_var_54;
    return eax;

loc_42dbd6:
    ebx = 0x0;
    decomp_var_38 = 0x0;
    decomp_var_2c = 0x634e90;
    goto loc_42dbe2;

loc_42dbe2:
    edx = 0x0;
    decomp_var_3c = 0x0;
    if (ecx <= ebx) goto loc_42e025;
    goto loc_42dbf0;

loc_42e025:
    edi = decomp_var_40;
    goto loc_42e029;

loc_42dbf0:
    ebp = decomp_var_2c;
    edi = decomp_var_44 + decomp_var_44 + decomp_var_44 + decomp_var_44 + decomp_var_44 + decomp_var_44 + decomp_var_44 + decomp_var_44;
    decomp_var_30 = edi;
    goto loc_42dc14;

loc_42e029:
    eax = edi[0x2];
    ecx = eax[0x901];
    decomp_var_2c = decomp_var_2c + 0x4;
    decomp_var_38 = decomp_var_38 + 0x15;
    edx = decomp_var_44 + 0x1;
    decomp_var_44 = edx;
    if (edx < ecx) {
            continue;
    }
    break;

loc_42dc14:
    if (decomp_var_44 == edx) goto loc_42dffa;
    goto loc_42dc1e;

loc_42dffa:
    edi = decomp_var_40;
    eax = edi[0x2];
    decomp_var_30 = decomp_var_30 + 0xa8;
    edx = decomp_var_3c + 0x1;
    ebp = &arg_50;
    decomp_var_3c = edx;
    if (edx < eax[0x901]) {
            edi = decomp_var_30;
            continue;
    }
    break;

loc_42dc1e:
    ecx = decomp_var_38;
    if (*(edx * 0x4 + dword_623990) != ebx) goto loc_42dc71;
    goto loc_42dc2b;

loc_42dc71:
    esi = ecx + edx;
    ecx = *(esi * 0x4 + 0x62cc68);
    if (ecx != 0x1) goto loc_42dd8d;
    goto loc_42dc84;

loc_42dc2b:
    *((ecx + edx) * 0x8 + 0x4d5528) = ebx;
    *((ecx + edx) * 0x8 + 0x4d552c) = ebx;
    *((ecx + edx) * 0x8 + 0x4d4610) = ebx;
    *((ecx + edx) * 0x8 + 0x4d4614) = ebx;
    *((ecx + edx) * 0x4 + 0x634e90) = ebx;
    *ebp = ebx;
    edi[0x13554a] = ebx;
    edi[0x13554b] = ebx;
    edi[0x135184] = ebx;
    edi[0x135185] = ebx;
    goto loc_42dffa;

loc_42dd8d:
    if (*(esi * 0x4 + 0x62b0c8) != 0x1) goto loc_42ddba;
    goto loc_42dd97;

loc_42dc84:
    eax = *ebp;
    if (eax >= 0xa && *(esi * 0x4 + 0x634e90) >= 0xa) {
            edx = *(esi * 0x4 + 0x62a2f8);
            eax = esi * 0x4 + 0x634e90;
            *eax = *eax + (0xffffffba - edx + edx * 0x4 + edx + edx * 0x4 + edx + edx * 0x4 + edx + edx * 0x4);
            *ebp = *ebp + (0xffffffba - edx + edx * 0x4 + edx + edx * 0x4 + edx + edx * 0x4 + edx + edx * 0x4);
            *(esi * 0x4 + 0x62a2f8) = edx + 0x1;
            ecx = 0x0;
            if (*(decomp_var_40[0x2] + 0x2404) > ebx) {
                    do {
                            if (decomp_var_44 == decomp_var_34 && ecx != decomp_var_3c) {
                                    *(ecx * 0x8 + 0x4cf4c0) = ebx;
                                    *(ecx * 0x8 + 0x4cf4c4) = ebx;
                            }
                            ecx = ecx + 0x1;
                    } while (ecx < *(decomp_var_40[0x2] + 0x2404));
            }
    }
    else {
            if (*(esi * 0x4 + 0x6340c0) > 0x3) {
                    edx = *(esi * 0x4 + 0x62a2f8);
                    eax = esi * 0x4 + 0x634e90;
                    *eax = *eax + (0xffffffba - edx + edx * 0x4 + edx + edx * 0x4 + edx + edx * 0x4 + edx + edx * 0x4);
                    *ebp = *ebp + (0xffffffba - edx + edx * 0x4 + edx + edx * 0x4 + edx + edx * 0x4 + edx + edx * 0x4);
                    *(esi * 0x4 + 0x62a2f8) = edx + 0x1;
                    ecx = 0x0;
                    if (*(decomp_var_40[0x2] + 0x2404) > ebx) {
                            do {
                                    if (decomp_var_44 == decomp_var_34 && ecx != decomp_var_3c) {
                                            *(ecx * 0x8 + 0x4cf4c0) = ebx;
                                            *(ecx * 0x8 + 0x4cf4c4) = ebx;
                                    }
                                    ecx = ecx + 0x1;
                            } while (ecx < *(decomp_var_40[0x2] + 0x2404));
                    }
            }
            else {
                    if (eax >= 0x5) {
                            edx = *(esi * 0x4 + 0x634e90);
                            eax = esi * 0x4 + 0x634e90;
                            if (edx >= 0x5) {
                                    edi = esi * 0x4 + 0x62a2f8;
                                    esi = *edi;
                                    *eax = edx - esi + esi * 0x4 + esi + esi * 0x4 - 0xa;
                                    *ebp = *ebp + (0xfffffff6 - esi + esi * 0x4 + esi + esi * 0x4);
                                    *edi = esi + 0x1;
                            }
                            else {
                                    eax = esi * 0x4 + 0x634e90;
                                    *eax = ebx;
                                    *ebp = ebx;
                            }
                    }
                    else {
                            eax = esi * 0x4 + 0x634e90;
                            *eax = ebx;
                            *ebp = ebx;
                    }
            }
    }
    if (*eax < 0xffffffce) {
            *eax = 0xffffffce;
    }
    if (*ebp < 0xffffffce) {
            *ebp = 0xffffffce;
    }
    goto loc_42dffa;

loc_42ddba:
    if (ecx != ebx || *(esi * 0x4 + 0x62c580) != ebx || *(esi * 0x4 + 0x62be98) != ebx) goto loc_42dffa;
    goto loc_42dddc;

loc_42dd97:
    eax = esi * 0x4 + 0x634e90;
    if (*(esi * 0x4 + 0x634e90) > ebx) {
            *eax = ebx;
    }
    if (*ebp > ebx) {
            *ebp = ebx;
    }
    goto loc_42dffa;

loc_42dddc:
    eax = eax[0x1225] & 0xffff;
    if (*(int16_t *)word_4c6ccc == eax || *(int16_t *)word_4c6cd4 == eax) goto loc_42ddf9;
    goto loc_42dffa;

loc_42ddf9:
    edx = *(esi * 0x8 + 0x4d552c);
    bool_167 = edx > ebx;
    ecx = *(esi * 0x8 + 0x4d5528);
    if (edx < ebx || !bool_167 && ecx <= ebx || *(esi * 0x4 + 0x62a9e0) != 0x1 || *(esi * 0x4 + 0x62b7b0) != ebx) goto .l29;
    goto loc_42de24;

.l29:
    bool_852 = edi[0x13554b] < ebx;
    bool_290 = edi[0x13554b] > ebx;
    if (bool_852) goto .l30;
    goto loc_42de5f;

loc_42de24:
    eax = *(esi * 0x4 + 0x634e90);
    if (eax < 0x32) {
            if (*dword_baed64 == 0x1) {
                    *(esi * 0x4 + 0x634e90) = eax + 0x5;
            }
            else {
                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
            }
            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                            esp = esp - 0x4;
                            sub_46db50();
                            eax = sub_4273a0(decomp_var_64);
                            if (eax[0x6] >= 0x10) {
                                    eax = eax[0x1];
                            }
                            else {
                                    eax = eax + 0x4;
                            }
                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                            decomp_var_48 = 0x19;
                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                            esp = (esp - 0xc) + 0xc - 0x10;
                            eax = sub_41c450(&decomp_var_1c, eax);
                            sub_4106b0();
                    }
            }
            eax = esi * 0x4 + 0x634e90;
            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                    *eax = 0x32;
            }
            edi = decomp_var_40;
            eax = edi[0x2];
            decomp_var_30 = decomp_var_30 + 0xa8;
            edx = decomp_var_3c + 0x1;
            ebp = &arg_50;
            decomp_var_3c = edx;
            if (edx < eax[0x901]) {
                    edi = decomp_var_30;
                    continue;
            }
            break;
    }
    else {
            bool_918 = edi[0x13554b] > ebx;
            if (edi[0x13554b] >= ebx) {
                    if (!bool_918) {
                            if (edi[0x13554a] > ebx) {
                                    if (*(esi * 0x4 + 0x62a9e0) == ebx) {
                                            eax = *(esi * 0x4 + 0x634e90);
                                            if (eax < 0x32) {
                                                    *(esi * 0x4 + 0x634e90) = eax + 0x5;
                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                    esp = esp - 0x4;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_64);
                                                                    if (eax[0x6] >= 0x10) {
                                                                            eax = eax[0x1];
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x4;
                                                                    }
                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                    decomp_var_48 = 0x19;
                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                    sub_4106b0();
                                                            }
                                                    }
                                                    eax = esi * 0x4 + 0x634e90;
                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                            *eax = 0x32;
                                                    }
                                                    edi = decomp_var_40;
                                                    eax = edi[0x2];
                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                    edx = decomp_var_3c + 0x1;
                                                    ebp = &arg_50;
                                                    decomp_var_3c = edx;
                                                    if (edx < eax[0x901]) {
                                                            edi = decomp_var_30;
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0) {
                                                            if (*(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            if (*dword_baed64 > 0x1) {
                                                                                    if (decomp_var_44 != decomp_var_34) {
                                                                                            *(esi * 0x8 + 0x4d5528) = 0x1;
                                                                                            *(esi * 0x8 + 0x4d552c) = ebx;
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                                            esp = esp - 0x4;
                                                                                                            sub_46db50();
                                                                                                            eax = sub_4273a0(decomp_var_64);
                                                                                                            if (eax[0x6] >= 0x10) {
                                                                                                                    eax = eax[0x1];
                                                                                                            }
                                                                                                            else {
                                                                                                                    eax = eax + 0x4;
                                                                                                            }
                                                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                                            decomp_var_48 = 0x19;
                                                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                                                            sub_4106b0();
                                                                                                    }
                                                                                            }
                                                                                            eax = esi * 0x4 + 0x634e90;
                                                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                                    *eax = 0x32;
                                                                                            }
                                                                                            edi = decomp_var_40;
                                                                                            eax = edi[0x2];
                                                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                                                            edx = decomp_var_3c + 0x1;
                                                                                            ebp = &arg_50;
                                                                                            decomp_var_3c = edx;
                                                                                            if (edx < eax[0x901]) {
                                                                                                    edi = decomp_var_30;
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            if ((*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                                            esp = esp - 0x4;
                                                                                                            sub_46db50();
                                                                                                            eax = sub_4273a0(decomp_var_64);
                                                                                                            if (eax[0x6] >= 0x10) {
                                                                                                                    eax = eax[0x1];
                                                                                                            }
                                                                                                            else {
                                                                                                                    eax = eax + 0x4;
                                                                                                            }
                                                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                                            decomp_var_48 = 0x19;
                                                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                                                            sub_4106b0();
                                                                                                    }
                                                                                            }
                                                                                            eax = esi * 0x4 + 0x634e90;
                                                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                                    *eax = 0x32;
                                                                                            }
                                                                                            edi = decomp_var_40;
                                                                                            eax = edi[0x2];
                                                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                                                            edx = decomp_var_3c + 0x1;
                                                                                            ebp = &arg_50;
                                                                                            decomp_var_3c = edx;
                                                                                            if (edx < eax[0x901]) {
                                                                                                    edi = decomp_var_30;
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if ((ecx | edx) == 0x0) {
                                                                                            eax = *(esi * 0x4 + 0x634e90);
                                                                                            if (eax < ebx) {
                                                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                                                    if (eax + 0xa > ebx) {
                                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                                    esp = esp - 0x4;
                                                                                                    sub_46db50();
                                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                                    if (eax[0x6] >= 0x10) {
                                                                                                            eax = eax[0x1];
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = eax + 0x4;
                                                                                                    }
                                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                                    decomp_var_48 = 0x19;
                                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                                    sub_4106b0();
                                                                                            }
                                                                                    }
                                                                                    eax = esi * 0x4 + 0x634e90;
                                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                            *eax = 0x32;
                                                                                    }
                                                                                    edi = decomp_var_40;
                                                                                    eax = edi[0x2];
                                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                                    edx = decomp_var_3c + 0x1;
                                                                                    ebp = &arg_50;
                                                                                    decomp_var_3c = edx;
                                                                                    if (edx < eax[0x901]) {
                                                                                            edi = decomp_var_30;
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0) {
                                                                                    eax = *(esi * 0x4 + 0x634e90);
                                                                                    if (eax < ebx) {
                                                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                                            if (eax + 0xa > ebx) {
                                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                            esp = esp - 0x4;
                                                                                            sub_46db50();
                                                                                            eax = sub_4273a0(decomp_var_64);
                                                                                            if (eax[0x6] >= 0x10) {
                                                                                                    eax = eax[0x1];
                                                                                            }
                                                                                            else {
                                                                                                    eax = eax + 0x4;
                                                                                            }
                                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                            decomp_var_48 = 0x19;
                                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                                            sub_4106b0();
                                                                                    }
                                                                            }
                                                                            eax = esi * 0x4 + 0x634e90;
                                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                    *eax = 0x32;
                                                                            }
                                                                            edi = decomp_var_40;
                                                                            eax = edi[0x2];
                                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                                            edx = decomp_var_3c + 0x1;
                                                                            ebp = &arg_50;
                                                                            decomp_var_3c = edx;
                                                                            if (edx < eax[0x901]) {
                                                                                    edi = decomp_var_30;
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0) {
                                                                            eax = *(esi * 0x4 + 0x634e90);
                                                                            if (eax < ebx) {
                                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                                    if (eax + 0xa > ebx) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                    esp = esp - 0x4;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            eax = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x4;
                                                                                    }
                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                    decomp_var_48 = 0x19;
                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                    sub_4106b0();
                                                                            }
                                                                    }
                                                                    eax = esi * 0x4 + 0x634e90;
                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                            *eax = 0x32;
                                                                    }
                                                                    edi = decomp_var_40;
                                                                    eax = edi[0x2];
                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                    edx = decomp_var_3c + 0x1;
                                                                    ebp = &arg_50;
                                                                    decomp_var_3c = edx;
                                                                    if (edx < eax[0x901]) {
                                                                            edi = decomp_var_30;
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0) {
                                                                    eax = *(esi * 0x4 + 0x634e90);
                                                                    if (eax < ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                            if (eax + 0xa > ebx) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                            esp = esp - 0x4;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_64);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                            decomp_var_48 = 0x19;
                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                            sub_4106b0();
                                                                    }
                                                            }
                                                            eax = esi * 0x4 + 0x634e90;
                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                    *eax = 0x32;
                                                            }
                                                            edi = decomp_var_40;
                                                            eax = edi[0x2];
                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                            edx = decomp_var_3c + 0x1;
                                                            ebp = &arg_50;
                                                            decomp_var_3c = edx;
                                                            if (edx < eax[0x901]) {
                                                                    edi = decomp_var_30;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0) {
                                                    if (*(esi * 0x4 + 0x62b7b0) == ebx) {
                                                            if (*(esi * 0x4 + 0x634e90) >= ebx) {
                                                                    if (*dword_baed64 > 0x1) {
                                                                            if (decomp_var_44 != decomp_var_34) {
                                                                                    *(esi * 0x8 + 0x4d5528) = 0x1;
                                                                                    *(esi * 0x8 + 0x4d552c) = ebx;
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                                    esp = esp - 0x4;
                                                                                                    sub_46db50();
                                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                                    if (eax[0x6] >= 0x10) {
                                                                                                            eax = eax[0x1];
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = eax + 0x4;
                                                                                                    }
                                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                                    decomp_var_48 = 0x19;
                                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                                    sub_4106b0();
                                                                                            }
                                                                                    }
                                                                                    eax = esi * 0x4 + 0x634e90;
                                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                            *eax = 0x32;
                                                                                    }
                                                                                    edi = decomp_var_40;
                                                                                    eax = edi[0x2];
                                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                                    edx = decomp_var_3c + 0x1;
                                                                                    ebp = &arg_50;
                                                                                    decomp_var_3c = edx;
                                                                                    if (edx < eax[0x901]) {
                                                                                            edi = decomp_var_30;
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    if ((*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                                    esp = esp - 0x4;
                                                                                                    sub_46db50();
                                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                                    if (eax[0x6] >= 0x10) {
                                                                                                            eax = eax[0x1];
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = eax + 0x4;
                                                                                                    }
                                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                                    decomp_var_48 = 0x19;
                                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                                    sub_4106b0();
                                                                                            }
                                                                                    }
                                                                                    eax = esi * 0x4 + 0x634e90;
                                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                            *eax = 0x32;
                                                                                    }
                                                                                    edi = decomp_var_40;
                                                                                    eax = edi[0x2];
                                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                                    edx = decomp_var_3c + 0x1;
                                                                                    ebp = &arg_50;
                                                                                    decomp_var_3c = edx;
                                                                                    if (edx < eax[0x901]) {
                                                                                            edi = decomp_var_30;
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0) {
                                                                                    eax = *(esi * 0x4 + 0x634e90);
                                                                                    if (eax < ebx) {
                                                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                                            if (eax + 0xa > ebx) {
                                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                            esp = esp - 0x4;
                                                                                            sub_46db50();
                                                                                            eax = sub_4273a0(decomp_var_64);
                                                                                            if (eax[0x6] >= 0x10) {
                                                                                                    eax = eax[0x1];
                                                                                            }
                                                                                            else {
                                                                                                    eax = eax + 0x4;
                                                                                            }
                                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                            decomp_var_48 = 0x19;
                                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                                            sub_4106b0();
                                                                                    }
                                                                            }
                                                                            eax = esi * 0x4 + 0x634e90;
                                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                    *eax = 0x32;
                                                                            }
                                                                            edi = decomp_var_40;
                                                                            eax = edi[0x2];
                                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                                            edx = decomp_var_3c + 0x1;
                                                                            ebp = &arg_50;
                                                                            decomp_var_3c = edx;
                                                                            if (edx < eax[0x901]) {
                                                                                    edi = decomp_var_30;
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0) {
                                                                            eax = *(esi * 0x4 + 0x634e90);
                                                                            if (eax < ebx) {
                                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                                    if (eax + 0xa > ebx) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                    esp = esp - 0x4;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            eax = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x4;
                                                                                    }
                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                    decomp_var_48 = 0x19;
                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                    sub_4106b0();
                                                                            }
                                                                    }
                                                                    eax = esi * 0x4 + 0x634e90;
                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                            *eax = 0x32;
                                                                    }
                                                                    edi = decomp_var_40;
                                                                    eax = edi[0x2];
                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                    edx = decomp_var_3c + 0x1;
                                                                    ebp = &arg_50;
                                                                    decomp_var_3c = edx;
                                                                    if (edx < eax[0x901]) {
                                                                            edi = decomp_var_30;
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0) {
                                                                    eax = *(esi * 0x4 + 0x634e90);
                                                                    if (eax < ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                            if (eax + 0xa > ebx) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                            esp = esp - 0x4;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_64);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                            decomp_var_48 = 0x19;
                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                            sub_4106b0();
                                                                    }
                                                            }
                                                            eax = esi * 0x4 + 0x634e90;
                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                    *eax = 0x32;
                                                            }
                                                            edi = decomp_var_40;
                                                            eax = edi[0x2];
                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                            edx = decomp_var_3c + 0x1;
                                                            ebp = &arg_50;
                                                            decomp_var_3c = edx;
                                                            if (edx < eax[0x901]) {
                                                                    edi = decomp_var_30;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0) {
                                                            eax = *(esi * 0x4 + 0x634e90);
                                                            if (eax < ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                    if (eax + 0xa > ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                    esp = esp - 0x4;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_64);
                                                                    if (eax[0x6] >= 0x10) {
                                                                            eax = eax[0x1];
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x4;
                                                                    }
                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                    decomp_var_48 = 0x19;
                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                    sub_4106b0();
                                                            }
                                                    }
                                                    eax = esi * 0x4 + 0x634e90;
                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                            *eax = 0x32;
                                                    }
                                                    edi = decomp_var_40;
                                                    eax = edi[0x2];
                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                    edx = decomp_var_3c + 0x1;
                                                    ebp = &arg_50;
                                                    decomp_var_3c = edx;
                                                    if (edx < eax[0x901]) {
                                                            edi = decomp_var_30;
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    if ((ecx | edx) == 0x0) {
                                            if (*(esi * 0x4 + 0x62b7b0) == ebx) {
                                                    if (*(esi * 0x4 + 0x634e90) >= ebx) {
                                                            if (*dword_baed64 > 0x1) {
                                                                    if (decomp_var_44 != decomp_var_34) {
                                                                            *(esi * 0x8 + 0x4d5528) = 0x1;
                                                                            *(esi * 0x8 + 0x4d552c) = ebx;
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                            esp = esp - 0x4;
                                                                                            sub_46db50();
                                                                                            eax = sub_4273a0(decomp_var_64);
                                                                                            if (eax[0x6] >= 0x10) {
                                                                                                    eax = eax[0x1];
                                                                                            }
                                                                                            else {
                                                                                                    eax = eax + 0x4;
                                                                                            }
                                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                            decomp_var_48 = 0x19;
                                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                                            sub_4106b0();
                                                                                    }
                                                                            }
                                                                            eax = esi * 0x4 + 0x634e90;
                                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                    *eax = 0x32;
                                                                            }
                                                                            edi = decomp_var_40;
                                                                            eax = edi[0x2];
                                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                                            edx = decomp_var_3c + 0x1;
                                                                            ebp = &arg_50;
                                                                            decomp_var_3c = edx;
                                                                            if (edx < eax[0x901]) {
                                                                                    edi = decomp_var_30;
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            if ((*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                            esp = esp - 0x4;
                                                                                            sub_46db50();
                                                                                            eax = sub_4273a0(decomp_var_64);
                                                                                            if (eax[0x6] >= 0x10) {
                                                                                                    eax = eax[0x1];
                                                                                            }
                                                                                            else {
                                                                                                    eax = eax + 0x4;
                                                                                            }
                                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                            decomp_var_48 = 0x19;
                                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                                            sub_4106b0();
                                                                                    }
                                                                            }
                                                                            eax = esi * 0x4 + 0x634e90;
                                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                    *eax = 0x32;
                                                                            }
                                                                            edi = decomp_var_40;
                                                                            eax = edi[0x2];
                                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                                            edx = decomp_var_3c + 0x1;
                                                                            ebp = &arg_50;
                                                                            decomp_var_3c = edx;
                                                                            if (edx < eax[0x901]) {
                                                                                    edi = decomp_var_30;
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0) {
                                                                            eax = *(esi * 0x4 + 0x634e90);
                                                                            if (eax < ebx) {
                                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                                    if (eax + 0xa > ebx) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                    esp = esp - 0x4;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            eax = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x4;
                                                                                    }
                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                    decomp_var_48 = 0x19;
                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                    sub_4106b0();
                                                                            }
                                                                    }
                                                                    eax = esi * 0x4 + 0x634e90;
                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                            *eax = 0x32;
                                                                    }
                                                                    edi = decomp_var_40;
                                                                    eax = edi[0x2];
                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                    edx = decomp_var_3c + 0x1;
                                                                    ebp = &arg_50;
                                                                    decomp_var_3c = edx;
                                                                    if (edx < eax[0x901]) {
                                                                            edi = decomp_var_30;
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0) {
                                                                    eax = *(esi * 0x4 + 0x634e90);
                                                                    if (eax < ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                            if (eax + 0xa > ebx) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                            esp = esp - 0x4;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_64);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                            decomp_var_48 = 0x19;
                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                            sub_4106b0();
                                                                    }
                                                            }
                                                            eax = esi * 0x4 + 0x634e90;
                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                    *eax = 0x32;
                                                            }
                                                            edi = decomp_var_40;
                                                            eax = edi[0x2];
                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                            edx = decomp_var_3c + 0x1;
                                                            ebp = &arg_50;
                                                            decomp_var_3c = edx;
                                                            if (edx < eax[0x901]) {
                                                                    edi = decomp_var_30;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0) {
                                                            eax = *(esi * 0x4 + 0x634e90);
                                                            if (eax < ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                    if (eax + 0xa > ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                    esp = esp - 0x4;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_64);
                                                                    if (eax[0x6] >= 0x10) {
                                                                            eax = eax[0x1];
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x4;
                                                                    }
                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                    decomp_var_48 = 0x19;
                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                    sub_4106b0();
                                                            }
                                                    }
                                                    eax = esi * 0x4 + 0x634e90;
                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                            *eax = 0x32;
                                                    }
                                                    edi = decomp_var_40;
                                                    eax = edi[0x2];
                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                    edx = decomp_var_3c + 0x1;
                                                    ebp = &arg_50;
                                                    decomp_var_3c = edx;
                                                    if (edx < eax[0x901]) {
                                                            edi = decomp_var_30;
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0) {
                                                    eax = *(esi * 0x4 + 0x634e90);
                                                    if (eax < ebx) {
                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                            if (eax + 0xa > ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                            }
                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                            esp = esp - 0x4;
                                                            sub_46db50();
                                                            eax = sub_4273a0(decomp_var_64);
                                                            if (eax[0x6] >= 0x10) {
                                                                    eax = eax[0x1];
                                                            }
                                                            else {
                                                                    eax = eax + 0x4;
                                                            }
                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                            decomp_var_48 = 0x19;
                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                            sub_4106b0();
                                                    }
                                            }
                                            eax = esi * 0x4 + 0x634e90;
                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                    *eax = 0x32;
                                            }
                                            edi = decomp_var_40;
                                            eax = edi[0x2];
                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                            edx = decomp_var_3c + 0x1;
                                            ebp = &arg_50;
                                            decomp_var_3c = edx;
                                            if (edx < eax[0x901]) {
                                                    edi = decomp_var_30;
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                    }
                    else {
                            if (*(esi * 0x4 + 0x62a9e0) == ebx) {
                                    eax = *(esi * 0x4 + 0x634e90);
                                    if (eax < 0x32) {
                                            *(esi * 0x4 + 0x634e90) = eax + 0x5;
                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                            esp = esp - 0x4;
                                                            sub_46db50();
                                                            eax = sub_4273a0(decomp_var_64);
                                                            if (eax[0x6] >= 0x10) {
                                                                    eax = eax[0x1];
                                                            }
                                                            else {
                                                                    eax = eax + 0x4;
                                                            }
                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                            decomp_var_48 = 0x19;
                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                            sub_4106b0();
                                                    }
                                            }
                                            eax = esi * 0x4 + 0x634e90;
                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                    *eax = 0x32;
                                            }
                                            edi = decomp_var_40;
                                            eax = edi[0x2];
                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                            edx = decomp_var_3c + 0x1;
                                            ebp = &arg_50;
                                            decomp_var_3c = edx;
                                            if (edx < eax[0x901]) {
                                                    edi = decomp_var_30;
                                                    continue;
                                            }
                                            break;
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0) {
                                                    if (*(esi * 0x4 + 0x62b7b0) == ebx) {
                                                            if (*(esi * 0x4 + 0x634e90) >= ebx) {
                                                                    if (*dword_baed64 > 0x1) {
                                                                            if (decomp_var_44 != decomp_var_34) {
                                                                                    *(esi * 0x8 + 0x4d5528) = 0x1;
                                                                                    *(esi * 0x8 + 0x4d552c) = ebx;
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx && *(esi * 0x4 + 0x62a9e0) == 0x1) {
                                                                                            if (*(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                                    esp = esp - 0x4;
                                                                                                    sub_46db50();
                                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                                    if (eax[0x6] >= 0x10) {
                                                                                                            eax = eax[0x1];
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = eax + 0x4;
                                                                                                    }
                                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                                    decomp_var_48 = 0x19;
                                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                                    sub_4106b0();
                                                                                            }
                                                                                    }
                                                                                    eax = esi * 0x4 + 0x634e90;
                                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                            *eax = 0x32;
                                                                                    }
                                                                                    edi = decomp_var_40;
                                                                                    eax = edi[0x2];
                                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                                    edx = decomp_var_3c + 0x1;
                                                                                    ebp = &arg_50;
                                                                                    decomp_var_3c = edx;
                                                                                    if (edx < eax[0x901]) {
                                                                                            edi = decomp_var_30;
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    if ((*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                                    esp = esp - 0x4;
                                                                                                    sub_46db50();
                                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                                    if (eax[0x6] >= 0x10) {
                                                                                                            eax = eax[0x1];
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = eax + 0x4;
                                                                                                    }
                                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                                    decomp_var_48 = 0x19;
                                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                                    sub_4106b0();
                                                                                            }
                                                                                    }
                                                                                    eax = esi * 0x4 + 0x634e90;
                                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                            *eax = 0x32;
                                                                                    }
                                                                                    edi = decomp_var_40;
                                                                                    eax = edi[0x2];
                                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                                    edx = decomp_var_3c + 0x1;
                                                                                    ebp = &arg_50;
                                                                                    decomp_var_3c = edx;
                                                                                    if (edx < eax[0x901]) {
                                                                                            edi = decomp_var_30;
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0) {
                                                                                    eax = *(esi * 0x4 + 0x634e90);
                                                                                    if (eax < ebx) {
                                                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                                            if (eax + 0xa > ebx) {
                                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                            esp = esp - 0x4;
                                                                                            sub_46db50();
                                                                                            eax = sub_4273a0(decomp_var_64);
                                                                                            if (eax[0x6] >= 0x10) {
                                                                                                    eax = eax[0x1];
                                                                                            }
                                                                                            else {
                                                                                                    eax = eax + 0x4;
                                                                                            }
                                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                            decomp_var_48 = 0x19;
                                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                                            sub_4106b0();
                                                                                    }
                                                                            }
                                                                            eax = esi * 0x4 + 0x634e90;
                                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                    *eax = 0x32;
                                                                            }
                                                                            edi = decomp_var_40;
                                                                            eax = edi[0x2];
                                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                                            edx = decomp_var_3c + 0x1;
                                                                            ebp = &arg_50;
                                                                            decomp_var_3c = edx;
                                                                            if (edx < eax[0x901]) {
                                                                                    edi = decomp_var_30;
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0) {
                                                                            eax = *(esi * 0x4 + 0x634e90);
                                                                            if (eax < ebx) {
                                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                                    if (eax + 0xa > ebx) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                    esp = esp - 0x4;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            eax = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x4;
                                                                                    }
                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                    decomp_var_48 = 0x19;
                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                    sub_4106b0();
                                                                            }
                                                                    }
                                                                    eax = esi * 0x4 + 0x634e90;
                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                            *eax = 0x32;
                                                                    }
                                                                    edi = decomp_var_40;
                                                                    eax = edi[0x2];
                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                    edx = decomp_var_3c + 0x1;
                                                                    ebp = &arg_50;
                                                                    decomp_var_3c = edx;
                                                                    if (edx < eax[0x901]) {
                                                                            edi = decomp_var_30;
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0) {
                                                                    eax = *(esi * 0x4 + 0x634e90);
                                                                    if (eax < ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                            if (eax + 0xa > ebx) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                            esp = esp - 0x4;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_64);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                            decomp_var_48 = 0x19;
                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                            sub_4106b0();
                                                                    }
                                                            }
                                                            eax = esi * 0x4 + 0x634e90;
                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                    *eax = 0x32;
                                                            }
                                                            edi = decomp_var_40;
                                                            eax = edi[0x2];
                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                            edx = decomp_var_3c + 0x1;
                                                            ebp = &arg_50;
                                                            decomp_var_3c = edx;
                                                            if (edx < eax[0x901]) {
                                                                    edi = decomp_var_30;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0) {
                                                            eax = *(esi * 0x4 + 0x634e90);
                                                            if (eax < ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                    if (eax + 0xa > ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                    esp = esp - 0x4;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_64);
                                                                    if (eax[0x6] >= 0x10) {
                                                                            eax = eax[0x1];
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x4;
                                                                    }
                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                    decomp_var_48 = 0x19;
                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                    sub_4106b0();
                                                            }
                                                    }
                                                    eax = esi * 0x4 + 0x634e90;
                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                            *eax = 0x32;
                                                    }
                                                    edi = decomp_var_40;
                                                    eax = edi[0x2];
                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                    edx = decomp_var_3c + 0x1;
                                                    ebp = &arg_50;
                                                    decomp_var_3c = edx;
                                                    if (edx < eax[0x901]) {
                                                            edi = decomp_var_30;
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    if ((ecx | edx) == 0x0) {
                                            if (*(esi * 0x4 + 0x62b7b0) == ebx) {
                                                    if (*(esi * 0x4 + 0x634e90) >= ebx) {
                                                            if (*dword_baed64 > 0x1) {
                                                                    if (decomp_var_44 != decomp_var_34) {
                                                                            *(esi * 0x8 + 0x4d5528) = 0x1;
                                                                            *(esi * 0x8 + 0x4d552c) = ebx;
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                            esp = esp - 0x4;
                                                                                            sub_46db50();
                                                                                            eax = sub_4273a0(decomp_var_64);
                                                                                            if (eax[0x6] >= 0x10) {
                                                                                                    eax = eax[0x1];
                                                                                            }
                                                                                            else {
                                                                                                    eax = eax + 0x4;
                                                                                            }
                                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                            decomp_var_48 = 0x19;
                                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                                            sub_4106b0();
                                                                                    }
                                                                            }
                                                                            eax = esi * 0x4 + 0x634e90;
                                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                    *eax = 0x32;
                                                                            }
                                                                            edi = decomp_var_40;
                                                                            eax = edi[0x2];
                                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                                            edx = decomp_var_3c + 0x1;
                                                                            ebp = &arg_50;
                                                                            decomp_var_3c = edx;
                                                                            if (edx < eax[0x901]) {
                                                                                    edi = decomp_var_30;
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            if ((*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                            esp = esp - 0x4;
                                                                                            sub_46db50();
                                                                                            eax = sub_4273a0(decomp_var_64);
                                                                                            if (eax[0x6] >= 0x10) {
                                                                                                    eax = eax[0x1];
                                                                                            }
                                                                                            else {
                                                                                                    eax = eax + 0x4;
                                                                                            }
                                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                            decomp_var_48 = 0x19;
                                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                                            sub_4106b0();
                                                                                    }
                                                                            }
                                                                            eax = esi * 0x4 + 0x634e90;
                                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                    *eax = 0x32;
                                                                            }
                                                                            edi = decomp_var_40;
                                                                            eax = edi[0x2];
                                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                                            edx = decomp_var_3c + 0x1;
                                                                            ebp = &arg_50;
                                                                            decomp_var_3c = edx;
                                                                            if (edx < eax[0x901]) {
                                                                                    edi = decomp_var_30;
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0) {
                                                                            eax = *(esi * 0x4 + 0x634e90);
                                                                            if (eax < ebx) {
                                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                                    if (eax + 0xa > ebx) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                    esp = esp - 0x4;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            eax = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x4;
                                                                                    }
                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                    decomp_var_48 = 0x19;
                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                    sub_4106b0();
                                                                            }
                                                                    }
                                                                    eax = esi * 0x4 + 0x634e90;
                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                            *eax = 0x32;
                                                                    }
                                                                    edi = decomp_var_40;
                                                                    eax = edi[0x2];
                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                    edx = decomp_var_3c + 0x1;
                                                                    ebp = &arg_50;
                                                                    decomp_var_3c = edx;
                                                                    if (edx < eax[0x901]) {
                                                                            edi = decomp_var_30;
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0) {
                                                                    eax = *(esi * 0x4 + 0x634e90);
                                                                    if (eax < ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                            if (eax + 0xa > ebx) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                            esp = esp - 0x4;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_64);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                            decomp_var_48 = 0x19;
                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                            sub_4106b0();
                                                                    }
                                                            }
                                                            eax = esi * 0x4 + 0x634e90;
                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                    *eax = 0x32;
                                                            }
                                                            edi = decomp_var_40;
                                                            eax = edi[0x2];
                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                            edx = decomp_var_3c + 0x1;
                                                            ebp = &arg_50;
                                                            decomp_var_3c = edx;
                                                            if (edx < eax[0x901]) {
                                                                    edi = decomp_var_30;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0) {
                                                            eax = *(esi * 0x4 + 0x634e90);
                                                            if (eax < ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                    if (eax + 0xa > ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                    esp = esp - 0x4;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_64);
                                                                    if (eax[0x6] >= 0x10) {
                                                                            eax = eax[0x1];
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x4;
                                                                    }
                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                    decomp_var_48 = 0x19;
                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                    sub_4106b0();
                                                            }
                                                    }
                                                    eax = esi * 0x4 + 0x634e90;
                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                            *eax = 0x32;
                                                    }
                                                    edi = decomp_var_40;
                                                    eax = edi[0x2];
                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                    edx = decomp_var_3c + 0x1;
                                                    ebp = &arg_50;
                                                    decomp_var_3c = edx;
                                                    if (edx < eax[0x901]) {
                                                            edi = decomp_var_30;
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0) {
                                                    eax = *(esi * 0x4 + 0x634e90);
                                                    if (eax < ebx) {
                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                            if (eax + 0xa > ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                            }
                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                            esp = esp - 0x4;
                                                            sub_46db50();
                                                            eax = sub_4273a0(decomp_var_64);
                                                            if (eax[0x6] >= 0x10) {
                                                                    eax = eax[0x1];
                                                            }
                                                            else {
                                                                    eax = eax + 0x4;
                                                            }
                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                            decomp_var_48 = 0x19;
                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                            sub_4106b0();
                                                    }
                                            }
                                            eax = esi * 0x4 + 0x634e90;
                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                    *eax = 0x32;
                                            }
                                            edi = decomp_var_40;
                                            eax = edi[0x2];
                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                            edx = decomp_var_3c + 0x1;
                                            ebp = &arg_50;
                                            decomp_var_3c = edx;
                                            if (edx < eax[0x901]) {
                                                    edi = decomp_var_30;
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                    }
            }
            else {
                    if ((ecx | edx) == 0x0) {
                            if (*(esi * 0x4 + 0x62b7b0) == ebx) {
                                    if (*(esi * 0x4 + 0x634e90) >= ebx) {
                                            if (*dword_baed64 > 0x1) {
                                                    if (decomp_var_44 != decomp_var_34) {
                                                            *(esi * 0x8 + 0x4d5528) = 0x1;
                                                            *(esi * 0x8 + 0x4d552c) = ebx;
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                            esp = esp - 0x4;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_64);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                            decomp_var_48 = 0x19;
                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                            sub_4106b0();
                                                                    }
                                                            }
                                                            eax = esi * 0x4 + 0x634e90;
                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                    *eax = 0x32;
                                                            }
                                                            edi = decomp_var_40;
                                                            eax = edi[0x2];
                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                            edx = decomp_var_3c + 0x1;
                                                            ebp = &arg_50;
                                                            decomp_var_3c = edx;
                                                            if (edx < eax[0x901]) {
                                                                    edi = decomp_var_30;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            if ((*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                            esp = esp - 0x4;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_64);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                            decomp_var_48 = 0x19;
                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                            sub_4106b0();
                                                                    }
                                                            }
                                                            eax = esi * 0x4 + 0x634e90;
                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                    *eax = 0x32;
                                                            }
                                                            edi = decomp_var_40;
                                                            eax = edi[0x2];
                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                            edx = decomp_var_3c + 0x1;
                                                            ebp = &arg_50;
                                                            decomp_var_3c = edx;
                                                            if (edx < eax[0x901]) {
                                                                    edi = decomp_var_30;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0) {
                                                            eax = *(esi * 0x4 + 0x634e90);
                                                            if (eax < ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                    if (eax + 0xa > ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                    esp = esp - 0x4;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_64);
                                                                    if (eax[0x6] >= 0x10) {
                                                                            eax = eax[0x1];
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x4;
                                                                    }
                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                    decomp_var_48 = 0x19;
                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                    sub_4106b0();
                                                            }
                                                    }
                                                    eax = esi * 0x4 + 0x634e90;
                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                            *eax = 0x32;
                                                    }
                                                    edi = decomp_var_40;
                                                    eax = edi[0x2];
                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                    edx = decomp_var_3c + 0x1;
                                                    ebp = &arg_50;
                                                    decomp_var_3c = edx;
                                                    if (edx < eax[0x901]) {
                                                            edi = decomp_var_30;
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0) {
                                                    eax = *(esi * 0x4 + 0x634e90);
                                                    if (eax < ebx) {
                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                            if (eax + 0xa > ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                            }
                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                            esp = esp - 0x4;
                                                            sub_46db50();
                                                            eax = sub_4273a0(decomp_var_64);
                                                            if (eax[0x6] >= 0x10) {
                                                                    eax = eax[0x1];
                                                            }
                                                            else {
                                                                    eax = eax + 0x4;
                                                            }
                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                            decomp_var_48 = 0x19;
                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                            sub_4106b0();
                                                    }
                                            }
                                            eax = esi * 0x4 + 0x634e90;
                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                    *eax = 0x32;
                                            }
                                            edi = decomp_var_40;
                                            eax = edi[0x2];
                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                            edx = decomp_var_3c + 0x1;
                                            ebp = &arg_50;
                                            decomp_var_3c = edx;
                                            if (edx < eax[0x901]) {
                                                    edi = decomp_var_30;
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    if ((ecx | edx) == 0x0) {
                                            eax = *(esi * 0x4 + 0x634e90);
                                            if (eax < ebx) {
                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                    if (eax + 0xa > ebx) {
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                    }
                                            }
                                    }
                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                    esp = esp - 0x4;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_64);
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                    decomp_var_48 = 0x19;
                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                    sub_4106b0();
                                            }
                                    }
                                    eax = esi * 0x4 + 0x634e90;
                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                            *eax = 0x32;
                                    }
                                    edi = decomp_var_40;
                                    eax = edi[0x2];
                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                    edx = decomp_var_3c + 0x1;
                                    ebp = &arg_50;
                                    decomp_var_3c = edx;
                                    if (edx < eax[0x901]) {
                                            edi = decomp_var_30;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if ((ecx | edx) == 0x0) {
                                    eax = *(esi * 0x4 + 0x634e90);
                                    if (eax < ebx) {
                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                            if (eax + 0xa > ebx) {
                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                            }
                                    }
                            }
                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                            esp = esp - 0x4;
                                            sub_46db50();
                                            eax = sub_4273a0(decomp_var_64);
                                            if (eax[0x6] >= 0x10) {
                                                    eax = eax[0x1];
                                            }
                                            else {
                                                    eax = eax + 0x4;
                                            }
                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                            decomp_var_48 = 0x19;
                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                            esp = (esp - 0xc) + 0xc - 0x10;
                                            eax = sub_41c450(&decomp_var_1c, eax);
                                            sub_4106b0();
                                    }
                            }
                            eax = esi * 0x4 + 0x634e90;
                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                    *eax = 0x32;
                            }
                            edi = decomp_var_40;
                            eax = edi[0x2];
                            decomp_var_30 = decomp_var_30 + 0xa8;
                            edx = decomp_var_3c + 0x1;
                            ebp = &arg_50;
                            decomp_var_3c = edx;
                            if (edx < eax[0x901]) {
                                    edi = decomp_var_30;
                                    continue;
                            }
                            break;
                    }
            }
    }
    goto loc_42e029;

.l30:
    if ((ecx | edx) != 0x0) goto .l33;
    goto loc_42de93;

loc_42de5f:
    if (!bool_290) {
            if (edi[0x13554a] > ebx) {
                    if (*(esi * 0x4 + 0x62a9e0) == ebx) {
                            eax = *(esi * 0x4 + 0x634e90);
                            if (eax < 0x32) {
                                    *(esi * 0x4 + 0x634e90) = eax + 0x5;
                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                    esp = esp - 0x4;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_64);
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                    decomp_var_48 = 0x19;
                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                    sub_4106b0();
                                            }
                                    }
                                    eax = esi * 0x4 + 0x634e90;
                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                            *eax = 0x32;
                                    }
                                    edi = decomp_var_40;
                                    eax = edi[0x2];
                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                    edx = decomp_var_3c + 0x1;
                                    ebp = &arg_50;
                                    decomp_var_3c = edx;
                                    if (edx < eax[0x901]) {
                                            edi = decomp_var_30;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if ((ecx | edx) == 0x0) {
                                            if (*(esi * 0x4 + 0x62b7b0) == ebx) {
                                                    if (*(esi * 0x4 + 0x634e90) >= ebx) {
                                                            if (*dword_baed64 > 0x1) {
                                                                    if (decomp_var_44 != decomp_var_34) {
                                                                            *(esi * 0x8 + 0x4d5528) = 0x1;
                                                                            *(esi * 0x8 + 0x4d552c) = ebx;
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                            esp = esp - 0x4;
                                                                                            sub_46db50();
                                                                                            eax = sub_4273a0(decomp_var_64);
                                                                                            if (eax[0x6] >= 0x10) {
                                                                                                    eax = eax[0x1];
                                                                                            }
                                                                                            else {
                                                                                                    eax = eax + 0x4;
                                                                                            }
                                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                            decomp_var_48 = 0x19;
                                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                                            sub_4106b0();
                                                                                    }
                                                                            }
                                                                            eax = esi * 0x4 + 0x634e90;
                                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                    *eax = 0x32;
                                                                            }
                                                                            edi = decomp_var_40;
                                                                            eax = edi[0x2];
                                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                                            edx = decomp_var_3c + 0x1;
                                                                            ebp = &arg_50;
                                                                            decomp_var_3c = edx;
                                                                            if (edx < eax[0x901]) {
                                                                                    edi = decomp_var_30;
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            if ((*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                            esp = esp - 0x4;
                                                                                            sub_46db50();
                                                                                            eax = sub_4273a0(decomp_var_64);
                                                                                            if (eax[0x6] >= 0x10) {
                                                                                                    eax = eax[0x1];
                                                                                            }
                                                                                            else {
                                                                                                    eax = eax + 0x4;
                                                                                            }
                                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                            decomp_var_48 = 0x19;
                                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                                            sub_4106b0();
                                                                                    }
                                                                            }
                                                                            eax = esi * 0x4 + 0x634e90;
                                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                                    *eax = 0x32;
                                                                            }
                                                                            edi = decomp_var_40;
                                                                            eax = edi[0x2];
                                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                                            edx = decomp_var_3c + 0x1;
                                                                            ebp = &arg_50;
                                                                            decomp_var_3c = edx;
                                                                            if (edx < eax[0x901]) {
                                                                                    edi = decomp_var_30;
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0) {
                                                                            eax = *(esi * 0x4 + 0x634e90);
                                                                            if (eax < ebx) {
                                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                                    if (eax + 0xa > ebx) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                    esp = esp - 0x4;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            eax = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x4;
                                                                                    }
                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                    decomp_var_48 = 0x19;
                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                    sub_4106b0();
                                                                            }
                                                                    }
                                                                    eax = esi * 0x4 + 0x634e90;
                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                            *eax = 0x32;
                                                                    }
                                                                    edi = decomp_var_40;
                                                                    eax = edi[0x2];
                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                    edx = decomp_var_3c + 0x1;
                                                                    ebp = &arg_50;
                                                                    decomp_var_3c = edx;
                                                                    if (edx < eax[0x901]) {
                                                                            edi = decomp_var_30;
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0) {
                                                                    eax = *(esi * 0x4 + 0x634e90);
                                                                    if (eax < ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                            if (eax + 0xa > ebx) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                            esp = esp - 0x4;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_64);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                            decomp_var_48 = 0x19;
                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                            sub_4106b0();
                                                                    }
                                                            }
                                                            eax = esi * 0x4 + 0x634e90;
                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                    *eax = 0x32;
                                                            }
                                                            edi = decomp_var_40;
                                                            eax = edi[0x2];
                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                            edx = decomp_var_3c + 0x1;
                                                            ebp = &arg_50;
                                                            decomp_var_3c = edx;
                                                            if (edx < eax[0x901]) {
                                                                    edi = decomp_var_30;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0) {
                                                            eax = *(esi * 0x4 + 0x634e90);
                                                            if (eax < ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                    if (eax + 0xa > ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                    esp = esp - 0x4;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_64);
                                                                    if (eax[0x6] >= 0x10) {
                                                                            eax = eax[0x1];
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x4;
                                                                    }
                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                    decomp_var_48 = 0x19;
                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                    sub_4106b0();
                                                            }
                                                    }
                                                    eax = esi * 0x4 + 0x634e90;
                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                            *eax = 0x32;
                                                    }
                                                    edi = decomp_var_40;
                                                    eax = edi[0x2];
                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                    edx = decomp_var_3c + 0x1;
                                                    ebp = &arg_50;
                                                    decomp_var_3c = edx;
                                                    if (edx < eax[0x901]) {
                                                            edi = decomp_var_30;
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0) {
                                                    eax = *(esi * 0x4 + 0x634e90);
                                                    if (eax < ebx) {
                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                            if (eax + 0xa > ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                            }
                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                            esp = esp - 0x4;
                                                            sub_46db50();
                                                            eax = sub_4273a0(decomp_var_64);
                                                            if (eax[0x6] >= 0x10) {
                                                                    eax = eax[0x1];
                                                            }
                                                            else {
                                                                    eax = eax + 0x4;
                                                            }
                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                            decomp_var_48 = 0x19;
                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                            sub_4106b0();
                                                    }
                                            }
                                            eax = esi * 0x4 + 0x634e90;
                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                    *eax = 0x32;
                                            }
                                            edi = decomp_var_40;
                                            eax = edi[0x2];
                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                            edx = decomp_var_3c + 0x1;
                                            ebp = &arg_50;
                                            decomp_var_3c = edx;
                                            if (edx < eax[0x901]) {
                                                    edi = decomp_var_30;
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                    }
                    else {
                            if ((ecx | edx) == 0x0) {
                                    if (*(esi * 0x4 + 0x62b7b0) == ebx) {
                                            if (*(esi * 0x4 + 0x634e90) >= ebx) {
                                                    if (*dword_baed64 > 0x1) {
                                                            if (decomp_var_44 != decomp_var_34) {
                                                                    *(esi * 0x8 + 0x4d5528) = 0x1;
                                                                    *(esi * 0x8 + 0x4d552c) = ebx;
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                    esp = esp - 0x4;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            eax = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x4;
                                                                                    }
                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                    decomp_var_48 = 0x19;
                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                    sub_4106b0();
                                                                            }
                                                                    }
                                                                    eax = esi * 0x4 + 0x634e90;
                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                            *eax = 0x32;
                                                                    }
                                                                    edi = decomp_var_40;
                                                                    eax = edi[0x2];
                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                    edx = decomp_var_3c + 0x1;
                                                                    ebp = &arg_50;
                                                                    decomp_var_3c = edx;
                                                                    if (edx < eax[0x901]) {
                                                                            edi = decomp_var_30;
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    if ((*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                    esp = esp - 0x4;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            eax = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x4;
                                                                                    }
                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                    decomp_var_48 = 0x19;
                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                    sub_4106b0();
                                                                            }
                                                                    }
                                                                    eax = esi * 0x4 + 0x634e90;
                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                            *eax = 0x32;
                                                                    }
                                                                    edi = decomp_var_40;
                                                                    eax = edi[0x2];
                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                    edx = decomp_var_3c + 0x1;
                                                                    ebp = &arg_50;
                                                                    decomp_var_3c = edx;
                                                                    if (edx < eax[0x901]) {
                                                                            edi = decomp_var_30;
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0) {
                                                                    eax = *(esi * 0x4 + 0x634e90);
                                                                    if (eax < ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                            if (eax + 0xa > ebx) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                            esp = esp - 0x4;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_64);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                            decomp_var_48 = 0x19;
                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                            sub_4106b0();
                                                                    }
                                                            }
                                                            eax = esi * 0x4 + 0x634e90;
                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                    *eax = 0x32;
                                                            }
                                                            edi = decomp_var_40;
                                                            eax = edi[0x2];
                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                            edx = decomp_var_3c + 0x1;
                                                            ebp = &arg_50;
                                                            decomp_var_3c = edx;
                                                            if (edx < eax[0x901]) {
                                                                    edi = decomp_var_30;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0) {
                                                            eax = *(esi * 0x4 + 0x634e90);
                                                            if (eax < ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                    if (eax + 0xa > ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                    esp = esp - 0x4;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_64);
                                                                    if (eax[0x6] >= 0x10) {
                                                                            eax = eax[0x1];
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x4;
                                                                    }
                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                    decomp_var_48 = 0x19;
                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                    sub_4106b0();
                                                            }
                                                    }
                                                    eax = esi * 0x4 + 0x634e90;
                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                            *eax = 0x32;
                                                    }
                                                    edi = decomp_var_40;
                                                    eax = edi[0x2];
                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                    edx = decomp_var_3c + 0x1;
                                                    ebp = &arg_50;
                                                    decomp_var_3c = edx;
                                                    if (edx < eax[0x901]) {
                                                            edi = decomp_var_30;
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0) {
                                                    eax = *(esi * 0x4 + 0x634e90);
                                                    if (eax < ebx) {
                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                            if (eax + 0xa > ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                            }
                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                            esp = esp - 0x4;
                                                            sub_46db50();
                                                            eax = sub_4273a0(decomp_var_64);
                                                            if (eax[0x6] >= 0x10) {
                                                                    eax = eax[0x1];
                                                            }
                                                            else {
                                                                    eax = eax + 0x4;
                                                            }
                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                            decomp_var_48 = 0x19;
                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                            sub_4106b0();
                                                    }
                                            }
                                            eax = esi * 0x4 + 0x634e90;
                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                    *eax = 0x32;
                                            }
                                            edi = decomp_var_40;
                                            eax = edi[0x2];
                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                            edx = decomp_var_3c + 0x1;
                                            ebp = &arg_50;
                                            decomp_var_3c = edx;
                                            if (edx < eax[0x901]) {
                                                    edi = decomp_var_30;
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    if ((ecx | edx) == 0x0) {
                                            eax = *(esi * 0x4 + 0x634e90);
                                            if (eax < ebx) {
                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                    if (eax + 0xa > ebx) {
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                    }
                                            }
                                    }
                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                    esp = esp - 0x4;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_64);
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                    decomp_var_48 = 0x19;
                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                    sub_4106b0();
                                            }
                                    }
                                    eax = esi * 0x4 + 0x634e90;
                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                            *eax = 0x32;
                                    }
                                    edi = decomp_var_40;
                                    eax = edi[0x2];
                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                    edx = decomp_var_3c + 0x1;
                                    ebp = &arg_50;
                                    decomp_var_3c = edx;
                                    if (edx < eax[0x901]) {
                                            edi = decomp_var_30;
                                            continue;
                                    }
                                    break;
                            }
                    }
            }
            else {
                    if ((ecx | edx) == 0x0) {
                            if (*(esi * 0x4 + 0x62b7b0) == ebx) {
                                    if (*(esi * 0x4 + 0x634e90) >= ebx) {
                                            if (*dword_baed64 > 0x1) {
                                                    if (decomp_var_44 != decomp_var_34) {
                                                            *(esi * 0x8 + 0x4d5528) = 0x1;
                                                            *(esi * 0x8 + 0x4d552c) = ebx;
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                            esp = esp - 0x4;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_64);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                            decomp_var_48 = 0x19;
                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                            sub_4106b0();
                                                                    }
                                                            }
                                                            eax = esi * 0x4 + 0x634e90;
                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                    *eax = 0x32;
                                                            }
                                                            edi = decomp_var_40;
                                                            eax = edi[0x2];
                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                            edx = decomp_var_3c + 0x1;
                                                            ebp = &arg_50;
                                                            decomp_var_3c = edx;
                                                            if (edx < eax[0x901]) {
                                                                    edi = decomp_var_30;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            if ((*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                            esp = esp - 0x4;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_64);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                            decomp_var_48 = 0x19;
                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                            sub_4106b0();
                                                                    }
                                                            }
                                                            eax = esi * 0x4 + 0x634e90;
                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                    *eax = 0x32;
                                                            }
                                                            edi = decomp_var_40;
                                                            eax = edi[0x2];
                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                            edx = decomp_var_3c + 0x1;
                                                            ebp = &arg_50;
                                                            decomp_var_3c = edx;
                                                            if (edx < eax[0x901]) {
                                                                    edi = decomp_var_30;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0) {
                                                            eax = *(esi * 0x4 + 0x634e90);
                                                            if (eax < ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                    if (eax + 0xa > ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                    esp = esp - 0x4;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_64);
                                                                    if (eax[0x6] >= 0x10) {
                                                                            eax = eax[0x1];
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x4;
                                                                    }
                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                    decomp_var_48 = 0x19;
                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                    sub_4106b0();
                                                            }
                                                    }
                                                    eax = esi * 0x4 + 0x634e90;
                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                            *eax = 0x32;
                                                    }
                                                    edi = decomp_var_40;
                                                    eax = edi[0x2];
                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                    edx = decomp_var_3c + 0x1;
                                                    ebp = &arg_50;
                                                    decomp_var_3c = edx;
                                                    if (edx < eax[0x901]) {
                                                            edi = decomp_var_30;
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0) {
                                                    eax = *(esi * 0x4 + 0x634e90);
                                                    if (eax < ebx) {
                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                            if (eax + 0xa > ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                            }
                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                            esp = esp - 0x4;
                                                            sub_46db50();
                                                            eax = sub_4273a0(decomp_var_64);
                                                            if (eax[0x6] >= 0x10) {
                                                                    eax = eax[0x1];
                                                            }
                                                            else {
                                                                    eax = eax + 0x4;
                                                            }
                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                            decomp_var_48 = 0x19;
                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                            sub_4106b0();
                                                    }
                                            }
                                            eax = esi * 0x4 + 0x634e90;
                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                    *eax = 0x32;
                                            }
                                            edi = decomp_var_40;
                                            eax = edi[0x2];
                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                            edx = decomp_var_3c + 0x1;
                                            ebp = &arg_50;
                                            decomp_var_3c = edx;
                                            if (edx < eax[0x901]) {
                                                    edi = decomp_var_30;
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    if ((ecx | edx) == 0x0) {
                                            eax = *(esi * 0x4 + 0x634e90);
                                            if (eax < ebx) {
                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                    if (eax + 0xa > ebx) {
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                    }
                                            }
                                    }
                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                    esp = esp - 0x4;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_64);
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                    decomp_var_48 = 0x19;
                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                    sub_4106b0();
                                            }
                                    }
                                    eax = esi * 0x4 + 0x634e90;
                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                            *eax = 0x32;
                                    }
                                    edi = decomp_var_40;
                                    eax = edi[0x2];
                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                    edx = decomp_var_3c + 0x1;
                                    ebp = &arg_50;
                                    decomp_var_3c = edx;
                                    if (edx < eax[0x901]) {
                                            edi = decomp_var_30;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if ((ecx | edx) == 0x0) {
                                    eax = *(esi * 0x4 + 0x634e90);
                                    if (eax < ebx) {
                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                            if (eax + 0xa > ebx) {
                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                            }
                                    }
                            }
                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                            esp = esp - 0x4;
                                            sub_46db50();
                                            eax = sub_4273a0(decomp_var_64);
                                            if (eax[0x6] >= 0x10) {
                                                    eax = eax[0x1];
                                            }
                                            else {
                                                    eax = eax + 0x4;
                                            }
                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                            decomp_var_48 = 0x19;
                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                            esp = (esp - 0xc) + 0xc - 0x10;
                                            eax = sub_41c450(&decomp_var_1c, eax);
                                            sub_4106b0();
                                    }
                            }
                            eax = esi * 0x4 + 0x634e90;
                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                    *eax = 0x32;
                            }
                            edi = decomp_var_40;
                            eax = edi[0x2];
                            decomp_var_30 = decomp_var_30 + 0xa8;
                            edx = decomp_var_3c + 0x1;
                            ebp = &arg_50;
                            decomp_var_3c = edx;
                            if (edx < eax[0x901]) {
                                    edi = decomp_var_30;
                                    continue;
                            }
                            break;
                    }
            }
    }
    else {
            if (*(esi * 0x4 + 0x62a9e0) == ebx) {
                    eax = *(esi * 0x4 + 0x634e90);
                    if (eax < 0x32) {
                            *(esi * 0x4 + 0x634e90) = eax + 0x5;
                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                            esp = esp - 0x4;
                                            sub_46db50();
                                            eax = sub_4273a0(decomp_var_64);
                                            if (eax[0x6] >= 0x10) {
                                                    eax = eax[0x1];
                                            }
                                            else {
                                                    eax = eax + 0x4;
                                            }
                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                            decomp_var_48 = 0x19;
                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                            esp = (esp - 0xc) + 0xc - 0x10;
                                            eax = sub_41c450(&decomp_var_1c, eax);
                                            sub_4106b0();
                                    }
                            }
                            eax = esi * 0x4 + 0x634e90;
                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                    *eax = 0x32;
                            }
                            edi = decomp_var_40;
                            eax = edi[0x2];
                            decomp_var_30 = decomp_var_30 + 0xa8;
                            edx = decomp_var_3c + 0x1;
                            ebp = &arg_50;
                            decomp_var_3c = edx;
                            if (edx < eax[0x901]) {
                                    edi = decomp_var_30;
                                    continue;
                            }
                            break;
                    }
                    else {
                            if ((ecx | edx) == 0x0) {
                                    if (*(esi * 0x4 + 0x62b7b0) == ebx) {
                                            if (*(esi * 0x4 + 0x634e90) >= ebx) {
                                                    if (*dword_baed64 > 0x1) {
                                                            if (decomp_var_44 != decomp_var_34) {
                                                                    *(esi * 0x8 + 0x4d5528) = 0x1;
                                                                    *(esi * 0x8 + 0x4d552c) = ebx;
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                    esp = esp - 0x4;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            eax = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x4;
                                                                                    }
                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                    decomp_var_48 = 0x19;
                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                    sub_4106b0();
                                                                            }
                                                                    }
                                                                    eax = esi * 0x4 + 0x634e90;
                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                            *eax = 0x32;
                                                                    }
                                                                    edi = decomp_var_40;
                                                                    eax = edi[0x2];
                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                    edx = decomp_var_3c + 0x1;
                                                                    ebp = &arg_50;
                                                                    decomp_var_3c = edx;
                                                                    if (edx < eax[0x901]) {
                                                                            edi = decomp_var_30;
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    if ((*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                                    esp = esp - 0x4;
                                                                                    sub_46db50();
                                                                                    eax = sub_4273a0(decomp_var_64);
                                                                                    if (eax[0x6] >= 0x10) {
                                                                                            eax = eax[0x1];
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x4;
                                                                                    }
                                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                                    decomp_var_48 = 0x19;
                                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                                    sub_4106b0();
                                                                            }
                                                                    }
                                                                    eax = esi * 0x4 + 0x634e90;
                                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                            *eax = 0x32;
                                                                    }
                                                                    edi = decomp_var_40;
                                                                    eax = edi[0x2];
                                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                                    edx = decomp_var_3c + 0x1;
                                                                    ebp = &arg_50;
                                                                    decomp_var_3c = edx;
                                                                    if (edx < eax[0x901]) {
                                                                            edi = decomp_var_30;
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0) {
                                                                    eax = *(esi * 0x4 + 0x634e90);
                                                                    if (eax < ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                            if (eax + 0xa > ebx) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                            esp = esp - 0x4;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_64);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                            decomp_var_48 = 0x19;
                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                            sub_4106b0();
                                                                    }
                                                            }
                                                            eax = esi * 0x4 + 0x634e90;
                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                    *eax = 0x32;
                                                            }
                                                            edi = decomp_var_40;
                                                            eax = edi[0x2];
                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                            edx = decomp_var_3c + 0x1;
                                                            ebp = &arg_50;
                                                            decomp_var_3c = edx;
                                                            if (edx < eax[0x901]) {
                                                                    edi = decomp_var_30;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0) {
                                                            eax = *(esi * 0x4 + 0x634e90);
                                                            if (eax < ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                    if (eax + 0xa > ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                    esp = esp - 0x4;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_64);
                                                                    if (eax[0x6] >= 0x10) {
                                                                            eax = eax[0x1];
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x4;
                                                                    }
                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                    decomp_var_48 = 0x19;
                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                    sub_4106b0();
                                                            }
                                                    }
                                                    eax = esi * 0x4 + 0x634e90;
                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                            *eax = 0x32;
                                                    }
                                                    edi = decomp_var_40;
                                                    eax = edi[0x2];
                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                    edx = decomp_var_3c + 0x1;
                                                    ebp = &arg_50;
                                                    decomp_var_3c = edx;
                                                    if (edx < eax[0x901]) {
                                                            edi = decomp_var_30;
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0) {
                                                    eax = *(esi * 0x4 + 0x634e90);
                                                    if (eax < ebx) {
                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                            if (eax + 0xa > ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                            }
                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                            esp = esp - 0x4;
                                                            sub_46db50();
                                                            eax = sub_4273a0(decomp_var_64);
                                                            if (eax[0x6] >= 0x10) {
                                                                    eax = eax[0x1];
                                                            }
                                                            else {
                                                                    eax = eax + 0x4;
                                                            }
                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                            decomp_var_48 = 0x19;
                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                            sub_4106b0();
                                                    }
                                            }
                                            eax = esi * 0x4 + 0x634e90;
                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                    *eax = 0x32;
                                            }
                                            edi = decomp_var_40;
                                            eax = edi[0x2];
                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                            edx = decomp_var_3c + 0x1;
                                            ebp = &arg_50;
                                            decomp_var_3c = edx;
                                            if (edx < eax[0x901]) {
                                                    edi = decomp_var_30;
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    if ((ecx | edx) == 0x0) {
                                            eax = *(esi * 0x4 + 0x634e90);
                                            if (eax < ebx) {
                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                    if (eax + 0xa > ebx) {
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                    }
                                            }
                                    }
                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                    esp = esp - 0x4;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_64);
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                    decomp_var_48 = 0x19;
                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                    sub_4106b0();
                                            }
                                    }
                                    eax = esi * 0x4 + 0x634e90;
                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                            *eax = 0x32;
                                    }
                                    edi = decomp_var_40;
                                    eax = edi[0x2];
                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                    edx = decomp_var_3c + 0x1;
                                    ebp = &arg_50;
                                    decomp_var_3c = edx;
                                    if (edx < eax[0x901]) {
                                            edi = decomp_var_30;
                                            continue;
                                    }
                                    break;
                            }
                    }
            }
            else {
                    if ((ecx | edx) == 0x0) {
                            if (*(esi * 0x4 + 0x62b7b0) == ebx) {
                                    if (*(esi * 0x4 + 0x634e90) >= ebx) {
                                            if (*dword_baed64 > 0x1) {
                                                    if (decomp_var_44 != decomp_var_34) {
                                                            *(esi * 0x8 + 0x4d5528) = 0x1;
                                                            *(esi * 0x8 + 0x4d552c) = ebx;
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                            esp = esp - 0x4;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_64);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                            decomp_var_48 = 0x19;
                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                            sub_4106b0();
                                                                    }
                                                            }
                                                            eax = esi * 0x4 + 0x634e90;
                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                    *eax = 0x32;
                                                            }
                                                            edi = decomp_var_40;
                                                            eax = edi[0x2];
                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                            edx = decomp_var_3c + 0x1;
                                                            ebp = &arg_50;
                                                            decomp_var_3c = edx;
                                                            if (edx < eax[0x901]) {
                                                                    edi = decomp_var_30;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            if ((*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                            esp = esp - 0x4;
                                                                            sub_46db50();
                                                                            eax = sub_4273a0(decomp_var_64);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                            decomp_var_48 = 0x19;
                                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                                            sub_4106b0();
                                                                    }
                                                            }
                                                            eax = esi * 0x4 + 0x634e90;
                                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                                    *eax = 0x32;
                                                            }
                                                            edi = decomp_var_40;
                                                            eax = edi[0x2];
                                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                                            edx = decomp_var_3c + 0x1;
                                                            ebp = &arg_50;
                                                            decomp_var_3c = edx;
                                                            if (edx < eax[0x901]) {
                                                                    edi = decomp_var_30;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0) {
                                                            eax = *(esi * 0x4 + 0x634e90);
                                                            if (eax < ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                                    if (eax + 0xa > ebx) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                                    esp = esp - 0x4;
                                                                    sub_46db50();
                                                                    eax = sub_4273a0(decomp_var_64);
                                                                    if (eax[0x6] >= 0x10) {
                                                                            eax = eax[0x1];
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x4;
                                                                    }
                                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                                    decomp_var_48 = 0x19;
                                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                                    sub_4106b0();
                                                            }
                                                    }
                                                    eax = esi * 0x4 + 0x634e90;
                                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                            *eax = 0x32;
                                                    }
                                                    edi = decomp_var_40;
                                                    eax = edi[0x2];
                                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                                    edx = decomp_var_3c + 0x1;
                                                    ebp = &arg_50;
                                                    decomp_var_3c = edx;
                                                    if (edx < eax[0x901]) {
                                                            edi = decomp_var_30;
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0) {
                                                    eax = *(esi * 0x4 + 0x634e90);
                                                    if (eax < ebx) {
                                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                            if (eax + 0xa > ebx) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                            }
                                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                            esp = esp - 0x4;
                                                            sub_46db50();
                                                            eax = sub_4273a0(decomp_var_64);
                                                            if (eax[0x6] >= 0x10) {
                                                                    eax = eax[0x1];
                                                            }
                                                            else {
                                                                    eax = eax + 0x4;
                                                            }
                                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                            decomp_var_48 = 0x19;
                                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                            esp = (esp - 0xc) + 0xc - 0x10;
                                                            eax = sub_41c450(&decomp_var_1c, eax);
                                                            sub_4106b0();
                                                    }
                                            }
                                            eax = esi * 0x4 + 0x634e90;
                                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                                    *eax = 0x32;
                                            }
                                            edi = decomp_var_40;
                                            eax = edi[0x2];
                                            decomp_var_30 = decomp_var_30 + 0xa8;
                                            edx = decomp_var_3c + 0x1;
                                            ebp = &arg_50;
                                            decomp_var_3c = edx;
                                            if (edx < eax[0x901]) {
                                                    edi = decomp_var_30;
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    if ((ecx | edx) == 0x0) {
                                            eax = *(esi * 0x4 + 0x634e90);
                                            if (eax < ebx) {
                                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                                    if (eax + 0xa > ebx) {
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                    }
                                            }
                                            else {
                                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                    }
                                            }
                                    }
                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                    esp = esp - 0x4;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_64);
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                    decomp_var_48 = 0x19;
                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                    sub_4106b0();
                                            }
                                    }
                                    eax = esi * 0x4 + 0x634e90;
                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                            *eax = 0x32;
                                    }
                                    edi = decomp_var_40;
                                    eax = edi[0x2];
                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                    edx = decomp_var_3c + 0x1;
                                    ebp = &arg_50;
                                    decomp_var_3c = edx;
                                    if (edx < eax[0x901]) {
                                            edi = decomp_var_30;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if ((ecx | edx) == 0x0) {
                                    eax = *(esi * 0x4 + 0x634e90);
                                    if (eax < ebx) {
                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                            if (eax + 0xa > ebx) {
                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                            }
                                    }
                            }
                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                            esp = esp - 0x4;
                                            sub_46db50();
                                            eax = sub_4273a0(decomp_var_64);
                                            if (eax[0x6] >= 0x10) {
                                                    eax = eax[0x1];
                                            }
                                            else {
                                                    eax = eax + 0x4;
                                            }
                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                            decomp_var_48 = 0x19;
                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                            esp = (esp - 0xc) + 0xc - 0x10;
                                            eax = sub_41c450(&decomp_var_1c, eax);
                                            sub_4106b0();
                                    }
                            }
                            eax = esi * 0x4 + 0x634e90;
                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                    *eax = 0x32;
                            }
                            edi = decomp_var_40;
                            eax = edi[0x2];
                            decomp_var_30 = decomp_var_30 + 0xa8;
                            edx = decomp_var_3c + 0x1;
                            ebp = &arg_50;
                            decomp_var_3c = edx;
                            if (edx < eax[0x901]) {
                                    edi = decomp_var_30;
                                    continue;
                            }
                            break;
                    }
            }
    }
    goto loc_42e029;

.l33:
    if ((ecx | edx) == 0x0) {
            eax = *(esi * 0x4 + 0x634e90);
            if (eax < ebx) {
                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                    if (eax + 0xa > ebx) {
                            *(esi * 0x4 + 0x634e90) = ebx;
                    }
            }
            else {
                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                    *(esi * 0x4 + 0x634e90) = ebx;
                            }
                    }
            }
    }
    else {
            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                            *(esi * 0x4 + 0x634e90) = ebx;
                    }
            }
    }
    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                    esp = esp - 0x4;
                    sub_46db50();
                    eax = sub_4273a0(decomp_var_64);
                    if (eax[0x6] >= 0x10) {
                            eax = eax[0x1];
                    }
                    else {
                            eax = eax + 0x4;
                    }
                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                    decomp_var_48 = 0x19;
                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                    esp = (esp - 0xc) + 0xc - 0x10;
                    eax = sub_41c450(&decomp_var_1c, eax);
                    sub_4106b0();
            }
    }
    eax = esi * 0x4 + 0x634e90;
    if (*(esi * 0x4 + 0x634e90) > 0x32) {
            *eax = 0x32;
    }
    goto loc_42dffa;

loc_42de93:
    if (*(esi * 0x4 + 0x62b7b0) == ebx) {
            if (*(esi * 0x4 + 0x634e90) >= ebx) {
                    if (*dword_baed64 > 0x1) {
                            if (decomp_var_44 != decomp_var_34) {
                                    *(esi * 0x8 + 0x4d5528) = 0x1;
                                    *(esi * 0x8 + 0x4d552c) = ebx;
                                    *(esi * 0x4 + 0x634e90) = ebx;
                                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                    esp = esp - 0x4;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_64);
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                    decomp_var_48 = 0x19;
                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                    sub_4106b0();
                                            }
                                    }
                                    eax = esi * 0x4 + 0x634e90;
                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                            *eax = 0x32;
                                    }
                                    edi = decomp_var_40;
                                    eax = edi[0x2];
                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                    edx = decomp_var_3c + 0x1;
                                    ebp = &arg_50;
                                    decomp_var_3c = edx;
                                    if (edx < eax[0x901]) {
                                            edi = decomp_var_30;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if ((*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                                    esp = esp - 0x4;
                                                    sub_46db50();
                                                    eax = sub_4273a0(decomp_var_64);
                                                    if (eax[0x6] >= 0x10) {
                                                            eax = eax[0x1];
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                    }
                                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                                    decomp_var_48 = 0x19;
                                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                                    esp = (esp - 0xc) + 0xc - 0x10;
                                                    eax = sub_41c450(&decomp_var_1c, eax);
                                                    sub_4106b0();
                                            }
                                    }
                                    eax = esi * 0x4 + 0x634e90;
                                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                            *eax = 0x32;
                                    }
                                    edi = decomp_var_40;
                                    eax = edi[0x2];
                                    decomp_var_30 = decomp_var_30 + 0xa8;
                                    edx = decomp_var_3c + 0x1;
                                    ebp = &arg_50;
                                    decomp_var_3c = edx;
                                    if (edx < eax[0x901]) {
                                            edi = decomp_var_30;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if ((ecx | edx) == 0x0) {
                                    eax = *(esi * 0x4 + 0x634e90);
                                    if (eax < ebx) {
                                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                            if (eax + 0xa > ebx) {
                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                            }
                                    }
                                    else {
                                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                            *(esi * 0x4 + 0x634e90) = ebx;
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                            }
                                    }
                            }
                            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                            esp = esp - 0x4;
                                            sub_46db50();
                                            eax = sub_4273a0(decomp_var_64);
                                            if (eax[0x6] >= 0x10) {
                                                    eax = eax[0x1];
                                            }
                                            else {
                                                    eax = eax + 0x4;
                                            }
                                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                            decomp_var_48 = 0x19;
                                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                            esp = (esp - 0xc) + 0xc - 0x10;
                                            eax = sub_41c450(&decomp_var_1c, eax);
                                            sub_4106b0();
                                    }
                            }
                            eax = esi * 0x4 + 0x634e90;
                            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                                    *eax = 0x32;
                            }
                            edi = decomp_var_40;
                            eax = edi[0x2];
                            decomp_var_30 = decomp_var_30 + 0xa8;
                            edx = decomp_var_3c + 0x1;
                            ebp = &arg_50;
                            decomp_var_3c = edx;
                            if (edx < eax[0x901]) {
                                    edi = decomp_var_30;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    if ((ecx | edx) == 0x0) {
                            eax = *(esi * 0x4 + 0x634e90);
                            if (eax < ebx) {
                                    *(esi * 0x4 + 0x634e90) = eax + 0xa;
                                    if (eax + 0xa > ebx) {
                                            *(esi * 0x4 + 0x634e90) = ebx;
                                    }
                            }
                            else {
                                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                                    *(esi * 0x4 + 0x634e90) = ebx;
                                            }
                                    }
                            }
                    }
                    else {
                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                            *(esi * 0x4 + 0x634e90) = ebx;
                                    }
                            }
                    }
                    if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                            if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                                    *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                                    *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                                    esp = esp - 0x4;
                                    sub_46db50();
                                    eax = sub_4273a0(decomp_var_64);
                                    if (eax[0x6] >= 0x10) {
                                            eax = eax[0x1];
                                    }
                                    else {
                                            eax = eax + 0x4;
                                    }
                                    sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                                    decomp_var_48 = 0x19;
                                    eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                                    esp = (esp - 0xc) + 0xc - 0x10;
                                    eax = sub_41c450(&decomp_var_1c, eax);
                                    sub_4106b0();
                            }
                    }
                    eax = esi * 0x4 + 0x634e90;
                    if (*(esi * 0x4 + 0x634e90) > 0x32) {
                            *eax = 0x32;
                    }
                    edi = decomp_var_40;
                    eax = edi[0x2];
                    decomp_var_30 = decomp_var_30 + 0xa8;
                    edx = decomp_var_3c + 0x1;
                    ebp = &arg_50;
                    decomp_var_3c = edx;
                    if (edx < eax[0x901]) {
                            edi = decomp_var_30;
                            continue;
                    }
                    break;
            }
    }
    else {
            if ((ecx | edx) == 0x0) {
                    eax = *(esi * 0x4 + 0x634e90);
                    if (eax < ebx) {
                            *(esi * 0x4 + 0x634e90) = eax + 0xa;
                            if (eax + 0xa > ebx) {
                                    *(esi * 0x4 + 0x634e90) = ebx;
                            }
                    }
                    else {
                            if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                                    if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                            *(esi * 0x4 + 0x634e90) = ebx;
                                    }
                            }
                    }
            }
            else {
                    if ((ecx | edx) == 0x0 && *(esi * 0x4 + 0x634e90) > ebx) {
                            if (*(esi * 0x4 + 0x62b7b0) == 0x1) {
                                    *(esi * 0x4 + 0x634e90) = ebx;
                            }
                    }
            }
            if (decomp_var_44 == decomp_var_34 && (*(esi * 0x8 + 0x4d5528) | *(esi * 0x8 + 0x4d552c)) == 0x0 && *(esi * 0x4 + 0x62b7b0) == ebx) {
                    if (*(esi * 0x4 + 0x62a9e0) == 0x1 && *(esi * 0x4 + 0x634e90) >= ebx) {
                            *(decomp_var_3c * 0x8 + 0x4cf4c0) = ebx;
                            *(decomp_var_3c * 0x8 + 0x4cf4c4) = ebx;
                            esp = esp - 0x4;
                            sub_46db50();
                            eax = sub_4273a0(decomp_var_64);
                            if (eax[0x6] >= 0x10) {
                                    eax = eax[0x1];
                            }
                            else {
                                    eax = eax + 0x4;
                            }
                            sub_410c10(&decomp_var_28, "I think we are getting a peace signal from (%s)", eax);
                            decomp_var_48 = 0x19;
                            eax = sub_410b40(&decomp_var_48, &decomp_var_28);
                            esp = (esp - 0xc) + 0xc - 0x10;
                            eax = sub_41c450(&decomp_var_1c, eax);
                            sub_4106b0();
                    }
            }
            eax = esi * 0x4 + 0x634e90;
            if (*(esi * 0x4 + 0x634e90) > 0x32) {
                    *eax = 0x32;
            }
            edi = decomp_var_40;
            eax = edi[0x2];
            decomp_var_30 = decomp_var_30 + 0xa8;
            edx = decomp_var_3c + 0x1;
            ebp = &arg_50;
            decomp_var_3c = edx;
            if (edx < eax[0x901]) {
                    edi = decomp_var_30;
                    continue;
            }
            break;
    }
    goto loc_42e029;
}
