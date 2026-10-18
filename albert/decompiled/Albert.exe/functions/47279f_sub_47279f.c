// sub_47279f @ 0x47279f
// hopper name: sub_47279f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47279f() {
    esp = esp - 0x4;
    esi = arg_0;
    if (esi != 0x7fffffff) {
            eax = 0x7fffffff;
            edx = *ecx;
            if (edx != 0x7fffffff) {
                    if (edx != esi) {
                            eax = 0x7fffffff;
                            sub_46dedc();
                    }
                    *ecx = esi;
                    eax = 0x7fffffff;
                    ecx = *ecx;
                    if (ecx == 0x7fffffff) {
                            sub_46dedc();
                    }
                    eax = sub_478104();
            }
            else {
                    *ecx = esi;
                    ecx = *ecx;
                    if (ecx == 0x7fffffff) {
                            sub_46dedc();
                    }
                    eax = sub_478104();
            }
    }
    else {
            ecx = *ecx;
            if (ecx == 0x7fffffff) {
                    eax = 0x7fffffff;
                    sub_46dedc();
            }
            eax = sub_478104();
    }
    return eax;
}
