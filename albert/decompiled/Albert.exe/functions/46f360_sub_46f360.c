// sub_46f360 @ 0x46f360
// hopper name: sub_46f360
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46f360() {
    ecx[0x8] = 0x0;
    ecx[0x9] = 0x0;
    ecx[0xb] = 0x0;
    ecx[0xc] = 0x0;
    eax = sub_471099();
    eax[0xd] = 0x0;
    eax[0x15] = 0x0;
    eax = GetCursorPos(eax + 0x4c);
    ecx[0x10] = 0x0;
    ecx[0xf] = 0x0;
    ecx[0xa] = 0x1;
    return eax;
}
