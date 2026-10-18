// exp_vos_avl_insert @ 0x10005b00
// hopper name: exp_vos_avl_insert
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_avl_insert() {
    decomp_var_8 = esi;
    esp = esp - 0x8;
    decomp_var_c = edi;
    edi = arg_0;
    ecx = edi[0x5];
    esi = edi[0x1];
    edi[0x5] = ecx + 0x1;
    if (esi == 0x0) {
            edi[0x1] = arg_4;
            edi[0x2] = arg_4;
            edi[0x3] = arg_4;
            arg_4[0x4] = 0x0;
            arg_4[0x8] = 0x0;
    }
    else {
            esp = esp - 0x4;
            if (esi != 0x0) {
                    ebx = arg_4;
                    while (true) {
                            eax = edi[0x8];
                            ecx = edi[0x9];
                            esp = (esp - 0x8) + 0x8;
                            if ((*edi)((eax - ecx) + ebx, (eax - ecx) + esi) > 0x0) {
                                    ebp = 0x0;
                                    eax = esi[0x3];
                                    if (eax != 0x0) {
                                            esi = eax;
                                            if (esi != ebp) {
                                                    continue;
                                            }
                                            sub_10005fb0(edi, esi);
                                            edi = decomp_var_4;
                                            esi = saved_fp;
                                            esp = (esp - 0x8) + 0x18;
                                            temp_0 = 0x2;
                                            break;
                                    }
                                    else {
                                            esi[0x3] = ebx;
                                            esi[0x8] = 0x1;
                                            *ebx = esi;
                                            ebx[0x8] = ebp;
                                            ebx[0x4] = ebp;
                                            if (esi == edi[0x3]) {
                                                    edi[0x3] = ebx;
                                                    sub_10005fb0(edi, esi);
                                                    edi = decomp_var_4;
                                                    esi = saved_fp;
                                                    esp = (esp - 0x8) + 0x18;
                                                    temp_0 = 0x3;
                                            }
                                            else {
                                                    temp_0 = 0x0;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    ebp = 0x0;
                                    eax = esi[0x1];
                                    if (eax != 0x0) {
                                            esi = eax;
                                            if (esi != ebp) {
                                                    continue;
                                            }
                                            sub_10005fb0(edi, esi);
                                            edi = decomp_var_4;
                                            esi = saved_fp;
                                            esp = (esp - 0x8) + 0x18;
                                            temp_0 = 0x2;
                                            break;
                                    }
                                    else {
                                            esi[0x1] = ebx;
                                            esi[0x4] = 0x1;
                                            *ebx = esi;
                                            ebx[0x8] = ebp;
                                            ebx[0x4] = ebp;
                                            if (esi == edi[0x2]) {
                                                    edi[0x2] = ebx;
                                                    temp_0 = 0x4;
                                            }
                                            else {
                                                    temp_0 = 0x1;
                                            }
                                            break;
                                    }
                            }
                    }
                    switch (temp_0) {
                        case 0:
                            sub_10005fb0(edi, esi);
                            break;
                        case 1:
                            sub_10005fb0(edi, esi);
                            break;
                        default:
                            if (temp_0 != 0x2) {
                                    if (temp_0 != 0x3) {
                                            sub_10005fb0(edi, esi);
                                    }
                            }
                            break;
                    }
            }
            else {
                    sub_10005fb0(edi, esi);
            }
    }
    return;
}
