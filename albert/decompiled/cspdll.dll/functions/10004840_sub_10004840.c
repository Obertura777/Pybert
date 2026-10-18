// sub_10004840 @ 0x10004840
// hopper name: sub_10004840
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10004840() {
    decomp_var_8 = 0x6;
    esi = malloc(0x6);
    esp = (esp - 0x8) + 0x4;
    if (esi != 0x0) {
            *(int8_t *)esi = 0x4;
            esi[0x1] = (*0x10009140)();
            esp = esp - 0x8;
            decomp_var_8 = arg_0;
            esi[0x2] = (*0x10009140)();
    }
    eax = esi;
    return eax;
}
