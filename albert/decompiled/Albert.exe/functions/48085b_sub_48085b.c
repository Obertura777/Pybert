// sub_48085b @ 0x48085b
// hopper name: sub_48085b
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48085b() {
    *(edi - 0x4) = decomp_var_24;
    sub_47acbf(decomp_var_28);
    esp = (esp - 0x4) + 0x4;
    *(sub_480086() + 0x88) = decomp_var_2c;
    eax = sub_480086();
    eax[0x23] = decomp_var_30;
    if (*esi == 0xe06d7363 && esi[0x4] == 0x3) {
            eax = esi[0x5];
            switch (eax) {
                case 429065504:
                    if (decomp_var_34 == 0x0 && decomp_var_1c != 0x0) {
                            eax = sub_47ac9e(esi[0x6]);
                            esp = (esp - 0x4) + 0x4;
                            if (eax != 0x0) {
                                    eax = sub_4805e7();
                            }
                    }
                    break;
                case 429065505:
                    if (decomp_var_34 == 0x0 && decomp_var_1c != 0x0) {
                            eax = sub_47ac9e(esi[0x6]);
                            esp = (esp - 0x4) + 0x4;
                            if (eax != 0x0) {
                                    eax = sub_4805e7();
                            }
                    }
                    break;
                default:
                    if (eax == 0x19930522 && decomp_var_34 == 0x0) {
                            if (decomp_var_1c != 0x0) {
                                    eax = sub_47ac9e(esi[0x6]);
                                    esp = (esp - 0x4) + 0x4;
                                    if (eax != 0x0) {
                                            eax = sub_4805e7();
                                    }
                            }
                    }
                    break;
            }
    }
    return eax;
}
