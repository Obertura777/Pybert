// sub_4717d2 @ 0x4717d2
// hopper name: sub_4717d2
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4717d2() {
    if (sub_471691() != 0x0) {
            (*dword_bc5f24)(arg_0, arg_4);
    }
    else {
            if ((arg_4 & 0x3) == 0x0) {
                    esp = esp - 0x4;
                    if (IsIconic(arg_0) != 0x0) {
                            esp = esp - 0x8;
                            eax = GetWindowPlacement(arg_0, &var_2C);
                    }
                    else {
                            esp = esp - 0x8;
                            eax = GetWindowRect(arg_0, &var_10);
                    }
                    if (eax != 0x0) {
                            sub_471786(&var_10, arg_4);
                    }
            }
    }
    return;
}
