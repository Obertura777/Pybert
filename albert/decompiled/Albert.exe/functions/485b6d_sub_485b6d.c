// sub_485b6d @ 0x485b6d
// hopper name: sub_485b6d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_485b6d() {
    decomp_var_4 = ebx;
    esp = esp - 0x8;
    decomp_var_8 = esi;
    esi = eax;
    ebx = ecx;
    if ((edi[0xc] & 0x40) != 0x0) {
            if (edi[0x2] == 0x0) {
                    *esi = *esi + arg_0;
            }
            else {
                    if (arg_0 > 0x0) {
                            arg_0 = arg_0 - 0x1;
                            sub_485b16();
                            ebx = ebx + 0x1;
                            if (*esi == 0xffffffff) {
                                    if (*sub_47d812() == 0x2a) {
                                            sub_485b16();
                                            while (true) {
                                                    if (arg_0 > 0x0) {
                                                            arg_0 = arg_0 - 0x1;
                                                            sub_485b16();
                                                            ebx = ebx + 0x1;
                                                            if (*esi != 0xffffffff) {
                                                                    continue;
                                                            }
                                                            if (*sub_47d812() == 0x2a) {
                                                                    sub_485b16();
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    while (true) {
                                            if (arg_0 > 0x0) {
                                                    arg_0 = arg_0 - 0x1;
                                                    sub_485b16();
                                                    ebx = ebx + 0x1;
                                                    if (*esi != 0xffffffff) {
                                                            continue;
                                                    }
                                                    if (*sub_47d812() == 0x2a) {
                                                            sub_485b16();
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                            }
                    }
            }
    }
    else {
            while (true) {
                    if (arg_0 > 0x0) {
                            arg_0 = arg_0 - 0x1;
                            sub_485b16();
                            ebx = ebx + 0x1;
                            if (*esi != 0xffffffff) {
                                    continue;
                            }
                            if (*sub_47d812() == 0x2a) {
                                    sub_485b16();
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    temp_0 = 0x0;
                    break;
            }
    }
    return;
}
