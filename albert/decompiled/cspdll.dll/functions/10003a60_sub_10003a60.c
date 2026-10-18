// sub_10003a60 @ 0x10003a60
// hopper name: sub_10003a60
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10003a60() {
    esi = malloc(saved_fp);
    esp = (esp - 0xc) + 0x4;
    if (esi != 0x0) {
            arg_8 = esi + 0x4;
            ebx = sub_10003bd0();
            (sub_10003b40())();
            esp = (esp - 0x1c) + 0x14;
            if (ebx != 0x0) {
                    *(int16_t *)arg_8 = 0x140;
                    edi = arg_8 + 0x2;
            }
            else {
                    edi = arg_8;
            }
            *(int8_t *)esi = 0x2;
            esi[0x1] = (*0x10009140)();
            realloc(saved_fp, arg_0);
    }
    return;
}
