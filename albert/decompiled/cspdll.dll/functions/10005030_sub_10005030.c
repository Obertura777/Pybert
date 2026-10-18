// sub_10005030 @ 0x10005030
// hopper name: sub_10005030
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10005030() {
    eax = arg_8;
    var_4 = ebx;
    var_8 = ebp;
    var_C = esi;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    if (eax == 0x0) {
            ebx = arg_4;
            esi = arg_0;
            while (true) {
                    eax = *(esi + ebx * 0x4 + 0x4);
                    ebp = eax[0xc];
                    if (ebp != 0x0) {
                            arg_4 = 0x1;
                            edi = (eax - (ebp & 0xffff)) + 0x18;
                    }
                    else {
                            eax = eax[0x7];
                            arg_4 = 0x0;
                            ecx = eax[0x2];
                            edi = eax[0x2];
                            edi = edi + ecx;
                            esp = esp - 0x4;
                            ebp = (*0x10009150)();
                            eax = *(esi + ebx * 0x4 + 0x4);
                            ebp = ebp + (0x4 - *(int16_t *)(eax[0x7] + 0x4));
                    }
                    decomp_var_14 = 0x0;
                    decomp_var_18 = ebp & 0xffff;
                    decomp_var_1c = edi;
                    esp = esp - 0x10;
                    decomp_var_20 = *eax;
                    eax = (*0x10009154)();
                    var_C = eax;
                    if (*(*esi + 0x44) != 0x0) {
                            sub_10003d20(esi, ebx, eax, edi, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, var_8, var_4, saved_fp, arg_0, arg_4, arg_8);
                            eax = var_C;
                            esp = (esp - 0x10) + 0x10;
                    }
                    if (eax == 0xffffffff) {
                            eax = (*0x10009178)();
                            if (eax != 0x2733) {
                                    sub_100055f0(esi, ebx, 0x5, var_4, decomp_var_20, decomp_var_1c);
                                    eax = sub_10005a00(esi, ebx);
                                    *(esi + ebx * 0x4 + 0x4) = 0x0;
                                    esi[0x33] = 0x1;
                                    esi = decomp_var_1c;
                                    ebx = decomp_var_14;
                                    esp = (esp - 0x18) + 0x28;
                                    temp_0 = 0x1;
                            }
                            else {
                                    temp_0 = 0x3;
                            }
                            break;
                    }
                    if (eax == 0x0) {
                            temp_0 = 0x0;
                            break;
                    }
                    ecx = *(esi + ebx * 0x4 + 0x4);
                    if (var_8 == 0x0) {
                            ecx = ecx[0x7];
                            ecx[0x2] = ecx[0x2] + eax;
                            if (ebp != eax) {
                                    var_4 = 0x0;
                                    continue;
                            }
                            temp_0 = 0x2;
                            break;
                    }
                    ecx[0xc] = ecx[0xc] - eax;
                    if (*(int16_t *)(*(esi + ebx * 0x4 + 0x4) + 0x18) != 0x0) {
                            var_4 = 0x0;
                            continue;
                    }
                    *(*(esi + ebx * 0x4 + 0x4) + 0x1c) = sub_10005a90();
                    edi = (*0x10009150)();
                    esp = (esp - 0x8) + 0x4;
                    *(*(*(esi + ebx * 0x4 + 0x4) + 0x1c) + 0x8) = malloc((edi & 0xffff) + 0x4);
                    eax = *(esi + ebx * 0x4 + 0x4);
                    **(eax[0x7] + 0x8) = eax[0x5];
                    eax = *(esi + ebx * 0x4 + 0x4);
                    *(int16_t *)(eax[0x7] + 0x4) = 0x4;
                    if (edi != 0x0) {
                            var_4 = 0x0;
                            continue;
                    }
                    temp_0 = 0x2;
                    break;
            }
            if (temp_0 != 0x0 && temp_0 != 0x1 && temp_0 == 0x2) {
                    eax = sub_100053c0(esi, ebx);
                    esp = (esp - 0x8) + 0x8;
            }
    }
    else {
            sub_100055f0(arg_0, arg_4, 0x5, eax, decomp_var_10, var_C);
            eax = sub_10005a00(arg_0, arg_4);
            *(arg_0 + arg_4 * 0x4 + 0x4) = 0x0;
            arg_0[0x33] = 0x1;
    }
    return eax;
}
