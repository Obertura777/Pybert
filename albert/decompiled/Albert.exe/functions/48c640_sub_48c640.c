// sub_48c640 @ 0x48c640
// hopper name: sub_48c640
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48c640() {
    esp = esp - 0x4;
    eax = arg_c | arg_c;
    if (eax == 0x0) {
            ebx = arg_4 / arg_8;
            esi = arg_0 / arg_8;
            eax = esi * arg_8;
            edx = HIDWORD(esi * arg_8) + ebx * arg_8;
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
                    bool_5 = edx < arg_4;
                    if (edx <= arg_4) {
                            if (!bool_5 && eax > arg_0) {
                                    esi = esi - 0x1;
                                    eax = eax - arg_8;
                                    edx = edx - arg_c + CARRY(EFLAGS(cf));
                            }
                    }
                    else {
                            esi = esi - 0x1;
                            eax = eax - arg_8;
                            edx = edx - arg_c + CARRY(EFLAGS(cf));
                    }
            }
            else {
                    esi = esi - 0x1;
                    eax = eax - arg_8;
                    edx = edx - arg_c + CARRY(EFLAGS(cf));
            }
            ebx = 0x0;
    }
    eax = esi;
    return eax;
}
