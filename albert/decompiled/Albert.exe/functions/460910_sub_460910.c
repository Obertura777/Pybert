// sub_460910 @ 0x460910
// hopper name: sub_460910
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_460910() {
    decomp_var_c = ebx;
    decomp_var_10 = ebp;
    decomp_var_14 = esi;
    decomp_var_18 = edi;
    esi = ecx + 0x245c;
    esp = esp - 0x20;
    eax = sub_402060(&var_8, &arg_0, decomp_var_18, decomp_var_14, decomp_var_10);
    edi = *eax;
    ebp = eax[0x1];
    ebx = esi[0x1];
    if (edi == 0x0 || edi != esi) {
            sub_47a948();
    }
    if (ebp == ebx) {
            eax = 0x0;
    }
    else {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (ebp == edi[0x1]) {
                    sub_47a948();
            }
            eax = 0x1;
    }
    return eax;
}
