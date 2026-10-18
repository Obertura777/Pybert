// sub_10002b90 @ 0x10002b90
// hopper name: sub_10002b90
// referenced by: called,pointer
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10002b90() {
    esp = esp - 0x4;
    esi = arg_0;
    eax = *esi;
    if (eax != 0x0) {
            sub_100067a0(eax);
            esp = (esp - 0x4) + 0x4;
    }
    eax = esi[0x1];
    if (eax != 0x0) {
            sub_100067a0(eax);
            esp = (esp - 0x4) + 0x4;
    }
    eax = free(esi);
    return eax;
}
