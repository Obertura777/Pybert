// sub_47db5e @ 0x47db5e
// hopper name: sub_47db5e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47db5e() {
    ecx = arg_0;
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    decomp_var_c = edi;
    if (ecx != 0x0) {
            edi = arg_4;
            if (edi <= 0x0) {
                    esp = (esp - 0x4) + 0x4;
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = (esp - 0x14) + 0x14;
                    eax = 0x16;
            }
            else {
                    ebx = 0x0;
                    esi = arg_8;
                    if (esi == 0x0) {
                            *(int8_t *)ecx = ebx;
                            esp = (esp - 0x4) + 0x4;
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = 0x16;
                    }
                    else {
                            edx = ecx;
                            do {
                                    eax = *(int8_t *)esi;
                                    *(int8_t *)edx = eax;
                                    edx = edx + 0x1;
                                    esi = esi + 0x1;
                                    if (eax == ebx) {
                                            break;
                                    }
                                    edi = edi - 0x1;
                            } while (edi != 0x0);
                            if (edi == ebx) {
                                    *(int8_t *)ecx = 0x0;
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
