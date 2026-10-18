// sub_100067a0 @ 0x100067a0
// hopper name: sub_100067a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100067a0() {
    decomp_var_8 = ebx;
    esp = esp - 0xc;
    decomp_var_c = ebp;
    ebp = arg_0;
    ebx = 0x0;
    var_4 = 0x0;
    if (*ebp > 0x0) {
            esp = esp - 0x8;
            do {
                    eax = *(ebx + arg_0);
                    if (eax != ebx + arg_0) {
                            do {
                                    esi = eax[0x2];
                                    *(*esi + 0x4) = esi[0x1];
                                    *esi[0x1] = *esi;
                                    edx = esi[0x3];
                                    *esi = 0x0;
                                    esi[0x1] = 0x0;
                                    free(edx);
                                    eax = esi[0x5];
                                    esi[0x3] = 0x0;
                                    free(eax);
                                    esi[0x5] = 0x0;
                                    esp = (esp - 0x8) + 0x8;
                                    eax = *(arg_0 + ebx);
                            } while (eax != arg_0 + ebx);
                    }
                    ebx = ebx + 0x1c;
                    bool_1 = arg_0 + 0x1 < *ebp;
                    arg_0 = arg_0 + 0x1;
            } while (bool_1);
            esp = esp + 0x8;
    }
    return;
}
