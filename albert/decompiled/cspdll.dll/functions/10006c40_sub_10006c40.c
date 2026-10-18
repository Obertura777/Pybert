// sub_10006c40 @ 0x10006c40
// hopper name: sub_10006c40
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10006c40() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    ebp = arg_0;
    decomp_var_c = esi;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    edx = *ebp;
    eax = *(int8_t *)edx;
    if (eax != 0x0) {
            do {
                    if (eax == 0x5c) {
                            *ebp = edx + 0x1;
                    }
                    eax = edx[0x1];
                    edx = edx + 0x1;
            } while (eax != 0x0);
    }
    if (*dword_1000ab30 != 0x0) {
            ecx = *dword_1000ab30;
            if (*(int8_t *)*dword_1000ab30 != 0x0) {
                    ebx = *ebp;
                    edx = 0x0;
                    esi = ebx;
                    do {
                            eax = *(int8_t *)ecx;
                            if (eax == 0x2c) {
                                    edx = 0x1;
                                    ecx = ecx + 0x1;
                                    esi = esi + 0x1;
                                    if (0x1 == 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                            if (eax == 0x0) {
                                    edx = 0x1;
                                    ecx = ecx + 0x1;
                                    esi = esi + 0x1;
                                    if (0x1 == 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                            if (*(int8_t *)esi == eax) {
                                    edx = 0x0;
                                    ecx = ecx + 0x1;
                                    esi = esi + 0x1;
                                    if (0x0 == 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                            esi = ebx - 0x1;
                            while (eax != 0x0) {
                                    eax = ecx[0x1];
                                    ecx = ecx + 0x1;
                                    if (eax == 0x2c) {
                                            break;
                                    }
                            }
                            if (*(int8_t *)ecx == 0x0) {
                                    break;
                            }
                            ecx = ecx + 0x1;
                            esi = esi + 0x1;
                    } while (edx == 0x0);
            }
            else {
                    edx = 0x1;
            }
    }
    else {
            edx = 0x1;
    }
    bool_3 = edx == 0x0;
    edx = edx == 0x0 ? 0x1 : 0x0;
    if (!bool_3) {
            edi = *dword_1000ab34;
            if (*(int8_t *)*dword_1000ab34 != 0x0) {
                    esi = *ebp;
                    ecx = esi;
                    if (edx == 0x0) {
                            while (true) {
                                    eax = *(int8_t *)edi;
                                    if (eax == 0x2c) {
                                            edx = 0x1;
                                            edi = edi + 0x1;
                                            ecx = ecx + 0x1;
                                            if (0x1 == 0x0) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    if (eax == 0x0) {
                                            edx = 0x1;
                                            edi = edi + 0x1;
                                            ecx = ecx + 0x1;
                                            if (0x1 == 0x0) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    if (*(int8_t *)ecx == eax) {
                                            edi = edi + 0x1;
                                            ecx = ecx + 0x1;
                                            if (edx == 0x0) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    ecx = esi - 0x1;
                                    while (eax != 0x0) {
                                            eax = edi[0x1];
                                            edi = edi + 0x1;
                                            if (eax == 0x2c) {
                                                    break;
                                            }
                                    }
                                    if (*(int8_t *)edi == 0x0) {
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    edi = edi + 0x1;
                                    ecx = ecx + 0x1;
                                    if (edx == 0x0) {
                                            continue;
                                    }
                                    temp_0 = 0x1;
                                    break;
                            }
                    }
            }
    }
    eax = edx == 0x0 ? 0x1 : 0x0;
    return eax;
}
