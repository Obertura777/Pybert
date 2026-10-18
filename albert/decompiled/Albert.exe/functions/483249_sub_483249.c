// sub_483249 @ 0x483249
// hopper name: sub_483249
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_483249() {
    decomp_var_14 = esi;
    esp = esp - 0x8;
    sub_47aea2(arg_4);
    eax = arg_0;
    ecx = *(int8_t *)eax;
    esi = var_10;
    if (ecx != 0x0) {
            edx = esi[0x2f];
            edx = *edx;
            edx = *(int8_t *)edx;
            while (true) {
                    if (ecx == edx) {
                            temp_1 = 0x1;
                            break;
                    }
                    eax = eax + 0x1;
                    ecx = *(int8_t *)eax;
                    if (ecx != 0x0) {
                            continue;
                    }
                    temp_1 = 0x0;
                    break;
            }
    }
    ecx = *(int8_t *)eax;
    eax = eax + 0x1;
    if (ecx != 0x0) {
            while (true) {
                    ecx = *(int8_t *)eax;
                    if (ecx == 0x0) {
                            temp_0 = 0x0;
                            break;
                    }
                    else {
                            if (ecx != 0x65) {
                                    if (ecx != 0x45) {
                                            eax = eax + 0x1;
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
            }
            edx = eax;
            do {
                    eax = eax - 0x1;
            } while (*(int8_t *)eax == 0x30);
            esp = (esp - 0x4) + 0x4;
            if (*(int8_t *)eax == *(int8_t *)*esi[0x2f]) {
                    eax = eax - 0x1;
                    ecx = *(int8_t *)edx;
                    eax = eax + 0x1;
                    edx = edx + 0x1;
                    *(int8_t *)eax = ecx;
                    if (ecx != 0x0) {
                            do {
                                    ecx = *(int8_t *)edx;
                                    eax = eax + 0x1;
                                    edx = edx + 0x1;
                                    *(int8_t *)eax = ecx;
                            } while (ecx != 0x0);
                    }
            }
            else {
                    ecx = *(int8_t *)edx;
                    eax = eax + 0x1;
                    edx = edx + 0x1;
                    *(int8_t *)eax = ecx;
                    if (ecx != 0x0) {
                            continue;
                    }
                    break;
            }
    }
    if (var_4 != 0x0) {
            eax = var_8;
            eax[0x1c] = eax[0x1c] & 0xfffffffd;
    }
    return eax;
}
