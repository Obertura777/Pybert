// sub_467660 @ 0x467660
// hopper name: sub_467660
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467660() {
    var_C = *0x0;
    decomp_var_14 = esi;
    var_18 = *dword_4c8db8 ^ &decomp_var_14;
    *0x0 = &var_C;
    sub_47a685();
    *ecx = 0x4b1cd4;
    *(ecx + 0x20) = 0x0;
    *(ecx + 0x24) = 0xf;
    *(int8_t *)(ecx + 0x10) = 0x0;
    sub_4024f0(arg_0, 0x0, 0xffffffff);
    eax = ecx;
    *0x0 = var_18;
    return eax;
}
