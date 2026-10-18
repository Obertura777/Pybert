// sub_483ae7 @ 0x483ae7
// hopper name: sub_483ae7
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_483ae7() {
    var_4 = *dword_4c8db8 ^ ebp;
    decomp_var_34 = ebx;
    decomp_var_38 = esi;
    esi = arg_4;
    decomp_var_3c = edi;
    eax = sub_48c999(*arg_0, arg_0[0x1], &var_30, &var_1C, 0x16);
    esp = ((esp - 0x10) + 0x4 - 0x14) + 0x14;
    if (esi == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            esp = (esp - 0x14) + 0x14;
            eax = sub_47ad69();
    }
    else {
            ecx = arg_8;
            if (ecx > 0x0) {
                    var_20 = var_2C - 0x1;
                    eax = var_30 == 0x2d ? 0x1 : 0x0;
                    edi = eax + esi;
                    if (var_30 == 0x2d) {
                            ecx = ecx | ecx;
                    }
                    else {
                            ecx = ecx - eax;
                    }
                    ebx = 0x0;
                    eax = sub_48c821(edi, ecx, arg_c, &var_30);
                    esp = (esp - 0x10) + 0x10;
                    if (eax != 0x0) {
                            *(int8_t *)esi = ebx;
                            eax = sub_47ad69();
                    }
                    else {
                            eax = var_2C - 0x1;
                            ecx = var_20 < eax ? 0x1 : 0x0;
                            if (var_20 >= eax) {
                                    if (eax < arg_c) {
                                            ebx = 0x0;
                                            if (ecx != 0x0) {
                                                    do {
                                                            eax = *(int8_t *)edi;
                                                            edi = edi + 0x1;
                                                    } while (eax != 0x0);
                                                    *(int8_t *)(edi - 0x2) = ebx;
                                            }
                                            sub_483939(arg_8, arg_c, 0x1, arg_14);
                                            esp = (esp - 0x10) + 0x10;
                                            eax = sub_47ad69();
                                    }
                                    else {
                                            sub_48336f(arg_8, arg_c, arg_10, &var_30, 0x1, arg_14);
                                            esp = (esp - 0x18) + 0x18;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    sub_48336f(arg_8, arg_c, arg_10, &var_30, 0x1, arg_14);
                                    esp = (esp - 0x18) + 0x18;
                                    eax = sub_47ad69();
                            }
                    }
            }
            else {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = (esp - 0x14) + 0x14;
                    eax = sub_47ad69();
            }
    }
    return eax;
}
