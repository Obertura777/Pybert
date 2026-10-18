// sub_100053c0 @ 0x100053c0
// hopper name: sub_100053c0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100053c0() {
    decomp_var_4 = ebx;
    var_8 = ebp;
    decomp_var_c = esi;
    esi = arg_0;
    decomp_var_10 = edi;
    edi = arg_4;
    ebx = *(*(esi + edi * 0x4 + 0x4) + 0x1c);
    esp = esp - 0x14;
    decomp_var_14 = *(int16_t *)(ebx[0x2] + 0x2);
    eax = (*0x10009150)();
    ecx = ebx[0x2];
    ebp = eax;
    saved_fp = ebp;
    eax = *(int8_t *)ecx;
    switch (*(eax * 0x4 + switch_table)) {
        case 0:
            decomp_var_18 = ecx[0x3];
            ebp = (*0x10009150)();
            esp = esp - 0x8;
            decomp_var_1c = *(int16_t *)(ebx[0x2] + 0x4);
            eax = (*0x10009150)();
            if (*(*esi + 0x20) != 0x0) {
                    eax = sub_10004c20(esi, edi, 0x7);
            }
            else {
                    if (var_8 != 0x4) {
                            eax = sub_10004c20(esi, edi, 0x9);
                    }
                    else {
                            if (ebp != 0xda10) {
                                    eax = sub_10004c20(esi, edi, (*(int16_t *)(ebx[0x2] + 0x6) != 0xda10 ? 0x1 : 0x0) + 0x3);
                            }
                            else {
                                    if (eax != 0x1) {
                                            eax = sub_10004c20(esi, edi, 0x5);
                                    }
                                    else {
                                            eax = *(esi + edi * 0x4 + 0x4);
                                            if (eax[0x20] != 0x0) {
                                                    eax = sub_10004c20(esi, edi, 0x6);
                                            }
                                            else {
                                                    eax[0x20] = 0x2;
                                                    eax = sub_10005a90();
                                                    eax[0x2] = *(*esi + 0x40);
                                                    eax[0x3] = 0x1;
                                                    sub_10004cf0(esi, edi, eax, 0x0);
                                                    esp = (esp - 0x10) + 0x10;
                                                    sub_10005680(esi, ebx, edi, decomp_var_14, decomp_var_10, decomp_var_c, var_8, decomp_var_4, saved_fp, arg_0);
                                                    *(int16_t *)(*(esi + edi * 0x4 + 0x4) + 0x18) = 0x4;
                                                    eax = *(esi + edi * 0x4 + 0x4);
                                                    eax[0x7] = 0x0;
                                            }
                                    }
                            }
                    }
            }
            break;
        case 1:
            if (*(*esi + 0x20) == 0x0) {
                    eax = sub_10004c20(esi, edi, 0xd);
            }
            else {
                    if ((ebp & 0xffff) % 0x6 != 0x0) {
                            eax = sub_10004c20(esi, edi, 0x9);
                    }
                    else {
                            if (*(int8_t *)(*(esi + edi * 0x4 + 0x4) + 0x20) != 0x1) {
                                    eax = sub_10004c20(esi, edi, 0xc);
                            }
                            else {
                                    eax = sub_10002bc0(*dword_1000a728, ecx, &arg_0, decomp_var_14, decomp_var_10, decomp_var_c);
                                    esp = (esp - 0xc) + 0xc;
                                    *(int8_t *)(*(esi + edi * 0x4 + 0x4) + 0x20) = 0x2;
                                    sub_10005680(esi, ebx, edi, decomp_var_14, decomp_var_10, decomp_var_c, var_8, decomp_var_4, saved_fp, arg_0);
                                    *(int16_t *)(*(esi + edi * 0x4 + 0x4) + 0x18) = 0x4;
                                    eax = *(esi + edi * 0x4 + 0x4);
                                    eax[0x7] = 0x0;
                            }
                    }
            }
            break;
        case 2:
            if (*(int8_t *)(*(esi + edi * 0x4 + 0x4) + 0x20) != 0x2) {
                    eax = *(*esi + 0x20);
                    eax = sub_10004c20(esi, edi, (--eax - --eax + CARRY(EFLAGS(cf)) & 0x8) + 0x2);
            }
            else {
                    sub_10005680(esi, ebx, edi, decomp_var_14, decomp_var_10, decomp_var_c, var_8, decomp_var_4, saved_fp, arg_0);
                    *(int16_t *)(*(esi + edi * 0x4 + 0x4) + 0x18) = 0x4;
                    eax = *(esi + edi * 0x4 + 0x4);
                    eax[0x7] = 0x0;
            }
            break;
        default:
            eax = sub_10005a00(esi, edi);
            *(esi + edi * 0x4 + 0x4) = 0x0;
            esi[0x33] = 0x1;
            break;
        default:
            sub_10005680(esi, ebx, edi, decomp_var_14, decomp_var_10, decomp_var_c, var_8, decomp_var_4, saved_fp, arg_0);
            *(int16_t *)(*(esi + edi * 0x4 + 0x4) + 0x18) = 0x4;
            eax = *(esi + edi * 0x4 + 0x4);
            eax[0x7] = 0x0;
    }
    return eax;
}
