// sub_460f60 @ 0x460f60
// hopper name: sub_460f60
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_460f60() {
    decomp_var_1c = ebx;
    decomp_var_20 = ebp;
    ebp = arg_0;
    decomp_var_24 = esi;
    ebx = ecx;
    decomp_var_28 = edi;
    esi = ebx + 0x2474;
    esp = esp - 0x2c;
    var_18 = ebp;
    eax = sub_40ef70(&var_18);
    edi = eax;
    if (esi == 0x0) {
            sub_47a948();
    }
    var_14 = esi[0x1];
    if (esi == 0x0 || esi != esi) {
            sub_47a948();
    }
    if (edi != var_14) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi[0x3] == ebp) {
                    esp = esp - 0xc;
                    sub_4048e0(&var_18, esi, edi, decomp_var_28, decomp_var_24, decomp_var_20, decomp_var_1c, var_18, var_14, var_10, var_C, decomp_var_8, decomp_var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
            }
    }
    var_18 = ebp;
    eax = sub_404ef0(&var_C, &var_18);
    ebx[0x2488] = 0x1;
    return eax;
}
