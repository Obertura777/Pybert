// sub_45b860 @ 0x45b860
// hopper name: sub_45b860
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45b860() {
    WaitForSingleObject(*(*dword_bc2124 + 0x24), 0xffffffff);
    eax = *dword_bc2124;
    edx = eax[0x9];
    esi = eax[0x8];
    ReleaseMutex(edx);
    eax = esi != 0x0 ? 0x1 : 0x0;
    return eax;
}
