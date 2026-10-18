// exp_vos_avl_remove @ 0x10005be0
// hopper name: exp_vos_avl_remove
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_vos_avl_remove() {
    decomp_var_4 = esi;
    esi = arg_4;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    edi = arg_0;
    eax = esi[0x1];
    if (eax == 0x0) {
            if (esi[0x3] == 0x0) {
                    eax = 0x0;
                    if (edi[0x2] == esi) {
                            edi[0x2] = *esi;
                    }
                    if (edi[0x3] == esi) {
                            edx = *esi;
                            edi[0x3] = edx;
                    }
            }
            else {
                    if (eax == 0x0) {
                            ecx = edi[0x2];
                            eax = esi[0x3];
                            if (ecx == esi) {
                                    edi[0x2] = eax;
                            }
                    }
                    else {
                            ecx = esi[0x3];
                            if (ecx == 0x0) {
                                    if (edi[0x3] == esi) {
                                            edi[0x3] = eax;
                                    }
                            }
                            else {
                                    edx = esi[0x4];
                                    if (esi[0x8] > edx) {
                                            if (ecx[0x1] == 0x0) {
                                                    eax = ecx;
                                                    eax[0x4] = edx;
                                                    ecx = esi[0x1];
                                                    eax[0x1] = ecx;
                                                    *ecx = eax;
                                            }
                                            else {
                                                    sub_10005e70(edi, ecx, esi);
                                                    eax = esi[0x3];
                                                    esp = (esp - 0xc) + 0xc;
                                            }
                                    }
                                    else {
                                            edx = eax[0x3];
                                            if (edx == 0x0) {
                                                    eax[0x3] = ecx;
                                                    *ecx = eax;
                                                    eax[0x8] = esi[0x8];
                                            }
                                            else {
                                                    sub_10005f10(edi, eax, esi);
                                                    eax = esi[0x1];
                                                    esp = (esp - 0xc) + 0xc;
                                            }
                                    }
                            }
                    }
            }
    }
    else {
            if (eax == 0x0) {
                    ecx = edi[0x2];
                    eax = esi[0x3];
                    if (ecx == esi) {
                            edi[0x2] = eax;
                    }
            }
            else {
                    ecx = esi[0x3];
                    if (ecx == 0x0) {
                            if (edi[0x3] == esi) {
                                    edi[0x3] = eax;
                            }
                    }
                    else {
                            edx = esi[0x4];
                            if (esi[0x8] > edx) {
                                    if (ecx[0x1] == 0x0) {
                                            eax = ecx;
                                            eax[0x4] = edx;
                                            ecx = esi[0x1];
                                            eax[0x1] = ecx;
                                            *ecx = eax;
                                    }
                                    else {
                                            sub_10005e70(edi, ecx, esi);
                                            eax = esi[0x3];
                                            esp = (esp - 0xc) + 0xc;
                                    }
                            }
                            else {
                                    edx = eax[0x3];
                                    if (edx == 0x0) {
                                            eax[0x3] = ecx;
                                            *ecx = eax;
                                            eax[0x8] = esi[0x8];
                                    }
                                    else {
                                            sub_10005f10(edi, eax, esi);
                                            eax = esi[0x1];
                                            esp = (esp - 0xc) + 0xc;
                                    }
                            }
                    }
            }
    }
    ecx = *esi;
    *esi = 0x0;
    esi[0x1] = 0x0;
    esi[0x3] = 0x0;
    esi[0x4] = edx | 0xffffffff;
    esi[0x8] = edx | 0xffffffff;
    if (eax == 0x0) {
            edx = 0x0;
    }
    else {
            edx = eax[0x4];
            *eax = ecx;
            if (edx > eax[0x8]) {
                    edx = sign_extend_32(edx);
            }
            else {
                    edx = sign_extend_32(eax[0x8]);
            }
            edx = edx + 0x1;
    }
    if (ecx != 0x0) {
            esp = (esp - 0x4) + 0x4;
            if (ecx[0x1] == esi) {
                    ecx[0x1] = eax;
                    ecx[0x4] = edx;
                    sub_10005fb0(edi, ecx);
                    eax = edi[0x5];
                    eax = eax - 0x1;
                    edi[0x5] = eax;
            }
            else {
                    ecx[0x3] = eax;
                    ecx[0x8] = edx;
                    sub_10005fb0(edi, ecx);
                    eax = edi[0x5];
                    eax = eax - 0x1;
                    edi[0x5] = eax;
            }
    }
    else {
            edi[0x1] = eax;
            eax = edi[0x5];
            eax = eax - 0x1;
            edi[0x5] = eax;
    }
    return eax;
}
