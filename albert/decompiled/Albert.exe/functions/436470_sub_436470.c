// sub_436470 @ 0x436470
// hopper name: sub_436470
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5603afdb33265f2ea0acc9a81cbc14c61d166c3a97fb9b974c9d4823276f52ec
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_436470() {
    &decomp_var_4 = &decomp_var_4 & 0xfffffff8;
    eax = ecx[0x2];
    decomp_var_d0 = ebx;
    decomp_var_d4 = ebp;
    ebp = 0x0;
    decomp_var_d8 = esi;
    esp = esp - 0xd8;
    decomp_var_dc = edi;
    decomp_var_c8 = ecx;
    decomp_var_68 = eax[0x2424] & 0xff;
    decomp_var_c0 = 0x0;
    if (eax[0x901] <= 0x0) goto loc_4369e6;
    goto loc_4364a9;

loc_4369e6:
    esi = decomp_var_c8;
    eax = esi[0x2];
    eax = eax[0x901];
    edx = 0x0;
    if (eax > 0x0) {
            ebx = 0xb755cc;
            do {
                    ecx = 0x0;
                    if (eax > 0x0) {
                            eax = ebx;
                            do {
                                    *(eax - 0x54) = 0x0;
                                    *eax = 0x0;
                                    eax[0x15] = 0x0;
                                    ecx = ecx + 0x1;
                                    eax = eax + 0x4;
                            } while (ecx < arg_2400);
                    }
                    eax = *(esi[0x2] + 0x2404);
                    edx = edx + 0x1;
                    ebx = ebx + 0xfc;
            } while (edx < eax);
    }
    ecx = esi[0x2];
    decomp_var_c4 = 0x0;
    if (ecx[0x901] <= 0x0) goto loc_436bbd;
    goto loc_436a4a;

loc_4364a9:
    decomp_var_bc = 0x0;
    if (eax[0x900] <= 0x0) goto loc_4365b4;
    goto loc_4364bb;

loc_436bbd:
    esi = *arg_4[0x915];
    edi = arg_4 + 0x2450;
    decomp_var_8c = edi;
    ebx = arg_4[0x915];
    eax = arg_4 + 0x2450;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi == ebx) goto loc_436d0c;
    goto loc_436c03;

loc_436a4a:
    edi = decomp_var_c8;
    decomp_var_c0 = 0x0;
    esi = 0x0;
    goto loc_436a60;

loc_4365b4:
    esi = ecx[0x2];
    edi = *esi[0x915];
    esi = esi + 0x2450;
    decomp_var_8c = esi;
    decomp_var_88 = edi;
    goto loc_4365d0;

loc_4364bb:
    edx = 0x0;
    decomp_var_c4 = 0x0;
    goto loc_4364c2;

loc_436d0c:
    eax = arg_4;
    decomp_var_c0 = 0x0;
    if (eax[0x901] <= 0x0) goto loc_436e53;
    goto loc_436d21;

loc_436c03:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    ebx = sub_4075b0(esi + 0x14, decomp_var_dc);
    sub_436c50(decomp_var_dc, decomp_var_d8, decomp_var_d4, decomp_var_d0, decomp_var_cc, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, ebx, *ebx[0x1], decomp_var_94, decomp_var_90);
    return;

loc_436a60:
    ebx = 0x0;
    if (ecx[0x900] <= 0x0) goto loc_436b99;
    goto loc_436a6e;

loc_4365d0:
    eax = decomp_var_c8[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
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
            if (edi[0x6] == decomp_var_c0) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_41c1e0(edi + 0x10);
                    *eax = 0x1388;
                    eax[0x1] = 0x0;
            }
            sub_401390();
            edi = decomp_var_88;
            esi = decomp_var_8c;
            continue;
    }
    break;

loc_4364c2:
    ebx = eax + decomp_var_c4 + 0x8;
    decomp_var_74 = edx;
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_7c = esi;
    decomp_var_78 = edi;
    goto loc_436500;

loc_436e53:
    eax = arg_4;
    esi = 0x0;
    ebx = 0x0;
    edi = 0x0;
    if (eax[0x900] <= 0x0) goto loc_436ed2;
    goto loc_436e68;

loc_436d21:
    decomp_var_c4 = 0x0;
    goto loc_436d25;

.l1:
    return;

loc_436b99:
    ecx = edi[0x2];
    esi = esi + 0x100;
    bool_304 = decomp_var_c4 + 0x1 < ecx[0x901];
    decomp_var_c4 = decomp_var_c4 + 0x1;
    decomp_var_c0 = esi;
    if (bool_304) {
            continue;
    }
    break;

loc_436a6e:
    edx = 0x0;
    decomp_var_b8 = 0x0;
    decomp_var_bc = 0x4d62f0;
    &decomp_var_dc = &decomp_var_dc;
    goto loc_436a80;
    decomp_var_a8 = decomp_var_c8 + ((decomp_var_c0 << 0x4) - decomp_var_c0) * 0x8;
    edi = decomp_var_c8 + ((decomp_var_c0 << 0x4) - decomp_var_c0) * 0x8 + 0x3628;
    decomp_var_c4 = edi;
    decomp_var_bc = 0x5;
    goto loc_436683;

loc_436500:
    decomp_var_58 = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (edi != decomp_var_58) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esi = decomp_var_c8 + ((decomp_var_c0 << 0x4) - decomp_var_c0) * 0x8 + 0x361c;
            edi = 0x6;
            do {
                    esp = esp - 0x4;
                    eax = sub_41c1e0(&decomp_var_74);
                    esi = esi + 0xc;
                    edi = edi - 0x1;
                    *eax = 0x0;
                    eax[0x1] = 0x0;
            } while (edi != 0x0);
            sub_401590();
            edi = decomp_var_78;
            esi = decomp_var_7c;
            continue;
    }
    break;

loc_436ed2:
    esi = 0x0;
    if (arg_4[0x900] > 0x0) {
            bool_18 = 0x0 > 0x0;
            if (0x0 >= 0x0) {
                    if (!bool_18) {
                            if (0x0 > 0x0) {
                                    edx = *(esi * 0x8 + 0x5f90ec);
                                    esp = esp - 0x20;
                                    *(esi * 0x8 + 0x5f90e8) = sub_47bac0(sub_47bb70(*(esi * 0x8 + 0x5f90e8), edx, 0x64, 0x0), edx, 0x0, 0x0);
                                    *(esi * 0x8 + 0x5f90ec) = edx;
                                    esi = esi + 0x1;
                                    if (esi < arg_4[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    esi = esi + 0x1;
                                    if (esi < arg_4[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            edx = *(esi * 0x8 + 0x5f90ec);
                            esp = esp - 0x20;
                            *(esi * 0x8 + 0x5f90e8) = sub_47bac0(sub_47bb70(*(esi * 0x8 + 0x5f90e8), edx, 0x64, 0x0), edx, 0x0, 0x0);
                            *(esi * 0x8 + 0x5f90ec) = edx;
                            esi = esi + 0x1;
                            if (esi < arg_4[0x900]) {
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    esi = esi + 0x1;
                    if (esi < arg_4[0x900]) {
                            continue;
                    }
                    break;
            }
    }
    eax = arg_4;
    ecx = eax[0x901];
    ebx = 0x0;
    decomp_var_c4 = 0x0;
    if (ecx <= 0x0) goto loc_437437;
    goto loc_436f3e;

loc_436e68:
    edx = eax[0x901];
    goto loc_436e6e;

loc_436d25:
    ebp = eax[0x900];
    ebx = 0x0;
    esi = 0x0;
    ecx = 0x0;
    decomp_var_94 = 0x0;
    if (ebp <= 0x0) goto loc_436d83;
    goto loc_436d39;

loc_436a80:
    if (*(int8_t *)(edx + ecx + 0x3) == 0x0) goto loc_436b7b;
    goto loc_436a8b;

loc_436683:
    esi = *edi[0x1];
    ebp = edi;
    decomp_var_b4 = ebp;
    decomp_var_b0 = esi;
    goto loc_436692;
    ecx = decomp_var_c8;
    eax = ecx[0x2];
    decomp_var_c4 = decomp_var_c4 + 0x24;
    edx = decomp_var_bc + 0x1;
    decomp_var_bc = edx;
    if (edx < eax[0x900]) {
            continue;
    }
    break;

loc_437437:
    eax = decomp_var_c8[0x2];
    ebp = 0x0;
    if (eax[0x901] > 0x0) {
            ebx = 0x0;
            asm { fld1 };
            decomp_var_b8 = ebx;
            do {
                    esi = 0x0;
                    if (eax[0x900] > 0x0) {
                            edi = 0x0;
                            do {
                                    if (*(int8_t *)(eax + edi + 0x3) != 0x0) {
                                            eax = *(int16_t *)(eax + edi + 0x20);
                                            if (HIBYTE(eax) == 0x41) {
                                                    ecx = eax & 0xff;
                                                    if (ecx != 0x14 && ecx != ebp) {
                                                            edx = decomp_var_b8 + esi + decomp_var_b8 + esi + decomp_var_b8 + esi + decomp_var_b8 + esi;
                                                            asm { fcom       qword [edx+edx+0xb76a28] };
                                                            edx = edx + edx;
                                                            asm { fnstsw     ax };
                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                    edx = edx[0x1386bc];
                                                                    *(ecx + ebx + ecx + ebx + ecx + ebx + ecx + ebx + 0xb75578) = *(ecx + ebx + ecx + ebx + ecx + ebx + ecx + ebx + 0xb75578) + 0x1;
                                                                    *(ecx + ebx + ecx + ebx + ecx + ebx + ecx + ebx + 0xb755cc) = *(ecx + ebx + ecx + ebx + ecx + ebx + ecx + ebx + 0xb755cc) + edx;
                                                                    *(ecx + ebx + ecx + ebx + ecx + ebx + ecx + ebx + 0xb75620) = *(ecx + ebx + ecx + ebx + ecx + ebx + ecx + ebx + 0xb75620) + *(((ecx << 0x8) + esi) * 0x8 + 0x4e1af0);
                                                            }
                                                    }
                                            }
                                    }
                                    eax = decomp_var_c8[0x2];
                                    esi = esi + 0x1;
                                    edi = edi + 0x24;
                            } while (esi < eax[0x900]);
                    }
                    eax = decomp_var_c8[0x2];
                    decomp_var_b8 = decomp_var_b8 + 0x100;
                    ebp = &arg_fffffffffffffffd;
                    ebx = ebx + 0x3f;
            } while (ebp < eax[0x901]);
            asm { fstp       st0 };
    }
    &decomp_var_cc = decomp_var_d4;
    return;

loc_436f3e:
    goto loc_436f40;

loc_436e6e:
    if (edx > 0x0) {
            sub_436e80();
    }
    eax = *(esi * 0x8 + 0x5f90ec);
    bool_197 = eax > edi;
    ecx = *(esi * 0x8 + 0x5f90e8);
    if (eax >= edi && (bool_197 || ecx > ebx)) {
            ebx = ecx;
            edi = eax;
    }
    esi = esi + 0x1;
    if (esi < arg_4[0x900]) {
            continue;
    }
    temp_0 = 0x1;
    break;

loc_436d83:
    decomp_var_bc = 0x0;
    if (ebp > 0x0) {
            ecx = ecx + 0x0 + CARRY(EFLAGS(cf));
            edi = esi + 0x1;
            esi = decomp_var_c4;
            ebp = ecx;
            do {
                    edx = esi[0x13b0bd];
                    eax = esi[0x13b0bc];
                    eax = sub_47bb70(eax, edx, 0x64, 0x0);
                    esp = esp - 0x20;
                    eax = sub_47bac0(eax, edx, edi, ebp);
                    bool_215 = ebx > 0x0;
                    esi[0x13b0bc] = eax;
                    esi[0x13b0bd] = edx;
                    if (ebx < 0x0) {
                            esi = esi + 0x8;
                            bool_212 = decomp_var_bc + 0x1 < *(decomp_var_c8[0x2] + 0x2400);
                            decomp_var_bc = decomp_var_bc + 0x1;
                            if (bool_212) {
                                    continue;
                            }
                            break;
                    }
                    if (bool_215) {
                            esp = esp - 0x20;
                            esi[0x16bc3a] = sub_47bac0(sub_47bb70(esi[0x16bc3a], esi[0x16bc3b], 0x64, 0x0), edx, decomp_var_94, ebx);
                            esi[0x16bc3b] = edx;
                            esi = esi + 0x8;
                            bool_216 = decomp_var_bc + 0x1 < *(decomp_var_c8[0x2] + 0x2400);
                            decomp_var_bc = decomp_var_bc + 0x1;
                            if (bool_216) {
                                    continue;
                            }
                            break;
                    }
                    if (decomp_var_94 <= 0x0) {
                            esi = esi + 0x8;
                            bool_217 = decomp_var_bc + 0x1 < *(decomp_var_c8[0x2] + 0x2400);
                            decomp_var_bc = decomp_var_bc + 0x1;
                            if (bool_217) {
                                    continue;
                            }
                            break;
                    }
                    esp = esp - 0x20;
                    esi[0x16bc3a] = sub_47bac0(sub_47bb70(esi[0x16bc3a], esi[0x16bc3b], 0x64, 0x0), edx, decomp_var_94, ebx);
                    esi[0x16bc3b] = edx;
                    esi = esi + 0x8;
                    bool_211 = decomp_var_bc + 0x1 < *(decomp_var_c8[0x2] + 0x2400);
                    decomp_var_bc = decomp_var_bc + 0x1;
            } while (bool_211);
    }
    edx = decomp_var_c8;
    eax = edx[0x2];
    decomp_var_c4 = decomp_var_c4 + 0x800;
    bool_200 = decomp_var_c0 + 0x1 < eax[0x901];
    decomp_var_c0 = decomp_var_c0 + 0x1;
    if (bool_200) {
            continue;
    }
    break;

loc_436d39:
    eax = decomp_var_c4;
    decomp_var_a8 = ebp;
    goto loc_436d41;

loc_436b7b:
    ecx = edi[0x2];
    decomp_var_bc = decomp_var_bc + 0x8;
    ebx = ebx + 0x1;
    edx = edx + 0x24;
    decomp_var_b8 = edx;
    if (ebx < ecx[0x900]) {
            continue;
    }
    break;

loc_436a8b:
    eax = *(int16_t *)(edx + ecx + 0x20);
    if (HIBYTE(eax) != 0x41) goto loc_436b7b;
    goto loc_436a99;

loc_436692:
    ebx = edi[0x1];
    if (ebp == 0x0 || ebp != edi) {
            sub_47a948();
    }
    if (esi == ebx) goto .l44;
    goto loc_4366aa;

loc_436f40:
    decomp_var_c0 = 0x0;
    if (ecx <= 0x0) goto loc_43741b;
    goto loc_436f50;
    if (temp_0 == 0x0) goto .l1;
    goto .l3;

loc_436d41:
    edx = eax[0x13b0bd];
    bool_209 = edx > ecx;
    edi = eax[0x13b0bc];
    if (edx >= ecx && (bool_209 || edi > esi)) {
            esi = edi;
            ecx = edx;
    }
    edx = eax[0x16bc3b];
    bool_207 = edx > ebx;
    edi = eax[0x16bc3a];
    if (edx >= ebx && (bool_207 || edi > decomp_var_94)) {
            decomp_var_94 = edi;
            ebx = edx;
    }
    eax = eax + 0x8;
    decomp_var_a8 = decomp_var_a8 - 0x1;
    if (decomp_var_a8 != 0x0) {
            continue;
    }
    break;

loc_436a99:
    eax = eax & 0xff;
    if (eax == 0x14) goto loc_436b7b;
    goto loc_436aa5;

.l44:
    break;

loc_4366aa:
    if (ebp == 0x0) {
            sub_47a948();
    }
    if (esi == arg_0) {
            sub_47a948();
    }
    edi = esi + 0x10;
    if (esi == arg_0) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_4075b0(edi + 0x4, decomp_var_dc);
    ebx = eax;
    decomp_var_80 = eax;
    decomp_var_b8 = 0xffffffff;
    decomp_var_9c = ebx;
    decomp_var_98 = *eax[0x1];
    goto loc_436700;

loc_43741b:
    eax = decomp_var_c8[0x2];
    ecx = eax[0x901];
    ebx = ebx + 0x1;
    decomp_var_c4 = ebx;
    if (ebx < ecx) {
            continue;
    }
    break;

loc_436f50:
    if (decomp_var_c0 == ebx) goto .l5;
    goto loc_436f5a;

.l3:
    esi = 0x0;
    if (arg_4[0x900] > 0x0) {
            bool_328 = edi > 0x0;
            if (edi >= 0x0) {
                    if (!bool_328) {
                            if (ebx > 0x0) {
                                    edx = *(esi * 0x8 + 0x5f90ec);
                                    esp = esp - 0x20;
                                    *(esi * 0x8 + 0x5f90e8) = sub_47bac0(sub_47bb70(*(esi * 0x8 + 0x5f90e8), edx, 0x64, 0x0), edx, ebx, edi);
                                    *(esi * 0x8 + 0x5f90ec) = edx;
                                    esi = esi + 0x1;
                                    if (esi < arg_4[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    esi = esi + 0x1;
                                    if (esi < arg_4[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            edx = *(esi * 0x8 + 0x5f90ec);
                            esp = esp - 0x20;
                            *(esi * 0x8 + 0x5f90e8) = sub_47bac0(sub_47bb70(*(esi * 0x8 + 0x5f90e8), edx, 0x64, 0x0), edx, ebx, edi);
                            *(esi * 0x8 + 0x5f90ec) = edx;
                            esi = esi + 0x1;
                            if (esi < arg_4[0x900]) {
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    esi = esi + 0x1;
                    if (esi < arg_4[0x900]) {
                            continue;
                    }
                    break;
            }
    }
    eax = arg_4;
    ecx = eax[0x901];
    ebx = 0x0;
    decomp_var_c4 = 0x0;
    if (ecx <= 0x0) goto .l4;
    goto .l2;

loc_436aa5:
    if (eax != decomp_var_c4) goto loc_436b3e;
    goto loc_436aaf;
    edi = edi + 0xc;
    decomp_var_bc = decomp_var_bc - 0x1;
    decomp_var_c4 = edi;
    if (decomp_var_bc != 0x0) {
            continue;
    }
    break;

loc_436700:
    decomp_var_60 = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (decomp_var_98 != decomp_var_60) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (decomp_var_98 == ebx[0x1]) {
                    sub_47a948();
            }
            eax = decomp_var_98;
            ebp = eax + 0xc;
            if (eax[0x3] != decomp_var_b8) {
                    if (eax == ebx[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_41c1e0(ebp);
                    bool_67 = esi != decomp_var_b4[0x1];
                    ebx = *eax;
                    decomp_var_a4 = ebx;
                    decomp_var_a0 = eax[0x1];
                    if (!bool_67) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_b4[0x1]) {
                            sub_47a948();
                    }
                    ecx = edi[0x2];
                    edx = edi[0x3];
                    esi[0x6] = ecx + ebx;
                    esi[0x7] = edx + decomp_var_a0 + CARRY(EFLAGS(cf));
                    if (decomp_var_98 == decomp_var_9c[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_b8 = *ebp;
                    sub_40f400();
                    ebx = decomp_var_9c;
                    eax = decomp_var_80;
                    continue;
            }
            if (eax == ebx[0x1]) {
                    sub_47a948();
            }
            ebx = decomp_var_c4 - 0xc;
            esp = esp - 0x4;
            eax = sub_41c1e0(ebp);
            edx = eax[0x1];
            bool_79 = edx > decomp_var_a0;
            if (edx < decomp_var_a0) {
                    if (decomp_var_98 == decomp_var_9c[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_b8 = *ebp;
                    sub_40f400();
                    ebx = decomp_var_9c;
                    eax = decomp_var_80;
                    continue;
            }
            if (bool_79) {
                    if (esi == decomp_var_b4[0x1]) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_b4[0x1]) {
                            sub_47a948();
                    }
                    eax = edi[0x2];
                    ecx = edi[0x3];
                    esi[0x6] = eax - decomp_var_a4;
                    esi[0x7] = ecx - decomp_var_a0 + CARRY(EFLAGS(cf));
                    if (decomp_var_98 == decomp_var_9c[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_41c1e0(ebp);
                    decomp_var_a4 = *eax;
                    decomp_var_a0 = eax[0x1];
                    if (esi == decomp_var_b4[0x1]) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_b4[0x1]) {
                            sub_47a948();
                    }
                    edx = edi[0x2];
                    eax = edi[0x3];
                    esi[0x6] = edx + decomp_var_a4;
                    esi[0x7] = eax + decomp_var_a0 + CARRY(EFLAGS(cf));
                    if (decomp_var_98 == decomp_var_9c[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_b8 = *ebp;
                    sub_40f400();
                    ebx = decomp_var_9c;
                    eax = decomp_var_80;
                    continue;
            }
            if (*eax > decomp_var_a4) {
                    if (esi == decomp_var_b4[0x1]) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_b4[0x1]) {
                            sub_47a948();
                    }
                    eax = edi[0x2];
                    ecx = edi[0x3];
                    esi[0x6] = eax - decomp_var_a4;
                    esi[0x7] = ecx - decomp_var_a0 + CARRY(EFLAGS(cf));
                    if (decomp_var_98 == decomp_var_9c[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_41c1e0(ebp);
                    decomp_var_a4 = *eax;
                    decomp_var_a0 = eax[0x1];
                    if (esi == decomp_var_b4[0x1]) {
                            sub_47a948();
                    }
                    if (esi == decomp_var_b4[0x1]) {
                            sub_47a948();
                    }
                    edx = edi[0x2];
                    eax = edi[0x3];
                    esi[0x6] = edx + decomp_var_a4;
                    esi[0x7] = eax + decomp_var_a0 + CARRY(EFLAGS(cf));
                    if (decomp_var_98 == decomp_var_9c[0x1]) {
                            sub_47a948();
                    }
                    decomp_var_b8 = *ebp;
                    sub_40f400();
                    ebx = decomp_var_9c;
                    eax = decomp_var_80;
                    continue;
            }
            if (decomp_var_98 == decomp_var_9c[0x1]) {
                    sub_47a948();
            }
            decomp_var_b8 = *ebp;
            sub_40f400();
            ebx = decomp_var_9c;
            eax = decomp_var_80;
            continue;
    }
    break;

.l5:
    edx = decomp_var_c8;
    eax = edx[0x2];
    bool_124 = decomp_var_c0 + 0x1 < eax[0x901];
    decomp_var_c0 = decomp_var_c0 + 0x1;
    if (bool_124) {
            continue;
    }
    break;

loc_436f5a:
    esi = 0x0;
    decomp_var_b4 = 0x0;
    decomp_var_b0 = 0x0;
    decomp_var_a4 = 0x0;
    decomp_var_a0 = 0x0;
    decomp_var_bc = 0x0;
    if (eax[0x900] <= 0x0) goto .l29;
    goto loc_436f7c;

.l4:
    eax = decomp_var_c8[0x2];
    ebp = 0x0;
    if (eax[0x901] > 0x0) {
            ebx = 0x0;
            asm { fld1 };
            decomp_var_b8 = ebx;
            do {
                    esi = 0x0;
                    if (eax[0x900] > 0x0) {
                            edi = 0x0;
                            do {
                                    if (*(int8_t *)(eax + edi + 0x3) != 0x0) {
                                            eax = *(int16_t *)(eax + edi + 0x20);
                                            if (HIBYTE(eax) == 0x41) {
                                                    ecx = eax & 0xff;
                                                    if (ecx != 0x14 && ecx != ebp) {
                                                            edx = decomp_var_b8 + esi + decomp_var_b8 + esi + decomp_var_b8 + esi + decomp_var_b8 + esi;
                                                            asm { fcom       qword [edx+edx+0xb76a28] };
                                                            edx = edx + edx;
                                                            asm { fnstsw     ax };
                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                    edx = edx[0x1386bc];
                                                                    *(ecx + ebx + ecx + ebx + ecx + ebx + ecx + ebx + 0xb75578) = *(ecx + ebx + ecx + ebx + ecx + ebx + ecx + ebx + 0xb75578) + 0x1;
                                                                    *(ecx + ebx + ecx + ebx + ecx + ebx + ecx + ebx + 0xb755cc) = *(ecx + ebx + ecx + ebx + ecx + ebx + ecx + ebx + 0xb755cc) + edx;
                                                                    *(ecx + ebx + ecx + ebx + ecx + ebx + ecx + ebx + 0xb75620) = *(ecx + ebx + ecx + ebx + ecx + ebx + ecx + ebx + 0xb75620) + *(((ecx << 0x8) + esi) * 0x8 + 0x4e1af0);
                                                            }
                                                    }
                                            }
                                    }
                                    eax = decomp_var_c8[0x2];
                                    esi = esi + 0x1;
                                    edi = edi + 0x24;
                            } while (esi < eax[0x900]);
                    }
                    eax = decomp_var_c8[0x2];
                    decomp_var_b8 = decomp_var_b8 + 0x100;
                    ebp = &arg_fffffffffffffffd;
                    ebx = ebx + 0x3f;
            } while (ebp < eax[0x901]);
            asm { fstp       st0 };
    }
    &decomp_var_cc = decomp_var_d4;
    return;

.l2:
    goto .l15;

loc_436b3e:
    ecx = esi + ebx + esi + ebx + esi + ebx + esi + ebx;
    asm { fild       qword [ecx+ecx+0x4d62f0] };
    ecx = ecx + ecx;
    decomp_var_7c = &arg_fffffffffffffffd;
    asm { fild       qword [esp+0xdc+-124] };
    asm { fdivp      st1 };
    asm { fstp       qword [ecx+0xb76a28] };
    goto loc_436b7b;

loc_436aaf:
    ecx = ecx[0x901];
    ebp = 0x0;
    decomp_var_b4 = 0x0;
    decomp_var_b0 = 0x0;
    decomp_var_a8 = ecx;
    if (ecx <= 0x0) goto loc_436b07;
    goto loc_436ac7;
    esi = *decomp_var_a8[0xd88];
    ebx = decomp_var_a8 + 0x361c;
    edi = ebx;
    decomp_var_94 = edi;
    decomp_var_90 = esi;
    goto loc_436940;
    if (esi == arg_0) {
            sub_47a948();
            if (esi == arg_0) {
                    sub_47a948();
                    if (esi == arg_0) {
                            sub_47a948();
                    }
            }
    }
    esp = esp - 0x4;
    eax = sub_41c1e0(edi);
    ecx = edi[0x2];
    ecx = ecx + *eax;
    edx = edi[0x3];
    edx = edx + eax[0x1] + CARRY(EFLAGS(cf));
    esi[0x6] = ecx;
    esi[0x7] = edx;
    if (esi == arg_0) {
            sub_47a948();
            if (esi == arg_0) {
                    sub_47a948();
            }
    }
    esp = esp - 0x10;
    esi[0x6] = sub_47bac0(edi[0x2], edi[0x3], 0x5, 0x0);
    esi[0x7] = edx;
    sub_40f6f0();
    esi = decomp_var_b0;
    ebp = decomp_var_b4;
    edi = decomp_var_c4;
    continue;

.l29:
    edx = decomp_var_c8;
    eax = edx[0x2];
    bool_114 = decomp_var_c0 + 0x1 < eax[0x901];
    decomp_var_c0 = decomp_var_c0 + 0x1;
    if (bool_114) {
            continue;
    }
    break;

loc_436f7c:
    asm { fld        qword [qword_value_4636737291354636288] };
    asm { fld        qword [qword_value_4618441417868443648] };
    sub_47b370();
    asm { fstp       qword [esp+0xdc+-100] };
    asm { fld        qword [qword_value_4636737291354636288] };
    asm { fld        qword [qword_value_4617315517961601024] };
    sub_47b370();
    asm { fstp       qword [esp+0xdc+-116] };
    asm { fld        qword [qword_value_4636737291354636288] };
    asm { fld        qword [qword_value_4611686018427387904] };
    sub_47b370();
    asm { fstp       qword [esp+0xdc+-124] };
    ebx = ebx << 0xb;
    ebp = 0x0;
    edi = decomp_var_c0 << 0xb;
    decomp_var_80 = ebx;
    decomp_var_a8 = ebx;
    decomp_var_b8 = edi;
    goto loc_436fd3;

.l15:
    decomp_var_c0 = 0x0;
    if (ecx <= 0x0) goto .l12;
    goto .l31;

loc_436b07:
    asm { fild       qword [esp+0xdc+-180] };
    ecx = *(((eax << 0x8) + ebx) * 0x8 + 0x4d62f0);
    decomp_var_94 = ecx + 0x1;
    decomp_var_90 = *(((eax << 0x8) + ebx) * 0x8 + 0x4d62f4) + 0x0 + CARRY(EFLAGS(cf));
    asm { fild       qword [esp+0xdc+-148] };
    ecx = esi + ebx;
    asm { fdivp      st1 };
    asm { fstp       qword [dword_633f14+5516052+ecx*8] };
    goto loc_436b7b;

loc_436ac7:
    esi = decomp_var_bc;
    goto loc_436acb;

loc_436940:
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
            bool_88 = esi != edi[0x1];
            decomp_var_74 = esi[0x4];
            if (!bool_88) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            esi = ((decomp_var_c0 << 0x8) + esi[0x4]) * 0x8 + 0x4d62f0;
            eax = sub_41c1e0(&decomp_var_74);
            *esi = *esi + *eax;
            esi[0x1] = esi[0x1] + eax[0x1] + CARRY(EFLAGS(cf));
            sub_40f6f0();
            esi = decomp_var_90;
            edi = decomp_var_94;
            continue;
    }
    break;

loc_436fd3:
    asm { fild       qword [ebx+0x5af0e8] };
    asm { fst        qword [esp+0xdc+-140] };
    asm { fild       qword [edi+0x4ec2f0] };
    asm { fstp       qword [esp+0xdc+-148] };
    asm { fld        qword [qword_value_4621256167635550208] };
    sub_47b370();
    asm { fdiv       qword [esp+0xdc+-100] };
    asm { fstp       qword [esp+0xdc+-92] };
    asm { fld        qword [esp+0xdc+-148] };
    asm { fld        qword [qword_value_4620693217682128896] };
    sub_47b370();
    asm { fmul       qword [esp+0xdc+-92] };
    asm { fdiv       qword [esp+0xdc+-116] };
    eax = sub_47b5f6();
    asm { fld        qword [esp+0xdc+-140] };
    asm { fld        qword [aOurMovesAnalys+80] };
    *(esi * 0x8 + 0x4e12f0) = eax;
    *(esi * 0x8 + 0x4e12f4) = edx;
    sub_47b370();
    asm { fdiv       qword [esp+0xdc+-124] };
    asm { fstp       qword [esp+0xdc+-92] };
    asm { fld        qword [esp+0xdc+-148] };
    asm { fld        qword [aOurMovesAnalys+80] };
    sub_47b370();
    asm { fmul       qword [esp+0xdc+-92] };
    asm { fdiv       qword [esp+0xdc+-124] };
    *(esi * 0x8 + 0x4e0af0) = sub_47b5f6();
    *(esi * 0x8 + 0x4e0af4) = edx;
    edx = ebx[0x1386bc];
    edx = edx | ebx[0x1386bd];
    if (edx == 0x0 || (edi[0x1386bc] | edi[0x1386bd]) == 0x0) {
            *(esi * 0x8 + 0x4e12f0) = 0x0;
            *(esi * 0x8 + 0x4e0af0) = 0x0;
            *(esi * 0x8 + 0x4e12f4) = 0x0;
            *(esi * 0x8 + 0x4e0af4) = 0x0;
    }
    eax = *(esi * 0x8 + 0x4e12f4);
    bool_175 = eax > decomp_var_b0;
    ecx = *(esi * 0x8 + 0x4e12f0);
    if (eax >= decomp_var_b0 && (bool_175 || ecx > decomp_var_b4)) {
            decomp_var_b4 = ecx;
            decomp_var_b0 = eax;
    }
    ecx = *(esi * 0x8 + 0x4e0af4);
    bool_183 = ecx > decomp_var_a0;
    if (ecx >= decomp_var_a0) {
            if (!bool_183) {
                    edx = *(esi * 0x8 + 0x4e0af0);
                    if (edx > decomp_var_a4) {
                            ecx = decomp_var_c8[0x2];
                            ebx = *(ecx + ebp + 0x18);
                            edx = &decomp_var_c0;
                            esi = ecx + ebp + 0x14;
                            esp = esp - 0x8;
                            eax = sub_401ff0(&decomp_var_9c, edx, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                            edi = eax;
                            eax = *edi;
                            if (eax == 0x0 || eax != esi) {
                                    sub_47a948();
                            }
                            if (edi[0x1] == ebx) {
                                    edx = decomp_var_c8[0x2];
                                    ebx = *(edx + ebp + 0x18);
                                    esi = edx + ebp + 0x14;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&decomp_var_24, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                                    edi = eax;
                                    eax = *edi;
                                    if (eax == 0x0 || eax != esi) {
                                            sub_47a948();
                                    }
                                    if (edi[0x1] == ebx) {
                                            edx = *(decomp_var_bc * 0x8 + 0x4e0af0);
                                            decomp_var_a4 = edx;
                                            decomp_var_a0 = *(decomp_var_bc * 0x8 + 0x4e0af4);
                                    }
                            }
                            eax = decomp_var_c8;
                            ecx = eax[0x2];
                            esi = decomp_var_bc + 0x1;
                            ebx = decomp_var_a8 + 0x8;
                            edi = decomp_var_b8 + 0x8;
                            ebp = &arg_20;
                            decomp_var_bc = esi;
                            decomp_var_a8 = ebx;
                            decomp_var_b8 = edi;
                            if (esi < ecx[0x900]) {
                                    continue;
                            }
                            break;
                    }
                    else {
                            eax = decomp_var_c8;
                            ecx = eax[0x2];
                            esi = decomp_var_bc + 0x1;
                            ebx = decomp_var_a8 + 0x8;
                            edi = decomp_var_b8 + 0x8;
                            ebp = &arg_20;
                            decomp_var_bc = esi;
                            decomp_var_a8 = ebx;
                            decomp_var_b8 = edi;
                            if (esi < ecx[0x900]) {
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    ecx = decomp_var_c8[0x2];
                    ebx = *(ecx + ebp + 0x18);
                    edx = &decomp_var_c0;
                    esi = ecx + ebp + 0x14;
                    esp = esp - 0x8;
                    eax = sub_401ff0(&decomp_var_9c, edx, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    edi = eax;
                    eax = *edi;
                    if (eax == 0x0 || eax != esi) {
                            sub_47a948();
                    }
                    if (edi[0x1] == ebx) {
                            edx = decomp_var_c8[0x2];
                            ebx = *(edx + ebp + 0x18);
                            esi = edx + ebp + 0x14;
                            esp = esp - 0x8;
                            eax = sub_401ff0(&decomp_var_24, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                            edi = eax;
                            eax = *edi;
                            if (eax == 0x0 || eax != esi) {
                                    sub_47a948();
                            }
                            if (edi[0x1] == ebx) {
                                    edx = *(decomp_var_bc * 0x8 + 0x4e0af0);
                                    decomp_var_a4 = edx;
                                    decomp_var_a0 = *(decomp_var_bc * 0x8 + 0x4e0af4);
                            }
                    }
                    eax = decomp_var_c8;
                    ecx = eax[0x2];
                    esi = decomp_var_bc + 0x1;
                    ebx = decomp_var_a8 + 0x8;
                    edi = decomp_var_b8 + 0x8;
                    ebp = &arg_20;
                    decomp_var_bc = esi;
                    decomp_var_a8 = ebx;
                    decomp_var_b8 = edi;
                    if (esi < ecx[0x900]) {
                            continue;
                    }
                    break;
            }
    }
    else {
            eax = decomp_var_c8;
            ecx = eax[0x2];
            esi = decomp_var_bc + 0x1;
            ebx = decomp_var_a8 + 0x8;
            edi = decomp_var_b8 + 0x8;
            ebp = &arg_20;
            decomp_var_bc = esi;
            decomp_var_a8 = ebx;
            decomp_var_b8 = edi;
            if (esi < ecx[0x900]) {
                    continue;
            }
            break;
    }
    goto .l10;

.l12:
    eax = decomp_var_c8[0x2];
    ecx = eax[0x901];
    ebx = ebx + 0x1;
    decomp_var_c4 = ebx;
    if (ebx < ecx) {
            continue;
    }
    break;

.l31:
    if (decomp_var_c0 == ebx) goto .l19;
    goto .l30;

loc_436acb:
    if (ebp != decomp_var_c4) {
            edx = esi[0x1];
            bool_316 = decomp_var_b0 < edx;
            edi = *esi;
            if (decomp_var_b0 <= edx && (bool_316 || decomp_var_b4 < edi)) {
                    decomp_var_b4 = edi;
                    decomp_var_b0 = edx;
            }
    }
    ebp = &arg_fffffffffffffffd;
    esi = esi + 0x800;
    if (ebp < decomp_var_a8) {
            continue;
    }
    break;
    ecx = decomp_var_c8;
    eax = ecx[0x2];
    ebp = &arg_fffffffffffffffd;
    decomp_var_c0 = ebp;
    if (ebp < eax[0x901]) {
            continue;
    }
    break;

.l10:
    bool_112 = decomp_var_b0 > 0x0;
    if (decomp_var_b0 >= 0x0) {
            if (!bool_112) {
                    if (decomp_var_b4 > 0x0) {
                            edi = 0x0;
                            if (ecx[0x900] > 0x0) {
                                    ebp = decomp_var_c4;
                                    asm { fild       qword [esp+0xdc+-180] };
                                    esi = decomp_var_80 + 0x5a48e8;
                                    ebp = (ebp * 0x15 + decomp_var_c0) * 0x8 + 0xb84948;
                                    ebx = eax;
                                    do {
                                            asm { fild       qword [dword_4ca540+93616+edi*8] };
                                            asm { fmul       qword [ebp] };
                                            asm { fdiv       st1 };
                                            eax = sub_47b5c0();
                                            *esi = *esi + eax;
                                            esi[0x1] = esi[0x1] + (eax & 0x80000000 ? 0xffffffff : 0x0) + CARRY(EFLAGS(cf));
                                            edi = edi + 0x1;
                                            esi = esi + 0x8;
                                    } while (edi < *(ebx[0x2] + 0x2400));
                                    asm { fstp       st0 };
                                    eax = ebx;
                            }
                    }
            }
            else {
                    edi = 0x0;
                    if (ecx[0x900] > 0x0) {
                            ebp = decomp_var_c4;
                            asm { fild       qword [esp+0xdc+-180] };
                            esi = decomp_var_80 + 0x5a48e8;
                            ebp = (ebp * 0x15 + decomp_var_c0) * 0x8 + 0xb84948;
                            ebx = eax;
                            do {
                                    asm { fild       qword [dword_4ca540+93616+edi*8] };
                                    asm { fmul       qword [ebp] };
                                    asm { fdiv       st1 };
                                    eax = sub_47b5c0();
                                    *esi = *esi + eax;
                                    esi[0x1] = esi[0x1] + (eax & 0x80000000 ? 0xffffffff : 0x0) + CARRY(EFLAGS(cf));
                                    edi = edi + 0x1;
                                    esi = esi + 0x8;
                            } while (edi < *(ebx[0x2] + 0x2400));
                            asm { fstp       st0 };
                            eax = ebx;
                    }
            }
    }
    bool_120 = decomp_var_a0 > 0x0;
    if (decomp_var_a0 < 0x0) goto loc_4373f9;
    goto loc_43722c;

.l19:
    edx = decomp_var_c8;
    eax = edx[0x2];
    bool_235 = decomp_var_c0 + 0x1 < eax[0x901];
    decomp_var_c0 = decomp_var_c0 + 0x1;
    if (bool_235) {
            continue;
    }
    break;

.l30:
    esi = 0x0;
    decomp_var_b4 = 0x0;
    decomp_var_b0 = 0x0;
    decomp_var_a4 = 0x0;
    decomp_var_a0 = 0x0;
    decomp_var_bc = 0x0;
    if (eax[0x900] <= 0x0) goto .l21;
    goto .l22;
    esi = decomp_var_c0;
    edx = decomp_var_b8;
    edi = decomp_var_c8;
    goto loc_436b07;

loc_4373f9:
    ebx = decomp_var_c4;
    edx = decomp_var_c8;
    eax = edx[0x2];
    bool_113 = decomp_var_c0 + 0x1 < eax[0x901];
    decomp_var_c0 = decomp_var_c0 + 0x1;
    if (bool_113) {
            continue;
    }
    break;

loc_43722c:
    if (bool_120) goto .l6;
    goto loc_43722e;

.l21:
    edx = decomp_var_c8;
    eax = edx[0x2];
    bool_227 = decomp_var_c0 + 0x1 < eax[0x901];
    decomp_var_c0 = decomp_var_c0 + 0x1;
    if (bool_227) {
            continue;
    }
    break;

.l22:
    asm { fld        qword [qword_value_4636737291354636288] };
    asm { fld        qword [qword_value_4618441417868443648] };
    sub_47b370();
    asm { fstp       qword [esp+0xdc+-100] };
    asm { fld        qword [qword_value_4636737291354636288] };
    asm { fld        qword [qword_value_4617315517961601024] };
    sub_47b370();
    asm { fstp       qword [esp+0xdc+-116] };
    asm { fld        qword [qword_value_4636737291354636288] };
    asm { fld        qword [qword_value_4611686018427387904] };
    sub_47b370();
    asm { fstp       qword [esp+0xdc+-124] };
    ebx = ebx << 0xb;
    ebp = 0x0;
    edi = decomp_var_c0 << 0xb;
    decomp_var_80 = ebx;
    decomp_var_a8 = ebx;
    decomp_var_b8 = edi;
    goto .l33;

.l6:
    edi = eax[0x2];
    esi = 0x0;
    decomp_var_bc = 0x0;
    if (edi[0x900] <= 0x0) goto .l7;
    goto loc_43724e;

loc_43722e:
    if (decomp_var_a4 <= 0x0) goto .l13;
    goto loc_437239;

.l33:
    asm { fild       qword [ebx+0x5af0e8] };
    asm { fst        qword [esp+0xdc+-140] };
    asm { fild       qword [edi+0x4ec2f0] };
    asm { fstp       qword [esp+0xdc+-148] };
    asm { fld        qword [qword_value_4621256167635550208] };
    sub_47b370();
    asm { fdiv       qword [esp+0xdc+-100] };
    asm { fstp       qword [esp+0xdc+-92] };
    asm { fld        qword [esp+0xdc+-148] };
    asm { fld        qword [qword_value_4620693217682128896] };
    sub_47b370();
    asm { fmul       qword [esp+0xdc+-92] };
    asm { fdiv       qword [esp+0xdc+-116] };
    eax = sub_47b5f6();
    asm { fld        qword [esp+0xdc+-140] };
    asm { fld        qword [aOurMovesAnalys+80] };
    *(esi * 0x8 + 0x4e12f0) = eax;
    *(esi * 0x8 + 0x4e12f4) = edx;
    sub_47b370();
    asm { fdiv       qword [esp+0xdc+-124] };
    asm { fstp       qword [esp+0xdc+-92] };
    asm { fld        qword [esp+0xdc+-148] };
    asm { fld        qword [aOurMovesAnalys+80] };
    sub_47b370();
    asm { fmul       qword [esp+0xdc+-92] };
    asm { fdiv       qword [esp+0xdc+-124] };
    *(esi * 0x8 + 0x4e0af0) = sub_47b5f6();
    *(esi * 0x8 + 0x4e0af4) = edx;
    edx = ebx[0x1386bc];
    edx = edx | ebx[0x1386bd];
    if (edx == 0x0 || (edi[0x1386bc] | edi[0x1386bd]) == 0x0) {
            *(esi * 0x8 + 0x4e12f0) = 0x0;
            *(esi * 0x8 + 0x4e0af0) = 0x0;
            *(esi * 0x8 + 0x4e12f4) = 0x0;
            *(esi * 0x8 + 0x4e0af4) = 0x0;
    }
    eax = *(esi * 0x8 + 0x4e12f4);
    bool_240 = eax > decomp_var_b0;
    ecx = *(esi * 0x8 + 0x4e12f0);
    if (eax >= decomp_var_b0 && (bool_240 || ecx > decomp_var_b4)) {
            decomp_var_b4 = ecx;
            decomp_var_b0 = eax;
    }
    ecx = *(esi * 0x8 + 0x4e0af4);
    bool_258 = ecx > decomp_var_a0;
    if (ecx >= decomp_var_a0) {
            if (!bool_258) {
                    edx = *(esi * 0x8 + 0x4e0af0);
                    if (edx > decomp_var_a4) {
                            ecx = decomp_var_c8[0x2];
                            ebx = *(ecx + ebp + 0x18);
                            edx = &decomp_var_c0;
                            esi = ecx + ebp + 0x14;
                            esp = esp - 0x8;
                            eax = sub_401ff0(&decomp_var_9c, edx, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                            edi = eax;
                            eax = *edi;
                            if (eax == 0x0 || eax != esi) {
                                    sub_47a948();
                            }
                            if (edi[0x1] == ebx) {
                                    edx = decomp_var_c8[0x2];
                                    ebx = *(edx + ebp + 0x18);
                                    esi = edx + ebp + 0x14;
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&decomp_var_24, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                                    edi = eax;
                                    eax = *edi;
                                    if (eax == 0x0 || eax != esi) {
                                            sub_47a948();
                                    }
                                    if (edi[0x1] == ebx) {
                                            edx = *(decomp_var_bc * 0x8 + 0x4e0af0);
                                            decomp_var_a4 = edx;
                                            decomp_var_a0 = *(decomp_var_bc * 0x8 + 0x4e0af4);
                                    }
                            }
                            eax = decomp_var_c8;
                            ecx = eax[0x2];
                            esi = decomp_var_bc + 0x1;
                            ebx = decomp_var_a8 + 0x8;
                            edi = decomp_var_b8 + 0x8;
                            ebp = &arg_20;
                            decomp_var_bc = esi;
                            decomp_var_a8 = ebx;
                            decomp_var_b8 = edi;
                            if (esi < ecx[0x900]) {
                                    continue;
                            }
                            break;
                    }
                    else {
                            eax = decomp_var_c8;
                            ecx = eax[0x2];
                            esi = decomp_var_bc + 0x1;
                            ebx = decomp_var_a8 + 0x8;
                            edi = decomp_var_b8 + 0x8;
                            ebp = &arg_20;
                            decomp_var_bc = esi;
                            decomp_var_a8 = ebx;
                            decomp_var_b8 = edi;
                            if (esi < ecx[0x900]) {
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    ecx = decomp_var_c8[0x2];
                    ebx = *(ecx + ebp + 0x18);
                    edx = &decomp_var_c0;
                    esi = ecx + ebp + 0x14;
                    esp = esp - 0x8;
                    eax = sub_401ff0(&decomp_var_9c, edx, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    edi = eax;
                    eax = *edi;
                    if (eax == 0x0 || eax != esi) {
                            sub_47a948();
                    }
                    if (edi[0x1] == ebx) {
                            edx = decomp_var_c8[0x2];
                            ebx = *(edx + ebp + 0x18);
                            esi = edx + ebp + 0x14;
                            esp = esp - 0x8;
                            eax = sub_401ff0(&decomp_var_24, &decomp_var_c4, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                            edi = eax;
                            eax = *edi;
                            if (eax == 0x0 || eax != esi) {
                                    sub_47a948();
                            }
                            if (edi[0x1] == ebx) {
                                    edx = *(decomp_var_bc * 0x8 + 0x4e0af0);
                                    decomp_var_a4 = edx;
                                    decomp_var_a0 = *(decomp_var_bc * 0x8 + 0x4e0af4);
                            }
                    }
                    eax = decomp_var_c8;
                    ecx = eax[0x2];
                    esi = decomp_var_bc + 0x1;
                    ebx = decomp_var_a8 + 0x8;
                    edi = decomp_var_b8 + 0x8;
                    ebp = &arg_20;
                    decomp_var_bc = esi;
                    decomp_var_a8 = ebx;
                    decomp_var_b8 = edi;
                    if (esi < ecx[0x900]) {
                            continue;
                    }
                    break;
            }
    }
    else {
            eax = decomp_var_c8;
            ecx = eax[0x2];
            esi = decomp_var_bc + 0x1;
            ebx = decomp_var_a8 + 0x8;
            edi = decomp_var_b8 + 0x8;
            ebp = &arg_20;
            decomp_var_bc = esi;
            decomp_var_a8 = ebx;
            decomp_var_b8 = edi;
            if (esi < ecx[0x900]) {
                    continue;
            }
            break;
    }
    goto .l32;

.l7:
    ebx = decomp_var_c4;
    edx = decomp_var_c8;
    eax = edx[0x2];
    bool_117 = decomp_var_c0 + 0x1 < eax[0x901];
    decomp_var_c0 = decomp_var_c0 + 0x1;
    if (bool_117) {
            continue;
    }
    break;

loc_43724e:
    ecx = decomp_var_c4;
    asm { fild       qword [esp+0xdc+-164] };
    ecx = ecx * 0x15;
    asm { fstp       qword [esp+0xdc+-100] };
    decomp_var_80 = (ecx + decomp_var_c0) * 0x8 + 0xb84948;
    goto .l9;

.l13:
    ebx = decomp_var_c4;
    edx = decomp_var_c8;
    eax = edx[0x2];
    bool_128 = decomp_var_c0 + 0x1 < eax[0x901];
    decomp_var_c0 = decomp_var_c0 + 0x1;
    if (bool_128) {
            continue;
    }
    break;

loc_437239:
    edi = eax[0x2];
    esi = 0x0;
    decomp_var_bc = 0x0;
    if (edi[0x900] <= 0x0) goto .l14;
    goto .l8;

.l32:
    bool_234 = decomp_var_b0 > 0x0;
    if (decomp_var_b0 >= 0x0) {
            if (!bool_234) {
                    if (decomp_var_b4 > 0x0) {
                            edi = 0x0;
                            if (ecx[0x900] > 0x0) {
                                    ebp = decomp_var_c4;
                                    asm { fild       qword [esp+0xdc+-180] };
                                    esi = decomp_var_80 + 0x5a48e8;
                                    ebp = (ebp * 0x15 + decomp_var_c0) * 0x8 + 0xb84948;
                                    ebx = eax;
                                    do {
                                            asm { fild       qword [dword_4ca540+93616+edi*8] };
                                            asm { fmul       qword [ebp] };
                                            asm { fdiv       st1 };
                                            eax = sub_47b5c0();
                                            *esi = *esi + eax;
                                            esi[0x1] = esi[0x1] + (eax & 0x80000000 ? 0xffffffff : 0x0) + CARRY(EFLAGS(cf));
                                            edi = edi + 0x1;
                                            esi = esi + 0x8;
                                    } while (edi < *(ebx[0x2] + 0x2400));
                                    asm { fstp       st0 };
                                    eax = ebx;
                            }
                    }
            }
            else {
                    edi = 0x0;
                    if (ecx[0x900] > 0x0) {
                            ebp = decomp_var_c4;
                            asm { fild       qword [esp+0xdc+-180] };
                            esi = decomp_var_80 + 0x5a48e8;
                            ebp = (ebp * 0x15 + decomp_var_c0) * 0x8 + 0xb84948;
                            ebx = eax;
                            do {
                                    asm { fild       qword [dword_4ca540+93616+edi*8] };
                                    asm { fmul       qword [ebp] };
                                    asm { fdiv       st1 };
                                    eax = sub_47b5c0();
                                    *esi = *esi + eax;
                                    esi[0x1] = esi[0x1] + (eax & 0x80000000 ? 0xffffffff : 0x0) + CARRY(EFLAGS(cf));
                                    edi = edi + 0x1;
                                    esi = esi + 0x8;
                            } while (edi < *(ebx[0x2] + 0x2400));
                            asm { fstp       st0 };
                            eax = ebx;
                    }
            }
    }
    bool_226 = decomp_var_a0 > 0x0;
    if (decomp_var_a0 < 0x0) goto .l28;
    goto .l18;

.l9:
    asm { fild       qword [dword_4ca540+91568+esi*8] };
    asm { fmul       qword [eax] };
    asm { fdiv       qword [esp+0xdc+-100] };
    eax = sub_47b5c0();
    decomp_var_b8 = eax;
    if (decomp_var_c4 == decomp_var_68) {
            if (eax > 0x0) {
                    ebp = edi[0x915];
                    edi = edi + 0x2450;
                    esp = esp - 0x8;
                    eax = sub_402060(&decomp_var_2c, &decomp_var_bc, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    ebx = eax;
                    eax = *ebx;
                    if (eax == 0x0 || eax != edi) {
                            sub_47a948();
                    }
                    if (ebx[0x1] == ebp) {
                            eax = *(esi * 0x4 + 0xba2f70);
                            ecx = decomp_var_c0;
                            decomp_var_50 = 0x0;
                            decomp_var_44 = 0x1;
                            if (eax == ecx) {
                                    decomp_var_44 = 0x0;
                            }
                            else {
                            }
                            eax = decomp_var_c8[0x2];
                            bool_160 = *(int8_t *)(eax + (esi + esi * 0x8) * 0x4 + 0x3) == 0x0;
                            eax = eax + (esi + esi * 0x8) * 0x4;
                            if (!bool_160) {
                                    eax = eax[0x10];
                                    if (HIBYTE(eax) == 0x41) {
                                            eax = eax & 0xff;
                                            if (eax != 0x14) {
                                                    if (eax == decomp_var_68) {
                                                            decomp_var_44 = 0x0;
                                                            eax = &decomp_var_1c;
                                                    }
                                                    else {
                                                            eax = &decomp_var_1c;
                                                    }
                                                    decomp_var_40 = decomp_var_b8;
                                                    esp = esp - 0x8;
                                                    sub_419d80(eax, &decomp_var_40, decomp_var_dc);
                                                    edi = decomp_var_c8[0x2];
                                                    esi = esi + 0x1;
                                                    decomp_var_bc = esi;
                                                    if (esi < edi[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    edi = decomp_var_c8[0x2];
                                                    esi = esi + 0x1;
                                                    decomp_var_bc = esi;
                                                    if (esi < edi[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            edi = decomp_var_c8[0x2];
                                            esi = esi + 0x1;
                                            decomp_var_bc = esi;
                                            if (esi < edi[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    eax = &decomp_var_10;
                                    decomp_var_40 = decomp_var_b8;
                                    esp = esp - 0x8;
                                    sub_419d80(eax, &decomp_var_40, decomp_var_dc);
                                    edi = decomp_var_c8[0x2];
                                    esi = esi + 0x1;
                                    decomp_var_bc = esi;
                                    if (esi < edi[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            edi = decomp_var_c8[0x2];
                            esi = esi + 0x1;
                            decomp_var_bc = esi;
                            if (esi < edi[0x900]) {
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    edi = decomp_var_c8[0x2];
                    esi = esi + 0x1;
                    decomp_var_bc = esi;
                    if (esi < edi[0x900]) {
                            continue;
                    }
                    break;
            }
    }
    else {
            edi = decomp_var_c8[0x2];
            esi = esi + 0x1;
            decomp_var_bc = esi;
            if (esi < edi[0x900]) {
                    continue;
            }
            break;
    }
    goto .l7;

.l14:
    ebx = decomp_var_c4;
    edx = decomp_var_c8;
    eax = edx[0x2];
    bool_116 = decomp_var_c0 + 0x1 < eax[0x901];
    decomp_var_c0 = decomp_var_c0 + 0x1;
    if (bool_116) {
            continue;
    }
    break;

.l8:
    ecx = decomp_var_c4;
    asm { fild       qword [esp+0xdc+-164] };
    ecx = ecx * 0x15;
    asm { fstp       qword [esp+0xdc+-100] };
    decomp_var_80 = (ecx + decomp_var_c0) * 0x8 + 0xb84948;
    goto loc_43726c;

.l28:
    ebx = decomp_var_c4;
    edx = decomp_var_c8;
    eax = edx[0x2];
    bool_230 = decomp_var_c0 + 0x1 < eax[0x901];
    decomp_var_c0 = decomp_var_c0 + 0x1;
    if (bool_230) {
            continue;
    }
    break;

.l18:
    if (bool_226) goto .l17;
    goto .l23;

loc_43726c:
    asm { fild       qword [dword_4ca540+91568+esi*8] };
    asm { fmul       qword [eax] };
    asm { fdiv       qword [esp+0xdc+-100] };
    eax = sub_47b5c0();
    decomp_var_b8 = eax;
    if (decomp_var_c4 == decomp_var_68) {
            if (eax > 0x0) {
                    ebp = edi[0x915];
                    edi = edi + 0x2450;
                    esp = esp - 0x8;
                    eax = sub_402060(&decomp_var_2c, &decomp_var_bc, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    ebx = eax;
                    eax = *ebx;
                    if (eax == 0x0 || eax != edi) {
                            sub_47a948();
                    }
                    if (ebx[0x1] == ebp) {
                            eax = *(esi * 0x4 + 0xba2f70);
                            ecx = decomp_var_c0;
                            decomp_var_50 = 0x0;
                            decomp_var_44 = 0x1;
                            if (eax == ecx) {
                                    decomp_var_44 = 0x0;
                            }
                            else {
                            }
                            eax = decomp_var_c8[0x2];
                            bool_139 = *(int8_t *)(eax + (esi + esi * 0x8) * 0x4 + 0x3) == 0x0;
                            eax = eax + (esi + esi * 0x8) * 0x4;
                            if (!bool_139) {
                                    eax = eax[0x10];
                                    if (HIBYTE(eax) == 0x41) {
                                            eax = eax & 0xff;
                                            if (eax != 0x14) {
                                                    if (eax == decomp_var_68) {
                                                            decomp_var_44 = 0x0;
                                                            eax = &decomp_var_1c;
                                                    }
                                                    else {
                                                            eax = &decomp_var_1c;
                                                    }
                                                    decomp_var_40 = decomp_var_b8;
                                                    esp = esp - 0x8;
                                                    sub_419d80(eax, &decomp_var_40, decomp_var_dc);
                                                    edi = decomp_var_c8[0x2];
                                                    esi = esi + 0x1;
                                                    decomp_var_bc = esi;
                                                    if (esi < edi[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    edi = decomp_var_c8[0x2];
                                                    esi = esi + 0x1;
                                                    decomp_var_bc = esi;
                                                    if (esi < edi[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            edi = decomp_var_c8[0x2];
                                            esi = esi + 0x1;
                                            decomp_var_bc = esi;
                                            if (esi < edi[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    eax = &decomp_var_10;
                                    decomp_var_40 = decomp_var_b8;
                                    esp = esp - 0x8;
                                    sub_419d80(eax, &decomp_var_40, decomp_var_dc);
                                    edi = decomp_var_c8[0x2];
                                    esi = esi + 0x1;
                                    decomp_var_bc = esi;
                                    if (esi < edi[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            edi = decomp_var_c8[0x2];
                            esi = esi + 0x1;
                            decomp_var_bc = esi;
                            if (esi < edi[0x900]) {
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    edi = decomp_var_c8[0x2];
                    esi = esi + 0x1;
                    decomp_var_bc = esi;
                    if (esi < edi[0x900]) {
                            continue;
                    }
                    break;
            }
    }
    else {
            edi = decomp_var_c8[0x2];
            esi = esi + 0x1;
            decomp_var_bc = esi;
            if (esi < edi[0x900]) {
                    continue;
            }
            break;
    }
    goto .l14;

.l17:
    edi = eax[0x2];
    esi = 0x0;
    decomp_var_bc = 0x0;
    if (edi[0x900] <= 0x0) goto .l26;
    goto .l27;

.l23:
    if (decomp_var_a4 <= 0x0) goto .l25;
    goto .l20;

.l26:
    ebx = decomp_var_c4;
    edx = decomp_var_c8;
    eax = edx[0x2];
    bool_233 = decomp_var_c0 + 0x1 < eax[0x901];
    decomp_var_c0 = decomp_var_c0 + 0x1;
    if (bool_233) {
            continue;
    }
    break;

.l27:
    ecx = decomp_var_c4;
    asm { fild       qword [esp+0xdc+-164] };
    ecx = ecx * 0x15;
    asm { fstp       qword [esp+0xdc+-100] };
    decomp_var_80 = (ecx + decomp_var_c0) * 0x8 + 0xb84948;
    goto .l34;

.l25:
    ebx = decomp_var_c4;
    edx = decomp_var_c8;
    eax = edx[0x2];
    bool_221 = decomp_var_c0 + 0x1 < eax[0x901];
    decomp_var_c0 = decomp_var_c0 + 0x1;
    if (bool_221) {
            continue;
    }
    break;

.l20:
    edi = eax[0x2];
    esi = 0x0;
    decomp_var_bc = 0x0;
    if (edi[0x900] <= 0x0) goto .l16;
    goto .l24;

.l34:
    asm { fild       qword [dword_4ca540+91568+esi*8] };
    asm { fmul       qword [eax] };
    asm { fdiv       qword [esp+0xdc+-100] };
    eax = sub_47b5c0();
    decomp_var_b8 = eax;
    if (decomp_var_c4 == decomp_var_68) {
            if (eax > 0x0) {
                    ebp = edi[0x915];
                    edi = edi + 0x2450;
                    esp = esp - 0x8;
                    eax = sub_402060(&decomp_var_2c, &decomp_var_bc, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    ebx = eax;
                    eax = *ebx;
                    if (eax == 0x0 || eax != edi) {
                            sub_47a948();
                    }
                    if (ebx[0x1] == ebp) {
                            eax = *(esi * 0x4 + 0xba2f70);
                            ecx = decomp_var_c0;
                            decomp_var_50 = 0x0;
                            decomp_var_44 = 0x1;
                            if (eax == ecx) {
                                    decomp_var_44 = 0x0;
                            }
                            else {
                            }
                            eax = decomp_var_c8[0x2];
                            bool_273 = *(int8_t *)(eax + (esi + esi * 0x8) * 0x4 + 0x3) == 0x0;
                            eax = eax + (esi + esi * 0x8) * 0x4;
                            if (!bool_273) {
                                    eax = eax[0x10];
                                    if (HIBYTE(eax) == 0x41) {
                                            eax = eax & 0xff;
                                            if (eax != 0x14) {
                                                    if (eax == decomp_var_68) {
                                                            decomp_var_44 = 0x0;
                                                            eax = &decomp_var_1c;
                                                    }
                                                    else {
                                                            eax = &decomp_var_1c;
                                                    }
                                                    decomp_var_40 = decomp_var_b8;
                                                    esp = esp - 0x8;
                                                    sub_419d80(eax, &decomp_var_40, decomp_var_dc);
                                                    edi = decomp_var_c8[0x2];
                                                    esi = esi + 0x1;
                                                    decomp_var_bc = esi;
                                                    if (esi < edi[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    edi = decomp_var_c8[0x2];
                                                    esi = esi + 0x1;
                                                    decomp_var_bc = esi;
                                                    if (esi < edi[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            edi = decomp_var_c8[0x2];
                                            esi = esi + 0x1;
                                            decomp_var_bc = esi;
                                            if (esi < edi[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    eax = &decomp_var_10;
                                    decomp_var_40 = decomp_var_b8;
                                    esp = esp - 0x8;
                                    sub_419d80(eax, &decomp_var_40, decomp_var_dc);
                                    edi = decomp_var_c8[0x2];
                                    esi = esi + 0x1;
                                    decomp_var_bc = esi;
                                    if (esi < edi[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            edi = decomp_var_c8[0x2];
                            esi = esi + 0x1;
                            decomp_var_bc = esi;
                            if (esi < edi[0x900]) {
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    edi = decomp_var_c8[0x2];
                    esi = esi + 0x1;
                    decomp_var_bc = esi;
                    if (esi < edi[0x900]) {
                            continue;
                    }
                    break;
            }
    }
    else {
            edi = decomp_var_c8[0x2];
            esi = esi + 0x1;
            decomp_var_bc = esi;
            if (esi < edi[0x900]) {
                    continue;
            }
            break;
    }
    goto .l26;

.l16:
    ebx = decomp_var_c4;
    edx = decomp_var_c8;
    eax = edx[0x2];
    bool_220 = decomp_var_c0 + 0x1 < eax[0x901];
    decomp_var_c0 = decomp_var_c0 + 0x1;
    if (bool_220) {
            continue;
    }
    break;

.l24:
    ecx = decomp_var_c4;
    asm { fild       qword [esp+0xdc+-164] };
    ecx = ecx * 0x15;
    asm { fstp       qword [esp+0xdc+-100] };
    decomp_var_80 = (ecx + decomp_var_c0) * 0x8 + 0xb84948;
    goto .l35;

.l35:
    asm { fild       qword [dword_4ca540+91568+esi*8] };
    asm { fmul       qword [eax] };
    asm { fdiv       qword [esp+0xdc+-100] };
    eax = sub_47b5c0();
    decomp_var_b8 = eax;
    if (decomp_var_c4 == decomp_var_68) {
            if (eax > 0x0) {
                    ebp = edi[0x915];
                    edi = edi + 0x2450;
                    esp = esp - 0x8;
                    eax = sub_402060(&decomp_var_2c, &decomp_var_bc, decomp_var_dc, decomp_var_d8, decomp_var_d4);
                    ebx = eax;
                    eax = *ebx;
                    if (eax == 0x0 || eax != edi) {
                            sub_47a948();
                    }
                    if (ebx[0x1] == ebp) {
                            eax = *(esi * 0x4 + 0xba2f70);
                            ecx = decomp_var_c0;
                            decomp_var_50 = 0x0;
                            decomp_var_44 = 0x1;
                            if (eax == ecx) {
                                    decomp_var_44 = 0x0;
                            }
                            else {
                            }
                            eax = decomp_var_c8[0x2];
                            bool_297 = *(int8_t *)(eax + (esi + esi * 0x8) * 0x4 + 0x3) == 0x0;
                            eax = eax + (esi + esi * 0x8) * 0x4;
                            if (!bool_297) {
                                    eax = eax[0x10];
                                    if (HIBYTE(eax) == 0x41) {
                                            eax = eax & 0xff;
                                            if (eax != 0x14) {
                                                    if (eax == decomp_var_68) {
                                                            decomp_var_44 = 0x0;
                                                            eax = &decomp_var_1c;
                                                    }
                                                    else {
                                                            eax = &decomp_var_1c;
                                                    }
                                                    decomp_var_40 = decomp_var_b8;
                                                    esp = esp - 0x8;
                                                    sub_419d80(eax, &decomp_var_40, decomp_var_dc);
                                                    edi = decomp_var_c8[0x2];
                                                    esi = esi + 0x1;
                                                    decomp_var_bc = esi;
                                                    if (esi < edi[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    edi = decomp_var_c8[0x2];
                                                    esi = esi + 0x1;
                                                    decomp_var_bc = esi;
                                                    if (esi < edi[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            edi = decomp_var_c8[0x2];
                                            esi = esi + 0x1;
                                            decomp_var_bc = esi;
                                            if (esi < edi[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    eax = &decomp_var_10;
                                    decomp_var_40 = decomp_var_b8;
                                    esp = esp - 0x8;
                                    sub_419d80(eax, &decomp_var_40, decomp_var_dc);
                                    edi = decomp_var_c8[0x2];
                                    esi = esi + 0x1;
                                    decomp_var_bc = esi;
                                    if (esi < edi[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            edi = decomp_var_c8[0x2];
                            esi = esi + 0x1;
                            decomp_var_bc = esi;
                            if (esi < edi[0x900]) {
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    edi = decomp_var_c8[0x2];
                    esi = esi + 0x1;
                    decomp_var_bc = esi;
                    if (esi < edi[0x900]) {
                            continue;
                    }
                    break;
            }
    }
    else {
            edi = decomp_var_c8[0x2];
            esi = esi + 0x1;
            decomp_var_bc = esi;
            if (esi < edi[0x900]) {
                    continue;
            }
            break;
    }
    goto .l16;
}
