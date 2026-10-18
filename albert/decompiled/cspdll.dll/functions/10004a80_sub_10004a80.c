// sub_10004a80 @ 0x10004a80
// hopper name: sub_10004a80
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10004a80() {
    decomp_var_4 = ebx;
    esp = esp - 0x8;
    esi = dword_1000a728;
    do {
            ecx = *esi;
            if (ecx != 0x0) {
                    eax = *(esi - 0x4);
                    if (eax != 0x0) {
                            (eax)(ecx);
                            esp = (esp - 0x4) + 0x4;
                            *esi = 0x0;
                    }
            }
            esi = esi + 0x14;
    } while (esi < 0x1000a764);
    ebx = arg_4;
    if (*(*ebx + 0x20) != 0x0) {
            if (ebx[0x1] != 0x0) {
                    sub_10005a00(ebx, 0x0);
                    ebx[0x1] = 0x0;
            }
    }
    else {
            esp = esp - 0x4;
            decomp_var_8 = edi;
            esi = 0x0;
            edi = ebx + 0x4;
            do {
                    if (*edi != 0x0) {
                            sub_10005a00(ebx, esi);
                            esp = (esp - 0x8) + 0x8;
                            *edi = 0x0;
                    }
                    esi = esi + 0x1;
                    edi = edi + 0x4;
            } while (esi < 0x32);
            esp = esp + 0x4;
    }
    return;
}
