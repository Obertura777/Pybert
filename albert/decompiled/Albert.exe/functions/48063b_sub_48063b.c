// sub_48063b @ 0x48063b
// hopper name: sub_48063b
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48063b() {
    ecx = arg_4;
    eax = *ecx;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = arg_0;
    eax = eax + esi;
    if (ecx[0x1] >= 0x0) {
            edx = ecx[0x1];
            eax = eax + *(*(edx + esi) + ecx[0x2]) + edx;
    }
    return eax;
}
