// exp_vos_trace_pop_function @ 0x10006f50
// hopper name: exp_vos_trace_pop_function
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_trace_pop_function() {
    eax = *dword_1000ab2c;
    eax = eax[0x4e];
    ecx = eax[0x1];
    eax[0x1] = *ecx;
    eax = free(ecx);
    return eax;
}
