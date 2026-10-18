// sub_10002990 @ 0x10002990
// hopper name: sub_10002990
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10002990() {
    edx = arg_0;
    decomp_var_4 = ebx;
    esp = esp - 0x8;
    decomp_var_8 = ebp;
    ecx = *edx;
    eax = 0x1;
    ebx = *(int16_t *)ecx;
    ecx = ecx + 0x2;
    *edx = ecx;
    if (ebx == 0x40) {
            eax = 0x1;
            ebx = *(int16_t *)ecx;
            *edx = ecx + 0x2;
            *(int16_t *)arg_4 = HIBYTE(ebx) & 0xff;
            esi = *edx;
            ecx = *(int16_t *)esi;
            *edx = esi + 0x2;
            arg_4[0x1] = 0x1 << ((ecx & 0xffff) >> 0x9) + 0x3;
            ecx = *edx;
            esp = (esp - 0x8) + 0x8;
            if (*(int16_t *)ecx == 0x140) {
                    *edx = ecx + 0x2;
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            ecx = arg_4;
            *(int16_t *)ecx = HIBYTE(ebx) & 0xff;
            edx = arg_8;
            if (edx == 0x42) {
                    eax = 0x1;
                    ecx[0x1] = 0x1;
            }
            else {
                    if (edx == 0x142) {
                            ecx[0x1] = 0x8000;
                    }
                    else {
                            eax = 0x0;
                    }
            }
    }
    return eax;
}
