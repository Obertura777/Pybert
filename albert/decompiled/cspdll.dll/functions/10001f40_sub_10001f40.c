// sub_10001f40 @ 0x10001f40
// hopper name: sub_10001f40
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10001f40() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esi = arg_c;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = arg_0;
    *(int16_t *)esi = 0xb48;
    esi[0x1] = 0x10;
    esi[0x4] = arg_8;
    eax = *edi;
    if (*(int16_t *)eax == 0xb48) {
            *edi = eax + 0x2;
            if ((*(int8_t *)(eax + 0x6) & 0xc0) == 0x0) {
                    esi[0x2] = 0x1;
                    esi[0x7] = 0x0;
                    eax = *edi;
                    if (*(int16_t *)eax == 0x40) {
                            *edi = eax + 0x2;
                            esi[0x6] = sub_10001640(eax[0x1]);
                            edx = *edi;
                            esp = (esp - 0x4) + 0x4;
                            eax = edx + 0x2;
                            *edi = edx + 0x2;
                            if (*(int16_t *)eax == 0x140) {
                                    *edi = eax + 0x2;
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
                    esi[0x2] = 0x0;
                    esi[0x6] = 0x0;
                    edx = *edi;
                    esi[0x7] = 0x0;
                    ebx = (arg_4 & 0xffff) + edx;
                    if (ebx > *edi) {
                            while (true) {
                                    eax = esi[0x7];
                                    esp = (esp - 0x8) + 0x8;
                                    if (sub_10002830(edi, (eax + eax * 0x2 << 0x5) + esi + 0x10) == 0x0) {
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    esi[0x7] = esi[0x7] + 0x1;
                                    esi[0x1] = esi[0x1] + 0x60;
                                    if (ebx > *edi) {
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
    }
    else {
            eax = 0x0;
    }
    return eax;
}
