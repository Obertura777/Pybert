// exp_vos_avl_compare_u32 @ 0x10006220
// hopper name: exp_vos_avl_compare_u32
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_avl_compare_u32() {
    eax = *arg_0;
    ecx = *arg_4;
    bool_1 = true;
    if (ecx > eax) {
            eax = eax | 0xffffffff;
    }
    else {
            eax = -(eax - eax + CARRY(EFLAGS(cf)));
    }
    return eax;
}
