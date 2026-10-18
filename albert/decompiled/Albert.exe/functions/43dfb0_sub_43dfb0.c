// sub_43dfb0 @ 0x43dfb0
// hopper name: sub_43dfb0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5603afdb33265f2ea0acc9a81cbc14c61d166c3a97fb9b974c9d4823276f52ec
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_43dfb0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    sub_47bf20();
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    esp = esp - 0x10;
    var_10 = edi;
    ebp = ecx;
    edx = 0x0;
    arg_1c = ebp;
    if (arg_0[0x900] > 0x0) {
            edi = edi | 0xffffffff;
            do {
                    *(edx * 0x4 + 0xba1fb0) = edi;
                    esi = arg_0;
                    ecx = esi[0x901];
                    if (ecx > 0x0) {
                            eax = &var_10 + edx * 0x4 + 0x38;
                            do {
                                    *eax = 0x0;
                                    eax = eax + 0x400;
                                    ecx = ecx - 0x1;
                            } while (ecx != 0x0);
                    }
                    edx = edx + 0x1;
            } while (edx < esi[0x900]);
    }
    esi = arg_0 + 0x2450;
    ebx = *arg_0[0x915];
    arg_c = esi;
    arg_10 = ebx;
    goto loc_43e040;

loc_43e040:
    edi = arg_0[0x915];
    eax = arg_0 + 0x2450;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (ebx == edi) goto .l22;
    goto loc_43e063;

.l22:
    break;

loc_43e063:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (ebx == esi[0x1]) {
            sub_47a948();
            if (ebx == esi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(ebx + 0x14, var_10);
    edx = arg_0[0x901];
    edi = eax;
    eax = 0x0;
    arg_14 = edi;
    if (edx > 0x0) {
            ecx = 0x0;
            do {
                    if (eax != ebx[0x6]) {
                            *(&var_10 + (ebx[0x4] + ecx) * 0x4 + 0x38) = 0x1;
                    }
                    eax = eax + 0x1;
                    ecx = ecx + 0x100;
            } while (eax < edx);
    }
    ebx = edi;
    arg_4 = ebx;
    arg_8 = *edi[0x1];
    goto loc_43e0e0;
    edi = arg_0;
    eax = edi[0x900];
    if (eax > 0x0) {
            edx = &arg_20;
            arg_0 = edx;
            edi = edi + 0x20;
            arg_14 = eax;
            do {
                    if (*(int8_t *)(edi - 0x1d) == 0x1) {
                            esi = arg_0[0x901];
                            eax = 0x0;
                            if (esi > 0x0) {
                                    ebx = *(int16_t *)edi;
                                    ecx = ebx >> 0x8;
                                    var_FFFFFFFFFFFFFFFA = ecx;
                                    while (true) {
                                            bool_43 = ecx == 0x41;
                                            ecx = ebx & 0xff;
                                            if (!bool_43) {
                                                    ecx = 0x14;
                                            }
                                            if (eax != ecx) {
                                                    *edx = 0x1;
                                            }
                                            eax = eax + 0x1;
                                            edx = edx + 0x400;
                                            if (eax >= esi) {
                                                    break;
                                            }
                                            ecx = var_FFFFFFFFFFFFFFFA;
                                    }
                            }
                    }
                    edx = arg_0 + 0x4;
                    edi = edi + 0x24;
                    arg_14 = arg_14 - 0x1;
                    arg_0 = edx;
            } while (arg_14 != 0x0);
    }
    edi = *arg_0[0x915];
    ebx = arg_0 + 0x2450;
    arg_c = ebx;
    arg_10 = edi;
    &var_10 = &var_10;
    goto loc_43e210;

loc_43e0e0:
    esi = edi[0x1];
    if (ebx == 0x0 || ebx != edi) {
            sub_47a948();
    }
    if (arg_8 != esi) {
            esi = 0x0;
            if (arg_0[0x901] <= 0x0) {
                    sub_40f400();
                    ebx = arg_4;
                    continue;
            }
            edi = 0x0;
            do {
                    if (esi != arg_10[0x6]) {
                            if (ebx == 0x0) {
                                    sub_47a948();
                            }
                            if (arg_8 == ebx[0x1]) {
                                    sub_47a948();
                            }
                            *(&var_10 + (arg_8[0x3] + edi) * 0x4 + 0x38) = 0x1;
                    }
                    esi = esi + 0x1;
                    edi = edi + 0x100;
            } while (esi < arg_0[0x901]);
            edi = arg_14;
            sub_40f400();
            ebx = arg_4;
            continue;
    }
    break;

loc_43e210:
    esi = arg_0[0x915];
    eax = arg_0 + 0x2450;
    if (ebx == 0x0 || ebx != eax) {
            eax = sub_47a948();
    }
    if (edi == esi) goto .l25;
    goto loc_43e233;
    sub_401390();
    esi = arg_c;
    ebx = arg_10;
    continue;

.l25:
    break;

loc_43e233:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    esi = edi + 0x10;
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    ebx = sub_4075b0(esi + 0x4, var_10);
    esp = esp - 0x8;
    eax = sub_41c1e0(esi);
    ecx = esi[0x2];
    edx = ebx[0x1];
    eax = *eax;
    ebp = *edx;
    edi = ebx;
    arg_0 = eax;
    var_FFFFFFFFFFFFFFFA = *(&var_10 + ((ecx << 0x8) + *esi) * 0x4 + 0x38) != 0x1 ? 0x1 : 0x0;
    arg_4 = edi;
    arg_8 = ebp;
    goto loc_43e2a5;
    &saved_fp = decomp_var_8;
    return eax;

loc_43e2a5:
    arg_18 = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (ebp != arg_18) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebp == edi[0x1]) {
                    sub_47a948();
            }
            edi = &arg_4;
            esp = esp - 0x4;
            eax = sub_41c1e0(edi);
            eax = *eax;
            if (eax > arg_0) {
                    arg_0 = eax;
            }
            if (ebp == arg_4[0x1]) {
                    sub_47a948();
            }
            if (*(&var_10 + ((esi[0x2] << 0x8) + *edi) * 0x4 + 0x38) == 0x1) {
                    var_FFFFFFFFFFFFFFFA = 0x0;
            }
            sub_40f400();
            ebp = arg_8;
            edi = arg_4;
            continue;
    }
    break;
    if (var_FFFFFFFFFFFFFFFA == 0x1) {
            *(*esi * 0x4 + 0xba1fb0) = arg_0;
    }
    sub_401390();
    edi = arg_10;
    ebx = arg_c;
    ebp = arg_1c;
    continue;
}
