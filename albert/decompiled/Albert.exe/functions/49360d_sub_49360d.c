// sub_49360d @ 0x49360d
// hopper name: sub_49360d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_49360d() {
    esp = esp - 0x4;
    decomp_var_14 = esi;
    esi = arg_4;
    if (esi == 0x0) {
            var_C = *(sub_48bbb4() + 0x8);
            eax = sub_48bb8e();
    }
    else {
            var_C = *esi;
            eax = esi[0x1];
    }
    var_10 = eax;
    if (var_C == 0x0) {
            eax = arg_0;
            if (eax <= 0x7a) {
                    eax = eax - 0x20;
            }
    }
    else {
            esp = esp - 0x4;
            decomp_var_18 = ebx;
            ebx = arg_0;
            if (ebx < 0x100) {
                    if (esi == 0x0) {
                            esp = (esp - 0x4) + 0x4;
                            if (sub_47d022(ebx) == 0x0) {
                                    eax = ebx;
                                    esp = esp + 0x4;
                            }
                            else {
                                    var_8 = SAR(ebx, 0x8);
                                    eax = sub_48ac5f();
                                    eax = *(int16_t *)(eax + (var_8 & 0xff) * 0x2) & 0xffff;
                                    eax = eax & 0x8000;
                                    if (eax != 0x0) {
                                            arg_4 = var_8;
                                            eax = 0x2;
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    else {
                                            arg_4 = ebx;
                                            eax = 0x1;
                                    }
                                    eax = sub_482d50(0x0, var_C, 0x200, &arg_4, eax, &var_4, 0x3, var_10, 0x1);
                                    esp = (esp - 0x24) + 0x24;
                                    if (eax == 0x0) {
                                            eax = ebx;
                                    }
                                    else {
                                            if (eax == 0x1) {
                                                    eax = var_4 & 0xff;
                                            }
                                            else {
                                                    HIBYTE(eax) = var_4;
                                                    eax = eax | var_3 & 0xff;
                                            }
                                    }
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            if ((*(int8_t *)(esi[0x2] + ebx * 0x2) & 0x2) != 0x0) {
                                    if (esi == 0x0) {
                                            var_8 = SAR(ebx, 0x8);
                                            eax = sub_48ac5f();
                                            eax = *(int16_t *)(eax + (var_8 & 0xff) * 0x2) & 0xffff;
                                            eax = eax & 0x8000;
                                    }
                                    else {
                                            var_8 = SAR(ebx, 0x8);
                                            eax = *(int16_t *)(esi[0x2] + (var_8 & 0xff) * 0x2) & 0xffff;
                                            eax = eax >> 0xf & 0x1;
                                    }
                                    if (eax != 0x0) {
                                            arg_4 = var_8;
                                            eax = 0x2;
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    else {
                                            arg_4 = ebx;
                                            eax = 0x1;
                                    }
                                    eax = sub_482d50(0x0, var_C, 0x200, &arg_4, eax, &var_4, 0x3, var_10, 0x1);
                                    esp = (esp - 0x24) + 0x24;
                                    if (eax == 0x0) {
                                            eax = ebx;
                                    }
                                    else {
                                            if (eax == 0x1) {
                                                    eax = var_4 & 0xff;
                                            }
                                            else {
                                                    HIBYTE(eax) = var_4;
                                                    eax = eax | var_3 & 0xff;
                                            }
                                    }
                                    esp = esp + 0x4;
                            }
                            else {
                                    eax = ebx;
                                    esp = esp + 0x4;
                            }
                    }
            }
            else {
                    if (esi == 0x0) {
                            var_8 = SAR(ebx, 0x8);
                            eax = sub_48ac5f();
                            eax = *(int16_t *)(eax + (var_8 & 0xff) * 0x2) & 0xffff;
                            eax = eax & 0x8000;
                    }
                    else {
                            var_8 = SAR(ebx, 0x8);
                            eax = *(int16_t *)(esi[0x2] + (var_8 & 0xff) * 0x2) & 0xffff;
                            eax = eax >> 0xf & 0x1;
                    }
                    if (eax != 0x0) {
                            arg_4 = var_8;
                            eax = 0x2;
                            esp = (esp - 0x4) + 0x4;
                    }
                    else {
                            arg_4 = ebx;
                            eax = 0x1;
                    }
                    eax = sub_482d50(0x0, var_C, 0x200, &arg_4, eax, &var_4, 0x3, var_10, 0x1);
                    esp = (esp - 0x24) + 0x24;
                    if (eax == 0x0) {
                            eax = ebx;
                    }
                    else {
                            if (eax == 0x1) {
                                    eax = var_4 & 0xff;
                            }
                            else {
                                    HIBYTE(eax) = var_4;
                                    eax = eax | var_3 & 0xff;
                            }
                    }
                    esp = esp + 0x4;
            }
    }
    return eax;
}
