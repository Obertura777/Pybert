// sub_47b6f8 @ 0x47b6f8
// hopper name: sub_47b6f8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47b6f8() {
    sub_47f31c(0x4c3360, 0xc);
    esi = arg_8;
    arg_4 = arg_4 + esi * arg_c;
    while (true) {
            arg_c = arg_c - 0x1;
            if (arg_c < 0x0) {
                    break;
            }
            arg_4 = arg_4 - esi;
            (arg_10)();
    }
    sub_47b743();
    sub_47f361();
    return;
}
