// sub_419300 @ 0x419300
// hopper name: sub_419300
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_419300() {
    decomp_var_10 = ebx;
    ebx = arg_4;
    decomp_var_14 = ebp;
    ebp = ecx;
    esp = esp - 0x1c;
    edi = arg_0;
    esi = edi[0x1];
    eax = 0x1;
    var_C = 0x1;
    if (esi[0x1d] == 0x0) {
            do {
                    esp = esp - 0x4;
                    edi = esi;
                    eax = sub_465cf0(esi + 0xc);
                    var_C = eax;
                    if (eax != 0x0) {
                            esi = *esi;
                    }
                    else {
                            esi = esi[0x2];
                    }
            } while (esi[0x1d] == 0x0);
    }
    esi = edi;
    arg_0 = esi;
    saved_fp = ebp;
    if (eax != 0x0) {
            if (edi == *arg_0) {
                    eax = sub_4134d0(&saved_fp, 0x1, edi, ebx, decomp_var_14, decomp_var_10, var_C, decomp_var_8, var_4);
                    ecx = eax;
                    edx = *ecx;
                    eax = arg_8;
                    eax[0x1] = ecx[0x1];
                    eax[0x8] = 0x1;
                    *eax = edx;
            }
            else {
                    sub_401790();
                    esi = arg_0;
                    esp = esp - 0x4;
                    if (sub_465cf0(ebx) != 0x0) {
                            eax = sub_4134d0(&saved_fp, var_4, edi, ebx, decomp_var_14, decomp_var_10, var_C, decomp_var_8, var_4);
                            ecx = eax;
                            edx = *ecx;
                            eax = arg_8;
                            eax[0x1] = ecx[0x1];
                            eax[0x8] = 0x1;
                            *eax = edx;
                    }
                    else {
                            eax = arg_8;
                            eax[0x1] = esi;
                            eax[0x8] = 0x0;
                            *eax = saved_fp;
                    }
            }
    }
    else {
            esp = esp - 0x4;
            if (sub_465cf0(ebx) != 0x0) {
                    eax = sub_4134d0(&saved_fp, var_4, edi, ebx, decomp_var_14, decomp_var_10, var_C, decomp_var_8, var_4);
                    ecx = eax;
                    edx = *ecx;
                    eax = arg_8;
                    eax[0x1] = ecx[0x1];
                    eax[0x8] = 0x1;
                    *eax = edx;
            }
            else {
                    eax = arg_8;
                    eax[0x1] = esi;
                    eax[0x8] = 0x0;
                    *eax = saved_fp;
            }
    }
    return eax;
}
