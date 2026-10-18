// sub_467710 @ 0x467710
// hopper name: sub_467710
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467710() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = ecx;
    *esi = 0x4b1cd4;
    if (esi[0x9] >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    esi[0x9] = 0xf;
    esi[0x8] = 0x0;
    esi[0x10] = 0x0;
    sub_47a73c();
    if ((arg_0 & 0x1) != 0x0) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    eax = esi;
    return eax;
}
