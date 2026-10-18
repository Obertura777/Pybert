// sub_476b55 @ 0x476b55
// hopper name: sub_476b55
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_476b55() {
    eax = TabbedTextOutA(ecx[0x1], arg_4, arg_8, arg_c, arg_10, arg_14, arg_18, arg_1c);
    arg_0[0x1] = sign_extend_32(eax >> 0x10);
    *arg_0 = sign_extend_32(eax);
    eax = arg_0;
    return eax;
}
