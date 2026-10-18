// sub_47a62a @ 0x47a62a
// hopper name: sub_47a62a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47a62a() {
    eax = arg_c;
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    if (eax != 0x0) {
            if (arg_0 == 0x0) {
                    esp = (esp - 0x4) + 0x4;
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = (esp - 0x14) + 0x14;
                    eax = 0x16;
            }
            else {
                    if (arg_8 != 0x0) {
                            if (arg_4 < eax) {
                                    esp = (esp - 0x4) + 0x4;
                                    *sub_47d812() = 0x22;
                                    sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    eax = 0x22;
                            }
                            else {
                                    sub_47f9a0(arg_0, arg_8, eax);
                                    esp = (esp - 0xc) + 0xc;
                                    eax = 0x0;
                            }
                    }
                    else {
                            esp = (esp - 0x4) + 0x4;
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = 0x16;
                    }
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
