// sub_10002540 @ 0x10002540
// hopper name: sub_10002540
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10002540() {
    ecx = arg_0;
    decomp_var_4 = esi;
    esi = arg_c;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    *(int16_t *)esi = 0x1648;
    esi[0x1] = 0x8;
    esi[0x4] = arg_8;
    edx = *ecx;
    if (*(int16_t *)edx == 0x1648) {
            edx = edx + 0x2;
            *ecx = edx;
            if (*(int16_t *)edx == 0x40) {
                    *ecx = edx + 0x2;
                    ebx = edx[0x1];
                    *ecx = edx + 0x4;
                    esp = (esp - 0x4) + 0x4;
                    esi[0x3] = HIBYTE(ebx);
                    edx = *ecx;
                    if (*(int16_t *)edx == 0x140) {
                            *ecx = edx + 0x2;
                            eax = 0x1;
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
    return eax;
}
