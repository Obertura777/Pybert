// exp_vos_avl_next @ 0x10005d80
// hopper name: exp_vos_avl_next
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_avl_next() {
    ecx = arg_4;
    eax = ecx[0x3];
    if (eax != 0x0) {
            ecx = eax[0x1];
            if (ecx != 0x0) {
                    do {
                            eax = ecx;
                            ecx = eax[0x1];
                    } while (ecx != 0x0);
            }
            if (eax != 0x0) {
                    eax = eax - arg_0[0x9];
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            if (ecx != 0x0) {
                    while (true) {
                            eax = *ecx;
                            if (eax == 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            if (eax[0x1] == ecx) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            ecx = eax;
                            if (ecx != 0x0) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    if (temp_0 != 0x0) {
                            eax = *ecx;
                            if (eax != 0x0) {
                                    eax = eax - arg_0[0x9];
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    return eax;
}
