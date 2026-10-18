// sub_10006750 @ 0x10006750
// hopper name: sub_10006750
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10006750() {
    eax = arg_8;
    ecx = 0x0;
    if (eax > 0x0) {
            edx = arg_4;
            esp = esp - 0x4;
            decomp_var_4 = esi;
            esi = eax & 0xff;
            do {
                    eax = *(int8_t *)edx;
                    ecx = (eax + ecx << 0xa) + eax + ecx ^ (eax + ecx << 0xa) + eax + ecx >> 0x6;
                    edx = edx + 0x1;
                    esi = esi - 0x1;
            } while (esi != 0x0);
    }
    eax = ((ecx + ecx * 0x8 >> 0xb ^ ecx + ecx * 0x8) << 0xf) + (ecx + ecx * 0x8 >> 0xb ^ ecx + ecx * 0x8) & *arg_0 - 0x1;
    return eax;
}
