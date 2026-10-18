// sub_47f8ba @ 0x47f8ba
// hopper name: sub_47f8ba
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47f8ba() {
    decomp_var_14 = ebx;
    decomp_var_18 = esi;
    esp = esp - 0xc;
    sub_47aea2(arg_8);
    esi = var_C;
    if (esi[0x2] == 0x0) {
            sub_47d320(arg_0, arg_4);
            esp = (esp - 0x8) + 0x8;
            if (var_4 != 0x0) {
                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
            }
    }
    else {
            eax = arg_0;
            if (eax == 0x0) {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = (esp - 0x14) + 0x14;
                    if (var_4 != 0x0) {
                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                    }
            }
            else {
                    ebx = 0x0;
                    if (arg_4 != 0x0) {
                            if (*(int8_t *)eax != ebx) {
                                    esp = esp - 0x4;
                                    decomp_var_1c = edi;
                                    while (true) {
                                            ecx = arg_4;
                                            while (true) {
                                                    if (*(int8_t *)ecx == ebx) {
                                                            temp_0 = 0x0;
                                                            break;
                                                    }
                                                    else {
                                                            edx = *(int8_t *)ecx;
                                                            if ((*(int8_t *)((edx & 0xff) + esi + 0x1d) & 0x4) != 0x0) {
                                                                    if (edx == *(int8_t *)eax) {
                                                                            if (ecx[0x1] != eax[0x1]) {
                                                                                    edx = ecx + 0x1;
                                                                                    if (*(int8_t *)edx != ebx) {
                                                                                            ecx = edx;
                                                                                            ecx = ecx + 0x1;
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
                                                                            edx = ecx + 0x1;
                                                                            if (*(int8_t *)edx != ebx) {
                                                                                    ecx = edx;
                                                                                    ecx = ecx + 0x1;
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (edx != *(int8_t *)eax) {
                                                                            ecx = ecx + 0x1;
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            if (*(int8_t *)ecx != ebx) {
                                                    temp_1 = 0x0;
                                                    break;
                                            }
                                            if ((*(int8_t *)((*(int8_t *)eax & 0xff) + esi + 0x1d) & 0x4) == 0x0) {
                                                    eax = eax + 0x1;
                                                    if (*(int8_t *)eax != ebx) {
                                                            continue;
                                                    }
                                                    temp_1 = 0x1;
                                                    break;
                                            }
                                            eax = eax + 0x1;
                                            if (*(int8_t *)eax == ebx) {
                                                    temp_1 = 0x0;
                                                    break;
                                            }
                                            eax = eax + 0x1;
                                            if (*(int8_t *)eax != ebx) {
                                                    continue;
                                            }
                                            temp_1 = 0x1;
                                            break;
                                    }
                                    esp = esp + 0x4;
                            }
                            if (var_4 != ebx) {
                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                            }
                    }
                    else {
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            if (var_4 != 0x0) {
                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                            }
                    }
            }
    }
    return;
}
