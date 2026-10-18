// sub_48edeb @ 0x48edeb
// hopper name: sub_48edeb
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48edeb() {
    esp = esp - 0x8;
    sub_47f31c(0x4c39d8, 0x14);
    decomp_var_1c = 0x0;
    edi = arg_14;
    if (edi == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            eax = sub_47f361();
    }
    else {
            *edi = *edi | 0xffffffff;
            if (arg_4 != 0x0) {
                    esi = 0x0;
                    if (arg_18 != 0x0) {
                            if (-(arg_10 & 0xfffffe7f) - -(arg_10 & 0xfffffe7f) + CARRY(EFLAGS(cf)) != 0xffffffff) {
                                    sub_48e7ad(&decomp_var_1c, arg_4, arg_8, arg_c, arg_10);
                                    sub_48ee89();
                                    if (decomp_var_20 != esi) {
                                            *edi = *edi | 0xffffffff;
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
                            sub_48e7ad(&decomp_var_1c, arg_4, arg_8, arg_c, arg_10);
                            sub_48ee89();
                            if (decomp_var_20 != esi) {
                                    *edi = *edi | 0xffffffff;
                            }
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
