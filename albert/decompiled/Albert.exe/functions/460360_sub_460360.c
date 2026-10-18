// sub_460360 @ 0x460360
// hopper name: sub_460360
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_460360() {
    edx = ecx[0x1];
    eax = edx[0x1];
    esp = esp - 0x18;
    edi = arg_4;
    if (eax[0x29] == 0x0) {
            esi = *edi;
            do {
                    if (eax[0x3] < esi) {
                            eax = eax[0x2];
                    }
                    else {
                            edx = eax;
                            eax = *eax;
                    }
            } while (eax[0x29] == 0x0);
    }
    eax = ecx[0x1];
    var_4 = edx;
    var_8 = ecx;
    if (edx != eax && *edi >= edx[0x3]) {
            ecx = &var_8;
    }
    else {
            saved_fp = ecx;
            ecx = &saved_fp;
    }
    edx = *ecx;
    eax = arg_10;
    ecx = ecx[0x1];
    *eax = edx;
    eax[0x1] = ecx;
    return eax;
}
