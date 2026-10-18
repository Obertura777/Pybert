// sub_45e9f0 @ 0x45e9f0
// hopper name: sub_45e9f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45e9f0() {
    decomp_var_14 = ebx;
    decomp_var_18 = ebp;
    decomp_var_1c = esi;
    decomp_var_20 = edi;
    edi = ecx;
    var_C = 0x0;
    eax = sub_4658f0(&var_10);
    ecx = *(int16_t *)eax;
    ebp = edi[0x4];
    esi = edi + 0xc;
    var_10 = ecx;
    esp = esp - 0x2c;
    eax = sub_4108a0(&var_8, &var_10, decomp_var_20, decomp_var_1c, decomp_var_18);
    ebx = eax;
    eax = *ebx;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (ebx[0x1] != ebp) {
            esp = esp - 0x4;
            sub_45e5b0(&var_10);
            var_C = 0x1;
    }
    eax = (*(*edi + 0x4c))(arg_0, arg_4, var_C);
    return eax;
}
