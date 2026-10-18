// sub_476048 @ 0x476048
// hopper name: sub_476048
// referenced by: called,pointer
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_476048() {
    if (ecx[0x14] != 0x0) {
            eax = SendMessageA(ecx[0x8], arg_0 + 0x2000, arg_4, arg_8);
            esp = (esp - 0x14) + 0x4;
            if (arg_0 <= 0x138) {
                    if (eax != 0x0) {
                            ecx = arg_c;
                            if (ecx != 0x0) {
                                    *ecx = eax;
                            }
                    }
            }
            else {
                    ecx = arg_c;
                    if (ecx != 0x0) {
                            *ecx = eax;
                    }
            }
    }
    else {
            sub_475ce6(arg_fffffffffffffffc, arg_0, arg_4, arg_8);
    }
    return;
}
