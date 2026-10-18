// sub_10003c90 @ 0x10003c90
// hopper name: sub_10003c90
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10003c90() {
    esi = arg_0;
    edi = arg_4;
    var_4 = sub_100068d0();
    fwrite(&var_4, 0x4, 0x1, *(*(esi + edi * 0x4 + 0x4) + 0x38));
    arg_24 = 0x6;
    fwrite(&arg_24, 0x2, 0x1, *(*(esi + edi * 0x4 + 0x4) + 0x38));
    ebp = arg_3c;
    arg_34 = ebp;
    eax = fwrite(&arg_34, 0x4, 0x1, *(*(esi + edi * 0x4 + 0x4) + 0x38));
    esp = (esp - 0x44) + 0x30;
    if (ebp != 0xffffffff) {
            eax = fwrite(arg_50, ebp, 0x1, *(*(esi + edi * 0x4 + 0x4) + 0x38));
            esp = (esp - 0x10) + 0x10;
    }
    return eax;
}
