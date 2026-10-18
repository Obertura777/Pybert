// sub_10003510 @ 0x10003510
// hopper name: sub_10003510
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10003510() {
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    esi = arg_4;
    decomp_var_10 = edi;
    esp = esp - 0x14;
    decomp_var_14 = esi[0x1];
    eax = (*0x10009150)();
    ebp = arg_4;
    ecx = *(int8_t *)esi;
    esi[0x1] = eax;
    if (ecx <= 0xff) {
            if (ecx != 0xff) {
                    switch (*(ecx * 0x4 + switch_table)) {
                        case 0:
                            eax = (*0x10009150)();
                            esi[0x2] = eax;
                            esi[0x3] = (*0x10009150)();
                            *ebp = esi;
                            eax = esi[0x1];
                            eax = eax + 0x4;
                            break;
                        case 1:
                            edi = 0x0;
                            if (eax > 0x0) {
                                    do {
                                            ebx = (edi & 0xffff) + esi + 0x4;
                                            esp = esp - 0x4;
                                            decomp_var_18 = *(int16_t *)((edi & 0xffff) + esi + 0x4);
                                            edi = edi + 0x6;
                                            *(int16_t *)ebx = (*0x10009150)();
                                    } while (edi < esi[0x1]);
                                    *ebp = esi;
                                    eax = esi[0x1];
                                    eax = eax + 0x4;
                            }
                            else {
                                    *ebp = esi;
                                    eax = esi[0x1];
                                    eax = eax + 0x4;
                            }
                            break;
                        case 2:
                            edi = 0x0;
                            if (eax > 0x0) {
                                    do {
                                            ebx = (edi & 0xffff) + esi + 0x4;
                                            esp = esp - 0x4;
                                            decomp_var_18 = *(int16_t *)((edi & 0xffff) + esi + 0x4);
                                            edi = edi + 0x2;
                                            *(int16_t *)ebx = (*0x10009150)();
                                    } while (edi < esi[0x1]);
                                    *ebp = esi;
                                    eax = esi[0x1];
                                    eax = eax + 0x4;
                            }
                            else {
                                    *ebp = esi;
                                    eax = esi[0x1];
                                    eax = eax + 0x4;
                            }
                            break;
                        case 3:
                            *ebp = esi;
                            eax = esi[0x1];
                            eax = eax + 0x4;
                            break;
                        default:
                            esi[0x2] = (*0x10009150)();
                            *ebp = esi;
                            eax = esi[0x1];
                            eax = eax + 0x4;
                            break;
                        default:
                            *ebp = 0x0;
                            *ebp = esi;
                            eax = esi[0x1];
                            eax = eax + 0x4;
                    }
            }
            else {
                    *ebp = esi;
                    eax = esi[0x1];
                    eax = eax + 0x4;
            }
    }
    else {
            *ebp = 0x0;
            *ebp = esi;
            eax = esi[0x1];
            eax = eax + 0x4;
    }
    return eax;
}
