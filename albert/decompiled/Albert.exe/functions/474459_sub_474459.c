// sub_474459 @ 0x474459
// hopper name: sub_474459
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_474459() {
    decomp_var_4 = 0x54;
    sub_47d6bb(0x54);
    esp = esp - 0x8;
    eax = sub_473a7a();
    if (eax != 0x0) {
            edi = arg_4;
            esi = eax + 0x1c;
            esp = esp - 0x4;
            eax = sub_4791ea();
            if (eax == 0x0) {
                    esp = esp - 0x8;
                    GetParent(edi);
                    eax = sub_4791ea();
                    if (eax != 0x0) {
                            eax = eax[0x13];
                            if (eax != 0x0) {
                                    esp = esp - 0x4;
                                    esi = sub_4791ea();
                                    if (esi != 0x0) {
                                            sub_471f02(edi);
                                            sub_473e92() != 0x0 ? 0x1 : 0x0;
                                            sub_474239();
                                    }
                            }
                    }
            }
            else {
                    sub_473e92();
            }
    }
    eax = sub_47d75a();
    return eax;
}
