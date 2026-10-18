// sub_10002470 @ 0x10002470
// hopper name: sub_10002470
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10002470() {
    ecx = arg_c;
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    esi = arg_0;
    ecx[0x4] = arg_8;
    *(int16_t *)ecx = 0x1548;
    ecx[0x1] = 0x8;
    edx = *esi;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    eax = (arg_4 & 0xffff) + edx;
    if (*(int16_t *)edx == 0x1548) {
            *esi = edx + 0x2;
            ecx[0x3] = 0x0;
            if (eax > *esi) {
                    while (true) {
                            edx = *esi;
                            if (*(int16_t *)edx != 0x40) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            *esi = edx + 0x2;
                            ebx = edx[0x1];
                            edi = edx + 0x4;
                            *esi = edi;
                            edx = HIBYTE(ebx);
                            ebx = *(int16_t *)edi;
                            ebp = edx & 0xff;
                            if (ebx != 0x140) {
                                    edx = edi;
                                    do {
                                            *esi = edx + 0x2;
                                            *(int16_t *)(ecx + ecx[0x3] * 0x4 + 0x8) = ebp;
                                            *(int16_t *)(ecx + ecx[0x3] * 0x4 + 0xa) = HIBYTE(ebx) & 0xff;
                                            ecx[0x3] = ecx[0x3] + 0x1;
                                            ecx[0x1] = ecx[0x1] + 0x4;
                                            edx = *esi;
                                            ebx = *(int16_t *)edx;
                                    } while (ebx != 0x140);
                            }
                            edx = *esi;
                            if (*(int16_t *)edx != 0x140) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            *esi = edx + 0x2;
                            if (eax > edx + 0x2) {
                                    continue;
                            }
                            temp_0 = 0x0;
                            break;
                    }
                    if (temp_0 != 0x0) {
                            eax = 0x0;
                    }
                    else {
                            eax = 0x1;
                    }
            }
            else {
                    eax = 0x1;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
