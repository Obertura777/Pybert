// sub_48fc86 @ 0x48fc86
// hopper name: sub_48fc86
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48fc86() {
    if (*dword_bc686c == 0x0) {
            if (arg_0 == 0x0) {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    loc_48fcd3();
            }
            else {
                    if (arg_4 != 0x0) {
                            sub_48fb7e(arg_fffffffffffffffc, arg_0);
                    }
                    else {
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            loc_48fcd3();
                    }
            }
    }
    else {
            sub_48fbb3(arg_fffffffffffffffc, arg_0, arg_4);
    }
    return;
}
