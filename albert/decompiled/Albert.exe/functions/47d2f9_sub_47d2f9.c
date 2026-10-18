// sub_47d2f9 @ 0x47d2f9
// hopper name: sub_47d2f9
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47d2f9() {
    ecx = *(sub_480086() + 0x6c);
    bool_1 = ecx != *dword_4c95f8;
    if (ecx != *dword_4c95f8 && !bool_1) {
            sub_481ce6();
    }
    return *dword_4c8e14;
}
