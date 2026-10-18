// sub_47183d @ 0x47183d
// hopper name: sub_47183d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47183d() {
    if (sub_471691() != 0x0) {
            (*dword_bc5f30)(arg_0, arg_4);
    }
    else {
            esp = esp - 0x8;
            decomp_var_18 = esi;
            if (arg_0 == 0x12340042) {
                    ebx = arg_4;
                    if (ebx != 0x0 && *ebx >= 0x28) {
                            esp = esp - 0x10;
                            eax = SystemParametersInfoA(0x30, 0x0, &var_10, 0x0);
                            bool_9 = true;
                            bool_8 = true;
                            bool_7 = true;
                            bool_6 = true;
                            if (eax != 0x0) {
                                    ebx[0x1] = 0x0;
                                    ebx[0x2] = 0x0;
                                    ebx[0x3] = GetSystemMetrics(0x0);
                                    eax = GetSystemMetrics(0x1);
                                    ebx[0x5] = var_10;
                                    ebx[0x5] = var_10;
                                    ebx[0x5] = var_10;
                                    ebx[0x5] = var_10;
                                    bool_5 = *ebx < 0x48;
                                    ebx[0x4] = eax;
                                    ebx[0x9] = 0x1;
                                    esp = (esp - 0xc) + 0x4;
                                    if (!bool_5) {
                                            sub_47f4a4(ebx + 0x28, 0x20, "DISPLAY", 0x1f);
                                            esp = (esp - 0x10) + 0x10;
                                    }
                            }
                    }
            }
    }
    return;
}
