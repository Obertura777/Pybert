// sub_48690d @ 0x48690d
// hopper name: sub_48690d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48690d() {
    eax = arg_0;
    if (eax < 0x14) {
            eax = sub_487c06(eax + 0x10);
    }
    else {
            eax = EnterCriticalSection(arg_4 + 0x20);
    }
    return eax;
}
