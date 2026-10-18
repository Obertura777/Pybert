// sub_100020d0 @ 0x100020d0
// hopper name: sub_100020d0
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100020d0() {
    ecx = arg_0;
    eax = 0x0;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    edx = *ecx;
    if (*(int16_t *)edx == 0xd48) {
            edx = edx + 0x2;
            *ecx = edx;
            if (*(int16_t *)edx == 0x40) {
                    esi = arg_c;
                    eax = edx + 0x2;
                    edx = arg_4;
                    *ecx = eax;
                    decomp_var_8 = esi;
                    esp = esp - 0x8;
                    decomp_var_c = arg_8;
                    if (*(int16_t *)eax == 0x48) {
                            eax = sub_10001760(ecx, edx - 0x4, decomp_var_c, decomp_var_8);
                            esi[0x2] = 0x0;
                    }
                    else {
                            eax = sub_100017c0(ecx, edx - 0x4, decomp_var_c, decomp_var_8);
                            esp = (esp - 0x8) + 0x10;
                            esi[0x2] = 0x0;
                    }
            }
    }
    return eax;
}
