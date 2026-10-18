// sub_475089 @ 0x475089
// hopper name: sub_475089
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_475089() {
    edi = arg_0;
    eax = sub_476745();
    if ((eax & 0x40000000) == 0x0) {
            esp = esp - 0x4;
            eax = sub_474d7e();
            ebx = eax;
            if (ebx != 0x0) {
                    esp = esp - 0x4;
                    esi = arg_8;
                    if (esi != 0x0) {
                            esp = esp - 0x4;
                            if (IsWindow(esi[0x8]) != 0x0) {
                                    eax = sub_474d7e();
                                    if (ebx != eax) {
                                            var_8 = edi[0x8];
                                            if (esi == 0x0) {
                                                    var_4 = var_4 & esi;
                                            }
                                            else {
                                                    var_4 = esi[0x8];
                                            }
                                            esp = esp - 0x10;
                                            eax = SendMessageA(ebx[0x8], 0x36e, arg_4, &var_8);
                                            esp = esp + 0x4;
                                            esp = esp + 0x4;
                                    }
                                    else {
                                            esp = esp + 0x4;
                                            esp = esp + 0x4;
                                    }
                            }
                            else {
                                    var_8 = edi[0x8];
                                    if (esi == 0x0) {
                                            var_4 = var_4 & esi;
                                    }
                                    else {
                                            var_4 = esi[0x8];
                                    }
                                    esp = esp - 0x10;
                                    eax = SendMessageA(ebx[0x8], 0x36e, arg_4, &var_8);
                                    esp = esp + 0x4;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            var_8 = edi[0x8];
                            if (esi == 0x0) {
                                    var_4 = var_4 & esi;
                            }
                            else {
                                    var_4 = esi[0x8];
                            }
                            esp = esp - 0x10;
                            eax = SendMessageA(ebx[0x8], 0x36e, arg_4, &var_8);
                            esp = esp + 0x4;
                            esp = esp + 0x4;
                    }
            }
            else {
                    esp = esp + 0x4;
            }
    }
    return eax;
}
