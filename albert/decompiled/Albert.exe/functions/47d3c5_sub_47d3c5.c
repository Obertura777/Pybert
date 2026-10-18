// sub_47d3c5 @ 0x47d3c5
// hopper name: sub_47d3c5
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47d3c5() {
    if (*(int16_t *)word_400000 == 0x5a4d) {
            if (*(*dword_40003c + word_400000) == 0x4550) {
                    if (*(int16_t *)(*dword_40003c + 0x400018) == 0x10b) {
                            if (*(*dword_40003c + 0x400074) > 0xe) {
                                    eax = *(*dword_40003c + 0x4000e8) != 0x0 ? 0x1 : 0x0;
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
