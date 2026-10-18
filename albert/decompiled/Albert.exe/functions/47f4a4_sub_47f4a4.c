// sub_47f4a4 @ 0x47f4a4
// hopper name: sub_47f4a4
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47f4a4() {
    esi = arg_0;
    esp = esp - 0x4;
    decomp_var_c = edi;
    if (arg_c == 0x0) {
            if (esi == 0x0) {
                    if (arg_4 == 0x0) {
                            eax = 0x0;
                    }
                    else {
                            esp = (esp - 0x4) + 0x4;
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = 0x16;
                    }
            }
            else {
                    edi = arg_4;
                    if (edi <= 0x0) {
                            esp = (esp - 0x4) + 0x4;
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = 0x16;
                    }
                    else {
                            if (arg_c == 0x0) {
                                    *(int8_t *)esi = 0x0;
                                    eax = 0x0;
                            }
                            else {
                                    ebx = 0x0;
                                    edx = arg_8;
                                    if (edx == 0x0) {
                                            *(int8_t *)esi = ebx;
                                            esp = (esp - 0x4) + 0x4;
                                            *sub_47d812() = 0x16;
                                            sub_47a924();
                                            esp = (esp - 0x14) + 0x14;
                                            eax = 0x16;
                                    }
                                    else {
                                            eax = esi;
                                            if (arg_c == 0xffffffff) {
                                                    ecx = *(int8_t *)edx;
                                                    *(int8_t *)eax = ecx;
                                                    eax = eax + 0x1;
                                                    edx = edx + 0x1;
                                                    if (ecx != ebx) {
                                                            edi = edi - 0x1;
                                                            if (edi != 0x0) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            break;
                                                    }
                                            }
                                            else {
                                                    while (true) {
                                                            ecx = *(int8_t *)edx;
                                                            *(int8_t *)eax = ecx;
                                                            eax = eax + 0x1;
                                                            edx = edx + 0x1;
                                                            if (ecx == ebx) {
                                                                    temp_0 = 0x0;
                                                                    break;
                                                            }
                                                            edi = edi - 0x1;
                                                            if (edi == 0x0) {
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
                                                    if (arg_c == 0x0) {
                                                            *(int8_t *)eax = 0x0;
                                                    }
                                            }
                                            if (edi == 0x0) {
                                                    if (arg_c == 0xffffffff) {
                                                            *(int8_t *)(esi + (arg_4 - 0x1)) = 0x0;
                                                            eax = 0x50;
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    else {
                                                            ebx = 0x0;
                                                            *(int8_t *)esi = 0x0;
                                                            esp = (esp - 0x4) + 0x4;
                                                            *sub_47d812() = 0x22;
                                                            sub_47a924();
                                                            esp = (esp - 0x14) + 0x14;
                                                            eax = 0x22;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                            }
                    }
            }
    }
    else {
            if (esi != 0x0) {
                    edi = arg_4;
                    if (edi <= 0x0) {
                            esp = (esp - 0x4) + 0x4;
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = 0x16;
                    }
                    else {
                            if (arg_c == 0x0) {
                                    *(int8_t *)esi = 0x0;
                                    eax = 0x0;
                            }
                            else {
                                    ebx = 0x0;
                                    edx = arg_8;
                                    if (edx == 0x0) {
                                            ebx = 0x0;
                                            *(int8_t *)esi = 0x0;
                                            esp = (esp - 0x4) + 0x4;
                                            *sub_47d812() = 0x16;
                                            sub_47a924();
                                            esp = (esp - 0x14) + 0x14;
                                            eax = 0x16;
                                    }
                                    else {
                                            eax = esi;
                                            if (arg_c == 0xffffffff) {
                                                    do {
                                                            ecx = *(int8_t *)edx;
                                                            *(int8_t *)eax = ecx;
                                                            eax = eax + 0x1;
                                                            edx = edx + 0x1;
                                                            if (ecx == ebx) {
                                                                    break;
                                                            }
                                                            edi = edi - 0x1;
                                                    } while (edi != 0x0);
                                            }
                                            else {
                                                    while (true) {
                                                            ecx = *(int8_t *)edx;
                                                            *(int8_t *)eax = ecx;
                                                            eax = eax + 0x1;
                                                            edx = edx + 0x1;
                                                            if (ecx == ebx) {
                                                                    temp_0 = 0x0;
                                                                    break;
                                                            }
                                                            edi = edi - 0x1;
                                                            if (edi == 0x0) {
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
                                                    if (arg_c == ebx) {
                                                            *(int8_t *)eax = ebx;
                                                    }
                                            }
                                            if (edi == ebx) {
                                                    if (arg_c == 0xffffffff) {
                                                            *(int8_t *)(esi + (arg_4 - 0x1)) = 0x0;
                                                            eax = 0x50;
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    else {
                                                            *(int8_t *)esi = ebx;
                                                            esp = (esp - 0x4) + 0x4;
                                                            *sub_47d812() = 0x22;
                                                            sub_47a924();
                                                            esp = (esp - 0x14) + 0x14;
                                                            eax = 0x22;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                            }
                    }
            }
            else {
                    esp = (esp - 0x4) + 0x4;
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = (esp - 0x14) + 0x14;
                    eax = 0x16;
            }
    }
    return eax;
}
