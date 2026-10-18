// sub_4312a0 @ 0x4312a0
// hopper name: sub_4312a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_84a29276878deed2f6f82f4902efd1af3068bd2f0c5f74171e6c8513865ea0d2
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4312a0() {
    decomp_var_c = ebx;
    decomp_var_10 = ebp;
    ebp = arg_0;
    esp = esp - 0x14;
    decomp_var_14 = edi;
    ebx = ecx;
    edi = ebp;
    if (arg_1d == 0x0) {
            esp = esp - 0x4;
            decomp_var_18 = esi;
            do {
                    sub_4312a0(edi[0x2]);
                    ecx = *arg_14;
                    edi = *edi;
                    eax = sub_41aa20(&var_8, &arg_10, ecx, &arg_10, arg_14);
                    sub_47c8f9();
                    *(&arg_10 + 0x4) = 0x0;
                    *(&arg_10 + 0x8) = 0x0;
                    sub_47c8f9();
                    esp = (esp - 0x20) + 0x8;
                    ebp = edi;
            } while (edi[0x21] == 0x0);
            esp = esp + 0x4;
    }
    return;
}
