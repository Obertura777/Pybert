// sub_4813a3 @ 0x4813a3
// hopper name: sub_4813a3
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4813a3() {
    eax = eax - 0x3a4;
    if (eax != 0x0) {
            eax = eax - 0x4;
            if (eax != 0x0) {
                    eax = eax - 0xd;
                    if (eax != 0x0) {
                            if (eax != 0x1) {
                                    eax = 0x0;
                            }
                            else {
                                    eax = 0x404;
                            }
                    }
                    else {
                            eax = 0x412;
                    }
            }
            else {
                    eax = 0x804;
            }
    }
    else {
            eax = 0x411;
    }
    return eax;
}
