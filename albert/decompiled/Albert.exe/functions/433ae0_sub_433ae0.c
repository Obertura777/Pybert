// sub_433ae0 @ 0x433ae0
// hopper name: sub_433ae0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_84a29276878deed2f6f82f4902efd1af3068bd2f0c5f74171e6c8513865ea0d2
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_433ae0() {
    var_C = *0x0;
    decomp_var_40 = ebx;
    decomp_var_44 = ebp;
    decomp_var_48 = esi;
    decomp_var_4c = edi;
    decomp_var_50 = *dword_4c8db8 ^ &decomp_var_4c;
    *0x0 = &var_C;
    ebp = ecx;
    var_3C = ebp;
    edi = arg_0;
    esp = esp - 0x54;
    esi = sub_40eee0(edi);
    if (ebp == 0x0) {
            sub_47a948();
    }
    if (esi != arg_0) {
            eax = *edi;
            ecx = esi[0x3];
            bool_13 = eax != ecx;
            if (eax >= ecx) {
                    if (!bool_13) {
                            if (edi[0x2] < esi[0x8]) {
                                    eax = sub_410370();
                                    var_28 = eax;
                                    eax[0x39] = 0x1;
                                    var_28[0x1] = var_28;
                                    *var_28 = var_28;
                                    var_28[0x2] = var_28;
                                    var_20 = *edi;
                                    sub_422460(&var_2C);
                                    eax = sub_430b90(&var_34, ebp, esi, &var_20);
                                    ebp = *eax;
                                    esi = eax[0x1];
                                    sub_41aa20(&var_3C, &var_18, *var_14, &var_18, var_14);
                                    sub_47c8f9();
                                    sub_41aa20(&var_3C, &var_2C, *var_28, &var_2C, var_28);
                                    sub_47c8f9();
                                    esp = ((esp - 0x2c) + 0x4 - 0x18) + 0x4;
                                    if (ebp == 0x0) {
                                            sub_47a948();
                                    }
                                    if (esi == arg_0) {
                                            sub_47a948();
                                    }
                                    eax = esi + 0x14;
                                    *0x0 = var_C;
                            }
                            else {
                                    if (ebp == 0x0) {
                                            sub_47a948();
                                    }
                                    if (esi == arg_0) {
                                            sub_47a948();
                                    }
                                    eax = esi + 0x14;
                                    *0x0 = var_C;
                            }
                    }
                    else {
                            if (ebp == 0x0) {
                                    sub_47a948();
                            }
                            if (esi == arg_0) {
                                    sub_47a948();
                            }
                            eax = esi + 0x14;
                            *0x0 = var_C;
                    }
            }
            else {
                    eax = sub_410370();
                    var_28 = eax;
                    eax[0x39] = 0x1;
                    var_28[0x1] = var_28;
                    *var_28 = var_28;
                    var_28[0x2] = var_28;
                    var_20 = *edi;
                    sub_422460(&var_2C);
                    eax = sub_430b90(&var_34, ebp, esi, &var_20);
                    ebp = *eax;
                    esi = eax[0x1];
                    sub_41aa20(&var_3C, &var_18, *var_14, &var_18, var_14);
                    sub_47c8f9();
                    sub_41aa20(&var_3C, &var_2C, *var_28, &var_2C, var_28);
                    sub_47c8f9();
                    esp = ((esp - 0x2c) + 0x4 - 0x18) + 0x4;
                    if (ebp == 0x0) {
                            sub_47a948();
                    }
                    if (esi == arg_0) {
                            sub_47a948();
                    }
                    eax = esi + 0x14;
                    *0x0 = var_C;
            }
    }
    else {
            eax = sub_410370();
            var_28 = eax;
            eax[0x39] = 0x1;
            var_28[0x1] = var_28;
            *var_28 = var_28;
            var_28[0x2] = var_28;
            var_20 = *edi;
            sub_422460(&var_2C);
            eax = sub_430b90(&var_34, ebp, esi, &var_20);
            ebp = *eax;
            esi = eax[0x1];
            sub_41aa20(&var_3C, &var_18, *var_14, &var_18, var_14);
            sub_47c8f9();
            sub_41aa20(&var_3C, &var_2C, *var_28, &var_2C, var_28);
            sub_47c8f9();
            esp = ((esp - 0x2c) + 0x4 - 0x18) + 0x4;
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (esi == arg_0) {
                    sub_47a948();
            }
            eax = esi + 0x14;
            *0x0 = var_C;
    }
    return eax;
}
