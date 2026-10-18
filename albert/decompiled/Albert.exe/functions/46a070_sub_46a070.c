// sub_46a070 @ 0x46a070
// hopper name: sub_46a070
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46a070() {
    var_C = *0x0;
    decomp_var_24 = ebx;
    decomp_var_28 = esi;
    decomp_var_2c = edi;
    decomp_var_30 = *dword_4c8db8 ^ ebp;
    *0x0 = &var_C;
    esi = arg_0;
    edi = 0x0;
    esp = esp - 0x34;
    sub_468ff0(esi);
    if (var_1C != 0x0) {
            ecx = *(*esi + 0x4);
            eax = *(ecx + esi + 0x18);
            ecx = ecx + esi;
            if (eax <= 0x1) {
                    edi = 0x0;
                    var_14 = 0x0;
            }
            else {
                    var_14 = eax - 0x1;
            }
            if ((ecx[0x4] & 0x1c0) != 0x40) {
                    while (true) {
                            if (edi != 0x0) {
                                    temp_1 = 0x0;
                                    break;
                            }
                            if (var_14 > edi) {
                                    ecx = *(*esi + 0x4) + esi;
                                    eax = ecx[0x30];
                                    ecx = ecx[0xa];
                                    if (*ecx[0x9] == edi) {
                                            esp = esp - 0x4;
                                            decomp_var_34 = eax & 0xff;
                                            eax = *(*ecx + 0x4);
                                            eax = (eax)(decomp_var_34);
                                            if (eax == 0xffffffff) {
                                                    edi = 0x4;
                                            }
                                            var_14 = var_14 - 0x1;
                                            continue;
                                    }
                                    edx = ecx[0xd];
                                    if (*edx > edi) {
                                            *edx = *edx - 0x1;
                                            ecx = ecx[0x9];
                                            edx = *ecx;
                                            *ecx = edx + 0x1;
                                            *(int8_t *)edx = eax;
                                            eax = eax & 0xff;
                                            if (eax == 0xffffffff) {
                                                    edi = 0x4;
                                            }
                                            var_14 = var_14 - 0x1;
                                            continue;
                                    }
                                    esp = esp - 0x4;
                                    decomp_var_34 = eax & 0xff;
                                    eax = *(*ecx + 0x4);
                                    eax = (eax)(decomp_var_34);
                                    if (eax == 0xffffffff) {
                                            edi = 0x4;
                                    }
                                    var_14 = var_14 - 0x1;
                                    continue;
                            }
                            temp_1 = 0x1;
                            break;
                    }
                    if (temp_1 != 0x0) {
                            ecx = *(*(*esi + 0x4) + esi + 0x28);
                            if (*ecx[0x9] != 0x0) {
                                    edx = ecx[0xd];
                                    if (*edx > 0x0) {
                                            *edx = *edx - 0x1;
                                            ecx = ecx[0x9];
                                            eax = *ecx;
                                            *ecx = eax + 0x1;
                                            *(int8_t *)eax = arg_4;
                                            eax = arg_4 & 0xff;
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            eax = *(*ecx + 0x4);
                                            eax = (eax)(arg_4 & 0xff);
                                    }
                            }
                            else {
                                    esp = esp - 0x4;
                                    eax = *(*ecx + 0x4);
                                    eax = (eax)(arg_4 & 0xff);
                            }
                            if (eax == 0xffffffff) {
                                    if (0x4 == 0x0) {
                                            if (var_14 > 0x4) {
                                                    edx = *(*esi + 0x4);
                                                    eax = *(int8_t *)(edx + esi + 0x30);
                                                    ecx = *(edx + esi + 0x28);
                                                    if (*ecx[0x9] != 0x4) {
                                                            edx = ecx[0xd];
                                                            if (*edx > 0x4) {
                                                                    *edx = *edx - 0x1;
                                                                    ecx = ecx[0x9];
                                                                    edx = *ecx;
                                                                    *ecx = edx + 0x1;
                                                                    *(int8_t *)edx = eax;
                                                                    eax = eax & 0xff;
                                                            }
                                                            else {
                                                                    esp = esp - 0x4;
                                                                    decomp_var_34 = eax & 0xff;
                                                                    eax = *(*ecx + 0x4);
                                                                    eax = (eax)(decomp_var_34);
                                                            }
                                                    }
                                                    else {
                                                            esp = esp - 0x4;
                                                            decomp_var_34 = eax & 0xff;
                                                            eax = *(*ecx + 0x4);
                                                            eax = (eax)(decomp_var_34);
                                                    }
                                                    var_14 = var_14 - 0x1;
                                                    while (true) {
                                                            if (0x4 != 0x0) {
                                                                    temp_0 = 0x0;
                                                                    break;
                                                            }
                                                            if (var_14 > 0x4) {
                                                                    edx = *(*esi + 0x4);
                                                                    eax = *(int8_t *)(edx + esi + 0x30);
                                                                    ecx = *(edx + esi + 0x28);
                                                                    if (*ecx[0x9] == 0x4) {
                                                                            esp = esp - 0x4;
                                                                            decomp_var_34 = eax & 0xff;
                                                                            eax = *(*ecx + 0x4);
                                                                            eax = (eax)(decomp_var_34);
                                                                            var_14 = var_14 - 0x1;
                                                                            continue;
                                                                    }
                                                                    edx = ecx[0xd];
                                                                    if (*edx > 0x4) {
                                                                            *edx = *edx - 0x1;
                                                                            ecx = ecx[0x9];
                                                                            edx = *ecx;
                                                                            *ecx = edx + 0x1;
                                                                            *(int8_t *)edx = eax;
                                                                            eax = eax & 0xff;
                                                                            var_14 = var_14 - 0x1;
                                                                            continue;
                                                                    }
                                                                    esp = esp - 0x4;
                                                                    decomp_var_34 = eax & 0xff;
                                                                    eax = *(*ecx + 0x4);
                                                                    eax = (eax)(decomp_var_34);
                                                                    var_14 = var_14 - 0x1;
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    *(*(*esi + 0x4) + esi + 0x18) = 0x0;
                                                    ecx = *esi;
                                                    ecx = ecx[0x1];
                                                    ecx = ecx + esi;
                                                    if (0x4 != 0x0) {
                                                            eax = ecx[0x2];
                                                            eax = eax | 0x4;
                                                            if (ecx[0xa] == 0x0) {
                                                                    eax = eax | 0x4;
                                                            }
                                                            esp = esp - 0x8;
                                                            sub_467d70(eax, 0x0);
                                                    }
                                                    if (sub_493721() == 0x0) {
                                                            sub_469080();
                                                    }
                                                    eax = *(*(*var_20 + 0x4) + var_20 + 0x28);
                                                    if (eax != 0x0) {
                                                            sub_493604();
                                                    }
                                                    eax = esi;
                                                    *0x0 = var_C;
                                                    &var_20 = ebp;
                                            }
                                            else {
                                                    *(*(*esi + 0x4) + esi + 0x18) = 0x0;
                                                    ecx = *esi;
                                                    ecx = ecx[0x1];
                                                    ecx = ecx + esi;
                                                    if (0x4 != 0x0) {
                                                            eax = ecx[0x2];
                                                            eax = eax | 0x4;
                                                            if (ecx[0xa] == 0x0) {
                                                                    eax = eax | 0x4;
                                                            }
                                                            esp = esp - 0x8;
                                                            sub_467d70(eax, 0x0);
                                                    }
                                                    if (sub_493721() == 0x0) {
                                                            sub_469080();
                                                    }
                                                    eax = *(*(*var_20 + 0x4) + var_20 + 0x28);
                                                    if (eax != 0x0) {
                                                            sub_493604();
                                                    }
                                                    eax = esi;
                                                    *0x0 = var_C;
                                                    &var_20 = ebp;
                                            }
                                    }
                                    else {
                                            *(*(*esi + 0x4) + esi + 0x18) = 0x0;
                                            ecx = *esi;
                                            ecx = ecx[0x1];
                                            ecx = ecx + esi;
                                            if (0x4 != 0x0) {
                                                    eax = ecx[0x2];
                                                    eax = eax | 0x4;
                                                    if (ecx[0xa] == 0x0) {
                                                            eax = eax | 0x4;
                                                    }
                                                    esp = esp - 0x8;
                                                    sub_467d70(eax, 0x0);
                                            }
                                            if (sub_493721() == 0x0) {
                                                    sub_469080();
                                            }
                                            eax = *(*(*var_20 + 0x4) + var_20 + 0x28);
                                            if (eax != 0x0) {
                                                    sub_493604();
                                            }
                                            eax = esi;
                                            *0x0 = var_C;
                                            &var_20 = ebp;
                                    }
                            }
                            else {
                                    while (true) {
                                            if (edi != 0x0) {
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                            if (var_14 > edi) {
                                                    edx = *(*esi + 0x4);
                                                    eax = *(int8_t *)(edx + esi + 0x30);
                                                    ecx = *(edx + esi + 0x28);
                                                    if (*ecx[0x9] == edi) {
                                                            esp = esp - 0x4;
                                                            decomp_var_34 = eax & 0xff;
                                                            eax = *(*ecx + 0x4);
                                                            eax = (eax)(decomp_var_34);
                                                            if (eax == 0xffffffff) {
                                                                    edi = 0x4;
                                                            }
                                                            var_14 = var_14 - 0x1;
                                                            continue;
                                                    }
                                                    edx = ecx[0xd];
                                                    if (*edx > edi) {
                                                            *edx = *edx - 0x1;
                                                            ecx = ecx[0x9];
                                                            edx = *ecx;
                                                            *ecx = edx + 0x1;
                                                            *(int8_t *)edx = eax;
                                                            eax = eax & 0xff;
                                                            if (eax == 0xffffffff) {
                                                                    edi = 0x4;
                                                            }
                                                            var_14 = var_14 - 0x1;
                                                            continue;
                                                    }
                                                    esp = esp - 0x4;
                                                    decomp_var_34 = eax & 0xff;
                                                    eax = *(*ecx + 0x4);
                                                    eax = (eax)(decomp_var_34);
                                                    if (eax == 0xffffffff) {
                                                            edi = 0x4;
                                                    }
                                                    var_14 = var_14 - 0x1;
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    *(*(*esi + 0x4) + esi + 0x18) = 0x0;
                                    ecx = *esi;
                                    ecx = ecx[0x1];
                                    ecx = ecx + esi;
                                    if (edi != 0x0) {
                                            eax = ecx[0x2];
                                            eax = eax | edi;
                                            if (ecx[0xa] == 0x0) {
                                                    eax = eax | 0x4;
                                            }
                                            esp = esp - 0x8;
                                            sub_467d70(eax, 0x0);
                                    }
                                    if (sub_493721() == 0x0) {
                                            sub_469080();
                                    }
                                    eax = *(*(*var_20 + 0x4) + var_20 + 0x28);
                                    if (eax != 0x0) {
                                            sub_493604();
                                    }
                                    eax = esi;
                                    *0x0 = var_C;
                                    &var_20 = ebp;
                            }
                    }
                    else {
                            *(*(*esi + 0x4) + esi + 0x18) = 0x0;
                            ecx = *esi;
                            ecx = ecx[0x1];
                            ecx = ecx + esi;
                            if (edi != 0x0) {
                                    eax = ecx[0x2];
                                    eax = eax | edi;
                                    if (ecx[0xa] == 0x0) {
                                            eax = eax | 0x4;
                                    }
                                    esp = esp - 0x8;
                                    sub_467d70(eax, 0x0);
                            }
                            if (sub_493721() == 0x0) {
                                    sub_469080();
                            }
                            eax = *(*(*var_20 + 0x4) + var_20 + 0x28);
                            if (eax != 0x0) {
                                    sub_493604();
                            }
                            eax = esi;
                            *0x0 = var_C;
                            &var_20 = ebp;
                    }
            }
            else {
                    ecx = *(*(*esi + 0x4) + esi + 0x28);
                    if (*ecx[0x9] != 0x0) {
                            edx = ecx[0xd];
                            if (*edx > 0x0) {
                                    *edx = *edx - 0x1;
                                    ecx = ecx[0x9];
                                    eax = *ecx;
                                    *ecx = eax + 0x1;
                                    *(int8_t *)eax = arg_4;
                                    eax = arg_4 & 0xff;
                            }
                            else {
                                    esp = esp - 0x4;
                                    eax = *(*ecx + 0x4);
                                    eax = (eax)(arg_4 & 0xff);
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            eax = *(*ecx + 0x4);
                            eax = (eax)(arg_4 & 0xff);
                    }
                    if (eax == 0xffffffff) {
                            if (0x4 == 0x0) {
                                    if (var_14 > 0x4) {
                                            edx = *(*esi + 0x4);
                                            eax = *(int8_t *)(edx + esi + 0x30);
                                            ecx = *(edx + esi + 0x28);
                                            if (*ecx[0x9] != 0x4) {
                                                    edx = ecx[0xd];
                                                    if (*edx > 0x4) {
                                                            *edx = *edx - 0x1;
                                                            ecx = ecx[0x9];
                                                            edx = *ecx;
                                                            *ecx = edx + 0x1;
                                                            *(int8_t *)edx = eax;
                                                            eax = eax & 0xff;
                                                    }
                                                    else {
                                                            esp = esp - 0x4;
                                                            decomp_var_34 = eax & 0xff;
                                                            eax = *(*ecx + 0x4);
                                                            eax = (eax)(decomp_var_34);
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_34 = eax & 0xff;
                                                    eax = *(*ecx + 0x4);
                                                    eax = (eax)(decomp_var_34);
                                            }
                                            var_14 = var_14 - 0x1;
                                            while (true) {
                                                    if (0x4 != 0x0) {
                                                            temp_0 = 0x0;
                                                            break;
                                                    }
                                                    if (var_14 > 0x4) {
                                                            edx = *(*esi + 0x4);
                                                            eax = *(int8_t *)(edx + esi + 0x30);
                                                            ecx = *(edx + esi + 0x28);
                                                            if (*ecx[0x9] == 0x4) {
                                                                    esp = esp - 0x4;
                                                                    decomp_var_34 = eax & 0xff;
                                                                    eax = *(*ecx + 0x4);
                                                                    eax = (eax)(decomp_var_34);
                                                                    var_14 = var_14 - 0x1;
                                                                    continue;
                                                            }
                                                            edx = ecx[0xd];
                                                            if (*edx > 0x4) {
                                                                    *edx = *edx - 0x1;
                                                                    ecx = ecx[0x9];
                                                                    edx = *ecx;
                                                                    *ecx = edx + 0x1;
                                                                    *(int8_t *)edx = eax;
                                                                    eax = eax & 0xff;
                                                                    var_14 = var_14 - 0x1;
                                                                    continue;
                                                            }
                                                            esp = esp - 0x4;
                                                            decomp_var_34 = eax & 0xff;
                                                            eax = *(*ecx + 0x4);
                                                            eax = (eax)(decomp_var_34);
                                                            var_14 = var_14 - 0x1;
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            *(*(*esi + 0x4) + esi + 0x18) = 0x0;
                                            ecx = *esi;
                                            ecx = ecx[0x1];
                                            ecx = ecx + esi;
                                            if (0x4 != 0x0) {
                                                    eax = ecx[0x2];
                                                    eax = eax | 0x4;
                                                    if (ecx[0xa] == 0x0) {
                                                            eax = eax | 0x4;
                                                    }
                                                    esp = esp - 0x8;
                                                    sub_467d70(eax, 0x0);
                                            }
                                            if (sub_493721() == 0x0) {
                                                    sub_469080();
                                            }
                                            eax = *(*(*var_20 + 0x4) + var_20 + 0x28);
                                            if (eax != 0x0) {
                                                    sub_493604();
                                            }
                                            eax = esi;
                                            *0x0 = var_C;
                                            &var_20 = ebp;
                                    }
                                    else {
                                            *(*(*esi + 0x4) + esi + 0x18) = 0x0;
                                            ecx = *esi;
                                            ecx = ecx[0x1];
                                            ecx = ecx + esi;
                                            if (0x4 != 0x0) {
                                                    eax = ecx[0x2];
                                                    eax = eax | 0x4;
                                                    if (ecx[0xa] == 0x0) {
                                                            eax = eax | 0x4;
                                                    }
                                                    esp = esp - 0x8;
                                                    sub_467d70(eax, 0x0);
                                            }
                                            if (sub_493721() == 0x0) {
                                                    sub_469080();
                                            }
                                            eax = *(*(*var_20 + 0x4) + var_20 + 0x28);
                                            if (eax != 0x0) {
                                                    sub_493604();
                                            }
                                            eax = esi;
                                            *0x0 = var_C;
                                            &var_20 = ebp;
                                    }
                            }
                            else {
                                    *(*(*esi + 0x4) + esi + 0x18) = 0x0;
                                    ecx = *esi;
                                    ecx = ecx[0x1];
                                    ecx = ecx + esi;
                                    if (0x4 != 0x0) {
                                            eax = ecx[0x2];
                                            eax = eax | 0x4;
                                            if (ecx[0xa] == 0x0) {
                                                    eax = eax | 0x4;
                                            }
                                            esp = esp - 0x8;
                                            sub_467d70(eax, 0x0);
                                    }
                                    if (sub_493721() == 0x0) {
                                            sub_469080();
                                    }
                                    eax = *(*(*var_20 + 0x4) + var_20 + 0x28);
                                    if (eax != 0x0) {
                                            sub_493604();
                                    }
                                    eax = esi;
                                    *0x0 = var_C;
                                    &var_20 = ebp;
                            }
                    }
                    else {
                            while (true) {
                                    if (edi != 0x0) {
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    if (var_14 > edi) {
                                            edx = *(*esi + 0x4);
                                            eax = *(int8_t *)(edx + esi + 0x30);
                                            ecx = *(edx + esi + 0x28);
                                            if (*ecx[0x9] == edi) {
                                                    esp = esp - 0x4;
                                                    decomp_var_34 = eax & 0xff;
                                                    eax = *(*ecx + 0x4);
                                                    eax = (eax)(decomp_var_34);
                                                    if (eax == 0xffffffff) {
                                                            edi = 0x4;
                                                    }
                                                    var_14 = var_14 - 0x1;
                                                    continue;
                                            }
                                            edx = ecx[0xd];
                                            if (*edx > edi) {
                                                    *edx = *edx - 0x1;
                                                    ecx = ecx[0x9];
                                                    edx = *ecx;
                                                    *ecx = edx + 0x1;
                                                    *(int8_t *)edx = eax;
                                                    eax = eax & 0xff;
                                                    if (eax == 0xffffffff) {
                                                            edi = 0x4;
                                                    }
                                                    var_14 = var_14 - 0x1;
                                                    continue;
                                            }
                                            esp = esp - 0x4;
                                            decomp_var_34 = eax & 0xff;
                                            eax = *(*ecx + 0x4);
                                            eax = (eax)(decomp_var_34);
                                            if (eax == 0xffffffff) {
                                                    edi = 0x4;
                                            }
                                            var_14 = var_14 - 0x1;
                                            continue;
                                    }
                                    temp_0 = 0x1;
                                    break;
                            }
                            *(*(*esi + 0x4) + esi + 0x18) = 0x0;
                            ecx = *esi;
                            ecx = ecx[0x1];
                            ecx = ecx + esi;
                            if (edi != 0x0) {
                                    eax = ecx[0x2];
                                    eax = eax | edi;
                                    if (ecx[0xa] == 0x0) {
                                            eax = eax | 0x4;
                                    }
                                    esp = esp - 0x8;
                                    sub_467d70(eax, 0x0);
                            }
                            if (sub_493721() == 0x0) {
                                    sub_469080();
                            }
                            eax = *(*(*var_20 + 0x4) + var_20 + 0x28);
                            if (eax != 0x0) {
                                    sub_493604();
                            }
                            eax = esi;
                            *0x0 = var_C;
                            &var_20 = ebp;
                    }
            }
    }
    else {
            *(*(*esi + 0x4) + esi + 0x18) = 0x0;
            ecx = *esi;
            ecx = ecx[0x1];
            ecx = ecx + esi;
            if (0x0 != 0x0) {
                    eax = ecx[0x2];
                    eax = eax | 0x0;
                    if (ecx[0xa] == 0x0) {
                            eax = eax | 0x4;
                    }
                    esp = esp - 0x8;
                    sub_467d70(eax, 0x0);
            }
            if (sub_493721() == 0x0) {
                    sub_469080();
            }
            eax = *(*(*var_20 + 0x4) + var_20 + 0x28);
            if (eax != 0x0) {
                    sub_493604();
            }
            eax = esi;
            *0x0 = var_C;
            &var_20 = ebp;
    }
    return eax;
}
