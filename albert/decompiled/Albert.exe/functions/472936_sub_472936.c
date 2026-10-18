// sub_472936 @ 0x472936
// hopper name: sub_472936
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_472936() {
    esi = arg_4;
    esp = esp - 0x4;
    decomp_var_10 = edi;
    if (esi == 0x0) {
            sub_46dedc();
    }
    esp = esp - 0x4;
    decomp_var_14 = esi[0x1];
    eax = GetMenuItemCount(decomp_var_14);
    edi = 0x0;
    arg_4 = eax;
    if (eax > 0x0) {
            ebx = arg_8;
            while (true) {
                    esp = esp - 0x4;
                    decomp_var_14 = edi;
                    eax = sub_472789(decomp_var_14);
                    if (eax != 0x0) {
                            if (eax[0x1] != ebx) {
                                    decomp_var_14 = ebx;
                                    esp = esp - 0x8;
                                    decomp_var_18 = eax;
                                    if (sub_472936() == 0x0) {
                                            edi = edi + 0x1;
                                            if (edi < arg_4) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    else {
                                            temp_0 = 0x0;
                                            break;
                                    }
                            }
                            else {
                                    temp_0 = 0x2;
                                    break;
                            }
                    }
                    else {
                            decomp_var_14 = edi;
                            esp = esp - 0x8;
                            decomp_var_18 = esi[0x1];
                            if (GetMenuItemID(decomp_var_18, decomp_var_14) != ebx) {
                                    edi = edi + 0x1;
                                    if (edi < arg_4) {
                                            continue;
                                    }
                                    temp_0 = 0x1;
                                    break;
                            }
                            else {
                                    temp_0 = 0x2;
                                    break;
                            }
                    }
            }
            if (temp_0 != 0x0 && temp_0 != 0x1) {
                    esp = esp - 0x4;
                    decomp_var_14 = esi[0x1];
                    sub_479661();
            }
    }
    return;
}
