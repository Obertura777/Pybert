// sub_45b7b0 @ 0x45b7b0
// hopper name: sub_45b7b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45b7b0() {
    eax = arg_0;
    ecx = eax[0x2];
    if (ecx[0x2d] == 0x0) {
            do {
                    eax = ecx;
                    ecx = eax[0x2];
            } while (ecx[0x2d] == 0x0);
    }
    return eax;
}
