// sub_486c87 @ 0x486c87
// hopper name: sub_486c87
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_486c87() {
    decomp_var_14 = ebx;
    esp = esp - 0x8;
    decomp_var_18 = esi;
    esi = arg_4;
    var_4 = *dword_bc6f54;
    var_C = 0x0;
    var_8 = 0x0;
    var_10 = 0x0;
    while (*(int8_t *)esi == 0x20) {
            esi = esi + 0x1;
    }
    eax = *(int8_t *)esi;
    if (eax != 0x61) {
            if (eax != 0x72) {
                    if (eax != 0x77) {
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = 0x0;
                    }
                    else {
                            arg_4 = 0x301;
                            var_4 = var_4 | 0x2;
                            ecx = 0x1;
                            esi = esi + 0x1;
                            eax = *(int8_t *)esi;
                            esp = esp - 0x4;
                            decomp_var_1c = edi;
                            if (eax != 0x0) {
                                    while (true) {
                                            ebx = 0x0;
                                            if (ecx == 0x0) {
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            eax = sign_extend_32(eax);
                                            bool_117 = eax == 0x53;
                                            if (eax <= 0x53) {
                                                    if (!bool_117) {
                                                            eax = eax - 0x20;
                                                            if (eax != 0x0) {
                                                                    eax = eax - 0xb;
                                                                    if (eax != 0x0) {
                                                                            eax = eax - 0x1;
                                                                            if (eax != 0x0) {
                                                                                    eax = eax - 0x18;
                                                                                    if (eax != 0x0) {
                                                                                            eax = eax - 0xa;
                                                                                            if (eax != 0x0) {
                                                                                                    if (eax == 0x4) {
                                                                                                            if (var_8 == ebx) {
                                                                                                                    arg_4 = arg_4 | 0x10;
                                                                                                                    var_8 = 0x1;
                                                                                                            }
                                                                                                            else {
                                                                                                                    ecx = 0x0;
                                                                                                            }
                                                                                                            esi = esi + 0x1;
                                                                                                            eax = *(int8_t *)esi;
                                                                                                            if (eax != ebx) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            temp_0 = 0x1;
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_0 = 0x0;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    arg_4 = arg_4 | 0x80;
                                                                                                    esi = esi + 0x1;
                                                                                                    eax = *(int8_t *)esi;
                                                                                                    if (eax != ebx) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_0 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if ((arg_4 & 0x40) == 0x0) {
                                                                                                    arg_4 = arg_4 | 0x40;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = 0x0;
                                                                                            }
                                                                                            esi = esi + 0x1;
                                                                                            eax = *(int8_t *)esi;
                                                                                            if (eax != ebx) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_0 = 0x1;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    var_10 = 0x1;
                                                                                    ecx = 0x0;
                                                                                    esi = esi + 0x1;
                                                                                    eax = *(int8_t *)esi;
                                                                                    if (eax != ebx) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((arg_4 & 0x2) == 0x0) {
                                                                                    arg_4 = arg_4 & 0xfffffffe | 0x2;
                                                                                    var_4 = var_4 & 0xfffffffc | 0x80;
                                                                            }
                                                                            else {
                                                                                    ecx = 0x0;
                                                                            }
                                                                            esi = esi + 0x1;
                                                                            eax = *(int8_t *)esi;
                                                                            if (eax != ebx) {
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    esi = esi + 0x1;
                                                                    eax = *(int8_t *)esi;
                                                                    if (eax != ebx) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (var_8 == ebx) {
                                                                    arg_4 = arg_4 | 0x20;
                                                                    var_8 = 0x1;
                                                            }
                                                            else {
                                                                    ecx = 0x0;
                                                            }
                                                            esi = esi + 0x1;
                                                            eax = *(int8_t *)esi;
                                                            if (eax != ebx) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    eax = eax - 0x54;
                                                    if (eax != 0x0) {
                                                            eax = eax - 0xe;
                                                            if (eax != 0x0) {
                                                                    eax = eax - 0x1;
                                                                    if (eax != 0x0) {
                                                                            eax = eax - 0xb;
                                                                            if (eax != 0x0) {
                                                                                    if (eax == 0x6) {
                                                                                            if ((arg_4 & 0xc000) == 0x0) {
                                                                                                    arg_4 = arg_4 | 0x4000;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = 0x0;
                                                                                            }
                                                                                            esi = esi + 0x1;
                                                                                            eax = *(int8_t *)esi;
                                                                                            if (eax != ebx) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_0 = 0x1;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x2;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (var_C == 0x0) {
                                                                                            var_4 = var_4 & 0xffffbfff;
                                                                                            var_C = 0x1;
                                                                                    }
                                                                                    else {
                                                                                            ecx = 0x0;
                                                                                    }
                                                                                    esi = esi + 0x1;
                                                                                    eax = *(int8_t *)esi;
                                                                                    if (eax != 0x0) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = 0x0;
                                                                            if (var_C == 0x0) {
                                                                                    var_4 = var_4 | 0x4000;
                                                                                    var_C = 0x1;
                                                                                    esi = esi + 0x1;
                                                                                    eax = *(int8_t *)esi;
                                                                                    if (eax != ebx) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = 0x0;
                                                                                    esi = esi + 0x1;
                                                                                    eax = *(int8_t *)esi;
                                                                                    if (eax != ebx) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if ((arg_4 & 0xc000) == 0x0) {
                                                                            arg_4 = arg_4 | 0x8000;
                                                                            esi = esi + 0x1;
                                                                            eax = *(int8_t *)esi;
                                                                            if (eax != 0x0) {
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = 0x0;
                                                                            esi = esi + 0x1;
                                                                            eax = *(int8_t *)esi;
                                                                            if (eax != ebx) {
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if ((arg_4 & 0x1000) != 0x0) {
                                                                    ecx = 0x0;
                                                                    esi = esi + 0x1;
                                                                    eax = *(int8_t *)esi;
                                                                    if (eax != 0x0) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                            else {
                                                                    arg_4 = arg_4 | 0x1000;
                                                                    esi = esi + 0x1;
                                                                    eax = *(int8_t *)esi;
                                                                    if (eax != ebx) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                            }
                                    }
                                    switch (temp_0) {
                                        case 0:
                                            *sub_47d812() = 0x16;
                                            sub_47a924();
                                            esp = (esp - 0x14) + 0x14;
                                            eax = 0x0;
                                            esp = esp + 0x4;
                                            break;
                                        case 1:
                                            ebx = 0x0;
                                            if (var_10 != 0x0) {
                                                    while (*(int8_t *)esi == 0x20) {
                                                            esi = esi + 0x1;
                                                    }
                                                    esp = (esp - 0xc) + 0xc;
                                                    if (sub_48f26b("ccs=", esi, 0x4) == 0x0) {
                                                            esi = esi + 0x4;
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (sub_48f0ef(esi, "UTF-8") == 0x0) {
                                                                    esi = esi + 0x5;
                                                                    arg_4 = arg_4 | 0x40000;
                                                                    while (*(int8_t *)esi == 0x20) {
                                                                            esi = esi + 0x1;
                                                                    }
                                                                    if (*(int8_t *)esi != ebx) {
                                                                            *sub_47d812() = 0x16;
                                                                            sub_47a924();
                                                                            esp = (esp - 0x14) + 0x14;
                                                                            eax = 0x0;
                                                                            esp = esp + 0x4;
                                                                    }
                                                                    else {
                                                                            eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                                                                            esp = (esp - 0x14) + 0x14;
                                                                            if (eax != 0x0) {
                                                                                    eax = 0x0;
                                                                            }
                                                                            else {
                                                                                    eax = arg_c;
                                                                                    *dword_bc6894 = *dword_bc6894 + 0x1;
                                                                                    eax[0x3] = var_4;
                                                                                    eax[0x1] = 0x0;
                                                                                    *eax = 0x0;
                                                                                    eax[0x2] = 0x0;
                                                                                    eax[0x7] = 0x0;
                                                                                    eax[0x4] = var_10;
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    esp = (esp - 0x8) + 0x8;
                                                                    if (sub_48f0ef(esi, "UTF-16LE") == 0x0) {
                                                                            esi = esi + 0x8;
                                                                            arg_4 = arg_4 | 0x20000;
                                                                            while (*(int8_t *)esi == 0x20) {
                                                                                    esi = esi + 0x1;
                                                                            }
                                                                            ebx = 0x0;
                                                                            if (*(int8_t *)esi != 0x0) {
                                                                                    *sub_47d812() = 0x16;
                                                                                    sub_47a924();
                                                                                    esp = (esp - 0x14) + 0x14;
                                                                                    eax = 0x0;
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                            else {
                                                                                    eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                                                                                    esp = (esp - 0x14) + 0x14;
                                                                                    if (eax != 0x0) {
                                                                                            eax = 0x0;
                                                                                    }
                                                                                    else {
                                                                                            eax = arg_c;
                                                                                            *dword_bc6894 = *dword_bc6894 + 0x1;
                                                                                            eax[0x3] = var_4;
                                                                                            eax[0x1] = 0x0;
                                                                                            *eax = 0x0;
                                                                                            eax[0x2] = 0x0;
                                                                                            eax[0x7] = 0x0;
                                                                                            eax[0x4] = var_10;
                                                                                    }
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esp = (esp - 0x8) + 0x8;
                                                                            if (sub_48f0ef(esi, "UNICODE") == 0x0) {
                                                                                    esi = esi + 0x7;
                                                                                    arg_4 = arg_4 | 0x10000;
                                                                                    while (*(int8_t *)esi == 0x20) {
                                                                                            esi = esi + 0x1;
                                                                                    }
                                                                                    if (*(int8_t *)esi != ebx) {
                                                                                            *sub_47d812() = 0x16;
                                                                                            sub_47a924();
                                                                                            esp = (esp - 0x14) + 0x14;
                                                                                            eax = 0x0;
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                                    else {
                                                                                            eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                                                                                            esp = (esp - 0x14) + 0x14;
                                                                                            if (eax != 0x0) {
                                                                                                    eax = 0x0;
                                                                                            }
                                                                                            else {
                                                                                                    eax = arg_c;
                                                                                                    *dword_bc6894 = *dword_bc6894 + 0x1;
                                                                                                    eax[0x3] = var_4;
                                                                                                    eax[0x1] = 0x0;
                                                                                                    *eax = 0x0;
                                                                                                    eax[0x2] = 0x0;
                                                                                                    eax[0x7] = 0x0;
                                                                                                    eax[0x4] = var_10;
                                                                                            }
                                                                                            esp = esp + 0x4;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    *sub_47d812() = 0x16;
                                                                                    sub_47a924();
                                                                                    esp = (esp - 0x14) + 0x14;
                                                                                    eax = 0x0;
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            *sub_47d812() = 0x16;
                                                            sub_47a924();
                                                            esp = (esp - 0x14) + 0x14;
                                                            eax = 0x0;
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                            else {
                                                    while (*(int8_t *)esi == 0x20) {
                                                            esi = esi + 0x1;
                                                    }
                                                    if (*(int8_t *)esi != ebx) {
                                                            *sub_47d812() = 0x16;
                                                            sub_47a924();
                                                            esp = (esp - 0x14) + 0x14;
                                                            eax = 0x0;
                                                            esp = esp + 0x4;
                                                    }
                                                    else {
                                                            eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                                                            esp = (esp - 0x14) + 0x14;
                                                            if (eax != 0x0) {
                                                                    eax = 0x0;
                                                            }
                                                            else {
                                                                    eax = arg_c;
                                                                    *dword_bc6894 = *dword_bc6894 + 0x1;
                                                                    eax[0x3] = var_4;
                                                                    eax[0x1] = 0x0;
                                                                    *eax = 0x0;
                                                                    eax[0x2] = 0x0;
                                                                    eax[0x7] = 0x0;
                                                                    eax[0x4] = var_10;
                                                            }
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                            break;
                                        default:
                                            *sub_47d812() = 0x16;
                                            sub_47a924();
                                            esp = (esp - 0x14) + 0x14;
                                            eax = 0x0;
                                            esp = esp + 0x4;
                                            break;
                                    }
                            }
                            else {
                                    while (*(int8_t *)esi == 0x20) {
                                            esi = esi + 0x1;
                                    }
                                    if (*(int8_t *)esi != 0x0) {
                                            *sub_47d812() = 0x16;
                                            sub_47a924();
                                            esp = (esp - 0x14) + 0x14;
                                            eax = 0x0;
                                            esp = esp + 0x4;
                                    }
                                    else {
                                            eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                                            esp = (esp - 0x14) + 0x14;
                                            if (eax != 0x0) {
                                                    eax = 0x0;
                                            }
                                            else {
                                                    eax = arg_c;
                                                    *dword_bc6894 = *dword_bc6894 + 0x1;
                                                    eax[0x3] = var_4;
                                                    eax[0x1] = 0x0;
                                                    *eax = 0x0;
                                                    eax[0x2] = 0x0;
                                                    eax[0x7] = 0x0;
                                                    eax[0x4] = var_10;
                                            }
                                            esp = esp + 0x4;
                                    }
                            }
                    }
            }
            else {
                    var_4 = var_4 | 0x1;
                    arg_4 = 0x0;
                    ebx = 0x0;
                    ecx = 0x1;
                    esi = esi + 0x1;
                    eax = *(int8_t *)esi;
                    esp = esp - 0x4;
                    decomp_var_1c = edi;
                    if (eax != 0x0) {
                            while (true) {
                                    if (ecx == ebx) {
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    eax = sign_extend_32(eax);
                                    bool_78 = eax == 0x53;
                                    if (eax <= 0x53) {
                                            if (!bool_78) {
                                                    eax = eax - 0x20;
                                                    if (eax != 0x0) {
                                                            eax = eax - 0xb;
                                                            if (eax != 0x0) {
                                                                    eax = eax - 0x1;
                                                                    if (eax != 0x0) {
                                                                            eax = eax - 0x18;
                                                                            if (eax != 0x0) {
                                                                                    eax = eax - 0xa;
                                                                                    if (eax != 0x0) {
                                                                                            if (eax == 0x4) {
                                                                                                    if (var_8 == ebx) {
                                                                                                            arg_4 = arg_4 | 0x10;
                                                                                                            var_8 = 0x1;
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = 0x0;
                                                                                                    }
                                                                                                    esi = esi + 0x1;
                                                                                                    eax = *(int8_t *)esi;
                                                                                                    if (eax != ebx) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_0 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_0 = 0x0;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            arg_4 = arg_4 | 0x80;
                                                                                            esi = esi + 0x1;
                                                                                            eax = *(int8_t *)esi;
                                                                                            if (eax != ebx) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_0 = 0x1;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if ((arg_4 & 0x40) == 0x0) {
                                                                                            arg_4 = arg_4 | 0x40;
                                                                                    }
                                                                                    else {
                                                                                            ecx = 0x0;
                                                                                    }
                                                                                    esi = esi + 0x1;
                                                                                    eax = *(int8_t *)esi;
                                                                                    if (eax != ebx) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            var_10 = 0x1;
                                                                            ecx = 0x0;
                                                                            esi = esi + 0x1;
                                                                            eax = *(int8_t *)esi;
                                                                            if (eax != ebx) {
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if ((arg_4 & 0x2) == 0x0) {
                                                                            arg_4 = arg_4 & 0xfffffffe | 0x2;
                                                                            var_4 = var_4 & 0xfffffffc | 0x80;
                                                                    }
                                                                    else {
                                                                            ecx = 0x0;
                                                                    }
                                                                    esi = esi + 0x1;
                                                                    eax = *(int8_t *)esi;
                                                                    if (eax != ebx) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            esi = esi + 0x1;
                                                            eax = *(int8_t *)esi;
                                                            if (eax != ebx) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (var_8 == ebx) {
                                                            arg_4 = arg_4 | 0x20;
                                                            var_8 = 0x1;
                                                    }
                                                    else {
                                                            ecx = 0x0;
                                                    }
                                                    esi = esi + 0x1;
                                                    eax = *(int8_t *)esi;
                                                    if (eax != ebx) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                    }
                                    else {
                                            eax = eax - 0x54;
                                            if (eax != 0x0) {
                                                    eax = eax - 0xe;
                                                    if (eax != 0x0) {
                                                            eax = eax - 0x1;
                                                            if (eax != 0x0) {
                                                                    eax = eax - 0xb;
                                                                    if (eax != 0x0) {
                                                                            if (eax == 0x6) {
                                                                                    if ((arg_4 & 0xc000) == 0x0) {
                                                                                            arg_4 = arg_4 | 0x4000;
                                                                                    }
                                                                                    else {
                                                                                            ecx = 0x0;
                                                                                    }
                                                                                    esi = esi + 0x1;
                                                                                    eax = *(int8_t *)esi;
                                                                                    if (eax != ebx) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x2;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (var_C == ebx) {
                                                                                    var_4 = var_4 & 0xffffbfff;
                                                                                    var_C = 0x1;
                                                                            }
                                                                            else {
                                                                                    ecx = 0x0;
                                                                            }
                                                                            esi = esi + 0x1;
                                                                            eax = *(int8_t *)esi;
                                                                            if (eax != ebx) {
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (var_C == ebx) {
                                                                            var_4 = var_4 | 0x4000;
                                                                            var_C = 0x1;
                                                                            esi = esi + 0x1;
                                                                            eax = *(int8_t *)esi;
                                                                            if (eax != ebx) {
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = 0x0;
                                                                            esi = esi + 0x1;
                                                                            eax = *(int8_t *)esi;
                                                                            if (eax != ebx) {
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if ((arg_4 & 0xc000) == 0x0) {
                                                                    arg_4 = arg_4 | 0x8000;
                                                                    esi = esi + 0x1;
                                                                    eax = *(int8_t *)esi;
                                                                    if (eax != ebx) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = 0x0;
                                                                    esi = esi + 0x1;
                                                                    eax = *(int8_t *)esi;
                                                                    if (eax != ebx) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if ((arg_4 & 0x1000) != 0x0) {
                                                            ecx = 0x0;
                                                            esi = esi + 0x1;
                                                            eax = *(int8_t *)esi;
                                                            if (eax != ebx) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    else {
                                                            arg_4 = arg_4 | 0x1000;
                                                            esi = esi + 0x1;
                                                            eax = *(int8_t *)esi;
                                                            if (eax != ebx) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                    }
                            }
                            switch (temp_0) {
                                case 0:
                                    *sub_47d812() = 0x16;
                                    sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    eax = 0x0;
                                    esp = esp + 0x4;
                                    break;
                                case 1:
                                    if (var_10 != 0x0) {
                                            while (*(int8_t *)esi == 0x20) {
                                                    esi = esi + 0x1;
                                            }
                                            esp = (esp - 0xc) + 0xc;
                                            if (sub_48f26b("ccs=", esi, 0x4) == 0x0) {
                                                    esi = esi + 0x4;
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (sub_48f0ef(esi, "UTF-8") == 0x0) {
                                                            esi = esi + 0x5;
                                                            arg_4 = arg_4 | 0x40000;
                                                            while (*(int8_t *)esi == 0x20) {
                                                                    esi = esi + 0x1;
                                                            }
                                                            ebx = 0x0;
                                                            if (*(int8_t *)esi != 0x0) {
                                                                    *sub_47d812() = 0x16;
                                                                    sub_47a924();
                                                                    esp = (esp - 0x14) + 0x14;
                                                                    eax = 0x0;
                                                                    esp = esp + 0x4;
                                                            }
                                                            else {
                                                                    eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                                                                    esp = (esp - 0x14) + 0x14;
                                                                    if (eax != 0x0) {
                                                                            eax = 0x0;
                                                                    }
                                                                    else {
                                                                            eax = arg_c;
                                                                            *dword_bc6894 = *dword_bc6894 + 0x1;
                                                                            eax[0x3] = var_4;
                                                                            eax[0x1] = ebx;
                                                                            *eax = ebx;
                                                                            eax[0x2] = ebx;
                                                                            eax[0x7] = ebx;
                                                                            eax[0x4] = var_10;
                                                                    }
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (sub_48f0ef(esi, "UTF-16LE") == 0x0) {
                                                                    esi = esi + 0x8;
                                                                    arg_4 = arg_4 | 0x20000;
                                                                    while (*(int8_t *)esi == 0x20) {
                                                                            esi = esi + 0x1;
                                                                    }
                                                                    ebx = 0x0;
                                                                    if (*(int8_t *)esi != 0x0) {
                                                                            *sub_47d812() = 0x16;
                                                                            sub_47a924();
                                                                            esp = (esp - 0x14) + 0x14;
                                                                            eax = 0x0;
                                                                            esp = esp + 0x4;
                                                                    }
                                                                    else {
                                                                            eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                                                                            esp = (esp - 0x14) + 0x14;
                                                                            if (eax != 0x0) {
                                                                                    eax = 0x0;
                                                                            }
                                                                            else {
                                                                                    eax = arg_c;
                                                                                    *dword_bc6894 = *dword_bc6894 + 0x1;
                                                                                    eax[0x3] = var_4;
                                                                                    eax[0x1] = 0x0;
                                                                                    *eax = 0x0;
                                                                                    eax[0x2] = 0x0;
                                                                                    eax[0x7] = 0x0;
                                                                                    eax[0x4] = var_10;
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    esp = (esp - 0x8) + 0x8;
                                                                    if (sub_48f0ef(esi, "UNICODE") == 0x0) {
                                                                            esi = esi + 0x7;
                                                                            arg_4 = arg_4 | 0x10000;
                                                                            while (*(int8_t *)esi == 0x20) {
                                                                                    esi = esi + 0x1;
                                                                            }
                                                                            ebx = 0x0;
                                                                            if (*(int8_t *)esi != 0x0) {
                                                                                    *sub_47d812() = 0x16;
                                                                                    sub_47a924();
                                                                                    esp = (esp - 0x14) + 0x14;
                                                                                    eax = 0x0;
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                            else {
                                                                                    eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                                                                                    esp = (esp - 0x14) + 0x14;
                                                                                    if (eax != 0x0) {
                                                                                            eax = 0x0;
                                                                                    }
                                                                                    else {
                                                                                            eax = arg_c;
                                                                                            *dword_bc6894 = *dword_bc6894 + 0x1;
                                                                                            eax[0x3] = var_4;
                                                                                            eax[0x1] = ebx;
                                                                                            *eax = ebx;
                                                                                            eax[0x2] = ebx;
                                                                                            eax[0x7] = ebx;
                                                                                            eax[0x4] = var_10;
                                                                                    }
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *sub_47d812() = 0x16;
                                                                            sub_47a924();
                                                                            esp = (esp - 0x14) + 0x14;
                                                                            eax = 0x0;
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    *sub_47d812() = 0x16;
                                                    sub_47a924();
                                                    esp = (esp - 0x14) + 0x14;
                                                    eax = 0x0;
                                                    esp = esp + 0x4;
                                            }
                                    }
                                    else {
                                            while (*(int8_t *)esi == 0x20) {
                                                    esi = esi + 0x1;
                                            }
                                            ebx = 0x0;
                                            if (*(int8_t *)esi != 0x0) {
                                                    *sub_47d812() = 0x16;
                                                    sub_47a924();
                                                    esp = (esp - 0x14) + 0x14;
                                                    eax = 0x0;
                                                    esp = esp + 0x4;
                                            }
                                            else {
                                                    eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                                                    esp = (esp - 0x14) + 0x14;
                                                    if (eax != 0x0) {
                                                            eax = 0x0;
                                                    }
                                                    else {
                                                            eax = arg_c;
                                                            *dword_bc6894 = *dword_bc6894 + 0x1;
                                                            eax[0x3] = var_4;
                                                            eax[0x1] = ebx;
                                                            *eax = ebx;
                                                            eax[0x2] = ebx;
                                                            eax[0x7] = ebx;
                                                            eax[0x4] = var_10;
                                                    }
                                                    esp = esp + 0x4;
                                            }
                                    }
                                    break;
                                default:
                                    *sub_47d812() = 0x16;
                                    sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    eax = 0x0;
                                    esp = esp + 0x4;
                                    break;
                            }
                    }
                    else {
                            while (*(int8_t *)esi == 0x20) {
                                    esi = esi + 0x1;
                            }
                            if (*(int8_t *)esi != 0x0) {
                                    *sub_47d812() = 0x16;
                                    sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    eax = 0x0;
                                    esp = esp + 0x4;
                            }
                            else {
                                    eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                                    esp = (esp - 0x14) + 0x14;
                                    if (eax != 0x0) {
                                            eax = 0x0;
                                    }
                                    else {
                                            eax = arg_c;
                                            *dword_bc6894 = *dword_bc6894 + 0x1;
                                            eax[0x3] = var_4;
                                            eax[0x1] = 0x0;
                                            *eax = 0x0;
                                            eax[0x2] = 0x0;
                                            eax[0x7] = 0x0;
                                            eax[0x4] = var_10;
                                    }
                                    esp = esp + 0x4;
                            }
                    }
            }
    }
    else {
            arg_4 = 0x109;
            var_4 = var_4 | 0x2;
            ecx = 0x1;
            esi = esi + 0x1;
            eax = *(int8_t *)esi;
            esp = esp - 0x4;
            decomp_var_1c = edi;
            if (eax != 0x0) {
                    while (true) {
                            ebx = 0x0;
                            if (ecx == 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            eax = sign_extend_32(eax);
                            bool_173 = eax == 0x53;
                            if (eax <= 0x53) {
                                    if (!bool_173) {
                                            eax = eax - 0x20;
                                            if (eax != 0x0) {
                                                    eax = eax - 0xb;
                                                    if (eax != 0x0) {
                                                            eax = eax - 0x1;
                                                            if (eax != 0x0) {
                                                                    eax = eax - 0x18;
                                                                    if (eax != 0x0) {
                                                                            eax = eax - 0xa;
                                                                            if (eax != 0x0) {
                                                                                    if (eax == 0x4) {
                                                                                            ebx = 0x0;
                                                                                            if (var_8 == 0x0) {
                                                                                                    arg_4 = arg_4 | 0x10;
                                                                                                    var_8 = 0x1;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = 0x0;
                                                                                            }
                                                                                            esi = esi + 0x1;
                                                                                            eax = *(int8_t *)esi;
                                                                                            if (eax != ebx) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_0 = 0x1;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x0;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    arg_4 = arg_4 | 0x80;
                                                                                    esi = esi + 0x1;
                                                                                    eax = *(int8_t *)esi;
                                                                                    if (eax != 0x0) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if ((arg_4 & 0x40) == 0x0) {
                                                                                    arg_4 = arg_4 | 0x40;
                                                                            }
                                                                            else {
                                                                                    ecx = 0x0;
                                                                            }
                                                                            esi = esi + 0x1;
                                                                            eax = *(int8_t *)esi;
                                                                            if (eax != ebx) {
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    var_10 = 0x1;
                                                                    ecx = 0x0;
                                                                    esi = esi + 0x1;
                                                                    eax = *(int8_t *)esi;
                                                                    if (eax != 0x0) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if ((arg_4 & 0x2) == 0x0) {
                                                                    arg_4 = arg_4 & 0xfffffffe | 0x2;
                                                                    var_4 = var_4 & 0xfffffffc | 0x80;
                                                            }
                                                            else {
                                                                    ecx = 0x0;
                                                            }
                                                            esi = esi + 0x1;
                                                            eax = *(int8_t *)esi;
                                                            if (eax != 0x0) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    esi = esi + 0x1;
                                                    eax = *(int8_t *)esi;
                                                    if (eax != ebx) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                    }
                                    else {
                                            if (var_8 == ebx) {
                                                    arg_4 = arg_4 | 0x20;
                                                    var_8 = 0x1;
                                            }
                                            else {
                                                    ecx = 0x0;
                                            }
                                            esi = esi + 0x1;
                                            eax = *(int8_t *)esi;
                                            if (eax != 0x0) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                            }
                            else {
                                    eax = eax - 0x54;
                                    if (eax != 0x0) {
                                            eax = eax - 0xe;
                                            if (eax != 0x0) {
                                                    eax = eax - 0x1;
                                                    if (eax != 0x0) {
                                                            eax = eax - 0xb;
                                                            if (eax != 0x0) {
                                                                    if (eax == 0x6) {
                                                                            if ((arg_4 & 0xc000) == 0x0) {
                                                                                    arg_4 = arg_4 | 0x4000;
                                                                            }
                                                                            else {
                                                                                    ecx = 0x0;
                                                                            }
                                                                            esi = esi + 0x1;
                                                                            eax = *(int8_t *)esi;
                                                                            if (eax != ebx) {
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x2;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (var_C == ebx) {
                                                                            var_4 = var_4 & 0xffffbfff;
                                                                            var_C = 0x1;
                                                                    }
                                                                    else {
                                                                            ecx = 0x0;
                                                                    }
                                                                    esi = esi + 0x1;
                                                                    eax = *(int8_t *)esi;
                                                                    if (eax != 0x0) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (var_C == ebx) {
                                                                    var_4 = var_4 | 0x4000;
                                                                    var_C = 0x1;
                                                                    esi = esi + 0x1;
                                                                    eax = *(int8_t *)esi;
                                                                    if (eax != 0x0) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = 0x0;
                                                                    esi = esi + 0x1;
                                                                    eax = *(int8_t *)esi;
                                                                    if (eax != 0x0) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if ((arg_4 & 0xc000) == 0x0) {
                                                            arg_4 = arg_4 | 0x8000;
                                                            esi = esi + 0x1;
                                                            eax = *(int8_t *)esi;
                                                            if (eax != ebx) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    else {
                                                            ecx = 0x0;
                                                            esi = esi + 0x1;
                                                            eax = *(int8_t *)esi;
                                                            if (eax != 0x0) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if ((arg_4 & 0x1000) != 0x0) {
                                                    ecx = 0x0;
                                                    esi = esi + 0x1;
                                                    eax = *(int8_t *)esi;
                                                    if (eax != ebx) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            else {
                                                    arg_4 = arg_4 | 0x1000;
                                                    esi = esi + 0x1;
                                                    eax = *(int8_t *)esi;
                                                    if (eax != 0x0) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                    }
                            }
                    }
                    switch (temp_0) {
                        case 0:
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = 0x0;
                            esp = esp + 0x4;
                            break;
                        case 1:
                            ebx = 0x0;
                            if (var_10 != 0x0) {
                                    while (*(int8_t *)esi == 0x20) {
                                            esi = esi + 0x1;
                                    }
                                    esp = (esp - 0xc) + 0xc;
                                    if (sub_48f26b("ccs=", esi, 0x4) == 0x0) {
                                            esi = esi + 0x4;
                                            esp = (esp - 0x8) + 0x8;
                                            if (sub_48f0ef(esi, "UTF-8") == 0x0) {
                                                    esi = esi + 0x5;
                                                    arg_4 = arg_4 | 0x40000;
                                                    while (*(int8_t *)esi == 0x20) {
                                                            esi = esi + 0x1;
                                                    }
                                                    if (*(int8_t *)esi != ebx) {
                                                            *sub_47d812() = 0x16;
                                                            sub_47a924();
                                                            esp = (esp - 0x14) + 0x14;
                                                            eax = 0x0;
                                                            esp = esp + 0x4;
                                                    }
                                                    else {
                                                            eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                                                            esp = (esp - 0x14) + 0x14;
                                                            if (eax != 0x0) {
                                                                    eax = 0x0;
                                                            }
                                                            else {
                                                                    eax = arg_c;
                                                                    *dword_bc6894 = *dword_bc6894 + 0x1;
                                                                    eax[0x3] = var_4;
                                                                    eax[0x1] = 0x0;
                                                                    *eax = 0x0;
                                                                    eax[0x2] = 0x0;
                                                                    eax[0x7] = 0x0;
                                                                    eax[0x4] = var_10;
                                                            }
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                            else {
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (sub_48f0ef(esi, "UTF-16LE") == 0x0) {
                                                            esi = esi + 0x8;
                                                            arg_4 = arg_4 | 0x20000;
                                                            while (*(int8_t *)esi == 0x20) {
                                                                    esi = esi + 0x1;
                                                            }
                                                            ebx = 0x0;
                                                            if (*(int8_t *)esi != 0x0) {
                                                                    *sub_47d812() = 0x16;
                                                                    sub_47a924();
                                                                    esp = (esp - 0x14) + 0x14;
                                                                    eax = 0x0;
                                                                    esp = esp + 0x4;
                                                            }
                                                            else {
                                                                    eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                                                                    esp = (esp - 0x14) + 0x14;
                                                                    if (eax != 0x0) {
                                                                            eax = 0x0;
                                                                    }
                                                                    else {
                                                                            eax = arg_c;
                                                                            *dword_bc6894 = *dword_bc6894 + 0x1;
                                                                            eax[0x3] = var_4;
                                                                            eax[0x1] = 0x0;
                                                                            *eax = 0x0;
                                                                            eax[0x2] = 0x0;
                                                                            eax[0x7] = 0x0;
                                                                            eax[0x4] = var_10;
                                                                    }
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                                    else {
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (sub_48f0ef(esi, "UNICODE") == 0x0) {
                                                                    esi = esi + 0x7;
                                                                    arg_4 = arg_4 | 0x10000;
                                                                    while (*(int8_t *)esi == 0x20) {
                                                                            esi = esi + 0x1;
                                                                    }
                                                                    if (*(int8_t *)esi != ebx) {
                                                                            *sub_47d812() = 0x16;
                                                                            sub_47a924();
                                                                            esp = (esp - 0x14) + 0x14;
                                                                            eax = 0x0;
                                                                            esp = esp + 0x4;
                                                                    }
                                                                    else {
                                                                            eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                                                                            esp = (esp - 0x14) + 0x14;
                                                                            if (eax != 0x0) {
                                                                                    eax = 0x0;
                                                                            }
                                                                            else {
                                                                                    eax = arg_c;
                                                                                    *dword_bc6894 = *dword_bc6894 + 0x1;
                                                                                    eax[0x3] = var_4;
                                                                                    eax[0x1] = 0x0;
                                                                                    *eax = 0x0;
                                                                                    eax[0x2] = 0x0;
                                                                                    eax[0x7] = 0x0;
                                                                                    eax[0x4] = var_10;
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    *sub_47d812() = 0x16;
                                                                    sub_47a924();
                                                                    esp = (esp - 0x14) + 0x14;
                                                                    eax = 0x0;
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            *sub_47d812() = 0x16;
                                            sub_47a924();
                                            esp = (esp - 0x14) + 0x14;
                                            eax = 0x0;
                                            esp = esp + 0x4;
                                    }
                            }
                            else {
                                    while (*(int8_t *)esi == 0x20) {
                                            esi = esi + 0x1;
                                    }
                                    if (*(int8_t *)esi != ebx) {
                                            *sub_47d812() = 0x16;
                                            sub_47a924();
                                            esp = (esp - 0x14) + 0x14;
                                            eax = 0x0;
                                            esp = esp + 0x4;
                                    }
                                    else {
                                            eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                                            esp = (esp - 0x14) + 0x14;
                                            if (eax != 0x0) {
                                                    eax = 0x0;
                                            }
                                            else {
                                                    eax = arg_c;
                                                    *dword_bc6894 = *dword_bc6894 + 0x1;
                                                    eax[0x3] = var_4;
                                                    eax[0x1] = 0x0;
                                                    *eax = 0x0;
                                                    eax[0x2] = 0x0;
                                                    eax[0x7] = 0x0;
                                                    eax[0x4] = var_10;
                                            }
                                            esp = esp + 0x4;
                                    }
                            }
                            break;
                        default:
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = 0x0;
                            esp = esp + 0x4;
                            break;
                    }
            }
            else {
                    while (*(int8_t *)esi == 0x20) {
                            esi = esi + 0x1;
                    }
                    if (*(int8_t *)esi != 0x0) {
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = 0x0;
                            esp = esp + 0x4;
                    }
                    else {
                            eax = sub_48eeb7(&var_10, arg_0, arg_4, arg_8, 0x180);
                            esp = (esp - 0x14) + 0x14;
                            if (eax != 0x0) {
                                    eax = 0x0;
                            }
                            else {
                                    eax = arg_c;
                                    *dword_bc6894 = *dword_bc6894 + 0x1;
                                    eax[0x3] = var_4;
                                    eax[0x1] = 0x0;
                                    *eax = 0x0;
                                    eax[0x2] = 0x0;
                                    eax[0x7] = 0x0;
                                    eax[0x4] = var_10;
                            }
                            esp = esp + 0x4;
                    }
            }
    }
    return eax;
}
