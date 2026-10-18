// exp_vos_avl_find @ 0x10005d20
// hopper name: exp_vos_avl_find
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_avl_find() {
    decomp_var_4 = ebx;
    esp = esp - 0xc;
    edi = arg_0;
    esi = edi[0x1];
    if (esi != 0x0) {
            ebx = arg_4;
            while (true) {
                    eax = edi[0x8];
                    eax = (*edi)(ebx, (eax - edi[0x9]) + esi);
                    esp = (esp - 0x8) + 0x8;
                    bool_2 = eax >= 0x0;
                    if (eax > 0x0) {
                            esi = esi[0x3];
                            if (esi != 0x0) {
                                    continue;
                            }
                            temp_0 = 0x1;
                            break;
                    }
                    else {
                            if (!bool_2) {
                                    esi = esi[0x1];
                                    if (esi != 0x0) {
                                            continue;
                                    }
                                    temp_0 = 0x1;
                                    break;
                            }
                            else {
                                    if (esi != 0x0) {
                                            eax = esi - edi[0x9];
                                            esp = esp + 0xc;
                                            temp_0 = 0x0;
                                    }
                                    else {
                                            temp_0 = 0x2;
                                    }
                                    break;
                            }
                    }
            }
            if (temp_0 != 0x0) {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
