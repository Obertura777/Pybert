// sub_4815b1 @ 0x4815b1
// hopper name: sub_4815b1
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4815b1() {
    decomp_var_4 = 0xc;
    esp = esp - 0x8;
    sub_47f31c(0x4c3758, 0xc);
    edi = sub_480086();
    if (!CPU_FLAGS & E) {
            if (edi[0x1b] != 0x0) {
                    esi = edi[0x1a];
                    if (esi == 0x0) {
                            sub_47d856(0x20);
                    }
                    eax = sub_47f361();
            }
            else {
                    sub_487c06(0xd);
                    esp = (esp - 0x4) + 0x4;
                    esi = edi[0x1a];
                    if (esi != *dword_4c9418) {
                            if (esi != 0x0) {
                                    esp = esp - 0x4;
                                    if (InterlockedDecrement(esi) == 0x0) {
                                            if (esi != 0x4c8ff0) {
                                                    decomp_var_c = esi;
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                    }
                            }
                            edi[0x1a] = *dword_4c9418;
                            esi = *dword_4c9418;
                            esp = esp - 0x4;
                            InterlockedIncrement(*dword_4c9418);
                    }
                    sub_48164c();
                    if (esi == 0x0) {
                            sub_47d856(0x20);
                    }
                    eax = sub_47f361();
            }
    }
    else {
            sub_487c06(0xd);
            esp = (esp - 0x4) + 0x4;
            esi = edi[0x1a];
            if (esi != *dword_4c9418) {
                    if (esi != 0x0) {
                            esp = esp - 0x4;
                            if (InterlockedDecrement(esi) == 0x0) {
                                    if (esi != 0x4c8ff0) {
                                            decomp_var_c = esi;
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                    }
                            }
                    }
                    edi[0x1a] = *dword_4c9418;
                    esi = *dword_4c9418;
                    esp = esp - 0x4;
                    InterlockedIncrement(*dword_4c9418);
            }
            sub_48164c();
            if (esi == 0x0) {
                    sub_47d856(0x20);
            }
            eax = sub_47f361();
    }
    return eax;
}
