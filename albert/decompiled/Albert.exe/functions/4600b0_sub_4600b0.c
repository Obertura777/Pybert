// sub_4600b0 @ 0x4600b0
// hopper name: sub_4600b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4600b0() {
    eax = arg_4;
    if (eax == 0x1) {
            if (ecx[0x6] >= 0x10) {
                    eax = arg_8;
                    *(int8_t *)(ecx[0x1] + arg_0) = eax;
            }
            else {
                    eax = arg_8;
                    *(int8_t *)(ecx + 0x4 + arg_0) = eax;
            }
    }
    else {
            if (ecx[0x6] >= 0x10) {
                    ecx = ecx[0x1];
            }
            else {
                    ecx = ecx + 0x4;
            }
            eax = sub_47ba40(ecx + arg_c, sign_extend_32(arg_14), eax);
    }
    return eax;
}
