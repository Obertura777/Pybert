// sub_47c365 @ 0x47c365
// hopper name: sub_47c365
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47c365() {
    decomp_var_4 = ebx;
    esp = esp - 0x8;
    decomp_var_8 = esi;
    esi = arg_0;
    eax = esi[0x3];
    ebx = 0x0;
    if ((eax & 0x3) == 0x2 && (eax & 0x108) != 0x0) {
            eax = esi[0x2];
            esp = esp - 0x4;
            decomp_var_c = edi;
            edi = *esi;
            edi = edi - eax;
            if (edi > 0x0) {
                    sub_4867ae(esi);
                    esp = ((esp - 0xc) + 0x4 - 0x4) + 0xc;
                    if (sub_4878d3() == edi) {
                            eax = esi[0x3];
                            if (eax < 0x0) {
                                    esi[0x3] = eax & 0xfffffffd;
                            }
                    }
                    else {
                            esi[0x3] = esi[0x3] | 0x20;
                            ebx = 0xffffffff;
                    }
            }
            esp = esp + 0x4;
    }
    eax = esi[0x2];
    esi[0x1] = esi[0x1] & 0x0;
    *esi = eax;
    eax = ebx;
    return eax;
}
