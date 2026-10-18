// sub_48dff3 @ 0x48dff3
// hopper name: sub_48dff3
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48dff3() {
    esp = esp - 0x8;
    sub_47f31c(0x4c3950, 0x14);
    esi = esi | 0xffffffff;
    decomp_var_24 = esi;
    decomp_var_20 = esi;
    eax = arg_4;
    if (eax == 0xfffffffe) {
            eax = sub_47d825();
            *eax = *eax & 0x0;
            *sub_47d812() = 0x9;
            eax = sub_47f361();
    }
    else {
            if (eax >= 0x0) {
                    if (eax >= *dword_bc7228) {
                            *sub_47d825() = 0x0;
                            *sub_47d812() = 0x9;
                            sub_47a924();
                            eax = sub_47f361();
                    }
                    else {
                            ebx = (SAR(eax, 0x5)) * 0x4 + dword_bc7240;
                            esi = (eax & 0x1f) * 0x28;
                            if ((*(int8_t *)(*ebx + esi + 0x4) & 0xff & 0x1) == 0x0) {
                                    *sub_47d825() = 0x0;
                                    *sub_47d812() = 0x9;
                                    sub_47a924();
                            }
                            else {
                                    sub_48e4ad();
                                    esp = (esp - 0x4) + 0x4;
                                    if ((*(int8_t *)(*ebx + esi + 0x4) & 0x1) != 0x0) {
                                            decomp_var_24 = sub_48df70(arg_4, arg_8, arg_c, arg_10);
                                            decomp_var_20 = edx;
                                    }
                                    else {
                                            *sub_47d812() = 0x9;
                                            *sub_47d825() = 0x0;
                                            decomp_var_24 = decomp_var_24 | 0xffffffff;
                                            decomp_var_20 = decomp_var_20 | 0xffffffff;
                                    }
                                    sub_48e102();
                            }
                            eax = sub_47f361();
                    }
            }
            else {
                    *sub_47d825() = 0x0;
                    *sub_47d812() = 0x9;
                    sub_47a924();
                    eax = sub_47f361();
            }
    }
    return eax;
}
