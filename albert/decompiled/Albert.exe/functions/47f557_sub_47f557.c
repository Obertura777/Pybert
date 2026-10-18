// sub_47f557 @ 0x47f557
// hopper name: sub_47f557
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47f557() {
    eax = arg_0;
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    decomp_var_c = edi;
    if (eax != 0x0) {
            edi = arg_4;
            if (edi <= 0x0) {
                    esp = (esp - 0x4) + 0x4;
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = (esp - 0x14) + 0x14;
                    eax = 0x16;
            }
            else {
                    esi = arg_8;
                    if (esi == 0x0) {
                            *(int8_t *)eax = 0x0;
                            esp = (esp - 0x4) + 0x4;
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = 0x16;
                    }
                    else {
                            edx = eax;
                            while (*(int8_t *)edx != 0x0) {
                                    edx = edx + 0x1;
                                    edi = edi - 0x1;
                                    if (edi == 0x0) {
                                            break;
                                    }
                            }
                            if (edi != 0x0) {
                                    do {
                                            ecx = *(int8_t *)esi;
                                            *(int8_t *)edx = ecx;
                                            edx = edx + 0x1;
                                            esi = esi + 0x1;
                                            if (ecx == 0x0) {
                                                    break;
                                            }
                                            edi = edi - 0x1;
                                    } while (edi != 0x0);
                                    ebx = 0x0;
                                    if (edi == 0x0) {
                                            *(int8_t *)eax = ebx;
                                            esp = (esp - 0x4) + 0x4;
                                            *sub_47d812() = 0x22;
                                            sub_47a924();
                                            esp = (esp - 0x14) + 0x14;
                                            eax = 0x22;
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    *(int8_t *)eax = 0x0;
                                    esp = (esp - 0x4) + 0x4;
                                    *sub_47d812() = 0x16;
                                    sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    eax = 0x16;
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
    return eax;
}
