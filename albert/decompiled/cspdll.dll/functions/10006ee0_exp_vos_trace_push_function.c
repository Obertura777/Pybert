// exp_vos_trace_push_function @ 0x10006ee0
// hopper name: exp_vos_trace_push_function
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_trace_push_function() {
    ebx = arg_0;
    esp = esp - 0xc;
    ecx = ecx | 0xffffffff;
    asm { repne scasb al, byte [edi] };
    esi = malloc(!ecx + 0x10);
    ecx = ecx | 0xffffffff;
    edx = esi + 0x10;
    esi[0x1] = edx;
    asm { repne scasb al, byte [edi] };
    strncpy(edx, ebx, !ecx);
    *esi = *(*(*dword_1000ab2c + 0x138) + 0x4);
    *(*(*dword_1000ab2c + 0x138) + 0x4) = esi;
    eax = QueryPerformanceCounter(esi + 0x8);
    return eax;
}
