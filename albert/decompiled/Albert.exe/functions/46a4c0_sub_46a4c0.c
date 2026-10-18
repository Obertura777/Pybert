// sub_46a4c0 @ 0x46a4c0
// hopper name: sub_46a4c0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46a4c0() {
    var_C = *0x0;
    decomp_var_28 = ebx;
    decomp_var_2c = esi;
    decomp_var_30 = edi;
    esp = esp - 0x34;
    var_34 = *dword_4c8db8 ^ ebp;
    *0x0 = &var_C;
    edi = arg_0;
    ebx = arg_4;
    eax = *(*(*edi + 0x4) + edi + 0x18);
    ecx = ebx[0x5];
    var_14 = 0x0;
    var_1C = ecx;
    if (eax > 0x0 && eax > ecx) {
            var_18 = eax - ecx;
    }
    else {
            var_18 = 0x0;
    }
    esi = 0x0;
    esp = esp - 0x4;
    sub_468ff0(edi);
    if (var_20 == 0x0) {
            var_14 = 0x4;
            ecx = *edi;
            ecx = ecx[0x1];
            edx = var_14;
            ecx = ecx + edi;
            if (edx != 0x0) {
                    eax = ecx[0x2];
                    eax = eax | edx;
                    if (ecx[0xa] == 0x0) {
                            eax = eax | 0x4;
                    }
                    esp = esp - 0x8;
                    sub_467d70(eax, 0x0);
            }
            if (sub_493721() == 0x0) {
                    sub_469080();
            }
            eax = *(*(*var_24 + 0x4) + var_24 + 0x28);
            if (eax != 0x0) {
                    sub_493604();
            }
            eax = edi;
            *0x0 = var_C;
            &var_24 = ebp;
    }
    else {
            if ((*(*(*edi + 0x4) + edi + 0x10) & 0x1c0) != 0x40) {
                    &var_34 = &var_34;
                    while (var_18 > 0x0) {
                            ecx = *(*edi + 0x4) + edi;
                            eax = ecx[0x30];
                            ecx = ecx[0xa];
                            if (*ecx[0x9] == 0x0) {
                                    esp = esp - 0x4;
                                    decomp_var_38 = eax & 0xff;
                                    eax = *(*ecx + 0x4);
                                    eax = (eax)(decomp_var_38);
                                    if (eax != 0xffffffff) {
                                            var_18 = var_18 - 0x1;
                                            continue;
                                    }
                                    var_14 = var_14 | 0x4;
                                    break;
                            }
                            edx = ecx[0xd];
                            if (*edx <= 0x0) {
                                    esp = esp - 0x4;
                                    decomp_var_38 = eax & 0xff;
                                    eax = *(*ecx + 0x4);
                                    eax = (eax)(decomp_var_38);
                                    if (eax != 0xffffffff) {
                                            var_18 = var_18 - 0x1;
                                            continue;
                                    }
                                    var_14 = var_14 | 0x4;
                                    break;
                            }
                            *edx = *edx - 0x1;
                            ecx = ecx[0x9];
                            edx = *ecx;
                            *ecx = edx + 0x1;
                            *(int8_t *)edx = eax;
                            eax = eax & 0xff;
                            if (eax != 0xffffffff) {
                                    var_18 = var_18 - 0x1;
                                    continue;
                            }
                            var_14 = var_14 | 0x4;
                            break;
                    }
                    if (var_14 == 0x0) {
                            if (0x0 < var_1C) {
                                    if (0x0 > ebx[0x5]) {
                                            sub_47a948();
                                    }
                                    if (ebx[0x6] >= 0x10) {
                                            eax = ebx[0x1];
                                    }
                                    else {
                                            eax = ebx + 0x4;
                                    }
                                    ecx = *(*(*edi + 0x4) + edi + 0x28);
                                    bool_21 = *ecx[0x9] == 0x0;
                                    eax = eax[0x0];
                                    if (!bool_21) {
                                            edx = ecx[0xd];
                                            if (*edx > 0x0) {
                                                    *edx = *edx - 0x1;
                                                    ecx = ecx[0x9];
                                                    edx = *ecx;
                                                    *ecx = edx + 0x1;
                                                    ebx = arg_4;
                                                    *(int8_t *)edx = eax;
                                                    eax = eax & 0xff;
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_38 = eax & 0xff;
                                                    eax = *(*ecx + 0x4);
                                                    eax = (eax)(decomp_var_38);
                                            }
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_38 = eax & 0xff;
                                            eax = *(*ecx + 0x4);
                                            eax = (eax)(decomp_var_38);
                                    }
                                    if (eax == 0xffffffff) {
                                            var_14 = var_14 | 0x4;
                                    }
                                    else {
                                            esi = 0x1;
                                            while (true) {
                                                    if (esi >= var_1C) {
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    if (esi > ebx[0x5]) {
                                                            sub_47a948();
                                                    }
                                                    if (ebx[0x6] >= 0x10) {
                                                            eax = ebx[0x1];
                                                    }
                                                    else {
                                                            eax = ebx + 0x4;
                                                    }
                                                    ecx = *(*(*edi + 0x4) + edi + 0x28);
                                                    bool_36 = *ecx[0x9] == 0x0;
                                                    eax = *(int8_t *)(eax + esi);
                                                    if (bool_36) {
                                                            esp = esp - 0x4;
                                                            decomp_var_38 = eax & 0xff;
                                                            eax = *(*ecx + 0x4);
                                                            eax = (eax)(decomp_var_38);
                                                            if (eax != 0xffffffff) {
                                                                    esi = esi + 0x1;
                                                                    continue;
                                                            }
                                                            temp_0 = 0x0;
                                                            break;
                                                    }
                                                    edx = ecx[0xd];
                                                    if (*edx <= 0x0) {
                                                            esp = esp - 0x4;
                                                            decomp_var_38 = eax & 0xff;
                                                            eax = *(*ecx + 0x4);
                                                            eax = (eax)(decomp_var_38);
                                                            if (eax != 0xffffffff) {
                                                                    esi = esi + 0x1;
                                                                    continue;
                                                            }
                                                            temp_0 = 0x0;
                                                            break;
                                                    }
                                                    *edx = *edx - 0x1;
                                                    ecx = ecx[0x9];
                                                    edx = *ecx;
                                                    *ecx = edx + 0x1;
                                                    ebx = arg_4;
                                                    *(int8_t *)edx = eax;
                                                    eax = eax & 0xff;
                                                    if (eax != 0xffffffff) {
                                                            esi = esi + 0x1;
                                                            continue;
                                                    }
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                            if (temp_0 == 0x0) {
                                                    var_14 = var_14 | 0x4;
                                            }
                                    }
                            }
                            if (var_14 == 0x0) {
                                    if (var_18 > 0x0) {
                                            edx = *(*edi + 0x4);
                                            eax = *(int8_t *)(edx + edi + 0x30);
                                            ecx = *(edx + edi + 0x28);
                                            if (*ecx[0x9] != 0x0) {
                                                    edx = ecx[0xd];
                                                    if (*edx > 0x0) {
                                                            *edx = *edx - 0x1;
                                                            ecx = ecx[0x9];
                                                            edx = *ecx;
                                                            *ecx = edx + 0x1;
                                                            *(int8_t *)edx = eax;
                                                            eax = eax & 0xff;
                                                            if (eax != 0xffffffff) {
                                                                    var_18 = var_18 - 0x1;
                                                                    continue;
                                                            }
                                                            var_14 = var_14 | 0x4;
                                                            break;
                                                    }
                                                    else {
                                                            esp = esp - 0x4;
                                                            decomp_var_38 = eax & 0xff;
                                                            eax = *(*ecx + 0x4);
                                                            eax = (eax)(decomp_var_38);
                                                            if (eax != 0xffffffff) {
                                                                    var_18 = var_18 - 0x1;
                                                                    continue;
                                                            }
                                                            var_14 = var_14 | 0x4;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_38 = eax & 0xff;
                                                    eax = *(*ecx + 0x4);
                                                    eax = (eax)(decomp_var_38);
                                                    if (eax != 0xffffffff) {
                                                            var_18 = var_18 - 0x1;
                                                            continue;
                                                    }
                                                    var_14 = var_14 | 0x4;
                                                    break;
                                            }
                                    }
                                    else {
                                            break;
                                    }
                            }
                            *(*(*edi + 0x4) + edi + 0x18) = 0x0;
                            ecx = *edi;
                            ecx = ecx[0x1];
                            edx = var_14;
                            ecx = ecx + edi;
                            if (edx != 0x0) {
                                    eax = ecx[0x2];
                                    eax = eax | edx;
                                    if (ecx[0xa] == 0x0) {
                                            eax = eax | 0x4;
                                    }
                                    esp = esp - 0x8;
                                    sub_467d70(eax, 0x0);
                            }
                            if (sub_493721() == 0x0) {
                                    sub_469080();
                            }
                            eax = *(*(*var_24 + 0x4) + var_24 + 0x28);
                            if (eax != 0x0) {
                                    sub_493604();
                            }
                            eax = edi;
                            *0x0 = var_C;
                            &var_24 = ebp;
                    }
                    else {
                            *(*(*edi + 0x4) + edi + 0x18) = 0x0;
                            ecx = *edi;
                            ecx = ecx[0x1];
                            edx = var_14;
                            ecx = ecx + edi;
                            if (edx != 0x0) {
                                    eax = ecx[0x2];
                                    eax = eax | edx;
                                    if (ecx[0xa] == 0x0) {
                                            eax = eax | 0x4;
                                    }
                                    esp = esp - 0x8;
                                    sub_467d70(eax, 0x0);
                            }
                            if (sub_493721() == 0x0) {
                                    sub_469080();
                            }
                            eax = *(*(*var_24 + 0x4) + var_24 + 0x28);
                            if (eax != 0x0) {
                                    sub_493604();
                            }
                            eax = edi;
                            *0x0 = var_C;
                            &var_24 = ebp;
                    }
            }
            else {
                    while (true) {
                            if (esi >= var_1C) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            if (esi > ebx[0x5]) {
                                    sub_47a948();
                            }
                            if (ebx[0x6] >= 0x10) {
                                    eax = ebx[0x1];
                            }
                            else {
                                    eax = ebx + 0x4;
                            }
                            ecx = *(*(*edi + 0x4) + edi + 0x28);
                            bool_62 = *ecx[0x9] == 0x0;
                            eax = *(int8_t *)(eax + esi);
                            if (bool_62) {
                                    esp = esp - 0x4;
                                    decomp_var_38 = eax & 0xff;
                                    eax = *(*ecx + 0x4);
                                    eax = (eax)(decomp_var_38);
                                    if (eax != 0xffffffff) {
                                            esi = esi + 0x1;
                                            continue;
                                    }
                                    temp_0 = 0x0;
                                    break;
                            }
                            edx = ecx[0xd];
                            if (*edx <= 0x0) {
                                    esp = esp - 0x4;
                                    decomp_var_38 = eax & 0xff;
                                    eax = *(*ecx + 0x4);
                                    eax = (eax)(decomp_var_38);
                                    if (eax != 0xffffffff) {
                                            esi = esi + 0x1;
                                            continue;
                                    }
                                    temp_0 = 0x0;
                                    break;
                            }
                            *edx = *edx - 0x1;
                            ecx = ecx[0x9];
                            edx = *ecx;
                            *ecx = edx + 0x1;
                            ebx = arg_4;
                            *(int8_t *)edx = eax;
                            eax = eax & 0xff;
                            if (eax != 0xffffffff) {
                                    esi = esi + 0x1;
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    if (temp_0 == 0x0) {
                            var_14 = var_14 | 0x4;
                    }
                    if (var_14 == 0x0) {
                            if (var_18 > 0x0) {
                                    edx = *(*edi + 0x4);
                                    eax = *(int8_t *)(edx + edi + 0x30);
                                    ecx = *(edx + edi + 0x28);
                                    if (*ecx[0x9] != 0x0) {
                                            edx = ecx[0xd];
                                            if (*edx > 0x0) {
                                                    *edx = *edx - 0x1;
                                                    ecx = ecx[0x9];
                                                    edx = *ecx;
                                                    *ecx = edx + 0x1;
                                                    *(int8_t *)edx = eax;
                                                    eax = eax & 0xff;
                                                    if (eax != 0xffffffff) {
                                                            var_18 = var_18 - 0x1;
                                                            continue;
                                                    }
                                                    var_14 = var_14 | 0x4;
                                                    break;
                                            }
                                            else {
                                                    esp = esp - 0x4;
                                                    decomp_var_38 = eax & 0xff;
                                                    eax = *(*ecx + 0x4);
                                                    eax = (eax)(decomp_var_38);
                                                    if (eax != 0xffffffff) {
                                                            var_18 = var_18 - 0x1;
                                                            continue;
                                                    }
                                                    var_14 = var_14 | 0x4;
                                                    break;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x4;
                                            decomp_var_38 = eax & 0xff;
                                            eax = *(*ecx + 0x4);
                                            eax = (eax)(decomp_var_38);
                                            if (eax != 0xffffffff) {
                                                    var_18 = var_18 - 0x1;
                                                    continue;
                                            }
                                            var_14 = var_14 | 0x4;
                                            break;
                                    }
                            }
                            else {
                                    break;
                            }
                    }
                    *(*(*edi + 0x4) + edi + 0x18) = 0x0;
                    ecx = *edi;
                    ecx = ecx[0x1];
                    edx = var_14;
                    ecx = ecx + edi;
                    if (edx != 0x0) {
                            eax = ecx[0x2];
                            eax = eax | edx;
                            if (ecx[0xa] == 0x0) {
                                    eax = eax | 0x4;
                            }
                            esp = esp - 0x8;
                            sub_467d70(eax, 0x0);
                    }
                    if (sub_493721() == 0x0) {
                            sub_469080();
                    }
                    eax = *(*(*var_24 + 0x4) + var_24 + 0x28);
                    if (eax != 0x0) {
                            sub_493604();
                    }
                    eax = edi;
                    *0x0 = var_C;
                    &var_24 = ebp;
            }
    }
    return eax;
}
