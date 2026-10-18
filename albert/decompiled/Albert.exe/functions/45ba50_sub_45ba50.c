// sub_45ba50 @ 0x45ba50
// hopper name: sub_45ba50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45ba50() {
    eax = arg_0;
    if (eax == 0xffffffff) {
            eax = *ecx;
            if (eax != 0x0) {
                    esp = esp - 0x4;
                    decomp_var_4 = esi;
                    esi = eax + 0x1;
                    do {
                            edx = *(int8_t *)eax;
                            eax = eax + 0x1;
                    } while (edx != 0x0);
                    eax = eax - esi;
                    esp = esp + 0x4;
                    if (eax >= 0x0) {
                            edx = *ecx;
                            if (eax <= *(edx - 0x8)) {
                                    *(edx - 0xc) = eax;
                                    *(int8_t *)(eax + *ecx) = 0x0;
                            }
                            else {
                                    eax = sub_40b5a0(0x80070057);
                            }
                    }
                    else {
                            eax = sub_40b5a0(0x80070057);
                    }
            }
            else {
                    edx = *ecx;
                    if (eax <= *(edx - 0x8)) {
                            *(edx - 0xc) = eax;
                            *(int8_t *)(eax + *ecx) = 0x0;
                    }
                    else {
                            eax = sub_40b5a0(0x80070057);
                    }
            }
    }
    else {
            if (eax >= 0x0) {
                    edx = *ecx;
                    if (eax <= *(edx - 0x8)) {
                            *(edx - 0xc) = eax;
                            *(int8_t *)(eax + *ecx) = 0x0;
                    }
                    else {
                            eax = sub_40b5a0(0x80070057);
                    }
            }
            else {
                    eax = sub_40b5a0(0x80070057);
            }
    }
    return eax;
}
