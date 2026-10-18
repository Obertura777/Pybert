// sub_47be47 @ 0x47be47
// hopper name: sub_47be47
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47be47() {
    esp = esp - 0x8;
    sub_47f31c(0x4c33e0, 0xc);
    edi = arg_4;
    if (edi == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            eax = sub_47f361();
    }
    else {
            esi = arg_8;
            if (esi != 0x0) {
                    if (*(int8_t *)esi != 0x0) {
                            ebx = 0x0;
                            eax = sub_486f29();
                            if (eax == 0x0) {
                                    *sub_47d812() = 0x18;
                            }
                            else {
                                    if (*(int8_t *)edi == ebx) {
                                            *sub_47d812() = 0x16;
                                            sub_487050(dword_4c8db8, &decomp_var_10, 0xfffffffe);
                                    }
                                    else {
                                            sub_486c87(edi, esi, arg_c, eax);
                                            sub_47bf01();
                                    }
                            }
                            eax = sub_47f361();
                    }
                    else {
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            eax = sub_47f361();
                    }
            }
            else {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    eax = sub_47f361();
            }
    }
    return eax;
}
