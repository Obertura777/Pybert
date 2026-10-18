// sub_45de50 @ 0x45de50
// hopper name: sub_45de50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45de50() {
    var_C = *0x0;
    decomp_var_1c = ebx;
    decomp_var_20 = esi;
    decomp_var_24 = edi;
    decomp_var_28 = *dword_4c8db8 ^ ebp;
    *0x0 = &var_C;
    esi = sub_46dbce(0x30);
    esp = (esp - 0x2c) + 0x4;
    if (esi != 0x0) {
            esp = esp - 0x14;
            sub_45d450(arg_0, arg_4, arg_8, arg_c, arg_10);
    }
    eax = esi;
    *0x0 = var_C;
    &var_18 = ebp;
    return eax;
}
