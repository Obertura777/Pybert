// sub_4892d7 @ 0x4892d7
// hopper name: sub_4892d7
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4892d7() {
    decomp_var_18 = ebx;
    esp = esp - 0x8;
    decomp_var_1c = esi;
    esi = arg_0;
    if (arg_c == 0x0) {
            if (esi == 0x0) {
                    if (arg_4 == 0x0) {
                            eax = 0x0;
                    }
                    else {
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                            eax = 0x16;
                    }
            }
            else {
                    ebx = 0x0;
                    if (arg_4 <= 0x0) {
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                            eax = 0x16;
                    }
                    else {
                            if (arg_c == ebx) {
                                    *(int8_t *)esi = ebx;
                                    eax = 0x0;
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_20 = edi;
                                    edi = arg_8;
                                    if (edi == 0x0) {
                                            *(int8_t *)esi = 0x0;
                                            *sub_47d812() = 0x16;
                                            sub_47a924();
                                            esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                                            eax = 0x16;
                                            esp = esp + 0x4;
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            sub_47aea2(arg_10);
                                            if (var_10[0x2] == 0x0) {
                                                    eax = sub_47f4a4(esi, arg_4, edi, arg_c);
                                                    esp = (esp - 0x10) + 0x10;
                                                    if (var_8 != 0x0) {
                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                    }
                                                    esp = esp + 0x4;
                                            }
                                            else {
                                                    edx = arg_4;
                                                    eax = esi;
                                                    if (arg_c == 0xffffffff) {
                                                            do {
                                                                    ecx = *(int8_t *)edi;
                                                                    *(int8_t *)eax = ecx;
                                                                    eax = eax + 0x1;
                                                                    edi = edi + 0x1;
                                                                    if (ecx == 0x0) {
                                                                            break;
                                                                    }
                                                                    edx = edx - 0x1;
                                                            } while (edx != 0x0);
                                                    }
                                                    else {
                                                            while (true) {
                                                                    ecx = *(int8_t *)edi;
                                                                    *(int8_t *)eax = ecx;
                                                                    eax = eax + 0x1;
                                                                    edi = edi + 0x1;
                                                                    if (ecx == 0x0) {
                                                                            temp_0 = 0x0;
                                                                            break;
                                                                    }
                                                                    edx = edx - 0x1;
                                                                    if (edx == 0x0) {
                                                                            temp_0 = 0x0;
                                                                            break;
                                                                    }
                                                                    arg_c = arg_c - 0x1;
                                                                    if (arg_c != 0x0) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                            ebx = 0x0;
                                                            if (arg_c == 0x0) {
                                                                    *(int8_t *)eax = ebx;
                                                                    eax = eax + 0x1;
                                                            }
                                                    }
                                                    ebx = 0x0;
                                                    if (edx == 0x0) {
                                                            if (*(int8_t *)edi != ebx) {
                                                                    if (arg_c == 0x1) {
                                                                            edi = eax - 0x1;
                                                                            var_4 = edi;
                                                                            if (edi >= esi) {
                                                                                    while (true) {
                                                                                            eax = *(int8_t *)var_4 & 0xff;
                                                                                            eax = sub_47f619(eax, &var_14);
                                                                                            esp = (esp - 0x8) + 0x8;
                                                                                            if (eax == 0x0) {
                                                                                                    temp_1 = 0x0;
                                                                                                    break;
                                                                                            }
                                                                                            var_4 = var_4 - 0x1;
                                                                                            if (var_4 >= esi) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x1;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            if ((edi - var_4 & 0x1) == 0x0) {
                                                                                    if (arg_c == 0xffffffff) {
                                                                                            eax = arg_4;
                                                                                            if (eax > 0x1) {
                                                                                                    edi = esi + (eax - 0x2);
                                                                                                    arg_c = edi;
                                                                                                    if (edi >= esi) {
                                                                                                            do {
                                                                                                                    eax = *(int8_t *)arg_c & 0xff;
                                                                                                                    eax = sub_47f619(eax, &var_14);
                                                                                                                    esp = (esp - 0x8) + 0x8;
                                                                                                                    if (eax == 0x0) {
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    arg_c = arg_c - 0x1;
                                                                                                            } while (arg_c >= esi);
                                                                                                            eax = arg_4;
                                                                                                    }
                                                                                                    if ((edi - arg_c & 0x1) != 0x0) {
                                                                                                            *(int8_t *)edi = ebx;
                                                                                                    }
                                                                                                    else {
                                                                                                            *(int8_t *)(esi + (eax - 0x1)) = ebx;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    *(int8_t *)(esi + (eax - 0x1)) = ebx;
                                                                                            }
                                                                                            if (var_8 != 0x0) {
                                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                            }
                                                                                            eax = 0x50;
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                    }
                                                                                    else {
                                                                                            *(int8_t *)esi = ebx;
                                                                                            *sub_47d812() = 0x22;
                                                                                            sub_47a924();
                                                                                            esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                                                                                            if (var_8 != ebx) {
                                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                            }
                                                                                            eax = 0x22;
                                                                                    }
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                            else {
                                                                                    *(int8_t *)edi = ebx;
                                                                                    ecx = sub_47d812();
                                                                                    eax = 0x2a;
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    *ecx = 0x2a;
                                                                                    if (var_8 != ebx) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                    }
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (arg_c == 0xffffffff) {
                                                                                    eax = arg_4;
                                                                                    if (eax > 0x1) {
                                                                                            edi = esi + (eax - 0x2);
                                                                                            arg_c = edi;
                                                                                            if (edi >= esi) {
                                                                                                    do {
                                                                                                            eax = *(int8_t *)arg_c & 0xff;
                                                                                                            eax = sub_47f619(eax, &var_14);
                                                                                                            esp = (esp - 0x8) + 0x8;
                                                                                                            if (eax == 0x0) {
                                                                                                                    break;
                                                                                                            }
                                                                                                            arg_c = arg_c - 0x1;
                                                                                                    } while (arg_c >= esi);
                                                                                                    eax = arg_4;
                                                                                            }
                                                                                            if ((edi - arg_c & 0x1) != 0x0) {
                                                                                                    *(int8_t *)edi = ebx;
                                                                                            }
                                                                                            else {
                                                                                                    *(int8_t *)(esi + (eax - 0x1)) = ebx;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            *(int8_t *)(esi + (eax - 0x1)) = ebx;
                                                                                    }
                                                                                    if (var_8 != ebx) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                    }
                                                                                    eax = 0x50;
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            else {
                                                                                    *(int8_t *)esi = ebx;
                                                                                    *sub_47d812() = 0x22;
                                                                                    sub_47a924();
                                                                                    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                                                                                    if (var_8 != ebx) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                    }
                                                                                    eax = 0x22;
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    edi = eax - 0x1;
                                                                    var_4 = edi;
                                                                    if (edi >= esi) {
                                                                            while (true) {
                                                                                    eax = *(int8_t *)var_4 & 0xff;
                                                                                    eax = sub_47f619(eax, &var_14);
                                                                                    esp = (esp - 0x8) + 0x8;
                                                                                    if (eax == 0x0) {
                                                                                            temp_1 = 0x0;
                                                                                            break;
                                                                                    }
                                                                                    var_4 = var_4 - 0x1;
                                                                                    if (var_4 >= esi) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x1;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    if ((edi - var_4 & 0x1) == 0x0) {
                                                                            if (arg_c == 0xffffffff) {
                                                                                    eax = arg_4;
                                                                                    if (eax > 0x1) {
                                                                                            edi = esi + (eax - 0x2);
                                                                                            arg_c = edi;
                                                                                            if (edi >= esi) {
                                                                                                    do {
                                                                                                            eax = *(int8_t *)arg_c & 0xff;
                                                                                                            eax = sub_47f619(eax, &var_14);
                                                                                                            esp = (esp - 0x8) + 0x8;
                                                                                                            if (eax == 0x0) {
                                                                                                                    break;
                                                                                                            }
                                                                                                            arg_c = arg_c - 0x1;
                                                                                                    } while (arg_c >= esi);
                                                                                                    eax = arg_4;
                                                                                            }
                                                                                            if ((edi - arg_c & 0x1) != 0x0) {
                                                                                                    *(int8_t *)edi = ebx;
                                                                                            }
                                                                                            else {
                                                                                                    *(int8_t *)(esi + (eax - 0x1)) = ebx;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            *(int8_t *)(esi + (eax - 0x1)) = ebx;
                                                                                    }
                                                                                    if (var_8 != ebx) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                    }
                                                                                    eax = 0x50;
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            else {
                                                                                    *(int8_t *)esi = ebx;
                                                                                    *sub_47d812() = 0x22;
                                                                                    sub_47a924();
                                                                                    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                                                                                    if (var_8 != ebx) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                    }
                                                                                    eax = 0x22;
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                                    else {
                                                                            *(int8_t *)edi = 0x0;
                                                                            ecx = sub_47d812();
                                                                            eax = 0x2a;
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            *ecx = 0x2a;
                                                                            if (var_8 != 0x0) {
                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (eax - esi >= 0x2) {
                                                                    edi = eax - 0x2;
                                                                    arg_c = edi;
                                                                    if (edi >= esi) {
                                                                            while (true) {
                                                                                    eax = *(int8_t *)arg_c & 0xff;
                                                                                    eax = sub_47f619(eax, &var_14);
                                                                                    esp = (esp - 0x8) + 0x8;
                                                                                    if (eax == 0x0) {
                                                                                            temp_2 = 0x0;
                                                                                            break;
                                                                                    }
                                                                                    arg_c = arg_c - 0x1;
                                                                                    if (arg_c >= esi) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_2 = 0x1;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    if ((edi - arg_c & 0x1) != 0x0) {
                                                                            *(int8_t *)edi = 0x0;
                                                                            ecx = sub_47d812();
                                                                            eax = 0x2a;
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            *ecx = 0x2a;
                                                                            if (var_8 != 0x0) {
                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                                    else {
                                                                            if (var_8 != 0x0) {
                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                            }
                                                                            eax = 0x0;
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    if (var_8 != 0x0) {
                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                    }
                                                                    eax = 0x0;
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }
    else {
            if (esi != 0x0) {
                    if (arg_4 <= 0x0) {
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                            eax = 0x16;
                    }
                    else {
                            if (arg_c == 0x0) {
                                    *(int8_t *)esi = 0x0;
                                    eax = 0x0;
                            }
                            else {
                                    ebx = 0x0;
                                    esp = esp - 0x4;
                                    decomp_var_20 = edi;
                                    edi = arg_8;
                                    if (edi == 0x0) {
                                            *(int8_t *)esi = ebx;
                                            *sub_47d812() = 0x16;
                                            sub_47a924();
                                            esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                                            eax = 0x16;
                                            esp = esp + 0x4;
                                    }
                                    else {
                                            ebx = 0x0;
                                            esp = esp - 0x4;
                                            sub_47aea2(arg_10);
                                            if (var_10[0x2] == 0x0) {
                                                    eax = sub_47f4a4(esi, arg_4, edi, arg_c);
                                                    esp = (esp - 0x10) + 0x10;
                                                    if (var_8 != ebx) {
                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                    }
                                                    esp = esp + 0x4;
                                            }
                                            else {
                                                    edx = arg_4;
                                                    eax = esi;
                                                    if (arg_c == 0xffffffff) {
                                                            do {
                                                                    ecx = *(int8_t *)edi;
                                                                    *(int8_t *)eax = ecx;
                                                                    eax = eax + 0x1;
                                                                    edi = edi + 0x1;
                                                                    if (ecx == ebx) {
                                                                            break;
                                                                    }
                                                                    edx = edx - 0x1;
                                                            } while (edx != 0x0);
                                                    }
                                                    else {
                                                            while (true) {
                                                                    ecx = *(int8_t *)edi;
                                                                    *(int8_t *)eax = ecx;
                                                                    eax = eax + 0x1;
                                                                    edi = edi + 0x1;
                                                                    if (ecx == ebx) {
                                                                            temp_0 = 0x0;
                                                                            break;
                                                                    }
                                                                    edx = edx - 0x1;
                                                                    if (edx == 0x0) {
                                                                            temp_0 = 0x0;
                                                                            break;
                                                                    }
                                                                    arg_c = arg_c - 0x1;
                                                                    if (arg_c != 0x0) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                            ebx = 0x0;
                                                            if (arg_c == 0x0) {
                                                                    *(int8_t *)eax = ebx;
                                                                    eax = eax + 0x1;
                                                            }
                                                    }
                                                    if (edx == ebx) {
                                                            if (*(int8_t *)edi != ebx) {
                                                                    if (arg_c == 0x1) {
                                                                            edi = eax - 0x1;
                                                                            var_4 = edi;
                                                                            if (edi >= esi) {
                                                                                    while (true) {
                                                                                            eax = *(int8_t *)var_4 & 0xff;
                                                                                            eax = sub_47f619(eax, &var_14);
                                                                                            esp = (esp - 0x8) + 0x8;
                                                                                            if (eax == 0x0) {
                                                                                                    temp_1 = 0x0;
                                                                                                    break;
                                                                                            }
                                                                                            var_4 = var_4 - 0x1;
                                                                                            if (var_4 >= esi) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x1;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            if ((edi - var_4 & 0x1) == 0x0) {
                                                                                    if (arg_c == 0xffffffff) {
                                                                                            eax = arg_4;
                                                                                            if (eax > 0x1) {
                                                                                                    edi = esi + (eax - 0x2);
                                                                                                    arg_c = edi;
                                                                                                    if (edi >= esi) {
                                                                                                            do {
                                                                                                                    eax = *(int8_t *)arg_c & 0xff;
                                                                                                                    eax = sub_47f619(eax, &var_14);
                                                                                                                    esp = (esp - 0x8) + 0x8;
                                                                                                                    if (eax == 0x0) {
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    arg_c = arg_c - 0x1;
                                                                                                            } while (arg_c >= esi);
                                                                                                            eax = arg_4;
                                                                                                    }
                                                                                                    if ((edi - arg_c & 0x1) != 0x0) {
                                                                                                            *(int8_t *)edi = ebx;
                                                                                                    }
                                                                                                    else {
                                                                                                            *(int8_t *)(esi + (eax - 0x1)) = ebx;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    *(int8_t *)(esi + (eax - 0x1)) = ebx;
                                                                                            }
                                                                                            if (var_8 != ebx) {
                                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                            }
                                                                                            eax = 0x50;
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                    }
                                                                                    else {
                                                                                            *(int8_t *)esi = ebx;
                                                                                            *sub_47d812() = 0x22;
                                                                                            sub_47a924();
                                                                                            esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                                                                                            if (var_8 != ebx) {
                                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                            }
                                                                                            eax = 0x22;
                                                                                    }
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                            else {
                                                                                    *(int8_t *)edi = ebx;
                                                                                    ecx = sub_47d812();
                                                                                    eax = 0x2a;
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    *ecx = 0x2a;
                                                                                    if (var_8 != ebx) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                    }
                                                                                    esp = esp + 0x4;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (arg_c == 0xffffffff) {
                                                                                    eax = arg_4;
                                                                                    if (eax > 0x1) {
                                                                                            edi = esi + (eax - 0x2);
                                                                                            arg_c = edi;
                                                                                            if (edi >= esi) {
                                                                                                    do {
                                                                                                            eax = *(int8_t *)arg_c & 0xff;
                                                                                                            eax = sub_47f619(eax, &var_14);
                                                                                                            esp = (esp - 0x8) + 0x8;
                                                                                                            if (eax == 0x0) {
                                                                                                                    break;
                                                                                                            }
                                                                                                            arg_c = arg_c - 0x1;
                                                                                                    } while (arg_c >= esi);
                                                                                                    eax = arg_4;
                                                                                            }
                                                                                            if ((edi - arg_c & 0x1) != 0x0) {
                                                                                                    *(int8_t *)edi = ebx;
                                                                                            }
                                                                                            else {
                                                                                                    *(int8_t *)(esi + (eax - 0x1)) = ebx;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            *(int8_t *)(esi + (eax - 0x1)) = ebx;
                                                                                    }
                                                                                    if (var_8 != ebx) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                    }
                                                                                    eax = 0x50;
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            else {
                                                                                    *(int8_t *)esi = ebx;
                                                                                    *sub_47d812() = 0x22;
                                                                                    sub_47a924();
                                                                                    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                                                                                    if (var_8 != ebx) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                    }
                                                                                    eax = 0x22;
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    edi = eax - 0x1;
                                                                    var_4 = edi;
                                                                    if (edi >= esi) {
                                                                            while (true) {
                                                                                    eax = *(int8_t *)var_4 & 0xff;
                                                                                    eax = sub_47f619(eax, &var_14);
                                                                                    esp = (esp - 0x8) + 0x8;
                                                                                    if (eax == 0x0) {
                                                                                            temp_1 = 0x0;
                                                                                            break;
                                                                                    }
                                                                                    var_4 = var_4 - 0x1;
                                                                                    if (var_4 >= esi) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x1;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    if ((edi - var_4 & 0x1) == 0x0) {
                                                                            if (arg_c == 0xffffffff) {
                                                                                    eax = arg_4;
                                                                                    if (eax > 0x1) {
                                                                                            edi = esi + (eax - 0x2);
                                                                                            arg_c = edi;
                                                                                            if (edi >= esi) {
                                                                                                    do {
                                                                                                            eax = *(int8_t *)arg_c & 0xff;
                                                                                                            eax = sub_47f619(eax, &var_14);
                                                                                                            esp = (esp - 0x8) + 0x8;
                                                                                                            if (eax == 0x0) {
                                                                                                                    break;
                                                                                                            }
                                                                                                            arg_c = arg_c - 0x1;
                                                                                                    } while (arg_c >= esi);
                                                                                                    eax = arg_4;
                                                                                            }
                                                                                            if ((edi - arg_c & 0x1) != 0x0) {
                                                                                                    *(int8_t *)edi = ebx;
                                                                                            }
                                                                                            else {
                                                                                                    *(int8_t *)(esi + (eax - 0x1)) = ebx;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            *(int8_t *)(esi + (eax - 0x1)) = ebx;
                                                                                    }
                                                                                    if (var_8 != ebx) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                    }
                                                                                    eax = 0x50;
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                            }
                                                                            else {
                                                                                    *(int8_t *)esi = ebx;
                                                                                    *sub_47d812() = 0x22;
                                                                                    sub_47a924();
                                                                                    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                                                                                    if (var_8 != ebx) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                    }
                                                                                    eax = 0x22;
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                                    else {
                                                                            *(int8_t *)edi = ebx;
                                                                            ecx = sub_47d812();
                                                                            eax = 0x2a;
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            *ecx = 0x2a;
                                                                            if (var_8 != ebx) {
                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (eax - esi >= 0x2) {
                                                                    edi = eax - 0x2;
                                                                    arg_c = edi;
                                                                    if (edi >= esi) {
                                                                            while (true) {
                                                                                    eax = *(int8_t *)arg_c & 0xff;
                                                                                    eax = sub_47f619(eax, &var_14);
                                                                                    esp = (esp - 0x8) + 0x8;
                                                                                    if (eax == 0x0) {
                                                                                            temp_2 = 0x0;
                                                                                            break;
                                                                                    }
                                                                                    arg_c = arg_c - 0x1;
                                                                                    if (arg_c >= esi) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_2 = 0x1;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    if ((edi - arg_c & 0x1) != 0x0) {
                                                                            *(int8_t *)edi = ebx;
                                                                            ecx = sub_47d812();
                                                                            eax = 0x2a;
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            *ecx = 0x2a;
                                                                            if (var_8 != ebx) {
                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                            }
                                                                            esp = esp + 0x4;
                                                                    }
                                                                    else {
                                                                            if (var_8 != 0x0) {
                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                            }
                                                                            eax = 0x0;
                                                                            esp = esp + 0x4;
                                                                    }
                                                            }
                                                            else {
                                                                    if (var_8 != ebx) {
                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                    }
                                                                    eax = 0x0;
                                                                    esp = esp + 0x4;
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                    eax = 0x16;
            }
    }
    return eax;
}
