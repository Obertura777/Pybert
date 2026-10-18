// sub_474019 @ 0x474019
// hopper name: sub_474019
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_474019() {
    esp = esp - 0x4;
    edi = 0x0;
    sub_4715ba(&var_4);
    if (*sub_47391c() != 0x0) {
            esp = esp - 0x4;
            if (sub_4739f1(arg_0) != 0x0) {
                    edi = arg_4;
            }
    }
    else {
            if ((arg_4 & 0x3fc0) == arg_4) {
                    **(sub_4715ba() + 0x78);
                    sub_4738a8();
                    edi = 0x3fc0;
            }
    }
    eax = edi;
    return eax;
}
