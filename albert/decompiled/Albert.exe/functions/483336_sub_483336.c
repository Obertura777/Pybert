// sub_483336 @ 0x483336
// hopper name: sub_483336
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_483336() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = eax;
    if (edi != 0x0) {
            sub_47f9a0(esi + edi, esi, sub_47d630(esi) + 0x1);
            esp = (esp - 0x10) + 0x10;
    }
    return;
}
