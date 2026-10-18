// sub_10004ea0 @ 0x10004ea0
// hopper name: sub_10004ea0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10004ea0() {
    decomp_var_4 = esi;
    esi = arg_0;
    decomp_var_8 = edi;
    sub_100055f0(esi, 0x0, 0x1, arg_4, decomp_var_8, decomp_var_4);
    esp = (esp - 0x18) + 0x10;
    if (arg_4 == 0x0) {
            eax = esi[0x1];
            eax[0x2] = eax[0x2] & 0xffffffef;
            edi = sub_10005a90();
            edi[0x2] = sub_10004800();
            sub_10004cf0(esi, 0x0, edi, 0x1);
            eax = esi[0x1];
            esp = (esp - 0x10) + 0x10;
            if (eax != 0x0) {
                    if (eax[0x3] != 0x0) {
                            sub_10005210(esi, 0x0, 0x0);
                            esp = (esp - 0xc) + 0xc;
                    }
            }
    }
    return;
}
