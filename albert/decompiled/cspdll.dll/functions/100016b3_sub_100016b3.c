// sub_100016b3 @ 0x100016b3
// hopper name: sub_100016b3
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100016b3() {
    esi = arg_8;
    esp = esp - 0xc;
    edi = arg_18;
    *(int16_t *)edi = 0x1d48;
    edi[0x1] = 0x248;
    edi[0x4] = arg_8;
    eax = *esi;
    if (*(int16_t *)eax == 0x1d48) {
            eax = eax + 0x2;
            *esi = eax;
            if (*(int16_t *)eax == 0x40) {
                    *esi = eax + 0x2;
                    esp = (esp - 0xc) + 0xc;
                    if (sub_10001660(saved_fp, arg_0, arg_4) != 0x0) {
                            eax = *esi;
                            if (*(int16_t *)eax == 0x140) {
                                    eax = eax + 0x2;
                                    *esi = eax;
                                    if (*(int16_t *)eax == 0x40) {
                                            *esi = eax + 0x2;
                                            esp = (esp - 0xc) + 0xc;
                                            if (sub_10001660(saved_fp, arg_0, arg_4) != 0x0) {
                                                    eax = *esi;
                                                    if (*(int16_t *)eax == 0x140) {
                                                            *esi = eax + 0x2;
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }
    return;
}
