// sub_466860 @ 0x466860
// hopper name: sub_466860
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_466860() {
    edx = ecx[0x8];
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = *edx;
    if (esi == 0x0) {
            eax = eax | 0xffffffff;
    }
    else {
            decomp_var_8 = ebx;
            esp = esp - 0x8;
            decomp_var_c = edi;
            edi = ecx[0xc];
            eax = esi;
            if (eax < *edi + eax) {
                    eax = *(int8_t *)esi & 0xff;
            }
            else {
                    if ((ecx[0x40] & 0x4) == 0x0) {
                            eax = ecx[0x9];
                            eax = *eax;
                            if (eax != 0x0) {
                                    if (eax <= esi) {
                                            if (ecx[0xf] > esi) {
                                                    if (ecx[0xf] < eax) {
                                                            ecx[0xf] = eax;
                                                    }
                                                    *edi = ecx[0xf] - *edx;
                                                    eax = *(int8_t *)*ecx[0x8] & 0xff;
                                            }
                                            else {
                                                    eax = eax | 0xffffffff;
                                            }
                                    }
                                    else {
                                            if (ecx[0xf] < eax) {
                                                    ecx[0xf] = eax;
                                            }
                                            *edi = ecx[0xf] - *edx;
                                            eax = *(int8_t *)*ecx[0x8] & 0xff;
                                    }
                            }
                            else {
                                    eax = eax | 0xffffffff;
                            }
                    }
                    else {
                            eax = eax | 0xffffffff;
                    }
            }
    }
    return eax;
}
