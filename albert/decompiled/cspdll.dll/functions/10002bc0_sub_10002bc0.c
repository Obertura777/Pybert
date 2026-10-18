// sub_10002bc0 @ 0x10002bc0
// hopper name: sub_10002bc0
// referenced by: called,pointer
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10002bc0() {
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = arg_4;
    eax = *(int8_t *)esi;
    bool_5 = eax == 0x2;
    if (eax <= 0x2) {
            if (!bool_5) {
                    eax = eax - 0x0;
                    if (eax != 0x0) {
                            if (eax == 0x1) {
                                    sub_100030d0(arg_0, esi);
                                    esp = (esp - 0x8) + 0x8;
                                    eax = 0x0;
                                    *arg_8 = 0x0;
                            }
                            else {
                                    eax = 0x0;
                                    *arg_8 = 0x0;
                            }
                    }
                    else {
                            eax = 0x0;
                            *arg_8 = 0x0;
                    }
            }
            else {
                    ebx = arg_14;
                    *ebx = malloc(0x20000);
                    sub_10002eb0(arg_c, esi);
                    edx = *ebx;
                    ecx = ecx | 0xffffffff;
                    asm { repne scasb al, byte [edi] };
                    esi = (!ecx - 0x1) + 0x1;
                    *ebx = realloc(edx, esi);
                    eax = esi;
            }
    }
    else {
            if (eax >= 0x3) {
                    if (eax > 0x4) {
                            if (eax == 0xff) {
                                    eax = sub_10002c70(esi, arg_8, decomp_var_4, saved_fp, arg_0, arg_4);
                            }
                            else {
                                    eax = 0x0;
                                    *arg_8 = 0x0;
                            }
                    }
                    else {
                            eax = 0x0;
                            *arg_8 = 0x0;
                    }
            }
            else {
                    eax = 0x0;
                    *arg_8 = 0x0;
            }
    }
    return eax;
}
