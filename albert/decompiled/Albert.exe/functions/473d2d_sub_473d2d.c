// sub_473d2d @ 0x473d2d
// hopper name: sub_473d2d
// referenced by: called,pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_473d2d() {
    decomp_var_4 = esi;
    esi = ecx;
    eax = esi[0x8];
    esp = esp - 0x8;
    decomp_var_8 = edi;
    if (eax == 0x0) {
            if (esi[0x14] == 0x0) {
                    eax = 0x0;
            }
            else {
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            eax = sub_473a7a();
                            if (eax == 0x0) {
                                    sub_46dedc();
                            }
                            esp = esp - 0x4;
                            sub_4791ea();
                            edi = 0x0;
                            eax = esi[0x8];
                            if (eax == 0x0) {
                                    if (esi[0x14] != edi) {
                                            if (esi[0x14] == edi) {
                                                    esp = esp - 0x4;
                                                    eax = DestroyWindow(eax);
                                            }
                                            else {
                                                    eax = *esi[0x14];
                                                    eax = (eax[0x16])();
                                            }
                                            edi = eax;
                                            eax = edi;
                                    }
                                    else {
                                            eax = edi;
                                    }
                            }
                            else {
                                    if (esi[0x14] == 0x0) {
                                            esp = esp - 0x4;
                                            eax = DestroyWindow(eax);
                                    }
                                    else {
                                            eax = *esi[0x14];
                                            eax = (eax[0x16])();
                                    }
                                    edi = eax;
                                    eax = edi;
                            }
                    }
                    else {
                            eax = esi[0x8];
                            if (eax == 0x0) {
                                    edi = 0x0;
                                    if (esi[0x14] != 0x0) {
                                            if (esi[0x14] == 0x0) {
                                                    esp = esp - 0x4;
                                                    eax = DestroyWindow(eax);
                                            }
                                            else {
                                                    eax = *esi[0x14];
                                                    eax = (eax[0x16])();
                                            }
                                            edi = eax;
                                            eax = edi;
                                    }
                                    else {
                                            eax = edi;
                                    }
                            }
                            else {
                                    if (esi[0x14] == 0x0) {
                                            esp = esp - 0x4;
                                            eax = DestroyWindow(eax);
                                    }
                                    else {
                                            eax = *esi[0x14];
                                            eax = (eax[0x16])();
                                    }
                                    edi = eax;
                                    eax = edi;
                            }
                    }
            }
    }
    else {
            esp = esp - 0x4;
            eax = sub_473a7a();
            if (eax == 0x0) {
                    sub_46dedc();
            }
            esp = esp - 0x4;
            sub_4791ea();
            edi = 0x0;
            eax = esi[0x8];
            if (eax == 0x0) {
                    if (esi[0x14] != edi) {
                            if (esi[0x14] == edi) {
                                    esp = esp - 0x4;
                                    eax = DestroyWindow(eax);
                            }
                            else {
                                    eax = *esi[0x14];
                                    eax = (eax[0x16])();
                            }
                            edi = eax;
                            eax = edi;
                    }
                    else {
                            eax = edi;
                    }
            }
            else {
                    if (esi[0x14] == 0x0) {
                            esp = esp - 0x4;
                            eax = DestroyWindow(eax);
                    }
                    else {
                            eax = *esi[0x14];
                            eax = (eax[0x16])();
                    }
                    edi = eax;
                    eax = edi;
            }
    }
    return eax;
}
