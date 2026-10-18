// sub_467d70 @ 0x467d70
// hopper name: sub_467d70
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_467d70() {
    var_C = *0x0;
    esp = esp - 0x98;
    decomp_var_98 = *dword_4c8db8 ^ &var_94;
    *0x0 = &var_C;
    eax = arg_0 & 0x17;
    ecx[0x2] = eax;
    ecx = ecx[0x3];
    ecx = ecx & eax;
    if (ecx != 0x0) {
            if (arg_4 != 0x0) {
                    esp = esp - 0x8;
                    sub_47a958(0x0, 0x0);
            }
            if ((ecx & 0x4) != 0x0) {
                    sub_402b30("ios_base::badbit set");
                    eax = sub_467660(&var_6C);
                    ecx = &var_94;
                    esp = esp - 0x10;
                    var_94 = 0x4b1ce0;
                    sub_47a958(ecx, 0x4c1574);
            }
            if ((ecx & 0x2) != 0x0) {
                    sub_402b30("ios_base::failbit set");
                    sub_467660(&var_6C);
                    esp = esp - 0x10;
                    var_94 = 0x4b1ce0;
                    sub_47a958(&var_94, 0x4c1574);
            }
            sub_402b30("ios_base::eofbit set");
            sub_467660(&var_28);
            esp = esp - 0x10;
            var_50 = 0x4b1ce0;
            eax = sub_47a958(&var_50, 0x4c1574);
    }
    *0x0 = var_C;
    return eax;
}
