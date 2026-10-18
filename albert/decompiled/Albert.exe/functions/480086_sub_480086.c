// sub_480086 @ 0x480086
// hopper name: sub_480086
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_480086() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = sub_480003();
    if (esi == 0x0) {
            sub_47d856(0x10);
            esp = (esp - 0x4) + 0x4;
    }
    eax = esi;
    return eax;
}
