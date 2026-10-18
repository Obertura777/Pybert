// Recover @ 0x424850
// hopper name: sub_424850
// pybert name: Recover
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

Recover() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    esp = esp - 0xc4;
    *0x0 = &var_C;
    eax = sub_410330();
    eax[0x19] = 0x1;
    eax[0x1] = eax;
    *eax = eax;
    edi = 0x0;
    eax[0x2] = eax;
    sub_465870();
    asm { fild       dword [dword_62cc64] };
    var_74 = *dword_62cc64 + 0x2;
    asm { fidiv      dword [esp+0xc4+var_74] };
    esi = arg_0;
    var_88 = *(esi * 0x4 + 0x62e460) + 0x1;
    esp = esp - 0x4;
    decomp_var_c8 = var_98[0x1];
    asm { fstp       dword [esp+0xc8+var_74] };
    asm { fild       dword [esp+0xc8+var_88] };
    asm { fdivr      qword [qword_value_4610785298501913804] };
    asm { fadd       qword [qword_value_4610560118520545280] };
    asm { fstp       dword [esp+0xc8+var_84] };
    sub_40fb70(decomp_var_c8);
    var_98[0x1] = var_98;
    *var_98 = var_98;
    var_98[0x2] = var_98;
    esi = *(esi * 0x4 + 0xb9fe88);
    asm { fild       dword [esp+0xc4+var_B0] };
    asm { fld        qword [qword_value_4587366580439587226] };
    asm { fmul       st1 };
    asm { fadd       qword [qword_value_4617315517961601024] };
    eax = sub_47b5c0();
    asm { fld1 };
    arg_44 = eax;
    eax = *dword_62cc64;
    bool_4 = eax >= edi;
    if (eax == edi) {
            asm { fstp       st1 };
            ecx = esi + 0xbb8;
            asm { fild       dword [esp+arg_C] };
            asm { fstp       dword [esp+arg_34] };
            asm { fld        dword [esp+arg_34] };
            arg_34 = ecx;
            asm { fld        st0 };
            asm { fidiv      dword [esp+arg_34] };
            asm { fsubr      st2 };
            asm { fmulp      st1 };
            asm { faddp      st1 };
            sub_47b5c0();
    }
    else {
            asm { fstp       st0 };
            if (!bool_4) {
                    arg_34 = 0x1 - esi / (esi + 0x1f4);
                    asm { fild       dword [esp+arg_34] };
                    asm { fild       dword [dword_62cc64] };
                    asm { fmul       qword [qword_value_4590284912998123307] };
                    asm { fsubr      qword [qword_value_4603579539098121011] };
                    asm { fmulp      st2 };
                    asm { fmulp      st1 };
                    asm { fiadd      dword [esp+arg_44] };
                    sub_47b5c0();
            }
            else {
                    asm { fstp       st0 };
            }
    }
    if (arg_4 == 0x0) {
            arg_4c = esi + 0x1;
    }
    edi = **dword_bbf60c;
    esi = 0xbbf608;
    arg_44 = 0xbbf608;
    arg_48 = **dword_bbf60c;
    goto loc_424a06;

loc_424a06:
    if (esi == 0x0 || esi != 0xbbf608) {
            sub_47a948();
    }
    if (edi != *dword_bbf60c) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi[0x7] != arg_0) {
                    sub_40f260();
                    edi = arg_48;
                    esi = arg_44;
                    continue;
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi[0x9] > arg_18) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    arg_18 = edi[0x9];
            }
            sub_40f260();
            edi = arg_48;
            esi = arg_44;
            continue;
    }
    break;
    edi = **dword_bbf60c;
    ebx = 0x9c4 - arg_18;
    esi = 0xbbf608;
    arg_54 = ebx;
    arg_44 = 0xbbf608;
    arg_48 = **dword_bbf60c;
    goto loc_424aa0;

loc_424aa0:
    arg_78 = *dword_bbf60c;
    if (esi == 0x0 || esi != 0xbbf608) {
            sub_47a948();
    }
    if (edi != arg_78) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi[0x7] == arg_0) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    arg_60 = edi[0x9] + ebx;
                    esp = esp - 0x8;
                    arg_0 = &arg_98;
                    arg_68 = edi;
                    sub_419fa0(arg_0, &arg_60, arg_8);
            }
            sub_40f260();
            edi = arg_50;
            esi = arg_4c;
            continue;
    }
    break;
    esi = *arg_34;
    ebx = &arg_30;
    arg_1c = 0x1;
    temp_3 = 0x3;
    goto .l28;

.l28:
    if (temp_3 == 0x3) goto loc_424b32;
    goto .l32;

loc_424b32:
    arg_2c = esi;
    arg_28 = ebx;
    edi = arg_34;
    if (ebx == 0x0 || ebx != &arg_30) {
            sub_47a948();
    }
    if (esi == edi) goto .l35;
    goto .l3;

.l32:
    if (temp_3 == 0x4) goto loc_424b40;
    goto loc_424c50;

.l35:
    break;

.l3:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    if (*(int8_t *)(esi[0x5] + 0x50) != 0x0) {
            if (arg_2F == 0x1) {
                    arg_8 = ebx;
                    esp = esp - 0xc;
                    eax = sub_412540(&arg_68, arg_8, esi, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, arg_2c, arg_30, arg_34, arg_38, arg_3c, arg_40, arg_44, arg_48);
                    ebx = *eax;
                    esi = eax[0x1];
                    temp_3 = 0x3;
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x28) > arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x28) = arg_24;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x2c) < arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x2c) = arg_24;
                    }
                    sub_40e680();
                    arg_24 = arg_24 + 0x1;
                    esi = arg_34;
                    ebx = arg_30;
                    temp_3 = 0x4;
            }
            continue;
    }
    bool_235 = esi != ebx[0x1];
    edi = &arg_30;
    arg_3c = edi;
    arg_40 = *arg_34;
    if (!bool_235) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    if (*(esi[0x5] + 0x4c) == 0x0) {
            arg_20 = 0x64;
            temp_3 = 0x26;
            continue;
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    eax = *(esi[0x5] + 0x4c);
    arg_20 = (-(eax - 0x1) - -(eax - 0x1) + CARRY(EFLAGS(cf)) & 0xffffffce) + 0x32;
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (arg_48 == esi) {
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            *(int8_t *)(esi[0x5] + 0x51) = arg_2F;
            if (arg_2F == 0x1) {
                    arg_8 = ebx;
                    esp = esp - 0xc;
                    eax = sub_412540(&arg_68, arg_8, esi, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, arg_2c, arg_30, arg_34, arg_38, arg_3c, arg_40, arg_44, arg_48);
                    ebx = *eax;
                    esi = eax[0x1];
                    temp_3 = 0x3;
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x28) > arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x28) = arg_24;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x2c) < arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x2c) = arg_24;
                    }
                    sub_40e680();
                    arg_24 = arg_24 + 0x1;
                    esi = arg_34;
                    ebx = arg_30;
                    temp_3 = 0x4;
            }
            continue;
    }
    ebx = 0x0;
    if (*dword_62cc64 <= 0xffffffff) {
            if (esi == arg_30[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            ebx = esi[0x5];
            ebx = ebx + 0xc;
            if (edi == 0x0) {
                    sub_47a948();
            }
            eax = arg_48;
            if (eax == edi[0x1]) {
                    sub_47a948();
                    eax = arg_48;
            }
            if (eax[0x4] == 0x0) {
                    sub_47a948();
                    eax = arg_48;
            }
            if (eax[0x5] == *(eax[0x4] + 0x4)) {
                    sub_47a948();
                    eax = arg_48;
            }
            edx = eax[0x5];
            eax = *dword_62cc64;
            if (*(ebx + eax * 0x4 + 0x140) == *(edx + eax * 0x4 + 0x14c)) {
                    sub_40e680();
                    edi = arg_44;
                    ebx = arg_30;
                    temp_3 = 0x26;
                    continue;
            }
            ebx = arg_30;
            arg_2F = 0x1;
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            *(int8_t *)(esi[0x5] + 0x51) = arg_2F;
            if (arg_2F == 0x1) {
                    arg_8 = ebx;
                    esp = esp - 0xc;
                    eax = sub_412540(&arg_68, arg_8, esi, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, arg_2c, arg_30, arg_34, arg_38, arg_3c, arg_40, arg_44, arg_48);
                    ebx = *eax;
                    esi = eax[0x1];
                    temp_3 = 0x3;
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x28) > arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x28) = arg_24;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x2c) < arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x2c) = arg_24;
                    }
                    sub_40e680();
                    arg_24 = arg_24 + 0x1;
                    esi = arg_34;
                    ebx = arg_30;
                    temp_3 = 0x4;
            }
            continue;
    }
    goto loc_424c79;

loc_424b40:
    edi = arg_34;
    if (ebx == 0x0 || ebx != &arg_30) {
            sub_47a948();
    }
    if (esi == edi) goto .l4;
    goto loc_424b5d;

loc_424c50:
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (arg_48 == esi) {
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            *(int8_t *)(esi[0x5] + 0x51) = arg_2F;
            if (arg_2F == 0x1) {
                    arg_8 = ebx;
                    esp = esp - 0xc;
                    eax = sub_412540(&arg_68, arg_8, esi, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, arg_2c, arg_30, arg_34, arg_38, arg_3c, arg_40, arg_44, arg_48);
                    ebx = *eax;
                    esi = eax[0x1];
                    temp_3 = 0x3;
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x28) > arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x28) = arg_24;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x2c) < arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x2c) = arg_24;
                    }
                    sub_40e680();
                    arg_24 = arg_24 + 0x1;
                    esi = arg_34;
                    ebx = arg_30;
                    temp_3 = 0x4;
            }
            continue;
    }
    ebx = 0x0;
    if (*dword_62cc64 <= 0xffffffff) {
            if (esi == arg_30[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            ebx = esi[0x5];
            ebx = ebx + 0xc;
            if (edi == 0x0) {
                    sub_47a948();
            }
            eax = arg_48;
            if (eax == edi[0x1]) {
                    sub_47a948();
                    eax = arg_48;
            }
            if (eax[0x4] == 0x0) {
                    sub_47a948();
                    eax = arg_48;
            }
            if (eax[0x5] == *(eax[0x4] + 0x4)) {
                    sub_47a948();
                    eax = arg_48;
            }
            edx = eax[0x5];
            eax = *dword_62cc64;
            if (*(ebx + eax * 0x4 + 0x140) == *(edx + eax * 0x4 + 0x14c)) {
                    sub_40e680();
                    edi = arg_44;
                    ebx = arg_30;
                    temp_3 = 0x26;
                    continue;
            }
            ebx = arg_30;
            arg_2F = 0x1;
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            *(int8_t *)(esi[0x5] + 0x51) = arg_2F;
            if (arg_2F == 0x1) {
                    arg_8 = ebx;
                    esp = esp - 0xc;
                    eax = sub_412540(&arg_68, arg_8, esi, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, arg_2c, arg_30, arg_34, arg_38, arg_3c, arg_40, arg_44, arg_48);
                    ebx = *eax;
                    esi = eax[0x1];
                    temp_3 = 0x3;
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x28) > arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x28) = arg_24;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x2c) < arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x2c) = arg_24;
                    }
                    sub_40e680();
                    arg_24 = arg_24 + 0x1;
                    esi = arg_34;
                    ebx = arg_30;
                    temp_3 = 0x4;
            }
            continue;
    }
    goto .l7;
    edx = arg_34;
    asm { fldz };
    esi = *edx;
    asm { fstp       dword [esp-0x10+arg_44] };
    edi = &arg_30;
    arg_1c = 0x0;
    arg_28 = edi;
    arg_2c = esi;
    &arg_8 = &arg_8;
    goto loc_424f20;

loc_424c79:
    if (ebx == 0x0 && *dword_62cc64 > 0x7) {
            ebx = 0x2;
    }
    if (esi == arg_30[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    edi = esi[0x5];
    edi = edi + 0xc;
    if (arg_44 == 0x0) {
            sub_47a948();
    }
    eax = arg_48;
    if (eax == arg_44[0x1]) {
            sub_47a948();
            eax = arg_48;
    }
    if (eax[0x4] == 0x0) {
            sub_47a948();
            eax = arg_48;
    }
    if (eax[0x5] == *(eax[0x4] + 0x4)) {
            sub_47a948();
            eax = arg_48;
    }
    if (*(edi + ebx * 0x4 + 0xc8) + arg_28 <= *(eax[0x5] + ebx * 0x4 + 0xd4)) {
            ebx = ebx + 0x1;
            if (ebx < *dword_62cc64 + 0x1) {
                    continue;
            }
            temp_2 = 0x0;
            break;
    }
    else {
            temp_2 = 0x1;
            break;
    }
    goto .l5;

.l4:
    break;

loc_424b5d:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    if (*(int8_t *)(esi[0x5] + 0x50) != 0x0) {
            if (arg_2F == 0x1) {
                    arg_8 = ebx;
                    esp = esp - 0xc;
                    eax = sub_412540(&arg_68, arg_8, esi, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, arg_2c, arg_30, arg_34, arg_38, arg_3c, arg_40, arg_44, arg_48);
                    ebx = *eax;
                    esi = eax[0x1];
                    temp_3 = 0x3;
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x28) > arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x28) = arg_24;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x2c) < arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x2c) = arg_24;
                    }
                    sub_40e680();
                    arg_24 = arg_24 + 0x1;
                    esi = arg_34;
                    ebx = arg_30;
                    temp_3 = 0x4;
            }
            continue;
    }
    bool_392 = esi != ebx[0x1];
    edi = &arg_30;
    arg_3c = edi;
    arg_40 = *arg_34;
    if (!bool_392) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    if (*(esi[0x5] + 0x4c) == 0x0) {
            arg_20 = 0x64;
            temp_3 = 0x26;
            continue;
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    eax = *(esi[0x5] + 0x4c);
    arg_20 = (-(eax - 0x1) - -(eax - 0x1) + CARRY(EFLAGS(cf)) & 0xffffffce) + 0x32;
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (arg_48 == esi) {
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            *(int8_t *)(esi[0x5] + 0x51) = arg_2F;
            if (arg_2F == 0x1) {
                    arg_8 = ebx;
                    esp = esp - 0xc;
                    eax = sub_412540(&arg_68, arg_8, esi, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, arg_2c, arg_30, arg_34, arg_38, arg_3c, arg_40, arg_44, arg_48);
                    ebx = *eax;
                    esi = eax[0x1];
                    temp_3 = 0x3;
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x28) > arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x28) = arg_24;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x2c) < arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x2c) = arg_24;
                    }
                    sub_40e680();
                    arg_24 = arg_24 + 0x1;
                    esi = arg_34;
                    ebx = arg_30;
                    temp_3 = 0x4;
            }
            continue;
    }
    ebx = 0x0;
    if (*dword_62cc64 <= 0xffffffff) {
            if (esi == arg_30[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            ebx = esi[0x5];
            ebx = ebx + 0xc;
            if (edi == 0x0) {
                    sub_47a948();
            }
            eax = arg_48;
            if (eax == edi[0x1]) {
                    sub_47a948();
                    eax = arg_48;
            }
            if (eax[0x4] == 0x0) {
                    sub_47a948();
                    eax = arg_48;
            }
            if (eax[0x5] == *(eax[0x4] + 0x4)) {
                    sub_47a948();
                    eax = arg_48;
            }
            edx = eax[0x5];
            eax = *dword_62cc64;
            if (*(ebx + eax * 0x4 + 0x140) == *(edx + eax * 0x4 + 0x14c)) {
                    sub_40e680();
                    edi = arg_44;
                    ebx = arg_30;
                    temp_3 = 0x26;
                    continue;
            }
            ebx = arg_30;
            arg_2F = 0x1;
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            *(int8_t *)(esi[0x5] + 0x51) = arg_2F;
            if (arg_2F == 0x1) {
                    arg_8 = ebx;
                    esp = esp - 0xc;
                    eax = sub_412540(&arg_68, arg_8, esi, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, arg_2c, arg_30, arg_34, arg_38, arg_3c, arg_40, arg_44, arg_48);
                    ebx = *eax;
                    esi = eax[0x1];
                    temp_3 = 0x3;
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x28) > arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x28) = arg_24;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    if (*(esi[0x5] + 0x2c) < arg_24) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x4] == 0x0) {
                                    sub_47a948();
                            }
                            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                                    sub_47a948();
                            }
                            *(esi[0x5] + 0x2c) = arg_24;
                    }
                    sub_40e680();
                    arg_24 = arg_24 + 0x1;
                    esi = arg_34;
                    ebx = arg_30;
                    temp_3 = 0x4;
            }
            continue;
    }
    goto .l8;

.l7:
    if (ebx == 0x0 && *dword_62cc64 > 0x7) {
            ebx = 0x2;
    }
    if (esi == arg_30[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    edi = esi[0x5];
    edi = edi + 0xc;
    if (arg_44 == 0x0) {
            sub_47a948();
    }
    eax = arg_48;
    if (eax == arg_44[0x1]) {
            sub_47a948();
            eax = arg_48;
    }
    if (eax[0x4] == 0x0) {
            sub_47a948();
            eax = arg_48;
    }
    if (eax[0x5] == *(eax[0x4] + 0x4)) {
            sub_47a948();
            eax = arg_48;
    }
    if (*(edi + ebx * 0x4 + 0xc8) + arg_28 <= *(eax[0x5] + ebx * 0x4 + 0xd4)) {
            ebx = ebx + 0x1;
            if (ebx < *dword_62cc64 + 0x1) {
                    continue;
            }
            temp_2 = 0x0;
            break;
    }
    else {
            temp_2 = 0x1;
            break;
    }
    goto .l6;

loc_424f20:
    ebx = arg_34;
    if (edi == 0x0 || edi != &arg_30) {
            sub_47a948();
    }
    if (esi != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            if (*(int8_t *)(esi[0x5] + 0x50) != 0x0) {
                    sub_40e680();
                    esi = arg_2c;
                    edi = arg_28;
                    continue;
            }
            asm { fldz };
            arg_1c = arg_1c + 0x1;
            asm { fst        dword [esp-0x10+arg_20] };
            asm { fst        dword [esp-0x10+arg_8C] };
            arg_7C = edi;
            asm { fstp       dword [esp-0x10+arg_6C] };
            arg_80 = esi;
            sub_40e680();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] > 0x0) {
                    ebx = arg_7C;
                    arg_A8 = arg_34;
                    if (ebx == 0x0 || ebx != &arg_30) {
                            sub_47a948();
                    }
                    edi = arg_80;
                    if (edi != arg_A8) {
                            if (ebx == 0x0) {
                                    sub_47a948();
                            }
                            if (edi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (edi[0x3] > 0x0) {
                                    if (edi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (esi == arg_28[0x1]) {
                                            sub_47a948();
                                    }
                                    if (edi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (esi == arg_28[0x1]) {
                                            sub_47a948();
                                    }
                                    if (edi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    edx = esi[0x3];
                                    asm { fild       dword [edi+0xc] };
                                    edx = edx - edi[0x3];
                                    asm { fstp       dword [esp-0x10+arg_3C] };
                                    arg_20 = edx;
                                    asm { fild       dword [esp-0x10+arg_20] };
                                    asm { fld        dword [esp-0x10+arg_48] };
                                    sub_47b370();
                                    asm { fstp       dword [esp-0x10+arg_20] };
                                    eax = esi[0x3];
                                    asm { fld        dword [esp-0x10+arg_20] };
                                    arg_20 = eax + edi[0x3];
                                    asm { fiadd      dword [esp-0x10+arg_20] };
                                    asm { fdivr      dword [esp-0x10+arg_3C] };
                                    asm { fstp       dword [esp-0x10+arg_20] };
                            }
                            arg_84 = ebx;
                            arg_88 = edi;
                            sub_40e680();
                            ebx = arg_84;
                            arg_9C = arg_34;
                            if (ebx == 0x0 || ebx != &arg_30) {
                                    sub_47a948();
                            }
                            edi = arg_88;
                            if (edi != arg_9C) {
                                    if (ebx == 0x0) {
                                            sub_47a948();
                                    }
                                    if (edi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (edi[0x3] > 0x0) {
                                            if (edi == ebx[0x1]) {
                                                    sub_47a948();
                                            }
                                            if (esi == arg_28[0x1]) {
                                                    sub_47a948();
                                            }
                                            if (edi == ebx[0x1]) {
                                                    sub_47a948();
                                            }
                                            if (esi == arg_28[0x1]) {
                                                    sub_47a948();
                                            }
                                            if (edi == ebx[0x1]) {
                                                    sub_47a948();
                                            }
                                            asm { fild       dword [edi+0xc] };
                                            edx = esi[0x3];
                                            edx = edx - edi[0x3];
                                            asm { fmul       qword [qword_value_4604174014248933917] };
                                            arg_3c = edx;
                                            asm { fstp       qword [esp-0x10+arg_8C] };
                                            asm { fild       dword [esp-0x10+arg_3C] };
                                            asm { fld        dword [esp-0x10+arg_48] };
                                            sub_47b370();
                                            asm { fstp       dword [esp-0x10+arg_3C] };
                                            eax = esi[0x3];
                                            asm { fld        dword [esp-0x10+arg_3C] };
                                            arg_3c = eax + edi[0x3];
                                            asm { fiadd      dword [esp-0x10+arg_3C] };
                                            asm { fdivr      qword [esp-0x10+arg_8C] };
                                            asm { fstp       dword [esp-0x10+arg_8C] };
                                    }
                                    arg_74 = ebx;
                                    arg_78 = edi;
                                    sub_40e680();
                                    ebx = arg_74;
                                    arg_64 = arg_34;
                                    if (ebx == 0x0 || ebx != &arg_30) {
                                            sub_47a948();
                                    }
                                    edi = arg_78;
                                    if (edi != arg_64) {
                                            if (ebx == 0x0) {
                                                    sub_47a948();
                                            }
                                            if (edi == ebx[0x1]) {
                                                    sub_47a948();
                                            }
                                            if (edi[0x3] > 0x0) {
                                                    if (edi == ebx[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    if (esi == arg_28[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    if (edi == ebx[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    if (esi == arg_28[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    if (edi == ebx[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    asm { fild       dword [edi+0xc] };
                                                    edx = esi[0x3];
                                                    edx = edx - edi[0x3];
                                                    asm { fmul       qword [qword_value_4602678819172646912] };
                                                    arg_3c = edx;
                                                    asm { fstp       qword [esp-0x10+arg_6C] };
                                                    asm { fild       dword [esp-0x10+arg_3C] };
                                                    asm { fld        dword [esp-0x10+arg_48] };
                                                    sub_47b370();
                                                    asm { fstp       dword [esp-0x10+arg_3C] };
                                                    eax = esi[0x3];
                                                    asm { fld        dword [esp-0x10+arg_3C] };
                                                    arg_3c = eax + edi[0x3];
                                                    asm { fiadd      dword [esp-0x10+arg_3C] };
                                                    asm { fdivr      qword [esp-0x10+arg_6C] };
                                                    asm { fstp       dword [esp-0x10+arg_6C] };
                                            }
                                    }
                            }
                    }
            }
            asm { fld        dword [esp-0x10+arg_44] };
            bool_67 = esi != arg_28[0x1];
            asm { fld        st0 };
            asm { fsubr      qword [qword_value_4636737291354636288] };
            asm { fld        dword [esp-0x10+arg_20] };
            asm { fld1 };
            asm { fld        st0 };
            asm { fsubrp     st2 };
            asm { fxch       st0, st2 };
            asm { fmulp      st1 };
            asm { fld        dword [esp-0x10+arg_8C] };
            asm { fsubr      st2 };
            asm { fmulp      st1 };
            asm { fld        dword [esp-0x10+arg_6C] };
            asm { fsubp      st2 };
            asm { fmulp      st1 };
            asm { fstp       dword [esp-0x10+arg_6C] };
            asm { fadd       dword [esp-0x10+arg_6C] };
            asm { fstp       dword [esp-0x10+arg_44] };
            if (!bool_67) {
                    sub_47a948();
            }
            edi = esi[0x4];
            esi = esi[0x5];
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            asm { fld        dword [esp-0x10+arg_6C] };
            asm { fstp       dword [esi+0x58] };
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_73 = esi != edi[0x1];
            asm { fld        dword [esp-0x10+arg_58] };
            asm { fld        st0 };
            asm { fld1 };
            asm { fsubrp     st1 };
            asm { fimul      dword [esp-0x10+arg_1C] };
            asm { fld        dword [esi+0x30] };
            asm { fmulp      st2 };
            asm { faddp      st1 };
            asm { fstp       dword [esp-0x10+arg_20] };
            if (!bool_73) {
                    sub_47a948();
            }
            asm { fld        dword [esp-0x10+arg_20] };
            asm { fstp       dword [esi+0x30] };
            sub_40e680();
            esi = arg_2c;
            edi = arg_28;
            continue;
    }
    break;

.l5:
    if (temp_2 != 0x0) {
            sub_40e680();
            edi = arg_44;
            ebx = arg_30;
            temp_3 = 0x26;
            continue;
    }
    edi = arg_44;
    if (esi == arg_30[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    ebx = esi[0x5];
    ebx = ebx + 0xc;
    if (edi == 0x0) {
            sub_47a948();
    }
    eax = arg_48;
    if (eax == edi[0x1]) {
            sub_47a948();
            eax = arg_48;
    }
    if (eax[0x4] == 0x0) {
            sub_47a948();
            eax = arg_48;
    }
    if (eax[0x5] == *(eax[0x4] + 0x4)) {
            sub_47a948();
            eax = arg_48;
    }
    edx = eax[0x5];
    eax = *dword_62cc64;
    if (*(ebx + eax * 0x4 + 0x140) == *(edx + eax * 0x4 + 0x14c)) {
            sub_40e680();
            edi = arg_44;
            ebx = arg_30;
            temp_3 = 0x26;
            continue;
    }
    ebx = arg_30;
    arg_2F = 0x1;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    *(int8_t *)(esi[0x5] + 0x51) = arg_2F;
    if (arg_2F == 0x1) {
            arg_8 = ebx;
            esp = esp - 0xc;
            eax = sub_412540(&arg_68, arg_8, esi, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, arg_2c, arg_30, arg_34, arg_38, arg_3c, arg_40, arg_44, arg_48);
            ebx = *eax;
            esi = eax[0x1];
            temp_3 = 0x3;
    }
    else {
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            if (*(esi[0x5] + 0x28) > arg_24) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    *(esi[0x5] + 0x28) = arg_24;
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            if (*(esi[0x5] + 0x2c) < arg_24) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    *(esi[0x5] + 0x2c) = arg_24;
            }
            sub_40e680();
            arg_24 = arg_24 + 0x1;
            esi = arg_34;
            ebx = arg_30;
            temp_3 = 0x4;
    }
    continue;

.l8:
    if (ebx == 0x0 && *dword_62cc64 > 0x7) {
            ebx = 0x2;
    }
    if (esi == arg_30[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    edi = esi[0x5];
    edi = edi + 0xc;
    if (arg_44 == 0x0) {
            sub_47a948();
    }
    eax = arg_48;
    if (eax == arg_44[0x1]) {
            sub_47a948();
            eax = arg_48;
    }
    if (eax[0x4] == 0x0) {
            sub_47a948();
            eax = arg_48;
    }
    if (eax[0x5] == *(eax[0x4] + 0x4)) {
            sub_47a948();
            eax = arg_48;
    }
    if (*(edi + ebx * 0x4 + 0xc8) + arg_28 <= *(eax[0x5] + ebx * 0x4 + 0xd4)) {
            ebx = ebx + 0x1;
            if (ebx < *dword_62cc64 + 0x1) {
                    continue;
            }
            temp_2 = 0x0;
            break;
    }
    else {
            temp_2 = 0x1;
            break;
    }
    goto .l9;

.l6:
    if (temp_2 != 0x0) {
            sub_40e680();
            edi = arg_44;
            ebx = arg_30;
            temp_3 = 0x26;
            continue;
    }
    edi = arg_44;
    if (esi == arg_30[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    ebx = esi[0x5];
    ebx = ebx + 0xc;
    if (edi == 0x0) {
            sub_47a948();
    }
    eax = arg_48;
    if (eax == edi[0x1]) {
            sub_47a948();
            eax = arg_48;
    }
    if (eax[0x4] == 0x0) {
            sub_47a948();
            eax = arg_48;
    }
    if (eax[0x5] == *(eax[0x4] + 0x4)) {
            sub_47a948();
            eax = arg_48;
    }
    edx = eax[0x5];
    eax = *dword_62cc64;
    if (*(ebx + eax * 0x4 + 0x140) == *(edx + eax * 0x4 + 0x14c)) {
            sub_40e680();
            edi = arg_44;
            ebx = arg_30;
            temp_3 = 0x26;
            continue;
    }
    ebx = arg_30;
    arg_2F = 0x1;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    *(int8_t *)(esi[0x5] + 0x51) = arg_2F;
    if (arg_2F == 0x1) {
            arg_8 = ebx;
            esp = esp - 0xc;
            eax = sub_412540(&arg_68, arg_8, esi, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, arg_2c, arg_30, arg_34, arg_38, arg_3c, arg_40, arg_44, arg_48);
            ebx = *eax;
            esi = eax[0x1];
            temp_3 = 0x3;
    }
    else {
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            if (*(esi[0x5] + 0x28) > arg_24) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    *(esi[0x5] + 0x28) = arg_24;
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            if (*(esi[0x5] + 0x2c) < arg_24) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    *(esi[0x5] + 0x2c) = arg_24;
            }
            sub_40e680();
            arg_24 = arg_24 + 0x1;
            esi = arg_34;
            ebx = arg_30;
            temp_3 = 0x4;
    }
    continue;
    edi = arg_34[0x1];
    esi = edi;
    if (edi[0x19] == 0x0) {
            do {
                    sub_40fb70(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x19] == 0x0);
    }
    arg_34[0x1] = arg_34;
    arg_38 = 0x0;
    *arg_34 = arg_34;
    arg_34[0x2] = arg_34;
    edi = **dword_bbf60c;
    esi = 0xbbf608;
    arg_4c = 0xbbf608;
    arg_50 = **dword_bbf60c;
    goto loc_425341;

.l9:
    if (temp_2 != 0x0) {
            sub_40e680();
            edi = arg_44;
            ebx = arg_30;
            temp_3 = 0x26;
            continue;
    }
    edi = arg_44;
    if (esi == arg_30[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    ebx = esi[0x5];
    ebx = ebx + 0xc;
    if (edi == 0x0) {
            sub_47a948();
    }
    eax = arg_48;
    if (eax == edi[0x1]) {
            sub_47a948();
            eax = arg_48;
    }
    if (eax[0x4] == 0x0) {
            sub_47a948();
            eax = arg_48;
    }
    if (eax[0x5] == *(eax[0x4] + 0x4)) {
            sub_47a948();
            eax = arg_48;
    }
    edx = eax[0x5];
    eax = *dword_62cc64;
    if (*(ebx + eax * 0x4 + 0x140) == *(edx + eax * 0x4 + 0x14c)) {
            sub_40e680();
            edi = arg_44;
            ebx = arg_30;
            temp_3 = 0x26;
            continue;
    }
    ebx = arg_30;
    arg_2F = 0x1;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    if (esi[0x4] == 0x0) {
            sub_47a948();
    }
    if (esi[0x5] == *(esi[0x4] + 0x4)) {
            sub_47a948();
    }
    *(int8_t *)(esi[0x5] + 0x51) = arg_2F;
    if (arg_2F == 0x1) {
            arg_8 = ebx;
            esp = esp - 0xc;
            eax = sub_412540(&arg_68, arg_8, esi, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, arg_2c, arg_30, arg_34, arg_38, arg_3c, arg_40, arg_44, arg_48);
            ebx = *eax;
            esi = eax[0x1];
            temp_3 = 0x3;
    }
    else {
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            if (*(esi[0x5] + 0x28) > arg_24) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    *(esi[0x5] + 0x28) = arg_24;
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            if (*(esi[0x5] + 0x2c) < arg_24) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    *(esi[0x5] + 0x2c) = arg_24;
            }
            sub_40e680();
            arg_24 = arg_24 + 0x1;
            esi = arg_34;
            ebx = arg_30;
            temp_3 = 0x4;
    }
    continue;

loc_425341:
    if (esi == 0x0 || esi != 0xbbf608) {
            sub_47a948();
    }
    if (edi != *dword_bbf60c) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi[0x7] == arg_0) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    arg_0 = &arg_98;
                    arg_60 = edi[0x9] + arg_5C;
                    arg_68 = edi;
                    sub_419fa0(arg_0, &arg_60, arg_8);
            }
            sub_40f260();
            edi = arg_50;
            esi = arg_4c;
            continue;
    }
    break;
    arg_1c = 0x0;
    arg_48 = 0x0;
    eax = arg_34;
    ebx = *eax;
    esi = &arg_30;
    arg_28 = esi;
    arg_2c = ebx;
    &arg_8 = &arg_8;
    goto loc_4253e0;

loc_4253e0:
    edi = arg_34;
    if (esi == 0x0 || esi != &arg_30) {
            eax = sub_47a948();
    }
    if (ebx != edi) {
            arg_1c = arg_1c + 0x1;
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (ebx == esi[0x1]) {
                    sub_47a948();
            }
            if (ebx[0x4] == 0x0) {
                    sub_47a948();
            }
            if (ebx[0x5] == *(ebx[0x4] + 0x4)) {
                    sub_47a948();
            }
            if (*(ebx[0x5] + 0x54) > 0x0) {
                    if (ebx == esi[0x1]) {
                            sub_47a948();
                    }
                    if (ebx[0x4] == 0x0) {
                            sub_47a948();
                    }
                    edx = ebx[0x4];
                    eax = ebx[0x5];
                    if (eax == edx[0x1]) {
                            eax = sub_47a948();
                    }
                    if (*(int8_t *)(ebx[0x5] + 0x50) == 0x0) {
                            asm { fld        dword [byte_4c6bdc+4] };
                            asm { fcomp      qword [dword_value_1119092736+8] };
                            asm { fnstsw     ax };
                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                    arg_48 = arg_48 + 0x1;
                            }
                    }
            }
            if (ebx == esi[0x1]) {
                    sub_47a948();
            }
            if (ebx[0x4] == 0x0) {
                    sub_47a948();
            }
            edx = ebx[0x4];
            eax = ebx[0x5];
            if (eax == edx[0x1]) {
                    eax = sub_47a948();
            }
            if (*(int8_t *)(ebx[0x5] + 0x50) != 0x0) {
                    eax = sub_40e680();
                    ebx = arg_2c;
                    esi = arg_28;
                    continue;
            }
            if (ebx == esi[0x1]) {
                    eax = sub_47a948();
            }
            edi = ebx[0x4];
            esi = ebx[0x5];
            if (edi == 0x0) {
                    eax = sub_47a948();
            }
            if (esi == edi[0x1]) {
                    eax = sub_47a948();
            }
            asm { fld        dword [esi+0x30] };
            asm { fild       dword [esp-0x10+arg_54] };
            asm { fcompp };
            asm { fnstsw     ax };
            if ((HIBYTE(eax) & 0x41) == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x51] == 0x1) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            asm { fldz };
                            asm { fstp       dword [esi+0x58] };
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            asm { fldz };
                            asm { fstp       dword [esi+0x1c4] };
                    }
                    if (*dword_62cc64 < 0x1) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            asm { fld        dword [esi+0x58] };
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                            }
                            asm { fld        dword [esp-0x10+arg_58] };
                            asm { fld        st0 };
                            asm { fld1 };
                            asm { fsubrp     st1 };
                            asm { fmul       dword [esi+0x58] };
                            asm { fld        dword [esi+0x1c4] };
                            asm { fmulp      st2 };
                            asm { faddp      st1 };
                    }
                    bool_179 = esi != edi[0x1];
                    asm { fstp       dword [esp-0x18+arg_28] };
                    if (!bool_179) {
                            sub_47a948();
                    }
                    asm { fld        dword [esp-0x18+arg_28] };
                    asm { fstp       dword [esi+0x1c4] };
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0xa] > arg_24) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi[0xa] = arg_24;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0xb] < arg_24) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi[0xb] = arg_24;
                    }
                    eax = sub_40e680();
                    ebx = arg_2c;
                    esi = arg_28;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0xa] < 0x6) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x51] == 0x1) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            asm { fldz };
                            asm { fstp       dword [esi+0x58] };
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            asm { fldz };
                            asm { fstp       dword [esi+0x1c4] };
                    }
                    if (*dword_62cc64 < 0x1) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            asm { fld        dword [esi+0x58] };
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                            }
                            asm { fld        dword [esp-0x10+arg_58] };
                            asm { fld        st0 };
                            asm { fld1 };
                            asm { fsubrp     st1 };
                            asm { fmul       dword [esi+0x58] };
                            asm { fld        dword [esi+0x1c4] };
                            asm { fmulp      st2 };
                            asm { faddp      st1 };
                    }
                    bool_154 = esi != edi[0x1];
                    asm { fstp       dword [esp-0x18+arg_28] };
                    if (!bool_154) {
                            sub_47a948();
                    }
                    asm { fld        dword [esp-0x18+arg_28] };
                    asm { fstp       dword [esi+0x1c4] };
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0xa] > arg_24) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi[0xa] = arg_24;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0xb] < arg_24) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi[0xb] = arg_24;
                    }
                    eax = sub_40e680();
                    ebx = arg_2c;
                    esi = arg_28;
                    continue;
            }
            if (arg_1c < 0xa) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x51] == 0x1) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            asm { fldz };
                            asm { fstp       dword [esi+0x58] };
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            asm { fldz };
                            asm { fstp       dword [esi+0x1c4] };
                    }
                    if (*dword_62cc64 < 0x1) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            asm { fld        dword [esi+0x58] };
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                            }
                            asm { fld        dword [esp-0x10+arg_58] };
                            asm { fld        st0 };
                            asm { fld1 };
                            asm { fsubrp     st1 };
                            asm { fmul       dword [esi+0x58] };
                            asm { fld        dword [esi+0x1c4] };
                            asm { fmulp      st2 };
                            asm { faddp      st1 };
                    }
                    bool_152 = esi != edi[0x1];
                    asm { fstp       dword [esp-0x18+arg_28] };
                    if (!bool_152) {
                            sub_47a948();
                    }
                    asm { fld        dword [esp-0x18+arg_28] };
                    asm { fstp       dword [esi+0x1c4] };
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0xa] > arg_24) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi[0xa] = arg_24;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0xb] < arg_24) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi[0xb] = arg_24;
                    }
                    eax = sub_40e680();
                    ebx = arg_2c;
                    esi = arg_28;
                    continue;
            }
            if (ebx == arg_28[0x1]) {
                    sub_47a948();
            }
            if (ebx[0x4] == 0x0) {
                    sub_47a948();
            }
            if (ebx[0x5] == *(ebx[0x4] + 0x4)) {
                    sub_47a948();
            }
            if (*(ebx[0x5] + 0x54) == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x50] != 0x0) {
                            eax = sub_40e680();
                            ebx = arg_2c;
                            esi = arg_28;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0xa] > arg_1c) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi[0xa] = arg_1c;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0xb] < arg_1c) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi[0xb] = arg_1c;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x50] = 0x1;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    asm { fldz };
                    asm { fstp       dword [esi+0x58] };
                    if (esi == edi[0x1]) {
                            sub_47a948();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                    }
                    esi[0x9] = 0xfff0bdc0 - esi[0xa];
                    if (esi == edi[0x1]) {
                            sub_47a948();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                    }
                    asm { fild       dword [esp-0x10+arg_5C] };
                    asm { fstp       dword [esi+0x1c4] };
                    *dword_62d34c = *dword_62d34c + 0x1;
                    eax = sub_40e680();
                    ebx = arg_2c;
                    esi = arg_28;
                    continue;
            }
            if (arg_48 >= 0xa) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x50] != 0x0) {
                            eax = sub_40e680();
                            ebx = arg_2c;
                            esi = arg_28;
                            continue;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0xa] > arg_1c) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi[0xa] = arg_1c;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0xb] < arg_1c) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi[0xb] = arg_1c;
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x50] = 0x1;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    asm { fldz };
                    asm { fstp       dword [esi+0x58] };
                    if (esi == edi[0x1]) {
                            sub_47a948();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                    }
                    esi[0x9] = 0xfff0bdc0 - esi[0xa];
                    if (esi == edi[0x1]) {
                            sub_47a948();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                    }
                    asm { fild       dword [esp-0x10+arg_5C] };
                    asm { fstp       dword [esi+0x1c4] };
                    *dword_62d34c = *dword_62d34c + 0x1;
                    eax = sub_40e680();
                    ebx = arg_2c;
                    esi = arg_28;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x51] == 0x1) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    asm { fldz };
                    asm { fstp       dword [esi+0x58] };
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    asm { fldz };
                    asm { fstp       dword [esi+0x1c4] };
            }
            if (*dword_62cc64 < 0x1) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    asm { fld        dword [esi+0x58] };
            }
            else {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                    }
                    asm { fld        dword [esp-0x10+arg_58] };
                    asm { fld        st0 };
                    asm { fld1 };
                    asm { fsubrp     st1 };
                    asm { fmul       dword [esi+0x58] };
                    asm { fld        dword [esi+0x1c4] };
                    asm { fmulp      st2 };
                    asm { faddp      st1 };
            }
            bool_136 = esi != edi[0x1];
            asm { fstp       dword [esp-0x18+arg_28] };
            if (!bool_136) {
                    sub_47a948();
            }
            asm { fld        dword [esp-0x18+arg_28] };
            asm { fstp       dword [esi+0x1c4] };
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0xa] > arg_24) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0xa] = arg_24;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0xb] < arg_24) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0xb] = arg_24;
            }
            eax = sub_40e680();
            ebx = arg_2c;
            esi = arg_28;
            continue;
    }
    break;
    ecx = arg_34;
    asm { fldz };
    esi = *ecx;
    asm { fstp       dword [esp-0x10+arg_1C] };
    edi = &arg_30;
    arg_28 = edi;
    arg_2c = esi;
    goto loc_425728;

loc_425728:
    ebx = arg_34;
    if (edi == 0x0 || edi != &arg_30) {
            eax = sub_47a948();
    }
    if (esi != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            if (*(int8_t *)(esi[0x5] + 0x50) == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    asm { fld        dword [edx+0x1c4] };
                    asm { fadd       dword [esp-0x10+arg_1C] };
                    asm { fstp       dword [esp-0x10+arg_1C] };
            }
            eax = sub_40e680();
            esi = arg_2c;
            edi = arg_28;
            continue;
    }
    break;
    asm { fld        dword [esp-0x10+arg_1C] };
    asm { fsubr      qword [qword_value_4636737291354636288] };
    asm { fstp       dword [esp-0x10+arg_1C] };
    asm { fld        dword [dword_value_1119092736] };
    asm { fcom       dword [esp-0x10+arg_1C] };
    asm { fnstsw     ax };
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            asm { fstp       dword [esp-0x10+arg_1C] };
    }
    else {
            asm { fstp       st0 };
    }
    esi = *arg_3c;
    edi = &arg_38;
    arg_30 = edi;
    arg_34 = esi;
    goto loc_425801;

loc_425801:
    ebx = arg_3c;
    if (edi == 0x0 || edi != &arg_38) {
            sub_47a948();
    }
    if (esi != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x4] == 0x0) {
                    sub_47a948();
            }
            if (esi[0x5] == *(esi[0x4] + 0x4)) {
                    sub_47a948();
            }
            if (*(int8_t *)(esi[0x5] + 0x50) == 0x0) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    bool_538 = esi != edi[0x1];
                    asm { fld        dword [ecx+0x1c4] };
                    asm { fld        dword [esp-0x18+arg_24] };
                    asm { fld        st0 };
                    asm { fmulp      st2 };
                    asm { fsubr      qword [qword_value_4636737291354636288] };
                    asm { fdivp      st1 };
                    asm { fstp       dword [esp-0x18+arg_28] };
                    if (!bool_538) {
                            sub_47a948();
                    }
                    if (esi[0x4] == 0x0) {
                            sub_47a948();
                    }
                    if (esi[0x5] == *(esi[0x4] + 0x4)) {
                            sub_47a948();
                    }
                    esi = esi[0x5];
                    asm { fld        dword [esi+0x1c4] };
                    asm { fadd       dword [esp-0x18+arg_28] };
                    asm { fstp       dword [esi+0x1c4] };
            }
            sub_40e680();
            esi = arg_34;
            edi = arg_30;
            continue;
    }
    break;
    sub_465fa0();
    sub_414e10(&arg_68, &arg_38, *arg_3c, &arg_38, arg_3c);
    eax = sub_47c8f9();
    *0x0 = arg_C8;
    &arg_20 = ebp;
    return eax;
}
