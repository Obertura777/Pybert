// sub_45d4b0 @ 0x45d4b0
// hopper name: sub_45d4b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45d4b0() {
    decomp_var_8 = ebx;
    var_C = ebp;
    decomp_var_10 = esi;
    esp = esp - 0x14;
    decomp_var_14 = edi;
    edi = arg_4;
    if (edi != 0x0) {
            ebx = sub_46db50();
            sub_46be00();
            if (edi > 0x0) {
                    esi = arg_0 + 0x2;
                    edi = (HIDWORD(0xaaaaaaab * (edi - 0x1)) >> 0x2) + 0x1;
                    do {
                            esp = esp - 0x1c;
                            var_4 = *(int8_t *)(esi - 0x2);
                            eax = esi;
                            decomp_var_18 = 0xf;
                            decomp_var_1c = 0x0;
                            decomp_var_2c = 0x0;
                            ebp = eax + 0x1;
                            do {
                                    edx = *(int8_t *)eax;
                                    eax = eax + 0x1;
                            } while (edx != 0x0);
                            sub_402650(esi, eax - ebp);
                            esp = esp - 0xc;
                            eax = sub_46bed0(&var_C, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c, decomp_var_28, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, decomp_var_8, var_4, saved_fp);
                            esi = esi + 0x6;
                            edi = edi - 0x1;
                    } while (edi != 0x0);
            }
    }
    return;
}
