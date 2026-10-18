// sub_4782d6 @ 0x4782d6
// hopper name: sub_4782d6
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4782d6() {
    esp = esp - 0x4;
    esi = ecx;
    if (esi != 0x0) {
            eax = esi[0x11];
            var_8 = --eax - --eax + CARRY(EFLAGS(cf));
            if (--eax != --eax + CARRY(EFLAGS(cf))) {
                    esp = esp - 0x4;
                    edi = esi + 0x38;
                    do {
                            decomp_var_1c = &var_C;
                            esp = esp - 0xc;
                            decomp_var_20 = &var_8;
                            sub_479294();
                            eax = esi[0x16];
                            eax = eax + var_4;
                            *eax = *eax & 0x0;
                            if (esi[0x17] == 0x2) {
                                    eax[0x1] = eax[0x1] & 0x0;
                            }
                            esp = esp - 0x4;
                            (esi[0x6])(var_4);
                    } while (var_8 != 0x0);
                    esp = esp + 0x4;
            }
            sub_47916e();
            sub_479b2f();
    }
    return;
}
