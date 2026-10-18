// sub_467f40 @ 0x467f40
// hopper name: sub_467f40
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467f40() {
    decomp_var_8 = 0x49a13b;
    var_C = *0x0;
    var_10 = *dword_4c8db8 ^ &var_54;
    *0x0 = &var_C;
    var_40 = ecx;
    esi = 0x0;
    var_4C = 0xffffffff;
    var_20 = 0x0;
    var_30 = 0x0;
    sub_46db50() + 0xc;
    edi = arg_14;
    eax = sub_46dbce(-((-(OVERFLOW(arg_14 * 0x2) ? 0x1 : 0x0) | arg_14 * 0x2) < 0xfffffffc ? 0x1 : 0x0) | (-(OVERFLOW(arg_14 * 0x2) ? 0x1 : 0x0) | arg_14 * 0x2) + 0x4);
    esp = (esp - 0x6c) + 0x4;
    var_4 = 0x2;
    if (eax != 0x0) {
            ebx = eax + 0x4;
            esp = esp - 0x14;
            *eax = edi;
            sub_47bba4();
    }
    else {
            esi = 0x0;
    }
    temp_1 = 0x9;
    goto .l18;

.l18:
    if (temp_1 != 0x0) {
            eax = arg_30;
            if (esi < eax) {
                    edx = arg_34;
                    ecx = arg_20;
                    ebx = 0x10;
                    eax = ecx;
                    if (edx < 0x10) {
                            eax = &arg_20;
                    }
                    if (*(int8_t *)(eax + esi) == 0x20) {
                            esi = esi + 0x1;
                            if (var_14 == 0xffffffff) {
                                    temp_1 = 0x9;
                                    continue;
                            }
                            edi = var_14;
                            temp_2 = 0x0;
                            break;
                    }
                    else {
                            ebx = 0x10;
                            eax = ecx;
                            if (edx < 0x10) {
                                    eax = &arg_20;
                            }
                            if (*(int8_t *)(eax + esi) == 0x28) {
                                    var_2C = var_2C + 0x1;
                                    *(int16_t *)(var_34 + var_38 * 0x2) = *(int16_t *)word_4c79b4;
                                    eax = var_38 + 0x1;
                                    esi = esi + 0x1;
                                    if (var_14 == 0xffffffff) {
                                            temp_1 = 0x9;
                                            continue;
                                    }
                                    edi = var_14;
                                    temp_2 = 0x0;
                                    break;
                            }
                            else {
                                    ebx = 0x10;
                                    eax = ecx;
                                    if (edx < 0x10) {
                                            eax = &arg_20;
                                    }
                                    if (*(int8_t *)(eax + esi) == 0x29) {
                                            *(int16_t *)(var_34 + var_38 * 0x2) = *(int16_t *)word_4c79b8;
                                            var_2C = var_2C - 0x1;
                                            if (var_2C < 0x0) {
                                                    var_30 = esi;
                                            }
                                            var_38 = var_38 + 0x1;
                                            esi = esi + 0x1;
                                            if (var_14 == 0xffffffff) {
                                                    temp_1 = 0x9;
                                                    continue;
                                            }
                                            edi = var_14;
                                            temp_2 = 0x0;
                                            break;
                                    }
                                    else {
                                            eax = ecx;
                                            if (edx < ebx) {
                                                    eax = &arg_20;
                                            }
                                            if (*(int8_t *)(eax + esi) == 0x27) {
                                                    eax = var_38;
                                                    esi = esi + 0x1;
                                                    if (eax > 0x0) {
                                                            ecx = var_34;
                                                            if (*(int8_t *)(ecx + (eax * 0x2 - 0x1)) == 0x4b) {
                                                                    *(int16_t *)(ecx + eax * 0x2) = 0x4b27;
                                                                    var_38 = eax + 0x1;
                                                            }
                                                    }
                                                    bool_84 = esi <= arg_30;
                                                    bool_38 = esi <= arg_30;
                                                    if (esi < arg_30) {
                                                            edi = var_38;
                                                            ebp = ebx;
                                                            ebx = var_34;
                                                            if (!bool_38) {
                                                                    sub_47a948();
                                                            }
                                                            eax = arg_20;
                                                            if (arg_34 < ebp) {
                                                                    eax = &arg_20;
                                                            }
                                                            bool_47 = *(int8_t *)(eax + esi) == 0x27;
                                                            bool_23 = *(int8_t *)(eax + esi) <= 0x27;
                                                            if (!bool_47) {
                                                                    if (esi > arg_30) {
                                                                            sub_47a948();
                                                                    }
                                                                    eax = arg_20;
                                                                    if (arg_34 < ebp) {
                                                                            eax = &arg_20;
                                                                    }
                                                                    *(int16_t *)(ebx + edi * 0x2) = *(int8_t *)(eax + esi) & 0xff | 0x4b00;
                                                                    edi = edi + 0x1;
                                                                    esi = esi + 0x1;
                                                                    bool_57 = esi <= arg_30;
                                                                    var_38 = edi;
                                                                    if (esi < arg_30) {
                                                                            temp_1 = 0x0;
                                                                            continue;
                                                                    }
                                                                    if (!bool_57) {
                                                                            sub_47a948();
                                                                    }
                                                                    eax = arg_3c;
                                                                    if (arg_50 < 0x10) {
                                                                            eax = &arg_3c;
                                                                    }
                                                                    if (*(int8_t *)(eax + esi) != 0x27) {
                                                                            var_14 = esi;
                                                                    }
                                                                    else {
                                                                            esi = esi + 0x1;
                                                                    }
                                                                    if (var_14 == 0xffffffff) {
                                                                            temp_1 = 0x9;
                                                                            continue;
                                                                    }
                                                                    edi = var_14;
                                                                    temp_2 = 0x0;
                                                                    break;
                                                            }
                                                            else {
                                                                    if (!bool_23) {
                                                                            sub_47a948();
                                                                    }
                                                                    eax = arg_3c;
                                                                    if (arg_50 < 0x10) {
                                                                            eax = &arg_3c;
                                                                    }
                                                                    if (*(int8_t *)(eax + esi) != 0x27) {
                                                                            var_14 = esi;
                                                                    }
                                                                    else {
                                                                            esi = esi + 0x1;
                                                                    }
                                                                    if (var_14 == 0xffffffff) {
                                                                            temp_1 = 0x9;
                                                                            continue;
                                                                    }
                                                                    edi = var_14;
                                                                    temp_2 = 0x0;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_84) {
                                                                    sub_47a948();
                                                            }
                                                            eax = arg_3c;
                                                            if (arg_50 < 0x10) {
                                                                    eax = &arg_3c;
                                                            }
                                                            if (*(int8_t *)(eax + esi) != 0x27) {
                                                                    var_14 = esi;
                                                            }
                                                            else {
                                                                    esi = esi + 0x1;
                                                            }
                                                            if (var_14 == 0xffffffff) {
                                                                    temp_1 = 0x9;
                                                                    continue;
                                                            }
                                                            edi = var_14;
                                                            temp_2 = 0x0;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    eax = ecx;
                                                    if (edx < ebx) {
                                                            eax = &arg_20;
                                                    }
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (sub_47cf30(sign_extend_32(*(int8_t *)(eax + esi))) != 0x0) {
                                                            if (esi > arg_30) {
                                                                    sub_47a948();
                                                            }
                                                            ebx = 0x10;
                                                            eax = arg_20;
                                                            if (arg_34 < 0x10) {
                                                                    eax = &arg_20;
                                                            }
                                                            edi = esi + 0x1;
                                                            esp = (esp - 0x4) + 0x4;
                                                            arg_0 = sub_47d2d2(sign_extend_32(*(int8_t *)(eax + esi)));
                                                            if (edi > arg_30) {
                                                                    sub_47a948();
                                                            }
                                                            eax = arg_20;
                                                            if (arg_34 < ebx) {
                                                                    eax = &arg_20;
                                                            }
                                                            eax = sign_extend_32(*(int8_t *)(eax + edi));
                                                            edi = esi + 0x2;
                                                            esp = (esp - 0x4) + 0x4;
                                                            sub_47d2d2(eax);
                                                            if (edi > arg_30) {
                                                                    sub_47a948();
                                                            }
                                                            eax = arg_20;
                                                            if (arg_34 < ebx) {
                                                                    eax = &arg_20;
                                                            }
                                                            sub_47d2d2(sign_extend_32(*(int8_t *)(eax + edi)));
                                                            eax = &arg_0;
                                                            esp = (esp - 0x4) + 0x4;
                                                            edx = eax + 0x1;
                                                            &var_4C = &var_4C;
                                                            do {
                                                                    ecx = *(int8_t *)eax;
                                                                    eax = eax + 0x1;
                                                            } while (ecx != 0x0);
                                                            sub_402650(&arg_0, eax - edx);
                                                            esp = esp - 0x10;
                                                            eax = sub_4675e0(&var_28, &var_20, &arg_0, eax - edx, var_4C);
                                                            edi = *eax;
                                                            ebp = eax[0x1];
                                                            ebx = var_30[0x1];
                                                            if (edi == 0x0 || edi != var_30) {
                                                                    sub_47a948();
                                                            }
                                                            if (ebp == ebx) {
                                                                    var_38 = esi;
                                                            }
                                                            else {
                                                                    if (edi == 0x0) {
                                                                            sub_47a948();
                                                                    }
                                                                    if (ebp == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    *(int16_t *)(var_3C + var_40 * 0x2) = arg_24;
                                                                    eax = var_40 + 0x1;
                                                                    esi = esi + 0x3;
                                                            }
                                                            if (var_14 == 0xffffffff) {
                                                                    temp_1 = 0x9;
                                                                    continue;
                                                            }
                                                            edi = var_14;
                                                            temp_2 = 0x0;
                                                            break;
                                                    }
                                                    else {
                                                            if (esi > arg_30) {
                                                                    sub_47a948();
                                                            }
                                                            ebx = 0x10;
                                                            eax = arg_20;
                                                            if (arg_34 < 0x10) {
                                                                    eax = &arg_20;
                                                            }
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (sub_47d09a(sign_extend_32(*(int8_t *)(eax + esi))) == 0x0) {
                                                                    if (esi > arg_30) {
                                                                            sub_47a948();
                                                                    }
                                                                    eax = arg_20;
                                                                    if (arg_34 < ebx) {
                                                                            eax = &arg_20;
                                                                    }
                                                                    if (*(int8_t *)(eax + esi) != 0x2d) {
                                                                            var_30 = esi;
                                                                            if (var_14 == 0xffffffff) {
                                                                                    temp_1 = 0x9;
                                                                                    continue;
                                                                            }
                                                                            edi = var_14;
                                                                            temp_2 = 0x0;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            if (esi > arg_30) {
                                                                                    sub_47a948();
                                                                            }
                                                                            eax = arg_20;
                                                                            if (arg_34 < ebx) {
                                                                                    eax = &arg_20;
                                                                            }
                                                                            if (*(int8_t *)(eax + esi) == 0x2d) {
                                                                                    esi = esi + 0x1;
                                                                            }
                                                                            edi = 0x0;
                                                                            &var_4C = &var_4C;
                                                                            while (true) {
                                                                                    if (esi > arg_30) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    eax = arg_20;
                                                                                    if (arg_34 < ebx) {
                                                                                            eax = &arg_20;
                                                                                    }
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    if (sub_47d09a(sign_extend_32(*(int8_t *)(eax + esi))) == 0x0) {
                                                                                            break;
                                                                                    }
                                                                                    if (esi > arg_30) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    eax = arg_20;
                                                                                    if (arg_34 < ebx) {
                                                                                            eax = &arg_20;
                                                                                    }
                                                                                    edi = sign_extend_32(*(int8_t *)(eax + esi)) + ((edi + edi * 0x4) * 0x2 - 0x30);
                                                                                    esi = esi + 0x1;
                                                                            }
                                                                            edi = edi & 0x3fff;
                                                                            *(int16_t *)(var_34 + var_38 * 0x2) = edi;
                                                                            eax = var_38 + 0x1;
                                                                            if (var_14 == 0xffffffff) {
                                                                                    temp_1 = 0x9;
                                                                                    continue;
                                                                            }
                                                                            edi = var_14;
                                                                            temp_2 = 0x0;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (esi > arg_30) {
                                                                            sub_47a948();
                                                                    }
                                                                    eax = arg_20;
                                                                    if (arg_34 < ebx) {
                                                                            eax = &arg_20;
                                                                    }
                                                                    if (*(int8_t *)(eax + esi) == 0x2d) {
                                                                            esi = esi + 0x1;
                                                                    }
                                                                    edi = 0x0;
                                                                    &var_4C = &var_4C;
                                                                    while (true) {
                                                                            if (esi > arg_30) {
                                                                                    sub_47a948();
                                                                            }
                                                                            eax = arg_20;
                                                                            if (arg_34 < ebx) {
                                                                                    eax = &arg_20;
                                                                            }
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            if (sub_47d09a(sign_extend_32(*(int8_t *)(eax + esi))) == 0x0) {
                                                                                    break;
                                                                            }
                                                                            if (esi > arg_30) {
                                                                                    sub_47a948();
                                                                            }
                                                                            eax = arg_20;
                                                                            if (arg_34 < ebx) {
                                                                                    eax = &arg_20;
                                                                            }
                                                                            edi = sign_extend_32(*(int8_t *)(eax + esi)) + ((edi + edi * 0x4) * 0x2 - 0x30);
                                                                            esi = esi + 0x1;
                                                                    }
                                                                    edi = edi & 0x3fff;
                                                                    *(int16_t *)(var_34 + var_38 * 0x2) = edi;
                                                                    eax = var_38 + 0x1;
                                                                    if (var_14 == 0xffffffff) {
                                                                            temp_1 = 0x9;
                                                                            continue;
                                                                    }
                                                                    edi = var_14;
                                                                    temp_2 = 0x0;
                                                                    break;
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    edi = var_30;
                    if (edi == 0xffffffff) {
                            if (var_2C != 0x0) {
                                    edi = eax;
                                    temp_2 = 0x1;
                            }
                            else {
                                    esp = esp - 0x8;
                                    edi = sub_465940(var_34, var_38, var_4C);
                                    if (edi != 0xffffffff) {
                                            edi = arg_30;
                                            temp_2 = 0x3;
                                    }
                                    else {
                                            temp_2 = 0x2;
                                    }
                            }
                    }
                    else {
                            temp_2 = 0x0;
                    }
                    break;
            }
    }
    else {
            eax = arg_20;
            if (arg_34 < ebp) {
                    eax = &arg_20;
            }
            bool_81 = *(int8_t *)(eax + esi) == 0x27;
            bool_63 = *(int8_t *)(eax + esi) <= 0x27;
            if (!bool_81) {
                    if (esi > arg_30) {
                            sub_47a948();
                    }
                    eax = arg_20;
                    if (arg_34 < ebp) {
                            eax = &arg_20;
                    }
                    *(int16_t *)(ebx + edi * 0x2) = *(int8_t *)(eax + esi) & 0xff | 0x4b00;
                    edi = edi + 0x1;
                    esi = esi + 0x1;
                    bool_39 = esi <= arg_30;
                    var_38 = edi;
                    if (esi < arg_30) {
                            temp_1 = 0x0;
                            continue;
                    }
                    if (!bool_39) {
                            sub_47a948();
                    }
                    eax = arg_3c;
                    if (arg_50 < 0x10) {
                            eax = &arg_3c;
                    }
                    if (*(int8_t *)(eax + esi) != 0x27) {
                            var_14 = esi;
                    }
                    else {
                            esi = esi + 0x1;
                    }
                    if (var_14 == 0xffffffff) {
                            temp_1 = 0x9;
                            continue;
                    }
                    edi = var_14;
                    temp_2 = 0x0;
                    break;
            }
            else {
                    if (!bool_63) {
                            sub_47a948();
                    }
                    eax = arg_3c;
                    if (arg_50 < 0x10) {
                            eax = &arg_3c;
                    }
                    if (*(int8_t *)(eax + esi) != 0x27) {
                            var_14 = esi;
                    }
                    else {
                            esi = esi + 0x1;
                    }
                    if (var_14 == 0xffffffff) {
                            temp_1 = 0x9;
                            continue;
                    }
                    edi = var_14;
                    temp_2 = 0x0;
                    break;
            }
    }
    goto .l2;

.l2:
    eax = arg_0;
    if (eax != 0x0) {
            sub_47b6f8();
            sub_47c8f9();
            esp = (esp - 0x14) + 0x4;
    }
    if (arg_34 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    if (arg_6C >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    *0x0 = arg_44;
    eax = sub_47ad69();
    return eax;
}
