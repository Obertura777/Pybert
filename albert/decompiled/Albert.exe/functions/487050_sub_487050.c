// sub_487050 @ 0x487050
// hopper name: sub_487050
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_487050() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    decomp_var_c = edi;
    esp = esp - 0x28;
    decomp_var_28 = *0x0;
    *0x0 = &decomp_var_28;
    while (true) {
            eax = arg_4;
            ebx = eax[0x2];
            ebx = ebx ^ *arg_0;
            esi = eax[0x3];
            if (esi == 0xfffffffe) {
                    break;
            }
            edx = arg_8;
            if (edx == 0xfffffffe) {
                    ebx = ebx + (esi + esi * 0x2) * 0x4 + 0x10;
                    eax[0x3] = *ebx;
                    if (ebx[0x1] == 0x0) {
                            esp = esp - 0x4;
                            sub_48aa45(0x101);
                            sub_48aa64();
                    }
                    continue;
            }
            if (esi <= edx) {
                    break;
            }
            ebx = ebx + (esi + esi * 0x2) * 0x4 + 0x10;
            eax[0x3] = *ebx;
            if (ebx[0x1] == 0x0) {
                    esp = esp - 0x4;
                    sub_48aa45(0x101);
                    sub_48aa64();
            }
    }
    *0x0 = decomp_var_28;
    return eax;
}
