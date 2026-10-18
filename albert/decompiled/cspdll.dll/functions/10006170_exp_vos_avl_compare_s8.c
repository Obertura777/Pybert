// exp_vos_avl_compare_s8 @ 0x10006170
// hopper name: exp_vos_avl_compare_s8
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_avl_compare_s8() {
    eax = *(int8_t *)arg_0;
    ecx = *(int8_t *)arg_4;
    if (eax < ecx) {
            eax = eax | 0xffffffff;
    }
    else {
            eax = eax > ecx ? 0x1 : 0x0;
    }
    return eax;
}
