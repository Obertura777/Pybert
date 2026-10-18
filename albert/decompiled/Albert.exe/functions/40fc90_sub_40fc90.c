// sub_40fc90 @ 0x40fc90
// hopper name: sub_40fc90
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40fc90() {
    eax = sub_46dbce(0xc0);
    esp = (esp - 0x4) + 0x4;
    bool_1 = true;
    if (eax != 0x0) {
            *eax = arg_0;
            eax[0x2] = arg_8;
            eax[0x1] = arg_4;
            eax[0x3] = *arg_c;
            eax[0x8] = arg_c[0x2];
            eax[0x5] = arg_c[0x2];
            eax[0xbc] = arg_10;
            eax[0xbd] = 0x0;
    }
    return;
}
