// sub_45fa10 @ 0x45fa10
// hopper name: sub_45fa10
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45fa10() {
    esp = esp - 0x1c;
    if (*(int8_t *)byte_bc2130 != 0x0) {
            if (*dword_bc212c == 0x0) {
                    eax = sub_47bf0b("tcpiplog.txt", 0x4b0b1c);
                    esp = (esp - 0x8) + 0x8;
                    *dword_bc212c = eax;
                    if (eax != 0x0) {
                            if (arg_0 != 0x0) {
                                    esp = esp - 0x4;
                            }
                            else {
                                    esp = esp - 0x4;
                            }
                            sub_47bcf8();
                            esp = (esp - 0x4) + 0x8 - 0x4;
                            eax = sub_46b050(&var_1C, var_1C, var_18);
                            if (eax[0x6] >= 0x10) {
                                    eax = eax[0x1];
                            }
                            else {
                                    eax = eax + 0x4;
                            }
                            sub_47bcf8();
                            esp = (esp - 0xc) + 0xc;
                            if (var_4 >= 0x10) {
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                            sub_47c4e3();
                            esp = (esp - 0x4) + 0x4;
                    }
            }
            else {
                    if (arg_0 != 0x0) {
                            esp = esp - 0x4;
                    }
                    else {
                            esp = esp - 0x4;
                    }
                    sub_47bcf8();
                    esp = (esp - 0x4) + 0x8 - 0x4;
                    eax = sub_46b050(&var_1C, var_1C, var_18);
                    if (eax[0x6] >= 0x10) {
                            eax = eax[0x1];
                    }
                    else {
                            eax = eax + 0x4;
                    }
                    sub_47bcf8();
                    esp = (esp - 0xc) + 0xc;
                    if (var_4 >= 0x10) {
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                    }
                    sub_47c4e3();
                    esp = (esp - 0x4) + 0x4;
            }
    }
    return;
}
