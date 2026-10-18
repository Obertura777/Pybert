// sub_46ece9 @ 0x46ece9
// hopper name: sub_46ece9
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46ece9() {
    ecx = arg_4;
    if (ecx == 0x0) {
            sub_46dedc();
    }
    eax = arg_1c;
    esp = esp - 0x4;
    decomp_var_8 = ebx;
    ebx = 0x1;
    if (eax != 0x0) {
            *eax = ecx;
            eax[0x1] = arg_10;
    }
    else {
            eax = arg_18 - 0x38;
            esp = esp - 0x4;
            switch (*(eax * 0x4 + switch_table)) {
                case 0:
                    (arg_10)();
                    esp = esp + 0x4;
                    break;
                case 1:
                    eax = (arg_10)();
                    ebx = eax;
                    esp = esp + 0x4;
                    break;
                case 2:
                    esp = esp - 0x4;
                    decomp_var_10 = arg_8;
                    (arg_10)(decomp_var_10);
                    esp = esp + 0x4;
                    break;
                case 3:
                    esp = esp - 0x4;
                    decomp_var_10 = arg_8;
                    eax = (arg_10)(decomp_var_10);
                    ebx = eax;
                    esp = esp + 0x4;
                    break;
                case 4:
                    eax = arg_14;
                    if (eax == 0x0) {
                            sub_46dedc();
                    }
                    decomp_var_10 = *eax;
                    esp = esp - 0x8;
                    (arg_10)(eax[0x1], decomp_var_10);
                    esp = esp + 0x4;
                    break;
                case 5:
                    eax = arg_14;
                    if (eax == 0x0) {
                            sub_46dedc();
                    }
                    decomp_var_10 = *eax;
                    esp = esp - 0x8;
                    eax = (arg_10)(eax[0x1], decomp_var_10);
                    ebx = eax;
                    esp = esp + 0x4;
                    break;
                case 6:
                    eax = arg_14;
                    if (eax == 0x0) {
                            sub_46dedc();
                    }
                    decomp_var_10 = *eax;
                    esp = esp - 0xc;
                    (arg_10)(arg_8, eax[0x1], decomp_var_10);
                    esp = esp + 0x4;
                    break;
                case 7:
                    eax = arg_14;
                    if (eax == 0x0) {
                            sub_46dedc();
                    }
                    decomp_var_10 = *eax;
                    esp = esp - 0xc;
                    eax = (arg_10)(arg_8, eax[0x1], decomp_var_10);
                    ebx = eax;
                    esp = esp + 0x4;
                    break;
                case 8:
                    esi = arg_14;
                    if (esi == 0x0) {
                            sub_46dedc();
                    }
                    esp = esp - 0x4;
                    decomp_var_10 = esi;
                    (arg_10)(decomp_var_10);
                    ebx = esi[0x7] == 0x0 ? 0x1 : 0x0;
                    esi[0x7] = esi[0x7] & 0x0;
                    esp = esp + 0x4;
                    break;
                case 9:
                    esi = arg_14;
                    if (esi == 0x0) {
                            sub_46dedc();
                    }
                    decomp_var_10 = arg_8;
                    esp = esp - 0x8;
                    (arg_10)(esi, decomp_var_10);
                    ebx = esi[0x7] == 0x0 ? 0x1 : 0x0;
                    esi[0x7] = esi[0x7] & 0x0;
                    esp = esp + 0x4;
                    break;
                default:
                    if (*(eax * 0x4 + switch_table) != 0xa) {
                            esp = esp - 0x4;
                            decomp_var_10 = arg_14;
                            eax = (arg_10)(decomp_var_10);
                            ebx = eax;
                    }
                    else {
                            esp = esp - 0x4;
                            decomp_var_10 = arg_14;
                            (arg_10)(decomp_var_10);
                    }
                    esp = esp + 0x4;
                    break;
                default:
                    esp = esp + 0x4;
            }
    }
    return;
}
