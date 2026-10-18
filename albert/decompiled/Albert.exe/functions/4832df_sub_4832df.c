// sub_4832df @ 0x4832df
// hopper name: sub_4832df
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4832df() {
    decomp_var_c = arg_c;
    esp = esp - 0x8;
    decomp_var_10 = arg_8;
    if (arg_0 != 0x0) {
            esp = esp - 0x4;
            sub_48c6d5(&var_8, decomp_var_10, decomp_var_c);
            eax = arg_4;
            *eax = var_8;
            eax[0x1] = var_4;
    }
    else {
            esp = esp - 0x4;
            sub_48c77b(&arg_0, decomp_var_10, decomp_var_c);
            eax = arg_4;
            *eax = arg_0;
    }
    return eax;
}
