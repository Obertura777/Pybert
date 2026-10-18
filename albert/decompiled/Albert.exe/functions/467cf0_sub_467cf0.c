// sub_467cf0 @ 0x467cf0
// hopper name: sub_467cf0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467cf0() {
    var_C = *0x0;
    decomp_var_10 = esi;
    esp = esp - 0x14;
    decomp_var_14 = *dword_4c8db8 ^ &decomp_var_10;
    *0x0 = &var_C;
    esi = arg_0;
    if (esi != 0x0 && *esi == 0x0) {
            eax = sub_46dbce(0x18);
            esp = (esp - 0x4) + 0x4;
            if (eax != 0x0) {
                    esp = esp - 0xc;
                    eax = sub_467a00(0x0, 0x0, 0x0, decomp_var_14, decomp_var_10);
            }
            else {
                    eax = 0x0;
            }
            *esi = eax;
    }
    *0x0 = var_C;
    return 0x2;
}
