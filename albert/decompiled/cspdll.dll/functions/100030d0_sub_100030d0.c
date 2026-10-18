// sub_100030d0 @ 0x100030d0
// hopper name: sub_100030d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100030d0() {
    var_4 = ebx;
    decomp_var_c = edi;
    edi = arg_4;
    esp = esp - 0x10;
    decomp_var_10 = edi[0x1];
    eax = (*0x10009150)();
    esi = eax;
    if (edi[0x1] != 0x0) {
            ebx = saved_fp;
            decomp_var_14 = ebx;
            eax = sub_10003190(decomp_var_14);
            esp = (esp - 0x4) + 0x4;
            if ((esi & 0xffff) > 0x0) {
                    esp = esp - 0x4;
                    decomp_var_14 = ebp;
                    esi = edi + 0x6;
                    ebp = 0xfffffffa - edi;
                    do {
                            esp = esp - 0x4;
                            decomp_var_18 = *(int16_t *)(esi - 0x2);
                            saved_fp = (*0x10009150)();
                            ecx = ecx | 0xffffffff;
                            asm { repne scasb al, byte [edi] };
                            eax = *ebx;
                            ecx = !ecx - 0x1;
                            eax = sub_10006500(eax, esi, ecx, &saved_fp, 0x2, 0x0, decomp_var_18, decomp_var_14);
                            esp = (esp - 0x18) + 0x18;
                            if (eax == 0x0) {
                                    ecx = ecx | 0xffffffff;
                                    edx = ebx[0x1];
                                    asm { repne scasb al, byte [edi] };
                                    sub_10006500(edx, &saved_fp, 0x2, esi, !ecx - 0x1 & 0xff, 0x0, decomp_var_18, decomp_var_14);
                                    esp = (esp - 0x18) + 0x18;
                            }
                            esi = esi + 0x6;
                            eax = esi + ebp;
                    } while (eax < var_4);
                    esp = esp + 0x4;
            }
    }
    return eax;
}
