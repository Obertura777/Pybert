// sub_470381 @ 0x470381
// hopper name: sub_470381
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_470381() {
    sub_4727e8();
    *ecx = 0x4b2854;
    sub_47ba40(ecx + 0x54, 0x0, 0x20);
    ecx[0x1a] = arg_4;
    ecx[0x15] = arg_0;
    ecx[0x16] = arg_0 & 0xffff;
    eax = ecx;
    return eax;
}
