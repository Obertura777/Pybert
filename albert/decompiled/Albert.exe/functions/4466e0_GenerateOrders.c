// GenerateOrders @ 0x4466e0
// hopper name: sub_4466e0
// pybert name: GenerateOrders
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

GenerateOrders() {
    &decomp_var_4 = &decomp_var_4 & 0xfffffff8;
    sub_47bf20();
    decomp_var_18 = ebx;
    decomp_var_1c = ebp;
    decomp_var_20 = esi;
    decomp_var_24 = edi;
    esp = esp - 0x24;
    decomp_var_28 = *dword_4c8db8 ^ &decomp_var_24;
    *0x0 = &arg_6094;
    edi = ecx;
    decomp_var_c = edi;
    eax = sub_401e30();
    arg_20 = eax;
    eax[0x11] = 0x1;
    arg_20[0x1] = arg_20;
    *arg_20 = arg_20;
    arg_20[0x2] = arg_20;
    eax = sub_4103b0();
    arg_c = eax;
    eax[0x21] = 0x1;
    arg_c[0x1] = arg_c;
    *arg_c = arg_c;
    arg_c[0x2] = arg_c;
    ecx = edi;
    sub_445580(decomp_var_28, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
    eax = edi[0x2];
    ebx = 0x0;
    if (eax[0x901] <= 0x0) goto loc_446829;
    goto loc_446799;

loc_446829:
    eax = 0x0;
    ecx = ecx | 0xffffffff;
    if (*(edi[0x2] + 0x2400) > 0x0) {
            &decomp_var_28 = &decomp_var_28;
            do {
                    *(eax * 0x8 + 0x5f90e8) = 0x0;
                    *(eax * 0x8 + 0x5f90ec) = 0x0;
                    *(eax * 0x8 + 0x5b98e8) = ecx;
                    *(eax * 0x8 + 0x5b98ec) = ecx;
                    eax = eax + 0x1;
            } while (eax < *(edi[0x2] + 0x2400));
    }
    esi = 0x0;
    eax = edi[0x2];
    asm { fldz };
    eax = eax[0x901];
    edx = 0x0;
    if (eax > esi) {
            ebx = 0x0;
            do {
                    ecx = 0x0;
                    if (eax > esi) {
                            eax = ebx;
                            do {
                                    asm { fst        qword [eax+0xb84948] };
                                    ecx = ecx + 0x1;
                                    asm { fst        qword [eax+0xb81228] };
                                    eax = eax + 0x8;
                            } while (ecx < arg_2400);
                    }
                    eax = *(edi[0x2] + 0x2404);
                    edx = edx + 0x1;
                    ebx = ebx + 0xa8;
            } while (edx < eax);
    }
    edi = edi[0x2];
    decomp_var_8 = esi;
    if (edi[0x901] <= esi) goto loc_447003;
    goto loc_4468cb;

loc_446799:
    ecx = eax[0x900];
    while (true) {
            if (ecx > 0x0) {
                    sub_4467b0();
            }
            ebx = ebx + 0x1;
            if (ebx < *(edi[0x2] + 0x2404)) {
                    continue;
            }
            temp_2 = 0x1;
            break;
    }
    if (temp_2 == 0x0) goto .l1;
    goto .l15;

loc_447003:
    edi = decomp_var_c;
    eax = edi[0x2];
    eax = eax[0x901];
    edx = 0x0;
    if (eax > 0x0) {
            esi = 0x0;
            do {
                    ecx = 0x0;
                    if (eax > 0x0) {
                            eax = esi;
                            do {
                                    asm { fld        qword [eax+0xb84948] };
                                    ecx = ecx + 0x1;
                                    asm { fstp       qword [eax+0xb81228] };
                                    eax = eax + 0x8;
                            } while (ecx < *(edi[0x2] + 0x2404));
                    }
                    eax = *(edi[0x2] + 0x2404);
                    edx = edx + 0x1;
                    esi = esi + 0xa8;
            } while (edx < eax);
    }
    edx = edi[0x2];
    eax = edx[0x901];
    esi = 0x0;
    bool_50 = eax <= 0x0;
    if (eax > 0x0) {
            ebx = 0xb84948;
            do {
                    asm { fld        st0 };
                    if (!bool_50) {
                            ecx = ebx;
                            do {
                                    asm { fadd       qword [ecx] };
                                    ecx = ecx + 0x8;
                                    eax = eax - 0x1;
                            } while (eax != 0x0);
                    }
                    *(esi * 0x8 + 0x4f6c40) = sub_47b5f6();
                    *(esi * 0x8 + 0x4f6c44) = edx;
                    eax = edi[0x2];
                    eax = eax[0x901];
                    esi = esi + 0x1;
                    ebx = ebx + 0xa8;
            } while (esi < eax);
    }
    ecx = edi[0x2];
    asm { fld        qword [qword_value_4636737291354636288] };
    eax = ecx[0x901];
    if (eax > 0x0) {
            asm { fstp       st1 };
            decomp_var_4 = 0xb84948;
            do {
                    esi = 0x0;
                    bool_47 = eax < 0x0;
                    if (eax > 0x0) {
                            edi = decomp_var_4;
                            do {
                                    edx = *(esi * 0x8 + 0x4f6c40);
                                    asm { fmul       qword [edi] };
                                    asm { fild       qword [esp+0x28+44] };
                                    asm { fdivp      st1 };
                                    asm { fld        qword [qword_value_4608083138725491507] };
                                    sub_47b370();
                                    asm { fmul       qword [qword_value_4647503709213818880] };
                                    esi = esi + 0x1;
                                    edi = edi + 0x8;
                                    asm { fadd       qword [edi-8] };
                                    asm { fstp       qword [edi-8] };
                                    asm { fld        qword [qword_value_4636737291354636288] };
                            } while (bool_47);
                    }
                    eax = decomp_var_c[0x2];
                    eax = eax[0x901];
                    decomp_var_4 = decomp_var_4 + 0xa8;
            } while (&arg_fffffffffffffffd < eax);
            asm { fldz };
            asm { fxch       st0, st1 };
    }
    ebp = decomp_var_c;
    eax = arg_4[0x901];
    edi = 0x0;
    bool_337 = eax <= 0x0;
    if (eax > 0x0) {
            esi = 0x0;
            ebx = 0xb84948;
            do {
                    asm { fld        st1 };
                    if (!bool_337) {
                            ecx = ebx;
                            edx = eax;
                            do {
                                    asm { fadd       qword [ecx] };
                                    ecx = ecx + 0x8;
                                    edx = edx - 0x1;
                            } while (edx != 0x0);
                    }
                    ecx = 0x0;
                    if (eax > 0x0) {
                            asm { fld        st2 };
                            asm { fucomp     st1 };
                            asm { fnstsw     ax };
                            if (PARITY(HIBYTE(eax) & 0x44)) {
                                    eax = esi + ecx;
                                    asm { fld        qword [dword_633f14+5573172+eax*8] };
                                    asm { fmul       st2 };
                                    asm { fdiv       st1 };
                                    asm { fstp       qword [dword_633f14+5573172+eax*8] };
                            }
                            ecx = ecx + 0x1;
                            if (ecx < arg_4[0x901]) {
                                    continue;
                            }
                            break;
                    }
                    eax = arg_4;
                    asm { fstp       st0 };
                    eax = eax[0x901];
                    edi = edi + 0x1;
                    ebx = ebx + 0xa8;
                    esi = esi + 0x15;
            } while (edi < eax);
    }
    ecx = arg_4;
    asm { fstp       st0 };
    eax = ecx[0x901];
    edi = 0x0;
    bool_35 = eax <= 0x0;
    if (eax <= 0x0) goto loc_4472d5;
    goto loc_4471e8;

loc_4468cb:
    asm { fstp       st0 };
    goto .l20;

.l1:
    return;

.l15:
    eax = 0x0;
    ecx = ecx | 0xffffffff;
    if (*(edi[0x2] + 0x2400) > 0x0) {
            &decomp_var_28 = &decomp_var_28;
            do {
                    *(eax * 0x8 + 0x5f90e8) = 0x0;
                    *(eax * 0x8 + 0x5f90ec) = 0x0;
                    *(eax * 0x8 + 0x5b98e8) = ecx;
                    *(eax * 0x8 + 0x5b98ec) = ecx;
                    eax = eax + 0x1;
            } while (eax < *(edi[0x2] + 0x2400));
    }
    esi = 0x0;
    eax = edi[0x2];
    asm { fldz };
    eax = eax[0x901];
    edx = 0x0;
    if (eax > esi) {
            ebx = 0x0;
            do {
                    ecx = 0x0;
                    if (eax > esi) {
                            eax = ebx;
                            do {
                                    asm { fst        qword [eax+0xb84948] };
                                    ecx = ecx + 0x1;
                                    asm { fst        qword [eax+0xb81228] };
                                    eax = eax + 0x8;
                            } while (ecx < arg_2400);
                    }
                    eax = *(edi[0x2] + 0x2404);
                    edx = edx + 0x1;
                    ebx = ebx + 0xa8;
            } while (edx < eax);
    }
    edi = edi[0x2];
    decomp_var_8 = 0x0;
    if (edi[0x901] <= 0x0) goto .l12;
    goto .l6;

loc_4472d5:
    asm { fstp       st0 };
    sub_436470();
    decomp_var_8 = 0x0;
    if (arg_4[0x901] > 0x0) {
            decomp_var_4 = 0x0;
            ebx = 0x62e408;
            &decomp_var_28 = &decomp_var_28;
            do {
                    bool_258 = *dword_baed64 != 0x1;
                    *ebx = 0xffffffff;
                    if (!bool_258) {
                            eax = arg_4;
                            if (*(int16_t *)word_4c6cc4 == eax[0x1225]) {
                                    esi = 0x0;
                                    decomp_var_10 = 0x0;
                                    if (eax[0x900] > 0x0) {
                                            edi = 0x0;
                                            do {
                                                    if (*(int8_t *)(eax + edi + 0x3) == 0x0) {
                                                            eax = arg_4;
                                                            esi = esi + 0x1;
                                                            edi = edi + 0x24;
                                                            if (esi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    eax = *(int16_t *)(eax + edi + 0x20);
                                                    if (HIBYTE(eax) != 0x41) {
                                                            asm { fild       qword [dword_4ca540+936872+edx*8] };
                                                            asm { fld        qword [qword_value_4612811918334230528] };
                                                            eax = sub_47b370();
                                                            asm { fadd       st0, st0 };
                                                            asm { fild       qword [dword_4ca540+1239976+esi*8] };
                                                            asm { fdivp      st1 };
                                                            asm { fild       dword [esp+0x28+-16] };
                                                            asm { fcomp      st1 };
                                                            asm { fnstsw     ax };
                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                    decomp_var_10 = sub_47b5c0();
                                                                    *ebx = esi;
                                                            }
                                                            else {
                                                                    asm { fstp       st0 };
                                                            }
                                                            eax = arg_4;
                                                            esi = esi + 0x1;
                                                            edi = edi + 0x24;
                                                            if (esi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    if ((eax & 0xff) != 0x14) {
                                                            eax = arg_4;
                                                            esi = esi + 0x1;
                                                            edi = edi + 0x24;
                                                            if (esi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    asm { fild       qword [dword_4ca540+936872+edx*8] };
                                                    asm { fld        qword [qword_value_4612811918334230528] };
                                                    eax = sub_47b370();
                                                    asm { fadd       st0, st0 };
                                                    asm { fild       qword [dword_4ca540+1239976+esi*8] };
                                                    asm { fdivp      st1 };
                                                    asm { fild       dword [esp+0x28+-16] };
                                                    asm { fcomp      st1 };
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                            decomp_var_10 = sub_47b5c0();
                                                            *ebx = esi;
                                                    }
                                                    else {
                                                            asm { fstp       st0 };
                                                    }
                                                    eax = arg_4;
                                                    esi = esi + 0x1;
                                                    edi = edi + 0x24;
                                            } while (esi < eax[0x900]);
                                    }
                            }
                    }
                    decomp_var_4 = decomp_var_4 + 0x100;
                    ebx = ebx + 0x4;
                    bool_260 = decomp_var_8 + 0x1 < arg_4[0x901];
                    decomp_var_8 = decomp_var_8 + 0x1;
            } while (bool_260);
    }
    sub_41a3a0(&arg_40, &arg_8, *arg_c, &arg_8, arg_c);
    sub_47c8f9();
    sub_403430(&arg_40, &arg_1c, *arg_20, &arg_1c, arg_20);
    sub_47c8f9();
    *0x0 = arg_6094;
    &decomp_var_14 = decomp_var_1c;
    return;

loc_4471e8:
    asm { fld1 };
    ecx = 0xb81228;
    asm { fld        qword [qword_value_4613937818241073152] };
    ebx = 0x0;
    asm { fld        qword [qword_value_13837309855095848960] };
    decomp_var_4 = ecx;
    goto loc_447201;

.l20:
    arg_4 = 0x0;
    if (edi[0x900] <= 0x0) goto .l22;
    goto .l23;

.l12:
    edi = decomp_var_c;
    eax = edi[0x2];
    eax = eax[0x901];
    edx = 0x0;
    if (eax > 0x0) {
            esi = 0x0;
            do {
                    ecx = 0x0;
                    if (eax > 0x0) {
                            eax = esi;
                            do {
                                    asm { fld        qword [eax+0xb84948] };
                                    ecx = ecx + 0x1;
                                    asm { fstp       qword [eax+0xb81228] };
                                    eax = eax + 0x8;
                            } while (ecx < *(edi[0x2] + 0x2404));
                    }
                    eax = *(edi[0x2] + 0x2404);
                    edx = edx + 0x1;
                    esi = esi + 0xa8;
            } while (edx < eax);
    }
    edx = edi[0x2];
    eax = edx[0x901];
    esi = 0x0;
    bool_312 = eax <= 0x0;
    if (eax > 0x0) {
            ebx = 0xb84948;
            do {
                    asm { fld        st0 };
                    if (!bool_312) {
                            ecx = ebx;
                            do {
                                    asm { fadd       qword [ecx] };
                                    ecx = ecx + 0x8;
                                    eax = eax - 0x1;
                            } while (eax != 0x0);
                    }
                    *(esi * 0x8 + 0x4f6c40) = sub_47b5f6();
                    *(esi * 0x8 + 0x4f6c44) = edx;
                    eax = edi[0x2];
                    eax = eax[0x901];
                    esi = esi + 0x1;
                    ebx = ebx + 0xa8;
            } while (esi < eax);
    }
    ecx = edi[0x2];
    asm { fld        qword [qword_value_4636737291354636288] };
    eax = ecx[0x901];
    if (eax > 0x0) {
            asm { fstp       st1 };
            decomp_var_4 = 0xb84948;
            do {
                    esi = 0x0;
                    bool_344 = eax < 0x0;
                    if (eax > 0x0) {
                            edi = decomp_var_4;
                            do {
                                    edx = *(esi * 0x8 + 0x4f6c40);
                                    asm { fmul       qword [edi] };
                                    asm { fild       qword [esp+0x28+44] };
                                    asm { fdivp      st1 };
                                    asm { fld        qword [qword_value_4608083138725491507] };
                                    sub_47b370();
                                    asm { fmul       qword [qword_value_4647503709213818880] };
                                    esi = esi + 0x1;
                                    edi = edi + 0x8;
                                    asm { fadd       qword [edi-8] };
                                    asm { fstp       qword [edi-8] };
                                    asm { fld        qword [qword_value_4636737291354636288] };
                            } while (bool_344);
                    }
                    eax = decomp_var_c[0x2];
                    eax = eax[0x901];
                    decomp_var_4 = decomp_var_4 + 0xa8;
            } while (&arg_fffffffffffffffd < eax);
            asm { fldz };
            asm { fxch       st0, st1 };
    }
    ebp = decomp_var_c;
    eax = arg_4[0x901];
    edi = 0x0;
    bool_252 = eax <= 0x0;
    if (eax > 0x0) {
            esi = 0x0;
            ebx = 0xb84948;
            do {
                    asm { fld        st1 };
                    if (!bool_252) {
                            ecx = ebx;
                            edx = eax;
                            do {
                                    asm { fadd       qword [ecx] };
                                    ecx = ecx + 0x8;
                                    edx = edx - 0x1;
                            } while (edx != 0x0);
                    }
                    ecx = 0x0;
                    if (eax > 0x0) {
                            asm { fld        st2 };
                            asm { fucomp     st1 };
                            asm { fnstsw     ax };
                            if (PARITY(HIBYTE(eax) & 0x44)) {
                                    eax = esi + ecx;
                                    asm { fld        qword [dword_633f14+5573172+eax*8] };
                                    asm { fmul       st2 };
                                    asm { fdiv       st1 };
                                    asm { fstp       qword [dword_633f14+5573172+eax*8] };
                            }
                            ecx = ecx + 0x1;
                            if (ecx < arg_4[0x901]) {
                                    continue;
                            }
                            break;
                    }
                    eax = arg_4;
                    asm { fstp       st0 };
                    eax = eax[0x901];
                    edi = edi + 0x1;
                    ebx = ebx + 0xa8;
                    esi = esi + 0x15;
            } while (edi < eax);
    }
    ecx = arg_4;
    asm { fstp       st0 };
    eax = ecx[0x901];
    edi = 0x0;
    bool_288 = eax <= 0x0;
    if (eax <= 0x0) goto .l14;
    goto .l11;

.l6:
    asm { fstp       st0 };
    goto loc_4468cd;

loc_447201:
    asm { fld        st3 };
    if (!bool_35) {
            edx = eax;
            do {
                    asm { fadd       qword [ecx] };
                    ecx = ecx + 0xa8;
                    edx = edx - 0x1;
            } while (edx != 0x0);
    }
    edx = 0x0;
    if (eax <= 0x0) goto loc_4472ab;
    goto loc_447220;

.l22:
    decomp_var_10 = 0x100;
    decomp_var_4 = &arg_890;
    goto .l36;

.l23:
    decomp_var_10 = 0x0;
    edi = decomp_var_8 << 0xb;
    goto .l47;

.l14:
    asm { fstp       st0 };
    sub_436470();
    decomp_var_8 = 0x0;
    if (arg_4[0x901] > 0x0) {
            decomp_var_4 = 0x0;
            ebx = 0x62e408;
            &decomp_var_28 = &decomp_var_28;
            do {
                    bool_273 = *dword_baed64 != 0x1;
                    *ebx = 0xffffffff;
                    if (!bool_273) {
                            eax = arg_4;
                            if (*(int16_t *)word_4c6cc4 == eax[0x1225]) {
                                    esi = 0x0;
                                    decomp_var_10 = 0x0;
                                    if (eax[0x900] > 0x0) {
                                            edi = 0x0;
                                            do {
                                                    if (*(int8_t *)(eax + edi + 0x3) == 0x0) {
                                                            eax = arg_4;
                                                            esi = esi + 0x1;
                                                            edi = edi + 0x24;
                                                            if (esi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    eax = *(int16_t *)(eax + edi + 0x20);
                                                    if (HIBYTE(eax) != 0x41) {
                                                            asm { fild       qword [dword_4ca540+936872+edx*8] };
                                                            asm { fld        qword [qword_value_4612811918334230528] };
                                                            eax = sub_47b370();
                                                            asm { fadd       st0, st0 };
                                                            asm { fild       qword [dword_4ca540+1239976+esi*8] };
                                                            asm { fdivp      st1 };
                                                            asm { fild       dword [esp+0x28+-16] };
                                                            asm { fcomp      st1 };
                                                            asm { fnstsw     ax };
                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                    decomp_var_10 = sub_47b5c0();
                                                                    *ebx = esi;
                                                            }
                                                            else {
                                                                    asm { fstp       st0 };
                                                            }
                                                            eax = arg_4;
                                                            esi = esi + 0x1;
                                                            edi = edi + 0x24;
                                                            if (esi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    if ((eax & 0xff) != 0x14) {
                                                            eax = arg_4;
                                                            esi = esi + 0x1;
                                                            edi = edi + 0x24;
                                                            if (esi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    asm { fild       qword [dword_4ca540+936872+edx*8] };
                                                    asm { fld        qword [qword_value_4612811918334230528] };
                                                    eax = sub_47b370();
                                                    asm { fadd       st0, st0 };
                                                    asm { fild       qword [dword_4ca540+1239976+esi*8] };
                                                    asm { fdivp      st1 };
                                                    asm { fild       dword [esp+0x28+-16] };
                                                    asm { fcomp      st1 };
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                            decomp_var_10 = sub_47b5c0();
                                                            *ebx = esi;
                                                    }
                                                    else {
                                                            asm { fstp       st0 };
                                                    }
                                                    eax = arg_4;
                                                    esi = esi + 0x1;
                                                    edi = edi + 0x24;
                                            } while (esi < eax[0x900]);
                                    }
                            }
                    }
                    decomp_var_4 = decomp_var_4 + 0x100;
                    ebx = ebx + 0x4;
                    bool_272 = decomp_var_8 + 0x1 < arg_4[0x901];
                    decomp_var_8 = decomp_var_8 + 0x1;
            } while (bool_272);
    }
    sub_41a3a0(&arg_40, &arg_8, *arg_c, &arg_8, arg_c);
    sub_47c8f9();
    sub_403430(&arg_40, &arg_1c, *arg_20, &arg_1c, arg_20);
    sub_47c8f9();
    *0x0 = arg_6094;
    &decomp_var_14 = decomp_var_1c;
    return;

.l11:
    asm { fld1 };
    ecx = 0xb81228;
    asm { fld        qword [qword_value_4613937818241073152] };
    ebx = 0x0;
    asm { fld        qword [qword_value_13837309855095848960] };
    decomp_var_4 = ecx;
    goto .l50;

loc_4468cd:
    arg_4 = 0x0;
    if (edi[0x900] <= 0x0) goto loc_446a35;
    goto loc_4468df;

loc_4472ab:
    ecx = decomp_var_4;
    asm { fstp       st0 };
    eax = arg_4[0x901];
    edi = edi + 0x1;
    ecx = ecx + 0x8;
    ebx = ebx + 0x15;
    decomp_var_4 = ecx;
    if (edi < eax) {
            continue;
    }
    break;

loc_447220:
    esi = decomp_var_4;
    goto loc_447224;

.l36:
    ecx = decomp_var_c;
    edx = ecx[0x2];
    arg_4 = 0x0;
    if (edx[0x900] <= 0x0) goto .l34;
    goto .l35;

.l47:
    ebp = 0x0;
    edi[0x13b0bc] = 0x0;
    edi[0x1386bc] = 0x0;
    edi[0x13b0bd] = 0x0;
    edi[0x1386bd] = 0x0;
    eax = decomp_var_c[0x2];
    esi = eax + decomp_var_10 + 0x14;
    esp = esp - 0x8;
    arg_64 = *(eax + decomp_var_10 + 0x18);
    eax = sub_401ff0(&arg_7c, &decomp_var_8, decomp_var_28, decomp_var_24, decomp_var_20);
    ebx = eax;
    eax = *ebx;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (ebx[0x1] != arg_64) {
            eax = *(int16_t *)(decomp_var_c[0x2] + decomp_var_10 + 0x20);
            bool_198 = HIBYTE(eax) == 0x41;
            eax = eax & 0xff;
            if (!bool_198) {
                    eax = 0x14;
            }
            ecx = decomp_var_8;
            if (eax == ecx) {
                    esi = arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4;
                    if (*(int8_t *)byte_baed68 == 0x1) {
                            *(&decomp_var_28 + esi + 0xbc) = 0x1388;
                            *(&decomp_var_28 + esi + 0xc0) = ebp;
                    }
                    else {
                            eax = *(ecx * 0x4 + 0x6240d0);
                            ecx = *(ecx * 0x4 + dword_623990);
                            if (eax > ecx) {
                                    *(&decomp_var_28 + esi + 0xbc) = ((eax - ecx) + 0x2) * 0x1f4;
                                    *(&decomp_var_28 + esi + 0xc0) = ((eax - ecx) + 0x2) * 0x1f4 & 0x80000000 ? 0xffffffff : 0x0;
                            }
                            else {
                                    *(&decomp_var_28 + esi + 0xbc) = 0x3e8;
                                    *(&decomp_var_28 + esi + 0xc0) = ebp;
                            }
                    }
            }
            else {
                    ebp = 0x0;
                    esi = arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4;
                    *(&decomp_var_28 + esi + 0xbc) = 0x0;
                    *(&decomp_var_28 + esi + 0xc0) = ebp;
            }
    }
    else {
            esi = arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4;
            *(&decomp_var_28 + esi + 0xbc) = ebp;
            *(&decomp_var_28 + esi + 0xc0) = ebp;
    }
    eax = &decomp_var_28 + esi + 0x8bc;
    ecx = 0x5;
    do {
            *eax = ebp;
            eax[0x1] = ebp;
            eax = eax + 0x800;
            ecx = ecx - 0x1;
    } while (ecx != 0x0);
    decomp_var_10 = decomp_var_10 + 0x24;
    edi = edi + 0x8;
    bool_197 = arg_4 + 0x1 < *(decomp_var_c[0x2] + 0x2400);
    arg_4 = arg_4 + 0x1;
    if (bool_197) {
            continue;
    }
    break;

.l50:
    asm { fld        st3 };
    if (!bool_288) {
            edx = eax;
            do {
                    asm { fadd       qword [ecx] };
                    ecx = ecx + 0xa8;
                    edx = edx - 0x1;
            } while (edx != 0x0);
    }
    edx = 0x0;
    if (eax <= 0x0) goto .l48;
    goto .l49;

loc_446a35:
    decomp_var_10 = 0x100;
    decomp_var_4 = &arg_890;
    goto loc_446a50;

loc_4468df:
    decomp_var_10 = 0x0;
    edi = decomp_var_8 << 0xb;
    goto loc_4468f0;
    asm { fstp       st2 };
    asm { fstp       st0 };
    asm { fstp       st0 };
    goto loc_4472d5;

loc_447224:
    if (edx != edi) {
            if (*(edi * 0x4 + dword_623990) != 0x0 && *(edx * 0x4 + dword_623990) != 0x0) {
                    ecx = ebx + edx + ebx + edx + ebx + edx + ebx + edx;
                    asm { fld        qword [ecx+ecx+0xb81228] };
                    ecx = ecx + ecx;
                    asm { fcomp      qword [esi] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x41)) {
                            asm { fld        qword [ecx+0xb81228] };
                            asm { fadd       st4 };
                            asm { fdivr      qword [esi] };
                            asm { fmul       qword [esi] };
                            asm { fdiv       st1 };
                            asm { fmul       st3 };
                            asm { fstp       qword [ecx+0xb83b80] };
                    }
                    else {
                            asm { fld        qword [esi] };
                            asm { fadd       st4 };
                            asm { fdivr      qword [ecx+0xb81228] };
                            asm { fmul       qword [esi] };
                            asm { fdiv       st1 };
                            asm { fmul       st2 };
                            asm { fstp       qword [ecx+0xb83b80] };
                    }
            }
            else {
                    asm { fxch       st0, st4 };
                    eax = ebx + edx;
                    asm { fst        qword [dword_633f14+5569644+eax*8] };
                    asm { fxch       st0, st4 };
            }
    }
    edx = edx + 0x1;
    esi = esi + 0xa8;
    if (edx < arg_4[0x901]) {
            continue;
    }
    break;

.l34:
    decomp_var_4 = decomp_var_4 + 0x800;
    bool_169 = decomp_var_10 < 0x500;
    decomp_var_10 = decomp_var_10 + 0x100;
    if (bool_169) {
            continue;
    }
    break;

.l35:
    esi = decomp_var_4;
    ebp = &arg_2a18;
    goto .l38;

.l48:
    ecx = decomp_var_4;
    asm { fstp       st0 };
    eax = arg_4[0x901];
    edi = edi + 0x1;
    ecx = ecx + 0x8;
    ebx = ebx + 0x15;
    decomp_var_4 = ecx;
    if (edi < eax) {
            continue;
    }
    break;

.l49:
    esi = decomp_var_4;
    goto .l51;

loc_446a50:
    ecx = decomp_var_c;
    edx = ecx[0x2];
    arg_4 = 0x0;
    if (edx[0x900] <= 0x0) goto loc_446b23;
    goto loc_446a6c;

loc_4468f0:
    ebp = 0x0;
    edi[0x13b0bc] = 0x0;
    edi[0x1386bc] = 0x0;
    edi[0x13b0bd] = 0x0;
    edi[0x1386bd] = 0x0;
    eax = decomp_var_c[0x2];
    esi = eax + decomp_var_10 + 0x14;
    esp = esp - 0x8;
    arg_64 = *(eax + decomp_var_10 + 0x18);
    eax = sub_401ff0(&arg_7c, &decomp_var_8, decomp_var_28, decomp_var_24, decomp_var_20);
    ebx = eax;
    eax = *ebx;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (ebx[0x1] != arg_64) {
            eax = *(int16_t *)(decomp_var_c[0x2] + decomp_var_10 + 0x20);
            bool_94 = HIBYTE(eax) == 0x41;
            eax = eax & 0xff;
            if (!bool_94) {
                    eax = 0x14;
            }
            ecx = decomp_var_8;
            if (eax == ecx) {
                    esi = arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4;
                    if (*(int8_t *)byte_baed68 == 0x1) {
                            *(&decomp_var_28 + esi + 0xbc) = 0x1388;
                            ebp = 0x0;
                            *(&decomp_var_28 + esi + 0xc0) = 0x0;
                    }
                    else {
                            eax = *(ecx * 0x4 + 0x6240d0);
                            ecx = *(ecx * 0x4 + dword_623990);
                            if (eax > ecx) {
                                    *(&decomp_var_28 + esi + 0xbc) = ((eax - ecx) + 0x2) * 0x1f4;
                                    *(&decomp_var_28 + esi + 0xc0) = ((eax - ecx) + 0x2) * 0x1f4 & 0x80000000 ? 0xffffffff : 0x0;
                            }
                            else {
                                    *(&decomp_var_28 + esi + 0xbc) = 0x3e8;
                                    ebp = 0x0;
                                    *(&decomp_var_28 + esi + 0xc0) = 0x0;
                            }
                    }
            }
            else {
                    ebp = 0x0;
                    esi = arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4;
                    *(&decomp_var_28 + esi + 0xbc) = 0x0;
                    *(&decomp_var_28 + esi + 0xc0) = ebp;
            }
    }
    else {
            esi = arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4 + arg_4;
            *(&decomp_var_28 + esi + 0xbc) = 0x0;
            ebp = 0x0;
            *(&decomp_var_28 + esi + 0xc0) = 0x0;
    }
    eax = &decomp_var_28 + esi + 0x8bc;
    ecx = 0x5;
    do {
            *eax = ebp;
            eax[0x1] = ebp;
            eax = eax + 0x800;
            ecx = ecx - 0x1;
    } while (ecx != 0x0);
    decomp_var_10 = decomp_var_10 + 0x24;
    edi = edi + 0x8;
    bool_96 = arg_4 + 0x1 < *(decomp_var_c[0x2] + 0x2400);
    arg_4 = arg_4 + 0x1;
    if (bool_96) {
            continue;
    }
    break;
    esi = decomp_var_c[0x2];
    eax = esi[0x900];
    if (eax > 0x0) {
            ecx = &arg_3890;
            edi = eax;
            do {
                    *(ecx - 0x800) = 0x0;
                    *(ecx - 0x7fc) = 0x0;
                    eax = ecx;
                    edx = 0x5;
                    do {
                            *eax = 0x0;
                            eax[0x1] = 0x0;
                            eax = eax + 0x800;
                            edx = edx - 0x1;
                    } while (edx != 0x0);
                    ecx = ecx + 0x8;
                    edi = edi - 0x1;
            } while (edi != 0x0);
    }
    eax = esi[0x915];
    esi = esi + 0x2450;
    edi = *eax;
    arg_38 = esi;
    arg_3c = edi;
    goto .l40;

.l38:
    edi = ebp;
    ebx = *arg_0;
    arg_14 = edi;
    arg_18 = ebx;
    &decomp_var_28 = &decomp_var_28;
    goto .l39;
    asm { fstp       st2 };
    asm { fstp       st0 };
    asm { fstp       st0 };
    goto .l14;

.l51:
    if (edx != edi) {
            if (*(edi * 0x4 + dword_623990) != 0x0 && *(edx * 0x4 + dword_623990) != 0x0) {
                    ecx = ebx + edx + ebx + edx + ebx + edx + ebx + edx;
                    asm { fld        qword [ecx+ecx+0xb81228] };
                    ecx = ecx + ecx;
                    asm { fcomp      qword [esi] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x41)) {
                            asm { fld        qword [ecx+0xb81228] };
                            asm { fadd       st4 };
                            asm { fdivr      qword [esi] };
                            asm { fmul       qword [esi] };
                            asm { fdiv       st1 };
                            asm { fmul       st3 };
                            asm { fstp       qword [ecx+0xb83b80] };
                    }
                    else {
                            asm { fld        qword [esi] };
                            asm { fadd       st4 };
                            asm { fdivr      qword [ecx+0xb81228] };
                            asm { fmul       qword [esi] };
                            asm { fdiv       st1 };
                            asm { fmul       st2 };
                            asm { fstp       qword [ecx+0xb83b80] };
                    }
            }
            else {
                    asm { fxch       st0, st4 };
                    eax = ebx + edx;
                    asm { fst        qword [dword_633f14+5569644+eax*8] };
                    asm { fxch       st0, st4 };
            }
    }
    edx = edx + 0x1;
    esi = esi + 0xa8;
    if (edx < arg_4[0x901]) {
            continue;
    }
    break;

loc_446b23:
    decomp_var_4 = decomp_var_4 + 0x800;
    bool_103 = decomp_var_10 < 0x500;
    decomp_var_10 = decomp_var_10 + 0x100;
    if (bool_103) {
            continue;
    }
    break;

loc_446a6c:
    esi = decomp_var_4;
    ebp = &arg_2a18;
    goto loc_446a78;

.l40:
    eax = decomp_var_c[0x2];
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
            if (edi[0x6] == decomp_var_8) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    eax = edi[0x4];
                    *(&decomp_var_28 + eax * 0x8 + 0x30bc) = *(&decomp_var_28 + eax * 0x8 + 0x30bc) + 0x1388;
                    *(&decomp_var_28 + eax * 0x8 + 0x30c0) = *(&decomp_var_28 + eax * 0x8 + 0x30c0) + 0x0 + CARRY(EFLAGS(cf));
            }
            sub_401390();
            edi = arg_3c;
            esi = arg_38;
            continue;
    }
    break;

.l39:
    arg_4c = arg_0;
    if (edi == 0x0 || edi != ebp) {
            sub_47a948();
    }
    if (ebx != arg_4c) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            eax = ebx[0x3];
            *esi = *esi + *(&decomp_var_28 + ((eax + decomp_var_10) * 0x8 - 0x744));
            edx = *(&decomp_var_28 + ((eax + decomp_var_10) * 0x8 - 0x740));
            esi[0x1] = esi[0x1] + edx + CARRY(EFLAGS(cf));
            sub_401520();
            ebx = arg_18;
            edi = arg_14;
            continue;
    }
    break;
    esi = decomp_var_c[0x2];
    eax = esi[0x900];
    if (eax > 0x0) {
            ecx = &arg_3890;
            edi = eax;
            do {
                    *(ecx - 0x800) = 0x0;
                    *(ecx - 0x7fc) = 0x0;
                    eax = ecx;
                    edx = 0x5;
                    do {
                            *eax = 0x0;
                            eax[0x1] = 0x0;
                            eax = eax + 0x800;
                            edx = edx - 0x1;
                    } while (edx != 0x0);
                    ecx = ecx + 0x8;
                    edi = edi - 0x1;
            } while (edi != 0x0);
    }
    eax = esi[0x915];
    esi = esi + 0x2450;
    edi = *eax;
    arg_38 = esi;
    arg_3c = edi;
    goto loc_446ba2;

loc_446a78:
    edi = ebp;
    ebx = *arg_0;
    arg_14 = edi;
    arg_18 = ebx;
    &decomp_var_28 = &decomp_var_28;
    goto loc_446a90;
    decomp_var_4 = 0x100;
    decomp_var_10 = &arg_3890;
    &decomp_var_28 = &decomp_var_28;
    goto .l42;
    esp = esp - 0x10;
    *esi = sub_47bac0(*esi, esi[0x1], 0x5, 0x0);
    esi[0x1] = edx;
    edx = decomp_var_c;
    ebp = &arg_8;
    esi = esi + 0x8;
    bool_171 = arg_4 + 0x1 < *(edx[0x2] + 0x2400);
    arg_4 = arg_4 + 0x1;
    if (bool_171) {
            continue;
    }
    break;

loc_446ba2:
    eax = decomp_var_c[0x2];
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
            if (edi[0x6] == decomp_var_8) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    eax = edi[0x4];
                    *(&decomp_var_28 + eax * 0x8 + 0x30bc) = *(&decomp_var_28 + eax * 0x8 + 0x30bc) + 0x1388;
                    *(&decomp_var_28 + eax * 0x8 + 0x30c0) = *(&decomp_var_28 + eax * 0x8 + 0x30c0) + 0x0 + CARRY(EFLAGS(cf));
            }
            sub_401390();
            edi = arg_3c;
            esi = arg_38;
            continue;
    }
    break;

loc_446a90:
    arg_4c = arg_0;
    if (edi == 0x0 || edi != ebp) {
            sub_47a948();
    }
    if (ebx != arg_4c) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            eax = ebx[0x3];
            *esi = *esi + *(&decomp_var_28 + ((eax + decomp_var_10) * 0x8 - 0x744));
            edx = *(&decomp_var_28 + ((eax + decomp_var_10) * 0x8 - 0x740));
            esi[0x1] = esi[0x1] + edx + CARRY(EFLAGS(cf));
            sub_401520();
            ebx = arg_18;
            edi = arg_14;
            continue;
    }
    break;

.l42:
    eax = decomp_var_c;
    arg_4 = 0x0;
    if (*(eax[0x2] + 0x2400) <= 0x0) goto .l43;
    goto .l41;
    decomp_var_4 = 0x100;
    decomp_var_10 = &arg_3890;
    &decomp_var_28 = &decomp_var_28;
    goto loc_446c30;
    esp = esp - 0x10;
    *esi = sub_47bac0(*esi, esi[0x1], 0x5, 0x0);
    esi[0x1] = edx;
    edx = decomp_var_c;
    ebp = &arg_8;
    esi = esi + 0x8;
    bool_104 = arg_4 + 0x1 < *(edx[0x2] + 0x2400);
    arg_4 = arg_4 + 0x1;
    if (bool_104) {
            continue;
    }
    break;

.l43:
    decomp_var_10 = decomp_var_10 + 0x800;
    bool_187 = decomp_var_4 < 0x500;
    decomp_var_4 = decomp_var_4 + 0x100;
    if (bool_187) {
            continue;
    }
    break;

.l41:
    esi = decomp_var_10;
    ebp = &arg_2a18;
    goto .l45;

loc_446c30:
    eax = decomp_var_c;
    arg_4 = 0x0;
    if (*(eax[0x2] + 0x2400) <= 0x0) goto loc_446d09;
    goto loc_446c4c;
    ebx = decomp_var_c;
    eax = ebx[0x2];
    bool_147 = eax[0x901] <= 0x0;
    decomp_var_10 = 0x0;
    if (eax[0x901] <= 0x0) goto .l21;
    goto .l31;

.l45:
    edi = ebp;
    ebx = *arg_0;
    arg_14 = edi;
    arg_18 = ebx;
    &decomp_var_28 = &decomp_var_28;
    goto .l46;

loc_446d09:
    decomp_var_10 = decomp_var_10 + 0x800;
    bool_123 = decomp_var_4 < 0x500;
    decomp_var_4 = decomp_var_4 + 0x100;
    if (bool_123) {
            continue;
    }
    break;

loc_446c4c:
    esi = decomp_var_10;
    ebp = &arg_2a18;
    goto loc_446c58;

.l21:
    eax = arg_c;
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
            eax = arg_c;
    }
    eax[0x1] = eax;
    edi = 0x0;
    *arg_c = arg_c;
    arg_c[0x2] = arg_c;
    eax = ebx[0x2];
    esi = 0x0;
    if (eax[0x900] > 0x0) {
            &decomp_var_28 = &decomp_var_28;
            do {
                    if (*(int8_t *)(edi + eax + 0x3) != 0x0) {
                            arg_68 = *(&decomp_var_28 + esi * 0x8 + 0x28bc);
                            esp = esp - 0x8;
                            eax = sub_419070(&arg_84, &arg_68, decomp_var_28);
                    }
                    eax = ebx[0x2];
                    esi = esi + 0x1;
                    edi = edi + 0x24;
            } while (esi < eax[0x900]);
    }
    esi = *arg_c;
    edi = &arg_8;
    decomp_var_4 = 0x1;
    arg_30 = edi;
    arg_34 = esi;
    goto .l32;

.l31:
    while (true) {
            asm { fldz };
            asm { fstp       qword [esp+0x28+-4] };
            if (!bool_147) {
                    sub_446d60(decomp_var_28, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, decomp_var_c, decomp_var_8);
            }
            ecx = decomp_var_10;
            asm { fld        qword [esp+0x28+-4] };
            eax = decomp_var_c;
            edx = ecx * 0x15 + decomp_var_8;
            ecx = ecx + 0x1;
            decomp_var_10 = ecx;
            asm { fstp       qword [dword_633f14+5573172+edx*8] };
            if (ecx < *(eax[0x2] + 0x2404)) {
                    continue;
            }
            temp_0 = 0x1;
            break;
    }
    if (temp_0 == 0x0) goto .l28;
    goto .l19;

.l46:
    edx = arg_0;
    arg_5c = edx;
    if (edi == 0x0 || edi != ebp) {
            sub_47a948();
    }
    if (ebx != arg_5c) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            eax = ebx[0x3];
            *esi = *esi + *(&decomp_var_28 + (eax + decomp_var_4) * 0x8 + 0x28bc);
            esi[0x1] = esi[0x1] + *(&decomp_var_28 + (eax + decomp_var_4) * 0x8 + 0x28c0) + CARRY(EFLAGS(cf));
            sub_401520();
            ebx = arg_18;
            edi = arg_14;
            continue;
    }
    break;
    ebx = decomp_var_c;
    eax = ebx[0x2];
    bool_80 = eax[0x901] <= 0x0;
    decomp_var_10 = 0x0;
    if (eax[0x901] <= 0x0) goto loc_446e26;
    goto loc_446d45;

loc_446c58:
    edi = ebp;
    ebx = *arg_0;
    arg_14 = edi;
    arg_18 = ebx;
    &decomp_var_28 = &decomp_var_28;
    goto loc_446c70;

.l32:
    ebp = arg_c;
    if (edi == 0x0 || edi != &arg_8) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (decomp_var_4 > ebx[0xffe]) {
                    sub_40f6f0();
                    esi = arg_34;
                    edi = arg_30;
                    continue;
            }
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x6];
            eax = *(int16_t *)(ebx[0x2] + (eax + eax * 0x8) * 0x4 + 0x20);
            bool_156 = HIBYTE(eax) == 0x41;
            eax = eax & 0xff;
            if (!bool_156) {
                    eax = 0x14;
            }
            if (eax != decomp_var_8) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                    }
                    edx = esi[0x4];
                    eax = (decomp_var_8 << 0x8) + esi[0x6];
                    decomp_var_4 = decomp_var_4 + 0x1;
                    *(eax * 0x8 + 0x59a0e8) = edx;
                    *(eax * 0x8 + 0x59a0ec) = esi[0x5];
            }
            sub_40f6f0();
            esi = arg_34;
            edi = arg_30;
            continue;
    }
    break;

.l28:
    temp_1 = 0x0;
    break;

.l19:
    ebx = decomp_var_c;
    eax = arg_c;
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
            eax = arg_c;
    }
    eax[0x1] = eax;
    edi = 0x0;
    *arg_c = arg_c;
    arg_c[0x2] = arg_c;
    eax = ebx[0x2];
    esi = 0x0;
    if (eax[0x900] > 0x0) {
            &decomp_var_28 = &decomp_var_28;
            do {
                    if (*(int8_t *)(edi + eax + 0x3) != 0x0) {
                            arg_68 = *(&decomp_var_28 + esi * 0x8 + 0x28bc);
                            esp = esp - 0x8;
                            eax = sub_419070(&arg_84, &arg_68, decomp_var_28);
                    }
                    eax = ebx[0x2];
                    esi = esi + 0x1;
                    edi = edi + 0x24;
            } while (esi < eax[0x900]);
    }
    esi = *arg_c;
    edi = &arg_8;
    decomp_var_4 = 0x1;
    arg_30 = edi;
    arg_34 = esi;
    goto .l33;
    esp = esp - 0x10;
    *esi = sub_47bac0(*esi, esi[0x1], 0x5, 0x0);
    esi[0x1] = edx;
    ebp = &arg_8;
    esi = esi + 0x8;
    bool_188 = arg_4 + 0x1 < *(decomp_var_c[0x2] + 0x2400);
    arg_4 = arg_4 + 0x1;
    if (bool_188) {
            continue;
    }
    break;

loc_446e26:
    eax = arg_c;
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
            eax = arg_c;
    }
    eax[0x1] = eax;
    edi = 0x0;
    *arg_c = arg_c;
    arg_c[0x2] = arg_c;
    eax = ebx[0x2];
    esi = 0x0;
    if (eax[0x900] > 0x0) {
            &decomp_var_28 = &decomp_var_28;
            do {
                    if (*(int8_t *)(edi + eax + 0x3) != 0x0) {
                            arg_68 = *(&decomp_var_28 + esi * 0x8 + 0x28bc);
                            esp = esp - 0x8;
                            eax = sub_419070(&arg_84, &arg_68, decomp_var_28);
                    }
                    eax = ebx[0x2];
                    esi = esi + 0x1;
                    edi = edi + 0x24;
            } while (esi < eax[0x900]);
    }
    esi = *arg_c;
    edi = &arg_8;
    decomp_var_4 = 0x1;
    arg_30 = edi;
    arg_34 = esi;
    goto .l18;

loc_446d45:
    while (true) {
            asm { fldz };
            asm { fstp       qword [esp+0x28+-4] };
            if (!bool_80) {
                    sub_446d60(decomp_var_28, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, decomp_var_c, decomp_var_8);
            }
            ecx = decomp_var_10;
            asm { fld        qword [esp+0x28+-4] };
            eax = decomp_var_c;
            edx = ecx * 0x15 + decomp_var_8;
            ecx = ecx + 0x1;
            decomp_var_10 = ecx;
            asm { fstp       qword [dword_633f14+5573172+edx*8] };
            if (ecx < *(eax[0x2] + 0x2404)) {
                    continue;
            }
            temp_0 = 0x1;
            break;
    }
    if (temp_0 == 0x0) goto .l99;
    goto loc_446e22;

loc_446c70:
    edx = arg_0;
    arg_5c = edx;
    if (edi == 0x0 || edi != ebp) {
            sub_47a948();
    }
    if (ebx != arg_5c) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            eax = ebx[0x3];
            *esi = *esi + *(&decomp_var_28 + (eax + decomp_var_4) * 0x8 + 0x28bc);
            esi[0x1] = esi[0x1] + *(&decomp_var_28 + (eax + decomp_var_4) * 0x8 + 0x28c0) + CARRY(EFLAGS(cf));
            sub_401520();
            ebx = arg_18;
            edi = arg_14;
            continue;
    }
    break;
    ecx = 0x0;
    if (*(ebx[0x2] + 0x2400) > 0x0) {
            eax = decomp_var_8 << 0xb;
            do {
                    edx = *(&decomp_var_28 + ecx * 0x8 + 0x28bc);
                    esi = *(&decomp_var_28 + ecx * 0x8 + 0x28c0);
                    eax[0x16bc3a] = edx;
                    eax[0x13b0bc] = edx;
                    eax[0x16bc3b] = esi;
                    eax[0x13b0bd] = esi;
                    ecx = ecx + 0x1;
                    eax = eax + 0x8;
            } while (ecx < *(ebx[0x2] + 0x2400));
    }
    edi = ebx[0x2];
    bool_137 = decomp_var_8 + 0x1 < edi[0x901];
    decomp_var_8 = decomp_var_8 + 0x1;
    if (bool_137) {
            continue;
    }
    asm { fldz };
    temp_1 = 0x1;
    break;
    if (temp_1 == 0x0) goto .l1;
    goto .l3;

.l33:
    ebp = arg_c;
    if (edi == 0x0 || edi != &arg_8) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (decomp_var_4 <= ebx[0xffe]) {
                    if (edi == 0x0) {
                            sub_47a948();
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi[0x6];
                    eax = *(int16_t *)(ebx[0x2] + (eax + eax * 0x8) * 0x4 + 0x20);
                    bool_161 = HIBYTE(eax) == 0x41;
                    eax = eax & 0xff;
                    if (!bool_161) {
                            eax = 0x14;
                    }
                    if (eax != decomp_var_8) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                            }
                            edx = esi[0x4];
                            eax = (decomp_var_8 << 0x8) + esi[0x6];
                            decomp_var_4 = decomp_var_4 + 0x1;
                            *(eax * 0x8 + 0x59a0e8) = edx;
                            *(eax * 0x8 + 0x59a0ec) = esi[0x5];
                    }
            }
            sub_40f6f0();
            esi = arg_34;
            edi = arg_30;
            continue;
    }
    break;

.l18:
    ebp = arg_c;
    if (edi == 0x0 || edi != &arg_8) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (decomp_var_4 <= ebx[0xffe]) {
                    if (edi == 0x0) {
                            sub_47a948();
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    eax = esi[0x6];
                    eax = *(int16_t *)(ebx[0x2] + (eax + eax * 0x8) * 0x4 + 0x20);
                    bool_113 = HIBYTE(eax) == 0x41;
                    eax = eax & 0xff;
                    if (!bool_113) {
                            eax = 0x14;
                    }
                    if (eax != decomp_var_8) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                            }
                            edx = esi[0x4];
                            eax = (decomp_var_8 << 0x8) + esi[0x6];
                            decomp_var_4 = decomp_var_4 + 0x1;
                            *(eax * 0x8 + 0x59a0e8) = edx;
                            *(eax * 0x8 + 0x59a0ec) = esi[0x5];
                    }
            }
            sub_40f6f0();
            esi = arg_34;
            edi = arg_30;
            continue;
    }
    break;

.l99:
    temp_1 = 0x0;
    break;

loc_446e22:
    ebx = decomp_var_c;
    eax = arg_c;
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
            eax = arg_c;
    }
    eax[0x1] = eax;
    edi = 0x0;
    *arg_c = arg_c;
    arg_c[0x2] = arg_c;
    eax = ebx[0x2];
    esi = 0x0;
    if (eax[0x900] > 0x0) {
            &decomp_var_28 = &decomp_var_28;
            do {
                    if (*(int8_t *)(edi + eax + 0x3) != 0x0) {
                            arg_68 = *(&decomp_var_28 + esi * 0x8 + 0x28bc);
                            esp = esp - 0x8;
                            eax = sub_419070(&arg_84, &arg_68, decomp_var_28);
                    }
                    eax = ebx[0x2];
                    esi = esi + 0x1;
                    edi = edi + 0x24;
            } while (esi < eax[0x900]);
    }
    esi = *arg_c;
    edi = &arg_8;
    decomp_var_4 = 0x1;
    arg_30 = edi;
    arg_34 = esi;
    goto loc_446ef0;
    esp = esp - 0x10;
    *esi = sub_47bac0(*esi, esi[0x1], 0x5, 0x0);
    esi[0x1] = edx;
    ebp = &arg_8;
    esi = esi + 0x8;
    bool_124 = arg_4 + 0x1 < *(decomp_var_c[0x2] + 0x2400);
    arg_4 = arg_4 + 0x1;
    if (bool_124) {
            continue;
    }
    break;

.l3:
    edi = decomp_var_c;
    eax = edi[0x2];
    eax = eax[0x901];
    edx = 0x0;
    if (eax > 0x0) {
            esi = 0x0;
            do {
                    ecx = 0x0;
                    if (eax > 0x0) {
                            eax = esi;
                            do {
                                    asm { fld        qword [eax+0xb84948] };
                                    ecx = ecx + 0x1;
                                    asm { fstp       qword [eax+0xb81228] };
                                    eax = eax + 0x8;
                            } while (ecx < *(edi[0x2] + 0x2404));
                    }
                    eax = *(edi[0x2] + 0x2404);
                    edx = edx + 0x1;
                    esi = esi + 0xa8;
            } while (edx < eax);
    }
    edx = edi[0x2];
    eax = edx[0x901];
    esi = 0x0;
    bool_249 = eax <= 0x0;
    if (eax > 0x0) {
            ebx = 0xb84948;
            do {
                    asm { fld        st0 };
                    if (!bool_249) {
                            ecx = ebx;
                            do {
                                    asm { fadd       qword [ecx] };
                                    ecx = ecx + 0x8;
                                    eax = eax - 0x1;
                            } while (eax != 0x0);
                    }
                    *(esi * 0x8 + 0x4f6c40) = sub_47b5f6();
                    *(esi * 0x8 + 0x4f6c44) = edx;
                    eax = edi[0x2];
                    eax = eax[0x901];
                    esi = esi + 0x1;
                    ebx = ebx + 0xa8;
            } while (esi < eax);
    }
    ecx = edi[0x2];
    asm { fld        qword [qword_value_4636737291354636288] };
    eax = ecx[0x901];
    if (eax > 0x0) {
            asm { fstp       st1 };
            decomp_var_4 = 0xb84948;
            do {
                    esi = 0x0;
                    bool_246 = eax < 0x0;
                    if (eax > 0x0) {
                            edi = decomp_var_4;
                            do {
                                    edx = *(esi * 0x8 + 0x4f6c40);
                                    asm { fmul       qword [edi] };
                                    asm { fild       qword [esp+0x28+44] };
                                    asm { fdivp      st1 };
                                    asm { fld        qword [qword_value_4608083138725491507] };
                                    sub_47b370();
                                    asm { fmul       qword [qword_value_4647503709213818880] };
                                    esi = esi + 0x1;
                                    edi = edi + 0x8;
                                    asm { fadd       qword [edi-8] };
                                    asm { fstp       qword [edi-8] };
                                    asm { fld        qword [qword_value_4636737291354636288] };
                            } while (bool_246);
                    }
                    eax = decomp_var_c[0x2];
                    eax = eax[0x901];
                    decomp_var_4 = decomp_var_4 + 0xa8;
            } while (&arg_fffffffffffffffd < eax);
            asm { fldz };
            asm { fxch       st0, st1 };
    }
    ebp = decomp_var_c;
    eax = arg_4[0x901];
    edi = 0x0;
    bool_297 = eax <= 0x0;
    if (eax > 0x0) {
            esi = 0x0;
            ebx = 0xb84948;
            do {
                    asm { fld        st1 };
                    if (!bool_297) {
                            ecx = ebx;
                            edx = eax;
                            do {
                                    asm { fadd       qword [ecx] };
                                    ecx = ecx + 0x8;
                                    edx = edx - 0x1;
                            } while (edx != 0x0);
                    }
                    ecx = 0x0;
                    if (eax > 0x0) {
                            asm { fld        st2 };
                            asm { fucomp     st1 };
                            asm { fnstsw     ax };
                            if (PARITY(HIBYTE(eax) & 0x44)) {
                                    eax = esi + ecx;
                                    asm { fld        qword [dword_633f14+5573172+eax*8] };
                                    asm { fmul       st2 };
                                    asm { fdiv       st1 };
                                    asm { fstp       qword [dword_633f14+5573172+eax*8] };
                            }
                            ecx = ecx + 0x1;
                            if (ecx < arg_4[0x901]) {
                                    continue;
                            }
                            break;
                    }
                    eax = arg_4;
                    asm { fstp       st0 };
                    eax = eax[0x901];
                    edi = edi + 0x1;
                    ebx = ebx + 0xa8;
                    esi = esi + 0x15;
            } while (edi < eax);
    }
    ecx = arg_4;
    asm { fstp       st0 };
    eax = ecx[0x901];
    edi = 0x0;
    bool_327 = eax <= 0x0;
    if (eax <= 0x0) goto .l5;
    goto .l2;
    ecx = 0x0;
    if (*(ebx[0x2] + 0x2400) > 0x0) {
            eax = decomp_var_8 << 0xb;
            do {
                    edx = *(&decomp_var_28 + ecx * 0x8 + 0x28bc);
                    esi = *(&decomp_var_28 + ecx * 0x8 + 0x28c0);
                    eax[0x16bc3a] = edx;
                    eax[0x13b0bc] = edx;
                    eax[0x16bc3b] = esi;
                    eax[0x13b0bd] = esi;
                    ecx = ecx + 0x1;
                    eax = eax + 0x8;
            } while (ecx < *(ebx[0x2] + 0x2400));
    }
    edi = ebx[0x2];
    bool_135 = decomp_var_8 + 0x1 < edi[0x901];
    decomp_var_8 = decomp_var_8 + 0x1;
    if (bool_135) {
            continue;
    }
    asm { fldz };
    temp_1 = 0x1;
    break;
    ecx = 0x0;
    if (*(ebx[0x2] + 0x2400) > 0x0) {
            eax = decomp_var_8 << 0xb;
            do {
                    edx = *(&decomp_var_28 + ecx * 0x8 + 0x28bc);
                    esi = *(&decomp_var_28 + ecx * 0x8 + 0x28c0);
                    eax[0x16bc3a] = edx;
                    eax[0x13b0bc] = edx;
                    eax[0x16bc3b] = esi;
                    eax[0x13b0bd] = esi;
                    ecx = ecx + 0x1;
                    eax = eax + 0x8;
            } while (ecx < *(ebx[0x2] + 0x2400));
    }
    edi = ebx[0x2];
    bool_64 = decomp_var_8 + 0x1 < edi[0x901];
    decomp_var_8 = decomp_var_8 + 0x1;
    if (bool_64) {
            continue;
    }
    asm { fldz };
    temp_1 = 0x1;
    break;
    if (temp_1 == 0x0) goto .l1;
    goto .l8;

loc_446ef0:
    ebp = arg_c;
    if (edi == 0x0 || edi != &arg_8) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (decomp_var_4 > ebx[0xffe]) {
                    sub_40f6f0();
                    esi = arg_34;
                    edi = arg_30;
                    continue;
            }
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x6];
            eax = *(int16_t *)(ebx[0x2] + (eax + eax * 0x8) * 0x4 + 0x20);
            bool_85 = HIBYTE(eax) == 0x41;
            eax = eax & 0xff;
            if (!bool_85) {
                    eax = 0x14;
            }
            if (eax != decomp_var_8) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                    }
                    edx = esi[0x4];
                    eax = (decomp_var_8 << 0x8) + esi[0x6];
                    decomp_var_4 = decomp_var_4 + 0x1;
                    *(eax * 0x8 + 0x59a0e8) = edx;
                    *(eax * 0x8 + 0x59a0ec) = esi[0x5];
            }
            sub_40f6f0();
            esi = arg_34;
            edi = arg_30;
            continue;
    }
    break;

.l5:
    asm { fstp       st0 };
    sub_436470();
    decomp_var_8 = 0x0;
    if (arg_4[0x901] > 0x0) {
            decomp_var_4 = 0x0;
            ebx = 0x62e408;
            &decomp_var_28 = &decomp_var_28;
            do {
                    bool_221 = *dword_baed64 != 0x1;
                    *ebx = 0xffffffff;
                    if (!bool_221) {
                            eax = arg_4;
                            if (*(int16_t *)word_4c6cc4 == eax[0x1225]) {
                                    esi = 0x0;
                                    decomp_var_10 = 0x0;
                                    if (eax[0x900] > 0x0) {
                                            edi = 0x0;
                                            do {
                                                    if (*(int8_t *)(eax + edi + 0x3) == 0x0) {
                                                            eax = arg_4;
                                                            esi = esi + 0x1;
                                                            edi = edi + 0x24;
                                                            if (esi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    eax = *(int16_t *)(eax + edi + 0x20);
                                                    if (HIBYTE(eax) != 0x41) {
                                                            asm { fild       qword [dword_4ca540+936872+edx*8] };
                                                            asm { fld        qword [qword_value_4612811918334230528] };
                                                            eax = sub_47b370();
                                                            asm { fadd       st0, st0 };
                                                            asm { fild       qword [dword_4ca540+1239976+esi*8] };
                                                            asm { fdivp      st1 };
                                                            asm { fild       dword [esp+0x28+-16] };
                                                            asm { fcomp      st1 };
                                                            asm { fnstsw     ax };
                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                    decomp_var_10 = sub_47b5c0();
                                                                    *ebx = esi;
                                                            }
                                                            else {
                                                                    asm { fstp       st0 };
                                                            }
                                                            eax = arg_4;
                                                            esi = esi + 0x1;
                                                            edi = edi + 0x24;
                                                            if (esi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    if ((eax & 0xff) != 0x14) {
                                                            eax = arg_4;
                                                            esi = esi + 0x1;
                                                            edi = edi + 0x24;
                                                            if (esi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    asm { fild       qword [dword_4ca540+936872+edx*8] };
                                                    asm { fld        qword [qword_value_4612811918334230528] };
                                                    eax = sub_47b370();
                                                    asm { fadd       st0, st0 };
                                                    asm { fild       qword [dword_4ca540+1239976+esi*8] };
                                                    asm { fdivp      st1 };
                                                    asm { fild       dword [esp+0x28+-16] };
                                                    asm { fcomp      st1 };
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                            decomp_var_10 = sub_47b5c0();
                                                            *ebx = esi;
                                                    }
                                                    else {
                                                            asm { fstp       st0 };
                                                    }
                                                    eax = arg_4;
                                                    esi = esi + 0x1;
                                                    edi = edi + 0x24;
                                            } while (esi < eax[0x900]);
                                    }
                            }
                    }
                    decomp_var_4 = decomp_var_4 + 0x100;
                    ebx = ebx + 0x4;
                    bool_220 = decomp_var_8 + 0x1 < arg_4[0x901];
                    decomp_var_8 = decomp_var_8 + 0x1;
            } while (bool_220);
    }
    sub_41a3a0(&arg_40, &arg_8, *arg_c, &arg_8, arg_c);
    sub_47c8f9();
    sub_403430(&arg_40, &arg_1c, *arg_20, &arg_1c, arg_20);
    sub_47c8f9();
    *0x0 = arg_6094;
    &decomp_var_14 = decomp_var_1c;
    return;

.l2:
    asm { fld1 };
    ecx = 0xb81228;
    asm { fld        qword [qword_value_4613937818241073152] };
    ebx = 0x0;
    asm { fld        qword [qword_value_13837309855095848960] };
    decomp_var_4 = ecx;
    goto .l56;

.l8:
    edi = decomp_var_c;
    eax = edi[0x2];
    eax = eax[0x901];
    edx = 0x0;
    if (eax > 0x0) {
            esi = 0x0;
            do {
                    ecx = 0x0;
                    if (eax > 0x0) {
                            eax = esi;
                            do {
                                    asm { fld        qword [eax+0xb84948] };
                                    ecx = ecx + 0x1;
                                    asm { fstp       qword [eax+0xb81228] };
                                    eax = eax + 0x8;
                            } while (ecx < *(edi[0x2] + 0x2404));
                    }
                    eax = *(edi[0x2] + 0x2404);
                    edx = edx + 0x1;
                    esi = esi + 0xa8;
            } while (edx < eax);
    }
    edx = edi[0x2];
    eax = edx[0x901];
    esi = 0x0;
    bool_316 = eax <= 0x0;
    if (eax > 0x0) {
            ebx = 0xb84948;
            do {
                    asm { fld        st0 };
                    if (!bool_316) {
                            ecx = ebx;
                            do {
                                    asm { fadd       qword [ecx] };
                                    ecx = ecx + 0x8;
                                    eax = eax - 0x1;
                            } while (eax != 0x0);
                    }
                    *(esi * 0x8 + 0x4f6c40) = sub_47b5f6();
                    *(esi * 0x8 + 0x4f6c44) = edx;
                    eax = edi[0x2];
                    eax = eax[0x901];
                    esi = esi + 0x1;
                    ebx = ebx + 0xa8;
            } while (esi < eax);
    }
    ecx = edi[0x2];
    asm { fld        qword [qword_value_4636737291354636288] };
    eax = ecx[0x901];
    if (eax > 0x0) {
            asm { fstp       st1 };
            decomp_var_4 = 0xb84948;
            do {
                    esi = 0x0;
                    bool_54 = eax < 0x0;
                    if (eax > 0x0) {
                            edi = decomp_var_4;
                            do {
                                    edx = *(esi * 0x8 + 0x4f6c40);
                                    asm { fmul       qword [edi] };
                                    asm { fild       qword [esp+0x28+44] };
                                    asm { fdivp      st1 };
                                    asm { fld        qword [qword_value_4608083138725491507] };
                                    sub_47b370();
                                    asm { fmul       qword [qword_value_4647503709213818880] };
                                    esi = esi + 0x1;
                                    edi = edi + 0x8;
                                    asm { fadd       qword [edi-8] };
                                    asm { fstp       qword [edi-8] };
                                    asm { fld        qword [qword_value_4636737291354636288] };
                            } while (bool_54);
                    }
                    eax = decomp_var_c[0x2];
                    eax = eax[0x901];
                    decomp_var_4 = decomp_var_4 + 0xa8;
            } while (&arg_fffffffffffffffd < eax);
            asm { fldz };
            asm { fxch       st0, st1 };
    }
    ebp = decomp_var_c;
    eax = arg_4[0x901];
    edi = 0x0;
    bool_306 = eax <= 0x0;
    if (eax > 0x0) {
            esi = 0x0;
            ebx = 0xb84948;
            do {
                    asm { fld        st1 };
                    if (!bool_306) {
                            ecx = ebx;
                            edx = eax;
                            do {
                                    asm { fadd       qword [ecx] };
                                    ecx = ecx + 0x8;
                                    edx = edx - 0x1;
                            } while (edx != 0x0);
                    }
                    ecx = 0x0;
                    if (eax > 0x0) {
                            asm { fld        st2 };
                            asm { fucomp     st1 };
                            asm { fnstsw     ax };
                            if (PARITY(HIBYTE(eax) & 0x44)) {
                                    eax = esi + ecx;
                                    asm { fld        qword [dword_633f14+5573172+eax*8] };
                                    asm { fmul       st2 };
                                    asm { fdiv       st1 };
                                    asm { fstp       qword [dword_633f14+5573172+eax*8] };
                            }
                            ecx = ecx + 0x1;
                            if (ecx < arg_4[0x901]) {
                                    continue;
                            }
                            break;
                    }
                    eax = arg_4;
                    asm { fstp       st0 };
                    eax = eax[0x901];
                    edi = edi + 0x1;
                    ebx = ebx + 0xa8;
                    esi = esi + 0x15;
            } while (edi < eax);
    }
    ecx = arg_4;
    asm { fstp       st0 };
    eax = ecx[0x901];
    edi = 0x0;
    bool_320 = eax <= 0x0;
    if (eax <= 0x0) goto .l10;
    goto .l7;
    ecx = 0x0;
    if (*(ebx[0x2] + 0x2400) > 0x0) {
            eax = decomp_var_8 << 0xb;
            do {
                    edx = *(&decomp_var_28 + ecx * 0x8 + 0x28bc);
                    esi = *(&decomp_var_28 + ecx * 0x8 + 0x28c0);
                    eax[0x16bc3a] = edx;
                    eax[0x13b0bc] = edx;
                    eax[0x16bc3b] = esi;
                    eax[0x13b0bd] = esi;
                    ecx = ecx + 0x1;
                    eax = eax + 0x8;
            } while (ecx < *(ebx[0x2] + 0x2400));
    }
    edi = ebx[0x2];
    bool_61 = decomp_var_8 + 0x1 < edi[0x901];
    decomp_var_8 = decomp_var_8 + 0x1;
    if (bool_61) {
            continue;
    }
    asm { fldz };
    temp_1 = 0x1;
    break;

.l56:
    asm { fld        st3 };
    if (!bool_327) {
            edx = eax;
            do {
                    asm { fadd       qword [ecx] };
                    ecx = ecx + 0xa8;
                    edx = edx - 0x1;
            } while (edx != 0x0);
    }
    edx = 0x0;
    if (eax <= 0x0) goto .l57;
    goto .l58;

.l10:
    asm { fstp       st0 };
    sub_436470();
    decomp_var_8 = 0x0;
    if (arg_4[0x901] > 0x0) {
            decomp_var_4 = 0x0;
            ebx = 0x62e408;
            &decomp_var_28 = &decomp_var_28;
            do {
                    bool_233 = *dword_baed64 != 0x1;
                    *ebx = 0xffffffff;
                    if (!bool_233) {
                            eax = arg_4;
                            if (*(int16_t *)word_4c6cc4 == eax[0x1225]) {
                                    esi = 0x0;
                                    decomp_var_10 = 0x0;
                                    if (eax[0x900] > 0x0) {
                                            edi = 0x0;
                                            do {
                                                    if (*(int8_t *)(eax + edi + 0x3) == 0x0) {
                                                            eax = arg_4;
                                                            esi = esi + 0x1;
                                                            edi = edi + 0x24;
                                                            if (esi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    eax = *(int16_t *)(eax + edi + 0x20);
                                                    if (HIBYTE(eax) != 0x41) {
                                                            asm { fild       qword [dword_4ca540+936872+edx*8] };
                                                            asm { fld        qword [qword_value_4612811918334230528] };
                                                            eax = sub_47b370();
                                                            asm { fadd       st0, st0 };
                                                            asm { fild       qword [dword_4ca540+1239976+esi*8] };
                                                            asm { fdivp      st1 };
                                                            asm { fild       dword [esp+0x28+-16] };
                                                            asm { fcomp      st1 };
                                                            asm { fnstsw     ax };
                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                    decomp_var_10 = sub_47b5c0();
                                                                    *ebx = esi;
                                                            }
                                                            else {
                                                                    asm { fstp       st0 };
                                                            }
                                                            eax = arg_4;
                                                            esi = esi + 0x1;
                                                            edi = edi + 0x24;
                                                            if (esi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    if ((eax & 0xff) != 0x14) {
                                                            eax = arg_4;
                                                            esi = esi + 0x1;
                                                            edi = edi + 0x24;
                                                            if (esi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    asm { fild       qword [dword_4ca540+936872+edx*8] };
                                                    asm { fld        qword [qword_value_4612811918334230528] };
                                                    eax = sub_47b370();
                                                    asm { fadd       st0, st0 };
                                                    asm { fild       qword [dword_4ca540+1239976+esi*8] };
                                                    asm { fdivp      st1 };
                                                    asm { fild       dword [esp+0x28+-16] };
                                                    asm { fcomp      st1 };
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                            decomp_var_10 = sub_47b5c0();
                                                            *ebx = esi;
                                                    }
                                                    else {
                                                            asm { fstp       st0 };
                                                    }
                                                    eax = arg_4;
                                                    esi = esi + 0x1;
                                                    edi = edi + 0x24;
                                            } while (esi < eax[0x900]);
                                    }
                            }
                    }
                    decomp_var_4 = decomp_var_4 + 0x100;
                    ebx = ebx + 0x4;
                    bool_231 = decomp_var_8 + 0x1 < arg_4[0x901];
                    decomp_var_8 = decomp_var_8 + 0x1;
            } while (bool_231);
    }
    sub_41a3a0(&arg_40, &arg_8, *arg_c, &arg_8, arg_c);
    sub_47c8f9();
    sub_403430(&arg_40, &arg_1c, *arg_20, &arg_1c, arg_20);
    sub_47c8f9();
    *0x0 = arg_6094;
    &decomp_var_14 = decomp_var_1c;
    return;

.l7:
    asm { fld1 };
    ecx = 0xb81228;
    asm { fld        qword [qword_value_4613937818241073152] };
    ebx = 0x0;
    asm { fld        qword [qword_value_13837309855095848960] };
    decomp_var_4 = ecx;
    goto .l54;

.l57:
    ecx = decomp_var_4;
    asm { fstp       st0 };
    eax = arg_4[0x901];
    edi = edi + 0x1;
    ecx = ecx + 0x8;
    ebx = ebx + 0x15;
    decomp_var_4 = ecx;
    if (edi < eax) {
            continue;
    }
    break;

.l58:
    esi = decomp_var_4;
    goto .l59;

.l54:
    asm { fld        st3 };
    if (!bool_320) {
            edx = eax;
            do {
                    asm { fadd       qword [ecx] };
                    ecx = ecx + 0xa8;
                    edx = edx - 0x1;
            } while (edx != 0x0);
    }
    edx = 0x0;
    if (eax <= 0x0) goto .l53;
    goto .l52;
    asm { fstp       st2 };
    asm { fstp       st0 };
    asm { fstp       st0 };
    goto .l5;

.l59:
    if (edx != edi) {
            if (*(edi * 0x4 + dword_623990) != 0x0 && *(edx * 0x4 + dword_623990) != 0x0) {
                    ecx = ebx + edx + ebx + edx + ebx + edx + ebx + edx;
                    asm { fld        qword [ecx+ecx+0xb81228] };
                    ecx = ecx + ecx;
                    asm { fcomp      qword [esi] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x41)) {
                            asm { fld        qword [ecx+0xb81228] };
                            asm { fadd       st4 };
                            asm { fdivr      qword [esi] };
                            asm { fmul       qword [esi] };
                            asm { fdiv       st1 };
                            asm { fmul       st3 };
                            asm { fstp       qword [ecx+0xb83b80] };
                    }
                    else {
                            asm { fld        qword [esi] };
                            asm { fadd       st4 };
                            asm { fdivr      qword [ecx+0xb81228] };
                            asm { fmul       qword [esi] };
                            asm { fdiv       st1 };
                            asm { fmul       st2 };
                            asm { fstp       qword [ecx+0xb83b80] };
                    }
            }
            else {
                    asm { fxch       st0, st4 };
                    eax = ebx + edx;
                    asm { fst        qword [dword_633f14+5569644+eax*8] };
                    asm { fxch       st0, st4 };
            }
    }
    edx = edx + 0x1;
    esi = esi + 0xa8;
    if (edx < arg_4[0x901]) {
            continue;
    }
    break;

.l53:
    ecx = decomp_var_4;
    asm { fstp       st0 };
    eax = arg_4[0x901];
    edi = edi + 0x1;
    ecx = ecx + 0x8;
    ebx = ebx + 0x15;
    decomp_var_4 = ecx;
    if (edi < eax) {
            continue;
    }
    break;

.l52:
    esi = decomp_var_4;
    goto .l55;
    asm { fstp       st2 };
    asm { fstp       st0 };
    asm { fstp       st0 };
    goto .l10;

.l55:
    if (edx != edi) {
            if (*(edi * 0x4 + dword_623990) != 0x0 && *(edx * 0x4 + dword_623990) != 0x0) {
                    ecx = ebx + edx + ebx + edx + ebx + edx + ebx + edx;
                    asm { fld        qword [ecx+ecx+0xb81228] };
                    ecx = ecx + ecx;
                    asm { fcomp      qword [esi] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x41)) {
                            asm { fld        qword [ecx+0xb81228] };
                            asm { fadd       st4 };
                            asm { fdivr      qword [esi] };
                            asm { fmul       qword [esi] };
                            asm { fdiv       st1 };
                            asm { fmul       st3 };
                            asm { fstp       qword [ecx+0xb83b80] };
                    }
                    else {
                            asm { fld        qword [esi] };
                            asm { fadd       st4 };
                            asm { fdivr      qword [ecx+0xb81228] };
                            asm { fmul       qword [esi] };
                            asm { fdiv       st1 };
                            asm { fmul       st2 };
                            asm { fstp       qword [ecx+0xb83b80] };
                    }
            }
            else {
                    asm { fxch       st0, st4 };
                    eax = ebx + edx;
                    asm { fst        qword [dword_633f14+5569644+eax*8] };
                    asm { fxch       st0, st4 };
            }
    }
    edx = edx + 0x1;
    esi = esi + 0xa8;
    if (edx < arg_4[0x901]) {
            continue;
    }
    break;
}
