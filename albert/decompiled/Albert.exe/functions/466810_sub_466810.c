// sub_466810 @ 0x466810
// hopper name: sub_466810
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_466810() {
    eax = ecx[0x8];
    eax = *eax;
    if (eax != 0x0) {
            if (eax > *ecx[0x4]) {
                    edx = arg_0;
                    if (edx != 0xffffffff) {
                            if (edx != *(int8_t *)(eax - 0x1)) {
                                    if ((ecx[0x40] & 0x2) == 0x0) {
                                            eax = ecx[0xc];
                                            *eax = *eax + 0x1;
                                            eax = ecx[0x8];
                                            *eax = *eax - 0x1;
                                            if (edx != 0xffffffff) {
                                                    *(int8_t *)*ecx[0x8] = edx;
                                                    eax = edx;
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = eax | 0xffffffff;
                                    }
                            }
                            else {
                                    eax = ecx[0xc];
                                    *eax = *eax + 0x1;
                                    eax = ecx[0x8];
                                    *eax = *eax - 0x1;
                                    if (edx != 0xffffffff) {
                                            *(int8_t *)*ecx[0x8] = edx;
                                            eax = edx;
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                    }
                    else {
                            eax = ecx[0xc];
                            *eax = *eax + 0x1;
                            eax = ecx[0x8];
                            *eax = *eax - 0x1;
                            if (edx != 0xffffffff) {
                                    *(int8_t *)*ecx[0x8] = edx;
                                    eax = edx;
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
            }
            else {
                    eax = eax | 0xffffffff;
            }
    }
    else {
            eax = eax | 0xffffffff;
    }
    return eax;
}
