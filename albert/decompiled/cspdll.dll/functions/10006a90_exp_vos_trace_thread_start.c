// exp_vos_trace_thread_start @ 0x10006a90
// hopper name: exp_vos_trace_thread_start
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_trace_thread_start() {
    WaitForSingleObject(*(*dword_1000ab2c + 0x10c), 0xffffffff);
    ecx = *dword_1000ab2c;
    eax = ecx[0x110];
    *(ecx + (eax + eax * 0x2) * 0x4 + 0x11c) = 0x2;
    ecx = *dword_1000ab2c;
    eax = ecx[0x110];
    *(ecx + (eax + eax * 0x2) * 0x4 + 0x118) = 0x0;
    eax = GetCurrentThreadId();
    edx = *dword_1000ab2c;
    ecx = edx[0x110];
    *(edx + (ecx + 0x17 + (ecx + 0x17) * 0x2) * 0x4) = eax;
    eax = *dword_1000ab2c;
    eax[0x110] = eax[0x110] + 0x1;
    eax = *(*dword_1000ab2c + 0x10c);
    eax = ReleaseMutex(eax);
    return eax;
}
