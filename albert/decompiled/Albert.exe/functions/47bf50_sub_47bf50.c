// sub_47bf50 @ 0x47bf50
// hopper name: sub_47bf50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47bf50() {
    eax = arg_8;
    esp = esp - 0x4;
    decomp_var_4 = ebx;
    if (eax != 0x0) {
            edx = arg_0;
            ebx = arg_4;
            if ((edx & 0x3) != 0x0) {
                    while (true) {
                            ecx = *(int8_t *)edx;
                            edx = edx + 0x1;
                            if ((ecx ^ ebx) == 0x0) {
                                    temp_1 = 0x1;
                                    break;
                            }
                            eax = eax - 0x1;
                            if (eax == 0x0) {
                                    temp_1 = 0x0;
                                    break;
                            }
                            if ((edx & 0x3) != 0x0) {
                                    continue;
                            }
                            temp_1 = 0x2;
                            break;
                    }
                    if (temp_1 != 0x0) {
                            if (temp_1 != 0x1) {
                                    eax = eax - 0x4;
                                    if (eax >= 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_8 = edi;
                                            ebx = ((ebx << 0x8) + ebx << 0x10) + (ebx << 0x8) + ebx;
                                            while (true) {
                                                    ecx = *edx;
                                                    edx = edx + 0x4;
                                                    if (((ecx ^ ebx ^ 0xffffffff ^ 0x7efefeff + (ecx ^ ebx)) & 0x81010100) == 0x0) {
                                                            eax = eax - 0x4;
                                                            if (eax >= 0x0) {
                                                                    continue;
                                                            }
                                                            esp = esp + 0x4;
                                                            temp_0 = 0x3;
                                                            break;
                                                    }
                                                    ecx = *(edx - 0x4);
                                                    ecx = ecx ^ ebx;
                                                    if (ecx == 0x0) {
                                                            eax = edx - 0x4;
                                                            ebx = decomp_var_4;
                                                            esp = esp + 0x8;
                                                            temp_0 = 0x0;
                                                            break;
                                                    }
                                                    HIBYTE(ecx) = HIBYTE(ecx) ^ ebx;
                                                    if (HIBYTE(ecx) == 0x0) {
                                                            eax = edx - 0x3;
                                                            ebx = decomp_var_4;
                                                            esp = esp + 0x8;
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                                    ecx = ecx >> 0x10 ^ ebx;
                                                    if (ecx == 0x0) {
                                                            eax = edx - 0x2;
                                                            ebx = decomp_var_4;
                                                            esp = esp + 0x8;
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    HIBYTE(ecx) = HIBYTE(ecx) ^ ebx;
                                                    if (HIBYTE(ecx) == 0x0) {
                                                            esp = esp + 0x4;
                                                            temp_0 = 0x4;
                                                            break;
                                                    }
                                                    eax = eax - 0x4;
                                                    if (eax >= 0x0) {
                                                            continue;
                                                    }
                                                    esp = esp + 0x4;
                                                    temp_0 = 0x3;
                                                    break;
                                            }
                                            if (temp_0 != 0x0 && temp_0 != 0x1 && temp_0 != 0x2) {
                                                    if (temp_0 != 0x3) {
                                                            eax = edx - 0x1;
                                                    }
                                                    else {
                                                            eax = eax + 0x4;
                                                            if (eax != 0x0) {
                                                                    while (true) {
                                                                            ecx = *(int8_t *)edx;
                                                                            edx = edx + 0x1;
                                                                            if ((ecx ^ ebx) == 0x0) {
                                                                                    temp_2 = 0x1;
                                                                                    break;
                                                                            }
                                                                            eax = eax - 0x1;
                                                                            if (eax != 0x0) {
                                                                                    continue;
                                                                            }
                                                                            temp_2 = 0x0;
                                                                            break;
                                                                    }
                                                                    if (temp_2 != 0x0) {
                                                                            eax = edx - 0x1;
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            eax = eax + 0x4;
                                            if (eax != 0x0) {
                                                    while (true) {
                                                            ecx = *(int8_t *)edx;
                                                            edx = edx + 0x1;
                                                            if ((ecx ^ ebx) == 0x0) {
                                                                    temp_2 = 0x1;
                                                                    break;
                                                            }
                                                            eax = eax - 0x1;
                                                            if (eax != 0x0) {
                                                                    continue;
                                                            }
                                                            temp_2 = 0x0;
                                                            break;
                                                    }
                                                    if (temp_2 != 0x0) {
                                                            eax = edx - 0x1;
                                                    }
                                            }
                                    }
                            }
                            else {
                                    eax = edx - 0x1;
                            }
                    }
            }
            else {
                    eax = eax - 0x4;
                    if (eax >= 0x0) {
                            esp = esp - 0x4;
                            decomp_var_8 = edi;
                            ebx = ((ebx << 0x8) + ebx << 0x10) + (ebx << 0x8) + ebx;
                            while (true) {
                                    ecx = *edx;
                                    edx = edx + 0x4;
                                    if (((ecx ^ ebx ^ 0xffffffff ^ 0x7efefeff + (ecx ^ ebx)) & 0x81010100) == 0x0) {
                                            eax = eax - 0x4;
                                            if (eax >= 0x0) {
                                                    continue;
                                            }
                                            esp = esp + 0x4;
                                            temp_0 = 0x3;
                                            break;
                                    }
                                    ecx = *(edx - 0x4);
                                    ecx = ecx ^ ebx;
                                    if (ecx == 0x0) {
                                            eax = edx - 0x4;
                                            ebx = decomp_var_4;
                                            esp = esp + 0x8;
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    HIBYTE(ecx) = HIBYTE(ecx) ^ ebx;
                                    if (HIBYTE(ecx) == 0x0) {
                                            eax = edx - 0x3;
                                            ebx = decomp_var_4;
                                            esp = esp + 0x8;
                                            temp_0 = 0x2;
                                            break;
                                    }
                                    ecx = ecx >> 0x10 ^ ebx;
                                    if (ecx == 0x0) {
                                            eax = edx - 0x2;
                                            ebx = decomp_var_4;
                                            esp = esp + 0x8;
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    HIBYTE(ecx) = HIBYTE(ecx) ^ ebx;
                                    if (HIBYTE(ecx) == 0x0) {
                                            esp = esp + 0x4;
                                            temp_0 = 0x4;
                                            break;
                                    }
                                    eax = eax - 0x4;
                                    if (eax >= 0x0) {
                                            continue;
                                    }
                                    esp = esp + 0x4;
                                    temp_0 = 0x3;
                                    break;
                            }
                            if (temp_0 != 0x0 && temp_0 != 0x1 && temp_0 != 0x2) {
                                    if (temp_0 != 0x3) {
                                            eax = edx - 0x1;
                                    }
                                    else {
                                            eax = eax + 0x4;
                                            if (eax != 0x0) {
                                                    while (true) {
                                                            ecx = *(int8_t *)edx;
                                                            edx = edx + 0x1;
                                                            if ((ecx ^ ebx) == 0x0) {
                                                                    temp_2 = 0x1;
                                                                    break;
                                                            }
                                                            eax = eax - 0x1;
                                                            if (eax != 0x0) {
                                                                    continue;
                                                            }
                                                            temp_2 = 0x0;
                                                            break;
                                                    }
                                                    if (temp_2 != 0x0) {
                                                            eax = edx - 0x1;
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            eax = eax + 0x4;
                            if (eax != 0x0) {
                                    while (true) {
                                            ecx = *(int8_t *)edx;
                                            edx = edx + 0x1;
                                            if ((ecx ^ ebx) == 0x0) {
                                                    temp_2 = 0x1;
                                                    break;
                                            }
                                            eax = eax - 0x1;
                                            if (eax != 0x0) {
                                                    continue;
                                            }
                                            temp_2 = 0x0;
                                            break;
                                    }
                                    if (temp_2 != 0x0) {
                                            eax = edx - 0x1;
                                    }
                            }
                    }
            }
    }
    return eax;
}
