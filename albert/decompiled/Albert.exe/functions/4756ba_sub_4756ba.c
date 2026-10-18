// sub_4756ba @ 0x4756ba
// hopper name: sub_4756ba
// referenced by: called,pointer
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4756ba() {
    esp = esp - 0x4;
    sub_47d6bb(0x70);
    edi = ecx;
    decomp_var_10 = 0x0;
    decomp_var_14 = 0x7fffffff;
    ebx = arg_4;
    decomp_var_4 = 0x0;
    if (ebx != 0x111) goto loc_475704;
    goto loc_4756e2;

loc_475704:
    if (ebx != 0x4e) goto loc_475733;
    goto loc_475709;

loc_4756e2:
    if ((*(*edi + 0xe8))(arg_8, arg_c) == 0x0) goto loc_4758ca;
    goto loc_4756f8;

loc_475733:
    esi = arg_c;
    if (ebx == 0x6) {
            esp = esp - 0x10;
            decomp_var_10 = edi;
            sub_475089(decomp_var_10, arg_8, sub_473aee(esi));
    }
    if (ebx != 0x20) goto loc_475764;
    goto loc_475750;

loc_475709:
    ecx = arg_c;
    if (*ecx == 0x0) goto loc_4758ca;
    goto loc_475714;

loc_4758ca:
    sub_4727ce();
    goto loc_4758d8;

loc_4756f8:
    decomp_var_10 = 0x1;
    goto loc_475bb1;

loc_475764:
    eax = edi[0x13];
    if (eax == 0x0 || eax[0x1d] <= 0x0) goto loc_4757b8;
    goto loc_475771;

loc_475750:
    esp = esp - 0xc;
    decomp_var_10 = edi;
    if (sub_4750ff(decomp_var_10, sign_extend_32(esi), esi >> 0x10) != 0x0) goto loc_4756f8;
    goto loc_475764;

loc_475714:
    eax = *edi;
    decomp_var_10 = arg_8;
    eax = (eax[0x3b])(decomp_var_10, ecx, &decomp_var_10);
    goto loc_475726;

loc_4758d8:
    eax = sub_47d75a();
    return eax;

loc_475bb1:
    eax = arg_10;
    if (eax != 0x0) {
            *eax = decomp_var_10;
    }
    sub_4727ce();
    goto loc_4758d8;

loc_4757b8:
    eax = *edi;
    eax = (eax[0xa])();
    esp = esp - 0x4;
    arg_c = eax;
    ebx = (eax ^ arg_4) & 0x1ff;
    sub_47279f();
    ebx = ebx * 0xc + 0xbc4720;
    decomp_var_18 = ebx;
    if (arg_4 != *ebx) goto loc_475818;
    goto loc_4757ea;

loc_475771:
    if (ebx < 0x200 || ebx > 0x209) goto loc_475781;
    goto loc_47579c;

loc_475726:
    if (eax == 0x0) {
            sub_4727ce();
    }
    else {
            eax = arg_10;
            if (eax != 0x0) {
                    *eax = decomp_var_10;
            }
            sub_4727ce();
    }
    goto loc_4758d8;

loc_475818:
    ebx = arg_c;
    ecx = arg_4;
    *decomp_var_18 = ecx;
    decomp_var_18[0x2] = ebx;
    while (true) {
            if (*ebx == 0x0) {
                    decomp_var_18[0x1] = decomp_var_18[0x1] & 0x0;
                    sub_4727ce();
                    temp_1 = 0x1;
                    break;
            }
            else {
                    arg_0 = 0x0;
                    esp = esp - 0x8;
                    saved_fp = 0x0;
                    if (arg_4 < 0xc000) {
                            decomp_var_4 = arg_4;
                            esp = esp - 0x8;
                            eax = sub_472033(ebx[0x1], decomp_var_4, saved_fp, arg_0);
                            arg_c = eax;
                            if (eax == 0x0) {
                                    ebx = (*ebx)();
                                    arg_c = ebx;
                                    continue;
                            }
                            decomp_var_18[0x1] = eax;
                            sub_4727ce();
                            temp_1 = 0x0;
                            break;
                    }
                    else {
                            decomp_var_4 = 0xc000;
                            esp = esp - 0x8;
                            while (true) {
                                    ebx = sub_472033(arg_4, arg_8, arg_c, arg_10);
                                    if (ebx != 0x0) {
                                            ecx = arg_4;
                                            if (*ebx[0x4] != ecx) {
                                                    arg_10 = 0x0;
                                                    arg_c = 0x0;
                                                    arg_8 = 0xc000;
                                                    esp = esp - 0x10;
                                                    arg_4 = ebx + 0x18;
                                                    continue;
                                            }
                                            ecx = &decomp_var_14;
                                            decomp_var_18[0x1] = ebx;
                                            sub_4727ce();
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    temp_0 = 0x0;
                                    break;
                            }
                            if (temp_0 == 0x0) {
                                    ebx = arg_c;
                                    ebx = (*ebx)();
                                    arg_c = ebx;
                                    continue;
                            }
                            temp_1 = 0x2;
                            break;
                    }
            }
    }
    if (temp_1 == 0x0) goto loc_475858;
    goto .l88;

loc_4757ea:
    eax = ebx;
    if (arg_c != eax[0x2]) goto loc_475818;
    goto loc_4757f4;

loc_475781:
    if (ebx < 0x100 || ebx > 0x10f) goto loc_475791;

loc_47579c:
    eax = *edi[0x13];
    decomp_var_10 = arg_8;
    esp = esp - 0x10;
    decomp_var_14 = ebx;
    eax = (eax[0x25])(decomp_var_14, decomp_var_10, esi, &decomp_var_10);
    if (eax != 0x0) goto loc_475bb1;
    goto loc_4757b8;

loc_475858:
    ebx = arg_c[0x5];
    eax = arg_c[0x4];
    ecx = eax - 0x1;
    if (ecx > 0x44) goto loc_475bb1;
    goto loc_47586d;

.l88:
    if (temp_1 == 0x1) goto loc_4758ca;
    goto loc_475ba3;

loc_4757f4:
    ebx = eax[0x1];
    arg_c = ebx;
    sub_4727ce();
    if (ebx == 0x0) goto loc_4758ca;
    goto loc_47580a;

loc_475791:
    if (ebx > 0x291) goto .l19;
    goto loc_47579c;

loc_47586d:
    if (*(ecx * 0x4 + switch_table) == 0x0) goto loc_4758f0;
    goto .l32;

loc_475ba3:
    ebx = ebx[0x5];
    goto loc_475ba6;

loc_47580a:
    if (arg_4 < 0xc000) goto loc_475858;
    goto loc_475ba3;

.l19:
    eax = *edi;
    eax = (eax[0xa])();
    esp = esp - 0x4;
    arg_c = eax;
    ebx = (eax ^ arg_4) & 0x1ff;
    sub_47279f();
    ebx = ebx * 0xc + 0xbc4720;
    decomp_var_18 = ebx;
    if (arg_4 == *ebx) {
            eax = ebx;
            if (arg_c == eax[0x2]) {
                    ebx = eax[0x1];
                    arg_c = ebx;
                    sub_4727ce();
                    if (ebx != 0x0) {
                            if (arg_4 >= 0xc000) {
                                    ebx = ebx[0x5];
                                    arg_0 = esi;
                                    saved_fp = arg_8;
                                    eax = (ebx)(saved_fp, arg_0);
                                    decomp_var_10 = eax;
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                            }
                            else {
                                    ebx = arg_c[0x5];
                                    eax = arg_c[0x4];
                                    ecx = eax - 0x1;
                                    switch (*(ecx * 0x4 + switch_table)) {
                                        case 0:
                                            sub_476eb4();
                                            eax = (ebx)();
                                            decomp_var_10 = eax;
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 1:
                                            eax = (ebx)();
                                            decomp_var_10 = eax;
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 2:
                                            esp = esp - 0xc;
                                            decomp_var_14 = arg_8;
                                            eax = sub_473aee(decomp_var_14);
                                            eax = (ebx)(eax);
                                            decomp_var_10 = eax;
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 3:
                                            esp = esp - 0x8;
                                            eax = sub_473aee(arg_8);
                                            eax = (ebx)();
                                            decomp_var_10 = eax;
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 4:
                                            eax = (ebx)();
                                            decomp_var_10 = eax;
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 5:
                                            sub_476adc();
                                            decomp_var_24 = esi[0x1];
                                            sub_4727e8();
                                            eax = *esi;
                                            esi = esi[0x2];
                                            esp = esp - 0x4;
                                            decomp_var_c = eax;
                                            decomp_var_5c = eax;
                                            eax = sub_473b15();
                                            if (eax == 0x0) {
                                                    eax = edi[0x13];
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x4;
                                                            decomp_var_c = decomp_var_5c;
                                                            eax = sub_4791ea();
                                                    }
                                                    eax = &decomp_var_7c;
                                            }
                                            decomp_var_14 = eax;
                                            eax = (ebx)(&decomp_var_28, decomp_var_14, esi, decomp_var_c);
                                            decomp_var_10 = eax;
                                            sub_474239();
                                            decomp_var_4 = 0x0;
                                            sub_476f26();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 6:
                                            sub_476adc();
                                            eax = (ebx)(&decomp_var_28, esi[0x2]);
                                            decomp_var_10 = eax;
                                            decomp_var_4 = 0x0;
                                            sub_476f26();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 7:
                                            esp = esp - 0x8;
                                            eax = sub_473aee(esi);
                                            esp = esp - 0x4;
                                            eax = arg_8 & 0xffff;
                                            eax = (ebx)(eax);
                                            decomp_var_10 = eax;
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 8:
                                            esp = esp - 0x4;
                                            eax = arg_8 & 0xffff;
                                            eax = (ebx)();
                                            decomp_var_10 = eax;
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 9:
                                            arg_0 = esi;
                                            saved_fp = arg_8;
                                            eax = (ebx)(saved_fp, arg_0);
                                            decomp_var_10 = eax;
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 10:
                                            esp = esp - 0x8;
                                            sub_479653(esi);
                                            eax = arg_8 >> 0x10;
                                            esp = esp - 0x4;
                                            eax = arg_8 & 0xffff;
                                            eax = (ebx)(eax);
                                            decomp_var_10 = eax;
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 11:
                                            esp = esp - 0x4;
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 12:
                                            decomp_var_c = arg_8;
                                            (ebx)(decomp_var_c);
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 13:
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 14:
                                            esp = esp - 0x4;
                                            eax = arg_8 & 0xffff;
                                            decomp_var_10 = eax;
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 15:
                                            esp = esp - 0x4;
                                            eax = sign_extend_32(esi);
                                            decomp_var_10 = eax;
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 16:
                                            esp = esp - 0x4;
                                            eax = esi & 0xffff;
                                            decomp_var_10 = eax;
                                            decomp_var_14 = arg_8;
                                            (ebx)(decomp_var_14, decomp_var_10);
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 17:
                                            esp = esp - 0x8;
                                            sub_473aee(esi);
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 18:
                                            eax = (ebx)();
                                            decomp_var_10 = eax;
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 19:
                                            sub_473aee(arg_8);
                                            esp = esp - 0x10;
                                            decomp_var_10 = sub_473aee(esi);
                                            eax = edi[0x8] == esi ? 0x1 : 0x0;
                                            decomp_var_14 = eax;
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 20:
                                            esp = esp - 0x4;
                                            eax = sub_476eb4();
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 21:
                                            esp = esp - 0x4;
                                            eax = sub_479653(arg_8);
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 22:
                                            decomp_var_10 = sign_extend_32(esi);
                                            esp = esp - 0xc;
                                            eax = sub_479653(arg_8, decomp_var_10, sign_extend_32(esi >> 0x10));
                                            decomp_var_14 = eax;
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 23:
                                            esp = esp - 0x4;
                                            decomp_var_c = arg_8;
                                            eax = sub_473aee(decomp_var_c);
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 24:
                                            esp = esp - 0x4;
                                            decomp_var_c = esi;
                                            eax = sub_473aee(decomp_var_c);
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 25:
                                            esp = esp - 0x4;
                                            eax = esi & 0xffff;
                                            decomp_var_10 = eax;
                                            esp = esp - 0x8;
                                            eax = sub_473aee(arg_8);
                                            decomp_var_14 = eax;
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 26:
                                            eax = sign_extend_32(esi);
                                            esp = esp - 0x4;
                                            decomp_var_10 = eax;
                                            esp = esp - 0x8;
                                            eax = sub_473aee(arg_8);
                                            decomp_var_14 = eax;
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 27:
                                            esp = esp - 0x8;
                                            eax = sub_473aee(arg_8);
                                            decomp_var_10 = eax;
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 28:
                                            esp = esp - 0x8;
                                            eax = sub_473aee(esi);
                                            esp = esp - 0x4;
                                            decomp_var_10 = eax;
                                            eax = arg_8 & 0xffff;
                                            decomp_var_14 = eax;
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 29:
                                            edx = sign_extend_32(arg_8);
                                            ecx = sign_extend_32(arg_8 >> 0x10);
                                            arg_4 = edx;
                                            arg_8 = ecx;
                                            if (eax == 0x2a) {
                                                    sub_473aee(esi);
                                                    decomp_var_10 = arg_8;
                                                    decomp_var_14 = arg_4;
                                                    (ebx)();
                                            }
                                            else {
                                                    decomp_var_10 = edx;
                                                    (ebx)();
                                            }
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 30:
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 31:
                                            (ebx)(arg_8, esi);
                                            decomp_var_10 = 0x1;
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 32:
                                            eax = sign_extend_32(esi);
                                            esp = esp - 0x4;
                                            eax = (ebx)();
                                            decomp_var_10 = eax;
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 33:
                                            esp = esp - 0x4;
                                            eax = arg_8 >> 0x10;
                                            esp = esp - 0x4;
                                            decomp_var_10 = eax;
                                            eax = arg_8 & 0xffff;
                                            decomp_var_14 = eax;
                                            (ebx)();
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 34:
                                            eax = sign_extend_32(esi);
                                            esp = esp - 0x4;
                                            decomp_var_10 = eax;
                                            decomp_var_14 = arg_8;
                                            (ebx)(decomp_var_14, decomp_var_10);
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        case 35:
                                            decomp_var_14 = arg_8 >> 0x10;
                                            eax = (ebx)(arg_8 & 0xffff, decomp_var_14, sign_extend_32(esi), sign_extend_32(esi >> 0x10));
                                            decomp_var_10 = eax;
                                            if (eax == 0x0) {
                                                    sub_4727ce();
                                                    eax = sub_47d75a();
                                            }
                                            else {
                                                    eax = arg_10;
                                                    if (eax != 0x0) {
                                                            *eax = decomp_var_10;
                                                    }
                                                    sub_4727ce();
                                                    eax = sub_47d75a();
                                            }
                                            break;
                                        case 36:
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                            break;
                                        default:
                                            eax = (ebx)();
                                            decomp_var_10 = eax;
                                            if (eax != 0x0) {
                                                    sub_4727ce();
                                                    eax = sub_47d75a();
                                            }
                                            else {
                                                    eax = arg_10;
                                                    if (eax != 0x0) {
                                                            *eax = decomp_var_10;
                                                    }
                                                    sub_4727ce();
                                                    eax = sub_47d75a();
                                            }
                                            break;
                                        default:
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                    }
                            }
                    }
                    else {
                            sub_4727ce();
                            eax = sub_47d75a();
                    }
            }
            else {
                    ebx = arg_c;
                    ecx = arg_4;
                    *decomp_var_18 = ecx;
                    decomp_var_18[0x2] = ebx;
                    while (true) {
                            if (*ebx == 0x0) {
                                    decomp_var_18[0x1] = decomp_var_18[0x1] & 0x0;
                                    sub_4727ce();
                                    temp_1 = 0x1;
                                    break;
                            }
                            else {
                                    arg_0 = 0x0;
                                    esp = esp - 0x8;
                                    saved_fp = 0x0;
                                    if (arg_4 < 0xc000) {
                                            decomp_var_4 = arg_4;
                                            esp = esp - 0x8;
                                            eax = sub_472033(ebx[0x1], decomp_var_4, saved_fp, arg_0);
                                            arg_c = eax;
                                            if (eax == 0x0) {
                                                    ebx = (*ebx)();
                                                    arg_c = ebx;
                                                    continue;
                                            }
                                            decomp_var_18[0x1] = eax;
                                            sub_4727ce();
                                            temp_1 = 0x0;
                                            break;
                                    }
                                    else {
                                            decomp_var_4 = 0xc000;
                                            esp = esp - 0x8;
                                            while (true) {
                                                    ebx = sub_472033(arg_4, arg_8, arg_c, arg_10);
                                                    if (ebx != 0x0) {
                                                            ecx = arg_4;
                                                            if (*ebx[0x4] != ecx) {
                                                                    arg_10 = 0x0;
                                                                    arg_c = 0x0;
                                                                    arg_8 = 0xc000;
                                                                    esp = esp - 0x10;
                                                                    arg_4 = ebx + 0x18;
                                                                    continue;
                                                            }
                                                            ecx = &decomp_var_14;
                                                            decomp_var_18[0x1] = ebx;
                                                            sub_4727ce();
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                            if (temp_0 == 0x0) {
                                                    ebx = arg_c;
                                                    ebx = (*ebx)();
                                                    arg_c = ebx;
                                                    continue;
                                            }
                                            temp_1 = 0x2;
                                            break;
                                    }
                            }
                    }
                    switch (temp_1) {
                        case 0:
                            ebx = arg_c[0x5];
                            eax = arg_c[0x4];
                            ecx = eax - 0x1;
                            switch (*(ecx * 0x4 + switch_table)) {
                                case 0:
                                    sub_476eb4();
                                    eax = (ebx)();
                                    decomp_var_10 = eax;
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 1:
                                    eax = (ebx)();
                                    decomp_var_10 = eax;
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 2:
                                    esp = esp - 0xc;
                                    decomp_var_14 = arg_8;
                                    eax = sub_473aee(decomp_var_14);
                                    eax = (ebx)(eax);
                                    decomp_var_10 = eax;
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 3:
                                    esp = esp - 0x8;
                                    eax = sub_473aee(arg_8);
                                    eax = (ebx)();
                                    decomp_var_10 = eax;
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 4:
                                    eax = (ebx)();
                                    decomp_var_10 = eax;
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 5:
                                    sub_476adc();
                                    decomp_var_24 = esi[0x1];
                                    sub_4727e8();
                                    eax = *esi;
                                    esi = esi[0x2];
                                    esp = esp - 0x4;
                                    decomp_var_c = eax;
                                    decomp_var_5c = eax;
                                    eax = sub_473b15();
                                    if (eax == 0x0) {
                                            eax = edi[0x13];
                                            if (eax != 0x0) {
                                                    esp = esp - 0x4;
                                                    decomp_var_c = decomp_var_5c;
                                                    eax = sub_4791ea();
                                            }
                                            eax = &decomp_var_7c;
                                    }
                                    decomp_var_14 = eax;
                                    eax = (ebx)(&decomp_var_28, decomp_var_14, esi, decomp_var_c);
                                    decomp_var_10 = eax;
                                    sub_474239();
                                    decomp_var_4 = 0x0;
                                    sub_476f26();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 6:
                                    sub_476adc();
                                    eax = (ebx)(&decomp_var_28, esi[0x2]);
                                    decomp_var_10 = eax;
                                    decomp_var_4 = 0x0;
                                    sub_476f26();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 7:
                                    esp = esp - 0x8;
                                    eax = sub_473aee(esi);
                                    esp = esp - 0x4;
                                    eax = arg_8 & 0xffff;
                                    eax = (ebx)(eax);
                                    decomp_var_10 = eax;
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 8:
                                    esp = esp - 0x4;
                                    eax = arg_8 & 0xffff;
                                    eax = (ebx)();
                                    decomp_var_10 = eax;
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 9:
                                    arg_0 = esi;
                                    saved_fp = arg_8;
                                    eax = (ebx)(saved_fp, arg_0);
                                    decomp_var_10 = eax;
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 10:
                                    esp = esp - 0x8;
                                    sub_479653(esi);
                                    eax = arg_8 >> 0x10;
                                    esp = esp - 0x4;
                                    eax = arg_8 & 0xffff;
                                    eax = (ebx)(eax);
                                    decomp_var_10 = eax;
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 11:
                                    esp = esp - 0x4;
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 12:
                                    decomp_var_c = arg_8;
                                    (ebx)(decomp_var_c);
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 13:
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 14:
                                    esp = esp - 0x4;
                                    eax = arg_8 & 0xffff;
                                    decomp_var_10 = eax;
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 15:
                                    esp = esp - 0x4;
                                    eax = sign_extend_32(esi);
                                    decomp_var_10 = eax;
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 16:
                                    esp = esp - 0x4;
                                    eax = esi & 0xffff;
                                    decomp_var_10 = eax;
                                    decomp_var_14 = arg_8;
                                    (ebx)(decomp_var_14, decomp_var_10);
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 17:
                                    esp = esp - 0x8;
                                    sub_473aee(esi);
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 18:
                                    eax = (ebx)();
                                    decomp_var_10 = eax;
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 19:
                                    sub_473aee(arg_8);
                                    esp = esp - 0x10;
                                    decomp_var_10 = sub_473aee(esi);
                                    eax = edi[0x8] == esi ? 0x1 : 0x0;
                                    decomp_var_14 = eax;
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 20:
                                    esp = esp - 0x4;
                                    eax = sub_476eb4();
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 21:
                                    esp = esp - 0x4;
                                    eax = sub_479653(arg_8);
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 22:
                                    decomp_var_10 = sign_extend_32(esi);
                                    esp = esp - 0xc;
                                    eax = sub_479653(arg_8, decomp_var_10, sign_extend_32(esi >> 0x10));
                                    decomp_var_14 = eax;
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 23:
                                    esp = esp - 0x4;
                                    decomp_var_c = arg_8;
                                    eax = sub_473aee(decomp_var_c);
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 24:
                                    esp = esp - 0x4;
                                    decomp_var_c = esi;
                                    eax = sub_473aee(decomp_var_c);
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 25:
                                    esp = esp - 0x4;
                                    eax = esi & 0xffff;
                                    decomp_var_10 = eax;
                                    esp = esp - 0x8;
                                    eax = sub_473aee(arg_8);
                                    decomp_var_14 = eax;
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 26:
                                    eax = sign_extend_32(esi);
                                    esp = esp - 0x4;
                                    decomp_var_10 = eax;
                                    esp = esp - 0x8;
                                    eax = sub_473aee(arg_8);
                                    decomp_var_14 = eax;
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 27:
                                    esp = esp - 0x8;
                                    eax = sub_473aee(arg_8);
                                    decomp_var_10 = eax;
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 28:
                                    esp = esp - 0x8;
                                    eax = sub_473aee(esi);
                                    esp = esp - 0x4;
                                    decomp_var_10 = eax;
                                    eax = arg_8 & 0xffff;
                                    decomp_var_14 = eax;
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 29:
                                    edx = sign_extend_32(arg_8);
                                    ecx = sign_extend_32(arg_8 >> 0x10);
                                    arg_4 = edx;
                                    arg_8 = ecx;
                                    if (eax == 0x2a) {
                                            sub_473aee(esi);
                                            decomp_var_10 = arg_8;
                                            decomp_var_14 = arg_4;
                                            (ebx)();
                                    }
                                    else {
                                            decomp_var_10 = edx;
                                            (ebx)();
                                    }
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 30:
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 31:
                                    (ebx)(arg_8, esi);
                                    decomp_var_10 = 0x1;
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 32:
                                    eax = sign_extend_32(esi);
                                    esp = esp - 0x4;
                                    eax = (ebx)();
                                    decomp_var_10 = eax;
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 33:
                                    esp = esp - 0x4;
                                    eax = arg_8 >> 0x10;
                                    esp = esp - 0x4;
                                    decomp_var_10 = eax;
                                    eax = arg_8 & 0xffff;
                                    decomp_var_14 = eax;
                                    (ebx)();
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 34:
                                    eax = sign_extend_32(esi);
                                    esp = esp - 0x4;
                                    decomp_var_10 = eax;
                                    decomp_var_14 = arg_8;
                                    (ebx)(decomp_var_14, decomp_var_10);
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                case 35:
                                    decomp_var_14 = arg_8 >> 0x10;
                                    eax = (ebx)(arg_8 & 0xffff, decomp_var_14, sign_extend_32(esi), sign_extend_32(esi >> 0x10));
                                    decomp_var_10 = eax;
                                    if (eax == 0x0) {
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                    }
                                    else {
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                    }
                                    break;
                                case 36:
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                                    break;
                                default:
                                    eax = (ebx)();
                                    decomp_var_10 = eax;
                                    if (eax != 0x0) {
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                    }
                                    else {
                                            eax = arg_10;
                                            if (eax != 0x0) {
                                                    *eax = decomp_var_10;
                                            }
                                            sub_4727ce();
                                            eax = sub_47d75a();
                                    }
                                    break;
                                default:
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                            }
                            break;
                        case 1:
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        default:
                            ebx = ebx[0x5];
                            arg_0 = esi;
                            saved_fp = arg_8;
                            eax = (ebx)(saved_fp, arg_0);
                            decomp_var_10 = eax;
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                    }
            }
    }
    else {
            ebx = arg_c;
            ecx = arg_4;
            *decomp_var_18 = ecx;
            decomp_var_18[0x2] = ebx;
            while (true) {
                    if (*ebx == 0x0) {
                            decomp_var_18[0x1] = decomp_var_18[0x1] & 0x0;
                            sub_4727ce();
                            temp_1 = 0x1;
                            break;
                    }
                    else {
                            arg_0 = 0x0;
                            esp = esp - 0x8;
                            saved_fp = 0x0;
                            if (arg_4 < 0xc000) {
                                    decomp_var_4 = arg_4;
                                    esp = esp - 0x8;
                                    eax = sub_472033(ebx[0x1], decomp_var_4, saved_fp, arg_0);
                                    arg_c = eax;
                                    if (eax == 0x0) {
                                            ebx = (*ebx)();
                                            arg_c = ebx;
                                            continue;
                                    }
                                    decomp_var_18[0x1] = eax;
                                    sub_4727ce();
                                    temp_1 = 0x0;
                                    break;
                            }
                            else {
                                    decomp_var_4 = 0xc000;
                                    esp = esp - 0x8;
                                    while (true) {
                                            ebx = sub_472033(arg_4, arg_8, arg_c, arg_10);
                                            if (ebx != 0x0) {
                                                    ecx = arg_4;
                                                    if (*ebx[0x4] != ecx) {
                                                            arg_10 = 0x0;
                                                            arg_c = 0x0;
                                                            arg_8 = 0xc000;
                                                            esp = esp - 0x10;
                                                            arg_4 = ebx + 0x18;
                                                            continue;
                                                    }
                                                    ecx = &decomp_var_14;
                                                    decomp_var_18[0x1] = ebx;
                                                    sub_4727ce();
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    if (temp_0 == 0x0) {
                                            ebx = arg_c;
                                            ebx = (*ebx)();
                                            arg_c = ebx;
                                            continue;
                                    }
                                    temp_1 = 0x2;
                                    break;
                            }
                    }
            }
            switch (temp_1) {
                case 0:
                    ebx = arg_c[0x5];
                    eax = arg_c[0x4];
                    ecx = eax - 0x1;
                    switch (*(ecx * 0x4 + switch_table)) {
                        case 0:
                            sub_476eb4();
                            eax = (ebx)();
                            decomp_var_10 = eax;
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 1:
                            eax = (ebx)();
                            decomp_var_10 = eax;
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 2:
                            esp = esp - 0xc;
                            decomp_var_14 = arg_8;
                            eax = sub_473aee(decomp_var_14);
                            eax = (ebx)(eax);
                            decomp_var_10 = eax;
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 3:
                            esp = esp - 0x8;
                            eax = sub_473aee(arg_8);
                            eax = (ebx)();
                            decomp_var_10 = eax;
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 4:
                            eax = (ebx)();
                            decomp_var_10 = eax;
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 5:
                            sub_476adc();
                            decomp_var_24 = esi[0x1];
                            sub_4727e8();
                            eax = *esi;
                            esi = esi[0x2];
                            esp = esp - 0x4;
                            decomp_var_c = eax;
                            decomp_var_5c = eax;
                            eax = sub_473b15();
                            if (eax == 0x0) {
                                    eax = edi[0x13];
                                    if (eax != 0x0) {
                                            esp = esp - 0x4;
                                            decomp_var_c = decomp_var_5c;
                                            eax = sub_4791ea();
                                    }
                                    eax = &decomp_var_7c;
                            }
                            decomp_var_14 = eax;
                            eax = (ebx)(&decomp_var_28, decomp_var_14, esi, decomp_var_c);
                            decomp_var_10 = eax;
                            sub_474239();
                            decomp_var_4 = 0x0;
                            sub_476f26();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 6:
                            sub_476adc();
                            eax = (ebx)(&decomp_var_28, esi[0x2]);
                            decomp_var_10 = eax;
                            decomp_var_4 = 0x0;
                            sub_476f26();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 7:
                            esp = esp - 0x8;
                            eax = sub_473aee(esi);
                            esp = esp - 0x4;
                            eax = arg_8 & 0xffff;
                            eax = (ebx)(eax);
                            decomp_var_10 = eax;
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 8:
                            esp = esp - 0x4;
                            eax = arg_8 & 0xffff;
                            eax = (ebx)();
                            decomp_var_10 = eax;
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 9:
                            arg_0 = esi;
                            saved_fp = arg_8;
                            eax = (ebx)(saved_fp, arg_0);
                            decomp_var_10 = eax;
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 10:
                            esp = esp - 0x8;
                            sub_479653(esi);
                            eax = arg_8 >> 0x10;
                            esp = esp - 0x4;
                            eax = arg_8 & 0xffff;
                            eax = (ebx)(eax);
                            decomp_var_10 = eax;
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 11:
                            esp = esp - 0x4;
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 12:
                            decomp_var_c = arg_8;
                            (ebx)(decomp_var_c);
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 13:
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 14:
                            esp = esp - 0x4;
                            eax = arg_8 & 0xffff;
                            decomp_var_10 = eax;
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 15:
                            esp = esp - 0x4;
                            eax = sign_extend_32(esi);
                            decomp_var_10 = eax;
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 16:
                            esp = esp - 0x4;
                            eax = esi & 0xffff;
                            decomp_var_10 = eax;
                            decomp_var_14 = arg_8;
                            (ebx)(decomp_var_14, decomp_var_10);
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 17:
                            esp = esp - 0x8;
                            sub_473aee(esi);
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 18:
                            eax = (ebx)();
                            decomp_var_10 = eax;
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 19:
                            sub_473aee(arg_8);
                            esp = esp - 0x10;
                            decomp_var_10 = sub_473aee(esi);
                            eax = edi[0x8] == esi ? 0x1 : 0x0;
                            decomp_var_14 = eax;
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 20:
                            esp = esp - 0x4;
                            eax = sub_476eb4();
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 21:
                            esp = esp - 0x4;
                            eax = sub_479653(arg_8);
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 22:
                            decomp_var_10 = sign_extend_32(esi);
                            esp = esp - 0xc;
                            eax = sub_479653(arg_8, decomp_var_10, sign_extend_32(esi >> 0x10));
                            decomp_var_14 = eax;
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 23:
                            esp = esp - 0x4;
                            decomp_var_c = arg_8;
                            eax = sub_473aee(decomp_var_c);
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 24:
                            esp = esp - 0x4;
                            decomp_var_c = esi;
                            eax = sub_473aee(decomp_var_c);
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 25:
                            esp = esp - 0x4;
                            eax = esi & 0xffff;
                            decomp_var_10 = eax;
                            esp = esp - 0x8;
                            eax = sub_473aee(arg_8);
                            decomp_var_14 = eax;
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 26:
                            eax = sign_extend_32(esi);
                            esp = esp - 0x4;
                            decomp_var_10 = eax;
                            esp = esp - 0x8;
                            eax = sub_473aee(arg_8);
                            decomp_var_14 = eax;
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 27:
                            esp = esp - 0x8;
                            eax = sub_473aee(arg_8);
                            decomp_var_10 = eax;
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 28:
                            esp = esp - 0x8;
                            eax = sub_473aee(esi);
                            esp = esp - 0x4;
                            decomp_var_10 = eax;
                            eax = arg_8 & 0xffff;
                            decomp_var_14 = eax;
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 29:
                            edx = sign_extend_32(arg_8);
                            ecx = sign_extend_32(arg_8 >> 0x10);
                            arg_4 = edx;
                            arg_8 = ecx;
                            if (eax == 0x2a) {
                                    sub_473aee(esi);
                                    decomp_var_10 = arg_8;
                                    decomp_var_14 = arg_4;
                                    (ebx)();
                            }
                            else {
                                    decomp_var_10 = edx;
                                    (ebx)();
                            }
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 30:
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 31:
                            (ebx)(arg_8, esi);
                            decomp_var_10 = 0x1;
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 32:
                            eax = sign_extend_32(esi);
                            esp = esp - 0x4;
                            eax = (ebx)();
                            decomp_var_10 = eax;
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 33:
                            esp = esp - 0x4;
                            eax = arg_8 >> 0x10;
                            esp = esp - 0x4;
                            decomp_var_10 = eax;
                            eax = arg_8 & 0xffff;
                            decomp_var_14 = eax;
                            (ebx)();
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 34:
                            eax = sign_extend_32(esi);
                            esp = esp - 0x4;
                            decomp_var_10 = eax;
                            decomp_var_14 = arg_8;
                            (ebx)(decomp_var_14, decomp_var_10);
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        case 35:
                            decomp_var_14 = arg_8 >> 0x10;
                            eax = (ebx)(arg_8 & 0xffff, decomp_var_14, sign_extend_32(esi), sign_extend_32(esi >> 0x10));
                            decomp_var_10 = eax;
                            if (eax == 0x0) {
                                    sub_4727ce();
                                    eax = sub_47d75a();
                            }
                            else {
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                            }
                            break;
                        case 36:
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                            break;
                        default:
                            eax = (ebx)();
                            decomp_var_10 = eax;
                            if (eax != 0x0) {
                                    sub_4727ce();
                                    eax = sub_47d75a();
                            }
                            else {
                                    eax = arg_10;
                                    if (eax != 0x0) {
                                            *eax = decomp_var_10;
                                    }
                                    sub_4727ce();
                                    eax = sub_47d75a();
                            }
                            break;
                        default:
                            eax = arg_10;
                            if (eax != 0x0) {
                                    *eax = decomp_var_10;
                            }
                            sub_4727ce();
                            eax = sub_47d75a();
                    }
                    break;
                case 1:
                    sub_4727ce();
                    eax = sub_47d75a();
                    break;
                default:
                    ebx = ebx[0x5];
                    arg_0 = esi;
                    saved_fp = arg_8;
                    eax = (ebx)(saved_fp, arg_0);
                    decomp_var_10 = eax;
                    eax = arg_10;
                    if (eax != 0x0) {
                            *eax = decomp_var_10;
                    }
                    sub_4727ce();
                    eax = sub_47d75a();
                    break;
            }
    }
    return eax;

loc_4758f0:
    sub_476eb4();
    goto loc_4758f9;

.l32:
    if (*(ecx * 0x4 + switch_table) == 0x1) goto loc_4758f9;
    goto .l33;

loc_475ba6:
    arg_0 = esi;
    saved_fp = arg_8;
    goto loc_475baa;

loc_4758f9:
    eax = (ebx)();
    goto loc_475bae;

.l33:
    if (*(ecx * 0x4 + switch_table) == 0x2) goto loc_47591c;
    goto .l34;

loc_475baa:
    eax = (ebx)(saved_fp, arg_0);
    goto loc_475bae;

loc_475bae:
    decomp_var_10 = eax;
    goto loc_475bb1;

loc_47591c:
    esp = esp - 0xc;
    decomp_var_14 = arg_8;
    eax = sub_473aee(decomp_var_14);
    goto loc_47592e;

.l34:
    if (*(ecx * 0x4 + switch_table) == 0x3) goto loc_475938;
    goto .l35;

loc_47592e:
    eax = (ebx)(eax);
    goto loc_475bae;

loc_475938:
    esp = esp - 0x8;
    eax = sub_473aee(arg_8);
    goto loc_475baa;

.l35:
    if (*(ecx * 0x4 + switch_table) == 0x4) goto loc_4758f9;

.l36:
    if (*(ecx * 0x4 + switch_table) == 0x5) goto loc_475946;
    goto .l37;

loc_475946:
    sub_476adc();
    decomp_var_24 = esi[0x1];
    sub_4727e8();
    eax = *esi;
    esi = esi[0x2];
    esp = esp - 0x4;
    decomp_var_c = eax;
    decomp_var_5c = eax;
    eax = sub_473b15();
    if (eax == 0x0) {
            eax = edi[0x13];
            if (eax != 0x0) {
                    esp = esp - 0x4;
                    decomp_var_c = decomp_var_5c;
                    eax = sub_4791ea();
            }
            eax = &decomp_var_7c;
    }
    decomp_var_14 = eax;
    eax = (ebx)(&decomp_var_28, decomp_var_14, esi, decomp_var_c);
    decomp_var_10 = eax;
    sub_474239();
    goto loc_4759d9;

.l37:
    if (*(ecx * 0x4 + switch_table) == 0x6) goto loc_4759b5;
    goto .l38;

loc_4759d9:
    decomp_var_4 = 0x0;
    sub_476f26();
    goto loc_475bb1;

loc_4759b5:
    sub_476adc();
    eax = (ebx)(&decomp_var_28, esi[0x2]);
    decomp_var_10 = eax;
    goto loc_4759d9;

.l38:
    if (*(ecx * 0x4 + switch_table) == 0x7) goto loc_4759ea;
    goto .l39;

loc_4759ea:
    esp = esp - 0x8;
    eax = sub_473aee(esi);
    goto loc_4759f7;

.l39:
    if (*(ecx * 0x4 + switch_table) == 0x8) goto loc_475a01;
    goto .l40;

loc_4759f7:
    esp = esp - 0x4;
    eax = arg_8 & 0xffff;
    goto loc_47592e;

loc_475a01:
    esp = esp - 0x4;
    eax = arg_8 & 0xffff;
    goto loc_475baa;

.l40:
    if (*(ecx * 0x4 + switch_table) == 0x9) goto loc_475ba6;

.l41:
    if (*(ecx * 0x4 + switch_table) == 0xa) goto loc_475a11;
    goto .l42;

loc_475a11:
    esp = esp - 0x8;
    sub_479653(esi);
    eax = arg_8 >> 0x10;
    goto loc_4759f7;

.l42:
    if (*(ecx * 0x4 + switch_table) == 0xb) goto loc_475b1e;
    goto .l43;

loc_475b1e:
    esp = esp - 0x4;
    goto loc_475b22;

.l43:
    if (*(ecx * 0x4 + switch_table) == 0xc) goto loc_475a29;
    goto .l44;

loc_475b22:
    (ebx)();
    goto loc_475bb1;

loc_475a29:
    decomp_var_c = arg_8;
    goto loc_475b2c;

.l44:
    if (*(ecx * 0x4 + switch_table) == 0xd) goto loc_475a20;
    goto .l45;

loc_475b2c:
    (ebx)(decomp_var_c);
    goto loc_475bb1;

loc_475a20:
    (ebx)();
    goto loc_475bb1;

.l45:
    if (*(ecx * 0x4 + switch_table) == 0xe) goto loc_475a31;
    goto .l46;

loc_475a31:
    esp = esp - 0x4;
    eax = arg_8 & 0xffff;
    goto loc_475ae2;

.l46:
    if (*(ecx * 0x4 + switch_table) == 0xf) goto loc_475a41;
    goto .l47;

loc_475ae2:
    decomp_var_10 = eax;
    goto loc_475b22;

loc_475a41:
    esp = esp - 0x4;
    eax = sign_extend_32(esi);
    goto loc_475ae2;

.l47:
    if (*(ecx * 0x4 + switch_table) == 0x10) goto loc_475a52;
    goto .l48;

loc_475a52:
    esp = esp - 0x4;
    eax = esi & 0xffff;
    goto loc_475b4b;

.l48:
    if (*(ecx * 0x4 + switch_table) == 0x11) goto loc_475910;
    goto .l49;

loc_475b4b:
    decomp_var_10 = eax;
    decomp_var_14 = arg_8;
    goto loc_475b4f;

loc_475910:
    esp = esp - 0x8;
    sub_473aee(esi);
    goto loc_475b22;

.l49:
    if (*(ecx * 0x4 + switch_table) == 0x12) goto loc_475907;
    goto .l50;

loc_475b4f:
    (ebx)(decomp_var_14, decomp_var_10);
    goto loc_475bb1;

loc_475907:
    eax = (ebx)();
    goto loc_475bae;

.l50:
    if (*(ecx * 0x4 + switch_table) == 0x13) goto loc_475a60;
    goto .l51;

loc_475a60:
    sub_473aee(arg_8);
    esp = esp - 0x10;
    decomp_var_10 = sub_473aee(esi);
    eax = edi[0x8] == esi ? 0x1 : 0x0;
    goto loc_475b3e;

.l51:
    if (*(ecx * 0x4 + switch_table) == 0x14) goto loc_475a7d;
    goto .l52;

loc_475b3e:
    decomp_var_14 = eax;
    goto loc_475b4f;

loc_475a7d:
    esp = esp - 0x4;
    eax = sub_476eb4();
    goto loc_475ab6;

.l52:
    if (*(ecx * 0x4 + switch_table) == 0x15) goto loc_475a87;
    goto .l53;

loc_475ab6:
    decomp_var_c = eax;
    goto loc_475b2c;

loc_475a87:
    esp = esp - 0x4;
    eax = sub_479653(arg_8);
    goto loc_475ab6;

.l53:
    if (*(ecx * 0x4 + switch_table) == 0x16) goto loc_475a91;
    goto .l54;

loc_475a91:
    decomp_var_10 = sign_extend_32(esi);
    esp = esp - 0xc;
    eax = sub_479653(arg_8, decomp_var_10, sign_extend_32(esi >> 0x10));
    goto loc_475b3e;

.l54:
    if (*(ecx * 0x4 + switch_table) == 0x17) goto loc_475aab;
    goto .l55;

loc_475aab:
    esp = esp - 0x4;
    decomp_var_c = arg_8;
    goto loc_475ab1;

.l55:
    if (*(ecx * 0x4 + switch_table) == 0x18) goto loc_475ab0;
    goto .l56;

loc_475ab1:
    eax = sub_473aee(decomp_var_c);
    goto loc_475ab6;

loc_475ab0:
    esp = esp - 0x4;
    decomp_var_c = esi;
    goto loc_475ab1;

.l56:
    if (*(ecx * 0x4 + switch_table) == 0x19) goto loc_475ab9;
    goto .l57;

loc_475ab9:
    esp = esp - 0x4;
    eax = esi & 0xffff;
    goto loc_475ace;

.l57:
    if (*(ecx * 0x4 + switch_table) == 0x1a) goto loc_475ac4;
    goto .l58;

loc_475ace:
    decomp_var_10 = eax;
    esp = esp - 0x8;
    eax = sub_473aee(arg_8);
    goto loc_475b3e;

loc_475ac4:
    eax = sign_extend_32(esi);
    esp = esp - 0x4;
    goto loc_475ace;

.l58:
    if (*(ecx * 0x4 + switch_table) == 0x1b) goto loc_475ad9;
    goto .l59;

loc_475ad9:
    esp = esp - 0x8;
    eax = sub_473aee(arg_8);
    goto loc_475ae2;

.l59:
    if (*(ecx * 0x4 + switch_table) == 0x1c) goto loc_475ae5;
    goto .l60;

loc_475ae5:
    esp = esp - 0x8;
    eax = sub_473aee(esi);
    goto loc_475b39;

.l60:
    if (*(ecx * 0x4 + switch_table) == 0x1d) goto loc_475af4;
    goto .l61;

loc_475b39:
    esp = esp - 0x4;
    decomp_var_10 = eax;
    eax = arg_8 & 0xffff;
    goto loc_475b3e;

loc_475af4:
    edx = sign_extend_32(arg_8);
    ecx = sign_extend_32(arg_8 >> 0x10);
    arg_4 = edx;
    arg_8 = ecx;
    if (eax != 0x2a) goto loc_475b1a;
    goto loc_475b0b;

.l61:
    if (*(ecx * 0x4 + switch_table) == 0x1e) goto loc_475b2b;
    goto .l62;

loc_475b1a:
    decomp_var_10 = edx;
    goto loc_475b22;

loc_475b0b:
    sub_473aee(esi);
    decomp_var_10 = arg_8;
    decomp_var_14 = arg_4;
    goto loc_475b4f;

loc_475b2b:
    decomp_var_c = esi;
    goto loc_475b2c;

.l62:
    if (*(ecx * 0x4 + switch_table) == 0x1f) goto loc_475b55;
    goto .l63;

loc_475b55:
    (ebx)(arg_8, esi);
    goto loc_4756f8;

.l63:
    if (*(ecx * 0x4 + switch_table) == 0x20) goto loc_4758e0;
    goto .l64;

loc_4758e0:
    eax = sign_extend_32(esi);
    esp = esp - 0x4;
    goto loc_475baa;

.l64:
    if (*(ecx * 0x4 + switch_table) == 0x21) goto loc_475b32;
    goto .l65;

loc_475b32:
    esp = esp - 0x4;
    eax = arg_8 >> 0x10;
    goto loc_475b39;

.l65:
    if (*(ecx * 0x4 + switch_table) == 0x22) goto loc_475b41;
    goto .l66;

loc_475b41:
    eax = sign_extend_32(esi);
    esp = esp - 0x4;
    goto loc_475b4b;

.l66:
    if (*(ecx * 0x4 + switch_table) == 0x23) goto loc_475b62;
    goto .l67;

loc_475b62:
    decomp_var_14 = arg_8 >> 0x10;
    eax = (ebx)(arg_8 & 0xffff, decomp_var_14, sign_extend_32(esi), sign_extend_32(esi >> 0x10));
    decomp_var_10 = eax;
    goto loc_475726;

.l67:
    if (*(ecx * 0x4 + switch_table) != 0x24) {
            eax = (ebx)();
            decomp_var_10 = eax;
            if (eax != 0x0) {
                    sub_4727ce();
            }
            else {
                    eax = arg_10;
                    if (eax != 0x0) {
                            *eax = decomp_var_10;
                    }
                    sub_4727ce();
            }
    }
    else {
            eax = arg_10;
            if (eax != 0x0) {
                    *eax = decomp_var_10;
            }
            sub_4727ce();
    }
    goto loc_4758d8;
}
