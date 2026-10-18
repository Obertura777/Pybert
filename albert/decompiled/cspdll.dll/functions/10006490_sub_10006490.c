// sub_10006490 @ 0x10006490
// hopper name: sub_10006490
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10006490() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    edi = malloc(0x8);
    esp = (esp - 0x10) + 0x4;
    if (edi != 0x0) {
            esi = arg_4;
            eax = malloc(esi * 0x8 - esi << 0x2, decomp_var_8, decomp_var_4);
            esp = (esp - 0x4) + 0x4;
            if (eax != 0x0) {
                    *edi = esi;
                    edi[0x1] = eax;
                    if (esi > 0x0) {
                            do {
                                    eax[0x2] = 0x0;
                                    *eax = eax;
                                    eax[0x1] = eax;
                                    eax = eax + 0x1c;
                                    esi = esi - 0x1;
                            } while (esi != 0x0);
                    }
                    eax = edi;
            }
            else {
                    free(edi);
                    eax = 0x0;
            }
    }
    else {
            eax = edi;
    }
    return eax;
}
