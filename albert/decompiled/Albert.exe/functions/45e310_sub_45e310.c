// sub_45e310 @ 0x45e310
// hopper name: sub_45e310
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45e310() {
    var_C = *0x0;
    decomp_var_4c = ebx;
    decomp_var_50 = ebp;
    decomp_var_54 = esi;
    decomp_var_58 = edi;
    decomp_var_5c = *dword_4c8db8 ^ &decomp_var_58;
    *0x0 = &var_C;
    esi = ecx;
    sub_465f30(word_4c7098);
    sub_465870();
    eax = sub_466060(&var_28, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_46b050(&var_28, decomp_var_5c, decomp_var_58);
    if (eax[0x6] >= 0x10) {
            edi = eax[0x1];
    }
    else {
            edi = eax + 0x4;
    }
    eax = sub_45e3c0(decomp_var_5c, decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, var_48, decomp_var_44, decomp_var_40, decomp_var_3c, var_38, decomp_var_34, decomp_var_30, decomp_var_2c, var_28, decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
    return eax;
}
