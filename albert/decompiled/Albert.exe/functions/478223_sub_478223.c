// sub_478223 @ 0x478223
// hopper name: sub_478223
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_478223() {
    esp = esp - 0x4;
    decomp_var_4 = 0x8;
    sub_47d6ee(0x8);
    esi = ecx;
    edi = arg_4;
    if (edi == 0x0) {
            eax = sub_47d75a();
    }
    else {
            esp = esp - 0x4;
            if (sub_4791ea() == 0x0) {
                    esp = esp - 0x4;
                    eax = sub_4791ea();
                    if (eax != 0x0) {
                            ecx = esi[0x16];
                            ecx = ecx + eax;
                            *ecx = edi;
                            if (esi[0x17] == 0x2) {
                                    ecx[0x1] = edi;
                            }
                            eax = sub_47d75a();
                    }
                    else {
                            esp = esp - 0x4;
                            eax = sub_46dbbc(0x477e2d);
                            decomp_var_4 = decomp_var_4 & 0x0;
                            arg_4 = eax;
                            ebx = sub_479b49();
                            if (ebx == 0x0) {
                                    sub_46dea8();
                            }
                            (esi[0x5])(ebx);
                            *sub_47939c(edi) = ebx;
                            sub_46dbbc(arg_4);
                            eax = esi[0x16];
                            eax = eax + ebx;
                            *eax = edi;
                            if (esi[0x17] == 0x2) {
                                    eax[0x1] = edi;
                            }
                            eax = sub_47d75a();
                    }
            }
            else {
                    eax = sub_47d75a();
            }
    }
    return eax;
}
