// sub_483a2e @ 0x483a2e
// hopper name: sub_483a2e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_483a2e() {
    var_4 = *dword_4c8db8 ^ ebp;
    decomp_var_30 = ebx;
    decomp_var_34 = esi;
    decomp_var_38 = edi;
    edi = arg_4;
    eax = sub_48c999(*arg_0, arg_0[0x1], &var_2C, &var_1C, 0x16);
    esp = ((esp - 0x10) + 0x4 - 0x14) + 0x14;
    if (edi == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            esp = (esp - 0x14) + 0x14;
            eax = sub_47ad69();
    }
    else {
            eax = arg_8;
            if (eax > 0x0) {
                    if (eax == 0xffffffff) {
                            eax = eax | eax;
                    }
                    else {
                            eax = eax - (var_2C == 0x2d ? 0x1 : 0x0);
                    }
                    esi = arg_c;
                    eax = sub_48c821((var_2C == 0x2d ? 0x1 : 0x0) + edi, eax, var_28 + esi, &var_2C);
                    esp = (esp - 0x10) + 0x10;
                    if (var_2C != 0x2d) {
                            *(int8_t *)edi = 0x0;
                    }
                    else {
                            sub_483939(arg_8, esi, 0x0, arg_10);
                            esp = (esp - 0x10) + 0x10;
                    }
                    eax = sub_47ad69();
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
