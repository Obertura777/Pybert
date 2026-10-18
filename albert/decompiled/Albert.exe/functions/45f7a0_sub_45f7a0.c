// sub_45f7a0 @ 0x45f7a0
// hopper name: sub_45f7a0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45f7a0() {
    var_4 = 0xffffffff;
    var_C = *0x0;
    var_2C = esi;
    var_30 = edi;
    esp = esp - 0x34;
    decomp_var_34 = *dword_4c8db8 ^ &var_30;
    *0x0 = &var_C;
    edi = ecx;
    if (edi[0x60] != 0x0) {
            ecx = edi[0x19];
            eax = ecx;
            var_14 = 0x0;
            esi = eax + 0x1;
            do {
                    edx = *(int8_t *)eax;
                    eax = eax + 0x1;
            } while (edx != 0x0);
            decomp_var_38 = eax - esi;
            decomp_var_3c = ecx;
            sub_402650(decomp_var_3c, decomp_var_38);
            esp = esp - 0xc;
            sub_46db50() + 0xc;
            *(int16_t *)var_4 = *(int16_t *)sub_45f570(decomp_var_40);
            if (var_18 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            *saved_fp = edi[0x1a];
    }
    eax = edi[0x60];
    *0x0 = var_14;
    return eax;
}
