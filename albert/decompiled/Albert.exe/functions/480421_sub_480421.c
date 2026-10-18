// sub_480421 @ 0x480421
// hopper name: sub_480421
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_480421() {
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_0;
    eax = edi[0x1];
    if (eax != 0x0) {
            edx = eax + 0x8;
            if (*(int8_t *)edx != 0x0) {
                    esi = arg_4;
                    ecx = esi[0x1];
                    if (eax != ecx) {
                            esp = (esp - 0x8) + 0x8;
                            if (sub_47fd80(edx, ecx + 0x8) != 0x0) {
                                    eax = 0x0;
                            }
                            else {
                                    if ((*(int8_t *)esi & 0x2) != 0x0) {
                                            if ((*(int8_t *)edi & 0x8) != 0x0) {
                                                    eax = *arg_8;
                                                    if ((eax & 0x1) != 0x0) {
                                                            if ((*(int8_t *)edi & 0x1) != 0x0) {
                                                                    if ((eax & 0x2) != 0x0) {
                                                                            if ((*(int8_t *)edi & 0x2) != 0x0) {
                                                                                    eax = 0x1;
                                                                            }
                                                                            else {
                                                                                    eax = 0x0;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = 0x1;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            if ((eax & 0x2) != 0x0) {
                                                                    if ((*(int8_t *)edi & 0x2) != 0x0) {
                                                                            eax = 0x1;
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x1;
                                                            }
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = *arg_8;
                                            if ((eax & 0x1) != 0x0) {
                                                    if ((*(int8_t *)edi & 0x1) != 0x0) {
                                                            if ((eax & 0x2) != 0x0) {
                                                                    if ((*(int8_t *)edi & 0x2) != 0x0) {
                                                                            eax = 0x1;
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x1;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                            else {
                                                    if ((eax & 0x2) != 0x0) {
                                                            if ((*(int8_t *)edi & 0x2) != 0x0) {
                                                                    eax = 0x1;
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x1;
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            if ((*(int8_t *)esi & 0x2) != 0x0) {
                                    if ((*(int8_t *)edi & 0x8) != 0x0) {
                                            eax = *arg_8;
                                            if ((eax & 0x1) != 0x0) {
                                                    if ((*(int8_t *)edi & 0x1) != 0x0) {
                                                            if ((eax & 0x2) != 0x0) {
                                                                    if ((*(int8_t *)edi & 0x2) != 0x0) {
                                                                            eax = 0x1;
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x1;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                            else {
                                                    if ((eax & 0x2) != 0x0) {
                                                            if ((*(int8_t *)edi & 0x2) != 0x0) {
                                                                    eax = 0x1;
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x1;
                                                    }
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    eax = *arg_8;
                                    if ((eax & 0x1) != 0x0) {
                                            if ((*(int8_t *)edi & 0x1) != 0x0) {
                                                    if ((eax & 0x2) != 0x0) {
                                                            if ((*(int8_t *)edi & 0x2) != 0x0) {
                                                                    eax = 0x1;
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x1;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            if ((eax & 0x2) != 0x0) {
                                                    if ((*(int8_t *)edi & 0x2) != 0x0) {
                                                            eax = 0x1;
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                            else {
                                                    eax = 0x1;
                                            }
                                    }
                            }
                    }
            }
            else {
                    eax = 0x1;
            }
    }
    else {
            eax = 0x1;
    }
    return eax;
}
