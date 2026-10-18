// sub_10004cf0 @ 0x10004cf0
// hopper name: sub_10004cf0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10004cf0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    if (arg_c == 0x0) {
            eax = arg_0;
            ecx = arg_4;
            esp = esp - 0x4;
            decomp_var_8 = edi;
            edi = arg_8;
            edx = *(eax + ecx * 0x4 + 0x4);
            esi = edx[0x4];
            if (esi == 0x0) {
                    edx[0x3] = edi;
                    *(*(eax + ecx * 0x4 + 0x4) + 0x10) = edi;
                    eax = sub_10005210(eax, ecx, 0x0);
            }
            else {
                    *esi = edi;
                    *(*(eax + ecx * 0x4 + 0x4) + 0x10) = edi;
                    eax = sub_10005210(eax, ecx, 0x0);
            }
    }
    else {
            eax = arg_0;
            ecx = arg_4;
            edx = *(eax + ecx * 0x4 + 0x4);
            if (edx[0x4] == 0x0) {
                    edx[0x3] = arg_8;
                    *(*(eax + ecx * 0x4 + 0x4) + 0x10) = arg_8;
                    eax = sub_10005210(eax, ecx, 0x0);
            }
            else {
                    *arg_8 = edx[0x3];
                    *(*(eax + ecx * 0x4 + 0x4) + 0xc) = arg_8;
                    eax = sub_10005210(eax, ecx, 0x0);
            }
    }
    return eax;
}
