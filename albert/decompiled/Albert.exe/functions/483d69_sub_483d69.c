// sub_483d69 @ 0x483d69
// hopper name: sub_483d69
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_483d69() {
    intrinsic_movlpd(xmm0, arg_0);
    intrinsic_movlpd(xmm7, 2.22507e-308);
    intrinsic_movlpd(xmm2, 1.0);
    intrinsic_andpd(xmm7, xmm0);
    xmm4 = xmm0;
    xmm0 = intrinsic_psrlq(xmm0, 0x2c);
    intrinsic_pextrw(xmm0, 0x0);
    intrinsic_orpd(xmm7, xmm2);
    intrinsic_pextrw(xmm4, 0x3);
    xmm7 = xmm7 * *(double *)(((eax & 0xff) + 0x1 & 0x1fe) * 0x4 + double_value_1);
    xmm5 = intrinsic_movlpd(xmm5, *(int64_t *)(((eax & 0xff) + 0x1 & 0x1fe) * 0x4 + double_value_1));
    xmm6 = intrinsic_movapd(xmm6, *(int128_t *)((eax + eax) * 0x4 + 0x4b3fb0));
    edx = 0x7fef - ecx;
    bool_41 = true;
    bool_40 = true;
    bool_39 = true;
    bool_38 = true;
    bool_37 = true;
    bool_30 = true;
    if ((ecx - 0x10 | edx) >= 0x80000000) goto loc_4840b7;
    goto loc_483ddc;

loc_4840b7:
    intrinsic_movlpd(xmm1, arg_8);
    xmm3 = intrinsic_movlpd(xmm3, Nan);
    eax = zero_extend_32(xmm1);
    xmm2 = xmm1;
    xmm1 = intrinsic_andpd(xmm1, xmm3);
    xmm1 = intrinsic_psrlq(xmm1, 0x20);
    ecx = zero_extend_32(xmm1);
    if (ecx >= 0x7ff00000) goto loc_4841c0;
    goto loc_4840e6;

loc_483ddc:
    ecx = 0x0;
    edx = 0x3fe7f;
    goto loc_483de6;

loc_4841c0:
    intrinsic_movlpd(xmm7, arg_0);
    xmm4 = intrinsic_movlpd(xmm4, arg_0);
    edx = zero_extend_32(xmm7);
    xmm7 = intrinsic_psrlq(xmm7, 0x20);
    ecx = zero_extend_32(xmm7);
    eax = zero_extend_32(xmm7) & 0x7fffffff;
    bool_54 = eax > 0x7ff00000;
    bool_50 = true;
    if (eax < 0x7ff00000) goto .l16;
    goto loc_4841eb;

loc_4840e6:
    eax = eax | ecx;
    if (eax == 0x0) goto loc_48450d;
    goto loc_4840f1;

loc_483de6:
    xmm0 = intrinsic_psubq(xmm0, zero_extend_32(edx));
    xmm0 = intrinsic_psrlq(xmm0, 0x8);
    intrinsic_cvtdq2pd(xmm0, xmm0);
    intrinsic_movlpd(xmm1, Nan);
    intrinsic_pextrw(intrinsic_psrlq(xmm7, 0x26), 0x0);
    intrinsic_andpd(xmm4, 2.22507e-308);
    intrinsic_addpd(xmm6, *(int128_t *)((((eax & 0xff) + 0x1 & 0x1fe) + ((eax & 0xff) + 0x1 & 0x1fe)) * 0x4 + 0x4b4bd0));
    intrinsic_andpd(xmm1, intrinsic_orpd(xmm4, 1.0));
    intrinsic_pextrw(intrinsic_psrlq(xmm3, 0x1f), 0x0);
    intrinsic_movlpd(xmm0, Nan);
    intrinsic_movlpd(xmm7, -1.44269);
    intrinsic_addpd(xmm6, *(int128_t *)(((eax & 0x1ff) + 0x1 & 0x3fe) * 0x8 + 0x4b5bf0));
    xmm0 = intrinsic_andpd(xmm0, xmm5);
    xmm1 = intrinsic_movlpd(xmm1 * (xmm5 - xmm0), arg_8);
    intrinsic_pextrw(xmm1, 0x3);
    xmm3 = intrinsic_movlpd(xmm3, Nan);
    edx = intrinsic_pextrw(xmm6, 0x3);
    xmm2 = xmm2 - xmm4;
    xmm4 = xmm6;
    xmm0 = xmm0 + xmm7;
    xmm6 = xmm6 - xmm2;
    xmm7 = intrinsic_unpcklpd(xmm7 - xmm2, xmm7 - xmm2);
    eax = eax & 0x7ff0;
    if (eax >= 0x7ff0) goto loc_484428;
    goto loc_483f11;

.l16:
    if ((intrinsic_pmovmskb(eax, intrinsic_pcmpeqd(intrinsic_xorpd(xmm1, xmm1), intrinsic_andpd(intrinsic_movlpd(xmm3, 2.22507e-308), xmm2))) & 0xff) != 0xff) goto loc_4844fe;
    goto loc_4844a9;

loc_4841eb:
    if (!bool_54) {
            bool_51 = true;
            if (edx <= 0x0) {
                    eax = intrinsic_pmovmskb(eax, intrinsic_pcmpeqd(intrinsic_xorpd(xmm1, xmm1), intrinsic_andpd(intrinsic_movlpd(xmm3, 2.22507e-308), xmm2)));
                    bool_55 = true;
                    if ((eax & 0xff) == 0xff) {
                            intrinsic_pextrw(xmm2, 0x3);
                            xmm4 = intrinsic_movlpd(xmm4, arg_0);
                            eax = eax & 0x8000;
                            if ((edx | ecx ^ 0xbff00000) != 0x0) {
                                    if (eax != 0x0) {
                                            eax = intrinsic_pextrw(xmm4, 0x3);
                                            eax = eax & 0x7ff0;
                                            if (eax >= 0x3ff0) {
                                                    asm { fldz };
                                            }
                                            else {
                                                    asm { fld        qword [double_value_minus_1_44269+16] };
                                            }
                                    }
                                    else {
                                            eax = intrinsic_pextrw(xmm4, 0x3);
                                            eax = eax & 0x7ff0;
                                            if (eax < 0x3ff0) {
                                                    asm { fldz };
                                            }
                                            else {
                                                    asm { fld        qword [double_value_minus_1_44269+16] };
                                            }
                                    }
                            }
                            else {
                                    xmm0 = intrinsic_movlpd(xmm0, 1.0);
                                    intrinsic_movlpd(var_C, xmm0);
                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                    asm { fld        qword [esp+0x1c+var_C] };
                            }
                    }
                    else {
                            xmm0 = xmm2 + xmm2;
                            intrinsic_movlpd(var_C, xmm0);
                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                            asm { fld        qword [esp+0x1c+var_C] };
                    }
            }
            else {
                    xmm0 = xmm4 + xmm4;
                    intrinsic_movlpd(var_C, xmm0);
                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                    asm { fld        qword [esp+0x1c+var_C] };
            }
    }
    else {
            xmm0 = xmm4 + xmm4;
            intrinsic_movlpd(var_C, xmm0);
            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
            asm { fld        qword [esp+0x1c+var_C] };
    }
    return eax;

loc_48450d:
    xmm4 = intrinsic_psrlq(xmm4, 0x20);
    ecx = eax;
    xmm0 = intrinsic_movlpd(xmm0, 1.0);
    edx = 0x1a;
    if (eax != 0x0) {
            eax = zero_extend_32(xmm4) & 0x7fffffff;
            bool_60 = eax < 0x7ff00000;
            if (eax <= 0x7ff00000) {
                    if (!bool_60 && ecx > 0x0) {
                            intrinsic_movlpd(var_C, xmm0);
                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                            asm { fld        qword [esp+0x1c+var_C] };
                    }
                    else {
                            asm { fld        qword [esp+0x10+var_C] };
                    }
            }
            else {
                    intrinsic_movlpd(var_C, xmm0);
                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                    asm { fld        qword [esp+0x1c+var_C] };
            }
    }
    else {
            intrinsic_movlpd(var_C, xmm0);
            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
            asm { fld        qword [esp+0x1c+var_C] };
    }
    return eax;

loc_4840f1:
    if (edx >= 0x0) goto loc_4841ff;
    goto loc_4840fa;

loc_484428:
    xmm4 = intrinsic_movlpd(xmm4, arg_0);
    xmm2 = intrinsic_movlpd(xmm2, arg_8);
    intrinsic_movlpd(xmm3, 2.22507e-308);
    intrinsic_xorpd(xmm1, xmm1);
    xmm3 = intrinsic_andpd(xmm3, xmm2);
    xmm1 = intrinsic_pcmpeqd(xmm1, xmm3);
    eax = intrinsic_pmovmskb(eax, xmm1);
    bool_28 = true;
    if ((eax & 0xff) != 0xff) goto loc_4844fe;
    goto loc_48445c;

loc_483f11:
    eax = (eax - 0x3ff0) + (edx & 0x7ff0);
    edx = 0x40a0 - eax;
    eax = eax - 0x3c70;
    bool_3 = true;
    if ((edx | eax) >= 0x80000000) goto loc_48481c;
    goto loc_483f38;

loc_4844fe:
    xmm0 = xmm2 + xmm2;
    edx = 0x3ee;
    goto .l13;

loc_4844a9:
    intrinsic_pextrw(xmm2, 0x3);
    xmm4 = intrinsic_movlpd(xmm4, arg_0);
    eax = eax & 0x8000;
    if ((edx | ecx ^ 0xbff00000) == 0x0) goto loc_484563;
    goto loc_4844ca;

loc_4841ff:
    ecx = 0x0;
    goto loc_484204;

loc_4840fa:
    intrinsic_orpd(xmm2, intrinsic_psllq(xmm3, 0x34));
    intrinsic_psubd(intrinsic_psrlq(xmm1, 0x14), xmm3);
    xmm3 = intrinsic_pxor(xmm3, xmm3);
    xmm1 = intrinsic_pmaxsw(xmm1, xmm3);
    xmm2 = intrinsic_psllq(xmm2, xmm1);
    xmm2 = intrinsic_pcmpeqd(xmm2, xmm3);
    eax = intrinsic_pmovmskb(eax, xmm2);
    ecx = edx;
    edx = edx & 0x7fff;
    if (edx >= 0x7ff0) goto loc_4842e8;
    goto loc_484145;

loc_48445c:
    eax = zero_extend_32(xmm4);
    if (eax != 0x0) goto .l16;
    goto loc_484465;

loc_48481c:
    xmm4 = intrinsic_pshufd(xmm1, 0x44);
    xmm4 = intrinsic_mulpd(xmm4, xmm6);
    eax = intrinsic_pextrw(xmm4, 0x3);
    edx = 0x40a0 - (eax & 0x7ff0);
    eax = (eax & 0x7ff0) - 0x3c70;
    if ((edx | eax) < 0x80000000) goto loc_483f38;
    goto loc_484849;

loc_483f38:
    intrinsic_movlpd(xmm4 - xmm6, Nan);
    intrinsic_andpd(xmm3, xmm1);
    intrinsic_andpd(xmm4, xmm6);
    xmm0 = xmm0 - xmm2;
    intrinsic_xorpd(xmm2, xmm2);
    xmm2 = intrinsic_pinsrw(0x4060, 0x3);
    xmm3 = xmm3 * xmm4 * xmm2;
    xmm2 = intrinsic_movapd(xmm2, 0.160151);
    intrinsic_cvtsd2si(eax, xmm3);
    xmm6 = xmm6 * xmm1;
    xmm1 = intrinsic_movapd(xmm1, -0.0832562);
    xmm4 = intrinsic_pshufd(xmm6, 0xee);
    xmm5 = xmm5 + xmm6;
    edx = 0x1ff7f - eax | eax + 0x1e1ff;
    eax = eax + 0x1e1ff - 0x1e1ff;
    bool_4 = true;
    if (edx <= 0x0) goto loc_4845a0;
    goto loc_483fbf;

.l13:
    intrinsic_movlpd(var_C, xmm0);
    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
    asm { fld        qword [esp+0x1c+var_C] };
    return eax;

loc_484563:
    xmm0 = intrinsic_movlpd(xmm0, 1.0);
    edx = 0x1c;
    goto .l13;

loc_4844ca:
    if (eax != 0x0) {
            eax = intrinsic_pextrw(xmm4, 0x3);
            eax = eax & 0x7ff0;
            if (eax >= 0x3ff0) {
                    asm { fldz };
            }
            else {
                    asm { fld        qword [double_value_minus_1_44269+16] };
            }
    }
    else {
            eax = intrinsic_pextrw(xmm4, 0x3);
            eax = eax & 0x7ff0;
            if (eax < 0x3ff0) {
                    asm { fldz };
            }
            else {
                    asm { fld        qword [double_value_minus_1_44269+16] };
            }
    }
    return eax;

loc_484204:
    intrinsic_xorpd(xmm0, xmm0);
    intrinsic_pinsrw(0x43f0, 0x3);
    xmm7 = intrinsic_movlpd(xmm7, 2.22507e-308);
    xmm2 = intrinsic_movlpd(xmm2, 1.0);
    xmm0 = xmm0 * xmm4;
    eax = zero_extend_32(intrinsic_psrlq(xmm4, 0x20));
    bool_91 = true;
    bool_90 = true;
    bool_89 = true;
    bool_88 = true;
    bool_87 = true;
    bool_86 = true;
    if (edx == 0x0) goto loc_48428a;
    goto .l2;

loc_4842e8:
    intrinsic_movlpd(xmm3, 2.22507e-308);
    xmm1 = intrinsic_xorpd(xmm1, xmm1);
    xmm1 = intrinsic_pcmpeqd(xmm1, intrinsic_andpd(xmm3, xmm4));
    ecx = intrinsic_pmovmskb(ecx, xmm1);
    bool_47 = true;
    if ((ecx & 0xff) != 0xff) goto .l20;
    goto loc_484312;

loc_484145:
    eax = eax & 0xff;
    if (eax != 0xff) goto loc_4843e1;
    goto loc_484155;

loc_484465:
    xmm4 = intrinsic_psrlq(xmm4, 0x20);
    edx = zero_extend_32(xmm4);
    if (edx == 0x3ff00000) goto loc_484563;
    goto loc_48447a;

loc_484849:
    if (eax < 0x80000000) goto loc_484870;
    goto loc_484850;

loc_4845a0:
    if (eax <= 0x0) goto loc_4845cd;
    goto loc_4845a5;

loc_483fbf:
    intrinsic_mulpd(xmm2, xmm7);
    intrinsic_mulpd(xmm7, xmm7);
    eax = eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax;
    intrinsic_movapd(xmm3, eax[0x4b6c2]);
    intrinsic_movapd(xmm6, 0.00133336);
    intrinsic_pshufd(intrinsic_addpd(xmm2, intrinsic_mulpd(xmm1, xmm7)), 0xee);
    intrinsic_xorpd(xmm7, xmm7);
    intrinsic_pinsrw(0x3f80, 0x3);
    intrinsic_movlpd(xmm4, 0.693147);
    intrinsic_pshufd(intrinsic_psllq(zero_extend_32(ecx), 0x2d), 0x44);
    intrinsic_movapd(xmm7, 0.00961813);
    intrinsic_mulpd(xmm3, xmm1);
    intrinsic_mulpd(xmm6, intrinsic_unpcklpd(xmm0 + xmm5, xmm0 + xmm5));
    intrinsic_mulpd(xmm0, xmm0);
    xmm7 = intrinsic_addpd(xmm7, xmm6);
    xmm7 = intrinsic_mulpd(xmm7, xmm0);
    asm { fld        qword [esp+0x10+var_C] };
    return eax;

loc_48428a:
    bool_43 = true;
    if ((eax & 0x7fffffff) != 0x0) goto loc_484238;
    goto loc_484297;

.l2:
    intrinsic_andpd(xmm7, xmm0);
    xmm4 = xmm0;
    xmm0 = intrinsic_andpd(xmm0, Nan);
    xmm0 = intrinsic_psrlq(xmm0, 0x2c);
    intrinsic_pextrw(xmm0, 0x0);
    xmm7 = intrinsic_orpd(xmm7, xmm2);
    xmm7 = xmm7 * *(double *)(((eax & 0xff) + 0x1 & 0x1fe) * 0x4 + double_value_1);
    xmm5 = intrinsic_movlpd(xmm5, *(int64_t *)(((eax & 0xff) + 0x1 & 0x1fe) * 0x4 + double_value_1));
    xmm6 = intrinsic_movapd(xmm6, *(int128_t *)((eax + eax) * 0x4 + 0x4b3fb0));
    xmm0 = intrinsic_psubq(xmm0, zero_extend_32(0x43e7f));
    xmm0 = intrinsic_psrlq(xmm0, 0x8);
    intrinsic_cvtdq2pd(xmm0, xmm0);
    intrinsic_movlpd(xmm1, Nan);
    intrinsic_pextrw(intrinsic_psrlq(xmm7, 0x26), 0x0);
    intrinsic_andpd(xmm4, 2.22507e-308);
    intrinsic_addpd(xmm6, *(int128_t *)((((eax & 0xff) + 0x1 & 0x1fe) + ((eax & 0xff) + 0x1 & 0x1fe)) * 0x4 + 0x4b4bd0));
    intrinsic_andpd(xmm1, intrinsic_orpd(xmm4, 1.0));
    intrinsic_pextrw(intrinsic_psrlq(xmm3, 0x1f), 0x0);
    intrinsic_movlpd(xmm0, Nan);
    intrinsic_movlpd(xmm7, -1.44269);
    intrinsic_addpd(xmm6, *(int128_t *)(((eax & 0x1ff) + 0x1 & 0x3fe) * 0x8 + 0x4b5bf0));
    xmm0 = intrinsic_andpd(xmm0, xmm5);
    xmm1 = intrinsic_movlpd(xmm1 * (xmm5 - xmm0), arg_8);
    intrinsic_pextrw(xmm1, 0x3);
    xmm3 = intrinsic_movlpd(xmm3, Nan);
    edx = intrinsic_pextrw(xmm6, 0x3);
    xmm2 = xmm2 - xmm4;
    xmm4 = xmm6;
    xmm0 = xmm0 + xmm7;
    xmm6 = xmm6 - xmm2;
    xmm7 = intrinsic_unpcklpd(xmm7 - xmm2, xmm7 - xmm2);
    eax = eax & 0x7ff0;
    if (eax < 0x7ff0) {
            eax = (eax - 0x3ff0) + (edx & 0x7ff0);
            edx = 0x40a0 - eax;
            eax = eax - 0x3c70;
            bool_128 = true;
            if ((edx | eax) < 0x80000000) {
                    intrinsic_movlpd(xmm4 - xmm6, Nan);
                    intrinsic_andpd(xmm3, xmm1);
                    intrinsic_andpd(xmm4, xmm6);
                    xmm0 = xmm0 - xmm2;
                    intrinsic_xorpd(xmm2, xmm2);
                    xmm2 = intrinsic_pinsrw(0x4060, 0x3);
                    xmm3 = xmm3 * xmm4 * xmm2;
                    xmm2 = intrinsic_movapd(xmm2, 0.160151);
                    intrinsic_cvtsd2si(eax, xmm3);
                    xmm6 = xmm6 * xmm1;
                    xmm1 = intrinsic_movapd(xmm1, -0.0832562);
                    xmm4 = intrinsic_pshufd(xmm6, 0xee);
                    xmm5 = xmm5 + xmm6;
                    edx = 0x1ff7f - eax | eax + 0x1e1ff;
                    eax = eax + 0x1e1ff - 0x1e1ff;
                    bool_131 = true;
                    if (edx > 0x0) {
                            intrinsic_mulpd(xmm2, xmm7);
                            intrinsic_mulpd(xmm7, xmm7);
                            eax = eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax;
                            intrinsic_movapd(xmm3, eax[0x4b6c2]);
                            intrinsic_movapd(xmm6, 0.00133336);
                            intrinsic_pshufd(intrinsic_addpd(xmm2, intrinsic_mulpd(xmm1, xmm7)), 0xee);
                            intrinsic_xorpd(xmm7, xmm7);
                            intrinsic_pinsrw(0x3f80, 0x3);
                            intrinsic_movlpd(xmm4, 0.693147);
                            intrinsic_pshufd(intrinsic_psllq(zero_extend_32(ecx), 0x2d), 0x44);
                            intrinsic_movapd(xmm7, 0.00961813);
                            intrinsic_mulpd(xmm3, xmm1);
                            intrinsic_mulpd(xmm6, intrinsic_unpcklpd(xmm0 + xmm5, xmm0 + xmm5));
                            intrinsic_mulpd(xmm0, xmm0);
                            xmm7 = intrinsic_addpd(xmm7, xmm6);
                            xmm7 = intrinsic_mulpd(xmm7, xmm0);
                            asm { fld        qword [esp+0x10+var_C] };
                    }
                    else {
                            if (eax > 0x0) {
                                    bool_136 = true;
                                    bool_135 = true;
                                    if (eax < 0x40000) {
                                            decomp_var_4 = esi;
                                            edx = eax;
                                            eax = eax & 0x7f;
                                            ecx = ecx + 0x3ff00;
                                            edx = edx - 0x80 & 0xffffff80;
                                            esp = esp - 0x8;
                                            var_C = edi;
                                            intrinsic_mulpd(xmm2, xmm7);
                                            intrinsic_mulpd(xmm7, xmm7);
                                            intrinsic_movapd(xmm3, *(int128_t *)(eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + 0x4b6c20));
                                            intrinsic_movapd(xmm6, 0.00133336);
                                            xmm2 * xmm7 + intrinsic_pshufd(intrinsic_addpd(xmm2, intrinsic_mulpd(xmm1, xmm7)), 0xee) + xmm4;
                                            intrinsic_movlpd(xmm4, 0.693147);
                                            intrinsic_xorpd(xmm7, xmm7);
                                            intrinsic_pinsrw(0x3f80, 0x3);
                                            intrinsic_pshufd(intrinsic_psllq(xmm1, 0x2d), 0x44);
                                            intrinsic_movapd(xmm7, 0.00961813);
                                            intrinsic_mulpd(xmm3, xmm1);
                                            intrinsic_mulpd(xmm6, intrinsic_unpcklpd(xmm0 + xmm5, xmm0 + xmm5));
                                            intrinsic_mulpd(xmm0, xmm0);
                                            intrinsic_pshufd(intrinsic_mulpd(intrinsic_addpd(xmm7, xmm6), xmm0), 0xee);
                                            intrinsic_pshufd(xmm3, 0xee);
                                            xmm7 = intrinsic_psllq(zero_extend_32(ecx), 0x2d);
                                            intrinsic_andpd(intrinsic_psllq(intrinsic_pcmpeqd(xmm1, xmm1), xmm2), xmm3);
                                            intrinsic_xorpd(xmm6, xmm6);
                                            xmm1 = intrinsic_andpd(xmm1 + xmm0, intrinsic_psllq(intrinsic_pcmpeqd(xmm4, xmm4), xmm2));
                                            xmm6 = intrinsic_pinsrw(0x3ff0, 0x3);
                                            esp = esp + 0x4;
                                            xmm0 = xmm0 + (xmm2 - xmm1) + xmm3;
                                            if (edx <= 0x1ff80) {
                                                    esp = esp + 0x4;
                                                    xmm0 = xmm0 * xmm7 + xmm1 * xmm7 + xmm6 * (xmm0 * xmm7 + xmm1 * xmm7);
                                                    eax = intrinsic_pextrw(xmm0, 0x3);
                                                    eax = eax & 0x7ff0;
                                                    switch (eax) {
                                                        case 32752:
                                                            intrinsic_movlpd(var_C, xmm0);
                                                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                            asm { fld        qword [esp+0x1c+var_C] };
                                                            break;
                                                        case 0:
                                                            intrinsic_movlpd(var_C, xmm0);
                                                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                            asm { fld        qword [esp+0x1c+var_C] };
                                                            break;
                                                        default:
                                                            asm { fld        qword [esp+0x10+var_C] };
                                                            break;
                                                    }
                                            }
                                            else {
                                                    esp = esp + 0x4;
                                                    xmm0 = (xmm0 + xmm1) * xmm7 + xmm6 * (xmm0 + xmm1) * xmm7;
                                                    eax = intrinsic_pextrw(xmm0, 0x3);
                                                    eax = eax & 0x7ff0;
                                                    switch (eax) {
                                                        case 32752:
                                                            intrinsic_movlpd(var_C, xmm0);
                                                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                            asm { fld        qword [esp+0x1c+var_C] };
                                                            break;
                                                        case 0:
                                                            intrinsic_movlpd(var_C, xmm0);
                                                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                            asm { fld        qword [esp+0x1c+var_C] };
                                                            break;
                                                        default:
                                                            asm { fld        qword [esp+0x10+var_C] };
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if (ecx != 0x0) {
                                                    xmm0 = intrinsic_movlpd(xmm0, -8.98847e+307);
                                                    xmm0 = xmm0 * 8.98847e+307;
                                            }
                                            else {
                                                    xmm0 = intrinsic_movlpd(xmm0, 8.98847e+307);
                                                    xmm0 = xmm0 * xmm0;
                                            }
                                            intrinsic_movlpd(var_C, xmm0);
                                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                            asm { fld        qword [esp+0x1c+var_C] };
                                    }
                            }
                            else {
                                    bool_126 = true;
                                    bool_125 = true;
                                    if (eax > 0xfffc0200) {
                                            decomp_var_4 = esi;
                                            edx = eax;
                                            eax = eax & 0x7f;
                                            ecx = ecx + 0x80;
                                            edx = (edx & 0xffffff80) + 0x3fe80;
                                            esp = esp - 0x8;
                                            var_C = edi;
                                            intrinsic_mulpd(xmm2, xmm7);
                                            intrinsic_mulpd(xmm7, xmm7);
                                            intrinsic_movapd(xmm3, *(int128_t *)(eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + 0x4b6c20));
                                            intrinsic_movapd(xmm6, 0.00133336);
                                            xmm2 * xmm7 + intrinsic_pshufd(intrinsic_addpd(xmm2, intrinsic_mulpd(xmm1, xmm7)), 0xee) + xmm4;
                                            intrinsic_movlpd(xmm4, 0.693147);
                                            intrinsic_xorpd(xmm7, xmm7);
                                            intrinsic_pinsrw(0x3f80, 0x3);
                                            intrinsic_pshufd(intrinsic_psllq(xmm1, 0x2d), 0x44);
                                            intrinsic_movapd(xmm7, 0.00961813);
                                            intrinsic_mulpd(xmm3, xmm1);
                                            intrinsic_mulpd(xmm6, intrinsic_unpcklpd(xmm0 + xmm5, xmm0 + xmm5));
                                            intrinsic_mulpd(xmm0, xmm0);
                                            intrinsic_pshufd(intrinsic_mulpd(intrinsic_addpd(xmm7, xmm6), xmm0), 0xee);
                                            intrinsic_pshufd(xmm3, 0xee);
                                            xmm7 = intrinsic_psllq(zero_extend_32(ecx), 0x2d);
                                            intrinsic_andpd(intrinsic_psllq(intrinsic_pcmpeqd(xmm1, xmm1), xmm2), xmm3);
                                            intrinsic_xorpd(xmm6, xmm6);
                                            xmm1 = intrinsic_andpd(xmm1 + xmm0, intrinsic_psllq(intrinsic_pcmpeqd(xmm4, xmm4), xmm2));
                                            xmm6 = intrinsic_pinsrw(0x0, 0x3);
                                            esp = esp + 0x4;
                                            xmm0 = xmm0 + (xmm2 - xmm1) + xmm3;
                                            if (edx <= 0x1ff80) {
                                                    esp = esp + 0x4;
                                                    xmm0 = xmm0 * xmm7 + xmm1 * xmm7 + xmm6 * (xmm0 * xmm7 + xmm1 * xmm7);
                                                    eax = intrinsic_pextrw(xmm0, 0x3);
                                                    eax = eax & 0x7ff0;
                                                    switch (eax) {
                                                        case 32752:
                                                            intrinsic_movlpd(var_C, xmm0);
                                                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                            asm { fld        qword [esp+0x1c+var_C] };
                                                            break;
                                                        case 0:
                                                            intrinsic_movlpd(var_C, xmm0);
                                                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                            asm { fld        qword [esp+0x1c+var_C] };
                                                            break;
                                                        default:
                                                            asm { fld        qword [esp+0x10+var_C] };
                                                            break;
                                                    }
                                            }
                                            else {
                                                    esp = esp + 0x4;
                                                    xmm0 = (xmm0 + xmm1) * xmm7 + xmm6 * (xmm0 + xmm1) * xmm7;
                                                    eax = intrinsic_pextrw(xmm0, 0x3);
                                                    eax = eax & 0x7ff0;
                                                    switch (eax) {
                                                        case 32752:
                                                            intrinsic_movlpd(var_C, xmm0);
                                                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                            asm { fld        qword [esp+0x1c+var_C] };
                                                            break;
                                                        case 0:
                                                            intrinsic_movlpd(var_C, xmm0);
                                                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                            asm { fld        qword [esp+0x1c+var_C] };
                                                            break;
                                                        default:
                                                            asm { fld        qword [esp+0x10+var_C] };
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            xmm0 = intrinsic_movlpd(xmm0, 2.22507e-308);
                                            xmm0 = intrinsic_orpd(xmm0 * xmm0, intrinsic_psllq(zero_extend_32(ecx), 0x2d));
                                            intrinsic_movlpd(var_C, xmm0);
                                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                            asm { fld        qword [esp+0x1c+var_C] };
                                    }
                            }
                    }
            }
            else {
                    xmm4 = intrinsic_pshufd(xmm1, 0x44);
                    xmm4 = intrinsic_mulpd(xmm4, xmm6);
                    eax = intrinsic_pextrw(xmm4, 0x3);
                    edx = 0x40a0 - (eax & 0x7ff0);
                    eax = (eax & 0x7ff0) - 0x3c70;
                    bool_75 = true;
                    if ((edx | eax) >= 0x80000000) {
                            if (eax >= 0x80000000) {
                                    asm { fld        qword [esp+0x10+var_C] };
                            }
                            else {
                                    if (((intrinsic_pextrw(xmm1, 0x3) ^ (intrinsic_pextrw(intrinsic_movlpd(xmm4, arg_0), 0x3) & 0x7ff0) - 0x3ff0) & 0x8000) == 0x0) {
                                            edx = 0x18;
                                            if (ecx != 0x0) {
                                                    xmm0 = intrinsic_movlpd(xmm0, -8.98847e+307);
                                                    xmm0 = xmm0 * 8.98847e+307;
                                            }
                                            else {
                                                    xmm0 = intrinsic_movlpd(xmm0, 8.98847e+307);
                                                    xmm0 = xmm0 * xmm0;
                                            }
                                    }
                                    else {
                                            xmm0 = intrinsic_movlpd(xmm0, 2.22507e-308);
                                            xmm0 = intrinsic_orpd(xmm0 * xmm0, intrinsic_psllq(zero_extend_32(ecx), 0x2d));
                                            edx = 0x19;
                                    }
                                    intrinsic_movlpd(var_C, xmm0);
                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                    asm { fld        qword [esp+0x1c+var_C] };
                            }
                    }
                    else {
                            intrinsic_movlpd(xmm4 - xmm6, Nan);
                            intrinsic_andpd(xmm3, xmm1);
                            intrinsic_andpd(xmm4, xmm6);
                            xmm0 = xmm0 - xmm2;
                            intrinsic_xorpd(xmm2, xmm2);
                            xmm2 = intrinsic_pinsrw(0x4060, 0x3);
                            xmm3 = xmm3 * xmm4 * xmm2;
                            xmm2 = intrinsic_movapd(xmm2, 0.160151);
                            intrinsic_cvtsd2si(eax, xmm3);
                            xmm6 = xmm6 * xmm1;
                            xmm1 = intrinsic_movapd(xmm1, -0.0832562);
                            xmm4 = intrinsic_pshufd(xmm6, 0xee);
                            xmm5 = xmm5 + xmm6;
                            edx = 0x1ff7f - eax | eax + 0x1e1ff;
                            eax = eax + 0x1e1ff - 0x1e1ff;
                            bool_121 = true;
                            if (edx > 0x0) {
                                    intrinsic_mulpd(xmm2, xmm7);
                                    intrinsic_mulpd(xmm7, xmm7);
                                    eax = eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax;
                                    intrinsic_movapd(xmm3, eax[0x4b6c2]);
                                    intrinsic_movapd(xmm6, 0.00133336);
                                    intrinsic_pshufd(intrinsic_addpd(xmm2, intrinsic_mulpd(xmm1, xmm7)), 0xee);
                                    intrinsic_xorpd(xmm7, xmm7);
                                    intrinsic_pinsrw(0x3f80, 0x3);
                                    intrinsic_movlpd(xmm4, 0.693147);
                                    intrinsic_pshufd(intrinsic_psllq(zero_extend_32(ecx), 0x2d), 0x44);
                                    intrinsic_movapd(xmm7, 0.00961813);
                                    intrinsic_mulpd(xmm3, xmm1);
                                    intrinsic_mulpd(xmm6, intrinsic_unpcklpd(xmm0 + xmm5, xmm0 + xmm5));
                                    intrinsic_mulpd(xmm0, xmm0);
                                    xmm7 = intrinsic_addpd(xmm7, xmm6);
                                    xmm7 = intrinsic_mulpd(xmm7, xmm0);
                                    asm { fld        qword [esp+0x10+var_C] };
                            }
                            else {
                                    if (eax > 0x0) {
                                            bool_115 = true;
                                            bool_114 = true;
                                            if (eax < 0x40000) {
                                                    decomp_var_4 = esi;
                                                    edx = eax;
                                                    eax = eax & 0x7f;
                                                    ecx = ecx + 0x3ff00;
                                                    edx = edx - 0x80 & 0xffffff80;
                                                    esp = esp - 0x8;
                                                    var_C = edi;
                                                    intrinsic_mulpd(xmm2, xmm7);
                                                    intrinsic_mulpd(xmm7, xmm7);
                                                    intrinsic_movapd(xmm3, *(int128_t *)(eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + 0x4b6c20));
                                                    intrinsic_movapd(xmm6, 0.00133336);
                                                    xmm2 * xmm7 + intrinsic_pshufd(intrinsic_addpd(xmm2, intrinsic_mulpd(xmm1, xmm7)), 0xee) + xmm4;
                                                    intrinsic_movlpd(xmm4, 0.693147);
                                                    intrinsic_xorpd(xmm7, xmm7);
                                                    intrinsic_pinsrw(0x3f80, 0x3);
                                                    intrinsic_pshufd(intrinsic_psllq(xmm1, 0x2d), 0x44);
                                                    intrinsic_movapd(xmm7, 0.00961813);
                                                    intrinsic_mulpd(xmm3, xmm1);
                                                    intrinsic_mulpd(xmm6, intrinsic_unpcklpd(xmm0 + xmm5, xmm0 + xmm5));
                                                    intrinsic_mulpd(xmm0, xmm0);
                                                    intrinsic_pshufd(intrinsic_mulpd(intrinsic_addpd(xmm7, xmm6), xmm0), 0xee);
                                                    intrinsic_pshufd(xmm3, 0xee);
                                                    xmm7 = intrinsic_psllq(zero_extend_32(ecx), 0x2d);
                                                    intrinsic_andpd(intrinsic_psllq(intrinsic_pcmpeqd(xmm1, xmm1), xmm2), xmm3);
                                                    intrinsic_xorpd(xmm6, xmm6);
                                                    xmm1 = intrinsic_andpd(xmm1 + xmm0, intrinsic_psllq(intrinsic_pcmpeqd(xmm4, xmm4), xmm2));
                                                    xmm6 = intrinsic_pinsrw(0x3ff0, 0x3);
                                                    esp = esp + 0x4;
                                                    xmm0 = xmm0 + (xmm2 - xmm1) + xmm3;
                                                    if (edx <= 0x1ff80) {
                                                            esp = esp + 0x4;
                                                            xmm0 = xmm0 * xmm7 + xmm1 * xmm7 + xmm6 * (xmm0 * xmm7 + xmm1 * xmm7);
                                                            eax = intrinsic_pextrw(xmm0, 0x3);
                                                            eax = eax & 0x7ff0;
                                                            switch (eax) {
                                                                case 32752:
                                                                    intrinsic_movlpd(var_C, xmm0);
                                                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                                    asm { fld        qword [esp+0x1c+var_C] };
                                                                    break;
                                                                case 0:
                                                                    intrinsic_movlpd(var_C, xmm0);
                                                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                                    asm { fld        qword [esp+0x1c+var_C] };
                                                                    break;
                                                                default:
                                                                    asm { fld        qword [esp+0x10+var_C] };
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp + 0x4;
                                                            xmm0 = (xmm0 + xmm1) * xmm7 + xmm6 * (xmm0 + xmm1) * xmm7;
                                                            eax = intrinsic_pextrw(xmm0, 0x3);
                                                            eax = eax & 0x7ff0;
                                                            switch (eax) {
                                                                case 32752:
                                                                    intrinsic_movlpd(var_C, xmm0);
                                                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                                    asm { fld        qword [esp+0x1c+var_C] };
                                                                    break;
                                                                case 0:
                                                                    intrinsic_movlpd(var_C, xmm0);
                                                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                                    asm { fld        qword [esp+0x1c+var_C] };
                                                                    break;
                                                                default:
                                                                    asm { fld        qword [esp+0x10+var_C] };
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (ecx != 0x0) {
                                                            xmm0 = intrinsic_movlpd(xmm0, -8.98847e+307);
                                                            xmm0 = xmm0 * 8.98847e+307;
                                                    }
                                                    else {
                                                            xmm0 = intrinsic_movlpd(xmm0, 8.98847e+307);
                                                            xmm0 = xmm0 * xmm0;
                                                    }
                                                    intrinsic_movlpd(var_C, xmm0);
                                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                    asm { fld        qword [esp+0x1c+var_C] };
                                            }
                                    }
                                    else {
                                            bool_80 = true;
                                            bool_79 = true;
                                            if (eax > 0xfffc0200) {
                                                    decomp_var_4 = esi;
                                                    edx = eax;
                                                    eax = eax & 0x7f;
                                                    ecx = ecx + 0x80;
                                                    edx = (edx & 0xffffff80) + 0x3fe80;
                                                    esp = esp - 0x8;
                                                    var_C = edi;
                                                    intrinsic_mulpd(xmm2, xmm7);
                                                    intrinsic_mulpd(xmm7, xmm7);
                                                    intrinsic_movapd(xmm3, *(int128_t *)(eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + 0x4b6c20));
                                                    intrinsic_movapd(xmm6, 0.00133336);
                                                    xmm2 * xmm7 + intrinsic_pshufd(intrinsic_addpd(xmm2, intrinsic_mulpd(xmm1, xmm7)), 0xee) + xmm4;
                                                    intrinsic_movlpd(xmm4, 0.693147);
                                                    intrinsic_xorpd(xmm7, xmm7);
                                                    intrinsic_pinsrw(0x3f80, 0x3);
                                                    intrinsic_pshufd(intrinsic_psllq(xmm1, 0x2d), 0x44);
                                                    intrinsic_movapd(xmm7, 0.00961813);
                                                    intrinsic_mulpd(xmm3, xmm1);
                                                    intrinsic_mulpd(xmm6, intrinsic_unpcklpd(xmm0 + xmm5, xmm0 + xmm5));
                                                    intrinsic_mulpd(xmm0, xmm0);
                                                    intrinsic_pshufd(intrinsic_mulpd(intrinsic_addpd(xmm7, xmm6), xmm0), 0xee);
                                                    intrinsic_pshufd(xmm3, 0xee);
                                                    xmm7 = intrinsic_psllq(zero_extend_32(ecx), 0x2d);
                                                    intrinsic_andpd(intrinsic_psllq(intrinsic_pcmpeqd(xmm1, xmm1), xmm2), xmm3);
                                                    intrinsic_xorpd(xmm6, xmm6);
                                                    xmm1 = intrinsic_andpd(xmm1 + xmm0, intrinsic_psllq(intrinsic_pcmpeqd(xmm4, xmm4), xmm2));
                                                    xmm6 = intrinsic_pinsrw(0x0, 0x3);
                                                    esp = esp + 0x4;
                                                    xmm0 = xmm0 + (xmm2 - xmm1) + xmm3;
                                                    if (edx <= 0x1ff80) {
                                                            esp = esp + 0x4;
                                                            xmm0 = xmm0 * xmm7 + xmm1 * xmm7 + xmm6 * (xmm0 * xmm7 + xmm1 * xmm7);
                                                            eax = intrinsic_pextrw(xmm0, 0x3);
                                                            eax = eax & 0x7ff0;
                                                            switch (eax) {
                                                                case 32752:
                                                                    intrinsic_movlpd(var_C, xmm0);
                                                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                                    asm { fld        qword [esp+0x1c+var_C] };
                                                                    break;
                                                                case 0:
                                                                    intrinsic_movlpd(var_C, xmm0);
                                                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                                    asm { fld        qword [esp+0x1c+var_C] };
                                                                    break;
                                                                default:
                                                                    asm { fld        qword [esp+0x10+var_C] };
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp + 0x4;
                                                            xmm0 = (xmm0 + xmm1) * xmm7 + xmm6 * (xmm0 + xmm1) * xmm7;
                                                            eax = intrinsic_pextrw(xmm0, 0x3);
                                                            eax = eax & 0x7ff0;
                                                            edx = 0x18;
                                                            switch (eax) {
                                                                case 32752:
                                                                    intrinsic_movlpd(var_C, xmm0);
                                                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                                    asm { fld        qword [esp+0x1c+var_C] };
                                                                    break;
                                                                case 0:
                                                                    intrinsic_movlpd(var_C, xmm0);
                                                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                                    asm { fld        qword [esp+0x1c+var_C] };
                                                                    break;
                                                                default:
                                                                    asm { fld        qword [esp+0x10+var_C] };
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    xmm0 = intrinsic_movlpd(xmm0, 2.22507e-308);
                                                    xmm0 = intrinsic_orpd(xmm0 * xmm0, intrinsic_psllq(zero_extend_32(ecx), 0x2d));
                                                    intrinsic_movlpd(var_C, xmm0);
                                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                    asm { fld        qword [esp+0x1c+var_C] };
                                            }
                                    }
                            }
                    }
            }
    }
    else {
            xmm4 = intrinsic_movlpd(xmm4, arg_0);
            xmm2 = intrinsic_movlpd(xmm2, arg_8);
            intrinsic_movlpd(xmm3, 2.22507e-308);
            intrinsic_xorpd(xmm1, xmm1);
            xmm3 = intrinsic_andpd(xmm3, xmm2);
            xmm1 = intrinsic_pcmpeqd(xmm1, xmm3);
            eax = intrinsic_pmovmskb(eax, xmm1);
            bool_105 = true;
            if ((eax & 0xff) == 0xff) {
                    eax = zero_extend_32(xmm4);
                    if (eax == 0x0) {
                            xmm4 = intrinsic_psrlq(xmm4, 0x20);
                            edx = zero_extend_32(xmm4);
                            if (edx != 0x3ff00000) {
                                    if (edx == 0xbff00000) {
                                            asm { fld1 };
                                    }
                                    else {
                                            eax = intrinsic_pmovmskb(eax, intrinsic_pcmpeqd(intrinsic_xorpd(xmm1, xmm1), intrinsic_andpd(intrinsic_movlpd(xmm3, 2.22507e-308), xmm2)));
                                            bool_101 = true;
                                            if ((eax & 0xff) == 0xff) {
                                                    intrinsic_pextrw(xmm2, 0x3);
                                                    xmm4 = intrinsic_movlpd(xmm4, arg_0);
                                                    eax = eax & 0x8000;
                                                    if ((edx | ecx ^ 0xbff00000) != 0x0) {
                                                            if (eax != 0x0) {
                                                                    eax = intrinsic_pextrw(xmm4, 0x3);
                                                                    eax = eax & 0x7ff0;
                                                                    if (eax >= 0x3ff0) {
                                                                            asm { fldz };
                                                                    }
                                                                    else {
                                                                            asm { fld        qword [double_value_minus_1_44269+16] };
                                                                    }
                                                            }
                                                            else {
                                                                    eax = intrinsic_pextrw(xmm4, 0x3);
                                                                    eax = eax & 0x7ff0;
                                                                    if (eax < 0x3ff0) {
                                                                            asm { fldz };
                                                                    }
                                                                    else {
                                                                            asm { fld        qword [double_value_minus_1_44269+16] };
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            xmm0 = intrinsic_movlpd(xmm0, 1.0);
                                                            intrinsic_movlpd(var_C, xmm0);
                                                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                            asm { fld        qword [esp+0x1c+var_C] };
                                                    }
                                            }
                                            else {
                                                    xmm0 = xmm2 + xmm2;
                                                    intrinsic_movlpd(var_C, xmm0);
                                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                                    asm { fld        qword [esp+0x1c+var_C] };
                                            }
                                    }
                            }
                            else {
                                    xmm0 = intrinsic_movlpd(xmm0, 1.0);
                                    intrinsic_movlpd(var_C, xmm0);
                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                    asm { fld        qword [esp+0x1c+var_C] };
                            }
                    }
                    else {
                            eax = intrinsic_pmovmskb(eax, intrinsic_pcmpeqd(intrinsic_xorpd(xmm1, xmm1), intrinsic_andpd(intrinsic_movlpd(xmm3, 2.22507e-308), xmm2)));
                            bool_96 = true;
                            if ((eax & 0xff) == 0xff) {
                                    intrinsic_pextrw(xmm2, 0x3);
                                    xmm4 = intrinsic_movlpd(xmm4, arg_0);
                                    eax = eax & 0x8000;
                                    if ((edx | ecx ^ 0xbff00000) != 0x0) {
                                            if (eax != 0x0) {
                                                    eax = intrinsic_pextrw(xmm4, 0x3);
                                                    eax = eax & 0x7ff0;
                                                    if (eax >= 0x3ff0) {
                                                            asm { fldz };
                                                    }
                                                    else {
                                                            asm { fld        qword [double_value_minus_1_44269+16] };
                                                    }
                                            }
                                            else {
                                                    eax = intrinsic_pextrw(xmm4, 0x3);
                                                    eax = eax & 0x7ff0;
                                                    if (eax < 0x3ff0) {
                                                            asm { fldz };
                                                    }
                                                    else {
                                                            asm { fld        qword [double_value_minus_1_44269+16] };
                                                    }
                                            }
                                    }
                                    else {
                                            xmm0 = intrinsic_movlpd(xmm0, 1.0);
                                            edx = 0x1c;
                                            intrinsic_movlpd(var_C, xmm0);
                                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                            asm { fld        qword [esp+0x1c+var_C] };
                                    }
                            }
                            else {
                                    xmm0 = xmm2 + xmm2;
                                    intrinsic_movlpd(var_C, xmm0);
                                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                                    asm { fld        qword [esp+0x1c+var_C] };
                            }
                    }
            }
            else {
                    xmm0 = xmm2 + xmm2;
                    intrinsic_movlpd(var_C, xmm0);
                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                    asm { fld        qword [esp+0x1c+var_C] };
            }
    }
    return eax;

.l20:
    xmm0 = xmm4 + xmm4;
    edx = 0x3ee;
    goto .l13;

loc_484312:
    if ((intrinsic_pextrw(xmm4, 0x3) & 0x8000) != 0x0) {
            eax = eax & 0xff;
            if (eax == 0xff) {
                    intrinsic_movlpd(xmm1, arg_8);
                    intrinsic_movlpd(xmm2, arg_8);
                    xmm1 = intrinsic_andpd(xmm1, Nan);
                    xmm1 = intrinsic_psrlq(xmm1, 0x34);
                    xmm1 = intrinsic_psubd(xmm1, xmm3);
                    if ((intrinsic_pmovmskb(eax, intrinsic_pcmpeqd(intrinsic_psllq(xmm2, xmm1), intrinsic_pxor(xmm3, xmm3))) & 0xff) != 0xff) {
                            eax = intrinsic_pextrw(intrinsic_movlpd(xmm1, arg_8), 0x3);
                            eax = eax & 0x8000;
                            if (eax != 0x0) {
                                    asm { fld        qword [double_value_minus_0] };
                            }
                            else {
                                    asm { fld        qword [qword_value_18442240474082181120] };
                            }
                    }
                    else {
                            eax = intrinsic_pextrw(intrinsic_movlpd(xmm1, arg_8), 0x3);
                            eax = eax & 0x8000;
                            if (eax != 0x0) {
                                    asm { fldz };
                            }
                            else {
                                    asm { fld        qword [double_value_minus_1_44269+16] };
                            }
                    }
            }
            else {
                    eax = intrinsic_pextrw(intrinsic_movlpd(xmm1, arg_8), 0x3);
                    eax = eax & 0x8000;
                    if (eax != 0x0) {
                            asm { fldz };
                    }
                    else {
                            asm { fld        qword [double_value_minus_1_44269+16] };
                    }
            }
    }
    else {
            eax = intrinsic_pextrw(intrinsic_movlpd(xmm1, arg_8), 0x3);
            eax = eax & 0x8000;
            if (eax != 0x0) {
                    asm { fldz };
            }
            else {
                    asm { fld        qword [double_value_minus_1_44269+16] };
            }
    }
    return eax;

loc_4843e1:
    xmm2 = intrinsic_movlpd(xmm2, arg_0);
    xmm2 = intrinsic_psrlq(xmm2, 0x20);
    eax = eax | zero_extend_32(xmm2) & 0x7fffffff;
    ecx = 0x0;
    if (eax == 0x0) goto loc_48428a;
    goto loc_48440a;

loc_484155:
    intrinsic_movlpd(xmm1, arg_8);
    intrinsic_movlpd(xmm2, arg_8);
    xmm1 = intrinsic_andpd(xmm1, Nan);
    xmm1 = intrinsic_psrlq(xmm1, 0x34);
    xmm1 = intrinsic_psubd(xmm1, xmm3);
    xmm3 = intrinsic_movlpd(xmm3, -0.0);
    xmm2 = intrinsic_psllq(xmm2, xmm1);
    xmm2 = intrinsic_pcmpeqd(xmm2, xmm3);
    ecx = 0x3ff01 + (intrinsic_pmovmskb(eax, xmm2) & 0xff) & 0x40000;
    if (edx < 0x10) goto loc_484204;
    goto loc_4841a6;

loc_48447a:
    if (edx != 0xbff00000) goto .l16;
    goto loc_484482;

loc_484870:
    if (((intrinsic_pextrw(xmm1, 0x3) ^ (intrinsic_pextrw(intrinsic_movlpd(xmm4, arg_0), 0x3) & 0x7ff0) - 0x3ff0) & 0x8000) == 0x0) {
            edx = 0x18;
            if (ecx != 0x0) {
                    xmm0 = intrinsic_movlpd(xmm0, -8.98847e+307);
                    xmm0 = xmm0 * 8.98847e+307;
            }
            else {
                    xmm0 = intrinsic_movlpd(xmm0, 8.98847e+307);
                    xmm0 = xmm0 * xmm0;
            }
    }
    else {
            xmm0 = intrinsic_movlpd(xmm0, 2.22507e-308);
            xmm0 = intrinsic_orpd(xmm0 * xmm0, intrinsic_psllq(zero_extend_32(ecx), 0x2d));
            edx = 0x19;
    }
    goto .l13;

loc_484850:
    asm { fld        qword [esp+0x10+var_C] };
    return eax;

loc_4845cd:
    if (eax <= 0xfffc0200) goto loc_4847c9;
    goto loc_4845d8;

loc_4845a5:
    bool_9 = true;
    bool_8 = true;
    if (eax >= 0x40000) goto loc_4847ec;
    goto loc_4845b0;

loc_484238:
    intrinsic_andpd(xmm7, xmm0);
    xmm4 = xmm0;
    xmm0 = intrinsic_andpd(xmm0, Nan);
    xmm0 = intrinsic_psrlq(xmm0, 0x2c);
    intrinsic_pextrw(xmm0, 0x0);
    xmm7 = intrinsic_orpd(xmm7, xmm2);
    xmm7 = xmm7 * *(double *)(((eax & 0xff) + 0x1 & 0x1fe) * 0x4 + double_value_1);
    xmm5 = intrinsic_movlpd(xmm5, *(int64_t *)(((eax & 0xff) + 0x1 & 0x1fe) * 0x4 + double_value_1));
    xmm6 = intrinsic_movapd(xmm6, *(int128_t *)((eax + eax) * 0x4 + 0x4b3fb0));
    edx = 0x43e7f;
    goto loc_483de6;

loc_484297:
    if ((arg_c & 0x80000000) != 0x0) {
            xmm0 = intrinsic_psllq(zero_extend_32(0x7ff00000 | eax & ecx << 0xd), 0x20);
            intrinsic_movlpd(xmm1, 1.0) / intrinsic_movlpd(xmm2, arg_0);
            intrinsic_movlpd(var_C, xmm0);
            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
            asm { fld        qword [esp+0x1c+var_C] };
    }
    else {
            eax = eax & ecx << 0xd;
            if (eax == 0x0) {
                    asm { fldz };
            }
            else {
                    asm { fld        qword [double_value_minus_0] };
            }
    }
    return eax;

loc_48440a:
    intrinsic_movlpd(xmm1, Nan);
    xmm0 = intrinsic_movlpd(xmm0, Nan);
    intrinsic_movlpd(var_C, xmm0);
    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
    asm { fld        qword [esp+0x1c+var_C] };
    return eax;

loc_4841a6:
    edx = 0xbfe7f;
    intrinsic_movlpd(xmm3, 2.22507e-308);
    intrinsic_movlpd(xmm2, 1.0);
    goto loc_483de6;

loc_484482:
    asm { fld1 };
    return eax;

loc_4847c9:
    xmm0 = intrinsic_movlpd(xmm0, 2.22507e-308);
    xmm0 = intrinsic_orpd(xmm0 * xmm0, intrinsic_psllq(zero_extend_32(ecx), 0x2d));
    edx = 0x19;
    goto .l13;

loc_4845d8:
    decomp_var_4 = esi;
    edx = eax;
    eax = eax & 0x7f;
    ecx = ecx + 0x80;
    edx = (edx & 0xffffff80) + 0x3fe80;
    esp = esp - 0x8;
    var_C = edi;
    edi = 0x0;
    goto loc_4845f3;

loc_4847ec:
    edx = 0x18;
    if (ecx != 0x0) {
            xmm0 = intrinsic_movlpd(xmm0, -8.98847e+307);
            xmm0 = xmm0 * 8.98847e+307;
    }
    else {
            xmm0 = intrinsic_movlpd(xmm0, 8.98847e+307);
            xmm0 = xmm0 * xmm0;
    }
    goto .l13;

loc_4845b0:
    decomp_var_4 = esi;
    edx = eax;
    eax = eax & 0x7f;
    ecx = ecx + 0x3ff00;
    edx = edx - 0x80 & 0xffffff80;
    esp = esp - 0x8;
    var_C = edi;
    edi = 0x3ff0;
    goto loc_4845f3;

loc_4845f3:
    intrinsic_mulpd(xmm2, xmm7);
    intrinsic_mulpd(xmm7, xmm7);
    intrinsic_movapd(xmm3, *(int128_t *)(eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + eax + 0x4b6c20));
    intrinsic_movapd(xmm6, 0.00133336);
    xmm2 * xmm7 + intrinsic_pshufd(intrinsic_addpd(xmm2, intrinsic_mulpd(xmm1, xmm7)), 0xee) + xmm4;
    intrinsic_movlpd(xmm4, 0.693147);
    intrinsic_xorpd(xmm7, xmm7);
    intrinsic_pinsrw(0x3f80, 0x3);
    intrinsic_pshufd(intrinsic_psllq(xmm1, 0x2d), 0x44);
    intrinsic_movapd(xmm7, 0.00961813);
    intrinsic_mulpd(xmm3, xmm1);
    intrinsic_mulpd(xmm6, intrinsic_unpcklpd(xmm0 + xmm5, xmm0 + xmm5));
    intrinsic_mulpd(xmm0, xmm0);
    intrinsic_pshufd(intrinsic_mulpd(intrinsic_addpd(xmm7, xmm6), xmm0), 0xee);
    intrinsic_pshufd(xmm3, 0xee);
    xmm7 = intrinsic_psllq(zero_extend_32(ecx), 0x2d);
    intrinsic_andpd(intrinsic_psllq(intrinsic_pcmpeqd(xmm1, xmm1), xmm2), xmm3);
    intrinsic_xorpd(xmm6, xmm6);
    xmm1 = intrinsic_andpd(xmm1 + xmm0, intrinsic_psllq(intrinsic_pcmpeqd(xmm4, xmm4), xmm2));
    xmm6 = intrinsic_pinsrw(edi, 0x3);
    esp = esp + 0x4;
    xmm0 = xmm0 + (xmm2 - xmm1) + xmm3;
    if (edx <= 0x1ff80) {
            esp = esp + 0x4;
            xmm0 = xmm0 * xmm7 + xmm1 * xmm7 + xmm6 * (xmm0 * xmm7 + xmm1 * xmm7);
            eax = intrinsic_pextrw(xmm0, 0x3);
            eax = eax & 0x7ff0;
            edx = 0x18;
            if (eax != 0x7ff0) {
                    edx = 0x19;
                    if (eax != 0x0) {
                            asm { fld        qword [esp+0x10+var_C] };
                    }
                    else {
                            intrinsic_movlpd(var_C, xmm0);
                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                            asm { fld        qword [esp+0x1c+var_C] };
                    }
            }
            else {
                    intrinsic_movlpd(var_C, xmm0);
                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                    asm { fld        qword [esp+0x1c+var_C] };
            }
    }
    else {
            esp = esp + 0x4;
            xmm0 = (xmm0 + xmm1) * xmm7 + xmm6 * (xmm0 + xmm1) * xmm7;
            eax = intrinsic_pextrw(xmm0, 0x3);
            eax = eax & 0x7ff0;
            edx = 0x18;
            if (eax != 0x7ff0) {
                    edx = 0x19;
                    if (eax != 0x0) {
                            asm { fld        qword [esp+0x10+var_C] };
                    }
                    else {
                            intrinsic_movlpd(var_C, xmm0);
                            eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                            asm { fld        qword [esp+0x1c+var_C] };
                    }
            }
            else {
                    intrinsic_movlpd(var_C, xmm0);
                    eax = sub_48cc5f(&var_1C + 0x28 - 0x8, &var_1C + 0x28, &var_1C + 0x10, edx);
                    asm { fld        qword [esp+0x1c+var_C] };
            }
    }
    return eax;
}
