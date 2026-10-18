// sub_46db50 @ 0x46db50
// hopper name: sub_46db50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46db50() {
    var_C = *0x0;
    eax = *dword_4c8db8;
    esp = esp - 0x10;
    decomp_var_10 = eax ^ &var_C;
    *0x0 = &var_C;
    if ((eax ^ &var_C) == 0x0) {
            *dword_bc46c0 = *dword_bc46c0 | 0x1;
            sub_46bfd0();
            sub_47ae90(sub_4ac1c0);
            esp = (esp - 0x4) + 0x4;
    }
    *0x0 = var_C;
    return 0xbc46a8;
}
