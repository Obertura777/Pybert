// exp_vos_trace_set_globals @ 0x10006b60
// hopper name: exp_vos_trace_set_globals
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_trace_set_globals() {
    decomp_var_c = esi;
    decomp_var_10 = 0xffffffff;
    esp = esp - 0x14;
    WaitForSingleObject(*(*dword_1000ab2c + 0x10c), 0xffffffff);
    eax = GetCurrentThreadId();
    ebx = 0x0;
    var_8 = 0x0;
    if (*(int8_t *)(*dword_1000ab2c + 0x110) > 0x0) {
            while (true) {
                    edx = var_8;
                    if (*(*dword_1000ab2c + ((edx & 0xff) + 0x17 + ((edx & 0xff) + 0x17) * 0x2) * 0x4) == eax) {
                            esi = *dword_1000ab2c;
                            esi[0x4e] = esi + ((edx & 0xff) + 0x17 + ((edx & 0xff) + 0x17) * 0x2) * 0x4;
                            *(int8_t *)(*dword_1000ab2c + 0x13c) = ebx;
                            temp_0 = 0x1;
                            break;
                    }
                    ebx = ebx + 0x1;
                    var_8 = ebx;
                    if (ebx < *(int8_t *)(*dword_1000ab2c + 0x110)) {
                            continue;
                    }
                    esp = esp + 0xc;
                    temp_0 = 0x0;
                    break;
            }
    }
    return;
}
