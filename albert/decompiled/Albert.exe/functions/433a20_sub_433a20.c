// sub_433a20 @ 0x433a20
// hopper name: sub_433a20
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_84a29276878deed2f6f82f4902efd1af3068bd2f0c5f74171e6c8513865ea0d2
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_433a20() {
    decomp_var_10 = ebp;
    ebp = arg_4;
    esp = esp - 0x18;
    edi = ecx;
    esi = edi[0x1];
    eax = esi[0x1];
    ecx = 0x1;
    var_C = 0x1;
    if (eax[0x31] == 0x0) {
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
            } while (eax[0x31] == 0x0);
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
                    ecx = sub_430990(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, decomp_var_8, var_4, saved_fp);
                    edx = *ecx;
                    eax = arg_8;
                    ecx = ecx[0x1];
                    *eax = edx;
                    eax[0x1] = ecx;
                    eax[0x8] = 0x1;
            }
            else {
                    sub_40e280();
                    edx = arg_0;
                    if (edx[0x3] < *ebp) {
                            decomp_var_14 = ebp;
                            decomp_var_18 = esi;
                            decomp_var_1c = var_4;
                            esp = esp - 0x10;
                            decomp_var_20 = &saved_fp;
                            ecx = sub_430990(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, decomp_var_8, var_4, saved_fp);
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
                    ecx = sub_430990(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, decomp_var_8, var_4, saved_fp);
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
