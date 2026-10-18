// sub_461010 @ 0x461010
// hopper name: sub_461010
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_461010() {
    decomp_var_1c = ebx;
    decomp_var_20 = ebp;
    decomp_var_24 = esi;
    decomp_var_28 = edi;
    esi = &arg_244c;
    esp = esp - 0x30;
    eax = sub_402060(&var_C, &arg_0, decomp_var_28, decomp_var_24, decomp_var_20);
    edi = *eax;
    edx = esi[0x1];
    ebx = eax[0x1];
    var_14 = edx;
    if (edi == 0x0 || edi != esi) {
            sub_47a948();
    }
    if (ebx == var_14) {
            eax = 0x0;
    }
    else {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            var_18 = ebx[0x4];
            sub_404ef0(&var_C, &var_18);
            eax = 0x1;
    }
    return eax;
}
