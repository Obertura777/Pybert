// sub_45b560 @ 0x45b560
// hopper name: sub_45b560
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45b560() {
    *(int8_t *)(ecx[0x2] + 0x2449) = 0x1;
    if (ecx[0x28] != 0x0) {
            ecx[0x28] = 0x0;
    }
    eax = sub_40bdb0();
    return eax;
}
