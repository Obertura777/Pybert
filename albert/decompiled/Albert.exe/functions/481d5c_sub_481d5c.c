// sub_481d5c @ 0x481d5c
// hopper name: sub_481d5c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_481d5c() {
    eax = *dword_4c95f8;
    *dword_bc6888 = eax[0x1];
    *dword_bc688c = eax[0x2];
    *dword_4c95fc = eax[0x2a];
    *dword_4c9de0 = eax[0x35];
    *dword_4c8e14 = eax[0x2f];
    *dword_4c9d20 = eax[0x32];
    eax = eax[0x2b];
    *dword_4c9de4 = eax;
    return eax;
}
