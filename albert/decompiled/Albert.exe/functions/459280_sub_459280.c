// sub_459280 @ 0x459280
// hopper name: sub_459280
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_459280() {
    eax = ecx[0x2];
    if (eax[0x2449] == 0x0) {
            if (*(int8_t *)byte_baed46 == 0x1) {
                    eax = sub_457890();
            }
            else {
                    eax = sub_443ed0();
            }
    }
    return eax;
}
