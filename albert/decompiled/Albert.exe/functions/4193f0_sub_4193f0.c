// sub_4193f0 @ 0x4193f0
// hopper name: sub_4193f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4193f0() {
    decomp_var_10 = ebp;
    ebp = arg_4;
    esp = esp - 0x18;
    edi = ecx;
    esi = edi[0x1];
    eax = esi[0x1];
    ecx = 0x1;
    var_C = 0x1;
    if (eax[0x19] == 0x0) {
            edx = *ebp;
            do {
                    esi = eax;
                    ecx = edx < eax[0x3] ? 0x1 : 0x0;
                    var_C = ecx;
                    if (ecx != 0x0) {
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x19] == 0x0);
    }
    edx = esi;
    arg_0 = edx;
    saved_fp = edi;
    if (ecx != 0x0) {
            ecx = &saved_fp;
            if (esi == *edi[0x1]) {
                    decomp_var_14 = ebp;
                    decomp_var_18 = esi;
                    decomp_var_1c = 0x1;
                    esp = esp - 0x10;
                    decomp_var_20 = ecx;
                    ecx = sub_4136d0(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, decomp_var_8, var_4, saved_fp);
                    edx = *ecx;
                    eax = arg_8;
                    ecx = ecx[0x1];
                    *eax = edx;
                    eax[0x1] = ecx;
                    eax[0x8] = 0x1;
            }
            else {
                    sub_40e5f0();
                    edx = arg_0;
                    if (edx[0x3] < *ebp) {
                            decomp_var_14 = ebp;
                            decomp_var_18 = esi;
                            decomp_var_1c = var_4;
                            esp = esp - 0x10;
                            decomp_var_20 = &saved_fp;
                            ecx = sub_4136d0(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, decomp_var_8, var_4, saved_fp);
                            edx = *ecx;
                            eax = arg_8;
                            ecx = ecx[0x1];
                            *eax = edx;
                            eax[0x1] = ecx;
                            eax[0x8] = 0x1;
                    }
                    else {
                            eax = arg_8;
                            *eax = saved_fp;
                            eax[0x1] = edx;
                            eax[0x8] = 0x0;
                    }
            }
    }
    else {
            if (edx[0x3] < *ebp) {
                    decomp_var_14 = ebp;
                    decomp_var_18 = esi;
                    decomp_var_1c = var_4;
                    esp = esp - 0x10;
                    decomp_var_20 = &saved_fp;
                    ecx = sub_4136d0(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, decomp_var_8, var_4, saved_fp);
                    edx = *ecx;
                    eax = arg_8;
                    ecx = ecx[0x1];
                    *eax = edx;
                    eax[0x1] = ecx;
                    eax[0x8] = 0x1;
            }
            else {
                    eax = arg_8;
                    *eax = saved_fp;
                    eax[0x1] = edx;
                    eax[0x8] = 0x0;
            }
    }
    return eax;
}
