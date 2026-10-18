// sub_4761e0 @ 0x4761e0
// hopper name: sub_4761e0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4761e0() {
    decomp_var_38 = esi;
    esi = arg_0;
    esp = esp - 0x8;
    decomp_var_3c = edi;
    edi = ecx;
    var_8 = edi;
    var_4 = 0x1;
    if (esi != 0x0) {
            esp = esp - 0x4;
            while (true) {
                    eax = *(int16_t *)esi & 0xffff;
                    if (eax == 0x0) {
                            break;
                    }
                    ecx = eax & 0xffff;
                    eax = *(int16_t *)(esi + 0x2) & 0xffff;
                    edx = *(esi + 0x4);
                    esi = esi + 0x8;
                    bool_19 = true;
                    var_C = ecx;
                    var_10 = edx;
                    if (eax == 0x1234) {
                            esp = (esp - 0x4) + 0x4;
                            asm { rep stosd  dword [edi], eax };
                            var_30 = var_30 | 0xffffffff;
                            var_34 = 0x1;
                            sub_40bba0();
                            esp = esp - 0x18;
                            eax = SendDlgItemMessageA(var_8[0x8], var_C & 0xffff, 0x401, 0x0, &var_34);
                            if (eax == 0xffffffff) {
                                    var_4 = var_4 & 0x0;
                            }
                            sub_40b670();
                            edi = var_8;
                            esi = esi + var_10;
                            if (var_4 != 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (eax == 0x401) {
                            esp = esp - 0x14;
                            if (SendDlgItemMessageA(edi[0x8], ecx & 0xffff, 0x180 & 0xffff, 0x0, esi) == 0xffffffff) {
                                    var_4 = var_4 & 0x0;
                            }
                            esi = esi + var_10;
                            if (var_4 != 0x0) {
                                    continue;
                            }
                            break;
                    }
                    else {
                            if (eax == 0x403) {
                                    eax = 0x143;
                            }
                            bool_15 = true;
                            if (eax == 0x401) {
                                    esp = (esp - 0x4) + 0x4;
                                    asm { rep stosd  dword [edi], eax };
                                    var_30 = var_30 | 0xffffffff;
                                    var_34 = 0x1;
                                    sub_40bba0();
                                    esp = esp - 0x18;
                                    eax = SendDlgItemMessageA(var_8[0x8], var_C & 0xffff, 0x401, 0x0, &var_34);
                                    if (eax == 0xffffffff) {
                                            var_4 = var_4 & 0x0;
                                    }
                                    sub_40b670();
                                    edi = var_8;
                                    esi = esi + var_10;
                                    if (var_4 != 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (eax != 0x180) {
                                            if (eax == 0x143) {
                                                    esp = esp - 0x14;
                                                    if (SendDlgItemMessageA(edi[0x8], ecx & 0xffff, eax & 0xffff, 0x0, esi) == 0xffffffff) {
                                                            var_4 = var_4 & 0x0;
                                                    }
                                                    esi = esi + var_10;
                                                    if (var_4 != 0x0) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    esi = esi + var_10;
                                                    if (var_4 != 0x0) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            esp = esp - 0x14;
                                            if (SendDlgItemMessageA(edi[0x8], ecx & 0xffff, eax & 0xffff, 0x0, esi) == 0xffffffff) {
                                                    var_4 = var_4 & 0x0;
                                            }
                                            esi = esi + var_10;
                                            if (var_4 != 0x0) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                    }
            }
            esp = esp + 0x4;
            if (var_4 != 0x0) {
                    esp = esp - 0x18;
                    sub_4743dc(edi[0x8], 0x364, 0x0, 0x0, 0x0, 0x0);
                    eax = var_4;
            }
            else {
                    eax = var_4;
            }
    }
    else {
            esp = esp - 0x18;
            sub_4743dc(edi[0x8], 0x364, 0x0, 0x0, 0x0, 0x0);
            eax = var_4;
    }
    return eax;
}
