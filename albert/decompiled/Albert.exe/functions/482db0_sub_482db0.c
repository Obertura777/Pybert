// sub_482db0 @ 0x482db0
// hopper name: sub_482db0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_482db0() {
    ecx = arg_4;
    decomp_var_4 = edi;
    decomp_var_8 = ebx;
    esp = esp - 0xc;
    decomp_var_c = esi;
    edi = arg_0;
    if (*(int8_t *)ecx != 0x0) {
            HIBYTE(edx) = ecx[0x1];
            if (HIBYTE(edx) != 0x0) {
                    temp_1 = 0x4;
                    while (true) {
                            if (temp_1 != 0x4) {
                                    if (temp_1 != 0x7) {
                                            eax = *(int8_t *)esi;
                                            esi = esi + 0x1;
                                            if (eax == HIBYTE(edx)) {
                                                    edi = esi - 0x1;
                                                    while (true) {
                                                            HIBYTE(eax) = ecx[0x2];
                                                            if (HIBYTE(eax) == 0x0) {
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                            eax = *(int8_t *)esi;
                                                            esi = esi + 0x2;
                                                            if (eax != HIBYTE(eax)) {
                                                                    temp_0 = 0x0;
                                                                    break;
                                                            }
                                                            eax = ecx[0x3];
                                                            if (eax == 0x0) {
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                            HIBYTE(eax) = *(int8_t *)(esi - 0x1);
                                                            ecx = ecx + 0x2;
                                                            if (eax == HIBYTE(eax)) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    if (temp_0 == 0x0) {
                                                            temp_1 = 0x4;
                                                            continue;
                                                    }
                                                    if (temp_0 == 0x1) {
                                                            temp_1 = 0x4;
                                                            continue;
                                                    }
                                                    eax = edi - 0x1;
                                                    esp = esp + 0xc;
                                                    temp_2 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    if (eax == edx) {
                                                            temp_1 = 0x9;
                                                            continue;
                                                    }
                                                    if (eax != 0x0) {
                                                            eax = *(int8_t *)esi;
                                                            esi = esi + 0x1;
                                                            temp_1 = 0x7;
                                                            continue;
                                                    }
                                                    temp_2 = 0x1;
                                                    break;
                                            }
                                    }
                                    else {
                                            if (eax == edx) {
                                                    temp_1 = 0x9;
                                                    continue;
                                            }
                                            if (eax != 0x0) {
                                                    eax = *(int8_t *)esi;
                                                    esi = esi + 0x1;
                                                    temp_1 = 0x7;
                                                    continue;
                                            }
                                            temp_2 = 0x1;
                                            break;
                                    }
                            }
                            else {
                                    ecx = arg_4;
                                    eax = *(int8_t *)edi;
                                    esi = edi + 0x1;
                                    if (eax != edx) {
                                            if (eax != 0x0) {
                                                    eax = *(int8_t *)esi;
                                                    esi = esi + 0x1;
                                                    temp_1 = 0x7;
                                                    continue;
                                            }
                                            temp_2 = 0x1;
                                            break;
                                    }
                                    else {
                                            eax = *(int8_t *)esi;
                                            esi = esi + 0x1;
                                            if (eax == HIBYTE(edx)) {
                                                    edi = esi - 0x1;
                                                    while (true) {
                                                            HIBYTE(eax) = ecx[0x2];
                                                            if (HIBYTE(eax) == 0x0) {
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                            eax = *(int8_t *)esi;
                                                            esi = esi + 0x2;
                                                            if (eax != HIBYTE(eax)) {
                                                                    temp_0 = 0x0;
                                                                    break;
                                                            }
                                                            eax = ecx[0x3];
                                                            if (eax == 0x0) {
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                            HIBYTE(eax) = *(int8_t *)(esi - 0x1);
                                                            ecx = ecx + 0x2;
                                                            if (eax == HIBYTE(eax)) {
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    if (temp_0 == 0x0) {
                                                            temp_1 = 0x4;
                                                            continue;
                                                    }
                                                    if (temp_0 == 0x1) {
                                                            temp_1 = 0x4;
                                                            continue;
                                                    }
                                                    eax = edi - 0x1;
                                                    esp = esp + 0xc;
                                                    temp_2 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    if (eax == edx) {
                                                            temp_1 = 0x9;
                                                            continue;
                                                    }
                                                    if (eax != 0x0) {
                                                            eax = *(int8_t *)esi;
                                                            esi = esi + 0x1;
                                                            temp_1 = 0x7;
                                                            continue;
                                                    }
                                                    temp_2 = 0x1;
                                                    break;
                                            }
                                    }
                            }
                    }
                    if (temp_2 != 0x0) {
                            eax = 0x0;
                    }
            }
            else {
                    eax = loc_482e56(saved_fp, arg_0);
            }
    }
    else {
            eax = edi;
    }
    return eax;
}
