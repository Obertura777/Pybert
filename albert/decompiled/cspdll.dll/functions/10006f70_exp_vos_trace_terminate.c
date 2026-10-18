// exp_vos_trace_terminate @ 0x10006f70
// hopper name: exp_vos_trace_terminate
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_trace_terminate() {
    fflush(**dword_1000ab2c);
    fclose(**dword_1000ab2c);
    **dword_1000ab2c = 0x0;
    eax = sub_100068c0(*dword_1000ab2c);
    *dword_1000ab2c = 0x0;
    return eax;
}
