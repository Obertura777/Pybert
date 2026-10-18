// sub_47ba40 @ 0x47ba40
// hopper name: sub_47ba40
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47ba40() {
    edx = arg_8;
    ecx = arg_0;
    if (edx != 0x0) {
            eax = arg_4;
            if (eax == 0x0) {
                    if (edx >= 0x100) {
                            if (*dword_bc8368 != 0x0) {
                                    eax = sub_4865be(saved_fp, arg_0, arg_4);
                            }
                            else {
                                    esp = esp - 0x4;
                                    decomp_var_4 = edi;
                                    edi = ecx;
                                    if (edx >= 0x4) {
                                            ecx = -ecx & 0x3;
                                            if (ecx != 0x0) {
                                                    edx = edx - ecx;
                                                    do {
                                                            *(int8_t *)edi = eax;
                                                            edi = edi + 0x1;
                                                            ecx = ecx - 0x1;
                                                    } while (ecx != 0x0);
                                            }
                                            eax = ((eax << 0x8) + eax << 0x10) + (eax << 0x8) + eax;
                                            ecx = edx;
                                            edx = edx & 0x3;
                                            bool_21 = true;
                                            if (ecx >> 0x2 != 0x0) {
                                                    asm { rep stosd  dword [edi], eax };
                                                    if (edx != 0x0) {
                                                            *(int8_t *)edi = eax;
                                                            edi = edi + 0x1;
                                                            edx = edx - 0x1;
                                                            if (edx == 0x0) {
                                                                    eax = arg_0;
                                                            }
                                                            else {
                                                                    do {
                                                                            *(int8_t *)edi = eax;
                                                                            edi = edi + 0x1;
                                                                            edx = edx - 0x1;
                                                                    } while (edx != 0x0);
                                                                    eax = arg_0;
                                                            }
                                                    }
                                                    else {
                                                            eax = arg_0;
                                                    }
                                            }
                                            else {
                                                    *(int8_t *)edi = eax;
                                                    edi = edi + 0x1;
                                                    edx = edx - 0x1;
                                                    if (edx == 0x0) {
                                                            eax = arg_0;
                                                    }
                                                    else {
                                                            do {
                                                                    *(int8_t *)edi = eax;
                                                                    edi = edi + 0x1;
                                                                    edx = edx - 0x1;
                                                            } while (edx != 0x0);
                                                            eax = arg_0;
                                                    }
                                            }
                                    }
                                    else {
                                            do {
                                                    *(int8_t *)edi = eax;
                                                    edi = edi + 0x1;
                                                    edx = edx - 0x1;
                                            } while (edx != 0x0);
                                            eax = arg_0;
                                    }
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            decomp_var_4 = edi;
                            edi = ecx;
                            if (edx >= 0x4) {
                                    ecx = -ecx & 0x3;
                                    if (ecx != 0x0) {
                                            edx = edx - ecx;
                                            do {
                                                    *(int8_t *)edi = eax;
                                                    edi = edi + 0x1;
                                                    ecx = ecx - 0x1;
                                            } while (ecx != 0x0);
                                    }
                                    eax = ((eax << 0x8) + eax << 0x10) + (eax << 0x8) + eax;
                                    ecx = edx;
                                    edx = edx & 0x3;
                                    bool_11 = true;
                                    if (ecx >> 0x2 != 0x0) {
                                            asm { rep stosd  dword [edi], eax };
                                            if (edx != 0x0) {
                                                    *(int8_t *)edi = eax;
                                                    edi = edi + 0x1;
                                                    edx = edx - 0x1;
                                                    if (edx == 0x0) {
                                                            eax = arg_0;
                                                    }
                                                    else {
                                                            do {
                                                                    *(int8_t *)edi = eax;
                                                                    edi = edi + 0x1;
                                                                    edx = edx - 0x1;
                                                            } while (edx != 0x0);
                                                            eax = arg_0;
                                                    }
                                            }
                                            else {
                                                    eax = arg_0;
                                            }
                                    }
                                    else {
                                            *(int8_t *)edi = eax;
                                            edi = edi + 0x1;
                                            edx = edx - 0x1;
                                            if (edx == 0x0) {
                                                    eax = arg_0;
                                            }
                                            else {
                                                    do {
                                                            *(int8_t *)edi = eax;
                                                            edi = edi + 0x1;
                                                            edx = edx - 0x1;
                                                    } while (edx != 0x0);
                                                    eax = arg_0;
                                            }
                                    }
                            }
                            else {
                                    do {
                                            *(int8_t *)edi = eax;
                                            edi = edi + 0x1;
                                            edx = edx - 0x1;
                                    } while (edx != 0x0);
                                    eax = arg_0;
                            }
                    }
            }
            else {
                    esp = esp - 0x4;
                    decomp_var_4 = edi;
                    edi = ecx;
                    if (edx >= 0x4) {
                            ecx = -ecx & 0x3;
                            if (ecx != 0x0) {
                                    edx = edx - ecx;
                                    do {
                                            *(int8_t *)edi = eax;
                                            edi = edi + 0x1;
                                            ecx = ecx - 0x1;
                                    } while (ecx != 0x0);
                            }
                            eax = ((eax << 0x8) + eax << 0x10) + (eax << 0x8) + eax;
                            ecx = edx;
                            edx = edx & 0x3;
                            bool_6 = true;
                            if (ecx >> 0x2 != 0x0) {
                                    asm { rep stosd  dword [edi], eax };
                                    if (edx != 0x0) {
                                            *(int8_t *)edi = eax;
                                            edi = edi + 0x1;
                                            edx = edx - 0x1;
                                            if (edx == 0x0) {
                                                    eax = arg_0;
                                            }
                                            else {
                                                    do {
                                                            *(int8_t *)edi = eax;
                                                            edi = edi + 0x1;
                                                            edx = edx - 0x1;
                                                    } while (edx != 0x0);
                                                    eax = arg_0;
                                            }
                                    }
                                    else {
                                            eax = arg_0;
                                    }
                            }
                            else {
                                    *(int8_t *)edi = eax;
                                    edi = edi + 0x1;
                                    edx = edx - 0x1;
                                    if (edx == 0x0) {
                                            eax = arg_0;
                                    }
                                    else {
                                            do {
                                                    *(int8_t *)edi = eax;
                                                    edi = edi + 0x1;
                                                    edx = edx - 0x1;
                                            } while (edx != 0x0);
                                            eax = arg_0;
                                    }
                            }
                    }
                    else {
                            do {
                                    *(int8_t *)edi = eax;
                                    edi = edi + 0x1;
                                    edx = edx - 0x1;
                            } while (edx != 0x0);
                            eax = arg_0;
                    }
            }
    }
    else {
            eax = arg_0;
    }
    return eax;
}
