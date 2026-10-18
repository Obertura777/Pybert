// sub_467400 @ 0x467400
// hopper name: sub_467400
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467400() {
    var_C = *0x0;
    decomp_var_14 = esi;
    esp = esp - 0x18;
    decomp_var_18 = *dword_4c8db8 ^ &decomp_var_14;
    *0x0 = &var_C;
    esi = ecx;
    sub_466b90();
    ecx = arg_0;
    eax = 0x0;
    *esi = 0x4b1c90;
    if ((ecx & 0x1) == 0x0) {
            eax = 0x4;
    }
    if ((ecx & 0x2) == 0x0) {
            eax = eax | 0x2;
    }
    if ((ecx & 0x8) != 0x0) {
            eax = eax | 0x8;
    }
    if ((ecx & 0x4) != 0x0) {
            eax = eax | 0x10;
    }
    esi[0x10] = eax;
    esi[0xf] = 0x0;
    eax = esi;
    *0x0 = var_C;
    return eax;
}
