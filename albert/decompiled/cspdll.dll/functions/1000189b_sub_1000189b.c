// sub_1000189b @ 0x1000189b
// hopper name: sub_1000189b
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_1000189b() {
    esi = arg_8;
    esp = esp - 0xc;
    edi = arg_18;
    *(int16_t *)edi = 0x748;
    edi[0x1] = 0xa;
    edi[0x4] = arg_8;
    eax = *esi;
    if (*(int16_t *)eax == 0x748) {
            eax = eax + 0x2;
            *esi = eax;
            if (*(int16_t *)eax == 0x40) {
                    *esi = eax + 0x2;
                    edi[0x3] = eax[0x1];
                    edx = *esi;
                    eax = edx + 0x2;
                    *esi = edx + 0x2;
                    if (*(int16_t *)eax == 0x140) {
                            eax = eax + 0x2;
                            *esi = eax;
                            if (*(int16_t *)eax == 0x40) {
                                    *esi = eax + 0x2;
                                    *esi = eax + 0x4;
                                    edi[0x4] = sub_10001640(saved_fp);
                                    eax = *esi;
                                    esp = (esp - 0x4) + 0x4;
                                    if (*(int16_t *)eax == 0x140) {
                                            *esi = eax + 0x2;
                                    }
                            }
                    }
            }
    }
    return;
}
