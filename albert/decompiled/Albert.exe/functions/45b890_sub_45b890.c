// sub_45b890 @ 0x45b890
// hopper name: sub_45b890
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45b890() {
    esp = esp - 0x4;
    edx = arg_8;
    eax = arg_4;
    var_4 = ecx;
    if (edx == 0x0) {
            if (eax > ecx[0x5]) {
                    decomp_var_8 = ebx;
                    esp = esp - 0x10;
                    edi = ecx[0x5];
                    if (eax < edi) {
                            edi = edi - eax;
                            if (edx <= edi) {
                                    edi = edi + (0x1 - edx);
                                    if (ecx[0x6] >= 0x10) {
                                            arg_4 = ecx + 0x4;
                                            ecx = ecx[0x1];
                                    }
                                    else {
                                            ecx = ecx + 0x4;
                                            arg_4 = ecx;
                                    }
                                    ebp = arg_c;
                                    ebx = ecx + eax;
                                    eax = sign_extend_32(*(int8_t *)ebp);
                                    eax = sub_47bf50(ebx, eax, edi);
                                    esi = eax;
                                    esp = (esp - 0xc) + 0xc;
                                    if (esi != 0x0) {
                                            while (true) {
                                                    ecx = arg_14;
                                                    esp = (esp - 0xc) + 0xc;
                                                    if (sub_40cd30(esi, ebp, ecx) == 0x0) {
                                                            eax = arg_4;
                                                            ecx = arg_10;
                                                            if (eax[0x6] >= 0x10) {
                                                                    ecx = *ecx;
                                                                    temp_0 = 0x1;
                                                            }
                                                            else {
                                                                    temp_0 = 0x1;
                                                            }
                                                            break;
                                                    }
                                                    edi = edi + (ebx - esi - 0x1);
                                                    ebx = esi + 0x1;
                                                    eax = sub_47bf50(ebx, sign_extend_32(*(int8_t *)ebp), edi);
                                                    esi = eax;
                                                    esp = (esp - 0xc) + 0xc;
                                                    if (esi != 0x0) {
                                                            continue;
                                                    }
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                            if (temp_0 != 0x0) {
                                                    eax = esi - ecx;
                                            }
                                            else {
                                                    eax = eax | 0xffffffff;
                                                    esp = esp + 0x10;
                                            }
                                    }
                                    else {
                                            eax = eax | 0xffffffff;
                                            esp = esp + 0x10;
                                    }
                            }
                            else {
                                    eax = eax | 0xffffffff;
                                    esp = esp + 0x10;
                            }
                    }
                    else {
                            eax = eax | 0xffffffff;
                            esp = esp + 0x10;
                    }
            }
    }
    else {
            decomp_var_8 = ebx;
            esp = esp - 0x10;
            edi = ecx[0x5];
            if (eax < edi) {
                    edi = edi - eax;
                    if (edx <= edi) {
                            edi = edi + (0x1 - edx);
                            if (ecx[0x6] >= 0x10) {
                                    arg_4 = ecx + 0x4;
                                    ecx = ecx[0x1];
                            }
                            else {
                                    ecx = ecx + 0x4;
                                    arg_4 = ecx;
                            }
                            ebp = arg_c;
                            ebx = ecx + eax;
                            eax = sign_extend_32(*(int8_t *)ebp);
                            eax = sub_47bf50(ebx, eax, edi);
                            esi = eax;
                            esp = (esp - 0xc) + 0xc;
                            if (esi != 0x0) {
                                    while (true) {
                                            ecx = arg_14;
                                            esp = (esp - 0xc) + 0xc;
                                            if (sub_40cd30(esi, ebp, ecx) == 0x0) {
                                                    eax = arg_4;
                                                    ecx = arg_10;
                                                    if (eax[0x6] >= 0x10) {
                                                            ecx = *ecx;
                                                            temp_0 = 0x1;
                                                    }
                                                    else {
                                                            temp_0 = 0x1;
                                                    }
                                                    break;
                                            }
                                            edi = edi + (ebx - esi - 0x1);
                                            ebx = esi + 0x1;
                                            eax = sub_47bf50(ebx, sign_extend_32(*(int8_t *)ebp), edi);
                                            esi = eax;
                                            esp = (esp - 0xc) + 0xc;
                                            if (esi != 0x0) {
                                                    continue;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    if (temp_0 != 0x0) {
                                            eax = esi - ecx;
                                    }
                                    else {
                                            eax = eax | 0xffffffff;
                                            esp = esp + 0x10;
                                    }
                            }
                            else {
                                    eax = eax | 0xffffffff;
                                    esp = esp + 0x10;
                            }
                    }
                    else {
                            eax = eax | 0xffffffff;
                            esp = esp + 0x10;
                    }
            }
            else {
                    eax = eax | 0xffffffff;
                    esp = esp + 0x10;
            }
    }
    return eax;
}
