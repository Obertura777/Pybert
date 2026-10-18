// sub_479eca @ 0x479eca
// hopper name: sub_479eca
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479eca() {
    esp = esp - 0x4;
    sub_47d6bb(saved_fp);
    esi = ecx;
    if ((0x1 & !esi[0x6]) != 0x0) {
            if (esi[0xe] == 0x0) {
                    edi = 0x0;
                    esp = (esp - 0x4) + 0x4;
                    decomp_var_4 = 0x0;
                    if (sub_46dbce(saved_fp) != 0x0) {
                            esp = esp - 0x4;
                            decomp_var_4 = esi[0x10];
                            eax = sub_479315(saved_fp);
                    }
                    else {
                            eax = 0x0;
                    }
                    esi[0xe] = eax;
                    sub_479114(saved_fp, arg_0);
                    esp = esp - 0xc;
                    *sub_47939c(saved_fp) = edi;
                    esi[0xd] = 0x1;
            }
            if (arg_4 != 0x0) {
                    sub_479eb6();
                    *sub_47939c(saved_fp) = esi[0xd];
                    esi[0xd] = esi[0xd] + 0x1;
                    loc_479fbb();
            }
            else {
                    (null)();
            }
    }
    else {
            sub_479f50();
    }
    return;
}
