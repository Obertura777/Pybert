// sub_46abf0 @ 0x46abf0
// hopper name: sub_46abf0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46abf0() {
    var_4 = *dword_4c8db8 ^ &decomp_var_84;
    ebp = arg_10;
    eax = arg_10;
    esp = esp - 0x94;
    if (eax <= 0x0 && (arg_c & 0x2000) == 0x0) {
            eax = 0x6;
    }
    esi = eax;
    edx = 0x24;
    if (esi <= 0x24) {
            edx = esi;
    }
    ecx = arg_c;
    eax = ecx & 0x3000;
    esi = esi - edx;
    ebx = 0x0;
    edi = 0x0;
    if (eax == 0x2000) {
            asm { fldz };
            asm { fld        qword [esp+0x94+arg_18] };
            asm { fcom       st1 };
            asm { fnstsw     ax };
            if (!PARITY(HIBYTE(eax) & 0x5)) {
                    asm { fchs };
            }
            else {
                    ebx = 0x0;
            }
            asm { fld        qword [qword_value_5130517386810051970] };
            asm { fcom       st1 };
            asm { fnstsw     ax };
            asm { fld        qword [qword_value_4756540486875873280] };
            if (PARITY(HIBYTE(eax) & 0x41)) {
                    asm { fstp       st1 };
            }
            else {
                    while (true) {
                            if (ebx >= 0x1388) {
                                    temp_1 = 0x0;
                                    break;
                            }
                            asm { fdiv       st2, st0 };
                            ebx = ebx + 0xa;
                            asm { fxch       st0, st1 };
                            asm { fcom       st2 };
                            asm { fnstsw     ax };
                            if (!PARITY(HIBYTE(eax) & 0x41)) {
                                    asm { fxch       st0, st1 };
                                    continue;
                            }
                            asm { fstp       st0 };
                            temp_1 = 0x1;
                            break;
                    }
                    if (temp_1 == 0x0) {
                            asm { fstp       st1 };
                    }
            }
            asm { fxch       st0, st2 };
            asm { fcomp      st1 };
            asm { fnstsw     ax };
            if (!PARITY(HIBYTE(eax) & 0x5) && esi >= 0xa) {
                    asm { fld        qword [qword_value_4083240551153433103] };
                    while (true) {
                            asm { fcom       st1 };
                            asm { fnstsw     ax };
                            if ((HIBYTE(eax) & 0x1) != 0x0) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            if (edi >= 0x1388) {
                                    temp_0 = 0x1;
                                    break;
                            }
                            esi = esi - 0xa;
                            asm { fxch       st0, st1 };
                            edi = edi + 0xa;
                            asm { fmul       st2 };
                            if (esi >= 0xa) {
                                    asm { fxch       st0, st1 };
                                    continue;
                            }
                            asm { fstp       st1 };
                            temp_0 = 0x0;
                            break;
                    }
                    if (temp_0 != 0x0) {
                            asm { fstp       st0 };
                    }
            }
            bool_9 = var_41 == 0x0;
            asm { fstp       st1 };
            if (!bool_9) {
                    asm { fchs };
            }
    }
    else {
            asm { fld        qword [esp+0x94+arg_18] };
    }
    eax = &var_17;
    if ((ecx & 0x20) != 0x0) {
            eax = &var_16;
    }
    if ((ecx & 0x10) != 0x0) {
            *(int8_t *)eax = 0x23;
            eax = eax + 0x1;
    }
    *(int8_t *)eax = 0x2e;
    eax[0x1] = 0x2a;
    ecx = ecx & 0x3000;
    eax = eax + 0x2;
    if (ecx == 0x2000) {
            ecx = 0x66;
    }
    else {
            ecx = (ecx != 0x1000 ? 0x1 : 0x0) + (ecx != 0x1000 ? 0x1 : 0x0) + 0x65;
    }
    asm { fstp       qword [esp+0x1c+var_1C] };
    *(int8_t *)eax = ecx;
    eax[0x1] = 0x0;
    eax = sub_47d366(&arg_c, 0x6c, &arg_4, edx);
    decomp_var_3c = arg_84;
    sub_469600(saved_fp, arg_0, decomp_var_3c, arg_88, arg_8C, ebp, arg_94, &arg_c, ebx, edi, esi, eax);
    eax = sub_47ad69();
    return eax;
}
