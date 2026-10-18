// sub_49f1c0 @ 0x49f1c0
// hopper name: sub_49f1c0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_d0ced5848078d0c8fa33850112ccedc1b66b774e6265bab395e5928f9c409794
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_49f1c0() {
    eax = sub_410330();
    *dword_bb7134 = eax;
    eax[0x19] = 0x1;
    eax = *dword_bb7134;
    eax[0x1] = eax;
    eax = *dword_bb7134;
    *eax = eax;
    eax = *dword_bb7134;
    eax[0x2] = eax;
    *dword_bb7138 = 0x0;
    eax = sub_47ae90(sub_4a7900);
    return eax;
}
