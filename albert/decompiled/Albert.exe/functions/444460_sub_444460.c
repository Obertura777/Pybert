// sub_444460 @ 0x444460
// hopper name: sub_444460
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_444460() {

sub_444460:
    esi = arg_48;
    if (ebx == 0x0 || ebx != &arg_44) {
            sub_47a948();
    }
    if (edi == esi) goto loc_4445df;
    goto loc_44447d;

loc_4445df:
    if (arg_12 == 0x1) goto .l1;
    goto .l2;

loc_44447d:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    esi = edi + 0xc;
    esp = esp - 0x4;
    if (*(int8_t *)sub_422170(esi) != 0x1) goto loc_4445c9;
    goto loc_4444a6;

.l1:
    eax = (null)();
    return eax;

.l2:
    ebx = *arg_48;
    esi = &arg_44;
    arg_38 = esi;
    arg_3c = ebx;
    &saved_fp = &saved_fp;
    goto loc_444600;

loc_4445c9:
    sub_40e680();
    edi = arg_3c;
    ebx = arg_38;
    goto sub_444460;

loc_4444a6:
    if (edi == ebx[0x1]) {
            sub_47a948();
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(esi + 0x4, saved_fp);
    ebx = *eax[0x1];
    esi = eax;
    arg_84 = eax;
    arg_74 = esi;
    arg_78 = ebx;
    &saved_fp = &saved_fp;
    goto loc_4444f0;

loc_444600:
    edi = arg_48;
    if (esi == 0x0 || esi != &arg_44) {
            sub_47a948();
    }
    if (ebx == edi) goto loc_4446e2;
    goto loc_44461d;

loc_4444f0:
    edi = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (ebx == edi) goto loc_4445c9;
    goto loc_444508;

loc_4446e2:
    if (arg_13 != 0x1) goto .l31;
    goto loc_4446ed;

loc_44461d:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (ebx == esi[0x1]) {
            sub_47a948();
    }
    eax = ebx[0x3];
    if (*(int8_t *)(arg_14[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) != 0x0) {
            if (ebx == esi[0x1]) {
                    sub_47a948();
            }
            eax = ebx[0x3];
            ecx = eax + eax * 0x8;
            eax = arg_14[0x2];
            eax = *(int16_t *)(eax + ecx * 0x4 + 0x20);
            bool_29 = HIBYTE(eax) == 0x41;
            eax = eax & 0xff;
            if (!bool_29) {
                    eax = 0x14;
            }
            edi = arg_4;
            arg_5C = eax;
            arg_80 = edi[0x1];
            esp = esp - 0x8;
            eax = sub_401ff0(&arg_90, &arg_5C, saved_fp, arg_0, arg_4);
            esi = eax;
            eax = *esi;
            if (eax == 0x0 || eax != edi) {
                    sub_47a948();
            }
            if (esi[0x1] == arg_80) {
                    if (ebx == arg_38[0x1]) {
                            sub_47a948();
                    }
                    if (ebx[0x14] == 0x1) {
                            arg_13 = 0x0;
                    }
            }
    }
    sub_40e680();
    ebx = arg_3c;
    esi = arg_38;
    goto loc_444600;

loc_444508:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (ebx == esi[0x1]) {
            sub_47a948();
    }
    edi = ebx + 0xc;
    esp = esp - 0x4;
    if (*(int8_t *)(sub_422200(edi) + 0x14) == 0x0) {
            if (ebx == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            if (*(int8_t *)sub_422170(edi) == 0x0) {
                    if (ebx == esi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    *(int8_t *)sub_422170(edi) = 0x1;
                    if (ebx == esi[0x1]) {
                            sub_47a948();
                    }
                    eax = *edi;
                    if (*(int8_t *)(arg_14[0x2] + (eax + eax * 0x8) * 0x4 + 0x4) == 0x1) {
                            if (ebx == esi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x4;
                            arg_2c = *edi;
                            eax = sub_422170(&arg_2c);
                            *(int8_t *)eax = 0x1;
                    }
                    arg_12 = 0x1;
            }
    }
    sub_40f400();
    ebx = arg_78;
    esi = arg_74;
    eax = arg_84;
    goto loc_4444f0;

.l31:
    goto loc_44547a;

loc_4446ed:
    arg_34 = 0xffffffff;
    arg_38 = &arg_44;
    arg_3c = *arg_48;
    goto loc_444707;

loc_44547a:
    sub_403430(&arg_9C, &arg_6C, *arg_70, &arg_6C, arg_70);
    sub_47c8f9();
    sub_403430(&arg_9C, &arg_54, *arg_58, &arg_54, arg_58);
    sub_47c8f9();
    sub_41af00(&arg_9C, &arg_24, *arg_28, &arg_24, arg_28);
    sub_47c8f9();
    sub_41ad70(&arg_9C, &arg_48, *arg_4c, &arg_48, arg_4c);
    sub_47c8f9();
    eax = arg_17;
    *0x0 = arg_118;
    &arg_10 = ebp;
    return eax;

loc_444707:
    esi = arg_3c;
    edi = arg_38;
    goto loc_44470f;

loc_44470f:
    ebx = arg_48;
    if (edi == 0x0 || edi != &arg_44) {
            sub_47a948();
    }
    if (esi == ebx) goto loc_44499a;
    goto loc_44472c;

loc_44499a:
    esi = arg_14[0x2];
    eax = esi[0x915];
    esi = esi + 0x2450;
    edi = *eax;
    arg_18 = esi;
    arg_1c = edi;
    &saved_fp = &saved_fp;
    goto loc_4449c0;

loc_44472c:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x14] != 0x1) goto loc_444903;
    goto loc_444749;

loc_4449c0:
    eax = arg_14[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi == ebx) goto loc_444ad0;
    goto loc_4449e7;

loc_444903:
    sub_40e680();
    edi = arg_38;
    ebx = arg_48;
    if (edi == 0x0 || edi != &arg_44) {
            sub_47a948();
    }
    esi = arg_3c;
    if (esi != ebx) goto loc_44470f;
    goto loc_444931;

loc_444749:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (arg_34 == esi[0x3]) goto loc_444831;
    goto loc_444760;

loc_444ad0:
    if (arg_13 != 0x1) goto .l31;
    goto loc_444adb;

loc_4449e7:
    arg_80 = arg_4[0x1];
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    eax = sub_401ff0(&arg_90, edi + 0x18, saved_fp, arg_0, arg_4);
    ebx = eax;
    eax = *ebx;
    if (eax == 0x0 || eax != arg_4) {
            sub_47a948();
    }
    if (ebx[0x1] != arg_80) goto loc_444aba;
    goto loc_444a3d;

loc_444931:
    edi = *arg_54;
    esi = &arg_50;
    arg_2c = esi;
    arg_30 = edi;
    goto loc_444943;

loc_444831:
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(esi + 0x10, saved_fp);
    edi = *eax[0x1];
    esi = eax;
    arg_84 = eax;
    arg_74 = esi;
    arg_78 = edi;
    goto loc_444875;

loc_444760:
    edi = *arg_54;
    esi = &arg_50;
    arg_2c = esi;
    arg_30 = edi;
    goto loc_444772;

loc_444adb:
    ebx = arg_14;
    arg_38 = 0x0;
    goto loc_444ae7;

loc_444aba:
    sub_401390();
    edi = arg_1c;
    esi = arg_18;
    goto loc_4449c0;

loc_444a3d:
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    ebx = edi + 0x10;
    esp = esp - 0x4;
    if (*(sub_422200(ebx) + 0x10) > 0x1) goto loc_444a9f;
    goto loc_444a5a;

loc_444943:
    ebx = arg_54;
    if (esi == 0x0 || esi != &arg_50) {
            sub_47a948();
    }
    if (edi == ebx) goto loc_444707;
    goto loc_444960;

loc_444875:
    ebx = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi == ebx) goto loc_444903;
    goto loc_444889;

loc_444772:
    ebx = arg_54;
    if (esi == 0x0 || esi != &arg_50) {
            sub_47a948();
    }
    if (edi == ebx) goto loc_4447c5;
    goto loc_44478b;

loc_444ae7:
    eax = ebx[0x2];
    arg_38 = arg_38 + 0x1;
    edi = eax + 0x2450;
    esi = *eax[0x915];
    arg_12 = 0x0;
    arg_18 = edi;
    arg_1c = esi;
    goto loc_444b10;

loc_444a9f:
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    *(sub_422200(ebx) + 0x4) = 0xffffffff;
    goto loc_444aba;

loc_444a5a:
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    *(int8_t *)sub_422200(ebx) = 0x1;
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    *(int8_t *)(sub_422200(ebx) + 0x9) = 0x1;
    sub_401390();
    edi = arg_1c;
    esi = arg_18;
    goto loc_4449c0;

loc_444960:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_422200(edi + 0xc);
    eax[0x4] = eax[0x4] + 0x1;
    sub_401520();
    edi = arg_30;
    esi = arg_2c;
    goto loc_444943;

loc_444889:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    ebx = edi + 0xc;
    esp = esp - 0x4;
    if (*(int8_t *)(sub_422200(ebx) + 0x14) == 0x1) {
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_404ce0(&arg_98, ebx, saved_fp);
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            *(sub_422200(ebx) + 0x4) = arg_34;
    }
    sub_40f400();
    edi = arg_78;
    esi = arg_74;
    eax = arg_84;
    goto loc_444875;

loc_4447c5:
    edi = arg_54[0x1];
    esi = edi;
    if (edi[0x11] != 0x0) goto loc_4447f4;
    goto loc_4447d4;

loc_44478b:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_422200(edi + 0xc);
    eax[0x4] = eax[0x4] + 0x1;
    sub_401520();
    edi = arg_30;
    esi = arg_2c;
    goto loc_444772;

loc_444b10:
    eax = ebx[0x2];
    ecx = eax[0x915];
    eax = eax + 0x2450;
    arg_C0 = ecx;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi == arg_C0) goto loc_444ee0;
    goto loc_444b3f;

loc_4447f4:
    esi = arg_3c;
    arg_54[0x1] = arg_54;
    arg_58 = 0x0;
    *arg_54 = arg_54;
    arg_54[0x2] = arg_54;
    if (esi == arg_38[0x1]) {
            sub_47a948();
    }
    edx = esi[0x3];
    edi = arg_38;
    esi = arg_3c;
    arg_34 = edx;
    goto loc_444831;

loc_4447d4:
    sub_401950(esi[0x2]);
    esi = *esi;
    sub_47c8f9();
    esp = (esp - 0x8) + 0x4;
    edi = esi;
    if (esi[0x11] == 0x0) goto loc_4447d4;
    goto loc_4447f4;

loc_444ee0:
    if (arg_12 == 0x1) goto loc_444ae7;
    goto loc_444eeb;

loc_444b3f:
    arg_E0 = arg_4[0x1];
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    eax = sub_401ff0(&arg_F4, esi + 0x18, saved_fp, arg_0, arg_4);
    ebx = eax;
    eax = *ebx;
    if (eax == 0x0 || eax != arg_4) {
            sub_47a948();
    }
    if (ebx[0x1] != arg_E0) goto loc_444e42;
    goto loc_444b95;

loc_444eeb:
    edi = arg_14;
    goto loc_444efc;

loc_444e42:
    esi = *arg_28;
    edi = &arg_24;
    arg_64 = edi;
    arg_68 = esi;
    goto loc_444e54;

loc_444b95:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    ebx = esi + 0x10;
    esp = esp - 0x4;
    arg_88 = ebx;
    if (*(int8_t *)sub_422200(ebx) != 0x1) goto loc_444e42;
    goto loc_444bbc;

loc_444efc:
    eax = edi[0x2];
    arg_3c = arg_3c + 0x1;
    esi = eax + 0x2450;
    ebx = *eax[0x915];
    arg_16 = 0x0;
    arg_1c = esi;
    arg_20 = ebx;
    goto loc_444f22;

loc_444e54:
    ebx = arg_28;
    if (edi == 0x0 || edi != &arg_24) {
            sub_47a948();
    }
    if (esi == ebx) goto loc_444ec6;
    goto loc_444e6d;

loc_444bbc:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    if (*(int8_t *)(sub_422200(ebx) + 0x8) != 0x0) goto loc_444e42;
    goto loc_444bda;

loc_444f22:
    eax = edi[0x2];
    ecx = eax[0x915];
    eax = eax + 0x2450;
    arg_CC = ecx;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (ebx == arg_CC) goto loc_4453ed;
    goto loc_444f51;

loc_444ec6:
    sub_401390();
    esi = arg_20;
    edi = arg_1c;
    ebx = arg_18;
    goto loc_444b10;

loc_444e6d:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x24] == 0x1) {
            if (esi == edi[0x1]) {
                    sub_47a948();
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
            }
            if (esi[0x7] >= esi[0x8] - 0x1) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esi[0x19] = 0x1;
            }
    }
    sub_40e210();
    esi = arg_68;
    edi = arg_64;
    goto loc_444e54;

loc_444bda:
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(esi + 0x14, saved_fp);
    ebx = *eax[0x1];
    edi = eax;
    arg_34 = 0xffffffff;
    arg_40 = 0x0;
    arg_78 = ebx;
    goto loc_444c34;

loc_4453ed:
    if (arg_16 == 0x1) goto loc_444ef1;
    goto loc_4453f8;

loc_444f51:
    edi = arg_4;
    arg_EC = edi[0x1];
    if (esi == 0x0) {
            sub_47a948();
    }
    if (ebx == esi[0x1]) {
            sub_47a948();
    }
    saved_fp = ebx + 0x18;
    esp = esp - 0x8;
    eax = sub_401ff0(&arg_100, saved_fp, arg_0, arg_4, arg_8);
    esi = eax;
    eax = *esi;
    if (eax == 0x0 || eax != edi) {
            sub_47a948();
    }
    if (esi[0x1] != arg_EC) goto loc_4452fc;
    goto loc_444fa5;

loc_444c34:
    arg_D0 = eax[0x1];
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (ebx == arg_D0) goto loc_444dd4;
    goto loc_444c58;

loc_444ef1:
    if (arg_17 != 0x1) goto loc_4453f8;
    goto loc_444efc;

loc_4453f8:
    if (arg_3c > 0x2) goto loc_444ad0;
    goto loc_445403;

loc_4452fc:
    sub_401390();
    ebx = arg_20;
    edi = arg_18;
    esi = arg_1c;
    goto loc_444f22;

loc_444fa5:
    esi = arg_20;
    if (esi == arg_1c[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    saved_fp = esi + 0x10;
    if (*(int8_t *)(sub_422200(saved_fp) + 0x9) != 0x0) goto loc_4452fc;
    goto loc_444fce;

loc_444dd4:
    eax = arg_40;
    if (eax == 0x0) {
            if (esi == arg_18[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            *(int8_t *)(sub_422200(arg_88) + 0x8) = 0x1;
    }
    else {
            if (eax == 0x1) {
                    if (esi == arg_18[0x1]) {
                            sub_47a948();
                    }
                    *(int8_t *)(sub_422200(arg_88) + 0x8) = 0x1;
                    esp = esp - 0x8;
                    eax = sub_422200(&arg_34);
                    eax[0x3] = eax[0x3] + 0x1;
            }
    }
    goto loc_444e42;

loc_444c58:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (ebx == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    arg_8C = ebx + 0xc;
    if (*(int8_t *)(sub_422200(ebx + 0xc) + 0x14) == 0x1) {
            if (ebx == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            if (*(int8_t *)(sub_422200(arg_8C) + 0x9) == 0x0) {
                    if (ebx == edi[0x1]) {
                            sub_47a948();
                    }
                    if (arg_34 != *arg_8C) {
                            if (esi == arg_18[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x4;
                            if (*(sub_422200(arg_88) + 0x4) == 0xffffffff) {
                                    arg_40 = arg_40 + 0x1;
                                    if (ebx == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    arg_34 = *arg_8C;
                            }
                            else {
                                    if (esi == arg_18[0x1]) {
                                            sub_47a948();
                                    }
                                    esp = esp - 0x4;
                                    eax = sub_422200(arg_88);
                                    bool_98 = ebx != edi[0x1];
                                    esi = eax[0x1];
                                    if (!bool_98) {
                                            sub_47a948();
                                    }
                                    esi = arg_14 + (esi + esi * 0x2) * 0x4 + 0x2a1c;
                                    arg_5C = *arg_8C;
                                    arg_D8 = esi[0x1];
                                    esp = esp - 0x8;
                                    eax = sub_401ff0(&arg_EC, &arg_5C, saved_fp, arg_0, arg_4);
                                    ebx = eax;
                                    eax = *ebx;
                                    if (eax == 0x0 || eax != esi) {
                                            sub_47a948();
                                    }
                                    if (ebx[0x1] != arg_D8) {
                                            arg_40 = arg_40 + 0x1;
                                            if (arg_78 == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            arg_34 = *arg_8C;
                                    }
                            }
                    }
            }
    }
    sub_40f400();
    ebx = arg_7C;
    edi = arg_78;
    eax = arg_88;
    esi = arg_20;
    goto loc_444c34;

loc_445403:
    if (arg_17 != 0x1) goto .l31;
    goto loc_44540a;

loc_444fce:
    eax = arg_70;
    edi = eax[0x1];
    arg_44 = 0x0;
    esi = edi;
    if (edi[0x11] != 0x0) goto loc_445006;
    goto loc_444fe2;

loc_44540a:
    edi = *arg_28;
    esi = &arg_24;
    arg_64 = esi;
    arg_68 = edi;
    &arg_0 = &arg_0;
    goto loc_445420;

loc_445006:
    eax[0x1] = eax;
    *arg_70 = arg_70;
    arg_70[0x2] = arg_70;
    if (arg_20 == arg_1c[0x1]) {
            sub_47a948();
    }
    edi = arg_20;
    eax = edi[0x4];
    ebx = arg_18 + (eax + eax * 0x2) * 0x4 + 0x2a1c;
    arg_34 = **(arg_18 + (eax + eax * 0x2) * 0x4 + 0x2a20);
    goto loc_445052;

loc_444fe2:
    sub_401950(esi[0x2]);
    esi = *esi;
    sub_47c8f9();
    esp = (esp - 0x8) + 0x4;
    edi = esi;
    if (esi[0x11] == 0x0) goto loc_444fe2;
    goto loc_445002;

loc_445420:
    ebx = arg_28;
    if (esi == 0x0 || esi != &arg_24) {
            sub_47a948();
    }
    if (edi == ebx) goto loc_44547a;
    goto loc_445439;

loc_445052:
    if (edi == arg_1c[0x1]) {
            sub_47a948();
    }
    eax = edi[0x4];
    esi = *(arg_18 + (eax + eax * 0x2) * 0x4 + 0x2a20);
    eax = arg_18 + (eax + eax * 0x2) * 0x4 + 0x2a1c;
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (arg_34 == esi) goto loc_4452b2;
    goto loc_44508f;

loc_445002:
    eax = arg_70;
    goto loc_445006;

loc_445439:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    if (edi[0x24] == 0x1) {
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi[0x19] == 0x0) {
                    arg_17 = 0x0;
            }
    }
    sub_40e210();
    edi = arg_68;
    esi = arg_64;
    goto loc_445420;

loc_4452b2:
    if (edi == arg_1c[0x1]) {
            sub_47a948();
    }
    if (edi == arg_1c[0x1]) {
            sub_47a948();
    }
    ebx = edi + 0x10;
    esp = esp - 0x8;
    saved_fp = ebx;
    if (*(sub_422200(edi + 0x10) + 0x10) - *(sub_422200(saved_fp) + 0xc) - arg_44 <= 0x1) goto loc_445316;
    goto loc_4452f7;

loc_44508f:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (arg_34 == ebx[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    arg_38 = arg_34 + 0xc;
    if (*(int8_t *)(sub_422200(arg_34 + 0xc) + 0x14) != 0x1) goto loc_44529c;
    goto loc_4450c5;

loc_445316:
    esi = arg_1c;
    if (edi == esi[0x1]) {
            sub_47a948();
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x8;
    saved_fp = ebx;
    if (*(sub_422200(edi + 0x10) + 0x10) - *(sub_422200(saved_fp) + 0xc) - arg_44 != 0x1) goto loc_4452fc;
    goto loc_445354;

loc_4452f7:
    arg_17 = 0x0;
    goto loc_4452fc;

loc_44529c:
    sub_401520();
    ebx = arg_34;
    edi = arg_24;
    goto loc_445052;

loc_4450c5:
    if (arg_34 == ebx[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    if (*(int8_t *)sub_422200(arg_38) != 0x1) goto loc_44529c;
    goto loc_4450ea;

loc_445354:
    arg_16 = 0x1;
    if (edi == arg_1c[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    saved_fp = ebx;
    *(int8_t *)(sub_422200(saved_fp) + 0x9) = 0x1;
    edi = *arg_70;
    esi = &arg_6C;
    arg_80 = esi;
    arg_84 = edi;
    goto loc_445390;

loc_4450ea:
    if (arg_34 == ebx[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    if (*(int8_t *)(sub_422200(arg_38) + 0x8) != 0x0) goto loc_44529c;
    goto loc_445110;

loc_445390:
    ebx = arg_70;
    if (esi == 0x0 || esi != &arg_6C) {
            sub_47a948();
    }
    if (edi == ebx) goto loc_4452fc;
    goto loc_4453ad;

loc_445110:
    esi = arg_34;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    edi = arg_38;
    esp = esp - 0x4;
    if (*(sub_422200(edi) + 0x4) != 0xffffffff) goto loc_44519e;
    goto loc_445132;

loc_4453ad:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    saved_fp = edi + 0xc;
    *(int8_t *)(sub_422200(saved_fp) + 0x8) = 0x1;
    sub_401520();
    edi = arg_84;
    esi = arg_80;
    goto loc_445390;

loc_44519e:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    esi = *(sub_422200(edi) + 0x4);
    if (arg_20 == arg_1c[0x1]) {
            sub_47a948();
    }
    esi = arg_18 + (esi + esi * 0x2) * 0x4 + 0x2a1c;
    arg_60 = arg_20[0x4];
    esp = esp - 0x8;
    arg_98 = esi[0x1];
    eax = sub_401ff0(&arg_9C, &arg_60, arg_0, arg_4, arg_8);
    edi = eax;
    eax = *edi;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (edi[0x1] == arg_98) goto loc_44529c;
    goto loc_445222;

loc_445132:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_407720(edi);
    edi = arg_20;
    esi = eax;
    if (edi == arg_1c[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    if (sub_460a10(esi, edi[0x4]) != 0x1) goto loc_44529c;
    goto loc_44517f;

loc_445222:
    if (arg_34 == ebx[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    edi = arg_20;
    esi = sub_407720(arg_38);
    if (edi == arg_1c[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    if (sub_460a10(esi, edi[0x4]) != 0x1) goto loc_44529c;
    goto loc_445273;

loc_44517f:
    arg_44 = arg_44 + 0x1;
    if (arg_34 == ebx[0x1]) {
            sub_47a948();
    }
    edx = &arg_108;
    goto loc_44528d;

loc_445273:
    arg_44 = arg_44 + 0x1;
    if (arg_34 == ebx[0x1]) {
            sub_47a948();
    }
    edx = &arg_A8;
    goto loc_44528d;

loc_44528d:
    arg_0 = arg_3c;
    esp = esp - 0x8;
    sub_404ce0(edx, arg_0, arg_4);
    goto loc_44529c;
}
