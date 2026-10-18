// sub_45d550 @ 0x45d550
// hopper name: sub_45d550
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45d550() {
    var_C = *0x0;
    var_30 = esi;
    decomp_var_34 = edi;
    eax = *dword_4c8db8;
    *0x0 = &var_C;
    esi = arg_0;
    var_2C = 0x27;
    eax = sub_45b890(&var_2C, 0x0, 0x1, eax ^ &decomp_var_34, decomp_var_34, var_30);
    decomp_var_3c = 0x1;
    decomp_var_40 = 0xffffffff;
    esp = esp - 0x50;
    decomp_var_44 = &arg_0;
    edi = eax;
    eax = sub_45b950(decomp_var_44, 0xffffffff, 0x1, decomp_var_38, decomp_var_34, var_30);
    if (eax > edi) {
            eax = sub_45d370(&var_28, edi + 0x1, eax - edi - 0x1);
            decomp_var_3c = 0xffffffff;
            decomp_var_40 = 0x0;
            esp = esp - 0x18;
            decomp_var_44 = eax;
            eax = sub_4024f0(decomp_var_44, 0x0, 0xffffffff);
            if (var_1C >= 0x10) {
                    eax = sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
    }
    *0x0 = var_18;
    return eax;
}
