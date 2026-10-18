// sub_10004c20 @ 0x10004c20
// hopper name: sub_10004c20
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10004c20() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    decomp_var_c = edi;
    ebx = arg_4;
    edi = arg_0;
    esi = sub_10005a90();
    if (esi != 0x0) {
            eax = sub_10004840(arg_8);
            esp = (esp - 0x4) + 0x4;
            esi[0x2] = eax;
            if (eax != 0x0) {
                    sub_10004cf0(edi, ebx, esi, 0x0);
                    esp = (esp - 0x10) + 0x10;
            }
            else {
                    free(esi);
                    esp = (esp - 0x4) + 0x4;
            }
    }
    sub_10005a00(edi, ebx);
    *(edi + ebx * 0x4 + 0x4) = 0x0;
    edi[0x33] = 0x1;
    return;
}
