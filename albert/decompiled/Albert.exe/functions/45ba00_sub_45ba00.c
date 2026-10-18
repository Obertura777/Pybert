// sub_45ba00 @ 0x45ba00
// hopper name: sub_45ba00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45ba00() {
    edx = arg_0;
    eax = edx[0x2];
    esp = esp - 0x4;
    decomp_var_4 = esi;
    edx[0x2] = *eax;
    esi = *eax;
    if (esi[0x2d] == 0x0) {
            esi[0x1] = edx;
    }
    eax[0x1] = edx[0x1];
    ecx = ecx[0x1];
    if (edx == ecx[0x1]) {
            ecx[0x1] = eax;
            *eax = edx;
            edx[0x1] = eax;
    }
    else {
            ecx = edx[0x1];
            if (edx == *ecx) {
                    *ecx = eax;
                    *eax = edx;
                    edx[0x1] = eax;
            }
            else {
                    ecx[0x2] = eax;
                    *eax = edx;
                    edx[0x1] = eax;
            }
    }
    return eax;
}
