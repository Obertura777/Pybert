// sub_47263c @ 0x47263c
// hopper name: sub_47263c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47263c() {
    sub_47f31c(0x4c23d0, 0x14);
    decomp_var_20 = 0x0;
    sub_4715ba(&decomp_var_20);
    esp = esp - 0x10;
    if (sub_470ded() != 0x0) {
            CreateWindowExA(arg_4, arg_8, arg_c, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28, arg_2c, arg_30);
            sub_4726b6();
    }
    eax = sub_47f361();
    return eax;
}
