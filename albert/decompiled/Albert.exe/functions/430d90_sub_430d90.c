// sub_430d90 @ 0x430d90
// hopper name: sub_430d90
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_430d90() {
    decomp_var_4 = ebx;
    eax = arg_0[0x1];
    decomp_var_8 = esi;
    decomp_var_c = edi;
    esi = ecx;
    edi = esi[0x1];
    esp = esp - 0x14;
    edi[0x1] = sub_4307f0(eax[0x1], edi);
    ecx = arg_0[0x2];
    edx = esi[0x1];
    esi[0x2] = ecx;
    eax = edx[0x1];
    if (eax[0x31] == 0x0) {
            ecx = *eax;
            if (ecx[0x31] == 0x0) {
                    eax = ecx;
                    ecx = *eax;
                    if (ecx[0x31] == 0x0) {
                            continue;
                    }
                    break;
            }
            *edx = eax;
            esi = esi[0x1];
            ecx = esi[0x1];
            eax = ecx[0x2];
            if (eax[0x31] == 0x0) {
                    do {
                            ecx = eax;
                            eax = ecx[0x2];
                    } while (eax[0x31] == 0x0);
            }
            esi[0x2] = ecx;
    }
    else {
            *edx = edx;
            esi = esi[0x1];
            esi[0x2] = esi;
    }
    return eax;
}
