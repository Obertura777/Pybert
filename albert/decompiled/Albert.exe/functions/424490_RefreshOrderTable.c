// RefreshOrderTable @ 0x424490
// hopper name: sub_424490
// pybert name: RefreshOrderTable
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

RefreshOrderTable() {
    var_8 = sub_4962b0;
    var_C = *0x0;
    decomp_var_60 = ebx;
    decomp_var_64 = ebp;
    decomp_var_68 = esi;
    decomp_var_6c = edi;
    decomp_var_70 = *dword_4c8db8 ^ &decomp_var_6c;
    *0x0 = &var_C;
    eax = sub_410330();
    var_30 = eax;
    eax[0x19] = 0x1;
    var_30[0x1] = var_30;
    *var_30 = var_30;
    var_30[0x2] = var_30;
    sub_465870();
    esp = esp - 0x74;
    sub_40fb70(var_30[0x1]);
    var_30[0x1] = var_30;
    var_2C = 0x0;
    *var_30 = var_30;
    var_30[0x2] = var_30;
    edi = **dword_bbf60c;
    esi = 0xbbf608;
    var_48 = 0xbbf608;
    var_44 = **dword_bbf60c;
    goto loc_424532;

loc_424532:
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
                    asm { fld        dword [edi+0x1c4] };
                    asm { fmul       qword [qword_value_4621819117588971520] };
                    asm { fstp       dword [esp+0x70+var_54] };
                    asm { fld        dword [esp+0x70+var_54] };
                    esp = esp - 0x8;
                    var_40 = sub_47b5c0();
                    var_3C = esi;
                    eax = sub_419fa0(&var_28, &var_40, decomp_var_70);
            }
            sub_40f260();
            edi = var_44;
            esi = var_48;
            continue;
    }
    break;
    var_54 = 0x0;
    var_4C = ((arg_0 << 0x4) - arg_0) + ((arg_0 << 0x4) - arg_0);
    goto loc_4245d6;

loc_4245d6:
    edx = var_30;
    asm { fldz };
    eax = *edx;
    asm { fstp       dword [esp+0x70+var_58] };
    var_48 = &var_34;
    edi = eax;
    if (eax == edx) goto .l4;
    goto loc_4245f4;

.l4:
    var_44 = &var_30;
    edi = *var_2C;
    esi = &var_30;
    goto loc_4247b9;

loc_4245f4:
    var_40 = var_48;
    var_3C = edi;
    sub_40e680();
    ebp = var_40;
    esi = var_30;
    if (ebp == 0x0 || ebp != &var_34) {
            sub_47a948();
    }
    ebx = var_3C;
    if (ebx != esi) {
            esi = var_48;
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi[0x3] > 0x0) {
                    if (ebp == 0x0) {
                            sub_47a948();
                    }
                    if (ebx == arg_0) {
                            sub_47a948();
                    }
                    if (ebx[0x3] > 0x0) {
                            if (edi == esi[0x1]) {
                                    sub_47a948();
                            }
                            var_5C = 0x3e8 - edi[0x3];
                            asm { fild       dword [esp+0x70+var_5C] };
                            asm { fsub       dword [esp+0x70+var_58] };
                    }
                    else {
                            asm { fldz };
                    }
            }
            else {
                    asm { fldz };
            }
            asm { fstp       dword [esp+0x6c+var_58] };
            ecx = sub_47b678();
            eax = ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x3 + 0x2;
            if (eax > 0x1) {
                    esi = eax - 0x1;
                    do {
                            ecx = sub_47b678();
                            eax = ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) / 0x3e8;
                            esi = esi - 0x1;
                            var_4C = ((SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4) >> 0x1f) + (SAR(HIDWORD(0xb21642c9 * ecx) + ecx, 0x4))) % 0x3e8;
                    } while (esi != 0x0);
                    esi = var_44;
            }
            asm { fild       dword [esp+0x6c+var_4C] };
            asm { fld        dword [esp+0x6c+var_58] };
            asm { fcompp };
            asm { fnstsw     ax };
            if (PARITY(HIBYTE(eax) & 0x41)) {
                    if (var_50 != 0x0) {
                            if (edi == esi[0x1]) {
                                    sub_47a948();
                            }
                            asm { fild       dword [edi+0xc] };
                            var_44 = ebp;
                            edi = ebx;
                            asm { fadd       dword [esp+0x6c+var_54] };
                            asm { fstp       dword [esp+0x6c+var_54] };
                            continue;
                    }
                    esi = arg_4;
                    if (*(int8_t *)byte_baed6c == 0x1) {
                            if (*byte_624124 != esi) {
                                    if (ebp == 0x0) {
                                            sub_47a948();
                                    }
                                    if (ebx == arg_0) {
                                            sub_47a948();
                                    }
                                    if (ebx[0x3] >= 0x32) {
                                            if (*(esi * 0x4 + dword_623990) < 0x4) {
                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                            if (ebp == 0x0) {
                                                                    sub_47a948();
                                                            }
                                                            if (ebx == arg_0) {
                                                                    sub_47a948();
                                                            }
                                                            if (ebx[0x3] >= 0x32) {
                                                                    if (*(esi * 0x4 + dword_623990) >= 0x6) {
                                                                            esi = var_44;
                                                                            if (edi == esi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            asm { fild       dword [edi+0xc] };
                                                                            var_44 = ebp;
                                                                            edi = ebx;
                                                                            asm { fadd       dword [esp+0x6c+var_54] };
                                                                            asm { fstp       dword [esp+0x6c+var_54] };
                                                                            continue;
                                                                    }
                                                                    if (ebp == 0x0) {
                                                                            sub_47a948();
                                                                    }
                                                                    if (ebx == arg_0) {
                                                                            sub_47a948();
                                                                    }
                                                                    if (ebx[0x3] >= 0x14) {
                                                                            esi = var_44;
                                                                            if (edi == esi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            asm { fild       dword [edi+0xc] };
                                                                            var_44 = ebp;
                                                                            edi = ebx;
                                                                            asm { fadd       dword [esp+0x6c+var_54] };
                                                                            asm { fstp       dword [esp+0x6c+var_54] };
                                                                            continue;
                                                                    }
                                                                    temp_6 = 0x0;
                                                                    break;
                                                            }
                                                            else {
                                                                    temp_6 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (*(esi * 0x4 + dword_623990) >= 0x6) {
                                                                    esi = var_44;
                                                                    if (edi == esi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    asm { fild       dword [edi+0xc] };
                                                                    var_44 = ebp;
                                                                    edi = ebx;
                                                                    asm { fadd       dword [esp+0x6c+var_54] };
                                                                    asm { fstp       dword [esp+0x6c+var_54] };
                                                                    continue;
                                                            }
                                                            if (ebp == 0x0) {
                                                                    sub_47a948();
                                                            }
                                                            if (ebx == arg_0) {
                                                                    sub_47a948();
                                                            }
                                                            if (ebx[0x3] >= 0x14) {
                                                                    esi = var_44;
                                                                    if (edi == esi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    asm { fild       dword [edi+0xc] };
                                                                    var_44 = ebp;
                                                                    edi = ebx;
                                                                    asm { fadd       dword [esp+0x6c+var_54] };
                                                                    asm { fstp       dword [esp+0x6c+var_54] };
                                                                    continue;
                                                            }
                                                            temp_6 = 0x0;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (*(esi * 0x4 + dword_623990) >= 0x6) {
                                                            esi = var_44;
                                                            if (edi == esi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            asm { fild       dword [edi+0xc] };
                                                            var_44 = ebp;
                                                            edi = ebx;
                                                            asm { fadd       dword [esp+0x6c+var_54] };
                                                            asm { fstp       dword [esp+0x6c+var_54] };
                                                            continue;
                                                    }
                                                    if (ebp == 0x0) {
                                                            sub_47a948();
                                                    }
                                                    if (ebx == arg_0) {
                                                            sub_47a948();
                                                    }
                                                    if (ebx[0x3] >= 0x14) {
                                                            esi = var_44;
                                                            if (edi == esi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            asm { fild       dword [edi+0xc] };
                                                            var_44 = ebp;
                                                            edi = ebx;
                                                            asm { fadd       dword [esp+0x6c+var_54] };
                                                            asm { fstp       dword [esp+0x6c+var_54] };
                                                            continue;
                                                    }
                                                    temp_6 = 0x0;
                                                    break;
                                            }
                                    }
                                    else {
                                            temp_6 = 0x2;
                                            break;
                                    }
                            }
                            else {
                                    if (*(esi * 0x4 + dword_623990) < 0x4) {
                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                    if (ebp == 0x0) {
                                                            sub_47a948();
                                                    }
                                                    if (ebx == arg_0) {
                                                            sub_47a948();
                                                    }
                                                    if (ebx[0x3] >= 0x32) {
                                                            if (*(esi * 0x4 + dword_623990) >= 0x6) {
                                                                    esi = var_44;
                                                                    if (edi == esi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    asm { fild       dword [edi+0xc] };
                                                                    var_44 = ebp;
                                                                    edi = ebx;
                                                                    asm { fadd       dword [esp+0x6c+var_54] };
                                                                    asm { fstp       dword [esp+0x6c+var_54] };
                                                                    continue;
                                                            }
                                                            if (ebp == 0x0) {
                                                                    sub_47a948();
                                                            }
                                                            if (ebx == arg_0) {
                                                                    sub_47a948();
                                                            }
                                                            if (ebx[0x3] >= 0x14) {
                                                                    esi = var_44;
                                                                    if (edi == esi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    asm { fild       dword [edi+0xc] };
                                                                    var_44 = ebp;
                                                                    edi = ebx;
                                                                    asm { fadd       dword [esp+0x6c+var_54] };
                                                                    asm { fstp       dword [esp+0x6c+var_54] };
                                                                    continue;
                                                            }
                                                            temp_6 = 0x0;
                                                            break;
                                                    }
                                                    else {
                                                            temp_6 = 0x1;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (*(esi * 0x4 + dword_623990) >= 0x6) {
                                                            esi = var_44;
                                                            if (edi == esi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            asm { fild       dword [edi+0xc] };
                                                            var_44 = ebp;
                                                            edi = ebx;
                                                            asm { fadd       dword [esp+0x6c+var_54] };
                                                            asm { fstp       dword [esp+0x6c+var_54] };
                                                            continue;
                                                    }
                                                    if (ebp == 0x0) {
                                                            sub_47a948();
                                                    }
                                                    if (ebx == arg_0) {
                                                            sub_47a948();
                                                    }
                                                    if (ebx[0x3] >= 0x14) {
                                                            esi = var_44;
                                                            if (edi == esi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            asm { fild       dword [edi+0xc] };
                                                            var_44 = ebp;
                                                            edi = ebx;
                                                            asm { fadd       dword [esp+0x6c+var_54] };
                                                            asm { fstp       dword [esp+0x6c+var_54] };
                                                            continue;
                                                    }
                                                    temp_6 = 0x0;
                                                    break;
                                            }
                                    }
                                    else {
                                            if (*(esi * 0x4 + dword_623990) >= 0x6) {
                                                    esi = var_44;
                                                    if (edi == esi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    asm { fild       dword [edi+0xc] };
                                                    var_44 = ebp;
                                                    edi = ebx;
                                                    asm { fadd       dword [esp+0x6c+var_54] };
                                                    asm { fstp       dword [esp+0x6c+var_54] };
                                                    continue;
                                            }
                                            if (ebp == 0x0) {
                                                    sub_47a948();
                                            }
                                            if (ebx == arg_0) {
                                                    sub_47a948();
                                            }
                                            if (ebx[0x3] >= 0x14) {
                                                    esi = var_44;
                                                    if (edi == esi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    asm { fild       dword [edi+0xc] };
                                                    var_44 = ebp;
                                                    edi = ebx;
                                                    asm { fadd       dword [esp+0x6c+var_54] };
                                                    asm { fstp       dword [esp+0x6c+var_54] };
                                                    continue;
                                            }
                                            temp_6 = 0x0;
                                            break;
                                    }
                            }
                    }
                    else {
                            if (*(esi * 0x4 + dword_623990) < 0x4) {
                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                            if (ebp == 0x0) {
                                                    sub_47a948();
                                            }
                                            if (ebx == arg_0) {
                                                    sub_47a948();
                                            }
                                            if (ebx[0x3] >= 0x32) {
                                                    if (*(esi * 0x4 + dword_623990) >= 0x6) {
                                                            esi = var_44;
                                                            if (edi == esi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            asm { fild       dword [edi+0xc] };
                                                            var_44 = ebp;
                                                            edi = ebx;
                                                            asm { fadd       dword [esp+0x6c+var_54] };
                                                            asm { fstp       dword [esp+0x6c+var_54] };
                                                            continue;
                                                    }
                                                    if (ebp == 0x0) {
                                                            sub_47a948();
                                                    }
                                                    if (ebx == arg_0) {
                                                            sub_47a948();
                                                    }
                                                    if (ebx[0x3] >= 0x14) {
                                                            esi = var_44;
                                                            if (edi == esi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            asm { fild       dword [edi+0xc] };
                                                            var_44 = ebp;
                                                            edi = ebx;
                                                            asm { fadd       dword [esp+0x6c+var_54] };
                                                            asm { fstp       dword [esp+0x6c+var_54] };
                                                            continue;
                                                    }
                                                    temp_6 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    temp_6 = 0x1;
                                                    break;
                                            }
                                    }
                                    else {
                                            if (*(esi * 0x4 + dword_623990) >= 0x6) {
                                                    esi = var_44;
                                                    if (edi == esi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    asm { fild       dword [edi+0xc] };
                                                    var_44 = ebp;
                                                    edi = ebx;
                                                    asm { fadd       dword [esp+0x6c+var_54] };
                                                    asm { fstp       dword [esp+0x6c+var_54] };
                                                    continue;
                                            }
                                            if (ebp == 0x0) {
                                                    sub_47a948();
                                            }
                                            if (ebx == arg_0) {
                                                    sub_47a948();
                                            }
                                            if (ebx[0x3] >= 0x14) {
                                                    esi = var_44;
                                                    if (edi == esi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    asm { fild       dword [edi+0xc] };
                                                    var_44 = ebp;
                                                    edi = ebx;
                                                    asm { fadd       dword [esp+0x6c+var_54] };
                                                    asm { fstp       dword [esp+0x6c+var_54] };
                                                    continue;
                                            }
                                            temp_6 = 0x0;
                                            break;
                                    }
                            }
                            else {
                                    if (*(esi * 0x4 + dword_623990) >= 0x6) {
                                            esi = var_44;
                                            if (edi == esi[0x1]) {
                                                    sub_47a948();
                                            }
                                            asm { fild       dword [edi+0xc] };
                                            var_44 = ebp;
                                            edi = ebx;
                                            asm { fadd       dword [esp+0x6c+var_54] };
                                            asm { fstp       dword [esp+0x6c+var_54] };
                                            continue;
                                    }
                                    if (ebp == 0x0) {
                                            sub_47a948();
                                    }
                                    if (ebx == arg_0) {
                                            sub_47a948();
                                    }
                                    if (ebx[0x3] >= 0x14) {
                                            esi = var_44;
                                            if (edi == esi[0x1]) {
                                                    sub_47a948();
                                            }
                                            asm { fild       dword [edi+0xc] };
                                            var_44 = ebp;
                                            edi = ebx;
                                            asm { fadd       dword [esp+0x6c+var_54] };
                                            asm { fstp       dword [esp+0x6c+var_54] };
                                            continue;
                                    }
                                    temp_6 = 0x0;
                                    break;
                            }
                    }
            }
            else {
                    temp_6 = 0x4;
                    break;
            }
    }
    else {
            temp_6 = 0x3;
            break;
    }
    goto .l2;

loc_4247b9:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    bool_8 = var_50 < 0x1d;
    *((var_48 + var_50) * 0x8 + 0xbbf690) = edi[0x4];
    *((var_48 + var_50) * 0x8 + 0xbbf694) = edi[0x5];
    var_50 = var_50 + 0x1;
    if (bool_8) {
            continue;
    }
    break;

.l2:
    switch (temp_6) {
        case 0:
            var_44 = &var_30;
            edi = *var_2C;
            esi = &var_30;
            break;
        case 1:
            var_44 = &var_30;
            edi = *var_2C;
            esi = &var_30;
            break;
        case 2:
            var_44 = &var_30;
            edi = *var_2C;
            esi = &var_30;
            break;
        case 3:
            var_44 = &var_30;
            edi = *var_2C;
            esi = &var_30;
            break;
    }
    goto loc_4247b9;
    sub_465fa0();
    sub_414e10(&var_3C, &var_30, *var_2C, &var_30, var_2C);
    eax = sub_47c8f9();
    *0x0 = var_8;
    return eax;
}
