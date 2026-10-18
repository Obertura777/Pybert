// sub_47d8ff @ 0x47d8ff
// hopper name: sub_47d8ff
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47d8ff() {
    ecx = arg_0;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    if (ecx == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            eax = 0x16;
    }
    else {
            if (*dword_bc64bc != 0x0) {
                    *ecx = *dword_bc64bc;
                    eax = 0x0;
            }
            else {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    eax = 0x16;
            }
    }
    return eax;
}
