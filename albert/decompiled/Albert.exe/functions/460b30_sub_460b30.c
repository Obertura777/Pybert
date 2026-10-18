// sub_460b30 @ 0x460b30
// hopper name: sub_460b30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_460b30() {
    decomp_var_14 = ebx;
    decomp_var_18 = ebp;
    decomp_var_1c = esi;
    decomp_var_20 = edi;
    esp = esp - 0x28;
    eax = sub_4602f0(&var_10, arg_0 + 0x4, decomp_var_20, decomp_var_1c, decomp_var_18);
    ebp = *eax;
    ebx = eax[0x1];
    edi = *arg_0;
    eax = ecx + (edi + edi * 0x8) * 0x4 + 0x8;
    esi = eax[0x1];
    if (ebp == 0x0 || ebp != eax) {
            sub_47a948();
    }
    if (ebx != esi) {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (ebx == arg_0) {
                    sub_47a948();
            }
            edi = ebx[0x5];
            esi = ebx + 0x10;
            if (ebx == arg_0) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_460ac0(&var_8, &arg_4, decomp_var_20);
            ebx = eax;
            eax = *ebx;
            if (eax == 0x0 || eax != esi) {
                    sub_47a948();
            }
            if (ebx[0x1] != edi) {
                    eax = 0x1;
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
