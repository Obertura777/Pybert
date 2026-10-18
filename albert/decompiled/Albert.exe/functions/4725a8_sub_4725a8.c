// sub_4725a8 @ 0x4725a8
// hopper name: sub_4725a8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4725a8() {
    sub_47f31c(saved_fp, arg_0);
    esp = esp - 0x10;
    *(sub_4715ba() + 0x80);
    if (sub_470ded() != 0x0) {
            GetClassInfoExA(saved_fp, arg_0, arg_4);
            loc_472607();
    }
    sub_47f361();
    return;
}
