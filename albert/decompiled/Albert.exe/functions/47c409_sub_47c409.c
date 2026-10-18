// sub_47c409 @ 0x47c409
// hopper name: sub_47c409
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47c409() {
    sub_47f31c(0x4c3400, 0x14);
    decomp_var_1c = 0x0;
    decomp_var_24 = 0x0;
    sub_487c06(0x1);
    esp = (esp - 0xc) + 0x4;
    for (esi = 0x0; esi < *dword_bc8360; esi = esi + 0x1) {
            eax = *dword_bc7340;
            eax = eax + esi * 0x4;
            if (*eax == 0x0) {
                    esi = esi + 0x1;
                    continue;
            }
            eax = *eax;
            if ((eax[0xc] & 0x83) == 0x0) {
                    esi = esi + 0x1;
                    continue;
            }
            sub_48690d(esi, eax);
            esp = (esp - 0x8) + 0x8;
            eax = *dword_bc7340;
            eax = *(eax + esi * 0x4);
            ecx = eax[0x3];
            if ((ecx & 0x83) != 0x0) {
                    if (arg_4 == 0x1) {
                            esp = (esp - 0x4) + 0x4;
                            if (sub_47c3c7(eax) != 0xffffffff) {
                                    decomp_var_1c = decomp_var_1c + 0x1;
                            }
                    }
                    else {
                            if (arg_4 == 0x0 && (ecx & 0x2) != 0x0) {
                                    eax = sub_47c3c7(eax);
                                    esp = (esp - 0x4) + 0x4;
                                    if (eax == 0xffffffff) {
                                            decomp_var_24 = decomp_var_24 | eax;
                                    }
                            }
                    }
            }
            sub_47c4ab();
    }
    sub_47c4da();
    eax = sub_47f361();
    return eax;
}
