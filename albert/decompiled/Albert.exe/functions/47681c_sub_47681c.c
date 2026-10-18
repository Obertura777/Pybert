// sub_47681c @ 0x47681c
// hopper name: sub_47681c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47681c() {
    if (ecx[0x14] == 0x0) {
            eax = arg_0;
            if (eax != 0x0) {
                    eax = eax[0x8];
            }
            eax = SetWindowPos(ecx[0x8], eax, arg_4, arg_8, arg_c, arg_10, arg_14);
    }
    else {
            eax = *ecx[0x14];
            eax = (eax[0x27])();
    }
    return eax;
}
