// sub_45bb70 @ 0x45bb70
// hopper name: sub_45bb70
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45bb70() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    if (esi[0x6] >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi[0x6] = 0xf;
    esi[0x5] = 0x0;
    esi[0x4] = 0x0;
    return 0x0;
}
