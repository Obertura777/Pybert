// sub_45bc10 @ 0x45bc10
// hopper name: sub_45bc10
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45bc10() {
    eax = arg_4;
    bool_0 = eax[0x6] < 0x10;
    ecx = eax[0x5];
    if (!bool_0) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    eax = sub_40e9b0();
    eax = eax < 0x0 ? 0x1 : 0x0;
    return eax;
}
