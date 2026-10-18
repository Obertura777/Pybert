// EvaluateProvinceScore @ 0x433ce0
// hopper name: sub_433ce0
// pybert name: EvaluateProvinceScore
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_84a29276878deed2f6f82f4902efd1af3068bd2f0c5f74171e6c8513865ea0d2
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

EvaluateProvinceScore() {
    decomp_var_48 = ebp;
    edx = *(ecx + (arg_0 + arg_0 * 0x2) * 0x4 + 0x2a20);
    eax = ecx + (arg_0 + arg_0 * 0x2) * 0x4 + 0x2a1c;
    decomp_var_4c = esi;
    esi = *edx;
    ebx = eax;
    esp = esp - 0x50;
    decomp_var_50 = edi;
    var_40 = ecx;
    var_38 = 0x0;
    var_34 = 0x0;
    var_24 = 0x0;
    var_3C = eax;
    var_30 = ebx;
    var_2C = esi;
    goto loc_433d21;

loc_433d21:
    edi = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            eax = sub_47a948();
    }
    if (esi != edi) {
            edi = arg_4 + 0x2450;
            var_1C = arg_4[0x915];
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            esi = esi + 0xc;
            esp = esp - 0x8;
            eax = sub_402060(&var_10, esi, decomp_var_50, decomp_var_4c, decomp_var_48);
            ebx = eax;
            eax = *ebx;
            if (eax == 0x0 || eax != edi) {
                    sub_47a948();
            }
            if (ebx[0x1] == var_1C) {
                    sub_401520();
                    esi = var_2C;
                    eax = var_3C;
                    ebx = var_30;
                    continue;
            }
            if (var_2C == var_30[0x1]) {
                    sub_47a948();
            }
            eax = *esi;
            edi = arg_4 << 0x8;
            eax = eax + edi;
            if (*(eax * 0x8 + 0x4f6ce8) != 0x1) {
                    if (var_2C == var_30[0x1]) {
                            sub_47a948();
                    }
                    eax = *esi;
                    eax = eax + edi;
                    if (*(eax * 0x8 + 0x50bce8) != 0x1) {
                            sub_401520();
                            esi = var_2C;
                            eax = var_3C;
                            ebx = var_30;
                            continue;
                    }
                    if (*(eax * 0x8 + 0x50bcec) != 0x0) {
                            sub_401520();
                            esi = var_2C;
                            eax = var_3C;
                            ebx = var_30;
                            continue;
                    }
                    if (var_2C == var_30[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_402060(&var_8, esi, decomp_var_50, decomp_var_4c, decomp_var_48);
                    ebx = *eax;
                    edi = eax[0x1];
                    var_18 = ebx;
                    if (ebx == 0x0) {
                            sub_47a948();
                    }
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    eax = *(edi[0x6] * 0x4 + dword_623990);
                    bool_176 = (eax & 0x80000000 ? 0xffffffff : 0x0) > var_34;
                    if ((eax & 0x80000000 ? 0xffffffff : 0x0) < var_34) {
                            sub_401520();
                            esi = var_2C;
                            eax = var_3C;
                            ebx = var_30;
                            continue;
                    }
                    if (!bool_176) {
                            if (eax <= var_38) {
                                    sub_401520();
                                    esi = var_2C;
                                    eax = var_3C;
                                    ebx = var_30;
                                    continue;
                            }
                            if (edi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (edi[0x6] != arg_4) {
                                    if (edi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (var_2C == var_30[0x1]) {
                                            sub_47a948();
                                    }
                                    ebx = *(sub_4075b0(edi + 0x14, decomp_var_50) + 0x4);
                                    esp = esp - 0x8;
                                    var_28 = arg_0;
                                    var_24 = 0x0;
                                    eax = sub_40fab0(&var_28);
                                    if (eax != ebx && arg_8 == arg_0) {
                                            if (edi == var_18[0x1]) {
                                                    sub_47a948();
                                            }
                                            eax = edi[0x6];
                                            eax = *(eax * 0x4 + dword_623990);
                                            var_38 = eax;
                                            var_34 = eax & 0x80000000 ? 0xffffffff : 0x0;
                                    }
                            }
                            sub_401520();
                            esi = var_2C;
                            eax = var_3C;
                            ebx = var_30;
                            continue;
                    }
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (edi[0x6] == arg_4) {
                            sub_401520();
                            esi = var_2C;
                            eax = var_3C;
                            ebx = var_30;
                            continue;
                    }
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (var_2C == var_30[0x1]) {
                            sub_47a948();
                    }
                    ebx = *(sub_4075b0(edi + 0x14, decomp_var_50) + 0x4);
                    esp = esp - 0x8;
                    var_28 = arg_0;
                    var_24 = 0x0;
                    eax = sub_40fab0(&var_28);
                    if (eax != ebx && arg_8 == arg_0) {
                            if (edi == var_18[0x1]) {
                                    sub_47a948();
                            }
                            eax = edi[0x6];
                            eax = *(eax * 0x4 + dword_623990);
                            var_38 = eax;
                            var_34 = eax & 0x80000000 ? 0xffffffff : 0x0;
                    }
                    sub_401520();
                    esi = var_2C;
                    eax = var_3C;
                    ebx = var_30;
                    continue;
            }
            if (*(eax * 0x8 + 0x4f6cec) != 0x0) {
                    if (var_2C == var_30[0x1]) {
                            sub_47a948();
                    }
                    eax = *esi;
                    eax = eax + edi;
                    if (*(eax * 0x8 + 0x50bce8) != 0x1) {
                            sub_401520();
                            esi = var_2C;
                            eax = var_3C;
                            ebx = var_30;
                            continue;
                    }
                    if (*(eax * 0x8 + 0x50bcec) != 0x0) {
                            sub_401520();
                            esi = var_2C;
                            eax = var_3C;
                            ebx = var_30;
                            continue;
                    }
                    if (var_2C == var_30[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_402060(&var_8, esi, decomp_var_50, decomp_var_4c, decomp_var_48);
                    ebx = *eax;
                    edi = eax[0x1];
                    var_18 = ebx;
                    if (ebx == 0x0) {
                            sub_47a948();
                    }
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    eax = *(edi[0x6] * 0x4 + dword_623990);
                    bool_240 = edx > var_34;
                    if ((eax & 0x80000000 ? 0xffffffff : 0x0) < var_34) {
                            sub_401520();
                            esi = var_2C;
                            eax = var_3C;
                            ebx = var_30;
                            continue;
                    }
                    if (!bool_240) {
                            if (eax <= var_38) {
                                    sub_401520();
                                    esi = var_2C;
                                    eax = var_3C;
                                    ebx = var_30;
                                    continue;
                            }
                            if (edi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (edi[0x6] != arg_4) {
                                    if (edi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (var_2C == var_30[0x1]) {
                                            sub_47a948();
                                    }
                                    ebx = *(sub_4075b0(edi + 0x14, decomp_var_50) + 0x4);
                                    esp = esp - 0x8;
                                    var_28 = arg_0;
                                    var_24 = 0x0;
                                    eax = sub_40fab0(&var_28);
                                    if (eax != ebx && arg_8 == arg_0) {
                                            if (edi == var_18[0x1]) {
                                                    sub_47a948();
                                            }
                                            eax = edi[0x6];
                                            eax = *(eax * 0x4 + dword_623990);
                                            var_38 = eax;
                                            var_34 = eax & 0x80000000 ? 0xffffffff : 0x0;
                                    }
                            }
                            sub_401520();
                            esi = var_2C;
                            eax = var_3C;
                            ebx = var_30;
                            continue;
                    }
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (edi[0x6] == arg_4) {
                            sub_401520();
                            esi = var_2C;
                            eax = var_3C;
                            ebx = var_30;
                            continue;
                    }
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (var_2C == var_30[0x1]) {
                            sub_47a948();
                    }
                    ebx = *(sub_4075b0(edi + 0x14, decomp_var_50) + 0x4);
                    esp = esp - 0x8;
                    var_28 = arg_0;
                    var_24 = 0x0;
                    eax = sub_40fab0(&var_28);
                    if (eax == ebx) {
                            sub_401520();
                            esi = var_2C;
                            eax = var_3C;
                            ebx = var_30;
                            continue;
                    }
                    if (arg_8 == arg_0) {
                            if (edi == var_18[0x1]) {
                                    sub_47a948();
                            }
                            eax = edi[0x6];
                            eax = *(eax * 0x4 + dword_623990);
                            var_38 = eax;
                            var_34 = eax & 0x80000000 ? 0xffffffff : 0x0;
                    }
                    sub_401520();
                    esi = var_2C;
                    eax = var_3C;
                    ebx = var_30;
                    continue;
            }
            if (var_2C == var_30[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_402060(&var_8, esi, decomp_var_50, decomp_var_4c, decomp_var_48);
            ebx = *eax;
            edi = eax[0x1];
            var_18 = ebx;
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = *(edi[0x6] * 0x4 + dword_623990);
            bool_165 = (eax & 0x80000000 ? 0xffffffff : 0x0) > var_34;
            if ((eax & 0x80000000 ? 0xffffffff : 0x0) < var_34) {
                    sub_401520();
                    esi = var_2C;
                    eax = var_3C;
                    ebx = var_30;
                    continue;
            }
            if (!bool_165) {
                    if (eax <= var_38) {
                            sub_401520();
                            esi = var_2C;
                            eax = var_3C;
                            ebx = var_30;
                            continue;
                    }
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (edi[0x6] == arg_4) {
                            sub_401520();
                            esi = var_2C;
                            eax = var_3C;
                            ebx = var_30;
                            continue;
                    }
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (var_2C == var_30[0x1]) {
                            sub_47a948();
                    }
                    ebx = *(sub_4075b0(edi + 0x14, decomp_var_50) + 0x4);
                    esp = esp - 0x8;
                    var_28 = arg_0;
                    var_24 = 0x0;
                    eax = sub_40fab0(&var_28);
                    if (eax == ebx) {
                            sub_401520();
                            esi = var_2C;
                            eax = var_3C;
                            ebx = var_30;
                            continue;
                    }
                    if (arg_8 == arg_0) {
                            if (edi == var_18[0x1]) {
                                    sub_47a948();
                            }
                            eax = edi[0x6];
                            eax = *(eax * 0x4 + dword_623990);
                            var_38 = eax;
                            var_34 = eax & 0x80000000 ? 0xffffffff : 0x0;
                    }
                    sub_401520();
                    esi = var_2C;
                    eax = var_3C;
                    ebx = var_30;
                    continue;
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi[0x6] != arg_4) {
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (var_2C == var_30[0x1]) {
                            sub_47a948();
                    }
                    ebx = *(sub_4075b0(edi + 0x14, decomp_var_50) + 0x4);
                    esp = esp - 0x8;
                    var_28 = arg_0;
                    var_24 = 0x0;
                    eax = sub_40fab0(&var_28);
                    if (eax != ebx && arg_8 == arg_0) {
                            if (edi == var_18[0x1]) {
                                    sub_47a948();
                            }
                            eax = edi[0x6];
                            eax = *(eax * 0x4 + dword_623990);
                            var_38 = eax;
                            var_34 = eax & 0x80000000 ? 0xffffffff : 0x0;
                    }
            }
            sub_401520();
            esi = var_2C;
            eax = var_3C;
            ebx = var_30;
            continue;
    }
    break;
    ecx = 0x0;
    edi = var_34;
    asm { fld        dword [byte_4c6bdc+4] };
    bool_28 = edi > ecx;
    if (edi < ecx) goto loc_433fe2;
    goto loc_433f2e;

loc_433fe2:
    ebp = arg_4;
    if ((var_30 | var_2C) != 0x0) goto .l13;
    goto loc_433ff0;

loc_433f2e:
    if (bool_28) goto loc_433f3a;
    goto loc_433f30;

.l13:
    if (*(int8_t *)byte_baed68 == 0x1) {
            asm { fcomp      dword [dword_value_1077936128] };
            asm { fnstsw     ax };
            if (!PARITY(HIBYTE(eax) & 0x5)) {
                    if ((var_28 | var_24) == 0x0) {
                            ecx = 0x0;
                            eax = (ebp << 0x8) + arg_10;
                            bool_12 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                            if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                    if (!bool_12 && *(eax * 0x8 + 0x57a8e8) <= ecx) {
                                            eax = var_28;
                                    }
                                    else {
                                            eax = 0x2;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    eax = var_28;
            }
    }
    else {
            asm { fstp       st0 };
            eax = var_28;
    }
    return eax;

loc_433ff0:
    ecx = 0x0;
    eax = (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8;
    bool_3 = eax[0x16143b] > 0x0;
    if (eax[0x16143b] < 0x0) goto .l13;
    goto loc_434007;

loc_433f3a:
    edx = arg_3ff8 & 0x80000000 ? 0xffffffff : 0x0;
    ebp = edx;
    eax = sub_47bb70(var_38, edi, 0x64, 0x0);
    esp = esp - 0x20;
    eax = sub_47bac0(eax, edx, arg_3ff8, ebp);
    bool_20 = edx > 0x0;
    if (edx < 0x0) goto .l73;
    goto loc_433f60;

loc_433f30:
    ecx = 0x0;
    if (var_38 <= 0x0) goto .l28;
    goto .l19;

loc_434007:
    if (bool_3) goto .l34;
    goto loc_434009;

.l73:
    ebp = arg_4;
    var_38 = 0x32;
    var_34 = 0x0;
    goto loc_434057;

loc_433f60:
    if (bool_20) goto .l51;
    goto loc_433f62;

.l28:
    ebp = arg_4;
    if ((var_30 | var_2C) != 0x0) goto .l32;
    goto .l26;

.l19:
    edx = arg_3ff8 & 0x80000000 ? 0xffffffff : 0x0;
    ebp = edx;
    eax = sub_47bb70(var_38, edi, 0x64, 0x0);
    esp = esp - 0x20;
    eax = sub_47bac0(eax, edx, arg_3ff8, ebp);
    bool_41 = edx > 0x0;
    if (edx < 0x0) goto .l113;
    goto .l14;

.l34:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l36;
    goto .l35;

loc_434009:
    if (eax[0x16143a] <= ecx) goto .l13;
    goto loc_434011;

loc_434057:
    if (*(int8_t *)byte_baed68 == 0x1) {
            asm { fcomp      dword [dword_value_1077936128] };
            asm { fnstsw     ax };
            if (!PARITY(HIBYTE(eax) & 0x5)) {
                    if ((var_28 | var_24) == 0x0) {
                            eax = (ebp << 0x8) + arg_10;
                            bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                            if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                    if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                            eax = var_28;
                                    }
                                    else {
                                            eax = 0x2;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    eax = var_28;
            }
    }
    else {
            asm { fstp       st0 };
            eax = var_28;
    }
    return eax;

.l51:
    ebp = arg_4;
    ebx = *((ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + 0x52b4e8);
    edi = *((ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + 0x52b4ec);
    ecx = (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0;
    ebx = ebx + 0x1;
    bool_93 = edi + 0x0 + CARRY(EFLAGS(cf)) > ecx[0x163e3b];
    if (edi + 0x0 + CARRY(EFLAGS(cf)) < ecx[0x163e3b]) goto .l72;
    goto .l52;

loc_433f62:
    if (eax <= 0x32) goto loc_433fce;
    goto loc_433f66;

.l32:
    if (*(int8_t *)byte_baed68 == 0x1) {
            asm { fcomp      dword [dword_value_1077936128] };
            asm { fnstsw     ax };
            if (!PARITY(HIBYTE(eax) & 0x5)) {
                    if ((var_28 | var_24) == 0x0) {
                            eax = (ebp << 0x8) + arg_10;
                            bool_65 = *(eax * 0x8 + 0x57a8ec) > ecx;
                            if (*(eax * 0x8 + 0x57a8ec) >= ecx) {
                                    if (!bool_65 && *(eax * 0x8 + 0x57a8e8) <= ecx) {
                                            eax = var_28;
                                    }
                                    else {
                                            eax = 0x2;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    eax = var_28;
            }
    }
    else {
            asm { fstp       st0 };
            eax = var_28;
    }
    return eax;

.l26:
    eax = (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8;
    bool_60 = eax[0x16143b] > ecx;
    if (eax[0x16143b] < ecx) goto .l32;
    goto .l30;

.l113:
    ebp = arg_4;
    var_38 = 0x32;
    var_34 = 0x0;
    goto .l21;

.l14:
    if (bool_41) goto .l91;
    goto .l15;

.l36:
    goto .l13;

.l35:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    ecx = 0x0;
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_12 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_12 && *(eax * 0x8 + 0x57a8e8) <= ecx) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    ecx = 0x0;
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_12 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_12 && *(eax * 0x8 + 0x57a8e8) <= ecx) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

loc_434011:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto loc_434042;
    goto loc_43402d;

.l72:
    var_38 = 0x32;
    var_34 = 0x0;
    goto loc_434057;

.l52:
    if (bool_93) goto .l65;
    goto .l53;

loc_433fce:
    ebp = arg_4;
    var_38 = 0x32;
    var_34 = 0x0;
    goto loc_434057;

loc_433f66:
    ebp = arg_4;
    ebx = *((ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + 0x52b4e8);
    edi = *((ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + 0x52b4ec);
    ecx = (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0;
    ebx = ebx + 0x1;
    bool_15 = edi + 0x0 + CARRY(EFLAGS(cf)) < ecx[0x163e3b];
    bool_14 = edi + 0x0 + CARRY(EFLAGS(cf)) > ecx[0x163e3b];
    if (bool_15) goto .l50;
    goto loc_433f95;

.l30:
    if (bool_60) goto .l74;
    goto .l27;

.l21:
    if (*(int8_t *)byte_baed68 == 0x1) {
            asm { fcomp      dword [dword_value_1077936128] };
            asm { fnstsw     ax };
            if (!PARITY(HIBYTE(eax) & 0x5)) {
                    if ((var_28 | var_24) == 0x0) {
                            eax = (ebp << 0x8) + arg_10;
                            bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                            if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                    if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                            eax = var_28;
                                    }
                                    else {
                                            eax = 0x2;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    eax = var_28;
            }
    }
    else {
            asm { fstp       st0 };
            eax = var_28;
    }
    return eax;

.l91:
    ebp = arg_4;
    ebx = *((ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + 0x52b4e8);
    edi = *((ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + 0x52b4ec);
    ecx = (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0;
    ebx = ebx + 0x1;
    bool_139 = edi + 0x0 + CARRY(EFLAGS(cf)) > ecx[0x163e3b];
    if (edi + 0x0 + CARRY(EFLAGS(cf)) < ecx[0x163e3b]) goto .l112;
    goto .l92;

.l15:
    if (eax <= 0x32) goto .l24;
    goto .l9;

loc_434042:
    goto .l13;

loc_43402d:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    ecx = 0x0;
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_12 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_12 && *(eax * 0x8 + 0x57a8e8) <= ecx) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    ecx = 0x0;
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_12 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_12 && *(eax * 0x8 + 0x57a8e8) <= ecx) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l65:
    bool_107 = true;
    eax = sub_47bb70(eax - 0x32, edx - 0x0 + CARRY(EFLAGS(cf)), 0x96, 0x0);
    esp = esp - 0x20;
    eax = sub_47bac0(eax, edx, 0x64, 0x0);
    eax = eax + 0x32;
    var_38 = eax;
    var_34 = edx + 0x0 + CARRY(EFLAGS(cf));
    if ((var_30 | var_2C) != 0x0) goto loc_434057;
    goto .l66;

.l53:
    if (ebx < ecx[0x163e3a]) goto .l64;
    goto .l54;

.l50:
    var_38 = 0x32;
    var_34 = 0x0;
    goto loc_434057;

loc_433f95:
    if (bool_14) goto .l40;
    goto loc_433f97;

.l74:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l76;
    goto .l75;

.l27:
    if (eax[0x16143a] <= ecx) goto .l32;
    goto .l25;

.l112:
    var_38 = 0x32;
    var_34 = 0x0;
    goto .l21;

.l92:
    if (bool_139) goto .l105;
    goto .l93;

.l24:
    ebp = arg_4;
    var_38 = 0x32;
    var_34 = 0x0;
    goto .l21;

.l9:
    ebp = arg_4;
    ebx = *((ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + 0x52b4e8);
    edi = *((ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + 0x52b4ec);
    ecx = (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0 + (ebp << 0x8) + arg_0;
    ebx = ebx + 0x1;
    bool_36 = edi + 0x0 + CARRY(EFLAGS(cf)) < ecx[0x163e3b];
    bool_35 = edi + 0x0 + CARRY(EFLAGS(cf)) > ecx[0x163e3b];
    if (bool_36) goto .l90;
    goto .l8;

.l66:
    eax = (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8;
    bool_111 = eax[0x16143b] > 0x0;
    if (eax[0x16143b] < 0x0) goto loc_434057;
    goto .l67;

.l64:
    var_38 = 0x32;
    var_34 = 0x0;
    goto loc_434057;

.l54:
    bool_95 = true;
    eax = sub_47bb70(eax - 0x32, edx - 0x0 + CARRY(EFLAGS(cf)), 0x96, 0x0);
    esp = esp - 0x20;
    eax = sub_47bac0(eax, edx, 0x64, 0x0);
    eax = eax + 0x32;
    var_38 = eax;
    var_34 = edx + 0x0 + CARRY(EFLAGS(cf));
    if ((var_30 | var_2C) != 0x0) goto loc_434057;
    goto .l55;

.l40:
    esi = 0x32;
    bool_79 = true;
    eax = sub_47bb70(eax - 0x32, edx - 0x0 + CARRY(EFLAGS(cf)), 0x96, 0x0);
    esp = esp - 0x20;
    eax = sub_47bac0(eax, edx, 0x64, 0x0);
    eax = eax + 0x32;
    var_38 = eax;
    var_34 = edx + 0x0 + CARRY(EFLAGS(cf));
    if ((var_30 | var_2C) != 0x0) goto loc_434057;
    goto .l41;

loc_433f97:
    if (ebx < ecx[0x163e3a]) goto .l17;
    goto loc_433f9f;

.l76:
    goto .l32;

.l75:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_65 = *(eax * 0x8 + 0x57a8ec) > ecx;
                                    if (*(eax * 0x8 + 0x57a8ec) >= ecx) {
                                            if (!bool_65 && *(eax * 0x8 + 0x57a8e8) <= ecx) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_65 = *(eax * 0x8 + 0x57a8ec) > ecx;
                                    if (*(eax * 0x8 + 0x57a8ec) >= ecx) {
                                            if (!bool_65 && *(eax * 0x8 + 0x57a8e8) <= ecx) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l25:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l29;
    goto .l31;

.l105:
    bool_153 = true;
    eax = sub_47bb70(eax - 0x32, edx - 0x0 + CARRY(EFLAGS(cf)), 0x96, 0x0);
    esp = esp - 0x20;
    eax = sub_47bac0(eax, edx, 0x64, 0x0);
    eax = eax + 0x32;
    var_38 = eax;
    var_34 = edx + 0x0 + CARRY(EFLAGS(cf));
    if ((var_30 | var_2C) != 0x0) goto .l21;
    goto .l106;

.l93:
    if (ebx < ecx[0x163e3a]) goto .l104;
    goto .l94;

.l90:
    var_38 = 0x32;
    var_34 = 0x0;
    goto .l21;

.l8:
    if (bool_35) goto .l80;
    goto .l20;

.l67:
    if (bool_111) goto .l69;
    goto .l68;

.l55:
    eax = (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8;
    bool_99 = eax[0x16143b] > 0x0;
    if (eax[0x16143b] < 0x0) goto loc_434057;
    goto .l56;

.l41:
    eax = (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8;
    bool_83 = eax[0x16143b] > 0x0;
    if (eax[0x16143b] < 0x0) goto loc_434057;
    goto .l42;

.l17:
    var_38 = 0x32;
    var_34 = 0x0;
    goto loc_434057;

loc_433f9f:
    esi = 0x32;
    bool_30 = true;
    eax = sub_47bb70(eax - 0x32, edx - 0x0 + CARRY(EFLAGS(cf)), 0x96, 0x0);
    esp = esp - 0x20;
    eax = sub_47bac0(eax, edx, 0x64, 0x0);
    eax = eax + 0x32;
    var_38 = eax;
    var_34 = edx + 0x0 + CARRY(EFLAGS(cf));
    if ((var_30 | var_2C) != 0x0) goto loc_434057;
    goto .l3;

.l29:
    goto .l32;

.l31:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_65 = *(eax * 0x8 + 0x57a8ec) > ecx;
                                    if (*(eax * 0x8 + 0x57a8ec) >= ecx) {
                                            if (!bool_65 && *(eax * 0x8 + 0x57a8e8) <= ecx) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_65 = *(eax * 0x8 + 0x57a8ec) > ecx;
                                    if (*(eax * 0x8 + 0x57a8ec) >= ecx) {
                                            if (!bool_65 && *(eax * 0x8 + 0x57a8e8) <= ecx) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l106:
    eax = (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8;
    bool_157 = eax[0x16143b] > 0x0;
    if (eax[0x16143b] < 0x0) goto .l21;
    goto .l107;

.l104:
    var_38 = 0x32;
    var_34 = 0x0;
    goto .l21;

.l94:
    bool_141 = true;
    eax = sub_47bb70(eax - 0x32, edx - 0x0 + CARRY(EFLAGS(cf)), 0x96, 0x0);
    esp = esp - 0x20;
    eax = sub_47bac0(eax, edx, 0x64, 0x0);
    eax = eax + 0x32;
    var_38 = eax;
    var_34 = edx + 0x0 + CARRY(EFLAGS(cf));
    if ((var_30 | var_2C) != 0x0) goto .l21;
    goto .l95;

.l80:
    esi = 0x32;
    bool_125 = true;
    eax = sub_47bb70(eax - 0x32, edx - 0x0 + CARRY(EFLAGS(cf)), 0x96, 0x0);
    esp = esp - 0x20;
    eax = sub_47bac0(eax, edx, 0x64, 0x0);
    eax = eax + 0x32;
    var_38 = eax;
    var_34 = edx + 0x0 + CARRY(EFLAGS(cf));
    if ((var_30 | var_2C) != 0x0) goto .l21;
    goto .l81;

.l20:
    if (ebx < ecx[0x163e3a]) goto .l33;
    goto .l23;

.l69:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l71;
    goto .l70;

.l68:
    ecx = 0x0;
    if (eax[0x16143a] > 0x0) {
            asm { fld        dword [aWeHaveReceived_4b0d00+36] };
            asm { fcomp      st1 };
            asm { fnstsw     ax };
            if (!asm { fnstsw     ax }) {
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if (*(int8_t *)byte_baed68 == 0x1) {
                                    asm { fcomp      dword [dword_value_1077936128] };
                                    asm { fnstsw     ax };
                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                            if ((var_28 | var_24) == 0x0) {
                                                    eax = (ebp << 0x8) + arg_10;
                                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                                    eax = var_28;
                                                            }
                                                            else {
                                                                    eax = 0x2;
                                                            }
                                                    }
                                                    else {
                                                            eax = var_28;
                                                    }
                                            }
                                            else {
                                                    eax = var_28;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    asm { fstp       st0 };
                                    eax = var_28;
                            }
                    }
                    else {
                            if (*(int8_t *)byte_baed68 == 0x1) {
                                    asm { fcomp      dword [dword_value_1077936128] };
                                    asm { fnstsw     ax };
                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                            if ((var_28 | var_24) == 0x0) {
                                                    eax = (ebp << 0x8) + arg_10;
                                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                                    eax = var_28;
                                                            }
                                                            else {
                                                                    eax = 0x2;
                                                            }
                                                    }
                                                    else {
                                                            eax = var_28;
                                                    }
                                            }
                                            else {
                                                    eax = var_28;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    asm { fstp       st0 };
                                    eax = var_28;
                            }
                    }
            }
            else {
                    if (PARITY(HIBYTE(eax) & 0x5)) {
                            if (*(int8_t *)byte_baed68 == 0x1) {
                                    asm { fcomp      dword [dword_value_1077936128] };
                                    asm { fnstsw     ax };
                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                            if ((var_28 | var_24) == 0x0) {
                                                    eax = (ebp << 0x8) + arg_10;
                                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                                    eax = var_28;
                                                            }
                                                            else {
                                                                    eax = 0x2;
                                                            }
                                                    }
                                                    else {
                                                            eax = var_28;
                                                    }
                                            }
                                            else {
                                                    eax = var_28;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    asm { fstp       st0 };
                                    eax = var_28;
                            }
                    }
                    else {
                            if (*(int8_t *)byte_baed68 == 0x1) {
                                    asm { fcomp      dword [dword_value_1077936128] };
                                    asm { fnstsw     ax };
                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                            if ((var_28 | var_24) == 0x0) {
                                                    eax = (ebp << 0x8) + arg_10;
                                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                                    eax = var_28;
                                                            }
                                                            else {
                                                                    eax = 0x2;
                                                            }
                                                    }
                                                    else {
                                                            eax = var_28;
                                                    }
                                            }
                                            else {
                                                    eax = var_28;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    asm { fstp       st0 };
                                    eax = var_28;
                            }
                    }
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l56:
    if (bool_99) goto .l61;
    goto .l57;

.l42:
    if (bool_83) goto .l47;
    goto .l43;

.l3:
    eax = (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8;
    bool_23 = eax[0x16143b] > 0x0;
    if (eax[0x16143b] < 0x0) goto loc_434057;
    goto .l6;

.l107:
    if (bool_157) goto .l109;
    goto .l108;

.l95:
    eax = (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8;
    bool_145 = eax[0x16143b] > 0x0;
    if (eax[0x16143b] < 0x0) goto .l21;
    goto .l96;

.l81:
    eax = (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8;
    bool_129 = eax[0x16143b] > 0x0;
    if (eax[0x16143b] < 0x0) goto .l21;
    goto .l82;

.l33:
    var_38 = 0x32;
    var_34 = 0x0;
    goto .l21;

.l23:
    esi = 0x32;
    bool_51 = true;
    eax = sub_47bb70(eax - 0x32, edx - 0x0 + CARRY(EFLAGS(cf)), 0x96, 0x0);
    esp = esp - 0x20;
    eax = sub_47bac0(eax, edx, 0x64, 0x0);
    eax = eax + 0x32;
    var_38 = eax;
    var_34 = edx + 0x0 + CARRY(EFLAGS(cf));
    if ((var_30 | var_2C) != 0x0) goto .l21;
    goto .l11;

.l71:
    goto loc_434057;

.l70:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l61:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l63;
    goto .l62;

.l57:
    ecx = 0x0;
    if (eax[0x16143a] <= 0x0) goto loc_434057;
    goto .l58;

.l47:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l49;
    goto .l48;

.l43:
    ecx = 0x0;
    if (eax[0x16143a] <= 0x0) goto loc_434057;
    goto .l44;

.l6:
    if (bool_23) goto .l37;
    goto .l4;

.l109:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l111;
    goto .l110;

.l108:
    ecx = 0x0;
    if (eax[0x16143a] > 0x0) {
            asm { fld        dword [aWeHaveReceived_4b0d00+36] };
            asm { fcomp      st1 };
            asm { fnstsw     ax };
            if (!asm { fnstsw     ax }) {
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if (*(int8_t *)byte_baed68 == 0x1) {
                                    asm { fcomp      dword [dword_value_1077936128] };
                                    asm { fnstsw     ax };
                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                            if ((var_28 | var_24) == 0x0) {
                                                    eax = (ebp << 0x8) + arg_10;
                                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                                    eax = var_28;
                                                            }
                                                            else {
                                                                    eax = 0x2;
                                                            }
                                                    }
                                                    else {
                                                            eax = var_28;
                                                    }
                                            }
                                            else {
                                                    eax = var_28;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    asm { fstp       st0 };
                                    eax = var_28;
                            }
                    }
                    else {
                            if (*(int8_t *)byte_baed68 == 0x1) {
                                    asm { fcomp      dword [dword_value_1077936128] };
                                    asm { fnstsw     ax };
                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                            if ((var_28 | var_24) == 0x0) {
                                                    eax = (ebp << 0x8) + arg_10;
                                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                                    eax = var_28;
                                                            }
                                                            else {
                                                                    eax = 0x2;
                                                            }
                                                    }
                                                    else {
                                                            eax = var_28;
                                                    }
                                            }
                                            else {
                                                    eax = var_28;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    asm { fstp       st0 };
                                    eax = var_28;
                            }
                    }
            }
            else {
                    if (PARITY(HIBYTE(eax) & 0x5)) {
                            if (*(int8_t *)byte_baed68 == 0x1) {
                                    asm { fcomp      dword [dword_value_1077936128] };
                                    asm { fnstsw     ax };
                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                            if ((var_28 | var_24) == 0x0) {
                                                    eax = (ebp << 0x8) + arg_10;
                                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                                    eax = var_28;
                                                            }
                                                            else {
                                                                    eax = 0x2;
                                                            }
                                                    }
                                                    else {
                                                            eax = var_28;
                                                    }
                                            }
                                            else {
                                                    eax = var_28;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    asm { fstp       st0 };
                                    eax = var_28;
                            }
                    }
                    else {
                            if (*(int8_t *)byte_baed68 == 0x1) {
                                    asm { fcomp      dword [dword_value_1077936128] };
                                    asm { fnstsw     ax };
                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                            if ((var_28 | var_24) == 0x0) {
                                                    eax = (ebp << 0x8) + arg_10;
                                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                                    eax = var_28;
                                                            }
                                                            else {
                                                                    eax = 0x2;
                                                            }
                                                    }
                                                    else {
                                                            eax = var_28;
                                                    }
                                            }
                                            else {
                                                    eax = var_28;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    asm { fstp       st0 };
                                    eax = var_28;
                            }
                    }
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l96:
    if (bool_145) goto .l101;
    goto .l97;

.l82:
    if (bool_129) goto .l87;
    goto .l83;

.l11:
    eax = (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8 + (ebp << 0x8) + arg_8;
    bool_44 = eax[0x16143b] > 0x0;
    if (eax[0x16143b] < 0x0) goto .l21;
    goto .l18;

.l63:
    goto loc_434057;

.l62:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l58:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l60;
    goto .l59;

.l49:
    goto loc_434057;

.l48:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l44:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l46;
    goto .l45;

.l37:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l39;
    goto .l38;

.l4:
    if (eax[0x16143a] <= 0x0) goto loc_434057;
    goto .l2;

.l111:
    goto .l21;

.l110:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l101:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l103;
    goto .l102;

.l97:
    ecx = 0x0;
    if (eax[0x16143a] <= 0x0) goto .l21;
    goto .l98;

.l87:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l89;
    goto .l88;

.l83:
    ecx = 0x0;
    if (eax[0x16143a] <= 0x0) goto .l21;
    goto .l84;

.l18:
    if (bool_44) goto .l77;
    goto .l12;

.l60:
    goto loc_434057;

.l59:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l46:
    goto loc_434057;

.l45:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l39:
    goto loc_434057;

.l38:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l2:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l5;
    goto .l7;

.l103:
    goto .l21;

.l102:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l98:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l100;
    goto .l99;

.l89:
    goto .l21;

.l88:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l84:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l86;
    goto .l85;

.l77:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l79;
    goto .l78;

.l12:
    if (eax[0x16143a] <= 0x0) goto .l21;
    goto .l10;

.l5:
    goto loc_434057;

.l7:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_33 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_33 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l100:
    goto .l21;

.l99:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l86:
    goto .l21;

.l85:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l79:
    goto .l21;

.l78:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;

.l10:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st1 };
    asm { fnstsw     ax };
    if (asm { fnstsw     ax }) goto .l16;
    goto .l22;

.l16:
    goto .l21;

.l22:
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    else {
            if (*(int8_t *)byte_baed68 == 0x1) {
                    asm { fcomp      dword [dword_value_1077936128] };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if ((var_28 | var_24) == 0x0) {
                                    eax = (ebp << 0x8) + arg_10;
                                    bool_54 = *(eax * 0x8 + 0x57a8ec) > 0x0;
                                    if (*(eax * 0x8 + 0x57a8ec) >= 0x0) {
                                            if (!bool_54 && *(eax * 0x8 + 0x57a8e8) <= 0x0) {
                                                    eax = var_28;
                                            }
                                            else {
                                                    eax = 0x2;
                                            }
                                    }
                                    else {
                                            eax = var_28;
                                    }
                            }
                            else {
                                    eax = var_28;
                            }
                    }
                    else {
                            eax = var_28;
                    }
            }
            else {
                    asm { fstp       st0 };
                    eax = var_28;
            }
    }
    return eax;
}
