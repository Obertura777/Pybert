// sub_100058e0 @ 0x100058e0
// hopper name: sub_100058e0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100058e0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    eax = arg_8[0x4];
    eax = eax - 0x0;
    if (eax != 0x0) {
            eax = eax - 0x2;
            if (eax != 0x0) {
                    eax = eax - 0x6;
                    if (eax == 0x0) {
                            sub_100055f0(arg_0, arg_4, 0x7, 0x0, edi, decomp_var_4);
                            eax = sub_10005a00(arg_0, arg_4);
                            *(arg_0 + arg_4 * 0x4 + 0x4) = 0x0;
                            arg_0[0x33] = 0x1;
                    }
            }
            else {
                    esi = arg_0;
                    eax = sub_10004b00(esi);
                    esp = (esp - 0x4) + 0x4;
                    if (eax != 0x0) {
                            eax = sub_100055f0(esi, arg_4, 0x2, eax, decomp_var_4, saved_fp);
                    }
            }
    }
    else {
            esi = arg_0;
            eax = sub_10004b00(esi);
            esp = (esp - 0x4) + 0x4;
            if (eax != 0x0) {
                    eax = sub_100055f0(esi, arg_4, 0x1, eax, decomp_var_4, saved_fp);
                    esp = (esp - 0x10) + 0x10;
            }
    }
    return eax;
}
