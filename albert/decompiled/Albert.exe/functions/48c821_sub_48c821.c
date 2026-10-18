// sub_48c821 @ 0x48c821
// hopper name: sub_48c821
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48c821() {
    ecx = arg_c;
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esi = arg_0;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = ecx[0x3];
    if (esi == 0x0) {
            esp = (esp - 0x4) + 0x4;
            *sub_47d812() = 0x16;
            sub_47a924();
            esp = (esp - 0x14) + 0x14;
            eax = 0x16;
    }
    else {
            if (arg_4 > 0x0) {
                    ebx = 0x0;
                    edx = arg_8;
                    *(int8_t *)esi = 0x0;
                    if (edx > 0x0) {
                            eax = edx;
                    }
                    else {
                            eax = 0x0;
                    }
                    if (arg_4 <= eax + 0x1) {
                            esp = (esp - 0x4) + 0x4;
                            *sub_47d812() = 0x22;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = 0x22;
                    }
                    else {
                            *(int8_t *)esi = 0x30;
                            eax = esi + 0x1;
                            if (edx > ebx) {
                                    do {
                                            ecx = *(int8_t *)edi;
                                            if (ecx != ebx) {
                                                    ecx = sign_extend_32(ecx);
                                                    edi = edi + 0x1;
                                            }
                                            else {
                                                    ecx = 0x30;
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            *(int8_t *)eax = ecx;
                                            eax = eax + 0x1;
                                            edx = edx - 0x1;
                                    } while (edx > ebx);
                                    ecx = arg_c;
                            }
                            *(int8_t *)eax = ebx;
                            if (edx >= ebx && *(int8_t *)edi >= 0x35) {
                                    while (true) {
                                            eax = eax - 0x1;
                                            if (*(int8_t *)eax != 0x39) {
                                                    break;
                                            }
                                            *(int8_t *)eax = 0x30;
                                    }
                                    *(int8_t *)eax = *(int8_t *)eax + 0x1;
                            }
                            if (*(int8_t *)esi == 0x31) {
                                    ecx[0x1] = ecx[0x1] + 0x1;
                            }
                            else {
                                    sub_47f9a0(esi, esi + 0x1, sub_47d630(esi + 0x1) + 0x1);
                                    esp = (esp - 0x10) + 0x10;
                            }
                            eax = 0x0;
                    }
            }
            else {
                    esp = (esp - 0x4) + 0x4;
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = (esp - 0x14) + 0x14;
                    eax = 0x16;
            }
    }
    return eax;
}
