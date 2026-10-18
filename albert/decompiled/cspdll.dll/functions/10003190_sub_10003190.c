// sub_10003190 @ 0x10003190
// hopper name: sub_10003190
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10003190() {
    decomp_var_c = ebx;
    decomp_var_10 = ebp;
    decomp_var_14 = esi;
    esi = 0x10009189;
    esp = esp - 0x18;
    decomp_var_18 = edi;
    var_8 = 0x10009189;
    do {
            eax = *(int8_t *)(esi - 0x1);
            if (eax == 0x50) {
                    ecx = *(int8_t *)esi;
                    if (ecx > 0x0) {
                            ebx = eax << 0x8;
                            esi = esi + 0x3;
                            do {
                                    eax = esi[0x2];
                                    edx = *esi;
                                    var_4 = eax | ebx;
                                    ecx = ecx | 0xffffffff;
                                    asm { repne scasb al, byte [edi] };
                                    edi = arg_0;
                                    eax = sub_10006630(*edi, edx, !ecx - 0x1);
                                    esp = (esp - 0xc) + 0xc;
                                    if (eax != 0x0) {
                                            eax = edi[0x1];
                                            eax = sub_10006630(eax, &var_4, 0x2);
                                            esp = (esp - 0xc) + 0xc;
                                    }
                                    edx = var_8;
                                    esi = esi + 0x8;
                                    ecx = *(int8_t *)edx;
                            } while (&arg_fffffffffffffffd < ecx);
                            esi = edx;
                    }
                    esi = esi + 0x114;
                    var_8 = esi;
                    if (esi < 0x1000a719) {
                            continue;
                    }
                    break;
            }
            if (eax == 0x51) {
                    ecx = *(int8_t *)esi;
                    if (ecx > 0x0) {
                            ebx = eax << 0x8;
                            esi = esi + 0x3;
                            do {
                                    eax = esi[0x2];
                                    edx = *esi;
                                    var_4 = eax | ebx;
                                    ecx = ecx | 0xffffffff;
                                    asm { repne scasb al, byte [edi] };
                                    edi = arg_0;
                                    eax = sub_10006630(*edi, edx, !ecx - 0x1);
                                    esp = (esp - 0xc) + 0xc;
                                    if (eax != 0x0) {
                                            eax = edi[0x1];
                                            eax = sub_10006630(eax, &var_4, 0x2);
                                            esp = (esp - 0xc) + 0xc;
                                    }
                                    edx = var_8;
                                    esi = esi + 0x8;
                                    ecx = *(int8_t *)edx;
                            } while (&arg_fffffffffffffffd < ecx);
                            esi = edx;
                    }
                    esi = esi + 0x114;
                    var_8 = esi;
                    if (esi < 0x1000a719) {
                            continue;
                    }
                    break;
            }
            if (eax == 0x52) {
                    ecx = *(int8_t *)esi;
                    if (ecx > 0x0) {
                            ebx = eax << 0x8;
                            esi = esi + 0x3;
                            do {
                                    eax = esi[0x2];
                                    edx = *esi;
                                    var_4 = eax | ebx;
                                    ecx = ecx | 0xffffffff;
                                    asm { repne scasb al, byte [edi] };
                                    edi = arg_0;
                                    eax = sub_10006630(*edi, edx, !ecx - 0x1);
                                    esp = (esp - 0xc) + 0xc;
                                    if (eax != 0x0) {
                                            eax = edi[0x1];
                                            eax = sub_10006630(eax, &var_4, 0x2);
                                            esp = (esp - 0xc) + 0xc;
                                    }
                                    edx = var_8;
                                    esi = esi + 0x8;
                                    ecx = *(int8_t *)edx;
                            } while (&arg_fffffffffffffffd < ecx);
                            esi = edx;
                    }
                    esi = esi + 0x114;
                    var_8 = esi;
                    if (esi < 0x1000a719) {
                            continue;
                    }
                    break;
            }
            if (eax == 0x53) {
                    ecx = *(int8_t *)esi;
                    if (ecx > 0x0) {
                            ebx = eax << 0x8;
                            esi = esi + 0x3;
                            do {
                                    eax = esi[0x2];
                                    edx = *esi;
                                    var_4 = eax | ebx;
                                    ecx = ecx | 0xffffffff;
                                    asm { repne scasb al, byte [edi] };
                                    edi = arg_0;
                                    eax = sub_10006630(*edi, edx, !ecx - 0x1);
                                    esp = (esp - 0xc) + 0xc;
                                    if (eax != 0x0) {
                                            eax = edi[0x1];
                                            eax = sub_10006630(eax, &var_4, 0x2);
                                            esp = (esp - 0xc) + 0xc;
                                    }
                                    edx = var_8;
                                    esi = esi + 0x8;
                                    ecx = *(int8_t *)edx;
                            } while (&arg_fffffffffffffffd < ecx);
                            esi = edx;
                    }
                    esi = esi + 0x114;
                    var_8 = esi;
                    if (esi < 0x1000a719) {
                            continue;
                    }
                    break;
            }
            if (eax == 0x54) {
                    ecx = *(int8_t *)esi;
                    if (ecx > 0x0) {
                            ebx = eax << 0x8;
                            esi = esi + 0x3;
                            do {
                                    eax = esi[0x2];
                                    edx = *esi;
                                    var_4 = eax | ebx;
                                    ecx = ecx | 0xffffffff;
                                    asm { repne scasb al, byte [edi] };
                                    edi = arg_0;
                                    eax = sub_10006630(*edi, edx, !ecx - 0x1);
                                    esp = (esp - 0xc) + 0xc;
                                    if (eax != 0x0) {
                                            eax = edi[0x1];
                                            eax = sub_10006630(eax, &var_4, 0x2);
                                            esp = (esp - 0xc) + 0xc;
                                    }
                                    edx = var_8;
                                    esi = esi + 0x8;
                                    ecx = *(int8_t *)edx;
                            } while (&arg_fffffffffffffffd < ecx);
                            esi = edx;
                    }
                    esi = esi + 0x114;
                    var_8 = esi;
                    if (esi < 0x1000a719) {
                            continue;
                    }
                    break;
            }
            if (eax == 0x55) {
                    ecx = *(int8_t *)esi;
                    if (ecx > 0x0) {
                            ebx = eax << 0x8;
                            esi = esi + 0x3;
                            do {
                                    eax = esi[0x2];
                                    edx = *esi;
                                    var_4 = eax | ebx;
                                    ecx = ecx | 0xffffffff;
                                    asm { repne scasb al, byte [edi] };
                                    edi = arg_0;
                                    eax = sub_10006630(*edi, edx, !ecx - 0x1);
                                    esp = (esp - 0xc) + 0xc;
                                    if (eax != 0x0) {
                                            eax = edi[0x1];
                                            eax = sub_10006630(eax, &var_4, 0x2);
                                            esp = (esp - 0xc) + 0xc;
                                    }
                                    edx = var_8;
                                    esi = esi + 0x8;
                                    ecx = *(int8_t *)edx;
                            } while (&arg_fffffffffffffffd < ecx);
                            esi = edx;
                    }
                    esi = esi + 0x114;
                    var_8 = esi;
                    if (esi < 0x1000a719) {
                            continue;
                    }
                    break;
            }
            if (eax == 0x56) {
                    ecx = *(int8_t *)esi;
                    if (ecx > 0x0) {
                            ebx = eax << 0x8;
                            esi = esi + 0x3;
                            do {
                                    eax = esi[0x2];
                                    edx = *esi;
                                    var_4 = eax | ebx;
                                    ecx = ecx | 0xffffffff;
                                    asm { repne scasb al, byte [edi] };
                                    edi = arg_0;
                                    eax = sub_10006630(*edi, edx, !ecx - 0x1);
                                    esp = (esp - 0xc) + 0xc;
                                    if (eax != 0x0) {
                                            eax = edi[0x1];
                                            eax = sub_10006630(eax, &var_4, 0x2);
                                            esp = (esp - 0xc) + 0xc;
                                    }
                                    edx = var_8;
                                    esi = esi + 0x8;
                                    ecx = *(int8_t *)edx;
                            } while (&arg_fffffffffffffffd < ecx);
                            esi = edx;
                    }
                    esi = esi + 0x114;
                    var_8 = esi;
                    if (esi < 0x1000a719) {
                            continue;
                    }
                    break;
            }
            if (eax == 0x57) {
                    ecx = *(int8_t *)esi;
                    if (ecx > 0x0) {
                            ebx = eax << 0x8;
                            esi = esi + 0x3;
                            do {
                                    eax = esi[0x2];
                                    edx = *esi;
                                    var_4 = eax | ebx;
                                    ecx = ecx | 0xffffffff;
                                    asm { repne scasb al, byte [edi] };
                                    edi = arg_0;
                                    eax = sub_10006630(*edi, edx, !ecx - 0x1);
                                    esp = (esp - 0xc) + 0xc;
                                    if (eax != 0x0) {
                                            eax = edi[0x1];
                                            eax = sub_10006630(eax, &var_4, 0x2);
                                            esp = (esp - 0xc) + 0xc;
                                    }
                                    edx = var_8;
                                    esi = esi + 0x8;
                                    ecx = *(int8_t *)edx;
                            } while (&arg_fffffffffffffffd < ecx);
                            esi = edx;
                    }
                    esi = esi + 0x114;
                    var_8 = esi;
                    if (esi < 0x1000a719) {
                            continue;
                    }
                    break;
            }
            if (eax != 0x41) {
                    esi = esi + 0x114;
                    var_8 = esi;
                    if (esi < 0x1000a719) {
                            continue;
                    }
                    break;
            }
            ecx = *(int8_t *)esi;
            if (ecx > 0x0) {
                    ebx = eax << 0x8;
                    esi = esi + 0x3;
                    do {
                            eax = esi[0x2];
                            edx = *esi;
                            var_4 = eax | ebx;
                            ecx = ecx | 0xffffffff;
                            asm { repne scasb al, byte [edi] };
                            edi = arg_0;
                            eax = sub_10006630(*edi, edx, !ecx - 0x1);
                            esp = (esp - 0xc) + 0xc;
                            if (eax != 0x0) {
                                    eax = edi[0x1];
                                    eax = sub_10006630(eax, &var_4, 0x2);
                                    esp = (esp - 0xc) + 0xc;
                            }
                            edx = var_8;
                            esi = esi + 0x8;
                            ecx = *(int8_t *)edx;
                    } while (&arg_fffffffffffffffd < ecx);
                    esi = edx;
            }
            esi = esi + 0x114;
            var_8 = esi;
    } while (esi < 0x1000a719);
    return eax;
}
