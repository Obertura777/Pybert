// sub_10005fb0 @ 0x10005fb0
// hopper name: sub_10005fb0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10005fb0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = arg_4;
    eax = *esi;
    if (eax != 0x0) {
            esp = esp - 0x4;
            decomp_var_8 = edi;
            do {
                    bool_3 = eax[0x3] != esi;
                    esi = eax;
                    if (!bool_3) {
                            sub_10006040(esi + 0xc);
                            edi = esi[0x3];
                            esp = (esp - 0x4) + 0x4;
                            eax = edi[0x8];
                            edi = edi[0x4];
                            bool_5 = eax > edi;
                            eax = sign_extend_32(eax);
                            if (!bool_5) {
                                    eax = sign_extend_32(edi);
                            }
                            esi[0x8] = eax + 0x1;
                    }
                    else {
                            sub_10006040(esi + 0x4);
                            edi = esi[0x1];
                            esp = (esp - 0x4) + 0x4;
                            eax = edi[0x8];
                            edi = edi[0x4];
                            bool_2 = eax > edi;
                            eax = sign_extend_32(eax);
                            if (!bool_2) {
                                    eax = sign_extend_32(edi);
                            }
                            esi[0x4] = eax + 0x1;
                    }
                    eax = *esi;
            } while (eax != 0x0);
            esp = esp + 0x4;
    }
    eax = esi[0x4];
    esp = esp + 0x4;
    if (eax != esi[0x8]) {
            eax = sub_10006040(arg_0 + 0x4);
    }
    return eax;
}
