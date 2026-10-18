// sub_481ca8 @ 0x481ca8
// hopper name: sub_481ca8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_481ca8() {
    if (edi != 0x0 && eax != 0x0) {
            esp = esp - 0x4;
            decomp_var_4 = esi;
            esi = *eax;
            if (esi != edi) {
                    *eax = edi;
                    sub_481b72(edi);
                    esp = (esp - 0x4) + 0x4;
                    if (esi != 0x0) {
                            sub_481bf8(esi);
                            esp = (esp - 0x4) + 0x4;
                            if (*esi == 0x0) {
                                    if (esi != 0x4c9520) {
                                            sub_481a32(esi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                            }
                    }
            }
            eax = edi;
    }
    else {
            eax = 0x0;
    }
    return eax;
}
