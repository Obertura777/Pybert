// sub_47bc09 @ 0x47bc09
// hopper name: sub_47bc09
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47bc09() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esi = arg_0;
    esp = esp - 0xc;
    decomp_var_c = edi;
    ebx = ebx | 0xffffffff;
    if (esi == 0x0) {
            *sub_47d812() = 0x16;
            eax = sub_47a924();
            esp = (esp - 0x14) + 0x14;
            eax = eax | 0xffffffff;
    }
    else {
            if ((esi[0xc] & 0x83) != 0x0) {
                    ebx = sub_47c365(esi);
                    sub_4867db(esi);
                    sub_4867ae(esi);
                    esp = (esp - 0x10) + 0x10;
                    if (sub_4866e1() < 0x0) {
                            ebx = ebx | 0xffffffff;
                    }
                    else {
                            eax = esi[0x7];
                            if (eax != 0x0) {
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                                    esi[0x7] = 0x0;
                            }
                    }
            }
            esi[0x3] = 0x0;
            eax = ebx;
    }
    return eax;
}
