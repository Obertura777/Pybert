// sub_467170 @ 0x467170
// hopper name: sub_467170
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467170() {
    var_C = *0x0;
    decomp_var_14 = esi;
    *0x0 = &var_C;
    *(*(*(ecx - 0x4c) + 0x4) + (ecx - 0x4c)) = 0x4b1ccc;
    *(ecx - 0x48) = 0x4b1c90;
    sub_465e50();
    sub_4666a0();
    eax = *(ecx - 0x4c);
    *(eax[0x1] + (ecx - 0x4c)) = 0x4b1c44;
    *0x0 = var_C;
    return eax;
}
