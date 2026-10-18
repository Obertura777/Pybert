// sub_10006040 @ 0x10006040
// hopper name: sub_10006040
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10006040() {
    decomp_var_4 = esi;
    esi = arg_0;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    eax = *esi;
    ecx = sign_extend_32(eax[0x4]);
    edx = sign_extend_32(eax[0x8]);
    if (edx > ecx + 0x1) {
            ecx = eax + 0xc;
            eax = eax[0x3];
            if (eax[0x4] > eax[0x8]) {
                    sub_10006110(ecx);
                    esp = (esp - 0x4) + 0x4;
            }
            eax = sub_100060b0(esi);
    }
    else {
            if (ecx > edx + 0x1) {
                    ecx = eax + 0x4;
                    eax = eax[0x1];
                    if (eax[0x8] > eax[0x4]) {
                            sub_100060b0(ecx);
                            esp = (esp - 0x4) + 0x4;
                    }
                    eax = sub_10006110(esi);
                    esp = (esp - 0x4) + 0x4;
            }
    }
    return eax;
}
