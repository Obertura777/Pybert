// sub_48187a @ 0x48187a
// hopper name: sub_48187a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48187a() {
    decomp_var_4 = 0x14;
    esp = esp - 0x8;
    sub_47f31c(0x4c3778, 0x14);
    decomp_var_20 = decomp_var_20 | 0xffffffff;
    edi = sub_480086();
    decomp_var_24 = edi;
    sub_4815b1();
    ebx = edi[0x1a];
    eax = sub_481655();
    arg_4 = eax;
    if (eax != ebx[0x1]) {
            esp = (esp - 0x4) + 0x4;
            ebx = sub_481280(0x220);
            bool_3 = true;
            if (ebx != 0x0) {
                    *ebx = *edi[0x1a];
                    *ebx = *ebx & 0x0;
                    eax = sub_4816cf(arg_4, ebx);
                    esp = (esp - 0x8) + 0x8;
                    decomp_var_20 = eax;
                    if (eax == 0x0) {
                            esi = decomp_var_24;
                            esp = esp - 0x4;
                            decomp_var_c = esi[0x1a];
                            if (InterlockedDecrement(decomp_var_c) == 0x0) {
                                    eax = esi[0x1a];
                                    if (eax != 0x4c8ff0) {
                                            decomp_var_c = eax;
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                    }
                            }
                            esi[0x1a] = ebx;
                            esp = esp - 0x4;
                            InterlockedIncrement(ebx);
                            if ((esi[0x70] & 0x2) == 0x0 && (*(int8_t *)byte_4c9514 & 0x1) == 0x0) {
                                    sub_487c06(0xd);
                                    esp = (esp - 0x4) + 0x4;
                                    *dword_bc6860 = ebx[0x1];
                                    *dword_bc6864 = ebx[0x2];
                                    *dword_bc6868 = ebx[0x3];
                                    for (eax = 0x0; eax < 0x5; eax = eax + 0x1) {
                                            *(int16_t *)(eax * 0x2 + 0xbc6854) = *(int16_t *)(ebx + eax * 0x2 + 0x10);
                                    }
                                    for (eax = 0x0; eax < 0x101; eax = eax + 0x1) {
                                            eax[0x4c9210] = *(int8_t *)(eax + ebx + 0x1c);
                                    }
                                    for (eax = 0x0; eax < 0x100; eax = eax + 0x1) {
                                            eax[0x4c9318] = *(int8_t *)(eax + ebx + 0x11d);
                                    }
                                    esp = esp - 0x4;
                                    if (InterlockedDecrement(*dword_4c9418) == 0x0 && *dword_4c9418 != 0x4c8ff0) {
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    *dword_4c9418 = ebx;
                                    InterlockedIncrement(ebx);
                                    sub_4819db();
                            }
                    }
                    else {
                            if (eax == 0xffffffff) {
                                    if (ebx != 0x4c8ff0) {
                                            sub_47c8f9();
                                    }
                                    *sub_47d812() = 0x16;
                            }
                    }
            }
    }
    else {
            decomp_var_20 = decomp_var_20 & 0x0;
    }
    eax = sub_47f361();
    return eax;
}
