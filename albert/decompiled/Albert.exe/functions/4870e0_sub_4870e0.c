// sub_4870e0 @ 0x4870e0
// hopper name: sub_4870e0
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4870e0() {
    eax = 0x1;
    if ((arg_0[0x1] & 0x6) != 0x0) {
            eax = sub_47ad69();
            sub_487050(eax[0x5], eax[0x4], eax[0x3]);
            *arg_c = arg_4;
            eax = 0x3;
    }
    return eax;
}
