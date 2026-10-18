// sub_4783a2 @ 0x4783a2
// hopper name: sub_4783a2
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4783a2() {
    ebx = sub_4715ed();
    eax = ebx[0x4];
    if (eax != 0x0) {
            ebx[0x4] = eax - 0x1;
            if (eax == 0x1) {
                    esi = 0x0;
                    if (arg_0 != 0x0) {
                            if (arg_0 != 0xffffffff) {
                                    eax = sub_46f313();
                                    if (eax != esi) {
                                            eax = eax[0xf];
                                            if (eax != esi) {
                                                    esp = esp - 0x8;
                                                    (eax)(esi, esi);
                                            }
                                    }
                            }
                            sub_4782d6();
                            sub_4782d6();
                            sub_4782d6();
                            sub_4782d6();
                            sub_4782d6();
                    }
                    esp = esp - 0x4;
                    decomp_var_c = edi;
                    edi = *(sub_4715ba(decomp_var_c) + 0x4);
                    esi = sub_47759a();
                    if (esi != 0x0) {
                            if (edi != 0x0) {
                                    eax = esi[0x3];
                                    if (eax != 0x0) {
                                            esp = (esp - 0x4) + 0x4;
                                            if (sub_47f73f() < edi[0x26]) {
                                                    if (edi[0x26] != 0x0) {
                                                            eax = esi[0x3];
                                                            arg_0 = arg_0 & 0x0;
                                                            if (eax != 0x0) {
                                                                    arg_0 = sub_47f73f();
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x8) + 0x8;
                                                            }
                                                            eax = sub_47c836();
                                                            esp = (esp - 0x4) + 0x4;
                                                            esi[0x3] = eax;
                                                            if (eax == 0x0) {
                                                                    if (arg_0 != eax) {
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            esi[0x3] = sub_47c836();
                                                                    }
                                                            }
                                                    }
                                                    esp = esp + 0x4;
                                                    eax = ebx[0x4] != 0x0 ? 0x1 : 0x0;
                                            }
                                            else {
                                                    esp = esp + 0x4;
                                                    eax = ebx[0x4] != 0x0 ? 0x1 : 0x0;
                                            }
                                    }
                                    else {
                                            if (edi[0x26] != 0x0) {
                                                    eax = esi[0x3];
                                                    arg_0 = arg_0 & 0x0;
                                                    if (eax != 0x0) {
                                                            arg_0 = sub_47f73f();
                                                            sub_47c8f9();
                                                            esp = (esp - 0x8) + 0x8;
                                                    }
                                                    eax = sub_47c836();
                                                    esp = (esp - 0x4) + 0x4;
                                                    esi[0x3] = eax;
                                                    if (eax == 0x0) {
                                                            if (arg_0 != eax) {
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    esi[0x3] = sub_47c836();
                                                            }
                                                    }
                                            }
                                            esp = esp + 0x4;
                                            eax = ebx[0x4] != 0x0 ? 0x1 : 0x0;
                                    }
                            }
                            else {
                                    esp = esp + 0x4;
                                    eax = ebx[0x4] != 0x0 ? 0x1 : 0x0;
                            }
                    }
                    else {
                            esp = esp + 0x4;
                            eax = ebx[0x4] != 0x0 ? 0x1 : 0x0;
                    }
            }
            else {
                    eax = ebx[0x4] != 0x0 ? 0x1 : 0x0;
            }
    }
    else {
            eax = ebx[0x4] != 0x0 ? 0x1 : 0x0;
    }
    return eax;
}
