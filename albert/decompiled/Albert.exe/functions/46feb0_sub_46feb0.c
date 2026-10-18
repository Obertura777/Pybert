// sub_46feb0 @ 0x46feb0
// hopper name: sub_46feb0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46feb0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = sub_46e5d5();
    if (esi != 0x0 && (*(*esi + 0x120))() != 0x0) {
            eax = esi + 0x80;
            if (*eax != 0x0) {
                    esp = esp - 0x4;
                    (*(**eax + 0x64))(arg_0);
            }
    }
    return;
}
