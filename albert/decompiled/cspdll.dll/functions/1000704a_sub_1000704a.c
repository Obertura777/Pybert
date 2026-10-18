// sub_1000704a @ 0x1000704a
// hopper name: sub_1000704a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_1000704a() {
    eax = arg_4;
    if (eax == 0x0) {
            if (*0x1000ab44 > eax) {
                    *0x1000ab44 = *0x1000ab44 - 0x1;
                    *0x1000ab48 = *_adjust_fdiv;
                    if (eax == 0x1) {
                            eax = malloc(0x80);
                            esp = (esp - 0x4) + 0x4;
                            *0x1000ab50 = eax;
                            if (eax == 0x0) {
                                    eax = 0x0;
                            }
                            else {
                                    *eax = *eax & 0x0;
                                    *0x1000ab4c = *0x1000ab50;
                                    _initterm(0x10009000, 0x10009004);
                                    *0x1000ab44 = *0x1000ab44 + 0x1;
                                    esp = (esp - 0x8) + 0x8;
                                    eax = 0x1;
                            }
                    }
                    else {
                            if (eax == 0x0 && *0x1000ab50 != 0x0) {
                                    esp = esp - 0x4;
                                    decomp_var_4 = esi;
                                    for (esi = *0x1000ab4c - 0x4; esi >= *0x1000ab50; esi = esi - 0x4) {
                                            ecx = *esi;
                                            if (ecx != 0x0) {
                                                    (ecx)();
                                            }
                                    }
                                    free(*0x1000ab50);
                                    *0x1000ab50 = *0x1000ab50 & 0x0;
                                    esp = (esp - 0x4) + 0x8;
                            }
                            eax = 0x1;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            *0x1000ab48 = *_adjust_fdiv;
            if (eax == 0x1) {
                    eax = malloc(0x80);
                    esp = (esp - 0x4) + 0x4;
                    *0x1000ab50 = eax;
                    if (eax == 0x0) {
                            eax = 0x0;
                    }
                    else {
                            *eax = *eax & 0x0;
                            *0x1000ab4c = *0x1000ab50;
                            _initterm(0x10009000, 0x10009004);
                            *0x1000ab44 = *0x1000ab44 + 0x1;
                            esp = (esp - 0x8) + 0x8;
                            eax = 0x1;
                    }
            }
            else {
                    if (eax == 0x0 && *0x1000ab50 != 0x0) {
                            esp = esp - 0x4;
                            decomp_var_4 = esi;
                            for (esi = *0x1000ab4c - 0x4; esi >= *0x1000ab50; esi = esi - 0x4) {
                                    ecx = *esi;
                                    if (ecx != 0x0) {
                                            (ecx)();
                                    }
                            }
                            free(*0x1000ab50);
                            *0x1000ab50 = *0x1000ab50 & 0x0;
                            esp = (esp - 0x4) + 0x8;
                    }
                    eax = 0x1;
            }
    }
    return eax;
}
