// sub_10005210 @ 0x10005210
// hopper name: sub_10005210
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10005210() {
    eax = arg_8;
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    var_C = esi;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    if (eax == 0x0) {
            edi = arg_0;
            ebx = arg_4;
            while (true) {
                    eax = *(edi + ebx * 0x4 + 0x4);
                    if ((eax[0x8] & 0x10) != 0x0) {
                            temp_0 = 0x0;
                            break;
                    }
                    esi = eax[0x3];
                    decomp_var_14 = *(int16_t *)(esi[0x2] + 0x2);
                    ebp = (*0x10009150)();
                    eax = esi[0x2];
                    ecx = esi[0x2];
                    decomp_var_18 = 0x0;
                    decomp_var_1c = ((ebp & 0xffff) - ecx) + 0x4;
                    decomp_var_20 = eax + ecx;
                    esp = esp - 0x14;
                    decomp_var_24 = **(edi + ebx * 0x4 + 0x4);
                    eax = (*0x10009158)();
                    var_C = eax;
                    if (*(*edi + 0x44) != 0x0) {
                            sub_10003c90(edi, ebx, eax, esi[0x2] + esi[0x2], decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, var_C, decomp_var_8, decomp_var_4, saved_fp, arg_0, arg_4);
                            eax = var_C;
                            esp = (esp - 0x10) + 0x10;
                    }
                    if (eax == 0xffffffff) {
                            sub_100055f0(edi, ebx, 0x6, (*0x10009178)(), decomp_var_24, decomp_var_20);
                            eax = sub_10005a00(edi, ebx);
                            *(edi + ebx * 0x4 + 0x4) = 0x0;
                            esp = (esp - 0x18) + 0x18;
                            edi[0x33] = 0x1;
                            temp_0 = 0x2;
                            break;
                    }
                    esi[0x2] = esi[0x2] + eax;
                    eax = esi[0x2];
                    eax = eax & 0xffff;
                    if (eax < &arg_0) {
                            temp_0 = 0x0;
                            break;
                    }
                    *(*(edi + ebx * 0x4 + 0x4) + 0xc) = *esi;
                    eax = *(edi + ebx * 0x4 + 0x4);
                    if (eax[0x3] == 0x0) {
                            eax[0x4] = 0x0;
                    }
                    eax = esi[0x3];
                    *esi = 0x0;
                    if (eax == 0x0) {
                            free(esi[0x2]);
                            esp = (esp - 0x4) + 0x4;
                            esi[0x2] = 0x0;
                    }
                    free(esi);
                    eax = *(edi + ebx * 0x4 + 0x4);
                    esp = (esp - 0x4) + 0x4;
                    if (eax[0x3] != 0x0) {
                            continue;
                    }
                    temp_0 = 0x1;
                    break;
            }
    }
    else {
            sub_100055f0(arg_0, arg_4, 0x6, eax, decomp_var_10, var_C);
            eax = sub_10005a00(arg_0, arg_4);
            *(arg_0 + arg_4 * 0x4 + 0x4) = 0x0;
            arg_0[0x33] = 0x1;
    }
    return eax;
}
