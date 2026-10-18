// exp_vos_trace_clear_globals @ 0x10006bf0
// hopper name: exp_vos_trace_clear_globals
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_trace_clear_globals() {
    fflush(**dword_1000ab2c);
    sub_10006860(*dword_1000ab2c);
    *(*dword_1000ab2c + 0x138) = 0x0;
    *(int8_t *)(*dword_1000ab2c + 0x13c) = 0x0;
    eax = ReleaseMutex(*(*dword_1000ab2c + 0x10c));
    return eax;
}
