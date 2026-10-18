// sub_10002130 @ 0x10002130
// hopper name: sub_10002130
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10002130() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    esi = arg_c;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    edi = arg_0;
    *(int16_t *)esi = 0xe48;
    esi[0x1] = 0xc;
    esi[0x4] = arg_8;
    esi[0x5] = 0x0;
    eax = *edi;
    ebx = (arg_4 & 0xffff) + eax;
    if (*(int16_t *)eax == 0xe48) {
            eax = eax + 0x2;
            *edi = eax;
            if (*(int16_t *)eax == 0x40) {
                    *edi = eax + 0x2;
                    esi[0x3] = eax[0x1];
                    ecx = *edi;
                    eax = ecx + 0x2;
                    *edi = ecx + 0x2;
                    ecx = *(int16_t *)eax;
                    *edi = eax + 0x2;
                    esi[0x4] = sub_10001640(ecx);
                    eax = *edi;
                    esp = (esp - 0x4) + 0x4;
                    if (*(int16_t *)eax == 0x140) {
                            *edi = eax + 0x2;
                            if (ebx > eax + 0x2) {
                                    while (true) {
                                            eax = esi[0x5];
                                            eax = sub_10002830(edi, (eax + eax * 0x2 << 0x5) + esi + 0xc);
                                            esp = (esp - 0x8) + 0x8;
                                            if (eax == 0x0) {
                                                    eax = 0x0;
                                                    esp = esp + 0x10;
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                            esi[0x5] = esi[0x5] + 0x1;
                                            esi[0x1] = esi[0x1] + 0x60;
                                            if (ebx > *edi) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    if (temp_0 != 0x0) {
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
