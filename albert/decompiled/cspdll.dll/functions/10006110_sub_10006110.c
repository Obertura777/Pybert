// sub_10006110 @ 0x10006110
// hopper name: sub_10006110
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10006110() {
    ecx = arg_0;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    edx = *ecx;
    eax = edx[0x1];
    edx[0x1] = eax[0x3];
    edx = *ecx;
    esi = edx[0x1];
    if (esi != 0x0) {
            *esi = edx;
    }
    *(int16_t *)(*ecx + 0x8) = eax[0x8];
    *eax = **ecx;
    edx = *ecx;
    eax[0x3] = edx;
    *edx = eax;
    edx = *ecx;
    esi = edx[0x8];
    edx = edx[0x4];
    if (esi > edx) {
            eax[0x8] = sign_extend_32(esi) + 0x1;
            *ecx = eax;
    }
    else {
            eax[0x8] = sign_extend_32(edx) + 0x1;
            *ecx = eax;
    }
    return eax;
}
