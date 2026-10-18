// sub_430480 @ 0x430480
// hopper name: sub_430480
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_430480() {
    edx = ecx[0x1];
    eax = edx[0x1];
    decomp_var_c = ebp;
    ebp = arg_4;
    esp = esp - 0x10;
    esi = edx;
    var_8 = 0x1;
    if (eax[0xe9] == 0x0) {
            esp = esp - 0x4;
            edi = *ebp;
            do {
                    bool_2 = edi < eax[0x4];
                    esi = eax;
                    var_8 = bool_2 ? 0x1 : 0x0;
                    if ((bool_2 ? 0x1 : 0x0) != 0x0) {
                            eax = *eax;
                    }
                    else {
                            eax = eax[0x2];
                    }
            } while (eax[0xe9] == 0x0);
            esp = esp + 0x4;
    }
    eax = sub_42e450(&saved_fp, saved_fp, esi, ebp, var_8, decomp_var_4, saved_fp, arg_0, arg_4);
    ecx = eax;
    edx = *ecx;
    eax = arg_8;
    ecx = ecx[0x1];
    *eax = edx;
    eax[0x1] = ecx;
    eax[0x8] = 0x1;
    return eax;
}
