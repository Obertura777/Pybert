// sub_10002a30 @ 0x10002a30
// hopper name: sub_10002a30
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10002a30() {
    ebx = malloc(0x8);
    esp = (esp - 0x18) + 0x4;
    if (ebx != 0x0) {
            *ebx = 0x0;
            ebx[0x1] = 0x0;
            eax = sub_10006490(0x80, decomp_var_c);
            esp = (esp - 0x4) + 0x4;
            *ebx = eax;
            if (eax == 0x0) {
                    sub_10002b90(ebx);
                    eax = 0x0;
            }
            else {
                    eax = sub_10006490(0x80, decomp_var_c);
                    esp = (esp - 0x4) + 0x4;
                    ebx[0x1] = eax;
                    if (eax == 0x0) {
                            sub_10002b90(ebx);
                            eax = 0x0;
                    }
                    else {
                            decomp_var_10 = ebp;
                            ebp = 0x10009189;
                            decomp_var_14 = esi;
                            esp = esp - 0xc;
                            decomp_var_18 = edi;
                            var_8 = 0x10009189;
                            do {
                                    eax = var_4;
                                    saved_fp = 0x0;
                                    if (*(int8_t *)ebp > 0x0) {
                                            eax = (eax & 0xff) << 0x8;
                                            arg_0 = eax;
                                            ebp = &ret_addr;
                                            while (true) {
                                                    esi = *ebp;
                                                    var_4 = arg_0 | eax;
                                                    ecx = arg_0 | eax | 0xffffffff;
                                                    esp = esp - 0x4;
                                                    decomp_var_1c = 0x0;
                                                    asm { repne scasb al, byte [edi] };
                                                    eax = *ebx;
                                                    ecx = !ecx - 0x1;
                                                    eax = sub_10006500(eax, esi, ecx, &var_4, 0x2, decomp_var_1c, decomp_var_18, decomp_var_14);
                                                    esp = (esp - 0x14) + 0x18;
                                                    if (eax == 0x0) {
                                                            ecx = ecx | 0xffffffff;
                                                            edx = ebx[0x1];
                                                            asm { repne scasb al, byte [edi] };
                                                            eax = sub_10006500(edx, &var_4, 0x2, esi, !ecx - 0x1 & 0xff, 0x0, decomp_var_18, decomp_var_14);
                                                            esp = (esp - 0x18) + 0x18;
                                                            if (eax != 0x0) {
                                                                    sub_10002b90(ebx);
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    ebx = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            sub_10002b90(ebx);
                                                            esp = (esp - 0x4) + 0x4;
                                                            ebx = 0x0;
                                                    }
                                                    edx = var_8;
                                                    ebp = &arg_4;
                                                    bool_7 = saved_fp + 0x1 < *(int8_t *)edx;
                                                    saved_fp = saved_fp + 0x1;
                                                    if (!bool_7) {
                                                            break;
                                                    }
                                                    eax = arg_0;
                                            }
                                    }
                                    ebp = &arg_110;
                                    var_8 = ebp;
                            } while (ebp < 0x1000a719);
                            eax = ebx;
                    }
            }
    }
    else {
            eax = ebx;
    }
    return eax;
}
