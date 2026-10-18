// sub_468930 @ 0x468930
// hopper name: sub_468930
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_468930() {
    decomp_var_4 = esi;
    esi = arg_10;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_18;
    if (edi > 0x0) {
            esp = esp - 0x4;
            decomp_var_c = ebx;
            ebx = arg_14;
            do {
                    if (esi == 0x0) {
                            arg_c = 0x1;
                            edi = edi - 0x1;
                            if (edi != 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (*esi[0x9] == 0x0) {
                            esp = esp - 0x4;
                            eax = (*(*esi + 0x4))(ebx & 0xff);
                            if (eax == 0xffffffff) {
                                    arg_c = 0x1;
                            }
                            edi = edi - 0x1;
                            if (edi != 0x0) {
                                    continue;
                            }
                            break;
                    }
                    ecx = esi[0xd];
                    if (*ecx <= 0x0) {
                            esp = esp - 0x4;
                            eax = (*(*esi + 0x4))(ebx & 0xff);
                            if (eax == 0xffffffff) {
                                    arg_c = 0x1;
                            }
                            edi = edi - 0x1;
                            if (edi != 0x0) {
                                    continue;
                            }
                            break;
                    }
                    *ecx = *ecx - 0x1;
                    eax = esi[0x9];
                    ecx = *eax;
                    *eax = ecx + 0x1;
                    *(int8_t *)ecx = ebx;
                    eax = ebx & 0xff;
                    if (eax == 0xffffffff) {
                            arg_c = 0x1;
                    }
                    edi = edi - 0x1;
            } while (edi != 0x0);
            esp = esp + 0x4;
    }
    eax = arg_4;
    *eax = arg_8;
    eax[0x1] = arg_c;
    eax[0x2] = esi;
    return eax;
}
