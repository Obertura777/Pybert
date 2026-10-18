// sub_10004c90 @ 0x10004c90
// hopper name: sub_10004c90
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10004c90() {
    var_10 = 0x1;
    decomp_var_14 = 0x0;
    decomp_var_18 = 0x0;
    esp = esp - 0x24;
    eax = (*0x10009180)(0x2, 0x1, 0x6, 0x0, 0x0, 0x1, edi, esi, 0x1);
    esi = esi;
    *esi = eax;
    if (eax == 0xffffffff) {
            eax = 0x0;
    }
    else {
            decomp_var_1c = &var_10;
            decomp_var_20 = 0x8004667e;
            esp = esp - 0xc;
            decomp_var_24 = eax;
            if ((*0x10009148)() != 0x0) {
                    (*0x10009130)();
                    *esi = 0xffffffff;
                    eax = 0x0;
            }
            else {
                    eax = 0x1;
            }
    }
    return eax;
}
