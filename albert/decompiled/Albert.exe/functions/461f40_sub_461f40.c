// sub_461f40 @ 0x461f40
// hopper name: sub_461f40
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_461f40() {
    decomp_var_c = ebx;
    decomp_var_10 = ebp;
    ebp = arg_0;
    esp = esp - 0x14;
    decomp_var_14 = edi;
    ebx = ecx;
    edi = ebp;
    if (arg_25 == 0x0) {
            esp = esp - 0x4;
            decomp_var_18 = esi;
            do {
                    sub_461f40(edi[0x2]);
                    ecx = *arg_10;
                    edi = *edi;
                    eax = sub_4053f0(&var_8, &arg_c, ecx, &arg_c, arg_10);
                    sub_47c8f9();
                    *(&arg_c + 0x4) = 0x0;
                    *(&arg_c + 0x8) = 0x0;
                    sub_47c8f9();
                    esp = (esp - 0x20) + 0x8;
                    ebp = edi;
            } while (edi[0x29] == 0x0);
            esp = esp + 0x4;
    }
    return;
}
