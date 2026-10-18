// sub_46a2b0 @ 0x46a2b0
// hopper name: sub_46a2b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46a2b0() {
    var_C = *0x0;
    decomp_var_24 = ebx;
    decomp_var_28 = esi;
    decomp_var_2c = edi;
    esp = esp - 0x30;
    decomp_var_30 = *dword_4c8db8 ^ ebp;
    *0x0 = &var_C;
    eax = arg_4;
    var_14 = 0x0;
    edx = eax + 0x1;
    do {
            ecx = *(int8_t *)eax;
            eax = eax + 0x1;
    } while (ecx != 0x0);
    esi = arg_0;
    edi = eax - edx;
    eax = *(*(*esi + 0x4) + esi + 0x18);
    if (eax > 0x0 && eax > edi) {
            ebx = eax - edi;
            var_18 = eax - edi;
    }
    else {
            ebx = 0x0;
            var_18 = 0x0;
    }
    esp = esp - 0x4;
    sub_468ff0(esi);
    if (var_1C == 0x0) {
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
            sub_469340();
            eax = esi;
            *0x0 = var_C;
            &var_20 = ebp;
    }
    else {
            if ((*(*(*esi + 0x4) + esi + 0x10) & 0x1c0) != 0x40) {
                    while (ebx > 0x0) {
                            edx = *(*esi + 0x4);
                            eax = *(int8_t *)(edx + esi + 0x30);
                            ecx = *(edx + esi + 0x28);
                            if (*ecx[0x9] == 0x0) {
                                    esp = esp - 0x4;
                                    decomp_var_34 = eax & 0xff;
                                    eax = *(*ecx + 0x4);
                                    eax = (eax)(decomp_var_34);
                                    if (eax != 0xffffffff) {
                                            ebx = ebx - 0x1;
                                            var_18 = ebx;
                                            continue;
                                    }
                                    var_14 = var_14 | 0x4;
                                    break;
                            }
                            edx = ecx[0xd];
                            if (*edx <= 0x0) {
                                    esp = esp - 0x4;
                                    decomp_var_34 = eax & 0xff;
                                    eax = *(*ecx + 0x4);
                                    eax = (eax)(decomp_var_34);
                                    if (eax != 0xffffffff) {
                                            ebx = ebx - 0x1;
                                            var_18 = ebx;
                                            continue;
                                    }
                                    var_14 = var_14 | 0x4;
                                    break;
                            }
                            *edx = *edx - 0x1;
                            ecx = ecx[0x9];
                            edx = *ecx;
                            *ecx = edx + 0x1;
                            ebx = var_18;
                            *(int8_t *)edx = eax;
                            eax = eax & 0xff;
                            if (eax != 0xffffffff) {
                                    ebx = ebx - 0x1;
                                    var_18 = ebx;
                                    continue;
                            }
                            var_14 = var_14 | 0x4;
                            break;
                    }
                    if (var_14 == 0x0) {
                            esp = esp - 0x8;
                            if ((*(**(*(*esi + 0x4) + esi + 0x28) + 0x20))(arg_4, edi) != edi) {
                                    var_14 = 0x4;
                            }
                            else {
                                    while (true) {
                                            if (ebx <= 0x0) {
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                            ecx = *(*esi + 0x4);
                                            eax = *(int8_t *)(ecx + esi + 0x30);
                                            ecx = *(ecx + esi + 0x28);
                                            if (*ecx[0x9] == 0x0) {
                                                    esp = esp - 0x4;
                                                    decomp_var_34 = eax & 0xff;
                                                    eax = *(*ecx + 0x4);
                                                    eax = (eax)(decomp_var_34);
                                                    if (eax != 0xffffffff) {
                                                            ebx = ebx - 0x1;
                                                            continue;
                                                    }
                                                    var_14 = var_14 | 0x4;
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            edx = ecx[0xd];
                                            if (*edx <= 0x0) {
                                                    esp = esp - 0x4;
                                                    decomp_var_34 = eax & 0xff;
                                                    eax = *(*ecx + 0x4);
                                                    eax = (eax)(decomp_var_34);
                                                    if (eax != 0xffffffff) {
                                                            ebx = ebx - 0x1;
                                                            continue;
                                                    }
                                                    var_14 = var_14 | 0x4;
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            *edx = *edx - 0x1;
                                            ecx = ecx[0x9];
                                            edx = *ecx;
                                            *ecx = edx + 0x1;
                                            *(int8_t *)edx = eax;
                                            eax = eax & 0xff;
                                            if (eax != 0xffffffff) {
                                                    ebx = ebx - 0x1;
                                                    continue;
                                            }
                                            var_14 = var_14 | 0x4;
                                            temp_0 = 0x1;
                                            break;
                                    }
                            }
                            *(*(*esi + 0x4) + esi + 0x18) = 0x0;
                            edx = var_14;
                            ecx = *esi;
                            ecx = ecx[0x1];
                            ecx = ecx + esi;
                            if (edx != 0x0) {
                                    eax = ecx[0x2];
                                    eax = eax | edx;
                                    if (ecx[0xa] == 0x0) {
                                            eax = eax | 0x4;
                                    }
                                    esp = esp - 0x8;
                                    sub_467d70(eax, 0x0);
                            }
                            sub_469340();
                            eax = esi;
                            *0x0 = var_C;
                            &var_20 = ebp;
                    }
                    else {
                            *(*(*esi + 0x4) + esi + 0x18) = 0x0;
                            edx = var_14;
                            ecx = *esi;
                            ecx = ecx[0x1];
                            ecx = ecx + esi;
                            if (edx != 0x0) {
                                    eax = ecx[0x2];
                                    eax = eax | edx;
                                    if (ecx[0xa] == 0x0) {
                                            eax = eax | 0x4;
                                    }
                                    esp = esp - 0x8;
                                    sub_467d70(eax, 0x0);
                            }
                            sub_469340();
                            eax = esi;
                            *0x0 = var_C;
                            &var_20 = ebp;
                    }
            }
            else {
                    esp = esp - 0x8;
                    if ((*(**(*(*esi + 0x4) + esi + 0x28) + 0x20))(arg_4, edi) != edi) {
                            var_14 = 0x4;
                    }
                    else {
                            while (true) {
                                    if (ebx <= 0x0) {
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    ecx = *(*esi + 0x4);
                                    eax = *(int8_t *)(ecx + esi + 0x30);
                                    ecx = *(ecx + esi + 0x28);
                                    if (*ecx[0x9] == 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_34 = eax & 0xff;
                                            eax = *(*ecx + 0x4);
                                            eax = (eax)(decomp_var_34);
                                            if (eax != 0xffffffff) {
                                                    ebx = ebx - 0x1;
                                                    continue;
                                            }
                                            var_14 = var_14 | 0x4;
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    edx = ecx[0xd];
                                    if (*edx <= 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_34 = eax & 0xff;
                                            eax = *(*ecx + 0x4);
                                            eax = (eax)(decomp_var_34);
                                            if (eax != 0xffffffff) {
                                                    ebx = ebx - 0x1;
                                                    continue;
                                            }
                                            var_14 = var_14 | 0x4;
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    *edx = *edx - 0x1;
                                    ecx = ecx[0x9];
                                    edx = *ecx;
                                    *ecx = edx + 0x1;
                                    *(int8_t *)edx = eax;
                                    eax = eax & 0xff;
                                    if (eax != 0xffffffff) {
                                            ebx = ebx - 0x1;
                                            continue;
                                    }
                                    var_14 = var_14 | 0x4;
                                    temp_0 = 0x1;
                                    break;
                            }
                    }
                    *(*(*esi + 0x4) + esi + 0x18) = 0x0;
                    edx = var_14;
                    ecx = *esi;
                    ecx = ecx[0x1];
                    ecx = ecx + esi;
                    if (edx != 0x0) {
                            eax = ecx[0x2];
                            eax = eax | edx;
                            if (ecx[0xa] == 0x0) {
                                    eax = eax | 0x4;
                            }
                            esp = esp - 0x8;
                            sub_467d70(eax, 0x0);
                    }
                    sub_469340();
                    eax = esi;
                    *0x0 = var_C;
                    &var_20 = ebp;
            }
    }
    return eax;
}
