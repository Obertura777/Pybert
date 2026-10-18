// sub_47bac0 @ 0x47bac0
// hopper name: sub_47bac0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47bac0() {
    esp = esp - 0xc;
    edi = 0x0;
    eax = arg_4 | arg_4;
    if (eax < 0x0) {
            edi = 0x1;
            arg_4 = -eax - 0x0 + CARRY(EFLAGS(cf));
            arg_0 = -arg_0;
    }
    eax = arg_c | arg_c;
    if (eax < 0x0) {
            edi = edi + 0x1;
            eax = -eax - 0x0 + CARRY(EFLAGS(cf));
            arg_c = eax;
            arg_8 = -arg_8;
    }
    eax = eax | eax;
    if (eax == 0x0) {
            eax = arg_0 / arg_8;
            edx = arg_4 / arg_8;
    }
    else {
            ebx = eax;
            ecx = arg_8;
            edx = arg_4;
            eax = arg_0;
            do {
                    ebx = ebx >> 0x1;
                    asm { rcr        ecx, 0x1 };
                    edx = edx >> 0x1;
                    asm { rcr        eax, 0x1 };
                    ebx = ebx | ebx;
            } while (ebx != 0x0);
            esi = eax / ecx;
            ecx = eax / ecx * arg_c;
            eax = arg_8 * esi;
            edx = HIDWORD(arg_8 * esi) + ecx;
            if (edx >= 0x0) {
                    bool_7 = edx < arg_4;
                    if (edx <= arg_4) {
                            if (!bool_7 && eax > arg_0) {
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
            edx = 0x0;
            eax = esi;
    }
    if (edi == 0x1) {
            eax = -eax;
    }
    return eax;
}
