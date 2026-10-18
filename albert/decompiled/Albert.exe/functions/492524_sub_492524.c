// sub_492524 @ 0x492524
// hopper name: sub_492524
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_492524() {
    edx = arg_8;
    decomp_var_20 = esi;
    esi = arg_0;
    esp = (esp - 0x8) + 0x4;
    var_14 = 0xfffffffe;
    var_1C = edx;
    if (esi == 0xfffffffe) {
            eax = sub_47d825();
            *eax = *eax & 0x0;
            eax = sub_47d812();
            *eax = 0x9;
            eax = eax | 0xffffffff;
    }
    else {
            esp = esp - 0x4;
            decomp_var_24 = edi;
            if (esi >= 0x0) {
                    if (esi >= *dword_bc7228) {
                            *sub_47d825() = 0x0;
                            *sub_47d812() = 0x9;
                            eax = sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = eax | 0xffffffff;
                            esp = esp + 0x4;
                    }
                    else {
                            eax = esi;
                            esi = (esi & 0x1f) * 0x28;
                            esp = esp - 0x4;
                            decomp_var_28 = ebx;
                            ebx = (SAR(eax, 0x5)) * 0x4 + dword_bc7240;
                            eax = *ebx;
                            eax = eax + esi;
                            ecx = eax[0x4];
                            if ((ecx & 0x1) == 0x0) {
                                    *sub_47d825() = 0x0;
                                    *sub_47d812() = 0x9;
                                    eax = sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    eax = eax | 0xffffffff;
                                    esp = esp + 0x4;
                                    esp = esp + 0x4;
                            }
                            else {
                                    var_10 = 0x0;
                                    if (edx != 0x0) {
                                            if ((ecx & 0x2) == 0x0) {
                                                    ecx = arg_4;
                                                    if (ecx != 0x0) {
                                                            eax = eax[0x24];
                                                            var_2 = SAR(eax + eax, 0x1);
                                                            eax = sign_extend_32(SAR(eax + eax, 0x1)) - 0x1;
                                                            if (eax != 0x0) {
                                                                    if (eax == 0x1) {
                                                                            if ((!edx & 0x1) != 0x0) {
                                                                                    arg_8 = edx & 0xfffffffe;
                                                                                    var_C = ecx;
                                                                                    eax = var_C;
                                                                                    edi = esi + *ebx;
                                                                                    if ((edi[0x4] & 0x48) != 0x0) {
                                                                                            ecx = edi[0x5];
                                                                                            if (ecx != 0xa && arg_8 != 0x0) {
                                                                                                    *(int8_t *)eax = ecx;
                                                                                                    eax = eax + 0x1;
                                                                                                    arg_8 = arg_8 - 0x1;
                                                                                                    var_10 = 0x1;
                                                                                                    *(int8_t *)(esi + *ebx + 0x5) = 0xa;
                                                                                                    if (var_2 != 0x0) {
                                                                                                            ecx = *ebx;
                                                                                                            ecx = *(int8_t *)(esi + ecx + 0x25);
                                                                                                            if (ecx != 0xa && arg_8 != 0x0) {
                                                                                                                    *(int8_t *)eax = ecx;
                                                                                                                    eax = eax + 0x1;
                                                                                                                    arg_8 = arg_8 - 0x1;
                                                                                                                    var_10 = 0x2;
                                                                                                                    *(int8_t *)(esi + *ebx + 0x25) = 0xa;
                                                                                                                    if (var_2 == 0x1) {
                                                                                                                            ecx = *ebx;
                                                                                                                            ecx = *(int8_t *)(esi + ecx + 0x26);
                                                                                                                            if (ecx != 0xa) {
                                                                                                                                    if (arg_8 != 0x0) {
                                                                                                                                            *(int8_t *)eax = ecx;
                                                                                                                                            eax = eax + 0x1;
                                                                                                                                            arg_8 = arg_8 - 0x1;
                                                                                                                                            var_10 = 0x3;
                                                                                                                                            *(int8_t *)(esi + *ebx + 0x26) = 0xa;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                    }
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    esp = esp - 0x14;
                                                                                    eax = ReadFile(*(esi + *ebx), eax, arg_8, &var_18, 0x0);
                                                                                    if (eax != 0x0) {
                                                                                            edi = var_18;
                                                                                            if (edi >= 0x0) {
                                                                                                    if (edi <= arg_8) {
                                                                                                            eax = *ebx;
                                                                                                            var_10 = var_10 + edi;
                                                                                                            eax = esi + eax + 0x4;
                                                                                                            if ((*(int8_t *)eax & 0x80) != 0x0) {
                                                                                                                    if (var_2 != 0x2) {
                                                                                                                            if (edi != 0x0 && *(int8_t *)var_C == 0xa) {
                                                                                                                                    *(int8_t *)eax = *(int8_t *)eax | 0x4;
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    *(int8_t *)eax = *(int8_t *)eax & 0xfb;
                                                                                                                            }
                                                                                                                            edi = var_C;
                                                                                                                            bool_112 = edi >= var_10 + edi;
                                                                                                                            arg_8 = edi;
                                                                                                                            var_10 = var_10 + edi;
                                                                                                                            if (!bool_112) {
                                                                                                                                    while (true) {
                                                                                                                                            ecx = arg_8;
                                                                                                                                            eax = *(int8_t *)ecx;
                                                                                                                                            if (eax == 0x1a) {
                                                                                                                                                    eax = *ebx;
                                                                                                                                                    eax = esi + eax + 0x4;
                                                                                                                                                    if ((*(int8_t *)eax & 0x40) == 0x0) {
                                                                                                                                                            *(int8_t *)eax = *(int8_t *)eax | 0x2;
                                                                                                                                                            temp_0 = 0x1;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            *(int8_t *)edi = *(int8_t *)ecx;
                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                            temp_0 = 0x2;
                                                                                                                                                    }
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                            if (eax != 0xd) {
                                                                                                                                                    *(int8_t *)edi = eax;
                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                    arg_8 = ecx + 0x1;
                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    if (ecx < var_10 - 0x1) {
                                                                                                                                                            eax = ecx + 0x1;
                                                                                                                                                            if (*(int8_t *)eax == 0xa) {
                                                                                                                                                                    arg_8 = ecx + 0x2;
                                                                                                                                                                    *(int8_t *)edi = 0xa;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    arg_8 = eax;
                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                            }
                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            arg_8 = arg_8 + 0x1;
                                                                                                                                                            esp = esp - 0x14;
                                                                                                                                                            eax = ReadFile(*(esi + *ebx), &var_1, 0x1, &var_18, 0x0);
                                                                                                                                                            if (eax == 0x0) {
                                                                                                                                                                    if (GetLastError() == 0x0) {
                                                                                                                                                                            if (var_18 != 0x0) {
                                                                                                                                                                                    if ((*(int8_t *)(esi + *ebx + 0x4) & 0x48) != 0x0) {
                                                                                                                                                                                            if (var_1 != 0xa) {
                                                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x5) = var_1;
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    *(int8_t *)edi = 0xa;
                                                                                                                                                                                            }
                                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                    continue;
                                                                                                                                                                                            }
                                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                                            break;
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            if (edi == var_C) {
                                                                                                                                                                                                    if (var_1 != 0xa) {
                                                                                                                                                                                                            sub_48df70(arg_0, 0xffffffff, 0xffffffff, 0x1);
                                                                                                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                                            if (var_1 != 0xa) {
                                                                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                                    continue;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                                                            break;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    else {
                                                                                                                                                                                                            *(int8_t *)edi = 0xa;
                                                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                                    continue;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                                                            break;
                                                                                                                                                                                                    }
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    sub_48df70(arg_0, 0xffffffff, 0xffffffff, 0x1);
                                                                                                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                                    if (var_1 != 0xa) {
                                                                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                            continue;
                                                                                                                                                                                    }
                                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                                    break;
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    if (var_18 != 0x0) {
                                                                                                                                                                            if ((*(int8_t *)(esi + *ebx + 0x4) & 0x48) != 0x0) {
                                                                                                                                                                                    if (var_1 != 0xa) {
                                                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                                                            *(int8_t *)(esi + *ebx + 0x5) = var_1;
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            *(int8_t *)edi = 0xa;
                                                                                                                                                                                    }
                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                            continue;
                                                                                                                                                                                    }
                                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                                    break;
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    if (edi == var_C) {
                                                                                                                                                                                            if (var_1 != 0xa) {
                                                                                                                                                                                                    sub_48df70(arg_0, 0xffffffff, 0xffffffff, 0x1);
                                                                                                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                                    if (var_1 != 0xa) {
                                                                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    *(int8_t *)edi = 0xa;
                                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            sub_48df70(arg_0, 0xffffffff, 0xffffffff, 0x1);
                                                                                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                            if (var_1 != 0xa) {
                                                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                                            }
                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                    continue;
                                                                                                                                                                                            }
                                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                                            break;
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            eax = edi - var_C;
                                                                                                                            var_10 = eax;
                                                                                                                            if (var_2 == 0x1) {
                                                                                                                                    if (eax != 0x0) {
                                                                                                                                            edi = edi - 0x1;
                                                                                                                                            ecx = *(int8_t *)edi;
                                                                                                                                            if (ecx >= 0x0) {
                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                    esp = esp - 0x18;
                                                                                                                                                    eax = MultiByteToWideChar(0xfde9, 0x0, var_C, edi - var_C, arg_4, var_1C >> 0x1);
                                                                                                                                                    var_10 = eax;
                                                                                                                                                    if (eax == 0x0) {
                                                                                                                                                            eax = GetLastError();
                                                                                                                                                            sub_47d838(eax);
                                                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                                                            var_14 = var_14 | 0xffffffff;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            var_10 = eax + eax;
                                                                                                                                                    }
                                                                                                                                                    eax = var_C;
                                                                                                                                                    if (eax != arg_4) {
                                                                                                                                                            sub_47c8f9();
                                                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                                                    }
                                                                                                                                                    eax = var_14;
                                                                                                                                                    if (eax == 0xfffffffe) {
                                                                                                                                                            eax = var_10;
                                                                                                                                                    }
                                                                                                                                                    esp = esp + 0x4;
                                                                                                                                                    esp = esp + 0x4;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    eax = 0x1;
                                                                                                                                                    ecx = ecx & 0xff;
                                                                                                                                                    while (true) {
                                                                                                                                                            if (ecx[0x4ca0b8] != 0x0) {
                                                                                                                                                                    temp_2 = 0x0;
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    if (eax <= 0x4) {
                                                                                                                                                                            if (edi >= var_C) {
                                                                                                                                                                                    edi = edi - 0x1;
                                                                                                                                                                                    ecx = *(int8_t *)edi & 0xff;
                                                                                                                                                                                    eax = eax + 0x1;
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            temp_2 = 0x1;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            temp_2 = 0x0;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    edx = *(int8_t *)edi;
                                                                                                                                                    ecx = sign_extend_32(*(int8_t *)((edx & 0xff) + 0x4ca0b8));
                                                                                                                                                    if (ecx == 0x0) {
                                                                                                                                                            *sub_47d812() = 0x2a;
                                                                                                                                                            var_14 = var_14 | 0xffffffff;
                                                                                                                                                            eax = var_C;
                                                                                                                                                            if (eax != arg_4) {
                                                                                                                                                                    sub_47c8f9();
                                                                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                                                            }
                                                                                                                                                            eax = var_14;
                                                                                                                                                            if (eax == 0xfffffffe) {
                                                                                                                                                                    eax = var_10;
                                                                                                                                                            }
                                                                                                                                                            esp = esp + 0x4;
                                                                                                                                                            esp = esp + 0x4;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            if (ecx + 0x1 == eax) {
                                                                                                                                                                    edi = edi + eax;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    ecx = *ebx;
                                                                                                                                                                    ecx = ecx + esi;
                                                                                                                                                                    if ((ecx[0x4] & 0x48) != 0x0) {
                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                            ecx[0x5] = edx;
                                                                                                                                                                            if (eax >= 0x2) {
                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x25) = *(int8_t *)edi;
                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                            }
                                                                                                                                                                            if (eax == 0x3) {
                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x26) = *(int8_t *)edi;
                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                            }
                                                                                                                                                                            edi = edi - eax;
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            sub_48df70(arg_0, -eax, -eax & 0x80000000 ? 0xffffffff : 0x0, 0x1);
                                                                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            esp = esp - 0x18;
                                                                                                                                                            eax = MultiByteToWideChar(0xfde9, 0x0, var_C, edi - var_C, arg_4, var_1C >> 0x1);
                                                                                                                                                            var_10 = eax;
                                                                                                                                                            if (eax == 0x0) {
                                                                                                                                                                    eax = GetLastError();
                                                                                                                                                                    sub_47d838(eax);
                                                                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                                                                    var_14 = var_14 | 0xffffffff;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    var_10 = eax + eax;
                                                                                                                                                            }
                                                                                                                                                            eax = var_C;
                                                                                                                                                            if (eax != arg_4) {
                                                                                                                                                                    sub_47c8f9();
                                                                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                                                            }
                                                                                                                                                            eax = var_14;
                                                                                                                                                            if (eax == 0xfffffffe) {
                                                                                                                                                                    eax = var_10;
                                                                                                                                                            }
                                                                                                                                                            esp = esp + 0x4;
                                                                                                                                                            esp = esp + 0x4;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            eax = var_C;
                                                                                                                                            if (eax != arg_4) {
                                                                                                                                                    sub_47c8f9();
                                                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                                            }
                                                                                                                                            eax = var_14;
                                                                                                                                            if (eax == 0xfffffffe) {
                                                                                                                                                    eax = var_10;
                                                                                                                                            }
                                                                                                                                            esp = esp + 0x4;
                                                                                                                                            esp = esp + 0x4;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    eax = var_C;
                                                                                                                                    if (eax != arg_4) {
                                                                                                                                            sub_47c8f9();
                                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                                    }
                                                                                                                                    eax = var_14;
                                                                                                                                    if (eax == 0xfffffffe) {
                                                                                                                                            eax = var_10;
                                                                                                                                    }
                                                                                                                                    esp = esp + 0x4;
                                                                                                                                    esp = esp + 0x4;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            if (edi != 0x0 && *(int16_t *)var_C == 0xa) {
                                                                                                                                    *(int8_t *)eax = *(int8_t *)eax | 0x4;
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    *(int8_t *)eax = *(int8_t *)eax & 0xfb;
                                                                                                                            }
                                                                                                                            edi = var_C;
                                                                                                                            bool_78 = edi >= var_10 + edi;
                                                                                                                            arg_8 = edi;
                                                                                                                            var_10 = var_10 + edi;
                                                                                                                            if (!bool_78) {
                                                                                                                                    while (true) {
                                                                                                                                            eax = arg_8;
                                                                                                                                            ecx = *(int16_t *)eax & 0xffff;
                                                                                                                                            if (ecx == 0x1a) {
                                                                                                                                                    esi = esi + *ebx + 0x4;
                                                                                                                                                    if ((*(int8_t *)esi & 0x40) == 0x0) {
                                                                                                                                                            *(int8_t *)esi = *(int8_t *)esi | 0x2;
                                                                                                                                                            temp_1 = 0x1;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            *(int16_t *)edi = *(int16_t *)eax;
                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                            temp_1 = 0x2;
                                                                                                                                                    }
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                            if (ecx != 0xd) {
                                                                                                                                                    *(int16_t *)edi = ecx;
                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                    arg_8 = eax + 0x2;
                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    if (eax < var_10 - 0x2) {
                                                                                                                                                            ecx = eax + 0x2;
                                                                                                                                                            if (*(int16_t *)ecx == 0xa) {
                                                                                                                                                                    arg_8 = eax + 0x4;
                                                                                                                                                                    *(int16_t *)edi = 0xa;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    arg_8 = ecx;
                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                            }
                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            arg_8 = arg_8 + 0x2;
                                                                                                                                                            esp = esp - 0x14;
                                                                                                                                                            eax = ReadFile(*(esi + *ebx), &var_8, 0x2, &var_18, 0x0);
                                                                                                                                                            if (eax == 0x0) {
                                                                                                                                                                    if (GetLastError() == 0x0) {
                                                                                                                                                                            if (var_18 != 0x0) {
                                                                                                                                                                                    if ((*(int8_t *)(esi + *ebx + 0x4) & 0x48) != 0x0) {
                                                                                                                                                                                            if (var_8 != 0xa) {
                                                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x5) = var_8;
                                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x25) = var_7;
                                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x26) = 0xa;
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    *(int16_t *)edi = 0xa;
                                                                                                                                                                                            }
                                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                    continue;
                                                                                                                                                                                            }
                                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                                            break;
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            if (edi == var_C) {
                                                                                                                                                                                                    if (var_8 != 0xa) {
                                                                                                                                                                                                            sub_48df70(arg_0, 0xfffffffe, 0xffffffff, 0x1);
                                                                                                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                                            if (var_8 != 0xa) {
                                                                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                                    continue;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                                                            break;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    else {
                                                                                                                                                                                                            *(int16_t *)edi = 0xa;
                                                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                                    continue;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                                                            break;
                                                                                                                                                                                                    }
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    sub_48df70(arg_0, 0xfffffffe, 0xffffffff, 0x1);
                                                                                                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                                    if (var_8 != 0xa) {
                                                                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                            continue;
                                                                                                                                                                                    }
                                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                                    break;
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    if (var_18 != 0x0) {
                                                                                                                                                                            if ((*(int8_t *)(esi + *ebx + 0x4) & 0x48) != 0x0) {
                                                                                                                                                                                    if (var_8 != 0xa) {
                                                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                                                            *(int8_t *)(esi + *ebx + 0x5) = var_8;
                                                                                                                                                                                            *(int8_t *)(esi + *ebx + 0x25) = var_7;
                                                                                                                                                                                            *(int8_t *)(esi + *ebx + 0x26) = 0xa;
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            *(int16_t *)edi = 0xa;
                                                                                                                                                                                    }
                                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                            continue;
                                                                                                                                                                                    }
                                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                                    break;
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    if (edi == var_C) {
                                                                                                                                                                                            if (var_8 != 0xa) {
                                                                                                                                                                                                    sub_48df70(arg_0, 0xfffffffe, 0xffffffff, 0x1);
                                                                                                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                                    if (var_8 != 0xa) {
                                                                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    *(int16_t *)edi = 0xa;
                                                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            sub_48df70(arg_0, 0xfffffffe, 0xffffffff, 0x1);
                                                                                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                            if (var_8 != 0xa) {
                                                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                                            }
                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                    continue;
                                                                                                                                                                                            }
                                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                                            break;
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            var_10 = edi - var_C;
                                                                                                                            eax = var_C;
                                                                                                                            if (eax != arg_4) {
                                                                                                                                    sub_47c8f9();
                                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                            }
                                                                                                                            eax = var_14;
                                                                                                                            if (eax == 0xfffffffe) {
                                                                                                                                    eax = var_10;
                                                                                                                            }
                                                                                                                            esp = esp + 0x4;
                                                                                                                            esp = esp + 0x4;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    eax = var_C;
                                                                                                                    if (eax != arg_4) {
                                                                                                                            sub_47c8f9();
                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                    }
                                                                                                                    eax = var_14;
                                                                                                                    if (eax == 0xfffffffe) {
                                                                                                                            eax = var_10;
                                                                                                                    }
                                                                                                                    esp = esp + 0x4;
                                                                                                                    esp = esp + 0x4;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = GetLastError();
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            if (eax == 0x5) {
                                                                                                                    *sub_47d812() = 0x9;
                                                                                                                    *sub_47d825() = 0x5;
                                                                                                                    var_14 = var_14 | 0xffffffff;
                                                                                                            }
                                                                                                            else {
                                                                                                                    if (eax == 0x6d) {
                                                                                                                            var_14 = var_14 & 0x0;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            sub_47d838(eax);
                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                            var_14 = var_14 | 0xffffffff;
                                                                                                                    }
                                                                                                            }
                                                                                                            eax = var_C;
                                                                                                            if (eax != arg_4) {
                                                                                                                    sub_47c8f9();
                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                            }
                                                                                                            eax = var_14;
                                                                                                            if (eax == 0xfffffffe) {
                                                                                                                    eax = var_10;
                                                                                                            }
                                                                                                            esp = esp + 0x4;
                                                                                                            esp = esp + 0x4;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    eax = GetLastError();
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    if (eax == 0x5) {
                                                                                                            *sub_47d812() = 0x9;
                                                                                                            *sub_47d825() = 0x5;
                                                                                                            var_14 = var_14 | 0xffffffff;
                                                                                                    }
                                                                                                    else {
                                                                                                            if (eax == 0x6d) {
                                                                                                                    var_14 = var_14 & 0x0;
                                                                                                            }
                                                                                                            else {
                                                                                                                    sub_47d838(eax);
                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                    var_14 = var_14 | 0xffffffff;
                                                                                                            }
                                                                                                    }
                                                                                                    eax = var_C;
                                                                                                    if (eax != arg_4) {
                                                                                                            sub_47c8f9();
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                    }
                                                                                                    eax = var_14;
                                                                                                    if (eax == 0xfffffffe) {
                                                                                                            eax = var_10;
                                                                                                    }
                                                                                                    esp = esp + 0x4;
                                                                                                    esp = esp + 0x4;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            eax = GetLastError();
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            if (eax == 0x5) {
                                                                                                    *sub_47d812() = 0x9;
                                                                                                    *sub_47d825() = 0x5;
                                                                                                    var_14 = var_14 | 0xffffffff;
                                                                                            }
                                                                                            else {
                                                                                                    if (eax == 0x6d) {
                                                                                                            var_14 = var_14 & 0x0;
                                                                                                    }
                                                                                                    else {
                                                                                                            sub_47d838(eax);
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            var_14 = var_14 | 0xffffffff;
                                                                                                    }
                                                                                            }
                                                                                            eax = var_C;
                                                                                            if (eax != arg_4) {
                                                                                                    sub_47c8f9();
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                            }
                                                                                            eax = var_14;
                                                                                            if (eax == 0xfffffffe) {
                                                                                                    eax = var_10;
                                                                                            }
                                                                                            esp = esp + 0x4;
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    *sub_47d825() = 0x0;
                                                                                    *sub_47d812() = 0x16;
                                                                                    eax = sub_47a924();
                                                                                    esp = (esp - 0x14) + 0x14;
                                                                                    eax = eax | 0xffffffff;
                                                                                    esp = esp + 0x4;
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            var_C = ecx;
                                                                            eax = var_C;
                                                                            edi = esi + *ebx;
                                                                            if ((edi[0x4] & 0x48) != 0x0) {
                                                                                    ecx = edi[0x5];
                                                                                    if (ecx != 0xa && arg_8 != 0x0) {
                                                                                            *(int8_t *)eax = ecx;
                                                                                            eax = eax + 0x1;
                                                                                            arg_8 = arg_8 - 0x1;
                                                                                            var_10 = 0x1;
                                                                                            *(int8_t *)(esi + *ebx + 0x5) = 0xa;
                                                                                            if (var_2 != 0x0) {
                                                                                                    ecx = *ebx;
                                                                                                    ecx = *(int8_t *)(esi + ecx + 0x25);
                                                                                                    if (ecx != 0xa && arg_8 != 0x0) {
                                                                                                            *(int8_t *)eax = ecx;
                                                                                                            eax = eax + 0x1;
                                                                                                            arg_8 = arg_8 - 0x1;
                                                                                                            var_10 = 0x2;
                                                                                                            *(int8_t *)(esi + *ebx + 0x25) = 0xa;
                                                                                                            if (var_2 == 0x1) {
                                                                                                                    ecx = *ebx;
                                                                                                                    ecx = *(int8_t *)(esi + ecx + 0x26);
                                                                                                                    if (ecx != 0xa) {
                                                                                                                            if (arg_8 != 0x0) {
                                                                                                                                    *(int8_t *)eax = ecx;
                                                                                                                                    eax = eax + 0x1;
                                                                                                                                    arg_8 = arg_8 - 0x1;
                                                                                                                                    var_10 = 0x3;
                                                                                                                                    *(int8_t *)(esi + *ebx + 0x26) = 0xa;
                                                                                                                            }
                                                                                                                    }
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                            esp = esp - 0x14;
                                                                            eax = ReadFile(*(esi + *ebx), eax, arg_8, &var_18, 0x0);
                                                                            if (eax != 0x0) {
                                                                                    edi = var_18;
                                                                                    if (edi >= 0x0) {
                                                                                            if (edi <= arg_8) {
                                                                                                    eax = *ebx;
                                                                                                    var_10 = var_10 + edi;
                                                                                                    eax = esi + eax + 0x4;
                                                                                                    if ((*(int8_t *)eax & 0x80) != 0x0) {
                                                                                                            if (var_2 != 0x2) {
                                                                                                                    if (edi != 0x0 && *(int8_t *)var_C == 0xa) {
                                                                                                                            *(int8_t *)eax = *(int8_t *)eax | 0x4;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            *(int8_t *)eax = *(int8_t *)eax & 0xfb;
                                                                                                                    }
                                                                                                                    edi = var_C;
                                                                                                                    bool_46 = edi >= var_10 + edi;
                                                                                                                    arg_8 = edi;
                                                                                                                    var_10 = var_10 + edi;
                                                                                                                    if (!bool_46) {
                                                                                                                            while (true) {
                                                                                                                                    ecx = arg_8;
                                                                                                                                    eax = *(int8_t *)ecx;
                                                                                                                                    if (eax == 0x1a) {
                                                                                                                                            eax = *ebx;
                                                                                                                                            eax = esi + eax + 0x4;
                                                                                                                                            if ((*(int8_t *)eax & 0x40) == 0x0) {
                                                                                                                                                    *(int8_t *)eax = *(int8_t *)eax | 0x2;
                                                                                                                                                    temp_0 = 0x1;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    *(int8_t *)edi = *(int8_t *)ecx;
                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                    temp_0 = 0x2;
                                                                                                                                            }
                                                                                                                                            break;
                                                                                                                                    }
                                                                                                                                    if (eax != 0xd) {
                                                                                                                                            *(int8_t *)edi = eax;
                                                                                                                                            edi = edi + 0x1;
                                                                                                                                            arg_8 = ecx + 0x1;
                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                    continue;
                                                                                                                                            }
                                                                                                                                            temp_0 = 0x0;
                                                                                                                                            break;
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            if (ecx < var_10 - 0x1) {
                                                                                                                                                    eax = ecx + 0x1;
                                                                                                                                                    if (*(int8_t *)eax == 0xa) {
                                                                                                                                                            arg_8 = ecx + 0x2;
                                                                                                                                                            *(int8_t *)edi = 0xa;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            arg_8 = eax;
                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                    }
                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    arg_8 = arg_8 + 0x1;
                                                                                                                                                    esp = esp - 0x14;
                                                                                                                                                    eax = ReadFile(*(esi + *ebx), &var_1, 0x1, &var_18, 0x0);
                                                                                                                                                    if (eax == 0x0) {
                                                                                                                                                            if (GetLastError() == 0x0) {
                                                                                                                                                                    if (var_18 != 0x0) {
                                                                                                                                                                            if ((*(int8_t *)(esi + *ebx + 0x4) & 0x48) != 0x0) {
                                                                                                                                                                                    if (var_1 != 0xa) {
                                                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                                                            *(int8_t *)(esi + *ebx + 0x5) = var_1;
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            *(int8_t *)edi = 0xa;
                                                                                                                                                                                    }
                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                            continue;
                                                                                                                                                                                    }
                                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                                    break;
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    if (edi == var_C) {
                                                                                                                                                                                            if (var_1 != 0xa) {
                                                                                                                                                                                                    sub_48df70(arg_0, 0xffffffff, 0xffffffff, 0x1);
                                                                                                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                                    if (var_1 != 0xa) {
                                                                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    *(int8_t *)edi = 0xa;
                                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            sub_48df70(arg_0, 0xffffffff, 0xffffffff, 0x1);
                                                                                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                            if (var_1 != 0xa) {
                                                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                                            }
                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                    continue;
                                                                                                                                                                                            }
                                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                                            break;
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            if (var_18 != 0x0) {
                                                                                                                                                                    if ((*(int8_t *)(esi + *ebx + 0x4) & 0x48) != 0x0) {
                                                                                                                                                                            if (var_1 != 0xa) {
                                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x5) = var_1;
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    *(int8_t *)edi = 0xa;
                                                                                                                                                                            }
                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            if (edi == var_C) {
                                                                                                                                                                                    if (var_1 != 0xa) {
                                                                                                                                                                                            sub_48df70(arg_0, 0xffffffff, 0xffffffff, 0x1);
                                                                                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                            if (var_1 != 0xa) {
                                                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                                            }
                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                    continue;
                                                                                                                                                                                            }
                                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                                            break;
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            *(int8_t *)edi = 0xa;
                                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                    continue;
                                                                                                                                                                                            }
                                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                                            break;
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    sub_48df70(arg_0, 0xffffffff, 0xffffffff, 0x1);
                                                                                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                    if (var_1 != 0xa) {
                                                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                                    }
                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                            continue;
                                                                                                                                                                                    }
                                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                                    break;
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                            }
                                                                                                                    }
                                                                                                                    eax = edi - var_C;
                                                                                                                    var_10 = eax;
                                                                                                                    if (var_2 == 0x1) {
                                                                                                                            if (eax != 0x0) {
                                                                                                                                    edi = edi - 0x1;
                                                                                                                                    ecx = *(int8_t *)edi;
                                                                                                                                    if (ecx >= 0x0) {
                                                                                                                                            edi = edi + 0x1;
                                                                                                                                            esp = esp - 0x18;
                                                                                                                                            eax = MultiByteToWideChar(0xfde9, 0x0, var_C, edi - var_C, arg_4, var_1C >> 0x1);
                                                                                                                                            var_10 = eax;
                                                                                                                                            if (eax == 0x0) {
                                                                                                                                                    eax = GetLastError();
                                                                                                                                                    sub_47d838(eax);
                                                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                                                    var_14 = var_14 | 0xffffffff;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    var_10 = eax + eax;
                                                                                                                                            }
                                                                                                                                            eax = var_C;
                                                                                                                                            if (eax != arg_4) {
                                                                                                                                                    sub_47c8f9();
                                                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                                            }
                                                                                                                                            eax = var_14;
                                                                                                                                            if (eax == 0xfffffffe) {
                                                                                                                                                    eax = var_10;
                                                                                                                                            }
                                                                                                                                            esp = esp + 0x4;
                                                                                                                                            esp = esp + 0x4;
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            eax = 0x1;
                                                                                                                                            ecx = ecx & 0xff;
                                                                                                                                            while (true) {
                                                                                                                                                    if (ecx[0x4ca0b8] != 0x0) {
                                                                                                                                                            temp_2 = 0x0;
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            if (eax <= 0x4) {
                                                                                                                                                                    if (edi >= var_C) {
                                                                                                                                                                            edi = edi - 0x1;
                                                                                                                                                                            ecx = *(int8_t *)edi & 0xff;
                                                                                                                                                                            eax = eax + 0x1;
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    temp_2 = 0x1;
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    temp_2 = 0x0;
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                            edx = *(int8_t *)edi;
                                                                                                                                            ecx = sign_extend_32(*(int8_t *)((edx & 0xff) + 0x4ca0b8));
                                                                                                                                            if (ecx == 0x0) {
                                                                                                                                                    *sub_47d812() = 0x2a;
                                                                                                                                                    var_14 = var_14 | 0xffffffff;
                                                                                                                                                    eax = var_C;
                                                                                                                                                    if (eax != arg_4) {
                                                                                                                                                            sub_47c8f9();
                                                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                                                    }
                                                                                                                                                    eax = var_14;
                                                                                                                                                    if (eax == 0xfffffffe) {
                                                                                                                                                            eax = var_10;
                                                                                                                                                    }
                                                                                                                                                    esp = esp + 0x4;
                                                                                                                                                    esp = esp + 0x4;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    if (ecx + 0x1 == eax) {
                                                                                                                                                            edi = edi + eax;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            ecx = *ebx;
                                                                                                                                                            ecx = ecx + esi;
                                                                                                                                                            if ((ecx[0x4] & 0x48) != 0x0) {
                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                    ecx[0x5] = edx;
                                                                                                                                                                    if (eax >= 0x2) {
                                                                                                                                                                            *(int8_t *)(esi + *ebx + 0x25) = *(int8_t *)edi;
                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                    }
                                                                                                                                                                    if (eax == 0x3) {
                                                                                                                                                                            *(int8_t *)(esi + *ebx + 0x26) = *(int8_t *)edi;
                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                    }
                                                                                                                                                                    edi = edi - eax;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    sub_48df70(arg_0, -eax, -eax & 0x80000000 ? 0xffffffff : 0x0, 0x1);
                                                                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    esp = esp - 0x18;
                                                                                                                                                    eax = MultiByteToWideChar(0xfde9, 0x0, var_C, edi - var_C, arg_4, var_1C >> 0x1);
                                                                                                                                                    var_10 = eax;
                                                                                                                                                    if (eax == 0x0) {
                                                                                                                                                            eax = GetLastError();
                                                                                                                                                            sub_47d838(eax);
                                                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                                                            var_14 = var_14 | 0xffffffff;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            var_10 = eax + eax;
                                                                                                                                                    }
                                                                                                                                                    eax = var_C;
                                                                                                                                                    if (eax != arg_4) {
                                                                                                                                                            sub_47c8f9();
                                                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                                                    }
                                                                                                                                                    eax = var_14;
                                                                                                                                                    if (eax == 0xfffffffe) {
                                                                                                                                                            eax = var_10;
                                                                                                                                                    }
                                                                                                                                                    esp = esp + 0x4;
                                                                                                                                                    esp = esp + 0x4;
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    eax = var_C;
                                                                                                                                    if (eax != arg_4) {
                                                                                                                                            sub_47c8f9();
                                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                                    }
                                                                                                                                    eax = var_14;
                                                                                                                                    if (eax == 0xfffffffe) {
                                                                                                                                            eax = var_10;
                                                                                                                                    }
                                                                                                                                    esp = esp + 0x4;
                                                                                                                                    esp = esp + 0x4;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            eax = var_C;
                                                                                                                            if (eax != arg_4) {
                                                                                                                                    sub_47c8f9();
                                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                            }
                                                                                                                            eax = var_14;
                                                                                                                            if (eax == 0xfffffffe) {
                                                                                                                                    eax = var_10;
                                                                                                                            }
                                                                                                                            esp = esp + 0x4;
                                                                                                                            esp = esp + 0x4;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    if (edi != 0x0 && *(int16_t *)var_C == 0xa) {
                                                                                                                            *(int8_t *)eax = *(int8_t *)eax | 0x4;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            *(int8_t *)eax = *(int8_t *)eax & 0xfb;
                                                                                                                    }
                                                                                                                    edi = var_C;
                                                                                                                    bool_164 = edi >= var_10 + edi;
                                                                                                                    arg_8 = edi;
                                                                                                                    var_10 = var_10 + edi;
                                                                                                                    if (!bool_164) {
                                                                                                                            while (true) {
                                                                                                                                    eax = arg_8;
                                                                                                                                    ecx = *(int16_t *)eax & 0xffff;
                                                                                                                                    if (ecx == 0x1a) {
                                                                                                                                            esi = esi + *ebx + 0x4;
                                                                                                                                            if ((*(int8_t *)esi & 0x40) == 0x0) {
                                                                                                                                                    *(int8_t *)esi = *(int8_t *)esi | 0x2;
                                                                                                                                                    temp_1 = 0x1;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    *(int16_t *)edi = *(int16_t *)eax;
                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                    temp_1 = 0x2;
                                                                                                                                            }
                                                                                                                                            break;
                                                                                                                                    }
                                                                                                                                    if (ecx != 0xd) {
                                                                                                                                            *(int16_t *)edi = ecx;
                                                                                                                                            edi = edi + 0x2;
                                                                                                                                            arg_8 = eax + 0x2;
                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                    continue;
                                                                                                                                            }
                                                                                                                                            temp_1 = 0x0;
                                                                                                                                            break;
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            if (eax < var_10 - 0x2) {
                                                                                                                                                    ecx = eax + 0x2;
                                                                                                                                                    if (*(int16_t *)ecx == 0xa) {
                                                                                                                                                            arg_8 = eax + 0x4;
                                                                                                                                                            *(int16_t *)edi = 0xa;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            arg_8 = ecx;
                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                    }
                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    arg_8 = arg_8 + 0x2;
                                                                                                                                                    esp = esp - 0x14;
                                                                                                                                                    eax = ReadFile(*(esi + *ebx), &var_8, 0x2, &var_18, 0x0);
                                                                                                                                                    if (eax == 0x0) {
                                                                                                                                                            if (GetLastError() == 0x0) {
                                                                                                                                                                    if (var_18 != 0x0) {
                                                                                                                                                                            if ((*(int8_t *)(esi + *ebx + 0x4) & 0x48) != 0x0) {
                                                                                                                                                                                    if (var_8 != 0xa) {
                                                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                                                            *(int8_t *)(esi + *ebx + 0x5) = var_8;
                                                                                                                                                                                            *(int8_t *)(esi + *ebx + 0x25) = var_7;
                                                                                                                                                                                            *(int8_t *)(esi + *ebx + 0x26) = 0xa;
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            *(int16_t *)edi = 0xa;
                                                                                                                                                                                    }
                                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                            continue;
                                                                                                                                                                                    }
                                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                                    break;
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    if (edi == var_C) {
                                                                                                                                                                                            if (var_8 != 0xa) {
                                                                                                                                                                                                    sub_48df70(arg_0, 0xfffffffe, 0xffffffff, 0x1);
                                                                                                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                                    if (var_8 != 0xa) {
                                                                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    *(int16_t *)edi = 0xa;
                                                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            sub_48df70(arg_0, 0xfffffffe, 0xffffffff, 0x1);
                                                                                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                            if (var_8 != 0xa) {
                                                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                                            }
                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                    continue;
                                                                                                                                                                                            }
                                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                                            break;
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            if (var_18 != 0x0) {
                                                                                                                                                                    if ((*(int8_t *)(esi + *ebx + 0x4) & 0x48) != 0x0) {
                                                                                                                                                                            if (var_8 != 0xa) {
                                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x5) = var_8;
                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x25) = var_7;
                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x26) = 0xa;
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    *(int16_t *)edi = 0xa;
                                                                                                                                                                            }
                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            if (edi == var_C) {
                                                                                                                                                                                    if (var_8 != 0xa) {
                                                                                                                                                                                            sub_48df70(arg_0, 0xfffffffe, 0xffffffff, 0x1);
                                                                                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                            if (var_8 != 0xa) {
                                                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                                            }
                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                    continue;
                                                                                                                                                                                            }
                                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                                            break;
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            *(int16_t *)edi = 0xa;
                                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                    continue;
                                                                                                                                                                                            }
                                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                                            break;
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    sub_48df70(arg_0, 0xfffffffe, 0xffffffff, 0x1);
                                                                                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                    if (var_8 != 0xa) {
                                                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                                    }
                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                            continue;
                                                                                                                                                                                    }
                                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                                    break;
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                            continue;
                                                                                                                                                                    }
                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                            }
                                                                                                                    }
                                                                                                                    var_10 = edi - var_C;
                                                                                                                    eax = var_C;
                                                                                                                    if (eax != arg_4) {
                                                                                                                            sub_47c8f9();
                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                    }
                                                                                                                    eax = var_14;
                                                                                                                    if (eax == 0xfffffffe) {
                                                                                                                            eax = var_10;
                                                                                                                    }
                                                                                                                    esp = esp + 0x4;
                                                                                                                    esp = esp + 0x4;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = var_C;
                                                                                                            if (eax != arg_4) {
                                                                                                                    sub_47c8f9();
                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                            }
                                                                                                            eax = var_14;
                                                                                                            if (eax == 0xfffffffe) {
                                                                                                                    eax = var_10;
                                                                                                            }
                                                                                                            esp = esp + 0x4;
                                                                                                            esp = esp + 0x4;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    eax = GetLastError();
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    if (eax == 0x5) {
                                                                                                            *sub_47d812() = 0x9;
                                                                                                            *sub_47d825() = 0x5;
                                                                                                            var_14 = var_14 | 0xffffffff;
                                                                                                    }
                                                                                                    else {
                                                                                                            if (eax == 0x6d) {
                                                                                                                    var_14 = var_14 & 0x0;
                                                                                                            }
                                                                                                            else {
                                                                                                                    sub_47d838(eax);
                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                    var_14 = var_14 | 0xffffffff;
                                                                                                            }
                                                                                                    }
                                                                                                    eax = var_C;
                                                                                                    if (eax != arg_4) {
                                                                                                            sub_47c8f9();
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                    }
                                                                                                    eax = var_14;
                                                                                                    if (eax == 0xfffffffe) {
                                                                                                            eax = var_10;
                                                                                                    }
                                                                                                    esp = esp + 0x4;
                                                                                                    esp = esp + 0x4;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            eax = GetLastError();
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            if (eax == 0x5) {
                                                                                                    *sub_47d812() = 0x9;
                                                                                                    *sub_47d825() = 0x5;
                                                                                                    var_14 = var_14 | 0xffffffff;
                                                                                            }
                                                                                            else {
                                                                                                    if (eax == 0x6d) {
                                                                                                            var_14 = var_14 & 0x0;
                                                                                                    }
                                                                                                    else {
                                                                                                            sub_47d838(eax);
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            var_14 = var_14 | 0xffffffff;
                                                                                                    }
                                                                                            }
                                                                                            eax = var_C;
                                                                                            if (eax != arg_4) {
                                                                                                    sub_47c8f9();
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                            }
                                                                                            eax = var_14;
                                                                                            if (eax == 0xfffffffe) {
                                                                                                    eax = var_10;
                                                                                            }
                                                                                            esp = esp + 0x4;
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = GetLastError();
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    if (eax == 0x5) {
                                                                                            *sub_47d812() = 0x9;
                                                                                            *sub_47d825() = 0x5;
                                                                                            var_14 = var_14 | 0xffffffff;
                                                                                    }
                                                                                    else {
                                                                                            if (eax == 0x6d) {
                                                                                                    var_14 = var_14 & 0x0;
                                                                                            }
                                                                                            else {
                                                                                                    sub_47d838(eax);
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    var_14 = var_14 | 0xffffffff;
                                                                                            }
                                                                                    }
                                                                                    eax = var_C;
                                                                                    if (eax != arg_4) {
                                                                                            sub_47c8f9();
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                    }
                                                                                    eax = var_14;
                                                                                    if (eax == 0xfffffffe) {
                                                                                            eax = var_10;
                                                                                    }
                                                                                    esp = esp + 0x4;
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if ((!edx & 0x1) == 0x0) {
                                                                            *sub_47d825() = 0x0;
                                                                            *sub_47d812() = 0x16;
                                                                            eax = sub_47a924();
                                                                            esp = (esp - 0x14) + 0x14;
                                                                            eax = eax | 0xffffffff;
                                                                            esp = esp + 0x4;
                                                                            esp = esp + 0x4;
                                                                    }
                                                                    else {
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            eax = edx >> 0x1;
                                                                            arg_8 = 0x4;
                                                                            if (eax >= 0x4) {
                                                                                    arg_8 = eax;
                                                                            }
                                                                            eax = sub_481280(arg_8);
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            var_C = eax;
                                                                            if (eax == 0x0) {
                                                                                    *sub_47d812() = 0xc;
                                                                                    eax = sub_47d825();
                                                                                    *eax = 0x8;
                                                                                    eax = eax | 0xffffffff;
                                                                                    esp = esp + 0x4;
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                            else {
                                                                                    eax = var_C;
                                                                                    edi = esi + *ebx;
                                                                                    if ((edi[0x4] & 0x48) != 0x0) {
                                                                                            ecx = edi[0x5];
                                                                                            if (ecx != 0xa && arg_8 != 0x0) {
                                                                                                    *(int8_t *)eax = ecx;
                                                                                                    eax = eax + 0x1;
                                                                                                    arg_8 = arg_8 - 0x1;
                                                                                                    var_10 = 0x1;
                                                                                                    *(int8_t *)(esi + *ebx + 0x5) = 0xa;
                                                                                                    if (var_2 != 0x0) {
                                                                                                            ecx = *ebx;
                                                                                                            ecx = *(int8_t *)(esi + ecx + 0x25);
                                                                                                            if (ecx != 0xa && arg_8 != 0x0) {
                                                                                                                    *(int8_t *)eax = ecx;
                                                                                                                    eax = eax + 0x1;
                                                                                                                    arg_8 = arg_8 - 0x1;
                                                                                                                    var_10 = 0x2;
                                                                                                                    *(int8_t *)(esi + *ebx + 0x25) = 0xa;
                                                                                                                    if (var_2 == 0x1) {
                                                                                                                            ecx = *ebx;
                                                                                                                            ecx = *(int8_t *)(esi + ecx + 0x26);
                                                                                                                            if (ecx != 0xa) {
                                                                                                                                    if (arg_8 != 0x0) {
                                                                                                                                            *(int8_t *)eax = ecx;
                                                                                                                                            eax = eax + 0x1;
                                                                                                                                            arg_8 = arg_8 - 0x1;
                                                                                                                                            var_10 = 0x3;
                                                                                                                                            *(int8_t *)(esi + *ebx + 0x26) = 0xa;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                    }
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    esp = esp - 0x14;
                                                                                    eax = ReadFile(*(esi + *ebx), eax, arg_8, &var_18, 0x0);
                                                                                    if (eax != 0x0) {
                                                                                            edi = var_18;
                                                                                            if (edi >= 0x0) {
                                                                                                    if (edi <= arg_8) {
                                                                                                            eax = *ebx;
                                                                                                            var_10 = var_10 + edi;
                                                                                                            eax = esi + eax + 0x4;
                                                                                                            if ((*(int8_t *)eax & 0x80) != 0x0) {
                                                                                                                    if (var_2 != 0x2) {
                                                                                                                            if (edi != 0x0 && *(int8_t *)var_C == 0xa) {
                                                                                                                                    *(int8_t *)eax = *(int8_t *)eax | 0x4;
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    *(int8_t *)eax = *(int8_t *)eax & 0xfb;
                                                                                                                            }
                                                                                                                            edi = var_C;
                                                                                                                            bool_120 = edi >= var_10 + edi;
                                                                                                                            arg_8 = edi;
                                                                                                                            var_10 = var_10 + edi;
                                                                                                                            if (!bool_120) {
                                                                                                                                    while (true) {
                                                                                                                                            ecx = arg_8;
                                                                                                                                            eax = *(int8_t *)ecx;
                                                                                                                                            if (eax == 0x1a) {
                                                                                                                                                    eax = *ebx;
                                                                                                                                                    eax = esi + eax + 0x4;
                                                                                                                                                    if ((*(int8_t *)eax & 0x40) == 0x0) {
                                                                                                                                                            *(int8_t *)eax = *(int8_t *)eax | 0x2;
                                                                                                                                                            temp_0 = 0x1;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            *(int8_t *)edi = *(int8_t *)ecx;
                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                            temp_0 = 0x2;
                                                                                                                                                    }
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                            if (eax != 0xd) {
                                                                                                                                                    *(int8_t *)edi = eax;
                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                    arg_8 = ecx + 0x1;
                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    if (ecx < var_10 - 0x1) {
                                                                                                                                                            eax = ecx + 0x1;
                                                                                                                                                            if (*(int8_t *)eax == 0xa) {
                                                                                                                                                                    arg_8 = ecx + 0x2;
                                                                                                                                                                    *(int8_t *)edi = 0xa;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    arg_8 = eax;
                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                            }
                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            arg_8 = arg_8 + 0x1;
                                                                                                                                                            esp = esp - 0x14;
                                                                                                                                                            eax = ReadFile(*(esi + *ebx), &var_1, 0x1, &var_18, 0x0);
                                                                                                                                                            if (eax == 0x0) {
                                                                                                                                                                    if (GetLastError() == 0x0) {
                                                                                                                                                                            if (var_18 != 0x0) {
                                                                                                                                                                                    if ((*(int8_t *)(esi + *ebx + 0x4) & 0x48) != 0x0) {
                                                                                                                                                                                            if (var_1 != 0xa) {
                                                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x5) = var_1;
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    *(int8_t *)edi = 0xa;
                                                                                                                                                                                            }
                                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                    continue;
                                                                                                                                                                                            }
                                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                                            break;
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            if (edi == var_C) {
                                                                                                                                                                                                    if (var_1 != 0xa) {
                                                                                                                                                                                                            sub_48df70(arg_0, 0xffffffff, 0xffffffff, 0x1);
                                                                                                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                                            if (var_1 != 0xa) {
                                                                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                                    continue;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                                                            break;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    else {
                                                                                                                                                                                                            *(int8_t *)edi = 0xa;
                                                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                                    continue;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                                                            break;
                                                                                                                                                                                                    }
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    sub_48df70(arg_0, 0xffffffff, 0xffffffff, 0x1);
                                                                                                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                                    if (var_1 != 0xa) {
                                                                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                            continue;
                                                                                                                                                                                    }
                                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                                    break;
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    if (var_18 != 0x0) {
                                                                                                                                                                            if ((*(int8_t *)(esi + *ebx + 0x4) & 0x48) != 0x0) {
                                                                                                                                                                                    if (var_1 != 0xa) {
                                                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                                                            *(int8_t *)(esi + *ebx + 0x5) = var_1;
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            *(int8_t *)edi = 0xa;
                                                                                                                                                                                    }
                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                            continue;
                                                                                                                                                                                    }
                                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                                    break;
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    if (edi == var_C) {
                                                                                                                                                                                            if (var_1 != 0xa) {
                                                                                                                                                                                                    sub_48df70(arg_0, 0xffffffff, 0xffffffff, 0x1);
                                                                                                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                                    if (var_1 != 0xa) {
                                                                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    *(int8_t *)edi = 0xa;
                                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            sub_48df70(arg_0, 0xffffffff, 0xffffffff, 0x1);
                                                                                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                            if (var_1 != 0xa) {
                                                                                                                                                                                                    *(int8_t *)edi = 0xd;
                                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                                            }
                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                    continue;
                                                                                                                                                                                            }
                                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                                            break;
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            *(int8_t *)edi = 0xd;
                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            temp_0 = 0x0;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            eax = edi - var_C;
                                                                                                                            var_10 = eax;
                                                                                                                            if (var_2 == 0x1) {
                                                                                                                                    if (eax != 0x0) {
                                                                                                                                            edi = edi - 0x1;
                                                                                                                                            ecx = *(int8_t *)edi;
                                                                                                                                            if (ecx >= 0x0) {
                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                    esp = esp - 0x18;
                                                                                                                                                    eax = MultiByteToWideChar(0xfde9, 0x0, var_C, edi - var_C, arg_4, var_1C >> 0x1);
                                                                                                                                                    var_10 = eax;
                                                                                                                                                    if (eax == 0x0) {
                                                                                                                                                            eax = GetLastError();
                                                                                                                                                            sub_47d838(eax);
                                                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                                                            var_14 = var_14 | 0xffffffff;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            var_10 = eax + eax;
                                                                                                                                                    }
                                                                                                                                                    eax = var_C;
                                                                                                                                                    if (eax != arg_4) {
                                                                                                                                                            sub_47c8f9();
                                                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                                                    }
                                                                                                                                                    eax = var_14;
                                                                                                                                                    if (eax == 0xfffffffe) {
                                                                                                                                                            eax = var_10;
                                                                                                                                                    }
                                                                                                                                                    esp = esp + 0x4;
                                                                                                                                                    esp = esp + 0x4;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    eax = 0x1;
                                                                                                                                                    ecx = ecx & 0xff;
                                                                                                                                                    while (true) {
                                                                                                                                                            if (ecx[0x4ca0b8] != 0x0) {
                                                                                                                                                                    temp_2 = 0x0;
                                                                                                                                                                    break;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    if (eax <= 0x4) {
                                                                                                                                                                            if (edi >= var_C) {
                                                                                                                                                                                    edi = edi - 0x1;
                                                                                                                                                                                    ecx = *(int8_t *)edi & 0xff;
                                                                                                                                                                                    eax = eax + 0x1;
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            temp_2 = 0x1;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            temp_2 = 0x0;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    edx = *(int8_t *)edi;
                                                                                                                                                    ecx = sign_extend_32(*(int8_t *)((edx & 0xff) + 0x4ca0b8));
                                                                                                                                                    if (ecx == 0x0) {
                                                                                                                                                            *sub_47d812() = 0x2a;
                                                                                                                                                            var_14 = var_14 | 0xffffffff;
                                                                                                                                                            eax = var_C;
                                                                                                                                                            if (eax != arg_4) {
                                                                                                                                                                    sub_47c8f9();
                                                                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                                                            }
                                                                                                                                                            eax = var_14;
                                                                                                                                                            if (eax == 0xfffffffe) {
                                                                                                                                                                    eax = var_10;
                                                                                                                                                            }
                                                                                                                                                            esp = esp + 0x4;
                                                                                                                                                            esp = esp + 0x4;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            if (ecx + 0x1 == eax) {
                                                                                                                                                                    edi = edi + eax;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    ecx = *ebx;
                                                                                                                                                                    ecx = ecx + esi;
                                                                                                                                                                    if ((ecx[0x4] & 0x48) != 0x0) {
                                                                                                                                                                            edi = edi + 0x1;
                                                                                                                                                                            ecx[0x5] = edx;
                                                                                                                                                                            if (eax >= 0x2) {
                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x25) = *(int8_t *)edi;
                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                            }
                                                                                                                                                                            if (eax == 0x3) {
                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x26) = *(int8_t *)edi;
                                                                                                                                                                                    edi = edi + 0x1;
                                                                                                                                                                            }
                                                                                                                                                                            edi = edi - eax;
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            sub_48df70(arg_0, -eax, -eax & 0x80000000 ? 0xffffffff : 0x0, 0x1);
                                                                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            esp = esp - 0x18;
                                                                                                                                                            eax = MultiByteToWideChar(0xfde9, 0x0, var_C, edi - var_C, arg_4, var_1C >> 0x1);
                                                                                                                                                            var_10 = eax;
                                                                                                                                                            if (eax == 0x0) {
                                                                                                                                                                    eax = GetLastError();
                                                                                                                                                                    sub_47d838(eax);
                                                                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                                                                    var_14 = var_14 | 0xffffffff;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    var_10 = eax + eax;
                                                                                                                                                            }
                                                                                                                                                            eax = var_C;
                                                                                                                                                            if (eax != arg_4) {
                                                                                                                                                                    sub_47c8f9();
                                                                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                                                            }
                                                                                                                                                            eax = var_14;
                                                                                                                                                            if (eax == 0xfffffffe) {
                                                                                                                                                                    eax = var_10;
                                                                                                                                                            }
                                                                                                                                                            esp = esp + 0x4;
                                                                                                                                                            esp = esp + 0x4;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            eax = var_C;
                                                                                                                                            if (eax != arg_4) {
                                                                                                                                                    sub_47c8f9();
                                                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                                            }
                                                                                                                                            eax = var_14;
                                                                                                                                            if (eax == 0xfffffffe) {
                                                                                                                                                    eax = var_10;
                                                                                                                                            }
                                                                                                                                            esp = esp + 0x4;
                                                                                                                                            esp = esp + 0x4;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    eax = var_C;
                                                                                                                                    if (eax != arg_4) {
                                                                                                                                            sub_47c8f9();
                                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                                    }
                                                                                                                                    eax = var_14;
                                                                                                                                    if (eax == 0xfffffffe) {
                                                                                                                                            eax = var_10;
                                                                                                                                    }
                                                                                                                                    esp = esp + 0x4;
                                                                                                                                    esp = esp + 0x4;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            if (edi != 0x0 && *(int16_t *)var_C == 0xa) {
                                                                                                                                    *(int8_t *)eax = *(int8_t *)eax | 0x4;
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    *(int8_t *)eax = *(int8_t *)eax & 0xfb;
                                                                                                                            }
                                                                                                                            edi = var_C;
                                                                                                                            bool_135 = edi >= var_10 + edi;
                                                                                                                            arg_8 = edi;
                                                                                                                            var_10 = var_10 + edi;
                                                                                                                            if (!bool_135) {
                                                                                                                                    while (true) {
                                                                                                                                            eax = arg_8;
                                                                                                                                            ecx = *(int16_t *)eax & 0xffff;
                                                                                                                                            if (ecx == 0x1a) {
                                                                                                                                                    esi = esi + *ebx + 0x4;
                                                                                                                                                    if ((*(int8_t *)esi & 0x40) == 0x0) {
                                                                                                                                                            *(int8_t *)esi = *(int8_t *)esi | 0x2;
                                                                                                                                                            temp_1 = 0x1;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            *(int16_t *)edi = *(int16_t *)eax;
                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                            temp_1 = 0x2;
                                                                                                                                                    }
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                            if (ecx != 0xd) {
                                                                                                                                                    *(int16_t *)edi = ecx;
                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                    arg_8 = eax + 0x2;
                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                            continue;
                                                                                                                                                    }
                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    if (eax < var_10 - 0x2) {
                                                                                                                                                            ecx = eax + 0x2;
                                                                                                                                                            if (*(int16_t *)ecx == 0xa) {
                                                                                                                                                                    arg_8 = eax + 0x4;
                                                                                                                                                                    *(int16_t *)edi = 0xa;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    arg_8 = ecx;
                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                            }
                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            arg_8 = arg_8 + 0x2;
                                                                                                                                                            esp = esp - 0x14;
                                                                                                                                                            eax = ReadFile(*(esi + *ebx), &var_8, 0x2, &var_18, 0x0);
                                                                                                                                                            if (eax == 0x0) {
                                                                                                                                                                    if (GetLastError() == 0x0) {
                                                                                                                                                                            if (var_18 != 0x0) {
                                                                                                                                                                                    if ((*(int8_t *)(esi + *ebx + 0x4) & 0x48) != 0x0) {
                                                                                                                                                                                            if (var_8 != 0xa) {
                                                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x5) = var_8;
                                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x25) = var_7;
                                                                                                                                                                                                    *(int8_t *)(esi + *ebx + 0x26) = 0xa;
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    *(int16_t *)edi = 0xa;
                                                                                                                                                                                            }
                                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                    continue;
                                                                                                                                                                                            }
                                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                                            break;
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            if (edi == var_C) {
                                                                                                                                                                                                    if (var_8 != 0xa) {
                                                                                                                                                                                                            sub_48df70(arg_0, 0xfffffffe, 0xffffffff, 0x1);
                                                                                                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                                            if (var_8 != 0xa) {
                                                                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                                    continue;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                                                            break;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    else {
                                                                                                                                                                                                            *(int16_t *)edi = 0xa;
                                                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                                    continue;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                                                            break;
                                                                                                                                                                                                    }
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    sub_48df70(arg_0, 0xfffffffe, 0xffffffff, 0x1);
                                                                                                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                                    if (var_8 != 0xa) {
                                                                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                            continue;
                                                                                                                                                                                    }
                                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                                    break;
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    if (var_18 != 0x0) {
                                                                                                                                                                            if ((*(int8_t *)(esi + *ebx + 0x4) & 0x48) != 0x0) {
                                                                                                                                                                                    if (var_8 != 0xa) {
                                                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                                                            *(int8_t *)(esi + *ebx + 0x5) = var_8;
                                                                                                                                                                                            *(int8_t *)(esi + *ebx + 0x25) = var_7;
                                                                                                                                                                                            *(int8_t *)(esi + *ebx + 0x26) = 0xa;
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            *(int16_t *)edi = 0xa;
                                                                                                                                                                                    }
                                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                            continue;
                                                                                                                                                                                    }
                                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                                    break;
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    if (edi == var_C) {
                                                                                                                                                                                            if (var_8 != 0xa) {
                                                                                                                                                                                                    sub_48df70(arg_0, 0xfffffffe, 0xffffffff, 0x1);
                                                                                                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                                    if (var_8 != 0xa) {
                                                                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                            else {
                                                                                                                                                                                                    *(int16_t *)edi = 0xa;
                                                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                                                    if (arg_8 < var_10) {
                                                                                                                                                                                                            continue;
                                                                                                                                                                                                    }
                                                                                                                                                                                                    temp_1 = 0x0;
                                                                                                                                                                                                    break;
                                                                                                                                                                                            }
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            sub_48df70(arg_0, 0xfffffffe, 0xffffffff, 0x1);
                                                                                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                                                                                            if (var_8 != 0xa) {
                                                                                                                                                                                                    *(int16_t *)edi = 0xd;
                                                                                                                                                                                                    edi = edi + 0x2;
                                                                                                                                                                                            }
                                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                                    continue;
                                                                                                                                                                                            }
                                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                                            break;
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            *(int16_t *)edi = 0xd;
                                                                                                                                                                            edi = edi + 0x2;
                                                                                                                                                                            if (arg_8 < var_10) {
                                                                                                                                                                                    continue;
                                                                                                                                                                            }
                                                                                                                                                                            temp_1 = 0x0;
                                                                                                                                                                            break;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            var_10 = edi - var_C;
                                                                                                                            eax = var_C;
                                                                                                                            if (eax != arg_4) {
                                                                                                                                    sub_47c8f9();
                                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                            }
                                                                                                                            eax = var_14;
                                                                                                                            if (eax == 0xfffffffe) {
                                                                                                                                    eax = var_10;
                                                                                                                            }
                                                                                                                            esp = esp + 0x4;
                                                                                                                            esp = esp + 0x4;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    eax = var_C;
                                                                                                                    if (eax != arg_4) {
                                                                                                                            sub_47c8f9();
                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                    }
                                                                                                                    eax = var_14;
                                                                                                                    if (eax == 0xfffffffe) {
                                                                                                                            eax = var_10;
                                                                                                                    }
                                                                                                                    esp = esp + 0x4;
                                                                                                                    esp = esp + 0x4;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = GetLastError();
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            if (eax == 0x5) {
                                                                                                                    *sub_47d812() = 0x9;
                                                                                                                    *sub_47d825() = 0x5;
                                                                                                                    var_14 = var_14 | 0xffffffff;
                                                                                                            }
                                                                                                            else {
                                                                                                                    if (eax == 0x6d) {
                                                                                                                            var_14 = var_14 & 0x0;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            sub_47d838(eax);
                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                            var_14 = var_14 | 0xffffffff;
                                                                                                                    }
                                                                                                            }
                                                                                                            eax = var_C;
                                                                                                            if (eax != arg_4) {
                                                                                                                    sub_47c8f9();
                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                            }
                                                                                                            eax = var_14;
                                                                                                            if (eax == 0xfffffffe) {
                                                                                                                    eax = var_10;
                                                                                                            }
                                                                                                            esp = esp + 0x4;
                                                                                                            esp = esp + 0x4;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    eax = GetLastError();
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    if (eax == 0x5) {
                                                                                                            *sub_47d812() = 0x9;
                                                                                                            *sub_47d825() = 0x5;
                                                                                                            var_14 = var_14 | 0xffffffff;
                                                                                                    }
                                                                                                    else {
                                                                                                            if (eax == 0x6d) {
                                                                                                                    var_14 = var_14 & 0x0;
                                                                                                            }
                                                                                                            else {
                                                                                                                    sub_47d838(eax);
                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                    var_14 = var_14 | 0xffffffff;
                                                                                                            }
                                                                                                    }
                                                                                                    eax = var_C;
                                                                                                    if (eax != arg_4) {
                                                                                                            sub_47c8f9();
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                    }
                                                                                                    eax = var_14;
                                                                                                    if (eax == 0xfffffffe) {
                                                                                                            eax = var_10;
                                                                                                    }
                                                                                                    esp = esp + 0x4;
                                                                                                    esp = esp + 0x4;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            eax = GetLastError();
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            if (eax == 0x5) {
                                                                                                    *sub_47d812() = 0x9;
                                                                                                    *sub_47d825() = 0x5;
                                                                                                    var_14 = var_14 | 0xffffffff;
                                                                                            }
                                                                                            else {
                                                                                                    if (eax == 0x6d) {
                                                                                                            var_14 = var_14 & 0x0;
                                                                                                    }
                                                                                                    else {
                                                                                                            sub_47d838(eax);
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            var_14 = var_14 | 0xffffffff;
                                                                                                    }
                                                                                            }
                                                                                            eax = var_C;
                                                                                            if (eax != arg_4) {
                                                                                                    sub_47c8f9();
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                            }
                                                                                            eax = var_14;
                                                                                            if (eax == 0xfffffffe) {
                                                                                                    eax = var_10;
                                                                                            }
                                                                                            esp = esp + 0x4;
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            *sub_47d825() = 0x0;
                                                            *sub_47d812() = 0x16;
                                                            eax = sub_47a924();
                                                            esp = (esp - 0x14) + 0x14;
                                                            eax = eax | 0xffffffff;
                                                            esp = esp + 0x4;
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                                    esp = esp + 0x4;
                                                    esp = esp + 0x4;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                            esp = esp + 0x4;
                                            esp = esp + 0x4;
                                    }
                            }
                    }
            }
            else {
                    *sub_47d825() = 0x0;
                    *sub_47d812() = 0x9;
                    eax = sub_47a924();
                    esp = (esp - 0x14) + 0x14;
                    eax = eax | 0xffffffff;
                    esp = esp + 0x4;
            }
    }
    return eax;
}
