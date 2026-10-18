// sub_47d60b @ 0x47d60b
// hopper name: sub_47d60b
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47d60b() {
    eax = arg_0;
    do {
            ecx = *(int16_t *)eax;
            eax = eax + 0x2;
    } while (ecx != 0x0);
    eax = (SAR(eax - arg_0, 0x1)) - 0x1;
    return eax;
}
