// sub_474a6e @ 0x474a6e
// hopper name: sub_474a6e
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_474a6e() {
    eax = arg_0;
    if (eax[0x2] == 0x0) {
            eax = 0x80010108;
    }
    else {
            eax = eax[0x2];
            esp = esp - 0x18;
            eax = (*(*eax + 0x14))(eax, arg_4, arg_8, arg_c, arg_10, arg_14);
    }
    return eax;
}
