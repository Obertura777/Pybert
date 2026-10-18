// sub_47d8df @ 0x47d8df
// hopper name: sub_47d8df
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47d8df() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = arg_0;
    eax = 0x0;
    while (esi < arg_4) {
            if (eax != 0x0) {
                    break;
            }
            ecx = *esi;
            if (ecx != 0x0) {
                    eax = (ecx)();
            }
            esi = esi + 0x4;
    }
    return;
}
