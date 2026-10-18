// sub_465d90 @ 0x465d90
// hopper name: sub_465d90
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465d90() {
    decomp_var_4 = ebx;
    ebx = arg_0;
    decomp_var_8 = esi;
    esi = *ebx;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edx = 0x0;
    edi = 0x0;
    if (esi != 0x0) {
            eax = *ecx;
            if (eax != 0x0) {
                    ecx = ecx[0x1];
                    if (ecx != ebx[0x1]) {
                            eax = 0x1 == 0x0 ? 0x1 : 0x0;
                    }
                    else {
                            esi = esi - eax;
                            while (edi < ecx) {
                                    if (*(int16_t *)(esi + eax) != *(int16_t *)eax) {
                                            edx = 0x1;
                                    }
                                    edi = edi + 0x1;
                                    eax = eax + 0x2;
                                    if (edx != 0x0) {
                                            break;
                                    }
                            }
                            eax = edx == 0x0 ? 0x1 : 0x0;
                    }
            }
            else {
                    eax = 0x1 == 0x0 ? 0x1 : 0x0;
            }
    }
    else {
            eax = 0x1 == 0x0 ? 0x1 : 0x0;
    }
    return eax;
}
