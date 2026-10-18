// exp_vos_avl_compare_ntstr @ 0x10006240
// hopper name: exp_vos_avl_compare_ntstr
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_avl_compare_ntstr() {
    decomp_var_4 = ebx;
    esp = esp - 0x8;
    decomp_var_8 = esi;
    esi = *arg_4;
    eax = *arg_0;
    while (true) {
            edx = *(int8_t *)eax;
            ecx = edx;
            if (edx != *(int8_t *)esi) {
                    temp_0 = 0x1;
                    break;
            }
            if (ecx == 0x0) {
                    temp_0 = 0x0;
                    break;
            }
            edx = eax[0x1];
            ecx = edx;
            if (edx != esi[0x1]) {
                    temp_0 = 0x1;
                    break;
            }
            eax = eax + 0x2;
            esi = esi + 0x2;
            bool_3 = true;
            if (ecx != 0x0) {
                    continue;
            }
            temp_0 = 0x0;
            break;
    }
    if (temp_0 != 0x0) {
            eax = eax - eax + CARRY(EFLAGS(cf)) - (eax - eax + CARRY(EFLAGS(cf))) + CARRY(EFLAGS(cf)) - 0xffffffff + CARRY(EFLAGS(cf));
    }
    else {
            eax = 0x0;
    }
    bool_1 = eax <= 0x0;
    if (eax < 0x0) {
            eax = eax | 0xffffffff;
    }
    else {
            if (!bool_1) {
                    eax = 0x1;
            }
    }
    return eax;
}
