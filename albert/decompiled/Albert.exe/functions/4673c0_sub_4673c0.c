// sub_4673c0 @ 0x4673c0
// hopper name: sub_4673c0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4673c0() {
    decomp_var_4 = esi;
    decomp_var_8 = edi;
    edi = ecx - 0x4c;
    sub_467170();
    edi[0x13] = 0x4b1c3c;
    sub_493590(edi + 0x4c);
    esp = (esp - 0xc) + 0x4;
    if ((arg_0 & 0x1) != 0x0) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    eax = edi;
    return eax;
}
