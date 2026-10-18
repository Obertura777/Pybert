// sub_482f0e @ 0x482f0e
// hopper name: sub_482f0e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_482f0e() {
    decomp_var_18 = esi;
    decomp_var_1c = edi;
    esp = esp - 0xc;
    sub_47aea2(arg_0);
    eax = arg_8;
    esi = arg_4;
    if (eax != 0x0) {
            *eax = esi;
    }
    if (esi == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            esp = (esp - 0x14) + 0x14;
            if (var_8 != 0x0) {
                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
            }
            eax = 0x0;
    }
    else {
            if (arg_c != 0x0) {
                    if (arg_c >= 0x2) {
                            if (arg_c <= 0x24) {
                                    ecx = var_14;
                                    esp = esp - 0x4;
                                    decomp_var_20 = ebx;
                                    ebx = *(int8_t *)esi;
                                    var_4 = 0x0;
                                    edi = esi + 0x1;
                                    while (true) {
                                            if (ecx[0x2b] > 0x1) {
                                                    eax = sub_487c7b(ebx & 0xff, 0x8, &var_14);
                                                    ecx = var_14;
                                                    esp = (esp - 0xc) + 0xc;
                                            }
                                            else {
                                                    eax = *(int8_t *)(ecx[0x32] + (ebx & 0xff) * 0x2) & 0xff;
                                                    eax = eax & 0x8;
                                            }
                                            if (eax == 0x0) {
                                                    break;
                                            }
                                            ebx = *(int8_t *)edi;
                                            edi = edi + 0x1;
                                    }
                                    if (ebx == 0x2d) {
                                            arg_10 = arg_10 | 0x2;
                                            ebx = *(int8_t *)edi;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            if (ebx == 0x2b) {
                                                    ebx = *(int8_t *)edi;
                                                    edi = edi + 0x1;
                                            }
                                    }
                                    eax = arg_c;
                                    if (eax >= 0x0) {
                                            if (eax != 0x1) {
                                                    if (eax <= 0x24) {
                                                            if (eax == 0x0) {
                                                                    if (ebx != 0x30) {
                                                                            arg_c = 0xa;
                                                                    }
                                                                    else {
                                                                            eax = *(int8_t *)edi;
                                                                            if (eax != 0x78 && eax != 0x58) {
                                                                                    arg_c = 0x8;
                                                                            }
                                                                            else {
                                                                                    arg_c = 0x10;
                                                                                    eax = *(int8_t *)edi;
                                                                                    if (eax == 0x78 || eax == 0x58) {
                                                                                            ebx = edi[0x1];
                                                                                            edi = edi + 0x2;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax == 0x10 && ebx == 0x30) {
                                                                            eax = *(int8_t *)edi;
                                                                            if (eax == 0x78 || eax == 0x58) {
                                                                                    ebx = edi[0x1];
                                                                                    edi = edi + 0x2;
                                                                            }
                                                                    }
                                                            }
                                                            esi = ecx[0x32];
                                                            temp_1 = (eax | 0xffffffff) % arg_c;
                                                            eax = (eax | 0xffffffff) / arg_c;
                                                            edx = temp_1;
                                                            while (true) {
                                                                    ecx = *(int16_t *)(esi + (ebx & 0xff) * 0x2) & 0xffff;
                                                                    if ((ecx & 0x4) != 0x0) {
                                                                            ecx = sign_extend_32(ebx) - 0x30;
                                                                            if (ecx < arg_c) {
                                                                                    arg_10 = arg_10 | 0x8;
                                                                                    bool_121 = var_4 != eax;
                                                                                    if (var_4 < eax) {
                                                                                            var_4 = var_4 * arg_c + ecx;
                                                                                            ebx = *(int8_t *)edi;
                                                                                            edi = edi + 0x1;
                                                                                            continue;
                                                                                    }
                                                                                    if (!bool_121) {
                                                                                            if (ecx <= edx) {
                                                                                                    var_4 = var_4 * arg_c + ecx;
                                                                                                    ebx = *(int8_t *)edi;
                                                                                                    edi = edi + 0x1;
                                                                                                    continue;
                                                                                            }
                                                                                            arg_10 = arg_10 | 0x4;
                                                                                            if (arg_8 != 0x0) {
                                                                                                    ebx = *(int8_t *)edi;
                                                                                                    edi = edi + 0x1;
                                                                                                    continue;
                                                                                            }
                                                                                            temp_2 = 0x0;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            arg_10 = arg_10 | 0x4;
                                                                                            if (arg_8 != 0x0) {
                                                                                                    ebx = *(int8_t *)edi;
                                                                                                    edi = edi + 0x1;
                                                                                                    continue;
                                                                                            }
                                                                                            temp_2 = 0x0;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    temp_2 = 0x0;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((ecx & 0x103) != 0x0) {
                                                                                    ecx = sign_extend_32(ebx);
                                                                                    if (ebx <= 0x7a) {
                                                                                            ecx = ecx - 0x20;
                                                                                    }
                                                                                    ecx = ecx - 0x37;
                                                                                    if (ecx < arg_c) {
                                                                                            arg_10 = arg_10 | 0x8;
                                                                                            bool_117 = var_4 != eax;
                                                                                            if (var_4 < eax) {
                                                                                                    var_4 = var_4 * arg_c + ecx;
                                                                                                    ebx = *(int8_t *)edi;
                                                                                                    edi = edi + 0x1;
                                                                                                    continue;
                                                                                            }
                                                                                            if (!bool_117) {
                                                                                                    if (ecx <= edx) {
                                                                                                            var_4 = var_4 * arg_c + ecx;
                                                                                                            ebx = *(int8_t *)edi;
                                                                                                            edi = edi + 0x1;
                                                                                                            continue;
                                                                                                    }
                                                                                                    arg_10 = arg_10 | 0x4;
                                                                                                    if (arg_8 != 0x0) {
                                                                                                            ebx = *(int8_t *)edi;
                                                                                                            edi = edi + 0x1;
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_2 = 0x0;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    arg_10 = arg_10 | 0x4;
                                                                                                    if (arg_8 != 0x0) {
                                                                                                            ebx = *(int8_t *)edi;
                                                                                                            edi = edi + 0x1;
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_2 = 0x0;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            temp_2 = 0x0;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    temp_2 = 0x1;
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            eax = arg_10;
                                                            edi = edi - 0x1;
                                                            if ((eax & 0x8) == 0x0) {
                                                                    if (arg_8 != 0x0) {
                                                                            edi = arg_4;
                                                                    }
                                                                    var_4 = var_4 & 0x0;
                                                                    eax = arg_8;
                                                                    if (eax != 0x0) {
                                                                            *eax = edi;
                                                                    }
                                                                    if ((arg_10 & 0x2) != 0x0) {
                                                                            var_4 = -var_4;
                                                                    }
                                                                    if (var_8 != 0x0) {
                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                    }
                                                                    eax = var_4;
                                                                    esp = esp + 0x4;
                                                            }
                                                            else {
                                                                    if ((eax & 0x4) == 0x0) {
                                                                            if ((eax & 0x1) == 0x0) {
                                                                                    eax = eax & 0x2;
                                                                                    if (eax != 0x0) {
                                                                                            if (var_4 <= 0x80000000) {
                                                                                                    if (eax == 0x0 && var_4 > 0x7fffffff) {
                                                                                                            *sub_47d812() = 0x22;
                                                                                                            if ((arg_10 & 0x1) != 0x0) {
                                                                                                                    var_4 = var_4 | 0xffffffff;
                                                                                                            }
                                                                                                            else {
                                                                                                                    var_4 = -(-(arg_10 & 0x2) - -(arg_10 & 0x2) + CARRY(EFLAGS(cf))) + 0x7fffffff;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    *sub_47d812() = 0x22;
                                                                                                    if ((arg_10 & 0x1) != 0x0) {
                                                                                                            var_4 = var_4 | 0xffffffff;
                                                                                                    }
                                                                                                    else {
                                                                                                            var_4 = -(-(arg_10 & 0x2) - -(arg_10 & 0x2) + CARRY(EFLAGS(cf))) + 0x7fffffff;
                                                                                                    }
                                                                                            }
                                                                                            eax = arg_8;
                                                                                            if (eax != 0x0) {
                                                                                                    *eax = edi;
                                                                                            }
                                                                                            if ((arg_10 & 0x2) != 0x0) {
                                                                                                    var_4 = -var_4;
                                                                                            }
                                                                                            if (var_8 != 0x0) {
                                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                            }
                                                                                            eax = var_4;
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                                    else {
                                                                                            if (eax == 0x0 && var_4 > 0x7fffffff) {
                                                                                                    *sub_47d812() = 0x22;
                                                                                                    if ((arg_10 & 0x1) != 0x0) {
                                                                                                            var_4 = var_4 | 0xffffffff;
                                                                                                    }
                                                                                                    else {
                                                                                                            var_4 = -(-(arg_10 & 0x2) - -(arg_10 & 0x2) + CARRY(EFLAGS(cf))) + 0x7fffffff;
                                                                                                    }
                                                                                            }
                                                                                            eax = arg_8;
                                                                                            if (eax != 0x0) {
                                                                                                    *eax = edi;
                                                                                            }
                                                                                            if ((arg_10 & 0x2) != 0x0) {
                                                                                                    var_4 = -var_4;
                                                                                            }
                                                                                            if (var_8 != 0x0) {
                                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                            }
                                                                                            eax = var_4;
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = arg_8;
                                                                                    if (eax != 0x0) {
                                                                                            *eax = edi;
                                                                                    }
                                                                                    if ((arg_10 & 0x2) != 0x0) {
                                                                                            var_4 = -var_4;
                                                                                    }
                                                                                    if (var_8 != 0x0) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                    }
                                                                                    eax = var_4;
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *sub_47d812() = 0x22;
                                                                            if ((arg_10 & 0x1) != 0x0) {
                                                                                    var_4 = var_4 | 0xffffffff;
                                                                            }
                                                                            else {
                                                                                    var_4 = -(-(arg_10 & 0x2) - -(arg_10 & 0x2) + CARRY(EFLAGS(cf))) + 0x7fffffff;
                                                                            }
                                                                            eax = arg_8;
                                                                            if (eax != 0x0) {
                                                                                    *eax = edi;
                                                                            }
                                                                            if ((arg_10 & 0x2) != 0x0) {
                                                                                    var_4 = -var_4;
                                                                            }
                                                                            if (var_8 != 0x0) {
                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                            }
                                                                            eax = var_4;
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            eax = arg_8;
                                                            if (eax != 0x0) {
                                                                    *eax = esi;
                                                            }
                                                            if (var_8 != 0x0) {
                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                            }
                                                            eax = 0x0;
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                            else {
                                                    eax = arg_8;
                                                    if (eax != 0x0) {
                                                            *eax = esi;
                                                    }
                                                    if (var_8 != 0x0) {
                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = 0x0;
                                                    esp = esp + 0x4;
                                            }
                                    }
                                    else {
                                            eax = arg_8;
                                            if (eax != 0x0) {
                                                    *eax = esi;
                                            }
                                            if (var_8 != 0x0) {
                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                            }
                                            eax = 0x0;
                                            esp = esp + 0x4;
                                    }
                            }
                            else {
                                    *sub_47d812() = 0x16;
                                    sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    if (var_8 != 0x0) {
                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                            }
                    }
                    else {
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            if (var_8 != 0x0) {
                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                            }
                            eax = 0x0;
                    }
            }
            else {
                    ecx = var_14;
                    esp = esp - 0x4;
                    decomp_var_20 = ebx;
                    ebx = *(int8_t *)esi;
                    var_4 = 0x0;
                    edi = esi + 0x1;
                    while (true) {
                            if (ecx[0x2b] > 0x1) {
                                    eax = sub_487c7b(ebx & 0xff, 0x8, &var_14);
                                    ecx = var_14;
                                    esp = (esp - 0xc) + 0xc;
                            }
                            else {
                                    eax = *(int8_t *)(ecx[0x32] + (ebx & 0xff) * 0x2) & 0xff;
                                    eax = eax & 0x8;
                            }
                            if (eax == 0x0) {
                                    break;
                            }
                            ebx = *(int8_t *)edi;
                            edi = edi + 0x1;
                    }
                    if (ebx == 0x2d) {
                            arg_10 = arg_10 | 0x2;
                            ebx = *(int8_t *)edi;
                            edi = edi + 0x1;
                    }
                    else {
                            if (ebx == 0x2b) {
                                    ebx = *(int8_t *)edi;
                                    edi = edi + 0x1;
                            }
                    }
                    eax = arg_c;
                    if (eax >= 0x0) {
                            if (eax != 0x1) {
                                    if (eax <= 0x24) {
                                            if (eax == 0x0) {
                                                    if (ebx != 0x30) {
                                                            arg_c = 0xa;
                                                    }
                                                    else {
                                                            eax = *(int8_t *)edi;
                                                            if (eax != 0x78 && eax != 0x58) {
                                                                    arg_c = 0x8;
                                                            }
                                                            else {
                                                                    arg_c = 0x10;
                                                                    eax = *(int8_t *)edi;
                                                                    if (eax == 0x78 || eax == 0x58) {
                                                                            ebx = edi[0x1];
                                                                            edi = edi + 0x2;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (eax == 0x10 && ebx == 0x30) {
                                                            eax = *(int8_t *)edi;
                                                            if (eax == 0x78 || eax == 0x58) {
                                                                    ebx = edi[0x1];
                                                                    edi = edi + 0x2;
                                                            }
                                                    }
                                            }
                                            esi = ecx[0x32];
                                            temp_1 = (eax | 0xffffffff) % arg_c;
                                            eax = (eax | 0xffffffff) / arg_c;
                                            edx = temp_1;
                                            while (true) {
                                                    ecx = *(int16_t *)(esi + (ebx & 0xff) * 0x2) & 0xffff;
                                                    if ((ecx & 0x4) != 0x0) {
                                                            ecx = sign_extend_32(ebx) - 0x30;
                                                            if (ecx < arg_c) {
                                                                    arg_10 = arg_10 | 0x8;
                                                                    bool_134 = var_4 != eax;
                                                                    if (var_4 < eax) {
                                                                            var_4 = var_4 * arg_c + ecx;
                                                                            ebx = *(int8_t *)edi;
                                                                            edi = edi + 0x1;
                                                                            continue;
                                                                    }
                                                                    if (!bool_134) {
                                                                            if (ecx <= edx) {
                                                                                    var_4 = var_4 * arg_c + ecx;
                                                                                    ebx = *(int8_t *)edi;
                                                                                    edi = edi + 0x1;
                                                                                    continue;
                                                                            }
                                                                            arg_10 = arg_10 | 0x4;
                                                                            if (arg_8 != 0x0) {
                                                                                    ebx = *(int8_t *)edi;
                                                                                    edi = edi + 0x1;
                                                                                    continue;
                                                                            }
                                                                            temp_2 = 0x0;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            arg_10 = arg_10 | 0x4;
                                                                            if (arg_8 != 0x0) {
                                                                                    ebx = *(int8_t *)edi;
                                                                                    edi = edi + 0x1;
                                                                                    continue;
                                                                            }
                                                                            temp_2 = 0x0;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_2 = 0x0;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if ((ecx & 0x103) != 0x0) {
                                                                    ecx = sign_extend_32(ebx);
                                                                    if (ebx <= 0x7a) {
                                                                            ecx = ecx - 0x20;
                                                                    }
                                                                    ecx = ecx - 0x37;
                                                                    if (ecx < arg_c) {
                                                                            arg_10 = arg_10 | 0x8;
                                                                            bool_133 = var_4 != eax;
                                                                            if (var_4 < eax) {
                                                                                    var_4 = var_4 * arg_c + ecx;
                                                                                    ebx = *(int8_t *)edi;
                                                                                    edi = edi + 0x1;
                                                                                    continue;
                                                                            }
                                                                            if (!bool_133) {
                                                                                    if (ecx <= edx) {
                                                                                            var_4 = var_4 * arg_c + ecx;
                                                                                            ebx = *(int8_t *)edi;
                                                                                            edi = edi + 0x1;
                                                                                            continue;
                                                                                    }
                                                                                    arg_10 = arg_10 | 0x4;
                                                                                    if (arg_8 != 0x0) {
                                                                                            ebx = *(int8_t *)edi;
                                                                                            edi = edi + 0x1;
                                                                                            continue;
                                                                                    }
                                                                                    temp_2 = 0x0;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    arg_10 = arg_10 | 0x4;
                                                                                    if (arg_8 != 0x0) {
                                                                                            ebx = *(int8_t *)edi;
                                                                                            edi = edi + 0x1;
                                                                                            continue;
                                                                                    }
                                                                                    temp_2 = 0x0;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_2 = 0x0;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_2 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            eax = arg_10;
                                            edi = edi - 0x1;
                                            if ((eax & 0x8) == 0x0) {
                                                    if (arg_8 != 0x0) {
                                                            edi = arg_4;
                                                    }
                                                    var_4 = var_4 & 0x0;
                                                    eax = arg_8;
                                                    if (eax != 0x0) {
                                                            *eax = edi;
                                                    }
                                                    if ((arg_10 & 0x2) != 0x0) {
                                                            var_4 = -var_4;
                                                    }
                                                    if (var_8 != 0x0) {
                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = var_4;
                                                    esp = esp + 0x4;
                                            }
                                            else {
                                                    if ((eax & 0x4) == 0x0) {
                                                            if ((eax & 0x1) == 0x0) {
                                                                    eax = eax & 0x2;
                                                                    if (eax != 0x0) {
                                                                            if (var_4 <= 0x80000000) {
                                                                                    if (eax == 0x0 && var_4 > 0x7fffffff) {
                                                                                            *sub_47d812() = 0x22;
                                                                                            if ((arg_10 & 0x1) != 0x0) {
                                                                                                    var_4 = var_4 | 0xffffffff;
                                                                                            }
                                                                                            else {
                                                                                                    var_4 = -(-(arg_10 & 0x2) - -(arg_10 & 0x2) + CARRY(EFLAGS(cf))) + 0x7fffffff;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    *sub_47d812() = 0x22;
                                                                                    if ((arg_10 & 0x1) != 0x0) {
                                                                                            var_4 = var_4 | 0xffffffff;
                                                                                    }
                                                                                    else {
                                                                                            var_4 = -(-(arg_10 & 0x2) - -(arg_10 & 0x2) + CARRY(EFLAGS(cf))) + 0x7fffffff;
                                                                                    }
                                                                            }
                                                                            eax = arg_8;
                                                                            if (eax != 0x0) {
                                                                                    *eax = edi;
                                                                            }
                                                                            if ((arg_10 & 0x2) != 0x0) {
                                                                                    var_4 = -var_4;
                                                                            }
                                                                            if (var_8 != 0x0) {
                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                            }
                                                                            eax = var_4;
                                                                            esp = esp + 0x4;
                                                                    }
                                                                    else {
                                                                            if (eax == 0x0 && var_4 > 0x7fffffff) {
                                                                                    *sub_47d812() = 0x22;
                                                                                    if ((arg_10 & 0x1) != 0x0) {
                                                                                            var_4 = var_4 | 0xffffffff;
                                                                                    }
                                                                                    else {
                                                                                            var_4 = -(-(arg_10 & 0x2) - -(arg_10 & 0x2) + CARRY(EFLAGS(cf))) + 0x7fffffff;
                                                                                    }
                                                                            }
                                                                            eax = arg_8;
                                                                            if (eax != 0x0) {
                                                                                    *eax = edi;
                                                                            }
                                                                            if ((arg_10 & 0x2) != 0x0) {
                                                                                    var_4 = -var_4;
                                                                            }
                                                                            if (var_8 != 0x0) {
                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                            }
                                                                            eax = var_4;
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = arg_8;
                                                                    if (eax != 0x0) {
                                                                            *eax = edi;
                                                                    }
                                                                    if ((arg_10 & 0x2) != 0x0) {
                                                                            var_4 = -var_4;
                                                                    }
                                                                    if (var_8 != 0x0) {
                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                    }
                                                                    eax = var_4;
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            *sub_47d812() = 0x22;
                                                            if ((arg_10 & 0x1) != 0x0) {
                                                                    var_4 = var_4 | 0xffffffff;
                                                            }
                                                            else {
                                                                    var_4 = -(-(arg_10 & 0x2) - -(arg_10 & 0x2) + CARRY(EFLAGS(cf))) + 0x7fffffff;
                                                            }
                                                            eax = arg_8;
                                                            if (eax != 0x0) {
                                                                    *eax = edi;
                                                            }
                                                            if ((arg_10 & 0x2) != 0x0) {
                                                                    var_4 = -var_4;
                                                            }
                                                            if (var_8 != 0x0) {
                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                            }
                                                            eax = var_4;
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                    }
                                    else {
                                            eax = arg_8;
                                            if (eax != 0x0) {
                                                    *eax = esi;
                                            }
                                            if (var_8 != 0x0) {
                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                            }
                                            eax = 0x0;
                                            esp = esp + 0x4;
                                    }
                            }
                            else {
                                    eax = arg_8;
                                    if (eax != 0x0) {
                                            *eax = esi;
                                    }
                                    if (var_8 != 0x0) {
                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            eax = arg_8;
                            if (eax != 0x0) {
                                    *eax = esi;
                            }
                            if (var_8 != 0x0) {
                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                            }
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
            }
    }
    return eax;
}
