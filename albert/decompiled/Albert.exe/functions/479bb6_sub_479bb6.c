// sub_479bb6 @ 0x479bb6
// hopper name: sub_479bb6
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479bb6() {
    edi = arg_4;
    esi = ecx;
    if (edi < 0x0) {
            sub_46dedc();
    }
    eax = arg_8;
    if (eax >= 0x0) {
            esi[0x4] = eax;
    }
    ebx = 0x0;
    if (edi == 0x0) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
            esi[0x3] = ebx;
            esi[0x2] = ebx;
            esi[0x1] = ebx;
    }
    else {
            ebx = 0x0;
            ecx = esi[0x1];
            if (ecx == 0x0) {
                    if (edi > 0xffffffff) {
                            sub_46dedc();
                    }
                    eax = sub_46dbce(edi);
                    esi[0x1] = eax;
                    sub_47ba40(eax, ebx, edi);
                    esp = (esp - 0x10) + 0x10;
                    esi[0x3] = edi;
                    esi[0x2] = edi;
            }
            else {
                    ebx = esi[0x3];
                    if (edi <= ebx) {
                            eax = esi[0x2];
                            if (edi > eax) {
                                    sub_47ba40(eax + ecx, 0x0, edi - eax);
                                    esp = (esp - 0xc) + 0xc;
                            }
                            esi[0x2] = edi;
                    }
                    else {
                            eax = esi[0x4];
                            if (eax == 0x0) {
                                    eax = esi[0x2];
                                    eax = SAR(eax + ((eax & 0x80000000 ? 0xffffffff : 0x0) & 0x7), 0x3);
                                    if (eax >= 0x4) {
                                            if (eax > 0x400) {
                                                    eax = 0x400;
                                            }
                                            else {
                                                    if (eax < 0x4) {
                                                            eax = 0x4;
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                            }
                                    }
                                    else {
                                            eax = 0x4;
                                            esp = (esp - 0x4) + 0x4;
                                    }
                            }
                            arg_4 = eax + ebx;
                            if (edi >= eax + ebx) {
                                    arg_4 = edi;
                            }
                            if (arg_4 < ebx) {
                                    sub_46dedc();
                            }
                            ebx = sub_46dbce(arg_4);
                            sub_46dc09(ebx, arg_4, esi[0x1], esi[0x2]);
                            eax = esi[0x2];
                            sub_47ba40(eax + ebx, 0x0, edi - eax);
                            sub_47c8f9();
                            esp = (esp - 0x24) + 0x24;
                            esi[0x2] = edi;
                            esi[0x3] = arg_4;
                            esi[0x1] = ebx;
                    }
            }
    }
    return;
}
