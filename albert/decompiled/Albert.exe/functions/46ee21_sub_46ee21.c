// sub_46ee21 @ 0x46ee21
// hopper name: sub_46ee21
// referenced by: called,pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46ee21() {
    eax = arg_8;
    esp = esp - 0x4;
    decomp_var_8 = edi;
    edi = ecx;
    if (eax == 0xfffffffe) {
            if (*(sub_4715ba() + 0x3c) == 0x0) {
                    sub_46dedc();
            }
            esp = esp - 0x10;
            (*(**(sub_4715ba() + 0x3c) + 0x4))(edi, arg_4, arg_c, arg_10);
    }
    else {
            decomp_var_c = ebx;
            esp = esp - 0x8;
            decomp_var_10 = esi;
            if (eax == 0xfffffffd) {
                    ebx = arg_c;
                    arg_8 = arg_8 & 0x0;
                    if (ebx == 0x0) {
                            sub_46dedc();
                    }
                    arg_c = ebx[0xc];
                    for (edi = (*(*edi + 0x2c))(); edi != 0x0; edi = *edi) {
                            if (arg_8 != 0x0) {
                                    break;
                            }
                            esi = edi[0x1];
                            while (true) {
                                    eax = esi[0x1];
                                    if (eax == 0x0) {
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    else {
                                            if (esi[0x2] != 0x0) {
                                                    if (arg_8 == 0x0) {
                                                            if (arg_4 != eax) {
                                                                    esi = esi + 0xc;
                                                                    continue;
                                                            }
                                                            if (arg_c == 0x0) {
                                                                    if (*esi != 0x0) {
                                                                            esi = esi + 0xc;
                                                                            continue;
                                                                    }
                                                                    ebx[0x1] = esi[0x2];
                                                                    arg_8 = 0x1;
                                                                    esi = esi + 0xc;
                                                                    continue;
                                                            }
                                                            eax = *esi;
                                                            if (eax == 0x0) {
                                                                    esi = esi + 0xc;
                                                                    continue;
                                                            }
                                                            esp = (esp - 0x8) + 0x8;
                                                            if (sub_46ecd1(arg_c, eax) != 0x0) {
                                                                    ebx[0x1] = esi[0x2];
                                                                    arg_8 = 0x1;
                                                                    esi = esi + 0xc;
                                                                    continue;
                                                            }
                                                            esi = esi + 0xc;
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            else {
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                    }
                            }
                    }
                    esp = esp + 0x8;
            }
            else {
                    if (eax != 0xffffffff) {
                            ebx = eax >> 0x10;
                            arg_8 = eax & 0xffff;
                            if (ebx == 0x0) {
                                    ebx = 0x111;
                            }
                    }
                    else {
                            ebx = 0x111;
                    }
                    eax = *edi;
                    eax = (eax[0xa])();
                    while (true) {
                            esi = eax;
                            if (*esi != 0x0) {
                                    esp = esp - 0x10;
                                    eax = sub_472033(esi[0x1], ebx, arg_8, arg_4);
                                    if (eax == 0x0) {
                                            eax = (*esi)();
                                            continue;
                                    }
                                    esp = esp - 0x1c;
                                    sub_46ece9();
                                    temp_1 = 0x1;
                                    break;
                            }
                            temp_1 = 0x0;
                            break;
                    }
                    esp = esp + 0x8;
            }
    }
    return;
}
