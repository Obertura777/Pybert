// sub_100012de @ 0x100012de
// hopper name: sub_100012de
// referenced by: 
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100012de() {
    esi = arg_8;
    ebx = arg_c;
    esp = esp - 0xc;
    edi = 0x0;
    *(int16_t *)*esi = 0x1848;
    edx = *esi;
    *esi = edx + 0x2;
    eax = edx + 0x2;
    if (ebx[0x3] > 0x0) {
            do {
                    *(int16_t *)eax = 0x40;
                    *esi = *esi + 0x2;
                    sub_10001350();
                    esp = (esp - 0x8) + 0x8;
                    *(int16_t *)*esi = 0x140;
                    eax = *esi;
                    eax = eax + 0x2;
                    edi = edi + 0x1;
                    *esi = eax;
            } while (edi < ebx[0x3]);
    }
    return;
}
