// sub_465680 @ 0x465680
// hopper name: sub_465680
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465680() {
    var_C = *0x0;
    eax = *dword_4c8db8;
    esp = esp - 0x10;
    decomp_var_10 = eax ^ &var_C;
    *0x0 = &var_C;
    if ((eax ^ &var_C) == 0x0) {
            *dword_bc468c = *dword_bc468c | 0x1;
            sub_464f20();
            sub_47ae90(sub_4aa690);
            esp = (esp - 0x4) + 0x4;
    }
    *0x0 = var_C;
    return 0xbc2138;
}
