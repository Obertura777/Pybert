// sub_46e5e8 @ 0x46e5e8
// hopper name: sub_46e5e8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46e5e8() {
    eax = CompareStringA(0x409, 0x1, arg_0, 0xffffffff, arg_4, 0xffffffff);
    eax = eax - 0x2;
    return eax;
}
