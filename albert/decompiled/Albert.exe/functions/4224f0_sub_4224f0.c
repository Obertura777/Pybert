// sub_4224f0 @ 0x4224f0
// hopper name: sub_4224f0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4224f0() {
    decomp_var_10 = ebp;
    ebp = arg_4;
    esp = esp - 0x18;
    edi = ecx;
    esi = edi[0x1];
    eax = esi[0x1];
    ecx = 0x1;
    var_C = 0x1;
    if (eax[0x2d] == 0x0) {
            edx = *(int16_t *)ebp & 0xffff;
            do {
                    esi = eax;
                    ecx = edx < eax[0x6] ? 0x1 : 0x0;
                    var_C = ecx;
                    if (ecx != 0x0) {
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0x2d] == 0x0);
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
                    ecx = sub_41c940(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, decomp_var_8, var_4, saved_fp);
                    edx = *ecx;
                    eax = arg_8;
                    ecx = ecx[0x1];
                    *eax = edx;
                    eax[0x1] = ecx;
                    eax[0x8] = 0x1;
            }
            else {
                    sub_40f920();
                    edx = arg_0;
                    if (edx[0x6] < *(int16_t *)ebp) {
                            decomp_var_14 = ebp;
                            decomp_var_18 = esi;
                            decomp_var_1c = var_4;
                            esp = esp - 0x10;
                            decomp_var_20 = &saved_fp;
                            ecx = sub_41c940(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, decomp_var_8, var_4, saved_fp);
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
            if (edx[0x6] < *(int16_t *)ebp) {
                    decomp_var_14 = ebp;
                    decomp_var_18 = esi;
                    decomp_var_1c = var_4;
                    esp = esp - 0x10;
                    decomp_var_20 = &saved_fp;
                    ecx = sub_41c940(decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, decomp_var_8, var_4, saved_fp);
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
