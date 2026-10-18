// sub_49f010 @ 0x49f010
// hopper name: sub_49f010
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_d0ced5848078d0c8fa33850112ccedc1b66b774e6265bab395e5928f9c409794
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_49f010() {
    eax = sub_40fd90();
    *dword_bb6df8 = eax;
    eax[0x1d] = 0x1;
    eax = *dword_bb6df8;
    eax[0x1] = eax;
    eax = *dword_bb6df8;
    *eax = eax;
    eax = *dword_bb6df8;
    eax[0x2] = eax;
    *dword_bb6dfc = 0x0;
    eax = sub_47ae90(sub_4a77c0);
    return eax;
}
