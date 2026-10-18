// sub_45b950 @ 0x45b950
// hopper name: sub_45b950
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45b950() {
    edx = arg_8;
    esp = esp - 0x4;
    decomp_var_4 = edi;
    edi = ecx;
    eax = edi[0x5];
    if (edx == 0x0) {
            ecx = arg_4;
            if (ecx < eax) {
                    eax = ecx;
            }
    }
    else {
            esp = esp - 0xc;
            if (edx <= eax) {
                    ecx = arg_4;
                    eax = eax - edx;
                    if (ecx < eax) {
                            eax = ecx;
                    }
                    ecx = edi[0x6];
                    arg_4 = ecx;
                    ebx = edi + 0x4;
                    if (ecx >= 0x10) {
                            ecx = *ebx;
                    }
                    else {
                            ecx = ebx;
                    }
                    ebp = arg_c;
                    esi = ecx + eax;
                    while (true) {
                            if (*(int8_t *)esi != *(int8_t *)ebp) {
                                    eax = sub_402350();
                                    if (esi != eax) {
                                            edx = arg_14;
                                            esi = esi - 0x1;
                                            continue;
                                    }
                                    temp_0 = 0x2;
                                    break;
                            }
                            esp = (esp - 0xc) + 0xc;
                            if (sub_40cd30(esi, ebp, edx) == 0x0) {
                                    if (arg_10 >= 0x10) {
                                            eax = esi - *ebx;
                                            esp = esp + 0x10;
                                            temp_0 = 0x1;
                                    }
                                    else {
                                            eax = esi - ebx;
                                            esp = esp + 0x10;
                                            temp_0 = 0x0;
                                    }
                                    break;
                            }
                            eax = sub_402350();
                            if (esi != eax) {
                                    edx = arg_14;
                                    esi = esi - 0x1;
                                    continue;
                            }
                            temp_0 = 0x2;
                            break;
                    }
                    if (temp_0 != 0x0 && temp_0 != 0x1) {
                            eax = eax | 0xffffffff;
                            esp = esp + 0xc;
                    }
            }
            else {
                    eax = eax | 0xffffffff;
                    esp = esp + 0xc;
            }
    }
    return eax;
}
