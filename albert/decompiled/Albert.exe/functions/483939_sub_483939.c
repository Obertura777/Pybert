// sub_483939 @ 0x483939
// hopper name: sub_483939
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_483939() {
    decomp_var_14 = ebx;
    decomp_var_18 = esi;
    decomp_var_1c = edi;
    esp = esp - 0x10;
    ebx = eax;
    esi = ebx[0x1];
    edi = ecx;
    esi = esi - 0x1;
    sub_47aea2(arg_c);
    if (edi == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
            if (var_4 != 0x0) {
                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
            }
            eax = 0x16;
    }
    else {
            if (arg_0 > 0x0) {
                    if (arg_8 != 0x0 && esi == arg_4) {
                            bool_11 = *ebx == 0x2d;
                            *(int8_t *)((bool_11 ? 0x1 : 0x0) + esi + edi) = 0x30;
                            *(int8_t *)((bool_11 ? 0x1 : 0x0) + esi + edi + 0x1) = 0x0;
                    }
                    esi = edi;
                    if (*ebx == 0x2d) {
                            *(int8_t *)edi = 0x2d;
                            esi = edi + 0x1;
                    }
                    eax = ebx[0x1];
                    if (eax <= 0x0) {
                            sub_483336();
                            *(int8_t *)esi = 0x30;
                            esi = esi + 0x1;
                    }
                    else {
                            esi = esi + eax;
                    }
                    if (arg_4 > 0x0) {
                            sub_483336();
                            *(int8_t *)esi = *(int8_t *)*var_10[0x2f];
                            ebx = ebx[0x1];
                            esi = esi + 0x1;
                            if (ebx < 0x0) {
                                    ebx = -ebx;
                                    if (arg_8 != 0x0 || arg_4 >= ebx) {
                                            arg_4 = ebx;
                                    }
                                    sub_483336();
                                    sub_47ba40(esi, 0x30, arg_4);
                                    esp = (esp - 0xc) + 0xc;
                            }
                    }
                    if (var_4 != 0x0) {
                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                    }
                    eax = 0x0;
            }
            else {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = ((esp - 0x4) + 0x4 - 0x14) + 0x14;
                    if (var_4 != 0x0) {
                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                    }
                    eax = 0x16;
            }
    }
    return eax;
}
