// sub_48201a @ 0x48201a
// hopper name: sub_48201a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48201a() {
    decomp_var_14 = ebx;
    var_8 = 0x1;
    eax = sub_481280(0x355);
    esp = (esp - 0x18) + 0x4;
    var_4 = eax;
    if (eax != 0x0) {
            decomp_var_18 = ebp;
            decomp_var_1c = edi;
            edi = eax + 0x4;
            *(int8_t *)edi = 0x0;
            *eax = 0x1;
            var_C = 0x1;
            ebx = &arg_44;
            decomp_var_20 = *ebx;
            decomp_var_24 = 0x4b3b54;
            sub_481e48(edi, 0x351, 0x3);
            esp = (esp - 0x20) + 0x18;
            var_10 = dword_value_4930152;
            do {
                    esp = (esp - 0xc) + 0xc;
                    if (sub_47f557(edi, 0x351, 0x4b3790) != 0x0) {
                            decomp_var_20 = 0x0;
                            decomp_var_24 = 0x0;
                            sub_47a828();
                            esp = (esp - 0x14) + 0x14;
                    }
                    esp = (esp - 0x8) + 0x8;
                    if (sub_47fd80(*ebx, arg_54) != 0x0) {
                            var_8 = var_8 & 0x0;
                    }
                    var_C = var_C + 0x1;
                    var_10 = var_10 + 0xc;
                    ebx = &arg_44;
                    decomp_var_20 = *ebx;
                    decomp_var_24 = 0x4b3b54;
                    sub_481e48(edi, 0x351, 0x3);
                    esp = (esp - 0x18) + 0x18;
            } while (var_10 < 0x4b3abc);
            if (var_8 == 0x0) {
                    eax = esi[0x14];
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            if (InterlockedDecrement(eax) == 0x0) {
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                    }
                    eax = esi[0x15];
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            if (InterlockedDecrement(eax) == 0x0) {
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                    }
                    esi[0x14] = var_4;
                    esi[0x12] = edi;
            }
            else {
                    sub_47c8f9();
                    eax = esi[0x14];
                    esp = (esp - 0x4) + 0x4;
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            if (InterlockedDecrement(eax) == 0x0) {
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                    }
                    eax = esi[0x15];
                    if (eax != 0x0) {
                            esp = esp - 0x4;
                            if (InterlockedDecrement(eax) == 0x0) {
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                            }
                    }
                    esi[0x14] = 0x0;
                    esi[0x12] = 0x0;
            }
            esi[0x13] = 0x0;
            esi[0x15] = 0x0;
            esp = esp + 0x8;
    }
    return;
}
