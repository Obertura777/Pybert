// sub_473684 @ 0x473684
// hopper name: sub_473684
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_473684() {
    decomp_var_14 = ebx;
    decomp_var_18 = ebp;
    decomp_var_1c = esi;
    esp = esp - 0x20;
    decomp_var_20 = edi;
    ebx = 0x1;
    esi = ecx;
    var_C = 0x1;
    var_10 = 0x0;
    if ((arg_0 & 0x4) == 0x0 || (sub_476745() & 0x10000000) != 0x0) {
            ebx = 0x0;
    }
    esp = esp - 0x4;
    eax = GetParent(esi[0x8]);
    esi[0xf] = esi[0xf] | 0x18;
    var_4 = eax;
    var_8 = sub_46f31c();
    temp_0 = 0x10;
    goto .l8;

.l8:
    if (temp_0 != 0x10) {
            if (sub_46f714() != 0x0) {
                    if (ebx != 0x0) {
                            eax = var_4[0x1];
                            if (eax == 0x118 || eax == 0x104) {
                                    sub_476779(0x1);
                                    esp = esp - 0x8;
                                    decomp_var_20 = esi[0x8];
                                    UpdateWindow(decomp_var_20);
                                    ebx = 0x0;
                            }
                    }
                    if ((*(*esi + 0x80))() != 0x0) {
                            esp = (esp - 0x4) + 0x4;
                            if (sub_46f62e(var_4) != 0x0) {
                                    var_8 = 0x1;
                                    var_C = 0x0;
                            }
                            esp = esp - 0x14;
                            if (PeekMessageA(var_4, 0x0, 0x0, 0x0, 0x0) == 0x0) {
                                    temp_0 = 0x10;
                            }
                            else {
                                    temp_0 = 0x11;
                            }
                            continue;
                    }
                    esi[0xf] = esi[0xf] & 0xffffffe7;
                    eax = esi[0x11];
                    break;
            }
            else {
                    esp = esp - 0x4;
                    eax = sub_46e3eb();
                    eax = eax | 0xffffffff;
                    break;
            }
    }
    else {
            if (var_8 == 0x0) {
                    temp_0 = 0x11;
                    continue;
            }
            esp = esp - 0x14;
            if (PeekMessageA(var_4, 0x0, 0x0, 0x0, 0x0) == 0x0) {
                    if (ebx != 0x0) {
                            sub_476779(0x1);
                            esp = esp - 0x8;
                            decomp_var_20 = esi[0x8];
                            UpdateWindow(decomp_var_20);
                            ebx = 0x0;
                    }
                    if ((arg_4 & 0x1) == 0x0) {
                            edi = 0x0;
                            if (saved_fp != 0x0 && var_C == edi) {
                                    decomp_var_20 = esi[0x8];
                                    esp = esp - 0x10;
                                    SendMessageA(saved_fp, 0x121, edi, decomp_var_20);
                            }
                    }
                    if ((arg_4 & 0x2) == 0x0) {
                            edi = 0x0;
                            esp = esp - 0x10;
                            eax = SendMessageA(esi[0x8], 0x36a, 0x0, var_C);
                            var_C = var_C + 0x1;
                            if (eax == 0x0) {
                                    var_8 = edi;
                            }
                    }
                    else {
                            var_8 = 0x0;
                    }
                    temp_0 = 0x10;
                    continue;
            }
            if (sub_46f714() != 0x0) {
                    edi = 0x0;
                    if (ebx != 0x0) {
                            eax = var_4[0x1];
                            if (eax == 0x118 || eax == 0x104) {
                                    sub_476779(0x1);
                                    esp = esp - 0x8;
                                    decomp_var_20 = esi[0x8];
                                    UpdateWindow(decomp_var_20);
                                    ebx = 0x0;
                            }
                    }
                    if ((*(*esi + 0x80))() != 0x0) {
                            esp = (esp - 0x4) + 0x4;
                            if (sub_46f62e(var_4) != 0x0) {
                                    var_8 = 0x1;
                                    var_C = edi;
                            }
                            esp = esp - 0x14;
                            if (PeekMessageA(var_4, edi, edi, edi, edi) == 0x0) {
                                    temp_0 = 0x10;
                            }
                            else {
                                    temp_0 = 0x11;
                            }
                            continue;
                    }
                    esi[0xf] = esi[0xf] & 0xffffffe7;
                    eax = esi[0x11];
                    break;
            }
            else {
                    esp = esp - 0x4;
                    eax = sub_46e3eb();
                    eax = eax | 0xffffffff;
                    break;
            }
    }
    return eax;
}
