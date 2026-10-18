// sub_48f282 @ 0x48f282
// hopper name: sub_48f282
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48f282() {
    var_4 = *dword_4c8db8 ^ ebp;
    esp = esp - 0x4;
    decomp_var_14 = esi;
    if (*dword_4c9f78 != 0x0) {
            if (*dword_4ca1bc == 0xfffffffe) {
                    sub_492d04();
            }
            if (*dword_4ca1bc == 0xffffffff) {
                    eax = sub_47ad69();
            }
            else {
                    eax = *dword_4ca1bc;
                    esp = esp - 0x14;
                    eax = WriteConsoleW(eax, &arg_0, 0x1, &var_10, 0x0);
                    if (eax == 0x0) {
                            if (*dword_4c9f78 == 0x2) {
                                    eax = GetLastError();
                                    if (eax == 0x78) {
                                            *dword_4c9f78 = 0x0;
                                            esi = 0x0;
                                            eax = GetConsoleOutputCP();
                                            esp = esp - 0x20;
                                            eax = WideCharToMultiByte(eax, decomp_var_14, var_10, var_C, decomp_var_8, var_4, saved_fp, arg_fffffffffffffffc);
                                            if (*dword_4ca1bc != 0xffffffff) {
                                                    esp = esp - 0x14;
                                                    eax = WriteConsoleA(*dword_4ca1bc, &var_C, eax, &var_10, esi);
                                                    if (eax != 0x0) {
                                                            eax = sub_47ad69();
                                                    }
                                                    else {
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            *dword_4c9f78 = 0x1;
                            eax = sub_47ad69();
                    }
            }
    }
    else {
            eax = GetConsoleOutputCP();
            esp = esp - 0x20;
            eax = WideCharToMultiByte(eax, decomp_var_14, var_10, var_C, decomp_var_8, var_4, saved_fp, arg_fffffffffffffffc);
            if (*dword_4ca1bc != 0xffffffff) {
                    esp = esp - 0x14;
                    eax = WriteConsoleA(*dword_4ca1bc, &var_C, eax, &var_10, 0x0);
                    if (eax != 0x0) {
                            eax = sub_47ad69();
                    }
                    else {
                            eax = sub_47ad69();
                    }
            }
            else {
                    eax = sub_47ad69();
            }
    }
    return eax;
}
