// sub_45ea80 @ 0x45ea80
// hopper name: sub_45ea80
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45ea80() {
    ebx = arg_4;
    esp = esp - 0x1c;
    edi = ecx;
    eax = edi[0x1];
    esi = eax[0x1];
    ebp = eax;
    eax = 0x1;
    if (esi[0x2d] == 0x0) {
            do {
                    bool_14 = esi[0x9] < 0x10;
                    ebp = esi[0x8];
                    arg_4 = esi;
                    if (!bool_14) {
                            edx = esi[0x4];
                    }
                    else {
                            edx = esi + 0x10;
                    }
                    edi = ebx[0x5];
                    ecx = edi;
                    if (edi >= ebp) {
                            ecx = ebp;
                    }
                    if (ebx[0x6] >= 0x10) {
                            eax = ebx[0x1];
                    }
                    else {
                            eax = ebx + 0x4;
                    }
                    eax = sub_40cd30(eax, edx, ecx);
                    esp = (esp - 0xc) + 0xc;
                    bool_9 = eax < 0x0;
                    if (eax == 0x0) {
                    }
                    eax = bool_9 ? 0x1 : 0x0;
                    arg_8 = eax;
                    if (eax != 0x0) {
                            esi = *esi;
                    }
                    else {
                            esi = esi[0x2];
                    }
            } while (esi[0x2d] == 0x0);
            edi = arg_14;
            ebp = arg_24;
    }
    esi = ebp;
    arg_18 = esi;
    arg_14 = edi;
    if (eax != 0x0) {
            ecx = &arg_14;
            if (ebp == *edi[0x1]) {
                    saved_fp = ebx;
                    decomp_var_4 = ebp;
                    esp = esp - 0xc;
                    var_8 = 0x1;
                    ecx = sub_45e620(ecx, var_8, decomp_var_4, saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10);
                    edx = *ecx;
                    eax = arg_20;
                    eax[0x1] = ecx[0x1];
                    eax[0x8] = 0x1;
                    *eax = edx;
            }
            else {
                    sub_40f920();
                    esi = arg_18;
                    bool_6 = ebx[0x6] < 0x10;
                    edx = ebx[0x5];
                    ecx = esi + 0xc;
                    if (!bool_6) {
                            eax = ebx[0x1];
                    }
                    else {
                            eax = ebx + 0x4;
                    }
                    arg_4 = edx;
                    arg_0 = eax;
                    saved_fp = ecx[0x5];
                    esp = esp - 0x10;
                    decomp_var_4 = 0x0;
                    if (sub_40e9b0() < 0x0) {
                            var_8 = ebx;
                            esp = esp - 0xc;
                            ecx = &arg_c;
                            ecx = sub_45e620(ecx, var_8, decomp_var_4, saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10);
                            edx = *ecx;
                            eax = arg_20;
                            eax[0x1] = ecx[0x1];
                            eax[0x8] = 0x1;
                            *eax = edx;
                    }
                    else {
                            eax = arg_18;
                            eax[0x1] = esi;
                            eax[0x8] = 0x0;
                            *eax = arg_c;
                    }
            }
    }
    else {
            bool_2 = ebx[0x6] < 0x10;
            edx = ebx[0x5];
            ecx = esi + 0xc;
            if (!bool_2) {
                    eax = ebx[0x1];
            }
            else {
                    eax = ebx + 0x4;
            }
            arg_4 = edx;
            arg_0 = eax;
            saved_fp = ecx[0x5];
            esp = esp - 0x10;
            decomp_var_4 = 0x0;
            if (sub_40e9b0() < 0x0) {
                    var_8 = ebx;
                    esp = esp - 0xc;
                    ecx = &arg_c;
                    ecx = sub_45e620(ecx, var_8, decomp_var_4, saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10);
                    edx = *ecx;
                    eax = arg_20;
                    eax[0x1] = ecx[0x1];
                    eax[0x8] = 0x1;
                    *eax = edx;
            }
            else {
                    eax = arg_18;
                    eax[0x1] = esi;
                    eax[0x8] = 0x0;
                    *eax = arg_c;
            }
    }
    return eax;
}
