// sub_46dc5d @ 0x46dc5d
// hopper name: sub_46dc5d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46dc5d() {
    sub_47d6bb(0x4);
    esp = (esp - 0x8) + 0x4;
    ecx = sub_46dbce(0xc);
    eax = 0x0;
    decomp_var_4 = 0x0;
    if (ecx != 0x0) {
            eax = sub_46dc47();
    }
    eax[0x2] = arg_4;
    arg_4 = eax;
    eax = sub_47a958(&arg_4, 0x4c1d30);
    asm { int3 };
    return eax;
}
