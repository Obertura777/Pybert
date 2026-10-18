// sub_460d20 @ 0x460d20
// hopper name: sub_460d20
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_460d20() {
    var_C = *0x0;
    var_30 = ebx;
    var_34 = esi;
    eax = *dword_4c8db8;
    *0x0 = &var_C;
    esp = esp - 0x44;
    var_2C = 0x0;
    sub_4024f0(arg_4, 0x0, 0xffffffff, eax ^ &var_34, var_34, var_30, 0x0);
    edx = saved_fp;
    eax = edx;
    var_10 = 0x0;
    esi = eax + 0x1;
    &var_44 = &var_44;
    do {
            ecx = *(int8_t *)eax;
            eax = eax + 0x1;
    } while (ecx != 0x0);
    eax = sub_460580();
    esi = var_10;
    decomp_var_50 = 0xffffffff;
    decomp_var_54 = 0x0;
    esi[0x6] = 0xf;
    esi[0x5] = 0x0;
    esp = esp - 0x14;
    decomp_var_58 = eax;
    esi[0x4] = 0x0;
    sub_4024f0(decomp_var_58, 0x0, 0xffffffff);
    if (var_30 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    eax = esi;
    *0x0 = var_2C;
    return eax;
}
