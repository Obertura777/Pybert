// sub_4678b0 @ 0x4678b0
// hopper name: sub_4678b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4678b0() {
    var_C = *0x0;
    var_58 = ebx;
    decomp_var_5c = esi;
    decomp_var_60 = *dword_4c8db8 ^ &decomp_var_5c;
    *0x0 = &var_C;
    esi = ecx;
    esp = esp - 0x64;
    decomp_var_64 = 0x0;
    sub_4931ea(0x0);
    esi[0x7] = 0xf;
    esi[0x6] = 0x0;
    esi[0x8] = 0x0;
    esi[0xe] = 0xf;
    esi[0xd] = 0x0;
    esi[0x24] = 0x0;
    esi[0x15] = 0xf;
    esi[0x14] = 0x0;
    esi[0x40] = 0x0;
    esi[0x1c] = 0xf;
    esi[0x1b] = 0x0;
    esi[0x5c] = 0x0;
    ecx = arg_0;
    if (ecx == 0x0) {
            decomp_var_64 = 0xf;
            decomp_var_68 = "bad locale name";
            var_3C = 0x0;
            sub_402650("bad locale name", 0xf);
            sub_467660(&var_58);
            ecx = &var_3C;
            esp = esp - 0x14;
            sub_47a958(ecx, 0x4c1464);
    }
    sub_4934de(esi);
    eax = esi;
    *0x0 = var_14;
    return eax;
}
