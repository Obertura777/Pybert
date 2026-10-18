// sub_468be0 @ 0x468be0
// hopper name: sub_468be0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_468be0() {
    var_C = *0x0;
    var_10 = *dword_4c8db8 ^ &var_88;
    decomp_var_8c = esi;
    decomp_var_90 = *dword_4c8db8 ^ &decomp_var_8c;
    *0x0 = &var_C;
    esi = ecx;
    var_88 = esi;
    esi[0x1] = arg_0;
    *esi = 0x4b1dbc;
    sub_4678b0(0x4b1d28);
    esp = esp - 0x98;
    sub_4687d0();
    if (esi[0xd] == 0x0) {
            sub_49317e();
            esi[0xd] = 0x2c;
    }
    sub_467490();
    *0x0 = var_C;
    eax = sub_47ad69();
    return eax;
}
