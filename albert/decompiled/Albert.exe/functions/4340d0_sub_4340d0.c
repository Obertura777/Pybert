// sub_4340d0 @ 0x4340d0
// hopper name: sub_4340d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_84a29276878deed2f6f82f4902efd1af3068bd2f0c5f74171e6c8513865ea0d2
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4340d0() {
    &decomp_var_4 = &decomp_var_4 & 0xfffffff8;
    decomp_var_10 = *0x0;
    decomp_var_46c = ebp;
    decomp_var_470 = esi;
    decomp_var_474 = edi;
    esp = esp - 0x474;
    decomp_var_478 = *dword_4c8db8 ^ &decomp_var_474;
    *0x0 = &decomp_var_10;
    esi = ecx;
    eax = sub_47020b();
    if (eax == 0x0) {
            esp = esp - 0x4;
            decomp_var_47c = 0x80004005;
            eax = sub_40b5a0(0x80004005);
    }
    decomp_var_42c = (*(*eax + 0xc))() + 0x10;
    eax = 0x0;
    ebp = ebp | 0xffffffff;
    if (*(esi[0x2] + 0x2400) > 0x0) {
            do {
                    *(eax * 0x8 + 0x4d2610) = ebp;
                    *(eax * 0x8 + 0x4d2614) = ebp;
                    *(eax * 0x8 + 0x4d2e10) = ebp;
                    *(eax * 0x8 + 0x4d2e14) = ebp;
                    *(eax * 0x8 + 0x4d3610) = ebp;
                    *(eax * 0x8 + 0x4d3614) = ebp;
                    *(eax * 0x8 + 0x4d3e10) = ebp;
                    *(eax * 0x8 + 0x4d3e14) = ebp;
                    eax = eax + 0x1;
            } while (eax < *(esi[0x2] + 0x2400));
    }
    edi = 0x0;
    eax = esi[0x2];
    ecx = 0x0;
    if (eax[0x900] > 0x0) {
            do {
                    if (*(int8_t *)(eax + edi + 0x3) != 0x0) {
                            eax = *(int16_t *)(eax + edi + 0x20);
                            bool_87 = HIBYTE(eax) == 0x41;
                            eax = eax & 0xff;
                            if (!bool_87) {
                                    eax = 0x14;
                            }
                            *(ecx * 0x8 + 0x4d3610) = 0xfffffffe;
                            *(ecx * 0x8 + 0x4d3614) = ebp;
                            if (eax != 0x14) {
                                    *(ecx * 0x8 + 0x4d2610) = eax;
                                    *(ecx * 0x8 + 0x4d2614) = eax & 0x80000000 ? 0xffffffff : 0x0;
                            }
                    }
                    eax = esi[0x2];
                    ecx = ecx + 0x1;
                    edi = edi + 0x24;
            } while (ecx < eax[0x900]);
    }
    eax = esi[0x2];
    edi = eax + 0x2450;
    ebp = *eax[0x915];
    decomp_var_450 = edi;
    decomp_var_44c = ebp;
    goto loc_434220;

loc_434220:
    eax = esi[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (edi == 0x0 || edi != eax) {
            eax = sub_47a948();
    }
    if (ebp != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebp == edi[0x1]) {
                    sub_47a948();
                    if (ebp == edi[0x1]) {
                            sub_47a948();
                    }
            }
            *(arg_c * 0x8 + 0x4d2e10) = arg_14;
            *(arg_c * 0x8 + 0x4d2e14) = arg_14 & 0x80000000 ? 0xffffffff : 0x0;
            sub_401390();
            ebp = decomp_var_44c;
            edi = decomp_var_450;
            continue;
    }
    break;
    if (*(int8_t *)byte_baed69 != 0x0) goto loc_434a39;
    goto loc_434291;

loc_434a39:
    if (*dword_baed64 >= 0x2) goto loc_43505e;
    goto loc_434a46;

loc_434291:
    edx = decomp_var_464;
    eax = edx[0x2];
    decomp_var_444 = 0x0;
    if (eax[0x900] <= 0x0) goto loc_434411;
    goto loc_4342aa;

loc_43505e:
    edx = decomp_var_464;
    eax = edx[0x2];
    ecx = eax[0x1225] & 0xffff;
    if (*(int16_t *)word_4c6cc4 != ecx) {
            if (*(int16_t *)word_4c6ccc == ecx) {
                    esi = 0x0;
                    if (eax[0x900] > 0x0) {
                            do {
                                    eax = esi * 0x8;
                                    eax[0x134384] = eax[0x134984];
                                    eax[0x134385] = eax[0x134985];
                                    eax[0x134584] = eax[0x134b84];
                                    eax[0x134585] = eax[0x134b85];
                                    eax[0x134784] = eax[0x134d84];
                                    eax[0x134785] = eax[0x134d85];
                                    ecx = 0x0;
                                    if (*(edx[0x2] + 0x2404) > 0x0) {
                                            &decomp_var_47c = &decomp_var_47c;
                                            do {
                                                    eax[0x17663a] = eax[0x17903a];
                                                    eax[0x17663b] = eax[0x17903b];
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x800;
                                            } while (ecx < *(edx[0x2] + 0x2404));
                                    }
                                    esi = esi + 0x1;
                            } while (esi < *(edx[0x2] + 0x2400));
                    }
            }
    }
    else {
            esi = 0x0;
            if (eax[0x900] > 0x0) {
                    do {
                            eax = esi * 0x8;
                            eax[0x134384] = eax[0x134984];
                            eax[0x134385] = eax[0x134985];
                            eax[0x134584] = eax[0x134b84];
                            eax[0x134585] = eax[0x134b85];
                            eax[0x134784] = eax[0x134d84];
                            eax[0x134785] = eax[0x134d85];
                            ecx = 0x0;
                            if (*(edx[0x2] + 0x2404) > 0x0) {
                                    &decomp_var_47c = &decomp_var_47c;
                                    do {
                                            eax[0x17663a] = eax[0x17903a];
                                            eax[0x17663b] = eax[0x17903b];
                                            ecx = ecx + 0x1;
                                            eax = eax + 0x800;
                                    } while (ecx < *(edx[0x2] + 0x2404));
                            }
                            esi = esi + 0x1;
                    } while (esi < *(edx[0x2] + 0x2400));
            }
    }
    ecx = edx[0x2];
    eax = ecx[0x1225] & 0xffff;
    if (*(int16_t *)word_4c6cc8 != eax) {
            if (*(int16_t *)word_4c6cd0 == eax) {
                    if (ecx[0x900] > 0x0) {
                            sub_435160();
                    }
                    eax = decomp_var_42c - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    *0x0 = decomp_var_14;
                    &decomp_var_468 = decomp_var_470;
            }
            else {
                    eax = decomp_var_42c - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    *0x0 = decomp_var_14;
                    &decomp_var_468 = decomp_var_470;
            }
    }
    else {
            if (ecx[0x900] > 0x0) {
                    sub_435160();
            }
            eax = decomp_var_42c - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
            if (ecx <= 0x1) {
                    esp = esp - 0x4;
                    (*(**eax + 0x4))(eax);
            }
            *0x0 = decomp_var_14;
            &decomp_var_468 = decomp_var_470;
    }
    return;

loc_434a46:
    if (*(int8_t *)byte_baed45 != 0x1) goto .l2;
    goto loc_434a53;

loc_434411:
    eax = edx[0x2];
    decomp_var_454 = 0x0;
    if (eax[0x901] <= 0x0) goto loc_434561;
    goto loc_434429;

loc_4342aa:
    ecx = 0x0;
    decomp_var_460 = 0x0;
    ebx = edx + 0x2a1c;
    goto loc_4342b4;

.l2:
    edx = decomp_var_464;
    eax = edx[0x2];
    ecx = eax[0x1225] & 0xffff;
    if (*(int16_t *)word_4c6cc4 != ecx) {
            if (*(int16_t *)word_4c6ccc == ecx) {
                    esi = 0x0;
                    if (eax[0x900] > 0x0) {
                            do {
                                    eax = esi * 0x8;
                                    eax[0x134384] = eax[0x134984];
                                    eax[0x134385] = eax[0x134985];
                                    eax[0x134584] = eax[0x134b84];
                                    eax[0x134585] = eax[0x134b85];
                                    eax[0x134784] = eax[0x134d84];
                                    eax[0x134785] = eax[0x134d85];
                                    ecx = 0x0;
                                    if (*(edx[0x2] + 0x2404) > 0x0) {
                                            &decomp_var_47c = &decomp_var_47c;
                                            do {
                                                    eax[0x17663a] = eax[0x17903a];
                                                    eax[0x17663b] = eax[0x17903b];
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x800;
                                            } while (ecx < *(edx[0x2] + 0x2404));
                                    }
                                    esi = esi + 0x1;
                            } while (esi < *(edx[0x2] + 0x2400));
                    }
            }
    }
    else {
            esi = 0x0;
            if (eax[0x900] > 0x0) {
                    do {
                            eax = esi * 0x8;
                            eax[0x134384] = eax[0x134984];
                            eax[0x134385] = eax[0x134985];
                            eax[0x134584] = eax[0x134b84];
                            eax[0x134585] = eax[0x134b85];
                            eax[0x134784] = eax[0x134d84];
                            eax[0x134785] = eax[0x134d85];
                            ecx = 0x0;
                            if (*(edx[0x2] + 0x2404) > 0x0) {
                                    &decomp_var_47c = &decomp_var_47c;
                                    do {
                                            eax[0x17663a] = eax[0x17903a];
                                            eax[0x17663b] = eax[0x17903b];
                                            ecx = ecx + 0x1;
                                            eax = eax + 0x800;
                                    } while (ecx < *(edx[0x2] + 0x2404));
                            }
                            esi = esi + 0x1;
                    } while (esi < *(edx[0x2] + 0x2400));
            }
    }
    ecx = edx[0x2];
    eax = ecx[0x1225] & 0xffff;
    if (*(int16_t *)word_4c6cc8 != eax) {
            if (*(int16_t *)word_4c6cd0 == eax) {
                    if (ecx[0x900] > 0x0) {
                            sub_435160();
                    }
                    eax = decomp_var_42c - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    *0x0 = decomp_var_14;
                    &decomp_var_468 = decomp_var_470;
            }
            else {
                    eax = decomp_var_42c - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    *0x0 = decomp_var_14;
                    &decomp_var_468 = decomp_var_470;
            }
    }
    else {
            if (ecx[0x900] > 0x0) {
                    sub_435160();
            }
            eax = decomp_var_42c - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
            if (ecx <= 0x1) {
                    esp = esp - 0x4;
                    (*(**eax + 0x4))(eax);
            }
            *0x0 = decomp_var_14;
            &decomp_var_468 = decomp_var_470;
    }
    return;

loc_434a53:
    edx = decomp_var_464;
    esi = edx[0x2];
    ecx = esi[0x900];
    bool_32 = true;
    if (ecx > 0x0) {
            asm { rep stosd  dword [edi], eax };
    }
    edi = esi + 0x2450;
    esi = *esi[0x915];
    decomp_var_450 = edi;
    decomp_var_44c = esi;
    goto .l30;

loc_434561:
    eax = decomp_var_464[0x2];
    ecx = eax[0x901];
    decomp_var_454 = 0x0;
    if (ecx <= 0x0) goto loc_43472b;
    goto loc_43457e;

loc_434429:
    decomp_var_45c = 0x0;
    goto loc_434431;

loc_4342b4:
    if (*(int8_t *)(eax + ecx + 0x3) == 0x0) goto loc_4343ed;
    goto loc_4342bf;

.l30:
    eax = edx[0x2];
    ebp = eax[0x915];
    eax = eax + 0x2450;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
            edx = decomp_var_464;
    }
    if (esi == ebp) goto .l32;
    goto .l29;

loc_43472b:
    eax = decomp_var_464[0x2];
    if (eax[0x901] <= 0x0) goto .l3;
    goto loc_434748;

loc_43457e:
    decomp_var_460 = 0x0;
    decomp_var_45c = 0x0;
    goto loc_434590;

loc_434431:
    decomp_var_444 = 0x0;
    if (eax[0x900] <= 0x0) goto loc_43453b;
    goto loc_434446;

loc_4343ed:
    eax = edx[0x2];
    ecx = ecx + 0x24;
    ebx = ebx + 0xc;
    bool_299 = decomp_var_444 + 0x1 < eax[0x900];
    decomp_var_444 = decomp_var_444 + 0x1;
    decomp_var_460 = ecx;
    if (bool_299) {
            continue;
    }
    break;

loc_4342bf:
    eax = *(int16_t *)(eax + ecx + 0x20);
    if (HIBYTE(eax) != 0x41) goto loc_4343ed;
    goto loc_4342cd;

.l32:
    break;

.l29:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != decomp_var_428) {
            sub_401390();
            esi = decomp_var_44c;
            edi = decomp_var_450;
            edx = decomp_var_464;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    edx = esi + 0x14;
    esp = esp - 0x4;
    ebp = sub_4075b0(edx, decomp_var_47c);
    edi = *arg_0;
    esi = ebp;
    decomp_var_438 = esi;
    decomp_var_434 = edi;
    goto .l33;

.l3:
    if (*dword_baed64 >= 0x2) goto .l11;
    goto .l9;

loc_434748:
    sub_434760();
    return;

loc_434590:
    decomp_var_448 = 0x0;
    if (ecx <= 0x0) goto loc_4346fe;
    goto loc_4345a0;

loc_43453b:
    eax = decomp_var_464[0x2];
    decomp_var_45c = decomp_var_45c + 0x100;
    bool_193 = decomp_var_454 + 0x1 < eax[0x901];
    decomp_var_454 = decomp_var_454 + 0x1;
    if (bool_193) {
            continue;
    }
    break;

loc_434446:
    decomp_var_460 = 0x0;
    ebx = decomp_var_464 + 0x2a1c;
    goto loc_434460;

loc_4342cd:
    decomp_var_45c = eax & 0xff;
    if ((eax & 0xff) == 0x14) goto loc_4343ed;
    goto loc_4342dd;
    eax = edx[0x2];
    edi = eax + 0x2450;
    esi = *eax[0x915];
    decomp_var_450 = edi;
    decomp_var_44c = esi;
    goto .l26;

.l33:
    ebx = arg_0;
    if (esi == 0x0 || esi != ebp) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (*(&decomp_var_47c + edi[0x3] * 0x4 + 0x64) == 0xffffffff) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    *(&decomp_var_47c + edi[0x3] * 0x4 + 0x64) = 0x0;
                    sub_40f400();
                    edi = decomp_var_434;
                    esi = decomp_var_438;
            }
            else {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    *(&decomp_var_47c + edi[0x3] * 0x4 + 0x64) = 0xfffffff6;
                    sub_40f400();
                    edi = decomp_var_434;
                    esi = decomp_var_438;
            }
            continue;
    }
    break;

.l11:
    edx = decomp_var_464;
    eax = edx[0x2];
    ecx = eax[0x1225] & 0xffff;
    if (*(int16_t *)word_4c6cc4 != ecx) {
            if (*(int16_t *)word_4c6ccc == ecx) {
                    esi = 0x0;
                    if (eax[0x900] > 0x0) {
                            do {
                                    eax = esi * 0x8;
                                    eax[0x134384] = eax[0x134984];
                                    eax[0x134385] = eax[0x134985];
                                    eax[0x134584] = eax[0x134b84];
                                    eax[0x134585] = eax[0x134b85];
                                    eax[0x134784] = eax[0x134d84];
                                    eax[0x134785] = eax[0x134d85];
                                    ecx = 0x0;
                                    if (*(edx[0x2] + 0x2404) > 0x0) {
                                            &decomp_var_47c = &decomp_var_47c;
                                            do {
                                                    eax[0x17663a] = eax[0x17903a];
                                                    eax[0x17663b] = eax[0x17903b];
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x800;
                                            } while (ecx < *(edx[0x2] + 0x2404));
                                    }
                                    esi = esi + 0x1;
                            } while (esi < *(edx[0x2] + 0x2400));
                    }
            }
    }
    else {
            esi = 0x0;
            if (eax[0x900] > 0x0) {
                    do {
                            eax = esi * 0x8;
                            eax[0x134384] = eax[0x134984];
                            eax[0x134385] = eax[0x134985];
                            eax[0x134584] = eax[0x134b84];
                            eax[0x134585] = eax[0x134b85];
                            eax[0x134784] = eax[0x134d84];
                            eax[0x134785] = eax[0x134d85];
                            ecx = 0x0;
                            if (*(edx[0x2] + 0x2404) > 0x0) {
                                    &decomp_var_47c = &decomp_var_47c;
                                    do {
                                            eax[0x17663a] = eax[0x17903a];
                                            eax[0x17663b] = eax[0x17903b];
                                            ecx = ecx + 0x1;
                                            eax = eax + 0x800;
                                    } while (ecx < *(edx[0x2] + 0x2404));
                            }
                            esi = esi + 0x1;
                    } while (esi < *(edx[0x2] + 0x2400));
            }
    }
    ecx = edx[0x2];
    eax = ecx[0x1225] & 0xffff;
    if (*(int16_t *)word_4c6cc8 != eax) {
            if (*(int16_t *)word_4c6cd0 == eax) {
                    if (ecx[0x900] > 0x0) {
                            sub_435160();
                    }
                    eax = decomp_var_42c - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    *0x0 = decomp_var_14;
                    &decomp_var_468 = decomp_var_470;
            }
            else {
                    eax = decomp_var_42c - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    *0x0 = decomp_var_14;
                    &decomp_var_468 = decomp_var_470;
            }
    }
    else {
            if (ecx[0x900] > 0x0) {
                    sub_435160();
            }
            eax = decomp_var_42c - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
            if (ecx <= 0x1) {
                    esp = esp - 0x4;
                    (*(**eax + 0x4))(eax);
            }
            *0x0 = decomp_var_14;
            &decomp_var_468 = decomp_var_470;
    }
    return;

.l9:
    if (*(int8_t *)byte_baed45 != 0x1) goto .l10;
    goto .l4;

loc_4346fe:
    eax = decomp_var_464[0x2];
    ecx = eax[0x901];
    decomp_var_45c = decomp_var_45c + 0x15;
    decomp_var_460 = decomp_var_460 + 0x100;
    bool_94 = decomp_var_454 + 0x1 < ecx;
    decomp_var_454 = decomp_var_454 + 0x1;
    if (bool_94) {
            continue;
    }
    break;

loc_4345a0:
    ecx = decomp_var_448;
    if (decomp_var_454 == ecx) goto .l7;
    goto loc_4345ae;

loc_434460:
    ecx = decomp_var_460;
    if (*(int8_t *)(ecx + eax + 0x3) == 0x0) goto loc_434515;
    goto loc_43446f;

loc_4342dd:
    edi = ebx;
    esi = *ebx[0x1];
    decomp_var_440 = edi;
    decomp_var_43c = esi;
    goto loc_4342f0;

.l26:
    eax = edx[0x2];
    ebp = eax[0x915];
    eax = eax + 0x2450;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
            edx = decomp_var_464;
    }
    if (esi == ebp) goto .l24;
    goto .l25;
    sub_401390();
    esi = decomp_var_44c;
    edi = decomp_var_450;
    edx = decomp_var_464;
    continue;

.l10:
    edx = decomp_var_464;
    eax = edx[0x2];
    ecx = eax[0x1225] & 0xffff;
    if (*(int16_t *)word_4c6cc4 != ecx) {
            if (*(int16_t *)word_4c6ccc == ecx) {
                    esi = 0x0;
                    if (eax[0x900] > 0x0) {
                            do {
                                    eax = esi * 0x8;
                                    eax[0x134384] = eax[0x134984];
                                    eax[0x134385] = eax[0x134985];
                                    eax[0x134584] = eax[0x134b84];
                                    eax[0x134585] = eax[0x134b85];
                                    eax[0x134784] = eax[0x134d84];
                                    eax[0x134785] = eax[0x134d85];
                                    ecx = 0x0;
                                    if (*(edx[0x2] + 0x2404) > 0x0) {
                                            &decomp_var_47c = &decomp_var_47c;
                                            do {
                                                    eax[0x17663a] = eax[0x17903a];
                                                    eax[0x17663b] = eax[0x17903b];
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x800;
                                            } while (ecx < *(edx[0x2] + 0x2404));
                                    }
                                    esi = esi + 0x1;
                            } while (esi < *(edx[0x2] + 0x2400));
                    }
            }
    }
    else {
            esi = 0x0;
            if (eax[0x900] > 0x0) {
                    do {
                            eax = esi * 0x8;
                            eax[0x134384] = eax[0x134984];
                            eax[0x134385] = eax[0x134985];
                            eax[0x134584] = eax[0x134b84];
                            eax[0x134585] = eax[0x134b85];
                            eax[0x134784] = eax[0x134d84];
                            eax[0x134785] = eax[0x134d85];
                            ecx = 0x0;
                            if (*(edx[0x2] + 0x2404) > 0x0) {
                                    &decomp_var_47c = &decomp_var_47c;
                                    do {
                                            eax[0x17663a] = eax[0x17903a];
                                            eax[0x17663b] = eax[0x17903b];
                                            ecx = ecx + 0x1;
                                            eax = eax + 0x800;
                                    } while (ecx < *(edx[0x2] + 0x2404));
                            }
                            esi = esi + 0x1;
                    } while (esi < *(edx[0x2] + 0x2400));
            }
    }
    ecx = edx[0x2];
    eax = ecx[0x1225] & 0xffff;
    if (*(int16_t *)word_4c6cc8 != eax) {
            if (*(int16_t *)word_4c6cd0 == eax) {
                    if (ecx[0x900] > 0x0) {
                            sub_435160();
                    }
                    eax = decomp_var_42c - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    *0x0 = decomp_var_14;
                    &decomp_var_468 = decomp_var_470;
            }
            else {
                    eax = decomp_var_42c - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    *0x0 = decomp_var_14;
                    &decomp_var_468 = decomp_var_470;
            }
    }
    else {
            if (ecx[0x900] > 0x0) {
                    sub_435160();
            }
            eax = decomp_var_42c - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
            if (ecx <= 0x1) {
                    esp = esp - 0x4;
                    (*(**eax + 0x4))(eax);
            }
            *0x0 = decomp_var_14;
            &decomp_var_468 = decomp_var_470;
    }
    return;

.l4:
    edx = decomp_var_464;
    esi = edx[0x2];
    ecx = esi[0x900];
    bool_46 = true;
    if (ecx > 0x0) {
            asm { rep stosd  dword [edi], eax };
    }
    edi = esi + 0x2450;
    esi = *esi[0x915];
    decomp_var_450 = edi;
    decomp_var_44c = esi;
    goto loc_434a90;

.l7:
    eax = decomp_var_464[0x2];
    bool_105 = decomp_var_448 + 0x1 < eax[0x901];
    decomp_var_448 = decomp_var_448 + 0x1;
    if (bool_105) {
            continue;
    }
    break;

loc_4345ae:
    ecx = ecx + decomp_var_45c;
    bool_99 = *(ecx * 0x8 + 0x4d552c) < 0x0;
    bool_95 = *(ecx * 0x8 + 0x4d552c) > 0x0;
    if (bool_99) goto .l13;
    goto loc_4345c2;

loc_434515:
    eax = decomp_var_464[0x2];
    decomp_var_460 = decomp_var_460 + 0x24;
    ebx = ebx + 0xc;
    bool_197 = decomp_var_444 + 0x1 < eax[0x900];
    decomp_var_444 = decomp_var_444 + 0x1;
    if (bool_197) {
            continue;
    }
    break;

loc_43446f:
    eax = *(int16_t *)(ecx + eax + 0x20);
    bool_196 = HIBYTE(eax) == 0x41;
    eax = eax & 0xff;
    if (!bool_196) {
            eax = 0x14;
    }
    if (eax != decomp_var_454) goto loc_434515;
    goto loc_43448d;

loc_4342f0:
    ebp = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if ((*(eax * 0x8 + 0x4d3610) & *(eax * 0x8 + 0x4d3614)) == 0xffffffff) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi = esi[0x3];
                    *(esi * 0x8 + 0x4d3610) = decomp_var_45c;
                    *(esi * 0x8 + 0x4d3614) = decomp_var_45c & 0x80000000 ? 0xffffffff : 0x0;
                    sub_401520();
                    esi = decomp_var_43c;
                    edi = decomp_var_440;
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi[0x3];
                    if ((*(eax * 0x8 + 0x4d3610) & *(eax * 0x8 + 0x4d3614)) != 0xffffffff) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            ecx = esi[0x3];
                            edx = decomp_var_45c & 0x80000000 ? 0xffffffff : 0x0;
                            if (*(ecx * 0x8 + 0x4d3610) == decomp_var_45c) {
                                    if (*(ecx * 0x8 + 0x4d3614) != edx) {
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            esi = esi[0x3];
                                            *(esi * 0x8 + 0x4d3610) = 0xfffffffe;
                                            *(esi * 0x8 + 0x4d3614) = 0xffffffff;
                                    }
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    esi = esi[0x3];
                                    *(esi * 0x8 + 0x4d3610) = 0xfffffffe;
                                    *(esi * 0x8 + 0x4d3614) = 0xffffffff;
                            }
                    }
                    sub_401520();
                    esi = decomp_var_43c;
                    edi = decomp_var_440;
            }
            continue;
    }
    break;

.l24:
    break;

.l25:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != decomp_var_428) {
            sub_401390();
            esi = decomp_var_44c;
            edi = decomp_var_450;
            edx = decomp_var_464;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x4];
    if (*(int8_t *)(decomp_var_464[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) != 0x0) {
            decomp_var_458 = decomp_var_458 | 0x1;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x4];
            ecx = decomp_var_464[0x2];
            bool_244 = *(int16_t *)(ecx + (eax + eax * 0x8) * 0x4 + 0x20) == 0x14;
            bool_243 = *(int16_t *)(ecx + (eax + eax * 0x8) * 0x4 + 0x20) != 0x14;
            eax = (bool_244 ? 0x1 : 0x0) & 0xff;
            if (!bool_243 && (eax & 0xff) == 0x0) {
                    eax = 0x0;
            }
            else {
                    eax = 0x1;
            }
    }
    else {
            eax = 0x0;
    }
    if ((decomp_var_458 & 0x1) != 0x0) {
            decomp_var_458 = decomp_var_458 & 0xfffffffe;
    }
    if (eax == 0x0) {
            sub_401390();
            esi = decomp_var_44c;
            edi = decomp_var_450;
            edx = decomp_var_464;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    eax = esi + 0x14;
    esp = esp - 0x4;
    ebx = sub_4075b0(eax, decomp_var_47c);
    esi = *ebx[0x1];
    edi = ebx;
    decomp_var_438 = edi;
    decomp_var_434 = esi;
    goto .l28;

loc_434a90:
    eax = edx[0x2];
    ebp = eax[0x915];
    eax = eax + 0x2450;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
            edx = decomp_var_464;
    }
    if (esi == ebp) goto .l80;
    goto loc_434ab7;

.l13:
    eax = decomp_var_464[0x2];
    bool_104 = decomp_var_448 + 0x1 < eax[0x901];
    decomp_var_448 = decomp_var_448 + 0x1;
    if (bool_104) {
            continue;
    }
    break;

loc_4345c2:
    if (bool_95) goto loc_4345d2;
    goto loc_4345c4;

loc_43448d:
    edi = ebx;
    esi = *ebx[0x1];
    decomp_var_440 = edi;
    decomp_var_43c = esi;
    goto loc_4344a0;
    ecx = decomp_var_460;
    edx = decomp_var_464;
    goto loc_4343ed;
    eax = edx[0x2];
    edi = eax + 0x2450;
    esi = *eax[0x915];
    decomp_var_450 = edi;
    decomp_var_44c = esi;
    goto loc_434dc2;

.l28:
    ebp = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(int8_t *)(decomp_var_464[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) != 0x0) {
                    decomp_var_458 = decomp_var_458 | 0x2;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi[0x3];
                    ecx = decomp_var_464[0x2];
                    bool_268 = *(int16_t *)(ecx + (eax + eax * 0x8) * 0x4 + 0x20) == 0x14;
                    bool_267 = *(int16_t *)(ecx + (eax + eax * 0x8) * 0x4 + 0x20) != 0x14;
                    eax = (bool_268 ? 0x1 : 0x0) & 0xff;
                    if (!bool_267 && (eax & 0xff) == 0x0) {
                            eax = 0x0;
                    }
                    else {
                            eax = 0x1;
                    }
            }
            else {
                    eax = 0x0;
            }
            if ((decomp_var_458 & 0x2) != 0x0) {
                    decomp_var_458 = decomp_var_458 & 0xfffffffd;
            }
            if (eax != 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (*(&decomp_var_47c + esi[0x3] * 0x4 + 0x64) == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            *(&decomp_var_47c + esi[0x3] * 0x4 + 0x64) = 0x1;
                    }
            }
            sub_40f400();
            esi = decomp_var_434;
            edi = decomp_var_438;
            continue;
    }
    break;

.l80:
    break;

loc_434ab7:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != decomp_var_428) {
            sub_401390();
            esi = decomp_var_44c;
            edi = decomp_var_450;
            edx = decomp_var_464;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    edx = esi + 0x14;
    esp = esp - 0x4;
    ebp = sub_4075b0(edx, decomp_var_47c);
    edi = *arg_0;
    esi = ebp;
    decomp_var_438 = esi;
    decomp_var_434 = edi;
    goto loc_434b16;

loc_4345d2:
    decomp_var_444 = 0x0;
    if (eax[0x900] <= 0x0) goto loc_4346e0;
    goto .l15;

loc_4345c4:
    if (*(ecx * 0x8 + 0x4d5528) <= 0x1) goto .l8;
    goto .l14;

loc_4344a0:
    ebp = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(int8_t *)(decomp_var_464[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi[0x3];
                    *((eax + decomp_var_45c) * 0x8 + 0x5e40e8) = 0x1;
                    *((eax + decomp_var_45c) * 0x8 + 0x5e40ec) = 0x0;
            }
            sub_401520();
            esi = decomp_var_43c;
            edi = decomp_var_440;
            continue;
    }
    break;

loc_434dc2:
    eax = edx[0x2];
    ebp = eax[0x915];
    eax = eax + 0x2450;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
            edx = decomp_var_464;
    }
    if (esi == ebp) goto .l67;
    goto loc_434de9;
    sub_401390();
    esi = decomp_var_44c;
    edi = decomp_var_450;
    edx = decomp_var_464;
    continue;
    eax = edx[0x2];
    edi = eax + 0x2450;
    esi = *eax[0x915];
    decomp_var_450 = edi;
    decomp_var_44c = esi;
    goto loc_434bd0;

loc_434b16:
    ebx = arg_0;
    if (esi == 0x0 || esi != ebp) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (*(&decomp_var_47c + edi[0x3] * 0x4 + 0x64) == 0xffffffff) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    *(&decomp_var_47c + edi[0x3] * 0x4 + 0x64) = 0x0;
                    sub_40f400();
                    edi = decomp_var_434;
                    esi = decomp_var_438;
            }
            else {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    *(&decomp_var_47c + edi[0x3] * 0x4 + 0x64) = 0xfffffff6;
                    sub_40f400();
                    edi = decomp_var_434;
                    esi = decomp_var_438;
            }
            continue;
    }
    break;

loc_4346e0:
    eax = decomp_var_464[0x2];
    bool_98 = decomp_var_448 + 0x1 < eax[0x901];
    decomp_var_448 = decomp_var_448 + 0x1;
    if (bool_98) {
            continue;
    }
    break;

.l15:
    edx = 0x0;
    decomp_var_430 = 0x0;
    ebx = decomp_var_464 + 0x2a1c;
    goto loc_434600;

.l8:
    eax = decomp_var_464[0x2];
    bool_97 = decomp_var_448 + 0x1 < eax[0x901];
    decomp_var_448 = decomp_var_448 + 0x1;
    if (bool_97) {
            continue;
    }
    break;

.l14:
    decomp_var_444 = 0x0;
    if (eax[0x900] <= 0x0) goto .l12;
    goto loc_4345e7;

.l67:
    temp_1 = 0x1;
    break;

loc_434de9:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != *dword_4c6bc4) {
            sub_401390();
            esi = decomp_var_44c;
            edi = decomp_var_450;
            edx = decomp_var_464;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x4];
    if (*(int8_t *)(decomp_var_464[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) != 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x4];
            if (*(int8_t *)(decomp_var_464[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) == 0x1) {
                    decomp_var_458 = decomp_var_458 | 0x4;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi[0x4];
                    edx = decomp_var_464[0x2];
                    bool_162 = *(int16_t *)(edx + (eax + eax * 0x8) * 0x4 + 0x20) != 0x14;
                    bool_161 = *(int16_t *)(edx + (eax + eax * 0x8) * 0x4 + 0x20) != 0x14;
                    eax = (bool_162 ? 0x1 : 0x0) & 0xff;
                    if (!bool_161) {
                            if ((eax & 0xff) == 0x0) {
                                    eax = 0x0;
                            }
                            else {
                                    eax = 0x1;
                            }
                    }
                    else {
                            eax = 0x1;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x1;
    }
    if ((decomp_var_458 & 0x4) != 0x0) {
            decomp_var_458 = decomp_var_458 & 0xfffffffb;
    }
    if (eax == 0x0) {
            sub_401390();
            esi = decomp_var_44c;
            edi = decomp_var_450;
            edx = decomp_var_464;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    edx = decomp_var_464;
    eax = esi + 0x14;
    esp = esp - 0x4;
    ebx = sub_4075b0(eax, decomp_var_47c);
    edi = ebx;
    esi = *ebx[0x1];
    goto loc_434ed7;

loc_434bd0:
    eax = edx[0x2];
    ebp = eax[0x915];
    eax = eax + 0x2450;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
            edx = decomp_var_464;
    }
    if (esi == ebp) goto .l71;
    goto loc_434bf7;
    sub_401390();
    esi = decomp_var_44c;
    edi = decomp_var_450;
    edx = decomp_var_464;
    continue;

loc_434600:
    if (*(int8_t *)(edx + eax + 0x3) == 0x0) goto loc_4346b8;
    goto loc_43460b;

.l12:
    eax = decomp_var_464[0x2];
    bool_100 = decomp_var_448 + 0x1 < eax[0x901];
    decomp_var_448 = decomp_var_448 + 0x1;
    if (bool_100) {
            continue;
    }
    break;

loc_4345e7:
    edx = 0x0;
    decomp_var_430 = 0x0;
    ebx = decomp_var_464 + 0x2a1c;
    goto .l20;
    if (temp_1 != 0x0) {
            eax = edx[0x2];
            ecx = eax[0x1225] & 0xffff;
            if (*(int16_t *)word_4c6cc4 != ecx) {
                    if (*(int16_t *)word_4c6ccc == ecx) {
                            esi = 0x0;
                            if (eax[0x900] > 0x0) {
                                    do {
                                            eax = esi * 0x8;
                                            eax[0x134384] = eax[0x134984];
                                            eax[0x134385] = eax[0x134985];
                                            eax[0x134584] = eax[0x134b84];
                                            eax[0x134585] = eax[0x134b85];
                                            eax[0x134784] = eax[0x134d84];
                                            eax[0x134785] = eax[0x134d85];
                                            ecx = 0x0;
                                            if (*(edx[0x2] + 0x2404) > 0x0) {
                                                    &decomp_var_47c = &decomp_var_47c;
                                                    do {
                                                            eax[0x17663a] = eax[0x17903a];
                                                            eax[0x17663b] = eax[0x17903b];
                                                            ecx = ecx + 0x1;
                                                            eax = eax + 0x800;
                                                    } while (ecx < *(edx[0x2] + 0x2404));
                                            }
                                            esi = esi + 0x1;
                                    } while (esi < *(edx[0x2] + 0x2400));
                            }
                    }
            }
            else {
                    esi = 0x0;
                    if (eax[0x900] > 0x0) {
                            do {
                                    eax = esi * 0x8;
                                    eax[0x134384] = eax[0x134984];
                                    eax[0x134385] = eax[0x134985];
                                    eax[0x134584] = eax[0x134b84];
                                    eax[0x134585] = eax[0x134b85];
                                    eax[0x134784] = eax[0x134d84];
                                    eax[0x134785] = eax[0x134d85];
                                    ecx = 0x0;
                                    if (*(edx[0x2] + 0x2404) > 0x0) {
                                            &decomp_var_47c = &decomp_var_47c;
                                            do {
                                                    eax[0x17663a] = eax[0x17903a];
                                                    eax[0x17663b] = eax[0x17903b];
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x800;
                                            } while (ecx < *(edx[0x2] + 0x2404));
                                    }
                                    esi = esi + 0x1;
                            } while (esi < *(edx[0x2] + 0x2400));
                    }
            }
            ecx = edx[0x2];
            eax = ecx[0x1225] & 0xffff;
            if (*(int16_t *)word_4c6cc8 != eax) {
                    if (*(int16_t *)word_4c6cd0 == eax) {
                            if (ecx[0x900] > 0x0) {
                                    sub_435160();
                            }
                            eax = decomp_var_42c - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                            if (ecx <= 0x1) {
                                    esp = esp - 0x4;
                                    (*(**eax + 0x4))(eax);
                            }
                            *0x0 = decomp_var_14;
                            &decomp_var_468 = decomp_var_470;
                    }
                    else {
                            eax = decomp_var_42c - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                            if (ecx <= 0x1) {
                                    esp = esp - 0x4;
                                    (*(**eax + 0x4))(eax);
                            }
                            *0x0 = decomp_var_14;
                            &decomp_var_468 = decomp_var_470;
                    }
            }
            else {
                    if (ecx[0x900] > 0x0) {
                            sub_435160();
                    }
                    eax = decomp_var_42c - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    *0x0 = decomp_var_14;
                    &decomp_var_468 = decomp_var_470;
            }
    }
    return;

loc_434ed7:
    ebp = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (*(&decomp_var_47c + esi[0x3] * 0x4 + 0x64) != 0x1) {
                    sub_40f400();
                    esi = decomp_var_440;
                    edi = decomp_var_444;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = *dword_4c6bc4;
            ecx = esi[0x3];
            *(ecx * 0x8 + 0x4d3610) = eax;
            *(ecx * 0x8 + 0x4d3614) = eax & 0x80000000 ? 0xffffffff : 0x0;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            sub_46db50();
            eax = sub_4273a0(decomp_var_480);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            decomp_var_488 = &decomp_var_42c;
            sub_410c10(decomp_var_488, 0x4b0d28, eax);
            edx = **(decomp_var_42c - 0x10);
            eax = edx[0x4];
            esi = decomp_var_42c - 0x10;
            esp = (esp - 0xc) + 0xc;
            decomp_var_440 = 0x3;
            eax = (eax)();
            ecx = esi + 0xc;
            if (esi[0x3] >= 0x0) {
                    if (eax == *esi) {
                            edi = esi;
                            *ecx = lock intrinsic_xadd(*ecx, 0x1);
                            esp = esp - 0x8;
                            eax = sub_419e60(&decomp_var_430, &decomp_var_44c, decomp_var_488);
                            eax = edi + 0x10 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            edx = edx - 0x1;
                            if (edx <= 0x0) {
                                    edx = **eax;
                                    esp = esp - 0x4;
                                    (edx[0x1])(eax);
                            }
                            sub_40f400();
                            esi = decomp_var_440;
                            edi = decomp_var_444;
                            continue;
                    }
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
                            eax = sub_419e60(&decomp_var_430, &decomp_var_44c, decomp_var_488);
                            eax = edi + 0x10 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            edx = edx - 0x1;
                            if (edx <= 0x0) {
                                    edx = **eax;
                                    esp = esp - 0x4;
                                    (edx[0x1])(eax);
                            }
                            sub_40f400();
                            esi = decomp_var_440;
                            edi = decomp_var_444;
                            continue;
                    }
                    sub_40b6d0();
                    temp_0 = 0x1;
                    break;
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
                            eax = sub_419e60(&decomp_var_430, &decomp_var_44c, decomp_var_488);
                            eax = edi + 0x10 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            edx = edx - 0x1;
                            if (edx <= 0x0) {
                                    edx = **eax;
                                    esp = esp - 0x4;
                                    (edx[0x1])(eax);
                            }
                            sub_40f400();
                            esi = decomp_var_440;
                            edi = decomp_var_444;
                            continue;
                    }
                    sub_40b6d0();
                    temp_0 = 0x1;
                    break;
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l23;

.l71:
    break;

loc_434bf7:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != decomp_var_428) {
            sub_401390();
            esi = decomp_var_44c;
            edi = decomp_var_450;
            edx = decomp_var_464;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x4];
    if (*(int8_t *)(decomp_var_464[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) != 0x0) {
            decomp_var_458 = decomp_var_458 | 0x1;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x4];
            ecx = decomp_var_464[0x2];
            bool_217 = *(int16_t *)(ecx + (eax + eax * 0x8) * 0x4 + 0x20) == 0x14;
            bool_216 = *(int16_t *)(ecx + (eax + eax * 0x8) * 0x4 + 0x20) != 0x14;
            eax = (bool_217 ? 0x1 : 0x0) & 0xff;
            if (!bool_216 && (eax & 0xff) == 0x0) {
                    eax = 0x0;
            }
            else {
                    eax = 0x1;
            }
    }
    else {
            eax = 0x0;
    }
    if ((decomp_var_458 & 0x1) != 0x0) {
            decomp_var_458 = decomp_var_458 & 0xfffffffe;
    }
    if (eax == 0x0) {
            sub_401390();
            esi = decomp_var_44c;
            edi = decomp_var_450;
            edx = decomp_var_464;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    eax = esi + 0x14;
    esp = esp - 0x4;
    ebx = sub_4075b0(eax, decomp_var_47c);
    esi = *ebx[0x1];
    edi = ebx;
    decomp_var_438 = edi;
    decomp_var_434 = esi;
    goto loc_434cc3;

loc_4346b8:
    eax = decomp_var_464[0x2];
    edx = edx + 0x24;
    ebx = ebx + 0xc;
    bool_106 = decomp_var_444 + 0x1 < eax[0x900];
    decomp_var_444 = decomp_var_444 + 0x1;
    decomp_var_430 = edx;
    if (bool_106) {
            continue;
    }
    break;

loc_43460b:
    eax = *(int16_t *)(edx + eax + 0x20);
    bool_109 = HIBYTE(eax) == 0x41;
    eax = eax & 0xff;
    if (!bool_109) {
            eax = 0x14;
    }
    if (eax != decomp_var_448) goto loc_4346b8;
    goto loc_434627;

.l20:
    if (*(int8_t *)(edx + eax + 0x3) == 0x0) goto .l17;
    goto .l16;

.l23:
    if (temp_0 == 0x0) {
            sub_401390();
            esi = decomp_var_44c;
            edi = decomp_var_450;
            edx = decomp_var_464;
            continue;
    }
    temp_1 = 0x0;
    break;
    eax = edx[0x2];
    edi = eax + 0x2450;
    esi = *eax[0x915];
    decomp_var_450 = edi;
    decomp_var_44c = esi;
    goto .l35;

loc_434cc3:
    ebp = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(int8_t *)(decomp_var_464[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) != 0x0) {
                    decomp_var_458 = decomp_var_458 | 0x2;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi[0x3];
                    ecx = decomp_var_464[0x2];
                    bool_227 = *(int16_t *)(ecx + (eax + eax * 0x8) * 0x4 + 0x20) == 0x14;
                    bool_226 = *(int16_t *)(ecx + (eax + eax * 0x8) * 0x4 + 0x20) != 0x14;
                    eax = (bool_227 ? 0x1 : 0x0) & 0xff;
                    if (!bool_226 && (eax & 0xff) == 0x0) {
                            eax = 0x0;
                    }
                    else {
                            eax = 0x1;
                    }
            }
            else {
                    eax = 0x0;
            }
            if ((decomp_var_458 & 0x2) != 0x0) {
                    decomp_var_458 = decomp_var_458 & 0xfffffffd;
            }
            if (eax != 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (*(&decomp_var_47c + esi[0x3] * 0x4 + 0x64) == 0x0) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            *(&decomp_var_47c + esi[0x3] * 0x4 + 0x64) = 0x1;
                    }
            }
            sub_40f400();
            esi = decomp_var_434;
            edi = decomp_var_438;
            continue;
    }
    break;

loc_434627:
    edi = ebx;
    esi = *ebx[0x1];
    decomp_var_440 = edi;
    decomp_var_43c = esi;
    goto loc_434638;

.l17:
    eax = decomp_var_464[0x2];
    edx = edx + 0x24;
    ebx = ebx + 0xc;
    bool_119 = decomp_var_444 + 0x1 < eax[0x900];
    decomp_var_444 = decomp_var_444 + 0x1;
    decomp_var_430 = edx;
    if (bool_119) {
            continue;
    }
    break;

.l16:
    eax = *(int16_t *)(edx + eax + 0x20);
    bool_118 = HIBYTE(eax) == 0x41;
    eax = eax & 0xff;
    if (!bool_118) {
            eax = 0x14;
    }
    if (eax != decomp_var_448) goto .l17;
    goto .l19;

.l35:
    eax = edx[0x2];
    ebp = eax[0x915];
    eax = eax + 0x2450;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
            edx = decomp_var_464;
    }
    if (esi == ebp) goto .l36;
    goto .l34;
    sub_401390();
    esi = decomp_var_44c;
    edi = decomp_var_450;
    edx = decomp_var_464;
    continue;

loc_434638:
    ebp = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + decomp_var_460;
            if (*(eax * 0x8 + 0x5e40e8) == 0x1 && *(eax * 0x8 + 0x5e40ec) == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi[0x3];
                    *((eax + decomp_var_460) * 0x8 + 0x5e40e8) = 0x2;
                    *((eax + decomp_var_460) * 0x8 + 0x5e40ec) = 0x0;
            }
            sub_401520();
            esi = decomp_var_43c;
            edi = decomp_var_440;
            continue;
    }
    break;

.l19:
    edi = ebx;
    esi = *ebx[0x1];
    decomp_var_440 = edi;
    decomp_var_43c = esi;
    goto .l21;

.l36:
    temp_1 = 0x1;
    break;

.l34:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != *dword_4c6bc4) {
            sub_401390();
            esi = decomp_var_44c;
            edi = decomp_var_450;
            edx = decomp_var_464;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x4];
    if (*(int8_t *)(decomp_var_464[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) != 0x0) {
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x4];
            if (*(int8_t *)(decomp_var_464[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) == 0x1) {
                    decomp_var_458 = decomp_var_458 | 0x4;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi[0x4];
                    edx = decomp_var_464[0x2];
                    bool_331 = *(int16_t *)(edx + (eax + eax * 0x8) * 0x4 + 0x20) != 0x14;
                    bool_330 = *(int16_t *)(edx + (eax + eax * 0x8) * 0x4 + 0x20) != 0x14;
                    eax = (bool_331 ? 0x1 : 0x0) & 0xff;
                    if (!bool_330) {
                            if ((eax & 0xff) == 0x0) {
                                    eax = 0x0;
                            }
                            else {
                                    eax = 0x1;
                            }
                    }
                    else {
                            eax = 0x1;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x1;
    }
    if ((decomp_var_458 & 0x4) != 0x0) {
            decomp_var_458 = decomp_var_458 & 0xfffffffb;
    }
    if (eax == 0x0) {
            sub_401390();
            esi = decomp_var_44c;
            edi = decomp_var_450;
            edx = decomp_var_464;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    edx = decomp_var_464;
    eax = esi + 0x14;
    esp = esp - 0x4;
    ebx = sub_4075b0(eax, decomp_var_47c);
    edi = ebx;
    esi = *ebx[0x1];
    goto .l39;
    edx = decomp_var_430;
    goto loc_4346b8;

.l21:
    ebp = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            eax = eax + decomp_var_460;
            if (*(eax * 0x8 + 0x5e40e8) == 0x1 && *(eax * 0x8 + 0x5e40ec) == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi[0x3];
                    *((eax + decomp_var_460) * 0x8 + 0x5e40e8) = 0x2;
                    *((eax + decomp_var_460) * 0x8 + 0x5e40ec) = 0x0;
            }
            sub_401520();
            esi = decomp_var_43c;
            edi = decomp_var_440;
            continue;
    }
    break;
    if (temp_1 != 0x0) {
            eax = edx[0x2];
            ecx = eax[0x1225] & 0xffff;
            if (*(int16_t *)word_4c6cc4 != ecx) {
                    if (*(int16_t *)word_4c6ccc == ecx) {
                            esi = 0x0;
                            if (eax[0x900] > 0x0) {
                                    do {
                                            eax = esi * 0x8;
                                            eax[0x134384] = eax[0x134984];
                                            eax[0x134385] = eax[0x134985];
                                            eax[0x134584] = eax[0x134b84];
                                            eax[0x134585] = eax[0x134b85];
                                            eax[0x134784] = eax[0x134d84];
                                            eax[0x134785] = eax[0x134d85];
                                            ecx = 0x0;
                                            if (*(edx[0x2] + 0x2404) > 0x0) {
                                                    &decomp_var_47c = &decomp_var_47c;
                                                    do {
                                                            eax[0x17663a] = eax[0x17903a];
                                                            eax[0x17663b] = eax[0x17903b];
                                                            ecx = ecx + 0x1;
                                                            eax = eax + 0x800;
                                                    } while (ecx < *(edx[0x2] + 0x2404));
                                            }
                                            esi = esi + 0x1;
                                    } while (esi < *(edx[0x2] + 0x2400));
                            }
                    }
            }
            else {
                    esi = 0x0;
                    if (eax[0x900] > 0x0) {
                            do {
                                    eax = esi * 0x8;
                                    eax[0x134384] = eax[0x134984];
                                    eax[0x134385] = eax[0x134985];
                                    eax[0x134584] = eax[0x134b84];
                                    eax[0x134585] = eax[0x134b85];
                                    eax[0x134784] = eax[0x134d84];
                                    eax[0x134785] = eax[0x134d85];
                                    ecx = 0x0;
                                    if (*(edx[0x2] + 0x2404) > 0x0) {
                                            &decomp_var_47c = &decomp_var_47c;
                                            do {
                                                    eax[0x17663a] = eax[0x17903a];
                                                    eax[0x17663b] = eax[0x17903b];
                                                    ecx = ecx + 0x1;
                                                    eax = eax + 0x800;
                                            } while (ecx < *(edx[0x2] + 0x2404));
                                    }
                                    esi = esi + 0x1;
                            } while (esi < *(edx[0x2] + 0x2400));
                    }
            }
            ecx = edx[0x2];
            eax = ecx[0x1225] & 0xffff;
            if (*(int16_t *)word_4c6cc8 != eax) {
                    if (*(int16_t *)word_4c6cd0 == eax) {
                            if (ecx[0x900] > 0x0) {
                                    sub_435160();
                            }
                            eax = decomp_var_42c - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                            if (ecx <= 0x1) {
                                    esp = esp - 0x4;
                                    (*(**eax + 0x4))(eax);
                            }
                            *0x0 = decomp_var_14;
                            &decomp_var_468 = decomp_var_470;
                    }
                    else {
                            eax = decomp_var_42c - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                            if (ecx <= 0x1) {
                                    esp = esp - 0x4;
                                    (*(**eax + 0x4))(eax);
                            }
                            *0x0 = decomp_var_14;
                            &decomp_var_468 = decomp_var_470;
                    }
            }
            else {
                    if (ecx[0x900] > 0x0) {
                            sub_435160();
                    }
                    eax = decomp_var_42c - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                    if (ecx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    *0x0 = decomp_var_14;
                    &decomp_var_468 = decomp_var_470;
            }
    }
    return;

.l39:
    ebp = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (*(&decomp_var_47c + esi[0x3] * 0x4 + 0x64) != 0x1) {
                    sub_40f400();
                    esi = decomp_var_440;
                    edi = decomp_var_444;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = *dword_4c6bc4;
            ecx = esi[0x3];
            *(ecx * 0x8 + 0x4d3610) = eax;
            *(ecx * 0x8 + 0x4d3614) = eax & 0x80000000 ? 0xffffffff : 0x0;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            sub_46db50();
            eax = sub_4273a0(decomp_var_480);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            decomp_var_488 = &decomp_var_42c;
            sub_410c10(decomp_var_488, 0x4b0d28, eax);
            edx = **(decomp_var_42c - 0x10);
            eax = edx[0x4];
            esi = decomp_var_42c - 0x10;
            esp = (esp - 0xc) + 0xc;
            decomp_var_440 = 0x3;
            eax = (eax)();
            ecx = esi + 0xc;
            if (esi[0x3] >= 0x0) {
                    if (eax == *esi) {
                            edi = esi;
                            *ecx = lock intrinsic_xadd(*ecx, 0x1);
                            esp = esp - 0x8;
                            eax = sub_419e60(&decomp_var_430, &decomp_var_44c, decomp_var_488);
                            eax = edi + 0x10 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            edx = edx - 0x1;
                            if (edx <= 0x0) {
                                    edx = **eax;
                                    esp = esp - 0x4;
                                    (edx[0x1])(eax);
                            }
                            sub_40f400();
                            esi = decomp_var_440;
                            edi = decomp_var_444;
                            continue;
                    }
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
                            eax = sub_419e60(&decomp_var_430, &decomp_var_44c, decomp_var_488);
                            eax = edi + 0x10 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            edx = edx - 0x1;
                            if (edx <= 0x0) {
                                    edx = **eax;
                                    esp = esp - 0x4;
                                    (edx[0x1])(eax);
                            }
                            sub_40f400();
                            esi = decomp_var_440;
                            edi = decomp_var_444;
                            continue;
                    }
                    sub_40b6d0();
                    temp_0 = 0x1;
                    break;
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
                            eax = sub_419e60(&decomp_var_430, &decomp_var_44c, decomp_var_488);
                            eax = edi + 0x10 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            edx = edx - 0x1;
                            if (edx <= 0x0) {
                                    edx = **eax;
                                    esp = esp - 0x4;
                                    (edx[0x1])(eax);
                            }
                            sub_40f400();
                            esi = decomp_var_440;
                            edi = decomp_var_444;
                            continue;
                    }
                    sub_40b6d0();
                    temp_0 = 0x1;
                    break;
            }
    }
    else {
            temp_0 = 0x0;
            break;
    }
    goto .l38;
    edx = decomp_var_430;
    goto .l17;

.l38:
    if (temp_0 == 0x0) {
            sub_401390();
            esi = decomp_var_44c;
            edi = decomp_var_450;
            edx = decomp_var_464;
            continue;
    }
    temp_1 = 0x0;
    break;
}
