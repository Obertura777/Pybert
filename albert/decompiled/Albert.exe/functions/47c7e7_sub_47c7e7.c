// sub_47c7e7 @ 0x47c7e7
// hopper name: sub_47c7e7
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47c7e7() {
    decomp_var_4 = 0xc;
    esp = esp - 0x8;
    sub_47f31c(0x4c3468, 0xc);
    decomp_var_1c = decomp_var_1c & 0x0;
    esi = arg_4;
    if (esi <= *dword_bc7218) {
            sub_487c06(0x4);
            decomp_var_1c = sub_48854d(esi);
            sub_47c82d();
    }
    eax = sub_47f361();
    return eax;
}
