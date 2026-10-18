// sub_482e50 @ 0x482e50
// hopper name: sub_482e50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_482e50() {
    esp = esp - 0x4;
    decomp_var_4 = ebx;
    ebx = arg_4;
    eax = arg_4 << 0x8;
    edx = arg_0;
    if ((edx & 0x3) != 0x0) {
            while (true) {
                    ecx = *(int8_t *)edx;
                    edx = edx + 0x1;
                    if (ecx == ebx) {
                            eax = edx - 0x1;
                            ebx = decomp_var_4;
                            esp = esp + 0x4;
                            temp_1 = 0x0;
                            break;
                    }
                    if (ecx == 0x0) {
                            temp_1 = 0x2;
                            break;
                    }
                    if ((edx & 0x3) != 0x0) {
                            continue;
                    }
                    temp_1 = 0x1;
                    break;
            }
            if (temp_1 != 0x0) {
                    if (temp_1 != 0x1) {
                            eax = 0x0;
                    }
                    else {
                            decomp_var_8 = edi;
                            esp = esp - 0x8;
                            decomp_var_c = esi;
                            ebx = (ebx | eax) << 0x10 | ebx | eax;
                            while (true) {
                                    ecx = *edx;
                                    esi = 0x7efefeff + ecx;
                                    eax = ecx ^ 0xffffffff ^ esi;
                                    edx = edx + 0x4;
                                    if (((ecx ^ ebx ^ 0xffffffff ^ 0x7efefeff + (ecx ^ ebx)) & 0x81010100) == 0x0) {
                                            eax = eax & 0x81010100;
                                            if (eax == 0x0) {
                                                    continue;
                                            }
                                            eax = eax & 0x1010100;
                                            if (eax == 0x0) {
                                                    if ((esi & 0x80000000) != 0x0) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            else {
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                    }
                                    else {
                                            eax = *(edx - 0x4);
                                            if (eax != ebx) {
                                                    if (eax != 0x0) {
                                                            if (HIBYTE(eax) != ebx) {
                                                                    if (HIBYTE(eax) != 0x0) {
                                                                            eax = eax >> 0x10;
                                                                            if (eax != ebx) {
                                                                                    if (eax != 0x0) {
                                                                                            if (HIBYTE(eax) != ebx) {
                                                                                                    if (HIBYTE(eax) != 0x0) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_0 = 0x7;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    eax = edx - 0x1;
                                                                                                    esp = esp + 0xc;
                                                                                                    temp_0 = 0x5;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x4;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = edx - 0x2;
                                                                                    esp = esp + 0xc;
                                                                                    temp_0 = 0x5;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x3;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = edx - 0x3;
                                                                    esp = esp + 0xc;
                                                                    temp_0 = 0x6;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            temp_0 = 0x2;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    eax = edx - 0x4;
                                                    esp = esp + 0xc;
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                    }
                            }
                            if (temp_0 != 0x0) {
                                    switch (temp_0) {
                                        case 1:
                                            esp = esp + 0x8;
                                            eax = 0x0;
                                            break;
                                        case 2:
                                            esp = esp + 0x8;
                                            eax = 0x0;
                                            break;
                                        case 3:
                                            esp = esp + 0x8;
                                            eax = 0x0;
                                            break;
                                        case 4:
                                            esp = esp + 0x8;
                                            eax = 0x0;
                                            break;
                                        default:
                                            if (temp_0 != 0x5 && temp_0 != 0x6) {
                                                    esp = esp + 0x8;
                                                    eax = 0x0;
                                            }
                                            break;
                                    }
                            }
                    }
            }
    }
    else {
            decomp_var_8 = edi;
            esp = esp - 0x8;
            decomp_var_c = esi;
            ebx = (ebx | eax) << 0x10 | ebx | eax;
            while (true) {
                    ecx = *edx;
                    esi = 0x7efefeff + ecx;
                    eax = ecx ^ 0xffffffff ^ esi;
                    edx = edx + 0x4;
                    if (((ecx ^ ebx ^ 0xffffffff ^ 0x7efefeff + (ecx ^ ebx)) & 0x81010100) == 0x0) {
                            eax = eax & 0x81010100;
                            if (eax == 0x0) {
                                    continue;
                            }
                            eax = eax & 0x1010100;
                            if (eax == 0x0) {
                                    if ((esi & 0x80000000) != 0x0) {
                                            continue;
                                    }
                                    temp_0 = 0x1;
                                    break;
                            }
                            else {
                                    temp_0 = 0x1;
                                    break;
                            }
                    }
                    else {
                            eax = *(edx - 0x4);
                            if (eax != ebx) {
                                    if (eax != 0x0) {
                                            if (HIBYTE(eax) != ebx) {
                                                    if (HIBYTE(eax) != 0x0) {
                                                            eax = eax >> 0x10;
                                                            if (eax != ebx) {
                                                                    if (eax != 0x0) {
                                                                            if (HIBYTE(eax) != ebx) {
                                                                                    if (HIBYTE(eax) != 0x0) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_0 = 0x7;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    eax = edx - 0x1;
                                                                                    esp = esp + 0xc;
                                                                                    temp_0 = 0x5;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x4;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = edx - 0x2;
                                                                    esp = esp + 0xc;
                                                                    temp_0 = 0x5;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            temp_0 = 0x3;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    eax = edx - 0x3;
                                                    esp = esp + 0xc;
                                                    temp_0 = 0x6;
                                                    break;
                                            }
                                    }
                                    else {
                                            temp_0 = 0x2;
                                            break;
                                    }
                            }
                            else {
                                    eax = edx - 0x4;
                                    esp = esp + 0xc;
                                    temp_0 = 0x0;
                                    break;
                            }
                    }
            }
            if (temp_0 != 0x0) {
                    switch (temp_0) {
                        case 1:
                            esp = esp + 0x8;
                            eax = 0x0;
                            break;
                        case 2:
                            esp = esp + 0x8;
                            eax = 0x0;
                            break;
                        case 3:
                            esp = esp + 0x8;
                            eax = 0x0;
                            break;
                        case 4:
                            esp = esp + 0x8;
                            eax = 0x0;
                            break;
                        default:
                            if (temp_0 != 0x5 && temp_0 != 0x6) {
                                    esp = esp + 0x8;
                                    eax = 0x0;
                            }
                            break;
                    }
            }
    }
    return eax;
}
