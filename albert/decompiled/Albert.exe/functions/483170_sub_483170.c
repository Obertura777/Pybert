// sub_483170 @ 0x483170
// hopper name: sub_483170
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_483170() {
    esp = esp - 0x8;
    eax = arg_c | arg_c;
    if (eax == 0x0) {
            eax = arg_0 / arg_8;
    }
    else {
            ecx = eax;
            ebx = arg_8;
            edx = arg_4;
            eax = arg_0;
            do {
                    ecx = ecx >> 0x1;
                    asm { rcr        ebx, 0x1 };
                    edx = edx >> 0x1;
                    asm { rcr        eax, 0x1 };
                    ecx = ecx | ecx;
            } while (ecx != 0x0);
            esi = eax / ebx;
            ecx = eax / ebx * arg_c;
            eax = arg_8 * esi;
            edx = HIDWORD(arg_8 * esi) + ecx;
            if (edx >= 0x0) {
                    bool_3 = edx < arg_4;
                    if (edx <= arg_4) {
                            if (!bool_3 && eax > arg_0) {
                                    esi = esi - 0x1;
                            }
                    }
                    else {
                            esi = esi - 0x1;
                    }
            }
            else {
                    esi = esi - 0x1;
            }
            eax = esi;
    }
    return eax;
}
