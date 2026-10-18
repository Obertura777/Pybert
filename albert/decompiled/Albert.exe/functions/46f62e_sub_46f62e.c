// sub_46f62e @ 0x46f62e
// hopper name: sub_46f62e
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46f62e() {
    ecx = *(sub_4715ed() + 0x4);
    if (ecx != 0x0) {
            eax = *ecx;
            eax = (eax[0x19])(arg_0);
    }
    else {
            esp = esp - 0x4;
            decomp_var_4 = esi;
            esi = arg_0;
            eax = esi[0x1];
            switch (eax) {
                case 512:
                    decomp_var_8 = ebx;
                    decomp_var_c = edi;
                    ebx = sub_471099();
                    esp = esp - 0x10;
                    edi = ebx + 0x4c;
                    if (sub_46f520(esi[0x5], esi[0x6]) != 0x0) {
                            if (esi[0x1] == ebx[0x15]) {
                                    eax = 0x0;
                            }
                            else {
                                    *edi = esi[0x5];
                                    edi[0x1] = esi[0x6];
                                    ebx[0x15] = esi[0x1];
                                    eax = 0x1;
                            }
                    }
                    else {
                            *edi = esi[0x5];
                            edi[0x1] = esi[0x6];
                            ebx[0x15] = esi[0x1];
                            eax = 0x1;
                    }
                    break;
                case 160:
                    decomp_var_8 = ebx;
                    decomp_var_c = edi;
                    ebx = sub_471099();
                    esp = esp - 0x10;
                    edi = ebx + 0x4c;
                    if (sub_46f520(esi[0x5], esi[0x6]) != 0x0) {
                            if (esi[0x1] == ebx[0x15]) {
                                    eax = 0x0;
                            }
                            else {
                                    *edi = esi[0x5];
                                    edi[0x1] = esi[0x6];
                                    ebx[0x15] = esi[0x1];
                                    eax = 0x1;
                            }
                    }
                    else {
                            *edi = esi[0x5];
                            edi[0x1] = esi[0x6];
                            ebx[0x15] = esi[0x1];
                            eax = 0x1;
                    }
                    break;
                case 15:
                    eax = 0x0;
                    break;
                case 280:
                    eax = 0x0;
                    break;
                default:
                    eax = 0x1;
                    break;
            }
    }
    return eax;
}
