// exp_dcsp_convert_address @ 0x10004190
// hopper name: exp_dcsp_convert_address
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

exp_dcsp_convert_address() {
    eax = arg_4;
    if (eax == 0x0) {
            *(int16_t *)(*dword_1000ab38 + 0x30) = 0x2;
            *(*dword_1000ab38 + 0x34) = (*0x10009144)();
            *(int16_t *)(*dword_1000ab38 + 0x32) = arg_4;
            eax = *(*dword_1000ab38 + 0x34) != 0xffffffff ? 0x1 : 0x0;
    }
    else {
            if (eax == 0x1) {
                    eax = (*0x10009138)();
                    if (eax != 0x0) {
                            if (eax[0x4] == 0x2) {
                                    if (eax[0x5] == 0x4) {
                                            *(int16_t *)(*dword_1000ab38 + 0x30) = 0x2;
                                            *(*dword_1000ab38 + 0x34) = **eax[0x3];
                                            eax = 0x1;
                                            *(int16_t *)(*dword_1000ab38 + 0x32) = arg_4;
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
            }
            else {
                    *(int16_t *)(*dword_1000ab38 + 0x30) = 0x2;
                    *(*dword_1000ab38 + 0x34) = 0x0;
                    *(int16_t *)(*dword_1000ab38 + 0x32) = arg_8;
                    eax = 0x1;
            }
    }
    return eax;
}
