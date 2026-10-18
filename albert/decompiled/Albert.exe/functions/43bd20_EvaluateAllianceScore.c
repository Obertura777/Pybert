// EvaluateAllianceScore @ 0x43bd20
// hopper name: sub_43bd20
// pybert name: EvaluateAllianceScore
// contains unmarked entry 0x43d770
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5603afdb33265f2ea0acc9a81cbc14c61d166c3a97fb9b974c9d4823276f52ec
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

EvaluateAllianceScore() {
    &decomp_var_4 = &decomp_var_4 & 0xfffffff8;
    sub_47bf20();
    asm { fld        dword [dword_value_1077936128] };
    asm { fld        dword [byte_4c6bdc+4] };
    decomp_var_8 = ebx;
    esp = esp - 0x8;
    asm { fcom       st1 };
    esi = ecx[0x2];
    arg_5c = 0x32;
    arg_48 = 0x32;
    ebx = 0x0;
    asm { fnstsw     ax };
    asm { fstp       st1 };
    esp = esp - 0x4;
    decomp_var_10 = edi;
    asm { fld        dword [aWeAreCloseToEl+60] };
    arg_0 = ecx;
    arg_30 = ebx;
    arg_28 = ebx;
    if (asm { fld        dword [aWeAreCloseToEl+60] } || *(arg_4 * 0x4 + dword_623990) < 0x3) goto loc_43bda4;
    goto loc_43bd87;

loc_43bda4:
    asm { fstp       st1 };
    goto loc_43bda6;

loc_43bd87:
    eax = 0x32;
    asm { fcom       st1 };
    asm { fnstsw     ax };
    if ((HIBYTE(eax) & 0x41) != 0x0) goto loc_43bfa9;
    goto loc_43bd94;

loc_43bda6:
    eax = esi[0x901];
    bool_9 = true;
    bool_8 = true;
    bool_7 = true;
    bool_6 = true;
    bool_5 = true;
    bool_4 = true;
    bool_3 = true;
    if (eax > 0x0) {
            arg_4 = eax;
            eax = 0x0;
            asm { rep stosd  dword [edi], eax };
            asm { rep stosd  dword [edi], eax };
            asm { rep stosd  dword [edi], eax };
            asm { rep stosd  dword [edi], eax };
            asm { rep stosd  dword [edi], eax };
            asm { rep stosd  dword [edi], eax };
            asm { rep stosd  dword [edi], eax };
            edx = 0x0;
            do {
                    bool_348 = true;
                    bool_347 = true;
                    bool_346 = true;
                    if (esi[0x900] > 0x0) {
                            eax = 0x0;
                            asm { rep stosd  dword [edi], eax };
                            asm { rep stosd  dword [edi], eax };
                            asm { rep stosd  dword [edi], eax };
                    }
                    edx = edx + 0x400;
                    arg_4 = arg_4 - 0x1;
            } while (arg_4 != 0x0);
    }
    eax = 0x0;
    if (esi[0x900] > 0x0) {
            ecx = arg_0;
            do {
                    *(eax * 0x8 + 0x62db58) = 0x0;
                    *(eax * 0x8 + 0x62db5c) = 0x0;
                    edx = ecx[0x2];
                    *(&decomp_var_10 + eax * 0x4 + 0x2f0) = 0x0;
                    eax = eax + 0x1;
            } while (eax < edx[0x900]);
    }
    edi = **dword_baed80;
    ebx = 0xbaed7c;
    arg_c = 0xbaed7c;
    arg_10 = **dword_baed80;
    goto loc_43bebf;

loc_43bfa9:
    eax = 0x32;
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    asm { fcomp      st2 };
    asm { fnstsw     ax };
    asm { fstp       st1 };
    if ((HIBYTE(eax) & 0x41) == 0x0) {
            arg_5c = 0x64;
            arg_48 = 0x5a;
    }
    else {
            arg_5c = 0x78;
            arg_48 = 0x64;
    }
    goto loc_43bda6;

loc_43bd94:
    arg_5c = 0x50;
    arg_48 = 0x46;
    goto loc_43bda4;

loc_43bebf:
    if (ebx == 0x0 || ebx != 0xbaed7c) {
            asm { fstp       st0 };
            sub_47a948();
            asm { fld        dword [aWeAreCloseToEl+60] };
    }
    if (edi != *dword_baed80) {
            bool_926 = ebx != 0x0;
            asm { fstp       st0 };
            if (!bool_926) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            ecx = edi[0x4];
            eax = edi[0x3];
            arg_58 = ecx;
            ebx = 0x0;
            if (*(arg_0[0x2] + 0x2404) <= 0x0) {
                    sub_40f380();
                    asm { fld        dword [aWeAreCloseToEl+60] };
                    edi = arg_10;
                    ebx = arg_c;
                    continue;
            }
            arg_4 = &decomp_var_10 + eax * 0x4 + 0x2f0;
            arg_8 = *(&decomp_var_10 + eax * 0x4 + 0x2f0);
            edi = arg_10 + 0x68;
            esi = &decomp_var_10 + eax * 0x4 + 0x6f0;
            do {
                    if (arg_10 == arg_c[0x1]) {
                            sub_47a948();
                    }
                    arg_8 = arg_8 + *edi;
                    if (arg_10 == arg_c[0x1]) {
                            sub_47a948();
                    }
                    *esi = *esi + *edi;
                    ebx = ebx + 0x1;
                    edi = edi + 0x4;
                    esi = esi + 0x400;
            } while (ebx < *(arg_0[0x2] + 0x2404));
            *arg_4 = arg_8;
            sub_40f380();
            asm { fld        dword [aWeAreCloseToEl+60] };
            edi = arg_10;
            ebx = arg_c;
            continue;
    }
    break;
    ecx = arg_0;
    asm { fld        dword [byte_4c6bdc+4] };
    eax = ecx[0x2];
    esi = eax[0x900];
    edx = 0x0;
    arg_14 = 0x0;
    decomp_var_4 = eax;
    arg_4 = esi;
    if (esi > 0x0) {
            edi = eax[0x901];
            do {
                    saved_fp = 0x0;
                    if (edi > 0x0) {
                            arg_8 = 0x0;
                            esi = &decomp_var_10 + edx * 0x4 + 0xaef0;
                            do {
                                    ecx = 0x0;
                                    edx = edx + edx + edx + edx;
                                    do {
                                            if (saved_fp != ecx) {
                                                    eax = arg_8 + ecx;
                                                    if (*(eax * 0x4 + 0x634e90) < 0xa) {
                                                            asm { fcom       st1 };
                                                            asm { fnstsw     ax };
                                                            bool_343 = (HIBYTE(eax) & 0x41) != 0x0;
                                                            eax = edx[0x2e5560];
                                                            if (!bool_343) {
                                                                    *esi = *esi + eax + edx[0x2e6a60];
                                                            }
                                                            else {
                                                                    eax = eax + edx[0x2e6a60];
                                                                    if (eax > *esi) {
                                                                            *esi = eax;
                                                                    }
                                                            }
                                                    }
                                            }
                                            ecx = ecx + 0x1;
                                            edx = edx + 0x400;
                                    } while (ecx < edi);
                                    arg_10 = arg_10 + 0x15;
                                    edx = arg_1c;
                                    esi = esi + 0x400;
                                    bool_339 = arg_4 + 0x1 < edi;
                                    arg_4 = arg_4 + 0x1;
                            } while (bool_339);
                            esi = arg_c;
                    }
                    edx = edx + 0x1;
                    arg_1c = edx;
            } while (edx < esi);
    }
    arg_1c = 0x0;
    if (esi <= 0x0) goto loc_43c43f;
    goto loc_43c0c3;

loc_43c43f:
    edi = arg_28;
    asm { fstp       st1 };
    edx = edi[0x901];
    eax = 0x0;
    bool_14 = edx <= 0x0;
    arg_7c = edx;
    if (edx > 0x0) {
            ecx = *(&arg_1c + eax * 0x4 + 0x298);
            if (ecx > 0x0 && *(&arg_1c + eax * 0x4 + 0x130) == 0x0) {
                    *(&arg_1c + eax * 0x4 + 0x80) = *(&arg_1c + eax * 0x4 + 0x80) + ecx;
            }
            eax = eax + 0x1;
            if (eax < edx) {
                    continue;
            }
            break;
    }
    asm { fld        qword [qword_value_4621819117588971520] };
    arg_44 = 0x0;
    if (!bool_14) {
            asm { fld        qword [aNewSelectionIs+56] };
            arg_54 = edi;
            asm { fld1 };
            asm { fld        dword [aWeHaveReceived_4b0d00+36] };
            while (true) {
                    arg_34 = 0x0;
                    if (edx > 0x0) {
                            arg_7e = arg_5c[0x3];
                            arg_74 = 0x0;
                            arg_30 = arg_4c * 0x8;
                            arg_40 = arg_4c + arg_4c + arg_4c + arg_4c;
                            do {
                                    if (arg_7e != 0x1) {
                                            arg_7c = arg_7c + 0x15;
                                            arg_38 = arg_38 + 0x800;
                                            arg_48 = arg_48 + 0x400;
                                            bool_734 = arg_3c + 0x1 < arg_8c;
                                            arg_3c = arg_3c + 0x1;
                                            if (bool_734) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    eax = arg_5c[0x10];
                                    bool_728 = HIBYTE(eax) == 0x41;
                                    eax = eax & 0xff;
                                    if (!bool_728) {
                                            eax = 0x14;
                                    }
                                    if (eax != arg_34) {
                                            arg_7c = arg_7c + 0x15;
                                            arg_38 = arg_38 + 0x800;
                                            arg_48 = arg_48 + 0x400;
                                            bool_733 = arg_3c + 0x1 < arg_8c;
                                            arg_3c = arg_3c + 0x1;
                                            if (bool_733) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    if (*(int8_t *)byte_baed68 != 0x0) {
                                            arg_7c = arg_7c + 0x15;
                                            arg_38 = arg_38 + 0x800;
                                            arg_48 = arg_48 + 0x400;
                                            bool_725 = arg_3c + 0x1 < arg_8c;
                                            arg_3c = arg_3c + 0x1;
                                            if (bool_725) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    asm { fcom       st4 };
                                    asm { fnstsw     ax };
                                    if ((HIBYTE(eax) & 0x41) == 0x0) {
                                            edi = arg_40[0x2e6a60];
                                            eax = 0x0;
                                            esi = 0x0;
                                            arg_6c = 0x0;
                                            ebx = arg_4c + arg_4c + arg_4c + arg_4c + 0xb9a980;
                                            while (true) {
                                                    if (esi == arg_34) {
                                                            esi = esi + 0x1;
                                                            ebx = ebx + 0x400;
                                                            if (esi < arg_8c) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    ecx = arg_74 + esi;
                                                    if (*(ecx * 0x4 + 0x634e90) < 0xa) {
                                                            bool_841 = *(ecx * 0x8 + 0x4d552c) < 0x0;
                                                            bool_809 = *(ecx * 0x8 + 0x4d552c) > 0x0;
                                                            if (!bool_841) {
                                                                    if (!bool_809) {
                                                                            if (*(ecx * 0x8 + 0x4d5528) > 0x1) {
                                                                                    ecx = *ebx;
                                                                                    if (ecx <= 0x0) {
                                                                                            edx = arg_30;
                                                                                            bool_802 = edx[0x15963b] > 0x0;
                                                                                            if (edx[0x15963b] >= 0x0) {
                                                                                                    if (!bool_802) {
                                                                                                            if (edx[0x15963a] > 0x0) {
                                                                                                                    if (ecx > edi) {
                                                                                                                            arg_54 = ecx - edi;
                                                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                                                            asm { fmul       st3 };
                                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                                            asm { fadd       st2 };
                                                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                                                            eax = sub_47b5c0();
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            if (arg_8 >= edi) {
                                                                                                                                    arg_54 = arg_8 - edi;
                                                                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                                                                    asm { fmul       st3 };
                                                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                                                    asm { fadd       st2 };
                                                                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                                                                    eax = sub_47b5c0();
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    eax = eax + 0x1;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    arg_74 = eax;
                                                                                                                    esi = esi + 0x1;
                                                                                                                    ebx = ebx + 0x400;
                                                                                                                    if (esi < arg_8c) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    esi = esi + 0x1;
                                                                                                                    ebx = ebx + 0x400;
                                                                                                                    if (esi < arg_8c) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            if (ecx > edi) {
                                                                                                                    arg_54 = ecx - edi;
                                                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                                                    asm { fmul       st3 };
                                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                                    asm { fadd       st2 };
                                                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                                                    eax = sub_47b5c0();
                                                                                                            }
                                                                                                            else {
                                                                                                                    if (arg_8 >= edi) {
                                                                                                                            arg_54 = arg_8 - edi;
                                                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                                                            asm { fmul       st3 };
                                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                                            asm { fadd       st2 };
                                                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                                                            eax = sub_47b5c0();
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            eax = eax + 0x1;
                                                                                                                    }
                                                                                                            }
                                                                                                            arg_74 = eax;
                                                                                                            esi = esi + 0x1;
                                                                                                            ebx = ebx + 0x400;
                                                                                                            if (esi < arg_8c) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    esi = esi + 0x1;
                                                                                                    ebx = ebx + 0x400;
                                                                                                    if (esi < arg_8c) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (ecx > edi) {
                                                                                                    arg_54 = ecx - edi;
                                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                                    asm { fmul       st3 };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fadd       st2 };
                                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                                    eax = sub_47b5c0();
                                                                                            }
                                                                                            else {
                                                                                                    if (arg_8 >= edi) {
                                                                                                            arg_54 = arg_8 - edi;
                                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                                            asm { fmul       st3 };
                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                            asm { fadd       st2 };
                                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                                            eax = sub_47b5c0();
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = eax + 0x1;
                                                                                                    }
                                                                                            }
                                                                                            arg_74 = eax;
                                                                                            esi = esi + 0x1;
                                                                                            ebx = ebx + 0x400;
                                                                                            if (esi < arg_8c) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esi = esi + 0x1;
                                                                                    ebx = ebx + 0x400;
                                                                                    if (esi < arg_8c) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = *ebx;
                                                                            if (ecx <= 0x0) {
                                                                                    edx = arg_30;
                                                                                    bool_820 = edx[0x15963b] < 0x0;
                                                                                    bool_810 = edx[0x15963b] > 0x0;
                                                                                    if (!bool_820) {
                                                                                            if (!bool_810) {
                                                                                                    if (edx[0x15963a] > 0x0) {
                                                                                                            if (ecx > edi) {
                                                                                                                    arg_54 = ecx - edi;
                                                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                                                    asm { fmul       st3 };
                                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                                    asm { fadd       st2 };
                                                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                                                    eax = sub_47b5c0();
                                                                                                            }
                                                                                                            else {
                                                                                                                    if (arg_8 >= edi) {
                                                                                                                            arg_54 = arg_8 - edi;
                                                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                                                            asm { fmul       st3 };
                                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                                            asm { fadd       st2 };
                                                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                                                            eax = sub_47b5c0();
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            eax = eax + 0x1;
                                                                                                                    }
                                                                                                            }
                                                                                                            arg_74 = eax;
                                                                                                            esi = esi + 0x1;
                                                                                                            ebx = ebx + 0x400;
                                                                                                            if (esi < arg_8c) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            esi = esi + 0x1;
                                                                                                            ebx = ebx + 0x400;
                                                                                                            if (esi < arg_8c) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (ecx > edi) {
                                                                                                            arg_54 = ecx - edi;
                                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                                            asm { fmul       st3 };
                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                            asm { fadd       st2 };
                                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                                            eax = sub_47b5c0();
                                                                                                    }
                                                                                                    else {
                                                                                                            if (arg_8 >= edi) {
                                                                                                                    arg_54 = arg_8 - edi;
                                                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                                                    asm { fmul       st3 };
                                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                                    asm { fadd       st2 };
                                                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                                                    eax = sub_47b5c0();
                                                                                                            }
                                                                                                            else {
                                                                                                                    eax = eax + 0x1;
                                                                                                            }
                                                                                                    }
                                                                                                    arg_74 = eax;
                                                                                                    esi = esi + 0x1;
                                                                                                    ebx = ebx + 0x400;
                                                                                                    if (esi < arg_8c) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            esi = esi + 0x1;
                                                                                            ebx = ebx + 0x400;
                                                                                            if (esi < arg_8c) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (ecx > edi) {
                                                                                            arg_54 = ecx - edi;
                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                            asm { fmul       st3 };
                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                            asm { fadd       st2 };
                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                            eax = sub_47b5c0();
                                                                                    }
                                                                                    else {
                                                                                            if (arg_8 >= edi) {
                                                                                                    arg_54 = arg_8 - edi;
                                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                                    asm { fmul       st3 };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fadd       st2 };
                                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                                    eax = sub_47b5c0();
                                                                                            }
                                                                                            else {
                                                                                                    eax = eax + 0x1;
                                                                                            }
                                                                                    }
                                                                                    arg_74 = eax;
                                                                                    esi = esi + 0x1;
                                                                                    ebx = ebx + 0x400;
                                                                                    if (esi < arg_8c) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    esi = esi + 0x1;
                                                                    ebx = ebx + 0x400;
                                                                    if (esi < arg_8c) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = *ebx;
                                                            if (ecx <= 0x0) {
                                                                    edx = arg_30;
                                                                    bool_842 = edx[0x15963b] > 0x0;
                                                                    if (edx[0x15963b] >= 0x0) {
                                                                            if (!bool_842) {
                                                                                    if (edx[0x15963a] > 0x0) {
                                                                                            if (ecx > edi) {
                                                                                                    arg_54 = ecx - edi;
                                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                                    asm { fmul       st3 };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fadd       st2 };
                                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                                    eax = sub_47b5c0();
                                                                                            }
                                                                                            else {
                                                                                                    if (arg_8 >= edi) {
                                                                                                            arg_54 = arg_8 - edi;
                                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                                            asm { fmul       st3 };
                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                            asm { fadd       st2 };
                                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                                            eax = sub_47b5c0();
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = eax + 0x1;
                                                                                                    }
                                                                                            }
                                                                                            arg_74 = eax;
                                                                                            esi = esi + 0x1;
                                                                                            ebx = ebx + 0x400;
                                                                                            if (esi < arg_8c) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            esi = esi + 0x1;
                                                                                            ebx = ebx + 0x400;
                                                                                            if (esi < arg_8c) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (ecx > edi) {
                                                                                            arg_54 = ecx - edi;
                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                            asm { fmul       st3 };
                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                            asm { fadd       st2 };
                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                            eax = sub_47b5c0();
                                                                                    }
                                                                                    else {
                                                                                            if (arg_8 >= edi) {
                                                                                                    arg_54 = arg_8 - edi;
                                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                                    asm { fmul       st3 };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fadd       st2 };
                                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                                    eax = sub_47b5c0();
                                                                                            }
                                                                                            else {
                                                                                                    eax = eax + 0x1;
                                                                                            }
                                                                                    }
                                                                                    arg_74 = eax;
                                                                                    esi = esi + 0x1;
                                                                                    ebx = ebx + 0x400;
                                                                                    if (esi < arg_8c) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi = esi + 0x1;
                                                                            ebx = ebx + 0x400;
                                                                            if (esi < arg_8c) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (ecx > edi) {
                                                                            arg_54 = ecx - edi;
                                                                            asm { fild       dword [esp-0x28+88] };
                                                                            asm { fmul       st3 };
                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                            asm { fadd       st2 };
                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                            eax = sub_47b5c0();
                                                                    }
                                                                    else {
                                                                            if (arg_8 >= edi) {
                                                                                    arg_54 = arg_8 - edi;
                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                    asm { fmul       st3 };
                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                    asm { fadd       st2 };
                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                    eax = sub_47b5c0();
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x1;
                                                                            }
                                                                    }
                                                                    arg_74 = eax;
                                                                    esi = esi + 0x1;
                                                                    ebx = ebx + 0x400;
                                                                    if (esi < arg_8c) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            if (eax > 0x0) {
                                                    arg_5c = arg_8 - *(&arg_2c + arg_48 + 0x6f0);
                                                    asm { fild       dword [esp-0x30+96] };
                                                    asm { fmul       st4 };
                                                    asm { fidiv      dword [ebp+0xc] };
                                                    asm { fiadd      dword [esp-0x30+120] };
                                                    eax = sub_47b5c0();
                                                    *(&arg_2c + arg_3c * 0x4 + 0xd8) = *(&arg_2c + arg_3c * 0x4 + 0xd8) - eax;
                                                    *(&arg_2c + arg_3c * 0x4 + 0x80) = *(&arg_2c + arg_3c * 0x4 + 0x80) - eax;
                                            }
                                            arg_7c = arg_7c + 0x15;
                                            arg_38 = arg_38 + 0x800;
                                            arg_48 = arg_48 + 0x400;
                                            bool_729 = arg_3c + 0x1 < arg_8c;
                                            arg_3c = arg_3c + 0x1;
                                            if (bool_729) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    if (*byte_624124 != arg_34) {
                                            arg_7c = arg_7c + 0x15;
                                            arg_38 = arg_38 + 0x800;
                                            arg_48 = arg_48 + 0x400;
                                            bool_732 = arg_3c + 0x1 < arg_8c;
                                            arg_3c = arg_3c + 0x1;
                                            if (bool_732) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    edi = arg_40[0x2e6a60];
                                    eax = 0x0;
                                    esi = 0x0;
                                    arg_6c = 0x0;
                                    ebx = arg_4c + arg_4c + arg_4c + arg_4c + 0xb9a980;
                                    while (true) {
                                            if (esi == arg_34) {
                                                    esi = esi + 0x1;
                                                    ebx = ebx + 0x400;
                                                    if (esi < arg_8c) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            ecx = arg_74 + esi;
                                            if (*(ecx * 0x4 + 0x634e90) < 0xa) {
                                                    bool_787 = *(ecx * 0x8 + 0x4d552c) > 0x0;
                                                    if (*(ecx * 0x8 + 0x4d552c) >= 0x0) {
                                                            if (!bool_787) {
                                                                    if (*(ecx * 0x8 + 0x4d5528) > 0x1) {
                                                                            ecx = *ebx;
                                                                            if (ecx <= 0x0) {
                                                                                    edx = arg_30;
                                                                                    bool_789 = edx[0x15963b] < 0x0;
                                                                                    bool_745 = edx[0x15963b] > 0x0;
                                                                                    if (!bool_789) {
                                                                                            if (!bool_745) {
                                                                                                    if (edx[0x15963a] > 0x0) {
                                                                                                            if (ecx > edi) {
                                                                                                                    arg_54 = ecx - edi;
                                                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                                                    asm { fmul       st3 };
                                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                                    asm { fadd       st2 };
                                                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                                                    eax = sub_47b5c0();
                                                                                                            }
                                                                                                            else {
                                                                                                                    if (arg_8 >= edi) {
                                                                                                                            arg_54 = arg_8 - edi;
                                                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                                                            asm { fmul       st3 };
                                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                                            asm { fadd       st2 };
                                                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                                                            eax = sub_47b5c0();
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            eax = eax + 0x1;
                                                                                                                    }
                                                                                                            }
                                                                                                            arg_74 = eax;
                                                                                                            esi = esi + 0x1;
                                                                                                            ebx = ebx + 0x400;
                                                                                                            if (esi < arg_8c) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            esi = esi + 0x1;
                                                                                                            ebx = ebx + 0x400;
                                                                                                            if (esi < arg_8c) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (ecx > edi) {
                                                                                                            arg_54 = ecx - edi;
                                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                                            asm { fmul       st3 };
                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                            asm { fadd       st2 };
                                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                                            eax = sub_47b5c0();
                                                                                                    }
                                                                                                    else {
                                                                                                            if (arg_8 >= edi) {
                                                                                                                    arg_54 = arg_8 - edi;
                                                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                                                    asm { fmul       st3 };
                                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                                    asm { fadd       st2 };
                                                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                                                    eax = sub_47b5c0();
                                                                                                            }
                                                                                                            else {
                                                                                                                    eax = eax + 0x1;
                                                                                                            }
                                                                                                    }
                                                                                                    arg_74 = eax;
                                                                                                    esi = esi + 0x1;
                                                                                                    ebx = ebx + 0x400;
                                                                                                    if (esi < arg_8c) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            esi = esi + 0x1;
                                                                                            ebx = ebx + 0x400;
                                                                                            if (esi < arg_8c) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (ecx > edi) {
                                                                                            arg_54 = ecx - edi;
                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                            asm { fmul       st3 };
                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                            asm { fadd       st2 };
                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                            eax = sub_47b5c0();
                                                                                    }
                                                                                    else {
                                                                                            if (arg_8 >= edi) {
                                                                                                    arg_54 = arg_8 - edi;
                                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                                    asm { fmul       st3 };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fadd       st2 };
                                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                                    eax = sub_47b5c0();
                                                                                            }
                                                                                            else {
                                                                                                    eax = eax + 0x1;
                                                                                            }
                                                                                    }
                                                                                    arg_74 = eax;
                                                                                    esi = esi + 0x1;
                                                                                    ebx = ebx + 0x400;
                                                                                    if (esi < arg_8c) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            esi = esi + 0x1;
                                                                            ebx = ebx + 0x400;
                                                                            if (esi < arg_8c) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = *ebx;
                                                                    if (ecx <= 0x0) {
                                                                            edx = arg_30;
                                                                            bool_750 = edx[0x15963b] < 0x0;
                                                                            bool_742 = edx[0x15963b] > 0x0;
                                                                            if (!bool_750) {
                                                                                    if (!bool_742) {
                                                                                            if (edx[0x15963a] > 0x0) {
                                                                                                    if (ecx > edi) {
                                                                                                            arg_54 = ecx - edi;
                                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                                            asm { fmul       st3 };
                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                            asm { fadd       st2 };
                                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                                            eax = sub_47b5c0();
                                                                                                    }
                                                                                                    else {
                                                                                                            if (arg_8 >= edi) {
                                                                                                                    arg_54 = arg_8 - edi;
                                                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                                                    asm { fmul       st3 };
                                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                                    asm { fadd       st2 };
                                                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                                                    eax = sub_47b5c0();
                                                                                                            }
                                                                                                            else {
                                                                                                                    eax = eax + 0x1;
                                                                                                            }
                                                                                                    }
                                                                                                    arg_74 = eax;
                                                                                                    esi = esi + 0x1;
                                                                                                    ebx = ebx + 0x400;
                                                                                                    if (esi < arg_8c) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    esi = esi + 0x1;
                                                                                                    ebx = ebx + 0x400;
                                                                                                    if (esi < arg_8c) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (ecx > edi) {
                                                                                                    arg_54 = ecx - edi;
                                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                                    asm { fmul       st3 };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fadd       st2 };
                                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                                    eax = sub_47b5c0();
                                                                                            }
                                                                                            else {
                                                                                                    if (arg_8 >= edi) {
                                                                                                            arg_54 = arg_8 - edi;
                                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                                            asm { fmul       st3 };
                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                            asm { fadd       st2 };
                                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                                            eax = sub_47b5c0();
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = eax + 0x1;
                                                                                                    }
                                                                                            }
                                                                                            arg_74 = eax;
                                                                                            esi = esi + 0x1;
                                                                                            ebx = ebx + 0x400;
                                                                                            if (esi < arg_8c) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    esi = esi + 0x1;
                                                                                    ebx = ebx + 0x400;
                                                                                    if (esi < arg_8c) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (ecx > edi) {
                                                                                    arg_54 = ecx - edi;
                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                    asm { fmul       st3 };
                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                    asm { fadd       st2 };
                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                    eax = sub_47b5c0();
                                                                            }
                                                                            else {
                                                                                    if (arg_8 >= edi) {
                                                                                            arg_54 = arg_8 - edi;
                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                            asm { fmul       st3 };
                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                            asm { fadd       st2 };
                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                            eax = sub_47b5c0();
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x1;
                                                                                    }
                                                                            }
                                                                            arg_74 = eax;
                                                                            esi = esi + 0x1;
                                                                            ebx = ebx + 0x400;
                                                                            if (esi < arg_8c) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            esi = esi + 0x1;
                                                            ebx = ebx + 0x400;
                                                            if (esi < arg_8c) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ecx = *ebx;
                                                    if (ecx <= 0x0) {
                                                            edx = arg_30;
                                                            bool_786 = edx[0x15963b] > 0x0;
                                                            if (edx[0x15963b] >= 0x0) {
                                                                    if (!bool_786) {
                                                                            if (edx[0x15963a] > 0x0) {
                                                                                    if (ecx > edi) {
                                                                                            arg_54 = ecx - edi;
                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                            asm { fmul       st3 };
                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                            asm { fadd       st2 };
                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                            eax = sub_47b5c0();
                                                                                    }
                                                                                    else {
                                                                                            if (arg_8 >= edi) {
                                                                                                    arg_54 = arg_8 - edi;
                                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                                    asm { fmul       st3 };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fadd       st2 };
                                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                                    eax = sub_47b5c0();
                                                                                            }
                                                                                            else {
                                                                                                    eax = eax + 0x1;
                                                                                            }
                                                                                    }
                                                                                    arg_74 = eax;
                                                                                    esi = esi + 0x1;
                                                                                    ebx = ebx + 0x400;
                                                                                    if (esi < arg_8c) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    esi = esi + 0x1;
                                                                                    ebx = ebx + 0x400;
                                                                                    if (esi < arg_8c) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (ecx > edi) {
                                                                                    arg_54 = ecx - edi;
                                                                                    asm { fild       dword [esp-0x28+88] };
                                                                                    asm { fmul       st3 };
                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                    asm { fadd       st2 };
                                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                                    eax = sub_47b5c0();
                                                                            }
                                                                            else {
                                                                                    if (arg_8 >= edi) {
                                                                                            arg_54 = arg_8 - edi;
                                                                                            asm { fild       dword [esp-0x28+88] };
                                                                                            asm { fmul       st3 };
                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                            asm { fadd       st2 };
                                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                                            eax = sub_47b5c0();
                                                                                    }
                                                                                    else {
                                                                                            eax = eax + 0x1;
                                                                                    }
                                                                            }
                                                                            arg_74 = eax;
                                                                            esi = esi + 0x1;
                                                                            ebx = ebx + 0x400;
                                                                            if (esi < arg_8c) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    esi = esi + 0x1;
                                                                    ebx = ebx + 0x400;
                                                                    if (esi < arg_8c) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (ecx > edi) {
                                                                    arg_54 = ecx - edi;
                                                                    asm { fild       dword [esp-0x28+88] };
                                                                    asm { fmul       st3 };
                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                    asm { fadd       st2 };
                                                                    asm { fiadd      dword [esp-0x28+112] };
                                                                    eax = sub_47b5c0();
                                                            }
                                                            else {
                                                                    if (arg_8 >= edi) {
                                                                            arg_54 = arg_8 - edi;
                                                                            asm { fild       dword [esp-0x28+88] };
                                                                            asm { fmul       st3 };
                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                            asm { fadd       st2 };
                                                                            asm { fiadd      dword [esp-0x28+112] };
                                                                            eax = sub_47b5c0();
                                                                    }
                                                                    else {
                                                                            eax = eax + 0x1;
                                                                    }
                                                            }
                                                            arg_74 = eax;
                                                            esi = esi + 0x1;
                                                            ebx = ebx + 0x400;
                                                            if (esi < arg_8c) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    if (eax > 0x0) {
                                            arg_5c = arg_8 - *(&arg_2c + arg_48 + 0x6f0);
                                            asm { fild       dword [esp-0x30+96] };
                                            asm { fmul       st4 };
                                            asm { fidiv      dword [ebp+0xc] };
                                            asm { fiadd      dword [esp-0x30+120] };
                                            eax = sub_47b5c0();
                                            *(&arg_2c + arg_3c * 0x4 + 0xd8) = *(&arg_2c + arg_3c * 0x4 + 0xd8) - eax;
                                            *(&arg_2c + arg_3c * 0x4 + 0x80) = *(&arg_2c + arg_3c * 0x4 + 0x80) - eax;
                                    }
                                    arg_7c = arg_7c + 0x15;
                                    arg_38 = arg_38 + 0x800;
                                    arg_48 = arg_48 + 0x400;
                                    bool_730 = arg_3c + 0x1 < arg_8c;
                                    arg_3c = arg_3c + 0x1;
                            } while (bool_730);
                    }
                    arg_64 = arg_64 + 0x24;
                    bool_721 = arg_54 + 0x1 < arg_44;
                    arg_54 = arg_54 + 0x1;
                    if (!bool_721) {
                            break;
                    }
                    edx = arg_8c;
            }
            asm { fstp       st2 };
            asm { fstp       st0 };
            asm { fstp       st2 };
    }
    eax = *dword_baed80;
    asm { fstp       st1 };
    edi = *eax;
    asm { fstp       st0 };
    esi = 0xbaed7c;
    arg_4c = 0xbaed7c;
    arg_50 = edi;
    goto loc_43c6a0;

loc_43c0c3:
    arg_10 = arg_0 + 0x3;
    goto loc_43c0ce;

loc_43c6a0:
    ebx = arg_4;
    arg_90 = *dword_baed80;
    if (esi == 0x0 || esi != 0xbaed7c) {
            sub_47a948();
    }
    if (edi == arg_90) goto loc_43cf04;
    goto loc_43c6c8;

loc_43c0ce:
    edx = *(int8_t *)arg_10;
    if (edx == 0x0) {
            ecx = *(&decomp_var_8 + (arg_4 << 0x8) + arg_1c + (arg_4 << 0x8) + arg_1c + (arg_4 << 0x8) + arg_1c + (arg_4 << 0x8) + arg_1c + 0xaef0);
            eax = *((arg_4 << 0x8) + arg_1c + (arg_4 << 0x8) + arg_1c + (arg_4 << 0x8) + arg_1c + (arg_4 << 0x8) + arg_1c + 0xb9a980);
            if (ecx > 0x0 && eax > 0x0) {
                    if (eax - ecx >= arg_8) {
                            arg_30 = arg_30 + 0x14;
                    }
                    else {
                            if (eax + eax > ecx + ecx * 0x2) {
                                    arg_30 = arg_30 + 0xa;
                            }
                            else {
                                    bool_845 = eax == ecx;
                                    if (eax > ecx) {
                                            arg_30 = arg_30 + 0x5;
                                    }
                                    else {
                                            if (!bool_845) {
                                                    arg_30 = arg_30 - 0xa;
                                            }
                                    }
                            }
                    }
            }
    }
    if (edx != 0x1) goto loc_43c427;
    goto loc_43c137;

loc_43cf04:
    edi = arg_40[0x2];
    esi = *edi[0x915];
    edi = edi + 0x2450;
    goto loc_43cf21;

loc_43c6c8:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    ecx = edi[0x3];
    eax = *(arg_40[0x2] + 0x2404);
    arg_94 = ecx;
    arg_3c = 0x0;
    if (eax <= 0x0) {
            sub_40f380();
            edi = arg_58;
            esi = arg_54;
            continue;
    }
    arg_48 = ecx + ecx * 0x8 + ecx + ecx * 0x8 + ecx + ecx * 0x8 + ecx + ecx * 0x8;
    goto loc_43c720;

loc_43c427:
    arg_38 = arg_38 + 0x24;
    bool_844 = arg_44 + 0x1 < esi;
    arg_44 = arg_44 + 0x1;
    if (bool_844) {
            continue;
    }
    break;

loc_43c137:
    eax = arg_8[0x901];
    arg_5c = eax;
    if (eax <= 0x0) goto loc_43c427;
    goto loc_43c14f;

loc_43cf21:
    eax = arg_40[0x2];
    ecx = eax[0x915];
    eax = eax + 0x2450;
    arg_a4 = ecx;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    eax = arg_40[0x2];
    if (esi != arg_a4) {
            if (eax[0x901] <= 0x0) {
                    sub_401390();
                    esi = arg_78;
                    edi = arg_74;
                    ebx = arg_4;
                    continue;
            }
            ebx = 0x0;
            arg_38 = 0x0;
            while (true) {
                    if (edi == 0x0) {
                            sub_47a948();
                    }
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x6] == ebx) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            eax = esi[0x3];
                            eax = eax + arg_38;
                            bool_460 = *(eax * 0x8 + 0x535cec) > 0x0;
                            if (*(eax * 0x8 + 0x535cec) >= 0x0) {
                                    if (!bool_460) {
                                            if (*(eax * 0x8 + 0x535ce8) > 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    eax = *((esi[0x3] + arg_38) * 0x4 + 0xb8ff68);
                                                    *(&arg_2c + ebx * 0x4 + 0xd8) = *(&arg_2c + ebx * 0x4 + 0xd8) - eax;
                                                    *(&arg_2c + ebx * 0x4 + 0x80) = *(&arg_2c + ebx * 0x4 + 0x80) - eax;
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    eax = esi[0x3];
                                                    if (*(int8_t *)(arg_40[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) != 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            eax = esi[0x3];
                                                            eax = *(int16_t *)(arg_40[0x2] + (eax + eax * 0x8) * 0x4 + 0x20);
                                                            bool_411 = HIBYTE(eax) == 0x41;
                                                            eax = eax & 0xff;
                                                            if (!bool_411) {
                                                                    eax = 0x14;
                                                            }
                                                            if (eax == ebx) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    if (esi[0x8] != 0x2) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            if (esi[0x8] == 0x6) {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                            if (esi == edi[0x1]) {
                                                                                                    sub_47a948();
                                                                                            }
                                                                                    }
                                                                                    esp = esp - 0x4;
                                                                                    asm { fild       dword [eax+ebx*4] };
                                                                                    esp = esp - 0x4;
                                                                                    arg_28 = esi + 0x10;
                                                                                    asm { fstp       qword [esp-0x2c+152] };
                                                                                    eax = sub_41c270(arg_28);
                                                                                    asm { fild       dword [eax+ebx*4] };
                                                                                    asm { fmul       qword [qword_value_4605831338911806259] };
                                                                                    asm { fcomp      qword [esp-0x30+152] };
                                                                                    asm { fnstsw     ax };
                                                                                    if (!PARITY(HIBYTE(eax) & 0x5) && *(int8_t *)byte_baed68 == 0x0) {
                                                                                            if (esi == edi[0x1]) {
                                                                                                    sub_47a948();
                                                                                                    if (esi == edi[0x1]) {
                                                                                                            sub_47a948();
                                                                                                    }
                                                                                            }
                                                                                            ecx = esi[0x3];
                                                                                            *(&arg_2c + ebx * 0x4 + 0x80) = (arg_8 - *(&arg_2c + ecx * 0x4 + 0x2f0)) * *((ecx + arg_38) * 0x4 + 0xb8ff68) / arg_8 + *(&arg_2c + ebx * 0x4 + 0x80);
                                                                                    }
                                                                                    arg_40 = arg_40 + 0x100;
                                                                                    ebx = ebx + 0x1;
                                                                                    if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    arg_40 = arg_40 + 0x100;
                                                                                    ebx = ebx + 0x1;
                                                                                    if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                            }
                                                                            esp = esp - 0x4;
                                                                            asm { fild       dword [eax+ebx*4] };
                                                                            esp = esp - 0x4;
                                                                            arg_28 = esi + 0x10;
                                                                            asm { fstp       qword [esp-0x2c+152] };
                                                                            eax = sub_41c270(arg_28);
                                                                            asm { fild       dword [eax+ebx*4] };
                                                                            asm { fmul       qword [qword_value_4605831338911806259] };
                                                                            asm { fcomp      qword [esp-0x30+152] };
                                                                            asm { fnstsw     ax };
                                                                            if (!PARITY(HIBYTE(eax) & 0x5) && *(int8_t *)byte_baed68 == 0x0) {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                            if (esi == edi[0x1]) {
                                                                                                    sub_47a948();
                                                                                            }
                                                                                    }
                                                                                    ecx = esi[0x3];
                                                                                    *(&arg_2c + ebx * 0x4 + 0x80) = (arg_8 - *(&arg_2c + ecx * 0x4 + 0x2f0)) * *((ecx + arg_38) * 0x4 + 0xb8ff68) / arg_8 + *(&arg_2c + ebx * 0x4 + 0x80);
                                                                            }
                                                                            arg_40 = arg_40 + 0x100;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    arg_40 = arg_40 + 0x100;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            if (esi[0x8] != 0x2) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    if (esi[0x8] == 0x6) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                            }
                                                                            esp = esp - 0x4;
                                                                            asm { fild       dword [eax+ebx*4] };
                                                                            esp = esp - 0x4;
                                                                            arg_28 = esi + 0x10;
                                                                            asm { fstp       qword [esp-0x2c+152] };
                                                                            eax = sub_41c270(arg_28);
                                                                            asm { fild       dword [eax+ebx*4] };
                                                                            asm { fmul       qword [qword_value_4605831338911806259] };
                                                                            asm { fcomp      qword [esp-0x30+152] };
                                                                            asm { fnstsw     ax };
                                                                            if (!PARITY(HIBYTE(eax) & 0x5) && *(int8_t *)byte_baed68 == 0x0) {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                            if (esi == edi[0x1]) {
                                                                                                    sub_47a948();
                                                                                            }
                                                                                    }
                                                                                    ecx = esi[0x3];
                                                                                    *(&arg_2c + ebx * 0x4 + 0x80) = (arg_8 - *(&arg_2c + ecx * 0x4 + 0x2f0)) * *((ecx + arg_38) * 0x4 + 0xb8ff68) / arg_8 + *(&arg_2c + ebx * 0x4 + 0x80);
                                                                            }
                                                                            arg_40 = arg_40 + 0x100;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            arg_40 = arg_40 + 0x100;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                    }
                                                                    esp = esp - 0x4;
                                                                    asm { fild       dword [eax+ebx*4] };
                                                                    esp = esp - 0x4;
                                                                    arg_28 = esi + 0x10;
                                                                    asm { fstp       qword [esp-0x2c+152] };
                                                                    eax = sub_41c270(arg_28);
                                                                    asm { fild       dword [eax+ebx*4] };
                                                                    asm { fmul       qword [qword_value_4605831338911806259] };
                                                                    asm { fcomp      qword [esp-0x30+152] };
                                                                    asm { fnstsw     ax };
                                                                    if (!PARITY(HIBYTE(eax) & 0x5) && *(int8_t *)byte_baed68 == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                            }
                                                                            ecx = esi[0x3];
                                                                            *(&arg_2c + ebx * 0x4 + 0x80) = (arg_8 - *(&arg_2c + ecx * 0x4 + 0x2f0)) * *((ecx + arg_38) * 0x4 + 0xb8ff68) / arg_8 + *(&arg_2c + ebx * 0x4 + 0x80);
                                                                    }
                                                                    arg_40 = arg_40 + 0x100;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    arg_40 = arg_40 + 0x100;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            eax = *((esi[0x3] + arg_38) * 0x4 + 0xb8ff68);
                                            *(&arg_2c + ebx * 0x4 + 0xd8) = *(&arg_2c + ebx * 0x4 + 0xd8) - eax;
                                            *(&arg_2c + ebx * 0x4 + 0x80) = *(&arg_2c + ebx * 0x4 + 0x80) - eax;
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            eax = esi[0x3];
                                            if (*(int8_t *)(arg_40[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) != 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    eax = esi[0x3];
                                                    eax = *(int16_t *)(arg_40[0x2] + (eax + eax * 0x8) * 0x4 + 0x20);
                                                    bool_428 = HIBYTE(eax) == 0x41;
                                                    eax = eax & 0xff;
                                                    if (!bool_428) {
                                                            eax = 0x14;
                                                    }
                                                    if (eax == ebx) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            if (esi[0x8] != 0x2) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    if (esi[0x8] == 0x6) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                            }
                                                                            esp = esp - 0x4;
                                                                            asm { fild       dword [eax+ebx*4] };
                                                                            esp = esp - 0x4;
                                                                            arg_28 = esi + 0x10;
                                                                            asm { fstp       qword [esp-0x2c+152] };
                                                                            eax = sub_41c270(arg_28);
                                                                            asm { fild       dword [eax+ebx*4] };
                                                                            asm { fmul       qword [qword_value_4605831338911806259] };
                                                                            asm { fcomp      qword [esp-0x30+152] };
                                                                            asm { fnstsw     ax };
                                                                            if (!PARITY(HIBYTE(eax) & 0x5) && *(int8_t *)byte_baed68 == 0x0) {
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                            if (esi == edi[0x1]) {
                                                                                                    sub_47a948();
                                                                                            }
                                                                                    }
                                                                                    ecx = esi[0x3];
                                                                                    *(&arg_2c + ebx * 0x4 + 0x80) = (arg_8 - *(&arg_2c + ecx * 0x4 + 0x2f0)) * *((ecx + arg_38) * 0x4 + 0xb8ff68) / arg_8 + *(&arg_2c + ebx * 0x4 + 0x80);
                                                                            }
                                                                            arg_40 = arg_40 + 0x100;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            arg_40 = arg_40 + 0x100;
                                                                            ebx = ebx + 0x1;
                                                                            if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                    }
                                                                    esp = esp - 0x4;
                                                                    asm { fild       dword [eax+ebx*4] };
                                                                    esp = esp - 0x4;
                                                                    arg_28 = esi + 0x10;
                                                                    asm { fstp       qword [esp-0x2c+152] };
                                                                    eax = sub_41c270(arg_28);
                                                                    asm { fild       dword [eax+ebx*4] };
                                                                    asm { fmul       qword [qword_value_4605831338911806259] };
                                                                    asm { fcomp      qword [esp-0x30+152] };
                                                                    asm { fnstsw     ax };
                                                                    if (!PARITY(HIBYTE(eax) & 0x5) && *(int8_t *)byte_baed68 == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                            }
                                                                            ecx = esi[0x3];
                                                                            *(&arg_2c + ebx * 0x4 + 0x80) = (arg_8 - *(&arg_2c + ecx * 0x4 + 0x2f0)) * *((ecx + arg_38) * 0x4 + 0xb8ff68) / arg_8 + *(&arg_2c + ebx * 0x4 + 0x80);
                                                                    }
                                                                    arg_40 = arg_40 + 0x100;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            arg_40 = arg_40 + 0x100;
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    if (esi[0x8] != 0x2) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            if (esi[0x8] == 0x6) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                    }
                                                                    esp = esp - 0x4;
                                                                    asm { fild       dword [eax+ebx*4] };
                                                                    esp = esp - 0x4;
                                                                    arg_28 = esi + 0x10;
                                                                    asm { fstp       qword [esp-0x2c+152] };
                                                                    eax = sub_41c270(arg_28);
                                                                    asm { fild       dword [eax+ebx*4] };
                                                                    asm { fmul       qword [qword_value_4605831338911806259] };
                                                                    asm { fcomp      qword [esp-0x30+152] };
                                                                    asm { fnstsw     ax };
                                                                    if (!PARITY(HIBYTE(eax) & 0x5) && *(int8_t *)byte_baed68 == 0x0) {
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                                    if (esi == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                            }
                                                                            ecx = esi[0x3];
                                                                            *(&arg_2c + ebx * 0x4 + 0x80) = (arg_8 - *(&arg_2c + ecx * 0x4 + 0x2f0)) * *((ecx + arg_38) * 0x4 + 0xb8ff68) / arg_8 + *(&arg_2c + ebx * 0x4 + 0x80);
                                                                    }
                                                                    arg_40 = arg_40 + 0x100;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    arg_40 = arg_40 + 0x100;
                                                                    ebx = ebx + 0x1;
                                                                    if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                            }
                                                            esp = esp - 0x4;
                                                            asm { fild       dword [eax+ebx*4] };
                                                            esp = esp - 0x4;
                                                            arg_28 = esi + 0x10;
                                                            asm { fstp       qword [esp-0x2c+152] };
                                                            eax = sub_41c270(arg_28);
                                                            asm { fild       dword [eax+ebx*4] };
                                                            asm { fmul       qword [qword_value_4605831338911806259] };
                                                            asm { fcomp      qword [esp-0x30+152] };
                                                            asm { fnstsw     ax };
                                                            if (!PARITY(HIBYTE(eax) & 0x5) && *(int8_t *)byte_baed68 == 0x0) {
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                            if (esi == edi[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                    }
                                                                    ecx = esi[0x3];
                                                                    *(&arg_2c + ebx * 0x4 + 0x80) = (arg_8 - *(&arg_2c + ecx * 0x4 + 0x2f0)) * *((ecx + arg_38) * 0x4 + 0xb8ff68) / arg_8 + *(&arg_2c + ebx * 0x4 + 0x80);
                                                            }
                                                            arg_40 = arg_40 + 0x100;
                                                            ebx = ebx + 0x1;
                                                            if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                            }
                            else {
                                    arg_40 = arg_40 + 0x100;
                                    ebx = ebx + 0x1;
                                    if (ebx < *(arg_48[0x2] + 0x2404)) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            eax = esi[0x3];
                            eax = eax + arg_38;
                            bool_499 = *(eax * 0x8 + 0x58f8ec) < 0x0;
                            bool_464 = *(eax * 0x8 + 0x58f8ec) > 0x0;
                            if (!bool_499) {
                                    if (!bool_464) {
                                            if (*(eax * 0x8 + 0x58f8e8) > 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    *(&arg_2c + ebx * 0x4 + 0x80) = *(&arg_2c + ebx * 0x4 + 0x80) + *((esi[0x3] + arg_38) * 0x4 + 0xb8ff68);
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    eax = esi[0x3];
                                                    if ((*((eax + arg_38) * 0x8 + 0x5164e8) | *((eax + arg_38) * 0x8 + 0x5164ec)) == 0x0) {
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                                    if (esi == edi[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                            }
                                                            ecx = esi[0x3];
                                                            eax = arg_8 - *(&arg_2c + ecx * 0x4 + 0x2f0);
                                                            eax = eax * *((ecx + arg_38) * 0x4 + 0xb8ff68);
                                                            *(&arg_2c + ebx * 0x4 + 0xd8) = *(&arg_2c + ebx * 0x4 + 0xd8) - eax / arg_8;
                                                            *(&arg_2c + ebx * 0x4 + 0x80) = *(&arg_2c + ebx * 0x4 + 0x80) - eax / arg_8;
                                                    }
                                                    arg_40 = arg_40 + 0x100;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    arg_40 = arg_40 + 0x100;
                                                    ebx = ebx + 0x1;
                                                    if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            *(&arg_2c + ebx * 0x4 + 0x80) = *(&arg_2c + ebx * 0x4 + 0x80) + *((esi[0x3] + arg_38) * 0x4 + 0xb8ff68);
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            eax = esi[0x3];
                                            if ((*((eax + arg_38) * 0x8 + 0x5164e8) | *((eax + arg_38) * 0x8 + 0x5164ec)) == 0x0) {
                                                    if (esi == edi[0x1]) {
                                                            sub_47a948();
                                                            if (esi == edi[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                    }
                                                    ecx = esi[0x3];
                                                    eax = arg_8 - *(&arg_2c + ecx * 0x4 + 0x2f0);
                                                    eax = eax * *((ecx + arg_38) * 0x4 + 0xb8ff68);
                                                    *(&arg_2c + ebx * 0x4 + 0xd8) = *(&arg_2c + ebx * 0x4 + 0xd8) - eax / arg_8;
                                                    *(&arg_2c + ebx * 0x4 + 0x80) = *(&arg_2c + ebx * 0x4 + 0x80) - eax / arg_8;
                                            }
                                            arg_40 = arg_40 + 0x100;
                                            ebx = ebx + 0x1;
                                            if (ebx < *(arg_48[0x2] + 0x2404)) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    arg_40 = arg_40 + 0x100;
                                    ebx = ebx + 0x1;
                                    if (ebx < *(arg_48[0x2] + 0x2404)) {
                                            continue;
                                    }
                                    break;
                            }
                    }
            }
            sub_401390();
            esi = arg_78;
            edi = arg_74;
            ebx = arg_4;
            continue;
    }
    break;

loc_43c720:
    arg_4c = 0x0;
    if (eax > 0x0) {
            arg_40 = edi + 0x68;
            sub_43c740(arg_34, arg_38, arg_3c, arg_40, arg_44, arg_48, arg_4c, arg_50);
    }
    if (*(int8_t *)(arg_50 + arg_48[0x2] + 0x4) != 0x0) goto loc_43cece;
    goto loc_43cba2;

loc_43c14f:
    ecx = 0x0;
    edx = *(int16_t *)(arg_18 + 0x1d);
    arg_c = edx >> 0x8;
    ebx = arg_24 * 0x4;
    eax = arg_24 * 0x8;
    arg_34 = 0x0;
    arg_4c = ebx;
    arg_44 = eax;
    goto loc_43c18f;
    asm { fld        dword [byte_4c6bdc+4] };
    esi = 0x0;
    arg_3c = 0x0;
    arg_38 = eax;
    if (eax[0x901] <= 0x0) goto .l163;
    goto loc_43d1f0;

loc_43cece:
    eax = arg_48[0x2];
    eax = eax[0x901];
    bool_362 = arg_44 + 0x1 < eax;
    arg_44 = arg_44 + 0x1;
    if (bool_362) {
            continue;
    }
    temp_10 = 0x1;
    break;

loc_43cba2:
    if (edi == arg_54[0x1]) {
            sub_47a948();
    }
    if (*(edi + arg_44 * 0x4 + 0x68) <= 0x0) goto loc_43cece;
    goto loc_43cbbf;

loc_43c18f:
    edi = edx & 0xff;
    if (arg_14 != 0x41) {
            edi = 0x14;
    }
    edx = *(&arg_4 + ebx + 0xaef0);
    if (edi != ecx) {
            esi = ebx[0x2e6a60];
            if (esi > 0x0) {
                    eax = ebx[0x2e5560];
                    if (esi >= eax) {
                            esi = esi + eax;
                    }
                    else {
                            esi = esi + esi;
                    }
                    if (esi > 0x0) {
                            if (esi >= edx) {
                                    eax = arg_44 + edi;
                                    bool_893 = *(eax * 0x8 + 0x4d552c) > 0x0;
                                    bool_861 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                    if (!bool_893) {
                                            if (!bool_861) {
                                                    if (*(eax * 0x8 + 0x4d5528) < 0x2) {
                                                            edi = *(&arg_c + ebx + 0x6f0);
                                                            if (edi > 0x0) {
                                                                    if (edx != 0x0) {
                                                                            eax = esi - edx;
                                                                            if (eax >= arg_8) {
                                                                                    *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + arg_8;
                                                                            }
                                                                            else {
                                                                                    if (edx == 0x0) {
                                                                                            *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + esi;
                                                                                    }
                                                                                    else {
                                                                                            if (*(&arg_c + arg_34 + arg_34 + arg_34 + arg_34 + 0x2f0) == 0x0) {
                                                                                                    eax = eax + arg_8;
                                                                                                    eax = SAR(eax + ((eax & 0x80000000 ? 0xffffffff : 0x0) & 0x3), 0x2);
                                                                                                    *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + eax;
                                                                                            }
                                                                                            else {
                                                                                                    if (edi > 0x0) {
                                                                                                            *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + edi;
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = SAR(eax + ((eax & 0x80000000 ? 0xffffffff : 0x0) & 0x3), 0x2);
                                                                                                            *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + eax;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    eax = esi - edx;
                                                                    if (eax >= arg_8) {
                                                                            *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + arg_8;
                                                                    }
                                                                    else {
                                                                            if (edx == 0x0) {
                                                                                    *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + esi;
                                                                            }
                                                                            else {
                                                                                    if (*(&arg_c + arg_34 + arg_34 + arg_34 + arg_34 + 0x2f0) == 0x0) {
                                                                                            eax = eax + arg_8;
                                                                                            eax = SAR(eax + ((eax & 0x80000000 ? 0xffffffff : 0x0) & 0x3), 0x2);
                                                                                            *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + eax;
                                                                                    }
                                                                                    else {
                                                                                            if (edi > 0x0) {
                                                                                                    *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + edi;
                                                                                            }
                                                                                            else {
                                                                                                    eax = SAR(eax + ((eax & 0x80000000 ? 0xffffffff : 0x0) & 0x3), 0x2);
                                                                                                    *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + eax;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            if (edi == 0x0) {
                                                                    eax = arg_5c;
                                                                    if ((eax[0x15ea3a] | eax[0x15ea3b]) == 0x0) {
                                                                            eax = *(int16_t *)word_4c6cc4;
                                                                            if (*(int16_t *)word_4c6cc4 == arg_20[0x1225] && esi >= arg_8) {
                                                                                    eax = arg_5c;
                                                                                    bool_906 = eax[0x15c03b] < edi;
                                                                                    bool_855 = eax[0x15c03b] > edi;
                                                                                    if (!bool_906) {
                                                                                            if (bool_855 || eax[0x15c03a] > edi) {
                                                                                                    eax = arg_5c;
                                                                                                    *(&arg_14 + ecx * 0x4 + 0x298) = *(&arg_14 + ecx * 0x4 + 0x298) + (eax[0x156c3a] - eax[0x15c03a]);
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            arg_64 = arg_64 + 0x800;
                                                            arg_54 = arg_54 + 0x15;
                                                            ecx = ecx + 0x1;
                                                            ebx = ebx + 0x400;
                                                            if (ecx < arg_7c) {
                                                                    edx = arg_76;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            arg_64 = arg_64 + 0x800;
                                                            arg_54 = arg_54 + 0x15;
                                                            ecx = ecx + 0x1;
                                                            ebx = ebx + 0x400;
                                                            if (ecx < arg_7c) {
                                                                    edx = arg_76;
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    edi = *(&arg_c + ebx + 0x6f0);
                                                    if (edi > 0x0) {
                                                            if (edx != 0x0) {
                                                                    eax = esi - edx;
                                                                    if (eax >= arg_8) {
                                                                            *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + arg_8;
                                                                    }
                                                                    else {
                                                                            if (edx == 0x0) {
                                                                                    *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + esi;
                                                                            }
                                                                            else {
                                                                                    if (*(&arg_c + arg_34 + arg_34 + arg_34 + arg_34 + 0x2f0) == 0x0) {
                                                                                            eax = eax + arg_8;
                                                                                            eax = SAR(eax + ((eax & 0x80000000 ? 0xffffffff : 0x0) & 0x3), 0x2);
                                                                                            *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + eax;
                                                                                    }
                                                                                    else {
                                                                                            if (edi > 0x0) {
                                                                                                    *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + edi;
                                                                                            }
                                                                                            else {
                                                                                                    eax = SAR(eax + ((eax & 0x80000000 ? 0xffffffff : 0x0) & 0x3), 0x2);
                                                                                                    *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + eax;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            eax = esi - edx;
                                                            if (eax >= arg_8) {
                                                                    *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + arg_8;
                                                            }
                                                            else {
                                                                    if (edx == 0x0) {
                                                                            *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + esi;
                                                                    }
                                                                    else {
                                                                            if (*(&arg_c + arg_34 + arg_34 + arg_34 + arg_34 + 0x2f0) == 0x0) {
                                                                                    eax = eax + arg_8;
                                                                                    eax = SAR(eax + ((eax & 0x80000000 ? 0xffffffff : 0x0) & 0x3), 0x2);
                                                                                    *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + eax;
                                                                            }
                                                                            else {
                                                                                    if (edi > 0x0) {
                                                                                            *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + edi;
                                                                                    }
                                                                                    else {
                                                                                            eax = SAR(eax + ((eax & 0x80000000 ? 0xffffffff : 0x0) & 0x3), 0x2);
                                                                                            *(&arg_c + ecx * 0x4 + 0x190) = *(&arg_c + ecx * 0x4 + 0x190) + eax;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    if (edi == 0x0) {
                                                            eax = arg_5c;
                                                            if ((eax[0x15ea3a] | eax[0x15ea3b]) == 0x0) {
                                                                    eax = *(int16_t *)word_4c6cc4;
                                                                    if (*(int16_t *)word_4c6cc4 == arg_20[0x1225] && esi >= arg_8) {
                                                                            eax = arg_5c;
                                                                            bool_904 = eax[0x15c03b] > edi;
                                                                            if (eax[0x15c03b] >= edi) {
                                                                                    if (bool_904 || eax[0x15c03a] > edi) {
                                                                                            eax = arg_5c;
                                                                                            *(&arg_14 + ecx * 0x4 + 0x298) = *(&arg_14 + ecx * 0x4 + 0x298) + (eax[0x156c3a] - eax[0x15c03a]);
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    arg_64 = arg_64 + 0x800;
                                                    arg_54 = arg_54 + 0x15;
                                                    ecx = ecx + 0x1;
                                                    ebx = ebx + 0x400;
                                                    if (ecx < arg_7c) {
                                                            edx = arg_76;
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            arg_64 = arg_64 + 0x800;
                                            arg_54 = arg_54 + 0x15;
                                            ecx = ecx + 0x1;
                                            ebx = ebx + 0x400;
                                            if (ecx < arg_7c) {
                                                    edx = arg_76;
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    if (*(&arg_c + ebx + 0x6f0) > 0x0) {
                                            eax = edx;
                                            edx = arg_8;
                                            eax = eax - esi;
                                            if (eax >= edx) {
                                                    *(&arg_c + ecx * 0x4 + 0x130) = *(&arg_c + ecx * 0x4 + 0x130) - edx;
                                            }
                                            else {
                                                    eax = SAR(eax + ((eax & 0x80000000 ? 0xffffffff : 0x0) & 0x3), 0x2);
                                                    eax = -eax;
                                                    *(&arg_14 + ecx * 0x4 + 0x130) = *(&arg_14 + ecx * 0x4 + 0x130) + eax;
                                            }
                                    }
                                    arg_64 = arg_64 + 0x800;
                                    arg_54 = arg_54 + 0x15;
                                    ecx = ecx + 0x1;
                                    ebx = ebx + 0x400;
                                    if (ecx < arg_7c) {
                                            edx = arg_76;
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            arg_64 = arg_64 + 0x800;
                            arg_54 = arg_54 + 0x15;
                            ecx = ecx + 0x1;
                            ebx = ebx + 0x400;
                            if (ecx < arg_7c) {
                                    edx = arg_76;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    arg_64 = arg_64 + 0x800;
                    arg_54 = arg_54 + 0x15;
                    ecx = ecx + 0x1;
                    ebx = ebx + 0x400;
                    if (ecx < arg_7c) {
                            edx = arg_76;
                            continue;
                    }
                    break;
            }
    }
    else {
            esi = ebx[0x2e5560];
            asm { fcom       st1 };
            esi = esi + ebx[0x2e6a60];
            asm { fnstsw     ax };
            if ((HIBYTE(eax) & 0x41) == 0x0) {
                    eax = 0x0;
                    edi = arg_2c + arg_2c + arg_2c + arg_2c + 0xb9a980;
                    do {
                            if (eax != ecx && *((arg_3c + eax) * 0x4 + 0x634e90) > 0x23) {
                                    esi = esi + *edi;
                            }
                            eax = eax + 0x1;
                            edi = edi + 0x400;
                    } while (eax < arg_64);
                    ebx = arg_54;
            }
            edi = arg_8;
            if (edx > 0x0) {
                    if (edx >= esi) {
                            eax = edx - esi;
                            if (eax >= edi) {
                                    *(&arg_4 + ecx * 0x4 + 0x130) = *(&arg_4 + ecx * 0x4 + 0x130) - edi;
                                    arg_64 = arg_64 + 0x800;
                                    arg_54 = arg_54 + 0x15;
                                    ecx = ecx + 0x1;
                                    ebx = ebx + 0x400;
                                    if (ecx < arg_7c) {
                                            edx = arg_76;
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (esi == 0x0) {
                                            *(&arg_4 + ecx * 0x4 + 0x130) = *(&arg_4 + ecx * 0x4 + 0x130) - edx;
                                            arg_64 = arg_64 + 0x800;
                                            arg_54 = arg_54 + 0x15;
                                            ecx = ecx + 0x1;
                                            ebx = ebx + 0x400;
                                            if (ecx < arg_7c) {
                                                    edx = arg_76;
                                                    continue;
                                            }
                                            break;
                                    }
                                    else {
                                            ebx = arg_54;
                                            if (*(&arg_4 + arg_2c + arg_2c + arg_2c + arg_2c + 0x2f0) == 0x0) {
                                                    eax = SAR(eax + edi + 0x1 + ((eax + edi + 0x1 & 0x80000000 ? 0xffffffff : 0x0) & 0x7), 0x3);
                                            }
                                            else {
                                                    if (edx != esi) {
                                                            eax = SAR(eax + ((eax & 0x80000000 ? 0xffffffff : 0x0) & 0x3), 0x2);
                                                    }
                                                    else {
                                                            eax = SAR(edi + ((edi & 0x80000000 ? 0xffffffff : 0x0) & 0xf), 0x4);
                                                    }
                                            }
                                            eax = -eax;
                                            *(&arg_14 + ecx * 0x4 + 0x130) = *(&arg_14 + ecx * 0x4 + 0x130) + eax;
                                            arg_64 = arg_64 + 0x800;
                                            arg_54 = arg_54 + 0x15;
                                            ecx = ecx + 0x1;
                                            ebx = ebx + 0x400;
                                            if (ecx < arg_7c) {
                                                    edx = arg_76;
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                    }
                    else {
                            if (esi < edx + edx) {
                                    if (*(&arg_4 + arg_2c + arg_2c + arg_2c + arg_2c + 0x2f0) == 0x0) {
                                            eax = SAR((edx - esi) + edi + 0x1 + (((edx - esi) + edi + 0x1 & 0x80000000 ? 0xffffffff : 0x0) & 0x7), 0x3);
                                    }
                                    else {
                                            eax = SAR(edi + ((edi & 0x80000000 ? 0xffffffff : 0x0) & 0xf), 0x4);
                                    }
                            }
                            else {
                                    eax = SAR(edi + ((edi & 0x80000000 ? 0xffffffff : 0x0) & 0xf), 0x4);
                            }
                            eax = -eax;
                            *(&arg_14 + ecx * 0x4 + 0x130) = *(&arg_14 + ecx * 0x4 + 0x130) + eax;
                            arg_64 = arg_64 + 0x800;
                            arg_54 = arg_54 + 0x15;
                            ecx = ecx + 0x1;
                            ebx = ebx + 0x400;
                            if (ecx < arg_7c) {
                                    edx = arg_76;
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    arg_64 = arg_64 + 0x800;
                    arg_54 = arg_54 + 0x15;
                    ecx = ecx + 0x1;
                    ebx = ebx + 0x400;
                    if (ecx < arg_7c) {
                            edx = arg_76;
                            continue;
                    }
                    break;
            }
    }
    goto .l5;

.l163:
    temp_11 = 0x1;
    goto .l164;

loc_43d1f0:
    if (eax[0x900] <= 0x0) goto loc_43d4b6;
    goto loc_43d1fe;
    if (temp_10 != 0x0) {
            sub_40f380();
            edi = arg_58;
            esi = arg_54;
            continue;
    }
    temp_11 = 0x0;
    break;

loc_43cbbf:
    esp = esp - 0x4;
    esi = arg_54;
    arg_6c = sub_4075b0(word_4c6c0c, arg_34);
    if (edi == esi[0x1]) {
            sub_47a948();
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
    }
    arg_4c = (*(edi + arg_44 * 0x4 + 0x14) + 0x32) * *(edi + arg_44 * 0x4 + 0x68) / arg_8;
    eax = arg_6c;
    esi = *eax[0x1];
    ebx = eax;
    goto loc_43cc20;

.l5:
    esi = arg_34;
    goto loc_43c427;

.l164:
    break;

loc_43d4b6:
    eax = arg_50[0x2];
    ecx = eax[0x1225] & 0xffff;
    if (*(int16_t *)word_4c6cc4 == ecx) {
            asm { fld        qword [qword_value_4636737291354636288] };
            asm { fmul       st1 };
            asm { fild       dword [ebp+0xc] };
            asm { fstp       dword [esp-0x40+88] };
            asm { fild       dword [esp+esi*4-0x40+552] };
            asm { fmul       st1 };
            asm { fld        dword [esp-0x40+88] };
            asm { fld        st0 };
            asm { fdivp      st2 };
            asm { fxch       st0, st1 };
            eax = sub_47b5c0();
            *(&arg_3c + esi * 0x4 + 0x80) = *(&arg_3c + esi * 0x4 + 0x80) + eax;
            arg_54 = *(&arg_3c + esi * 0x4 + 0x80);
            if (eax < 0x0) {
                    *(&arg_3c + esi * 0x4 + 0xd8) = *(&arg_3c + esi * 0x4 + 0xd8) + eax;
            }
            asm { fild       dword [esp+esi*4-0x40+464] };
            asm { fmul       st2 };
            asm { fdiv       st1 };
            asm { fiadd      dword [esp-0x40+88] };
            eax = sub_47b5c0();
            asm { fild       dword [esp+esi*4-0x40+368] };
            *(&arg_3c + esi * 0x4 + 0x80) = eax;
            asm { fmulp      st2 };
            asm { fdivp      st1 };
            eax = sub_47b5c0();
            *(&arg_3c + esi * 0x4 + 0x80) = *(&arg_3c + esi * 0x4 + 0x80) + eax;
            *(&arg_3c + esi * 0x4 + 0xd8) = *(&arg_3c + esi * 0x4 + 0xd8) - eax;
            eax = arg_50;
    }
    else {
            if (*(int16_t *)word_4c6ccc == ecx) {
                    asm { fild       dword [ebp+0xc] };
                    asm { fstp       dword [esp-0x40+88] };
                    asm { fild       dword [esp+esi*4-0x40+552] };
                    asm { fld        st1 };
                    asm { fmul       qword [qword_value_4643985272004935680] };
                    asm { fmulp      st1 };
                    asm { fld        dword [esp-0x40+88] };
                    asm { fld        st0 };
                    asm { fdivp      st2 };
                    asm { fxch       st0, st1 };
                    eax = sub_47b5c0();
                    *(&arg_3c + esi * 0x4 + 0x80) = *(&arg_3c + esi * 0x4 + 0x80) + eax;
                    arg_54 = *(&arg_3c + esi * 0x4 + 0x80);
                    if (eax < 0x0) {
                            *(&arg_3c + esi * 0x4 + 0xd8) = *(&arg_3c + esi * 0x4 + 0xd8) + eax;
                    }
                    asm { fld        st1 };
                    asm { fmul       qword [qword_value_4621819117588971520] };
                    asm { fild       dword [esp+esi*4-0x40+464] };
                    asm { fmul       st1 };
                    asm { fdiv       st2 };
                    asm { fiadd      dword [esp-0x40+88] };
                    eax = sub_47b5c0();
                    asm { fimul      dword [esp+esi*4-0x40+368] };
                    *(&arg_3c + esi * 0x4 + 0x80) = eax;
                    asm { fdivrp     st1 };
                    eax = sub_47b5c0();
                    *(&arg_3c + esi * 0x4 + 0x80) = *(&arg_3c + esi * 0x4 + 0x80) + eax;
                    *(&arg_3c + esi * 0x4 + 0xd8) = *(&arg_3c + esi * 0x4 + 0xd8) + eax;
                    eax = arg_50;
            }
    }
    esi = esi + 0x1;
    arg_54 = esi;
    if (esi < eax[0x901]) {
            continue;
    }
    break;

loc_43d1fe:
    edi = 0x0;
    eax = *(&arg_2c + esi * 0x4 + 0x80);
    asm { fstp       st0 };
    ebx = arg_38;
    arg_54 = eax;
    arg_48 = edi;
    arg_44 = &arg_2c + (esi << 0xa) + 0x5af0;
    esi = esi << 0xb;
    goto loc_43d226;
    if (temp_11 == 0x0) goto .l1;
    goto loc_43d5fe;

loc_43cc20:
    arg_60 = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != arg_60) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            arg_78 = *(int16_t *)word_4c6c08;
            esp = esp - 0x4;
            arg_74 = esi[0x3];
            eax = sub_41c270(&arg_74);
            if (*(eax + arg_44 * 0x4 + 0x54) <= 0x0) {
                    sub_40f400();
                    esi = arg_88;
                    ebx = arg_84;
                    eax = arg_74;
                    continue;
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            bool_376 = esi != ebx[0x1];
            eax = esi[0x3];
            ecx = arg_48[0x2];
            arg_64 = ecx + (eax + eax * 0x8) * 0x4 + 0x14;
            arg_ac = *(ecx + (eax + eax * 0x8) * 0x4 + 0x18);
            if (!bool_376) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            arg_2c = &arg_1bc;
            eax = sub_401ff0(arg_2c, &arg_44, arg_34, arg_38, arg_3c);
            arg_84 = eax;
            eax = *eax;
            if (eax == 0x0 || eax != arg_64) {
                    sub_47a948();
            }
            if (arg_84[0x1] != arg_ac) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    asm { fild       dword [esp-0x38+80] };
                    ecx = &arg_74;
                    eax = arg_44 << 0x8;
                    asm { fmul       qword [qword_value_4591870180066957722] };
                    esp = esp - 0x4;
                    arg_30 = ecx;
                    arg_40 = eax;
                    asm { fmul       qword [qword_value_4602678819172646912] };
                    asm { fstp       qword [esp-0x34+136] };
                    asm { fild       dword [ebp+0xc] };
                    asm { fstp       qword [esp-0x34+104] };
                    asm { fild       dword [eax+edx*4+0x54] };
                    eax = esi[0x3];
                    eax = eax + arg_40;
                    asm { fmul       qword [esp-0x38+136] };
                    asm { fdiv       qword [esp-0x38+104] };
                    asm { fild       dword [esp+eax*4-0x38+23336] };
                    asm { fcompp };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x4;
                            eax = sub_41c270(&arg_74);
                            asm { fild       dword [eax+edx*4+0x54] };
                            asm { fmul       qword [esp-0x38+136] };
                            asm { fdiv       qword [esp-0x38+104] };
                            eax = sub_47b5c0();
                            ecx = esi[0x3];
                            bool_365 = esi != ebx[0x1];
                            *(&arg_34 + (ecx + arg_40) * 0x4 + 0x5af0) = eax;
                            if (!bool_365) {
                                    sub_47a948();
                            }
                            if (*(&arg_34 + (esi[0x3] + arg_40) * 0x4 + 0x5af0) > 0xa) {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    *(&arg_34 + (esi[0x3] + arg_40) * 0x4 + 0x5af0) = 0xa;
                            }
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    asm { fild       dword [esp-0x38+80] };
                    ecx = &arg_74;
                    eax = arg_44 << 0x8;
                    asm { fmul       qword [qword_value_4591870180066957722] };
                    esp = esp - 0x4;
                    arg_30 = ecx;
                    arg_40 = eax;
                    asm { fstp       qword [esp-0x34+136] };
                    asm { fild       dword [ebp+0xc] };
                    asm { fstp       qword [esp-0x34+104] };
                    asm { fild       dword [eax+edx*4+0x54] };
                    eax = esi[0x3];
                    eax = eax + arg_40;
                    asm { fmul       qword [esp-0x38+136] };
                    asm { fdiv       qword [esp-0x38+104] };
                    asm { fild       dword [esp+eax*4-0x38+23336] };
                    asm { fcompp };
                    asm { fnstsw     ax };
                    if (PARITY(HIBYTE(eax) & 0x5)) {
                            sub_40f400();
                            esi = arg_88;
                            ebx = arg_84;
                            eax = arg_74;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    eax = sub_41c270(&arg_74);
                    asm { fild       dword [eax+edx*4+0x54] };
                    asm { fmul       qword [esp-0x38+136] };
                    asm { fdiv       qword [esp-0x38+104] };
                    eax = sub_47b5c0();
                    ecx = esi[0x3];
                    bool_366 = esi != ebx[0x1];
                    *(&arg_34 + (ecx + arg_40) * 0x4 + 0x5af0) = eax;
                    if (!bool_366) {
                            sub_47a948();
                    }
                    if (*(&arg_34 + (esi[0x3] + arg_40) * 0x4 + 0x5af0) > 0x14) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            *(&arg_34 + (esi[0x3] + arg_40) * 0x4 + 0x5af0) = 0x14;
                    }
            }
            sub_40f400();
            esi = arg_88;
            ebx = arg_84;
            eax = arg_74;
            continue;
    }
    break;
    temp_11 = 0x1;
    goto .l164;

loc_43d226:
    eax = arg_54 + *arg_44;
    ecx = esi[0x163e3b];
    bool_637 = ecx > 0x0;
    edx = esi[0x163e3a];
    arg_54 = eax;
    if (ecx >= 0x0) {
            if (!bool_637) {
                    if (edx > 0x0) {
                            bool_626 = esi[0x15183b] < 0x0;
                            bool_623 = esi[0x15183b] > 0x0;
                            if (!bool_626) {
                                    if (!bool_623) {
                                            if (esi[0x15183a] > 0x0) {
                                                    ebx = arg_38;
                                                    if ((*(edi * 0x8 + 0x4d2e10) & *(edi * 0x8 + 0x4d2e14)) == 0xffffffff) {
                                                            arg_54 = eax + esi[0x15423a];
                                                    }
                                            }
                                    }
                                    else {
                                            ebx = arg_38;
                                            if ((*(edi * 0x8 + 0x4d2e10) & *(edi * 0x8 + 0x4d2e14)) == 0xffffffff) {
                                                    arg_54 = eax + esi[0x15423a];
                                            }
                                    }
                            }
                    }
            }
            else {
                    bool_627 = esi[0x15183b] > 0x0;
                    if (esi[0x15183b] >= 0x0) {
                            if (!bool_627) {
                                    if (esi[0x15183a] > 0x0) {
                                            ebx = arg_38;
                                            if ((*(edi * 0x8 + 0x4d2e10) & *(edi * 0x8 + 0x4d2e14)) == 0xffffffff) {
                                                    arg_54 = eax + esi[0x15423a];
                                            }
                                    }
                            }
                            else {
                                    ebx = arg_38;
                                    if ((*(edi * 0x8 + 0x4d2e10) & *(edi * 0x8 + 0x4d2e14)) == 0xffffffff) {
                                            arg_54 = eax + esi[0x15423a];
                                    }
                            }
                    }
            }
    }
    bool_597 = esi[0x18103b] > 0x0;
    if (esi[0x18103b] >= 0x0) {
            if (!bool_597) {
                    if (esi[0x18103a] > 0x0) {
                            if ((*(edi * 0x8 + 0x4d2e10) & *(edi * 0x8 + 0x4d2e14)) == 0xffffffff) {
                                    arg_28 = esi[0x15423b];
                                    ecx = esi[0x15423a];
                                    eax = arg_8 - *(&arg_28 + edi * 0x4 + 0x2f4);
                                    eax = sub_47bb70(eax, eax & 0x80000000 ? 0xffffffff : 0x0, ecx, arg_28);
                                    arg_5c = edx;
                                    esp = esp - 0x20;
                                    arg_54 = arg_54 + sub_47bac0(eax, arg_5c, arg_8, arg_8 & 0x80000000 ? 0xffffffff : 0x0);
                            }
                            else {
                                    bool_579 = esi[0x16923b] < 0x0;
                                    bool_571 = esi[0x16923b] > 0x0;
                                    if (!bool_579) {
                                            if (!bool_571) {
                                                    if (esi[0x16923a] > 0xa && (*(edi * 0x8 + 0x4d2e10) & *(edi * 0x8 + 0x4d2e14)) == 0xffffffff) {
                                                            bool_563 = ecx > 0x0;
                                                            if (ecx >= 0x0) {
                                                                    if (!bool_563) {
                                                                            if (edx > 0x0) {
                                                                                    bool_556 = esi[0x15183b] < 0x0;
                                                                                    bool_554 = esi[0x15183b] > 0x0;
                                                                                    if (!bool_556) {
                                                                                            if (!bool_554) {
                                                                                                    if (esi[0x15183a] > 0x0) {
                                                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                                    ecx = esi[0x15423b];
                                                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                                    esp = esp - 0x10;
                                                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                                                    arg_54 = sub_47b5c0();
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                            ecx = esi[0x15423b];
                                                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                            esp = esp - 0x10;
                                                                                                            asm { fild       qword [esp-0x30+112] };
                                                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                                                            arg_54 = sub_47b5c0();
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            bool_677 = esi[0x15183b] > 0x0;
                                                                            if (esi[0x15183b] >= 0x0) {
                                                                                    if (!bool_677) {
                                                                                            if (esi[0x15183a] > 0x0) {
                                                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                            ecx = esi[0x15423b];
                                                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                            esp = esp - 0x10;
                                                                                                            asm { fild       qword [esp-0x30+112] };
                                                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                                                            arg_54 = sub_47b5c0();
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                    ecx = esi[0x15423b];
                                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                    esp = esp - 0x10;
                                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                                    arg_54 = sub_47b5c0();
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    if ((*(edi * 0x8 + 0x4d2e10) & *(edi * 0x8 + 0x4d2e14)) == 0xffffffff) {
                                                            bool_618 = ecx > 0x0;
                                                            if (ecx >= 0x0) {
                                                                    if (!bool_618) {
                                                                            if (edx > 0x0) {
                                                                                    bool_700 = esi[0x15183b] > 0x0;
                                                                                    if (esi[0x15183b] >= 0x0) {
                                                                                            if (!bool_700) {
                                                                                                    if (esi[0x15183a] > 0x0) {
                                                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                                    ecx = esi[0x15423b];
                                                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                                    esp = esp - 0x10;
                                                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                                                    arg_54 = sub_47b5c0();
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                            ecx = esi[0x15423b];
                                                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                            esp = esp - 0x10;
                                                                                                            asm { fild       qword [esp-0x30+112] };
                                                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                                                            arg_54 = sub_47b5c0();
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            bool_542 = esi[0x15183b] > 0x0;
                                                                            if (esi[0x15183b] >= 0x0) {
                                                                                    if (!bool_542) {
                                                                                            if (esi[0x15183a] > 0x0) {
                                                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                            ecx = esi[0x15423b];
                                                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                            esp = esp - 0x10;
                                                                                                            asm { fild       qword [esp-0x30+112] };
                                                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                                                            arg_54 = sub_47b5c0();
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                    ecx = esi[0x15423b];
                                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                    esp = esp - 0x10;
                                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                                    arg_54 = sub_47b5c0();
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            bool_631 = esi[0x16923b] > 0x0;
                            if (esi[0x16923b] >= 0x0) {
                                    if (!bool_631) {
                                            if (esi[0x16923a] > 0xa && (*(edi * 0x8 + 0x4d2e10) & *(edi * 0x8 + 0x4d2e14)) == 0xffffffff) {
                                                    bool_535 = ecx > 0x0;
                                                    if (ecx >= 0x0) {
                                                            if (!bool_535) {
                                                                    if (edx > 0x0) {
                                                                            bool_607 = esi[0x15183b] < 0x0;
                                                                            bool_519 = esi[0x15183b] > 0x0;
                                                                            if (!bool_607) {
                                                                                    if (!bool_519) {
                                                                                            if (esi[0x15183a] > 0x0) {
                                                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                            ecx = esi[0x15423b];
                                                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                            esp = esp - 0x10;
                                                                                                            asm { fild       qword [esp-0x30+112] };
                                                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                                                            arg_54 = sub_47b5c0();
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                    ecx = esi[0x15423b];
                                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                    esp = esp - 0x10;
                                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                                    arg_54 = sub_47b5c0();
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    bool_569 = esi[0x15183b] > 0x0;
                                                                    if (esi[0x15183b] >= 0x0) {
                                                                            if (!bool_569) {
                                                                                    if (esi[0x15183a] > 0x0) {
                                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                    ecx = esi[0x15423b];
                                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                    esp = esp - 0x10;
                                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                                    arg_54 = sub_47b5c0();
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                            ecx = esi[0x15423b];
                                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                            esp = esp - 0x10;
                                                                                            asm { fild       qword [esp-0x30+112] };
                                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                                            arg_54 = sub_47b5c0();
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            if ((*(edi * 0x8 + 0x4d2e10) & *(edi * 0x8 + 0x4d2e14)) == 0xffffffff) {
                                                    bool_662 = ecx > 0x0;
                                                    if (ecx >= 0x0) {
                                                            if (!bool_662) {
                                                                    if (edx > 0x0) {
                                                                            bool_540 = esi[0x15183b] > 0x0;
                                                                            if (esi[0x15183b] >= 0x0) {
                                                                                    if (!bool_540) {
                                                                                            if (esi[0x15183a] > 0x0) {
                                                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                            ecx = esi[0x15423b];
                                                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                            esp = esp - 0x10;
                                                                                                            asm { fild       qword [esp-0x30+112] };
                                                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                                                            arg_54 = sub_47b5c0();
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                    ecx = esi[0x15423b];
                                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                    esp = esp - 0x10;
                                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                                    arg_54 = sub_47b5c0();
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    bool_598 = esi[0x15183b] > 0x0;
                                                                    if (esi[0x15183b] >= 0x0) {
                                                                            if (!bool_598) {
                                                                                    if (esi[0x15183a] > 0x0) {
                                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                    ecx = esi[0x15423b];
                                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                    esp = esp - 0x10;
                                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                                    arg_54 = sub_47b5c0();
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                            ecx = esi[0x15423b];
                                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                            esp = esp - 0x10;
                                                                                            asm { fild       qword [esp-0x30+112] };
                                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                                            arg_54 = sub_47b5c0();
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    if ((*(edi * 0x8 + 0x4d2e10) & *(edi * 0x8 + 0x4d2e14)) == 0xffffffff) {
                            arg_28 = esi[0x15423b];
                            ecx = esi[0x15423a];
                            eax = arg_8 - *(&arg_28 + edi * 0x4 + 0x2f4);
                            eax = sub_47bb70(eax, eax & 0x80000000 ? 0xffffffff : 0x0, ecx, arg_28);
                            arg_5c = edx;
                            esp = esp - 0x20;
                            arg_54 = arg_54 + sub_47bac0(eax, arg_5c, arg_8, arg_8 & 0x80000000 ? 0xffffffff : 0x0);
                    }
                    else {
                            bool_605 = esi[0x16923b] > 0x0;
                            if (esi[0x16923b] >= 0x0) {
                                    if (!bool_605) {
                                            if (esi[0x16923a] > 0xa && (*(edi * 0x8 + 0x4d2e10) & *(edi * 0x8 + 0x4d2e14)) == 0xffffffff) {
                                                    bool_516 = ecx > 0x0;
                                                    if (ecx >= 0x0) {
                                                            if (!bool_516) {
                                                                    if (edx > 0x0) {
                                                                            bool_613 = esi[0x15183b] > 0x0;
                                                                            if (esi[0x15183b] >= 0x0) {
                                                                                    if (!bool_613) {
                                                                                            if (esi[0x15183a] > 0x0) {
                                                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                            ecx = esi[0x15423b];
                                                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                            esp = esp - 0x10;
                                                                                                            asm { fild       qword [esp-0x30+112] };
                                                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                                                            arg_54 = sub_47b5c0();
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                    ecx = esi[0x15423b];
                                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                    esp = esp - 0x10;
                                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                                    arg_54 = sub_47b5c0();
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    bool_657 = esi[0x15183b] > 0x0;
                                                                    if (esi[0x15183b] >= 0x0) {
                                                                            if (!bool_657) {
                                                                                    if (esi[0x15183a] > 0x0) {
                                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                    ecx = esi[0x15423b];
                                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                    esp = esp - 0x10;
                                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                                    arg_54 = sub_47b5c0();
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                            ecx = esi[0x15423b];
                                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                            esp = esp - 0x10;
                                                                                            asm { fild       qword [esp-0x30+112] };
                                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                                            arg_54 = sub_47b5c0();
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            if ((*(edi * 0x8 + 0x4d2e10) & *(edi * 0x8 + 0x4d2e14)) == 0xffffffff) {
                                                    bool_537 = ecx > 0x0;
                                                    if (ecx >= 0x0) {
                                                            if (!bool_537) {
                                                                    if (edx > 0x0) {
                                                                            bool_638 = esi[0x15183b] > 0x0;
                                                                            if (esi[0x15183b] >= 0x0) {
                                                                                    if (!bool_638) {
                                                                                            if (esi[0x15183a] > 0x0) {
                                                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                            ecx = esi[0x15423b];
                                                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                            esp = esp - 0x10;
                                                                                                            asm { fild       qword [esp-0x30+112] };
                                                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                                                            arg_54 = sub_47b5c0();
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                    ecx = esi[0x15423b];
                                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                    esp = esp - 0x10;
                                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                                    arg_54 = sub_47b5c0();
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    bool_686 = esi[0x15183b] > 0x0;
                                                                    if (esi[0x15183b] >= 0x0) {
                                                                            if (!bool_686) {
                                                                                    if (esi[0x15183a] > 0x0) {
                                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                                    ecx = esi[0x15423b];
                                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                                    esp = esp - 0x10;
                                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                                    arg_54 = sub_47b5c0();
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                            ecx = esi[0x15423b];
                                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                            esp = esp - 0x10;
                                                                                            asm { fild       qword [esp-0x30+112] };
                                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                                            arg_54 = sub_47b5c0();
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }
    else {
            bool_577 = esi[0x16923b] > 0x0;
            if (esi[0x16923b] >= 0x0) {
                    if (!bool_577) {
                            if (esi[0x16923a] > 0xa && (*(edi * 0x8 + 0x4d2e10) & *(edi * 0x8 + 0x4d2e14)) == 0xffffffff) {
                                    bool_693 = ecx > 0x0;
                                    if (ecx >= 0x0) {
                                            if (!bool_693) {
                                                    if (edx > 0x0) {
                                                            bool_587 = esi[0x15183b] > 0x0;
                                                            if (esi[0x15183b] >= 0x0) {
                                                                    if (!bool_587) {
                                                                            if (esi[0x15183a] > 0x0) {
                                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                            ecx = esi[0x15423b];
                                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                            esp = esp - 0x10;
                                                                                            asm { fild       qword [esp-0x30+112] };
                                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                                            arg_54 = sub_47b5c0();
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                    ecx = esi[0x15423b];
                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                    esp = esp - 0x10;
                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                    arg_54 = sub_47b5c0();
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    bool_634 = esi[0x15183b] > 0x0;
                                                    if (esi[0x15183b] >= 0x0) {
                                                            if (!bool_634) {
                                                                    if (esi[0x15183a] > 0x0) {
                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                    ecx = esi[0x15423b];
                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                    esp = esp - 0x10;
                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                    arg_54 = sub_47b5c0();
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                            ecx = esi[0x15423b];
                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                            esp = esp - 0x10;
                                                                            asm { fild       qword [esp-0x30+112] };
                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                            arg_54 = sub_47b5c0();
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            if ((*(edi * 0x8 + 0x4d2e10) & *(edi * 0x8 + 0x4d2e14)) == 0xffffffff) {
                                    bool_525 = ecx > 0x0;
                                    if (ecx >= 0x0) {
                                            if (!bool_525) {
                                                    if (edx > 0x0) {
                                                            bool_625 = esi[0x15183b] > 0x0;
                                                            if (esi[0x15183b] >= 0x0) {
                                                                    if (!bool_625) {
                                                                            if (esi[0x15183a] > 0x0) {
                                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                            ecx = esi[0x15423b];
                                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                            esp = esp - 0x10;
                                                                                            asm { fild       qword [esp-0x30+112] };
                                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                                            arg_54 = sub_47b5c0();
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                    ecx = esi[0x15423b];
                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                    esp = esp - 0x10;
                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                    arg_54 = sub_47b5c0();
                                                                            }
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    bool_669 = esi[0x15183b] > 0x0;
                                                    if (esi[0x15183b] >= 0x0) {
                                                            if (!bool_669) {
                                                                    if (esi[0x15183a] > 0x0) {
                                                                            if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                                    ecx = esi[0x15423b];
                                                                                    eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                                    esp = esp - 0x10;
                                                                                    asm { fild       qword [esp-0x30+112] };
                                                                                    asm { fmul       qword [qword_value_4604930618986332160] };
                                                                                    asm { fidiv      dword [ebp+0xc] };
                                                                                    asm { fiadd      dword [esp-0x30+88] };
                                                                                    arg_54 = sub_47b5c0();
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (*(int8_t *)(arg_48 + ebx + 0x3) == 0x0 || *(int16_t *)word_4c6cc4 == ebx[0x1225]) {
                                                                            ecx = esi[0x15423b];
                                                                            eax = arg_8 - *(&arg_2c + edi * 0x4 + 0x2f0);
                                                                            esp = esp - 0x10;
                                                                            asm { fild       qword [esp-0x30+112] };
                                                                            asm { fmul       qword [qword_value_4604930618986332160] };
                                                                            asm { fidiv      dword [ebp+0xc] };
                                                                            asm { fiadd      dword [esp-0x30+88] };
                                                                            arg_54 = sub_47b5c0();
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }
    ebx = arg_50 + arg_40 + 0x14;
    arg_ac = *(arg_50 + arg_40 + 0x18);
    esp = esp - 0x8;
    arg_2c = &arg_1bc;
    eax = sub_401ff0(arg_2c, &arg_44, arg_34, arg_38, arg_3c);
    arg_64 = eax;
    eax = *eax;
    if (eax == 0x0 || eax != ebx) {
            sub_47a948();
    }
    if (arg_64[0x1] != arg_ac) {
            ecx = arg_48[0x2];
            ecx = ecx[0x1225] & 0xffff;
            if (*(int16_t *)word_4c6cc4 == ecx) {
                    edx = arg_4 & 0x80000000 ? 0xffffffff : 0x0;
                    if (*(edi * 0x8 + 0x4d2610) == arg_4) {
                            if (*(edi * 0x8 + 0x4d2614) == edx) {
                                    ecx = arg_8;
                                    eax = ecx - *(&arg_34 + edi * 0x4 + 0x2f0);
                                    eax = eax + eax * 0x4 + eax + eax * 0x4;
                                    arg_64 = arg_64 + eax / ecx;
                                    ebx = arg_50[0x2];
                                    arg_58 = arg_58 + 0x24;
                                    arg_54 = arg_54 + 0x4;
                                    edi = edi + 0x1;
                                    esi = esi + 0x8;
                                    arg_48 = ebx;
                                    if (edi < ebx[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (*(int16_t *)word_4c6ccc == ecx) {
                                            ebx = *(&arg_34 + arg_44 * 0x4 + 0x240);
                                            if (ebx > 0x0) {
                                                    edx = arg_4 & 0x80000000 ? 0xffffffff : 0x0;
                                                    if (*(edi * 0x8 + 0x4d2610) == arg_4 && *(edi * 0x8 + 0x4d2614) == edx) {
                                                            ecx = arg_8;
                                                            eax = ecx - *(&arg_34 + edi * 0x4 + 0x2f0);
                                                            eax = (eax * ebx + eax * ebx * 0x4 + eax * ebx + eax * ebx * 0x4 + eax * ebx + eax * ebx * 0x4 + eax * ebx + eax * ebx * 0x4) / ecx;
                                                            arg_64 = arg_64 + eax / ecx;
                                                    }
                                            }
                                    }
                                    ebx = arg_50[0x2];
                                    arg_58 = arg_58 + 0x24;
                                    arg_54 = arg_54 + 0x4;
                                    edi = edi + 0x1;
                                    esi = esi + 0x8;
                                    arg_48 = ebx;
                                    if (edi < ebx[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (*(int16_t *)word_4c6ccc == ecx) {
                                    ebx = *(&arg_34 + arg_44 * 0x4 + 0x240);
                                    if (ebx > 0x0) {
                                            edx = arg_4 & 0x80000000 ? 0xffffffff : 0x0;
                                            if (*(edi * 0x8 + 0x4d2610) == arg_4 && *(edi * 0x8 + 0x4d2614) == edx) {
                                                    ecx = arg_8;
                                                    eax = ecx - *(&arg_34 + edi * 0x4 + 0x2f0);
                                                    eax = (eax * ebx + eax * ebx * 0x4 + eax * ebx + eax * ebx * 0x4 + eax * ebx + eax * ebx * 0x4 + eax * ebx + eax * ebx * 0x4) / ecx;
                                                    arg_64 = arg_64 + eax / ecx;
                                            }
                                    }
                            }
                            ebx = arg_50[0x2];
                            arg_58 = arg_58 + 0x24;
                            arg_54 = arg_54 + 0x4;
                            edi = edi + 0x1;
                            esi = esi + 0x8;
                            arg_48 = ebx;
                            if (edi < ebx[0x900]) {
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    if (*(int16_t *)word_4c6ccc == ecx) {
                            ebx = *(&arg_34 + arg_44 * 0x4 + 0x240);
                            if (ebx > 0x0) {
                                    edx = arg_4 & 0x80000000 ? 0xffffffff : 0x0;
                                    if (*(edi * 0x8 + 0x4d2610) == arg_4 && *(edi * 0x8 + 0x4d2614) == edx) {
                                            ecx = arg_8;
                                            eax = ecx - *(&arg_34 + edi * 0x4 + 0x2f0);
                                            eax = (eax * ebx + eax * ebx * 0x4 + eax * ebx + eax * ebx * 0x4 + eax * ebx + eax * ebx * 0x4 + eax * ebx + eax * ebx * 0x4) / ecx;
                                            arg_64 = arg_64 + eax / ecx;
                                    }
                            }
                    }
                    ebx = arg_50[0x2];
                    arg_58 = arg_58 + 0x24;
                    arg_54 = arg_54 + 0x4;
                    edi = edi + 0x1;
                    esi = esi + 0x8;
                    arg_48 = ebx;
                    if (edi < ebx[0x900]) {
                            continue;
                    }
                    break;
            }
    }
    else {
            ebx = arg_50[0x2];
            arg_58 = arg_58 + 0x24;
            arg_54 = arg_54 + 0x4;
            edi = edi + 0x1;
            esi = esi + 0x8;
            arg_48 = ebx;
            if (edi < ebx[0x900]) {
                    continue;
            }
            break;
    }
    goto .l4;

.l1:
    return;

loc_43d5fe:
    eax = *dword_62c57c;
    *(&arg_44 + ebx * 0x4 + 0x80) = *(&arg_44 + ebx * 0x4 + 0x80) - eax;
    *(&arg_44 + ebx * 0x4 + 0xd8) = *(&arg_44 + ebx * 0x4 + 0xd8) - eax;
    eax = *dword_633ebc;
    *(&arg_44 + ebx * 0x4 + 0x80) = *(&arg_44 + ebx * 0x4 + 0x80) - eax;
    *(&arg_44 + ebx * 0x4 + 0xd8) = *(&arg_44 + ebx * 0x4 + 0xd8) - eax;
    eax = *dword_633e64;
    edx = *dword_6240cc;
    *(&arg_44 + ebx * 0x4 + 0x80) = *(&arg_44 + ebx * 0x4 + 0x80) - eax * 0x32;
    *(&arg_44 + ebx * 0x4 + 0xd8) = *(&arg_44 + ebx * 0x4 + 0xd8) - eax * 0x32;
    esi = &arg_44 + ebx * 0x4 + 0x80;
    ecx = 0x0;
    arg_74 = edx;
    if (*(arg_58[0x2] + 0x2400) <= 0x0) goto loc_43d6f7;
    goto loc_43d660;

.l4:
    eax = arg_4c;
    asm { fld        dword [byte_4c6bdc+4] };
    ebx = arg_4;
    *(&arg_3c + eax * 0x4 + 0x80) = arg_64;
    esi = eax;
    goto loc_43d4b6;

loc_43d6f7:
    ecx = arg_58[0x2];
    ecx = ecx[0x900];
    eax = 0x0;
    if (ecx > 0x0) {
            do {
                    edx = edx + *(eax * 0x8 + 0x62db58);
                    eax = eax + 0x1;
            } while (eax < ecx);
    }
    eax = edx;
    edx = eax & 0x80000000 ? 0xffffffff : 0x0;
    bool_17 = edx > *dword_62e35c;
    if (edx >= *dword_62e35c && (bool_17 || eax > *qword_62e358)) {
            *qword_62e358 = eax;
            *dword_62e35c = edx;
    }
    bool_21 = *(int8_t *)byte_baed6a != 0x1;
    asm { fadd       qword [qword_value_4613937818241073152] };
    asm { fild       qword [qword_62e358] };
    asm { fmulp      st1 };
    if (!bool_21) {
            asm { fmul       qword [qword_value_4589168020290535424] };
    }
    else {
            asm { fmul       qword [qword_value_4593671619917905920] };
    }
    eax = sub_47b5c0();
    *esi = *esi - eax;
    *(&arg_4c + ebx * 0x4 + 0xd8) = *(&arg_4c + ebx * 0x4 + 0xd8) - eax;
    eax = *dword_62be94;
    *esi = *esi - eax;
    *(&arg_4c + ebx * 0x4 + 0xd8) = *(&arg_4c + ebx * 0x4 + 0xd8) - eax;
    bool_19 = *(int8_t *)byte_baed68 != 0x0;
    ecx = *esi;
    if (!bool_19) {
            *esi = ecx + arg_88;
    }
    edi = 0x0;
    if (*(arg_60[0x2] + 0x2404) > 0x0) {
            asm { fld        qword [qword_value_4666723172467343360] };
            while (true) {
                    if (edi == ebx) {
                            edi = edi + 0x1;
                            if (edi < arg_bc) {
                                    continue;
                            }
                            break;
                    }
                    eax = ebx * 0x15 + edi;
                    edx = *(eax * 0x8 + 0x4d5528);
                    ecx = *(eax * 0x8 + 0x4d552c);
                    if ((edx | ecx) == 0x0) {
                            asm { fild       dword [esp-0x50+128] };
                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                            asm { fdiv       st1 };
                            eax = sub_47b5c0();
                            ebx = arg_4;
                            *esi = *esi + eax;
                            *(&arg_4c + ebx * 0x4 + 0xd8) = *(&arg_4c + ebx * 0x4 + 0xd8) + eax;
                            edi = edi + 0x1;
                            if (edi < arg_bc) {
                                    continue;
                            }
                            break;
                    }
                    bool_263 = edx > 0x1;
                    bool_28 = edx < 0x1;
                    if (edx == 0x1) {
                            bool_158 = ecx > 0x0;
                            bool_73 = ecx < 0x0;
                            if (ecx == 0x0) {
                                    bool_307 = *(eax * 0x4 + 0x634e90) > 0xa;
                                    bool_273 = *(eax * 0x4 + 0x634e90) < 0xa;
                                    if (*(eax * 0x4 + 0x634e90) > 0xa) {
                                            if (!bool_273) {
                                                    if (!bool_307) {
                                                            if (edx >= 0x1) {
                                                                    if (*(eax * 0x4 + 0x634e90) < 0x14) {
                                                                            bool_245 = ecx > 0x0;
                                                                            if (ecx >= 0x0) {
                                                                                    if (!bool_245) {
                                                                                            if (edx >= 0x3) {
                                                                                                    if (*dword_baed64 > 0x1) {
                                                                                                            ebx = arg_4;
                                                                                                            if (ebx == arg_c8) {
                                                                                                                    if (arg_a8 <= 0x32) {
                                                                                                                            if (edi == *dword_4c6bc4) {
                                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                            bool_101 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                                            edx = arg_a8;
                                                                                                                                            if (!bool_101) {
                                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                                            asm { fdiv       st1 };
                                                                                                            asm { fiadd      dword [esi] };
                                                                                                            *esi = sub_47b5c0();
                                                                                                            edi = edi + 0x1;
                                                                                                            if (edi < arg_bc) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            ebx = arg_4;
                                                                                                            edi = edi + 0x1;
                                                                                                            if (edi < arg_bc) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ebx = arg_4;
                                                                                                    edi = edi + 0x1;
                                                                                                    if (edi < arg_bc) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (*dword_baed64 > 0x1) {
                                                                                                    ebx = arg_4;
                                                                                                    if (ebx == arg_c8) {
                                                                                                            if (arg_a8 <= 0x32) {
                                                                                                                    if (edi == *dword_4c6bc4) {
                                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                    bool_171 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                                    edx = arg_a8;
                                                                                                                                    if (!bool_171) {
                                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                                    asm { fdiv       st1 };
                                                                                                    asm { fiadd      dword [esi] };
                                                                                                    *esi = sub_47b5c0();
                                                                                                    edi = edi + 0x1;
                                                                                                    if (edi < arg_bc) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ebx = arg_4;
                                                                                                    edi = edi + 0x1;
                                                                                                    if (edi < arg_bc) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx = arg_4;
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = arg_4;
                                                                            if (ebx == arg_c8) {
                                                                                    if (arg_a8 <= 0x32) {
                                                                                            if (edi == *dword_4c6bc4) {
                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                            bool_84 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                            edx = arg_a8;
                                                                                                            if (!bool_84) {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                            }
                                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                            asm { fdiv       st1 };
                                                                            asm { fiadd      dword [esi] };
                                                                            *esi = sub_47b5c0();
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    bool_52 = ecx > 0x0;
                                                                    if (ecx >= 0x0) {
                                                                            if (!bool_52) {
                                                                                    if (edx >= 0x3) {
                                                                                            if (*dword_baed64 > 0x1) {
                                                                                                    ebx = arg_4;
                                                                                                    if (ebx == arg_c8) {
                                                                                                            if (arg_a8 <= 0x32) {
                                                                                                                    if (edi == *dword_4c6bc4) {
                                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                    bool_92 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                                    edx = arg_a8;
                                                                                                                                    if (!bool_92) {
                                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                                    asm { fdiv       st1 };
                                                                                                    asm { fiadd      dword [esi] };
                                                                                                    *esi = sub_47b5c0();
                                                                                                    edi = edi + 0x1;
                                                                                                    if (edi < arg_bc) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ebx = arg_4;
                                                                                                    edi = edi + 0x1;
                                                                                                    if (edi < arg_bc) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ebx = arg_4;
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (*dword_baed64 > 0x1) {
                                                                                            ebx = arg_4;
                                                                                            if (ebx == arg_c8) {
                                                                                                    if (arg_a8 <= 0x32) {
                                                                                                            if (edi == *dword_4c6bc4) {
                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                            bool_230 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                            edx = arg_a8;
                                                                                                                            if (!bool_230) {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                            asm { fdiv       st1 };
                                                                                            asm { fiadd      dword [esi] };
                                                                                            *esi = sub_47b5c0();
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ebx = arg_4;
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = arg_4;
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (*(eax * 0x4 + 0x634e90) < 0x14) {
                                                                    bool_112 = ecx > 0x0;
                                                                    if (ecx >= 0x0) {
                                                                            if (!bool_112) {
                                                                                    if (edx >= 0x3) {
                                                                                            if (*dword_baed64 > 0x1) {
                                                                                                    ebx = arg_4;
                                                                                                    if (ebx == arg_c8) {
                                                                                                            if (arg_a8 <= 0x32) {
                                                                                                                    if (edi == *dword_4c6bc4) {
                                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                    bool_186 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                                    edx = arg_a8;
                                                                                                                                    if (!bool_186) {
                                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                                    asm { fdiv       st1 };
                                                                                                    asm { fiadd      dword [esi] };
                                                                                                    *esi = sub_47b5c0();
                                                                                                    edi = edi + 0x1;
                                                                                                    if (edi < arg_bc) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ebx = arg_4;
                                                                                                    edi = edi + 0x1;
                                                                                                    if (edi < arg_bc) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ebx = arg_4;
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (*dword_baed64 > 0x1) {
                                                                                            ebx = arg_4;
                                                                                            if (ebx == arg_c8) {
                                                                                                    if (arg_a8 <= 0x32) {
                                                                                                            if (edi == *dword_4c6bc4) {
                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                            bool_311 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                            edx = arg_a8;
                                                                                                                            if (!bool_311) {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                            asm { fdiv       st1 };
                                                                                            asm { fiadd      dword [esi] };
                                                                                            *esi = sub_47b5c0();
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ebx = arg_4;
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = arg_4;
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = arg_4;
                                                                    if (ebx == arg_c8) {
                                                                            if (arg_a8 <= 0x32) {
                                                                                    if (edi == *dword_4c6bc4) {
                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                    bool_153 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                    edx = arg_a8;
                                                                                                    if (!bool_153) {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                            }
                                                                    }
                                                                    else {
                                                                            asm { fild       dword [esp-0x50+128] };
                                                                    }
                                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                    asm { fdiv       st1 };
                                                                    asm { fiadd      dword [esi] };
                                                                    *esi = sub_47b5c0();
                                                                    edi = edi + 0x1;
                                                                    if (edi < arg_bc) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    bool_316 = ecx > 0x0;
                                                    if (ecx >= 0x0) {
                                                            if (!bool_316) {
                                                                    if (edx >= 0x3) {
                                                                            if (*dword_baed64 > 0x1) {
                                                                                    ebx = arg_4;
                                                                                    if (ebx == arg_c8) {
                                                                                            if (arg_a8 <= 0x32) {
                                                                                                    if (edi == *dword_4c6bc4) {
                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                    bool_166 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                    edx = arg_a8;
                                                                                                                    if (!bool_166) {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                    asm { fdiv       st1 };
                                                                                    asm { fiadd      dword [esi] };
                                                                                    *esi = sub_47b5c0();
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ebx = arg_4;
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = arg_4;
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (*dword_baed64 > 0x1) {
                                                                            ebx = arg_4;
                                                                            if (ebx == arg_c8) {
                                                                                    if (arg_a8 <= 0x32) {
                                                                                            if (edi == *dword_4c6bc4) {
                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                            bool_218 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                            edx = arg_a8;
                                                                                                            if (!bool_218) {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                            }
                                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                            asm { fdiv       st1 };
                                                                            asm { fiadd      dword [esi] };
                                                                            *esi = sub_47b5c0();
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ebx = arg_4;
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            ebx = arg_4;
                                                            edi = edi + 0x1;
                                                            if (edi < arg_bc) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            asm { fild       dword [esp-0x50+128] };
                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                            asm { fdiv       st1 };
                                            eax = sub_47b5c0();
                                            ebx = arg_4;
                                            *esi = *esi + eax;
                                            *(&arg_4c + ebx * 0x4 + 0xd8) = *(&arg_4c + ebx * 0x4 + 0xd8) + eax;
                                            edi = edi + 0x1;
                                            if (edi < arg_bc) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    if (!bool_73) {
                                            if (!bool_158) {
                                                    if (edx >= 0x1) {
                                                            if (*(eax * 0x4 + 0x634e90) < 0x14) {
                                                                    bool_200 = ecx > 0x0;
                                                                    if (ecx >= 0x0) {
                                                                            if (!bool_200) {
                                                                                    if (edx >= 0x3) {
                                                                                            if (*dword_baed64 > 0x1) {
                                                                                                    ebx = arg_4;
                                                                                                    if (ebx == arg_c8) {
                                                                                                            if (arg_a8 <= 0x32) {
                                                                                                                    if (edi == *dword_4c6bc4) {
                                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                                    bool_219 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                                    edx = arg_a8;
                                                                                                                                    if (!bool_219) {
                                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                                    asm { fdiv       st1 };
                                                                                                    asm { fiadd      dword [esi] };
                                                                                                    *esi = sub_47b5c0();
                                                                                                    edi = edi + 0x1;
                                                                                                    if (edi < arg_bc) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ebx = arg_4;
                                                                                                    edi = edi + 0x1;
                                                                                                    if (edi < arg_bc) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ebx = arg_4;
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (*dword_baed64 > 0x1) {
                                                                                            ebx = arg_4;
                                                                                            if (ebx == arg_c8) {
                                                                                                    if (arg_a8 <= 0x32) {
                                                                                                            if (edi == *dword_4c6bc4) {
                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                            bool_33 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                            edx = arg_a8;
                                                                                                                            if (!bool_33) {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                            asm { fdiv       st1 };
                                                                                            asm { fiadd      dword [esi] };
                                                                                            *esi = sub_47b5c0();
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ebx = arg_4;
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = arg_4;
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = arg_4;
                                                                    if (ebx == arg_c8) {
                                                                            if (arg_a8 <= 0x32) {
                                                                                    if (edi == *dword_4c6bc4) {
                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                    bool_192 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                    edx = arg_a8;
                                                                                                    if (!bool_192) {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                            }
                                                                    }
                                                                    else {
                                                                            asm { fild       dword [esp-0x50+128] };
                                                                    }
                                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                    asm { fdiv       st1 };
                                                                    asm { fiadd      dword [esi] };
                                                                    *esi = sub_47b5c0();
                                                                    edi = edi + 0x1;
                                                                    if (edi < arg_bc) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            bool_205 = ecx > 0x0;
                                                            if (ecx >= 0x0) {
                                                                    if (!bool_205) {
                                                                            if (edx >= 0x3) {
                                                                                    if (*dword_baed64 > 0x1) {
                                                                                            ebx = arg_4;
                                                                                            if (ebx == arg_c8) {
                                                                                                    if (arg_a8 <= 0x32) {
                                                                                                            if (edi == *dword_4c6bc4) {
                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                            bool_49 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                            edx = arg_a8;
                                                                                                                            if (!bool_49) {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                            asm { fdiv       st1 };
                                                                                            asm { fiadd      dword [esi] };
                                                                                            *esi = sub_47b5c0();
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ebx = arg_4;
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx = arg_4;
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (*dword_baed64 > 0x1) {
                                                                                    ebx = arg_4;
                                                                                    if (ebx == arg_c8) {
                                                                                            if (arg_a8 <= 0x32) {
                                                                                                    if (edi == *dword_4c6bc4) {
                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                    bool_188 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                    edx = arg_a8;
                                                                                                                    if (!bool_188) {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                    asm { fdiv       st1 };
                                                                                    asm { fiadd      dword [esi] };
                                                                                    *esi = sub_47b5c0();
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ebx = arg_4;
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = arg_4;
                                                                    edi = edi + 0x1;
                                                                    if (edi < arg_bc) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (*(eax * 0x4 + 0x634e90) < 0x14) {
                                                            bool_272 = ecx > 0x0;
                                                            if (ecx >= 0x0) {
                                                                    if (!bool_272) {
                                                                            if (edx >= 0x3) {
                                                                                    if (*dword_baed64 > 0x1) {
                                                                                            ebx = arg_4;
                                                                                            if (ebx == arg_c8) {
                                                                                                    if (arg_a8 <= 0x32) {
                                                                                                            if (edi == *dword_4c6bc4) {
                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                            bool_26 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                            edx = arg_a8;
                                                                                                                            if (!bool_26) {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                            asm { fdiv       st1 };
                                                                                            asm { fiadd      dword [esi] };
                                                                                            *esi = sub_47b5c0();
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ebx = arg_4;
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx = arg_4;
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (*dword_baed64 > 0x1) {
                                                                                    ebx = arg_4;
                                                                                    if (ebx == arg_c8) {
                                                                                            if (arg_a8 <= 0x32) {
                                                                                                    if (edi == *dword_4c6bc4) {
                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                    bool_168 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                    edx = arg_a8;
                                                                                                                    if (!bool_168) {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                    asm { fdiv       st1 };
                                                                                    asm { fiadd      dword [esi] };
                                                                                    *esi = sub_47b5c0();
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ebx = arg_4;
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = arg_4;
                                                                    edi = edi + 0x1;
                                                                    if (edi < arg_bc) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ebx = arg_4;
                                                            if (ebx == arg_c8) {
                                                                    if (arg_a8 <= 0x32) {
                                                                            if (edi == *dword_4c6bc4) {
                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                            bool_102 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                            edx = arg_a8;
                                                                                            if (!bool_102) {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                            }
                                                                    }
                                                                    else {
                                                                            asm { fild       dword [esp-0x50+128] };
                                                                    }
                                                            }
                                                            else {
                                                                    asm { fild       dword [esp-0x50+128] };
                                                            }
                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                            asm { fdiv       st1 };
                                                            asm { fiadd      dword [esi] };
                                                            *esi = sub_47b5c0();
                                                            edi = edi + 0x1;
                                                            if (edi < arg_bc) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            bool_325 = ecx > 0x0;
                                            if (ecx >= 0x0) {
                                                    if (!bool_325) {
                                                            if (edx >= 0x3) {
                                                                    if (*dword_baed64 > 0x1) {
                                                                            ebx = arg_4;
                                                                            if (ebx == arg_c8) {
                                                                                    if (arg_a8 <= 0x32) {
                                                                                            if (edi == *dword_4c6bc4) {
                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                            bool_222 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                            edx = arg_a8;
                                                                                                            if (!bool_222) {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                            }
                                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                            asm { fdiv       st1 };
                                                                            asm { fiadd      dword [esi] };
                                                                            *esi = sub_47b5c0();
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ebx = arg_4;
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = arg_4;
                                                                    edi = edi + 0x1;
                                                                    if (edi < arg_bc) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (*dword_baed64 > 0x1) {
                                                                    ebx = arg_4;
                                                                    if (ebx == arg_c8) {
                                                                            if (arg_a8 <= 0x32) {
                                                                                    if (edi == *dword_4c6bc4) {
                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                    bool_46 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                    edx = arg_a8;
                                                                                                    if (!bool_46) {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                            }
                                                                    }
                                                                    else {
                                                                            asm { fild       dword [esp-0x50+128] };
                                                                    }
                                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                    asm { fdiv       st1 };
                                                                    asm { fiadd      dword [esi] };
                                                                    *esi = sub_47b5c0();
                                                                    edi = edi + 0x1;
                                                                    if (edi < arg_bc) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    ebx = arg_4;
                                                                    edi = edi + 0x1;
                                                                    if (edi < arg_bc) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    ebx = arg_4;
                                                    edi = edi + 0x1;
                                                    if (edi < arg_bc) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                            }
                    }
                    else {
                            if (!bool_28) {
                                    if (!bool_263) {
                                            if (edx >= 0x1) {
                                                    if (*(eax * 0x4 + 0x634e90) < 0x14) {
                                                            bool_262 = ecx > 0x0;
                                                            if (ecx >= 0x0) {
                                                                    if (!bool_262) {
                                                                            if (edx >= 0x3) {
                                                                                    if (*dword_baed64 > 0x1) {
                                                                                            ebx = arg_4;
                                                                                            if (ebx == arg_c8) {
                                                                                                    if (arg_a8 <= 0x32) {
                                                                                                            if (edi == *dword_4c6bc4) {
                                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                            bool_47 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                            edx = arg_a8;
                                                                                                                            if (!bool_47) {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                            asm { fdiv       st1 };
                                                                                            asm { fiadd      dword [esi] };
                                                                                            *esi = sub_47b5c0();
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ebx = arg_4;
                                                                                            edi = edi + 0x1;
                                                                                            if (edi < arg_bc) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx = arg_4;
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (*dword_baed64 > 0x1) {
                                                                                    ebx = arg_4;
                                                                                    if (ebx == arg_c8) {
                                                                                            if (arg_a8 <= 0x32) {
                                                                                                    if (edi == *dword_4c6bc4) {
                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                    bool_182 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                    edx = arg_a8;
                                                                                                                    if (!bool_182) {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                    asm { fdiv       st1 };
                                                                                    asm { fiadd      dword [esi] };
                                                                                    *esi = sub_47b5c0();
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ebx = arg_4;
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = arg_4;
                                                                    edi = edi + 0x1;
                                                                    if (edi < arg_bc) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ebx = arg_4;
                                                            if (ebx == arg_c8) {
                                                                    if (arg_a8 <= 0x32) {
                                                                            if (edi == *dword_4c6bc4) {
                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                            bool_89 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                            edx = arg_a8;
                                                                                            if (!bool_89) {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                            }
                                                                    }
                                                                    else {
                                                                            asm { fild       dword [esp-0x50+128] };
                                                                    }
                                                            }
                                                            else {
                                                                    asm { fild       dword [esp-0x50+128] };
                                                            }
                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                            asm { fdiv       st1 };
                                                            asm { fiadd      dword [esi] };
                                                            *esi = sub_47b5c0();
                                                            edi = edi + 0x1;
                                                            if (edi < arg_bc) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    bool_105 = ecx > 0x0;
                                                    if (ecx >= 0x0) {
                                                            if (!bool_105) {
                                                                    if (edx >= 0x3) {
                                                                            if (*dword_baed64 > 0x1) {
                                                                                    ebx = arg_4;
                                                                                    if (ebx == arg_c8) {
                                                                                            if (arg_a8 <= 0x32) {
                                                                                                    if (edi == *dword_4c6bc4) {
                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                    bool_150 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                    edx = arg_a8;
                                                                                                                    if (!bool_150) {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                    asm { fdiv       st1 };
                                                                                    asm { fiadd      dword [esi] };
                                                                                    *esi = sub_47b5c0();
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ebx = arg_4;
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = arg_4;
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (*dword_baed64 > 0x1) {
                                                                            ebx = arg_4;
                                                                            if (ebx == arg_c8) {
                                                                                    if (arg_a8 <= 0x32) {
                                                                                            if (edi == *dword_4c6bc4) {
                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                            bool_276 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                            edx = arg_a8;
                                                                                                            if (!bool_276) {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                            }
                                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                            asm { fdiv       st1 };
                                                                            asm { fiadd      dword [esi] };
                                                                            *esi = sub_47b5c0();
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ebx = arg_4;
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            ebx = arg_4;
                                                            edi = edi + 0x1;
                                                            if (edi < arg_bc) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if (*(eax * 0x4 + 0x634e90) < 0x14) {
                                                    bool_65 = ecx > 0x0;
                                                    if (ecx >= 0x0) {
                                                            if (!bool_65) {
                                                                    if (edx >= 0x3) {
                                                                            if (*dword_baed64 > 0x1) {
                                                                                    ebx = arg_4;
                                                                                    if (ebx == arg_c8) {
                                                                                            if (arg_a8 <= 0x32) {
                                                                                                    if (edi == *dword_4c6bc4) {
                                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                                    bool_143 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                                    edx = arg_a8;
                                                                                                                    if (!bool_143) {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                                    asm { fdiv       st1 };
                                                                                    asm { fiadd      dword [esi] };
                                                                                    *esi = sub_47b5c0();
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ebx = arg_4;
                                                                                    edi = edi + 0x1;
                                                                                    if (edi < arg_bc) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = arg_4;
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (*dword_baed64 > 0x1) {
                                                                            ebx = arg_4;
                                                                            if (ebx == arg_c8) {
                                                                                    if (arg_a8 <= 0x32) {
                                                                                            if (edi == *dword_4c6bc4) {
                                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                            bool_268 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                            edx = arg_a8;
                                                                                                            if (!bool_268) {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                            else {
                                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                            }
                                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                            asm { fdiv       st1 };
                                                                            asm { fiadd      dword [esi] };
                                                                            *esi = sub_47b5c0();
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ebx = arg_4;
                                                                            edi = edi + 0x1;
                                                                            if (edi < arg_bc) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            ebx = arg_4;
                                                            edi = edi + 0x1;
                                                            if (edi < arg_bc) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ebx = arg_4;
                                                    if (ebx == arg_c8) {
                                                            if (arg_a8 <= 0x32) {
                                                                    if (edi == *dword_4c6bc4) {
                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                    bool_120 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                    edx = arg_a8;
                                                                                    if (!bool_120) {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                            }
                                                                    }
                                                                    else {
                                                                            asm { fild       dword [esp-0x50+128] };
                                                                    }
                                                            }
                                                            else {
                                                                    asm { fild       dword [esp-0x50+128] };
                                                            }
                                                    }
                                                    else {
                                                            asm { fild       dword [esp-0x50+128] };
                                                    }
                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                    asm { fdiv       st1 };
                                                    asm { fiadd      dword [esi] };
                                                    *esi = sub_47b5c0();
                                                    edi = edi + 0x1;
                                                    if (edi < arg_bc) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    bool_81 = ecx > 0x0;
                                    if (ecx >= 0x0) {
                                            if (!bool_81) {
                                                    if (edx >= 0x3) {
                                                            if (*dword_baed64 > 0x1) {
                                                                    ebx = arg_4;
                                                                    if (ebx == arg_c8) {
                                                                            if (arg_a8 <= 0x32) {
                                                                                    if (edi == *dword_4c6bc4) {
                                                                                            if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                                    bool_198 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                                    ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                                    edx = arg_a8;
                                                                                                    if (!bool_198) {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                            }
                                                                    }
                                                                    else {
                                                                            asm { fild       dword [esp-0x50+128] };
                                                                    }
                                                                    asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                                    asm { fdiv       st1 };
                                                                    asm { fiadd      dword [esi] };
                                                                    *esi = sub_47b5c0();
                                                                    edi = edi + 0x1;
                                                                    if (edi < arg_bc) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    ebx = arg_4;
                                                                    edi = edi + 0x1;
                                                                    if (edi < arg_bc) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ebx = arg_4;
                                                            edi = edi + 0x1;
                                                            if (edi < arg_bc) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (*dword_baed64 > 0x1) {
                                                            ebx = arg_4;
                                                            if (ebx == arg_c8) {
                                                                    if (arg_a8 <= 0x32) {
                                                                            if (edi == *dword_4c6bc4) {
                                                                                    if (*(int8_t *)byte_baed68 == 0x0) {
                                                                                            bool_310 = *(*dword_4c6bc4 * 0x4 + dword_623990) > *(ebx * 0x4 + dword_623990) + 0x1;
                                                                                            ecx = *(&arg_4c + edi * 0x4 + 0x80);
                                                                                            edx = arg_a8;
                                                                                            if (!bool_310) {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                            else {
                                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fild       dword [esp-0x50+128] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fild       dword [esp-0x50+128] };
                                                                            }
                                                                    }
                                                                    else {
                                                                            asm { fild       dword [esp-0x50+128] };
                                                                    }
                                                            }
                                                            else {
                                                                    asm { fild       dword [esp-0x50+128] };
                                                            }
                                                            asm { fmul       qword [dword_633f14+5573172+eax*8] };
                                                            asm { fdiv       st1 };
                                                            asm { fiadd      dword [esi] };
                                                            *esi = sub_47b5c0();
                                                            edi = edi + 0x1;
                                                            if (edi < arg_bc) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            ebx = arg_4;
                                                            edi = edi + 0x1;
                                                            if (edi < arg_bc) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            ebx = arg_4;
                                            edi = edi + 0x1;
                                            if (edi < arg_bc) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                    }
            }
            asm { fstp       st0 };
    }
    &arg_68 = ebp;
    return;

loc_43d660:
    asm { fld        dword [aWeHaveReceived_4b0d00+36] };
    arg_88 = ebx & 0x80000000 ? 0xffffffff : 0x0;
    edx = *dword_62b0c4;
    arg_84 = ebx;
    edx = edx + 0x200;
    goto loc_43d67d;

loc_43d67d:
    if (*(ecx * 0x8 + 0x4d2610) == arg_84) {
            eax = *(ecx * 0x8 + 0x4d2614);
            if (eax == arg_88 && *edx > 0x0) {
                    asm { fcom       st1 };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5) && *byte_624124 != ebx) {
                            bool_718 = *(ecx * 0x8 + 0x62db5c) > 0x0;
                            bool_712 = *(ecx * 0x8 + 0x62db5c) < 0x0;
                            if (!bool_718) {
                                    if (bool_712 || *(ecx * 0x8 + 0x62db58) < 0x3e8) {
                                            *(ecx * 0x8 + 0x62db58) = 0x3e8;
                                            *(ecx * 0x8 + 0x62db5c) = 0x0;
                                    }
                            }
                    }
            }
    }
    ecx = ecx + 0x1;
    edx = edx + 0x4;
    if (ecx < *(arg_58[0x2] + 0x2400)) {
            continue;
    }
    break;
    edx = arg_74;
    asm { fstp       st0 };
    goto loc_43d6f7;
}
