// sub_48f940 @ 0x48f940
// hopper name: sub_48f940
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48f940() {
    decomp_var_4 = esi;
    esi = arg_0;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    if (esi == 0x0) {
            *sub_47d812() = 0x16;
            eax = sub_47a924();
            esp = (esp - 0x14) + 0x14;
            eax = eax | 0xffffffff;
    }
    else {
            eax = esi[0x3];
            if ((eax & 0x83) != 0x0) {
                    if ((eax & 0x40) == 0x0) {
                            if ((eax & 0x2) != 0x0) {
                                    eax = eax | 0x20;
                                    esi[0x3] = eax;
                                    eax = eax | 0xffffffff;
                            }
                            else {
                                    esi[0x3] = eax | 0x1;
                                    if (((eax | 0x1) & 0x10c) == 0x0) {
                                            sub_48e10c(esi);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    else {
                                            *esi = esi[0x2];
                                    }
                                    decomp_var_c = esi[0x6];
                                    decomp_var_10 = esi[0x2];
                                    sub_4867ae(esi);
                                    eax = sub_492ac6();
                                    esp = ((esp - 0xc) + 0x4 - 0x4) + 0xc;
                                    esi[0x1] = eax;
                                    switch (eax) {
                                        case 0:
                                            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x10) + 0x10;
                                            esi[0x3] = esi[0x3] | eax;
                                            esi[0x1] = 0x0;
                                            eax = eax | 0xffffffff;
                                            break;
                                        case -1:
                                            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x10) + 0x10;
                                            esi[0x3] = esi[0x3] | eax;
                                            esi[0x1] = 0x0;
                                            eax = eax | 0xffffffff;
                                            break;
                                        default:
                                            if ((esi[0xc] & 0x82) == 0x0) {
                                                    esp = (esp - 0x4) + 0x4;
                                                    if (sub_4867ae(esi) != 0xffffffff) {
                                                            esp = (esp - 0x4) + 0x4;
                                                            if (sub_4867ae(esi) != 0xfffffffe) {
                                                                    edi = (SAR(sub_4867ae(esi), 0x5)) * 0x4 + dword_bc7240;
                                                                    eax = sub_4867ae(esi);
                                                                    eax = (eax & 0x1f) * 0x28 + *edi;
                                                                    esp = (esp - 0x8) + 0x8;
                                                            }
                                                            else {
                                                                    eax = 0x4c9958;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x4c9958;
                                                    }
                                                    if ((eax[0x4] & 0x82) == 0x82) {
                                                            esi[0x3] = esi[0x3] | 0x2000;
                                                    }
                                            }
                                            if (esi[0x6] == 0x200) {
                                                    eax = esi[0x3];
                                                    if ((eax & 0x8) != 0x0 && (eax & 0x400) == 0x0) {
                                                            esi[0x6] = 0x1000;
                                                    }
                                            }
                                            ecx = *esi;
                                            esi[0x1] = esi[0x1] - 0x1;
                                            eax = *(int8_t *)ecx & 0xff;
                                            *esi = ecx + 0x1;
                                            break;
                                    }
                            }
                    }
                    else {
                            eax = eax | 0xffffffff;
                    }
            }
            else {
                    eax = eax | 0xffffffff;
            }
    }
    return eax;
}
