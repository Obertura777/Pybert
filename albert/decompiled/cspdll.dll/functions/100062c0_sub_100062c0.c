// sub_100062c0 @ 0x100062c0
// hopper name: sub_100062c0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_4b1f8de061f5c787694758b75407d852fd7f40b3801805e317e6117c1400ad70
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_100062c0() {
    decomp_var_7c = ebx;
    esp = esp - 0x84;
    decomp_var_84 = edi;
    eax = 0x0;
    var_74 = eax;
    asm { rep stosd  dword [edi], eax };
    edi = &var_73;
    asm { rep stosd  dword [edi], eax };
    esp = esp - 0x4;
    decomp_var_88 = 0x20;
    asm { stosw      word [edi], ax };
    ebp = sub_10006490(decomp_var_88, decomp_var_84);
    esp = esp + 0x4;
    if (ebp == 0x0) goto loc_10006434;
    goto loc_100062fd;

loc_10006434:
    eax = ebp;
    return eax;

loc_100062fd:
    ebx = fopen(arg_0, 0x1000aae8);
    esp = (esp - 0x8) + 0x8;
    if (ebx != 0x0) goto loc_1000632f;
    goto loc_1000631d;

loc_1000632f:
    eax = fgets(&var_4C, 0x50, ebx);
    esp = (esp - 0xc) + 0xc;
    if (eax == 0x0) goto loc_1000642a;
    goto loc_10006348;

loc_1000631d:
    sub_100067a0(ebp);
    eax = 0x0;
    return eax;

loc_1000642a:
    fclose(ebx);
    esp = (esp - 0x4) + 0x4;
    eax = ebp;
    return eax;

loc_10006348:
    esp = esp - 0x4;
    goto loc_1000634f;

loc_1000634f:
    eax = strrchr(&var_40, 0xa);
    esp = (esp - 0x8) + 0x8;
    if (eax != 0x0) {
            *(int8_t *)eax = 0x0;
    }
    esi = &var_38;
    while (true) {
            eax = *(int8_t *)esi;
            if (eax < 0x9) {
                    if (eax == 0x20) {
                            esi = esi + 0x1;
                            continue;
                    }
                    break;
            }
            if (eax <= 0xd) {
                    esi = esi + 0x1;
                    continue;
            }
            if (eax != 0x20) {
                    break;
            }
            esi = esi + 0x1;
    }
    eax = *(int8_t *)esi;
    if (eax == 0x0 || eax == 0x3b) goto loc_10006410;
    goto loc_1000638d;

loc_10006410:
    var_4C = ebx;
    var_50 = 0x50;
    eax = fgets(&var_14, 0x50, var_4C);
    esp = (esp - 0xc) + 0xc;
    if (eax != 0x0) {
            continue;
    }
    break;

loc_1000638d:
    esp = (esp - 0x8) + 0x8;
    ebx = strcspn(esi, 0x1000aae4);
    goto loc_1000639a;
    esp = esp + 0x4;
    goto loc_1000642a;

loc_1000639a:
    eax = *(int8_t *)(ebx + (esi - 0x1));
    ebx = ebx - 0x1;
    if (eax >= 0x9) {
            if (eax > 0xd) {
                    if (eax == 0x20 && ebx > 0x0) {
                            continue;
                    }
                    break;
            }
            else {
                    if (ebx > 0x0) {
                            continue;
                    }
                    break;
            }
    }
    else {
            if (eax == 0x20 && ebx > 0x0) {
                    continue;
            }
            break;
    }
    goto .l2;

.l2:
    ebx = ebx + 0x1;
    if (ebx > 0x1f) {
            ebx = 0x1f;
    }
    eax = strncpy(&var_50, esi, ebx);
    decomp_var_6c = esi;
    *(int8_t *)(&decomp_var_6c + ebx + 0x28) = 0x0;
    esp = (esp - 0x14) + 0x14;
    esi = strchr(decomp_var_6c, 0x3d);
    do {
            eax = esi[0x1];
            esi = esi + 0x1;
            if (eax < 0x9) {
                    if (eax == 0x20) {
                            continue;
                    }
                    break;
            }
            if (eax <= 0xd) {
                    continue;
            }
    } while (eax == 0x20);
    eax = strcspn(esi, 0x1000aae0);
    *(int8_t *)(eax + esi) = 0x0;
    eax = sub_10006500(ebp, &var_34, ebx + 0x1, esi, eax + 0x1, 0x1, var_50, var_4C);
    ebx = var_38;
    esp = (esp - 0x20) + 0x20;
    goto loc_10006410;
}
