// sub_10003250 @ 0x10003250
// hopper name: sub_10003250
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10003250() {
    decomp_var_4 = ecx;
    esp = (esp - 0x14) + 0xc;
    if (strncmp(arg_4, 0x100090ac, 0x3) == 0x0) {
            eax = sub_100034a0(arg_8, decomp_var_4, saved_fp);
    }
    else {
            edi = malloc(0xffff);
            esp = (esp - 0x4) + 0x4;
            if (edi != 0x0) {
                    decomp_var_4 = ebp;
                    ebp = arg_c;
                    eax = edi + 0x4;
                    esp = esp - 0x8;
                    arg_0 = eax;
                    ecx = *(int8_t *)ebp;
                    if (ecx != 0x0) {
                            esi = arg_8;
                            while (true) {
                                    ecx = sign_extend_32(ecx) - 0x20;
                                    if (ecx > 0x19) {
                                            sub_100033c0(esi, ebp, 0x3);
                                            eax = arg_0 + 0x2;
                                            esp = (esp - 0x10) + 0x10;
                                            arg_0 = eax;
                                            arg_c = arg_c + 0x3;
                                            ebp = arg_c;
                                            ecx = *(int8_t *)ebp;
                                            if (ecx != 0x0) {
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    eax = (*(ecx[0x10003398] * 0x4 + 0x10003384))();
                                    temp_0 = 0x0;
                                    break;
                            }
                            if (temp_0 != 0x0) {
                                    *(int8_t *)edi = 0x2;
                                    edi[0x1] = (*0x10009140)();
                                    eax = realloc(edi, eax - edi & 0xffff);
                            }
                    }
                    else {
                            *(int8_t *)edi = 0x2;
                            edi[0x1] = (*0x10009140)();
                            eax = realloc(edi, eax - edi & 0xffff);
                    }
            }
            else {
                    eax = edi;
            }
    }
    return eax;
}
