// sub_4688b0 @ 0x4688b0
// hopper name: sub_4688b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4688b0() {
    esp = esp - 0x4;
    decomp_var_8 = esi;
    esi = arg_10;
    if (arg_18 > 0x0) {
            decomp_var_c = ebx;
            esp = esp - 0x8;
            decomp_var_10 = edi;
            edi = arg_14;
            do {
                    if (esi == 0x0) {
                            arg_c = 0x1;
                            edi = edi + 0x1;
                            if (&decomp_var_1 > 0x0) {
                                    continue;
                            }
                            break;
                    }
                    bool_6 = *esi[0x9] == 0x0;
                    edx = *(int8_t *)edi;
                    if (bool_6) {
                            esp = esp - 0x4;
                            eax = (*(*esi + 0x4))(edx & 0xff);
                            if (eax == 0xffffffff) {
                                    arg_c = 0x1;
                            }
                            edi = edi + 0x1;
                            if (&decomp_var_1 > 0x0) {
                                    continue;
                            }
                            break;
                    }
                    ecx = esi[0xd];
                    if (*ecx <= 0x0) {
                            esp = esp - 0x4;
                            eax = (*(*esi + 0x4))(edx & 0xff);
                            if (eax == 0xffffffff) {
                                    arg_c = 0x1;
                            }
                            edi = edi + 0x1;
                            if (&decomp_var_1 > 0x0) {
                                    continue;
                            }
                            break;
                    }
                    *ecx = *ecx - 0x1;
                    eax = esi[0x9];
                    ecx = *eax;
                    *eax = ecx + 0x1;
                    *(int8_t *)ecx = edx;
                    eax = edx & 0xff;
                    if (eax == 0xffffffff) {
                            arg_c = 0x1;
                    }
                    edi = edi + 0x1;
            } while (&decomp_var_1 > 0x0);
            esp = esp + 0x8;
    }
    eax = arg_4;
    *eax = arg_8;
    eax[0x1] = arg_c;
    eax[0x2] = esi;
    return eax;
}
