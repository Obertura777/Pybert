// sub_10002c70 @ 0x10002c70
// hopper name: sub_10002c70
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10002c70() {
    eax = malloc(0x8c);
    ebp = arg_14;
    ebx = arg_10;
    esp = (esp - 0x14) + 0x4;
    *ebp = eax;
    ecx = ebx[0x4];
    if (ecx <= 0x7) {
            switch (*(ecx * 0x4 + switch_table)) {
                case 0:
                    *eax = *"<-- CONNECT";
                    ecx = *"CONNECT";
                    eax[0x1] = *"CONNECT";
                    eax[0x2] = *"ECT";
                    break;
                case 1:
                    *eax = *"--> CONNECTED - ";
                    eax[0x1] = *"CONNECTED - ";
                    eax[0x2] = *"ECTED - ";
                    eax[0x3] = *"D - ";
                    ecx = *(int8_t *)"";
                    eax[0x10] = *(int8_t *)"";
                    break;
                case 2:
                    *eax = *"<-- LISTEN";
                    eax[0x1] = *"LISTEN";
                    ecx = *(int16_t *)"EN";
                    eax[0x4] = *(int16_t *)"EN";
                    eax[0xa] = *(int8_t *)"";
                    break;
                case 3:
                    *eax = *"--> OUT OF MEMORY";
                    eax[0x1] = *"OUT OF MEMORY";
                    eax[0x2] = *"OF MEMORY";
                    eax[0x3] = *"EMORY";
                    ecx = *(int16_t *)"Y";
                    eax[0x8] = *(int16_t *)"Y";
                    break;
                case 4:
                    *eax = *"--> ACCEPTED ";
                    eax[0x1] = *"ACCEPTED ";
                    eax[0x2] = *"PTED ";
                    ecx = *(int16_t *)" ";
                    eax[0x6] = *(int16_t *)" ";
                    break;
                case 5:
                    *eax = *"--> READ - ";
                    ecx = *"READ - ";
                    eax[0x1] = *"READ - ";
                    eax[0x2] = *" - ";
                    break;
                case 6:
                    *eax = *"--> WRITE - ";
                    eax[0x1] = *"WRITE - ";
                    ecx = *"E - ";
                    eax[0x2] = *"E - ";
                    eax[0xc] = *(int8_t *)"";
                    break;
                default:
                    *eax = *"--> CLOSED - ";
                    eax[0x1] = *"CLOSED - ";
                    ecx = *"ED - ";
                    eax[0x2] = *"ED - ";
                    eax[0x6] = *(int16_t *)" ";
                    break;
            }
    }
    edx = *ebp;
    ecx = ecx | 0xffffffff;
    asm { repne scasb al, byte [edi] };
    eax = ebx[0x1];
    ecx = !ecx - 0x1;
    esi = ecx + edx;
    if (eax != 0x0) {
            esp = esp - 0x1c;
            FormatMessageA(0x1200, 0x0, eax, 0x400, esi, 0x64, 0x0);
            ecx = ecx | 0xffffffff;
            eax = 0x0;
            asm { repne scasb al, byte [edi] };
            ecx = !ecx - 0x1;
            *(int8_t *)(ecx + (esi - 0x2)) = eax;
    }
    else {
            eax = ebx[0x4];
            if (eax == 0x4) {
                    eax = sign_extend_32(ebx[0x11]);
                    ecx = sign_extend_32(ebx[0x10]);
                    sprintf(esi, "(%d.%d.%d.%d) - Okay", sign_extend_32(ebx[0xe]), sign_extend_32(ebx[0xf]), ecx, eax);
                    esp = (esp - 0x18) + 0x18;
            }
            else {
                    if (eax != 0x0) {
                            if (eax != 0x2) {
                                    ecx = *"Okay";
                                    *esi = *"Okay";
                                    esi[0x4] = *(int8_t *)"";
                            }
                    }
            }
    }
    ecx = ecx | 0xffffffff;
    asm { repne scasb al, byte [edi] };
    eax = (!ecx - 0x1) + 0x1;
    return eax;
}
