// sub_45bae0 @ 0x45bae0
// hopper name: sub_45bae0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45bae0() {
    eax = sub_46dbce(0x14);
    esp = (esp - 0x4) + 0x4;
    if (eax != 0x0) {
            *eax = arg_0;
    }
    ecx = eax + 0x4;
    if (ecx != 0x0) {
            *ecx = arg_4;
    }
    ecx = eax + 0x8;
    if (ecx != 0x0) {
            *ecx = *arg_8;
            ecx[0x1] = arg_8[0x1];
            ecx[0x2] = arg_8[0x2];
    }
    return;
}
