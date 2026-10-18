// sub_49f0e0 @ 0x49f0e0
// hopper name: sub_49f0e0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_d0ced5848078d0c8fa33850112ccedc1b66b774e6265bab395e5928f9c409794
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_49f0e0() {
    eax = sub_40fed0();
    *dword_bb6f20 = eax;
    eax[0x21] = 0x1;
    eax = *dword_bb6f20;
    eax[0x1] = eax;
    eax = *dword_bb6f20;
    *eax = eax;
    eax = *dword_bb6f20;
    eax[0x2] = eax;
    *dword_bb6f24 = 0x0;
    eax = sub_47ae90(sub_4a7b40);
    return eax;
}
