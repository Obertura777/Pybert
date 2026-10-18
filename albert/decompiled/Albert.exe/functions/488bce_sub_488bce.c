// sub_488bce @ 0x488bce
// hopper name: sub_488bce
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_488bce() {
    esi = sub_480003();
    if (esi == 0x0) {
            esp = esp - 0x4;
            UnhandledExceptionFilter(arg_4);
    }
    else {
            edx = esi[0x17];
            decomp_var_10 = edi;
            edi = arg_0;
            ecx = edx;
            esp = esp - 0x8;
            decomp_var_14 = ebx;
            while (*ecx != edi) {
                    ecx = ecx + 0xc;
                    if (ecx >= *dword_4c9be4 * 0xc + edx) {
                            break;
                    }
            }
            if (ecx < *dword_4c9be4 * 0xc + edx && *ecx == edi) {
                    eax = ecx;
            }
            else {
                    eax = 0x0;
            }
            if (eax != 0x0) {
                    ebx = eax[0x2];
                    var_4 = ebx;
                    if (ebx == 0x0) {
                            esp = esp - 0x4;
                            UnhandledExceptionFilter(arg_4);
                    }
                    else {
                            if (ebx == 0x5) {
                                    eax[0x2] = eax[0x2] & 0x0;
                            }
                            else {
                                    if (ebx != 0x1) {
                                            var_8 = esi[0x18];
                                            esi[0x18] = arg_4;
                                            ecx = eax[0x1];
                                            if (ecx == 0x8) {
                                                    ecx = *dword_4c9bd8;
                                                    edx = ecx;
                                                    if (edx < *dword_4c9bdc + ecx) {
                                                            ecx = *dword_4c9bd8;
                                                            ecx = ecx * 0xc;
                                                            do {
                                                                    edi = esi[0x17];
                                                                    *(ecx + edi + 0x8) = *(ecx + edi + 0x8) & 0x0;
                                                                    edx = edx + 0x1;
                                                                    ecx = ecx + 0xc;
                                                            } while (edx < *dword_4c9bdc + *dword_4c9bd8);
                                                            ebx = var_4;
                                                    }
                                                    eax = *eax;
                                                    edi = esi[0x19];
                                                    if (eax == 0xc000008e) {
                                                            esi[0x19] = 0x83;
                                                    }
                                                    else {
                                                            if (eax == 0xc0000090) {
                                                                    esi[0x19] = 0x81;
                                                            }
                                                            else {
                                                                    if (eax == 0xc0000091) {
                                                                            esi[0x19] = 0x84;
                                                                    }
                                                                    else {
                                                                            if (eax == 0xc0000093) {
                                                                                    esi[0x19] = 0x85;
                                                                            }
                                                                            else {
                                                                                    if (eax == 0xc000008d) {
                                                                                            esi[0x19] = 0x82;
                                                                                    }
                                                                                    else {
                                                                                            if (eax == 0xc000008f) {
                                                                                                    esi[0x19] = 0x86;
                                                                                            }
                                                                                            else {
                                                                                                    if (eax == 0xc0000092) {
                                                                                                            esi[0x19] = 0x8a;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    (ebx)(0x8, esi[0x19]);
                                                    esp = (esp - 0x8) + 0x4;
                                                    esi[0x19] = edi;
                                            }
                                            else {
                                                    eax[0x2] = eax[0x2] & 0x0;
                                                    esp = esp - 0x4;
                                                    (ebx)(ecx);
                                            }
                                            eax = var_8;
                                            esp = esp + 0x4;
                                            esi[0x18] = eax;
                                    }
                            }
                    }
            }
            else {
                    esp = esp - 0x4;
                    UnhandledExceptionFilter(arg_4);
            }
            esp = esp + 0x8;
    }
    return;
}
