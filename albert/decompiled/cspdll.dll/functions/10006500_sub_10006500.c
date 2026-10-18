// sub_10006500 @ 0x10006500
// hopper name: sub_10006500
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10006500() {
    var_4 = ecx;
    decomp_var_8 = ebx;
    ebx = arg_0;
    decomp_var_c = ebp;
    decomp_var_10 = esi;
    esi = arg_4;
    edi = arg_8;
    eax = sub_100066d0(ebx, esi, edi, &var_4, &arg_4);
    esp = (esp - 0x28) + 0x14;
    if (eax == 0x0) {
            sub_10006630(ebx, esi, edi);
            esp = (esp - 0xc) + 0xc;
    }
    edi = edi & 0xff;
    ebp = malloc(edi);
    esp = (esp - 0x4) + 0x4;
    bool_3 = true;
    bool_2 = true;
    if (ebp == 0x0) {
            eax = 0x1;
    }
    else {
            *ebp = *esi;
            asm { rep movsb  byte [edi], byte [esi] };
            esi = arg_14;
            ebx = malloc(esi);
            esp = (esp - 0x4) + 0x4;
            bool_7 = true;
            bool_6 = true;
            if (ebx == 0x0) {
                    free(ebp);
                    eax = 0x1;
            }
            else {
                    *ebx = *arg_14;
                    asm { rep movsb  byte [edi], byte [esi] };
                    edi = arg_8;
                    esi = sub_10006750(edi, ebp, arg_10);
                    eax = malloc(0x1c);
                    esp = (esp - 0x10) + 0x10;
                    if (eax == 0x0) {
                            free(ebp);
                            free(ebx);
                            eax = 0x1;
                    }
                    else {
                            eax[0x6] = arg_1c;
                            eax[0x3] = ebp;
                            eax[0x10] = arg_14;
                            eax[0x5] = ebx;
                            eax[0x2] = eax;
                            *eax = 0x0;
                            eax[0x1] = 0x0;
                            eax[0x1] = *(edi[0x1] + (esi * 0x8 - esi << 0x2) + 0x4);
                            ecx = (esi * 0x8 - esi << 0x2) + edi[0x1];
                            *eax = ecx;
                            ecx[0x1] = eax;
                            *eax[0x1] = eax;
                            eax = 0x0;
                    }
            }
    }
    return eax;
}
