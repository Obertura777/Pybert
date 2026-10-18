// sub_100060b0 @ 0x100060b0
// hopper name: sub_100060b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100060b0() {
    ecx = arg_0;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    edx = *ecx;
    eax = edx[0x3];
    edx[0x3] = eax[0x1];
    edx = *ecx;
    esi = edx[0x3];
    if (esi != 0x0) {
            *esi = edx;
    }
    *(int16_t *)(*ecx + 0x10) = eax[0x4];
    *eax = **ecx;
    edx = *ecx;
    eax[0x1] = edx;
    *edx = eax;
    edx = *ecx;
    esi = edx[0x8];
    edx = edx[0x4];
    if (esi > edx) {
            eax[0x4] = sign_extend_32(esi) + 0x1;
            *ecx = eax;
    }
    else {
            eax[0x4] = sign_extend_32(edx) + 0x1;
            *ecx = eax;
    }
    return eax;
}
