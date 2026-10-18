// sub_483c86 @ 0x483c86
// hopper name: sub_483c86
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_483c86() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = 0x0;
    do {
            esi = edi + dword_4c9610;
            edi = edi + 0x4;
            esp = (esp - 0x4) + 0x4;
            *esi = sub_47fe10(*esi);
    } while (edi < 0x28);
    return;
}
