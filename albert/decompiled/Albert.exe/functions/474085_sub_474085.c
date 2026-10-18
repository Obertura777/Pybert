// sub_474085 @ 0x474085
// hopper name: sub_474085
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_474085() {
    if ((arg_8 & 0x10000000) == 0x0) {
            esp = esp - 0x4;
            decomp_var_14 = esi;
            esi = arg_0;
            if ((sub_476745() & 0x50000000) == 0x0) {
                    esp = esp - 0x8;
                    GetWindowRect(esi[0x8], &var_10);
                    eax = arg_4;
                    if (*eax == var_10 && eax[0x1] == var_C) {
                            eax = GetWindow(esi[0x8], 0x4);
                            esp = esp - 0xc;
                            eax = sub_473aee(eax);
                            if (eax != 0x0) {
                                    if (sub_47679a() == 0x0) {
                                            if ((*(*esi + 0x11c))() != 0x0) {
                                                    esp = esp - 0x4;
                                                    sub_4734c2(0x0);
                                            }
                                    }
                            }
                            else {
                                    if ((*(*esi + 0x11c))() != 0x0) {
                                            esp = esp - 0x4;
                                            sub_4734c2(0x0);
                                    }
                            }
                    }
            }
    }
    return;
}
