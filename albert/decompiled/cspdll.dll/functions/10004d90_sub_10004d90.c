// sub_10004d90 @ 0x10004d90
// hopper name: sub_10004d90
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10004d90() {
    decomp_var_30 = esi;
    esi = arg_0;
    decomp_var_34 = edi;
    edi = arg_4;
    eax = *(esi + edi * 0x4 + 0x4);
    edx = eax[0x1];
    eax = *eax;
    esp = esp - 0x40;
    eax = (*0x10009170)(eax, edx, &var_2C, decomp_var_34, decomp_var_30);
    if (eax != 0x0) {
            eax = (*0x10009178)();
    }
    if ((var_24 & 0x10) != 0x0) {
            sub_10004ea0(esi, var_10);
            ecx = var_24 & 0xffffffef;
            esp = (esp - 0x8) + 0x8;
            var_24 = ecx;
            eax = *(*(esi + edi * 0x4 + 0x4) + 0xc);
            if (eax == 0x0) {
                    eax = ecx & 0xfd;
                    var_24 = eax;
            }
    }
    if ((var_24 & 0x8) != 0x0) {
            sub_10004f00(esi, var_14);
            eax = *(esi + edi * 0x4 + 0x4);
            esp = (esp - 0x8) + 0x8;
            var_24 = var_24 & 0xfffffff7;
            if (eax == 0x0) {
                    var_24 = 0x0;
            }
    }
    if ((var_24 & 0x1) != 0x0) {
            sub_10005030(esi, edi, var_20);
            eax = *(esi + edi * 0x4 + 0x4);
            esp = (esp - 0xc) + 0xc;
            var_24 = var_24 & 0xfffffffe;
            if (eax == 0x0) {
                    var_24 = 0x0;
            }
    }
    if ((var_24 & 0x2) != 0x0) {
            sub_10005210(esi, edi, var_1C);
            eax = *(esi + edi * 0x4 + 0x4);
            esp = (esp - 0xc) + 0xc;
            var_24 = var_24 & 0xfffffffd;
            if (eax == 0x0) {
                    var_24 = 0x0;
            }
    }
    if ((var_24 & 0x20) != 0x0) {
            eax = sub_10005380(esi, edi, var_C);
            esp = (esp - 0xc) + 0xc;
    }
    return eax;
}
