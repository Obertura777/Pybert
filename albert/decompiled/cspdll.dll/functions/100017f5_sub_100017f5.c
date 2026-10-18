// sub_100017f5 @ 0x100017f5
// hopper name: sub_100017f5
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100017f5() {
    esi = arg_10;
    esp = esp - 0x8;
    esi[0x4] = arg_8;
    ecx = arg_8;
    *(int16_t *)esi = 0x448;
    esi[0x1] = 0x28;
    edx = *ecx;
    if (*(int16_t *)edx == 0x448) {
            edx = edx + 0x2;
            *ecx = edx;
            if (*(int16_t *)edx == 0x40) {
                    *ecx = edx + 0x2;
                    esi[0x3] = edx[0x1];
                    edx = *ecx;
                    edx = edx + 0x2;
                    *ecx = edx;
                    if (*(int16_t *)edx == 0x140) {
                            edx = edx + 0x2;
                            *ecx = edx;
                            if (*(int16_t *)edx == 0x40) {
                                    *ecx = edx + 0x2;
                                    *ecx = edx + 0x4;
                                    esi[0x4] = sub_10001640(saved_fp);
                                    esp = (esp - 0x4) + 0x4;
                                    esi[0x5] = 0x0;
                                    esi[0x6] = 0x0;
                                    esi[0x7] = 0x0;
                                    esi[0x8] = 0x0;
                                    esi[0x5] = 0x0;
                                    esi[0x6] = 0x0;
                                    esi[0xe] = 0x0;
                                    esi[0x8] = 0x0;
                                    esi[0x9] = 0x0;
                            }
                    }
            }
    }
    return;
}
