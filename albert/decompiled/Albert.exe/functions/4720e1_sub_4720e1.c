// sub_4720e1 @ 0x4720e1
// hopper name: sub_4720e1
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4720e1() {
    esp = esp - 0x4;
    esi = ecx;
    eax = loc_47675f();
    if (arg_8 == 0x0) {
            eax = eax & 0xfffffdff;
    }
    sub_476745();
    AdjustWindowRectEx(saved_fp, arg_0, arg_4, arg_8);
    return;
}
