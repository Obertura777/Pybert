// sub_475ce6 @ 0x475ce6
// hopper name: sub_475ce6
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_475ce6() {
    eax = arg_0;
    bool_13 = eax == 0x111;
    esp = esp - 0x10;
    decomp_var_10 = esi;
    if (eax <= 0x111) {
            if (!bool_13) {
                    if (eax >= 0x2b) {
                            if (eax > 0x2f) {
                                    if (eax != 0x39) {
                                            if (eax == 0x4e) {
                                                    esp = esp - 0x10;
                                                    eax = sub_46ee21();
                                            }
                                            else {
                                                    if (eax <= 0x138) {
                                                            eax = sub_4756ba();
                                                            esp = (esp - 0x14) + 0x4;
                                                            if (*arg_c == 0x0) {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                    }
                                    else {
                                            esp = esp - 0x10;
                                            eax = sub_4756ba();
                                    }
                            }
                            else {
                                    esp = esp - 0x10;
                                    eax = sub_4756ba();
                            }
                    }
                    else {
                            if (eax <= 0x138) {
                                    eax = sub_4756ba();
                                    esp = (esp - 0x14) + 0x4;
                                    if (*arg_c == 0x0) {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
            }
            else {
                    esp = esp - 0x10;
                    if (sub_46ee21() != 0x0) {
                            ecx = arg_c;
                            eax = 0x1;
                            if (ecx != 0x0) {
                                    eax = 0x1;
                                    *ecx = 0x1;
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
    }
    else {
            if (eax >= 0x114) {
                    if (eax > 0x115) {
                            if (eax == 0x210) {
                                    esp = esp - 0x10;
                                    eax = sub_4756ba();
                            }
                            else {
                                    if (eax <= 0x138) {
                                            eax = sub_4756ba();
                                            esp = (esp - 0x14) + 0x4;
                                            if (*arg_c == 0x0) {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                    }
                    else {
                            esp = esp - 0x10;
                            eax = sub_4756ba();
                    }
            }
            else {
                    if (eax <= 0x138) {
                            eax = sub_4756ba();
                            esp = (esp - 0x14) + 0x4;
                            if (*arg_c == 0x0) {
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
    }
    return eax;
}
