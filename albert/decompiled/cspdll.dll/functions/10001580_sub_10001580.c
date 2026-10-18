// sub_10001580 @ 0x10001580
// hopper name: sub_10001580
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10001580() {
    edx = arg_8;
    if ((edx & 0x7) != 0x0) {
            *(int16_t *)*arg_0 = arg_4;
            *arg_0 = *arg_0 + 0x2;
    }
    else {
            eax = arg_0;
            esp = esp - 0x4;
            *(int16_t *)*eax = 0x40;
            esi = *eax;
            *eax = esi + 0x2;
            esi[0x1] = arg_8;
            ecx = *eax;
            *eax = ecx + 0x2;
            esi = ecx + 0x2;
            ecx = 0x0;
            if (edx != 0x1) {
                    do {
                            edx = edx >> 0x1;
                            ecx = ecx + 0x1;
                    } while (edx != 0x1);
            }
            *(int16_t *)esi = ecx + 0x7d << 0x9 | 0x46;
            edx = *eax;
            *eax = edx + 0x2;
            edx[0x1] = 0x140;
            *eax = *eax + 0x2;
    }
    return;
}
