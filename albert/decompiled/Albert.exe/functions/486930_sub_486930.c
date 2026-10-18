// sub_486930 @ 0x486930
// hopper name: sub_486930
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_486930() {
    eax = arg_0;
    if (eax >= 0x4c96d8 && eax <= 0x4c9938) {
            eax = sub_487b2e((SAR(eax - 0x4c96d8, 0x5)) + 0x10);
    }
    else {
            eax = LeaveCriticalSection(eax + 0x20);
    }
    return eax;
}
