// sub_4866e1 @ 0x4866e1
// hopper name: sub_4866e1
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4866e1() {
    esp = esp - 0x8;
    sub_47f31c(0x4c3810, 0x10);
    eax = arg_4;
    if (eax == 0xfffffffe) {
            eax = sub_47d825();
            *eax = *eax & 0x0;
            eax = sub_47d812();
            *eax = 0x9;
            eax = sub_47f361();
    }
    else {
            if (eax >= 0x0) {
                    if (eax >= *dword_bc7228) {
                            *sub_47d825() = 0x0;
                            *sub_47d812() = 0x9;
                            eax = sub_47a924();
                            eax = sub_47f361();
                    }
                    else {
                            ebx = (SAR(eax, 0x5)) * 0x4 + dword_bc7240;
                            esi = (eax & 0x1f) * 0x28;
                            if ((*(int8_t *)(*ebx + esi + 0x4) & 0xff & 0x1) != 0x0) {
                                    decomp_var_c = eax;
                                    sub_48e4ad();
                                    esp = (esp - 0x4) + 0x4;
                                    if ((*(int8_t *)(*ebx + esi + 0x4) & 0x1) != 0x0) {
                                            decomp_var_1c = sub_48664d(arg_4);
                                    }
                                    else {
                                            *sub_47d812() = 0x9;
                                            decomp_var_1c = decomp_var_1c | 0xffffffff;
                                    }
                                    sub_4867a4();
                                    eax = sub_47f361();
                            }
                            else {
                                    *sub_47d825() = 0x0;
                                    *sub_47d812() = 0x9;
                                    eax = sub_47a924();
                                    eax = sub_47f361();
                            }
                    }
            }
            else {
                    *sub_47d825() = 0x0;
                    *sub_47d812() = 0x9;
                    eax = sub_47a924();
                    eax = sub_47f361();
            }
    }
    return eax;
}
