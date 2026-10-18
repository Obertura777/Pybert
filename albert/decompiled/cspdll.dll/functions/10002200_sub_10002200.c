// sub_10002200 @ 0x10002200
// hopper name: sub_10002200
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_cab9cc0ffb1683a85f845c0b808a6d964cb88b1ad680e7ff1329a49e9dd00f73
// binary: cspdll.dll sha256 e1135db1c8dee181c26a428639fdc98b72ab09fe459262f251723cbcc6d742ca

sub_10002200() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esi = arg_0;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = arg_c;
    ebx = 0x0;
    *(int16_t *)edi = 0x1148;
    edi[0x1] = 0x104;
    edi[0x4] = arg_8;
    eax = *esi;
    if (*(int16_t *)eax != 0x1148) goto .l6;
    goto loc_1000222c;

.l6:
    eax = 0x0;
    return eax;

loc_1000222c:
    eax = eax + 0x2;
    *esi = eax;
    if (*(int16_t *)eax != 0x40) goto .l23;
    goto loc_1000223b;

.l23:
    eax = 0x0;
    return eax;

loc_1000223b:
    *esi = eax + 0x2;
    edi[0x3] = eax[0x1];
    ecx = *esi;
    eax = ecx + 0x2;
    *esi = ecx + 0x2;
    ecx = *(int16_t *)eax;
    *esi = eax + 0x2;
    edi[0x4] = sub_10001640(ecx);
    eax = *esi;
    esp = (esp - 0x4) + 0x4;
    if (*(int16_t *)eax != 0x140) goto .l7;
    goto loc_10002272;

.l7:
    eax = 0x0;
    return eax;

loc_10002272:
    eax = eax + 0x2;
    *esi = eax;
    if (*(int16_t *)eax != 0x40) goto .l8;
    goto loc_10002281;

.l8:
    eax = 0x0;
    return eax;

loc_10002281:
    eax = eax + 0x2;
    *esi = eax;
    ecx = eax + 0x2;
    if (eax[0x1] == 0x8243) goto loc_100022a8;
    goto loc_10002291;

loc_100022a8:
    eax = *(int16_t *)eax;
    *esi = ecx;
    edi[0x6] = HIBYTE(eax);
    edi[0x36] = *(int16_t *)*esi;
    *esi = *esi + 0x2;
    eax = edi[0x36];
    bool_79 = eax == 0x2343;
    if (eax > 0x2343) goto loc_100023c1;
    goto .l62;

loc_10002291:
    esp = (esp - 0x8) + 0x8;
    if (sub_10002830(esi, edi + 0xc) == 0x0) goto .l9;
    goto loc_100022a6;

loc_100023c1:
    if (eax != 0x2443) {
            if (eax == 0x4143) {
                    decomp_var_10 = edi[0x7];
                    esp = esp - 0x8;
                    decomp_var_14 = edi + 0x6e;
                    esp = (esp - 0x4) + 0xc;
                    if (sub_10002990(esi, decomp_var_14, decomp_var_10) != 0x0) {
                            eax = *esi;
                            if (*(int16_t *)eax == 0x140) {
                                    eax = eax + 0x2;
                                    *esi = eax;
                                    if (*(int16_t *)eax == 0x40) {
                                            *esi = eax + 0x2;
                                            edi[0x80] = eax[0x1];
                                            edi = *esi;
                                            *esi = edi + 0x2;
                                            ecx = edi[0x1];
                                            eax = edi + 0x4;
                                            *esi = eax;
                                            if (ecx == 0x645) {
                                                    if (*(int16_t *)eax == 0x140) {
                                                            *esi = eax + 0x2;
                                                            ebx = 0x1;
                                                    }
                                            }
                                            else {
                                                    ebx = 0x1;
                                            }
                                    }
                            }
                            eax = ebx;
                    }
                    else {
                            eax = 0x0;
                    }
            }
            else {
                    eax = *esi;
                    if (*(int16_t *)eax == 0x140) {
                            eax = eax + 0x2;
                            *esi = eax;
                            if (*(int16_t *)eax == 0x40) {
                                    *esi = eax + 0x2;
                                    edi[0x80] = eax[0x1];
                                    edi = *esi;
                                    *esi = edi + 0x2;
                                    ecx = edi[0x1];
                                    eax = edi + 0x4;
                                    *esi = eax;
                                    if (ecx == 0x645) {
                                            if (*(int16_t *)eax == 0x140) {
                                                    *esi = eax + 0x2;
                                                    ebx = 0x1;
                                            }
                                    }
                                    else {
                                            ebx = 0x1;
                                    }
                            }
                    }
                    eax = ebx;
            }
    }
    else {
            esp = (esp - 0x8) + 0x8;
            if (sub_10002830(esi, edi + 0x74) != 0x0) {
                    eax = *esi;
                    if (*(int16_t *)eax == 0x2343) {
                            *esi = eax + 0x2;
                            esp = (esp - 0xc) + 0xc;
                            if (sub_10002990(esi, edi + 0x6e, edi[0x3b]) != 0x0) {
                                    eax = *esi;
                                    if (*(int16_t *)eax == 0x140) {
                                            eax = eax + 0x2;
                                            *esi = eax;
                                            if (*(int16_t *)eax == 0x40) {
                                                    *esi = eax + 0x2;
                                                    edi[0x80] = eax[0x1];
                                                    edi = *esi;
                                                    *esi = edi + 0x2;
                                                    ecx = edi[0x1];
                                                    eax = edi + 0x4;
                                                    *esi = eax;
                                                    if (ecx == 0x645) {
                                                            if (*(int16_t *)eax == 0x140) {
                                                                    *esi = eax + 0x2;
                                                                    ebx = 0x1;
                                                            }
                                                    }
                                                    else {
                                                            ebx = 0x1;
                                                    }
                                            }
                                    }
                                    eax = ebx;
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = *esi;
                            if (*(int16_t *)eax == 0x140) {
                                    eax = eax + 0x2;
                                    *esi = eax;
                                    if (*(int16_t *)eax == 0x40) {
                                            *esi = eax + 0x2;
                                            edi[0x80] = eax[0x1];
                                            edi = *esi;
                                            *esi = edi + 0x2;
                                            ecx = edi[0x1];
                                            eax = edi + 0x4;
                                            *esi = eax;
                                            if (ecx == 0x645) {
                                                    if (*(int16_t *)eax == 0x140) {
                                                            *esi = eax + 0x2;
                                                            ebx = 0x1;
                                                    }
                                            }
                                            else {
                                                    ebx = 0x1;
                                            }
                                    }
                            }
                            eax = ebx;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    return eax;

.l62:
    if (bool_79) goto loc_100023cf;
    goto loc_100022e1;

.l9:
    eax = 0x0;
    return eax;

loc_100022a6:
    edi[0x36] = *(int16_t *)*esi;
    *esi = *esi + 0x2;
    eax = edi[0x36];
    bool_23 = eax == 0x2343;
    if (eax > 0x2343) goto .l50;
    goto loc_100022db;

loc_100023cf:
    decomp_var_10 = edi[0x7];
    esp = esp - 0x8;
    decomp_var_14 = edi + 0x6e;
    esp = (esp - 0x4) + 0xc;
    if (sub_10002990(esi, decomp_var_14, decomp_var_10) != 0x0) {
            eax = *esi;
            if (*(int16_t *)eax == 0x140) {
                    eax = eax + 0x2;
                    *esi = eax;
                    if (*(int16_t *)eax == 0x40) {
                            *esi = eax + 0x2;
                            edi[0x80] = eax[0x1];
                            edi = *esi;
                            *esi = edi + 0x2;
                            ecx = edi[0x1];
                            eax = edi + 0x4;
                            *esi = eax;
                            if (ecx == 0x645) {
                                    if (*(int16_t *)eax == 0x140) {
                                            *esi = eax + 0x2;
                                            ebx = 0x1;
                                    }
                            }
                            else {
                                    ebx = 0x1;
                            }
                    }
            }
            eax = ebx;
    }
    else {
            eax = 0x0;
    }
    return eax;

loc_100022e1:
    if (eax == 0x2043) goto .l64;
    goto loc_100022e8;

.l50:
    if (eax == 0x2443) goto loc_100023dd;
    goto loc_100023c8;

loc_100022db:
    if (bool_23) goto .l44;
    goto .l86;

.l64:
    esp = (esp - 0xc) + 0xc;
    if (sub_10002990(esi, edi + 0x6e, 0x42) == 0x0) goto .l16;
    goto loc_10002350;

loc_100022e8:
    if (eax != 0x2143) goto .l2;
    goto loc_100022f3;

loc_100023dd:
    esp = (esp - 0x8) + 0x8;
    if (sub_10002830(esi, edi + 0x74) == 0x0) goto .l21;
    goto loc_100023ee;

loc_100023c8:
    if (eax != 0x4143) goto .l4;
    goto .l59;

.l44:
    decomp_var_10 = edi[0x7];
    esp = esp - 0x8;
    decomp_var_14 = edi + 0x6e;
    esp = (esp - 0x4) + 0xc;
    if (sub_10002990(esi, decomp_var_14, decomp_var_10) == 0x0) goto .l54;
    goto .l24;

.l86:
    if (eax == 0x2043) goto loc_10002339;
    goto .l80;

.l16:
    eax = 0x0;
    return eax;

loc_10002350:
    eax = *esi;
    if (*(int16_t *)eax != 0x2543) goto .l17;
    goto loc_1000235d;

.l2:
    eax = *esi;
    if (*(int16_t *)eax != 0x140) goto .l69;
    goto .l3;

loc_100022f3:
    esp = (esp - 0x8) + 0x8;
    if (sub_10002830(esi, edi + 0x74) == 0x0) goto .l68;
    goto loc_10002308;

.l21:
    eax = 0x0;
    return eax;

loc_100023ee:
    eax = *esi;
    if (*(int16_t *)eax != 0x2343) goto .l5;
    goto loc_100023f7;

.l4:
    eax = *esi;
    if (*(int16_t *)eax != 0x140) goto .l46;
    goto .l45;

.l59:
    decomp_var_10 = edi[0x7];
    esp = esp - 0x8;
    decomp_var_14 = edi + 0x6e;
    esp = (esp - 0x4) + 0xc;
    if (sub_10002990(esi, decomp_var_14, decomp_var_10) == 0x0) goto .l73;
    goto .l34;

.l54:
    eax = 0x0;
    return eax;

.l24:
    eax = *esi;
    if (*(int16_t *)eax != 0x140) goto .l48;
    goto .l41;

loc_10002339:
    esp = (esp - 0xc) + 0xc;
    if (sub_10002990(esi, edi + 0x6e, 0x42) != 0x0) {
            eax = *esi;
            if (*(int16_t *)eax == 0x2543) {
                    eax = eax + 0x2;
                    *esi = eax;
                    if (*(int16_t *)eax == 0x40) {
                            *esi = eax + 0x2;
                            edi[0x6a] = 0x0;
                            eax = *esi;
                            ecx = *(int16_t *)eax;
                            if (ecx != 0x140) {
                                    *esi = eax + 0x2;
                                    *(int16_t *)(edi + edi[0x6a] * 0x2 + 0xd6) = ecx;
                                    edi[0x6a] = edi[0x6a] + 0x1;
                                    eax = *esi;
                                    ecx = *(int16_t *)eax;
                                    if (ecx != 0x140) {
                                            continue;
                                    }
                                    break;
                            }
                            eax = *esi;
                            if (*(int16_t *)eax == 0x140) {
                                    *esi = eax + 0x2;
                                    eax = *esi;
                                    if (*(int16_t *)eax == 0x140) {
                                            eax = eax + 0x2;
                                            *esi = eax;
                                            if (*(int16_t *)eax == 0x40) {
                                                    *esi = eax + 0x2;
                                                    edi[0x80] = eax[0x1];
                                                    edi = *esi;
                                                    *esi = edi + 0x2;
                                                    ecx = edi[0x1];
                                                    eax = edi + 0x4;
                                                    *esi = eax;
                                                    if (ecx == 0x645 && *(int16_t *)eax == 0x140) {
                                                            *esi = eax + 0x2;
                                                    }
                                            }
                                    }
                                    eax = 0x1;
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;

.l80:
    if (eax != 0x2143) goto .l91;
    goto .l76;

.l17:
    eax = 0x0;
    return eax;

loc_1000235d:
    eax = eax + 0x2;
    *esi = eax;
    if (*(int16_t *)eax != 0x40) goto .l18;
    goto loc_1000236c;

.l69:
    eax = ebx;
    return eax;

.l3:
    eax = eax + 0x2;
    *esi = eax;
    if (*(int16_t *)eax != 0x40) goto .l69;
    goto .l70;

.l68:
    eax = 0x0;
    return eax;

loc_10002308:
    eax = *esi;
    if (*(int16_t *)eax != 0x2043) goto .l11;
    goto loc_10002315;

.l5:
    eax = *esi;
    if (*(int16_t *)eax != 0x140) goto .l29;
    goto .l83;

loc_100023f7:
    *esi = eax + 0x2;
    esp = (esp - 0xc) + 0xc;
    if (sub_10002990(esi, edi + 0x6e, edi[0x3b]) == 0x0) goto loc_1000245e;
    goto loc_10002412;

.l46:
    eax = ebx;
    return eax;

.l45:
    eax = eax + 0x2;
    *esi = eax;
    if (*(int16_t *)eax != 0x40) goto .l46;
    goto .l52;

.l73:
    eax = 0x0;
    return eax;

.l34:
    eax = *esi;
    if (*(int16_t *)eax != 0x140) goto .l55;
    goto .l56;

.l48:
    eax = ebx;
    return eax;

.l41:
    eax = eax + 0x2;
    *esi = eax;
    if (*(int16_t *)eax != 0x40) goto .l48;
    goto .l49;

.l91:
    eax = *esi;
    if (*(int16_t *)eax != 0x140) goto .l78;
    goto .l40;

.l76:
    esp = (esp - 0x8) + 0x8;
    if (sub_10002830(esi, edi + 0x74) == 0x0) goto .l10;
    goto .l84;

.l18:
    eax = 0x0;
    return eax;

loc_1000236c:
    ebx = 0x0;
    *esi = eax + 0x2;
    edi[0x6a] = 0x0;
    eax = *esi;
    ecx = *(int16_t *)eax;
    if (ecx != 0x140) {
            do {
                    *esi = eax + 0x2;
                    *(int16_t *)(edi + edi[0x6a] * 0x2 + 0xd6) = ecx;
                    edi[0x6a] = edi[0x6a] + 0x1;
                    eax = *esi;
                    ecx = *(int16_t *)eax;
            } while (ecx != 0x140);
    }
    eax = *esi;
    if (*(int16_t *)eax != 0x140) goto .l19;
    goto loc_100023ba;

.l70:
    *esi = eax + 0x2;
    edi[0x80] = eax[0x1];
    edi = *esi;
    *esi = edi + 0x2;
    ecx = edi[0x1];
    eax = edi + 0x4;
    *esi = eax;
    if (ecx != 0x645) goto loc_10002459;
    goto loc_1000244d;

.l11:
    eax = 0x0;
    return eax;

loc_10002315:
    *esi = eax + 0x2;
    decomp_var_10 = edi[0x3b];
    esp = esp - 0x8;
    decomp_var_14 = edi + 0x6e;
    esp = (esp - 0x4) + 0xc;
    if (sub_10002990(esi, decomp_var_14, decomp_var_10) == 0x0) goto .l20;
    goto loc_10002334;

.l29:
    eax = ebx;
    return eax;

.l83:
    eax = eax + 0x2;
    *esi = eax;
    if (*(int16_t *)eax != 0x40) goto .l29;
    goto loc_10002426;

loc_1000245e:
    eax = 0x0;
    return eax;

loc_10002412:
    eax = *esi;
    if (*(int16_t *)eax != 0x140) goto .l32;
    goto .l26;

.l52:
    *esi = eax + 0x2;
    edi[0x80] = eax[0x1];
    edi = *esi;
    *esi = edi + 0x2;
    ecx = edi[0x1];
    eax = edi + 0x4;
    *esi = eax;
    if (ecx != 0x645) goto .l53;
    goto .l33;

.l55:
    eax = ebx;
    return eax;

.l56:
    eax = eax + 0x2;
    *esi = eax;
    if (*(int16_t *)eax != 0x40) goto .l55;
    goto .l71;

.l49:
    *esi = eax + 0x2;
    edi[0x80] = eax[0x1];
    edi = *esi;
    *esi = edi + 0x2;
    ecx = edi[0x1];
    eax = edi + 0x4;
    *esi = eax;
    if (ecx != 0x645) goto .l43;
    goto .l51;

.l78:
    eax = ebx;
    return eax;

.l40:
    eax = eax + 0x2;
    *esi = eax;
    if (*(int16_t *)eax != 0x40) goto .l78;
    goto .l79;

.l10:
    eax = 0x0;
    return eax;

.l84:
    eax = *esi;
    if (*(int16_t *)eax != 0x2043) goto .l81;
    goto .l75;

.l19:
    eax = 0x0;
    return eax;

loc_100023ba:
    *esi = eax + 0x2;
    eax = *esi;
    if (*(int16_t *)eax != 0x140) goto .l15;
    goto loc_1000241b;

loc_10002459:
    ebx = 0x1;
    goto .l69;

loc_1000244d:
    if (*(int16_t *)eax != 0x140) goto .l69;
    goto .l12;

.l20:
    eax = 0x0;
    return eax;

loc_10002334:
    eax = *esi;
    if (*(int16_t *)eax != 0x140) goto .l35;
    goto .l22;

loc_10002426:
    *esi = eax + 0x2;
    edi[0x80] = eax[0x1];
    edi = *esi;
    *esi = edi + 0x2;
    ecx = edi[0x1];
    eax = edi + 0x4;
    *esi = eax;
    if (ecx != 0x645) goto .l77;
    goto .l30;

.l32:
    eax = ebx;
    return eax;

.l26:
    eax = eax + 0x2;
    *esi = eax;
    if (*(int16_t *)eax != 0x40) goto .l32;
    goto .l31;

.l53:
    ebx = 0x1;
    goto .l46;

.l33:
    if (*(int16_t *)eax != 0x140) goto .l46;
    goto .l72;

.l71:
    *esi = eax + 0x2;
    edi[0x80] = eax[0x1];
    edi = *esi;
    *esi = edi + 0x2;
    ecx = edi[0x1];
    eax = edi + 0x4;
    *esi = eax;
    if (ecx != 0x645) goto .l58;
    goto .l47;

.l43:
    ebx = 0x1;
    goto .l48;

.l51:
    if (*(int16_t *)eax != 0x140) goto .l48;
    goto .l42;

.l79:
    *esi = eax + 0x2;
    edi[0x80] = eax[0x1];
    edi = *esi;
    *esi = edi + 0x2;
    ecx = edi[0x1];
    eax = edi + 0x4;
    *esi = eax;
    if (ecx != 0x645) goto .l39;
    goto .l38;

.l81:
    eax = 0x0;
    return eax;

.l75:
    *esi = eax + 0x2;
    decomp_var_10 = edi[0x3b];
    esp = esp - 0x8;
    decomp_var_14 = edi + 0x6e;
    esp = (esp - 0x4) + 0xc;
    if (sub_10002990(esi, decomp_var_14, decomp_var_10) == 0x0) goto .l85;
    goto .l74;

.l15:
    eax = ebx;
    return eax;

loc_1000241b:
    eax = eax + 0x2;
    *esi = eax;
    if (*(int16_t *)eax != 0x40) goto .l15;
    goto .l60;

.l12:
    *esi = eax + 0x2;
    goto loc_10002459;

.l35:
    eax = ebx;
    return eax;

.l22:
    eax = eax + 0x2;
    *esi = eax;
    if (*(int16_t *)eax != 0x40) goto .l35;
    goto .l36;

.l77:
    ebx = 0x1;
    goto .l29;

.l30:
    if (*(int16_t *)eax != 0x140) goto .l29;
    goto .l82;

.l31:
    *esi = eax + 0x2;
    edi[0x80] = eax[0x1];
    edi = *esi;
    *esi = edi + 0x2;
    ecx = edi[0x1];
    eax = edi + 0x4;
    *esi = eax;
    if (ecx != 0x645) goto .l27;
    goto .l28;

.l72:
    *esi = eax + 0x2;
    goto .l53;

.l58:
    ebx = 0x1;
    goto .l55;

.l47:
    if (*(int16_t *)eax != 0x140) goto .l55;
    goto .l57;

.l42:
    *esi = eax + 0x2;
    goto .l43;

.l39:
    ebx = 0x1;
    goto .l78;

.l38:
    if (*(int16_t *)eax != 0x140) goto .l78;
    goto .l37;

.l85:
    eax = 0x0;
    return eax;

.l74:
    eax = *esi;
    if (*(int16_t *)eax != 0x140) goto .l61;
    goto .l89;

.l60:
    *esi = eax + 0x2;
    edi[0x80] = eax[0x1];
    edi = *esi;
    *esi = edi + 0x2;
    ecx = edi[0x1];
    eax = edi + 0x4;
    *esi = eax;
    if (ecx != 0x645) goto .l63;
    goto .l90;

.l36:
    *esi = eax + 0x2;
    edi[0x80] = eax[0x1];
    edi = *esi;
    *esi = edi + 0x2;
    ecx = edi[0x1];
    eax = edi + 0x4;
    *esi = eax;
    if (ecx != 0x645) goto .l13;
    goto .l66;

.l82:
    *esi = eax + 0x2;
    goto .l77;

.l27:
    ebx = 0x1;
    goto .l32;

.l28:
    if (*(int16_t *)eax != 0x140) goto .l32;
    goto .l25;

.l57:
    *esi = eax + 0x2;
    goto .l58;

.l37:
    *esi = eax + 0x2;
    goto .l39;

.l61:
    eax = ebx;
    return eax;

.l89:
    eax = eax + 0x2;
    *esi = eax;
    if (*(int16_t *)eax != 0x40) goto .l61;
    goto .l67;

.l63:
    ebx = 0x1;
    goto .l15;

.l90:
    if (*(int16_t *)eax != 0x140) goto .l15;
    goto loc_10002454;

.l13:
    ebx = 0x1;
    goto .l35;

.l66:
    if (*(int16_t *)eax != 0x140) goto .l35;
    goto .l14;

.l25:
    *esi = eax + 0x2;
    goto .l27;

.l67:
    *esi = eax + 0x2;
    edi[0x80] = eax[0x1];
    edi = *esi;
    *esi = edi + 0x2;
    ecx = edi[0x1];
    eax = edi + 0x4;
    *esi = eax;
    if (ecx != 0x645) goto .l87;
    goto .l65;

loc_10002454:
    *esi = eax + 0x2;
    goto .l63;

.l14:
    *esi = eax + 0x2;
    goto .l13;

.l87:
    ebx = 0x1;
    goto .l61;

.l65:
    if (*(int16_t *)eax != 0x140) goto .l61;

.l88:
    *esi = eax + 0x2;
    goto .l87;
}
