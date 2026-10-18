// sub_45bba0 @ 0x45bba0
// hopper name: sub_45bba0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45bba0() {
    edx = ecx[0x1];
    eax = edx[0x1];
    esp = esp - 0x8;
    edi = arg_4;
    if (eax[0xf] == 0x0) {
            esi = *(int16_t *)edi & 0xffff;
            do {
                    if (esi < eax[0x6]) {
                            edx = eax;
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0xf] == 0x0);
    }
    esi = ecx[0x1];
    eax = esi[0x1];
    if (eax[0xf] == 0x0) {
            edi = *(int16_t *)edi & 0xffff;
            &saved_fp = &saved_fp;
            do {
                    if (eax[0x6] < edi) {
                            eax = eax[0x2];
                    }
                    else {
                            esi = eax;
                            eax = *eax;
                    }
            } while (eax[0xf] == 0x0);
    }
    eax = arg_10;
    eax[0x1] = esi;
    *eax = ecx;
    eax[0x2] = ecx;
    eax[0x3] = edx;
    return eax;
}
