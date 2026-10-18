// sub_48ca30 @ 0x48ca30
// hopper name: sub_48ca30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48ca30() {
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
            ebx = arg_4 / arg_8;
            esi = arg_0 / arg_8;
            eax = esi * arg_8;
            edx = HIDWORD(esi * arg_8) + ebx * arg_8;
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
                    bool_10 = edx < arg_4;
                    if (edx <= arg_4) {
                            if (!bool_10 && eax > arg_0) {
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
    eax = eax - arg_10;
    edx = edx - arg_14 + CARRY(EFLAGS(cf));
    if (&decomp_var_1 < 0x0) {
            eax = -eax;
            edx = -edx - 0x0 + CARRY(EFLAGS(cf));
    }
    edx = ebx;
    eax = esi;
    if (edi == 0x1) {
            eax = -eax;
    }
    return eax;
}
