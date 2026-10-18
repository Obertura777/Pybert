// sub_10001350 @ 0x10001350
// hopper name: sub_10001350
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10001350() {
    esp = esp - 0x8;
    edi = arg_c;
    if (edi[0x30] != 0x8243) {
            esi = arg_8;
            *(int16_t *)*esi = 0x40;
            eax = *esi;
            *esi = eax + 0x2;
            HIBYTE(ecx) = *(int8_t *)edi;
            eax[0x1] = ecx | 0x41;
            eax = *esi;
            *esi = eax + 0x2;
            eax[0x1] = edi[0x1];
            *esi = *esi + 0x2;
            sub_10001580();
            esp = (esp - 0xc) + 0xc;
            *(int16_t *)*esi = 0x140;
    }
    else {
            esi = arg_8;
            HIBYTE(eax) = *(int8_t *)edi;
            *(int16_t *)*esi = eax | 0x41;
    }
    eax = *esi;
    *esi = eax + 0x2;
    eax[0x1] = edi[0x30];
    eax = *esi;
    *esi = eax + 0x2;
    ecx = eax + 0x2;
    eax = edi[0x30];
    bool_7 = eax == 0x2343;
    if (eax <= 0x2343) {
            if (!bool_7) {
                    if (eax != 0x2043) {
                            if (eax == 0x2143) {
                                    *(int16_t *)ecx = 0x40;
                                    eax = *esi;
                                    *esi = eax + 0x2;
                                    HIBYTE(ecx) = edi[0x68];
                                    eax[0x1] = ecx | 0x41;
                                    eax = *esi;
                                    *esi = eax + 0x2;
                                    eax[0x1] = edi[0x35];
                                    *esi = *esi + 0x2;
                                    sub_10001580();
                                    *(int16_t *)*esi = 0x140;
                                    edx = *esi;
                                    *esi = edx + 0x2;
                                    edx[0x1] = 0x2043;
                                    ecx = *esi;
                                    *esi = ecx + 0x2;
                                    ecx[0x1] = edi[0x31];
                                    *esi = *esi + 0x2;
                            }
                    }
                    else {
                            sub_10001580();
                            esp = (esp - 0xc) + 0xc;
                            *(int16_t *)*esi = 0x2543;
                            ecx = *esi;
                            *esi = ecx + 0x2;
                            ecx[0x1] = 0x40;
                            eax = *esi;
                            *esi = eax + 0x2;
                            ecx = eax + 0x2;
                            eax = 0x0;
                            if (edi[0x64] > 0x0) {
                                    do {
                                            *(int16_t *)ecx = *(int16_t *)(edi + (eax & 0xffff) * 0x2 + 0xca);
                                            ecx = *esi;
                                            ecx = ecx + 0x2;
                                            eax = eax + 0x1;
                                            *esi = ecx;
                                    } while (eax < edi[0x64]);
                            }
                            *(int16_t *)ecx = 0x140;
                            *esi = *esi + 0x2;
                    }
            }
            else {
                    sub_10001580();
            }
    }
    else {
            if (eax != 0x2443) {
                    if (eax == 0x4143) {
                            sub_10001580();
                    }
            }
            else {
                    *(int16_t *)ecx = 0x40;
                    edx = *esi;
                    *esi = edx + 0x2;
                    eax = edx + 0x2;
                    HIBYTE(edx) = edi[0x68];
                    *(int16_t *)eax = edx | 0x41;
                    edx = *esi;
                    *esi = edx + 0x2;
                    edx[0x1] = edi[0x35];
                    *esi = *esi + 0x2;
                    sub_10001580();
                    esp = (esp - 0xc) + 0xc;
                    *(int16_t *)*esi = 0x140;
                    edx = *esi;
                    *esi = edx + 0x2;
                    eax = edx + 0x2;
                    if (edi[0x31] != 0x158) {
                            *(int16_t *)eax = 0x2343;
                            ecx = *esi;
                            *esi = ecx + 0x2;
                            ecx[0x1] = edi[0x31];
                            *esi = *esi + 0x2;
                    }
            }
    }
    return;
}
