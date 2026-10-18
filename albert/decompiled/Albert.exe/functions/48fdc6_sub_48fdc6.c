// sub_48fdc6 @ 0x48fdc6
// hopper name: sub_48fdc6
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48fdc6() {
    if (*dword_bc686c == 0x0) {
            if (arg_0 == 0x0) {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = (esp - 0x14) + 0x14;
            }
            else {
                    if (arg_4 != 0x0) {
                            if (arg_8 <= 0x7fffffff) {
                                    sub_492d50(arg_fffffffffffffffc, arg_0, arg_4);
                            }
                            else {
                                    *sub_47d812() = 0x16;
                                    sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                            }
                    }
                    else {
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                    }
            }
    }
    else {
            sub_48fcd6(arg_0, arg_4, arg_8, 0x0);
            esp = (esp - 0x10) + 0x10;
    }
    return;
}
