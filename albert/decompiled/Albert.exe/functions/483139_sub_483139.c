// sub_483139 @ 0x483139
// hopper name: sub_483139
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_483139() {
    decomp_var_4 = 0x0;
    decomp_var_8 = arg_8;
    decomp_var_c = arg_4;
    esp = esp - 0x10;
    decomp_var_10 = arg_0;
    if (*dword_bc686c == 0x0) {
            esp = esp - 0x4;
            decomp_var_14 = 0x4c9600;
    }
    else {
            esp = esp - 0x4;
            decomp_var_14 = 0x0;
    }
    eax = sub_482f0e(decomp_var_14, decomp_var_10, decomp_var_c, decomp_var_8, decomp_var_4);
    return eax;
}
