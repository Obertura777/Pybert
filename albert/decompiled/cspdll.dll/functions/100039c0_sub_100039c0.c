// sub_100039c0 @ 0x100039c0
// hopper name: sub_100039c0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100039c0() {
    edx = arg_0;
    esp = esp - 0x4;
    eax = *edx;
    ecx = *(int16_t *)eax;
    esi = eax[0x1];
    if (ecx == 0x1c48) {
            if (esi == 0x40) {
                    *edx = eax + 0x4;
            }
    }
    else {
            if (ecx == 0x1448 && esi == 0x40) {
                    *edx = eax + 0x4;
            }
    }
    return;
}
