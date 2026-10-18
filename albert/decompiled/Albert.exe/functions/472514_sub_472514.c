// sub_472514 @ 0x472514
// hopper name: sub_472514
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_472514() {
    sub_47f31c(0x4c2390, 0x14);
    decomp_var_20 = 0x0;
    sub_4715ba(&decomp_var_20);
    esp = esp - 0x10;
    if (sub_470ded() != 0x0) {
            GetClassInfoA(arg_4, arg_8, arg_c);
            sub_472573();
    }
    eax = sub_47f361();
    return eax;
}
