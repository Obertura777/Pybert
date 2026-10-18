// sub_4750ff @ 0x4750ff
// hopper name: sub_4750ff
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4750ff() {
    esp = esp - 0x4;
    if (arg_4 == 0xfffffffe) {
            switch (arg_8) {
                case 513:
                    eax = sub_474d7e();
                    if (eax != 0x0) {
                            esp = esp - 0x8;
                            esi = sub_473aee(GetLastActivePopup(eax[0x8]));
                            if (esi != 0x0) {
                                    esp = esp - 0x4;
                                    if (esi != sub_473aee(GetForegroundWindow())) {
                                            if (sub_47679a() != 0x0) {
                                                    esp = esp - 0x4;
                                                    SetForegroundWindow(esi[0x8]);
                                                    eax = 0x1;
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = 0x0;
                    }
                    break;
                case 519:
                    eax = sub_474d7e();
                    if (eax != 0x0) {
                            esp = esp - 0x8;
                            esi = sub_473aee(GetLastActivePopup(eax[0x8]));
                            if (esi != 0x0) {
                                    esp = esp - 0x4;
                                    if (esi != sub_473aee(GetForegroundWindow())) {
                                            if (sub_47679a() != 0x0) {
                                                    esp = esp - 0x4;
                                                    SetForegroundWindow(esi[0x8]);
                                                    eax = 0x1;
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = 0x0;
                    }
                    break;
                default:
                    if (arg_8 == 0x204) {
                            eax = sub_474d7e();
                            if (eax != 0x0) {
                                    esp = esp - 0x8;
                                    esi = sub_473aee(GetLastActivePopup(eax[0x8]));
                                    if (esi != 0x0) {
                                            esp = esp - 0x4;
                                            if (esi != sub_473aee(GetForegroundWindow())) {
                                                    if (sub_47679a() != 0x0) {
                                                            esp = esp - 0x4;
                                                            SetForegroundWindow(esi[0x8]);
                                                            eax = 0x1;
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = 0x0;
                    }
                    break;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
