// sub_492242 @ 0x492242
// hopper name: sub_492242
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_492242() {
    eax = arg_0;
    bool_1 = eax <= 0x1;
    if (eax != 0x1) {
            if (!bool_1 && eax <= 0x3) {
                    eax = sub_47d812();
                    *eax = 0x22;
            }
    }
    else {
            eax = sub_47d812();
            *eax = 0x21;
    }
    return eax;
}
