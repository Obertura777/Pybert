// sub_480ae1 @ 0x480ae1
// hopper name: sub_480ae1
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_480ae1() {
    if (arg_10 != 0x0) {
            sub_480a50();
            esp = (esp - 0x10) + 0x10;
    }
    esp = esp - 0x4;
    decomp_var_4 = arg_0;
    if (arg_18 == 0x0) {
            esp = esp - 0x4;
            decomp_var_8 = esi;
    }
    else {
            esp = esp - 0x4;
            decomp_var_8 = arg_18;
    }
    sub_47a9d9(decomp_var_8, decomp_var_4);
    decomp_var_8 = arg_c;
    sub_4804c1();
    esi[0x2] = edi[0x1] + 0x1;
    eax = sub_480735();
    esp = (esp - 0x28) + 0x28;
    if (eax != 0x0) {
            esp = esp - 0x8;
            decomp_var_8 = eax;
            eax = sub_47a9a2(decomp_var_8, esi);
    }
    return eax;
}
