// sub_445580 @ 0x445580
// hopper name: sub_445580
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_445580() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    decomp_var_464 = ebx;
    decomp_var_468 = ebp;
    decomp_var_46c = esi;
    decomp_var_470 = edi;
    esp = esp - 0x474;
    decomp_var_474 = *dword_4c8db8 ^ &decomp_var_470;
    *0x0 = &var_C;
    ebx = ecx;
    var_428 = ebx;
    eax = sub_40ff50();
    var_44C = eax;
    eax[0x15] = 0x1;
    var_44C[0x1] = var_44C;
    *var_44C = var_44C;
    ebp = 0x0;
    var_44C[0x2] = var_44C;
    asm { fldz };
    eax = ebx[0x2];
    esi = 0x0;
    if (eax[0x901] > ebp) {
            edx = eax[0x900];
            edi = 0x624ef8;
            do {
                    eax = 0x0;
                    if (edx > 0x0) {
                            ecx = edi;
                            do {
                                    asm { fst        dword [ecx] };
                                    edx = ebx[0x2];
                                    edx = edx[0x900];
                                    eax = eax + 0x1;
                                    ecx = ecx + 0x4;
                            } while (eax < edx);
                    }
                    esi = esi + 0x1;
                    edi = edi + 0x400;
            } while (esi < *(ebx[0x2] + 0x2404));
    }
    esi = ebx[0x2];
    ecx = esi[0x900];
    bool_2 = true;
    if (ecx > 0x0) {
            asm { rep stosd  dword [edi], eax };
    }
    ebp = 0x0;
    edx = 0x0;
    if (esi[0x901] > 0x0) {
            esi = 0x0;
            do {
                    *(edx * 0x4 + 0x6240d0) = *(edx * 0x4 + dword_623990);
                    ecx = 0x0;
                    if (*(ebx[0x2] + 0x2404) > ebp) {
                            eax = esi;
                            do {
                                    asm { fst        dword [eax+0x624810] };
                                    eax[0x18904a] = ebp;
                                    asm { fst        dword [eax+0x6239e8] };
                                    ecx = ecx + 0x1;
                                    eax = eax + 0x4;
                            } while (ecx < *(ebx[0x2] + 0x2404));
                    }
                    edx = edx + 0x1;
                    esi = esi + 0x54;
            } while (edx < *(ebx[0x2] + 0x2404));
    }
    eax = ebx[0x2];
    asm { fstp       st0 };
    esi = eax + 0x2450;
    ebp = *eax[0x915];
    var_45C = esi;
    var_458 = ebp;
    goto loc_4456d0;

loc_4456d0:
    eax = ebx[0x2];
    edi = eax[0x915];
    eax = eax + 0x2450;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (ebp != edi) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            *(&decomp_var_474 + arg_8 * 0x4 + 0x64) = 0x1;
            sub_401390();
            ebp = var_458;
            esi = var_45C;
            continue;
    }
    break;
    edi = **dword_bc1e20;
    esi = 0xbc1e1c;
    var_45C = 0xbc1e1c;
    var_458 = **dword_bc1e20;
    goto loc_445734;

loc_445734:
    if (esi == 0x0 || esi != 0xbc1e1c) {
            sub_47a948();
    }
    if (edi == *dword_bc1e20) goto .l33;
    goto loc_445753;

.l33:
    break;

loc_445753:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    eax = edi[0x3];
    var_430 = eax;
    edx = eax + eax * 0x8;
    eax = ebx[0x2];
    bool_17 = *(int8_t *)(eax + edx * 0x4 + 0x3) == 0x0;
    eax = eax + edx * 0x4;
    if (bool_17) {
            sub_40f6f0();
            esi = var_45C;
            edi = var_458;
            continue;
    }
    eax = eax[0x10];
    if (HIBYTE(eax) != 0x41 || (eax & 0xff) == 0x14) {
            sub_40f6f0();
            esi = var_45C;
            edi = var_458;
            continue;
    }
    if (var_458 == var_45C[0x1]) {
            sub_47a948();
    }
    edi = var_458;
    ebp = *edi[0x6];
    esi = edi + 0x14;
    var_438 = esi;
    var_434 = ebp;
    goto loc_4457c7;
    eax = *(ebx[0x2] + 0x2404);
    var_438 = 0x0;
    if (eax <= 0x0) goto loc_445b08;
    goto loc_4458ac;

loc_4457c7:
    if (edi == var_45C[0x1]) {
            sub_47a948();
    }
    eax = edi + 0x14;
    edi = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (ebp != edi) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            edi = &arg_8;
            var_420 = arg_c;
            if (*(&decomp_var_474 + arg_8 * 0x4 + 0x64) != 0x1) {
                    sub_40f7f0();
                    ebp = var_434;
                    esi = var_438;
                    edi = var_458;
                    continue;
            }
            if (ebp == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            edi = sub_407720(edi);
            if (var_420 == edi[0x2]) {
                    if (ebp == esi[0x1]) {
                            sub_47a948();
                    }
                    asm { fld        qword [qword_value_4666723172467343360] };
                    eax = edi[0x2];
                    asm { fdiv       qword [ebp+arg_18] };
                    eax = ((eax << 0x8) + var_430) * 0x4 + 0x624ef8;
                    asm { fadd       dword [eax] };
                    asm { fstp       dword [eax] };
            }
            sub_40f7f0();
            ebp = var_434;
            esi = var_438;
            edi = var_458;
            continue;
    }
    break;

loc_445b08:
    eax = ebx[0x2];
    eax = eax[0x901];
    if (eax > 0x0) {
            esi = 0x0;
            asm { fld        dword [aRemovalSelecte+28] };
            var_45C = esi;
            asm { fldz };
            ebp = 0x624810;
            do {
                    edx = 0x0;
                    if (eax > 0x0) {
                            ecx = var_45C;
                            edi = ebp;
                            do {
                                    asm { fcom       dword [edi] };
                                    asm { fnstsw     ax };
                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                            asm { fld        dword [ecx+0x624810] };
                                            asm { fdiv       dword [edi] };
                                            asm { fstp       dword [ecx+0x6239e8] };
                                    }
                                    else {
                                            asm { fxch       st0, st1 };
                                            asm { fst        dword [ecx+0x6239e8] };
                                            asm { fxch       st0, st1 };
                                    }
                                    eax = ebx[0x2];
                                    edx = edx + 0x1;
                                    ecx = ecx + 0x4;
                                    edi = edi + 0x54;
                            } while (edx < eax[0x901]);
                    }
                    eax = *(ebx[0x2] + 0x2404);
                    var_45C = var_45C + 0x54;
                    esi = esi + 0x1;
                    ebp = &arg_fffffffffffffffc;
            } while (esi < eax);
            asm { fstp       st1 };
            asm { fstp       st0 };
    }
    sub_41afd0(&var_424, &var_450, *var_44C, &var_450, var_44C);
    eax = sub_47c8f9();
    *0x0 = var_C;
    &decomp_var_460 = decomp_var_468;
    return eax;

loc_4458ac:
    var_444 = 0x0;
    var_45C = 0x0;
    goto loc_4458c0;
    sub_40f6f0();
    esi = var_45C;
    edi = var_458;
    continue;

loc_4458c0:
    var_440 = 0x0;
    if (eax <= 0x0) goto loc_445adf;
    goto loc_4458d0;

loc_445adf:
    eax = *(ebx[0x2] + 0x2404);
    var_45C = var_45C + 0x100;
    var_444 = var_444 + 0x15;
    bool_37 = var_438 + 0x1 < eax;
    var_438 = var_438 + 0x1;
    if (bool_37) {
            continue;
    }
    break;

loc_4458d0:
    eax = var_44C;
    ebp = eax[0x1];
    edi = ebp;
    if (arg_D == 0x0) {
            do {
                    sub_4019f0(edi[0x2]);
                    edi = *edi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    ebp = edi;
            } while (edi[0x15] == 0x0);
            eax = var_44C;
    }
    eax[0x1] = eax;
    *var_44C = var_44C;
    var_44C[0x2] = var_44C;
    eax = ebx[0x2];
    var_454 = 0x0;
    if (eax[0x900] <= 0x0) goto loc_445ac1;
    goto loc_44592d;

loc_445ac1:
    ebx = var_428;
    bool_41 = var_440 + 0x1 < *(ebx[0x2] + 0x2404);
    var_440 = var_440 + 0x1;
    if (bool_41) {
            continue;
    }
    break;

loc_44592d:
    esi = 0x0;
    var_43C = 0x0;
    do {
            ecx = var_43C;
            if (*(int8_t *)(eax + ecx + 0x3) != 0x0) {
                    eax = *(int16_t *)(eax + ecx + 0x20);
                    edi = eax & 0xff;
                    if (HIBYTE(eax) != 0x41) {
                            edi = 0x14;
                    }
                    if (edi == var_440) {
                            ecx = edi << 0x8;
                            ebp = var_45C + esi;
                            asm { fld        dword [dword_624ef4+4+ebp*4] };
                            ecx = ecx + esi;
                            asm { fdiv       dword [dword_624ef4+4+ecx*4] };
                            ebx = ecx * 0x4 + 0x624ef8;
                            decomp_var_478 = &var_424;
                            esp = esp - 0x8;
                            decomp_var_47c = &var_41C;
                            asm { fstp       dword [esp+0x47c+var_424] };
                            eax = sub_41a180(decomp_var_47c, decomp_var_478, decomp_var_474);
                            asm { fld        dword [dword_624ef4+4+ebp*4] };
                            asm { fld        dword [ebx] };
                            var_454 = var_454 + 0x1;
                            asm { fcompp };
                            asm { fnstsw     ax };
                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                    edx = *((var_444 + edi) * 0x8 + 0x4d5528);
                                    *((var_444 + edi) * 0x4 + 0x624128) = *((var_444 + edi) * 0x4 + 0x624128) + 0x1;
                                    if ((edx | *((var_444 + edi) * 0x8 + 0x4d552c)) == 0x0) {
                                            *(var_438 * 0x4 + 0x6240d0) = *(var_438 * 0x4 + 0x6240d0) + 0x1;
                                            *(edi * 0x4 + 0x6240d0) = *(edi * 0x4 + 0x6240d0) - 0x1;
                                    }
                            }
                    }
            }
            eax = var_428[0x2];
            var_43C = var_43C + 0x24;
            esi = esi + 0x1;
    } while (esi < eax[0x900]);
    if (var_454 <= 0x0) goto loc_445ac1;

loc_445a0f:
    asm { fild       dword [esp+0x474+var_454] };
    asm { fmul       qword [qword_value_4604480259023595110] };
    eax = sub_47b5c0();
    var_454 = eax;
    if (eax == 0x0) {
            var_454 = 0x1;
    }
    edi = *var_44C;
    esi = &var_450;
    ebx = 0x0;
    var_430 = esi;
    var_42C = edi;
    goto loc_445a42;

loc_445a42:
    ebp = var_44C;
    if (esi == 0x0 || esi != &var_450) {
            sub_47a948();
    }
    if (edi != ebp) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            bool_48 = edi >= esi[0x1];
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = var_440;
            asm { fld        dword [edi+0xc] };
            eax = eax + var_444;
            asm { fadd       dword [dword_62480c+4+eax*4] };
            ebx = ebx + 0x1;
            asm { fstp       dword [dword_62480c+4+eax*4] };
            if (!bool_48) {
                    sub_40f400();
                    edi = var_42C;
                    esi = var_430;
                    continue;
            }
            break;
    }
    else {
            break;
    }
    goto .l2;

.l2:
    eax = var_440 + var_444;
    asm { fld        dword [dword_62480c+4+eax*4] };
    asm { fidiv      dword [esp+0x474+var_454] };
    asm { fstp       dword [dword_62480c+4+eax*4] };
    goto loc_445ac1;
}
