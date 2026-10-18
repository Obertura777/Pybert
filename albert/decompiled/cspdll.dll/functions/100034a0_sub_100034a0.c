// sub_100034a0 @ 0x100034a0
// hopper name: sub_100034a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100034a0() {
    esi = malloc(0x20);
    *(int8_t *)esi = 0xff;
    edi = arg_8;
    esi[0x1] = (*0x10009140)();
    esi[0x1] = 0x0;
    eax = strncmp(edi, "<-- CONNECT", 0xc);
    esp = ((esp - 0x10) + 0x4 - 0x10) + 0xc;
    if (eax == 0x0) {
            esi[0x4] = eax;
            eax = esi;
    }
    else {
            esp = (esp - 0xc) + 0xc;
            if (strncmp(edi, "<-- LISTEN", 0xb) == 0x0) {
                    esi[0x4] = 0x2;
            }
            eax = esi;
    }
    return eax;
}
