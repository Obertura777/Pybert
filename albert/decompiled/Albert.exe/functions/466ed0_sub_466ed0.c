// sub_466ed0 @ 0x466ed0
// hopper name: sub_466ed0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_466ed0() {
    var_C = *0x0;
    decomp_var_24 = ebx;
    decomp_var_28 = esi;
    decomp_var_2c = edi;
    decomp_var_30 = *dword_4c8db8 ^ &decomp_var_2c;
    *0x0 = &var_C;
    var_14 = 0x0;
    sub_465940(ecx, 0x1, decomp_var_30);
    edi = arg_0;
    esp = esp - 0x40;
    sub_466e10(edi, arg_4);
    eax = 0x0;
    if (0x0 != 0x0) {
            sub_47b6f8();
            sub_47c8f9();
            esp = (esp - 0x14) + 0x4;
    }
    eax = var_14;
    if (eax != 0x0) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    eax = edi;
    *0x0 = var_C;
    return eax;
}
