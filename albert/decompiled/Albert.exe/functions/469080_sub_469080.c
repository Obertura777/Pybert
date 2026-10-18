// sub_469080 @ 0x469080
// hopper name: sub_469080
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_469080() {
    var_C = *0x0;
    decomp_var_14 = ebx;
    decomp_var_18 = esi;
    decomp_var_1c = edi;
    esp = esp - 0x20;
    decomp_var_20 = *dword_4c8db8 ^ ebp;
    *0x0 = &var_C;
    eax = *ecx;
    if ((*(int8_t *)(eax[0x1] + ecx + 0x10) & 0x2) != 0x0) {
            eax = sub_468fa0();
    }
    *0x0 = var_C;
    &var_10 = ebp;
    return eax;
}
