// exp_vos_trace_entry @ 0x10006da0
// hopper name: exp_vos_trace_entry
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_trace_entry() {
    eax = *dword_1000ab2c;
    if (**dword_1000ab2c != 0x0) {
            ecx = *(*dword_1000ab2c + 0x138);
            ecx = ecx[0x2];
            if (ecx > 0x0) {
                    esp = esp - 0x4;
                    decomp_var_4 = esi;
                    esi = ecx;
                    do {
                            sub_10006840(*dword_1000ab2c, 0x1000ab1c, decomp_var_4);
                            esp = (esp - 0x8) + 0x8;
                            esi = esi - 0x1;
                    } while (esi != 0x0);
                    esp = esp + 0x4;
            }
            sub_10006840(*dword_1000ab2c, 0x1000ab18, saved_fp);
            eax = *(*dword_1000ab2c + 0x138);
            eax[0x2] = eax[0x2] + 0x2;
    }
    return eax;
}
