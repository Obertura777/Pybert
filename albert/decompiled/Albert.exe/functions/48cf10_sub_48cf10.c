// sub_48cf10 @ 0x48cf10
// hopper name: sub_48cf10
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48cf10() {
    asm { fld        tword [esp+arg_C] };
    asm { fld        tword [esp+arg_0] };
    while (true) {
            eax = arg_4 + arg_4;
            if (eax < 0x0) {
                    eax = eax ^ 0xe000000;
                    if ((eax & 0xe000000) != 0x0) {
                            asm { fdivp      st1 };
                            temp_0 = 0x3;
                    }
                    else {
                            eax = eax >> 0x1c;
                            if (eax[0x4c9df0] == 0x0) {
                                    asm { fdivp      st1 };
                                    temp_0 = 0x3;
                            }
                            else {
                                    eax = arg_8 & 0x7fff;
                                    switch (eax) {
                                        case 0:
                                            temp_0 = 0x0;
                                            break;
                                        case 32767:
                                            temp_0 = 0x0;
                                            break;
                                        default:
                                            asm { fnstcw     word [esp+arg_18] };
                                            asm { fldcw      word [esp+arg_1C] };
                                            eax = arg_14 & 0x7fff;
                                            if (eax != 0x1) {
                                                    asm { fmul       dword [dword_4c9e00] };
                                                    asm { fxch       st0, st1 };
                                                    asm { fmul       dword [dword_4c9e00] };
                                                    asm { fxch       st0, st1 };
                                                    asm { fldcw      word [esp+arg_18] };
                                                    asm { fdivp      st1 };
                                                    temp_0 = 0x4;
                                            }
                                            else {
                                                    asm { fmul       dword [dword_4c9e04] };
                                                    asm { fxch       st0, st1 };
                                                    asm { fmul       dword [dword_4c9e04] };
                                                    asm { fxch       st0, st1 };
                                                    asm { fldcw      word [esp+arg_18] };
                                                    asm { fdivp      st1 };
                                                    temp_0 = 0x5;
                                            }
                                            break;
                                    }
                            }
                    }
                    break;
            }
            else {
                    eax = arg_0 | arg_4;
                    if (eax == 0x0) {
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            eax = arg_8 & 0x7fff;
                            if (eax == 0x0) {
                                    asm { fnstcw     word [esp+arg_18] };
                                    asm { fldcw      word [esp+arg_1C] };
                                    eax = arg_14 & 0x7fff;
                                    if (eax != 0x0) {
                                            if (eax != 0x7fff) {
                                                    eax = arg_10 + arg_10;
                                                    if (eax < 0x0) {
                                                            asm { fxch       st0, st1 };
                                                            asm { fstp       st0 };
                                                            asm { fld        st0 };
                                                            asm { fmul       dword [dword_4c9e08] };
                                                            asm { fstp       tword [esp+arg_0] };
                                                            asm { fld        tword [esp+arg_C] };
                                                            asm { fxch       st0, st1 };
                                                            asm { wait };
                                                            asm { fldcw      word [esp+arg_18] };
                                                            continue;
                                                    }
                                                    temp_0 = 0x2;
                                                    break;
                                            }
                                            else {
                                                    temp_0 = 0x2;
                                                    break;
                                            }
                                    }
                                    else {
                                            eax = arg_10 + arg_10;
                                            if (eax >= 0x0) {
                                                    asm { fxch       st0, st1 };
                                                    asm { fstp       st0 };
                                                    asm { fld        st0 };
                                                    asm { fmul       dword [dword_4c9e08] };
                                                    asm { fstp       tword [esp+arg_0] };
                                                    asm { fld        tword [esp+arg_C] };
                                                    asm { fxch       st0, st1 };
                                                    asm { wait };
                                                    asm { fldcw      word [esp+arg_18] };
                                                    continue;
                                            }
                                            temp_0 = 0x7;
                                            break;
                                    }
                            }
                            else {
                                    temp_0 = 0x6;
                                    break;
                            }
                    }
            }
    }
    switch (temp_0) {
        case 0:
            asm { fdivp      st1 };
            break;
        case 1:
            asm { fdivp      st1 };
            break;
        case 2:
            asm { fldcw      word [esp+arg_18] };
            asm { fdivp      st1 };
            break;
        default:
            if (temp_0 != 0x3 && temp_0 != 0x4 && temp_0 != 0x5) {
                    if (temp_0 != 0x6) {
                            asm { fldcw      word [esp+arg_18] };
                            asm { fdivp      st1 };
                    }
                    else {
                            asm { fdivp      st1 };
                    }
            }
            break;
    }
    return eax;
}
