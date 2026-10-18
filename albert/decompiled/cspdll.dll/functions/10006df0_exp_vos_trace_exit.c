// exp_vos_trace_exit @ 0x10006df0
// hopper name: exp_vos_trace_exit
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_trace_exit() {
    esp = esp - 0xc;
    eax = QueryPerformanceCounter(&var_8);
    eax = *dword_1000ab2c;
    if (**dword_1000ab2c != 0x0) {
            eax = *dword_1000ab2c;
            eax = eax[0x4e];
            esp = esp - 0x4;
            decomp_var_c = esi;
            eax[0x2] = eax[0x2] - 0x2;
            eax = *(*(*dword_1000ab2c + 0x138) + 0x8);
            if (eax > 0x0) {
                    esi = eax;
                    do {
                            sub_10006840(*dword_1000ab2c, 0x1000ab1c, decomp_var_c);
                            esp = (esp - 0x8) + 0x8;
                            esi = esi - 0x1;
                    } while (esi != 0x0);
            }
            ecx = *dword_1000ab2c;
            eax = var_8 - *(*(ecx[0x4e] + 0x4) + 0x8);
            eax = sub_10006840(ecx, "} (%d)\n", eax);
            esp = (esp - 0x10) + 0x14;
    }
    return eax;
}
