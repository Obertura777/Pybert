// sub_47dbc3 @ 0x47dbc3
// hopper name: sub_47dbc3
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47dbc3() {
    decomp_var_24 = edi;
    eax = sub_47d630(esi);
    esp = (esp - 0x8) + 0x4;
    if (esi == 0x0) {
            *sub_47d812() = 0x16;
            eax = sub_47a924();
            esp = (esp - 0x14) + 0x14;
            eax = eax | 0xffffffff;
    }
    else {
            if (arg_4 != 0x0) {
                    var_20 = esi;
                    eax = (arg_0)(&var_20, arg_4, arg_8, arg_c);
                    esp = (esp - 0x10) + 0x10;
            }
            else {
                    *sub_47d812() = 0x16;
                    eax = sub_47a924();
                    esp = (esp - 0x14) + 0x14;
                    eax = eax | 0xffffffff;
            }
    }
    return eax;
}
