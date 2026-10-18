// exp_vos_trace_prolog @ 0x10006d10
// hopper name: exp_vos_trace_prolog
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_trace_prolog() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    if (*(*dword_1000ab2c + 0x108) > 0x0) {
            eax = sub_10006c40(&arg_0);
            esp = (esp - 0x4) + 0x4;
            if (eax != 0x0) {
                    if (**dword_1000ab2c != 0x0) {
                            eax = *dword_1000ab2c;
                            sub_10006840(eax, "%08x %-10s %.4d %-*s%-*s%-*s |", *eax[0x4e]);
                            eax = 0x1;
                    }
                    else {
                            eax = 0x1;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
